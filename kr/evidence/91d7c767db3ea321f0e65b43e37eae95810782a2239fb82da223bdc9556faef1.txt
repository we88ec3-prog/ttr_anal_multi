import pathlib,json,hashlib,struct,sys
OUT=pathlib.Path(__file__).resolve().parent;ROOT=OUT.parents[1];EV=OUT/'evidence'
sys.path.insert(0,str(ROOT.parent/'anal/python_deps'));import capstone
raw=(ROOT.parent/'Tartaros.bin').read_bytes();digest=hashlib.sha256(raw).hexdigest();assert digest=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe=struct.unpack_from('<I',raw,60)[0];n=struct.unpack_from('<H',raw,pe+6)[0];sz=struct.unpack_from('<H',raw,pe+20)[0];sec=[struct.unpack_from('<IIII',raw,pe+24+sz+i*40+8) for i in range(n)]
def off(va):return next(p+va-0x400000-v for z,v,s,p in sec if v<=va-0x400000<v+s)
status=json.loads((EV/'loader-session-status.json').read_text(encoding='utf-8'));done={r['path']:r for r in status['completed']};md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);rows=[]
for p in sorted(EV.glob('loader-4f*.json')):
    e=json.loads(p.read_text(encoding='utf-8'));record=done['evidence/'+p.name];assert not record['is_error'] and hashlib.sha256(p.read_bytes()).hexdigest()==record['sha256'];assert e['subject']['digest']['sha256']==digest
    nr=e['normalized_result'];addrs=set();ranges=[];selected=[]
    for r in nr['procedure']['body']['ranges']:
        start,end=int(r['start'],16),int(r['end'],16);b=raw[off(start):off(end)+1];ins=list(md.disasm(b,start));assert sum(i.size for i in ins)==len(b);addrs.update(i.address for i in ins);ranges.append({**r,'file_offset_start':off(start),'sha256':hashlib.sha256(b).hexdigest()})
        selected += [{'va':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str} for i in ins if i.mnemonic=='mov' and i.op_str in ('ecx, 0xfb7490','ecx, 0xfb74a0')]
    assert addrs=={int(a.split(':',1)[0],16) for a in nr['assembly']}
    rows.append({'path':p.name,'sha256':record['sha256'],'evidence_id':e['evidence_id'],'procedure':nr['procedure']['address'],'provider':e['provider'],'analysis_profile_digest':e['analysis_profile']['digest'],'body':nr['procedure']['body'],'range_byte_hashes':ranges,'all_instruction_addresses_equal':True,'referenced_strings':nr['referenced_strings'],'selected_instructions':selected,'limitations':e['limitations']})
result={'status':'待整合','source_sha256':digest,'module':'Tartaros.bin','tool_version':{'python':sys.version,'capstone':capstone.__version__,'script_version':1},'records':rows,'limits':['Raw-byte/entry/body and selected pointer instruction binding only','Sound routes recorded only by table string for exclusion; no sound analysis','No whole-client absence claim, no gameplay or ABI acceptance from recovered pseudocode']}
(EV/'loader-byte-verification.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({'records':len(rows),'instruction_address_sets_match':True}))
