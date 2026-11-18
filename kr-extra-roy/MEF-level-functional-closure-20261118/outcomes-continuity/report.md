# 關卡生命週期、通關結果與保存：MEF 功能分析

**本分題已把正常主線、一般副本與單人挑戰的進關、可操作、清場、轉場、結果、拾取、復活及保存串成可實作的契約。MEF 包含 Server 執行的關卡規則，也包含 Client 已證可執行的有限演出；已有 Server 實作保留其進度。** 新增分析不以官方 MEF 格式為前提，也不把「需要保存」解讀成 MEF 不處理。

**發布前較新 main 補註：** 固定 commit `7344eeb65198e2dd61684b66cf811021765ed8f5` 已新增 Product 184 付費完全復活的購買／領取／裝備容量／背包與快捷請求／同場續戰／store reopen 離線證據，應計入已有進度。死亡懲罰與評級效果、Scenario 特定 Client 入口及指定 v2 操作仍明列未閉合。新增四份來源 pin 與精確影響見 [latest-main-update.md](latest-main-update.md)／[JSON](latest-main-update.json)；原 50 份分析基準不變，本 agent 沒有重跑上游測試。

本輪新增的主要結果：

- 釐清 **Q119 的兩次敘事提交與重建邊界**：清組後可以先在規則狀態解鎖，但清場劇情完成、提交並重建後，World 才以當時旗標發布完整點集合。重建前做的 Client setter 不會因此成為新一代點的狀態。
- 把 **擊倒時已入帳**、**通關才入帳**、**畫面預告**、**待領獎勵**、**離場丟棄的暫存量** 分開。Q119 首次完整成長配置為 `68 + 5880 = 5948 EXP`；一般 Case 693–696 為 `56 + 20 = 76 EXP`。這是所選設定的計算與既有開發紀錄，並非本輪新跑 Server 收據。
- 原 BIN 新閉合 Scenario 結果的非零 `+9` 分支：它進 **招募新角色視窗 `CEmployNewCharacter`**；該視窗的指定按鈕在非 mode 1 分支送出兩 bytes `C2S 0033`。它有自己的按鈕與教學例外，不能泛稱為一般結果確認或任意關窗成功。
- 重新計算 11 份既有設定、15 條正常路線，保留每個設定的實際差異；主線「資源延續版」與「經驗／掉落版」沒有被偷偷合成一份已部署內容。

來源固定在 `09799b117f01e577be56dee3e909e1cde25b855f`；原 BIN 為 SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。50 份來源、18 個原件視窗、20 項原生斷言的身份與內容核對通過。詳見 [來源清單](source-manifest.json)、[機器契約](lifecycle-contracts.json)、[路線投影](outcome-projections.json) 與 [驗證收據](verification.json)。本輪沒有啟動 Server、Client、Lua 或修改原件；已有實作與先前離線／人測狀態按原紀錄採用。

## 1. 進度如何判讀

「分析完成」表示已列明可用入口、狀態、順序、提交點、既有成果與具體缺邊，不表示這次完成部署或指定 v2 人測。以下 P0／P1／P2 是本分題的交付優先序，沒有改正式需求台帳。[S01–S03]

