from pathlib import Path
import sys,json,hashlib,bisect,argparse
ap=argparse.ArgumentParser();ap.add_argument('--workspace-root',type=Path,default=Path(__file__).resolve().parents[3]);R=ap.parse_args().workspace_root.resolve();D=Path(__file__).parent
sys.path[:0]=[str(R/'anal/python_deps'),str(R/'anal')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
p=PE(R/'Tartaros.bin');sha=lambda b:hashlib.sha256(b).hexdigest();r=json.loads((D/'metadata.json').read_text(encoding='utf-8'));assert sha(p.data)==r['target_sha256']
for w in r['windows']:assert sha(p.read(int(w['va'],16),w['bytes']))==w['sha256']
for s in r['saved_bulk_sources']:assert sha((R/Path(s['path'])).read_bytes())==s['sha256']
assert p.read(int(r['type_descriptor'],16)+8,20).startswith(b'.?AVCMonster@@')
B=R/'anal-multi/kr-bulk-roy'/r['target_sha256'];idx=[json.loads(l) for l in (B/'index.jsonl').read_text(encoding='utf-8').splitlines()];by={int(x['address'],16):x for x in idx if x.get('status')=='ok'};starts=sorted(by);md=Cs(CS_ARCH_X86,CS_MODE_32)
text=[];sources=[]
for a in [0x4b2620,0x4bb150,0x4ca890,0x4cad40]:
 end=starts[bisect.bisect_right(starts,a)];raw=p.read(a,end-a);ins=list(md.disasm(raw,a));assert ins and ins[0].address==a
 f=B/'functions'/f'0x{a:x}.c';assert sha(f.read_bytes())==by[a]['pseudocode_sha256']
 sources.append({'root':hex(a),'endExclusive':hex(end),'rawSha256':sha(raw),'savedBulkSha256':sha(f.read_bytes()),'qualification':'SELECTED_CONTROL_FLOW_AND_DATA_WRITES_ONLY_NOT_WHOLE_FUNCTION_PASS'})
 if a in [0x4b2620,0x4bb150]:text.append('\n'.join(f'{i.address:08x} {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in ins))
(D/'historical-lead-windows.txt').write_bytes(('\n\n'.join(text)+'\n').encode())
(D/'historical-lead-boundaries.json').write_bytes((json.dumps({'schema':'S00_MONSTER_AUTHORITY_HISTORICAL_LEAD_BOUNDARY','targetSha256':r['target_sha256'],'sources':sources,'reusedReports':['anal/MONSTER-STATE-TRANSITIONS-AND-SOURCES.md','anal/LOCAL-ACTOR-AND-AI-FRAMEWORK.md','anal/LB-CREATE-OBJECT-ABI-AND-CONTROL.md','anal/BATTLE-AUTHORITY-TRACE.md'],'selectedClaims':['4B2620 selected actor categories0/1 loop requests state1 and clearsDWORD+E0 bit31, preservingdirection. It is an existing incoming reset path, not evidence of autonomous pursuit.','4BB150 selected loop looks up IDs0/1000/2000, selects state20 then one of21..23 or24..26 motionvalues. This loop is presentation sequencing, not an identified monster target/skill selector.','4CA890 consumes existing movementflags/direction and speedgetter to update movement; that is not itself a source for choosing a target.'],'unknown':['Unexpanded callees and indirect paths may have other roles.','Official Server versus host/peer authority remains unproven.','Native MEF trigger/parser/transport and autonomous monster decision chain remain unclosed.']},ensure_ascii=False,indent=2)+'\n').encode())
print('Verified',len(r['windows']),'native windows,',len(r['saved_bulk_sources']),'bulk identities and4bounded roots')
