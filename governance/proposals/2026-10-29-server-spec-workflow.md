# Tartaros 分析與 Server 設計專案 — 新流程提案

狀態：**提案，尚未生效**  
日期：2026-10-29（Asia/Taipei）  
目標儲存庫：`we88ec3-prog/ttr_anal_multi`  
本文件為流程設計提案；**文件提交至 GitHub 不代表所提新工作規則已生效**。正式啟用須另行審議與更新相關規範。

## 1. 專案目的與邊界

### 1.1 公開設計專案（本庫）

本庫的最終產出是：其他開發者**不需自行重新逆向全部 Client**，即可依據文件實作自己選擇語言、框架和資料庫的 Tartaros Server。

本庫負責：
- 依 KR / TC 原始版本分開管理 Client 逆向證據、來源與不確定性。
- 發佈獨立於實作語言的 Client 協定、Server 對外行為、功能需求及狀態契約。
- 提供可攜、可重現的測試向量與相容性測試規格。
- 記錄缺口、設計決策、規格變更及所影響的依賴。
- 保留研究原稿、退回、矛盾、歷史 SHA，不將推論冒充原生事實。

本庫**不**以特定實作原始碼、資料庫引擎、程式架構、可遊玩程度或單一 Agent 的執行結果作為 Server 規格正確的唯一標準。Server 的實際執行、部署和完整程式碼放在另一個開發儲存庫。

### 1.2 獨立 Server 開發專案

目前由同一位維護者開發，但規格與實作要當成不同產品。開發專案依規格建置、測試、執行與回報實作阻塞。自有 Server 的 bug 不自動等於公開規格 bug；修正後只需回傳可公開的最小重現資訊與證據，不要求公開整份程式碼。

### 1.3 本階段社群政策

現在**不主動接收或處理外部問題回報**：不啟用面向外部的 Issues 招募或 Discussions；不在正式 `.github/ISSUE_TEMPLATE/` 部署對外受理模板。內部設計疑問可在獨立的**私人 Server 開發庫**記錄；只有已去識別化、可公開的規格問題才同步為本公開庫的 `design/feedback/`。注意本庫是公開 Repo，寫入本庫的「內部回饋」仍會被所有人看見，並不具保密性。未來有人接手，經明確啟用決策後再開放 GitHub Issues／Discussions 與外部貢獻；是否實際開啟 Issues 可由 Repository 管理者決定。公開 Repo 本身仍可能有人提出非正式聯繫或 PR，不承諾受理與回覆。

## 2. 工作角色與責任

| 工作線 | 責任 | 正式產出 | 禁止的責任混淆 |
| --- | --- | --- | --- |
| T01 研究整合 | 來源接收、SHA 去重、衝突偵測、可引用主張索引、退回處理 | `research/claims/`、來源及退回台帳 | 不再要求每篇都重新全文逆向才能讓 S00 使用；不替其他 Task 重寫原稿 |
| T02–T16 專項研究 | 解決指定的 Client／封包／資源問題，維持研究原稿與證據 | 研究原稿 + 結構化 `research-handoff` | 不代替 S00 制定 Server 架構或對未知原版後端臆造事實 |
| S00 規格整合（新設） | 將已知行為和開發需求組合成獨立、跨 Task 的 Server 規格 | `spec/`、`design/decisions/`、`conformance/` | 不將自訂 Server 決策標示為原生驗證 |
| Server 開發專案 | 建置、啟動、測試、除錯、回饋規格缺口 | 獨立 Repository 中的可運行程式及測試紀錄 | 不直接更改公開原生證據來迎合現有程式碼 |
| 目前維護者 | 裁決優先順序、重要設計決策、規格發佈與變更 | 核准的規格版本 | 不必逐行人工批准所有機械驗證結果 |

S00 可以由網頁 ChatGPT、桌面 Codex 或其他無 REA Agent 進行。REA 是研究工具，不是規格／Server 開發的先決條件。

## 3. 新工作流程（循環式）

```text
[Server 實作或規格覆蓋需求]
       ↓
[S00 立需求/缺口，指定受影響的功能和 Client 版本]
       ↓
[先查已發佈規格與 T01 主張索引]
       ├─ 足夠 → [S00 編輯／補充可實作規格]
       └─ 不足 → [Txx 定向研究：已有原稿→資源/靜態→REA/Ghidra/BIN→授權後動態測試]
                           ↓
                 [T01 接收證據、去重、發現衝突]
                           ↓
                    [S00 完成契約／設計決策]
                           ↓
               [conformance 規格測試／審核]
                           ↓
                     [發佈規格版本]
                           ↓
                 [獨立 Server 開發與測試]
                           ↓
              [內部設計回饋 FB → S00 分類]
                           └─ 必要時回到 Txx 補證
```

