# T08-202 BIN-first 勘誤：GetQueuedCompletionStatus 對送出OVERLAPPED的對應、部分完成扣除ring、pending/refcount；預設mode=2

- 研究者：chatgpt-web roy；建立日期 2026-10-31 03:45 Asia/Taipei。延續**同一個未完成T08-202**。原始KR /mnt/data/Tartaros.bin，12,472,320 bytes，SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**；PE native .text raw=VA−0x400C00。未執行/patch遊戲，所有原生機器碼以 objdump -d -M intel /mnt/data/Tartaros.bin --start-address ... 從正確PE節直接再核；匯入名稱取原件 objdump -p。
- 同次更正前置新稿：[T08-202 output ring至WSABUF本體](20261031-034400-chatgpt-web-roy-T08-202-native-output-ring-to-WSABUF-WSASend-identity-correction.md)。之前33:09稿所稱「ring→WSASend WSABUF尚未建立」已由該稿**在正常狀態/guards**補齊；本稿再沿同一WSASend實際[conn+A050]OVERLAPPED找IOCP completion回調及byte consumption，並釐清非同步計數器import身份。
- 本稿能證**Client原生的有條件提交/成功完成消費功能**；不證指定packet已在runtime成功送到OS、對端已收到，或原版Server/玩家場景採什麼決策；T01 LEGACY-MAPPING-001仍 NEEDS_FIX，T08-202整體未達全部靜態目標。

## I. 從真的IAT辨識工作迴圈與回收函式，避免不正確API名稱

以原始PE Import Table直接核對，地址並非外推：
- **IAT 0xBD2274 = KERNEL32.dll!GetQueuedCompletionStatus**。
- **IAT 0xBD227C = KERNEL32.dll!InterlockedDecrement**，**不是**SetEvent；在send completion上的計數器更新不可寫成event通知。
- **IAT 0xBD2284 = KERNEL32.dll!InterlockedIncrement**，WSASend提交成功／pending路上使用。
- **IAT 0xBD224C = KERNEL32.dll!EnterCriticalSection；0xBD2248 = LeaveCriticalSection**。
- **IAT 0xBD25B8 = WS2_32.dll!WSASend**。

CIocpNetwork primary vtable 0xC51748 +0x04 = **0x806CF0**，有一個帶GetQueuedCompletionStatus的worker/completion loop。該slot不是+0x0C的WSASend，也不是+0x10的enqueue；不同virtual slots應分開。

~~~asm
; this=CIocpNetwork* ECX; EBX=this， ESI=0
806CF0 55 8B EC                         push ebp;mov ebp,esp
806D04 8B D9                            mov ebx,ecx
806D6F 6A FF                            push -1                 ; INFINITE timeout
806D71 8D 4D E0                         lea ecx,[ebp-0x20]     ; &OVERLAPPED* out
806D74 51                               push ecx
806D75 8B 0D B8 33 FE 00                mov ecx,[0xFE33B8]     ; completion port HANDLE
806D7B 8D 55 E4                         lea edx,[ebp-0x1C]     ; &completionKey out
806D7E 52                               push edx
806D7F 8D 45 DC                         lea eax,[ebp-0x24]     ; &bytesTransferred out
806D82 50                               push eax
806D83 51                               push ecx
806D84 FF 15 74 22 BD 00                call [0xBD2274]       ; GetQueuedCompletionStatus
806D8A 85 C0                            test eax,eax
806D8C 0F 84 3D 01 00 00                je 0x806ECF           ; failure path separate
806D92 8B 45 E4                         mov eax,[ebp-0x1C]   ; completionKey, Connection* candidate
806D95 83 F8 01                         cmp eax,1
806D98 0F 84 90 01 00 00                je 0x806F2E           ; special exit/stop signal
806D9E 8B 55 E0                         mov edx,[ebp-0x20]   ; actual returned OVERLAPPED*
806DA1 3B D6                            cmp edx,esi           ; NULL?
806DA3 75 1B                            jne 0x806DC0          ; nonnull handles rx/tx
806DC0 8B 4D DC                         mov ecx,[ebp-0x24]   ; bytesTransferred
806DC3 3B CE                            cmp ecx,esi
806DC5 75 1D                            jne 0x806DE4
806DE4 8D B8 30 A0 00 00                lea edi,[eax+0xA030] ; rx OVERLAPPED
806DEA 3B D7                            cmp edx,edi
806DEC 0F 85 8B 00 00 00                jne 0x806E7D          ; if not rx, test tx
806E7D 8D B8 50 A0 00 00                lea edi,[eax+0xA050] ; **tx OVERLAPPED**
806E83 3B D7                            cmp edx,edi
806E85 0F 85 A5 FE FF FF                jne 0x806D30          ; unmatched completion, loop
~~~

