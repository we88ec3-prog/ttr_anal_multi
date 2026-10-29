# S00 Phase B — research intake and bounded acceptance protocol

This is an S00 **read-only queue view** over the [single authoritative RR registry](../research/requests/index.json). It does not assign work, create RR items, approve sources, trigger Agent conversations, run an original Client, or make a Server compatible.

## S00 work cycle

1. Fetch current GitHub main and each Task README/T01 return section; check competing edits.
2. Run: python -B governance/phase_b_worklist.py --format markdown. For a Task, add --task T02 or --task T03; --version tc never borrows KR evidence. The tool separates direct RR impact (GAP/COV-linked SPEC and their TEST) from **broader milestone context**; do not edit every SPEC merely because the same B-CONTRACT milestone lists it.
3. Check the authoritative [T02 inbox](../research/dispatch/inbox/T02.md) or [T03 inbox](../research/dispatch/inbox/T03.md). The worklist is not a second dispatch index; a branch-local claim is not public before merging to main.
4. Prioritize existing SUBMITTED/IN_REVIEW evidence for T01/S00; then previously approved T01 NEEDS_FIX/FIXING returns, user assignments, and remaining P0 then P1 research. Roadmap dependencies constrain **delivery**, not the ability to research a downstream target.
5. Without submissions, prepare scoped acceptance guidance. Do not manufacture native claims or resolve requests.

## Research waves (existing RR IDs, not new assignments)

| Wave | Task | Existing RR | Narrow target | S00 effect only after evidence |
| --- | --- | --- | --- | --- |
| B0 | T02 | RR-0001, RR-0004 | Actual first C2S/S2C frame and A02C/mode fallback; separate local buffer from actual socket exchange | Scoped CLM, GAP-NET-0001, COV-0001/0002 |
| B1 | T02 | RR-0005 | Login result to slot/port/handoff and close/retry | GAP-NET-0002 |
| B2 | T03 | RR-0003 | E8/000F branch, 0x13 response and channel rows | GAP-AUTH-0001 |
| B3 | T03 | RR-0002 | 65+53*N roster and 0x42 selection response | GAP-CHAR-0001 |
| B4 | T02/T03 | RR-0007, RR-0008 | Inbound handler/scene writer, extra/roy1 as cited historical evidence | Scene resources are not unproved wire commands |
| B5 | T02 | RR-0006 | 0x2633/0x22D7, checksum and malformed downstream | GAP-NET-0003 |

These are research dependencies, **not** an observed original network sequence, and do not rewrite RR priorities. RR-0006 is an existing valid P1 request but currently has no delivery milestone; the worklist labels it RESEARCH_BACKLOG rather than failing validation or silently expanding the roadmap.

## Exact submission contract

A source Task submission must include:
- RR ID, KR/TC and original SHA256, research path, **Git blob SHA**, source VA/raw and bounded branches/guards.
- Direction, frame marker vs opcode, connection slot/pipeline/mode, payload length/offsets/encoding and producer/consumer.
- A negative branch/counterexample or precise UNKNOWN. Keep proven local facts separate from assumptions about Server behavior.
- Affected SPEC/GAP/COV/TEST, contradictions and T01 historical returns; cite corrected source blob if one exists.
- What specific RR acceptance criterion was answered; preserve unrelated gaps.

Only the claimant may submit via [dispatch workflow](../research/dispatch/README.md). The report must already exist in the checkout, and the exact main version/blob needs checking.

## Separate review axes

**T01** owns source identity, original binary/CFG verification when necessary, conflicts, and narrow native-confidence decisions. No automatic full-document FULL-PASS.

**S00** decides the specific RR outcome. Published ACCEPTED/NEEDS_REVISION decisions require a matching [review ledger](reviews/README.md), submitted report blob and review Markdown blob. Accepted research can still leave SPEC DRAFT or GAP OPEN.

## Source → implementer contract gate

1. Update scoped CLM, without claiming NATIVE_VERIFIED absent formal existing source decision.
2. Update exact SPEC fields: direction, bytes, state, error branches and version. Keep UNKNOWN fields and DRAFT/PARTIAL when indispensable values remain unproved.
3. Reconsider GAP/COV/TEST separately; synthetic fixture ≠ authentic traffic. EVIDENCE_BACKED requires precise reviewed CLM→SRC and unmatched TEST status stays blocked.
4. Independent implementer should understand SPEC alone. Any reverse-engineering-dependent missing field returns to S00/Txx.
5. No Client launch/capture, use of official remote Server, or separate actual Server repository modification is authorized here.

## Read-only commands

~~~powershell
python -B governance/phase_b_worklist.py --format markdown
python -B governance/phase_b_worklist.py --task T02 --version kr --format json
python -B governance/phase_b_worklist.py --task T03 --version kr --format markdown
python -B governance/phase_b_worklist.py --version tc --format json
python -B governance/phase_b_worklist.py --check
python -B governance/check_s00_reviews.py --check
python -B governance/check_contract_coverage.py --check
python -B governance/check_s00_readiness.py --check
~~~

The --check flag fails on invalid links/version/state, **not** merely on eight QUEUED RR or blocked Phase B contracts.

## Next-chat handoff

Read the latest main, this protocol, Iteration 06 results and the live worklist. Reconfirm each RR state before editing it. GitHub updates do **not** automatically wake an Agent. Do not treat an unlaunched T02/T03 Agent as already working.


## Iteration 07: submitted research review packet

Run `python -B governance/phase_b_review_preflight.py --rr RR-0001 --format markdown` after an actual submission. It checks canonical report bytes against the RR's Git blob SHA, rejects unsafe paths and shows direct impact SPEC/GAP/COV/TEST and existing UNKNOWN fields. Mechanical artifact presence is **not** a review approval; T01/S00 must separately decide bounded native quality and the RR's acceptance conditions. The new tool never modifies dispatch, reviews or SPEC states.
