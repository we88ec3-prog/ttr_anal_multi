# S00：蘋果房屋前180筆輸入耗盡與補給修正

## 人測與實際Server證據

使用者在v9回報「要進入蘋果房屋前突然不能移動」，補充「沒有對話框，按方向鍵角色完全不動」。
這是指定修改工作副本的GAME_RUNTIME_OBSERVATION，非原版Client驗收。
測試Client SHA仍為`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。
v9 Host60448／來源`5cd508fbd006b8124bb2791deac91470a3a4c2ac`，主連線仍ESTABLISHED，心跳續回。

直接打開metadata JSONL讀取後確認：Server已保存本輪首戰勝利，依序收到1000/10及1000/12；
有且只有 **180筆C2S000A**，最後一筆UTC `2026-11-01T16:08:34.681783Z`，之後仍有心跳，
沒有1000/13。這排除了「Server已斷線」的判斷，但只靠metadata不能恢復方向／按鍵內容。
[可重現摘要工具](../summarize_runtime_input_metadata.py)、[本輪snapshot](evidence/S00-20261102-V9-HOUSE-INPUT-METADATA.json)。

**日誌觀測更正：**先前只看目錄項Length=0，誤認為未寫日誌；實際開啟檔案handle可讀到持續
增加的metadata。目錄快取大小不能當作pump失敗或無流量證據。這輪不修改健康的journal寫入器。

## 原生counter／訊息的限定證據

KR原BIN SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
選讀已存REA/Ghidra並從原檔核對5個有效指令視窗，沒有執行／附加Client：

- CClient前端16-byte槽的`C+FA8`為command DA：`4931F6`載handler4959F0，`4931FB`存入該槽。
- `495A44 add [FBA7B0],5`：S2C DA給輸入發送counter加5。
- `4B8001 mov [FBA7B0],30`：既有scene bootstrap資料路線初始化為30。
- `5457A4`讀counter；`5457F7/F9`要求大於0才走後面的非空000A產生／送出路徑。
  同函式按counter區間選發包門檻；這不是角色連段窗口。
- `545B38`檢查000A組出長度大於6，`545B4F`扣counter一次，之後交發送介面。
  因此消費單位是一次非空batch，**不是每筆row、每次命中或玩家資源值**。

[核對器](../inspect_input_credit_sources.py)、[byte／指令證據](evidence/S00-20261102-INPUT-CREDIT.json)。
這支持輸入流控介面，不等於原服補給頻率或所有分派／傳輸的FULL-PASS。

v9原本只在5次角色／地圖重建相關時點各送6個DA，共30個DA；每個加5，加bootstrap30，
總計`30 + 30×5 = 180`，恰與最後實收000A數一致。Counter耗盡是這次停止發送的明確機制。
它不是金錢、體力、技能CD或允許玩家移動次數的遊戲規則。

## Server修正

- 認證後、教學已提供的connection，每收到5個結構有效的非空000A batch，補1個S2C DA。
  以已收的batch數做平衡，不靠固定時間、heartbeat或劇情報告無限灌額度。
- 補給與gameplay授權分開：重複actor row／未知旗標不因此獲得移動、傷害或任務授權。
  Row數不乘大補給量；DA不是「動作已成功」或Quest完成ACK。
- 舊初始化補給保留；實際每5筆回5額度是明示Server策略，不宣稱官服相同時序。
- 先前source-only廣場轉移保存改為獨立明確opt-in：
  `TARTAROS_LOCAL_TUTORIAL_JOURNEY_MODE=LOCAL_WORKING_COPY_TUTORIAL_JOURNEY_PERSISTENCE_CANDIDATE`。
  預設OFF，故本次修bug可沿用v9原資料元件，不建立新表、不migration。

25個HappyPath案例通過，包含保存元件ON／OFF兩條正常廣場路線，兩者各在蘋果家前連續
移動200筆、恰收到40個DA，然後繼續招募、廣場初始化、移動與停止。新heartbeat barrier只為
先排空前序回覆，不拿heartbeat當補給。測試先後修正前序DA被算入與新增heartbeat計數，
保留失敗紀錄，不改Server規則來掩蓋fixture計數錯誤。未執行負向／重登／競態／故障測試。

## 使用者後續測試安排

使用者要求「連擊可能還要優化，之後進入馮德斯村的副本再做測試優化」；另回報
「移動後攻擊可能也要做修正或優化」。兩項保留REQ-0016，後續正常副本戰鬥再測，未標通過。
目前先解除房屋前卡點，不要求重測戰鬥手感。新版本實際部署／人工是否通過另記；
完整新帳號教學、Quest14/16與獎勵仍未宣稱完成。
