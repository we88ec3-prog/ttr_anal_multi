#!/usr/bin/env python3
"""Read-only static validation of original prepass/resource contracts.

Client and Lua are never executed. Git is read with lazy fetch disabled. SYN
examples are bounded integer contract counterexamples, not a native emulator.
"""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import struct
import subprocess
import sys
sys.dont_write_bytecode=True
def check(v,msg):
    if not v:raise ValueError(msg)
def sha(b):return hashlib.sha256(b).hexdigest()
def load(p):return json.loads(p.read_text())

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin',type=Path,required=True)
    ap.add_argument('--repo',type=Path,required=True)
    ap.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
    ap.add_argument('--out',type=Path)
    args=ap.parse_args();e=args.evidence_dir
    m=load(e/'source-manifest.json');native=load(e/'native-windows.json');t=load(e/'contracts.json')
    helper=args.repo/'kr-extra-roy/MEF-runtime-contracts-20261115/input-lifecycle/verify_evidence.py'
    pin=next(x for x in m['references'] if x['path'].endswith('input-lifecycle/verify_evidence.py'))
    check(sha(helper.read_bytes())==pin['sha256'],'Pinned read-only PE helper')
    sp=importlib.util.spec_from_file_location('r8_bridge_pe',helper);mod=importlib.util.module_from_spec(sp);sp.loader.exec_module(mod)
    pe=mod.PE(args.bin,native['binary']);ins={}
    for r in native['records']:
        s=int(r['va'],0);end=int(r['end'],0);b=pe.at(s,r['length'])
        check(end==s+r['length'] and int(r['raw'],0)==pe.raw(s,len(b)),'VA/raw mapping '+r['id'])
        check(b.hex()==r['hex'] and sha(b)==r['sha256'],'Original selected bytes '+r['id'])
        if r['kind']=='code':
            actual=pe.disasm(s,end);check(actual==r['instructions'],'Original disassembly '+r['id']);p=s
            for x in actual:
                check(int(x['va'],0)==p and '(bad)' not in x['asm'] and '.byte' not in x['asm'],'Instruction boundary '+r['id'])
                p+=len(bytes.fromhex(x['hex']));ins[int(x['va'],0)]=x
            check(p==end,'Complete final instruction '+r['id'])
    for a in t['anchors']:
        p=int(a['va'],0);check(p in ins and ins[p]['hex']==a['hex'],'Exact semantic anchor '+a['label'])
    for link in t['direct_links']:
        a=int(link['callsite'],0);target=int(link['target'],0)
        pe.relcall(a,target);check(a in ins,'Direct call on decoded boundary')
    for imp in t['imports']:
        a=int(imp['iat'],0);p=int(imp['name_va'],0)
        check(pe.u32(a)+pe.base+2==p and pe.string(p)==imp['name'],'Original IAT symbol '+imp['name'])
    expected={0xbd20fc:'WaitForSingleObject',0xbd21c8:'CloseHandle',0xbd20cc:'CreateEventW',0xbd20d0:'SetEvent',0xbd224c:'EnterCriticalSection',0xbd2248:'LeaveCriticalSection'}
    check({int(x['iat'],0):x['name'] for x in t['imports']}==expected,'Native import identities')
    for a,target in [(0x561c03,0xbd20fc),(0x561c0a,0xbd21c8),(0x79dd87,0xbd20cc),(0x79e08e,0xbd20d0),(0x541729,0xbd20fc)]:
        check(pe.at(a,6)==b'\xff\x15'+struct.pack('<I',target) and a in ins,'Import call boundary')
    check(pe.at(0x561bfe,18).hex()=='8bf06aff56ff15fc20bd0056ff15c821bd00','Wait return unused before CloseHandle')
    for cb in t['callbacks']:
        rec=next(r for r in native['records'] if r['va']==cb['body']);body=rec['instructions'];indices=[]
        for k,x in enumerate(body):
            a=int(x['va'],0);b=bytes.fromhex(x['hex'])
            if len(b)!=5 or b[0]!=0xe8 or a+5+struct.unpack('<i',b[1:])[0]!=0x6f50f0:continue
            prev=bytes.fromhex(body[k-2]['hex'])
            if prev[:1]==b'\xb8' and len(prev)==5:idx=struct.unpack('<i',prev[1:])[0]
            else:check(prev==b'\x83\xc8\xff','Negative-index -1 instruction');idx=-1
            indices.append(idx)
        check(indices==cb['stack_indices'] and len(indices)==cb['arity'],'Exact callback argument window '+cb['name'])
    for b in t['prepass_bindings']:
        a=int(b['instruction'],0);p=int(b['name_va'],0)
        check(pe.at(a,5)==b'\xbf'+struct.pack('<I',p) and pe.string(p)==b['name'],'Rebound callback name')
    check([b['name'] for b in t['prepass_bindings']]==['CreateObject','AniObject','WalkObject','WarpObject','Register','PlayMusic'],'Six prepass overrides')
    motion=t['motion'];v=int(motion['vtable'],0);sv=int(motion['receiver_vtable'],0);td=int(motion['type_descriptor'],0)
    check(pe.u32(v-4)==0xc80304 and pe.u32(sv-4)==0xc802f0,'CMotion COL pointers')
    check(pe.u32(0xc80304+12)==td and pe.u32(0xc802f0+12)==td and pe.u32(0xc802f0+4)==4,'CMotion receiver offset and type')
    check(pe.string(td+8)==motion['type_name'],'CMotion original RTTI')
    for off,target in motion['slots'].items():check(pe.u32(v+int(off,0))==int(target,0),'CMotion primary virtual')
    check(pe.u32(sv)==int(motion['receiver_slot0'],0),'CMotion receiver virtual')

    # Explicit synthetic counterexamples of the integer contract above.
    cases=load(e/'synthetic-contracts.json')['cases'];syn=[]
    for case in cases:
        slots={};music=''
        for op in case['operations']:
            kind=op[0]
            if kind=='reset':slots={};music='';continue
            if kind=='music':music=op[1];continue
            slot=op[1]&0xffff
            if kind=='create':
                _,_,model,action=op
                if slot not in slots:
                    slots[slot]=dict(model=model&0xffff,actions=set());action=1 if action==0 else action
                slots[slot]['actions'].add(action&0xffff)
            elif kind=='clear_script_stub':pass
            elif slot in slots:
                if kind=='ani':action=op[2]
                else:
                    _,_,gate,action=op
                    if gate==0:continue
                    if action<0:action=4 if kind=='walk' else 1
                slots[slot]['actions'].add(action&0xffff)
        result=dict(slots=[dict(slot=k,model=v['model'],actions=sorted(v['actions'])) for k,v in sorted(slots.items())],music=music)
        check(result==case['expected'],'SYN integer contract '+case['id']);syn.append(case['id'])
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0');refs=m['navigation']+m['references'];groups={}
    for ref in refs:groups.setdefault(ref['commit'],[]).append(ref)
    checked=[]
    for commit,group in groups.items():
        result=subprocess.run(['git','-c','remote.origin.promisor=false','ls-tree',commit,'--',*[x['path'] for x in group]],cwd=args.repo,env=env,text=True,capture_output=True,check=True).stdout
        found={r.split(None,3)[3]:r.split(None,3)[2] for r in result.splitlines()}
        for x in group:
            check(found.get(x['path'])==x['git_blob'],'Pinned commit:path '+x['path'])
            b=subprocess.run(['git','-c','remote.origin.promisor=false','cat-file','blob',x['git_blob']],cwd=args.repo,env=env,capture_output=True,check=True).stdout
            check(len(b)==x['bytes'] and sha(b)==x['sha256'] and hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==x['git_blob'],'Pinned source content '+x['path'])
            checked.append(x['path'])
    result=dict(status='PASS',validation_kind='Static original-byte/data verification; no runtime, parser emulation or T01 FULL-PASS',records=len(native['records']),code_windows=sum(x['kind']=='code' for x in native['records']),bytes=sum(x['length'] for x in native['records']),instructions=len(ins),exact_anchors=len(t['anchors']),direct_links=len(t['direct_links']),imports=len(t['imports']),callback_argument_windows=len(t['callbacks']),synthetic_cases=len(syn),source_pins=len(refs),source_content_hashes=len(checked))
    if args.out:
        dest=args.out.resolve();check(dest!=args.bin.resolve() and not dest.is_relative_to(args.repo.resolve()/'.git'),'Result target outside inputs/Git metadata');dest.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))
if __name__=='__main__':main()
