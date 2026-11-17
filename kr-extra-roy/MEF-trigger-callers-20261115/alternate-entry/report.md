# MEF caller 追查補充：Lua `debug.debug`、`require` 與 Expedition UI 的實際上游

日期：2026-11-15（Asia/Taipei）。研究分工：`mef_trigger_alternative`。原件唯讀，未執行 Client、Lua、原始資源或歷史腳本；未改 repo、branch、Client 或 Server。

## 1. 結論與本次可證範圍

本次補到三條先前 caller 清冊未完整說明的上游。其中 **`debug.debug` 的原生實作直接以 callback `6FE860` 進入 parser，沒有經過 `6FE990` wrapper**，因此只列 `6FE990` 的 direct callers 會漏掉這個實際輸入來源。但它先要求既有 Lua 執行 `debug.debug()`，輸入又來自 CRT stdin 的逐行讀取；目前沒有證據把它連成正常 Server 收件後自動載入 `.mef` 的入口。

| 入口 | 誰先觸發 | filename / buffer 來源 | 已閉合到的 consumer | 對 `.mef` 串接的意義 |
| --- | --- | --- | --- | --- |
| `debug.debug` → `701820` | 已在執行的 Lua 呼叫已註冊 C function | CRT stdin → `fgets(buffer, 250, stream)` → `strlen` | `6FE770(6FE860)` parse，成功後 `6FE770(6F5A50)` execute | 正向確認額外可執行字串的來源；尚無正常 UI / Server 自動呼叫它的證據，且不是任意長度二進位檔案傳輸介面 |
| global `require` → `70A830` | 已在執行的 Lua 傳 module 名稱 | Lua argument 1 → `package.path` 模板 → CRT 檔案路徑 | Lua searcher `70A510` → `6F6E60` → 既有 parser，之後 `require` 執行載入 closure | 不是固定 module 白名單；存在動態路徑能力，但尚缺正常腳本的具體呼叫點與 module 名稱，不能把 stdlib 存在當成第一個 `.mef` caller |
| Expedition UI → `5A64B0` | `CExpeditionPage` 初始化，或 `CExpeditionScene` control 700 的內部 UI event | native 固定 `Event/TutorialMain.lua`，固定 `Synopsis_EntryPoint` | `4C1E10` → `4A89C0` → `6F4A50` / `6F4DD0` | 補到具體正常 UI 觸發條件；這一條固定載入 TutorialMain，沒有 `.mef` filename 或 Server script buffer |

**本報告沒有找到「某個正常 Server handler／玩家操作首次選出 `.mef` 路徑，並將它交給 parser」的完整鏈。** 它縮小了可疑入口：一條是真實但須先有 Lua 的 stdin 執行能力；一條是真實但須先有 Lua 呼叫的 module loader；一條是已能指向正常 UI 的固定 TutorialMain 入口。主線對 named call、資源 carrier 及現存腳本的追查應與本報告合併判斷，不得單憑這三條就宣稱 `.mef` 收件／執行已串好。

證據：原生窗 `N01–N37`、資料窗 `D01–D16`、字串 `S01–S28`，均在 [native-windows.json](native-windows.json)；按原生表格展開後的結果在 [tables.json](tables.json)。本次 native 查核是下述有界主張的研究證據，不是 T01 的整篇 FULL-PASS、整個函式語意驗收或可玩驗收。

## 2. 來源、基準與舊研究復用

第一手原件為 KR `02-Tartaros.bin`，大小 **12,472,320 bytes**，SHA256：

`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`

PE 為 i386 PE32，ImageBase `00400000`。本包依 PE section header 計算 VA → raw，沒有將 BSS 或未載入的 runtime pointer 視為磁碟原件 bytes。各 native window 都保留 VA、end-exclusive、raw offset、長度、完整 hex、SHA256；code window 另保留逐指令邊界及反組譯。

