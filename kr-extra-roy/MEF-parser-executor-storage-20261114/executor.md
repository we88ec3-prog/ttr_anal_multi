# KR Client 腳本 executor 與可實作 API 契約

2026-11-14。範圍：協助使用者判定「要讓重建 `.mef` 的規則在 Client 生效，哪些 parser／executor 已有，哪些必須另行設計」。工作基準為 `extra/roy1`，原件唯讀；研究階段唯讀原件，未改 Client、Server 或原始資源，未執行 Lua／遊戲；本附件由主稿整合並依使用者授權發布。本稿是有界靜態結論，不是 T01 FULL-PASS 或遊玩驗收。

## 1. 結論

**原 Client 已有可讀 Lua 文字／相容 bytecode、執行 SEQ、驅動協程並呼叫遊戲功能的執行器。這足以支持「重建有限場景演出」的正向契約；目前仍不能稱為已找到原生 MEF 執行器，亦不能把所有遊戲規則直接塞進一份 SEQ。**

新補到的重要相容條件是 **SEQ 會在兩個不同的 Lua state 先後執行**。前置 state 的 `Register(scene)` 會立刻呼叫 scene 函式，收集物件／動畫／音樂依賴；許多演出函式在此只綁到空 callback。正式 state 才用 `coroutine.create` 註冊，之後由場景管理更新驅動。正式 state 具有 Q、lb、Tutorial，不表示前置 state 也具有這些完整 API。

所以，新增腳本至少必須同時滿足：可以被既有 loader 選到；內容可解析；前置階段有限完成且依賴收集完整；正式階段在有效 context 中執行；所等待的事件確實存在。檔案已送到磁碟只完成其中第一層的一部分。

另一項校正：`lb.GetObjectCount` 的 wrapper 在 EAX 回傳 `1`，表示 **一個 Lua 回傳槽位**，不是物件數字 1。已核 target 沒有遍歷物件或計數，也沒有把有效 count 推回 Lua stack；不能拿它當清怪／清波判定。

## 2. 原件與證據

