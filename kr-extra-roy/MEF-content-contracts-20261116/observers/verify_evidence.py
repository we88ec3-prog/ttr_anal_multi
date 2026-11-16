#!/usr/bin/env python3
"""Read-only verification of bounded MEF observer evidence.

Reads the exact original BIN/STP, package files, and optionally cached Git blobs.
Does not execute Lua or the Client, fetch Git objects, change sources or checkout.
PASS is package / selected-structure verification, not T01 FULL-PASS or gameplay.
"""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True


def check(ok, msg):
    if not ok:
        raise ValueError(msg)


def digest(b): return hashlib.sha256(b).hexdigest()
def num(v): return int(v, 0) if isinstance(v, str) else v
def load(p): return json.loads(p.read_text(encoding='utf-8'))


def disassemble(bin_path, start, end):
    proc = subprocess.run([
        'objdump', '-D', '-Mintel', '--insn-width=16',
        '--start-address='+hex(start), '--stop-address='+hex(end+15),
        str(bin_path)], check=True, capture_output=True, text=True)
    rows=[]
    for line in proc.stdout.splitlines():
        m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
        if not m: continue
        va=int(m[1],16)
        if va>=end: continue
        rows.append(dict(va=va,hex=bytes.fromhex(m[2]).hex(),asm=m[3].strip()))
    return rows


def direct_branch(va, b):
    if b[0] in (0xe8,0xe9) and len(b)==5:
        return va+5+struct.unpack('<i',b[1:])[0]
    if (b[0]==0xeb or 0x70<=b[0]<=0x7f) and len(b)==2:
        return va+2+struct.unpack('<b',b[1:])[0]
    if b[0]==0x0f and 0x80<=b[1]<=0x8f and len(b)==6:
        return va+6+struct.unpack('<i',b[2:])[0]
    raise ValueError(f'not a selected direct branch: {va:#x} {b.hex()}')


OPNAMES='MOVE LOADK LOADBOOL LOADNIL GETUPVAL GETGLOBAL GETTABLE SETGLOBAL SETUPVAL SETTABLE NEWTABLE SELF ADD SUB MUL DIV MOD POW UNM NOT LEN CONCAT JMP EQ LT LE TEST TESTSET CALL TAILCALL RETURN FORLOOP FORPREP TFORLOOP SETLIST CLOSE CLOSURE VARARG'.split()


def lua_instruction(w, pc):
    op=w&63; a=(w>>6)&255; b=(w>>23)&511; c=(w>>14)&511; bx=w>>14; sb=bx-131071
    d=dict(pc=pc,word=w,word_hex=struct.pack('<I',w).hex(),opcode=OPNAMES[op],A=a,B=b,C=c,Bx=bx,sBx=sb)
    if op==22: d['jump_target']=pc+1+sb
    return d


