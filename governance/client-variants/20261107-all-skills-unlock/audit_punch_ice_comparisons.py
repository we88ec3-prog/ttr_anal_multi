"""Two finite semantic component hypotheses, not native active/action mappings."""
from pathlib import Path
import argparse, collections, hashlib, json, re, sys, xml.etree.ElementTree as E

p=argparse.ArgumentParser();p.add_argument('workspace',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
R=a.workspace;O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};sources=[]
def read(root,carrier,name):
    key=(root,carrier)
    if key not in arcs:arcs[key]=Archive(root/carrier)
    data=arcs[key].read(name)
    sources.append({'root':str(root),'carrier':carrier,'member':name,'sha256':sha(data)})
    return data
def original(carrier,name):
    data=read(O,carrier,name);assert data==read(R,carrier,name);return data
def xml(data):
    encoding='euc-kr' if b'euc-kr' in data[:150].lower() else 'utf-8-sig'
    return E.fromstring('<ROOT>'+re.sub(r'<\?xml[^?]*\?>','',data.decode(encoding))+'</ROOT>')
def flatten(n,path='',out=None):
    if out is None:out={}
    for k,v in n.attrib.items():
        if not(n.tag=='AnimationHeader' and k in ('ID','NAME')):out[path+'/@'+k]=v
    if(n.text or '').strip():out[path+'/#text']=n.text.strip()
    counts=collections.Counter()
    for child in n:
        i=counts[child.tag];counts[child.tag]+=1
        flatten(child,path+'/'+child.tag+'['+str(i)+']',out)
    return out

