# RR-0003 KR 原版登入 C2S 來源與 C04-E2b／C04-F0 開發契約 — T03 BIN-first 補充研究

> 日期：2026-11-01（Asia/Taipei）｜研究者：chatgpt-web roy｜分支：t03/roy/chatgpt-web。本稿延續已在 IN_REVIEW 的 RR-0003，**不覆寫既有 1463 行原稿，不自行提升 T01 FULL-PASS 或 S00 ACCEPTED**。僅離線讀取原版 Client，沒有執行、附加、改動、抓包或取得原版 Server。

## 0. 來源、版本與驗收範圍

- KR Tartaros.bin：12,472,320 bytes，SHA256 = 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；原版 Tartaros.exe SHA256 = 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f。
- PE32、i386、ImageBase 0x400000；.text VA 0x401000 / raw 0x400 / VirtualSize 0x7D01F0 / RawSize 0x7D0200；.rdata VA 0xBD2000 / raw 0x7D0600；.data VA 0xD61000 / raw 0x95E800。只有 .text 使用 file offset = VA - 0x400C00；.rdata/.data 依 section header 轉換。
- 正式來源：RR-0003、KR T03、GAP-AUTH-0001；main 台帳狀態 ACTIVE / dispatch IN_REVIEW。正式任務沒有授權研究員自己標記 ACCEPTED。原 RR3 技術稿 kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md，blob SHA 64c8c1a3429ae6ff177a84dee0d08ad69dba0b17；W05–W08 blob e5463936b7b48421219c0e0c83d5d4bf9b07b09f；E83 正向回覆/選服補證 blob f479ab85b123779e4674161bcc71030389cbd623。
- 已真正把 main=f9913c4da0e4afaa3a6f8aca9a5d69919912eb5c 合併至既有 T03 分支，雙父 merge commit f6a8c11c9b16371a41f55391c89f8dad21742fd8；核對 behind=0，保留原 T03 工作並避免重寫別的 Task。
- 研究分類：N＝原始 BIN 指令及正確邊界確認；C＝局部可達但依賴有效 UI/場景/Conn/CRT/編碼；U＝未知或未全域封閉；SYN＝合成測試，不是官方封包／Client 實測。
- S00 C04 Iteration40 目標 M1 = 真正 Client 登入 C2S 可辨識；M2 = 信任登入後 C02 Account/Session；M3 = Client 接受登入回覆顯示下一畫面。這些都需獨立驗收，本稿是必要來源交付而非 Server 功能實作。

## 1. 登入事件 → key1 → vtable → 兩種 Producer：真正正向來源

### 1.1 UI 入口與控制狀態

對原始 .text 的 E8 rel32 目標掃描，登入提交入口 0x66DE20 有三個直接呼叫起點：0x66E23B、0x66E257、0x66E3E0。後者前面的 0x66E3C3–0x66E3DA 會把事件物件欄位與 [EDI+0xF0]+0x20 或 [EDI+0xF4]+0x20 比對，匹配才執行 0x66DE20；之後設定 owner+0x13DC=0、+0x13D9=1。前兩個 callsites 為另一組 UI 旗標/條件分支，不能當作兩種登入 mode 的證據。

在 0x66DE20 本體：
- 0x66DE49–0x66DE7D 依次以 UI controls [EDI+F0]、[EDI+F4]、[EDI+F8] 的 vtable +0x90(0) 更新狀態；失敗後 0x66DF2B–0x66DF5F 用 +0x90(1) 恢復。
- 0x66DE7F–0x66DE96 從 [EDI+F4]+0x148 取得非空 pointer，呼叫 0x6EE1F0 建立 [EBP-0x78] 本地輸入；0x66DEA1 檢查 [EDI+F0]+0x141 旗標，0x66DEB7 從 [EDI+F0]+0x108 取得另一個字串（small-string inline/heap selector）。
- 0x66DEC5 檢查 FBACD0 lazy flag；0x66DEE6 call 0x6D6300 建立 singleton，0x66DEF0 將 pointer 存 FBACD4。
- 0x66DF04 lea ecx,[ebp-0x78]、0x66DF07 push ecx、0x66DF08 push esi、0x66DF09 mov eax,0xFBACD4（**singleton holder 位址**）、0x66DF0E call 0x6D6400。返回後 0x66DF13–0x66DF25 將 0x66 bytes 本地暫存清為零；不能把它推成所有 heap credentials 都已清除。
- 原生僅證明上述 UI input/control pointer；**精確官方 UI 按鈕資源 ID、輸入欄 label、0x6EE1F0 全部過濾和失敗 UI 文案仍未知**。不要由函式命名猜出這些資訊。

