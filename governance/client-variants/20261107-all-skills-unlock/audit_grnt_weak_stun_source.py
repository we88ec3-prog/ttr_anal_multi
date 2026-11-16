"""Active3056 explicitly named weak stun, distinct from Hold and ordinary stun."""
from pathlib import Path
import argparse,hashlib,json,sys,xml.etree.ElementTree as E
p=argparse.ArgumentParser();p.add_argument('workspace',type=Path);p.add_argument('output',type=Path);a=p.parse_args();R=a.workspace
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sources=[];versions=[];origin=Archive(R.parent/'origin/Table.stp');sha=lambda b:hashlib.sha256(b).hexdigest()
review_path=Path(__file__).parent/'grnt-sheep-component-review-v1.json';review_bytes=review_path.read_bytes()
assert sha(review_bytes)=='b65d29be680c251a8f0332f573442010b54039043c4f3e98f65c0fdaf70da1f6'
review=json.loads(review_bytes)
for label,root,word in [('kr',R,'약한 기절'),('tc',R.parent/'tc_workspace','輕微暈眩')]:
    arc=Archive(root/'Table.stp');tables={}
    for member in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml','Table/BuffExplainTable.xml','Table/_BuffList.xml']:
        data=arc.read(member)
        if label=='kr':assert data==origin.read(member)
        sources.append({'version':label,'member':member,'sha256':sha(data)});tables[member]=E.fromstring(data.decode('utf-8-sig'))
    active=next(n for n in tables['Table/SkillActiveTable.xml'] if n.get('no')=='3056')
    explain=next(n for n in tables['Table/skillexplaintable.xml'] if n.get('no')=='3056')
    text=''.join(explain.find('EXPLAIN').itertext());buff=next(n for n in tables['Table/BuffExplainTable.xml'] if n.get('no')=='39')
    assert word==buff.get('name') and word in text
    levels=[{'level':int(n.get('val')),'rawTime':n.get('time'),'fullText':''.join(n.itertext())} for n in buff.findall('LEVEL')]
    assert [(n['level'],n['rawTime']) for n in levels]==[(1,'4'),(2,'5'),(3,'6'),(4,'7'),(5,'8')]
    old=next(v for v in review['tableVersions'] if v['root']==str(root));assert old['fullText']==text
    versions.append({'version':label,'active':dict(active.attrib),'fullText':text,'buff':dict(buff.attrib),'buffLevels':levels,
        'buffListEntry':dict(next(n for n in tables['Table/_BuffList.xml'] if n.get('ID')=='39').attrib)})
out={'schema':'GRNT_WEAK_STUN_SOURCE_BOUNDARY_V1','role':6,'practice':277,'active':3056,'versions':versions,'sourceMembers':sources,
    'practiceAndMatrixReviewSha256':sha(review_bytes),'nativeDispatchEstablished':False,'nativeMef':False,
    'limits':['Weak stun is39, not ordinary stun13 or movement-only Hold12.',
        'ActiveKR says received damage has high chance of release; Buff text says release on damage. Numeric chance/order remain unverified.',
        'No precise application probability, native grant level, timer units, range or projectile/hit timing recovered.',
        'Cancelling pending prototype melee windup is a Server lab policy, not recovered handling of already launched projectiles.',
        'No new enemy Buff icon/EFF publication or native FSM stun state is established.']}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode());print(sha(a.output.read_bytes()))
