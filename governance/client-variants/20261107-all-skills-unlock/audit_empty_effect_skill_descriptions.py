"""Five matrix skills with no projected ATTACK/HEAL: positive description evidence only."""
from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace');D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
prior=D/'heal-targeting-source-boundary-v1.json';p=json.loads(prior.read_text(encoding='utf8'));expected={(1,4),(2,13),(2,15),(3,25),(4,34)};assert {tuple(x) for x in p['summary']['emptyEffectPairs']}==expected
tables={};ids=[]
for root in [R,O,TC]:
 a=Archive(root/'Table.stp');tables[root]={}
 for member in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml']:
  b=a.read(member);tables[root][member]=E.fromstring(b.decode('utf-8-sig'));ids.append({'root':str(root),'member':member,'sha256':sha(b)})
for member in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml']:
 assert next(x['sha256'] for x in ids if x['root']==str(R) and x['member']==member)==next(x['sha256'] for x in ids if x['root']==str(O) and x['member']==member)
review={
 4:{'category':'SELF_DAMAGE_REDUCTION_BUFF','positiveText':'Both KR/TC explicitly give caster a defense buff reducing damage received when hit.','notEstablished':'No duration, reduction percentage, stack/refresh rule, attack event or reflected/counter damage formula established.'},
 13:{'category':'SELF_DAMAGE_REDUCTION_AND_PHYSICAL_ATTACK_BUFF','positiveText':'Both versions reduce damage received and increase physical attack while buff persists. Increased physical attack is a modifier to later attacks, not a direct hit declared by this cast.','notEstablished':'No reduction/additive multiplier, duration or later-attack interaction formula established.'},
 15:{'category':'SELF_AND_NEARBY_ALLY_FINITE_HIT_BLOCK_BUFF','positiveText':'KR grants caster/allies a barrier blocking a specified number of ordinary bullets and normal attacks; TC more generally says block a fixed number of attacks.','notEstablished':'No exact block count/duration, projectile categories, HP absorption pool, reflection or counterattack established. Do not silently widen KR ordinary-attack restriction to all hits.'},
 25:{'category':'SELF_FINITE_COUNT_ALL_ATTACK_BLOCK_BUFF','positiveText':'KR explicitly says completely block a specified number of all attacks; TC says fixed number of attacks.','notEstablished':'No exact count/duration, block event timing, HP absorption pool, reflected/counter damage established.'},
 34:{'category':'SELF_EVASION_CHANCE_BUFF','positiveText':'Both versions explicitly increase evasion while buff persists.','notEstablished':'No evasion percentage, hit-roll formula, duration, counterattack trigger or direct damage declared.'}
}
rows=[]
for role,aid in sorted(expected):
 vs=[]
 for root in [R,TC]:
  ac=next(n for n in tables[root]['Table/SkillActiveTable.xml'] if n.get('no')==str(aid));ex=next(n for n in tables[root]['Table/skillexplaintable.xml'] if n.get('no')==str(aid));text=''.join(ex.find('EXPLAIN').itertext());levels=[{'level':dict(l.attrib),'declaredKinds':[c.tag for c in l],'attackHealTags':[{'tag':c.tag,'attributes':dict(c.attrib)} for c in l if c.tag in ['ATTACK','HEAL']]} for l in ac.findall('LEVEL')];assert not any(l['attackHealTags'] for l in levels)
  vs.append({'root':str(root),'activeIdentity':dict(ac.attrib),'fullExplainText':text,'textUtf8Sha256':sha(text.encode()),'levelDeclarations':levels})
 rows.append({'role':role,'active':aid,'effectKinds':[],'descriptionReview':review[aid],'versions':vs,'directAttackDeclaredInDescription':False,'counterOrReflectionDeclaredInDescription':False,'gameplayZeroEffectProven':False})
out={'schema':'EMPTY_EFFECT_FIVE_DESCRIPTION_BOUNDARY_V1','authority':'POSITIVE_FULL_KR_TC_DESCRIPTION_EVIDENCE_NOT_NATIVE_BUFF_MECHANICS','priorSourceEffectReview':{'file':prior.name,'sha256':sha(prior.read_bytes())},'rows':rows,'conclusion':'All five have affirmative defensive/support buff descriptions. None describes this cast as a direct hit or counter/reflection. This positive description evidence supports a distinct lab buff/unimplemented branch rather than generic cast damage; absence of ATTACK/HEAL alone never proves the skill has no effect.','policyBoundary':['No automatically applied generic attack damage for these five based solely on empty effect arrays.','No invented buff magnitude/count/duration, absorbHP, counterattack or guaranteed evasion; mark mechanics unimplemented or explicitly Server-owned calibration.','A skill can alter damage dealt/received by later combat events despite having no directATTACK tag.','This does not claim all native effects or script-side damage paths have been excluded.'],'limits':['Known Table members only; no native/provider/game/Host/Client/Server/shared/Git actions.'],'sourceMembers':ids}
f=D/'empty-effect-five-description-boundary-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()))
