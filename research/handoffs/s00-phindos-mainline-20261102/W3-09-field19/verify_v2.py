#!/usr/bin/env python3
"""Read-only Field19 v2 BND + native static SHA verification; no Client/Server execution."""
import argparse,hashlib,importlib.util,json,struct,sys,zlib
from pathlib import Path
from array import array
from collections import Counter
from xml.etree import ElementTree as ET

PINS={'BoundMap.stp':'07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8','Table.stp':'09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442','Tartaros.bin':'9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'}
PRIOR={'W3-07-normal-town/verify.py':'977a58b576122d7027e810c3ab0c91b727a5cb5cfe3b80636fcb58094666dc47','W3-08-town001-implementation/inspect_town001.py':'804a14c36d56e7191007a1cccc9c8e86532d04b95490058986340a8978482d9b'}
MAPS={'scenario_pathofpindus01':(191,'adb627155fc051aaa5a568ae57fe8731d388d58c2cf3244711078ef377321c58'),'scenario_pathofpindus02':(192,'89cc3d4b77d3cf0cdf64d45f610d7b987c704bc268881c13396e1375a2234fff')}
SLICES=[('BND dispatch',0x830040,0x8300CD,'a537b98b5913fd32f2c7cd968aeddd82637a140b02d47ee593001ffb8ce79089'),('non3 layout',0x82F660,0x82F84E,'4943b074282b8927bbe0b1f8187439d1782f52ae89c111b38f06e3958a346713'),('two-layer check',0x82CDF0,0x82CE72,'d194993f3d12e35d87a55a8ad2c934628a7f6dd220d94b009a8eaf120af3ce50'),('expedition layout loader',0x4C0EC0,0x4C13A0,'e399d5cdb7fac32a1ea63ac777930b4a174aadc78deb80b7dfd9800801f9c54c'),('expedition display caller',0x4C15C0,0x4C1879,'0609b352ed616daad125474952365d20eb41d829caa7c4928823b9978abcae98')]
def sha(b):return hashlib.sha256(b).hexdigest()
def load(p,n):
 s=importlib.util.spec_from_file_location(n,p)
 if s is None or s.loader is None:raise RuntimeError(str(p))
 m=importlib.util.module_from_spec(s);s.loader.exec_module(m);return m

