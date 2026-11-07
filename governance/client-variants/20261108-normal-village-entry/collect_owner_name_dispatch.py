"""Read-only slot/lane and proactive name-cache publication boundary."""
from pathlib import Path
import sys,json,hashlib
ROOT=Path(__file__).resolve().parents[3]
sys.path[:0]=[str(ROOT/'anal/python_deps'),str(ROOT/'anal')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
p=PE(ROOT/'Tartaros.bin');assert sha(p.data)==TARGET
m=Cs(CS_ARCH_X86,CS_MODE_32)
bulk=ROOT/'anal-multi/kr-bulk-roy'/TARGET/'functions'
sources=[]
for va in [0x4957c0,0x806ad0,0x807b40,0x489920,0x8040a0,0x804740,0x4930e0,0x493170,0x48aad0,0x4943b0,0x4fda30,0x4e1da0,0x4e27b0]:
 f=bulk/f'0x{va:x}.c';sources.append({'va':f'{va:08X}','path':str(f.relative_to(ROOT)),'sha256':sha(f.read_bytes())})
windows=[]
for va,n in [(0x4957c0,0x45),(0x806ad0,0x69),(0x4930e0,0x7f),(0x493170,0x54),(0x48aad0,0x80),(0x4931b4,0xb),(0x49440c,0x2b),(0x48c027,8),(0x4e1e4f,10)]:
 b=p.read(va,n);windows.append({'va':f'{va:08X}','length':n,'sha256':sha(b),'instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in m.disasm(b,va)]})
assert (0x3c8-0x208)//16==0x1c and (0x3c8-0x208)%16==0
idx=json.loads((ROOT/'anal/native-index/Tartaros.bin.json').read_text(encoding='utf8'))
vt=[t for t in idx['vtables'] if t['className']=='.?AVCGlobalStatus@@' and t['thisOffset']==0][0]
assert vt['address']==0xc0d15c and vt['entries'][1]==0x4fda30
assert int.from_bytes(p.read(0xc0d160,4),'little')==0x4fda30
assert int.from_bytes(p.read(0xc05aec,4),'little')==0x4930e0
assert int.from_bytes(p.read(0xc05b08,4),'little')==0x48aad0
out={
 'schema':'owner-name-proactive-dispatch-boundary-v1','targetSha256':TARGET,
 'authority':'BOUNDED_SOURCE_SUPPORT_FOR_SERVER_POLICY_NOT_OFFICIAL_REQUEST_REPLY_OR_AUX_AUTH',
 'connections':{'normalPrimary':'4957E0 push2 pipeline,4957E2 push0 slot,port8416;4957EA connect','normalAux':'4957F2 push2 pipeline,4957F4 push2 slot,port8414;495803 connect','laneWrite':'806B25 reads fourth stackarg [EBP+14];806B33 stores connection+A080','conclusion':'Known primary slot0 and aux slot2 both feed pipeline lane2; socket slot and lane are distinct namespaces.'},
 'receiveScope':{'inheritedContract':'s00-runtime-dev/spec/protocol/SPEC-NET-0003.md:807B40 good frame->489920->8040A0->804740->4930E0','callback':'4930E0 validates positive length and lane2, invokes processor via[this+B8]+4; its connection argument is not used to select a command table','normalCallbackBase':'RTTI CClient subobject+148 VT C05AEC slot0=4930E0. Its+B8 is full-client+200 processor subobject, VT C05B04 slot4=48AAD0','registration':'493170 sets function slots starting fullclient+208 at16-byte stride;4931B9 stores4943B0 atfullclient+3C8','opcodeArithmetic':'(3C8-208)/10hex = 1Chex; exact modulo zero checked','redirect':'4943B0 forwards payload,length,command to F8D9E0 CGlobalStatus virtual+4; original vtable C0D15C+4=4FDA30','global':'GlobalStatus registration4E1E4F [EAX+E4]=4E27B0 =>(E4-4)/8=001C','scene':'001C explicit Client redirect executes before generic scene-manager routing; does not require live scene pointer or a scene-specific override in this bounded normal table.'},
 'supportedCandidate':'Server may proactively publish S2C001C containing only authorized/visible directory owner wireAlias and stored adventure-team names over the existing authenticated primary slot0 stream, to seed the cache before/with008D. This does not require claiming aux connection admission or pairing C2S0013 with this snapshot.',
 'limits':['This is source-shaped Server publication policy, not evidence of official unsolicited001C sequence.','No IP-based account association, aux authentication, new aux admission contract or C2S0013-on-slot0 alias is justified.','Known normal connections and callback identities only; dynamic later table overwrites and all alternative connections are not exhaustively audited.','No runtime delivery/Client test performed; table/ABI evidence does not equal complete end-to-end interoperability pass.','No guessed scene or mode changes.'],
 'sources':sources,'originalWindows':windows
}
f=Path(__file__).with_name('owner-name-proactive-dispatch-boundary-v1.json');f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(str(f));print(sha(f.read_bytes()))