| 來源 | 精確版本 | 本次用途 |
| --- | --- | --- |
| 最新主線基準 | `e66dadaa721671919cbbeb228ae3f26ad990c9e3` | 本次逐函式反編譯導引、S00 舊研究、政策 |
| 已發布 MEF 原稿 | `0a2503db089a4867cff5ef8bf6d7689333f12fd1` | parser / executor / entry / lifecycle 的既有結論 |
| `kr-bulk-roy/9741…ef91/functions/0x*.c` | 逐檔 blob 見 manifest | 只用來挑選函式與閱讀導引；關鍵 call、callback、vtable、欄位來源以 BIN bytes 核對 |
| `project_sources/09-02-PROJECT-SHARED-INSTRUCTIONS.md` | SHA256 `624d808521354aa4fb00774839a25cac29e8fdbaa6029c66f39dc43bf7a1bb43` | 原件唯讀、完整鏈、Server / Client 未知分層 |

精確復用檔案與 blob：

| repo 相對路徑 | Git blob SHA |
| --- | --- |
| `kr-extra-roy/MEF-parser-executor-storage-20261114/parser.md` | `b1d2f7404d771e4a1bf5ca72c1fa024408e446e7` |
| `kr-extra-roy/MEF-parser-executor-storage-20261114/executor.md` | `9bb84b5f173636024e4bb58ada8e190e52209c55` |
| `kr-extra-roy/MEF-entry-lifecycle-events-20261114/entry.md` | `8c5a1e6bdd278847b894f8806819c14d773987a9` |
| `kr-extra-roy/MEF-entry-lifecycle-events-20261114/lifecycle.md` | `fd7aea4847a75c9fa199de26059415c162df7092` |
| `governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md` | `e3422673ebd928d90f998b792cb513f10b28b69b` |

上面前四份 pinned 於 `0a2503…`，S00 原稿 pinned 於 `e66dadaa…`。其他逐檔 SHA、大小及本地唯讀來源副本對應都列在 [source-manifest.json](source-manifest.json)。`sources/` 的 `.c` 是既有 Git 反編譯資料的工作副本，不需要再次發布，也不是新增原件。

### 2.1 本次沒有重算或冒稱新成果的內容

- 沿用 `6F4A50` 的既有 direct caller 分類；沒有重做 15 / 16 caller 全清冊。
- global uppercase `DoFile` → `6F48A0`、`lb.DoFile` → `4A1230` → `6F4C20` 的 loader 能力沿用已發布結果。本輪實際新增的是相鄰 stdlib 的上游／來源分類與 `6FE860` inline 分支。
- `4A89C0` 固定 TutorialMain / Synopsis 名稱，以及 `4C1FFC` → `4A89C0` 的下游，沿用 lifecycle 結論並有限重驗。新部分是它之前的 Expedition page / UI event 觸發條件。
- 已完成的 `0047`、review 特例及 bootstrap 不列作本次新發現。`47B850` 導引曾選讀，沒有再次擴大既有 review 結論。
- S00 已對 Event.stp 的 **1,840 `.seq` 與 3 `.lua`** 做過 standard `load` / `loadstring` / `loadfile` / `dofile` / `require` 的限定內容檢查。本次復用其範圍和陰性結果，沒有把它重新掃描當新成果，也沒有將它擴大成所有可能 Lua 語法、動態組名及缺失腳本的全域陰性證明。
- 同一份 main `e66dadaa…` 的 S00 原稿「兩版啟動 Lua 的檔案讀取範圍」也已解析 `boot.lua`、`Logic.lua`、`Coroutine.lua`、`ai.lua` 全部 bytecode，分別為 **1、1、13、8 個 prototypes**，未見檔案 loader 引用、含副檔名字串常數或 `CONCAT`。UI/Table 啟動 Lua 的三個明列 `DoFile` 目標亦已有核對。本次工作目錄缺少其中散檔，不代表它們尚未分析；這些內容不列作阻塞。該 S00 完整原稿 SHA256 為 `dcb12f0ae59e048775841545c111c84379c11a350639d7f44a8c846d4ff5a0bc`，Git blob 已列於上表。

## 3. `debug.debug`：已確認的另一個 parser 輸入來源

### 3.1 它真的有註冊，不是只存在一段未掛接的 library code

正式 Lua 初始化 `6F4380` 把 state 寫入 `FDF3C8`，在 `6F43AF` 呼叫 `6F7660`。後者以 `C0C0D8` 起算的 8-byte `(name, callback)` table 逐項開啟標準函式庫；`6F7685` 將 callback 建為 Lua C closure，`6F76EA` 透過 `6FE550` 執行該開庫 callback。`debug` 這一列為：

