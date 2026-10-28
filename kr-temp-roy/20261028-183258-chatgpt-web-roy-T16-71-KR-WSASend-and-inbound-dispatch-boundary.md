# KR T16-71 — 出站 WSASend 與入站業務分派邊界（BIN-first）

- 研究人員：`chatgpt-web roy`；僅 KR；本次原件 `/mnt/data/Tartaros.bin`、`/mnt/data/Tartaros.exe` 唯讀、未啟動、未 patch。
- BIN：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本次以 `sha256sum` 實際驗證。
- PE32 `.text`: VA 0x401000、raw 0x400；**僅 `.text`** 地址 `raw=VA-0x400C00`。IAT 屬其他 section，不能套此規則。以 `objdump -D -Mintel -b pei-i386 -m i386` 直接反組譯 BIN，另 `objdump -p` 核對 import 名稱。
- 基準 T16-69/70：`RequestStartScenario(n) → 0x4AA4D0 → [FBA854] vtable+0x10 (0x8069A0) → 0x8060D0/0x806060 → connection+A074 queue → 0x8061A0 → 0x807A70/0x807830 → connection send buffer`。此鏈各 gate 有條件，非執行 trace。

## 1. 第 1 輪：重大新證據，直接確認作業系統 WSASend 呼叫點

### 1.1 Import／原生指令對齊

PE import table 的 `WS2_32.dll` 記錄：`[0x00BD25B8]=WSASend`、`[0x00BD25BC]=WSARecv`、`[0x00BD25D0]=WSASocketA`；這裡對照 API 名稱依 **BIN PE import table**，不是猜測。使用小端 4-byte IAT 地址在 `.text` 搜索，分別找到 `0x806912`、`0x806A4C`、`0x806B7C` 的 indirect call 指令。搜尋結果只代表字節命中，以下透過反組譯確認它們是完整指令。

```asm
8068b0: push ebp
8068b6: mov edi,DWORD PTR [ebp+0xc]     ; candidate buffer pointer
8068bb: test edi,edi
8068bd: je 0x806993
8068c3: mov edx,DWORD PTR [ebp+0x10]    ; candidate byte count
8068c6: test edx,edx
8068c8: je 0x806993
8068ce: mov esi,DWORD PTR [ebp+0x8]     ; connection pointer
8068d1: cmp DWORD PTR [esi+0xa0a8],0
8068d8: jne 0x806993
8068de: lea eax,[esi+0xa050]            ; WSASend overlapped storage
8068fc: mov DWORD PTR [eax+0x18],edi   ; WSABUF.buf
806905: mov DWORD PTR [ecx],edx        ; WSABUF.len
806907: mov edx,DWORD PTR [esi]        ; socket
806909: push ecx                       ; LPWSAOVERLAPPED
80690a: push edx                       ; SOCKET
806912: call DWORD PTR ds:0xbd25b8    ; WSASend
806920: cmp eax,0xffffffff
806925: call DWORD PTR ds:0xbd25cc    ; WSAGetLastError (import table to verify if cited)
80692d: cmp edi,0x3e5                 ; 997, WSA_IO_PENDING
806933: je 0x806961
806958: xor eax,eax                   ; error result 0
806961: add esi,0xa0b8
806967: push esi
806968: call DWORD PTR ds:0xbd2284
806970: mov eax,0x2                   ; pending result 2
80697a: add esi,0xa0b8
806980: push esi
806981: call DWORD PTR ds:0xbd2284
806989: mov eax,0x1                   ; immediate-success result 1
806993: ...                          ; invalid gate result -1
```

**精確參數佈局：** 此函式先將 `connection+0xA050` 清為零，設定 `+0xA068`（即 overlap base+0x18）指向 payload、`+0xA064`（base+0x14）為長度，符合由 `WSABUF { ULONG len; CHAR* buf; }` 指向臨時 `+0xA064` 的方式。`[connection]` socket handle。`WSASend` 的 `WSABUF`、計數1、zero flags、bytes-sent pointer、overlapped、completion routine 0 由原始 push 順序確認。由此**直接證實存在原版 Client 的 Winsock 寫出呼叫**，但不等於特定 Scenario 請求每次必定穿越全部 gate。

### 1.2 vtable+0x0C 與主循環發送觸發的交叉閉合

以 `.rdata` VA `0xC51748` 對應 raw `0x852D48`（`.rdata` VA `0xBD2000`, raw `0x7D0600`）讀出 vtable：

