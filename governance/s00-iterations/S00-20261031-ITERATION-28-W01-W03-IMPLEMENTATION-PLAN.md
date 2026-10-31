# S00 Iteration 28 — C05 W01～W03：可直接交給 Server 實作的原子入場、Encounter、Actor／AI 契約

**2026-10-31（Asia/Taipei）**｜**非規範 Server-domain 設計／未執行測試**。**並未修改或執行 `ttr_server_roy`**，並未執行原版 Client。KR 原始檔 SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本輪源：`ttr_anal_multi main=97e019c603bea79a7774631e82195b13be207fc4`、[Iteration27](S00-20261031-ITERATION-27-C05-DELIVERY-PLAN.md)、[W01～W09 matrix](S00-ITERATION-27-C05-DELIVERY-MATRIX.json)。已核對獨立 Server `main=c17a986fc66caca8af0efb72e2b42d1188e2a584` 的 C03 實際程式；該快照可能被其他人更新，因此下游接手時**需重新核對 Server main**。

## 1. 核心新增：C03 的安全查詢不等於跨交易的 Encounter 寫入授權

現有 C03-C 的 `IAtomicCharacterActions.GetSelectedAsync(SessionLease)` 與 `SelectAsync(...)` 會在**各自**交易內查當前 lease；`CharacterSummary` 僅提供 `CharacterId(Guid)`、owner ID、display name。**它不是跨交易可重用的授權票券**。另一個登入/Session 續租會更新 `SessionLease.Revision`、撤銷或清除選角欄位；若先 `GetSelectedAsync` 再在另筆交易直接寫 Encounter，有一段 TOCTOU 競態。必須將該問題當 **W01 最先要修的實作邊界**，不可當成已解決。

| 底層 | 已存在的 source-backed Server 程式 | Iteration28 必須新增的能力 |
| --- | --- | --- |
| C02 Session | `SessionLease(SessionId,AccountId,ConnectionId,Revision,ExpiresAt)`；`ISessionLeaseRegistry.IsCurrentAsync/TryRenewAsync/RevokeAccountAsync` | 對 Encounter 的**同資料交易/鎖定序列**再驗 full lease；`IsCurrentAsync` 不可在另一筆交易提前 check 然後信任 |
| C03 Character | `IAtomicCharacterActions.SelectAsync/GetSelectedAsync`；SQLite `SqliteCharacterStore`，PostgreSQL `PostgresCharacterActions` | 交易內讀 session.selected_character_id + owned `CharacterId`，檢查尚未被續租或重登覆蓋，並一次性寫入 Encounter |
| SQLite | `SqliteLocalDatabase` 目前 local `PRAGMA user_version=1`，單 writer；`sessions` 含 `selected_character_id` | 新增需維護者批准的 additive mock schema/migration；以明確 **write transaction** 排序 Session 更新與 Encounter insert；重新開 DB 後能核對 schema/資料 |
| PostgreSQL | `tartaros_session_leases` 的 `selected_character_id` 和 `selected_revision`（migration003）；C03 SELECT FOR UPDATE | 先鎖有效 SessionLease row，再查 selected_revision/role ownership，最後插入 Encounter；鎖順序與 renew/revoke/selection 一致防死鎖 |

**不能**把 Server C03 可設定 1～16 個角色的 slot 與 Client KR 角色 record ID/bitmask 硬對照，也不能將 Client C2S0x42 mode0/2 或 S2C0x69 subtype7 視為選角後已進入教程。

## 2. W01 — 原子授權＋預約 Encounter（新的 proposed application/DB API）

建議不要重寫 C03 `IAtomicCharacterActions` 的已驗證 public 行為。可在獨立 `Tartaros.World` 或 `Tartaros.Encounter` domain module，新增一個**由 Persistence 層實作的原子指令**；這是**提案簽名**、並非現有 C# 原始碼：

```csharp
// PROPOSED: server-internal mock domain only; not KR Client packet.
Task<ReserveEncounterResult> ReserveEncounterForCurrentSelectedAsync(
    SessionLease exactLease,
    MockSceneKey scene,
    MockConfigDigest fixtureDigest,
    Guid requestId,
    CancellationToken cancellationToken);
```

最小成功交易（共同規格；實作 SQLite 與 PostgreSQL 細節不同）：