| 來源 | 固定身分／用途 |
|---|---|
| `project_sources/02-Tartaros.bin` | SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；12,472,320B。新補原生證據均來自此檔 |
| `project_sources/06-Event.stp` | SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| `Event/qbase.lua` | 解碼 SHA-256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`；STP raw `0xA20810`、stored size 11,836；本段重核 76 個 prototype、906 個 instruction words 與原件逐字一致 |
| `native-windows.json` | 本段新增原生指令／字串視窗，含 VA、PE section 對應 raw offset、長度、SHA-256、完整 hex |
| `prepass-bindings.json` | 前置 72 個空全域、每次載入的 6 個有效 callback（5 個覆蓋空版本、PlayMusic 新增），以及局部 Q 表方法的精確名稱與位址 |
| `qbase-prototypes-evidence.json` | 固定原件／既有解碼 JSON 身分，保存本段引用的 prototype 指令與來源 |

PE `.text` 為 VA `0x401000`→raw `0x400`；`.rdata` 為 VA `0xBD2000`→raw `0x7D0600`；`.data` 為 VA `0xD61000`→raw `0x95E800`。資料字串按各自 section 換算；尤其 `0xD6ADA0` 是 `.data` 的 `GetObjectCount`，不能套用文字節或唯讀資料節的差值。

既有能力矩陣主要復用 2026-11-09 的 `scenario-controls.md`、`town-npc.md`、`shop-services.md`、`shop-asset-sync.md`，保留其原件 pin、版本及未驗收限制。新補追查集中在前置 Register、正式 coroutine 更新和 Lua C 回傳 ABI；沒有重跑既有 MEF 否定搜尋。

## 3. 兩個 state 與同一條 SEQ 的兩次執行

| 階段 | state／wrapper 的精確來源 | 用途與限制 |
|---|---|---|
| 前置資源收集 | `55C69E → 6F74B0` 建新 state，`55C6B3` 存至 `FE1EEC`；12B wrapper 存於 `FE1EF0`，其 `+0` 指向該 state | 每次 `55D6A0` 清收集容器與音樂字串，重綁六個 callback，再 `55D7C2 → 6F4A50` 執行 SEQ。不是一般演出 VM 的複製品 |
| 正式場景／共用 VM | `48D76B` 取 `&FDF3C8`，`48D770` 取 manager `&FB73C0`，經 `560600`；`56060B` 將 wrapper 存到 manager `+0` | `56060D → 565E40` 在同 wrapper 註冊 Q；`560796/7A2/7AE/7BA` 依序載 `Coroutine.lua`、`Boot.lua`、`Logic.lua`、`Event/qbase.lua` |
| lb namespace | `4A09AB` 傳 `&FDF3C8 → 4A14D0`，`4A14E2` 存 `FE1774` | 與正式 scene 相同 state；不是另外一個 MEF VM |
| Tutorial namespace | `48D7D4` 取同 `&FDF3C8`，`48D7D9` 取 `&FC0F84`，`48D7DE → 4A88E0` | namespace 註冊可見，不等於任何模式都提供相同教學 controller、事件與資料 |

上述共用 state 的上游鏈由本輪 [parser.md](parser.md) §6 覆核，原件窗存於該目錄 `native-windows.json` 的 parser group；本稿新增證據覆核前置 state、綁定、呼叫，以及正式 tick 的使用者。`FB73F0` 是另一個初始化物件，**不能誤寫成 Lua state**。Lua coroutine 有自己的 execution stack／thread，這裡「共用 state」指同一 global VM／environment 的 wrapper 關係，沒有把 coroutine stack 說成主 stack。

SEQ 的主啟動路徑先於 `561AF3 → 55D6A0` 收集；返回的是 collector `+8` 的容器指標，`561AFA` 存 manager `+70`。`561B43..561B88` 遍歷該結果，從記錄取 WORD 並交 `4A8680` 建立後續需求。稍後 `561C7A` 取 manager `+0` 的正式 wrapper，`561C7D → 6F4A50` 再讀同一路徑。另一個 `565720` 場景路徑也有先 `5659BB → 55D6A0`、再 `5659D9 → 6F4A50` 的雙載入；復用 E16 已核字串來源。

### 3.1 前置初始化實際只提供哪些函式

`55C6DB → 55D7E0` 在新 state 逐項建立 72 個全域。所有 callback 皆為 `8DC2F0`，三個原始位元組 `33 C0 C3`：`xor eax,eax; ret`，即零個 Lua 回傳值，不做實際等待或演出。完整 72 名稱另存 JSON，包含：

- `wait`、`yield`、各 `WaitFor*`。
- 對話、相機、音效、色彩、載入、換圖等 qbase 風格的全域 wrapper 名。
- `CreateObject`、`WalkObject`、`WarpObject`、`AniObject`、`Register` 的預設空版本。
- `Phase1..4`、`RevPhase1..4`。

尾端 `55E2BC → 55E410` 另建名為 `Q` 的 table，加入 `Rebind`；`55E2C5 → 55E4F0` 加入 `Q.DeleteAllObject`。後者的 target `5F5D10` 是單一 `ret`；其 binding 同樣不能由 EAX=1 推出有意義的 Lua 數值。這不是正式 Q API 全表，也沒有此初始化呼叫 lb/Tutorial 註冊或標準庫開啟函式。

**這個缺省集合的範圍限定為已核初始化與每次重新註冊；state 會保留，腳本本身仍可能修改全域。** 因此「本段未註冊 lb」不是對所有可能腳本修改後狀態的永久不存在宣告。

### 3.2 每次前置載入的六個有效 callback

其中 CreateObject、AniObject、WalkObject、WarpObject、Register 覆蓋初始化的空版本；PlayMusic 不在那 72 個空全域內，是這一步另外註冊。

| 全域名 | callback | 原生效果 |
|---|---:|---|
| `CreateObject` | `55C940` | 解析九個參數；`55CC87..55CC9B` 把三個相關值送 `55C810`。以槽位 key 建／找 `0x14` bytes 的資源記錄，保存模型 WORD 與動作集合；這裡不建 CEventActor／CMonster |
| `AniObject` | `55CCE0` | 以物件槽位查 collector，經 `55CE84/55CE8F` 將動作加入集合；不存在該槽位便略過 |
| `WalkObject` | `55CED0` | 讀七個參數；在指定參數條件成立時為既有槽位加入需要的動作；`55D188..55D191` 包含負值選預設動作 4 的分支。沒有讓世界 actor 行走 |
| `WarpObject` | `55D220` | 讀七個參數，查同 collector，經 `55D50E/55D519` 加入動作；沒有移動世界 actor |
| `Register` | `55D560` | **立即 protected-call 傳入的 Lua 函式**，見下節；不是只把 function 放入清單 |
| `PlayMusic` | `55D5E0` | 將可轉為字串的參數複製到 collector 的音樂欄 `FE1F04`；`55D684 → 402A70`。此階段沒有播放音樂 |

`55C810` 按第一個物件 key 的低 WORD 查樹；新記錄配置 `0x14` bytes，`55C520` 把傳入的模型值低 WORD 寫 record `+0`，在 record `+4` 初始化動作容器。`55C913/55C91D` 插入動作。這些結構、尺寸與 consumer 支持「資源收集」，不能與正式 `Q.CreateObject` 的 `0x438` bytes 事件 actor 混為一談。

### 3.3 Register 確實執行 scene，錯誤不會變成前置失敗回傳

`55D56B..55D57F` 取 Lua stack 最上方的引數，要求 type=6 function。`55D590` 指定 callback `6F5A50`，`55D597` 設要求結果數為 0，`55D59F → 6FE770` 進 protected call。`6F5A50 → 6FE550` 的 Lua 執行鏈由本輪 parser 原件窗閉合；E15 提供 protected-call 骨架，未曾閉合 execution thunk 的精確語意。

如 scene 執行回報錯誤，`55D5AB..55D5D2` 處理／移除錯誤槽；`55D5D7` EAX=0 表示此 C callback 不回 Lua 結果。它沒有再次拋出錯誤。外層 `55D6A0` 在 `55D7C2` 之後，直接把先前 collector 指標裝回 EAX 並返回，沒有傳遞 `6F4A50` 的成功／失敗結果。

因此不能把「前置函式有返回」當成「全部依賴收集完成」。若 scene 在中途呼叫缺少的 `lb.DoFile` 或不存在的 Q 方法，前置可能只收集錯誤之前的項目，而外層繼續正式載入。

### 3.4 對新腳本的直接限制

正式 VM 可見的 API，不能不加區別直接寫入前置也會呼叫的 scene。使用原有全域 `WalkObject` 等可經前置 collector；直接 `Q.WalkObject` 則不在此前置 Q 表的已註冊方法內。`lb` 與 Tutorial 也不能僅憑正式 VM 註冊就當成前置可用。

前置的 `wait` 是空函式。新寫的 `while not cleared do wait(100) end`，若前置分支會進入，**不能靠 wait 暫停**；條件不改變時將沒有這條 API 提供的讓出機制。這是雙階段 executor 的實作契約，並非以 Lua 文法通過就能排除的問題。適配設計必須區分前置與正式行為，讓前置有限完成、資源需求完整。具體 guard／離線依賴宣告與 script 範本屬待設計及驗收，本輪未改檔實作。

## 4. 正式 executor：協程、更新、等待、結束

### 4.1 原始 qbase 的協程契約

本段重核的 qbase proto 0 建 `qco = MoCo.new()`；proto 75（來源行 550–552）的 `Register(f)` 呼叫 `coroutine.create(f)`，再轉入 `f_registerCoroutine`。proto 1 將協程交給 `qco:registerCoroutine`。這與前置同名 Register 的立即呼叫語意不同。

proto 2 的 `f_doCoTask()` 呼叫 `qco:doCoTask(Q.EndCutScene)`，將場景結束函式當參數交給 scheduler。proto 3 的 `f_removeAllCoroutines()` 轉呼叫 `qco:removeAllCoroutines()`。因此已知建立／排程／移除的接口；`MoCo` 的完整實作若不在本次可讀原件，不能由這些名字補猜所有排程與錯誤政策。

### 4.2 native 更新有條件

`561520` 的 manager 來自 ECX。`561587` 要求 manager `+28 != 0`；`5615C7` 要求 `+2C == 0`，才於 `5615D3` 指定 `f_doCoTask`、`5615D8 → 6F4DD0`。EAX 取自 `[manager+0]`，即上節正式 wrapper。`6F4DD0` 在這個 state 的全域環境取函式，確認 type=6，準備參數後 `6F4E81 → 6FE770` protected-call。

這個函式亦遍歷 manager 的事件物件樹並呼叫物件 vtable `+20`。它提供演出物件的持續更新，未證明一般副本在沒有活動 CutScene 時也會一直驅動 qco。

前輪已核主更新 `491E75` 受載入旗標控制，會略過含 `491ED7 → 561520` 的更新群組。故新規則若要求在載入中或演出結束後仍計時，不能僅以「VM 還在記憶體」判定它會繼續被排程。

### 4.3 等待的是具體子系統狀態

| qbase 函式 | 已核 prototype 行為 | 不應擴張的解讀 |
|---|---|---|
| `yield()` | proto 4 轉呼叫 `wait(0)` | 尚未由本段根檔確認 wait 的時間單位與所有喚醒條件 |
| `WaitForScene()` | 先 yield，再輪詢 `g_scenePlaying`，迴圈呼叫 `wait(100)`；`OnEndTalk` 清該旗標 | 是對話完成等待，不是地圖／全場怪物完成 |
| `WaitForCamera()` | 輪詢 `CameraWorks.IsEnded()` | 是相機狀態，不是關卡完成 |
| `WaitForProlog()`／`WaitForBook()` | 分別輪詢 `Q.IsPrologRunning()`／`Q.IsBookFlying()` | 不能當任意事件回報接口 |
| `WaitForObjectsStop()` | 輪詢 `Q.IsAllObjectsStopped()` | 對應演出物件停止；沒有掃世界怪物 HP 或群組 |
| `WalkObject`／`AniObject` 等 wrapper | 呼叫相應 Q 方法，再 yield | 能把固定中間演出交給 Client；目標仍須由腳本提供 |
| `StartLoading()`／`EndLoading()` | qbase proto 40／41 都只有 yield | 不能因命名就宣稱會傳網路 ready／切載入畫面 |

本段的 `100` 只寫原腳本參數，沒有自行定義成 100 毫秒。實際 scheduler 要看 `Coroutine.lua`／wait 實作與計時來源。

### 4.4 結束／取消／回報不能合併

已核 `IsCutSceneRunning` target `489CF0` 讀 manager `+28`。`EndCutScene → 561DB0` 在適用分支清同欄，並經 `4AD0A0` 呼叫 `f_removeAllCoroutines`；另清理場景物件、UI／相機相關狀態與後續場景決策，復用 E12 與 scenario-controls 的有限生命週期證據。

原有 C2S `003F` 可出現在清理路徑，且可能早於 coroutine／UI 清理完成。它不能直接當成「全部怪物死亡」「本波完成」「獎勵可入帳」或「新檔案成功執行」的確認。新功能必須定義自己要觀察的完成點，不能借相同名稱替換。

## 5. 可實作內容矩陣

「已有」表示 Client 已有相應子能力或原件實例，仍受資源可見、兩個 VM、模式與 actor 存在條件限制。表中的重建規則名稱是設計層概念，不是已發現官方 MEF opcode。

| 內容／需求 | 已有可放入 Lua／SEQ 的能力 | context／API 邊界 | Server 開發需求 |
|---|---|---|---|
| 場景觸發 | S2C `0047 → 503070 → 561760` 取任務／場景鍵；Q.StartCutScene 也進相同 target；SceneList 選 `Event/Sequences/<funcName>.seq` | 有忙碌、查表、資源與模式分支；不是下載檔案 opcode。新場景必須有可選的索引與檔案 | 在適用狀態選正確 key，維護演出進度；版本／資源交付屬更新通道工作 |
| 固定對話、鏡頭、音樂、特效 | qbase 的 OpenTalkScene、PlayCamera、PlayMusic、PlaySound、Fade、Book、Dialogue 等；Q119/3 有真實序列實例 | 表格對話 key、相機／音效資源須存在；前置只收依賴或略過表現 | 發起一次有限演出後可由 Client 編排；故事條件與共享進度由 Server 提供 |
| 演出角色生成、走位、動作、刪除 | Q.CreateObject 建 `CEventActor`（`562EC0 → 4D0B80`），Q.WalkObject→563330，Q.AniObject→5634E0；qbase ClearObjects→Q.DeleteAllObject | 使用事件自己的槽位／容器，與世界可戰鬥 actor 不同；停步不等於死亡 | 決定演出起點；不要把演出 actor 當已同步的敵人 |
| 真正世界 monster／NPC 本地建立 | `lb.CreateObjectEx(model,x,y,scale,direction,attach)`；模型 10..10000 走 CMonster `4D1710`，>10000 分支走 CNPC `4D2120`；`4A11B6 → 4DFF30` 入共同索引 | 六參數沒有外來 EntityId；用 F7DE04 本地計數器，並非 Q 的槽位。前置無此 lb API；attach 不等於自主 AI | 若要接替整波網路生怪，必須提供實體／波次身分對照、避免重複建立、對齊命中與移除；現成 S2C0007 使用 Server row ID |
| 既有出口開／關 | `Tutorial.SetCheckPointStatus(key,category,status) → 4A9460 → 544940`，與 S2C0048 同 setter | 只更新已存在點；前置無 Tutorial；普通副本事件到該 API 的觸發仍未閉合 | 可先用 S2C0027 登記出口，再在有證事件來源時接本地 setter；選圖／結果仍要同步 |
| 建立提示／互動點 | Tutorial.AddCheckPoint 經 TutCheckPointList 建 category4 提示點 | 固定 category4，不能當成通用 category0 出口或 category2 商店建立器 | S2C0027 有新點 row 接口，且先清舊集合；Server 應發布正確完整集合 |
| 本地換圖 | `lb.ChangeMap → 4A0AC0 → 4DF510` 與網路地圖載入共用子能力 | 只證載入本機地圖；不自帶 Server 副本節點／actor／存檔同步；前置不直接可用 | 實例、節點、出生點、出口、actor、完成／獎勵狀態應一起轉移 |
| 商店／NPC 行為 | 已有模型、對話、market checkpoint、ShopInfo／ShopProduct 與商店 UI consumer；可使用既有資源組合 | 可視 NPC 不等於商店點。category2 key 是 ShopNo；一般腳本建 CNPC 不會自動產商品清單或商店能力 | 提供正確 ShopNo、Town+NPC 商品關係、交易結果與資產同步；價格、數量、物品權屬、持久化由 Server 實作 |
| 按條件接續演出／教學 | TutorialMain part2 RequestStartScenario(14)，輪詢 IsScenarioEnded(14)；教學 S2C004C 寫對應 scenario 旗標 | 這是教學 controller 的特定事件，不是全域怪物死亡／group-clear；不可平移成普通關卡清波事件 | 一般波次需有明確 stage／group／entity 狀態與事件接口；現有教學接口只按已證適用情境使用 |
| 普通怪固定路段 | S2C0018 一次傳 actor、終點、步數，CMonster 更新執行中間步進 | 這不是已證 Lua 自主尋敵 API；碰撞與終點另有規則，步數不能當毫秒 | 決定終點、改目標／中止、校正位置；可用小範圍對照驗收是否減少中間位置包 |
| 波次、清怪、分支與開門 | 可以用重建規則描述；有限條件式／協程編排已有 Lua 基礎 | 缺一般戰鬥的可靠 group-clear producer、持續運行 context；GetObjectCount 不提供可用證據。SEQ 前置還會先執行 scene | 在 Server 維護實體死亡／波次狀態，對已證 Client 接口輸出結果；要本地等待新事件，需先閉合 Client 接口，不能捏造 opcode |
| 尋敵／仇恨／選招／命中／HP／掉落／任務結算 | 可以描述規則、播放動畫，已有各類狀態 consumer | 動作播放或 HP setter 不等於 Client 算出命中；未建普通敵方自主決策到可靠回報的完整鏈 | 決策、權威戰鬥狀態、多人同步、合法結果與獎勵持久化列 Server 開發需求 |
| 新腳本追加讀檔 | 正式全域 `DoFile`、`lb.DoFile`、標準 `dofile` 各有實作 | 三者不同：大D DoFile 走資源且處理 BOM；lb.DoFile 走資源 buffer loader；小d dofile 走 stdio。前置沒有由本段裝入這套標準／lb 接口 | 安排可達資源、版本／hash 與明確啟動鏈；不從 API 存在推導網路傳檔能力 |

### 5.1 身分不能只用「同模型」替代

Q 建的是事件 actor，自己的 slot key 對應自己的容器。lb 建世界 actor 時 `4A104F` 讀 `F7DE04` 低 WORD，`4A105F` 寫 actor `+4`，`4A11BB` 自增；磁碟初值 1001 不保證每場重設。S2C0007 則由來包 row 取 EntityId（`4AEB2C/4AEB30`），再加入同 `4DFF30` 索引。遇到重複 key 的原生處理不是自動把兩個來源合併。

因此一份重建規則若有 `spawn(group)`，執行契約至少須區分 scene slot、model/template、Server EntityId、instance/group。它們都是不同概念，不能僅用相同整數或相同外觀假定關聯。

### 5.2 商店需要資料與交易協定

既有 market category2 的 key 是 ShopNo，由 CShopMgr 查 ShopInfo（NO、TOWN、TYPE、NPC）；貨品再按 Town+NPC 查找。NPC 外觀與商店 checkpoint 可分開存在。原 town1 部分 merchant NPC 沒有可供 class6 建立的模型／roster，不能以「已有建 NPC API」保證生成對應商店人物。

買入 C2S0027、賣出 C2S0020、強化 C2S00A1 及其結果 UI，都有各自相容格式。S2C0030／00D9 等結果反饋不等同帳目／物品已同步；現有資產更新還使用獨立的 S2C002C／0029 等路徑。重建規則可表達何時開放哪個服務，Server 仍須計算與提交交易，對齊貨幣、背包與持久化。

## 6. GetObjectCount 的正式校正

既有 scenario-controls 最後一段寫「wrapper 在 4A1F32 覆寫 EAX=1」。指令事實正確，但若讀成數量永遠 1 就會錯。本段沿 native Lua 呼叫端補證：

1. `4A1668` 設 `FE1780=4A0A30`；`4A16A8` 入棧名稱 `GetObjectCount`，`4A16B9` 指定 wrapper `4A1EF0`。
2. wrapper 把輸入 Lua state 存在 local，`4A1F2C` 呼叫 `FE1780`，`4A1F32` EAX=1；沒有把 target 的 EAX 轉成 Lua number 或推入有效數值槽。
3. target `4A0A30` 檢查一次性 manager 初始化。已初始化時 `4A0A62 → 4A0A84` 直接回程；未初始化則呼叫 `4DEC90` 與 atexit。函式沒有遍歷物件／怪群／HP。
4. Lua 的 C closure call `6FE360` 呼叫 callback，接著 `6FE375 shl eax,4`，`6FE37A` 取 stack top、`6FE37D` 減掉回傳數×16，`6FE380 → 6FE4C0` 從既有 TValue 槽複製結果。**EAX 是回傳值個數。**

可證結論是「這組 binding 沒有建立可靠的物件數輸出契約」，而非「一定回傳數字 1」。未 push 的情況具體會拿到哪個舊 slot 取決於呼叫 stack，這裡不以猜測值作遊戲規則。清波判定應使用有已證 producer／consumer 的事件或 Server 實體狀態。

## 7. parser／executor 實作需求應如何劃分

| 層 | 若重用已證 Lua／SEQ | 若要求原生 `.mef` 或新的關卡語言 |
|---|---|---|
| 檔案取得 | 用已證更新／資源載入通道，確認使用同版本、同鍵的內容 | 交付檔案本身仍不決定語言；副檔名 `.mef` 不能產生 parser |
| 內容解析 | 已有 Lua parser／VM，但須使用版本相容文字或 bytecode，以及各 loader 的 BOM／封裝契約 | 原生 MEF magic、資料列／指令、型別、錯誤行為尚未確認；不能宣稱現有 Lua 就能解析原格式。若設計新格式要明標 `NOT_NATIVE_MEF` |
| 索引與入口 | 用既有 scene key／SceneList／SEQ 路徑或已證 API 進入 | 原生 MEF reader、入口、map-to-file 與 dispatch 未證；未知 Client 接口仍是 Client 待逆向，不全丟給 Server |
| 前置資源階段 | 保留或適配雙 VM 契約，有限完成、資源集合完整，不能執行世界副作用或一般等待迴圈 | 新格式需要明確依賴宣告／預載策略；此為設計，不是原版格式推定 |
| 執行與 scheduler | 有 coroutine、protected call、場景更新與結束；但 update 依 running/loading 條件 | 普通戰鬥的常駐生命週期、計時、取消／換圖、錯誤處理要有已證入口或另行設計 |
| host bridge | 可重用具名 API 的已證效果與參數，分清 Q、lb、Tutorial／場景模式 | 新增指令必須有實際 native 效果；只列名字不構成實作 |
| 事件與狀態 | 對話／相機／演出停止、教學完成有局部實例 | 一般死亡、群組清空、波次完成、玩家進區、多人一致性等仍需各自 producer／consumer；未證介面不可捏造 |
| Server 相容輸出 | 有效 scene key、actor ID、checkpoint、交易與資產等既有訊息 | 相容 Server 決定規則、資料、事件順序及持久化；不必還原原 Server 的內部演算法 |

本輪只提出需求與可用介面，未提出已可直接套用的完整新 MEF 封包／檔案規格，未修改 Client 安裝新的 parser／executor。若以 Server 自訂關卡定義決定波次、生成、獎勵，再輸出已證封包，那是 Server 實作路線；若要讓新規則在 Client 自行運行，還必須完成對應的 loader、context、事件及同步契約。

## 8. 是否找到另一個獨立 MEF 事件引擎

這次的新陽性是兩個 Lua state、資源收集 callback 和正式 Q/lb/Tutorial bridge。兩個 state 有清楚的 SEQ 前置／正式關係，**不構成另一個 MEF 引擎的證據**。

既有 baseline 已核 `_MapList.TRIGGER` 名稱、同地形不同邏輯地圖與不同 trigger、MapFlow 的 Node.title；目前已證 consumer 沒有把那些名稱連入上述 Lua loader 或另一個已識別的事件 parser。TriggerMsgList／005E 是提示文字；CLUSTERSET 的已證使用是預載需求。這些結論沿用原件與既有範圍，本段不重做否定掃描，也不把「未找到」升為全程式不存在。

下一個有價值的新增證據應是：某個入口實際取得以 trigger／邏輯地圖區別的內容，接入獨立 parser／dispatch，並有可觀察的場景／戰鬥事件 consumer。只再找到一個字串、table 名或空 callback，不能補上這條鏈。

## 9. 待移交項目與驗收狀態

| 分類 | 本次剩餘項目 |
|---|---|
| Client 待逆向 | 原生 MEF parser／executor 的輸入與選擇鏈；一般戰鬥 group-clear 事件到 script 的橋接；常駐場景以外 scheduler 的可用入口；本次未取得的 MoCo 完整時間／錯誤政策 |
| Server 待開發 | 副本 instance／stage／group／EntityId 對照、波次／死亡／勝利規則；相容 scene／actor／checkpoint／交易輸出；合法結果與獎勵持久化；資源版本與交付服務 |
| 跨功能待整合 | 本輪交付窗口、parser／資源存放與本稿 executor 的同版本鏈；新增 SEQ 的前置／正式行為與現有資源依賴 |
| 待遊玩驗證 | 新檔實際被選用、前置收集完整、正式執行／等待／收尾、世界 actor 身分一致、事件回報、實際封包節省；本輪均未實機驗收 |

## 10. 來源索引

- 本段原件與新證據：本目錄 `native-windows.json`、`prepass-bindings.json`、`qbase-prototypes-evidence.json`、`native-windows.asm` 的 executor group；整合重驗工具與命令見 [README](README.md)。
- `governance/client-variants/20261109-mef-town-services/scenario-controls.md`：演出例、世界 actor、移動、checkpoint、教學旗標與原件 hash。GetObjectCount 的 C return 解讀以本稿 §6 補正。
- 同目錄 `town-npc.md`、`shop-services.md`、`shop-asset-sync.md`、`README.md`：NPC／商店資源關係、交易 UI 與資產同步責任。
- `kr-extra-roy/20261029-chatgpt-web-roy-E12-CutScene-named-Lua-API-lifecycle.md`：Start／End／IsRunning 具名 native target 與生命週期。
- 同目錄 E13、E14、E15、E16：SceneList 到 SEQ 路徑、資源讀取、Lua protected execution、雙次載入。前置 Register 的立即執行及 72stub 是本段新增；不用舊稿的未知狀態覆蓋新證。
- `shared/integrations/T01-20261029-semantic-review/t16/lua/kr-qbase.lua.json`：既有 Lua 解碼。JSON SHA-256 `8fdf2bf78c2d8465dc7b401ce76b29dbb2c0f389c5804382196980a38451ab56`；本段回到原 STP 核對全部 906 指令字。
- 上述 qbase JSON 的 Git 來源為 commit `ba5f96dfa94d734cbded291fb8887f50426bfa77`、path `shared/integrations/T01-20261029-semantic-review/t16/lua/kr-qbase.lua.json`、blob `65fbcc2f8dc46bc9fb43a950465c96934b6a547a`，與本輪工作樹檔案相符。支線驗證只讀原 STP 的固定區間並 XOR `FF`，核完整成員 SHA，再以每個 prototype 的 `code_offset`／`words` 做 little-endian DWORD 比較；不呼叫 Lua、不執行 chunk。其 76 proto／906 words 結果保存在 `qbase-full-source-verification.json`；整合工具可獨立核本包 24 個選取 proto，或提供固定原始 JSON 重驗全部。這項核對不自行升級全部 decoded 語意為 FULL-PASS。
- `source-manifest.json` 列每項承接來源的實際檔 SHA、Git commit/path/blob 與新原件窗／本段產出的 SHA；「僅承接既有筆記」與「本段新增原件覆核」分開標示。
- `governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md`：既有有界否定結果、其他容器與 trigger 研究。傳遞時機本身應另看本輪新的 launcher 正向結果，不能沿用舊稿「所有時機為零」概括外部更新通道。

