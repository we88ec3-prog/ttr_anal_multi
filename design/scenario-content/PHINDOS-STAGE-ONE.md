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

使用復活卷軸後，地形傷害區會從下一次世界更新重新計時。在原地復活的角色有該區域設定的一個完整傷害間隔可離開。既有怪物及關卡旗標保留，後續可繼續清場。這是 Server 的復活規則，指定 Client 的動作與回饋仍待實機驗收。

## 怪物繞行

一般副本的追擊若被牆擋住，Server 可用本機地圖的可通行格尋路。有巡邏路點或無巡邏路點的怪物都可繞行。若怪物設定追擊半徑，搜尋仍受該範圍限制。每次更新至多規劃一條路線，同一怪物至少間隔半秒才重算，屏障開關後可立即重算。找到路線後，Server 逐步更新位置，出手及命中仍檢查通路。這是 Server 規則，指定 Client 的動作與同步留待實機。

## 擊倒經驗

一般副本的初始怪物、順序增援和計時增援都可逐隻指定 `defeatExperience`。例如頭目出場列可設定 `"defeatExperience": 11`。省略時為 0。Server 在該實體從存活降至零血量時累計一次。跨圖保留同一場的累計，最終出口將擊倒、清場、通關三項合併為同一筆經驗入帳。退出未結算的場次會捨棄暫存的擊倒經驗。進度指定場次沒有經驗入帳。

正常入口依可達通關路線的最低總經驗判定。每條路線的總經驗均為正時，可省略 `completionExperience`，完全由 `defeatExperience` 與 `clearExperience` 提供獎勵。這種設定的 `/health` 會顯示 `normalEntryEnabled=true`、`completionExperience=0` 及 `completionExperienceSource=ROUTE_REWARDS`。本機預檢可用 `-CompletionExperience 0 -ExperienceSource ROUTE_REWARDS`。省略固定獎勵且存在零經驗路線的設定仍只適用測試預覽，並停用掉落。

載入時逐條計算可達通關路線的獎勵，包含該路線各圖的清場、普通怪、頭目與全部增援，另加通關基礎經驗。單一路線的合計上限為 2,147,483,647。互斥分支各自計算，共用路段只在同一路線計一次。實際只計玩家走過的路線及確實擊倒的怪物。原有各 Case 配置未設定擊倒經驗，保留原先的通關經驗。此欄位屬 Server 規則。

### 可載入的練等配置

[Case 1 練等配置](phindos-stage1-case1-leveling.scenario.json)沿用地圖 1 起點與原有五圖、怪物、出口和頭目掉落。14 隻普通怪各 4 EXP，頭目 24 EXP，通關基礎獎勵 20 EXP，每場合計維持 100 EXP。擊倒獎勵在通關前累計，全部經驗仍於最終出口入帳。分配數值是 Server 暫定規則。

Host 保持 Case 1，設定 `TARTAROS_LOCAL_STAGE_ONE_SCENARIO_PATH` 為這份定義的絕對路徑，`TARTAROS_LOCAL_STAGE_ONE_SCENARIO_SHA256=9e3af74130568f177b843245a61e2fbf7961ceb22391cf73f3030d0635b6e931`，讓經驗取自定義（省略 `TARTAROS_LOCAL_STAGE_ONE_COMPLETION_EXP`），並以 `SCENARIO_CATALOG` 啟用掉落。執行 Host 預檢時，預期的 `CompletionExperience` 是基礎獎勵 20，完整通關的結果是 100。預檢可加上 `-MinimumRouteExperience 100 -MaximumRouteExperience 100`，同時核對兩個總額。

### 其他起點與分岔的練等配置

四個 Case 都可選地圖 1、2、3 的練等配置。每隻普通怪 4 EXP、頭目 24 EXP、通關基礎 20 EXP。地圖 2 或 3 起點的路線少三隻普通怪，因此在兩條互斥分支的各自節點加 12 清場 EXP。每場只會經過其中一條分支，完整通關均為 100 EXP。獎勵數值是 Server 暫定規則，沿用對應原配置的出生、戰鬥、出口與頭目掉落。

Host 按下表設定 Case、關卡絕對路徑與 SHA-256，並沿用 Case 1 練等配置的獎勵預檢。地圖內的出口由玩家按 Z 選擇，起點取決於 Host 載入的配置。

