# 生怪、移動、戰鬥與清波：以 Server 提供的 MEF 為功能中心

日期：2026-11-18。分支：`extra/roy1`。來源基線：`60c1c1a5dc7a73902d9dbb50361d5148e8b30058`。本文是本輪 world／combat 分題；不更動 T08、T09、T10、T12、T13 的 owner、RR 或正式驗收。

## 1. 結論：MEF 能編排戰鬥；Client 已有實體與動作執行器，缺口集中在可用接口

**生怪、巡邏、索敵、選招、命中規則、血量階段及清波條件，全部納入 Server 提供的 MEF 開發範圍。** 應先讓內容定義承擔規則，再按已有接口決定在哪裡執行。現有 Server 自訂關卡已經具備其中多項；本輪不能把它們改列為「都還沒做」。本輪新增的是 Client 可承接工作的證據整理與接口契約，沒有執行或修改 Server、Client、Lua。[S1]

本題最重要的正向結果是：`lb.CreateObjectEx` 配置的普通怪確實是 **CMonster**，進入普通 world 索引；同一索引的更新會走到 CMonster 的位置步進、朝向更新、動畫與狀態執行器。它不只是用怪物模型扮演的 Q 演出角色。因此，**本地生成與既有 native 動作執行能力應保留在可用能力清單**。缺少本地 EntityId 回傳，會限制後續指名、跨端對帳及結果觀察，但不會抹掉已證的建立效果。[N1][S2][S3]

同時，這些 native 執行器尚不能直接等同「MEF 已可在普通副本獨立完成一場戰鬥」。本輪沿具體鏈確認：

- 普通移動可以由 Client 按既有移動狀態逐步執行；原專案還已有固定路段的人測結果。這可供減少高頻座標下發的整合使用，**不是這次才新出現的節省**。[N1][S1][S2]
- `attach != 0` 掛接的是當前控制器。Single／Tutorial 的入口只管理三個控制槽；Formation 接 SubAI 後，已選定攻擊執行器仍拒絕 model > 9。不能把第六參數當成「啟動敵人 AI」。[N1][S2]
- 普通技能動作 `000D → 4C8A90 → state 13 → motion/rate` 是動作執行鏈。該 state 的 enter 只寫一個計數欄位，tick 是返回 stub；這條鏈沒有給出命中或扣血算法。[N1]
- 真正的 HP snapshot writer、死亡 FSM、淡出、world erase 是分開的 native 路線。它們可作 MEF 執行結果的現有輸出接口，但不能把任何一個畫面效果冒充「Lua 收到這隻怪本次生命已死亡」。[S4][S5]

因此，實作策略是：**已有內容規則繼續放在 MEF；已有 native 動作讓 Client 執行；普通世界的可指名操作、生命事件觀察與跨端結果提交，列成有明確輸入輸出的 adapter 需求。** 若選擇由 Server 的 MEF 執行器先計算戰鬥規則，再經既有封包 adapter 驅動 Client，也屬 MEF 功能完成路徑。這種分工可以減少逐關硬編碼；能否減少 Server CPU，還要看是否移出逐怪判斷、改成事件驅動或減少實際更新量，不能由「換成 MEF」三個字推得。

## 2. 必須先承認的現有成果

下表來自固定 Git 的專案完成追蹤及規格；本輪沒有重跑 Server 或重做人測。「已有」表示文件記錄的實作狀態，測試限制仍逐項保留。[S1][S2][S7][S8][S9]

