"""Read-only square BND comparison and authorized new pool BND extraction.
No Client/game resource changes. numpy1.26.4; raw BND remains local.
"""
from pathlib import Path
import sys,struct,zlib,hashlib,json,collections,xml.etree.ElementTree as ET
import numpy as np
R=Path(r'E:\Tartaros\workspace');sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
OUT=R/'CLIENT/evidence/20261107-square-minimap'
sha=lambda b:hashlib.sha256(b).hexdigest()
B=Archive(R/'Map/BoundMap.stp');M=Archive(R/'Map/MiniMap.stp');T=Archive(R/'Table.stp')
assert sha((R/'Map/BoundMap.stp').read_bytes())=='07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8'
maps=[n.attrib for n in ET.fromstring(T.read('Table/_MapList.xml')).iter('MAP')]
selected=[n for n in maps if 'square' in n.get('MAP','').lower() or 'square' in n.get('BOUND','').lower()]
mini={Path(n).stem.lower():n for n in M.files if n.lower().endswith('.mmt')}
rows=[];masks={}
for member in sorted(n for n in B.files if 'square' in n.lower() and n.lower().endswith('.bnd')):
 data=B.read(member);stem=Path(member).stem.lower();v,w,h,wx,wy=struct.unpack_from('<IIIff',data,0x20)
 row={'member':member,'bytes':len(data),'sha256':sha(data),'version':v,'width':w,'height':h,'worldWidth':wx,'worldHeight':wy,'map_rows':[n for n in selected if n['BOUND'].lower()==stem],'minimap_member':mini.get(stem)}
 try:
  assert data[:21]==b'MapTool Reinforce 1.0' and v in (0,2) and 0<w<=2048 and 0<h<=2048 and wx>0 and wy>0
  blocked=np.zeros(w*h,dtype=np.uint8);cursor=0x234;layers=[];static=hashlib.sha256(struct.pack('<IIff',w,h,wx,wy))
  for i in range(32):
   offset,size,expanded,count=struct.unpack_from('<4I',data,0x34+i*16)
   if not count:continue
   assert i<=1 and count==w*h and expanded==count*4 and offset==cursor and size<=len(data)-cursor
   d=zlib.decompressobj();raw=d.decompress(data[offset:offset+size]);assert d.eof and not d.unused_data and len(raw)==expanded
   blocked|=(np.frombuffer(raw,dtype='<u4')!=0).astype(np.uint8);cursor+=size
   static.update(struct.pack('<I',i));static.update(raw);layers.append({'layer':i,'sha256':sha(raw),'nonzero_cells':int(np.count_nonzero(np.frombuffer(raw,dtype='<u4')))})
  assert [x['layer'] for x in layers]==[0,1] and cursor==len(data)
  row.update(status='VALID_STATIC_SERVER_RULES',layers=layers,static_layers_sha256=static.hexdigest(),movement_mask_sha256=sha(struct.pack('<IIff',w,h,wx,wy)+blocked.tobytes()),walkable_cells=int(np.count_nonzero(blocked==0)))
  masks[stem]=(blocked.reshape(h,w),w,h,wx,wy)
  assert wx==1536 and wy==1536 and 1536%w==0 and 1536%h==0
  world_mask=np.repeat(np.repeat(blocked.reshape(h,w),1536//h,axis=0),1536//w,axis=1)
  row['world_unit_mask_sha256']=sha(struct.pack('<II',1536,1536)+world_mask.tobytes())
  row['walkable_world_unit_tiles']=int(np.count_nonzero(world_mask==0))
 except Exception as ex:row.update(status='UNSUPPORTED_OR_INVALID_STATIC_LAYOUT',reason=str(ex) or 'Header/layers rejected by exact LocalTutorialBounds static0/1 constraints; additional layer or incomplete layout')
 if row['minimap_member']:
  raw=M.read(row['minimap_member'])
  try:text=raw.decode('utf-8-sig')
  except UnicodeDecodeError:text=raw.decode('euc-kr')
  row['minimap_attributes']=ET.fromstring(text).attrib;row['minimap_sha256']=sha(raw)
 rows.append(row)
def stand(stem,x,y):
 b,w,h,wx,wy=masks[stem]
 return bool(0<=x<wx and 0<=y<wy and b[int(y*h/wy),int(x*w/wx)]==0)
positions=[(10338,920,900),(10013,850,940),(10014,870,940),(10015,890,940),(10016,910,940),(10049,930,940),(10050,930,910),(10051,850,965),(10069,850,910),(10094,870,910),(10101,910,965),(10026,930,965)]
pool='square03n_avatar_pool';checks=[{'id':i,'x':x,'y':y,'canStand':stand(pool,x,y)} for i,x,y in positions]
reserved=[(x,y) for i,x,y in positions if stand(pool,x,y)];alternatives=[]
for row in checks:
 if row['canStand']:continue
 ox,oy=row['x'],row['y'];options=[]
 for dx in range(-50,51,5):
  for dy in range(-50,51,5):
   x,y=ox+dx,oy+dy
   if not stand(pool,x,y) or any((x-rx)**2+(y-ry)**2<100 for rx,ry in reserved):continue
   # Extra margin is reconstruction policy; primary CanStand remains exact.
   if not all(stand(pool,x+mx,y+my) for mx,my in [(0,0),(-3,0),(3,0),(0,-3),(0,3)]):continue
   options.append((dx*dx+dy*dy,(x-900)**2+(y-900)**2,x,y,dx,dy))
 assert options;_,_,x,y,dx,dy=min(options);reserved.append((x,y));alternatives.append({'id':row['id'],'original':[ox,oy],'candidate':[x,y],'offset':[dx,dy],'canStand':True,'source':'SERVER_CANDIDATE_NOT_OFFICIAL_PLACEMENT','selection':'nearest5-unit-grid candidate with3-unit cardinal margin and10-unit NPC separation'})
poolrow=next(x for x in rows if x['member'].lower().endswith('/'+pool+'.bnd'))
pooldata=B.read(poolrow['member']);target=R/'runtime-observations/2026-11-07-pool-square/pool-square.bnd';target.parent.mkdir(parents=True,exist_ok=True)
if target.exists():assert target.read_bytes()==pooldata
else:
 with target.open('xb') as f:f.write(pooldata)
def groups(key):
 d=collections.defaultdict(list)
 for row in rows:
  if key in row:d[row[key]].append(row['member'])
 return [{'hash':k,'members':v,'members_with_mmt':[x for x in v if next(r for r in rows if r['member']==x)['minimap_member']]} for k,v in d.items() if len(v)>1]
result={'schema':'square-static-bounds-equivalence-v1','policy':'Full exact static layer0/1 nonzero union matching LocalTutorialBounds; dynamic/MEF barriers excluded. Extents included in movement hash.','maplist_square_rows':selected,'bounds':rows,'byte_identical_groups':groups('sha256'),'static_layers_identical_groups':groups('static_layers_sha256'),'movement_mask_identical_groups':groups('movement_mask_sha256'),'world_unit_mask_identical_groups':groups('world_unit_mask_sha256'),'pool':{'map':1088,'model':'Square03N_Avatar_Pool','bound':'Square03N_Avatar_Pool','extracted_path':str(target),'sha256':poolrow['sha256'],'version':poolrow['version'],'worldWidth':poolrow['worldWidth'],'worldHeight':poolrow['worldHeight'],'minimap':poolrow['minimap_attributes'],'player900_900':stand(pool,900,900),'player906_900':stand(pool,906,900),'npc_checks':checks,'npc_alternatives':alternatives},'unresolved_maps':[n for n in selected if not any(Path(x['member']).stem.lower()==n['BOUND'].lower() for x in rows)]}
(OUT/'square-bounds-equivalence.json').write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'))
print(json.dumps({'bounds_checked':len(rows),'valid':sum(x['status']=='VALID_STATIC_SERVER_RULES' for x in rows),'pool':result['pool'],'byte_groups':len(result['byte_identical_groups']),'mask_groups':len(result['movement_mask_identical_groups'])}))
