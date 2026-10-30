# S00 — Server Requirement Candidate Registry

[Authoritative intake policy](../../governance/S00-SERVER-REQUIREMENT-SOURCES.md) | [Machine-checkable candidates](index.json)

This is a **non-normative S00 discovery inbox**, not a second RR registry and not a list of approved Server MUSTs. There are three active `origin` choices, each sufficient **on its own** to propose a requirement:

1. `CODE_ANALYSIS`: reverse engineering any Client send, receive, handler, scene/state transition, error branch or code path whose completion requires a Server-facing contract.
2. `RUNTIME_OBSERVATION`: direct observation of the game under **separately authorized** execution with preserved versioned record.
3. `USER_REQUEST`: a player, administrator or maintainer asks for a new Server behavior or goal. **User-provided historical protocol/old Server data (the formerly proposed item 5) belongs here as `reference_materials`, not its own origin.**

Additional suggested origins remain **proposals only**: Client assets/configuration, implementation or conformance feedback, and external official/community documentation. They can be cited as research context but do not automatically create another active origin class.

Every candidate has `id`, `origin`, `evidence_status`, `direction`, an evidence anchor (`source_path` and registered `source_claim_ids` where relevant), `requirement`, `unknowns`, and references to existing SPEC, GAP and RR. A candidate may be created even when a packet opcode or reply is UNKNOWN, as long as the conditional need and evidence are accurately stated.

**No extra independent source is required.** For `CODE_ANALYSIS` a bounded native/CLM reference is sufficient to open a candidate; its evidence class is `CLIENT_STATIC_BOUNDED`, not an observed original Server packet. For a `USER_REQUEST` the evidence class is `USER_INTENT_ONLY`, which is valid for the feature request but not native Client behavior. For `RUNTIME_OBSERVATION` an explicitly authorized record is required and does not infer global protocol policy.

Task agents T01–T16 should **suggest new Server requirements in their own technical reports**, with addresses, branches, negative cases, source path and target/version where possible; they do not directly edit this S00-owned index unless specifically assigned by the maintainer. S00 deduplicates and adds candidates; research gaps use the existing RR workflow only when not already covered. Human SPEC/ADR decisions are separate.

Current entries are four candidates (three code-based, one user request); no original Client was run and none of the candidates are approved. The existing seven SPEC remain DRAFT/PARTIAL, GAP remain OPEN and no original Client/Server compatibility is claimed.

Run from repository root:

```powershell
python -B governance/check_server_requirements.py --check
python -B governance/check_server_requirements.py --json
python -B -m unittest discover -s governance/tests -v
```
