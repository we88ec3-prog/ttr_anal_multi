# T03-B：W05～W08 KR 登入認證 C→S／S→C 靜態原生閉合與未知界線

> 研究者：chatgpt-web roy；2026-10-31 18:24:06（Asia/Taipei）；工作分支 `t03/roy/chatgpt-web`；KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；KR `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。兩個原件本次由本機唯讀重新計算；**未執行、附加、修補 Client 或與原版 Server 交談**。本稿為 B 工作包的 Client 靜態研究閉合，不等於原版 Server 完整協定、RR-0003 ACCEPTED、T01 FULL-PASS、SPEC STABLE 或可玩驗收。

## 0. 工作範圍、來源品質與停止條件

這份完整原稿回答工作規劃 T03-W05、W06、W07、W08。正式 RR-0003（KR／T03／GAP-AUTH-0001）在主線唯一台帳 `research/requests/index.json` 目前為 `IN_REVIEW`，已提交原稿 `kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md`，blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`。本稿用第一手原始 BIN 定向複核與補查，**不重新提交或變更 RR-0003 的正式狀態**，不修改 T01/S00 的來源品質評語。本輪復用 E69（blob `98546ce73206e2b8f6fede78d83923af7a76cf5b`）、T02 E56（blob `843889349bb58209c02221e720800f0e9e3ff9d8`）、T02 E60（blob `2ca02f3870d79d3217abf39b8651c43226eb77d6`）已存在的有界研究，僅對 B 所需的機器碼作自己驗證。

目標分三層：① Client 何時產生哪一種**本地 application payload／queue**；② 有效 LOGIN scene 在收到相應 application message 時對狀態、群組及 UI 做什麼；③ 哪些內容是 Client **無法從原始 BIN 單獨證明**的原版 Server 封包配對、前後次序和策略。不要把 ①② 拼成③。停止於 Client 相關入口、關鍵分支、payload writer/consumer、local event 與跨 T02 連線交界均已實證，且剩餘未知可具體分流；即使有重要發現也不能用它填上缺失的 Server 事實。

### 0.1 PE、來源與可重跑驗證

| PE section | VA | raw | virtual / raw size |
|---|---:|---:|---:|
| .text | `0x00401000` | `0x00000400` | `0x7D01F0 / 0x7D0200` |
| .rdata | `0x00BD2000` | `0x007D0600` | `0x18E07C / 0x18E200` |
| .data | `0x00D61000` | `0x0095E800` | `0x2873D8 / 0x22B800` |

本輪實測 PE32 i386、image-base `0x400000`。`.text` 指令 `raw=VA-0x400C00`，`.rdata` 指標 `raw=VA-0x401A00`；對 `FBA808` 所在虛擬零填充區不能拿不存在的 raw byte 當初始化。用 GNU objdump 指定完整函式入口反組譯，並於實體 BIN 以 [唯讀驗證器](./20261031-182406-chatgpt-web-roy-T03-B-verify.py) **64 個精確指令起點**、vtable 指標、`FBA808` 七個直接 displacement、PE sections、group 算術確認全部通過。檢查的是指定原生位址及靜態資料流；不對每個間接別名、runtime 或 Server 封包作全稱保證。

## 1. W05 — 認證模式來源、函式分派與 C→S 本地 payload

### 1.1 正向上游：此物件模式的來源，不是固定 launcher 決策

**新補強的正向物件來源**：`0x006D6300` 成立的 allocation 成功路徑，`6D6321 c7 00 1c b0 bf 00` 安裝 vtable `0xBFB01C`，且 `6D6340 c7 40 08 52 00 00 00` 將物件 `+0x08` 初始化為 `0x52`。在 `.rdata` 的 `0xBFB04C`（`BFB01C+0x30`）有完整 DWORD `0x00440790`，即 vtable-style 的第 12 個 DWORD 入口。`0x440793 mov eax,[ecx+8]` 明確讀取**同一型別方法所用的 mode 欄位**。正向能說「此建構函式產生的物件在首次未被改寫時，mode 初值為0x52」；**不能**說任何 launcher 啟動/帳戶輸入永遠走 E8，或完全排除由 callback、alias、另一初始化路徑改成 `0x54`。關於 `6D6300` 的 GUI/連線生命週期，亦不可只憑類別或 mode 52 命名。

