# MEF R14：提示點、玩家操作、Lua 可觀察結果與後續演出的完整鏈

整理基準：2026-11-16 19:17:47（Asia/Taipei）。工作分支 **extra/roy1**。固定父提交 **89698a074cf9edde8a6da9e3f40002bbef8b32e3**；核對 main 仍為 **03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc**，沿用本對話已合入的主線，不建立新分支或空合併。本輪只提交自己的研究、節錄與驗證器，不改 Client、Server、原始資源或正式 Task／RR 狀態。

## 1. 本輪回答：腳本能等待玩家抵達或操作，再自己續行

**已有一條正向原件鏈：建立教學提示點 → 玩家進入範圍／按互動動作 → native 寫入教學進度旗標 → Lua 讀同一旗標 → 關閉提示點 → 播放下一段演出。** 這不只是推測可組合的 API；原版 TutorialMain.lua 本身就在使用這個流程。

R11 已確認 InsertTutorialCheckPoint、Get／SetControlStatus 的基本能力；R12／R13 已有 point 容器、啟停及候選篩選。本輪新增的是它們的**同一對象 writer→getter→原版 Lua consumer、控制器與輸入來源，以及重用時三種不同狀態的生命週期**。未將已知 API 名稱重新算作新發現。

本輪最重要的區別：R13 的 `point+0x104` 仍只是進入範圍／候選邊緣紀錄；真正可由 Lua 查詢的是 **CTutorialController+0xB4+4*key 的 DWORD 控制旗標**。兩者不能混成同一欄位，也不能因前者沒有 getter 就說腳本無法知道教學提示點被觸發。

本文中的 MEF 能力指重建事件內容可以利用的既有 Client 腳本機制；使用者不要求普通戰鬥全部移交給 MEF。本輪以 **Tutorial 合法上下文**為範圍，不把它直接延伸為任意普通地圖事件 API，也沒有宣稱把檔名改成 .mef 就能自動執行。

## 2. 可直接使用的能力與條件

| 想做的內容 | 原件支持的操作 | 必要條件／不能假設的部分 |
|---|---|---|
| 顯示一個教學目的地 | InsertTutorialCheckPoint(key) 讀原表，建立 category 4 點與效果 | 有效表列、效果資源、已初始化 Tutorial owner；不是任意座標建立 API |
| 走入範圍後續劇情 | 非零 mode 不要求同一互動輸入；成功分派會寫 progress[key]=1 | 啟用狀態、嚴格範圍、候選選取及頁面 gate 均成立 |
| 在範圍內按互動才繼續 | mode 0 要求映射動作 13 的 state==1 | 不是長按狀態；不是永遠綁定同一實體鍵 |
| 腳本等待該次操作 | GetControlStatus(key) 讀同一控制器的數字狀態 | 必須使用正確控制器與合法索引，不能以 Lua 0 當 false |
| 關閉提示點並播放下一段 | SetCheckPointStatus(key,4,0)，原版 helper 再啟動 Q scene 並等待 | 點的啟停、進度旗標、演出狀態各自不同；不等於任務／獎勵結算 |
| 重複使用同一提示 | 內容可顯式清進度、協調既有點與重新進入範圍 | 插入成功不清舊進度；重插會追加，不能當 upsert 或完整 reset |

## 3. 原件、資料與復驗方法

KR BIN SHA-256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32 i386、ImageBase 0x400000。Event.stp SHA-256：`2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；Table.stp：`09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。本輪實際讀取原件，解析 Lua bytecode 為資料，沒有執行 Lua。

[native-evidence.json](MEF-tutorial-observation-20261116/native-evidence.json) 保存 24 組 code windows 的 VA/raw/大小/SHA-256/指令數，15 組關鍵 bytes、4 組 vtable／RTTI 資料、13 個字串及 14 條 direct calls。窗口使用完整函式或明列的分支區間；不是全程式覆蓋。未序列化的完整 code window 可由給定原件和固定範圍重新反組譯，摘要指令另列於下文。

