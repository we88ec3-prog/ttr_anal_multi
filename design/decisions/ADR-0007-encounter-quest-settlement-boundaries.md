# ADR-0007 — Encounter/Scenario/Quest/Reward/Exit authority separation

**Status: PROPOSED / NOT APPROVED / NON-NORMATIVE.** Proposed S00 Server implementation decision, 2026-10-31; this is **not** evidence of original Tartaros Server behavior. Relevant exact KR Client target SHA256: 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91.

## Problem

The original KR Client contains partial, distinct source paths: local Scenario14 request builder C2S 40 00 0E 00, CTutorial S2C app0x004C consumer setting local map[scenarioId]=1, QuestInfo resource dependencies Quest16→Quest14 and Quest15→Quest16, and local scene/resource loaders. There is no proven complete original Server sequence or authoritative encounter/quest/reward behavior. Domain game systems nevertheless need clear crash/replay/actor-state authority to avoid a runnable mock permanently drifting from a future original-Client adapter.

## Proposed policy

1. **Role/Session/Encounter ownership:** every EncounterId is scoped to a Server-authorized RoleId, SessionEpoch, SceneInstance and immutable EncounterConfig version. Clients may submit bounded **intents**, never authoritative spawn/AI/hit/loot/victory results. Mock fixture config is not a claimed original Scenario14 wave.
2. **Actor/Action:** Server validates owner, scene, allowed skill/action/cooldown, monotonic timeline, legal target and replay key. Spawn, hit, death and wave advancement are versioned deterministic domain events, not accepted at face value from local Client state.
3. **Once-only scenario outcome:** terminal result is guarded by valid objectives and a unique per-encounter settlementKey, CAS state transition and transactional outbox. S2C app0x004C is merely a known limited Client consumer and requires separate compatibility proof before any original Client packet is emitted.
4. **Quest transitions remain independent:** Quest14 complete/turn-in is **not** implied by Scenario14 settled; Quest16 available/accepted/completed and Quest15 available/accepted/completed remain distinct states. A QuestInfo Demand field is a partial static prerequisite, not the entire original Server authority.
5. **Rewards and tutorial terminal:** RewardLedger unique per-role reward key and idempotent commit. Quest16 Reward type=2/value=50 is **not** automatically EXP or currency. Tutorial COMPLETED is a separate, approved prerequisite decision governed together with [ADR-0006](ADR-0006-tutorial-progress-and-session-fencing.md); neither S2C0x004C nor Quest15 availability alone can mark it.
6. **Exit and retry:** scene/field transfer and normal-world readiness are separate admission gates; if unknown Client framing/scene/resource/actor attributes cannot be proven, native adapter remains OFF, durable progress persists and re-login uses a new SessionEpoch.
7. **Evidentiary firewall:** Domain synthetic, scoped native static, original KR Client runtime compatibility, and original Server trace must be separately recorded. Green CI and mock successes never upgrade RR/CLM/SPEC maturity.

## Alternatives and unresolved maintainer choices

- Trusting a client-reported kill or static elapsed timeout to settle Scenario14 is unsafe and not source-supported.
- Publishing a full KR Scenario14 with guessed enemy count/positions/HP, auto-granted Quest14/Quest16 and Reward type-to-currency would be an unsupported compatibility claim.
- A Server-owned deterministic mock encounter can be useful for early development **only while explicitly labeled PROPOSED/DOMAIN_SYNTHETIC**, with substitute encounter configuration pinned to mock fixtures.
- Maintainer must decide final authoritative actor model, collision/rate protections, session disconnect recovery vs abort rules, Quest14/16 reward and terminal transactions, replay policy, whether tutorial exit and completed marker share one transaction, and how to migrate old progress.

## Approval gates

[Iteration26 implementation plan](../../governance/s00-iterations/S00-20261031-ITERATION-26-COMBAT-QUEST-EXIT-PLAN.md), [19-gate machine matrix](../../governance/s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json), and [18 planned tests](../../governance/s00-iterations/S00-20261031-ITERATION-26-ACCEPTANCE.md). All tests NOT_RUN. Requires an explicit maintainer review/approval_record before normative status; do not add to formal SPEC adr_ids while PROPOSED. E17/E18–26 remain Client evidence-limited. New official RR/REQ/TEST need their own separate pipeline and T01 scoped original evidence.
