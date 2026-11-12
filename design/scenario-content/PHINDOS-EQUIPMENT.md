# 馮德斯鐵匠商品與裝備實例

`ShopInfo.xml` 的 Town 1、Shop 2、NPC 10030 貨單含 Product 2614。韓版 `Product.xml` 的 Product 2614「스마트 글러브」對應 Item 2607，買入 3,700 LeeLoo，回售 370，其他幣別為零。`ItemTable2.xml` 的 Item 2607 為 class 1、`quan=1`、gettype 3。原始檔身份與參數由[商品設定](phindos.town-trade.json)記錄。這筆先用來驗證同款裝備分件，合成測試的 metadata 是測試資料。 [原版交易入口與強化視窗](../../governance/client-variants/20261109-mef-town-services/shop-services.md)

從 `ShopInfo.xml` 的 Town 1 依 Shop No 列出商品，以 Product No 取得 `Product.xml` 的 Item、`LEELOO`、`SELL_LEELOO`，再以 Item 查 `ItemTable2.xml` 的 `class` 與 `quan`。三家店共有 36 筆 `quan=1`，其他幣別欄位皆為 0，已全部納入馮德斯的普通買賣設定。

| 商店 | NPC | 筆數 | Item class | 買入／賣回 LeeLoo |
|---|---:|---:|---|---|
| 鐵匠 Shop 2 | 10030 | 27 | 1、2、43 | 各 9 筆，3,700／370、2,100／210、910／91 |
| 飾品 Shop 3 | 10029 | 3 | 3、27、4 | Product 29022 為 2,400／240，29023 與 29024 為 1,200／120 |
| 鍊金 Shop 4 | 10031 | 6 | 11 | 每件 700／70 |

Shop 4 的石類物品同樣每格一件，沿用分件儲存。資料庫欄名 `equipment_id` 同時用作這批物品的獨立身分，石類物品的用途由各自的道具規則決定。

## S00 GAME_RUNTIME_OBSERVATION

1. Server 以已配置的 Shop 2、3、4 市場點核對各店開店及買賣位置。普通開店沿用 C2S `001C` category 2，購買沿用 `0027` context 1。每個新品的 `metadata.field10`、`metadata.field14` 需由測試配置提供已核對的值。
2. 每次購買一件獨立物品，檢查錢包與空格，寫入 quantity 1 及新 GUID。物品佔獨立格，同 Product 可有多件。售回以請求格位為準。買賣與錢包更新在同一 SQLite 交易提交。
3. V6 保留舊錢包、背包格、倉庫格和掉落領取資料。舊有堆疊的裝備 ID 為空，仍沿用堆疊規則。新裝備的 GUID 和欄位值隨背包、倉庫轉移及換格保存。裝備只可轉入空格，既有倉庫整格換位可交換兩件。
4. GUID 屬 Server 儲存身分。現有 `0029`、`002C` 和 `00C3` 仍按格位傳送 Product、數量和已知欄位。獨立物品可經掉落規則入包。已查到穿脫請求及裝備欄接收格式，穿脫交易、能力值及強化仍待開發。新品入包欄位與實機驗收待完成。 [戰鬥掉落與撿取](GROUND-LOOT.md) · [裝備穿脫封包](EQUIPMENT-WEAR-WIRE.md)

合成案例分別對 Product 2614、29022、1399 使用兩次各一件的購買，檢查不同格位、不同 GUID，並檢查其中一件存入、換位、重開儲存層及取回後的 GUID。售回其中一件後，另一件仍在原格。 [批次驗收 TS-09 至 TS-11](../testing/S00-CONTENT-BATCH-TESTS.md)
