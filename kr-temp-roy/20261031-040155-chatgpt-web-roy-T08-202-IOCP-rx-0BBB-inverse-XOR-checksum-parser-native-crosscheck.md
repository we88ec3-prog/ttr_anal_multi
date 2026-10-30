# T08-202 — BIN-first 勘誤：Client RX 0x807B40 原生確認 0x0BBB、逆向XOR與checksum

**研究者** chatgpt-web roy；2026-10-31 04:01:55 Asia/Taipei，KR，接續未完T08-202，不另開T08-203。
**第一手證據** 原始 `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32 .text VA=0x401000, raw=0x400，真code raw=VA−0x400C00；本輪直接對原生PE `objdump -d -M intel --start-address ...`核對0x806DC0–0x806E32、0x807B40–0x807E43、0x807E50–0x807E78。無Client runtime、封包抓取或原版Server source。

**被交叉核對的新增勘誤** [T08-202 非零 TX 6-byte header及逐byte XOR原生算法](20261031-035954-chatgpt-web-roy-T08-202-nonzero-frame-XOR-checksum-corrected-native-algorithm.md)，Git blob **c971ba55de04120379eeb622bee2c03a1988a8ef**。原始舊T08-202 03:32稿（blob 0da7938fc496735c29df384303ae496e9c1e67a6）只證明TX出現 `0x7D810BBB`中間常數及模糊XOR/checksum，未確認真正header高位被覆寫；本輪由另一個RX函式提供獨立反證與相同格式的實際解析者。**T01 LEGACY-MAPPING-001仍NEEDS_FIX，T08-202仍INCOMPLETE**。

## 1. 真RX IOCP callback → parser，辨別RX與TX OVERLAPPED

前輪已確認的CIocpNetwork vtable+4=0x806CF0 使用 `GetQueuedCompletionStatus`，若成功且transferredBytes>0，完成通知的OVERLAPPED與`Connection+0xA030`相等則走RX（TX另於+0xA050）。同一Connection*的偏移+0x18作RX緩衝view。

~~~asm
806DC0 8B 4D DC                   mov ecx,[ebp-0x24]        ; bytesTransferred
806DC3 3B CE                      cmp ecx,esi               ; ESI=0
806DC5 75 1D                      jne 0x806DE4
806DE4 8D B8 30 A0 00 00          lea edi,[eax+0xA030]     ; RX OVERLAPPED
806DEA 3B D7                      cmp edx,edi
806DEC 0F 85 8B 00 00 00          jne 0x806E7D              ; TX candidate
806DF8 39 B0 AC A0 00 00          cmp [eax+0xA0AC],esi     ; Connection gate
806DFE 0F 84 2C FF FF FF          je 0x806D30
806E04 8D 50 18                   lea edx,[eax+0x18]       ; RX buffer view
806E07 50                         push eax                 ; Connection*
806E08 E8 33 0D 00 00             call 0x807B40             ; RX frame parser
806E0D 85 C0                      test eax,eax
806E12 74 0F                      je 0x806E23
806E14 8B 13                      mov edx,[ebx]             ; Network vptr
806E16 8B 52 14                   mov edx,[edx+0x14]
806E19 50                         push eax
806E1C FF D2                      call edx
~~~

只能證正常條件下存在此Client解碼器，不代表原版Server每次都送此marker或該函式直接是遊戲業務handler。

## 2. 真RX marker分派：0x0BBB=6-byte checksum frame，0x1A68=4-byte plain

~~~asm
807BB0 0F B7 33                   movzx esi,word [ebx]      ; L=payload size
807BB5 66 3B F1                   cmp si,cx                 ; reject L==0
807BB8 0F 84 5F 02 00 00          je 0x807E1D
807BBE BA 00 10 00 00             mov edx,0x1000
807BC3 66 3B F2                   cmp si,dx
807BC6 0F 87 51 02 00 00          ja 0x807E1D              ; reject >4096
807BD4 0F B7 4B 02                movzx ecx,word [ebx+2]    ; marker
807BDD C7 44 24 20 04 00 00 00   mov [esp+0x20],4         ; default header=4
807BE5 66 3B CA                   cmp cx,0x2633
807BEA C7 44 24 18 01 00 00 00   mov [esp+0x18],1         ; 2633 special mode
807BF2 C7 44 24 20 08 00 00 00   mov [esp+0x20],8
807BFC BA BB 0B 00 00             mov edx,0x0BBB
807C01 66 3B CA                   cmp cx,dx
807C04 75 12                      jne 0x807C18
807C06 C7 44 24 1C 01 00 00 00   mov [esp+0x1C],1         ; enable XOR/checksum
807C0E C7 44 24 20 06 00 00 00   mov [esp+0x20],6         ; header=6
807C18 BA 68 1A 00 00             mov edx,0x1A68
807C1D 66 3B CA                   cmp cx,dx
807C20 74 0A                      je 0x807C2C
807C22 BA D7 22 00 00             mov edx,0x22D7
807C27 66 3B CA                   cmp cx,dx
807C2A 75 08                      jne 0x807C34
807C2C C7 44 24 20 04 00 00 00   mov [esp+0x20],4
807C34 8B CE                      mov ecx,esi              ; length
807C36 8B 74 24 20                mov esi,[esp+0x20]       ; header
807C3A 03 CE                      add ecx,esi
807C3C 3B C8                      cmp ecx,eax              ; available>=L+header?
807C3E 0F 8F 96 01 00 00          jg 0x807DDA              ; else wait/return
~~~

| marker u16 (little-endian) | 此函式的header size | 行為邊界 |
|---|---:|---|
| **0x0BBB** | **6** | 此函式的inverse-XOR和16-bit checksum驗證 |
| **0x1A68** | 4 | 原始payload複製路 |
| **0x22D7** | 4 | 此函式同樣採4-byte原樣payload，後續語義未確定 |
| **0x2633** | 8 | 特殊 0x7C XOR + 0x727190 helper，完整壓縮/解壓契約仍待T02 |
| 其他值 | 預設4 | 本分支在marker分派處不直接拒絕，但下游是否接受不能據此宣稱 |

所以原TX稿中`0x7D810BBB`的高兩bytes`81 7D`不會被0x0BBB成功frame當作固定DWORD magic：RX明確依**WORD [frame+2] == 0x0BBB**選6-byte header，另讀WORD [frame+4]做checksum。

## 3. 接收端實際逆XOR與checksum，精確印證送出端

對marker==0x0BBB，`edi=ebx+6`是encoded body起始。正常分支：

~~~asm
807D2C 83 7C 24 1C 00            cmp [esp+0x1C],0         ; XOR flag
807D31 74 44                      je 0x807D77
807D33 8A 07                      mov al,[edi]             ; encoded[0]
807D35 34 B6                      xor al,0xB6              ; original[0]
807D37 0F B6 C8                   movzx ecx,al
807D3C 89 54 24 1C               mov [esp+0x1C],edx      ; first checksum
807D40 BA 01 00 00 00            mov edx,1
807D45 88 44 24 2C               mov [esp+0x2C],al        ; decoded[0]
807D49 3B F2                     cmp esi,edx              ; if L<=1 bypass loop
807D4B 76 19                     jbe 0x807D66
807D50 8A 04 3A                  mov al,[edx+edi]          ; encoded[i]
807D53 32 44 14 2B               xor al,[esp+edx+0x2B]   ; decoded[i-1]
807D57 42                        inc edx
807D58 88 44 14 2B               mov [esp+edx+0x2B],al   ; decoded[i]
807D5C 0F B6 C0                  movzx eax,al
807D5F 66 03 C8                  add cx,ax                 ; checksum low WORD
807D62 3B D6                     cmp edx,esi
807D64 72 EA                     jb 0x807D50
807D66 66 39 4B 04               cmp word [ebx+4],cx       ; compare checksum u16
807D6A 75 13                     jne 0x807D7F              ; skip packet delivery
807D70 8D 4C 24 2C               lea ecx,[esp+0x2C]
807D74 51                        push ecx                  ; decoded data
807D7A E8 D1 00 00 00            call 0x807E50             ; packetNode payload copy
~~~

發送端0x807830的每byte規則：
- `encrypted[0]=original[0]^0xB6`
- `encrypted[i]=original[i-1]^original[i]`,  i>=1；
- `checksum=sum(original) & 0xFFFF`。

此接收端對等實作：
- `original[0]=encrypted[0]^0xB6`
- `original[i]=encrypted[i]^original[i-1]`；
- `sum(original) & 0xFFFF == LE16(frame+4)` 時進入0x807E50。

兩組**獨立Client native函式**同時對上marker0x0BBB／header6／首byte XOR B6／相鄰byte還原／checksum word，強化了先前只憑送出函式的靜態模型。**這是本地程式碼的交叉驗證，非封包實測或原版Server允許條件的全部還原。**

### checksum不匹配時的精確負證據

`807D6A jne 0x807D7F`跳過`807D70 push decoded`與`807D7A call 807E50`，因此不會由本分支將bad-checksum payload複製到新packetNode。下一步`807D7F`後仍執行擬定的cursor進位`807DB2..807DC9`，所耗數據量為`L+headerSize`；不是由這一個條件跳轉就能聲稱socket必然斷線、重發或Server端ACK。

## 4. 下游只到packetNode，不可直接聲稱遊戲UI結果

~~~asm
807E50 55 8B EC                  push ebp; mov ebp,esp
807E53 81 FE 00 10 00 00       cmp esi,0x1000
807E59 76 06                   jbe 0x807E61
807E61 8B 45 08                mov eax,[ebp+8]       ; source
807E64 56                      push esi              ; L
807E65 50                      push eax              ; bytes
807E66 8D 4F 08                lea ecx,[edi+8]       ; dest PacketNode+8
807E69 51                      push ecx
807E6A E8 61 5D 09 00          call 0x89DBD0
807E72 89 77 04                mov [edi+4],esi      ; PacketNode len
807E75 B0 01                   mov al,1
807E78 C2 04 00                ret 4
~~~

`0x807B40` 先以cursor/length限制、marker及checksum判斷，再通過0x807E50把解碼結果放到後續packet-node memory；這**不是**T08的26/81遊戲handler、也不直接是場景更新結果。更上層network virtual+14和T02 dispatcher須分開核對。

## 5. 可交接的數學測試向量（獨立Python round-trip，非抓包）

|原始payload|預期0x0BBB frame|16-bit checksum|
|---|---|---|
|`10`|`01 00 BB 0B 10 00 A6`|0010|
|`10 20`|`02 00 BB 0B 30 00 A6 30`|0030|
|`0A 00 44 33 22 11`|`06 00 BB 0B B4 00 BC 0A 44 77 11 33`|00B4|

獨立Python依兩段native指令數學等價模型已做1、2、6、119 bytes輸入的encode/decode往返，皆通過；**不是原版Client現場封包capture**。T02在Server parser實作前應自行以更大範圍做原生＋實際資料一致性驗收，尤其packet斷片、混合marker、錯誤碼與session handshake。

## 6. 本研究不代表T08-202完結

**已確認Client**：送出0x807830非零轉換成len+0BBB+checksum+XOR、接收0x807B40辨識相同格式且逆轉換並驗checksum、合格內容複製成PacketNode。`0x807B40` 還支持其它marker，需與T02交接。

**Client待逆向**：Actor record P+4/P+8其餘alias/間接writer、命令26／81與owner/controller清理一致性、真正S2C封包域與場景可見結果；mode0/fallback/非0處理後的IOCP錯誤和多connection/lane；marker0x2633具體算法、0x22D7和unknown marker語義。

**Server待開發**：僅根據Client可證的wire契約設計接收/回覆；Client RX支援某種marker不等於原版Server按同一業務規則運作。**跨功能**：T02網路與dispatcher、T06/T07/T14場景、S00規格、T01原生驗證；**待遊玩驗證**與實際I/O completion獨立。

**狀態：T08-202 INCOMPLETE，T01 LEGACY-MAPPING-001 NEEDS_FIX；沒有修改舊FAILED原稿或聲稱FULL-PASS。**