### 1.2 key1 Connect gate → 0x440790 的間接真實 caller

~~~asm
6D6321 C7 00 1C B0 BF 00     mov dword [eax],0xBFB01C ; ctor vtable
6D6340 C7 40 08 52 00 00 00  mov dword [eax+8],0x52    ; initial login mode

6D6400 55 8B EC               push ebp; mov ebp,esp
6D6404 8B F0                  mov esi,eax             ; &FBACD4
6D6406 8B 06                  mov eax,[esi]           ; login object
6D6408 85 C0                  test eax,eax
6D640A ...                    je 6D6491              ; no object -> return 0
6D6410 83 C0 0C               add eax,0x0C          ; host string
6D6413 83 78 14 10            cmp dword [eax+14h],16 ; string inline/heap
6D641B 6A 00                  push 0                 ; no pre-shutdown flag
6D641D 50                     push eax               ; host
6D641E A1 18 13 FB 00         mov eax,[FB1318]      ; Client*
6D6423 50                     push eax
6D6424 E8 E7 F1 DB FF         call 0x495610         ; key1, port0x20DF, lane2
6D6429 85 C0                  test eax,eax
6D642B 75 6B                  jne 6D6498           ; nonzero Conn gate
6D6491 33 C0                  xor eax,eax
6D6495 C2 08 00               ret 8
6D6498 8B 45 0C               mov eax,[ebp+0Ch]
6D649B 8B 0E                  mov ecx,[esi]          ; login object
6D649D 8B 11                  mov edx,[ecx]          ; vtable
6D649F 8B 52 30               mov edx,[edx+30h]
6D64A2 50                     push eax               ; second UI input
6D64A3 8B 45 08               mov eax,[ebp+8]
6D64A6 50                     push eax               ; first UI input
6D64A7 FF D2                  call edx               ; -> 0x440790 if ctor vptr
6D64A9 B8 01 00 00 00         mov eax,1             ; ignores dispatch return
~~~

原件 .rdata [0xBFB01C+0x30]（VA 0xBFB04C）為 DWORD 0x00440790。故實際正向鏈為：

~~~text
UI 事件 (66E23B / 66E257 / 66E3E0)
 → 66DE20，收集兩組 UI input
 → 66DF0E / 6D6400
 → 6D6424 / 495610：key1 Connect (historical port 8415 / lane2)
 → nonzero only
 → 6D64A7 vtable +0x30 → 440790
 → per-call mode dispatch：E8 或 000F
 → [FBA854].vtable+0x10(slot=1,payload,length)
 → T02 Manager lookup/Conn queue/framing/WSASend (further gates)
~~~

**不能誤判 440790 沒有 caller**：掃描原始 .text E8 rel32 的 0x440790 直接呼叫候選為零，因正向呼叫是上述 vtable 間接。0x6D6400 的 Connect=非零只是本地 helper gate，不是 Server 已收到登入或曾回覆。其它 key1 helper direct caller 0x6D6377/6D6508/6D65C8/6D670C/6D696C 有其各自本地初包候選/回調，並非另五個 E8/000F producer；不能混成單一登入流程。

### 1.3 Mode 來源、不同模式與互斥邊界

