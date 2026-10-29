"""Source/correction/registry consistency plus current main's nine CI gates; no semantic auto-pass."""
import pathlib,json,hashlib,subprocess,io,re,sys,os,datetime
D=pathlib.Path(__file__).resolve().parent;R=D.parents[2]
def read(p):return json.loads(p.read_text(encoding='utf8'))
manifest=read(D/'sources.json');base=manifest['base_main'];source_head=manifest['source_head']
def old(p):return subprocess.check_output(['git','show',base+':'+p],cwd=R)
rows=manifest['sources'];assert len(rows)==19 and {x['number'] for x in rows}==set(range(1,20))
p=subprocess.run(['git','cat-file','--batch'],cwd=R,input=('\n'.join(source_head+':'+x['source_file'] for x in rows)+'\n').encode(),capture_output=True,check=True);stream=io.BytesIO(p.stdout)
for x in rows:
    h=stream.readline().decode().split();assert h[0]==x['source_blob_sha'] and h[1]=='blob';b=stream.read(int(h[2]));assert stream.read(1)==b'\n'
    assert (R/x['source_file']).read_bytes()==b
    assert hashlib.sha256(b).hexdigest()==x['source_sha256'];assert len(b)==x['bytes']
assert sum(x['bytes'] for x in rows)==283064
before_i=json.loads(old('research/intake/index.json'))['items'];after_i=read(R/'research/intake/index.json')['items'];assert before_i==after_i[:len(before_i)]
before_c=json.loads(old('research/claims/index.json'))['items'];after_c=read(R/'research/claims/index.json')['items']
for before,after in zip(before_c,after_c):
    stripped=dict(after);stripped.pop('additional_sources',None);baseline=dict(before);baseline.pop('additional_sources',None);assert stripped==baseline,before['id']
    assert after.get('additional_sources',[])[:len(before.get('additional_sources',[]))]==before.get('additional_sources',[])
newsrc=after_i[len(before_i):];newclaims=after_c[len(before_c):];assert len(newsrc)==19 and len(newclaims)==13
assert all(x['integration_status']=='CONFLICT_CHECKED' and x['original_document_review_status']=='PENDING' for x in newsrc)
assert not any(x['evidence_level']=='NATIVE_VERIFIED' for x in newclaims)
assert {k:sum(x['evidence_level']==k for x in newclaims) for k in ['PARTIAL','INFERRED','REFUTED']}==dict(PARTIAL=11,INFERRED=1,REFUTED=1)
allsource={x['id']:x for x in after_i};newids={x['id'] for x in newsrc};extra=[]
for c in after_c:
    for a in c.get('additional_sources',[]):
        if a['source_intake_id'] not in newids:continue
        s=allsource[a['source_intake_id']]
        assert a['source_file']==s['source_file'] and a['source_blob_sha']==s['source_blob_sha'] and a['client_version']=='kr'
        assert c['id'] in s['claim_ids'] and not a['quality_inheritance'];extra.append(a)
assert len(extra)==10
for p in ['research/requests/index.json','shared/catalog.json','spec/spec-index.json','design/gaps/index.json','design/decisions/index.json','conformance/test-index.json','conformance/contract-coverage.json','shared/integrations/T01-REVIEW-CURRENT.json','shared/integrations/T01-20261029-continuation-02/source-ledger.json']+[f'kr/tasks/{t}/task.json' for t in ['T01','T02','T03','T04','T05','T06']]:
    assert old(p).replace(b'\r\n',b'\n')==(R/p).read_bytes().replace(b'\r\n',b'\n'),p
path='kr/tasks/T03/README.md';oldtext=old(path).decode('utf8').replace('\r\n','\n');newtext=(R/path).read_text(encoding='utf8');anchor='狀態：'
assert oldtext[oldtext.index(anchor):]==newtext[newtext.index(anchor):]
assert len(re.findall(r'^### T01-RETURN-T03-006-LAYOUT-001 — NEEDS_FIX$',newtext,re.M))==1
for p in D.glob('*.md'):
    for href in re.findall(r'\]\(([^)]+)\)',p.read_text(encoding='utf8')):
        if '://' not in href and not href.startswith('#') and href!='validation.json':assert (p.parent/href.split('#')[0]).is_file(),(p,href)
checks=[];commands=[['governance/validate_s00.py'],['governance/check_s00_readiness.py','--check'],['governance/check_contract_coverage.py','--check'],['-m','unittest','discover','-s','governance/tests','-v'],['research/dispatch/dispatch.py','check'],['-m','unittest','discover','-s','research/dispatch/tests','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/protocol','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/character','-p','test_*.py','-v'],['-m','unittest','discover','-s','conformance/session','-p','test_*.py','-v']]
env=dict(os.environ,PYTHONDONTWRITEBYTECODE='1',PYTHONUTF8='1')
for args in commands:
    p=subprocess.run([sys.executable,'-X','utf8','-B']+args,cwd=R,env=env,capture_output=True,text=True,encoding='utf8');checks.append(dict(command='python -X utf8 -B '+' '.join(args),returncode=p.returncode,stdout=p.stdout.strip(),stderr=p.stderr.strip()));assert p.returncode==0,checks[-1]
out=dict(ok=True,completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),source_head=source_head,base_main=base,exact_source_blobs=19,source_bytes=283064,new_claims=13,additional_source_relations=10,new_native_verified=0,remaining_this_batch=0,spec_consumable=0,old318_ledger_and_rr_specs_gaps_adr_test_owners_preserved=True,old_claim_assertions_and_quality_preserved=True,source_task_research_body_preserved=True,checks=checks,meaning='Workflow/source/reference and offline synthetic integrity only. R2 bytes/import proof separate; no new full-document or gameplay certificate.')
(D/'validation.json').write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps(dict(ok=True,sources=19,new_claims=13,extra_source_relations=10,ci_gates=len(checks),remaining=0,new_fullpass=0)))
