#!/usr/bin/env python3
"""Read-only check of selected capability controls and qbase export navigation.

Reads original BIN/STP, fixed local Git objects and derived evidence only.
No Client, Lua, Server or game resource execution; no fetch or repository write.
PASS verifies bytes, provenance and the listed bounded facts, not gameplay.
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
import types
sys.dont_write_bytecode = True

def require(ok, why):
    if not ok:
        raise ValueError(why)
def sha(b):
    return hashlib.sha256(b).hexdigest()
def number(v):
    return int(v, 0) if isinstance(v, str) else v
def read(p):
    return json.loads(p.read_text())

def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', type=Path, required=True)
    ap.add_argument('--event-stp', type=Path, required=True)
    ap.add_argument('--repo', type=Path, required=True)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    a = ap.parse_args(); e = a.evidence_dir
    source = read(e/'source-manifest.json'); native = read(e/'native-windows.json')
    helpers = read(e/'helper-index.json'); bindings = read(e/'bindings.json')
    env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_OPTIONAL_LOCKS='0', GIT_NO_REPLACE_OBJECTS='1', GIT_TERMINAL_PROMPT='0')
    blobs = {}
    for p in source['references']:
        b = subprocess.check_output(['git','-c','remote.origin.promisor=false','-c','maintenance.auto=false','show',p['commit']+':'+p['path']],cwd=a.repo,env=env)
        require(len(b)==p['bytes'] and sha(b)==p['sha256'], 'Pinned content '+p['path'])
        require(hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==p['blob'], 'Pinned blob '+p['path'])
        blobs[p['path']] = b
    pp = source['parser_source']; parser_bytes = blobs[pp['path']]
    require(sha(parser_bytes)=='8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56','Fixed read-only parser')
    parser = types.ModuleType('fixed_capability_parser'); parser.__file__=pp['path']
    exec(compile(parser_bytes,pp['path'],'exec'),parser.__dict__)
    meta=dict(native['binary'],size=native['binary']['bytes'])
    pe=parser.PE(a.bin,meta); boundaries=set(); instructions=0
    for w in native['records']:
        pe.verify_window(w)
        require(number(w['end'])-number(w['va'])==w['length'],'Window extent '+w['id'])
        if w['kind']!='code':continue
        txt=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16','--start-address='+w['va'],'--stop-address='+hex(number(w['end'])+15),str(a.bin)],text=True)
        actual=[]
        for line in txt.splitlines():
            m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if m and int(m[1],16)<number(w['end']):
                va=int(m[1],16); b=bytes.fromhex(m[2])
                actual.append(dict(va=hex(va),raw=hex(pe.raw_of(va,len(b))),hex=b.hex(),asm=m[3].strip()))
        require(actual==w['instructions'],'Regenerated disassembly '+w['id'])
        cursor=number(w['va'])
        for ins in actual:
            require(number(ins['va'])==cursor and '(bad)' not in ins['asm'],'Contiguous native boundary '+w['id'])
            boundaries.add(cursor);cursor+=len(bytes.fromhex(ins['hex']));instructions+=1
        require(cursor==number(w['end']),'Exact native endpoint '+w['id'])
    def at(v,n):return pe.at(number(v),n)
    def u32(v):return struct.unpack('<I',at(v,4))[0]
    def cstr(v):
        off=pe.raw_of(number(v),1);return pe.data[off:pe.data.index(0,off)].decode('ascii')
    baseline=json.loads(blobs['kr-extra-roy/MEF-control-flow-20261116/world/bindings.json'])['rows']
    for x in bindings['rows']:
        require(x==next(b for b in baseline if b['full_name']==x['full_name']),'Inherited tuple '+x['full_name'])
        r=number(x['registrar']);call=number(x['call_site']);b=at(call,5)
        require(b[0]==0xe8 and call+5+struct.unpack_from('<i',b,1)[0]==r,'Actual root registration call '+x['full_name'])
        require(at(r,x['length']).hex()==x['hex'],'Registrar raw '+x['full_name'])
        require(at(r+0x18,2)==b'\xc7\x05' and u32(r+0x1a)==number(x['slot']) and u32(r+0x1e)==number(x['native']),'Native target '+x['full_name'])
        require(cstr(x['name_va'])==x['name'] and u32(r+0x6a)==number(x['closure']),'Name and closure '+x['full_name'])
    require(at(0x4a0b70,6)==bytes.fromhex('ff25a025bd00') and u32(0xbd25a0)+pe.base==0xd5f00c and cstr(0xd5f00e)=='timeGetTime','GetTime exact import')
    require(at(0x4a21d9,3)==bytes.fromhex('db4508'),'GetTime signed DWORD FILD, no unsigned repair')
    require(at(0x5f5d10,1)==b'\xc3','PrintCurrSceneID stub')
    require(at(0x56ce05,5)==bytes.fromhex('b9d074fb00'),'Minimap BOUND map receiver differs from trigger root')
    require(at(0x4a142e,3)==bytes.fromhex('8b4d08') and at(0x4a1431,5)==bytes.fromhex('bfc4f3fd00'),'Minimap numeric key and existing component holder')
    require(cstr(0xc107b0)=='Map/Minimap/townMinimap.mmm' and cstr(0xc107cc)=='Map/Minimap/fieldMinimap.mmm' and cstr(0xc107fc)=='.mmt','Exact minimap resource suffixes')
    require(at(0x58b4b9,5)==bytes.fromhex('3dd8d60000'),'HideUI current page type guard')
    require(at(0x5969fe,6)==bytes.fromhex('8b9094000000') and at(0x596a04,2)==bytes.fromhex('6a00'),'HideUI visibility virtual receives zero')
    stp=parser.STPD(a.event_stp,helpers['carrier']);chunk=stp.verify_member(helpers['member']);ps=parser.read_lua51_prototypes(chunk)
    require(len(ps)==76 and sum(len(p['words'])for p in ps)==906,'Whole original qbase structural counts')
    full_old=json.loads(blobs['shared/integrations/T01-20261029-semantic-review/t16/lua/kr-qbase.lua.json'])['prototypes']
    for p in ps:
        for key,value in p.items():require(value==full_old[p['index']][key],'Original qbase versus pinned navigation '+str(p['index'])+'/'+key)
    root=ps[0];actual=[]
    for pc in range(len(root['words'])-1):
        w,n=root['words'][pc:pc+2]
        if w&63==36 and n&63==7 and ((w>>6)&255)==((n>>6)&255):
            p=ps[root['children'][w>>14]];raw=b''.join(struct.pack('<I',x)for x in p['words'])
            actual.append(dict(name=root['constants'][n>>14],prototype=p['index'],parameters=p['params'],vararg=p['vararg'],root_closure_pc=pc,root_setglobal_pc=pc+1,instruction_words=len(p['words']),code_sha256=sha(raw),referenced_globals=list(dict.fromkeys(p['constants'][x>>14]for x in p['words']if x&63==5)),stored_globals=list(dict.fromkeys(p['constants'][x>>14]for x in p['words']if x&63==7)),return_only=all(x&63==30 for x in p['words'])))
    require(actual==helpers['exports'] and len(actual)==75,'All 75 qbase closure exports reproduced from original')
    stubs=[x['name']for x in actual if x['return_only']]
    require(stubs==['OnNextTalk','Phase2','Phase3','Phase4','RevPhase4','RevPhase2'],'Helper no-op bodies distinguished from capabilities')
    for name in ['StartLoading','EndLoading']:
        x=next(x for x in actual if x['name']==name)
        require(x['referenced_globals']==['yield'] and x['stored_globals']==[],'Loading helper is a scheduling point, not a resource loader')
    print(json.dumps(dict(status='PASS',scope='Selected capability controls, raw instructions, fixed sources and all qbase export descriptors; no runtime acceptance',native_records=len(native['records']),code_windows=sum(w['kind']=='code'for w in native['records']),native_bytes=sum(w['length']for w in native['records']),decoded_instructions=instructions,selected_bindings=len(bindings['rows']),source_pins=len(source['references']),qbase=dict(prototypes=len(ps),instruction_words=906,root_exported_functions=len(actual),return_only_helpers=stubs,full_member_published=False),client_executed=False,lua_executed=False,server_executed=False),ensure_ascii=False,indent=2))

if __name__=='__main__':
    try:main()
    except (ValueError,KeyError,OSError,subprocess.CalledProcessError) as exc:
        print(json.dumps(dict(status='FAIL',error=str(exc)),ensure_ascii=False),file=sys.stderr);sys.exit(1)
