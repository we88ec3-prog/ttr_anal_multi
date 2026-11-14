# MEF 完整流程補證：Lua 失敗、取消、重入與條件式內容橋接

研究基準：2026-11-15（Asia/Taipei）；`extra/roy1` 工作起點 `67021e609f56e45981aecf45533bdad084039a47`；`main` 查核基準 `909754f28bd2e54c8ede00e3a56021cf59facd14`。

## 1. 本輪可回答到哪一層

**現有原件已足以描述「通用 Lua 載檔 → 註冊工作 → native 每次更新叫回 Lua → 內容顯式收尾／移除工作」的外部契約，並補出載入失敗、舊函數殘留、取消與重入的限制。** 這些能力可供既有場景／教學的 Server 整合使用，也能評估未來另准新內容時，讓既有 `.seq` 明確呼叫全域 `DoFile` 讀取以 `.mef` 命名之 Lua 內容的技術方案。

本輪沒有找到原版 MapList Trigger 名稱到 `.mef` loader 的新增正向 caller；沒有把通用 Lua 能力當成原生 MEF 格式或原生 MEF 流程。`Coroutine.lua` 曾有完整 13-prototype 分析，這項既有成果應保留；但目前可取回的發布資料未附該原件 body、完整 operands 或原件 SHA，不能從那份「未見 loader 引用」摘要推導新的 wait／error／cancel 決策。

本輪主要新增以下契約，來源均為原 BIN 指令或固定 Event 成員指令：

| 問題 | 新確認結果 | 可用範圍 |
| --- | --- | --- |
| `6F4A50` 是否真的沒有結果？ | 正常返回時 `EAX=0` 表示解析與頂層執行成功；已處理的開檔／解析／執行失敗返回 `1`。部分反編譯的 `void` 型別不足以描述 ABI。 | native path loader，不能擴成所有崩潰情境的保證。 |
| 全域 `DoFile` 回什麼？ | Lua 可見的唯一回值是**數字** `0`／`1`。內層執行接受 MULTRET，但外層 C callback 只公開最後壓入的 status。 | 不能把回值當 module table／function，也不能用真假直接辨識成功。 |
| 載 TutorialMain 失敗後是否停？ | 兩個 native 啟動 caller 沒有檢查 loader status，就繼續查找固定名稱的 global entry。 | 若同一 VM 已留有舊 entry，失敗後仍可能進入舊定義；不是每次失敗都必然如此。 |
| Q 載入失敗會立即 End？ | 已核正常／review 路徑都未依 formal loader status 做 immediate cleanup；正常 Q 的「找不到 SceneList row」另有 End 分支。 | 不能把缺 row cleanup 說成任何解析／載入失敗的 cleanup，也不能反推一定永久卡住。 |
| tick 呼叫失敗等於完成嗎？ | Tutorial tick 忽略 named-call status，直接再讀 stack top；Q tick 失敗後也沒有當場按該 status 取消。 | 原生旗標不能當成功、正常完成、清理完成的共同 ACK。 |
| Lua 有防重入與 finally 嗎？ | Tutorial／Synopsis entry body 無條件註冊；Synopsis 收尾是普通順序呼叫。Part1 子工作被 skip 時先 StopCutScene 再 remove，Part2 是 parent 內直接呼叫。 | 可指出呼叫端沒有哪些保證；MoCo 內部是否去重／如何取消仍須原 body。 |

證據位置：[本輪 native 窗與原始 bytes](native-windows.json)、[反組譯](native-windows.asm)、[選定 Lua operands](selected-lua-evidence.json)、[來源 manifest](source-manifest.json)。驗證器的 `PASS_FOR_BOUNDED_STATIC_EVIDENCE` 只表示所列證據重建相符，不是 T01 FULL-PASS、Server 完成或遊玩通過。

## 2. 讀集、沿用範圍與記號

### 2.1 固定原件

| 原件 | bytes | SHA-256 |
| --- | ---: | --- |
| `02-Tartaros.bin` | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `06-Event.stp` | 11,241,597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |

所有 native 地址均為此 KR BIN 的 VA，image base `0x400000`。`W` 表示既有 Lua wrapper，`L` 為其 state；`M` 為既有 Q manager；`T` 為 Tutorial 物件。這些是分析用記號，不是原生 C++ 型別符號。不同物件的相同 offset 不互相混用。

| 本輪實讀 Event member | block id／stored offset | 解碼後 bytes | 解碼後 SHA-256 | prototype／words／CALL+TAILCALL |
| --- | --- | ---: | --- | ---: |
| `Event/qbase.lua` | `7378`／`10618896` | 11,836 | `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3` | 76／906／138 |
| `Event/TutorialBase.lua` | `7380`／`10645520` | 1,416 | `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744` | 6／72／7 |
| `Event/TutorialMain.lua` | `7381`／`10647568` | 5,480 | `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809` | 11／558／110 |

