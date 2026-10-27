# T16 任務與劇情流程（Quest & Story Progression）— KR

> 規劃文件，尚未認領；`native_complete=false`。此文件已納入 GitHub，不代表 catalog 正式登記、原生功能驗收或可遊玩完成。

## 正式範圍
新手教學（P0）、早期主線（P0）、後續主線（P1）、支線（P2；主線必要前置優先）的接取、前置依賴、事件觸發、階段推進、交付、解鎖、狀態同步與中斷續接。

## 職責邊界
T16 主責跨任務／跨關卡 Quest & Story Progression；不建立新角色，不負責初始能力、裝備、出生位置、初始場景。T04 主責角色初始化；T03 主責登入選角；T07 主責關卡進出；T14 主責關卡目標、勝敗、結算與獎勵；T15 主責底層持久化；T02 主責封包基礎框架。引用其他 Task 的地圖、NPC、實體和戰鬥證據，不改其 owner 或 catalog。

## 優先研究
1. 按版本與 SHA 盤點任務資源、任務 ID／step ID、文本、事件、封包，區分原生與 AI/fixture。
2. 以 T03/T04 既有角色資料為輸入，查教學適用判定→逐步目標與驗證→完成或中斷續接；區分 UI、本地事件及伺服器權威。
3. 還原教學結束→主線首節 NPC/對話前置→接取→場景／關卡條件→交付→後續解鎖。
4. 逐章延伸主線依賴圖；支線獨立建檔，若阻塞主線則優先。
5. 形成最小伺服器／封包恢復規格，不把測試 fixture 的自製條件當官方規則。

## KR 證據與驗收
以版本匹配的 KR BIN、客戶端資源、可信封包和原始來源交叉驗證，提供原始位址、指令、來源 SHA、狀態欄位、證據分級和明確缺口。既有 MAINLINE-FLOW、QUEST-STATE-NOTIFICATIONS 與 tutorial fixture 均只能作研究線索。

每個節點應記錄 quest/step ID、前置、trigger、state writer、網路通知、下一節點解鎖、持久化需求、證據與測試案例；未知欄位填 unknown。遵循 AGENTS.md、HANDOFF.md 與 shared/CLIENT-MODIFICATION-POLICY.md。

2026-10-28 來源整合入口：[T01-20261028-06](../../../shared/integrations/T01-20261028-06/README.md)。限定證據、T16分工與更正已入catalog；不等完整原生／遊玩驗收，既有主責與狀態保留。實際接續SHA見批次收據。
