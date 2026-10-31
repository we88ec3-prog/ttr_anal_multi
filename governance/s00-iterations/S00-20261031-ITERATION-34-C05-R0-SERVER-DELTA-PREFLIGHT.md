# S00 Iteration 34 — 實際 Server 差異收件、C05 R0／P01 入場前置驗收

**2026-10-31｜S00 規劃／實作回饋整合，非 Server 程式、非原版 Client 實測。** 接續 [Iteration33](S00-20261031-ITERATION-33-C05-INTEGRATED-DELIVERY-PLAN.md) 的 C05-P01～P19 DAG。本輪**不新增第20個同義 C05 PR**，也不把 WEB Admin、合成測試或 CI 成功當作 C05 gameplay 已完成。產物是固定來源的真正跨庫差異審查、R0 決策／P01 開工封鎖清單與可執行的離線規劃結構檢查。

## 1. 已確認的實作增量（不是推測）

| 欄位 | 2026-10-31 來源快照 |
| --- | --- |
| 本庫上一輪 main | `e80b06d8cc7160b5624fa057c8635198fee9df29`，Iteration33 已合併 |
| 先前 Server snapshot | `we88ec3-prog/ttr_server_roy@272079cc69b124870af303d711931ec20bce2229` |
| 本輪 Server head | `we88ec3-prog/ttr_server_roy@3e0b7e3a8666f363f747dbf68c2fd462a8777b09` |
| 兩個 Server commit 間 | GitHub compare `ahead=21, behind=0`；14 條變更檔案（僅此版本快照） |
| 主要實際新增 | 獨立 `src/Tartaros.Admin.Web`、`SqliteWebAdminReader`、WEB smoke 和 xUnit 測試、runbook、SQLite 相對路徑修正 |
| 不變的 Client 相容門檻 | Server `contracts/spec-revision.json` 仍 pin S00 `dd69ec9...`、`implemented_wire_contracts=[]`；原生 Client runtime 未授權、未通過 |
| 真正 C05 | Server `docs/DEVELOPMENT-PLAN.md` 仍標記 C05 `BLOCKED BY EVIDENCE`；P01～P19 **沒有被此差異證明實作** |
| 提交時確認的 CI | Server head 四個工作流 SUCCESS：C00 validation、.NET build/test、C01 transport、C02/C03 PostgreSQL；皆只證既有適用範圍 |

證據採 [Iteration34 機讀差異與開工契約](S00-ITERATION-34-C05-R0-SERVER-DELTA-CONTRACT.json) 中的 repo、head、Git blob、Actions run URL；該 JSON 是**一次性唯讀觀察**，CI 不會連線重新驗證遠端 Server，也不代表最新 Server 仍停留於這個 SHA。後續接手務必再查實際 Server main／Actions，不可把歷史快照當 live status。

## 2. WEB-ADMIN-001 的收件分類與現行 REQ 不一致之處

