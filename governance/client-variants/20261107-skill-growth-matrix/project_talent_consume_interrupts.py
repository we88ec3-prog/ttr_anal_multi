"""Exact signed Consume data; no percent-to-absolute conversion or formula."""
from pathlib import Path
import json,sys,hashlib,collections,xml.etree.ElementTree as E
R=Path(r'E:\Tartaros\workspace');D=Path(__file__).parent;P=R/'runtime-observations/2026-11-05-all-skills/all-skills-catalog.json'
c=json.loads(P.read_text(encoding='utf-8-sig'));sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
a,w=Archive(R.parent/'origin/Table.stp'),Archive(R/'Table.stp');sha=lambda b:hashlib.sha256(b).hexdigest()
def node(n):return {'tag':n.tag,'attributes':dict(n.attrib),'children':[node(x) for x in n]}
rows=[];members=[];examined=0
for p in c['practices']:
 if p['category']!='Talent':continue
 examined+=1;raw=a.read(p['source']);root=E.fromstring(raw);cons=root.findall('.//Interrupts/Interrupt[@Type="Consume"]')
 if not cons:continue
 work=w.read(p['source']);assert raw==work and sha(raw)==c['members'][p['source']]['original_sha256']
 members.append({'member':p['source'],'originalSha256':sha(raw),'workingSha256':sha(work),'equal':True})
 practice=root.find('Practice')
 for level in practice.findall('LevelData'):
  for index,i in enumerate(level.findall('Interrupts/Interrupt')):
   if i.get('Type')!='Consume':continue
   cs=i.find('Conditions');conds=list(cs) if cs is not None else [];target=[n for n in conds if n.tag=='Condition' and n.get('Type')=='SkillLevel' and n.get('SkillID') is not None];targets=sorted({int(n.get('SkillID')) for n in target})
   extra=[node(n) for n in conds if n not in target];blocked=[]
   if not targets:blocked.append('NO_EXPLICIT_SKILLLEVEL_SKILLID_CONDITION_DO_NOT_APPLY')
   if len(targets)>1:blocked.append('MULTIPLE_TARGET_CONDITION_OPERATOR_UNRESOLVED')
   if extra:blocked.append('ADDITIONAL_RUNTIME_CONDITIONS_MUST_BE_IMPLEMENTED')
   attrs=dict(i.attrib)
   for k in attrs:assert k in ['Type','HP','SP','MP','Cooltime','HPPercent','SPPercent','MPPercent'],k
   val=lambda name:int(attrs[name]) if name in attrs else None
   rows.append({'role':p['role'],'talentPractice':p['id'],'talentLearnedLevel':int(level.get('Level')),'targetActive':targets[0] if len(targets)==1 else None,'targetActivesRaw':targets,'hpDelta':val('HP'),'spDelta':val('SP'),'mpDelta':val('MP'),'cooltimeDelta':val('Cooltime'),'hpPercentDelta':val('HPPercent'),'spPercentDelta':val('SPPercent'),'mpPercentDelta':val('MPPercent'),'source':p['source'],'interruptIndex':index,'rawAttributes':attrs,'requirements':node(level.find('Requirements')) if level.find('Requirements') is not None else None,'conditionContainerAttributes':dict(cs.attrib) if cs is not None else None,'conditions':[node(n) for n in conds],'allModifiers':[dict(n.attrib) for n in level.findall('Modifiers/Modifier')],'blockedReasons':blocked,'simpleExactTargetCandidate':not blocked,'automaticRuntimeAdmission':False,'authority':'EXACT_CONDITIONAL_RESOURCE_CONSUME_DECLARATION_NOT_NATIVE_FORMULA'})
result={'schema':'tartaros-talent-consume-interrupts-v1','rows':rows,'memberIdentities':members,'scope':{'talentPracticesExamined':examined,'consumeSourceMembers':len(members),'consumeLevelRows':len(rows)},'rules':['Every row requires the declared Talent learned level and all original learning Requirements; metadata is not permission to bypass them.','All Interrupt Conditions must hold; a missing target SkillLevel condition never becomes a global modifier.','A null delta means the source attribute is absent, not an invented zero cost or recovery.','Percent deltas are independent raw fields and must not be passed as absolute SP/MP deltas.','No stacking, percentage base, truncation, minimum cost or event timing formula is inferred.','simpleExactTargetCandidate only classifies source shape; it does not assert native consumer closure.'],'catalogSha256':sha(P.read_bytes())}
(D/'talent-consume-interrupts.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode())
print(json.dumps({**result['scope'],'simpleExactTargetRows':sum(r['simpleExactTargetCandidate'] for r in rows),'blocked':dict(collections.Counter(v for r in rows for v in r['blockedReasons'])),'attributePresence':dict(collections.Counter(k for r in rows for k in r['rawAttributes']))}))