1. 在**同一筆可序列化的寫入交易**，鎖定／驗證 exact `account_id + session_id + connection_id + revision + expires_at > serverNow`。Session Renewal、Revoke、Claim 與 Encounter 寫入必須使用**同一 DB/鎖定權威**；若未經維護者確認鎖序，不可宣稱無跨程序競態。
2. 交易內讀取 `selected_character_id`；PostgreSQL 另核對 C03 `selected_revision=lease.Revision`；再查 `characters.owner_id=lease.AccountId`。沒有選角、角色刪除、owner 不符則 fail closed。**不得接受 Client slot/role name 作 primary identity**。
3. 檢查 `scene` 屬於已審核的**MOCK fixture namespace**；`fixtureDigest` 必須 pin 明確 hash/version、且有允許的 Actor budget。不可使用未證原版 SceneList(1001,1)、Quest15 map 或 S2C 資料當 mock scene 正式地圖。
4. 寫入 `EncounterId`、角色/帳號、full lease fencing fields、scene/config/aggregateRevision=1/state=RESERVED、expiry。unique index 阻止同角色/場景同 epoch 出現重複 live encounter；在尚有效的 lease 下同 `requestId` 重送可返回同結果。
5. **重試/冪等的先後順序不能倒過來**：先確認當前 lease/role，再決定是否回傳先前 `requestId` 結果；否則已遭停權/重登的舊請求仍會拿到 success。提交時須處理 transaction deadlock/retry、unique conflict 和 timeout，回傳 Server-internal 狀態（不是原版 S2C result code）。

建議結果類型：`Accepted`、`Replay`、`AccessDenied`、`MissingSelection`、`InvalidMockConfig`、`Conflict`、`Expired`、`CapacityExceeded`。所有錯誤分支需零持久化副作用；可用 opaque `EncounterId`，不可因角色名/Client slot 推算 actor。對使用者可見的世界 ready 仍是**另外待證**的 Client gate。

## 3. W02 — Encounter 狀態機、lease fencing 和崩潰復原

```text
MOCK_DOMAIN_ONLY
RESERVED  --[valid full lease, scene/config, CAS]--> ACTIVE
RESERVED  --[expiry/abort/fence]------------------> ABORTED
ACTIVE    --[policy-approved terminal]----------> SUCCEEDED / FAILED / ABORTED
ABORTED/FAILED/SUCCEEDED --[retry]--------------> same terminal (NO resurrection)
```

- Domain 需保存 `EncounterId/AccountId/CharacterId/SceneInstanceMock/SessionId/ConnectionId/SessionRevision/leaseExpiry/configDigest/aggregateRevision`；**`SessionLease.Revision` 即當前程式具體可用的 fencing 欄位**，不另外杜撰原版 SessionEpoch 封包欄位。
- `ActivateMockEncounterAsync` 須執行 exact lease + expectedRevision CAS。任何 reconnect、Session renew、Disconnect、Revoke/ban 後的舊 lease 不能啟用、移動或更新 Encounter。
- Worker crash 後只根據已 commit 的 Encounter/Actor/event row 恢復；**不得**因孤兒 `RESERVED` 重新配置第二個 EncounterId 或把 `ACTIVE` 誤當 Client 已載入 scene。逾期 fence/abort/resume policy 是 **ADR-0006/0007 尚未批准的候選**；未定政策時 fail closed。
- 日誌記 bounded `server_commit`、`lease_revision`、`encounter_id`、`request_id`、`config_hash`、前後狀態及 DB provider，不記錄帳密、真玩家資料、未證的 KR network packets。多角色帳號／兩個 Session /重登的交錯順序都要固定可重現。

## 4. W03 — 可重現的 mock Actor 生成與 AI tick，而非偽裝的原版 Scenario14

