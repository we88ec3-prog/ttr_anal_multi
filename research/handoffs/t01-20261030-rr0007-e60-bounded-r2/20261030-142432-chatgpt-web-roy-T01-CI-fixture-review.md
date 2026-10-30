# T01 / S00：修復 Phase B 回歸測試的歷史狀態假設（2026-10-30）

本輪 T01 整合 RR-0007 E60 及 RR-0001/0004/0006/0007 的 `IN_REVIEW` 並提交後，GitHub Actions `S00 specification registry integrity` [run 41013672946](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41013672946) 的前八個正式資料完整性檢查通過，但 48 個 regression tests 中 7 個因**測試夾具混用真實主線台帳**失敗：

- `test_contract_coverage` 預設 `RR-0001=QUEUED`；
- `test_phase_b_review_preflight` 預設沒有研究原稿，實際主線五個正式提交已存在，測試 temp root 僅複製 JSON，導致來源缺檔；
- `test_phase_b_worklist` 預設全部八個 RR 未提交，並以唯一 `RR-0008` SUBMITTED 測排序；
- `test_s00_readiness` 預設 `requests_queued=8`；
- `test_s00_reviews` 預設空 S00 review ledger，但現有 RR-0005 ACCEPTED 已有完整 review，temp root 沒複製其關聯 blob。

**修正**：新增 `governance/s00_test_fixtures.py`，僅在上述五個單元測試的 `TemporaryDirectory` 複製完成後建立**明確標記的 synthetic「8 RR QUEUED／未提交／空 review」基準**；真實 `main` 的 `research/requests/index.json`、`governance/reviews/index.json`、source blob、正式 S00/T01 驗收與測試產線行為一律不更動。以此維持歷史風險/缺漏測試同時讓後續真實 RR 派工合法演進。

本次變更只修測試資料隔離，不將 `RR IN_REVIEW` 提升 `ACCEPTED`、`SPEC_CONSUMABLE`、`NATIVE_VERIFIED/FULL-PASS`、`SPEC STABLE` 或可玩性。GitHub CI 是否全綠，以後續新 commit 的 Actions 結果為準。
