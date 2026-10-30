# ADR-0004 — V1 Admin WEB 固定網址 + 來源 IP 白名單（不設管理員登入）

**Status: PROPOSED / NOT APPROVED / NON-NORMATIVE.** Server-only design proposal; `client_version=null`, not native Client protocol proof. Related: `REQ-0006` and its user follow-up **「目前先不管權限，指定的IP與URL就能管理」**; supports `REQ-0007/0008`. Original request history retained in `design/requirements/requests/2026-10-31-admin-web-account-operations.md`.

## V1 user-scoped policy (updated 2026-10-31)

The **first phase explicitly skips** administrator user accounts, login page, passwords, SSO, MFA, role definitions, per-action RBAC and admin-session/token lifecycle. A single management surface is reachable only if:

1. The **actual inbound client source IP** matches a configured explicit IPv4/IPv6 CIDR or single-IP allowlist (default deny when unconfigured).
2. The request targets an explicitly configured management URL: scheme, Host/domain/IP, port and expected base path; routes to account-list, create, suspend, unsuspend, audit. Configuration examples are placeholders only, not real credentials or exposed production URLs.
3. The request reaches a **private network, VPN, localhost, or similarly restricted segment**; cross-host transport uses TLS. Neither obscure URL nor DNS name is proof of the visitor's identity. This policy is not suitable alone as a public-Internet administrator authentication replacement.

**Enforcement point:** do the source-IP deny at the trusted reverse proxy/firewall **and** verify request metadata/route at the backend; block requests that bypass the proxy by binding the backend to loopback/private interfaces and firewalling direct access. Treat `X-Forwarded-For`/`Forwarded` headers as untrusted unless received from explicitly configured trusted proxy IPs; parse the client chain correctly (including IPv4-mapped IPv6) instead of reading arbitrary first header value. Reject malformed/missing/unexpected Host and deny wildcard routes.

## Request protections that remain despite skipping permissions

- All account mutations use POST (not GET), strict `Origin` (and `Referer` where appropriate) + CSRF-aware same-origin checks, reject cross-origin browser submissions, prohibit permissive CORS, restrict content types and require deliberate UI confirmation. An IP allowlist alone cannot prevent a malicious website from causing an allowed browser to submit a request.
- Rate limits, bounded request body, validation, idempotency, expectedVersion/CAS, no querystring credentials, safe audit/errors; never disclose credential/hash/token in page, logs, URL or exception.
- Access IP allowlist should be managed through server-only configuration/env (or restricted private deployment settings), **not** a self-service public endpoint. Never hardcode actual operator IPs in this public repository.
- When multiple people share an allowed public IP, corporate NAT or VPN egress IP, **all may gain the same management capability**; IP is a network gate, not user attribution. Compromised allowed host or proxy could grant full access. Before public deployment, revisit real administrator authentication and MFA.

## Audit semantics

Audit actor must be truthfully labeled as `IP_ONLY_OPERATOR` (or equivalent anonymous network-admin actor) plus observed client IP, timestamp, target account UUID, action/reason, result, correlation ID. Do **not** fill `created_by_admin_id`, `ended_by`, or authorization-decision fields with invented administrator identities; nullable/synthetic identifiers with explicit provenance are required until identity exists. Success writes and audit should be atomic/recoverably coupled.

## Alternatives and deferred features

- Management login/RBAC/MFA: **deferred for V1 per user clarification**, not removed from future production security considerations.
- URL-only without IP validation: **reject**, URL is not a secret.
- IP-only with unvalidated Host/proxy and public backend bypass: **reject**.
- Dedicated Admin Host or logically isolated management endpoints inside the existing .NET modular monolith: either possible after private-network security review; do not expose existing C00 `/health` or guess native Client opcodes.

## Approval gate

This is still `PROPOSED`: user has clarified V1 scope but not specified exact allowed IP/CIDR, management Host/port/path, proxy topology, TLS deployment or production-risk acceptance. Before implementation exposure, verify default-deny, bypass resistance, private bind, trusted proxy behavior, browser CSRF protection, backup/audit integrity, shared-IP threat and recovery/rollback. No original Client compatibility claim.
