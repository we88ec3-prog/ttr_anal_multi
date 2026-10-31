# T08-202 — Controller pair 第二輪真正生效、CDoll 清理及 P 數值關聯（BIN-first 完整補證）

研究者 chatgpt-web roy；2026-10-31 04:54:59（Asia/Taipei）。一手 KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際 SHA256 相符。PE32 `.text` VA `0x401000` raw `0x400`，真機器碼 raw=`VA−0x400C00`；`.rdata` VA `0xBD2000` raw `0x7D0600`。以 `objdump -d -M intel` 從真 PE 根入口解碼，並用原BIN `struct`+hash、vtable DWORD和 E8 signed rel32獨立覆核；不執行或改動Client。T08/主審T01/Server/遊玩驗收狀態彼此獨立。

## 0. 前置已知與本輪真正新結論

T08-201原生已知本地index8 `0x4AF530`配置0x2C P、`0x4DFFB0`插入Owner+0x18 secondary tree、index7 `0x4AEC83→0x4C6E50`條件綁定P+4/+8、CMonster `4D1910→4C7DF0→7A4C50`分配CDoll並保存在Actor+15C。本輪**不冒稱首次發現**。前次202已確認index10 `0x4AF920`特別分支→Controller `vptr+8=5451D0`入8-byte pair，26與81移除、Owner P重用、P數值的Scene consumer及CIocpNetwork出站鏈。

**202此前關鍵缺口是 pair 是否只被545390消耗而不真的觸發Actor效果；本輪從同一`0x5452C0`的根函式找到`0x5459B7..545B32`第二pass，並從.rdata確認已知六Controller `vptr+0x44 = 0x546EF0`**。另外201的CMonster/CDoll interface+8真target 7A57C0在本輪再次獨立確認，並排除了幾個表面同位移、實際不同型別的P writer假陽性。

## 1. 特殊pair入列者：544? Controller `0x5451D0`

~~~asm
5451d0 55 8b ec               push ebp;mov ebp,esp
5451d6 66 8b 45 08            mov ax,[ebp+8]       ; caller first word idA
5451da 8b 55 0c               mov edx,[ebp+0xc]   ; Actor*
5451e1 0f b7 42 04            movzx eax,word [edx+4] ; Actor ID idB
5451ea 8d 79 30               lea edi,[ecx+0x30]  ; Controller pair vector
5451ed 8d 45 f8               lea eax,[ebp-8]     ; 8 bytes stack pair
5451f7 e8 24 74 fb ff         call 0x4FC620       ; append
545200 c2 08 00               ret 8
~~~

此8-byte pair在已核成功路，其`word[0]`取Actor+4 ID，`word[2]`取caller firstWORD；不是兩個raw Actor pointers，不能混到Controller+0x0C/+0x18/+0x24三raw槽或owner P+4/+8。

## 2. 第二輪真消費：`0x5452C0`由pair兩WORD查Actor，再調Controller virtual+44

Controller vptr+2C=`0x5452C0`。第一pass `0x54537D..0x545400` 用 `[Controller+34]−[Controller+30]>>3`求筆數，`0x54539A`算row=`begin+index*8`，`0x5453D4`取row第一WORD，經主Actor tree檢索。**此第一pass不是唯一的pair作用**。後面經Controller+78/時間/三raw槽狀態gate，第二pass：

~~~asm
54599a 8b 44 24 14            mov eax,[esp+14h]   ; Controller this
54599e 8b 48 34               mov ecx,[eax+34h]   ; vector end
5459a1 2b 48 30               sub ecx,[eax+30h]   ; minus begin
5459ac c1 f9 03               sar ecx,3
5459b7 8b 44 24 18            mov eax,[esp+18h]   ; row index
5459bf 8b 72 30               mov esi,[edx+30h]   ; begin
5459c2 03 c0                  add eax,eax
5459c4 03 c0                  add eax,eax
5459c6 03 c0                  add eax,eax
5459c8 03 f0                  add esi,eax         ; pair row
5459fc 0f b7 16               movzx edx,word [esi] ; row.firstWORD
545a10 39 50 0c               cmp [eax+0Ch],edx  ; main Actor-tree comparison
545a49 8b 70 10               mov esi,[eax+10h] ; found Actor*
545a4c 85 f6                  test esi,esi
545a54 8b 86 e0 00 00 00      mov eax,[esi+0E0h] ; Actor state
545a5e 8b 17                  mov edx,[edi]      ; Controller vptr
545a60 8b 52 44               mov edx,[edx+44h] ; virtual method
545a67 8a 8e e4 00 00 00      mov cl,[esi+0E4h]
545a6d 8b 47 30               mov eax,[edi+30h] ; pair begin again
545a84 03 c1                  add eax,ecx        ; index*8
545a86 0f b7 40 02            movzx eax,word [eax+2] ; row.secondWORD
545a8e 51                     push ecx          ; state output buffer
545a8f 56                     push esi          ; found Actor
545a90 50                     push eax          ; row.secondWORD
545a91 8b cf                  mov ecx,edi       ; Controller this
545a97 ff d2                  call edx          ; Controller.vptr+44
545a99 85 c0                  test eax,eax
~~~