**此分支的精確語義限制**：上述tx branch在前面有成功return與nonzero transferred byte count的條件；不應把GetQueuedCompletionStatus失敗或zero-byte event當正常成功送出。INFINITE超時意味wait不靠簡單輪詢固定週期，但不證thread schedule/OS執行先後。

## II. 和WSASend的OVERLAPPED是同一物理指標，而非兩組offset看似類似

先前同次原生B1稿已核：
- 0x804B5A/0x8052AC呼叫Network vtable +0x0C=0x8068B0；
- 0x8068B0以[EBP+8]=Connection*，用其+0x5020和+A028建WSABUF；
- 0x8068DE lea eax,[esi+0xA050]，傳給WSASend as lpOverlapped（0x8068F3 push eax），以及0x8068FC/0x806905設置連線內WSABUF +A068/+A064。

真PE片段：
~~~asm
8068DE 8D 86 50 A0 00 00                lea eax,[esi+0xA050]  ; OVERLAPPED* submitted
8068F3 50                               push eax
8068FC 89 78 18                         mov [eax+0x18],edi     ; WSABUF.buf
806905 89 11                            mov [ecx],edx          ; WSABUF.len
806909 51                               push ecx
80690A 52                               push edx               ; socket HANDLE
806912 FF 15 B8 25 BD 00                call [0xBD25B8]       ; WSASend

806E7D 8D B8 50 A0 00 00                lea edi,[eax+0xA050] ; same connection!
806E83 3B D7                            cmp edx,edi           ; completed OVERLAPPED exact equality
~~~

此**exact pointer equality**加上固定的source Connection*，足以證明成功IOCP tx完成路有歸屬同一個Connection內先前提交的WSASend OVERLAPPED；不需要依序號、原版Server或runtime packet capture臆測函式關聯。但允許Conn在不同時間提交不同bytes；不能從靜態碼證明這次取回的是特定0x000A actor entry的那一次OS完成事件。

## III. 真正把已完成 bytes從output ring扣除／整理，並恢復 pending flag

從0x806D84成功完成、且0x806E83確認tx overlap後，ECX保存[EBP−0x24]的 transferredBytes（上一節）。以[Connection+A0AC]為guard，正常路把 Connection+0x501C 的ringView和 transferred bytes交給 **0x8077B0**：

~~~asm
806E8B 01 4B 28                       add [ebx+0x28],ecx     ; Network-side byte metric
806E8E FF 43 38                       inc [ebx+0x38]         ; Network-side completion metric
806E91 39 B0 AC A0 00 00              cmp [eax+0xA0AC],esi  ; conn state guard
806E97 74 12                          je 0x806EAB
806E99 8D B0 1C 50 00 00              lea esi,[eax+0x501C] ; same output ringView
806E9F 8B F9                          mov edi,ecx           ; transferredBytes
806EA1 E8 0A 09 00 00                 call 0x8077B0
806EA6 8B 45 E4                       mov eax,[ebp-0x1C]    ; restore Connection*
806EAB 39 B0 28 A0 00 00              cmp [eax+0xA028],esi  ; remaining ring count
806EB1 0F 97 C1                       seta cl
806EB4 88 88 24 A0 00 00              mov byte [eax+0xA024],cl ; pending=(len>0)
806EBA 8B 55 E4                       mov edx,[ebp-0x1C]
806EBD 81 C2 B8 A0 00 00              add edx,0xA0B8
806EC3 52                             push edx
806EC4 FF 15 7C 22 BD 00              call [0xBD227C]       ; **InterlockedDecrement**, not SetEvent!
806ECA E9 61 FE FF FF                 jmp 0x806D30          ; keep processing completions
~~~