此輪做過`.text` 直接 `E8 rel32` 偵測：`0x440790` 無直呼候選、而 `0x4A3360`／`0x4A31B0` 有 `0x440790` 內直接呼叫者；**沒有直接 call 不是沒有間接執行**，反而與此 vtable 入口相符。Object mode 其他 writer 和特定 launcher 的來源還須完整間接 callgraph 或 runtime 才能定論，保留 Client 未知。

```asm
6D6321 C7 00 1C B0 BF 00      mov dword ptr [eax],0xBFB01C
6D6340 C7 40 08 52 00 00 00   mov dword ptr [eax+8],0x52
.rdata BFB04C: 90 07 44 00     ; DWORD = 0x440790，vtable+0x30
440793 8B 41 08               mov eax,[ecx+8]
440796 83 F8 52               cmp eax,0x52
4407C2 E8 99 2B 06 00         call 0x4A3360  ; mode52
4407CB 83 F8 54               cmp eax,0x54
4407F7 E8 B4 29 06 00         call 0x4A31B0  ; mode54
440822 E8 89 29 06 00         call 0x4A31B0  ; fallback(other)
```

判斷 `0x52` 的分支會測試並更新 `0xFB1314` bit0 與局部初始化`0x89231A`；`0x54`／其他亦有其分支。這是目前可見的局部模式路徑，不是傳輸層 `Conn+A02C` 的編碼模式，也不是 S2C status 值。

### 1.2 兩個 application payload 的欄位與 queue（raw≠TCP）

| 路徑 | Native builder / evidence | application payload | slot | 已證 byte 來源 |
|---|---|---:|---:|---|
| mode=`0x52` | `0x4A3360`；`4A33AB b9 e8…`、`4A33B0`、`4A34FC 6a70`、`4A3505 ff d2` | **112B** | 1 | LE16 `00E8`；`+2..52` 窄字串/51B，`+53..103` 窄摘要/51B，`+104..109` opaque 六位元組，`+110..111` 來源 `[FB1318]+BF80` WORD |
| mode=`0x54` 或其他 | `0x4A31B0`；`4A31E3 b9 0f…`、`4A31EC`、`4A31F3`、`4A31FA`、`4A32B6 68d600…`、`4A32C4 ff d2` | **214B** | 1 | LE16 `000F`；`+2..103` UTF-16LE/51 WCHAR 容量，`+104..205` UTF-16LE/51 WCHAR 容量，`+206..209=0x00010001`，`+210..211=0x0034`，`+212..213` 來源 `[FB1318]+BF80` WORD |

`0x4A3360` 的局部 buffer 在其方法內以 112B 送到 `[FBA854] manager vtable+0x10`，`0x4A31B0` 類似 214B。這是 **local enqueue attempt**：到 T02 的 queue／send pump／framing／WSASend 還有前提。不能把長度112/214稱為完整 TCP frame，不能用 manager 返回值聲稱 Server 收到，不能由 mode 推回 original Server 的回覆 opcode。

```asm
4A33AB B9 E8 00 00 00          mov ecx,0xE8
4A33B0 66 89 4C 24 74          mov [esp+0x74],cx       ; WORD E8
4A33B5 66 8B 8A 80 BF 00 00   mov cx,[edx+0xBF80]    ; FB1318-based
4A33C5 66 89 8C 24 E6 00 00 00 mov [esp+0xE6],cx    ; tail WORD, stack-adjusted
4A34D3 6A 33                   push 0x33               ; narrow capacity 51
4A34E6 6A 33                   push 0x33
4A34FC 6A 70                   push 0x70               ; length 112
4A3505 FF D2                   call edx                ; manager virtual send
4A31EC 66 89 8D C4 FE FF FF   mov [ebp-0x13C],cx     ; WORD 000F
4A31F3 C7 45 92 01 00 01 00   mov dword [ebp-0x6E],0x10001
4A31FA C7 45 96 34 00 00 00   mov dword [ebp-0x6A],0x34
4A32B6 68 D6 00 00 00         push 0xD6               ; length 214
4A32C4 FF D2                  call edx                ; manager virtual send
```

`_strcpy_s` 或 `_wcscpy_s` 的容量不是官方帳號/密碼允許長度、也不是安全填零整個 packet 的證據。進一步追 `0x47F540`、`0x46E3C0`、`0x733DD0` 來源是格式與轉碼/摘要文字鏈；沒有可用的原版 Server 實際認證政策或公認為必然成功的 request–reply 配對。

