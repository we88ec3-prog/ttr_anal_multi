# T08-132-R2 — 第二queue caller、A陣列與B消費的真正PE地址分流

2026-10-31 chatgpt-web roy。KR `Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，.text VA0x401000/raw0x400（raw=VA−0x400C00）。原T08-132 source `kr-temp-roy/20261027-190000-chatgpt-web-roy-T08-132-second-queue-caller-and-producer-boundary.md` blob `3d35052d8bc09d70fe1394b6ac9380a5454b73a9`，舊文使用raw=VA−0x401000，函式地址誤高0x400；本稿按原生機器碼重新固定有界call，不更動舊原稿。

## A. 真第二consumer caller

原文稱`0x7BAC79 E8 C2 09 00 00`是另一個`0x7BB640` caller。正確KR PE原始位置為 **0x7BA879**，bytes仍是`E8 C2 09 00 00`，故 **call 0x7BB240**。`0x799F94 E8 A7 12 02 00 →0x7BB240`是另一條來自dispatcher的caller（T08-130 R2），兩者功能上不可混為同一dispatch來源，也不能推斷執行頻率。

## B. 真A陣列的回傳物件與registry登記

```asm
7BA7E5: 8B 91 8C 00 00 00 mov edx,[ecx+0x8C]
7BA7EB: 50                push eax
7BA7EC: 52                push edx
7BA7ED: E8 4E DA 02 00    call 0x7E8240
7BA7F2: 43                inc ebx
7BA7F3: 3B DF             cmp ebx,edi
7BA7F5: 72 DC             jb 0x7BA7D3
7BA7F7: 83 BE 8C 00 00 00 00 cmp dword [esi+0x8C],0
```

這段從A陣列的entry+0x34取得的值，與 owner+0x8C 共同傳入**真 `0x7E8240`**（T08-133 R2），而不是舊錯地址`0x7E8640`。`[ebp+8]`獲最後push的owner+8C值；`[ebp+C]`獲第一push的entry+34。若owner+8C非空，其後同一caller還可能觸發該物件vtable+8，但其`this`不是B queue元素，不可與float comparator vtable+8混淆。

## C. A陣列的建立鏈不是直接B queue producer

```asm
7EB407: E8 44 FD FC FF    call 0x7BB150
7BB223: E8 28 01 00 00    call 0x7BB350
```

原報記`0x7EB807→0x7BB550`，真E8是 **0x7EB407→0x7BB150**。原報`0x7BB623 call 0x7BB750`，真E8在**0x7BB223→0x7BB350**。T08-131及本段原生證據指`0x7BB150`與其helper操作A-vector（owner+0xA4 triplet），而B queue consumer `0x7BB240`讀的是owner+0xB4/+B8/+C4；同一個append helper也可接不同vector地址，不可因callee相同就說A=B。

## D. 實體操作順序與限制

- A-vector元素先行提供+0x34給`0x7E8240`、另有對owner+0x8C的不同virtual呼叫；其後從owner+0x7C/+0x80取得另一個指標陣列，有對子物件的間接呼叫，最後再由`0x7BA879`到B-vector consumer。這是局部code order，**不是**全部路徑固定跨幀順序。
- 原報曾注意`0x7BAC50`暫借ESI存byte-offset後再恢復；真候選是`0x7BA850`一段，需按callee的每個CFG分支重新確認全域owner身分。此部分**未證**second caller的所有entry必然使用`[0xFBA838]`。
- T08-132的B+0xB8 writer全域集合尚未閉合；看到constructor清零和consumer end reset不等於沒有別的producer。原版Server波次、wire opcode、場景runtime由T02/S00及遊玩驗收另行處理。

## E. T01驗收交付

有界已證：兩條不同B consumer call、A entry+34傳到registry、A-helper與B-helper的資料結構分界、所有上述E8目的地；保留T08-132歷史FAILED，不直接聲稱整篇FULL-PASS。`LEGACY-MAPPING-001`仍NEEDS_FIX；需要完整真PE入口CFG、所有別名writer、vtable實體及上游owner屬性再完成語義複驗。
