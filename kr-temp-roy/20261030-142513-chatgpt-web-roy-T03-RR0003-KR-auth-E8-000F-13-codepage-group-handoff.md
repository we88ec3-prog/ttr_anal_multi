# KR T03／RR-0003 — 登入請求 `0x00E8`／`0x000F`、`0x0013` 回覆、字元編碼、群組／頻道游標與選服交接的原生靜態界線

> **研究狀態**：完整的 *Client 可證、有界靜態證據交付候選*。此文件只承諾已列的 Native 指令與條件，不承諾原版 Server 認證演算法、實際首個 S2C 回覆、互動/可玩性或 T01 FULL-PASS。RR `SUBMITTED` 是研究者提交審查，非 S00 `ACCEPTED`。

- 研究日期（Asia/Taipei）：**2026-10-30T14:25:13+08:00**；研究者：`chatgpt-web roy`。
- **唯一分析原件**：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；另行重算 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。未執行/修改原版 Client，未取得原版 Server 或擷取網路實包。
- 本次啟動讀取時 `main=edbf681af76909abbdcb82d6ba223bfbc27b3619`；T03 依固定指示將 main **合併至 `t03/roy/chatgpt-web`**，雙父 Commit `fd975a2650552ffafdadc37ac8bbb3c5ec96ae03`（父 1 `6dc876e84358c1f1ab343ce5b8899006574ddf26`、父 2 `edbf681af76909abbdcb82d6ba223bfbc27b3619`）。認領 RR-0003 透過 main 正式 PR #43 發布。本稿建立時尚未取得研究提交 Commit，**下列 Git SHA 只表示已有來源或啟動基準**。
- PE32 x86 imagebase `0x400000`，`.text VA=0x401000, raw=0x400, raw size=0x7D0200, virtual size=0x7D01F0`，**僅 `.text`** 可用 `raw = VA − 0x400C00`；`.data VA=0xD61000 raw=0x95E800 raw size=0x22B800 virtual size=0x2873D8`。本稿組合語言直接由原始 BIN 以 GNU `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 定向反組譯；附錄保留逐 byte 的 disassembly，未使用現成偽碼冒充第一手證據。
- 範圍：**KR／T03／RR-0003（P0）**。T02 的 framing/queue/Connect、T04 角色權威、T05 場景、T06 UI 資源僅按已知來源引用，不越權改成登入業務結論。
- T03 另有原生 QA 退回 `T01-RETURN-T03-006-LAYOUT-001 — NEEDS_FIX`，與本 RR 無關；使用者這次明確要求選擇一項 RR 開工，故該退回保留原狀，**未假稱已修復**。

## A. RR 正式目標（不縮題）

**question**：Identify bounded E8/000F opaque fields and codepage dependencies, actual 0x13 status response, channel group cursor/limits and subsequent handoff; preserve official-backend unknowns.

**acceptance criteria**：`GAP-AUTH-0001` — opaque E8 tail、來源 codepage、`0x13` response 欄位／陣列界限、結果時序及連線 handoff；區分原版 Server 政策與新 Server 自行設計的政策。

本次按 **Client 原始二進位可以證明的局部條件**驗收，而不是要求重建原版 Server 計算密碼、帳號庫或歷史線上時序。對每個未知提供精確限制、反證與後續解除方法。既有局部已載於 `kr/evidence/602d11...` 等；本次重新直接核對 Native assembly，另補強 `0x13/0x7A` 各自清單位置、成功/錯誤 gate、零群組處理、列表**缺少長度逐筆保護**、`.data` 虛擬零填充 codepage 和與選服的非立即性。

## B. 一頁證據結論（N = 本次原始 BIN 確認；C = 有條件；U = 未證）

| ID | 主張 | 原始證據／位置 | 級別與界線 |
|---|---|---|---|
| RR3-01 | `0x440790` 的 mode `0x52` 分派到 `0x4A3360`；`0x54` 及其他模式走 `0x4A31B0` | `0x440793..0x440828` | N；尚需 launcher 輸入才能知道某玩家何時用哪個 mode |
| RR3-02 | 兩種送包都透過通訊 manager vtable `+0x10`、slot `1`，長度分別 `0x70=112`、`0xD6=214` | `0x4A34EE..3505`、`0x4A32A8..32C4` | N：本地 queue/send interface；不是完整 wire frame 或傳輸成功 |
| RR3-03 | E8 `0x00E8` 為窄字串 51-byte 槽兩組；000F `0x000F` 為寬字串 51 UTF-16 code units 槽兩組 | `0x4A34D0..4A34E9`、`0x4A3279..4A32A3` | N/C，須保留 CRT 失敗路徑及 codepage 轉換 |
| RR3-04 | 000F 尾欄 `+206: DWORD 0x00010001`、`+210: WORD 0x0034`；兩分支最後 WORD 均從 `FB1318+BF80` | `0x4A31F3..4A31FA`、`0x4A3266..3281`、`0x4A33A0..33C5` | N：bytes/來源，不把常數命名為官方版本/語意 |
| RR3-05 | E8 `+104..+109` 是缺少正向已證初始化的**六個不透明 byte** | E8 build 區 `0x4A33A0..4A3505`（調用堆疊與非連續寫入） | U：不能說固定0、伺服器版本、checksum；亦不能因 static 搜尋未中就宣布必為未初始化 |
| RR3-06 | `FBA808` 是 codepage global；正常路徑由它讀取並傳給 Windows Unicode/ANSI API；PE `.data` 在這個 VA 為虛擬零填充 | `0x40410C/404158`、`0x46E2CA/46E31C`、`0x47F59E/47F5D9`、`0x4C37E7`；PE headers | N：初始值 0 / CP_ACP 選擇；U：runtime alias 改寫、具體 OS ACP，非固定 UTF-8 或 CP949 |
| RR3-07 | `0x0013` 的登入場景內 handler 是 `0x4C37A0`；`0x007A` 列表 handler 是 `0x4C3C10` | `0x4C3220..3265` 第二層表覆寫，索引偏移 / 8 | N/C：需有效 scene 和 T02 lane2 分派，不能由 handler 存在推回 Server 首包 |
| RR3-08 | `0x13` status 在 `payload+0x16`；`5` 專用失敗、`0` 且 `+2` UTF-16 NUL-terminated 名稱非空才能做成功資料更新；其他值或空名走錯誤/清理 | `0x4C3821..3827`、`0x4C3949..3973`、`0x4C3A30..3B64` | N；只有這幾條 branch semantics，完整 enum 未知 |
| RR3-09 | 成功路寫 `Client+67E0/+67E4/+68B4/+68B0/+6898..`；從 `+0x1C` 取 group count，從 `+0x92` 取 group cursor | `0x4C3979..4C3A24` | N；`0x87` 是容量5的窄字串 copy，非憑空指認原版 ticket 정책 |
| RR3-10 | `0x4C3080` 每 group：`WORD id + BYTE childCount`（3 bytes），每 child：10 bytes，IPv4 四個 byte 在 `+4..+7`；`+8!=0` 才 append；`+9` 傳給 `0x507610` | `0x4C30BE..4C3144` | N；`+2..3`、`+9` 業務意義 U |
| RR3-11 | 列表 parser 以 count 迴圈，**沒有在這條函式內拿剩餘 payload length 做逐項 guard**；count0 也呼叫 `0x58AAD0(F4243)` | `0x4C30AA..314F` | N，限定函式本體；安全性需看上游整體 buffer 驗證，不可從此推定 exploitation |
| RR3-12 | `0x13` 成功、且 `payload+0x90==0` 才呼叫 `0x4C3170`，寫 `context+BD54=1`、`BD58=timeGetTime()` 並發 `F4241`；列表解析自有 `F4243` | `0x4C3A03..3A29`, `0x4C31E4..3204` | N：狀態/本地通知，**不是立刻改 socket 的充分條件** |
| RR3-13 | `0x007A` 的 list count/cursor **不是** `0x13` 的 `+1C/+92`：`0x4C3C10` 取 `+2` 的 DWORD count、`+6` cursor | `0x4C3C10..4C3C25` | N；須分開解析，不能複製 `0x13` layout |
| RR3-14 | UI 選服流程依託 `0x4C3080→FE1B54` 的資料，再受玩家 UI 選擇 gate；下游 `0x4957C0` 可建 key0/key2 | E45/E56 對選服 endpoint/Connect 的已提交限定證據 | C；不是 `0x13` 一成功必連全部 socket，也不是官方 Server 時序證明 |

## C. AUTH C→S：登入前的 mode 決策、字串與本地送包

### C.1 入口：`0x440790` 是 mode 分派而非封包格式本身

`0x440793` 讀 `[ecx+8]` mode；比較 `0x52` 時使用 `0x4A3360`；比較 `0x54` 與其餘路徑均使用 `0x4A31B0`。這個 mode 是 Client 啟動／本地選擇域，**不等於傳輸 frame marker 0x0BBB/0x1A68**。第一次進入分支時 `FB1314` 的 bit0 可能安排單次本地初始化；不等於認證成功標記。

### C.2 兩個本地 payload 的位元組幾何（由 Send `push size` + field writes 複核）

| 相對位置 | mode52：`0x00E8`，112 bytes | mode54／其他：`0x000F`，214 bytes |
|---|---|---|
| `+0..1` | `E8 00`（LE16） | `0F 00`（LE16） |
| `+2..52` | 第一欄：**51-byte** multibyte C-string 槽，轉碼須成功 | 第一欄：**51 個 wchar_t（102 bytes）**，UTF-16LE-style wide slot |
| `+53..103` / `+104..205` | 第二欄：**51-byte** multibyte C-string 槽，摘要文字經寬/窄轉碼 | 第二欄：**51 個 wchar_t（102 bytes）**，同一摘要文字來源 |
| `+104..109` / `+206..209` | 六 byte opaque：缺正向值，**禁止假定固定全零** | `01 00 01 00`（LE32 `0x00010001`） |
| `+110..111` / `+210..211` | 最後一個 LE16 從 `FB1318+BF80` | `34 00`（LE16 `0x0034`） |
| `+212..213` | — | 最後一個 LE16 從 `FB1318+BF80` |

**重要**：`_strcpy_s(dst,51,src)` 是 copy 容量（可包括 NUL）而不是「官方帳號最多 51 字」；`_wcscpy_s(dst,51,src)` 是 51 個 16-bit unit 的容量，不等於 51 個 Unicode scalar 或 Server 的身份規則。若轉碼或 CRT validation 失敗，不宣稱有有效 payload 可上線；未驗證輸入的實際 runtime 不靠合成字串代替。

- `0x4A33B0` 明寫 LE16 E8；`0x4A33B5` 讀 `FB1318+BF80`；`0x4A34D6`、`0x4A34E9` 以容量 `0x33` 複製兩個窄字串；`0x4A34FC..3505` 送 slot1，len `0x70`。
- `0x4A31E3` 明寫 LE16 000F；`0x4A31F3`、`0x4A31FA` 明寫常數；`0x4A327D` 寫同來源 version-like word，`0x4A329A..32A3` 容量0x33 的 wchar copy，`0x4A32B6..32C4` 送 slot1 len `0xD6`。
- MD5-like 16-byte digest → `%02x` 小寫文字路徑已有原生依據：`0x47F540 → 0x733DD0 → 0x733C30 / 0x809BA0 → 0x46E3C0`，並已由歷史有限核對稿記錄 MD5 IV 與常數。本次以 BIN 重新看到 `0x733DD0`、`0x46E3C0`、`0x47F540` calls；**不能由本地摘要計算反推出原版伺服器的密碼儲存、加鹽、重試、帳號政策**。原版是否對所有例外輸入都成功生成相同 digest 未全證。

### C.3 E8 `+104..+109` 不透明欄位的正確驗收方式

檢視 `0x4A3360` 整段 `0x4A33A0..0x4A3505`：可確實指認包頭、兩個字串區複製與最後來源 Word，**沒有合理依據給中間六個位元組指定官方欄名**；任何採用固定0的本機 fixture 都屬 Server 設計/合成填值，不可說是 Client 每次真的送相同 bytes。若要解除 U，需就實際 stack SSA/CRT 調用記憶體範圍及初始化完整證明，或使用取得明確許可的 runtime 記憶體／WSASend 擷取。這不是把仍可查驗的 Client 入口一概丟給 Server，而是對本稿逐 byte 已證寫入的清晰負界線。

### C.4 請求到通訊層的精確邊界

`FBA854` manager vtable `+0x10`、slot1，`push` 的本地 payload 長度為 112 或 214。T02 已核的 `0x8060D0→0x8061A0→0x807830/0x807A70→0x8068B0 WSASend` 仍受 mode、queue、socket 與 send callback gate 影響；**C2S payload bytes 不是完整 wire bytes**。別把 `0x00E8` / `0x000F` 當成 framing marker、也別把 112/214 當作 TCP frame 長度。

## D. Codepage 依賴與真正能證的預設

Windows PE import table：IAT `0xBD21CC` 是 `WideCharToMultiByte`；IAT `0xBD230C` 是 `MultiByteToWideChar`。Native 多個直接 caller 在堆疊參數傳入 `DWORD PTR [0xFBA808]` 作 CodePage：

```asm
40410c  mov ecx, DWORD PTR ds:0xfba808
404124  call ebx            ; ebx = IAT BD230C
46e2ca  mov ecx, DWORD PTR ds:0xfba808
46e2d6  call DWORD PTR ds:0xbd230c
47f59e  mov eax, DWORD PTR ds:0xfba808
47f5a5  call DWORD PTR ds:0xbd21cc
47f5d9  mov edx, DWORD PTR ds:0xfba808
47f5f3  call DWORD PTR ds:0xbd21cc
4c37e7  mov edx, DWORD PTR ds:0xfba808
4c3800  call DWORD PTR ds:0xbd21cc
```

**原始 PE 實測反例**：`0xFBA808` 落在 `.data` 的虛擬範圍，偏移 `0x259808`，但 `.data` *raw size* 只有 `0x22B800`。此地址是**載入器零填充的 uninitialized virtual tail（BSS-like）**，不是可以用 `VA→raw` 直接從檔案讀出的初始化 DWORD。若錯誤將超過 raw 區域的 VA 換成檔案 offset，會讀到 `.rsrc` 等無關 bytes 並誤認為非零 codepage。故正確說法是「此 image 的 loader 初始記憶體為0」，而不是「BIN 檔案在這個 offset 明存四個 `00`」。

於 `.text` 搜尋 4-byte immediate `08 A8 FB 00` 共 **7 個命中位置**：`0x40410E`、`0x404159`、`0x46E2CC`、`0x46E31E`、`0x47F59F`、`0x47F5DB`、`0x4C37E9`（此為 immediate 所在位置，非每條指令起點）；各自的直接引用均為讀取。這是**具搜尋範圍限制的陰性結果**，不排除透過 alias/基底指標或 memcpy 寫入。`CodePage=0` 對 Windows API 表示 CP_ACP，因此依系統 active ANSI codepage，**沒有證據強迫相容 Server 將全部字串當成 UTF-8、CP949 或固定一個平台上的字元集**。同一帳號字元在不同系統 codepage 可能變成不同 bytes；應以來源 bytes 和傳輸路徑為 Server 契約基準。

## E. AUTH S→C：`0x0013` 結果 handler、結果欄位與錯誤條件

### E.1 命令身份、場景條件

`0x4C3220` 是登入場景的第二層 handler 表初始化段：

```asm
4c323b mov DWORD PTR [esi+0x5f44],0x4c37a0  ; (0x5f44-0x5eac)/8 = 0x13
4c325b mov DWORD PTR [esi+0x627c],0x4c3c10  ; (0x627c-0x5eac)/8 = 0x7a
```

所以在有效登入場景、對應 table 被註冊及 T02 已確認的 channel2/decode/delegate gate 成立時，**S2C app command 0x0013** 可進 `0x4C37A0`，`0x007A` 可進 `0x4C3C10`。只有處理器存在，**不代表原版 Server 在登入成功後必然先送哪筆**，也不代表該指標在全 Client 場景均有效。

### E.2 結果分支完整局部 CFG

1. `0x4C37CE`: ESI 取得輸入 payload 指標；`0x4C37D3` 若 `payload+0x20` 的 `WCHAR` 非零，先經全域 codepage 轉換與獨立文字緩衝更新；這個 optional notice 分支**在 status 判斷之前**，不能因失敗就推定全無字串副作用。
2. `0x4C3821`: `BYTE [payload+0x16]` 與 `5` 比較；等於5走 `0x4C382D` 專用錯誤資源、通知與 `0x4C3933` 的 vtable+0x20（push 1,1）後，至 `0x4C3B59`：寫 `Client+BF60=0`、回 `0x80004005`。此路徑**不執行 status0 的身分欄位寫入/群組解析**。
3. 若 status !=5，`0x4C3949` `test dl,dl`；非零走 `0x4C3A30` 的一般錯誤：錯誤碼傳 log/格式化，走 vtable+0x20，`Client+BF60=0`，回 `0x80004005`。這條不是 status5 的相同 UI 資源。
4. `status=0` 時，從 `payload+2` 步進 2 byte 尋找 UTF-16 NUL；若**名稱空**（`0x4C3973`），仍跳錯誤分支。沒有看到這段對輸入 buffer 終點的逐步長度檢查，**不應建造沒有 NUL 的合成回覆**。
5. `status=0` 且名字非空時，進 `0x4C3979..4C3A29`：寫 Client 相應狀態，group parse，視 `+0x90` 決定是否觸發 `0x4C3170`。**返回0**；不能把返回0直接叫做已經切到所有 socket。

### E.3 `0x0013` response 主要欄位（relative to app payload）

| 欄位位移 | 讀取方式 / 本地效果 | 已證程度與 Server 合約界線 |
|---|---|---|
| `+0..1` | S2C application LE16 command `0x0013`（由 T02 dispatcher 辨認） | N/C：要有合法外框/lane/scene；不是 frame magic |
| `+2` | NUL 終止寬字串（status0 的名稱），copy 到 Client+0x67E4，`_wcsncpy_s(dest,11,src,10)` | N：需有效 terminator 和長度；不能據此推出官方帳號允許長度 |
| `+0x16` | `BYTE status`，`5` 專用失敗；`0` 且名稱非空成功；其他或空名失敗 | N：分支，U：完整官方 result enum |
| `+0x17` | `BYTE → Client+0x68B4`（實作使用 movzx → DWORD） | N：writer，U：業務語意 |
| `+0x18` | `DWORD → Client+0x67E0` | N：writer，U：官方 ID 語意/配置方式 |
| `+0x1C` | `DWORD groupCount` 供 `0x4C3080` | N：group 數量；U：上限/Server policy |
| `+0x20` | 可選寬字串，非零時轉碼至全域文字區 | N：在 status check 前；U：正式 notice 語意及容量界線 |
| `+0x86` | `BYTE → Client+0x6898` | N：writer，U：token/session type 意義 |
| `+0x87` | NUL終止窄字串，`_strcpy_s` 目標容量5 到 Client+0x6899 | N：copy 容量5，U：官方 token 值及生命期 |
| `+0x8C` | `DWORD → Client+0x68A0` | N：writer，U：官方 ticket/nonce 語意 |
| `+0x90` | `BYTE → Client+0x68B0`；為0才呼叫 `0x4C3170` | N：條件，U：命名成「成功權限」的業務意思 |
| `+0x92` | group 資料游標起點 | N：隨 `+0x1C` count 迴圈；U：上游資料長度完整校驗 |

**不能互借**：`0x0013` 的 status at `+0x16` 與 T03 其他訊息的 `+0x02`、場景層 `0x42` 回覆、T02 frame marker `0x0BBB` 是不同 namespace / buffer base。

## F. Group/channel 清單格式、cursor、數量與缺少的 guard

### F.1 來自原始 `0x4C3080` 的解析模型

入口 `[ebp+8]` 為 group 數 `uint32`（寄存器 EBX），`ECX` 是**目前 group 游標指標**（EDI）。每次：

```c
// Native path semantics; NOT a trusted-length-safe parser.
void parse_groups(uint8_t* cursor, uint32_t group_count) {
    reset_local_choice_list();                 // call 0x4C4240
    for (uint32_t g=0; g<group_count; g++) {
        const uint16_t group_id = le16(cursor); // [EBX]
        const uint8_t n = cursor[2];            // [EBX+2]
        register_group(group_id);              // call 0x507510
        cursor += 3;
        for (unsigned i=0; i<n; ++i) {
            auto row = cursor;
            char host[/*local*/];
            format_decimal_ipv4(row[4],row[5],row[6],row[7],host);
            if(row[8] != 0) {
                append_row(group_id, le16(row), row[9], host); // 0x507610
            }
            cursor += 10;                     // even filtered-out rows advance
        }
    }
    dispatch_local_event(0xF4243); // also when group_count==0
}
```

本稿中 `format_decimal_ipv4` 的實際格式常數是 `.rdata` `0xBFB050` 的 `%d.%d.%d.%d`（與 RR-0005 E45 交叉）。**`row[2..3]` 用途未閉合，不能假設它們一定 0；`row[8]` 可證為是否 append 的 filter，未證明其官方名為「online」；`row[9]` 有 native `movzx edx,[esi+9]` 正向來源，傳給 `0x507610`，但語意尚未確認。**

### F.2 不同 S2C 命令的 group payload 入口不可混合

| 命令/handler | Count | 第一筆 group 游標 | 迴圈解析 |
|---|---|---|---|
| `0x0013` / `0x4C37A0`（status0有效名） | `DWORD payload[0x1C..0x1F]` | `payload+0x92` | `0x4C3080` |
| `0x007A` / `0x4C3C10` | `DWORD payload[+2..+5]` | `payload+6` | 同一 `0x4C3080` |

Group count 為0時 `0x4C30AA` 跳到 `0x4C314A` **仍送本地 `F4243` 通知**，不是無輸出/直接 return。每 group childCount=0 時只消耗3 bytes；每 child 無論 row[8] 是否為0，都消耗10 bytes。

### F.3 可以推導的長度算術 ≠ Client 已驗證的長度保護

用 `n_i` 表第 `i` 組 byte `channelCount`，對 `0x0013` 清單可從 Native 指標步進推得：

\[
  L_\text{needed} = 0x92 + \sum_{i=1}^G (3 + 10 n_i)
\]

同一 group/row 集合在 `0x007A` 的需求是 `6 + Σ(3 + 10 n_i)`。合成例：空清單 `0x0013` 的入口游標從 `0x92` 起但不讀群組；一組兩頻道需要 `0x92+3+20=0xA9=169` bytes（作為滿足本地讀取的最低 byte extent），**不表示 Server 真正回過這種清單，也不表示4KiB是單一群組欄位上限**。

`0x4C3080` 內讀 groupCount/childCount 時，未見「將 cursor 與 inbound buffer total length 比較」的原生指令；`0x4C37A0` 名稱 NUL 迴圈也沒有自己的 end pointer。底層 T02 frame parser 的有效 payload 最大 0x1000，**不會自動證明上層這些變長讀取已按陣列大小安全驗證**。因此安全 Server 應自行依上式對每個 row 檢查構造完整性，這是**相容規格要求的保守工程建議，不是擅稱原 Client 自己做了此檢查**。

## G. 從登入回覆到選服：到底有什麼已經可證

```text
本地 mode 0x52 / other → 建 00E8/000F C2S local payload → manager slot1 enqueue
    [framing/send queue/io completion 由 T02 管理，實際 wire 次序 U]
