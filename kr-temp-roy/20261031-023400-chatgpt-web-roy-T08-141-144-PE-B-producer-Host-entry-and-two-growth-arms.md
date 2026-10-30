# T08-141～144 — B queue 已有原生 producer：Host+0x0C 借用指標與兩條 grow／append CFG（KR BIN-first）

- 研究者 `chatgpt-web roy`，2026-10-31 Asia/Taipei；第一手原件 KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- PE `.text` VA `0x401000`，raw `0x400`，程式指令 raw=`VA-0x400C00`；`.rdata` VA `0xBD2000`、raw `0x7D0600`。本篇列出的每段關鍵指令皆由原件按**真正PE位址**切片、從入口或有效分支邊界解碼；E8 callee以 `VA+5+(signed rel32)` 獨立核算。未執行遊戲。
- 舊來源完整保留：T08-141 `kr-temp-roy/20261027-210935-chatgpt-web-roy-T08-141-B-vector-producer-confirmed.md`（blob `0044621bfd57ae0a7a1ee5a8687a13b2654a1032`）；142 `20261027-210935-chatgpt-web-roy-T08-142-B-producer-control-gates.md`（`05dfc203138c444e28c09fe8f910a3ed684ba2c5`）；143 `20261027-210935-chatgpt-web-roy-T08-143-B-vector-growth-and-alias-safety.md`（`0c5f49419fdb626eca8d007186bffbe22c4c8349`）；144 `20261027-210935-chatgpt-web-roy-T08-144-B-producer-consumer-link-and-vtable-limit.md`（`d1af4d9f33eaf7f55c72cc98f6c79169d867f58b`）；完整路徑均在 `kr-temp-roy/`。
- 研究地位：**這是四份舊版 source 的新原生修正依據**，但它們既有FAILED歷史與 `T01-RETURN-T08-LEGACY-MAPPING-001 NEEDS_FIX` 不被本稿自動變成FULL-PASS或RESOLVED。

## 1. 原生函式入口，舊址一律有 0x400 錯置

T08-141～144 所稱 `0x7A67C0` producer 的舊線性反組譯實際**位於 `0x7A63C0`**；先前以整個PE raw0做 `--adjust-vma=0x401000`，忽略真節區 `.text` raw0x400，導致顯示程式碼VA偏高0x400，連同 `E8` 目標偏高。這是**source coordinate錯誤**，不是將exe做整體rebase，也不容許把 `.rdata` 內絕對虛擬表指標減去0x400。

```asm
7A63C0: 55                  push ebp
7A63C1: 8B EC               mov ebp,esp
7A63E8: 8B F9               mov edi,ecx         ; Host this
7A63ED: 83 7F 1C 00         cmp dword [edi+0x1C],0
7A63F1: 0F 84 92 02 00 00  je 0x7A6689       ; bypass B producer
7A63F7: 83 BF 24 01 00 00 00 cmp dword [edi+0x124],0
7A63FE: 0F 84 85 02 00 00  je 0x7A6689       ; bypass B producer
7A6404: 83 BF AC 00 00 00 00 cmp dword [edi+0xAC],0
```

之後有 `[Host+AC]` 可選虛擬呼叫 `vtable+0x2C`；透過 `Host+0x70` 的迭代節點及其 `vtable+0x30` 檢查中間 gate。這些條件**不能**從線性機器碼窄窗擴張成某種「遊戲主動生成時間／Server AI」。在真正入列前仍有獨立的 gate：

```asm
7A65BE: 83 BF 8C 00 00 00 00 cmp dword [edi+0x8C],0
7A65C5: 0F 84 A0 00 00 00    je 0x7A666B
7A65D0: E8 DB 1A 09 00       call 0x8380B0
7A65D9: 8B 35 38 A8 FB 00    mov esi,[0xFBA838]        ; 0x10C-byte global owner
7A65DF: 8B 86 B8 00 00 00    mov eax,[esi+0xB8]       ; B.end
7A65E5: 83 C7 0C             add edi,0xC               ; Host+0xC embedded entry
7A65E8: 8D 4D EC             lea ecx,[ebp-0x14]      ; temporary pointer slot
7A65EB: 89 7D EC             mov [ebp-0x14],edi
```

`0x7A65D0 E8 DB 1A 09 00` 以真VA重算目標是 `0x8380B0`，並非舊稿 `0x8384B0`。 `0xFBA838` 是**global pointer slot**；`ESI=[0xFBA838]` 後的 `ESI+0xB4/B8/BC` 是另一個動態對象的B三指標，與Host內同偏移不能混同。

## 2. 兩條別名保護與 grow 分支是同一個B producer

