## 後續狀態更新

已新增明示opt-in的提交後發布adapter，詳見[發布與控制器核對](S00-20261102-TUTORIAL-PREREQUISITES-PUBLICATION.md)。
下文「沒有接入adapter」是本保存元件首次提交時狀態；目前live v10仍未啟用、未換版、未migration。

# S00：教學任務前置的獨立保存候選（SOURCE ONLY）

為後續Quest15／廣場NPC接續新增私有Server domain元件，沒有接入目前Host、沒有發6F／74、
沒有對live DB migration或換版。這不是官方Quest14／16算法，亦非已完成進村。

## 明示的Server重建政策

本候選採account／冒險團scope；前置為當前lease有效、role4自有、role2已招募、role4裝備存在、
首戰勝利已保存，且有**同一session／connection／revision**的square transfer授權紀錄。
該transfer在既有連線程式中還要求本輪Server勝利／返回及10/12/13/14有序事件。
內部方法不是對外Client任意完成API，不將任意3F literal1直接授完成。

此重建政策將滿足完整正常教學的14／16記為prerequisite keys；不是各任務官服接取／交付細節
已還原。它須在後續Client介面及產品規則整合時繼續核對，不能直接升APPROVED。
本輪沒有把舊帳號歷史勝利回填為Quest完成，也沒有讓live NPC讀到這些keys。

## 實作資料邊界

新增獨立tutorial quest component v1，要求既有tutorial及journey元件，Account user_version不變。
明示CLI `--initialize-tutorial-quest-component-v1`只初始化另外五表；Host沒有自動migration或啟用。

- component marker：僅識別這個候選定義。
- prerequisite state／keys：owner全集合與revision，保存後才提供snapshot資料；首次本政策寫入revision2。
- tutorial settlement：account唯一，保存來源session／connection／lease revision／rule／UTC，FK綁到transfer。
- reward entitlement：Quest16原始type2/value50，狀態固定PENDING_NATIVE_PUBLICATION。

同一交易再驗lease／ownership／transfer／win，記錄keys、來源及entitlement，讀取整個owner集合。
沒有猜貨幣、沒有將PartyExp entitlement寫成已付款、沒有發native餘額／等級／技能更新。
獎勵定義的Client PartyExp顯示對應見[已採用分析](S00-20261102-QUEST-REWARD-CHANNELS.md)。
真正發獎與Client更新仍待W5／S00閉合；這個候選不宣稱官方獎勵已完成交付。

## 實際驗證

既有正流程TCP案例完成首戰、招募、有序出口與保存transfer後，測試以同一實際lease
呼叫內部commit，再獨立SQL join settlement→transfer核對：keys14/16、rule、原始type2/value50、
PENDING_NATIVE_PUBLICATION。完整25個HappyPath通過；CLI建置零警告／錯誤。
測試用DB建立新元件，不是live migration；負向／重送／重登／故障／併發仍未執行。

## 接續需求

接上live前要閉合NPC候選列表、前置key發布時序與Quest15正常啟動，並完成一整段可人測的版本。
不得只為此元件重啟Host。新的[明日Web AI工作包](../../research/handoffs/s00-phindos-web-analysis-20261103/README.md)
將任務／場景／村落／副本／角色獎勵分工，先解除真正進村卡點再展開整村劇情。
