# KR Bulk 集中品質檢查 — 第五段（2026-10-29）

**狀態：PARTIAL / CODE-UPDATED / NOT FULL-PASS。**

## 實際來源與執行範圍
- 以遠端 `extra/roy2` 上的 `shared/reviews/tools/bulk_integrity_audit.py`、`test_bulk_integrity_audit.py` 為基礎修改；沒有修改凍結 `kr-bulk-roy`、其他 Task 或 `main`。
- GitHub 連線可讀個別原始檔，但 `index.jsonl` 大型內容尚無法取得；`git ls-remote` 因容器 DNS 無法解析 GitHub，故無法 clone 完整倉庫做全量核對。
- **本次沒有實際執行更新後的單元測試**；新增五個 fixture 案例屬「已撰寫、待執行」，不得稱 11/11 通過。
- 先前第四段的 6/6 通過為前版紀錄，不得外推至此版。

## 程式碼改進與可驗證設計
| 改進 | 靜態確認的實作 | 當前狀態 |
|---|---|---|
| 地址格式 | `ADDRESS.fullmatch` 只允許十六進位地址 | 已寫入；待實際執行 |
| SHA 格式 | `HEX64.fullmatch` 拒絕非 hex 64 字元 digest | 已寫入；待實際執行 |
| 重複地址 | 保留前筆行號及內容；輸出 `identical` 標記 | 已寫入；待實際執行 |
| 偽碼參照缺少 | `missing_pseudocode_reference` | 已寫入；待實際執行 |
| Evidence 雙來源 | 同列包含 `batch_path` 與 `seed_evidence` 時警示 | 已寫入；待依實際 schema 判讀 |
| 路徑檢查 | 路徑解析後做根目錄限制，並拒絕 POSIX absolute path | 已寫入；Windows drive path 尚需跨平台測試 |
| 例外截斷 | `issues_total`、`exceptions_truncated`、CLI `--max-exceptions` | 已寫入；待實際執行 |

## 測試增量
保留舊有六項 fixture；新增 `test_invalid_digest_format`、`test_missing_pseudocode_reference`、`test_ambiguous_evidence_reference`、`test_duplicate_conflict_flag`、`test_exception_truncation`。目前總共 11 個測試方法；**非 11 個已通過**。

## 尚未解除的風險
1. `index.jsonl` 111,054 筆對偽碼／raw 的全量 SHA 尚未執行；未獲得真實錯誤率。
2. 尚未以實際 index 樣本確證 row schema，seed/batch 欄位預期須在完整 checkout 核對。
3. 檔案散布於 Unix/Windows 時，字母大小寫、symlink、Windows 絕對路徑仍需跨平台測試。
4. 工具仍對重複引用的 raw batch 反覆 hash，待完成效能實測與快取設計。
5. `--output` 產物是檔案完整性 QA，不代表任何 CFG、封包、函式語意或 FULL-PASS。

## 驗收命令（需完整 Git checkout）
```bash
python -m unittest discover -s shared/reviews/tools -p 'test_bulk_integrity_audit.py' -v
python shared/reviews/tools/bulk_integrity_audit.py . --output kr-bulk-qa-05-results.json
```
成功執行後需將 stdout、測試結果、實際 JSON 計數與 exception 詳情一起記錄；不能把歷史凍結紀錄當成新結果。
