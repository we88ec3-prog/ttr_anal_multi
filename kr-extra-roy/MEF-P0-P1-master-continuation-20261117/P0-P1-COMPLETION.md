# P0／P1 完成判定

本表逐項對應固定基準的[原 ANALYSIS-PLAN](../MEF-comprehensive-contracts-20261117/ANALYSIS-PLAN.md)。使用者要求完成 P0 並繼續 P1，因此本輪先處理新 Master 能解除的來源／loader 缺邊，再完成四項 P1 續析；不會因目標要求「閉合」便把缺少原件或尚無正向入口的項目改成已證。

## 1. P0

| 原工作包 | 本輪完成 | 保留的驗收邊界 |
|---|---|---|
| 採用勘誤與 ABI | 原121 binding／33 marshaller、15項勘誤、75 helpers及既有分析器重新驗證；原件與固定來源一致 | 這是內容工具的研究契約；不聲稱 Server 已整合全部功能 |
| 內容真實依賴 | 新 Master 全899 members、897 AttachedPackage 與897 PackingRules逐一join；原132依賴node重新接路由；補實際EMF／ETF consumer與條件 | **掛載宣告缺口已閉合，整體payload／選取／ready尚未閉合**。108原前緣仍被原件或實際context阻擋，13個descriptor缺件未變 |
| 執行與收尾契約 | 22 owners、20 cleanup edges、3 run profiles重跑；保持Q immediate1、圖片替換／零fadeout、資源強持有與各自收尾界線 | 實際各owner完成、渲染、回城控制與遊玩沒有因靜態重跑完成；003F／00EB不升為總ACK |

三項 P0 的**本輪分析與整合處置均完成**。其中資源工作包仍有真實來源／選取條件未滿足，故 `all_p0_readiness_gates_closed=false`、`resource_ready=false`。17筆舊「缺 Master」敘述由新增來源取代，沒有刪改舊發布歷史或把108個原前緣都當成Master問題。[Master差異](master-resource-closure/p0-frontier-delta.json)、[重跑ABI](baseline-replay/abi.json)、[重跑生命期](baseline-replay/lifecycle.json)

## 2. P1：四項均已續析

| 原工作包 | 分析交付 | 功能／遊玩判定 |
|---|---|---|
| 第一個完整正常旅程 | Q119前置→5原SEQ→4普通節點→結果→119/5返回→Q120資格；10步、176 body calls、54 Talk rows、7 camera members、4真BND | `ANALYZED_WITH_EXACT_RESOURCE_FRONTIERS`；未執行或驗收完整旅程 |
| 擴充所有功能族 | 原規劃的相機、聲音、圖片、書本／教學、world NPC／服務、互動點、場景／小地圖，7/7各有實際資料與取得／退出契約 | `ANALYZED_7_OF_7`；這是七族至少一例，不能泛化為所有內容或任意組合皆可用 |
| 不中斷普通場景首次入口 B | 正常Mission／Scenario typed receiver安裝、Rebind、指定全域writer、繼承XML reader／clone及Master新來源，5候選已裁決 | `NOT_CLOSED`。仍缺首次content load／execute、同VM持續pump、owner取消／重入的完整鏈 |
| world結果到Lua出口 | 0000比例／0034絕對HP/SP/MP／000E視覺記錄、真正HUD／AI／tick／draw consumers，接死亡FSM與erase | `NOT_CLOSED_NO_PROVEN_ENDPOINT`。尚無同run、actor generation及事件身分的registered Lua出口 |

分題報告：[正常旅程及七族](journey-families/REPORT.md)、[B入口](entry-b/report.md)、[world→Lua](world-lua/report.md)。`p1_analysis_packages_completed=4` 不等於四種能力驗收通過。沒有將「未找到正向鏈」寫成全程式不存在，也不要求Server業務等待這兩個Client缺邊。

## 3. 解除剩餘 gate 的最小證據

| Gate | 所需證據 |
|---|---|
| 資源／選取 | 同版 `fcs.flu` 或實際cache-miss選取記錄、category Base／selected avatar、真正FLD／texture／音訊／UI載體，按native次序確定winner後展開後代 |
| B入口 | 具體ordinary事件caller→typed owner→首次本次content load/execute→同VM後續pump；明確保留普通field/input與取消重入 |
| world→Lua | world producer→具生命期關聯storage/bridge→registered callback/getter typed payload→同VM/coroutine consumer |
| 官方MEF格式（原P2） | 真實 `.mef` 正例及消費它的parser/executor；Field規則或副檔名本身不能通過 |
| Server與遊玩 | 實作／serializer／持久化證據，再依專案允許流程驗收正常NPC→戰鬥／出口→結果→返回與後續資格 |

具體補件與可並行開發分別見[SOURCE-REQUEST](SOURCE-REQUEST.md)、[SERVER-HANDOFF](SERVER-HANDOFF.md)。正式驗收與研究完成旗標未變。
