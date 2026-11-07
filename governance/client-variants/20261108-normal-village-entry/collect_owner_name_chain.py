"""Collect bounded original source for directory owner UID/name cache publication."""
from pathlib import Path
import sys,json,hashlib
ROOT=Path(__file__).resolve().parents[3]
sys.path[:0]=[str(ROOT/'anal/python_deps'),str(ROOT/'anal')]
sys.stdout.reconfigure(encoding='utf-8')
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32,CS_OP_MEM,CS_OP_IMM
sha=lambda b:hashlib.sha256(b).hexdigest()
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
p=PE(ROOT/'Tartaros.bin');assert sha(p.data)==TARGET
m=Cs(CS_ARCH_X86,CS_MODE_32);m.detail=True
ins=list(m.disasm(p.read(0x4e1e4f,10),0x4e1e4f))[0]
assert ins.mnemonic=='mov' and ins.operands[0].type==CS_OP_MEM and ins.operands[1].type==CS_OP_IMM
assert ins.operands[1].imm==0x4e27b0
disp=ins.operands[0].mem.disp
assert disp==0xe4 and (disp-4)%8==0
opcode=(disp-4)//8;assert opcode==0x1c
bulk=ROOT/'anal-multi/kr-bulk-roy'/TARGET/'functions'
sources=[]
for va in [0x4f6a30,0x4a8680,0x4f6b80,0x425330,0x4f6950,0x4e27b0,0x4e1da0,0x4b7f00,0x68e6f0]:
 f=bulk/f'0x{va:x}.c';sources.append({'va':f'{va:08X}','path':str(f.relative_to(ROOT)),'sha256':sha(f.read_bytes())})
windows=[]
for va,n in [(0x4f6a30,0xb0),(0x4f6b80,0xcf),(0x491fc7,0xc),(0x4e1e4f,10),(0x4e27b0,0xd3),(0x4f6950,0xe0),(0x4b8030,0x70)]:
 b=p.read(va,n);windows.append({'va':f'{va:08X}','length':n,'sha256':sha(b),'instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in m.disasm(b,va)]})
d={
 'schema':'normal-directory-owner-name-chain-v1','targetSha256':TARGET,
 'authority':'BOUNDED_ORIGINAL_NATIVE_SOURCE_NOT_OFFICIAL_SERVER_CAPTURE',
 'directoryStart':'008D row DWORD+2E ownerUID is consumed by 68EB45 ->4F6A30; prior directory-list-and-leave.json records that boundary.',
 'cache':{'singleton':'425330 returns FB7470','lookup':'4F6A30 EAX=this; stackarg UID; lookup map this+100, sentinel this+104','miss':'4F6A72 adds this+110;4F6A7B calls4A8680 with EAX=&UID, EDI=&queue; inserts placeholder into same cache','placeholder':'E2AA9C string used, not a real owner name','setter':'4F6950 EAX=this, stack UID/name; inserts name or overwrites an existing entry if incoming name is nonempty'},
 'request':{'producer':'491FC7 calls425330 -> ESI=this ->491FCE calls4F6B80','queue':'this+110 begin,+114 end,+118 capacity','command':'0013','slot':2,'layout':'WORD command at0, N DWORD UIDs consecutively at+2; no count prefix','length':'2+4*N','batchLimit':20,'queueConsumption':'4F6BFE..4F6C2D removes consumed prefix and retains the rest; send only when length>2','boundary':'This proves an actual native send invocation slot2; Server routing/connection ownership must preserve it.'},
 'reply':{'command':f'{opcode:04X}','handler':'4E27B0','registration':{'instructionVA':'004E1E4F','displacement':disp,'formula':'(displacement-4)//8','opcode':opcode},'header':'WORD opcode only, rows start+2','rows':'floor((length-2)/46)','row':{'0':'UTF16 name21WCHAR (42 bytes; terminated name expected by4F6950)','42':'DWORD UID'},'length':'2+46*N','update':'4E2830 reads row+2A UID; pushes row name, UID; EAX=FB7470;4E283A calls4F6950','selfUpdate':'if UID==CGlobalStatus+5F50, copies at most20 UTF16 characters to CGlobalStatus+5F12 (capacity21)'},
 'nameIdentity':{'globalBase':'F8D9E0','globalName':'F8D9E0+5F12 = F938F2','rosterBootstrap':'S2C0002/4B7F00 copies packet UTF16+0C to F938F2, capacity21/max20; UID packet+2 ->F93930 = global+5F50','conclusion':'001C publishes the same per-UID expedition/adventure-team name field as the existing roster bootstrap; it is not a role-specific character name row.'},
 'implementationBoundary':['Server can answer known requested owner wireAlias values with saved expedition names using this source-shaped001C layout.','Native consumes terminated UTF16 strings; initialize all21 WCHAR and keep max20 characters plusNUL.','No unsolicited placeholder labels or fabricated names for unknownUIDs are justified by this chain.','No inference of request+1:001C is derived from original registration operand.','The cache handler does not visibly emit a UI notification in this bounded function; normal list refresh/paint can query the updated cache.','No Client execution, game attachment, provider retry, shared source edits, Host restart or multiplayer test performed.'],
 'sources':sources,'originalWindows':windows
}
f=Path(__file__).with_name('directory-owner-name-chain-v1.json');f.write_text(json.dumps(d,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps({'path':str(f),'sha256':sha(f.read_bytes()),'opcode':f'{opcode:04X}','sourceCount':len(sources)}))
