"""Bounded original invitation/response source; no Client execution."""
from pathlib import Path
import sys,json,hashlib,re,xml.etree.ElementTree as ET
ROOT=Path(__file__).resolve().parents[3]
sys.path[:0]=[str(ROOT/'anal/python_deps'),str(ROOT/'anal')]
sys.stdout.reconfigure(encoding='utf8')
from build_native_index import PE
from stp_resources import Archive
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
T='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';p=PE(ROOT/'Tartaros.bin');assert sha(p.data)==T
m=Cs(CS_ARCH_X86,CS_MODE_32);bulk=ROOT/'anal-multi/kr-bulk-roy'/T/'functions'
sources=[]
for va in [0x53a2d0,0x5b7c50,0x5b9850,0x5b7f80,0x5b9d50,0x53bc00,0x42bee0,0x6903b0,0x66fd30,0x66fed0,0x68f6a0,0x53bc60,0x53bb20,0x4a3ee0,0x4a3f20,0x68d4c0]:
 f=bulk/f'0x{va:x}.c';sources.append({'va':f'{va:08X}','path':str(f.relative_to(ROOT)),'sha256':sha(f.read_bytes())})
windows=[]
for va,n in [(0x53a2d0,0x15f),(0x5b9a48,0x71),(0x5b9db2,0x92),(0x53bc60,0x57),(0x66fdbe,8),(0x690490,0xb),(0x42bfc0,0xb),(0x4a3ee0,0x3a)]:
 b=p.read(va,n);windows.append({'va':f'{va:08X}','length':n,'sha256':sha(b),'instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in m.disasm(b,va)]})
f=ROOT/'Table.stp';b=Archive(f).read('Table/Messages/CommonMessages.xml');tree=ET.fromstring('<A>'+re.sub(r'<\?xml.*?\?>','',b.decode('utf8'))+'</A>')
labels=[n.attrib for n in tree.iter() if n.get('key') in ['kParty_ReceiveInvite','kParty_RequestApply','kParty_RequestInvite','kQuickJoinPartyNotExists']]
assert any(n.get('key')=='kParty_ReceiveInvite' for n in labels)
record=p.read(0xd65ed8,12);assert int.from_bytes(record[:4],'little')==0x3a and int.from_bytes(record[4:8],'little')==0xc18c94
assert p.read(0xc18c94,len(b'kParty_ReceiveInvite\0'))==b'kParty_ReceiveInvite\0'
loc=[]
for j in range(6):
 a=int.from_bytes(p.read(0xd6a0d4+j*4,4),'little');b0=p.read(a,100);end=next(k for k in range(0,98,2) if b0[k:k+2]==b'\0\0');loc.append({'index':j,'ptr':hex(a),'text':b0[:end].decode('utf-16le')})
out={
 'schema':'normal-party-invitation-confirmation-boundary-v1','targetSha256':T,
 'authority':'BOUNDED_NATIVE_CONSUMER_AND_REQUEST_PRODUCER_NOT_OFFICIAL_SERVER_ADMISSION_POLICY',
 's2c0090':{'handler':'53A2D0; opcode registration derives from party-opcode-correction-v2.json','layout':{'0':'WORD0090','2':'DWORD inviterUID','6':'UTF16 inviter adventure-team name21WCHAR42B','30hex':'BYTE inviter level (passed as formatted LV argument)','31hex':'BYTE inviter location kind (indexes D6A0D4)','32hex':'not read by this bounded handler','33hex':'BYTE copied into C2S0056 busy-response tail; native meaning unresolved'},'minimumReads':'normal popup branch reads through+31 (50B total); busy autoresponse reads+33 (52B total); do not claim52B official exact length','normal':'FB73E8==0 ->4F6950(inviterUID,name);F428C event payload UID/level/location;5B7C50->5B9850','popup':'5B9850 code3A kParty_ReceiveInvite, formats level/name/location and presents CF-style confirmation; not an applicant-awaits-owner-approval message','duplicate':'5B9850 checks pending map at page+2E8/+2EC keyed inviterUID before creating prompt; do not infer timeout/cancel policy','busy':'FB73E8!=0 ->C2S0056 DWORD status2 at+2, inviterUID at+6, tail copied from0090+33; no popup'},
 'confirmResponse':{'chain':'F43E0 ->5B7F80 ->5B9D50','command':'0056','length':11,'slot':0,'fields':{'0':'WORD0056','2':'DWORD1 for result6A7 accept; DWORD0 for result6A8 decline','6':'DWORD inviterUID from saved popup event','10':'BYTE0 in both explicit accept and decline'},'limits':'No party state mutated by sending acceptance; successful affiliation is still subsequent008E/008F consumer behavior.'},
 'request0054':{'builder':'53BC00(targetUID,byteMode)','length':7,'slot':0,'fields':'WORD0054,+2BYTE mode,+3DWORD targetUID','knownCallers':[{'callVA':'42BFC6','function':'42BEE0','mode':1,'target':'directory row+2E ownerUID'},{'callVA':'690496','function':'6903B0','mode':1,'target':'directory row+2E ownerUID'},{'callVA':'66FDC1','function':'66FD30 via66FED0','mode':0,'target':'CSquareUserListDialog selected user item+248 UID'}],'additionalEquivalent':'53BB20 manual InviteParty dialog checks local party and local leader, resolves entered name toUID;4A3EE0 emits0054 mode0 when cached or4A3F20 emits0063 mode0 + name when uncached. These are additional sender builders, not calls to53BC00.','preflight':'68F6A0: if directory join allowed and no current party ->6903B0 directly; if in another party -> own local confirmation Common43/kParty_RequestApply then F439B path. This is applicant consent to leave their current party, not owner authorization.'},
 'quickJoin':{'command':'0055','builder':'53BC60','exactLength':4,'slot':0,'fields':'WORD0055,+2BYTE directorykind,+3BYTE context','UI':'EID16000/1145 quick join as proven join-update-and-modify-v2.json','localState':'builder sends only; no new request correlation or alternate positive decoder selected in this function'},
 'serverBoundary':['0090 is an invitation to its receiving player, with explicit0056 consent; do not present it as owner-confirmation proof for0054 mode1.','Native Client cannot establish whether official Server admits0054 mode1 directly, asks owner, or sends an invitation back to applicant. The authoritative Server policy remains unresolved.','Likewise no captured official0055 positive reply sequence;008E/008F remains source-shaped affiliation publication independent of request source.','Safe adapter must state its chosen admission policy explicitly; existing internalJoin must not silently become official wire semantics.','No inferred scene/mode/travel changes or aux authentication.','No Client launch/attachment, Server/Host edits, or multiplayer tests.'],
 'resource':{'carrier':'Table.stp','carrierSha256':sha(f.read_bytes()),'member':'Table/Messages/CommonMessages.xml','decodedSha256':sha(b),'selectedLabels':labels,'nativeMessageBinding':{'va':'D65ED8','bytes':record.hex(),'code':'3A','keyPointer':'C18C94'},'locationTable':loc},'sources':sources,'originalWindows':windows
}
f=Path(__file__).with_name('party-invitation-confirmation-boundary-v1.json');f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()))
