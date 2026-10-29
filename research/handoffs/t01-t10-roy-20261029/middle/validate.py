"""Mechanical R0/link/scope validation, never native or whole-source acceptance."""
import pathlib,json,hashlib,collections
D=pathlib.Path(__file__).resolve().parent;R=D.parents[3]
p=json.loads((D/'proposal.json').read_text(encoding='utf-8'))
inv=json.loads((D.parent/'sources.json').read_text(encoding='utf-8'))
expected={s['source_file']:s for s in inv['sources'] if s['scope']=='middle'}
assert len(p['sources'])==len(expected)==44
assert set(s['source_file'] for s in p['sources'])==set(expected)
groups={g['key']:g for g in p['groups']};assert len(groups)==16
actual={};failed=0
for s in p['sources']:
 q=expected[s['source_file']];raw=(R/s['source_file']).read_bytes();ls=raw.decode('utf-8-sig').splitlines()
 assert hashlib.sha256(raw).hexdigest()==q['source_sha256']==s['source_sha256']
 assert hashlib.sha1(b'blob '+str(len(raw)).encode()+b'\0'+raw).hexdigest()==q['source_blob_sha']==s['source_blob_sha']
 assert q['historical_status']==s['historical_status_preserved']
 assert s['claim_keys'] and all(k in groups for k in s['claim_keys'])
 assert s['disposition'] and s['observations'] and not s['new_native_verification']
 for x in s['source_lines']:assert x['text']=='\n'.join(ls[x['start']-1:x['end']])
 actual[s['source_file']]=s
 if s['excluded_scopes']:
  failed+=1;assert q['number'] in [62,63]
  assert all(groups[x['claim_key']]['evidence_level']=='REFUTED' and x['return_id'].endswith('-001') for x in s['excluded_scopes'])
assert failed==2
linked=set();refs=0
for g in p['groups']:
 assert g['evidence_level'] in ['PARTIAL','UNKNOWN','REFUTED']
 for field in ['key','assertion','evidence_scope','limits','conflicts','affected_spec_ids','existing_claim_ids','source_refs']:assert field in g
 assert g['source_refs']
 for q in g['source_refs']:
  s=actual[q['source_file']];assert g['key'] in s['claim_keys']
  assert q['source_blob_sha']==s['source_blob_sha'] and q['source_sha256']==s['source_sha256']
  a,z=q['source_lines'];assert isinstance(a,int) and a<=z and q['scope_observation']
  assert any(x['start']==a and x['end']==z for x in s['source_lines'])
  assert not q['quality_inheritance'];linked.add(q['source_file']);refs+=1
  if g['evidence_level']=='REFUTED':assert s['excluded_scopes'] and q['source_lines']==[12,12]
assert linked==set(expected)
v=dict(status='PASS',meaning='Identity, exact excerpts, authority links and existing-refutation segregation only.',sources=44,unfinished=0,groups=16,evidence_levels=dict(collections.Counter(g['evidence_level'] for g in p['groups'])),authoritative_source_refs=refs,existing_refuted_scopes=2,appendix_qualification_sources=3,new_native_verified=0,new_full_pass=0)
(D/'validation.json').write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps(v))
