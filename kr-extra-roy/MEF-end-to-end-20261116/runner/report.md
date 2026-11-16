# 普通戰鬥 Lua runner：callback 事件來源、公開 input 介面與 Q pause 的有界閉合

## 1. 結論與本輪新增進度

**普通 Mission／Scenario 戰鬥中，具有合法入口、持續 pump、普通輸入保留及 owner stop 的背景 `.mef` runner，仍未由已查公開介面閉合。** 已有 Q、Tutorial、Expedition 特定支線與 ScenarioReview 的 runner 契約沿用前稿。本輪沒有重新把 checkpoint 或一般 UI tick 的舊讀集列成新發現。

本輪補完三個具體問題：

1. `debug.sethook` 確實能登記 Lua callback，但其 `count` 是 **Lua 指令派發次數**。已追到 call、return、line、count、tail return 的真正 native producer，以及 callback consumer；這組機制需要 Lua 已經在執行，沒有提供一個獨立的 Client frame／時間來源。[H01–H10、D01–D02]
2. `Tutorial.SetKeymapEnabled` 與 `lb.ChangeKeymapType` 的公開名稱、closure、參數轉換、native 效果已串起來。兩者讀最後一個 Lua 引數，只對 number／可轉數值 string 做整數轉換；Lua boolean 走 native `0`。因此 `SetKeymapEnabled(true)` 不能等同數值 `1`，而且這些介面都沒有解除 Q 的 controller busy ownership。[I01–I10]
3. Q 的 `M+0x2C` 絕對位址參照已限定掃描範圍並核回原指令：只有 constructor 清零。更關鍵的是，Q tick **先寫 controller+0x58，再檢查 M+0x2C**；即使日後找到合法 pause writer，單純暫停 Q coroutine 仍不會繞過前面的輸入抑制。[Q01–Q02、scoped-xrefs.json]

以上可直接用於 Server／內容契約與離線檢查器；不能改寫成「全 Client 不存在其他 runner」或「普通戰鬥 `.mef` 已可直接開發並驗收」。沒有執行 Client、Lua、遊戲資源或腳本，沒有改寫原件。`verification-result.json` 的 PASS 僅代表下面保存的靜態 bytes、解碼、關係與來源 pin 通過驗證。

**位元用語：本文的 input lock 指 mask 數值 `0x2`，即從零起算的 bit index `1`；不是 `1 << 2`。** 部分前稿或機讀欄位沿用「bit 2」簡稱時，也應按數值 `0x2` 解讀。

## 2. 證據、來源與實際覆蓋範圍

原件為 `02-Tartaros.bin`，12,472,320 bytes，SHA-256：

`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`

格式為 PE32 i386、ImageBase `0x00400000`。原件 machine code 優先於 bulk C；C 只用於導航。新增證據保存於 [native-windows.json](native-windows.json) 和 [native-windows.asm](native-windows.asm)，共 **43 個 code／data／string records、5,219 bytes，其中 31 個 code windows**。每段都有 VA、exclusive end、raw offset、完整 hex、SHA-256，code window 另有逐指令 bytes 與反組譯。

固定來源分為兩組，均可在 [source-manifest.json](source-manifest.json) 重驗：

| 來源 | 固定 commit | 用途 |
|---|---|---|
| 精確 main 的 bulk C | `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` | 145 個導航來源；不以偽碼替代原件證明 |
| 公開同 tree merge 中既有 MEF 證據 | `15819c892c0a9a23924704daa5883615a09626bf` | 9 個報告／機讀資料來源；明示復用，未冒稱本輪新發現 |

原本機研究父提交為 `b0bf6bb5986f9c849fcfac4e16db42f0a1cf960c`；來源 blob 不變，公開提交 metadata 的對照見 [publication-note.md](../publication-note.md)。

這 154 個 pin 保存 commit、path、Git blob、bytes、SHA-256。檔案可讀不代表其所有語義都經本輪重新證明；新主張以本文 H／I／Q record 指定的原件窗口為界。

### 2.1 復用的已閉合工作

