"""Four explicit lab Active/Buff name hypotheses; not native dispatch or stat formulas."""
from pathlib import Path
import argparse, hashlib, json

p=argparse.ArgumentParser()
p.add_argument('output',type=Path)
a=p.parse_args()
source=Path(__file__).with_name('named-defensive-buff-text-candidates-v1.json')
assert source.resolve()!=a.output.resolve()
raw=source.read_bytes()
expected='e1a10b5ea0fab9eaf52dfaaea46c264f6ce5f3d05aa640db2cb827a22439f419'
assert hashlib.sha256(raw).hexdigest()==expected
groups=json.loads(raw)['rows'];rows=[]
for role,active,buff in [(1,4,1),(2,13,2),(2,15,3),(3,25,4)]:
    g=next(g for g in groups if(g['role'],g['active'])==(role,active))
    assert g['sameNameBuffIdCandidate']==buff and not g['numericOrRawTimeVersionDifferences']
    assert not g['officialActiveBuffDispatchEstablished']
    levels=g['versions'][0]['levels'];assert [v['level'] for v in levels]==[1,2,3,4,5]
    for level in levels:
        n=level['numbersAsWritten']
        rows.append({'role':role,'active':active,'activeLevel':level['level'],
                     'sourceBuff':buff,'sourceBuffLevel':level['level'],
                     'rawTime':float(level['rawTime']),
                     'damageReductionPercent':n.get('damageReductionPercentText',0),
                     'maximumReductionPercent':n.get('damageReductionMaximumPercentText',0),
                     'normalAttackBlocks':n['blockedAttackCountText'] if buff==3 else 0,
                     'allAttackBlocks':n['blockedAttackCountText'] if buff==4 else 0,
                     'declaredPhysicalAttackIncrease':n.get('physicalAttackIncreaseText',0)})
out={'schema':'LOCAL_SKILL_LAB_DEFENCE_V1_NOT_NATIVE_MEF','nativeMef':False,
     'sourceReviewSha256':expected,'rows':rows}
data=(json.dumps(out,indent=2)+'\n').encode();a.output.write_bytes(data)
print(json.dumps({'rows':len(rows),'sha256':hashlib.sha256(data).hexdigest(),
                  'authority':'EXPLICIT_LAB_NAME_MAPPING_SAME_LEVEL_AND_RAW_TIME_AS_SECONDS_POLICY'}))
