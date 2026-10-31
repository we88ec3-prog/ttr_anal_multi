# W00-062 — reset 的一般 40-byte 清零與特殊樹初始化時序更正

**撤回**原 T10-062「第一 branch 的 6D1DA0 特殊初始化先於普通 40-byte 清零」的敘述。

```asm
6D4A5B cmp byte [ebp+8],0   ; mode 判斷
6D4A68 test byte [FB7C14],1
6D4A7E call 6D0750          ; 另一 lazy initialization，條件式
6D4A93 xor eax,eax
6D4A95 F6 05 EC F3 FD 00 01 test byte [FDF3EC],1
6D4A9C..6D4AC9              ; 十個 mov [FB9004..FB9028],eax（40 bytes）
6D4ACE jne 6D4AEE           ; flags 來自 6D4A95
6D4AD9 E8 C2 D2 FF FF       call 6D1DA0 ; 未初始化才呼叫，必在上述 clear 後
6D4AEE mov edi,FDF630
6D4AF3 call 823850
```
更正：在第一支，**40-byte clear 先發生**，條件式 `6D1DA0` 才發生；若 FDF3EC 已初始化，跳過 `6D1DA0`。`6D0750` 的可選先行不等同特殊樹初始化。第二支 `6D4B6B..6D4B98` 清零須視其獨立 gate，無法由第一支推出無條件。W00 3 項 bytes asserts PASS，`[0x6D4A90,0x6D4AF8)` SHA256 `7757c50e82930dcd00c276b39d0c706fac73f9dc5478ca4d33e6e95f55da3c75`。原 mode 是否等於技能/普攻狀態未知，T01 應依真實 CFG 複驗。

---

**來源與完成界線：** KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` 的 raw=VA−0x400C00、`.rdata` 的 raw=VA−0x401A00。保留舊稿 `kr-temp-roy/20261028-022217-chatgpt-web-roy-T10-062-lifecycle-reset-dual-branch.md` 與 Git blob `43ca57972ac64ad0752ce37c419331ff120befda`，正式 T01 通知 `T01-RETURN-T10-062-001`；另於同目錄提供 30 bytes asserts / 11 hashes 機讀文件。狀態是**勘誤已提出／待 T01 原生語意複驗**，非 RESOLVED、FULL-PASS、原版 Server 規則或已可玩。未修改原始 Client、T11 owner、正式 RR/S00 台帳或其他 Task 原稿。