Ctor 0x6D6340 預設登入物件 +8=0x52。另一 virtual 方法 0x440280 從本地設定字串更新 mode；0x440441 push .rdata 0xBFAFC0（ASCII serverIp.ini），0x440446 call IAT BD218C=GetFileAttributesA，0x440450 比對 -1。後續原生：
- 0x440462 起與 0xBFAFD0 的 ASCII Rlyeh 比對，命中 0x440494 寫 [object+8]=0x40；
- 0x4404AD 起與 0xBF2375 比對，該地址**確切原始字節為 NUL**（空 C 字串），命中 0x4404DF 寫 [object+8]=0x52；
- 0x4404F5 起與 0xBFAFD8 的 ASCII 81F91496CFC348A89F5AF83CBCDCEAE8 比對，命中 0x44052D 寫 [object+8]=0x54；0x440534 寫 object+0x28=1。此 32 字元不應被命名為官方密碼演算法或官方 Server secret。

~~~asm
440793 8B 41 08             mov eax,[ecx+8]
440796 83 F8 52             cmp eax,0x52
4407C2 E8 99 2B 06 00      call 0x4A3360 ; mode52 -> 0xE8 112B
4407CB 83 F8 54             cmp eax,0x54
4407F7 E8 B4 29 06 00      call 0x4A31B0 ; mode54 -> 0x000F 214B
440822 E8 89 29 06 00      call 0x4A31B0 ; other (including mode40)
~~~

**同一次 0x440790 呼叫互斥**（0x52 走 E8；0x54/其它走000F），但 mode 可能隨 Client 本地設定改變，因此不可聲稱某個玩家/版本永遠固定一種 payload。它是 object+8 LOGIN Mode，不等於 T02 Conn+A02C FRAME Mode。直接 E8 掃描兩個 builder：4A3360 只命中 4407C2，4A31B0 命中 4407F7、440822；不排除 computed/indirect 或其它網路相關 Producer。

## 2. C04-E2b 登入 Payload 契約表（**decoded application payload**）

表內 offset **全部相對 application payload 起點**，不是 TCP frame marker 或含 header 的 wire offset；LE 為 little-endian。Writer 的 N 僅限列出的原件 Builder。

| 格式/offset | Type | Bytes | 上游 Writer／資料來源 | Server 假設邊界 |
| --- | --- | ---: | --- | --- |
| E8 +0..1 | uint16 LE | 2 | 4A33AB MOV ECX,E8；4A33B0 寫本地 WORD | opcode 00E8 |
| E8 +2..52 | char[51] | 51 | [EBP+8] 第一組 UI 傳入 → 4A33CD call 47F540；4A3455/3475/34AA/34C8 CP_ACP WideCharToMultiByte；4A34D3/4A34D6 capacity51 copy | 窄字串、可能含 NUL；不得假設 UTF-8/CP949 或每字節必為 ASCII |
| E8 +53..103 | char[51] | 51 | [EBP+0C] 第二組 UI 傳入 → 733DD0 digest-like transform、46E3C0 文字化、ACP 轉碼，4A34E6/4A34E9 capacity51 copy | **轉換後文字，不是明文密碼**；不得直接當 C02 plaintext |
| E8 +104..109 | byte[6] | 6 | 已核 E8 Builder 找不到正向完整 writer，stack 區間無已證全面初始化 | **OPAQUE/UNKNOWN**：不是已證零、nonce、ticket、版本、checksum；不可做授權憑證 |
| E8 +110..111 | uint16 LE | 2 | 4A33A0 讀 global [FB1318]、4A33B5 讀 Client+BF80 WORD、4A33C5 寫 tail | 動態狀態 WORD，語義 UNKNOWN |
| 000F +0..1 | uint16 LE | 2 | 4A31E3 MOV ECX,0F；4A31EC 寫 WORD | opcode 000F |
| 000F +2..103 | UTF-16LE WCHAR[51] | 102 | 第一組 UI [EBP+8] → 4A3273..4A3281 call 892E4D capacity51 | WCHAR 單位與 UTF-16LE code unit，不是 51 個 UTF-8 bytes |
| 000F +104..205 | UTF-16LE WCHAR[51] | 102 | 4A3201 47F540、4A3231 733DD0、4A325D 46E3C0，4A3299..4A32A3 bounded WCHAR copy | 轉換後摘要文字；來源環節仍可能受 ACP 影響 |
| 000F +206..209 | uint32 LE | 4 | 4A31F3 寫 0x00010001 | fixed builder constant；**不擅自命名官方版本** |
| 000F +210..211 | uint16 LE | 2 | 4A31FA MOV DWORD [EBP-6A],0x34 的低兩個 bytes | fixed 0x0034 |
| 000F +212..213 | uint16 LE | 2 | 4A3266 讀 [FB1318]，4A326C 讀 Client+BF80，4A327D 再寫 WORD [EBP-68] | 會覆寫前述 DWORD 0x34 的高兩 byte；**不是固定0** |