**研究停止條件：** 當特定 Server 契約的必填欄位、行為條件、版本範圍、異常路徑和測試已足夠且不存在阻斷性衝突，就先停止該方向的深入逆向；後續新問題才重開研究。不是等整個函式、整篇報告或全部 Client 分析完才可設計。

**現有禁令：** 原件與原分析資料保持唯讀；未獲另外授權不執行／附加原版遊戲、不修改 Client；Server 自身的獨立啟動／測試應明確在開發專案的測試政策中授權。需要 Client 動態測試時再單獨提出測試計畫，不因本提案自動放寬舊規則。

## 4. 證據與規格分層：不得混淆

### 4.1 研究主張 `CLM-*`

每條主張有唯一 ID、來源版本（KR／TC、原始 SHA）、來源原稿 Git blob SHA、精確位址／資源位置、主張、成立條件、反例／矛盾、證據等級及被哪些規格引用。

**證據等級：** `NATIVE_VERIFIED`（現行有界 FULL-PASS 標準）、`PARTIAL`、`INFERRED`、`UNKNOWN`、`REFUTED`。原生確認只適用於明確的範圍和條件，不能自動升格整份原稿。

### 4.2 規格 `SPEC-*`

每份規格獨立記錄：
- `spec_id`，標題，適用 Client 版本與原件 SHA。
- 對外的 Server 必須行為（**MUST**）、建議行為（**SHOULD**）、可選行為（**MAY**）。
- 客戶端輸入／Server 輸出、封包 schema、長度、端序、欄位含義、觸發條件、合法狀態、錯誤情境和時序。
- 服務責任、狀態擁有者、持久化需求、其他規格依賴。
- `evidence_refs: [CLM-...]`、設計決策 `decision_refs: [ADR-...]`、測試 `test_refs: [TEST-...]`。
- `unknowns`、`blockers`、最後審核與修訂版本。

**規格成熟度**與**證據等級**分開：`DRAFT → REVIEWED → STABLE → DEPRECATED`。`STABLE` 表示明確、可測、變更受控；不表示每個設計都由原版 Server 證實。未知的協定必要欄位不可偽裝成 Stable Client 相容契約。

### 4.3 設計決策 `ADR-*`

例如伺服器權威狀態管理、資料儲存與交易策略、未知原版後端規則下選用的行為。記錄：問題背景、候選方案、選擇理由、影響與取捨、所對應規格、是否強制。**如果只是架構建議，標成非規範性；不可強制所有獨立 Server 直接照搬。**

### 4.4 缺口 `GAP-*`

至少區分 `CLIENT_PROTOCOL_UNKNOWN`、`CLIENT_BEHAVIOR_UNKNOWN`、`SERVER_DESIGN_UNDECIDED`、`SPEC_CONTRADICTION`、`TEST_MISSING`。寫明阻塞的 SPEC、風險、優先級、研究擁有者及解除條件。

## 5. T01 驗收改革與歷史成果處理

現有 318 個凍結的原稿版本、3 篇有界全文通過、FAILED 舊稿及其他審閱狀態全部保留。**不重算為「全部完成」，也不要求 FAILED 原稿未來改成 PASS。**

### 新增「整合可用」而非放寬 FULL-PASS

- `REGISTERED`：來源版本與 SHA 已收錄，未決定語意正確。
- `CLAIMS_EXTRACTED`：已萃取可引用主張與限制，附證據連結。
- `CONFLICT_CHECKED`：與既有主張／版本差異檢查，矛盾已標記或裁決。
- `SPEC_CONSUMABLE`：S00 能以所標示的信心水平引用，不代表原生已驗證。
- `NATIVE_VERIFIED`：只有符合現有 FULL-PASS 條件的精確主張可被標示。

上述是**獨立的整合狀態**；既有 `FAILED`／`PARTIAL`／`SOURCE_ONLY`／`PENDING` 原稿驗收狀態不覆寫。

T01 不需要每篇全文手動驗收才讓資料進入 `research/claims/`。只有準備宣告原生事實、解決互相矛盾的高風險主張、或 Server 相容契約的關鍵欄位時才執行必要的深度原生驗證。驗證範圍是**契約／主張**，不是任意擴大到整篇文章。

