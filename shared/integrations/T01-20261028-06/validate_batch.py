"""Read-only validation of this bounded integration; never execute captured artifacts."""
import pathlib,json,hashlib,sqlite3,subprocess,sys
R=pathlib.Path(__file__).resolve().parents[3];D=pathlib.Path(__file__).resolve().parent
c=json.loads((R/'shared/catalog.json').read_text(encoding='utf-8'));a={x['id']:x for x in c['artifacts']};claims=json.loads((D/'accepted-claims.json').read_text(encoding='utf-8'));assert len(claims)==29
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
 if t['version']=='kr' and t.get('integration_handoff',{}).get('batch')=='T01-20261028-06':assert json.loads((R/f"kr/tasks/{t['id']}/task.json").read_text(encoding='utf-8'))==t
assert next(t for t in c['tasks'] if t['version']=='kr' and t['id']=='T14')['analysis_paused_by_user'] is True
assert len(c['tasks'])==32
for v in ['kr','tc']:
 t=next(x for x in c['tasks'] if x['version']==v and x['id']=='T16');assert t['owner'] is None and t['state']=='unclaimed' and t['native_complete'] is False
for x in claims:
 if x['version']=='tc':assert not x['method_addresses']
resource=json.loads((D/'resource-source-audit.json').read_text(encoding='utf-8'));assert resource['summary']['independent_selected_resource_member_decodes']==96 and len(resource['lua_static_validation'])==12
byte=json.loads((D/'online-byte-source-audit.json').read_text(encoding='utf-8'));assert byte['summary']['matched_windows']==14009 and byte['summary']['nonmatching_windows']==0 and byte['summary']['local_saved_windows_matched']==38
result={'ok':True,'sqlite_matches_json':True,'source_ledgers_match_artifact_sha':True,'accepted_claims':29,'new_corrections':12,'task_files_match':True,'T14_analysis_paused':True}
if '--compare-base' in sys.argv:
 base=json.loads(subprocess.check_output(['git','show','b8e97085c08833f66fbd06ee4ef3bf7d32276409:shared/catalog.json'],cwd=R))
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