| 既有證據 | 本輪直接沿用的契約 |
|---|---|
| `MEF-runtime-contracts-20261115/scheduler/report.md` | MoCo register／resume／yield／remove；`wait` 的毫秒時基；正常完成、失敗及 list mutation 的差別 |
| `MEF-runtime-contracts-20261115/vm-lifetime/report.md` | 正式 wrapper、VM 共用／壽命；移除 task 不等於關閉 VM |
| `MEF-runtime-contracts-20261115/input-lifecycle/report.md` 與 `tables.json` | Q 公開 63 筆 regular bindings、Q input mask、controller+0x58、frame 順序、End／Stop／00EB 的不同效果 |
| `MEF-world-integration-20261115/runner/report.md` | T runner 三個具體 direct caller、Tutorial／Expedition／review owner 與限制 |
| `MEF-content-contracts-20261116/ordinary-runner/report.md` | 普通 field/page 的已查 native tick；checkpoint／UI tick 的有界排除，不在本輪重做 |
| `MEF-trigger-callers-20261115/named-calls/report.md` | 三種 named-call wrapper 的 caller、固定名稱與引數來源 |
| `MEF-complete-flow-20261115/parser-executor/report.md` | parser／executor 入口清冊、標準庫 hook 註冊與 callable consumer 的先前證明 |
| `MEF-entry-lifecycle-events-20261114/lifecycle.md` | Q start/end 的既有生命週期與事件邊界 |

### 2.2 Q 公開介面的實際核對邊界

[public-surface-review.json](public-surface-review.json) 保存完整 63 筆既有 Q binding 索引，包括名稱、registrar、Lua closure、native target。這避免用關鍵字無命中取代對真實 binding target 的檢查。

其中 59 個 native target 有本輪讀取的精確 main bulk C 導航 body；另 4 個沒有獨立 bulk body 的方法直接取原件完整小函式：

| 公開方法 | Native | 本輪原件所見 | Record |
|---|---:|---|---|
| `IsCutSceneRunning` | `489CF0` | 直接回傳 receiver+0x28 | Q03 |
| `IsAllObjectsStopped` | `564880` | 遍歷 receiver+0x1C 的 Q-owned object tree，檢查物件 word+0xE2 的 `0x8000`；空樹返回 1 | Q04 |
| `ShowLetterbox` | `564B00` | 設定獨立 presentation flag `FE36EC`，含初始化分支 | Q05 |
| `HideLetterbox` | `564B50` | 清除同一 presentation flag，含初始化分支 | Q06 |

這個表面包含真正的 Start／End、input enable／disable、camera、Q scene objects、文字／音樂／特效與 Q-domain query；**沒有因此取得普通 world 的 task owner、無 Q busy 的 pump，或 M+0x2C 的公開 writer 契約。** 59 個導航 body 不構成所有 callee／alias 的形式化閉包；四個補取小函式也不是新的世界實體 observer。Q rebind 可以改 binding receiver，既有證據已指出它不會同時改 native frame loop 固定使用的 singleton，不能當作合法新 scheduler。

## 3. `debug.sethook` 的完整 producer → consumer

前稿已證 `debug.sethook=701510` 和 `701320` hook consumer。本輪新增的是**什麼時候產生 callback，以及誰負責推動它**。

### 3.1 登記的是 thread 的 hook 欄位

`701E00` 將標準 debug 函式表交給註冊器；`C0BE90` 這一列是 `sethook` 名稱 pointer 與 native `701510`。[H15、D02、S06、S10]

`701510` 先判斷第一個引數是否為 thread（TValue tag 8）。是 thread 時採該 thread 為 target，否則以目前 L 為 target。非空 hook 要求 function tag 6；mask 由 `701400` 解析小寫 `c`、`r`、`l`，count 大於零才增加 `0x8`。[H01–H02]

