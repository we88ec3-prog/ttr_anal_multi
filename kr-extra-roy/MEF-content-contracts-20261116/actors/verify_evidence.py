#!/usr/bin/env python3
"""Read-only reproduction of bounded MEF/Q actor byte and identity contracts.

No Client/Lua execution, process attachment, resource mutation, Git mutation,
network fetch, or whole-program certification. JSON result goes to stdout.
"""
import argparse, hashlib, json, os, re, struct, subprocess
from pathlib import Path

EXPECTED='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def sha(b):return hashlib.sha256(b).hexdigest()
def need(v,why):
 if not v:raise AssertionError(why)
def parse_pe(b):
 p=struct.unpack_from('<I',b,0x3c)[0]
 need(b[p:p+4]==b'PE\0\0','PE signature')
 machine,n=struct.unpack_from('<HH',b,p+4)
 o=p+24;size=struct.unpack_from('<H',b,p+20)[0]
 need(machine==0x14c and struct.unpack_from('<H',b,o)[0]==0x10b,'PE32/i386')
 base=struct.unpack_from('<I',b,o+28)[0];ss=[]
 for i in range(n):
  at=o+size+40*i;vs,rva,rs,rp=struct.unpack_from('<IIII',b,at+8)
  ss.append(dict(name=b[at:at+8].split(b'\0')[0].decode(),va=base+rva,virtual_size=vs,raw_size=rs,raw_offset=rp))
 return base,ss
def decoded(text):
 rows=[]
 for line in text.splitlines():
  m=re.match(r'^\s*([0-9a-fA-F]+):\s+((?:[0-9a-fA-F]{2}\s+)+)\s*(.*?)\s*$',line)
  if m:rows.append(dict(va=int(m[1],16),hex=''.join(m[2].split()).lower(),text=m[3]))
 return rows
