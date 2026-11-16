"""Explicit frostbite skill admission/deferral from full descriptions, not name matching."""
from pathlib import Path
import argparse,hashlib,json,sys,xml.etree.ElementTree as E
p=argparse.ArgumentParser();p.add_argument('workspace',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
R=a.workspace;sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();sources=[];versions=[]
boundary=Path(__file__).with_name('crmd-frostbite-source-boundary-v1.json').read_bytes()
assert sha(boundary)=='f038be108b98590665413433a86de73408f817919de5ac20f858a9f172c29f37'
cat_path=R/'runtime-observations/2026-11-05-all-skills/all-skills-catalog.json';cat=json.loads(cat_path.read_bytes())
config=[(7,333,98,'TRAIT_REQUIRED_DEFERRED'),(7,340,105,'EXISTING_HIT_COMPONENT'),
    (7,737,106,'EXISTING_HIT_COMPONENT'),(7,1299,110,'EXISTING_HIT_COMPONENT'),
    (9,1403,129,'TRAIT_REQUIRED_DEFERRED'),(9,1412,139,'CIRCLE_PULL_HIT_COMPONENT'),
    (7,2527,181,'CIRCLE_HIT_COMPONENT'),(9,2534,186,'SELF_CIRCLE_HIT_COMPONENT_ALLY_AURA_DEFERRED'),
    (9,2536,187,'EXISTING_HIT_COMPONENT'),(7,3033,254,'MOTION_UNAVAILABLE_DEFERRED'),
    (7,3034,255,'EXISTING_ADMISSION'),(9,3043,264,'MOTION_UNAVAILABLE_DEFERRED'),
    (9,3045,266,'EXISTING_HIT_COMPONENT')]
original=Archive(R.parent/'origin/Table.stp')
for label,root,word in [('KR',R,'동상'),('TC',R.parent/'tc_workspace','凍傷')]:
    arc=Archive(root/'Table.stp')
    def table(name):
        b=arc.read(name)
        if label=='KR':assert b==original.read(name)
        sources.append({'version':label,'member':name,'sha256':sha(b)})
        return E.fromstring(b.decode('utf-8-sig'))
    skills=table('Table/SkillActiveTable.xml');explains=table('Table/skillexplaintable.xml');rows=[]
    for role,active,practice,admission in config:
        name=next(n for n in cat['practices'] if n['id']==practice)['source']
        pr=table(name).find('.//Practice');assert int(pr.get('ID'))==practice and int(pr.get('CharID'))==role
        assert all(any(n.get('Type')=='SkillLevel' and n.get('TargetSkillID')==str(active) for n in ld.findall('Modifiers/Modifier')) for ld in pr.findall('LevelData'))
        act=next(n for n in skills if n.get('no')==str(active));ex=next(n for n in explains if n.get('no')==str(active));text=''.join(ex.find('EXPLAIN').itertext());assert word in text
        if label=='KR' and admission=='TRAIT_REQUIRED_DEFERRED':assert '특성 강화로 활성화' in text
        rows.append({'role':role,'active':active,'practice':practice,'practiceMember':name,'activeAttributes':dict(act.attrib),
            'activeLevels':[int(n.get('val')) for n in act.findall('LEVEL')],'fullText':text,'admissionPolicy':admission})
    versions.append({'version':label,'rows':rows})
out={'schema':'FROSTBITE_SKILL_ADMISSION_SOURCE_BOUNDARY_V1','versions':versions,'sourceMembers':sources,
    'priorBuff28BoundarySha256':sha(boundary),'practiceCatalogueSha256':sha(cat_path.read_bytes()),
    'admittedSkills':9,'newHitComponentAdmissions':8,'traitGatedDeferred':2,'motionUnavailableDeferred':2,
    'nativeGrantEstablished':False,'nativeMef':False,
    'limits':['Full text distinguishes trait-gated attacks, surrounding attacks/pull, persistent/projectile hits and unopened motions.',
        'Only existing positive prototype hits are granted partial frostbite. This is not the full named projectile/field/aura mechanic.',
        'Circle radius65, pulse at0.2s, prototype damage and pull20/stop8 are explicit Server lab calibrations.',
        'Only equal Active/Buff levels1..5 are admitted. Active340level6 remains a playable skill with frostbite-level mapping pending.',
        'No trait activation, ally aura, target marker, taunt, roll, armor, original proc/level/clock or status-FX completion.']}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print('Frostbite skill admission boundary SHA256 '+sha(a.output.read_bytes()))