其中 **0x8077B0** 先取得ring mutex [ESI]，檢查transferred >=0且 <= pending (ring+0x500C)，再：
~~~asm
8077B0 53                            push ebx
8077B1 8B 1E                         mov ebx,[esi]           ; ring critical-section
8077B3 53                            push ebx
8077B4 FF 15 4C 22 BD 00             call [0xBD224C]       ; EnterCriticalSection
8077BA 85 FF                         test edi,edi
8077BC 78 5B                         js 0x807819           ; reject negative
8077BE 8B 86 0C 50 00 00             mov eax,[esi+0x500C] ; current bytes
8077C4 3B C7                         cmp eax,edi
8077C6 72 51                         jb 0x807819           ; reject transferred > buffered
8077C8 2B C7                         sub eax,edi
8077CA 89 86 0C 50 00 00             mov [esi+0x500C],eax ; **Connection+A028 remaining**
8077D0 74 3E                         je 0x807810          ; if zero, reset cursor
8077D2 8B 86 04 50 00 00             mov eax,[esi+0x5004] ; ring end pointer
8077E1 2B C7                         sub eax,edi           ; end' = end - transferred
8077EF 89 01                         mov [ecx],eax          ; ring cursor = adjusted
8077F6 50                            push eax              ; length-derived remaining memcpy window
8077F7 8D 44 37 04                   lea eax,[edi+esi+4]   ; src = ring payload + transferred
8077FC 52                            push edx              ; dst = ring payload start
8077FD E8 CE 63 09 00                call 0x89DBD0         ; copy/compact bytes
807805 53                            push ebx
807806 FF 15 48 22 BD 00             call [0xBD2248]       ; LeaveCriticalSection
80780C B0 01                         mov al,1
807810 8D 4E 04                      lea ecx,[esi+4]       ; zero-count reset branch
807813 89 8E 04 50 00 00             mov [esi+0x5004],ecx
807819 53                            push ebx
80781A FF 15 48 22 BD 00             call [0xBD2248]
807820 32 C0                         xor al,al
~~~

**精確不變條件**：同一output ring的buffer長度在frame writer新增成功時上升；由send完畢的IOCP bytesTransferred進入0x8077B0時下降，對仍有待送bytes的情況整理實體byte位置；再根據剩餘count重設Connection+0xA024 pending flag。0x8077B0拒絕負值或大於當前count，也未因此把OS已接受的bytes全部視為「全部已送完」；**部分完成會保留剩餘byte**。當剩餘count=0會調整cursor並返回al=0，這個布林值在已解0x806EA1 caller並沒有被測試，不能單以al==0說IOCP錯誤。

**其他分支需區分**：0x806CF0也有rx completion OVERLAPPED=conn+A030，0x806E04 call 0x807B40處理接收資料；0x806ECF是GetQueuedCompletionStatus返回false後的另一條錯誤分支，可能用InterlockedDecrement/close處理等待；絕不能把所有GQCS結果都當成tx byte consumption。

## IV. 新補正：連線建立時mode不是plain預設；真初始化=2，不能把0x1A68當必然第一個wire前綴

~~~asm
805D02 C6 86 2C A0 00 00 02      mov byte [Connection+0xA02C],0x02  ; constructor default=2
806202 0F BE 86 2C A0 00 00      movsx eax,byte [Connection+0xA02C]
806218 74 15                     je 0x80622F                    ; only mode 0 direct 807A70
806223 E8 08 16 00 00            call 0x807830                  ; mode !=0 tries transform
806228 85 C0                     test eax,eax
80622A 75 23                     jne 0x80624F                   ; successful transform
80622F ...                        fallback to 807A70 when mode0 or transform fails
~~~

搜索本原始PE .text區對A02C displacement四bytes **2C A0 00 00**，找到兩個詞彙站點（0x805D04的寫入、0x806205的讀取），未見另一個直接disp32取用；但不能排除**基址指標別名、指向struct的批次copy或外部初始化**。可以確認：這條0x805CA0新Connection建構路徑本地mode=2，而非0；若沒有中途改寫且nonzero 807830成功，那麼該Connection本地buffer送出時採 **+6 XOR/checksum** 而非mode0的**+4 [len][1A68] plain frame**。這是**初始化值＋分支條件的靜態推導**，仍不等於原版Server官方只接受這種格式。

