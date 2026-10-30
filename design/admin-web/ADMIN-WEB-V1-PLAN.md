# S00 WEB 後台 V1 — 玩家帳號建立、N 天／永久停權及解封（設計草案）

日期：2026-10-31；類型：**ADMINISTRATOR REQUEST + SERVER-ONLY DESIGN，CANDIDATE / NOT_IMPLEMENTED / NON-NORMATIVE**。來源 REQ-0006～0008／[使用者原文](../requirements/requests/2026-10-31-admin-web-account-operations.md)。不代表正式核准、原版 Client 的功能或 Server 程式已具備。

## 1. 範圍、目標與實作現況

**目標：**在指定來源 IP 與配置的管理網址均通過 Server-side 存取檢查時，可直接查詢／建立玩家帳號、停權 N 天／永久與解封；V1 不設管理員登入和角色權限。操作紀錄只能追溯來源 IP/請求，不能聲稱辨認真人操作者；停權對新登入與既有 Session 都有效。

與 [`ttr_server_roy`](https://github.com/we88ec3-prog/ttr_server_roy) 2026-10-31 main `b8efc6b09c0595cea058593addfc779ae09759b4` 核對：

- **已存在但僅限離線 Server:** `src/Tartaros.Account/InMemoryAccountDirectory.cs` 可測試建立帳號／密碼查驗；`Tartaros.Persistence` 的 PostgreSQL C02 migration 001 有 `tartaros_accounts`；`LocalLoginCoordinator` 與 `ISessionLeaseRegistry.RevokeAccountAsync` 有內部 Session 所有權／撤銷介面。**不代表公開的 WEB API 已存在，也不證原 Client 可以成功登入。**
- **尚缺：** `Tartaros.Admin/IAdministrativeAuditSink.cs` 目前僅有 `RecordAsync(actionName)` 介面，沒有 WEB 後台入口/來源 IP 限制、後台 API、完整稽核資料、持久化停權、跨登入 Session 禁止登入機制、操作 UI 或測試。
- 現有 C02 `locked_until` 是**密碼驗證失敗的暫時鎖定**，不是人工停權欄位；**禁止將兩者共用**。
- 本 S00 repo **只設計**；Server Code／DB migration 應由實作庫獨立 PR、測試、正式資料庫部署審查。
- Client KR／TC wire 分立，角色創建 `RR-0010` 與本次**管理員建立玩家帳號**完全不同；本需求不設原 Client C2S/S2C RR。

## 2. V1 存取方式、頁面與操作（使用者已簡化）

**免登入版本：**不設管理員帳密、登入頁、MFA、角色/RBAC、管理 Session；只需配置 `ADMIN_ALLOWED_CLIENT_CIDRS` 與 `ADMIN_BASE_URL`（名稱與 env schema 為候選，具體 IP／URL 尚未提供）。預設空 allowlist = 全部拒絕。管理 URL 是**入口**，不是密碼；不能只靠隱藏路徑保護。

```text
Browser ──> private VPN/LAN / TLS reverse proxy [來源 IP allowlist]
         └─> 管理 Host+port+base-path (Server 驗證 Host/path)
                   └─> Admin API / WEB UI (所有允許 IP 功能相同)
                            └─> Account / Session / Persistence
```

| 頁面 | 最小欄位與動作 | 保留保護 |
| --- | --- | --- |
| 管理入口 | 指定 URL 直接進入帳號列表；**不顯示管理員登入頁** | 僅允許配置的 client IP/CIDR，指定 Host/port/base path |
| 帳號清單/詳情 | 搜尋、分頁、帳號 ID、建立時間、停權狀態、到期、登入失敗鎖定 | IP/Host gate、必要資料、不顯示憑證/hash |
| 新增帳號 | 玩家帳號名稱、初始密碼或安全產生（待決策） | 二次確認、去重、冪等、操作紀錄 |
| 停權 | N 天或永久、原因、開始/到期 UTC、確認 | 版號 CAS、持久化、撤銷 Session |
| 解封 | 結束停權、解除原因、確認 | 不復活舊 Session、不刪除歷史 |
| 稽核查詢 | `IP_ONLY_OPERATOR` + 來源 IP、操作、對象 UUID、原因、時間、結果 | 只能稱為**來源網路辨識**，無法識別真人操作者 |

## 3. 網路邊界與安全限制（ADR-0004，PROPOSED）

1. **來源 IP 必須在 Server 可信邊界比對**。管理端若經反向代理，僅信任明確設定的 trusted proxy；禁止直接相信來訪者自己提供的 `X-Forwarded-For`。反向代理與 backend 要防直接繞過，管理 Host/路徑不匹配立即拒絕。
2. **指定 URL 不是身分驗證**，同 NAT/VPN 來源 IP 的其他使用者也可能取得全部管理功能。只限本機、私有網段或 VPN 上使用；不可視為適合公開 Internet 的正式無登入後台。跨主機使用 TLS。
3. 無管理員 Cookie/角色，但**仍需防 CSRF**：所有異動使用 POST 而非 GET，驗證可信 `Origin`／預期的 Host（必要時 `Referer`）、禁止任意 CORS、拒絕未預期內容型別，前端要求確認且不得允許跨站自動異動。
4. 每次異動必須經來源 IP + URL gate、原因及目標驗證、`idempotency-key` 和 `expectedVersion`；拒絕、不合法/超量、衝突也須可稽核，並避免帳密/雜湊/Session token 暴露。
5. 管理登入與細部權限為**未來可選階段**；本 V1 不應強迫實作者開發。URL/IP 配置不寫入公開 repo 的真實值，不授權調整現有 C00 `/health` 對外 bind。

## 4. 帳號建立的業務契約（REQ-0007）

**資料欄位（提案）：** `account_id: UUID`（Server 產生），`normalized_name`（沿用 C02 暫行規則，後續可配置並版本化），`credential_format/version`（沿用既有 Server-owned KDF、部署前另審），`created_at_utc`、`created_via=IP_ONLY_ADMIN`、`created_source_ip`、`row_version`。V1 不捏造 `created_by_admin_id`。

**成功條件：**請求來源 IP 在 allowlist 且命中管理 Host/base-path，名稱/憑證符合當前 Server 政策；在資料庫事務內插入單一玩家帳號並完整記錄 audit；新帳號預設**沒有遊戲角色、沒有停權**；若 Session、遊戲 Client wire 尚未完成，成功只代表帳號在 Server-owned store 存在。

**拒絕／併發：**名稱標準化後重複（含大小寫混用）回衝突而不新增、非法名稱或不符合政策拒絕、不同允許來源併行創建同名只可成功一次；相同冪等鍵重送回相同結果，**不能產生第二個帳號**。資料庫或稽核寫入失敗不得報成功／產生無稽核的管理修改。

**憑證選擇待核准：**V1 可採由管理員在受限表單設定初始密碼且**僅暫時在記憶體持有**，服務端 hash、不顯示／不保存明文；較佳選項為一次性設定流程，但如果沒有經驗證的 Client 密碼更換介面不能假定遊戲支援首次強迫修改。暫時不要求寄送 Email 或玩家自行註冊。

## 5. 帳號停權／永久停權／解封（REQ-0008、ADR-0005）

### 5.1 獨立的處置資料模型

建議新表／實體（非已實作的 SQL）：

| 欄位 | 用途 |
| --- | --- |
| `sanction_id`, `account_id` | 具不可變 ID 的處置與玩家帳號外鍵 |
| `kind` | `TEMPORARY` / `PERMANENT` |
| `starts_at_utc` | Server 可信時計；不採瀏覽器時間 |
| `expires_at_utc` | TEMPORARY 必填；PERMANENT 必須 NULL |
| `ended_at_utc` / `ended_source_ip` / `end_reason` | 提前解封／自然到期的保存與顯示（自然到期可由時間衍生） |
| `reason` / `created_source_ip` / `created_at_utc` | 操作來源與原因；V1 無管理員身分，不可偽造 created_by 管理員 ID |
| `account_policy_version` | 防止停權、解封、舊 Session 併行覆寫 |
| `correlation_id` / `idempotency_key` | 一次 mutation 的可查追蹤／冪等 |

**狀態判定**（同一 account 同一時間最多一筆 active sanction，DB 約束＋鎖/序列化必須設計）：

```text
ACTIVE ── suspend(N) ──> SUSPENDED_TEMP [now, now + N * 24 hours)
ACTIVE ── suspend(permanent) ──> SUSPENDED_PERMANENT
SUSPENDED_TEMP ── now >= expires_at_utc ──> ACTIVE (按時間衍生)
SUSPENDED_TEMP / PERMANENT ── unsuspend(reason) ──> ACTIVE
```

- **N 天**定義為從**Server 端 UTC 生效時刻起 N×24 小時**（提案，非自然日終止）；`N` 為正整數，有上限與 overflow 檢查（上限數字尚未批准）；畫面按管理頁配置的顯示時區顯示 UTC 起訖。不得使用瀏覽器所在地午夜當有效期限。
- **永久**沒有自動到期，只有通過 IP/URL 存取邊界的解封操作可以終止。
- **到期自然生效**：驗證及 Session 發放每次依可信時間計算，**不依賴排程器一定準時運行**。背景任務可整理歷史，但不可成為停止封禁的唯一依據。
- **重複停權／再次解封**：V1 建議舊封禁仍有效時第二次不同請求以 `409 CONFLICT` 拒絕，改期限/轉永久列未來獨立需求；相同 idempotency key 則回原結果。沒有 active sanction 的解封也回狀態衝突（經審核後可改為 no-op）。
- **停權 vs 密碼錯誤鎖定**：現有 `tartaros_accounts.locked_until` 僅是登入失敗鎖定；管理員解封**不清除**該欄，也不重置失敗次數。
- **歷史保存**：解封不刪掉停權原始事件或理由；保留至獨立核定的 retention 期限。V1 不設硬刪帳號。

### 5.2 一致的驗證／既有連線處置

要達到「真正停權」而不是「資料庫顯示停權」，必須同時覆蓋：

1. **認證前/後檢查**：在核對憑證後、正式簽發 Session lease **之前**以同一 Server-owned account ID 查有效停權，拒絕新 Session；避免「查狀態 → 剛被停權 → 取得新 lease」競態，採一致版本／序列化判斷。
2. **既有 Session 撤銷**：停權提交後，更新 account policy generation 並要求 `ISessionLeaseRegistry.RevokeAccountAsync` 或等效 CAS 撤銷；在各遊戲 action/renew/connection admission 邊界驗證當前 generation，以防舊 Session 持續遊玩。
3. **跨進程/失敗恢復**：PostgreSQL 事務內持久化 sanction＋管理 audit＋outbox 通知（若採），在進程崩潰後重送 revocation；**不能只靠發布一次記憶體 event**。所有 gateway/worker 在敏感操作前做 authoritative gate 或有界、可撤銷快取，確保失效立即被拒絕。DB 不可用時採 fail-closed，不可回退到已知過期或未知禁令狀態而允許遊玩。
4. **明確的完成語意**：停權 API 只有在不可逆持久化成功後才回成功；回應列出 `session_revocation: APPLIED | PENDING_RETRY`（若仍待跨節點通知則不得宣稱已踢下線）。若需求是「立刻強制斷線」，上線前必須選定同步阻斷/ack timeout 策略並通過多節點測試。所有策略在 ADR-0005 正式決議前僅是建議。
5. **解封不自動登入**：清除有效 sanction 不等於解除密碼輸錯鎖定、不恢復已被撤銷的 Session；玩家需重新通過一般認證。

## 6. 建議內部 WEB API 草案（僅設計，未開放）

管理入口例如 `https://<PRIVATE-ADMIN-HOST>:<PORT>/admin/`（佔位格式，**不是實際位址**），API base path `/admin/api/v1`。所有 API 先通過 client-IP allowlist、受控 reverse proxy/可信 forwarded headers、Host/port/base path 比對；不要求管理員 login、session、RBAC header 或 bearer token。跨主機 TLS、Mutation POST 的 Origin/CSRF、冪等與版本檢查仍適用。

| 方法／路徑 | 輸入核心 | 回傳 |
| --- | --- | --- |
| `GET /accounts?query=&cursor=&limit=` | 搜尋、分頁 | 帳號摘要與停權/登入錯誤鎖定兩種獨立狀態 |
| `GET /accounts/{id}` | account UUID | 詳細資料，不含憑證 |
| `POST /accounts` | `name`, `initialCredential`, `idempotencyKey` | `201`＋ID；同名 `409` |
| `POST /accounts/{id}/suspensions` | `kind: TEMPORARY/PERMANENT`, `days: N`（僅 temporary）, `reason`, `expectedVersion` | sanction、UTC 起訖、Session revocation 狀態 |
| `POST /accounts/{id}/unsuspend` | `reason`, `expectedVersion`, `idempotencyKey` | 解封結果；不恢復舊 Session |
| `GET /audit?accountId=&cursor=` | 查詢、分頁 | 來源 IP/原因/動作/時間等去敏稽核 |

拒絕規則：未在白名單、錯誤 Host/path 或不可確認來源 = `403`（在路由前也可由 proxy 拒絕），欄位 `400/422`、不存在 `404`、狀態衝突 `409`、節流 `429`、DB/權威狀態不可用 `503`。本 V1 **沒有**以「未登入」為理由回 `401` 的流程。

## 7. 稽核與持久化

每次 CREATE_ACCOUNT / SUSPEND_TEMP / SUSPEND_PERMANENT / UNSUSPEND 與拒絕事件都記錄 `audit_event_id`, `operator_kind=IP_ONLY_OPERATOR`, `source_client_ip`, `target_account_id`, `action`, `at_utc`, `reason`, `before/after_status`, `correlation_id`, `outcome`, `policy_version`。這**不是**個人身分稽核：同 IP 可能多人共用。不得保存密碼/Hash/Token/敏感內容。

資料庫 mutation 與成功稽核必須同一交易或具可靠 outbox；不可成功但無 audit。符合預期 `row_version`，並行不同請求由 DB unique/active sanction constraint 序列化，同一冪等鍵不可重複建立／封禁。完整稽核保留和備份期限仍須批准。

## 8. Server 實作拆分與分階段交付（未開工）

| 階段 | 模組／交付 | 完成門檻 |
| --- | --- | --- |
| ADM-00 | 配置 IP/CIDR allowlist、WEB Host/URL、private bind/TLS trusted proxy 和 ADR-0004/5 | 未允許 IP、未設定 allowlist、錯誤 Host/path、偽造 forwarding headers 全部拒絕 |
| ADM-01 | `Tartaros.Admin` Admin API、WEB UI、來源 IP/URL gate、操作稽核 | **無登入頁**；所有管理頁/API 由同一 Server-side gate 保護，CSRF/Origin 測試通過 |
| ADM-02 | `Tartaros.Account/Persistence` 建立帳號＋冪等 | 正規化名稱唯一性、成功持久化、來源 IP 稽核 |
| ADM-03 | `Tartaros.Persistence/Session` sanction store + migration + lease fencing | N天/永久/解封、過期/競態/崩潰恢復及重連限制 |
| ADM-04 | WEB 清單、詳情、建立、停權、解封、稽核介面 | 無角色權限流程，操作確認，無敏感資訊暴露 |
| ADM-05 | 私網隔離測試、備份/恢復、部署演練 | 規劃的測試逐項執行、環境/風險核准才部署 |

與現有 C00 /health 和 KR/TC wire 分離。管理後台不使原版 Client 可玩能力自動成熟。

## 9. 待配置／需核對的環境值（尚未提供）

- 要允許的**使用者設備來源 IP/CIDR**（不是 Server IP）、WEB URL 的 scheme/domain/IP/port/base path；例如 `https://<private-host>/admin/` 僅為佔位示意。配置來源不得信任任意 `X-Forwarded-For`。
- Server 實際部署拓樸：本機、同 LAN、VPN、或 reverse proxy；私網以外使用需要重新評估無登入危險。
- 初始玩家密碼如何交付、名稱政策、N 天上限、顯示時區、何時要求 Session 強制斷線；這些是與 V1 **IP/URL 簡化**獨立的決策。
- **已確定不需本階段開發**：管理員帳號登入、管理員角色、MFA、按功能劃分權限。若未來要求公開 Internet，必須再決定正式管理員認證機制。

**驗收情境見** [ADMIN-WEB-V1-ACCEPTANCE.md](ADMIN-WEB-V1-ACCEPTANCE.md)，全部 PLANNED / NOT_RUN。