```asm
7A65EE: 3B C8                cmp ecx,eax
7A65F0: 73 40                jae 0x7A6632           ; slot >= B.end: no alias
7A65F2: 8B 8E B4 00 00 00   mov ecx,[esi+0xB4]   ; B.begin
7A65F8: 8D 55 EC            lea edx,[ebp-0x14]
7A65FB: 3B CA               cmp ecx,edx
7A65FD: 77 33               ja 0x7A6632           ; begin > source slot
7A65FF: 8B FA               mov edi,edx
7A6601: 2B F9               sub edi,ecx
7A6603: C1 FF 02            sar edi,2              ; index if slot overlaps backing vector
7A6606: 3B 86 BC 00 00 00   cmp eax,[esi+0xBC]    ; end == capacity?
7A660C: 75 0B               jne 0x7A6619
7A660E: 8D 86 B4 00 00 00   lea eax,[esi+0xB4]
7A6614: E8 17 13 FF FF      call 0x797930        ; grow for alias arm
7A6619: 8B 86 B4 00 00 00   mov eax,[esi+0xB4]    ; refresh begin
7A661F: 8D 3C B8            lea edi,[eax+edi*4]
7A6622: 8B 86 B8 00 00 00   mov eax,[esi+0xB8]
7A6628: 85 C0               test eax,eax
7A662A: 74 25               je 0x7A6651
7A662C: 8B 0F               mov ecx,[edi]         ; alias content
7A662E: 89 08               mov [eax],ecx
7A6630: EB 1F               jmp 0x7A6651
7A6632: 3B 86 BC 00 00 00   cmp eax,[esi+0xBC]
7A6638: 75 0B               jne 0x7A6645
7A663A: 8D 86 B4 00 00 00   lea eax,[esi+0xB4]
7A6640: E8 EB 12 FF FF      call 0x797930        ; grow for non-alias arm
7A6645: 8B 86 B8 00 00 00   mov eax,[esi+0xB8]
7A664B: 85 C0               test eax,eax
7A664D: 74 02               je 0x7A6651
7A664F: 89 38               mov [eax],edi         ; append Host+0xC pointer
7A6651: 83 86 B8 00 00 00 04 add dword [esi+0xB8],4
```

**可證的局部資料流**：
1. `EDI` 在 `7A63E8` 原本為Host，至 `7A65E5` 加0xC，故非alias通常寫入B的entry pointer = **Host+0x0C**；
2. 檢查來源slot地址是否落在 `[B.begin,B.end)`；若落於其中，保存索引後才growth，再由更新begin重取來源DWORD；不應稱有實際runtime alias案例發生；
3. 真 `0x797930` 是兩分支的擴容helper；`B.end += 4` 位於 `0x7A6651`。**此處才是 T08-137～140 當時局部搜尋沒有找到、而T08-141已找到的 B 寫入者**。先前把B producer稱為全遊戲未知是過時敘述；未證的是B是否還有**其他**producer、failure/alias/null執行與全部worker條件。

## 3. 與consumer的結構身分閉合（不等於因果推定）

```text
Host.this (ECX in 0x7A63C0)
    → gates Host+1C / +124, other polymorphic predicates, Host+8C
    → 0x7A65E5 EDI += 0x0C   [Host secondary subobject address]
    → [0xFBA838] manager, B={+B4 begin,+B8 end,+BC capacity}
    → 0x7A664F write pointer  → 0x7A6651 B.end +=4
    ── same global manager's B vector ──
      0x7BB240 B consumer
          limit = min((end-begin)/4, manager+C4)
          0x7BB3B0 partial-sort-like selector; entry +8 score
          0x7BB2FE entry.vtable+4; 0x7BB330 logical B.end=begin
```

已在其他真PE來源確認B consumer有兩個E8 caller：`0x799F94`與`0x7BA879`，均指向 `0x7BB240`。這完成一個**相同B vector的producer→consumer候選物理接口**，不證明在每次consumer時B非空、entry還活著、同一輪入列與執行，或B slot+4直接寫全域22桶。這類執行時序與所有權需要完整Host life-cycle和runtime查證。

## 4. T01/Server交付等級與待解問題

|玩家相關事件候選|已核Client位元組|Client仍需逆向|Server規則|跨Task|
|---|---|---|---|---|
|Host進priority B|真producer 0x7A63C0 B.append(Host+0x0C)，兩條grow正確目標0x797930|完整predicates、來源Host實體生命週期、其他writer、異常/alias|沒有證據證明波次、時機由原Server如何決策|先核T08-145/146 B-entry vptr、T02 wire來源|
|B消費|真consumer 0x7BB240前N多型執行及end=begin|fn4、fn8所屬真正動態type、與22桶因果|不從此推Monster AI/原版Server策略|T08 及T02、S00|

**T01-RETURN-T08-LEGACY-MAPPING-001 仍NEEDS_FIX**；141–144原稿FAILED保留，以上是新的相對完整有界來源重建，不表示24個來源版本全部改正，也不等於原版SERVER可寫規格。
