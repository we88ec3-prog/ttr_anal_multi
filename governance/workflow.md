# Server 設計專案工作流程（階段 A，分支試行）

狀態：試行規則；合併至 main 並經維護者確認後，才成為新的正式工作流程。日期：2026-10-29。

## 專案交付目標

本庫主要交付 **獨立 Server 開發者可用的 Client 相容契約、Server 行為需求、資料與狀態規格、證據及測試**。實際 Server 原始碼、啟動與部署在獨立實作庫。此處不以研究文檔數、函式覆蓋率或單一實作可運作為完成指標。

## 新工作循環

1. S00 收到 Server 設計需求、既有實作回饋或規格缺口，建立可追蹤的 SPEC/GAP 項目。
2. T01 查既有原稿、精確 SHA、既有驗收與衝突，交付帶可信度的主張；**允許未取得全文 FULL-PASS 的材料作非已驗證線索**。
3. 缺少必要 Client 行為時，交 T02–T16 按功能定向研究。先用現有索引、原稿與資源；必要時再用 REA/Ghidra/原始 BIN。沒有 REA 的 Agent 仍可工作。
4. S00 將研究主張與**獨立的 Server 設計決策**轉成開發者可讀的規格。未知協定欄位必須保留 UNKNOWN/GAP，不能猜測原版協定。
5. 為可驗證契約建立 TEST 並審查版本、依賴與變更影響；公開發布規格需要維護者明確核准。
6. 獨立 Server 實作在自己的庫啟動與驗證。真正的規格缺陷以可公開的 FB 回流 S00；私人紀錄不得直接放到本公開庫。

## 角色邊界

- **T01：**來源收件、去重、證據查核、衝突和內部研究退回，不再預設逐篇全文重做。
- **T02–T16：**來源專項分析與證據、提供 server-impact；不替 Server 決定不可觀察的原版後端規則。
- **S00：**需求、規格、契約、狀態與測試索引的唯一發布責任者；不把設計決策冒稱原生事實。
- **實作 Agent：**在另一庫執行 Server、提交可重現但不涉及敏感資訊的規格回饋。

## 驗收分離

- **來源完整性：**SHA、blob、版本、有效來源路徑。機械驗證不證明語意。
- **研究證據：**保留原本精確範圍的 NATIVE_VERIFIED/PARTIAL/INFERRED/UNKNOWN/REFUTED；原稿 FAILED 不會自動復原。
- **規格成熟度：**DRAFT/REVIEWED/STABLE/DEPRECATED，與證據等級分開；STABLE 要有可追溯依據、無阻斷性未知、測試和版本審核。
- **Server 測試：**RUNTIME、CONFORMANCE、CLIENT_COMPATIBILITY 三者分開；不因某一種通過宣稱另外兩種通過。

## 明確不變項

保留所有歷史 318 版原稿台帳、舊退回、歷史 SHA、已發表的 `shared/verified-knowledge/`；現有 FULL-PASS 准入門檻不降低。T01 內部研究退回仍寫來源 Task README，不使用 GitHub Issues。沒有授權不執行/附加原版 Client、不變更原檔或研究原稿。現在不啟用對外 Issue/Discussions，不承諾受理外部回饋。

導入順序：A 工作制度與檢查器 → B T02/T03 規格與可重現測試 → C 獨立 Server 回饋閉環 → D 其他模組 → E 維護交接。參見 [S00](s00-workflow.md)、[T01](t01-integration-workflow.md)。
