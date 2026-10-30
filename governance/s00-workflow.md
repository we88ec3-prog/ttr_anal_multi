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


## S00：Server 需求來源與跨 Task 收件（2026-10-30）

Server 需求採用 [唯一 REQ 台帳](../design/requirements/README.md)，**並行三種發現來源**：程式碼逆向分析發現 Client 需要 Server 收發或狀態資料（CODE_ANALYSIS）、已另行明確授權的遊戲運行觀察（GAME_RUNTIME_OBSERVATION）、玩家/管理員實際提出的功能與營運要求（PLAYER_ADMIN_REQUEST）。同一需求多來源只追加 discovery，不另建同義 REQ；來源不等於 Client 原生保證或批准。安全、備份、權限、GM 稽核都屬玩家/管理員需求，不另設獨立來源。可考慮的實作整合回饋新來源仍**未核准**，既有 Server bug 用 FB 流程。新 T02–T16 程式碼研究若涉及新 Server 收發，先找 REQ，按原版 SHA/CLM 附有界證據，再分流 GAP/RR/SPEC/ADR。原版 Client 執行/抓包需要獨立明確授權，不能因需求台帳存在就啟動。

命令：`python -B governance/check_server_requirements.py --check`；詳見 [S00 本輪紀錄](S00-20261030-REQUIREMENTS-ORIGINS.md)。


## Iteration 11 — 分段優先與跨對話交接

以 [需求分段計畫](s00-requirement-slices.json) 和 [唯讀進度檢查](server_requirement_slices.py) 將三來源 REQ 協調成 `SLICE-LOBBY`（登入至角色畫面）、`SLICE-CREATE`（創角）、`SLICE-ENTER-WORLD`（選角後進世界）；僅是現有 B-* Roadmap 的需求分析視圖，並非新 RR 台帳或正式 B 里程碑升級。角色畫面與選角成功後轉場**不應誤當同一驗收**，但有 RR-0002 的 UI 初始化未知就保留阻塞。先問 [精確研究題單](S00-LOBBY-CREATE-RESEARCH-QUESTIONS.md) 而非猜任務／packet； [新對話交接](S00-NEXT-CHAT.md) 提供共同開工規則。`--check` 遇到 BLOCKED/DISCOVERY_REQUIRED 屬預期，只有 JSON/links/DAG 錯誤才 CI fail。


## Iteration 12／13 — Lobby 分段契約閘門

[Iteration 12 規劃](S00-20261030-ITERATION-12.md) 已按 L00–L08 拆開 Client 有界證據、未證 Server 責任及測試來源；[Iteration 13](S00-20261030-ITERATION-13.md) 使用 [同一 REQ/RR/GAP/SPEC 台帳派生的矩陣](s00-lobby-gates.json) 分別追 UI 就緒、登入跨線與創角 positive evidence。CLI `python -B governance/check_s00_lobby_gates.py --check` 僅檢查計畫內一致性，不能將原版 Client 相容或研究請求結案自動宣稱完成。12 個 L12-Txx 全部尚未執行且不建立正式 TEST 項，原版 Client runtime 仍需另行明確授權。新的共同交接入口維持 [S00-NEXT-CHAT.md](S00-NEXT-CHAT.md)。


## Iteration 21 — 創角契約的正式缺口／去重後派工

[正式分析與差異](s00-iterations/S00-20261031-ITERATION-21-CREATE-UI-WIRE-DISPATCH.md) 建立 `RR-0009`（E05：N=0/新增按鈕→Create UI 的本地 scene/dialog/event 正向入口）、`RR-0010`（E06：**Create** C2S 與匹配 S2C consumer／roster refresh），分別連至新 `GAP-CHAR-0002/0003`，研究 owner 均為 KR T03；T06/T04/T02 只提供既有職責內的跨 Task 介面。既有 `RR-0002` selection、`RR-0007` dispatcher、`RR-0008` selection→scene 不應被覆蓋或任意升級。新的 T03 inbox 由唯一 RR 台帳同步產生，只有 main 合併後供認領；沒有自動通知、沒有原 Client runtime 授權。SPEC-CHAR/FLOW 保留 DRAFT/PARTIAL。

## Iteration 22 — 管理員 WEB 後台以第三來源直接建 REQ（非 Client RR）

