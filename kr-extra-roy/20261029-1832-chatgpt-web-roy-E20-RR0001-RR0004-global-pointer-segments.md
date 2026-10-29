# E20 — RR-0001/RR-0004 全域分段指標儲存與 per-connection 佇列 drain（KR BIN-first）

研究日期：2026-10-29（Asia/Taipei），工作線 extra/roy1。原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes，已直接重新雜湊。PE .text VA = raw + `0x400C00`。未執行/修補原始 Client。最新 main 比較基準 `5cb495f4561833e0a123bbded14b76266ac1f201`，RR-0001、0004 維持 QUEUED；此跨 Task 原稿不認領、不修改台帳。

## 第一輪：分段儲存 producer 對照，重大新增

E19 記述 `0x8061A0` 成功建構 frame 後會將指標交予以 `0xFE3368` 為根的全域結構；本輪證實**同一結構有另一個入口 `0x8063E0`**，且它與 `0x8061A0` 的語意不同：

### 0x8061A0 後半段 producer

```asm
8062C6 a1 74 33 fe 00        mov eax,[0xFE3374]
8062CB 8b 0d 70 33 fe 00     mov ecx,[0xFE3370]
8062F0 8b 3d 70 33 fe 00     mov edi,[0xFE3370]
8062F6 03 3d 74 33 fe 00     add edi,[0xFE3374]
80630C 8b 0d 68 33 fe 00     mov ecx,[0xFE3368]
806312 83 3c b1 00           cmp dword [ecx+esi*4],0
806318 6a 10                 push 0x10
80631A e8 49 af 08 00        call 0x891268
806326 8b 15 68 33 fe 00     mov edx,[0xFE3368]
80632C 89 04 b2              mov [edx+esi*4],eax
80632F a1 68 33 fe 00        mov eax,[0xFE3368]
806334 8b 0c b0              mov ecx,[eax+esi*4]
806337 83 e7 03              and edi,3
80633A 8d 04 b9              lea eax,[ecx+edi*4]
806341 8b 55 ec              mov edx,[ebp-0x14]
806344 89 10                 mov [eax],edx
806350 01 35 74 33 fe 00     add [0xFE3374],esi
806356 29 35 7c 33 fe 00     sub [0xFE337C],esi
```

末尾兩指令的 `esi=1` 為 `0x80634B` 明確寫入。可見這是**以 index 拆分成 page slot 與 page 內 4-byte pointer** 的 segmented pointer storage。每 page 配置 `0x10` bytes，最多四個指標元素。這比將 `0xFE3368` 隨意稱為「發送 pool」更具體：實際上是共用分段指標容器，是否供 socket sender 消費尚未由此段證實。

### 新增第二個 producer：0x8063E0

