# MEF 名稱、記憶體物件與可辨識讀取者

## 結論與本輪增量

本輪原件證據可以正面確認：`Table/_MapList.xml` 的 `trigger` 欄位進入 `FB74C0` 後，保存的是 **以 map ID 為 key 的窄字元名稱字串**。已核定字串長度、容量、inline／heap 選擇、複製、節點建構與銷毀；這些欄位不是 `.mef` 檔案大小、檔案內容 buffer 或 MEF 執行器狀態。

「Client 記憶體中有 `scenario_town000.mef` 這類字串」因此只足以支持「Client 載入過引用此名稱的表格」。它不能支持「完整 MEF 已存在記憶體」、「MEF 只存在記憶體」或「此名稱已被 parser 開啟」。本輪沒有找到新增的 MEF bytes consumer、parser 或 executor，也沒有推導出可實作的 MEF 語法。

新增範圍限於既有 writer／getter／initializer 的資料型態與生命週期，以及 initializer 回傳的候選別名：

- `4F5640 → 402A70 → 4F7DF0 → 403040`：XML 名稱到自有字串的完整配置／複製路徑。
- `4F9B40 / 504180`：0x30-byte node 建構與字串／node 釋放。
- `4F3D80 → 425330` 候選別名：165 個 initializer E8 候選皆隨即註冊固定 destructor；`425330` 的 32 個 E8 候選經九個 helper 使用其他成員，未找到 trigger `+0x50` 投射。
- PE `.data` 虛擬零初始化尾段：`FB74C0` 並非原件 raw-backed 資料。

沒有重做 `.mef`／STP 名稱全掃、`FB74C0` literal pointer scan、舊 16 個 `4F7DF0` direct callsite 盤點、`Node.title`／DMP／包內無副檔名搜尋。本輪證據不可包裝成重新發現既有陰性。

## 來源與可重現性

