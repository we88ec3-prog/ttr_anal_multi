# S00 Server-only design proposals

Current ADR-0001..0005 are **PROPOSED**, not approved, not normative, and not assertions about the original game's Server. They are potential implementation architecture directions; the actual Server code lives in a different repository. The `spec/spec-index.json` deliberately does not list these proposals as a normative ADR dependency.

| Draft | Topic | Evidence boundary |
| --- | --- | --- |
| [ADR-0001](ADR-0001-session-boundaries.md) | Transport connection vs Server session | No proven initial wire mode/handoff yet |
| [ADR-0002](ADR-0002-auth-policy.md) | Account storage/verification policy | E8/000F Client payload is not historical Server DB behavior |
| [ADR-0003](ADR-0003-character-authority.md) | Character record storage and ownership | 0x42 response and 65-byte prefix semantics still unresolved |

To approve: maintainer separately verifies scope, risks, independently implementable interfaces and source-backed wire requirements; record outcome and impacted SPEC/TEST in an explicit review. **Do not auto-promote a SPEC, close a GAP or ACCEPT an RR** because an ADR proposal exists. No sensitive account data belongs here.

## WEB 後台 Server-only 提案（2026-10-31）

- [ADR-0004 — Admin WEB 身分、權限、稽核與隔離部署](ADR-0004-admin-web-security-boundary.md)：支援 REQ-0006/0007/0008；與玩家登入及 C00 diagnostic Host 分離。
- [ADR-0005 — 管理停權的 UTC 期限、資料持久化、Session revocation/fencing](ADR-0005-account-sanctions.md)：支援 REQ-0008；**不共用** C02 failed-password `locked_until`。

二者皆為版本中立、`PROPOSED`、`client_version=null`，不與 KR/TC wire 綁定；未來要核准必須經維護者明確批准安全／資料／故障策略，不能只因 Git merge 就自動變成 normative。
