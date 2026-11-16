# W3 輸入與語意獨立稽核

這份是 W3 交付給 S00 的獨立輸入稽核，不是 T01 FULL-PASS、RR ACCEPTED、S00 核准或遊玩驗收。稽核只使用上傳資料包，沒有執行舊證據腳本、Client 或 Server。

## 核對結果

- 外包 MANIFEST 130 檔 SHA256/bytes 全部符合；來源分析 commit `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。
- 五個 Table member（QuestInfo、_MapList、_CaseList、_TownList、_ActorList）的原 member SHA 與 T16 source-members 一致；local carrier 與原 carrier 不同不可抹去。
- 四個 Skill member 的原始匹配標記為 `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST`，不能當 true。
- 十個 Quest 的原 QuestInfo row byte range SHA 全部與 CSV row_sha256 一致。
- S00 的三十筆 scene/function/SEQ SHA 與 T16 quest-scenes 一致，但 raw SEQ 及原 SceneList 不在此包；這是投影交叉核對，不是假稱完整原件已重驗。
- 四個補充 Case 的原 Chart map choices、NodeLink 及全部 Cluster objects，已與 S00 baseline 比對相符。群數 Case101=31、107=19、108=47、109=43；S00 每 Case 取前四個 cluster 是 Server 候選政策。

## 十 Quest 的預期關聯

| Quest | 前置 → 後繼 | Giver=Finisher NPC | Quest town / Chapter town | Field / candidate Case | Scenes | S00 旅程 |
| --- | --- | --- | --- | --- | --- | --- |
| 117 | 15 → 118 | 10002 | 1 / 1 | — / — | 1 | 敘事 1；不在此路線建立副本 |
| 118 | 117 → 119 | 10047 | 1 / 1 | 28 / 109 | 1 | 敘事 1；不在此路線建立副本 |
| 119 | 118 → 120 | 10047 | 1 / 1 | 26 / 107 | 5 | 敘事 1；632→633→634→635；返回 Town1 |
| 120 | 119 → 121 | 10008 | 1 / 1 | — / — | 3 | 敘事 1,2,3；不在此路線建立副本 |
| 121 | 120 → 122 | 10002 | 1 / 1 | — / — | 1 | 敘事 1；不在此路線建立副本 |
| 122 | 121 → 123 | 10002 | 1 / 1 | 27 / 108 | 5 | 敘事 1；636→637→638→639；返回 Town1 |
| 123 | 122 → 124 | 10048 | 1 / 1 | — / — | 1 | 敘事 1；不在此路線建立副本 |
| 124 | 123 → 131 | 10048 | 1 / 1 | 17 / 101 | 7 | 敘事 1；184→185→186→187；返回 Town1 |
| 131 | 124 → 132 | 10002 | 1 / 2 | — / — | 1 | 敘事 1；不在此路線建立副本 |
| 132 | 131 → 133 | 10002 | 1 / 2 | 28 / 109 | 5 | 敘事 1；640→641→642→643；返回 Town2 |

精確定位：`quest-definitions.json#/definitions/9..18`，`quest-catalog.csv` 的資料列（含 header=1）11–20，`quest-scenes.csv` 6–35。每筆完整 CSV 列號、JSON pointer、原 member SHA 已在 `source-audit.json`。Q117 前置 Q15、Q132 後繼 Q133 都是有效的 scope 外端點，不得丟失或當不存在。

## 必留差異

