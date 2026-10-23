"""Finalize portable paths and explicit identity evidence; does not analyze binaries."""
import hashlib,json,pathlib,sqlite3
from refine_delivery import ROOT,SRC,dump
def main():
    c=json.loads((ROOT/'shared/catalog.json').read_text(encoding='utf-8'));amap={a['id']:a for a in c['artifacts']};changes=[]
    for p in sorted(SRC.glob('kr-*/input-provenance.json')):
        d=json.loads(p.read_text(encoding='utf-8-sig'))
        if not isinstance(d,dict) or d.get('source_sha256')!=c['targets']['kr']['sha256']:continue
        matches=[r for r in d.get('inputs',[]) if r.get('sha256') in amap]
        if not matches:continue
        raw=p.read_bytes();h=hashlib.sha256(raw).hexdigest()
        if h not in amap:
            rel=f'kr/evidence/{h}.txt';(ROOT/rel).write_bytes(raw);a={'id':h,'sha256':h,'path':rel,'bytes':len(raw),'original_sources':[p.relative_to(SRC).as_posix()],'version':'kr','roles':['input-provenance'],'identity_basis':'Explicit target SHA and per-input file hash','attributions':[]};c['artifacts'].append(a);amap[h]=a
        for r in matches:
            a=amap[r['sha256']]
            if a['version']=='unclassified':
                a['version']='kr';a['identity_basis']='Exact file hash matches a KR input-provenance manifest; association only, not semantic revalidation';a['identity_evidence_ids']=[h];changes.append(a['id'])
    for a in c['artifacts']:
        if a['version'] not in ('kr','tc'):continue
        desired=f'{a["version"]}/evidence/{a["id"]}.txt'
        if a['path']!=desired:
            old=(ROOT/a['path']).resolve();new=(ROOT/desired).resolve();assert old.is_relative_to(ROOT.resolve()) and new.is_relative_to(ROOT.resolve())
            if new.exists():assert new.read_bytes()==old.read_bytes();old.unlink()
            else:old.replace(new)
            a['path']=desired
    for t in c['tasks']:
        ids=set(t['evidence_ids']);queue=list(ids)
        for aid in queue:
            for dep in amap[aid].get('identity_evidence_ids',[]):
                if dep not in ids:ids.add(dep);queue.append(dep)
        t['evidence_ids']=sorted(ids);folder=ROOT/t['version']/'tasks'/t['id'];dump(folder/'task.json',t)
        claims=[x for x in c['claims'] if x['version']==t['version'] and x['task']==t['id']]
        lines=[f'# {t["id"]} {t["title"]}','',f'狀態：{t["handoff_status"]}；負責人未認領。','','## 範圍','',t['scope'],'',t['excluded_scope'],'','## 已有成果與缺口','']
        lines+=['- **'+x['status']+'**：'+x['statement'] for x in claims]
        lines+=['','## 依賴、接續與驗收','', '依賴：'+(', '.join(t['dependencies']) or '版本共用證據')+'。先核對SHA及更正，再認領具體方法；其他主責任務只引用。','']
        lines+=['- '+s for s in t['next_steps']+t['acceptance']]
        lines+=['','## 證據','']
        lines += [f'- [{amap[aid]["original_sources"][0]}](../../../{amap[aid]["path"]})' for aid in t['evidence_ids']]
        lines+=['','舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。','']
        (folder/'README.md').write_text('\n'.join(lines),encoding='utf-8')
    dump(ROOT/'shared/catalog.json',c)
    db=ROOT/'shared/catalog.sqlite';db.unlink();con=sqlite3.connect(db)
    for table in ('artifacts','tasks','claims','entities','corrections'):
        con.execute(f'create table {table}(id text,version text,task text,record text)')
        for r in c[table]:con.execute(f'insert into {table} values(?,?,?,?)',(r['id'],r.get('version'),r.get('task',r.get('primary_task')),json.dumps(r,ensure_ascii=False)))
    con.commit();assert con.execute('pragma integrity_check').fetchone()[0]=='ok';con.close()
    dump(ROOT/'shared/manifests/source-map-v2.json',{'sources':[{'original_path':p,'artifact_id':a['id'],'sha256':a['sha256'],'portable_path':a['path'],'version':a['version'],'basis':a['identity_basis']} for a in c['artifacts'] for p in a['original_sources']]})
    dump(ROOT/'unclassified/selected-sources.json',[a for a in c['artifacts'] if a['version']=='unclassified'])
    dump(ROOT/'validation/identity-refinement.json',{'exact_input_hash_matches':changes,'remaining_unclassified':sum(a['version']=='unclassified' for a in c['artifacts'])});print(json.dumps({'artifacts':len(c['artifacts']),'exact_matches':len(changes)}))
if __name__=='__main__':main()