本輪實際 Server 交付是**本機 loopback-only** WEB 管理程式：`http://127.0.0.1:<port>/admin`、指定**既有** SQLite v2 `--db`、來源 Host guard、POST antiforgery、帳號建立／查詢／停權／解封、部分稽核、備份及過期 Session 清理。依 [Server runbook](https://github.com/we88ec3-prog/ttr_server_roy/blob/3e0b7e3a8666f363f747dbf68c2fd462a8777b09/docs/WEB-ADMIN-LOCAL.md)，沒有 PostgreSQL WEB 管理、遠端自訂 IP allowlist、HTTPS／生產級權限、具操作員身分的稽核。這是 **OFFLINE_SERVER_IMPLEMENTATION**，不等於 S00 設計需求已 APPROVED 或正式驗收完成。

| 正式來源 | 與實作的關係 | 本輪決定 |
| --- | --- | --- |
| `REQ-0006` 管理存取 | 使用者選定「指定 IP + URL」、原先 S00 設計含可配置來源 IP/CIDR；目前 Server **強制 127.0.0.1**。本機可驗收、指定遠端 IP 不成立 | 記錄 **PARTIAL_LOCAL_ONLY**，不修改 REQ 的 CANDIDATE 或 ADR；遠端存取前另審查可信代理/TLS/CSRF/來源 IP spoofing |
| `REQ-0007` 建立玩家帳號 | 有 SQLite 本機 WEB 的實際實作；不是原 Client 創角，也不證 PostgreSQL 同等 | **OFFLINE_LOCAL_IMPLEMENTED_SCOPE**，正式需求仍需批准及端到端驗收 |
| `REQ-0008` N 天／永久／解封 | 有 SQLite 本機 moderation、Session revoke 與本機 smoke；不能外推至 PG／所有分散 Session | **OFFLINE_LOCAL_IMPLEMENTED_SCOPE**，跨 provider、異常重登與防重放仍需測 |
| `ADR-0004/0005` | S00 仍 PROPOSED；不因某實作已存在而倒填成已批准歷史決議 | 保持提案，進行獨立 maintainer 決策 |

**不用新增 REQ／FB／RR 取代既有台帳。** 本輪把有界的實作回饋記在 Iteration34；若 Server owner 之後提報具體缺陷，依 [現有 FB 流程](../../design/feedback/README.md) 核對其實際路徑與可複驗測試，不虛構已建立的 FB。

## 3. R0 — 現有程式支持哪些 C05 前置？哪些仍禁止默認

**已可復用（本輪唯讀確認）：** C03-C 提供角色選擇與 Session 交易基底；SQLite local v2、PostgreSQL migration 003 曾由 [Iteration33](S00-20261031-ITERATION-33-C05-INTEGRATED-DELIVERY-PLAN.md) 核對，Server 最新 `SqliteLocalDatabase.cs` 仍保留 v2；WEB Admin 採本機 existing-v2 fail closed、不會自動解決 C05 migration。C04-A/B/C 為 source-scoped offline，非原生完整 handshake。

**尚未完成（R0 必須顯式保留）：**
1. C05 schema **單一** provider migration manifest／版本配號／檔 SHA／回復策略：`UNALLOCATED_NOT_APPLIED`；不能把 I28～30 分別候選的 SQLite v3 / PG004 直接視為已用。
2. 產品政策 D33-01～D33-08 仍缺真正 maintainer 核准及版本化決策；ADR-0006/0007 PROPOSED。
3. PostgreSQL 帳號停權/撤銷 Session **與 SQLite local v2 的同等交易語義**不能因 PG C02/C03 CI PASS 而推定。
4. Server `contracts/spec-revision.json` 尚未升到 S00 最新且 `implemented_wire_contracts=[]`；原生 adapter **OFF**，不得偷偷以 mock 封包冒充 KR。
5. 原版 Client 教學與 E17-A/J、E23～E26、選角→scene 仍有未知正向因果鏈。R6 原版 Client 測試未授權、未執行。

R0 **不要求**等原生 Server 全部協定完整後才能寫 mock domain；但要先由 Server owner 取得明確 policy/config/schema 身分，才能宣稱 P01 可提交可重現的持久化 PR。

## 4. C05-P01 可交付的最小工作單位（僅提案，不是已完成）

**目的：** 把已存在的 C03 Session/角色交易能力擴為 **Mock EncounterAdmission** 的單一權威 gate。不是為原版 Client 發封包，不是複製第二套 Account/Character DB。

`P01` 的一次入場請求：`AdmissionId, AccountId, RoleId, SessionId, ConnectionId, SessionRevision, ExpiresAt, RequestFingerprint`；伺服器必須從 DB 權威值重新驗證，不接受 client 自報權威。交易與併發規則：

1. 同一個 DB 交易內核對 account/selected owned role、現行 Session tuple（含 revision／到期）與**該 provider 已確認可用的停權判定**；禁止先外部 `IsCurrentAsync` 再跨交易 insert。
2. 同一 `AdmissionId + AccountId + SessionRevision`、相同 payload fingerprint 的重試只能返回同一 reservation；相同 id 不同 fingerprint 返回衝突且不建立新 Encounter。
3. 新的 Session claim、revocation、ban 或角色重選和 admission 發生競態時，失效版本不得成功寫入。不可由 stale request 覆寫新 lease/role。
4. Encounter 先 `RESERVED`，後續 P02 才有 `ACTIVE/TERMINAL`；只預留不能自稱 Client 已 SceneLoaded、WorldReady、Actor visible。
5. SQLite local 與 PostgreSQL 用各自支援的 transaction/lock/CAS；同等性只能分別測過才聲稱。未核准 migration 不落正式 schema，PG suspension parity 未證就 **fail closed**。
6. 負向結果需穩定內部 reason code、不得洩露憑證／Session token，依模組可重現 trace 記錄拒絕與衝突。
7. P01 PR 應附真實 `server_commit`、source pin、schema manifest digest、provider-version、policy revision、CI run、replay/fault trace；少任一關鍵資料仍 **NOT_ACCEPTED**。

### P01 必須交給 Server owner 的接口

- **Domain**：`IEncounterAdmission.TryReserveAsync` 返回 `Reserved/SameReservation/DeniedStaleLease/DeniedBan/DeniedOwnership/ConflictFingerprint/UnavailableProviderPolicy`（命名是**新 Server 設計候選**，不是官方 KR opcode）。
- **Persistence**：`EncounterReservation` 的 identity、lease epoch/fingerprint 唯一約束與 CAS；migration 只能由單一 allocator 配號。
- **Concurrency**：兩個同時 admission、role select、ban、Session renew／revoke、process crash 的明確序列測試。
- **Wire**：`NATIVE_ADAPTER_DISABLED`。任何 Client 參數、opcode、scene ID、回覆行為都要回到 T02/T03/T05/T07/T08/T16 原生研究及 S00 SPEC/GAP，禁止在 P01 猜補。

**開工準則：** Server owner 可先編寫 P01 domain API + mock/fault tests；若要落地交易 schema／宣告 R1 PASS，必須通過 R0 provider/policy/migration 和[ Iteration34 驗收矩陣](S00-20261031-ITERATION-34-ACCEPTANCE.md) 中的關鍵條件。仍不可宣稱原版 KR Client 可連線。

## 5. 後續進度／責任分界

| 工作 | Owner | 解除條件與驗收 |
| --- | --- | --- |
| WEB Admin SQLite/PG/遠端 IP 差異回報 | Server developer + S00 | 依 REQ-0006..0008、ADR-0004/5 分拆已完成本機範圍和剩餘產品需求；不要把 local CI 視為 PostgreSQL/遠端正式驗收 |
| R0 migration allocation | Server DB owner | 讀最新 SQLite/PG schema、集中編號、append-only manifest、檔 SHA/回復策略、兩 provider rollback/restore |
| C05-P01 domain+transaction | Server gameplay maintainer | 分離 mock admission 和 native adapter；真 Server PR/commit + 正反測與 crash/multi-session trace |
| 原版 Client 正向場景/封包 | T02/T03/T05/T07/T08/T16 按現有 RR/Task owner | 新資料才由 T01 與 S00 以有限主張接收；不得以原版 Server 未知阻止仍可做的 Client static 分析 |
| R0/R1 檢查與審核 | S00 | 本輪 Python checker 僅驗機讀工件及 source pins；真 Server/Client 驗收在不同 Repo／獨立授權環境執行 |

**明確未改動：** `research/requests/index.json`、正式 REQ/CLM/GAP/SPEC/TEST、Task owner、ADR 批准、Server repo、原版 Client／二進位；新 [I34-T01～T16](S00-20261031-ITERATION-34-ACCEPTANCE.md) 都是 `PLAN_ONLY/NOT_RUN`。沒有新增「正式 C05 完成」或「PostgreSQL 管理可用」的主張。

**Iteration35 的必要輸入：** Server 真 C05-P01 PR 或經核准的 R0 policy/migration manifest／可複驗 implementation feedback；否則沿上述 blockers 精確補證，不重畫另一份 P01～P19 DAG。
