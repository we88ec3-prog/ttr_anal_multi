# S00 Iteration 29 — 普通攻擊、技能施放、傷害死亡及取消恢復驗收計畫

**24/24 全部 PLAN_ONLY / NOT_RUN。** 下述 `I29-Txx` 僅是將來 `ttr_server_roy` 的 Server-only mock/domain 驗收設計，**不是**正式 `conformance/test-index.json` TEST，也沒有真實執行 .NET、原版 Client 或原版 Server。來源：[Iteration29 完整規劃](S00-20261031-ITERATION-29-COMBAT-IMPLEMENTATION-PLAN.md) 與 [機讀契約](S00-ITERATION-29-C05-COMBAT-CONTRACT.json)。

| Case | S29 工作包 | 類別 | 刺激／前置 | 預期 mock domain 結果（非官方 KR 規則） |
| --- | --- | --- | --- | --- |
| I29-T01 | S29-01 | DOMAIN | Current lease, owned selected role, ACTIVE mock Encounter, valid attack window | Authorize and commit exactly one ActionId; no automatic hit, damage or quest state |
| I29-T02 | S29-01 | RACE | Authorize attack, then reconnect/renew/revoke/ban before commit | Same-transaction final lease/ban/role check rejects commit; no action or hit side effect |
| I29-T03 | S29-01 | NEGATIVE | Cross-character actor or target from another Encounter | Reject before action state change or any resource cost |
| I29-T04 | S29-01 | REPLAY | Duplicate ActionId + identical payload concurrently after valid lease recheck | One durable result; second replay reads that result, not extra attack |
| I29-T05 | S29-01 | NEGATIVE | Same ActionId with changed target/payload fingerprint | Conflict; cannot mutate previously approved action |
| I29-T06 | S29-01 | WINDOW | Combo too early, too late, stale revision, forged Client timestamp | Reject or remain in prior valid mock state using Server timeline |
| I29-T07 | S29-02 | DOMAIN | Available mock skill with sufficient resources and no cooldown | Reserve cost once and bind CastId/actor/target/Encounter; server-tick starts authorized mock cast |
| I29-T08 | S29-02 | CONCURRENCY | Two simultaneous CastIds competing for one resource balance | At most one accepted if shared balance insufficient; no negative balance/double cost |
| I29-T09 | S29-02 | COOLDOWN | Cast repeated before server-tick cooldown, Client time edited | Cooldown blocks regardless of Client clock; committed cast advances mock cooldown once |
| I29-T10 | S29-02 | CANCEL | Cast canceled/interrupted before commit and replayed | Single cancel; refund policy flagged as unapproved and specified by fixture, not native behavior |
| I29-T11 | S29-02 | NEGATIVE | Unknown SkillKey, stolen actor, cast in wrong Scene/Encounter | Fail closed, no resource/cooldown or actor-state mutation |
| I29-T12 | S29-02 | REPLAY | Same CastId replay after Session renewal or ban, altered payload | Stale lease rejected before idempotent success; changed payload yields conflict under valid lease |
| I29-T13 | S29-03 | DOMAIN | Committed mock action with valid target and authoritative hit predicate | Apply one mock damage effect, clamp HP to 0..max and update aggregate revision |
| I29-T14 | S29-03 | NEGATIVE | Client sends arbitrary damage, HP zero or death flag | Ignore as authority; cannot create a hit or terminal event |
| I29-T15 | S29-03 | BOUNDARY | Damage fixed-point overflow, negative HP, invalid maxHP, invalid range | Reject before commit, no partial HP mutation or unchecked overflow |
| I29-T16 | S29-03 | CONCURRENCY | Two workers commit same HitId to same TargetId | One hit/death outcome only; second safely returns prior effect if authorized |
| I29-T17 | S29-03 | NEGATIVE | Cross-Encounter ActorId, already-dead target, out-of-range or invalid faction fixture | Reject with HP/revision unchanged; no assumed original KR damage policy |
| I29-T18 | S29-03 | DEATH | Final legal hit drives mock HP to zero and repeats DeathKey | Death emitted once, not auto Quest14, Scenario14 or tutorial completion |
| I29-T19 | S29-04 | RACE | Cancel action races hit commit at equal revision | Exactly one serializable result; late cancel cannot undo committed damage |
| I29-T20 | S29-04 | FENCING | Ban/unban/relogin while cast pending, old worker wakes | Old SessionLease cannot commit action/hit, unban does not restore old lease |
| I29-T21 | S29-04 | CRASH | Crash after resource reserve but before committed cast | Reconcile from durable CastId, choose approved cancel/commit policy once; no double spend |
| I29-T22 | S29-04 | CRASH | Crash after hit DB commit before outbox delivery | Hit remains exactly once; outbox can deliver at least once with downstream dedup |
| I29-T23 | S29-04 | HANDOFF | ActorDeath event arrives twice at mock objective engine | Unique death event forwarded to W05; scenario terminal not inferred |
| I29-T24 | S29-04 | E2E_PLAN | Original Client attack/skill/HP/death packet and observable scene test not authorized | Keep native adapter OFF; case NOT_RUN, not eligible for native-compatibility PASS |

## 測試分批與報告欄位

- **P1 → I29-T01～06**：原子授權＋攻擊輸入；**P2 → T07～12**：Cast/Cost/Cooldown/Cancel；**P3 → T13～18**：Hit/HP/Death；**P4 → T19～24**：Race/Crash/Outbox/客戶端 No-Go。P2 與 P3 不可略過 Encounter/Actor 的 Iteration28 前提。
- 各實際測試應報 `s00_plan_sha`、`server_commit`、`test_case`、`provider`、`migration_version`、`fixture_sha256`、`actor/encounter/action/cast/hit IDs`、`lease_revision`、`server_tick`、`pre/post_aggregate_revision`、`expected`、`actual`、`status`、`evidence_class`、`native_gap`；禁止記真實帳密／敏感玩家資料。
- 需要 deterministic mock config 及 fixed-point 例子來證明受控溢位、時間窗與 cooldown；**數字不得被敘述為原版 Tartaros 正規傷害或技能表**。
- SQLite 更新到 C02-D 版本 **v2**（已於最新 Server main 實作）不等於已存在 C05 表。SQLite 新規劃 v3 和 PostgreSQL 下一版 v4 都是 `PROPOSED_NOT_APPLIED`；若後續實作要實際跑 DB 及 restore 測試，需與現有登入/選角/停權 transaction 共同驗證。
- `DOMAIN_SYNTHETIC` PASS 只代表實際新 Server 的 mock 測試成功。原始 `NATIVE_STATIC_SCOPED` 需具版本/位址/方向/連線/frame/scene/boundary/反例；`COMPAT_CLIENT_RUNTIME` 需另外授權隔離 Client。此處 24 項皆 `NOT_RUN`。