## 2. W06 — E8 六位元組、CP_ACP 與 writer／alias 限界

### 2.1 `E8+104..109` 不是已證定值

相對於 `0x4A3360` 後段送出 base，已找到兩個各 51-byte 目的地及尾端 WORD。這兩個字串槽結束於 `+103`，下一條明確填寫是 `+110..111`。`+104..109` 在本函式被查驗的直接 store／copy 指令中**沒有獨立顯式初始化 writer**。注意：
- stack allocation `sub esp,E0` 不是 `memset`；不能用「區域變數被配置」當作六位元組全 0；
- 目的地指標、指令時的 `ESP` 會因 `push` 改變；`0x4A33C5` 的 tail 目的地換算必須計算此前的 push；
- 只證「沒有找到這個函式的直接初始化」，不證間接 write/別名、未定義資料、每次 runtime 值或 Server 語意；
- 合成 Server 不能硬編六個為0、nonce、token、版本或 salt；如需可重現的實際值，需在取得授權後以同版 local memory/wire capture 補證。

`0x4A3454`、`0x4A3475`、`0x4A34AA`、`0x4A34C8` 四處呼叫 IAT `0xBD21CC`（`WideCharToMultiByte`），其參數中 CodePage 為常數0（CP_ACP）。其中轉碼返回零後未見對所有路徑的顯式「直接禁止 manager enqueue」分支；但 CRT invalid-parameter／異常／資源失敗可能另中止流程，不能宣稱失敗時一定會送出有效 E8。

### 2.2 兩條 codepage 路徑分離（核對 .text 全直接 absolute xref）

| 層次 | Dataflow | 可證／不可證 |
|---|---|---|
| 登入前輸入轉換與相關 helper | `0x47F540`、`0x46E270` 相關 Win32 MultiByte/WideChar API 使用 `[0xFBA808]` | `FBA808` 所在 .data virtual-zero tail **初始**為0（CP_ACP），不能以零填充當固定 runtime 配置 |
| E8 後段輸出文字 | `0x4A3360` 內四次 `WideCharToMultiByte` 傳入 CodePage=0 | 直接 CP_ACP，並非逐次從 `FBA808` 讀取 |
| 真實宿主轉碼 | Windows ACP + 執行中可能的 alias writer | 不可宣稱固定 CP949／UTF-8、不能保證任意字元的產物一致 |

對整個 `.text raw [0x400,0x7D0600)` 的 DWORD 位元組 `08 A8 FB 00` 搜尋，共 **7 處立即位址引用**，對應的 VA **`40410E`、`404159`、`46E2CC`、`46E31E`、`47F59F`、`47F5DB`、`4C37E9`**。各 site 鄰近指令為讀取用的 `mov`/push-data，不提供直接 absolute write；此負證僅限精確 direct displacement，**不排除計算後 pointer、register alias、外部 setter**。`FBA808−D61000=0x259808`，大於 .data raw size `0x22B800`，而小於 virtual `0x2873D8`。

可驗證的新 Server 需求：輸入編碼必須跟指定 KR Client+主機 locale 的實際文字結果相容，Server 需要明確自訂保存和驗證政策；不能從 Client 具 MD5 文字鏈推斷官方內部資料庫、加鹽與 Token 規則。

## 3. W07 — LOGIN S→C 0x13／0x7A 解析、狀態與 UI 副作用

### 3.1 必須先經 T02 分派及 LOGIN scene

T02 E60 已保存 `lane=2`、`0x4930E0` business dispatch、first-level default `0x4B7EC0` 與有效 active LOGIN scene 的兩層 callback 邊界。本輪獨立查 `0x4C3220`，其登入 scene 二級 table base `+0x5EAC`、stride8：
- `0x4C323B` 將 `0x4C37A0` 裝到 `+0x5F44 = +0x5EAC+0x13×8`；
- `0x4C325B` 將 `0x4C3C10` 裝到 `+0x627C = +0x5EAC+0x7A×8`。

因此 0x13、0x7A 是**LOGIN scene 可達 application opcode**，不是 framing marker。另一個 scene 不必具相同 handler；這不證真實 Server 第一次先下哪一包。

### 3.2 `0x4C37A0` 先處理 notice，再讀 status

