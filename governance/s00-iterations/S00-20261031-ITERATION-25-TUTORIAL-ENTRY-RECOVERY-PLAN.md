# S00 Iteration 25 — 首次教學入場、進度持久化、斷線恢復與重登

**2026-10-31 Asia/Taipei**。S00 非規範設計／開發交接，PLAN_ONLY / NOT_RUN；不是原 Client 實測或 Server 程式實作。KR 原件 SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。

## 1. 來源、驗證基線、不能越過的限制

- 開工 main=e9ec313b3d2cf0693134606d1e58f818c2f557ca，對應 [GitHub Actions #41124285391](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41124285391) SUCCESS；這只是 registry／離線驗證，**不是原版 Client 相容或玩法驗收**。
- [Iteration23](S00-20261031-ITERATION-23-EXPEDITION-ROSTER-PLAN.md)：Account、ExpeditionProfile、PlayableRole 分離；S2C app2 完整清單 65+53N、app2B 增量 2+53N 在 KR Client 寫同一角色記錄指標 F94304，並不證明原版 Server 一定按某個建角時序發送。
- [Iteration24](S00-20261031-ITERATION-24-SELECTION-SQUARE-HANDOFF.md)：C2S app0x42 4B（roleIndex+mode，觀察到 mode0/2）是選擇已存在角色；Client local scene+0xCC 可能未真正 queue 就置為 pending。另有條件式 S2C0x69 subtype7→CSquare／C2S0x43 路徑，**不能當作原版 Server 對 C2S42 的已證成功 ACK**。
- 產品 gate 承接 [Iteration16 E00–E12](S00-20261030-ITERATION-16-NEW-ACCOUNT-TO-TUTORIAL-PLAN.md) 與 [Iteration17 E13–E26](S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json)；不變更 E00–E26 編號、E17-A～J 子 gate，不修改研究者的原稿或派工者。資源 SceneList(1001,1)→tutorial_start 是 **Client resource locator**，不是已證網路 opcode 或首次登入政策。
- [ADR-0006](../../design/decisions/ADR-0006-tutorial-progress-and-session-fencing.md) 是本輪**僅提出、尚未批准**的 Server domain model。既有正式 RR/GAP/SPEC/TEST 保留原等級。

## 2. 核心修正：選角、世界就緒、教學進度是三種獨立交易

| 分層 | Server 自訂候選狀態 | 成功需具備的事實 | 不能用來假裝成功的訊號 |
| --- | --- | --- | --- |
| Session／角色入場 | AUTHENTICATED → ROLE_AUTHORIZED → SCENE_BOOTSTRAP_PENDING → WORLD_ADMISSION_PENDING → WORLD_READY | Server 帳號/角色所有權 + SessionEpoch/AdmissionId lease，且 Server 有明確世界 admission 決策 | Client scene+0xCC pending、Server 曾 queue S2C0x69、Client C2S0x43 出現都不保證真正世界可玩 |
| 教學 durable 進度 | NOT_STARTED → IN_PROGRESS → COMPLETED | CharacterId 上的 versioned state、Server domain checkpoint/合法完成及唯一 event key | 初次帳號登入、UI flag、Scenario14 local map、Quest15 available |
| Client 觀測層 | UNOBSERVED → SCENE_LOADED_OBSERVED → CONTROL_READY_OBSERVED | 經適當測試可追溯的同版 Client scene/UI/互動證據 | Server internal domain READY 或 mock Client PASS |
| Quest / Scenario / Reward | 各自獨立 source of truth | Quest14/Quest16 completion、Quest15 availability、reward granting 與離場分開判定 | S2C0x4C 的 Client local Scenario14 map flag ≠ Quest/整個教學完成 |

**預設原則**：每位角色的 TutorialProgress，與使用者帳號/遠征隊名稱/角色名單分離；首次「帳號 vs 角色」判定仍須維護者批准。Scene admission lease 是短暫連線狀態，不能在 crash 後被誤認為世界成功；世界初始座標和教學關卡號不能無來源硬填。

## 3. Server Domain-only 擬議介面（完全不聲稱原版 wire contract）

| 操作 | 必要輸入 | 原子性與回傳 | 失敗、重試、證據要求 |
| --- | --- | --- | --- |
| ReserveRoleAdmission | AccountId, owned RoleId/clientSlot, SessionEpoch, roleRevision, candidate selectionMode | CAS 領取唯一 AdmissionId/epoch；進入 ROLE_AUTHORIZED，保留入場租約而非立即動教程 | 無角色、停權、錯 owner、stale epoch、同帳號並行：拒絕或 fence；同意圖重送不 double spawn；mode2 語義未知 |
| DecideEntryRoute | RoleId + authoritative TutorialProgress/revision | NOT_STARTED→候選首次教學；IN_PROGRESS→候選 checkpoint resume；COMPLETED→候選 normal world | 這是 Server **產品路由提案**，不等於 Client 能處理某個 S2C 或 mode2=skip |
| BeginOrResumeTutorial | valid AdmissionId/epoch + RoleId + CAS revision | 首次原子 NOT_STARTED→IN_PROGRESS、已有狀態讀取 checkpoint；不依 Client UI event | DB/CAS conflict 重讀；scene 封包未被 Client 消費時 ClientReadyObserved 仍 false |
| AdvanceCheckpoint | Server-authorized domain event + legal predecessor + unique per-role event key | 進度版本單調、checkpoint/Quest/outbox 原子更新 | replay/out-of-order/old epoch 不可前進；出站重送只重送 outbox，不二次執行事務 |
| CompleteTutorial | 真正 Server 可驗證的 Quest/Scenario/exit prerequisites + unique completion key | durable COMPLETED、completedAtUtc；reward/Quest15 availability **另獨立原子決議/記帳** | 不能把 Scenario14 S2C0x4C、Quest15 available 或 Lua local script 當完成；半套 DB 寫入要 rollback |
| ExitTutorialToWorld | approved completion/顯式 skip policy + verified normal-scene requirements | domain handoff + role admission；另需 Client-ready 實測證據 | scene/resource/wire UNKNOWN 時 adapter fail closed，禁止以(1001,1)造包 |
| ReLoginReconcile | new SessionEpoch + RoleId + durable TutorialProgress | revoke/fence old lease、重讀 checkpoint／選擇候選 route，重建需要的 session-only state | old client ACK、重複 Scene/Quest 事件、同角色多連線不可覆蓋新狀態 |

建議邏輯資料：Account → ExpeditionProfile（可空）→ PlayableRole（account-bound）；RoleId → TutorialProgress(state,checkpoint,revision,startedAtUtc,completedAtUtc)、QuestProgress、RewardLedger；SessionLease(sessionId,epoch,roleId,admissionId,expiresAtUtc)；EventInbox(roleId,eventKey UNIQUE)、DomainOutbox(eventId,aggregate,deliveryStatus)。**均為新 Server 提議，不是原始 DB schema，也尚未編寫 migration**。若不能用單一 DB transaction 保護 Progress/Outbox/Reward，需明確 saga/reconciliation，不能假稱分散式 exactly-once。

### 安全與 WEB 後台的整合

- 角色只能由已登入且未停權的帳號控制；WEB 管理帳號停權必須 fence 其目前 Session/Admission，不清掉 TutorialProgress；解封後使用新的 SessionEpoch 恢復，不繼承舊連線授權。
- Server policy 的 role slot 初期 1..9 是防呆輸出候選；不能說是所有原版 KR Client 官方合法範圍。
- 客戶端不能直接送「教學完成、掉落已領、怪物已死」就令 Server 改 durable state；必須經授權且驗證的 domain event。
- 實際 Adapter 對未知 frame/Conn/scene/header/token/模式值 **預設關閉**，使用 FakeClient / domain test 和 native original-client compatibility tests 分開記錄。

## 4. E10–E26 的逐段交接

| Gate | Server 現在可以規劃/開發 | 原始 Client／Research 仍缺口 |
| --- | --- | --- |
| E10 | per-role progress route，首次／恢復／完成的候選分歧 | 原始帳號-first vs 角色-first 政策、mode2 真實動作、Skip 行為未知；T03/T04/T16 |
| E11 | 分開 source-backed resource lookup 和 Session/scene bootstrap | SceneList(1001,1)、0x565720 有非首次登入 caller，尚無 wire→scene key；T03/T06/T07/T16、RR-0008 |
| E12 | Server actor/world admission + runtime ClientReady 兩個不同回報 | original Client scene/control/UI-ready 不曾本輪測得；T04/T05/T06/T07 |
| E13–E15 | checkpoint、NPC 及演出／腳本前置表、失敗恢復 | Lua local UI/scene wait 不是網路確認、NPC 資源 id 不是 packet id；T05/T06/T07/T16 |
| E16 | ScenarioStartIntent 授權、去重、stale fencing | 既有局部 source 的 C2S 40 00 0E 00 只是 Client builder，非原版送達/回覆；T02/T07/T16 |
| E17/E17-A～J | Server 自訂 actor/spawn/AI/skill/hit/death/clear state machine（待逐子 gate 研究） | 不能把自製固定波次、血量或 0.75s 勝利當原版戰鬥規則；T05/T08/T09/T10/T14 |
| E18–E19 | scenario 結算與 quest/reward 分離；可靠 outbox 避免 Lua 永久卡住 | Client S2C0x4C local map[14] 不等於 Quest14/16 或整段教學結束；T14/T16 |
| E20–E22 | Quest14/16 progress、Quest15 available、一次性獎勵 | Quest15 可接 ≠已完成；NPC/腳本/Server 結果配對仍須追；T14/T15/T16 |
| E23–E26 | CompleteTutorial、Exit、ReLoginReconcile、normal world gate | 必須另證 exit scene/position/bootstrap；Quest/Server 狀態與原 Client 可見結果仍不等價 |

**最短實作順序**：SR23-01/02 角色資料 → SR24-01/02 角色所有權及 Session 選角 → SR25-01/02 role tutorial progress + epoch lease → SR25-03 route decision → SR25-04 checkpoint/quest/reward → SR25-05 feature-gated scene adapter。這些不能被描述為已完成的 Server 程式；要實作需在 ttr_server_roy 另開工作。

## 5. 可交付工作包與 D/S/R 證據

| WP | 接手模組 | 交付條件 | 驗證分類 |
| --- | --- | --- | --- |
| SR25-01 | Character / Persistence | Progress row per role、revision、unique event key、0/1/多角色/重登資料不流失 | DOMAIN_SYNTHETIC |
| SR25-02 | Session / Access | SessionEpoch + AdmissionId lease、並行、timeout、disconnect、ban/unban fencing | DOMAIN_SYNTHETIC |
| SR25-03 | Tutorial router | NOT_STARTED/IN_PROGRESS/COMPLETED 的三分岔、未知 mode 不跳關、重登恢復 | DOMAIN_SYNTHETIC + ADR review |
| SR25-04 | Quest / Rewards | scenario / quest / payout 獨立進度與去重；Scenario14≠Quest16/Quest15；rollback | DOMAIN_SYNTHETIC |
| SR25-05 | Protocol / Scene | feature flag OFF，版本/Conn/scene/Client resource 填不完整即不編碼/不送包；隔離測試才開候選 adapter | SOURCE_BOUNDED + FUTURE_CLIENT_RUNTIME |
| SR25-06 | Test | [Iteration25 16 項案例](S00-20261031-ITERATION-25-ACCEPTANCE.md)，全部 PLAN_ONLY/NOT_RUN；记录 expected/observed/commit/env | NOT_RUN |
| SR25-07 | T02/T03/T04/T05/T06/T07/T14/T16/T01/S00 | 沿 RR-0001/2/7/8/9/10 去重，定向找 scene→可操作→scenario/quest 結果與 exit chain | RESEARCH_REQUIRED |

## 6. 決策與發版邊界

需要明確 ADR 批准：首次觸發範圍（Account 或 Role）、是否可以 Skip／重玩、mode2 的 Client 真實含義、重連 checkpoint 的重播粒度、Quest/Scenario/獎勵結算原子性、誰可授權 GM 重置。**ADR-0006 = PROPOSED / NON-NORMATIVE**，並非維護者已批准，也不進入正式 SPEC 的規範性 adr_ids。

原版完整資料鏈（3E→4A→app2/app2B→B6→42→69/7→43→SceneList1001/1→Scenario14→S2C4C→Quest16）**並沒有被原版 Server 交易證實**；不能將局部 handler 拼接成必然順序，或以新的 Server MockClient 合成結果升格正式 RR/CLM/TEST。要宣稱 KR Original Client E2E，仍須經明確授權的隔離 runtime + 可稽核 scene/Conn/進度/畫面 trace。
