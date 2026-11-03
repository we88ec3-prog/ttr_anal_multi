# S00：NPC本地劇情啟動與C2S1C／3F的方向界線

接續[Quest15事件／碰撞](S00-20261102-PHINDOS-SEQUENCES-AND-BOUNDS.md)，
本輪核對原KR BIN而非執行Client。目標SHA仍為
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
[可重跑工具](../inspect_scene_notification_order.py)／
[兩個完整指令視窗、13個assert與source-shaped例子](evidence/S00-20261102-SCENE-NOTIFICATION-ORDER.json)。
有限basic block核對，不是整份函式或官方Server往返FULL-PASS。

## 先本地呼叫，再通知Server

NPC事件helper `5B9340` 的其中一條事件分支，保存Ghidra可見先經`5008B0`取得候選key，
再呼叫`561760`，最後將來源event欄位組成C2S1C。
本輪原始bytes窗口自**5B943F basic block**起（不是新函式入口）：

- 5B943F push1、5B9441 push edi、5B9442選FB73C0，5B9447 call561760。
- 5B9453選命令1C；5B945C/64讀event物件+18/+1C兩個WORD並放入連續目的位置。
- 5B947D push6，5B9485 call sender，並受既有FBA798分支限制。

因此這條分支**不是單純先送1C、等待Server播放ACK才開始本地劇情**。
不代表全部NPC都走此分支，也不證明兩個event欄位必然等於Quest／scene或某個NPC ID。
Server後續仍需依合法前置與實際事件內容維護狀態；不能猜一個通用ACK來解凍。

## 劇情manager與回報值的限制

保存反編譯來源重新讀取：

| 函式 | 偽碼SHA256 | 本輪用途 |
| --- | --- | --- |
| 560170 | 424fa1bb1b48dfea3347cd4909a0e8fa22cee43250072426c38e97f3838f2da0 | FB73C0 manager初始化並呼叫5607D0 |
| 5607D0 | caf4b4f2ed2af64abcf7ca484a934f55ea90cb95e15155e1c7b8c6be4b08d73f | SCENESET／SCENE及questIdx等欄位載入 |
| 561760 | ac9f0289161abfd668cdd1a38a95bd680f6f9519bb207f0c2146450454859606 | 保存兩個輸入於+38/+3C並查場景；查無紀錄可走561DB0 |
| 561DB0 | a33c6fd3d88db3bdc680c131c5eaae9a0cbcd44773c7bc4dcd5dc9d37c1077ff | 結束／清理路線有4A39A0；另有確認與下一段分支，未全域證成固定Server順序 |
| 565720 | 89b9db20b93a36dcefeb4cf67e469e3350bc5356d12b7210e2c332a2186b4916 | 另一種場景啟動，組Event/Sequences路徑；不是新wire ACK |
| 4A39A0 | 67bc2d4e1bf948c7c0359f67f99674a523f495adfbd8a8495894277463fb0568 | 8B C2S3F producer |

bulk原始Evidence／偽碼可從既有kr-bulk-roy lookup依位址追溯，並不把上述選讀當所有helper語意驗收。
4A39A0原始bytes證實：命令WORD3F、WORD參數1、WORD參數2、WORD literal1，送8B／slot0。
查無場景也可能到清理／回報鏈，所以value1不是正常演出成功或任務完成證明。
既有教學出口還需本connection的Server勝利／返回、自有角色與有序事件，未移除任何前置。

## 私有Server採用與仍缺功能

新增KrSceneReportCandidateProtocol與明確QuestKey／SceneKey／ReportValue記錄，
接入教學出口判定及post-battle metadata，取代這兩處流程重複的WORD位移讀取。
不提供Succeeded屬性、不自動完成任務、不接未知NPC intent、不傳猜測的scene ACK。
現有25個HappyPath案例通過，包含正常首戰、招募、廣場及有序出口；未執行暫緩測試。
這是協定欄位解析與既有路徑整理，尚未發布新Host，也不是已完成馮德斯進村功能。

下一個必要開發點：讓廣場NPC候選key來自合法已提交的前置／任務狀態，
追清楚15/1結束後的下一步排程與一般Town1切入。不能單憑3F literal1，
也不能從本地呼叫先於1C就推論Server不必處理任何任務／換場通知。
Quest結算／獎勵、正常Town scene/controller與spawn仍未閉合。MEF／AI未知界線不變。
