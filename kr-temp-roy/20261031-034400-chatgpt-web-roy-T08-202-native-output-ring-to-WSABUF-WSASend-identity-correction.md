# T08-202 BIN-first 勘誤：同一 Connection 輸出 ring → WSABUF → CIocpNetwork::WSASend 的有條件實際 caller（真PE）

- 研究者：chatgpt-web roy，2026-10-31 03:44（Asia/Taipei）。KR T08-202 **同段延續，整體研究未完成**。
- 原始唯讀證據：/mnt/data/Tartaros.bin，12,472,320 bytes，SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**；本輪本機sha256sum驗證。PE .text VA=0x401000/raw=0x400，code raw=VA−0x400C00；.rdata VA=0xBD2000/raw=0x7D0600。此次直接用原生PE的 objdump -d -M intel --start-address/--stop-address 解碼，**不再使用整檔raw0錯高0x400映射**；Import Table直接以 objdump -p 核。
- 前置來源（GitHub T08工作分支）：20261031-033042-chatgpt-web-roy-T08-202-CIocpNetwork-vtable-outbound-buffer-IOCP-queue-PE-BIN-correction.md（blob 9336f7fd3d1515ea9ee7fe185c0f8772d19c4fe3）、20261031-033209-chatgpt-web-roy-T08-202-IOCP-queue-drain-length-magic-XOR-frame-BIN-correction.md（blob 0da7938fc496735c29df384303ae496e9c1e67a6）。舊source/原T01 FAILED均保留。前稿尚未證output ring到WSABUF，本稿直接補完整的**pointer identity與兩個虛擬call site**。
- **完成界線**：只在已知connection/網路object vptr存活、packet被成功frame、connection guard允許提交時，證明相同ring字節範圍提交WSASend；此為Client靜態可達鏈，**不是**「Server收到封包／WSA completion成功」及原版Server協定決策。

## 1. 關鍵新事實：ring struct的+0x500C其實正是 Connection+0xA028

先前報告中：
- 0x8061A0以ESI=Connection*，建立ring writer參數 ECX/EDI=Connection+0x501C；0x807A70（mode0/fallback）與0x807830（nonzero-mode）以該 ring struct 操作capacity和cursor，增加 [ring+0x500C]，但尚未連到WSASend長度。
- 同樣的Connection*在2個outer loop中，以 [conn+0xA028]作WSASend資料長度，以conn+0x5020為資料位址。

**內存地址恒等式（這不是欄位offset碰巧相同）**：

~~~text
ring = (byte*)Connection + 0x501C
ring.bytes = ring + 4 = Connection + 0x5020
ring.count_at_500C = ring + 0x500C = Connection + (0x501C+0x500C) = Connection + 0xA028
~~~

並有下列**原生寫入端、讀取端以及constructor**交叉驗：

~~~asm
; 0x805CA0 Connection construction/initialization, ESI=Connection*
805CF6 8D 86 20 50 00 00       lea eax,[esi+0x5020]           ; outgoing contiguous bytes
805CFC 89 BE 1C 50 00 00       mov [esi+0x501C],edi           ; ring's critical section pointer
805D02 C6 86 2C A0 00 00 02    mov byte [esi+0xA02C],2        ; initialized mode=2
805D09 89 86 20 A0 00 00       mov [esi+0xA020],eax           ; separate explicit alias to payload bytes
805D15 89 9E 28 A0 00 00       mov [esi+0xA028],ebx           ; initial count 0
; 0x805F50 reset:
805F7F 89 9E 28 A0 00 00       mov [esi+0xA028],ebx           ; reset count 0
805F85 8D 86 20 50 00 00       lea eax,[esi+0x5020]
805F8B 89 86 20 A0 00 00       mov [esi+0xA020],eax           ; reset payload base
; 0x8061A0 caller of 0x807A70:
80622F 8B 45 F0                mov eax,[ebp-0x10]            ; queued packet copied payload
806234 8D BE 1C 50 00 00       lea edi,[esi+0x501C]          ; THIS ring address
80623A E8 31 18 00 00          call 0x807A70
; ring mode0 writer:
807AFA 01 9F 0C 50 00 00       add dword [edi+0x500C],ebx    ; = Connection+0xA028 += len+4
; ring nonzero mode writer, this ESI=Connection+0x501C:
807A1F 01 86 0C 50 00 00       add dword [esi+0x500C],eax    ; = Connection+0xA028 += len+6 on successful transformed path
~~~

此處「Connection+0xA028」不只從read site猜為待發長度，直接由兩個實際frame writer寫入；「Connection+0x5020」是ring的固定byte起點，且constructor/Reset設置了相同指標別名。0x807A70與0x807830分屬不同mode，但都會在真正成功加入buffer時更新同一欄位。前稿的「還未證明WSASend的精確WSABUF input pointer」可在**正常guard成功路**撤下；零長、fallback、ring容量不足等失敗路不能套用成功結論。

