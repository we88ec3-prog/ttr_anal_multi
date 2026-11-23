# 完全復活效果 consumer：仍未閉合

2026-11-24。本次為來源與工具界線記錄，**不是新consumer語意結論，也不是效果已完成**。
既有[付費完全復活](CASH-COMPLETE-REVIVAL.md)的回滿資源、扣物、冷卻與同場續戰照原範圍保留；
Action3的VALUE=-800、Action23、死亡懲罰／評級恢復仍未知，不新增任何經驗、CP或其他退款。

重新核對原KR `Tartaros.bin` SHA256
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，與shared/targets.json一致；
不是指定v2 EXE或TC。REA6.5.0成功綁定此原件，Ghidra12.1.4的REBIRTH literal查詢觸發唯讀匯入。
此次未取得default auto-analysis之後的字串查詢結果；在300秒tools/call期限後返回工具錯誤，沒有Evidence或空搜尋結果。
過程曾核對自有Java PID14348的CPU持續增加；逾時後實查PID已不存在，再關閉REA session。
原件後驗SHA不變，沒有執行／附加Client，沒有改工具設定或原樣重跑同一失敗查詢。

完整已保存bulk偽碼目錄中對`REBIRTH`及`ItemUsableTable`兩個區分大小寫literal查詢未命中。
範圍只限保存的偽碼文字；這不能推出原件沒有相關字串或consumer，更不能給Action命名。
共用verified-knowledge／catalog與T03／T08／T11小型報告的有界查詢也沒有直接復活效果結論。
catalog的kr-T12-gap仍是「命中死亡復活權威缺失」的organizer判讀，不能反推全程式不存在consumer。

既有50C640與4C9530偽碼只可作class26使用入口及predicate的歷史引用；4C9530偽碼顯示以EAX為基底，
從偏移0x158的指標取偏移0x34，空指標時回1；物件型別未因此確認。這次沒有新的機器碼／完整函式語意驗收，
也沒有把該欄位命名為死亡、疲勞、評級或Action23效果。
T08的命令151鏈及技能可用性矩陣同樣沒有與這兩個Action建立關聯，不由數字巧合接線。
原Task／catalog／sealed研究包與既有FULL-PASS判定均未改寫。

原始ItemUsable表及其有限來源檢查仍見
[revival-source-verification.json](../../governance/client-variants/20261118-cash-shop/revival-source-verification.json)，
已發布的效果／退出缺口見
[較新來源補註](../../kr-extra-roy/MEF-level-functional-closure-20261118/outcomes-continuity/latest-main-update.md)。
本次工具紀錄：[revival-consumer-20261124.attempt.json](../testing/revival-consumer-20261124.attempt.json)。

後續需取得能連接Item使用效果與具體欄位變更的來源，或在有授權時取得相應運行證據。
不因此把所有Server MEF開發暫停；可獨立實作的地形解碼共用已另外交付，兩項狀態不混用。
