# ADR-0003 — Server-authoritative character records with client-compatible serialization boundary

**Status: PROPOSED / NOT APPROVED / NON-NORMATIVE.** S00 planning discussion only, **not** original Tartaros Server evidence; only for candidate KR pilot (Client target SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`). The implementation repository and maintainer must approve a decision before it becomes normative. No runtime Client verification, no backend code in this repo.

## Problem and distinction

The Client has a bounded S2C command-2 roster parser with 65-byte prefix and 53-byte entries, and evidence of a selection C2S 0x42 candidate; exact selection success reply and some fields remain UNKNOWN.

## Proposed design direction (not a Client native claim)

Separate server-owned character roster selection/authorization from the byte geometry consumed by the KR Client; do not assign semantics to unknown 65-byte prefix fields.

## Alternatives requiring review

- Mirror arbitrary UI/Client-provided data without authorization: not suitable.
- Keep role records and selection authorization in a distinct Server-controlled store, serialize only proven Client-visible fields (proposal).
- Fill unknown 65-byte prefix with made-up values: invalid until native proof or explicit experimental fixture.

## Risks and unresolved proof

GAP-CHAR-0001, GAP-FLOW-0001 and RR-0002/0008 remain open; a working synthetic roster parser is not a real selection-to-scene success trace.

## Approval and evidence gates

- For any chosen persistence model record an ADR in the Server repo, then define per-field Client serialization and ownership separately.
- Reject selecting roles not owned by the active Server session as a Server security policy, not a proven historic Client behavior.
- Validate any required roster fields, selection result and initial world state through T03/T04 before releasing client-compatibility claims.

## Scope / references

Affected S00 specifications: `SPEC-CHAR-0001`, `SPEC-FLOW-0001`. Source-of-truth index [design/decisions/index.json](index.json). All dependent Client wire assertions are still DRAFT/PARTIAL and have their own GAP/RR gates. **Do not add this proposal to a spec's normative ADR list or change SPEC/GAP/RR maturity solely because this file exists.**
