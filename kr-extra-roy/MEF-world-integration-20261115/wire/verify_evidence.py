#!/usr/bin/env python3
"""Read-only original-BIN and source-pin verification of MEF wire integration.

Decodes x86 as data using objdump. Pure-Python SYN vectors exercise the documented
arithmetic only. Never executes Client/Lua, opens sockets, fetches, or writes Git.
"""
import argparse, hashlib, importlib.util, json, os, re, struct, subprocess, sys
from pathlib import Path
sys.dont_write_bytecode=True
def check(ok,msg):
    if not ok: raise ValueError(msg)
def sha(b): return hashlib.sha256(b).hexdigest()
def load(p): return json.loads(p.read_text())

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin',type=Path,required=True)
    ap.add_argument('--repo',type=Path,required=True)
    ap.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
    ap.add_argument('--out',type=Path,help='Optional result JSON outside original inputs')
    a=ap.parse_args();e=a.evidence_dir
    manifest=load(e/'source-manifest.json');native=load(e/'native-windows.json')
    tables=load(e/'frontend-table.json');contracts=load(e/'contracts.json')
    helper=a.repo/manifest['pe_helper']['path']
    check(sha(helper.read_bytes())==manifest['pe_helper']['sha256'],'Pinned PE helper before import')
    sp=importlib.util.spec_from_file_location('pinned_mef_pe',helper);m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
    pe=m.PE(a.bin,native['binary']);ins={};ncode=0
    for r in native['records']:
        start,end=int(r['va'],0),int(r['end'],0);b=pe.at(start,r['length'])
        check(start+r['length']==end and pe.raw(start,len(b))==int(r['raw'],0),'PE raw mapping '+r['id'])
        check(b.hex()==r['hex'] and sha(b)==r['sha256'],'Original bytes '+r['id'])
        if r['kind']!='code':continue
        actual=pe.disasm(start,end);check(actual==r['instructions'],'Original native disassembly '+r['id'])
        p=start
        for row in actual:
            check(int(row['va'],0)==p and '(bad)' not in row['asm'] and '.byte' not in row['asm'],'Complete instructions '+r['id'])
            ins[p]=row;p+=len(bytes.fromhex(row['hex']))
        check(p==end,'Complete end instruction '+r['id']);ncode+=1
        origin=int(r['boundary_origin'],0)
        if origin!=start:check(start in [int(x['va'],0) for x in pe.disasm(origin,end)],'Known function boundary '+r['id'])
    assertions=[]
    def exact(va,h,label):
        check(va in ins and ins[va]['hex']==h and pe.at(va,len(bytes.fromhex(h))).hex()==h,label)
        assertions.append(dict(va=hex(va),label=label))
    def call(va,target):
        pe.relcall(va,target);check(va in ins,'CALL on decoded boundary');assertions.append(dict(va=hex(va),target=hex(target)))
    for va,h,label in [
      (0x807bb0,'0fb733','Frame n is little-endian WORD'),
      (0x807bb5,'663bf1','Frame n==0 rejection comparison'),
      (0x807bc3,'663bf2','Frame n<=0x1000 comparison'),
      (0x807c0e,'c744242006000000','BBB header six bytes'),
      (0x807c2c,'c744242004000000','1A68/raw header four bytes'),
      (0x807d35,'34b6','BBB differential XOR seed B6'),
      (0x807d53,'3244142b','BBB XOR preceding decoded byte'),
      (0x807d5f,'6603c8','BBB sum modulo 65536'),
      (0x807d66,'66394b04','BBB checksum compared at frame+4'),
      (0x807d9e,'8b8980a00000','Lane read from Conn+A080'),
      (0x4930ed,'0fb738','App opcode WORD read before length check'),
      (0x493108,'83e802','Only lane2 dispatched'),
      (0x48acac,'c78700020000045bc000','C+200 frontend vtable installed'),
      (0x48c027,'8d43f8','Initializer full C base = C+8 argument minus8'),
      (0x48aada,'0fbfc3','Frontend signed WORD index'),
      (0x48aae6,'8b4cc70c','Frontend adjust at F+0C+16*op'),
      (0x48aaed,'8b4608','Frontend handler at F+8+16*op'),
      (0x48ab34,'8d8c3800feffff','Frontend this adjustment back to full C'),
      (0x4ae1fd,'c7805c07000090614b00','Field primary 00EB handler'),
      (0x4b61ea,'33c0','00EB returns zero; no yield0x100'),
      (0x56210c,'830d3088fb0002','Wait sets input mask2'),
      (0x562307,'83253088fb00fd','Unlock clears input mask2'),
      (0x4a39a6,'833d98a7fb0000','003F send guard'),
      (0x4a39dc,'6a08','003F payload eight bytes'),
      (0x4a39e2,'6a00','003F transport key0'),
      (0x5618c6,'6a00','Skip path sends first key zero'),
      (0x5618ef,'897328','Active set after skip branch'),
      (0x561f69,'897728','Normal End clears active before report'),
    ]:exact(va,h,label)
    for va,target in [(0x806e08,0x807b40),(0x807d7a,0x807e50),(0x807da6,0x489920),(0x807dad,0x8040a0),(0x49198a,0x804740),(0x48ac87,0x804380),(0x48c02a,0x493170),(0x4c4694,0x4fda30),(0x4b61e5,0x562250),(0x5622db,0x753440),(0x5618c8,0x4a39a0),(0x5618cd,0x5620b0),(0x561fb0,0x4a39a0),(0x561fe0,0x4a39a0),(0x561fe5,0x5620b0),(0x56202d,0x4ad0a0),(0x491ed7,0x561520),(0x491fdd,0x804a40)]:call(va,target)
    for slot,target in [(0xc05aa4+0x20,0x48be50),(0xc05aa4+0x30,0x490fe0),(0xc05aec,0x4930e0),(0xc05b04+4,0x48aad0),(0xc06eb4+4,0x4fda30),(0xc073b4+4,0x4c4670),(0xc0705c+4,0x4c4670),(0xc51748+0x10,0x8069a0)]:check(pe.u32(slot)==target,'Vtable slot '+hex(slot))

    # Complete, narrowly recognized static initialization data flow. No x86 code execution.
    init=next(x['instructions'] for x in native['records'] if x['id']=='frontend_registration_full')
    fixed=[];regs={'esi':0,'ecx':0xbf2375};nonstores=[]
    for r in init:
        if int(r['va'],0)<0x49319e:continue
        mat=re.fullmatch(r'mov\s+(edx|ecx),0x([0-9a-f]+)',r['asm'])
        if mat:regs[mat[1]]=int(mat[2],16);continue
        mat=re.fullmatch(r'mov\s+DWORD PTR \[eax\+0x([0-9a-f]+)\],(edx|esi|ecx)',r['asm'])
        if mat:fixed.append(dict(va=r['va'],offset=hex(int(mat[1],16)),value=hex(regs[mat[2]]),register=mat[2],hex=r['hex']))
        else:nonstores.append(r['asm'])
    check(nonstores==['pop    edi','pop    esi','pop    ebx','ret'],'No omitted post-loop instructions or alias writes')
    check(fixed==tables['fixed_stores'] and len(fixed)==591,'Complete fixed-store collection')
    handlers=[dict(x,opcode=hex((int(x['offset'],0)-0x208)//16)) for x in fixed if (int(x['offset'],0)-0x208)%16==0]
    check(handlers==tables['handler_overrides'] and len(handlers)==197,'All 197 handler overrides')
    for op in [0x4c,0x4e,0xeb]:
        off=0x208+op*16
        check(not any(off<=int(x['offset'],0)<off+12 for x in fixed),'Untouched initialized record '+hex(op))
    check(pe.at(0x493180,5).hex()=='bed50b0000' and pe.at(0x493198,3).hex()=='83c210','Count3029 stride16')
    check(pe.at(0x493173,5).hex()=='bf60434900' and pe.at(0x493178,2).hex()=='33db','Initial default and zero adjust')
    check(4+0xeb*8==0x75c and 0x5eac+0xeb*8==0x6604,'Two field slot offsets')
    # All raw E8 candidates are independently checked on instruction boundaries.
    candidates=[]
    for name,start,_,size,raw in pe.sections:
        if name!='.text':continue
        b=pe.b[raw:raw+size]
        for i in range(len(b)-4):
            if b[i]==0xe8 and start+i+5+struct.unpack_from('<i',b,i+1)[0]==0x4a39a0:candidates.append(start+i)
    check(candidates==[0x5618c8,0x561fb0,0x561fe0],'Bounded complete direct-call candidate set')
    check(all(x in ins for x in candidates),'All candidate calls on original decoded boundaries')
    check([hex(x) for x in candidates]==contracts['c2s003f']['direct_call_candidates'],'Contract caller list')

    # SYN: selected receiver-arithmetic model; not an executed Client or official packet.
    def selected_decode(stream):
        packets=[];consumed=0
        while len(stream)-consumed>=4:
            n,marker=struct.unpack_from('<HH',stream,consumed)
            check(1<=n<=0x1000,'SYN valid n')
            check(marker in (0x1a68,0xbbb),'SYN selected forms only')
            header=6 if marker==0xbbb else 4
            if len(stream)-consumed<header+n:break
            payload=stream[consumed+header:consumed+header+n]
            if marker==0xbbb:
                decoded=[];last=0xb6
                for c in payload:last=c^last;decoded.append(last)
                payload=bytes(decoded)
                valid=(sum(payload)&0xffff)==struct.unpack_from('<H',stream,consumed+4)[0]
            else:valid=True
            if valid:packets.append(payload)
            consumed+=header+n
        return packets,stream[consumed:]
    frames=[bytes.fromhex(x['hex']) for x in contracts['frames']]
    check(frames==[bytes.fromhex('0200681aeb00'),bytes.fromhex('0200bb0beb005deb')],'Exact SYN vectors')
    syn=[]
    for i,frame in enumerate(frames):
        check(selected_decode(frame)==([b'\xeb\0'],b''),'SYN complete frame')
        for n in range(1,len(frame)):
            p,tail=selected_decode(frame[:n]);check(p==[] and tail==frame[:n],'SYN incomplete frame retained')
        syn.append(dict(form=contracts['frames'][i]['label'],wire_hex=frame.hex(),complete=True,incomplete_prefixes=len(frame)-1))
    check(selected_decode(frames[0]+frames[1])==([b'\xeb\0',b'\xeb\0'],b''),'SYN multiple frames')
    bad=bytearray(frames[1]);bad[4]^=1
    check(selected_decode(bytes(bad)+frames[0])==([b'\xeb\0'],b''),'SYN checksum fail consumes frame without business payload')

    env={**os.environ,'GIT_NO_LAZY_FETCH':'1','GIT_OPTIONAL_LOCKS':'0','GIT_TERMINAL_PROMPT':'0','GIT_NO_REPLACE_OBJECTS':'1'}
    for r in manifest['references']:
        path=a.repo/r['repo_path'];content=path.read_bytes() if path.is_file() else subprocess.check_output(['git','cat-file','blob',r['repo_blob']],cwd=a.repo,env=env)
        actual=subprocess.check_output(['git','rev-parse',r['repo_commit']+':'+r['repo_path']],cwd=a.repo,env=env,text=True).strip()
        check(actual==r['repo_blob'],'Fixed commit/path/blob '+r['repo_path'])
        check(len(content)==r['size'] and sha(content)==r['sha256'],'Source bytes '+r['repo_path'])
        check(hashlib.sha1(b'blob '+str(len(content)).encode()+b'\0'+content).hexdigest()==r['repo_blob'],'Source Git object identity')
    result=dict(schema='mef-world-wire-verification-v1',status='PASS',scope='Bounded static original-byte and synthetic arithmetic verification only',native_records=len(native['records']),code_windows=ncode,instructions=sum(len(x.get('instructions',[])) for x in native['records']),bytes=sum(x['length'] for x in native['records']),anchor_assertions=len(assertions),frontend_fixed_stores=591,frontend_unique_overrides=197,source_pins=len(manifest['references']),direct_003f_callers=3,synthetic_vectors=syn,synthetic_multi_frame=True,synthetic_checksum_drop=True,client_executed=False,lua_executed=False,network_transmitted=False,official_server_pairing_proved=False,assertions=assertions)
    text=json.dumps(result,ensure_ascii=False,indent=2)+'\n'
    if a.out:a.out.write_text(text)
    print(text)
if __name__=='__main__':main()