```asm
4C37D3 8D 46 20                  lea eax,[esi+0x20]      ; optional UTF16 notice
4C37E7 8B 15 08 A8 FB 00         mov edx,[FBA808]
4C3800 FF 15 CC 21 BD 00         call [BD21CC]           ; notice conversion
4C3821 8A 56 16                  mov dl,[esi+0x16]       ; status
4C3824 80 FA 05                  cmp dl,5
4C3949 84 D2                     test dl,dl
4C3951 8D 7E 02                  lea edi,[esi+2]         ; account name
4C3960 66 8B 08                  mov cx,[eax]            ; NUL probe, no local end ptr
4C3973 0F 84 B7 00 00 00         je 0x4C3A30            ; empty-name generic error
4C3979 8B 5E 18                  mov ebx,[esi+0x18]      ; identity DWORD
4C39A3 0F B6 7E 17               movzx edi,[esi+0x17]
4C39B2 8A 9E 90 00 00 00         mov bl,[esi+0x90]
4C39C3 8A 96 86 00 00 00         mov dl,[esi+0x86]
4C39FD 89 9F A0 68 00 00         mov [edi+0x68A0],ebx
4C3A03 8B 46 1C                  mov eax,[esi+0x1C]     ; groupCount
4C3A0A 8D 8E 92 00 00 00         lea ecx,[esi+0x92]    ; group cursor
4C3A10 E8 6B F6 FF FF            call 0x4C3080
4C3A15 80 BE 90 00 00 00 00      cmp byte [esi+0x90],0
4C3A24 E8 47 F7 FF FF            call 0x4C3170         ; ONLY if +90==0
```

| 玩家收到的資料 | 原生 Client 分支 | Local effect（有條件） | 不可擅認 |
|---|---|---|---|
| `status=5` | `4C3824`→`4C382D`→錯誤資源/通知、manager vtable+0x20 | `Client+BF60=0`、return `0x80004005` | status 5 官方名稱/伺服器原因未知 |
| `status!=0,5` | `4C3949`→`4C3A30` | 一般錯誤通知/記錄/清理、`BF60=0` | 其他值與 Server 錯誤 enum 未證 |
| `status=0` 但 UTF-16 name 為空 | `4C3951..3973` 走一般錯誤 | 不寫正常身份與群組 | status0 單獨不保證登入成功 |
| `status=0` 且 name 非空且可被正常讀取 | `4C3979..4C3A29` | identity/session 本地欄位更新→`4C3080` 列表→`F4243`；`+90==0` 再觸發 `4C3170` | 不代表所有 socket 已建立或原版 Server 已授權進世界 |

**先處理的可選 notice**（`payload+0x20` WCHAR 非0）在任何 status 的本地副作用之前就可能執行。失敗不保證畫面沒有文字更新。名稱採逐 WCHAR 直到 NUL，該 handler 局部沒有逐字測上層 payload end；若無 NUL，不能直接拿此原始程式宣稱會安全拒絕，亦不能只靠靜態資料宣稱必 crash。

| S2C 0x13 application offset | native reader / writer | 能說／不能說 |
|---|---|---|
| +0..1 | valid scene 二級 handler 的 LE16 app opcode 0x13 | 與 transport marker、C2S opcode 分開 |
| +2 | UTF16LE NUL-terminated name，copy 至 Client+0x67E4（容量11，最多10 units） | 官方帳號名稱政策 UNKNOWN |
| +0x16 | status byte；5／0／其它分支 | 完整 enum/Server 政策 UNKNOWN |
| +0x17 | BYTE → Client+0x68B4 | 業務身份意義 UNKNOWN |
| +0x18 | DWORD → Client+0x67E0 | 業務權限/ID意義 UNKNOWN |
| +0x1C | DWORD group count → `4C3080` | 缺上游 per-row total-length guard |
| +0x20 | 非零可選 UTF16 notice，**在 status 前**處理 | 實際文案/長度 UNKNOWN |
| +0x86 | BYTE → Client+0x6898 | 不是已證 Server ticket type |
| +0x87 | narrow 字串，`strcpy_s` 目標容量5 → Client+0x6899 | 不是已證 token policy |
| +0x8C | DWORD → Client+0x68A0 | 不是已證 nonce |
| +0x90 | BYTE → Client+0x68B0；0 才另 call `4C3170` | 不是已證 Server auth 全流程結果 |
| +0x92 | group cursor（不是 header pointer） | 與 0x7A 的 +6 不可互換 |

### 3.3 群組逐列和獨立 0x7A