S2C frame decode → app command word 0x0013, lane2, active login scene
    → 4C37A0
       ├─ +0x16=5：專用失敗/清理 → manager shutdown(1,1) → Client+BF60=0
       ├─ +0x16!=0 或 name empty：一般失敗/清理
       └─ +0x16=0 && name非空：Client identity/session字段更新
            → 4C3080(G,+0x92) 更新群組/頻道資料，發 F4243
            → 若 +0x90==0：4C3170 寫 BD54/BD58、發 F4241
            → UI 後續可取得 group/channel 資料
                 → 玩家選擇/資料可用/控件 gate（T03）
                 → 66C090→4957C0: 連 key0:20E0 / key2:20DE（T02 RR5）
```

**分層的重要限制**：S2C frame 到 T03 handler 需要 T02 已證的 `Conn/queue/lane2` 路徑與活躍登入場景；登入 `0x13` 的本地 group event != 已經選服；`4C3170` 的 `timeGetTime` 及 `F4241` != Server 發過官方 connect acceptance；`66C090→4957C0` 也有 UI/record/連線成敗 gate，不能從 `status=0` 自動確保 Socket key0/key2 建立。Client 固定端口 (`0x20E0`,`0x20DE`,`0x20DF`) 是舊 Client literal，而非推薦新 Server 的部署拓撲。

**已提交來源限定復用**：`extra/roy1` E45（IPv4 octets→ASCII端點）、E56（key0/1/2連線及首包）、`rr/t02/roy/rr-0007` E60（第一層/第二層/scene 的指令路由）、及 `kr/evidence/602d11...`（先前 T03 有界 native notes）。這些報告不能自動合稱 T01 FULL-PASS；此次再核的 `0x4C37A0/4C3080` 和 `0x4A31B0/4A3360` 為本稿第一手補證範圍。

## H. 玩家情境矩陣：輸入、回覆、狀態、未知

| 玩家情境 | Client 條件 → C2S | 可證的 S2C consumer | UI/狀態後果 | Server-facing NEED / UNKNOWN |
|---|---|---|---|---|
| 啟動 mode=0x52，填入登入資料 | `4A3360`, LE16 E8, 112B，slot1 | 非由 mode 直接決定；需相容 S2C 0x13 | 送出後有字串 slot 清理，不能直接顯示登入成功 | Server policy／官方密碼比對 U；E8 tail6 bytes U |
| 啟動 mode=0x54 或其他 | `4A31B0`, LE16 000F, 214B，slot1 | 同上，不能假設 reply opcode 必然 +1 | 由實際 status/scene 觸發後續 UI | 字串編碼/CP_ACP；不能把測試固定值當官方資料 |
| `0x13` status 5 | 不是新 C2S | 登入場景 `4C37A0` 特殊錯誤 | 專用通知、vtable+20、BF60清零、返回0x80004005 | 錯誤顯示資源/文案原語意 U |
| `0x13` status非0且非5 或 status0空名 | 同上 | `4C37A0` 一般失敗 | log/本地錯誤+關閉/清理，不填身份/群組 | 全部 status enum U；別替 Server 硬造狀態 |
| `0x13` status0、名稱非空 | 同上 | `4C37A0` identity writes，清單解析 | F4243；+90為0又觸發F4241/BD54/BD58 | 群組 count、rows、身份token實值由新 Server 自行提供，需符合 Client 已證欄位 |
| 獨立 `0x7A` 列表回覆 | 不自動代表 auth C2S | `4C3C10`: +2 count/+6 cursor | 同一 group parser，發 F4243 | 發送時機/Server 策略 U，不能與0x13共用 byte layout |
| 使用者選擇有效頻道 | UI event gate→Connect | 由 RR5 確認限定條件 | key0/key2 新 Conn，依後續成功/失敗進行狀態處理 | 不是 `0x13` 直接網路副作用；原版 Server 服務分派規則 U |

## I. 原生驗證與反證／限制清單

- **N：** 原始檔 SHA/section/header/IAT；`0x440790` 分支、兩個 payload 送出長度、`0x4C37A0` 主要 status gate、`0x4C3080` count+cursor+row、`0x4C3C10` 替代 count cursor、`0x4C3170` state writer、`0x4C3220` handler 表。
- **N：** `0xFBA808` VA 屬於 PE `.data` virtual zero-tail，不在檔案 raw 區域；direct immediate xref 7處皆讀，不能以超出raw的 bytes 作 static initialized DWORD。系統 ACP 仍是 OS/runtime 依賴。
- **C：** MD5 文字鏈在正常返回、有效轉碼/有效buffer的前提可作 C2S bytes 來源；`0x13→group/UI→選服` 有本地多階段條件；登入 `0x13` 並非所有 scene 皆可處理。
- **U（Client 靜態尚未完整正向閉合）**：E8 `+104..+109` 每次運行的確切六個 bytes；`FBA808` 所有間接 alias writers；輸入過長 CRT invalid-param/exception 的完整控制流；上層針對 `0x13`/`0x7A` 變長 payload 的最終安全長度驗證；使用者啟動/launcher mode 選擇的完整來源和任意字元的實際 codepage。
- **U（原版 Server 不可從 Client 本身求出）**：帳號庫、認證規則、MD5儲存/加鹽/比較、session token生成與過期政策、官方 server IP/多 Conn 的實際 TCP 封包先後、正式 status enum 其餘所有值及實際 gameplay 使用。
- **交給 T03 RR-0002/0008、T04/T05/T06**：選角 response 對應、角色清單權威、進入場景/初次 tutorial 的 scene state writer、UI control identity。不應藉本 RR 宣稱已完整登入→可遊玩。
- **可解除未知的下一證據**：E8 stack-SAA/CRT完整生命週期和記憶體寫入範圍；全 `.text` 間接資料流到 `FBA808`，跨函式指標別名；輸入 payload length 在 `4C4670/4FDA30` 前置的逐項傳遞；經使用者明確許可的本地除錯截圖／WSASend 前內存dump/封包；原版 Server 官方協定文件（若取得）。上述項目未在本稿臆造官方值。

## J. 相容 Server 專用的工程驗收矩陣（不是官方 Server 內部政策）

| 測試 ID | 測試條件 | 由 Client Native 可要求的結果 | 範圍 |
|---|---|---|---|
| AUTH-C2S-E8 | 模擬 mode52，生成有效 112B 本地 payload | LE16 E8 / 2個51-byte窄字串槽；不能以 padding 猜 E8 tail | T03 writer bytes + T02 framing |
| AUTH-C2S-F | 模擬 mode54，生成有效 214B 本地 payload | LE16 000F / 2個102-byte wide欄 / 常數尾 / 來源 WORD | T03 writer bytes |
| AUTH-CP-0 | 在不同 ACP 環境輸入可轉與不可轉字符 | 維持原始轉碼 API 的適用邊界；不要把UTF8/949寫死成「官方」 | codepage OS 依賴；待實機驗證 |
| AUTH-13-S5 | payload+16=5，合法傳入場景 | 專用錯誤/關閉分支，不更新 session list | handler bounded path |
| AUTH-13-SOTHER | payload+16=其他非0或無名稱 | 一般錯誤與清理；不應假裝驗證成功 | handler bounded path |
| AUTH-13-S0 | status=0且名稱正確NUL終止、group格式自洽 | identity writes，group event；+90為0另有 state/event | 成功 handler bounded path |
| AUTH-13-GROUP0 | groupCount=0 | 仍派本地 F4243 | 4C3080 group-zero branch |
| AUTH-13-ROW0 | groupCount=1且childCount=0 | 消耗3B，不 append row，仍 F4243 | length arithmetic |
| AUTH-13-ROW2 | groupCount=1且childCount=2 | 需 `0x92+3+20=0xA9` 的資料範圍 | **合成算術測試，不是官方實包** |
| AUTH-7A-LIST | 0x7A 有效場景與 layout | count at+2,cursor+6、同 group loop | 不可套 0x13 的 count/cursor |
| AUTH-HANDOFF | UI 中實際選擇有效 row | 有界 Connect callsite 及 key0/key2失敗行為（依E56） | 不能只靠 0x13 success 推定自動 Connect |

**來源追溯索引**：

- `kr/evidence/602d11a657a2e8a3dc53cff4664f837d579cd6cb187311b2c4c7070e994887d9.txt`：早期 T03 登入來源與 fixture 對照，現由本稿重新核實的正確部分才以 N 表述。
- `unclassified/evidence/4cb0b42cbee49f5e05fff20c2ff5f5eca257c24c0fbe060371bc59ec0e1177e8.txt`、`d4184e747c61654be90f36a379cb745f17e882bcf67fdcd266156acb53a84360.txt`：既存 000F/E8 Ghidra 反組譯導航；此次以原始 BIN 的 GNU objdump 獨立核對。
- `kr-extra-roy/20261030-091559-chatgpt-web-roy-E56-RR0005-bounded-static-completion-transport-owner-retry-reply.md`，`extra/roy1` Git blob `843889349bb58209c02221e720800f0e9e3ff9d8`：已限定 Connect/socket/選服 interface。
- `kr-extra-roy/20261030-113803-chatgpt-web-roy-E60-RR0007-KR-auth-roster-selection-scene-gated-S2C-dispatch.md`，T02 RR7 Git blob `2ca02f3870d79d3217abf39b8651c43226eb77d6`：已限定 frame→lane2→scene 的兩層 handler。
- `spec/session-account/phase-b-message-matrix.md`：S00 原本的設計查驗矩陣，本稿僅交證據，**不修改 S00 SPEC 或狀態**。

## K. 合成驗算工具（不執行 Client；不冒充原版封包）

```python
def required_group_bytes(group_channel_counts, offset=0x92):
    assert all(0 <= n <= 255 for n in group_channel_counts)
    return offset + sum(3 + 10*n for n in group_channel_counts)