| 子系統 | 新 Server mock 提案 | fail-closed / 原版 Client 證據界線 |
| --- | --- | --- |
| Fixture | canonical JSON 配置 + SHA-256 digest + 固定 seed + 有界 actor budget/位移邊界 | 必須標 `mock` namespace，不能把假配置叫原版 Scenario14 波次/血量/生成點 |
| ActorId | 在 `EncounterId + template + spawn ordinal` 範圍內 deterministically 推導 opaque ActorId；DB unique `(EncounterId,spawnKey)` | 不直接沿用原版 NPC id、封包 actor handle 或 scene key；碰撞以 unique reject |
| Spawn | `MaterializeMockActorsAsync` 採 eventId 去重，於同交易寫 Actor rows、spawn state、aggregateRevision | 重複呼叫/崩潰恢復不能出生兩次；先檢查 lease/Encounter 狀態 |
| AI | `StepMockAiAsync` 僅由 Server mock dispatcher 執行；tick 單調、fixed seed tie-break、bounded action，不接受 Client 自報 AI 動作 | 原 Client AI owner/指令 wire 尚未知；因此不賦予 client authority |
| Movement | 限同 `EncounterId` Actor 與合法角色 move intent；檢查 tick/expected revision/位移上限/fixture 世界界線 | 不能把 mock 導出的 delta/座標映射成原版 KR map/field/axis |
| Finish | W03 只交可測 Actor position/AI state、alive placeholder；**不產生 Scenario14 過關、傷害、技能或 Quest** | W04 以上另依 Iteration27 的 action/hit/Quest contract 開發；未證不要 auto-clear |

**最小 mock fixture（純概念，不是實際資料）**：單一虛構場景、1 個虛構 NPC、固定初始座標/AI step、明確 actorBudget、configDigest。選擇固定值為了單元測試可重現，**絕非原始 Tartaros 的合法座標或怪物資料**。

## 5. 可交付之資料／migration 審查

[機讀契約](S00-ITERATION-28-C05-W01-W03-CONTRACT.json) 把待建資料欄位拆成 `mock_encounter`、`mock_actor`、`mock_event_dedup`。這些**只是候選表模型，沒有在 Server repo 建 migration**。

- SQLite 既有 `user_version=1`，下一版加表應明確 migration/version verifier、foreign-key、已有 C02/C03 可重登/選角保留、不相容版本拒絕、reopen/restore。不要用單獨 `IsCurrentAsync` 查詢＋另一連線寫資料，而要**單 write transaction**。
- PostgreSQL 已有 migration001–003，下一版若採用應加 new migration file、schema verifier、disposable + restored DB CI，鎖順序以 **session row FOR UPDATE → selected role → encounter insert** 控制；同一角色若有舊 Session 相依資料，要處理 CAS/unique 衝突及 race。不能把 SQLite SQL 直接套 PostgreSQL。
- `MockActorId`、`MockConfigDigest`、`MockSceneKey` 是提案 DTO，不可視為現有 C# 程式；在獨立 Server repo 實作時還要決定命名、serialization、權限和正式業務 policy。
- 如果 C05 migration 尚未批准，**只可用 isolated mock repository / unit tests** 進行原型，不得更新正式玩家資料或把代碼注入遊戲 listener。

## 6. 來源、驗收順序、下游 PR 切片

| 建議下游 Server PR | 閉合目標 | 必交測試 | 解阻條件 |
| --- | --- | --- | --- |
| **C05-P1** | `S28-01` 原子角色授權與 Encounter reservation | [I28-T01～T05](S00-20261031-ITERATION-28-W01-W03-ACCEPTANCE.md)，SQLite/NewSession/撤銷交錯、PG row-lock 避免 TOCTOU | Server maintainer 認可同交易鎖序／新表版本；不靠原 Client |
| **C05-P2** | `S28-02` Encounter aggregate／狀態 CAS／Session revoke／restart | I28-T06～T09，crash after commit、old epoch、duplicate reservation | 依 ADR-0006/0007 明確選擇 abort/recovery policy；尚未批准只能原型 |
| **C05-P3** | `S28-03` fake Actor spawn/AI/tick/movement | I28-T10～T16，固定 hash，actor ownership、DB reopen/restore、duplicate event | 先完成 P1/P2 transaction & Actor/scene ID namespace |
| **後續 W04** | Skills、hit、death 由真實 Actor state 衍生，而非 Client 傳勝利 | 沿用 Iteration27 S27-W04/I27-T07/08 | T09/T10 真正原生 wire 與可用技能依舊待來源補證 |

**目前正式證據未變**：RR-0002/0010 BLOCKED，RR-0008 IN_REVIEW；SPEC-FLOW/SCENE DRAFT/PARTIAL；ADR-0006/0007 **PROPOSED/NON-NORMATIVE**；實際 Server C05 尚無此次新程式碼、原版 Client 沒有執行。下游真正執行後才可按證據登記 `DOMAIN_SYNTHETIC` pass；S00 CI 檢查只保護規劃，不證工作完成。
