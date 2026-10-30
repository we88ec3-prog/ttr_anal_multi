# T08-145～147 — B-entry 真vptr、三維平方距離分數與 fn4→record registry 有界資料鏈（KR BIN-first）

- 研究者 `chatgpt-web roy`，2026-10-31 Asia/Taipei；原件唯讀 KR `Tartaros.bin`（12,472,320 bytes）SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。不涉及runtime動態追蹤。
- PE 正確映射：`.text` VA0x401000/raw0x400，raw=`VA−0x400C00`；`.rdata` VA0xBD2000/raw0x7D0600。**所有下列子物件vtable DWORD從真rdata讀取，不將指向的絕對函式VA減0x400**；每個虛擬函式於其指向的真PE VA入口重新解碼。
- 原始 source（保留舊Git blob與歷史FAILED）：T08-145 `kr-temp-roy/20261027-221100-chatgpt-web-roy-T08-145-embedded-vptr-construction-candidate.md` blob `f65fa24deba3bb11bb7e95c4fa04468b27b10f06`；T08-146 `kr-temp-roy/20261027-221100-chatgpt-web-roy-T08-146-vtable-slots-and-rdata-section-mapping.md` blob `c80e130172d127172992f00f044a5af89e994174`；T08-147 `kr-temp-roy/20261027-221100-chatgpt-web-roy-T08-147-subobject-vptr-destruction-lifetime-boundary.md` blob `795ae00b864bfb7929546313975550b437dbdab1`。此稿只是新的、由原生bytes支持的**有界修正版本**，T01尚未FULL-PASS。

## 1. Host constructor 的多vfptr寫入是真 0x7A4C50，不是舊 0x7A5050

```asm
7A4C77 8B 75 08                mov esi,[ebp+8]        ; newly constructed Host*
7A4C7F C7 46 04 4C F6 C4 00   mov [esi+4], 0xC4F64C
7A4C86 C7 46 08 78 F8 C0 00   mov [esi+8], 0xC0F878
7A4C8D C7 46 0C 6C F6 C4 00   mov [esi+0xC],0xC4F66C  ; initial subobject vptr
7A4C94 89 5E 10               mov [esi+0x10],ebx
7A4C97 89 5E 14               mov [esi+0x14],ebx
7A4CA5 C7 06 7C F6 C4 00      mov [esi],0xC4F67C
7A4CAB C7 46 04 90 F6 C4 00   mov [esi+4],0xC4F690
7A4CB2 C7 46 08 B0 F6 C4 00   mov [esi+8],0xC4F6B0
7A4CB9 C7 46 0C C0 F6 C4 00   mov [esi+0xC],0xC4F6C0 ; derived vptr
7A4CC0 89 46 18               mov [esi+0x18],eax
7A4CC3 89 5E 1C               mov [esi+0x1C],ebx
```

同一 `Host+0x0C` 記憶體位置被初始vfptr `0xC4F66C` 改寫為 `0xC4F6C0`，**不是二個分配出的獨立B entry物件**。真producer `0x7A63C0` 在 `0x7A65E5` 將Host指標加0xC，再加入 `[0xFBA838]` 所指manager的B-vector；因此在**建構完成且vptr尚未被destructor還原**的有界條件下，B元素可指向這個embedded subobject。

## 2. 真 `.rdata` 中 secondary vtable+0/+4/+8 構成實際fn ABI

真 `.rdata`：`0xC4F6C0 - 0xBD2000 + 0x7D0600 = 0x84DCC0`。連續八個原始 little-endian DWORD：

|Slot|vtable 讀出真VA|真 PE 指令入口／界線|
|---|---|---|
| `0xC4F6C0+00` | `0x7AAA90` | **this-adjustment thunk** `83 E9 0C; E9 58 A5 FF FF`：ECX -=0x0C，jmp `0x7A4FF0` |
| `+04` | **`0x7A8310`** | `55 8B EC 83 E4 F8 83 EC 4C`；實體多型execute，非「指令中間」 |
| `+08` | **`0x7A8E10`** | `55 8B EC 83 EC 0C 8B 45 08`；x87 float score，非「指令中間」 |
| `+0C` | `0xC7F9F4` | 本稿只記錄DWORD（可能非一般code；未驗）|
| `+10` | `0x7AAA40` | 尚需另析函式體|
| `+14` | `0x7A3920` | 尚需另析函式體|
| `+18` | `0x7A3950` | 尚需另析函式體|
| `+1C` | `0x7848C0` | 尚需另析函式體|

另在 `0xC4F66C`（真rdata raw `0x84DC6C`）讀出前八個DWORD為 `7A4C20,891FB2,891FB2,C7FA7C,7A4FF0,77B4E0,7A63C0,550450`；這是initial vptr附近的原始資料，不能把連續常數無證擬造成一個完整C++ class。**重大修正**：舊T01「`7A8310`／`7A8E10`似乎位於指令中途」的早期懷疑，源於舊 `.text` 映射錯置；它們在真正PE有有效prologue，並由真rdata vtable直接指向。

