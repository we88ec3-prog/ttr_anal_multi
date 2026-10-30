"""R0/R1 package consistency only; never a native semantic test."""
from pathlib import Path
import json,hashlib,subprocess
D=Path(__file__).resolve().parent;R=D.parents[3]
P=json.loads((D/'proposal.json').read_text(encoding='utf-8'))
I=json.loads((D.parent/'sources.json').read_text(encoding='utf-8'))
expected={x['source_file']:x for x in I['sources'] if x['scope']=='early'}
assert len(expected)==42 and P['source_count']==42
assert {s['source_file'] for s in P['sources']}==set(expected)
assert len(P['sources'])==42 and P['remaining_sources_in_scope']==0
keys={g['key'] for g in P['groups']};assert len(keys)==len(P['groups'])==24
assert all(k.startswith('early-') for k in keys)
assert P['native_promotions']==P['new_native_audits']==P['historical_verdict_changes']==0
obs_count=0
for s in P['sources']:
 e=expected[s['source_file']];b=(R/s['source_file']).read_bytes();lines=b.decode('utf-8-sig').splitlines()
 assert hashlib.sha256(b).hexdigest()==s['source_sha256']==e['source_sha256']
 sha=hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
 assert sha==s['source_blob_sha']==e['source_blob_sha']
 for ref in [P['base_main'],P['source_head']]:
  assert subprocess.check_output(['git','rev-parse',ref+':'+s['source_file']],cwd=R,text=True).strip()==sha
 assert s['historical_status']==e['historical_status'] and s['historical_status_unchanged']
 assert s['observations'] and set(s['claim_keys'])<=keys
 assert s['integration_proposed']=='CONFLICT_CHECKED' and not s['affected_spec_ids']
 for o in s['observations']:
  a,z=o['source_lines'];assert 1<=a<=z<=len(lines)
  assert o['source_excerpt']=='\n'.join(lines[a-1:z])
  assert o['claim_key'] in keys and o['observation'].strip()
  assert set(o['conflict_keys'])<=set(P['conflict_registry'])
  obs_count+=1
assert obs_count==74
for g in P['groups']:
 assert g['evidence_level'] in ['PARTIAL','UNKNOWN']
 assert g['assertion'] and g['limits'] and g['evidence_scope'] and g['source_refs']
 assert not g['affected_spec_ids'] and g['s00_acceptance']=='NOT_REQUESTED_OR_GRANTED'
 assert set(g['existing_claim_ids'])<= {'CLM-CLIENT-0002'}
 if g['existing_claim_ids']:assert g['key']=='early-pool-lifecycle' and g['existing_claim_reuse_scope']
 actual={(s['source_file'],tuple(o['source_lines']),o['observation']) for s in P['sources'] for o in s['observations'] if o['claim_key']==g['key']}
 claimed={(x['source_file'],tuple(x['source_lines']),x['scope_observation']) for x in g['source_refs']}
 assert actual==claimed
 for c in g['conflicts']:
  assert c['disposition'] and c['r2_if_needed']
  for ref in c['refs']:assert (R/ref).is_file(),ref
for c in P['conflict_registry'].values():
 for ref in c['refs']:assert (R/ref).is_file(),ref
claims=json.loads((R/'research/claims/index.json').read_text(encoding='utf-8'))
items=claims.get('items',claims.get('claims',[]));assert any(x.get('id')=='CLM-CLIENT-0002' for x in items)
result=dict(ok=True,scope='early',sources=42,remaining_in_scope=0,groups=24,observations=74,levels={k:sum(g['evidence_level']==k for g in P['groups']) for k in ['PARTIAL','UNKNOWN']},all_source_sha_blob_and_two_commits_match=True,all_excerpt_line_ranges_match=True,source_group_edges_match=True,known_conflict_refs_exist=True,history_unchanged=True,native_promotions=0,native_audits=0,s00_acceptance=False,limitation='Mechanical R0/R1 package validation, not native semantic or whole-report acceptance.')
(D/'validation.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
manifest=[]
for p in sorted(D.glob('*')):
 if p.is_file() and p.name!='manifest.json':
  b=p.read_bytes();manifest.append(dict(path=p.name,sha256=hashlib.sha256(b).hexdigest(),bytes=len(b)))
(D/'manifest.json').write_text(json.dumps(dict(files=manifest),ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps(result,ensure_ascii=False))
