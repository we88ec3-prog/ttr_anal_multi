#!/usr/bin/env python3
"""Read-only original-byte and bounded 005F cancellation evidence verifier."""
from pathlib import Path
import argparse,hashlib,json,re,struct,subprocess

def main():
 ap=argparse.ArgumentParser(description=__doc__)
 ap.add_argument('--bin',required=True,type=Path)
 ap.add_argument('--repo',type=Path,help='Optional existing object metadata; git ls-tree only')
 args=ap.parse_args();root=Path(__file__).resolve().parent
 load=lambda n:json.loads((root/n).read_text())
 manifest=load('source-manifest.json');ev=load('native-windows.json');calls=load('bounded-call-sites.json');tab=load('tables.json')
 b=args.bin.read_bytes();sha=hashlib.sha256(b).hexdigest()
 assert sha==manifest['binary']['sha256']==ev['target_sha256'] and len(b)==ev['target_size']
 pe=struct.unpack_from('<I',b,0x3c)[0];machine,n=struct.unpack_from('<HH',b,pe+4)
 oz=struct.unpack_from('<H',b,pe+20)[0];opt=pe+24;base=struct.unpack_from('<I',b,opt+28)[0]
 assert b[pe:pe+4]==b'PE\0\0' and machine==0x14c and struct.unpack_from('<H',b,opt)[0]==0x10b
 secs=[]
 for i in range(n):
  p=opt+oz+i*40;name=b[p:p+8].rstrip(b'\0').decode();vs,rva,rs,raw=struct.unpack_from('<IIII',b,p+8)
  secs.append(dict(name=name,va=base+rva,virtual_size=vs,raw=raw,raw_size=rs))
 assert secs==ev['sections']
 def mapping(va,n=1):
  for s in secs:
   if s['va']<=va and va+n<=s['va']+s['raw_size']:return s,s['raw']+va-s['va']
  raise AssertionError(f'unmapped {va:X}')
 def take(va,n):
  _,p=mapping(va,n);return b[p:p+n]
 def u(va):return struct.unpack('<I',take(va,4))[0]
 def cstr(va):
  _,p=mapping(va);return b[p:b.index(0,p)].decode('ascii')
 sets={x['window_id']:x for x in calls['windows']};code_count=0;ni=0;all_direct=[]
 for w in ev['windows']:
  va=int(w['va'],16);end=int(w['end_exclusive'],16);sec,raw=mapping(va,end-va);payload=b[raw:raw+w['length']]
  assert raw==int(w['raw'],16) and sec['name']==w['section'] and end-va==w['length']
  assert payload.hex()==w['hex'] and hashlib.sha256(payload).hexdigest()==w['sha256'],w['id']
  if w['kind']=='cstring':assert payload==w['value'].encode()+b'\0'
  if w['kind']!='code':continue
  code_count+=1
  out=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16',f'--start-address={va}',f'--stop-address={end+15}',str(args.bin)],text=True)
  ins=[];cursor=va;direct=[];indirect=[]
  for line in out.splitlines():
   m=re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s)+)\s*(.*)$',line)
   if not m:continue
   pos=int(m[1],16)
   if pos>=end:break
   bb=bytes.fromhex(m[2]);asm=m[3].strip();assert pos==cursor and '(bad)' not in asm and not asm.startswith('.byte')
   cursor+=len(bb);item=dict(va=f'0x{pos:08X}',hex=bb.hex(),asm=asm);ins.append(item)
   if asm.startswith('call'):
    if len(bb)==5 and bb[0]==0xe8:
     dest=(pos+5+struct.unpack_from('<i',bb,1)[0])&0xffffffff
     direct.append(dict(va=f'0x{pos:08X}',target=f'0x{dest:08X}',hex=bb.hex()))
    else:indirect.append(item)
  assert cursor==end and ins==w['instructions'],w['id']
  assert direct==sets[w['id']]['direct'] and indirect==sets[w['id']]['indirect']
  all_direct+=direct;ni+=len(ins)
 for v in tab['vtables']:
  vt=int(v['vtable'],16);col=int(v['col'],16);td=int(v['type_descriptor'],16)
  assert u(vt-4)==col and u(col+12)==td and cstr(td+8)==v['rtti_name']
  for s in v['slots']:assert u(vt+int(s['offset'],16))==int(s['target'],16)
 anchors={
  0x4b7eaf:'c705f42ffd00c0994b00',
  0x494376:'c705f82cfd00b46ec000',
  0x494380:'c705a48bfd0000000000',
  0x49439c:'b9f82cfd00',
  0x4fda3e:'8b44fe04',
  0x4fda88:'8bceff55fc',
  0x4b99ec:'8bd9',
  0x4b9a32:'a32c39f900',
  0x4b9b34:'8bf3e815e2ffff',
  0x4b7d6e:'ffd2',0x4b7d80:'ffd2',
  0x4b7da7:'89beac5e0000',0x4b7dbc:'ffd2',
  0x4c594a:'c706385bc000',0x8dc2f0:'33c0c3',
  0x4bbf65:'b85873fb00e8d1770900',
  0x58a9eb:'c7401055430f00',0x58aa2e:'be6c5cf900',
 }
 for va,h in anchors.items():assert take(va,len(h)//2).hex()==h,hex(va)
 assert tab['scene_owner']['owner']=='0x00FD2CF8' and tab['scene_owner']['field']=='0x00FD8BA4'
 assert 0xfd2cf8+0x5eac==0xfd8ba4 and 0xf8d9e0+0x5f4c==0xf9392c
 assert 0xfd2cf8+4+0x5f*8==0xfd2ff4
 stops=[x for x in all_direct if int(x['target'],16) in (0x5624b0,0x561db0,0x4ad0a0,0x6f4dd0,0x6f4f40,0x6f5a70)]
 assert not stops,'Unexpected explicit Q/known named-call target in this bounded set'
 git_count=0;nav_count=0
 for s in manifest['sources']:
  if args.repo:
   parts=subprocess.check_output(['git','ls-tree',s['commit'],'--',s['path']],cwd=args.repo,text=True).split()
   assert parts and parts[2]==s['git_blob'],s['path'];git_count+=1
  if 'local_copy' in s and (root/s['local_copy']).exists():
   payload=(root/s['local_copy']).read_bytes()
   assert hashlib.sha256(payload).hexdigest()==s['sha256'] and len(payload)==s['size']
   assert hashlib.sha1(f'blob {len(payload)}\0'.encode()+payload).hexdigest()==s['git_blob'];nav_count+=1
 files_count=0
 if (root/'deliverables-manifest.json').exists():
  for x in load('deliverables-manifest.json')['files']:
   payload=(root/x['path']).read_bytes()
   assert len(payload)==x['size'] and hashlib.sha256(payload).hexdigest()==x['sha256'];files_count+=1
 print(json.dumps(dict(status='PASS_BOUNDED_005F_CANCELLATION_EVIDENCE',read_only=True,original_sha256=sha,windows=len(ev['windows']),bytes=sum(x['length'] for x in ev['windows']),code_windows=code_count,decoded_instructions=ni,bounded_direct_calls=len(all_direct),bounded_indirect_calls=sum(len(x['indirect']) for x in sets.values()),explicit_Q_or_known_named_call_targets_in_windows=len(stops),vtables=len(tab['vtables']),source_pins_verified=git_count,optional_navigation_copies_verified=nav_count,deliverables_verified=files_count,excludes=['Client/Lua execution','Transitive absence through dynamic object callbacks','All scene types or disconnect paths','Network packet scheduling order']),ensure_ascii=False,indent=2))

if __name__=='__main__':main()
