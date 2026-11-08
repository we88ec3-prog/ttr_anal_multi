"""Finite228 known ScriptLevel Talent members, all declared levels; no motion mapping."""
from pathlib import Path
import json,hashlib,sys,collections,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
P=Path(__file__).parent;D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();raw=(D/'all-skills-catalog.json').read_bytes()
assert sha(raw)=='5f4d8310037f985047e903b102f5240f12ede24311a9e59a7e7f9366c935d14b'
c=json.loads(raw);practices=[p for p in c['practices'] if any(m.get('Type')=='SkillScriptLevel' for m in p['modifiers'])]
assert len(practices)==228 and {p['role'] for p in practices}==set(range(1,10))
assert all(p['category']=='Talent' for p in practices)
arcs={k:Archive(root/'Table.stp') for k,root in [('original',R.parent/'origin'),('working',R),('taiwan',R.parent/'tc_workspace')]}
sources=[];rows=[];cache={};targetPairs=set();versionDifferences=[];interruptDifferences=[];requirementDifferences=[]
def node(n):
 return dict(tag=n.tag,attributes=dict(n.attrib),children=[node(x) for x in n])
for p in practices:
 member=p['source'];versions=[]
 for key,a in arcs.items():
  if (key,member) not in cache:
   b=a.read(member);cache[key,member]=b;sources.append(dict(version=key,member=member,sha256=sha(b)))
  b=cache[key,member]
  t=next(n for n in E.fromstring(b.decode('utf-8-sig')).findall('Practice') if n.get('ID')==str(p['id']))
  assert t.get('CharID')==str(p['role']) and t.get('Category')=='Talent'
  levels=[]
  for n in t.findall('LevelData'):
   mods=[dict(x.attrib) for x in n.findall('Modifiers/Modifier')];selected=[x for x in mods if x.get('Type')=='SkillScriptLevel']
   for m in selected:
    assert set(m)=={'Type','TargetSkillID','Level'} and 0<int(m['Level'])<65536
    if key=='original':targetPairs.add((p['role'],int(m['TargetSkillID'])))
   levels.append(dict(talentLevel=int(n.get('Level')),scriptLevelModifiers=selected,
    otherModifierCount=len(mods)-len(selected),requirements=[dict(x.attrib) for x in n.findall('Requirements/Require')],
    interruptCount=len(n.findall('Interrupts/Interrupt')),interruptDeclarations=[node(x) for x in n.findall('Interrupts/Interrupt')]))
  assert len({x['talentLevel'] for x in levels})==len(levels)
  versions.append(dict(version=key,levels=levels))
 assert cache['original',member]==cache['working',member]
 sig=lambda v:[(x['talentLevel'],x['scriptLevelModifiers']) for x in v['levels']]
 equal=sig(versions[0])==sig(versions[2])
 interruptsEqual=[(x['talentLevel'],x['interruptDeclarations']) for x in versions[0]['levels']]==[(x['talentLevel'],x['interruptDeclarations']) for x in versions[2]['levels']]
 requirementsEqual=[(x['talentLevel'],x['requirements']) for x in versions[0]['levels']]==[(x['talentLevel'],x['requirements']) for x in versions[2]['levels']]
 if not equal:versionDifferences.append(dict(role=p['role'],talent=p['id']))
 if not interruptsEqual:interruptDifferences.append(dict(role=p['role'],talent=p['id']))
 if not requirementsEqual:requirementDifferences.append(dict(role=p['role'],talent=p['id']))
 canonical=versions[0]['levels'];versionRefs=[]
 for v in versions:
  item=dict(version=v['version'],levelsSha256=sha(json.dumps(v['levels'],sort_keys=True,separators=(',',':')).encode()),sameProjectedLevelsAsOriginal=v['levels']==canonical)
  if v['levels']!=canonical:item['levelsOverride']=v['levels']
  versionRefs.append(item)
 rows.append(dict(role=p['role'],talent=p['id'],nameTc=p['taiwan_name'],member=member,levels=canonical,versions=versionRefs,
  originalWorkingByteEqual=True,krTcScriptModifierProjectionEqual=equal,krTcInterruptProjectionEqual=interruptsEqual,krTcRequirementAttributesEqual=requirementsEqual))
np=D/'numeric-family-explicit-link-audit.json';numeric=json.loads(np.read_bytes())
advanced={(x['role'],x['active']) for x in numeric['matrixSkillTalentRelations']};assert len(advanced)==72
allActive={(p['role'],int(m['active_skill'])) for p in c['practices'] if p['category']=='ActiveSkill' for m in p['skill_level_targets']}
assert targetPairs<=allActive and advanced<=targetPairs
out=dict(schema='RESOURCE_SKILL_SCRIPTLEVEL_TRAITS_V1_NOT_NATIVE_MEF',authority='EXACT_DECLARED_TALENT_LEVEL_PROJECTION_NOT_NATIVE_EXECUTION_OR_MOTION_BINDING',
 sourceCatalogueSha256=sha(raw),advancedTargetIndexSha256=sha(np.read_bytes()),rows=rows,sourceMembers=sources,
 summary=dict(talents=len(rows),roles=9,uniqueRoleActiveTargets=len(targetPairs),knownAdvancedTargetsCovered=len(advanced),
  levels=sum(len(x['levels']) for x in rows),byRole=dict(collections.Counter(x['role'] for x in rows)),
  levelsWithInterruptDeclarations=sum(l['interruptCount']>0 for x in rows for l in x['levels']),
  rawScriptLevelValues=sorted({int(m['Level']) for x in rows for l in x['levels'] for m in l['scriptLevelModifiers']}),
  krTcScriptModifierDifferences=versionDifferences,krTcInterruptDifferences=interruptDifferences,krTcRequirementAttributeDifferences=requirementDifferences,newMotionBindings=0,nativeMef=False),
 limits=['Finite228 members already identified by existing catalogue first-level SkillScriptLevel metadata; no archive inventory/MEF search.',
  'All declared levels projected only for these228 members. Do not claim other Talent files or later-only modifiers absent globally.',
  'Raw requirement attributes and interrupt declaration trees are source metadata, not native condition evaluation/side enums/chance units/payment or complete gameplay behavior.',
  'ScriptLevel differs from ordinary learned/Active level, matrix/tier and animation ID. No ordinal motion mapping.',
  'Companion bounded native cache audit supports default1/MAX bookkeeping only; presentation consumer remains unresolved.',
  'No Client operation/modification, provider retry, automatic grants, new Server behavior or deferred tests.'])
f=D/'skill-scriptlevel-traits-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps(out['summary']));print(sha(f.read_bytes()))