| Thread 欄位 | 已證意義 | 主要讀寫位置 |
|---|---|---|
| `+0x38` byte | hook mask | `7016AB` 寫；`6FC597`、各 call／return producer 讀 |
| `+0x39` byte | 同 thread hook 執行期間的 reentry guard | `6FDE83/6FDE92`、`6FE474/6FE483` 清零／恢復 |
| `+0x3C` dword | base instruction count | `7016AE` 寫；`6FB67F` 讀 |
| `+0x40` dword | 剩餘 instruction count | `7016B1` 寫；`6FC59E` 遞減；`6FB68B` 重設 |
| `+0x44` pointer | native hook callback | `7016A8` 寫 `701320` 或零；dispatcher 間接呼叫 |

`701450` 取得／建立 registry 中由 lightuserdata `C081DF` 索引的 hook table；`701510` 再用 target thread pointer 作 lightuserdata key，存入 Lua hook function。傳 nil／無 hook 或有效 mask 為零時，native callback 和 mask 被停用。這是 thread hook 的設定／解除，並沒有建立 timer、Client frame owner 或持續 resume 來源。[H02–H03]

### 3.2 五種事件都來自已執行中的 Lua 流程

| Event 值 | 傳給 Lua 的名稱 | Mask 數值 | 真正 producer | 事件發生條件 |
|---:|---|---:|---|---|
| 0 | `call` | `0x1` | `6FE2D1`、`6FE34C` → `6FDDE0` | `6FE1C0` 正在建立 Lua／C function call |
| 1 | `return` | `0x2` | `6FE3C3` → `6FDDE0` | `6FE4C0` 的 return 路徑檢查 mask，進 `6FE3A0` |
| 2 | `line` | `0x4` | `6FB6E7` → `6FDDE0` | 已執行 opcode 的 PC／prototype line 比較符合條件 |
| 3 | `count` | `0x8` | `6FB68E` → `6FDDE0` | instruction count 已到零，先重設 count，再通知 |
| 4 | `tail return` | `0x2` | `6FE478` 間接 callback | return helper 處理已記錄的 tail-call 計數 |

名稱與 enum 順序由原件 `C0BE08` 的五個指標及字串核對，不以外部 Lua 版本文件推定。[D01、S01–S05、H06、H08–H10]

最直接的時基證據在 `6FC550`：`6FC58E` 取下一個 opcode，`6FC590` 推進 PC；若 mask 含 line／count，`6FC59E` 對 **L+0x40 執行 `dec`**，條件成立才於 `6FC5AE` 呼 `6FB660`。這發生在 `6FC5F1` 的 opcode jump table 派發前。`6FB660` 的 count 分支將 L+0x3C 複製回 L+0x40，然後以 event 3、line=-1 呼 dispatcher。[H05–H06]

因此，`count=1000` 表示這套 instruction counter 的門檻，不能翻成 1000 毫秒，也不能翻成 Client 1000 frames。`wait` 的 `lb.GetTime` 時基屬於前稿另一條契約；此處沒有把兩者接成同一個 native pump。

### 3.3 callback 是同步執行；同 thread 的再入被關閉

`6FDDE0` 讀 L+0x44 且檢查 L+0x39。滿足時準備 event／line 結構、暫存 stack 邊界、將 L+0x39 設零，於 `6FDE87` 呼 callback，正常返回後恢復 guard 與 stack 邊界。tail return 的 `6FE3A0` 有另一份 inline dispatch，於 `6FE478` 呼同樣來源的 callback，不能只掃 `6FDDE0` 的 direct callers 就漏掉這條邊。[H07、H09]

`701320` 依目前 L 的 thread pointer 找到 hook table 中的 function，推入 event name，以及 line number 或 nil，於 `7013EC` 同步交給 `6FE550`，要求零個結果。它沒有把 coroutine 放入另一個 native queue，也不會自行等待下一幀。[H04]

這裡可確認的是**同一 thread hook 執行期間**的 guard；沒有將它擴大成所有 threads 都被全域禁止。其他 native 入口若再次使某個 Lua state 執行，仍可能產生相應 hook 事件。

### 3.4 新 coroutine 的 native 欄位複製，不等於 Lua callback 自動繼承

