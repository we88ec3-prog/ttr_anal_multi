# 怪物巡邏路線

關卡可在初始怪物、順序增援或定時增援的單筆 `encounters` 設定 `patrol`。每筆路線包含 1 至 16 個絕對地圖座標。怪物從出生點開始，依序走完各點再回出生點，然後重複。未設定路線的怪物沿用原行為。

```json
{
  "model": 1001,
  "x": 389.5,
  "y": 377.5,
  "aiProfile": "patrol-melee-v1",
  "patrol": [{ "x": 393.5, "y": 377.5 }, { "x": 393.5, "y": 381.5 }]
}
```

套用的 AI 設定須同時有 `aggroRange` 和 `leashRadius`。載入時驗證所有巡邏段，包括最後一點回出生點，須在可走地形內，每段距離大於 0 且至多 256，所有點都在以出生點為中心的追擊範圍內。巡邏中依怪物當前位置判定索敵，並以出生點判定追擊範圍。受擊或索敵後接既有戰鬥邏輯。目標離開追擊範圍時取消待命中的攻擊並回出生點，抵達後從第一個巡邏點重新開始，HP 與攻擊冷卻照原值保留。

巡邏與回位都使用 Server 地圖碰撞。戰鬥後的回位是直線，若遭地形阻擋會停在可走位置，這版沒有繞路。Server 決定位置並發送既有位置及動作更新，Client 顯示路線。原生 `.mef` 的格式、Client 自行生怪與自主選路仍待證實。 [Client 怪物控制證據](../../governance/s00-iterations/S00-20261113-MONSTER-LOCAL-CONTROLLER-BOUNDARY.md)

## Q119 範例

第一圖 632 的第一隻怪使用上述巡邏。範例保留主線地圖和怪物模型順序，另沿用 Q119 資源延續版的設定。路線與索敵半徑為 Server 候選配置。載入 [主線外部關卡](STORY-SCENARIO-OVERRIDES.md) 時，另設定 `TARTAROS_LOCAL_MONSTER_BEHAVIOR_PATH` 和 `TARTAROS_LOCAL_MONSTER_BEHAVIOR_SHA256`。怪物行為檔包含原有的 `legacy-melee-v1`，供其他怪物繼續使用。

| 檔案 | SHA-256 |
|---|---|
| [關卡](story-q119-patrol.scenario.json) | `103d65834f343eb99e562dc8ca29a40e853233363f64f67280a6baf7f1dc786c` |
| [怪物行為](story-q119-patrol.monster-behavior.json) | `3d7296de932fdc71a9ac29db06eb82cf9527b12d662b49eb2a3cd94a59690df0` |

資料預檢同時載入主線、外部關卡與行為檔，檢查配對雜湊、怪物模型順序及巡邏段地形。使用 Server 檢查工具時，依序傳入下列參數，各檔使用絕對路徑。

```text
--story-content <主線檔> <地圖資源目錄> <主線SHA> <關卡檔> <關卡SHA> <怪物行為檔> <怪物行為SHA>
```

[PT-01](../testing/S00-CONTENT-BATCH-TESTS.md) 待實機驗收。
