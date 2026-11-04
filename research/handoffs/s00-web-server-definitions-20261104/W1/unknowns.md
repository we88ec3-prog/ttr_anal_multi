# W1 精確缺口與 Server 待辦（不是原生已證）

此表能直接提供 S00 做需求收件／去重（**不新增平行 RR、SPEC、ADR**）。`W1-*` 是文件內追蹤鍵，不是 GitHub 正式 RR 編號。所有五個 Scenario 都維持 `DRAFT_BLOCKED`。

| 追蹤鍵 | 責任類型 | 精確 Case／ID | 缺口證據 | 解除條件／Server 實作要求 |
| --- | --- | --- | --- | --- |
| W1-SRV-101-01 | Server 待開發 / Client 資料待證 | Case101，Map 184, 185, 186, 187 | `scenario_ygg01.mef`, `scenario_ygg02.mef`, `scenario_ygg03.mef`, `scenario_ygg04.mef` 僅為 `_MapList.TRIGGER` 字串；MEF 本體／事件語義及每 node 觸發條件未提供 | 初版實作維持明示候選事件，加入 `Condition` 承載實際觸發、拒絕、重送與合法性；原生 MEF 解析排程暫緩 |
| W1-SRV-101-02 | Server 待開發 / 待遊玩驗證 | Case101，Map 184, 185, 186, 187 | Bound keys `scenario_ygg01`, `scenario_ygg02`, `scenario_ygg03`, `scenario_ygg04`；具體出生點、入口安全距離、出口 bottom-corridor 位置/大型特效/碰撞半徑皆無法由 MapFlow editor x/y 推出 | 副本實作逐圖挑合法 world point 並驗證入口安全/手動 Z/large visual effect；W1 所有 world_position=null |
| W1-SRV-101-03 | Server 待開發 / 資料待補 | Case101，Cluster `Field/Cluster/CLUST_scenario_ygg_01.xml` | 31 groups，`PRE` 具體用途、採用策略與官方先後波次／清怪與出口解鎖／Boss victory 未驗；S00只採前幾組 | 顯式 group selection 策略與 event outcome 狀態機，保留候選 mapping，禁止由 COUNT 推導總關卡怪數 |
| W1-SRV-103-01 | Server 待開發 / Client 資料待證 | Case103，Map 191, 192 | `S_pathofpindus01.mef`, `S_pathofpindus02.mef` 僅為 `_MapList.TRIGGER` 字串；MEF 本體／事件語義及每 node 觸發條件未提供 | 初版實作維持明示候選事件，加入 `Condition` 承載實際觸發、拒絕、重送與合法性；原生 MEF 解析排程暫緩 |
| W1-SRV-103-02 | Server 待開發 / 待遊玩驗證 | Case103，Map 191, 192 | Bound keys `scenario_pathofpindus01`, `scenario_pathofpindus02`；具體出生點、入口安全距離、出口 bottom-corridor 位置/大型特效/碰撞半徑皆無法由 MapFlow editor x/y 推出 | 副本實作逐圖挑合法 world point 並驗證入口安全/手動 Z/large visual effect；W1 所有 world_position=null |
| W1-SRV-103-03 | Server 待開發 / 資料待補 | Case103，Cluster `Field/Cluster/CLUST_S_pathofpindus_01.xml` | 3 groups，`PRE` 具體用途、採用策略與官方先後波次／清怪與出口解鎖／Boss victory 未驗；S00只採前幾組 | 顯式 group selection 策略與 event outcome 狀態機，保留候選 mapping，禁止由 COUNT 推導總關卡怪數 |
| W1-SRV-107-01 | Server 待開發 / Client 資料待證 | Case107，Map 635, 634, 633, 632 | `scenario_chicken04.mef`, `scenario_chicken03.mef`, `scenario_chicken02.mef`, `scenario_chicken01.mef` 僅為 `_MapList.TRIGGER` 字串；MEF 本體／事件語義及每 node 觸發條件未提供 | 初版實作維持明示候選事件，加入 `Condition` 承載實際觸發、拒絕、重送與合法性；原生 MEF 解析排程暫緩 |
| W1-SRV-107-02 | Server 待開發 / 待遊玩驗證 | Case107，Map 635, 634, 633, 632 | Bound keys `mushroom12`, `mushroom07`, `mushroom04`, `mushroom01`；具體出生點、入口安全距離、出口 bottom-corridor 位置/大型特效/碰撞半徑皆無法由 MapFlow editor x/y 推出 | 副本實作逐圖挑合法 world point 並驗證入口安全/手動 Z/large visual effect；W1 所有 world_position=null |
| W1-SRV-107-03 | Server 待開發 / 資料待補 | Case107，Cluster `Field/Cluster/CLUST_scenario_chicken_01.xml` | 19 groups，`PRE` 具體用途、採用策略與官方先後波次／清怪與出口解鎖／Boss victory 未驗；S00只採前幾組 | 顯式 group selection 策略與 event outcome 狀態機，保留候選 mapping，禁止由 COUNT 推導總關卡怪數 |
| W1-SRV-108-01 | Server 待開發 / Client 資料待證 | Case108，Map 639, 638, 637, 636 | `scenario_razed04.mef`, `scenario_razed03.mef`, `scenario_razed02.mef`, `scenario_razed01.mef` 僅為 `_MapList.TRIGGER` 字串；MEF 本體／事件語義及每 node 觸發條件未提供 | 初版實作維持明示候選事件，加入 `Condition` 承載實際觸發、拒絕、重送與合法性；原生 MEF 解析排程暫緩 |
| W1-SRV-108-02 | Server 待開發 / 待遊玩驗證 | Case108，Map 639, 638, 637, 636 | Bound keys `bluetree10`, `bluetree08`, `bluetree05`, `bluetree01`；具體出生點、入口安全距離、出口 bottom-corridor 位置/大型特效/碰撞半徑皆無法由 MapFlow editor x/y 推出 | 副本實作逐圖挑合法 world point 並驗證入口安全/手動 Z/large visual effect；W1 所有 world_position=null |
| W1-SRV-108-03 | Server 待開發 / 資料待補 | Case108，Cluster `Field/Cluster/CLUST_scenario_razed_01.xml` | 47 groups，`PRE` 具體用途、採用策略與官方先後波次／清怪與出口解鎖／Boss victory 未驗；S00只採前幾組 | 顯式 group selection 策略與 event outcome 狀態機，保留候選 mapping，禁止由 COUNT 推導總關卡怪數 |
| W1-SRV-109-01 | Server 待開發 / Client 資料待證 | Case109，Map 643, 642, 641, 640 | `S_pathofAlsmeer_04.mef`, `S_pathofAlsmeer_03.mef`, `S_pathofAlsmeer_02.mef`, `S_pathofAlsmeer_01.mef` 僅為 `_MapList.TRIGGER` 字串；MEF 本體／事件語義及每 node 觸發條件未提供 | 初版實作維持明示候選事件，加入 `Condition` 承載實際觸發、拒絕、重送與合法性；原生 MEF 解析排程暫緩 |
| W1-SRV-109-02 | Server 待開發 / 待遊玩驗證 | Case109，Map 643, 642, 641, 640 | Bound keys `keep02`, `barley03`, `barley01`, `mushroom02`；具體出生點、入口安全距離、出口 bottom-corridor 位置/大型特效/碰撞半徑皆無法由 MapFlow editor x/y 推出 | 副本實作逐圖挑合法 world point 並驗證入口安全/手動 Z/large visual effect；W1 所有 world_position=null |
| W1-SRV-109-03 | Server 待開發 / 資料待補 | Case109，Cluster `Field/Cluster/CLUST_S_pathofAlsmeer_01.xml` | 43 groups，`PRE` 具體用途、採用策略與官方先後波次／清怪與出口解鎖／Boss victory 未驗；S00只採前幾組 | 顯式 group selection 策略與 event outcome 狀態機，保留候選 mapping，禁止由 COUNT 推導總關卡怪數 |
| W1-SRV-109-04 | Server 待開發 / 跨任務待整合 | Quest118、Quest132 → Field28 → Case109 | Q118 雖有 field28 但只有村內單 scene；共享 Field 不等於 Q118 自動進副本 | S00 指定各 Quest admission/scene route（目前主線 Q132），分開記錄與正式 Quest grant |
| W1-SRV-ALL-05 | Server 待開發 | 5 Cases、18 Map nodes | `NodeLink` 不是勝利觸發；Group 與 node 無官方關聯；`Map percent=100` 僅保留 raw，不證明官方 RNG；`Node.type`/`icon`/`rotate` 語意未查 | Server 原子化 transition/portal activation/outcome gate、失敗回滾，遷移時需逐node核對 |
| W1-SRV-ALL-06 | Server 待開發 / 跨任務待整合 | Quest15、119、122、124、132 | Quest reward/objective/settlement/wire/native scene dispatch 尚未閉合；劇情播完或通過副本不等於 Quest 完成 | S00/T16 提供正式完成判定、存檔、獎勵與 UI 回包，W1只保存 cue 候選 |
| W1-CLIENT-ALL-07 | Client 待逆向（另案） | 5 Cases 的 18 個 TRIGGER 名稱 | 缺原生 MEF bytes、事件腳本與 loader/bind；W1 不是 MEF 檔 | 等Server至少 60% 且使用者重新授權排程，勿在本輪追 MEF |
| W1-SRC-ALL-08 | 來源限制 | 10 個 Field Chart/Cluster | Manifest 有 Field carrier pin，未提供 `original_member_sha_match`；不能把 pin 當 T01 原 carrier 再驗證 | T01 逐member核對實際 Field 原 carrier / stored MD5；Table 3 member 有 original SHA true |
| W1-SRC-ALL-09 | 來源缺件（包外） | BoundMap、Event/Sequences 與原生 MEF | W1 包未含完整 BoundMap BND body、18 個 native MEF body、Event sequences 本體；僅現存 S00/T16 引用資料 | 補精確 BOUND key、TRIGGER 檔名、source member SHA，不向使用者現場索取影片／截圖 |
| W1-PLAY-ALL-10 | 待遊玩驗證 | 5 Case 18 nodes | 大型出口視覺尺寸、入口距離、Z 交互、各圖真正合法路線和場景提示播放時序未真人驗證 | 副本逐圖驗收，合成測試與 DRAFT 資源整理不算實機 PASS |

