# KR：MEF parser／executor、可實作內容與 Client 儲存位置

- 工作分支：既有 `extra/roy1`；未新增 branch。
- 研究起點：2026-11-14 19:06:24（UTC+8）。
- 主線證據基準：`ba5f96dfa94d734cbded291fb8887f50426bfa77`。
- 本輪工作基準：`be56ab2e6c87358230db3b60275ca6c7f3bf8195`，即前輪 Server 可傳遞時窗分析。
- 使用者本輪問題：「請分析 .mef 的 parser／executor 以確認 .mef 該實作哪些內容，另外目前主程式都沒 .mef，client 的 .mef 是否存放在記憶體？或是儲存在特定路徑？」
- 提交授權：接續同一工作串的「分析請推上 git」，包含追加的 parser／executor／儲存位置研究；僅本分支研究文件與證據。
- 狀態：**已完成本輪可達 Lua parser／executor 及名稱儲存的有界原件研究；原生 MEF 格式與其實際 consumer 仍未閉合。** 本稿不宣告 MEF 全功能完成、RR 結案、S00 ACCEPTED 或 T01 FULL-PASS。

## 1. 直接回答

**Client 記憶體裡確實有 `.mef`「名稱」，但目前沒有證據證明那些名稱對應的 MEF 檔案本體已載入 RAM，也沒有找到一個可確認的專用 MEF 目錄。** 已接通的資料流是 `Table/_MapList.xml → trigger 字串 → 依 map ID 索引的名稱表`，還沒有接到 `開啟該 trigger 檔案 → 解析 → 執行`。

另一方面，Client 有完整且實際可達的 **Lua parser／executor**。它接受 Lua 5.1 系列文字，以及符合本機格式的 Lua 5.1 bytecode；本輪閉合了首 byte 分流、header、Proto／closure、受保護呼叫、opcode VM、coroutine 與兩個不同 Lua 環境。**如果某份內容本來就是相容 Lua，名稱取成 `.mef` 不會在這條 parser 鏈遭到副檔名拒絕；但必須有實際 caller 把它交給 loader。** 這不能倒推原本那些 `.mef` 就是 Lua，也不能倒推 Server 已有任意檔案上傳後執行的封包。

對 Server 開發，現在可落地的是：依已證 Client 介面排程場景、同步世界物件與狀態，以及自行設計地圖事件／波次／完成條件／獎勵等 Server 規則。若要發布 Client 執行內容，須遵守既有資源路徑、Lua 格式、前置收集與正式執行兩環境，以及啟動／結束狀態契約。**不能先假設有原生 MEF grammar，再按猜測造檔。**

| 使用者問題 | 本輪可確認答案 | 還不能宣稱的部分 |
|---|---|---|
| `.mef` 的 parser 是什麼？ | 已閉合可用的 Lua text／binary parser；它按 bytes 分流，沒有副檔名限制 | 尚未證明 `_MapList.TRIGGER` 所指原生 `.mef` 會進這個 parser，或原生 MEF 另有何種格式 |
| executor 能做什麼？ | 已證 Lua opcode 執行、註冊的遊戲 API、場景 coroutine、前置依賴收集 | 不等於任意戰鬥時刻的常駐事件引擎，也不等於 Server 可直接傳腳本執行 |
| 主目錄沒有 `.mef`，是否放 RAM？ | 名稱被深拷貝到 heap／字串節點；已載入的 Lua 程式也會形成 VM 物件 | 名稱、Lua Proto、原始 MEF bytes 是三種不同內容；後兩者沒有被 `.mef` 名稱本身證明 |
| 是否在特定路徑？ | 名稱來源是 `Table.stp` 的 `Table/_MapList.xml`；已知腳本在 `Event.stp` 的虛擬路徑 | 沒有證據支持 `MEF/`、`Event/MEF/`、AppData／Temp 等專用位置，不能任選一個當成既定路徑 |
| 現在該實作哪些內容？ | 第 7～9 節列出可用呈現能力、內容契約與 Server 開發需求 | 這些是相容實作需求，並非原生 MEF 的已還原欄位或 opcode 清單 |

完整下鑽筆記：[parser](MEF-parser-executor-storage-20261114/parser.md)、[executor](MEF-parser-executor-storage-20261114/executor.md)、[storage](MEF-parser-executor-storage-20261114/storage.md)。原件與重驗方式見 [證據索引](MEF-parser-executor-storage-20261114/README.md)。

## 2. 原件身分與研究方法