```asm
4C30AA 85 DB                test ebx,ebx              ; groupCount=0 bypass loop
4C30BE 0F B7 0B             movzx ecx,word [ebx]     ; groupId
4C30C1 83 C7 03             add edi,3                ; group header =3B
4C30C9 80 7B 02 00          cmp byte [ebx+2],0      ; childCount
4C30FF 83 C7 0A             add edi,10               ; each child=10B
4C3107 0F B6 4E 08          movzx ecx,byte [esi+8]  ; include/filter
4C311A 0F B6 56 09          movzx edx,byte [esi+9]  ; passed to row consumer
4C3C16 8B 48 02             mov ecx,[eax+2]          ; S2C7A count
4C3C1A 8D 48 06             lea ecx,[eax+6]          ; S2C7A cursor
4C3C1D E8 5E F4 FF FF       call 0x4C3080
```

0x13：`groupCount=le32(payload+0x1C)`，`cursor=payload+0x92`。0x7A（`0x4C3C10`）：`groupCount=le32(payload+2)`，`cursor=payload+6`。共用 `4C3080`：先清本地列表，每 group 取 **3B**（LE16 groupId + U8 childCount），每 child **10B**；child `+4..+7` 形成 dotted IPv4，`+8 !=0` 才 append 本地 row，`+9` 確實是傳入 row helper 的來源，**不是已證 padding**；跳過的 child 也消耗10B。groupCount=0 **仍會走本地 `F4243`**，此為 `4C314A` 一側的尾部 effect（借用既有 RR3/E69 並與原始分支位址交叉確認）。

推導合成訊息最低 cursor extent：0x13 為 `0x92 + Σ(3+10*nᵢ)`；0x7A 為 `6 + Σ(3+10*nᵢ)`。例如一組兩個 child：0x13 `0xA9` bytes，0x7A **29** bytes。這不是原版實際 wire 長度證據，也不是該 Client 已逐 row 保證不越界的安全證明；安全的合成產生器需要額外檢查每個變長欄位，**屬 Server 自訂防呆政策**。

## 4. W08 — 身份回覆、local event 到連線的嚴格分界

### 4.1 可證的局部順序

```text
[靜態上游：物件 mode+8]
   → 440790 → (mode52→4A3360 E8 112B / other→4A31B0 000F 214B)
   → FBA854 / manager virtual+10 / slot1 local enqueue
   → [T02 queue→framing→socket，條件性；未觀測 wire]
[S2C 某次有效合法 frame，lane2+LOGIN scene 為前提]
   → application 0x13 由 4C3220 table 註冊的 4C37A0
      ├─ optional +20 notice（status 前）
      ├─ status5→專用失敗/清理
      ├─ status other / name empty→一般失敗/清理
      └─ status0 & name非空→Client身份欄位寫入
           → 4C3080 groupCount +0x1C / cursor +0x92
              → local F4243（包含零 group）
           → +0x90==0 才 call 4C3170
              → Client+BD54=1、timeGetTime→BD58、local F4241
              → [後續 UI 選服資料、映射、資源、指標 gate]
              → [有條件的 66C090→4957C0 key0/key2 Connect；T02 主責]
[S2C 另一個有效 application 0x7A] → 4C3C10(+2/+6)→4C3080→F4243
```

`0x4C31E4` 對 Client `+BD54` 寫1，`0x4C31EE` 取時間，`0x4C31F4` push **`0xF4241`** 並由本地事件機制投遞；**這是 Client local event，不是 wire message**。`0x13` 的 handler 本體沒有直接呼叫 socket Connect。T02 E56 的有界呼叫鏈：選擇有效 UI row/endpoint 後，`0x66C090` 可達 `0x4957C0`，有 key0 與 key2 連線、先後與錯誤的條件性本地實作；不能因 `status0` 或 `F4241` 就聲稱對端已完成連線。舊 8414/8415/8416 埠是 Client 靜態常數，不可說是目前部署／原版 Server 唯一權威。

### 4.2 第一筆消息真正不可由本 Client 靜態推定的項目

