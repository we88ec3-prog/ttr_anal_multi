# T08-202 BIN-first 出站後續勘誤：CIocpNetwork queue drain、len+4 framing、len+6 XOR/checksum 模式

- 作者：chatgpt-web roy；2026-10-31 03:32:09（Asia/Taipei），T08-202同一未完目標，不能視為已完成202或開203。
- 一手證據：原始KR Tartaros.bin，12,472,320 bytes，SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**，本輪獨立重算；真PE .text VA 0x401000/file offset 0x400，**raw = VA − 0x400C00**。重新從原始檔切取函式真位址0x8061A0～0x806400、0x807830～0x807A70、0x807A70～0x807B20及0x8068B0～0x806980，以GNU objdump解碼。非歷史whole-file錯高0x400映射。
- 前置來源（已Commit／readback）：kr-temp-roy/20261031-033042-chatgpt-web-roy-T08-202-CIocpNetwork-vtable-outbound-buffer-IOCP-queue-PE-BIN-correction.md，Git blob **9336f7fd3d1515ea9ee7fe185c0f8772d19c4fe3**。先前報告已證本地FE38D0的6-byte header+5-byte entries經0x545B71 vtable+0x10 →CIocpNetwork::0x8069A0→0x8060D0複製資料→0x806060加入connection送出佇列。**這份新來源取代前置報告「queue reader尚未連上」的未解記錄；但不宣稱精確WSASend instance已閉合。**
- 此研究屬Client本地send path，而非官方Server內部或已收封包的runtime追蹤；不更動T01對24舊源FAILED的總NEEDS_FIX。

## I. 原來獨立的enqueue與queue-reader確定是同一packetNode／長度／payload

0x806060以connection this（ESI）操作[conn+0xA074] queue sentinel、[conn+0xA0D4] critical-section，增加[conn+0xA078] count，尾端BYTE[conn+0xA024]=1；0x8061A0以[EBP+8]獲取connection*並讀**相同欄位和同一佇列結構**。特別重要的是queue-entry和packetNode為兩個不同層的pointer，不能直接把[queueEntry+8]當byte payload：

~~~asm
8061A0 55 8B EC                push ebp; mov ebp,esp
8061C8 8B 75 08                mov esi,[ebp+8]        ; connection*
8061CB 8B 86 D4 A0 00 00      mov eax,[esi+0xA0D4]  ; same lock used by enqueue
8061E0 FF 15 4C 22 BD 00      call [0xBD224C]       ; KERNEL32 EnterCriticalSection
8061E6 8B 86 74 A0 00 00      mov eax,[esi+0xA074]  ; same queue head sentinel
8061EC 8B 18                   mov ebx,[eax]         ; queueEntry*
8061EE 3B D8                   cmp ebx,eax          ; empty?
8061F0 0F 84 C4 01 00 00      je 0x8063BA
8061F6 8B 7B 08                mov edi,[ebx+8]      ; packetNode* in entry
8061F9 8B 57 04                mov edx,[edi+4]      ; packetNode length (writer at 806174)
8061FC 8D 47 08                lea eax,[edi+8]      ; packetNode copied payload (80616C)
8061FF 89 45 F0                mov [ebp-0x10],eax
806202 0F BE 86 2C A0 00 00   movsx eax,byte [esi+0xA02C] ; mode
80620C 8D 8E 1C 50 00 00      lea ecx,[esi+0x501C] ; connection output ring
~~~

Queue reader direct E8 callers 0x804AD6 and 0x805228（在原生相應函式中的connection迭代/guard路）；只證存在caller，不等於知道哪個scene幀必觸發。

## II. Mode==0的具體函式：0x807A70在原來payload前增加little-endian四位元組

~~~asm
806218 74 15                je 0x80622F        ; mode=0 -> plain branch
80621E 52                   push edx          ; nonzero mode original len
80621F 8B 55 F0             mov edx,[ebp-0x10] ; payload pointer
806222 52                   push edx
806223 E8 08 16 00 00      call 0x807830     ; nonzero-mode transform
806228 85 C0                test eax,eax
80622A 75 23                jne 0x80624F     ; transformed success
80622C 8B 55 E0             mov edx,[ebp-0x20] ; restore original len
80622F 8B 45 F0             mov eax,[ebp-0x10] ; original bytes
806232 52                   push edx
806233 50                   push eax
806234 8D BE 1C 50 00 00   lea edi,[esi+0x501C]
80623A E8 31 18 00 00      call 0x807A70
80623F 85 C0                test eax,eax
806246 0F 84 58 01 00 00   je 0x8063A4      ; failed -> do not unlink success
~~~