| 原件 | 大小 | SHA256 |
|---|---:|---|
| `02-Tartaros.bin` | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `06-Event.stp` | 11,241,597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| `07-Table.stp` | 5,248,784 | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |

原件位於本工作區 `/workspace/scratch/b43c6175f310/project_sources/`。BIN 是 PE32 i386，ImageBase `00400000`。本輪只讀原件、擷取有界機器碼／資料窗、解碼六個已知 STP member；沒有啟動、附加、載入執行或修改原 Client，沒有執行資源中的 Lua，也沒有改 Server。

前輪已讀的共用指令、最新 main、T01 狀態、RR／收件箱及現行 MEF 功能完成政策繼續適用。舊的全面 `.mef` 檔名／STP inventory、`FB74C0` literal 掃描、網路 handler 表等有界陰性成果直接復用，不重掃並冒充新發現。本輪新增的是：Lua parser 下游、address-taken callback、兩 VM 的 ownership／API 差異、名稱配置／釋放／指定 accessor 別名，以及 generic root／file opener。

來源與 Git blob 固定於 [source-manifest.json](MEF-parser-executor-storage-20261114/source-manifest.json)。Ghidra 偽碼作導航；本輪新增機器碼主張由 [native-windows.json](MEF-parser-executor-storage-20261114/native-windows.json) 與同窗反組譯支撐。既有跨功能結論會明列承接來源，不以字節核對自動提升其驗收狀態。

## 3. 記憶體裡的 `.mef`：目前證到的是名稱表

### 3.1 名稱來源與實際內容

`4F5640` 讀固定 `Table/_MapList.xml`，在 `4F5723..4F572A` 查 `trigger`，將文字建成區域字串。`4F581E → 4F7DF0` 依 map ID 取得名稱節點，**`4F582C → 403040` 深拷貝該字串到 node+10**。之後 `4F58C4` 釋放區域字串，`4F5D2D` 銷毀 XML document；node 所有的名稱仍可存在。

本輪只從已知 `_MapList.xml` member 定向取五個例子，沒有重做全部 MEF 名稱盤點：

| Map ID | `TRIGGER` 名稱 | `MAP` | `BOUND` |
|---:|---|---|---|
| 1 | `N_mushroom01_01N.mef` | `mushroom01D` | `mushroom01` |
| 19 | `N_mushroom12_01B.mef` | `mushroom12D` | `mushroom12` |
| 190 | `scenario_town000.mef` | `town000D` | `scenario_town000` |
| 635 | `scenario_chicken04.mef` | `mushroom12D` | `mushroom12` |
| 934 | `R_Phindous03.mef` | `mushroom12D` | `mushroom12` |

這些是 **metadata 引用**。只讀這個表不會把名稱對應的檔案內容讀入。表內同時有 `MAP`、`BOUND`、`TRIGGER`，也不能把三個資源 domain 的相似名稱視為相同檔案。

### 3.2 結構與生命週期

singleton 基址是 `FB7470`；trigger 容器在 `FB74C0`，head 在 `FB74C4`，元素數在 `FB74C8`。每個 tree node 配置 `0x30` bytes：

| Node offset | 原件支持的內容 |
|---:|---|
| `+00/+04/+08` | left／parent／right |
| `+0C` | key，與此容器的 map ID 查找對應 |
| `+10..+1F` | 16-byte 小字串區；長名稱時首 DWORD 為 heap chars pointer |
| `+20` | 名稱長度，不含 NUL；**不是 MEF 檔案大小** |
| `+24` | 字串 capacity；小於 16 用 inline，否則用 heap |
| `+28..+2B` | 不賦予 MEF payload 語義 |
| `+2C/+2D` | tree color／nil flag |

`403040` 的 `40304E` 讀來源長度，`4030F7` 複製 chars，`403103` 設長度，`40310A/403119` 補 NUL。另一個 `402BB0` 是 ownership transfer，不能通稱深拷貝；真正 trigger writer 用的是 `403040`。

`4F44B0 → 4F7FE0 → 504180` 清理此 tree：`50419E` 看 capacity，`5041AA` 釋放 heap chars，`5041C5` 釋放 node；`4F4869` 釋放 head。`425330` 的 singleton 初始化註冊 `_atexit(BCD1E0)`，而 `BCD1E0` 跳到 `4F44B0`。因此已接上退出清理，但不能推論所有釋放只能在退出發生。

### 3.3 不可把零初始化全域當成 BIN 內嵌 MEF

