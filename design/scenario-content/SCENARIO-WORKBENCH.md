# Server 關卡編輯工作台

此工作台編輯 `LOCAL_SCENARIO_DEFINITION_V1_NOT_NATIVE_MEF`，不是原生 MEF
編輯器、不接收或執行 Lua。範圍是既有一般主線副本的戰鬥編排覆蓋檔。
不改任務順序、Client 原件、原生場景索引或存檔。

2026-11-19 後續擴充：同頁新增[一般狩獵場工作台](HUNTING-SCENARIO-WORKBENCH.md)，
支援固定 Case 315／693–706；下方原有主線契約與歷史驗證仍保留。

## 作業流程

在 loopback 管理端 `/admin/scenarios` 選既有主線任務建立範本，或貼上既有
`.scenario.json`，保存有名稱與原因的草稿。全文 JSON 可調整怪物出生、個別 AI、
波次、訊號、屏障、掉落與出口；節點編號、地圖、初始模型順序及來源維持主線
契約。草稿使用獨立 SQLite 表，每次保存產生不可覆寫的版本，保留內容 SHA。
可查看舊版本，從舊內容另存為最新版本。單份 JSON 上限 256 KiB。

每份草稿固定建立時的驗證設定 SHA，由主線 SHA、AI 目錄 SHA 與各地圖 BND
SHA 組成。設定不一致時保留唯讀；不得把舊基準直接視為新版可用內容。
保存不要求驗證成功，避免編輯中的內容遺失；匯出時必須重新驗證指定版本。

驗證使用與 Host 相同的內容解析、圖與旗標依賴、主線來源／任務綁定、AI
參照及 BND 靜態可達性檢查。預覽列出節點、怪物、增援、訊號及出口；
錯誤顯示在編輯頁，不以保存成功等同可載入或實機通過。

通過後下載原版本 UTF-8 位元組的 `.scenario.json`，顯示 SHA-256 與
`TARTAROS_LOCAL_STORY_SCENARIO_PATH`／`TARTAROS_LOCAL_STORY_SCENARIO_SHA256`
載入方式。工作台不修改運行中設定、不替換 Host、不生成 Client 資源。
正式發布仍須完整 Host 預檢、關卡掉落等配套檢查與正常實機驗收。

## 啟用與界線

Admin 需設定三項：`TARTAROS_ADMIN_SCENARIO_STORY_PATH`、
`TARTAROS_ADMIN_SCENARIO_STORY_SHA256`、`TARTAROS_ADMIN_SCENARIO_BOUNDS_DIRECTORY`。
使用既有固定來源主線與 BND，啟動時核對；未設定時不開放工作台。
目前使用 Host 內建 AI 目錄，預覽顯示其 SHA；自訂 AI 配套、圖形化編排與
任意新 Case 的部署仍另行開發。範本與保存資料不包含帳號或遊戲資產。

現行 `alsmeer-mainline-route-v2.json` 提供 Q119 至 Q144 的十份主線副本範本，
SHA `14773c3184b201e6a369b753fbf1094972d792c1e2f8e10a4f67587714def50c`。
本機 launcher `tools/start-local-cash-admin.ps1` 可指定 `-ScenarioBoundsDirectory`；
省略時僅在已有 `outputs/fresh-early-raid-story-bounds` 時啟用。不下載原始資源，
不以空白地形代替 BND。其他使用者需自行備妥相同 SHA 的合法來源。

原生 MEF 的名稱到載入／執行鏈與本地怪物身分／死亡事件仍缺證，
沿用 [MEF 功能追蹤](../../governance/MEF-FUNCTIONAL-COMPLETION.md)的界線。
此工作台不能將上述缺口標記完成。

## 2026-11-19 工程驗證

[收據](scenario-workbench-validation.json)：Host、檢查器與管理端 Release
最終建置零警告、零錯誤。最終 HappyPath 608／608 通過。首次整套曾有既有商城
TCP 正流程在 Session 釋放等待逾時（607／608），原樣單項複驗與整套重跑通過；
成因尚未確認，Server 的 SFD-0009 保留此觀察，不聲稱已修復。

獨立瀏覽器建立 Q119 範本、加入背包旗標與資源延續保存第二版，實際 BND
檢查通過；HTTP 匯出兩版與原保存 UTF-8 位元組及 SHA 標頭一致，歷史可讀。
管理端已換版並核對組件 SHA、四頁 HTTP 200 與 loopback。遊戲 Host 保持原程序，
測試草稿未搬入使用者資料庫，Client 操作／資源修改與遊戲實機驗收均未執行。