## 2. 兩個真正caller：先同Connection+queue讀取，後透過Network vtable+0x0C傳出ring指標及count

在0x804A40處理全域 [0xFBA858] connection pointer-vector內每個合格Connection*（ESI），另0x8051B0於同vector的指定index迭代；它們已在前份證據核到 direct E8 queue drain 0x8061A0。**本輪沿相同ESI到實際送出call前stack args**：

~~~asm
; 0x804A40，第一個outer scheduler
804AC3 8B 16                   mov edx,[esi_owner]           ; vector begin (ESI initially vector ptr)
804AC5 8B 34 82                mov esi,[edx+eax*4]           ; ESI=Connection*
804AC8 83 BE AC A0 00 00 00    cmp dword [esi+0xA0AC],0
804AD5 56                      push esi
804AD6 E8 C5 16 00 00         call 0x8061A0                  ; same Connection queue->ring
; send gate later:
804B21 83 BE 28 A0 00 00 00    cmp dword [esi+0xA028],0    ; bytes pending?
804B28 0F 84 1D 01 00 00       je 0x804C4B                   ; skip if zero
804B2E 8B 86 B8 A0 00 00       mov eax,[esi+0xA0B8]
804B36 0F 8F 0F 01 00 00       jg 0x804C4B                    ; additional outstanding guard
804B3C 8B 86 28 A0 00 00       mov eax,[esi+0xA028]         ; original ring count
804B42 8B 0D 54 A8 FB 00       mov ecx,[0xFBA854]           ; CIocpNetwork*
804B48 8B 11                   mov edx,[ecx]                 ; Network vptr
804B4A 8B 52 0C                mov edx,[edx+0x0C]           ; virtual target
804B4D 8D 7D EC                lea edi,[ebp-0x14]           ; output count variable
804B50 57                      push edi                     ; 4th arg
804B51 50                      push eax                     ; 3rd arg: count = Connection+A028
804B52 8D 86 20 50 00 00       lea eax,[esi+0x5020]
804B58 50                      push eax                     ; 2nd arg: conn+5020 bytes
804B59 56                      push esi                     ; 1st arg: connection*
804B5A FF D2                   call edx                      ; vptr+0x0C, CIocpNetwork->8068B0
804B5C 85 C0                   test eax,eax                  ; check result

; 0x8051B0，second indexed connection scheduler
805217 8B 34 B9                mov esi,[ecx+edi*4]          ; same Connection*
80521A 83 BE AC A0 00 00 00    cmp [esi+0xA0AC],0
805227 56                      push esi
805228 E8 73 0F 00 00         call 0x8061A0                  ; queue->ring
805273 83 BE 28 A0 00 00 00    cmp dword [esi+0xA028],0
80527A 0F 84 29 01 00 00       je 0x8053A9
805280 8B 96 B8 A0 00 00       mov edx,[esi+0xA0B8]
805288 0F 8F 1B 01 00 00       jg 0x8053A9
80528E 8B 86 28 A0 00 00       mov eax,[esi+0xA028]         ; count
805294 8B 0D 54 A8 FB 00       mov ecx,[0xFBA854]          ; Network*
80529A 8B 11                   mov edx,[ecx]
80529C 8B 52 0C                mov edx,[edx+0x0C]
80529F 8D 7D F4                lea edi,[ebp-0x0C]
8052A2 57                      push edi
8052A3 50                      push eax                     ; count
8052A4 8D 86 20 50 00 00       lea eax,[esi+0x5020]
8052AA 50                      push eax                     ; bytes
8052AB 56                      push esi                     ; connection
8052AC FF D2                   call edx
8052AE 85 C0                   test eax,eax
~~~

於前輪已獨立核實 CIocpNetwork RTTI / derived vptr C51748，該表+0x0C即0x8068B0，並且network全域[FBA854]初始化後可為該類物件。**兩組序列並非隨便在別函式找到一個send call**：它們和0x8061A0所取得的ESI是同一個Connection*，使用前後實際相同的+0xA028 count與+0x5020 bytes，且vtable slot及CIocpNetwork動態目標指針有另證。只要有效連線、非空ring、無outstanding guard阻擋、network.vptr仍為C51748，可形成條件性完整資料鏈。

## 3. 0x8068B0 將這組pointer/length實際建成WSABUF，呼叫WinSock WSASend

PE Import Directory核對：
- **IAT 0xBD25B8 = WS2_32.dll!WSASend**；
- **IAT 0xBD25CC** 是另個WinSock error API（要從IAT字串核對具體符號，原生片段僅判斷返回值997=WSA_IO_PENDING）；
- IAT 0xBD2248 / 0xBD224C = LeaveCriticalSection / EnterCriticalSection。

