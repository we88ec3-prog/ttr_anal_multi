# RR-0005 KR／T02 增量原生補證：選服連線的隱含 ESI Client 上下文、雙 Conn 成功門檻與入列回傳界線

> chatgpt-web roy；2026-11-01 01:49 Asia/Taipei。工作分支：extra/roy2。這是**已正式 ACCEPTED 的 RR-0005 的額外靜態補充**，不是重新認領／重新提交／修改 RR 台帳，也不自稱 T01 FULL-PASS。

## 0. 第一手來源、既有研究與新的精確問題

- 原始 KR `Tartaros.bin`：12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；本次對實際檔案唯讀重新計算通過。對照 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE32 ImageBase `0x400000`；`.text` VA `0x401000`，raw `0x400`，VirtualSize `0x7D01F0`，SizeOfRawData `0x7D0200`；此區 VA `v` 轉 raw 為 `v−0x400C00`；未混用 KR 與 TC。
- 正式請求：`research/requests/index.json` 中 `RR-0005`／`GAP-NET-0002`；研究登入 0x13 至選服 UI、`0x495610`／`0x4957C0` 連線、socket 關閉、首次本地發包、重試/連線所有權。查證當下 RR-0005 為 `RESOLVED/ACCEPTED`；`GAP-NET-0002` 尚 OPEN、SPEC DRAFT/PARTIAL。
- 已存在且不可覆蓋的完整 E56 原稿：`kr-extra-roy/20261030-091559-chatgpt-web-roy-E56-RR0005-bounded-static-completion-transport-owner-retry-reply.md`，Git blob `843889349bb58209c02221e720800f0e9e3ff9d8`。E56 已驗收其**限定 Client 靜態契約**；本文新增 register-level provenance 與幾個回傳值檢查的精細分支，不重複 E56 的 138K 全稿。
- 額外對照：E57/E82 的 key0 first local frame 證據、E58 的 `Conn+A02C` frame selector，只做來源關係；本稿**不把 local enqueue 等同 wire send**。
- 這次的新問題：（1）選服 UI 只向 Connect helper 傳文字 endpoint 嗎？（2）`ESI` 指向誰，在哪裡初始化，哪些路徑使用？（3）排隊寫入和接收掛載如果失敗，是否阻止 helper 回傳成功？（4）舊 key1 是否等到排入 0x007E 成功才改狀態？

## 1. 結論摘要（僅限上述 KR client native）

1. `0x48ABA1`：Client 建構函式 `0x48AB70` 將 `EDI`（Client object）寫入 global `[0xFB1318]`，`0x48ACB6/BC/C2` 同時將該物件的 BF60/BF64/BF68 各清 0。這提供具體的 Client 指標來源。
2. UI resolver 的**兩個已核對直接呼叫** `0x66C1A7/0x66C247` 之前，分別在 `0x66C1A1/0x66C241` 讀取 `[0xFB1318]` → ESI；先前的 ESI 另經 `push esi` 作為堆疊上的 host 參數。`0x4957C0` 本體在兩個 Conn pointer 都非零時，從 `[ESI+BF60]` 讀舊 key1、後續寫 `[ESI+BF64/BF68]`。因此**傳入 IP 字串不是這個 helper 成功分支使用的唯一上下文**。
3. 同一 helper 內 `0x49593D` 透過 vtable+0x10 處理 key0 的 **57-byte local candidate**；`0x49594B` 與 `0x495959` 透過 vtable+0x14 對兩個 Conn 掛載接收。三個 `call edx` **回傳值皆沒有在 `0x49595B/0x495962` 寫 BF64/BF68 前被測試**，隨後返回 EAX=1。這只證該 helper 的條件式流程已過兩個非 NULL Conn gate，不證明 WSASend 成功、IOCP 完成或 Server 首回覆。
4. 若在雙 Conn 成功時原有 `ESI+BF60 != 0`，`0x495853` 會嘗試把兩 bytes `WORD 0x007E` 送入舊 key1 的 queue API `0x8060D0`；**其回傳值沒有被檢查**，之後 `0x49585E` 直接置舊 Conn `+A0B0=1`，`0x495868` 直接將 `ESI+BF60=0`。不能由這段宣稱 0x007E 已抵達 Server 或成功收回舊 key1。
5. `0x495610` 另依 stack Client* 及 host，走 key1 port `0x20DF`；對照 `0x4957C0` 使用 host stack + ESI Client* 的函式界線，**不可把兩個 helper 套成同一個純堆疊參數宣告**。
6. 本次重新搜尋 `.text` 內對三個目標的**E8 rel32 byte 候選**：`0x4957C0` 有 2 處、`0x495610` 有 6 處、`0x8060D0` 有 2 處。均按 VA+5+signed rel32 計算，並就上述選定的已知 native callsite 用 objdump 確認指令邊界；這個搜尋**不能否定間接 call／非 .text / dynamic patch**。

