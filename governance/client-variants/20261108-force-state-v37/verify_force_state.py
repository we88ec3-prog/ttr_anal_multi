from pathlib import Path
import sys,struct,hashlib,json,argparse
parser=argparse.ArgumentParser();parser.add_argument("--workspace-root",type=Path,default=Path(__file__).resolve().parents[3]);R=parser.parse_args().workspace_root.resolve()
sys.path.insert(0,str(R/'anal/python_deps'));sys.path.insert(0,str(R/'anal'))
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from build_native_index import PE
D=Path(__file__).parent;pe=PE(R/'Tartaros.bin');sha=lambda b:hashlib.sha256(b).hexdigest()
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert sha(pe.data)==TARGET
md=Cs(CS_ARCH_X86,CS_MODE_32)
specs=[(0x4cd6f0,0x4cdaa0,0x4cd9b5,0x4cda0d),(0x4cb230,0x4cb300,0x4cb230,0x4cb2b0),(0x4cbe30,0x4cbe43,0x4cbe30,0x4cbe43),(0x4c8a90,0x4c8b90,0x4c8b67,0x4c8b86),(0x546100,0x5464a0,0x546230,0x546269),(0x4b0130,0x4b01c0,0x4b0130,0x4b01b0)]
identity=[];outputs=[]
for root,end,start,stop in specs:
 instructions=list(md.disasm(pe.read(root,end-root),root));chosen=[i for i in instructions if start<=i.address<stop]
 assert chosen and chosen[0].address==start,(hex(start),[hex(i.address) for i in chosen[:3]])
 body='\n'.join(f'{i.address:08x} {i.bytes.hex()} {i.mnemonic} {i.op_str}' for i in chosen)+'\n'
 outputs.append(body);identity.append({'root':hex(root),'range':[hex(start),hex(stop)],'sha256':sha(pe.read(start,stop-start)),'method':'ROOTED_CAPSTONE_X86_32_FROM_FUNCTION_ENTRY'})
# Exact RTTI complete-object locator and the valid five-slot Force vtable.
assert pe.read(0xf7e708,32).startswith(b'.?AVCForceState@CharStates@@')
assert struct.unpack('<5I',pe.read(0xc6a874,20))==(0,0,0,0xf7e700,0xc6a888)
assert struct.unpack('<I',pe.read(0xc079b0,4))[0]==0xc6a874
assert struct.unpack('<5I',pe.read(0xc079b4,20))==(0x4cb8e0,0x4cbe30,0x476430,0x5f5d10,0x5f5d10)
assert pe.read(0x4cd9b7,5)==bytes.fromhex('b90c000000')
assert pe.read(0x4cd9c6,6)==bytes.fromhex('c706b479c000')
assert pe.read(0x4cbe3e,4)==bytes.fromhex('6a13ffd2')
(D/'native-windows.txt').write_text('\n'.join(outputs),encoding='utf-8')
f=R/'anal-multi/kr-bulk-roy'/TARGET/'functions'
sources=[]
for a in [0x4cd6f0,0x4cb230,0x4cbe30,0x4c8a90,0x546100,0x4b0130,0x4c7070]:
 p=f/f'0x{a:x}.c';sources.append({'address':hex(a),'path':str(p.relative_to(R)).replace('\\','/'),'sha256':sha(p.read_bytes()),'status':'SAVED_BULK_SOURCE_NOT_WHOLE_FUNCTION_FULL_PASS'})
(D/'contract.json').write_text(json.dumps({'schema':'S00_V37_FORCE_STATE_NATIVE_BOUNDARY','targetSha256':TARGET,'rtti':{'typeDescriptor':'0xF7E700','locator':'0xC6A874','vtable':'0xC079B4','enter':'0x4CBE30'},'forceState':12,'forceMotion':19,'skillState':13,'wireCandidate':'000C + u16actor + signedbyte12','claims':['Character ctor passes ECX12 to state ctor and registers Force vtable under resulting stateID.','Force Enter invokes actor virtual68 with motion19 and speed1 without forcing skill state13.','Character Force sets state+2C/+30 to1, which differs from zero default in ordinary SkillState.','546100 requires current state+2C nonzero before constructing action and V-event rows.','000C handler forwards statebyte through actorFSM virtual8.'],'unknown':['Official Server emission timing/sequence not observed.','UI row2 during heldV remains explicit Server reconstruction.','Human v37 interaction and animation pending.'],'ranges':identity,'sources':sources},ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print('Bounded ForceState identity/instruction assertions passed')
