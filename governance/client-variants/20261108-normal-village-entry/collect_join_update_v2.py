"""Bounded read-only evidence collection; writes only adjacent metadata."""
from pathlib import Path
import sys, json, hashlib, re, xml.etree.ElementTree as ET
sys.stdout.reconfigure(encoding='utf-8')
ROOT=Path(__file__).resolve().parents[3]
sys.path[:0]=[str(ROOT/'anal/python_deps'),str(ROOT/'anal')]
from build_native_index import PE
from stp_resources import Archive
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
p=PE(ROOT/'Tartaros.bin'); assert sha(p.data)==TARGET
md=Cs(CS_ARCH_X86,CS_MODE_32)
bulk=ROOT/'anal-multi/kr-bulk-roy'/TARGET/'functions'
sources=[]
for va in [0x53a0a0,0x539690,0x539810,0x5398e0,0x53b750,0x53aaa0,0x53ace0,0x53b100,0x53b2c0,0x797a00,0x53b990,0x68d020,0x68e070,0x692390,0x68fed0,0x53bc60,0x68f6a0,0x6903b0,0x53bc00]:
 f=bulk/f'0x{va:x}.c'
 sources.append({'va':f'{va:08X}','path':str(f.relative_to(ROOT)),'sha256':sha(f.read_bytes()) if f.exists() else None})
windows=[]
for va,n in [(0x53a0ce,0x25),(0x53a1c5,0x51),(0x68d3ac,0x19),(0x68e087,0xd),(0x6923a3,0xa),(0x69029e,0x25),(0x53bc60,0x57)]:
 b=p.read(va,n)
 windows.append({'va':f'{va:08X}','length':n,'sha256':sha(b),'instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in md.disasm(b,va)]})
resources=[]
for carrier,member in [('UI/Component.stp','Component/Party_Matching_Wnd.FTC'),('UI/StringTable.stp','StringTable/Korean.FCS')]:
 f=ROOT/carrier; a=Archive(f); b=a.read(member)
 resources.append({'carrier':carrier,'carrierSha256':sha(f.read_bytes()),'member':member,'decodedLength':len(b),'decodedSha256':sha(b)})
 tree=ET.fromstring('<AUDIT>'+re.sub(r'<\?xml.*?\?>','',b.decode('utf-8'))+'</AUDIT>')
 # Keep only bounded label nodes; do not export the resource payload.
 selected=[]
 if carrier.endswith('Component.stp'):
  resources[-1]['boundedWidgetLinks']=[{'eid':node.get('EID'),'class':node.get('ClassName'),'textLinkCodes':[c.get('Code') for c in node.iter('TextLink') if c.get('Code')]} for node in tree.iter() if node.get('EID') in ('16000','50000','11000')]
 for node in tree.iter():
  xml=ET.tostring(node,encoding='unicode')
  if len(xml)>2000:continue
  if carrier.endswith('StringTable.stp') and any(v in xml for v in ['빠른 참여','파티 대기중인 리스트만 표시']):
   selected.append(xml)
 resources[-1]['boundedLabelNodes']=selected
out={
 'schema':'normal-party-join-update-v2','targetSha256':TARGET,
 'authority':'BOUNDED_NATIVE_AND_RESOURCE_EVIDENCE_NOT_OFFICIAL_SERVER_REPLY_CAPTURE',
 'opcodeAuthority':{'file':'party-opcode-correction-v2.json','sha256':sha((Path(__file__).parent/'party-opcode-correction-v2.json').read_bytes()),'formula':'(original registration memory displacement - 4) / 8; verifier checks exact divisible operands'},
 'memberPublication':{
  'handler':'008F -> 53A0A0','partyKey':'WORD packet+2 -> AX -> 53A960',
  'replacement':'DWORD packet+4 != 0 -> 797A00 with EDI=party+28: frees member objects and clears vector; party record/current pointer remains',
  'row':'9 bytes from packet+8: DWORD UID, BYTE role, BYTE level, WORD flags, BYTE Duel grouping candidate',
  'flags':{'0002':'leader property; ordinary full snapshot writes member+6 = true','0004':'join notification; if row UID equals GlobalStatus+5F50 then 53B750(partyKey) sets current party pointer; 53AAA0 notification','0008':'53ACE0 ordinary leave notification then 539810 marks member inactive','0040':'53B100 kick notification then 539810 marks member inactive','0001':'if existing member leader and set: clears leader and saves old leader UID','0020':'with 0002, when prior leader test does not take 0001 path: saves new leader UID'},
  'leaderTail':'if old/new leader UID nonzero -> 53B2C0(new UID), emits F4405; this does not itself prove a Server leadership-transfer request',
  'tail':'5398E0 compacts inactive member entries, then F4404 UI notification',
  'identity':'existing S2C0002 DWORD+2 -> F93930 = GlobalStatus+5F50; use published wireAlias; no need to invent unknown 002A fields'
 },
 'sourceShapedPolicyCandidates':{
  'joiner':'008E existing room record, then 008F full snapshot owner flags2 and joining self flags4; self UID must match current roster identity',
  'existingOwner':'008F full snapshot owner flags2 and new member flags4; replacing member vector does not clear current party record',
  'leaver':'0089 status0 clears own party; remaining members may receive 008F row flags8; official ordering not captured',
  'limits':['These consumers establish party affiliation and UI only, not scene/mode/map/position or actor spawn.','008E/008F do not carry directory kind/context. No same-scene teleport or room-context setter is inferred.','No actual multiplayer test performed; Server authorization, membership transactions and cross-session ordering remain policy.']
 },
 'modify':{'normalUI':'68D020 -> 68D3BD push0, push EDI(capacity), call53B990','request':'005F, 46 bytes: WORD opcode; name21WCHAR at+2; BYTE capacity+2C; BYTE flag+2D=0 in normal dialog','consumer':'008B -> 53A8C0 reads terminated name+2 and capacity+2C; minimum read45B; not a two-byte clear','listing':'008A sets record+24 from WORD+2; 008C clears record+24 without packet field reads'},
 'quickJoin':{'resource':'Matching EID16000 TextLink1145 -> Korean code1145 빠른 참여 (Quick Join)','nativeUI':'68E087 -> setup692390; 6923A3 push16000 binds button at panel+100; click69029E reads panel+208 kind and +20C context ->53BC60','request':'0055 length4: WORD opcode, BYTE kind+2, BYTE context+3','boundary':'Quick Join is NOT a room target setter.'},
 'waitingFilter':{'resource':'Matching EID50000 TextLink608 -> 파티 대기중인 리스트만 표시 (show only waiting parties)','request':'0052 +6 checkbox filter bit9; not a level filter','boundary':'Exact server admission/filter semantics beyond the UI label remain policy.'},
 'manualJoin':{'resource':'Matching EID11000 TextLink155 파티 신청','native':'selected row 68F6A0 ->6903B0 -> row DWORD+2E ownerUID ->53BC00(ownerUID,1)','request':'0054 length7: WORD opcode, BYTE1+2, DWORD ownerUID+3; not listing WORD key'},
 'sources':sources,'originalWindows':windows,'resources':resources,
 'limitations':['Original artifact only; no Client launch/attachment/patch/provider call.','No formal RR or full-function pass claim.','Prior metadata remains retained; opcode correction v2 supersedes conflicting old opcode prose.']
}
f=Path(__file__).with_name('join-update-and-modify-v2.json');f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'path':str(f),'sha256':sha(f.read_bytes()),'sources':len(sources),'windows':len(windows),'resources':resources},ensure_ascii=False))