| 資料 VA | 值 | 意義 |
| --- | --- | --- |
| `C0C110` | `C42864` → `"debug"` | library namespace |
| `C0C114` | `701E00` | debug 開庫 callback |
| `C0BE48` | `C42864` → `"debug"` | 該 namespace 內的 function name |
| `C0BE4C` | `701820` | `debug.debug` C callback |

`701E06` push `C0BE48`、`701E0B` push `C42864`，`701E10` call `6F6590`。`6F6590` 先依非空 library name 取得／建立 globals 中的 table（`6F663D` 的 pseudo-index 為 `FFFFD8EE`），再以 stride 8 取各 registration row；`6F66BC–6F66C2` 取 row+4 callback、建立 C closure，`6F66C7–6F6713` 以 row 的 name 存入 table。

所以這裡正確的名字是 namespace 加 member 的 **`debug.debug`**。它與 global `DoFile` 不同，也不因名稱有 debug 就能被假定綁到遊戲內 console、快捷鍵或 Server command。

來源：`N01–N03`、`N36`、`D01–D02`、`S01`。標準 Lua globals pseudo-index 的既有語意沿用 parser / executor 基礎分析；此處核對的是實際傳入值、table row、callback 建立與存入關係。

### 3.2 它繞過 `6FE990`，直接傳入 parser callback

以第一手原件做限定指標候選掃描，`6FE860` 的 little-endian 4-byte literal 在 `.text/.rdata/.data` raw-backed 區域只有兩個候選，且都落在可核對的 `push imm32` 指令中：

| instruction VA | operand VA / raw offset | bytes | 角色 |
| --- | --- | --- | --- |
| `6FE9BC` | `6FE9BD` / `2FDDBD` | `68 60 E8 6F 00` | 既有 `6FE990` wrapper 的 parser callback |
| `7018FC` | `7018FD` / `300CFD` | `68 60 E8 6F 00` | 本次確認的 `701820` inline parser 路徑 |

`701917` 是 `E8 54 CE FF FF`，其 target 為 `6FE770`。它不是呼叫 `6FE990`。這是「舊 direct caller 清冊無法看出另一條 parser 來源」的具體原生反例，不需要推測新 opcode 或新的 loader API。

同一限定掃描中，`701820` 的 literal pointer 僅在 `C0BE4C`，沒有 `.text` 的 direct E8 / E9 候選。這支持目前所見呼叫方式是 library registration callback；**不宣稱它能排除任意計算後的間接呼叫、Lua alias、動態取表或未取得腳本內容**。完整範圍和候選在 [scoped-xrefs.json](scoped-xrefs.json)。

### 3.3 buffer 的 producer 是 CRT stdin

`701820` 的 buffer 來源可逐步閉合：

1. `894FAB` 的原生 bytes 為 `B8 F8 1A D6 00 C3`：回傳 `D61AF8`，即三個初始 CRT stream record 的起點。`D61AF8 + 0x20`、`+0x40` 的記錄 descriptor 分別為 1、2；第一筆 descriptor 為 0。此處只核對用到的 stream table，沒有擴展 CRT 子系統研究。
2. `701840` 取 table 起點後加 `0x40`，把 `"lua_debug> "` 印至第三個 stream；`701853` 再取 table 起點，這次不加偏移，作為輸入 stream。
3. `701858–701863` 的參數為 `(stack buffer, 0xFA, first stream)`，呼叫 `897618`。`8976F6–89772D` 可見 count 先減、逐 byte 讀入、遇 newline `0A` 結束、最後補 NUL 的 `fgets` 相容迴圈。`0xFA=250`，單次最多保留 249 個輸入 bytes 再加 terminator。
4. 初次讀取回傳 NULL 就跳到 `701A2B` 結束；若 buffer 等於 native 字串 `"cont\n"` 也結束。
5. `7018B1–7018C1` 從同一 stack buffer 算 `strlen`。`7018D3–7018D8` 將 buffer pointer 放入 reader userdata；reader 為 `6F70E0`，chunk name 為 `C43000 → "=(debug command)"`。
6. `701917` 執行 protected parser。parse 成功才進到 `701962` push `6F5A50`、`70196D` call `6FE770`，以 0 個預期結果執行剛產生的 closure。
7. 錯誤文字印到第三個 stream；`7019F2–7019F5` 將 Lua top 回復 base，然後 `701A1B` 再讀下一行。