| Case | 起點地圖 | 練等配置 | SHA-256 |
|---:|---:|---|---|
| 1 | 1 | [配置](phindos-stage1-case1-leveling.scenario.json) | `9e3af74130568f177b843245a61e2fbf7961ceb22391cf73f3030d0635b6e931` |
| 1 | 2 | [配置](phindos-stage1-case1-map2-branches-leveling.scenario.json) | `a1480f4ee153f761de124ee74be0c6f4d0e1055972b445d3304463f8c54a1af1` |
| 1 | 3 | [配置](phindos-stage1-case1-map3-branches-leveling.scenario.json) | `f0e75ca068c11d8a94df5533b9e2d7cab177cbe86018b23b68437b6b36d06407` |
| 2 | 1 | [配置](phindos-stage1-case2-leveling.scenario.json) | `50d4636ed8c75caf215b7474d81c7256f39da2991e62fec0ee8647895fd0401a` |
| 2 | 2 | [配置](phindos-stage1-case2-map2-branches-leveling.scenario.json) | `5194fc19fa908cdab862808f222e18b523223dd5cab07cd29347fb8bf6ae50b7` |
| 2 | 3 | [配置](phindos-stage1-case2-map3-branches-leveling.scenario.json) | `746a8857af553a975a6ab74288b8b6d35e72b373730201b2cb60c0a1ea8de5d8` |
| 3 | 1 | [配置](phindos-stage1-case3-leveling.scenario.json) | `b897f667564ae7ea2540202912a87de85189bcb90c9256b5484a753d1df0d8fe` |
| 3 | 2 | [配置](phindos-stage1-case3-map2-branches-leveling.scenario.json) | `4eb59c4d27493020915a317b61e090066abb8e1b9a4eb6ce03e52dc4b76601f8` |
| 3 | 3 | [配置](phindos-stage1-case3-map3-branches-leveling.scenario.json) | `92f6aa24937670c8a1595982ab72eec2b958e64474d40492931b2dc31a186492` |
| 4 | 1 | [配置](phindos-stage1-case4-leveling.scenario.json) | `1a438df994e6e66e28287c3e455f47cccd7d38f1eb71fc8214aac1c38e14776c` |
| 4 | 2 | [配置](phindos-stage1-case4-map2-branches-leveling.scenario.json) | `e8b48ac51870732f9e732d92da7410da94f160f21f83723e0d7845328e1cca06` |
| 4 | 3 | [配置](phindos-stage1-case4-map3-branches-leveling.scenario.json) | `e945ee24a3ec51c597faa09f906caa0f1b8ae9390b30afb8b7db33159f554f57` |

## 頭目戰鬥設定

12 份練等配置只對地圖 19 的頭目 1086/PRE1 指定 `phindos-stage1-boss-v1`。這份 [行為設定](phindos-stage1.monster-behavior.json) 將頭目 HP 設為 120，普通怪保留 60 HP，沿用既有攻擊與倒地動作。這是暫定的 Server 數值。必要頭目、掉落與通關總經驗仍由關卡定義控制。

Server 可使用內建行為設定。若部署有設定 `TARTAROS_LOCAL_MONSTER_BEHAVIOR_PATH`，須包含 `phindos-stage1-boss-v1`；上方行為設定的 SHA-256 為 `67dadc1ac485c38481d4f84d171b4f9b4e2587f92cabb31022f5802ac1228ef2`。若另外使用自訂怪物配置，應保留其餘已用的行為並更新該檔的雜湊。

頭目血量歸零時即產生設定中的掉落，可以先拾取。清場須等必要頭目的倒地移除訊息列入同一輪或更早的 Server 更新，再開啟出口。這讓設定較長倒地時間的頭目也能完成倒地流程。合成測試用 3 秒移除時間驗證，實機動畫及地面特效仍待確認。

一般副本的每張圖都套用相同的移除順序。普通怪或增援仍在等待倒地移除時，Server 暫不累計本圖的 `clearExperience`，也不開啟清場出口。已生成的地面道具可在這段時間依正常距離與路徑規則拾取。此順序適用 Stage 1 一般副本，教學及主線副本沿用各自的清場判定。

## 馮德斯第一狩獵場 Stage 462／Case 693

