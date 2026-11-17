#!/usr/bin/env python3
"""Read-only original bytes/resources and offline contract verification.
No Client/Lua/Server execution, network, repository writes or unpacked-resource output.
Uses the hash-pinned, reviewed STPD data reader in the prior sibling study.
"""
from __future__ import annotations
import argparse,hashlib,importlib.util,json,re,struct,subprocess,sys,zlib
from pathlib import Path
import xml.etree.ElementTree as ET
if sys.flags.optimize:raise RuntimeError('Use Python without -O')
HERE=Path(__file__).resolve().parent
BIN_SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def sha(b:bytes)->str:return hashlib.sha256(b).hexdigest()
def require(ok:bool,why:str):
 if not ok:raise ValueError(why)
def read(p:Path):return json.loads(p.read_text(encoding='utf-8'))
def xml(b:bytes):
 m=re.search(br'encoding=[\"\x27]([^\"\x27]+)',b[:160]);enc=m[1].decode()if m else'utf-8-sig'
 return ET.fromstring(re.sub(r'encoding=[\"\x27][^\"\x27]+[\"\x27]','encoding="utf-8"',b.decode(enc),count=1))
def run(a):
 b=a.bin.read_bytes();require(sha(b)==BIN_SHA,'KR binary identity')
 pe=struct.unpack_from('<I',b,60)[0];op=pe+24
 require(b[:2]==b'MZ'and b[pe:pe+4]==b'PE\0\0','PE')
 require(struct.unpack_from('<H',b,pe+4)[0]==0x14c and struct.unpack_from('<H',b,op)[0]==0x10b,'PE32 i386')
 base=struct.unpack_from('<I',b,op+28)[0];require(base==0x400000,'base')
 st=op+struct.unpack_from('<H',b,pe+20)[0];sections=[]
 for i in range(struct.unpack_from('<H',b,pe+6)[0]):
  vsize,va,n,o=struct.unpack_from('<IIII',b,st+40*i+8);sections.append((base+va,n,o))
 def raw(va,n):
  matches=[o+va-v for v,size,o in sections if v<=va and va+n<=v+size]
  require(len(matches)==1,'raw backing');return matches[0]
 def at(va,n):o=raw(va,n);return b[o:o+n]
 e=read(HERE/'native-evidence.json');boundary=set();ins_count=0
 for w in e['windows']:
  v=int(w['va'],16);n=w['bytes'];data=at(v,n)
  require(int(w['raw'],16)==raw(v,n)and data.hex()==w['hex']and sha(data)==w['sha256'],'window '+w['id'])
  txt=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(v),'--stop-address='+hex(v+n+15),str(a.bin)],text=True)
  rows=[]
  for line in txt.splitlines():
   m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)$',line)
   if m and int(m[1],16)<v+n:rows.append(dict(va=hex(int(m[1],16)),hex=bytes.fromhex(m[2]).hex(),asm=m[3].strip()))
  require(rows==w['instructions'],'native decoding '+w['id']);cursor=v
  for x in rows:
   require(int(x['va'],16)==cursor and '(bad)'not in x['asm'],'native instruction boundary');boundary.add(cursor);cursor+=len(bytes.fromhex(x['hex']))
  require(cursor==v+n,'native endpoint');ins_count+=len(rows)
 for x in e['data']:
  data=bytes.fromhex(x['hex']);v=int(x['va'],16);require(at(v,len(data))==data and raw(v,len(data))==int(x['raw'],16),'data '+x['id'])
 for x in e['direct_transfers']:
  v=int(x['site'],16);data=at(v,5);require(v in boundary and data[0]==int(x['opcode'],16)and v+5+struct.unpack_from('<i',data,1)[0]==int(x['target'],16),'direct transfer')
 # Semantically load-bearing instruction assertions, independently named.
 anchors={0x4add98:'c7404430f54a00',0x4adda2:'c7405420f94a00',0x4addea:'c74074406c4300',
  0x4af735:'894f1c',0x4af73b:'884720',0x4af740:'89470c',0x4af747:'66894716',0x4af74f:'66894714',0x4af756:'894710',0x4af75d:'66894718',0x4af766:'884728',0x4af777:'884729',0x4af781:'895724',
  0x436c40:'8b01ff6028',0x4c4a4c:'be287afb00',0x548de3:'c705287afb0070fbc000',0x54aaf7:'49',0x54ab13:'8b4008',0x54aafa:'8b400c',0x5016a7:'0fb77908',0x5016c6:'66897dfa',0x5016ca:'66895dfc'}
 for v,h in anchors.items():require(v in boundary and at(v,len(bytes.fromhex(h))).hex()==h,'named anchor '+hex(v))
 require(struct.unpack('<I',at(0xc07084,4))[0]==0x4b0640,'Mission v+28')
 require(struct.unpack('<I',at(0xc073dc,4))[0]==0x4c4920,'Scenario v+28')
 pin=e['registered_target_comparison'];sp=HERE/pin['source_path'];require(sha(sp.read_bytes())==pin['sha256'],'surface pin')
 surface=read(sp);targets={int(x[4],16)for x in surface['registrars']}
 for x in pin['comparison']:require((int(x['native'],16)in targets)==x['direct_target_registered'],'exact registered target comparison')
 src=read(HERE/'source-manifest.json');pins=0
 for x in src['references']:
  if x['kind']=='PENDING_SIBLING_RESEARCH_REUSED':require(sha((HERE/x['path']).read_bytes())==x['sha256'],'sibling source pin');pins+=1
 parser=HERE.parent/'MEF-world-identity-scene-interaction-20261117/stp_reader.py'
 require(sha(parser.read_bytes())=='14cb262d8abfaabadcf3160d9cf4e404587dca8b4273175de3a1549170f1c9dd','reviewed data-only parser')
 spec=importlib.util.spec_from_file_location('pinned_data_reader',parser);module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
 paths={'Table.stp':a.table_stp,'Event.stp':a.event_stp,'BoundMap.stp':a.bound_stp};carriers={k:module.STP(v)for k,v in paths.items()}
 r=read(HERE/'resource-evidence.json');sample_count=0;squares=0
 for rec in r['members']:
  wanted=rec['member'];content,actual=carriers[wanted['carrier']].get(wanted['path']);require(actual==wanted,'resource identity '+wanted['path'])
  name=wanted['path']
  if name.endswith('.bnd'):
   ver,w,h=struct.unpack_from('<III',content,32);wx,wy=struct.unpack_from('<ff',content,44)
   require(rec['header']==dict(version=ver,width=w,height=h,world_x=wx,world_y=wy),'BND header')
   layers=[]
   for layer in rec['layers']:
    off,n,expanded,count=struct.unpack_from('<4I',content,0x34+16*layer['index']);z=zlib.decompressobj();p=z.decompress(content[off:off+n])+z.flush()
    require(z.eof and not z.unused_data and not z.unconsumed_tail and len(p)==expanded==count*4,'BND zlib bounds')
    require(sha(p)==layer['sha256']and [off,n,expanded,count]==[layer[k]for k in ('offset','compressed','expanded','count')],'BND layer hash');layers.append(p)
   for sample in rec['samples']:
    x,y=sample['point'];cx=int(x*w/wx);cy=int(y*h/wy);vals=[struct.unpack_from('<I',p,4*(cy*w+cx))[0]for p in layers];require(vals==sample['values'],'BND static sample');sample_count+=1
   q=rec['prior_candidate_square'];cx,cy=q['cell_center'];half=q['half_extent'];clear=all(struct.unpack_from('<I',p,4*(iy*w+ix))[0]==0 for p in layers for iy in range(cy-half,cy+half+1)for ix in range(cx-half,cx+half+1))
   require(clear==q['both_layers_zero']and q['side']==2*half+1,'BND candidate square only');squares+=1
  else:
   root=xml(content)
   if name=='Table/_ActorList.xml':
    rows=[dict(category=p.get('ID'),attributes=dict(x.attrib))for p in root if p.tag=='OBJCATEGORY'and p.get('ID')in('0','3')for x in p if x.get('ID')=='1'];require(rows==rec['rows'],'typed model contrast')
   elif name=='Table/_PortalList.xml':
    attrs=sorted(set().union(*(set(x.attrib)for x in root.iter())));require(attrs==['FILE','ID','STATE']and attrs==rec['attribute_names'],'portal effects not world points');require(sum('FILE'in x.attrib for x in root.iter())==rec['file_records'],'portal record count')
   elif name=='Event/SceneList.xml':require([dict(x.attrib)for x in root if x.get('questIdx')=='0'and x.get('sceneIdx')=='32760']==rec['matches'],'A1 collision check against fixed original only')
   else:
    keys={'191','192'}if name=='Table/_MapList.xml'else{'103'};require([dict(x.attrib)for x in root.iter()if x.get('ID')in keys]==rec['rows'],'selected resource rows')
 from test_contract import run as models
 model=models()
 return dict(status='PASS',scope='Bounded native bytes/decoding, selected original resources, source pins and offline models; NOT gameplay',binary_sha256=BIN_SHA,native_windows=len(e['windows']),native_bytes=sum(x['bytes']for x in e['windows']),decoded_instructions=ins_count,exact_anchors=len(anchors),data_records=len(e['data']),direct_transfers=len(e['direct_transfers']),sibling_source_pins=pins,original_members=len(r['members']),BND_samples=sample_count,prior_candidate_squares=squares,model_checks=model['model_tests'],field_carrier_reacquired=False,field_chart_cluster='public extracted sources read through connector; not reverified by this local script',client_executed=False,lua_executed=False,server_executed=False,runtime_target_complete=False,limits=['Deployment bindings intentionally remain null','Native target equality does not exclude arbitrary wrappers or aliases','BND zeros do not certify legal spawn','Bulk result handler coverage limited to prefix plus specific wrappers'])
if __name__=='__main__':
 p=argparse.ArgumentParser(description=__doc__);p.add_argument('--bin',required=True,type=Path);p.add_argument('--table-stp',required=True,type=Path);p.add_argument('--event-stp',required=True,type=Path);p.add_argument('--bound-stp',required=True,type=Path);a=p.parse_args()
 print(json.dumps(run(a),ensure_ascii=False,indent=2))
