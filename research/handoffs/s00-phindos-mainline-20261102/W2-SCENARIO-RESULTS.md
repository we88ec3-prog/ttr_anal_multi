# W2：馮德斯一般副本入場、編隊、進度、結果及返回

指定extra/roy2。先讀[總卡](README.md)，沿既有授權分析分支；不覆寫舊T03登入原稿，
也不自行更動T14/T07 owner。可跨查來源但要保留主責與限定，不因分類而停掉可做的查證。

1. 首批聚焦進村橋接：Quest15／Field19／Case103／CHART_S_pathofpindus_01／Map191/192。
   原Case預載key不能拿Field或Quest代填；004E與0028 token先以原樣echo介面表示，不猜同域。
2. 一般Scenario的005F/type2、kind3 controller、0038 type2/6、實體0012／reset／actor bind／14
   的正向正常偏序；0040/003C等Quest意圖與0047 scene入口分開。填寫每個欄位與消費者、下限、
   未知及必要前置；同一數字在不同opcode／方向不能合併。
3. 檢查地圖節點1→2的切換觸發、Server進度與終端證據。重點為消息／場景／控制流程；
   核心MEF格式、AI與連段由S00查，無資料時明列依賴，不另造全清勝利／秒數觸發。
4. 舊來源提及0022/type0→SCED結果頁，C2S0033無目的地返回；重核完整可用欄位、UI／
   controller清理、Quest15/3與回廣場／進村觸發；不可套教學專用004C或Raid type9。
5. 再做村內候選主線118/132的Field28、119的26、122的27、124的17之Case/Chart/Map入口
   索引與差異。角色／編隊約束與token是Server待決策時須明示，不從ID相同硬推。

交付phase→C2S／S2C→domain狀態→資源→正常達成／返回的矩陣及可直接實作的有限契約，
先交Field19最小批次，再延伸其他field。新增W2-RESULT報告及必要機讀資料，Commit／Push後回
commit／blob SHA。原件唯讀，不執行Client／Server，不跑負向／故障／重入等暫緩測試。
