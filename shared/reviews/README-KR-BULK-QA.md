# KR Bulk 跨 Task 集中品質檢查入口

**實驗性工作分支：`extra/roy2`**；這不是 `main` 的正式 T01 FULL-PASS 審核決議，不修改任何 Task 的 owner、catalog 或正式結論。

## 檢查批次

1. [第一段品質基線與保存紀錄摘要](KR-BULK-CENTRAL-QA-20261029-ROUND-01-SUMMARY.md)：GitHub 封存狀態、BIN SHA、PE 映射、未審核範圍。第一段本地完整版另附於原對話；此處僅為摘要。
2. [第二段 BIN-first 四函式入口抽查](KR-BULK-CENTRAL-QA-ROUND-02-20261029.md)：VA/raw、48-byte 機器碼入口、偽碼警告、待檢驗風險。
3. [第二段機器可讀 JSON](KR-BULK-CENTRAL-QA-ROUND-02-20261029.json)：精確樣本地址、偏移、入口 bytes、Git blob SHA。

## 使用規則

- 每個 Task 可按地址直接選讀 `kr-bulk-roy/<SHA>/functions/0x<addr>.c`，但標記 `derived-unreviewed`。
- 需要共享結論時，先核 BIN 原始指令、CFG、資料流及 raw；依 `shared/T01-FULL-PASS-UNCLASSIFIED-INTEGRATION-RULES.md` 由 T01 正式審核，不能因為這份 QA 報告上 GitHub 就視為 FULL-PASS。
- 本批無全量 SHA/索引核對、沒有完成逐函式語意驗證、沒有驗證 Server 邏輯與玩家可玩性。
- 本分支作為品質工作成果，不應自動合併至 `main`。

## 第三段：查詢器與索引品質（2026-10-29）

- [第三段完整品質報告](KR-BULK-CENTRAL-QA-ROUND-03-20261029.md)：對 `lookup.py`／`review_status.py` 靜態檢查，指出 silent JSON parse skip、重複地址未回報、Evidence 路徑驗證、`assert` 的 `-O` 限制與線性掃描成本；再次核對四個 BIN 入口 16 bytes。**均是有界原碼品質觀察，未宣稱現有完整 index 實際受損。**
- [第三段機器可讀結果](KR-BULK-CENTRAL-QA-ROUND-03-20261029.json)。
- 完整 `index.jsonl` 內容在這次工具環境未取得，故**全量 SHA 與 index→raw 逐筆核對仍未完成**；後續須在具完整 Git checkout 的環境實行。狀態依然是 **PARTIAL / NOT FULL-PASS**。