```asm
806408 8b 75 08              mov esi,[ebp+8]          ; connection argument
80640B 8b 86 d4 a0 00 00     mov eax,[esi+0xA0D4]   ; synchronization handle
806412 ff 15 4c 22 bd 00     call dword [0xBD224C]   ; wait/lock related
806418 8b 86 74 a0 00 00     mov eax,[esi+0xA074]   ; list sentinel
80641E 8b 18                 mov ebx,[eax]           ; first linked node
806423 3b d8                 cmp ebx,eax
806425 0f 84 fe 00 00 00     je 0x806529           ; empty
80645B a1 80 33 fe 00        mov eax,[0xFE3380]
806460 8b 73 08              mov esi,[ebx+8]        ; node payload ptr
806467 ff 15 4c 22 bd 00     call dword [0xBD224C]  ; global lock
80646D c7 06 00 00 00 00     mov dword [esi],0
806473 c7 46 04 00 00 00 00  mov dword [esi+4],0
80647A a1 74 33 fe 00        mov eax,[0xFE3374]
8064A4 8b 3d 70 33 fe 00     mov edi,[0xFE3370]
8064AA 03 3d 74 33 fe 00     add edi,[0xFE3374]
8064C0 8b 0d 68 33 fe 00     mov ecx,[0xFE3368]
8064C6 83 3c b1 00           cmp dword [ecx+esi*4],0
8064CC 6a 10                 push 0x10
8064CE e8 95 ad 08 00        call 0x891268
8064DE 8b 15 68 33 fe 00     mov edx,[0xFE3368]
8064E4 89 04 b2              mov [edx+esi*4],eax
8064E7 a1 68 33 fe 00        mov eax,[0xFE3368]
8064EC 8b 0c b0              mov ecx,[eax+esi*4]
8064EF 83 e7 03              and edi,3
8064F2 8d 04 b9              lea eax,[ecx+edi*4]
8064F9 8b 55 f0              mov edx,[ebp-0x10]
8064FC 89 10                 mov [eax],edx
806503 01 05 74 33 fe 00     add [0xFE3374],eax     ; EAX=1 at 0x8064FE
806509 29 05 7c 33 fe 00     sub [0xFE337C],eax
80651B 8b 1b                 mov ebx,[ebx]           ; next pending node
806529 8b 8e 74 a0 00 00     mov ecx,[esi+0xA074]
806531 89 09                 mov [ecx],ecx
806539 89 49 04              mov [ecx+4],ecx
80653C c7 86 78 a0 00 00 00 00 00 00 mov [esi+0xA078],0
806550 8b 38                 mov edi,[eax]
806553 e8 b4 ac 08 00        call 0x89120C         ; free drained nodes
806565 8b 86 d4 a0 00 00     mov eax,[esi+0xA0D4]
80656C ff 15 48 22 bd 00     call dword [0xBD2248]  ; release lock
806583 c2 04 00              ret 4
```

兩條 producer 在全域 `0xFE3368/0xFE3374/0xFE337C` 的 index 算式、page 配置、pointer store、count 增減幾乎同構，但 `0x8063E0` 是**整批轉移 connection+0xA074 既有節點 payload，再將 list 歸零並清理節點**；不像 `0x8061A0` 先組新 frame。該段的 `[payload]`、`[payload+4]` 被重置為 0，但不能自行認定 payload type 是 WSABUF。

### 全域結構直接 displacement xref 覆蓋（僅原始 .text）

對原始 BIN 的 `0x400..0x7D0600` 可執行原始窗掃 little-endian 4-byte VA：
- `0xFE3368`：`0x80630E`, `0x806328`, `0x806330`, `0x8064C2`, `0x8064E0`, `0x8064E8`, `0x8071AE`。
- `0xFE3374`：`0x8062C7`, `0x8062F8`, `0x806352`, `0x80647B`, `0x8064AC`, `0x806505`, `0x8071C0`。
- `0xFE337C`：`0x806358`, `0x80650B`, `0x8071CC`。
- `0xFE3370`：`0x8062CD`, `0x8062F2`, `0x806481`, `0x8064A6`, `0x8071BA`。

這個直接位移引用覆蓋說明：`0x807120` 是全域結構初始化者（`0x8071AC` 將 `[0xFE3368]` 設零；`0x8071BE` 將 `[0xFE3374]` 設零），而且 **此處未出現具直接常數讀取 `0xFE3368` 的 socket consumer**。但**不能**由 direct-xref 不存在推出無 indirect consumer：可能通過容器指標、iterator、vtable 或 other module 訪問。

## 第二輪：確認 0x8068B0 實際 WSASend API 的 ABI，避免把 producer 視為 sender