真PE 0x807A70是ring寫入器，只有容量和長度符合才成功：

~~~asm
807A70 55 8B EC                  push ebp; mov ebp,esp
807A78 8B 37                     mov esi,[edi]        ; ring critical-section
807A7E FF 15 4C 22 BD 00        call [0xBD224C]
807A84 8B 55 0C                  mov edx,[ebp+0xC]    ; original payload len
807A87 8D 5A 04                  lea ebx,[edx+4]     ; framed total length
807A8A B8 68 1A 00 00            mov eax,0x1A68
807A8F 66 89 45 FE               mov word [ebp-2],ax ; marker
807A93 66 89 55 FC               mov word [ebp-4],dx ; original length low16
807A97 81 FB 00 10 00 00         cmp ebx,0x1000     ; fail if len+4>4096
807AA3 85 D2                     test edx,edx        ; len nonzero
807AAB 8B 8F 0C 50 00 00         mov ecx,[edi+0x500C]
807AB1 03 CB                     add ecx,ebx
807AB3 81 F9 00 40 00 00         cmp ecx,0x4000     ; bounded ring occupancy
807ABB 8B 87 04 50 00 00         mov eax,[edi+0x5004] ; ring cursor
807AE2 8B 4D FC                  mov ecx,[ebp-4]     ; adjacent [len,u16 marker]
807AE5 52                        push edx           ; payload length
807AE6 8B 55 08                  mov edx,[ebp+8]
807AE9 89 08                     mov [eax],ecx      ; prefix DWORD
807AEB 8B 06                     mov eax,[esi]      ; ring cursor
807AED 52                        push edx          ; original bytes
807AEE 83 C0 04                  add eax,4
807AF1 50                        push eax          ; destination after 4-byte prefix
807AF2 E8 D9 60 09 00           call 0x89DBD0       ; copy len bytes
807AFA 01 9F 0C 50 00 00        add [edi+0x500C],ebx
807B00 01 1E                     add [esi],ebx
807B0D B8 01 00 00 00           mov eax,1          ; success
807B16 C2 08 00                  ret 8
~~~

在「模式0，且此queue entry成功寫ring」的限定條件，內存連續bytes：

| offset from written record | bytes | source |
|---|---|---|
|0–1|u16 little-endian(6+5N)|original payload length|
|2–3|68 1A|0x1A68 fixed prefix word|
|4–5|0A 00|0x54582E/0x54584A生成的Client出站本地字|
|6–9|DWORD little-endian [0xF93944]|controller header data|
|10 ...|5*N bytes|eligible pair entries|
|total|4+(6+5N)|all bytes written into ring when success|

**極重要的更正**：前置報告提「header 0x000A + length 6+5N」，而**真socket前還有可觀察的4-byte framing**，所以不能把FE38D0當已核完整wire frame，或把本地C→S 0x000A自動等於S→C handler domain index10。此ring buffer被其他方法提交至網路的精確時序仍欠補證。

### 靜態上限不完全一致（真條件對照）

Controller在0x545AFC只檢查OriginalLen=6+5N<=0x1000；queue的mode0 frame還檢查OriginalLen+4<=0x1000。因此N=818時，OriginalLen=4096可進queue，但framer要求4100超限，返回0；N=817則OriginalLen=4091，framed=4095，若ring occupancy尚有容量可成功。**這是不同函式的靜態門檻差異**，不是已有runtime證明遊戲能收集818個合格entries，也不是已證實有損封包。

## III. Nonzero mode真正存在len+6和XOR/checksum，不得宣稱所有出站都是1A68明文frame

0x806202透過 signed BYTE[connection+0xA02C]挑模式。非0模式經0x807830先處理，成功則不走0x807A70，只有失敗才可能fallback；因此**0x1A68這個4-byte-prefix只適用mode0或fallback**。真PE 0x807830原生片段：