`6F70E0` 是一次性 memory reader：userdata+4 非零時寫出 size、清零剩餘長度、回傳 userdata+0 的 buffer；下一次 reader 回傳 NULL。parser `6FE860` 根據第一個 byte 判斷：`1B` 走 `70D680`，其他走 `70E420`。這一選擇與副檔名無關，仍沿用既有 parser 結論。

這裡沒有 `.mef` filename、沒有 archive member 選擇、沒有 socket / packet buffer 參數。它是 **先進入 `debug.debug()`，再讀 stdin 的文字命令入口**。stdin 在實際程序可能沒有可讀 console、可能被重導向；本輪未執行 Client，故不宣稱玩家目前能實際鍵入或 Server 能寫入它。另一方面，不能因尚未接上 Server 就否認這段確實有 parse + execute 能力。

來源：`N04–N10`、`D03`、`S02–S04`。

### 3.4 對 `.mef` 內容能力的界線

`701820` 會共用 text / bytecode parser，但其外層是 `fgets(...,250,...)` 和 `strlen`。因此不能將「parser 能辨識 `1B`」擴大成「stdin 支線可以完整承載任意二進位 `.mef`」。長資料會分成獨立解析的多次讀取，內嵌 NUL 會縮短送入 parser 的 length。它也沒有整個腳本下載、組包、檔案快取或網路完成通知。

等價導航偽碼如下；這只是上述 bytes 的縮寫，不作新增 API 規格：

```cpp
// Callback 701820, 已有 Lua state 才能由 debug.debug() 進入。
while (read_line(buffer, 250, CRT_stream_0) != nullptr) {
    if (strcmp(buffer, "cont\n") == 0)
        break;
    ReaderData rd = { buffer, strlen(buffer) };
    int status = protected_call(parser_callback_6FE860,
                                one_chunk_reader_6F70E0, &rd,
                                "=(debug command)");
    if (status == 0)
        status = protected_call(execute_thunk_6F5A50, loaded_closure, 0);
    if (status != 0)
        print_error(CRT_stream_2);
    lua_top = lua_base;
}
```

## 4. `require`：module 名稱由 Lua 傳入，路徑由 package 設定產生

### 4.1 可達的 registration 與四個 searcher

同一 stdlib 開庫表 `C0C0E0/C0C0E4` 註冊 `"package" → 70B3B0`。`70B3B0` 先以 `C0B93C` 註冊 package table，再將下列 callback 加入 `package.loaders`；`70B4CB` 讀首指標，`70B4D9–70B4FF` 逐項建 closure 和填入 1 起算的 array index。

| index | pointer slot | callback | 本次覆蓋 |
| --- | --- | --- | --- |
| 1 | `C0B954` | `70A730` | 登記存在；偽碼導引為 preload 搜尋，未擴大成可從 Server 輸入 |
| 2 | `C0B958` | `70A510` | 本次完整追至 `package.path` 與 Lua file parser |
| 3 | `C0B95C` | `70A5D0` | 登記存在；C module 搜尋分支不當作 MEF parser |
| 4 | `C0B960` | `70A630` | 登記存在；C root module 分支不當作 MEF parser |

`70B701` push registration table `C0B9B8`，`70B706` push NULL name，`70B70A` call `6F6590`，在已推入的 globals table 上註冊：

- `C0B9B8/C0B9BC`：`"module" → 70AFB0`。
- `C0B9C0/C0B9C4`：`"require" → 70A830`。

`70A830` 的入口 `70A83F–70A845` 從 Lua argument **1** 取得 module 名稱。它會查 `_LOADED`；尚未載入時從 `loaders` table 逐個取 callback，`70AAE8` 呼叫搜尋器，回傳值是 function type `6` 才接受（`70AAFD–70AB01`）。找到 function 後，`70AC18` 再透過 `6FE550` 執行它，傳入同一 module 名稱。這是取得 loader closure 與執行 loaded module 的兩個時點。

