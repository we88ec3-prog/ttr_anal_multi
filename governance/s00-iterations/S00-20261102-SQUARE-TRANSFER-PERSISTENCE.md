# S00：廣場轉移授權的保存界線

REQ-0017／原目標續作。v9實測卡待回，本輪不換版。先前人工已走到廣場的紀錄仍保留，
但當前帳號DB只保存首戰勝利、角色與裝備，缺少出口階段追溯，不能據此證明完整教學結算。

## 明確Server設計

新增獨立、可選的journey資料元件，記錄 **Server已授權從本次教學轉往廣場**：

| 欄位 | 意義 |
| --- | --- |
| account_id | 當前有效lease所屬帳號 |
| session_id／connection_id／session_revision | 授權時的有效session世代及連線 |
| authorized_at | Server UTC授權時間 |
| rule_version | 固定`TUTORIAL_EXIT_CANDIDATE_V1`，供之後規則更正追溯 |

唯一鍵為帳號＋session＋connection，與原首戰時間分開。紀錄不是Quest完成bitmap、
不是獎勵、不是Client已收到／完成載圖／Lua清理的ACK，也不會改登入時是否進入教學。
不把已保存的first_battle_completed_at回填成Quest14完成。

## 寫入與出站順序

1. 連線已在本輪由Server怪物HP／勝利排程取得首戰勝利，且已成功保存／返回教學。
2. 沿既有候選出口策略，收到1000/{10,12,13,14}有序回報；後段具有自有角色4／2。
   回報有載入失敗producer的限制仍保留，不因此稱原生終端完成事件。
3. 保存交易再次核對當前lease、已命名冒險團、自有角色4／2、首戰時間、角色4裝備。
4. 成功記錄授權後才建立原有loading／69廣場轉移封包。尚未成功保存時留pending，
   由現有world poll續做，不先發送廣場轉移。它不重播教學劇情、不重新授予角色或首戰獎勵。

這是Server後端可自行決策的追溯資料，不主張原服使用相同DB、欄位或寫入時機。
Quest14／16的合法結算、Reward type2/value50的語義與正式狀態消息仍另列缺口。
單靠新增保存欄位不會讓原目標完成。

## 元件與驗證

保留Account schema2、expedition v1、tutorial v1，新增獨立journey v1元件及轉移表。
既有tutorial資料不改寫。明確離線初始化工具才建立此元件；Host在exit模式只驗證，
不自動migration／repair，其他既有模式不要求新元件。

24個HappyPath案例通過，包含新帳號命名、首戰、角色取得、有序出口、廣場初始化與移動停止；
SQLite獨立查詢確認保存紀錄與當前session／connection／revision吻合。這是合成正流程，
不是原版Client或全新帳號人工驗收。負向、錯序／重送、故障、斷線／重登、併發、舊資料升級／
回復與壓測仍列待測，本輪沒有執行。

SOURCE ONLY：v9仍使用先前已部署程式與原DB，沒有對實測DB建立新元件。未修改Client。
正式規格／ADR核准、native FULL-PASS與normative pin均未變更。

## 來源界線

沿用[S00教學出口閘門](S00-20261101-TUTORIAL-EXIT-GATES.md)與
[Quest snapshot／Town context](S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.md)。
本輪查T16現有README確認其Server內部規則與Client封包研究分工，並保留T16-117 mode2提交
舊誤判的勘誤限制；沒有因名稱相似就補猜完成opcode。新元件沒有增加Client封包或native主張。
