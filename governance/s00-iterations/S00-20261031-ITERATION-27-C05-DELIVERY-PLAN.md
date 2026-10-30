# S00 Iteration 27 — C05 世界／教學戰鬥實作交接：真實 Server 基線、最短可驗收路徑與防 BUG 邊界

**日期 2026-10-31（Asia/Taipei）**。**規劃／未執行的開發交接**，不是 Server 新增程式碼、不是原版 KR Client 可玩或 native wire 結案。

## 0. 先核對實際兩庫，不重做 C03、也不假裝 C05 已開發

| 庫 | 2026-10-31 開工核對的 main（只代表當時快照） | 真正可引用的結果 |
| --- | --- | --- |
| 規格 `we88ec3-prog/ttr_anal_multi` | `5c1aac53faf4638c72a000f673ee04750fdcdf4c` | [Iteration26 的 Main CI](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41127783472) **SUCCESS**；E17-A～J/E18–26 有 [19-gate evidence overlay](S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json)，**仍不是 original Client runtime** |
| 實作 `we88ec3-prog/ttr_server_roy` | `c17a986fc66caca8af0efb72e2b42d1188e2a584` | [Server Actions](https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/41122572516) SUCCESS，C00–C03 有 **離線核心**；C04-A/B/C 只證受限原生形狀及離線檢查，C05 **仍 BLOCKED BY EVIDENCE** |

**真正存在的 Server 介面（本輪已核對 Git blob）**：`src/Tartaros.Character/IAtomicCharacterActions.cs` 的 `IAtomicCharacterActions.SelectAsync`、`GetSelectedAsync` 與 `LocalCharacterSelectionCoordinator`（同一資料交易與有效 C02 lease 檢查）；`src/Tartaros.Session/ISessionLeaseRegistry.cs` 的 `IsCurrentAsync`、`TryRenewAsync`、`RevokeAccountAsync`、`DisconnectAsync`；`src/Tartaros.Persistence/SqliteLocalDatabase.cs` 是**本地開發 SQLite schema v1**，`db/migrations/001..003` 為獨立 PostgreSQL migrations。需**新增**的 Encounter/Quest/Reward/Progress 交易介面並未因這些現有檔案存在就已實作。嚴禁把舊 `LocalCharacterService` 的非交易前置檢查直接當正式網路寫入權限。

**關鍵差異**：現有 C03 每個帳號可設定 **1～16** 個 Server-internal role slot（預設4），原版 KR Client 的 app0x2 role 索引高位檢查及 ID0 bitmask 風險需另議相容輸出政策；**不得把 Server DB slot 1..16 直接寫入 KR 角色清單，也不能稱官方合法 slot 範圍已證為 1..9**。迄今 `contracts/spec-revision.json` 仍 pin 舊 `dd69ec9...` 且 `implemented_wire_contracts=[]`；**本輪不修改 Server pin**、不替該庫的維護者批准任何 ADR。

## 1. 交付目標與工作分層

以 [Iteration25 Role/Progress/Session 規劃](S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md) 與 [Iteration26 Encounter/Quest/Exit 規劃](S00-20261031-ITERATION-26-COMBAT-QUEST-EXIT-PLAN.md) 為來源，建立可逐案驗收的 **9 個 C05 工作包**、[18 個新規劃測試](S00-20261031-ITERATION-27-C05-ACCEPTANCE.md)、[機器可讀交付矩陣](S00-ITERATION-27-C05-DELIVERY-MATRIX.json)。它們不是第二套正式 S00 REQ/RR/TEST 或 Server 程式庫已有的 C05 任務編號。

**分兩條可並行的執行路線**：
- **路線 D：Server 內部可實作**。以 SQLite/MockClient/測試資料先做安全的角色授權、Scene/Encounter lease、Actor/AI/Attack/Skill/Damage、Scenario Terminal、Quest、Reward、Tutorial Exit/重登；維護者須先核准必要業務 policy/持久化模型，或只做標明 PROPOSED 的離線 prototype。**不必等待原版 Server**。
- **路線 N：Client 原生相容**。T02/T03/T04/T05/T06/T07/T08/T09/T10/T14/T15/T16/T01 依既有來源補最短方向別 Client 封包／Scene/Actor/Quest consumer 及反例，整合後原版 KR Client 仍需**另行明確授權**才能隔離執行。此路線未完成不得打開 native codec/scene adapter。

## 2. S27-W01～W09：交接到實作庫的完整行為表

