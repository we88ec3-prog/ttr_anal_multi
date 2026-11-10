# S00：分支出口驗證紀錄

對應穩定SCENARIO-BRANCH-CONTRACT；仍是NOT_NATIVE_MEF，不代表官方格式／Client腳本。

最終337項受影響正常旅程回歸通過，Host Release與頁面JS檢查通過。
沿既有原生分析複核後修正0027整份集合替換語義：所有點放在同一封包，
驗證包含一包38bytes／兩列，而非兩包各一列。0048狀態更新仍依key逐個送。
驗證不同出口走1→2→4或1→3→4後進Result、只在提交後公開新游標、
世界層收到替代key82後發布替代地圖，以及兩種生命週期都開啟全部出口。
未執行延期的錯誤／循環／重送／安全／壓測測試，不將未測項寫成通過。

公開branch-example.scenario.json經實際typed loader載入並執行兩條到結果的路線，
SHA256 `972acf0502981b940490075c76bc0852f86c2f62ce73800fae3c34df137f03aa`。
這是作者示範，尚無實際BND配置及Client人測，不能直接替換正式任務內容。
新schema SHA256 `6802be57937881dcf8d97b497e456f11539d2f78e1b001ad00a79819c22f0400`。
上一版timed-only schema另存local-scenario-definition-timed-v1.schema.json。

v94增援補測已收到通過回覆；分支本身仍未做Client人測。
下一批附加入場標記候選，但不把標記／增援結果擴大成多出口實機驗收。
條件旗標／道具分支、組隊、跨實例、普通副本原生腳本入口及完整AI另有未完成項。

分支程式已隨v95載入；正式故事內容未新增分支，Client多出口仍未實機驗收。
當前短測只驗入場標記，不能據其回覆代驗分支。
