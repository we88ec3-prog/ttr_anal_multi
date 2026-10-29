# 相容性測試規格

`test-index.json` 初始為空；沒有任何已完成的規格相容性測試宣稱。Phase B 從 T02 framing 與 T03 登入/選角起，交付語言無關的輸入、預期結果、狀態前後條件、版本、來源/ADR 與例外。

三種驗收互不取代：`RUNTIME`（Server 真正能啟動）、`CONFORMANCE`（實作符合已發布測試）、`CLIENT_COMPATIBILITY`（有授權時測試原版 Client）。本庫僅發布契約與測試；實際 Server 程式碼獨立。