```asm
8068B6 8b 7d 0c              mov edi,[ebp+0xC]       ; data buffer pointer
8068C3 8b 55 10              mov edx,[ebp+0x10]      ; byte length
8068D1 83 be a8 a0 00 00 00 cmp dword [esi+0xA0A8],0
8068DE 8d 86 50 a0 00 00     lea eax,[esi+0xA050]   ; OVERLAPPED
8068F3 50                    push eax
8068F7 8d 48 14              lea ecx,[eax+0x14]      ; WSABUF
8068FC 89 78 18              mov [eax+0x18],edi     ; WSABUF.buf
806905 89 11                 mov [ecx],edx          ; WSABUF.len
806909 51                    push ecx               ; WSABUF
80690A 52                    push edx               ; socket handle
806912 ff 15 b8 25 bd 00     call dword [0xBD25B8]  ; WSASend import
806920 83 f8 ff              cmp eax,-1
806925 ff 15 cc 25 bd 00     call dword [0xBD25CC]  ; WSAGetLastError on SOCKET_ERROR
80692D 81 ff e5 03 00 00     cmp edi,0x3E5          ; WSA_IO_PENDING
```

這裡 `0x8068F3` 是 **OVERLAPPED**，`0x806909` 是 **WSABUF**，呼叫前 `[connection+0xA050+0x18]` 寫 buf pointer，`[connection+0xA050+0x14]` 寫 len，確認正確參數層次。現有資料**還沒有**從 `0xFE3368` 項目讀出 `(buf,len,connection)` 並 invoke `0x8068B0` 的端到端消費者。

## 第三輪：受限的結果與研究責任

局部已確認：
- `0x8061A0`: 封包建構 + pending node 處理 + 分段儲存 producer。
- `0x8063E0`: 批次清空 connection pending list 並將 payload pointer 交接到同一全域分段結構。
- `0x807120`: 首次建立/初始化共用分段結構與同步資源。
- `0x8068B0`: 真正 Winsock WSASend wrapper 的獨立 byte-length/WSABUF/OVERLAPPED 使用。

沒有證明：
1. 全域 pointer segments 真正的 consumer / descriptor type（應查 direct-struct pointer callsite，而非只掃 literal VA）。
2. connection 到 socket sender 的 sequence/order。
3. RR-0001 的 first frame 與 RR-0004 的 fallback 真實 wire 規格。
4. 為何同一個 connection 同時有 `0x8061A0`（可能做 frame）和 `0x8063E0`（批次移轉）兩條 producer；必須找原生 callers。

**特別更正**：本段不可稱 E19 的全域 `0xFE3368` 已連到 `WSASend`；也不可聲稱沒有找到 direct-xref 就是沒有 consumer。本段將「建立了兩個 producer 的共用資料結構與 socket API ABI」視為完整而有界的重大原生新發現，尚未完成 T02 RR acceptance。

### 待續 E21

- 從 `0x8063E0` 的所有 direct E8 caller / potential virtual caller 出發，確認誰將 connection pending nodes 移到全域 segments。
- 從 `0xFE3364` 容器 manager、iterator virtual interface 追 **真正**取出 `0xFE3368` 的 pointer；特別留意 inlined access that operates on pointer passed as argument。
- 從 `0x8068B0` wrapper caller 反向追其 buf,len connection 來源（direct E8 call 查找 + vtable `0xC51748`）。
- 將 connection first request 依 RR-0001 契約定位；fallback 的前置錯誤與 wire type 仍需接到真實 write。

**分類**：Client 待逆向＝consumer/sender/first-frame；Server 待開發＝frame accept, error handling 需以原生收發為準；跨功能待整合＝T02 framing × T03 auth/handoff；待遊玩驗證＝沒有實際 pcap 或 Client↔Server 整合測試。

### 重現

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x8061e6 --stop-address=0x806380 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x8063e0 --stop-address=0x8065b0 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x807120 --stop-address=0x807220 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x8068b0 --stop-address=0x806965 Tartaros.bin
```

共用三輪規則：第一輪得到**第二 producer + 共享分段容器具體 index/store/cleanup**重大新增；第二輪核對實際 WSASend ABI；第三輪收斂實證與否證範圍。沒有把缺失線路自行補齊或假稱 RR 已完成。只推 extra/roy1，不變更 main 或 T02 原稿。