| 優先序／玩家功能 | 已有進度 | 真正還缺的項目 | 可優化的方向 |
|---|---|---|---|
| P0 進關後能正常走動和戰鬥 | field、地圖、角色、控制綁定、點集合及 ready 的正向鏈已知；已有正常入場流程 | 選定內容與 profile 的接線；指定 v2 的完整畫面和操作驗收 | 相容 controller 可重用；必要綁定、點與資源一次成批發布 |
| P0 打完怪、播完劇情才開門 | 等待屍體移除排送、敘事提交、重建及完整 `0027` 已有規格 | 若新增重建後有限插播，要明確抑制提前開點並綁定新 generation；同包根報告處理已看過 scene 的分支 | 無重建時使用小量點更新；有重建時只發布一份完整集合 |
| P0 主線通關領獎與回村 | 終點、返回劇情、經驗／錢包／熟練度及進度同交易已有接線 | 新 MEF 內容接既有服務；v2 結果與回村操作 | 結果顯示使用對應候選或已入帳收據；擊倒經驗不再重加 |
| P0 打怪掉物、撿起來不會丟 | 血量歸零掉落、Space 意圖、背包交易、claim 去重及離圖清理已有實作 | 特定掉落外觀與 v2 拾取觀感；正式新裝備掉落內容 | 同一更新批次發掉落；有效拾取維持先存入再消失 |
| P1 換圖不把血魔和冷卻重置 | 普通副本已有承接；一般主線可用 `preserveOwnerAcrossNodes` | SC-01 人測；連段、蓄氣、暫時增益、投射物跨圖尚未開放 | 保存絕對截止時間與回復起算時間；第一批角色資料就用承接值 |
| P1 一般副本練等、分支與連刷 | Case 693–696 八路已有正常離線戰鬥、拾取、結算／回隊伍紀錄 | 指定 v2 的正常選關、分支、拾取、結算及連刷 | 只在成功入帳後推進 Case 輪替；回隊伍重發正確選關 |
| P1 倒地後用卷軸原地復活 | 普通／主線及單人挑戰有既有復活處理、扣物與帳號 UTC 冷卻 | v2 復活動畫與重新可操作；完全復活的「死亡懲罰解除」效果仍未閉合 | 扣物與冷卻同交易；復活後新輸入才移動，危險區重啟完整間隔 |
| P1 離場、重登還保有已拿到的東西 | 普通副本離隊保留已拾取物品與已入帳擊倒經驗；主線重登保留已完成進度 | 主線倒地退出按鈕／請求未證；普通副本內實際離隊 UI 待驗；未提供戰鬥中途續接 | 保存業務里程碑；未完成場依現政策重開，避免不必要的逐幀存檔 |
| P2 挑戰成功拿書、失敗結算 | 三本經驗書的待領紀錄、滿包保留、run 去重；單人失敗 CP 候選已有實作 | 指定 v2 提示與結果；主動退出／斷線 CP 政策；多人路徑不屬這份單人契約 | 先保存獎勵權利再顯示卡片，後續可重試領取 |
| P2 結果之後出現新角色介紹 | 本輪補出 RTTI、實際按鈕與非 mode 1 的 `0033` 發送鏈 | 其他關閉／取消路徑未證；此證據本身沒有完成角色授予或人測 | 正常結果與招募視窗分開綁定；只使用合法且已初始化的角色選項 |
| P2 普通任務目標／已完成進度 | Accepted、Ready、目標計數及登入／換圖回填已有紀錄 | 新目標種類逐項接實際事件；沒有任意 Lua 變數上報的已證通用接口 | 沿用共同 journal 與事件索引 |
| P2 減少逐關專用程式與表現命令 | 共用事件引擎、有限 Q、Client 原生表現可組合 | 新內容編譯／adapter 與相同正常內容的實際量測 | 載入時建立條件索引；一次選擇有限內容；避免逐句下指令 |

本表的技術依據見以下各節；機器版每列都有來源 ID 與 `new_runtime_pass_claim=false`。不存在以通過幾個腳本就換算「遊戲功能完成百分比」的做法。

## 2. 入場與可操作：五件事各自有責任

既有正常入場可復用，但不能只看地圖出現就宣告玩家可操作。[S10、S11、S22]

| 層次 | 可用介面／既有消費者 | 整合必須滿足的條件 |
|---|---|---|
| 場景種類 | `005F/type 2` 為 Scenario／Formation；type 4 為 Mission／Single；Raid 使用 type 9 | 選對 field、controller 和頁面；場景安裝本身不保證停止上一段 Q |
| 地圖與地形 | `0012` 清點、reset controller，再由 map ID 進 loader | 同 MapID 也先清點和控制資料；相同地形可被多個邏輯 map 共用 |
| 世界角色／控制關聯 | 既有角色生成、world ID、relation／controller 綁定 | world actor 要在被引用前存在；新一張圖不能沿用未驗證的舊指標 |
| 出口及互動點 | `0027` 完整集合；`0048`／Lua setter 改已有的點 | `0027` 是替換；setter 不新增點、不改座標，同類別／key 必須唯一 |
| 控制與 loading | `0014`、`0023/0024`、Q End、`00EB` 分別處理 | `0014` 不等於解除 Q 等待；`00EB` 不等於建立角色／完成載圖；active Q 仍可能抑制一般控制 |

這是必要依賴的**偏序**，不是復原官方固定封包順序。共用主線引擎已將事件規劃放在獨立 instance snapshot，敘事 Commit 後才發布狀態。新 MEF 接線應沿用此邊界，不要直接把收到任一 scene 回報視為整場完成。[S17]

## 3. Q119 清場：關鍵是提交、重建與新的點集合