**型別/ABI反證**：`0x545A05 mov eax,[esi+4]`出現在上述搜尋區間，此處ESI已切為RB-tree sentinel，**不是pair row**。若錯把它當row第二DWORD就會推錯資料結構。真正第二WORD來自`545A86`。從成功主樹命中後的第二pass確實有動態Actor輸入與虛擬方法，不可再將pair只視為無副作用的history lookup。

## 3. 六種Controller+44真實函式指標（直接.rdata DWORD）

|原生已知類別|primary vptr|+0x44 方法|
|---|---|---|
|CController|`0xC0F944`|`0x546EF0`|
|CEmptyController|`0xC0F99C`|`0x546EF0`|
|CMissionRoomController|`0xC0FA6C`|`0x546EF0`|
|CSingleController|`0xC0FAC4`|`0x546EF0`|
|CTutorialController|`0xC0FB1C`|`0x546EF0`|
|CTagController|`0xBFB5A4`|`0x546EF0`|

因此在這六種原生建構的vptr仍有效時，`545A97`真callee為`546EF0`；不可推廣未查到的衍生型別及壽命變動。

## 4. `0x546EF0`用pair第二WORD當Actor ID做位置和狀態判斷

~~~asm
546ef0 55 8b ec                  push ebp;mov ebp,esp
546f1c 8b 7d 0c                  mov edi,[ebp+0xc]  ; matched Actor
546f1f 85 ff                     test edi,edi
546f41 8b 87 e0 00 00 00         mov eax,[edi+0xE0]
546f47 8a 9f e4 00 00 00         mov bl,[edi+0xE4]
546f81 0f b7 4d 08               movzx ecx,word [ebp+8] ; pair secondWORD
546f92 b9 38 b1 fa 00            mov ecx,0xFAB138  ; main Actor tree
546f97 e8 64 7f 2e 00            call 0x82EF00     ; look up second Actor
546fa0 3b 05 3c b1 fa 00         cmp eax,[0xFAB13C]
546fac 8b 40 10                  mov eax,[eax+0x10]
546faf 8b 88 a0 00 00 00         mov ecx,[eax+0xA0] ; target position
546fb5 8b 90 a4 00 00 00         mov edx,[eax+0xA4]
546fbb 8b 87 a0 00 00 00         mov eax,[edi+0xA0] ; source position
546fc9 8b 8f a4 00 00 00         mov ecx,[edi+0xA4]
547007 dc c8                     fmul st(0),st
54700d de c1                     faddp st(1),st
547017 e8 54 88 3b 00            call 0x8FF870
547031 0f 86 88 00 00 00         jbe 0x5470BF
54703b ba 00 80 00 00            mov edx,0x8000
547044 66 09 56 02               or word [esi+2],dx   ; output bit
~~~

這是Client內部位置比較與分支更新，不是原版Server如何決定目標或波次的證據。無法僅憑這段宣稱玩家UI何時顯示。

## 5. 結果從同一tick轉為5-byte entry，並有已核CIocpNetwork出站下游

~~~asm
545aeb 66 8b 56 04             mov dx,word [esi+4]    ; Actor ID
545aef a1 d0 48 fe 00          mov eax,[0xFE48D0]   ; current payload length
545af9 8d 50 05                lea edx,[eax+5]
545afc 81 fa 00 10 00 00       cmp edx,0x1000
545b08 8d 80 d0 38 fe 00       lea eax,[eax+0xFE38D0]
545b0e 89 10                   mov [eax],edx        ; 4 bytes
545b10 88 48 04                mov [eax+4],cl      ; 1 byte
545b13 83 05 d0 48 fe 00 05   add dword [0xFE48D0],5
545b38 83 3d d0 48 fe 00 06   cmp dword [0xFE48D0],6
545b43 76 2e                  jbe 0x545B73
545b49 8b 0d 54 a8 fb 00       mov ecx,[0xFBA854] ; CIocpNetwork
545b64 8b 11                   mov edx,[ecx]
545b66 8b 52 10                mov edx,[edx+0x10]
545b69 50                      push eax            ; length
545b6a 68 d0 38 fe 00          push 0xFE38D0      ; 6+5*N bytes
545b6f 6a 00                   push 0
545b71 ff d2                   call edx            ; queued submission
~~~

前置202已在其它原生筆記證明後續有條件 Client 鏈：CIocpNetwork+10=8069A0→8060D0 packet queue→8061A0 framing，mode2優先0BBB XOR/checksum且失敗可fallback mode0的1A68 plain；同Connection ring+5020/[A028]→804B5A/8052AC→network+0C=8068B0 WSASend→GQCS success conn+A050→8077B0扣除已完成bytes。**WSASend提交與OS完成不等於Server收到或Server採取任何原版策略**。

## 6. type1 CMonster 的 Actor+15C 指向CDoll，其次級virtual+8真正是7A57C0