| slot | native target | 作用／限制 |
|---|---|---|
| +0x0C | `0x8068B0` | **已確認** 直接 `WSASend` |
| +0x10 | `0x8069A0` | T16-69 已確認 queue 入口 |
| +0x14 | `0x806A00` | **已確認** 直接 `WSARecv` |

`0x804AD6` 及 `0x805228` 是 `0x8061A0` 的 **direct call sites**，均讀 connection+0xA0AC 判斷後嘗試 drain queue。`0x804B42` 從 `[FBA854]` 取得物件，`0x804B4A` 取 `[vtable+0x0C]`，帶 connection、`[connection+0x5020]`、`[connection+0xA028]` 和返回資訊的地址作參數呼叫，因 vtable 已解析，此 call target = `0x8068B0`。

```asm
804ac8: cmp DWORD PTR [esi+0xa0ac],0
804ad5: push esi
804ad6: call 0x8061a0
804b21: cmp DWORD PTR [esi+0xa028],0
804b2e: mov eax,DWORD PTR [esi+0xa0b8]
804b34: test eax,eax
804b36: jg 0x804c4b                     ; outstanding send, do not re-enter
804b3c: mov eax,DWORD PTR [esi+0xa028]
804b42: mov ecx,DWORD PTR ds:0xfba854
804b48: mov edx,DWORD PTR [ecx]
804b4a: mov edx,DWORD PTR [edx+0xc]
804b4d: lea edi,[ebp-0x14]
804b50: push edi
804b51: push eax                       ; length
804b52: lea eax,[esi+0x5020]
804b58: push eax                       ; send buffer
804b59: push esi                       ; connection
804b5a: call edx                       ; vtable+0x0c → 0x8068B0 → WSASend
804b5c: test eax,eax
804b60: push esi
804b61: call 0x8063e0                   ; failure/backpressure auxiliary routine
804b66: mov ecx,DWORD PTR ds:0xfba854
804b6e: mov edx,DWORD PTR [eax+0x24]
804b74: call edx                       ; virtual shutdown/disconnect candidate
```

**新的有界閉環：** 先前 `0x807A70`／`0x807830` 把 frame 放進 connection 內部傳送緩衝；主循環 `0x804AD6` 嘗試 drain outbound queue，而 `0x804B3C...0x804B5A` 在有待送長度及無 outstanding send 條件下呼叫 `WSASend`。這使「Client 原生具有從出站佇列到 OS 送出 API 的靜態路徑」達成 **原生已確認**。仍沒有執行流量，無法確認 server 實收、ACK、重傳或封包數量。

### 1.3 反向 WSARecv 與解析器消費者

`0x806A00` 以 `WSARecv` 填充連線內 `+0xA030` 相關 OVERLAPPED／WSABUF，`0x806A4C call [0xBD25BC]`；接收完成處理 `0x806DE4` 判定 callback overlapped 是否等於 `[connection+0xA030]`，符合後 `0x806E08 call 0x807B40` 解析已讀入的 frame。這提供 `WSARecv → completion handling → frame parser` 的靜態連結。

```asm
806a0a: lea eax,[esi+0xa030]
806a22: mov ecx,DWORD PTR [esi+0x5018]
806a2b: mov DWORD PTR [eax+0x18],ecx
806a3b: mov DWORD PTR [ecx],0x1000
806a41: mov edx,DWORD PTR [esi]
806a4c: call DWORD PTR ds:0xbd25bc    ; WSARecv
806de4: lea edi,[eax+0xa030]
806dea: cmp edx,edi
806e04: lea edx,[eax+0x18]
806e08: call 0x807b40                 ; frame parse
806e14: mov edx,DWORD PTR [ebx]
806e16: mov edx,DWORD PTR [edx+0x14]
806e1c: call edx                      ; on-complete consumer candidate
```

### 1.4 `0x807B40` 解框後的兩條 app 分派入口

