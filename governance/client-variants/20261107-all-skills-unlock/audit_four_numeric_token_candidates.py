"""Four finite token hypotheses reusing prior declaredFiles; no numeric-order skill assignment."""
from pathlib import Path
import sys,json,hashlib,re,xml.etree.ElementTree as E,collections
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace');D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};members=[];carriers=[]
def rd(root,c,n):
 k=(str(root),c)
 if k not in arcs:
  f=root/c;arcs[k]=Archive(f);carriers.append({'root':str(root),'carrier':c,'sha256':sha(f.read_bytes())})
 a=arcs[k];names=[x for x in a.files if x.casefold()==n.casefold()];assert len(names)==1;b=a.read(names[0]);members.append({'root':str(root),'carrier':c,'member':names[0],'sha256':sha(b)})
 return b
def ori(c,n):
 a,b=rd(O,c,n),rd(R,c,n);assert a==b;return a
def xml(b):return E.fromstring('<ROOT>'+re.sub(r'<\?xml[^?]*\?>','',b.decode('utf-8-sig'))+'</ROOT>')
af=D/'numeric-family-explicit-link-audit.json';audit=json.loads(af.read_text(encoding='utf8'));jf=D/'all-role-motion-joins.json';j=json.loads(jf.read_text(encoding='utf8'));effprior={e['member']:e for e in audit['referencedEffectStructures']}
tables={root:{n:xml(rd(root,'Table.stp',n)) for n in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml','Table/PracticeExplainTable.xml']} for root in [R,TC]}
cfg=[(4,8,3018,239,'isla_BladesExtinction','extinction'),(8,7,3041,262,'ruko_DanceSurigeom','dancesuri'),(9,5,3047,268,'Epds_HolySpiritShield','holyshield'),(2,3,2997,218,'pipa_DefinitionMoloto','c_pipa_firebottle')]
groups=[]
for role,family,active,pid,stem,token in cfg:
 r=next(x for x in j['roles'] if x['role']==role);families=[x for x in audit['numericFamilyRows'] if x['role']==role and x['numericFamily']==family];ids={x['motion'] for x in families};ab=xml(ori('Character/Cha/Base.stp',r['abf_member'])).find('.//Character');abrows={int(n.get('ID')):n for n in ab.findall('AnimationList/Animation')};clips=[];pm='Table/Skill/Active/'+stem+'.xml';pr=xml(ori('Table.stp',pm)).find('.//Practice');assert int(pr.get('ID'))==pid
 versions=[]
 for root in [R,TC]:
  pt=pr if root==R else xml(rd(root,'Table.stp',pm)).find('.//Practice');act=next(n for n in tables[root]['Table/SkillActiveTable.xml'].iter('SKILL') if n.get('no')==str(active));exp=next(n for n in tables[root]['Table/skillexplaintable.xml'].iter('SKILL') if n.get('no')==str(active));pn=next(n for n in tables[root]['Table/PracticeExplainTable.xml'].iter('PRACTICE') if n.get('ID')==str(pid));text=''.join(exp.find('EXPLAIN').itertext());versions.append({'root':str(root),'practiceIdentity':dict(pt.attrib),'skillLevelTargets':[dict(n.attrib) for n in pt.findall('LevelData/Modifiers/Modifier') if n.get('Type')=='SkillLevel'],'activeIdentity':dict(act.attrib),'level1Info':[{'tag':n.tag,'attributes':dict(n.attrib)} for n in act.findall('LEVEL')[0]],'practiceName':pn.get('NAME'),'shortExplanation':text[:250],'fullExplanationSha256':sha(text.encode('utf8'))})
 for m in r['motion_metadata']:
  if m['motion_id'] not in ids:continue
  b=ori(m['asd_carrier'],m['asd_member']);h=xml(b).find('.//AnimationHeader');effects=[]
  for ref in h.findall('Effect'):
   if not ref.get('File') or ref.get('File').lower()=='null':continue
   ef=ref.get('Folder','').replace('\\','/')+ref.get('File');eb=ori('Effect/Effect.stp',ef);et=xml(eb);files=sorted({v for n in et.iter() for k,v in n.attrib.items() if k.lower() in ['file','name']});assert files==effprior[ef]['declaredFiles']
   effects.append({'member':ef,'sha256':sha(eb),'priorDeclaredFilesRechecked':True,'hypothesisTokenMatches':[f for f in files if token in f.lower()],'declaredFiles':files,'selectionLikeAttributes':[{'tag':n.tag,'attribute':k,'value':v} for n in et.iter() for k,v in n.attrib.items() if re.search('skill|practice|phase|random|select|target',k,re.I)]})
  clips.append({'motion':m['motion_id'],'abfAnimation':dict(abrows[m['motion_id']].attrib),'asdMember':m['asd_member'],'asdSha256':sha(b),'animationData':dict(h.find('AnimationData').attrib),'rawSplitRows':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],'effects':effects})
 # Countercheck only already named-role-motion explicit effect references, not an archive inventory search.
 oldrefs={}
 for m in r['motion_metadata']:
  if re.fullmatch(r'[A-Za-z]+_\d+-\d+\.asd',m['abf_file'],re.I):continue
  for f in m['effects']:oldrefs.setdefault(f['path'],[]).append(m['motion_id'])
 checked=[];hits=[]
 for ef,mids in sorted(oldrefs.items()):
  eb=ori('Effect/Effect.stp',ef);et=xml(eb);matching=sorted({v for n in et.iter() for k,v in n.attrib.items() if k.lower()=='file' and token in v.lower()});checked.append({'member':ef,'sha256':sha(eb),'motionRefs':mids})
  if matching:hits.append({'member':ef,'motionRefs':mids,'files':matching})
 groups.append({'role':role,'numericFamily':family,'active':active,'practice':pid,'practiceMember':pm,'hypothesisToken':token,'versions':versions,'clips':clips,'oldNamedMotionComponentCountercheck':{'scope':'Existing role motion metadata only, excluding numeric ASD basenames; read only explicit EFF refs','checkedCount':len(checked),'checked':checked,'tokenReuseHits':hits},'classification':'SEMANTIC_COMPONENT_CANDIDATE_NOT_ID_TO_ACTION_BRIDGE','selectedMotion':None,'officialMappingResolved':False,'boundary':['Practice/Active IDs and texts are explicit; relation to numeric motion family remains a naming/component semantic hypothesis.','No family-number-to-skill-position inference or minimum/variant selection.','No token reuse in this named-role scope does not prove global uniqueness.','Variant-specific absence of token stays visible; family membership alone does not prove same skill or level assignment.']})
out={'schema':'FOUR_NUMERIC_TOKEN_CANDIDATES_V1','authority':'FINITE_COMPONENT_TOKEN_AND_EXPLANATION_HYPOTHESES_NOT_OFFICIAL_DISPATCH','priorAuditSha256':sha(af.read_bytes()),'motionMetadataSha256':sha(jf.read_bytes()),'scope':'Reuse prior numeric declaredFiles projection. Recheck only16 requested family clips/ASDs and their explicit EFFs, four Practice/Active/text records; old-reuse countercheck only explicit EFF refs of already named motions for the four roles. No294-family rescan or full-archive search.','groups':groups,'summary':{'skills':len(groups),'familyClips':sum(len(g['clips']) for g in groups),'oldNamedEffectRefsChecked':sum(g['oldNamedMotionComponentCountercheck']['checkedCount'] for g in groups),'oldComponentReuseHits':sum(len(g['oldNamedMotionComponentCountercheck']['tokenReuseHits']) for g in groups),'newOfficialMappings':0},'policyCandidateBoundary':'Root may review each full named motion as an explicit Server-owned lab comparison candidate, keeping ID/variant selection and mechanics separate. No automatic unlock, tier/level/phase assignment, damage/buff/AI behavior or native-completion credit follows from token names.','limits':['Ruko7 variants2/3/4 lack the literal dancesuri component token present in variant1 and have different split row sequences; do not hide that difference.','Reuse countercheck does not read component geometry or native dispatch.','No duration-clock/MEF/provider/game/attachment investigation.','No Client/Server/Host/shared changes or Git actions; only new evidence/script.'],'carriers':carriers,'sourceMembers':members}
f=D/'four-numeric-token-candidates-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()));print(out['summary'])
