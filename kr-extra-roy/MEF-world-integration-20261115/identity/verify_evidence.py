#!/usr/bin/env python3
"""Read-only static verifier: original bytes, PE mapping, selected edges and pins.

No Client/Lua execution, memory attachment, original mutation or Git writes.
Emit JSON to stdout; redirect it to save a verification result.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess

EXPECTED='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def sha(b): return hashlib.sha256(b).hexdigest()
def need(value,why):
    if not value: raise AssertionError(why)
def read_pe(b):
    p=struct.unpack_from('<I',b,0x3c)[0]
    need(b[p:p+4]==b'PE\0\0','PE signature')
    machine,n=struct.unpack_from('<HH',b,p+4)
    o=p+24; size=struct.unpack_from('<H',b,p+20)[0]
    need(machine==0x14c and struct.unpack_from('<H',b,o)[0]==0x10b,'PE32/i386')
    base=struct.unpack_from('<I',b,o+28)[0]
    ss=[]
    for i in range(n):
        at=o+size+40*i
        vs,rva,rs,rp=struct.unpack_from('<IIII',b,at+8)
        ss.append(dict(name=b[at:at+8].split(b'\0')[0].decode(),va=base+rva,virtual_size=vs,raw_size=rs,raw_offset=rp))
    return base,ss
def decode(text):
    rows=[]
    for line in text.splitlines():
        m=re.match(r'^\s*([0-9a-fA-F]+):\s+((?:[0-9a-fA-F]{2}\s+)+)\s*(.*?)\s*$',line)
        if m: rows.append(dict(va=int(m[1],16),hex=''.join(m[2].split()).lower(),text=m[3]))
    return rows
def main():
    p=argparse.ArgumentParser()
    p.add_argument('--bin','--binary',dest='binary',type=Path,required=True)
    p.add_argument('--repo',type=Path)
    p.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
    args=p.parse_args()
    data=args.binary.read_bytes(); need(sha(data)==EXPECTED,'original SHA256')
    evidence=json.loads((args.evidence_dir/'native-windows.json').read_text())
    manifest=json.loads((args.evidence_dir/'source-manifest.json').read_text())
    base,ss=read_pe(data)
    need(base==evidence['binary']['image_base']==0x400000,'image base')
    need(ss==evidence['binary']['sections'],'sections')
    need(len(data)==evidence['binary']['size'],'original byte length')
    def raw(va,n=1):
        for s in ss:
            d=va-s['va']
            if 0<=d and d+n<=s['raw_size']: return s['raw_offset']+d
        raise AssertionError(f'VA not file backed: {va:#x}/{n}')
    def grab(va,n):
        at=raw(va,n); return data[at:at+n]
    def u32(va): return struct.unpack('<I',grab(va,4))[0]
    def ins_at(va):
        need(va in instructions,f'instruction boundary {va:#x}')
        return instructions[va]
    records=evidence['records']; ids=set(); instructions={}; code_bytes=0; code_windows=0; data_records=0
    for r in records:
        need(r['id'] not in ids,'unique record ID'); ids.add(r['id'])
        n=r['size'];va=r['va'];bs=grab(va,n)
        need(va+n==r['end_va'],'range '+r['id'])
        need(raw(va,n)==r['raw_offset'],'raw mapping '+r['id'])
        need(bs.hex()==r['hex'] and sha(bs)==r['sha256'],'bytes/hash '+r['id'])
        if r['kind']=='code':
            code_windows+=1;code_bytes+=n
            # Extend the decoder input beyond end_va so a truncated final
            # instruction cannot pass merely because objdump prints a mnemonic.
            text=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16',f'--start-address={va}',f'--stop-address={r["end_va"]+16}',str(args.binary)],text=True)
            decoded=[x for x in decode(text) if x['va']<r['end_va']]
            need(decoded==r['instructions'],'original disassembly '+r['id'])
            cursor=va
            for i in decoded:
                need(cursor==i['va'],'continuous instruction boundaries '+r['id'])
                need('(bad)' not in i['text'] and '.byte' not in i['text'],'valid decode '+r['id'])
                nbytes=len(bytes.fromhex(i['hex']));cursor+=nbytes
                need(cursor<=r['end_va'],'instruction straddles end '+r['id'])
                instructions[i['va']]=i
            need(cursor==r['end_va'],'complete selected window '+r['id'])
        else:
            data_records+=1
            if 'u32' in r: need(u32(va)==r['u32'],'u32 '+r['id'])
            if 'u32_values' in r: need(list(struct.unpack('<'+'I'*(n//4),bs))==r['u32_values'],'table '+r['id'])
            if 'f64' in r: need(struct.unpack('<d',bs)[0]==r['f64'],'f64 '+r['id'])
            if 'encoding' in r: need(bs[-1:]==b'\0' and bs[:-1].decode(r['encoding'])==r['decoded'],'string '+r['id'])
    edge_checks=[]
    def exact(va,hexbytes,label):
        need(ins_at(va)['hex']==hexbytes,label);edge_checks.append(label)
    def rel(va,target,label):
        i=ins_at(va);b=bytes.fromhex(i['hex'])
        if b[0] in (0xe8,0xe9):d=struct.unpack('<i',b[1:5])[0]
        elif b[:1]==b'\x0f' and 0x80<=b[1]<=0x8f:d=struct.unpack('<i',b[2:6])[0]
        elif b[0]==0xeb or 0x70<=b[0]<=0x7f:d=struct.unpack('<b',b[1:2])[0]
        else: raise AssertionError('not selected direct relative edge '+label)
        need(va+len(b)+d==target,label);edge_checks.append(label)
    exact(0x4a104f,'66a104def700','local counter read is WORD')
    exact(0x4a105f,'66894604','local actor+04 ID store is WORD')
    exact(0x4a10a4,'bf01000000','counter increment operand EDI=1')
    exact(0x4a11bb,'013d04def700','counter increments as DWORD')
    need(u32(0xf7de04)==1001,'initial counter is 1001');edge_checks.append('initial counter 1001')
    rel(0x4a11b6,0x4dff30,'local factory enters common insertion')
    rel(0x4dff6a,0x4dff90,'duplicate insertion branches to warning')
    rel(0x4dff99,0x6edb60,'duplicate warning is diagnostic')
    rel(0x4ae5b2,0x4aed42,'0007 existing-ID branches directly to next row')
    targets=[0x4ae5e4,0x4ae671,0x4aed83,0x4aed83,0x4aed83,0x4aed83,0x4ae80a,0x4ae8d6]
    need([u32(0x4aed90+i*4) for i in range(8)]==targets,'0007 low-byte target table');edge_checks.append('0007 typed jump table')
    rel(0x4aed88,0x6edc70,'0007 unsupported type reaches error helper')
    exact(0x6edce9,'cc','error helper contains INT3')
    rel(0x4c8ba0,0x4cab80,'position virtual reaches concrete XY setter')
    exact(0x4c8c36,'8881b0000000','direction virtual writes BYTE +B0')
    rel(0x4b2a51,0x4cc8b0,'001A special-layout prelude target')
    rel(0x4b2ac2,0x4dfbc0,'001A common removal target')
    rel(0x4d1f80,0x4c8360,'CMonster on-remove cleanup target')
    rel(0x4d18e6,0x4c7b90,'CMonster destructor cleanup target')
    rel(0x4d18f2,0x89120c,'CMonster deleting destructor frees actor')
    rel(0x4dfc1e,0x7b6890,'common removal tree erase target')
    rel(0x7b6ac7,0x89120c,'tree erase frees the node')
    rel(0x56901a,0x56b590,'Q closure invokes scalar result marshaller')
    exact(0x56b607,'dd19','Q marshaller pushes a QWORD numeric value')
    exact(0x56b609,'c7410803000000','Q marshaller assigns Lua number type 3')
    exact(0x56b610,'83400810','Q marshaller advances Lua stack top')
    rel(0x4ac621,0x4acf90,'Tutorial closure invokes scalar result marshaller')
    exact(0x4acffe,'c7410803000000','Tutorial marshaller assigns Lua number type 3')
    exact(0x4ad005,'dd19','Tutorial marshaller pushes numeric result')
    exact(0x4ad007,'83400810','Tutorial marshaller advances Lua stack top')
    exact(0x4a9f59,'83b87c04000000','availability getter reads fixed +47C field')
    need(0x47c==2*0x210+0x5c,'fixed roster entry arithmetic');edge_checks.append('entry 2 +5C arithmetic')
    getter=next(r for r in records if r['id']=='I29')
    need(not any('[ebp+0x8]' in i['text'] for i in getter['instructions']),'native availability getter does not read its stack argument');edge_checks.append('native fixed getter argument unused')
    rel(0x546200,0x54615a,'input mapper model>9 rejection target')
    vchecks=[(0xc0c9dc,0,0x4d18d0),(0xc0c9dc,0x14,0x4d1f80),(0xc0c9dc,0x44,0x4c8b90),(0xc0c9dc,0x50,0x4c8fa0),(0xc0c9dc,0x58,0x4c8c30),*( (v,0x20,0x5452b0) for v in (0xc0fac4,0xc0fa14,0xc0fb1c))]
    for table,offset,target in vchecks:need(u32(table+offset)==target,f'vtable {table:#x}+{offset:#x}')
    pins=0
    if args.repo:
        env={**os.environ,'GIT_NO_LAZY_FETCH':'1','GIT_OPTIONAL_LOCKS':'0'}
        for s in manifest['sources']:
            tree=subprocess.check_output(['git','ls-tree',s['commit'],'--',s['path']],cwd=args.repo,env=env,text=True).strip()
            need(tree and tree.split()[2]==s['git_blob_sha1'] and tree.split('\t',1)[1]==s['path'],'commit/path pin '+s['path'])
            b=subprocess.check_output(['git','cat-file','blob',s['git_blob_sha1']],cwd=args.repo,env=env)
            need(len(b)==s['size'] and sha(b)==s['sha256'],'source bytes '+s['path'])
            need(hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==s['git_blob_sha1'],'Git blob '+s['path'])
            pins+=1
    print(json.dumps(dict(status='PASS',scope='read-only static evidence integrity and selected semantic edges; no Client/Lua execution',binary_sha256=EXPECTED,binary_size=len(data),pe_image_base=hex(base),code_windows=code_windows,code_bytes=code_bytes,data_records=data_records,selected_edge_checks=len(edge_checks),vtable_target_checks=len(vchecks),source_pins_checked=pins,source_pins_status='verified' if args.repo else 'not requested',checks=edge_checks,artifacts={n:sha((args.evidence_dir/n).read_bytes()) for n in ['native-windows.json','native-windows.asm','source-manifest.json']}),ensure_ascii=False,indent=2))

if __name__=='__main__':main()
