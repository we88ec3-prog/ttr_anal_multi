#!/usr/bin/env python3
"""Read-only verification of typed MEF observation contracts; no target execution."""
from __future__ import annotations
import argparse,hashlib,json,pathlib,re,struct,subprocess,sys
sys.dont_write_bytecode=True
HERE=pathlib.Path(__file__).resolve().parent
SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def require(ok,why):
 if not ok:raise ValueError(why)
def digest(b):return hashlib.sha256(b).hexdigest()
class PE:
 def __init__(self,path):
  self.path=path;self.b=path.read_bytes();require(digest(self.b)==SHA,'KR BIN identity')
  p=struct.unpack_from('<I',self.b,0x3c)[0];o=p+24;self.base=struct.unpack_from('<I',self.b,o+28)[0]
  require(self.b[:2]==b'MZ'and self.b[p:p+4]==b'PE\0\0'and struct.unpack_from('<H',self.b,p+4)[0]==0x14c and struct.unpack_from('<H',self.b,o)[0]==0x10b and self.base==0x400000,'PE32/i386 mapping')
  h=o+struct.unpack_from('<H',self.b,p+20)[0];self.sections=[]
  for i in range(struct.unpack_from('<H',self.b,p+6)[0]):
   s=h+i*40;vs,rv,rs,ro=struct.unpack_from('<4I',self.b,s+8);self.sections.append((self.b[s:s+8].rstrip(b'\0').decode(),self.base+rv,rs,ro))
 def raw(self,v,n=1):
  m=[o+v-a for name,a,s,o in self.sections if a<=v and v+n<=a+s];require(len(m)==1,'Raw-backed range');return m[0]
 def at(self,v,n):
  o=self.raw(v,n);return self.b[o:o+n]
 def u32(self,v):return struct.unpack('<I',self.at(v,4))[0]
 def string(self,v):
  o=self.raw(v);z=self.b.index(0,o);require(z-o<4096,'Bounded string');return self.b[o:z].decode('ascii')
 def candidates(self,t):
  rel=[];lit=[]
  for name,a,n,o in self.sections:
   data=self.b[o:o+n]
   if name=='.text':
    for op in (0xe8,0xe9):
     k=-1
     while True:
      k=data.find(bytes([op]),k+1)
      if k<0 or k+5>len(data):break
      dest=(a+k+5+struct.unpack_from('<i',data,k+1)[0])&0xffffffff
      if dest==t:rel.append([hex(a+k),hex(op)])
   if name in ('.text','.rdata','.data'):
    k=-1
    while True:
     k=data.find(struct.pack('<I',t),k+1)
     if k<0:break
     lit.append([name,hex(a+k)])
  return dict(relative_candidates=sorted(rel,key=lambda x:int(x[0],16)),literal_candidates=lit)
 def decode(self,a,z):
  txt=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(a),'--stop-address='+hex(z+15),str(self.path)],text=True);rows=[];cursor=a
  for line in txt.splitlines():
   m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)$',line)
   if m and a<=int(m[1],16)<z:
    v=int(m[1],16);b=bytes.fromhex(m[2]);asm=m[3].strip();require(v==cursor and '(bad)'not in asm and b==self.at(v,len(b)),'Decode instruction boundary');cursor+=len(b);rows.append(dict(va=hex(v),hex=b.hex(),asm=asm))
  require(cursor==z,'Exact endpoint');return rows