assert required_group_bytes([]) == 0x92
assert required_group_bytes([0]) == 0x95
assert required_group_bytes([1]) == 0x9f
assert required_group_bytes([2]) == 0xa9
assert required_group_bytes([1, 3]) == 0xc0
assert required_group_bytes([255]) == 0xa8b
```

這些是數學測試向量：**不是**原版 Client 實際接收過的封包；Server 仍需額外驗證字串 NUL、frame length、各 group cursor 與 rows 完整性。

## 附錄 L — 每個重要函式的第一手 `.text` 原始指令節選

下列是直接對 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 的 BIN 進行反組譯，不是其他 Agent 重新撰寫的偽碼。地址前綴的 `.data+...` 是 GNU **raw binary disassembler 的段名顯示**（該指令輸入不讀 PE 節名），這些 VA 實際在上文核對的 PE `.text`；**不要誤認為真正在 `.data` 執行**。

### AUTH mode dispatch `0x440790`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00440790 <.data+0x3fb90>:
  440790:	55                   	push   ebp
  440791:	8b ec                	mov    ebp,esp
  440793:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  440796:	83 f8 52             	cmp    eax,0x52
  440799:	75 30                	jne    0x4407cb
  44079b:	b8 01 00 00 00       	mov    eax,0x1
  4407a0:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  4407a6:	75 13                	jne    0x4407bb
  4407a8:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  4407ae:	68 10 cf bc 00       	push   0xbccf10
  4407b3:	e8 62 1b 45 00       	call   0x89231a
  4407b8:	83 c4 04             	add    esp,0x4
  4407bb:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4407be:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4407c1:	50                   	push   eax
  4407c2:	e8 99 2b 06 00       	call   0x4a3360
  4407c7:	5d                   	pop    ebp
  4407c8:	c2 08 00             	ret    0x8
  4407cb:	83 f8 54             	cmp    eax,0x54
  4407ce:	b8 01 00 00 00       	mov    eax,0x1
  4407d3:	75 2b                	jne    0x440800
  4407d5:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  4407db:	75 13                	jne    0x4407f0
  4407dd:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  4407e3:	68 10 cf bc 00       	push   0xbccf10
  4407e8:	e8 2d 1b 45 00       	call   0x89231a
  4407ed:	83 c4 04             	add    esp,0x4
  4407f0:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4407f3:	51                   	push   ecx
  4407f4:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4407f7:	e8 b4 29 06 00       	call   0x4a31b0
  4407fc:	5d                   	pop    ebp
  4407fd:	c2 08 00             	ret    0x8
  440800:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  440806:	75 13                	jne    0x44081b
  440808:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  44080e:	68 10 cf bc 00       	push   0xbccf10
  440813:	e8 02 1b 45 00       	call   0x89231a
  440818:	83 c4 04             	add    esp,0x4
  44081b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  44081e:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  440821:	52                   	push   edx
  440822:	e8 89 29 06 00       	call   0x4a31b0
  440827:	5d                   	pop    ebp
  440828:	c2 08 00             	ret    0x8
  44082b:	cc                   	int3
  44082c:	cc                   	int3
  44082d:	cc                   	int3
  44082e:	cc                   	int3
  44082f:	cc                   	int3
  440830:	55                   	push   ebp
  440831:	8b ec                	mov    ebp,esp
  440833:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  440836:	8d 45 0c             	lea    eax,[ebp+0xc]
  440839:	50                   	push   eax
  44083a:	51                   	push   ecx
  44083b:	6a 40                	push   0x40
  44083d:	52                   	push   edx
  44083e:	e8 46          	call   0x891e89
```

