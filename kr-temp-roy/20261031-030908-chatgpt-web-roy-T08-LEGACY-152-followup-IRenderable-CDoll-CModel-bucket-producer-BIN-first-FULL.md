# T08／T01 LEGACY-MAPPING 勘誤續查 — IRenderable 派生 CDoll / CModel 分界，CModel 的全域分桶雙寫入者

研究者：chatgpt-web roy；時區 Asia/Taipei；檔案時間 2026-10-31 03:09:08 +0800；KR 客戶端靜態逆向，**階段性原生證據稿；整體退回尚未完成**。

## 0. 第一手證據／既有來源

- 唯讀原始檔 **Tartaros.bin**，12,472,320 bytes；本輪 SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**。
- PE .text VA 0x401000，raw 0x400，code raw = VA−0x400C00；.rdata VA 0xBD2000 raw 0x7D0600，rdata raw=VA−0x401A00；.data VA 0xD61000 raw 0x95E800。以正確 .text 切片後 GNU objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 反組譯全段；原始DWORD以 Python struct little-endian直接讀取，獨立從code bytes驗E8 rel32。
- 工作基準：前輪新的 T08-152真PE/RTTI勘誤 kr-temp-roy/20261031-025103-chatgpt-web-roy-T08-152-native-PE-RTTI-vtable-and-producer-xref-corrections-FULL.md（blob 14813f82c72673a0ffe271dcdc23ad6abcb106f3），與134–151原生修訂索引（blob c65530704ffde0106a47a98f4f585dc8da6cebb4）；**原 T08-129～152 FAILED source不得覆寫**。T01-RETURN-T08-LEGACY-MAPPING-001 仍 NEEDS_FIX。
- 研究目標：除了修復「vtable target是半指令」錯誤，針對新發現的 primary vtable slot+8 追查**真正的record/22桶入列者與身份界線**；定位真PE入口與分支、正確pointer owner、明確區分CDoll的B queue與CModel的全域bucket producer，避免不同型別都叫slot+8就誤判為單一函式。

## 1. MSVC RTTI 兩個獨立派生類，**共用 IRenderable、互不直接繼承**

按PE原生 .rdata 的 MSVC x86 CompleteObjectLocator (COL) 格式：signature, offset, cdOffset, TypeDescriptor*, ClassHierarchyDescriptor*。解析CHD的baseClassArray及BaseClassDescriptor->TypeDescriptor名字（原生ASCII，非人工命名）：

|COL | 5 DWORD | TypeDescriptor原名 |
|---|---|---|
| 0xC7FA7C | 0, 0, 0, F8A718, C7FA90 | .?AVCDoll@IS3D@@ |
| 0xC80104 | 0, 0, 0, F8A990, C80118 | **.?AVCModel@IS3D@@** |
| 0xC7FA40 | 0, 0xC, 0, F8A718, C7FA90 | CDoll +0xC embedded subobject |
| 0xC69F48 | 0, 0, 0, F7E264, C69F5C | std::tr1::_Ref_count<CDoll> |

- **CDoll CHD @0xC7FA90**：raw DWORD [0,1,6,0xC7FAA0]，共**6**筆base descriptions。依序解析TypeDescriptor名字：CDoll、IRenderable、IObject、IDXManagedObject、CShadowCaster、enable_shared_from_this<CDoll>。其中IRenderable BCD @0xC7F804，IObject的member displacement為+4，IDXManagedObject為+8，CShadowCaster為+0xC。
- **CModel CHD @0xC80118**：raw DWORD [0,0,2,0xC80128]，共**2**筆base descriptions。依序為**CModel、IRenderable**（同一IRenderable BCD @0xC7F804）；沒有CDoll。
- 結論：**CDoll與CModel皆可經IRenderable介面派送，但不能把二者當同一個vtable/object，亦無來源證明二者一者直接繼承另一者**。兩表都是各自 RTTI offset0 的primary vtable；slot +8相同只是ABI/介面契約可能相容，**方法實作不同**。

## 2. 完整真PE vtable對照與method指標起源

~~~text
C4F678 = C7FA7C       CDoll primary COL（offset 0）
C4F67C = 7A4FF0       CDoll vfptr+0
C4F680 = 77B4E0       CDoll vfptr+4
C4F684 = 7A63C0       CDoll vfptr+8: guarded B producer

