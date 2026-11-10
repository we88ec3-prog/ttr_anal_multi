# S00：固定路段的Client執行比較契約

## 目的及來源

使用者本階段目標是完成關卡／MEF功能開發，不等待官方格式復原。
沿用獨立schema／副檔名、NOT_NATIVE_MEF，不虛構原生檔案或傳輸opcode。
本契約接續[既有操作接手證據](../client-variants/20261109-mef-town-services/scenario-controls.md)：
KR handler4B2730，既有actor接到0018終點／更新步數，CMonster可執行中間步進。
此處重用已發表有限證據，不新增原件反組譯FULL-PASS主張。

## 最小wire契約

Application payload，不含既有transport frame。多位元組皆little-endian。

|偏移|型別|意義|
|---|---|---|
|0|u16|0018|
|2|u16|已建立的EntityId，不是模型ID或group ID|
|4|f32|目標X|
|8|f32|目標Y|
|12|u16|更新步數，不能當毫秒或秒|

單列14B；consumer按(len−2)/12讀列。本版僅實作明確單列。
來源樣例entity257、target422/385、steps4：
`18 00 01 01 00 00 d3 43 00 80 c0 43 04 00`。
沒有已證完成ACK；碰撞會消耗步數，末端處理與中斷仍待實機。

## 本機比較模式

|項目|行為與界線|
|---|---|
|入口|沿用loopback測試頁，SkillLab、role4、matrix0、tier0、level1、energy1000、targets=ClientRoute|
|內容身份|LOCAL_CLIENT_ROUTE_COMPARISON_V1_NOT_NATIVE_MEF，記錄scenario與route SHA|
|配置|node1第一個encounter的模型／出生點；目標X−4、Y不變，四分之一單位靜態地形預檢|
|物件身份|沿用Server自訂entity257，與player256不同；沒有另建邏輯戰鬥怪|
|套用|只重建比較場與生成靜止怪，不送0018、不自動播放|
|啟動|回遊戲按Z，開始訊息000B／000C後只送一次0018|
|步數|120更新步，僅為方便觀察的測試選擇；不推定與秒數對應|
|途中|Server不補該怪0016／000B、不作末端校正，沒有計時器宣告完成|
|戰鬥|該物件不加入Server敵人集合，不尋敵、不受Server技能傷害、不產生勝利或獎勵|
|重做／離開|重新套用讓既有Map bootstrap清理；切其他測試模式清掉route診斷|
|觀測|status區別READY與TARGET_SENT_AWAITING_HUMAN_OBSERVATION_NO_COMPLETION_ACK；不是抵達確認|

測試場只保留玩家方向移動和Z啟動；不在這個模式施放一般技能。
目前不做一般戰鬥位置同步，因為缺少可驗證的途中位置與完成回報。
不能把Server仍知道起點／目標當成知道Client當下位置。

## 驗證與接續

路段配置使用獨立JSON及JSON Schema：
`LOCAL_CLIENT_ROUTE_DEFINITION_V1_NOT_NATIVE_MEF`，`nativeMef=false`，
`authority=SERVER_RECONSTRUCTION_NOT_NATIVE_MEF`。欄位包含scenarioId、node、map、
encounterIndex、targetOffset、updateSteps、nativeMovementSpeed與requireClearPath。
上表是預設值，不是不可調整的原生常數。Host可由
`TARTAROS_LOCAL_CLIENT_ROUTE_PATH`與`TARTAROS_LOCAL_CLIENT_ROUTE_SHA256`
讀取固定SHA的絕對路徑JSON；未指定則使用嵌入版本。準備場景時核對關卡身份、
出生索引與地形，診斷公開實際內容SHA。這不是向Client傳送JSON／MEF。

308項受影響HappyPath合成測試通過，包括外部內容替換偏移／步數／速度；
不代表下列實機觀察通過。

Server實作提交：私有`ttr_server_roy` main `5214685`；Host Release建置0警告／0錯誤。
這是v89準備成果，尚未啟用；本輪維持v88，不把準備版寫為實機通過。

後續啟用紀錄：本功能已隨v90整批啟用，v89未單獨換版。
瀏覽器已確認準備區及無連線時的停用狀態；已發出新的路段觀察卡。
尚未收到Client移動／末端狀態回報，不變更實機待驗結論。

工程：來源向量逐byte、套用不發目標、遊戲Z一次目標、後續Poll不補怪物座標／動作、
不發命中／勝利、過再久也不偽造完成、切模式解除。Outbound trace納入固定長度0018，
沿用SERVER_SEND_COMPLETED_NOT_CLIENT_ACK語意；另納入出口0048。

實機：先直線觀察位移、起停／面向；再對已明確定義的牆旁路段、打斷與末端做比較。
來源欄位、工程正常結果、實際Client接手分開記錄。不由這一項外推完整怪物自主AI。

後續將已驗操作納入typed關卡action：固定路線、停止／改目標、事件與共享狀態提交。
缺少途中位置時不直接切進有命中判定的正常AI，不用Server校正製造表面成功。
