# S00：條件出口實作驗證（v97準備批次）

狀態：Server程式與資料已完成本批驗證；尚未啟用，尚無Client人測結果。
使用者目前無法測試，先累積到[批次測試表](../../design/testing/S00-CONTENT-BATCH-TESTS.md)，不發逐項測試催問。
契約見[typed條件出口](S00-20261111-CONDITIONAL-EXIT-CONTRACT.md)。

- 345個受影響HappyPath通過；新增5個案例涵蓋typed旗標、區域鎖存、分key開關、完整World與測試場正常路線。
- 最新World資源讀值補入後，兩個實際換圖案例再確認施放技能後資源相等延續；不把重跑數量累加成347。
- 跨圖HP/SP/MP、冷卻絕對到期與回復原點沿用已驗證值快照。個人Buff／地面效果仍未在這批繼承。
- typed loader實際讀取公開JSON，兩個出口501／502皆走到結果；第一圖旗標在後圖仍存在。
- 地圖193／194／195所有新出生點、怪物、出口及條件區域中心通過實際BND靜態檢查。
- jsonschema4.23.0標準validator通過新schema本身與目前功能場、v96、v94歷史場及分支示範。
- 網頁JavaScript語法通過；目前線上的v96a保持不動，準備中的v97需日後集中啟用。

資料SHA256 `127df7b301f9b792be6c00892500f383c62de821e9c80074969194f522e7343d`。
Schema SHA256 `a5ed2ab6872d368392a454c092721f8a116537e6b566888e8657c60f58b9a704`，公開與私有副本相同。
舊分支schema另存local-scenario-definition-branch-v1.schema.json，v96場景資料另存functional-lab-v96.scenario.json。

條件已接共享Story與獨立場，正式故事JSON及既有保存階段未更改。BND中心檢查不是完整導航／碰撞證明。
旗標不能憑空從中途節點啟動；需要從instance入口產生，沒有假造前置進度。
機關／NPC互動、任務物品條件、原生MEF、完整Client自主AI、跨圖Buff／地面效果仍有未完成工作。
本批沒有Client修改、遊戲執行／附加，也未執行延期的錯誤／邊界／重送／併發／故障／安全／壓測。