Q119 現行敘事資料是 NPC 10047、Field 26、Case 107；runtime 節點依序 1／2／3／4，Map 632／633／634／635。來源的 `sourceNode` 則為 4／3／2／1，兩者不是同一個鍵。intro 為 scene 1；圖 632 入場 scene 2、圖 635 入場 scene 3、圖 635 清場 scene 4；返回 Town 1 使用 scene 5。[C12；路線投影]

最後一張的順序如下。「提交 A／B」是本分析用語，沒有新增既有 schema 欄位。[S04、S17]

| 階段 | 事件／條件 | 狀態與動作 | 不能誤認為 |
|---|---|---|---|
| 1. 怪物倒下 | 權威 HP 從正值變 0 | 掉落可立即生成；符合條件的擊倒經驗先交易入帳 | 全圖已清，或倒地動畫已播完 |
| 2. 移除排送 | 該圖所有必要倒地物件的移除訊息已列入本次或先前更新 | 才允許提交清場／啟動後續劇情 | Client 已回覆「動畫完全結束」；目前只證排送依賴 |
| 3. 清場規劃與提交 A | 必要怪物、波次、頭目清除條件滿足 | 事件引擎可把出口規則標為解鎖，敘事提交後發布該階段；World 仍等清場劇情 | 已對玩家開門或發放最終獎勵 |
| 4. 清場 Q | 依目前敘事步驟選 scene 4 | 有限劇情執行與正確 End／輸入生命週期 | `003F` 是開點成功 ACK |
| 5. 劇情完成提交 B | 回報符合目前接受的清場劇情步驟 | 完成並提交敘事步驟，才接戰鬥／地圖重建 | 通關獎勵交易；此時尚未走最終出口與返回劇情 |
| 6. 重建同圖 | 既有主線重建流程 | 重建所需世界狀態；發一次完整 `0027`，採用已提交旗標；用過的互動保持停用 | 舊 field generation 的 setter 會自動保留 |
| 7. 點及控制交接 | 點集合、控制綁定、Q 收尾和 ready 條件齊備 | 世界按正常規則顯示／接受出口 Z | 一個 ready 封包能涵蓋所有前置 |

因此，上一輪「GroupCleared → 一次 `0047` → finite wait／setter／End」只能在它宣告的**同 field／同 generation、既有點仍在**條件使用。Q119 目前有中間重建；`0012` 清點、`0027` 替換點，重建前 setter 不能當成最終開門。既有重建又可能按旗標直接把點設為 enabled，這時重建後再 setter 沒有有效差額。[S10、S19]

若選擇讓有限 Client 內容在重建後負責最後開門，需要新的 adapter：先以明確策略保留該點關閉，在新 generation 的完整點集合和角色／控制狀態齊備後，才選擇可執行的 finite 內容。adapter 需避免過期 callback、重複鍵、already-enabled 狀態及「已看過 scene」跳過執行的分支。**這些是新接線需求，沒有被標成既有實作。** 根報告的 [finite-handoff](../finite-handoff/report.md) 補充 scene seen gate 與 `CSL.scn` 持久化；本分題不另建通用 world→Lua 事件橋。

沒有清場劇情且所有出口已預先登記的節點，現有規格允許只改點狀態，無須把整份地圖或完整點集再發一次。若只有一個點要改，既有 `0048` adapter 也可能比為此啟動一段有限 Q 更合適。[S04、S10、S19]

## 4. 正常主線的完整結果與返回

### 4.1 Q119 的可用映射

| 玩家看到的步驟 | MEF 規則與既有 Server 接線 | 保存／發布 |
|---|---|---|
| 找 NPC、組成參戰角色、看入場故事 | 驗證 Q118、等級／擁有角色、NPC 和目前敘事；採 Field 26／Case 107 和版本綁定 | 既有敘事 checkpoint、帳號租約與參戰角色 |
| 打四張地圖，按出口前進 | 每節點 Entry／GroupCleared／InteractZ；最後一張指定必要頭目及清場故事 | 每次符合規則的擊倒 XP 可即時存入；圖內旗標按 instance 存續 |
| 清場故事後走最終出口 | 上節重建／點交接後接受 Result 出口 | 建立受益角色、終點、圖版本、獎勵方案與返回條件的 outcome candidate |
| 看結果、按返回 | `S2C 0022/type 0`；直接結果確認的 `C2S 0033` 只有 opcode | 畫面可以預告尚待最終提交的任務獎勵；`0033` 沒有 Quest／Town／Map，須由當前 phase 解析 |
| 返回故事播完 | Q119 的 scene 5，返回 Town 1 | 通過目前帳號／租約／revision 後，完成事件、主線、經驗、適用錢包和熟練度同筆交易 |
| 回村，出現下一個任務 | 重建 village、owner、點、資產與任務快照；Q120 仍要滿足等級 8／NPC 10008 等資格 | 實際已提交的資料在 ready 前發布；登入由持久狀態回填 |

