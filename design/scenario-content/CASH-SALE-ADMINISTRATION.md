# 商城商品管理與 Client 商品列表分界

2026-11-19 接續 [Web 錢包／保管箱管理](CASH-WEB-ADMIN.md)。使用者問「目前商城僅能透過更換 .stp 更換商品列表嗎」，並指定先完成商城管理、再接續副本 MEF 分析與開發。

## 目前能控制的內容

遊戲可見列表、名稱、價格選項來自現用 Table.stp 的 CashProduct.xml 與既有資源。目前未取得可用來動態替換全列表的原生 Server 封包；00DD／寶石重整只發布錢包，不重載商品表。因此「後台停賣」與「從遊戲列表消失」是兩項功能，不能互相冒稱完成。

Server 另讀固定 SHA 商品目錄。新增 `/admin/cash/catalog` 可搜尋名稱／Product／Item、分頁看所有價格選項、目前 Client 是否列出、Server 已支援或未開放狀態，並停賣／恢復已支援 Product。停賣對該 Product 的全部選項生效；恢復不能把原目錄不支援的特殊功能開放。不可直接改價，以免再次產生 Client 標價與 Server 收費不一致。

名稱來自 [唯讀投影工具](../../governance/client-variants/20261118-cash-shop/build_admin_labels.py) 及 [Web 標籤資料](kr-working-copy.cash-shop-labels.json)。先核對工作 Table.stp、CashProduct、Product 與既有 archive reader 的 SHA；EXPLAIN 作現用列表顯示名稱，未列商品回退 Product 原名稱。標籤記錄 clientListed，且與工作目錄 SHA `f13f57ed492ec99833b744ef99467f7d59e100d34a2990f05b516b20467b1cd4` 綁定，不能把原版保留商品說成已在現用 Client 顯示。此投影與 schema 均為 Server 管理資料，不是原生 MEF 或可供 Client 載入的新表。

## 交易與稽核

交易元件 V29 保持；增加獨立 LOCAL_CASH_SALE_CONTROL_V1 管理元件，初始化納入既有交易 migration。local_cash_sale_rules 保存目前 Product 狀態、原因及時間；local_cash_sale_audit 保存唯一操作 ID、Product、前後狀態、原因、管理時使用的目錄 SHA 及 UTC 時間。表單沿既有 loopback／POST／防偽權杖／HTML 編碼。

每次付款在同一 SQLite 寫入交易中讀取停賣狀態、核對錢包、寫保管箱並扣款；不依靠 Host 啟動時快照，所以管理變更不需重啟遊戲 Server。這是 Server 供貨政策，不是官方後台 SQL。沒有改現用 STP 或來源目錄。既有付款保管箱的領取不查新販售狀態，避免停賣撤銷已付款權利。

購買回覆區分權限／供貨拒絕與餘額不足。既有 699260 consumer 的狀態 3、4、5 分別取 CommonMessages code 19、21、265。原件 D65C20 的 12-byte triplet 對應 kInsufficient_Cash、kInsufficient_CashInvenMax、kCashShopPermissionDenide；原 Locales.stp 的韓文 CommonMessages member SHA 為 `830cc748fc4739bd11d02ca741a5380895e5f170fdf88b6dc166ee7b9d2e60cc`。265 文意為「沒有購買權限」。新 Server 選擇狀態 5 回覆停賣／不支援，只有已授權錢包不足走 3；沒有捏造新 opcode。這是有限 consumer／文字映射與 Server 拒絕政策，不代表官方拒絕條件已恢復。

## 驗證界線

新正流程驗證付款 1,000→750、停賣記錄、停賣期間成功領取已付黑羽翅膀、恢復後同一 store 成功付款到 500，以及重開後兩筆稽核與規則。它沒有執行停賣購買拒絕、欠款、重送、防偽失敗、安全或壓測；這些依既有排程留待後續。

另以獨立 DB 和隔離埠啟動真實 Web 程式，GET 搜尋 2625、合法 Cookie／CSRF POST 停賣與恢復、再 GET 檢查下一步按鈕狀態與 SQL 稽核。沒有操作遊戲 Client，沒有更動使用者的正式測試副本販售規則。前次直接建置碰到仍在線的舊 Admin DLL 檔案鎖，保留失敗；改以獨立輸出目錄成功建置，部署改用工作副本目錄，避免後續開發鎖住 Release。

收據與 SHA 見 [驗證索引](cash-sale-administration-validation.json)。新管理頁實機操作、停賣拒絕提示仍另列待測；不是全商城或所有特殊商品完成。下一步範圍見 [管理接續表](CASH-MANAGEMENT-COMPLETION.md)。

本批依使用者要求先發布 Git 成果，未替換目前在線 Host／Admin。新販售控制須兩者都換成此版後才可使用；既有在線服務不算本批部署證據。來源重跑工具為 verify_sale_messages.py（原 BIN、指定 v2、原 Locales.stp），標籤工具的 --check 已通過。
