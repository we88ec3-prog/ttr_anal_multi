"""Verify phase records and frozen source identities; no target execution.

This integrity check never produces a semantic FULL_PASS decision.
"""
import pathlib,json,hashlib,collections,re,subprocess
D=pathlib.Path(__file__).resolve().parent;R=D.parents[2]
def read(p):return json.loads(p.read_text(encoding='utf-8'))
def sh(b):return hashlib.sha256(b).hexdigest()
ledger=read(D/'source-ledger.json');rows=ledger['rows'];assert len(rows)==318
assert len({x['source'] for x in rows})==318
assert collections.Counter(x['status'] for x in rows)==ledger['counts']
for x in rows:
    b=(R/x['source']).read_bytes();assert sh(b)==x['sha256'],x['source']
    assert hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==x['git_blob_sha'],x['source']
    assert x['source_whole_document_certified'] is False
    assert x['all_affirmative_claims_reviewed'] is False
assert ledger['document_full_pass']==0 and not ledger['all_documents_complete']
notices=read(D/'return-notices.json')['items'];assert len(notices)==46
assert len({x['return_id'] for x in notices})==46
for x in notices:
    assert (D/x['evidence']).is_file()
    t=(R/f"kr/tasks/{x['task']}/README.md").read_text(encoding='utf-8')
    # Every ID appears as exactly one notification heading; old IDs are updated in place.
    assert len(re.findall(r'^#{3,4} '+re.escape(x['return_id'])+r'\b',t,re.M))==1,x['return_id']
links=0
for p in [D/'README.md',D/'NEXT-STEPS.md',R/'shared/verified-knowledge/client-receiver-exact-lookup-erase-iterator.md']:
    for url in re.findall(r'\]\(([^)]+)\)',p.read_text(encoding='utf-8')):
        if '://' in url or url.startswith('#'):continue
        assert (p.parent/url.split('#')[0]).is_file(),(str(p),url);links+=1
base=ledger['frozen_base'];changed=subprocess.check_output(['git','diff','--name-only',base],cwd=R,text=True).splitlines()
assert all(p in ['HANDOFF.md','kr/tasks/T01/README.md','kr/tasks/T08/README.md','kr/tasks/T10/README.md','kr/tasks/T16/README.md','shared/verified-knowledge/README.md'] or p.startswith('shared/integrations/T01-20261029-semantic-review/') or p=='shared/verified-knowledge/client-receiver-exact-lookup-erase-iterator.md' for p in changed),changed
assert not any(p.endswith('task.json') or p.startswith('shared/catalog') or p.startswith('kr-temp-roy/') for p in changed)
manifest=D/'files-manifest.json'
if manifest.exists():
    for x in read(manifest)['files']:
        p=D/x['path'];assert p.stat().st_size==x['bytes'] and sh(p.read_bytes())==x['sha256'],x['path']
print(json.dumps(dict(ok=True,source_versions=318,counts=ledger['counts'],whole_document_full_pass=0,return_items=46,new_knowledge_entries=3,relative_links_checked=links,catalog_tasks_original_sources_preserved=True,semantic_certification_by_this_validator=False),ensure_ascii=False))