合計 3 個 member、93 個 prototype、1,536 個 instruction words、255 個 CALL／TAILCALL。位元碼僅解析成資料，沒有執行。`PC` 自 `0` 起算；chunk offset 指解碼後 member 內的位移。完整原件解碼內容不列為提交交付，交付保留 caller 來源索引與 20 個必要 prototype 的 operands。

### 2.2 既有成果直接沿用

以下既有鏈已具證據，本輪不把它們當新發現重報：

- [parser](../../MEF-parser-executor-storage-20261114/parser.md)：全域／`lb.DoFile` binding、Lua 5.1 parser、兩個 VM、一般執行／resume／yield 原生基礎。
- [executor](../../MEF-parser-executor-storage-20261114/executor.md)：prepass 的 72 個空 binding、6 個 per-load binding、`Register` 立即執行、正式 Q coroutine 的介面。
- [entry](../../MEF-entry-lifecycle-events-20261114/entry.md) 與 [lifecycle](../../MEF-entry-lifecycle-events-20261114/lifecycle.md)：Q selector、`Event/Sequences/<funcName>.seq`、native active/tick/exit、Tutorial／Synopsis 正常入口與 cleanup。
- [named calls](../../MEF-trigger-callers-20261115/named-calls/report.md)：固定名稱 callable lookup、3／2／1／11 個有界 native caller 集合。
- [script consumers](../../MEF-trigger-callers-20261115/script-consumers/report.md)：camera XML、地圖與三個旗標 callback consumer。
- main S00 既有 1,840 `.seq`＋3 `.lua` 內容讀取，以及 boot／Logic／Coroutine／ai 的 1／1／13／8-prototype 結果。本輪沒有重做 1,843 個成員內容掃描，亦不把舊小寫 loader 陰性升格成 upper-case／alias 的全域否定證明。

本輪 `E01..E10`、`A01..A06` 共 16 個證據窗、4,612 bytes；部分與既有原件窗重疊，新的價值是錯誤 status、呼叫後控制流與 ABI 解釋，不是新增函式數量。驗證器另外重核 16 個指定舊 anchor，並分開列示。

## 3. 載檔結果：三種介面不能混成同一個 bool

### 3.1 Native path loader `6F4A50` 的正常返回值

原件窗 `E01` 包含完整函式控制流。`6F4A94` 先設 `ESI=1`。資源開啟結果為空會經 `6F4AA5` 跳到收尾，保留失敗值。兩條 parser 分支的非零 status 分別在 `6F4B15`、`6F4B72` 跳至 `6F4BB8`，該處同樣設 `ESI=1`。頂層 protected execution 在 `6F4B9A → 6FE770`，`6F4BB0..B2` 檢查其 status；成功才在 `6F4BB4` 清零 ESI。結尾 `6F4C07` 明確 `mov eax,esi`，`6F4C15 ret 4`。

```asm
6F4A94  mov esi,1          ; 先保留失敗值
6F4BB0  test eax,eax       ; protected execution status
6F4BB2  jne 6F4BB8
6F4BB4  xor esi,esi        ; 成功 = 0
6F4BB8  mov esi,1          ; 錯誤 = 1
6F4C07  mov eax,esi
6F4C15  ret 4
```

中間的 security-cookie helper `891001` 正常路徑僅比較 cookie、`rep ret`，不覆寫 EAX（`A06`）。因此不能因反編譯宣告為 `void`，就說此函式無法提供成功／失敗結果。

此結果只涵蓋函式正常返回的已處理路徑。`0` 表示資源取得、解析、頂層執行走成功路徑；不表示內容已註冊 coroutine、不表示物件 preload 全部完成、不表示一場任務已完成。`6F47A0`（`E02`）是讀 stack error、輸出診斷、在適用路徑彈出 error 的 reporter；這段沒有把先前 global 函數或腳本已做的副作用回滾。

### 3.2 全域 `DoFile`：Lua 的回值是數字 0／1

全域 binding 是 `6F4380` 建立正式 VM 時掛上的 **`6F48A0`**。本節不是 `lb.DoFile`，也不是標準庫小寫 `dofile`。`A01` 顯示 `6F48A0` 使用呼叫 callback 時傳入的當前 `L`；取路徑、取得資源、parse，然後對該 `L` protected-call 頂層 chunk。

成功／失敗的本地整數分別在 `6F4A0A` 寫 `0`、`6F4A16` 寫 `1`。尾端並非只 `return 1` 讓 Lua 得到 true：它先以 FILD 把 flag 轉為 double，寫 `TValue tag=3`，再把 top 推進一槽；最後的 `EAX=1` 是 C callback 的**結果槽數**。

