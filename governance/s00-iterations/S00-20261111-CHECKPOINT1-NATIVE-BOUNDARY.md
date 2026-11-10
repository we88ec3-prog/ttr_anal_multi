# S00：category1手動檢查點的原生邊界

沿用已釘定KR BIN與既有函式快取，重算原件SHA及選定範圍，不重跑舊MEF搜尋。
目標SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
[有界證據](evidence/S00-20261111-CHECKPOINT1-MANUAL-INTENT.json)保留窗口身份與少量新增判讀指令。
REA開啟呼叫逾時後未重啟分析；只讀session仍核對同一目標，無可觀察活動。
本輪語意來自既有反編譯與現件窗口比對，不宣稱新全量反編譯完成。

- 原TutorialBase Lua主prototype pc2定義CHECKPOINT_CATEGORY.SAVEPOINT=1，與PORTAL=0、NPC=3不同。
- 4B2AF0接0027後先清集合，每18B列將signed category、key、位置、radius、enable等交543700。
- 543700保存category與key，category1不進category0的傳送陣效果建構與radius×0.8分支。
- 544730對已啟用點檢查距離與manual按鍵，544A00從有效點選最近者並調virtual+64。
- 544070對3走NPC/UI、2走市集、4走教學、5走Client自訂；category1在已查普通模式走544020，送6B C2S001C(category,key)。模式與controller前提仍存在，不保證所有場景都會送。
- 544940同時比對category/key，543B30先寫enable+105；0048可對category1改狀態，不需發明新opcode。

原生SAVEPOINT名詞不證官方存檔政策、3D機關、任務道具或MEF產生器。重建用途是手動互動點
觸發Server定義旗標；這是SERVER_DESIGN_CHOICE，不提升為原版機關完整復原。
category1無已證視覺，本次可附一個不同key的category0關閉圈作可見提示；所有點必須在同一0027集合。
提示圈仍不可互動、不是傳送，也不代表原版機關外觀。完全未修改或執行Client；實際按鍵仍待日後集中人測。

Native category1輸入以嚴格距離小於wireRadius判斷，Server重建Region採含邊界驗證；兩者不宣稱完全相同半徑。
