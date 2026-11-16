"""Exact Town2 story resources plus explicitly reconstructed finite lab placements."""
from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as E,struct,zlib,collections,csv
from array import array
R=Path(r'E:\Tartaros\workspace');O=R.parent/'origin';D=Path(__file__).parent;A=R/'runtime-observations/20261107-alsmeer-mainline/assets'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();archives={};members={}
def read(carrier,member):
 if carrier not in archives:archives[carrier]=(Archive(O/carrier),Archive(R/carrier))
 a,w=archives[carrier];raw,work=a.read(member),w.read(member);assert raw==work
 members[(carrier,member)]={'carrier':carrier,'member':member,'originalSha256':sha(raw),'workingSha256':sha(work),'equal':True}
 return raw
T={n:E.fromstring(read('Table.stp','Table/'+n+'.xml')) for n in ['QuestInfo','_TownList','_MapList','_CaseList']}
quest={int(n.get('id')):n for n in T['QuestInfo']};selected={q for q,n in quest.items() if n.get('town')=='2' and n.get('type')=='2'}
assert len(selected)==12
# Follow explicit single-demand graph, not sorted IDs.
front=[q for q in selected if not any(int(d.get('id')) in selected for d in quest[q].findall('Demands/Demand'))];assert len(front)==1
chain=[];qid=front[0]
while qid is not None:
 assert qid not in chain;chain.append(qid);nexts=[q for q in selected if any(int(d.get('id'))==qid for d in quest[q].findall('Demands/Demand'))];assert len(nexts)<=1;qid=nexts[0] if nexts else None
assert set(chain)==selected
boundary=[{'quest':q,'attributes':dict(n.attrib),'demands':[int(d.get('id')) for d in n.findall('Demands/Demand')]} for q,n in quest.items() if q not in selected and any(int(d.get('id'))==chain[-1] for d in n.findall('Demands/Demand'))]
fields={int(quest[q].get('field')) for q in chain if quest[q].get('field')};cases=[n for n in T['_CaseList'] if int(n.get('STAGE')) in fields];scenarios=[];maps={183,199}
for c in cases:
 chartMember='Field/MapFlow/'+c.get('MAPFLOW');clusterMember='Field/Cluster/'+c.get('CLUSTER');chart=E.fromstring(read('Field.stp',chartMember).decode('euc-kr'));cluster=E.fromstring(read('Field.stp',clusterMember).decode('euc-kr'))
 nodes={int(n.get('id')):n for n in chart.findall('NodeList/Node')};paths=[]
 def walk(link,path):
  ident=int(link.get('id'));assert ident not in path;n=nodes[ident];choices=[dict(m.attrib) for m in n.findall('Map')];assert len(choices)==1 and choices[0]['percent']=='100';maps.add(int(choices[0]['id']));item={'sourceNode':ident,'map':int(choices[0]['id']),'nodeTypeRaw':n.get('type'),'editorOnly':{k:n.get(k) for k in ['x','y','arrayx','arrayy']}};children=link.findall('Node')
  if not children:paths.append(path+[item])
  for ch in children:walk(ch,path+[item])
 for link in chart.findall('NodeLink/Node'):walk(link,[])
 assert len(paths)==1
 sets=[{'attributes':dict(s.attrib),'clusters':[{'cluster':int(g.get('ID')),'objects':[dict(model=int(o.get('ID')),preRaw=int(o.get('PRE')),count=int(o.get('COUNT'))) for o in g.findall('OBJECT')]} for g in s.findall('CLUSTER')]} for s in cluster.findall('CLUSTERSET')]
 assert sets and len(sets[0]['clusters'])>=len(paths[0]);ordered=paths[0]
 for i,node in enumerate(ordered):
  g=sets[0]['clusters'][i];node['candidateSelectedCluster']=g['cluster'];node['candidateEncounterModels']=[o['model'] for o in g['objects'] for _ in range(o['count'])]
 scenarios.append({'field':int(c.get('STAGE')),'case':int(c.get('ID')),'mapFlow':c.get('MAPFLOW'),'cluster':c.get('CLUSTER'),'nodes':ordered,'allClusterSets':sets,'preloadIds':[int(n.get('ID')) for n in cluster.findall('PRELOADSET/IMAGE')],'clusterSelectionPolicy':'FIRST_CLUSTER_PER_ORDERED_NODE_SERVER_RECONSTRUCTION_NOT_MEF','caseJoinAuthority':'UNIQUE_QUEST_FIELD_EQUALS_CASE_STAGE_RESOURCE_JOIN_NOT_NATIVE_COMPLETION_RULE'})

