# ADR-0001 — Separate protocol Gateway state from Server session identity

**Status: PROPOSED / NOT APPROVED / NON-NORMATIVE.** S00 planning discussion only, **not** original Tartaros Server evidence; only for candidate KR pilot (Client target SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`). The implementation repository and maintainer must approve a decision before it becomes normative. No runtime Client verification, no backend code in this repo.

## Problem and distinction

KR analysis identifies connection slot keys, pipeline class and frame mode in Client structures, but neither the official Server session identity nor the connection lifecycle are yet proven.

## Proposed design direction (not a Client native claim)

Treat Client slot/pipeline/mode as transport metadata; Server session identity is a separate self-defined concept.

## Alternatives requiring review

- Use only socket connection tuple as identity: simple but unstable across reconnect/hand-off.
- Use client slot as identity: leaks local Client addressing into Server policy; reject without evidence.
- Use a distinct Server-owned session handle and map transport connection(s) to it: proposed.

## Risks and unresolved proof

RR-0001/0005 and GAP-NET-0001/0002 remain open; no proof of first wire frame, handoff token or real Server accept port. Until then the transport/session mapping is **architecture proposal only**.

## Approval and evidence gates

- Maintain a documented mapping lifecycle for test Server connections only after T02/T03 source-backed initial/transition message semantics are available.
- Define authorization/expiry/reconnect as Server policy ADR, never as claimed native KR behavior.
- Approve only after threats and implementation test plan are reviewed.

## Scope / references

Affected S00 specifications: `SPEC-NET-0002`, `SPEC-NET-0003`, `SPEC-FLOW-0001`. Source-of-truth index [design/decisions/index.json](index.json). All dependent Client wire assertions are still DRAFT/PARTIAL and have their own GAP/RR gates. **Do not add this proposal to a spec's normative ADR list or change SPEC/GAP/RR maturity solely because this file exists.**
