# 已交付任務門檻：正常 NPC 接取與交付

2026-11-22，OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。補
[QuestCompleted](../scenario-content/QUEST-COMPLETION-SIGNALS.md)先前只準備完成紀錄的缺口。
原有準備方式保留；本項只新增獨立的正常 NPC／TCP 路線，不改任務或副本規則。

準備仍限隔離帳號的教學／Q15資格、角色4／Lv15及已公布政策；不預先寫入Q2842。
正常登入、primary交接、廣場建隊及入村後，依原BND走到NPC10002。該NPC先屬Q117：
由正常001C觸發0047/Quest117/Scene1，再送003F與正式gateway world poll提交，
回村依0043完成載入、收到0024後才繼續。原政策Q117無EXP，保存QuestIndex1。
003F為合成回報，不是Client成功播放證明。這不取消主線NPC優先規則。

之後由C2S0036接取
Q2842，核對0040與初始0042；兩次正常001C/NPC互動分別使目標Ready及Completed。
每一步核對已保存狀態；完成前不發0046，完成後核對700EXP及005C／0034/type1，
背包與錢包保持此任務無物品報酬的既有規則。

接著由同一隊伍正常選Stage462、開始Case693 quest-gate候選，觀察已保存Completed
設立quest-types-completed，再實際拾取183與消耗機關，走原波次／頭目／分支到結果。
任務700EXP與副本88EXP使用獨立的前後基準；最終保存增量788EXP，回原村同隊，
沒有把任務報酬算成副本收益或由門檻再次給獎。
回村再以授權讀取確認Q2842仍Completed、主線QuestIndex仍1，並核對總增量。

所有遊戲輸入經登入／primary socket及正式gateway，時間沿既有檢查器時計；NPC
移動使用已載入BND的路徑及正常方向輸入，不能SetPosition、進度覆寫、直接Handle／
Poll、直接AdvanceHuntingQuest或寫SQL補任務。store／SQL僅讀取正常操作的保存證據。
此「正常NPC」只指工程路線所走的遊戲協定及領域服務，不等於Client視窗點擊驗收。

指定v2、自然新帳號一路升級、獨立部署Host遊戲通關、瀏覽器新欄位及暫緩的非正流程
測試仍分開待驗。現有運行服務不換版，原始資源與既有證據保留。

## 最終正流程結果

兩條分支均走正常Q117→NPC接取／Ready／交付Q2842→Stage462選關→原機關、波次、
頭目、結果並回原村同隊。Q2842的6次方向輸入及23次gateway poll包含正常場景提交與
回村載入，並非設定座標。任務700EXP、副本88EXP分別保存，最後39788／Lv15；
回村仍Completed及主線索引1。兩路各5枚投射物建立／移除，機關各扣1個183。

Release Host／Inspector／Admin.Web零警告錯誤，674 HappyPath通過；本批未改生產
規則或新增單元案例，新增驅動由實際TCP驗證。單元、Host、Admin與檢查器的Network
核心DLL bytes相同。初次缺少Q117、gateway poll或0043的失敗嘗試留存，沒有改Server
放行。結果見 [機器收據](quest-gate-npc-tcp-validation.json)。
