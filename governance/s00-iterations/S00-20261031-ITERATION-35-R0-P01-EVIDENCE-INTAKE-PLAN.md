# S00 Iteration 35 — C05 R0/P01 可稽核證據收件與拒收工具

**2026-10-31 · 設計／治理工具，不是 Server C05 實作或原版 KR Client 互通。** 承接 [Iteration33 C05-P01～P19 的 DAG](S00-20261031-ITERATION-33-C05-INTEGRATED-DELIVERY-PLAN.md) 與 [Iteration34 實際 Server 差異](S00-20261031-ITERATION-34-C05-R0-SERVER-DELTA-PREFLIGHT.md)。本輪**不重複建立第三份 C05 實作路線圖**，而是提供可執行的、供未來真正 Server PR 提交 evidence receipt 的審前自檢工具；在真實成果未交付前明確維持 NO_RECEIPT。

## 1. 重新核對的實際基準

| 項目 | 本次核對 | 此項不能證明 |
| --- | --- | --- |
| S00 上一版 main | `bfaca5b7690e4d1deba95ca68ae3feccb946ba85`；Iteration34 主線 CI `41185000160` SUCCESS | Server 的 C05 本體 |
| Server main | `we88ec3-prog/ttr_server_roy@3e0b7e3a8666f363f747dbf68c2fd462a8777b09`，與 Iteration34 的觀察相同 | P01 已寫入 |
| Server CI | 該 Server SHA 四組已成功：C00 validation `41183934552`、.NET `41183934606`、C01 `41183934657`、PG C02/C03 `41183934579` | C05 的 admission / migration / PostgreSQL 停權同等性 |
| Server 原始碼 | C03-C `PostgresCharacterActions` 使用 Session row lock + transaction；`SqliteCharacterStore` 有獨立交易路徑，`ISessionLeaseRegistry` 提供 Lease 介面；PG migration `003_c03_selection.sql` 已存在 | P01 Encounter reservation 已與 C03 同交易 |
| 仍待審 | D33-01～08 所有政策、單一 SQLite/PG C05 migration 序列、P01 admission 真測試及 PG ban parity | 不得憑本 S00 checker 當作已 APPROVED |

上述為 **source-pinned 靜態版本觀察**，不是動態 GitHub 同步機制。現行 C03 PostgreSQL 將 Session row lock 作為同交易角色授權的既有範例，但移用到 Encounter **必須新增真正的 P01 實作／交易測試**，不可藉 reference code 宣稱已存在。

## 2. 收件目的與兩層把關

1. **S00 本地檢查**：`python -B governance/check_s00_iteration35.py --check`。核對 [唯一 I35 收件狀態](S00-ITERATION-35-C05-EVIDENCE-INTAKE.json) 的五個槽位、Iteration34 原始 Git blobs、12 個 NOT_RUN、Client native OFF、Decision 未核准，全部機械一致。這只驗收**誠實的未提交狀態**。
2. **Server 證據草案收件**：`python -B governance/check_s00_iteration35.py --candidate <receipt.json>`。檢查來源、完整 SHA、明確的 provider/slot、source-file manifest、與單一 Server commit 綁定的 GitHub Actions 收據、關鍵負向測試、policy/migration/atomicity 欄位。**若格式可審，回傳 `STRUCTURALLY_REVIEWABLE_NOT_APPROVED`，絕非批准或 PASS。**
3. **正式受理的人工複驗**：S00/Server maintainer 從 GitHub 遠端以實際 HEAD/commit、Git blob、CI `head_sha`、artifact、DB schema dump/checksum、原始可重現測試及簽核紀錄讀回核對；如不符，仍不可變更槽位狀態。具體 owner 遵照 [既有 S00 流程](../s00-workflow.md)。原始 Client 的 Native R6 持續由原生證據及另行授權實測獨立決定。

本輪驗證器**不呼叫 GitHub、不解析真資料庫、不跑 Server、不執行原版 Client**。輸入是外部提供的未受信 JSON；任何 SHA、test name、approval reference 均可由提交者任意文字填入，必須在第三步核對，CI 結果不能自動修改正式台帳。

## 3. 收件槽位與最小證據

| 收件 slot | Source owner | 結構收件的必備內容 | 未通過時 |
| --- | --- | --- | --- |
| `R0-POLICY` | Server maintainer | D33-01～D33-08 每項決策、reviewer／approval source SHA／policy revision；仍需逐項真的簽核 | 不得套用新的生產政策 |
| `R0-SQLITE-MIGRATION` | DB owner | SQLite baseline=2；同 provider 遞增不重複版號、migration SHA、單一 manifest SHA256、前置版本、fresh/upgrade/duplicate/recovery 等負向測試 | 保持 SQLite C05 schema 未配號 |
| `R0-POSTGRES-MIGRATION` | DB owner | PostgreSQL baseline=3；相同 manifest 和 DB schema 檢核，另查帳號停權/Session parity | 不得假定 PG ban parity |
| `P01-SQLITE` | Gameplay maintainer | exact SessionId/AccountId/ConnectionId/Revision/ExpiresAt、role owner、ban、同 DB transaction CAS、AdmissionId+fingerprint、並發/重試/crash | 不得宣稱 P01 durable |
| `P01-POSTGRES` | Gameplay maintainer | 上述 P01 證據且完整 Postgres policy 或明確 fail-closed；必須獨立 CI | 不得聲稱跨 provider 相容 |

