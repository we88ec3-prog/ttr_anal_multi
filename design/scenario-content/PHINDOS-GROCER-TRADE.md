# 馮德斯雜貨店買賣

第一個交易案例限定 Town 1、ShopNo 1、NPC 10028 的商品 183。原 `Product.xml` 對應道具 183，一般復活卷軸。購買單價 2,000 LeeLoo，售回單價 200 LeeLoo。貨單身分與價格來自同版的 `ShopInfo.xml`、`Product.xml`。 [原表與指令查證](../../governance/client-variants/20261109-mef-town-services/shop-services.md)

| 請求 | 已核對欄位 |
|---|---|
| 開啟普通商店 | C2S `001C`，category 2 與 `ShopNo` |
| 購買 | C2S `0027`，視窗 context byte、商品 u32、數量 u8 |
| 賣回 | C2S `0020`，背包種類 1、格號 u8、數量 u8 |

買賣使用 Server 已授權的城鎮與店號，購買請求的 context 原值保留，不能據它推定店號。Server 根據商品或所屬格號讀出物品，按原表單價乘數量。成功交易在同一個 SQLite 交易內提交錢包與背包，回傳提交後的餘額、格號、物品與格內數量。候選背包每種道具一格，最多 255 件，新道具使用第一個空格，賣完清除該格。這是候選資產模型，原版堆疊限制仍需確認。

目前已驗證離線買賣與落盤。村莊收到普通商店開啟請求時，Server 會按所在 Town、配置店號及估計位置核對，並在主線診斷中記錄最近一次已核對的開店。這筆觀察只能用來確認貨單入口。

普通商品的購買 context 已確認為 1。遊戲內更新使用 player-state S2C `002C` 的絕對餘額與格位資料，`0030` 另用於交易提示。Server 現可用同一筆 SQLite 交易讀回 LeeLoo、Battle Point、背包及物品 metadata，並組裝只含餘額、單格或多格的 `002C`。每列更新明列一格，數量 0 代表清格，省略的格位維持 Client 現有內容。 [原生資產更新證據](../../governance/client-variants/20261109-mef-town-services/shop-asset-sync.md)

舊版候選資料升級時保留 LeeLoo 與背包，新增的 Battle Point 以本機初始值 0 補上。舊物品缺少的兩個 metadata 欄維持未知。Client 另有 `0029` 初始化背包容量及格位，適合與 `002C` 的交易增量分開使用，實際登入送出順序待核對。尚未接入正式道具來源與 Host 的交易回覆，缺資料的格位不可用假值組裝。候選儲存以 0–99 分配新格位，Client 使用 1–100，接線時需做轉換。重新登入的驗收須比對同帳號的兩個餘額、格位與數量，並確認賣完的格位已清除。
