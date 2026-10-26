"""Read-only portable batch checks. Never executes evidence or reads original anal."""
import pathlib,json,hashlib,sqlite3,re,collections
ROOT=pathlib.Path(__file__).resolve().parents[3]
BATCH=pathlib.Path(__file__).resolve().parent
def read(p):return json.loads(p.read_text(encoding='utf-8-sig'))
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    c=read(ROOT/'shared/catalog.json');amap={a['id']:a for a in c['artifacts']}
    assert len(amap)==len(c['artifacts'])
    for a in c['artifacts']:assert digest(ROOT/a['path'])==a['sha256'],a['path']
    db=sqlite3.connect((ROOT/'shared/catalog.sqlite').resolve().as_uri()+'?mode=ro&immutable=1',uri=True);total=0
    for table in ['artifacts','tasks','claims','entities','corrections']:
        rows=db.execute(f'SELECT id,version,record FROM {table}').fetchall();assert len(rows)==len(c[table])
        expected={(x['id'],x.get('version')):x for x in c[table]}
        for ident,version,raw in rows:assert json.loads(raw)==expected[(ident,version)];total+=1
    assert db.execute('pragma integrity_check').fetchone()[0]=='ok';db.close()
    for t in c['tasks']:assert t==read(ROOT/t['version']/'tasks'/t['id']/'task.json'),(t['version'],t['id'])
    for x in read(BATCH/'local-items.json'):assert digest(ROOT/x['path'])==x['sha256']
    for x in read(BATCH/'local-items.json'):
        if x['current_staging_equals_accepted']:assert digest(ROOT/x['staging'])==x['sha256']
    for x in read(BATCH/'remote-review.json'):assert digest(ROOT/x['path'])==x['sha256']
    for x in read(BATCH/'supporting-dependencies.json'):assert digest(ROOT/x['path'])==x['sha256']
    mappings=read(ROOT/'shared/manifests/source-map-v2.json')['sources']
    for a in c['artifacts']:assert any(m['artifact_id']==a['id'] and m['sha256']==a['sha256'] and m['portable_path']==a['path'] for m in mappings),a['id']
    keys=[(e['version'],e['module'],e['va']) for e in c['entities']];assert len(keys)==len(set(keys))
    delta=read(BATCH/'catalog-delta.json')
    for x in delta['entities']['updated']:assert x['before']['primary_task']==x['after']['primary_task']
    links=0
    pages=[ROOT/'AGENTS.md',ROOT/'HANDOFF.md',ROOT/'shared/T07-TOWN-ENTRY-DEPENDENCY-HANDOFF.md',BATCH/'README.md']+[ROOT/t['version']/'tasks'/t['id']/'README.md' for t in c['tasks'] if t.get('integration_handoff')]
    for p in pages:
        for href in re.findall(r'\]\(([^)]+)\)',p.read_text(encoding='utf-8')):
            if '://' in href or href.startswith('#'):continue
            target=(p.parent/href.split('#')[0]).resolve();assert target.is_relative_to(ROOT.resolve()) and target.is_file(),(str(p.relative_to(ROOT)),href)
            links+=1
    return {'ok':True,'artifact_hashes':len(amap),'json_sqlite_records':total,'task_records':len(c['tasks']),'accepted_versions':len(read(BATCH/'local-items.json')),'remote_reports_not_promoted':len(read(BATCH/'remote-review.json')),'formal_links':links,'ownership_unique':True,'source_map_complete':True,'native_semantics_revalidated':False,'playability_accepted':False}
if __name__=='__main__':print(json.dumps(main(),ensure_ascii=False))
