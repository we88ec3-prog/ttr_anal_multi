# T08-202 — BIN-first Actor owner record P+4/P+8：0007「僅空值寫入」與000A「第一筆覆寫」；26/81 清理區分、原生本地handler表交叉證明

**研究者**：chatgpt-web roy；2026-10-31 04:04:57 Asia/Taipei；KR Client靜態，T08-202同段勘誤，並非新T08-203。
**原始資料**：`Tartaros.bin` 12,472,320 bytes SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**，2026-10-31重新讀原始BIN。PE .text VA 0x401000/raw0x400，原生code raw=VA−0x400C00；`objdump -d -M intel`按有效入口解碼4ADD65..4ADFD0、4AEC08..4AEC98、4C6E50..4C6E9C、4AF920..4AFAC7、4B2A56..4B2AC7、4B3710..4B374E、4DFBC0..4DFD34、4DFC30..4DFC8A、4B1A30..4B1A82。全原始.text E8 rel32目標掃描僅為**候選直接call sites**，先和真解碼指令邊界比對；全檔DWORD精確字節搜尋不含推導間接xref。
**源譜**：原`kr-temp-roy/20261031-005014-chatgpt-web-roy-T08-202-supplemented-bounded-static-evidence-FULL.md`已列明兩個有界P writer和26/81差異（Git blob 0770df4aa4567a26fed794f725a1775dfa72cd72）；本次以原生PE重核並補明**不同producer的覆寫條件、獨立本地handler slot、低16bit值及穩定性界線**。不修改前手原稿，T01 LEGACY-MAPPING-001仍 NEEDS_FIX，T08-202整體INCOMPLETE。

## I. Handler編號從程式內建本地dispatch表實際指標寫入得來，不能叫wire opcode

在真PE 0x4ADDxx..0x4ADFxx，初始化器將每entry 8-byte中offset+4的DWORD設為function pointer；已知條目對照：

~~~asm
4ADDA2 C7 40 54 20 F9 4A 00      mov dword [eax+0x54],0x4AF920    ; (0x54-4)/8=10
4ADE11 C7 80 84 00 00 00 30 1A 4B 00 mov dword [eax+0x84],0x4B1A30 ; index16
4ADE8D C7 80 D4 00 00 00 D0 28 4B 00 mov dword [eax+0xD4],0x4B28D0 ; index26
4ADFBD C7 80 8C 02 00 00 10 37 4B 00 mov dword [eax+0x28C],0x4B3710; index81
~~~

索引計算是已觀測的「8 bytes/entry、pointer存base+4」的本地表布局；在整檔精確DWORD掃描分別命中0x4AF920 raw0xAD1A5、0x4B28D0 raw0xAD293、0x4B3710 raw0xAD3C3、0x4B1A30 raw0xAD217（以上都位於**原生.text immediate而非.rdata vtable**）。這比單看舊報告稱「命令26／81」更有可回查證據，但**只證 Client 本地dispatch index，不能自動套成原始完整S→C封包wire opcode或設計出Server payload**。

## II. 0007到P+4/+8：必須既有record且P+4==0才call4C6E50

~~~asm
; 前置packet/owner lookup，本地過濾
4AEC08 83 7B 0E 00            cmp dword [ebx+0x0E],0
4AEC0C 0F 84 86 00 00 00      je 0x4AEC98                 ; no secondary lookup
4AEC4A 8B 4B 0E               mov ecx,[ebx+0x0E]         ; secondary record search key
4AEC5A B9 48 B1 FA 00         mov ecx,0xFAB148          ; owner secondary index, not actor tree
4AEC5F E8 5C 4C 39 00         call 0x8438C0             ; tree lookup
4AEC68 3B 05 4C B1 FA 00      cmp eax,[0xFAB14C]       ; end sentinel
4AEC6E 74 28                  je 0x4AEC98
4AEC70 8B 48 10               mov ecx,[eax+0x10]        ; record P
4AEC73 85 C9                  test ecx,ecx
4AEC75 74 21                  je 0x4AEC98
4AEC77 83 79 04 00            cmp dword [ecx+4],0       ; **existing P+4 must be zero**
4AEC7B 75 1B                  jne 0x4AEC98             ; nonzero => leave P unchanged
4AEC7D 0F B7 43 FC            movzx eax,word [ebx-4]   ; incoming actor ID
4AEC81 8B F9                  mov edi,ecx              ; P pointer
4AEC83 E8 C8 81 01 00         call 0x4C6E50           ; valid direct E8 caller

4C6E50 55 8B EC              push ebp ;mov ebp,esp
4C6E57 89 47 04              mov [edi+4],eax           ; P+4 = actor ID (zero-extended WORD)
4C6E5D E8 FE 81 F4 FF        call 0x40F060            ; owner main Actor tree
4C6E68 8D 4E 08              lea ecx,[esi+8]          ; tree
4C6E6E E8 8D 80 36 00        call 0x82EF00
4C6E76 3B 46 0C              cmp eax,[esi+0x0C]       ; sentinel?
4C6E79 74 16                 je 0x4C6E91
4C6E7B 8B 40 10              mov eax,[eax+0x10]       ; Actor*
4C6E80 74 0F                 je 0x4C6E91              ; missing value
4C6E82 0F B7 88 88 00 00 00  movzx ecx,word [eax+0x88]
4C6E89 89 4F 08              mov [edi+8],ecx          ; P+8 = ZERO-EXTENDED Actor+88 low16
4C6E91 C7 47 08 00 00 00 00  mov [edi+8],0           ; no Actor => P+8 zero
~~~

