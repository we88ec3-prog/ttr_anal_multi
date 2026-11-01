# S00：全新帳號正常教學到廣場人工通過

使用者依替代短帳號測試卡回覆：「完成教學，到廣場且能移動停止」。
測試卡要求首次登入／命名、方向鍵／滑鼠／視角、Tab、預設伊莉西亞首戰、
蘋果招募與後續劇情、廣場人物／NPC顯示與移動停止；不點廣場NPC、不跳過教學。
這是使用者操作指定工作副本的一次完整正流程結果，不把它改寫為未修改KR原版驗收。

## 獨立保存證據

[去識別測前／測後資料](evidence/S00-20261102-FRESH-TUTORIAL-HUMAN-PASS.json)：
同一私有帳號參考值已核對相等，公開移除參考值、帳密與顯示名稱。

| 項目 | 測前 | 測後 |
| --- | --- | --- |
| 冒險團profile／命名 | 無／無 | 有／有，revision4 |
| 自有角色 | 空 | 1、2、3、4 |
| 首戰勝利保存 | 無 | 有，tutorial revision3 |
| 教學裝備 | 無 | role4／slot1／item28 |
| session／獨立character列 | 0／0 | 0／0 |
| journey transfer component | 無 | 無，未遷移 |

character列屬另一套選角模型，不將其0誤認為冒險團四位隊員消失。
測後session0也不能證明遊戲仍在線。metadata在17:08:42.8933042Z有PeerEOF／Close，
與本次測後資料相符；不依此猜測使用者為何關閉遊戲，也沒有執行重登恢復測試。

正常登入metadata為UTC17:05:49.2897497 AUTHACCEPTED，接著TXCOMPLETED163；
primary有handoff、roster、命名結果與教學entry，17:06:53.3429425保存首戰勝利，
後續正常scene1000/10、12、13、14均有對應事件。日誌跨segment分割，按時間合併，
沒有把單一segment當整場，也未公開原始封包或連線識別。
這些metadata支援流程追蹤，廣場可見可動則依使用者人工回覆，不從43推定Client ready。

Host仍為v10 code`cd2a7bc70f3cfb92602628137bf65c5df81b0eb2`，
測試EXE本輪重算SHA仍為`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。
沒有換Server、改Client／資源或做migration。原登入名稱過長失敗與替代fixture修復
仍保留於[S00觀察](S00-20261102-FRESH-LOGIN-NAME-LIMIT.md)，不抹除第一次失敗。

## 驗收範圍與下一個必要缺口

新帳號「正常遊玩到廣場且能移動停止」已有人工與相應保存證據。
**Quest14／16合法結算、獎勵／Client完成狀態發布、terminal保存仍未完成**；
不能將上述正流程通過或已有首戰win直接等同這些狀態已存在。
轉場畫面可見性、戰鬥連擊／移動後攻擊手感仍未因這輪回覆被確認，後者按使用者排到馮德斯副本。
廣場NPC主線及MEF／原生AI也未在這張卡驗收。完整goal保持未結案。

REQ-0017追加GAME_RUNTIME_OBSERVATION；台帳19REQ／CODE5／RUNTIME26／PLAYER8／APPROVED0。
正式規格、批准、原生FULL-PASS狀態不變；本輪只有保存核對與紀錄，未重跑無關合成測試。
