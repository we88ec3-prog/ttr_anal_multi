# ADR-0005 — Persisted account suspension, expiration, unban and Session fencing

**Status: PROPOSED / NOT APPROVED / NON-NORMATIVE.** Server-only operations policy tied to `REQ-0008`, independent of the original Client wire and C02 failed-password `locked_until`.

## Problem

Admins need N-day and permanent account suspension plus unban. Current `tartaros_accounts.locked_until` is for **credential failures**, and `RevokeAccountAsync` exists but does not provide durable moderation sanctions or an atomic policy generation. Just displaying a ban status in UI does not stop already-issued game sessions.

## Proposed design decision

- Store independently versioned moderation sanctions with `TEMPORARY` (`starts_at_utc`, `expires_at_utc`), `PERMANENT` (`expires_at_utc=NULL`), reason, creation/end timestamps, **V1 observed source IP (operator_kind=IP_ONLY_OPERATOR, not an identified administrator)** and immutable audit history. Only one effective sanction at a time per account; immutable historical records remain. Future identified actors can be modeled separately if login/RBAC is introduced.
- A day = 24 hours; for positive integer N, UTC expiration = Server authoritative `now + N*24h`; numeric ceiling, overflow guard and local display timezone policy to be approved. No scheduler required to restore a naturally expired suspension.
- Enforce ban in the authoritative authenticated Session admission/lease issuance **and** at existing Session/actor action boundaries; use account generation/epoch fencing and durable/acknowledged revocation across nodes. Rollback-safe sanction write+audit; outbox/retry for post-commit notifications; fail closed when sanction status cannot be determined.
- Unban ends current sanction but does **not** clear password-failure lockout, reset credentials or restore old sessions.
- For V1, reject new different ban when one active, and reject unsuspend if none active (`409`); exact repeated idempotency key replays same result. Changing/extending bans is a separate future decision.

## Alternatives and unresolved decisions

- Reuse `locked_until`: **reject** (cannot express permanent, attribution, audit and separate lockout).
- Disconnect-only: **reject** (race/reconnect/multi-node bypass).
- Eventual revocation only: can deliver delayed disconnect; must not be represented as immediate enforcement. Choose synchronization/ack timeouts and acceptable time-to-deny.
- DB-backed authoritative checks vs bounded cache: requires consistency/threat modeling and performance testing.
- Account sanction duration upper bound, admin role for permanent bans, audit retention and appeals/access to reasons require operator approval.

## Approval gates

Approve data migration plan with uniqueness/CAS, revocation idempotency and crash-recovery tests, fail-closed behavior, privacy, backup/restore, read-path performance and admin permission guard. Keep original KR/TC protocol status untouched; this proposal is not an RR, not native SPEC evidence and not approved production policy.

## V1 access clarification (2026-10-31)

User narrowed the WEB Admin entry to a configured URL and client source IP allowlist, **without admin login or RBAC**; see [ADR-0004](ADR-0004-admin-web-security-boundary.md). This affects only the management **entry/audit actor label**, not the game-account suspension or Session fencing semantics. V1 audit cannot identify an individual person behind a shared IP; it records source IP, event, target, reason, UTC and result. Still PROPOSED, not approved or implemented.