C4F6BC = C7FA40       CDoll secondary COL（offset +0xC）
C4F6C0 = 7AAA90       CDoll secondary vfptr+0: this-=0xC thunk
C4F6C4 = 7A8310       CDoll secondary vfptr+4: record execute
C4F6C8 = 7A8E10       CDoll secondary vfptr+8: squared-distance score
C4F6CC = C7F9F4       NEXT CLASS COL，不是CDoll的第四個slot

C500D0 = C80104       CModel primary COL（offset 0）
C500D4 = 7D2EE0       CModel vfptr+0: deleting dtor wrapper
C500D8 = 409510       CModel vfptr+4: 本輪不命名
C500DC = 7D3470       **CModel vfptr+8: direct bucket + helper producer**
C500E0 = 7D33D0       CModel vfptr+0xC: 複合render/other候選
C500E4 = 69757145       ASCII資料；本表沒有無條件+0x10 slot依據
~~~

真正CModel constructor 0x7D2DB0（入口55 8B EC）在0x7D2DE7執行 **C7 06 D4 00 C5 00: mov [esi],0xC500D4**；在0x7D2E11..3D把多個float填0與1（含0x5C），在0x7D2E4C push 0x1C分配後設定+0x74成員，再初始化CModel +0x88/+0x98/+0xA8的動態容器。相對的vtable+0 destructor於0x7D2EE0有效進入，0x7D2EE6直接call 0x7D2F10，並視flag位0釋放物件。可把vtable與constructor來源連成同一型別，**非只因DWORD像code address就猜類別**。

~~~asm
7D2DB0 55 8B EC                      ; CModel ctor rooted入口
7D2DD7 8B 75 08                     mov esi,[ebp+8]
7D2DE7 C7 06 D4 00 C5 00            mov dword [esi],0xC500D4
7D2DED C7 46 04 04 00 00 00         mov dword [esi+4],4
7D2DF4 C7 46 08 0E 00 00 00         mov dword [esi+8],0xE
7D2DFB C7 46 0C 07 00 00 00         mov dword [esi+0xC],7
7D2E11 D9 56 28                     fst dword [esi+0x28]
7D2E3D D9 5E 5C                     fstp dword [esi+0x5C]
7D2E4C 6A 1C                        push 0x1C
7D2E52 E8 11 E4 0B 00               call 0x891268
7D2E77 89 46 74                     mov [esi+0x74],eax
7D2EC2 E8 E9 08 00 00               call 0x7D37B0
~~~

## 3. 真 0x7D3470 的兩個**直接寫同一全域分桶族**的有效分支

CModel vtable slot+8是真 **0x7D3470**；從有效函式入口重解，this ECX保存在EBX，初始EDI=1。先以x87比較[EBX+0x5C]和rdata QWORD[0xC55820]，不同x87 flags會選兩個寫入分支，不能只憑JP/test ah 0x5推說“官方遠近/透明排序規則”。兩分支均讀動態全域bucket base pointer **[0xFB7740]**：

~~~asm
7D3470 55 8B EC                      push ebp; mov ebp,esp
7D349C 8B D9                         mov ebx,ecx
7D34A5 BF 01 00 00 00               mov edi,1
7D34D4 D9 43 5C                     fld dword [ebx+0x5C]
7D34D7 DC 1D 20 58 C5 00            fcomp qword [0xC55820]
7D34DD DF E0                        fnstsw ax
7D34DF F6 C4 05                     test ah,5
7D34E2 0F 8A 86 00 00 00            jp 0x7D356E ; alternative branch

