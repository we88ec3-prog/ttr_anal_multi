# S00：怪物直線投射物後端驗證（v99準備批次）

狀態：後端已完成本批驗證；飛行特效與實際物種／動作尚未對應，不列Client功能完成。
沿用[後端契約](S00-20261111-MONSTER-PROJECTILE-CONTRACT.md)，不新增原生MEF或飛彈opcode。

## 正流程證據

358個受影響HappyPath通過，相較v98新增8例：飛行後單次命中、橫移閃避與相對掃掠、
保守地圖遮擋及射程端點時間、壽命到期、combat前搖發射／受擊、敵死後彈體及清場等待、
普通攻擊盾防，以及外部可選內容唯讀載入。Targeted9包含1個既有案例，不與358相加。

公開example-projectiles.monster-behavior.json經實際typed loader讀取及Validate，SHA256
`acd8f98ee79e250b125984f8a8e4fd2bb8f5f2b35006c429ca4afde8027a1ef4`。
新schema SHA256 `2ee4f91f917fa7a7213bc474c484402a6febc2cb8b9e493356662ffe05b06fe8`，公開／私有副本相同。
jsonschema4.23.0標準validator通過新schema及投射物、選招、leash、現行功能場與v94行為資料。
舊選招schema保留為local-monster-behavior-attack-selection-v1.schema.json。

## 排程修正與限制

初次targeted合成測試混入一段玩家死亡布林清理檢查，已移至Deferred並保留歷史結果，
不把該條件列為本輪排程驗收；最終358僅Category=HappyPath。其他延期套件未執行。
初次Remove斷言誤用actor+2，已按既有001A語法改讀+4，未更改Server封包以遷就測試。

固定方向、2D線性相對掃掠、quarter-unit可走性遮擋及數值均是Server政策，未證原版投射碰撞、
高度、精準角色hitbox或物種AI。既有動作101不能證明箭／火球視覺；未新增遊戲內人測入口。
v99僅準備，不啟用；線上v96a不動，已有8列人工測試繼續累積。
正式scenario與monster-behavior資料、Client主程式與資源未修改；未執行或附加遊戲。
追蹤彈、範圍／法術攻擊、完整物種AI、召喚、3D機關、道具條件與跨圖Buff／地面效果仍未完成。

接續控制需求：受擊恢復需保留明確移動／放開意圖，不因一段時間沒有新列就推定放鍵，也不能依敵人仍存活才允許玩家行走。既有750ms判斷已列待修，尚非本批操控驗收。