[resource-evidence.json](MEF-tutorial-observation-20261116/resource-evidence.json) 固定四個來源 member 的物理位置／hash，保存 11 段原版 Lua 的 156 個選定指令字及用到的常數、少量 XML 屬性；**不包含完整解包檔**。PC 從 0 起算，終點不含。STPD/Lua 只讀 parser 的來源與本輪來源 pins 見 [source-manifest.json](MEF-tutorial-observation-20261116/source-manifest.json)。

[verify_evidence.py](MEF-tutorial-observation-20261116/verify_evidence.py) 核原件 SHA、PE 映射、窗口 hash、重新解碼的指令邊界、calls/vtables、選定 member 原件與 Lua/XML，並檢查有限狀態推導案例。驗證器不連網、不改 Git／原件、不發封包；狀態模型不是執行遊戲。實際 stdout 存於 [verification-result.json](MEF-tutorial-observation-20261116/verification-result.json)。

## 4. 登記、載入與執行上下文

| 接口 | 正常 registrar → native slot/target → closure | 關鍵條件 |
|---|---|---|
| InsertTutorialCheckPoint | 4AA7C0 → FE1810=4A9430 → 4ABF70 | 一個數值索引；不是 filename 或三個座標 |
| SetControlStatus | 4AB300 → FE1858=4A9F90 → 4AC640 | index,value；native 不做索引 bounds check |
| GetControlStatus | 4AB3A0 → FE185C=4A9FB0 → 4AC6A0 | 回傳 number，不是 boolean |

bootstrap 4A88E0 的 4A8902／4A896E／4A8974 真正呼這三個 registrar，尾端讀 `Event/TutorialBase.lua`。教學入口 **4A8A60** 在 4A8B64 載入 `Event/TutorialMain.lua`，4A8B74 呼 `Tutorial_EntryPoint`；另一個 4A89C0 入口呼的是 `Synopsis_EntryPoint`，不能混用。原版 TutorialMain 的 P9 登記 TutorialMain；P8 在啟動 Part1 前呼 SetControlStatus(10,TRUE)。

native pump 4A8B90 經名字 `t_doCoTask` 呼 Lua；所選正向 caller 4C19A9..4C19B3 傳入 Tutorial owner FC0F84。TutorialBase P1/P2 保存 coroutine 登記／doCoTask 的實際原版 operands；更深層 MoCo resume／End 差異沿用 [R6 scheduler](MEF-runtime-contracts-20261115/scheduler/report.md)，不重新宣稱返回自然等於 End。

### Getter 的真實資料型別

4AC6A0 closure → 4ACF90 conversion → 4A9FB0。conversion 以數值／可轉數字字串轉索引，其他 tag 會落到 0；native 讀 DWORD 後以 signed FILD 轉 number，寫 Lua tag 3 並增加 top。相反地 Insert 的 conversion 4ACB70 呼 native 後清 EAX，沒有 push 一個新的成功結果。**不能把 Insert 呼叫結果或 closure 回傳個數 1 當成功 ACK。** 內容端需事前驗資料與 context，缺資料不能靠猜回傳值補救。

## 5. 提示點如何建立：active 是觸發模式，不是啟用值

4A8C20 讀 `Table/TutCheckPointList.xml`，解析 id、category、x、y、range、active、effect；本次原表四列皆沒有 category 屬性。4A90C0 以輸入 low WORD 查已載入的表，取 row+2 的 key、row+4/+8 的 XY、row+C 的 range、row+10 的 active。其建立呼叫為：

```text
4A9132  mov edx,[edi+10h]    ; active -> mode
4A9139  push edx
4A913E  push 1              ; enabled 固定為 1
4A9141  lea ecx,[edi+4]      ; XY
4A9147  push edx            ; 此時 EDX 已是 row key
4A9148  push 4              ; category 固定 Tutorial
4A914B  call 543700
...
4A9225  call 443D10         ; append 新 point 指標
```

