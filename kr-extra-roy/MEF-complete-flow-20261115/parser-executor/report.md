# MEF 完整流程補查：最底層 parser、reader 與直接執行入口

## 1. 結論與本輪範圍

**本輪沒有找到新的「遊戲資料／Server 內容 → script bytes → 首次執行」入口，但把兩個容易漏掉的原生分支界線具體縮小了。**

第一，直接從 text parser `70E420`、binary parser `70D680` 與 memory reader `6F70E0` 反查，在下述有限搜尋範圍內，兩個 parser 只回到已知的 `6FE860` 首 byte 分流；memory reader 的六個實際使用點也均回到已有 producer 分類，沒有另一個未歸類的遊戲 reader。

第二，直接從 `6FE550` 與 `6FE1C0` 反查，找到 **20 與 4 個 E8 呼叫點**。這些執行點確實能呼叫函式，但其輸入分別來自已存在的 Lua stack、metatable、registry、標準庫 callback、VM register 或 coroutine。對可能被誤認為通用 game wrapper 的 `6F64F0`、`6FB700`、`6FB7B0`、`70C4C0` 等，本輪已穿透到實際上游及函式值來源，沒有以「位址在 Lua 區域」作為排除理由。

這個結果增加的是**指定入口集合的覆蓋證據**，不是「整個 Client 不可能從別處載入 MEF」的全程式否定。既有 Lua 若改寫 global／metatable／registry，或將 loader 當 callback 傳入，仍可能改變後續呼叫；要把這種能力提升為現成遊戲觸發鏈，仍須具體的寫入者、正常觸發者與內容 producer。

### 1.1 原件與來源 pin

| 項目 | 固定版本 |
|---|---|
| 原件 | `project_sources/02-Tartaros.bin`，12,472,320 bytes |
| SHA-256 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| PE | i386 PE32；ImageBase `00400000`；VA 經原件 section table 換算 raw offset |
| 本輪導航偽碼 | main `909754f28bd2e54c8ede00e3a56021cf59facd14`，`kr-bulk-roy/<原件SHA>/functions/0x....c` |
| 復用已發布分析 | extra/roy1 `67021e609f56e45981aecf45533bdad084039a47` |
| 共用指示 | `09-02-PROJECT-SHARED-INSTRUCTIONS.md`，SHA-256 `624d808521354aa4fb00774839a25cac29e8fdbaa6029c66f39dc43bf7a1bb43` |

偽碼只用來定位。本文判斷的 native instructions、指標表、字串、呼叫 bytes 均保存於 [native-windows.json](native-windows.json)，含 VA、raw、完整 hex、SHA-256 與反組譯；[source-manifest.json](source-manifest.json) 列每個來源的 commit、path、Git blob，以及本地導航副本的 SHA-256。

### 1.2 搜尋能證明到哪裡

[scoped-xrefs.json](scoped-xrefs.json) 固定三組共 18 個 target：3 個 parser／reader、2 個 execute target、13 個有需要向上核對的 helper／callback。搜尋僅包括：

- raw-backed `.text`、`.rdata`、`.data` 內的 little-endian 32-bit literal。
- `.text` 內 E8／E9 rel32 候選；對本文採用的候選核對原件 instruction、上游或資料表。

不涵蓋 runtime 計算地址、其他模組、動態生成的 callback、執行後 Lua global／metatable／registry 的全部改寫。**零 E8 不等於不可達**；本文明確保留 table registration 與 indirect call 的可達性。這輪未重做 `6FE990`、`6FE860`、`6F5A50` 舊 caller census，也未擴成完整標準庫逆向。

## 2. Parser／reader 反查閉合

### 2.1 兩個最底層 parser

| Target | literal 使用點 | 實際指令與作用 | direct E8／E9 |
|---|---|---|---:|
| text `0070E420` | operand VA `006FE898`，raw `002FDC98` | `6FE897 mov eax,70E420` | 0／0 |
| binary `0070D680` | operand VA `006FE88E`，raw `002FDC8E` | `6FE88D mov eax,70D680` | 0／0 |