```asm
6F4A33  fild dword ptr [esp+0C]   ; status 轉為 double
6F4A37  mov dword ptr [eax+08],3 ; Lua number
6F4A3E  fstp qword ptr [eax]
6F4A40  add dword ptr [edi+08],10h
6F4A46  mov eax,1                ; 一個 Lua 結果槽
```

因此內容必須以**數字等於 0**辨識成功。Lua 5.1 的數字 `0`、`1` 都是 truthy；把此回值直接當條件無法區分兩者。這個 status 也不是網路 ACK，沒有證據把它自動送回 Server。

### 3.3 頂層 module 的 return values：內層 MULTRET，外層只公開 status

此處不能寫成「pcall 要求 `nresults=0`，所以 module 回值被丟棄」。實際 bytes 是：

| 原件位置 | 觀察 |
| --- | --- |
| `6F49D6` | 把待呼叫 chunk 的 stack slot 存入 callback userdata 的第一欄。 |
| `6F49EC` | 將同一 userdata 的 `+4` 設為 `0xFFFFFFFF`，即 wanted results 為 MULTRET。ESP 此時比存第一欄時多了三個 push。 |
| `6F5A56..61` | execution thunk 讀 userdata `+4` 與第一欄，交入 `6FE550`。 |
| `6F4A30..46` | 回到全域 DoFile 後，另外在目前 top 壓入一個數字 status，callback 結果數為 1。 |
| `6FE375..380 → 6FE4C0` | C closure 返回後以 `top − count×16` 選出公開結果；此時只選最後的 status 槽。 |

內層可以暫留 chunk 的任意 return values，但呼叫 **`DoFile` 的外層 Lua 最終只得到那一個 status**。因此不能用 `local fn = DoFile(...)` 或 `local module = DoFile(...)` 期待拿到 chunk 的函數／table。若將來設計新 module，需要另外約定 global／table 匯出；讀取前清除或替換自己的 namespace、讀取成功後核對本次匯出，才能避免呼叫殘留舊函數。這是內容設計要求，不是原版已提供的 module 交易保證。[`A01`；沿用 anchor `execution_thunk_not_error_handler`、`lua-c-result-count`、`lua-result-slot-copy`]

### 3.4 `lb.DoFile` 的零值有歧義

`lb.DoFile` 經既有 binding `4A1B68` 將 `FE17A0` 寫為 `4A1230`，再由 `4A2200 → 4A2A70` 間接呼叫。`4A2ACA..E4` 將 native EAX 轉為 double、`tag=3`、回一槽；因此它對 Lua 也是 numeric result。[`A02`、`A03` 與沿用 binding anchor]

但 `4A1230` 的 resource-open 失敗在 `4A1316` 直接 `xor eax,eax`；成功取得資源後，`4A12E2` 使用固定 `&FDF3C8` 主 VM wrapper，`4A12E7` 走 buffer loader `6F4C20`。後者也以 `0` 表示成功、`1` 表示 parser／execution failure。[`A04`、`A05`]

所以 **`lb.DoFile == 0` 同時包含成功與開檔失敗**，不能當可靠載入成功條件。這個零值歧義沿用舊 parser 結果，本輪補清 numeric marshalling。它也不等同「在呼叫者目前 coroutine 的 L 內載入」；全域 `DoFile` 與固定主 wrapper 的 `lb.DoFile` 應保持區別。

## 4. 失敗後誰繼續執行：entry、active 與 tick

### 4.1 Tutorial／Synopsis：載入失敗後仍會查固定 global

兩段 caller 原件都沒有以 loader EAX 決定是否繼續：

| 流程 | 原件呼叫順序 | 結論 |
| --- | --- | --- |
| Synopsis | `4A8A36 → 6F4A50`；其後載入 wrapper／參數，`4A8A46 → 6F4DD0("Synopsis_EntryPoint")` | 載檔返回後不查 status，繼續 named global lookup。 |
| Tutorial | `4A8B64 → 6F4A50`；其後載入 wrapper／參數，`4A8B74 → 6F4DD0("Tutorial_EntryPoint")` | 同上。 |

`6F4DD0` 已由既有原件證明是查現存 global、檢查 callable 再呼叫的 wrapper，並不重新載檔。[`E07`、`E08`；沿用 named-call anchor]

**條件式推論：**同一 VM 若先前已有這些 globals，新一次 load 失敗不會自動清除舊定義；後續 lookup 因而可能叫到舊 entry。若該 global 尚不存在或不再是 callable，會走 named-call 自己的錯誤分支。若 chunk 執行到一半才失敗，也不能保證 global 集合全部來自同一次成功載入。不能簡化成「失敗一定執行舊版」，亦不能簡化成「載檔失敗一定停止」。

