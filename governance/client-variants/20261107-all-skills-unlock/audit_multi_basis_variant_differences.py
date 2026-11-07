"""Exact differences for two requested multi-Basis families; no sequence/selection assignment."""
from pathlib import Path
import sys,json,hashlib,re,xml.etree.ElementTree as E,collections
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
arcs={};members=[];carriers=[]
def rd(root,c,n):
 k=(str(root),c)
 if k not in arcs:
  f=root/c;arcs[k]=Archive(f);carriers.append({'root':str(root),'carrier':c,'sha256':sha(f.read_bytes())})
 a=arcs[k];keys=[x for x in a.files if x.casefold()==n.casefold()];assert len(keys)==1;b=a.read(keys[0]);members.append({'root':str(root),'carrier':c,'member':keys[0],'sha256':sha(b)})
 return b
def ori(c,n):
 a,b=rd(O,c,n),rd(R,c,n);assert a==b;return a
def xml(b):return E.fromstring('<ROOT>'+re.sub(r'<\?xml[^?]*\?>','',b.decode('utf-8-sig'))+'</ROOT>')
def flat(node,path='',exclude=False):
 d={path+'/@'+k:v for k,v in node.attrib.items() if not(exclude and node.tag=='AnimationHeader' and k in ['ID','NAME'])}
 if node.text and node.text.strip():d[path+'/#text']=node.text.strip()
 ct=collections.Counter()
 for ch in node:
  idx=ct[ch.tag];ct[ch.tag]+=1;d.update(flat(ch,path+'/'+ch.tag+'['+str(idx)+']',exclude))
 return d
def diffs(maps,labels):
 keys=sorted(set().union(*(d.keys() for d in maps)))
 return [{'path':k,'values':{str(l):m.get(k) for l,m in zip(labels,maps)}} for k in keys if len({m.get(k) for m in maps})>1]
jpath=D/'all-role-motion-joins.json';j=json.loads(jpath.read_text(encoding='utf8'));groups=[]
for role,active,practice,stem,ids in [(1,5,5,'soma_chain',[110,111,112]),(2,19,26,'pipa_grenade',[112,113,114,184])]:
 r=next(r for r in j['roles'] if r['role']==role);ab=xml(ori('Character/Cha/Base.stp',r['abf_member'])).find('.//Character');abrows={int(n.get('ID')):n for n in ab.findall('AnimationList/Animation')}
 pm='Table/Skill/Active/'+stem+'.xml';pt=xml(ori('Table.stp',pm)).find('.//Practice');clips=[];asdMaps=[];effectMaps={};effects=[]
 for mid in ids:
  row=next(m for m in r['motion_metadata'] if m['motion_id']==mid);b=ori(row['asd_carrier'],row['asd_member']);t=xml(b);h=t.find('.//AnimationHeader');am=flat(t,exclude=True);asdMaps.append(am);refs=[]
  for ref in h.findall('Effect'):
   if not ref.get('File') or ref.get('File').lower()=='null':continue
   n=ref.get('Folder','').replace('\\','/')+ref.get('File');refs.append(n)
   if n not in effectMaps:
    eb=ori('Effect/Effect.stp',n);et=xml(eb);fm=flat(et);effectMaps[n]=fm
    structuralCounts=[{'path':k,'value':v} for k,v in fm.items() if re.search('count',k,re.I)]
    selectors=[{'path':k,'value':v} for k,v in fm.items() if re.search('target|phase|sequence|random|select|direction|step',k,re.I)]
    effects.append({'member':n,'sha256':sha(eb),'rootAttributes':dict(list(et)[0].attrib),'elementCount':len(et.findall('.//Element')),'structuralCountFields':structuralCounts,'selectionLikeFields':selectors,'commentsCount':len(re.findall(rb'<!--',eb)),'allAttributeNames':dict(collections.Counter(k for node in et.iter() for k in node.attrib))})
  clips.append({'motion':mid,'asdMember':row['asd_member'],'asdSha256':sha(b),'canonicalExcludingHeaderIdNameSha256':sha(json.dumps(am,sort_keys=True,ensure_ascii=False).encode()),'abfAnimation':dict(abrows[mid].attrib),'animationData':dict(h.find('AnimationData').attrib),'splitRows':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],'effectMembers':refs})
 labels=[]
 for root in [R,TC]:
  sk=xml(rd(root,'Table.stp','Table/skillexplaintable.xml'));px=xml(rd(root,'Table.stp','Table/PracticeExplainTable.xml'));sn=next(n for n in sk.iter('SKILL') if n.get('no')==str(active));pn=next(n for n in px.iter('PRACTICE') if n.get('ID')==str(practice));text=''.join(sn.find('EXPLAIN').itertext());labels.append({'root':str(root),'practiceName':pn.get('NAME'),'shortExplanation':text[:250],'fullExplanationSha256':sha(text.encode())})
 ediff=diffs(list(effectMaps.values()),list(effectMaps));adiff=diffs(asdMaps,ids)
 groups.append({'role':role,'active':active,'practice':practice,'practiceMember':pm,'practiceIdentity':dict(pt.attrib),'practiceModifiers':[dict(n.attrib) for n in pt.findall('LevelData/Modifiers/Modifier')],'textEvidence':labels,'clips':clips,'asdCanonicalDifferencesExcludingHeaderIdName':adiff,'effectResources':effects,'effectCanonicalDifferences':ediff,'effectDiffAttributeCounts':dict(collections.Counter(d['path'].rsplit('/@',1)[-1] for d in ediff)),'selectionRuleFound':False,'selectedMotion':None})