原表 id 1、2、3 的 active=1，id 4 的 active=0。**id4 不是建立後關閉的點**：它一樣 enabled=1，只是需要互動動作的 mode0。原表 category 缺省不會把它建成 category0；native 此入口固定傳 4。

Point 配置大小 0x108，建構器設 point+104=0，vptr C0F7FC。查表成功會另外處理原表 effect，最後追加到全域 point vector；此路徑沒有先搜尋同一 (category,key) 的既有物件。表不存在則回 0。合法資料／效果存在、記憶體分配成功及當前 owner 有效都屬前提，不能把所有異常包成安全 false。

## 6. 玩家操作到可觀察結果：三份狀態與兩個 gate

### 6.1 型別與進度欄位

CTutorialController 的 ctor 548B90 寫 vptr C0FB1C，RTTI 字串 `.?AVCTutorialController@@`。其 32 個 DWORD B4..130 初始化為 0；548C65 將全域 FBA7AC 設為 4。`+134` 是另一個教學 UI state，不屬此 32 格。

| 所屬對象 | 欄位 | 作用／原生讀寫者 |
|---|---|---|
| CCheckPoint | +105 byte | 可用狀態；Lua／0048 共用 setter |
| CCheckPoint | +104 byte | 候選邊緣 latch；544730 讀寫，尚未證直接 Lua getter |
| CTutorialController | +B4+4*k DWORD | 控制／教學進度；5443E3 寫 1，4A9FB0 讀，4A9F90 寫 |

**32 格不是任意可用事件槽。** 原版 P8 已使用 index10 作掃描開關、index0 作中止 Part1 的控制；新內容必須使用有來源且不碰撞的配置，不能利用 native 缺 bounds check 去存取別的欄位。

### 6.2 為什麼尚未寫到進度旗標

CTutorialController v+2C=548CB0。它先要求 self+4 非空、**self+DC 非零**、self+C 有效；DC 就是 B4+4*10，呼應原版 P8 的 SetControlStatus(10,TRUE)。之後從 input accessor 444960 讀 `input+7E1==1`，傳 1 或 0 給 544A00。只有可用控制器、角色/context 與掃描開關都符合時，point 才會進入這條檢查。

點的候選判定 544730 對有限正常數值採 **距離平方 < 半徑平方**；剛好等於半徑不算內部。mode0 再要求輸入參數非零；mode非零不要求同一參數。所有點先更新各自 +104，544A00 再選距離最小的有效候選；等距比較不替換先前候選，所以本次 vector 中較先者保留。最後 **F942C0==0** 才呼 winner 的 v+64=544070。

### 6.3 真正的 progress writer

```text
5443C0  mov ebx,4
5443C5  cmp ax,bx                 ; point category 4
5443CA  cmp [FBA7AC],ebx          ; current controller type 4
5443D6  movsx eax,word [esi+F6h]  ; point key: signed WORD
5443DD  mov ecx,[FBA7A4]
5443E3  mov dword [ecx+eax*4+B4h],1
```

GetControlStatus 的 4A9FB0 讀當前 FBA7A4 的同一個 B4+4*index；SetControlStatus 的 4A9F90 也寫同一位置。這才形成 **同一教學 key 的原生事件可被 Lua 觀察**。此 category4 成功分支直接返回，沒有經 R12 的 001C fallback；不能因此擴成所有提示點、所有教學步驟都不需要任何 Server。

## 7. mode0 的輸入是「映射動作新按下」，不是長按或固定實體鍵

input accessor 回 FB8830，7E1 = 7D4+13。6D1480 的輸入更新以40筆映射列產生本次 raw 狀態，6D1915..6D19BC 比較先前 `+7AC+i` 與目前值，寫 `+7D4+i`。在已正規化的 0/0x80 域：

