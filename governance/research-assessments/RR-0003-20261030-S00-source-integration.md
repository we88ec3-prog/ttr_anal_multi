# S00 — RR-0003 bounded integration assessment (2026-10-30)

**Disposition: SOURCE-INTEGRATED / S00 ACCEPTANCE NOT YET ISSUED.** This is a technical pre-decision assessment, **not** an entry in `governance/reviews/index.json`, a T01 FULL-PASS, a NATIVE_VERIFIED promotion, or original Client/Server compatibility. Authoritative RR-0003 status remains `IN_REVIEW`.

## Verifiable repository inputs

- KR original `Tartaros.bin` SHA256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, original executable unavailable in this S00 review context for fresh binary-level revalidation.
- T03 RR3 primary report: `kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md`, **Git blob SHA `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`**, `SRC-0473`, `CLM-AUTH-0003..0005` (PARTIAL), source already merged on main via PR #45/#46.
- Later source-scoped E69 correction: `kr-extra-roy/20261030-chatgpt-web-roy-E69-RR0003-E8-tail-uninitialized-CPACP-and-13-handoff-native.md`, **Git blob SHA `98546ce73206e2b8f6fede78d83923af7a76cf5b`**, `SRC-0482`, `CLM-AUTH-0006` (PARTIAL).
- Independent T02 handoff research `RR-0005=ACCEPTED` only for bounded Client static path: `CLM-NET-0018..0020`; its exact `GAP-NET-0002` remains OPEN. T02 `RR-0007=IN_REVIEW`, `CLM-NET-0029..0031`, supplies conditional app dispatch/LOGIN scene context.
- Source Git blob SHAs verified against the *existing main repository files*, not invented from document titles; S00 did **not** re-run T03's original BIN or independent T01 R2 Native instruction checks in this iteration.

## Clause-by-clause narrow analysis

| RR3 requested boundary | Bounded positive evidence | Remaining disqualifying assertion for full wire contract |
| --- | --- | --- |
| E8/000F mode and local payload | Native `0x440790`: mode `0x52→0x4A3360` E8/112B; `0x54/other→0x4A31B0` 000F/214B. Both queue via manager vtable+0x10 to slot1. | Does not identify launcher distribution, successful socket send, actual Server response or frame marker. |
| E8 opaque bytes | E8 `+104..109` lacks direct initialization along inspected builder path; `+110..111` comes from source WORD. F-mode `+206..213` has separate explicit values. | Do **not** give six bytes a stable Server-mandated value, assume all-zero, or treat lack of direct store as a global alias-writer exclusion. |
| Codepage | FBA808 is PE `.data` virtual-zero tail; initial 0 = CP_ACP; Native input conversions use this global. E8 output WCTMB directly pushes CodePage=0 (CP_ACP). | Runtime ACP/global alias writer and invalid/exceptional conversion behavior remain partly unknown. Fixed UTF8/CP949 Server requirement not source-backed. |
| Active LOGIN S2C handlers | Second-level table `0x4C3220`: `0x0013→0x4C37A0` and separate `0x007A→0x4C3C10`; T02 lane2/scene dispatcher preconditions are necessary. | Handler registration does not prove official Server sends either first or that E8 request pairs with a specific S2C order. |
| `0x13` status and fields | `payload+0x16` status; `5` distinct fail; `0` plus nonempty UTF16 name at `+2` local success; optional notice at `+0x20` can be processed before status. Additional fields +0x17,+0x18,+0x86,+0x87,+0x8C,+0x90/+0x92 source-backed. | Complete status enum, missing terminator/too-short payload and official token/session business semantics absent. |
| 0x13 / 0x7A group cursor | `0x13`: groupCount at +0x1C / cursor +0x92; `0x7A`: groupCount at +2 / cursor +6. Common group header3 + child10, IPv4 child+4..7, child+8 filter, child+9 downstream argument. | `0x4C3080` has no visible per-row input remaining-length guard. Formula is minimum cursor extent, not original Server packet capture/safety verdict. |
| Login result → choose/Connect | `0x13` success plus +0x90=0 can call `0x4C3170` (local `F4241`); UI selection still requires `0x66C090` data/mapping/guards before `0x4957C0` connects key0/key2. | No unconditional `0x13→key0/key2` transition, endpoint policy, or cross-socket first S2C; accepted RR5 is not whole-flow closure. |

## S00 conclusion on this evidence

1. **Supported for DRAFT spec enrichment:** distinguish source and output codepage paths; enumerate locally observed application handler identities and guarded data offsets; keep status0/5 behavior bounded; document the separate 0x13/0x7A group extents; preserve key1/key0/key2/UI gate distinction.
2. **Not supported:** official Server authentication algorithm, constant E8 tail, packet-order claims, unconditional Connect, native bounds checking, live replay success, Client compatibility, or closure of GAP-AUTH-0001.
3. **Review status:** RR3 remains `IN_REVIEW` pending authorized S00 final bounded-acceptance decision and any additional T01 native review of source-level conflicts. This technical analysis alone does not edit RR events or create an accepted review ledger entry.
4. **T01 review boundaries:** Source-intake `CONFLICT_CHECKED` and PARTIAL CLM flags verify registration/limited extraction, **not** comprehensive original-BIN re-verification or a FULL-PASS. If a new NATIVE_VERIFIED claim is desired, pass exact source, binary SHA, address/CFG/counterexample to T01 and use existing strict workflow.
5. **Follow-up priority:** obtain true C2S→S2C pairing / authenticated session order; decide if source-only bounded RR3 can be accepted independently while retaining GAP-AUTH-0001. Pursue `RR-0002=BLOCKED` exact selection response and `RR-0007/0008=IN_REVIEW` scene/gated-flow without manufacturing a request+1 opcode.

## Updates made in this S00 iteration

- Revised `spec/session-account/SPEC-AUTH-0001.md` plus `SPEC-FLOW-0001.md` and `phase-b-message-matrix.md`.
- Linked existing `CLM-AUTH-0003..0006` and conditional dispatch to SPEC indices, with no new fabricated native evidence. Adjusted only COV-0004 command-identity knowledge from UNKNOWN to **PARTIAL** and updated notes; request/reply pairing, transport context and test provenance remain blocked.
- Maintained `SPEC-AUTH-0001=DRAFT/PARTIAL`, `SPEC-FLOW-0001=DRAFT/PARTIAL`, `GAP-AUTH-0001=OPEN`, `RR-0003=IN_REVIEW`. No existing T02/T03 task owner changed.

## Reproducibility

`python -B governance/validate_s00.py` and `python -B governance/check_contract_coverage.py --check` verify registry/link structural integrity, **not** Native semantics. `conformance/session/test_kr_auth_group_cursor_synthetic.py` checks only a synthetic cursor/extent model; it is not a captured original S2C vector.
