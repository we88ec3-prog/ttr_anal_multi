# S00 Iteration 33 — C05-P01～P19 端到端 Server 開發整合與上線驗收門檻

**2026-10-31／規劃與治理交接，不是已實作。** 本輪將 Iterations28～32 的五份 mock-only contract 轉成完整 **19 個獨立 Server PR 的依賴圖、單一資料庫升版序列規範、八項待核准政策、七層 Release Gate 和 24 項預定驗收**。這份文件在 `ttr_anal_multi`，**沒有修改 `ttr_server_roy` 的原始程式**，沒有 .NET C05 gameplay / 原版 Client 真實 E2E，也沒有 original Server trace。

## 一、工作基線與可靠性界線

- **S00 規劃庫** `main=e1a3c383a046a0514f7eee983bc2fc3173c3a113`，[CI #41179316444](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41179316444) SUCCESS，成功範圍只有台帳檢查、離線 Python 與 source-pinned 規劃。
- **獨立 Server** `we88ec3-prog/ttr_server_roy main=272079cc69b124870af303d711931ec20bce2229`，[CI #41134733030](https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/41134733030) SUCCESS，現有功能：C00-OPS 離線 SQLite 維運、C02-D local ban／Session revoke、C03-C 交易式角色選擇、C04 來源有限的離線封包形狀驗證。C05 Encounter、Combat、Quest、Reward、World Exit **都尚未實作**。
- **S27 基底**：[Iteration27 C05 delivery matrix](S00-ITERATION-27-C05-DELIVERY-MATRIX.json) 九個 W01～W09；[Iteration28](S00-ITERATION-28-C05-W01-W03-CONTRACT.json) 3、[29](S00-ITERATION-29-C05-COMBAT-CONTRACT.json) 4、[30](S00-ITERATION-30-OBJECTIVE-SETTLEMENT-CONTRACT.json) 4、[31](S00-ITERATION-31-QUEST-REWARD-CONTRACT.json) 4、[32](S00-ITERATION-32-TUTORIAL-EXIT-RELOG-CONTRACT.json) 4 個 mock-only workpack，合計 19 個建議 Server PR。
- **KR Client BIN SHA256** `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。Native Client/Server 完整相容性並非因一個封包 handler 或 mock domain CI 通過而取得。E17-A、E17-J、E23、E24、E25、E26 的原 evidence/owners/blockers 在本輪 `source-blobs` 保持原狀。
- Server repo 的 `contracts/spec-revision.json` 仍 `implemented_wire_contracts=[]`；其 pinned upstream 並非 Iteration33。**S00 的 PR 不得替 Server 自動更新 pin，也不可直接幫 Source Gate 升等**。

## 二、19 個 Server PR — 必須遵守 DAG 而非僅看名稱順序

下表是**建議 PR 識別碼，不是已在 GitHub 建立的 19 個 PR**。每項應先有該來源工作包具體 API/schema/負向測試。標示 Pxx 為 C05-Pxx。

| Release 層級 | 建議 PR | 來源工作包 | 範圍 | 原子前置 PR |
| --- | --- | --- | --- | --- |
| R1 | C05-P01 | S28-01 | 原子角色/Session 授權與 Encounter 預約 | — |
| R1 | C05-P02 | S28-02 | Encounter 聚合、CAS 與重登恢復 | P01 |
| R1 | C05-P03 | S28-03 | mock Actor 生成、AI 與移動 | P02 |
| R2 | C05-P04 | S29-01 | 普通攻擊意圖與連段時窗 | P02、P03 |
| R2 | C05-P05 | S29-02 | 技能施放、資源與冷卻 | P04 |
| R2 | C05-P06 | S29-03 | 命中、傷害、HP、死亡唯一化 | P04、P05 |
| R2 | C05-P07 | S29-04 | 取消、Session fencing、combat crash/replay | P06 |
| R3 | C05-P08 | S30-01 | Verified ActorDeath inbox | P06、P07 |
| R3 | C05-P09 | S30-02 | Mock wave／Objective Predicate | P08 |
| R3 | C05-P10 | S30-03 | 唯一 ScenarioTerminal CAS／audit | P09 |
| R3 | C05-P11 | S30-04 | Durable Scenario Outbox＋Quest eligibility seam | P10 |
| R4 | C05-P12 | S31-01 | Quest14 eligibility／NPC turn-in | P10、P11 |
| R4 | C05-P13 | S31-02 | Quest16 available／accepted／completed／turned-in | P12 |
| R4 | C05-P14 | S31-03 | RewardPolicy quarantine／ledger／Outbox | P13、P11 |
| R4 | C05-P15 | S31-04 | Quest15 AVAILABLE／Quest 重登復原 | P13、P14 |
| R5 | C05-P16 | S32-01 | Per-role 教學終局資格／checkpoint | P10、P14、P15 |
| R5 | C05-P17 | S32-02 | SceneExitAdmission／transfer CAS | P16 |
| R5 | C05-P18 | S32-03 | Mock world-ready／原版 Client 觀測隔離 | P17 |
| R5 | C05-P19 | S32-04 | 重登、停權、斷線與跨模組 crash 恢復 | P16、P17、P18 |

**每階段 Release Gate（全為設計、NOT_RUN）：**

- **R0 治理準備**：先決定 Server 所有權、policy reviewer、C05 單一 migration allocator、實際 provider 版本、fixture digest、lease/ban/role CAS 鎖序和執行測試者。**不要求先證實原版所有封包才開始 Mock domain**，但拒絕把 Draft policy 當正式 Production semantics。
- **R1（P01～P03）Encounter/Actor**：用 C03-C selected角色＋current SessionLease 同 transaction 入場，Actor/AI 可重現、重複 spawn 和 stale epoch fail-closed，SQLite/PostgreSQL 各自 restore。
- **R2（P04～P07）Combat**：攻擊／技能只當 Client-like input、Server 自己計消耗/冷卻/命中傷害/死亡，取消與重登不雙扣/雙殺；**技能/傷害都是 MOCK fixture**。
- **R3（P08～P11）Scenario**：接受 verified ActorDeath、mock wave goal、唯一 terminal/outbox，Quest14 終局是另一個事件而非自動達成。
- **R4（P12～P15）Quest/Reward**：Quest14／16／15 分別擁有角色版本狀態、NPC/Role ownership、opaque Reward type2/value50 quarantine、一次性 Ledger/outbox；Quest15 AVAILABLE 不等於 ACCEPTED 或完成教學。
- **R5（P16～P19）Tutorial exit**：durable per-role tutorial checkpoint、SceneExitAdmission、mock Server WorldAdmission 和原版 Client 可操作是**不同狀態**；重登/停權/Outbox crash/replay 不重賞、不二次 spawn。
- **R6（獨立，非 P01～P19）原版 Client Native Adapter**：只有原版本 Client producer/consumer/Conn/scene/frame/欄位/錯誤分支完整證據、Server 明確接受該功能規格、授權隔離 runtime 後，才可逐項開 native adapter。**不得用 R5 mock PASS 直接升為 R6 PASS。**

除了 Pxx 前置之外，測試框架、migration manifest、fixture 驗證器與 read-only evidence review 可並行；但不能在依賴未具備時宣稱下一個 PR 已符合邏輯驗收。R1～R5 不表示可對原版 Client 開放連線，R6 也不是因所有 PR merged 就自動批准。

## 三、單一 C05 migration 配號與跨 Provider 相容政策（新增重大整合規範）

**已觀察的真實基線**：SQLite local `PRAGMA user_version=2`（C02-D local suspension/transactional revoke），PostgreSQL migrations 001～003（C03 selected role）。**未證 PostgreSQL 已擁有完全相同的 C02-D ban 功能**。Iteration28～30 曾分別把 SQLite v3／PostgreSQL v4 寫成相對當時的**候選下一版**；它們並沒有實際被套用，**不同工作包不得各自使用同一版本號建立不同的資料表**。

因此：**Iteration33 不分配任何新數字版本，也不新增 migration 檔。** 後續由獨立 Server repo 建立一個經授權的、append-only 的 `C05 schema release manifest`，其中每一條 migration 至少保存：
`provider, version_or_sequence, module, owner, depends_on, file_path, sha256, applied_state, verified_schema_hash, revert/restore_plan`。

配號流程：
1. 在實際 `ttr_server_roy main` 讀 SQLite `user_version` 和 PostgreSQL `schema_migrations` 真實最新版本，對比該版 release manifest；不能僅看 S00 提議。
2. 將 Encounter→Actor→Combat→Objective→Quest/Reward→TutorialExit 的 schema dependency 以一張 DAG 配號；同 provider 的 version **唯一且不可重用**，並固定 migration content digest。
3. CI 必須針對 SQLite local & PostgreSQL **分別**驗 `fresh create`、`v2/003 upgrade`、`mixed old/new process rejection`、`unique CAS/ledger/outbox`、`crash during migration`、`backup/restore-new/reopen` 和現有 C02/C03 帳號/角色／Session 過期/停權/復權。
4. SQLite 可以使用已建的 C00-OPS `status/check/backup/restore-new` 作為**離線備份工具**，它本身不會替未實作的 C05 表驗 schema；DB 的正式環境升版另需部署維護窗口與回復策略。
5. 移轉序列尚未批准時，本規格的 `sqlite_next=UNALLOCATED_NOT_APPLIED`、`pg_next=UNALLOCATED_NOT_APPLIED`。多個 PR 的 placeholder DDL **不能自動建立同版 schema**。

## 四、八個產品與安全政策決策點（需要 owner 核准，不能等同原 Client 事實）

| Decision | Owner | 尚未核准的選擇 | 未核准時 default |
| --- | --- | --- | --- |
| D33-01 | Server maintainer | 角色 vs 帳號的 TutorialProgress，首次入場和 Resume | Mock-only/fail closed |
| D33-02 | Server maintainer | Encounter 重登續玩/abort、Scenario 失敗優先序／唯一 terminal | Mock-only/fail closed |
| D33-03 | Server maintainer | mock cast 取消／退款／冷卻起算／命中算法 | Fixture only，**非原版技能** |
| D33-04 | Server maintainer | Quest14/16 NPC/轉移/交付、Quest15 Available 前置 | 不自動改 Quest |
| D33-05 | Server maintainer＋研究者 | `Reward type2,value50` 原語意以及產品 payout mapping | `REWARD_POLICY_UNRESOLVED`、不入帳 |
| D33-06 | Server maintainer | TutorialCompleted 與 SceneExit 的先後、世界目的地/轉場補償 | `PENDING`，不宣稱 WorldReady |
| D33-07 | DB release owner | provider 升版唯一序列、lock ordering、restore | 不啟用 C05 schema |
| D33-08 | Client research owners | 同版本原生 packet／world／quest／relog 正向證據與 runtime | Native adapter OFF |

正式 **ADR-0006/ADR-0007 仍為 PROPOSED/NON-NORMATIVE**。如果後續產品批准其中某一項，應由有權 maintainer 留下記錄、更新 Server policy revision 和來源，分別標示 `DOMAIN_SERVER_CHOICE` 與 `KR_NATIVE_SOURCE`，不得只因引入 mock fixture 而把原版封包/數值寫成官方規格。

## 五、跨模組共同不可破壞的交易與安全規則

- Authoritative DB transaction 內要同時確認 `SessionId+AccountId+ConnectionId+Revision+ExpiresAt`、selected owned role、帳號 suspension（**SQLite local**）、Encounter/Quest/Scene CAS、payload fingerprint；不能先獨立 `IsCurrentAsync`/GetSelected 再在另一交易自由寫入進度。
- `EncounterId/ActorGeneration/ActionId/DeathEventId/SettlementKey/QuestTransitionId/RewardGrantKey/AdmissionId` 的不同範圍均需自己的唯一索引與 idempotency policy。**Client 回傳 HP/死亡/勝利/任務完成/世界 ready 都不得直接變成 Server 權威。**
- Durable credit/terminal/quest effects 最多提交一次；Outbox 可以至少一次傳遞，須 consumer inbox 去重，不能宣稱 exactly-once TCP。
- 斷線／renew／login claim／ban 讓舊 lease/epoch 不能再改已持久化結果，unban 不能復活舊 Session。崩潰恢復只能讀回已提交 state 或按已核准補償，不能重複 RewardLedger/Spawn/Quest。
- **原生 Client 不可誤升格**：`CTutorial app0x004C local map[14]`、`Quest15 AVAILABLE`、Lua `LoadMap town001D`、`C2S0x42/S2C0x69/C2S0x43` 局部消息、`scene+0xCC` pending、R5 Mock WorldDomainAdmitted，**都不直接證明原版 Client 已載入場景且可自由移動**。

## 六、24 項整合驗收（都尚未執行）

[完整 24 項測試／Release Gate 對照](S00-20261031-ITERATION-33-ACCEPTANCE.md) 分為 R0 source/政策/migration（I33-T01～04）、R1 Encounter（T05～08）、R2 Combat（T09～12）、R3 Scenario（T13～16）、R4 Quest/Reward（T17～20）、R5/R6 Relog/world-ready/native release（T21～24）。這些是跨模組整合案例，**不取代** Iterations28～32 各自原有的 16、24、24、24、24 個未執行分項測試。

**真實驗收報告欄位**：`s00_spec_commit`、`server_commit`、`pr_id`、`migration_manifest_digest`、`provider/current_version`、`policy_revision`、`fixture_digest`、`session/role/encounter/quest/scene/ledger_keys`、`test_id`、`expected`、`actual`、`result`、`evidence_class`、`known_native_gap`。只有在**真執行** Server .NET/SQLite/PostgreSQL CI 且附 trace 時才可報 DOMAIN_SYNTHETIC_PASS；需要原版 Client 的 Gate 僅能在獨立授權後驗收。

**來源圖**：[Iteration33 19-PR machine contract](S00-ITERATION-33-C05-INTEGRATION-CONTRACT.json) pin Iterations27～32 六份來源與原 E17-A/J/E23～26 gate evidence 及 Server 八份 read-only Git blob；`governance/check_s00_iteration33.py --check` 的範圍只驗來源、DAG/覆蓋率、現有版本與禁止升格條件，不會檢查遠端 Server 當下 HEAD 或執行 original Client。

## 七、下一步真正落地應如何開始

Server 實作 owner 可以**先完成 R0 的政策審查、C05 schema allocator 及 P01 的 transactional role admission**，再照 DAG 開發 C05-P02～P19；若 original Client static 分析仍有缺口，保持 native adapter disabled，但持續進行可獨立測試的 mock domain 工程。

如果進入下一次設計 Iteration34，建議只處理獲核准的政策或真正在 Server 產生的實作／測試反饋，不要為了延長迭代反覆建立同類規劃。**目前 C05 的 19 PR 都屬「待開發」而非已提交的實作成果。**
