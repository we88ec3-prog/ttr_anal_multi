"""Seven ASD headers and six distinct explicit EFFs; no new skill dispatch claim."""
from pathlib import Path
import hashlib,json,re,sys,collections,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();D=R/'runtime-observations/2026-11-05-all-skills'
jp=D/'all-role-motion-joins.json';j=json.loads(jp.read_bytes());role=next(x for x in j['roles'] if x['role']==2)
oe=Archive(R.parent/'origin/Effect/Effect.stp');we=Archive(R/'Effect/Effect.stp')
oa=Archive(R.parent/'origin/Character/Cha/Avatar/02_Pipa.stp');wa=Archive(R/'Character/Cha/Avatar/02_Pipa.stp')
rows=[];data={}
for mid in [112,113,114,184,185,186,187]:
 m=next(x for x in role['motion_metadata'] if x['motion_id']==mid)
 b=oa.read(m['asd_member']);assert b==wa.read(m['asd_member']) and sha(b)==m['asd_sha256']
 effects=[]
 for ref in m['effects']:
  eb=oe.read(ref['path']);assert eb==we.read(ref['path']) and sha(eb)==ref['sha256'];data[ref['path']]=eb
  root=E.fromstring('<ROOT>'+re.sub(r'<\?xml[^?]*\?>','',eb.decode('utf-8-sig'))+'</ROOT>')
  chosen=[x for x in root.iter('Element') if 'HowitzerGrenade' in x.get('File','') or 'WarningTarget' in x.get('File','')]
  effects.append(dict(member=ref['path'],sha256=sha(eb),counts=dict(collections.Counter(x.get('File') for x in chosen)),
   visualElements=[dict(attributes=dict(x.attrib),children=[dict(tag=c.tag,attributes=dict(c.attrib)) for c in x]) for x in chosen]))
 rows.append(dict(motion=mid,asdMember=m['asd_member'],asdSha256=sha(b),effects=effects))
assert rows[0]['effects'][0]['member']==rows[3]['effects'][0]['member']=='Effect/Character/C_Pipa-BasisGrenade01.eff'
out=dict(schema='PIPA_GRENADE_FINITE_COMPONENT_COMPARISON_V1',sourceMotionMetadataSha256=sha(jp.read_bytes()),
 scope='Only known motions112/113/114/184/185/186/187 and their explicit EFF references (six distinct members)',rows=rows,
 exactReuse=dict(leftMotion=112,rightMotion=184,sharedMember='Effect/Character/C_Pipa-BasisGrenade01.eff',sha256=sha(data['Effect/Character/C_Pipa-BasisGrenade01.eff'])),
 conclusion='Grenade/warning component presence alone cannot uniquely identify strengthened Active2996; numeric motion184 shares byte-identical EFF with old named motion112. Numeric variants have4/6/8/10 warning elements, but not proven hit counts, skill levels or dispatch.',
 limits=['Numeric family does not prove skill/order binding or .gb3-to-.emf native alias.',
  'EFF element count/delay/placement are visual metadata, not projectile AI, damage timing/count or FPS-to-gameplay clock.',
  'No component geometry read, Client execution/changes, inventory rescan, packet sending or native MEF completion.'])
f=D/'pipa-grenade-component-comparison-v1.json';f.write_text(json.dumps(out,indent=2)+'\n',encoding='utf8');print(sha(f.read_bytes()))
