# Tartaros Server 規格入口（S00）

**狀態：Phase A 試行，尚未發布正式相容性規格。**

這是獨立 Server 開發者的入口；任何語言都可以使用。既有逆向證據位於 `kr/`、`tc/`、`shared/`；規格中只引用，不要求開發者逐篇閱讀。實際 Server 程式碼、資料庫、部署不在此庫。

- [規格索引](spec-index.json)：以功能分類；DRAFT/REVIEWED/STABLE/DEPRECATED 與原生證據等級分離。
- [S00 工作流程](../governance/s00-workflow.md)：需求如何成為規格。
- [缺口索引](../design/gaps/index.json)：可能阻塞 Server 相容性的未知。
- [證據索引](../research/claims/index.json)：新式有限主張；既有嚴格原生結論仍查 [verified-knowledge](../shared/verified-knowledge/README.md)。
- [測試索引](../conformance/test-index.json)：只有有測試向量的規格才可能升級 STABLE。

目前 `SPEC-NET-0001`、`SPEC-CHAR-0001` 僅是**試行規格佔位符**，不是經驗證的完整封包格式。不得基於未知 opcode、欄位或回覆順序宣稱相容。

未來各模組會有獨立的規範文件，含 MUST/SHOULD/MAY、Client KR/TC+SHA、輸入輸出、前後條件、資料持久化、錯誤與序列、來源 CLM/ADR、測試及未知。歷史推論與自行設計的 Server 規則不得冒稱已證實原版實作。

尚未啟用外部 Issues/Discussions；規格回饋流程見 [設計入口](../design/README.md)。
