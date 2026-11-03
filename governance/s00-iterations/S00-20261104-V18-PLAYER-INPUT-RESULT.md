# S00 — v18 玩家輸入回報（2026-11-04）

使用者操作指定工作副本，回覆 v18 測試卡：「目前每走幾步路會抖動一下，請按Z仍然無法移動」。依測試卡上下文記為方向＋連點Z仍不能移動；不擅自補成按鍵時間的精確標註。使用者先前已授權本機正常輸入取證及Server修正；未操作／修改Client。

## 保存紀錄與界線

已停止的 v18 journal 保存為本機 v18-player-movement-jitter-evidence.jsonl，SHA256 4257b0eefe18f4dd6181ae024ce596616ef4bc502f8612ed684eb9a26f1cdaf0。共833筆，324個input、509個Server Send；時間2026-11-03T17:32:29.8420513Z至17:34:34.5506208Z。來源Server a3478089164d24eeaec75839ee5c5b86cb36aad7，v19於17:34:41Z啟用，回報不能套成v19人測。

input分類：flags0=148、0x8000=88、1=87、2=1；所保存的action-only rows沒有moving bit。outbound command11=165、12=154、DA=100、16=69、0E=12、0D=9。原始時間與回覆關聯保留在本機，不將登入／帳密或其他任意payload放進公庫。

目前world policy仍由0x8000計算movement report，action-only會令moving=false並可能送stop/idle/Server position；它不是完整物理按鍵解碼。實際同時按住方向仍可能產生action-only，因此不能靠此資料宣稱方向已放開。Server pose30 units/sec以及stop時位置回校亦是候選政策，可能影響抖動，但尚未證明具體因果；不得把消除position、延長hold或Z強停當成已驗證修法。

## 待修正／驗收

移動抖動與方向＋Z維持OPEN。需結合原生controller／action queue／state-machine及時間關聯，找出合法的movement/action共存與位置同步方式，確保方向釋放能停、持續按方向＋Z能走、同方向重按恢復。保留未知輸入組合，不猜成其他技能。新旅程v19不宣稱修復此問題，也不為這筆回報反覆換版。真人測試暫停重複取證，先分析現有紀錄。