~~~asm
4c8360 53 56 57                push ebx;push esi;push edi
4c8365 8b 87 5c 01 00 00      mov eax,[edi+0x15C] ; Actor child
4c836b 85 c0                   test eax,eax
4c836f 8d 48 08                lea ecx,[eax+8]    ; CDoll secondary subobject
4c8372 8b 01                   mov eax,[ecx]
4c8374 8b 50 08                mov edx,[eax+8]
4c8377 ff d2                   call edx
~~~

T08-201已證CMonster合法建構時child是CDoll，CDoll ctor `7A4CB2 mov [CDoll+8],0xC4F6B0`；原始 `.rdata[0xC4F6B8]=0x7A57C0`。因此CMonster正常動態型別此callee為7A57C0，**不是Controller slot14**。

7A57C0以CDoll+8 this入EBX；7A57EE從自身+118取資源，若非null在7A57FF調該resource vtable+8、再清+118；7A580C依自身+1C phase選分支；phase1可以配置0x38臨時物件、下游7A5680；7A5911清自身+14，7A5949清自身+1C，7A594C寫自身+20=1；7A595A以lock xadd處理control引用；7A5992起釋放自身+144 vector之8-byte records，7A5A01另有自身+100 resource。已核直接指令未寫Owner P+4/+8或Controller三個raw slots，但7A57FF和資源釋放之虛擬子呼叫存在，不能用局部缺直接store宣稱不可能跨物件callback。

## 7. Owner P已核寫入者、讀取者及非P的同偏移假陽性

|Source|真實物件|操作|適用條件|
|---|---|---|---|
|index8 `4AF530` new|0x2C P record|4AF649/4AF64C初始化P+4/P+8為0|201已證，202再核|
|index8 `4AF6F1..4AF781` reuse|同key已有P|更新其它P欄位、不直接改P+4/+8|只限本條refresh成功CFG|
|index7 `4AEC83→4C6E50`|P secondary tree node+10=P|P+4原0才設ID；P+8設Actor+88低WORD或0|不是raw Actor pointer|
|index10 `4AF920`|同P|普通首行覆寫P+4/P+8；特殊local pair改用Controller+30|兩個分支不同|
|Scene::CDuelDecision+30 `4BD600`|P tree node+10=P|4BD728讀P+4作main Actor lookup，成功寫Scene+5EE0/+5ED0|失敗走Controller index0備援|
|其它讀者 `4D6F00/4D70AB`|P tree node+10=P|4D6F2C與4D70D7讀P+4作主Actor ID lookup|值是數字，不是指標|
|`4BBAE0→4DFC30`|P及owner+F8 special cache|清匹配cache、free P並erase P tree|不等Actor主樹刪除|
|`4B1A30→4E1070`|secondary tree全部P|free全部P並重設sentinel/count|限本地type0 reset支線|
|`4BBDFF/4BBE02`|其它malloc 0x18 object|寫該物件+4/+8=0|**不屬P writer**|
|`4C1897/4C346F`|Controller [FBA7A4]*|寫Controller+4狀態|**不屬P writer**|

正面直接root xref追查涉及[0xFAB148]之4AE9、4AEC、4AF0、4AF5、4B06、4BD6、4D6F、4D70等；所有同名offset需先驗真正pointer/allocator/owner。這足以閉合本T08-202已指認輸入/消費者的有限資料流，但**尚未證明全Client所有間接回呼、bulk-copy或其他P alias writer不存在**；不能將相同位元組模式掃描誤當完整whole-program alias analysis。

## 8. 重現／驗證和精確剩餘範圍

本輪本機Python直接以真PE raw offset、原始SHA核對：**58個code byte anchors PASS、6個Controller vtable+44均546EF0、1個CDoll次級vtable+8=7A57C0（共7個slots PASS）、3個E8 rel32 signed target PASS**。原先手工標 `545A93=FF D2` 被byte對照檢出錯位；真 `545A93=88 5C 24 28`、真正 `FF D2` 位於**545A97**，本稿已修訂。

**本批明確完成的Client有界鏈**：本地000A特殊pair→Controller value append→5452C0第二pass→Actor main-tree→Controller+44→Actor狀態/5-byte output→Client正常可提交至WSASend；index7/8/10的owner P數值綁定、26/81和reset的已核局部移除、CMonster/CDoll子資源清理、Scene P+4讀者各有明確入口及型別，無需因缺原版Server停止這些已閉合靜態正面結論。

**仍屬Client可深入但不能虛稱已證全局排他**：其它任意P alias writer（非已知direct xref）、child subresource indirect callback副作用、所有Actor動態類別及其它Scene consumer；若本段完成標準仍明確要求這些「全部」排他證明，T08-202應保持尚未完成，不得因本輪重大新發現自動FINISHED。**Server待開發**：玩家生成、波次、控制策略自行依S00設計，不逆推官方；**跨功能**：T02的S2C business domain、T06/T07/T14實際場景/介面和S00 SPEC/GAP/TEST；**待遊玩驗證**：Client真執行與Server相容、WSASend→OS/對端實際觀測；**T01原生FULL-PASS**：只有獨立審核者可下判。
