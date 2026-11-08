"""Finite existing numeric ASD whitelist for visual comparison, never skill assignment."""
from pathlib import Path
import argparse,hashlib,json,math,re,sys,xml.etree.ElementTree as E
p=argparse.ArgumentParser();p.add_argument('workspace',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
R=a.workspace;O=R.parent/'origin';D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
mp=D/'all-role-motion-joins.json';np=D/'numeric-family-explicit-link-audit.json';meta=json.loads(mp.read_bytes());numeric=json.loads(np.read_bytes())
carriers=[];cache={}
def arc(carrier):
    if carrier not in cache:
        before=(O/carrier).read_bytes();working=(R/carrier).read_bytes();assert before==working
        old=next(x for x in meta['carriers'] if x['relative_path']==carrier)
        assert sha(before)==old['original_sha256']==old['working_sha256']
        carriers.append({'path':carrier,'originalWorkingSha256':sha(before)})
        cache[carrier]=Archive(O/carrier)
    return cache[carrier]
def xml(b):
    return E.fromstring('<ROOT>'+re.sub(r'<\?xml.*?\?>','',b.decode('euc-kr' if b'euc-kr' in b[:150].lower() else 'utf-8-sig'))+'</ROOT>')
base=arc('Character/Cha/Base.stp');effects=arc('Effect/Effect.stp')
oldEffects={e['member']:e for e in numeric['sourceMembers'] if e['carrier']=='Effect/Effect.stp'}
rows=[];excluded=[];abfs={}
for n in numeric['numericFamilyRows']:
    role=next(r for r in meta['roles'] if r['role']==n['role'])
    if n['role'] not in abfs:
        t=xml(base.read(role['abf_member']));abfs[n['role']]={int(x.get('ID')):x for x in t.findall('.//AnimationList/Animation')}
    m=next(x for x in role['motion_metadata'] if x['motion_id']==n['motion'])
    b=arc(m['asd_carrier']).read(n['asdMember']);assert sha(b)==n['asdSha256']==m['asd_sha256']
    h=xml(b).find('.//AnimationHeader');ab=abfs[n['role']][n['motion']]
    assert int(h.get('ID'))==n['motion'] and ab.get('File')==m['abf_file']
    repeat=h.find('AnimationData').get('Repeat');splits=[dict(x.attrib) for x in h.findall('ReferIndex/SpliteData')]
    assert splits==m['split_rows']
    refs=[]
    for e in n['effects']:
        eb=effects.read(e);assert sha(eb)==oldEffects[e]['originalSha256']==oldEffects[e]['workingSha256'];refs.append({'member':e,'sha256':sha(eb)})
    if repeat!='false' or ab.get('Repeat')!='false':
        excluded.append({'role':n['role'],'motion':n['motion'],'reason':'REPEATING_ANIMATION_NOT_ADMITTED'});continue
    seconds=sum((float(s['EndFrame'])+float(s['Delay']))/float(s['FPS']) for s in splits)
    assert math.isfinite(seconds)
    rows.append({'role':n['role'],'motion':n['motion'],'family':n['numericFamily'],'variant':n['numericVariant'],
        'name':m['abf_file'],'asdMember':n['asdMember'],'asdSha256':sha(b),'effectReferences':refs,
        'nominalSeconds':seconds,'recoveryEstimateSeconds':min(30,max(10,seconds+0.5)) if seconds>0 else 10,
        'status':'RESOURCE_VERIFIED_ACTION_PREVIEW_NOT_SKILL_MAPPING'})
vp=Path(__file__).with_name('video-title-skill-join-v2.json')
videos=json.loads(vp.read_bytes())['videos']
videos.append({'role':4,'active':None,'name':'伊希莉亞技能等級變化（使用者參考）','url':'https://www.youtube.com/watch?v=CSKA-ZXu-Z4'})
out={'schema':'LOCAL_ACTION_PREVIEW_CATALOGUE_V1_NOT_NATIVE_MEF','entries':rows,'videos':videos,'excluded':excluded,
    'videoTitleIndexSha256':sha(vp.read_bytes()),'videoAuthority':'USER_REFERENCE_AND_EXACT_TITLE_JOIN_NOT_VISUAL_MAPPING',
    'sourceMetadataSha256':sha(mp.read_bytes()),'priorNumericAuditSha256':sha(np.read_bytes()),'carriers':carriers,
    'limits':['Existing294 numeric ASD targets only; no inventory rescan or skill/order assignment.',
        'ASD/ABF identity, non-repeat and direct EFF existence are checked, not complete geometry/texture/loader or rendered safety.',
        'Recovery is a conservative10..30-second Server preview watchdog, not a native clock; same-role selection resets it without scene reload.',
        'No skill costs/damage/buffs/AI or Active ID is inferred. Actual visual matching and Client acceptance remain pending.']}
a.output.write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
print(json.dumps({'entries':len(rows),'excluded':len(excluded),'roles':len({r['role'] for r in rows}),'families':len({(r['role'],r['family']) for r in rows}),'sha256':sha(a.output.read_bytes())}))
