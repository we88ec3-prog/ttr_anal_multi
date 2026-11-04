# S00：v9連擊／受擊／怪物節奏整批部署

依使用者先前允許直接結束指定loopback測試連線的授權，核對Host4592的完整v8路徑後
只替換本任務Host。v9於UTC `2026-11-01T15:54:04.7260184Z` 啟動，PID60448，
來源私有Server commit `5cd508fbd006b8124bb2791deac91470a3a4c2ac`。
沒有啟動／操作／附加遊戲或修改Client；原有Admin2452與帳號資料保留，無migration。

本機實際模式仍為`LOCAL_WORKING_COPY_TUTORIAL_EXIT_CANDIDATE`，限定127.0.0.1。
netstat核對5082／8414／8415／8416均由60448監聽；健康端點auth與journey啟用，
管理頁HTTP200，啟動後stderr為0B。通用diagnostic的gameListener=false屬另一層旗標，
不能因此宣稱本機候選沒有登入／遊戲服務。啟動正常不等於遊玩驗收。

## 整批變更與可追溯值

- [連擊／受擊](S00-20261101-COMBO-RECOVERY-AND-HURT-COOLDOWN.md)：普通攻擊的候選350ms續段恢復，
  一筆400ms新鮮輸入意圖；移動受擊150ms、反應觸發冷卻900ms，仍正常扣血。
- [怪物節奏／MEF界線](S00-20261101-ENEMY-PACING-AND-MEF-BOUNDARY.md)：本場三怪輪流選擇，
  群體800ms出招間隔與個體2.4秒冷卻。其餘追擊、命中檢查與死亡／勝利前置保留。
- 以上時間為明示Server重建規則；沒有新增MEF下載／解譯器或宣稱官方AI已恢復。
  原有v8 loading23/24候選也保留，是否可見仍待人工觀察。

SQLite唯讀連線backup API取得換版前一致快照：
`accounts-before-combat-exit-v9.db` SHA256
`73c506bf32f7ee436c2038e8623349695a75b77b128977cc364c831a35688dd4`，schema2不變。
不公開DB、帳密或帳號紀錄。部署DLL SHA256：

| 檔案 | SHA256 |
| --- | --- |
| Tartaros.Network.dll | 5222e2e8c17d4db841a7412a26496ddbec80a4354f19a2995bc23b346015bdec |
| Tartaros.Protocol.dll | 914ee6efe591c8bc6e1d3fe69e4c1b2ca825e4197847a5a071dd82f5b7bcc262 |
| 測試Client（未變） | 6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c |

## 驗證與下一個實測段落

24個HappyPath合成案例通過，publish完成，啟動後核對上述PID／路徑／埠／健康／SHA。
負向、重登、競態、故障、安全、壓測仍暫緩；沒有為本輪另跑完整suite。

已送使用者回饋卡：正常教學到首戰，依次看三怪節奏、移動受擊、Z連段與放開停止、一次X；
戰鬥正常才續招募／劇情至廣場，走動停止後停下，不點NPC、不跳過教學。異常立即停。
**結果待回**；不把這張卡或合成fixture寫成GAME_RUNTIME通過。
現有測試帳號會保留進度，不構成全新帳號單輪教學／完整合法結算保存的證明。
REQ-0016／17／18、MEF與原生時序缺口保持未完成，正式核准與normative pin不變。