| 包 | 前置與模組（提案） | 最小可測成功 | 原版 Client 相容 gate |
| --- | --- | --- | --- |
| **W01 C03 seam** | 現有 `IAtomicCharacterActions`、`ISessionLeaseRegistry`；C03-C transactional selection 做正式 boundary | 絕不信任另一帳號角色或過期 SessionLease；舊 selected role 與 Server Scene admission 分開 | 角色 UI 0x42 / 原版 Server success/reject 尚未證 |
| **W02 Encounter Admission** | W01；Scenario/Instance/Role/SessionEpoch 和單次 Admission/EncounterId | 多次點選、雙連線、停權/過期拒絕或冪等；可撤銷的 encounter lease，不雙重建立關卡 | 原版 Scene/Instance 初始場景與 C2S40/Conn 未證 |
| **W03 Actor/AI/Movement** | W02；明確 **MOCK fixture**、Actor owner、spawn/wave/config revision | 可重現 Actor 出生/移除/移動、AI 及 tick，禁止虛構 Client 原版出生座標 | T08/T09/T05 原生 Actor/AI 封包、責任歸屬仍未知 |
| **W04 Attack/Skill/Hit** | W02+W03；Player intent、cooldown、skill resource、target | 重送不雙扣、不假傷害/死亡；錯 actor/target 與舊 tick 拒絕 | 真正技能列表、時窗、C2S/S2C、傷害公式由 T09/T10 |
| **W05 Objective/Settlement** | W04；Scenario14 或其他 mock 的目標 predicate、terminal CAS+outbox | 只能由明確 objective 成功；單次 Scenario outcome、崩潰後不重算勝利或重領 | CTutorial S2C0x4C map flag 不證 Quest14/Server reply |
| **W06 Quest Graph** | W05；Quest14/16/15 可用/接受/完成/交付狀態明分 | Quest14 turn-in 不因 Scenario success 自動完成，Quest16/15前置與 NPC/角色權限拒絕 | 真正 Quest status/人對話/回覆與 Reward type 意義未知 |
| **W07 Reward/Outbox** | W05+W06；Rewards 唯一 key、audit event、可靠 outbox | DB commit 一次、送出重試可重放而不雙倍發獎；SQLite/PostgreSQL transaction 不混同 | 不能將 Quest16 type2 value50 自行當經驗或金幣 |
| **W08 Tutorial Terminal/Exit/ReLogin** | W06+W07；進度 checkpoint、完成策略、世界出場 lease，SessionEpoch fencing | 停權不清進度、重登不倒退；已完成教程不等於正常地圖已可操作 | E25/E26 正常世界 client scene/Actor/UI 對應仍未知 |
| **W09 Native adapter admission** | W02+W05+W08；**SOURCE_GATED_NO_IMPLEMENTATION** | 必須具 exact KR SHA/Conn/dir/len/field/scene/error 與 runtime 授權，未通關則明確 UNSUPPORTED | 不准打開 KR/TC codec 或自行增加 `implemented_wire_contracts` |

**正式 S00/Server 的分界**：W01～W08 的 Server 願景是 **DOMAIN_OFFLINE_PROTOTYPE**（必要 ADR-0006/0007 批准前非 normative）；W09 是只規劃 admission/no-go 的「防火牆」，不因上游 mock 進度便可開發原生封包。各包都要能回傳 `Unsupported / PolicyUndecided / InvalidLease / Conflict / Rejected` 等**Server-internal** 意義；它們不是原版 S2C error code。

## 3. 具體資料一致性與 DB migration 決策表（不可直接照抄為原版 DB）

| 操作 | 一個必要交易邊界（提案） | 故障恢復必測 | 本輪特別防止的錯誤 |
| --- | --- | --- | --- |
| `ReserveEncounter` | 角色屬權＋當前 SessionLease＋Admission/Encounter CAS 在可靠儲存層下原子決議 | 斷線/ban、重送、兩裝置衝突 | 別把 C03 in-memory precheck 當 durable lock |
| `MaterializeMockActorSet` | Encounter revision + 唯一 ActorId／spawn event key | worker 重啟後不重複出生 | mock Actor ID 不要穿越到原版 Client wire |
| `CommitScenarioTerminal` | Objective verified → terminal CAS → outbox event 同 transaction；若採兩階段須有恢復策略 | commit 後未送通知/雙 worker settlement | 不因 Client 0x4C map/定時器輸入決定勝利 |
| `CompleteQuest* / GrantRewardOnce` | Quest revision/CAS + reward ledger unique key；跨表需 DB txn 或版本化 outbox/saga | crash at any commit point、相同 key、跨角色 key collision | 不把 Scenario settled 自動升格 Quest 或多發獎 |
| `ExitToNormalWorld` | TutorialProgress durable，Scene/World admission 另存 lease；Client observable readiness 非 Server-only 訊號 | 完成後斷線、scene adapter disabled、重登 | 不因 Quest15 available／資源 SceneList 將進度假設為離開教學 |

