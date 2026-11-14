# Lua 記憶體 parser、執行入口與 `.mef` 名稱的能力邊界

日期：2026-11-14。整合附件：`parser.md`；原始研究階段產物由主稿整合發布。原件 BIN-first；本稿是有界靜態原件核對，未執行目標。作者 bytes 核對不等於 T01 `FULL-PASS`。

## 1. 可直接採用的結論

**這個 Client 有真正的「記憶體 bytes + 長度 → Lua parser → Lua VM」路徑，parser 本身不要求 `.lua` 或 `.seq` 副檔名。**若已有可達 caller 把某資源路徑交給遊戲 loader，而且該路徑實際解析到合法 Lua 內容，名稱以 `.mef` 結尾並不會在本次核對的 loader/parser 層遭拒。這個結論只表示「取名 `.mef` 的 Lua 內容可用同一 loader」，**不能把任意原生 MEF 資料、MEF 容器或另一種事件 DSL 宣稱為 Lua 可解析格式**。

啟動入口仍是必要條件。已核對的路徑有遊戲原生 caller、Lua 全域 `DoFile`、`lb.DoFile`、標準 `loadstring`／`load`／檔案庫；它們各自需要既有執行中的程式、Lua stack 參數或本機可解析資源。**本稿沒有發現 Server 收到一個任意 blob 後直接把它交給這些 parser 的新資料通路。**函式存在、callback 可間接呼叫與傳輸入口已打通是三個不同命題。

主要新增證據：

- `6FE860` 在 `6FE892` 比較 stream 首 byte `0x1B`，選 `70D680` binary loader；其餘走 `70E420` text parser。不是按檔名分流。
- `70D5F0` 精確比對 12-byte header：`1B 4C 75 61 51 00 01 04 04 04 08 00`。BIN 另有 Lua 5.1.3 自述字串。載入 binary 後還會做 code 結構檢查。
- `6F5A50` 是執行 thunk，實際呼叫 `6FE550`，後者經 `6FE1C0` 準備 Lua call，再到 `6FC550` opcode VM。不是 E14 所寫的 error-handler callback。
- 零 direct caller 的 `6F48A0` **有實際 Lua 註冊入口**：`6F43E3` 把它註冊為全域大寫 `DoFile`。不可再把零 direct call 說成不可達或未使用。
- `lb`、`Q` 及正式場景載入的 owner 指向同一全域 Lua wrapper `FDF3C8`；前置資源收集另有 `FE1EEC/FE1EF0` Lua state。`FB73F0` 不是 Lua state。
- 原始檔案 buffer 是暫時來源；解析產生的 Proto、code、字串、closure 由 VM allocator 另建。遊戲 loader 完成頂層呼叫後釋放來源 copy。不能將「Lua 物件仍存活」說成「收到的原 blob 永久放在某固定地址」。

## 2. 原件、基線與本稿邊界

| 項目 | 固定身分／範圍 |
|---|---|
| 原始 BIN | `/workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin` |
| 大小 | 12,472,320 bytes |
| SHA256 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| 映像 | PE32 i386，ImageBase `00400000`；所有 VA/raw 由 PE section 表轉換 |
| 既有主線快照 | `ba5f96dfa94d734cbded291fb8887f50426bfa77` |
| 已讀基線 | `governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md`，blob `6fc6018a3dd5119cbd927fa183cb4228229d0dd7` |
| 原件證據 | `native-windows.json 的 parser group`：64 windows、10,244 bytes，含 VA、raw、hex、SHA；`native-windows.asm 的 parser group` 為同窗 objdump |
| Targeted xrefs | `parser-xrefs.json`；僅列明的 Lua 入口 literal pointer 及少量初始化／resume direct targets |
| 字串證據 | `native-windows.json 的 strings/parser`：78 個定向字串，含實際 bytes、raw、SHA |
| 既存 Ghidra 輔助讀本 | `source-manifest.json 的 repository_sources`：28 筆 pinned source record；只作導航、原件 bytes 為結論依據 |