| 玩家功能 | 目前已有的 MEF／Server 基礎 | 仍缺什麼，與本輪的關係 |
|---|---|---|
| 指定這張圖有哪些怪、分幾波出現 | Scenario／MonsterBehavior 定義、逐出生 profile、順序／定時／區域增援；部分正常流程與增援已有實機記錄 | 正式關卡配置與幾何仍需整理；Client 本地生成後的指名／同步另外驗收 |
| 怪物發現玩家、追上來、離太遠回家 | 個別 profile、索敵與追擊／回位；v93 記錄追擊及回位人測 | 多目標仇恨、特殊 Boss、更多物種動作仍待擴充；把決策搬到 Client 需可用輸入與動作接口 |
| 怪物依路線巡邏、遇牆繞路 | 1 至 16 個巡邏點、靜態地形檢查、追擊／回位、搜尋預算及恢復巡邏規則 | PT-01 至 PT-03 待實機；現有規格由 Server 決定路線，沒有普通 Client 巡邏決策已獨立執行的證明 |
| 一次指定終點，怪物自己走完該段 | `LocalClientRouteComparison` 已有單次目標組；v92 記錄停止彈跳、速度可接受 | 尚未併入戰鬥 AI；Server 排程停止／待機不等於 Client 回報抵達 |
| 打到某一波全倒下才出下一波 | `WaveCleared` 已按指定波次的 Server HP 鎖存旗標；未生成的波次不會先清除 | 不是泛稱沒有清波系統；缺的是把 Client 本地觀察接成同一實例、同一波次的可靠來源 |
| 頭目血量到門檻召援軍 | `WaveHealthReached` 以該波現 HP 總和／最大 HP 總和判斷，一次鎖存 | 該規則可繼續由 MEF 定義；Client Lua 任意世界 HP getter 未證，不能直接把 HUD 讀值當接口 |
| 攻擊、掉落、結算、回村 | 完成追蹤記錄一般副本正常工程流程及部分人測；共用戰鬥和資產接線已有基礎 | 指定 Client 的完整實機與新功能驗收仍要分列；本輪只處理 world／combat 接口，獎勵與保存由同輪整合分題列明 |

現有規格上的 `NOT_NATIVE_MEF` 是格式來源標記。它不應被解讀為「不算 MEF 功能開發」或「一定要等官方檔案才能做」。使用者已明確選定自訂 MEF 的功能目標。

## 3. 各功能應由 MEF 承擔什麼

`capability-contracts.json` 有相同分工的機讀版本。以下「Client 既有」均是有限靜態能力，不表示本輪已在遊戲中跑過新腳本。

