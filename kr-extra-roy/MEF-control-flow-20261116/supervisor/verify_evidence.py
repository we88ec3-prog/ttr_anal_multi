#!/usr/bin/env python3
"""Read-only checks for the conditional Q outer/inner coroutine supervisor.

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
    args=ap.parse_args();e=args.evidence_dir.resolve();repo=args.repo.resolve()
    manifest=load(e/'source-manifest.json');native=load(e/'native-windows.json')
    assertions=load(e/'native-assertions.json');lua=load(e/'lua-evidence.json')
    contract=load(e/'supervisor-contract.json')
    pe=PE(args.bin,native['binary']);ins={};code_count=0;record_ids=set()
    for r in native['records']:
        check(r['id'] not in record_ids,'Unique native record');record_ids.add(r['id'])
        a=int(r['va'],0);end=int(r['end'],0);bb=pe.at(a,r['length'])
        check(end-a==r['length'] and pe.raw(a,len(bb))==int(r['raw'],0),'PE mapping '+r['id'])
        check(bb.hex()==r['hex'] and sha(bb)==r['sha256'],'Native byte identity '+r['id'])
        if r['kind']=='code':
            actual=pe.disasm(a,end);check(actual==r['instructions'],'Fresh native disassembly '+r['id'])
            cursor=a
            for row in actual:
                va=int(row['va'],0)
                check(va==cursor and '(bad)' not in row['asm'],'Continuous valid instruction '+r['id'])
                check(va not in ins,'Code windows do not double-count instructions')
                cursor+=len(bytes.fromhex(row['hex']));ins[va]=row
            check(cursor==end,'Complete end instruction '+r['id']);code_count+=1
        else:check(r['kind']=='data' and 'instructions' not in r,'Data table is not disassembled')
    asm=[]
    for r in native['records']:
        asm += ['; '+r['id']+' '+r['va']+'..'+r['end']+' raw '+r['raw']+' SHA256 '+r['sha256'],'; '+r['meaning']]
        if r['kind']=='code':asm += [x['va']+'  '+x['hex'].ljust(32)+'  '+x['asm'] for x in r['instructions']]
        else:asm += [r['hex']]
        asm += ['']
    check((e/'native-windows.asm').read_text()=='\n'.join(asm),'Readable ASM matches every JSON record')
    for r in assertions['anchors']:
        a=int(r['va'],0)
        check(a in ins and ins[a]['hex']==r['hex'] and ins[a]['asm']==r['label'],'Full native instruction anchor')
    for r in assertions['relcalls']:
        a=int(r['callsite'],0);target=int(r['target'],0);bb=pe.at(a,5)
        check(a in ins and bb[0]==0xe8 and a+5+struct.unpack('<i',bb[1:])[0]==target,'Original direct call edge')
    for r in assertions['bindings']:
        a=int(r['row_va'],0);sp=int(r['name_va'],0)
        check(pe.u32(a)==sp and pe.u32(a+4)==int(r['target'],0) and pe.string(sp)==r['name'],'Native named binding')
    for r in assertions['tables']:
        a=int(r['va'],0)
        check([hex(pe.u32(a+4*i)) for i in range(len(r['values']))]==r['values'],'Original data table '+r['id'])
    for r in assertions['strings']:check(pe.string(int(r['va'],0))==r['value'],'Original native string')
    binding={r['name']:int(r['target'],0) for r in assertions['bindings']}
    check(all(binding[k]==v for k,v in {'create':0x707380,'resume':0x707230,'status':0x707070,'yield':0x707480,'running':0x7074c0}.items()),'Required coroutine binding identities')
    check(binding['error']==0x705650 and binding['pcall']==0x706ac0,'Original base error/pcall named targets')
    check([pe.string(pe.u32(0xc0bc58+4*i)) for i in range(4)]==['running','suspended','normal','dead'],'Native status table order')
    check([pe.u32(0x6fd704+4*i) for i in range(3)]==[0x6fd01e,0x6fd076,0x6fd629],'Native CALL/TAILCALL/RETURN dispatch')
    check(pe.u32(0x6fdab8)==0x6fda9c,'Runtime error status 2 copies original error TValue')

    identities={x['file']:x for x in manifest['originals']}
    for name,path in [('02-Tartaros.bin',args.bin),('06-Event.stp',args.event_stp)]:
        b=path.read_bytes();identity=identities[name]
        check(len(b)==identity['size'] and sha(b)==identity['sha256'],'Original whole-file identity '+name)
    instructions=manifest['provided_instructions']
    original_instruction_path=args.bin.resolve().parent/instructions['file']
    ib=original_instruction_path.read_bytes()
    check(len(ib)==instructions['size'] and sha(ib)==instructions['sha256'],'Provided shared instructions identity')
    event=args.event_stp.read_bytes();m=lua['qbase']['member']
    stored=event[m['stored_offset']:m['stored_offset']+m['stored_length']]
    decoded=bytes(x^255 for x in stored)
    check(sha(stored)==m['stored_sha256'] and sha(decoded)==m['decoded_sha256'],'Pinned qbase member bytes')
    q=parse_lua(decoded);qw=verify_lua(q,lua['qbase'])
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_NO_REPLACE_OBJECTS='1',GIT_TERMINAL_PROMPT='0',PYTHONDONTWRITEBYTECODE='1')
    def git(*parts):
        return subprocess.run(['git','-c','remote.origin.promisor=false','-c','maintenance.auto=false','-C',str(repo),*parts],env=env,capture_output=True,check=True).stdout
    allowed={manifest['repo_commit'],manifest['main_baseline']}
    check(allowed=={'ad9ea950216923b5e351a7501d38e006df57a4c6','03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc'},'Only public R9/main active source commits')
    checked=[]
    def verify_pin(r):
        check(r['commit'] in allowed,'Source pin uses public allowed commit')
        check(git('rev-parse',r['commit']+':'+r['path']).decode().strip()==r['git_blob'],'Commit/path/blob source identity')
        payload=git('show',r['commit']+':'+r['path'])
        check(len(payload)==r['size'] and sha(payload)==r['sha256'] and blob(payload)==r['git_blob'],'Pinned source payload')
        return payload
    for r in manifest['references']:
        verify_pin(r);checked.append(r['id'])
    check(len(set(checked))==len(checked),'Unique reference pin IDs')
    c=lua['coroutine']['carrier'];check(c==manifest['coroutine_original'],'Same raw Coroutine carrier pin')
    cb=verify_pin(c);co=parse_lua(cb);cw=verify_lua(co,lua['coroutine'])

    # Original operand claims used by the supervisor. No new Lua is compiled/run.
    p=word_row(co[7],3)
    check(co[7]['params']==2 and co[7]['vararg']==0 and p['mnemonic']=='CALL' and p['A']==4 and p['B']==2 and p['C']==3,'MoCo resume passes only handle and captures Boolean/payload')
    check(word_row(co[7],2)['B']==1,'MoCo handle comes from its declared argument')
    wait=word_row(co[1],5)
    check(wait['mnemonic']=='CALL' and wait['B']==1 and wait['C']==1,'Original wait yields zero values and ignores resume results')
    check(word_row(co[1],11)['mnemonic']=='JMP' and co[1]['constants']==['lb','GetTime','coroutine','yield'],'Original finite-slice wait body retained')
    check(co[9]['params']==1 and co[9]['vararg']==0 and word_row(co[9],1)['B']==2,'doCoTask does not forward completion callback')
    check(len(co[11]['words'])==3 and word_row(co[11],0)['mnemonic']=='NEWTABLE' and word_row(co[11],1)['mnemonic']=='SETTABLE','removeAll only replaces coroutineList')
    check(word_row(q[74],54)['constant']=='yield' and word_row(q[74],55)['B']==1,'RevPhase1 has a zero-argument yield before its tail')
    check(word_row(q[74],57)['RK_constants']['C']=='EnableInput' and word_row(q[74],60)['RK_constants']['C']=='EndCutScene','RevPhase1 final input/End order')
    check(q[75]['params']==1 and q[75]['constants']==['f_registerCoroutine','coroutine','create'],'Original formal Register contract')
    for idx in [10,11,12,13,24]:
        check(q[idx]['params']==0 and q[idx]['vararg']==0 and 'yield' in q[idx]['constants'],'Selected qbase Wait helper uses coroutine yield without handle argument')

    check(contract['classification']=='CONDITIONAL_DESIGN_NOT_NATIVE_MEF' and contract['deployable_resource'] is False,'Conditional design classification')
    check(contract['work_parent']==manifest['repo_commit'],'Contract/source publication baseline')
    schedule=contract['scheduling'];bounds=contract['boundaries'];cancel=contract['cancellation'];cleanup=contract['cleanup'];proto=contract['protocol']
    check(schedule['registered_threads']==['outer_only'] and schedule['inner_registered_in_qco'] is False,'Only outer is scheduled by MoCo')
    check(schedule['outer_moco_resume_arguments']==schedule['inner_resume_arguments']==0,'No invented MoCo resume payload')
    check(schedule['inner_steps_per_outer_visit_max']==1 and schedule['outer_yield_after_child_yield'] is True,'No busy-loop stepping child')
    check(schedule['normal_return_false_is_resume_error'] is False and schedule['normal_return_is_business_success'] is False,'Return and resume/business outcomes distinguished')
    check(bounds['wrapper_yield_only_after_resume_returns'] is True and bounds['wrap_yielding_entry_in_pcall'] is False and bounds['wrap_yielding_outer_loop_in_pcall'] is False and bounds['yield_from_DoFile_top_level'] is False,'All same-thread yield boundary restrictions retained')
    check(bounds['all_api_failures_caught'] is False and bounds['all_native_failures_caught'] is False and bounds['thread_is_sandbox'] is False,'No universal protection or isolation claim')
    check(cancel['requires_outer_execution'] is True and cancel['inner_preemption'] is False and cancel['external_remove_runs_cleanup'] is False and cancel['dropped_suspended_child_is_dead'] is False,'Cooperative and external cancellation separated')
    check(cleanup['complete_before_End'] is True and cleanup['End_then_Stop_is_recovery'] is False and cleanup['cleanup_requested_equals_restored'] is False and cleanup['cleanup_error_automatically_caught'] is False,'Effect cleanup/postconditions precede End without universal finally')
    check(cleanup['selected_cleanup_policy_contains_End'] is False and cleanup['original_RevPhase1_contains_own_End'] is True and cleanup['repeat_End_after_RevPhase1_allowed'] is False,'One final End owner; unchanged RevPhase1 cannot be double-ended')
    check(proto['every_End_emits_003f'] is False and proto['packet_003f_proves_module_success'] is False and proto['packet_00eb_stops_Q'] is False and proto['new_opcode_or_run_token_invented'] is False,'No invented wire completion/cancel semantics')
    check(proto['nonzero_quest_003f_condition']=='active && !review && converted_CheckConfirmMessage == 1','Nonzero quest End reporting gate preserved')
    check(all(x['assigned'] is False and x['value'] is None for x in contract['unallocated_parameters']),'No invented deployment assignments')
    check(all(x is False for x in contract['validation'].values()),'No Lua/Client/Server/deployment/formal acceptance claim')
    ids={s['id'] for s in contract['states']};check(len(ids)==len(contract['states']),'Unique design states')
    adjacency={x:set() for x in ids}
    for edge in contract['transitions']:
        check(edge['source'] in ids and edge['target'] in ids and edge['condition'],'Defined conditional design transition')
        adjacency[edge['source']].add(edge['target'])
    reachable={'formal_bridge'};todo=['formal_bridge']
    while todo:
        for dst in adjacency[todo.pop()]-reachable:reachable.add(dst);todo.append(dst)
    check(reachable==ids,'Every described design state is structurally reachable')
    check(not any(p.suffix.lower() in {'.lua','.seq','.mef','.bin','.exe','.stp','.pyc'} for p in e.rglob('*') if p.is_file()),'No raw/deployable resources or bytecode cache in evidence package')
    result=dict(status='PASS',validation_kind='Read-only static original-byte/source/operand/contract-shape consistency; not Lua execution, gameplay, full semantic certification, T01 FULL-PASS or RR acceptance',
        native_records=len(native['records']),native_code_windows=code_count,native_bytes=sum(r['length'] for r in native['records']),native_instructions=len(ins),native_anchors=len(assertions['anchors']),native_relcalls=len(assertions['relcalls']),native_bindings=len(assertions['bindings']),native_tables=len(assertions['tables']),native_strings=len(assertions['strings']),asm_matches_native_records=True,
        original_qbase_prototypes=len(q),original_coroutine_prototypes=len(co),selected_lua_words=qw+cw,source_pins=len(checked),source_commits=sorted(allowed),coroutine_carrier_commit=c['commit'],contract_states=len(ids),contract_transitions=len(contract['transitions']),
        limits=['Ordinary escaped inner Lua body errors only; public wrapper/outer/cleanup/native failures are not universally caught','External removal, Q/VM teardown and non-yielding inner work do not gain automatic cleanup or preemption','Presentation cleanup steps and postconditions belong to the separately linked R10 presentation package','Conditional compatible-content design is not a native MapList MEF caller or an ordinary gameplay background runner','Server timeout/result/persistence policy and gameplay acceptance remain separate work'])
    if args.output:
        out=args.output.resolve();protected={args.bin.resolve(),args.event_stp.resolve(),original_instruction_path.resolve()}
        protected.update(p.resolve() for p in e.iterdir() if p.name!='verification-result.json')
        check(out not in protected,'Would overwrite an evidence input')
        check(not out.is_relative_to(repo),'Verifier output must stay outside Git worktree')
        check(not out.is_relative_to(args.bin.resolve().parent),'Verifier output must stay outside original directory')
        check(out.suffix=='.json','Only explicit JSON result output is supported')
        out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))

if __name__=='__main__':main()
