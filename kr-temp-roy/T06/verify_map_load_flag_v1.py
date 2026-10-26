import pathlib,json,hashlib,struct,sys,bisect,datetime
out=pathlib.Path(__file__).resolve().parent;root=out.parents[1];ev=out/'evidence';sha='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';bulk=root/'kr-bulk-roy'/sha;sys.path.insert(0,str(root.parent/'anal/python_deps'));import capstone
raw=(root.parent/'Tartaros.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()==sha;pe=struct.unpack_from('<I',raw,60)[0];n=struct.unpack_from('<H',raw,pe+6)[0];sz=struct.unpack_from('<H',raw,pe+20)[0];secs=[struct.unpack_from('<IIII',raw,pe+24+sz+i*40+8) for i in range(n)]
def off(va):return next(p+va-0x400000-v for z,v,s,p in secs if v<=va-0x400000<v+s)
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);calls=[]
for start,end,callsite,flag in [(0x4df785,0x4df78c,0x4df787,1),(0x563d3f,0x563d4a,0x563d45,0),(0x56435a,0x564361,0x56435c,0)]:
 b=raw[off(start):off(end)];ins=list(md.disasm(b,start));assert ins[0].mnemonic=='push' and int(ins[0].op_str,0)==flag;call=next(x for x in ins if x.address==callsite);assert call.mnemonic=='call' and call.op_str=='0x7c1e00';calls.append({'range':[hex(start),hex(end)],'literal_argument':flag,'instructions':[{'va':hex(x.address),'bytes':x.bytes.hex(),'asm':x.mnemonic+' '+x.op_str} for x in ins]})
strings=[]
for address in [0xc4fd34,0xc4fd5c,0xc4fd7c,0xc4fd9c,0xc4fdb0]:
 p=off(address);end=raw.index(b'\0',p);b=raw[p:end];strings.append({'va':hex(address),'file_offset':p,'raw_hex':b.hex(),'text_euc_kr':b.decode('euc-kr')})
m=json.loads((bulk/'inventory-manifest.json').read_text(encoding='utf-8'));ip=bulk/m['path'];assert hashlib.sha256(ip.read_bytes()).hexdigest()==m['sha256'];starts=sorted({int(x['address'],16) for x in json.loads(ip.read_text(encoding='utf-8'))['normalized_result'] if x['address'].startswith('0x')});end=starts[bisect.bisect_right(starts,0x7c1e00)];ins=list(md.disasm(raw[off(0x7c1e00):off(end)],0x7c1e00));selected=[]
for i,x in enumerate(ins):
 if any(a in x.op_str for a in ['0xc4fd7c','0xc4fd9c','0xc4fdb0']) or x.mnemonic in ['cmp','test'] or (x.mnemonic=='call' and x.op_str.startswith('dword ptr')):selected.extend(ins[max(0,i-1):min(len(ins),i+3)])
 if 0x7c1fd0<=x.address<0x7c2066 or (x.mnemonic=='xor' and x.op_str=='ebx, ebx'):selected.append(x)
dedup={x.address:x for x in selected};idx=None
with (bulk/'index.jsonl').open(encoding='utf-8') as f:
 for line in f:
  try:r=json.loads(line)
  except json.JSONDecodeError:continue
  if r.get('address')=='0x7c1e00' and r.get('status')=='ok':idx=r
assert idx;bp=bulk/idx['batch_path'];assert hashlib.sha256(bp.read_bytes()).hexdigest()==idx['batch_sha256']
v={'status':'待整合','at_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'source_sha256':sha,'module':'Tartaros.bin','address_range':{'callee_search':[hex(0x7c1e00),hex(end)],'callsites':[x['range'] for x in calls]},'tool_version':'REA6.5.0/Ghidra12.1.4 bulk pseudocode; Capstone'+capstone.__version__+' independent selected instruction checks','evidence':{'batch_path':bp.relative_to(root).as_posix(),'batch_sha256':idx['batch_sha256'],'procedure_identity':idx['procedure'],'inventory_evidence_sha256':m['sha256']},'observed':{'caller_literal_arguments':calls,'raw_target_strings':strings,'callee_selected_instructions':[{'va':hex(x.address),'bytes':x.bytes.hex(),'asm':x.mnemonic+' '+x.op_str} for x in sorted(dedup.values(),key=lambda x:x.address)]},'inference_pending':'Bind literal0/1 to the same-filename branch; do not name it a town/mission/party type.','conditions':['Exact original target SHA; primary Ghidra pseudocode and canonical entry checked before independent byte verification.'],'limits':['Next provider entry is a search boundary, not a complete-body proof.','Indirect virtual loader semantics and complete resource lifecycle remain unreviewed.','No normal TownMap binding, spawn or playability acceptance.']}
(ev/'map-load-flag-byte-review-v1.json').write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
with (out/'findings.jsonl').open('a',encoding='utf-8') as f:f.write(json.dumps(v,ensure_ascii=False)+'\n')
print(json.dumps({'strings':strings,'selected_instructions':[{'va':hex(x.address),'asm':x.mnemonic+' '+x.op_str} for x in sorted(dedup.values(),key=lambda x:x.address)]},ensure_ascii=True))