| 先前 raw | 本次 raw | 寫入 state | 意義 |
|---|---|---|---|
| 0 | 0 | 0 | 未按 |
| 0 | 0x80 | 1 | 新按下 |
| 0x80 | 0x80 | 2 | 持續按住 |
| 0x80 | 0 | 3 | 放開 |

所選原式為 changed ? ((old|0x40)>>6) : ((old>>6)&2)。controller 只比 1，故持續按住不等同新的 mode0 觸發。6D19E4..6D1A0B 另會把 input owner+80C..810 的事件項目覆寫到同一狀態陣列，因此也不能宣稱這個值只可能來自某一物理鍵。

原 `Table/KeyMapping.xml` 的 DefaultType=0；MapButton13 在 Type0 為 Key44、Type1 為 Key36，兩者 ModKey0。6D0B07..6D0B19 依 MapButton 與所選 type 定位16-byte列。此處只公布原始鍵碼，不擅自把可切換映射改寫成全流程固定 Z；KeyMapping 的選型／複製能力沿用 R11。

## 8. 原版 Lua 已如何利用它：不是虛構示例

| member／prototype／PC | 原版操作 |
|---|---|
| TutorialBase P0 0..12 | TUTORIAL_POINT=4、ST_CLOSE=0、ST_OPEN=1 等列舉 |
| TutorialMain P8 10..17 | SetControlStatus(10,TRUE)，登記 Tutorial_Part1 |
| P5 27..54 | 顯示 TUTORIAL_KEYBOARD 提示；插點1；GetControlStatus(1) 等待；關點1 |
| P5 60..63 | PlayAndWaitForScene(1000,3) |
| P5 64..91 | 顯示 TUTORIAL_MOUSE 提示；插點2；同 key 等待；關點2 |
| P6 73..94 | 插點4；GetControlStatus(4) 等待；關點4 |
| P1 0..16 | Tutorial.StartCutScene(q,s)，輪詢 IsCutSceneRunning，再 yield |

原碼等待是數值 getter 與環境 global FALSE 的比較，不是 boolean getter；內容若新寫判斷，應明確比較預期數值。這些片段只解析，沒有執行。原版 helper 和資料均不等於新模組已部署。

**一項有用的限制：已核 P5 的鍵盤移動／滑鼠移動等待，只讀各自 GetControlStatus(1/2)，點1/2又都是自動範圍模式；這條完成判斷本身沒有區分玩家究竟以鍵盤還是滑鼠抵達。** 提示文字不能當輸入方式驗證。這不是宣稱遊戲完全沒有其他輸入紀錄，而是限定該原版等待條件。

## 9. 重用與收尾：成功重插不是重置，狀態也不是事件佇列

### 9.1 三份狀態的重置矩陣

| 操作 | point+105 | point+104 | controller progress[k] |
|---|---|---|---|
| SetControlStatus(k,v) | 不動 | 不動 | 寫 v |
| SetCheckPointStatus／0048 | 更新既有點 | 沒有這項重置保證 | 不動 |
| InsertTutorialCheckPoint 成功 | 新點固定1 | 新點0；舊點不因此被移除 | **保留舊值** |
| 同入口因缺 row 返回0 | 沒建新點 | 沒建新點 | wrapper 將所給 index 寫0 |
| 全量0027重建 point 集合 | 使用新 row 狀態 | 新物件初值0 | 不是控制器重建，不自動清此陣列 |
| 新 Tutorial controller ctor | 另一容器，非此 ctor 清理責任 | 同左 | 32格初始化0 |

4A9445 test eax,eax；4A9447 jne4A9450 使**成功跳過**4A9449的 progress 清零；只有回0才寫0。這不是「每次插入就開始新的未完成事件」。同 key 重插還會追加第二個點，既有狀態 setter 僅修改第一個配對點（R12 已證），可能讓後面的 duplicate 仍可觸發。

