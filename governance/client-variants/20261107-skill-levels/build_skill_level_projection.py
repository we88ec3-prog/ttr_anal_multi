"""Read-only all-role exact PracticeLearnedLevel -> ActiveLevel costs.
Talent SkillScriptLevel is a distinct axis and never assigned an animation.
"""
from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as ET,collections
R=Path(r'E:\Tartaros\workspace');O=R.parent/'origin';D=R/'runtime-observations/2026-11-05-all-skills';OUT=R/'CLIENT/evidence/20261107-skill-levels'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
c=json.loads((D/'all-skills-catalog.json').read_text(encoding='utf-8-sig'))
a,w=Archive(O/'Table.stp'),Archive(R/'Table.stp');identities={}
def read(member):
 raw,wr=a.read(member),w.read(member);assert raw==wr
 if member in c['members']:
  assert sha(raw)==c['members'][member]['original_sha256'] and sha(wr)==c['members'][member]['working_sha256']
 identities[member]={'member':member,'original_sha256':sha(raw),'working_sha256':sha(wr),'matched':True};return raw
activeRoot=ET.fromstring(read('Table/SkillActiveTable.xml'));active={}
for n in activeRoot:
 ident=int(n.get('no'));assert ident not in active;levels={}
 for lev in n.findall('LEVEL'):
  value=int(lev.get('val'));assert value not in levels
  info=lev.find('ACTIVEINFO')
  levels[value]={'info':{key:int(info.get(key,'0')) for key in ['hp','sp','mp','cooltime']} if info is not None else None,
                 'performance':[{'tag':x.tag,'attributes':dict(x.attrib)} for x in lev if x.tag!='ACTIVEINFO']}
 active[ident]=levels
rows=[];ranges=[];unresolved=[];talents=[];practiceSummaries=[]
for p in c['practices']:
 if p['category'] not in ['ActiveSkill','Talent']:continue
 root=ET.fromstring(read(p['source']));pr=root.find('Practice');assert int(pr.get('ID'))==p['id'] and int(pr.get('CharID'))==p['role']
 allowed=[];declared=[];levelProjection=[]
 for level in pr.findall('LevelData'):
  learned=int(level.get('Level'));declared.append(learned)
  modifiers=[dict(m.attrib) for m in level.findall('Modifiers/Modifier')]
  requires=[dict(n.attrib) for n in level.findall('Requirements/Require')]
  if p['category']=='Talent':
   for mod in modifiers:
    if mod.get('Type')=='SkillScriptLevel':talents.append({'role':p['role'],'talentPractice':p['id'],'talentLearnedLevel':learned,'active':int(mod['TargetSkillID']),'scriptLevel':int(mod['Level']),'source':p['source'],'requirements':requires})
   continue
  grants=[m for m in modifiers if m.get('Type')=='SkillLevel'];valid=bool(grants);pending=[]
  for grant in grants:
   skill,activeLevel=int(grant['TargetSkillID']),int(grant['Value']);value=active.get(skill,{}).get(activeLevel)
   if value is None or value['info'] is None:
    valid=False;unresolved.append({'role':p['role'],'practice':p['id'],'learnedLevel':learned,'active':skill,'activeLevel':activeLevel,'issue':'NO_EXACT_ACTIVEINFO_LEVEL'})
    continue
   info=value['info']
   pending.append({'role':p['role'],'practice':p['id'],'learnedLevel':learned,'active':skill,'activeLevel':activeLevel,
                   'hp':-info['hp'],'sp':-info['sp'],'mp':-info['mp'],'rawCooltime':info['cooltime'],'signedRaw':info,
                   'source':p['source'],'authority':'EXACT_ORIGINAL_RESOURCE_LEVEL_JOIN'})
   levelProjection.append({'learnedLevel':learned,'active':skill,'activeLevel':activeLevel,'activeInfo':info,'performance':value['performance'],'requirements':requires})
  if not grants:unresolved.append({'role':p['role'],'practice':p['id'],'learnedLevel':learned,'issue':'NO_SKILLLEVEL_MODIFIER'})
  if valid:allowed.append(learned);rows.extend(pending)
 if p['category']=='ActiveSkill':
  ranges.append({'role':p['role'],'practice':p['id'],'allowedLearnedLevels':sorted(set(allowed)),'maxLearnedLevel':max(allowed) if allowed else None,'declaredLearnedLevels':sorted(set(declared))})
  practiceSummaries.append({'role':p['role'],'practice':p['id'],'source':p['source'],'levels':levelProjection})
keys=[(x['role'],x['practice'],x['learnedLevel'],x['active']) for x in rows];assert len(keys)==len(set(keys))
projection={'schema':'tartaros-active-practice-level-costs-v1','rows':rows,'practiceRanges':ranges,'unresolved':unresolved,
            'levelRule':'Use exact Practice/LevelData@Level then SkillLevel@TargetSkillID and @Value, then ACTIVEINFO LEVEL@val. No numeric-index assumption, clamping or tier/learned-level conflation.',
            'costRule':'hp/sp/mp are consumption=-signed source ACTIVEINFO. rawCooltime is raw source integer; unit not newly proven.','talentsIncluded':False,
            'sourceMemberManifest':'source-members.json','inputCatalogSha256':sha((D/'all-skills-catalog.json').read_bytes())}
OUT.mkdir(parents=True,exist_ok=True)
def save(name,obj):(OUT/name).write_bytes((json.dumps(obj,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
save('active-practice-level-costs.json',projection)
save('practice-level-performance.json',{'schema':'tartaros-practice-level-performance-v1','practices':practiceSummaries,'limitations':['Exact original numeric data only. No original Server formula/animation/multihit authority.']})
save('talent-script-levels.json',{'schema':'tartaros-talent-script-levels-v1','rows':talents,'limitations':['Talent learned level and ScriptLevel are distinct from ActiveSkill learned/cost level and Matrix/Tier.','No direct basis/average/exper/master/super mapping assigned from numeric ScriptLevel.']})
save('source-members.json',list(identities.values()))
# Actual level lookup disagreements are reported, never silently flattened.
summary={'roles':len(set(x['role'] for x in rows)),'active_practices':len(ranges),'level_cost_rows':len(rows),'talent_script_rows':len(talents),'unresolved':len(unresolved),'identity_checked_members':len(identities),'learned_vs_active_level_differences':sum(x['learnedLevel']!=x['activeLevel'] for x in rows),'resource_gain_rows':sum(any(x[k]<0 for k in ['hp','sp','mp']) for x in rows)}
save('summary.json',summary);print(json.dumps(summary));print('runtime_sha256',sha((OUT/'active-practice-level-costs.json').read_bytes()))