`TutorialMain.lua` root 只把 `g_TutoEmployCharQuery`、`g_isTutorialRunning` 設為 `FALSE` 並重新寫入函數 globals；沒有重建 `tco`。`tco` 是 TutorialBase root 建立的實例。兩個 EntryPoint 各只有四條指令：取 `t_executeCoFunction`、取指定 Lua function、CALL、RETURN；不存在 Lua 層的 busy／deduplicate 分支。這證明**此 body 沒有防重入保證**，不證明 native 啟動 gate 或 MoCo 內部一定允許重複工作。[selected TutorialMain root／proto 9、10；TutorialBase root／proto 1]

### 4.2 Q：missing row 與 load failure 必須分開

正常 Q `561760` 中，`5618EF` 先將 `M+0x28` 設成 `1`，再進行 lookup、prepass、正式載入。找不到選定 SceneList row 的分支是 `561A85 → 561D7F`，接著 `561D81 → 561DB0` 收尾。這條可確認的 End 路徑屬於**資料列不存在**。

若有有效 row 而走到正式載入，`561C7D → 6F4A50` 後第一條是 `561C82 xor ebx,ebx`，後續 native 初始化／釋放程式未以此次 EAX 分支到 End。因此載入開檔、解析或頂層執行失敗，**沒有由這個 caller 保證的立即 active reset／cleanup**。[完整窗 `E09`]

review Q `565720` 亦有前置狀態：`+0x89` 於 gate 前寫入，`+0x28` 在通過後設成 `1`。它找不到 row 時由 `565926 → 565A65` 走 epilogue，未走正常 Q 上述 End 分支。正式載入 `5659D9 → 6F4A50` 後立即 `5659DE → 434250`，同樣沒有測 loader status。[完整窗 `E10`；欄位既有語義沿用 entry 報告]

這不是「一定永久卡住」的證據。之後的 Q tick 仍可能依 MoCo 的空集合／完成策略叫傳入的 `Q.EndCutScene`，也可能遇到其他 native exit；目前缺的是 MoCo 對該 callback 的精確決策 body。可以保證到的是 caller 未提供即時、以 load error 為條件的清理。

### 4.3 tick 回傳值不是統一的完成 ACK

`4AD0A0` 的 named-call 成功分支在 `4AD0FF` 記錄 wanted results，返回 `1`；失敗經 `4AD113 → 6F4830`。後者 `6F4883` 將 top 減一槽，`6F488C` 返回 `0`。[`E03`、`E04`]

Tutorial tick `4A8B90` 在 `4A8BA6` 用此 wrapper 呼叫 `t_doCoTask`，要求一個結果。接著它**不檢查** wrapper 的 `0／1`，`4A8BAF` 直接把 EAX 改成 stack index `-1`，`4A8BB2 → 6F50F0` 讀當時 stack top。接下來只有 numeric／numeric-string 轉換與 `T+0x34` 更新。[`E05`]

所以 `T+0x34` 的結果不能無條件解作「scheduler 正常執行且正常結束」。若 wrapper 失敗，它沒有保證 top 是成功 `t_doCoTask` 應回的值。本輪不假造當時 stack 內容、不宣稱所有錯誤必設零，也不把旗標當已清理 camera／input／Server state 的證據。

Q tick 的 `5615D8 → 6F4DD0("f_doCoTask")` 後，`5615DD` 清參數、`5615E0` 開始取得 actor 容器，接續 actor 更新；沒有以 named-call 錯誤返回值立刻取消。[`E06`]

上述描述是**native 外層失敗**。若 MoCo 內部用 resume 的結果自行處理錯誤，未把錯誤再丟到 named-call wrapper，外層可能仍顯示呼叫成功；兩層不可混為同一個錯誤狀態。

## 5. 已讀 Lua 的工作註冊、取消與重入契約

### 5.1 function value 的流向已確定，排程政策仍有明確邊界

| Lua 介面 | 原件 prototype／code offset | 實際 operand 所示 |
| --- | --- | --- |
| `Register(f)` | qbase proto 75／`0x2DCC` | `coroutine.create(f)`，再交 `f_registerCoroutine`；不是接受路徑的 loader。 |
| `f_registerCoroutine(co)` | qbase proto 1／`0x090A` | tail-call `qco:registerCoroutine(co)`。 |
| `f_doCoTask()` | qbase proto 2／`0x096A` | `qco:doCoTask(Q.EndCutScene)`，CALL 不保留回值。 |
| `f_removeAllCoroutines()` | qbase proto 3／`0x09D9` | 呼叫 `qco:removeAllCoroutines()`。 |
| `yield()` | qbase proto 4／`0x0A33` | 呼叫 global `wait(0)`；這段本身不定義 wait 的時間單位。 |
| `t_executeCoFunction(f)` | TutorialBase proto 1／`0x0385` | `tco:createCoroutine(f)`，再 tail-call `tco:registerCoroutine(...)`，返回後者結果。 |
| `t_doCoTask()` | TutorialBase proto 2／`0x0406` | tail-call `tco:doCoTask(Q.EndCutScene)`，保留回值給 native caller。 |
| `t_removeCoroutine(handle)` | TutorialBase proto 4／`0x04D3` | tail-call `tco:removeCoroutine(handle)`。 |
| `t_isCoroutineAlive(handle)` | TutorialBase proto 5／`0x0531` | tail-call `tco:isCoroutineAlive(handle)`。 |