~~~asm
807830 55 8B EC                   push ebp; mov ebp,esp
807833 B8 38 10 00 00             mov eax,0x1038
807838 E8 33 8E 0A 00             call 0x8B0670        ; stack allocation helper
807848 8B 5D 08                   mov ebx,[ebp+8]     ; original bytes ptr
807851 8B 7D 0C                   mov edi,[ebp+0xC]   ; original len
80786D 8D 47 06                   lea eax,[edi+6]    ; transformed record total
807870 C7 85 E6 EF FF FF BB 0B 81 7D mov dword [ebp-0x101A],0x7D810BBB
80787A 66 89 BD E4 EF FF FF       mov word [ebp-0x101C],di
807887 3D 00 10 00 00             cmp eax,0x1000
8078FD 8A 03                      mov al,[ebx]       ; first source byte
807901 80 F2 B6                   xor dl,0xB6       ; first output transform
807967 8A 08                      mov cl,[eax]       ; later input byte
80796F 32 D9                      xor bl,cl
807974 66 01 8D EC EF FF FF       add word [ebp-0x1014],cx  ; running sum
80797E 88 1E                      mov [esi],bl       ; transform output
807989 32 D9                      xor bl,cl         ; rolling XOR
807995 88 1C 06                   mov [esi+eax],bl
8079F6 89 11                      mov [ecx],edx     ; copy 4-prefix bytes
8079F8 66 89 41 04                mov word [ecx+4],ax ; checksum part
807A0E E8 BD 61 09 00             call 0x89DBD0    ; copy transformed payload to ring
807A1F 01 86 0C 50 00 00          add [esi+0x500C],eax
807A25 01 86 04 50 00 00          add [esi+0x5004],eax
807A4A C2 08 00                   ret 8
~~~

觀測到新+6 byte overhead、4-byte常數0x7D810BBB、原始len low16、rolling XOR 及至少兩個累加checksum相關欄位。**不能**從節錄直接宣稱完整演算法或所有key的語義。原件可繼續向上還原input->output每個byte及非0 mode值。非0模式長度要求 OriginalLen+6<=4096。若OriginalLen=6+5N，N=817 OriginalLen=4091則加6=4097失敗；最大可行整數N=816時OriginalLen=4086+6=4092（仍須其他guard）。失敗時fallback到plain path與其條件需按CFG再驗，不得推所有mode一定寫一種封包。

## IV. 成功隊列摘除與同一入列record的所有權

0x8061A0僅在上列任一framer/transform返回success後執行：

~~~asm
80624F 8B 0B                     mov ecx,[ebx]        ; linked next
80625C 8B 43 04                  mov eax,[ebx+4]    ; linked prev
80625F 89 08                     mov [eax],ecx
806266 53                        push ebx
80626A E8 9D AF 08 00            call 0x89120C     ; free queue entry
806275 FF 8E 78 A0 00 00         dec dword [esi+0xA078]
8063BA 8B 96 D4 A0 00 00         mov edx,[esi+0xA0D4]
8063C1 FF 15 48 22 BD 00        call [0xBD2248]    ; LeaveCriticalSection
~~~

因此真正的中間功能鏈是**「packet copied → queued → on eligible drain framed into output buffer → unlink entry」**，不是「copy→立刻WSASend」。0x8062B9～0x806356會涉及[FE33xx] global record/pool，尚未完整判其類別，不拿來誤稱Server封包序號。此局部亦不證明非同步IOCP完成成功或失敗。

## V. 原生Winsock endpoint與T08-202仍未閉合的必需條件

同一RTTI CIocpNetwork primary vtable C51748 的+0x0C=8068B0，是獨立的已確認socket方法：0x806912 **call dword [0xBD25B8] = WS2_32.dll!WSASend**（從PE Import Table），使用per-connection socket與WSABUF/OVERLAPPED，並判斷WSA_IO_PENDING=997。**但尚未把本次0x807A70或0x807830寫入的那一份ring bytes，沿實際caller/source pointer直接追到0x8068B0所提交的WSABUF**；要再查 connection+0x5004/+0x500C 的consumer、0x8068B0所有vtable呼叫者、完成回調和retries，不能跳過T02責任界線。

目前已證的**有條件資料路徑**：

~~~text
0x545B71 controller + outgoing FE38D0 length (6+5N)
  -> CIocpNetwork vtable+10 (0x8069A0) lookup connectionId=0
  -> 0x8060D0 packetNode+4 length, +8 bytes
  -> 0x806060 [conn+A074] queue + pending flag
  -> 0x8061A0 same sentinel -> queued node + payload
     ├─ mode0 -> 0x807A70 [len:u16][0x1A68:u16][original data] -> output ring
     └─ mode!=0 -> 0x807830 [six-byte+XOR/checksum transformed data]
             if fails, fallback 0x807A70
  -> on success unlink queue entry / record pool
  [ring-to-WSABUF and actual 8068B0 WSASend: STILL UNVERIFIED]
~~~

仍待T08-202完整靜態目標：Actor record P+4/P+8 其他alias writer、命令26/81移除／owner一致性、不同scene controller的pair輸入來源、frame/payload across network layers, async completion, event/game UI副作用。**新的frame證據不可替代其它Client未解事項**，也不能拿它推Server內部自訂規則。跨T02封包、T06/T07場景、S00相容需求與T01 FULL-PASS仍分開。

