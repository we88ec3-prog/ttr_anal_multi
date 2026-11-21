# 一般狩獵場工作台

2026-11-22：訊號編排新增 [普通任務已交付](QUEST-COMPLETION-SIGNALS.md) 與Quest ID欄位；由既有任務服務只讀Completed，不代交或發獎勵。新版欄位瀏覽器操作仍待驗，JSON／載入／正常TCP路線已有收據。

2026-11-22：一般狩獵場編排新增可選入場權重，取消會移除欄位；同Stage正常Case每場選一次。保存新版本及ZIP不自動部署，詳見 [入場權重契約](HUNTING-ENTRY-WEIGHTS.md)。
此擴充沿用[主線工作台](SCENARIO-WORKBENCH.md)的 JSON 編輯、不可覆寫版本與
匯出流程，新增一般狩獵場的驗證設定。仍為 `NOT_NATIVE_MEF`；不改 Client，
不建立新的原生 Stage／Case，不把編輯成功當成遊戲驗收。

## 內容與來源

[固定範本清單](hunting-workbench-profiles.json)列出 Case 315、693–706，
每份既有 Server 關卡以檔名及 SHA 識別。範本只讀，編輯另存 SQLite 草稿。
啟動時走既有一般狩獵場 reader，核對 Case、圖序與各張原版 BND SHA。
驗證設定的 SHA 包含原範本 SHA、Case／Stage、AI 目錄與已讀 BND 的 SHA；
切換編輯類型不改舊草稿的來源。主線驗證設定的既有 SHA 算法保持不變。

一般狩獵場覆蓋檔只包含該 Case 的一個定義，保留原來源、入口節點、
節點編號、地圖與換圖目標集合。可編輯出生、怪物、AI 引用、增援、訊號、
屏障、掉落與經驗，但仍須通過共用圖／條件檢查、原版 BND 的靜態可達性、
巡邏、必要頭目與結算範圍檢查。一般入口必須保有正的路線經驗。
預覽顯示最短／最長路線與結算經驗，數值是 Server 編排，不是原版公式認定。

關卡工作台不負責物品目錄、掉落入包 metadata、經驗帳本及村莊等全部部署
配套；發布時仍須執行完整 Host 預檢。匯出維持該版本的 UTF-8 位元組與 SHA。

## 管理端與載入

`/admin/scenarios` 可選主線或一般狩獵場驗證設定。從已存草稿開啟時，以其
來源 SHA 選回對應設定；目前未載入的舊設定保留唯讀，不能按另一個 Case 匯出。
保存不發布，匯出不替換目前遊戲 Host。

Admin 設定 `TARTAROS_ADMIN_HUNTING_PROFILES_PATH`、
`TARTAROS_ADMIN_HUNTING_PROFILES_SHA256`、`TARTAROS_ADMIN_HUNTING_SCENARIO_DIRECTORY`，
並沿用 `TARTAROS_ADMIN_SCENARIO_BOUNDS_DIRECTORY`。範本清單與 Server 配套檔
保持相同 SHA，啟動時核對。缺少任何固定來源時不以空白地形替代。

匯出頁提供現行配置的對應鍵：Case 693 為主 Case、695 為另一狩獵場，
694／696／698／700／702／704／706 為同 Stage 的輪替，其餘為額外狩獵場。
設定鍵須配合已啟用 Stage、村莊及正常經驗政策；不是可任意新增 Stage 的入口。

原生 MEF 載入、Lua 編排、Client 本地生怪與 AI 移交仍依既有缺口追查。

後續加入[關卡與怪物 AI 配套](SCENARIO-AI-BUNDLES.md)，一般狩獵場同樣可在
每版保存自訂 AI、重驗引用與巡邏地形，再匯出配對 ZIP；不改 Case／圖序的界線。

## 2026-11-19 驗證

範本清單 SHA 為 `2173bc50eebbc16b037cfbdcbb24396299087a1ce6a48b5f59ae8dca5e901a1d`。
[工程收據](hunting-workbench-validation.json)記錄 17 項針對與完整 HappyPath
623／623 通過，Host／檢查器／管理端 Release 建置零警告、零錯誤。
單元幾何為合成；15 個 Case 的管理端保存／驗證／匯出則使用固定原 BND。
舊主線草稿的 profile SHA 與精確匯出位元組保持相同。

獨立瀏覽器將 Case 693 結算從 20 改為 25 EXP，預覽路線總計由 76 改為 81。
匯出 SHA `296c027550cc19f3fb8a3683d6b0ac8a0276056016e2a5ca1ace4319def56f94`，
純離線 `--stage-one` 檢查使用原 BND，戰鬥／拾取／結算兩次各入帳 81 EXP。
未啟用含離隊／登出分支的 journey 選項，也未宣稱此新範例已完成正常入口
或指定 v2 的實機驗收。

管理端已更新至 16 組設定，四頁 HTTP 200、組件 SHA 與 loopback 核對通過；
遊戲 Host 保留，既有草稿指紋一致，無測試範例移入使用者資料庫。

2026-11-19 補充：[單場正常入口工程驗證](../testing/HUNTING-NORMAL-ROUTE-INSPECTION.md)
已完成基準 37 條、自訂 AI 兩條及 81 EXP 匯出版本兩條，共 41 條。
準備帳號通過廣場建隊至同室回村；並非新帳號主線、TCP 或指定 v2 實機。