來源：`N02`、`N11–N13`、`N36`、`D01`、`D04–D05`、`S05–S10`、`S27–S28`。`N12` 截至 `70AC26`，本包不以它宣稱整個 `require` cache 收尾函式已全面驗收；本段主張限於 argument、cache gate、搜尋器選擇及已取得 closure 的執行點。

### 4.2 動態路徑的實際來源與限制

Lua searcher `70A510` 在 `70A51E` 再取得 argument 1，於 `70A52B` 呼叫 `70A230(module, "path")`，返回非 NULL path 才在 `70A53D` 呼叫 `6F6E60`。`70A230` 有兩層轉換：

- `70A241–70A24D` 以 `"."` → `"\\"` 改寫 module 名稱。
- 從 `package.path` 逐個取得 template；`70A379–70A381` 將 template 的 `"?"` 代換為前述 module 名稱。

`70A3B7` push native 字串 `"r"`，`70A3BC` push candidate path，`70A3BD` call CRT open `89187B`；成功在 `70A45A` close `891CC9` 後返回該 path。失敗則累積錯誤並取下一個 template。後續 `6F6E60` 又以同一 CRT file route 打開該路徑，在 `6F7051` 進入 `6FE990`。這一條使用 stdio 檔案，不是 `714770` 的 archive/member lookup route。

因此 `require` 的 module argument **不是 native 固定白名單**，也不是直接原封不動拿來當 filename。預設 `.lua` template 與 `.` 的名稱轉換是實際限制。若既有腳本自行改 `package.path`，可產生不同後綴的 candidate；本次沒有找到這種改寫的原件呼叫點，故不補猜 `.mef` template 或 module 名稱。

來源：`N13–N18`、`N37`、`S08`、`S15–S18`。template iterator `70A1A0` 在 `70A1A6–70A1B4` 跳過 `0x3B`（分號），`70A1C2–70A1C5` 找下一個分號；把目前指標到該位置的字串推入 Lua，回傳後續迭代位置。這補足 `package.path` 確實逐段取模板的 native 來源，不擴大成整個 package library 的語意驗收。

### 4.3 初始化路徑不等於自動載入腳本

`70B539–70B55E` 為兩次 path 初始化，對應 native 字串如下：

| 欄位 | environment name | native fallback 字串 |
| --- | --- | --- |
| `package.path` | `LUA_PATH` | `.\?.lua;!\lua\?.lua;!\lua\?\init.lua;!\?.lua;!\?\init.lua` |
| `package.cpath` | `LUA_CPATH` | `.\?.dll;!\?.dll;!\loadall.dll` |

`70B2D0` 在 `70B2E5` 取環境值；無值時 `70B2F1–70B2F2` 使用 caller 傳進來的 fallback。有值時將 `;;` 處以 marker 換成 fallback，之後 `70B351` 呼叫 `709DF0` 展開 `!`。`709E15` 的 import slot `BD2114` 在原始 PE import table 中對應 **`KERNEL32.dll!GetModuleFileNameA`**；它取可執行檔路徑、截到最後一個 `\\`，再替換 `!`。

