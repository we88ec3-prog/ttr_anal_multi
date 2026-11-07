# v37：修正氣散發循環造成輸入鎖定

## 人測退回

使用者v36／v7測試回覆「無法移動且無法施放技能」，先前95項合成通過保留，但不能當實機成功。之後使用者要求暫停並重開機，2026-11-08再要求繼續。重開後本任務Host未在執行。
v36 trace最後input12為flags128，回覆有000D motion19，後無後續input；不將此解讀成使用者沒有放開V，亦不冒稱取得其實際按鍵狀態。

## 原因與精確修正

[限定原生證據](../client-variants/20261108-force-state-v37/README.md)識別CForceState為FSM12，其OnEnter直接播放motion19且保留操作旗標。先前直接000D(motion19)經4C8A90會先切SkillState13；搭配循環動畫及Server long.MaxValue，可能關閉產生release的collector，雙方互等。
改以既有000C(entity,12)進入原生ForceState，再以000C(entity,1)離開。保留v36長按期間row2候選、成功施放即回基礎／保留動畫與CD，以及同包release＋攻擊處理。
ForceState12與技能charge-tier2是兩個不同域，不以狀態發現升格圖示切組為官方事實。未改Client，未解鎖87項未決技能。

## 驗證與部署

95項Category=HappyPath通過50秒、0失敗／略過；九角色長按測試改為驗證000C狀態12且不送000D，不能維持原來錯誤封包斷言只求綠燈。新的狀態入口仍需使用者實機驗證。S00需求來源與部署回執後補。