def main():
 p=argparse.ArgumentParser()
 p.add_argument('--bin',type=Path,required=True)
 p.add_argument('--repo',type=Path,required=True)
 p.add_argument('--evidence-dir',type=Path,default=Path(__file__).resolve().parent)
 a=p.parse_args();d=a.bin.read_bytes()
 need(sha(d)==EXPECTED,'original SHA256')
 e=json.loads((a.evidence_dir/'native-windows.json').read_text())
 c=json.loads((a.evidence_dir/'contracts.json').read_text())
 m=json.loads((a.evidence_dir/'source-manifest.json').read_text())
 base,ss=parse_pe(d)
 need(base==e['binary']['image_base']==0x400000,'image base')
 need(ss==e['binary']['sections'] and len(d)==e['binary']['size'],'PE mapping/size')
 def raw(va,n=1):
  for s in ss:
   x=va-s['va']
   if 0<=x and x+n<=s['raw_size']:return s['raw_offset']+x
  raise AssertionError(f'not file backed: {va:x}/{n}')
 def grab(va,n):
  o=raw(va,n);return d[o:o+n]
 def u32(va):return struct.unpack('<I',grab(va,4))[0]
 ins={};ids=set();code=0;count=0;total=0
 for r in e['records']:
  need(r['id'] not in ids,'unique record');ids.add(r['id'])
  va=r['va'];n=r['size'];b=grab(va,n);total+=n
  need(va+n==r['end_va'] and raw(va,n)==r['raw_offset'],'range '+r['id'])
  need(b.hex()==r['hex'] and sha(b)==r['sha256'],'bytes/hash '+r['id'])
  if r['kind']=='code':
   code+=1
   t=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16',f'--start-address={va}',f'--stop-address={va+n+16}',str(a.bin)],text=True)
   actual=[x for x in decoded(t) if x['va']<va+n]
   need(actual==r['instructions'],'decode '+r['id']);cursor=va
   for x in actual:
    need(x['va']==cursor,'instruction boundary '+r['id'])
    need('(bad)' not in x['text'] and '.byte' not in x['text'],'valid instruction '+r['id'])
    cursor+=len(bytes.fromhex(x['hex']));ins[x['va']]=x;count+=1
   need(cursor==va+n,'complete decode '+r['id'])
  else:
   if 'u32_values' in r:need(list(struct.unpack('<'+'I'*(n//4),b))==r['u32_values'],'DWORD table '+r['id'])
   if 'decoded' in r:need(b[-1:]==b'\0' and b[:-1].decode(r['encoding'])==r['decoded'],'string '+r['id'])
   if 'rtti_name' in r:need(b[8:-1].decode()==r['rtti_name'] and b[-1:]==b'\0','RTTI name')
 checks=[]
 def exact(va,h,label):
  need(va in ins,'anchor boundary '+label)
  need(ins[va]['hex']==h,'anchor '+label);checks.append(label)
 def call(va,target):
  need(va in ins and ins[va]['hex'].startswith('e8'),'E8 boundary '+hex(va))
  b=grab(va,5);need(va+5+struct.unpack('<i',b[1:])[0]==target,'call target '+hex(va));checks.append(f'{va:08x}->{target:08x}')
 for b in c['bindings']:
  r=b['registrar'];need(grab(r+0x18,2)==b'\xc7\x05','registrar MOV '+b['name'])
  need(u32(r+0x1a)==b['slot'] and u32(r+0x1e)==b['target'],'registrar native target '+b['name'])
  need(grab(r+0x58,1)==b'\x68' and u32(r+0x59)==b['name_va'],'registrar name '+b['name'])
  need(grab(r+0x69,1)==b'\x68' and u32(r+0x6a)==b['closure'],'registrar closure '+b['name'])
  checks.append('registered '+b['name'])
 for v in c['vtables']:
  need(u32(v['vtable']-4)==v['col'],'vtable COL')
  need(u32(v['col']+12)==v['type_descriptor'],'RTTI type')
  for off,target in v['slots'].items():need(u32(v['vtable']+int(off,16))==int(target,16),'vtable target')
 exact(0x565e4b,'a37827fe00','normal native Q receiver stored')
 exact(0x560209,'a3dc73fb00','distinct Q actor sentinel published')
 exact(0x562efa,'83ff0a','signed model threshold 10')
 exact(0x562f05,'81ff10270000','signed model threshold 10000')
 exact(0x562f14,'81fff82a0000','signed model threshold 11000')
 exact(0x562f23,'81ff08520000','signed model threshold 21000')
 exact(0x562f45,'8a4d08','slot low BYTE for actor ID')
 exact(0x562f4d,'884c2419','slot byte placed in ID high BYTE')
 exact(0x562f82,'66895304','packed actor ID stored as WORD')
 exact(0x562f88,'c1e618','model type byte packed at bit24')
 exact(0x56319c,'0fb75508','dependency key is slot low WORD')
 exact(0x563284,'8b4508','formal map retains full DWORD slot')
 exact(0x56328b,'83c618','formal actor tree is M+18')
 exact(0x563298,'89442424','formal map node input key')
 exact(0x56329c,'895c2428','formal map node input actor pointer')
 exact(0x4d0bb8,'c70724c8c000','concrete CEventActor primary vtable')
 exact(0x4d0bbe,'c787f0000000acc8c000','concrete CEventActor FSM vtable')
 exact(0x476430,'c20400','DeleteObject has no body beyond ret4')
 exact(0x563abb,'8b5014','DeleteAll invokes cleanup slot +14')
 exact(0x563ac6,'6a01','DeleteAll requests deleting destructor')
 exact(0x563b1a,'8d7918','DeleteAll clears exactly M+18 tree')
 exact(0x4d0cbb,'f6450801','deleting destructor tests delete bit')
 exact(0x564911,'8d4e18','ShowObject looks up Q tree')
 exact(0x56492f,'89902c040000','ShowObject writes +42C only')
 exact(0x4d0fc0,'83b92c04000000','actor render checks show flag')
 exact(0x561705,'8b4228','Q render iteration selects v+28')
 exact(0x4a0bee,'b938b1fa00','lb avatar uses separate world tree')
 exact(0x56a9ed,'db5de8','formal slot numeric conversion is x87 FISTP32')
 exact(0x56a99a,'db5dec','formal model numeric conversion is x87 FISTP32')
 exact(0x56a8c1,'db5df0','direction numeric conversion is x87 FISTP32')
 exact(0x56aa2b,'ff55c0','CreateObject call with native owner')
 exact(0x56aa30,'33c0','CreateObject marshaller returns without pushing ID')
 exact(0x568e42,'b801000000','outer result count is one, not an ID push')
 for site,target in [(0x568e3a,0x56a710),(0x562f68,0x4d0b80),(0x5632a0,0x57ef20),(0x5632ab,0x82f200),(0x82f2ae,0x89120c),(0x568f00,0x56a430),(0x563b1d,0x823850),(0x4d0cb6,0x4c7b90),(0x4d0cc2,0x89120c),(0x823866,0x73eba0),(0x73ebc1,0x89120c),(0x562694,0x563a70),(0x4d0f8b,0x4d0dd0),(0x5632e9,0x82ef00),(0x564917,0x82ef00),(0x568e9a,0x56aaa0)]:call(site,target)
 need(c['q_tree']==c['q_owner']+0x18 and c['q_tree_sentinel_pointer']==c['q_tree']+4 and c['q_tree_count']==c['q_tree']+8,'Q map layout arithmetic')
 need(c['q_tree']!=c['world_tree'],'Q and world receiver identities differ')
 for v in c['slot_arithmetic_vectors']:
  s=v['slot'];need(v['q_map_key']==s&0xffffffff and v['prepass_key']==s&0xffff and v['actor_id']==((s&0xff)<<8)|1,'SYN slot projection')
 need(len({v['q_map_key'] for v in c['slot_arithmetic_vectors']})==3 and len({v['actor_id'] for v in c['slot_arithmetic_vectors']})==1,'distinct Q slots can alias actor ID')
 def classify(x):return 0 if x<10 else 1 if x<10000 else 6 if x<11000 else 7 if x<21000 else 0
 for v in c['model_classification_vectors']:need(v['type_byte']==classify(v['model']) and v['warning_branch']==(v['model']>=21000),'SYN classification')
 for name,h in m['artifacts'].items():need(sha((a.evidence_dir/name).read_bytes())==h,'artifact '+name)
 env=os.environ.copy();env.update(GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0',GIT_NO_REPLACE_OBJECTS='1')
 def git(*args):return subprocess.check_output(['git','-c','remote.origin.promisor=false',*args],cwd=a.repo,env=env)
 pins=m['source_pins'];cache={};contents=0
 for commit in {x['commit'] for x in pins}:
  paths=[x['path'] for x in pins if x['commit']==commit]
  tree=git('ls-tree',commit,'--',*paths).decode()
  cache[commit]={p.split(None,3)[3]:p.split(None,3)[2] for p in tree.splitlines()}
 for p in pins:
  need(cache[p['commit']].get(p['path'])==p['git_blob_sha1'],'source tree pin '+p['path'])
  b=git('cat-file','blob',p['git_blob_sha1'])
  need(hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==p['git_blob_sha1'],'Git object identity')
  need(len(b)==p['size'] and sha(b)==p['sha256'],'source content '+p['path']);contents+=1
 print(json.dumps(dict(status='PASS',scope='Bounded static original-byte, selected ABI/container/lifetime edges and source identities; no Client/Lua execution',records=len(e['records']),code_windows=code,native_bytes=total,instructions=count,selected_checks=len(checks),bindings=len(c['bindings']),vtables=len(c['vtables']),source_pins=len(pins),source_contents_checked=contents,synthetic_slot_vectors=len(c['slot_arithmetic_vectors']),synthetic_model_vectors=len(c['model_classification_vectors']),client_executed=False,lua_executed=False,checks=checks),ensure_ascii=False,indent=2))
if __name__=='__main__':main()
