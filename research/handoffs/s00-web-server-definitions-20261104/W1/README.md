# W1｜KR 副本事件與怪群資料定義（DRAFT_BLOCKED）

**範圍**：Case **101 / 103 / 107 / 108 / 109**；只讀 Client 資源與引用的既有 S00/T16 證據，**不是官方 `.mef`**、不是可直接啟用的 Server 配置，也沒有修改 Client／Server／RR／CLM／SPEC／ADR。Git 交付僅包含 JSON/schema/CSV/Markdown，不包含本機遊戲原材料或 ZIP。

## 交付

- `scenario-definitions.json`：5個 ScenarioDefinition、全部 MapFlow Node/有向 NodeLink/Map percent、所有 ClusterSet/SpawnGroup/object `ID/PRE/COUNT`、每節點 cue 候選、Portal/Condition/Action 空缺與現行有限 cluster 選用對照。
- `scenario-definition.schema.json`：JSON Schema draft 2020-12；有 `ScenarioDefinition`、`SpawnGroup`、`Condition`、`Action`、`PortalDefinition`、`TypedId`、`SourceRef`。
- `source-map.csv`：逐個 Case/Node/Edge/Map/ClusterSet/Group/**每個 OBJECT occurrence**、preload、Quest join、既有選擇和 scene cue 的來源/欄位/member SHA。
- `unknowns.md`：可交 S00 的精確 Server 待補項，含 Client 待證/Source/整合/遊玩範圍。
- `README.md`：本文件。

## 盤點及方向（NodeList 順序 ≠ NodeLink 流向）

| Case | Field/STAGE | 候選 Quest | 有向 NodeLink traversal | 對應 Map ID | ClusterSet/group數 | OBJECT rows | S00有限選用 |
| --- | --- | --- | --- | --- | ---: | ---: | --- |
| 101 | 17 | 124 | 1→2→3→4 | 184,185,186,187 | 31 | 31 | 4/4 node |
| 103 | 19 | 15 | 1→2 | 191,192 | 3 | 6 | 0/2 node |
| 107 | 26 | 119 | 4→3→2→1 | 632,633,634,635 | 19 | 26 | 4/4 node |
| 108 | 27 | 122 | 4→3→2→1 | 636,637,638,639 | 47 | 72 | 4/4 node |
| 109 | 28 | 118,132 | 4→3→2→1 | 640,641,642,643 | 43 | 51 | 4/4 node |

總計 **18 nodes / 143 cluster groups / 186 OBJECT rows**，並保留各 group 內的重複同ID與 PRE 差異，未把 `COUNT` 加總稱總關卡怪量。各 `Map/@percent` 保留 literal（本次均100），edge沒有原始概率時 `branch_probability_raw=null`，不能猜官方 RNG 或移動 gate。原始 MapChart 的 editor `x/y/arrayx/arrayy` 保留以便稽核，**不能拿來當 world spawn、出口座標**。

## 來源與真實度界線

- 使用者上傳ZIP內 `START-HERE.md`、`MANIFEST.json`、10個 Field Chart/Cluster XML、`Table/_CaseList.xml`、`_MapList.xml`、`QuestInfo.xml`，另讀 `git-evidence/AGENTS.md`、`shared/CLIENT-MODIFICATION-POLICY.md`、S00 `RESOURCE-BASELINE.json`、`S00-20261104-ALSMEER-STORY-CONTINUATION.md`、`S00-20261103-MEF-IMPLEMENTATION-AND-MIGRATION-PLAN.md`、T16 `scenario-entries.json`、`quest-scenario-entries.csv`、`quest-scenes.csv`、`evidence/scenario-resource-facts.json`、T16 `README.md`、W1派工README；沒有執行舊證據腳本。
- 資料包 `MANIFEST.json` SHA256 **4b6f14740df2ccfe1447ad84acac45ceb4752d67c4108d5c3f49335d0c9b96f3**，`source_analysis_commit=fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。現有 S00來源是快照/候選，不代表當前 Server revision 真正在某個位置啟用了生怪。包中 Git evidence member 可經 `source-map.csv` 追路徑/檔案/commit；**member SHA256 不是 Git blob SHA1**。
- Table local carrier SHA256 `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c` 與既有原件carrier不同。逐member `Table/_CaseList.xml`/`_MapList.xml`/`QuestInfo.xml` 的 manifest `original_member_sha_match=true`，已核算包內SHA，**不**把 local carrier 整包稱原版；Field carrier SHA256 `18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a` 對應pin，10 Field member均核對實際SHA與S00 baseline；原始 member 比對欄 **not declared**，不冒稱已完成 T01 raw carrier 原件比對。
- `CLIENT_RESOURCE_DIRECT` 只稱包內已核原始 XML member literal；`EXISTING_ANALYSIS_CITED` 是 Git 快照的轉述；`SERVER_CANDIDATE` 是 S00既有選群/依 `LoadMap` exact string 產生的 cue 候選；`USER_POLICY` 是 Z／大型出口／入口安全距離；`UNKNOWN` 是未核實。**Source NodeLink 不等於官方遊戲轉圖規則；per-node scene join 不等於官方播放或結算時機。**

## 有界遷移建議（只規劃，不改 Server）

1. 現行 S00 `resource-baseline.scenarios[].nodes[].selectedCluster` 僅覆蓋 Case101/107/108/109 的**有向 traversal 前四個 node 對應 group1～4**；可搬到 `nodes[].spawn_group_selected` 但必須保留 `classification=SERVER_CANDIDATE`。Case103有3個原始 group 與2個 node，**沒有可核來源的固定 group→node 選擇**，目前保持 `null`，不自行用前兩組冒充目前運行狀態。
2. 將每個 `MapFlow Node` 轉為 Scenario instance node，`cluster_sets[].groups[]` 建**完整 catalogue**（包括全部未使用group），與 node selected group 分開；下次採用某個 group 必須有明示選擇/隨機分支/數量策略，不能用預設第一組偷跳過原表。
3. Portal 使用 `portal-key` namespace；NodeLink 的目的地只列為 `candidate_destinations`。世界座標、半徑、scale、解鎖 `Condition` 都維持 `null`；手動Z、通道底端大出口與入口淨空只在 `USER_POLICY`。每一 node 的MEF TRIGGER字串並不是已解析的腳本／事件成功條件。
4. 以 `quest/field/case/map/scene/portal-key` **分域 join**。例如 `Quest15 → Field19 → Case103 → Map191/192`，而非 `Quest15=Field19=Case103=Map191`；`Q118/Q132` 都是 Field28，但現有主線 Q132 才有4圖旅程選群候選，Q118 不能由 Field28 自動入場。場景 cue 僅作候選視覺事件，不提交任務完成。
5. Server ScenarioRuntime 接口最少需讀取完整定義、獨立 instance progress、確認/清怪condition、portal交互、場景回包、冪等結果與 Quest settlement adapter；待 S00 逐項批准後才能解除 activation gate。**本次沒有直接改 runtime、沒有新增所有怪 AI 的假設。**

## 離線驗證及禁止事項

來源輸入逐member重新算 SHA256/bytes；`MapFlow NodeLink` 所有 node ID 存在，全部 edge 無懸空；`MapList` 每個 Map ID 唯一且可 join；Quest `@field` 必須和 Case `@STAGE` 一致；選定 group 必須出現在 source ClusterSet 且 Map一致；JSON schema/18 nodes/143 groups/每一 `OBJECT` row 數量等統計另做離線驗證。禁止把上述純靜態核對當 `T01 FULL-PASS`、正式 `SPEC STABLE` 或遊玩成功。