### Wide 000F C2S builder `0x4A31B0`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004a31b0 <.data+0xa25b0>:
  4a31b0:	55                   	push   ebp
  4a31b1:	8b ec                	mov    ebp,esp
  4a31b3:	6a ff                	push   0xffffffff
  4a31b5:	68 38 00 92 00       	push   0x920038
  4a31ba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a31c0:	50                   	push   eax
  4a31c1:	81 ec 34 01 00 00    	sub    esp,0x134
  4a31c7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a31cc:	33 c5                	xor    eax,ebp
  4a31ce:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a31d1:	53                   	push   ebx
  4a31d2:	56                   	push   esi
  4a31d3:	57                   	push   edi
  4a31d4:	50                   	push   eax
  4a31d5:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a31d8:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a31de:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a31e1:	8b f1                	mov    esi,ecx
  4a31e3:	b9 0f 00 00 00       	mov    ecx,0xf
  4a31e8:	50                   	push   eax
  4a31e9:	8d 7d 9c             	lea    edi,[ebp-0x64]
  4a31ec:	66 89 8d c4 fe ff ff 	mov    WORD PTR [ebp-0x13c],cx
  4a31f3:	c7 45 92 01 00 01 00 	mov    DWORD PTR [ebp-0x6e],0x10001
  4a31fa:	c7 45 96 34 00 00 00 	mov    DWORD PTR [ebp-0x6a],0x34
  4a3201:	e8 3a c3 fd ff       	call   0x47f540
  4a3206:	83 c4 04             	add    esp,0x4
  4a3209:	33 db                	xor    ebx,ebx
  4a320b:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4a320e:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  4a3215:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  4a3218:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  4a321b:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4a321f:	83 7d b0 10          	cmp    DWORD PTR [ebp-0x50],0x10
  4a3223:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  4a3226:	73 02                	jae    0x4a322a
  4a3228:	8b cf                	mov    ecx,edi
  4a322a:	8b 55 ac             	mov    edx,DWORD PTR [ebp-0x54]
  4a322d:	52                   	push   edx
  4a322e:	8d 7d d4             	lea    edi,[ebp-0x2c]
  4a3231:	e8 9a 0b 29 00       	call   0x733dd0
  4a3236:	83 ec 18             	sub    esp,0x18
  4a3239:	8b cc                	mov    ecx,esp
  4a323b:	89 a5 c0 fe ff ff    	mov    DWORD PTR [ebp-0x140],esp
  4a3241:	6a ff                	push   0xffffffff
  4a3243:	53                   	push   ebx
  4a3244:	8d 45 d4             	lea    eax,[ebp-0x2c]
  4a3247:	bf 0f 00 00 00       	mov    edi,0xf
  4a324c:	89 79 14             	mov    DWORD PTR [ecx+0x14],edi
  4a324f:	89 59 10             	mov    DWORD PTR [ecx+0x10],ebx
  4a3252:	50                   	push   eax
  4a3253:	88 19                	mov    BYTE PTR [ecx],bl
  4a3255:	e8 e6 fd f5 ff       	call   0x403040
  4a325a:	8d 4d b8             	lea    ecx,[ebp-0x48]
  4a325d:	e8 5e b1 fc ff       	call   0x46e3c0
  4a3262:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  4a3266:	8b 0d 18 13 fb 00    	mov    ecx,DWORD PTR ds:0xfb1318
  4a326c:	66 8b 91 80 bf 00 00 	mov    dx,WORD PTR [ecx+0xbf80]
  4a3273:	56                   	push   esi
  4a3274:	8d 85 c6 fe ff ff    	lea    eax,[ebp-0x13a]
  4a327a:	6a 33                	push   0x33
  4a327c:	50                   	push   eax
  4a327d:	66 89 55 98          	mov    WORD PTR [ebp-0x68],dx
  4a3281:	e8 c7 fb 3e 00       	call   0x892e4d
  4a3286:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  4a3289:	be 08 00 00 00       	mov    esi,0x8
  4a328e:	83 c4 28             	add    esp,0x28
  4a3291:	39 75 cc             	cmp    DWORD PTR [ebp-0x34],esi
  4a3294:	73 03                	jae    0x4a3299
  4a3296:	8d 45 b8             	lea    eax,[ebp-0x48]
  4a3299:	50                   	push   eax
  4a329a:	8d 8d 2c ff ff ff    	lea    ecx,[ebp-0xd4]
  4a32a0:	6a 33                	push   0x33
  4a32a2:	51                   	push   ecx
  4a32a3:	e8 a5 fb 3e 00       	call   0x892e4d
  4a32a8:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a32ae:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a32b0:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a32b3:	83 c4 0c             	add    esp,0xc
  4a32b6:	68 d6 00 00 00       	push   0xd6
  4a32bb:	8d 85 c4 fe ff ff    	lea    eax,[ebp-0x13c]
  4a32c1:	50                   	push   eax
  4a32c2:	6a 01                	push   0x1
  4a32c4:	ff d2                	call   edx
  4a32c6:	b9 66 00 00 00       	mov    ecx,0x66
  4a32cb:	8d 85 c6 fe ff ff    	lea    eax,[ebp-0x13a]
  4a32d1:	88 18                	mov    BYTE PTR [eax],bl
  4a32d3:	40                   	inc    eax
  4a32d4:	49                   	dec    ecx
  4a32d5:	75 fa                	jne    0x4a32d1
  4a32d7:	b9 66 00 00 00       	mov    ecx,0x66
  4a32dc:	8d 85 2c ff ff ff    	lea    eax,[ebp-0xd4]
  4a32e2:	88 18                	mov    BYTE PTR [eax],bl
  4a32e4:	40                   	inc    eax
  4a32e5:	49                   	dec    ecx
  4a32e6:	75 fa                	jne    0x4a32e2
  4a32e8:	39 75 cc             	cmp    DWORD PTR [ebp-0x34],esi
  4a32eb:	72 0c                	jb     0x4a32f9
  4a32ed:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  4a32f0:	50                   	push   eax
  4a32f1:	e8 16 df 3e 00       	call   0x89120c
  4a32f6:	83 c4 04             	add    esp,0x4
  4a32f9:	33 c9                	xor    ecx,ecx
  4a32fb:	be 10 00 00 00       	mov    esi,0x10
  4a3300:	c7 45 cc 07 00 00 00 	mov    DWORD PTR [ebp-0x34],0x7
  4a3307:	89 5d c8             	mov    DWORD PTR [ebp-0x38],ebx
  4a330a:	66 89 4d b8          	mov    WORD PTR [ebp-0x48],cx
  4a330e:	39 75 e8             	cmp    DWORD PTR [ebp-0x18],esi
  4a3311:	72 0c                	jb     0x4a331f
  4a3313:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  4a3316:	52                   	push   edx
  4a3317:	e8 f0 de 3e 00       	call   0x89120c
  4a331c:	83 c4 04             	add    esp,0x4
  4a331f:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  4a3322:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  4a3325:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  4a3328:	39 75 b0             	cmp    DWORD PTR [ebp-0x50],esi
  4a332b:	72 0c                	jb     0x4a3339
  4a332d:	8b 45 9c             	mov    eax,DWORD PTR [ebp-0x64]
  4a3330:	50                   	push   eax
  4a3331:	e8 d6 de 3e 00       	call   0x89120c
  4a3336:	83 c4 04             	add    esp,0x4
  4a3339:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a333c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a3343:	59                   	pop    ecx
  4a3344:	5f                   	pop    edi
  4a3345:	5e                   	pop    esi
  4a3346:	5b                   	pop    ebx
  4a3347:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4a334a:	33 cd                	xor    ecx,ebp
  4a334c:	e8 b0 dc 3e 00       	call   0x891001
  4a3351:	8b e5                	mov    esp,ebp
  4a3353:	5d                   	pop    ebp
  4a3354:	c2 04 00             	ret    0x4
  4a3357:	cc                   	int3
  4a3358:	cc                   	int3
  4a3359:	cc                   	int3
  4a335a:	cc                   	int3
  4a335b:	cc                   	int3
  4a335c:	cc                   	int3
  4a335d:	cc                   	int3
  4a335e:	cc                   	int3
  4a335f:	cc                   	int3
  4a3360:	55                   	push   ebp
  4a3361:	8b ec                	mov    ebp,esp
  4a3363:	83 e4 f8             	and    esp,0xfffffff8
  4a3366:	6a ff                	push   0xffffffff
  4a3368:	68 f1 ff 91 00       	push   0x91fff1
  4a336d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a3373:	50                   	push   eax
  4a3374:	81 ec e0 00 00 00    	sub    esp,0xe0
  4a337a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a337f:	33 c4                	xor    eax,esp
  4a3381:	89 84 24 d8 00 00 00 	mov    DWORD PTR [esp+0xd8],eax
  4a3388:	53                   	push   ebx
  4a3389:	56                   	push   esi
  4a338a:	57                   	push   edi
  4a338b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
