# W00-026 — cast/SubAI 函式邊界與 caller attribution 修正

原 T10-26 將 `0x549D54` 的 `call 0x54F270` 當成 `0x549980` 的可達呼叫，**撤回這個函式歸屬**。

```asm
549980 55 8B EC 83 E4 F8   ; 第一函式 prologue
549A34 C2 10 00            ; 早退 ret16
549C48 5F 5E 5B 8B E5 5D   ; 第一函式 epilogue
549C4E C2 10 00            ; 第一函式另一 ret16
549C51..549C5F CC         ; padding
549C60 55 8B EC 83 E4 F8  ; **第二函式獨立 prologue**
549C8B 8B 45 0C            ; 第二函式 arg
549C94 E8 C7 0D 00 00     ; call 54AA60 屬第二函式
549D54 E8 17 55 00 00     ; call 54F270 屬第二函式
```
因此 `0x549D54` 在以 `0x549C60` 為入口的第二函式，而非 `0x549980`；原 local `state=4` 若存在，仍須從第二函式正確 frame/參數/caller 重新建構，不能因函式名像技能就推官方施放判斷。W00 `026_fn1_ret`、`026_fn2_prologue`、`026_real_call` bytes asserts PASS；SHA `[0x549980,0x549A35)` `9f4edd8b95bffc3262cd99d653ddd3a8e10087330030c03a7ebe07f1758e3f71` 與 `[0x549C48,0x549D60)` `f778f26ef0aee3a0154e1d08cbba59c1ab0171cf5a799fcb306b410c501c5031`。

---

**來源與完成界線：** KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` 的 raw=VA−0x400C00、`.rdata` 的 raw=VA−0x401A00。保留舊稿 `kr-temp-roy/T10/20261027-205931-chatgpt-web-roy-T10-26-subai-cast-state-machine.md` 與 Git blob `c82bc8c3c53f304faecab0911f214b89440d1784`，正式 T01 通知 `T01-RETURN-T10-026-001`；另於同目錄提供 30 bytes asserts / 11 hashes 機讀文件。狀態是**勘誤已提出／待 T01 原生語意複驗**，非 RESOLVED、FULL-PASS、原版 Server 規則或已可玩。未修改原始 Client、T11 owner、正式 RR/S00 台帳或其他 Task 原稿。