`coroutine.create=707380` 呼 `6F7390` 建立 thread。`6F7390` 在初始化後，複製 parent 的 mask、base count、native hook pointer，並將新 thread 的 remaining count 設為 base count；新 thread 的 stack 初始化在 `6F7200`。[H11–H13]

這段 constructor／stack initializer 沒有呼叫 hook table setter。與 `701320` 以**目前執行 thread pointer**作 key 的 consumer 合併看，可得有界結論：**只在 parent 設 hook，不能將 parent 的 Lua hook function 自動視為所有 child 的 hook function。** 已保存的建立路徑複製 native 欄位，沒有複製那筆 thread-keyed Lua callback entry。若另一條程式明確替 child 登記／填入 entry，須另列其 producer；本輪沒有假設 runtime table 永遠不能被改動。[H02–H04、H11–H13]

對普通 runner 而言，`debug.sethook(thread, ...)` 能指定 callback 所屬 thread，卻不能令 suspended thread 自行 resume。所有已閉合事件仍須先進入 Lua 執行流程。

### 3.5 為何這仍不是普通背景 runner

已知 native named-call 會在其原有事件中啟動 Lua，因此 hook 可搭在那些執行上。不能把本輪結果說成「Q inactive 後永遠沒有任何 Lua／hook」。例如既有角色說明查詢或 UI callback 可能再次進入同一 VM；前稿已保存其固定名稱與引數來源。

真正欠缺的是：**普通 field 中有 owner、有持續節奏、Q inactive 時仍可靠運作，且不依賴 Tutorial／review／特定 UI 事件的 native producer。** 將 hook 登記完成，沒有證明這個 producer 已出現；在目前 Lua 呼叫內自行循環，也沒有建立讓 Client frame 繼續前進的外部 pump。hook 可作既有執行的觀察／同步 callback 機制，其靜態契約不能當成普通戰鬥 scheduler 的驗收。

## 4. 公開 input 介面的真實 ABI 與效果

### 4.1 兩條完整 binding 鏈

| 公開名稱 | 登記與 target slot | Lua closure → converter | Native |
|---|---|---|---|
| `Tutorial.SetKeymapEnabled` | `4AA900`，`FE1818 = 4A94C0` | `4AC030 → 4ACB70` | `4A94C0` |
| `lb.ChangeKeymapType` | `4A1DD0`，`FE17B0 = 4A1440` | `4A2380 → 4A23E0` | `4A1440` |

名稱字串、closure push、target slot store 均由原件核對。[I01–I03、I05–I07、S07–S08]

兩個 converter 都將 EAX 設為 `-1`，呼 `6F50F0`。原件 `6F510F–6F5115` 顯示 ordinary negative index 轉為 `L.top + index*0x10`，因此取的是**最後一個 Lua 引數**，不是固定第一個引數。隨後只接受 tag 3（number）或 tag 4（string，且數值解析成功）；數值經 x87 `FISTP` 轉成 native integer。其他 tag，包括 Lua `true`／`false`，直接把 `0` 交給 native。[I03、I07、I10]

`FISTP` 的具體捨入依當時 x87 控制狀態；不應把它擅自改寫成已證的向零截斷。內容契約採精確整數 `0`／`1`，即可避免對小數捨入的額外假設。也不要利用「最後一個引數」行為默許隨意多傳參數。

### 4.2 `SetKeymapEnabled` 的數值與布林不能混用

在 input singleton 已初始化的正常路徑：

| Lua 最後引數 | Native 值 | `4A94C0` 所做的事 |
|---|---:|---|
| number `1` | 1 | `FB8830 &= 0xFFFFFFFD`，清除 mask `0x2` |
| number `0` | 0 | `FB8830 |= 0x2`，設定 input lock |
| boolean `true` | 0 | 同樣設定 input lock |
| boolean `false` | 0 | 同樣設定 input lock |
| 可解析的數值 string | 轉換結果 | 再依 native 零／非零分支 |
| 其他 tag／無法解析字串 | 0 | 設定 input lock |

