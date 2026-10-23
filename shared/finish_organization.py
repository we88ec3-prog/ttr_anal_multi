"""Final report and compact inventory; requires completed scan and release tests."""
import collections,datetime,gzip,hashlib,json,pathlib,shutil
from refine_delivery import ROOT,SRC,dump
def sha(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda:f.read(1048576),b''):h.update(b)
    return h.hexdigest()
def main():
    inv=json.loads((ROOT/'shared/manifests/inventory-summary.json').read_text(encoding='utf-8'));assert inv['complete']
    tests=json.loads((ROOT/'validation/release-tests.json').read_text(encoding='utf-8'));assert all(r['verification']['ok'] and r['corruption_detected'] for r in tests)
    c=json.loads((ROOT/'shared/catalog.json').read_text(encoding='utf-8'));included={p:a for a in c['artifacts'] for p in a['original_sources']};changed=[]
    for p,a in included.items():
        if sha(SRC/p)!=a['sha256']:changed.append(p)
    assert not changed,changed
    counts=collections.Counter();sizes=collections.Counter();n=0;total=0;unknown=0
    with gzip.open(ROOT/'shared/manifests/source-inventory.complete.jsonl.gz','rt',encoding='utf-8') as src,gzip.open(ROOT/'shared/manifests/dispositions.jsonl.gz','wt',encoding='utf-8') as out:
        for line in src:
            r=json.loads(line);n+=1;total+=r['bytes'];unknown+=r['classification']=='unclassified'
            if r['path'] in included:action='included';reason='Selected task evidence';artifact=included[r['path']]['id']
            else:action='excluded';reason='Not needed for bounded task review; retained in original anal, no deletion';artifact=None
            counts[action]+=1;sizes[action]+=r['bytes'];out.write(json.dumps({'source_path':r['path'],'sha256':r['sha256'],'bytes':r['bytes'],'action':action,'reason':reason,'artifact_id':artifact,'identity_hash_mentions':r['identity_hash_mentions']},ensure_ascii=False)+'\n')
    assert n==inv['source_files'] and total==inv['source_bytes']
    # Delete only redundant generated working copies after archive tests passed.
    for name in ('kr-T08','kr-T09','kr-T08-v2','kr-T09-v2','kr-T08-release','kr-T09-release'):
        p=ROOT/'exports'/name
        if p.exists():assert p.resolve().is_relative_to((ROOT/'exports').resolve());shutil.rmtree(p)
    # Preserve checkpoints compactly; complete manifest supersedes their raw journals.
    for name in ('source-inventory.jsonl','inventory-resume-journal.jsonl','checkpoint-files.json'):
        p=ROOT/'shared/manifests'/name
        if p.exists():
            dest=ROOT/'history'/(name+'.gz')
            with p.open('rb') as src,gzip.open(dest,'wb') as out:shutil.copyfileobj(src,out)
            p.unlink()
    statuses=[{k:t[k] for k in ('version','id','title','handoff_status','read_only_review_ready','independent_analysis_ready','archival_reference_count')} for t in c['tasks']]
    report={'date':datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=8))).isoformat(),'organization_status':'completed bounded organization with explicit evidence gaps','inventory':inv,'dispositions':dict(counts),'source_bytes_by_disposition':dict(sizes),'unclassified_inventory_records':unknown,'selected_unclassified_artifacts':sum(a['version']=='unclassified' for a in c['artifacts']),'artifacts':len(c['artifacts']),'claims':len(c['claims']),'entities':len(c['entities']),'owned_method_seeds':sum(e.get('primary_task') is not None for e in c['entities']),'unassigned_methods':sum(e.get('primary_task') is None for e in c['entities']),'original_sources_rehashed':len(included),'changed_original_sources':changed,'original_anal_writes_performed':False,'native_semantics_revalidated':False,'exports':tests,'tasks':statuses,'remaining_limitations':['Historical references are not all packaged; task boundaries and omissions are explicit.','Unclassified sources need evidence before assigning version; no prefix-based assignment.','Native target files and REA/Ghidra environment are supplied separately.','TC tasks are background-only; no restored unpacking work.','Frame-dispatch retained evidence is still pending its original stage closeout; not promoted.','Ownership records cover retained selected methods only; unlisted methods must be claimed before parallel work.']}
    dump(ROOT/'REPORT.json',report);dump(ROOT/'shared/task-readiness.json',statuses)
    rows=['# 分工整理完成報告','','本輪完成既有成果的有界整理與試交接驗證；未完成原生功能還原，也未進行遊玩測試。','',f'- 原始盤點：{n:,}檔，{total/2**30:.3f} GiB。',f'- 選入來源：{counts["included"]}檔；去重後{len(c["artifacts"])}份內容。',f'- 排除：{counts["excluded"]:,}檔；逐檔SHA與原因見shared/manifests/dispositions.jsonl.gz。',f'- 仍待版本歸屬：選入內容{report["selected_unclassified_artifacts"]}份。這些是明列未知，不強行歸類。',f'- 方法項目：{len(c["entities"])}，其中{report["unassigned_methods"]}項待分派；不代表有效函式分母。',f'- 重新核對{len(included)}個選入原始來源SHA，無變更。原anal未修改。','','## 交接驗證','','T08/T09均完成獨立解壓、禁止原anal/原執行檔讀取、任務查詢及竄改偵測。完整歷史引用仍有缺口，沒有把校驗通過當成語意完成。','', '|版本|任務|狀態|', '|---|---|---|']
    rows += [f'|{t["version"]}|{t["id"]} {t["title"]}|{t["handoff_status"]}|' for t in statuses]
    rows += ['','## 工具與重現','','讀取/匯出：Python 3.10+標準庫，shared/handoff.py。原生證據保留原工具/版本/位址與限制；本輪不開新原生分析。','', '下一次來源有變動時：先備份本版，再執行resume_inventory.py增量核對；不可重建全部原生atlas。舊build_handoffs是初版建立程式，後續refine/add/finalize的修改已保存，不要只重跑初版覆蓋現況。','', '詳盡校驗與容量見REPORT.json；原始CHECKPOINT保存在history/checkpoint-v1.json.gz。']
    (ROOT/'REPORT.md').write_text('\n'.join(rows)+'\n',encoding='utf-8')
    (ROOT/'CHECKPOINT.json').write_text(json.dumps({'status':'organization-v2-complete-with-documented-gaps','current_report':'REPORT.json','previous_checkpoint':'history/checkpoint-v1.json.gz','running_processes':[],'next':'Assign a task from shared/task-readiness.json; do not restart historical broad analysis.'},ensure_ascii=False,indent=2),encoding='utf-8')
    (ROOT/'README.md').write_text(f'''# Tartaros 可遊玩流程分工資料

2026-10-24：既有成果整理版完成。原生功能仍有缺口；本輪沒有執行遊戲或新增原生逆向分析。

## 入口

- [KR：15項任務](kr/README.md)
- [TC：15項背景／缺口任務](tc/README.md)
- [接續導覽](HANDOFF.md)、[AI工作規則](AGENTS.md)
- [完成報告](REPORT.md)、[詳細統計](REPORT.json)
- [使用與重現步驟](REPRODUCE.md)
- [T08 實體生成與移除](exports/kr-T08-release.zip)
- [T09 關卡內移動與同步](exports/kr-T09-release.zip)

ZIP位於本機exports，預設不提交Git；從Git下載者可用下方命令自行匯出。

## 本版內容

完整盤點原始anal的{n:,}檔、{total/2**30:.3f} GiB。選入來源{counts['included']}檔，按SHA去重後{len(c['artifacts'])}份；所有未選檔案的SHA、位置與排除原因亦已保存。原anal未修改。

KR／TC各15項任務，{len(c['claims'])}筆狀態紀錄、{len(c['entities'])}個方法項目。方法數不是有效函式總數；未分派項目先認領再分析。選入內容仍有{report['selected_unclassified_artifacts']}份版本歸屬不充分，保留unclassified。

## 使用

Python 3.10+，僅標準函式庫。在本目錄執行：

```powershell
python shared/handoff.py verify
python shared/handoff.py query --version kr --task T08
python shared/handoff.py export --version kr --task T08 --out exports/kr-T08-new
```

對AI可說：「先讀README、AGENTS與kr/tasks/T08，接續KR T08；核對來源SHA與AI替代標記，先認領範圍，不執行遊戲。」

原始Tartaros.bin不隨包提供；新分析需另外取得shared/targets.json指定SHA的原檔，以及REA/Ghidra。閱讀與校驗不需要原anal。證據.txt保留原始內容，包含歷史腳本，不能直接執行。

## 驗證與限制

T08/T09已完成獨立解壓、禁止原anal與目標執行檔讀取、任務查詢、文件連結檢查及竄改偵測。詳validation/release-tests.json。

這證明有限成果包可攜，不代表全部歷史證據閉合、原生規則已完整還原或遊戲可玩。每項task.json保留缺口；台版不套用韓版結論，保護殼保持停止。最新frame-dispatch保留原階段未驗收限制。

完整壓縮清單：shared/manifests/source-inventory.complete.jsonl.gz；納入／排除：dispositions.jsonl.gz；選入映射：source-map-v2.json。舊檢查點保存在history，Git預設排除它與可重新生成的ZIP。
''',encoding='utf-8')
    (ROOT/'HANDOFF.md').write_text('''# 接續導覽

2026-10-24：整理版已完成，沒有執行中的盤點或遊戲程序需要接管。先讀REPORT及shared/task-readiness.json，不要恢復已完成的全量掃描或重建原生atlas。

下一步由使用者選定任務（例如KR T08），依AGENTS.md認領範圍。任務可獨立閱讀現有資料，但新分析仍需原檔和REA/Ghidra。台版只具背景／缺口資料。

仍有未分類來源與歷史外部引用；它們已明列為缺口，不能用檔名前綴、最新日期或相同功能名稱推定來源。需要某項缺口時才補取證據，不要為閉合全部導覽擴大範圍。

重要更正：AI固定出生點／怪物能力／傷害／追逐不能當原生規則；原版005F type6不是本機修補的Tutorial；000F不可直接按fixture名稱認成命中；4B18D4依路徑而非固定result0；4BC150不是有效函式入口。Frame-dispatch仍待原階段語意驗收。

可追溯性：原CHECKPOINT與初版catalog已封存在history/checkpoint-v1.json.gz；初版試包保留，新版使用exports/*-release.zip。原anal唯讀且未變更。重現與增量更新看REPRODUCE.md，避免只重跑初版builder覆蓋後續整理。
''',encoding='utf-8')
    (ROOT/'unclassified/README.md').write_text('# 待分類來源\n\n選入但歸屬不足的來源見selected-sources.json；全量來源盤點見../shared/manifests/source-inventory.complete.jsonl.gz。檔名或內容提到某SHA都不等於整檔所有結論屬於該版本。\n',encoding='utf-8')
    print(json.dumps({'files':n,'source_GiB':total/2**30,'artifacts':len(c['artifacts']),'included':counts['included'],'excluded':counts['excluded']}))
if __name__=='__main__':main()
