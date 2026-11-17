#!/usr/bin/env python3
"""Read-only KR native owner/lifecycle proof and SYN model verification.

No network, git mutation, game-resource creation, Client/Lua/Server execution.
Requires Python 3 and GNU objdump. Previous published-pending surface package
is a pinned, independently reproducible dependency; supply its path explicitly.
The optional original Event/parser pair also rechecks selected original qbase.
"""
from __future__ import annotations
import argparse, csv, hashlib, importlib.util, io, json, re, struct, subprocess, sys, unittest
from pathlib import Path

BIN_SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
AUDIT_SHA='d9e8c5ddd465eb192362ad77d68e70b39537eb681a041b329df48359c0c67564'
PRIOR_FILES={
 'surface-census.json':'0a52a335fae857a00cfc03be40c48af658d3ca73a9a03ee0e1217aa30221e1cf',
 'native-proof.json':'0519737ffcc421e824ed9f642635861638a10a729f43a722a3704c64793555ea',
 'capability-matrix.tsv':'e377e7776012c65e7d4e16ea8160ae94551ef8cb80dca2e3650c395e8e0d533a',
 'qbase-evidence.json':'3e0f7d641991b262c2ddcbea6791c50c4b7426fee917fb48372a1d8fa661a59e'}

def require(condition: bool, message: str) -> None:
    if not condition: raise ValueError(message)
def sha(data: bytes) -> str: return hashlib.sha256(data).hexdigest()
def load(path: Path): return json.loads(path.read_text(encoding='utf-8'))
def num(value): return int(value,0) if isinstance(value,str) else value