幾何：E8 = 2+51+51+6+2 = **112 B (0x70)**；000F = 2+102+102+4+2+2 = **214 B (0xD6)**。兩者經同一 Manager [FBA854].vtable+0x10、slot/key **1** 入列（E8: 4A34FC PUSH 0x70、4A3503 PUSH 1、4A3505 CALL EDX；000F: 4A32B6 PUSH 0xD6、4A32C2 PUSH 1、4A32C4 CALL EDX）。容量51含安全終止的前提；不是原版官方帳密允許字數或 CRT 全部錯誤路徑的證明。

### 2.1 Builder/欄位原生機器碼（選列）

~~~asm
; E8
4A33A0 8B 15 18 13 FB 00        mov edx,[FB1318]
4A33AB B9 E8 00 00 00           mov ecx,0xE8
4A33B0 66 89 4C 24 74           mov word [esp+74h],cx
4A33B5 66 8B 8A 80 BF 00 00     mov cx,[edx+BF80h]
4A33C5 66 89 8C 24 E6 00 00 00 mov [esp+E6h],cx
4A33CD E8 6E C1 FD FF           call 47F540
4A340C E8 BF 09 29 00           call 733DD0
4A3436 E8 85 AF FC FF           call 46E3C0
4A344E 8B 35 CC 21 BD 00        mov esi,[BD21CC] ; WideCharToMultiByte IAT
4A3454 53                       push ebx      ; ebx=0, CP_ACP
4A3455 FF D6                    call esi
4A3475 FF D6                    call esi
4A34AA FF D6                    call esi
4A34C8 FF D6                    call esi
4A34D3 6A 33                    push 0x33    ; first 51-byte slot
4A34D6 E8 7E 06 3F 00           call 893B59
4A34E6 6A 33                    push 0x33    ; second 51-byte slot
4A34E9 E8 6B 06 3F 00           call 893B59
4A34FC 6A 70                    push 0x70
4A3503 6A 01                    push 1
4A3505 FF D2                    call edx     ; manager vtable+0x10
; 000F
4A31E3 B9 0F 00 00 00           mov ecx,0x0F
4A31EC 66 89 8D C4 FE FF FF     mov word [ebp-13Ch],cx
4A31F3 C7 45 92 01 00 01 00     mov dword [ebp-6Eh],0x10001
4A31FA C7 45 96 34 00 00 00     mov dword [ebp-6Ah],0x34
4A3201 E8 3A C3 FD FF           call 47F540
4A3231 E8 9A 0B 29 00           call 733DD0
4A325D E8 5E B1 FC FF           call 46E3C0
4A3266 8B 0D 18 13 FB 00       mov ecx,[FB1318]
4A326C 66 8B 91 80 BF 00 00    mov dx,[ecx+BF80h]
4A327D 66 89 55 98              mov word [ebp-68h],dx
4A3281 E8 C7 FB 3E 00           call 892E4D
4A32A3 E8 A5 FB 3E 00           call 892E4D
4A32B6 68 D6 00 00 00           push 0xD6
4A32C2 6A 01                    push 1
4A32C4 FF D2                    call edx
~~~

