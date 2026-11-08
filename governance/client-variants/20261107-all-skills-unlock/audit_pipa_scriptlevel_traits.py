"""Two known Pipa Talent/Active Practice pairs; no animation-order inference."""
from pathlib import Path
import hashlib,json,sys,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
P=Path(__file__).parent;D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
roots={'original':R.parent/'origin','working':R,'taiwan':R.parent/'tc_workspace'}
archives={key:Archive(root/'Table.stp') for key,root in roots.items()};sources=[]
def read(member):
 data={key:a.read(member) for key,a in archives.items()};assert data['original']==data['working']
 sources.extend(dict(version=key,member=member,sha256=sha(b)) for key,b in data.items())
 return {key:E.fromstring(b.decode('utf-8-sig')) for key,b in data.items()}
catalogueRaw=(D/'all-skills-catalog.json').read_bytes()
assert sha(catalogueRaw)=='5f4d8310037f985047e903b102f5240f12ede24311a9e59a7e7f9366c935d14b'
catalogue=json.loads(catalogueRaw);rows=[]
for tid,aid,pid,stem,levels in [(1227,19,26,'pipa_27',[2,3]),(1251,2996,217,'pipa_51',[2,3,4])]:
 talentMember=f'Table/Skill/Talent/{stem}.xml'
 # The old member name comes from the pinned source catalogue, never a path guess.
 activeMember=next(x['source'] for x in catalogue['practices'] if x['role']==2 and x['id']==pid and x['category']=='ActiveSkill')
 talent=read(talentMember);active=read(activeMember);versions=[]
 for key in roots:
  t=talent[key].find('Practice');p=active[key].find('Practice')
  assert (int(t.get('ID')),int(t.get('CharID')),t.get('Category'))==(tid,2,'Talent')
  assert (int(p.get('ID')),int(p.get('CharID')),p.get('Category'))==(pid,2,'ActiveSkill')
  lv=[]
  for n in t.findall('LevelData'):
   mods=[dict(x.attrib) for x in n.findall('Modifiers/Modifier')]
   assert len(mods)==1 and mods[0]['Type']=='SkillScriptLevel' and int(mods[0]['TargetSkillID'])==aid
   assert not list(n.findall('Interrupts/Interrupt'))
   lv.append(dict(talentLevel=int(n.get('Level')),scriptLevel=int(mods[0]['Level']),modifiers=mods,
    requirements=[dict(x.attrib) for x in n.findall('Requirements/Require')]))
  assert [x['scriptLevel'] for x in lv]==levels
  learned=[]
  for n in p.findall('LevelData'):
   mods=[dict(x.attrib) for x in n.findall('Modifiers/Modifier')]
   assert mods==[{'Type':'SkillLevel','TargetSkillID':str(aid),'Value':n.get('Level')}]
   learned.append(dict(learnedLevel=int(n.get('Level')),activeLevel=int(mods[0]['Value'])))
  versions.append(dict(version=key,talentIdentity=dict(t.attrib),talentLevels=lv,activePracticeIdentity=dict(p.attrib),learnedLevels=learned))
 rows.append(dict(talent=tid,active=aid,practice=pid,talentMember=talentMember,activeMember=activeMember,versions=versions))
companions=[dict(file='cache-consumer/'+name,sha256=sha((P/'cache-consumer'/name).read_bytes())) for name in ['README.md','findings.json','cache-scriptlevel-max-windows.txt']]
out=dict(schema='PIPA_SCRIPTLEVEL_TRAIT_BOUNDARY_V1',sourceCatalogueSha256=sha(catalogueRaw),scope='Two exact known Talent/Active pairs, original/working/Taiwan member comparison only',rows=rows,sourceMembers=sources,companions=companions,
 priorNativeBoundary='Existing bounded cache audit: ordinary level word+4 differs from scriptLevel word+6; default scriptLevel1 and unsigned MAX(existing,modifier) at826114..826123. This audit does not re-run or widen the native consumer claim.',
 conclusions=['Talent1227 targets ONLYold19 with scriptLevels2/3; Talent1251 targets ONLY2996 with2/3/4. No cross-ID fallback.',
  'Old Active19 Practice grants SkillLevel1..6; strengthened2996 grants1..5. Neither is SkillScriptLevel.',
  'Neither two Talent members nor Active Practice members declares an animation/motion ID.',
  'Do not equate4 EFF variants with scriptLevels1..4 or assign them from ordinal coincidence.'],
 unknowns=['Actual ScriptLevel-to-motion/phase selector and native gameplay producer remain unresolved.',
  'Requirement consumption/enforcement, learned-Talent grants and visual/payload behavior are not tested here.',
  'No Client execution/attachment/change, native provider retry, MEF search, full inventory scan or new Server binding.'])
f=D/'pipa-scriptlevel-trait-boundary-v1.json';f.write_text(json.dumps(out,indent=2)+'\n',encoding='utf8');print(sha(f.read_bytes()))