[WEB Admin V1／Iteration 22](s00-iterations/S00-20261031-ITERATION-22-ADMIN-WEB-V1.md)：使用者實際要求管理頁面新增玩家帳號、N 天／永久停權與解封。以 `PLAYER_ADMIN_REQUEST` 與去敏 [request record](../design/requirements/requests/2026-10-31-admin-web-account-operations.md) 寫入**唯一正式** REQ-0006～0008（CANDIDATE）；這是不同於 REQ-0001～0005 的 Server 管理產品需求。無 Client native source 就**不建 RR/CLM/原生 SPEC**；Server-only 的隔離 Admin 身分/RBAC/audit 與停權/fencing 決策編入 PROPOSED ADR-0004/0005。完整 API、DB、UI、25項 NOT_RUN 驗收於 `design/admin-web/`；未正式批准時只能作非規範設計，不可推論遊戲 Client 可登入、Server 已上線或 S00 相容性障礙已解除。


## 2026-10-31 RR-0010 研究來源合併與有限驗證

`extra/roy1` 透過 [PR #63](https://github.com/we88ec3-prog/ttr_anal_multi/pull/63) 合併來源研究 E71–E75，並由 S00 在 [RR-0010 逐條審查](s00-iterations/S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md) 核對有界 Client 路徑與已保存同版偽碼。**研究來源 Git merge ≠ RR SUBMITTED / S00 ACCEPTED / T01 FULL-PASS**。建名本地 producer `C2S0x3E`、候選 `S2C0x4A` local result、app2 共享名稱是可供 DRAFT 及 Server-only 模型的進展；原始 Server 配對與 playable-character roster 仍未閉合，故 `RR-0010 BLOCKED`／`GAP-CHAR-0003 OPEN`，完整開工仍依研究派工唯一台帳，不因 report 存在自動喚醒 Agent。本 S00 審查未執行原始 BIN 或 Client。


## 2026-10-31 Iteration 24：新證據→Spec 與 Server 實作邊界

E80 RR-0002 研究 [PR #67](https://github.com/we88ec3-prog/ttr_anal_multi/pull/67) 可幫助 [Iteration 24 開發交接](s00-iterations/S00-20261031-ITERATION-24-SELECTION-SQUARE-HANDOFF.md) 增補 C2S42(index/mode)/Square candidate，有真正 source-limited Client positive subchains；但 **RR-0002/0010 的原版 Server request-reply pairing 均未達完整驗收**。應先把新的 selection DTO、Session lease 與 stale/retry/error rollback 置於獨立 Server 模組的**設計假設／合成測試**，角色建立與選角各自保留正式 RR/GAP。任何新的 CODE_ANALYSIS REQ/CLM 需重新核對同版 source、T01 scope；目前不替換原始派工事件、不以 Git 合併驗收原版行為，也不強迫舊帳號重新做 Expedition create。


## Iteration 25：原版 Client 未閉合時仍可分層推進 Server 的 tutorial domain

[Iteration25](s00-iterations/S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md) 為 E10–E26 建立兩條獨立出入口：一條是 Server-owned per-role TutorialProgress、Session admission、checkpoint/Quest/reward 一致性，另一條是需要 T02/T03/T05/T06/T07/T14/T16/原版 Client 相容證據的 scene/Conn/控制可操作測試。前者以 [ADR-0006（PROPOSED）](../design/decisions/ADR-0006-tutorial-progress-and-session-fencing.md) 提案、MockClient 合成測試可先做；後者 native adapter OFF、未知處不得臆填。每次回報須分 DomainSynthetic、NativeStatic、CompatibleClientRuntime 與 OriginalServerCapture；CI 成功不影響 RR/GAP/SPEC maturity。


## Iteration 26：教學戰鬥與 Quest/Exit 的 source-locked 規劃驗證

承接 Iteration25，使用 [Iteration26 規劃矩陣](s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json) 作**非規範 planning overlay**，對原始 E17-A～J、E18–E26 保存一一對應的 evidence_state、blocking_unknown 與來源 Git blob；只加 proposed Server actor/encounter/Quest/reward/exit action。新增 `python -B governance/check_s00_iteration26.py --check` 與 CI/unit regression，不替代原版 BIN/Client 驗證。更動正式 RR/CLM/REQ/SPEC/TEST 仍須原始唯一台帳的 review/dispatch，且原版 Client runtime 另需使用者授權；ADR-0007 仍 PROPOSED。


## Iteration 27：從 S00 設計庫移交到獨立 Server C05 的「先讀真實程式」約束

[Iteration27 C05 handoff](s00-iterations/S00-20261031-ITERATION-27-C05-DELIVERY-PLAN.md) 與 [9-pack machine matrix](s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json) 直接 pin 實際 `ttr_server_roy` 的 `IAtomicCharacterActions/ISessionLeaseRegistry/SqliteLocalDatabase/contracts/spec-revision.json` Git blob 與 Server main 快照，確保不再重新規劃已完成的 C03 transaction/Session 類型。CI checker `python -B governance/check_s00_iteration27.py --check` **只在本庫驗證**來源/blob 字串、工作包依賴、18 個 NOT_RUN case/no-go 與 ADR 未批准地位；遠端 Server main 若變化，下輪應人工重新讀取，不能冒稱本次 CI 已同步。

Domain mock/prototype 可採並行研究和工程化測試，但正式業務 policy/migration 要獲 Server 維護者和 ADR-0006/7 批准；W09 native adapter 對未證 KR/TC protocol remains Unsupported/feature OFF，runtime 原 Client 測試另行授權。真 Server bug 走修復/FB/SFD 流程，S00 純設計不得改他人的部署庫或偽造已完成 Wxx。


## Iteration28：C03 原子交易對接 C05 Mock Encounter 的重要陷阱

[Iteration28 原子 W01～W03 規劃](s00-iterations/S00-20261031-ITERATION-28-W01-W03-IMPLEMENTATION-PLAN.md) 將實際 C03 `GetSelectedAsync`（只在**其自身 transaction** 內檢查 full SessionLease）與 C05 的後續 Encounter write 分離，要求**在建立 Encounter 的同一 DB transaction 再核對 exact lease/selected role/ownership**，防止重登/renew/revoke/ban 發生於兩次操作之間的授權 TOCTOU。SQLite 與 PostgreSQL 的交易、鎖順序、版本升級要分別批准與測試。Server-only mock 原型可先做，但使用者未授權原版 Client 運行、未核准 ADR、未填齊 wire/scene/Actor 正向證據時，不得使 native codec 成為可用協定。Machine checker `governance/check_s00_iteration28.py --check` 只驗規劃本身及保留的 source Git blob 身分，不是完成 C05 代碼。


## Iteration 29 — C05 Combat domain：Client input ≠ Server authoritative damage

[Iteration29](s00-iterations/S00-20261031-ITERATION-29-COMBAT-IMPLEMENTATION-PLAN.md) 延續 Iteration28 的同交易 full lease/selected-role/Encounter 授權，不許另一次 `IsCurrentAsync`/選角 check 後直接寫 Hit；攻擊/技能只是意圖，技能費用/冷卻/取消必須以 mock policy CAS 防重複，Hit/HP/Death 由 Server-authoritative event 同交易更新，ActorDeath 只交給下一個 W05 objective，不可直接改 Scenario14/Quest/TutorialCompleted。**C02-D 最新 SQLite local v2 停權及 Session revoke 也須在 combat mutation gate 被重驗**；不能推論 PG 同步實作。

`python -B governance/check_s00_iteration29.py --check` 僅保護本庫 source blob、E17-E/F/G 未升格、24 個 `NOT_RUN` 與 ADR-0006/0007 原提案狀態；無遠端 Server 程式碼執行、原版 Client 啟動或 GitHub API live snapshot revalidate。正式 REQ/RR/GAP/CLM/SPEC/TEST 需原唯一台帳審查，Server domain 需其維護者核准持久化與 cooldown/refund 規則，KR/TC 原生封包需同版正向來源及另行授權的 Client runtime。


## Iteration 30：原始 Scenario14 研究與 Server mock Objective 隔離

[Iteration30 設計](s00-iterations/S00-20261031-ITERATION-30-OBJECTIVE-SETTLEMENT-PLAN.md) 從 Iteration29 verified domain ActorDeath 開始，必須有 encounter/actor generation/DeathEvent 唯一鍵及 authority；原版 Client 的 Local Scenario `map[14]`、`IsScenarioEnded(14)`、S2C app0x004C 部分 handler **都不能直接構成 Server 成功條件**。Server domain mock 的 wave/objective 決策、終局 CAS、Outbox 與 Quest14 eligibility 四邊界需獨立 transaction/稽核；Quest14 completed/turned-in 必須另經 W06/NPC/Quest record writer 正向規格。出現真 source 差異要依既有 Task/RR/CLM 逐項去重、審查，不可直接修改台帳狀態。 `python -B governance/check_s00_iteration30.py --check` 是本庫**只讀規劃驗證**；不會驗證獨立 Server CI、真正原 Client Gameplay 或自動核准 ADR-0006/0007。
