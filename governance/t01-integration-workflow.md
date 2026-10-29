# T01 — 研究整合與風險分流（階段 A）

此流程是**額外的設計整合通道**，不是將歷史全文驗收判定改成 PASS。舊 `kr/tasks/T01/`、318 版台帳與 `shared/verified-knowledge/` 原地保留，原有嚴格 FULL-PASS 判定規則不變。

## 輸入、來源身份與去重

接收研究原稿、精確檔案路徑、Git blob SHA、原件版本（KR/TC）、原始檔 SHA、位址/資料區間、主張邊界與限制。先檢索既存主張和來源修正版；禁止只按段號或時間戳判定相同。只有已明確歸因且確有內容的材料才能萃取主張，機械驗證不自動生成語意結論。

## 兩條**互不覆寫**的狀態軸

**原稿歷史審核：**PENDING / SOURCE_ONLY / PARTIAL / FAILED / FULL_PASS_DOCUMENT_SCOPED，完全沿用既有來源台帳。FAILED 舊版持續為 FAILED；修正版另追蹤 blob，不改舊版。

**新整合工作進度：**REGISTERED → CLAIMS_EXTRACTED → CONFLICT_CHECKED → SPEC_CONSUMABLE。這是工作流狀態，而非獨立原生品質認證。各步必留來源與動作紀錄。未經核對的部分僅可作研究線索，不能冒稱 VERIFIED。

**個別主張的可信度：**NATIVE_VERIFIED / PARTIAL / INFERRED / UNKNOWN / REFUTED。只有符合現有 FULL-PASS 嚴格條件的**精確主張**可標 NATIVE_VERIFIED，且須引用具體審查決議及原始證據。REFUTED 不得作為規範性相容性來源。

## 風險分流

- **R0 機械接收：**核對來源、SHA、版本、格式、路徑；不做語意升格。
- **R1 一般研究：**萃取 bounded claim、標註推論與限制、按精確主張/函式/版本去重，提供 S00 帶信心與未知的導航。
- **R2 高風險：**遇相反證據、映射衝突、關鍵封包欄位/順序、跨 Task 共用狀態、原稿錯誤時，定向查證影響範圍及必要 CFG/dataflow；若需原作者更正，繼續使用 Task README 的「T01 驗收退回事項」而非 Issue。
- **R3 正式原生事實：**欲進入 `shared/verified-knowledge/` 時必滿足全部既有嚴格有界 FULL-PASS 條件；不得由 CI、SHA、自動抽樣或 S00 的 SPEC_CONSUMABLE 自動升格。

## 交 S00 的文件

每一項包含：`claim_id`、`source_file`、`source_blob_sha`、`client_version`、`target_sha256`、`evidence_scope`、`evidence_level`、`assertion`、`limitations`、`conflicts`、`affected_spec_ids`；缺失欄位明示 unknown/阻塞。來源原稿不搬移、不覆寫；同一主張多個來源只做引用歸併，不能以其中一個來源的較高可信度自動涵蓋其他條件。

## 第一階段停止條件

完成來源身份及 bounded claim 的適用範圍、已知衝突標示與 S00 可引用的限定資訊，就停止一般 R1 的重驗。由 S00 遇到具體協定/設計阻塞時再派遣 R2/R3。**不再以完成 318 篇全文 FULL-PASS 作為規格整合門檻。**

精確退回與複驗、不修改其他 Task 原文及未經授權不推研究變更等現行政策仍有效。

## 來源收件操作紀錄

新來源先登錄 `research/intake/index.json`，記錄精確來源檔、Git blob SHA、SHA256、Client 版本與原件 SHA。只有完成 bounded claim 萃取後才可由 REGISTERED 升 CLAIMS_EXTRACTED；主張已和現有版本/反證查對並有紀錄才可升 CONFLICT_CHECKED；S00 確認有限用途並明確記載衝突處置才可升 SPEC_CONSUMABLE。這些狀態皆不代表已完成原生語意驗證。

優先使用 [source-intake 模板](../research/templates/source-intake.md) 和 [server-impact 模板](../research/templates/server-impact.md)。機械性來源 SHA 與引用檢查由 `governance/validate_s00.py` 進行；它不取代 T01 對關鍵原生主張的人工審核。


## T01 與 S00 新派工的介面

T01 每次開工先讀 [T01 待審收件箱](../research/dispatch/inbox/T01.md)，其 SUBMITTED/IN_REVIEW 僅表示研究回報待審，**不是** T01 FULL-PASS 驗收通知；本來的 Task README NEEDS_FIX/READY_FOR_REVIEW 退回程序照舊。T01 可在 RR IN_REVIEW 註明有界證據問題並要求 NEEDS_REVISION，但 S00 才能審核請求完成度與最終 ACCEPTED。請求 ACCEPTED 不表示來源原稿、BIN 語義或相關 SPEC 已正式通過。