任何 P01 的內部 API 都是**新 Server 自訂模型**，不對外使用原版 Client app opcode。拒收原版 Client `SceneLoaded`／`WorldReady`、Quest15 AVAILABLE、S2C0x004C 作 Server admission 已成功的假證據。收件資料不得包含使用者憑證、Token、Private DB、原始受保護資源或真玩家個資；僅公開去敏 metadata。

### Candidate receipt JSON 形狀

```json
{
  "schema": "s00-iteration35-server-c05-receipt-v1",
  "slot": "P01-SQLITE",
  "repository": "we88ec3-prog/ttr_server_roy",
  "server_commit": "<40位完整GitSHA>",
  "owner": "Server maintainer",
  "source_files": [{"path":"src/Example.cs","git_blob_sha":"<40位完整GitSHA>"}],
  "ci_runs": [{
    "run_id": 12345,
    "head_sha": "<相同Server Commit>",
    "url": "https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/12345",
    "conclusion": "success",
    "scope": "SERVER_OFFLINE_TEST",
    "test_ids": ["lease_race", "role_reselect", "ban_race", "replay_same", "replay_conflict", "crash_recovery", "transaction_atomic"]
  }],
  "native_adapter_enabled": false,
  "original_client_executed": false,
  "domain": "SERVER_MOCK_ONLY",
  "details": {
    "provider": "SQLITE",
    "policy_revision": "待真實批准的修訂號",
    "migration_manifest_sha256": "<64位SHA256>",
    "atomic_same_transaction": true,
    "fingerprint_collision_rejected": true,
    "admission_key_fields": ["AdmissionId", "AccountId", "SessionRevision"],
    "authority_fields": ["AccountId","SessionId","ConnectionId","SessionRevision","ExpiresAt","RoleId","Suspension"],
    "postresurrection_old_epoch_rejected": true
  }
}
```

上述 placeholder **不是實際可審收據**；測試程式中用虛構 SHA 產生的正向 fixture 只證**檢查器行為**，不證真的 Server 功能。未取得同版 source 與可重現 CI 時不得填入本庫的真實台帳或設為 APPROVED。

`R0-POLICY` 的 details 必須有 `policy_revision`、八項 `decisions`，每筆 `id`、`decision`、`approval_ref`、`approval_git_blob_sha`；`R0-*-MIGRATION` 必須有 provider、base_version、manifest_sha256、至少一個有序 `allocations`（version、module、path、sha256），且 CI `test_ids` 覆蓋 `fresh,upgrade,duplicate_version,mixed_old_new,backup_restore,crash_recovery`。這是證據**形狀**，不是版本號或政策批准。

## 4. 靜態接收與真正的 R0 Release 門檻分離

`NO_RECEIPT → STRUCTURALLY_REVIEWABLE_NOT_APPROVED → EXTERNALLY_VERIFIED_BY_OWNER → FORMALLY_REVIEWED` 是**待實作的治理意圖**，不是本輪修改正式 R0 state machine 或讓外部 JSON 控制 S00 進度。其間需二次確認：GitHub 檔案 blob/commit 身分、持久化 provider schema、CI 截圖與 trace 對應性、PR 內 review/approval 真實性。**不得拿 CLI 結構驗證的 exit 0 當作 Server C05 R0 PASS。**

### I35-T01～T12（全數 PLAN_ONLY / NOT_RUN）

| ID | 預期下游驗收對象 |
| --- | --- |
| I35-T01 | Server commit／source Git blob 遠端重取與固定 HEAD |
| I35-T02 | CI run head_sha / name / scope / test artifacts 遠端查核 |
| I35-T03 | 政策 D33-01～08 的授權身分、policy revision、ADR 選項 |
| I35-T04 | SQLite 單一 migration 版本、禁止重用與增量升版 |
| I35-T05 | PG 獨立 migration、schema 與 rollback |
| I35-T06 | SQLite/PG 各自 fresh/upgrade/backup/crash/old-new |
| I35-T07 | 同交易 Session lease/selected role/ban CAS |
| I35-T08 | Ban/renew/reselect/expire 並發造成的 stale write=0 |
| I35-T09 | 相同 AdmissionId + fingerprint 的 idempotent replay |
| I35-T10 | AdmissionId 相同而 fingerprint 改變時拒絕 |
| I35-T11 | Crash/restart 後 reservation/ledger 不重複 |
| I35-T12 | Mock R1 與原版 Client native R6 的嚴格隔離 |

此 12 項是**未執行的實作驗收規劃**，不是正式 `conformance/test-index.json` 的已執行測試。新 governance Python 單元測試只測收件驗證器在篡改輸入時有沒有 fail-closed，不是 I35-T01～T12 的真 Server CI。

## 5. 目前與下一輪交接

- **本輪已交付**：機讀收件空狀態、外部 receipt 靜態 CLI、拒收回歸測試、CI 持續防止假升格，詳細接受與缺件說明。
- **本輪未完成也不可宣稱完成**：D33-01～08 owner approval、C05 schema migration allocation、C05-P01 真實 Server PR／DB transaction tests、原版 Client 功能測試。
- **Iteration36 的有效觸發**：從 Server 專案交來真 R0 policy/migration 或 C05-P01 commit/CI/trace，S00 依本輪 receiver 先做結構分類，再以原始來源獨立複核、必要時提出 SPEC/ADR/FB 或研究 RR；若仍無成果，**應等待具體工作輸入而非為增加迭代數再製作同義 PR 規劃**。
- **狀態隔離**：不修改正式 REQ/RR/GAP/CLM/SPEC/TEST/ADR、Task owner、獨立 Server Repo；原版 Client 原件唯讀、不執行、Native Adapter OFF。