`.data` 從 VA `D61000` 開始，raw-backed 結束為 **`F8C800` exclusive**，虛擬 section 結束為 `FE83D8`。上述 `FB74xx` 全域位於 raw 檔案沒有覆蓋的零初始化尾段，沒有可以直接讀出的原始 MEF bytes。程式啟動後再配置 sentinel、nodes 與長名稱 chars。

本輪定向查 `425330` 的 32 個 E8 候選與九個第一 consumer；其實際 member offsets 為 `+100/+104`、`+110/+114`、`+120/+124`、`+130/+134`、`+00/+04` 或另一張 `+10` 寬字串表，沒有接到 trigger 的 `+50/+54`。這補強指定 alias 候選未接通檔案 consumer 的結論，**不宣稱已排除全部動態別名／間接 call**。完整分組與 raw 證據在 storage 筆記及 alias census。

## 4. 實體檔案、虛擬路徑與執行期物件

### 4.1 哪些內容確實在資源包裡？

本輪只讀取六個已知 member；每個 member 都保存 container hash、block ID、原件 offset／length、XOR 還原前綴、解碼後 hash。這些是實際檔案內容證據：

| 實體 carrier | 虛擬路徑 | 解碼後長度 | 內容 |
|---|---|---:|---|
| `Table.stp` | `Table/_MapList.xml` | 363,452 | XML，含 MEF 名稱 |
| `Event.stp` | `Event/SceneList.xml` | 158,269 | scene keys → 函式名稱等設定 |
| `Event.stp` | `Event/qbase.lua` | 11,836 | 符合下節 header 的 Lua bytecode |
| `Event.stp` | `Event/TutorialBase.lua` | 1,416 | Lua bytecode |
| `Event.stp` | `Event/TutorialMain.lua` | 5,480 | Lua bytecode |
| `Event.stp` | `Event/Sequences/Phindous_YuriandRazed_Boss.seq` | 1,571 | Lua 文字 |

最後一個 member 以 `-- TTEX Talk Scene File: DO NOT EDIT BY HAND` 開頭；`--` 是 Lua 註解，因此此例的 **TTEX 是文字註解，不是另一種 parser 的 binary magic**。它宣告 `Phindous_YuriandRazed_Boss` 函式，對應 SceneList 的 119／3。不能因副檔名為 `.seq` 就當成與 Lua 無關的自訂 binary 格式。

所以「主目錄找不到散裝腳本」本來就可能是資源包與虛擬路徑的結果。但本表證明的是列出的 `.lua`／`.seq`，**不是包裡已找到原生 `.mef`**。

### 4.2 Generic resource opener 不等於專用 MEF 目錄

沿前輪已證資源層，`714770` 先嘗試 package 來源，未取得時才走政策允許的 filesystem fallback。`FE4C94` 是相關 gate；其初始化為 0 的證據不代表未追完的所有程式路徑都不能改它。

本輪補到 `714030`：若 `FE3648` 啟用，先把 generic prefix `FE3548` 與 caller path 串接，嘗試壓縮／一般檔案；之後仍有直接 caller path 的嘗試。`713FF0` 初始化 prefix 區為零並令 enable flag=0。`713CC0` 配置 `0x10` file object，`713CFB → 89187B` 使用 path／mode 呼叫 `_fopen`；若 `FBA81C` 的可選內容檢查器提供 expected 值，後面還有 16-byte 比較，不能把存在於磁碟等同一定可用。

可確定的是 **generic prefix／相對 caller path／資源索引**，不是 `.mef` 專用搜尋目錄。未設定 prefix 的相對檔名仍依程序工作目錄解析；不可一概寫成「直接啟動 BIN 也一定以 EXE 所在目錄為根」。即使 launcher 能先落檔，也只解決交付與可見性，沒有替缺少的 consumer 決定讀取路徑。

### 4.3 「在記憶體」必須分層回答

| 層 | 保存什麼 | 能否當作 MEF 本體存在的證據？ |
|---|---|---|
| `_MapList` 名稱表 | map ID、檔名、字串長度／容量 | 不能；已確認是名稱 |
| 資源物件／來源 copy | 已實際開啟資源的 bytes | 必須先證明開啟的就是目標 `.mef`，本輪未接到 |
| parser 暫存 | stream／lexer buffer | 暫時解析資料，不是持久下載 cache |
| Lua Proto／closure／code／constants | 已編譯程式與被引用的資料 | 能證明 Lua 在 RAM 執行；不能由此認定原生 MEF 已存在 |
| coroutine／globals | 執行狀態與 Lua 引用 | 跟隨 VM 與引用生命週期，沒有固定 MEF 區域 |