def main():
 ap=argparse.ArgumentParser(description=__doc__)
 ap.add_argument('--sources',required=True,type=Path)
 ap.add_argument('--siblings',type=Path,default=Path(__file__).resolve().parent.parent)
 ap.add_argument('--output',required=True,type=Path)
 a=ap.parse_args()
 if a.output.exists():raise ValueError('Output already exists; refusing overwrite')
 raw={}
 for n,p in PINS.items():
  b=(a.sources/n).read_bytes()
  if sha(b)!=p:raise ValueError(n+' SHA mismatch')
  raw[n]=b
 for n,p in PRIOR.items():
  if sha((a.siblings/n).read_bytes())!=p:raise ValueError(n+' dependency SHA mismatch')
 v=load(a.siblings/'W3-07-normal-town/verify.py','w3reader')
 t=load(a.siblings/'W3-08-town001-implementation/inspect_town001.py','w3topology')
 bs=v.stp_selected(raw['BoundMap.stp'],{'BoundMap/'+n+'.bnd' for n in MAPS})
 tt=v.stp_selected(raw['Table.stp'],{'Table/_MapList.xml','Table/npctable.xml','Table/ExpeditionPosition.xml'})
 maprows=ET.fromstring(tt['Table/_MapList.xml'])
 results={}
 for name,(mapid,pin) in MAPS.items():
  b=bs['BoundMap/'+name+'.bnd']
  if sha(b)!=pin:raise ValueError(name+' SHA mismatch')
  version,w,h,wx,wy=struct.unpack_from('<IIIff',b,0x20)
  if (version,w,h,wx,wy)!=(2,768,768,768.,768.):raise ValueError(name+' header mismatch')
  row=maprows.find(f".//*[@ID='{mapid}']")
  if row is None or row.get('BOUND')!=name:raise ValueError(name+' MapList mismatch')
  layers=[];descs=[];cursor=0x234;empty=0
  for i in range(32):
   off,clen,expanded,count=struct.unpack_from('<4I',b,0x34+16*i)
   if count==0:
    if i<2 or (off,clen,expanded)!=(len(b),0,0):raise ValueError(name+' empty descriptor')
    empty+=1;continue
   if i!=len(layers) or i>=2 or off!=cursor or expanded!=count*4 or count!=w*h or off+clen>len(b):raise ValueError(name+' descriptor')
   d=zlib.decompressobj();z=d.decompress(b[off:off+clen],expanded+1)
   if len(z)!=expanded or not d.eof or d.unused_data or d.unconsumed_tail:raise ValueError(name+' zlib mismatch')
   aa=array('I');aa.frombytes(z)
   if aa.itemsize!=4:raise ValueError('requires uint32 array')
   if sys.byteorder!='little':aa.byteswap()
   counts=Counter(aa)
   if set(counts)-{0,1}:raise ValueError(name+' unexpected layer values')
   layers.append(aa)
   descs.append({'index':i,'offset':off,'compressed_bytes':clen,'expanded_bytes':expanded,'count':count,'sha256':sha(z),'value_counts':{str(k):counts[k] for k in sorted(counts)}})
   cursor=off+clen
  if len(layers)!=2 or empty!=30 or cursor!=len(b):raise ValueError(name+' incomplete layers')
  mask=bytearray(1 if x==0 and y==0 else 0 for x,y in zip(*layers))
  labels,dist,comps=t.topology(mask,w,h)
  for c in comps:
   cx,cy=c['candidate_cell']
   c['candidate_world_xy']=[cx+0.5,cy+0.5] # version2 world=grid, no Town1 2x
  overlap={'both_zero':sum(mask),'both_one':sum(x==1 and y==1 for x,y in zip(*layers)),'layer0_only_one':sum(x==1 and y==0 for x,y in zip(*layers)),'layer1_only_one':sum(x==0 and y==1 for x,y in zip(*layers))}
  if sum(overlap.values())!=w*h:raise ValueError('overlap mismatch')
  ix=372*w+360
  results[name]={'map_id':mapid,'map_row':dict(row.attrib),'bytes':len(b),'sha256':sha(b),'version':version,'grid':[w,h],'world':[wx,wy],'layer_descriptors':descs,'empty_descriptors':empty,'empty_offset':'EOF','mask_sha256':sha(mask),'overlap':overlap,'component_count':len(comps),'components_top3':comps[:3],'graph_coordinate_not_spawn_sample_360_372':[int(q[ix]) for q in layers]}
 sections=v.pe_sections(raw['Tartaros.bin']);sl=[]
 for name,a0,z,pin in SLICES:
  off=v.raw_offset(sections,a0,z-a0)
  if sha(raw['Tartaros.bin'][off:off+z-a0])!=pin:raise ValueError(name+' code hash mismatch')
  sl.append({'label':name,'va':hex(a0),'end_exclusive':hex(z),'raw_offset':hex(off),'sha256':pin})
 npcr=ET.fromstring(tt['Table/npctable.xml']);ids=[10001,10002,10003,10008,10013,10014,10047,10048,10015];npcs=[]
 for model in ids:
  n=npcr.find(f".//NPC[@ID='{model}']")
  if n is None:raise ValueError(str(model)+' missing')
  ts=n.findall('./TALKLIST/TALKSET')
  npcs.append({'model':model,'npc_type':n.get('TYPE'),'talksets':len(ts),'conditional_sets':sum(bool(q.findall('.//DEMAND')) for q in ts)})
 doc={'schema':'W3-09-v2-static-evidence-v1','source_sha256':PINS,'field19_maps':results,'native_slices':sl,'town1_talksets':npcs,'expedition_member_sha256':sha(tt['Table/ExpeditionPosition.xml']),'classification':{'static_decode':'PASS','native_FULL_PASS':'NOT_CLAIMED','original_spawn':'UNKNOWN','original_npc_placement':'UNKNOWN','gameplay':'NOT_RUN'}}
 a.output.parent.mkdir(parents=True,exist_ok=True)
 a.output.write_text(json.dumps(doc,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
 print(json.dumps({'static_decode':'PASS','maps':{k:{'both_zero':x['overlap']['both_zero'],'candidate_world_xy':x['components_top3'][0]['candidate_world_xy']} for k,x in results.items()},'gameplay':'NOT_RUN'},ensure_ascii=False))
if __name__=='__main__':main()
