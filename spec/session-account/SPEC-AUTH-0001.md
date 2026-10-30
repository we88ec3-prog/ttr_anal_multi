# SPEC-AUTH-0001 — KR Client 認證與登入回覆有限契約

**DRAFT / PARTIAL；僅限 Client 原生靜態路徑，非可直接互通的完整 Server Wire 規格。**
KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。以下 byte offset 均以 **application payload 起點** 為 0；框架 marker、socket、lane/scene 另有前提。

## 1. C2S 本地登入 builder（T03 RR-0003／BIN-first）

| 分支 | 指令／本地 queue | 欄位（位移為 payload-relative） | 必要限制 |
| --- | --- | --- | --- |
| `0x440790` mode `0x52` → `0x4A3360` | LE16 `0x00E8`，**112 bytes**，經 manager vtable+0x10、slot **1** | `+2..52` / `+53..103` 各 51-byte narrow 字串槽；`+104..109` **6-byte opaque**；`+110..111` 來源 WORD `FB1318+BF80` | 檢查的 builder 中六個 opaque bytes **無直接初始化 writer**；不可視為永遠 0 或 Server 業務欄位 |
| `0x440790` mode `0x54`／其他 → `0x4A31B0` | LE16 `0x000F`，**214 bytes**，同 manager／slot 1 | `+2..103` / `+104..205` 各 51 UTF-16 code unit 槽；`+206..209=0x00010001`；`+210..211=0x0034`；`+212..213` 同一來源 WORD | `_wcscpy_s` 容量 51 unit 不等於官方帳號長度政策；不可與 E8 byte layout 混用 |

以上長度是本地 application payload，**不是 TCP frame 總長，也不保證 WSASend 成功**。T02 transport mode `Conn+A02C` 與此處的 `0x52/0x54` builder mode 屬不同命名空間。密碼摘要所見是 Client 本地文字形成路徑，不能反推出原版 Server 加鹽、資料庫或身份驗證策略。

### 編碼來源（兩條不同路徑，不可統稱固定 codepage）

- **輸入／前置文字轉換**：全域 `0xFBA808` 位於 `.data` **virtual-zero tail**（初始載入記憶體為 0，非 raw 檔固定四個 byte）；Native API 使用它作 codepage 參數。初始 0 對 Win32 表示 CP_ACP；執行時別名 writer、主機 active ANSI codepage 均未封閉。
- **E8 builder 的後段輸出字串轉換**：`0x4A3360` 中 4 次 `WideCharToMultiByte` 直接傳 `CodePage=0`（CP_ACP），不等同於每一條前置 helper 都直接讀取 FBA808；不能無條件聲稱 UTF-8、固定 CP949 或任何官方 Server 字元集。
- 轉碼／CRT 失敗路徑並未證明一定中止 local enqueue；也不證明失敗時必有有效資料或 wire send。E8 `+104..109` 的局部未直接賦值不構成可安全讀取或固定值的保證。

## 2. S2C 兩個不同的 LOGIN scene application handler

T02 inbound frame 解包、lane2、有效 LOGIN scene 與二層 handler table 必須先成立。`0x4C3220` 註冊 app command `0x0013→0x4C37A0`、`0x007A→0x4C3C10`；命令身份屬 **Client 可達的 handler**，不是原版 Server 實際先後順序，**0x0013 也不是 transport marker**。

### S2C `0x0013` 局部欄位和狀態 gate

| Offset | 已觀察的 Native 使用 | 未閉合 |
| --- | --- | --- |
| `+0..1` | app LE16 `0x0013`（經有效 dispatcher／LOGIN scene） | 端對端第一回覆是否必為 `0x13` |
| `+2` | NUL-terminated UTF-16 名稱；status0 且非空才走資料更新 | 原版名稱政策；沒有 NUL 的 malformed buffer 處理 |
| `+0x16` | BYTE status：`5` 走專用失敗；`0` 且名稱非空走局部成功；其他／空名一般失敗 | 完整 result enum 與 Server 發送原因 |
| `+0x17` | BYTE → Client+0x68B4 | 官方語意 |
| `+0x18` | DWORD → Client+0x67E0 | 官方帳號／身份意義 |
| `+0x1C` | DWORD groupCount | 完整合法上限及上游長度檢驗 |
| `+0x20` | 可選寬字串 notice，**status 分支前**即可能處理 | 完整編碼失敗／notice 欄位與長度 |
| `+0x86`／`+0x87`／`+0x8C` | 分別讀 BYTE、以容量5複製 narrow 字串、讀 DWORD | 不可自行命名為可信 ticket/token |
| `+0x90` | BYTE；為 0 且前述 success path 才調 `0x4C3170` | 後續 socket 時序及原版業務旗標 |
| `+0x92` | group cursor 起點 | 需要匹配 groupCount 與可讀 extent |