| 功能 | MEF 應包含的內容 | Client 既有執行／觀察能力 | 接續缺口與實際可能減少的工作 |
|---|---|---|---|
| 生怪 | 模型、位置、時間、波次、出生 profile、可重入政策 | `lb.CreateObject[Ex]` 真正配置 world actor；Q 另有可指名演出 slot | 本地出怪可省相應生成指令與逐個 spawn dispatch，前提是入口和生成驗收成立。共享戰鬥需要本地結果／ID 配對；純擺設不必先解決多人對帳 |
| 身分與生命周期 | 自訂邏輯 actor key、所屬波次、出生次數／世代 | world `u16 EntityId`、Q slot、model ID、relation key 各有不同用途 | `CreateObjectEx` 未推新 ID，計數器與 typed ID 不能猜。需生成結果接口或沿用 Server 分配 ID 的現有生成 adapter |
| 普通移動 | 路點、移速規則、等待、追擊／回位策略 | 普通 CMonster 由 world update 消費移動狀態與位置增量；現有固定終點比較可復用 | 優先把固定路段整合進現有 AI；補足中止、校正與抵達判斷。減少的是路段內反覆座標下發，不是把本已在 Client 的動畫重新計為省量 |
| AI 決策 | 何時找誰、何時放哪招、何時退回、階段變化 | 已知 SubAI 為特定隊伍／模型控制；ordinary CMonster 的本地自主 hostile producer 未由所選入口證成 | 現有 Server 的 MonsterBehavior 是可復用執行器。若要再移到 Client，需取得位置／狀態輸入、可操作 handle 及動作輸出；不能把 attach 當 AI 開關 |
| 技能動作 | 招式選擇、時機、段數、取消與冷卻規則 | `000D` 對 world actor 套 action／rate；Client 播放 native 動作 | 可由 MEF 驅動既有動作 adapter；技能動作播放不自動完成命中和 HP 計算 |
| 命中與傷害 | 範圍、目標篩選、傷害與資源公式、命中時點、牆面／狀態規則 | 原件有結果消費與位置可用性檢查；所選技能／移動鏈沒有給出完整傷害公式或普通 Lua 判定 API | 可以先在 Server 的 MEF 執行器定義並執行自訂公式，復用共用戰鬥 adapter。Client 下放須補輸入／輸出接橋；不能用移動碰撞或跳字代替傷害算法 |
| HP／SP／MP | 初值、消耗、回復、血量階段條件 | `0034` 寫實際 max/current 欄位，HUD／native AI 會讀；`0000` 是另一比例通道 | 新增的減負來自下放規則或減少觀察頻率，不是 native 顯示。普通 Lua 對任意 actor 的 typed HP 讀取尚未證成 |
| 死亡 | 哪些條件判敗、何時進死亡、屍體與後續效果 | `000C → FSM state3 → CDeadState` 有真實 enter/update | MEF 可定義死亡政策；接回普通 Lua 需要同一 actor 生命事件。重複 state3 不是第二次擊殺 |
| 清波／下一波 | 成員集合、何時封閉名單、哪些終止原因算完成、觸發哪個後續規則 | Server 自訂 MEF 已有 `WaveCleared`；普通 Client 世界事件到 Lua 的可靠接橋未閉合 | 先復用現有規則，不重寫清場系統；要省掉 Server 每次輪詢，應讓狀態變更直接驅動同一規則。純 Client 清波需要可靠 observer |
| 移除／換圖清理 | 正常死亡後清除、取消、離圖、重生、清理範圍 | `001A → world erase`；Tutorial 固定低 byte 0 ID 刪除有窄接口；Q 有批次清理 | 移除不是死亡；控制器清理時序不同。不能把 `Tutorial.DeleteObject` 當所有 CMonster 的刪除器 |
| Q 演出 | 固定角色走位、動畫、表情、鏡頭、等待與收尾 | Q actors 是 CEventActor，具腳本 slot 與既有動作 consumer | 可直接下放演出安排；普通怪的血量、敵群和獎勵不會因演出結束而自動成立 |
| Tutorial 互動 | 提示、位置／輸入條件、教學段落推進 | 有真實 checkpoint／UI progress producer 及 Lua getter；`004C` 的完成旗標限適用 Tutorial 路徑 | 可復用相同適用情境；要用於普通副本，需要明確 context／事件橋接，不能換名稱便當成通用死亡 |

## 4. 正向 native 閉合：CMonster 不只會顯示，還會消費移動狀態

本輪重新核對以下普通 world 執行鏈，保留指令原件及 PE raw 映射。原件 BIN SHA-256 為 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。[N1]

| 階段 | 原件錨點 | 已能確認的作用 |
|---|---|---|
| 本地實體 | `lb.CreateObjectEx → 4A0F70`；沿用 I01 完整範圍 | model 10..10000 走 CMonster；設定世界 ID、model、位置、方向，加入 world tree |
| 同一 owner | frame `491CAF → 40F060`，回 `FAB130`；`491CB6 → 4E0060` | 這條選定 frame 分支使用同一 world owner；其前置 gate 仍須成立，不宣稱所有頁面每次都進入 |
| 世界遍歷 | `4E00C1 → 4E13F0`；`4E1400..4E1408` | node+10 取 actor，派送 actor `v+20` |
| 怪物步進 | `C0C9DC+20 → 4D1AE0 → 4C8580` | CMonster 使用普通 actor 的更新；`4C85AD → 4CA890` 消費位置／移動狀態 |
| 方向式步進 | `4CA890` 的已選定完整 body | 在非指定路段分支讀 `WORD actor+E2 bit8000`、方向 `actor+E4`，用 native 方向表與速度／設定值形成步進量；其餘分支可按既有目標與剩餘計數推進 |
| 位置可用性 gate | `v+54=4CABE0`；`4CAC78 → 82CDF0` | 用候選 XY 查 `FAB1D0` 所指物件；有效時才呼 `v+44`。`82CDF0` 要求兩次既有 membership probe 均為 0 才返回 true |
| 寫入位置 | `v+44=4C8B90 → 4CAB80` | 更新 actor A0/A4 及 transform 相關狀態；不是只在畫面上挪一張圖片 |
| 動作／狀態 | `CMonster v+24=4D1AF0 → 4C87D0` | native 更新模型／效果，最後對 actor+158 的 current state 派 `v+8`；Move state 的選定 consumer 為 `4CB4B0` |

