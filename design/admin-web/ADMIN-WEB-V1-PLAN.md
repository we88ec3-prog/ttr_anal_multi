# S00 WEB 後台 V1 — 玩家帳號建立、N 天／永久停權及解封（設計草案）

日期：2026-10-31；類型：**ADMINISTRATOR REQUEST + SERVER-ONLY DESIGN，CANDIDATE / NOT_IMPLEMENTED / NON-NORMATIVE**。來源 REQ-0006～0008／[使用者原文](../requirements/requests/2026-10-31-admin-web-account-operations.md)。不代表正式核准、原版 Client 的功能或 Server 程式已具備。

## 1. 範圍、目標與實作現況

**目標：**在非公開管理後台，授權管理員可查詢玩家帳號、建立帳號、停權正整數 N 天、永久停權、提前解封，並追查誰、何時、為何操作；停權後對新登入和既有 Session 都有效。

與 [`ttr_server_roy`](https://github.com/we88ec3-prog/ttr_server_roy) 2026-10-31 main `b8efc6b09c0595cea058593addfc779ae09759b4` 核對：

- **已存在但僅限離線 Server:** `src/Tartaros.Account/InMemoryAccountDirectory.cs` 可測試建立帳號／密碼查驗；`Tartaros.Persistence` 的 PostgreSQL C02 migration 001 有 `tartaros_accounts`；`LocalLoginCoordinator` 與 `ISessionLeaseRegistry.RevokeAccountAsync` 有內部 Session 所有權／撤銷介面。**不代表公開的 WEB API 已存在，也不證原 Client 可以成功登入。**
- **尚缺：** `Tartaros.Admin/IAdministrativeAuditSink.cs` 目前僅有 `RecordAsync(actionName)` 介面，沒有管理身分、後台 API、完整稽核資料、持久化停權、跨登入 Session 禁止登入機制、操作 UI 或測試。
- 現有 C02 `locked_until` 是**密碼驗證失敗的暫時鎖定**，不是人工停權欄位；**禁止將兩者共用**。
- 本 S00 repo **只設計**；Server Code／DB migration 應由實作庫獨立 PR、測試、正式資料庫部署審查。
- Client KR／TC wire 分立，角色創建 `RR-0010` 與本次**管理員建立玩家帳號**完全不同；本需求不設原 Client C2S/S2C RR。

## 2. 畫面與操作

| 頁面 | 最小欄位與動作 | 權限／操作防護 |
| --- | --- | --- |
| 管理員登入 | 管理員帳號、憑證、MFA（採用方式待審） | 與玩家帳號獨立身分領域；限許可網段／安全代理，短期 Session |
| 帳號清單 | 完整或遮罩帳號名稱（依角色）、帳號 ID、建立時間、有效停權狀態、停權到期、分頁/搜尋 | `accounts.read`；避免大量列出/枚舉 |
| 新增帳號 | 玩家帳號名稱、一次性初始憑證輸入或安全生成（選一，待批准） | `accounts.create`；表單防重送；成功僅顯示必要資訊 |
| 帳號詳情 | 玩家帳號 ID、目前停權與登入鎖定兩個獨立狀態、最近管理處置 | `accounts.read`；禁止顯示任何密碼／hash／token |
| 停權操作 | 二選一：**N 天** 或 **永久**；顯示生效與到期（UTC 與管理端在地時區），管理原因、最終確認 | `accounts.suspend`；二次確認及併發保護 |
| 解除停權 | 當前處置、停權原因（適當權限可閱）、解除原因、結果確認 | `accounts.unsuspend`；防重送；不可刪除歷史 |
| 稽核查詢 | 操作人、目標帳號 ID、動作、原因、UTC 時間、成功/拒絕、追蹤 ID | `audit.read`，分頁，唯讀 |

為日後手機管理可做響應式布局，但 V1 以桌面管理為主。這是界面資訊架構，不含 Figma/前端程式或已生成畫面。

## 3. 權限與安全邊界（ADR-0004，PROPOSED）

- **權限採 Server 驗證，不靠隱藏按鈕：** `accounts.read`、`accounts.create`、`accounts.suspend`、`accounts.unsuspend`、`audit.read`。建議角色 `SUPER_ADMIN`、`ACCOUNT_OPERATOR`、`AUDITOR` 作配置範例；角色授權清單與自我停權／最後一位管理者保護待正式批准。
- 管理員識別與玩家帳號**隔離**；不允許用遊戲密碼直接呼叫 Admin API。初版僅 private network/VPN + TLS 代理，禁將目前 C00 loopback `/health` 直接改成公開管理入口。
- 生產型管理員登入需安全的憑證策略及 MFA、速率限制、Session idle/absolute expiry、撤銷與稽核；Cookie 使用 `Secure`、`HttpOnly`、合適的 `SameSite`，有狀態操作需 CSRF 防護；禁止 cross-origin 任意呼叫。
- 每個管理 mutation 後端再驗 `actor`、scope/permission、`target`、CSRF、nonce/idempotency key 與預期版號；對存取拒絕與驗證失敗做節流、可稽核但不記錄秘密。
- 使用參數化 SQL/ORM，回應不洩漏 password hash、salt、token、原始憑證；所有操作於受控 TLS 通道，敏感輸入不得入 URL、URL query、log、埋點、Error trace；前端禁將管理登入 token 存 localStorage。
- **管理 API 不經 KR/TC 遊戲封包**；由內部 application service 呼叫 `Account`、`Session`、`Persistence`，避免管理員以虛構 opcode 操作遊戲。

## 4. 帳號建立的業務契約（REQ-0007）

**資料欄位（提案）：** `account_id: UUID`（Server 產生），`normalized_name`（沿用 C02 暫行規則，後續可配置並版本化），`credential_format/version`（沿用既有 Server-owned KDF、部署前另審），`created_at_utc`、`created_by_admin_id`、`row_version`。

**成功條件：**管理員有 `accounts.create`，名稱/憑證符合當前 Server 政策；在資料庫事務內插入單一玩家帳號並完整記錄 audit；新帳號預設**沒有遊戲角色、沒有停權**；若 Session、遊戲 Client wire 尚未完成，成功只代表帳號在 Server-owned store 存在。

**拒絕／併發：**名稱標準化後重複（含大小寫混用）回衝突而不新增、非法名稱或不符合政策拒絕、不同管理員併行創建同名只可成功一次；相同冪等鍵重送回相同結果，**不能產生第二個帳號**。資料庫或稽核寫入失敗不得報成功／產生無稽核的管理修改。

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
| `ended_at_utc` / `ended_by` / `end_reason` | 提前解封／自然到期的保存與顯示（自然到期可由時間衍生，是否產生記錄待決策） |
| `reason` / `created_by` / `created_at_utc` | 具權限限制的稽核責任資訊 |
| `account_policy_version` | 防止停權、解封、舊 Session 併行覆寫 |
| `correlation_id` / `idempotency_key` | 一次 mutation 的可查追蹤／冪等 |

**狀態判定**（同一 account 同一時間最多一筆 active sanction，DB 約束＋鎖/序列化必須設計）：

```text
ACTIVE ── suspend(N) ──> SUSPENDED_TEMP [now, now + N * 24 hours)
ACTIVE ── suspend(permanent) ──> SUSPENDED_PERMANENT
SUSPENDED_TEMP ── now >= expires_at_utc ──> ACTIVE (按時間衍生)
SUSPENDED_TEMP / PERMANENT ── unsuspend(reason) ──> ACTIVE
```

- **N 天**定義為從**Server 端 UTC 生效時刻起 N×24 小時**（提案，非自然日終止）；`N` 為正整數，有上限與 overflow 檢查（上限數字尚未批准）；畫面按管理員指定 IANA 時區顯示 UTC 起訖。不得使用瀏覽器所在地午夜當有效期限。
- **永久**沒有自動到期，只有有權限的解封動作可以終止。
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

## 6. 建議內部 WEB API 草案（版本候選；不是已公開的 endpoint）

Base path `/admin/api/v1`；所有請求限具認證的 Admin session、TLS、CSRF/權限檢查、`X-Request-Id` / `Idempotency-Key`、不可在 URL 夾帶敏感資料。下列路徑與 JSON 欄位只是交付實作者的**非規範提案**。

| 方法／路徑 | 權限 | 輸入核心 | 回傳（語意） |
| --- | --- | --- | --- |
| `GET /accounts?query=&cursor=&limit=` | accounts.read | 已授權的搜尋／分頁 | 帳號摘要，不含憑證或秘密 |
| `GET /accounts/{id}` | accounts.read | account UUID | 帳號與**停權／登入鎖定分欄** |
| `POST /accounts` | accounts.create | `name`, `initialCredential`, `idempotencyKey`（body/header 版本待決） | `201`＋ID；名稱衝突 `409` |
| `POST /accounts/{id}/suspensions` | accounts.suspend | `kind: TEMPORARY/PERMANENT`，TEMPORARY `days: N`，`reason`，`expectedVersion` | 新 sanction，UTC 起訖，Session revocation 狀態 |
| `POST /accounts/{id}/unsuspend` | accounts.unsuspend | `reason`, `expectedVersion`, `idempotencyKey` | `200` 且新狀態為 ACTIVE；不復活舊 Session |
| `GET /audit?accountId=&cursor=` | audit.read | 授權範圍＋分頁 | 稽核事件列表（已去敏） |

一致錯誤代碼：`400/422` 欄位規則、`401` 未登入、`403` 無權限、`404` 不存在或依法隱匿、`409` 重複／版本衝突、`429` 超量、`503` 無法安全確認資料庫/權威狀態。審查前不以這份草案承諾正式 REST 相容格式。

## 7. 稽核、不可否認與儲存策略

每次 `CREATE_ACCOUNT / SUSPEND_TEMP / SUSPEND_PERMANENT / UNSUSPEND`，以及許可拒絕、無效參數、衝突等安全事件，記錄 `audit_event_id`、管理員主體、目標 account UUID（必要時遮罩）、`action`、`at_utc`、`reason`、前後狀態摘要、request correlation/idempotency、結果與 policy version。成功 mutation 的持久化與 audit **必須同一 transaction 或具有明確的可靠提交協議**，不可成功卻沒有稽核；拒絕事件可獨立持久化。資料保留/匯出/存取權限待決議。

對帳號的每次 mutation 要檢查預期 `row_version`（樂觀鎖）與資料庫唯一/active-sanction constraint；同一請求的重試應冪等，不同請求競爭需有確定先後次序。紀錄不可暴露初始密碼、雜湊、Cookie、權杖、未必要的 IP 與個資。

## 8. Server 實作拆分與分階段交付（未開工）

| 階段 | 模組／交付 | 完成門檻 |
| --- | --- | --- |
| ADM-00 | 核定 ADR-0004/5、部署網段、管理員身份/MFA、權限矩陣 | 能在未開公開端口的環境測試拒絕未授權請求 |
| ADM-01 | `Tartaros.Admin` 管理 commands+auditor、獨立 Admin HTTP Host、頁面框架 | 管理 API 只透過 Server application services，審計/權限拒絕測試通過 |
| ADM-02 | `Tartaros.Account/Persistence` 帳號建立、冪等、帳號表唯一性 | 建帳並重登一致、重試不重複、稽核持久化 |
| ADM-03 | `Tartaros.Persistence/Session` sanction policy＋DB migration＋lease fencing | N天/永久/解除/期滿/多節點/崩潰恢復測試通過 |
| ADM-04 | 前端清單、詳情、建立、停權、解封、稽核頁 | 最小權限、二次確認、錯誤明確、無敏感資訊洩漏 |
| ADM-05 | 經審核的測試環境安全/備份/部署檢查 | 才評估部署，**不是**自動對外開放 |

不與 C00 `/health` 直接共享外部網路；規劃採同一模組化單體中的**分離 Admin Host/路由與存取政策**，而非必須另起微服務。若未來要整合原 KR Client，需繼續受 S00 原本的 AUTH/NET REQ/GAP/RR 限制，**不因 Admin V1 達標而聲稱遊戲 Client 登入完成**。

## 9. 未決事項與維護者審核（不阻礙形成候選規格）

- 管理員登入是否接企業 IdP／本地 MFA；只有內網或需公開 Internet？（建議先 VPN/private）
- 帳號名稱規則是否沿用目前 C02 的暫行 ASCII 3–32；初始化密碼如何安全交付，以及要不要另開帳號重設功能？
- N 天有效範圍與時長定義（建議 N×24h，UTC）；管理介面顯示之預設時區；改期與重複停權是否允許？
- 停權是否需要在 API 成功回傳前確認跨節點斷線，及不可用時的處置；audit retention/隱私政策、權限分層/需不需要雙人覆核？
- DB migration/備份/回滾策略需另行安全審核。以上在 `ADR-0004/5` **PROPOSED** 階段不能當已批准生產設定。

**驗收情境見** [ADMIN-WEB-V1-ACCEPTANCE.md](ADMIN-WEB-V1-ACCEPTANCE.md)，全部 `PLANNED / NOT_RUN`，不登錄為 Client conformance `TEST-*`。