**Stack-relative trap**：E8 4A33C5 的 [ESP+E6] 要依後續 PUSH/ESP 調整還原成 payload+110；不可以把 E6 當 wire offset。000F 4A31FA 先寫4 bytes，但 4A327D 後寫兩 byte，因此 +212..213 最終是 BF80 而不是 zero。檢查 51-capacity copy 不代表輸入過長時成功、也不等於包緩衝全部已初始化；CRT invalid parameter、Win32 轉換失敗仍要保留。

### 2.2 FBA808、CP_ACP 與動態 codepage

- FBA808 位在 .data 虛擬零填充範圍，**PE 初始為0**；0 傳給 Windows Unicode/ANSI conversion 表示 CP_ACP。4A3360 自己的四次 WideCharToMultiByte 輸出又明確推 CodePage=0（不是每次從 FBA808 讀）。
- 47F540 的 47F59E/47F5D9、46E270 的 46E2CA/46E31C 使用 [FBA808]，並在登入前中間字串/變換鏈提供 codepage 依賴。即使 000F 最終發送的是 UTF-16LE，摘要來源路徑也可能取決於 ACP。
- **不能宣稱 CP949 或 UTF-8 固定**；Windows host 的 ACP 可變，亦未全域排除 computed address/indirect alias 覆寫 FBA808。已知直接 displacement 不等於所有 writer 完成驗證。
- 輸入字串、轉碼、digest/text（733DD0/46E3C0）是不同操作。尤其第二欄是 **經轉換文字**，不是原始 password；如果 C02 只接受 plaintext，E3b 必須先進行安全的 credential-format-aware 兼容策略審核，**不可直接把摘要字串送給 AuthenticateAndClaimAsync 作明文**。

## 3. T02 Transport 正向交界：已入列 ≠ 已送 wire

~~~text
UI→6D6400 key1 Connect 495610 (port0x20DF=8415, lane2)
   └─ nonzero + valid login object -> 440790
       ├─ mode52 -> E8 112B
       └─ mode54/other -> 000F 214B
           ↓
       [FBA854].vtable+0x10(key=1,payload,n)
           ↓ 8069A0 Manager key lookup
           8069EB -> 8060D0 Conn local payload queue
           ↓ 804A40 / 804AD6 -> 8061A0 send pump
           ↓ 806202 reads Conn+A02C FRAME mode
            ├─ nonzero: 806223→807830 XOR/checksum 0x0BBB frame
            └─ zero / encoder failed: 80623A→807A70 raw 0x1A68 frame
           ↓ WSABUF / IOCP / 8068B0 WSASend (subject to connection/buffer gates)
~~~

此圖是 T03 Builder 與 T02 的 source-level 交界，不是實際 TCP trace。LOGIN object+8 mode **不等於** Conn+A02C framing mode；app opcode E8/000F **不等於** frame marker 0BBB/1A68。112/214 是 app payload bytes，還沒有算 outer header。原版 Client 協定使用的靜態 8415 也不代表新 Server 一定需要相同部署端點；實際 launcher/endpoint/版本、該次 buffer、first wire bytes、成功 IOCP completion 全部需另驗證。其它 key1 caller 可能排其它 packet，不能混淆為登入 Producer。

## 4. C04-F0 待補 S2C 回覆契約表

S2C LOGIN Scene 二級命令表 0x4C3220–0x4C3265：decoded app command 0x0013 → 0x4C37A0；0x007A → 0x4C3C10。它們需先通過 T02 0x807B40 receive frame、0x807E50 decoded node、lane2/0x4930E0/0x4C4670 scene/handler gate。單靠 Client 不能推論 **E8 /000F 各自必然配到 0x13 /0x7A**，也不能推論哪個是 original Server 首回覆。

