# 新作者分析輸入

本目錄是 2026-11-18 新編寫的 **Server MEF 作者候選**。不是從原件還原的官方關卡，也不是正式 Server／Client 已驗收內容。檔案仍沿既有 `LOCAL_SCENARIO_DEFINITION_V1_NOT_NATIVE_MEF` schema，`weighted-entry.plan.json` 則另標明為新 adapter 的設計輸入。[檔案清單與 hash](manifest.json)

| 檔案 | 定義／用途 |
|---|---|
| [missing-coverage.scenario.json](missing-coverage.scenario.json) | 4 定義：RegionEntered、BossDefeated、空初始順序波、空初始具名頭目波 |
| [bounded-repeat.scenario.json](bounded-repeat.scenario.json) | 1 定義／3 節點：同一模板固定三次拜訪，每輪獨立旗標，最後才 Result |
| [cross-node-guarantees.scenario.json](cross-node-guarantees.scenario.json) | 1 定義／2 節點：第一節點必要 Boss／Wave 的保證旗標供第二節點增援使用 |
| [weighted-entry.plan.json](weighted-entry.plan.json) | 新入口選擇提案：固定目錄 hash、2:1 權重、每場建立前只選一次 |

Map193、spawn `(377.5,315.5)`、portal `(377.5,307.5,r4,key801)`、Model1001、AI profile 及基本三規則骨架來自既有 `design/scenario-content/functional-lab.scenario.json` 的 `content-lab-wave-clear`。Model1009 來自既有 `region-wave-example.scenario.json`。新增區域 `(377.5,295.5,r2)`、增援位置與時間是作者選擇；全部位置重新對照原 Table／BoundMap 解出的 keep04.bnd。

初始空場不配置 `WaveCleared` 的 null 初始波觀察者。BossDefeated 例的 Model1001／PRE1 在整節點只出現一次；具名頭目例則明確指向 `boss-entry`。這符合固定 Server typed 驗證器的身分規則，但本包未實際呼叫該驗證器。[精確身分及清場說明](../report.md)

三輪例把每次 visit 編成不同 node／encounterGroup，全部本輪旗標改名；波名僅在各節點內使用。這可能重建房間，不是不中斷的同房三波。各例擊倒經驗與清場經驗明確為 0，沒有掉落或 completionExperience；最終 Result 交所選既有 adapter 處理，沒有自行新增最終獎勵。[逐欄展開對照](../repeat-mapping.json)

schema／條件依賴／BND 靜態檢查通過，仍須選定內容版本與正式入口。功能測試場有明列的 mode→definition 目錄；主線 override 固定原節點數、圖和初始模型順序，不能把這些泛用候選直接視為所有主線都會接受。[整合界線](../execution-contract.json)
