#!/usr/bin/env python3
"""Read-only checks for the bounded MEF first-caller phase contract.

Inputs are original bytes and pinned local Git objects. No network/fetch, Git
mutation, Lua execution/compilation, client execution, or game resource output.
PE/Lua readers are adapted from the separately pinned published verifier.
Only an explicitly requested verification-result JSON may be written.
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

def check(ok,why):
    if not ok:raise ValueError(why)
def sha(b):return hashlib.sha256(b).hexdigest()
def blob(b):return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
def load(p):return json.loads(p.read_text())

class PE:
    def __init__(self,path,identity):
        self.path=path;self.b=path.read_bytes()
        check(len(self.b)==identity['size'] and sha(self.b)==identity['sha256'],'Original BIN identity')
        p=struct.unpack_from('<I',self.b,0x3c)[0]
        check(self.b[p:p+4]==b'PE\0\0' and struct.unpack_from('<H',self.b,p+4)[0]==0x14c,'PE32 i386')
        check(struct.unpack_from('<H',self.b,p+24)[0]==0x10b,'PE32 optional header')
        n=struct.unpack_from('<H',self.b,p+6)[0];opt=struct.unpack_from('<H',self.b,p+20)[0]
        self.base=struct.unpack_from('<I',self.b,p+52)[0]
        check(self.base==int(identity['imagebase'],0),'ImageBase')
        self.sections=[]
        for i in range(n):
            q=p+24+opt+40*i;vs,rva,rs,raw=struct.unpack_from('<4I',self.b,q+8)
            self.sections.append((self.b[q:q+8].rstrip(b'\0').decode(),self.base+rva,rs,raw))
    def raw(self,va,n):
        for _,start,size,raw in self.sections:
            if start<=va and va+n<=start+size:return raw+va-start
        raise ValueError('Not raw-backed '+hex(va))
    def at(self,va,n):
        p=self.raw(va,n);return self.b[p:p+n]
    def u32(self,va):return struct.unpack('<I',self.at(va,4))[0]
    def string(self,va):
        p=self.raw(va,1);q=self.b.index(b'\0',p,p+512);return self.b[p:q].decode('ascii')
    def disasm(self,start,end):
        cmd=['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(start),'--stop-address='+hex(end+15),str(self.path)]
        out=subprocess.run(cmd,capture_output=True,text=True,check=True).stdout;rows=[]
        for line in out.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if not m:continue
            a=int(m[1],16)
            if a>=end:continue
            b=bytes.fromhex(m[2]);rows.append(dict(va=hex(a),raw=hex(self.raw(a,len(b))),hex=b.hex(),asm=m[3].strip()))
        return rows

def parse_lua(data):
    check(data[:12].hex()=='1b4c75615100010404040800','Original Lua 5.1 fixed header')
    pos=12;protos=[]
    def take(fmt):
        nonlocal pos
        n=struct.calcsize('<'+fmt);check(pos+n<=len(data),'Lua scalar bounds')
        r=struct.unpack_from('<'+fmt,data,pos);pos+=n;return r
    def string():
        nonlocal pos
        n=take('I')[0]
        if not n:return None
        check(pos+n<=len(data) and data[pos+n-1]==0,'Lua string bounds')
        s=data[pos:pos+n-1].decode('ascii');pos+=n;return s
    def proto(parent):
        nonlocal pos
        idx=len(protos);p=dict(index=idx,parent=parent);protos.append(p)
        p['source']=string();p['first'],p['last']=take('II')
        p['nups'],p['params'],p['vararg'],p['stack']=take('BBBB')
        n=take('I')[0];p['code_offset']=pos;p['words']=list(take('I'*n));constants=[]
        for _ in range(take('I')[0]):
            t=take('B')[0]
            if t==0:v=None
            elif t==1:v=bool(take('B')[0])
            elif t==3:v=take('d')[0]
            elif t==4:v=string()
            else:raise ValueError('Unknown original constant tag '+str(t))
            constants.append(v)
        p['constants']=constants;p['children']=[proto(idx) for _ in range(take('I')[0])]
        take('I'*take('I')[0])
        for _ in range(take('I')[0]):string();take('II')
        for _ in range(take('I')[0]):string()
        return idx
    proto(None);check(pos==len(data),'Complete original Lua carrier consumed');return protos

OPS='MOVE LOADK LOADBOOL LOADNIL GETUPVAL GETGLOBAL GETTABLE SETGLOBAL SETUPVAL SETTABLE NEWTABLE SELF ADD SUB MUL DIV MOD POW UNM NOT LEN CONCAT JMP EQ LT LE TEST TESTSET CALL TAILCALL RETURN FORLOOP FORPREP TFORLOOP SETLIST CLOSE CLOSURE VARARG'.split()
def word_row(p,pc):
    w=p['words'][pc];op=w&63;a=(w>>6)&255;b=w>>23;c=(w>>14)&511;bx=w>>14
    r=dict(pc=pc,chunk_offset=p['code_offset']+4*pc,word=w,hex=struct.pack('<I',w).hex(),opcode=op,mnemonic=OPS[op],A=a,B=b,C=c,Bx=bx)
    if op in(1,5,7):r['constant']=p['constants'][bx]
    if op==36:r['child_prototype']=p['children'][bx]
    if op in(6,9,11,23,24,25):r['RK_constants']={k:p['constants'][v-256] for k,v in [('B',b),('C',c)] if v>=256}
    return r

def verify_lua(actual,saved):
    check(len(actual)==saved['prototype_count'],'Original prototype count')
    check(sum(len(p['words']) for p in actual)==saved['instruction_words'],'Original instruction-word count')
    count=0
    for s in saved['selected_prototypes']:
        p=actual[s['index']]
        for k,v in s.items():
            if k in ('word_count','selected_words'):continue
            check(p[k]==v,'Original prototype field '+k)
        check(len(p['words'])==s['word_count'],'Original prototype word count')
        for r in s['selected_words']:
            check(word_row(p,r['pc'])==r,'Original Lua operand row');count+=1
    return count

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin',type=Path,required=True)
    ap.add_argument('--event-stp',type=Path,required=True)
    ap.add_argument('--repo',type=Path,required=True)
    ap.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
    ap.add_argument('--output',type=Path)
    args=ap.parse_args();e=args.evidence_dir
    manifest=load(e/'source-manifest.json');native=load(e/'native-windows.json')
    assertions=load(e/'native-assertions.json');lua=load(e/'lua-evidence.json')
    contract=load(e/'caller-contract.json');pe=PE(args.bin,native['binary']);ins={};codes=0
    for r in native['records']:
        a=int(r['va'],0);end=int(r['end'],0);bb=pe.at(a,r['length'])
        check(end-a==r['length'] and pe.raw(a,len(bb))==int(r['raw'],0),'Original mapping '+r['id'])
        check(bb.hex()==r['hex'] and sha(bb)==r['sha256'],'Original byte window '+r['id'])
        if r['kind']=='code':
            actual=pe.disasm(a,end);check(actual==r['instructions'],'Fresh native disassembly '+r['id']);cursor=a
            for i in actual:
                check(int(i['va'],0)==cursor and '(bad)' not in i['asm'],'Continuous native instructions')
                cursor+=len(bytes.fromhex(i['hex']));ins[int(i['va'],0)]=i
            check(cursor==end,'Complete final instruction '+r['id']);codes+=1
    for r in assertions['anchors']:
        a=int(r['va'],0);check(a in ins and ins[a]['hex']==r['hex'],'Full instruction anchor '+r['label'])
    for r in assertions['relcalls']:
        a=int(r['callsite'],0);t=int(r['target'],0);b=pe.at(a,5)
        check(a in ins and b[0]==0xe8 and a+5+struct.unpack('<i',b[1:])[0]==t,'Original rel32 edge')
    for r in assertions['switch_tables']:
        a=int(r['va'],0);check([hex(pe.u32(a+4*i)) for i in range(len(r['targets']))]==r['targets'],'Original switch '+r['id'])
    for r in assertions['bindings']:
        a=int(r['row_va'],0);sp=int(r['name_va'],0)
        check(pe.u32(a)==sp and pe.u32(a+4)==int(r['target'],0) and pe.string(sp)==r['name'],'Native named binding')
    bygroup={(r['group'],r['name']):int(r['target'],0) for r in assertions['bindings']}
    check(bygroup[('table','insert')]==0x70bd80 and bygroup[('coroutine','create')]==0x707380,'Required original ABI binding')
    check(pe.u32(0x6fd694+36*4)==0x6fd3fe and pe.u32(0x6fd694+30*4)==0x6fd629,'CLOSURE/RETURN dispatch targets')
    check(pe.u32(0x6fa030+(8-4)*4)==0x6fa014 and pe.u32(0x6fa870+(8-5)*4)==0x6fa80b,'Thread GC tag path')

    event=args.event_stp.read_bytes();ei=next(x for x in manifest['originals'] if x['file']=='06-Event.stp')
    check(len(event)==ei['size'] and sha(event)==ei['sha256'],'Original Event.stp identity')
    m=lua['qbase']['member'];stored=event[m['stored_offset']:m['stored_offset']+m['stored_length']]
    decoded=bytes(x^255 for x in stored)
    check(sha(stored)==m['stored_sha256'] and sha(decoded)==m['decoded_sha256'],'Pinned qbase member identity')
    q=parse_lua(decoded);qw=verify_lua(q,lua['qbase'])
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0')
    def git(*cmd):return subprocess.run(['git','-c','remote.origin.promisor=false',*cmd],cwd=args.repo,env=env,capture_output=True,check=True).stdout
    c=lua['coroutine']['carrier'];cb=git('show',c['commit']+':'+c['path'])
    check(len(cb)==c['size'] and sha(cb)==c['sha256'] and blob(cb)==c['git_blob'],'Pinned original Coroutine carrier')
    co=parse_lua(cb);cw=verify_lua(co,lua['coroutine'])
    check(word_row(q[0],170)['child_prototype']==75 and word_row(q[0],171)['constant']=='Register','Actual qbase Register binding')
    check(q[75]['params']==1 and q[75]['vararg']==0 and q[75]['constants']==['f_registerCoroutine','coroutine','create'],'Formal Register ABI')
    check(co[6]['params']==2 and co[6]['constants']==['table','insert','coroutineList'],'Formal registerCoroutine ABI')
    check(word_row(co[6],4)['B']==3 and word_row(co[6],4)['C']==1,'Insert takes list and handle; discard results')
    check(word_row(co[3],5)['mnemonic']=='NEWTABLE','coroutineList ordinary table producer')

    pins=[]
    for r in manifest['references']:
        check(git('rev-parse',r['commit']+':'+r['path']).decode().strip()==r['git_blob'],'Source commit/path/blob '+r['path'])
        p=args.repo/r['path'];b=p.read_bytes() if p.is_file() else git('show',r['commit']+':'+r['path'])
        check(len(b)==r['size'] and sha(b)==r['sha256'] and blob(b)==r['git_blob'],'Source content '+r['path'])
        pins.append(r['id'])
    check(contract['classification']=='CONDITIONAL_DESIGN_NOT_NATIVE_MEF' and contract['deployable_resource'] is False,'Design classification')
    check(all(v['assigned'] is False and v['value'] is None for v in contract['unallocated_parameters']),'No invented deployment values')
    ids={s['id'] for s in contract['states']};check(len(ids)==len(contract['states']),'Unique state IDs')
    for t in contract['transitions']:check(t['from'] in ids and t['to'] in ids and t['condition'],'Defined conditional state edge')
    adjacency={i:set() for i in ids}
    for t in contract['transitions']:adjacency[t['from']].add(t['to'])
    reachable={'requested'};todo=['requested']
    while todo:
        for dst in adjacency[todo.pop()]-reachable:reachable.add(dst);todo.append(dst)
    check(reachable==ids,'Every described design state has a path from request')
    check(contract['end_contract']['nonzero_quest_003f_condition']=='active && !review && converted_CheckConfirmMessage == 1','Nonzero End report gate retained')
    check(contract['end_contract']['every_End_emits_003f'] is False,'No false universal End ACK')
    check(contract['end_contract']['003f_proves_module_execution'] is False,'Skip counterexample retained')
    check(contract['phase_contract']['scope']=='normal_original_bindings_and_successful_nonreentrant_registration','Conditional phase scope retained')
    check(contract['phase_contract']['shared_flag_across_vms'] is False,'Each invocation has a distinct local')
    check(contract['module_contract']['invoke_entry_after_DoFile_returns'] is True and contract['module_contract']['wrap_yielding_entry_in_pcall'] is False,'Lua 5.1 boundary retained')
    result=dict(status='PASS',validation_kind='Read-only static original-byte/source/contract-shape consistency; no native semantic certification, Lua execution, gameplay validation or T01 FULL-PASS',
                native_records=len(native['records']),native_code_windows=codes,native_bytes=sum(x['length'] for x in native['records']),
                native_instructions=sum(len(x.get('instructions',[])) for x in native['records']),native_anchors=len(assertions['anchors']),native_relcalls=len(assertions['relcalls']),
                native_bindings=len(assertions['bindings']),native_switch_tables=len(assertions['switch_tables']),
                original_qbase_prototypes=len(q),original_coroutine_prototypes=len(co),selected_lua_words=qw+cw,
                source_pins=len(pins),contract_states=len(ids),contract_transitions=len(contract['transitions']),
                limits=['Semantic claims require review of report/native/dataflow together','Conditional design is not an executed/generated game resource','MapList.TRIGGER first native loader caller remains unproven','Server completion/timeout policy remains development work'])
    if args.output:
        out=args.output.resolve();protected={args.bin.resolve(),args.event_stp.resolve()}
        protected.update(p.resolve() for p in e.iterdir() if p.name!='verification-result.json')
        check(out not in protected,'Would overwrite evidence input')
        check(not out.is_relative_to(args.repo.resolve()),'Verifier output must stay outside Git worktree')
        check(not out.is_relative_to(args.bin.resolve().parent),'Verifier output must stay outside original source directory')
        args.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))

if __name__=='__main__':main()
