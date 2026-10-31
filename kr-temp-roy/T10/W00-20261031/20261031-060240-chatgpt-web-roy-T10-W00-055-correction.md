# W00-055 — 特殊鍵樹錯位視窗修正

原 T10-055 第一視窗從 `0x6D4BB0` 開始（落在 `0x6D4BAC` 的 7-byte mov immediate）；第四視窗從 `0x6D4D40` 開始（落在 `0x6D4D3E` LEA 內部）。**撤回**從錯位解碼而來的 `lock push` 與泛稱「所有列出 call/read/write 都為正常路徑真實指令」的說法；不是整篇歷史來源作廢。

```asm
6D4BAC C7 45 FC 04 00 00 00  mov dword [ebp-4],4
6D4BB3 E8 98 BB FF FF        call 6D0750
6D4BB8 68 30 D5 BC 00        push BCD530
6D4BBD E8 58 D7 1B 00        call 89231A
6D4BC2 83 C4 04              add esp,4
6D4D3E 8D 4D F0              lea ecx,[ebp-10h]
6D4D41 51                    push ecx
```
應改從 `6D4BAC` / `6D4BC2` 與 `6D4D3E` / `6D4D41` 這些合法邊界解碼。窗口尾端不足時的 `.byte` 只是**截斷**，不能當獨立正常指令。原生 byte assertions `055_aligned_local_init` 與 `055_real_call` PASS；`[0x6D4B9D,0x6D4BD0)` SHA256 `84cb30af34f6229ed54db97c8432d0d433e9b8a7e60e42087e17e2a00976b319`。這只校正 native instruction 邊界，special-key 的真實 action/packet/callback 仍未完成。T01 需限定各肯定主張的正確視窗再複驗。

---

**來源與完成界線：** KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` 的 raw=VA−0x400C00、`.rdata` 的 raw=VA−0x401A00。保留舊稿 `kr-temp-roy/20261028-021236-chatgpt-web-roy-T10-055-special-key-domain-tree-branches.md` 與 Git blob `61c1e3bca931c781be72db549bed483202cfff1a`，正式 T01 通知 `T01-RETURN-T10-055-EVIDENCE-001`；另於同目錄提供 30 bytes asserts / 11 hashes 機讀文件。狀態是**勘誤已提出／待 T01 原生語意複驗**，非 RESOLVED、FULL-PASS、原版 Server 規則或已可玩。未修改原始 Client、T11 owner、正式 RR/S00 台帳或其他 Task 原稿。
