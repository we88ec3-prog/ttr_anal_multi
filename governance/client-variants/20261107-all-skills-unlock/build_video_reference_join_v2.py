"""Repair boundary-whitespace joins; retain unjoined user links without guessed IDs."""
from pathlib import Path
import json,hashlib,sys,collections
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace')
P=Path(__file__).parent;sha=lambda b:hashlib.sha256(b).hexdigest()
cp=R/'runtime-observations/2026-11-05-all-skills/all-skills-catalog.json'
raw=cp.read_bytes();assert sha(raw)=='5f4d8310037f985047e903b102f5240f12ede24311a9e59a7e7f9366c935d14b'
c=json.loads(raw);act={x['id']:x for x in c['active_skills_level1']};lookup=collections.defaultdict(set);practice={}
for p in c['practices']:
 if p['category']!='ActiveSkill':continue
 for x in p['skill_level_targets']:
  aid=x['active_skill']
  if aid not in act:continue
  lookup[p['role'],act[aid]['name_tc'].strip()].add(aid);practice[p['role'],aid]=p['id']
vp=P/'user-video-index-108.json';source=json.loads(vp.read_bytes());assert len(source['items'])==108
rows=[];unjoined=[];videos=[]
for v in source['items']:
 ids=lookup[v['role'],v['titleSkillName'].strip()]
 if len(ids)==1:
  aid=next(iter(ids));name=act[aid]['name_tc']
  rows.append(dict(role=v['role'],active=aid,practice=practice[v['role'],aid],name=name.strip(),
   sourceDisplayName=name,sourceVideoTitle=v['titleSkillName'],videoIds=[v['videoId']],
   titleMatchAuthority='EXACT_ROLE_AND_TC_NAME_AFTER_BOUNDARY_WHITESPACE_ONLY_NOT_MOTION_PROOF'))
  videos.append(dict(role=v['role'],active=aid,name=name.strip(),url=v['url']))
 else:
  unjoined.append(dict(role=v['role'],title=v['titleSkillName'],videoId=v['videoId'],
   reason='NO_UNIQUE_ROLE_NAME_AFTER_BOUNDARY_WHITESPACE_ONLY',candidateActiveIds=sorted(ids)))
  videos.append(dict(role=v['role'],active=None,name=v['titleSkillName']+'（影片名稱，技能ID待核對）',url=v['url']))
prior=json.loads((P/'video-title-skill-join.json').read_bytes());before={(r['role'],r['active'],vid) for r in prior['rows'] for vid in r['videoIds']}
after={(r['role'],r['active'],vid) for r in rows for vid in r['videoIds']};assert before<=after
added=after-before;assert added=={(2,19,'wXCISUcUzLA'),(2,2996,'jsp4n0Gia10')}
assert len(rows)==107 and len(unjoined)==1 and unjoined[0]['videoId']=='UdUysoGfQ_k'
out=dict(schema='ROLE_VIDEO_REFERENCE_JOIN_V2',sourceCatalogueSha256=sha(raw),sourceVideoIndexSha256=sha(vp.read_bytes()),
 priorJoinSha256=sha((P/'video-title-skill-join.json').read_bytes()),normalization='BOUNDARY_WHITESPACE_STRIP_ONLY_NO_SYNONYM_OR_HANZI_REWRITE',
 rows=rows,unjoined=unjoined,videos=videos,addedExactJoins=[dict(role=r,active=a,videoId=v) for r,a,v in sorted(added)],
 limits=['Title/name join is not native dispatch, visual comparison or skill behavior proof.',
  'The unjoined video remains accessible with null Active; do not equate lava-name spellings without review.',
  'Prior105 joins retained unchanged; no new video links, source video edits, Client operation or automatic skill unlock.'])
f=P/'video-title-skill-join-v2.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(sha(f.read_bytes()))