- 原件：`project_sources/02-Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 歷史分析基線：commit `ba5f96dfa94d734cbded291fb8887f50426bfa77`，`governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md` 與 `governance/client-variants/20261107-mef-resume/native/{README.md,findings.json,source-identities.json}`。
- 偽碼輔助：同一 commit 的 `kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/functions/0x<VA>.c`。各 blob ID／SHA256 見 `source-manifest.json`。關鍵型態與資料流均回核原件，不以偽碼型態作唯一依據。
- 本輪機器碼證據：`native-windows.json` 的 storage group 保存 20 個 VA/raw/length/hex/SHA256 視窗，共 4,996 bytes；`native-windows.asm` 的 storage group 為相同視窗的 objdump 輸出。`alias-census.json` 另保存兩個指定 target 的 E8 候選、原始 bytes 與 accessor 第一個 consumer。
- 整合後重驗方式見 [README](README.md) 的 `verify_evidence.py`；只讀原件，沒有執行遊戲或修改 Client。

## 1. `FB74C0` 是執行期容器，不是靜態 MEF 內容

PE section 對照如下。所有 VA 使用 preferred image base `00400000`；未做 runtime ASLR 觀測。

| Section | VA | VirtualSize | Raw offset | RawSize |
|---|---:|---:|---:|---:|
| `.text` | `00401000` | `007D01F0` | `00000400` | `007D0200` |
| `.rdata` | `00BD2000` | `0018E07C` | `007D0600` | `0018E200` |
| `.data` | `00D61000` | `002873D8` | `0095E800` | `0022B800` |
| `.rsrc` | `00FE9000` | `0005AF58` | `00B8A000` | `0005B000` |

`.data` 的 raw-backed VA 結束於 `F8C800`（exclusive），虛擬 section 結束於 `FE83D8`。`FB7470`、`FB74C0/C4/C8`、`FB75B0` 全位於兩者之間，是載入後零初始化的虛擬尾段；**沒有可引用的原件 raw offset**。不得以一般 VA 減常數的公式替這些全域杜撰 raw bytes。

`4F3D80` 建構整個 table 集合。`4F3DA7/4F3DAC` 令 `EBX=1, ESI=0`，trigger head 建構精確位置是：

| VA | 行為 |
|---|---|
| `4F3EFD` | 配置 `0x30` bytes sentinel node |
| `4F3EFF` | `FB74C8 = 0`，初始元素數為零 |
| `4F3F15` | `FB74C4 = allocated_head` |
| `4F3F1A–4F3F29` | head 的 left／parent／right 指回自己 |
| `4F3F32/4F3F3B` | head `+2C/+2D = 1` |

container 基址為 `FB74C0`；`+04` 是 head，`+08` 是 size。相對整個集合 `FB7470`，trigger container 是 `+0x50`，其 head 是 `+0x54`。全域僅保存容器管理資訊；節點與長名稱的字元記憶體另在 heap 配置。

## 2. XML 中的名稱如何進入 heap node

原件可直接讀到的固定名稱是 `C0D4B4 = "Table/_MapList.xml"`，raw `80BAB4`。`C0D4D4 = "trigger"`，raw `80BAD4`。這是表格資源路徑與 XML 欄位名；本輪路徑上沒有 `.mef` 專用目錄常數。

`4F5640` 的第一個 XML 處理段：

| VA／呼叫 | 已確認資料意義 |
|---|---|
| `4F5675–4F56A0` | 用固定 `Table/_MapList.xml` 建立／載入 XML document |
| `4F56ED–4F5715` | 讀 `id` 屬性，以 `8917B4` 轉整數並作 map key |
| `4F5723–4F572A` | 查詢 `trigger` 屬性 |
| `4F5733–4F573C` | 屬性值字串的 capacity 在 attr `+44`；小字串資料在 attr `+30`，長字串從 `[attr+30]` 取 chars 指標 |
| `4F5744–4F5762` | 建立 capacity=15、length=0 的區域字串；逐 byte 找 NUL 算長度，再呼叫 `402A70(chars,length)` |
| `4F5807–4F581E` | 以同一 map ID 查／建立 `FB74C0` 節點；`4F7DF0` 回傳 node `+10` 字串物件地址 |
| `4F5823–4F582C` | `403040(destination=node+10, source=local_trigger, pos=0, count=0xFFFFFFFF)` |
| `4F58BB–4F58C4` | 區域 trigger 字串若 capacity≥16，釋放區域 heap chars |
| `4F5CED–4F5D2D` | 最後銷毀最初的 MapList XML document |

兩次內容複製的長度來源都是**名稱的字元長度**。`402A70` 在 `402B36` 複製給定長度，`402B42` 保存 length，`402B49/402B58` 補 NUL；`403040` 在 `40304E` 讀來源 string `+10` 長度，`4030F7` 複製，`403103` 保存目的 length，`40310A/403119` 補 NUL。此鏈沒有把名稱交給 resource open，也沒有把以此名稱找到的檔案大小／內容塞進同一 node。

`403040` 在目的 capacity 不足時呼叫 `402DC0`。其通常配置策略包含 requested length 與 `0xF` OR 後的容量，再配置 capacity+1；會複製舊字元、釋放舊 chars、保存新 pointer/capacity。這是字串容量管理，不能解讀成 MEF payload buffer 配置。

### 已核定的 node layout

`4F9B40` 在 `4F9B70` 配置 0x30 bytes。`4F9BAE–4F9BC5` 寫 key 與初始化字串；`504180` 使用完全相同的 field offset 銷毀：

| Node offset | 大小／語義 | 證據 |
|---:|---|---|
| `+00` | left pointer | `4F9B88`，`4F7E` traversal，`5041A2` |
| `+04` | parent pointer | `4F9B8D` |
| `+08` | right pointer | `4F9B93`，`504193` |
| `+0C` | 32-bit key | `4F9BB0`，`4F7E40` 比較 |
| `+10…+1F` | 16-byte inline chars，或其首 DWORD 為 heap chars pointer | `4F7EF5/4F7EFA` 回傳此處；字串 helper 以 capacity 決定 |
| `+20` | 字串長度，不含 NUL | `4F9BBF`；`403103` 的 string `+10`；`5041B9` |
| `+24` | 字串 capacity；`<16` inline，`≥16` heap | `4F9BB8`、`50419E` |
| `+28…+2B` | 未在本輪指定為 payload field；string grow exception/fallback 會把 string `+18` 地址交配置 helper | `402E81`。不憑 layout 猜成內容指標 |
| `+2C` | tree color flag | `4F9B9C`；既有樹平衡碼 |
| `+2D` | sentinel／nil flag | `4F9B9C`、`4F7E33`、`504188` |
| `+2E…+2F` | 本輪未賦予語義 | 不作 MEF 推論 |

`402BB0` 的名稱容易被偽碼誤導：它會在長字串情況移交來源 pointer 並把來源清空，屬 move／ownership transfer。`4F7DF0` 新增節點時先移動空字串；writer 真正保存 trigger 名稱使用的是 `403040` 深拷貝。兩者不可混稱「copy」。

## 3. 保存多久，誰負責釋放

`4F7DF0` 的結果是「node 中字串物件地址」，不是檔案 bytes。該 node 有獨立字串所有權，因此區域 trigger 與 XML document 釋放後，名稱仍可留在表內。

`4F44B0` 在 `4F485D` 對 trigger container 呼叫 `4F7FE0`，再在 `4F4869` 釋放 sentinel head。整棵樹清除分支 `4F7FFB → 504180` 遞迴銷毀 node：

- `50419E` 檢查 node `+24` capacity；若 ≥16，`5041A6/5041AA` 將 `[node+10]` 交給 `89120C` 釋放。
- `5041B2–5041C1` 重設容量、長度、NUL。
- `5041C5` 將 node 本體交給 `89120C` 釋放。
- `4F8000–4F8014` 把 head links 重設並把 container size 清零。

`BCD1E0` 原件是 `jmp 4F44B0`。`425330` 在 `FB75B0 & 1` 尚未設定時呼叫 initializer，接著 `_atexit(BCD1E0)`；其回傳為固定集合地址 `FB7470`。本輪 165 個 `E8 → 4F3D80` 候選後面皆是同一 `_atexit` 註冊序列。因此可確認 singleton 表格具有程序退出清理路徑，**不能把名稱存活時間當成「目前地圖的 MEF 執行中」**。

這不是「絕對只會在程序退出釋放」的證明：例外解構、未涵蓋的間接呼叫或其他別名修改不能由此完全排除。本輪沒有新增 per-map trigger bytes cache 或 MEF 重載路徑。

## 4. 候選別名補查：`425330` 是否通往 trigger

針對回傳 `FB7470` 的 `425330`，只查 `.text` 中 `E8 rel32` 對此 entry 的候選，不掃其他全域 literal。32 個候選的第一個 consumer 分為九種；原件和 helper 偽碼交叉核對如下：

| Helper | 集合的成員偏移 | 可確認用途／資料類型 |
|---|---|---|
| `4F6950` | `+100/+104` → `FB7570/FB7574` | 以 ID 寫入寬字串 pointer map |
| `4F6A30` | `+100/+104` | 取同一寬字串；缺值會安排查詢 |
| `4F6B20` | `+100/+104` | 查詢並複製同一寬字串 |
| `4F6B80` | `+110/+114`、`+130/+134` → `FB7580/84`、`FB75A0/A4` | 待查 ID 向量；送 `0x0013`／`0x0BC6` 查詢，不是 MEF 接收 |
| `4F6D20` | `+104` | 對寬字串比較，回查 ID |
| `4F6DC0` | `+104` | 對寬字串比較，回查 ID |
| `4F7370` | `+120/+124` → `FB7590/FB7594` | 另一個寬字串 pointer map |
| `4F7A70` | `+00/+04` → `FB7470/FB7474` | 0x78-byte node 的主資料表，nil flag 在 node `+75` |
| `4F7BA0` | caller 先加 `+10` → `FB7480/FB7484` | 另一個寬字串表；capacity 閾值為 8，不是 trigger 的窄字串閾值 16 |

對此精確候選集沒有看到 `FB7470 + 50/+54` 的 trigger lookup，也沒有新檔案開啟者。既有 `4DF510` 所傳集合別名到 `4F6E80` 實際投射 `+E0/+E4`，不是 `+50/+54`，直接沿用 main 基線，不再把它算新發現。

覆蓋邊界：32 個候選均核了第一個 consumer 與對應 helper；這不是整個程式的跨程序 alias 完整證明。未枚舉所有間接 call、未對全部任意根地址常數做新掃描、未保證所有 caller 後續暫存器保存值已全程追蹤。若往後出現具體新 consumer，仍應從其資料流追至資源開啟／buffer／parser；目前沒有這種正證據。

## 5. 回答「沒有 `.mef`，是否只在記憶體或特定路徑」

可以確認的只有：MapList 引用名稱會以自有字串存在記憶體。固定可見路徑是 **`Table/_MapList.xml`**；它是保存名稱的表格，不是 MEF 本體路徑。writer 不替 trigger 名稱加目錄、不驗副檔名，也不在這一段開啟該名稱。

不能確認的則是：未見實體 `.mef` 是否由封包只存 RAM、是否有專用隱藏路徑、是否是 pack 中另一個別名、是否有其他未識別 parser。這些都需要「名稱交給 opener」或「非名稱 buffer 交給 parser」的實際連線。不能用 memory 中含 `.mef` 的文字或節點字串 capacity 代替這條連線。

既有基線已證 `4DF58D → 4F7DF0` 取 trigger 名稱後沒有消費它。本輪完整釐清這個返回值的型態，使該結論更明確：它並不是「取回已解析的 MEF 物件但稍後隱式執行」，而是取回這個字串物件。仍須保留未涵蓋其他 alias 的邊界，不擴大宣稱整個 Client 絕無 MEF 支援。

## 6. Server 開發含意

這份分析可實作的是 **Server 的 map ID → trigger 名稱 metadata 模型與需求邊界**，不能據此實作 `.mef` binary grammar 或 executor：名稱只提供引用，不提供檔頭、record schema、opcode、執行順序或錯誤行為。

在未修改 Client 的目標下，Server 需求仍是找到可供既有 Client 消費的資料通道／內容格式與執行入口。若 Server 自行使用一個 MEF 解析器管理事件，那是 Server 端新增實作；它必須透過已證的 packet／場景腳本機制把遊戲結果呈現給 Client，不能宣稱 Client 會因為收到同名 `.mef` 自動啟用。本輪沒有修改 Server、Client、分支或索引。
