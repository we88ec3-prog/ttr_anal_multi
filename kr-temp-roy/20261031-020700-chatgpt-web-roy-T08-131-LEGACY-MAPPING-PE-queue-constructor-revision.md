# T08-131-R2 — 全域 queue owner 建構與優先陣列的真PE座標

2026-10-31 chatgpt-web roy，來源 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes。PE .text VA0x401000/raw0x400、raw=VA−0x400C00；.rdata VA0xBD2000/raw0x7D0600。舊來源：`kr-temp-roy/20261027-185400-chatgpt-web-roy-T08-131-queue-sort-constructor-and-comparator.md` blob `f962c4d39b8469e11d4c763949d234a46a931147`，屬LEGACY-MAPPING-001退回項。此稿是有限原生修正版，不直接宣稱T01 FULL-PASS。

## A. 應改的初始化 caller／allocation／constructor

```asm
7AAB41: 83 3D 38 A8 FB 00 00 cmp dword [0xFBA838],0
7AAB48: 75 33                jne 0x7AAB7D
7AAB4A: 68 0C 01 00 00       push 0x10C
7AAB4F: E8 14 67 0E 00       call 0x891268
7AAB66: E8 E5 DE 00 00       call 0x7B8A50
```

舊稿 `0x7AAF41/4F/66` 是相同bytes誤放在VA+0x400，舊直接call target也隨之錯成`0x891668/0x7B8E50`。真正由BIN重算：`0x7AAB4F+5+0xE6714=0x891268`；`0x7AAB66+5+0xDEE5=0x7B8A50`。不能因舊列出現指令在原VA不符，就誤以為原PE頭錯誤；也不能平移全域`[0xFBA838]`資料指標。

## B. 建構器真入口與獨立vector triplets

```asm
7B8A50: 55 8B EC 6A FF          push ebp / mov ebp,esp / push -1
7B8A78: 8B 7D 08                mov edi,[ebp+8]
7B8A80: C7 07 8C FC C4 00      mov dword [edi],0xC4FC8C
7B8B64: 89 9F A4 00 00 00      mov [edi+0xA4],ebx
7B8B6A: 89 9F A8 00 00 00      mov [edi+0xA8],ebx
7B8B70: 89 9F AC 00 00 00      mov [edi+0xAC],ebx
7B8B76: 89 9F B4 00 00 00      mov [edi+0xB4],ebx
7B8B7C: 89 9F B8 00 00 00      mov [edi+0xB8],ebx
7B8B82: 89 9F BC 00 00 00      mov [edi+0xBC],ebx
7B8B88: C7 87 C4 00 00 00 04 00 00 00 mov dword [edi+0xC4],4
```

以上三組`+A4/+A8/+AC`、`+B4/+B8/+BC`、`+C8/+CC/+D0`應依原始owner建立路徑及各自writer分開。`+C4=4`僅是**初始化值**，不可推斷runtime恆為4。`0xC4FC8C`是寫入的**vptr絕對值**，不是舊source coordinate：絕不可減0x400或未讀rdata就聲稱實際虛擬析構目標。

## C. 前N位排序與接收者（復用T08-130 R2有界結果）

原T08-131所稱`0x7BB640`真 consumer是`0x7BB240`，其`0x7BB264/26A/270`使用`+B8/+B4/+C4`的end/begin/limit，`0x7BB2DC E8 CF 00 00 00`真call到`0x7BB3B0`而非舊`0x7BB7B0`。helper內對entry vtable+8作浮點比較的精確排序鍵、完整拓樸、資料所有權需繼續以真入口`0x7BB3B0` rooted CFG核驗；目前不以“partial_sort已證原生模板”結案。

## D. 研究邊界與T01交付

已證：全域FBA838首次建立的0x10C配置、真construct call、各向量初始化及C4預設值。未證：整個manager動態型別、所有alias writer、B queue 的單一生產者身分、跨frame排序實際條件、全部vtable實作。舊 source 的錯誤映射及衍生callee名稱由本新版本更正；**LEGACY-MAPPING-001仍NEEDS_FIX**，這不是對131全文所有肯定結論的完成驗證。
