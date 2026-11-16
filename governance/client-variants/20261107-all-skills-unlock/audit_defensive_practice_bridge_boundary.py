"""Five exact Practice members: no broad table or native dispatch search."""
from pathlib import Path
import hashlib,json,sys,xml.etree.ElementTree as E

R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
catalog=json.loads((D/'all-skills-catalog.json').read_bytes())
original=Archive(R.parent/'origin/Table.stp');working=Archive(R/'Table.stp')
rows=[]
for role,active,practice in [(1,4,4),(2,13,21),(2,15,22),(3,25,38),(4,34,54)]:
    member=next(p['source'] for p in catalog['practices'] if p['id']==practice)
    raw=original.read(member);assert raw==working.read(member)
    node=E.fromstring(raw).find('Practice')
    assert(int(node.get('ID')),int(node.get('CharID')))==(practice,role)
    levels=[]
    for level in node.findall('LevelData'):
        modifiers=[dict(m.attrib) for m in level.findall('Modifiers/Modifier')]
        assert modifiers and all(m['Type']=='SkillLevel' and int(m['TargetSkillID'])==active for m in modifiers)
        levels.append({'learnedLevel':int(level.get('Level')),'modifiers':modifiers,
                       'interruptsChildren':len(level.find('Interrupts'))})
    rows.append({'role':role,'active':active,'practice':practice,'member':member,
                 'memberSha256':hashlib.sha256(raw).hexdigest(),'workingEqualOriginal':True,
                 'levels':levels,'explicitBuffModifierPresent':False})
out={'schema':'FIVE_DEFENSIVE_PRACTICE_BRIDGE_BOUNDARY_V1','rows':rows,
     'scope':'All LevelData modifiers in five exact Practice members only',
     'conclusion':'These modifiers join Practice to Active level only; they do not establish Active to Buff dispatch or buff-level conversion. No native indirect path exclusion is claimed.'}
p=D/'defensive-practice-bridge-boundary.json'
p.write_text(json.dumps(out,indent=2)+'\n',encoding='utf8')
print(hashlib.sha256(p.read_bytes()).hexdigest())