`6F4A50`、`4A1230` 取得資源長度與資料後配置 private copy、補 NUL，以明確 length 解析。頂層呼叫返回後在 `6F4BC7`／`4A12F8` free 來源 copy；Proto、code、interned strings、closure 則由 VM 分配與管理。**原檔 bytes 釋放後，已建立的 Lua 函式仍可能被 globals／coroutine 引用。** 這解釋程式可在 RAM 繼續執行，卻不保證能找到一塊完整原始檔案映像。

另外仍有合理但未證的可能：這版 Client 只保留 shared metadata 中的 trigger 名稱，實際邏輯由 Server 使用，或該欄位是未使用／歷史介面。這些是假說，不能以未找到 consumer 直接擇一認定。

## 5. Parser：已閉合的實際內容格式

### 5.1 記憶體 reader、text／binary 分流

`6F70E0` 是 one-shot `{pointer,length}` reader：第一次回傳整段，將剩餘長度設 0，之後回 NULL。`6FE990` 以 `6FE860` 為 protected-parser callback。後者在 `6FE892` 比較首 byte：

- `0x1B`：`70D680` binary chunk loader。
- 其他值：`70E420` Lua text parser。

檔名在此用於 chunk 診斷，不決定格式。binary header 精確為：

```text
1B 4C 75 61 51 00 01 04 04 04 08 00
```

| 位移 | 值 | 契約 |
|---:|---|---|
| 0～3 | `1B 4C 75 61` | Lua signature |
| 4 | `51` | Lua 5.1 bytecode 版本 |
| 5 | `00` | format 0 |
| 6 | `01` | little endian |
| 7／8／9 | `04／04／04` | int／size_t／instruction 均 4 bytes |
| 10 | `08` | number 8 bytes |
| 11 | `00` | 非整數 number 格式 |

`70D60A/70D611/70D618` 在原件產生上述常數，`70D640` 開始比較；其後還有 Proto、code、constants、子函式、debug 資料解析與 `6F82D0` code validation。BIN `C0C120` 自述 **Lua 5.1.3**；header 的 `0x51` 只識別 5.1，沒有編碼 patch release。不能把現代 Lua／LuaJIT bytecode 或任意 binary 只改副檔名就交給它。

