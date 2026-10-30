# E26 — RR-0001／RR-0005：選服切線的兩個 connect 與最早可定位 enqueue candidate（KR BIN-first）

研究日：2026-10-29 Asia/Taipei。原始 KR `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新計算確認。原件只讀、未執行。VA to raw：.text `VA−0x400C00`，.rdata `VA−0xBD2000+0x7D0600`。開工基準 main `610a822b15346c9e0b69edd4e104c2076f2b59ac`（extra/roy1 ahead32 behind2）；八筆 RR 仍 QUEUED。此為 extra/roy1 跨 Task 補證，不變更 RR owner、T02/T03 研究原稿或主線。

## 第一輪：從初始 socket 建立者向上追到兩種 connection handoff

此前 E21–E25 得到 transport vtable `0xC51748`、pending builder `0x8061A0`、serial / worker sender `0x804A40` / `0x805190`、IOCP completion `0x806CF0`；未找到初次送出的上游 enqueue。

本輪直接由 vtable `0xC51748` 的索引表讀出：
```text
+0x0C = 0x8068B0 ; WSASend
+0x10 = 0x8069A0 ; connection lookup + optional enqueue
+0x14 = 0x806A00 ; queue/arm receive
+0x18 = 0x806AD0 ; allocate and create/connect socket
+0x20 = 0x806F80 ; transport operation invoked by higher-level handoff
```
上列 target 來自原始 .rdata bytes，不靠符號或臆測名字。特別注意：`0x4957C0` vtable `+0x18` 對應的是 `0x806AD0`，**不是**直接向 OS `connect` 呼叫的 caller；真正 OS socket connect 由 `0x806AD0` 内 `0xBD25C4` 間接呼叫。

### 0x495610 的第一種連線

```asm
4956E0 mov ecx,[0xFBA854]
4956F2 mov eax,[ecx]
4956F4 mov edx,[eax+0x20]
4956F7 push 1
4956F9 push 0
4956FA call edx
4956FC mov ecx,[0xFBA854]
495704 mov edx,[eax+0x20]
495707 push 1
495709 push 2
49570B call edx
495743 mov ecx,[0xFBA854]
49574E mov eax,[eax+0x18] ; connect virtual
495751 push 2              ; final param
495753 push 1
495755 push 0x20DF         ; endpoint/service selector
49575A push edx            ; host/address context
49575B call eax
49575D mov esi,eax         ; connection pointer
49575F cmp esi,edi
495761 jne 0x495781
495781 mov ecx,[0xFBA854]
495789 mov eax,[edx+0x14] ; receive-arm virtual
49578C push esi
49578D call eax
495794 mov [ebx+0xBF60],esi
```
在這條分支，完成建立後會先對新 connection 呼叫 vtable `+0x14`，並把 pointer 保存於 `context+0xBF60`。其建立前也會呼叫 vtable `+0x20` 做舊連線/slot 狀態操作。不能從 `0x20DF` 自行得出部署 port 政策（需 `0x806AD0` 參數來源和具體 call ABI）。

### 0x4957C0 的第二種連線 handoff

```asm
4957D0 mov ecx,[0xFBA854]
4957D8 mov edx,[eax+0x18]
4957E0 push 2
4957E2 push 0
4957E4 push 0x20E0
4957E9 push ebx
4957EA call edx            ; first connection
4957F2 push 2
4957F4 push 2
4957FA mov edx,[eax+0x18]
4957FD push 0x20DE
495802 push ebx
495803 call edx            ; second connection
495805 mov ebx,eax
495807 test edi,edi
495809 je 0x4959B0        ; first failed
49580F test ebx,ebx
495811 je 0x49597E        ; second failed
495817 cmp [esi+0xBF60],0
495820 call 0x44D680
495832 mov eax,[esi+0xBF60]
495839 call 0x8063E0     ; flush old connection pending nodes
495843 push 2
495848 mov word [ebp-0x42],0x7E
49584C mov ecx,[esi+0xBF60]
495852 push edx
495853 call 0x8060D0     ; 2-byte local enqueue, old connection
495858 mov eax,[esi+0xBF60]
49585E mov [eax+0xA0B0],1
495868 mov [esi+0xBF60],0
```
`0x007E` 是**舊 connection 的兩 byte payload candidate**，此時尚未被完整 framing 或 WSASend 檢驗；絕不可宣稱新 connection 的 first opcode，也不可將它當正式 S2C handshake。

## 第二輪：固定長度 0x39 本地 payload 透過 vtable+0x10 queue

同一 `0x4957C0` 成功分支，在處理舊 connection 後建構 stack 上一個零初始化、混用 16-bit 欄位、固定長度的結構，從 `0x404BA0` 返回之資料來源複製多段欄位：

```asm
49587D xor eax,eax
495884 mov word [ebp-0x40],1
4958B3 call 0x404BA0
4958B8 mov edx,[eax+0x67E0]
4958BE mov [ebp-0x3E],edx
4958C1 call 0x404BA0
4958C6 push 0xA
4958C8 add eax,0x67E4
4958D4 call 0x893FFE
4958D9 call 0x404BA0
4958E0 add eax,0x67FA
4958EC call 0x893FFE
4958F1 mov byte [ebp-0x26],1
4958F5 call 0x404BA0
4958FA mov dl,[eax+0x6898]
495900 mov [ebp-0x25],dl
495903 call 0x404BA0
495908 add eax,0x6899
495914 call 0x893B59
495919 add esp,0x2C
49591C call 0x404BA0
495921 mov ecx,[eax+0x68A0]
495927 mov [ebp-0x1F],ecx
49592A mov ecx,[0xFBA854]
495932 mov edx,[edx+0x10]
495935 push 0x39
495937 lea eax,[ebp-0x40]
49593A push eax
49593B push 0
49593D call edx              ; vtable +0x10, 57-byte local enqueue
49593F mov ecx,[0xFBA854]
495947 mov edx,[eax+0x14]
49594A push edi
49594B call edx              ; arm receive for connection A
49594D mov ecx,[0xFBA854]
495955 mov edx,[eax+0x14]
495958 push ebx
495959 call edx              ; arm receive for connection B
49595B mov [esi+0xBF64],edi
495962 mov [esi+0xBF68],ebx
```

此處 `push 0` 是 connection/key argument，**不是**「沒有 socket」或 payload 零號 opcode。 `push 0x39` 是 vtable enqueue API 的**本地 payload 長度**；編碼後 4/6-byte framing 可能改變 wire bytes 數；不得把 `0x39` 當完整 wire frame。固定頭 `word=1` 與多個欄位來源是可追溯的 native 客戶端資料，不足以自行推「該封包就是所有登入流程第一個 C2S」。

### vtable+0x10 下游如何找 connection

`0x8069A0` 的實際內部：
```asm
8069A4 mov eax,[ebp+8]        ; connection lookup key
8069B1 lea ecx,[esi+0x18]     ; transport's tree
8069B7 call 0x8438C0         ; keyed search
8069BC mov eax,[ebp-4]
8069BF cmp eax,[esi+0x1C]     ; end sentinel
8069C5 mov ecx,[eax+0x10]    ; resolved connection
8069CC xor eax,eax            ; no connection => failure
8069D4 mov eax,[ebp+0x10]    ; payload length
8069D7 test eax,eax
8069DB mov eax,1              ; empty enqueue special success
8069E6 mov edx,[ebp+0xC]     ; payload pointer
8069E9 push eax              ; payload length
8069EA push edx              ; payload bytes
8069EB call 0x8060D0        ; enqueue into resolved connection
```
`0x8060D0` 的入列操作先定位 `+0xA0A4` 閾值 `0x12C`，然後按 `0x1000` 單一 payload 上限拷貝入 queue 物件，透過 `0x806060` 在鎖內插入 `conn+0xA074` linked list，使 `conn+0xA078` 加一並將 `conn+0xA024` 寫為 1。這比僅找到 socket send 排程器更接近業務資料 producer 的 **source → enqueue → queue count** 端到端有界證據。

## 第三輪：socket 建立不是天然等同首包，且 receive arm 與 send scheduler 需分流

vtable +0x18 的 `0x806AD0`:
```asm
806B0E mov ecx,[0xFBA858]
806B16 call 0x805950         ; obtain/create connection object
806B29 mov [ebx+0xA0B4],2
806B33 mov [ebx+0xA080],eax ; call param metadata
806B65 call dword [0xBD25A8] ; local endpoint lookup/convert
806B7C call dword [0xBD25D0] ; socket create (import mapping to confirm)
806B8A mov [ebx],eax        ; handle
806B8C call dword [0xBD25C4] ; connect-like API
806B92 cmp eax,-1
806B95 jne 0x806C16
806BF4 mov esi,[0xFBA858]
806BFB call 0x805AF0       ; connection cleanup on error
806C7B call 0x806620
806C87 call dword [0xBD2278] ; bind socket to completion port
```
依 Windows socket 呼叫參數形狀，`0xBD25C4` 高可信為 `connect`，但此報告未逐項印證 import directory 符號，因此寫成「connect-like」並提供 ABI 與參數相鄰地址。後續 `0x806A00` 將 `WSABUF.len=0x1000`、`WSABUF.buf=[conn+0x5018]`，呼叫 `0xBD25BC` WSARecv-like，成功/IO_PENDING 後走 `0x8065B0` 註冊 I/O；這和上述 enqueue 的來源/方向不同。

### 本段新確認的流程範圍

```text
0x4957C0 -> vtable+0x18 / 0x806AD0 => connection A + connection B
 (if both exist)
  -> previous conn +0xBF60 flush pending and enqueue 2-byte 0x007E
  -> build local 0x39 bytes with 0x404BA0 object-sourced fields
  -> vtable+0x10 / 0x8069A0 keyed lookup => 0x8060D0 enqueue
  -> conn+0xA074 linked-list, conn+0xA078 count / conn+A024 flag
  -> E25 0x804A40 or 0x805190 scheduler => 0x8061A0 builder
  -> E21 0x804B5A virtual => 0x8068B0 WSASend
  -> E22/E23 IOCP completion => bytes removed / next scheduler gate
