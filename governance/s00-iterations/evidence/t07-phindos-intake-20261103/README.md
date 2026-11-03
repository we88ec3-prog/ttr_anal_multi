# T07馮德斯有限來源匯入（2026-11-03）

此目錄把本機尚未由Git追蹤的T07歷史分析資料，依S00當前開發需要保存為可追溯的有限來源。
[manifest.json](manifest.json)列15份原路徑／原SHA／副本SHA，全部逐byte一致。只匯入5份說明與10份有限證據JSON；不複製Client原件、私人Server實作、帳號DB、runtime log或整批反編譯cache。

## 本輪引用範圍

- [劇情與編隊](post-t01/STORY-AND-FREE-PARTY-INTERFACE.md)：47場景入口、50可用／預選／容量、4E／28 token回送。
- [Field19／Case103分域](post-t01/FIELD19-CASE103-ID-CONTRACT.md)：38的Case預載key、Map191/192與Chart資源。
- [一般結果／返回](post-t01/SCENARIO-RESULT-AND-RETURN-INTERFACE.md)：22/type0、結果資料存取下限、33無目的地參數。
- [MissionLobby／Town依賴](post-t01/MISSION-LOBBY-AND-TOWN-PRELOAD-DEPENDENCIES.md)：99/type3局部控制器／UI生命週期，Town預載不等實體map。
- [Scenario生命週期](phindous-roundtrip/SCENE-ROUNDTRIP-INTERFACE.md)：5F/type2、kind3、reset／bind／ready及結果後controller切換。

原件SHA、check範圍及仍未知的欄位保留在各JSON。表中的數字域不可合併：Quest15、Field19、Case103、Map191/192/182、Town1；4E token仍是原樣echo介面，不能因候選取19就宣稱官方域已證。

## 歷史狀態與本輪驗證分開

來源文字中的「待整合」、v7/v8人測、歷史檢查項數及各未知都保持原樣。這次複製／hash核對不是全文語意驗收，也不改Task owner、正式APPROVED／FULL-PASS或原始結論的限制。

主工作流本輪回報的27項正流程合成測試是當前私有Server的獨立結果；這個匯入工作沒有重跑該測試，也沒有執行／操作Client。合成測試可支持候選Server資料流，不能證實原版視窗、換場、NPC／隊伍或正常進村已人工通過。

99/type3仍只能由有限來源證明CMissionRoom／MissionLobbyPage控制路徑，未證它就是官服Town1安裝路線；用在本輪村落候選時必須保持Server重建標籤。Field19的MEF排程、官方波次／勝利／發獎及正常村落spawn沒有因來源匯入而補齊。

## 相依檔與公開範圍

為保留byte identity，來源內相對連結／JSON source path未改寫；其中部分指向未匯入的`.c`、原始cache、影片筆記或舊候選程式，**不保證在本公開目錄可點開**。各項原SHA仍可供本機按位址回查保存bulk；這不是完整原始證據包。現行開發報告應連到本目錄已存在的指定文件，並對未收錄相依另列未知。

已讀取選定UTF-8文字／JSON並做帳密／secret／credential等字串檢查，沒有命中；檔中可保留歷史本機來源路徑及公開協定token名稱，兩者不是登入憑證。