因此 `Q.EndCutScene` 是傳入 scheduler 的**函數值**，沒有檔名交付。是否在工作集為空、全部 dead、個別 error 或其他條件叫它，不能只憑這個參數名稱決定。相同方法名在 `qco`、`tco` 上的呼叫，亦不表示它們是同一個實例。[選定 operands 與既有 lifecycle]

### 5.2 Synopsis 的 skip 及 cleanup 是普通順序控制流

TutorialMain proto 7（`PlaySynopsisMain`，code `0x1052`）：

| PC | 原件行為 |
| --- | --- |
| `0..4` | 先 `PrepareSynopsis()`，再註冊 `SynopsisMain`，把返回 handle 留在 R0。 |
| `5..9` | `t_isCoroutineAlive(handle)`；不存活則離開等待圈到 PC 24。 |
| `10..20` | 檢查 skip；skip 分支在 PC 18 呼叫 `t_removeCoroutine(handle)`，清本地 handle，離開等待圈。 |
| `21..23` | 未 skip 時 `yield()`，回到 PC 5。 |
| `24..27` | 清本地 handle，普通 CALL `EndSynopsis()`，RETURN。 |

`PrepareSynopsis`（proto 2）會關 keymap、PushCamera `TutorialCam`、登記 skip image；`EndSynopsis`（proto 4）則 DestroyFlyingObjects、PopCamera、重新開 keymap。這一對在正常控制流與明列 skip 分支可接上，但原 body 沒有 protected-finally 結構。若 parent 本身在到達 PC 25 前遭移除或拋錯，不能從此 body 保證 `EndSynopsis` 必被執行。native 其他退出處是否另行補清理，仍應使用既有 lifecycle 的逐條來源，不能讓這段普通 CALL 冒充所有取消情境的 finally。

### 5.3 Tutorial Part1 與 Part2 的生命週期不相同

TutorialMain proto 8（`TutorialMain`，code `0x11A5`）在 PC `15..17` 將 `Tutorial_Part1` 註冊成子工作並保存 handle。等待中若 control `0` 的 skip 條件成立，順序是：PC `30..34` 清 control flag，PC `35..37` **先** `Tutorial.StopCutScene()`，PC `38..40` **再** `t_removeCoroutine(handle)`。然後離開等待圈，關 checkpoint `1／2／3`、刪除 object `240`。

PC `75..76` 直接取 global `Tutorial_Part2` 並 CALL；沒有第二次 `t_executeCoFunction`。因此 Part2 在此處沿 parent coroutine 的呼叫棧執行，不能沿用 Part1「獨立 handle、只移除此子工作即可」的取消假設。這個差異由 operands 可證，不需要知道 MoCo 內部 wait 單位。

### 5.4 Q 的內容也有顯式 End，不能全部歸給未知 MoCo

qbase proto 74（`RevPhase1`，code `0x2B54`）在若干還原動作後，PC `54..55` yield，PC `56..58` `Q.EnableInput()`，PC `59..61` `Q.EndCutScene()`。這證明既有 content API 已提供明確可呼叫的 Q 收尾路徑；不是所有結束機會都只能等待未讀 MoCo 內部 callback。此 body 仍是普通控制流，沒有因此得到任意錯誤／取消必達 End 的保證。

## 6. 大寫 DoFile、table/global alias 的有界追蹤

本輪不是再對副檔名或小寫 `dofile` 做 grep。`lua_call_sources.py` 對上述 93 個原 prototype 建立保留兩側條件分支的 CFG，追蹤 callable register 的來源：GETGLOBAL、GETTABLE／SELF、MOVE、CLOSURE、CALL result，以及控制流合流。解析器確認這三個 chunks 的 prototype 均無 captured upvalue；沒有遺漏 closure 的 upvalue binding words。

所有原件的 255 個 CALL／TAILCALL 均納入來源索引，來源皆為**常數名稱的 global lookup，或 global table 的常數欄位 lookup**。這三個 chunks 內沒有需要把 callable 解析成未知函式參數／動態欄位鍵的站點；本輪 actual callable origins 也沒有 `global:DoFile` 或 `field(global:lb,constant:"DoFile")`。完整資料見 [callee 來源索引](lua-call-source-index.json) 與 [摘要與限制](call-source-summary.json)。

這個結果的強度只到 lookup origin，不能變成整個程式沒有 loader 的定理：

- global／table 可以被先前或其他腳本重寫；本分析不把它們視為不可變函數 identity。
- MoCo／native callee 的內部呼叫不能由這三份 caller 自動展開。
- table 的 metatable 或跨 chunk 動態賦值不在此資料流模型內。
- 開放參數數量的 CALL 使用可用 register 範圍作保守來源集合，不拿它推算實際執行期參數個數。

