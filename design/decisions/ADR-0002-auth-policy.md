# ADR-0002 — Keep account authentication policy independent of historical Client wire evidence

**Status: PROPOSED / NOT APPROVED / NON-NORMATIVE.** S00 planning discussion only, **not** original Tartaros Server evidence; only for candidate KR pilot (Client target SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`). The implementation repository and maintainer must approve a decision before it becomes normative. No runtime Client verification, no backend code in this repo.

## Problem and distinction

Client sends two bounded local authentication payload variants (0x00E8 or 0x000F), but Client binary analysis cannot prove historical Server's password verification, storage or account lifecycle.

## Proposed design direction (not a Client native claim)

Implement test account authentication/storage in the separate Server repository under explicit policy; do not infer original Server persistence or password storage from E8/000F.

## Alternatives requiring review

- Copy the assumed old storage/MD5: unsuitable and unsupported as a backend policy.
- Local-only disposable test accounts in an isolated environment: simplest pilot option.
- Extensible credential/identity provider layer with modern password hashing and rate limiting: future-ready option.

## Risks and unresolved proof

RR-0003 and GAP-AUTH-0001 remain unresolved, especially codepage, opaque fields and precise S2C result. No proposed server-side account policy can fill these missing wire bytes.

## Approval and evidence gates

- Choose and document a test-only credential strategy in the independent Server repo; do not place passwords, private credentials, tokens or personal records in the public analysis repo.
- Separate Client-on-wire compatibility for the chosen request variant from the Server policy for validating credentials.
- Require an explicit status/reply contract from T03 before any end-to-end result assertion.

## Scope / references

Affected S00 specifications: `SPEC-AUTH-0001`, `SPEC-FLOW-0001`. Source-of-truth index [design/decisions/index.json](index.json). All dependent Client wire assertions are still DRAFT/PARTIAL and have their own GAP/RR gates. **Do not add this proposal to a spec's normative ADR list or change SPEC/GAP/RR maturity solely because this file exists.**