`6FE860` 先讀 stream 首 byte，再依 `0x1B` 選上表函式並間接呼叫；副檔名不參與選擇。兩個 literal 均是 **parser target 的實際選擇**，不是新的 reader，也不是新的外部觸發者。原件窗 `P01`；格式與 parse→closure 語義復用已發布 `parser.md` §§2–4。

### 2.2 `6F70E0` 六個使用點及來源／執行界線

`6F70E0` 只消費 `{pointer,length}`：首次回 pointer 與 length、清 length，後續回 NULL；不開檔、不中途補網路內容。原件窗 `P02`，六個 operand 窗 `P03–P08`。

| reader operand VA／raw | 所在入口 | buffer producer | parse 後何處首次執行／結果 |
|---|---|---|---|
| `6F49BC`／`2F3DBC` | global `DoFile=6F48A0` | Lua 路徑引數 → 遊戲資源 `714770` → resource bytes／copy | loader 解析成功後走既有受保護執行；需要 Lua 已在執行 |
| `6F4B64`／`2F3F64` | path loader `6F4A50` | native caller 選路徑 → 同一資源系統 | 解析成功後執行；既有 native caller 清冊與正常觸發鏈復用前稿 |
| `6F4C58`／`2F4058` | memory wrapper `6F4C20` | ptr＋len；已知 `lb.DoFile` 的 `4A1230` 上游仍是本機資源 copy | wrapper 解析後執行；不能只因收 ptr＋len 就改稱 Server buffer |
| `6F7147`／`2F6547` | auxiliary memory parser `6F7110` | 既有 global DoFile／path loader 的 BOM 分支傳入 `ptr+3,len-3` | 本 helper 只 parse；回到上述 loader 才 execute |
| `70190B`／`300D0B` | `debug.debug=701820` | 已閉合的 stdin line buffer | inline protected parser 後執行；需要已存在 Lua 呼叫 debug.debug，不是新遊戲／Server 入口 |
| `706474`／`305874` | `loadstring=706400` | Lua arg1 string＋length | 回 compiled closure；需呼叫者另外 invoke，無自動 execute |

`6F7110` 並非新發現的載入者：前稿 `parser.md` §3 已列 `6F496F`、`6F4B0B` 的 BOM 呼叫；前稿 native window `aux_memory_parse_wrapper` 已存其原件。本輪只把它放回 memory-reader 的完整有限集合。

standard `load` 的 `706540` 是另一種已知 reader：呼 Lua function 取得分段 string；`706597→6FE550` 是向 reader 要內容，解析成功仍先回 closure。其註冊 `707790`、base table 與正式 state 可達鏈，已由前稿 `parser.md` §4.1、§5、§6 閉合，本輪沒有將相同發現再次列為增量。`debug.debug`、stdio `loadfile/dofile`、`require` 的檔案來源也復用前稿，沒有重做整條流程。

因此，本輪底層反查的準確結論是：**指定三個 target 的原件 literal／E8／E9 集合均能分類；尚未由此補出遊戲資料提供新 script bytes 的另一條鏈。**

## 3. 繞過 `6F5A50` 的直接執行入口

### 3.1 `6FE550` 的 20 個 direct caller

所有下列 E8 bytes 另有 `E01–E20` 獨立原件窗。表中的「已有 closure／callback」表示這個執行點取用 VM 中的函式值；不能據此推定該函式永不間接載入腳本。

