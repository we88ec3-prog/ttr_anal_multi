# S00 WEB 後台 V1 驗收矩陣（全部 PLAN_ONLY / NOT_RUN）

**規格來源：** [ADMIN-WEB-V1-PLAN.md](ADMIN-WEB-V1-PLAN.md)、REQ-0006～0008、ADR-0004/5（PROPOSED）。本表為 Server-side 預期行為草案，**不是**正式 `conformance/test-index.json` 的 KR/TC native TEST，也沒有執行紀錄。

| ID | 測試情境 | 最低預期／否決 |
| --- | --- | --- |
| AW-T01 | 未登入訪問任意管理 API | 401，沒有資料或修改 |
| AW-T02 | 只有 `accounts.read` 試圖新增/停權/解封 | 403，DB/Session 不變，拒絕有安全事件 |
| AW-T03 | 過期或撤銷 Admin session／CSRF 不符 | 拒絕；Admin 權限只在 Server 檢查 |
| AW-T04 | 管理員建立合法新玩家帳號 | 唯一 Account ID，DB 持久化，不自動產角色/Session，稽核一筆 |
| AW-T05 | 同名大小寫混合或同時兩管理員建帳 | 至多一筆成功，另一筆為衝突，無部分帳號 |
| AW-T06 | 建立帳號請求相同 idempotency key 重送 | 回相同結果，不雙建、不雙審計處置 |
| AW-T07 | 建立帳號非法名稱/憑證/資料庫故障 | 不新增資料，無明文密碼在結果/日誌 |
| AW-T08 | 密碼錯誤觸發既有 `locked_until` | 與管理停權獨立；解封不會清掉登入鎖定 |
| AW-T09 | 對 ACTIVE 施加 3 天停權 | `expires_at = trusted UTC now + 72h`，起訖可顯示、持久化、稽核 |
| AW-T10 | N = 0、負數、小數、超過配置上限、整數溢位 | 422 / 不修改帳號，沒有不合法永久誤判 |
| AW-T11 | 對 ACTIVE 設永久停權 | `expires_at_utc=NULL`，跨時間重登始終阻擋，只有解封才能恢復 |
| AW-T12 | 精確期限前/時點/後測試 | 時間比較為 `now < expires_at`；到期即有效，不依賴排程器 |
| AW-T13 | 停權期間持正確密碼嘗試重新登入 | 沒有新 Session lease；對外錯誤不透露機密 |
| AW-T14 | 停權時原有 Session 正在遊戲中 | 撤銷 lease，舊 generation 的後續 action／renew 被拒 |
| AW-T15 | 停權提交與同時登入競態 | 無可繞過停權而成功存活的新 lease（含多節點） |
| AW-T16 | 同帳號兩個管理員同時停權/解封 | expectedVersion/CAS 導致明確先後，不能讓過期覆寫新決策 |
| AW-T17 | 已有 active sanction 再提出不同停權 | 建議 409，不能默默改期；同 idempotency key 回原結果 |
| AW-T18 | 合法解封（暫時／永久） | active sanction 結束、保留歷史、可重新登入；不恢復舊 Session |
| AW-T19 | 未停權帳號解封／解封重送 | 不產生虛假操作；狀態衝突或一致重播 |
| AW-T20 | DB 成功但 revocation 通知失敗／服務 crash | 持久策略仍拒絕登入/舊 action，恢復後可靠重試；不虛報已即時踢下線 |
| AW-T21 | audit 寫入失敗或 mutation 中途斷線 | 操作不可報成功卻無稽核；交易與補償策略明確 |
| AW-T22 | 非管理員帳號／管理員 token 跨界混用 | 遊戲身分不能授權管理 API；停權指令不走原 Client opcode |
| AW-T23 | WEB list/detail/audit 分頁、搜尋與角色範圍 | 無過度曝露或未授權枚舉；不出現憑證、hash 或 token |
| AW-T24 | 資料庫不可達或快取過期 | 認證/遊戲入場 fail closed，不把未知停權視為可用 |
| AW-T25 | Postgres migration／backup／restore 對新 sanction & audit | 多個已封禁帳號恢復後仍受限制，歷史未損壞（僅合成帳號） |

**狀態：** 全部 `NOT_RUN`；目前未實作 Admin Web、sanction store 或測試執行。未通過安全審查與隔離環境測試前不對外發布網頁後台。不得混為原版 Client E2E 或 `TEST-*`。
