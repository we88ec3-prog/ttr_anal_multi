# 2026-10-30 — T16 工作分支正式合入 main（不改 T01 驗收結論）

- Repo: `we88ec3-prog/ttr_anal_multi`
- 整合方向：`t16/roy/chatgpt-web` → `main`（使用者本次明確授權）
- 來源 T16 分支 HEAD：`afde51ba3be5ffd539f58d21724b916057c89821`；原 `main` HEAD：`9b21d12d6c97a7b5183c7ad87c1ba0e7512e2020`；分岔共同祖先 `54747b31a1c093704785d43b9c599f4bf7fb3907`。
- GitHub 比對：T16 ahead 26 commits，behind 2；工作樹差異**只有 79 個新增檔案，沒有同一路徑衝突或來源檔修改**。
- 整合方法：**真正雙父 Merge Commit**（第一父本次 main，第二父 T16 工作分支），以 main 的原有 tree 為 base，只新增 T16 分支上精確的 79 個現存 Git blob；不修改作者原稿和 T01 正式 README 狀態。
- 交付清單：22 篇 `T16-93…113` 研究/修訂 Markdown、`03-PROJECT-T16-INSTRUCTIONS.md` 一份、`T16-T01-returns-20261029/` 的 37 份作者 errata、17 篇 rooted CFG 補證與 2 份歷史送審說明，共 **79 個來源檔**。逐檔 path/blob SHA 見 [manifest.json](manifest.json)。
- 新研究重要範圍：KR Scenario14、QuestInfo 14→16→15 靜態條件、教學 NPC/Isilia 本地互動、TalkBox C→S queue、S→C parser/handler 候選以及 S00 Server 契約邊界。這些是**研究來源**，不是自動驗證完成的商業 wire 協定。
- 現有 `kr/tasks/T16/README.md` 的 **43/43 個固定退回 ID 已在 T01 複檢決議中標示 `RESOLVED`**；整合時仍保留 main blob `128f9ed40b29f33591b866d61bb7643f6eb56b70`，**絕不回退**成 T16 分支較舊的 `5fd9d66ea0a6d9c005da891604602819b4111df5`（當時 27 resolved、16 ready）。
- 作者新增檔 `kr-temp-roy/T16-T01-returns-20261029/README.md` 與 `T01-REVIEW-REQUEST.md` 所述「等待 T01 審核」，是其**當時送審快照**，不能取代 T01 最新裁決。最新正式審核以 [T01 第三輪驗證](../T01-20261030-t16-phase3-table-review/README.md) 與 T16 README 為準。
- **不因 Merge 升格**：任何 T16 原稿的整篇 FULL-PASS、`shared/verified-knowledge` 的 NATIVE_VERIFIED、新 RR ACCEPTED、S00 SPEC STABLE、Quest14/16/15 Client 完整原生雙向封包或真正可玩驗收。新原稿須由 T01/S00 按既有證據、CLAIM、SPEC 與 RR 規則分別受理。
- `research/requests/index.json`、`research/claims/index.json`、`spec/`、`design/`、其他 Task owner/task.json 與原本主線所有文件，此次皆未改動。
- 來源歷史不可被覆寫：author branch 中每個原始 Git blob SHA 被原樣引用於本次 Merge tree，並保留 T16 branch 的完整 26 個前置提交。