| callsite | 所在功能 | 實際 callable／引數來源 | 分類與證據 |
|---|---|---|---|
| `6F5A61` | `6F5A50` execution thunk | 已建立的 call frame／stack | 前稿已閉合；不是新入口 |
| `6F6577` | `6F64F0` | Lua arg1 的 `__tostring`，再傳入原 arg1 | 本輪穿透到 `tostring` 註冊；`N01–N02` |
| `6F76EA` | 開標準庫 `6F7660` | 固定 stdlib 表中的 C callback | 前稿已閉合；`D08` 對照固定表 |
| `6F8B44` | `6F8AD0` error handler | `L+20` stack base 加 `L+74` error-function offset；引數為當前 error TValue | 已安裝的錯誤處理函式；`N03` |
| `6FADAB` | GC finalizer `6FAD00` | pending userdata 的 metatable `__gc`；引數為 userdata | VM GC 引用，不是新 bytes；`N04`、`D06` |
| `6FAEC5` | GC drain `6FADD0` | 同一 `__gc`／userdata 路徑 | GC／close 清理 callback；`N05`、`D06` |
| `6FB782` | 通用二引數 helper `6FB700` | 上游傳入的 metatable TValue 與兩個 operand | 已穿透四個上游；見 §3.3，`N06`、`N08`、`N10–N13` |
| `6FB841` | 三引數 helper `6FB7B0` | table-set 選出的 `__newindex`；object、key、value | 唯一上游 `6FBB66`；`N07`、`N09` |
| `6FD279` | VM generic-for | 目前 VM register 的 iterator、state、control | 已執行的 Lua 指令驅動；`N15`、`N33`、`D12` |
| `7013EC` | debug hook `701320` | registry hook table 以 thread pointer 取得既有函式；引數為 event name、line／nil | `debug.sethook` 先接收 Lua callable；`N19–N21`、`D05` |
| `7047DA` | `string.gsub` replacement helper `704750` | Lua arg3，type 6 分支；match captures 作引數 | `7048D0→704750`；`N22–N24`、`D04`、`D07` |
| `705412` | `print=705370` | 讀當時 global `tostring`，逐一傳 print 的 Lua 引數 | global 可變；預設 target 為 `706C70`；`N25`、`D01–D02` |
| `706597` | standard `load` reader `706540` | 已有 Lua reader function；其回傳字串交 parser | 前稿已閉合；不是新 producer |
| `706796` | lowercase `dofile=706740` | stdio loader 編譯後的 closure | 前稿已閉合；不同於 global `DoFile` |
| `70AAE8` | `require=70A830` | `package.loaders[i]` 搜尋器，模組名稱為引數 | 前輪已閉合 |
| `70AC18` | 同上 | 搜尋器回傳的 module closure，模組名稱為引數 | 前輪已閉合；此處才執行 module |
| `70AE57` | module options helper `70AE00` | Lua args 2..n 的 callable；模組 table 為引數 | 唯一上游 `70B151`，global `module=70AFB0`；`N26–N27`、`D09` |
| `70B8C5` | `table.foreachi=70B720` | Lua arg2 function；index、table[index] | `N28`、`D03` |
| `70BA76` | `table.foreach=70B920` | Lua arg2 function；當次 table key、value | `N29`、`D03` |
| `70C551` | sort comparator `70C4C0` | `table.sort` 可選 Lua arg2；待比較兩值 | 五個上游皆 `70C5D0` auxsort；`N30–N32`、`A01–A05`、`D03` |

本集合中沒有 E9 tail call 或 `6FE550` absolute-literal 命中。這是本掃描的具體結果；分類根據上表值來源，不依據 caller 的位址區域。

### 3.2 `6FE1C0` 的四個 direct caller

| callsite | 上游與 callable 來源 | 結論／原件 |
|---|---|---|
| `6FD045` | opcode 28 的 VM CALL；目前 register 選出的 function slot | 已執行 Lua 的 call；`N14`、`N33`、`D11`、`E21` |
| `6FD092` | opcode 29 的 VM TAILCALL；同一 register／frame 路徑 | 已執行 Lua 的 tail call；`N14`、`D11`、`E22` |
| `6FE59F` | `6FE550` 傳入的 function slot | 同一 execute core 的下一層；`N16`、`E23` |
| `6FE5FA` | coroutine resume callback `6FE5E0`，初次 resume 分支使用 coroutine stack 的起始 function | 復用前稿 resume gate／protected callback；`N17`、`E24` |

`6FE1C0` 本集合同樣沒有 E9 或 absolute-literal 命中。它接收 callable TValue，並準備 Lua frame 或呼已註冊 C closure；**它不將字串自行交給 parser**。前稿 `parser.md` §4 已閉合此區分。

### 3.3 不能停在 wrapper：四個具體閉合

#### A. `6F64F0` 是固定 `__tostring` 呼叫

`6F64F0` 以 index 1 讀 Lua arg1，從 table／userdata 物件的 `+8`，或 primitive 的 global-state metatable array 取 metatable。`6F6537` 固定載入 `C4365C="__tostring"`，交 `6F6470` 查欄位；找到後重新 push 原 arg1，在 `6F6577` 執行並取一個結果。沒有任意函式名稱參數。

