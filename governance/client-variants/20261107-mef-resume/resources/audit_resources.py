"""Read-only bounded MEF inventory; reuse prior index result on identical carrier."""
from pathlib import Path
import os,sys,hashlib,json,struct,collections,concurrent.futures,xml.etree.ElementTree as E
R=Path(r'E:\Tartaros\workspace');OUT=Path(__file__).parent
sha=lambda b:hashlib.sha256(b).hexdigest()
def filehash(path):
 h=hashlib.sha256()
 with path.open('rb') as f:
  while b:=f.read(4*1024*1024):h.update(b)
 return h.hexdigest()
priorPaths=[R/'anal/native-index/map-trigger-consumers-audit.json',R/'anal/native-index/tc-mef-evidence.json'];kr,tc=[json.loads(p.read_text(encoding='utf-8-sig')) for p in priorPaths]
roots={'original':R.parent/'origin','working':R,'taiwan':Path(r'E:\Tartaros\tc_workspace')}
targets=['scenario_town000.mef','S_pathofpindus01.mef','S_pathofpindus02.mef','town001.mef','town000.mef']
def read_index(path):
 # Read only STPD header + STPI tail; no payload decode or execution.
 with path.open('rb') as f:
  head=f.read(16);assert head[:4]==b'STPD';offset=int.from_bytes(bytes(v^255 for v in head[4:8]),'little');f.seek(offset);tail=f.read()
 assert tail[:4]==b'STPI';data=bytes(v^255 for v in tail);pos=8;names=[]
 def node(parent):
  nonlocal pos
  length=struct.unpack_from('<H',data,pos)[0];pos+=2;name=data[pos:pos+length].decode('ascii').rstrip('\0');pos+=length;kind=data[pos];pos+=1;full='/'.join(filter(None,(parent,name)))
  if kind in [1,2]:
   count=struct.unpack_from('<I',data,pos)[0];pos+=12
   for _ in range(count):node(full)
  elif kind==0:pos+=16;names.append(full)
  else:raise ValueError((kind,pos))
 node('');assert pos==len(data)
 return names
jobs=[]
for label,root in roots.items():
 old=tc if label=='taiwan' else kr
 for entry in old['archiveInventory']:jobs.append((label,root,entry))
def inspect(job):
 label,root,old=job;path=root/old['archive'];base={'root':label,'archive':old['archive'],'priorSha256':old['sha256'],'priorFileCount':old['files']}
 if not path.is_file():return {**base,'status':'MISSING_CARRIER','mefEntries':None}
 digest=filehash(path);same=digest==old['sha256'];names=None if same else read_index(path);hits=old['mefEntries'] if same else [n for n in names if '.mef' in n.casefold()]
 return {**base,'currentSha256':digest,'currentFileCount':old['files'] if same else len(names),'size':path.stat().st_size,'status':'REUSED_PRIOR_MEF_INDEX_RESULT_IDENTICAL_CARRIER' if same else 'REINDEXED_CHANGED_CARRIER','mefEntries':hits,'indexReadThisRun':not same,'targetHits':[{ 'target':t,'exactBasename':[n for n in hits if n.replace('\\','/').rsplit('/',1)[-1]==t],'casefoldBasename':[n for n in hits if n.replace('\\','/').rsplit('/',1)[-1].casefold()==t.casefold()]} for t in targets]}
with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:inventory=list(pool.map(inspect,jobs))
loose=[];walk=[]
for label,root in roots.items():
 dirs=0;files=0;skipped=[]
 for directory,children,names in os.walk(root,followlinks=False):
  dirs+=1
  for child in children[:]:
   p=Path(directory)/child
   if p.is_symlink() or getattr(p.lstat(),'st_file_attributes',0)&0x400:children.remove(child);skipped.append(str(p.relative_to(root)))
  for name in names:
   files+=1
   if Path(name).suffix.casefold()=='.mef':
    p=Path(directory)/name
    if p.is_symlink():continue
    loose.append({'root':label,'relativePath':str(p.relative_to(root)),'size':p.stat().st_size,'sha256':filehash(p)})
 walk.append({'root':label,'directoriesVisited':dirs,'filesVisited':files,'reparseSubtreesSkipped':skipped})