```

### Narrow E8 C2S builder `0x4A3360`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004a3360 <.data+0xa2760>:
  4a3360:	55                   	push   ebp
  4a3361:	8b ec                	mov    ebp,esp
  4a3363:	83 e4 f8             	and    esp,0xfffffff8
  4a3366:	6a ff                	push   0xffffffff
  4a3368:	68 f1 ff 91 00       	push   0x91fff1
  4a336d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a3373:	50                   	push   eax
  4a3374:	81 ec e0 00 00 00    	sub    esp,0xe0
  4a337a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a337f:	33 c4                	xor    eax,esp
  4a3381:	89 84 24 d8 00 00 00 	mov    DWORD PTR [esp+0xd8],eax
  4a3388:	53                   	push   ebx
  4a3389:	56                   	push   esi
  4a338a:	57                   	push   edi
  4a338b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a3390:	33 c4                	xor    eax,esp
  4a3392:	50                   	push   eax
  4a3393:	8d 84 24 f0 00 00 00 	lea    eax,[esp+0xf0]
  4a339a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a33a0:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  4a33a6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4a33a9:	8b f1                	mov    esi,ecx
  4a33ab:	b9 e8 00 00 00       	mov    ecx,0xe8
  4a33b0:	66 89 4c 24 74       	mov    WORD PTR [esp+0x74],cx
  4a33b5:	66 8b 8a 80 bf 00 00 	mov    cx,WORD PTR [edx+0xbf80]
  4a33bc:	50                   	push   eax
  4a33bd:	8d 7c 24 5c          	lea    edi,[esp+0x5c]
  4a33c1:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4a33c5:	66 89 8c 24 e6 00 00 	mov    WORD PTR [esp+0xe6],cx
  4a33cc:	00 
  4a33cd:	e8 6e c1 fd ff       	call   0x47f540
  4a33d2:	83 c4 04             	add    esp,0x4
  4a33d5:	33 db                	xor    ebx,ebx
  4a33d7:	89 9c 24 f8 00 00 00 	mov    DWORD PTR [esp+0xf8],ebx
  4a33de:	c7 44 24 50 0f 00 00 	mov    DWORD PTR [esp+0x50],0xf
  4a33e5:	00 
  4a33e6:	89 5c 24 4c          	mov    DWORD PTR [esp+0x4c],ebx
  4a33ea:	88 5c 24 3c          	mov    BYTE PTR [esp+0x3c],bl
  4a33ee:	c6 84 24 f8 00 00 00 	mov    BYTE PTR [esp+0xf8],0x1
  4a33f5:	01 
  4a33f6:	83 7c 24 6c 10       	cmp    DWORD PTR [esp+0x6c],0x10
  4a33fb:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  4a33ff:	73 02                	jae    0x4a3403
  4a3401:	8b cf                	mov    ecx,edi
  4a3403:	8b 54 24 68          	mov    edx,DWORD PTR [esp+0x68]
  4a3407:	52                   	push   edx
  4a3408:	8d 7c 24 40          	lea    edi,[esp+0x40]
  4a340c:	e8 bf 09 29 00       	call   0x733dd0
  4a3411:	83 ec 18             	sub    esp,0x18
  4a3414:	8b cc                	mov    ecx,esp
  4a3416:	89 64 24 30          	mov    DWORD PTR [esp+0x30],esp
  4a341a:	6a ff                	push   0xffffffff
  4a341c:	53                   	push   ebx
  4a341d:	8b c7                	mov    eax,edi
  4a341f:	c7 41 14 0f 00 00 00 	mov    DWORD PTR [ecx+0x14],0xf
  4a3426:	89 59 10             	mov    DWORD PTR [ecx+0x10],ebx
  4a3429:	50                   	push   eax
  4a342a:	c6 01 00             	mov    BYTE PTR [ecx],0x0
  4a342d:	e8 0e fc f5 ff       	call   0x403040
  4a3432:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
  4a3436:	e8 85 af fc ff       	call   0x46e3c0
  4a343b:	83 c4 1c             	add    esp,0x1c
  4a343e:	53                   	push   ebx
  4a343f:	53                   	push   ebx
  4a3440:	53                   	push   ebx
  4a3441:	53                   	push   ebx
  4a3442:	6a ff                	push   0xffffffff
  4a3444:	56                   	push   esi
  4a3445:	53                   	push   ebx
  4a3446:	c6 84 24 14 01 00 00 	mov    BYTE PTR [esp+0x114],0x2
  4a344d:	02 
  4a344e:	8b 35 cc 21 bd 00    	mov    esi,DWORD PTR ds:0xbd21cc
  4a3454:	53                   	push   ebx
  4a3455:	ff d6                	call   esi
  4a3457:	83 7c 24 34 08       	cmp    DWORD PTR [esp+0x34],0x8
  4a345c:	8b f8                	mov    edi,eax
  4a345e:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4a3462:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4a3466:	73 04                	jae    0x4a346c
  4a3468:	8d 44 24 20          	lea    eax,[esp+0x20]
  4a346c:	53                   	push   ebx
  4a346d:	53                   	push   ebx
  4a346e:	53                   	push   ebx
  4a346f:	53                   	push   ebx
  4a3470:	6a ff                	push   0xffffffff
  4a3472:	50                   	push   eax
  4a3473:	53                   	push   ebx
  4a3474:	53                   	push   ebx
  4a3475:	ff d6                	call   esi
  4a3477:	57                   	push   edi
  4a3478:	8b d8                	mov    ebx,eax
  4a347a:	e8 be a7 3d 00       	call   0x87dc3d
  4a347f:	83 c4 04             	add    esp,0x4
  4a3482:	53                   	push   ebx
  4a3483:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  4a3487:	e8 b1 a7 3d 00       	call   0x87dc3d
  4a348c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4a3490:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  4a3494:	83 c4 04             	add    esp,0x4
  4a3497:	6a 00                	push   0x0
  4a3499:	6a 00                	push   0x0
  4a349b:	51                   	push   ecx
  4a349c:	52                   	push   edx
  4a349d:	6a ff                	push   0xffffffff
  4a349f:	8b f8                	mov    edi,eax
  4a34a1:	8b 44 24 30          	mov    eax,DWORD PTR [esp+0x30]
  4a34a5:	50                   	push   eax
  4a34a6:	6a 00                	push   0x0
  4a34a8:	6a 00                	push   0x0
  4a34aa:	ff d6                	call   esi
  4a34ac:	83 7c 24 34 08       	cmp    DWORD PTR [esp+0x34],0x8
  4a34b1:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4a34b5:	73 04                	jae    0x4a34bb
  4a34b7:	8d 44 24 20          	lea    eax,[esp+0x20]
  4a34bb:	6a 00                	push   0x0
  4a34bd:	6a 00                	push   0x0
  4a34bf:	53                   	push   ebx
  4a34c0:	57                   	push   edi
  4a34c1:	6a ff                	push   0xffffffff
  4a34c3:	50                   	push   eax
  4a34c4:	6a 00                	push   0x0
  4a34c6:	6a 00                	push   0x0
  4a34c8:	ff d6                	call   esi
  4a34ca:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4a34ce:	51                   	push   ecx
  4a34cf:	8d 54 24 7a          	lea    edx,[esp+0x7a]
  4a34d3:	6a 33                	push   0x33
  4a34d5:	52                   	push   edx
  4a34d6:	e8 7e 06 3f 00       	call   0x893b59
  4a34db:	83 c4 0c             	add    esp,0xc
  4a34de:	57                   	push   edi
  4a34df:	8d 84 24 ad 00 00 00 	lea    eax,[esp+0xad]
  4a34e6:	6a 33                	push   0x33
  4a34e8:	50                   	push   eax
  4a34e9:	e8 6b 06 3f 00       	call   0x893b59
  4a34ee:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a34f4:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a34f6:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a34f9:	83 c4 0c             	add    esp,0xc
  4a34fc:	6a 70                	push   0x70
  4a34fe:	8d 44 24 78          	lea    eax,[esp+0x78]
  4a3502:	50                   	push   eax
  4a3503:	6a 01                	push   0x1
  4a3505:	ff d2                	call   edx
  4a3507:	b9 33 00 00 00       	mov    ecx,0x33
  4a350c:	8d 44 24 76          	lea    eax,[esp+0x76]
  4a3510:	c6 00 00             	mov    BYTE PTR [eax],0x0
  4a3513:	40                   	inc    eax
  4a3514:	49                   	dec    ecx
  4a3515:	75 f9                	jne    0x4a3510
  4a3517:	b9 33 00 00 00       	mov    ecx,0x33
  4a351c:	8d 84 24 a9 00 00 00 	lea    eax,[esp+0xa9]
  4a3523:	c6 00 00             	mov    BYTE PTR [eax],0x0
  4a3526:	40                   	inc    eax
  4a3527:	49                   	dec    ecx
  4a3528:	75 f9                	jne    0x4a3523
  4a352a:	83 7c 24 34 08       	cmp    DWORD PTR [esp+0x34],0x8
  4a352f:	72 0d                	jb     0x4a353e
  4a3531:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4a3535:	50                   	push   eax
  4a3536:	e8 d1 dc 3e 00       	call   0x89120c
  4a353b:	83 c4 04             	add    esp,0x4
  4a353e:	33 ff                	xor    edi,edi
  4a3540:	33 c9                	xor    ecx,ecx
  4a3542:	be 10 00 00 00       	mov    esi,0x10
  4a3547:	c7 44 24 34 07 00 00 	mov    DWORD PTR [esp+0x34],0x7
  4a354e:	00 
  4a354f:	89 7c 24 30          	mov    DWORD PTR [esp+0x30],edi
  4a3553:	66 89 4c 24 20       	mov    WORD PTR [esp+0x20],cx
  4a3558:	39 74 24 50          	cmp    DWORD PTR [esp+0x50],esi
  4a355c:	72 0d                	jb     0x4a356b
  4a355e:	8b 54 24 3c          	mov    edx,DWORD PTR [esp+0x3c]
  4a3562:	52                   	push   edx
  4a3563:	e8 a4 dc 3e 00       	call   0x89120c
  4a3568:	83 c4 04             	add    esp,0x4
  4a356b:	c7 44 24 50 0f 00 00 	mov    DWORD PTR [esp+0x50],0xf
  4a3572:	00 
  4a3573:	89 7c 24 4c          	mov    DWORD PTR [esp+0x4c],edi
  4a3577:	c6 44 24 3c 00       	mov    BYTE PTR [esp+0x3c],0x0
  4a357c:	39 74 24 6c          	cmp    DWORD PTR [esp+0x6c],esi
  4a3580:	72 0d                	jb     0x4a358f
  4a3582:	8b 44 24 58          	mov    eax,DWORD PTR [esp+0x58]
  4a3586:	50                   	push   eax
  4a3587:	e8 80 dc 3e 00       	call   0x89120c
  4a358c:	83 c4 04             	add    esp,0x4
  4a358f:	8b 8c 24 f0 00 00 00 	mov    ecx,DWORD PTR [esp+0xf0]
  4a3596:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a359d:	59                   	pop    ecx
  4a359e:	5f                   	pop    edi
  4a359f:	5e                   	pop    esi
  4a35a0:	5b                   	pop    ebx
  4a35a1:	8b 8c 24 d8 00 00 00 	mov    ecx,DWORD PTR [esp+0xd8]
  4a35a8:	33 cc                	xor    ecx,esp
  4a35aa:	e8 52 da 3e 00       	call   0x891001
  4a35af:	8b e5                	mov    esp,ebp
  4a35b1:	5d                   	pop    ebp
  4a35b2:	c2 04 00             	ret    0x4
  4a35b5:	cc                   	int3
  4a35b6:	cc                   	int3
  4a35b7:	cc                   	int3
  4a35b8:	cc                   	int3
  4a35b9:	cc                   	int3
  4a35ba:	cc                   	int3
  4a35bb:	cc                   	int3
  4a35bc:	cc                   	int3
  4a35bd:	cc                   	int3
  4a35be:	cc                   	int3
  4a35bf:	cc                   	int3
  4a35c0:	55                   	push   ebp
  4a35c1:	8b ec                	mov    ebp,esp
  4a35c3:	51                   	push   ecx
  4a35c4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a35cb:	b8 06 00 00 00       	mov    eax,0x6
  4a35d0:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  4a35d4:	75 15                	jne    0x4a35eb
  4a35d6:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a35dc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a35de:	8b 52              	mov    edx,DWORD PTR [edx+0x10]
```

