# Tartaros 可遊玩流程分工資料

2026-10-24：既有成果整理版完成。原生功能仍有缺口；本輪沒有執行遊戲或新增原生逆向分析。

## 入口

- [Server 規格（S00；規格各自維持 DRAFT/PARTIAL）](spec/README.md)
- [S00／T01 分析與 Server 規格工作流程（正式內部規則）](governance/workflow.md)
- [S00 → T01–T16 收件、認領、回報與審查（正式）](research/dispatch/README.md)
- [S00 Phase B 收斂與 Phase C 工作包計畫](governance/S00-NEXT-PLAN.md)
- [S00 Iteration 05 — 契約來源與審查狀態防誤升](governance/S00-20261029-ITERATION-05.md)
- [S00 Iteration 06 — Phase B 動態工作清單](governance/S00-20261029-ITERATION-06.md)
- [S00 Phase B 研究收件與有限契約驗收](governance/PHASE-B-INTAKE-REVIEW.md)
- [S00 RR 逐筆決議與來源審查](governance/reviews/README.md)
- [Server 契約可交付性審核與七項阻塞](spec/IMPLEMENTER-HANDOFF.md)
- [Server-only ADR 提案（尚未批准）](design/decisions/README.md)
- [T03 當前收件箱範例](research/dispatch/inbox/T03.md)（KR/TC 請求按版本區分）

- [Server 設計與專案分析原始提案（歷史記錄；派工流程已正式實作，規格仍按成熟度審核）](governance/proposals/2026-10-29-server-spec-workflow.md)

- [KR：T01～T16 任務入口](kr/README.md)（T16 新增規劃）
- [TC：T01～T16 任務入口](tc/README.md)（T16 新增規劃）
- [T16：任務與劇情流程規劃](T16-KR-TC-ANALYSIS-PLAN.md)
- [接續導覽](HANDOFF.md)、[AI工作規則](AGENTS.md)
- [完成報告](REPORT.md)、[詳細統計](REPORT.json)
- [使用與重現步驟](REPRODUCE.md)
- [T08 實體生成與移除](exports/kr-T08-release.zip)
- [T09 關卡內移動與同步](exports/kr-T09-release.zip)

ZIP位於本機exports，預設不提交Git；從Git下載者可用下方命令自行匯出。

## T16 新增規劃（2026-10-28）

T16：**任務與劇情流程（Quest & Story Progression）**。優先 P0 新手教學與早期主線，P1 其餘主線，P2 支線；阻塞主線的前置支線提前處理。T04 保留角色初始化與初始位置，T16 僅分析已建立角色的教學與任務起始判定、進度與解鎖。T14 的關卡目標、結算與 T15 的底層保存不移轉給 T16。KR/TC 分開蒐證，不直接套用位址或未驗證的任務規則。

新增 `kr/tasks/T16/{README.md,task.json}` 與 `tc/tasks/T16/{README.md,task.json}`；目前均未認領且未完成原生語義審核，尚未更新 catalog、匯出包及重新計算的任務統計。

## 本版內容

本頁412/407來源、124狀態與104方法為整理版基準統計；後續KR T03／roy增量原生審核見[任務文件](kr/tasks/T03/README.md)及shared/catalog，不能把基準頁的「未新增原生分析」套用到後續工作。

完整盤點原始anal的105,962檔、31.129 GiB。選入來源412檔，按SHA去重後407份；所有未選檔案的SHA、位置與排除原因亦已保存。原anal未修改。

**以下是 2026-10-24 既有整理版的歷史數字（不含新增 T16）**：KR／TC各15項任務，124筆狀態紀錄、104個方法項目。方法數不是有效函式總數；未分派項目先認領再分析。選入內容仍有166份版本歸屬不充分，保留unclassified。

## 使用

Python 3.10+，僅標準函式庫。在本目錄執行：

```powershell
python shared/handoff.py verify
python shared/handoff.py query --version kr --task T08
python shared/handoff.py export --version kr --task T08 --out exports/kr-T08-new
```

對AI可說：「先讀README、AGENTS與kr/tasks/T08，接續KR T08；核對來源SHA與AI替代標記，先認領範圍，不執行遊戲。」

原始Tartaros.bin不隨包提供；新分析需另外取得shared/targets.json指定SHA的原檔，以及REA/Ghidra。閱讀與校驗不需要原anal。證據.txt保留原始內容，包含歷史腳本，不能直接執行。

## 驗證與限制

T08/T09已完成獨立解壓、禁止原anal與目標執行檔讀取、任務查詢、文件連結檢查及竄改偵測。詳validation/release-tests.json。

這證明有限成果包可攜，不代表全部歷史證據閉合、原生規則已完整還原或遊戲可玩。每項task.json保留缺口；台版不套用韓版結論，保護殼保持停止。最新frame-dispatch保留原階段未驗收限制。

完整壓縮清單：shared/manifests/source-inventory.complete.jsonl.gz；納入／排除：dispositions.jsonl.gz；選入映射：source-map-v2.json。舊檢查點保存在history，Git預設排除它與可重新生成的ZIP。


2026-10-28：[本輪整合與T16登記](shared/integrations/T01-20261028-06/README.md)。catalog現為KR/TC各16項、共32項；原頁統計仍為歷史基準，最新限定結論與缺口依catalog／批次紀錄。