這是 **路徑設定來源**，並不是入口觸發。單純存在 `LUA_PATH`、`package.path` 或這些 default strings，不會自己啟動 `require`，也不證明 `.mef` 曾存於其中任何位置。相對的 `.\` 由該 process 的工作目錄解析；`!\` 對應 executable directory。實際啟動環境、工作目錄、環境變數值及檔案存在性，本輪沒有 runtime 證據。

來源：`N11`、`N15–N16`、`S11–S14`、`S19–S22` 及 `tables.json.imports_used`。不提出修改 Client 或設定環境變數作恢復方式。

## 5. 固定 Synopsis loader 的正常 UI 上游

### 5.1 RTTI、vtable 與建立關係

這條線不是只憑偽碼名稱將物件稱為 Expedition。原始 RTTI 能直接取得類別：

| 物件 | vtable | CompleteObjectLocator | TypeDescriptor | 原始 RTTI 名字 |
| --- | --- | --- | --- | --- |
| Expedition page | `C1C1A4` | `C6EF78` | `F80F10` | `.?AVCExpeditionPage@FUI@@` |
| Expedition scene UI | `C280F4` | `C74224` | `F8462C` | `.?AVCExpeditionScene@FUI@@` |

`58788C` 配置 `0x148` bytes，`5878B1` 寫入 `C1C1A4`，`5878B7–5878CF` 將 page+134、+138、+13C、+140、+144 清零。因此 `CExpeditionPage` 有實際配置和 vtable 安裝，不只是孤立 RTTI。`5F45B0` constructor 在 `5F45C5` 安裝 `C280F4`，將其 control 欄位清零。

本次用到的 virtual slot 為：

| vtable / offset | slot VA | target |
| --- | --- | --- |
| `CExpeditionPage +108` | `C1C2AC` | `5A65A0` page 初始化 |
| `CExpeditionPage +15C` | `C1C300` | `595D20` event 分流 |
| `CExpeditionPage +194` | `C1C338` | `5A67D0` Expedition event handler |
| `CExpeditionScene +114` | `C28208` | `5F4640` control 綁定 |
| `CExpeditionScene +15C` | `C28250` | `5F46D0` UI event handler |

來源：`N19–N21`、`D06–D14`、`S23–S24`。page 的完整啟用／切換 scheduler 不在本包逐項驗收範圍；以下正常入口的精確條件是「這個 page 被初始化」或「它是 current page 並收到下述 UI event」。

### 5.2 入口 A：page 初始化且 `page+144 == 0`

`5A65A0` 完成所需 UI 初始化後，`5A665F` 比較 `[EBX+144]` 是否為 0。等於 0 的分支處理幾個 UI control 後，在 **`5A66B3` 直接 call `5A64B0`**。非零走 `5A66BA`，不經這個 call。

不能直接把 `+144` 翻成「新帳號」「新角色」或「Synopsis 未完成」：本包只證明其型態為本次比較的 DWORD、constructor 初值 0、及這個 caller gate。其他寫入與遊玩語意應由既有 Expedition / UI 研究或後續定向研究補上。

來源：`N19`、`N30`。本次不把 native 初值 0 當作所有 runtime 初始化都一定保留 0。

### 5.3 入口 B：control 700 的 `0x578` event → 內部 `0xF4248`

`5F4640` 對 `CExpeditionScene` 綁控制項。在 `5F4685` push `0x2BC=700`，`5F468A` 取 `this+BC` 的地址，`5F4692` call `615FC0`。helper 先 `746940(id)` 查物件，再透過 object vtable+4 要求 type code `0x12D`；符合才於 `616096` 將查得 control pointer 存入 caller 提供的 slot。因而 `[scene+BC]` 的 producer 已具體到 UI control **700**。

`5F46D0` 收到 event 時讀 `event+10`。對 `0x578` 分支：

1. `5F47FF` 取 `event+8`，`5F4802–5F480B` 比對 `[scene+BC]+20` 的 control ID。
2. 相符才配置 `0x14` bytes 的 UI event；配置成功時，設定 `+4=-1`、`+8=-1`、`+C=0`。
3. `5F4836` 的 bytes 是 `C7 40 10 48 42 0F 00`，將 event+10 寫成 **`0xF4248`**。
4. `5F483F` call `404AA0`，取 UI manager `F94810`；`5F4844` call `750020` 送交 current page。

`0x578` 的具體使用者可見操作名稱、control 700 的文字標籤，本次沒有 UI layout 原件證據，故保留為上述 numeric UI condition，不補寫成特定按鈕名稱。

`0xF4248` 亦不可視為 Server wire opcode。它在這條原生分支中明確由 Client 建立 `0x14` bytes 的內部 UI event，沒有 packet reader 或 socket send。

來源：`N21–N27`。對 literal `0xF4248` 的三個 raw 候選已分類：`5DA791` 是 `5DA790` getter 的 immediate，`5DB2E6` 是 compare immediate，**`5F4839` 才是這條 event 欄位的 writer**。未因同值常數就把另外兩個位置也當 producer；詳 `N34–N35` 與 scoped xrefs。

### 5.4 current page 的兩層 dispatch 已用實際 slot 關起來

`750020` 不是直接 call `5A67D0`。其實際流程為：

- 取 UI manager+`13C4`，非 NULL 才讀其 vtable+`15C`；`750037` push event，`750038` indirect call。
- 若 current page 的動態型態為已核對的 `CExpeditionPage`，vtable+`15C` 即 `595D20`。
- `595D63–595D7A` 對 **`0xF4240 < event+10 < 0xF42D7`** 的範圍轉至 current page vtable+`194`，其 target 正是 `5A67D0`。
- `5A680E` 將 event code 減去 `0xF4245`，以 byte jump-index table `5A69A0` 和 target table `5A6988` 做 switch。輸入 `0xF4248` 的 offset 為 3，byte entry 為 3，DWORD target 亦為 **`5A696E`**。
- `5A696E` call **`5A64B0`**。

`75003A–750047` 在 dispatch 後以 event vtable+`10`、argument 1 回收 event；本支線沒有把該 UI event buffer 留作 Lua source。

這裡保留了 current page 的型態條件，沒有將一次 vtable 內容等同於永遠相同的 runtime receiver。也沒有用偽碼的間接 call 字樣取代實際 slot 對應。

來源：`N27–N29`、`D07–D09`、`D15–D16`、`tables.json.switch_event`。

### 5.5 最後落到固定檔案，不由 UI event 提供 filename

兩個 caller 都抵達 `5A64B0`。它先保證相關 singleton 的初始化，然後有兩個必要 gate：

- `5A64E9`：`[D6A674] == 0x45585044`。
- `5A64F5–5A64FC`：`[FD8BA4] != NULL`。

通過才在 `5A64FF` call `4C1E10([FD8BA4])`。本包使用 numeric tag 作判斷，不單憑它看起來像文字的常數就新增未驗證 scene 名稱。

既有 scene / Synopsis 下游在 `4C1FCE` 將 scene+`BD78` 寫為 1，`4C1FF7` 傳 controller `FC0F84`，`4C1FFC` call `4A89C0`。本次有限重驗的 loader 末段：

| VA | bytes / operand | 結果 |
| --- | --- | --- |
| `4A8A31` | `68 7C 68 C0 00` | push `C0687C → "Event/TutorialMain.lua"` |
| `4A8A36` | `E8 15 C0 24 00` | call `6F4A50` |
| `4A8A41` | `68 94 68 C0 00` | push `C06894 → "Synopsis_EntryPoint"` |
| `4A8A46` | `E8 85 C3 24 00` | call `6F4DD0` |

filename 和 entrypoint 都來自 native `.rdata` 常數，**不是 control ID、UI event payload、MapID 或收到的腳本 bytes**。因此新的 UI caller 證據可以解釋何時觸發這個已知固定 loader。TutorialMain 與已知後續腳本的原件內容直接復用 parser / executor / lifecycle、S00 基準及同輪 scripts 支線，不將已讀內容重新列作「尚待取得／尚未分析」。這些已知定義沒有補出正向 `.mef` 檔案載入 caller；尚未形式化排除的範圍是全域或 table field 執行期改寫、動態 alias 等間接情形，不能用字串陰性代替完整 VM 環境證明。

來源：`N31–N33`、`S25–S26`；controller 初始化、4C1E10 其餘 scene prepare 及資源 lifecycle 沿用既有 lifecycle 原稿，不以少量末段 bytes 宣稱整個流程都重新全面驗過。

## 6. 四種未知與 Server 開發要求

### Client 待逆向

1. 第一個正常 `.mef` caller 仍須有原件閉合：具體函式／腳本呼叫點、filename 或 buffer 的 producer、對應已註冊 loader，以及執行 context。`require` / `debug.debug` 的 library registration 不能替代這一鏈。
2. Boot / Logic / Coroutine / ai、UI/Table 已知後續檔案及 TutorialMain 相關內容沿用已發布完整解析與同輪 scripts 結果，均不列成新的缺檔阻塞。只有出現新原件資料流指出未涵蓋的全域改寫、table field 替換、動態 alias 或其他執行環境時，才沿該具體來源擴展。
3. 同輪主線已將 `6F4DD0`、`6F4F40`、`4AD0A0 → 6F5A70` 的直接 caller 和 name / argument 來源閉合為固定名稱，沒有來包字串控制函式名的正向鏈；三個 qbase callback body 也由 scripts 支線接回旗標邏輯。這些新結果由整合稿及其 named-calls / scripts 證據負責，本包不把這條已查支線保留成假設中的未知 Server 入口。
4. `debug.debug` 是否被任何正常既有 Lua 觸發，沒有具體原件 calling statement；本次只證其原生註冊和 stdin → parser → executor。

### Server 待開發

1. 已知正常 UI / 場景流程的後端資料、角色／場景狀態與回覆，仍由 Server 提供相容實作。對本報告的固定 Synopsis 入口，Server 不能把一個不存在的 `.mef` push opcode 當成實作捷徑；須依既有已證 scene / login / tutorial 契約整合。
2. 若後續原件證實 `require` 或 `DoFile` 讀某個原生已存在檔案，Server 應依遊玩規則提供促使該既有流程前進的資料及事件。應用規則、持久化與流程決策是 Server 設計需求，無須還原官方 Server 內部實作；但目前未知的 wire / caller 不能填成自訂欄位。
3. `LUA_PATH`、stdin 或注入 debug command 不是本次確認的 Client 收件介面。本報告不產生新 Server 命令、不要求修改 Client、不將未閉合路線寫成可直接開發的 `.mef` 傳輸契約。

以上是交由主線／S00 去重的需求界線，沒有另建平行 RR / REQ 台帳，也不宣稱 S00 已接受。

### 跨功能待整合

將本次三種能力分類接到主線已完成的 native named-call 調查、scripts 動態 consumer／callback 原件結果及 archive path mapping。S00 已解析的啟動與 Event 腳本是覆蓋基準；不因本機散檔不齊就重設研究阻塞。後續擴展必須由新的實際 consumer、registration、全域／table 改寫或其他執行環境證據導引。現有已完全閉合的 0047 / review / bootstrap 可直接引用。

### 待遊玩驗證

本輪全為靜態研究。未驗證 current page 真正切換順序、control 700 可見文字／可點狀態、scene gate 在玩家流程中的 runtime 值、stdin 可用性或腳本載入成功。這些不得由 bytes reproduction PASS 代替。

## 7. 重驗方式、結果與包內檔案

在保存同一原件與本包的環境執行：

```bash
python -B reproduce.py \
  --bin /workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

