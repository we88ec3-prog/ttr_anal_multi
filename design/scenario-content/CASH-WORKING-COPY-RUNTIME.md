# GAME_RUNTIME_OBSERVATION：現用商城購買與餘額重整

2026-11-19 使用者提供兩張指定 v2 畫面：廣場商城 Garnet 1,000，黑羽翅膀（칠흑의 날개）永久售價 250，購買卻提示商城點數不足；另回報寶石重整按鈕不更新。這是實機退回，先前原版表的離線／TCP 通過不能當成現用資源相容。

## 原因與來源分界

現用 `Table.stp` SHA `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c` 是既有工作副本；其 `CashProduct.xml` SHA `d1971c9482f1b74cdc8ed9d0208cc65181ad0f03766b6dce470489155e41f9ed` 與原版表不同。共 1,083 列，NOW_SELLING=1、SELLING_STATE=0，1,020 列 SELLING_TYPE=0、63 列為 1，所有價格均永久。這些不是原服今日上架政策。

Product 與 ItemTable2 member 和原版完全相同，SHA 分別為 `8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c`、`7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2`。黑羽翅膀是 Product 2625 → Item 16357、class 18、slot 7、SP／MP 各 +120，現用價格 QTY=1、PERIOD=0、PRICE=250。原版 CashProduct 沒有 2625，所以固定目錄查無 offer，通用拒絕 DF/3 又被 Client 顯示為點數不足。日誌不記 payload；該次 Product 身份由畫面名稱及現用資源交叉對照，沒有宣稱抓到請求 Product 欄。

原版 `4A4660` 以 B8 B4 00 00 00 建立命令、寫兩個 bytes 並經既有 transport 發送。`4A4660..4A468F` 原版／指定 v2 bytes 相同，既有靜態反編譯 `413590`、`699000` 都在商城點擊路徑呼叫它。Server 日誌 `2026-11-18T17:06:03/04Z` 記錄兩次長度 2 的 command 180（00B4），緊接 PRIMARYAPPLICATIONUNAVAILABLE；亦有長度 9 的 00AC 及短拒絕回覆。這與未處理的重整請求一致。S2C 沿已核 00DD，不新增 opcode。

## Server 修正與供貨範圍

00B4 在正常已載入廣場／村莊、有效租約下讀 SQLite 錢包並回 00DD。後台加扣後，可同次登入重整，不以舊畫面快照推算。

新增獨立 [現用商城目錄](kr-working-copy.cash-shop.json)，schema 為 LOCAL_CASH_SHOP_CATALOG_V2_WORKING_COPY_NOT_NATIVE_MEF。[投影工具](../../governance/client-variants/20261118-cash-shop/build_working_catalog.py) 唯讀核對工作 STP、三個 member、parser 與原版目錄。保留原版 offer 供既有已付商品及保管箱；現用表依相同四欄鍵覆蓋價格。合成後 2,325 個鍵、1,783 個可購鍵；這是 Server 供貨政策，不是原服商城或原生 MEF。

現用新增供貨只接受既有六類飾品／時裝 slot、已支援角色資格、完整 options 恰為 12=120／13=120 的永久商品。額外屬性、不同資格、武器及特殊服務保留 available=false，效果仍待開發。黑羽翅膀可按 250 購買、領取及穿戴。原版目錄不變。

啟動器明示 -UseWorkingCopyCashShop，核對工作 Table.stp 身份才使用此目錄；單獨 -IncludeCashShop 保留原版 profile。手動商城啟動檔使用工作 profile，不能僅憑 exe SHA 推定相同資源。

## 驗證與實機待回

新增正流程：管理加值 1,000 → 2625 付款 250 → 領取 → slot 7 穿戴 → 同次登入後台加 250 → 00B4 回 1,000，重開 store 保存。既有新帳號 TCP 商城旅程補管理加扣及 00B4／00DD。新測試先後因 bagSlot／equipmentSlot 放反及誤用角色 0 而失敗；更正為已持有角色 1 後專項通過，失敗 TRX 保留。

指定 v2 待重測：黑羽翅膀付款、領取、穿戴，以及後台加值後按重整。Server 合成與換版健康檢查不得標實機通過。Client、STP、原件均未改；其他特殊商品與額外屬性仍待完成。收據見 [驗證索引](cash-working-copy-validation.json)。

最終 HappyPath 590／590 通過，Host／檢查器 Release 零警告零錯誤。隔離 Host profile 預檢通過且 listener 已清除；隨後核對原 PID 33364 與部署路徑，只替換該本機遊戲 Host，新 PID 29852 的 health 確認載入工作目錄 SHA `f13f57ed492ec99833b744ef99467f7d59e100d34a2990f05b516b20467b1cd4`。管理端 PID 30276 保持、HTTP 200。原兩張畫面及雜湊保留於本機 outputs，未公開圖片。實機修正後結果待使用者回覆。
