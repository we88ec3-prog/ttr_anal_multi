# T01-BULK-20261026-02 完整反編譯保存與審核狀態

日期：2026-10-26（Asia/Taipei）。操作者：Codex T01 integrator。依使用者本輪「請先全部上傳，並記錄哪些尚未逐項審核」指示，將凍結的 `kr-bulk-roy` 完整上傳至 `main`。這次是保存完整工具輸出，沒有新增反編譯或功能語意驗收，也不改變方法主責。

來源為 KR `Tartaros.bin`，SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。不適用 TC、啟動器 `Tartaros.exe` 或修改後的 client。

## 檔案與 SHA

`kr-bulk-roy/<目標SHA>/functions/` 是 111,054 份逐函式偽碼；`raw/` 是原始 REA／Ghidra 批次 JSON。原始索引、進度、略過清單、日誌、工具腳本與導覽一併保存，不執行它們。`functions/*.c` 是衍生文字，原始 raw／seed Evidence 為準，換行 bytes 不作正規化。

[source-files.json.gz](source-files.json.gz) 逐檔記錄原始路徑、SHA256、大小與凍結時間；[summary.json](summary.json) 保存總數、來源基準、備份 SHA 及狀態。原 bulk README 的逐字副本另存 `kr-bulk-roy/README.source-before-upload.md`，新版 README 只更新已上傳導覽。完整備份不含 `.git`。凍結後其他任務修改不屬本批；不覆蓋來源工作區。

## 哪些尚未逐項審核

[review-status.jsonl.gz](review-status.jsonl.gz) 每個已保存函式各一筆，包含地址、檔案 SHA、原始來源及登記主責。

- `full_function_semantic_review=not-recorded`：尚無可據以宣稱整個函式完成逐項語意審核的紀錄。本批 111,054 個函式全部保留此標記。
- `related_bounded_evidence`：僅在偽碼檔或 seed Evidence 的精確 SHA 已見於正式 catalog 時列出關聯；這表示有可引用的有限證據，不能當成完整函式驗收。
- `registered_primary_task`：既有方法登記，僅供查主責。登記不等於審核，也不因上傳重新分派。
- raw 批次被引用不表示同批全部方法已審核；工具成功、檔案存在、候選數與行數亦不表示語意完成。

關聯有限證據的函式清單另見 [bounded-evidence-relations.json](bounded-evidence-relations.json)。原本 T02／T03／T06 的成立條件與限制仍以 `shared/catalog.json`、前批 `T01-20261026-01` 為準；本批不降級其既有有限結論，也不擴大驗收範圍。

在倉庫根目錄可查：

```powershell
python -B kr-bulk-roy/review_status.py --summary
python -B kr-bulk-roy/review_status.py 0x4df510
python -B kr-bulk-roy/lookup.py 0x4df510 --metadata-only
```

`lookup.py` 只讀已保存結果，不啟動分析。索引前 21 個 seed 的原始 JSON 依精確 SHA 補齊，見 [seed-dependencies.json](seed-dependencies.json)。來源完整性驗證見 validation.json；僅核對保存內容，不執行遊戲、附加程序、呼叫目標 API，也不修改原始執行檔／資源／帳號／存檔。

## 接續

上傳完成後的實際 commit 與遠端收據會另列於本批次及通知入口。接續者先 fetch，從包含本批次的 `origin/main` 開始，按位址讀現成結果，針對具體功能逐項核對。新審核應列明函式 SHA、覆蓋範圍、證據與未知項，再增量更新狀態；不可把上傳完成改寫成全部審核完成。

交接只透過檔案，未向其他對話傳訊。各功能任務未因此整體完成。

本輪驗證：118,021 份來源檔案／329,507,800 bytes 的 Git index SHA 全數相符，111,054 筆偽碼與狀態一對一，21 份 seed 依賴閉合，凍結後變動為零；詳 [validation.json](validation.json)。
