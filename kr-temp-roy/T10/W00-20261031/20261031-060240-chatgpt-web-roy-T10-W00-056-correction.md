# W00-056 — indexed reader 錯位偽 CALL 修正

**撤回**原 T10-056 第三視窗 `0x596430` 解出的 `CALL 596441→F8DC6459`；`596430` 位在 `59642E E9 rel32` 的 immediate，偽 CALL 跨過真 `59643F` CALL immediate 與 `596444` CMP，沒有 source-backed caller/callee 語意。尾端 `.byte` 須標截斷，不是正常 CFG。

```asm
59642E E9 7A 01 00 00        jmp 5965AD
596433 68 34 20 BF 00        push BF2034 ; 不能僅因線性相鄰就認定由 jmp 落入
596438 E8 F3 76 2E 00        call 87DB30
59643D 32 DB                 xor bl,bl
59643F E8 9C E8 13 00        call 6D4CE0
596444 83 F8 01              cmp eax,1
596447 0F 85 96 00 00 00     jne 5964E3
596452 74 11                 je 596465
596454 8B 01                 mov eax,[ecx]
596456 8B 90 EC 00 00 00     mov edx,[eax+ECh]
59645D FF D2                 call edx
```
正確重解碼入口 `59642E/596433/59643D/596452`。W00 bytes asserts `056_jump`、`056_real_call` PASS，`[0x59642E,0x596465)` SHA256 `3399f2e37b4357d65cc4b22a253bfa961a4ac73e54d831ed698ce04b926969c3`。保留原稿其它可獨立驗證的 indexed-reader/multiform consumer 觀察；具體 virtual+EC target 和玩家輸入因果仍待確認。

---

**來源與完成界線：** KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` 的 raw=VA−0x400C00、`.rdata` 的 raw=VA−0x401A00。保留舊稿 `kr-temp-roy/20261028-021236-chatgpt-web-roy-T10-056-indexed-reader-polymorphic-consumers.md` 與 Git blob `e2da2b34e1c97aeffd192d5af7a258f80b50c527`，正式 T01 通知 `T01-RETURN-T10-056-EVIDENCE-001`；另於同目錄提供 30 bytes asserts / 11 hashes 機讀文件。狀態是**勘誤已提出／待 T01 原生語意複驗**，非 RESOLVED、FULL-PASS、原版 Server 規則或已可玩。未修改原始 Client、T11 owner、正式 RR/S00 台帳或其他 Task 原稿。
