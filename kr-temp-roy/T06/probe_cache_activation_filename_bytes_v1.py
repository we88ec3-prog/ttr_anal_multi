import pathlib,json,hashlib,struct,sys,datetime
H=pathlib.Path(__file__).resolve().parent;A=H.parents[1];R=A.parent;E=H/'evidence';sys.path.insert(0,str(R/'anal/python_deps'));import capstone
raw=(R/'Tartaros.bin').read_bytes();digest=hashlib.sha256(raw).hexdigest();assert digest=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91';p=struct.unpack_from('<I',raw,60)[0];n=struct.unpack_from('<H',raw,p+6)[0];z=struct.unpack_from('<H',raw,p+20)[0];sections=[struct.unpack_from('<IIII',raw,p+24+z+40*i+8) for i in range(n)];off=lambda va:next(o+va-0x400000-r for vs,r,s,o in sections if r<=va-0x400000<r+s)
md=capstone.Cs(capstone.CS_ARCH_X86,capstone.CS_MODE_32);md.detail=True;start,end=0x7f5540,0x7f5901;ins=list(md.disasm(raw[off(start):off(end)],start));assert sum(x.size for x in ins)==end-start;strings=[];selected={}
for i,x in enumerate(ins):
 if x.mnemonic=='call' and x.op_str in ['0x401fc0','0x716740']:
  for y in ins[max(0,i-12):min(len(ins),i+5)]:selected[y.address]=y
 for op in x.operands:
  if op.type!=capstone.x86.X86_OP_IMM or not 0xbf0000<=op.imm<0x1000000:continue
  try:
   at=off(op.imm);b=raw[at:raw.index(b'\0',at,at+120)]
   if not b or not all(0x20<=v<0x7f for v in b):continue
   strings.append({'instruction_va':hex(x.address),'literal_va':hex(op.imm),'raw_hex':b.hex(),'ascii':b.decode('ascii')})
  except (StopIteration,ValueError):continue
v={'status':'待整合','at_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),'source_sha256':digest,'module':'Tartaros.bin','address_range':[hex(start),hex(end)],'tool_version':'REA6.5/Ghidra12.1.4 activation pseudocode primary; Capstone'+capstone.__version__+' independent early-path argument verification','observed':{'literal_immediates':strings,'selected_instructions':[{'va':hex(x.address),'bytes':x.bytes.hex(),'asm':x.mnemonic+' '+x.op_str} for x in sorted(selected.values(),key=lambda x:x.address)]},'conditions':['Exact original SHA, start from registered canonical entry; bounded early path only.'],'limitations':['Byte decoding completeness of this interval is not full function/CFG acceptance.','Raw string argument does not prove successful archive lookup/load or runtime reachability.']}
p=E/'field-cache-activation-filename-byte-review-v1.json';p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
with (H/'findings.jsonl').open('a',encoding='utf-8') as f:f.write(json.dumps(v,ensure_ascii=False)+'\n')
print(json.dumps(v['observed']))
