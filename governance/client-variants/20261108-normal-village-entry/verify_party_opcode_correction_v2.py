"""Read-only original-byte verification; writes only this evidence directory metadata."""
from pathlib import Path
import sys, json, hashlib, re
ROOT=Path(sys.argv[1]).resolve() if len(sys.argv)>1 else Path(__file__).resolve().parents[3]
sys.path[:0]=[str(ROOT/'anal/python_deps'),str(ROOT/'anal')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32,CS_OP_IMM,CS_OP_MEM
sha=lambda data:hashlib.sha256(data).hexdigest()
p=PE(ROOT/'Tartaros.bin')
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert sha(p.data)==TARGET
md=Cs(CS_ARCH_X86,CS_MODE_32);md.detail=True
bulk=ROOT/'anal-multi/kr-bulk-roy'/TARGET/'functions'
expected={0x88:0x53a440,0x89:0x53a760,0x8a:0x53a920,0x8b:0x53a8c0,0x8c:0x53a940,0x8d:0x539eb0,0x8e:0x53a050,0x8f:0x53a0a0,0x90:0x53a2d0}
registration=list(md.disasm(p.read(0x539df0,0xb1),0x539df0))
assert sum(i.size for i in registration)==0xb1 and registration[-1].mnemonic=='ret'
rows=[]
for i in registration:
 if i.mnemonic!='mov' or len(i.operands)!=2:continue
 dst,src=i.operands
 if dst.type!=CS_OP_MEM or src.type!=CS_OP_IMM or md.reg_name(dst.mem.base)!='ecx':continue
 disp=dst.mem.disp
 if src.imm not in expected.values():continue
 assert disp>=4 and (disp-4)%8==0
 opcode=(disp-4)//8
 assert expected[opcode]==src.imm
 f=bulk/f'0x{src.imm:x}.c'
 src_info={'source':str(f.relative_to(ROOT)),'sourceExists':f.exists()}
 if f.exists():
  data=f.read_bytes();text=data.decode('utf-8')
  src_info.update(sha256=sha(data),literalCalls53B680=len(re.findall(r'FUN_0053b680\s*\(',text,re.I)))
 else:
  assert src.imm==0x53a940
  src_info.update(note='No saved bulk function; independently bounded raw handler53A940..53A956.',literalCalls53B680='NOT_APPLICABLE_NO_PSEUDOCODE')
 rows.append({'opcode':f'{opcode:04X}','registrationInstructionVA':hex(i.address),'instruction':i.mnemonic+' '+i.op_str,'instructionBytes':i.bytes.hex(),'tableDisplacement':hex(disp),'formula':f'({disp}-4)//8={opcode}','handler':hex(src.imm),'consumerSource':src_info})
assert {int(x['opcode'],16) for x in rows}==set(expected)
by={x['opcode']:x for x in rows}
assert by['0088']['consumerSource']['literalCalls53B680']==0
assert by['0089']['consumerSource']['literalCalls53B680']==1
# Source dispatcher key index is material, not an assumed request/reply adjacency.
dispatch=list(md.disasm(p.read(0x4fda30,0x15),0x4fda30))
assert any(i.address==0x4fda3e and i.mnemonic=='mov' and i.operands[1].type==CS_OP_MEM and i.operands[1].mem.scale==8 and i.operands[1].mem.disp==4 for i in dispatch)
# Correct no-pseudocode clear-listing handler, full straight-line body to RET.
clear=list(md.disasm(p.read(0x53a940,0x16),0x53a940))
assert sum(i.size for i in clear)==0x16 and clear[-1].mnemonic=='ret'
assert not any(i.mnemonic=='call' for i in clear)
assert any(i.address==0x53a94a and i.mnemonic=='mov' and i.operands[0].type==CS_OP_MEM and i.operands[0].mem.disp==0x24 and i.operands[1].type==CS_OP_IMM and i.operands[1].imm==0 for i in clear)
# Exact 005F request: source buffer EBP-34, fields2C/2D are EBP-8/-7.
mod=list(md.disasm(p.read(0x53b990,0x80),0x53b990));ins={i.address:i for i in mod}
for a,op in [(0x53b9c4,'eax, 0x5f'),(0x53b9c9,'0x15'),(0x53b9cc,'word ptr [ebp - 0x34], ax'),(0x53b9d5,'dl, byte ptr [ebp + 8]'),(0x53b9d8,'al, byte ptr [ebp + 0xc]'),(0x53b9e5,'byte ptr [ebp - 8], dl'),(0x53b9e8,'byte ptr [ebp - 7], al'),(0x53b9f8,'0x2e'),(0x53b9fa,'eax, [ebp - 0x34]')]:assert ins[a].op_str==op,(hex(a),ins[a].op_str)
window=lambda a,n:{'va':hex(a),'bytes':n,'sha256':sha(p.read(a,n))}
result={'schema':'party-opcode-correction-v2','targetSha256':TARGET,'status':'EXACT_REGISTRATION_AND_SELECTED_TYPED_FIELDS_NOT_FULL_FUNCTION_PASS','cause':'Earlier assistant manually miscomputed adjacent registration displacements.008B is modify-name/capacity,008C is clear-listing.0088 was wrongly described as always clearing party.','preservation':'Prior metadata files retained unchanged; apply this versioned correction when consuming them.','registrationRows':sorted(rows,key=lambda x:x['opcode']),'confirmedSemantics':{'0088':'53A440 status/message handler; source has ZERO literal53B680 calls. Not a generic successful-create reply.','0089':'53A760 invokes53B680 once at normal tail; status1 adds kick popup.','008A':'53A920 sets currentParty+24 from packetWORD+2.','008B':'53A8C0 reads UTF16name+2 andcapacityBYTE+2C, updatescurrentparty; minimumread45bytes. NEVERsend2-byteclear tothishandler.','008C':'53A940 fullraw22B handler clearscurrentParty+24=0; no packetfieldreads. Two-bytepublicationcandidate.','008D':'539EB0 directorysnapshot54Brows.','008E':'53A050 partyrecord,partykeyWORD+2F.','008F':'53A0A0 memberrows9B.','0090':'53A2D0 invitationpath,notpartofnormalminimalcreation.'},'modifyRequest005F':{'builder':'53B990','totalBytes':46,'slot':0,'nameSource':'ESI UTF16pointer,wcscpy_s capacity21WCHAR','bufferBase':'EBP-34','fields':{'0':'WORD005F','2':'21WCHARnamearea42bytesincludingNULcapacity','0x2C':'BYTEstackargument1 atEBP+8 (capacity)','0x2D':'BYTEstackargument2 atEBP+C (flag;semanticsnotinferred)'},'trailingNamePadding':'not explicitly initialized;do not demandzeroafterNUL','responseBoundary':'008B typedname/capacityconsumer,officialrequest-responseorderingnotcaptured'},'windows':[window(0x539df0,0xb1),window(0x4fda30,0x15),window(0x53a940,0x16),window(0x53b990,0x80)],'clearHandlerInstructions':[{'va':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str} for i in clear],'modifyRequestInstructions':[{'va':hex(i.address),'mnemonic':i.mnemonic,'operands':i.op_str} for i in mod]}
# Exact old file identities retained as superseded findings, not original-byte evidence.
old={}
for name in ['party-publication-candidates.json','party-ui-consumers.json','directory-list-and-leave.json']:
 f=Path(__file__).with_name(name)
 data=f.read_bytes()
 if b'008B' in data or b'8B' in data or b'8Bclear' in data:old[f.name]=sha(data)
result['supersededFindingsFileHashes']=old
out=Path(__file__).with_name('party-opcode-correction-v2.json')
out.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'checks':'passed','registrationOpcodes':list(by),'output':str(out),'sha256':sha(out.read_bytes())}))