```asm
807bd4: movzx ecx,WORD PTR [ebx+0x2] ; frame kind
807bfc: mov edx,0xbbb
807c18: mov edx,0x1a68
807c22: mov edx,0x22d7
807c34: mov ecx,esi                  ; frame payload length
807c3a: add ecx,esi                  ; register esi now header size
807c3c: cmp ecx,eax                 ; complete-frame guard
807d33: mov al,BYTE PTR [edi]
807d35: xor al,0xb6                 ; decode 0x0BBB mode
807d50: mov al,BYTE PTR [edx+edi]
807d53: xor al,BYTE PTR [esp+edx+0x2b]
807d66: cmp WORD PTR [ebx+0x4],cx   ; checksum compare
807d7a: call 0x807e50               ; payload preparation helper
807d83: cmp DWORD PTR [eax+4],0
807d8f: push eax
807d90: call 0x804310                ; candidate application dispatch A
807d9e: mov ecx,DWORD PTR [ecx+0xa080]
807da4: push ecx
807da5: push eax
807da6: call 0x489920                ; candidate application dispatch B
807dad: mov edi,eax
807dad: ...
807db2: movzx edx,WORD PTR [ebx]
807db5: add edx,DWORD PTR [esp+0x20]
```

此處因局部暫存器在不同 CFG 分支切換，**嚴禁**將 `0x807C34` 單獨解讀為任何跨分支的惟一總長度公式；須看完整 CFG。兩條分派入口目前僅為 **app-level candidate**；`0x804310`、`0x489920` 尚未向下閉合 Quest handler，不能將它們命名為 Quest ACK/notification。

## 2. 控制與資料流（限定靜態可達性）

```text
RequestStartScenario(n) [既有 T16-69/70]
→ local message [40 00 | scenarioLow16]
→ virtual+10 = 8069A0 → 8060D0 → connection+A074 queue
→ 8061A0 (called 804AD6 or 805228) → frame encoder 807A70 or 807830
→ connection buffered frame
→ main loop 804B21: +A028 > 0 and +A0B8 <= 0
→ [FBA854] vtable+0C = 8068B0
→ [0xBD25B8] = WSASend
→ immediate success 1 / pending 2 / error 0 / rejected gate -1

WSARecv [0xBD25BC] ← 806A00
→ completion identifies +A030
→ 806E08 → 807B40 decode/validate frames
→ conditional call 804310 or 489920 (app-level dispatch candidates)
→ Quest-specific response handler / UI: unknown
```

## 3. 玩家情境及 Server 實作邊界

| 玩家情境 | 本地 gate | C→S | S→C | Quest/NPC/UI | 相容 Server 待開發 |
|---|---|---|---|---|---|
| 開始 Scenario(n) | FBA798==0、channel、queue、frame、send length/overlapped gates | **從 local tag `0x0040` payload 有原生靜態可達至 WSASend 路徑**；實際發包次數/執行狀態 unknown | 已確認 generic WSARecv→framing→app candidate，**未對到 scenario response** | unknown | 須以業務分派及狀態寫入確定請求及回覆；不可假裝 ACK 已證 |
| 教學完成 | unknown | unknown | unknown | unknown | 依實際 Quest/Scenario notifications 規格實作 |
| Quest16 → Quest15 可接 | unknown | unknown | generic receive only | unknown | 解鎖條件與狀態資料規格待原生 Client 業務 handler |
| 點擊 NPC 接取 Quest15 | unknown | unknown | generic receive only | unknown | 接取／拒絕 ACK 格式待查 |
| 重登 | P2 未查 | unknown | unknown | unknown | 不推測原版保存策略 |

## 4. 實際研究輪次、限制與下一入口

- **第 1 輪：達標。** 本段從此前未知的 connection buffer flusher，首次靜態閉合至 **原生 WSASend IAT/API**，並以精確 vtable+0x0C 對齊主循環發送者；另確認 `WSARecv`、completion、frame parser 和後續兩個 application dispatcher candidate。三輪規則下 `T16-71-2`、`T16-71-3` **未啟動（因首輪已達重大新發現）**。
- 對 Quest 業務 opcode：雖已有本機 message `0x0040` 和 frame kind，**仍欠 app dispatcher/semantic opcode 相互證明**；宣稱它是最終 wire opcode 必須在 receiver/message boundary 另行確認。
- 真正 `Quest16` 完成、`Quest15` 可接、NPC 點擊接受/拒絕，仍 **unknown**；絕不從一般 socket 路徑推得任務狀態。
- 下一段 T16-72 P0 優先 `0x804310`、`0x489920` 的 parser、message domain 和 Quest/Scenario consumer，平行找 Quest UI accept producer 及對應 C→S packet；server writer/DB 非 T16 逆向目標。
- 本次未改動 BIN/EXE、其他 Task、owner、catalog；**GitHub 未 Commit/Push**。