"""Four reviewed BuffList filenames: exact EFF membership/original-work equality only."""
from pathlib import Path
import hashlib,json,sys
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
raw=(D/'named-defensive-buff-text-candidates-v1.json').read_bytes()
assert hashlib.sha256(raw).hexdigest()=='e1a10b5ea0fab9eaf52dfaaea46c264f6ce5f3d05aa640db2cb827a22439f419'
original=Archive(R.parent/'origin/Effect/Effect.stp');working=Archive(R/'Effect/Effect.stp')
rows=[]
for group in json.loads(raw)['rows']:
    buff=group['sameNameBuffIdCandidate']
    if buff not in [1,2,3,4]:continue
    name=group['versions'][0]['buffListBySameId']['FILE']
    matches=[m for m in original.files if m.replace('\\','/').split('/')[-1].casefold()==name.casefold()]
    assert len(matches)==1
    data=original.read(matches[0]);assert data==working.read(matches[0])
    rows.append({'buff':buff,'declaredFile':name,'carrier':'Effect/Effect.stp',
                 'member':matches[0],'memberSha256':hashlib.sha256(data).hexdigest(),
                 'workingEqualOriginal':True})
assert len(rows)==4
out={'schema':'BUFF_SNAPSHOT_FOUR_EFFECT_MEMBERS_V1','rows':rows,
     'scope':'Only four reviewed filenames from the known Effect archive directory; no original member export.',
     'limitations':['Exact EFF existence/equality does not prove complete referenced geometry, runtime rendering, native lookup folder or visual cleanup scheduling.','No target execution, modification or full archive/member content scan.']}
p=D/'buff-snapshot-effect-members.json'
p.write_text(json.dumps(out,indent=2)+'\n',encoding='utf8');print(hashlib.sha256(p.read_bytes()).hexdigest())