| S2C payload relative offset | Type | Client Consumer 與行為 | 尚未知 / Server 可做 |
| --- | --- | --- | --- |
| 0x0013 +0 | uint16LE opcode | 0x4C37A0 LOGIN scene handler | 不是 guaranteed original first reply |
| 0x13 +2 | UTF-16LE NUL name / bounded copy | 0x4C3951..3973 success 必須 nonempty；0x4C3990/399B → owner+67E4（最多10 WCHAR source，dest capacity11） | 缺 name 即使 status0 也失敗；絕不能從短包假設安全 |
| 0x13 +0x16 | byte status | 4C3821 取值；4C3824 比5；4C3949 比0 | 0+nonempty→success，5→專用 failure UI，其它→generic error；**5 不得稱官方停權碼** |
| 0x13 +0x17 | byte | 4C39A3 等 → owner+68B4 | 意義 UNKNOWN |
| 0x13 +0x18 | uint32LE | 4C3979/3981 → owner+67E0 | 身分關聯值但非可信 Session authority |
| 0x13 +0x1C | uint32LE group count | 4C3A03 | 每個 group3B、child10B；缺 per-row remaining-length guard，Server 自行防短包/overflow |
| 0x13 +0x20.. | optional UTF-16LE notice | 4C37E2 在 status branch 之前會觸發 CP conversion/notice | 錯誤亦可能顯示服務端文字；長度/NUL 務必安全 |
| 0x13 +0x86 | byte | 4C39C3/4C39F2 → owner+6898 | 後續 key0 C2S0x0001 +27 |
| 0x13 +0x87 | narrow char[5] capped | 4C39E2/4C39F8 → owner+6899 | key0 +28..32，非已證 token |
| 0x13 +0x8C | uint32LE | 4C39C9/4C39FD → owner+68A0 | key0 +33..36，業務意義 UNKNOWN |
| 0x13 +0x90 | byte | 4C3A15 判0時 4C3170 → local F4241；另 local F4243 | 這是 UI notification，不是另發 C2S 或 S2C opcode |
| 0x13 +0x92.. | 3B group + N×10B row | 4C3A10→4C3080，row+4..7 IPv4，row+8!=0 append，row+9 local arg | 不證官方群組資料與 server-first order |
| 0x007A +0..1 | uint16LE opcode | 獨立 0x4C3C10 list handler | 非 0x13 status 同義字；配對/排序 UNKNOWN |
| 0x7A +2 | uint32LE group count | 4C3C10 → 4C3080 | **不是** 0x13 的 +0x1C |
| 0x7A +6.. | group rows cursor | 相同 group 3B / row 10B 消費者 | **不是** 0x13 的 +0x92 |
| ban/incorrect password distinction | 原版 status enum UNKNOWN | 專用 status5/generic path 使用 753F00、58AA50 UI，Manager vtable+0x20 key1 shutdown | C02 可自訂 ban policy，但回覆 enum 必須 T01 / Client 顯示測試才可宣稱兼容 |

**結果 branch native**：4C3821 MOV DL,[ESI+16h]；4C3824 CMP DL,5→專用 UI/error；4C3949 TEST DL,DL，0 且 +2 UTF-16 非空才到 4C3979 成功 writer；status5/其它/空名進 failure UI，manager virtual+0x20 shutdown (1,1) 並在 4C3B5E 清 BF60，錯誤返回 EAX=0x80004005。E83 核對：當 login singleton vptr 仍為 BFB01C，失敗中 virtual+0x14 的函式指標在 .rdata 為 0x476430，只含 C2 04 00 (ret4)，**不會由這個虛擬回調自動重送 E8/0F**；manager 的 close call 另有副作用。其它 UI 事件是否再觸發重試仍 UNKNOWN。

### 4.1 成功之後到選服，必須另有 UI/Conn gate

正確 status0 + nonempty UTF16 name + group 成功後，Client shared owner+67E0/+67E4/+6898/+6899/+68A0 由 0x4C37A0 寫入，local F4243、依 +0x90 可能 F4241 通知 UI；**沒有當場 key0/key2 Connect**。後續玩家/合法 UI 事件需經 0x66C090 resolver→0x4957C0，用列表來源的 host 建 key0 (0x20E0) 和 key2 (0x20DE)，兩個 Conn 非 NULL 才排 key0 的 C2S 0x0001 57B 候選。與登入 E8/000F 不可混同。