移動旗標的具體外部 writer 復用 `000B/4AFE60` 的 I09 完整證據；沒有藉此推論所有行走都會自動切 state2，或每次都必須另發 state2。[S3]

### 能採用的開發推論

高階移動狀態已能由 Client 續行；**在已成立的場景、資源與控制上下文下，Server／MEF 不必為單段連續移動的每一個畫格提供新座標**。這個推論也有專案既有固定路段比較支持。可先把該路段 adapter 接到現有巡邏／回位規則，再測中止、碰撞、轉向和誤差校正。[S2][S9]

這不是宣告普通怪能自己選路，也不是抵達 ACK。`82CDF0` 的成功結果只用在位置更新 gate；本輪未把它解讀為攻擊範圍、視線命中、傷害或某敵群完成。Client 原本就執行這些步進和動畫，效能比較應針對「此次實際少發了哪些座標、少跑了哪些 Server 判斷」，不能重複計功。

## 5. 直接追到戰鬥邊界：動作、傷害、血量、死亡各是不同資料流

### 5.1 可掛接，不等於普通怪的決策器已接通

`CreateObjectEx` 第六參數非零時，對 `[FBA7A4]` 呼 `v+4` 與 `v+10`。Single 與 Tutorial 的這兩槽分別是 `545040`、`5F5D10`；`545040` 只在三個 stride12 控制槽找空位，保存 actor pointer 與相關控制記錄。這是可供既有控制器持有物件的能力。[N1][S2]

Formation 的既有掛接鏈可把記錄交到 CAIControl，但 `549C60` 的已選定 native action 在 `549CEE` 讀 model low WORD，`549CFB/549CFE` 對 >9 跳過動作主體。model1036 不通過這條路。這個結論限該完整入口及所選定分支，不擴成全 Client 沒有敵方 AI。[N1][S2]

MEF 的 AI 規則仍應先定義。現有 MonsterBehavior 可以執行逐出生 profile；若目標是 Client 自主敵方 AI，下一個介面必須同時解決「可讀的目標／位置／狀態」及「可對特定普通怪下動作」。本輪沒有以原版 AI 所在主機未知，禁止自訂 MEF 行為；也沒有把原版執行器的模型限制自行 patch 掉。

### 5.2 普通技能動作的真實終點

選定 `000D` handler `4B01C0` 解析 9-byte rows，按 world ID 查 actor，再把方向與 action／rate 交 `4C8A90`。後者於 `4C8B67..4C8B69` 切 state13，於 `4C8B70..4C8B7E` 呼 actor `v+68` 套動作。CActor constructor 已把 state13 安裝成 CSkillState（vptr `C078EC`）。[N1]

本輪繼續追該 state 的真正槽：

- enter `C078EC+4 → 4CBB00`：讀 state+4 的 actor，只寫 `actor+418 = 300`，然後返回。
- update `C078EC+8 → 476430`：原件為 `ret 4`。
- actor 的 `v+68=4C8DA0` 是既有 motion／rate consumer，完整表現契約復用 world-npc。

因此，**這條 CSkillState 路線可支持技能動作表現，不能從它宣稱本地完成碰撞命中、扣 HP、判死或通知 Lua**。300 的單位與業務名稱沒有在此擴寫成 cooldown 毫秒。

必要的有限新搜尋：對整個 PE `.text` raw 範圍做 E8/E9 rel32 exact-target 掃描，`4C8A90` 只得到 `4B031A`；本輪從完整 `4B01C0` 入口核對該位置是實際 call。這只涵蓋直接相對呼叫，不涵蓋函式指標、其他包裝、外部模組或新腳本提供的能力，故不能推成全域唯一 producer。[N1]

### 5.3 真實 HP writer 與結果顯示