來源：[S04、S12、S13、S15、C12、C13]。上述是既有開發紀錄與本輪內容投影；不是在此 repo 外讀取即時部署程式或新執行的 Server 流程。

### 4.2 不把所有經驗都等到結算頁

Q119 成長／掉落設定的四圖擊倒經驗是 `8、12、16、32`，合計 **68**；末圖清場 **10**、整關通關 **20**，最後再加固定任務獎勵 **5850**。所以：

- 戰鬥中：已提交擊倒經驗 **68**，之後離場或重登仍保留。
- 正常返回劇情完成的任務交易：`10 + 20 + 5850 = 5880`。
- 首次完整走完的角色經驗增加：`68 + 5880 = 5948`。
- 配對的錢包政策可給 **900 LeeLoo**；必須啟用且符合它綁定的經驗政策 SHA，不能只因原表有數字就推成所有部署都會發。
- 原獎勵 type 3 的 **40** 已由後續資料閉合為技能熟練度，已有對應保存設計；它不應再列為未知獎勵類型。結果先顯示、返回交易時授予的差異仍保留。[S04、S12、S13、S20、S23、C03、C04、C13]

`story-q119-owner-continuity.scenario.json` 只提供該版本的延續功能；`story-q119-growth.scenario.json`／`ground-loot` 有經驗與掉落，但沒有因本分析而自動取得前者的選項。將功能合併成新內容是後續編排／驗證工作，不能把多份範例的優點加總後稱為同一份現況。

## 5. 一般副本：普通獎勵、分支與連刷

普通副本要使用自己的入場與 type 2 結果契約。Stage 選擇、Case 路線、map ID、節點鍵分開；`0008` 開始本身沒有攜帶 Case。Stage 462 由 `0064` 選取，`009A` 同步大廳選項，開始後採已接受的選項及 Host 配置。[S05、S22]

| Case 693 正常流程 | 已有可用內容／接口 | 結果與保存 |
|---|---|---|
| 單人隊長在正常大廳選狩獵場、按開始 | Stage 462／Case 693；Mission field type 4；`0038` 指定 Stage／Case，`0012` map，`0049` node | 產生新的 run 身分；不推進主線 |
| 首圖與增援 | node 10／Map 3430；node 1／Map 3431 的兩隻初始怪及 1.5 秒後一隻順序增援 | 對應擊倒經驗及 wave-qualified 掉落；初始同模型怪不能冒領限定增援掉落 |
| 分路再合流 | `10→1→3→5 或 6→4→2`；Map `3430→3431→3432→3433 或 3435→3437→3438` | 兩路都是擊倒 **56**、關卡 **20**；完整路線可生成三張必掉卷軸，實際入包取決於拾取 |
| 最終頭目及出口 | 指定 `1086/PRE 1`；必要頭目、其他怪與波次處理完，移除排送後才放行 | 新增本場清場／通關 **20**，使用已保存的擊倒收據；type 2 顯示 `20／56／76` |
| 確認、回原隊伍或回村 | 已選直接確認分支 `C2S 0019`；保留隊伍時可再次開始 | 保存資產重新發布；正常成功入帳才推進同 Stage 輪替 |
| 中途離隊 | 已有 `005D/00` adapter | 保留已領物品、已入帳擊倒 XP；未入帳的清場／通關量隨 run 結束，輪替不前進 |

四份 Case 693–696 成長設定共有 **8 條**正常路徑，本輪逐條計算皆為 `56+20=76`。Case 693 兩路各有三張保證生成的卷軸；其餘三個 Case 的正常路各一張。原專案已有原版 BND 正常離線旅程紀錄；指定 v2 實際選關、分路與結算畫面仍待驗。[S03、S05、C05–C08]

一般副本 `0022/type 2` 的已證讀取下限為 30 bytes。以下偏移用**十進位 application 起點**：`+8` 關卡、`+12` 殺戮、`+16` 隊伍、`+20` 總經驗、`+26` 排名。Client 在已核分支直接讀總經驗欄，不自行把列數相加。現行候選隊伍／排名為 0；若經驗封頂只能部分入帳，沿既有實際收據分項。`+24=2` 的直接確認路徑送 `0019`。[S05、S22]

