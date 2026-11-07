"""Bounded ASD split parser/copy/runtime-consumer evidence; no replacement timing formula."""
from pathlib import Path
import sys,json,hashlib,re,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');D=R/'runtime-observations/2026-11-05-all-skills'
sys.path[:0]=[str(R/'anal/python_deps'),str(R/'anal')]
from build_native_index import PE
from stp_resources import Archive
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
T='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';p=PE(R/'Tartaros.bin');assert sha(p.data)==T
m=Cs(CS_ARCH_X86,CS_MODE_32);bulk=R/'anal-multi/kr-bulk-roy'/T/'functions'
sources=[]
for va in [0x7ade80,0x7b1810,0x7d8d50,0x7da5a0,0x65cb20,0x7d9630,0x7d8ca0,0x7da4d0,0x7da460,0x7d9690,0x7d9d80]:
 f=bulk/f'0x{va:x}.c';sources.append({'va':f'{va:08X}','path':str(f.relative_to(R)),'sha256':sha(f.read_bytes())})
windows=[]
for va,n in [(0x7d9630,0x55),(0x7da4d0,0xcd),(0x7d9690,0xf6),(0x7d8d50,0x86),(0x7ae702,0x1d),(0x7d8ca0,0x1c)]:
 b=p.read(va,n);ins=list(m.disasm(b,va))
 windows.append({'va':f'{va:08X}','length':n,'sha256':sha(b),'decodedBytes':sum(i.size for i in ins),'instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in ins]})
# Select parser instructions by decoding from its known function start, never from a partial opcode.
parser=list(m.disasm(p.read(0x7ade80,0x910),0x7ade80))
selected=[i for i in parser if 0x7ae550<=i.address<0x7ae71f]
parserWindow={'start':'007AE550','selection':'whole instructions decoded from7ADE80 start','instructions':[{'va':f'{i.address:08X}','text':i.mnemonic+' '+i.op_str} for i in selected]}
strings=[]
for s,va in [('SpliteData',0xc4f924),('FPS',0xc4f938),('StartFrame',0xc4f93c),('EndFrame',0xc4f948),('Delay',0xc4f954)]:
 assert p.read(va,len(s)+1)==s.encode()+b'\0';strings.append({'value':s,'va':f'{va:08X}'})
assert int.from_bytes(p.read(0xc502ac,4),'little')==0x7d8ca0
assert int.from_bytes(p.read(0xc502bc,4),'little')==0x7da4d0
motion=json.loads((D/'all-role-motion-joins.json').read_text(encoding='utf8'));role=next(x for x in motion['roles'] if x['role']==1);arc={};examples=[]
for mid in [101,106]:
 row=next(x for x in role['motion_metadata'] if x['motion_id']==mid);c=row['asd_carrier']
 if c not in arc:arc[c]=Archive(R/c)
 b=arc[c].read(row['asd_member']);s=b.decode('utf-8-sig');t=E.fromstring('<R>'+re.sub(r'<\?xml[^?]*\?>','',s)+'</R>');splits=[dict(x.attrib) for x in t.findall('.//SpliteData')]
 examples.append({'role':1,'motion':mid,'carrier':c,'member':row['asd_member'],'sha256':sha(b),'splits':splits,'oldProjectionSeconds':sum((float(x['EndFrame'])+float(x.get('Delay','0')))/float(x['FPS']) for x in splits),'authority':'ARITHMETIC_REPRODUCTION_ONLY_NOT_NATIVE_DURATION_OR_CANCEL'})
out={
 'schema':'ASD_SPLIT_DURATION_SEMANTICS_BOUNDARY_V1','targetSha256':T,'authority':'BOUNDED_NATIVE_PARSER_AND_RUNTIME_FIELD_CONSUMERS_NOT_FULL_ANIMATION_CLOCK_OR_GAMEPLAY_LOCK',
 'parser':{'function':'7ADE80','strings':strings,'recordStride':20,'recordFields':{'0':'DWORDFileID','4':'floatFPS','8':'floatStartFrame','12':'floatEndFrame','16':'floatDelay'},'stackRecord':'EBP-130hex base; FPS at-12C,Start-128,End-124,Delay-120','copy':'7AE708 EAX=&record;7AE70E EDI=&vector;7AE71A->7B1810 appends five DWORDs; direct parsed floats, no FPS division or End-Start subtraction in this bounded parser path'},
 'runtimeCopy':{'constructor':'7D8D50 creates CSpliteMotion VT C5029C;header+A4 count ->motion+BC;header+A8 vector ->motion+C0 via7DA5A0/65CB20; records copied raw','fpsGetter':'VT+10=7D8CA0 returns current split row+4, index motion+110','sumGetter':'7D9630 EDX=motion, when loaded vector+114!=+118 sums count+BC entries of row+C and row+10 into motion+10C; returns ST0. No read of StartFrame or FPS here. Empty loaded vector returns ST0 zero in this bounded function.','seek':'VT+20=7DA4D0 selects split by cumulative(row+C + row+10); for advanced split reads selected row+8 StartFrame into local offset, conditionally adds it to input time before7DA460 subtracts prior split spans. StartFrame is consumed in local split seek/pose selection, not proven a gameplay cancel point.','loadCallback':'CSpliteMotion secondary VT C502EC slot0=7D9690, this adjusted by4. When adjustedthis+104 nonzero, received entry pointers append to vector; raw7D96F5 loads float[entry+4] and7D96F8 stores to splitrow+C. This can replace the field initially parsed as EndFrame. The exact source/units of entry+4 are not closed here.'},
 'oldProjectionAssessment':{'formula':'sum((XML.EndFrame+XML.Delay)/XML.FPS)','status':'UNVERIFIED_RESOURCE_ESTIMATE_NOT_VALIDATED_NATIVE_RUNTIME_FORMULA','reason':['The native sum consumer does not divide each segment by FPS. FPS is exposed separately by a current-segment virtual getter.','Native seeks use StartFrame as an offset; this does not justify changing each duration to EndFrame-StartFrame.','The runtime loading callback can overwrite the initially parsed EndFrame field; static XML alone may omit the final value.','The producer/units of loaded entry+4 and the caller clock scaling across changing FPS remain unresolved.'],'replacementFormula':None},
 'gameplayUse':{'actionLock':'NOT_SOURCE_VALIDATED: do not present this estimate as authoritative action lock duration','cancelAndCombo':'NOT_SOURCE_VALIDATED: no actor cancel/input-window consumer has been connected to these split timing fields','recommendedBoundary':'Retain old projection only as explicitly unverified metadata; use separately named Server timing policy where necessary, without claiming native timing parity or fixing by blind subtraction.'},
 'examples':examples,'notPlaybackEvidence':'7D9D80 writes XML SpliteData attributes; it is a serializer and is not used as a playback-duration proof.',
 'limits':['No broad scan, new provider invocation, Client execution/attach or patch, Server/Host/shared source edit.','No timing/runtime test or animation playback occurred.','This is not a full-function or RR acceptance claim; bounded raw windows and bulk identity are retained.'],
 'sources':sources,'originalWindows':windows,'parserSelectedInstructions':parserWindow
}
f=D/'asd-split-duration-semantics-boundary-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()));print([(x['motion'],x['oldProjectionSeconds']) for x in examples])
