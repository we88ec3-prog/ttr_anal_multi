# E69 — T03／RR-0003：登入 E8 尾端逐 byte 定界、CP_ACP 轉換層分歧、0x13 群組邊界與選服非同步交接

> **2026-10-30／chatgpt-web roy／KR BIN-first 補充研究**。唯一技術分支 `extra/roy1`，不開新分支。RR-0003 在本輪開工時 **已由 T01 設為 `IN_REVIEW`**（既有 E69 前報告 blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`；T01 登記 SRC-0473 與局部 PARTIAL）。本補充不重設歷史狀態、不宣稱 T01 FULL-PASS／S00 ACCEPTED 或可玩驗收。
>
> **唯一原生來源**：`/mnt/data/Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本輪從實檔重新計算，GNU `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 提取入口（不執行／Patch 遊戲）；後附既有 T03 RR-0003 原稿完整定向反組譯片段，關鍵新位址重新比對 raw bytes。

## 1. 研究終點與新增結論矩陣

最新 RR-0003 的 `question`：bounded `0x00E8/0x000F` opaque fields / codepage、實際 `S2C 0x0013` status consumer、group/channel cursor/limits 和後續 handoff，保留官方後端未知。GAP-AUTH-0001 另要求 E8 尾端、source codepage、response fields/array bounds、result-to-connection transition，區分官方與新 Server 的決策政策。本輪不把全部主張重新標為 FULL-PASS。

| 面向 | 新補強／修正 | 原生範圍與證據類型 |
|---|---|---|
| E8 尾端 `+104..+109` | 在 `0x4A3360` 內沒有找到**直接初始化寫入**；正常的兩組 `_strcpy_s` 目的地各 51 bytes，終點在 `+103`，下一明確寫入落在 `+110..111`。此六 bytes 為局部 stack buffer 未明確賦值的區間，**不是已證官方固定欄位** | 第一手 stack pointer／field destinations／112B enqueue；局部函式有界，外部 alias/記憶體破壞不作不存在論證 |
| E8 `+110..111` | `[global 0xFB1318]+0xBF80` 讀入 WORD，`0x4A33C5` 寫入 payload 末端（必須考慮之前 `push eax` 導致 ESP 差 4） | 第一手 |
| F `+206..213` | `+206..209=0x00010001`、`+210..211=0x0034`、`+212..213=[global 0xFB1318]+0xBF80`（WORD）。與 E8 6B 未初始化區不能共用欄位假設 | 第一手；stack EBP-relative |
| 輸入密碼 source codepage | `0x47F540` 的 WideCharToMultiByte 使用 `FBA808`，`0x46E270` 的 MultiByteToWideChar 亦使用此 global；初始 global 位於 `.data` 零填充虛擬尾端，**非 RAW 檔案儲存的固定 int32** | 第一手；runtime 間接 writer 未完全排除 |
| E8 傳輸文字 codepage | `0x4A3360` 在 `0x4A3455,3475,34AA,34C8` 四處透過 `ESI=[IAT 0xBD21CC]` 呼叫 WideCharToMultiByte，這條 **digest 後文字輸出路徑直接 push codepage=0**，即 Win32 CP_ACP。不能籠統說整個 AUTH 每次 WinAPI 都是 `FBA808` | 第一手 E8 函式、IAT；不同環境 ACP 可能不同，非 UTF-8/固定 CP949 |
| 轉碼失敗 | `0x47F540` 第一輪探測結果 `0` 時走空字串建立／fallback；E8 builder 內四個本地 WCTMB 沒看到「回值=0 後直接禁止 enqueue」的明確分支，最終仍可達 `0x4A3505`。但例外／CRT invalid parameter／heap 失敗可能中斷，不能斷言必然送出有效 payload | 本體局部 CFG positive + exception/OS runtime unknown |
| S2C 0x13 | 登入 scene + lane2 才進 `0x4C37A0`；可選 `payload+0x20` 通知在 status 判斷之前轉碼；status 5 專用錯誤、status 0+非空 UTF-16 名稱進資料寫入與群組；其餘走錯誤／清理 | 第一手 |
| group/channel | `0x4C3080` 每 group 3B（LE16 group id + BYTE childCount）、每 child 10B；`row[8]` 控制是否加入，`row[9]` 透過 EDX 進 `0x507610`，不是可隨意強制為零的填充 byte | 第一手 reader + downstream 507610 的入口資料保存 |
| handoff | `status0` + valid name 後先更新多個 Client 欄位、發 `F4243` 本地事件；`payload[+90]==0` 再走 `0x4C3170` 寫 `+BD54=1`、`timeGetTime` 寫 `+BD58`、派 `F4241`。之後經 UI/record/Conn gate 才可能進 `0x66C090→0x4957C0`，**不是直接在 `0x13` 函式 call Connect** | 第一手局部；跨 socket 實際先後 unknown |

## 2. AUTH C2S 位元組布局：正面與反例

| payload range | mode 0x52 → 0x00E8（112 bytes） | mode 0x54/default → 0x000F（214 bytes） |
|---|---|---|
| `+0..1` | LE16 `E8 00` | LE16 `0F 00` |
| `+2..52` | `_strcpy_s(...,51,...)` narrow account field | `+2..+103` UTF16 51-unit slot |
| `+53..103` | narrow digest string field, capacity 51 | `+104..+205` UTF16 51-unit digest slot |
| `+104..109` | **六個沒有本函式明確賦值的 stack bytes** | `+206..209` DWORD `0x00010001` |
| `+110..111` | 來自 `[0xFB1318]+0xBF80` WORD | `+210..211` WORD `0x0034`；`+212..213` 來自同一 `+BF80` |

### 2.1 為何六個 bytes 不能視為固定零

`0x4A3360` 建立 stack frame `sub esp,0xE0`，保留 112B 本地 payload；取**完成前臨時 push 以外的同一 ESP 基準 S**，`0x4A33B0: mov word [esp+0x74],cx` 將 command 放在 `S+0x74`。接著 `0x4A33BC push eax` 使 ESP 變 `S−4`，`0x4A33C5: mov word [esp+0xE6],cx` 實際地址 = `S+0xE2`，即 packet `+0x6E(+110)`。本體 `0x4A34D6`／`0x4A34E9` 的 `_strcpy_s` 各限定 0x33 bytes，分別從 payload `+2`、`+0x35(+53)` 起，直到 `+0x67(+103)`；`0x4A34FC` 調用 enqueue 的長度硬編 `0x70`，指標回到 `S+0x74`。於 `S+0xDC..0xE1` 正是 `+104..109` 六 bytes；在我們核對的**直接 store**指令中找不到對這六 bytes 的寫入。函式內 security cookie 的相對位置另在 `S+0xE8` 左右，不是 tail6。

**性質限定**：這是編碼前的 stack 未明確初始化區間，不可從原始 PE 斷言這六 bytes 在任何執行時必為非零、隨機或一定外洩敏感資訊；間接 API、重疊 alias、例外路徑、初始化策略需 runtime trace 才能完整排除。最重要的可實作結論是 Server 不可將這六 bytes 當作官方常數／角色 ID／校驗值，亦不應依其任意值做安全認證。

### 2.2 精確的 Native snippet（本輪 raw VA 逐點核對）

```asm
4A33AB mov ecx,0xE8
4A33B0 mov WORD PTR [esp+0x74],cx      ; S+0x74 payload[0..1]
4A33B5 mov cx,WORD PTR [edx+0xBF80]   ; source from [0xFB1318]
4A33BC push eax                         ; ESP now S-4
4A33C5 mov WORD PTR [esp+0xE6],cx      ; (S-4)+E6=S+E2, payload[110..111]
4A34D3 push 0x33                        ; first 51-byte narrow slot
4A34D6 call 0x893B59
4A34E6 push 0x33                        ; second 51-byte narrow slot
4A34E9 call 0x893B59
4A34FC push 0x70                        ; local payload len 112
4A34FE lea eax,[esp+0x78]              ; send pointer S+0x74
4A3505 call edx                         ; network manager virtual+0x10
```

對照 wide `000F`：

```asm
4A31EC mov WORD PTR [ebp-0x13C],cx     ; LE16 000F
4A31F3 mov DWORD PTR [ebp-0x6E],0x10001
4A31FA mov DWORD PTR [ebp-0x6A],0x34
4A326C mov dx,WORD PTR [ecx+0xBF80]
4A327D mov WORD PTR [ebp-0x68],dx
4A327A push 0x33                        ; wide field capacity 51 UTF16 code units
4A32A0 push 0x33
4A32B6 push 0xD6                        ; len 214
4A32C4 call edx
```

**錯誤推論清單**：`E8+104..109==00*6` 無原生 store 佐證；`000F+210` 不是 E8+110；`send length 112` 不等於 TCP 包含 frame header 的 wire 長度。原版 Server 對這幾欄的後端檢查，仍屬官方未知。

## 3. Unicode/ANSI/codepage：同一 AUTH 內的兩個不同來源

原始 IAT `0xBD21CC` 對應 `WideCharToMultiByte`，`0xBD230C` 對應 `MultiByteToWideChar`。本輪直接確認：

```asm
47F59E mov eax,[0xFBA808]             ; runtime CodePage input
47F5A5 call dword ptr [0xBD21CC]     ; first probe
47F5AD cmp ebx,esi                    ; probe length == 0 ?
47F5AF jne 0x47F5D0
47F5B1 ...                            ; zero/failed -> construct empty fallback string
47F5D9 mov edx,[0xFBA808]
47F5F3 call dword ptr [0xBD21CC]     ; second conversion
46E2CA mov ecx,[0xFBA808]            ; narrow digest → wide
46E2D6 call dword ptr [0xBD230C]
46E31C mov edx,[0xFBA808]
46E335 call dword ptr [0xBD230C]
4A344E mov esi,[0xBD21CC]
4A3455 call esi                        ; E8 builder: stack CodePage=0
4A3475 call esi                        ; second CP=0 probe
4A34AA call esi                        ; CP=0 output
4A34C8 call esi                        ; CP=0 output
```

**E8 builder 中 cp0 的 positive evidence**：以 `0x4A343E: push ebx ×4`、`0x4A3442 push -1`、`0x4A3444 push esi`、`0x4A3445 push ebx`、`0x4A3454 push ebx` 及 `EBX=0` 核對傳給 stdcall 的 8 個參數；另外 `0x4A346C..4A3475`、`0x4A3497..4A34AA`、`0x4A34BB..4A34C8` 亦以 0 作 CodePage。只憑某函式呼叫 WideCharToMultiByte 不能把所有階段都假定讀 `FBA808`。

**PE 證據**：`.data VA=0xD61000`，raw size `0x22B800`、virtual size `0x2873D8`；`0xFBA808 - 0xD61000 = 0x259808`，**超出 raw size、位於 virtual zero-tail**。Windows loader image initial state 0，即 `CP_ACP`，但未知執行時是否有透過 alias 的 setter。逐 byte 掃描整個 `.text` 對 `08 A8 FB 00` 的 immediate operands 僅於 `0x40410E,0x404159,0x46E2CC,0x46E31E,0x47F59F,0x47F5DB,0x4C37E9` 命中 7 處，已核對各自是讀取；這不等於排除所有基址間接寫。原版 Client 在特定 Windows 主機 ACP 可能為韓文字集，但**原件沒有把每條輸入硬編成 CP949、UTF8**。

**轉碼例外**：`0x47F540` 的零返回分支會建立空 narrow 字串並返回給 caller；E8 建構函式沒有可見的 `if (WideCharToMultiByte()==0) return; ` 式局部分支，仍可能走到 `0x4A3505`。這不代表例外/分配失敗時真實 socket 永遠發送成功；也不能以此猜測 Server 如何驗證密碼。兩種 local builder 的正常返回路徑都呼叫 `0x733DD0` digest helper 及 `0x46E3C0` widening，僅能描述 Client hash/text 資料來源，不是官方帳密儲存演算法。

## 4. S2C 0x13 的實際 status、notice 與界限

`0x4C3220` login scene table 將 `0x0013→0x4C37A0`、`0x007A→0x4C3C10`；須符合 T02 decoded frame、lane2、active LOGIN scene 才可進 handler，不能把 `0x13` 當 frame marker。

`0x4C37D3` 首先檢查 `WCHAR[payload+0x20]`，若非空，於 **status 分支之前**以 `[FBA808]` 作 CodePage 調用 `WideCharToMultiByte`，輸出到 0x400-byte local stack buffer，再經本地文字呈現函式；該 API 回值未見顯式 gate，不能宣稱失敗 status 一定沒有任何 notice 副作用。直到 `0x4C3821` 才讀 `BYTE payload[+0x16]`，`0x4C3824 cmp dl,5` 專用錯誤。其餘先 `0x4C3949 test dl,dl`，若 status0，`0x4C3951 lea edi,[esi+2]` 對 UTF16 名稱逐 WCHAR 讀到終止 NUL，`0x4C3973` 若名稱空則走一般失敗；非空才會進 `0x4C3979` identity/update。

```asm
4C37D3 lea eax,[esi+0x20]
4C37E2 cmp WORD PTR [eax],bx
4C37E7 mov edx,[0xFBA808]
4C3800 call dword ptr [0xBD21CC]
4C3821 mov dl,[esi+0x16]
4C3824 cmp dl,5
4C3949 test dl,dl
4C3951 lea edi,[esi+2]
4C3960 mov cx,WORD PTR [eax]
4C3963 add eax,2
4C3966 test cx,cx
4C3969 jne 0x4C3960
4C3973 je 0x4C3A30                      ; empty-name error branch
4C3979 mov ebx,[esi+0x18]
4C3981 mov [Client+0x67E0],ebx
4C39A3 movzx edi,BYTE [esi+0x17]
4C39AC mov [Client+0x68B4],edi
4C39B2 mov bl,BYTE [esi+0x90]
4C39BD mov [Client+0x68B0],bl
4C39C3 mov dl,BYTE [esi+0x86]
4C39C9 mov ebx,[esi+0x8C]
4C39F2 mov [Client+0x6898],al
4C39FD mov [Client+0x68A0],ebx
4C3A03 mov eax,[esi+0x1C]             ; group count
4C3A09 push eax
4C3A0A lea ecx,[esi+0x92]             ; group cursor
4C3A10 call 0x4C3080
4C3A15 cmp BYTE [esi+0x90],0
4C3A24 call 0x4C3170                  ; only when +90==0
```

**名稱無界限風險**：`0x4C3960..4C3969` 是以 NUL 為停條件的 loop，沒有在本地循環內檢查輸入 payload 的結尾；`0x4C37A0` 也在解包後直接讀固定高 offset 而沒有一個全域 min-length guard。由 T02 成功解包（最多 0x1000 payload）不自動保證上層名稱、notice 或陣列的分支讀取安全。合成 Server 的工程測試必須分正常非空/空名/缺 NUL/短包及 status5 分支；不能誤說 Client 本體已逐欄驗證。

## 5. Group/channel：兩個命令不能共用 layout

`0x4C3080` 接受 `ECX=groupCursor` 和 `stack[+8]=groupCount`；起始先 `0x4C4240` reset/clear 現有群組；`groupCount==0` 直接跳到 `0x4C314A`，但**仍派 `F4243` 本地事件**。非零對每筆：

```cpp
for (uint32_t i=0; i<groupCount; ++i) {
    uint16_t group_id = u16(cursor);      // 0x4C30BE
    uint8_t child_count = cursor[2];      // 0x4C30C9 / 0x4C3133
    cursor += 3;
    register_group(group_id);            // 0x507510
    for (uint32_t j=0; j<child_count; ++j) {
        uint8_t* row=cursor;
        string ipv4=fmt("%d.%d.%d.%d",row[4],row[5],row[6],row[7]);
        cursor += 10;                   // 0x4C30FF
        if (row[8] != 0) {
            // u16(row+0), row[9] in EDX, group/host object to 0x507610
            append_row(...);            // 0x507610, callback further formats records
        }
    }
}
dispatch_local_event(0xF4243);
```

這是按**宣告數量**推進，無本地每 row 與剩餘 payload size 的比較。欲構造 **自洽合成** payload，`0x13` 在 status0+非空名後其 groupCount 讀 `DWORD[+0x1C]`、第一筆游標 `+0x92`，最低資料 extent 是：
`L13 = 0x92 + Σ_i(3 + 10×childCount_i)`；`0x7A` 獨立 handler `0x4C3C10` 用 `DWORD[+2]`、游標 `+6`，相應 `L7A = 6 + Σ_i(3 + 10×childCount_i)`。這僅是 Server producer 的保守內容完整性推導，不是原版 Server 送出的具體清單。空清單：0x13 的解析分支仍可能要求前置狀態欄位存在；不能只傳 2B opcode 宣稱合法。

**下游新追溯**：`0x507610` 入口從 stack 取 row item、group object、已格式化 host，並把 EDX 來源的 `row[9]` 保存於自身 `[ebp-0x68]`；group id 和 row id 還被組成複合索引作查找、資料展示。此證據足以否定「row[9] 是無用 padding」的預設，但其對原版 Server 的正式頻道策略、端點身份及角色權威仍未知。另 `row[2..3]` 本輪未找到可靠業務命名，禁止視作零。

## 6. AUTH 結果→選服 handoff 的實際偏序及不成立的假說

`0x4C3A10` 處理完清單後，`0x4C3A15` 檢查 `payload[+0x90]==0`，此時 `0x4C3170`：

- 對全域 `0xFBACD0/0xFBACD4` 懶初始化及通知 method；
- `0x4C31E4` 寫 `Client+0xBD54=1`，`0x4C31EE` 呼叫 `timeGetTime`，`0x4C31F9` 保存 `Client+0xBD58`；
- `0x4C31F4` 以 `0xF4241` 發出**本地 UI/event**，而非網路 opcode。

後續 UI 選擇與連線路徑另在 `0x66C090` 取得 UI record 的兩個有限值/無效 -1 預設，向 `0x5078C0/0x507750` 查 mapping，檢查 `0xF94294`、結果指標和連線條件；滿足時 `0x66C1A7 call 0x4957C0`。因此 **`S2C0x13 status0→必定立即連 key0/key2` 不是已證結論**。同理原版跨 socket 送包順序必須由原版 Server trace、實機事件與 Conn owner 追查，不能拿 UI 事件序號 `0xF4241` 當 wire。

## 7. 對 S00 Server 設計與 T01 審核的具體交付

| 可供相容 Server 消費的 Client 有界需求 | 不可僭稱的官方 Server 政策 |
|---|---|
| 尊重 mode 對應的 C2S `E8/000F`、固定 payload 幾何；相容傳輸還須 T02 framing | 密碼資料庫 hash/加鹽、官方帳密法、固定 Server 先後 |
| 以實際位元組處理 E8 未初始化六-byte 區，不將其強制解讀為服務端必需的可信憑證 | 不宣稱六 bytes 恒等零／恒等隨機或規定其官方語意 |
| Windows ACP 的本地文字轉換有兩種 call 層；先使用正確 bytes，不把任何一條寫死 CP949／UTF8 | 不宣稱所有 Windows 的 ACP 相同 |
| `S2C 0x13` 的 status0 + 非空 UTF16 名稱才進 success identity/group；status5 特殊錯誤，其他拒絕 | 不自行編造所有非零結果 enum |
| groupCount/childCount 需要能完整遍歷的 3+10n 資料，Server 應保守校驗 NUL 長度與 frame 上限 | 不把安全工程要求寫成原 Client 已具備的逐項 bounds check |
| `S2C 0x7A` 的 count/cursor 與 `0x13` 不同；UI/Conn handoff 有更多 gates | 不將正常登入變成無條件 key 切線 |

**Client 尚待逆向**：E8 tail6 可能的間接寫入或 stack 生命週期（本輪可證「無本函式直接賦值」，不能全域 negative）；`FBA808` runtime alias setter；所有 CRT/heap 失敗與 exception unwind 是否仍呼叫 queue；上游任何完整輸入長度 validator；`0x507610` 各業務欄位的完整來源。
**Server 待開發**：認證資料庫及結果碼/令牌政策、角色擁有權、頻道權威、拒絕／重試策略，全部應由 S00 政策或 ADR 明示而非稱官方。
**跨功能待整合**：T02 Conn/queue/framing 已有 RR-0001/0004/0005/0007 有界證據；T03 RR-0002 的選角回覆另受 BLOCKED；T01 對舊 RR3 source 只標 PARTIAL 審核，不可自行覆蓋。
**待遊玩驗證**：不同 Windows codepage 與失敗輸入、C2S E8 尾端真實 WSASend 佇列 dump、0x13 status0/name/rows 合成 Server 觸發 UI/實際切線；合成不是原版 Server trace。

## 8. 確實執行的驗證

本輪實際以獨立 PE section parser 載入原始 `Tartaros.bin`（不是盲用 VA−0x400C00 讀 .data），自 `MZ/PE32` section header 判定四個 section 的 VMA、raw/virtual size，針對真正指令位址及從寄存器傳值取得 27 項靜態斷言，結果**27/27 PASS**。包含 mode dispatch E8/F 直接 callsites、兩種構造長度與 tail、4 個 WinAPI call、FBA808 7 個 immediate xref、response status/notice/count、group 3/10 byte geometry、兩個不同 group layout、handoff、本地數學向量。此為 self-audit，不代表 T01 FULL-PASS，也非 Client runtime。

重現：`python 20261030-chatgpt-web-roy-E69-RR0003-verify.py Tartaros.bin`。原測試檔應與本報告同時保留在 `extra/roy1:kr-extra-roy/`；其 hash 請以 GitHub push 後實際 blob 為準。

## 9. 舊原稿溯源、T01 退回與風險等級

- 原 E69 前 E69-previous RR3: `main:kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md`，blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`，1463 行，T01 已收 `SRC-0473/CLM-AUTH-0003..0005` PARTIAL、RR3 `IN_REVIEW`，不修改原稿。
- T03 另有 `T01-RETURN-T03-006-LAYOUT-001 — NEEDS_FIX`，是另一舊原生驗收退回，使用者本次明確指定 RR3 故本批延後處理；不自稱已解。
- E8 之前有 `kr/evidence/602d11...` 及 T02 E60/E56 等部分函式資料，現只增加新的 stack/codepage 分流與下游連結，不移動其它 task 主責。
- 核對原版 Client ≠ 原版 Server 政策，也不等於可玩 Server；本補充提交後由 **T01/RR reviewer 決定是否足夠 FULL-PASS／NEEDS_REVISION，再由 S00 決定 RR ACCEPTED**。研究者不自行改 RR3 從 IN_REVIEW 到 ACCEPTED。

## 附錄 A — 相關原始指令的來源保全（沿用舊 1463 行原稿，關鍵位址於本次 BIN 重新核對）

下列僅為 **第一手 disassembly 的可讀證據節錄**，不是新的命名/源碼。E69 實際新事實以上面 section 與本輪 27 個 byte assertions 為準。正式引用時請將相同原版 raw SHA 加入 T01 bounded claim 的出處。


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


---

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


---

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


---

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


---

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


**E69 收尾**：RR-0003 新的 Client 靜態疑問已獲正向 bounded local 說明，原版 Server policy/真實時序及執行環境依然 UNKNOWN；技術補充只推 `extra/roy1`，既有正式 `IN_REVIEW` 審核流程不由研究者改動。
