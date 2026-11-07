"""Three explicitly accepted component-stem lab hypotheses, not numeric mapping."""
from pathlib import Path
import argparse,hashlib,json
p=argparse.ArgumentParser();p.add_argument('bindings',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
assert a.bindings.resolve()!=a.output.resolve()
raw=Path(__file__).with_name('numeric-anchor-cycle-review.json').read_bytes()
assert hashlib.sha256(raw).hexdigest()=='ef9b047e9eb2ccfdf97e86ca62b91fd4a8ed3551d210f8e20febb22ec237f6be'
groups=json.loads(raw)['groups'];rows=json.loads(a.bindings.read_bytes());applied=[]
for role,active,practice,matrix,tier,mask,ids in [
    (8,3036,257,3,2,4,[177,178,179,180,218]),
    (9,3045,266,4,1,2,[208,209,210,211]),
    (9,3049,270,6,1,5,[224,225,226,227])]:
    g=next(g for g in groups if (g['role'],g['active'],g['practice'])==(role,active,practice))
    assert g['allClipsNonRepeat'] and g['canonicalDeltaSummary']['onlyEffectAndSoundReferencePathsDiffer']
    assert [c['motion'] for c in g['clips']]==ids
    durations=[]
    for c in g['clips']:
        assert c['animationData']['Repeat']=='false'
        v=sum((float(s['EndFrame'])+float(s['Delay']))/float(s['FPS']) for s in c['rawSplits'])
        assert v>0;durations.append(v)  # Existing unverified resource estimate only.
    selected=[r for r in rows if (r['Role'],r['Practice'],r['Active'])==(role,practice,active)]
    assert len(selected)==1
    r=selected[0];assert (r['Matrix'],r['Tier'],r['Mask'])==(matrix,tier,mask)
    r.update(Motions=ids,Durations=durations,Status='SERVER_OWNED_COMPONENT_ANCHOR_VISUAL_COMPARISON_CANDIDATE')
    applied.append({'role':role,'active':active,'motions':ids})
out=(json.dumps(rows,ensure_ascii=False,indent=2)+'\n').encode();a.output.write_bytes(out)
print(json.dumps({'applied':applied,'outputSha256':hashlib.sha256(out).hexdigest(),
 'authority':'EXPLICIT_LAB_COMPONENT_HYPOTHESIS_NOT_NATIVE_MAPPING_OR_VARIANT_SELECTION'}))
