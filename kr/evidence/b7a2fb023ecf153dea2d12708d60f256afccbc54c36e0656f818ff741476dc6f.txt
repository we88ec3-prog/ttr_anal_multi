import pathlib,json,struct,hashlib,sys
OUT=pathlib.Path(__file__).resolve().parent;ROOT=OUT.parents[1];EV=OUT/'evidence'
sys.path.insert(0,str(ROOT.parent/'anal/python_deps'));import capstone
raw=(ROOT.parent/'Tartaros.bin').read_bytes();digest=hashlib.sha256(raw).hexdigest();assert digest=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe=struct.unpack_from('<I',raw,60)[0];count=struct.unpack_from('<H',raw,pe+6)[0];sz=struct.unpack_from('<H',raw,pe+20)[0];sections=[struct.unpack_from('<IIII',raw,pe+24+sz+i*40+8) for i in range(count)]
def off(va):return next(p+va-0x400000-v for z,v,s,p in sections if v<=va-0x400000<v+s)
expected={0x4df538:('mov','esi, dword ptr [ebp + 0xc]'),0x4df53e:('cmp','dword ptr [eax + 0x48], esi'),0x4df54e:('mov','dword ptr [eax + 0x48], esi'),0x4df58a:('mov','dword ptr [ebp - 0x10], esi'),0x4df627:('mov','dword ptr [ebp - 0x14], esi'),0x4f7e38:('mov','ecx, dword ptr [edx]'),0x4f7e40:('cmp','dword ptr [eax + 0xc], ecx')}
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);rows=[]
for va,(op,args) in expected.items():
    i=next(md.disasm(raw[off(va):off(va)+15],va,count=1));assert (i.mnemonic,i.op_str)==(op,args)
    rows.append({'va':hex(va),'file_offset':off(va),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str})
native=json.loads((EV/'native-4df510.json').read_text(encoding='utf-8'));lookup=json.loads((EV/'native-4f7df0.json').read_text(encoding='utf-8'))
for e in (native,lookup):assert e['subject']['digest']['sha256']==digest
result={'status':'待整合','source_sha256':digest,'module':'Tartaros.bin','tool_version':{'python':sys.version,'capstone':capstone.__version__,'script_version':1},'native_evidence_ids':[native['evidence_id'],lookup['evidence_id']],'observed_instructions':rows,'observed':'Selector argument bits loaded fromstackDWORD, compared/stored asDWORD, passed as32-bit tree key; recovered float prototype is not serialization evidence','inference':'Compatibility code should preserve numeric Map ID bits for this selector path rather than convert toIEEE754 float bits','examples':[{'map_id':i,'integer_dword_le_hex':struct.pack('<I',i).hex(),'ieee754_float_le_hex_for_comparison_only':struct.pack('<f',float(i)).hex(),'destination_status':'known MapList row; Town1/2 association remains candidate'} for i in (182,183)],'limits':['No full original C++ signature recovery','Not all caller argument construction covered','Examples are scalar encoding comparisons, not emitted packets','No official Town/Map association, spawn or playable flow acceptance']}
(EV/'map-selector-scalar-review.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({'selected_instructions_verified':len(rows),'map_examples':result['examples']}))