清除 `0x2` 不會清掉 input mask 的其他位元。函式也包含 `6D0750` 的既有 lazy initialization 分支；這不是一個 Q stop 或 controller ownership 切換。[I04；既有 input-lifecycle]

另外，兩個 Lua closure 都在 converter 返回後宣告 C result count `1`；本輪所核的正常 converter／native 路徑沒有 push 一個新的 Lua result。因此依該 stack 路徑推得，回到 Lua 的是原本最後一個引數，**不應拿這個回傳值當作已成功解鎖或 runner 已停止的 acknowledgement**。這是有界 stack 推論，沒有執行腳本驗證；證據與該分類保存在 `R9-INPUT-RETURN`。[I02–I04、I06–I09]

### 4.3 `ChangeKeymapType` 只切換按鍵對映

`4A1440` 只接受 native 整數 `0` 或 `1`；其他值在已初始化情況下略過 copy。來源為 `FB8834 + type*0x280`，目的為 `FB8D34`，交 `6D1BE0` 複製。helper 迭代 40 個 stride `0x10` 的 vector 元素，處理各 vector 的資料／end／capacity 與需要的配置、複製。[I08–I09]

這個操作沒有將 `M+0x2C` 設成可用的 pause 狀態，也沒有寫 current controller+0x58。`ChangeKeymapType(true)` 的 native 值為零，會選 preset 0；不能把 Lua boolean 當成 preset 1。這是可直接落在內容型別檢查器的規則，與是否有合法 ordinary pump 是兩個不同的契約。

## 5. Q pause 與 input ownership 的先後順序

本輪使用以下 owner：Q manager `M=FB73C0`；active=`M+0x28=FB73E8`；pause gate=`M+0x2C=FB73EC`；input mask=`FB8830`；current controller pointer=`[FBA7A4]`。既有 frame 順序與普通 controller consumer 沿用 input-lifecycle 報告。

`561520` 的原件順序是：

1. `561587` 檢查 `M+0x28`。
2. active 非零時，`5615C4` 將 current controller+0x58 寫為 1。
3. **接著**在 `5615C7` 檢查 `M+0x2C`。
4. pause 為零時才於 `5615D8` 呼固定 `f_doCoTask`；pause 非零則略過該 Lua pump。[Q02、S09]

所以公開 input helper 清除 mask `0x2`，沒有移除 Q active 在每個 tick 寫入的 controller busy。Q pause 也沒有把前面的 busy store 變成條件之外的動作。普通 controller 如何抑制命令、尾端如何清除 busy，以及主更新先後，已由前稿原件閉合；本輪只補進這兩個公開 alias 與 pause writer 讀集，沒有重做同一份 frame 分析。

### 5.1 `M+0x2C` 已查到哪裡

對 raw-backed `.text`、`.rdata`、`.data` 的所有 byte alignment 搜尋 32-bit little-endian `FB73EC`，只得到 operand VA `560241`。其完整原指令在 `56023F`：`mov [FB73EC], ebx`；同一 constructor 的 `560197 xor ebx,ebx` 證明這是清零。`M+0x28` 也在緊前方清零。[Q01、scoped-xrefs.json]

這只能封住**此常數的絕對參照讀集**。透過 `M` alias 加 `0x2C` 的相對寫入、計算式位址、外部模組或 runtime 指標變動，不會必然帶有這個四位元組 literal。因此本輪沒有宣稱「整個程式只有一個 writer」。已知 relative reader `cmp [edi+0x2C],0` 則明確由 Q02 保存。

63 筆公開 binding 索引及其具體 target 導航，沒有建立一個可合法呼叫的 ordinary pause／input-owner API。即使後續找到 `M+0x2C` writer，仍須解決前面的 controller+0x58 store，不能把「找到 pause」直接視為 ordinary runner 完成。

## 6. start、pump、stop 的既有閉合與剩餘缺邊

下表將已可用契約和普通背景 runner 的未證項目分開；舊項目引用固定來源 pin，不列為本輪新增 reverse engineering。