基線已有 `6F4C20` 唯一 direct call `4A12E7`、`6F4A50` 的 15 個 direct callers、`6F48A0` 無 direct call、`6FE990` 的已知 direct caller 清冊、standard `load`／`loadstring` 與各網路 handler 的有界陰性分析。本稿不把這些舊項目重稱新發現，也沒有重掃 whole-network-table、所有資源檔名或全部 `.seq`。

本稿追查範圍是已知 loader 的下游解析／呼叫鏈、定向 address-taken／間接入口、兩個 Lua context 及來源 buffer 生命週期。未試造 wire，未證明任意未知間接資料流不存在。

## 3. 接受的 bytes：首 byte 與固定 Lua header，不是副檔名

### 3.1 One-shot memory reader 到 protected parser

`6F70E0` 接收 reader userdata 中的 `{pointer, length}`。`6F70E6` 讀 length；非零時在 `6F70F4` 輸出長度，`6F70F6` 將 userdata.length 清零，`6F70FD` 回傳原 pointer。下次讀取回傳 NULL。它不開檔、不寫檔，也不解釋路徑。

`6FEE30` 在 stream 沒有緩衝資料時，經 `6FEE48 call eax` 呼叫 reader。它將剛取的 byte 放回 stream 狀態後回傳 peek 值，因此 binary header loader 仍讀得到第一個 `0x1B`。stream 精確讀取 helper `6FEE90` 經相同 callback 取得 bytes，`6FEEF6` 用 memcpy 複製要求的部分；若 reader 結束而仍缺 bytes，回傳缺少的長度。

`6FE990` 把 stream、chunk name、parser 暫存 buffer 包入 userdata，`6FE9BC` 選 callback `6FE860`，`6FE9C7` 進 `6FE770` protected call。完成後它經 VM allocator 以 new-size=0 釋放 parser 暫存 buffer，再回傳 status。

這裡的 `6FE990` 具有 Lua protected-parser 的語意，但編譯後使用暫存器／stack 的 ABI，不能把地址直接當作未修改的公開 `lua_load` C ABI 來呼叫。`6F4C20` 也不是一個可隨便傳一個 pointer 即成功的標準 C 函式：已證 caller `4A12E7` 同時以 `EDI=&FDF3C8`、`ECX=length`、stack argument=buffer 建立所需 context。

### 3.2 Text / binary 分流與 binary header

`6FE860` 的關鍵機器碼：

```text
6FE871  call 6FEE30          ; peek stream 首 byte
6FE88D  mov eax,70D680
6FE892  cmp ebx,1Bh
6FE895  je  6FE89C
6FE897  mov eax,70E420
6FE8A8  call eax
```

`70D5F0` 在 stack 產生預期 header，`70D61F` 讀 12 bytes，`70D640..70D653` 逐 DWORD 比對：

| Header offset | 期望 bytes | 欄位解讀 |
|---|---|---|
| `0..3` | `1B 4C 75 61` | Lua binary signature |
| `4` | `51` | Lua 5.1 bytecode version |
| `5` | `00` | format 0 |
| `6` | `01` | little-endian |
| `7` | `04` | `int` 4 bytes |
| `8` | `04` | `size_t` 4 bytes |
| `9` | `04` | instruction 4 bytes |
| `10` | `08` | Lua number 8 bytes |
| `11` | `00` | number 非整數型格式 |

實際三個常數 writer 是 `70D60A: 61754C1B`、`70D611: 04010051`、`70D618: 00080404`。`C0C120` 的完整來源字串自述 **Lua 5.1.3**；binary header 只表達 5.1 格式，不應把 `0x51` 解讀成 patch release 5.1.3。