### wide→narrow with codepage and early failure `0x47F540`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0047f540 <.data+0x7e940>:
  47f540:	55                   	push   ebp
  47f541:	8b ec                	mov    ebp,esp
  47f543:	6a ff                	push   0xffffffff
  47f545:	68 38 78 91 00       	push   0x917838
  47f54a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47f550:	50                   	push   eax
  47f551:	83 ec 28             	sub    esp,0x28
  47f554:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47f559:	33 c5                	xor    eax,ebp
  47f55b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  47f55e:	53                   	push   ebx
  47f55f:	56                   	push   esi
  47f560:	50                   	push   eax
  47f561:	8d 45 f4             	lea    eax,[ebp-0xc]
  47f564:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47f56a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47f56d:	33 f6                	xor    esi,esi
  47f56f:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  47f572:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  47f575:	56                   	push   esi
  47f576:	3b c6                	cmp    eax,esi
  47f578:	75 1e                	jne    0x47f598
  47f57a:	c7 47 14 0f 00 00 00 	mov    DWORD PTR [edi+0x14],0xf
  47f581:	89 77 10             	mov    DWORD PTR [edi+0x10],esi
  47f584:	68 75 23 bf 00       	push   0xbf2375
  47f589:	8b cf                	mov    ecx,edi
  47f58b:	c6 07 00             	mov    BYTE PTR [edi],0x0
  47f58e:	e8 dd 34 f8 ff       	call   0x402a70
  47f593:	e9 c1 00 00 00       	jmp    0x47f659
  47f598:	56                   	push   esi
  47f599:	56                   	push   esi
  47f59a:	56                   	push   esi
  47f59b:	6a ff                	push   0xffffffff
  47f59d:	50                   	push   eax
  47f59e:	a1 08 a8 fb 00       	mov    eax,ds:0xfba808
  47f5a3:	56                   	push   esi
  47f5a4:	50                   	push   eax
  47f5a5:	ff 15 cc 21 bd 00    	call   DWORD PTR ds:0xbd21cc
  47f5ab:	8b d8                	mov    ebx,eax
  47f5ad:	3b de                	cmp    ebx,esi
  47f5af:	75 1f                	jne    0x47f5d0
  47f5b1:	56                   	push   esi
  47f5b2:	c7 47 14 0f 00 00 00 	mov    DWORD PTR [edi+0x14],0xf
  47f5b9:	89 77 10             	mov    DWORD PTR [edi+0x10],esi
  47f5bc:	68 75 23 bf 00       	push   0xbf2375
  47f5c1:	8b cf                	mov    ecx,edi
  47f5c3:	c6 07 00             	mov    BYTE PTR [edi],0x0
  47f5c6:	e8 a5 34 f8 ff       	call   0x402a70
  47f5cb:	e9 89 00 00 00       	jmp    0x47f659
  47f5d0:	53                   	push   ebx
  47f5d1:	e8 67 e6 3f 00       	call   0x87dc3d
  47f5d6:	8b 4d d0             	mov    ecx,DWORD PTR [ebp-0x30]
  47f5d9:	8b 15 08 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba808
  47f5df:	83 c4 04             	add    esp,0x4
  47f5e2:	6a 00                	push   0x0
  47f5e4:	6a 00                	push   0x0
  47f5e6:	53                   	push   ebx
  47f5e7:	8b f0                	mov    esi,eax
  47f5e9:	56                   	push   esi
  47f5ea:	6a ff                	push   0xffffffff
  47f5ec:	51                   	push   ecx
  47f5ed:	6a 00                	push   0x0
  47f5ef:	52                   	push   edx
  47f5f0:	c6 06 00             	mov    BYTE PTR [esi],0x0
  47f5f3:	ff 15 cc 21 bd 00    	call   DWORD PTR ds:0xbd21cc
  47f5f9:	33 db                	xor    ebx,ebx
  47f5fb:	8b c6                	mov    eax,esi
  47f5fd:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  47f604:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  47f607:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  47f60a:	8d 48 01             	lea    ecx,[eax+0x1]
  47f60d:	8d 49 00             	lea    ecx,[ecx+0x0]
  47f610:	8a 10                	mov    dl,BYTE PTR [eax]
  47f612:	40                   	inc    eax
  47f613:	84 d2                	test   dl,dl
  47f615:	75 f9                	jne    0x47f610
  47f617:	2b c1                	sub    eax,ecx
  47f619:	50                   	push   eax
  47f61a:	56                   	push   esi
  47f61b:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  47f61e:	e8 4d 34 f8 ff       	call   0x402a70
  47f623:	56                   	push   esi
  47f624:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47f627:	e8 11 27 41 00       	call   0x891d3d
  47f62c:	83 c4 04             	add    esp,0x4
  47f62f:	8d 45 d4             	lea    eax,[ebp-0x2c]
  47f632:	c7 47 14 0f 00 00 00 	mov    DWORD PTR [edi+0x14],0xf
  47f639:	89 5f 10             	mov    DWORD PTR [edi+0x10],ebx
  47f63c:	50                   	push   eax
  47f63d:	8b cf                	mov    ecx,edi
  47f63f:	c6 07 00             	mov    BYTE PTR [edi],0x0
  47f642:	e8 69 35 f8 ff       	call   0x402bb0
  47f647:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  47f64b:	72 0c                	jb     0x47f659
  47f64d:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  47f650:	51                   	push   ecx
  47f651:	e8 b6 1b 41 00       	call   0x89120c
  47f656:	83 c4 04             	add    esp,0x4
  47f659:	8b c7                	mov    eax,edi
  47f65b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47f65e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47f665:	59                   	pop    ecx
  47f666:	5e                   	pop    esi
  47f667:	5b                   	pop    ebx
  47f668:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  47f66b:	33 cd                	xor    ecx,ebp
  47f66d:	e8 8f 19 41 00       	call   0x891001
  47f672:	8b e5                	mov    esp,ebp
  47f674:	5d                   	pop    ebp
  47f675:	c3                   	ret
  47f676:	cc                   	int3
  47f677:	cc                   	int3
  47f678:	cc                   	int3
  47f679:	cc                   	int3
  47f67a:	cc                   	int3
  47f67b:	cc                   	int3
  47f67c:	cc                   	int3
  47f67d:	cc                   	int3
  47f67e:	cc                   	int3
  47f67f:	cc                   	int3
  47f680:	55                   	push   ebp
  47f681:	8b ec                	mov    ebp,esp
  47f683:	51                   	push   ecx
  47f684:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  47f688:	57                   	push   edi
  47f689:	8b f9                	mov    edi,ecx
  47f68b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47f692:	72 02                	jb     0x47f696
  47f694:	8b 00                	mov    eax,DWORD PTR [eax]
  47f696:	50                   	push   eax
  47f697:	e8 a4 fe ff ff       	call   0x47f540
  47f69c:	83 c4 04             	add    esp,0x4
  47f69f:	8b c7                	mov    eax,edi
  47f6a1:	5f                   	pop    edi
  47f6a2:	8b e5                	mov    esp,ebp
  47f6a4:	5d                   	pop    ebp
  47f6a5:	c3                   	ret
  47f6a6:	cc                   	int3
  47f6a7:	cc                   	int3
  47f6a8:	cc                   	int3
  47f6a9:	cc                   	int3
  47f6aa:	cc                   	int3
  47f6ab:	cc                   	int3
  47f6ac:	cc                   	int3
  47f6ad:	cc                   	int3
  47f6ae:	cc                   	int3
  47f6af:	cc                   	int3
  47f6b0:	55                   	push   ebp
  47f6b1:	8b ec                	mov    ebp,esp
  47f6b3:	6a ff                	push   0xffffffff
  47f6b5:	68 18 e5 91 00       	push   0x91e518
  47f6ba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
```

### digest widening `0x46E3C0`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0046e3c0 <.data+0x6d7c0>:
  46e3c0:	55                   	push   ebp
  46e3c1:	8b ec                	mov    ebp,esp
  46e3c3:	6a ff                	push   0xffffffff
  46e3c5:	68 78 e5 91 00       	push   0x91e578
  46e3ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  46e3d0:	50                   	push   eax
  46e3d1:	51                   	push   ecx
  46e3d2:	57                   	push   edi
  46e3d3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  46e3d8:	33 c5                	xor    eax,ebp
  46e3da:	50                   	push   eax
  46e3db:	8d 45 f4             	lea    eax,[ebp-0xc]
  46e3de:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  46e3e4:	33 c0                	xor    eax,eax
  46e3e6:	8b f9                	mov    edi,ecx
  46e3e8:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  46e3eb:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  46e3ee:	83 7d 1c 10          	cmp    DWORD PTR [ebp+0x1c],0x10
  46e3f2:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  46e3f5:	73 03                	jae    0x46e3fa
  46e3f7:	8d 45 08             	lea    eax,[ebp+0x8]
  46e3fa:	50                   	push   eax
  46e3fb:	e8 70 fe ff ff       	call   0x46e270
  46e400:	83 c4 04             	add    esp,0x4
  46e403:	83 7d 1c 10          	cmp    DWORD PTR [ebp+0x1c],0x10
  46e407:	72 0c                	jb     0x46e415
  46e409:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  46e40c:	50                   	push   eax
  46e40d:	e8 fa 2d 42 00       	call   0x89120c
  46e412:	83 c4 04             	add    esp,0x4
  46e415:	8b c7                	mov    eax,edi
  46e417:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  46e41a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  46e421:	59                   	pop    ecx
  46e422:	5f                   	pop    edi
  46e423:	8b e5                	mov    esp,ebp
  46e425:	5d                   	pop    ebp
  46e426:	c3                   	ret
  46e427:	cc                   	int3
  46e428:	cc                   	int3
  46e429:	cc                   	int3
  46e42a:	cc                   	int3
  46e42b:	cc                   	int3
  46e42c:	cc                   	int3
  46e42d:	cc                   	int3
  46e42e:	cc                   	int3
  46e42f:	cc                   	int3
  46e430:	55                   	push   ebp
  46e431:	8b ec                	mov    ebp,esp
  46e433:	6a ff                	push   0xffffffff
  46e435:	68 e5 8a 90 00       	push   0x908ae5
  46e43a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  46e440:	50                   	push   eax
  46e441:	51                   	push   ecx
  46e442:	56                   	push   esi
  46e443:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  46e448:	33 c5                	xor    eax,ebp
  46e44a:	50                   	push   eax
  46e44b:	8d 45 f4             	lea    eax,[ebp-0xc]
  46e44e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  46e454:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  46e45b:	a1 78 0d fc 00       	mov    eax,ds:0xfc0d78
  46e460:	8b 08                	mov    ecx,DWORD PTR [eax]
  46e462:	50                   	push   eax
  46e463:	51                   	push   ecx
  46e464:	8d 75 f0             	lea    esi,[ebp-0x10]
  46e467:	e8 c4 07 00 00       	call   0x46ec30
  46e46c:	a1 78 0d fc 00       	mov    eax,ds:0xfc0d78
  46e471:	50                   	push   eax
  46e472:	e8 95 2d 42 00       	call   0x89120c
  46e477:	83 c4 04             	add    esp,0x4
  46e47a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  46e47d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  46e484:	59                   	pop    ecx
  46e485:	5e                   	pop    esi
  46e486:	8b e5                	mov    esp,ebp
  46e488:	5d                   	pop    ebp
  46e489:	c3                   	ret
  46e48a:	cc                   	int3
  46e48b:	cc                   	int3
  46e48c:	cc                   	int3
  46e48d:	cc                   	int3
  46e48e:	cc                   	int3
  46e48f:	cc                   	int3
  46e490:	55                   	push   ebp
  46e491:	8b ec                	mov    ebp,esp
  46e493:	6a ff                	push   0xffffffff
  46e495:	68 65 b7 90 00       	push   0x90b765
  46e49a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  46e4a0:	50                   	push   eax
  46e4a1:	51                   	push   ecx
  46e4a2:	56                   	push   esi
  46e4a3:	57                   	push   edi
  46e4a4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  46e4a9:	33 c5                	xor    eax,ebp
  46e4ab:	50                   	push   eax
  46e4ac:	8d 45 f4             	lea    eax,[ebp-0xc]
  46e4af:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  46e4b5:	a1 84 0d fc 00       	mov    eax,ds:0xfc0d84
  46e4ba:	33 f6                	xor    esi,esi
  46e4bc:	3b c6                	cmp    eax,esi
  46e4be:	74 1e                	je     0x46e4de
  46e4c0:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  46e4c3:	8b 3d 88 0d fc 00    	mov    edi,DWORD PTR ds:0xfc0d88
  46e4c9:	51                   	push   ecx
  46e4ca:	e8 81 11 00 00       	call   0x46f650
  46e4cf:	8b 15 84 0d fc 00    	mov    edx,DWORD PTR ds:0xfc0d84
  46e4d5:	52                   	push   edx
  46e4d6:	e8 31 2d 42 00       	call   0x89120c
  46e4db:	83 c4 08             	add    esp,0x8
  46e4de:	89 35 84 0d fc 00    	mov    DWORD PTR ds:0xfc0d84,esi
  46e4e4:	89 35 88 0d fc 00    	mov    DWORD PTR ds:0xfc0d88,esi
  46e4ea:	89 35 8c 0d fc 00    	mov    DWORD PTR ds:0xfc0d8c,esi
  46e4f0:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  46e4f3:	a1 78 0d fc 00       	mov    eax,ds:0xfc0d78
  46e4f8:	8b 08                	mov    ecx,DWORD PTR [eax]
  46e4fa:	50                   	push   eax
  46e4fb:	51                   	push   ecx
  46e4fc:	8d 75 f0             	lea    esi,[ebp-0x10]
  46e4ff:	e8 2c 07 00 00       	call   0x46ec30
  46e504:	a1 78 0d fc 00       	mov    eax,ds:0xfc0d78
  46e509:	50                   	push   eax
  46e50a:	e8 fd 2c 42 00       	call   0x89120c
  46e50f:	83               	add    esp,0x4
```