- C2S builder → slot1 enqueue 的成立條件和本地 bytes 已確認；這**沒有**構成某一次 TCP send成功、封包整體外框、該包先後順位、帳號是否被原版 Server 接受的動態事實。
- `0x13`、`0x7A` 的**可分派 handler** 已確認；從 Client 端不能推出「Server 必先回0x13」、「E8必回0x13」、「000F必回0x7A」、「0x13成功即直接切線」。`0x13` 的 local status0 是 consumer 判定，不是 Server 身份策略。
- T02 E56 的 key0 首包候選 `0x0001` 是**選服後有條件的 local sender**，不是這次登入 C2S E8/000F 的 ACK，亦不是 Server first response。
- 真要證特定原版消息配對與多 Conn 次序，需同 KR 版本、含 frame 解碼／對應 slot、成功/拒絕兩種流程、選服 UI 時間戳的可信原始多 Conn pcap，或原版 Server 端來源；自製 Server 的 fixture 只能標明 synthetic compatibility，不能冒稱原版 trace。

## 5. 玩家流程 × Native 條件 × Client 結果 × Server 影響

| 情境 | 本地入口／C→S | S→C（條件性） | Client 狀態與 UI | 相容 Server 待開發 / UNKNOWN |
|---|---|---|---|---|
| 有效建構物件未改 mode | `6D6340` 初值52、`440790`→E8 112B，slot1 | 不是由 mode 必然決定 | 本地 enqueue 後不保證 UI 成功 | 官方認證演算法與實包未知 |
| mode54 或 fallback | `440790`→000F 214B，slot1 | 同上 | UTF16LE 51-unit×2 等欄位 | 不能把000F轉碼與E8的51窄 byte 混用 |
| 文字轉換失敗 | 前置 helper／E8 WCTMB | 未證收到回包 | exception/CRT/invalid param 未完全閉合 | 不填不透明 six bytes／不能宣稱一定送出 |
| 收 0x13 status5 | 不適用 | `4C37A0` 專用失敗 | optional notice可能先發、BF60清、error | enum名稱未知；安全拒絕由新 Server自行政策 |
| 收 0x13 status other | 不適用 | `4C37A0` 一般失敗 | 不進身份與 group 正常寫入 | 真實 Server 錯誤語意未知 |
| 收 0x13 status0+空名 | 不適用 | 同 handler，一般錯誤 | 不能認登入成功 | 合成 response 必須合法終止字串 |
| 收 0x13 status0+非空名 | 不適用 | identity、groups、`4C3080` | F4243；若+90=0，F4241 | 只支援 local UI/權限欄位，不保證 connect |
| 收 0x7A group列表 | 不適用 | `4C3C10` +2/+6 | local F4243 | 真實回覆次序未知 |
| 選一個有效 group/channel | UI row gate→`4957C0`（T02） | 後續 Server first S2C 未知 | 有條件建立其他 key Conn | Connect、Session、reconnect policy 必須獨立設計 |

## 6. 證據邊界、反證與完整四類責任清單

| 分流 | 精確剩餘內容 | 解除來源／Owner |
|---|---|---|
| Client 待逆向 | `6D6300` 所建立之 mode object 是否存在其它間接/runtime setter；特定 launcher/input 事件到該 virtual call 的完整 positive path；E8+104..109 可能的 alias write；`FBA808` 非直接 writer；全局輸入例外/CRT；上游對 0x13／0x7A 缺尾的安全長度檢查及其它 scene 的行為 | T03 繼續 client native alias/CFG；T02 提供上游 buffer/frame 邊界，不能用「七個 direct xref」否定全部 indirect writer |
| Server 待開發 | 帳號儲存、密碼規則、憑證與身份校驗、Session/租約、Server 選服策略、實際結果／錯誤碼生成、最小安全 payload、回覆順序策略 | S00 現有 `SPEC-AUTH-0001`、`SPEC-FLOW-0001`、`GAP-AUTH-0001` 提供 DRAFT，相容設計需 ADR；**不冒稱原版官方規則** |
| 跨功能待整合 | T02 active LOGIN scene、lane2/secondary dispatch、Conn key1→key0/key2；T03 group/UI；T06 控件資源；選角 RR2／場景 RR8 不本批混入 | 各 Task 只引用已驗證有界子流程；T03 不改 T02、T04、T05、T06 owner/catalog |
| 待遊玩驗證 | 原始 KR Client 成功/拒絕登入實際 socket trace、encoding ACP case、frame順序、Server反應、UI 切線/失敗復原 | 依使用者另外授權的本地隔離驗收；**本次未執行** |

**已反證的過度宣稱**：`E8+104..109 固定0`、`FBA808一律固定CP949/UTF8`、`status0獨立代表登入完全成功`、`F4241/F4243是封包`、`0x13 handler必然先到`、`S2C7A與13使用相同偏移`、`本地 queue=已發至原版 Server`、`local Group/Connect success=選角或世界就緒`。資料來源強度是各分支的原始字節、有限 T02 靜態證據及交接來源，不以 Git 合併自動升格。