## 缺件與來源範圍

- 原始已在包內：`Table/_CaseList.xml`、`Table/_MapList.xml`、`Table/QuestInfo.xml`；**Case101/103/107/108/109 的 5 Chart + 5 Cluster 均在包內**，沒有本輪 Chart/Cluster 缺件。來源SHA與每個 object occurrence 於 `source-map.csv`。
- 尚未提供：`Field` 真正 native MEF bytes/loader、可證物件生成與條件實作、完整 `BoundMap` member bytes、`Event/Sequences` body、原版 Server 達標/波次邏輯。18個候選原始 MEF 名稱與 bound keys 已列上表；包內 `TRIGGER` 字串**不是 MEF 內容**。
- 本輪唯讀執行：XML 逐筆轉換及 schema/來源完整性檢核。**未執行舊分析腳本、未啟動遊戲、未碰 Server runtime/DB、未查影片、未重新搜尋 MEF**。

## 待辦分層

- **可供 Server 立即準備**：採用具來源標籤的 `ScenarioDefinition/SpawnGroup/PortalDefinition/Condition/Action` 讀取模型、增加 instance 狀態儲存與後續 callback 的接口；但目前未授權正式啟用。
- **由 Server 開發決定**：逐圖 group 選取與事件觸發／勝利規則、原子化 transition、Portal 的位置/作用域/互動判定、獎勵提交與冪等、持久化與玩家身份契約；不得把候選說成原服內部規則。
- **Client 待證**：實際封包 wire、scene cue 真正來源/時序、MEF runtime（延後）。
- **跨功能整合／實機驗收**：T16 Quest settlement、T07 MapScene、T08 Actor、T09/T14 結果、實機腳步、碰撞與 Z 互動。