## 2. 來源／指令／消費者資料流（附 native bytes）

### 2.1 Client 物件 → 全域 Client pointer → UI 呼叫寄存器

```asm
48AB98 8B 7D 08                 mov edi,[ebp+8]             ; ctor Client*
48ABA1 89 3D 18 13 FB 00        mov [0xFB1318],edi
48ACB6 89 9F 60 BF 00 00        mov [edi+BF60],ebx         ; EBX=0
48ACBC 89 9F 64 BF 00 00        mov [edi+BF64],ebx
48ACC2 89 9F 68 BF 00 00        mov [edi+BF68],ebx

66C193 85 F6                    test esi,esi               ; UI host candidate gate
66C19B E8 E0 84 DA FF           call 0x414680
66C1A0 56                       push esi                   ; host param
66C1A1 8B 35 18 13 FB 00        mov esi,[0xFB1318]       ; Client* register context
66C1A7 E8 14 96 E2 FF           call 0x4957C0

66C233 85 F6                    test esi,esi               ; different UI branch
66C23B E8 40 84 DA FF           call 0x414680
66C240 56                       push esi
66C241 8B 35 18 13 FB 00        mov esi,[0xFB1318]
66C247 E8 74 95 E2 FF           call 0x4957C0
```

在 `0x66C1A0/0x66C240` 的 push 之後覆寫 ESI 是重要證據：**push 的是舊 ESI host，helper 的 live ESI 則來自 global Client 指標**。只看 `call 4957C0` 或只看堆疊參數會漏掉這條資料流。`0x4957C0` 開頭只建立 EBP frame、保存 EBX/EDI，沒有在讀 `[esi+BF60]` 前由自己的堆疊重新建立 ESI；兩個已確認 caller 的寄存器定義填上這個隱含依賴。這是 ABI/特定 caller **有界的實際 register interface**，不對其他可能 indirect caller 做普遍假定。

### 2.2 Connect 路徑條件與老 key1 恢復交接

```asm
4957E0 6A 02                    push 2                     ; lane
4957E2 6A 00                    push 0                     ; key0
4957E4 68 E0 20 00 00           push 0x20E0               ; 8416
4957EA FF D2                    call edx                   ; Manager Connect
4957F2 6A 02                    push 2
4957F4 6A 02                    push 2                     ; key2
4957FD 68 DE 20 00 00           push 0x20DE               ; 8414
495803 FF D2                    call edx
495807 85 FF                    test edi,edi               ; key0 non-null?
495809 0F 84 A1 01 00 00        je 0x4959B0
49580F 85 DB                    test ebx,ebx               ; key2 non-null?
495811 0F 84 67 01 00 00        je 0x49597E

495817 83 BE 60 BF 00 00 00     cmp dword [esi+BF60],0  ; old key1?
49581E 74 52                    je 0x495872
495832 8B 86 60 BF 00 00        mov eax,[esi+BF60]
495839 E8 A2 0B 37 00           call 0x8063E0             ; old Conn queue flush attempt
49583E B9 7E 00 00 00           mov ecx,0x7E
495843 6A 02                    push 2                     ; exactly two bytes
495848 66 89 4D BE              mov word [ebp-0x42],cx
49584C 8B 8E 60 BF 00 00        mov ecx,[esi+BF60]
495853 E8 78 08 37 00           call 0x8060D0             ; enqueue; no check of EAX here
495858 8B 86 60 BF 00 00        mov eax,[esi+BF60]
49585E C7 80 B0 A0 00 00 01 00 00 00
                                 mov dword [eax+A0B0],1
495868 C7 86 60 BF 00 00 00 00 00 00
                                 mov dword [esi+BF60],0
```

注：`0x495817` 的使用在雙 Connect 均非 NULL 後才達到。若第一次 Connect NULL，跳至 `0x4959B0`；若第一次非 NULL、第二次 NULL，跳至 `0x49597E` 清理。兩種失敗均不可稱「已成功分配兩個 slot」。`0x8063E0` 與 `0x8060D0` 是本地處理／queue API，不等於 socket write。

### 2.3 成功門檻的後置副作用與 unchecked returns

```asm
495935 6A 39                    push 0x39                  ; 57-byte local key0 candidate
495937 8D 45 C0                 lea eax,[ebp-0x40]
49593A 50                       push eax
49593B 6A 00                    push 0                     ; key0
49593D FF D2                    call edx                   ; vtable+0x10
49593F 8B 0D 54 A8 FB 00        mov ecx,[0xFBA854]        ; immediate continuation

49594A 57                       push edi                   ; key0 Conn
49594B FF D2                    call edx                   ; vtable+0x14
49594D 8B 0D 54 A8 FB 00        mov ecx,[0xFBA854]        ; immediate continuation
495958 53                       push ebx                   ; key2 Conn
495959 FF D2                    call edx                   ; vtable+0x14

49595B 89 BE 64 BF 00 00        mov [esi+BF64],edi         ; key0 pointer
495962 89 9E 68 BF 00 00        mov [esi+BF68],ebx         ; key2 pointer
495968 B8 01 00 00 00           mov eax,1
49597B C2 04 00                 ret 4
```

