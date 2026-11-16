"""Independent original-byte command registration/callback/receiver audit; no packet sending."""
from pathlib import Path
import sys,json,hashlib,struct
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace');D=R/'runtime-observations/2026-11-05-all-skills'
sys.path[:0]=[str(R/'anal/python_deps'),str(R/'anal')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32,CS_OP_MEM,CS_OP_IMM,CS_OP_REG
sha=lambda b:hashlib.sha256(b).hexdigest()
T='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';p=PE(R/'Tartaros.bin');assert sha(p.data)==T
m=Cs(CS_ARCH_X86,CS_MODE_32);m.detail=True
reg=list(m.disasm(p.read(0x493170,0x86),0x493170));last={};stores=[]
for i in reg:
 if i.mnemonic!='mov' or len(i.operands)!=2:continue
 dst,src=i.operands
 if dst.type==CS_OP_REG and src.type==CS_OP_IMM:last[m.reg_name(dst.reg)]=src.imm
 if dst.type==CS_OP_MEM and m.reg_name(dst.mem.base)=='eax' and src.type==CS_OP_REG:
  if last.get(m.reg_name(src.reg))==0x494750:stores.append((i.address,dst.mem.disp))
assert stores==[(0x4931f0,0x978)]
disp=stores[0][1];assert (disp-0x208)%16==0;command=(disp-0x208)//16;assert command==0x77
bulk=R/'anal-multi/kr-bulk-roy'/T/'functions';sources=[]
for va in [0x493170,0x494750,0x4d2e40,0x4930e0,0x48aad0,0x4957c0]:
 f=bulk/f'0x{va:x}.c';sources.append({'va':f'{va:08X}','path':str(f.relative_to(R)),'sha256':sha(f.read_bytes())})
windows=[]
for va,n,full in [(0x493170,0x86,False),(0x494750,0x30,True),(0x4d2e40,0x1a9,True),(0x4930e0,0x81,True),(0x48aad0,0x70,False),(0x4957c0,0x45,False)]:
 b=p.read(va,n);ins=list(m.disasm(b,va));assert sum(i.size for i in ins)==n,(hex(va),n,sum(i.size for i in ins))
 local=[]
 if full:
  assert ins[-1].mnemonic=='ret';starts={i.address for i in ins}
  for i in ins:
   if i.mnemonic.startswith('j') and i.operands[0].type==CS_OP_IMM:
    target=i.operands[0].imm;assert va<=target<va+n and target in starts;local.append({'branchVA':f'{i.address:08X}','targetVA':f'{target:08X}'})
 windows.append({'va':f'{va:08X}','length':n,'sha256':sha(b),'fullContinuousDecodeToRet':full,'localDirectBranchesChecked':local,'instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in ins]})
assert int.from_bytes(p.read(0xc05aec,4),'little')==0x4930e0
assert int.from_bytes(p.read(0xc05b08,4),'little')==0x48aad0
prior=D/'buff-ui-actor-map-boundary-v1.json'
out={'schema':'BUFF_SNAPSHOT_COMMAND_DISPATCH_V1','targetSha256':T,'authority':'INDEPENDENT_ORIGINAL_REGISTRATION_CALLBACK_AND_RECEIVER_ABI_NOT_OFFICIAL_SERVER_TIMING',
 'registration':{'instructionVA':'4931F0','handler':'494750','storeDisplacementHex':'978','processorSubobjectOffsetHex':'200','functionSlotOffsetHex':'8','strideHex':'10','mechanicalFormula':'(0x978 - (0x200 + 8)) / 0x10','derivedCommandHex':f'{command:04X}','rule':'493170 initializes function slots starting fullClient+208; register-value propagation above verifies EDX=494750 at exactstore, not request+1.'},
 'callbackLane':{'normalCallback':'CClient subobject+148 VT C05AEC slot0=4930E0 (original DWORDassert)','laneGate':'493105 reads callback stackarg4 [EBP+14], subtracts2; only lane2 invokes application processor. Connection argument is not used to pick opcode table.','processorIdentity':'callbackthis+B8 = fullClient+148+B8 = fullClient+200; original CClient processor VT C05B04+4=48AAD0','dispatch':'48AAD0 signextends command and reads processor+8+command*16.0077 explicitcallback494750 bypasses generic scene route.','normalPrimary':'Original4957E0 push2 lane,4957E2 push0 socketSlot,port8416 connect4957EA; auxslot2/8414 separatelyalso lane2. Thus lane2 is NOTsocket2.','scope':'Known normal Client callback/table/connect identity only; no universal claim about dynamic later overrides or all connection branches.'},
 'wrapperABI':{'function':'494750','input':'normal processor signature stackarg1 payload,stackarg2 length,stackarg3 command','forwarding':'494773 loads firststackarg payload;494776 pushes it;494777 calls4D2E40','return':'RET0C consumes original3 arguments; wrapper itself does not forwardlength/command'},
 'receiverABI':{'function':'4D2E40','input':'stackarg1 payload pointer','return':'EAX0,RET4','reads':'BYTEpayload+2 actorCount; cursor3; peractor WORDactorUID atcursor and BYTEbuffCount atcursor+2; advances3 then4 perrecord','lookup':'WORDactorUID zeroextends askey inFAB138;node+10 actor pointer. Missing actor path skips itsrecordCount*4 bytes.','perActorReplacement':'For foundactor, clears embedded actor+3F0 tree through+3F4 sentinel and resets+3F8,+400,+404,+408, then invokes recordwriter per suppliedentry. Count0 therefore clears this included actors map. Otheractors are not globally cleared.','record':'4 bytes:WORDrecordId at0,BYTEparamA at2,BYTEparamB at3','recordWriterCustomABI':'4D2FB5 ECX=zeroextendedrecordbyte3;pushECX(paramB);4D2FBA CX=recordWORD;pushEDX(paramA);4D2FBE ESI=actor;4D2FC0 call4C9840. EntryABI:ESIactor,CXrecordId,stackarg1paramA,stackarg2paramB.','bounds':'No inputlength argument/explicit packetbounds in this receiver. Shape is consumer layout evidence, not a recommendation to accept malformed input.','remainingTime':'No remaining-time DWORD or timestamp field is read by thislayout. ByteparamB must not be named duration without separatewriter semantics.'},
 'reviewBoundary':{'parentIndependentlyAuditsWriter':'4C9840 and4CA0B0 mutation semantics belong to root review, not newly asserted here.','priorClarification':'Prioractor+164 visual attachment audit was a bounded visual path only.4C9840 may also updateactor+3F0; oldvisual-only scope must not be promoted to a whole-function no-buff claim.','priorUiFile':{'name':prior.name,'sha256':sha(prior.read_bytes())},'adoption':'This supports a command0077 per-actor map replacement candidate on known normal primary stream; publication trigger/order/expiration remainsServer policy until independently established.'},
 'unknowns':['Separate incremental add/remove notification ifany; thisreceiver is per-includedactor replacement.','Precise semantics/range ofparamA/paramB pending rootwriter audit; no remaining-time contract established.','Actual officialServer publication order, buffgrant/expirygameplay and completeUIrefresh scheduling.'],
 'limits':['No packetbuilt/sent, Server/Client/Host/shared/Git edits, provider retry, targetlaunch/attachment or negative test.','Sourcebody boundaries/operands verified for listedranges only; not a formalRR full-pass claim.'],'sources':sources,'originalWindows':windows}
f=D/'buff-snapshot-command-dispatch-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()))
