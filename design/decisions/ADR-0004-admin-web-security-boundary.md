# ADR-0004 — Separate WEB administration identity and privilege boundary

**Status: PROPOSED / NOT APPROVED / NON-NORMATIVE.** Scope: Server-owned WEB admin, not historical KR/TC Client behavior. Request origin: `PLAYER_ADMIN_REQUEST`; relates to `REQ-0006`, supports REQ-0007/0008.

## Context

`ttr_server_roy` C00 exposes loopback diagnostics; Account/Session C02 is offline-only; `Tartaros.Admin/IAdministrativeAuditSink` has merely an interface. Exposing C00 HTTP as public WEB admin, reusing game passwords as Admin credentials, or allowing unauthenticated mutations would breach the current isolation boundary.

## Proposed decision

1. Introduce a **separate authenticated Admin API/WEB surface** (may share deployment with modular monolith but not unguarded diagnostic or game listener). Start with VPN/private access and TLS. External exposure must have separate risk review.
2. Admin identities are independent of player identities; enforce permissions server-side: `accounts.read/create/suspend/unsuspend`, `audit.read`. Protect all mutations with CSRF defense (where cookie-authenticated), short-lived revocable admin sessions, second confirmation, role-specific authorization, anti-enumeration and rate limiting. MFA/IdP is preferred but provider/rollout is undecided.
3. Every privileged action must have append-only audit metadata, actor, target, time, reason, result, correlation ID; never put password/hash/token in log or DB audit. Writes must be tied transactionally or via reliable outbox to audit.
4. Do not grant an unreviewed game role elevated access to this API; document explicit bootstrap and loss-of-admin recovery process, and prohibit self-escalation.

## Alternatives and trade-offs

- Reuse C00 `/health` directly as unguarded public admin: **reject**.
- Share player credentials with admin: **reject** due to privilege-boundary risks.
- Separate microservice vs a separate Admin Host within one .NET 10 modular monolith: **prefer latter for V1**, subject to deployment review.
- Local admin users vs external IdP/MFA: unresolved, decide before public connectivity.

## Approval gate

S00/Server maintainer must explicitly approve threat model, initial admin bootstrap/MFA, permissions, audit retention, private bind/reverse proxy/TLS, logging/privacy, rollback. Not approved by this PR; do not add this proposal as a normative Client SPEC dependency.