prior_path=R/'runtime-observations/2026-11-05-all-skills/numeric-family-explicit-link-audit.json'
prior=json.loads(prior_path.read_bytes());known={x['member']:x for x in prior['referencedEffectStructures']}
metadata_path=R/'runtime-observations/2026-11-05-all-skills/all-role-motion-joins.json'
metadata=json.loads(metadata_path.read_bytes())
matrix=xml(original('Table.stp','Table/Skill/Matrix/CharacterMatrices.xml'))
groups=[]
for role,active,practice,stem,ids,token in [
    (2,2995,216,'pipa_StrongPunch',[196,197,198,199],'C_Pipa_Powerpunchi.gb3'),
    (7,3034,255,'crmd_IceShower',[186,187,188,189],'2Page_IceStone')]:
    versions=[]
    for root in (R,TC):
        def table(name):return xml(original('Table.stp',name) if root==R else read(root,'Table.stp',name))
        name='Table/Skill/Active/'+stem+'.xml';pr=table(name).find('.//Practice')
        assert int(pr.get('ID'))==practice and int(pr.get('CharID'))==role
        assert all(any(n.get('Type')=='SkillLevel' and n.get('TargetSkillID')==str(active)
            for n in ld.findall('Modifiers/Modifier')) for ld in pr.findall('LevelData'))
        act=next(n for n in table('Table/SkillActiveTable.xml').iter('SKILL') if n.get('no')==str(active))
        explain=next(n for n in table('Table/skillexplaintable.xml').iter('SKILL') if n.get('no')==str(active))
        versions.append({'version':'KR' if root==R else 'TC','practice':dict(pr.attrib),'practiceMember':name,
            'active':dict(act.attrib),'fullText':''.join(explain.find('EXPLAIN').itertext())})
    slots=[]
    for char in matrix.iter('SkillMatrix'):
        if int(char.get('CharID'))!=role:continue
        for mx in char.findall('Matrix'):
            for tier in mx.findall('KeyInfo/Tier'):
                for key in tier:
                    if key.get('skill')==str(active):slots.append({'matrix':dict(mx.attrib),'tier':dict(tier.attrib),'key':dict(key.attrib)})
    assert len(slots)==1
    r=next(n for n in metadata['roles'] if n['role']==role)
    abf=xml(original('Character/Cha/Base.stp',r['abf_member']))
    animations={int(n.get('ID')):dict(n.attrib) for n in abf.findall('.//AnimationList/Animation')}
    clips=[];baseline=None
    for mid in ids:
        m=next(n for n in r['motion_metadata'] if n['motion_id']==mid)
        raw=original(m['asd_carrier'],m['asd_member']);assert sha(raw)==m['asd_sha256']
        tree=xml(raw);h=tree.find('.//AnimationHeader');assert int(h.get('ID'))==mid
        assert h.find('AnimationData').get('Repeat')=='false'
        fields=flatten(tree)
        if baseline is None:baseline=fields
        deltas=[{'path':k,'baseline':baseline.get(k),'value':fields.get(k)}
            for k in sorted(baseline.keys()|fields.keys()) if baseline.get(k)!=fields.get(k)]
        effects=[]
        for ref in h.findall('Effect'):
            if not ref.get('File') or ref.get('File').lower()=='null':continue
            ef=ref.get('Folder','').replace('\\','/')+ref.get('File');eb=original('Effect/Effect.stp',ef);et=xml(eb)
            files=sorted({v for n in et.iter() for k,v in n.attrib.items() if k.lower() in ('file','name')})
            assert files==known[ef]['declaredFiles']
            hits=[dict(n.attrib) for n in et.iter('Element') if token.casefold() in n.get('File','').casefold()]
            effects.append({'member':ef,'sha256':sha(eb),'tokenElements':hits,'priorDeclaredFilesRechecked':True})
        assert effects, (role,mid)
        clips.append({'motion':mid,'abfEntry':animations[mid],'asdMember':m['asd_member'],'asdSha256':sha(raw),
            'animationData':dict(h.find('AnimationData').attrib),'rawSplits':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],
            'canonicalDeltas':deltas,'effects':effects})
    refs={}
    for m in r['motion_metadata']:
        if re.fullmatch(r'[A-Za-z]+_\d+-\d+\.asd',m['abf_file'],re.I):continue
        for ef in m['effects']:refs.setdefault(ef['path'],[]).append(m['motion_id'])
    checked=[];reuse=[]
    for ef,mids in sorted(refs.items()):
        eb=original('Effect/Effect.stp',ef);et=xml(eb)
        matches=sorted({n.get('File') for n in et.iter('Element') if token.casefold() in n.get('File','').casefold()})
        row={'member':ef,'sha256':sha(eb),'motions':mids,'matches':matches};checked.append(row)
        if matches:reuse.append(row)
    assert any(e['tokenElements'] for c in clips for e in c['effects']), (role,token)
    groups.append({'role':role,'active':active,'practice':practice,'versions':versions,'exactKrSlots':slots,
        'hypothesisToken':token,'clips':clips,'namedRoleCountercheck':{'checked':checked,'reuse':reuse},
        'onlyEffectOrSoundDeltas':all('/Effect[' in d['path'] or '/Sound[' in d['path'] for c in clips for d in c['canonicalDeltas']),
        'nativeDispatchEstablished':False,'selectedMotions':[]})
out={'schema':'PUNCH_ICE_SEMANTIC_COMPONENT_COMPARISONS_V1','groups':groups,'sourceMembers':sources,
    'priorNumericProjectionSha256':sha(prior_path.read_bytes()),'motionMetadataSha256':sha(metadata_path.read_bytes()),
    'scope':'Eight exact ASD/ABF rows and explicit EFFs, two exact Practice/Active/matrix/full descriptions; named-role EFF refs only for reuse.',
    'limits':['Component semantics support a manual lab hypothesis only; not native active-to-motion dispatch.',
        'No family order, learned-level variant, phase, projectile/hit count, official targeting or timing inference.',
        'No complete geometry, native MEF, target execution, Client edit or archive-wide rescan.']}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print(json.dumps({'sha256':sha(a.output.read_bytes()),'groups':[{'role':g['role'],'active':g['active'],'slots':g['exactKrSlots'],
    'onlyEffectOrSoundDeltas':g['onlyEffectOrSoundDeltas'],'reuseCount':len(g['namedRoleCountercheck']['reuse'])} for g in groups]}))