**重要更正**：不能說「只要0007抵達就會更新P」：舊P+4非零時，本caller**不進**4C6E50。反之，若成功進入並找不到Actor，P+4仍先已設為傳入ID，但P+8被0覆寫；這種`P+4!=0 && P+8==0`是**Client靜態代碼容許的狀態**，不是證明Server必發送這種packet。全.text按E8 rel32尋4C6E50只找到`0x4AEC83`一處、全BIN 32-bit原始DWORD `4C6E50`命中零處，仍不能排除其它不以明文絕對DWORD保存的間接writer。

## III. 000A一般路第一筆i==0：覆寫P+4及P+8，不採0007的「舊P+4必為0」條件

`0x4AF920`經輸入B+2 owner secondary record key查找P；B+6是signed count，每筆B+7+4i WORD(idA)／B+9+4i WORD(idB)；若local owner且idA≠idB走controller slot+8 (pair)且跳過一般P更新。對其它正常一般路（有有效Actor及record），原生指令：

~~~asm
4AFA01 8B 45 08                  mov eax,[ebp+8]
4AFA04 66 8B 4C 98 07            mov cx,word [eax+ebx*4+7]    ; idA
4AFA09 66 3B 4C 98 09            cmp cx,word [eax+ebx*4+9]    ; idB
4AFA10 83 7D F8 00               cmp [ebp-8],0               ; local owner flag
4AFA16 E8 45 F6 F5 FF            call 0x40F060                 ; special local pair branch
4AFA2B 8B 52 08                  mov edx,[edx+8]
4AFA30 FF D2                     call edx                      ; controller append pair
4AFA32 E9 80 00 00 00            jmp 0x4AFAB7                  ; skip P+4/P+8 general route
4AFA37 85 DB                     test ebx,ebx                  ; i==0?
4AFA39 75 53                     jne 0x4AFA8E
4AFA3B 8B 45 FC                  mov eax,[ebp-4]              ; P*
4AFA3E C7 87 98 00 00 00 01 ... mov [edi+0x98],1            ; Actor property
4AFA48 89 70 04                  mov [eax+4],esi               ; **P+4=idA**, old P+4 unrestricted
4AFA73 0F B7 90 88 00 00 00     movzx edx,word [eax+0x88]    ; lookup Actor+88 low16
4AFA7A 8B 45 FC                  mov eax,[ebp-4]
4AFA7D 89 50 08                  mov [eax+8],edx               ; P+8
4AFA82 8B 4D FC                  mov ecx,[ebp-4]
4AFA85 C7 41 08 00 00 00 00     mov [ecx+8],0                 ; no Actor lookup
4AFA8E C7 87 98 00 00 00 00... mov [edi+0x98],0             ; i!=0 normal route
4AFAA1 89 87 9C 00 00 00        mov [edi+0x9C],eax          ; Actor property from P[0]
~~~

所以兩producer權限分明：0007只在P+4==0時初始化，000A在i==0一般路可以**替換非零P+4**；000A非首筆及local mismatch的pair分支不直接寫P+4/+8。本項是跨命令狀態一致性必須保留的原生界線。不能因0007先看`P+4==0`就認為P永遠immutable。

## IV. 命令26與81主樹移除不應混成同一controller解除副作用

~~~asm
; index26 = handler 4B28D0
4B2A56 8B 0D A4 A7 FB 00      mov ecx,[0xFBA7A4]     ; Controller*
4B2A5C 66 8B 76 04            mov si,word [esi+4]    ; soon-to-erase Actor id
4B2A65 8B 3A                  mov edi,[edx]         ; controller raw Actor slot
4B2A6B 66 39 77 04            cmp word [edi+4],si
4B2A84 8B 50 14               mov edx,[eax+0x14]
4B2A87 FF D2                  call edx              ; if any slot matches, all 3 cleared
4B2AB5 8B 44 24 14            mov eax,[esp+0x14]
4B2AB9 0F B7 08               movzx ecx,word [eax]
4B2ABD B8 30 B1 FA 00         mov eax,0xFAB130
4B2AC2 E8 F9 D0 02 00         call 0x4DFBC0        ; MAIN Actor erase after controller clear

; index81 = handler 4B3710
4B3730 0F B7 06               movzx eax,word [esi]
4B3733 0D 00 00 00 06         or eax,0x06000000 ; composite key for Actor+88
4B3738 50                     push eax
4B3739 E8 22 B9 F5 FF         call 0x40F060     ; owner main
4B373E E8 4D C5 02 00         call 0x4DFC90     ; composite-key Actor erase
~~~