# Reuse a retained KR decoded map member only after its old payload hash matches.
mapPath=R/'anal/resources/_MapList.xml';mapRaw=mapPath.read_bytes();assert sha(mapRaw)==kr['mapListSha256']
mapRows={'krPrior':[dict(n.attrib) for n in E.fromstring(mapRaw)]}
for t in tc['mapTables']:
 if t['entry'].casefold()=='table/_maplist.xml':mapRows['tcPrior']=t['mefRows']
selected={label:[n for n in rows if n.get('TRIGGER','').casefold() in {t.casefold() for t in targets}] for label,rows in mapRows.items()}
triggerNames={label:sorted({n.get('TRIGGER') for n in rows if n.get('TRIGGER','').casefold().endswith('.mef')}) for label,rows in mapRows.items()}
currentMapProof=[]
for label,root in roots.items():
 carrier=next(n for n in inventory if n['root']==label and n['archive']=='Table.stp')
 priorMemberHash=next(t['sha256'] for t in tc['mapTables'] if t['entry'].casefold()=='table/_maplist.xml') if label=='taiwan' else kr['mapListSha256']
 if carrier['indexReadThisRun']:
  sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
  decoded=Archive(root/'Table.stp').read('Table/_MapList.xml');currentHash=sha(decoded);rows=[dict(n.attrib) for n in E.fromstring(decoded)]
  selected[label+'Current']=[n for n in rows if n.get('TRIGGER','').casefold() in {t.casefold() for t in targets}]
 else:currentHash=priorMemberHash;selected[label+'Current']=selected['tcPrior' if label=='taiwan' else 'krPrior']
 currentMapProof.append({'root':label,'member':'Table/_MapList.xml','sha256':currentHash,'equalsPriorMemberHash':currentHash==priorMemberHash,'method':'CHANGED_CARRIER_MEMBER_REVALIDATED' if carrier['indexReadThisRun'] else 'IDENTICAL_CARRIER_REUSE'})
result={'schema':'tartaros-mef-resource-resume-v1','priorEvidence':[{'path':str(p.relative_to(R)),'sha256':sha(p.read_bytes())} for p in priorPaths],'targetNames':targets,'archiveInventory':inventory,'looseMefFiles':loose,'looseWalkScope':walk,'selectedTriggerReferences':selected,'currentMapMemberProof':currentMapProof,'priorTriggerNames':triggerNames,'retainedKrMapMember':{'path':str(mapPath.relative_to(R)),'sha256':sha(mapRaw),'matchesPriorMemberHash':True},'domainSeparation':{'MEF':'_MapList TRIGGER filename references; no sample or format proof from reference alone.','EMF':'Map/environment effect resource domain; .emf is not .mef and is not renamed or treated as a trigger script.','Light':'Lighting resource domain; same stem does not prove MEF behavior or compatibility.'},'limitations':['Only the listed42 KR carriers per original/working and56 TC carriers are indexed; payloads and other carriers are not exhaustively searched.','Identical carriers reuse the prior empty MEF index result; no complete retained index was available to enumerate unrelated EMF/Light members.','Bounded not-found is not absence of MEF throughout the Client, embedded payloads, other versions or official Server.','Loose walk is only three authorized roots and does not follow reparse subtrees.','No native or game launch, attach, rename, resource write, Client/Server edit or Git action.']}
OUT.mkdir(parents=True,exist_ok=True);(OUT/'resource-audit.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode())
summary={'carriers':len(inventory),'unchanged':sum(n['status']=='REUSED_PRIOR_MEF_INDEX_RESULT_IDENTICAL_CARRIER' for n in inventory),'reindexed':sum(n['status']=='REINDEXED_CHANGED_CARRIER' for n in inventory),'missing':sum(n['status']=='MISSING_CARRIER' for n in inventory),'indexedMefHits':sum(len(n['mefEntries'] or []) for n in inventory),'looseMefFiles':len(loose),'targetReferenceCounts':{k:len(v) for k,v in selected.items()}}
(OUT/'summary.json').write_bytes((json.dumps(summary,indent=2)+'\n').encode());print(json.dumps(summary))
