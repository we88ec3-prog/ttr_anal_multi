# 主線外部關卡檔

一般主線可由獨立的 Server 關卡 JSON 覆蓋特定任務的戰鬥編排。既有主線檔仍提供任務順序、NPC、場景鍵、地圖與存檔版本。未在外部檔列出的任務沿用主線檔內的編排。

## 載入與驗證

在已啟用的一般主線設定中，同時設定下列兩項。省略兩項會沿用原有編排。

| 設定 | 值 |
|---|---|
| `TARTAROS_LOCAL_STORY_SCENARIO_PATH` | 外部 `.scenario.json` 的絕對路徑 |
| `TARTAROS_LOCAL_STORY_SCENARIO_SHA256` | 外部檔案的 SHA-256 |

每個外部定義的 ID 使用 `story-quest-<QuestID>`，來源包含 `SERVER_STORY_NAVIGATION`、`quest:<QuestID>/finite-array-order` 與已載入主線檔的 SHA-256。定義從節點 1 開始，保留原節點編號、地圖和入場怪物模型順序。編排可指定出生位置、AI 設定、增援、旗標、互動點和出口。Server 啟動時檢查圖與條件依賴、AI 參照及現有 BND 的靜態位置。

主線與外部檔各自保留版本識別。已完成任務的前綴仍依主線版本讀取，未完成任務依既有規則從 NPC 開始。診斷欄位 `scenarioOverrideSha256` 表示外部檔版本，`scenarioGraphSha256` 表示合併後的關卡圖版本。

## Q119 範例

[四節點關卡範例](story-q119-clear-scene.scenario.json)的 SHA-256 是 `fc963e98b9ff73388342d349aeb661ba3b563a1055344c79d8bf0715577e3bd3`，配對[主線候選資料](../../governance/client-variants/20261107-town2-mainline/resources/alsmeer-full-mainline-content-candidate.json)的 `14773c3184b201e6a369b753fbf1094972d792c1e2f8e10a4f67587714def50c`。四張地圖、出生位置、怪物和原出口均來自該候選。只把最後一張圖 635 的出口改為入場時預先登記關閉狀態。

清場劇情完成並提交後，Server 依既有流程重建地圖，發送一次完整點位集合。出口和互動點使用當時的旗標，已使用的互動保持停用。沒有清場劇情且出口全都已預先登記的節點，可以只更新點狀態。前述行為屬 Server 自訂格式 `NOT_NATIVE_MEF`，Q119 最終 Client 顯示與互動仍待實機驗收。 [JSON Schema](local-scenario-definition.schema.json)
