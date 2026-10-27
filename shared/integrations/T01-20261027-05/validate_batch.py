"""Read-only validation of this bounded integration; never execute captured artifacts."""
import pathlib,json,hashlib,sqlite3,subprocess,sys
R=pathlib.Path(__file__).resolve().parents[3];D=pathlib.Path(__file__).resolve().parent
c=json.loads((R/'shared/catalog.json').read_text(encoding='utf-8'));a={x['id']:x for x in c['artifacts']};claims=json.loads((D/'accepted-claims.json').read_text(encoding='utf-8'));assert len(claims)==25
for key in ['artifacts','claims','entities','corrections']:assert len({x['id'] for x in c[key]})==len(c[key]),key
con=sqlite3.connect((R/'shared/catalog.sqlite').resolve().as_uri()+'?mode=ro&immutable=1',uri=True)
for key in ['artifacts','tasks','claims','entities','corrections']:
 rows=[json.loads(x[0]) for x in con.execute(f'SELECT record FROM {key}')];assert rows==c[key],key
con.close()
for item in json.loads((D/'local-items.json').read_text(encoding='utf-8'))+json.loads((D/'online-items.json').read_text(encoding='utf-8')):
 assert hashlib.sha256((R/item['formal_path']).read_bytes()).hexdigest()==item['sha256'],item['source']
for claim in claims:
 current=next(x for x in c['claims'] if x['id']==claim['id']);assert current==claim
 assert current['limitations'] and current['evidence_ids']
 for eid in current['evidence_ids']:assert eid in a,eid
for t in c['tasks']:
 if t['version']=='kr' and t.get('integration_handoff',{}).get('batch')=='T01-20261027-05':assert json.loads((R/f"kr/tasks/{t['id']}/task.json").read_text(encoding='utf-8'))==t
assert next(t for t in c['tasks'] if t['version']=='kr' and t['id']=='T14')['analysis_paused_by_user'] is True
ledger=json.loads((D/'online-items.json').read_text(encoding='utf-8'));assert len(ledger)==105 and all(x['source_sha_verified'] and x['claim_ids'] and not x['whole_report_semantic_review_complete'] for x in ledger)
audit=json.loads((D/'report-internal-audit.json').read_text(encoding='utf-8'));assert len(audit)==105 and sum(len(x['checks']) for x in audit)==1703 and not any(x['failures'] for x in audit)
index=json.loads((R/'shared/source-review-status.json').read_text(encoding='utf-8'));assert len({x['sha256'] for x in index['sources']})==len(index['sources']) and all(not x['whole_report_native_semantics_complete'] for x in index['sources'])
result={'ok':True,'sqlite_matches_json':True,'source_ledgers_match_artifact_sha':True,'accepted_claims':25,'new_corrections':13,'task_files_match':True,'T14_analysis_paused':True}
if '--compare-base' in sys.argv:
 base=json.loads(subprocess.check_output(['git','show','892a08e30ebcbe680d3171144e5bda35b2b6f79f:shared/catalog.json'],cwd=R))
 assert base['entities']==c['entities']
 assert base['targets']==c['targets'] and base['common_evidence']==c['common_evidence']
 for old in base['tasks']:
  new=next(t for t in c['tasks'] if (t['version'],t['id'])==(old['version'],old['id']))
  assert new['owner']==old['owner'] and new['state']==old['state']
  if old['version']=='tc':assert new==old
 for key in ['claims','corrections']:assert c[key][:len(base[key])]==base[key]
 for old in base['artifacts']:
  new=a[old['id']]
  for k,v in old.items():
   if k in ['original_sources','attributions']:assert all(x in new[k] for x in v)
   else:assert v==new[k],(old['id'],k)
 result['prior_claims_corrections_artifacts_ownership_preserved']=True
print(json.dumps(result,ensure_ascii=False))
