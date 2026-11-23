# Q15 開場取消後正常重開

2026-11-24。SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。接續
[Q15成功到村演出跳過](QUEST15-SUCCESSFUL-RETURN-SKIP.md)，補尚未編隊、尚未開始戰鬥的開場。
指定v2的實際取消按鈕、演出與鏡頭／輸入清理仍待人工驗收。

## 狀態與保存

已收到正常廣場NPC10338互動意圖，尚未完成編隊，且本次scene2尚未開始或仍等待完成時，
可以接受既有005D/00取消。要求已載入、有正常教學廣場前置、未解鎖Town1、無待提交橋接階段、
非debug／技能實驗；若目錄存在隊伍，仍必須是請求者持有的唯一隊員房間。
scene1沿用既有Client本機演出約定；收到其正常完成回報後才由Server送scene2的0047。
本批沒有替scene1偽造Server0047或宣稱已觀察到Client實際播放。

開場本身不建立Q15階段。取消不寫Accepted、不重設先前嘗試的游標或審計、不授予stage4或主線獎勵。
清除本次NPC意圖／演出等待狀態，重建有教學14／16前置的廣場並保留物品與普通任務日誌。
隨後可在同一連線重新對話，經scene1回報、實際scene2、編隊、兩圖勝利／出口、結果與到村演出，
才由正常保存流程取得stage1～4。編隊視窗已開的情況不包含在本取消階段。

## 廣場 context 與停止順序

重用已有的9-byte廣場候選context `380000050000000000`，移到69/7建立新CSquare之前；
43後的廣場snapshot不再重送。BeginSquareTransition與43結束時重設一次性標記，
普通廣場轉換仍保持原先context順序。停止可能產生的第一筆正常003F在載入期間不會開始scene2。
沒有新Stop-only opcode或清理ACK。

共用0038／CSquare的active-Q Stop與目的地預載證據沿用
[Intro來源](STORY-INTRO-ABANDON.md)及
[Town Stop來源](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/town-stop-source.json)。
**Town5和設定的廣場圖511（TCP）／1088（Host）仍是既有Server候選配對，官方Town5映射未證實。**
移動既有context的順序不能提升其參數為原生事實；Stop有active guard，也不等於Client畫面已清乾淨。
指定v2實際結果與原生MEF容器沒有由本工程批次代替。

## 工程驗證

兩個新增domain正流程覆蓋scene1／2：取消回廣場、context早於69且只送一次、14／16前置、
沒有進村資格或待提交階段；正常NPC重開後可取得Server scene2。
兩條TCP與兩個獨立實際時計Host都從零Q15階段開始，取消前後stage列與第一達成歷史皆為零，
183×3保持；再正常NPC／編隊完成191／192、結果及到村演出，才保存stage4。
Host停止後以DB／journal副本讀回stage4、四筆階段歷史及183×3，原證據和種子SHA保持。

預備教學／物品，Host另預備role4 Lv15；不是自然全新帳號教學驗收。
本批測的是第一次開場取消；先前戰鬥取消後再開場的持久化組合、重登／重送／故障等未執行。
這不改既有游標／審計保留程式，也不刪除原有測試。

完整收據見 [Q15開場取消](../testing/quest15-intro-abandon-20261124.receipt.json)。
SHA256 `3fc2979fd05b9455ef54922edfea88310069d88b5792082e42e5f5082eec79db`。
三Release零警告／錯誤；824HappyPath全通過，零失敗／略過。
現用服務未換版，Client與原始資源未修改；非正流程套件仍暫緩。
Q15四段演出的Server正常中斷／成功保留已有分批工程證據，仍不能整體標記實機通過。
原生MEF、其他副本與指定v2驗收繼續列為未完成。
