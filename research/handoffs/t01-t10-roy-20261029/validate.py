"""Paused checkpoint identity/workflow checks; no canonical or native promotion."""
import pathlib,json,hashlib,subprocess,sys,os,datetime,collections
D=pathlib.Path(__file__).resolve().parent;R=D.parents[2]
def read(p):return json.loads(p.read_text(encoding='utf8'))
m=read(D/'sources.json');base=m['base_main'];sources=m['sources'];assert len(sources)==127
def old(p):return subprocess.check_output(['git','show',base+':'+p],cwd=R)
for s in sources:
 b=(R/s['source_file']).read_bytes();assert hashlib.sha256(b).hexdigest()==s['source_sha256'];assert hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==s['source_blob_sha']
 assert subprocess.check_output(['git','rev-parse',m['source_head']+':'+s['source_file']],cwd=R,text=True).strip()==s['source_blob_sha']
 if s['already_exact_in_main']:assert subprocess.check_output(['git','rev-parse',base+':'+s['source_file']],cwd=R,text=True).strip()==s['source_blob_sha']
ix=read(R/'research/intake/index.json')['items'];bi=json.loads(old('research/intake/index.json'))['items'];assert ix[:len(bi)]==bi and len(ix)==len(bi)+29
by={s['source_file']:s for s in ix}
for s in sources:assert by[s['source_file']]['integration_status']=='REGISTERED' and not by[s['source_file']]['claim_ids']
for scope,n in [('early',49),('middle',44)]:
 p=read(D/scope/'proposal.json');assert len(p['sources'])==n
 for g in p['groups']:
  for q in g['source_refs']:
   source=by[q['source_file']];assert source['source_blob_sha']==q['source_blob_sha'] and source['source_sha256']==q['source_sha256']
   ls=(R/q['source_file']).read_text(encoding='utf-8-sig').splitlines();ranges=q['source_lines'];ranges=[ranges] if len(ranges)==2 and isinstance(ranges[0],int) else ranges
   for a,z in ranges:assert 1<=a<=z<=len(ls)
immutable=['research/claims/index.json','research/requests/index.json','governance/reviews/index.json','shared/catalog.json','shared/source-review-status.json','shared/integrations/T01-20261029-continuation-02/source-ledger.json','spec/spec-index.json','design/gaps/index.json','design/decisions/index.json','conformance/test-index.json']+[f'kr/tasks/{t}/task.json' for t in ['T01','T03','T08','T10','T16']]
for p in immutable:assert old(p).replace(b'\r\n',b'\n')==(R/p).read_bytes().replace(b'\r\n',b'\n'),p
p='kr/tasks/T10/README.md';a=old(p).decode('utf8').replace('\r\n','\n');b=(R/p).read_text(encoding='utf8');anchor='## 既有任務說明';assert a[a.index(anchor):]==b[b.index(anchor):]
ledger=read(R/'shared/integrations/T01-20261029-continuation-02/source-ledger.json')['rows'];assert sum(by[x['source']]['integration_status']=='REGISTERED' for x in ledger)==194
commands=[['governance/validate_s00.py'],['governance/check_s00_readiness.py','--check'],['governance/check_contract_coverage.py','--check'],['governance/check_s00_reviews.py','--check'],['governance/phase_b_worklist.py','--check'],['governance/phase_b_review_preflight.py','--check'],['-m','unittest','discover','-s','governance/tests','-v'],['research/dispatch/dispatch.py','check'],['-m','unittest','discover','-s','research/dispatch/tests','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/protocol','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/character','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/session','-p','test_*.py','-v']]
checks=[];env=dict(os.environ,PYTHONDONTWRITEBYTECODE='1',PYTHONUTF8='1')
for args in commands:
    p=subprocess.run([sys.executable,'-X','utf8','-B']+args,cwd=R,env=env,capture_output=True,text=True,encoding='utf8');checks.append(dict(command='python -X utf8 -B '+' '.join(args),returncode=p.returncode,stdout=p.stdout.strip(),stderr=p.stderr.strip()));assert p.returncode==0,checks[-1]
out=dict(ok=True,status='PAUSED_BY_USER',validated_against_main=subprocess.check_output(['git','rev-parse','origin/main'],cwd=R,text=True).strip(),completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),exact_branch_blobs=127,preexisting_main_blobs=105,raw_reports_imported=22,new_src=29,proposals_saved=93,new_canonical_claims=0,remaining_branch_canonical=127,remaining_old318=194,new_native_verified=0,checks=checks)
(D/'validation.json').write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps({k:v for k,v in out.items() if k!='checks'}))
