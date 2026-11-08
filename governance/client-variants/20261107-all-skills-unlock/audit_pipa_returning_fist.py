"""Read-only returning-fist text and rendering declaration boundary."""
from pathlib import Path
import argparse,hashlib,json,re,sys,xml.etree.ElementTree as E
p=argparse.ArgumentParser();p.add_argument('workspace',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
R=a.workspace;sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();sources=[];versions=[]
prior=Path(__file__).with_name('punch-ice-component-review-v1.json').read_bytes()
assert sha(prior)=='6a93bd097a95556d132ce8775f988ff2fd68b1761dbd3d26442941392f542873'
original=Archive(R.parent/'origin/Table.stp')
for label,root in [('KR',R),('TC',R.parent/'tc_workspace')]:
    arc=Archive(root/'Table.stp');tables={}
    for name in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml','Table/Skill/Active/pipa_StrongPunch.xml']:
        b=arc.read(name)
        if label=='KR':assert b==original.read(name)
        sources.append({'version':label,'member':name,'sha256':sha(b)})
        tables[name]=E.fromstring(b.decode('utf-8-sig'))
    pr=tables['Table/Skill/Active/pipa_StrongPunch.xml'].find('.//Practice');assert pr.get('ID')=='216' and pr.get('CharID')=='2'
    active=next(n for n in tables['Table/SkillActiveTable.xml'] if n.get('no')=='2995')
    text=''.join(next(n for n in tables['Table/skillexplaintable.xml'] if n.get('no')=='2995').find('EXPLAIN').itertext())
    reviewed=next(g for g in json.loads(prior)['groups'] if g['role']==2)
    assert text==next(v for v in reviewed['versions'] if v['version']==label)['fullText']
    versions.append({'version':label,'practice':dict(pr.attrib),'active':dict(active.attrib),'fullText':text})
effects=[];oa=Archive(R.parent/'origin/Effect/Effect.stp');wa=Archive(R/'Effect/Effect.stp')
for variant in range(1,5):
    name=f'Effect/Character/C_Pipa-5-{variant}.eff';b=oa.read(name);assert b==wa.read(name)
    t=E.fromstring('<ROOT>'+re.sub(r'<\?xml.*?\?>','',b.decode('utf-8-sig'))+'</ROOT>')
    elements=[]
    for n in t.iter('Element'):
        if n.get('File')=='C_Pipa_Powerpunchi.gb3':
            elements.append({'attributes':dict(n.attrib),'children':[{'tag':c.tag,'attributes':dict(c.attrib)} for c in n]})
    assert len(elements)==[2,2,2,4][variant-1]
    effects.append({'member':name,'sha256':sha(b),'punchElements':elements,'originalWorkingEqual':True})
out={'schema':'PIPA_RETURNING_FIST_SOURCE_BOUNDARY_V1','role':2,'practice':216,'active':2995,'versions':versions,
    'effectDeclarations':effects,'sourceMembers':sources,'priorComponentReviewSha256':sha(prior),
    'nativeProjectileContractEstablished':False,'nativeMef':False,
    'limits':['KR text explicitly says forward fist attacks and pulls enemies as it returns; TC confirms forward attack/pull and emission requirement.',
        'No explicit second damage event, gameplay projectile count, world trajectory, range, speed, collision radius or pull distance is given.',
        'EFF element counts/positions/delays are rendering declarations, not world projectile counts/units or a native time clock.',
        'One aggregate Server-only swept volume, outbound prototype60 damage and return pull without extra damage are explicit lab choices.',
        'No native projectile spawn/return/displacement packet or geometry alias is recovered.']}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print('Returning fist source boundary SHA256 '+sha(a.output.read_bytes()))