| 後續 key0 C2S 0x0001 | 本地 Writer/來源 |
| --- | --- |
| +0..1 | uint16LE opcode 0001 |
| +2..5 | owner+67E0 ← S2C13 +0x18 |
| +6..25 | owner+67E4 ← S2C13 +2 的 10-WCHAR capped copy |
| +26 | byte constant 1 |
| +27 | owner+6898 ← S2C13 +0x86 |
| +28..32 | owner+6899 ← S2C13 +0x87 |
| +33..36 | owner+68A0 ← S2C13 +0x8C |
| +37..56 | **owner+67FA 第二組 10 WCHAR copy**（4958D9..4958EC），來源完整 Writer UNKNOWN；先前 E82 指其最終 fixed-zero 已被 E83 指令反證 |

上述對應只證在 owner / UI / connection 充分成立時的**靜態資料流**，不能將 Client echo 的值當 Session proof；亦不代表實際登入後畫面已可操作，M3/M4 需另驗。

## 5. C04-E2b／E3b Server 必須驗證：Native vs 新 Server 自訂政策

| 項目 | Client 靜態可證/有界 | Server 設計政策（非官方）／阻斷 |
| --- | --- | --- |
| 版本與來源 | 本稿 KR BIN SHA 和固定地址；真實 Rebirth Client 版本未證同一 | Per-build profile，未知版本 fail closed；不得對不相符版本硬套 schema |
| 連線階段 | 本鏈 key1 slot1 login object +8 mode，Conn+A02C 是**另一個** frame mode | Server-side connectionId Guid、phase=LoginPending、timeout、重放限制、上下游 Session 綁定 |
| 解包與校驗 | app E8 112B / app000F 214B；frame marker 0BBB/1A68 由 T02 管理 | 先 per-connection bounded stream/decoder，嚴格拆 frame；禁止把 application 長度當 wire 長度 |
| account | E8 ACP char[51] 或000F UTF16LE WCHAR[51] | NUL、字元、容量、名稱正規化；ACP 需 profile，不能固定 UTF8/CP949 |
| credential | 第二欄為轉換後 digest-like 文字，**非已證 plaintext** | 安全協定 adapter + C02 storage/auth verification 必須相容；現有 AuthenticateAndClaimAsync(name,password,Guid,TimeSpan,ct) 若預期明文，**不能直接填摘要當明文** |
| opaque bytes | E8 +104..109 上游未證；兩種格式尾 WORD 來自 BF80 | 不許自訂成必等於0/nonce/password/token；可暫作未信任原始 bytes；若是必要認證資料，先阻止 native enable |
| 000F constants | +206=0x00010001、+210=0x0034、+212=BF80 | 可依指定 KR build 嚴格比對已證 constants，不賦予原版官方名稱 |
| Session lease | Client 提供本地資料不證明身份 | 使用與管理後台共用的 SQLite/PG provider，C02 受信查帳密/停權，建立 Server-owned lease，未知 native credential 時保持 OFFLINE / fail closed |
| status/reply | 0x13 status0/nonempty success local、status5 dedicated error、others generic；0x7A separate | 成功與帳密錯誤/停權映射可自訂，但未證 Client 會接受所有映射；F0 不得提前宣稱原生登入已成功 |
| security/logging | Payload 可能含敏感身份與摘要 | 不記 credential/raw frame/完整 hex 到公開日誌；僅保留安全 metadata/分類/位元組長度和匿名 trace |
| 實際可玩 | UI→Builder→T02 可達但非 OS 送出實證 | M1/M2/M3 分別 Gate；獲使用者授權同 SHA Client＋隔離自製 Server 與遮蔽敏感資料後做實測 |

## 6. 反例、仍未解疑點與交付