`70D680` 對 chunk name 只處理診斷顯示：以 `@`／`=` 起頭時略過第一字元，以 ESC 起頭時用 `binary string` 代名。它沒有取副檔名或按 `.mef`／`.seq` 判斷格式。`70D5F0` mismatch 走 `bad header`，不足資料走 `unexpected end`；`70CC28` 將這類 binary syntax error 以 status 3 丟回保護層。

header 一致也不是接受任意後續 bytes。`70D3A0` 載入 function prototype 的 source、line、upvalues、parameters、vararg、stack size、code、constants、子函式與 debug 資料。`70D5BD` 呼叫 `6F82D0` 檢查 code，失敗走 `70D5C9` 的 `bad code`。因此 Lua 5.2／5.3／5.4 binary header，或只把任意資料改前綴／檔名，都不是此 loader 的相容內容。

上表欄位名稱與 protected-parser 名稱另以 [Lua 官方 lundump.c](https://www.lua.org/source/5.1/lundump.c.html) 及 [ldo.c](https://www.lua.org/source/5.1/ldo.c.html) 比對。官方線上頁面目前列 5.1.5，本 BIN 自述 5.1.3，這只是結構語意對照；本稿沒有以線上 source 代替原件或宣稱兩者整份相同。

### 3.3 文字解析與 BOM 差異

非 ESC 首 byte 走 `70E420`。它以 `6FF2C0` 建 lexer 狀態、`70DFB0` 建 function parser 狀態、`711B20` 解析 chunk，並在 `70E4E6` 檢查 EOF token `0x11F`，最後 `70E51A` 完成函式。`C0BEC0..C0BF3B` token 表與對應字串包括 Lua 的 `and`、`function`、`local`、`return`、`while`、`...`、`<name>`、`<eof>` 等。這是 Lua 語法，不是因 `.mef` 名稱切換到另一個事件語法。

合法來源應符合此 Lua 5.1 系列文字 parser 與實際註冊 API；不同版本文字只有其相容子集才可在這裡使用。完整語法說明可參考 [Lua 5.1 官方手冊](https://www.lua.org/manual/5.1/manual.html)，本稿未對每一條 grammar production 重新反編譯。

各入口對 UTF-8 BOM 的處理不同：

| 入口 | 檢查與去除 `EF BB BF` | 本稿能保證的能力 |
|---|---|---|
| `6F4A50` 路徑 loader | 有，BOM 分支 `6F4B0B → 6F7110(ptr+3,len-3)` | 同一路徑可接受所支援的文字／binary bytes；資源需要先被 `714770` 找到 |
| 全域 `DoFile → 6F48A0` | 有，`6F496F → 6F7110(ptr+3,len-3)` | Lua stack 給路徑，走遊戲資源層，並載入／執行 |
| `lb.DoFile → 4A1230 → 6F4C20` | 本函式鏈沒有去 BOM | 直接對完整 ptr/length 分流；不要將前兩條的 BOM 容忍度套用過來 |
| standard `loadstring`／`load` | 本次已核 memory wrappers 沒有同樣的遊戲 BOM 去頭 | 能以字串／reader 編譯 Lua；不等於呼叫時自動執行 chunk |

`6F4C20` 與 standard memory wrappers 的能力應保守描述為「提供正確且無額外未處理包裝的 Lua bytes」。本稿沒有執行帶 BOM 的負向測試，不把靜態未見去頭擴張為所有 locale 下的完整 lexical 判決。

## 4. 從 parse 到 execute、yield 與 resume

### 4.1 Parse 成功只產生 closure

`6FE8A8` 的 text/binary parser 回傳 Proto。`6FE8BB` 呼叫 `6FD730` 配置 closure，`6FE8C5` 將 Proto 放入 closure+10；後續初始化 upvalues，將 closure 放到 Lua stack 並設 TValue type=6，top 增加 16 bytes。

這一層未跑 Lua opcode。因此 `loadstring` 的 `70648C → 6FE990`、`load` 的 `706705 → 6FE990` 成功後，只回傳一個 compiled function。成功回傳 branch 分別 `706498`、`706711`；失敗則回 `nil` 與 error。要產生遊戲行為仍需呼叫該 function。這兩個 API 在基線已識別，本稿補其和 parser／closure 的實際銜接。

### 4.2 遊戲 loader 立即 protected-execute 頂層 chunk

`6F4A50`、`6F48A0`、`6F4C20` 在 parse status=0 後，將剛壓入 stack 的 function slot 及 wanted-results `-1` 傳入 `6FE770`；callback 是 `6F5A50`。

```text
6F5A53..6F5A60  讀取 {function slot, wanted results}，傳入 L
6F5A61         call 6FE550
6FE59F         call 6FE1C0
6FE5A7         test eax,eax
6FE5AE         call 6FC550       ; Lua branch
```

`6FE1C0` 先檢查 callable TValue、再以 closure+6 區分 Lua closure 與 C closure。Lua 分支準備 stack／call-frame／Proto code pointer 並回 0；C 分支在 `6FE35C..6FE360` 取 closure+10 的 native function pointer 並間接呼叫。這解釋了 Lua 可呼叫已註冊的本機 API，但**並非 parser 會將任意輸入 bytes 當 x86 函式執行**。

`6FC550` 實際 VM 在 `6FC58E` 取 4-byte instruction、`6FC590` 推進 PC，`6FC5E5` 取低 6 bits opcode，`6FC5EC` 檢查 opcode 上界 `0x25`，`6FC5F1` 經 `6FD694` jump table 分派。可因此把本鏈閉合為 Lua opcode execution，而不是停在「疑似 execution wrapper」。

### 4.3 Protected call 是錯誤回復，不是非同步下載機制

`6FE770` 保存 stack／call-frame／C-call depth／error-function context，再到 `6FDBA0`。`6FDBA0` 建立 `L+70` 的 error-jump context，`6FDBDC` 呼叫 setjmp 類函式；正常路徑 `6FDBF0` 間接執行 callback，兩種退出路徑都恢復原 `L+70`。`6FE770` 的非零 status 路徑回復 VM 狀態；0 為正常完成。

**E14 必要更正**：E14 把 `6F5A50` 標成 Lua error handler；E15 只證 protected callback 骨架，仍明言 callback 精確語意未閉合，沒有修正該標籤。本輪直接證明 `6F5A50 → 6FE550 → 6FE1C0/6FC550`，應改稱 **execution thunk／受保護執行 callback**。真正的遊戲 error-report 路徑是 `6F47A0`；它不是此執行 thunk。

### 4.4 Coroutine 的 yield／resume 另有 gate

standard coroutine table `C0BC68..C0BC97` 將 `resume` 綁 `707230`、`yield` 綁 `707480`。已核 resume helper 的 `7071CD` 呼叫 `6FE6D0`；其 gate 接受 status=1 的 suspended coroutine，或 status=0 且位於初始 call-frame 的 coroutine，否則產生 `cannot resume non-suspended coroutine`。它以 `6FDBA0` 保護 callback `6FE5E0`，後者在 `6FE650` 重新進 `6FC550`。

`707480` 先在 `707492` 比較 C-call depth 與 base C-call depth；跨 C-call boundary 的不允許情形走 error。允許時 `7074B1` 寫 `L+6=1`，回 `-1`；`6FE1C0` 的 C closure branch 識別負返回值並回 yield 狀態。

這是已執行 Lua coroutine 的排程生命週期，**不表示一個來源 buffer 能在任意時刻到達、被保留成 pending script，或由 parser 自動等待網路補資料**。本輪 `6F70E0` 是 one-shot；standard `load` 能反覆向 Lua reader 要字串，仍要有可達 reader function 與其實際資料來源。

## 5. 可達入口與來源：address-taken 補查

| 路徑 | 原件證據與 bytes 來源 | 是否自動執行／能力邊界 |
|---|---|---|
| 原生 `6F4A50(path)` callers | 基線 15 direct calls；本體 `714770` → vtable+2C length、+38 data → private copy | parse 成功後執行；已知 scene caller 選既有 `.seq` 路徑，改檔名不會自動改 selector |
| 全域 `DoFile` | `6F43E3 push 6F48A0`、`6F43E8 → 6F55B0`、`6F43F6` 名稱 `C42590="DoFile"`、`6F4400 → 6F5790` 登記到全域；`6F48A0` 從 Lua stack 取路徑、走 `714770` | **真實 indirect 入口**；需要正在執行的 Lua call；不是新網路 handler |
| `lb.DoFile` | `4A1B68` 寫 `FE17A0=4A1230`，`4A1BB9` 以 `4A2200` 註冊 `DoFile`；`4A2200 → 4A2A70`，`4A2A74` 讀該 function pointer，`4A2AC7` 間接 call；`4A1230` 取本機資源 copy | `4A12E7 → 6F4C20` 直接 ptr+len 執行；其原件 caller 的來源已閉合到資源層 |
| standard `loadstring` | 表 `C0BBD8` name / `C0BBDC=706400`；`706418` 從 Lua stack 取得 string 與 length；reader `6F70E0` | 只編譯並回 closure；既有 stack 字串不代表 Server blob |
| standard `load` | 表 `C0BBD0` name / `C0BBD4=706620`；輸入需 callable；reader `706540` 在 `706597` 呼叫 Lua function，取其字串回傳 | 只編譯；reader 可返回多段字串，但本稿沒有找到網路內容提供者 |
| standard `loadfile`／`dofile` | lowercase 標準庫 table 分別 `7064D0`／`706740`，走 `6F6E60` 的 stdio FILE/stdin reader | 與遊戲 `DoFile`、`lb.DoFile` 不同；不可將 STP lookup 或 BOM 規則混用 |

`6F48A0` 的零 direct caller 基線沒有錯，但不充分。此次 `.text/.rdata/.data` 的 literal absolute-pointer 定向掃描，找到 `6F43E4` 裡的 `6F48A0` immediate；反組譯後確認上述註冊。因此今後應寫「無 E8 direct caller，但可由全域 `DoFile` callback 到達」。

同一掃描的其餘結果：`6F4C20`、`6F4A50`、`6FE990` 沒有 literal pointer 命中；`4A1230` 命中 `4A1B6E` 註冊欄位；`706400`／`706620` 命中上述 `.rdata` tables。這是精確搜尋範圍內的結果，不能排除 runtime 計算地址、另一模組或未涵蓋的動態建立路徑。反之，找到 Lua/native callback 也不等於找到 Server payload→callback argument 的資料流。

`lb.DoFile` 還有一個觀察結果限制：`4A1316` 在資源開啟失敗時直接回 0，而 `6F4C20` 執行成功亦回 0。故 `lb.DoFile` 返回 0 **不能單獨作為已成功讀取／執行的確認訊號**。

## 6. Lua state 真正位置：正式執行共用、前置環境獨立

定義 `W = &FDF3C8`（wrapper），`L = [W]`（main Lua state）；`M = &FB73C0`（場景 manager）。

| Owner／用途 | 可回核的初始化與取用 | 結論 |
|---|---|---|
| 全域 Lua wrapper | `6F4383 → 6F74B0` 新建 state；`6F4396` 寫 `[FDF3C8]=L`，+4=0、+8=1；`6F43AF → 6F7660` 開標準庫 | W 內存的是 state pointer，不是 `.mef` raw buffer |
| 場景 manager | `48D76B ESI=W`、`48D770 EAX=M`、`48D775 → 560600`；`56060B mov [eax],esi` | `[M]=W`，不是直接 L，也不是 `FB73F0` |
| `Q` table | `560609` 傳同一 W；`56060D → 565E40`；`565E57` 寫 `FE2774=W`，`565E88` 以 `C10604="Q"` 建 table | Q 註冊於正式全域 L |
| `lb` table | `4A09AB push W → 4A14D0`；`4A14E2` 寫 `FE1774=W`，`4A151D` 名稱 `C06220="lb"` | lb 與 Q 的 main registration L 相同 |
| 正式 `.seq` 載入 | `561C7A mov ecx,[manager]`、`561C7D → 6F4A50` | 正式第二次載入使用 W／L，因此其已註冊環境可見 Q 與 lb |
| Tutorial owner 注入 | `48D7D4 ESI=W`、`48D7D9 EAX=&FC0F84`、`48D7DE → 4A88E0` | 本輪確認傳入同一 wrapper；具體 Tutorial methods 由 executor/API 報告列明 |
| 前置場景資源收集 | `55C69E → 6F74B0` **另新建** Lp，`55C6B3` 寫 `[FE1EEC]=Lp`；配置 wrapper Wp，`55C6D6` 寫 `[FE1EF0]=Wp`；`55D7BE` 取 `[owner+4]` 給 `55D7C2 → 6F4A50` | 前置 Lp 與正式 L 分離，不可合併兩個 API 集合 |
| `FB73F0` | `56025A → 7CD2B0`、`560263` 存 pointer；`7CD2B0` 初始化多組 float 與字串 | 不是 Lua state，不可把此地址當腳本記憶體基址 |

`560796`、`5607A2`、`5607AE`、`5607BA` 用正式 W 依序載入 `Coroutine.lua`、`Boot.lua`、`Logic.lua`、`Event/qbase.lua`。全域標準庫由 `6F7660` 經 `C0C0D8` 表進 `707790`；`7075DC → 6F6590` 註冊 base table `C0BB90`，`70779E` 註冊 coroutine table。因此 standard memory APIs 在此正式全域環境有具體註冊鏈，不只是孤立未用程式碼。

前置 constructor 沒有同一個 `6F7660` 開庫呼叫；`55D6A0` 在前置 Lp 註冊六個場景資源 callback，`55D7E0` 另綁前置 stubs。executor 子報告進一步閉合 `Register` 會在 Lp 執行 scene 函式以收資源，其環境只有該階段的有限 API。因此「正式 L 有 `lb.DoFile`」不足以保證把此呼叫無條件插進 `.seq` 就能通過前置階段。主稿應合併雙 VM 契約，而不把所有查到的 API 當成每個載入階段都可直接呼叫。

上述相同 L 的證據是 registration/load owner 的 main state 相同。本稿不把 coroutine 的獨立 execution stack pointer 說成恆等於 main L，也沒有將 API 可見性擴張為所有遊戲狀態下都允許其動作。

## 7. 記憶體生命週期與路徑的角色

| 層次 | 實際持有內容 | 原件證據與有效期間 |
|---|---|---|
| 資源路徑 | 呼叫者給定的 C string／場景組成的 path；由資源層查索引或開本機檔 | `6F4A99`／`4A125E → 714770`。路徑用來找到來源；不是 Lua VM 後續每個 opcode 的檔案讀取位置 |
| 資源物件 | vtable+2C 提供 length，+38 提供 decoded／read data | loader 讀完後以 vtable+4 釋放。STP 優先與 disk fallback 的詳細生命週期沿用資源子報告 |
| 遊戲來源 copy | `malloc(length+1)`、memcpy、補 NUL；仍以明確 length 餵 parser | `4A127F`／`4A1295`／`4A129A`；`6F4ABA`／`6F4AD0`／`6F4AD5`。頂層執行返回後 `4A12F8` 或 `6F4BC7` free；global DoFile 同樣 release/free |
| Stream reader | 只借用來源 pointer、維持 remaining length／current pointer | `6F70E0`／`6FEE30`／`6FEE90`。沒有在這層建立下載 cache 或 persistent file |
| Parser 暫存 buffer | 字串／lexer 暫存 | `6FE990` 在 protected parse 後以 VM allocator 釋放；不能當持久 script registry |
| Proto、code、strings、closure | VM allocator 建立的物件及 arrays | `70D3C5` 分配 Proto，`70CD2C` 分配 code、`70CD75` copy 到 code array，`70CCAC` intern字串；`6FE8BB` 配置 closure 並掛 Proto |
| 後續可執行 Lua 物件 | 被 global table／registry／closure／coroutine 等引用的函式與資料 | 生存期由引用、GC、state close 決定；本輪 `6F75F0` 是 state close path。不能給出所有 script 固定地址或一律保留至離開場景的承諾 |

因此可以回答「是否一定要先存在一個磁碟 `.mef` 才能讓 Lua parser 工作」：**parser 不需要磁碟檔，pointer+length 足夠；已知遊戲入口的內容供應者主要是本機資源。**若只問已安裝 Client 的 Server 能力，仍必須再證明一條合法現存入口能把 Server bytes 供應給該 memory interface；這個缺口不會因 parser 可讀 memory 而自動消失。

名稱以 `.mef` 結尾也沒有另外的記憶體區。若它被當作 Lua 載入，將沿相同來源 copy、Proto、closure、VM state 流程。若它其實是原生另一種 MEF 格式，本稿未證實其 parser，應保留獨立待查。

## 8. 對 Server 開發與未解邊界的分類

| 分類 | 應採用的需求／仍缺的證據 |
|---|---|
| Client 已確認 | memory parser 存在、首 byte text/binary 分流、精確 Lua 5.1 header、game load-and-execute、Lua callback 入口、正式與前置兩個 context、來源 buffer 釋放 |
| Server 開發需求 | 若沿已證場景 key 協定，Server 只排程 Client 已有且狀態允許的場景；資源發布需符合實際 loader 的 path／內容／BOM／Lua version／雙 VM API 契約。不能用「副檔名任意」推導任意 Server path 或任意腳本 payload 協定 |
| Client 待逆向 | 是否另有合法 incoming payload field → Lua string／reader → load／execute 的現存資料流；若要稱原生 MEF，必須獨立取得／確認其格式與 parser。本稿的 targeted pointer negative 不能代替全流證明 |
| 跨功能待整合 | loader/resource provenance、executor/Q/Tutorial API 與前置 Register、已證 receive/scene/busy 時窗；本稿只補 parser/state 部分 |
| 待遊玩驗證 | 指定已部署資源被實際 caller 開啟，前置與正式環境皆完成所需效果；parser bytes 靜態核對不等於完整場景可玩 |

若 Server 需求是「把新檔案 bytes 直接送來並立刻執行」，目前缺的是 **相容接收／內容交付／入口契約**，不能以新 opcode、chunk format 或固定 sleep 猜補。若需求是「已可用資源何時能啟動」，本稿證明可用的 parser/executor，但排程仍受上一份 delivery-windows 報告與實際 scene manager gate 約束。

## 9. 重驗與來源索引

主稿的證據包已將三個支線與資源根目錄補查整合。請依 [README](README.md) 使用 `verify_evidence.py`：只讀原始 BIN／Event.stp／Table.stp，核對 PE 映射、bytes／SHA、名稱全域所在零初始化區、六個既知 member 及 qbase 選取指令，不執行 Client 或 Lua。

本 parser 支線原先獨立核對結果為 64 個窗、10,244 bytes、78 個定向字串；28 個固定 Git 導航來源的 blob／SHA 均已核。整合 manifest 保留這些紀錄。程式碼視窗仍以 parser group 區分；窗口可能與其他 group 重疊，不能把相加數當唯一覆蓋量。

本輪修正：E14 的 `6F5A50` error-handler 標籤改為 execution thunk；E15 的保護框架證據有效但未曾閉合該 thunk；E16 兩次 load 的 context 由本輪雙 VM 證據補足。作者原件核對不等於 T01 FULL-PASS 或任何 runtime 相容性驗收。
