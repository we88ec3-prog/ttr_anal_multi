# ChatGPT Web：T10／T11 技能與連段補查工作卡

使用者於2026-11-01要求先查看現有T10/T11缺口，再透過本分析庫交代Web工作，成果供
後續獨立Server開發使用。`as_server_spec`是誤植，已撤回，**不涉及該專案**。
本文件是使用者授權的補查範圍與交付約定，不是另一份RR台帳、已發布的正式認領或Task完成宣告。

## 已核對的目前狀態

唯讀取得公開main **ac6aac673426459df2a778d20a80c623b8559a92**。
[baseline.json](baseline.json)綁定README／task.json／inbox的精確Git blob，保存選定狀態與缺口。

| 主責 | 現有成果 | 明確缺口與注意事項 |
| --- | --- | --- |
| T10 普通攻擊與連段 | 156筆引用證據，既有輸入／矩陣／傳輸局部研究 | 官方連段／取消窗口未知；舊CHAIN_WINDOW=.65和Server續段排程是自製；另有T01退回待修 |
| T11 技能施放 | 31筆引用證據，技能矩陣／條件／旗標／計時局部研究 | 讀出矩陣不等於施放決策；冷卻、消耗及裁決未閉合 |

兩項task.json均為owner=null、state=unclaimed、native_complete=false；兩收件箱均無待處理RR。
這只反映庫內登記，**不表示使用者在Web或其他對話沒有進行工作**。先核對是否已有未提交
新報告，依來源去重；不自行改owner／task.json／inbox或假設現有報告全部失效。

必讀：根AGENTS、共用Client政策、T10/T11 README、task.json、
[派工規則](../../dispatch/README.md)、唯一RR台帳及相關source-review索引。
此工作卡不授權技能任務執行／附加遊戲或修改Client；開場畫面的單次修改例外不適用本工作。

## 目前遊戲與Server背景

指定工作副本SHA為6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c。
玩家實測已完成移動／視角／切角、伊莉西亞編隊、首戰及返回教學劇情。
05/1教學專用UI進場路徑與09請求詳見
[S00進場報告](../../../governance/s00-iterations/S00-20261101-TUTORIAL-ENTRY-PHASE.md)。
原版換場畫面因太快仍未確認；蘋果家劇情後另有角色取得阻塞，不能寫整段教學完成。

使用者另回報「新手對戰很不順暢」，詢問地圖是否有生成3隻怪的資訊，並要求處理技能施放與連擊。
當前Server只是單敵prototype：HP60、普攻20／X35／組合60、200ms impact、固定距離與
動作／冷卻近似值，未完成AI反擊、成本或完整波次。這些是待替換的Server實驗選擇，
**不提供其私有實作、不把它們反推成原版規則，也不能因能打完就當作戰鬥品質驗收。**

## T10優先補查：輸入到連段／取消的可追溯鏈

1. 先處理README既有T01退回，特別是
   `T01-RETURN-T10-116-ROW5-PROVENANCE-001`：Row B第五byte有保留R+E4的可達支，
   不是無條件R+B0；Row A需按ESP／virtual ABI與最後writer分支核對。保留原稿，交勘誤與新blob。
   055/056錯位視窗、062初始化順序、063writer guard、007/026位址／語意更正也須依README處理。
2. 普攻按下、放開、按住及快速再按如何進入輸入快照、封包row與動作狀態。
   分開各writer／owner gate／hero限制；不能把一支的BYTE來源擴大到所有角色與路徑。
3. 連段的輸入buffer、可接受／取消窗口、下一段選擇、移動中斷與動作收尾，
   對應原生clock、frame／animation事件及reset。沒有來源就明列未知，不沿用.65等舊fixture。
4. C2S輸入、S2C動作、Client播放與Server決策分開。0A、0D是候選入口，
   已有哪部分原生證據就引用哪部分，不因編號相同推官方配對。

## T11優先補查：技能決策與可供Server使用的參數

1. 先選伊莉西亞首戰技能，完成Skill ID、Motion ID、Effect／TargetSkill ID的鏈；
   不把TargetSkill ID直接當Motion ID。候選101…107、108／109及49／50／52仍需追溯來源。
2. 學習／等級／preset／slot、角色與裝備條件到可施放判斷，包含矩陣與非矩陣路徑。
   候選126／127／12C的消費形狀已有局部重核，不代表官方發送時序或技能取得政策完成。
3. 施放時間、冷卻起點／結束、資源消耗、連按／按住處理、互斥／取消及移動銜接。
   分清Client預顯示、Client gate與Server應裁決內容；Client沒有的官方後端規則留UNKNOWN。
4. 0D的float目前有動畫速度倍率的限定證據，不能當開始時間或以0凍結動作。
   舊tutorial-native-skills-v19是修改工作副本的記憶體快照，不是原始BIN／靜態資源清單。
5. 命中時間／目標／範圍的資料接口與傷害公式界線要明列；T10明文把傷害公式交T12，
   此工作不能越權把HP扣減、公式或暴擊等未知補成已確認結果。

## 「3隻怪」的相關依賴，另列給S00協調

目前pinned Field.stp的首cluster為set0/cluster1、OBJECTID1036/PRE1/COUNT1；
COUNT是**單次cluster呼叫**，不是整個Scenario14總數。
[既有核對](../../../governance/s00-iterations/evidence/S00-20261101-FIRST-TUTORIAL-CLUSTER.json)
沒有證明只有1隻，也沒有證明應有3隻。不可因玩家提問就硬寫COUNT3當作資源事實。
需補觸發器／重複呼叫／波次／位置與合法結束條件，由S00依主責協調地圖／戰鬥任務，
不塞入T10/T11傷害／技能研究冒稱已閉合。

額外唯讀盤點：Town.stp含Town/town000D.fld及.mre；Scenario.stp含
Scenario/scenario_town000D.fld及.mre。FLD是幾何／環境XML，MRE標頭GEOM_RESOURCE v1；
檔名不能當成MEF trigger。這兩包索引未列出`.mef`成員；
此有限盤點不是整套遊戲「不存在MEF」的證明，也不證明幾何Object數就是怪物數。

## 交付格式與使用方式

先交一份限定報告，建議位置`research/handoffs/s00-web-skill-gap-20261101/`，檔名包含
日期與T10/T11及主題，**不覆蓋原作者原稿**。有Git工具與授權才提交／推送；否則交可保存原文。
Web看不到E磁碟，缺BIN／資源時列出精確所需檔案，不能假裝讀過本機。

原始KR BIN SHA：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。
每份交付包含：

- baseline commit、來源路徑／blob／SHA、工具版本、有效指令邊界與實際查核範圍。
- `已確認／部分確認／推論／Server設計選擇／UNKNOWN`分欄；有反證就保留，不做整份FULL-PASS。
- 逐項Server可用資料表：觸發、輸入、gate、ID／型別／offset、輸出、clock／單位、
  reset／lifecycle、來源及未解依賴；官方回覆配對未證就標未證。
- 普攻／技能狀態流程與正流程驗收案例，列出哪些可立即落地、哪些必須補證；
  異常／重送／併發／安全／壓測案例只列待測，現在不執行。
- 舊結論的保留／更正清單，尤其.65連段窗口、速度float與不同ID域，避免下次再直接照搬。

這份文件與Git更新不會自動通知／喚醒Web。使用者可將本文件連結貼給ChatGPT Web並說：
「請依這份工作卡先完成T10／T11缺口核對，從最影響新手伊莉西亞戰鬥順暢度的項目開始，
  回報能讓Server直接使用的有限證據與剩餘UNKNOWN；不要改Client或把候選當官方規則。」
