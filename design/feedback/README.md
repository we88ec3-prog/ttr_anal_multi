# 內部 Server 規格回饋

**當前不接收外部 Issue、Discussions 或其他人的問題回報。**

目前主要由維護者在自己的**獨立 Server 開發庫**記錄問題。只有當實際發現了可重現、可公開、確實屬於規格的缺口，才把最小必要紀錄登錄 `design/feedback/index.json`。本 Repository 是公開的，`FB-*` 不是私人資訊。

記錄 ID、受影響 SPEC 版本、Client 版本、預期/實際結果、重現步驟、去敏感化測試資料、問題類型（IMPLEMENTATION_BUG / SPEC_AMBIGUITY / SPEC_DEFECT / EVIDENCE_GAP / DESIGN_REQUEST）、S00/Txx 分流、解決條件以及修訂/測試連結。

實作 bug 應回原開發庫修復；協定未知由 S00 建 GAP 並送研究請求；設計有不同合理選項時建立 ADR。未來接手者如何啟用外部 Issues，請見 `governance/future-feedback/`。
