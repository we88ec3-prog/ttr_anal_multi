"""Five explicit Grnt clips: sheep-component hypothesis, not native dispatch."""
from pathlib import Path
import argparse, collections, hashlib, json, re, sys, xml.etree.ElementTree as E
p=argparse.ArgumentParser();p.add_argument('workspace',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
R=a.workspace;D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};sources=[]
def read(root,carrier,member):
    key=(root,carrier)
    if key not in arcs:arcs[key]=Archive(root/carrier)
    data=arcs[key].read(member);sources.append({'root':str(root),'carrier':carrier,'member':member,'sha256':sha(data)})
    return data
def original(carrier,member):
    data=read(O,carrier,member);assert data==read(R,carrier,member);return data
def xml(data):return E.fromstring('<ROOT>'+re.sub(r'<\?xml[^?]*\?>','',data.decode('euc-kr' if b'euc-kr' in data[:150].lower() else 'utf-8-sig'))+'</ROOT>')
def flatten(n,path='',out=None):
    if out is None:out={}
    for k,v in n.attrib.items():
        if not(n.tag=='AnimationHeader' and k in ['ID','NAME']):out[path+'/@'+k]=v
    if(n.text or '').strip():out[path+'/#text']=n.text.strip()
    if(n.tail or '').strip():out[path+'/#tail']=n.tail.strip()
    counts=collections.Counter()
    for c in n:
        i=counts[c.tag];counts[c.tag]+=1;flatten(c,path+'/'+c.tag+'['+str(i)+']',out)
    return out
joins_path=D/'all-role-motion-joins.json';joins=json.loads(joins_path.read_bytes());role=next(n for n in joins['roles'] if n['role']==6)
abf=xml(original('Character/Cha/Base.stp',role['abf_member']));animations={int(n.get('ID')):dict(n.attrib) for n in abf.findall('.//AnimationList/Animation')}
clips=[];baseline=None;token='U3_OE_ShapeSheep_FrontStayA_X01.gb3'
for mid in [191,192,193,194,210]:
    m=next(n for n in role['motion_metadata'] if n['motion_id']==mid)
    data=original(m['asd_carrier'],m['asd_member']);tree=xml(data);header=tree.find('.//AnimationHeader');fields=flatten(tree)
    if baseline is None:baseline=fields
    deltas=[{'path':k,'baseline':baseline.get(k),'value':fields.get(k)} for k in sorted(baseline.keys()|fields.keys()) if baseline.get(k)!=fields.get(k)]
    effects=[]
    for ref in header.findall('Effect'):
        if not ref.get('File') or ref.get('File').lower()=='null':continue
        member=ref.get('Folder','').replace('\\','/')+ref.get('File');eb=original('Effect/Effect.stp',member);et=xml(eb)
        sheep=[e for e in et.iter('Element') if e.get('File')==token]
        angles=collections.Counter(e.find('Rotation').get('Z') for e in sheep)
        effects.append({'member':member,'sha256':sha(eb),'sheepComponent':token,'elementCount':len(sheep),
            'rotationZCounts':dict(angles),'rawDelayRange':[min(float(e.get('Delay')) for e in sheep),max(float(e.get('Delay')) for e in sheep)] if sheep else None,
            'scaleValues':sorted({e.get('Scale') for e in sheep}),
            'limits':'Element counts/angles are rendering declarations, not gameplay hits, rows, units or projectiles.'})
    assert all(e['elementCount']>0 for e in effects) and effects
    clips.append({'motion':mid,'abfEntry':animations[mid],'asdMember':m['asd_member'],'asdSha256':sha(data),
        'animationData':dict(header.find('AnimationData').attrib),'rawSplits':[dict(n.attrib) for n in header.findall('ReferIndex/SpliteData')],
        'canonicalDeltas':deltas,'effects':effects})

oldrefs={}
for m in role['motion_metadata']:
    if re.fullmatch(r'[A-Za-z]+_\d+-\d+\.asd',m['abf_file'],re.I):continue
    for e in m['effects']:oldrefs.setdefault(e['path'],[]).append(m['motion_id'])
