from pathlib import Path
import sys,struct,hashlib,json,argparse,bisect
ap=argparse.ArgumentParser();ap.add_argument('--workspace-root',type=Path,default=Path(__file__).resolve().parents[3]);R=ap.parse_args().workspace_root.resolve();D=Path(__file__).parent
sys.path[:0]=[str(R/'anal/python_deps'),str(R/'anal')]
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from build_native_index import PE
T='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';pe=PE(R/'Tartaros.bin');sha=lambda b:hashlib.sha256(b).hexdigest();assert sha(pe.data)==T
md=Cs(CS_ARCH_X86,CS_MODE_32)
B=R/'anal-multi/kr-bulk-roy'/T;idx=[json.loads(l) for l in (B/'index.jsonl').read_text(encoding='utf-8').splitlines()];by={int(x['address'],16):x for x in idx if x.get('status')=='ok'};starts=sorted(by)
addresses=[0x546100,0x5480e0,0x549980,0x549c60,0x54f270,0x81a8e0,0x4ce7f0]
parsed={};source=[]
for a in addresses:
 end=starts[bisect.bisect_right(starts,a)];assert 0<end-a<0x3000
 parsed[a]=list(md.disasm(pe.read(a,end-a),a))
 f=B/'functions'/f'0x{a:x}.c';assert sha(f.read_bytes())==by[a]['pseudocode_sha256'];source.append({'root':hex(a),'bulkSha256':sha(f.read_bytes()),'rawRootedSha256':sha(pe.read(a,end-a)),'endExclusive':hex(end),'status':'SELECTED_CLAIMS_ONLY_NOT_FULL_FUNCTION_PASS'})
expected={0x5462b4:'mov ecx, dword ptr [edi + 0x3e8]',0x5462bf:'push ecx',0x54f2f2:'mov al, byte ptr [ebp + 0xc]',0x54f2f7:'call 0x81a8e0',0x54825d:'mov ecx, dword ptr [esi + 0x3e8]',0x549d2f:'mov ecx, dword ptr [edx + 0x3e8]'}
all_ins={i.address:i for v in parsed.values() for i in v}
for a,text in expected.items():
 i=all_ins[a];assert i.mnemonic+' '+i.op_str==text,(hex(a),i.mnemonic,i.op_str,text)
ranges=[(0x546100,0x5462b0,0x5462e2),(0x5480e0,0x54825d,0x548284),(0x549c60,0x549d23,0x549d59),(0x54f270,0x54f2d2,0x54f2fc),(0x81a8e0,0x81a8e0,0x81a910)]
lines=[];windows=[]
for root,start,end in ranges:
 ins=[i for i in parsed[root] if start<=i.address<end];assert ins and ins[0].address==start,(hex(start),hex(ins[0].address))
 lines.append('\n'.join(f'{i.address:08x} {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in ins))
 windows.append({'root':hex(root),'start':hex(start),'endExclusive':hex(end),'sha256':sha(pe.read(start,end-start))})
(D/'row-consumer-windows.txt').write_bytes(('\n\n'.join(lines)+'\n').encode())
(D/'contract.json').write_bytes((json.dumps({'schema':'S00_V37_V_ROW_CONSUMERS_PARTIAL','targetSha256':T,'source':source,'ranges':windows,'claims':['546100 selected actor+3E8 is pushed as second argument to54F270.','54F270 second stack argument low byte is loaded intoAL as matrixrow; key selectsCL column before81A8E0.','5480E0 has corresponding actor+3E8 row input.','549C60 includes actor+3E8 row fallback; not all optional override/UI paths classified.','81A8E0 accepts row0..3 and column0..10, returns0 outside bounds.'],'notProven':['Server response to67/68/69 or official row transition.','Two shortV and heldV must share row2.','All upstream UI and actor contexts.'],'separateExistingProof':['Parameter4 writesactor+3E8 in4CE7F0; ForceState12 changes FSM and animation, not3E8.']},ensure_ascii=False,indent=2)+'\n').encode())
print('V row consumer rooted assertions passed')