### group cursor and 10-byte row `0x4C3080`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c3080 <.data+0xc2480>:
  4c3080:	55                   	push   ebp
  4c3081:	8b ec                	mov    ebp,esp
  4c3083:	83 e4 f8             	and    esp,0xfffffff8
  4c3086:	83 ec 24             	sub    esp,0x24
  4c3089:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c308e:	33 c4                	xor    eax,esp
  4c3090:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4c3094:	53                   	push   ebx
  4c3095:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4c3098:	56                   	push   esi
  4c3099:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  4c309f:	57                   	push   edi
  4c30a0:	83 c6 08             	add    esi,0x8
  4c30a3:	8b f9                	mov    edi,ecx
  4c30a5:	e8 96 11 00 00       	call   0x4c4240
  4c30aa:	85 db                	test   ebx,ebx
  4c30ac:	0f 84 98 00 00 00    	je     0x4c314a
  4c30b2:	89 5c 24 0c          	mov    DWORD PTR [esp+0xc],ebx
  4c30b6:	8b 15 54 1b fe 00    	mov    edx,DWORD PTR ds:0xfe1b54
  4c30bc:	8b df                	mov    ebx,edi
  4c30be:	0f b7 0b             	movzx  ecx,WORD PTR [ebx]
  4c30c1:	83 c7 03             	add    edi,0x3
  4c30c4:	e8 47 44 04 00       	call   0x507510
  4c30c9:	80 7b 02 00          	cmp    BYTE PTR [ebx+0x2],0x0
  4c30cd:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4c30d1:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  4c30d8:	00 
  4c30d9:	76 65                	jbe    0x4c3140
  4c30db:	eb 03                	jmp    0x4c30e0
  4c30dd:	8d 49 00             	lea    ecx,[ecx+0x0]
  4c30e0:	8b f7                	mov    esi,edi
  4c30e2:	0f b6 46 07          	movzx  eax,BYTE PTR [esi+0x7]
  4c30e6:	0f b6 4e 06          	movzx  ecx,BYTE PTR [esi+0x6]
  4c30ea:	0f b6 56 05          	movzx  edx,BYTE PTR [esi+0x5]
  4c30ee:	50                   	push   eax
  4c30ef:	0f b6 46 04          	movzx  eax,BYTE PTR [esi+0x4]
  4c30f3:	51                   	push   ecx
  4c30f4:	52                   	push   edx
  4c30f5:	50                   	push   eax
  4c30f6:	68 50 b0 bf 00       	push   0xbfb050
  4c30fb:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  4c30ff:	83 c7 0a             	add    edi,0xa
  4c3102:	e8 29 12 00 00       	call   0x4c4330
  4c3107:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  4c310b:	83 c4 14             	add    esp,0x14
  4c310e:	85 c9                	test   ecx,ecx
  4c3110:	74 1d                	je     0x4c312f
  4c3112:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4c3115:	8d 54 24 18          	lea    edx,[esp+0x18]
  4c3119:	52                   	push   edx
  4c311a:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  4c311e:	50                   	push   eax
  4c311f:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  4c3123:	50                   	push   eax
  4c3124:	a1 54 1b fe 00       	mov    eax,ds:0xfe1b54
  4c3129:	50                   	push   eax
  4c312a:	e8 e1 44 04 00       	call   0x507610
  4c312f:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4c3133:	0f b6 4b 02          	movzx  ecx,BYTE PTR [ebx+0x2]
  4c3137:	40                   	inc    eax
  4c3138:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4c313c:	3b c1                	cmp    eax,ecx
  4c313e:	72 a0                	jb     0x4c30e0
  4c3140:	ff 4c 24 0c          	dec    DWORD PTR [esp+0xc]
  4c3144:	0f 85 6c ff ff ff    	jne    0x4c30b6
  4c314a:	68 43 42 0f 00       	push   0xf4243
  4c314f:	e8 7c 79 0c 00       	call   0x58aad0
  4c3154:	8b 4c 24 30          	mov    ecx,DWORD PTR [esp+0x30]
  4c3158:	83 c4 04             	add    esp,0x4
  4c315b:	5f                   	pop    edi
  4c315c:	5e                   	pop    esi
  4c315d:	5b                   	pop    ebx
  4c315e:	33 cc                	xor    ecx,esp
  4c3160:	e8 9c de 3c 00       	call   0x891001
  4c3165:	8b e5                	mov    esp,ebp
  4c3167:	5d                   	pop    ebp
  4c3168:	c2 04 00             	ret    0x4
  4c316b:	cc                   	int3
  4c316c:	cc                   	int3
  4c316d:	cc                   	int3
  4c316e:	cc                   	int3
  4c316f:	cc                   	int3
