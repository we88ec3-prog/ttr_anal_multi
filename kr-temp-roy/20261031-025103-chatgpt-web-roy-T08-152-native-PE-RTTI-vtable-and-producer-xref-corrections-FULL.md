# T08-152 — 原生 PE／MSVC RTTI：CDoll 主虛表入列者與 secondary vtable 入口完整勘誤

研究者：chatgpt-web roy；時間：2026-10-31 02:51:03 Asia/Taipei。KR 原始 Tartaros.bin：12,472,320 bytes，SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**（本輪本機重新核算）。PE .text VA=0x401000、raw=0x400，code raw=VA−0x400C00；.rdata VA=0xBD2000、raw=0x7D0600；.data VA=0xD61000、raw=0x95E800。

歷史來源保持不變：kr-temp-roy/20261027-225400-chatgpt-web-roy-T08-152-vtable-entry-boundary-negative-xrefs.md，原 Git blob **6d50d49aa523a589714a76159169072b2a994145**；T01 LEGACY-MAPPING-001 原稿為 FAILED、整體目前 NEEDS_FIX。本次獨立於T01 9-row mapping表重新讀原BIN，按有效指令入口解碼、掃描全檔 DWORD 與 .text E8；僅為新來源修正，不自行FULL-PASS。

## 一、舊版看似「vtable指向指令中段」的矛盾已撤銷

早期以 objdump -b binary --adjust-vma=0x401000 對完整PE raw0反組譯，錯把 .text raw0x400 當raw0，使顯示的code地址比真PE VA高 **0x400**。但從 .rdata中讀到的 C++ vtable DWORD是**真的絕對程式地址**，不能連同code listing整體減0x400。

| 原稿疑點 | 原生真PE指令與結論 |
|---|---|
| 0x7A8310在 0x7A8300函式中途 | 真 0x7A8300 = C3（ret），真 0x7A8310 = 55 8B EC 83 E4 F8 83 EC 4C，是有prologue的獨立函式 |
| 0x7A8E10在fld displacement裡 | 舊摘錄位址0x7A8E0D的 D9 83 D8 00 00 00實際在 **0x7A8A0D**；真0x7A8E10 = 55 8B EC 83 EC 0C 是有效入口 |
| 0x7A3920在add esp,4裡 | 舊摘錄0x7A391F的83 C4 04實際在**0x7A351F**；真0x7A3920從85 C9 74 09開始，是合法短helper |
| 0x4CA660是樹操作中途 | 真0x4CA660 = 8B 49 0C 85 C9 74 08 8B 01 8B 10 6A 01 FF D2 C3，實際是自物件虛擬release helper |
| full BIN沒有0x7A67C0的DWORD命中 | 0x7A67C0是錯座標；真producer**0x7A63C0**在raw **0x84DC84**一筆，正是CDoll主vtable的+8方法 |

確實存在舊組語所述的0x7A8A07序列（D9 9B B4 00 00 00；D9 83 D8 00 00 00；DE D9；DF E0），以及0x7A351D（33 D2；83 C4 04；3B C2；74 2E；8B 4E 04）。**舊機器碼本身不是虛構，但錯誤映射造成對真正vtable target的無效反證。**

## 二、MSVC RTTI CompleteObjectLocator：確立CDoll最衍生物件和+0xC embedded view

本次直接在 .rdata 用小端32-bit讀取MSVC x86 RTTI COL 五個DWORD：signature、offset、cdOffset、pTypeDescriptor、pClassDescriptor。TypeDescriptor名字從 .data區TypeDescriptor+8讀取。下表是BIN原生數值，非猜測類別。

| COL VA | 五個 DWORD （依序） | TypeDescriptor名稱 | Subobject |
|---|---|---|---|
| 0xC7FB7C | 0,0,0,F8A734,C7FB90 | .?AVCShadowCaster@IS3D@@ | 基底階段 +0 |
| 0xC7FA7C | 0,0,0,F8A718,C7FA90 | **.?AVCDoll@IS3D@@** | CDoll +0 |
| 0xC7FA68 | 0,4,0,F8A718,C7FA90 | CDoll | +4 |
| 0xC7FA54 | 0,8,0,F8A718,C7FA90 | CDoll | +8 |
| 0xC7FA40 | 0,C,0,F8A718,C7FA90 | CDoll | **+0xC** |
| 0xC7F9F4 | 0,0,0,F8A69C,C7FA08 | std::tr1::_Ref_count<ModelReleaseSpec> | 下一個不同vtable |
| 0xC7F9A8 | 0,0,0,F8A660,C7F9BC | std::tr1::_Ref_count<ModelRequestSpec> | 下一個不同vtable |
| 0xC69F48 | 0,0,0,F7E264,C69F5C | **std::tr1::_Ref_count<CDoll>** | 獨立控制區塊 |

詳細原始 TypeDescriptor names 分別為 .?AVCDoll@IS3D@@、.?AVCShadowCaster@IS3D@@、.?AV?$_Ref_count@UModelReleaseSpec@IS3D@@@tr1@std@@、.?AV?$_Ref_count@UModelRequestSpec@IS3D@@@tr1@std@@、.?AV?$_Ref_count@VCDoll@IS3D@@@tr1@std@@。例 F8A718依.data mapping對應raw B87F18，其+8起為上述CDoll字串。

