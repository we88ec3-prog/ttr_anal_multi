"""Read-only resource projections for isolated role skill labs.
No native dispatcher mapping is asserted and no game/Server resource is modified.
"""
from pathlib import Path
import json,re,hashlib,collections,sys
R=Path(r'E:\Tartaros\workspace');O=R.parent/'origin';D=R/'runtime-observations/2026-11-05-all-skills';OUT=R/'CLIENT/evidence/20261107-all-matrices'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
c=json.loads((D/'all-skills-catalog.json').read_text(encoding='utf-8-sig'))
j=json.loads((D/'all-role-motion-joins.json').read_text(encoding='utf-8-sig'))
roles={r['role']:r for r in j['roles']};active={a['id']:a for a in c['active_skills_level1']}
joins=collections.defaultdict(list)
for z in j['active_practice_joins']:joins[(z['role'],z['active_skill_id'])].append(z)
motions={(r['role'],m['motion_id']):m for r in j['roles'] for m in r['motion_metadata']}
member_index={(m['carrier'],m['member']):m for m in j['members']}
arcs={};verified={}
def verify(carrier,member,expected=None):
 key=(carrier,member)
 if key in verified:return verified[key]
 if carrier not in arcs:arcs[carrier]=(Archive(O/carrier),Archive(R/carrier))
 a,w=arcs[carrier];name=next(n for n in a.files if n.casefold()==member.casefold());wn=next(n for n in w.files if n.casefold()==member.casefold())
 raw,wr=a.read(name),w.read(wn);assert raw==wr
 digest=sha(raw)
 if expected:assert digest==expected
 verified[key]={'carrier':carrier,'member':name,'original_sha256':digest,'working_sha256':sha(wr),'matched':True}
 return verified[key]
# Cost / matrix / Practice inputs are re-read only for identity, not rewritten.
verify('Table.stp','Table/SkillActiveTable.xml')
for name in c['members']:
 if 'matric' in name.lower():verify('Table.stp',name,c['members'][name]['original_sha256'])
def motion_row(role,ident):
 m=motions[(role,ident)]
 prove=verify(m['asd_carrier'],m['asd_member'],m['asd_sha256'])
 eff=[]
 for e in m['effects']:
  if e['present_in_effect_archive']:eff.append(verify('Effect/Effect.stp',e['path'],e['sha256']))
 return {'motion_id':ident,'asd_member':m['asd_member'],'asd_sha256':prove['original_sha256'],
         'duration_seconds_nominal':m['duration_seconds_candidate_sum_end_plus_delay_over_fps'],
         'abf_length_frame_units':m['abf_length_frame_units'],'header_matches_abf':m['header_matches_abf'],
         'effect_paths':[e['member'] for e in eff]}
def binding(role,skill,mask):
 candidates=joins.get((role,skill),[])
 if len(candidates)!=1:return {'practice_id':None,'status':'UNRESOLVED_NO_UNIQUE_ACTIVE_PRACTICE','single_motion':None,'sequence':[],'basis_candidate_motion_ids':[]}
 z=candidates[0];verify('Table.stp',z['practice_member'])
 basis=[];variant_evidence=[]
 for cm in z['available_motion_candidates']:
  m=motions[(role,cm['motion_id'])]
  tags=[(e['path'],q.group(1).lower()) for e in m['effects'] if (q:=re.search(r'-(Basis|Average|Exper|Master|Super)',e['path'],re.I))]
  if {t[1] for t in tags}=={'basis'}:
   basis.append(cm['motion_id']);variant_evidence.extend({'motion_id':cm['motion_id'],'effect_path':p,'variant':v} for p,v in tags)
 result={'practice_id':z['practice_id'],'practice_member':z['practice_member'],'basis_candidate_motion_ids':basis,
         'single_motion':None,'sequence':[],'variant_evidence':variant_evidence,
         'native_dispatch':'UNRESOLVED','authority':'EXACT_RESOURCE_STEM_AND_EFFECT_VARIANT_CANDIDATE_ONLY'}
 if len(basis)==1:
  result['status']='SINGLE_BASIS_RESOURCE_CANDIDATE';result['single_motion']=motion_row(role,basis[0])
 elif basis:
  # Z chains are resource-sequence candidates only. Non-Z multistage skills remain unresolved.
  seq=[motions[(role,i)] for i in sorted(basis)]
  nums=[]
  for m in seq:
   match=re.search(r'_SKILL01_(\d+)\.asd$',m['abf_file'],re.I)
   if match:nums.append(int(match[1]))
  if mask==1 and nums==list(range(1,len(seq)+1)):
   result['status']='BASIC_Z_RESOURCE_SEQUENCE_CANDIDATE';result['sequence']=[motion_row(role,m['motion_id']) for m in seq]
  else:result['status']='UNRESOLVED_MULTIPLE_BASIS_PHASES'
 else:result['status']='UNRESOLVED_NO_EXACT_RESOURCE_JOIN'
 return result
