# 關卡 MEF：接續開發與優化順序

本輪完成的是[20類功能分析](feature-status.json)與[9項改善規劃](optimization-plan.json)。以下均屬Server MEF開發／整合／內容工作；現有JSON／typed規則可以直接使用，沒有「必須先創造新格式」的前提。選用新語法、Client profile或新演出時，才開對應轉接工作。

## P0：先使選定關卡版本和交接一致

### D01：選定一份真正要玩的內容

直接從現有Q119、普通Case或功能lab選一個版本，固定來源、圖hash和獎勵政策。清場版、血魔延續版、陷阱版、占點版、掉落版是不同候選；需要合併時產生明確的新配置並保留差異，不默默當成已同時啟用。

接受條件是圖與旗標依賴、schema、所選BND位置／通行、Boss與掉落身分、收益提交點彼此一致。這輪的67檔稽核可直接用作內容分析基礎，但不是重新宣告每份候選都已部署。[規則分析](rules-waves/report.md)、[結果投影](outcomes-continuity/outcome-projections.json)

### D02：處理已找到的內容問題

若採用舊分岔範例，使用本輪13個座標候選或重新選點；5出口、2出生、3怪物的十個阻擋點有明確位置。候選已做靜態核對，尚未改原檔。若採用Q119屏障，明確選「局部障礙、出口獨立鎖定」；若要真正封路，需關閉時斷路、必要怪和機關仍可達、開啟後通路成立，並另綁3D門與Client碰撞。[可直接審查的修正方案](space-mechanisms/content-remediation.json)

### D03：維持清場、點集、倒數與結果的既有語意

MEF adapter必須保持：必要波未生成仍阻擋清場；剩餘投射物／勝利等待／移除排送不省略；清場演出完成並提交後才重建；完整0027由已提交旗標生成；同世代點變更才用0048。

權威倒數沿用原時計與各種類型的原點、演出期間規則和合格更新。Q119擊倒68與返回結算5880分開；普通副本結果用實際提交收據；掉落出現不等於入包。接受條件是選定正常旅程的波次時點、出口資格、物品、經驗和重登資料符合既有政策。[交接契約](finite-handoff/handoff-contract.json)、[規則優化等價條件](rules-waves/optimization-contracts.json)、[生命週期](outcomes-continuity/lifecycle-contracts.json)

### D04：按所選演出綁定有效入口

有限Client MEF可合併多步本地等待／效果，但先固定provider、scene selector、正式與預掃描callback、共享狀態cleanup、輸入交接及播放政策。`CSL.scn`可保存seen，不能以Client重啟／Server本次未送過就推論必播。

只要一個出口開關時優先既有完整快照或單次0048。若新內容需要重建後演出，才新增hook；目前schema沒有該hook。可跳過的純演出不掌握唯一業務進度；若真的要求最後setter才開門，另設延後開點、當代owner與有效執行政策，不能讓003F直接充當setter成功證明。[原件與可採路線](finite-handoff/report.md)

## P1：少做重複工作，補齊玩家可見接口

### D05：事件索引、波次彙總與期限

載入選定definition時建立事件與flag→consumer索引。本輪67檔合計26筆旗標引用是覆蓋統計，不是每場固定索引大小。以有效HP／生成變更維護每波活怪、當前／最大血量；死亡成員仍留在血量分母，待生成必要波仍參與清場。

沿用既有單調時計，依各計時種類維護期限；期限到了仍在原有效更新階段處理，保留定時先於順序與陣列次序。接受條件是同一正常內容的事件與提交順序相同，再比較實際規則評估量和timer工作量。[7項規則優化契約](rules-waves/optimization-contracts.json)

### D06：區域、點狀態與路徑共用

完成的一次性區域可退訂；仍需觀察出區的占點／危險區不能只記「進過」。索引粗篩後保留精確距離與邊界判定。作者工具應分別顯示Server半徑、category0 Client小於0.8倍半徑的可按區、目前barrier overlay。

只在安裝／重建發完整0027，同點集間只送確實變更；旗標影響通路時才失效相依路徑。沿用既有撞牆只停一次、真移動才發位置的處理，不把它重列成本輪新優化。[6項空間優化契約](space-mechanisms/spatial-contracts.json)

### D07：補公開玩法範例和具體玩家操作

現有67檔未配置RegionEntered、BossDefeated signal、初始空場、具名requiredBoss.waveId。這是公開範例缺口；BossDefeated有Q119合成紀錄、延後Boss有私有離線紀錄，初始空場在目前schema／契約支援。整理可追溯小型配置即可，不從頭重建引擎。

另依所選功能接：占點／陷阱／拉桿提示資產、掉落可見性、v2復活動畫與操控、主線倒地退出按鈕／請求、普通副本內離隊UI。完全復活的死亡懲罰解除，以及Raid主動退出／斷線CP是各自獨立的剩餘政策／consumer；不以原地復活成功代替全部完成。[規則缺口](rules-waves/report.md)、[保存與退出缺口](outcomes-continuity/report.md)

## P2：共用計畫與需要時才擴玩法

### D08：不可變計畫、地形與路徑快取

以內容hash與政策版本共用不可變catalog／圖／索引；每個instance只持有自己的flags、游標、timer、open／used集合。以BND解碼hash＋政策共用底圖，barrier overlay保留實例獨立。

本corpus118 MapID對74 BND；相對每MapID解一次可少44次重複解碼，這是工作量比較，不是實測CPU節省。實際收益需記錄解碼／尋路次數、展開格數、規則評估、封包bytes與交易耗時，再與相同內容比。[空間收益邊界](space-mechanisms/report.md)

### D09：按玩法需求新增typed MEF規則

若要隨機權重路線、循環與重複計數器、背包／任務道具條件、跨實例隊伍事件或戰鬥中途永久checkpoint，現行schema仍需擴充。每項都應附清楚的事件來源、條件型別、提交／保存政策和既有服務adapter。

要普通戰鬥不中斷且常駐Client腳本時，需選定controller、tick、合法輸入、事件觀察／回報及取消生命週期；這是特定profile開發，不把它變成所有Server MEF或有限演出的共同阻塞。真正物理門則沿選定資產、公開可達操作和碰撞consumer繼續追。[目前能力方向](../MEF-server-provided-capabilities-20261118/DEVELOPMENT-PLAN.md)

## 驗證沿用現行正常流程

本輪只跑只讀來源／機器碼／內容／幾何分析。後續部署驗收先沿已排定的正常旅程，確認看得見、操作得到、完成後物品／經驗／進度正確，再比較工作量。沒有因本規劃新增壓測或故障／併發測試，也不代填正式RR或玩家驗收。

發布前較新main已補完全復活的付款到同場續戰串接、裝備容量與消耗／熟練度等紀錄，直接沿用；CS系列實機與換版仍暫停，不由本包變更排程。詳[最新來源補註](LATEST-MAIN-UPDATE.md)。
