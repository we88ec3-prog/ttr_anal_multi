"""Organize existing evidence only. Never imports/runs a target or legacy script."""
import argparse, ast, collections, gzip, hashlib, json, pathlib, re, sqlite3
from inventory import TARGETS,sha
from task_spec import TASKS,EXTRA,TC_SOURCES,COMMON,DEFERRED
from curated_facts import add_claims
BASE=pathlib.Path(__file__).resolve().parent.parent
SOURCE=BASE.parent/'anal'
def dump(path,obj):
    path.parent.mkdir(parents=True,exist_ok=True);path.write_text(json.dumps(obj,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
def text(path,s):
    path.parent.mkdir(parents=True,exist_ok=True);path.write_text(s,encoding='utf-8')
def read(p): return p.read_text(encoding='utf-8-sig',errors='replace')
class Inventory(dict):
    def __contains__(self,key):return dict.__contains__(self,key) or (SOURCE/key).is_file()
    def __missing__(self,key):
        p=SOURCE/key
        if not p.is_file():raise KeyError(key)
        st=p.stat();raw=p.read_bytes();h=hashlib.sha256(raw).hexdigest();seen=[v for v,d in TARGETS.items() if d.encode() in raw.lower()]
        r={'path':key,'bytes':len(raw),'sha256':h,'mtime_ns':st.st_mtime_ns,'identity_hash_mentions':seen,'classification':'reference-'+seen[0] if len(seen)==1 else 'mixed-references' if seen else 'unclassified','classification_authority':'selected-source read-only inventory','default_action':'exclude-unless-selected','exclusion_reason':'Not selected'}
        self[key]=r;return r
def loadinv():
    d=Inventory()
    complete=BASE/'shared/manifests/source-inventory.complete.jsonl.gz'
    stream=gzip.open(complete,'rt',encoding='utf-8') if complete.exists() else (BASE/'shared/manifests/source-inventory.jsonl').open(encoding='utf-8')
    with stream as f:
        for line in f:
            try:r=json.loads(line);d[r['path']]=r
            except json.JSONDecodeError:
                if line.endswith('\n'):raise
    return d
def resolve(ref,parent):
    ref=ref.replace('\\','/').split('#')[0]
    if ref.startswith('anal/'):ref=ref[5:]
    opts=[parent/ref,SOURCE/ref,SOURCE/'native-index'/ref]
    for p in opts:
        try:
            q=p.resolve();rel=q.relative_to(SOURCE.resolve()).as_posix()
            if q.is_file():return rel
        except (ValueError,OSError):pass
def discover():
    inv=loadinv(); chosen={}; pending=[]; omissions=[]
    def add(rel,task,role,via):
        if rel not in inv:
            omissions.append({'source':rel,'task':task,'reason':'missing-source'});return
        r=inv[rel]
        if r['bytes']>8*1024*1024 or pathlib.Path(rel).suffix.lower() in ('.exe','.bin','.dll','.db','.sqlite3','.stp') or 'login-captures/' in rel:
            omissions.append({'source':rel,'task':task,'reason':'large-or-nonhandoff-artifact; retained in original','sha256':r['sha256']});return
        if rel not in chosen:
            chosen[rel]={'tasks':[],'roles':[],'via':[]};pending.append(rel)
        c=chosen[rel]
        if task not in c['tasks']:c['tasks'].append(task)
        if role not in c['roles']:c['roles'].append(role)
        if via not in c['via']:c['via'].append(via)
    for row in TASKS:
        tid,title,scope,deps,docs,impl,gap,seeds=row
        for p in docs.split():add(p,tid,'historical-report','curated-task-selection')
        for p in impl.split():add(p,tid,'AI-substitute-audit-source','curated-task-selection')
        for p in EXTRA.get(tid,[]):add(p,tid,'native-evidence','curated-task-selection')
    for p in COMMON:add(p,'COMMON','common-context','curated-common-selection')
    for p in DEFERRED:add(p,'DEFERRED','deferred-report','curated-deferred-selection')
    for p in TC_SOURCES:add(p,'TC-COMMON','tc-history','curated-tc-selection')
    # Only follow explicit evidence/script links; never recursively crawl unrelated reports.
    for rel in pending:
        p=SOURCE/rel
        if p.suffix.lower() not in ('.md','.py','.json'):continue
        s=read(p);refs=set(re.findall(r'[A-Za-z0-9_./\\-]+\.(?:json|txt|py)',s))
        if p.suffix=='.py':
            try:
                tree=ast.parse(s)
                for node in ast.walk(tree):
                    if isinstance(node,ast.Call) and isinstance(node.func,ast.Name) and node.func.id in ('dump','audit','bounded'):
                        for arg in node.args:
                            if isinstance(arg,ast.Constant) and isinstance(arg.value,str) and re.fullmatch(r'[\w-]+',arg.value):refs.add(arg.value+'.txt')
            except SyntaxError:pass
        # Do not chase entire global catalog/provenance inventories or archived protector reports.
        if 'COMMON' in chosen[rel]['tasks'] or 'TC-COMMON' in chosen[rel]['tasks'] or 'DEFERRED' in chosen[rel]['tasks']:continue
        if p.name in ('identity.json','input-provenance.json'):continue
        for ref in refs:
            if any(k in ref.lower() for k in ('snapshot','bundle','capture','accounts.','inventory-state','workbench','build_native_index','server','query_')):continue
            found=resolve(ref,p.parent)
            if found:
                for task in list(chosen[rel]['tasks']):add(found,task,'supporting-evidence',rel)
    # Dependency assignments can propagate after a shared source was first processed.
    for _ in range(5):
        changed=False
        for rel,c in chosen.items():
            for parent in c['via']:
                if parent in chosen:
                    for t in chosen[parent]['tasks']:
                        if t not in c['tasks']:c['tasks'].append(t);changed=True
        if not changed:break
    # Resolve retained REA IDs without opening/rebuilding a native project.
    ev_index={}
    for rel,r in inv.items():
        if '/mcp-evidence/' not in rel or not rel.endswith('.json'):continue
        with (SOURCE/rel).open('rb') as f:head=f.read(32768).decode('utf-8',errors='replace')
        ids=re.findall(r'ev_[0-9a-f]{64}',head)
        if ids:ev_index.setdefault(ids[0],rel)
    for rel in list(chosen):
        if pathlib.Path(rel).suffix not in ('.json','.md') or pathlib.Path(rel).name in ('identity.json','catalog.json'):continue
        if any(t in chosen[rel]['tasks'] for t in ('COMMON','TC-COMMON','DEFERRED')):continue
        for eid in set(re.findall(r'ev_[0-9a-f]{64}',read(SOURCE/rel))):
            if eid in ev_index:
                for task in list(chosen[rel]['tasks']):add(ev_index[eid],task,'retained-REA-evidence',rel)
            else:
                omissions.append({'source':rel,'evidence_id':eid,'tasks':chosen[rel]['tasks'],'reason':'retained-REA-record-not-found; summary-only'})
    entries=[]
    for rel,c in sorted(chosen.items()):
        r=inv[rel];mentions=r['identity_hash_mentions'];version='unclassified';basis='No exact target binding established; source retained for review'
        if 'AI-substitute-audit-source' in c['roles']:
            version='kr';basis='Curated association with KR local test implementation; NOT original-binary evidence'
        elif mentions==['kr']:version='kr';basis='Contains exact KR hash; assertion scope still bounded by record'
        elif mentions==['tc']:version='tc';basis='Contains exact TC hash; assertion scope still bounded by record'
        elif len(mentions)>1:version='cross-version';basis='Multiple target hashes; no address equivalence inferred'
        else:
            s=read(SOURCE/rel) if r['bytes']<2*1024*1024 and pathlib.Path(rel).suffix in ('.md','.json','.py','.txt') else ''
            if re.search(r'(原[始版]*韓版|original KR|原版韓版|original Korean)',s,re.I):
                version='kr';basis='Explicit historical original-KR attribution; exact hash requires linked audit'
        entries.append({**r,**c,'version':version,'identity_basis':basis,'action':'include'})
    plan={'source_root_historical':str(SOURCE),'entries':entries,'omissions':omissions,'estimated_unique_payload_bytes':sum({x['sha256']:x['bytes'] for x in entries}.values()),'scope':'curated gameplay handoffs; no new native analysis; original inventory retained','execution_order':['inventory','selection-plan','build','verify','export T08 T09','isolated verification']}
    dump(BASE/'shared/manifests/selection-plan.json',plan);print(json.dumps({'selected':len(entries),'estimated_MiB':plan['estimated_unique_payload_bytes']/2**20,'omissions':len(omissions)}))
    return plan
def build():
    plan=json.loads(read(BASE/'shared/manifests/selection-plan.json')); inv=loadinv();artifacts={};bytask=collections.defaultdict(list);byoriginal={}
    for r in plan['entries']:
        p=SOURCE/r['path'];assert sha(p)==r['sha256'],r['path']
        ver=r['version']; folder=ver if ver in ('kr','tc') else 'cross-version' if ver=='cross-version' else 'unclassified'
        aid=r['sha256'];dest=f'{folder}/evidence/{aid}.txt';data=p.read_bytes()
        # JSON/Python/Markdown retained byte-for-byte as inert .txt; no legacy scripts auto-run.
        if aid not in artifacts:
            q=BASE/dest;q.parent.mkdir(parents=True,exist_ok=True);q.write_bytes(data)
            artifacts[aid]={'id':aid,'path':dest,'sha256':aid,'bytes':len(data),'original_sources':[],'attributions':[],'version':ver,'roles':[],'identity_basis':r['identity_basis']}
        a=artifacts[aid];a['original_sources'].append(r['path']);a['attributions'].append({'source':r['path'],'version':ver,'identity_basis':r['identity_basis'],'roles':r['roles']});a['roles']=sorted(set(a['roles']+r['roles']));byoriginal[r['path']]=aid
        for t in r['tasks']:
            if aid not in bytask[t]:bytask[t].append(aid)
    targets={}
    for v,p in [('kr',BASE.parent/'Tartaros.bin'),('tc',BASE.parent.parent/'tc_workspace/Tartaros.bin')]:
        h=sha(p);assert h==TARGETS[v];targets[v]={'module':'Tartaros.bin','sha256':h,'bytes':p.stat().st_size,'included':False,'image_base':4194304 if v=='kr' else None,'original_path_historical':str(p)}
    dump(BASE/'shared/targets.json',targets)
    tasks=[];claims=[];entities=[];ownership={};methods={}
    c=sqlite3.connect((SOURCE/'native-index/method-atlas/methods.sqlite').resolve().as_uri()+'?mode=ro&immutable=1',uri=True);c.row_factory=sqlite3.Row
    assert c.execute('select sha256 from modules where module=?',('Tartaros.bin',)).fetchone()[0]==TARGETS['kr']
    for row in TASKS:
        tid,title,scope,deps,docs,impl,gap,seeds=row
        for ver in ('kr','tc'):
            evid=list(dict.fromkeys(bytask[tid]+bytask['COMMON'])) if ver=='kr' else list(bytask['TC-COMMON'])
            task={'id':tid,'version':ver,'title':title,'scope':scope,'excluded_scope':'不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用','owner':None,'state':'unclaimed','dependencies':deps.split(),'evidence_ids':evid,'handoff_status':'review-ready-partial' if ver=='kr' else 'not-independent-native-handoff','native_complete':False,'unknowns':[gap] if ver=='kr' else ['台版缺乏對應遊玩功能的原生證據；不得套用韓版位址或結論。保護殼分析維持停止。'],'next_steps':['先查來源與更正，再選一個具體阻塞；認領主要函式後開工。','僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。'] if ver=='kr' else ['僅整理既有資料；本輪不繼續解殼。'],'acceptance':['列明每項原生/部分/AI替代/缺失/待開發狀態與證據','交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收'],'limits':['交接可閱讀並核對現有證據，不代表功能已可玩或原生語意完整。','歷史報告外部引用僅是來源線索；未打包的證據不可當作已核對。']}
            tasks.append(task)
            claims.append({'id':f'{ver}-{tid}-gap','version':ver,'task':tid,'status':'資訊缺失','statement':task['unknowns'][0],'evidence_ids':evid,'authority':'organizer-gap-assessment','scope':scope})
            claims.append({'id':f'{ver}-{tid}-development','version':ver,'task':tid,'status':'待補充開發','statement':'取得原生依據後才能列出實作規格；目前不授權自行補值。'+task['unknowns'][0],'evidence_ids':[],'authority':'work-planning-not-native-fact','scope':scope})
            if ver=='kr':
                claims.append({'id':f'kr-{tid}-prior','version':'kr','task':tid,'status':'部分確認','statement':'既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。','evidence_ids':[byoriginal[p] for p in docs.split() if p in byoriginal],'authority':'historical-evidence-not-new-proof','scope':scope})
                for src in impl.split():
                    if src in byoriginal:
                        claims.append({'id':f'kr-{tid}-impl-{src}','version':'kr','task':tid,'status':'AI 替代','statement':'此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。','evidence_ids':[byoriginal[src]],'authority':'implementation-source','scope':src})
        for hx in seeds.split():
            va=int(hx,16);key=TARGETS['kr']+':Tartaros.bin:'+hex(va-0x400000)
            if key in ownership:continue
            ownership[key]=tid
            m=c.execute('select * from methods where module=? and address=?',('Tartaros.bin',va)).fetchone()
            slots=[dict(x) for x in c.execute('select * from virtual_slots where module=? and target=?',('Tartaros.bin',va))]
            entity={'id':key,'version':'kr','module':'Tartaros.bin','source_sha256':TARGETS['kr'],'va':hex(va),'rva':hex(va-0x400000),'primary_task':tid,'person_owner':None,'kind':'method-candidate','boundary_status':'legacy-index-observation; apply corrections','atlas_row':dict(m) if m else None,'virtual_slots':slots,'atlas_source_sha256':inv['native-index/method-atlas/methods.sqlite']['sha256'],'limits':'min/max envelope is not verified continuous body; shared fragments not split'}
            entities.append(entity)
    c.close()
    add_claims(claims,byoriginal,SOURCE,artifacts)
    # Mandatory corrections stay explicit and never get overwritten by latest-date precedence.
    correction_specs=[
      ('C01',['T04','T05'],'31-collision-grid-spawn-and-trace-crash.md','舊 blocked-spawn 判定已撤回，必須與30號報告並讀。'),
      ('C02',['T07','T14'],'SCENE-ENTRY-RESET-AND-READY.md','本機patch改4B99C0；原版type6建立CDuelField，修補流程不能當原版驗證。'),
      ('C03',['T12'],'kr-battle-frame-binding-20261023/binding-records.json','4B18D4依case使用不同source/target及result0/1/2，不能固定為0。'),
      ('C04',['T01','T03','T07'],'06-runtime-login-fix.md','歷史runtime使用修改過的Tartaros.local.exe；其成功不能證明原始SHA流程可玩。'),
      ('C05',['T12'],'CHECKPOINT-WIRE-AND-ACTION-NOTIFICATIONS.md','000E結果消費與000F CANNOT_USE_SKILL通知需分開；fixture把000F命名hit不能當原生命中格式。'),
      ('C06',['T09'],'kr-frame-dispatch-20261023/corrections.json','491CB6 caller/gates有新增紀錄，但此階段未封存驗收，保持待複核。'),
      ('C07',['T01','T13'],'kr-boundaries-20261022/boundary-records.json','4BC150為CALL位移內部，不是有效入口；真正建構入口4BC170。')]
    corrections=[]
    for cid,tids,src,s in correction_specs:
        rec={'id':cid,'version':'kr','tasks':tids,'statement':s,'evidence_ids':[byoriginal[src]] if src in byoriginal else [],'status':'historical-correction' if cid!='C06' else 'pending-stage-validation'};corrections.append(rec)
        for t in tasks:
            if t['version']=='kr' and t['id'] in tids:t['evidence_ids']=list(dict.fromkeys(t['evidence_ids']+rec['evidence_ids']))
    catalog={'schema_version':1,'targets':targets,'artifacts':list(artifacts.values()),'tasks':tasks,'claims':claims,'entities':entities,'corrections':corrections,'common_evidence':{'kr':bytask['COMMON'],'tc':bytask['TC-COMMON']},'deferred_evidence':bytask['DEFERRED'],'limits':['No full native index rebuild; selected original atlas rows imported only.','No new native semantics confirmed.','Whole file identity does not validate every historical conclusion.','Unknown legacy references remain archival dependencies, not silently satisfied.']}
    reference_status=[]
    for original,aid in byoriginal.items():
        if pathlib.Path(original).suffix not in ('.md','.json','.py'):continue
        raw=read(SOURCE/original)
        for ref in sorted(set(re.findall(r'[A-Za-z0-9_./\\-]+\.(?:json|txt|py|md|sqlite)',raw))):
            found=resolve(ref,(SOURCE/original).parent)
            if found:
                reference_status.append({'from_artifact':aid,'reference':ref,'source_path':found,'target_artifact':byoriginal.get(found),'source_sha256':inv[found]['sha256'] if found in inv else None,'status':'packaged' if found in byoriginal else 'archival-only-not-portable-evidence'})
            else:
                reference_status.append({'from_artifact':aid,'reference':ref,'target_artifact':None,'status':'unresolved-literal-or-external-reference'})
    rea_ids={}
    for a in artifacts.values():
        if 'retained-REA-evidence' in a['roles'] or any('/mcp-evidence/' in p for p in a['original_sources']):
            ids=re.findall(r'ev_[0-9a-f]{64}',read(BASE/a['path'])[:32768])
            if ids:rea_ids[ids[0]]=a['id']
    for original,aid in byoriginal.items():
        if pathlib.Path(original).suffix not in ('.json','.md'):continue
        for eid in sorted(set(re.findall(r'ev_[0-9a-f]{64}',read(SOURCE/original)))):
            reference_status.append({'from_artifact':aid,'reference':eid,'target_artifact':rea_ids.get(eid),'status':'packaged' if eid in rea_ids else 'retained-REA-record-not-packaged'})
    catalog['reference_status']=reference_status
    catalog['ownership_policy']='Listed entities are initial ownership seeds only. Other functions/data mentioned in artifacts remain unclaimed; register before analysis. Interface tasks may read but not independently redefine another primary task item.'
    for t in tasks:
        active=set(t['evidence_ids']);missing=[r for r in reference_status if r['from_artifact'] in active and r['status']!='packaged']
        t['read_only_review_ready']=True
        t['independent_analysis_ready']=False
        t['handoff_limit']='可獨立閱讀/校驗打包證據；尚非完整分析環境。歷史外部依賴及遊玩缺口仍需後續核對。' if t['version']=='kr' else '僅背景/缺口交接；尚無對應台版原生功能證據。'
        t['archival_reference_count']=len(missing)
        t['unresolved_dependencies']=missing
    dump(BASE/'shared/catalog.json',catalog)
    db=BASE/'shared/catalog.sqlite'
    if db.exists():db.unlink()
    conn=sqlite3.connect(db)
    for table in ('artifacts','tasks','claims','entities','corrections'):
        conn.execute(f'create table {table}(id text, version text, task text, record text)')
        for r in catalog[table]:conn.execute(f'insert into {table} values(?,?,?,?)',(r['id'],r.get('version'),r.get('task',r.get('primary_task')),json.dumps(r,ensure_ascii=False)))
    conn.commit();assert conn.execute('pragma integrity_check').fetchone()[0]=='ok';conn.close()
    for ver in ('kr','tc'):
        for sub in ('common','evidence','tasks','deferred'):(BASE/ver/sub).mkdir(parents=True,exist_ok=True)
        text(BASE/ver/'README.md',f'# {ver.upper()} 分工入口\n\n目標 SHA256：`{TARGETS[ver]}`。\n\n'+('原生證據與AI替代分列；歷史可玩狀態不代表目前原版可玩。' if ver=='kr' else '僅整理，保護殼分析停止。15項均未具備獨立原生功能交接證據。')+'\n\n'+'\n'.join(f'- [{t[0]} {t[1]}](tasks/{t[0]}/README.md)' for t in TASKS)+'\n')
        dump(BASE/ver/'common/dependencies.json',{'evidence_ids':catalog['common_evidence'][ver],'lookup':'../../shared/catalog.json','rule':'共用檔只保存一次，任務匯出會帶上必要依賴。'})
        text(BASE/ver/'common/README.md','# 共用規則\n\n依 dependencies.json 的ID查 shared/catalog.json。方法認領以SHA、模組、RVA唯一；同offset不同物件不得合併。報告中的絕對路徑是歷史來源，不是執行依賴。\n')
        text(BASE/ver/'deferred/README.md','# 暫緩項目\n\n音效、圖形、CRT及全檔區域帳務保留導覽，不繼續解析。來源ID見 shared/catalog.json 的 deferred_evidence；台版保護殼保持停止。\n')
    for t in tasks:
        d=BASE/t['version']/'tasks'/t['id'];dump(d/'task.json',t)
        links=[]
        for aid in t['evidence_ids']:
            a=artifacts[aid];links.append(f'- [{a["original_sources"][0]}](../../../{a["path"]}) — {a["identity_basis"]}')
        text(d/'README.md',f'# {t["id"]} {t["title"]}\n\n狀態：{t["handoff_status"]}；負責人：未認領。\n\n## 目標與邊界\n\n{t["scope"]}\n\n排除：{t["excluded_scope"]}\n\n## 已有成果與未知\n\n詳 task.json 及查詢工具的 claims/corrections。\n\n'+ '\n'.join('- '+s for s in t['unknowns'])+'\n\n## 共用依賴\n\n'+(', '.join(t['dependencies']) or '版本共用來源與更正')+'。依賴任務只帶介面及直接證據，不遞迴擴展整張圖。\n\n## 下一步與驗收\n\n'+'\n'.join('- '+s for s in t['next_steps']+t['acceptance'])+'\n\n## 必要來源\n\n'+'\n'.join(links)+'\n')
    unclassified=[r for r in plan['entries'] if r['version']=='unclassified']
    dump(BASE/'unclassified/selected-sources.json',unclassified)
    text(BASE/'unclassified/README.md','# 待分類\n\nselected-sources.json 列出已帶入但尚未精確綁定版本的來源。全目錄待分類項目見 shared/manifests/source-inventory.jsonl；hash出現在內容只代表引用，不是整檔所有結論的版本證明。\n')
    cross=[a for a in artifacts.values() if a['version']=='cross-version']
    dump(BASE/'cross-version/relations.json',{'verified_code_address_equivalences':[],'historical_resource_comparison':'TC-MEF-RESOURCE-COMPARISON.md 與 tc-mef-evidence.json記錄三個map ID名稱對比；不推出整表或程式等價。','source_ids':[byoriginal[x] for x in TC_SOURCES if x in byoriginal],'limits':['本輪未重核資源archive原檔；程式SHA與資源SHA分開。','沒有將KR程式位址套用TC。']})
    text(BASE/'cross-version/README.md','# 跨版本\n\n目前沒有已驗證的程式位址等價關係。既有資源比較僅為歷史限定觀察，見 relations.json。\n')
    dump(BASE/'shared/manifests/source-map.json',{'original_to_artifact':byoriginal,'scope':'Selected sources only. Full exclusions can be computed by subtracting from source-inventory.jsonl.','omissions':plan['omissions']})
    print(json.dumps({'artifacts':len(artifacts),'tasks':len(tasks),'claims':len(claims),'entities':len(entities),'unclassified_selected':len(unclassified)}))
if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('mode',choices=['plan','build']);a=ap.parse_args();discover() if a.mode=='plan' else build()