因此，Register 接收 closure、把 `Q.EndCutScene` 傳給 MoCo、從 global 查出 Tutorial entry，都是**現存 callable 的傳遞／呼叫**；沒有僅因函數名稱或常數出現就宣告它載入了 `.mef`。本輪只補「這三份核心 Lua caller 到下一層 binding」的明確界線。

## 7. MoCo 原 body 缺口：復用舊完整分析，不冒稱重新解析

main S00 `governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md` 的「兩版啟動 Lua 的檔案讀取範圍」明載：兩版 `boot.lua`、`Logic.lua`、`Coroutine.lua`、`ai.lua` 逐位元組相同，已完整解析 1／1／13／8 個 prototype，未見檔案載入函式引用、含副檔名字串常數或 CONCAT。其 Git blob 為 `e3422673ebd928d90f998b792cb513f10b28b69b`，SHA-256 `dcb12f0ae59e048775841545c111c84379c11a350639d7f44a8c846d4ff5a0bc`；本輪 main 該 blob 與前輪基準相同。

這是應直接沿用的舊成果。它不能支撐的新增問題，是四個尚未有 body 可讀的 MoCo 決策：

| 需要原 body 的端點 | 目前能證的外部呼叫 | 尚不能填的內部契約 |
| --- | --- | --- |
| `wait` | qbase `yield → wait(0)`；內容有其他數值傳入。 | 計時來源、單位、到期比較、一次 tick 可 resume 幾次。 |
| `doCoTask` | qco／tco 都接收 `Q.EndCutScene` function value；native 有固定 tick caller。 | resume 回傳 true／false、dead／suspended、錯誤紀錄／再拋的順序。 |
| 傳入的 End callback | 原件證明它是 `Q.EndCutScene` callable。 | 空集合、最後一個 task、個別錯誤時是否呼叫、呼叫次數。 |
| register／remove | 既有 Lua 對 registerCoroutine、removeCoroutine、removeAllCoroutines 的精確參數流已可讀。 | 迭代時新增／移除、取消目前 task、重入／去重、handle identity 的政策。 |

為找可延伸的原 body，本輪讀取／查找範圍固定於 [carrier-search.json](carrier-search.json)：

1. S00 指向的細節稿 `anal/SHARED-LUA-LOADING-AND-TUTORIAL-BOUNDARY.md` 不在此 main 的 Git tree；不能把舊作者工作區的 `anal` 路徑假稱現有 repo 檔。
2. 指定 `governance/s00-iterations/evidence`、`governance/client-variants`、`shared/integrations`、`research` 的 1,534 個 path metadata，找出的 Lua／prototype 類候選只有既有 KR／TC 各三份 qbase／TutorialBase／TutorialMain JSON。這是尋找 carrier 的 metadata 查核，不是對 1,534 份內容作陰性宣稱。
3. 精確讀了三份發布 JSON：`S00-20261101-AI-MEF-EXECUTION-BOUNDARIES.json`、`S00-20261101-MEF-CONSUMER-RECHECK.json`、`20261107-mef-resume/resources/resource-audit.json`。三份實際讀到的內容均固定 Git blob；沒有 Coroutine 原 body。前兩者是 native 證據，後者是資源 inventory，不能替代 Lua operands。
4. 本輪提供的原件 carrier 是 BIN／EXE 與 Event／Table／BoundMap STP，沒有另外提供當時已讀的 `Coroutine.lua` 散檔或可定位同一 member 的載體。本輪真正可讀、實際解析的三個 Event members，已逐一列在 §2。

**解除條件很具體：**取回 S00 當時兩版目錄中的同源 `Coroutine.lua` 原檔，或附原檔 SHA／carrier mapping 的完整 13-prototype operands，再靜態讀上述四組分支。這個缺口不需要先啟動 Client；也不代表 boot／Coroutine 過去沒分析、現有 loader 陰性無效，或整條 Client 靜態研究都必須停下來。

## 8. 若未來另准新內容：`.seq → DoFile(.mef)` 的技術契約

### 8.1 可行性層級與政策界線

既有 Q selector 可到 `Event/Sequences/<funcName>.seq`；正式 seq 的 `Register` 會把內容 closure 送入可被 tick 的 coroutine。全域 `DoFile` 的資源路徑與 Lua parser 本身沒有以 `.mef` 副檔名另選格式的流程。因此，**若日後另行允許新增內容、資源路徑亦通過既有可見性 gate，能設計一個明確的新 `.seq` caller，在正式執行階段呼叫全域 `DoFile`，載入名稱為 `.mef` 的相容 Lua 內容。** 這是建立新 caller 的條件式技術推論，不是發現原版 MapList caller。

