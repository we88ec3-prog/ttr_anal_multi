# S00：目前階段—全新帳號正常進入馮德斯村

使用者已將active goal由「新帳號完成教學到廣場」更新為「新帳號完成進入馮德斯村」。
這是本輪立即開發／驗收範圍；既有整村主線派工資料保留為後續準備，不把整村任務完成
誤列為本階段已實作，也不將直接傳送到村落冒充正常主線到達。

## 已完成與仍缺的接續

- 全新帳號教學到廣場已有[人工及保存資料證據](S00-20261102-FRESH-TUTORIAL-HUMAN-PASS.md)。
- 下一段必須銜接合法任務前置／廣場NPC主線、Quest15與其場景／必要戰鬥、正常村落初始化。
  [Quest14／16結算工作包](S00-20261101-TUTORIAL-SETTLEMENT-WORK-PACKAGES.json)仍開放，
  其中會影響Quest15接續的項目必須處理，不以新目標抹除前置缺口。
- 本階段終點：由全新帳號正常內容到達馮德斯村，村落地圖、玩家及所需NPC可見，
  輸入移動／放開停止正常；任務／進度保存可核對。進村過場鏡頭不等於一般村落就緒。

## 本輪新增原始資源核對

[可重跑工具](../inspect_phindos_entry_bridge.py)從原始KR Table備份唯讀讀取，
鎖定載體及QuestInfo／QuestTalk／SceneList各自SHA；
[完整選定欄位與限制](evidence/S00-20261102-PHINDOS-ENTRY-BRIDGE.json)。

| 資料域 | 實際內容 | 不能推定的事 |
| --- | --- | --- |
| QuestInfo15 | town5、field19、giver/finisher10338、Demand16 | NPC點擊就是接取／交付或可跳過前置 |
| SceneList15 | chapterIdx1、townId1，列sceneIdx1/2/3/4 | 這四列就是官服封包順序、每列自動完成任務 |
| QuestTalk | 本精確member無id15列 | 不需要NPC、沒有任何對話或一般UI永不適用 |
| 先前Town資源 | Town1/type1、map182/town001D、BNDv0 | 已證普通村落scene/controller或合法出生點 |

資源證據將任務所在Town5、章節Town1、地圖182分開，不能用同一整數變數混代。
Quest15沒有這張QuestTalk表列，故不能單憑一般QuestTalk模式自動捏造完成回覆；
下一個查核重點為實際SceneList/Event與NPC事件的入口、結束及換場連接。

## 持續開發順序與測試界線

1. 閉合Quest15前置及可供NPC／腳本使用的已提交任務狀態；PartyExp與Leeloo分域。
2. 核對NPC意圖與四段scene的因果關係、Field19/Case103/Map191/192所需的一般副本交握，
   哪些內容是必經由原始腳本證明，不猜wave或MEF格式。
3. 實作正常村落的scene、Town context、bounds、player/NPC與控制初始化，明示Server候選值。
4. 準備好有用的一整段才換版，提供從廣場可連測到村落的回饋卡；不反覆重測已通過教學。

AI／MEF仍由S00主查；[現有界線](S00-20261101-ENEMY-PACING-AND-MEF-BOUNDARY.md)
未找到完整MEF parser／網路接收鏈，現有三怪AI是Server程式。不得因本目標改稱已還原MEF。
連擊／移動後攻擊手感按使用者要求到後續副本測試。負向、重登、併發、故障等仍暫緩。
本輪新增資源核對與規劃，不改Client、Host、DB schema或正式APPROVED／FULL-PASS狀態。
