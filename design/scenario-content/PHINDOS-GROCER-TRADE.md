# 馮德斯雜貨店買賣

第一個交易案例限定 Town 1、ShopNo 1、NPC 10028 的商品 183。原 `Product.xml` 對應道具 183，一般復活卷軸。購買單價 2,000 LeeLoo，售回單價 200 LeeLoo。貨單身分與價格來自同版的 `ShopInfo.xml`、`Product.xml`。 [原表與指令查證](../../governance/client-variants/20261109-mef-town-services/shop-services.md)

| 請求 | 已核對欄位 |
|---|---|
| 開啟普通商店 | C2S `001C`，category 2 與 `ShopNo` |
| 購買 | C2S `0027`，視窗 context byte、商品 u32、數量 u8 |
| 賣回 | C2S `0020`，背包種類 1、格號 u8、數量 u8 |

買賣使用 Server 已授權的城鎮與店號，購買請求的 context 原值保留，不能據它推定店號。Server 根據商品或所屬格號讀出物品，按原表單價乘數量。成功交易在同一個 SQLite 交易內提交錢包與背包，回傳提交後的餘額、格號、物品與格內數量。候選背包每種道具一格，最多 255 件，新道具使用第一個空格，賣完清除該格。這是候選資產模型，原版堆疊限制仍需確認。

目前已驗證離線買賣與落盤。村莊收到普通商店開啟請求時，Server 會按所在 Town、配置店號及估計位置核對，並在主線診斷中記錄最近一次已核對的開店。這筆觀察只能用來確認貨單入口。

普通商品的購買 context 已確認為 1。遊戲內更新使用 player-state S2C `002C` 的絕對餘額與格位資料，`0030` 另用於交易提示。這輪實作單格更新的離線封包組裝，交易尚未接入本機 Host。正式接線須先從同一份權威資產資料載入背包、兩個餘額與物品 metadata，並確認收據更新及提示在 Client 的顯示結果。候選儲存的格位從 0 起算，Client 的買賣及同步使用 1–100，接線時必須在協定邊界轉換。 [原生資產更新證據](../../governance/client-variants/20261109-mef-town-services/shop-asset-sync.md)