; Branch A: CModel+4 index or model vfptr+4 fallback
7D34E8 8B 43 04                     mov eax,[ebx+4]
7D34EB 8B 35 40 77 FB 00            mov esi,[0xFB7740]
7D34F1 85 C0                        test eax,eax
7D34F3 75 09                        jne 0x7D34FE
7D34F5 8B 03                        mov eax,[ebx]
7D34F7 8B 50 04                     mov edx,[eax+4]
7D34FA 8B CB                        mov ecx,ebx
7D34FC FF D2                        call edx
7D34FE 69 C0 04 20 00 00            imul eax,eax,0x2004
7D3504 8B 8C 30 00 20 00 00         mov ecx,[eax+esi+0x2000]
7D350B 03 C6                        add eax,esi
7D350D 81 F9 00 08 00 00            cmp ecx,0x800
7D3513 7D 09                        jge 0x7D351E
7D3515 89 1C 88                     mov [eax+ecx*4],ebx
7D3518 01 B8 00 20 00 00            add dword [eax+0x2000],edi ; EDI=1

; Branch B: CModel+74 subordinate guard, other index or model vptr+4 fallback
7D356E 8B 43 74                     mov eax,[ebx+0x74]
7D3571 83 78 18 00                  cmp dword [eax+0x18],0
7D3575 74 36                        je 0x7D35AD
7D3577 8B 43 04                     mov eax,[ebx+4]
7D357A 8B 35 40 77 FB 00            mov esi,[0xFB7740]
7D3580 85 C0                        test eax,eax
7D3582 75 09                        jne 0x7D358D
7D3584 8B 13                        mov edx,[ebx]
7D3586 8B 42 04                     mov eax,[edx+4]
7D3589 8B CB                        mov ecx,ebx
7D358B FF D0                        call eax
7D358D 69 C0 04 20 00 00            imul eax,eax,0x2004
7D3593 8B 8C 30 00 20 00 00         mov ecx,[eax+esi+0x2000]
7D359A 03 C6                        add eax,esi
7D359C 81 F9 00 08 00 00            cmp ecx,0x800
7D35A2 7D 09                        jge 0x7D35AD
7D35A4 89 1C 88                     mov [eax+ecx*4],ebx
7D35A7 01 B8 00 20 00 00            add dword [eax+0x2000],edi ; EDI=1
~~~

**精確本地條件**：已知init EDI=1，且x86 EDI callee-preserved（本函式也保存/復原EDI）；上列寫入真正是**把 CModel this 的指標放入 bucket[index][count] 並增加count 1**，不是加一個指標的數值，也不是零長度清空。兩分支各先讀count和比較0x800，安全範圍僅對於指標、bucket index、bucket base有效的前提成立。**沒有**證明index在0..21、底層bucket實體長度，因為本函式未查它；“22桶”數量需引用既有consumer與分配證據，勿由單個0x2004 stride臆斷。

## 4. 同一CModel實作還會呼叫0x79A3C0：真正owner pointer和bucket identiy

Branch A的後段有全域 [0xFB7990] gate，可能從 CModel+[0x28/2C/30] 三DWORD context經0x79BC80得到index候選，然後視ret與fallback選擇 **CModel+0x0C/+0x08**。Branch B同樣有gate條件（CModel+[0x74]+0x14）。精確正常分支：

~~~asm
7D351E A1 90 79 FB 00               mov eax,[0xFB7990]
7D3526 0F 84 CB 00 00 00             je 0x7D35F7
7D3534 8B 43 28                     mov eax,[ebx+0x28]
7D3537 8B 4B 2C                     mov ecx,[ebx+0x2C]
7D353A 8B 53 30                     mov edx,[ebx+0x30]
7D3549 B8 A8 76 FB 00               mov eax,0xFB76A8
7D3552 E8 29 87 FC FF               call 0x79BC80
7D3559 B9 A8 76 FB 00               mov ecx,0xFB76A8
7D3566 8B 43 0C                     mov eax,[ebx+0x0C]
7D3569 E9 93 00 00 00               jmp 0x7D3601
7D35B0 83 79 14 00                  cmp dword [ecx+0x14],0
7D35B4 74 50                        je 0x7D3606
7D35F2 8B 43 0C                     mov eax,[ebx+0xC]
7D35F7 B9 A8 76 FB 00               mov ecx,0xFB76A8
7D35FC 8B FB                        mov edi,ebx
7D35FE 8B 43 08                     mov eax,[ebx+0x08]
7D3601 E8 BA 6D FC FF               call 0x79A3C0