## 3. +08 真實 score 是三維距離的平方和，非僅「不明浮點」

```asm
7A8E10 55                    push ebp
7A8E11 8B EC                 mov ebp,esp
7A8E13 83 EC 0C              sub esp,0xC
7A8E16 8B 45 08              mov eax,[ebp+8]       ; 12-byte context xyz
7A8E19 D9 81 E0 00 00 00     fld dword [ecx+0xE0]
7A8E1F D8 20                 fsub dword [eax]
7A8E21 D9 5D F4              fstp dword [ebp-0xC]
7A8E24 D9 81 E4 00 00 00     fld dword [ecx+0xE4]
7A8E2A D8 60 04              fsub dword [eax+4]
7A8E2D D9 5D F8              fstp dword [ebp-8]
7A8E30 D9 81 E8 00 00 00     fld dword [ecx+0xE8]
7A8E36 D8 60 08              fsub dword [eax+8]
7A8E39 D9 5D FC              fstp dword [ebp-4]
7A8E3C D9 45 F4              fld dword [ebp-0xC]
7A8E3F D9 45 F8              fld dword [ebp-8]
7A8E42 D9 45 FC              fld dword [ebp-4]
7A8E45 D9 C1                 fld st(1)
7A8E47 DE CA                 fmulp st(2),st
7A8E49 D9 C2                 fld st(2)
7A8E4B DE CB                 fmulp st(3),st
7A8E4D D9 C9                 fxch st(1)
7A8E4F DE C2                 faddp st(2),st
7A8E51 DC C8                 fmul st(0),st
7A8E53 DE C1                 faddp st(1),st
7A8E55 D9 5D 08              fstp dword [ebp+8]
7A8E58 D9 45 08              fld dword [ebp+8]
7A8E5B 8B E5                 mov esp,ebp
7A8E5D 5D                    pop ebp
7A8E5E C2 04 00              ret 4
```

`ECX` 是指向 **Host+0x0C** 的B entry，因此 `[ECX+0xE0/E4/E8]` 分別是 Host `+0xEC/+0xF0/+0xF4` 三維座標樣式欄位；`[EAX+0/+4/+8]` 是傳入的12-byte context。在分支和有效float前提下，x87依次做：

```cpp
// Derived behavior, not source C++ symbols
float dx = *(float*)(entry + 0xE0) - context[0];
float dy = *(float*)(entry + 0xE4) - context[1];
float dz = *(float*)(entry + 0xE8) - context[2];
return (float)(dx*dx + dy*dy + dz*dz); // x87 ST(0), ret 4
```

這裡的score可以明確稱為 **squared 3D distance**（中途float rounding按實際指令，非保證完全數學實數）；**不是官方相機/視野/怪物AI的高階名稱證據**。B consumer在 `0x7BB2AF..7BB2CD` 從 `[0xFB76E8]+0xC/+0x10/+0x14` 複製12-byte context，傳進選擇器 `0x7BB3B0`；selector的比較器真 `0x7BB870` 對兩個entry各叫vptr+0x08，取得x87 score並比較。僅在entry vptr匹配 `0xC4F6C0` 時，可將此score實作接上該comparison，**不能**宣稱所有可能entry/衍生型別均必然同一實作或排序方向已驗。

## 4. +04 真實 execute 存在 record registration 的直接E8鏈

`0x7A8310` 的原生入口 `55 8B EC`， `0x7A8325 mov ebx,ecx` 保存this（B-entry）。函式含重要**有條件**多型與實體/空間計算子鏈：

```asm
7A8327 83 BB A0 00 00 00 00  cmp dword [ebx+0xA0],0
7A8332 8B 43 10                mov eax,[ebx+0x10]
7A8347 8B 50 40                mov edx,[eax+0x40]   ; virtual +40
7A834A FF D2                   call edx
7A8353 E8 D8 C0 02 00          call 0x7D4430
7A836D 8B 48 28                mov ecx,[eax+0x28]  ; xyz candidate
7A8370 8B 50 2C                mov edx,[eax+0x2C]
7A8373 8B 40 30                mov eax,[eax+0x30]
7A8376 8D 73 F4                lea esi,[ebx-0x0C]  ; B-entry→Host*
7A8385 E8 76 ED FF FF          call 0x7A7100
...
7A85CE 83 BB 50 01 00 00 00  cmp dword [ebx+0x150],0
7A85D5 75 2A                   jne 0x7A8601
7A85DD 8B 15 38 A8 FB 00      mov edx,[0xFBA838]
7A85F6 E8 85 24 01 00         call 0x7BAA80     ; candidate record creation
7A85FB 89 83 50 01 00 00      mov [ebx+0x150],eax
7A8601 8B 9B 50 01 00 00      mov ebx,[ebx+0x150]
7A8607 85 DB                   test ebx,ebx
7A8609 74 12                   je 0x7A861D
7A860B A1 38 A8 FB 00         mov eax,[0xFBA838]
7A8610 8B 88 8C 00 00 00      mov ecx,[eax+0x8C]
7A8616 53                      push ebx            ; record ptr
7A8617 51                      push ecx            ; manager+0x8C
7A8618 E8 23 FC 03 00         call 0x7E8240      ; T08-133 record registry
```