保持原 Task README 的「T01 驗收退回事項」程序與舊 SHA 歷史。已有 `shared/verified-knowledge/` 保持嚴格准入，不降級標準。原批次驗證腳本只證明其聲稱的檢查範圍，不產生新的語意裁決。

## 6. T02–T16 的固定交付物

每次研究若產生會影響 Server 的新資訊，交付：
1. **原稿與證據**：完整技術記錄、原件／原稿 SHA、位址與可重現步驟。保留研究深度，但不要求把全部原稿複製到聊天。
2. **`research-handoff`**：3～10 條有明確邊界的 `CLM-*` 新主張或更正（數量依實際內容，非配額）。
3. **`server-impact`**：影響的 `SPEC-*`、欄位／時序／狀態、需修改內容和仍未知之處。
4. **`GAP-*`**：尚需 Client 補證或 Server 設計裁決的問題；必填解除條件。
5. **增量查核**：只對新增或被修改的主張、依賴與測試重新驗證。

來源研究不負責直接改寫正式 `spec/`；S00 整合和審核後發佈。防止多個 Agent 同時改動同一份對外規格。

## 7. 工具與 Agent 分工

1. **不使用 REA 的 Agent**：可閱讀 GitHub 說明、既有反編譯、函式索引、來源快取，執行 JSON/schema/索引驗證、設計規格與測試；不因無 REA 就停止 Server 開發。
2. **桌面 REA Agent**：僅處理 `GAP-*` 中確需原生分析的明確問題，優先定位指定函式、封包、資料流和 Client 狀態。交付證據與 `CLM-*`，而不是任意延伸下一百個函式。
3. **可使用 Ghidra/Capstone 但無 REA 的 Agent**：可用現有快取／腳本完成機械性與局部靜態驗證。REA 是便利入口，不是證據標準。
4. **Server 開發 Agent**：在獨立實作專案真正啟動服務、寫測試、暴露實作阻塞；公開設計專案只接受必要且可分享的最小回饋。

研究路徑：`現有規格和證據 → 原稿／索引 → 資源／靜態分析 → REA/Ghidra/BIN 對關鍵缺口補證 →（獲授權時）動態驗證`。BIN-first 不再是預設口號；需要原生強證據的相容性主張依然要有原件佐證。

## 8. 內部回饋（現在）與 Issues（未來）

### 8.1 現在：只用受版控的內部回饋檔

開發 Server 遇到問題時，先在私人開發庫追蹤。需要回流至公開規格時，經檢查無私有程式碼／帳號資料／敏感封包後，新增 `design/feedback/FB-0001.md`，內容：
- 回饋 ID、日期、狀態：`NEW / TRIAGED / NEEDS_RESEARCH / NEEDS_DECISION / FIX_READY / CLOSED`。
- 規格 ID／版本、受影響 Client KR 或 TC、預期與實際行為。
- 最小重現資料、可去識別化封包與日誌（不可上傳私密資料）。
- 類別：`IMPLEMENTATION_BUG` / `SPEC_AMBIGUITY` / `SPEC_DEFECT` / `EVIDENCE_GAP` / `DESIGN_REQUEST`。
- 分派目標：`S00`、`Txx` 或獨立 Server 開發專案。
- 若已結案：關聯 `CLM-* / ADR-* / SPEC-* / TEST-*` 與修訂版本。

這樣你自己可以測試規格是否真正可實作，又不必公開接受或回應外部 Issues。對外發佈資料只納入不含私有程式碼和敏感紀錄的部分。

### 8.2 將來：維護者決定才開放

現在預存於 `governance/future-feedback/` 的只是**草案**，不要提前部署 `.github/ISSUE_TEMPLATE/`。未來由新維護者明確完成：
1. 設置貢獻／回報政策與回應能力，決定是否在 Repo Settings 啟用 GitHub Issues。
2. 將回報模板部署到 `.github/ISSUE_TEMPLATE/`，再依需要啟用 Discussions。
3. 使用分類：`spec-defect`、`missing-contract`、`client-compatibility`、`evidence-request`、`design-proposal`；每件連結精確規格 ID、版本、證據和最小重現。
4. 由維護者初審，無論回報者為何人都不直接修改 `NATIVE_VERIFIED`；需要原生修正時交原 Task／研究工作線處理。
5. 在完成新版本規格、修正測試、建立變更紀錄後才結案。對外貢獻不是自動接受。

舊 `AGENTS.md`「不使用 GitHub Issue」仍適用 **T01 內部研究退回**；將來若開放外部 Issues，應明確限定兩種程序，避免互相衝突。

