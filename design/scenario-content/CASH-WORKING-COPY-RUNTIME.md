# GAME_RUNTIME_OBSERVATION：現用商城購買與餘額重整

2026-11-19 使用者提供兩張指定 v2 畫面：廣場商城 Garnet 1,000，黑羽翅膀（칠흑의 날개）永久售價 250，購買卻提示商城點數不足；另回報寶石重整按鈕不更新。這是實機退回，先前原版表的離線／TCP 通過不能當成現用資源相容。

## 最新實機結果：寶石重整通過

2026-11-19 使用者針對「重新登入後，在管理端加值，再按商城寶石重整，是否立即更新」回覆「可以正常更新」。因此指定 v2 的同次登入 Garnet 重整標為 USER_REPORTED_PASS，實際加值數量未提供。先前 00B4-only 的失敗紀錄保留；不擴大為所有商城商品效果、視覺或村莊入口通過。下方待回文字為各次換版當時狀態，最終結果以本節與接續收據 manualRetest 為準。

## 第二次實機回報：實際重整為 00A8

使用者回覆「重整鈕仍沒效，購買與重登會更新」，並詢問購買後放置位置。第一版 00B4 路徑修正未解決實際按鈕，不能標重整通過。購買先寫商城保管箱，C2S 00AD 領取才進一般背包；本輪後續唯讀保存觀察為 2625 已穿戴、2627 在背包、保管箱空。這支持付款／領取／穿戴的 Server 保存結果；指定 v2 視覺仍按使用者回報分列。

新 Host 日誌 `beaf6f6321224e7f8256087d46d5f712` 中有 17 次長度 2 的 00A8，未見 00B4，並有兩次 00AC、兩次 00AD。原版 `4A45F0..4A461F` 和指定 v2 bytes 一致，內含 `B8 A8 00 00 00`、兩 bytes 傳送；既有 `413590` 的 UI 點擊 578、control index 24 呼叫 `4A45F0`，另一 control index 26 才呼叫 `4A4660`。先前從 00B4 出現便推成主要重整按鈕，證據不足；此次由實機操作回報與同次日誌補正為 00A8。

Server 現將長度 2 的 00A8 接到已授權同錢包查詢及 00DD，保留已加入的 00B4 相容回覆；不再將 00B4 說成實際主要按鈕的已證請求。TCP 正流程用 00A8 查在線加值 17 後的 1,017，再以既有 00B4 查回復的 1,000；黑羽翅膀的正流程分別覆蓋兩種查詢。第一版收據仍保留，修正版驗證見 [00A8 接續收據](cash-refresh-a8-validation.json)。實機重整目前仍為退回待重測。

00A8 接續最終 591／591 HappyPath、Host／檢查器 Release 通過。核對 PID／部署路徑後只替換遊戲 Host 29852 → 31508，管理端 30276 保持 HTTP 200。再次請使用者同次登入加值後按重整，結果待回；沒有執行 Client、修改原件或直接發放商品。

## 原因與來源分界

現用 `Table.stp` SHA `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c` 是既有工作副本；其 `CashProduct.xml` SHA `d1971c9482f1b74cdc8ed9d0208cc65181ad0f03766b6dce470489155e41f9ed` 與原版表不同。共 1,083 列，NOW_SELLING=1、SELLING_STATE=0，1,020 列 SELLING_TYPE=0、63 列為 1，所有價格均永久。這些不是原服今日上架政策。

Product 與 ItemTable2 member 和原版完全相同，SHA 分別為 `8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c`、`7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2`。黑羽翅膀是 Product 2625 → Item 16357、class 18、slot 7、SP／MP 各 +120，現用價格 QTY=1、PERIOD=0、PRICE=250。原版 CashProduct 沒有 2625，所以固定目錄查無 offer，通用拒絕 DF/3 又被 Client 顯示為點數不足。日誌不記 payload；該次 Product 身份由畫面名稱及現用資源交叉對照，沒有宣稱抓到請求 Product 欄。

原版 `4A4660` 以 B8 B4 00 00 00 建立命令、寫兩個 bytes 並經既有 transport 發送。`4A4660..4A468F` 原版／指定 v2 bytes 相同，既有靜態反編譯 `413590`、`699000` 都在商城點擊路徑呼叫它。Server 日誌 `2026-11-18T17:06:03/04Z` 記錄兩次長度 2 的 command 180（00B4），緊接 PRIMARYAPPLICATIONUNAVAILABLE；亦有長度 9 的 00AC 及短拒絕回覆。這與未處理的重整請求一致。S2C 沿已核 00DD，不新增 opcode。

## Server 修正與供貨範圍

00A8 在正常已載入廣場／村莊、有效租約下讀 SQLite 錢包並回 00DD，00B4 保留既有相容回覆。後台加扣後，可同次登入重整，不以舊畫面快照推算。

新增獨立 [現用商城目錄](kr-working-copy.cash-shop.json)，schema 為 LOCAL_CASH_SHOP_CATALOG_V2_WORKING_COPY_NOT_NATIVE_MEF。[投影工具](../../governance/client-variants/20261118-cash-shop/build_working_catalog.py) 唯讀核對工作 STP、三個 member、parser 與原版目錄。保留原版 offer 供既有已付商品及保管箱；現用表依相同四欄鍵覆蓋價格。合成後 2,325 個鍵、1,783 個可購鍵；這是 Server 供貨政策，不是原服商城或原生 MEF。

現用新增供貨只接受既有六類飾品／時裝 slot、已支援角色資格、完整 options 恰為 12=120／13=120 的永久商品。額外屬性、不同資格、武器及特殊服務保留 available=false，效果仍待開發。黑羽翅膀可按 250 購買、領取及穿戴。原版目錄不變。

啟動器明示 -UseWorkingCopyCashShop，核對工作 Table.stp 身份才使用此目錄；單獨 -IncludeCashShop 保留原版 profile。手動商城啟動檔使用工作 profile，不能僅憑 exe SHA 推定相同資源。

## 驗證與實機待回

新增正流程：管理加值 1,000 → 2625 付款 250 → 領取 → slot 7 穿戴 → 同次登入後台加 250 → 00B4 回 1,000，重開 store 保存。既有新帳號 TCP 商城旅程補管理加扣及 00B4／00DD。新測試先後因 bagSlot／equipmentSlot 放反及誤用角色 0 而失敗；更正為已持有角色 1 後專項通過，失敗 TRX 保留。

指定 v2 待重測：黑羽翅膀付款、領取、穿戴，以及後台加值後按重整。Server 合成與換版健康檢查不得標實機通過。Client、STP、原件均未改；其他特殊商品與額外屬性仍待完成。收據見 [驗證索引](cash-working-copy-validation.json)。

最終 HappyPath 590／590 通過，Host／檢查器 Release 零警告零錯誤。隔離 Host profile 預檢通過且 listener 已清除；隨後核對原 PID 33364 與部署路徑，只替換該本機遊戲 Host，新 PID 29852 的 health 確認載入工作目錄 SHA `f13f57ed492ec99833b744ef99467f7d59e100d34a2990f05b516b20467b1cd4`。管理端 PID 30276 保持、HTTP 200。原兩張畫面及雜湊保留於本機 outputs，未公開圖片。實機修正後結果待使用者回覆。
