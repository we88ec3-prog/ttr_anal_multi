# 馮德斯鐵匠商品與裝備實例

`ShopInfo.xml` 的 Town 1、Shop 2、NPC 10030 貨單含 Product 2614。韓版 `Product.xml` 的 Product 2614「스마트 글러브」對應 Item 2607，買入 3,700 LeeLoo，回售 370，其他幣別為零。`ItemTable2.xml` 的 Item 2607 為 class 1、`quan=1`、gettype 3。原始檔身份與參數由[商品設定](phindos.town-trade.json)記錄。這筆先用來驗證同款裝備分件，合成測試的 metadata 是測試資料。 [原版交易入口與強化視窗](../../governance/client-variants/20261109-mef-town-services/shop-services.md)

## S00 GAME_RUNTIME_OBSERVATION

1. 商品表有 Shop 2／2614 時，Server 以已配置的 Shop 2 市場點核對開店及買賣位置。普通開店沿用 C2S `001C` category 2，購買沿用 `0027` context 1。新裝備的 `metadata.field10`、`metadata.field14` 需由測試配置提供已核對的值。
2. 每次購買一件獨立裝備，檢查錢包與空格，寫入 quantity 1 及新 GUID。裝備佔獨立格，同 Product 可有多件。售回以請求格位為準。買賣與錢包更新在同一 SQLite 交易提交。
3. V6 保留舊錢包、背包格、倉庫格和掉落領取資料。舊有堆疊的裝備 ID 為空，仍沿用堆疊規則。新裝備的 GUID 和欄位值隨背包、倉庫轉移及換格保存。裝備只可轉入空格，既有倉庫整格換位可交換兩件。
4. GUID 屬 Server 儲存身分。現有 `0029`、`002C` 和 `00C3` 仍按格位傳送 Product、數量和已知欄位。裝備穿脫、能力值、強化與裝備掉落各自需要已確認的 Client 契約。其餘 35 筆裝備貨單及實機驗收待完成。

合成案例使用兩次各一件的購買，檢查不同格位、不同 GUID，並檢查同一件裝備存入、換位、重開儲存層及取回後的 GUID。售回其中一件後，另一件仍在原格。 [批次驗收 TS-09](../testing/S00-CONTENT-BATCH-TESTS.md)
