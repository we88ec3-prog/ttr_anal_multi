# T08-138/139 — manager vtable 八個真 PE function entry 與 B-entry score ABI 原生校正

2026-10-31 Asia/Taipei；chatgpt-web roy。KR `Tartaros.bin` 12,472,320 bytes SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE `.text` VA0x401000/raw0x400，`raw=VA−0x400C00`；`.rdata` VA0xBD2000/raw0x7D0600。此稿逐一直接讀取原始vtable DWORD及指向目標的原生入口bytes，不靠舊線性列表的錯位函式邊界。

歷史來源（保持原內容與FAILED裁決）：
- `kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-138-manager-vtable-and-entry-type-boundary.md` blob `0f57fa53734a801984402bb13ac15617a3e01e76`。
- `kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-139-B-comparator-ABI-and-two-callers.md` blob `5ce4138eabb80f1a859b4801f075a56e4ac8167f`。

## 1. 原始PE vtable 0xC4FC8C：全部8個已存DWORD實際都是有效PE函式入口

**關鍵勘誤**：T08-138舊稿說「部分vtable指入反組譯顯示函式中段，ABI可疑」只能反映**舊座標解碼顯示錯置**。本次在真PE映射下，8個 vtable slot 的全部指向VA都有完整原生函式 prologue，而不是半途插進長指令。

| manager vtable slot | `.rdata` raw小端DWORD | 真 `.text` raw | 原始入口 bytes（前綴） | 此輪結論 |
|---|---|---|---|---|
| `C4FC8C +00` | **0x7BA8A0** | 0x3B9CA0 | `55 8B EC 83 E4 F8 6A FF` | 有效PE函式入口 |
| `C4FC8C +04` | **0x7B8C80** | 0x3B8080 | `55 8B EC 56 8B F1 E8 25 00 00 00` | 有效釋放wrapper |
| `C4FC8C +08` | **0x7B9390** | 0x3B8790 | `55 8B EC 6A FF 68 76 80 93 00` | 有效PE函式入口 |
| `C4FC8C +0C` | **0x7B96E0** | 0x3B8AE0 | `55 8B EC 6A FF 68 3E 80 93 00` | 有效PE函式入口 |
| `C4FC8C +10` | **0x7B98B0** | 0x3B8CB0 | `55 8B EC 6A FF 68 87 51 93 00` | 有效PE函式入口 |
| `C4FC8C +14` | **0x7B99C0** | 0x3B8DC0 | `55 8B EC 6A FF 68 DE C4 90 00` | 有效PE函式入口 |
| `C4FC8C +18` | **0x7BA380** | 0x3B9780 | `55 8B EC 83 E4 F8 6A FF` | 有效PE函式入口 |
| `C4FC8C +1C` | **0x7BA6B0** | 0x3B9AB0 | `55 8B EC 6A FF 68 CA 50 93 00` | 有效PE函式入口 |

vtable真.raw `0x84E28C`（因 `0xC4FC8C−0xBD2000+0x7D0600`），八個 little-endian DWORD依次：`7BA8A0,7B8C80,7B9390,7B96E0,7B98B0,7B99C0,7BA380,7BA6B0`。這些都是**資料節中的絕對指標值**，不是上游錯位反組譯清單地址。真正 vtable+4在`0x7B8C80`可見 `call 0x7B8CB0`，參數位0測試、條件釋放 `0x89120C`，具有 destructor-like wrapper ABI；不據此將所有別的slot命名為已證業務方法。

## 2. manager vptr 建立路與 B entry 介面絕不可混用

```asm
7B8A78 8B 7D 08             mov edi,[ebp+8]
7B8A7B 33 DB                xor ebx,ebx
7B8A7D 89 5D FC             mov [ebp-4],ebx
7B8A80 C7 07 8C FC C4 00    mov dword [edi],0xC4FC8C
7B8A86 BE 0F 00 00 00       mov esi,0xF
7B8C80 55 8B EC             push ebp; mov ebp,esp
7B8C86 E8 25 00 00 00       call 0x7B8CB0
7B8C8B F6 45 08 01          test byte [ebp+8],1
7B8C92 E8 75 85 0D 00       call 0x89120C
```

獨立 callback vtable常數 `0xC4FF8C`（raw0x84E58C），+0C指向真 **`0x7D1310`**；manager vtable `0xC4FC8C` 不能以相近位址/同slot合併成callback。B entry `entry.vptr+0x04` 是owner+0xB4 vector的**元素物件**方法，而不是manager本身 `0x7B8C80` destructor method。既有源T08-138較早對vtable指入「指令中段」的懷疑在真PE原件下**已被反證**；待查的是各slot的高階語義，而非入口是否位於半指令。

## 3. T08-139比較器真正入口 0x7BB870 與 x87 計分介面

