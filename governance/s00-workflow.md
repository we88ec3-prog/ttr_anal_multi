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


## 正式研究派工接口（2026-10-29）

S00 需要新 native 證據時，先查既有研究，若仍缺才在 [唯一 RR 台帳](../research/requests/index.json) 新增帶 GAP、owner_task、優先、明確驗收條件的 QUEUED 請求。產生 [T02–T16 收件箱](../research/dispatch/README.md) 並經 main 發布後，Task 開工時自行查閱、認領，按 CLAIMED→IN_PROGRESS→SUBMITTED→IN_REVIEW→ACCEPTED/NEEDS_REVISION 回報。S00 接受的是**某個研究請求的已交付範圍**，不自動升格原生 FULL-PASS 或 SPEC STABLE。需要原生嚴格複驗時回 T01，不代替其原有 README 退回流程。


## Phase B 收斂／Phase C 准入（2026-10-29 接續）

依 [S00 下一階段計畫](S00-NEXT-PLAN.md)、[工作包 JSON](s00-roadmap.json) 和 [訊息證據矩陣](../spec/session-account/phase-b-message-matrix.md) 對齊交付。每次開工先檢查 RR/GAP/SPEC/TEST，再執行 `python -B governance/check_s00_readiness.py`。只有具方向別封包、必需狀態、處理錯誤分支與測試來源的 *bounded* 契約可考慮 REVIEWED；不因 RR ACCEPTED、CI 通過或 Server 程式可編譯而自動 STABLE。真正實測原版 Client 另需使用者明確授權。


## 來源大量收件後的規格影響判定

T01 在 [本批首次新流程來源收件](../research/handoffs/t01-20261029-risk-intake/server-impact.md) 登記 318 個歷史版與 4 條新增 limited CLM。S00 不因 `REGISTERED/CONFLICT_CHECKED` 或既有 bounded native review 就直接寫成新 wire MUST；需逐條確認是否真正接到 Server-facing producer/consumer。若未形成特定消息、方向、狀態與 byte-range 的完整映射，作為研究導航，不升 SPEC_CONSUMABLE，也不關閉相關 GAP。

新的 [ADR-0001..0003](../design/decisions/README.md) 都只有提案地位；只有正式決議和必需的 Client 契約經驗證後才能寫入規範性規格。


## Iteration 05: conservative coverage and review guards

[Iteration 05 results](S00-20261029-ITERATION-05.md) add strict contract proof linkage (CLM → SRC), fail-closed non-synthetic TEST provenance, order-independent roadmap analysis and an auditable [RR review ledger](reviews/README.md). The latter mirrors a published S00/T01 review; `research/requests/index.json` remains the sole request state authority. None of these checks is original-Client compatibility proof or automatic SPEC promotion. Run `python -B governance/check_s00_reviews.py --check` with the existing S00 gates.


## Iteration 06: Phase B live intake without a second RR registry

[Read-only queue generator](phase_b_worklist.py) and [review protocol](PHASE-B-INTAKE-REVIEW.md) derive T02/T03 work scope and S00 source-to-spec impact from the existing RR/GAP/SPEC/COV/TEST and roadmap indices. They do not claim or resolve RR, awaken Agents, perform Client runtime testing or auto-upgrade SPEC. Use `python -B governance/phase_b_worklist.py --check`; review status is still determined only by the canonical request registry and human approval.


## Iteration 07: T01/S00 source review entry

The [RR submission preflight](phase_b_review_preflight.py) checks current submitted report path/blob identity and produces read-only, directly scoped SPEC/GAP/COV/TEST review questions. It never judges native semantics or upgrades contracts. Run `python -B governance/phase_b_review_preflight.py --check`; on `SUBMITTED/IN_REVIEW`, have T01 inspect source confidence and S00 decide the exact RR acceptance criteria. See [Iteration 07](S00-20261029-ITERATION-07.md).