此項對server相容性有用：即使已核明文0x000A來源與mode0下的1A68 marker，**不能**假設遊戲每個新連線預設都直接傳送1A68明文frame；T02需保留具體session/握手/選mode的相容條件，檢查XOR/checksum精確算法和fallback。

## V. IOCP成功/pending/失敗的區別與必須保留的未知

|邊界|原生已見|不得外推|
|---|---|---|
|WSASend 0x806912|CIocpNetwork+0x0C把Connection+5020 bytes、Connection+A028 len裝入conn+A064/A068 WSABUF，conn+A050 OVERLAPPED|不證 Server收到、packet逐個完成|
|WSASend返回>=0|0x80697A path call InterlockedIncrement(conn+A0B8)，ret=1|不是OS完成已被本地consumer處理|
|WSA_IO_PENDING 997|0x806961 path同樣InterlockedIncrement(conn+A0B8)，ret=2|pending不是錯誤也不是同步傳完|
|Other WSASend error|0x806935～0x80695E log/ret0|不可自動claim queued bytes一定被重試|
|GQCS TRUE & nonzero bytes, OVERLAPPED=conn+A050|0x806E8B metrics→0x8077B0扣除/compact→[conn+A024]=(count>0)→InterlockedDecrement(conn+A0B8)|不代表能證任何特定Server回覆|
|GQCS rx OVERLAPPED=conn+A030|0x806E04 0x807B40另一接收處理路|不是同一次send；T02需追後續opcode|
|GQCS FALSE|0x806ECF分支，含InterlockedDecrement/closure候選|尚未完成所有error code、競態或回收順序驗證|

注意IAT名字：0xBD227C確切是InterlockedDecrement；若其他文件描述為SetEvent，本稿直接提供原始PE的反證；本地有真正SetEvent import **0xBD20D0**，被其他connection loops使用，兩者不能混寫。

## VI. Client/Server/跨Task分類、交付與未完研究

本輪將T08-202的**Client send-path「封包由生成→network queue→ring→WSASend→成功IOCP completion對應same Connection ring byte consumer」**擴大到有條件閉合。精確流程：

~~~text
controller FE38D0: 6+5N bytes
 -> CIocpNetwork vtable+10 8069A0 connection tree id=0
 -> Connection outgoing queue +0xA074
 -> 8061A0 successful frame/transform into Connection+0x5020
 -> write += Connection+0xA028 (alias ring+0x500C)
 -> 804A40 or 8051B0 scheduler
 -> CIocpNetwork virtual +0x0C 8068B0
 -> conn+A064/A068 WSABUF len/pointer
 -> WSASend(conn.socket, WSABUF, OVERLAPPED conn+A050)
 -> on successful GQCS with same conn+A050:
    806CF0 -> 806E7D -> 806E99 -> 8077B0
 -> subtract transferredBytes, compact unconsumed ring,
    set conn+A024 pending according to remaining, decrement conn+A0B8
~~~

**Client仍待逆向**：Actor record P+4/P+8其餘writer；命令26/81分支和controller的真正owner解除一致性；本地0x000A的每個5-byte欄位與任一S→C狀態回覆對應；nonzero XOR/checksum算法的全條件；GQCS失敗及部分IOCP提交/重試的所有分支；connectionId0 lane/會話歸屬。**Server待開發**：相容Server依T02 Client wire完整鑑別實作接收/回應，不回推原版 Server內部判斷。**跨Task待整合**：T02 socket/framing與dispatch，T06/T07/T14 scene/actor，S00要求，T01嚴格審核。**待遊玩驗證**：真正packet capture和server相容測試不能拿靜態輸出取代。

本輪屬有實質新證據的階段性交付，**T08-202繼續INCOMPLETE**；T01 LEGACY-MAPPING-001保留NEEDS_FIX，無S00 RR被本稿擅改為ACCEPTED，也不能把T08新局部修訂升格T01 FULL-PASS。