def layout(data,town=False):
 # Same complete32-layer descriptor/offset/eof validation as old governance tool.
 assert data[:21]==b'MapTool Reinforce 1.0';version,w,h,wx,wy=struct.unpack_from('<IIIff',data,0x20);assert version in (0,2) and 0<w<=2048 and 0<h<=2048
 blocked=bytearray(w*h);cursor=0x234;layers=[]
 for layer in range(32):
  offset,size,expanded,count=struct.unpack_from('<4I',data,0x34+layer*16)
  if not count:continue
  assert layer in (0,1) and count==w*h and expanded==count*4 and offset==cursor
  z=zlib.decompressobj();raw=z.decompress(data[offset:offset+size]);assert z.eof and not z.unused_data and len(raw)==expanded
  vals=array('I');vals.frombytes(raw)
  for i,v in enumerate(vals):
   if v:blocked[i]=1
  cursor+=size;layers.append({'layer':layer,'offset':offset,'compressedBytes':size,'expandedBytes':expanded,'cells':count,'blockedCells':sum(bool(v) for v in vals)})
 assert [n['layer'] for n in layers]==[0,1] and cursor==len(data)
 prefix=array('I',[0])*((w+1)*(h+1))
 for y in range(h):
  row=0
  for x in range(w):row+=blocked[y*w+x];prefix[(y+1)*(w+1)+x+1]=prefix[y*(w+1)+x+1]+row
 def total(x0,y0,x1,y1):return prefix[y1*(w+1)+x1]-prefix[y0*(w+1)+x1]-prefix[y1*(w+1)+x0]+prefix[y0*(w+1)+x0]
 requested=36 if town else 18;attempts=[];step=2;legal=set()
 for requestedHalf in sorted({requested,18,8,2},reverse=True):
  if requestedHalf>requested:continue
  half=max(1,int(requestedHalf*w/wx)+1)
  legal={(x,y) for y in range(half,h-half,step) for x in range(half,w-half,step) if total(x-half,y-half,x+half+1,y+half+1)==0};attempts.append({'requestedHalfWorld':requestedHalf,'actualHalfWorld':half*wx/w,'legalCandidates':len(legal)})
  if legal:break
 assert legal,'No legal candidate even at2 world-unit reconstruction clearance'
 remaining=set(legal);components=[]
 while remaining:
  seed=min(remaining);remaining.remove(seed);todo=collections.deque([seed]);component={seed}
  while todo:
   x,y=todo.popleft()
   for p in [(x-step,y),(x+step,y),(x,y-step),(x,y+step)]:
    if p in remaining:remaining.remove(p);component.add(p);todo.append(p)
  components.append(component)
 largest=max(components,key=lambda comp:(len(comp),-min((p[0]-w/2)**2+(p[1]-h/2)**2 for p in comp)))
 spawn=min(largest,key=lambda p:((p[0]-w/2)**2+(p[1]-h/2)**2,p[1],p[0]));todo=collections.deque([spawn]);seen={spawn};dist={spawn:0}
 while todo:
  x,y=todo.popleft()
  for p in [(x-step,y),(x+step,y),(x,y-step),(x,y+step)]:
   if p in legal and p not in seen:seen.add(p);dist[p]=dist[(x,y)]+step;todo.append(p)
 portal=max(seen,key=lambda p:(dist[p],p[1],p[0]));world=lambda p:((p[0]+.5)*wx/w,(p[1]+.5)*wy/h)
 sx,sy=world(spawn);px,py=world(portal)
 npcPoints=[]
 if town:
  for point in sorted(seen,key=lambda p:((p[0]-spawn[0])**2+(p[1]-spawn[1])**2,p[1],p[0])):
   nx,ny=world(point)
   if (nx-sx)**2+(ny-sy)**2<20**2 or (nx-px)**2+(ny-py)**2<12**2:continue
   if any((nx-n['x'])**2+(ny-n['y'])**2<12**2 for n in npcPoints):continue
   npcPoints.append({'x':nx,'y':ny})
   if len(npcPoints)==9:break
 return {'version':version,'width':w,'height':h,'worldWidth':wx,'worldHeight':wy,'spawnX':sx,'spawnY':sy,'portalX':px,'portalY':py,'clearHalfWorld':half*wx/w,'clearanceAttempts':attempts,'clearanceReduced':len(attempts)>1,'placementAuthority':'LARGEST_LEGAL_GRID_COMPONENT_RECONSTRUCTION_NOT_MEF_OR_OFFICIAL_PORTAL','candidateCellCount':len(legal),'candidateComponentCount':len(components),'connectedCandidateCells':len(seen),'portalPathWorldCandidate':dist[portal]*wx/w,'candidateTownNpcPoints':npcPoints,'completeLayers':layers,'fullPayloadValidated':True}