它只讀 BIN、包內 JSON，以及 `git ls-tree` 的指定 commit。`objdump` 只解碼原件 bytes；不執行 Client 或 Lua。`--repo` 可省略，此時仍驗 native windows、xref 範圍和語意 anchor，但不檢查 Git tree provenance。`sources/` 若未隨包發布，verifier 只略過可選本地偽碼副本核對，已 pinned 的 repo path / blob 仍能用 `--repo` 重驗。

驗證涵蓋：81 個有限原生記錄（37 code windows、16 data windows、28 C strings）；所有 code window 的指令 bytes 逐項拼回原區間、起訖邊界；11 個指定 target 的 literal / E8 / E9 候選；兩組 RTTI、vtable slot、`0xF4248` switch entry、debug / require 註冊及 `GetModuleFileNameA` import；44 份 pinned 來源條目。不是對整個 Client 做完整 control-flow proof，也不是所有 indirect call / 動態 Lua 名稱的窮盡證明。

| 檔案 | 內容 |
| --- | --- |
| [native-windows.json](native-windows.json) | VA / raw / hex / hash / instructions，第一手 evidence windows |
| [native-disassembly.txt](native-disassembly.txt) | 同一批 code windows 的可讀原生指令 |
| [tables.json](tables.json) | registration / RTTI / vtable / switch / import 的解碼結果 |
| [scoped-xrefs.json](scoped-xrefs.json) | 11 個具體 target 的限定 raw 候選，保留 scope |
| [source-manifest.json](source-manifest.json) | 原件 hash、commit / path / blob、偽碼原始換行 bytes hash |
| [reproduce.py](reproduce.py) | 獨立唯讀重驗器 |

本分工交付時保留「尚未找到首個正常 `.mef` caller」狀態；已完成的是上述三條選定支線的實際入口、資料來源、關鍵 gate 與 parser / executor 或固定 loader 的有界追查。後續應由新的具體原件入口導引，不重做已閉合的啟動／Event／named-call 清冊，也不以 library 能力等同 Server 可傳輸時機。
