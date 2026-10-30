# T08-202：owner P record 的原生建立、綁定更新、26/81 移除與Controller多型清理（BIN-first完整大型批次技術稿）

> **2026-10-31 04:44 來源歸屬與後續跨型別證據修訂**：完整 T08-201 原稿 \`T08-201-original-full-20261028.md\` **已經確認** \`4AF530→0x2C P allocation→4DFFB0\`、owner主/次級樹分離，以及CMonster+14→4D1F80→4C8360。因此本文§2所述這條本地index8 new P不是首次發現，應標記「**重驗T08-201既有鏈**」；本次新限定證據是同key \`4AF6F1..4AF781\` refresh保留P+4/+8、26與81及Controller多型刪除差異的再驗/擴展。另已新增完整[四種0007 Actor RTTI→vtable+14與六種Controller共同H-tree析構底層](20261031-044016-chatgpt-web-roy-T08-202-four-native-Actor-RTTI-virtual-cleanup-and-Controller-H-tree-destructor-evidence.md)，修訂後Git blob \`6a404ccbc50c078a96384998d8522a2c0ec2aed8\`；該稿明確確認Tag/Single/Empty的deleting destructor終會回到\`544E80\`，**但26/81沒有直接析構Controller**。兩份文件皆非T01 FULL-PASS，亦不把全域P別名writer聲稱已窮盡。



研究者：chatgpt-web roy。研究時間：2026-10-31 04:35 Asia/Taipei。工作範圍：延續 T08-202；本批新增本地 index8 的 P record lifecycle、index7/index10 的實際欄位 writer、index26/81 的 Actor/Controller branch 和二級P釋放，不開203。

## 0. 一手證據與完成聲明

原始 KR 客戶端 Tartaros.bin：12,472,320 bytes，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；本次從本地原件實際執行sha256sum確認。PE32 .text VA=0x401000、raw=0x400，程式碼原生raw=VA−0x400C00；.rdata VA=0xBD2000/raw=0x7D0600。反組譯使用 GNU objdump -d -M intel，從正確PE函式入口及上下游指令窗口重解。原始BIN、EXE均唯讀，沒有啟動遊戲或執行Client API。

開工核對最新main@dd8d487316ea2bfb1de3e0b3851f14c398303a68、T08 README及T01、S00 inbox/T08和唯一RR台帳；無指派T08 RR。T08研究分支已經由雙親non-force merge同步最新main，保持未改其它Task。T01歷史24篇legacy之作者替代source在T08分支READY_FOR_REVIEW，但main的正式T01仍可NEEDS_FIX。這與本輪新分析不同。

前置證據：T08-202完整 bounded 原稿 kr-temp-roy/20261031-005014-chatgpt-web-roy-T08-202-supplemented-bounded-static-evidence-FULL.md (Git blob 0770df4aa4567a26fed794f725a1775dfa72cd72)；新出站鏈034400 WSABUF/WSASend (blob 3e87a808d6c278a248e59408f23d9ef02a4398b8)、034500 GQCS (blob 74407c9ead69bd40b6fc066c816abffdc7b50b62)、035954 XOR/checksum (blob c971ba55de04120379eeb622bee2c03a1988a8ef)。本文只對新增或交叉核對的部分聲稱本次BIN直接驗證，前述子鏈不冒稱本輪全部重做。

## 1. 本地handler table索引真實身份：8→4AF530，10→4AF920，26→4B28D0，81→4B3710

0x4ADD50是一手初始化入口，把handlerVA寫進長度8-byte的兩DWORD slot。第一個slot為 [table+4]，因此index=(offset−4)/8：

~~~asm
4ADD98 C7 40 44 30 F5 4A 00       mov [eax+0x44],0x4AF530    ; index8
4ADDA2 C7 40 54 20 F9 4A 00       mov [eax+0x54],0x4AF920    ; index10
4ADE8D C7 80 D4 00 00 00 D0 28 4B 00  ; index26->4B28D0
4ADFBD C7 80 8C 02 00 00 10 37 4B 00  ; index81->4B3710
~~~

後二行起始位置及完整長度依原BIN byte pattern與0x4ADD50連續handler表寫入鏈確認，不使用從指令中間開始的objdump誤解碼。全原BIN DWORD exact pattern hit：0x4AF530 raw0xAD19B，0x4AF920 raw0xAD1A5，0x4B28D0 raw0xAD293，0x4B3710 raw0xADFC3，各一筆；轉換為真PE VA時text raw+0x400C00。此處只確定Client的本地handler table index，不能未經T02 framing/dispatcher核實即把它擴張為Server官方wire opcode或內部決策。

## 2. 本地index8（0x4AF530）是P的真正新建及更新流程；新P大小0x2C

此函式解析一組以 0x16（22 bytes）為stride的owner P資料。根函式內0x4AF8F5 add EBX,0x16；本結構不能跟index7建立Actor時每列26 bytes的packet混為一類。0x4AF606取得record key，0x4AF612設全域 [0xFAB148] owner樹，0x4AF61B call 0x8438C0查找；已有node時0x4AF62C從[node+0x10]取得同一P pointer（EDI），並在0x4AF631跳向refresh；找不到才0x4AF637 allocate新P。

~~~asm
4AF637 6A 2C                        push 0x2C
4AF639 E8 2A 1C 3E 00               call 0x891268
4AF647 89 30                        mov [eax],esi         ; P+0 =0
4AF649 89 70 04                     mov [eax+4],esi       ; **P+4 =0**
4AF64C 89 70 08                     mov [eax+8],esi       ; **P+8 =0**
4AF64F 89 70 0C                     mov [eax+0xC],esi
4AF652 89 70 10                     mov [eax+0x10],esi
4AF655 89 48 14                     mov [eax+0x14],ecx
4AF658 89 70 1C                     mov [eax+0x1C],esi
4AF65B C7 40 24 FF FF FF FF         mov [eax+0x24],-1
4AF662 66 89 48 28                  mov word [eax+0x28],cx
4AF666 8B F8                        mov edi,eax          ; EDI = new P*
4AF673 8B 43 FA                     mov eax,[ebx-6]    ; owner key
4AF676 89 07                        mov [edi],eax      ; P+0=key
4AF6AB 3B 17                        cmp edx,[edi]
4AF6AD 0F 94 C1                     sete cl
4AF6B7 89 4F 1C                     mov [edi+0x1C],ecx ; local key flag
4AF6E5 68 30 B1 FA 00               push 0xFAB130     ; manager/owner reference
4AF6EA 8B CF                        mov ecx,edi       ; same P*
4AF6EC E8 BF 08 03 00               call 0x4DFFB0    ; secondary P insertion
~~~

實際跨函式身份已閉合：0x4DFFB0收到 ECX=P*、[EBP+8]=owner；0x4DFFDC mov ESI,ECX、0x4DFFDE mov EBX,[EBP+8]；0x4E0018比較 P+0 key與全域0xF93930特別key，命中0x4E0020 mov [owner+F8],P*（特殊P cache）。然後0x4E002C lea ESI,[owner+0x18]，經0x57EF20／0x57E850把P插入owner的二級樹。這不是把「主Actor樹 owner+8」當「P二級樹 owner+18」。

**新舊P差異**：0x4AF62C／4AF631已有P時，不再0x4AF637分配或初始化，因此在已驗的refresh後半：
~~~asm
4AF6F8 8B 43 FA                     mov eax,[ebx-6]
4AF6FB 89 07                        mov [edi],eax
4AF735 89 4F 1C                     mov [edi+0x1C],ecx
4AF73B 88 47 20                     mov [edi+0x20],al
4AF740 89 47 0C                     mov [edi+0xC],eax
4AF747 66 89 47 16                  mov word [edi+0x16],ax
4AF74F 66 89 47 14                  mov word [edi+0x14],ax
4AF756 89 47 10                     mov [edi+0x10],eax
4AF75D 66 89 47 18                  mov word [edi+0x18],ax
4AF766 88 47 28                     mov [edi+0x28],al
4AF777 88 47 29                     mov [edi+0x29],al
4AF781 89 57 24                     mov [edi+0x24],edx
4AF8F5 83 C3 16                     add ebx,0x16
~~~
**此正常同key刷新分支沒有重設 P+4/P+8**。此是確定的局部保留，不是聲稱全程沒有其他alias writer或原版必然會產生不一致。index8另有 [B+2] 非零則先清一組owner全域樹的分支，不能將它誤稱為只清當前P。

## 3. 原本兩類寫入者和新初始化閉合：P+4/P+8是數值不是Actor pointer

|本地路徑|P取得方式|P+4|P+8|必要條件|
|---|---|---|---|---|
|index8 0x4AF530 new P|malloc 0x2C EDI；4DFFB0插owner+18|4AF649 zero|4AF64C zero|原key找不到有效P且alloc成功|
|index7原先0007|0x4AEC70從[FAB148]找到次級P node+0x10|0x4C6E57寫WORD包ID的零擴展DWORD|4C6E89寫Actor+0x88的WORD零擴展值，缺失4C6E91寫0|0x4AEC77若P+4非零即skip|
|index10原先000A|4AF943在owner次級樹查P，保存在[EBP−4]|4AFA48在第0列寫idA|4AFA7D寫Actor+88低16；若查找無Actor，4AFA85清0|index0一般支線；local owner且idA!=idB走controller pair，不直接寫此P|

~~~asm
4AEC77 83 79 04 00                 cmp dword [ecx+4],0
4AEC7D 0F B7 43 FC                 movzx eax,word [ebx-4]
4AEC81 8B F9                       mov edi,ecx           ; P*
4AEC83 E8 C8 81 01 00              call 0x4C6E50
4C6E57 89 47 04                    mov [edi+4],eax
4C6E6E E8 8D 80 36 00              call 0x82EF00         ; main actor tree lookup
4C6E82 0F B7 88 88 00 00 00        movzx ecx,word [eax+0x88]
4C6E89 89 4F 08                    mov [edi+8],ecx
4C6E91 C7 47 08 00 00 00 00        mov [edi+8],0

4AFA04 66 8B 4C 98 07              mov cx,word [eax+ebx*4+7]
4AFA09 66 3B 4C 98 09              cmp cx,word [eax+ebx*4+9]
4AFA16 E8 45 F6 F5 FF              call 0x40F060
4AFA2B 8B 52 08                    mov edx,[edx+8]       ; controller virtual pair
4AFA30 FF D2                       call edx
4AFA37 85 DB                       test ebx,ebx         ; first row only
4AFA48 89 70 04                    mov [eax+4],esi      ; P+4=idA
4AFA7D 89 50 08                    mov [eax+8],edx      ; P+8=Actor+88 WORD
4AFA85 C7 41 08 00 00 00 00        mov [ecx+8],0       ; no matching Actor
~~~

獨立完整BIN掃描 E8 rel32候選：0x4DFFB0只有0x4AF6EC direct caller；0x4C6E50只有0x4AEC83；這兩個在根CFG驗證。**但是**index10由函式內直接store實現，不會以直接E8出現。也可能有virtual/alias/批次複製及其它handler writer，不能因掃E8只有兩站就宣告P+4/+8所有writer全局排他。此難點仍屬Client待逆向，而非Server-only未知。

## 4. index26與index81的真正Actor移除條件，不能混為一種函式

26入口0x4B28D0：len>=4時逐WORD從B+4讀key（count=floor((len−4)/2)），0x4B297A為完整六byte比較而非舊4B297C半指令。先對特定Actor type有條件subobject cleanup，後掃Controller 3個raw槽。**只有任一非null slot的WORD(Actor+4)匹配待刪key**，0x4B2A82–87才調controller virtual+0x14清槽；然後以原始包key 0x4B2ABD→0x4B2AC2 call 0x4DFBC0移除主Actor樹。

~~~asm
4B295C 0F B7 02                     movzx eax,word [edx]
4B297A 3B 05 3C B1 FA 00            cmp eax,[0xFAB13C]
4B2982 8B 70 10                     mov esi,[eax+0x10]   ; actor*
4B2A56 8B 0D A4 A7 FB 00            mov ecx,[0xFBA7A4]
4B2A5C 66 8B 76 04                  mov si,word [esi+4]
4B2A62 8D 51 0C                     lea edx,[ecx+0xC]
4B2A6B 66 39 77 04                  cmp word [edi+4],si
4B2A73 83 C2 0C                     add edx,0xC
4B2A76 83 F8 03                     cmp eax,3
4B2A82 8B 01                        mov eax,[ecx]
4B2A84 8B 50 14                     mov edx,[eax+0x14]
4B2A87 FF D2                        call edx               ; conditional controller clear
4B2ABD B8 30 B1 FA 00               mov eax,0xFAB130
4B2AC2 E8 F9 D0 02 00               call 0x4DFBC0         ; main Actor tree erase
~~~

81入口0x4B3710：len>=2，B+2起每WORD OR 0x06000000組成composite key；0x4B3739 call 0x40F060取得owner；0x4B373E call 0x4DFC90遍歷主Actor樹，0x4DFCB6以[Actor+0x88] DWORD比對，命中0x4DFCC3會呼叫**Actor自己的vtable+0x14**，然後0x4DFCE1 call 0x7B6890刪主樹節點。此路沒有26的直接Controller slot14清槽站點，但不能據此肯定Actor的多型析構一定不會間接操作controller。

~~~asm
4B3730 0F B7 06                     movzx eax,word [esi]
4B3733 0D 00 00 00 06                or eax,0x06000000
4B3739 E8 22 B9 F5 FF               call 0x40F060
4B373E E8 4D C5 02 00               call 0x4DFC90
4DFC96 8D 78 08                     lea edi,[eax+8]       ; main Actor tree
4DFCB6 39 81 88 00 00 00            cmp [ecx+0x88],eax
4DFCC0 8B 42 14                     mov eax,[edx+0x14]   ; Actor virtual method
4DFCC3 FF D0                        call eax
4DFCE1 E8 AA 6B 2D 00               call 0x7B6890
~~~

主Actor tree generic erase 0x4DFBC0對三次Controller virtual+0x1C做getter，但不在該函式直接清3槽／不直接寫二級P+4/+8；Actor virtual+0x14的實際派生副作用須繼續辨識。P+4、P+8是數值欄位而非raw Actor*，不能用「沒有清零」一項判定UAF。

## 5. Controller slot+0x14 真PE多型清理：一般與Tag有可驗旗標差異

一般Controller (0x545210) 和 CTagController (0x444910) 都將三個Actor raw slots +0xC/+0x18/+0x24置0；另外把Controller+0x34 (pair vector end) 改成+0x30 (begin) **logical clear**，沒有釋放pair buffer，也沒有erase Controller+0x48 H歷史樹或owner+0x18 P樹。一般Controller寫三個flag +0x14/+0x20/+0x2C=1；Tag在+0x20/+0x2C寫0（與一般不同）。

~~~asm
545210 33 C0                         xor eax,eax
545212 89 41 0C                      mov [ecx+0xC],eax
545215 89 41 18                      mov [ecx+0x18],eax
54521D 88 51 14                      mov [ecx+0x14],dl       ; =1
545223 88 51 20                      mov [ecx+0x20],dl       ; =1
545226 89 41 24                      mov [ecx+0x24],eax
54522C 88 51 2C                      mov [ecx+0x2C],dl       ; =1
54522F 8B 51 30                      mov edx,[ecx+0x30]
545233 8B 71 34                      mov esi,[ecx+0x34]
54523C 3B F6                         cmp esi,esi             ; always equal on this path
545256 89 51 34                      mov [ecx+0x34],edx     ; end=begin
444910 33 C0                         xor eax,eax
444912 89 41 0C                      mov [ecx+0xC],eax
444915 89 41 18                      mov [ecx+0x18],eax
444929 88 41 20                      mov [ecx+0x20],al       ; Tag=0
44492C 88 41 2C                      mov [ecx+0x2C],al       ; Tag=0
444956 89 51 34                      mov [ecx+0x34],edx     ; end=begin
~~~

區間0x545240–255表面包含一段copy循環，但從root入口成功走到54523C之比較ESI和自身後立即跳545256；不應根據不可達的簡單線性反組譯把它描述成正在copy全vector。正確效果是把有效end改回begin。Controller+0x48 H tree在slot14之外仍可能由其它方法消費/清理，不能因本方法無erase就說從不清。

## 6. P二級record的指定free和reset，不能混成主Actor erase

0x4BBAE0取 [packet+2] DWORD key，0x4BBB4B call 0x4DFC30，該函式0x4DFC39使用 [owner+0x18] 作P tree lookup。存在cached owner+F8 且其P+0 key等於被刪key才0x4DFC60清cache，再從二級node+0x10取得P*，0x4DFC72 call 0x89120C free P，0x4DFC80 call 0x7B6890 erase P tree node。它不在此直接刪主Actor tree。這裡P已釋放，沒有必要在free前再清數值P+4/+8；不能把P未顯式清零當清理缺陷。

~~~asm
4BBB42 8B 48 02                    mov ecx,[eax+2]
4BBB4B E8 E0 40 02 00              call 0x4DFC30
4DFC39 8D 5E 18                    lea ebx,[esi+0x18]
4DFC42 E8 79 3C 36 00              call 0x8438C0
4DFC4F 8B 86 F8 00 00 00           mov eax,[esi+0xF8]
4DFC5B 3B 4D 08                    cmp ecx,[ebp+8]
4DFC60 C7 86 F8 00 00 00 00        mov [esi+0xF8],0
4DFC6A 8B 47 10                    mov eax,[edi+0x10]
4DFC72 E8 95 15 3B 00              call 0x89120C
4DFC80 E8 0B 6C 2D 00              call 0x7B6890
~~~

另一命令本地index16 0x4B1A30的有界順序是：0x4DFD40按type0篩選刪Actor → Controller virtual+0x14清slot → owner+0xF8清cache → 0x4E1070全二級P tree釋放與sentinel/count reset。0x4E1070 先遍歷P tree，0x4E108A free每個 P*，最後0x4E1111/1117/111D把tree sentinel指回自己，0x4E1121把count設0。這不是「所有Actor無條件reset」，type1等依不同路徑處置。

## 7. 實際直接xref掃描與失效的全域排他推論

從完整原BIN .text按每個0xE8及signed rel32重算目標，並且把列明caller放回各函式根入口核：

|target|direct E8位址候選（已驗列明caller）|影響|
|---|---|---|
|4DFF30|4A11B6、4AA222、4AEC03、4AF4F7、4B2F83|主Actor tree insert（不是P tree）|
|4DFFB0|**4AF6EC**|P次級樹插入|
|4C6E50|**4AEC83**|index7 一次性P+4/+8綁定helper|
|4DFC30|**4BBB4B**|指定次級P刪除|
|4DFC90|**4B373E**|index81的Actor+0x88 composite erase|
|545040|5476F8|Controller add/索引實體；virtual方法可能另有間接caller|

Direct E8=0 不會排除Handler／Controller虛擬入口。這些只是靜態字節候選及已根入口核實的一部分；**沒有**做到對所有可能拿到P*的間接函式、owner+F8 cached pointer、tree node payload、memcpy/bulk writer的全域CFG閉合。故本輪不能把 P+4/P+8 writer全集標為已證排他。

## 8. 已整合的T08-202條件性鏈與Server交接

本地handler 8 → owner P 0x2C分配/owner+18 insert（或同keyrefresh不重設P+4/+8）；
本地handler 7 → 建Actor/條件設定 P+4/+8；
本地handler 10 → local特殊pair進Controller+0x30 8-byte vector（slot+8=5451D0），由前置已驗update tick 0x491CB6→4E0060→Controller slot+2C→5452C0 second pass→slot+44=546EF0；可條件性輸出FE38D0 5-byte state，後經CIocpNetwork+10入網路佇列、mode2優先XOR/checksum / 失敗fallback plain、WSASend/GQCS；
本地handler26／81 → 兩種不同的主Actor移除；指定P移除另走4BBAE0，type0 reset先主樹再控制槽再P樹。

**玩家情境矩陣**：

|場景|Client原生已證|Client仍未知|Server待開發與跨Task|
|---|---|---|---|
|owner record建立|index8 新P+4/+8初始0，key同值刷新保留；owner+18與+F8來源|所有owner類型/別名持有者對P其餘欄位的副作用|T02確定wire framing/業務domain，Server提供相容內容|
|Actor生成與綁定|index7/10按不同gate寫P numeric ID及Actor+88低16；index10特殊pair不寫P|全部P+4/+8間接writer和跨模式清零|Server生成時機/波次屬設計，不等於官方內部規則|
|特定Actor移除|26匹配Controller raw槽才先clear再erase；81按Actor+88 composite erase且無直接controller clear|所有Actor vtable+14派生副作用、controller H-tree其他reset|T06/T07/T14場景和玩家可見退場驗證|
|P單獨移除/reset|4DFC30 free P+erase node、4E1070全部free P；特別cache+F8按key清|同幀競態、其餘owner條件|動態/跨Task整合另行|

**分工**：Client待逆向：1)所有P+4/+8 alias writer，尤其owner+F8和secondary tree以外的指標傳遞；2)81 Actor vtable+14在所有動態型別的Controller副作用；3)Controller+48 H-tree consumer與所有清理。Server待開發：原版Server內部判定不可由這些本地handler逆推，相容Server只實作已核的Client要求；跨T02封包與T06/T07/T14場景須另接；遊玩驗證與靜態本地分析不同。上述1–3都是尚可在Client原BIN繼續研究的靜態缺口，**並非因缺少原版Server或實機就停止**。

**完成裁決**：本批取得新而有界的完整原生鏈並完成文件/提交，但因原交接明列的P全alias writer與81派生owner cleanup仍無全域證明，**T08-202整體暫不可真實標成FINISHED**。保留IN_PROGRESS、明確地址與下一步；不擅自改舊T01、S00或RR驗收。提交此稿不等於獲得T01 FULL-PASS。
