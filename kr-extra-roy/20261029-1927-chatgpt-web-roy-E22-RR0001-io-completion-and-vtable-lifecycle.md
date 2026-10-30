# E22 — RR-0001／RR-0004：transport vtable 安裝、pending-send 計數與 IOCP completion 分流（BIN-first）

研究日期：2026-10-29 Asia/Taipei；跨 Task extra/roy1 原稿。原始 `Tartaros.bin` 為 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪在容器直接重新計算。raw↔VA .text: `VA=raw+0x400C00`；.rdata: `raw=VA-0xBD2000+0x7D0600`。不執行原遊戲、不修改 BIN。

工作依據：E19–E21 原稿及 S00 `research/requests/index.json`。E22 開工比較時 main `594c079f6332677301e60baba775d1b691f42e35`（extra/roy1 ahead27, behind1），RR-0001/0004 尚未由 owner 提交/接受。本文件是跨 Task 支援，不更改 T02 原稿、RR 狀態或 main。

## 第一輪（重大新發現）：E21 vtable 的實際建構和發布

```asm
8046D7 push 0x5c
8046D9 call 0x891268       ; allocate object
8046F1 push esi
8046F2 call 0x803D60       ; object initialization
8046F7 mov dword ptr [esi],0xC51748
8046FD mov ecx,esi
80470A mov edx,[ecx]
80470C mov eax,[edx+8]
80470F mov [0xFBA854],ecx  ; publish singleton/interface receiver
804715 call eax            ; initialize via vtable +8
```

`.rdata` 原始 bytes，`0xC51748`（raw `0x84FD48`）連續 method targets：
- slot 0 `0x806670`
- slot +4 `0x806CF0`（completion worker 候選，下文確認其 I/O branch）
- slot +8 `0x806850`
- slot +0x0C `0x8068B0`（WSASend wrapper）
- slot +0x10 `0x8069A0`

故 E21 `0x804B5A call [vptr+0x0C]` 並非只有猜測函式型別：同一啟動路徑先確實 `mov [esi],0xC51748` 並發布到全域 `[0xFBA854]`。仍要將動態替換、析構與重設視為未知，不能說所有執行時刻保證同一 vptr。

## 第二輪：send wrapper 的精確回傳及 in-flight accounting

```asm
804B21 cmp dword ptr [esi+0xA028],0
804B28 je 0x804C4B
804B2E mov eax,[esi+0xA0B8]
804B36 jg 0x804C4B          ; positive count stops issuing another send
804B3C mov eax,[esi+0xA028]
804B42 mov ecx,[0xFBA854]
804B4A mov edx,[edx+0x0C]
804B52 lea eax,[esi+0x5020]
804B5A call edx
804B5C test eax,eax
804B5E jne 0x804B7C
804B61 call 0x8063E0       ; zero return: flush pending nodes
```

```asm
8068D1 cmp dword ptr [esi+0xA0A8],0
8068DE lea eax,[esi+0xA050]   ; send OVERLAPPED
8068FC mov [eax+0x18],edi     ; WSABUF.buf
806905 mov [ecx],edx          ; WSABUF.len
806912 call dword ptr [0xBD25B8] ; WSASend
806920 cmp eax,-1
806925 call dword ptr [0xBD25CC] ; WSAGetLastError on SOCKET_ERROR
80692D cmp edi,0x3E5             ; WSA_IO_PENDING
806933 je 0x806961
80695A xor eax,eax                ; nonpending error => 0
806967 push esi                   ; pointer to connection+0xA0B8
806968 call dword ptr [0xBD2284]
806970 mov eax,2                  ; pending accepted
806980 push esi
806981 call dword ptr [0xBD2284]
806989 mov eax,1                  ; immediate success
806995 or eax,-1                  ; invalid/blocked gate
```

這建立了 `[conn+A0B8]` 在成功/accepted-pending 時受原生 API 更新的事實；`0x804B36` 以 >0 gate 控制同連線再送。**仍須透過 import-name 實際對映方可正式把 `0xBD2284` 命名成 InterlockedIncrement；當前只直接證明「同一 import 以 conn+A0B8 pointer 為參數並於兩個 accepted branches 呼叫」。**

## 第三輪：IOCP completion 首次具體辨認 send OVERLAPPED 分支與對稱計數調整

vtable `+4→0x806CF0` 的 loop 透過 `0xBD2274` import 取 completion，回傳 packet/overlapped 及 completion key，再將通知連到具體 connection：

```asm
806D6F push -1                 ; infinite wait argument
806D71 lea ecx,[ebp-0x20]     ; returned OVERLAPPED*
806D75 mov ecx,[0xFE33B8]     ; completion port handle
806D7B lea edx,[ebp-0x1C]     ; completion key
806D7F lea eax,[ebp-0x24]     ; transferred bytes
806D83 push ecx
806D84 call dword ptr [0xBD2274]
806D8C je 0x806ECF            ; unsuccessful completion path
806DC0 mov ecx,[ebp-0x24]     ; transferred byte count
806DE4 lea edi,[eax+0xA030]   ; recv OVERLAPPED
806DEA cmp edx,edi
806DEC jne 0x806E7D
806E08 call 0x807B40          ; receive-parser path
```

**發送完成 path 是接收 OVERLAPPED 以外的 branch，且需要 `[ebp-0x20]` 是否等於 `conn+0xA050` 的物件區分：**

