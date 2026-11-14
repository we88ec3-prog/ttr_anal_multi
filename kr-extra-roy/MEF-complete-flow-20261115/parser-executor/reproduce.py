#!/usr/bin/env python3
"""Read-only verifier for the bounded parser/executor frontier evidence.

Does not launch Client/Lua, write files, connect to the network, or mutate Git.
"""
from pathlib import Path
import argparse,hashlib,json,re,struct,subprocess

def main():
 ap=argparse.ArgumentParser(description=__doc__)
 ap.add_argument('--bin',required=True,type=Path)
 ap.add_argument('--repo',type=Path,help='Optional existing checkout; verify pinned paths with git ls-tree only')
 args=ap.parse_args()
 root=Path(__file__).resolve().parent
 load=lambda name:json.loads((root/name).read_text())
 manifest=load('source-manifest.json'); ev=load('native-windows.json'); xr=load('scoped-xrefs.json');tables=load('tables.json')
 b=args.bin.read_bytes();sha=hashlib.sha256(b).hexdigest()
 assert sha==manifest['binary']['sha256']==ev['target_sha256']
 assert len(b)==manifest['binary']['size']==ev['target_size']
 pe=struct.unpack_from('<I',b,0x3c)[0]
 machine,count=struct.unpack_from('<HH',b,pe+4);optsize=struct.unpack_from('<H',b,pe+20)[0];opt=pe+24
 assert b[pe:pe+4]==b'PE\0\0' and machine==0x14c and struct.unpack_from('<H',b,opt)[0]==0x10b
 base=struct.unpack_from('<I',b,opt+28)[0];secs=[]
 for i in range(count):
  p=opt+optsize+i*40;name=b[p:p+8].rstrip(b'\0').decode();vs,rva,rs,raw=struct.unpack_from('<IIII',b,p+8)
  secs.append(dict(name=name,va=base+rva,virtual_size=vs,raw=raw,raw_size=rs))
 assert secs==ev['sections']
 def mapping(va,n=1):
  for s in secs:
   if s['va']<=va and va+n<=s['va']+s['raw_size']:return s,s['raw']+va-s['va']
  raise AssertionError(f'unmapped {va:X}')
 def u(va):return struct.unpack_from('<I',b,mapping(va,4)[1])[0]
 def cstr(va):
  p=mapping(va)[1];return b[p:b.index(0,p)].decode('ascii')
 code_count=0; instruction_count=0
 for w in ev['windows']:
  va=int(w['va'],16);end=int(w['end_exclusive'],16);sec,raw=mapping(va,end-va)
  assert raw==int(w['raw'],16) and sec['name']==w['section'] and end-va==w['length']
  payload=b[raw:raw+w['length']]
  assert payload.hex()==w['hex'] and hashlib.sha256(payload).hexdigest()==w['sha256'],w['id']
  if w['kind']=='cstring':assert payload[:-1].decode('ascii')==w['value'] and payload[-1]==0
  if w['kind']!='code':continue
  code_count+=1
  out=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16',f'--start-address={va}',f'--stop-address={end+15}',str(args.bin)],text=True)
  rows=[];cursor=va
  for line in out.splitlines():
   m=re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s)+)\s*(.*)$',line)
   if not m:continue
   pos=int(m[1],16)
   if pos>=end:break
   bb=bytes.fromhex(m[2]);asm=m[3].strip()
   assert pos==cursor and '(bad)' not in asm and not asm.startswith('.byte'),(w['id'],line)
   cursor+=len(bb);rows.append(dict(va=f'0x{pos:08X}',hex=bb.hex(),asm=asm))
  assert cursor==end and rows==w['instructions'],w['id']
  instruction_count+=len(rows)
 expected={int(x['target'],16):x for x in xr['targets']}
 actual={t:dict(literal_le32=[],raw_E8_E9_candidates=[]) for t in expected}
 for s in secs:
  if s['name'] not in ('.text','.rdata','.data'):continue
  payload=b[s['raw']:s['raw']+s['raw_size']]
  for t,a in actual.items():
   needle=struct.pack('<I',t);p=payload.find(needle)
   while p>=0:
    a['literal_le32'].append(dict(va=f"0x{s['va']+p:08X}",raw=f"0x{s['raw']+p:08X}",section=s['name']))
    p=payload.find(needle,p+1)
  if s['name']=='.text':
   for p in range(len(payload)-4):
    if payload[p] not in (0xe8,0xe9):continue
    dest=(s['va']+p+5+struct.unpack_from('<i',payload,p+1)[0])&0xffffffff
    if dest in actual:actual[dest]['raw_E8_E9_candidates'].append(dict(va=f"0x{s['va']+p:08X}",raw=f"0x{s['raw']+p:08X}",opcode=f'{payload[p]:02x}',hex=payload[p:p+5].hex()))
 for t,e in expected.items():
  assert actual[t]['literal_le32']==e['literal_le32'],hex(t)
  assert actual[t]['raw_E8_E9_candidates']==e['raw_E8_E9_candidates'],hex(t)
 for row in tables['registration_rows']+tables['existing_stdlibs']:
  slot=int(row['slot'],16)
  assert u(slot)==int(row['name_pointer'],16) and cstr(u(slot))==row['name'] and u(slot+4)==int(row['callback'],16)
 for row in tables['metamethod_names']:
  assert cstr(u(int(row['table_slot'],16)))==row['name']
  assert int(row['global_state_offset'],16)==0xbc+4*row['index']
 for row in tables['gsub_replacement_switch']:
  assert u(0x7048b8+4*(row['lua_type']-3))==int(row['target'],16)
 for row in tables['vm_execute_opcode_targets']:
  assert u(int(row['slot'],16))==int(row['target'],16)
 git_count=0;local_count=0
 for source in manifest['sources']:
  if args.repo:
   parts=subprocess.check_output(['git','ls-tree',source['commit'],'--',source['path']],cwd=args.repo,text=True).split()
   assert parts and parts[2]==source['git_blob'],source['path'];git_count+=1
  if 'local_copy' in source and (root/source['local_copy']).exists():
   payload=(root/source['local_copy']).read_bytes()
   assert len(payload)==source['size'] and hashlib.sha256(payload).hexdigest()==source['sha256']
   assert hashlib.sha1(f'blob {len(payload)}\0'.encode()+payload).hexdigest()==source['git_blob']
   local_count+=1
 deliverable_count=0
 if (root/'deliverables-manifest.json').exists():
  for item in load('deliverables-manifest.json')['files']:
   payload=(root/item['path']).read_bytes()
   assert hashlib.sha256(payload).hexdigest()==item['sha256'] and len(payload)==item['size'],item['path']
   deliverable_count+=1
 print(json.dumps(dict(status='PASS',read_only=True,binary_sha256=sha,binary_size=len(b),windows=len(ev['windows']),code_windows=code_count,instructions=instruction_count,scoped_targets=len(expected),parser_literal_counts=[len(actual[t]['literal_le32']) for t in [0x70e420,0x70d680,0x6f70e0]],execution_direct_counts=[len(actual[t]['raw_E8_E9_candidates']) for t in [0x6fe550,0x6fe1c0]],execution_literal_counts=[len(actual[t]['literal_le32']) for t in [0x6fe550,0x6fe1c0]],git_metadata_sources_verified=git_count,optional_local_navigation_sources_verified=local_count,deliverables_verified=deliverable_count),ensure_ascii=False,indent=2))

if __name__=='__main__':main()
