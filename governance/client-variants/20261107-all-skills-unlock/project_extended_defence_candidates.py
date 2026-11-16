"""Explicit v61 lab composition/level policy. No native Buff grant or damage formula."""
from pathlib import Path
import argparse,hashlib,json
p=argparse.ArgumentParser();p.add_argument('output',type=Path);a=p.parse_args();folder=Path(__file__).parent
def load(name,pin):
    path=folder/name;assert path.resolve()!=a.output.resolve()
    b=path.read_bytes();assert hashlib.sha256(b).hexdigest()==pin;return json.loads(b)['rows']
basepin='e1a10b5ea0fab9eaf52dfaaea46c264f6ce5f3d05aa640db2cb827a22439f419'
extrapin='11c961dddcd26ad1ff4f919e25cf4c1a3d8f8b056884401258d0c6cde310baac'
base=load('named-defensive-buff-text-candidates-v1.json',basepin)
extra=load('four-additional-buff-text-candidates-v1.json',extrapin);rows=[]
def emit(role,active,buff,level):
    n=level['numbersAsWritten'];rows.append({'role':role,'active':active,'activeLevel':level['level'],
        'sourceBuff':buff,'sourceBuffLevel':level['level'],'rawTime':float(level['rawTime']),
        'damageReductionPercent':n.get('damageReductionPercentText',0),
        'maximumReductionPercent':n.get('damageReductionMaximumPercentText'),
        'normalAttackBlocks':n['blockedAttackCountText'] if buff==3 else 0,
        'allAttackBlocks':n['blockedAttackCountText'] if buff in [4,107] else 0,
        'declaredPhysicalAttackIncrease':n.get('physicalAttackIncreaseText',0),
        'declaredAllDefenceIncrease':n.get('allDefenseStatIncreaseText',0),
        'damageRecoveryPercent':n.get('receivedDamageRecoveryPercentText',0),
        'damageRecoveryHits':n.get('attackCountUntilExpireText',0)})
for role,active,buff in [(1,4,1),(2,13,2),(2,15,3),(3,25,4)]:
    g=next(g for g in base if(g['role'],g['active'])==(role,active))
    assert not g['numericOrRawTimeVersionDifferences'] and g['sameNameBuffIdCandidate']==buff
    for level in g['versions'][0]['levels']:emit(role,active,buff,level)
for role,active,buff in [(1,2492,107),(9,1409,86),(5,42,8)]:
    g=next(g for g in extra if(g['role'],g['active'])==(role,active))
    assert not g['numericOrRawTimeDifferences'] and g['sameNameBuffIdCandidate']==buff
    v=g['versions'][0];available={l['activeLevel'] for l in v['allLevelDataToActive']}
    for level in v['buffExplainLevels']:
        if level['level'] not in available or level['level']>5:continue
        emit(role,active,buff,level)
    if active==2492:
        # Full description names both PowerDefence and Defence. Equal level and
        # simultaneous grant are explicit Server lab choices, not native proof.
        normal=next(b for b in base if b['sameNameBuffIdCandidate']==1)
        for level in normal['versions'][0]['levels']:emit(role,active,1,level)
assert len(rows)==40 and not any(r['active']==1297 for r in rows)
doc={'schema':'LOCAL_SKILL_LAB_DEFENCE_V2_NOT_NATIVE_MEF','nativeMef':False,
     'sourceReviewSha256':basepin,'supplementalSourceReviewSha256':extrapin,'rows':rows}
data=(json.dumps(doc,indent=2)+'\n').encode();a.output.write_bytes(data)
print(json.dumps({'rows':len(rows),'sha256':hashlib.sha256(data).hexdigest(),
 'authority':'EXPLICIT_LAB_COMPOSITION_SAME_LEVEL_TIME_SECONDS_AND_DAMAGE_RETURN_POLICY'}))
