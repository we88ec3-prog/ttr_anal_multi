# KR Bulk 第一段集中品質稽核摘要（由已完成的本地原稿整理）

日期：2026-10-29。狀態：**PARTIAL / 非 FULL-PASS**。本檔是第一段完整本地原稿 `KR-BULK-CENTRAL-QA-20261029.md` 的**共用摘要**，並非逐字原稿；不可冒稱完整重現，原稿在原對話附件保留。

## 保存快照（依 T01 凍結紀錄，非本次重新掃描）
- KR BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；本地重新計算一致。
- 本地 BIN 長度：12,472,320 bytes；PE32 x86、ImageBase `0x400000`。
- T01 記錄保存 118,021 檔、329,507,800 bytes；111,054 已保存函式、0 失敗、662 被略過候選；111,054 個函式均無完整函式語意驗收紀錄。
- 凍結結果有 21 個函式連結限定證據、197 個函式有方法主責；不構成 FULL-PASS。
- 已讀四個 GitHub 函式檔案：`0x4df510`、`0x4f49a0`、`0x4f3d80`、`0x55d7e0`；第一段僅核對讀取存在性與有限內容。
- 來源主據：`kr-bulk-roy/README.md`、`kr-bulk-roy/<SHA>/status.json`、`shared/integrations/T01-BULK-20261026-02/{README.md,summary.json,validation.json}`、`AGENTS.md` 與 `shared/T01-FULL-PASS-UNCLASSIFIED-INTEGRATION-RULES.md`。
- 本地尚未全量核對 `index.jsonl` → `functions/*.c` → `raw/*.json` 的 SHA 或全量語意 CFG，故不能據此提升審核。

## 跨 Task 使用
`kr-bulk-roy` 是可導航但未經全量語意審核的衍生反編譯來源；關鍵肯定主張應直接核對 BIN、raw 與明確上下游，並由 T01 依正式政策裁決。不能將未取得 Server 原件視作 Server 規則已驗證。

## 下一段
見 [第二段原生入口抽查](KR-BULK-CENTRAL-QA-ROUND-02-20261029.md)。第一段完整原稿未於此處逐字保存，請勿將本摘要作為其全文或全文驗證依據。
