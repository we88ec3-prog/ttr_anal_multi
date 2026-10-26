"""Portable query, integrity validation and task export. Python 3.10+, stdlib only."""
import argparse, hashlib, json, pathlib, shutil, sqlite3, zipfile, re
def digest(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda:f.read(1024*1024),b''):h.update(b)
    return h.hexdigest()
def safe(root,rel):
    p=(root/rel).resolve()
    if not p.is_relative_to(root.resolve()):raise ValueError('Path outside package: '+rel)
    return p
def write(p,obj):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(obj,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
def catalog(root):return json.loads((root/'shared/catalog.json').read_text(encoding='utf-8'))
def verify(root):
    c=catalog(root); failures=[];ids={a['id'] for a in c['artifacts']}
    for a in c['artifacts']:
        p=safe(root,a['path'])
        if not p.is_file() or digest(p)!=a['sha256']:failures.append('artifact '+a['id'])
    for table in ('tasks','claims','corrections'):
        for r in c[table]:
            for eid in r.get('evidence_ids',[]):
                if eid not in ids:failures.append('missing evidence '+eid)
    amap={a['id']:a for a in c['artifacts']}
    for a in c['artifacts']:
        for dep in a.get('identity_evidence_ids',[]):
            if dep not in ids:failures.append('missing provenance '+dep)
    for r in c.get('reference_status',[]):
        if r.get('target_artifact') and r['target_artifact'] not in ids:failures.append('reference target '+r['target_artifact'])
    for claim in c['claims']:
        loc=claim.get('location',{})
        if not loc or not claim.get('evidence_ids'):continue
        p=safe(root,amap[claim['evidence_ids'][0]]['path'])
        if 'json_pointer' in loc:
            value=json.loads(p.read_text(encoding='utf-8-sig'))
            for key in loc['json_pointer'].strip('/').split('/'):value=value[key]
            if value!=loc['value']:failures.append('JSON locator '+claim['id'])
        if 'matching_lines' in loc:
            lines=p.read_text(encoding='utf-8-sig').splitlines()
            if not loc['matching_lines'] or any(n>len(lines) or loc['anchor'].lower() not in lines[n-1].lower() for n in loc['matching_lines']):failures.append('line locator '+claim['id'])
    owners={}
    for e in c['entities']:
        if e['id'] in owners and owners[e['id']]!=e['primary_task']:failures.append('ownership '+e['id'])
        owners[e['id']]=e['primary_task']
    manifest=root/'manifest.json'
    if manifest.exists():
        for row in json.loads(manifest.read_text(encoding='utf-8'))['files']:
            p=safe(root,row['path'])
            if not p.is_file() or digest(p)!=row['sha256']:failures.append('manifest '+row['path'])
    db=root/'shared/catalog.sqlite'
    if db.exists():
        con=sqlite3.connect(db.resolve().as_uri()+'?mode=ro&immutable=1',uri=True)
        if con.execute('pragma integrity_check').fetchone()[0]!='ok':failures.append('sqlite integrity')
        con.close()
    unresolved=[r for r in c.get('reference_status',[]) if r['status']!='packaged']
    result={'ok':not failures,'artifact_integrity_ok':not failures,'required_package_dependencies_ok':not failures,'historical_reference_closure_ok':not unresolved,'native_evidence_complete':False,'unresolved_archival_references':len(unresolved),'artifacts':len(ids),'tasks':len(c['tasks']),'claims':len(c['claims']),'failures':failures,'native_semantics_revalidated':False,'original_directory_required_for_reading_and_integrity_check':False}
    print(json.dumps(result,ensure_ascii=False));return result
def export(root,version,task,out):
    c=catalog(root); t=next(t for t in c['tasks'] if t['version']==version and t['id']==task)
    if out.exists():raise ValueError('Output already exists; choose a new package path')
    # Explicit one-hop interfaces, not recursive dependency/entire source-tree copying.
    wanted={task,*t['dependencies']};ts=[json.loads(json.dumps(x)) for x in c['tasks'] if x['version']==version and x['id'] in wanted]
    for x in ts:
        x['package_role']='primary-task' if x['id']==task else 'interface-context-only'
        x['unexpanded_task_dependencies']=[d for d in x['dependencies'] if d not in wanted]
    cs=[x for x in c['claims'] if x['version']==version and x['task'] in wanted]
    corrections=[x for x in c['corrections'] if x['version']==version and set(x['tasks'])&wanted]
    ids=set(c['common_evidence'][version])
    for r in ts+cs+corrections:ids.update(r.get('evidence_ids',[]))
    amap={a['id']:a for a in c['artifacts']};queue=list(ids)
    for aid in queue:
        for dep in amap[aid].get('identity_evidence_ids',[]):
            if dep not in ids:ids.add(dep);queue.append(dep)
    selected=[a for a in c['artifacts'] if a['id'] in ids]
    assert len(selected)==len(ids)
    refs=[dict(r) for r in c.get('reference_status',[]) if r['from_artifact'] in ids]
    for r in refs:
        if r.get('target_artifact') not in ids:
            r['target_artifact']=None
            if r['status']=='packaged':r['status']='outside-task-export-not-portable-evidence'
    part={**c,'targets':{version:c['targets'][version]},'tasks':ts,'claims':cs,'corrections':corrections,'artifacts':selected,'entities':[x for x in c['entities'] if x['version']==version and x['primary_task'] in wanted],'common_evidence':{version:c['common_evidence'][version]},'deferred_evidence':[],'reference_status':refs,'export_scope':{'primary_task':task,'version':version,'interface_tasks':sorted(wanted-{task}),'dependency_policy':'one-hop interface evidence; not a claim of full dependent-task handoff','status':t['handoff_status']}}
    out.mkdir(parents=True);write(out/'shared/catalog.json',part)
    shutil.copy2(root/'shared/handoff.py',out/'shared/handoff.py')
    for a in selected:
        dst=safe(out,a['path']);dst.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(safe(root,a['path']),dst)
    for x in ts:
        p=pathlib.Path(version)/'tasks'/x['id'];(out/p).mkdir(parents=True,exist_ok=True)
        write(out/p/'task.json',x)
        content=(root/p/'README.md').read_text(encoding='utf-8')
        if x['id']!=task:content='> 此任務僅提供介面背景，並非整項任務的完整交接。未展開依賴見 task.json。\n\n'+content
        (out/p/'README.md').write_text(content,encoding='utf-8')
    # Task handoff links must remain readable in an isolated task export.
    batches={x.get('integration_handoff',{}).get('batch') for x in ts}
    for batch in sorted(b for b in batches if b):
        rel=pathlib.Path('shared/integrations')/batch
        source=safe(root,rel.as_posix())
        if not source.is_dir():raise ValueError('Missing integration handoff: '+str(rel))
        shutil.copytree(source,safe(out,rel.as_posix()))
    # Close supplemental Markdown handoff links without copying entire staging trees.
    queue=list(out.rglob('*.md'));seen=set()
    for page in queue:
        if page in seen:continue
        seen.add(page)
        for href in re.findall(r'\]\(([^)]+)\)',page.read_text(encoding='utf-8')):
            if '://' in href or href.startswith('#'):continue
            target=(page.parent/href.split('#')[0]).resolve()
            if not target.is_relative_to(out.resolve()):raise ValueError('Handoff link outside export: '+href)
            if not target.exists():
                source=safe(root,target.relative_to(out.resolve()).as_posix())
                if not source.is_file():raise ValueError('Missing handoff dependency: '+str(source))
                target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(source,target)
            if target.suffix.lower()=='.md':queue.append(target)
    write(out/'shared/targets.json',part['targets'])
    (out/'README.md').write_text(f'# {version.upper()} {task} 獨立交接包\n\n入口：[{t["title"]}]({version}/tasks/{task}/README.md)。\n\n狀態：{t["handoff_status"]}。只讀審核現有證據；不代表功能完成。\n\n```powershell\npython shared/handoff.py verify\npython shared/handoff.py query --version {version} --task {task}\n```\n\n原始程式另行供應並核對 shared/targets.json 的SHA。閱讀與校驗不需要原anal目錄。Python 3.10+，標準函式庫即可；繼續原生分析才需要REA/Ghidra。\n\n證據檔為原始內容的惰性.txt副本；其舊絕對路徑只作出處。直接依賴任務帶入介面資料，不表示其所有外部需求均已解決。不可執行打包的舊腳本。\n',encoding='utf-8')
    rows=[{'path':p.relative_to(out).as_posix(),'sha256':digest(p),'bytes':p.stat().st_size} for p in sorted(out.rglob('*')) if p.is_file()]
    write(out/'manifest.json',{'schema_version':1,'files':rows,'scope':part['export_scope']})
    if not verify(out)['ok']:raise RuntimeError('Export failed integrity check')
    archive=out.with_suffix('.zip')
    if archive.exists():raise ValueError('Archive already exists')
    with zipfile.ZipFile(archive,'w',zipfile.ZIP_DEFLATED,compresslevel=9) as z:
        for p in sorted(out.rglob('*')):
            if p.is_file():z.write(p,p.relative_to(out).as_posix())
    print(json.dumps({'package':str(archive),'zip_bytes':archive.stat().st_size,'payload_bytes':sum(x['bytes'] for x in rows),'status':t['handoff_status']},ensure_ascii=False))
def main():
    ap=argparse.ArgumentParser();ap.add_argument('--root',type=pathlib.Path,default=pathlib.Path(__file__).resolve().parent.parent);sub=ap.add_subparsers(dest='cmd',required=True)
    sub.add_parser('verify')
    q=sub.add_parser('query');q.add_argument('--version',choices=['kr','tc'],required=True);q.add_argument('--task');q.add_argument('--method',help='VA hexadecimal, not RVA')
    e=sub.add_parser('export');e.add_argument('--version',choices=['kr','tc'],required=True);e.add_argument('--task',required=True);e.add_argument('--out',type=pathlib.Path,required=True)
    a=ap.parse_args();root=a.root.resolve()
    if a.cmd=='verify':raise SystemExit(0 if verify(root)['ok'] else 1)
    if a.cmd=='export':export(root,a.version,a.task,a.out.resolve());return
    c=catalog(root)
    if a.method:
        va=int(a.method,16);res={'entities':[e for e in c['entities'] if e['version']==a.version and int(e['va'],16)==va],'corrections':[x for x in c['corrections'] if x['version']==a.version]}
    elif a.task:res={k:[r for r in c[k] if r.get('version')==a.version and (r.get('id')==a.task if k=='tasks' else r.get('task',r.get('primary_task'))==a.task)] for k in ('tasks','claims','entities')};res['corrections']=[x for x in c['corrections'] if x['version']==a.version and a.task in x['tasks']]
    else:res={'tasks':[{k:t[k] for k in ('id','title','handoff_status','owner')} for t in c['tasks'] if t['version']==a.version]}
    print(json.dumps(res,ensure_ascii=False,indent=2))
if __name__=='__main__':main()