### 9.2 有界反例：自動點的候選可能被消耗但沒收到完成

所有候選先寫 +104，之後才決定最近 winner 和 F942C0 的最後 gate。因此，在兩個重疊自動點同次進入的情況，兩者 latch 均可能成1，但只有最近的一個分派；另一個下一次掃描返回「仍在範圍」而沒有新邊緣。最後 gate 阻擋時，winner 也可能已有 latch1但沒有執行 category4 writer。

這是原件順序推導，驗證器只跑對應的**獨立有限模型**，不是原版遊戲重現。可實作的保守內容規則是避免活躍自動點重疊，保證所用 context 能分派；重試要明確處理離開／再進入或合法重新建點與 progress reset，不能只在 Lua 無限等 flag。mode0 在沒有新按下的後續掃描會清候選 latch，但不清已寫入的 progress。

## 10. 放回完整 MEF 使用流程

1. **內容與發布**：有來源的 scene、Tutorial table、效果／角色／對話資源與版本。沿用已證 launcher／resolver，不造 game TCP 傳檔 opcode。
2. **入口與執行環境**：既有 Tutorial entry 讀 Base/Main 並登記 tco；新相容模組則另依 R9 caller 設計。Q 序列仍有自己的 prepass/formal，不可把這份 Tutorial 控制器契約套進任何 VM。
3. **產生與觀察**：插入合法提示點、開啟所需控制 gate；native 以角色位置與映射輸入選點，寫控制器 progress；Lua 在後續合法 pump 讀回。
4. **本地續行**：原版腳本關點、隱藏／改提示、開始下一段 Q 演出與等待；不必由 Server 對每個中間顯示動作逐次命令。
5. **清理與 Server 續接**：point、progress、tco、Q actor/camera/UI 分別管理；End/003F/00EB 沿用原契約，不把本地提示完成直接當任務結算。交易、共享世界、權威任務與存檔仍由 Server 提供。

完整上游沿用 [R11 能力與流程](20261116-113220-chatgpt-web-roy1-MEF-capabilities.md)、[R9 入口](MEF-end-to-end-20261116/entry/report.md)、[R10 收尾](MEF-control-flow-20261116/presentation/report.md)、[R12 point 協定](20261116-MEF-checkpoint-lifecycle.md)。本輪對這條本地操作→Lua續行鏈有完整正向證據，不把「Server 仍做權威工作」當作能力未完成。

## 11. 開發交接、剩餘範圍與驗證結論

[Server／內容開發交接](MEF-tutorial-observation-20261116/server-handoff.md) 已分別列出合法資料、controller/context、slot使用、點重用、集合重建、結果對帳和正常流程驗收。Server 內部可以自訂 run/generation，但本輪沒有新的 wire 讓 Server 任意寫 progress，也沒有每次 local flag 的新增回報。

**Client 待逆向**保留原生 MapList.TRIGGER→官方 MEF 首次 loader／grammar／executor；point+104直接Luagetter仍未證。這不撤銷本輪對另一份 control progress 的正向證明。普通地圖要採不同入口時按實際需要另查，不設「普通戰鬥全面替代」共同門檻。

**跨功能待整合**為選定新內容與合法入口、共享 owner 及重試政策；**Server 待開發**為版本發布、相容流程／服務、權威結果與保存；**待遊玩驗證**為正常腳本開始、玩家抵達／操作、旗標更新、後續演出與最後雙端狀態。此輪未執行這些遊戲測試。

本輪實跑驗證器 PASS：24 組 native windows／7,055 bytes、2,149 條解碼指令，15組byte錨點、14條直接呼叫，4個原件member、156個選定Lua指令字。模型另有4組輸入邊緣、8組候選與1組重疊案例。**這些數量不是獨立能力數或全程式覆蓋率；PASS 不等於正式 T01 FULL-PASS、RR ACCEPTED、Server 已實作或玩家驗收。**
