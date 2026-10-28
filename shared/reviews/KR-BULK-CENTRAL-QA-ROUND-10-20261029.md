# KR Bulk QA — 第十段：真實資料存取判定與全量稽核執行契約（2026-10-29）

**審核等級：PARTIAL / BLOCKED-FULL-DATA / NOT FULL-PASS**

## 本次直接核驗

1. 對 GitHub `extra/roy2` 逐檔讀取 `shared/reviews/README-KR-BULK-QA.md`：存在，Git blob `d24bdac6ad9024657c1559e6a07eeb7de2e72204`（本輪查詢時的版本）。
2. `shared/integrations/T01-BULK-20261026-02/summary.json` 存在，Git blob `ed69932cc57ed1204c3a5c2b284ddb3f160465b1`。該檔原有保存統計，不是本次重新驗收。
3. `kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/index.jsonl` 在 GitHub 可查其 Git blob `89c8d6a75fea00b668df7d96945eadd30b561a97`，但本輪嘗試精確行範圍（1–5）仍傳回空內容（length 0）。這只能證明 API 內容讀取受限，**不能推定倉庫檔案為空**。
4. 本地 `git ls-remote https://github.com/we88ec3-prog/ttr_anal_multi.git refs/heads/extra/roy2` 回報 `Could not resolve host: github.com`。因此本次環境不能取得完整 checkout。
5. `/mnt/data` 中可用的是原始 `Tartaros.bin` 與先前報告等附件，沒有完整 `kr-bulk-roy` 的 `index.jsonl`、`functions`、`raw` 目錄。

## 重要品質結論：阻塞不是「索引不存在」

| 判斷 | 證據 | 分類 |
|---|---|---|
| Git 上有 `index.jsonl` 的 blob metadata | `89c8d6a75fea00b668df7d96945eadd30b561a97` | 已確認存在引用 |
| GitHub 讀取其少量行內容 | 回傳空字串 | 取得受阻 |
| 本地 Git clone／fetch | DNS 失敗 | 取得受阻 |
| 現有 111,054 筆是否逐筆 SHA 相符 | 無新測量 | **UNKNOWN** |
| 正式原版 Client 函式語意 | 沒有本輪完整 BIN CFG 審核 | **NOT FULL-PASS** |

### 來源版本鎖定

後續正式執行時，應固定這次 index Git blob `89c8d6a75fea00b668df7d96945eadd30b561a97`，並在結果中保留 checkout commit、`index.jsonl` SHA256、驗證器 Git blob、執行時間、Python 版本、exit code、所有例外及截斷標記。不要只報告「完成 111054 筆」。

## 全量稽核工作契約

在完整 checkout 中執行：

```bash
git status --short
python -m unittest discover -s shared/reviews/tools -p 'test_kr_bulk_preflight.py' -v
python -m unittest discover -s shared/reviews/tools -p 'test_bulk_integrity_audit.py' -v
python shared/reviews/tools/kr_bulk_preflight.py . --output kr-bulk-preflight.json
python shared/reviews/tools/bulk_integrity_audit.py . --output kr-bulk-integrity.json
```

結果 JSON 應寫到與凍結原件不同的位置、明確確認完整 checkout 且 `raw`、`functions` 存在後執行；如 exit code 非 0，保留輸出與完整 exceptions。對照 T01 凍結 `validation.json` 時標註「歷史原記錄／本次獨立實測」兩個不同欄位。檔案 hash 全部一致也不代表語意 FULL-PASS。

## 第十段停止理由

**這次實際沒有新增可靠的全量函式證據。** 在同一受限環境中繼續編造測試資料無法解除阻塞；下一個有意義的研究動作是從能下載完整 Git 物件的環境產出真實掃描報告。此段如實保存來源、阻塞與正式可驗收命令，不聲稱全量掃描成功。

未修改 `main`、其他 Task、T01 正式知識、原件或凍結 bulk 輸出。
