# ADR-0006 — Server-authoritative per-character tutorial progress, entry routing and session fencing

**Status: PROPOSED / NOT APPROVED / NON-NORMATIVE.** 2026-10-31 S00 proposed design for the new Server only; Client target baseline KR SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91. The Server implementation repo and maintainer need separate approval. This is **not** original Tartaros Server policy or an original Client packet fact.

## Context

Iteration 23 proves limited full/delta Client role-record storage, Iteration 24 proves bounded C2S42 selection fields and separate Square scene handler candidates. Neither proves the original Server selection ACK, the first-tutorial scene key, account-vs-character tutorial policy, or the genuine tutorial completion/exit message. Iteration 16/17 nevertheless define a target product journey: newly provisioned Account → playable Role → first tutorial and eventual completion/relog.

## Proposed decision (not yet operative)

1. Maintain one **Server-authoritative TutorialProgress per RoleId**, with durable state NOT_STARTED, IN_PROGRESS, COMPLETED, revision, optional last acknowledged checkpoint, started/completed timestamps and explicit policy version.
2. Keep **SessionEpoch/AdmissionId** in a distinct short-lived admission lease. Never confuse Client local scene+CC, local F4278, C2S43, sent S2C69 subtype7, or Server DTO WorldReady with proof that original Client controls/scene succeeded.
3. Route a *proposed* first-time playable role from NOT_STARTED→FIRST_TUTORIAL_ROUTE; IN_PROGRESS→RESUME_ROUTE; COMPLETED→NORMAL_WORLD_ROUTE. All route outputs are **internal proposals** until authorized Client tests prove the necessary scene/resource/frame contracts.
4. Only **Server-authorized domain events** with validated preconditions may commit checkpoint/completion; use CAS and unique per-role event keys. Quest14/Quest16, Quest15 availability, Scenario14, one-time rewards, and tutorial exit have different authorities and transition/transaction rules.
5. Preserve Progress during disconnection, ban, and unban; revoke/fence active Session admission on ban, and use new SessionEpoch after login. Old epochs cannot advance Progress or spawn multiple world sessions.
6. Feature-gate all experimental original Client encoders/adapters **OFF by default** until T02/T03/T05/T06/T07/T16 supply a documented valid Client-compatible scene/Conn/wire. A working MockClient is only synthetic validation.

## Explicit unresolved choices for maintainer review

- Is the first tutorial per **Account**, per **Role**, or another entity in intended V1 policy? Per Role is proposed for independent progress and replay protection, not a statement about original Server.
- Is skipping / replaying a tutorial ever permitted, by whom and with what audit? Client selection mode2 is **UNKNOWN**, never silently treated as skip.
- What is the authoritative completion boundary? Quest16? Later terminal/scene exit? A Server-side policy must name positive evidence, reject mere Scenario14 map flags, and separate Quest15 available from Quest15 completed.
- What checkpoint granularity can safely restore Lua coroutine state, NPC, actor and scene resource? Until native route proven, choose safe Server mock resume, do not guess Client internal execution frame.
- Can reward ledger and QuestProgress commit atomically in chosen DB? Otherwise require idempotent outbox/saga and reconciliation instead of fake exactly-once network delivery.

## Alternatives

- **Account-only tutorial flag**: smaller schema but may incorrectly suppress tutorial for additional roles and loses individual resume; requires explicit policy decision.
- **Trust Client-provided completion / UI-ready events**: unacceptable to Server security; local UI signals are not authenticated Server state.
- **Auto-complete tutorial on selection or S2C0x4C**: unsupported Client causal inference and loses recoverability.
- **Use per-Role progress with version/epoch fencing (proposal)**: supports fake-Client testing, independent recovery and future adapter isolation, at greater data/migration complexity.

## Acceptance and approval gates

- [Iteration 25 plan](../../governance/s00-iterations/S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md) defines candidate interfaces and progress boundaries; [16 I25 cases](../../governance/s00-iterations/S00-20261031-ITERATION-25-ACCEPTANCE.md) are all PLAN_ONLY/NOT_RUN.
- Explicit reviewer approval is required to change status to APPROVED/normative, plus account-vs-role policy, ban/lease/transaction/isolation and completion precondition decision. Separate Server implementation ADR and migration review may also be required.
- No spec becomes STABLE or native RR ACCEPTED because this ADR is proposed. Preserve RR-0002/0010 BLOCKED, RR-0008 IN_REVIEW, GAP-SCENE-0001 OPEN, SPEC-FLOW/SCENE DRAFT/PARTIAL until independently addressed.