**重要負向範圍**：只在列出的這個成功基本區塊內，`0x49593D/94B/959` 的返回值不決定是否寫入 slots；其他 Manager／IOCP／worker code 仍可另有失敗偵測或關閉流程。這裏沒有證據可用來保證 actual first wire bytes 或 accepted server response。

### 2.4 各 helper 的入參差異與 port

| Local helper | 已核對直接 caller | Host/Client* 來源（有界） | Connect 預設 | 隨後是否固定送出 wire |
| --- | --- | --- | --- | --- |
| `0x4957C0` | UI `0x66C1A7,0x66C247` | push 舊 ESI 的 host；新 ESI=global Client*；successful branch 使用 BF60/64/68 | key0 lane2 port `0x20E0=8416`，key2 lane2 `0x20DE=8414` | **否**；僅 local key0 57B candidate + two recv posts |
| `0x495610` | `0x6D6377,0x6D6424,0x6D6508,0x6D65C8,0x6D670C,0x6D696C` | stack `[ebp+8]` 為 Client*、`[ebp+0xC]` 為 host，第三參數控制 pre-shutdown | key1 lane2 port `0x20DF=8415` | **否**；六個上游路徑的本地 queue 候選不等於 wire-first |
| `0x8060D0` | `0x495853` 與 `0x8069EB` 兩處直接 E8 bytes | 本地 Conn queue API，不是 Winsock 直接發送 | 舊 key1 可入列 `WORD 0x007E`／n=2 | **否**；caller 未檢成功 |

Port 常數為**歷史 KR Client 本機程式碼值**；不是對新 Server 部署網路位址及 port 的建議，host 文字由上游 S2C 選服資料提供，不得捏造官方 IP。

## 3. 可重現驗證範圍、反證與本次結果

- 附帶 `kr-extra-roy/tools/rr5_esi_connect_native_audit.py`，以 Python 標準函式庫唯讀核對原件 SHA、PE .text section header、32 處原始 native instruction prefixes 與三組 literal E8-rel32 候選來源；已使用上列原始 BIN 實際執行，結果 **PASS**。GNU objdump 另以 function entry 為界交叉反組譯 `0x48AB70`、`0x495610`、`0x4957C0`、`0x66C090`。
- 可用指令：`python -B kr-extra-roy/tools/rr5_esi_connect_native_audit.py <合法取得的 KR Tartaros.bin 路徑>`。
- E8 raw 掃描可列 direct-call **位元組候選**，不等於全反組譯/全程 alias closure；已知 caller 的正確指令起點是由上下文交叉驗證，對 indirect call／DLL callback／runtime patch **不作不存在保證**。
- ESI 的兩個已知呼叫分支能從同一 global 原生建構 writer 對上；但不保證每個 runtime session global 一定非 NULL、或其它可能間接 caller 也設正確 ESI。若要做 exploitability／crash claim，必須補獨立證據；本文不作此類主張。
- `0x495853` queue return ignored 以及三個 vtable call unchecked，**不表示這些 API 一定失敗**；僅表示此 caller 的 slot writer 不能當成其成功證據。
- 與 BF58 直接 writer、same-key old Conn 全域最終 release、UI 事件實際點選順序、OS I/O 競態與原版 Server 初始回覆仍是不同問題；本次不將它們偽裝成已解。

## 4. 對 S00/Server 的精確交接（不修改已 ACCEPTED 的 RR）

| 類別 | 精確交接 |
|---|---|
| Client 已確認（有界） | S2C 0x13/0x7A→UI 選服→host 來源仍沿用 E56；本稿證實 UI→helper 還傳遞 ESI=Client*，雙 Conn→本地隊列/recv→slot writes 不以這三個回傳值為 gate。 |
| Client 待逆向 | 其它 indirect `0x4957C0` caller 是否存在及其 ESI provenance、BF58 alias、same-key old Conn 最終釋放，若 SPEC 真正要求再獨立精確派工。 |
| Server 待開發 | 兼容 Client 的各 key/port/marker 與階段業務 response；不能只憑 helper return1 判斷客戶端已確實送出或 Server 已回應。 |
| 跨 Task 待整合 | T02 framing、T03 S2C 0x13/list/choice UI 與 E82 的初始封包證據需分開引用；不能將 opcode 與 frame marker 混用。 |
| 待遊玩驗證 | 需同 KR 版本的每 Conn socket trace、Connect return、post-recv、首包與首回覆；目前缺原版 Server 同 session capture，runtime/wire-first 仍 U。 |

本檔是額外增量研究資料，原 E56/S00 RR-0005 **ACCEPTED 保持不變**；T01 FULL-PASS、GAP-NET-0002、SPEC 與實際可玩驗收各自依原正式程序判定。
