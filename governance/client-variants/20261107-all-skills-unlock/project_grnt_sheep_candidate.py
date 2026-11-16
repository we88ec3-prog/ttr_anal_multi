"""One explicit whole-clip comparison policy; no official dispatch/variant mapping."""
from pathlib import Path
import argparse, hashlib, json
p=argparse.ArgumentParser();p.add_argument('bindings',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
assert a.bindings.resolve()!=a.output.resolve()
data=(Path(__file__).parent/'grnt-sheep-component-review-v1.json').read_bytes()
assert hashlib.sha256(data).hexdigest()=='b65d29be680c251a8f0332f573442010b54039043c4f3e98f65c0fdaf70da1f6'
review=json.loads(data);slot=review['exactKrSlots'][0]
assert (slot['character']['CharID'],slot['matrix']['ID'],slot['tier']['tier'],slot['key']['key'],slot['key']['skill'])==('6','5','1','2','3056')
assert len(review['namedRoleCountercheck']['reuse'])==2 # Token is NOT unique to this skill.
for reused in review['namedRoleCountercheck']['reuse']:
    assert set(reused['rotationZCounts'])=={'0.000000'}
motions=[191,192,193,194,210];durations=[]
for mid in motions:
    clip=next(c for c in review['clips'] if c['motion']==mid)
    assert clip['animationData']['Repeat']=='false'
    assert all('/Effect[' in d['path'] or '/Sound[' in d['path'] for d in clip['canonicalDeltas'])
    assert all(set(e['rotationZCounts'])=={'0.000000','0.401426','-0.401426'} for e in clip['effects'])
    durations.append(sum((float(s['EndFrame'])+float(s['Delay']))/float(s['FPS']) for s in clip['rawSplits']))
rows=json.loads(a.bindings.read_bytes());selected=[r for r in rows if (r['Role'],r['Practice'],r['Active'])==(6,277,3056)]
assert len(selected)==1
row=selected[0];assert (row['Matrix'],row['Tier'],row['Mask'])==(5,1,2)
row.update(Motions=motions,Durations=durations,Status='SERVER_OWNED_COMPONENT_ANCHOR_VISUAL_COMPARISON_CANDIDATE')
a.output.write_bytes((json.dumps(rows,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print(json.dumps({'role':6,'active':3056,'clips':motions,'durationEstimates':durations,'authority':'EXPLICIT_LAB_COMPARISON_NOT_NATIVE_MAPPING'}))