舊可行性文件曾記「Stage 1 借用 type 0」「所有 XP 等到最後」，後續同文件與一般副本專項已有 type 2／擊倒即入帳更新。本報告採後續具體實作段落，不讓舊時間點重新變成當前缺口。

## 6. 結果頁不是同一種結果

| Profile | 結果入口 | 正常返回 | 業務提交的時機 | 本輪明確保留的界線 |
|---|---|---|---|---|
| 主線 Scenario | `S2C 0022/type 0`；CScenarioDecision／結果頁 8 | 直接分支兩 bytes `C2S 0033` | 所選主線政策在返回故事完成後提交最終任務交易；已提交擊倒 XP 不回滾 | 結果可能是預告；返回目的地由 Server 當前 phase 決定 |
| 一般 Mission | `S2C 0022/type 2` | 選定 `+24=2` 分支兩 bytes `C2S 0019` | 通關 run 的清場／通關 XP 先交易；畫面使用實際收據 | 切換 type 不代表 payload 相容 |
| 單人 Raid | `S2C 0022/type 3` | 已證結果分支兩 bytes `C2S 0019` | 成功先保存待領權利，或失敗先保存 CP 收據，再發布結果 | 不把 Raid 當 Scenario；mode 9 的本地 `0022` handler 與全域結果派送亦須區分 |

主線結果背景會清場並建立 EmptyController；把該 controller 的 ready 位設為 1 不會使它成為一般可玩 controller。返回仍要依既有流程建立 field、角色、關聯、點與相應 ready。`Q.RestoreMap` 只處理其視覺／相機層，不能代替完整回村。[S09、S10]

### 本輪補閉的新角色視窗分支

舊 Scenario 專項只追到 `+9 != 0` 時 `6BF310 / 596E00` 開另一視窗。這次由固定 decompilation 導航回原 BIN：

1. 結果 copy 把 application `+8` DWORD 存至 manager `+0x28`；其中 `+9` byte 就是 manager `+0x29`，結果按鈕用它發 `F431F`。
2. `5AACA0` 分別安裝結果視窗 `page+0x164` 和 `page+0x168`。後者由 `5AB020→5AB280` 建立，object vtable 為 `C3F024`。
3. 原 RTTI `C3F024[-4]→C7AD44→F87EF0` 的名稱是 `.?AVCEmployNewCharacter@FUI@@`。初始化槽 `+0x114=6BF140`，事件槽 `+0x15C=6BF2A0`。
4. 非零 `F431F` 將其參數交給 `6BF310`，只有 selector `<=9` 且對應角色記錄有效才填內容；不能把任何非零值視為合法參數。
5. 該視窗 `+0xD0` 綁 EID `0x5654`（22100）；`6BF2A0` 要求 click `0x578` 且 target 與該控制項相符。當 `context+0x5F4C != 1`，呼 `4A38D0`，sender 以長度 2 發 `33 00`。
6. 值 1 的分支設定 `g_TutoEmployCharQuery=1`，走本機通知與關窗，不能強行套 `0033`；其他關閉／取消也沒有由此被證明。

這封閉的是**特定招募視窗按鈕的返回意圖**。角色授予的持久化、正常結果按鈕、視窗取消三者沒有被混為一件事。完整原件窗口與斷言見 [native-proof.md](native-proof.md) 及 [native-evidence.json](native-evidence.json)。

## 7. 掉落、拾取與背包是一條獨立的持久化流程

掉落規則可以由 MEF 指定 monster／PRE、wave、Product、數量與機率。頭目選擇和掉落匹配要使用同一份明確身分；相同模型在初始群與後續波出現，不能只用 model ID 當唯一怪物。[S05、S06]

已知原生／既有 Server 分工如下：

- **生成與呈現：** HP0 時依內容建立地面物件；`S2C 0021` 有 31-byte row，可一次多筆。這只是地面物件，不代表背包已取得。
- **玩家意圖：** Space 對應的 `C2S 0007` 第三 byte 含 `0x80`；請求沒有目標 drop ID。Server 沿目前規則從附近、可達、符合資格的掉落選目標。
- **有效領取：** 有背包空間並通過商品／堆疊政策，先用 per-drop claim 身分提交，再發資產更新 `002C` 與物件移除 `001A`。背包滿或交易未成功，物件保持可領。
- **離圖清理：** 未領物件在換節點、結果／離場時按既有流程移除，已領物品留在背包；不把全部地上物件偷偷補發到背包。
- **外觀限制：** 原資料 visual 162 對到 `Spell_Scroll01`，現有原件未找到對應 effect 的來源已被記錄；特效缺失可能影響可見性，不能用成功交易替代實際可見性驗收。Server pickup radius 12 是配置候選，不冒充已完整還原的 native 搜尋半徑。[S06]

