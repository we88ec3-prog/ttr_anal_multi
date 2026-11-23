# Q15 通關後跳過首次到村演出

2026-11-24。SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。接續
[一般主線成功返村跳過](STORY-SUCCESSFUL-RETURN-SKIP.md)，補 Q15 的獨立首次到村狀態機。
指定 v2 的操作、鏡頭與輸入清理仍待人工驗收。

## 正常流程

兩張圖191／192的勝利均已保存、選擇最後出口使 Scenario.Completed=true 且 LastExitKey 存在，
再收到正常結果確認0033，載入Town1／Map182並開始scene3或4後，既有005D/00可以跳過剩餘演出。
必須是已載入、未到村、無待提交橋接階段、非debug／技能實驗，並且有正常廣場前置。
若目錄已有隊伍，仍要求唯一隊員兼owner。不能靠取消請求取得戰鬥勝利。

此操作只規劃既有 ArrivalAuthorized(stage4)，不呼叫場景完成回報、不偽造003F。
由原有 Poll 路徑在租約與stage／角色授權保存成功後，才記住村莊資格、建立一般主線，
並照既有設定建立不公開的一人隊伍。這延續使用者選擇的首次到村政策，
讓NPC與返回廣場可用；不是將尚未通關的放棄作成到村成功。

沒有新增資料表、格式、opcode或專用成功獎勵。stage1～3第一達成歷史保留，
只新增正常stage4紀錄。原有物品保持。正常播放完scene3／4的路徑不變。
開場scene1／2仍有獨立待辦；[未到村戰鬥放棄](QUEST15-ABANDON-RETURN.md)仍不給進村資格。

## 停止演出與回村

在新Town控制器安裝前送出既有合法目的村context `380000010000000000`，
利用已核的CSquare共用0038先嘗試active-Q Stop，再預載Town1。
自動一人隊伍採既有0099/3 Town安裝，該context在0099前送一次；
不建隊的既有69/7／43路徑則在69前送一次，從43後snapshot移除。
沒有把0038當作無副作用的Stop-only消息，也沒有新增清理ACK。

重用[CSquare來源與指定v2窗口比對](STORY-INTRO-ABANDON.md)及
[Town Stop來源](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/town-stop-source.json)。
本輪沒有重新匯入或執行原件；沿用固定SHA的共用處理器證據。
Stop仍有active guard，程式窗口一致不等於實機鏡頭／coroutine／輸入已驗收。
保留成功到村是Server規則，不宣稱恢復官方取消獎勵政策。

## 工程驗證範圍

四個新增HappyPath覆蓋scene3／4，以及有、無首次到村隊伍兩種安裝路徑：
正常兩圖戰鬥與出口、結果確認、規劃stage4後才到村、context先於場景安裝且只送一次，
同一world返回廣場時的前置含14／15／16。

兩條正常TCP與兩個獨立實際時計Host，均從尚未授予Q15階段開始，
正常登入、廣場NPC、本機scene1完成回報、Server scene2、編隊、兩圖戰鬥與結果確認。
對實際未回報的scene3或4送005D，處理第一筆可能的Stop003F，保存stage3→4；
183×3及第一達成歷史保留，正常進入Q117。之後透過NPC完成Q117，再返回廣場，無須重登。
Host的Town0038實際封包早於0099/3且只有一次，停止後的SQL副本讀回stage4、
四筆階段歷史、183×3和QuestIndex1／Npc（Q118）。

預備前置只有教學／物品；Host另預備role4 Lv15。Q15各階段都經正常封包取得，
但不因此宣稱自然全新帳號教學或指定v2實機通過。原始BND與現有任務／經驗配套保持。
初輪scene3僅驗回廣場的收據保留，最終批次另補實際Q117 NPC流程，不混作同一驗收範圍。
工具開發期間的編譯接線與Tuple序列化修正留本機輸出，不調整遊戲規則配合檢查器。

完整收據見 [Q15成功到村跳過](../testing/quest15-successful-return-skip-20261124.receipt.json)。
SHA256 `c68f77d3f4bbd51216d286f9c53bd7c117a63bd12badbc6e17a5a2b695713388`。
三Release零警告／錯誤；822HappyPath全通過，零失敗／略過。現用服務未換版、Client未修改，
原始證據與種子DB保持；沒有執行暫緩的重送／重登／故障／安全／壓測套件。

實機待驗：實際可達的scene3／4取消操作、鏡頭／輸入清理、自動私密一人隊伍、
NPC對話及不重登入返回廣場。Q15開場演出、原生MEF格式及其他副本工作仍各自開放。
