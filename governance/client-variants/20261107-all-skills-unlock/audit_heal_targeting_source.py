"""SourceEffect1448 + exact Table explanations; source-only heal/attack classification boundary."""
from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as E,collections
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace');D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
sourcePath=R/'s00-runtime-dev/governance/client-variants/20261107-all-skills-unlock/source-effect-coefficients.json';src=json.loads(sourcePath.read_text(encoding='utf8'));assert len(src['rows'])==1448
catalogPath=D/'all-skills-catalog.json';cat=json.loads(catalogPath.read_text(encoding='utf8'))
pairs={(c['role'],m['active_skill']) for c in cat['characters'] for m in c['matrix_entries'] if 1<=m['column']<=6 and m['active_skill']};assert len(pairs)==243
by=collections.defaultdict(list)
for r in src['rows']:by[(r['role'],r['active'])].append(r)
assert pairs<=by.keys()
classes=[];pure=[];mixed=[];empty=[];unstable=[]
for role,aid in sorted(pairs):
 rs=by[(role,aid)];kinds=sorted({e['kind'] for r in rs for e in r['effects']});signatures={tuple(sorted(e['kind'] for e in r['effects'])) for r in rs}
 row={'role':role,'active':aid,'effectKinds':kinds,'projectedLearnedLevelRows':len(rs),'allLevelsSameKindSet':len(signatures)==1}
 classes.append(row)
 if not kinds:empty.append((role,aid))
 if kinds==['HEAL']:pure.append((role,aid))
 if kinds==['ATTACK','HEAL']:mixed.append((role,aid))
 if len(signatures)>1:unstable.append({'role':role,'active':aid,'kindSets':list(signatures)})
arcs={root:Archive(root/'Table.stp') for root in [R,O,TC]};members=[];tables={}
for root in [R,O,TC]:
 tables[root]={}
 for name in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml']:
  b=arcs[root].read(name);members.append({'root':str(root),'member':name,'sha256':sha(b)});tables[root][name]=E.fromstring(b.decode('utf-8-sig'))
assert sha(arcs[R].read('Table/SkillActiveTable.xml'))==src['originalSha256']==sha(arcs[O].read('Table/SkillActiveTable.xml'))
assert arcs[R].read('Table/skillexplaintable.xml')==arcs[O].read('Table/skillexplaintable.xml')
activeMaps={root:{int(n.get('no')):n for n in tables[root]['Table/SkillActiveTable.xml']} for root in tables}
# Verify the effect coefficients, preserving source directions/levels, not a damage/heal formula.
for r in src['rows']:
 n=next(n for n in activeMaps[R][r['active']].findall('LEVEL') if int(n.get('val'))==r['activeLevel'])
 actual=[{'kind':c.tag,'ratio':int(c.get('ratio')) if c.get('ratio') is not None else None,'revision':int(c.get('rev')) if c.get('rev') is not None else None} for c in n if c.tag in ['ATTACK','HEAL']]
 assert actual==r['effects']
