#!/usr/bin/env python3
"""Read-only original-byte verification of bounded Q input lifecycle evidence.

Parses PE and Lua chunk bytes as data, invokes objdump only for decoding, and
checks fixed Git trees/local source contents. Never executes Client/Lua, fetches,
or writes to original inputs or Git. This is not runtime/full-protocol validation.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode=True
def check(ok,message):
    if not ok:raise ValueError(message)
def sha(b):return hashlib.sha256(b).hexdigest()
def load(p):return json.loads(p.read_text())

class PE:
    def __init__(self,path,identity):
        self.path=path;self.b=path.read_bytes()
        check(len(self.b)==identity['size'] and sha(self.b)==identity['sha256'],'Original BIN identity')
        pe=struct.unpack_from('<I',self.b,0x3c)[0]
        check(self.b[pe:pe+4]==b'PE\0\0','PE signature')
        check(struct.unpack_from('<H',self.b,pe+4)[0]==0x14c,'PE i386')
        n=struct.unpack_from('<H',self.b,pe+6)[0];opt=struct.unpack_from('<H',self.b,pe+20)[0]
        self.base=struct.unpack_from('<I',self.b,pe+24+28)[0]
        check(self.base==int(identity['imagebase'],0),'ImageBase')
        self.sections=[]
        for i in range(n):
            p=pe+24+opt+i*40;name=self.b[p:p+8].rstrip(b'\0').decode()
            vs,rva,rs,r=struct.unpack_from('<4I',self.b,p+8)
            self.sections.append((name,self.base+rva,vs,rs,r))
    def raw(self,va,n):
        for _,start,_,size,r in self.sections:
            if start<=va and va+n<=start+size:return r+va-start
        raise ValueError('VA outside original raw bytes '+hex(va))
    def at(self,va,n):
        r=self.raw(va,n);return self.b[r:r+n]
    def u32(self,va):return struct.unpack('<I',self.at(va,4))[0]
    def string(self,va):
        p=self.raw(va,1);q=self.b.index(b'\0',p,p+512);return self.b[p:q].decode('ascii')
    def disasm(self,start,end):
        out=subprocess.run(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(start),'--stop-address='+hex(end+15),str(self.path)],capture_output=True,text=True,check=True).stdout
        result=[]
        for line in out.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if not m:continue
            a=int(m[1],16)
            if a>=end:continue
            b=bytes.fromhex(m[2]);result.append(dict(va=hex(a),raw=hex(self.raw(a,len(b))),hex=b.hex(),asm=m[3].strip()))
        return result
    def relcall(self,va,target):
        b=self.at(va,5)
        check(b[0]==0xe8 and va+5+struct.unpack('<i',b[1:])[0]==target,f'CALL {va:x}->{target:x}')

def parse_lua(data):
    """Bounded Lua 5.1 data parser, adapted from the pinned published verifier."""
    check(data[:12].hex()=='1b4c75615100010404040800','Lua 5.1 fixed chunk header')
    pos=12;protos=[]
    def take(fmt):
        nonlocal pos
        r=struct.unpack_from('<'+fmt,data,pos);pos+=struct.calcsize('<'+fmt);return r
    def string():
        nonlocal pos
        n=take('I')[0]
        if not n:return None
        check(pos+n<=len(data) and data[pos+n-1]==0,'Lua string bounds')
        s=data[pos:pos+n-1].decode('ascii');pos+=n;return s
    def proto(parent):
        nonlocal pos
        i=len(protos);p=dict(index=i,parent=parent);protos.append(p)
        p['source']=string();p['first'],p['last']=take('II')
        p['nups'],p['params'],p['vararg'],p['stack']=take('BBBB')
        n=take('I')[0];p['code_offset']=pos;p['words']=list(take('I'*n))
        constants=[]
        for _ in range(take('I')[0]):
            k=take('B')[0]
            if k==0:v=None
            elif k==1:v=bool(take('B')[0])
            elif k==3:v=take('d')[0]
            elif k==4:v=string()
            else:raise ValueError('Lua constant tag '+str(k))
            constants.append(v)
        p['constants']=constants;p['children']=[proto(i) for _ in range(take('I')[0])]
        take('I'*take('I')[0])
        for _ in range(take('I')[0]):string();take('II')
        for _ in range(take('I')[0]):string()
        return i
    proto(None);check(pos==len(data),'Full bounded qbase chunk consumed');return protos

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin',type=Path,required=True)
    ap.add_argument('--event-stp',type=Path,required=True)
    ap.add_argument('--repo',type=Path,required=True)
    ap.add_argument('--source-cache',type=Path,help='Optional already-read navigation .c copies; no fetch')
    ap.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
    ap.add_argument('--out',type=Path,help='Optional result JSON outside original inputs and Git')
    args=ap.parse_args();e=args.evidence_dir
    native=load(e/'native-windows.json');tables=load(e/'tables.json');manifest=load(e/'source-manifest.json')
    pe=PE(args.bin,native['binary']);ins={};code_count=0
    for r in native['records']:
        a=int(r['va'],0);end=int(r['end'],0);b=pe.at(a,r['length'])
        check(end==a+r['length'] and pe.raw(a,len(b))==int(r['raw'],0),'Window mapping '+r['id'])
        check(b.hex()==r['hex'] and sha(b)==r['sha256'],'Original bytes '+r['id'])
        if r['kind']=='code':
            actual=pe.disasm(a,end);check(actual==r['instructions'],'Native decoding '+r['id'])
            p=a
            for i in actual:
                check(int(i['va'],0)==p,'Continuous instruction boundary '+r['id'])
                check(pe.at(p,len(bytes.fromhex(i['hex']))).hex()==i['hex'],'Decoded bytes')
                p+=len(bytes.fromhex(i['hex']));ins[int(i['va'],0)]=i
            check(p==end,'Complete final instruction '+r['id']);code_count+=1
    assertions=[]
    def exact(va,hexbytes,label):
        b=bytes.fromhex(hexbytes);check(pe.at(va,len(b))==b,label)
        check(va in ins and ins[va]['hex']==hexbytes,'Anchor is complete decoded instruction '+label)
        assertions.append(dict(va=hex(va),label=label))
    for va,b,label in [
        (0x5629ce,'83253088fb00fd','Enable clears mask value 0x2'),
        (0x562a3e,'830d3088fb0002','Disable sets mask value 0x2'),
        (0x56210c,'830d3088fb0002','Wait helper sets mask value 0x2'),
        (0x562307,'83253088fb00fd','Unlock helper clears mask value 0x2'),
        (0x56284a,'83253088fb00fd','Stop intermediate clear before End'),
        (0x568bf6,'8b0d7827fe00','Enable receiver comes from Rebind slot'),
        (0x568bfc,'ff158c27fe00','Enable indirect native target'),
        (0x568c02,'b801000000','Enable C result count is 1'),
        (0x568c56,'8b0d7827fe00','Disable receiver comes from Rebind slot'),
        (0x568c5c,'ff159027fe00','Disable indirect native target'),
        (0x568790,'a17427fe00','Rebind uses stored wrapper'),
        (0x56879a,'a37827fe00','Rebind changes native receiver slot'),
        (0x561587,'837f2800','Q active gate'),
        (0x5615c4,'897058','Q sets current controller+58'),
        (0x5615c7,'837f2c00','Pump gate checked after controller write'),
        (0x561f69,'897728','Normal End clears M+28 with zero ESI'),
        (0x6d4b35,'833d3088fb0000','Input action mask consumer'),
        (0x6d4bc8,'833d3088fb0000','Input hotkey mask consumer'),
        (0x546dad,'833d3088fb0000','Direction mapper mask consumer'),
        (0x4ae1fd,'c7805c07000090614b00','Field primary app00EB registration'),
        (0x4b7da7,'89beac5e0000','New field installed before its init'),
        (0x4b7dbc,'ffd2','New field virtual init'),
    ]:exact(va,b,label)
    rels=[(0x5615d8,0x6f4dd0),(0x561fe5,0x5620b0),(0x56288c,0x561db0),(0x5622db,0x753440),(0x4b61e5,0x562250),(0x4c4694,0x4fda30),(0x568795,0x4a2bb0)]
    rels += [(int(x['callsite'],0),int(x['target'],0)) for x in tables['main_order']]
    for a,t in rels:pe.relcall(a,t);check(a in ins,'Verified call boundary');assertions.append(dict(va=hex(a),target=hex(t)))

    bindings=tables['q_regular_bindings'];check(len(bindings)==63 and tables['q_binding_count']==64,'Q binding count')
    init=next(r for r in native['records'] if r['id']=='q_initialize')['instructions']
    targets=[]
    for i in init:
        b=bytes.fromhex(i['hex']);a=int(i['va'],0)
        if len(b)==5 and b[0]==0xe8:
            t=a+5+struct.unpack('<i',b[1:])[0]
            if 0x565f20<=t<=0x5685e0:targets.append((a,t))
    check(targets==[(int(x['callsite'],0),int(x['registrar'],0)) for x in bindings],'Complete regular registrar list from initializer')
    names=[]
    for r in bindings:
        a=int(r['registrar'],0);store=r['stores'][0];s=r['strings'][0];cb=r['callbacks'][0]
        pe.relcall(int(r['callsite'],0),a)
        check(pe.at(int(store['va'],0),10)==b'\xc7\x05'+struct.pack('<II',int(store['slot'],0),int(store['value'],0)),'Binding target store')
        check(pe.at(int(s['va'],0),5)==b'\x68'+struct.pack('<I',int(s['ptr'],0)) and pe.string(int(s['ptr'],0))==s['value'],'Binding name')
        check(pe.at(int(cb['va'],0),5)==b'\x68'+struct.pack('<I',int(cb['callback'],0)),'Binding closure')
        names.append(s['value'])
    check(len(set(names))==63 and not ({'Stop','Pause','Resume'}&set(names)),'Bounded original Q namespace names')
    check(pe.at(0x565e4b,5)==b'\xa3'+struct.pack('<I',0xfe2778),'Original Q receiver store')
    check(pe.string(0xc06224)=='Rebind','Rebind binding name')

    expected=sorted(int(r['callsite'],0) for r in tables['unlock_direct_callers']);actual=[]
    for name,start,_,size,raw in pe.sections:
        if name!='.text':continue
        b=pe.b[raw:raw+size]
        for off,v in enumerate(b[:-4]):
            if v==0xe8 and start+off+5+struct.unpack_from('<i',b,off+1)[0]==0x562250:actual.append(start+off)
    check(actual==expected and len(actual)==13,'Bounded exact direct-call candidate set for 562250')
    for a in actual:pe.relcall(a,0x562250);check(a in ins,'All 13 callers on decoded boundaries')
    for h in tables['scene_init_unlocks']:
        a=int(h['stop_call'],0);b=int(h['unlock_call'],0)
        pe.relcall(a,0x5624b0);check(a<b,'Init Stop before unlock')
        check(pe.u32(int(h['vtable'],0)+0x10)==int(h['init'],0),'Init vtable binding')
    for vt in tables['vtables']:
        a=int(vt['vtable'],0);col=int(vt['col'],0);td=int(vt['type_descriptor'],0)
        check(pe.u32(a-4)==col and pe.u32(col+12)==td and pe.string(td+8)==vt['type_name'],'Native RTTI '+vt['class_name'])
        for off,target in vt['slots'].items():check(pe.u32(a+int(off,0))==int(target,0),'Native vtable slot')
    for a,t in [(0x4224e5,0x4bb010),(0x4bc245,0x4bb010),(0x4c0680,0x4bb010),(0x4c5055,0x4bb010)]:pe.relcall(a,t)
    check((0x75c-4)//8==0xeb and 0x5eac+0xeb*8==0x6604,'00EB table offsets')
    check(all(x['app_command']!='00EB' for x in tables['scene_manager_overrides']),'00EB uses initialized SceneManager default')
    for x in tables['scene_manager_overrides']:
        a=int(x['va'],0);slot=int(x['slot'],0);target=int(x['target'],0)
        check(pe.at(a,10)==b'\xc7\x05'+struct.pack('<II',slot,target),'SceneManager override original')
        check(int(x['app_command'],16)==(slot-0xfd2cfc)//8,'SceneManager command index')
    check([hex(pe.u32(0x4b9994+i*4)) for i in range(8)]==tables['decision_subtype_targets'],'Decision subtype table')

    event=args.event_stp.read_bytes();event_id=next(x for x in manifest['originals'] if x['file']=='06-Event.stp')
    check(len(event)==event_id['size'] and sha(event)==event_id['sha256'],'Original Event.stp identity')
    lua=load(e/'qbase-tail.json');m=lua['member'];stored=event[m['stored_offset']:m['stored_offset']+m['stored_length']]
    decoded=bytes(x^255 for x in stored)
    check(sha(stored)==m['stored_sha256'] and sha(decoded)==m['decoded_sha256'],'Pinned bounded qbase member bytes')
    protos=parse_lua(decoded);p=protos[74]
    check(len(protos)==76 and p['code_offset']==lua['prototype']['code_offset'] and p['constants']==lua['prototype']['constants'] and len(p['words'])==lua['prototype']['word_count'],'Original RevPhase1 structure and constants')
    for r in lua['selected_words']:
        off=p['code_offset']+r['pc']*4;w=p['words'][r['pc']]
        check(off==r['chunk_offset'] and stored[off:off+4].hex()==r['stored_hex'] and decoded[off:off+4].hex()==r['decoded_hex'] and w==r['word'],'Original selected Lua word')
        check((w&63,(w>>6)&255,(w>>23)&511,(w>>14)&511,w>>14)==(r['opcode'],r['A'],r['B'],r['C'],r['Bx']),'Lua operands')
    check(p['constants'][22:24]==['EnableInput','EndCutScene'],'Q tail names')
    for pc in (58,61):
        w=p['words'][pc];check(w&63==28 and (w>>23)&511==1 and (w>>14)&511==1,'No-argument/no-result Lua CALL')

    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0')
    refs=manifest['references']+manifest['navigation'];groups={}
    for r in refs:groups.setdefault(r['repo_commit'],[]).append(r)
    source_checks=[]
    for commit,group in groups.items():
        out=subprocess.run(['git','-c','remote.origin.promisor=false','ls-tree',commit,'--',*[r['repo_path'] for r in group]],cwd=args.repo,env=env,capture_output=True,text=True,check=True).stdout
        found={line.split(None,3)[3]:line.split(None,3)[2] for line in out.splitlines()}
        for r in group:
            check(found.get(r['repo_path'])==r['repo_blob'],'Pinned tree/blob '+r['repo_path'])
            p=args.repo/r['repo_path'];status='PIN_MATCH_CONTENT_NOT_REOPENED'
            if not p.is_file() and args.source_cache and r.get('scratch_copy'):p=args.source_cache/Path(r['scratch_copy']).name
            if p.is_file():
                b=p.read_bytes();blob=hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
                check(blob==r['repo_blob'] and sha(b)==r['sha256'] and len(b)==r['size'],'Local source identity '+r['repo_path'])
                status='PIN_AND_LOCAL_CONTENT_MATCH'
            source_checks.append(dict(path=r['repo_path'],status=status))
    result=dict(status='PASS',validation_kind='Read-only static original-byte verification, not runtime execution or T01 FULL-PASS',records=len(native['records']),code_windows=code_count,bytes=sum(r['length'] for r in native['records']),instructions=sum(len(r.get('instructions',[])) for r in native['records']),native_assertions=len(assertions),q_bindings=64,unlock_direct_callers=13,scene_init_hooks=11,vtables=len(tables['vtables']),qbase_original_prototypes=len(protos),qbase_selected_words=len(lua['selected_words']),source_pins=len(refs),local_source_contents=sum(r['status']=='PIN_AND_LOCAL_CONTENT_MATCH' for r in source_checks),source_checks=source_checks,scope=tables['scope'])
    if args.out:
        dest=args.out.resolve();check(dest not in {args.bin.resolve(),args.event_stp.resolve()},'Output is not original input')
        check(not dest.is_relative_to(args.repo.resolve()/'.git'),'Output outside Git metadata')
        dest.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({k:v for k,v in result.items() if k!='source_checks'},ensure_ascii=False,indent=2))
if __name__=='__main__':main()