### 真實vtable的表界／slot（切勿越過下一張COL）

~~~text
rdata VA : DWORD       類別與意義
C4F668 : C7FB7C      CShadowCaster COL
C4F66C : 7A4C20      CShadowCaster base vtable +0
C4F670 : 891FB2      +4
C4F674 : 891FB2      +8
C4F678 : C7FA7C      CDoll COL, offset 0
C4F67C : 7A4FF0      CDoll primary vtable +0
C4F680 : 77B4E0      +4
C4F684 : 7A63C0      **+8 真正 B producer**
C4F688 : 550450      +0C
C4F68C : C7FA68      CDoll COL, offset 4
C4F690 : 7AAA70      secondary +4 vptr +0 (this -=4 thunk)
C4F694 : 7A6FB0      +4
C4F698 : 7A7050      +8
C4F69C : 7A7080      +0C
C4F6A0 : 7A70F0      +10
C4F6A4 : 7A71B0      +14
C4F6A8 : 7A7230      +18
C4F6AC : C7FA54      CDoll COL, offset 8
C4F6B0 : 7AAA80      secondary +8 vptr +0 (this -=8 thunk)
C4F6B4 : 7A5790      +4
C4F6B8 : 7A57C0      +8
C4F6BC : C7FA40      CDoll COL, offset C
C4F6C0 : 7AAA90      secondary +C vptr +0 (this -=C thunk)
C4F6C4 : 7A8310      **+4 execute**
C4F6C8 : 7A8E10      **+8 x87 score**
C4F6CC : C7F9F4      **NOT +0C method**; next class COL
C4F6D0 : 7AAA40      Ref_count<ModelReleaseSpec> vtable +0
C4F6D4 : 7A3920      next table +4
C4F6D8 : 7A3950      next table +8
C4F6DC : 7848C0      next table +0C
C4F6E0 : C7F9A8      Ref_count<ModelRequestSpec> COL
C4F6E4 : 7AAA50      next table +0
C4F6E8 : 7A3920      next table +4
C4F6EC : 7A3950      next table +8
C4F6F0 : 7848C0      next table +0C
~~~

**新勘誤**：前輪把C4F6C0+0x0C的C7F9F4只標為「不明方法／可能非code」，現在由MSVC COL型別與上下文確認它是下一個不同class的**RTTI preceding pointer**，因此C4F6C0這張表在此只有3個method slots。原T08-152將C4F6D4的7A3920誤解為可能CDoll entry方法，應移到不同Ref_count<ModelReleaseSpec>表下。不同vtable共享7A3920 helper不代表相同物件實體。

控制塊獨立證據：C07608 = C69F48（_Ref_count<CDoll> 的COL）；C0760C、10、14、18四DWORD依序為4CA660、7A3920、7A3950、7848C0。C0761C起是ASCII資料，例如 DWORD 6C6C6143（Call），不宜延伸成控制表第5個method。

## 三、真實constructor→primary virtual producer→secondary entry鏈

~~~asm
; CDoll constructor 0x7A4C50；ESI=caller提供的allocated object
7A4C77 8B 75 08               mov esi,[ebp+8]
7A4CA5 C7 06 7C F6 C4 00     mov dword [esi],0xC4F67C
7A4CAB C7 46 04 90 F6 C4 00  mov [esi+4],0xC4F690
7A4CB2 C7 46 08 B0 F6 C4 00  mov [esi+8],0xC4F6B0
7A4CB9 C7 46 0C C0 F6 C4 00  mov [esi+0xC],0xC4F6C0

; primary CDoll vtable+8 -> 0x7A63C0
7A63C0 55 8B EC               push ebp;mov ebp,esp
7A63E8 8B F9                  mov edi,ecx   ; CDoll base this
7A63ED 83 7F 1C 00           cmp dword [edi+0x1C],0
7A63F1 0F 84 92 02 00 00     je 0x7A6689
7A63F7 83 BF 24 01 00 00 00  cmp dword [edi+0x124],0
7A63FE 0F 84 85 02 00 00     je 0x7A6689
7A65D9 8B 35 38 A8 FB 00     mov esi,[0xFBA838] ; global B owner
7A65E5 83 C7 0C              add edi,0xC        ; CDoll embedded+0xC view
7A664F 89 38                 mov [eax],edi       ; non-alias append
7A6651 83 86 B8 00 00 00 04  add dword [esi+0xB8],4

; vtable+0 of subobject +C is this-adjusting virtual thunk
7AAA90 83 E9 0C              sub ecx,0xC
7AAA93 E9 58 A5 FF FF        jmp 0x7A4FF0
~~~