它唯一 E8 上游為 `706CA1`，位於 base `tostring=706C70`；實際 registration row 是 `C0BC30` name、`C0BC34=706C70`。同一 base 表開庫鏈已由前稿證實。故此候選不能列成額外 game eval／load wrapper。`print` 又會動態讀 global `tostring`；這是已存在 VM 的可變 dispatch，並未證明 Server 把 loader 或新內容塞進該 global。〔`N01–N02`、`N25`、`D01–D02`、`S01–S02`〕

#### B. `6FB700`／`6FB7B0` 取用 metatable 的現有值

| helper caller | 上游 | callable 的具體來源 |
|---|---|---|
| `6FB98B→6FB700` | table get `6FB850` | `global_state+BC` 的名稱／metatable lookup，即 `__index`；僅 function 分支 invoke |
| `6FBC04→6FB700` | 二元運算選擇 `6FBB80` | 先查左 operand metatable 的 `tmnames[event]`，不存在再查右 operand；同一 TValue 傳入 helper |
| `6FBD56→6FB700` | 比較 helper `6FBCA0` | 兩 operand 的同一 event metatable 值，檢查相容／相同後 invoke |
| `6FC027→6FB700` | 相等比較 `6FBFA0` | `6FBC20` 以固定 event 4、`global_state+CC` 取兩物件 `__eq` |
| `6FBB66→6FB7B0` | table set `6FB9A0` | 固定 event 1、`global_state+C0`，即 `__newindex` |

事件名稱不是從 Lua 常識套上去：`6FEA00` 將原件 `C0BF40` 的 17 個固定名稱依序寫入 `global_state+BC..FC`；名稱表與字串已保存。`6FB700` 自身只搬入 callable、兩個 TValue 並取一個結果；`6FB7B0` 搬入 callable、三個 TValue，要求零結果。〔`N06–N13`、`N18`、`D06`、[tables.json](tables.json)〕

這些函式可能由遊戲進行 Lua table 操作時觸發；結論只到「執行已有 metatable callback」。**沒有把 native table 操作說成不可從遊戲到達，也沒有把它等同新的 script byte producer。**

#### C. registry hook 需要先登記 Lua callback

`701320` 的兩個 literal 引用必須分開：`701634 mov ebx,701320` 是 `debug.sethook=701510` 的安裝；`701715` 是 `gethook=7016C0` 裡的比較，不是第二個安裝者。

setter 先驗證 Lua 引數為 function，將其按 thread key 寫入 hook table，再寫 `thread+44=701320`。callback 取 registry 中 lightuserdata key `C081DF` 的 hook table，再以 thread pointer 找函式；呼叫引數只有 VM hook event 名稱和 line／nil。setter 的 table registration row `C0BE90→701510` 與執行窗均有原件。這條鏈能執行已註冊函式；沒有直接讀 script buffer 或把 hook event 當檔名。〔`N19–N21`、`D05`、`D10`〕

此段只是分類 `7013EC` 這個 execute 候選，沒有重開前輪 `debug.debug` stdin loader 分析，也沒有據此發明遊戲 debug command。

#### D. sort 與其他標準庫 callback 仍取 Lua 實參

`70C4C0` 的五個直接上游 `70C654/70C710/70C77D/70C8AD/70C915` 都在 `70C5D0` 的排序實作；`table.sort=70CA40` 驗證 arg1 table、arg2 若存在則須 function，`70CBC8` 進 auxsort。comparison helper 從 Lua arg2 複製 callable，再複製兩個待比較值；沒有 arg2 時走現有 VM 比較邏輯。`70CBF0` 實際註冊 `C0B968` table library，故不以「找不到 direct game call」誤判為死碼。〔`N30–N32`、`A01–A05`、`D03`〕

`gsub`、`foreach`、`foreachi`、`module` 同樣都有具體註冊與 Lua 實參來源，已列於 §3.1。它們的功能或原字串可含遊戲資料，但 **資料成為 callback 的一般引數，不會自動成為 Lua source**；仍需上層程式將該資料送進 `load`／`loadstring`／DoFile 等已知 loader 才有新 script content。

## 4. 對完整 MEF 流程的影響與剩餘問題

