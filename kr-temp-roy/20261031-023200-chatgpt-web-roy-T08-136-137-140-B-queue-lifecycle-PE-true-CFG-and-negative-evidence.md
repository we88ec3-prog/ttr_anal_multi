# T08-136/137/140 — B queue selection → virtual dispatch → logical reset 與真PE析構之原生勘誤

研究時間2026-10-31 Asia/Taipei，chatgpt-web roy。KR `Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。真PE `.text` VA0x401000/raw0x400、raw=VA−0x400C00；獨立使用原始BIN擷取並由x86 Intel指令邊界反組譯。`.rdata`獨立映射。T01 LEGACY-MAPPING-001舊source仍FAILED，此新稿不自行標 FULL-PASS。

原始來源（保留不覆寫）：
- T08-136 `kr-temp-roy/20261027-191613-chatgpt-web-roy-T08-136-priority-queue-consumer-reset-boundary.md` blob `31bb246001362c2e15f4d94defdbd116add31204`。
- T08-137 `kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-137-B-writer-xref-audit.md` blob `39bb9462451fa62b890c7e5c1fca225d9eb70ed6`。
- T08-140 `kr-temp-roy/20261027-200622-chatgpt-web-roy-T08-140-B-queue-to-global-bucket-evidence-boundary.md` blob `471e5946d67fd02ad4f4390e6dedbfd1c2040430`。

## 1. 真 B consumer 0x7BB240 及兩個不同 direct caller

舊source的 `0x7BB640` 必須更正為 **0x7BB240**。由原始入口依CF/SEH正常建立至下列片段：

```asm
7BB240: 55 8B EC             push ebp; mov ebp,esp
7BB264: 8B 86 B8 00 00 00  mov eax,[esi+0xB8]     ; end
7BB26A: 2B 86 B4 00 00 00  sub eax,[esi+0xB4]     ; end-begin
7BB270: 8B 9E C4 00 00 00  mov ebx,[esi+0xC4]     ; configured cap
7BB276: C1 F8 02           sar eax,2
7BB279: 3B D8              cmp ebx,eax
7BB27B: 76 02              jbe 0x7BB27F
7BB27D: 8B D8              mov ebx,eax
7BB27F: F6 05 E8 79 FB 00 01 test byte [0xFB79E8],1
7BB286: 75 27              jne 0x7BB2AF
7BB296: E8 45 DB FD FF     call 0x798DE0
7BB2AF: A1 E8 76 FB 00     mov eax,[0xFB76E8]
7BB2B4: 8B 78 0C           mov edi,[eax+0x0C]
7BB2B7: 8B 96 B4 00 00 00  mov edx,[esi+0xB4]
7BB2CA: 89 79 04           mov [ecx+4],edi
7BB2CD: 89 41 08           mov [ecx+8],eax
7BB2D0: 8B 86 B8 00 00 00  mov eax,[esi+0xB8]
7BB2D6: 50                 push eax         ; last
7BB2D7: 8D 04 9A           lea eax,[edx+ebx*4]
7BB2DA: 50                 push eax         ; middle
7BB2DB: 52                 push edx         ; first
7BB2DC: E8 CF 00 00 00     call 0x7BB3B0    ; selection candidate
7BB2E1: 83 C4 18           add esp,0x18     ; 3 bounds + 12-byte context
```

這是共享的B queue consumer，而非全域22桶本身。兩個已驗原生E8 caller分別是 **0x799F94 → 0x7BB240**（dispatcher前置）與 **0x7BA879 → 0x7BB240**（另一群組路徑），不能用舊 `0x79A394/0x7BAC79` 的坐標冒充真caller。

## 2. 前N個entry的+4方法與B.end重置

```asm
7BB2E4 33 FF                  xor edi,edi
7BB2E6 85 DB                  test ebx,ebx
7BB2E8 74 1B                  je 0x7BB305
7BB2F0 8B 8E B4 00 00 00     mov ecx,[esi+0xB4]
7BB2F6 8B 0C B9              mov ecx,[ecx+edi*4] ; entry
7BB2F9 8B 11                 mov edx,[ecx]
7BB2FB 8B 42 04              mov eax,[edx+4]
7BB2FE FF D0                 call eax          ; entry vtable +4
7BB300 47                    inc edi
7BB301 3B FB                 cmp edi,ebx
7BB303 72 EB                 jb 0x7BB2F0
7BB305 8B 8E B8 00 00 00     mov ecx,[esi+0xB8]
7BB30B 8B BE B4 00 00 00     mov edi,[esi+0xB4]
7BB311 3B F9                 cmp edi,ecx
7BB313 74 21                 je 0x7BB336
7BB315 8B C1                 mov eax,ecx
7BB317 2B C1                 sub eax,ecx      ; eax = 0
7BB319 C1 F8 02              sar eax,2
7BB31C 8D 1C 85 00 00 00 00 lea ebx,[eax*4]
7BB323 53                    push ebx        ; 0 bytes
7BB324 51                    push ecx        ; last
7BB325 57                    push edi        ; first
7BB326 E8 C5 5F 0D 00        call 0x8912F0
7BB32B 83 C4 0C              add esp,12
7BB32E 03 DF                 add ebx,edi      ; ebx = begin
7BB330 89 9E B8 00 00 00     mov [esi+0xB8],ebx
7BB336 8B 4D F4              mov ecx,[ebp-0xC]
7BB346 C3                    ret
```

**精確條件**：在 `begin!=end` 的分支，因`7BB317 sub eax,ecx`兩運算元相同，傳給0x8912F0的bytes是零，接著B.end=begin；當begin==end時直接跳`7BB336`。這是**可觀測元素數量歸零**，並無任何可證的逐B-entry析構或payload free。`7BB3B0`選擇階段含短/長資料分支；本稿只命名為selection/partial-sort-like候選，非證原版STL精確型別。

## 3. 真PE析構不是B consumer的延伸

`0xC4FC8C +0x04` 真vtable slot DWORD指向**0x7B8C80**，入口實際存在：

```asm
7B8C80: 55 8B EC          push ebp ; mov ebp,esp
7B8C84: 8B F1             mov esi,ecx
7B8C86: E8 25 00 00 00    call 0x7B8CB0
7B8C8B: F6 45 08 01       test byte [ebp+8],1
7B8C8F: 74 09             je 0x7B8C9A
7B8C92: E8 75 85 0D 00    call 0x89120C
7B8C9E: C2 04 00          ret 4
7B8CB0: 55 8B EC          push ebp ; mov ebp,esp
7B8CDD: C7 03 8C FC C4 00 mov dword [ebx],0xC4FC8C
7B8DCF: 8B 83 B4 00 00 00 mov eax,[ebx+0xB4]  ; b.begin
7B8DD5: 3B C6             cmp eax,esi
7B8DD7: 74 09             je 0x7B8DE2
7B8DDA: E8 2D 84 0D 00    call 0x89120C    ; free allocated B storage
7B8DE2: 89 B3 B4 00 00 00 mov [ebx+0xB4],esi
7B8DE8: 89 B3 B8 00 00 00 mov [ebx+0xB8],esi
7B8DEE: 89 B3 BC 00 00 00 mov [ebx+0xBC],esi
```

有界析構序列包括另兩組不同vector及其他成員釋放；在上述B區分支中可證的是backing array free + 三指標歸零，而非每個B entry的virtual destructor。`0x7BB240`只是邏輯清空，**不能等同`0x7B8C80/CB0`析構**。

## 4. T08-137 的局部xref負面證據，及舊source中不同base+0xB8的反例

- 舊T08-137的局部掃描被錯置 `VA +0x400`：真constructor寫B分別`0x7B8B76/7B8B7C/7B8B82`；真destructor寫`0x7B8DE2/7B8DE8/7B8DEE`；真consumer讀`0x7BB264/7BB26A/7BB2B7/7BB2D0/7BB2F0/7BB305`，end-reset `0x7BB330`。
- 原稿另列 `0x7BED2F mov [eax+0xB8],ecx` 作**不同基址**同偏移範例，不能直接宣告B writer：在**真正** `0x7BED2F`，BIN的原始bytes是 `83 0D E8 79 FB 00 01`，實際為 `or dword [0xFB79E8],1`，與此原稿提及的舊位址不是同一機器碼。舊source那條寫入者若確實存在，需另外查真`0x7BE92F`，再從其callee/this來源比對，**不可**直接用錯位座標當作B producer。
- 局部範圍不能排除先有 `lea edi,[manager+0xB4]` 再呼叫通用 `0x7BB350`，或經alias/heap-held vector間接write +B8。負面結論只能說原指定bounds內未見獨立直接明寫B.end的合法證據，**不是全域不存在**。

## 5. B→22桶的因果鏈仍有缺口

已確定的 **code order**：`0x799F20` 前段經`0x799F94 call 0x7BB240`，然後才在`0x799FAB`調callback vtable+0x0C；該callback在已證vptr條件下實際目標是`0x7D1310`（全域22桶 consumer）。另一caller`0x7BA879`與此鏈不同。**沒有任何源證明B entry的fn4實作寫入全域bucket或B在此時非空**，不能把“先B後bucket”的順序推為“B造成22桶條目”的因果。

## 6. 對S00與T01需保留的限制

|情境|有界Client機制|玩家可見效果|未證Server決策|下一個靜態查點|
|---|---|---|---|---|
|priority B 消費|受C4上限的前N個entry +4虛擬執行，B.end=begin|未知，無直接場景角色畫面證據|為何哪一幀產生entry、如何填桶、wire格式未證|B producer alias、B-entry具體vptr→fn4、跨T02來源|

T01 LEGACY-MAPPING-001仍NEEDS_FIX。T08-136/137/140本稿已更正指令VA、直接E8、vector reset/析構分界，未對全部原稿的完整writer/entry身分進行FULL-PASS；Client待逆向、Server待開發、跨Task待整合、待遊玩驗證分開。
