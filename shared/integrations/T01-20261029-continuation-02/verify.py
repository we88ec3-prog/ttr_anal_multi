"""Mechanical integrity and review coverage checks, not a semantic verdict generator."""
import pathlib,json,hashlib,subprocess,collections,re
D=pathlib.Path(__file__).resolve().parent;R=D.parents[2]
BASE='fd8507169932ee9cb9d9362fcab07a5a3bd9bfa5'
def read(p):return json.loads(p.read_text(encoding='utf-8'))
L=read(D/'source-ledger.json');assert len(L['rows'])==318
assert dict(collections.Counter(x['status'] for x in L['rows']))==L['counts']
for x in L['rows']:
    b=(R/x['source']).read_bytes()
    assert hashlib.sha256(b).hexdigest()==x['sha256'],x['source']
    assert hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==x['git_blob_sha']
    original=subprocess.check_output(['git','show',BASE+':'+x['source']],cwd=R)
    assert original==b,x['source']
current=read(D/'reviewed-sources.json')['sources'];assert len(current)==10
full=[x for x in current if x['source_whole_document_certified']]
assert all(x['status']=='FULL_PASS_DOCUMENT_SCOPED' and x['all_affirmative_claims_reviewed'] for x in full)
assert L['document_full_pass']==len(full)
for t in ['T08','T10','T16']:
    p=f'kr/tasks/{t}/README.md'
    old=subprocess.check_output(['git','show',BASE+':'+p],cwd=R).decode('utf-8').replace('\r\n','\n')
    new=(R/p).read_text(encoding='utf-8');anchor='狀態：' if '狀態：' in old else '> 規劃文件'
    assert old[old.index(anchor):]==new[new.index(anchor):],t
for p in ['shared/catalog.json']+[f'kr/tasks/{t}/task.json' for t in ['T01','T08','T10','T16']]:
    assert subprocess.check_output(['git','show',BASE+':'+p],cwd=R).replace(b'\r\n',b'\n')==(R/p).read_bytes().replace(b'\r\n',b'\n'),p
for x in read(D/'return-notices.json')['items']:
    text=(R/f"kr/tasks/{x['task']}/README.md").read_text(encoding='utf-8')
    assert len(re.findall(r'^#{3,4} '+re.escape(x['id'])+r' — ',text,re.M))==1,x['id']
print(json.dumps(dict(ok=True,source_versions=318,current_batch_sources=10,counts=L['counts'],document_full_pass=len(full),task_bodies_catalog_owners_and_original_sources_preserved=True,semantic_verdicts_generated_by_validator=False),ensure_ascii=False))