79A3C0 56                           push esi
79A3C1 8B B1 98 00 00 00            mov esi,[ecx+0x98]
79A3C7 85 C0                        test eax,eax
79A3C9 75 09                        jne 0x79A3D4
79A3CB 8B 17                        mov edx,[edi]
79A3CD 8B 42 04                     mov eax,[edx+4]
79A3D0 8B CF                        mov ecx,edi
79A3D2 FF D0                        call eax
79A3D4 69 C0 04 20 00 00            imul eax,eax,0x2004
79A3DA 8B 8C 30 00 20 00 00         mov ecx,[eax+esi+0x2000]
79A3E1 03 C6                        add eax,esi
79A3E4 81 F9 00 08 00 00            cmp ecx,0x800
79A3EA 7D 09                        jge 0x79A3F5
79A3EC 89 3C 88                     mov [eax+ecx*4],edi
79A3EF FF 80 00 20 00 00            inc dword [eax+0x2000]
79A3F5 C3                           ret
~~~

**已閉合的實際指標別名**：0xFB76A8是**固定manager物件地址**（本地ECX設為立即常數，不是mov ecx,[...])。0xFB76A8+0x98=**0xFB7740**，所以helper所讀的 **[ECX+0x98]=[0xFB7740]** 就是0x7D34EB/0x7D357A直接載入的同一global bucket base pointer。0x79A3C0會以fallback index與EDI（即CModel*this）寫同一全域分桶群。此位址等式加上兩側的原生load與store，**是本輪新的上下游實證閉合**；不是僅因字段offset相同做推測。

和此前T08-129/130的callback consumer也有物理呼應：0x799F20於0x799F99/0x799FA1取得vtable+0x0C和[EDI+0x98]；若EDI=0xFB76A8，傳給真callback **0x7D1310** 的stack owner是 [0xFB7740]；0x7D13C4+0x4004 count、0x7D13DC+0x2004+index*4讀出該全域bucket內先前存入的interface物件指標，再呼叫各自vptr+0x0C。**但不能只靠這段單讀bucket 1就宣稱每個bucket或同幀執行時序都完成驗證。**

## 5. 和CDoll B queue的跨型別分界：相同slot並不等於B→bucket因果

從真RTTI及已核指令：
- **CDoll primary vptr C4F67C +8 → 7A63C0**：在 Host+0x1C/+0x124等guard和B manager條件下，將 **CDoll+0xC embedded subobject** 入 [0xFBA838] owner B vector (+B4/+B8/+BC)。此方法本身在已核寫入視窗**不直接寫 [0xFB7740] buckets**。
- **CDoll secondary vptr C4F6C0 +8 → 7A8E10**：B selection時經 x87算三維相對位置平方分數；+4 → 7A8310，在條件路可能創建record並透過 E8 7A8618→7E8240 keyed registry。此前只有record registry證據，**沒有**從此直接到CModel+8或全域bucket新增write的已驗CFG。
- **CModel primary vptr C500D4 +8 → 7D3470**：有兩個**直接 [0xFB7740] bucket store**，且另一條有效分支 E8 7D3601→79A3C0 再寫同一族bucket。它是IRenderable的**另一實體**，不能因CDoll也繼承IRenderable便說B consumer必定呼叫CModel方法。

介面資料流的正確最小圖：

~~~text
                         RTTI: IRenderable (共同基底)
                         /                        \
          CDoll 主vtable +8                   CModel 主vtable +8
          7A63C0（guarded B入列）              7D3470（two bucket branches）
                |                                   |
          [FBA838] manager B vector             [FB7740] bucket base <------+
                |                                   ^                      |
          7BB240 selector / front N                  |                      |
                |                                   |                      |
         CDoll sub+0C fn4 7A8310                      +-- E8 79A3C0 <-7D3601
                |
       7E8240 keyed record registry
                |
         （**此邊到bucket仍未由原生CFG閉合**）

[FB76A8] manager + 0x98 => [FB7740]；799F20 + callback 7D1310讀bucket。
~~~

**別名及生命週期的重要限制**：CDoll及CModel都可能由不同上游render dispatcher呼叫IRenderable slot+8；本稿沒有找到真正scene loop的operand+calling ECX origin，不能擅稱兩者會在固定frame順序同時運作，亦不能將“record”當“model”或CModel的this誤認CDoll+0xC。CModel的本地22桶writer鏈**獨立成立**，但CDoll B→22桶**仍待**找真record/model綁定與caller；不能以新發現提前結案。