~~~asm
8068B0 55 8B EC                push ebp;mov ebp,esp
8068B6 8B 7D 0C                mov edi,[ebp+0x0C]           ; actual conn+0x5020
8068C3 8B 55 10                mov edx,[ebp+0x10]           ; actual conn+0xA028
8068CE 8B 75 08                mov esi,[ebp+8]              ; same Connection
8068D1 83 BE A8 A0 00 00 00   cmp dword [esi+0xA0A8],0    ; guard disabled/error state
8068DE 8D 86 50 A0 00 00      lea eax,[esi+0xA050]        ; per-conn OVERLAPPED base
8068FC 89 78 18                mov [eax+0x18],edi          ; [conn+A068] WSABUF.buf = conn+5020
8068FF 8D 45 0C                lea eax,[ebp+0x0C]
806903 6A 01                   push 1                       ; count of WSABUF
806905 89 11                   mov [ecx],edx               ; [conn+A064] WSABUF.len = conn+A028
806907 8B 16                   mov edx,[esi]               ; socket handle
806909 51                      push ecx                    ; &conn+A064
80690A 52                      push edx                    ; socket
806912 FF 15 B8 25 BD 00       call dword [0xBD25B8]      ; **WSASend**
806920 83 F8 FF                cmp eax,-1
806925 FF 15 CC 25 BD 00       call dword [0xBD25CC]      ; error query if -1
80692D 81 FF E5 03 00 00       cmp edi,0x3E5              ; WSA_IO_PENDING
806961 81 C6 B8 A0 00 00      add esi,0xA0B8            ; pending-branch interlocked operation
806970 B8 02 00 00 00         mov eax,2                   ; async pending status
80697A 81 C6 B8 A0 00 00      add esi,0xA0B8
806989 B8 01 00 00 00         mov eax,1                   ; call accepted/sync return
806993 ...                     failure -1
~~~

傳給OS的WSABUF len/pointer是**ring的實際欄位**，已不需以「待證 WSABUF 來源」描述這個條件性路徑。細節：EDI!=0、EDX!=0且[conn+A0A8]==0才下達call；WSASend不為-1（正常ret1）或返回-1且error==997（pending ret2）的路，和失敗ret-1不同。別把ret1/2誤解為官方Server已處理該封包，Windows IOCP的完成通知仍需追查。

## 4. 仍不能過度宣稱的幾件事

1. **[FBA854]可能換指標**（前稿已見初始化與不同reset），所以這是正確的動態vptr下可達函式鏈；不能假設每次session都有有效connectionId0。
2. output ring可彙集多個packetNode，可能一起提交；不能從這條靜態call鏈推出指定5-byte entry對應哪次單一WSASend completion或Server回覆。
3. nonzero-mode transform／mode0 +4字節 framing是否逐byte完整正確，仍要原生多分支驗證；這裡的確切輸出pointer/len與WSABUF是一手事實，但**尚無runtime wire capture**。
4. **WSASend只證OS提交的呼叫**，異步完成/部分傳送的ring扣除與重試需下游查驗；不能在此稿聲稱sent全部byte、Server收到或帳號/場景已更新。
5. 其餘T08-202主題：record P+4/+8其他alias writer、26/81移除/owner一致性、pair的特殊id與scene跨方向同步、遠端相容Server設計與T01審核仍未完成；不可拿本次完成的網路子鏈直接標 T08-202 完成。

## 5. 有界C++表達（名稱只有CIocpNetwork經RTTI，Connection及欄位為研究暫名）

~~~cpp
// Known memory alias, not a source-level class layout proof:
Connection* c;
RingView* ring = (RingView*)((uint8_t*)c + 0x501C);
assert(&ring->bytes[0] == (uint8_t*)c + 0x5020);
assert((uint8_t*)&ring->count == (uint8_t*)c + 0xA028); // count is at ring+0x500C

// once 8061A0 successfully appends a framed record:
c->pendingLength += framedLength; // under mode-specific guards
// later same-connection scheduler:
if (c->pendingLength != 0 && c->outstandingGuard <= 0 && additionalConnectionState) {
    network->vtable[3](network, c, (uint8_t*)c + 0x5020,
                       *(uint32_t*)((uint8_t*)c+0xA028), &bytesSent);
}
// vtable[3]=0x8068B0 when CIocpNetwork vptr=0xC51748;
// WSABUF.buf/len above are set at Connection+A068/+A064 and submitted to WSASend.
~~~

**玩家功能 / Server責任分界**：Client已證「controller生成header+5-byte entries → network queue → chosen frame ring → same Connection WSABUF → WSASend的條件性路徑」。Client待逆向：completion/partial bytes消費、各mode對wire framing、Actor其他writer與移除情境。相容Server待開發：依T02核實的wire格式實作接收與回覆，不能由Client本地0x000A擅稱Server官方opcode/回覆策略。跨功能：T02 packet/network、T06/T07場景與T01原生審核分開。**T08-202仍為階段性未完成，LEGACY-MAPPING-001仍 NEEDS_FIX。**
