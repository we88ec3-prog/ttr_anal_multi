"""Independent byte binding for existing T06 Ghidra listings, not semantic completion."""
import pathlib,json,hashlib,struct,sys
OUT=pathlib.Path(__file__).resolve().parent;ROOT=OUT.parents[1];EV=OUT/'evidence'
sys.path.insert(0,str(ROOT.parent/'anal/python_deps'))
import capstone
raw=(ROOT.parent/'Tartaros.bin').read_bytes();sha=hashlib.sha256(raw).hexdigest()
assert sha=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe=struct.unpack_from('<I',raw,0x3c)[0];nsec=struct.unpack_from('<H',raw,pe+6)[0];opt=struct.unpack_from('<H',raw,pe+20)[0]
base=struct.unpack_from('<I',raw,pe+24+28)[0];table=pe+24+opt
sections=[struct.unpack_from('<IIII',raw,table+i*40+8) for i in range(nsec)]
def off(va):
    rva=va-base
    matches=[ptr+rva-vaddr for size,vaddr,rsz,ptr in sections if vaddr<=rva<vaddr+rsz]
    assert len(matches)==1;return matches[0]
c=json.loads((ROOT/'shared/catalog.json').read_text(encoding='utf-8'))
ids=['ed2173b1df5e91bf59cbfc1dc27e1573cef4d4857b751bfe26439cc9c56719b4','af75e8a81e45941f4663199d2cdfe712e5dfcde53593763e1d7c41bdfa3de745','fe1ba4d04bb33dff43a045c3eaa6e32cf60ae4aca0867623b48768dc8028bf2a']
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);records=[]
for eid in ids:
    a=next(a for a in c['artifacts'] if a['id']==eid);data=(ROOT/a['path']).read_bytes();assert hashlib.sha256(data).hexdigest()==eid
    outer=json.loads(data);e=json.loads(outer['content'][0]['text']);nr=e['normalized_result'];assert e['subject']['digest']['sha256']==sha
    decoded={};ranges=[]
    for r in nr['procedure']['body']['ranges']:
        start,end=int(r['start'],16),int(r['end'],16);blob=raw[off(start):off(end)+1]
        instructions=list(md.disasm(blob,start));assert sum(i.size for i in instructions)==len(blob)
        decoded.update({i.address:i for i in instructions});ranges.append({**r,'file_offset_start':off(start),'sha256':hashlib.sha256(blob).hexdigest()})
    listing_addrs={int(line.split(':',1)[0],16) for line in nr['assembly']}
    assert listing_addrs==set(decoded), (nr['procedure']['address'],len(listing_addrs),len(decoded))
    interesting=[{'va':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str} for i in decoded.values() if (i.mnemonic=='call' and i.op_str in ('0x4f7df0','0x4df1a0','0x7c1e00')) or (i.mnemonic=='mov' and i.op_str in ('ecx, 0xfb74b0','ecx, 0xfb74c0','ecx, 0xfb74d0'))]
    records.append({'artifact_id':eid,'evidence_id':e['evidence_id'],'provider':e['provider'],'procedure':nr['procedure']['address'],'ranges':ranges,'all_listing_instruction_addresses_match_independent_decode':True,'selected_instructions':interesting,'pseudocode':nr['pseudocode'],'limits':e['limitations']})
report={'source_sha256':sha,'module':'Tartaros.bin','tool':{'capstone_version':capstone.__version__,'python':sys.version,'script_sha256':hashlib.sha256(pathlib.Path(__file__).read_bytes()).hexdigest()},'status':'待整合','records':records,'limits':['Address-set and raw-byte binding only; not all instruction operand semantics compared','Decompiler signature and float typing are not source types','Ghidra no-return and indirect-call limitations retained','Static data-flow does not establish town mapping, scene readiness, instance policy or playable switching']}
(EV/'map-byte-verification.json').write_text(json.dumps(report,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'verified_procedures':[r['procedure'] for r in records]}))