舊稿 `0x7BBC70` 比較器真入口為**0x7BB870**。由原始BIN重算 `0x7BB3B0` 的長序列selection及其比較呼叫，顯示同一12-byte context透過 `push &context`交給兩個B entry的 vtable+0x08 function；兩次結果由x87 ST(0)送至 `qword` 再比較，不是直接的整數欄位比較。

```asm
7BB870 55 8B EC             push ebp; mov ebp,esp
7BB873 83 EC 0C            sub esp,0xC
7BB876 8B 45 08            mov eax,[ebp+8]      ; context origin
7BB879 8B 0E               mov ecx,[esi]        ; entry A
7BB87B 8B 11               mov edx,[ecx]        ; entry vptr
7BB87D 8B 52 08            mov edx,[edx+8]
7BB886 8D 45 0C            lea eax,[ebp+0xC]
7BB889 50                  push eax             ; context
7BB88A FF D2               call edx            ; entry score
7BB88C DD 5D F4            fstp qword [ebp-0xC]
7BB88F 8B 03               mov eax,[ebx]        ; entry B vptr
7BB891 8B 50 08            mov edx,[eax+8]
7BB894 8D 4D 0C            lea ecx,[ebp+0xC]
7BB897 51                  push ecx
7BB898 8B CB               mov ecx,ebx
7BB89A FF D2               call edx
7BB89C DC 5D F4            fcomp qword [ebp-0xC]
7BB89F DF E0               fnstsw ax
7BB8A1 F6 C4 41            test ah,0x41
7BB8A4 75 08               jne 0x7BB8AE
7BB8AA 89 0E               mov [esi],ecx       ; conditionally swap pointers
7BB8AC 89 07               mov [edi],eax
```

**證據等級**：可證多型slot+8接受context指標且回傳浮點ST(0)，此函式以x87比較及條件swap做排序過程。B-entry具體constructor/vptr尚未定位，**不可以**知道manager vtable真目標就把entry的+8方法識別成manager +8 slot，更不能將分數解作實際距離、相機視錐、畫面優先級的官方規則。

## 4. 選擇器真0x7BB3B0的長短分支與介面邊界

```asm
7BB3B0: 55 8B EC           push ebp; mov ebp,esp
7BB3B3: 8B 45 10           mov eax,[ebp+0x10]  ; last
7BB3B9: 53                 push ebx
7BB3BA: 8B 5D 08           mov ebx,[ebp+8]    ; first
7BB3BD: 2B C3              sub eax,ebx
7BB3BF: C1 F8 02           sar eax,2
7BB3C4: 83 F8 20           cmp eax,0x20
7BB3C7: 0F 8E A7 02 00 00  jle 0x7BB674      ; short-range path
7BB404: E8 97 02 00 00     call 0x7BB6A0     ; partition/helper long path
7BB41B: 8B 11              mov edx,[ecx]     ; B entry vptr
7BB41D: 8B 52 08           mov edx,[edx+8]
7BB427: FF D2              call edx
7BB429: DD 5D F0           fstp qword [ebp-0x10]
7BB438: FF D0              call eax
7BB43A: DC 5D F0           fcomp qword [ebp-0x10]
```

**新更正**：舊報中的 `0x7BB7B0` 是上述 selection 的錯誤code顯示地址；真 `0x7BB3B0` 且長序列分支進`0x7BB6A0`，短序列跳`0x7BB674`。根據三界址+浮點比較/交換可合理稱為partial-sort-like候選，但須以更完整短支線和helper驗證才能命名為精確 STL partial_sort。單純 vtable+8浮點回值不能推論其為距離或任何原版Server優先級。

## 5. 真 caller 與有限跨功能鏈

兩個確定的 B consumer E8 site：`0x799F94 E8 A7 12 02 00 → 0x7BB240`；`0x7BA879 E8 C2 09 00 00 → 0x7BB240`。前者在整個manager dispatcher中先執行B selection+fn4，再呼叫不同callback+0x0C（若正常初始化vptrC4FF8C則真0x7D1310，22桶consumer）。這是前後順序，不能推斷fn4造成22桶寫入。另一caller與分桶callback不在同一直接功能鏈中。

## 6. T01複驗與Server可見界線

|情境|Client原生有界證據|玩家可見|Server仍未知|補證入口|
|---|---|---|---|---|
|B-entry優先選擇|比較器真0x7BB870對entry vfptr+8取得x87分數，0x7BB240僅前N個呼叫fn4|無法直接證實具體渲染/怪物行為|何時產生entry，何時進桶，真正wire|B entry ctor及vptr+4/+8實作，T02封包上游|

T01 LEGACY-MAPPING-001維持NEEDS_FIX。本新來源對138舊「所有vtable函式入口有疑點」做**可被KR BIN原生反證的更正**，對139補了真正比較器與E8/CFG局部結論；八個入口以外的所有權、完整多型時序和全局writer仍待證。Client待逆向、Server待開發、跨Task整合、待遊玩驗證各自分類。