1. **Q118** 在 `/definitions/10/source_data/field` 為 28，`/entries/2` 有 Case109 的候選資源 join；S00 明確只播 scene1。保存這個候選 join，但 `scenario_entry_ref != null` 不能導出需要入場。
2. **Q131/Q132** 的 Quest town 是 1，chapter=2 的 chapter_town 是 2。這是不同欄位，不是矛盾；不要自動更正 Quest town。
3. **Q120** 三個 scene 為敘事排程，scene2 載入 `bluetree12C.fld`；**Q123** scene1 載入 `bluetree01C.fld`。LoadMap 是 presentation 模型名，兩者都不能據此推為副本。
4. `bluetree12C` 原 _MapList 對應 53/937/1734/1950/2166/3459；`bluetree01C` 對應 36/636/3449。模型名不唯一，不能全域字典覆寫成單一 MapID。
5. **Q132 scene2 在 Map642（第三個 node）**；scene3/4 對應 643，scene5 回到 Town2/Map183。Case107/108/109 NodeLink 4→3→2→1；Case101 1→2→3→4，必須保留來源 node ID 與有向順序。
6. 所有場景 key 為 `(quest, scene_index)`；scene_index=1 在十任務重複不是 duplicate scene。NPC10047、10048 同名仍是不同 ID。NPC↔scene 的 rows 是 indirect quest membership，不證明 scene actor/trigger。
7. **T16 與 S00 候選排程分層**：q119 T16 flow 先編隊／instance，再由 events 任意分派 scene cue，cleanup 回 events；S00 新旅程把 scene1 放在入場前。不能融合成已核准唯一流程。十任務只有 Q117/Q119 有 T16 flow，其餘八筆 flow_ref=null，不能套 q119 自動補。
8. 十任務 objectives 均 BLOCKED，`kind/target_ref/required_count/counter_scope/event_contract/filters` 仍 null。所有正式 acceptance／completion／turn-in／reward plan 未綁；accept、scene receipt、Instance result、返回村、敘事milestone、正式 settlement 互不等同。
9. 五個沒有 raw RewardsEtc 的任務（118/120/121/123/131）rewards=[]，但 reward_policy_status=BLOCKED；不能當零獎勵。Q117 type2=710；Q119=2:5850/3:40/4:900；Q122=2:9686/3:40/4:918；Q124=2:13086/3:40/4:1440；Q132=2:15850/3:40/4:1440。type2/type4 既有 Client 顯示名可保留，type3 顯示與全部 Server grant 仍未知。
10. id-values.csv 只有部分域資料：quest20/scene35/npc8/town8/case7/map3/item1/portal_effect10/monster29，沒有 field/chapter rows。不能只用它當唯一 ID registry，須合併 canonical typed 欄位與現有原表。

## 已補件與尚未取得

- Case101/107/108/109 的 Chart/Cluster 八個 raw members 都在 `local-resources/Field/`，具 pin SHA；T16 舊 entries 的 map_graph=null 與 DRAFT_BLOCKED 要原樣保留，在額外補件層呈現可用性。Q118 與 Q132 同引用 Case109，也不表示兩者都入場。
- T16 舊 content-manifest 55 項裡，`requirements.txt`、`validate_content.py` 不在上傳包。只列歷史非必要檔缺件；新標準庫 converter 不應依賴或執行它們。
- 原 `Table/SceneList.xml`、`Event/SceneList.xml`、`Table/npctable.xml`、`Table/QuestTalk.xml` 及全部 30 個選定 SEQ raw 缺件；來源投影可用，需明記無法獨立重 hash 原件。精確 member/SHA 在 JSON。
- S00 baseline 18 個 BND 只提供名稱及 SHA、解析摘要，原 BND bytes 不在此包；不要稱本工具重新證明可走幾何。原 `.mef` sample/parser 缺口屬已明確延後的工作，這輪不得重啟搜尋。

## 歷史來源版本不能混用

source-index 有 133 個固定來源。按引用原路徑定位，7 個可重 hash 匹配、2 個同 path 為不同版本、124 個未附引用路徑。另以全包內容 hash 核對，其中 3 個在不同路徑有相同 bytes：`evidence/work-package.md` 與 Case103 的 Chart／Cluster；因此 converter 另列 3 筆 `CONTENT_SHA_MATCH_VIA_OTHER_PACKAGE_PATH`，剩 121 筆無法取得精確內容。這 3 筆只證內容一致，不證歷史 Git 路徑／commit 收錄。原稽核 7／2／124 與 converter 的 7／3／2／121 是不同定位口徑，不是衝突。未取得不等同於關聯資料缺失，仍可保留帶原 SHA 的歷史投影；精確來源與相同內容路徑見 JSON 的 `supplementary_content_alias_matches`。