## 9. 建議目錄（增量新增，不搬移研究原稿）

```text
ttr_anal_multi/
├── README.md                         # 將主入口改為 Server 設計與規格
├── AGENTS.md                         # 全員與跨工作線規則
├── kr/ ...                           # 現有 KR 原稿、證據、Task，保持
├── tc/ ...                           # 現有 TC 原稿、證據、Task，保持
├── shared/verified-knowledge/ ...    # 原生 FULL-PASS 的既有嚴格索引
├── research/
│   ├── claims/                      # CLM 主張與來源交叉索引
│   ├── requests/                    # 按需研究請求
│   └── source-crosswalk.json        # 指向舊 Txx/原稿，不複製來源
├── spec/
│   ├── README.md                    # 開發者先讀這裡
│   ├── versions/                    # KR/TC 與相容性範圍
│   ├── protocol/                    # 封包與傳輸契約
│   ├── session-account/
│   ├── character/
│   ├── world-scene/
│   ├── entity-sync/
│   ├── combat/
│   ├── quest-reward/
│   ├── persistence/
│   └── spec-index.json              # SPEC ID、狀態、依賴
├── design/
│   ├── architecture/                # 非強制架構建議
│   ├── decisions/                   # ADR：已採用的設計決策
│   ├── gaps/                        # GAP：需要研究或決策
│   └── feedback/                    # FB：目前只由自己／內部使用
├── conformance/
│   ├── protocol/
│   ├── state-machines/
│   └── test-index.json              # TEST ID 與適用版本
├── governance/
│   ├── workflow.md
│   ├── spec-versioning.md
│   ├── release-checklist.md
│   └── future-feedback/             # Issues／PR 模板草案，暫不啟用
└── releases/                        # 已發佈版本索引及 changelog
```

**第一階段不需要一次建立所有模組內容。** 先建立流程、必要索引與 T02/T03 實際樣板；隨 Server 研究及設計擴充。

## 10. 最小規格範例（僅為模板，非已證實協定）

```yaml
spec_id: SPEC-CHAR-SELECT-001
revision: 0.1.0
client_version: KR
target_sha256: UNKNOWN
maturity: DRAFT
scope: 角色選擇請求與成功／失敗回覆
normative_contract:
  incoming_request:
    opcode: UNKNOWN
    layout_ref: UNKNOWN
  prerequisites:
    - valid_session # 作為待裁決的 Server 設計需求，不宣稱原版已驗證
  outgoing_response:
    sequence: UNKNOWN
  state_effect: UNKNOWN
source_evidence:
  - task: T03
    claim_id: null
    level: UNKNOWN
server_design_decisions: []
unknowns:
  - GAP-CHAR-SELECT-REPLY-001
required_tests:
  - TEST-CHAR-SELECT-001
```

規範性行為尚有 UNKNOWN 時不應宣告相容性 Stable；由 S00 逐步補齊。規格 JSON/YAML 的 schema 可另行制定，禁止沒有來源卻填入看似精確的 opcode 與預設值。

## 11. 品質保證與驗收

### 11.1 自動化驗證（本庫）
- ID 唯一且所有 `CLM / SPEC / GAP / ADR / TEST / FB` 引用存在。
- 每份已發佈規格有版本、適用 KR/TC、變更記錄與有效來源。
- `NATIVE_VERIFIED` 必須具備現行有界 FULL-PASS 依據與 SHA；機械校驗**不能自行產生**原生語意通過判定。
- 新的規格異動能找出受影響 `TEST-*` 與依賴規格。
- `STABLE` 的 Client 相容契約不存在未標示的阻斷性 UNKNOWN，且具有匹配的測試；未解阻塞需阻擋發布或正式降為 Draft/Experimental。
- 版本隔離：KR／TC 不互拷已驗證位址、封包欄位、資源 ID。

### 11.2 規格人工審核（S00／維護者）
- 其他開發者只看 `spec/` 與 `conformance/` 就能了解必須實作的對外行為。
- 明確區分已證實的 Client 行為、正式 Server 設計決策、可選架構建議與未證實假說。
- 協定欄位及時序一律追溯到證據；衝突已裁決或清楚標示為阻塞。
- 不因特定 Server 實作成功就反推官方 Server 的內部演算法。

### 11.3 獨立 Server 的實作驗證
Server 專案真正啟動和測試，分為三條：`RUNTIME`（程序可持續運作）、`CONFORMANCE`（符合已發佈規格測試）、`CLIENT_COMPATIBILITY`（在獲授權環境測得的原版 Client 行為）。**任何一項通過都不自動等於其他兩項通過。**