|玩家情境|Client本輪原生已確認|Client仍待查|Server待開發|跨Task／遊玩驗證|
|---|---|---|---|---|
|本地pair狀態送出|6+5N bytes排入CIocpNetwork連線queue，再依mode寫成4-byte或6-byte framing到outbound ring、成功才摘除queueEntry|ring→真正WSASend buffer、非0 transform全算法、connectionId0的session/lane、actor pair其他writer與控制清理|需依完成的T02 Client wire契約設計相容Server接收/回覆；勿猜官方協定方向|T02/T06/T07/T01原生審核及可玩|
|網路系統錯誤／backpressure|mode0兩層尺寸guard 4096 vs 4092，輸出ring occupancy≤0x4000，queue framer失敗有保留分支|何時重試及高水位時序、Node生命週期/緩衝覆蓋|重試規則可依Client相容性由S00設計，但非本稿獨立證實的原版Server邏輯|跨Agent補證|

**完成裁決：T08-202不能標完成。LEGACY-MAPPING-001仍NEEDS_FIX，舊source的T01 FAILED審核未由本稿變更。**


## VI. 再沿queue reader的兩個實際caller查到連線調度及backpressure

由真PE機器碼，0x804A40本地入口保存EDI作loop owner，透過全域 [0xFBA858] pointer-vector 依 begin/end 逐連線取ESI；0x8051B0函式內則以同一 [0xFBA858] pointer-vector，但用[EBX+4] index選擇起始連線、只迭代後續範圍。兩路都有相同[conn+0xA0AC] guard和直接E8至8061A0：

~~~asm
; call site A: 0x804A40... (global connection vector + len/timing guard)
804A75 8B 35 58 A8 FB 00   mov esi,[0xFBA858]
804AA2 8B 7E 04            mov edi,[esi+4]
804AA5 2B 3E               sub edi,[esi] ; byte count
804AA9 C1 FF 02            sar edi,2    ; count of connection pointers
804AC3 8B 16               mov edx,[esi]
804AC5 8B 34 82            mov esi,[edx+eax*4] ; connection*
804AC8 83 BE AC A0 00 00 00 cmp dword [esi+0xA0AC],0
804ACF 0F 84 76 01 00 00  je 0x804C4B
804AD5 56                  push esi
804AD6 E8 C5 16 00 00      call 0x8061A0
804ADB 85 C0               test eax,eax
804ADF 8B 86 A4 A0 00 00   mov eax,[esi+0xA0A4]
804AEB 83 F8 05            cmp eax,5
804AFC 83 C0 FB            add eax,-5    ; on branch A, countdown decrement
804B07 83 7D FC 00         cmp dword [ebp-4],0
804B13 83 86 A4 A0 00 00 05 add dword [esi+0xA0A4],5 ; on other branch

; call site B: 0x8051B0... (different owner/index)
8051EE 8B 0D 58 A8 FB 00   mov ecx,[0xFBA858]
8051F4 8B 41 04            mov eax,[ecx+4]
8051F7 2B 01               sub eax,[ecx]
8051FC C1 F8 02            sar eax,2
8051FF 89 4D F8            mov [ebp-8],ecx
805202 89 45 08            mov [ebp+8],eax
805215 8B 09               mov ecx,[ecx]
805217 8B 34 B9            mov esi,[ecx+edi*4]  ; conn indexed by EDI
80521A 83 BE AC A0 00 00 00 cmp dword [esi+0xA0AC],0
805221 0F 84 85 01 00 00   je 0x8053AC
805227 56                  push esi
805228 E8 73 0F 00 00      call 0x8061A0
80522D 85 C0               test eax,eax
805231 8B 86 A4 A0 00 00   mov eax,[esi+0xA0A4]
80523D 83 F8 05            cmp eax,5
80524E 83 C0 FB            add eax,-5   ; countdown normal branch
805259 80 7B 10 00         cmp byte [ebx+0x10],0
805265 83 86 A4 A0 00 00 05 add dword [esi+0xA0A4],5 ; alternate failure
~~~

**新已確立的關係**：queue reader確有上層**global connection vector**的兩個直接caller；不需要再將queue reader視為完全沒有調度者。但哪個outer thread/tick使804A40、8051B0運作、[conn+A0AC]為何被置為有效、A0A4累加/遞減的精確時間單位及跨連線競態，尚須繼續反向查owner及callers，不能據此稱所有connection都已成功觸發WSASend。

**修訂限制**：本篇trace完整證據只覆蓋queue->output ring與兩個reader直接caller，不宣稱已取得由ring到WSABUF的一一對應或實際Server收到資料。T08-202因此仍未完成；其出站部分的實質進度記入本README/交接，不能用完成一份報告冒充研究目標完成。