目前 main `shared/CLIENT-MODIFICATION-POLICY.md` 最新使用者限制仍是：不為恢復遊玩修改 Client 主程式或資源，Server 以既有封包與資料補流程。因此本節只提供可審閱內容契約，**沒有製作可執行橋接腳本，沒有新增／修改 `.seq` 或 `.mef`，也沒有宣稱現在已獲准採用這個部署方向**。此政策不阻止本輪已授權的原件靜態分析；亦不要求現在另開確認流程。

### 8.2 兩個 VM 不能共用未區分 phase 的 runtime body

| 階段 | 已證初始化／Register 行為 | 對新內容的要求 |
| --- | --- | --- |
| prepass | `55C610` 另外建立 state；沒有走 `6F4380` 正式建構／開標準庫；`55D7E0` 掛 72 個空 globals／有限 Q table，`55D6A0` 加 6 個 collector binding。其 `Register → 55D560` 會**立即執行傳入函數**。 | callback 必須有限完成，不能當成只登記而不跑；不能依賴正常 wait／yield 等待條件變化。 |
| formal | 正式 wrapper `6F4380` 開庫並註冊全域 `DoFile → 6F48A0`；qbase `Register` 建立 coroutine 後登記。 | 真正等待、場景動作與 module entry 可在 formal 工作中進行，但仍受 native gate、scheduler 與取消界線限制。 |

已核 prepass 的 72＋6 binding 名單不含全域 `DoFile` 或 `lb`。因此，依這份**初始環境**，可以把「只有正式環境可用的載入 capability」當新內容的 phase guard 設計基礎。這不是引擎原生 phase API：prepass state 會存續，globals 可被腳本重綁；僅檢查一個名稱是否存在，也不保證它永遠綁到原 callback。設計必須控制 namespace 與載入順序，並在 formal 分支核對所需介面。prepass guard 本身不可依賴該 VM 未初始化的標準庫函數。[沿用 constructor／prepass anchors、prepass-bindings；此節沒有提出未核原件的可執行語法]

module 如果只在 formal 階段讀入，其物件／動畫／音樂等依賴就不會自動出現在 prepass 的 collector 結果。需要在 seq 可達的 prepass 路徑提供明確、有限的依賴收集；不能一律 skip prepass，再假定 formal 呼叫 native 動作時所有依賴都已準備好。

### 8.3 DoFile 的頂層 chunk 不宜直接執行會 yield 的場景流程

原件可證的 coroutine C 邊界是：

| 原件 | 欄位／分支 |
| --- | --- |
| `6FE70E..13` resume | 將遞增後的 `L+0x34` 記到 `L+0x36`，作此次 resume 的深度基準。 |
| `6FE55B` call engine | 進一步呼叫 chunk 時遞增 `WORD[L+0x34]`；正常返回再遞減。 |
| `70748B..96` yield | 比較目前 `L+0x34` 與 `L+0x36`；大於基準時不走可 yield 分支。 |
| `707498..9E` | 走 C-boundary 錯誤字串與 Lua error 函數 `6F8B60`。 |

全域 DoFile 在當前 `L` 內經 `6F49F4 → 6FE770`，由 `6F5A50 → 6FE550` 執行頂層 chunk，會增加這一層深度。因此不能假定「在 coroutine 裡呼叫 DoFile，module 頂層即可直接 yield 穿回 scheduler」。這裡的限制是同一 coroutine 在 DoFile 保護執行中的直接 yield；不是宣告所有另建 coroutine／resume 的用法都被禁止。[沿用上述五個 parser anchors，驗證器另核 operands]

較可控的內容契約是：module 頂層只建立資料／函數並有限返回；DoFile 回到原本 seq coroutine 後，再由外層 Lua **直接**呼叫本次匯出的 entry。這樣不再讓該 entry 跨過 DoFile 的 C 執行層。它仍不自動補上 MoCo 內部 wait 單位、錯誤捕獲、重入／取消策略的未知，也不能隨意以會新增 C 邊界的 protected wrapper 包住可 yield entry 而假稱相容。

### 8.4 可供後續實作審閱的最小契約

