# S00 Iteration 28 — C05 W01～W03 可執行交接驗收測試草案

**16/16 全部 PLAN_ONLY / NOT_RUN**。這些 **I28** 測試是下游 Server 準備實作時用的測試規格，不是本回合實際執行結果，也不是正式 `conformance/test-index.json` 的 TEST，不能被當成原版 Client 功能已可玩。

參考 [完整設計](S00-20261031-ITERATION-28-W01-W03-IMPLEMENTATION-PLAN.md)、[機讀契約](S00-ITERATION-28-C05-W01-W03-CONTRACT.json)。僅測**新 Server 的 Mock/Domain**；原版 Client C2S/Scene/Actor 封包不可由測試自行補齊。

| ID | Work pack | 分類 | 刺激／前置 | Mock Server-only 預期 |
| --- | --- | --- | --- | --- |
| I28-T01 | S28-01 | AUTH | Valid lease and selected owned CharacterId | Atomic reservation once; EncounterId returned; Client scene readiness remains unknown |
| I28-T02 | S28-01 | RACE | GetSelectedAsync snapshot then Session renewal/reconnect before CreateEncounter | Atomic reservation rejects old full lease; no check-then-act vulnerability and no encounter row |
| I28-T03 | S28-01 | NEGATIVE | Account A Session selects role owned by Account B | NotOwned/AccessDenied, zero events/rows; role GUID never trusted from unverified Client slot |
| I28-T04 | S28-01 | REPLAY | Same RequestId, valid current full lease, concurrent retries | Return same reserved encounter/result, not two encounters or two client-ready signals |
| I28-T05 | S28-01 | NEGATIVE | Replay old RequestId after lease revision replaced or account revoked | Fail closed despite dedup hit, stale epoch cannot recover success response |
| I28-T06 | S28-02 | STATE | RESERVED -> ACTIVE with correct scene/role/version | Advance once with expected revision and valid lease, no implicit original tutorial ready |
| I28-T07 | S28-02 | CONCURRENCY | Two workers activate same encounter with same revision | One wins, other Conflict/idempotent replay, revision monotonic |
| I28-T08 | S28-02 | RECOVERY | Commit RESERVED then crash/restart before ACTIVATE | Reopen durable record, no duplicate EncounterId, no presumed client scene loaded |
| I28-T09 | S28-02 | FENCING | Disconnect, ban, renewal or new SessionEpoch while ACTIVE | Old epoch cannot mutate, terminal/abort monotone; preserve approved-only resume policy |
| I28-T10 | S28-03 | DETERMINISM | Same mock config digest+seed/spawn ordinal repeated after restart | Actor IDs, positions and spawn order deterministic; explicitly mock-only, no original Scenario14 wave claim |
| I28-T11 | S28-03 | NEGATIVE | Wrong fixture digest, missing mock template or oversized spawn budget | Fail before state change; bounded memory/allocation |
| I28-T12 | S28-03 | RACE | Duplicate spawn event key from concurrent workers | At most one actor set, event dedup unique, actor revision monotone |
| I28-T13 | S28-03 | AI | Same fixture state and tick triggers AI twice | Single deterministic Server-owned AI step and equal state hash; tie-break recorded |
| I28-T14 | S28-03 | NEGATIVE | Cross-encounter ActorId or client-forged AI action | Reject without modifying owner/target actor; no native ActorId inference |
| I28-T15 | S28-03 | MOVEMENT | Old tick, impossible displacement, invalid role/scene | Reject based on mock bounds; unchanged position and aggregate revision |
| I28-T16 | S28-03 | RECOVERY | SQLite/PostgreSQL crash/restore and old actor event replay | Provider-specific migration/restore integrity and dedup persistence; both adapters still OFF |

## 驗收實作實務

先跑 `I28-T01～T05` 解決真正的選角→Encounter 原子性；再跑 `T06～T09` 建狀態機、重連／重啟；最後跑 `T10～T16` 生成及 AI。後續 `W04` 的玩家技能/傷害只能在此基線有版本化 Actor 狀態且通過 lease fencing 時接入。

測試資料應包含：
- 固定來源：實際 `server_commit`、`s00_plan_commit`、SQLite user_version / PostgreSQL migrations、fixture_sha256、mock_seed、fake-role/actor/encounter ids、case ID、期望與實際結果。
- 每個並行測試記錄 transaction 排程（例如先讀 selected role、再續租/重登、後寫入）、commit/rollback 結果與唯一 request/event key；`PASS` 要基於實際 assertion 不是敘述。
- SQLite 與 PostgreSQL 使用**獨立資料庫與 migration**測試；包含不觸及既有 C02/C03 登入／選角資料的升級回復驗證，PostgreSQL 可使用 CI disposable service，不能用生產資料。
- `evidence_class=DOMAIN_SYNTHETIC` 的 PASS 只能用於 Server-only Domain acceptance；若需宣稱 `COMPAT_CLIENT_RUNTIME`，必須另行授權原版 Client、同版 SHA 及真正的 frame/Conn/Scene/Actor/UI trace。

**安全反例：** 不能把 C03 `GetSelectedAsync` 取得的資料當作跨交易永遠有效的權杖；不能由原版 UI 顯示或局部 Client handler 推論世界/AI已就緒；不能把任何 mock 的 NPC IDs、座標、HP、時間或勝利條件當原始 Scenario14 正規值。