`0034/4B3090` 的怪物分支要求 actor+39C=1、mode2、CMonster cast 成功，才在 `4B313C` 寫 maxHP+3BC、`4B3142` 寫 currentHP+3C8。角色 HP／SP／MP 有另外的 roster guards。這是具體 snapshot 寫入，不是 Lua getter，也不是本地傷害計算公式。[S4]

`000E` 的結果列處理跳字、視覺與部分 native AI 回饋；它的顯示數值不能拿來代替 `0034` 的 HP 欄位。HUD 也可能因死亡 state 將顯示條清成零而沒有寫 actor HP。相反地，`0034` 寫 HP=0 本身不會在該 handler 自動切死亡 state。[S4]

這些證據已足以規劃 **MEF 規則計算 → 共用戰鬥狀態 → 現有 HP／動作／結果 adapter**。現有 Server 的命中、冷卻、HP 與部分投射物等基礎應復用；要把同一判定移到 Client，才需要額外的 Lua／native observer 與 action 接口。設計自訂公式不須等待官方傷害公式；公式來源及驗收必須明示為本專案規則。

### 5.4 死亡、淡出、刪除與清波

| 路線 | 可確定作用 | 清波時要保留的差別 |
|---|---|---|
| `000C → 4B0130 → actor+F0 v+8 → 4CA060 → state3` | CDeadState 進入／更新 | 同 state 再送會重新 enter；不能每次 enter 都累計一殺 |
| `4CB590 / 4CB710` | 死亡 motion／效果與淡出更新 | 淡出沒有直接等同從 world tree 移除 |
| `001A → 4B28D0 → 4DFBC0` | typed 前置、部分控制槽清理、actor cleanup／destructor／tree erase | 移除可由換圖、取消等原因造成，不一定是擊殺 |
| `Tutorial.DeleteObject(n)` | 目標 key 是 `(n & 0xff) << 8` | 不是任意 u16 ID；普通 lowbyte1 CMonster 不能用同一接口直接刪；控制器前置清理亦不同 |
| `WaveCleared` 既有 Server MEF 規則 | 指定波已生成且其怪物 Server HP 全零才鎖存 | 這個現有規則可直接復用；不要改成數場上模型、等屍體消失或讀 UI 旗標 |

上表沿用已閉合的完整證據，本輪只以原 BIN 重核固定範圍 hash，不重做一份死亡或刪除研究。[S3][S4][S5][S7]

## 6. 普通敵群結果到 Lua：有限範圍內仍缺真正接橋

這個缺口不是「Server 負責所以 MEF 不做」，而是**要在 Client 執行這條 MEF 規則時，目前已證 API 沒有提供它需要的輸入**。若規則在現有 Server MEF 執行器執行，已有戰鬥狀態可使用；不必等 Client observer 才能完成關卡功能。[S1][S7]

| 已檢查候選 | 具體能取得什麼 | 為何未補足普通清波輸入 |
|---|---|---|
| `lb.GetObjectCount` | 既有分析沒有形成有效世界物件總數的返回契約 | 不能藉名稱造出 alive count，更無 wave／generation |
| `CreateObjectEx` 回值 | converter 沒有新推入 actor ID | 外層返回值個數不等於成功碼或新 ID |
| `Tutorial.GetTutorialState` | current controller+134，已閉合鍵位選擇確認 writer | 不是普通怪死亡 |
| `Tutorial.GetControlStatus` | Tutorial 控制旗標；另有位置／輸入 checkpoint producer | 任意旗標改名不會使普通戰鬥結果自然寫入 |
| `Tutorial.IsScenarioEnded`／004C | 適用 Tutorial route 的完成旗標 | 普通 Mission／Scenario 路由不能直接當同一通知 |
| 004E／`OnYes` | 選定 page 的 UI 確認 | 普通 page5／7 不呼同一 `OnYes`；無 actor、生命期或 wave payload |
| Scenario `000E → 54A8F0 → 54AA60` | CAIControl 三槽的目標記錄與原生 actor pointer reader | 會覆寫的目標記錄，不是死亡事件列；已核正常名稱表中沒有把這些函式直接註冊為 Lua target |
| `000D → 501650 → C2S00DF` | 特定任務事件 selector 與 event code | 沒有 world ID／生命期／wave，不是通用死亡或清群 ACK |
| `Q.IsAllObjectsStopped`／Q 完成 | 全 Q 索引的 actor 移動位元皆已停止；空索引也回 1 | Q slot 屬 CEventActor 索引；不是 ordinary world actor 存活狀態 |

