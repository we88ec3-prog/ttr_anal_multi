# S00 Iteration 30 — Scenario14 目標與波次、唯一結算、可靠事件與 Quest14 邊界

**2026-10-31 Asia/Taipei｜規劃完成範圍：Server-owned MOCK DOMAIN ONLY；驗收：24 項 PLAN_ONLY/NOT_RUN。** 不是原版 Tartaros Client/Server 已可操作或原生協定被驗證。KR 分析目標 BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 1. 開工基線與防誤判

- S00 `we88ec3-prog/ttr_anal_multi main=295b53b003f93e41d7281f94b98d158f06302bb1`；[main CI #41134506321](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41134506321) **SUCCESS**，**只是規格台帳/離線 Python 測試**。
- 獨立 Server `we88ec3-prog/ttr_server_roy main=272079cc69b124870af303d711931ec20bce2229`：本次已檢視其 commit/實際檔案，最新進度是 **C00-OPS 離線 SQLite 維運 CLI**，不是 C05 世界/戰鬥。該 SHA 的 GitHub Actions 在首次核對時仍 `in_progress`，**不可聲稱其最新 CI 已成功**。既有 C02-D local SQLite ban/audit 是 v2，C03-C 有交易式角色選擇，C04-A/B/C 是局部離線協定形狀；C05 combat/world 仍未實作。本輪僅在 S00 保存該 GitHub read-only snapshot/檔案 blob，CI 不會連線重新同步 Server 最新 main。
- [Iteration28 S28-01..03](S00-ITERATION-28-C05-W01-W03-CONTRACT.json) Encounter/Actor/AI、[Iteration29 S29-01..04](S00-ITERATION-29-C05-COMBAT-CONTRACT.json) authoritative action/cast/Hit/HP/Death，都只是**未在 Server repo 開工的建議契約**。不能跳過它們，直接聲稱 S30 已有真正擊殺輸入。
- [Iteration27 S27-W05](S00-ITERATION-27-C05-DELIVERY-MATRIX.json) 為目標/唯一結算的原工作包；本輪細化為 S30-01～04，**不另建正式 Server REQ/RR/TEST/GAP 或改動 Txx owner**。原 [Iteration18 E17-H/I/J](S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json) 和 [Iteration17 E18/E19/E20](S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json) 的 evidence/blocker 狀態保持原樣。

## 2. 正確因果：ActorDeath → Objective → Terminal → Outbox／Quest14 eligibility

```text
S29-authorized COMMITTED Hit / HP=0 / unique ActorDeathEvent
  -> S30-01 (valid Encounter/ActorGeneration + event inbox)
     -> S30-02 (mock wave/objective predicate + failure precedence)
        -> S30-03 (one Terminal CAS + audit + outbox intent in transaction)
           -> S30-04 (durable at-least-once delivery with consumer dedup)
             -> W06 Quest14 eligibility fact ONLY
               != Quest14 COMPLETED / TURNED_IN
               != Quest16 unlocked
               != Tutorial COMPLETED
               != native Client map[14] or control-ready
```

*有助釐清的 Client 部分證據*：
- 局部 `Tutorial.RequestStartScenario(14)` Client C2S builder 具有 `40 00 0E 00`；但沒有完整可信的官方 Server Request→S2C response causality。
- `CTutorial` S2C app `0x004C` consumer 能令本地 `map[scenarioId]=1`，`IsScenarioEnded(14)` 可能據此解除 Lua 等待。**這不證明原始 Server 在真實 Scenario14 成功時送哪個 frame/Conn、也不表示 Quest14 已完成。**
- `QuestInfo.xml` Quest14 NPC10027/type3 以及 `CompleteAction` 和 Quest14→Quest16→Quest15 靜態依賴，不是原版 Server 任務交付、獎勵或教學終局已正向閉合的證據。

## 3. S30-01 — Verified Death inbox，不收 Client 自報殺怪

**擬新增（未實作）** `RecordAuthorizedActorDeathAsync(EncounterId, DeathEventId, ActorId, SourceActionId, AggregateRevision,...)` 與 `ReadObjectiveProgressAsync`。輸入必須連回 S29 Hit/Death 已 commit 且合法 Actor HP=0 的 domain state；不可接受 Client 直接 `monster_dead=true`、自行判傷、Scene/Actor handle 亂填、或同名怪物跨 Encounter 的事件。

唯一鍵至少 `EncounterId + DeathEventId + ActorSpawnGeneration`，在同 transaction 驗 actor ownership、wave/config、Client Session/role 或**經維護者核准的 Server-owned processing lease**、事件 fingerprint 與 objective version。重送相同有效事件可 Replay，重用 EventId 卻更改 actor/結果必 Conflict；HP/死亡狀態必已持久化，否則拒絕。這裡的 actor generation、wave 與 event 欄位是 Mock Domain 提案，**不是原版 Tartaros 物件 ID**。

## 4. S30-02 — 目標／波次狀態機與勝敗優先序

```text
MOCK ENCOUNTER ACTIVE
  WAVE_CONFIGURED -> WAVE_ACTIVE -> WAVE_COMPLETE -> next WAVE_ACTIVE
  (source: configured mock Actor roster + verified death set)
  FINAL_WAVE_COMPLETE + all optional mock prerequisites -> OBJECTIVE_SUCCEEDED_CANDIDATE
  explicit mock failed-condition + approved deterministic precedence -> OBJECTIVE_FAILED_CANDIDATE
  never "timeout -> success" or "client map[14] -> success"
```

- 所有波次/殺怪數/目標/逾時/失敗條件都由 fixture config hash+version pin；只可用**可重現的虛構怪物配置**測試，禁止填入猜測原始 Scenario14 敵人數、出生座標/HP、NPC 與勝負門檻。
- 應保存 `EncounterId/SceneKeyMock/ConfigDigest/WaveId/WaveRevision/ObjectiveRevision/requiredActorGenerations/verifiedDeathIds/ServerTick`。新波只在前波合法完成且 CAS 成功後產生，重試不 spawn 第二波。
- 同 tick 有最後一擊與逾時/abort，必由**已核准 mock fixture** 明訂 deterministic precedence（例如按 terminal failure 類型先比，再依 tick/sequence）；不能以 thread timing 生成不同結果。
- 超時只能依 policy 判定 FAIL/ABORT 等，不可「計時完成即勝利」；未決 policy 要 fail closed `PolicyUndecided`。

## 5. S30-03 — 一次性勝敗結算與資料一致性

`CommitMockScenarioTerminalAsync(EncounterId,ExpectedRevision,ObjectiveDecisionId,...)`：只有**已保存且合法的 Objective decision**才能產生 `SUCCEEDED/FAILED/ABORTED`；不可由遊戲動畫、Lua flag 或 Client 假 success 判斷。

建議以一筆 transaction 將 `Encounter ACTIVE→TERMINAL` CAS、`TerminalKey Unique`、Objective proof hash、actor/wave/scene revision、audit 和 outbox event intent 一起提交；若因技術限制需 saga，必另外批准完全等效的 exactly-once **DB effect**/復原策略。不能把 **outbox 網路傳送**說成 exactly-once。已存在終局一律不可改第二種結果，也不可用不同 `SettlementKey` 產生第二次成功；不同 key 的重複終局應 Conflict 或返回不可變記錄，**不能再發新獎勵**。

真正的 `Quest14 completion`、交付、Quest16、TutorialCompleted 並不屬 Scenario terminal 的單筆自動結果；這部分在下一階段 W06/W07 額外授權/持久化策略處理。

## 6. S30-04 — Transactional Outbox 與 Quest14 eligibility（非完成）

- `mock_domain_outbox` 保存一個穩定 event key/payload version，`consumer_inbox` 記錄去重。網路/handler 只保證**可重試投遞**，並非 exactly-once TCP。Crash 後由可恢復 outbox 繼續交付，**不重新 commit terminal**。
- Native KR/TC adapter 必維持 `Unsupported/feature OFF`：此模擬 `ScenarioTerminal` 不代表已證需要生成原版 `0x004C`，也不可臆造 `C2S40→S2C4C` 順序或 scene/Conn。
- 對 W06 Quest14 只能提供**獨立驗證的候選 eligibility fact**；Quest 的 AVAILABLE/ACCEPTED/COMPLETED/TURNED_IN、NPC10027 與 Quest16/15 解鎖各有自己的前置條件，不可「打贏即完成 Quest14」。
- Deliver/retry/backoff/dead-letter/reconciliation 以及 disconnect/ban 後是否投遞內部事件是 Server own policy，需要與 ADR-0006/7 共同核准；**不能用外部訊息驅動玩家的 Quest/Reward 未授權變更**。

## 7. DB 與維運工具契約（不可修改正式環境）

| 項目 | 現有 Server 真實快照 | 待實作（均提案、未建表） |
| --- | --- | --- |
| SQLite | local **user_version=2**（C02-D ban/audit）、C00-OPS `status/check/backup/restore-new/prune-sessions` CLI | 若持久化 Objective/Settlement，候選 v3 migration、schema checker、相容已存在 C02/C03 資料及備份/還原 smoke |
| PostgreSQL | 001–003 C02/C03 帳號選角遷移 | 新增候選 migration004，transaction/row-lock/unique constraint/restore CI；不能假設已擁有等同 SQLite C02-D 的停權功能 |
| mock domain | 目前沒有 C05 actual domain tables | `mock_objective_progress`、`mock_wave_progress`、`mock_death_inbox`、`mock_scenario_settlement`、`mock_domain_outbox`、`mock_consumer_inbox` |
| 安全 | 現有原 Client profile fail-closed | Domain-only mock fixture，沒有新的 native opcode、暴露 port、公開 admin API；無 production data |

**避免資料庫誤升級**：Server 維運 `restore-new` 是安全的離線演練工具，並未自動驗 C05 新表；未來新增 migration 時要自行擴充 schema verifier、一次性 terminal/consumer dedup 檢查與 crash/recovery 測試，不能因現有 C00-OPS 檢查通過就宣稱 W05 域邏輯有效。

## 8. 下游 Server PR 切片、研究缺口與驗收

| 建議 Server PR | 新工作包 | 設計測試（**NOT_RUN**） | 主要 source 阻塞 |
| --- | --- | --- | --- |
| **C05-P8** | S30-01 Validated Death Inbox | [I30-T01～06](S00-20261031-ITERATION-30-ACCEPTANCE.md) | T12/T08/T14 原 Hit/Death/Actor 因果不閉合 |
| **C05-P9** | S30-02 Wave/Objective predicate | I30-T07～12 | T14/T07/T08/T16 原 Scenario14 波次/勝負未知 |
| **C05-P10** | S30-03 Terminal CAS/Audit | I30-T13～18 | T14/T16/T02/T07 S2C0x4C 真 sender/result 不明 |
| **C05-P11** | S30-04 Outbox + Quest14 eligibility seam | I30-T19～24 | E18/19/20 Lua/Quest14 writer/交付不明 |

[四個工作包機讀契約](S00-ITERATION-30-OBJECTIVE-SETTLEMENT-CONTRACT.json) 包含 5 份上游規劃/evidence gate Git blob、7 個原生 Gate 的原 evidence/owner/blocker、7 份 Server source snapshot 及 24 個全 `NOT_RUN` tests；`python -B governance/check_s00_iteration30.py --check` 只做規劃驗證，不執行新 Server/.NET/Client。

**完成定義（未達）**：四個工作包的正式下游 PR、完整 DB migration、各 24 個真實 mock test、SQLite/PostgreSQL 針對新表/原資料的 backup/restore，**全都必須後續確實執行才可記成功**。獨立 Server 目前仍是 C05 BLOCKED/未實作。ADR-0006/0007 PROPOSED，所有原版 Client 原生正向協定/Runtime 邊界未被這次計畫升格。

下個 Iteration31 可接 W06 Quest14→Quest16→Quest15，以及 W07 RewardLedger/唯一發獎；必須等明確 Quest/Reward domain 政策與原 Client source 消費端補證，不能從 S2C0x4C 本地 scenario map 直接推斷。