A.mkdir(parents=True,exist_ok=True);maprows=[]
for n in T['_MapList']:
 mid=int(n.get('ID'))
 if mid not in maps:continue
 bound=n.get('BOUND')+'.bnd';data=read('Map/BoundMap.stp','BoundMap/'+bound);dest=A/bound
 if dest.exists():assert dest.read_bytes()==data
 else:
  with dest.open('xb') as f:f.write(data)
 maprows.append({'map':mid,'model':n.get('MAP'),'triggerReferenceOnly':n.get('TRIGGER'),'bound':bound,'sha256':sha(data),'assetPath':str(dest.relative_to(R)),**layout(data,mid in [183,199])})
assert len(maprows)==len(maps)
quests=[]
for q in chain:
 n=quest[q];field=int(n.get('field')) if n.get('field') else None;quests.append({'quest':q,'attributes':dict(n.attrib),'giver':int(n.get('giver')),'finisher':int(n.get('finisher')),'demands':[int(d.get('id')) for d in n.findall('Demands/Demand')],'fieldRaw':field,'caseCandidates':[s['case'] for s in scenarios if s['field']==field],'caseDoesNotAuthorizeBattleWithoutScene':True,'nodeSha256':sha(E.tostring(n,encoding='utf-8'))})
csvPath=R/'s00-runtime-dev/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-scenes.csv'
with csvPath.open(encoding='utf-8-sig',newline='') as f:sceneRows=[r for r in csv.DictReader(f) if int(r['quest_id']) in selected]
result={'schema':'ALSMEER_MAINLINE_RESOURCE_BASELINE_V1_NOT_NATIVE_MEF','sourceMembers':list(members.values()),'orderedQuestIds':chain,'quests':quests,'incomingDemands':[d for d in quests[0]['demands'] if d not in selected],'externalSuccessors':boundary,'town2NpcIds':[int(n.get('ID')) for n in T['_TownList'].findall("./TOWN[@ID='2']/NPCLIST/NPC")],'town3NpcIds':[int(n.get('ID')) for n in T['_TownList'].findall("./TOWN[@ID='3']/NPCLIST/NPC")],'goalTownCandidate':3,'goalMapCandidate':199,'goalTownNativeSceneAuthority':'SEPARATE_SCENE_AUDIT_PENDING','scenarios':scenarios,'maps':maprows,'existingT16SceneRows':sceneRows,'existingT16SceneCsvSha256':sha(csvPath.read_bytes()),'excludedTown2NonType2QuestCount':sum(n.get('town')=='2' and n.get('type')!='2' for n in quest.values()),'limitations':['Only QuestInfo town2,type2 and explicit demands choose mainline scope; optional other quest types/Chapter membership do not become required.','MapChart x/y are editor placement, never player world coordinates.','Chart ordering is exact single100% path, but cluster/map relation is explicit reconstructed finite policy.','All candidate positions are bounds-derived reconstruction, not MEF location/waves/official exit design.','GoalTown/scene transition, rewards and success conditions need separate exact consumer/scene and Server policy evidence.']}
D.mkdir(parents=True,exist_ok=True);(D/'resource-baseline.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps({'quests':chain,'scenarios':len(scenarios),'maps':len(maprows),'members':len(members),'existingT16Scenes':len(sceneRows),'assets':str(A)}))
