# 動態循環：接續實作計畫

2026-11-22追加：[節點訪次與機關帳本V2](SCENARIO-VISIT-IDENTITY.md)已完成進入／fork／選擇身分、舊帳本保留與同節點兩訪扣款領域正流程；四路既有TCP／685 HappyPath通過。以下為此前來源快照及全循環計畫；旗標／loop作用域、循環控制與完整動態路線仍待完成，沒有放行cycle。

2026-11-22，SERVER_DESIGN_CHOICE／DRAFT／NOT_NATIVE_MEF。尚未實作完成，
不能把既有有限展開或本批條件分支改稱動態loop。目標是在同場依實際已提交
條件決定是否再進同一段關卡，且按每次實際訪問正確處理生怪、機關與獎勵。

## 本機來源核對

基準為Server afd76dd及本批條件出口增量，原生檔未新增分析。
LocalScenarioInstance仍以Node定位，拒絕來源圖cycle；旗標為單場集合，
權重／條件選擇歷史目前以node為key。固定prefix編譯器用不同logical node及
visit-local旗標避開重複身分，最後一輪保留canonical旗標給後段主線。
不能直接刪掉cycle檢查，否則現有路徑／經驗遞迴亦無法終止。

LocalScenarioGateConsumption與SQLite機關ledger主鍵包含
account/run/node/interaction，沒有訪次；同一run重回相同node會被視為已扣過。
StageOne擊倒經驗則累計實際combat增量，每次提交後換credit Guid，並不是
依node去重；需保留這個實際行為，不能憑假設另加按node一次的獎勵限制。
最終結算仍依mission run，須保持每場一次。現有換圖會清理combat並累計
拾取／擊倒EXP，owner continuity已包含HP/SP/MP、冷卻與增益，不能重做為新功能。

## 必要實作順序

1. 建立不可混淆的run／節點訪次身分。每次Enter產生Server自有visit識別，
   fork只複製，不自行增加；真正採用的轉移才建立下次訪問。wire chart/map仍
   使用原定義，不把visit編號塞進Client opcode。診斷／路線摘要保留兩種身分。
2. 機關領域操作／receipt／SQLite主鍵加入訪次，新schema以版本化遷移保留舊記錄。
   舊無循環V1路線仍映射舊語意；每訪正常各扣一次，不允許借用上一訪receipt。
3. 旗標及選擇改為明確Run或Visit作用域。Visit producer在重新入段時重啟，
   Run producer按已提交事實保留；當場停止條件不能因重啟清除，出口及頭目條件
   又不能沿用上一輪的成功。波次、hold／delay、屏障、危險區與選擇快照均受訪次
   管理，投射物／actor仍走既有換圖清理。保留跨圖資源與背包。
4. 才加入有顯式上限的結構化loop定義及body/header/latch/exit邊界；分析SCC與
   必達結果、可達條件、最大獎勵，不能在有環圖沿用DAG遞迴。條件出口原語提供
   在指定邊界讀取權威旗標並固定本次決定；不能改用測試者指定第幾輪停止。
   巢狀／跨body跳轉需明確schema與驗證，未知情形不得默默退回固定路線。
5. 正常入口adapter必須可重回同chart/map，重新安裝波次與點位；每次實際擊倒、
   掉落、拾取、機關成本及清組獎勵正確，mission completion僅一次。
6. 最後接Admin規則／迴圈預覽、保存／配套匯出及隔離Host預檢；不能只做圖形
   表單而沒有完整執行器。現有單房／兩房固定展開仍保留作獨立功能及控制組。

## 通關驗收

用同一份副本，由正常背包／機關／任務事實分別讓條件提前成立及到上限仍未
成立；真正在執行中決定不同訪次數。走正常login／party／village選關，逐訪
核對怪物、旗標、成本、掉落與累計EXP，結算一次並保存回原村同隊。測試預期
可指定，但不能把停止輪數直接注入生產runtime。準備角色TCP與指定v2／自然
新帳號／獨立Host遊戲驗收分開。重送、重登續關、並發、故障及壓測仍不執行，
保留待測清單；不得因只跑正流程就宣告它們通過。
