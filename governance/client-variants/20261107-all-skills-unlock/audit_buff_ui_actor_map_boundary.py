"""Reuse task indexes and bounded saved/native UI->actor-map consumers; no guessed wire packet."""
from pathlib import Path
import sys,json,hashlib,struct
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace');D=R/'runtime-observations/2026-11-05-all-skills'
sys.path[:0]=[str(R/'anal/python_deps'),str(R/'anal')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
T='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';p=PE(R/'Tartaros.bin');assert sha(p.data)==T
m=Cs(CS_ARCH_X86,CS_MODE_32);bulk=R/'anal-multi/kr-bulk-roy'/T/'functions'
indexes=[]
for name in ['s00-runtime-dev/kr/tasks/T04/README.md','s00-runtime-dev/kr/tasks/T11/README.md','anal/SKILL-MATRIX-CONSUMERS.md','anal/CONTROL-AND-SKILL-SOURCE.md','anal/ACTOR-ATTACHMENT-EFFECT-PROVENANCE.md','anal/kr-phase1-20261022/SEMANTIC-FINDINGS.md']:
 f=R/name;indexes.append({'path':name,'sha256':sha(f.read_bytes())})
idxPath=R/'anal/native-index/Tartaros.bin.json';idx=json.loads(idxPath.read_text(encoding='utf8'));vts=[]
for name,address in [('.?AVCBuffListBox@FUI@@',0xc378b4),('.?AVCBuffSlot@FUI@@',0xc3eccc)]:
 t=next(t for t in idx['vtables'] if t['className']==name and t['address']==address);assert p.read(address,4*len(t['entries']))==struct.pack('<'+'I'*len(t['entries']),*t['entries']);vts.append({'className':name,'address':f'{address:08X}','entries':[f'{a:08X}' for a in t['entries']]})
sources=[]
for va in [0x68b1e0,0x4d2da0,0x4d2cc0,0x68b260,0x6be4b0,0x6be6a0,0x6be950]:
 f=bulk/f'0x{va:x}.c';sources.append({'va':f'{va:08X}','path':str(f.relative_to(R)),'sha256':sha(f.read_bytes())})
windows=[]
for va,n in [(0x68b1e0,0x71),(0x4d2da0,0x95),(0x4d2cc0,0xc5),(0x68b750,0x51)]:
 b=p.read(va,n);ins=list(m.disasm(b,va));assert sum(i.size for i in ins)==n
 windows.append({'va':f'{va:08X}','length':n,'sha256':sha(b),'instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in ins]})
full=list(m.disasm(p.read(0x68b260,0x6cc),0x68b260));assert full[-1].mnemonic=='ret';mapIns=[i for i in full if 0x68b600<=i.address<0x68b700]
out={'schema':'BUFF_UI_ACTOR_MAP_BOUNDARY_V1','targetSha256':T,'authority':'BOUNDED_UI_ACTOR_DATA_CONSUMER_ONLY_NOT_BUFF_WIRE_CONTRACT','priorIndexReview':{'files':indexes,'finding':'No already-accepted Buff add/remove/remaining opcode contract found in these task inventories/summaries. Initial phase1 report only acknowledged BuffList resource initializer, not decoded notifications. This is a scoped inventory finding, not proof no existing report elsewhere.'},'nativeIndex':{'path':str(idxPath.relative_to(R)),'sha256':sha(idxPath.read_bytes()),'rttiVtablesOriginalChecked':vts},
 'boundedConsumer':{'listResolver':'68B1E0 custom ABI ESI=CBuffListBox; readsbox+DC mode. mode2 pushesbox+E0 to4D2DA0, mode3 pushesbox+E4 to4D2CC0; other modes return0. Both helpers return inEAX; role/entity identity meaning is not newly assigned from field names.','mode2Helper':'4D2DA0 stackarg[EBP+8] loadedEAX,ESI=FAB130 ->4DFB60. If actor found returns actor+3F0, else0; RET4. Do not call its missing bulk parameter a void ABI.','mode3Helper':'4D2CC0 stackarg[EBP+8] key ->map atFAB138 via82EF00; node+10 actor pointer; accepts actor byte+4 values0,1,6,7 (compressed switch), returns actor+3F0 or0; RET4.','ordinaryMap':'68B260 non-mode1 branch calls68B1E0; reads returned map+4 sentinel and iterates nodes. Node DWORD+10 is reduced to low24bits for UI projection. This identifies a real actor-resident data consumer, not a network field.','slotProjection':'Packed value low16 ->CBuffSlot+248 (zero convertedFFFFFFFF empty), bits16..23 ->BYTE+24C; category+254=0;6BE4B0 refreshes icon. Original68B750..68B7A1 verifies raw registers and stores.','tooltip':'Hover eventCB in6BE6A0 uses slot+248 and+24C ->6BE950. That method reads staticBuffExplain table FC0C6C, finds buffID then level. This is static level explanation; no remaining-duration notification is established.'},
 'wireBoundary':{'addOpcode':None,'removeOpcode':None,'remainingTimeOpcode':None,'wireLayout':None,'laneOrSocketContract':None,'reason':'No mutation producer foractor+3F0 has been connected to an inbound dispatcher. UI eventIDsF4274/F4275 and class names are not packet opcodes.'},
 'smallNextScope':{'rootOwnsProducerSearch':True,'minimumAddress':'4D2DA0/4D2CC0 establish exact actor+3F0 endpoint; next locate a concrete insertion/removal producer for that embedded container and only then its inbound registration.','keepSeparate':'4C9840→actor+164→551CD0/551DD0 is existing visual attachment evidence, not actor+3F0 state orBuffID dispatch.'},
 'limitations':['This does not establish buff grants, expiration, replacement, remaining time units, native icon packet publication or formal full-function acceptance.','Only named task indexes, saved native identity index and selected bounded functions/rawbytes; no111k function-body rescan, provider retry or target attach/run.','No constructed packet, Server/Client/Host/shared/Git change.'],'sources':sources,'originalWindows':windows,'selectedMapInstructionsFromKnownStart':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in mapIns]}
f=D/'buff-ui-actor-map-boundary-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()))
