# S00 WEB 管理後台設計入口

**定位：**Server-owned 管理工具產品規劃（非遊戲 Client、非原版 Server 封包），目前僅設計，沒有開放管理 WEB 埠或建置程式。

- [完整 V1 功能／頁面／API／資料模型／驗收門檻](ADMIN-WEB-V1-PLAN.md)
- [逐項驗收測試草案（尚未執行）](ADMIN-WEB-V1-ACCEPTANCE.md)
- [使用者原始需求](../requirements/requests/2026-10-31-admin-web-account-operations.md)
- [ADR-0004 後台安全邊界](../decisions/ADR-0004-admin-web-security-boundary.md)、[ADR-0005 停權語意與 Session 限制](../decisions/ADR-0005-account-sanctions.md)

**唯一需求權威：** `design/requirements/index.json` 的 REQ-0006～0008；此目錄不是新 REQ/RR/GAP/SPEC 台帳。管理員需求來自 `PLAYER_ADMIN_REQUEST`，不是新增來源類別。需 Server 實作時，在獨立 `ttr_server_roy` 的 Admin/Account/Session/Persistence 模組新增**經批准**的實作，不在本 S00 repo 存取個資或開放網路介面。
