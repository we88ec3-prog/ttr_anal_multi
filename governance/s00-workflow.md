# S00 — Server 規格整合工作說明

**定位：**本庫的設計/契約維護工作線，不是 Server 程式碼的實作 Task。初期僅由目前維護者審核與發布；外部回報暫不受理。

## 讀取順序

1. `spec/README.md` 及 `spec/spec-index.json`：開發者能看到的正式狀態；索引存在不表示已發布。
2. `design/gaps/index.json`：阻斷相容性的未知。
3. `research/claims/index.json` 與 `shared/verified-knowledge/`：有限原生證據，先查歷史更正。
4. `conformance/test-index.json`：測試與適用版本；測試工具通過不是原生語意驗證。

## 每次需求處理

- **接收：**先判斷是規格缺漏、原生 Client 行為未查、Server 設計尚未決策，還是某個 Server 實作本身的 bug。
- **界定：**建立 SPEC-* 草案與 GAP-*；每個缺口寫明 KR/TC、影響、優先級、負責來源 Txx、解除條件。
- **索證：**如需新原生事實，用精確問題派給 Txx；不要要求將整篇文件重新全文 FULL-PASS，除非本次規格所依賴的精確主張必須深驗。
- **組裝：**各條 MUST/SHOULD/MAY 要能追到已核實的 Client 主張、或明示為 Server 設計決策 ADR。Client 原生協定與自訂後端演算法分離。
- **驗收：**版本、必填輸出、時序/狀態、異常處理、unknown、引用及相容性測試。UNKNOWN 的 Client 必要欄位不能升 STABLE。
- **發布：**只有明確維護者審核才發布新規格版本，保留變更、影響測試與舊版本；不因填滿索引就自動發布。

## 必須交付

- `SPEC-*`：版本、適用 Client SHA、明確可實作的外部契約、證據、ADR、TEST、GAP 及未知。
- `ADR-*`：純 Server 決策理由、替代方案與是否規範性；不能假稱官方原版 Server。
- `GAP-*`：未知類型、阻塞等級、解除條件和 owner；解析完才關閉。
- `TEST-*`：輸入、期望、適用版本、來源/設計決策；未經實測的向量標記草案。
- `FB-*`：可公開的最小問題回饋，先分辨實作 bug 與規格缺陷。

## 第一批試行

限定 T02 封包 framing 與 T03 Session/角色清單/選角。可先有 **DRAFT 規格與明確 GAP**，不能填入未被查證的 opcode、layout、回覆順序。獨立於 REA 與程式語言。後續將這兩個 SPEC 變成可獨立實作的契約才算 B 階段完成。

參考：[工作流程](workflow.md)；[T01 的接口](t01-integration-workflow.md)。