`0x4C37A0` 的可選 notice 可能在失敗狀態前已有副作用。success path `0x4C3170` 更新 `Client+BD54/BD58` 並送 **本地** `F4241`，不等於立即 Connect key0/key2。status5／一般失敗各走不同分支與 BF60 清理；缺少完整 runtime success/failed capture。

### S2C `0x007A` 是不同布局

在 `0x4C3C10`，DWORD group count 由 payload `+2` 讀取；group cursor 是 `+6`；再共用 `0x4C3080`。**不可將 `0x0013` 的 `+0x1C`/`+0x92` 複製到 `0x007A`。** 兩者 handler 是否在某 session 必然前後相繼尚未證。

## 3. Group / channel cursor（局部讀取模型，不是已經驗證的安全解析器）

`0x4C3080` 對每一組讀 **3 bytes**（LE16 group id + BYTE childCount），每個 child 消耗 **10 bytes**；child `+4..7` 是用於 IPv4 文本格式化的 4 octets，`+8 != 0` 時才 append，`+9` 被傳到 `0x507610`（不可當 padding），`+2..3` 官方語意未知。被過濾的 10-byte child 仍推進 cursor；groupCount=0 仍可觸發 **本地** `F4243` 通知。

對一組群組數 `G`、每組 `n_i` 個 child，**合成 Producer 的保守 byte extent**：

- `0x0013`：`0x92 + Σ(3 + 10*n_i)`；groupCount 自 payload `+0x1C`。
- `0x007A`：`6 + Σ(3 + 10*n_i)`；groupCount 自 payload `+2`。

這是對原生讀取 cursor 步進的靜態推導，**並非原始 Client 內逐 group/row 有完整 remaining-length guard**，亦不是官方 Server 封包實測。若設計安全產生器／測試器，應額外保守驗證長度與 NUL；不能把這項設計安全政策宣稱為原版 Client 的錯誤處置。

## 4. 結果 → 選服連線與 Server 設計分界

`0x0013` success+`+0x90==0` 對 `F4241` 的本地通知只是前置條件。UI selection `0x66C090` 還要查 `FE1B54`、selection mapping 和 pointer gates，才可能到 `0x4957C0` key0/key2 Connect（另有 T02 RR-0005 key1）。**不得畫成 `S2C0x13→必定立即換 socket`**。`RR-0005` 已限定 `ACCEPTED`、但 GAP-NET-0002 仍 OPEN；`RR-0003` 本次維持 `IN_REVIEW`，不同於 RR5。

原版 Server credential policy、真實 first S2C command/marker、跨連線總時序、合法 payload 安全上限、E8 六個 byte 的每次值、FBA808 runtime setter 與選角成功／失敗配對仍 **UNKNOWN**。後端 DB、密碼儲存、Session token/重試屬自設 Server ADR，不可由這些本地路徑推定。

## 5. 來源、審核與測試地位

- 早期：`CLM-AUTH-0001/0002`（SRC-0003，PARTIAL）。
- T03 RR3 主報告：`CLM-AUTH-0003/0004/0005`（SRC-0473；`kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md`；Git blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`）。
- E69 更正與加強：`CLM-AUTH-0006`（SRC-0482；`kr-extra-roy/20261030-chatgpt-web-roy-E69-RR0003-E8-tail-uninitialized-CPACP-and-13-handoff-native.md`，PARTIAL）。
- T02 交叉：`CLM-NET-0018..0020`（RR-0005，限有界 Client static path）。T02 `CLM-NET-0029/0030` 支援 LOGIN scene/lane gate 條件，皆非 real wire trace。
- 本稿為 S00 **規格整理**，非重新執行原 BIN 的 T01 審核；RR3 仍 IN_REVIEW、`GAP-AUTH-0001` OPEN、TEST 只 `OFFLINE_SYNTHETIC`、無任何正式 Client/server compatibility verdict。

相關 [SPEC-FLOW-0001](SPEC-FLOW-0001.md) 與 [Phase B 訊息矩陣](phase-b-message-matrix.md)。
