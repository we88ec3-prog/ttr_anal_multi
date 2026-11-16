"""Finite spelling-family candidates, preserving every variant; no official mapping assignment."""
from pathlib import Path
import sys,json,hashlib,re,xml.etree.ElementTree as E,collections
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
arcs={};identities=[];carriers=[]
def rd(root,c,n):
 k=(str(root),c)
 if k not in arcs:
  f=root/c;arcs[k]=Archive(f);carriers.append({'root':str(root),'carrier':c,'sha256':sha(f.read_bytes())})
 a=arcs[k];keys=[x for x in a.files if x.casefold()==n.casefold()];assert len(keys)==1;b=a.read(keys[0]);identities.append({'root':str(root),'carrier':c,'member':keys[0],'sha256':sha(b)})
 return b
def original(c,n):
 a,b=rd(O,c,n),rd(R,c,n);assert a==b;return a
def xml(b):return E.fromstring('<AUDIT>'+re.sub(r'<\?xml[^?]*\?>','',b.decode('utf-8-sig'))+'</AUDIT>')
prior=D/'all-role-motion-joins.json';j=json.loads(prior.read_text(encoding='utf8'))
targets=[(6,49,82,'gren_summ','summon'),(6,54,87,'gren_egrit','egritsoul'),(8,2530,184,'ruko_inducingdagger','idagger')]
groups=[]
texts={root:{n:xml(rd(root,'Table.stp',n)) for n in ['Table/PracticeExplainTable.xml','Table/skillexplaintable.xml']} for root in [R,TC]}
for role,active,practice,stem,family in targets:
 r=next(x for x in j['roles'] if x['role']==role);pm='Table/Skill/Active/'+stem+'.xml';pt=xml(original('Table.stp',pm)).find('.//Practice');assert int(pt.get('ID'))==practice
 tcpt=xml(rd(TC,'Table.stp',pm)).find('.//Practice');labels=[]
 for root in [R,TC]:
  pr=next(n for n in texts[root]['Table/PracticeExplainTable.xml'].iter('PRACTICE') if n.get('ID')==str(practice));sk=next(n for n in texts[root]['Table/skillexplaintable.xml'].iter('SKILL') if n.get('no')==str(active));s=''.join(sk.find('EXPLAIN').itertext())
  labels.append({'root':str(root),'practiceName':pr.get('NAME'),'activeShortExplanation':s[:240],'fullExplanationSha256':sha(s.encode('utf8'))})
 ab=xml(original('Character/Cha/Base.stp',r['abf_member'])).find('.//Character');abrows={int(n.get('ID')):n for n in ab.findall('AnimationList/Animation')};clips=[]
 candidates=[m for m in r['motion_metadata'] if family in m['abf_file'].lower()]
 for row in candidates:
  action=row['motion_id'];abrow=abrows[action];b=original(row['asd_carrier'],row['asd_member']);t=xml(b);h=t.find('.//AnimationHeader');fx=[]
  for ref in h.findall('Effect'):
   if not ref.get('File') or ref.get('File').lower()=='null':continue
   member=ref.get('Folder','').replace('\\','/')+ref.get('File');eb=original('Effect/Effect.stp',member);et=xml(eb)
   timing=[{'tag':n.tag,'attribute':k,'value':v} for n in et.iter() for k,v in n.attrib.items() if re.search('time|delay|repeat|loop|start|end|frame',k,re.I)]
   files=collections.Counter(v for n in et.iter() for k,v in n.attrib.items() if k.lower()=='file')
   semantic=[{'tag':n.tag,'attribute':k,'value':v} for n in et.iter() for k,v in n.attrib.items() if re.search('skill|practice|script|action|motion',k,re.I)]
   variant=re.search(r'-(Basis|Average|Exper|Master|Super)',member,re.I)
   fx.append({'member':member,'sha256':sha(eb),'asdReferenceAttributes':dict(ref.attrib),'declaredVariantLabel':variant[1] if variant else None,'elementFileCounts':dict(files),'timingAttributes':timing,'explicitSkillSemanticAttributes':semantic})
  clips.append({'action':action,'abfAnimation':dict(abrow.attrib),'asdMember':row['asd_member'],'asdSha256':sha(b),'asdHeaderAttributes':dict(h.attrib),'splitRows':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],'effects':fx,'durationAuthority':'RAW_SPLIT_ROWS_ONLY; no duration/cancel formula inferred'})
 groups.append({'role':role,'active':active,'practice':practice,'practiceMember':pm,'practiceIdentity':dict(pt.attrib),'modifiers':[dict(n.attrib) for n in pt.findall('LevelData/Modifiers/Modifier')],'tcPracticeIdentity':dict(tcpt.attrib),'textEvidence':labels,'family':family,'candidates':clips,'selectedMotion':None,'officialMappingResolved':False,'serverOwnedComparisonCandidate':True,'candidateAuthority':'SPELLING/SEMANTIC_FAMILY_AND_RESOURCE_VARIANT_COMPARISON_ONLY_NOT_ACTIVE_DISPATCH','ambiguities':['All variants retained; no minimum-motion or implicit level1 choice.','Basis/Average/Exper/Master/Super in explicit effect filenames identify resource variants, not verified Practice level/ScriptLevel assignment.','Practice modifier links active ID to skill level only; no explicit ASD/action assignment is present.','Server may expose an explicitly labeled comparison candidate but must not count it as recovered official mapping.']})
out={'schema':'THREE_BASIC_SKILL_FAMILY_COMPARISON_V1','authority':'NAMING_AND_TEXT_CANDIDATES_NOT_OFFICIAL_NATIVE_DISPATCH','inputMotionMetadataSha256':sha(prior.read_bytes()),'groups':groups,'summary':{'skills':len(groups),'variantClips':sum(len(g['candidates']) for g in groups),'officialNewMappings':0},'scope':'Only three requested practices, existing matched motion-family rows, original ABFs/ASDs and their directly referenced EFFs, plus selected KR/TC short text. No component/MEF/clock traversal.','limits':['Original/work asset bytes are checked equal, origins remain read-only.','Effects can depict summons/targets rather than caster behavior; no hit count, summon logic, buff mechanics or advanced-level assignment is proven.','No game/provider/attach/Client/Server/Host/shared edit or Git changes.'],'carriers':carriers,'sourceMembers':identities}
f=D/'three-basic-skill-family-comparison-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()));print(out['summary'])
