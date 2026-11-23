# 已通關主線跳過返村演出

2026-11-24。SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC；Server 工程驗證完成，
指定 v2 的實際取消操作、鏡頭及輸入清理仍待驗。自訂 Scenario 保持 **NOT_NATIVE_MEF**。

## 狀態與結算

一般主線已完成最終出口、收到正常結果確認，進入 ReturnScene 後，既有正常離隊請求
`005D/00` 現在表示跳過剩餘返村演出。這是 Server 選擇的規則，不是已證明的官方取消獎勵語意。
與[戰鬥放棄](STORY-ABANDON-RETURN.md)分開：未通關放棄回同一任務 NPC、不給通關獎勵；
本流程保留成功結算，前進下一任務，或抵達路線終點。

條件：正常非 debug、目的村已載入、無待提交轉換、Current.Phase=ReturnScene、
本次 Scenario.Completed=true 且 LastExitKey 存在；目錄中若有隊伍，必須為請求者持有的一人隊伍。
正常封包路徑必須先經 Result 的 `0033` 確認才能抵達 ReturnScene。
新增獨立的 ReturnPresentationSkipped 效果，直接建立既有成功 completion proof，
不呼叫 SceneReported、不偽造 `003F` 成功回報、不將取消當作戰鬥完成證據。

沿用既有租約、revision 及 ScenarioCompletion 交易驗證，提交下一任務／目的村、固定任務經驗、
Scenario 經驗和 mastery。交易成功後才清除 instance、關閉一人隊伍並送既有 `0089/00`。
回村仍用既有背包預備／裝備恢復及 wallet 發布路徑，沒有新增資料庫或封包格式。

## 演出停止與來源界線

返村已是 CSquare 場景，沿用既有合法目的村 `0038` context，在 `0069/7` 場景替換前送出；
載入 `0043` 後不再重送該 context。它會先嘗試 active-Q Stop 並預載目的村，
不是沒有副作用的 Stop-only 封包。Stop 可能產生的第一筆正常 `003F` 在載入等待期間被抑制，
不作為清理確認或第二筆結算。保留普通演出完成後回村的既有路徑。

重用[Intro 的 CSquare／指定 v2 比對](STORY-INTRO-ABANDON.md)及
[Town Stop 證據](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/town-stop-source.json)。
本輪不重新匯入／執行 Client；收據固定三份既有證據 SHA。原生 Stop 有 active guard，
函式窗口相同不能取代指定 v2 操作驗收，也不能證明官方 Server 採本結算規則。

## 驗證

[工程收據](../testing/story-successful-return-skip-20261124.receipt.json)，SHA256
`922a8d90e0b3358d9b573fe10d5466d61e4e5ba289570b84ac53acb003d7a0c3`。

- 三個 Release 建置：Host、檢查器、Admin，零警告／錯誤；818 HappyPath 全通過。
- 新 domain 正流程比較 Q119／Q132 演出正常完成與跳過的 completion proof、目的村及下一任務／Goal；
  plan 階段不提前修改 current，commit 才清除 Scenario。Q132 覆蓋 Town2／路線終點，僅 domain 證據。
- 四條 Q119 TCP：正常與跳過各走 stop／cap，獎勵收據逐欄一致，每次一筆 Q119 結算。
  stop 四房13怪52 EXP；cap 八房23怪92 EXP；各加 5,880 EXP（固定5,850＋Scenario30），
  總計5,932／5,972 EXP、mastery40。普通完成保留原隊伍，跳過依離隊意圖清隊。
- 兩個獨立實際時鐘 Host：正常登入、建隊、Q117／118 NPC、Q119 編隊／戰鬥／結果確認，
  留下實際 scene5 未報，再送正常離隊、可能的 Stop report 及載入完成；均回 Map182，Q120 開放。
  目的村 context 順序與唯一性、隊伍目錄清理、5,932／5,972 EXP 及一筆結算都通過。
- 停止各自 Host 後，在資料庫／journal 副本讀回：EXP44,932／44,972、Q119獎勵5,880／mastery40、
  QuestIndex3／Npc／Town1。證據 DB、journal 及種子 SHA 保持；沒有故障注入或備份還原套件。

TCP 預備教學／Q15、採預設起始 EXP 和測試時鐘；Host 預備教學／Q15／role4 Lv15，
其後正常登入／封包操作。這不取代自然全新帳號或指定 v2 驗收。
原始 structured-loop 配套的 cap 為92擊倒經驗，不能套用別配套104經驗／總5,984的基準。
初次稽核誤套該基準的輸出留存，已修正稽核；Server 無須因錯誤期待值改動。

實機待驗：scene5 期間正常可達的離隊操作、鏡頭／角色／輸入清理、實際獎勵與背包、
不重登入接 Q120。Q15 活躍演出、原生 MEF 格式及其餘副本仍有各自待辦。
現用服務、Client 原件／配套未修改；非正流程套件仍暫緩。