| 項目 | 必需決定／確認的內容 |
| --- | --- |
| 入口與資源版本 | 明確 SceneList key、funcName、seq 邏輯路徑、module 固定路徑、彼此版本及 resource gate；不能只送一個裸檔名。 |
| 格式 | module 是此 build 可讀 Lua source／相容 Lua 5.1 chunk，外層 STP／EX 由資源契約另外規範；副檔名不是格式證據。標為新內容，非原生 MEF 格式還原。 |
| prepass | 明確 phase guard 假設與必要依賴 collector；有限執行，不把 wait stub 放進無窮輪詢。 |
| loader | 使用已核當前 L 的全域 DoFile；比較 numeric status `== 0`。不能拿 `lb.DoFile == 0` 排除 missing file。 |
| module 匯出 | 約定自己使用的 global／table namespace；載入前更新／清除本次匯出位置，成功後驗證版本／entry；不透過 DoFile return value 取得 module。 |
| 頂層副作用 | 頂層有限定義、不直接等待／yield，不假設 parse／runtime error 會回滾既有 globals 或先前 native side effects。 |
| 正式 entry | 在已登記的 seq coroutine 內直接叫當次匯出 entry；若要再巢狀 Register，須補 MoCo 迭代與重入政策。 |
| 失敗／取消 | 對 loader failure、缺匯出、entry 中途錯誤、skip、scene 切換各自列出誰負責明確 End／camera／input 恢復；不要使用「status=0」統包這些狀態。 |
| Server 相容介面 | 既有 selector／情境 state 的 wire、發送順序、版本與重複事件處理沿用對應證據；不新增未證 opcode 或腳本完成 ACK。 |
| 驗證 | 目前僅靜態可行性；後續若獲准實作，須以相同 BIN／資源版本驗證雙階段、missing／syntax／runtime error、stale export、skip／取消、重入與正常完成。 |

這可支持「新內容橋接有具體技術契約可設計」；不能支持「原版現在就會抓 `.mef`」或「只傳 `.mef` 即可由 Client 接手原本 Server 規則」。

## 9. 完成狀態與 Server 開發交接

| 分類 | 本輪狀態／待辦 | 精確界線 |
| --- | --- | --- |
| Client 已證外部契約 | native loader status、DoFile numeric／MULTRET ABI、entry 失敗後續控制流、Q active／missing-row 差異、tick status 忽略、Lua 顯式 skip／cleanup／reentry 形狀。 | 來源是固定原件；不包括未讀 MoCo body。 |
| Client 待逆向／原件不足 | §7 四組 MoCo 內部決策；原生 MapList／`.mef` 正向 caller 仍由主線結論保留。 | 取回指定 Coroutine 原 body 可推進前者；不以「需要 runtime」籠統取代。 |
| Server 待開發 | 對既有場景／教學情境提供正確 selector、必要資料與 state、觸發順序、重複事件策略、進度／持久化與相應回覆；Client 本地 status 不當作 Server ACK。 | Server 可自行設計業務政策，但 wire／欄位／Client gate 仍須引用已證相容介面，未知者保留未知，不猜官方規則。 |
| 跨功能待整合 | resource 可見性與版本、既有 selector 到合法 seq、prepass 依賴、formal 執行、原有 skip／exit／完成回包的各層邊界。 | 與主稿的資源 gate、parser producer 結果合併；本節不是新需求台帳。 |
| 待遊玩驗證 | 載檔失敗後 actual stack／flags、實際 task 時序、取消／再入、正常 entry 到完成的 trace。 | 尚未執行 Client／Lua；靜態推論不宣稱通過。 |
| 條件式新內容設計 | §8 可先保存可審閱契約；現行政策未允許改資源。 | 不作為當前原版 Server-only 恢復流程已具備的替代 caller。 |

只為尋找天然 `.mef` caller 而停止既有 Q／Tutorial Server 整合，沒有必要；那些已證 Client 介面可以繼續開發。另一方面，不能把 Server 尚需提供的規則、資料與持久化政策，轉成「放進新 `.mef` 就會自動完成」的未證假設。

## 10. 交付與重驗

可提交檔案：本報告、`source-manifest.json`、`carrier-search.json`、`native-windows.json`／`.asm`、`selected-lua-evidence.json`、`lua-call-source-index.json`、`call-source-summary.json`、`lua_call_sources.py`、`verify_evidence.py`、`verification-result.json`。不提交 `navigation-scratch.json`、完整解碼 originals 或僅供本地產生檔案的 `build_evidence.py`。

以下命令只讀原件與證據；輸出路徑須指向新產物，不覆寫 originals：

```bash
python -B verify_evidence.py \
  --originals /path/to/project_sources \
  --repo /path/to/ttr_anal_multi \
  --out /path/to/verification-result.json
```

若 repo 是 sparse checkout，未落地的參考文字可透過 `--reference-text-cache /path/to/main-source-text.json` 提供，格式是 `{ "repository/path": "exact file text" }`。驗證器逐份核對參考文字 bytes／SHA-256／Git blob；沒有提供的文字明記 `NOT_READ`，不冒稱全文複驗。原件 BIN／STP 與所有必要本輪 operands 必須存在並相符。

本輪實跑結果：3 members、93 prototypes、1,536 words、255 callable source sites、20 selected prototypes、16 本輪證據窗、16 沿用 native anchors、45 native contract assertions、14 Lua contract assertions；12 份參考文字 exact match、0 份 NOT_READ。完整機讀結果見 [verification-result.json](verification-result.json)。此驗證不執行 Lua、不檢測完整遊玩，也不認證不存在其他動態 caller。