由主vptr建立、RTTI offset=0、slot+8的真正指標與0x7A63C0內ECX→EDI=CDoll*聯合，**已可確認這是CDoll主虛擬方法在正常初始化類型下的 producer 指標**，比原T08-152「完全沒有 producer 上游身分證據」更強。和先前R2有界資料流相接：正常入列CDoll+0xC；B consumer 0x7BB240以前N個entry處理，secondary vptr+8在特定正常vptr時指向0x7A8E10（計算三維相對位置的平方和）；secondary +4指向0x7A8310；後者的條件分支存在到0x7A8618 E8→0x7E8240 record registry。

**但是**：主vtable存在slot+8不等於已找到哪個場景update caller真正dispatch此slot；producer還有0x1C、0x124及其他守門；B非空與entry存活、subobject還未被析構重寫vptr，以及fn4內record登記分支是否達成都有條件。沒有證據把此鏈無條件等同B導入22桶，也沒有Server生成波次/封包證據。

### 正確score入口（不是舊+0x400的假象）

~~~asm
7A8E10 55 8B EC           push ebp;mov ebp,esp
7A8E13 83 EC 0C           sub esp,0xC
7A8E16 8B 45 08           mov eax,[ebp+8]
7A8E19 D9 81 E0 00 00 00 fld dword [ecx+0xE0]
7A8E1F D8 20              fsub dword [eax]
7A8E24 D9 81 E4 00 00 00 fld dword [ecx+0xE4]
7A8E2A D8 60 04           fsub dword [eax+4]
7A8E30 D9 81 E8 00 00 00 fld dword [ecx+0xE8]
7A8E36 D8 60 08           fsub dword [eax+8]
7A8E45..7A8E53           x87 mul/add squared-distance
7A8E5E C2 04 00          ret 4
~~~

以ECX=CDoll+0xC，三個scalar位於CDoll+EC/F0/F4；12-byte context由上游B consumer取得。浮點x87中間會round，近似為dx²+dy²+dz²；不可由此聲稱官方語義為怪物AI距離或玩家畫面排序。

## 四、負面搜尋修正：有真vtable引用，不代表有直接E8 caller

本輪在原件整個BIN做4-byte小端literal查詢；再在真.text raw 0x400..0x7D0600依E8 rel32模式重算target：

|查找值|exact raw DWORD hits|raw offsets|direct E8目標命中|
|---|---:|---|---:|
|舊錯producer 0x7A67C0|0|—|不以舊錯位址驗收|
|**真producer 0x7A63C0**|**1**|**0x84DC84 = primary CDoll vtable+8**|**0**|
|真正secondary execute 0x7A8310|1|0x84DCC4|0|
|真正secondary score 0x7A8E10|1|0x84DCC8|0|
|真正短helper 0x7A3920|7|0x8016DC,0x805C10,0x80B538,0x84DB64,0x84DB78,0x84DCD4,0x84DCE8|0|
|控制helper 0x4CA660|1|0x805C0C|未以本次E8掃描窮盡|
|CDoll主vptr常數 0xC4F67C|2|0x3A40A7,0x3A45ED|n/a|
|CDoll secondary vptr 0xC4F6C0|2|0x3A40BC,0x3A4602|n/a|
|Ref_count<CDoll> vptr C0760C|1|0xC98AC|n/a|

完整BIN原始DWORD搜尋不是「所有xref」；direct E8模式搜尋也不包含透過vtable讀slot+8再間接call的路徑。**結論是有明確的static method target，但具體動態call site尚未取得**；原T08-149/152根據錯目標的零hit無法判定函式不可達。

## 五、明確的下游與完成邊界

有界功能模型（類別名CDoll有RTTI；欄位和函式名只為方便推理）：

~~~cpp
struct CDoll {
    void** primary_vptr; // +0: 0xC4F67C; slot+8=0x7A63C0
    void** sub_vptr4;    // +4: 0xC4F690
    void** sub_vptr8;    // +8: 0xC4F6B0
    void** sub_vptrC;    // +C: 0xC4F6C0; +4 execute, +8 score
};
void primary_slot8_CDoll(CDoll* p /* ECX */) {
    if (!p->gate_1C || !p->gate_124) return;
    // additional guarded routes; B growth and alias protection omitted here
    append_B(globalManager->B, (char*)p+0x0C);
}
~~~

|玩家情境|已證Client|Client待逆向|Server待開發|跨功能/遊玩|
|---|---|---|---|---|
|CDoll進場景本地B queue|主CDoll vptr+8 = 7A63C0，真分支可append CDoll+0xC，B consumer以vptr+4/+8執行entry|找virtual caller與全部gates、實際vptr lifetime、B→22桶因果、正確Actor/record上游|不能從此確立怪物生成策略與波次、封包時序|T02 wire、T06/T07場景、實際runtime與可玩驗證|

**已解的T08-152原始特定疑點**：四個真目標入口、RTTI+vtable與真正B producer間接引用、MSVC不同表邊界。**仍未完成的整體T01退回**：其他來源全文語義與T01正式審核，故LEGACY-MAPPING-001維持NEEDS_FIX；T01 FULL-PASS、RR/S00驗收、Server開發和遊玩驗證分別由其權責判斷。請勿因此跳過尚未完成的T08-202。
