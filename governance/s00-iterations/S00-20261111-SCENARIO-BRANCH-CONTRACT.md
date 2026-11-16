# S00：副本分支出口資料與執行契約

這是Server自訂Scenario圖，NOT_NATIVE_MEF；不要求官方MEF復原，不新增Client opcode。
節點原portal與InteractZ rule保留作預設出口；可選alternativeExits最多7個，
每項明示portal、action（NextNode或Result）、targetNode（NextNode必填、Result無）。
單節點最多8出口，key在節點內唯一。每出口中心／半徑有限、半徑為正、key非0。

每definition最多256節點；驗證器遍歷所有預設與替代邊，禁止環與不存在的目標，
要求全部定義由entry可達。每節點至少有合法預設出口，故有限無環圖每條路都到Result。
入口／清組／按Z三種事件仍明示，不加入任意程式或隱含支線／任務授權。

## 選擇與游標

世界層沿用已知互動報告的出口key並核對Server目前位置；故事路由收到同一
key與位置，再由共用實例驗證。不得將替代出口換成預設出口中心。
有key時只可選該key且必須在其半徑內；通用實例無key呼叫則選範圍內最近出口，
距離相同選較小key，因此重疊圓有確定規則。這不是Client自主路線選擇分析。

動作帶ExitKey，實例保存LastExitKey供診斷；進入目標前先關閉PortalUnlocked。
故事規劃在Fork上進行，未提交前保留原游標；提交後才發布已選分支與下一節點。
分支游標只在副本實例內，正常主線保存仍遵守既有已完成前綴與交易，不記戰鬥中途。

## 一般故事資料接線

每個story scenario node可選exitRule（完整InteractZ rule）覆寫預設線性出口，
以及alternativeExits。故事中的targetNode是該scenario陣列的1-based位置，
不是原生SourceNode或map ID。省略新欄位時保持既有線性順序。
所有出口在載入時檢查BND中心；這不保證整個圓、到出口走道或Client動態碰撞。

入圖將全部preRegisterClosed出口放在同一個0027封包登記。0027會替換整份集合，
不得逐出口各送一包；既有來源見S00-20261103-FIELD19-PORTAL-GATE.md。
清怪後若全部都預登記，只逐key送0048開啟；
如有未登記出口，沿用Map／重建策略後以單一0027登記全部已允許出口，避免混用時遺失點。
含ClearScenes的節點仍不允許預登記點，直到場景清除後的點恢復已驗證。
一般故事world會發布並授權全部出口。原固定兩圖保存adapter明確拒絕分支／跳圖，
避免套用通用圖後繞過FirstMapWon／SecondMapWon等既有保存階段。

## 完成界線

本次範圍是明示選出口的有限圖序分支。任務旗標／道具條件、隨機／權重路線、
組隊跨實例協調、原生MEF與Client腳本入口仍另列未完成。
合成測試與實機各自驗收；不為此打斷尚在待回覆的v94增援卡。
公開範例只是作者示範，座標、地圖配置仍須逐圖查驗才能套用正式主線。
