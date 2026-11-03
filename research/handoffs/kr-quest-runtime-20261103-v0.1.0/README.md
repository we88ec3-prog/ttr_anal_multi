# KR 任務 Runtime：S00 第一批接口與內容資料包

**0.1.0 · 2026-11-03 · Server 候選，非原生 MEF。**

先讀 [quest-runtime-design.md](quest-runtime-design.md)。本包配合 T16，引用 T06/T07/T09、W1/W2/W3 與固定版本 Server 候選；沒有接管 owner 或認領已公開 RR。原 Client、資源、來源 checkout、Server／玩家 DB 均未改動；沒有 commit／push、發包、執行遊戲或異常測試。

## 第一批可供 S00 設計的接口

| 內容 | 檔案 | 狀態 |
| --- | --- | --- |
| 狀態機、服務、事件、保存與解除門檻 | [quest-runtime-design.md](quest-runtime-design.md) | Server 候選設計 |
| 任務／flow／Scenario schema | [quest-definition.schema.json](quest-definition.schema.json)、[quest-flow.schema.json](quest-flow.schema.json)、[scenario-entry.schema.json](scenario-entry.schema.json) | Draft 2020-12，version 0.1.0，沒有 default |
| Quest15 完整資料形狀 | [definition](examples/quest15.definition.json)、[32-node flow](examples/q15.candidate.flow.json)、[Scenario](examples/quest15.scenario.json) | 原表與現有橋接映射；合法完成／獎勵／部分UI binding BLOCKED |
| Quest117 單scene樣本 | [definition](examples/quest117.definition.json)、[13-node flow](examples/q117.candidate.flow.json) | 結構已由原表確認；不可把觀影當完成 |
| Quest119 多scene樣本 | [definition](examples/quest119.definition.json)、[26-node flow](examples/q119.candidate.flow.json)、[Scenario](examples/quest119.scenario.json) | 事件分派形狀；缺Case107圖、排程與合法結算規則 |
| 現行教學特殊路線 | [17-node flow](examples/tutorial.current-candidate.flow.json)、[Quest14](examples/quest14.definition.json)、[Quest16](examples/quest16.definition.json) | 保留CTutorial／角色取得／首戰／退出hook |
| 不能抹平的差異 | [exceptions.csv](exceptions.csv)、[migration-matrix.csv](migration-matrix.csv) | 9例外、16實際分支映射 |

所有內容保持 `DRAFT_BLOCKED`。第一批的「完整」指欄位、來源與未知都已明列，**不表示可以啟用、合法結算或整村通關**。

## 九類交付索引

| 使用者要求 | 對應檔案 |
| --- | --- |
| 1. typed ID、原表關聯與SHA | `id-dictionary.csv`、`id-values.csv`、`id-relations.csv`、`source-index.json` |
| 2. 任務條件、目標、數量／作用域、分支、reward | `quest-definition.schema.json`、`quest-definitions.json`、`quest-catalog.csv`、`quest-objectives.csv`、`quest-rewards.csv` |
| 3. 通用狀態機與權威／持久化 | `quest-runtime-design.md` §§4–6、9 |
| 4. primitive、UI／scene生命週期與節點 | `quest-flow.schema.json`、`quest-flows.json`、`quest-nodes.csv`、`wire-adapter-contract.md` |
| 5. 單人Scenario介面 | `scenario-entry.schema.json`、`scenario-entries.json`、`quest-scenario-entries.csv`、`scenario-service-contract.md` |
| 6. 結算、保存、回復、獎勵與debug | `quest-runtime-design.md` §9、`quest-rewards.csv`、`acceptance-cards.md` |
| 7. domain→wire adapters | `quest-wire-map.csv`、`quest-wire-evidence.json`、`wire-adapter-contract.md` |
| 8. 批量機讀內容與檢核 | 各CSV/JSON、`csv-contracts.json`、`validate_content.py`、`validation-report.json` |
| 9. 採用、例外、遷移與正流程驗收 | `migration-matrix.csv`、`exceptions.csv`、`acceptance-cards.md`、`evidence/migration-source-provenance.json` |

另有 `quest-scenes.csv`、`quest-npc-scenes.csv`，分開chapter/scene membership與NPC giver/finisher的間接關聯；後者不宣稱NPC就是scene actor或觸發來源。

## 覆蓋與限制

原表投影有20個選定Quest、35個scene key，候選鏈按每一筆Demand核對為：

`15 → 117 → 118 → 119 → 120 → 121 → 122 → 123 → 124 → 131 → 132 → 133`

這仍是靜態候選鏈，不是完整已驗收章節。Q131/Q132已列Chapter2而Quest town仍為1；Q133的Quest town才為2。Q117無field且一scene，Q119有Field26且五scene；Q118則有Field28卻只有一個村莊scene，證明不能用「有field」決定一律入場。

來源採三個獨立快照：分析main `83959c0e7e65ab01348b285f03c285f487077610`、補充分析 `76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac`、Server候選 `f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e`。原KR BIN SHA256為 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。完整hash及來源範圍在 `source-index.json`。

Case103／Case102的保存Chart/Cluster原bytes已重讀；Field.stp carrier本輪未取得，不能宣稱完整原包重解。Quest119缺 `Field/MapFlow/CHART_scenario_chicken_01.xml` 與 `Field/Cluster/CLUST_scenario_chicken_01.xml`，保留null／BLOCKED。

歷史正常教學到廣場、v12到馮德斯的觀察與保存紀錄已核對，但版本、工作副本、三項缺陷及未付獎狀態保留。未直接讀取現在的玩家DB。到村資格不是Quest15結算；未見Quest15正式完成鍵或Quest117已完成證據。全部16張新驗收卡都是 `NOT_RUN`。

## 靜態檢核

Python依賴版本見 [requirements.txt](requirements.txt)。在解壓後的資料夾執行：

```bash
python validate_content.py --strict-missing
```

此程式不連線、不啟動Client／Server、不讀玩家DB；以本地schema registry檢查內容。exit0表示格式／引用／圖／來源索引通過，且沒有被誤啟用的內容；不表示activation已解除。

本批最後檢核結果：**structural PASS／activation BLOCKED**，0 errors、0 deferred、0 unsafe enabled。範圍為3schemas、44schema instances、20原表對照、4flows／88nodes、8Scenario entries／2可讀原圖、12獨立examples、41adapter references、13CSV／704rows、133來源索引。最終逐項結果以 [validation-report.json](validation-report.json) 為準。

程式檢查重複ID、外鍵、不可達node、未宣告迴圈、event分派、expected-node條件、typed domain、同Quest結算支配、來源SHA，以及跨definition/flow/Scenario的啟用阻擋。空reward array仍需明示reward plan；未知不補預設。這是靜態產物驗證，沒有做重送／斷線／故障等延期行為測試。

## 編輯與採用規則

先編輯canonical definition/flow/Scenario，再同步CSV投影。CSV中的巢狀object/array用JSON字串；空欄不是0、false或無獎勵。`source_sha`是64hex SHA256；Git blob SHA1獨立保存，不能互換。不要移除 `blocking_issues` 來假裝已補齊規則。

先在既有程式外抽facade與typed interfaces，逐個小分支採用；正常流程、保存與Client觀察對齊後，再停用對應專用分支。教學和Q15既有通路仍保留其生命週期／候選政策。未恢復的原Server算法應交S00明示設計；Client收發／生命週期缺口交原Task補證。不要一次重寫整條主線。

`content-manifest.json`列包內各檔SHA256；它不替代來源manifest，也不代表遊戲驗收。
