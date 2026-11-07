# v9：修復v8翻譯載入器存取違例；介面仍未完整中文

v8使用者回報0xC0000005；被動讀取遊戲自行產生的dump（SHA55da094bee82b24d10d7188abfa3670d0a8cc475264b9bd49d665c8c997b9011）確認EIP104D07C執行`mov word ptr[1048782],38`，ExceptionParameters為write／1048782。目的位於.csvzh，PEflags60000020（無WRITE）。沒有附加遊戲、讀取活程序或執行原生API；不發布dump或堆疊內容。

v8自己的mock只模擬ABI而未檢查記憶體頁權限，不能支持啟動通過。保留舊測試結果的限定範圍與失敗原件，不把歷史靜態通過改成人測通過。

v9從v7新建，保留v8。用新增可寫區段的selector選擇baseline路徑；既有翻譯baseline入口改為讀selector後尾呼叫原loader。成功掛載只寫自己的selector，原唯讀路徑不改。新增37條自訂指令／6個mock呼叫、selector權限、原路徑不變與dispatch檢查通過。實際原生掛載仍不由mock證明。

交付 `Tartaros.ip-zh-tw-v9.exe`，沿用v8的`U8/StringTable.stp`與`TC_UI/QuestTxt8.xml`，以及既有字型／翻譯依賴；原3D資源、fcs.flu、pack.gms未改。工具需同v8本機依賴與原件，不發布EXE／STP／XML。

使用者已回報可進遊戲，任務名稱中文，但任務按鈕／部分描述與村莊列表、隊伍介面仍韓文。這是部分通過，翻譯REQ-0022仍OPEN。結算及說話者尚未取得新的人測。後續核對真正caption locale／訊息文字來源，不再以FCS存在中文字作為實機成功證明。