## 6. 負面查證、研究深化與接續核驗

本輪在原始整個12,472,320 bytes作little-endian exactDWORD搜尋、並在正確 .text raw [0x400,0x7D0600)按E8 rel32模式重算target；要區分*候選raw pattern*與rooted executable指令：

|target|全BIN exact DWORD 命中與 raw offset |E8 rel32候選sites|解釋|
|---|---|---|---|
|0x7A63C0|1, 0x84DC84|0|CDoll primary vtable slot+8；未找到direct CALL，不代表virtual不可達|
|0x7D3470|1, 0x84E6DC|0|CModel primary vtable slot+8；同為間接候選|
|0x7D33D0|1, 0x84E6E0|0|CModel primary slot+0x0C，與+8不是同函式|
|0x79A3C0|0|**1, 0x7D3601**|CModel函式內真直接caller，E8 BA 6D FC FF|
|0x7E8240|0|**2, 0x7A8618 / 0x7BA7ED**|CDoll entry record path和另一A vector路，**不是直接bucket writer**|

上表E8掃描沒有CFG保證所有E8 byte都是合法指令邊界；列出的3個具代表性caller（7D3601、7A8618、7BA7ED）已在正確PE函式邊界的objdump中重新觀察。對vtable函式沒有direct E8符合C++虚擬派送，但須追IRenderable參考持有、scene列表與間接call source才證實具體caller。

未解靜態研究（不可單用runtime未測做為停止理由）：
1. IRenderable scene loop在哪裡、如何持有 CModel/CDoll及以哪些指標＋slot+8 dispatch；需追正確virtual caller與owner容器，而非只搜尋directE8；
2. CDoll B entry fn4→record registry→CModel object/ref或其他render submission的真CFG與資料欄位；這一項影響**B是否能造成bucket寫入**；
3. CModel+0x74 subordinate object的兩個flags如何被初始化、更改與恢復，以及CModel+0x4/+8/+C index有效範圍；本輪只證支線寫入，不證所有bucket索引合法；
4. callback 7D1310逐bucket consumer所有分支及 CModel vtable+0x0C最終消費副作用，如何影響可見畫面，不能混為Server原生規則；
5. CDoll owner+0x15C shared-control block、Host析構subobject vptr復原與B vector借用指標的同幀安全性。**沒有**runtime資料證明use-after-free存在／不存在。

## 7. 可交付S00的玩家情境與分工，不虛構原版Server決策

|情境|Client本輪一手確證|Client待逆向|Server待開發|跨功能／遊玩驗證|
|---|---|---|---|---|
|渲染/場景物件入全域bucket|CModel(原生RTTI)的vtable+8為7D3470；分支直接向[FB7740] bucket寫入CModel this，並可能E8 79A3C0寫同一base|IRenderable實際update caller、bucket索引來源/範圍、回收/視覺副作用|尚未獲原版Server封包或策略證據，不能將此local render流程視為Server下發怪物波次規則|T02網路與T06/T07場景交接、後續實機|
|CDoll記錄對應的B queue|CDoll primary+8可入B，secondary+8 score、+4有條件登記record|B→CModel→bucket實體關係、完整call及ownership鏈|是否／何時由Server送某entity的數據需要獨立的Client wire證據|封包handler、可玩驗收分開|
|bucket consumer|manager[FB76A8]+98物理等於[FB7740]，callback 7D1310 讀同一bucket家族|逐bucket visitor及UI/scene結果|沒有本段可證的原版Server內部決策|T01原生審核、S00規格准入各自獨立|

**T01結論狀態**：T08-152早期「vtable指入半指令」「producer缺xref」已被之前的RTTI修訂反證；這次更閉合 CModel獨立writer與分桶owner的靜態別名，且從RTTI證實CDoll/CModel是不同IRenderable派生。這**不是**24個legacy來源各篇全文FULL-PASS，更不是B→22桶因果完成；退回總項 LEGACY-MAPPING-001 必須保持 NEEDS_FIX，S00/RR/Server與遊玩驗證不因本稿升格。
