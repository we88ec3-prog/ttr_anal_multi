# S00 Server-only design proposals

Current ADR-0001..0003 are **PROPOSED**, not approved, not normative, and not assertions about the original game's Server. They are potential implementation architecture directions; the actual Server code lives in a different repository. The `spec/spec-index.json` deliberately does not list these proposals as a normative ADR dependency.

| Draft | Topic | Evidence boundary |
| --- | --- | --- |
| [ADR-0001](ADR-0001-session-boundaries.md) | Transport connection vs Server session | No proven initial wire mode/handoff yet |
| [ADR-0002](ADR-0002-auth-policy.md) | Account storage/verification policy | E8/000F Client payload is not historical Server DB behavior |
| [ADR-0003](ADR-0003-character-authority.md) | Character record storage and ownership | 0x42 response and 65-byte prefix semantics still unresolved |

To approve: maintainer separately verifies scope, risks, independently implementable interfaces and source-backed wire requirements; record outcome and impacted SPEC/TEST in an explicit review. **Do not auto-promote a SPEC, close a GAP or ACCEPT an RR** because an ADR proposal exists. No sensitive account data belongs here.
