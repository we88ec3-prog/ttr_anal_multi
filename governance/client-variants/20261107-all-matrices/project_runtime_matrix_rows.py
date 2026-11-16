"""Project reviewed all-matrix resource candidates to flat local Server lab rows."""
from pathlib import Path
import json,collections
R=Path(r'E:\Tartaros\workspace');D=R/'CLIENT/evidence/20261107-all-matrices';B=R/'runtime-observations/2026-11-05-all-skills'
x=json.loads((D/'role-skill-lab-candidates.json').read_text(encoding='utf-8-sig'))
c=json.loads((B/'all-skills-catalog.json').read_text(encoding='utf-8-sig'))
j=json.loads((B/'all-role-motion-joins.json').read_text(encoding='utf-8-sig'))
oldidx={(m['carrier'],m['member']):m for m in j['members']}
for m in x['verified_members']:
 old=c['members'].get(m['member']) if m['carrier']=='Table.stp' else oldidx.get((m['carrier'],m['member']))
 assert old is not None
 assert old['original_sha256']==m['original_sha256'] and old['working_sha256']==m['working_sha256']
motions={(rr['role'],m['motion_id']):m for rr in j['roles'] for m in rr['motion_metadata']};rows=[]
for z in x['rows']:
 selected=[z['single_motion']] if z['single_motion'] else z['sequence']
 if z['status']=='UNRESOLVED_MULTIPLE_BASIS_PHASES':
  selected=[{'motion_id':i,'duration_seconds_nominal':motions[(z['role'],i)]['duration_seconds_candidate_sum_end_plus_delay_over_fps']} for i in z['basis_candidate_motion_ids']]
 ready=z['status'] in ['SINGLE_BASIS_RESOURCE_CANDIDATE','BASIC_Z_RESOURCE_SEQUENCE_CANDIDATE'];cost=z['costs'] or {}
 rows.append({'role':z['role'],'matrix':z['matrix'],'tier':z['tier'],'mask':z['input_mask'],'practice':z['practice_id'],'active':z['active_skill_id'],
              'hp':cost.get('hp',0),'sp':cost.get('sp',0),'mp':cost.get('mp',0),'rawCooldown':cost.get('raw_cooltime',0),
              'motions':[m['motion_id'] for m in selected],'durationSeq':[m['duration_seconds_nominal'] for m in selected],
              'status':z['status'],'blocked':not ready,'isBasicChain':z['status']=='BASIC_Z_RESOURCE_SEQUENCE_CANDIDATE',
              'authority':'LAB_RESOURCE_CANDIDATE_NOT_NATIVE_DISPATCH'})
result={'schema':'tartaros-role-skill-lab-runtime-matrix-rows-v1','matrices':list(range(7)),'practiceLevel':1,'rows':rows,
        'sourceManifest':'role-skill-lab-candidates.json','memberIdentities':'source-members.json',
        'sourceMembersReverified':len(x['verified_members']),'limitations':x['limitations']}
(D/'runtime-matrix-rows.json').write_bytes((json.dumps(result,indent=2)+'\n').encode('utf-8'))
print('ready',sum(not r['blocked'] for r in rows),'blocked',sum(r['blocked'] for r in rows))

summary={'rows':len(rows),'ready':sum(not r['blocked'] for r in rows),'blocked':sum(r['blocked'] for r in rows),'statusCounts':dict(collections.Counter(r['status'] for r in rows)),'roles':[]}
for role in range(1,10):
 rr=[r for r in rows if r['role']==role];acts=[]
 for active in sorted(set(r['active'] for r in rr)):
  ar=[r for r in rr if r['active']==active];one=ar[0]
  assert all((r['practice'],r['status'],r['motions'])==(one['practice'],one['status'],one['motions']) for r in ar)
  acts.append({'active':active,'practice':one['practice'],'status':one['status'],'blocked':one['blocked'],'motions':one['motions'],'slots':[{'matrix':r['matrix'],'tier':r['tier'],'mask':r['mask']} for r in ar]})
 assert len(acts)==27
 summary['roles'].append({'role':role,'distinctActiveCount':len(acts),'readyDistinctActives':sum(not r['blocked'] for r in acts),'blockedDistinctActives':sum(r['blocked'] for r in acts),'actives':acts})
(D/'summary.json').write_bytes((json.dumps(summary,indent=2)+'\n').encode('utf-8'))
print('distinct active statuses',[(r['role'],r['readyDistinctActives'],r['blockedDistinctActives']) for r in summary['roles']])
