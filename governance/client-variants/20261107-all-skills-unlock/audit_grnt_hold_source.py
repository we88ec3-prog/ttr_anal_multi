"""One explicit movement-only Hold effect; no native probability or grant claim."""
from pathlib import Path
import argparse, hashlib, json, sys, xml.etree.ElementTree as E
p=argparse.ArgumentParser();p.add_argument('workspace',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
R=a.workspace;sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();sources=[];versions=[];original=Archive(R.parent/'origin/Table.stp')
catalog=json.loads((R/'runtime-observations/2026-11-05-all-skills/all-skills-catalog.json').read_bytes())
practice_member=next(n['source'] for n in catalog['practices'] if n['id']==93)
for label,root,word in [('kr',R,'홀드'),('tc',R.parent/'tc_workspace','拘束')]:
    arc=Archive(root/'Table.stp');tables={}
    for member in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml','Table/BuffExplainTable.xml','Table/_BuffList.xml']:
        data=arc.read(member)
        if label=='kr':assert data==original.read(member)
        sources.append({'version':label,'member':member,'sha256':sha(data)});tables[member]=E.fromstring(data.decode('utf-8-sig'))
    active=next(n for n in tables['Table/SkillActiveTable.xml'] if n.get('no')=='483')
    explain=next(n for n in tables['Table/skillexplaintable.xml'] if n.get('no')=='483')
    text=''.join(explain.find('EXPLAIN').itertext());buff=next(n for n in tables['Table/BuffExplainTable.xml'] if n.get('no')=='12')
    assert buff.get('name')==word and word in text
    levels=[{'level':int(n.get('val')),'rawTime':n.get('time'),'fullText':''.join(n.itertext())} for n in buff.findall('LEVEL')]
    assert [(n['level'],n['rawTime']) for n in levels]==[(1,'10'),(2,'11'),(3,'12'),(4,'13'),(5,'14')]
    data=arc.read(practice_member)
    if label=='kr':assert data==original.read(practice_member)
    sources.append({'version':label,'member':practice_member,'sha256':sha(data)})
    practice=E.fromstring(data.decode('utf-8-sig')).find('Practice')
    assert practice.get('ID')=='93' and practice.get('CharID')=='6'
    modifiers=[dict(n.attrib) for n in practice.findall('LevelData/Modifiers/Modifier') if n.get('Type')=='SkillLevel']
    assert len(modifiers)==5 and all(n['TargetSkillID']=='483' for n in modifiers)
    versions.append({'version':label,'active':dict(active.attrib),'fullText':text,'buff':dict(buff.attrib),'buffLevels':levels,
        'practiceIdentity':dict(practice.attrib),'practiceMember':practice_member,'levelModifiers':modifiers,
        'buffListEntry':dict(next(n for n in tables['Table/_BuffList.xml'] if n.get('ID')=='12').attrib)})
out={'schema':'GRNT_HOLD_SOURCE_BOUNDARY_V1','role':6,'active':483,'practice':93,'versions':versions,'sourceMembers':sources,
    'interpretation':'Active description explicitly names movement-only Hold; target is enemies inside surrounding field. Names are effect-text candidates, not native grant dispatch.',
    'unknown':['High probability is not a numeric percentage.','Native grant level, raw time units, radius and impact timing are unverified.','Hold is not stun: source does not say attacks/skills are disabled or damage ends it.','Do not add HP/SP/MP drain from different binding/suppression Buffs.'],
    'nativeDispatchEstablished':False,'nativeMef':False}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode());print(sha(a.output.read_bytes()))