out={'schema':'MULTI_BASIS_VARIANT_DIFFERENCES_V1','authority':'EXACT_RESOURCE_DIFFERENCES_AND_UI_TEXT_NOT_OFFICIAL_VARIANT_SELECTION','inputMotionMetadataSha256':sha(jpath.read_bytes()),'canonicalization':'XML tag-index paths and attributes; meaningful text preserved; whitespace-only text/comments excluded. ASD comparison excludes only AnimationHeader ID/NAME. Root wrapper is synthetic. Missing values remain null.','groups':groups,'conclusions':{'asd':'Both families differ only at Effect/@File after excluding header identity. Split FileID/FPS/StartFrame/EndFrame/Delay and Counter=2 match within each family. All Repeat=false. Counter=2 corresponds to the two declared split rows; no source here interprets it as external variant order.','soma':'EFF01/02/03 differ only Element[10]/@File: ChainZigzag_FrontStayA/B/C. This is an explicit visual component choice, not target-count/direction/random/phase selection proof. Component geometry was not traversed.','pipa':'EFF01/02/03 differ in68 canonical paths, primarily Position/Rotation/Delay/Scale and other visual layout attributes. Motion184 references the same EFF01 as112 and is canonical-equivalent after removing header identity.','sequence':'No target-count, phase/step, random or selector field establishes how Client/Server chooses these motion variants. Asset suffix01/02/03 cannot establish sequential casts or separate action phases.','text':'KR/TC text describes multiple enemies or multiple grenades; it supplies no mapping between those mechanics and the individual variants.'},'serverOwnedComparisonPolicyBoundary':{'allowedCandidate':'An explicit lab-only selector can compare one named full motion/effect variant per cast; record chosen motion and label it Server-owned visual policy, with no official mapping/recovery credit.','mustNotInfer':['Do not queue110->111->112 or112->113->114 as a recovered phase sequence.','Do not select variant by target count/direction/randomness without separate selection evidence.','Do not default to minimum motion or equate suffixnumber with skill level.','Do not use equal timing as equivalence of effects or gameplay hit mechanics.'],'testStatus':'NOT_RUNTIME_TESTED; user normal tests deferred; no new gameplay test performed'},'limits':['Only the seven requested motions, their six unique directly declared EFF members, two Practice members, selected shortKR/TC text. No component/MEF/duration-clock search.','Original/work member bytes checked equal; originals unchanged.','No provider retry, game launch/attachment, Client/Server/Host/shared edits or Git changes.'],'carriers':carriers,'sourceMembers':members}
f=D/'multi-basis-variant-differences-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()));print([(g['role'],len(g['asdCanonicalDifferencesExcludingHeaderIdName']),len(g['effectCanonicalDifferences'])) for g in groups])