0x4DFBC0自身在0x4DFBE4..0x4DFBF3先執行controller vtable+0x1C三次getter，**不是clear**；接著目標Actor vtable+0x14、virtual deleting destructor與erase tree node。0x4DFC90在0x4DFCB0..0x4DFCD2迭代main Actor tree以[Actor+0x88]==composite查找、對匹配Actor呼叫其vtable+0x14、deleting destructor及node erase，但**未在本函式同樣呼叫Controller+0x14**。上述兩條均不寫P+4/P+8；然而Actor own virtual+0x14的各動態型別下游與全域alias writer仍未完全查完，所以不能推論「81後一定殘留可用控制目標」或實機UAF。

同一main Actor erase wrapper `0x4DFBC0`還有**額外direct caller `0x4AA057`**（S2C其它局部handler）和26的0x4B2AC2；因此即使確認26上游做controller清槽，也不能據此一概說**所有**呼叫0x4DFBC0的路徑都先清槽。同樣的純原生direct E8掃描：`4DFC90`只見0x4B373E，`4DFC30`見0x4BBB4B（指定secondary record erase）；它們對應不同index及樹owner。

## V. 次級Record清理與Reset的正確範圍

~~~asm
; 0x4DFC30 with ESI=owner, [EBP+8]=secondary record key
4DFC4F 8B 86 F8 00 00 00     mov eax,[esi+F8]      ; owner cache ptr
4DFC59 8B 08                  mov ecx,[eax]         ; cached P->key at +0
4DFC5B 3B 4D 08               cmp ecx,[ebp+8]
4DFC60 C7 86 F8 00 00 00 00  mov [esi+F8],0       ; only if cached key matches
4DFC6A 8B 47 10               mov eax,[edi+10]    ; P* secondary tree payload
4DFC71 50                     push eax
4DFC72 E8 95 15 3B 00         call 0x89120C      ; free P
4DFC7A 57                     push edi
4DFC80 E8 0B 6C 2D 00         call 0x7B6890      ; secondary tree node erase

; local index16 only:
4B1A30 6A 00                  push 0               ; type0 filter
4B1A39 E8 02 E3 02 00         call 0x4DFD40       ; main Actor type0 removal
4B1A46 8B 50 14               mov edx,[eax+14]   ; controller clear virtual
4B1A49 FF D2                  call edx
4B1A50 C7 80 F8 00 00 00 00  mov [eax+F8],0      ; clear owner cache
4B1A5E E8 0D F6 02 00         call 0x4E1070     ; clear secondary tree P payloads
; index17
4B1A70 6A 01                  push 1
4B1A79 E8 C2 E2 02 00         call 0x4DFD40      ; type1 removal ONLY in this wrapper
~~~

命令26、81主樹刪Actor和次級P樹不是同一物件所有權。P+4/P+8都是**數值關聯**，可在相關Actor刪除後暫時維持以前的id/aux數值；這個靜態容許狀態不等於懸空Actor pointer。真正secondary erase或index16 bulk reset會直接free整個P，不需要逐欄重寫0。

## VI. 跨Task應保留的結論/反例/未解

| 玩家功能情境 | Client已確認 | Client待逆向 | Server待開發／整合 | 需現場驗證 |
|---|---|---|---|---|
| local index 7初始化次級owner關聯 | 4AEC77 P+4==0才4AEC83→4C6E50；P+8從Actor+88 low16，缺Actor清零 | 其它間接writer、P初始配置與所有所有者 | 不可把local index 7當已證完整wire opcode | 00/07 packet實際來源/時序 |
| local index10 Actor控制/owner更新 | 4AFA37 i0一般路覆寫P+4/P+8；特別local mismatch走pair queue且跳過 | 不同controller/runtime欄位重置及是否晚於Actor create | T02 wire與T08場景同步 | 玩家控制對象與畫面 |
| index26/81刪Actor | 26在部分raw controller slot命中時先virtual+14 clear再main erase；81 composite erase本體沒有相同controller clear；二者也不寫P字段 | Actor vtable+14所有目標、其它controller owner、異步收包/handler | S00規格須使用已證Client相容行為，不能推原版Server決策 | 操作焦點/不懸空的真實序列 |
| secondary record key erase / type0 reset | 4DFC30直接free P；index16 type0 Actor移除後清controller/owner P tree，index17僅type1 Actor | 其它次級記錄所有權與析構順序 | T06/T07場景清理接口 | 場景切換/重連驗收 |

**可確認的正面結論**：已驗兩個主要P字段producer存在不相同的更新條件；local handler表中7/10/26/81入口可直接用原生指標寫入定位；26/81/16/17/次級record erase是不同物件與生命週期邊界。

**明確尚未閉合**：本輪rawDWORD/E8掃描不能涵蓋動態vtable/函數指標間接call、inline alias物件拷貝、整個程序所有P欄位 writer；Controller slot/H-history、Actor所有衍生型別的vtable+14、完整C2S/S2C wire、實際同幀下游/玩家視覺亦待查。不得把0次direct hit當作「別的writer不存在」或把記錄數值持續存在當成runtime BUG。既有 T01-RETURN-T08-LEGACY-MAPPING-001保留NEEDS_FIX，本輪原生資料已提交待原生複驗，**T08-202整體仍未完成**。
