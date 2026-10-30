# KR Bulk 集中品質檢查 — 第八段（2026-10-29）

**狀態：PARTIAL / PREFLIGHT EXECUTED / NOT FULL-PASS**

## 1. 本段實質進展

新增實際可執行的唯讀前置檢查工具，用來區分資料未取得與資料已驗證，避免全 Task 將 GitHub 既有凍結批次的 111,054 筆當成本輪重新稽核結果。

- 工具：`shared/reviews/tools/kr_bulk_preflight.py`
- 測試：`shared/reviews/tools/test_kr_bulk_preflight.py`
- 原件 SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 工具不啟動遊戲、不修改已保存 `kr-bulk-roy`，只讀取 index 並可輸出獨立 JSON。

## 2. 真正執行的測試

```text
test_empty_index ... ok
test_missing_directories ... ok
test_missing_index ... ok
test_present_index ... ok

Ran 4 tests in 0.005s

OK
```

**4/4 pass，0 failures。** 所有測試使用 `tempfile` 的人工 fixture。

重要：本次不是重建副本近似性推論。實際本地測試檔案與 GitHub 遠端提交後讀回的 blob SHA 完全相同：

| 檔案 | Git blob SHA1 | 結果 |
|---|---|---|
| `kr_bulk_preflight.py` | `5376753e4e89cd55d442ac2bcf31688a2f839800` | 本地計算 = GitHub |
| `test_kr_bulk_preflight.py` | `d5f6b15039e8c3fbab94ce279e67b85165d2c28a` | 本地計算 = GitHub |

## 3. 本次環境的真實資料檢查

在本地執行：

```bash
python kr_bulk_preflight.py /mnt/data
```

結果：

```json
{
  "schema": "kr-bulk-audit-preflight-v1",
  "source_sha256": "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91",
  "index_exists": false,
  "index_bytes": null,
  "index_sha256": null,
  "ready_for_full_audit": false,
  "status": "BLOCKED_NO_COMPLETE_INDEX"
}
```

上述狀態**只描述這次容器 `/mnt/data` 無完整 index**，不能推論 GitHub 上的索引檔不存在。GitHub connector 可讀該檔的 blob SHA，但對大型正文無法提供內容；容器命令 `git ls-remote` 因 DNS 解析失敗而無法 clone。

## 4. 跨 Task 驗證規則

- `PREFLIGHT_ONLY_READY_FOR_FULL_AUDIT` 表示索引檔非空且基本目錄存在，**不代表任何行已校驗**。
- `BLOCKED_NO_COMPLETE_INDEX`、`BLOCKED_EMPTY_INDEX` 或 `BLOCKED_MISSING_DIRECTORY` 是本地資料條件不足；不可轉成原版遊戲缺函式、缺協定或損毀結論。
- 正式大量 QA 仍須執行 `bulk_integrity_audit.py`，保存完整 stdout、逐項 SHA、行號與 exceptions，以及 index 的實際 SHA。
- 即使檔案完整性全部通過，原生功能語意與 FULL-PASS 仍歸 T01 的正式逐主張審核。

## 5. 完整 checkout 的建議執行指令

```bash
python -m unittest discover -s shared/reviews/tools -p 'test_kr_bulk_preflight.py' -v
python shared/reviews/tools/kr_bulk_preflight.py . --output kr-bulk-preflight.json
python shared/reviews/tools/bulk_integrity_audit.py . --output kr-bulk-audit.json
```

唯讀掃描的結果檔需置於非凍結目錄，之後再依實際數字整理異常。下一段優先處理完整 index 的取得與大檔 IO；不應在沒有原件的環境無限增加假資料測試。

## 6. 變更範圍

只提交 `extra/roy2` 的 `shared/reviews/` 文件與工具。不改 `main`、`kr-bulk-roy`、其他 Task、catalog、owner 或正式 `shared/verified-knowledge/`。
