# S00 Iteration 34 — 16 項 Server 差異與 C05-P01 開工驗收（未執行）

**PLAN_ONLY／NOT_RUN，並非正式 conformance TEST。** 只定義本輪新增的 Versioned Server 實作回饋、R0 前置條件和 P01 授權／冪等測試。原始來源、狀態與阻塞見 [Iteration34 規劃](S00-20261031-ITERATION-34-C05-R0-SERVER-DELTA-PREFLIGHT.md) 和 [機讀快照](S00-ITERATION-34-C05-R0-SERVER-DELTA-CONTRACT.json)。本庫的 Python checker 只是設計完整性驗證，**不是下表的真實執行結果**。

| ID | 類別 | 必須驗收的情境 | 接受證據 | 執行責任 | 狀態 |
| --- | --- | --- | --- | --- | --- |
| I34-T01 | SOURCE | compare old/new Server main, head + 21 commits and path list | Versioned GitHub compare with head and 14 changed paths | S00 reviewer | **NOT_RUN** |
| I34-T02 | SOURCE | WEB admin docs/code identity and existing SQLite v2 restriction | Blob SHA of Program, runbook, DB path/reader | S00 reviewer | **NOT_RUN** |
| I34-T03 | NEGATIVE | Reject non-loopback URL/Host; reject nonexistent DB | Real server test receipt, no public route | Server maintainer | **NOT_RUN** |
| I34-T04 | NEGATIVE | Do not infer PG WEB Admin from PG C02/C03 CI | Explicit provider-specific implementation inventory | Server maintainer | **NOT_RUN** |
| I34-T05 | GOVERNANCE | REQ-0006 local implementation vs requested configurable IP+URL | Approved decision and testable remaining gap | S00 + maintainer | **NOT_RUN** |
| I34-T06 | GOVERNANCE | REQ-0007/0008 scope: local create/ban vs PG+multi-instance | Provider-split scope receipt; no status auto-promotion | S00 + maintainer | **NOT_RUN** |
| I34-T07 | MIGRATION | Unique append-only provider migration allocation | Manifest/version/file SHA; duplicate version rejected | DB release owner | **NOT_RUN** |
| I34-T08 | MIGRATION | Each provider new/upgrade/crash/backup/restore | SQLite and PG isolated CI traces and schema hashes | DB release owner | **NOT_RUN** |
| I34-T09 | DOMAIN | P01 same-transaction lease/owned selected role/admission | DB transaction proof, race harness, distinct negative reasons | Server C05 maintainer | **NOT_RUN** |
| I34-T10 | CONCURRENCY | Ban, revoke, reselect, expire racing admission | Multithread/interleaving receipts; stale writes=0 | Server C05 maintainer | **NOT_RUN** |
| I34-T11 | IDEMPOTENCY | Same AdmissionId+fingerprint replay | Same durable reservation, no new rows | Server C05 maintainer | **NOT_RUN** |
| I34-T12 | NEGATIVE | Same id, changed fingerprint | Atomic conflict without encounter mutation | Server C05 maintainer | **NOT_RUN** |
| I34-T13 | RECOVERY | Crash post-reservation and resume | Stable state, no duplicate admission/event | Server C05 maintainer | **NOT_RUN** |
| I34-T14 | NEGATIVE | PG suspension semantics missing | Provider policy fail-closed until proven | Server C05 maintainer | **NOT_RUN** |
| I34-T15 | SOURCE | C04 offline codec tests are not original Client success | No native/real-wire promotion in handoff | T02/T03/S00 | **NOT_RUN** |
| I34-T16 | NATIVE_NO_GO | R1 mock pass may not bypass original KR runtime gate | Native adapter remains OFF; authorized real-client trace separate | S00 + Client owners | **NOT_RUN** |

## 實際測試收據最低欄位

`server_repo, server_commit, upstream_s00_commit, branch_or_pr, provider, schema_version, migration_manifest_sha256, policy_revision, fixture_sha256, test_id, test_command, expected, actual, conclusion, trace_or_artifact_url, evidence_class, known_client_gap, operator`。沒有真實執行者、工具輸出或對應 commit，保持 NOT_RUN；沒有授權的原版 Client trace，不可宣稱 NATIVE_COMPATIBLE。

## No-Go 判準

- 沒有單一 migration 配號和 PostgreSQL/SQLite 個別測試收據時，不宣稱 R0 已通過或 P01 可持久化上線。
- 沒有 PG 帳號停權 parity 證據時，PG Admission 須 fail-closed；不能把 SQLite local 已通過宣稱跨 provider 成功。
- 重登／Session renew／ban／角色切換競態使 stale 版本能成功寫 Encounter 時，P01 不驗收。
- 同 AdmissionId 不同 payload 仍可寫入、或相同 payload 重試產生第二筆入場時，P01 不驗收。
- 任何本地 mock、WEB 管理 CI 或 C04 synthetic success 均不得解鎖 original Client native adapter；R6 需正式同版來源與另行授權的原版 Client E2E。

**正式 RR/REQ/GAP/CLM/SPEC/TEST/ADR 不因本規劃自動更新。** 可繼續依既有 Task 補證；沒有依賴已成立的 Server PR 實際收據，不能將 I34-T01～T16 標記 PASS。
