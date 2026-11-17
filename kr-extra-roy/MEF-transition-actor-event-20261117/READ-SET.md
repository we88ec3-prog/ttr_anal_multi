# 本輪已查範圍與沒有擴張的邊界

## 新增原件／連接

- common註冊prefix4ADD50..4ADDF4，0008/000A/000C/000D/000E地址與slot；不是重解全部dispatcher。
- 4AF530完整0008 producer與4AF920完整000A consumer；raw欄位→record及缺資料時序。
- 4A0B80、4A0C50、4A0D10完整world外觀wrapper；7A6EA0完整avatar選擇。CDoll worker/apply/render沿用R11，不把其全callee樹當本輪新驗。
- 436C40虛分派、Mission/Scenario v+28；4C4920完整Scenario wrapper；436B70另一完整wrapper，但未給其新場景上游。
- 4B0640只讀身分前綴到4B087A；其餘傷害／UI／效果沒有本輪完整分析聲明。
- 548DA0及CAIControl RTTI；54A8F0完整writer；4C96B0完整條件predicate；54AA60完整reader與獨立switch data。549686/549C94只查實際call／返回使用prefix，不重做SubAI決策主責。
- 4B01C0完整選定000D producer及501650完整00DF builder；不分析所有00DF caller，不冒稱死亡／群清語意。
- 121正式名稱的既有surface只比較四個native target是否直接註冊；沒有把此比較當全Client不存在間接API的證明。

## 新讀／重核資源

原Table.stp的_MapList、_CaseList、_ActorList、_PortalList；原Event/SceneList；BoundMap兩份scenario_pathofpindus01/02。只有Portal結構是新缺件排除、typed model對照與候選取樣為本題補證；原Map/Case/BND基本身分直接復用。

公開的Case103 MapChart、Cluster在固定歷史commit完整讀取；Field.stp本體未重取。舊Library scenario-resource-facts／source-index／quest15候選檔用來定位上述原始公開來源，不作官服配置或可部署策略。沒有公開這些整份Library檔。

## 明確未使用／未完成

未執行或修改Client/Lua/Server；未分析私有Server實作；未匯出完整遊戲資源；未改共享owner、派工／驗收狀態。未授予候選spawn正式許可；沒有挑定實際worldID、avatar variant或session；沒有替官方MEF編造語法或傳檔opcode。

精確阻塞是來源／資料流而不是「研究時間到了」：轉場profile缺實際部署資料；avatar缺descriptor與當次typed identity；普通事件已到native reader但沒有合法Lua橋。下一入口見NEXT-ANALYSIS，已排除的路線不重掃。