方向必須寫清：**`S2C 0021` 是地面掉落，`C2S 0021` 是背包直接使用；`S2C 0022` 是結果，`C2S 0022` 是快捷欄使用。** 這不是共用同一份格式的四個入口。[S06、S07]

## 8. 換圖、倒地、復活、放棄與重登

### 同一場的狀態延續

主線 `preserveOwnerAcrossNodes=true` 延續 HP／SP／MP、定時回復起點與技能絕對冷卻 deadline，涵蓋同一主線 instance 換節點及入場劇情後的重建。演出經過時間繼續計算，定時回復在戰鬥更新套用。預設 false；離開副本、完成／回村／重新入場便結束這段延續。[S04、C02]

新節點的怪物、位置與當前動作會重建。連段、蓄氣、暫時增益、投射物沒有被這項功能承諾保存。普通副本換圖第一個角色參數批次已改用承接後的資源比例；HP 按 10000，SP／MP 各按自己的上限換算至 0–100，`0034` 另給絕對值及上限。[S04、S05]

### 倒地與卷軸復活

倒地時清除當前及已保存移動意圖，倒地期間不接受方向推進、機關或出口。復活成功保留目前地圖、敵人與 run，原地回復資源，等新的方向輸入才移動；危險區由下一次世界更新重啟計時，給一個完整配置間隔。[S05、S07、S15]

普通 Product 183 為群組 2／300 秒；活動完全復活 248 為群組 3／4 秒。扣除卷軸與保存帳號 UTC 截止時間同一筆交易，跨圖、重登及 Server 重啟仍依期限判定。Client 的 `00B7` 倒數畫面不是實際可使用資格來源。已知動畫、快捷欄呈現與控制解鎖仍有指定 v2 人測缺口；完全復活表中的 Action 3 值 `-800` 與 Action 23 不能未查 consumer 就命名成經驗、疲勞或懲罰扣除。[S07]

兩種使用入口也要保留場景範圍：S07 已核的背包直接使用 class 26 分支接受 context mode 4／9，沒有由該分支涵蓋 Scenario 的 mode 2。現有主線復活服務及合成／離線紀錄，不能升格成「主線背包雙擊和快捷欄兩入口皆已原生閉合」。主線的實際可操作入口、復活動畫及後續控制仍按選定 v2 流程確認；這項限制不抹掉已存在的 Server 復活與保存服務。[S07、S10、S15]

較新 main 另補 Product 184 的付費正常來源接到這些服務：兩個一般狩獵場的合成正流程分別用背包／快捷請求，復活至裝備後容量並保留原 encounter，重開資產 store 仍保有數量、裝備、快捷及冷卻。它是 `OFFLINE_SYNTHETIC`，不是本輪新增 TCP、Client 或部署；S07 的 class 26 入口文字在該 main 與原基準逐 byte 相同。SkillCast 437 視聽、Action 3／23 與死亡懲罰／評級仍未驗證，CS-06 仍待排。[較新來源 U01–U04](latest-main-update.md)

### 放棄與重新進入

| 情境 | 現行可採用行為 | 還缺什麼 |
|---|---|---|
| 一般副本 `005D/00` 離隊 | 已拾取背包、已入帳擊倒 XP 保留；未領物件清掉，待結算清場量不發；下次同未完成 Case 從入口重開 | Client 是否能從副本內實際操作送出這條請求，仍待 v2 |
| 主線倒地退出 | 原地復活與重登回廣場再重開未完任務已有路線 | **倒地退出按鈕／請求尚未取證**；不能把隊伍離隊 `005D/00` 自動套過來 |
| 主線重登 | 保存已完成前綴、資產、已入帳 XP、帳號 cooldown；正常進村找 NPC 重開未完成任務 | 沒有戰鬥中途 checkpoint，未保存怪物現況或 Lua coroutine |
| 一般副本結算／離隊回單人城鎮 | `0069` 載入提示後等 `0043/type 10`，再發布村圖 `0012`／背包 `0029`；保留隊伍回大廳可同批發 map／bag | 實機的按鈕、載入與資產畫面 |
| 城鎮返回廣場 | 既有 `0042` 正常世界地圖返回路線，別名化會混淆結果返回 | 它不是 Scenario `0033` 或 Mission／Raid `0019` 的同一流程 |

