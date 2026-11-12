# 馮德斯雜貨店買賣

## 馮德斯商品設定

依原件 `ShopInfo.xml` 的 Town 1 店與商品清單，以 Product No 接 `Product.xml`，再以 Item No 接 `ItemTable2.xml`。下列六筆在一般商店流程使用 LeeLoo，且原件 Item 的 `quan` 大於 1。新版 Server 內容表選擇以該值作為購買疊加上限。原服如何執行上限仍待驗證。

| Shop | Product | Item | 道具 | 買入 LeeLoo | 賣回 LeeLoo | `quan` |
|---:|---:|---:|---|---:|---:|---:|
| 1 | 183 | 183 | 一般復活卷軸 | 2,000 | 200 | 100 |
| 1 | 232–234 | 232–234 | HP／SP／MP 回復卷軸，依商品號順序 | 810 | 81 | 255 |
| 1 | 17337 | 15918 | Phase 重置券（依韓文釋義） | 50,000 | 5,000 | 255 |
| 70 | 23232 | 20572 | 一億 LeeLoo 支票 | 100,000,000 | 100,000,000 | 255 |

Shop 1 的 232、233、234 同時列出 LeeLoo 810 和 Battle Point 3。KR `Tartaros.bin` 的 `51C61A–51C70F` 將 `LEELOO`、`BATTLE_POINT`、`HOORU` 分別寫入 Product 資料的 `+24`、`+2C`、`+30`。購買確認 `682713–68272D` 讀視窗 context，context 1 走一般 LeeLoo 分支。context 3 讀 `+30`（`682812`），context 4 讀 `+2C`（`6827A7`）。`682A38` 將同一 context 交給 `0027` 封包。這三件商品可先按 810 LeeLoo 交易，Battle Point 專用店仍待開發。

Shop 2、3、4 有 27、3、6 筆 `quan=1`。鐵匠商品 2614 已作為第一筆獨立裝備的買賣候選，其餘 35 筆待核對並開放。 [裝備實例與交易規格](PHINDOS-EQUIPMENT.md)

啟用既有本機商店模式後，設定 `TARTAROS_LOCAL_TOWN_TRADE_CATALOG_PATH` 及 `TARTAROS_LOCAL_TOWN_TRADE_CATALOG_SHA256`。已設定時，表內的店／商品配對是買賣白名單，Server 在入包前核對價格、數量及新疊 metadata。復活卷軸、支票可沿用各自現有測試設定的欄位。重置券和三種回復卷軸的新疊需在各列提供已核對的 `metadata.field10` 和 `metadata.field14`。公開範例省略這兩欄，避免把合成測試數值當作原服資料。回售以指定格位讀到的 Product 取價。舊疊超出設定上限時仍可售回，但不能再疊加購買。 [商品設定](phindos.town-trade.json) · [JSON Schema](local-town-trade.schema.json)

合成測試依序買入復活卷軸與重置券，重開儲存層後分別售回兩格，再買賣 Product 232，核對各自的成交價、餘額與背包清格。重置券使用效果及 Client 實際名稱、格位顯示與重登均待驗證。 [批次驗收](../testing/S00-CONTENT-BATCH-TESTS.md)

## 原有復活卷軸候選與封包

第一個交易案例限定 Town 1、ShopNo 1、NPC 10028 的商品 183。原 `Product.xml` 對應道具 183，一般復活卷軸。購買單價 2,000 LeeLoo，售回單價 200 LeeLoo。貨單身分與價格來自同版的 `ShopInfo.xml`、`Product.xml`。 [原表與指令查證](../../governance/client-variants/20261109-mef-town-services/shop-services.md)

| 請求 | 已核對欄位 |
|---|---|
| 開啟普通商店 | C2S `001C`，category 2 與 `ShopNo` |
| 購買 | C2S `0027`，視窗 context byte、商品 u32、數量 u8 |
| 賣回 | C2S `0020`，背包種類 1、格號 u8、數量 u8 |

買賣使用 Server 已授權的城鎮與店號，購買請求的 context 原值保留，不能據它推定店號。Server 根據商品或所屬格號讀出物品，按原表單價乘數量。成功交易在同一個 SQLite 交易內提交錢包與背包，回傳提交後的餘額、格號、物品與格內數量。候選背包每種道具一格，最多 255 件，新道具使用第一個空格，賣完清除該格。這是候選資產模型，原版堆疊限制仍需確認。

目前已驗證離線買賣與落盤。村莊收到普通商店開啟請求時，Server 會按所在 Town、配置店號及估計位置核對，並在主線診斷中記錄最近一次已核對的開店。這筆觀察只能用來確認貨單入口。

普通商品的購買 context 已確認為 1。遊戲內更新使用 player-state S2C `002C` 的絕對餘額與格位資料，`0030` 另用於交易提示。Server 現可用同一筆 SQLite 交易讀回 LeeLoo、Battle Point、背包及物品 metadata，並組裝只含餘額、單格或多格的 `002C`。每列更新明列一格，數量 0 代表清格，省略的格位維持 Client 現有內容。 [原生資產更新證據](../../governance/client-variants/20261109-mef-town-services/shop-asset-sync.md)

舊版候選資料升級時保留 LeeLoo 與背包，新增的 Battle Point 以本機初始值 0 補上。舊物品缺少的兩個 metadata 欄維持未知。候選儲存以 0–99 分配新格位，Client 使用 1–100，Server 在收發時轉換。

Host 已有預設關閉的本機交易候選。啟用後，正常進村的帳號在授權範圍內開啟馮德斯雜貨，Server 先以 `0029` 發布該帳號的背包 1，再以 `002C` 發布 LeeLoo 和 Battle Point。這個送出時機是 Server 的相容性方案，原版登入順序待核對。只處理已備資產的帳號，缺少物品欄位的背包不進入買賣狀態。買賣重新核對位置及商店 context，成功提交後依序回傳 `002C` 格位變化與 `0030` 交易提示。新購入的道具欄位目前需在本機測試設定提供，正式道具來源待接入。實機重新登入後應再次開啟雜貨，比對餘額與格位，並確認賣完的格位保持清空。
