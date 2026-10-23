"""Incremental organizational refinement; preserves original anal."""
import ast,collections,gzip,hashlib,json,pathlib,re,shutil,sqlite3
ROOT=pathlib.Path(__file__).resolve().parent.parent
SRC=ROOT.parent/'anal'
def dump(p,o):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(o,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
def main():
    cp=ROOT/'shared/catalog.json';c=json.loads(cp.read_text(encoding='utf-8'));backup=ROOT/'history/checkpoint-v1.json.gz'
    if backup.exists():raise RuntimeError('Refinement already started; do not overwrite history')
    backup.parent.mkdir(exist_ok=True)
    with gzip.open(backup,'wt',encoding='utf-8') as f:json.dump({'catalog':c,'checkpoint':json.loads((ROOT/'CHECKPOINT.json').read_text(encoding='utf-8'))},f,ensure_ascii=False)
    srcmap={p:a for a in c['artifacts'] for p in a['original_sources']};changes=[]
    # Bind script/output attribution only when the script explicitly checks original
    # Tartaros.bin against the hashed index and names a packaged exact-SHA audit.
    for a in c['artifacts']:
        if a['version']!='unclassified':continue
        raw=(ROOT/a['path']).read_text(encoding='utf-8-sig',errors='replace')
        if any(p.endswith('.py') for p in a['original_sources']) and 'Tartaros.bin' in raw and 'sha256' in raw:
            names=set(re.findall(r'[\w-]+audit\.json',raw));matches=[]
            for n in names:
                other=srcmap.get('native-index/'+n)
                if not other:continue
                try:d=json.loads((ROOT/other['path']).read_text(encoding='utf-8-sig'))
                except (ValueError,UnicodeError):continue
                if d.get('sha256')==c['targets']['kr']['sha256']:matches.append(other['id'])
            if matches:
                a['version']='kr';a['identity_basis']='Producer attribution: script names original Tartaros.bin and exact-SHA audit; outputs not semantically revalidated';a['identity_evidence_ids']=matches;changes.append(a['id'])
    # Reports and plain listings can be attributed through explicit producer references.
    for a in c['artifacts']:
        if a['version']!='unclassified':continue
        links=[]
        for r in c['reference_status']:
            if r['from_artifact']==a['id'] and r.get('target_artifact'):
                b=next((x for x in c['artifacts'] if x['id']==r['target_artifact']),None)
                if b and b.get('identity_evidence_ids'):links.append(b['id'])
        if links and any(p.endswith('.md') for p in a['original_sources']):
            a['version']='kr';a['identity_basis']='Historical report explicitly references a producer linked to exact-KR-SHA audit; not new semantic proof';a['identity_evidence_ids']=list(set(links));changes.append(a['id'])
    # Remove only ancillary tooling schemas; do not remove actual analysis evidence.
    excluded=[a for a in c['artifacts'] if all(pathlib.Path(p).name in ('tool-schemas.json','batch-tool-schemas.json') for p in a['original_sources'])]
    removed={a['id'] for a in excluded};c['artifacts']=[a for a in c['artifacts'] if a['id'] not in removed]
    for a in excluded:
        p=(ROOT/a['path']).resolve();assert p.is_relative_to(ROOT.resolve());p.unlink()
    for name in ('tasks','claims','corrections'):
        for r in c[name]:r['evidence_ids']=[x for x in r.get('evidence_ids',[]) if x not in removed]
    for v in c['common_evidence']:c['common_evidence'][v]=[x for x in c['common_evidence'][v] if x not in removed]
    c['reference_status']=[r for r in c['reference_status'] if r['from_artifact'] not in removed]
    amap={a['id']:a for a in c['artifacts']}
    for r in c['reference_status']:
        if r.get('target_artifact') in removed:r['target_artifact']=None;r['status']='excluded-tool-schema'
        r['scope']='historical-reference-not-a-required-new-claim'
    # Keep portable claim evidence explicit. Add provenance dependencies transitively.
    for t in c['tasks']:
        ids=set(t['evidence_ids']);queue=list(ids)
        for aid in queue:
            for dep in amap[aid].get('identity_evidence_ids',[]):
                if dep not in ids:ids.add(dep);queue.append(dep)
        t['evidence_ids']=sorted(ids)
        t['unresolved_dependencies']=[r for r in c['reference_status'] if r['from_artifact'] in ids and r['status']!='packaged']
        t['archival_reference_count']=len(t['unresolved_dependencies'])
        t['handoff_scope']='Offline audit of the captured records and listed unknowns only; original binary and analysis engine are separately required for new analysis.'
        t['handoff_status']='bounded-review-handoff' if t['version']=='kr' else 'background-only-native-evidence-missing'
    # Register all additional method addresses from already-packaged semantics,
    # without promoting candidate boundaries or inventing ownership.
    known={e['id'] for e in c['entities']};unclaimed=[]
    for a in c['artifacts']:
        if not any('semantic-records.json' in p for p in a['original_sources']):continue
        try:d=json.loads((ROOT/a['path']).read_text(encoding='utf-8-sig'))
        except ValueError:continue
        records=d if isinstance(d,list) else d.get('records',[])
        for r in records:
            if not isinstance(r,dict) or not r.get('address'):continue
            va=int(r['address'],16) if isinstance(r['address'],str) else r['address'];key=c['targets']['kr']['sha256']+':Tartaros.bin:'+hex(va-0x400000)
            if key not in known:
                unclaimed.append({'id':key,'version':'kr','module':'Tartaros.bin','source_sha256':c['targets']['kr']['sha256'],'va':hex(va),'rva':hex(va-0x400000),'primary_task':None,'person_owner':None,'kind':'retained-method-needs-assignment','evidence_ids':[a['id']],'boundary_status':'retained record; no new boundary validation'});known.add(key)
    c['entities'].extend(unclaimed);c['organization_revision']=2
    dump(cp,c)
    db=ROOT/'shared/catalog.sqlite';db.unlink();con=sqlite3.connect(db)
    for table in ('artifacts','tasks','claims','entities','corrections'):
        con.execute(f'create table {table}(id text,version text,task text,record text)')
        for r in c[table]:con.execute(f'insert into {table} values(?,?,?,?)',(r['id'],r.get('version'),r.get('task',r.get('primary_task')),json.dumps(r,ensure_ascii=False)))
    con.commit();con.close()
    for t in c['tasks']:
        folder=ROOT/t['version']/'tasks'/t['id'];dump(folder/'task.json',t)
        claims=[x for x in c['claims'] if x['version']==t['version'] and x['task']==t['id']]
        txt=f'# {t["id"]} {t["title"]}\n\n狀態：{t["handoff_status"]}；未認領。\n\n## 範圍\n\n{t["scope"]}\n\n{t["excluded_scope"]}\n\n## 已有結論與缺口\n\n'+'\n'.join('- **'+x['status']+'**：'+x['statement'] for x in claims)+'\n\n## 依賴與驗收\n\n依賴：'+(', '.join(t['dependencies']) or '版本共用來源')+'。只認領本任務主範圍，共用方法查shared/catalog.json。\n\n'+'\n'.join('- '+s for s in t['acceptance']+t['next_steps'])+'\n\n## 證據\n\n'
        for aid in t['evidence_ids']:
            a=amap[aid];txt+=f'- [{a["original_sources"][0]}](../../../{a["path"]})\n'
        txt+='\n歷史未打包引用見task.json；不得把背景來源當完整證明。原檔與引擎另行提供，不執行舊腳本。\n';(folder/'README.md').write_text(txt,encoding='utf-8')
    dump(ROOT/'unclassified/selected-sources.json',[a for a in c['artifacts'] if a['version']=='unclassified'])
    report={'revision':2,'attribution_updates':len(changes),'remaining_unclassified_artifacts':sum(a['version']=='unclassified' for a in c['artifacts']),'removed_tool_schema_artifacts':excluded,'additional_unclaimed_methods':len(unclaimed),'native_semantic_changes':0}
    dump(ROOT/'validation/refinement.json',report);print(json.dumps({k:v for k,v in report.items() if k!='removed_tool_schema_artifacts'}))
if __name__=='__main__':main()