```

中間 **具體是哪個 connection 被 key=0 解析、是否在同一 tick 被讀取及實際 first wire frame 是什麼**，仍無 runtime / complete tree lookup 相依條件確認。這是**有界 source-to-enqueue 和 socket-setup 關係**，不是「第一包完整證明」。

## 證據層級、RR 影響、下一段

- 已確認：vtable key/call placement、兩次 socket 連線 request 不同 selector、舊連線 enqueue 2-byte 0x007E、0x39-byte structure enqueue、connection linked-list 插入、receive arm callsites。
- 推測：0x20E0/0x20DE 是具體哪個 Server 類型、0x007E 的正式 wire opcode 與 0x39 的 handshake 名稱；不得升級為官方協定。
- 未解：connection key=0 tree mapping；0x4957C0 的確切 UI/0x13 上游；0x495610 另一連線第一包；E8/000F 與 S2C 初步回覆；A02C indirect alias writes；是否 login/角色選擇切線真實使用這條 path。
- RR-0001（T02 P0）：取得明確的 candidate business first enqueue 和 send-connection wiring，仍未滿足 per-connection first exchanged frame。
- RR-0005（T02 P0）：有兩條 connection create / old release/new receive-arm 的有界鏈，仍缺精確與 0x13 result／UI gate 的關係。
- RR-0004（T02 P0）：可復用 framed queue / socket chain，但 fallback runtime 條件未解。
- Client 待逆向：上述 handler/upstream/connection ownership；Server 待開發：必須實作以證據已確認之 wire 前提，未知 backend account/policy 不逆推；跨功能待整合：T02 connection × T03 auth/selection × T05 world handoff；待遊玩驗證：原版 Client+新 Server 的逐 socket pcap、最早出站 framing 與回覆順序。
- 三輪：第一輪 connect/old conn 0x7E；第二輪 0x39 架構與 vtable +0x10 enqueue；第三輪 socket setup 和 WSARecv arm 接合、嚴格保留 first-wire gap。屬重大新有界功能鏈。

### 重現指令

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x495610 --stop-address=0x4957c0 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4957c0 --stop-address=0x49597e Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x8069a0 --stop-address=0x8069f5 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x806ad0 --stop-address=0x806cd7 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x806060 --stop-address=0x8060cc Tartaros.bin
```