| 項目 | 已閉合的既有行為 | 為何還不能作普通背景 runner |
|---|---|---|
| Q start | `561760` 在正常分支建立 scene active；busy 分支不形成待執行 queue；loader／依賴與 seq 流程見既有稿 | active 在 script load 失敗後仍可能保留；成功開始場景不等於保留普通控制 |
| Q pump | `561520` 按 active／pause 呼固定 `f_doCoTask` | 同一分支先寫 controller+0x58 |
| Q End | `561DB0` 的 review／normal、003F／confirm／coroutine 清理分支已有原件契約 | end、input unlock、dialog wait 與 task 清理不是同一事件 |
| Q Stop／unlock | `5624B0`、`562250`、`Tutorial.StopCutScene` 與 S2C 00EB 的既有差別已定型 | 00EB 的解鎖不等於 stop Q；Stop 後 End 路徑可能再加 input lock，須遵守實際 ordering |
| T pump | `4A8B90` 呼固定 `t_doCoTask`，三個 direct caller 已閉合 | Tutorial 替換 field/controller；Expedition 特定條件與 review UI owner 不等於普通 field 常駐 owner |
| MoCo stop | remove-all 換 list，正常返回與 dead coroutine 的處理已有契約 | list removal 不自動 unwind 當前執行中的 task，也不替世界狀態／UI／輸入做通用 rollback |
| debug hook | 本輪閉合登記、五事件 producer、thread-keyed consumer | 無獨立時間／frame 來源，且 owner stop／ordinary reachability 未建立 |
| 兩個公開 input alias | 本輪閉合名稱、參數 ABI、mask 或 keymap copy | 都沒有取得 ordinary task owner 或解除 Q controller busy |

普通地圖切換本身也不能一律當成 Q stop；共享 VM 的 globals 可能仍存在，與 coroutine 是否仍被 pump、是否已取消，需要分別記錄。[既有 lifecycle、vm-lifetime、input-lifecycle]

## 7. 明確的排除範圍與解除條件

本輪 raw E8／E9 census 只針對 5 個新關注 target，並逐一核回有效指令邊界：

| Target | E8 callers | E9 | absolute literals | 本輪判定 |
|---|---|---:|---|---|
| `6FDDE0` | `6FB68E`、`6FB6E7`、`6FE2D1`、`6FE34C`、`6FE3C3` | 0 | 0 | line/count、call、return，全部在 Lua 執行流程 |
| `6FB660` | `6FC5AE` | 0 | 0 | opcode dispatch 前的 line/count producer |
| `6FE3A0` | `6FE4D3` | 0 | 0 | return path；另含 `6FE478` inline indirect callback |
| `701320` | 0 | 0 | `701635`、`701715` | 第一筆是 sethook 的 callback immediate；第二筆是 gethook 的比較 immediate |
| `701510` | 0 | 0 | `C0BE94` | debug registration table 的 function pointer |

literal 表列的是 **operand VA**；例如 `701715` 所在指令起點是 `701714 cmp eax,701320`，不是第二個 hook 安裝者。[H14、scoped-xrefs.json]

上述掃描不包括計算式 indirect target、外部模組實作、完整 object alias recovery 或未知 runtime 全域覆寫。本輪沒有擴張到全 UI 或所有標準庫；既有 native execution caller 清冊有明確 fixed-name／argument dataflow，直接復用。已查線索的排除理由是 producer／owner 的具體限制，不是函式名稱或字串無命中。

| 剩餘精確缺邊 | 需要什麼證據才解除 | 目前不能替代的材料 |
|---|---|---|
| 普通入口 | 普通 field 可達的 native producer，接到具體 Lua 名稱／檔案／參數與正式 VM | 任意 function pointer、臆測新 Server 字串命令 |
| 普通 pump | Q inactive、沒有 Tutorial／review owner 時，仍由真正 frame／時間來源持續呼 ordinary task | hook 登記成功、手動 resume 一次、偶發 UI 查詢 |
| input ownership | 實際 API／owner 契約，同時保留 input mask 與普通 controller 命令組裝 | 僅清 mask `0x2`、切 keymap、或假設能寫 Q pause |
| stop／取消／重入 | 普通 owner 在 map switch、死亡、斷線、重入時的可達清理，及 field／controller 恢復順序 | VM global 還在、只刪 MoCo list、只收到 00EB |
| M+0x2C 相對 writer（若方案依賴它） | 具體 pointer provenance、writer、公開 caller 及讀寫順序 | 唯一 absolute literal 結果；且找到 writer 仍不足以越過 controller busy |