- Ctor 預設 mode52 不等於所有登入必用 E8；0x440280 可以改 mode0x40/0x54，後者與其它 mode 都走 000F。
- 0x440790 沒有 direct E8 xref 不等於沒有 GUI 呼叫；0x6D64A7 vtable +0x30 的 BFB04C 確切指向它。
- key1 Connect 返回非零不等於 C2S 成功入列、WSASend 完成或 Server 收到；0x6D64A9 返回1 也未檢視登入 virtual dispatch 的返回值。
- E8 6-byte 未獲完整正向 writer 不能推成官方固定0；000F +212 在 4A327D 被動態 BF80 覆寫，不能由初始 DWORD 0x34 推成0。
- CP_ACP 是 runtime ANSI codepage；Windows OS、全域 FBA808 alias 等尚未全部閉合。000F UTF16LE 最終 layout 不等於上游 digest 完全不受 ACP 影響。
- status0 單一 byte 不構成成功：名稱必須非空且資源／handler/list有效。status5 不能未經證據就叫「帳密錯」或「停權」官方枚舉。
- 0x13 group count +0x1C、cursor+0x92；0x7A count+2、cursor+6。Client group/row consumer 局部缺剩餘長度 guard，Server 必須自行檢查至少 fixed prefix 和 n×record bounds。
- E82 把 key0 C2S1 +37..56 當固定零是已提出勘誤的舊主張，應以 E83 後續 source writer 補正，不使用過期固定值。
- **尚需原生靜態**：UI 所用 control 對應正式資源／完整 validation；E8 6-byte alias/writer；FBA808 computed writer；完整 733DD0/46E3C0 與 C02 credential 等價；S2C 0x13/0x7A 剩餘 handler guards；不可直接拿其它版本的 DB/Auth schema 當這個版本 native。
- **只能靠授權實機或原始 Server 證據**：某次真實 mode/ACP、首個 raw C2S frame 與回覆順序、原版 status-to-ban mapping、按下按鈕至選服 UI 的實際成功流程。合成 vector、原始 BIN bytes 或自製後端成功不能自動證明原版 Server 的歷史規則。
- 附獨立 Python 標準庫只讀 checker，核對 exact BIN SHA、PE section、native instruction prefixes、direct-E8 candidates、vtable BFB04C 和 layout arithmetic。這些是**有界位元組稽核**，不是原生 Client runtime、全部 callgraph、T01 FULL-PASS。T01 可按下述腳本/地址定向 R2；S00 再按既有 I40-07/I40-08/I40-14 記錄，不新增影子 RR/GAP。

### 原稿與跨 Task 追溯

- T03 RR3 主稿：kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md（blob 64c8c1a3429ae6ff177a84dee0d08ad69dba0b17）。
- T03-B W05–W08：kr-temp-roy/20261031-182406-chatgpt-web-roy-T03-B-W05-W08-auth-BIN-first.md（blob e5463936b7b48421219c0e0c83d5d4bf9b07b09f）。
- T03 E83：kr-temp-roy/20261101-chatgpt-web-roy-RR0003-E83-login-result-to-key0-identity-provenance.md（blob f479ab85b123779e4674161bcc71030389cbd623）與 E82 修訂 blob 02618e3d79f38092e39f1970e2b4977a2503e21f。
- T02 E56：kr-extra-roy/20261030-091559-chatgpt-web-roy-E56-RR0005-bounded-static-completion-transport-owner-retry-reply.md（blob 843889349bb58209c02221e720800f0e9e3ff9d8）；E58：kr-extra-roy/20261030-110906-chatgpt-web-roy-E58-RR0004-A02C-alias-mode-fallback-bounded-BIN-first.md（blob b5c53b93ec20e056fb3f07374468a341ce4ee9c9）。
- S00 C04-NATIVE-LOGIN-EXECUTION-READY-HANDOFF / Iteration39/40；T01 T03 README 的既有 READY_FOR_REVIEW 退回項保持不變。**本次只上傳新的 Markdown/驗證器到 T03 分支，不更動 main 或正式 RR/審核狀態。**