rows=[]
for ch in c['characters']:
 role=ch['role'];rr=roles[role]
 verify('Character/Cha/Base.stp',rr['abf_member'])
 for e in ch['matrix_entries']:
  mask=e['input_mask_candidate']
  if mask not in (1,2,3,4,5,6):continue
  skill=e['active_skill'];a=active.get(skill)
  row={'role':role,'matrix':e['matrix'],'tier':e['tier'],'column':e['column'],'input_mask':mask,'active_skill_id':skill,
       'activeinfo_level':1,'costs':None,'classification':a['classification'] if a else None}
  if a:
   raw=a['activeinfo_signed_raw'];row['costs']={'hp':-raw['hp'],'sp':-raw['sp'],'mp':-raw['mp'],'raw_cooltime':raw['cooltime']}
  row.update(binding(role,skill,mask));rows.append(row)
default=[x for x in rows if x['matrix']==0 and x['tier']==0]
assert len(default)==54
assert len(rows)==945
summary={'all_matrix_six_key_rows':len(rows),'default_six_rows':len(default),'default_status_counts':dict(collections.Counter(x['status'] for x in default)),'all_status_counts':dict(collections.Counter(x['status'] for x in rows))}
result={'schema':'tartaros-role-skill-lab-resource-candidates-v1','summary':summary,
        'input_catalog_sha256':sha((D/'all-skills-catalog.json').read_bytes()),'input_motion_join_sha256':sha((D/'all-role-motion-joins.json').read_bytes()),
        'selection_policy':'Use actual matrix/tier activeID and its unique ActiveSkill Practice level1. Exact stem candidate refined only by unambiguous Effect -Basis tag. This is a lab resource candidate, never a recovered native dispatch.',
        'rows':rows,'verified_members':list(verified.values()),
        'limitations':['No native active-ID-to-motion dispatcher closure. No per-tier reuse of default active IDs or motion numbers.','Basis/average/exper are resource variant labels; this output chooses basis only as a declared LEVEL1 lab candidate, not official variant admission.','UNRESOLVED rows are not assigned nearest-name or fixed108/109 motions.','Nominal duration is not a recovered cancel/input lock/multihit/impact timing.','Special matrix columns7/8/9/10 and V charge encoding belong to separate research.','Read-only original/working resource verification only; no Client/Server modification, game execution, attachment or MEF search.']}
OUT.mkdir(parents=True,exist_ok=True)
(OUT/'role-skill-lab-candidates.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
(OUT/'matrix0-default-six-lab-candidates.json').write_bytes((json.dumps({'schema':result['schema'],'rows':default,'limitations':result['limitations']},ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
(OUT/'source-members.json').write_bytes((json.dumps(list(verified.values()),indent=2)+'\n').encode('utf-8'))
print(json.dumps(summary));print('verified_members',len(verified))
