# T08-130-R2 — 原生PE dispatcher 調度、vector consumer與分桶producer分離

2026-10-31 chatgpt-web roy。來源 KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；.text VA0x401000/raw0x400，真raw=VA−0x400C00。舊稿 `kr-temp-roy/20261027-185041-chatgpt-web-roy-T08-130-dispatcher-phase-and-queue-lifecycle.md` blob `5e7a513b87ea08a9f920377e526be8b444d79ab3` 維持原樣及T01 FAILED。本篇為獨立修訂來源，不宣稱全文 FULL-PASS。

## 1. 錯誤來源的真正原因與 E8 目的地

舊報以 `objdump -b binary -m i386 --adjust-vma=0x401000` 對**PE整檔raw0**反組譯，將raw與真`.text`相差0x400的舊碼列標為PE VA；不是PE header失效。真 `.text` raw=VA−0x400C00。把每條指令重對真PE raw後，有以下由同一批原始E8直接可驗結果：

```asm
799F7C  6A 00                  push 0
799F7E  68 50 32 FE 00         push 0xFE3250
799F83  E8 68 50 03 00         call 0x7CEFF0
799F88  57                     push edi
799F89  E8 D2 10 00 00         call 0x79B060
799F8E  8B 35 38 A8 FB 00      mov esi,[0xFBA838]
799F94  E8 A7 12 02 00         call 0x7BB240
799F99  8B 8F A0 00 00 00      mov ecx,[edi+0xA0]
799F9F  8B 01                  mov eax,[ecx]
799FA1  8B 97 98 00 00 00      mov edx,[edi+0x98]
799FA7  8B 40 0C               mov eax,[eax+0x0C]
799FAA  52                     push edx
799FAB  FF D0                  call eax
799FAD  8B 0F                  mov ecx,[edi]
799FAF  8B 11                  mov edx,[ecx]
799FB1  8B 42 0C               mov eax,[edx+0x0C]
799FB4  BE 01 00 00 00         mov esi,1
799FB9  56                     push esi
799FBA  56                     push esi
799FBB  56                     push esi
799FBC  FF D0                  call eax
```

在此有界有效路上，前置順序是 `0x7CEFF0 → 0x79B060 → 0x7BB240 → callback+0x0C → core+0x0C`。舊稿 `0x7CF3F0/0x79B460/0x7BB640` 不是真E8目標。callback target若vtable為C4FF8C則是**真正0x7D1310**（見T08-129-R2）；**不可**對真`.rdata`指標和本來正確的code引用機械減400。

## 2. 真0x7BB240 限定Vector消費

```asm
7BB264 8B 86 B8 00 00 00  mov eax,[esi+0xB8] ; end
7BB26A 2B 86 B4 00 00 00  sub eax,[esi+0xB4] ; begin
7BB270 8B 9E C4 00 00 00  mov ebx,[esi+0xC4] ; limit
7BB276 C1 F8 02           sar eax,2
7BB279 3B D8              cmp ebx,eax
7BB27B 76 02              jbe 0x7BB27F
7BB27D 8B D8              mov ebx,eax
7BB2D0 8B 86 B8 00 00 00  mov eax,[esi+0xB8]
7BB2D6 50                 push eax
7BB2D7 8D 04 9A           lea eax,[edx+ebx*4]
7BB2DA 50                 push eax
7BB2DB 52                 push edx
7BB2DC E8 CF 00 00 00     call 0x7BB3B0
7BB2F0 8B 8E B4 00 00 00  mov ecx,[esi+0xB4]
7BB2F6 8B 0C B9           mov ecx,[ecx+edi*4]
7BB2F9 8B 11              mov edx,[ecx]
7BB2FB 8B 42 04           mov eax,[edx+4]
7BB2FE FF D0              call eax
7BB305 8B 8E B8 00 00 00  mov ecx,[esi+0xB8]
7BB30B 8B BE B4 00 00 00  mov edi,[esi+0xB4]
7BB315 8B C1              mov eax,ecx
7BB317 2B C1              sub eax,ecx  ; zero on this branch
7BB323 53                 push ebx
7BB324 51                 push ecx
7BB325 57                 push edi
7BB326 E8 C5 5F 0D 00     call 0x8912F0
7BB330 89 9E B8 00 00 00  mov [esi+0xB8],ebx
```

函式 `0x7BB240` 在有效vector及無溢出前提下求 `min(+0xC4,(end-begin)/4)`，先以`0x7BB3B0`處理該vector，再以元素vtable+4處理前N筆；末端`sub eax,ecx`確定為0，後續`0x8912F0`處理零長度，重設end。原碼所稱`0x7BB7B0`和`0x8916F0`均是錯誤的direct E8目標。`0x7BB3B0`的排序鍵語義與所有元素payload的所有權回收並未由這些指令單獨證明。

## 3. 真0x79B060的 core snapshot

`0x79B07D mov ebx,[ebp+8]` 取manager；`0x79B08F mov esi,[ebx]` 取core；`0x79B0BB add esi,0x98`、`0x79B0C1 mov ecx,0xD`、`0x79B0E7 rep movsd` 確立拷貝 **13 DWORD=0x34 bytes** 的core+0x98片段。例子：`0x79B0FE call 0x89E860`、`0x79B125 call 0x790B40`、`0x79B133 call 0x780890` 是重算後的真E8目標。不能未驗證即說camera/frustum/event。

## 4. 真0x79A3C0是不同producer函式

```asm
79A3C0 56                    push esi
79A3C1 8B B1 98 00 00 00     mov esi,[ecx+0x98]
79A3D4 69 C0 04 20 00 00     imul eax,eax,0x2004
79A3DA 8B 8C 30 00 20 00 00 mov ecx,[eax+esi+0x2000]
79A3E4 81 F9 00 08 00 00     cmp ecx,0x800
79A3EA 7D 09                 jge 0x79A3F5
79A3EC 89 3C 88              mov [eax+ecx*4],edi
79A3EF FF 80 00 20 00 00     inc dword [eax+0x2000]
79A3F5 C3                    ret
```

這段原生code證明每桶計數小於2048時append一筆，在到達上限時跳過。它屬真0x79A3C0，並非舊錯誤標示0x79A7C0；與dispatcher相鄰不代表在同一個呼叫內，也不證明某個Server波次如何觸發。

## 5. 舊來源受影響但尚未全文閉合的子鏈

舊稿 `0x79A495..0x79A781`的manager+0x28 list操作位址屬上述錯誤座標族，真候選是`0x79A095..0x79A381`。本輪沒有把該區全部CFG與payload虛擬析構核成確定的全回收；不沿用「兩條路必定釋放全部node」的完整肯定主張。所有衍生代碼與控制流需獨立以有效入口再核。

## 6. 正式待複驗／分工

T08-130本輪有界已確認：三個前置helper的E8 call、回呼及core不同virtual、受cap約束的vector消費、13 DWORD snapshot、真bucket producer。未知：後半list各路、所有所有權回收、完整caller集合及觸發時序。T01 `LEGACY-MAPPING-001` 維持NEEDS_FIX；本稿是新的來源修訂候選，不能以局部bytes吻合冒稱全篇FULL-PASS。場景Server決策與wire仍需T02/S00分離處理。