由真PE rooted CFG另見 `7A856A..7A85B4` 比較既存record的xyz及+0x40浮點欄位；未通過比較時在 `7A85B6 call 7D7300;7A85BC call 89120C;7A85C4 mov [ebx+150],0` 先釋放舊record並清零，**正確條件指令地址為7A85CE，非半指令7A85CD**。在 `Host` B-entry+0x150 的record pointer最終為null且走到上述條件路徑時，函式會先呼叫候選建構器 `0x7BAA80` 並儲存指標；若最終record指標非null，則從全域owner+0x8C取得registry owner，**以原生直接E8呼叫真 `0x7E8240`**。已知 `0x7E8240` 的下游記錄名稱查找使用 `0x7E86E0→0x7E8A00`（T08-133/134修正版），並在其命中/建構分支可能向record+0x20 vector append（真 `0x7BB350`）。

**新閉合的有界功能鏈**：

```text
Host constructor 0x7A4C50 writes B-subobject vptr 0xC4F6C0 at Host+0xC
  → Host producer 0x7A63C0 gated append (Host+0xC) into global B vector
  → consumer 0x7BB240 (two E8 callers 0x799F94 and 0x7BA879)
      → select with entry+0x08 = 0x7A8E10: squared 3D distance in normal vptr state
      → entry+0x04 = 0x7A8310 (normal vptr)
          → candidate spatial/record build 0x7BAA80 and field +0x150
          → [0xFBA838]+0x8C owner, E8 0x7A8618 → 0x7E8240
          → keyed record find/append chain
```

**反證／限制**：此鏈**強於**先前「B entry類別完全未知」的早期狀態；但無法因為有vptr建構就推定所有runtime入B的entry都此類、於consumption時vptr沒變、所有gates開啟、B fn4必然執行record registration（有null/其他早退路徑）。**更未由此確定 fn4直接寫22桶**：`0x799F20`中 B consumer 與22桶callback存在順序，但不構成同一帧因果或無中介網路行為。

## 5. Destructor階段secondary vptr回寫：借用指標生命週期問題

舊T08-147稱 `0x7A5A51` 真PE位置是 **`0x7A5651`**，與constructor寫入不同 vptr階段形成對照。重要原生視窗：

```asm
7A5637 8B 4B 14               mov ecx,[ebx+0x14]
7A563A 85 C9                  test ecx,ecx
7A563C 74 13                  je 0x7A5651
7A563E 8D 41 08               lea eax,[ecx+8]
7A5641 83 CA FF               or edx,-1
7A5644 F0 0F C1 10            lock xadd dword [eax],edx
7A5648 75 07                  jne 0x7A5651
7A564A 8B 01                  mov eax,[ecx]
7A564C 8B 50 04               mov edx,[eax+4]
7A564F FF D2                  call edx
7A5651 C7 43 0C 6C F6 C4 00   mov [ebx+0xC],0xC4F66C   ; secondary-vptr restored
7A5658 C7 43 08 78 F8 C0 00   mov [ebx+0x08],0xC0F878
7A565F C7 43 04 4C F6 C4 00   mov [ebx+0x04],0xC4F64C
7A5666 C7 03 68 F4 C4 00      mov [ebx],0xC4F468
```

有界地證明Host某釋放/解構階段撤去derived subobject vptr；它**沒有**自行證明B queue中借用 Host+0x0C 指標在Host解構前被移除、B.end重置一定同步、指標不存在懸空風險。不能單憑靜態slice聲稱存在可利用UAF或已證沒有UAF；需所有權、各caller的切換/回收條件與runtime順序。

## 6. 技術交付／待查責任

|情境|已證Client|待補Client|Server／跨Task邊界|
|---|---|---|---|
|Host進B並由場景優先選擇|producerB.append Host+0xC、vptr+C4F6C0、fn8實際算3D距離平方、fn4存在到record registry之直接E8|B entry其他類型、所有CFG gates、record+150所有寫入者、真正proximity含義、borrowed pointer lifetime|T02 packet来源不在此文；Server不由Client本地score硬推波次策略|
|B與22桶|同dispatcher內B先執行，後有22桶callback|Fn4/record producer是否導入22桶計數以及觸發時間|S00 Server規格仍待明確client協定/遊玩驗證|

**T01-RETURN-T08-LEGACY-MAPPING-001 仍 NEEDS_FIX**。此稿修正145–147舊source的VA/vtable ABI/squared-distance/record鏈，但不能當作24篇全部正式READY_FOR_REVIEW。其餘 148～152 的 Host owner交接、控制區塊生命週期、T01原生mapping及使用者需求另續。