**Provider 約束**：目前 SQLite 本地 DB `user_version=1` 和 PostgreSQL migrations `001/002/003` **不是相同 schema**，應分別設計 additive upgrade、migration verifier、restore/rollback、非法版本拒絕與資料保留測試；不能默默改寫舊已登入資料表、把 PostgreSQL DDL 複製成 SQLite 執行，也不能讓普通 Host 啟動自動修復 schema。這是獨立 Server 維護者的批准項，不是 S00 已批准的 DB migration。

## 4. 同步規格與部署的入場規則：絕不以新計畫跳過 source pin

1. 開發分支建立時記錄 `ttr_server_roy` 正確 main SHA、`contracts/spec-revision.json` 的原 pin、當次 S00 的新 main 與所依文檔；不改原始 upstream pin 即開發**mock-only 模組**時，也必須標註其來源與 `SERVER_DESIGN_PROPOSAL` 身分。
2. 寫可進正式 Server 的業務規則前，審核 **ADR-0006**（per-role 教程政策/epoch）和 **ADR-0007**（Encounter/Quest/Reward）及營運者決策；未核准可先寫 isolated prototype/tests，不可宣稱 production policy。真正需 T02/T03/T07/T08/T09/T10/T14/T16 native 的 W09 則不能以 ADR 代替 Client 證據。
3. 每個 W01～W08 應交 `server_commit`、`schema_migration_version`、fixture hash、scenario/Role ID（不可記真帳密）、各 negative test、SQLite/PostgreSQL 驗收、崩潰測試、Session/Scene ownership、data restore 結果；一個未通過就報原本 Package 的 `BLOCKED/PARTIAL`。
4. C03/C04 已完成的離線契約不應重造另一份身份或角色表。W01 整合時重用「選角經 transaction 驗證有效 lease」原生 Server 介面。Original KR/TC frame codec 預設停用；不將 0x42選角、0x69/7 Square、0x40Scenario14、0x4C Lua map 端點任意配對。
5. C05 的進度報告採**兩軌**：`domain_mock_acceptance` 與 `original_client_compatibility`；不同軌必有不同 source/evidence，即使所有 .NET 測試 PASS，原版 Client 相容仍標 UNKNOWN/BLOCKED。

## 5. 交接矩陣、測試及下輪順序

- [W01～W09 機讀工作包](S00-ITERATION-27-C05-DELIVERY-MATRIX.json)：包含上游 Iteration26 原始 Git blob、實際 Server SHA/已存在的 5 個 Server 檔案 blob 快照、依賴／mock-only/native-no-go／測試與解阻證據；**CI 不會連線重新驗證遠端 Server repo，所以這是本輪讀取快照，不是自動持續同步**。
- [I27-T01～T18 驗收草案](S00-20261031-ITERATION-27-C05-ACCEPTANCE.md)：全部 **PLAN_ONLY / NOT_RUN**，無正式 `conformance/test-index.json` TEST；用兩個 case/包覆蓋 W01..W09。
- [唯讀檢查器](../../governance/check_s00_iteration27.py) 用 `--check` 檢查 JSON package/source snapshot/真實已登錄 ID、有向無環依賴、native OFF、未執行案例；GitHub CI 及負向 regression 只驗規劃本身，不能驗遊戲。
- **下輪值得直接做**：在獨立實作庫的 C05 開始 W01 transactional role/Session interface integration，W02 encounter mock＋W03 actors；同時 T02/T03/T05/T07/T08/T09/T10/T14/T15/T16 以既有 RR/GAP/Txx 只查 W09 需要的最短 source edge。真正實作/核准／跨庫更新要由 Server 負責人依既有工作流程另行執行。

**保留正式狀態**：ADR-0006/0007 PROPOSED，不新增已核准 ADR；RR-0002/0010 BLOCKED、RR-0008 IN_REVIEW（以當時主台帳為準）；`SPEC-FLOW-0001`/`SPEC-SCENE-0001` DRAFT/PARTIAL；C05 原版 Client 相容未宣稱完成；沒有執行原版 Client、Server 或 Source BIN。