本表復用既有普通名稱／事件分析，**沒有重新掃一遍 121 names 作新增成果**。其中「不是直接註冊 target」的範圍僅限固定正常 registrar 集；不排除未辨識 wrapper、計算式 dispatch、外部模組或日後加入的適配器。[S3][S4][S6]

下一個有價值的證據應是：某可達正常 binding／callback 的 producer，帶著同一 world actor 身分與結果，實際抵達普通場景中存活的 Lua 任務；或明確選擇新的適配器契約。再看一次同名函式、重跑舊 call census、找官方 `.mef` 檔名，均不能補上這條邊。

## 7. 三種可落地的執行 profile

| Profile | 現在適合承擔 | 所需額外工作 | 對 Server 的減負性質 |
|---|---|---|---|
| Server 提供、Client 執行的演出／局部內容 | Q slot、走位、動畫、鏡頭、對話；已載入且有 context 時的 lb 本地 actor | 依同輪 delivery profile 接入入口與壽命；world actor 後續操作仍須 handle | 減少逐步演出／擺設控制；本地 spawn 可在驗收後停發對應生成指令 |
| 現有 Server MEF 執行器＋既有 Client 動作 adapter | SpawnGroup、逐怪 profile、AI 規則、HP 階段、WaveCleared、巡邏／回位 | 復用現有內容格式和 battle 接線；把固定路段接到 AI，按需求增加 typed 條件 | 已減少逐關硬編碼；經事件驅動、快取或路段下發後才可能再減 CPU／封包 |
| Client 自主普通戰鬥 MEF | 目標為本地生怪、決策、命中、生命事件、清波及階段切換 | 目前需可靠 world handle、狀態讀取、動作與 HP 變更接口、ordinary runner、終局／同步提交；所選舊接口不足以直接完成 | 成功時可移出逐怪 tick 和高頻指令；目前屬明確接口開發及驗收項，未完成部署 |

Tutorial 是另一個具體可用上下文：已閉合位置／輸入／UI 到 Lua 的 progress，可用來設計教學類內容；普通副本不能只換 page 或欄位名稱套用。

### 7.1 提議的接橋資料，不是假造現有 API

機讀契約使用以下概念資料，**不宣稱這些名稱已是 Lua API 或既有 opcode**：

1. 出生請求帶內容版本、run、wave、邏輯 actor key 及出生世代。
2. 出生套用結果回傳成功／失敗與可用 handle。跨端時再帶目前 u16 world ID；不依本地 counter 推算。
3. 生命結果帶同一 run、actor key、generation、單調事件識別與終止原因。
4. 波次名單明確封閉後，以成員生命周期狀態計算清波；未生成／出生失敗不視為擊殺，重送結果不重算，同 ID 的新一生不吃前一生的死亡。
5. MEF 規則可在取得同一事件後設定旗標、生成援軍或要求後續流程。跨端共享及持久化只提交必要結果，不必傳每個演出或每一畫格。

其中第 4 項是為新 observer 提供的審核模型；現有 `WaveCleared` 的 Server HP 判定已存在，不以此模型聲稱修改其運作。若日後另把「腳本清除」算作過關，應是明寫於內容的政策，預設不能由 erase 自動猜成擊殺。

### 7.2 最先整合的閉環

本節是未來整合驗收建議；本輪沒有新增、執行或擴大既定測試排程。

先使用現有 Server MEF 的出生／波次／血量規則，復用普通 CMonster 的 native 動作。把一段已驗證的固定路段接到單一巡邏怪，再比較原路線與路段下發；記錄移動指令數、位置校正次數、Server 更新時間及抵達／中止結果。只有對應控制停止後 Client 仍完成且觀察可對帳，才把那項工作從 Server 排程中移除。