Host 可用 `TARTAROS_LOCAL_STAGE_ONE_CASE=693` 載入[關卡定義](phindos-stage462-case693.scenario.json)，SHA-256 為 `a1a9dca3e9f5d7eac42585144b1c727d04300dbd49b75fe984ae624d1968e2bf`。沿用原版 BND 目錄與既有 `SCENARIO_CATALOG` 掉落設定。原有 Case 1～4 配置仍可照常使用。

玩家正常建單人隊進馮德斯，在狩獵場面板確認第一個項目。隊長的 `0064` 帶 Stage 462（`6400CE01`），Server 用 `009A` 回填大廳選項。隊長另按開始後，以 `0038` 送 Stage 462、Case 693。回村且維持隊伍時，重建大廳會重新發布選項，離隊或離村後須重新選擇。 [選關與資源證據](../../governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md#狩獵場確認送出-0064)

地圖依序為 `3430 → 3431 → 3432 → 3433 或 3435 → 3437 → 3438`，分岔的另一個出口鍵為 6。路線來自 Case 693 圖表，實體地圖分支、出生、出口和群組位置是 Server 候選配置。兩條路各有八隻普通怪與頭目 1086／PRE 1。暫定普通怪每隻 4 EXP、頭目 24 EXP、固定通關 20 EXP，總計 76 EXP。頭目可掉落 Product 183。定義使用 `NOT_NATIVE_MEF` 關卡格式。

首圖 3430 的普通怪 `1004/PRE1` 也使用節點的 `groundDrop`。暫用與頭目相同的 Product 183、外觀 162、數量 1、半徑 12，作為可由關卡作者調整的掉落規則。兩條分支皆已用原版 BND 在離線 Server 驗證首圖及頭目掉落、各自撿取入包、換圖與 76 EXP 結算。指定 v2 的物品外觀與 Space 操作仍待驗收。

### Case 694

同一狩獵場可改用 `TARTAROS_LOCAL_STAGE_ONE_CASE=694` 和 [Case 694 關卡定義](phindos-stage462-case694.scenario.json)，SHA-256 為 `f6c86e34c80db266a831d1571f15c5431f45c062d838992b2313d7d0d830de25`。玩家仍選 Stage 462。Server 在 `0038` 發布 Case 694，並依 `CHART_Re_mushroom_02.xml` 的 `1 → 3 → 4 → 6 或 7 → 5 → 2` 送出節點鍵。分岔的另一個出口鍵為 7。實體地圖、出生與怪物位置沿用 Case 693 的 Server 候選配置，兩條路皆為 76 EXP，頭目掉落 Product 183。預檢使用 `-ScenarioCase 694`。

## 馮德斯第二狩獵場 Stage 463

玩家確認第二個狩獵場時送 `6400CF01`，大廳候選回覆為 `9A00CF01`。Host 須載入下面其中一份關卡，並設定相同的 `TARTAROS_LOCAL_STAGE_ONE_CASE`、定義 SHA-256、原版 BND 目錄和 `SCENARIO_CATALOG` 掉落模式。預檢使用相同 Case。

| Case | 原版圖表節點 | 定義 SHA-256 |
| --- | --- | --- |
| [695](phindos-stage463-case695.scenario.json) | 1 → 2 → 3 → 5 → 7 → 9，或 1 → 2 → 4 → 6 → 7 → 9 | `03f3cf01fd4931fb3a89ca6975b76adf56f6f56edbabf6ac4d3d87a9c72ef427` |
| [696](phindos-stage463-case696.scenario.json) | 1 → 2 → 3 → 4 → 5 → 8，或 1 → 2 → 6 → 7 → 5 → 8 | `9679e2d7dfed19f5e585fefc5977f76dcd9c7fce8e25be1016517a4b13ffdf84` |

兩份定義逐邊對照原始 `CHART_Re_reed_01/02.xml`。地圖依序為 3439、3440、3441／3442、3444／3445、3446、3448。這些邏輯地圖的模型和 BND 源於 `_MapList.xml`，分支變體 3443、3447 暫不使用。怪物模型、PRE 與數量取自 `CLUST_Re_reed_01.xml`，實際組別分配、出生、出口與獎勵由 Server 暫定。頭目候選為 1083／PRE 1，採用既有 120 HP 頭目配置，掉落 Product 183。每條路八隻普通怪各 4 EXP，加頭目 24 EXP、通關 20 EXP，合計 76 EXP。兩個 Case 的四條分支各離線連刷兩次，指定 v2 實機待驗。

## 同一 Host 開放兩個狩獵場

原有 `TARTAROS_LOCAL_STAGE_ONE_*` 指定第一份配置。加上 `TARTAROS_LOCAL_HUNTING_GROUND_ALTERNATE_PATH`、`TARTAROS_LOCAL_HUNTING_GROUND_ALTERNATE_SHA256` 和 `TARTAROS_LOCAL_HUNTING_GROUND_ALTERNATE_CASE` 指定第二份。兩份須分屬 Stage 462 和 463，可交換順序。共用 BND 目錄、經驗政策與掉落模式。每個 Stage 配置一個 Case。

隊長的 `0064` 選擇狩獵場，`0008` 以當時選擇建立場次。場次固定使用同一份配置處理預載、換圖、怪物、掉落與結算。回村會重新發布原選項，之後可在同一隊伍改選。Host 的 `/health` 會在 `localHuntingGrounds` 列出兩份已載入配置。離線工具可在 `--stage-one-journey` 參數最後加 `--alternate-hunting-ground <關卡檔> <SHA-256> <Case>`，以同一連線依序通關兩個場地。

## 結算分項

一般副本 `0022/type 2` 以應用資料起點計算位移。`+8` 的「關卡獎勵」合計清場與固定通關經驗，`+12` 的「殺戮獎勵」顯示擊倒經驗，`+20` 為 SQLite 實際入帳總額。隊伍與排名欄暫為零。若經驗達上限而只能部分入帳，優先列入擊倒獎勵，剩餘才列為關卡獎勵。進度指定場次維持零獎勵。 [Client 結算欄位證據](../../governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md#結算介面的五個數值)

Stage 462／463 目前公開的四份設定，完整通關會顯示關卡獎勵 20、殺戮獎勵 56、總經驗 76。離線工具逐欄核對結算與角色經驗。指定 v2 的文字與畫面待驗。

## 通關出口驗證

一般副本的關卡定義載入時，Server 檢查所有結算出口都位於該 Case 的最終頭目節點，且該節點的所有出口都進入結算。配合關卡圖的可達性和無循環驗證，任何分支都必須走到最終頭目。頭目倒地移除、其他怪物清除及出口互動仍由各場次的正常流程處理。

## 同一狩獵場輪替 Case

每個已開放的狩獵場可加載另一份原版圖表對應的 Server 關卡。為第二個 Case 設定 `TARTAROS_LOCAL_HUNTING_GROUND_ROTATION__<Case>__PATH` 與 `TARTAROS_LOCAL_HUNTING_GROUND_ROTATION__<Case>__SHA256`。例如主設定為 693、另一狩獵場為 695 時，可分別配置 694 與 696。Host 會驗證每個輪替 Case 與已開放狩獵場同 Stage，並在 `/health.localHuntingGrounds` 列出全部配置。

同一遊戲連線內，各 Stage 從主設定的 Case 開始。每次正常通關並成功入帳後，下次同 Stage 開場改用另一個 Case。放棄場次及進度指定場不推進輪替。這是 Server 的暫定輪替規則，原版 Case 抽選規則仍待證。離線工具的 `--alternate-hunting-ground` 若指定同 Stage 的不同 Case，會驗證主 Case、輪替 Case、回到主 Case 的順序。

隔離 Host 已使用獨立 SQLite 和 loopback 埠同時載入 Case 693–696。四份配置分別通過 `check-stage-one-host.ps1` 預檢。指定 v2 Client 的 TS-37E 實機驗收仍待執行。

回到馮德斯後，本機測試頁的「下次開場」顯示該狩獵場下一次會使用的 Case。「上次通關」保留剛完成的 Case、路線、拾取筆數及實際入帳經驗。離線驗證會在第三次開場前比對這兩筆狀態，再核對實際入場訊息。輪替啟用時，即使兩次都選同一狩獵場，這兩筆 Case 也可以不同。

「上次通關」也記錄該場結算時的角色等級、累計經驗、本級起點及下一級門檻。這些數值來自已入帳的收據，回村後改選場地仍可用來對照遊戲的經驗條。離線四場交替流程逐場核對摘要與 SQLite 角色經驗，實機顯示依 TS-37H 驗收。

離線流程亦驗證輪替場的中途離場。收到既有離隊訊息 `005D/00` 時，Server 回覆離隊並讓玩家回馮德斯。已存經驗維持原值，沒有本場結算。玩家在村內重新建隊、選同一狩獵場後，仍以尚未通關的輪替 Case 從入口開始。已核對隊伍重建、換圖、結算與下次開場的 Server 訊息。指定 v2 Client 是否能從副本內的介面送出這個離隊訊息，仍待實機確認。

同 Stage 輪替的離線驗證連刷三場。以起始累計 100 EXP、每場 76 EXP 的伊希莉亞測試，兩個狩獵場都依序入帳至 176、252、328。第三場結算升到 3 級，第四場載入輪替 Case 時，角色資料與經驗條訊息仍顯示 3 級、328 EXP、本級起點 300 和下一級門檻 600。這組數值沿用目前的 Server 候選經驗政策。

離線工具可在雙狩獵場旅程參數尾端加入 `--rotate-both-hunting-grounds <第一場地輪替檔> <SHA-256> <Case> <第二場地輪替檔> <SHA-256> <Case>`。從同一個冒險團連線交替選場，核對 693、695、694、696 各自通關後，第一個場地回到 693。四場的掉落、背包、結算及回村摘要均已離線核對，累計由 100 增至 404 EXP。

### TS-37I 部署預檢

使用已有馮德斯、角色經驗、商品目錄與原版 BND 的本機 Host。將 `TARTAROS_LOCAL_STAGE_ONE_CASE` 設為 693，`TARTAROS_LOCAL_HUNTING_GROUND_ALTERNATE_CASE` 設為 695，輪替條目設為 694 與 696。四個路徑各配對相應的關卡檔與 SHA-256，掉落模式用 `SCENARIO_CATALOG`，通關經驗由關卡定義提供。

`/health.localHuntingGrounds` 的 `isRotationCase` 為 true 時表示該配置是輪替 Case。私有 Server 的 `tools/check-phindos-hunting-grounds.ps1` 可一次核對四份關卡。提供 `-HealthPort`、`-LoginPort`、`-ScenarioDirectory`、`-ExperiencePolicyPath`、`-TradeCatalogPath`。預設預期主 Case 為 693、695，並核對各關卡入口、SHA-256、掉落模式及 76 EXP 路線上下限。此預檢已在獨立 loopback Host 通過，實際 Client 操作依 TS-37I 驗收。

指定 v2 的部署再加 `-CheckClientEndpoints`，使用登入 8415、主連線 8416、輔助 8414 與測試頁 5082。預檢確認四個端點只綁在 `127.0.0.1`、由同一 Host 持有，且本機測試頁狀態可讀。隔離 Host 已在這組固定埠通過。尚未開啟 Client 時，測試頁回報 `NO_GAME_CONNECTION`，實際登入與入場仍由實機驗收確認。

私有 Server 的 `tools/start-phindos-acceptance-host.ps1` 可重建此部署。先建置 Release Host，再以 PowerShell 7.4 以上執行，指定 `-Workspace`、`-AnalysisDirectory`、`-BoundsDirectory`、`-Database` 和 `-LogDirectory`。資料庫須先具備本機冒險團、教學、主線及經驗儲存元件。先用隔離資料庫執行 `-PreflightOnly`，成功後會關閉該次 Host。正式本機驗收省略該開關，成功後 Host 保持監聽。兩種模式都已用隔離資料庫核對。啟動器為該程序套用固定設定及內容雜湊，遇到既有埠占用會停止啟動。

沿用較早的本機測試資料庫時，先用 SQLite backup 建立獨立副本，並執行 `PRAGMA integrity_check`。若副本缺少 `local_expedition_role_progress`，在私有 Server 根目錄執行 `dotnet run --project tools/Tartaros.LocalExpeditionMigrate -c Release -- --db <副本絕對路徑> --initialize-role-progress-v1`，再執行四關預檢。已以既有測試資料副本實際核對此步驟，帳號、教學進度、馮德斯旅程紀錄及主線場次／事件逐列相同，新增的副本經驗帳本從空白開始。這項結果驗證資料庫可供 Host 啟動，實際角色登入與副本流程仍依 TS-37 驗收。
