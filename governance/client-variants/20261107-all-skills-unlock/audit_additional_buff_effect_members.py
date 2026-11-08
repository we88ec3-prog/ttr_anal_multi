"""Four reviewed additional Buff EFF members; no geometry or runtime acceptance."""
from pathlib import Path
import hashlib,json,sys
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
D=R/'runtime-observations/2026-11-05-all-skills';sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
raw=(D/'four-additional-buff-text-candidates-v1.json').read_bytes()
assert hashlib.sha256(raw).hexdigest()=='11c961dddcd26ad1ff4f919e25cf4c1a3d8f8b056884401258d0c6cde310baac'
original=Archive(R.parent/'origin/Effect/Effect.stp');working=Archive(R/'Effect/Effect.stp');rows=[]
for group in json.loads(raw)['rows']:
    declared=group['versions'][0]['buffListSharedIdEntry']['FILE']
    matches=[m for m in original.files if m.replace('\\','/').split('/')[-1].casefold()==declared.casefold()]
    assert len(matches)==1;data=original.read(matches[0]);assert data==working.read(matches[0])
    rows.append({'role':group['role'],'active':group['active'],'buff':group['sameNameBuffIdCandidate'],
        'carrier':'Effect/Effect.stp','declaredFile':declared,'member':matches[0],
        'memberSha256':hashlib.sha256(data).hexdigest(),'workingEqualOriginal':True,
        'adoptedForOwnCaster':group['active']!=1297})
out={'schema':'FOUR_ADDITIONAL_BUFF_EFFECT_MEMBERS_V1','rows':rows,
     'limits':['Only four known EFF names checked; full geometry and runtime rendering not verified.',
               '1297 resource existence does not justify granting its ally-only protection to the caster.',
               'No resource export/change, native provider, game or Host operation.']}
p=D/'additional-buff-effect-members.json';p.write_text(json.dumps(out,indent=2)+'\n',encoding='utf8')
print(hashlib.sha256(p.read_bytes()).hexdigest())
