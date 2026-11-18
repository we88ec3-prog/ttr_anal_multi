# MEF 工作目標（2026-11-18 使用者修正）

本目錄後續 MEF 工作先讀 [MEF-CURRENT-DIRECTION.md](MEF-CURRENT-DIRECTION.md) 與目前研究包。這項明確使用者指示優先於歷史研究包的目標分類：

- MEF 開發是 Server 開發的一部分；Server 提供 MEF，能交給 MEF 的規則、排程與執行優先交給 MEF。
- 生怪、戰鬥判定、群清、出口、任務結算、獎勵與保存都在範圍內；不能因「Server 負責」把 MEF 排除。
- 不以復原官方 MEF／官方 grammar 為目標；不能把缺官方檔案當自有 MEF 的共同阻塞。自有設計與原生事實仍須分清。
- 區分 Client 執行 MEF 的計算外移、Server 執行 MEF 的規則資料化，以及最小同步／保存 adapter。報告實際能力與具體接口，不用 ownership 代替證據。
- 沿用 `extra/roy1`；沒有新的使用者要求不要另建 branch。原件唯讀、正式狀態與既有測試排程照原規則，不因本頁而改動。

`02-PROJECT-SHARED-INSTRUCTIONS.md` 的來源、證據、跨 Task 復用及 Server 需求分類繼續適用。遇到方向衝突依使用者本次說明，不重開確認流程。
