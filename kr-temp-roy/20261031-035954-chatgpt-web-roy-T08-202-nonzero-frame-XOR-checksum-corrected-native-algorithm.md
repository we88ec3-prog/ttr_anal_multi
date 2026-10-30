# T08-202 BIN-first 根本勘誤：非零模式的 6-byte frame 真正為 [len, 0x0BBB, checksum]，不是完整 0x7D810BBB 常數

**來源及版本**：T08，KR Tartaros.bin，12,472,320 bytes，SHA256 \`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91\`（2026-10-31原始檔實際重新hash）；PE32 .text VA 0x401000 raw 0x400；**raw=VA−0x400C00**。原始PE節直接GNU objdump -d -M intel在 0x807830..0x807A6C、0x8061F6..0x80624F、0x807A70..0x807B19解碼；下面地址都是真VA。作者 chatgpt-web roy，2026-10-31 03:59:54 Asia/Taipei。僅Client靜態，沒有原版Server／動態封包。

**被修正的原稿**：\`kr-temp-roy/20261031-033209-chatgpt-web-roy-T08-202-IOCP-queue-drain-length-magic-XOR-frame-BIN-correction.md\`（Git blob \`0da7938fc496735c29df384303ae496e9c1e67a6\`）已確認模式非零時採0x807830、總長len+6並出現 \`0x7D810BBB\` 暫存立即值，但尚未解其被覆寫的字段與全部變換；其「6-byte + XOR/checksum」雖方向正確，**不能把立即數0x7D810BBB當作完整的發送frame固定DWORD**。本稿依實際write CFG精確更正；舊來源不刪不改，T01 FULL-PASS及T08-202整體完成狀態仍獨立。

## 1. 一手 0x807830 的輸入、長度、ring 擁有者

入口：this \`ECX\` 為 **RingView=Connection+0x501C**，\`[EBP+8]\`=指向原始payload的指標，\`[EBP+0xC]\`=原始payload byte長度 \`L\`；由已核 0x8061A0同一connection queue reader呼叫，且Connection建構於0x805D02把mode byte \`+0xA02C\` 初始化為 **2**。模式零直接入0x807A70；模式非零先進此函式，失敗回退0x807A70。

~~~asm
807848 8B 5D 08                    mov ebx,[ebp+8]           ; source
80784C 8B F1                       mov esi,ecx               ; ring=Connection+501C
807851 8B 7D 0C                    mov edi,[ebp+C]           ; L
807867 FF 15 4C 22 BD 00           call [BD224C]             ; EnterCriticalSection
80786D 8D 47 06                    lea eax,[edi+6]           ; framedLen=L+6
807887 3D 00 10 00 00              cmp eax,0x1000
80788C 0F 87 BB 01 00 00           ja 807A4D                ; fail if L+6>4096
807892 85 FF                       test edi,edi
807894 0F 84 B3 01 00 00           je 807A4D                ; fail zero-length
80789A 8B 96 0C 50 00 00           mov edx,[esi+500C]      ; ring queued length
8078A0 03 D0                       add edx,eax
8078A2 81 FA 00 40 00 00           cmp edx,0x4000          ; max occupancy 16384
8078A8 76 0C                       jbe 8078B6              ; otherwise fail
8078B6 8B 8E 04 50 00 00           mov ecx,[esi+5004]      ; ring cursor/write pointer
8078BC 8D 96 04 50 00 00           lea edx,[esi+5004]      ; ring end
8078CA 8D 46 04                    lea eax,[esi+4]          ; ring byte base
8078D3 3B C8                       cmp ecx,eax             ; cursor >= ring byte base?
8078D5 72 D3                       jb 8078AA
8078D7 3B CA                       cmp ecx,edx             ; cursor < end?
8078D9 73 CF                       jae 8078AA
8078DB 8B 95 F4 EF FF FF           mov edx,[ebp-100C]      ; cursor+L+6
8078E1 3B D0                       cmp edx,eax             ; end pointer >= base?
8078E3 72 C5                       jb 8078AA
8078E5 8D 86 04 50 00 00           lea eax,[esi+5004]
8078EB 3B D0                       cmp edx,eax             ; end pointer < upper end?
8078ED 73 BB                       jae 8078AA
~~~

**重要邊界**：RingView的 \`+500C\` 就是物理 \`Connection+A028\` (queued byte count)；RingView+4物理Connection+5020。L+6=4096仍可能因cursor末端嚴格 \`end<base+0x5004\` 或ring使用量被拒；只有通過上列多個guard才會寫出frame。這不同於mode0 0x807A70的 L+4 guard。

## 2. 核心勘誤：0x7D810BBB 是先寫入stack scratch的 **過渡 DWORD**，高16 bits隨即被checksum覆蓋

~~~asm
807870 C7 85 E6 EF FF FF BB 0B 81 7D  mov dword [ebp-101A],0x7D810BBB
80787A 66 89 BD E4 EF FF FF           mov word  [ebp-101C],di   ; low WORD=L
...
8078F1 89 85 EC EF FF FF              mov [ebp-1014],eax    ; accumulate sums
8078F7 89 85 F4 EF FF FF              mov [ebp-100C],eax
807912 89 95 F8 EF FF FF              mov [ebp-1008],edx    ; starts with unsigned src[0]
...
8079D7 8B 95 F4 EF FF FF              mov edx,[ebp-100C]
8079DD 03 95 EC EF FF FF              add edx,[ebp-1014]
8079E3 01 95 F8 EF FF FF              add [ebp-1008],edx  ; total sum
8079E9 8B 95 E4 EF FF FF              mov edx,[ebp-101C]    ; DWORD {L.low16,0x0BBB}
8079EF 66 8B 85 F8 EF FF FF           mov ax,word [ebp-1008]; checksum
8079F6 89 11                          mov [ecx],edx         ; frame bytes0..3
8079F8 66 89 41 04                    mov word [ecx+4],ax   ; frame bytes4..5
8079FC 8B 8E 04 50 00 00              mov ecx,[esi+5004]  ; body memcpy
807A03 8D 85 FC EF FF FF              lea eax,[ebp-1004]  ; XOR buffer
807A0A 83 C1 06                       add ecx,6            ; body starts at +6
807A0E E8 BD 61 09 00                 call 0x89DBD0        ; memcpy body, L bytes
~~~

因此**成功frame確定前6 bytes為**：
- frame[0:2] = LE16(L)
- frame[2:4] = **BB 0B** (=LE16(0x0BBB))
- frame[4:6] = LE16(sum(source[i]) mod 65536)
- frame[6:6+L] = below XOR transformed bytes

原先常數0x7D810BBB的內存高二字節\`81 7D\`在本段存在於stack scratch，但**沒有**由本次成功分支按原樣輸出成任何frame header的一部分；因只有 \`mov edx,[ebp-101C]\`讀出含 \`L/0x0BBB\` 的前4 bytes，然後checksum寫後兩bytes。\`0x7D81\` **不是這份frame固定marker**。這個更正對相容Server解析尤為重要。

## 3. 每個位元組的原生 XOR 與 checksum，非僅「有做某種XOR」

初始：
~~~asm
8078FD 8A 03                       mov al,[ebx]              ; src[0]
8078FF 8A D0                       mov dl,al
807901 80 F2 B6                    xor dl,0xB6
807904 88 95 FC EF FF FF           mov [ebp-1004],dl        ; dst[0]
80790A 0F B6 D0                    movzx edx,al
807912 89 95 F8 EF FF FF           mov [ebp-1008],edx       ; initial checksum src0
~~~

Loop pair:
~~~asm
807950 8D 43 01                    lea eax,[ebx+1]          ; src+1
807967 8A 08                       mov cl,[eax]             ; src[i]
807969 03 F0                       add esi,eax
80796B 0F B6 1C 16                 movzx ebx,[esi+edx]      ; src[i-1] through address algebra
80796F 32 D9                       xor bl,cl               ; src[i-1]^src[i]
807971 0F B6 C9                    movzx ecx,cl
807974 66 01 8D EC EF FF FF        add word [ebp-1014],cx ; sum of first in each pair
80797B 8A 48 01                    mov cl,[eax+1]           ; src[i+1]
80797E 88 1E                       mov [esi],bl             ; dst[i]
807980 0F B6 18                    movzx ebx,[eax]          ; src[i]
807989 32 D9                       xor bl,cl               ; src[i]^src[i+1]
80798B 0F B6 C9                    movzx ecx,cl
80798E 66 01 8D F4 EF FF FF        add word [ebp-100C],cx ; sum of second in pair
807995 88 1C 06                    mov [esi+eax],bl         ; dst[i+1], through address algebra
807998 83 C0 02                    add eax,2                ; next odd/even pair
80799B 4F                          dec edi
80799C 75 C3                       jne 807961
~~~

尾數1 byte：\`8079BD\`讀source[index]、\`8079C0\`讀source[index-1]、\`8079C4 xor bl,dl\`、\`8079C9 add word [ebp-1008],dx\`、\`8079D0\`寫dst[index]。最後\`8079D7–8079E3\`把兩個pairs的unsigned source byte累加與初始/尾項合併；16-bit frame checksum取低16 bits。

對**可通過guards、L>=1** 的原始src，邏輯等價：

~~~python
frame_len = len(src) + 6
dst = bytearray(len(src))
dst[0] = src[0] ^ 0xB6
for i in range(1, len(src)):
    dst[i] = src[i-1] ^ src[i]
checksum = sum(src) & 0xFFFF
frame = LE16(len(src)) + LE16(0x0BBB) + LE16(checksum) + bytes(dst)
~~~

本伪碼是按x86寫入值重建的**靜態數學等價模型**，未在Client內執行，不聲稱是官方source。奇偶pair及tail處理被分開優化，但不改上述逐byte轉換。反向解碼（方便Server契約測試）在數學上為\`src[0]=dst[0]^0xB6\`、\`src[i]=dst[i]^src[i-1]\`，然後核對 \`sum(src)&0xFFFF\`，**是否要reject checksum錯誤需由T02確認原Client接收端行為與相容Server政策，不能自行冒稱官方Server規則**。

## 4. 具體可重現測試向量（數學模型，非抓包）

|輸入src bytes|L|前綴6 bytes|XOR output bytes|完整frame|
|---|---:|---|---|---|
|\`10\`|1|\`01 00 BB 0B 10 00\`|\`A6\`|\`01 00 BB 0B 10 00 A6\`|
|\`10 20\`|2|\`02 00 BB 0B 30 00\`|\`A6 30\`|\`02 00 BB 0B 30 00 A6 30\`|
|\`0A 00 44 33 22 11\`|6|\`06 00 BB 0B B4 00\`|\`BC 0A 44 77 11 33\`|\`06 00 BB 0B B4 00 BC 0A 44 77 11 33\`|

這些向量使用本地獨立Python運算\`struct.pack('<HHH',L,0xBBB,sum(src)&0xffff)\`和逐byte XOR，比對機器碼所推等價關係；它們**是預期靜態fixture，不是從Server或Client socket抓到的實際wire capture**。

## 5. 失敗與回退：原先把mode!=0當「必用轉換」亦需修正

來源0x8061A0隊列取出packetNode+4 len以及payload+8後，以Connection+0xA02C的**signed byte**選擇路：

~~~asm
806202 0F BE 86 2C A0 00 00       movsx eax,byte [esi+A02C]
806218 74 15                      je 80622F       ; mode==0 -> plain 807A70
80621E 52                         push edx       ; mode!=0 -> transform
806223 E8 08 16 00 00             call 807830
806228 85 C0                      test eax,eax
80622A 75 23                      jne 80624F     ; transform success
80622C 8B 55 E0                    mov edx,[ebp-20] ; original payload len
80622F 8B 45 F0                    mov eax,[ebp-10] ; original src
806232 52                         push edx
806233 50                         push eax
80623A E8 31 18 00 00             call 807A70    ; mode0 OR transform FAILURE fallback!
80623F 85 C0                      test eax,eax
806246 0F 84 58 01 00 00          je 8063A4     ; preserve queue on both fail
80624F 8B 0B                       mov ecx,[ebx] ; success -> unlink queueEntry
~~~

所以 mode!=0 **也可以**寫出plain \`[LE16 L][LE16 0x1A68][raw data]\`，只要transform先失敗而plain writer成功。

對T08 Controller給定payload \`L=6+5N\`，只比較靜態size gate（仍有ring occupancy、actor count等其他限制）：

|合格entries N|原始L|mode!=0 轉換size L+6|fallback plain size L+4|由size單獨推得|
|---:|---:|---:|---:|---|
|816|4086|4092 ≤4096|4090 ≤4096|transform可通過size guard；不保證其它guard|
|817|4091|4097 >4096|4095 ≤4096|**transform必被size拒絕；plain在其餘條件合格時可成功**|
|818|4096|4102 >4096|4100 >4096|兩者size guard均拒；queueEntry留待後續，是否實際產生818筆未知|

這修正「初始化mode=2 ⇒ 一定輸出0x0BBB frame」的過度推論。0x805D02明確將新Connection mode初始化2，只證它**優先嘗試**轉換，並非所有成功output都只能是0x0BBB。只有實際通過transform所有guard才有本稿的6-byte格式。

## 6. 提交後接續研究界線，T08-202尚未完成

本次完成的是**原生可核的每byte transform與6-byte header及合法fallback**；仍未解：
- Actor record P+4/P+8的全部真alias writer（此前限定已核4C6E50與4AF920 i=0，不能當全域排他）；命令26/81/controller解除與二級record是否留有數值關聯；此為T08-202當前優先。
- S2C 000A／S2C 0007/命令26/81的完整wire domain/handler與玩家可見結果；是否另有Server現場數據來源。
- CIocpNetwork 送出/IOCP error、跨連線lane、backpressure的**所有**分支；該Controller 0x000A payload在mode2/fallback中可能多個frame排隊，不能由純本地fixture證實OS/Server已收。
- Server只須依**已驗Client**的framing及消息內容實作相容性，原版Server內部演算法不可由此倒推；T02 socket/framing、S00 SPEC/TEST、T06/T07場景、T01嚴格FULL-PASS、實際遊玩驗收各自行權責。

**T01-RETURN-T08-LEGACY-MAPPING-001維持NEEDS_FIX；T08-202整體仍INCOMPLETE**。沒有重寫舊FAILED來源，也沒有冒稱所有Client/Server流量由此已閉合。
