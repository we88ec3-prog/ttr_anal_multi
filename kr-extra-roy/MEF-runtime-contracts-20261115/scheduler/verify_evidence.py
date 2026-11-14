#!/usr/bin/env python3
"""Verify bounded scheduler evidence as data. Never execute Client, Lua, or old scripts.

The default Coroutine input is the already published content-addressed carrier.
Use --coroutine when a sparse checkout does not contain that binary blob.
"""
import argparse
from collections import deque
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True
OPS = ['MOVE','LOADK','LOADBOOL','LOADNIL','GETUPVAL','GETGLOBAL','GETTABLE','SETGLOBAL',
       'SETUPVAL','SETTABLE','NEWTABLE','SELF','ADD','SUB','MUL','DIV','MOD','POW','UNM',
       'NOT','LEN','CONCAT','JMP','EQ','LT','LE','TEST','TESTSET','CALL','TAILCALL',
       'RETURN','FORLOOP','FORPREP','TFORLOOP','SETLIST','CLOSE','CLOSURE','VARARG']

def sha(data): return hashlib.sha256(data).hexdigest()
def blob(data): return hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()
def load(path): return json.loads(path.read_text())
def check(ok, label):
    if not ok: raise ValueError(label)

def pinned_helper(repo, record):
    path = repo / record['path']
    check(sha(path.read_bytes()) == record['sha256'], 'Pinned reader SHA')
    spec = importlib.util.spec_from_file_location('scheduler_pinned_reader', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

def rk(proto, operand):
    if operand >= 256:
        return dict(kind='constant', index=operand-256, value=proto['constants'][operand-256])
    return dict(kind='register', index=operand)

def decode(proto):
    records=[]
    for pc, word in enumerate(proto['words']):
        op=OPS[word & 63]; a=(word>>6)&255; b=(word>>23)&511; c=(word>>14)&511; bx=word>>14
        item=dict(pc=pc, chunk_offset=proto['code_offset']+4*pc, word=f'{word:08x}',
                  op=op, A=a, B=b, C=c, Bx=bx)
        if op in ('LOADK','GETGLOBAL','SETGLOBAL'): item['constant']=proto['constants'][bx]
        if op in ('GETTABLE','SELF'): item['C_RK']=rk(proto,c)
        if op in ('SETTABLE','ADD','SUB','MUL','DIV','MOD','POW','EQ','LT','LE'):
            item['B_RK']=rk(proto,b); item['C_RK']=rk(proto,c)
        if op == 'CLOSURE': item['child_prototype']=proto['children'][bx]
        if op in ('JMP','FORLOOP','FORPREP'):
            item['destination_pc']=pc+1+bx-131071
        if op in ('RETURN','TAILCALL'): successors=[]
        elif op in ('JMP','FORPREP'): successors=[item['destination_pc']]
        elif op == 'FORLOOP': successors=[pc+1,item['destination_pc']]
        elif op in ('EQ','LT','LE','TEST','TESTSET','TFORLOOP'): successors=[pc+1,pc+2]
        elif op == 'LOADBOOL' and c: successors=[pc+2]
        else: successors=[pc+1]
        for successor in successors:
            check(0 <= successor < len(proto['words']), f'CFG bounds P{proto["index"]}:{pc}')
        item['successors']=successors
        if op in ('CALL','TAILCALL'):
            item['argument_count'] = b-1 if b else 'open'
            item['result_count'] = c-1 if c and op == 'CALL' else 'open/tail'
        records.append(item)
    return records

def package_proto(proto):
    result={key:proto[key] for key in ('index','parent','start','source','first','last','nups',
            'params','vararg','stack','code_offset','words','constants','children','lines','locals',
            'upvalue_names','end')}
    result['instructions']=decode(proto)
    seen=set(); queue=deque([0])
    while queue:
        pc=queue.popleft()
        if pc in seen: continue
        seen.add(pc); queue.extend(result['instructions'][pc]['successors'])
    result['reachable_pcs']=sorted(seen)
    return result

def member_data(stp, path, helper):
    ident=stp.files[path]; length, first, last=stp.blocks[ident]; offset=16+first*1024
    data=helper.ex_decode(stp.data[offset:offset+length])
    metadata=dict(path=path,block_id=ident,stored_offset=offset,stored_length=length,
                  first_block=first,last_block=last,decoded_size=len(data),decoded_sha256=sha(data))
    return metadata, data

def import_record(pe, iat_va):
    peoff=struct.unpack_from('<I',pe.data,0x3c)[0]
    rva,size=struct.unpack_from('<II',pe.data,peoff+24+104)
    def cstr(va):
        output=bytearray()
        while True:
            byte=pe.at(va+len(output),1)[0]
            if byte==0: return output.decode('ascii')
            output.append(byte)
            check(len(output)<4096,'Import string bound')
    for va in range(pe.base+rva,pe.base+rva+size,20):
        oft,stamp,fwd,name,ft=struct.unpack('<5I',pe.at(va,20))
        if not any((oft,stamp,fwd,name,ft)): break
        at=0
        while True:
            hn=struct.unpack('<I',pe.at(pe.base+(oft or ft)+at*4,4))[0]
            if not hn: break
            if pe.base+ft+at*4==iat_va:
                check(not hn&0x80000000,'Named import required')
                return dict(descriptor_va=hex(va),original_first_thunk=hex(pe.base+oft),
                    first_thunk=hex(pe.base+ft),iat_va=hex(iat_va),dll_name_va=hex(pe.base+name),
                    dll=cstr(pe.base+name),hint_name_va=hex(pe.base+hn),
                    hint=struct.unpack('<H',pe.at(pe.base+hn,2))[0],name=cstr(pe.base+hn+2))
            at+=1
    raise ValueError('IAT entry not found')

def static_claim_checks(protos):
    """Bytecode shape checks, not execution or proof of arbitrary rebound globals."""
    def ins(p,pc,op,**fields):
        item=decode(protos[p])[pc]
        check(item['op']==op and all(item[k]==v for k,v in fields.items()),f'P{p}:{pc} {op}')
    check(len(protos)==13 and sum(len(p['words']) for p in protos)==187,'13/187 full body')
    check(all(p['nups']==0 for p in protos),'No captured upvalues')
    check(protos[9]['params']==1 and protos[9]['vararg']==0,'doCoTask fixed self-only parameters')
    check(protos[8]['params']==2 and protos[8]['vararg']==0,'executeCoroutines callback parameter')
    ins(1,2,'CALL',A=1,B=1,C=2); ins(1,5,'CALL',A=2,B=1,C=1)
    ins(1,9,'SUB',A=2,B=2,C=1); ins(1,10,'LE',A=0,B=0,C=2)
    ins(1,11,'JMP',destination_pc=3)
    ins(7,3,'CALL',A=4,B=2,C=3)
    ins(7,6,'EQ',A=0,B=2,C=258)
    check(protos[7]['constants'][2] is False,'Boolean false comparison')
    ins(7,11,'LOADK',constant=0); ins(7,14,'LOADK',constant=1)
    ins(8,9,'CALL',A=3,B=1,C=1)
    ins(8,15,'FORPREP',destination_pc=36)
    ins(8,34,'TAILCALL',A=7,B=3,C=0)
    ins(8,36,'FORLOOP',destination_pc=16)
    ins(9,1,'CALL',A=1,B=2,C=2)
    ins(9,11,'TAILCALL',A=2,B=2,C=0)
    ins(10,16,'TAILCALL',A=7,B=3,C=0)
    ins(11,0,'NEWTABLE'); ins(11,1,'SETTABLE',A=0,B=256,C=1)
    ins(12,3,'CALL',A=2,B=2,C=2)
    return ['full_13_prototypes_187_words','wait_yield_before_elapsed_test',
            'resume_boolean_to_numeric_status','first_removal_tail_returns',
            'doCoTask_discards_extra_parameter_and_does_not_forward_callback',
            'doCoTask_returns_table_length','removeAll_replaces_list',
            'isCoroutineAlive_uses_status_not_membership']

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--repo',required=True,type=Path)
    ap.add_argument('--sources',required=True,type=Path,help='Read-only folder containing 02-Tartaros.bin and 06-Event.stp')
    ap.add_argument('--coroutine',type=Path,help='Exact 2168-byte original chunk; not a decompilation')
    ap.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
    ap.add_argument('--out',type=Path)
    args=ap.parse_args(); evidence=args.evidence_dir
    manifest=load(evidence/'source-manifest.json')
    helper=pinned_helper(args.repo,manifest['helper'])
    carrier=manifest['coroutine_original']
    coroutine_path=args.coroutine or args.repo/carrier['path']
    data=coroutine_path.read_bytes()
    check(len(data)==carrier['bytes'] and sha(data)==carrier['sha256'],'Coroutine original SHA/size')
    check(blob(data)==carrier['git_blob'],'Coroutine original Git blob SHA')
    protos=helper.read_lua51_prototypes(data)
    recorded=load(evidence/'coroutine-evidence.json')
    check([package_proto(p) for p in protos]==recorded['prototypes'],'Full Coroutine operands/CFG')
    claims=static_claim_checks(protos)
    pe=helper.PE(args.sources/manifest['binary']['file'],manifest['binary'])
    native=load(evidence/'native-windows.json')
    for window in native['windows']:
        pe.verify_window(window)
    check(import_record(pe,0xbd25a0)==native['time_import'],'timeGetTime PE import binding')
    for binding in native['function_bindings']:
        check(pe.at(int(binding['row_va'],0),8)==struct.pack('<II',int(binding['name_va'],0),int(binding['function_va'],0)),'Native binding row')
        check(pe.at(int(binding['name_va'],0),len(binding['name'])+1)==binding['name'].encode()+b'\0','Native binding name')
    stp=helper.STPD(args.sources/manifest['event']['file'],manifest['event'])
    bridge=load(evidence/'bridge-evidence.json')
    member_results=[]
    for entry in bridge['lua_members']:
        metadata,member=member_data(stp,entry['member']['path'],helper)
        check(metadata==entry['member'],'Bridge member identity')
        parsed=helper.read_lua51_prototypes(member)
        for selected in entry['selected_prototypes']:
            check(package_proto(parsed[selected['index']])==selected,'Selected bridge operands')
        member_results.append(dict(path=metadata['path'],selected_prototypes=len(entry['selected_prototypes']),sha256=sha(member)))
    seq=bridge['sequence'];metadata,member=member_data(stp,seq['member']['path'],helper)
    check(metadata==seq['member'],'Selected SEQ identity')
    lines=member.decode('ascii').splitlines()
    for snippet in seq['snippets']:
        check(lines[snippet['first_line']-1:snippet['last_line']]==snippet['lines'],'Selected SEQ original lines')
    result=dict(status='PASS',scope='Original identities, complete Coroutine decoding/CFG, selected reused bridge operands, native byte windows and import/binding mapping; no runtime execution or T01 FULL-PASS assertion.',
        coroutine=dict(bytes=len(data),sha256=sha(data),git_blob=blob(data),prototypes=len(protos),instruction_words=sum(len(p['words']) for p in protos)),
        native_windows=len(native['windows']),native_bytes=sum(w['length'] for w in native['windows']),
        time_import=native['time_import'],bridge_members=member_results,selected_sequence=metadata,
        static_shape_checks=claims,excluded=['Client execution','Lua execution or compilation','Resource mutation','Network or git access from verifier'])
    if args.out:
        protected={coroutine_path.resolve(),(args.sources/manifest['binary']['file']).resolve(),
                   (args.sources/manifest['event']['file']).resolve()}
        protected.update(p.resolve() for p in evidence.iterdir() if p.name!='verification-result.json')
        check(args.out.resolve() not in protected,'Output would overwrite input')
        args.out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))

if __name__=='__main__': main()
