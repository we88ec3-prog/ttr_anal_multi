# T08-129-R2 — 129 的真 PE caller、callback vtable 與全域 bucket owner

研究：chatgpt-web roy，2026-10-31 Asia/Taipei。原件 KR Tartaros.bin，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。真 PE .text VA0x401000/raw0x400，code raw=VA−0x400C00；.rdata VA0xBD2000/raw0x7D0600。全部機器碼由原始BIN讀取、按真PE入口重算。舊版 `kr-temp-roy/20261027-184334-chatgpt-web-roy-T08-129-global-22-bucket-dispatcher-resolved.md`（blob `0023e1f4524453491e1dc42810969becd034c8ea`）保持原樣，其T01審核狀態FAILED。此為獨立修正來源，不擅自FULL-PASS。

## 原生 E8 caller 座標與指標來源

|舊標示碼VA|真實PE VA|原生bytes|有界含義|
|---|---|---|---|
|0x4931F8|**0x492DF8**|`BF A8 76 FB 00`|`mov edi,0xFB76A8`|
|0x4931FD|**0x492DFD**|`E8 1E 71 30 00`|`call 0x799F20`|
|0x6DD3E6|**0x6DCFE6**|`BF A8 76 FB 00`|`mov edi,0xFB76A8`|
|0x6DD3EB|**0x6DCFEB**|`E8 30 CF 0B 00`|`call 0x799F20`|
|0x79A320|**0x799F20**|`55 8B EC 6A FF`|有效的dispatcher prologue|

E8 目標精算：`0x492DFD+5+0x30711E=0x799F20`；`0x6DCFEB+5+0x0BCF30=0x799F20`。真 EDI 為字面量0xFB76A8，而非解參照該地址的結果。

## Dispatcher 入口可達的兩個不同 vtable 呼叫

```asm
799F99: 8B 8F A0 00 00 00 mov ecx,[edi+0xA0]
799F9F: 8B 01             mov eax,[ecx]
799FA1: 8B 97 98 00 00 00 mov edx,[edi+0x98]
799FA7: 8B 40 0C          mov eax,[eax+0x0C]
799FAA: 52                push edx
799FAB: FF D0             call eax
799FAD: 8B 0F             mov ecx,[edi]  ; core, not callback
799FAF: 8B 11             mov edx,[ecx]
799FB1: 8B 42 0C          mov eax,[edx+0x0C]
799FB4: BE 01 00 00 00    mov esi,1
799FB9: 56                push esi
799FBA: 56                push esi
799FBB: 56                push esi
799FBC: FF D0             call eax
```

對以上已驗兩個caller，EDI+0x98 的儲存位址是 `0xFB7740`；push出去的是**[0xFB7740]的DWORD值**，不是該位址本身。`799FAB` callback+0x0C與`799FBC` core+0x0C分屬不同物件。不能把三個literal 1當成callback參數。

## 不可整篇錯誤地把所有code值減0x400

以下已經在正確的真PE VA，與T01所見舊指令列表座標不同類別：

- **0x79985C**：原生 `C7 00 8C FF C4 00`，寫 callback vptr `0xC4FF8C`；**0x799866**：`89 86 A0 00 00 00`，寫到 manager+0xA0。這兩處不能移成0x79945C/0x799466。
- 真 `.rdata` VA **0xC4FF8C**、raw **0x84E58C**，little-endian四slot為 `0x7D12E0,0x5F5D10,0x5F5D10,0x7D1310`。故 callback +0x0C 在此前構造條件下是 **0x7D1310**。
- **0x7D1310** 原生 `55 8B EC`，為有效入口；**0x7D13C4** `8B 5D 08`取owner參數；**0x7D13C7** 查owner+0x4004；**0x7D13DC** 讀owner+index*4+0x2004；**0x7D1405**對owner+0x4004清零。這些都以真PE bytes核對，**不可減0x400**。
- **0x7D13A7** 的E8 `E8 44 92 FC FF` 真call目標 `0x79A5F0`，亦不受上述錯誤線性列表影響。

## 修訂後的有限功能鏈與責任界線

`0x492DFD / 0x6DCFEB → 0x799F20 → [EDI+0xA0] callback → vtable+0x0C(0x7D1310) → owner=[0xFB7740] → bucket read/conditional clear`。此鏈僅在callback按指定vptr初始化、指標有效、相應分支可達的前提下成立；未證所有22stage均執行、所有回呼目標恒定、runtime頻率或任何原版Server波次政策。原始T08-129的“結案”及全部衍生主張仍需T01對這個新來源逐條重審。

## C++ 行為骨架（非原版符號）

```cpp
// caller passed EDI = literal 0xFB76A8
auto* cb = *(void**)(EDI + 0xA0);
auto* owner = *(void**)(EDI + 0x98); // storage address FB7740
cb->vtbl[3](cb, owner);             // if vptr==C4FF8C => target 7D1310
auto* core = *(void**)EDI;
core->vtbl[3](core, 1, 1, 1);       // separate virtual target
```

## 不確定性／下一個驗收入口

完整dispatcher可達CFG及callback多型、consumer 22stage所有分支、上層觸發時序、另一manager和全域owner alias均未由本次有限窗口證成。Client待逆向；Server生成時間／波次屬Server待開發；跨Task與可玩驗證分開。`LEGACY-MAPPING-001` 總項維持 NEEDS_FIX，僅提出T08-129修復候選。