後續應以這些缺邊出現新的實際 consumer／producer 為擴張條件。再次重掃同一 checkpoint／UI tick，或只重新列 Q／T 名稱，不會解除它們。

## 8. Server 與內容開發可直接採用的要求

1. **既有 scene orchestration 可開始實作。** Server 對合法 scene 的 start、confirm、end、unlock 建立明確狀態與當次 context，分別處理等待／清理／輸入恢復；遵守既有 003F、00EB 與 scene 分支契約，不把一種封包或 Lua setter 回傳值當成全流程完成。
2. **內容與離線工具加入型別規則。** 兩個公開 input alias 使用單一整數 number；`SetKeymapEnabled` 以 `0`／`1` 表意。把 Lua boolean、額外引數、setter 回傳當 acknowledgement 等情況列為可檢查的不相容用法。hook count 的單位標為 Lua instructions，與 `wait` 毫秒分開。
3. **普通戰鬥權威邏輯由 Server 需求表承接。** Server 權威規則，以及已證 world/entity／quest 協定中的狀態、回覆與取消流程，明列為 Server 開發需求。尚未找到或尚未閉合的 Client trigger、world query、result observer／callback 介面，仍列為 Client 待逆向契約；不能將它們改稱 Server 可直接補上的 wire 功能。本分題不虛構 Client 已支援任意 Lua／MEF 命令，也不要求以改 Client 記憶體補接。
4. **普通背景 MEF runner 保留未建立狀態。** 新內容若要求普通戰鬥中持續執行，必須先補第 7 節的入口、pump、input ownership、stop 證據；不能只因 parser 能讀、Register 能建立 coroutine，就把整條玩法流程視為已驗收。

## 9. 交付檔與唯讀重驗

| 檔案 | 內容 |
|---|---|
| [report.md](report.md) | 本報告，含完成範圍、原件主張、推論與未證缺邊 |
| [native-windows.json](native-windows.json)／[native-windows.asm](native-windows.asm) | 精確原件 windows、hex、VA/raw/hash、逐指令解碼 |
| [contracts.json](contracts.json) | 6 項新契約、5 種 hook event、thread 欄位、2 個 input alias、9 條關係與開發／未知分界 |
| [scoped-xrefs.json](scoped-xrefs.json) | 5 個 hook target 的 bounded E8/E9/literal census、Q pause literal、inline callback |
| [public-surface-review.json](public-surface-review.json) | 完整 63 筆已證 Q binding 索引與本輪導航／補取範圍 |
| [source-manifest.json](source-manifest.json) | 154 個固定 Git source pins |
| [verify_evidence.py](verify_evidence.py) | 僅讀原件／本包／本地固定 Git objects；不 fetch、不執行 Client／Lua |
| [verification-result.json](verification-result.json) | 實際執行上述 verifier 的結果 |
| [deliverables-manifest.json](deliverables-manifest.json) | 交付檔的 bytes／SHA-256 |

可從任意工作目錄執行：

```bash
python /path/to/runner/verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --repo /path/to/ttr_anal_multi
```

驗證器核對 BIN identity、PE mapping、全部保存 bytes、完整指令邊界與 objdump 重現、bounded caller sets、關鍵 instruction／table／field edges、機讀 enum 與關係、固定 commit/tree/blob/SHA-256。固定 Git object 若不在本地，會失敗且不嘗試抓取。這個 PASS 不包含 runtime 遊戲驗收、全程式 runner 不存在證明或 T01 FULL-PASS。
