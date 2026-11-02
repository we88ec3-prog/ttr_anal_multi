# S00：v13三項正常流程修正候選

依[v12人測與保存核對](S00-20261103-PHINDOS-V12-HUMAN-RESULT.md)實作。
到達馮德斯／村內人物NPC與移動停止、換場畫面可見已有人測；三個缺陷仍須驗收修正版。

## NPC對話與第二段劇情

[原件九窗口／46項核對](S00-20261103-PHINDOS-ACCEPTANCE-UI.md)證明40/status0
排F438B，會建立接取對話呈現，不是無視窗ACK。從15/1→15/2交接移除40，只保留
有NPC意圖、已發布前置及預期scene的47。保存Accepted仍在實際28編隊確認之後，
不另捏造靜默Quest接取狀態或以固定sleep掩蓋UI時序。真Client重疊是否消失待測。

## 清怪後等待玩家進入出口

[原件傳送點介面](S00-20261103-FIELD19-PORTAL-GATE.md)補上27/category0、
enable1／automatic1的效果與觸發，及1C(category0,key)踩入回報。
每圖Server真實戰鬥完成／死亡演出與win保存後，只顯示傳送點、留在原圖可走動。
Server核對該圖已保存勝利、目前key、角色所有權及當前自身pose後，才切第二圖或22結果。
1C前更新monotonic Server pose，不能拿上一筆輸入位置或Client送來的XY作授權。

候選位置430/385及391/369、key1/2各對應本連線目前node，非原版MEF佈點／Map ID。
本實作wire radius6，原生effective radius4.8；Server gate6含1.2重建同步容差。
來源工具的radius5/effective4範例只是參數例，與本實作半徑取值分開。
每圖27完整替換目前checkpoint集合；換圖reset清舊集合。不改教學專用14副本的既有返回路線。

## 走路後連按Z

攻擊鍵或casting存在時，Server不把舊walking bit當持續走路意圖，也不讓它清掉連段buffer。
首次從走路轉攻擊先同步movement停止／idle／當前Server位置，再發攻擊；回復期間不自動
恢復先前步行。新方向移動及受傷後的移動恢復保持原有路徑。這是重建輸入政策，不稱原版
取消窗口或所有角色連段已還原。

## 驗證與人測界線

27項Category=HappyPath通過、0失敗／略過（15秒）。既有完整新帳號TCP旅程擴充：
走路後以帶cached move bit的Z立刻停在Server位置、清四怪只開portal、正常走入／送1C後
才下一圖／結果、返回村落與保存四階段。另補核對27的20B欄位、category0/enable1、
radius6、自動1／aux0，僅重跑新增正常旅程1項通過（4秒）。無暫緩異常測試。
實際對話無重疊、傳送圈可見與走入、移動轉攻擊手感仍需v13人測。

版本預設OFF／隔離本機模式、單人僅一角色1/3/4、三角色跟隨與蘋果出戰未完成、
MEF／官方波次與勝利規則未知、Quest15未標原生完成／未發獎、117後續未實作等界線不變。
Client原件與工作副本均未修改；這不是原始BIN的驗收或正式規格批准。
