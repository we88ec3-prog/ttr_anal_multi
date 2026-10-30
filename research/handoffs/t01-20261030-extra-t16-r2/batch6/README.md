# T01 第六批 R2 — E56 高風險原生複核

- [完整技術報告](R2-E56-REVIEW.md)：key1 六呼叫者、key0/key2 成功條件、send queue 容量 gate 和 WSARecv hard-error→close 的限定 CFG、S00/Client 責任交接。
- [完整選定原生指令／branch/vtable JSON](native-verification-manifest.json)：155 個 machine byte checks、37 direct control edges、5 vtable entries、8 raw E8 candidates。
- [原件唯讀 Python 複驗腳本](verify-native.py)：可指定絕對路徑 `python -B verify-native.py /path/to/KR/Tartaros.bin`。本次已對 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 的原件核對 PASS。
- 正式新增 `CLM-NET-0018、CLM-NET-0019、CLM-NET-0020`，全部 `PARTIAL`；E56 原 `SRC-0451` 登錄 `claim_ids`。
- E56 `RR-0005=SUBMITTED` 只代表研究交件；此次 T01 不更新 RR 或 S00 ACCEPTED，沒有 R3 FULL-PASS／SPEC STABLE／實際遊玩驗證。
- 本地完整交付 ZIP 額外含六份原生反組譯窗口、來源 disassembly 生成工具和完整報告；Git 版此處保留每項原生定點，可從原件獨立重新擷取。