def run(args):
    here=Path(__file__).resolve().parent
    native=load(here/'native-windows.json')
    lua=load(here/'lua-evidence.json')
    bindings=load(here/'bindings.json')
    sources=load(here/'source-manifest.json')
    contracts=load(here/'contracts.json')
    artifacts=load(here/'artifact-manifest.json')
    for row in artifacts['files']:
        b=(here/row['path']).read_bytes()
        check(len(b)==row['bytes'] and digest(b)==row['sha256'],'artifact '+row['path'])

    helper_path=args.repo/lua['reader_path']
    helper_bytes=helper_path.read_bytes()
    check(digest(helper_bytes)==lua['reader_sha256'],'pinned original-data reader')
    check(digest(helper_bytes)=='8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56','known original-data reader version')
    spec=importlib.util.spec_from_file_location('bounded_mef_source_reader',helper_path)
    helper=importlib.util.module_from_spec(spec);spec.loader.exec_module(helper)
    o=native['original']; pe=helper.PE(args.bin,dict(size=o['bytes'],sha256=o['sha256'],image_base=o['image_base']))

    all_ins={}; ids=set(); code_count=0; instruction_count=0
    for w in native['windows']:
        check(w['id'] not in ids,'duplicate native window ID'); ids.add(w['id'])
        helper.PE.verify_window(pe,w)
        start=num(w['va']);end=num(w['end'])
        check(end-start==w['length'],'window end '+w['id'])
        if w['kind']!='code': continue
        code_count+=1; cur=start
        actual=disassemble(args.bin,start,end)
        check(len(actual)==len(w['instructions']),'instruction count '+w['id'])
        for got,want in zip(actual,w['instructions']):
            check(got['va']==cur==num(want['va']),'instruction boundary '+w['id'])
            bb=bytes.fromhex(want['hex'])
            check(got['hex']==want['hex'] and pe.at(cur,len(bb))==bb,'instruction bytes '+hex(cur))
            check(' '.join(got['asm'].split())==' '.join(want['asm'].split()),'instruction decode '+hex(cur))
            check(pe.raw_of(cur,len(bb))==num(want['raw']),'instruction raw '+hex(cur))
            if cur in all_ins: check(all_ins[cur]==bb,'overlapping instruction agreement')
            all_ins[cur]=bb;cur+=len(bb);instruction_count+=1
        check(cur==end,'full continuous code window '+w['id'])

    def u32(va): return struct.unpack('<I',pe.at(va,4))[0]
    def cstr(va):
        out=bytearray()
        while True:
            b=pe.at(va+len(out),1)[0]
            if not b:return out.decode('ascii')
            out.append(b);check(len(out)<512,'bounded original string')

    check(len(bindings['tutorial'])==bindings['tutorial_regular_count']==31,'31 Tutorial registrars')
    check(len(bindings['q'])==bindings['q_selected_count']==4,'4 selected Q registrars')
    for rows in (bindings['q'],bindings['tutorial']):
        for row in rows:
            reg=num(row['registrar']);call=num(row['callsite'])
            check(pe.at(call,1)==b'\xe8','registrar call opcode')
            check(direct_branch(call,pe.at(call,5))==reg,'registrar caller')
            check(pe.at(reg+0x18,2)==b'\xc7\x05','registrar store opcode')
            check(u32(reg+0x1a)==num(row['slot']) and u32(reg+0x1e)==num(row['native']),'registrar native target')
            check(pe.at(reg+0x58,1)==b'\x68' and u32(reg+0x59)==num(row['string']),'registrar name push')
            check(cstr(num(row['string']))==row['name'],'registrar original name')
            check(pe.at(reg+0x69,1)==b'\x68' and u32(reg+0x6a)==num(row['closure']),'registrar Lua closure')
    for i,row in enumerate(bindings['tutorial']):
        check(num(row['registrar'])==0x4aa680+0xa0*i and num(row['callsite'])==0x4a88f6+6*i,'Tutorial finite call-chain order')
    for v in bindings['vtables']:
        ptr=num(v['vptr']);col=num(v['COL']);td=num(v['type_descriptor'])
        check(u32(ptr-4)==col and u32(col+12)==td,'COL/type link '+v['name'])
        check(cstr(td+8)==v['type_name'],'RTTI name '+v['name'])
        for off,target in v['slots'].items():check(u32(ptr+num(off))==num(target),'vtable slot '+v['name']+off)
    for c in bindings['float_constants']:
        check(struct.unpack(c['format'],pe.at(num(c['va']),struct.calcsize(c['format'])))[0]==c['value'],'float '+c['name'])
    for a in contracts['native_instruction_assertions']:
        va=num(a['va']);check(all_ins.get(va)==bytes.fromhex(a['hex']),'contract instruction '+a['meaning'])
    edges=[
        (0x56489f,0x5648f2),(0x4d0de1,0x4d0f00),(0x4d0df3,0x4d0f00),
        (0x4d0e8e,0x4d0ed5),(0x4d0eb2,0x4d0ed7),
        (0x56158b,0x5615e0),(0x5615cb,0x5615e0),
        (0x56337e,0x4d0ce0),(0x4d0f8b,0x4d0dd0),
        (0x4c8ba0,0x4cab80),(0x4c709d,0x4ca730),
        (0x5c3303,0x5c34b0),(0x596e13,0x596eb6),
        (0x5c3593,0x596e00)]
    for a,b in edges:check(direct_branch(a,all_ins[a])==b,f'selected CFG/call {a:#x} → {b:#x}')
    check(0x5615d8<0x5615e0<0x5615f8,'qco then native actor loop')
    getter=next(w for w in native['windows'] if w['id']=='q_all_stopped_native')
    check(not any(i['asm'].startswith('call') for i in getter['instructions']),'getter full body is direct tree/bit reader')

    stp=helper.STPD(args.event,lua['carrier'])
    data=stp.verify_member(lua['member'])
    ps=helper.read_lua51_prototypes(data)
    check(len(ps)==lua['all_prototype_count']==76,'qbase prototype count')
    check(sum(len(p['words']) for p in ps)==lua['all_instruction_word_count']==906,'qbase total word count')
    for saved in lua['selected_prototypes']:
        original=ps[saved['index']]
        for k,v in original.items():check(saved[k]==v,f'prototype {saved["index"]} '+k)
        code=data[original['code_offset']:original['code_offset']+4*len(original['words'])]
        check(code.hex()==saved['code_hex'] and digest(code)==saved['code_sha256'],'selected original bytecode')
        check([lua_instruction(w,pc) for pc,w in enumerate(original['words'])]==saved['instructions'],'selected opcode fields')
    root=ps[0]
    for row in lua['selected_root_bindings']:
        a=row['closure_pc'];b=row['setglobal_pc'];w1=root['words'][a];w2=root['words'][b]
        check(b==a+1 and w1&63==36 and w2&63==7,'root CLOSURE/SETGLOBAL pair')
        check(root['children'][w1>>14]==row['prototype'],'root child ordinal')
        check(root['constants'][w2>>14]==row['name'],'root assigned global name')
        check([w1,w2]==row['words'] and data[row['code_offset']:row['code_offset']+8].hex()==row['code_hex'],'root original bytecode pair')
    p24=ps[24];p25=ps[25];p26=ps[26];p35=ps[35]
    check(p24['params']==0 and p24['constants']==['yield','Q','IsAllObjectsStopped',0.0],'WaitForObjectsStop constants/arity')
    i24=[lua_instruction(w,pc) for pc,w in enumerate(p24['words'])]
    check(i24[0]['opcode']=='GETGLOBAL' and i24[1]['opcode']=='CALL' and i24[1]['B']==1 and i24[1]['C']==1,'initial zero-argument yield')
    check(i24[5]['opcode']=='EQ' and i24[5]['C']==259 and i24[6]['jump_target']==10 and i24[9]['jump_target']==2,'numeric-zero polling CFG')
    i26=[lua_instruction(w,pc) for pc,w in enumerate(p26['words'])]
    check(p26['params']==7 and [i26[i]['B'] for i in range(9,15)]==[0,1,2,4,5,6],'seven-to-six wrapper argument mapping')
    check(i26[15]['opcode']=='CALL' and i26[15]['B']==7 and i26[15]['C']==1,'native WalkObject six args / zero results requested')
    check(p35['params']==1 and p35['constants']==['Q','StopObject','yield'],'StopObject wrapper')
    speed_map={}
    for at in range(0,24,4):
        eq=lua_instruction(p25['words'][at],at); val=lua_instruction(p25['words'][at+2],at+2)
        check(eq['opcode']=='EQ' and val['opcode']=='LOADK','speed converter case shape')
        speed_map[str(int(p25['constants'][eq['C']-256]))]=p25['constants'][val['Bx']]
    check(speed_map==contracts['walk_global']['speedstep_map'],'speedstep original mappings')

    source_count=0
    if args.verify_sources:
        env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0')
        for row in sources['sources']:
            tree_spec=row['commit']+':'+row['path']
            actual=subprocess.run(['git','rev-parse',tree_spec],cwd=args.repo,env=env,check=True,capture_output=True).stdout.decode().strip()
            check(actual==row['git_blob'],'source tree/blob '+row['path'])
            b=subprocess.run(['git','cat-file','blob',actual],cwd=args.repo,env=env,check=True,capture_output=True).stdout
            git_oid=hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
            check(git_oid==actual and len(b)==row['bytes'] and digest(b)==row['sha256'],'source content '+row['path'])
            source_count+=1
    return dict(status='PASS',scope='Read-only exact-byte, PE, contiguous decode, binding/type, selected CFG, original Lua-data and source-pin checks; not T01 FULL-PASS',bin_sha256=o['sha256'],event_sha256=lua['carrier']['sha256'],qbase_sha256=lua['member']['decoded_sha256'],native_windows=len(native['windows']),code_windows=code_count,instruction_records=instruction_count,native_instruction_assertions=len(contracts['native_instruction_assertions']),selected_cfg_edges=len(edges),q_selected_bindings=len(bindings['q']),tutorial_regular_bindings=len(bindings['tutorial']),selected_lua_prototypes=len(lua['selected_prototypes']),selected_lua_words=sum(len(p['words']) for p in lua['selected_prototypes']),selected_root_bindings=len(lua['selected_root_bindings']),source_pins_verified=source_count,source_pin_check_enabled=args.verify_sources,artifact_hashes_verified=len(artifacts['files']),executed_client=False,executed_lua=False,modified_originals=False,t01_full_pass=False,ordinary_battle_completion_bridge_closed=False)


def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--repo',type=Path,required=True)
    ap.add_argument('--bin',type=Path,required=True)
    ap.add_argument('--event',type=Path,required=True)
    ap.add_argument('--verify-sources',action='store_true')
    args=ap.parse_args()
    try: print(json.dumps(run(args),ensure_ascii=False,indent=2))
    except Exception as e:
        print(json.dumps(dict(status='FAIL',error=str(e)),ensure_ascii=False),file=sys.stderr)
        raise SystemExit(1)


if __name__=='__main__': main()