direct={43,46,50,51,53,2518}
notes={
 43:('SELF_INCLUDED_NON_PERSISTENT_DESCRIPTION','Explicit self and nearby allies HP recovery; no persistent field in description. Charge prerequisite retained; exact cast/impact timing unknown.'),
 46:('SELF_INCLUDED_NON_PERSISTENT_DESCRIPTION','Self and allies in circle HP recovery plus cleanse/resistance buff; do not implement only a generic HP amount and claim completeness.'),
 50:('SELF_INCLUDED_NON_PERSISTENT_DESCRIPTION','Self and range allies; TC explicitly says instant HP recovery. Still no native numeric/time formula follows.'),
 51:('SELF_ONLY_NON_PERSISTENT_DESCRIPTION','Explicit caster HP recovery; a narrowly supported lab self-heal candidate.'),
 53:('SELF_INCLUDED_NON_PERSISTENT_DESCRIPTION','Explicit self and nearby allies HP recovery; prerequisite, radius, targeting and arrival timing separate.'),
 2518:('SELF_INCLUDED_RECOVERY_ORB','Explicit self and allies recovery orbs. Self can be a recipient, but projectile impact/arrival time is not proven cast-instant.'),
 478:('PERSISTENT_HEALING_FIELD','KR explicitly self/allies gradually recover inside field; TC says team gradually. Do not flatten to one immediate self heal.'),
 3024:('PERSISTENT_FIELD_PLUS_OUTSIDE_ALLY_GUIDED_HEAL','KR/TC gradually heal caster/allies within field; KR additionally sends guided heal outside field. Not immediate self heal.'),
 481:('LOWEST_HP_ALLY_PROJECTILE_AND_CLEANSE','KR first selects lowestHP ally in range, then caster/hit ally/nearby allies heal+earth/killing cleanse. TC includes 지속/continuous wording. Selection and arrival must not be replaced by unconditional immediate self heal.'),
 2511:('ALLY_CHAIN_HEAL','Orb first targets ally and chains from ally location; no explicit caster inclusion and no shortcut unconditional self-target.'),
 1407:('SUPPORT_BUFF_AND_NEARBY_ALLY_HEAL_TEXT_CONFLICT','KR grants support buffs, accuracy and an encouragement field healing nearby allies. TC adds selfHP cost and attack increase. Both level1 ACTIVEINFO hp0/mp-110. Neither source permits assuming cast-instant selfHP heal; do not inventHP sacrifice fromTC prose.'),
 3021:('MIXED_ATTACK_AND_SELF_PLUS_ALLY_HEAL','Attacks enemies and heals caster plus3 allies with cleanse/resistance. Need separate target sets and mechanics.'),
 3052:('MIXED_LOWEST_HP_ALLY_PROJECTILE_WITH_NEARBY_ENEMY_ATTACK','KR selects lowestHP ally orb, impact attacks nearby enemies and heals caster/hit ally/nearby allies with knockback-resistance buff. Do not flatten to immediate untargeted self heal.'),
 3043:('MIXED_TAGS_BUT_DESCRIPTION_SP_REGEN_BUFF','ATTACK+HEAL tags exist, yet KR/TC descriptions state enemy ice attack and persistentSP recovery buff. HEAL tag alone does not prove HP recovery; do not route itsHEAL coefficient toHP without independent mechanics evidence.')
}
details=[]
for role,aid in sorted(set(pure+mixed+empty)):
 versions=[]
 for root in [R,TC]:
  n=activeMaps[root][aid];e=next(n for n in tables[root]['Table/skillexplaintable.xml'] if int(n.get('no'))==aid);text=''.join(e.find('EXPLAIN').itertext());first=n.findall('LEVEL')[0]
  versions.append({'root':str(root),'name':n.get('name'),'activeIdentity':dict(n.attrib),'fullExplainText':text,'explainUtf8Sha256':sha(text.encode('utf8')),'firstLevel':dict(first.attrib),'firstLevelDeclarations':[{'tag':c.tag,'attributes':dict(c.attrib)} for c in first]})
 kind,comment=notes.get(aid,('NO_ATTACK_HEAL_TAGS_IN_PROJECTION','No ATTACK/HEAL declaration in source projection does NOT prove no gameplay effect. Buffs, movement, protection or external scripts may apply.'))
 rs=by[(role,aid)];details.append({'role':role,'active':aid,'effectKinds':sorted({e['kind'] for r in rs for e in r['effects']}),'classification':kind,'review':comment,'selfIncludedNonPersistentLabCandidate':aid in direct,'sourceRows':[{'practice':r['practice'],'learnedLevel':r['learnedLevel'],'activeLevel':r['activeLevel'],'effects':r['effects']} for r in rs],'versions':versions})
out={'schema':'HEAL_TARGETING_SOURCE_BOUNDARY_V1','authority':'EXACT_EFFECT_TAG_PROJECTION_PLUS_FULL_DESCRIPTIONS_NOT_NATIVE_TARGETING_OR_FORMULA','sourceProjection':{'path':str(sourcePath.relative_to(R)),'sha256':sha(sourcePath.read_bytes()),'rows':1448,'allRowsRecheckedAgainstOriginalKrActiveXml':True},'matrixScope':{'catalogSha256':sha(catalogPath.read_bytes()),'definition':'Unique nonzero(role,active) keys in exact matrix columns1..6; V/Tab special columns excluded','uniquePairs':243},'summary':{'pureHealPairs':pure,'mixedAttackHealPairs':mixed,'emptyEffectPairs':empty,'allLevelKindSetChanges':unstable,'selfIncludedNonPersistentCandidates':sorted(direct),'instantNativeTimingConfirmed':False},'matrixActiveClassification':classes,'targetingAndTextReview':details,'policyBoundary':['Do not route pureHEAL skills to generic monster damage.','Six self-included candidates support explicit lab healing policy only;2518 remains an orb and no universal cast-instant timing is proven.','478/3024 gradual fields,481/3052 lowestHP ally orbs,2511 ally chain,1407 support field require separate targeting/timing; none is generic instantaneous self heal.','HEAL coefficient is not proof of HP rather thanSP, periodicity, recipient or target selection;3043 is an explicit warning case.','MissingATTACK/HEAL tags are absence in this source projection only, not proof of zero gameplay effects.','Server-owned calibration amount/radius/delay must be named as custom policy, not a recovered native combat formula.','No negative tests, Host/game execution, provider retries, Client/Server/shared edits or Git actions.'],'sourceMembers':members}
f=D/'heal-targeting-source-boundary-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()));print(out['summary'])
