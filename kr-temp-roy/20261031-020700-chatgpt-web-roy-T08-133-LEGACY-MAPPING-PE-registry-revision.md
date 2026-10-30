# T08-133-R2 — record registry 的真正入口、雙 caller、計數與 append 修正

作者 chatgpt-web roy；2026-10-31 Asia/Taipei。KR原件 `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE `.text` VA0x401000/raw0x400，code raw=VA−0x400C00。保留原稿 `kr-temp-roy/20261027-191613-chatgpt-web-roy-T08-133-record-registry-7E8640.md`（blob `f466864d5317543d7f78863ede38355773eb25b9`，T01 LEGACY-MAPPING-001原生座標FAILED）；本篇為獨立重新核查的有界候選，不是全文FULL-PASS。

## 1. 真實函式入口和兩個 E8 caller

舊報 `0x7E8640` 稱為 `55 8B EC` 的雙參數函式，與KR PE **該VA實際 `4E 1C 72 08 33 C0 ...` 不符**。真入口是 **0x7E8240**，原生 `55 8B EC 83 E4 F8 6A FF 68 50 48 91 00`。真尾端 **0x7E841C C2 08 00**（ret 8），因此二個 DWORD stack arguments屬有界ABI。

```asm
7A8610: 8B 88 8C 00 00 00  mov ecx,[eax+0x8C]
7A8616: 53                 push ebx
7A8617: 51                 push ecx
7A8618: E8 23 FC 03 00     call 0x7E8240

7BA7E5: 8B 91 8C 00 00 00  mov edx,[ecx+0x8C]
7BA7EB: 50                 push eax
7BA7EC: 52                 push edx
7BA7ED: E8 4E DA 02 00     call 0x7E8240
```

對第一個caller，`[ebp+8]`為最後push的`[eax+0x8C]`值，`[ebp+0xC]`為`EBX`；第二個caller則`[ebp+8]`為`[ecx+0x8C]`值、`[ebp+0xC]`為`EAX`。不能把owner與record互換，也不從共用offset推定兩個caller的高階型別相同。直接call的E8位移在真PE重算都指向0x7E8240，不是舊0x7E8640。

## 2. 真函式下游欄位

```asm
7E8277: 8B 45 0C              mov eax,[ebp+0xC]
7E827A: FF 80 CC 3E 00 00     inc dword [eax+0x3ECC]
7E8280: 8B 5D 08              mov ebx,[ebp+8]
7E8283: 33 D2                 xor edx,edx
7E8285: 89 44 24 14           mov [esp+0x14],eax
7E8289: 8D B8 B0 3E 00 00     lea edi,[eax+0x3EB0]
7E828F: 39 10                 cmp [eax],edx
7E8291: 0F 85 AC 00 00 00     jne 0x7E8343
7E8297: 83 7F 14 10           cmp dword [edi+0x14],0x10
7E829B: 72 04                 jb 0x7E82A1
7E829D: 8B 0F                 mov ecx,[edi]
7E829F: EB 02                 jmp 0x7E82A3
7E82A1: 8B CF                 mov ecx,edi
```

此有限路徑可以確認 **第二個stack參數**的 `+0x3ECC` 計數遞增，`+0x3EB0` 視為string儲存（小字串/heap-string依length+0x14門檻選取）。舊反組譯的同一段在原檔中多次重列，不表示函式真的重複執行那些指令。低階報告不替該函式指定確切遊戲業務名稱。

## 3. 末端record vector append真正目標

```asm
7E83F3: 8D 44 24 14          lea eax,[esp+0x14]
7E83F7: 8D 7E 20             lea edi,[esi+0x20]
7E83FA: E8 51 2F FD FF       call 0x7BB350
7E83FF: 8B 4C 24 58          mov ecx,[esp+0x58]
7E8403: 64 89 0D 00 00 00 00 mov fs:[0],ecx
7E841C: C2 08 00             ret 8
```

有效E8由`0x7E83FA+5+signed(0xFFFD2F51)`算得**0x7BB350**；`0x7BB350`原生入口`56 8B F0 8B 47 04...`，不是舊稿的`0x7BB750`。由`lea edi,[esi+20]`可認此局部把record下的+0x20容器傳到append候選，**不是**manager/owner+0xB4 vector；完整append元素型別及所有權需追callee。

## 4. 有界反證／未知

- `0x7E86E0` 是舊`0x7E8AE0`相應位置的真入口候選，必須逐條真PE CFG查證；本篇未將此helper的全部string lookup語義提升為原生完成。
- 兩caller是已證的direct路徑；是否存在間接呼叫、其他版本或record alias尚未知。actor或Server的內容、封包Opcode、實際觸發時間亦未驗證。
- 完整原稿對兩個字串分支、record首次[record]=1、append全分支仍須依真PE重建；不可因上述有界證據成立，將T08-133整篇或LEGACY-MAPPING-001改RESOLVED。

## 5. T01複驗建議

逐條核對`7E8240`的full reachable CFG、`7E86E0`間接record查找、`7BB350`在所有alias上的append、caller到owner+0x8C的真正配置來源。對S00只提供已驗的Client結構邊界；Server待開發、跨功能整合和待遊玩測試各自獨立。
