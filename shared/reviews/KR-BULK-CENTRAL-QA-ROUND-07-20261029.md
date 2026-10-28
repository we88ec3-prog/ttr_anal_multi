# KR Bulk 集中品質檢查 — 第七段（2026-10-29）

**狀態：PARTIAL / 14 FIXTURE TESTS EXECUTED / NOT FULL-PASS**

## 實際執行結果

已從遠端 `extra/roy2` 讀回第六段 `bulk_integrity_audit.py`（blob `7c863ce2f4d997825268a254356d96c2c1678730`）與 `test_bulk_integrity_audit.py`（blob `586fd0b908ae97f3420418faae171b1d79f83cdc`）內容，依其程式邏輯於本地建立測試副本並執行：

```text
python -m unittest discover -p 'test_bulk_integrity_audit.py' -v
Ran 14 tests in 0.026s
OK
```

- 實際執行 14 個 unittest 方法：**14 pass / 0 failures / 0 errors**。
- 包含：有效索引、重複地址（相同／相異）、損壞 JSON、偽碼 hash 不符、路徑越界、缺檔、非法 hash 格式、缺少偽碼參照、雙 Evidence 參照、例外截斷、非法地址、來源 SHA 不符。
- 測試環境：Python 3、離線臨時 fixture；只建立暫存假資料，不執行或修改遊戲。
- **精確邊界**：本地手工重建副本與遠端版本程式邏輯一致，但因本地副本的引號／格式不同，Git blob 並非 byte-for-byte identical；因此這個測試不能冒稱為遠端原始 blob 的位元組完全一致測試。完整 unittest stdout 另存於本批文字紀錄，當次測試輸出以此報告所列總結為準。

## 新取得的確證

第六段 regex 修正後，在本地副本的實際測試下：
1. 十六進位函式地址及 SHA256 正常測試不再被格式檢查阻擋。
2. 14 個既存 fixture 的期望行為均成立。
3. 異常分類的程式介面可供下一階段完整 checkout 測試。

## 仍需區分的限制

- 本環境無完整 Git checkout；GitHub 大型 `index.jsonl` 仍無法直接完整讀回，且 GitHub DNS 下載不可用。
- **未執行實際 111,054 筆索引與 raw/偽碼 SHA256 全量核對**；沒有任何真實 bulk 的缺漏數、hash 差異數或通過率。
- 14 筆 fixture 測試不能代表原生函式語意、CFG 或 Server 端規則通過。
- 程式尚可能存在這 14 個 fixture 未覆蓋的 schema、跨平台 Windows path、I/O 效能及錯誤處理問題。
- FULL-PASS 提升仍須由 T01 精確主張審核。

## 下一階段 P0

以完整 Git checkout 執行工具，輸出逐行例外、實際統計與 SHA 對照；保留 stdout、工具 blob 與 `index.jsonl` blob。對 `batch_path` 與 `seed_evidence` 的真實 row schema 實行樣本驗證，避免 fixture 成功掩蓋真實資料格式不合。
