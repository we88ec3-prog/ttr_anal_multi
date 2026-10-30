# S00 Server-only design proposals

Current ADR-0001..0005 are **PROPOSED**, not approved, not normative, and not assertions about the original game's Server. They are potential implementation architecture directions; the actual Server code lives in a different repository. The `spec/spec-index.json` deliberately does not list these proposals as a normative ADR dependency.

| Draft | Topic | Evidence boundary |
| --- | --- | --- |
| [ADR-0001](ADR-0001-session-boundaries.md) | Transport connection vs Server session | No proven initial wire mode/handoff yet |
| [ADR-0002](ADR-0002-auth-policy.md) | Account storage/verification policy | E8/000F Client payload is not historical Server DB behavior |
| [ADR-0003](ADR-0003-character-authority.md) | Character record storage and ownership | 0x42 response and 65-byte prefix semantics still unresolved |

To approve: maintainer separately verifies scope, risks, independently implementable interfaces and source-backed wire requirements; record outcome and impacted SPEC/TEST in an explicit review. **Do not auto-promote a SPEC, close a GAP or ACCEPT an RR** because an ADR proposal exists. No sensitive account data belongs here.

## WEB 後台 Server-only 提案（2026-10-31）

- [ADR-0004 — V1 來源 IP 白名單＋固定管理網址（暫不做登入／RBAC）](ADR-0004-admin-web-security-boundary.md)：支援 REQ-0006/0007/0008；與玩家登入及 C00 diagnostic Host 分離，保留私網、代理信任界線及 CSRF 防護；網址本身不是密碼。
- [ADR-0005 — 管理停權的 UTC 期限、資料持久化、Session revocation/fencing](ADR-0005-account-sanctions.md)：支援 REQ-0008；**不共用** C02 failed-password `locked_until`。

二者皆為版本中立、`PROPOSED`、`client_version=null`，不與 KR/TC wire 綁定；未來要核准必須經維護者明確批准安全／資料／故障策略，不能只因 Git merge 就自動變成 normative。


## Iteration 25 — 首次教程狀態與重登之 Server policy（2026-10-31）

- [ADR-0006 — per-role TutorialProgress、SessionEpoch/AdmissionId、checkpoint、Quest/reward 去重及重登](ADR-0006-tutorial-progress-and-session-fencing.md)：**PROPOSED、尚未批准、NON-NORMATIVE**。對應 [Iteration25](../../governance/s00-iterations/S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md)；其 per-role 首次判定／mode2／Skip／完成條件、Lua checkpoint replay、Reward ledger 交易需維護者決議，不自動寫回原版 Client 協定。
- 現在共有 ADR-0001..0006，**皆仍是 PROPOSED**。新的 C-TUTORIAL-DOMAIN roadmap package 只是獨立 Server 測試路線，check_s00_readiness 應維持 EXTERNAL_REVIEW_REQUIRED；不代表 Main 已發展出可玩的 native Client Server。