checked=[];reuse=[]
for member,mids in sorted(oldrefs.items()):
    data=original('Effect/Effect.stp',member);tree=xml(data);hits=sum(1 for e in tree.iter('Element') if e.get('File')==token)
    row={'member':member,'sha256':sha(data),'motions':mids,'sameComponentElements':hits,
        'rotationZCounts':dict(collections.Counter(e.find('Rotation').get('Z') for e in tree.iter('Element') if e.get('File')==token))};checked.append(row)
    if hits:reuse.append(row)

cat=json.loads((D/'all-skills-catalog.json').read_bytes());practice=next(n for n in cat['practices'] if n['id']==277);versions=[]
for root in [R,TC]:
    def table(member):return xml(original('Table.stp',member) if root==R else read(root,'Table.stp',member))
    pr=table(practice['source']).find('.//Practice');assert int(pr.get('ID'))==277 and int(pr.get('CharID'))==6
    act=next(n for n in table('Table/SkillActiveTable.xml').iter('SKILL') if n.get('no')=='3056')
    ex=next(n for n in table('Table/skillexplaintable.xml').iter('SKILL') if n.get('no')=='3056')
    assert all(any(n.get('Type')=='SkillLevel' and n.get('TargetSkillID')=='3056' for n in ld.findall('Modifiers/Modifier')) for ld in pr.findall('LevelData'))
    versions.append({'root':str(root),'active':dict(act.attrib),'practice':dict(pr.attrib),'practiceMember':practice['source'],
        'levels':[{'attributes':dict(ld.attrib),'modifiers':[dict(n.attrib) for n in ld.findall('Modifiers/Modifier')]} for ld in pr.findall('LevelData')],
        'fullText':''.join(ex.find('EXPLAIN').itertext())})
matrix=xml(original('Table.stp','Table/Skill/Matrix/CharacterMatrices.xml'));slots=[]
for char in matrix.iter('SkillMatrix'):
    if char.get('CharID')!='6':continue
    for mx in char.findall('Matrix'):
        for tier in mx.findall('KeyInfo/Tier'):
            for key in tier:
                if key.get('skill')=='3056':slots.append({'character':dict(char.attrib),'matrix':dict(mx.attrib),'tier':dict(tier.attrib),'key':dict(key.attrib)})
assert len(slots)==1
geometry_archive=Archive(O/'Effect/Object.stp')
arcs[(O,'Effect/Object.stp')]=geometry_archive
geometry_names=[n for n in geometry_archive.files if n.rsplit('/',1)[-1].casefold()==(token[:-4]+'.emf').casefold()]
geometry=[]
for member in geometry_names:
    data=original('Effect/Object.stp',member);geometry.append({'carrier':'Effect/Object.stp','member':member,'sha256':sha(data),'bytes':len(data),
        'lookupBasis':'SAME_STEM_EMF_CANDIDATE_NOT_NATIVE_GB3_ALIAS_PROOF'})
assert len(geometry)==1
out={'schema':'GRNT_SHEEP_COMPONENT_REVIEW_V1','role':6,'active':3056,'practice':277,'clips':clips,'tableVersions':versions,'exactKrSlots':slots,
    'namedRoleCountercheck':{'checked':checked,'reuse':reuse},'sameStemEmfCandidates':geometry,'motionMetadataSha256':sha(joins_path.read_bytes()),'sourceMembers':sources,
    'scope':'Five explicitly selected existing numeric ASD clips and their EFF, exact ABF entries and one skill/Practice/matrix. Named-role effect-reference reuse countercheck only; no294 rescan.',
    'nativeDispatchEstablished':False,'selectedMotions':[],
    'limits':['Sheep token and full skill text support a lab hypothesis only; no numeric family-order mapping.',
        'No component geometry or exact three-row/world trajectory/gameplay hit-count proof.',
        'Same-stem .emf presence is not proof of the native .gb3-to-.emf loader alias.',
        'No native time clock, variant selector, trait/learned-level animation mapping, native MEF or target execution.']}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print(json.dumps({'sha256':sha(a.output.read_bytes()),'clips':len(clips),'effectOnlyDifferences':all('/Effect[' in d['path'] or '/Sound[' in d['path'] for c in clips for d in c['canonicalDeltas']),'namedEffectsChecked':len(checked),'componentReuseHits':len(reuse),'slots':slots}))
