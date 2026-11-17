#!/usr/bin/env python3
"""Read-only original BIN/Event and Git verification for CDoll reuse addendum.

Python standard library + objdump only. No target, Lua or Server execution.
Event is checked for identity only; this addendum does not re-parse Lua.
--out is a derived result and may not overwrite source or evidence files.
"""
from pathlib import Path
import argparse, hashlib, importlib.util, json, os, re, struct, subprocess, sys
sys.dont_write_bytecode=True
BIN_SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
EVENT_SHA='2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b'
def check(ok,why):
    if not ok:raise ValueError(why)
def sha(b):return hashlib.sha256(b).hexdigest()
def num(x):return int(x,0) if isinstance(x,str) else x
def readj(p):return json.loads(p.read_text())


class PE:
    def __init__(self,path):
        self.path=path;self.data=path.read_bytes()
        check(len(self.data)==12472320 and sha(self.data)==BIN_SHA,'BIN identity')
        b=self.data;p=struct.unpack_from('<I',b,0x3c)[0];o=p+24
        check(b[:2]==b'MZ' and b[p:p+4]==b'PE\0\0','PE headers')
        check(struct.unpack_from('<H',b,p+4)[0]==0x14c and struct.unpack_from('<H',b,o)[0]==0x10b,'PE32/i386')
        self.base=struct.unpack_from('<I',b,o+28)[0];check(self.base==0x400000,'Image base')
        self.import_directory=struct.unpack_from('<II',b,o+104)
        head=o+struct.unpack_from('<H',b,p+20)[0];self.sections=[]
        for i in range(struct.unpack_from('<H',b,p+6)[0]):
            vs,rv,rs,ro=struct.unpack_from('<IIII',b,head+40*i+8)
            self.sections.append((self.base+rv,rs,ro))
    def raw(self,va,size):
        hits=[ro+va-a for a,rs,ro in self.sections if a<=va and va+size<=a+rs]
        check(len(hits)==1,'Raw-backed mapping '+hex(va));return hits[0]
    def at(self,va,size):
        p=self.raw(va,size);return self.data[p:p+size]
    def decode(self,a,z):
        t=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(a),'--stop-address='+hex(z+15),str(self.path)],text=True)
        rows=[];cursor=a
        for line in t.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if not m or not a<=int(m[1],16)<z:continue
            va=int(m[1],16);b=bytes.fromhex(m[2]);asm=m[3].strip()
            check(va==cursor and '(bad)' not in asm and b==self.at(va,len(b)),'Decode '+hex(va))
            cursor+=len(b);rows.append([hex(va),b.hex(),asm])
        check(cursor==z,'Instruction endpoint '+hex(z));return rows
    def imports(self):
        rv,size=self.import_directory;out={}
        def string(va):
            p=self.raw(va,1);z=self.data.index(b'\0',p);return self.data[p:z].decode('ascii')
        for i in range(size//20):
            oft,stamp,chain,name,ft=struct.unpack('<IIIII',self.at(self.base+rv+i*20,20))
            if not any((oft,stamp,chain,name,ft)):break
            dll=string(self.base+name);k=0
            while True:
                x=struct.unpack('<I',self.at(self.base+(oft or ft)+k*4,4))[0]
                if not x:break
                if not x&0x80000000:
                    out[self.base+ft+k*4]={'dll':dll,'symbol':string(self.base+x+2),'hint_name_va':hex(self.base+x)}
                k+=1
        return out


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    for a in ('bin','event','repo'):ap.add_argument('--'+a,required=True,type=Path)
    ap.add_argument('--out',type=Path);args=ap.parse_args()
    check(not sys.flags.optimize,'Do not use optimized Python')
    root=Path(__file__).resolve().parent;pe=PE(args.bin)
    event=args.event.read_bytes();check(len(event)==11241597 and sha(event)==EVENT_SHA,'Event identity only')
    proof=readj(root/'native-evidence.json');sources=readj(root/'source-manifest.json')
    check(proof['binary']['sha256']==BIN_SHA and sources['bin']['sha256']==BIN_SHA,'Manifest BIN identity')
    check(sources['event']['sha256']==EVENT_SHA,'Manifest Event identity')
    instructions={};asms=[]
    for w in proof['windows']:
        a=num(w['va']);z=num(w['end_exclusive']);b=pe.at(a,z-a)
        check(num(w['decoding_origin'])==a,'Recorded decode origin '+w['id'])
        check(w['length']==z-a and num(w['raw_offset'])==pe.raw(a,z-a),'Mapping '+w['id'])
        check(w['hex']==b.hex() and w['sha256']==sha(b),'Original bytes '+w['id'])
        rows=pe.decode(a,z)
        check(len(rows)==w['instruction_count'],'Instruction count '+w['id'])
        check([(x[0],x[1]) for x in rows]==[(x[0],x[1]) for x in w['instructions']],'Decoded byte boundaries '+w['id'])
        instructions.update({num(r[0]):r for r in rows})
        asms.append('; '+w['id']+' ['+w['role']+'] '+w['va']+'..'+w['end_exclusive']+' exclusive\n'+'\n'.join(f'{num(v):08X}  {h:<32} {t}' for v,h,t in w['instructions']))
    check((root/'native-evidence.asm').read_text()=='\n\n'.join(asms)+'\n','ASM transcription')
    for a in proof['anchors']:
        va=num(a['va']);check(va in instructions and instructions[va][1]==a['hex'],'Instruction anchor '+a['id'])
    calls={}
    for c in proof['direct_calls']:
        va=num(c['va']);b=pe.at(va,5)
        check(va in instructions and b[0]==0xe8 and b.hex()==c['hex'],'Call instruction '+c['id'])
        check(va+5+struct.unpack_from('<i',b,1)[0]==num(c['target']),'Call target '+c['id']);calls[c['id']]=va
    for row in proof['ordering_checks']:
        seq=[calls[x] for x in row];check(seq==sorted(seq) and len(set(seq))==len(seq),'Selected source ordering')
    for d in proof['data_words']:
        va=num(d['va']);b=pe.at(va,4)
        check(num(d['raw_offset'])==pe.raw(va,4) and b.hex()==d['hex'] and struct.unpack('<I',b)[0]==num(d['pointer']),'Original vtable word '+d['id'])
    imports=pe.imports()
    for x in proof['iat_imports']:
        check(imports[num(x['iat_va'])]=={k:v for k,v in x.items() if k!='iat_va'},'PE import '+x['symbol'])
    for missing in proof['bounded_absence_checks']:
        w=next(w for w in proof['windows'] if w['id']==missing['window']);targets=[]
        for va,h,t in w['instructions']:
            b=bytes.fromhex(h)
            if len(b)==5 and b[0] in (0xe8,0xe9):targets.append(num(va)+5+struct.unpack_from('<i',b,1)[0])
        check(not set(targets)&{num(x) for x in missing['missing_direct_targets']},'Bounded direct-target absence '+w['id'])
    # Non-negotiable proof obligations include the actual direct caller, both
    # independent resource writers, original-Doll target and failure retry gate.
    hard={0x56322e:'e8adddf6ff',0x4d0fe1:'6a01',0x4c7ee6:'c6402001',
          0x79e9d1:'8b7854',0x79eb03:'ff475c',0x79f045:'e8966b0200',
          0x79ed58:'8b7054',0x79ed76:'ff4e5c',0x7a8fcb:'837b2400',
          0x7a8fd2:'885604',0x7a5ca1:'83f803',0x7a913a:'c7432403000000',
          0x79dc57:'8b4008',0x79dc5a:'8b4068',0x7aa9ce:'8b776c',
          0x7c490c:'c6436001',0x7c5129:'83bbec00000000'}
    for va,h in hard.items():check(pe.at(va,len(bytes.fromhex(h))).hex()==h,'Native obligation '+hex(va))
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0',GIT_NO_REPLACE_OBJECTS='1')
    for src in sources['repository_sources']:
        cmd=['git','-c','remote.origin.promisor=false']
        blob=subprocess.check_output(cmd+['rev-parse',sources['source_commit']+':'+src['path']],cwd=args.repo,env=env,text=True).strip()
        check(blob==src['git_blob'],'Pinned Git path '+src['path'])
        b=subprocess.check_output(cmd+['cat-file','blob',blob],cwd=args.repo,env=env)
        check(len(b)==src['bytes'] and sha(b)==src['sha256'],'Pinned source bytes '+src['path'])
        check(hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==blob,'Pinned Git object')
    spec=importlib.util.spec_from_file_location('reuse_followup_syn',root/'reference_model.py')
    model=importlib.util.module_from_spec(spec);sys.modules[spec.name]=model;spec.loader.exec_module(model)
    examples=model.run_examples()
    manifest=readj(root/'artifact-manifest.json')
    for a in manifest['files']:
        b=(root/a['name']).read_bytes();check(len(b)==a['bytes'] and sha(b)==a['sha256'],'Deliverable integrity '+a['name'])
    result={'schema':'ttr-mef-reuse-followup-verification-v1','all_matched':True,
      'scope':'Original bytes, PE mappings, contiguous decoded boundaries, selected calls/dataflow gates, vtable words, import names, pinned Git guides and SYN counterexamples only.',
      'bin_sha256':BIN_SHA,'event_sha256':EVENT_SHA,'event_identity_only':True,
      'native_windows':len(proof['windows']),'native_prefix_windows':sum(w['kind'].startswith('selected') for w in proof['windows']),
      'native_window_bytes':sum(w['length'] for w in proof['windows']),'native_instructions':sum(w['instruction_count'] for w in proof['windows']),
      'anchors':len(proof['anchors']),'direct_calls':len(proof['direct_calls']),'data_words':len(proof['data_words']),
      'pe_imports':len(proof['iat_imports']),'source_pins':len(sources['repository_sources']),
      'artifact_integrity_files':len(manifest['files']),'synthetic_examples':examples,
      'client_executed':False,'lua_executed':False,'server_executed':False,'gameplay_tested':False,
      'official_mef_grammar_proved':False,'all_assets_ready_proved':False,'global_cancellation_absence_proved':False}
    if args.out:
        protected={args.bin.resolve(),args.event.resolve()}
        protected.update(p.resolve() for p in root.iterdir() if p.is_file() and p.name!='verification-result.json')
        check(args.out.resolve() not in protected,'Output cannot overwrite input/evidence')
        args.out.parent.mkdir(parents=True,exist_ok=True);args.out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))


if __name__=='__main__':main()
