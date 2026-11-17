# MEF 全功能契約與開發接續

日期：2026-11-17（Asia/Taipei）。工作分支：`extra/roy1`。原生目標為 KR BIN `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；研究起點 `5ef4ab8870ea1c65c6c7497901302d851f5c7a51`，治理讀集 `main@03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。

**先讀勘誤：`Q.FlyingObject` 在建立新圖前會取消上一張 Q 追蹤圖。** 舊 `MEF-feature-lifecycle-20261117` 的「只覆寫最後 handle、不取消前圖」解讀與相關合成測試已被原件反證。原 ASM 有效；須改採[更正說明](reuse/report.md)與[逐項勘誤索引](reuse/errata.json)，不要沿用舊測試的 PASS 作語意證明。

本次完成的是可重跑的靜態研究、全名稱 ABI、事件查詢定型、資源依賴盤點與 Server 開發交接；**整體 MEF／原生格式／Server／遊玩仍為階段性未完成**。121 個正常綁定有完整參數與回傳表，不等於121項功能都已部署，亦不等於所有 native body／動態入口皆已驗收。

按專案時間命名的[研究導讀](20261117-161726-chatgpt-web-roy1-MEF-comprehensive-contracts.md)亦保留同一批完整交付入口。

## 閱讀入口

| 目的 | 文件 |
|---|---|
| 先看本輪新發現、改變了哪些決策 | [REPORT.md](REPORT.md) |
| 看完整功能範圍與四層缺口 | [COMPLETION-MATRIX.md](COMPLETION-MATRIX.md)、[逐名稱索引](function-map/FUNCTION-INDEX.md) |
| 接續分析與功能開發順序 | [ANALYSIS-PLAN.md](ANALYSIS-PLAN.md) |
| 交給 Server 實作者與 S00 整合 | [SERVER-HANDOFF.md](SERVER-HANDOFF.md) |
| 121 個 API 的正確個數、順序、型別與結果 | [ABI 表](abi/ABI-CATALOG.md)、[ABI 說明](abi/report.md) |
| 16 個 query 究竟能觀察什麼 | [事件分析](events/report.md)、[機讀 query 表](events/observation-catalog.json) |
| 相機、模型、對話與圖片的原始資源依賴 | [資源分析](resources/report.md)、[依賴結果](resources/selected-dependencies.json) |
| Q模型ID／PRE、ABF索引及實際路徑如何選取 | [模型選取補證](resource-selection/report.md) |
| 圖片替換、模型引用與兩段交接 | [重用分析](reuse/report.md) |
| 重跑原件與內容預驗 | [VALIDATION.md](VALIDATION.md)、[整包結果](verification-result.json) |

## 使用方式與界線

內容工具先使用 `abi/validate_calls.py` 檢查宣告式呼叫計畫，再核 typed identity、實際資源、prepass／formal 差異、owner 與合法入口。`ABI_PASS_ONLY` 不可用作可部署狀態。資源工具刻意保留未齊全項目，`ready=false` 是有效研究結果，不應為讓測試轉綠而消除。

所有設計輸入、合成模型與 Server 政策皆明示 **NOT_NATIVE_MEF／SYN**。本包沒有新增封包 opcode、官方語法、scene key 或 slot 配置；沒有執行原版 Client、Lua 或 Server；沒有更改 RR、Task owner、T01 FULL-PASS 或 S00 接受狀態。主線既有 Server 功能及人測記錄沿[功能追蹤](../../governance/MEF-FUNCTIONAL-COMPLETION.md)復用，不因本輪新分析而歸零。

原 BIN、STP、完整解包 member 與資源 ZIP 留在本機。本包只發布必要證據片段、來源摘要、分析與驗證工具；來源及檔案雜湊分別見 [source-manifest.json](source-manifest.json) 和 [artifact-manifest.json](artifact-manifest.json)。