來源：[S05、S15、S16]。普通任務的 Accepted／Ready／目標計數另有持久 journal，不應因未保存「整場戰鬥」就被誤判為完全沒有中間任務進度。[S14]

## 9. 單人挑戰的成功、失敗及待領物品

Stage 50／51／52、Case 88／89／90 的五張圖配置可沿既有正常單人隊長入口使用；三份 scenario 本身沒有通關 XP 欄，**不等於沒有外部獎勵政策**。其成功獎勵是 Product 2274／2275／2276 的經驗書及相應持久待領 claim。[S08、C09–C11]

成功先按帳號＋run 存待領權利，再發 Raid type 3 結果，最後出口／返回結果流程按既有規則處理。回廣場嘗試把書存入背包；滿包保留 claim，重登也可補領，每個 run 去重。卡片外觀不是入包收據。[S08]

單人倒地可收到 `0039` 開 10 秒倒數；成功復活以 `003A` 關閉提示繼續戰鬥。`0031/0` 或期限到達按既有候選進失敗；run 的成功／失敗互斥，一次失敗至多扣 140 CP 且餘額不低於 0，交易後才發布餘額及 `type 3,+8=0` 無獎勵列的結果，`0019` 回廣場。**主動退出、斷線 CP 政策與多人分支仍是不同需求**，不能以這份單人倒地契約宣布涵蓋。[S08]

## 10. MEF 減負應落在哪裡

優先重用已存在的引擎、交易及發布 adapter；新增內容讓它們少寫逐關專用程式。只有經已證 Client profile 承擔的計時／演出／點操作，才可算實際移走 Server 的對應表現工作。[S17–S19]

| 優化 | 具體做法 | 必須保留的正確性 |
|---|---|---|
| 內容在載入時編譯 | 建 event→rule 索引、預解 typed IDs／Product／獎勵方案，固定圖與政策 SHA | 不混用 scene／node／map／Case；新內容與舊存檔需相容政策 |
| 小量點更新 | 同 field、同 point generation、完整點已存在且無重建時只發 delta | 0012／0027 後舊狀態無效；新 generation 用完整快照 |
| 有限 Client 表現 | 安裝相容有限內容，一次 selector 讓 Client 自行等候、播放與收尾 | profile 的輸入、seen gate、重建與返回條件仍要正確；不能用003F當setter ACK |
| 同更新批次發布 | 同 tick 新掉落合併 `0021` rows；已提交多筆擊倒經驗按既有更新收據發布 | 死亡→移除排送→清場先後；不能把屍體可視消失當可靠回報 |
| 減少無效存檔 | 逐幀相機、字幕、碰撞狀態留在 runtime；保存已承諾的 checkpoint 和領取權利 | 拾取成功、擊倒入帳、消耗冷卻、最終任務和 Raid claim 的持久交易不能被省略 |
| 結果以收據或明確預告組裝 | 普通副本使用實際已入帳分項；主線預告與返回後提交分開 | 不把預告當已領，不重發擊倒收入；封頂時分項與總額一致 |
| 回城快照一次正確發布 | 準備回城資產資料，提交後換入正確餘額；地圖後、ready 前一次給包／裝備／冷卻 | 保留失敗可重試的敘事階段，不送新舊兩份互相衝突餘額 |
| 資源延續用時間點 | HP/SP/MP snapshot、regen 起點、絕對 deadline 跨圖承接 | 不把演出時間抹掉；未支援的 buff／projectile 不能假裝保存 |

既有擊倒經驗本來就以一次世界更新的新死亡批次提交。建議是沿用同一 receipt 與去重方式，不重新改成每隻獨立交易，也不為了減少寫入將所有 XP 延到通關、破壞現在離場保留的語意。

減負驗收只需接在既定正常旅程：記錄同一份內容的規則評估數、timer／純表現 callback、封包數與 bytes、交易數與耗時、回城快照次數。先證明玩家看到的劇情、開門、經驗、物品與重登資料相同，再報實際差異。本輪沒有量測 CPU 或網路節省比例，沒有新增故障／併發／邊界實機排程。

## 11. 交付、重驗與來源

本目錄交付：