def run(a):
 require(not sys.flags.optimize,'Do not use -O');p=PE(a.bin);e=json.loads((HERE/'native-evidence.json').read_text());all_ins={};total=0
 for w in e['windows']:
  v=int(w['start'],16);z=int(w['end'],16);b=p.at(v,z-v);require(z-v==w['bytes']and hex(p.raw(v,z-v))==w['raw']and b.hex()==w['hex']and digest(b)==w['sha256'],'Window '+w['id']);rows=p.decode(v,z);require(rows==w['instructions'],'Disassembly '+w['id']);total+=len(rows);all_ins.update({int(i['va'],16):i for i in rows})
 for d in e['data']:
  v=int(d['va'],16);b=p.at(v,d['bytes']);require(b.hex()==d['hex']and digest(b)==d['sha256']and hex(p.raw(v,len(b)))==d['raw'],'Data '+d['id'])
 for target,expected in e['candidate_census'].items():require(p.candidates(int(target,16))==expected,'Census '+target)
 selected=[]
 for w in e['windows']:
  if w['id'].startswith('talk_'):
   selected.extend(dict(window=w['id'],**i)for i in w['instructions']if re.search(r'^mov\s+DWORD PTR \[[a-z]{3}\+0x9c\],',i['asm']))
 require(selected==e['talk_selected_direct_writes']and [x['va']for x in selected]==['0x6bced9','0x6bd682','0x6bd7cd'],'Typed direct selected writers')
 overrides=[dict(offset=hex(off),target=hex(p.u32(0xc3eb44+off)),base=hex(p.u32(0xc4909c+off)))for off in range(0,0x16c,4)if p.u32(0xc3eb44+off)!=p.u32(0xc4909c+off)]
 require(overrides==e['talk_vtable_overrides']and len(overrides)==7,'Typed override set')
 for x in e['time_import']:
  require(p.at(int(x['descriptor_va'],16),20).hex()==x['descriptor_hex']and p.at(int(x['lookup_slot_va'],16),4).hex()==x['lookup_hex']and p.string(int(x['name_va'],16))=='timeGetTime'and x['iat_va']=='0xbd25a0','timeGetTime import')
 anchors={0x4a9f59:'83b87c04000000',0x4a9f66:'0520040000',0x4aa27c:'66c744240c00f0',0x4aa4b1:'6683b88800000003',0x564688:'d9ee',0x5624f4:'817f38e8030000',0x562514:'c705a0a7fb0001000000',0x56251e:'397728',0x4a89e6:'c705a0a7fb0000000000',0x4a8a8a:'c705a0a7fb0000000000',0x54ea0d:'b801000000',0x5648eb:'b801000000'}
 for v,h in anchors.items():require(v in all_ins and all_ins[v]['hex']==h,'Semantic anchor '+hex(v))
 c=json.loads((HERE/'observation-catalog.json').read_text());expected={'lb.GetTime','Tutorial.IsSynopsisSkipped','Tutorial.IsCutSceneRunning','Tutorial.IsCharacterAvailable','Tutorial.GetControlStatus','Tutorial.GetTutorialState','Tutorial.IsIsiliaFound','Tutorial.CheckLeader','Tutorial.IsLeaderDialogOpened','Tutorial.IsScenarioEnded','CameraWorks.IsEnded','Q.IsCutSceneRunning','Q.GetLeaderPosN','Q.IsAllObjectsStopped','Q.IsPrologRunning','Q.IsBookFlying'};require(len(c['records'])==16 and {r['name']for r in c['records']}==expected,'16 exact queries')
 for r in c['records']:
  w=next(w for w in e['windows']if w['id']==r['evidence_id']);require(w['start']==r['native'],'Query native evidence')
 pins=0
 if a.repo:
  s=json.loads((HERE/'source-manifest.json').read_text())
  for r in s['references']:
   b=subprocess.check_output(['git','show',r['commit']+':'+r['path']],cwd=a.repo);require(len(b)==r['bytes']and digest(b)==r['sha256'],'Source pin '+r['path']) # SHA-256 checked; Git blob is independently checked below.
   oid=hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest();require(oid==r['git_blob'],'Git blob '+r['path']);pins+=1
 return dict(status='PASS',scope='Native bytes, instruction boundaries, 16 typed observation sources, bounded typed dialog writes and source pins; not gameplay',binary_sha256=SHA,code_windows=len(e['windows']),native_bytes=sum(w['bytes']for w in e['windows']),instructions=total,data_windows=len(e['data']),exact_query_sources=16,semantic_anchors=len(anchors),talk_vtable_slots=91,talk_override_slots=7,talk_explicit_selected_writers=3,candidate_censuses=len(e['candidate_census']),source_pins=pins,client_executed=False,lua_executed=False,server_executed=False,ordinary_world_lua_result_bridge=False,ordinary_non_q_first_entry=False,full_program_alias_exclusion=False)
if __name__=='__main__':
 ap=argparse.ArgumentParser(description=__doc__);ap.add_argument('--bin',required=True,type=pathlib.Path);ap.add_argument('--repo',type=pathlib.Path);args=ap.parse_args();print(json.dumps(run(args),ensure_ascii=False,indent=2))
