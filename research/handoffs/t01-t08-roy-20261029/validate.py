"""Validate this source/claim integration and latest workflow gates, never native semantics."""
import pathlib,json,hashlib,subprocess,io,sys,os,datetime,re,collections
D=pathlib.Path(__file__).resolve().parent;R=D.parents[2]
def read(p):return json.loads(p.read_text(encoding='utf8'))
m=read(D/'sources.json');base=m['base_main'];head=m['source_head'];sources=m['sources'];assert len(sources)==138
def old(p):return subprocess.check_output(['git','show',base+':'+p],cwd=R)
queries=[ref+':'+x['source_file'] for x in sources for ref in [head,base]]
p=subprocess.run(['git','cat-file','--batch'],cwd=R,input=('\n'.join(queries)+'\n').encode(),capture_output=True,check=True);stream=io.BytesIO(p.stdout)
for x in sources:
    for n in range(2):
        h=stream.readline().decode().split();assert h[0]==x['source_blob_sha'] and h[1]=='blob';b=stream.read(int(h[2]));assert stream.read(1)==b'\n';assert (R/x['source_file']).read_bytes()==b;assert hashlib.sha256(b).hexdigest()==x['source_sha256']
ix=read(R/'research/intake/index.json')['items'];cx=read(R/'research/claims/index.json')['items'];before_i=json.loads(old('research/intake/index.json'))['items'];before_c=json.loads(old('research/claims/index.json'))['items']
targetids={x['source_intake_id'] for x in sources};iby={x['id']:x for x in ix};cby={x['id']:x for x in cx}
assert len(ix)==len(before_i)+15
allowed={'integration_status','claim_ids','conflict_disposition','risk_level','intake_action_log','integration_review_ref','limitations','source_branch','source_head'}
for b in before_i:
    a=iby[b['id']]
    if b['id'] not in targetids:assert a==b,b['id'];continue
    assert {k:v for k,v in a.items() if k not in allowed}=={k:v for k,v in b.items() if k not in allowed},b['id']
for b,a in zip(before_c,cx):
    aa=dict(a);bb=dict(b);aa.pop('additional_sources',None);bb.pop('additional_sources',None);assert aa==bb,b['id']
    assert a.get('additional_sources',[])[:len(b.get('additional_sources',[]))]==b.get('additional_sources',[]),b['id']
newclaims=cx[len(before_c):];assert all(x['evidence_level']!='NATIVE_VERIFIED' for x in newclaims)
dis=read(D/'source-dispositions.json')['sources'];assert len(dis)==138 and {x['source_file'] for x in dis}=={x['source_file'] for x in sources}
for x in sources:
    s=iby[x['source_intake_id']];assert s['integration_status']=='CONFLICT_CHECKED' and s['claim_ids'];assert s['source_blob_sha']==x['source_blob_sha'] and s['source_sha256']==x['source_sha256'];assert s['original_document_review_status']==x['historical_status']
for c in cx:
    for a in c.get('additional_sources',[]):
        if a.get('source_intake_id') not in targetids:continue
        s=iby[a['source_intake_id']];assert a['source_file']==s['source_file'] and a['source_blob_sha']==s['source_blob_sha'];assert a['evidence_level'] in ['PARTIAL','UNKNOWN','INFERRED','REFUTED'];assert not a.get('quality_inheritance',True)
for x in dis:
    assert all(i in cby for i in x['claim_ids'])
    for link in x.get('source_links',[]):
        lo,hi=link['source_lines'];assert 1<=lo<=hi<=next(s['lines'] for s in sources if s['source_file']==x['source_file'])
immutable=['research/requests/index.json','governance/reviews/index.json','shared/catalog.json','shared/source-review-status.json','shared/integrations/T01-REVIEW-CURRENT.json','shared/integrations/T01-20261029-continuation-02/source-ledger.json','spec/spec-index.json','design/gaps/index.json','design/decisions/index.json','conformance/test-index.json','conformance/contract-coverage.json']+[f'kr/tasks/{t}/task.json' for t in ['T01','T02','T03','T08','T10','T16']]
for p in immutable:assert old(p).replace(b'\r\n',b'\n')==(R/p).read_bytes().replace(b'\r\n',b'\n'),p
path='kr/tasks/T08/README.md';a=old(path).decode('utf8').replace('\r\n','\n');b=(R/path).read_text(encoding='utf8');anchor='狀態：';assert a[a.index(anchor):]==b[b.index(anchor):]
for p in D.glob('*.md'):
    for href in re.findall(r'\]\(([^)]+)\)',p.read_text(encoding='utf8')):
        if '://' not in href and not href.startswith('#') and href!='validation.json':assert (p.parent/href.split('#')[0]).is_file(),(p,href)
commands=[['governance/validate_s00.py'],['governance/check_s00_readiness.py','--check'],['governance/check_contract_coverage.py','--check'],['governance/check_s00_reviews.py','--check'],['-m','unittest','discover','-s','governance/tests','-v'],['research/dispatch/dispatch.py','check'],['-m','unittest','discover','-s','research/dispatch/tests','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/protocol','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/character','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/session','-p','test_*.py','-v']]
commands.insert(4,['governance/phase_b_worklist.py','--check'])
commands.insert(5,['governance/phase_b_review_preflight.py','--check'])
checks=[];env=dict(os.environ,PYTHONDONTWRITEBYTECODE='1',PYTHONUTF8='1')
for args in commands:
    p=subprocess.run([sys.executable,'-X','utf8','-B']+args,cwd=R,env=env,capture_output=True,text=True,encoding='utf8');checks.append(dict(command='python -X utf8 -B '+' '.join(args),returncode=p.returncode,stdout=p.stdout.strip(),stderr=p.stderr.strip()));assert p.returncode==0,checks[-1]
out=dict(ok=True,completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),base_main=base,source_head=head,exact_source_blobs=138,new_raw_reports_imported=0,new_source_registrations=15,new_claims=len(newclaims),new_claim_levels=dict(collections.Counter(x['evidence_level'] for x in newclaims)),remaining_this_branch=0,new_native_verified=0,old_history_owners_rr_specs_gaps_adr_test_and_s00_decisions_preserved=True,checks=checks,meaning='Source identity, bounded workflow, reference and synthetic checks only; no new native semantic certificate.')
out['validated_against_main']=subprocess.check_output(['git','rev-parse','origin/main'],cwd=R,text=True).strip()
(D/'validation.json').write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps(dict(ok=True,sources=138,new_registrations=15,new_claims=len(newclaims),ci_gates=len(checks),remaining=0,new_fullpass=0)))