本地生成另外驗收：在已證入口、有效資源與 context 中，對某怪停發對應 `0007`，確認實體出現；接著確認動作／HP／移除仍指向同一物件。對不需要戰鬥身分的純擺設，第一步即可驗收其較小能力範圍，不能讓後面共享戰鬥的問題阻塞它。

## 8. 本分題完成度與缺項

| 層級 | 本輪已分析完成 | 尚未交付／缺少 |
|---|---|---|
| P0：分工與既有能力 | 既有 Server MEF 功能復核；CMonster 本地生成、普通 native 位置步進／狀態 consumer、技能動作與 HP／死亡／移除差異；普通 observer 候選的有限結論 | 新 Client world-handle／結果 adapter 尚未實作；未跑新腳本或實機，不稱獨立 Client 戰鬥完成 |
| P1：可採用的整合 | 現有固定路段接 AI／巡邏的最小路徑；明確出生／生命／清波契約；現有 WaveCleared／WaveHealthReached 的復用位置 | 路段抵達／取消／校正與多人重入驗收；現有文件所列 PT、血量階段、選招等實機缺項仍保留 |
| P2：進一步減負 | 明確哪些是原有 Client 成本、哪些才是新增減負；給 Client 自主普通戰鬥的必要接口及量測方向 | 未量測 CPU 百分比或網路節省；普通 hostile producer、通用 Lua HP／死亡觀察與 runner 背景接合未由這批現有入口證成 |

這裡的「分析完成」是把可用能力、已實作基礎、必要接口及驗收方式說清楚；不是把尚未寫入的 adapter 或尚未進遊戲的功能改標成完成。

## 9. 證據與重跑

- [native-evidence.json](native-evidence.json)：22 個由正確入口解碼的選定 code windows，共 4,765 bytes；11 個具體 vtable slots；8 個前稿範圍只留 pins 與 hash；2 個必要 exact-target 直接呼叫候選集合。
- [native-evidence.asm](native-evidence.asm)：同一選定原件範圍的可讀組譯。沒有公開原 BIN／STP 或完整 decoded member。
- [source-manifest.json](source-manifest.json)：固定 commit、Git blob、內容 SHA-256、長度及用途；bulk C 只作導航。
- [capability-contracts.json](capability-contracts.json)：能力、執行位置、現有基礎、adapter 缺口、收益及驗收。
- [verify_evidence.py](verify_evidence.py)／[verification-result.json](verification-result.json)：唯讀重核原件、固定 Git 來源、選定邊界／bytes／vtable／直接 call 候選，以及提議 observer 的有限案例。不是執行遊戲的測試。

```bash
python -B kr-extra-roy/MEF-server-provided-capabilities-20261118/world-offload/verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --repo /path/to/ttr_anal_multi
```

本文的證據代號：

| 代號 | 固定來源 |
|---|---|
| N1 | 本包 native-evidence.json／asm；原件 SHA 如上 |
| S1 | `governance/MEF-FUNCTIONAL-COMPLETION.md` |
| S2 | `governance/s00-iterations/S00-20261113-MONSTER-LOCAL-CONTROLLER-BOUNDARY.md` |
| S3 | `MEF-capabilities-20261116/world-npc`；`MEF-world-integration-20261115/identity` |
| S4 | `MEF-P0-P1-master-continuation-20261117/world-lua` |
| S5 | `MEF-world-identity-scene-interaction-20261117/WORLD-IDENTITY-EVENTS.md` |
| S6 | `MEF-transition-actor-event-20261117/WORLD-EVENTS.md`；既有 world/control-flow、Tutorial 及事件報告 |
| S7 | `design/scenario-content/WAVE-CLEAR-SIGNALS.md` |
| S8 | `design/scenario-content/WAVE-HEALTH-SIGNALS.md` |
| S9 | `design/scenario-content/MONSTER-PATROLS.md` |

S3–S6 的根為 `kr-extra-roy/`；每個實際引用檔案的完整路徑、不可變 blob 與 SHA 均在 source-manifest。舊稿的官方復原／責任分派文字只作歷史，本文依使用者最新目標重新裁定用途；原件欄位、型別和適用條件仍保留。
