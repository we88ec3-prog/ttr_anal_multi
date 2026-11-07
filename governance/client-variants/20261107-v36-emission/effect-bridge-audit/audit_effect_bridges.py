"""Bounded EFF schema extension; unassigned filename leads never become bindings."""
from pathlib import Path
import json,hashlib,sys,collections,xml.etree.ElementTree as E
R=Path(r'E:\Tartaros\workspace');D=Path(__file__).parent;source=R/'runtime-observations/2026-11-05-all-skills/all-role-motion-joins.json';sha=lambda b:hashlib.sha256(b).hexdigest();j=json.loads(source.read_text(encoding='utf-8-sig'))
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
# These are investigation leads already present in motion metadata, not aliases.
leads=[(1,1,list(range(101,107))),(1,3,[113]),(1,6,[114]),(2,10,list(range(101,106))),(2,14,[108]),(2,18,[115]),(3,471,[116]),(5,38,list(range(101,106))),(5,44,[113]),(6,49,[105]),(6,54,[108]),(7,332,[101]),(8,2530,[164]),(1,5,[110,111,112]),(2,19,[112,113,114,184])]
original=Archive(R.parent/'origin/Effect/Effect.stp');working=Archive(R/'Effect/Effect.stp');seen={};rows=[]
for role,active,ids in leads:
 roledata=next(r for r in j['roles'] if r['role']==role);members=[]
 for mid in ids:
  m=next(m for m in roledata['motion_metadata'] if m['motion_id']==mid)
  for ef in m['effects']:
   path=ef['path'];members.append(path)
   if path in seen:continue
   rb,wb=original.read(path),working.read(path);assert rb==wb and sha(rb)==ef['sha256'];root=E.fromstring(rb.decode('euc-kr'));tags=collections.Counter(n.tag for n in root.iter());attrs=collections.Counter(k for n in root.iter() for k in n.attrib)
   bridge=[{'tag':n.tag,'key':k,'value':v} for n in root.iter() for k,v in n.attrib.items() if any(t in k.lower() for t in ['skill','motion','animation','alias','next','transition','target'])]
   seen[path]={'member':path,'originalSha256':sha(rb),'workingSha256':sha(wb),'byteEqual':True,'tagCounts':dict(tags),'attributeCounts':dict(attrs),'explicitBridgeFields':bridge,'referencedFileExtensions':dict(collections.Counter(Path(n.get('File')).suffix.lower() for n in root.iter() if n.get('File')))}
 rows.append({'role':role,'active':active,'unassignedMotionLeads':ids,'effectMembers':sorted(set(members)),'bindingPromoted':False,'authority':'UNASSIGNED_FILENAME_LEADS_ONLY'})
result={'schema':'SKILL_BRIDGE_V36_BOUNDED_EFFECT_SCHEMA_AUDIT','sourceMotionJoinSha256':sha(source.read_bytes()),'scope':{'oldNamingGaps':13,'nonEquivalentFamilies':2,'uniqueEffectMembers':len(seen)},'rows':rows,'effects':list(seen.values()),'bridgeFieldCount':sum(len(e['explicitBridgeFields']) for e in seen.values()),'promotedMappings':0,'limitations':['Unassigned motion leads are not verified skill-to-motion links.','EFF schema effects are presentation resources, not gameplay timing/target/skill ownership proof.','Only enumerated exact members audited; not an archive-wide or whole-program absence assertion.','No original files modified; no Client execution/attachment or Server patch.']}
(D/'findings.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({k:result[k] for k in ['scope','bridgeFieldCount','promotedMappings']}))


