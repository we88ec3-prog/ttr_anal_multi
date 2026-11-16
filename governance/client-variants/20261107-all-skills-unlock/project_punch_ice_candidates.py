"""Two explicit whole-clip lab hypotheses; preserve every unrelated binding."""
from pathlib import Path
import argparse,hashlib,json
p=argparse.ArgumentParser();p.add_argument('bindings',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
assert a.bindings.resolve()!=a.output.resolve()
raw=Path(__file__).with_name('punch-ice-component-review-v1.json').read_bytes()
assert hashlib.sha256(raw).hexdigest()=='6a93bd097a95556d132ce8775f988ff2fd68b1761dbd3d26442941392f542873'
review=json.loads(raw);rows=json.loads(a.bindings.read_bytes());applied=[]
for role,active,practice,matrix,tier,mask,ids,counts in [
    (2,2995,216,3,2,4,[196,197,198,199],[2,2,2,4]),
    (7,3034,255,6,0,2,[188,189],[5,18])]:
    group=next(g for g in review['groups'] if (g['role'],g['active'],g['practice'])==(role,active,practice))
    assert group['onlyEffectOrSoundDeltas'] and not group['nativeDispatchEstablished']
    slot=group['exactKrSlots'][0]
    assert (int(slot['matrix']['ID']),int(slot['tier']['tier']),int(slot['key']['skill']))==(matrix,tier,active)
    durations=[]
    for mid,count in zip(ids,counts):
        clip=next(c for c in group['clips'] if c['motion']==mid)
        assert clip['animationData']['Repeat']=='false'
        assert sum(len(e['tokenElements']) for e in clip['effects'])==count
        assert all('/Effect[' in d['path'] or '/Sound[' in d['path'] for d in clip['canonicalDeltas'])
        duration=sum((float(s['EndFrame'])+float(s['Delay']))/float(s['FPS']) for s in clip['rawSplits'])
        assert duration>0;durations.append(duration) # Existing estimate only, not native lock/cancel/hit timing.
    selected=[r for r in rows if (r['Role'],r['Practice'],r['Active'])==(role,practice,active)]
    assert len(selected)==1
    row=selected[0];assert (row['Matrix'],row['Tier'],row['Mask'])==(matrix,tier,mask)
    row.update(Motions=ids,Durations=durations,Status='SERVER_OWNED_COMPONENT_ANCHOR_VISUAL_COMPARISON_CANDIDATE')
    applied.append({'role':role,'active':active,'motions':ids})
a.output.write_bytes((json.dumps(rows,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print(json.dumps({'applied':applied,'outputSha256':hashlib.sha256(a.output.read_bytes()).hexdigest(),
    'authority':'MANUAL_COMPONENT_SEMANTIC_LAB_HYPOTHESES_NOT_NATIVE_DISPATCH'}))