| Pointer | 引用 | 舊 SHA256 | 本包同名檔 SHA256 |
| --- | --- | --- | --- |
| /sources/62 | https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-MEF-IMPLEMENTATION-AND-MIGRATION-PLAN.md | 953a552181f769b2a71cc7fa8d6c6eca4f7da3f4495d0895c60631aa3a0a55ff | 9ff57bca984e115788f2f8836fe992c1980cac52857538063f3494a9eb98c604 |
| /sources/73 | https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/AGENTS.md | 35e3ce38b80f3608c0d9d79317d5c7793864141959f05055fb8c6ced59d0a3c1 | 10f982d87ce9899fc704460f34358e228199c4df1963f7561db6d789bb8dae30 |

`evidence/native-windows.json` 是 T16 相對路徑，實測與來源 `/sources/55` 的 `ca7f62b9...` 相同；這只重驗證據檔 SHA，不等同重新驗 BIN。Git blob SHA1、完整內容 SHA256、member SHA、row SHA 的欄位意義必須分開。

## Server 可接用與需求分流

- 可接用：十 Quest typed data、Demand/unlock鏈、NPC/Chapter/scene membership、原 reward metadata、四組有向 Map/Case resource graph、S00 明示候選旅程排程、保留全部未知的內容庫與逐欄來源對照。
- **Server 待開發**：T16 正式 Quest 模型的 progress owner/scope；eligibility（包含 level，比較方向不可由數值猜）、接取／交付政策；逐 Quest objective predicate、event/count/scope；既有 S00 候選編隊、admission、遭遇、portal、結果／返回服務與合法完成／結算契約的綁定；grant 交易／發布；場景生命周期和候選 milestone → 正式進度的整合。S00 continuation 已記錄旅程候選實作與合成驗證，此清單不是目前 Server 全面實作盤點。不得把原 Server 演算法未知當停止理由。
- **Client 待逆向**：尚未綁定的接取／交付具體 UI mode 收發、scene receipt 成功／失敗辨識及 cleanup/控制器介面。已有 bounded wire 資訊照來源保留，不寫成全部未知。
- **跨功能待整合**：資料 catalog 接到通用 handlers、world／NPC／scene／Scenario adapters；保留 T16 blocked flow 與 S00 journey 各自版本，不提升正式成熟度。
- **待遊玩驗證**：正常互動、scene自然退出、返回與Map183控制；離線重跑和SHA核對不算可玩／獎勵驗收。

## 讀取範圍

完整 MANIFEST 各檔的 bytes 都用於 hash；下列是另行進行內容／欄位／結構核對的來源。舊原稿腳本沒有執行。

- `MANIFEST.json`
- `START-HERE.md`
- `git-evidence/AGENTS.md`
- `git-evidence/governance/s00-iterations/S00-20261104-ALSMEER-STORY-CONTINUATION.md`
- `git-evidence/governance/s00-iterations/evidence/S00-20261104-ALSMEER-RESOURCE-BASELINE.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/candidate-chain.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/content-manifest.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/csv-contracts.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/evidence/quest-facts.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/evidence/resource-findings.md`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/evidence/scenario-resource-facts.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/evidence/scene-facts.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/evidence/source-members.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/evidence/typed-domain-facts.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/exceptions.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/id-dictionary.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/id-relations.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/id-values.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/migration-matrix.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-catalog.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-definitions.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-flows.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-nodes.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-npc-scenes.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-objectives.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-rewards.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-runtime-design.md`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-scenario-entries.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-scenes.csv`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/scenario-entries.json`
- `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/source-index.json`
- `git-evidence/research/handoffs/s00-web-server-definitions-20261104/README.md`
- `git-evidence/shared/CLIENT-MODIFICATION-POLICY.md`
- `local-resources/Field/Cluster/CLUST_S_pathofAlsmeer_01.xml`
- `local-resources/Field/Cluster/CLUST_scenario_chicken_01.xml`
- `local-resources/Field/Cluster/CLUST_scenario_razed_01.xml`
- `local-resources/Field/Cluster/CLUST_scenario_ygg_01.xml`
- `local-resources/Field/MapFlow/CHART_S_pathofAlsmeer_01.xml`
- `local-resources/Field/MapFlow/CHART_scenario_chicken_01.xml`
- `local-resources/Field/MapFlow/CHART_scenario_razed_01.xml`
- `local-resources/Field/MapFlow/CHART_scenario_ygg_01.xml`
- `local-resources/Table/QuestInfo.xml`
- `local-resources/Table/_CaseList.xml`
- `local-resources/Table/_MapList.xml`
