"""Exact Active3034 / Buff28 description boundary; no native grant/timer inference."""
from pathlib import Path
import argparse, hashlib, json, re, sys, xml.etree.ElementTree as E
p=argparse.ArgumentParser();p.add_argument('workspace',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
R=a.workspace;sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();sources=[];versions=[]
original=Archive(R.parent/'origin/Table.stp')
for version,root,word in [('KR',R,'동상'),('TC',R.parent/'tc_workspace','凍傷')]:
    arc=Archive(root/'Table.stp');tables={}
    for name in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml','Table/BuffExplainTable.xml','Table/_BuffList.xml']:
        raw=arc.read(name)
        if version=='KR':assert raw==original.read(name)
        sources.append({'version':version,'member':name,'sha256':sha(raw)})
        tables[name]=E.fromstring(raw.decode('utf-8-sig'))
    active=next(n for n in tables['Table/SkillActiveTable.xml'] if n.get('no')=='3034')
    explain=next(n for n in tables['Table/skillexplaintable.xml'] if n.get('no')=='3034')
    text=''.join(explain.find('EXPLAIN').itertext());assert word in text
    buff=next(n for n in tables['Table/BuffExplainTable.xml'] if n.get('no')=='28')
    assert buff.get('name')==word
    levels=[]
    for n in buff.findall('LEVEL'):
        full=''.join(n.itertext());numbers=re.findall(r'(\d+)%',full);assert len(numbers)==1
        levels.append({'level':int(n.get('val')),'rawTime':n.get('time'),
            'declaredAttackSpeedReductionPercent':int(numbers[0]),'fullText':full})
    assert [(x['level'],x['rawTime'],x['declaredAttackSpeedReductionPercent']) for x in levels]==[
        (1,'5',20),(2,'5',22),(3,'6',24),(4,'6',26),(5,'7',28)]
    entry=next(n for n in tables['Table/_BuffList.xml'] if n.get('ID')=='28')
    assert entry.get('FILE')=='S_Dbuff_BasisFrostbite01.eff'
    versions.append({'version':version,'active':dict(active.attrib),'fullSkillText':text,
        'buff':dict(buff.attrib),'levels':levels,'visualDeclaration':dict(entry.attrib)})
out={'schema':'CRMD_FROSTBITE_SOURCE_BOUNDARY_V1','role':7,'practice':255,'active':3034,'sourceMembers':sources,
    'versions':versions,'nativeGrantEstablished':False,'nativeMef':False,
    'limits':['Buff28 is linked by explicit frostbite description, not recovered native grant code.',
        'Movement speed decreases but no numeric movement reduction is declared in these rows.',
        'Raw time units, level conversion, proc rate, stacking, damage release and immunity rules are unknown.',
        'Applying equal Active/Buff levels, raw time as seconds and guaranteed proc are Server lab choices.',
        'A 20% movement reduction, reciprocal attack timing and admission-time snapshots are provisional Server choices.',
        'Visual declaration alone is not a verified enemy0077/FX emission contract.']}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print('Source boundary SHA256 '+sha(a.output.read_bytes()))
