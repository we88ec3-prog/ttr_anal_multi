#!/usr/bin/env python3
"""Read-only bounded MEF reuse verification; no Client/Lua/Server execution.

Requires objdump, Python standard library, original BIN/Event and pinned Git
source objects. Imports only the reviewed hash-pinned STPD/Lua data parser.
--out writes a derived result; it cannot overwrite any input/evidence file.
"""
from pathlib import Path
import argparse,hashlib,importlib.util,json,os,re,struct,subprocess,sys
sys.dont_write_bytecode=True
BIN_SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
PARSER_SHA='8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56'

def check(ok,why):
    if not ok: raise ValueError(why)
def digest(b):return hashlib.sha256(b).hexdigest()
def number(x):return int(x,0) if isinstance(x,str) else x
def readj(p):return json.loads(p.read_text())
def load_module(path,name):
    spec=importlib.util.spec_from_file_location(name,path)
    mod=importlib.util.module_from_spec(spec);sys.modules[name]=mod;spec.loader.exec_module(mod)
    return mod

class PE:
    def __init__(self,path):
        self.path=path;self.data=path.read_bytes()
        check(len(self.data)==12472320 and digest(self.data)==BIN_SHA,'BIN identity')
        b=self.data;p=struct.unpack_from('<I',b,0x3c)[0];o=p+24
        check(b[:2]==b'MZ' and b[p:p+4]==b'PE\0\0','PE headers')
        check(struct.unpack_from('<H',b,p+4)[0]==0x14c and struct.unpack_from('<H',b,o)[0]==0x10b,'PE32/i386')
        self.base=struct.unpack_from('<I',b,o+28)[0];check(self.base==0x400000,'Image base')
        self.sections=[];head=o+struct.unpack_from('<H',b,p+20)[0]
        for i in range(struct.unpack_from('<H',b,p+6)[0]):
            at=head+40*i;vs,rv,rs,ro=struct.unpack_from('<IIII',b,at+8)
            self.sections.append((self.base+rv,rs,ro))
    def raw(self,va,size):
        hits=[ro+va-a for a,rs,ro in self.sections if a<=va and va+size<=a+rs]
        check(len(hits)==1,'Raw-backed PE mapping '+hex(va));return hits[0]
    def at(self,va,size):
        p=self.raw(va,size);return self.data[p:p+size]
    def decode(self,a,z):
        txt=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(a),'--stop-address='+hex(z+15),str(self.path)],text=True)
        out=[];cursor=a
        for line in txt.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if not m or not a<=int(m[1],16)<z:continue
            va=int(m[1],16);b=bytes.fromhex(m[2]);asm=m[3].strip()
            check(va==cursor and '(bad)' not in asm and b==self.at(va,len(b)),'Instruction decode '+hex(va))
            cursor+=len(b);out.append([hex(va),b.hex(),asm])
        check(cursor==z,'Complete instruction endpoint '+hex(z));return out

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin',required=True,type=Path)
    ap.add_argument('--event',required=True,type=Path)
    ap.add_argument('--repo',required=True,type=Path)
    ap.add_argument('--out',type=Path)
    args=ap.parse_args();root=Path(__file__).resolve().parent
    check(not sys.flags.optimize,'Do not use optimized Python')
    proof=readj(root/'native-evidence.json');sources=readj(root/'source-manifest.json');qbase=readj(root/'qbase-evidence.json')
    pe=PE(args.bin);instructions={};all_asm=[]
    for w in proof['windows']:
        a=number(w['va']);z=number(w['end_exclusive']);b=pe.at(a,z-a)
        check(w['length']==z-a and pe.raw(a,z-a)==number(w['raw_offset']),'Window mapping '+w['id'])
        check(b.hex()==w['hex'] and digest(b)==w['sha256'],'Window original bytes '+w['id'])
        rows=pe.decode(a,z)
        check(len(rows)==w['instruction_count'],'Instruction count '+w['id'])
        # Mnemonic text may vary among binutils versions; exact bytes and decoded
        # boundaries must match, and this package records the local rendering.
        check([(r[0],r[1]) for r in rows]==[(r[0],r[1]) for r in w['instructions']],'Instruction bytes/starts '+w['id'])
        instructions.update({number(r[0]):r for r in rows})
        all_asm.append('; '+w['id']+' ['+w['role']+'] '+w['va']+'..'+w['end_exclusive']+' exclusive\n'+'\n'.join(f'{number(v):08X}  {h:<32} {t}' for v,h,t in w['instructions']))
    check((root/'native-evidence.asm').read_text()=='\n\n'.join(all_asm)+'\n','ASM transcription')
    for a in proof['anchors']:
        va=number(a['va']);check(va in instructions and instructions[va][1]==a['hex'],'Selected instruction '+a['id'])
    calls={}
    for c in proof['direct_calls']:
        va=number(c['va']);b=pe.at(va,5);target=va+5+struct.unpack_from('<i',b,1)[0]
        check(va in instructions and b[0]==0xe8 and b.hex()==c['hex'] and target==number(c['target']),'Direct call '+c['id']);calls[c['id']]=va
    for row in proof['ordering_checks']:
        seq=[calls[x] for x in row];check(seq==sorted(seq) and len(seq)==len(set(seq)),'Source order '+str(row))
    for absence in proof['bounded_absence_checks']:
        w=next(x for x in proof['windows'] if x['id']==absence['window']);targets=[]
        for v,h,t in w['instructions']:
            b=bytes.fromhex(h)
            if len(b)==5 and b[0] in (0xe8,0xe9): targets.append(number(v)+5+struct.unpack_from('<i',b,1)[0])
        check(not set(targets)&{number(x) for x in absence['missing_direct_targets']},'Bounded direct-call absence only')
    # Hardcoded proof-obligation bytes prevent a changed evidence label from
    # silently losing the image correction/model replacement boundaries.
    hard={0x56496a:'e8f1000000',0x564add:'c7401400000000',0x564ae4:'c74640ffffffff',
          0x564a44:'894b40',0x561b38:'c7460403000000',0x561b3f:'c6460801',
          0x563b61:'c6470801',0x563b67:'c7470403000000',0x7a0529:'ff4e5c',
          0x7a0701:'ff465c',0x7c50da:'c7475800000000',0x7c4ac2:'885f60'}
    for va,h in hard.items():check(pe.at(va,len(bytes.fromhex(h))).hex()==h,'Native obligation '+hex(va))
    # Read-only object inspection, never fetch, checkout or alter Git index.
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0',GIT_NO_REPLACE_OBJECTS='1')
    for src in sources['repository_sources']:
        cmd=['git','-c','remote.origin.promisor=false']
        blob=subprocess.check_output(cmd+['rev-parse',sources['source_commit']+':'+src['path']],cwd=args.repo,env=env,text=True).strip()
        check(blob==src['git_blob'],'Source tree path '+src['path'])
        b=subprocess.check_output(cmd+['cat-file','blob',blob],cwd=args.repo,env=env)
        check(len(b)==src['bytes'] and digest(b)==src['sha256'],'Source content '+src['path'])
        check(hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==blob,'Git blob content '+src['path'])
    parser_path=args.repo/qbase['parser']['path']
    check(digest(parser_path.read_bytes())==PARSER_SHA==qbase['parser']['sha256'],'Reviewed data parser exact version')
    parser=load_module(parser_path,'reuse_reviewed_parser')
    archive=parser.STPD(args.event,qbase['carrier']);chunk=archive.verify_member(qbase['member']);ps=parser.read_lua51_prototypes(chunk)
    check(len(ps)==qbase['prototype_count']==76 and sum(len(p['words']) for p in ps)==qbase['instruction_word_count']==906,'Original qbase shape')
    for q in qbase['selected_prototypes']:check(ps[q['index']]==q,'Original selected qbase prototype '+str(q['index']))
    rootq=qbase['root_prefix'];check(ps[0]['code_offset']==rootq['code_offset'] and ps[0]['words'][:len(rootq['words'])]==rootq['words'] and ps[0]['constants'][:len(rootq['constants_prefix'])]==rootq['constants_prefix'],'Original qco initialization prefix')
    model=load_module(root/'reference_model.py','reuse_synthetic_model');examples=model.run_examples()
    artifact_count=0
    for a in readj(root/'artifact-manifest.json')['files']:
        b=(root/a['name']).read_bytes();check(len(b)==a['bytes'] and digest(b)==a['sha256'],'Deliverable integrity '+a['name']);artifact_count+=1
    result={'schema':'ttr-mef-reuse-verification-v1','all_matched':True,'scope':'Bounded original bytes/PE/instructions/direct edges, original qbase data, Git source pins, and explicitly SYN counterexamples only. No target execution or original-MEF/parser claim.',
      'bin_sha256':BIN_SHA,'event_sha256':qbase['carrier']['sha256'],'native_windows':len(proof['windows']),
      'native_window_bytes':sum(w['length'] for w in proof['windows']),'native_instructions':sum(w['instruction_count'] for w in proof['windows']),
      'anchors':len(proof['anchors']),'direct_calls':len(proof['direct_calls']),'source_pins':len(sources['repository_sources']),
      'qbase_selected_prototypes':len(qbase['selected_prototypes']),'qbase_selected_instruction_words':sum(len(p['words']) for p in qbase['selected_prototypes']),
      'qbase_root_prefix_words':len(rootq['words']),'artifact_integrity_files':artifact_count,'synthetic_examples':examples,
      'superseded_prior_synthetic_expectation':'MEF-feature-lifecycle-20261117/test_models.py::SyntheticOwnerTests.test_last_handle_does_not_delete_first',
      'historical_aggregate_verifier_rerun':False,'historical_aggregate_verifier_reason':'Old parser SHA pin differs from the actual pinned Git parser; this verifier uses the reviewed exact source hash.',
      'client_executed':False,'lua_executed':False,'server_executed':False,'gameplay_tested':False,'official_mef_grammar_proved':False}
    if args.out:
        protected={args.bin.resolve(),args.event.resolve(),parser_path.resolve()}
        protected.update(p.resolve() for p in root.iterdir() if p.is_file() and p.name!='verification-result.json')
        check(args.out.resolve() not in protected,'Output cannot overwrite input/evidence')
        args.out.parent.mkdir(parents=True,exist_ok=True);args.out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))
if __name__=='__main__':main()