## 12. 規格版本與變更規則

- 初期版本可用 `0.x`，正式規範與相容性測試一同標記版本；不要拿 Git main 當不可變的穩定規格。
- 小幅澄清若不改行為，記錄修訂；封包 layout、必填時序、狀態轉移等破壞性變更必須提供變更說明、受影響規格／測試及升級指引。
- 內容修正保留原稿 blob SHA、反證、舊版決議，不靜默改寫已發布事實。
- 可選架構指南與規範性 Client 契約分開發布，避免無意約束多種獨立 Server。

## 13. 導入順序與完成門檻

### Phase A：治理與去瓶頸（優先）
交付：更新版工作規範草案、T01 新整合狀態定義、S00 權責、內部回饋流程。**完成門檻：** 能接收新研究而無須先全文審完，且不降低現有有界 FULL-PASS 標準；不更動舊史料。

### Phase B：第一條公開開發者規格
範圍：T02 Network framing + T03 Session／角色清單／選角的已知部分。交付：至少一份完整示例 SPEC、必要 GAP/CLM、測試向量、修訂與例外處理。**完成門檻：** 僅憑規格及測試，另一個與逆向隔離的 Agent 能實作已確認的子流程或清楚指出阻塞。

### Phase C：用你自己的 Server 作為第一個獨立使用者
Server 在獨立儲存庫啟動、開發、測試；發現問題寫 `FB-*`，由 S00 分流至改規格／設計決策／Txx 補證。**完成門檻：** 至少一個實際問題走完「發現→回報→裁決→規格／測試更新→Server 重新驗收」閉環。

### Phase D：擴充完整 Server 模組規格
依契約依賴與 Server 開發阻塞決定優先序，逐步擴至 T04–T16。另盤點背包、裝備、道具、經濟、隊伍／社交／公會、運維管理等既有 Task 未明確覆蓋的 Server 功能。**完成門檻：** 規格覆蓋矩陣與缺口表能回答「為完成某 Server 模組還缺什麼」。

### Phase E：將來維護交接（暫不啟用）
交付：維護者指南、規格發布流程、Issue 模板草案、分類和分流政策。**啟用條件：** 有新維護者正式接手且確認願意受理外部回報，再自行開啟 Issues／Discussions／外部 PR 流程。當前不承諾接受外部貢獻。

## 14. 建議追蹤指標

- `spec_ready_count / required_spec_count`：規格就緒程度（同時列出未盤點模組）。
- `protocol_critical_gaps`：阻塞 Server 相容性的未知封包與狀態。
- `spec_test_coverage`：規範性條款具備對應測試的比例。
- `unresolved_conflicts`：尚未裁決且影響已發佈契約的矛盾。
- `feedback_closure`：自己開發中發現的規格問題是否真的閉環。
- `runtime / conformance / client_compatibility`：獨立 Server 開發專案的三個真實測試面向。

保留 T01 原稿審核指標作歷史／稽核資訊，但不要再以「完成全部原稿 FULL-PASS」作為主專案成功條件。

## 15. 建議本次應先改的既有檔案（尚未修改）

1. `README.md`：公開定位、入口改為 Server 規格；原研究文件保留歷史入口。
2. `AGENTS.md`：新增 S00／Txx／T01 的清楚職責；「不用 Issues」限定內部研究退回；外部回報現階段暫不開放。
3. `kr/tasks/T01/README.md`、`kr/tasks/T01/task.json`：保留嚴格原生驗證的特定用途，新增來源快速整合與風險分流；不把舊 318 筆歷史覆寫。
4. `shared/T01-FULL-PASS-UNCLASSIFIED-INTEGRATION-RULES.md`：**保留**現有認證門檻，補上研究來源可供 `spec/` 以限定信心水平引用的規則。
5. 新增 `governance/workflow.md`、`spec/README.md`、`design/feedback/README.md` 與索引資料；不提前建立 `.github/ISSUE_TEMPLATE/`。
6. T02/T03 試行新增 `research-handoff` 與 `server-impact`；驗證格式後再推廣 T04–T16。

---

**總原則：** 本庫是一份有證據、有版本、有測試、能被第三方獨立實作的 Server 設計；REA 與 BIN 分析只在必要時補強契約；你的實作是第一個規格使用者而非唯一實作；外部 Issue 回饋在未來有人願意維護時才正式啟用。