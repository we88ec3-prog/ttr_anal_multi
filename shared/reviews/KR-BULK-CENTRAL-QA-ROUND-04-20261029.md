# KR Bulk 集中品質檢查 — 第四段（2026-10-29）

狀態：**PARTIAL / TOOL-TESTED / NOT FULL-PASS**。

## 目的
在第三段查詢器品質檢查後，建立跨 Task 可重複執行的唯讀索引完整性驗證器。工具不修改原本 `kr-bulk-roy` 的資料。

## 本次成果
- 新增 `shared/reviews/tools/bulk_integrity_audit.py`，讀取完整 checkout 的 `index.jsonl`，檢查 JSONL 格式、重複函式地址、來源 SHA、偽碼與 raw / seed 參照、檔案存在、SHA256 和路徑限制。
- 新增 `shared/reviews/tools/test_bulk_integrity_audit.py`，由獨立暫存 fixture 執行六種情境。
- **本地 Python unittest：6 tests / 6 passed**。測試案例是正常索引、重複地址、JSONL 格式錯誤、hash 不符、路徑越界、引用檔案缺失。
- 程式輸出 `schema`、`source_sha256`、`counts`、`unique_addresses`、`exceptions`、`exceptions_truncated` 與 `classification`；分類固定 `FILE_INTEGRITY_ONLY_NOT_SEMANTIC_OR_FULL_PASS`。

## 執行方式

```bash
python -m unittest discover -s shared/reviews/tools -p 'test_bulk_integrity_audit.py' -v
python shared/reviews/tools/bulk_integrity_audit.py . --output kr-bulk-audit-output.json
```

需在具有完整 repository checkout 的環境執行。**本次沒有取得完整 Git checkout／大型 `index.jsonl`，因此並未執行 111,054 筆全量資料核對。** 本段六項 fixture 通過不應解讀成 GitHub 上所有函式的 hash 已通過。

## 來源與限制
- 工作分支：`extra/roy2`。
- 原始 KR BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，已於前段核對。
- 本段沒有重新驗證全部 CFG、函式邊界或 Client / Server 語意。
- 工具每個引用獨立讀取及 hash，尚未對重複 Evidence 做快取，也尚未用真實的 index/schema 全量測試。
- 若未來取得實際 index 掃描結果，應與 `shared/integrations/T01-BULK-20261026-02/validation.json` 比較，不要用歷史凍結總數替代新掃描結果。
- 正式共用 FULL-PASS 准入仍須依 T01 審核政策辦理，這份 QA 只作 PARTIAL 導航與驗證準備。

## 下一段
以完整 checkout 的真實 JSONL schema 做行級掃描，紀錄總數、錯誤行號、唯一地址、重複地址異質性、各種缺檔及 SHA 比對結果，再分析性能與異常。