```

### 0x13 result/error consumer and nearby helpers `0x4C37A0`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c37a0 <.data+0xc2ba0>:
  4c37a0:	55                   	push   ebp
  4c37a1:	8b ec                	mov    ebp,esp
  4c37a3:	6a ff                	push   0xffffffff
  4c37a5:	68 3c 07 94 00       	push   0x94073c
  4c37aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c37b0:	50                   	push   eax
  4c37b1:	81 ec 4c 04 00 00    	sub    esp,0x44c
  4c37b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c37bc:	33 c5                	xor    eax,ebp
  4c37be:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4c37c1:	53                   	push   ebx
  4c37c2:	56                   	push   esi
  4c37c3:	57                   	push   edi
  4c37c4:	50                   	push   eax
  4c37c5:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c37c8:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c37ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c37d1:	33 db                	xor    ebx,ebx
  4c37d3:	8d 46 20             	lea    eax,[esi+0x20]
  4c37d6:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c37dc:	89 8d b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],ecx
  4c37e2:	66 39 18             	cmp    WORD PTR [eax],bx
  4c37e5:	74 3a                	je     0x4c3821
  4c37e7:	8b 15 08 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba808
  4c37ed:	53                   	push   ebx
  4c37ee:	53                   	push   ebx
  4c37ef:	68 00 04 00 00       	push   0x400
  4c37f4:	8d 8d f0 fb ff ff    	lea    ecx,[ebp-0x410]
  4c37fa:	51                   	push   ecx
  4c37fb:	6a ff                	push   0xffffffff
  4c37fd:	50                   	push   eax
  4c37fe:	53                   	push   ebx
  4c37ff:	52                   	push   edx
  4c3800:	ff 15 cc 21 bd 00    	call   DWORD PTR ds:0xbd21cc
  4c3806:	6a 32                	push   0x32
  4c3808:	8d 85 f0 fb ff ff    	lea    eax,[ebp-0x410]
  4c380e:	50                   	push   eax
  4c380f:	68 97 00 00 00       	push   0x97
  4c3814:	68 00 a7 fb 00       	push   0xfba700
  4c3819:	e8 cd 20 3d 00       	call   0x8958eb
  4c381e:	83 c4 10             	add    esp,0x10
  4c3821:	8a 56 16             	mov    dl,BYTE PTR [esi+0x16]
  4c3824:	80 fa 05             	cmp    dl,0x5
  4c3827:	0f 85 1c 01 00 00    	jne    0x4c3949
  4c382d:	6a 34                	push   0x34
  4c382f:	e8 34 da 3c 00       	call   0x891268
  4c3834:	8b f8                	mov    edi,eax
  4c3836:	83 c4 04             	add    esp,0x4
  4c3839:	89 bd b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],edi
  4c383f:	33 c0                	xor    eax,eax
  4c3841:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4c3844:	3b f8                	cmp    edi,eax
  4c3846:	74 4a                	je     0x4c3892
  4c3848:	33 c9                	xor    ecx,ecx
  4c384a:	50                   	push   eax
  4c384b:	66 89 8d b8 fb ff ff 	mov    WORD PTR [ebp-0x448],cx
  4c3852:	68 fc d1 be 00       	push   0xbed1fc
  4c3857:	8d 8d b8 fb ff ff    	lea    ecx,[ebp-0x448]
  4c385d:	c7 85 cc fb ff ff 07 	mov    DWORD PTR [ebp-0x434],0x7
  4c3864:	00 00 00 
  4c3867:	89 85 c8 fb ff ff    	mov    DWORD PTR [ebp-0x438],eax
  4c386d:	e8 ee e8 f3 ff       	call   0x402160
  4c3872:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4c3876:	0f be 4e 16          	movsx  ecx,BYTE PTR [esi+0x16]
  4c387a:	8d 95 b8 fb ff ff    	lea    edx,[ebp-0x448]
  4c3880:	52                   	push   edx
  4c3881:	bb 01 00 00 00       	mov    ebx,0x1
  4c3886:	57                   	push   edi
  4c3887:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c388d:	e8 6e 06 29 00       	call   0x753f00
  4c3892:	50                   	push   eax
  4c3893:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  4c389a:	e8 b1 71 0c 00       	call   0x58aa50
  4c389f:	83 ce ff             	or     esi,0xffffffff
  4c38a2:	83 c4 04             	add    esp,0x4
  4c38a5:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c38a8:	f6 c3 01             	test   bl,0x1
  4c38ab:	74 35                	je     0x4c38e2
  4c38ad:	83 bd cc fb ff ff 08 	cmp    DWORD PTR [ebp-0x434],0x8
  4c38b4:	72 0f                	jb     0x4c38c5
  4c38b6:	8b 85 b8 fb ff ff    	mov    eax,DWORD PTR [ebp-0x448]
  4c38bc:	50                   	push   eax
  4c38bd:	e8 4a d9 3c 00       	call   0x89120c
  4c38c2:	83 c4 04             	add    esp,0x4
  4c38c5:	33 ff                	xor    edi,edi
  4c38c7:	33 c9                	xor    ecx,ecx
  4c38c9:	c7 85 cc fb ff ff 07 	mov    DWORD PTR [ebp-0x434],0x7
  4c38d0:	00 00 00 
  4c38d3:	89 bd c8 fb ff ff    	mov    DWORD PTR [ebp-0x438],edi
  4c38d9:	66 89 8d b8 fb ff ff 	mov    WORD PTR [ebp-0x448],cx
  4c38e0:	eb 02                	jmp    0x4c38e4
  4c38e2:	33 ff                	xor    edi,edi
  4c38e4:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4c38eb:	75 2e                	jne    0x4c391b
  4c38ed:	83 0d d0 ac fb 00 01 	or     DWORD PTR ds:0xfbacd0,0x1
  4c38f4:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  4c38fb:	89 3d d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,edi
  4c3901:	e8 fa 29 21 00       	call   0x6d6300
  4c3906:	68 70 d6 bc 00       	push   0xbcd670
  4c390b:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4c3910:	e8 05 ea 3c 00       	call   0x89231a
  4c3915:	83 c4 04             	add    esp,0x4
  4c3918:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c391b:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  4c3921:	3b cf                	cmp    ecx,edi
  4c3923:	74 08                	je     0x4c392d
  4c3925:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c3927:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4c392a:	57                   	push   edi
  4c392b:	ff d0                	call   eax
  4c392d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4c3933:	8b 11                	mov    edx,DWORD PTR [ecx]
  4c3935:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  4c3938:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  4c393e:	6a 01                	push   0x1
  4c3940:	6a 01                	push   0x1
  4c3942:	ff d0                	call   eax
  4c3944:	e9 10 02 00 00       	jmp    0x4c3b59
  4c3949:	84 d2                	test   dl,dl
  4c394b:	0f 85 df 00 00 00    	jne    0x4c3a30
  4c3951:	8d 7e 02             	lea    edi,[esi+0x2]
  4c3954:	8b c7                	mov    eax,edi
  4c3956:	8d 48 02             	lea    ecx,[eax+0x2]
  4c3959:	89 8d a8 fb ff ff    	mov    DWORD PTR [ebp-0x458],ecx
  4c395f:	90                   	nop
  4c3960:	66 8b 08             	mov    cx,WORD PTR [eax]
  4c3963:	83 c0 02             	add    eax,0x2
  4c3966:	66 85 c9             	test   cx,cx
  4c3969:	75 f5                	jne    0x4c3960
  4c396b:	2b 85 a8 fb ff ff    	sub    eax,DWORD PTR [ebp-0x458]
  4c3971:	d1 f8                	sar    eax,1
  4c3973:	0f 84 b7 00 00 00    	je     0x4c3a30
  4c3979:	8b 5e 18             	mov    ebx,DWORD PTR [esi+0x18]
  4c397c:	e8 1f 12 f4 ff       	call   0x404ba0
  4c3981:	89 98 e0 67 00 00    	mov    DWORD PTR [eax+0x67e0],ebx
  4c3987:	e8 14 12 f4 ff       	call   0x404ba0
  4c398c:	85 ff                	test   edi,edi
  4c398e:	74 13                	je     0x4c39a3
  4c3990:	6a 0a                	push   0xa
  4c3992:	57                   	push   edi
  4c3993:	05 e4 67 00 00       	add    eax,0x67e4
  4c3998:	6a 0b                	push   0xb
  4c399a:	50                   	push   eax
  4c399b:	e8 5e 06 3d 00       	call   0x893ffe
  4c39a0:	83 c4 10             	add    esp,0x10
  4c39a3:	0f b6 7e 17          	movzx  edi,BYTE PTR [esi+0x17]
  4c39a7:	e8 f4 11 f4 ff       	call   0x404ba0
  4c39ac:	89 b8 b4 68 00 00    	mov    DWORD PTR [eax+0x68b4],edi
  4c39b2:	8a 9e 90 00 00 00    	mov    bl,BYTE PTR [esi+0x90]
  4c39b8:	e8 e3 11 f4 ff       	call   0x404ba0
  4c39bd:	88 98 b0 68 00 00    	mov    BYTE PTR [eax+0x68b0],bl
  4c39c3:	8a 96 86 00 00 00    	mov    dl,BYTE PTR [esi+0x86]
  4c39c9:	8b 9e 8c 00 00 00    	mov    ebx,DWORD PTR [esi+0x8c]
  4c39cf:	88 95 b4 fb ff ff    	mov    BYTE PTR [ebp-0x44c],dl
  4c39d5:	e8 c6 11 f4 ff       	call   0x404ba0
  4c39da:	8b f8                	mov    edi,eax
  4c39dc:	8a 85 b4 fb ff ff    	mov    al,BYTE PTR [ebp-0x44c]
  4c39e2:	8d 8e 87 00 00 00    	lea    ecx,[esi+0x87]
  4c39e8:	51                   	push   ecx
  4c39e9:	8d 97 99 68 00 00    	lea    edx,[edi+0x6899]
  4c39ef:	6a 05                	push   0x5
  4c39f1:	52                   	push   edx
  4c39f2:	88 87 98 68 00 00    	mov    BYTE PTR [edi+0x6898],al
  4c39f8:	e8 5c 01 3d 00       	call   0x893b59
  4c39fd:	89 9f a0 68 00 00    	mov    DWORD PTR [edi+0x68a0],ebx
  4c3a03:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
  4c3a06:	83 c4 0c             	add    esp,0xc
  4c3a09:	50                   	push   eax
  4c3a0a:	8d 8e 92 00 00 00    	lea    ecx,[esi+0x92]
  4c3a10:	e8 6b f6 ff ff       	call   0x4c3080
  4c3a15:	80 be 90 00 00 00 00 	cmp    BYTE PTR [esi+0x90],0x0
  4c3a1c:	75 0b                	jne    0x4c3a29
  4c3a1e:	8b bd b0 fb ff ff    	mov    edi,DWORD PTR [ebp-0x450]
  4c3a24:	e8 47 f7 ff ff       	call   0x4c3170
  4c3a29:	33 c0                	xor    eax,eax
  4c3a2b:	e9 34 01 00 00       	jmp    0x4c3b64
  4c3a30:	0f be ca             	movsx  ecx,dl
  4c3a33:	51                   	push   ecx
  4c3a34:	68 e4 72 c0 00       	push   0xc072e4
  4c3a39:	e8 22 a1 22 00       	call   0x6edb60
  4c3a3e:	6a 34                	push   0x34
  4c3a40:	e8 23 d8 3c 00       	call   0x891268
  4c3a45:	8b f8                	mov    edi,eax
  4c3a47:	83 c4 0c             	add    esp,0xc
  4c3a4a:	89 bd b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],edi
  4c3a50:	33 c0                	xor    eax,eax
  4c3a52:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  4c3a59:	3b f8                	cmp    edi,eax
  4c3a5b:	74 4a                	je     0x4c3aa7
  4c3a5d:	50                   	push   eax
  4c3a5e:	33 d2                	xor    edx,edx
  4c3a60:	68 fc d1 be 00       	push   0xbed1fc
  4c3a65:	8d 8d d4 fb ff ff    	lea    ecx,[ebp-0x42c]
  4c3a6b:	c7 85 e8 fb ff ff 07 	mov    DWORD PTR [ebp-0x418],0x7
  4c3a72:	00 00 00 
  4c3a75:	89 85 e4 fb ff ff    	mov    DWORD PTR [ebp-0x41c],eax
  4c3a7b:	66 89 95 d4 fb ff ff 	mov    WORD PTR [ebp-0x42c],dx
  4c3a82:	e8 d9 e6 f3 ff       	call   0x402160
  4c3a87:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  4c3a8b:	0f be 4e 16          	movsx  ecx,BYTE PTR [esi+0x16]
  4c3a8f:	8d 85 d4 fb ff ff    	lea    eax,[ebp-0x42c]
  4c3a95:	50                   	push   eax
  4c3a96:	bb 02 00 00 00       	mov    ebx,0x2
  4c3a9b:	57                   	push   edi
  4c3a9c:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c3aa2:	e8 59 04 29 00       	call   0x753f00
  4c3aa7:	50                   	push   eax
  4c3aa8:	c7 45 fc 06 00 00 00 	mov    DWORD PTR [ebp-0x4],0x6
  4c3aaf:	e8 9c 6f 0c 00       	call   0x58aa50
  4c3ab4:	83 ce ff             	or     esi,0xffffffff
  4c3ab7:	83 c4 04             	add    esp,0x4
  4c3aba:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c3abd:	f6 c3 02             	test   bl,0x2
  4c3ac0:	74 35                	je     0x4c3af7
  4c3ac2:	83 bd e8 fb ff ff 08 	cmp    DWORD PTR [ebp-0x418],0x8
  4c3ac9:	72 0f                	jb     0x4c3ada
  4c3acb:	8b 8d d4 fb ff ff    	mov    ecx,DWORD PTR [ebp-0x42c]
  4c3ad1:	51                   	push   ecx
  4c3ad2:	e8 35 d7 3c 00       	call   0x89120c
  4c3ad7:	83 c4 04             	add    esp,0x4
  4c3ada:	33 ff                	xor    edi,edi
  4c3adc:	33 d2                	xor    edx,edx
  4c3ade:	c7 85 e8 fb ff ff 07 	mov    DWORD PTR [ebp-0x418],0x7
  4c3ae5:	00 00 00 
  4c3ae8:	89 bd e4 fb ff ff    	mov    DWORD PTR [ebp-0x41c],edi
  4c3aee:	66 89 95 d4 fb ff ff 	mov    WORD PTR [ebp-0x42c],dx
  4c3af5:	eb 02                	jmp    0x4c3af9
  4c3af7:	33 ff                	xor    edi,edi
  4c3af9:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4c3b00:	75 2e                	jne    0x4c3b30
  4c3b02:	83 0d d0 ac fb 00 01 	or     DWORD PTR ds:0xfbacd0,0x1
  4c3b09:	c7 45 fc 07 00 00 00 	mov    DWORD PTR [ebp-0x4],0x7
  4c3b10:	89 3d d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,edi
  4c3b16:	e8 e5 27 21 00       	call   0x6d6300
  4c3b1b:	68 70 d6 bc 00       	push   0xbcd670
  4c3b20:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4c3b25:	e8 f0 e7 3c 00       	call   0x89231a
  4c3b2a:	83 c4 04             	add    esp,0x4
  4c3b2d:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4c3b30:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  4c3b36:	3b cf                	cmp    ecx,edi
  4c3b38:	74 08                	je     0x4c3b42
  4c3b3a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c3b3c:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4c3b3f:	57                   	push   edi
  4c3b40:	ff d2                	call   edx
  4c3b42:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4c3b48:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c3b4a:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4c3b4d:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  4c3b53:	6a 01                	push   0x1
  4c3b55:	6a 01                	push   0x1
  4c3b57:	ff d2                	call   edx
  4c3b59:	b8 05 40 00 80       	mov    eax,0x80004005
  4c3b5e:	89 be 60 bf 00 00    	mov    DWORD PTR [esi+0xbf60],edi
  4c3b64:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c3b67:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c3b6e:	59                   	pop    ecx
  4c3b6f:	5f                   	pop    edi
  4c3b70:	5e                   	pop    esi
  4c3b71:	5b                   	pop    ebx
  4c3b72:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4c3b75:	33 cd                	xor    ecx,ebp
  4c3b77:	e8 85 d4 3c 00       	call   0x891001
  4c3b7c:	8b e5                	mov    esp,ebp
  4c3b7e:	5d                   	pop    ebp
  4c3b7f:	c2 0c 00             	ret    0xc
  4c3b82:	cc                   	int3
  4c3b83:	cc                   	int3
  4c3b84:	cc                   	int3
  4c3b85:	cc                   	int3
  4c3b86:	cc                   	int3
  4c3b87:	cc                   	int3
  4c3b88:	cc                   	int3
  4c3b89:	cc                   	int3
  4c3b8a:	cc                   	int3
  4c3b8b:	cc                   	int3
  4c3b8c:	cc                   	int3
  4c3b8d:	cc                   	int3
  4c3b8e:	cc                   	int3
  4c3b8f:	cc                   	int3
  4c3b90:	55                   	push   ebp
  4c3b91:	8b ec                	mov    ebp,esp
  4c3b93:	6a ff                	push   0xffffffff
  4c3b95:	68 2e e4 91 00       	push   0x91e42e
  4c3b9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c3ba0:	50                   	push   eax
  4c3ba1:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c3ba6:	33 c5                	xor    eax,ebp
  4c3ba8:	50                   	push   eax
  4c3ba9:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c3bac:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c3bb2:	b8 01 00 00 00       	mov    eax,0x1
  4c3bb7:	84 05 30 1b fe 00    	test   BYTE PTR ds:0xfe1b30,al
  4c3bbd:	75 26                	jne    0x4c3be5
  4c3bbf:	09 05 30 1b fe 00    	or     DWORD PTR ds:0xfe1b30,eax
  4c3bc5:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c3bcc:	e8 1f bf fb ff       	call   0x47faf0
  4c3bd1:	68 b0 ea bc 00       	push   0xbceab0
  4c3bd6:	e8 3f e7 3c 00       	call   0x89231a
  4c3bdb:	83 c4 04             	add    esp,0x4
  4c3bde:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c3be5:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c3be8:	50                   	push   eax
  4c3be9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c3bec:	68 34 1b fe 00       	push   0xfe1b34
  4c3bf1:	e8 ba bf fb ff       	call   0x47fbb0
  4c3bf6:	33 c0                	xor    eax,eax
  4c3bf8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c3bfb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c3c02:	59                   	pop    ecx
  4c3c03:	8b e5                	mov    esp,ebp
  4c3c05:	5d                   	pop    ebp
  4c3c06:	c2 0c 00             	ret    0xc
  4c3c09:	cc                   	int3
  4c3c0a:	cc                   	int3
  4c3c0b:	cc                   	int3
  4c3c0c:	cc                   	int3
  4c3c0d:	cc                   	int3
  4c3c0e:	cc                   	int3
  4c3c0f:	cc                   	int3
```

## 附錄 M — 提交後校驗欄位（研究原稿不預先虛構）

本檔原始 `Git blob SHA` 由 `git hash-object` / GitHub create_blob 計算後在提交回報填寫。研究 Commit 及 PR/台帳狀態以正式遠端讀回為準；本稿不在尚未推送時自稱 `SUBMITTED`/`ACCEPTED`。
