# 商城 Web 管理

2026-11-19 接續新增 [商品查詢、停賣／恢復與稽核](CASH-SALE-ADMINISTRATION.md)。管理變更控制新購買，不會自動替換遊戲內的 STP 列表或標價。整體剩餘工作見 [管理接續範圍](CASH-MANAGEMENT-COMPLETION.md)。

本機後台新增 `/admin/cash`，接目前遊戲使用的 SQLite 測試資料庫。可搜尋登入帳號，查看 Garnet、保管箱筆數與前 100 筆尚未領取商品，並以正數加值、負數扣除。帳號須先完成冒險團命名。

每筆加扣必填原因，保存操作識別碼、帳號、增減、前後餘額及 UTC 時間。SQLite 同一寫入交易完成餘額與管理紀錄，識別碼避免表單重複提交造成再次加扣。商城購買亦讀同一錢包，管理操作後重新登入可確認 Client 餘額。管理記錄使用獨立 `local_cash_admin_audit` 表。

這些是 Server 管理功能，沿現有 loopback Web 後台與防偽表單處理。SQLite 版本提供商城管理，PostgreSQL 維持現有帳號管理。商城定價與供應仍沿固定目錄，原生玩法、原件及正式規格狀態沿既有工作線。

私有實作為 `SqliteCashShopAdministration`、`CashAdminHtml` 與 Web 路由。專項正流程核對管理加扣與商城實際付款共享餘額、管理記錄及保管箱。HTTP 合成使用專屬 DB 副本核對 GET、Cookie／防偽權杖 POST、餘額及記錄，未調整使用者原資料庫的資金。

Host、離線檢查器及 Web Release 建置均為零警告、零錯誤；最終 HappyPath 589／589 通過。前兩次全套的商城 TCP 交接出現等待 Session 釋放逾時／初始 roster EOF；測試原先尚持有主線連線便用同帳號開第二個 gateway，現先關閉原連線並等待釋放，再正常登入。失敗及最終通過的 TRX 雜湊、HTTP 收據和實作檔案雜湊見 [驗證索引](cash-web-admin-validation.json)。Wing 的既有獨立來源與八例合成收據仍見 `cash-wing-validation.json`。

測試工具已備妥 `tools/start-local-shop-test.ps1 -Database <測試DB>` 與 `tools/start-local-cash-admin.ps1 -Database <同一測試DB>`。前者啟動完整遊戲 Host 並載入商城，後者開啟 `http://127.0.0.1:5091/admin`，商城管理入口為 `/admin/cash`。本機操作說明位於私有庫 `docs/WEB-ADMIN-LOCAL.md`。

使用者 2026-11-18 重新安排商城實機測試，原有指定 v2 批次表供操作回報。Wing 的主出口選點與四秒冷卻仍為 Server 候選政策，官方選點及秒數待證。管理頁功能不會自動完成遊戲實機驗收。