```asm
806E7D ...                   ; other successful completion branch
806EAB cmp [eax+0xA028],esi  ; pending-send buffer length
806EB1 seta cl
806EB4 mov [eax+0xA024],cl   ; update has buffered bytes flag
806EBA mov edx,[ebp-0x1C]   ; connection
806EBD add edx,0xA0B8
806EC3 push edx
806EC4 call dword ptr [0xBD227C] ; counter update after completion
806ECA jmp 0x806D30
806ECF mov ecx,[ebp-0x20]   ; unsuccessful completion
806EDD lea edx,[eax+0xA030] ; recv OVERLAPPED
806EE3 cmp ecx,edx
806EE7 lea edx,[eax+0xA050] ; send OVERLAPPED
806EED cmp ecx,edx
806EEF jne 0x806F00
806EF1 add eax,0xA0B8
806EF6 push eax
806EF7 call dword ptr [0xBD227C] ; decrement-like counter operation
806F00 mov eax,[eax+0xA0B8]
806F08 jne 0x806D30          ; if still >? zero test is explicit
806F13 mov edx,[edx+0x24]   ; virtual close/release path
806F1A call edx
806F1F mov [eax+0xA0A8],1   ; terminal-ish flag
```

`0x806E7D` 處需要把上游分支與 byte count movement 完整展開才可聲稱送出成功的每 byte buffer drain 精確規則，尤其不能把 `0x806EC4` 的 import 操作未核名就標為完整已確認的 decrement API。可確認的重大新鏈是：**vtable 安裝→buffered send vcall→WSASend accepted increments→completion loop 以 OVERLAPPED 辨認 receive/send→計數更新與錯誤 close gate**。

### 具體與 E21 的界線修正

E21 僅證可能 vtable target；E22 補原生 vptr 安裝/發布與 completion loop。依然不能將 `WSA_IO_PENDING`、queued completion、同步完成視為實際 wire delivery order 的完整測試證據；Windows completion 回報和應用層 Server 回覆是不同狀態。也尚未從 segmented `0xFE3368` consumer 追至 socket: E20 的 producer 指標集合獨立於本次 local buffer output，不要將它們強行接合。

### 第三輪補強：成功 send completion 的精確 OVERLAPPED 比較及 buffer drain

```asm
806E7D lea edi,[eax+0xA050]         ; send OVERLAPPED
806E83 cmp edx,edi                  ; edx = completion OVERLAPPED
806E85 jne 0x806D30                 ; unrelated completion => skip
806E8B add [ebx+0x28],ecx           ; global successful send byte metrics
806E8E inc dword ptr [ebx+0x38]    ; global completion count
806E91 cmp [eax+0xA0AC],esi
806E97 je 0x806EAB
806E99 lea esi,[eax+0x501C]         ; local framed staging structure
806E9F mov edi,ecx                  ; bytes completed
806EA1 call 0x8077B0               ; local buffer advance/drain function (semantic provisional)
806EA6 mov eax,[ebp-0x1C]          ; current connection
806EA9 xor esi,esi
806EAB cmp [eax+0xA028],esi         ; remaining buffered length
806EB1 seta cl
806EB4 mov byte ptr [eax+0xA024],cl ; has buffered bytes flag
806EBA mov edx,[ebp-0x1C]
806EBD add edx,0xA0B8
806EC3 push edx
806EC4 call dword ptr [0xBD227C]   ; matching in-flight counter update
```

這將 E22 原本保留的「`0x806E7D` 上游細節待展開」補成更明確的成功送出完成路徑：**只有 OVERLAPPED 指向 connection+0xA050 才處理；依本次 completed byte count 呼叫 `0x8077B0`；重新計算 connection+0xA024；隨後更新 A0B8 計數。** 仍未在此段反組譯 `0x8077B0` 全部內部細節，因此「從傳送緩衝確實刪除多少 bytes」須再由該函式作完整確認。

## 進度與下一段 E23

- **RR-0001 Client 待逆向**：每個 connection 的首筆 frame builder 呼叫者、first WSASend；收包第一個 frame 及 dispatch 的 exact opcode/order；IOCP completion 成功-send branch 精細 buffer 刪除規則。
- **RR-0004 Client 待逆向**：`A02C` alias writer、fallback 實際條件與最終 wire 格式，含 807830 checksum/encoder 接收對照。
- **Server 待開發**：相容 frame、認證交換及錯誤處理，不能自原生 Client 猜原 Server policy。
- **跨功能待整合**：T02 first connect ↔ T03 login result ↔ T03/T05 game handoff。
- **待遊玩驗證**：需要原 Client/新 Server 實際傳輸與錯誤重試測試；未進行 runtime。
- 本段第一輪新見 vptr 安裝與發布；第二輪 send return/inflight 確認；第三輪 completion send/recv 分流閉環。沒有假稱整體 RR/T01 FULL-PASS/S00 接受。

### 原始 BIN 重現指令

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x8046d7 --stop-address=0x804720 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x804b21 --stop-address=0x804b80 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x8068b0 --stop-address=0x8069a0 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x806cf0 --stop-address=0x806f2e Tartaros.bin
```

僅推本跨 Task 原稿到 extra/roy1，main 和正式 RR 台帳不修改。