- [lifecycle-contracts.json](lifecycle-contracts.json)：26 個 event→state→action→commit 轉移、三個結果 profile、持久／暫存分界及 12 項玩家進度。
- [outcome-projections.json](outcome-projections.json)：11 個固定設定、15 條正常路線與 Q119 敘事／獎勵計算。
- [native-proof.md](native-proof.md)、[native-evidence.json](native-evidence.json)：新角色視窗的原 BIN 讀證。
- [source-manifest.json](source-manifest.json)、[verify.py](verify.py)、[verification.json](verification.json)：固定 commit／blob／SHA、唯讀核對與 PASS 收據。
- [root-handoff-review.json](root-handoff-review.json)：對同包有限插播／seen 持久化證據的獨立 PE／指令覆核，限定於收據所固定的檔案版本。
- [latest-main-update.md](latest-main-update.md)／[latest-main-update.json](latest-main-update.json)：發布前較新 main 的付費完全復活增量；另列四份 pin，不變動原 50 份基準來源。

從 repo 根目錄重跑：

```bash
python -B kr-extra-roy/MEF-level-functional-closure-20261118/outcomes-continuity/verify.py \
  --original-bin /path/to/02-Tartaros.bin \
  --output kr-extra-roy/MEF-level-functional-closure-20261118/outcomes-continuity/verification.json
```

此命令讀取固定 commit 的原始 Git blob，與執行時 HEAD 分開；原 BIN 只按 PE 映射讀 bytes。驗證不啟動任何遊戲、Server 或 Lua。

| 來源 ID | 可直接閱覽的來源 | 使用範圍 |
|---|---|---|
| S01／S02 | [Scoped AGENTS](../../AGENTS.md)／[現行方向](../../MEF-CURRENT-DIRECTION.md) | MEF＝Server 開發，正常測試優先 |
| S03 | [功能完成追蹤](../../../governance/MEF-FUNCTIONAL-COMPLETION.md) | 保留實作及既有驗證進度 |
| S04 | [主線外部關卡](../../../design/scenario-content/STORY-SCENARIO-OVERRIDES.md) | 清場、重建、延續、經驗 |
| S05 | [一般副本](../../../design/scenario-content/PHINDOS-STAGE-ONE.md) | 選關、路線、type 2、離隊與保存 |
| S06／S07 | [掉落拾取](../../../design/scenario-content/GROUND-LOOT.md)／[復活與道具使用](../../../design/scenario-content/PHINDOS-GROCER-TRADE.md) | 掉落、交易、倒地與冷卻 |
| S08 | [單人挑戰](../../../design/scenario-content/EARLY-RAID-ENTRY.md) | type 3、待領書、失敗 CP |
| S09 | [Scenario 結果及返回](../../../governance/s00-iterations/evidence/t07-phindos-intake-20261103/post-t01/SCENARIO-RESULT-AND-RETURN-INTERFACE.md) | 結果原生接口；次視窗由本輪補閉 |
| S10／S11 | [場景與互動](../../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md)／[輸入生命週期](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md) | ready／Q／地圖／點的分層 |
| S12／S13 | [經驗發布](../../../governance/client-variants/20261108-mainline-progression/experience-publication.md)／[NPC 與進度](../../MEF-server-provided-capabilities-20261118/npc-progression/report.md) | 版本化獎勵與原子提交 |
| S14 | [普通任務 journal](../../../design/scenario-content/ORDINARY-QUEST-OBJECTIVE-JOURNAL.md) | Accepted／Ready／目標計數 |
| S15／S16 | [正常單人旅程](../../../design/scenario-content/ALSMEER-SINGLE-PLAYER-ACCEPTANCE.md)／[村莊回廣場](../../../design/scenario-content/VILLAGE-SQUARE-RETURN.md) | 正常路線、重登、回村資產 |
| S17 | [共用事件引擎](../../../design/runtime-content/STORY-EVENT-ENGINE-CANDIDATE.md) | 規劃與敘事 Commit 邊界 |
| S18／S19 | [交付 profile](../../MEF-server-provided-capabilities-20261118/delivery-profiles/report.md)／[world 分工](../../MEF-server-provided-capabilities-20261118/world-offload/report.md) | 有限內容的已證能力；新 handoff 由根報告補充 |
| S20／S22 | [技能熟練度](../../../design/runtime-content/SKILL-PRACTICE-PROTOCOL.md)／[原生入口與結果證據](../../../governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md) | 後續欄位與結算 consumer |

所有 C／B 編號的精確路徑、commit、blob 與 SHA 都在來源清單中；C 為既有設定，B 為原有 decompilation 導航。沒有把這份分析的結論回寫成既有來源，也沒有修改正式進度、原 scenario、schema 或原件。