欄位語義另對照 [Lua 官方 5.1 lundump.c](https://www.lua.org/source/5.1/lundump.c.html)；線上版本標為 5.1.5，而本 BIN 自述 5.1.3。官方文件只作格式語義對照，本機接受 bytes 仍以原件常數為準。

### 5.2 哪些入口會 parse？哪些會 execute？

| 入口 | 來源與可達性 | parse 後的行為 | 實作要注意 |
|---|---|---|---|
| 原生 `6F4A50(path)` | caller 給 path，`714770` 資源層取內容 | 成功後執行頂層 chunk | 已知場景 selector 組成 `.seq`；放一個 `.mef` 不會自動被選中 |
| 全域 **`DoFile`** | **新增閉合**：`6F43E3` 註冊 `6F48A0`，名稱 `C42590` | 資源載入、parse、execute | 原先無 E8 caller 不代表不可達；需要 Lua 實際呼叫 |
| `lb.DoFile` | `4A2200 → 4A2A70 → [FE17A0]=4A1230 → 6F4C20` | pointer＋length parse／execute | bytes 來自本機資源；未接到新網路 payload |
| standard `loadstring`／`load` | Lua stack string／Lua reader callback | 回 compiled function，尚需呼叫 | compile 成功不等於遊戲行為已執行 |
| lowercase `dofile`／`loadfile` | 標準 stdio reader | `loadfile` 編譯並回 function；`dofile` 載入後執行 | 不可混用大寫 `DoFile` 的 STP／遊戲 loader 特性 |

`6F4A50` 與全域 `DoFile` 有 UTF-8 BOM 去頭；`lb.DoFile → 6F4C20` 沒有同樣處理。因此若選用已證 Lua 相容內容，**不帶 BOM 的 Lua 5.1 相容文字**是較少入口差異的作者格式建議。這是製作建議，不是證明原生 MEF 使用文字或任意 Unicode 字串皆能正確顯示；遊戲 API 的本地化編碼仍依既有資源／字串介面。

`lb.DoFile` 開檔失敗也回 0，成功的 parser／execute status 也可為 0。因此單看它回 0 不能作為 Server 的檔案已載入 ACK。

### 5.3 Executor 已經接到 opcode VM

parse 成功先建立 Proto／closure，壓入 Lua stack。遊戲 loader 之後呼叫：

```text
6FE770 protected call
  → 6F5A50 execution thunk
    → 6FE550
      → 6FE1C0（區分 Lua closure／C closure）
        → 6FC550（Lua opcode VM）
```

`6FC58E` 取 4-byte instruction，`6FC5E5` 取低 6 bits opcode，`6FC5EC` 檢查上界 `0x25`，`6FC5F1` 用 jump table 分派。C closure 分支則取已註冊 native callback。這一鏈已超過「疑似執行 wrapper」的程度；但還是 Lua 執行模型，沒有把任意資料 bytes 當 native 指令的介面。

**更正舊 E14**：`6F5A50` 不是 error handler，而是上述 execution thunk。E15 確認 protected-call 骨架，但未閉合 thunk 本體，本輪補上。真正遊戲 error-report 路徑是 `6F47A0`。

## 6. Executor 的關鍵限制：同一 `.seq` 進兩個環境

### 6.1 正式 Lua 與前置 Lua 的精確身分

| 用途 | 指標關係／原件證據 | 意義 |
|---|---|---|
| 正式 wrapper `W` | `W=&FDF3C8`，`L=[W]` | W 是 wrapper，並非原始腳本 bytes |
| 場景 manager `M` | `M=&FB73C0`，`56060B` 寫 `[M]=W` | 正式 scene load／tick 取此 W |
| Q／lb | `FE2774=W`／`FE1774=W` | 正式環境共享註冊所在 main L |
| Tutorial owner | `48D7DE → 4A88E0` 傳同一 W | 與正式 wrapper 的關係已核；方法能力另按原件與既有筆記 |
| 前置環境 | `55C69E → 6F74B0` 另建 Lp，存 `[FE1EEC]`；Wp 存 `[FE1EF0]` | 是另一個 VM，不可直接套用正式環境的 API 集合 |
| `FB73F0` | `56025A → 7CD2B0` 初始化 float／字串物件 | **不是 Lua state**，不能作為腳本 RAM 基址 |

這修補 E16 的 context 細節：兩次載入有不同目的，不應當成「同一 VM 重複執行的 bug」。同 main L 的註冊不表示 coroutine execution stack pointer 必須與 main L 相同。

### 6.2 前置階段真的執行 scene 函式

`55D7E0` 把 **72 個 qbase 式全域名稱**綁到 `8DC2F0`（`xor eax,eax; ret`，即回零個 Lua 結果），包括 wait／yield／WaitFor*／對話／鏡頭／Phase 類名稱。其 Q table 也只有受限方法。

每次 `55D6A0` 註冊六個有效 callback：前五個覆蓋同名空版本，`PlayMusic` 在這一步另行加入。

| 名稱 | Callback | 前置用途 |
|---|---|---|
| `CreateObject` | `55C940` | 經 collector 登記物件／模型依賴 |
| `AniObject` | `55CCE0` | 收集動作等資料 |
| `WalkObject` | `55CED0` | 收集物件相關資料 |
| `WarpObject` | `55D220` | 收集物件相關資料 |
| `Register` | `55D560` | **立即以 protected call 執行傳入 scene function** |
| `PlayMusic` | `55D5E0` | 保存音樂名稱 |

`Register` 的 `55D59F → 6FE770` 是重要的實作契約：不是只存函式名稱。已核前置 initializer 沒有正式 VM 那組標準庫／lb／Tutorial 註冊；新增腳本若無條件呼叫那些 API，可能在資源收集時遇到 nil／錯誤。前置 Register 會清理錯誤值並回零個結果，外層又沒有把此錯誤提升成完整成功／失敗契約，因而還有留下部分收集結果後繼續的風險。

此處的前置 API 集合指已核初始化及重新註冊狀態；前置 state 會保留，腳本仍可能修改其他全域。沒有把初始化未註冊某個 API 擴張成所有腳本修改後永遠不存在。

由此得到的**製作要求**：scene 的前置路徑必須有限結束，資源依賴收集必須完整。`while 未清怪 do wait(...) end` 不能直接照搬成通用場景循環，因為前置的 wait 是空 callback，不會 suspend。這是由已證 callback 行為推導的相容性要求，不是已執行過新腳本的 runtime 結果。

### 6.3 正式 coroutine 也有運行窗口

正式 qbase 的 Register 以 `coroutine.create` 建工作，再交 qco 登記；`561520` 只在 manager `+28 != 0`、`+2C == 0` 的窗口呼叫 `f_doCoTask`。qbase 又把 `Q.EndCutScene` 交入排程；結束流程會清 manager 的 active 狀態並移除 coroutines。前輪已證 loading flag 也可能略過這組 update。

本輪尚未取得 `Coroutine.lua`／`MoCo` 的完整實作；已確認註冊、tick、移除的介面與 native gate，但 `wait` 的時間單位、完整喚醒條件及 scheduler 錯誤政策仍未確認。Lua 原生 resume／yield 鏈已閉合，不代表遊戲 scheduler 的全部策略已還原。

因此目前閉合的是 **受場景生命週期管控的演出排程**。跨戰鬥波次、跨場景的常駐 scheduler、怪物死亡事件訂閱及無縫重連恢復，不能只因有 Lua／coroutine 就宣告現成。若由 Server 主導這些規則，應由 Server 維護事件狀態，再使用已確認的 Client 呈現入口。

## 7. 可實作能力矩陣：名稱存在還不夠

下表綜合本輪新證與固定 main 的 `20261109-mef-town-services` 系列原件研究。能力必須連同資源、物件種類、ID domain、API context 與 Server 狀態判讀；不是原生 MEF 指令格式表。

| 項目 | 可利用的已證能力 | 實作內容與邊界 |
|---|---|---|
| 場景對話、鏡頭、音樂、動作、行走 | Q／qbase 的有限場景腳本與正式 coroutine | 內容需要合法 scene 對應、模型／動作／音樂等依賴、可完成的前置路徑、結束／清理；時間與 wait 只在正確正式 context 有意義 |
| 演出用角色／物件 | `Q.CreateObject` 等私有 scene actor slot | 適合演出；其 slot 不可直接當 Server 世界 EntityId |
| 世界型 NPC／Monster 的本地建立 | `lb.CreateObjectEx` 對模型種類有原生分支 | 使用本地計數器分配 ID，沒有已證外部 EntityId 參數；不能單獨代表多人同步的 Server spawn |
| checkpoint 顯示／狀態 | Tutorial helper 與既有 `0x0048` path 可到同一 setter | 目標 point 需已存在；Server 應維護對應與進度，不能以 setter 自動生成地圖資料 |
| NPC／商店外觀、入口或視窗 | 已證本地物件／marker／選單路徑 | 商店 marker 和世界 NPC domain 分開；購買、金錢、庫存、強化結果等需要 Server 交易回覆與持久化 |
| 清怪／波次條件 | 尚無可直接採用的通用 Lua alive-count 契約 | 由 Server 實作敵人存活集合、事件與波次狀態；Client 呈現用既有相容封包／場景入口 |
| 任意 `.mef` 模組 | 相容 Lua bytes 可經實際 DoFile caller 載入 | 改副檔名、落檔或 `loadstring` 存在都不會建立 caller；前置／正式環境也不同 |
| 新的 Server→Client 腳本 blob | 本輪沒有補出合法現成資料通路 | 保留 Client 介面未知；不得猜造 opcode／framing／ACK |

### `lb.GetObjectCount` 的必要更正

不能以名稱推斷這是可用的清怪數量 API。原件 `4A1EF0` wrapper 呼叫 `[FE1780]=4A0A30`；target 只有 singleton 初始化，已初始化分支不遍歷 actor／group，也沒有把有效 count 壓入 Lua stack。wrapper 的 `EAX=1`，經 Lua C closure 的 `6FE375` 被解讀為 **回傳 TValue 數量**，不是數值「1」。

因此應寫成：**未證明它能提供有效物件／存活數量，不能作為波次完成判定的依據。** 本輪不猜現有 stack slot 恰好會返回什麼。這比「永遠回 1」或「有此 API 可直接清怪」更精確。

## 8. 「MEF 該實作哪些內容」的可執行規格界線

### 8.1 若目標是讓未修改 Client 呈現地圖事件

以下是 **Server 事件內容模型建議**，欄位概念由玩家功能與已知介面需求導出，並非還原的原生 MEF binary schema：

| 內容層 | 必須提供的內容 | 已確認 Client 接點／還缺什麼 |
|---|---|---|
| 地圖與事件身分 | map ID、可追溯 trigger 名稱、實例／事件版本 | MapList 可作名稱對照；trigger→原生 Client MEF executor 未證 |
| 初始世界狀態 | 敵人、NPC、互動點、座標、陣營／狀態及穩定 entity identity | 接到既有世界 spawn／更新介面；不可把 Q slot 或 lb 本地 ID 冒充 Server EntityId |
| 事件來源與條件 | 入場、互動、擊殺、波次、時間、checkpoint、玩家／隊伍進度 | Server 自行實作判定；尚未確認的 Client wire 欄位仍由對應 Task 補證 |
| 動作與呈現 | 世界狀態更新、既有 scene key、對話、音效／音樂、目標點狀態 | scene key 選既有資源；可用 API 受上述 context 與資源依賴限制 |
| 生命週期 | 初始化、啟動、暫停／切圖、取消、清理、重進／重連、終態 | 與 Client loading／scene busy／cleanup 狀態整合；不得以固定 sleep 猜完成 |
| 完成與獎勵 | 真正完成條件、重送去重、獎勵／庫存／貨幣／任務進度持久化 | 由 Server 決策；畫面結束／ready 通知不自動等於已完成或可發獎 |

Server 可選擇自己的資料檔／DSL／程式組織；這是相容 Server 的設計決策，無需假裝與未知原版 MEF 內部格式相同。若沿現有 packet／scene 能力即可達成玩家功能，不必等原始 `.mef` 出現才開始實作 Server 規則。

### 8.2 若目標另包含「發布新的 Client Lua 內容」

這條路必須補齊以下契約後，才能說某份檔案可用：

1. **入口契約**：哪個既存 caller、scene selector 或 Lua call 會取用它。已知 `0x0047` 對應 scene keys，後續組 `Event/Sequences/<funcName>.seq`；不能把 Server path 任意塞成 `.mef`。
2. **內容契約**：Lua 5.1 相容文字或精確匹配的 bytecode；不以現代 bytecode 代替。所有使用的 native API 名稱、參數與 context 需有證據。
3. **前置契約**：有限結束、依賴收集完整、不能假設 wait 有暫停功能，也不能假設正式環境庫都存在。不能單靠語法驗證或把錯誤吞掉判成功。
4. **正式執行契約**：確實建立需要的 coroutine／函式，遵守 active／pause／loading gate；區分頂層 chunk 已執行和後續 scene 已完成。
5. **資源契約**：虛擬 path、package 優先序、prefix／disk fallback policy、cache／已建索引及版本一致性。傳到磁碟的檔不一定是實際被讀的那份。
6. **物件與狀態契約**：scene actors、世界 actors、NPC marker、checkpoint 等 domain 明確對照；Server 負責需要同步的世界與交易結果。
7. **觀測契約**：區分存在、開啟、parse、頂層 call、prepass 完整、正式 coroutine 結束；`lb.DoFile==0` 不是充分成功證據。

這裡只列可用能力與相容性要求，沒有修改原 Client／資源或建立新的啟動 hook。如何發布內容仍受既有 Client 保留政策及已證交付路徑約束，不能把這份分析視為已准許修改 Client 的設計變更。

## 9. Server 開發需求候選：交由 S00 去重整合

沿既有 `REQ-0019`／`REQ-0021`、`GAP-SCENE-0001`／`GAP-FLOW-0001` 與 `SFD-0015` 的相關需求交界提出下列候選；本稿不另造正式台帳或變更狀態，具體歸屬以 S00 去重為準。

| 類型 | 開發／補證事項 | 完成判斷應看什麼 |
|---|---|---|
| **Server 待開發** | 地圖事件／波次／敵人存活集合／checkpoint／完成條件引擎 | 明確且可重現的狀態轉移，不依賴未證 count API，不冒稱原版 Server 演算法 |
| **Server 待開發** | 既有 scene key 與世界 packet 排程、忙碌／loading 期間的延後、重複啟動與取消策略 | 實際 Client 狀態相容；ready／scene start／scene finish／獎勵核准各自有語義 |
| **Server 待開發** | 世界 entity identity、scene slot、marker／checkpoint 對照及同步 | Server 所有權與本地演出物件分清，重進／重連結果一致 |
| **Server 待開發** | 資源清單、版本與內容發布服務；可用場景／API／依賴的 authoring 檢查 | 發布內容確實可達、讀到正確版本，前置與正式契約均滿足；服務端可達部署須實際成立 |
| **Server 待開發** | 任務、商店、金錢、庫存、獎勵與持久化 | 交易回覆、重送去重與權威狀態正確；Client 畫面動作不當成交易完成 |
| **Client 待逆向** | 原生 MEF 名稱→實際 opener／parser／executor；任何現存 incoming bytes→Lua 入口 | 需要真實 caller／buffer producer／consumer 鏈，不能用 parser 存在或缺檔猜填 |
| **跨功能待整合** | loader path／內容版本、scene 雙 VM、世界更新與 Server 事件狀態串接 | 每個已證局部契約可組成完整玩家流程，且沒有 ID／生命週期矛盾 |
| **待遊玩驗證** | 具體場景、取消／切圖、資源缺失、多人同步、重連與交易結果 | 動態結果符合已定義功能，不以作者 raw byte 核對代替 |

## 10. 可證與未證的精確終點

本輪已閉合的鏈：

- `MapList trigger → 獨立名稱字串 → tree node → cleanup`，加指定 accessor alias 候選與零初始化區界線。
- `本機資源／Lua string → memory reader → text／binary parser → Proto／closure → protected execute → opcode VM`。
- 全域 `DoFile`、`lb.DoFile` 與標準 load APIs 的實際間接入口及來源差異。
- 前置 Lua 的 72 stubs／六個有效 callback／Register 即時執行，正式 Lua 的共享 wrapper 與 coroutine gate。
- 六個已知資源 member 的實體 carrier、虛擬路徑、bytes 身分與三類記憶體內容的區別。

仍未閉合的是 **原生 `.mef` 本體的格式、名稱到真正 consumer 的連線，以及可供 Server 任意 blob 直達 parser 的既有協定**。既有 receiver／resource／literal 窮舉結果和本輪有界補查都沒有提供這條線，不能用未知原 Server 行為補洞。

後續有價值的解除證據是：另一個已知執行路徑實際把 trigger 名稱交給 opener；或可追溯的 buffer producer 確實進 parser；或同版本能補出 consumer 的新模組／足夠記憶體覆蓋。原生 MEF 樣本可協助格式識別，但**不是繼續實作上述 Server 事件與既有 Client 能力的前提**。先前只有極小 image-overlap 的 dump，不能用來否定 heap 中任何腳本存在。

與前輪關係：[Server 可傳遞時窗](20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md) 已區分啟動前 launcher 發布與遊戲協定。這一輪補上「傳完之後，什麼內容能被何種入口解析與執行」，並保留 **交付成功 ≠ 自動載入 ≠ 前置完整 ≠ 正式完成 ≠ Server 業務完成** 的分層。

## 11. 證據與來源導航

整合重驗結果為 `all_matched=true`：120 個有界原件窗、26,737 bytes（含重疊）、85 個字串、197 個指定 alias 候選窗、六個資源 member，以及 71 個固定 Git 來源 blob 相符。另將 qbase 全部 76 prototype／906 instruction words 與 constants／結構對照固定舊 JSON；本包保存其中 24 個與本輪結論直接相關的 prototype。詳見結果 JSON 與可重跑工具；這些計數不代表全程式覆蓋或語意完全驗收。

- [證據 README](MEF-parser-executor-storage-20261114/README.md)：檔案、重驗命令、結果與限制。
- [Parser 完整筆記](MEF-parser-executor-storage-20261114/parser.md)：入口、header、ABI、text／binary、call engine、BOM、兩 VM 與 buffer 生命週期。
- [Executor 完整筆記](MEF-parser-executor-storage-20261114/executor.md)：前置 callback、正式 coroutine、能力矩陣、`GetObjectCount` 的 C return ABI。
- [Storage 完整筆記](MEF-parser-executor-storage-20261114/storage.md)：tree layout、字串 copy、destructor、32 個 accessor 候選與 165 個 initializer 候選。
- [原件視窗](MEF-parser-executor-storage-20261114/native-windows.json)、[反組譯](MEF-parser-executor-storage-20261114/native-windows.asm)、[資源證據](MEF-parser-executor-storage-20261114/selected-resource-evidence.json)。
- [固定來源 manifest](MEF-parser-executor-storage-20261114/source-manifest.json)：引用來源及 Git blob，不把既有筆記的結論誤稱本輪全新核驗。
- 固定 main 既有研究：[MEF feasibility](https://github.com/we88ec3-prog/ttr_anal_multi/blob/ba5f96dfa94d734cbded291fb8887f50426bfa77/governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md)、[town services](https://github.com/we88ec3-prog/ttr_anal_multi/tree/ba5f96dfa94d734cbded291fb8887f50426bfa77/governance/client-variants/20261109-mef-town-services)。
- 外部語義對照：[Lua 5.1 manual](https://www.lua.org/manual/5.1/manual.html)、[lundump.c](https://www.lua.org/source/5.1/lundump.c.html)、[ldo.c](https://www.lua.org/source/5.1/ldo.c.html)。遊戲事實皆以本稿所列原件／固定資源為主，外部 source 不替代本機版本證據。