def main() -> dict:
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--bin',type=Path,required=True)
    p.add_argument('--previous',type=Path,default=Path(__file__).resolve().parent.parent/'MEF-full-surface-native-continuation-20261116')
    p.add_argument('--event',type=Path)
    p.add_argument('--prior-parser',type=Path)
    p.add_argument('--check-manifest',action='store_true')
    a=p.parse_args(); root=Path(__file__).resolve().parent
    require(not sys.flags.optimize,'Optimized Python is not supported by the inherited verifier')
    audit_path=a.previous/'audit.py'
    require(sha(audit_path.read_bytes())==AUDIT_SHA,'Pinned read-only audit SHA mismatch')
    for path,digest in PRIOR_FILES.items():
        require(sha((a.previous/path).read_bytes())==digest,'Pinned prior evidence: '+path)
    spec=importlib.util.spec_from_file_location('fixed_surface_audit',audit_path)
    mod=importlib.util.module_from_spec(spec);spec.loader.exec_module(mod)
    pe=mod.PE(a.bin)
    require(sha(pe.b)==BIN_SHA,'Original identity')
    cmd=[sys.executable,'-B',str(audit_path),'--bin',str(a.bin)]
    if a.event or a.prior_parser:
        require(bool(a.event and a.prior_parser),'Event and parser must be supplied together')
        cmd.extend(['--event',str(a.event),'--prior-parser',str(a.prior_parser)])
    previous=json.loads(subprocess.check_output(cmd,text=True))
    require(previous['status']=='PASS','Prior bounded census/continuation checks')
    e=load(root/'native-evidence.json');require(e['binary_sha256']==BIN_SHA,'Evidence identity')
    decoded={};boundaries=set();asm=[];instruction_bytes={}
    for record in e['windows']:
        start,end=num(record['va']),num(record['end']);b=pe.at(start,end-start)
        require(pe.raw(start,len(b))==num(record['raw']),'Window PE mapping '+record['id'])
        require(len(b)==record['bytes'] and sha(b)==record['sha256'] and b.hex()==record['hex'],'Window bytes '+record['id'])
        ins=pe.decode(start,end);decoded[record['id']]=ins
        require(len(ins)==record['instruction_count'],'Window boundary/count '+record['id'])
        for v,h,t in ins:
            if v in instruction_bytes:require(instruction_bytes[v]==h,'Overlapping instruction mismatch')
            instruction_bytes[v]=h;boundaries.add(v)
        asm.append('; '+record['id']+' ['+record['classification']+'] '+hex(start)+'..'+hex(end)+'\n'+'\n'.join(f'{v:08X}  {h:<30} {t}' for v,h,t in ins))
    require((root/'native-evidence.asm').read_text()=='\n\n'.join(asm)+'\n','Reproduced human-readable ASM')
    for record in e['anchors']+e['data']:
        start=num(record['va']);b=bytes.fromhex(record['hex'])
        require(pe.raw(start,len(b))==num(record['raw']) and pe.at(start,len(b))==b,'Anchor/data '+record['id'])
    for record in e['anchors']:
        start=num(record['va']);end=start+len(bytes.fromhex(record['hex']))
        require(start in boundaries and (end in boundaries or any(num(w['end'])==end for w in e['windows'])),'Anchor instruction boundary '+record['id'])
    for start,target in e['calls']:
        require(num(start) in boundaries and pe.rels_target(num(start))==num(target),'Direct call '+start)
    tables={
      0xc0fd20:{4:0x54e080,8:0x54e230,12:0x54e260,20:0x54e270,32:0x54e310},
      0xc0fd48:{4:0x54e340,12:0x54e570,16:0x54e580},
      0xc10748:{0:0x553e40,8:0x553de0,20:0x553b60,24:0x553fa0,36:0x80f010},
      0xc40fec:{8:0x4facd0}, 0xc0cf2c:{0:0x4e0520},
      0xc51bf4:{44:0x80eb30}}
    for address,slots in tables.items():
        for offset,target in slots.items():require(pe.u32(address+offset)==target,'Concrete virtual slot')
    require(list(struct.unpack('<5I',pe.at(0x553c50,20)))==[0x553b79,0x553b84,0x553b9a,0x553be9,0x553c05],'Image phase table')
    require(struct.unpack('<d',pe.at(0xc55890,8))[0]==0.20000000298023224,'Actual slow factor')
    require(pe.string(0xc106ec)=='f_removeAllCoroutines','Normal End names original qco clear')
    # Only explicit normal-End E8 destinations. This is NOT a transitive no-side-effect proof.
    normal_calls=[]
    for v,h,t in decoded['normal_and_review_end']:
        if v>=0x561f60 and h.startswith('e8') and len(bytes.fromhex(h))==5:
            normal_calls.append(pe.rels_target(v))
    cleanup={0x563a70,0x564a60,0x6d9cc0,0x54e9f0,0x564810,0x5656b0,0x564b50}
    require(not cleanup.intersection(normal_calls),'Unexpected explicit normal-End cleanup; review report')
    ledger=load(root/'feature-families.json');families={f['id']:f for f in ledger['families']}
    matrix=list(csv.DictReader((root/'capability-lifecycle.tsv').open(),delimiter='\t'))
    prior=list(csv.DictReader((a.previous/'capability-matrix.tsv').open(),delimiter='\t'))
    old={r['name']:r for r in prior}; names={r['name']for r in matrix}
    require(len(matrix)==121 and len(names)==121 and names==set(old),'Exact normal-name coverage')
    all_family_names=[n for f in families.values() for n in f['methods']]
    require(len(all_family_names)==121 and set(all_family_names)==names,'Family assignment no missing/duplicates')
    for row in matrix:
        for key in ('native','registrar','caller','closure','semantic_basis'):
            require(row[key]==old[row['name']][key],'Inherited binding tuple '+row['name'])
        require(row['name'] in families[row['family']]['methods'],'Family membership')
        require(row['deployment']=='NOT_DEPLOYED' and row['gameplay']=='NOT_TESTED','No inflated status')
        require(all(w in decoded for w in families[row['family']]['current_native_records']),'Evidence record link')
    require(not ledger['all_functions_complete'] and ledger['not_native_mef'],'Scope must remain explicit')
    sys.path.insert(0,str(root))
    import test_models
    suite=unittest.defaultTestLoader.loadTestsFromModule(test_models)
    stream=io.StringIO();tests=unittest.TextTestRunner(stream=stream,verbosity=1).run(suite)
    require(tests.wasSuccessful(),stream.getvalue())
    if a.check_manifest:
        for item in load(root/'artifact-manifest.json')['files']:
            b=(root/item['path']).read_bytes()
            require(len(b)==item['bytes'] and sha(b)==item['sha256'],'Artifact hash '+item['path'])
    return dict(status='PASS',scope='KR identity, bounded native windows/calls/vtables, inherited registration census, exact matrix coverage and SYN models; not formal semantics/gameplay',
      binary_sha256=BIN_SHA,native_windows=len(e['windows']),native_bytes=sum(w['bytes']for w in e['windows']),
      decoded_instructions=sum(len(v)for v in decoded.values()),unique_instruction_starts=len(instruction_bytes),
      exact_anchors=len(e['anchors']),data_windows=len(e['data']),direct_calls=len(e['calls']),
      virtual_slots_checked=sum(len(s)for s in tables.values()),formal_binding_names=len(matrix),functional_families=len(families),
      inherited_surface_recheck=previous,synthetic_tests=tests.testsRun,
      client_executed=False,lua_executed=False,server_executed=False,gameplay_tested=False,
      official_mef_first_loader_proven=False,all_functions_complete=False,
      limits=['Original Lua parsed only by the optional pinned data parser; not executed',
              'Normal initialized bindings/qbase and same-scene retained owners; no arbitrary runtime table replacements',
              'Selected cleanup/termination joins only; no exhaustive computed/inlined/DLL closure census',
              'Synthetic models are reasoning checks, not native runtime or formal semantic certification',
              'No T01/RR/Server deployment status changed'])

if __name__=='__main__':
    try: print(json.dumps(main(),ensure_ascii=False,indent=2))
    except (ValueError,OSError,KeyError,subprocess.CalledProcessError) as exc:
        print(json.dumps({'status':'FAIL','error':str(exc)},ensure_ascii=False),file=sys.stderr)
        raise SystemExit(1)
