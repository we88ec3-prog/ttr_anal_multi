"""New duration evidence only: loaded entry producer and callback transport, not old parser."""
from pathlib import Path
import sys,json,hashlib
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');D=R/'runtime-observations/2026-11-05-all-skills'
sys.path[:0]=[str(R/'anal/python_deps'),str(R/'anal')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
T='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';p=PE(R/'Tartaros.bin');assert sha(p.data)==T
m=Cs(CS_ARCH_X86,CS_MODE_32);bulk=R/'anal-multi/kr-bulk-roy'/T/'functions'
sources=[]
for va in [0x7b5980,0x7db4a0,0x7c6b70,0x7c6390,0x7c5f40,0x7b6010,0x7b6330,0x7b6e80]:
 f=bulk/f'0x{va:x}.c';sources.append({'va':f'{va:08X}','path':str(f.relative_to(R)),'sha256':sha(f.read_bytes())})
windows=[]
for va,n in [(0x7db4a0,0x73),(0x7c6390,0x9a),(0x7b5bae,0x43),(0x7b5c62,0x20),(0x7b60ae,0x39),(0x7b6500,0x18)]:
 b=p.read(va,n);ins=list(m.disasm(b,va));assert sum(i.size for i in ins)==n,(hex(va),n,sum(i.size for i in ins))
 windows.append({'va':f'{va:08X}','length':n,'sha256':sha(b),'instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in ins]})
# Fallback selected instructions are decoded from the real function start.
fall=list(m.disasm(p.read(0x7c5f40,0x300),0x7c5f40));selected=[i for i in fall if i.address<0x7c6070]
prior=D/'asd-split-duration-semantics-boundary-v1.json'
out={
 'schema':'LOADED_ANIMATION_SPAN_PRODUCER_V1','targetSha256':T,'authority':'BOUNDED_CUSTOM_ABI_AND_SOURCE_RANGE_PROJECTION_NOT_FULL_CLOCK_SECONDS_OR_RECOVERY_WINDOW',
 'priorBoundary':{'file':prior.name,'sha256':sha(prior.read_bytes()),'reuse':'Reuse existing7D9690 adjusted-this callback and splitrow+C replacement. Do not rescan parser or use7D9D80 serializer.'},
 'newProducer':{'allocation':'7B5BAE..7B5BDF allocates 0x24 bytes (36 bytes) for loaded entry, zeroes+0/+4, initializes critical section+8 and refcount+20','call':'7B5BE3 EAX=loaded source object (EDI), ESI=entry;7B5BE5 calls7DB4A0','customABI':'7DB4A0 input EAX=source object, ESI=entry; no stack arguments; writes entry+0 object and entry+4 float; RET','lookup':'7DB4A6 pushes typeID A1210000 then EAX object;7DB4AE calls7C6B70. This recursively checks object components type-info+4 and children; concrete class name for this typeID is not newly proven.','primary':'If component found,7DB4BF calls7C6390(component); integer EAX result is FILD converted and written as float entry+4 at7DB4CD. No multiplication by seconds factor here.','fallback':'If entry+4==0,7DB4DE..7DB4F3 call7C5F40(object,&two-int-range initialized0), compute abs(rangeEnd-rangeStart) as signed integer, FILD ->entry+4. Exact all-type fallback range behavior remains partial.'},
 'rangeProjection':{'function':'7C6390','inputABI':'stackarg object/component pointer atEBP+8','walk':'component+98/+9C vector; each element has+3C subtrack count;7C63C7 calls7800E0 with EAX=element and EDI=subtrack index, then virtual+1C gets a range-like pair through output buffer; returned EAX points to pair','accumulate':'minimum first integer maintained inEBX; maximum second integer maintained EBP-C initialized0','return':'7C6411..7C6423 signed integer maximum second integer /160, truncated toward0. Minimum is not subtracted in this primary return.','units':'Exact source-derived unit relationship: entry+4 = float(trunc(maximum returned range-end integer /160)) on primary path. A tick/frame conversion is plausible, but neither seconds nor a complete FPS timebase has been established here.','fallbackEvidence':'7C5F40 observed type-specific branches include returned rangeEnd/160, and another branch compares object+9C float*30. This supports preserving unit distinctions; it does not license a universal seconds formula.'},
 'transportToPriorCallback':{'return':'7B5C62 returns loaded entry inEAX','queue':'7B60AE calls7B5980(request inECX,manager stackarg),7B60BE stores request atlocal-18,7B60C1 stores returned entry atlocal-14;7B60DB appends the8B pair through7B6E80','dispatch':'7B6330 drains result pairs and resolves registered receiver;7B6512 pushes loaded entry,7B6513 pushes request,7B6514 ECX=receiver,7B6516 calls receiver virtual0','end':'For the already established CSpliteMotion secondary receiver,7D9690 appends loaded entry and copies float entry+4 to splitrow+C. No new parser reconstruction required.'},
 'timingImpact':{'improvement':'The value replacing staticXML EndFrame is now traced to loaded animation data range, not guessed from spelling or XML arithmetic. A future offline resource decoder could compare exact loaded range projection to staticXML EndFrame.','stillUnresolved':['Meaning and serialized source of typeID A1210000 component and the concrete virtual+1C range units.','Complete fallback7C5F40 per-type range semantics.','How upstream animation clock consumes current splitFPS7D8CA0 and converts accumulated spans into real seconds, including speed changes.','Actor input cancellation, action recovery, combo queue consumption and their relation to animation completion.'],'useForActionLockOrCombo':'NOT_YET_SOURCE_VALIDATED','replacementDurationSeconds':None},
 'limits':['Read-only original binary/source, no new provider/runtime or game execution/attachment.','No Client/Server/Host/shared changes; only new metadata and reproduction script.','Custom ABI and exact integer operations recorded independently of bulk prototypes, which misdeclare7B5980/7DB4A0 returns/inputs.','No claim that maxEnd/160 itself is seconds, and no blindEnd-Start formula introduced.'],
 'sources':sources,'originalWindows':windows,'fallbackSelectedInstructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in selected]
}
f=D/'loaded-animation-span-producer-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()))
