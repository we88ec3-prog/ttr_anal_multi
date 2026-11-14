# 馮德斯一般副本 Stage 1／Case 1

[關卡定義](phindos-stage1-case1.scenario.json)與維護者目前採用的設定逐位元組相同，SHA-256 為 `baa48fb43ec35420167be093e331c74fb2cbc0590da720f0626898ff2c6f64d2`。此範例使用公開的 [Server 關卡 JSON schema](local-scenario-definition.schema.json)，標示 `NOT_NATIVE_MEF`。圖表與群組來源的檔名和雜湊保存在定義內。出生點、怪物配置、出口半徑、必掉卷軸和 100 通關經驗是 Server 的候選規則。 [Case 1 的來源與碰撞分析](../../governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md#case-1-的-server-關卡定義候選)

| 節點 | 地圖 | 怪物數 | 碰撞資源 | SHA-256 |
|---:|---:|---:|---|---|
| 10 | 1 | 2 | `mushroom01.bnd` | `2d6052c29a1045d44c14834a9f8313ae2731861d1014b890dd4d9f8091d6f5d4` |
| 7 | 4 | 4 | `mushroom04.bnd` | `bd3dbb89aaf14c59550fe3b42378b1d3c20f4d7f38d661eddbda8c894128ee00` |
| 6 | 8 | 4 | `mushroom07.bnd` | `01375baecf167f5d51dcf24e37f380256f7ef9ac0858db1ad4e5c632e20b139c` |
| 3 | 12 | 4 | `mushroom09.bnd` | `d60169e1cc26ff742b5db164f9262376755ca0925c34dadc40aa07412d5b5104` |
| 2 | 19 | 1 | `mushroom12.bnd` | `0adeeef7c1a183642a3e49a321e80c191b6dd3c8243f4e2f4ff7d16b5290c653` |

1. 正常入口在馮德斯的單人隊伍大廳。Server 確認帳號已抵達馮德斯、目前可自由行動、角色已擁有且是單人隊長，再接受既有 `0008` 開場候選。
2. 開場設置場景與 Case，進入第一張圖。每張圖獨立使用地圖 ID 與節點鍵，建立該圖怪物及關閉的出口。清場開出口後，玩家到出口按 Z 才換圖。
3. 地圖 19 的必要頭目為 `1086/PRE1`。擊倒後建立 Product 183、外觀 162，走近按 Space 後以交易入包。清場並確認最終出口後才記入通關經驗。 [掉落與拾取規格](GROUND-LOOT.md)
4. 結算確認後回村，保留隊伍時可再次開始。兩場各自提交經驗，主線不因一般副本推進。

一般副本可使用已招募的蘋果＆坦基（角色 2）。韓版 `ItemTable2.xml` 的 Item 10 是角色 2 專用槍械（class 1、grade 1、rank 1，該列未設 minlv）。Server 使用它作為角色沒有可用持久裝備時的場景武器候選，背包與教學首戰裝備表不因這個備用方案新增物品。基礎配置沿用技能分析的 Z／X／Z＋C，Practice 17／18／19 對應 Active 10／11／12。Z 動作候選為 101～105，X 為 106，Z＋C 為 110。進階、技能特性與正式傷害公式另待驗證。 [技能分析索引](../runtime-content/ALL-ROLE-SKILL-READINESS-V78.md)

Stage 1 載入時要求終點節點 2 明列 `requiredBoss`。通用關卡定義會檢查該模型與 PRE 只對應一個遭遇物件。啟用掉落後，終點至少要有一筆對應同模型及 PRE 的掉落配置。清場仍須等該圖所有怪物與增援處理完，並確認必要頭目已倒下。離線走圖另外核對頭目死亡訊息。

啟用持久裝備時，蘋果的武器槽優先使用已裝備的道具，空槽才在場景裝備與外觀訊息發布備用 Item 10。備用道具不計入持久裝備能力。韓版 `SkillActiveTable.xml` 解碼雜湊 `1ea831f270df757d760f4ff87d6bf509a64326a23614a305c8d767580f2a2139`，Active 10／12 的 form 為 1，Active 11 的 form 為 2。沿用既有 form 對應的物攻／魔攻加成與本機傷害公式。

離線可用持有的五份原版 BND 核對出生點至怪物、出口的可達性，再用 Server 戰鬥與移動處理走完五張圖。驗收應看到怪物數依序 2、4、4、4、1，只有終點掉落 Product 183，終點出口產生結算。正常登入、建隊、連刷、道具入包與 Client 顯示由 TS-37 驗收。 [批次驗收 TS-37](../testing/S00-CONTENT-BATCH-TESTS.md)

## Case 2

從地圖 1 出發時，`CHART_mushroom_02.xml` 的節點順序同為 10 → 7 → 6 → 3 → 2，地圖順序為 **1 → 4 → 7 → 11 → 19**。原始 CHART 成員 SHA-256 為 `58e826c44e8d9169a376c983b2d4521f0a89c3ac8fa627d9afb223a6cc2e69cc`。地圖 7、11 分別與 Case 1 的 8、12 共用上表同節點的 BND，仍保留不同的地圖 ID。怪物、位置、掉落與經驗沿用 Case 1 的 Server 候選配置。 [Case 2 關卡定義](phindos-stage1-case2.scenario.json)

部署端設定 `TARTAROS_LOCAL_STAGE_ONE_CASE=2`、`TARTAROS_LOCAL_STAGE_ONE_SCENARIO_PATH` 及 `TARTAROS_LOCAL_STAGE_ONE_SCENARIO_SHA256`。範例雜湊為 `7a98842f1c5a1048ac6f89bbf128bf91ae861c2c655c6d9a57a38b015719b1d8`。入場的 `0038` 安裝 Case 2，換圖用 `0012` 發地圖 ID、`0049` 發節點鍵。開始封包 `0008` 沒有 Case 欄位，Case 由 Host 設定。省略 Case 設定沿用 Case 1。

離線工具可用 `--stage-one <關卡絕對路徑> <BND目錄絕對路徑> <SHA-256> 2` 檢查路線與結算。Host 預檢加上 `-ScenarioCase 2`。Case 2 的實機換圖與連刷另待驗收。

## Case 3、4

從原始 `Field.stp` 核對 `CHART_mushroom_03.xml`、`CHART_mushroom_04.xml` 的節點連線與地圖。兩者的節點鍵仍是 10 → 7 → 6 → 3 → 2。Case 3 使用 Case 1 的地圖路線，Case 4 使用 Case 2 的地圖路線。每個 Case 保留自己的圖表身分及入場值。兩個新增範例沿用對應路線的 Server 怪物與獎勵設定。

| Case | 路線 | 關卡定義與 SHA-256 |
|---:|---|---|
| 3 | 1 → 4 → 8 → 12 → 19 | [Case 3](phindos-stage1-case3.scenario.json) `98f9a8d5445847b309ec7761541003dc264f6095b339ed47e964bb2d30c9b0b0` |
| 4 | 1 → 4 → 7 → 11 → 19 | [Case 4](phindos-stage1-case4.scenario.json) `e43b8ae38d3cd2a6c7ba7ea8073644e2de743817d3920dcf1871dae0ce5758bd` |

部署改用相應 Case、檔案與雜湊。離線工具最後一個參數與 Host 預檢的 `-ScenarioCase` 使用相同 Case。驗收核對入場 Case 值、五圖 ID、終點掉落及 100 通關經驗；指定 v2 的轉場、建隊與連刷留待實機。

## Case 1 的地圖 2 起點

`CHART_mushroom_01.xml` 的 `NodeLink` 記載節點 11 → 8 → 1 → 4 → 2，對應地圖 **2 → 5 → 9 → 13 → 19**。下表碰撞成員由 `_MapList.xml` 的 `BOUND` 對應至 `Map/BoundMap.stp`，封裝 SHA-256 為 `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8`。怪物群取自既有 CLUST 群組。群組分配、座標及獎勵為 Server 候選規則。

| 節點／地圖 | 群組／怪物數 | 碰撞檔 | SHA-256 |
|---|---|---|---|
| 11／2 | 2／3 | `mushroom02.bnd` | `b5d6af0e491dae6a02496fad8f6e9716972756eee0827449b72921f00ea99925` |
| 8／5 | 4／4 | `mushroom05.bnd` | `2c1f23c83659a9da64bb832f08b177bb73ef2fd29cb03ae287bfc50ac8f47611` |
| 1／9 | 11／3 | `mushroom08.bnd` | `a0be87d1b07d7ba65863d1251fc5435f6255f3f87be1bb8d64031b28d655df13` |
| 4／13 | 16／1 | `mushroom10.bnd` | `674fec0033f6e743db05679385f248cc06cce663da8e167942af15233193d822` |
| 2／19 | 19／1 | `mushroom12.bnd` | 見上表 |

維持 Host 的 Case 1，將 `TARTAROS_LOCAL_STAGE_ONE_SCENARIO_PATH` 指向[地圖 2 起點定義](phindos-stage1-case1-map2.scenario.json)，並設定 `TARTAROS_LOCAL_STAGE_ONE_SCENARIO_SHA256=3ce4b9115c68fb12767a5d63154511b0380e662f669a1776942d2771a3336e65`。起點隨載入的定義決定，預設的 Case 1 檔案仍使用地圖 1。

離線走圖工具使用五份原版 BND，逐圖執行移動、戰鬥和出口互動，確認生成 3、4、3、1、1 隻、終點選取 Product 183 並產生 100 經驗的待結算狀態。正常建隊、Client 轉場、入包及經驗入帳仍按實機批次驗收。

### 地圖 9 的雙出口

`NodeLink` 在節點 1 同時連向節點 4（地圖 13）及節點 5（地圖 17），兩者都接到頭目節點 2。地圖 17 的 `BOUND` 為 `mushroom11`，對應碰撞檔 SHA-256 `c9b1d48580d8c02580d1a4ed66c1cea4053e76225426b4ed20fa80a4669cebd5`。Server 候選設定在該圖使用 CLUST 群組 17 的單隻 `1015/PRE1`。分支出口座標與鍵值屬 Server 配置。

啟用時以[雙出口關卡定義](phindos-stage1-case1-map2-branches.scenario.json)替換 Host 的設定路徑，並指定 SHA-256 `52243d19a1cb5409b6c55bc3237fc69891a932392ecf585d4da9b34bb9aee94e`。清完地圖 9 後，入口側的出口鍵 5 通往地圖 17，較遠的出口鍵 1 通往地圖 13。各路都通往地圖 19。離線走圖工具沿用 `--stage-one <關卡絕對路徑> <BND目錄絕對路徑> <SHA-256> 1` 驗地圖 13，末尾加 `5` 驗地圖 17。兩條路已各自走完五圖，抵達頭目掉落及待結算。實機需另確認兩個出口都顯示且能選擇。

## Case 1 的地圖 3 起點

`CHART_mushroom_01.xml` 另有節點 12 → 9 → 1，對應地圖 **3 → 6 → 9**。從地圖 9 沿相同的節點 4 或 5 前往頭目。下列兩份碰撞成員來自同一個原版 `Map/BoundMap.stp`；群組分配及座標屬 Server 候選規則。

| 節點／地圖 | 群組／怪物數 | 碰撞檔 | SHA-256 |
|---|---|---|---|
| 12／3 | 2／3 | `mushroom03.bnd` | `314548da51f6fb958a2ce63a31ce1267f18c47e863b7edb0a2550d6905341f94` |
| 9／6 | 5／4 | `mushroom06.bnd` | `d90baa75c2ff356dcabb8884a83d1d80e2868a70f0fe2368ea69f2ea422157b1` |

維持 Case 1，改用[地圖 3 雙出口定義](phindos-stage1-case1-map3-branches.scenario.json)和 SHA-256 `a07d76a01c269ece56e8765b49d782b67561e31034f8a47ad065d63f0e08fd66`。沿用上述走圖命令，使用新檔案與雜湊。離線已確認地圖 9 同時發布出口鍵 1 與 5，兩路皆可擊倒頭目、選取 Product 183 並產生 100 EXP 待結算。正常建隊入口、Client 顯示、實際入包及經驗入帳仍需實機。

## Case 2～4 的雙出口配置

核對 `CHART_mushroom_02.xml` 至 `CHART_mushroom_04.xml`，地圖 2／3 皆先走對應的地圖 5／6，再由節點 1 分岔至節點 4 或 5，最後抵達地圖 19。各 Case 的節點 ID 相同，分岔處和分支的地圖 ID 依圖表而異。節點 1、4、5 分別沿用上列的 `mushroom08.bnd`、`mushroom10.bnd`、`mushroom11.bnd`。每份定義列出對應圖表的 SHA-256。座標、怪物群組分配及獎勵沿用 Case 1 的 Server 候選配置。

| Case | 分岔圖 → 出口鍵 1／5 | 地圖 2 起點 | 地圖 3 起點 |
|---|---|---|---|
| 2 | 10 → 14／16 | [配置](phindos-stage1-case2-map2-branches.scenario.json) | [配置](phindos-stage1-case2-map3-branches.scenario.json) |
| 3 | 10 → 13／18 | [配置](phindos-stage1-case3-map2-branches.scenario.json) | [配置](phindos-stage1-case3-map3-branches.scenario.json) |
| 4 | 9 → 15／16 | [配置](phindos-stage1-case4-map2-branches.scenario.json) | [配置](phindos-stage1-case4-map3-branches.scenario.json) |

設定 Host 的 Case、檔案路徑及該檔 SHA-256。兩個出口由玩家在分岔圖內選擇。起點由 Host 選用的設定決定。離線逐一走完四個 Case 的 20 條圖表路線，分岔圖均發布兩個可用出口，每條均擊倒頭目、選取 Product 183 並產生 100 EXP 待結算。

## 逐圖清場經驗

Stage 1 的 Server 關卡定義可在節點加上非負整數 `clearExperience`，省略時為 0。當本圖的怪物、增援與必要頭目全部達到清場條件，Server 對本場累計一次。最終出口把已走路線的累計值加到通關經驗，整筆沿用既有副本結算入帳。離開未通關場次時，暫存的清場經驗隨場次結束。預覽場維持零獎勵。

這是 Server 獎勵規則，公開範例仍沿用 100 通關經驗。每條可達通關路線的獎勵總額須在 32 位元有號整數範圍內。離線分支測試在共用圖配置 5 EXP，兩條分支各配置 15、25 EXP，分別得到 120、130 EXP 待結算。一般副本的既有結果封包顯示實際入帳總額，本機測試頁另顯示累計清場經驗。

關卡載入時會檢查清場旗標控制的屏障。把本圖清場或清場後延遲才開啟的屏障保持關閉，其餘屏障視為可開，從出生點沿可走格檢查初始怪物及增援出生點。若仍有怪物位於不可到達區域，Host 會指出地圖並拒絕載入。有其他可走路徑時可以使用同一屏障配置。這項檢查針對清場與開門互相等待，實際互動時機與遊戲畫面仍由實機驗收。

## 怪物繞行

一般副本的追擊若被牆擋住，Server 可用本機地圖的可通行格尋路。有巡邏路點或無巡邏路點的怪物都可繞行。若怪物設定追擊半徑，搜尋仍受該範圍限制。每次更新至多規劃一條路線，同一怪物至少間隔半秒才重算，屏障開關後可立即重算。找到路線後，Server 逐步更新位置，出手及命中仍檢查通路。這是 Server 規則，指定 Client 的動作與同步留待實機。

## 擊倒經驗

一般副本的初始怪物、順序增援和計時增援都可逐隻指定 `defeatExperience`。例如頭目出場列可設定 `"defeatExperience": 11`。省略時為 0。Server 在該實體從存活降至零血量時累計一次。跨圖保留同一場的累計，最終出口將擊倒、清場、通關三項合併為同一筆經驗入帳。退出未結算的場次會捨棄暫存的擊倒經驗。進度指定場次沒有經驗入帳。

載入時逐條計算可達通關路線的獎勵，包含該路線各圖的清場、普通怪、頭目與全部增援，另加通關基礎經驗。單一路線的合計上限為 2,147,483,647。互斥分支各自計算，共用路段只在同一路線計一次。實際只計玩家走過的路線及確實擊倒的怪物。原有各 Case 配置未設定擊倒經驗，保留原先的通關經驗。此欄位屬 Server 規則。

### 可載入的練等配置

[Case 1 練等配置](phindos-stage1-case1-leveling.scenario.json)沿用地圖 1 起點與原有五圖、怪物、出口和頭目掉落。14 隻普通怪各 4 EXP，頭目 24 EXP，通關基礎獎勵 20 EXP，每場合計維持 100 EXP。擊倒獎勵在通關前累計，全部經驗仍於最終出口入帳。分配數值是 Server 暫定規則。

Host 保持 Case 1，設定 `TARTAROS_LOCAL_STAGE_ONE_SCENARIO_PATH` 為這份定義的絕對路徑，`TARTAROS_LOCAL_STAGE_ONE_SCENARIO_SHA256=95172edf5d4f543eb36e57d0a2c8bd4682c543953d6a25c9ac3d28f340758e77`，讓經驗取自定義（省略 `TARTAROS_LOCAL_STAGE_ONE_COMPLETION_EXP`），並以 `SCENARIO_CATALOG` 啟用掉落。執行 Host 預檢時，預期的 `CompletionExperience` 是基礎獎勵 20，完整通關的結果是 100。預檢可加上 `-MinimumRouteExperience 100 -MaximumRouteExperience 100`，同時核對兩個總額。
