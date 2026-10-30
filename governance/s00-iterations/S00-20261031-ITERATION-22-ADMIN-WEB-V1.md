# S00 Iteration 22 — WEB 玩家帳號管理後台的正式需求登記與分段交付

日期：2026-10-31（Asia/Taipei）。S00 原始 main SHA `2b5e6e25a6e7c8ca99b5c5c60dbcc2b355e9cc05`。交叉核對實作庫 `ttr_server_roy` 2026-10-31 main `b8efc6b09c0595cea058593addfc779ae09759b4`，但**本次未修改該實作庫**。

## 使用者需求（第三來源的真實首次登記）

由使用者本次明確要求「WEB端後台，第一個需求為新增玩家帳號／停權 N 天／永久／解封」；依既定三來源中的 **`PLAYER_ADMIN_REQUEST`** 登錄，不新增來源類別，不冒充 Client 本地或 Server wire 研究。

原始去敏化來源：[request record](../../design/requirements/requests/2026-10-31-admin-web-account-operations.md)。正式需求索引為 `design/requirements/index.json`；將不同可驗收的成果拆分為：

| 正式 ID | 功能 | 類別 | 狀態 | 證據來源 |
| --- | --- | --- | --- | --- |
| **REQ-0006** | V1 來源 IP＋WEB URL 入口與操作稽核 | OPERATIONS | CANDIDATE | USER ADMINISTRATOR REQUEST，安全基礎設計為衍生需求 |
| **REQ-0007** | WEB 新增玩家帳號 | PRODUCT_FEATURE | CANDIDATE | USER ADMINISTRATOR REQUEST |
| **REQ-0008** | WEB 停權 N 天、永久停權、解封 | OPERATIONS | CANDIDATE | USER ADMINISTRATOR REQUEST |

本輪**沒有維護者正式核准紀錄**，不得寫成 APPROVED。其驗收條件是**Server 自訂產品目標**，不是原版 Tartaros KR/TC 封包功能。原有 REQ-0001～0005 (CODE_ANALYSIS) 不變，不建立新 RR、CLM 或原生 Client `TEST-*`。

## 主要設計與實際程式缺口

- [WEB 後台 V1 完整設計](../../design/admin-web/ADMIN-WEB-V1-PLAN.md) 定義 UI 頁面、來源 IP/Host gate、API 候選、輸入/回應、帳號建立、停權狀態機、UTC 到期、稽核、冪等、併發、Session 立即阻止與跨進程故障恢復。
- [30 項候選測試](../../design/admin-web/ADMIN-WEB-V1-ACCEPTANCE.md) 皆為 **PLANNED / NOT_RUN**；涵蓋安全、不同停權類型、邊界、Session lease、故障、資料備份。它不是已通過的測試。
- 新的 [ADR-0004](../../design/decisions/ADR-0004-admin-web-security-boundary.md) 是「Admin WEB V1 來源 IP 白名單與固定 URL、免登入、稽核及 WEB 安全邊界」；[ADR-0005](../../design/decisions/ADR-0005-account-sanctions.md) 是「停權期間／永久／解封、登入拒絕、舊 Session fencing」；**全部 PROPOSED / NON-NORMATIVE**。
- `ttr_server_roy` C02 已實作離線 `AccountDirectory`、PostgreSQL migration 001、`LocalLoginCoordinator`、`ISessionLeaseRegistry.RevokeAccountAsync`，有機會重用；但既有 `locked_until` 是「失敗登入保護」，**不能偷當 GM 停權**。Admin 只有稽核 interface，未有 WEB UI/API、Sanction table、admin identity、audit transaction。
- 管理員帳號建立玩家帳號是**後端內部管理動作**，與 T03 `RR-0010` 的「原版 Client 創角」不同。不得因此修改 `SPEC-AUTH`、`SPEC-CHAR` 的原生封包判定或聲稱遊戲 Client 登入成功。

## ADM 分期（獨立於 B-NET/B-CHAR/Client E2E roadmap）

| 候選階段 | 交付項目 | 必要驗收關卡 |
| --- | --- | --- |
| ADM-00 | ADR-0004/5、來源 IP/CIDR、WEB URL/Host、私網部署/稽核決策 | 維護者安全審核與授權，非 CI 自動批准 |
| ADM-01 | 後台 Admin API/授權 Middleware、帳號列表/詳情、管理頁面 | 未授權 401/403、不暴露秘密、完整拒絕稽核 |
| ADM-02 | 管理員建立玩家帳號，接既有 C02 Account/Persistence | 持久唯一、冪等、重試安全，成功含稽核 |
| ADM-03 | 經核准 DB migration 的 temp/permanent sanction/unsuspend | 正確 UTC N×24 小時、期限、已鎖定/錯誤/衝突分離 |
| ADM-04 | Session admission/action fencing、revocation/outbox、多節點/失敗恢復 | 已封禁帳號不能重新拿 lease，舊 Session 不能持續操作 |
| ADM-05 | WEB 操作 UI/整合/部署演練 | 30 項計畫測試正式執行報告、安全/備份/rollback gate，才能準備實際部署 |

次序可由 Server 工程實作拆分 PR，但不在 S00 擅自建立 C milestone 或修改 Server repo。此 ADM overlay 是產品管理規劃，不是現有 `governance/s00-roadmap.json` 的新 B-* 里程碑，也不取代唯一 REQ 台帳。

## 這次禁止聲稱的完成事項

- 沒有實作 WEB 頁面、API、PostgreSQL migration、帳號停權、管理員登入或測試執行。
- 沒有對外開放服務、原 Client 執行/抓包、原版 Server 協定核准。
- 沒有將 `REQ-0006..0008` 由 CANDIDATE 升格 APPROVED，沒有將 ADR-0004/5 升成 normative。
- 沒有私自將 C02 登入失敗的 `locked_until` 改作管理封禁，沒有假造停權 opcode。

## 下一輪明確交付

S00 下一步應審核 ADR 選項（N 天如何計、IP allowlist/私網代理、註冊初始密碼、停權立即性與容錯/稽核）、取得批准後再向 `ttr_server_roy` 交接可執行契約；同時保持 E05/E06 原 Client 創角研究與 Admin WEB 帳號操作分流。可先做僅限合成資料的 Server 單元測試，不得以其通過宣稱 original Client E2E。

## 2026-10-31 同一需求的 V1 更正：免登入，僅來源 IP＋指定網址

使用者補充 **「目前先不管權限，指定的IP與URL就能管理」**。已在唯一 `REQ-0006` 追加 `PLAYER_ADMIN_REQUEST` discovery，並同步更新 REQ-0006～0008、ADR-0004 和 WEB Admin V1 文件／30 項測試。新版方案不設管理員登入、RBAC、MFA 或管理員 Session。使用者授權的是**簡化 V1 需求**，不是公開無驗證管理介面的部署許可。來源 IP 必須由可信代理/Backend 判斷，網址只負責 Host/路由匹配，預設拒絕、保留同源 POST/CSRF/稽核及私網隔離。沒有指定真實 IP、網域或埠，本輪不填假值；Admin V1 仍為設計，尚未改 Server 程式。
