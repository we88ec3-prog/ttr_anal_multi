# KR Bulk 集中品質檢查 — 第六段（2026-10-29）

**PARTIAL / REGEX-DEFECT-FIXED / NOT FULL-PASS**

## 重要新發現

經 GitHub 遠端逐檔讀回第五段的 `bulk_integrity_audit.py`，發現 `HEX64` 與 `ADDRESS` 兩個 regex 在 Python raw string 裡用了 **雙重反斜線**（`\\\\Z`），而正確的嚴格結尾錨點是單重反斜線（`\\Z`）。這會令合法 SHA256 或地址的 `fullmatch` 不依預期工作。現已在 `extra/roy2` 修改為：

```python
HEX64 = re.compile(r'[0-9a-fA-F]{64}\\Z')
ADDRESS = re.compile(r'0[xX][0-9a-fA-F]+\\Z')
```

上面程式碼是修正後的 Python 文字形式；可直接讀回工具比對。這是**驗證器程式碼問題**，不能推論原始 BIN 或凍結索引有損壞。

## 回歸測試覆蓋

前段 11 個測試定義保留，新加：
- `test_invalid_address_rejected`
- `test_source_sha_mismatch`
- `test_duplicate_identical_flag`

合計 **14 個測試方法已在 GitHub 提交**。本次尚未在可執行的完整 Git checkout 跑更新後整套 unittest；**不宣稱 14/14 passed**。前四段的舊 fixture 結果不代表本版通過。

## 真實 bulk 全量核對的限制

GitHub connector 已讀取工具與部分偽碼，但大型 `index.jsonl` 內容讀回為空；本地 container 對 GitHub 的 DNS 連線未成功，無法完成 clone。因此本段**沒有**產出新的 111,054 筆實測完整性通過率、重複地址數或缺檔清單。既有凍結批次保存統計仍是歷史紀錄，非本輪新驗證。

## 後續驗收

在完整 repo checkout 執行：

```bash
python -m unittest discover -s shared/reviews/tools -p 'test_bulk_integrity_audit.py' -v
python shared/reviews/tools/bulk_integrity_audit.py . --output kr-bulk-qa-results.json
```

通過後保留完整 stdout、檢查 JSON 與工具版本 commit SHA；如查到問題，列出具體 index 行號、地址、原始 hash、證據檔案。完整檔案 hash 驗證仍不是函式語意 FULL-PASS，正式知識提升由 T01 依共用政策裁決。

## 改動隔離

只變更 `shared/reviews/tools`、本審核原稿及共用 QA 導覽；未修改 `main`、其他 Task、`kr-bulk-roy` 凍結資料或 `shared/verified-knowledge`。