本輪把流程中的兩條界線分清楚：

| 問題 | 已有答案 | 本輪未增加的能力 |
|---|---|---|
| bytes 如何成為函式 | resource copy／stdio／Lua string／Lua reader → 既有 reader → text 或 binary parser → closure | 沒有新增網路接收 carrier |
| 函式何時被執行 | loader 主流程、明確 invoke、VM CALL／TAILCALL、coroutine、metatable、hook、stdlib callback | executor 不會自行尋找 `.mef` 或把所有字串當腳本 |
| 下游 callback 是否真能到達 | 實際 registration、metatable lookup、registry setter、VM 指令均可到達 | 可達 callback 不等於外部已提供新內容與參數 |
| `.mef` 副檔名是否解鎖入口 | parser 看內容；名稱只不能替代 selector、資源與執行時機的要求 | 沒有發現 `.mef` 專用的另一個底層 parser 或自動網路 handler |

前稿已閉合的 `55D591` 是前置 VM 的 `Register(scene)` 立即執行，不是本輪新入口；global `DoFile`、`lb.DoFile`、stdio `dofile` 不可互換。Boot／Logic／Coroutine／ai 與 Event 已有可復用內容分析，**不能把本地缺少散檔重新列為「未讀」阻塞**。其 scheduler／失敗處理與原生資源選擇／完整性 gate 由同輪其他分題補齊。

仍需沿具體需求閉合的 Client 逆向問題，是：若聲稱某個正常操作或 Server 資料能提供新內容，必須找到它的 **producer → resource/path/stack 寫入 → 已證 loader 或 callback → 首次 execute**，並保留所在 VM 與生命週期。對可變 global、metatable、registry 的別名／寫入鏈，這份有限集合沒有給全局否定。

Server 開發需求應依已證 Client 能力制定內容選擇、可取得的資源、啟動事件與結果狀態；若需求是動態新增 `.mef`，內容交付及確認契約仍須有可相容的 Client carrier／觸發入口作依據。**本輪沒有提供可直接實作的新 opcode，也不把未找到的 Client caller 改列成「Server 補送封包即可」。**

## 5. 復用文件、交付與唯讀重驗

主要復用文件固定在 `67021e609f56e45981aecf45533bdad084039a47`：

| 路徑 | Git blob |
|---|---|
| `kr-extra-roy/MEF-parser-executor-storage-20261114/parser.md` | `b1d2f7404d771e4a1bf5ca72c1fa024408e446e7` |
| 同目錄 `executor.md` | `9bb84b5f173636024e4bb58ada8e190e52209c55` |
| `kr-extra-roy/MEF-trigger-callers-20261115/alternate-entry/report.md` | `a159da50ab06841e02e8c228b2add6b1d0df9f2f` |
| 同輪 `named-calls/report.md` | `b5933d66d0edd0a7a0a807498c62be080bf04b35` |
| 同輪 `script-consumers/report.md` | `6904ec3ce8de271c2ad188f33625d4a9102d28be` |

完整 source pin 在 manifest，共 21 個導航偽碼及 8 個復用文件。交付為本報告、`native-windows.json`、`native-disassembly.txt`、`scoped-xrefs.json`、`tables.json`、`source-manifest.json`、`reproduce.py`、`validation.json`、`deliverables-manifest.json`。導航 C 副本與 scratch builder 不需另行發布。

在已有原件、GNU objdump 與本地 repo object metadata 的環境中執行：

```sh
python reproduce.py \
  --bin /workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

verifier 只讀檔與 `git ls-tree`，不下載、不執行 Client／Lua、不寫 repo。它校驗 binary SHA、section mapping、每個 window 的原 bytes／hash、原件反組譯完整 instruction 邊界、18 個 target 的相同有限掃描、註冊與 TM／opcode table、29 個固定來源 path／blob，以及可選本地導航副本。未提供 `--repo` 仍可重驗全部原件證據。

本輪原件驗證：**125 windows＝78 code＋12 data＋35 strings；2,770 instructions；parser literal counts 1／1／6；execution E8 counts 20／4，兩者 E9 與 literal 均為 0；29 source pins；全部 PASS。** 分支、Git index、原件均由本分題保持不變。