## 7. 測試建議與正式驗收狀態

| Test ID | 合成/原生前提 | 預期檢驗 | 等級 |
|---|---|---|---|
| T03-B-RAW-01 | 同 KR BIN | SHA、PE、64 native slices、vtable、7 absolute xrefs、zero-tail | **本次實際 PASS**（只限靜態） |
| T03-B-C2S-52 | mode52 | E8/112B、narrow ×2、tail opaque/WORD、slot1 | source-backed fixture **NOT_RUN** |
| T03-B-C2S-54 | mode54／其他 | 000F/214B、wide ×2、4B常數、WORD、slot1 | fixture NOT_RUN |
| T03-B-CP | Windows ACP 實際不同 | local text chain 不當成固定CP949 | runtime NOT_RUN |
| T03-B-13-5 | 有效LOGIN scene/status5 | optional notice與專用清理 | Client runtime NOT_RUN |
| T03-B-13-0 | status0、非空名稱、合法 group | identity/row/F4243，+90=0附加F4241 | runtime NOT_RUN |
| T03-B-13-EMPTY | status0、空名稱 | 一般錯誤，無正常身份寫入 | runtime NOT_RUN |
| T03-B-7A-0 | 7A,count0 | local F4243（非「什麼都不做」） | runtime NOT_RUN |
| T03-B-7A-ROW | group1,child2 | 合成 cursor 累計6+3+20=29 | 算術 PASS，非原版封包 |
| T03-B-CONN | valid UI row/endpoint | key0/key2 Connect 有條件候選 | T02 靜態來源，runtime NOT_RUN |
| T03-B-FIRST-WIRE | 同版本雙向多 Conn pcap | 首筆消息/response pairing、真實 frame bytes | **需另行授權／UNKNOWN** |

**W05–W08 完成判定**：這四項工作包要求的 Client 有界上下游、payload、writer、handler、分支、codepage／alias 負證範圍、local effect、T02 交界及原版 wire 無法推定的前提都已交出可重驗原生證據；因此 B 項的 **Client 靜態研究／交接完成**。但 W05 的全 runtime launcher 動態 setter、W06 的六個 opaque 真值、W08 的原版 first response 原生配對仍 **UNKNOWN**，需以所列解除來源處理，絕非「整條登入協定、官方 Server、實際可玩完成」。正式 `RR-0003=IN_REVIEW`、`GAP-AUTH-0001=OPEN`，待 T01/S00 依其流程獨立裁決；不改它們的狀態。

## 8. 精確來源與下一工作包

- 本人同版原件重新驗證：本檔 `Tartaros.bin`、`Tartaros.exe`；精確可重跑工具 `20261031-182406-chatgpt-web-roy-T03-B-verify.py`；全部 64 指令斷言是有界來源檢查而不是 REA/Ghidra 全函式語意認證。
- 原本有界 RR3 來源：`kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md`（blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`），以及 E69 來源 `kr-extra-roy/20261030-chatgpt-web-roy-E69-RR0003-E8-tail-uninitialized-CPACP-and-13-handoff-native.md`（blob `98546ce73206e2b8f6fede78d83923af7a76cf5b`）。
- 跨 Task transport／分派：T02 E56 `kr-extra-roy/20261030-091559-chatgpt-web-roy-E56-RR0005-bounded-static-completion-transport-owner-retry-reply.md`（blob `843889349bb58209c02221e720800f0e9e3ff9d8`）與 E60 `kr-extra-roy/20261030-113803-chatgpt-web-roy-E60-RR0007-KR-auth-roster-selection-scene-gated-S2C-dispatch.md`（blob `2ca02f3870d79d3217abf39b8651c43226eb77d6`）。各自並非已驗證原版 packet trace。
- 對 S00 的現有入口：`spec/session-account/SPEC-AUTH-0001.md`、`spec/session-account/SPEC-FLOW-0001.md`、`design/gaps/index.json`，**只交本稿有界證據，不越權替 S00 提升 SPEC/修改台帳**。
- 下一大項 **C（W09–W12）**：group/channel 的 record→UI item/endpoint、玩家點選→Connect、key1/key0/key2 state 與失敗 UI；優先擴充有條件正向 Client 路徑，而非重複目前的 E8/000F builder bytes。

