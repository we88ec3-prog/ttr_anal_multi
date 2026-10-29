# SPEC-CHAR-0001 — KR session / character selection (draft pilot)

**狀態：DRAFT / UNKNOWN；不可宣稱原版 Client 相容。**

- Client: KR；Tartaros.bin SHA256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- Source owner: T03；依賴 T02 網路框架、T04 角色初始化之介面。
- 請求（C2S）：選角欄位、合法狀態、封包順序尚待完整契約。
- 回覆（S2C）：成功與失敗回覆、回覆時序、Client 後續狀態尚待完整契約。
- Server 設計：帳號/Session/角色所有權等應另立 ADR 與測試，不得聲稱原版 Server 決策規則已知。
- 相關缺口：`GAP-CHAR-0001`；補證請求：`RR-0002`；目前通過的 TEST：無。
- 升級條件：T03/T02/T04 交付可實作的 bounded 證據、必要狀態與失敗路徑、相容性測試；阻塞性未知消除後才能評估 Stable。

本文件只示範如何承接現有 T03 研究，沒有填入未驗證 opcode 或假定回覆。
