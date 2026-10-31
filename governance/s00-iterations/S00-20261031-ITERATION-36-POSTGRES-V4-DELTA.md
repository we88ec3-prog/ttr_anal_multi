# S00 Iteration 36 — PostgreSQL v4 真實 Server 增量、C05 migration 配號更正與收件驗證器修復

**日期：2026-10-31。範圍：S00 Client/Server 規格整合；不修改獨立 Server 實作、原版 Client 或正式 RR/REQ/CLM/SPEC/GAP/TEST。** 完整結論以 [機讀差異](S00-ITERATION-36-POSTGRES-V4-DELTA.json) 和本次遠端 Git blob SHA 為界；CI 驗證的是本設計庫資料一致性，不是原版遊戲可玩。

## 一、為何 Iteration36 必須修正既有計畫

Iteration35 當時觀察的獨立 Server `3e0b7e3a8666f363f747dbf68c2fd462a8777b09` 沒有 PostgreSQL 管理 v4，因此 `governance/check_s00_iteration35.py` 把未來 PostgreSQL C05 migration 的 `base_version` **硬編為 3**。現在重新核對 Server `68186e8c63187c87f5957d3260574aaad04307d2`：GitHub compare `ahead=32, behind=0, files=28`；已新增 `db/migrations/004_web_admin.sql`（blob `3f32910fd005be4f4f09fb70cd4e068fa9cb5bf7`）。**PostgreSQL version 4 被 WEB-ADMIN-PG-001 使用**，是實際 source allocation，不能再將 `004` 當 C05 的候選號。**這不代表使用者部署的真實 PostgreSQL DB 已套用 v4；本輪沒有連線讀取其資料庫。**

新 Server 程式還有 [PostgresAdminMigrator](https://github.com/we88ec3-prog/ttr_server_roy/blob/68186e8c63187c87f5957d3260574aaad04307d2/src/Tartaros.Persistence/PostgresAdminMigrator.cs) `ApplyVersion4Async`（事先經 v3 及 advisory lock，寫入後 Verify）與 `VerifyVersion4Async`（後台啟動時唯讀驗證，不能擅自 migrate），[SchemaVerifier](https://github.com/we88ec3-prog/ttr_server_roy/blob/68186e8c63187c87f5957d3260574aaad04307d2/src/Tartaros.Persistence/PostgresAdminSchemaVerifier.cs) 要求版本 `[1,2,3,4]` 及欄位/constraint。這是**已存在的 Server code/離線 CI**，不是 C05 Schema allocator 已建、C05-P01 已交付或所有正式環境可用。

## 二、可複核的 source-scoped 增量與驗收範圍

| Server 來源（該 HEAD Git blob） | 正向確認 | 不可宣稱 |
| --- | --- | --- |
| `004_web_admin.sql` `3f32910f` | 帳號 `ban_until`/`ban_permanent`、moderation audit、version 4 marker | C05 Encounter schema 或使用者資料庫已實際升版 |
| `PostgresAccountAdministration.cs` `e4cb6882` | account `FOR UPDATE`→更新 ban→刪除 leases→audit→同交易 commit | C05 reservation 已原子保護、正式遠端管理安全 |
| `PostgresSessionRegistry.cs` `721441fe` | Claim account-first lock、ban gate；IsCurrent/Renew 含停權排除 | 各 provider 任意跨程序的 production fairness/SLA |
| `PostgresCharacterActions.cs` `19e4853f` | `LockCurrentAsync` 帳號 first/ban `FOR UPDATE`→session `FOR UPDATE`；C03 角色操作同交易授權 | P01 EncounterAdmission 已存在 |
| `PostgresWebAdminTests.cs` `8a08be0b` | 隔離 schema v4 升版、停權、舊 lease、角色建立遭拒、Claim/Suspend race、expired ban、負向 schema drift | 原版 Client E2E 或 C05 domain 已通過 |
| `WEB-ADMIN-POSTGRES.md` `290d81e6` | `--postgres` WEB 本機 127.0.0.1、維運指令、schema verification | 遠端 IP/URL 運營管理、PG 網頁備份、正式 HTTPS/RBAC |

CI（四個 run `41185325497`、`41185325522`、`41185325525`、`41185325530`）皆為同一 Server HEAD 的 SUCCESS；包含 C02/C03 PostgreSQL DB 專屬測試，但沒有自動代替人工逐一確認所有 race、C05 或正式部署。具體 source/full blob 見 JSON `server_delta.sources`。

**政策分類變動（只在 Iteration36 規劃層）：** `REQ-0007/0008` 的 PostgreSQL 本機管理範圍從 UNKNOWN 變成 **source-backed / offline-tested**；`REQ-0006` 的自訂 IP/CIDR + URL 仍未做到（本機 loopback only）。`ADR-0004/0005` 仍 PROPOSED、帳號權限/HTTPS/操作者稽核、PG 備份仍待產品/部署決策。不可藉此自行修改正式需求 CANDIDATE 或核准 ADR。

## 三、C05 R0/P01 新的前提：Provider-aware 版本而非舊 v3/004 假設

| 內容 | 先前 S00 快照 | 這次已核對（Server code） | 後續交付 |
| --- | --- | --- | --- |
| SQLite local schema | v2 | 仍只核對 v2 | C05 新 migration **UNALLOCATED**；不能預先佔用 v3 |
| PostgreSQL schema/code | 001～003 | **004 已分配給 WEB Admin** | 新 C05 schema 必須在 v4 之後，由 DB owner 統一配號；**v5 是下限候選，不是已核准的配號** |
| PG ban/session/角色保護 | 未證跨 provider | 已存在 PG v4 source + 離線實體 PG CI | C05 Admission 仍須於**新增寫入交易**內使用同樣 account→session lock，不能單靠前置 `IsCurrentAsync` |
| P01 EncounterReservation | 尚未實作 | 仍無本輪 source/CI 可證 | P01 SQLite/PG receipt 均 `NO_RECEIPT`；同交易 role ownership/ban/lease/fingerprint/CAS/重試/崩潰證據仍缺 |
| 原版 KR Client native adapter | OFF | OFF | 仍要同版 Client producer/consumer/frame/場景來源、獨立授權測試 |

**防止競態回歸的 P01 交接：** PostgreSQL 的 account-first→lease-row 鎖順序與 moderation 相同；新 Encounter admission 應沿用相同順序，不能復用「舊 C03 先 session 再 account」的設計文字；並需測試 `Suspend` 與 `Select/Claim/Renew/Reserve` 同時進行、重連舊 epoch、改角色、重送不同 fingerprint、斷電後 reservation 不重複。SQLite 與 PostgreSQL 應各自驗，**不從 PostgreSQL v4 的成功推斷 SQLite C05 實作已存在**。

## 四、對 Iteration35 收件器的實際更正

修正 `governance/check_s00_iteration35.py` 的 **未來 candidate`R0-POSTGRES-MIGRATION`** 驗證基準為 PostgreSQL v4；調整相應合成測試，**拒絕**用 version4 當 C05 新 migration、拒絕錯誤舊 `base_version=3` 交件。這只處理「從目前 PostgreSQL v4 之後提交 C05 migration」的候選，不回頭改動 Iteration35 的歷史 state JSON（當時的 `postgres_current_version=3` 是真實的舊 HEAD 快照）。歷史舊分支對照需仍以自己的 Git commit/version 註明；不能把 v4 source 存在等同真 DB 版號。

新增 `governance/check_s00_iteration36.py --check` 在 CI 驗 `Iteration35` 原始 blob 未變、本輪 Server 9 個 source SHA、資料庫 004 使用者身分、未配號與未核准限制、12 個 `NOT_RUN`；僅是 **S00 source identity/資料模型的本地完整性**，不會 live 調閱外部 Server 或執行 .NET/原版 Client。

**如正式要遷移**：Server owner 應先讀當時真正 DB schema/version（可能舊版尚未 v4），備份/還原演練、核對 `004` 實際套用，再決定 C05 唯一 migration manifest/數字、隔離 DB 測試與回滾。禁止用此計畫來直接修改任何玩家 DB。

## 五、並行進入 main 的 T01/T16-134 新來源（本輪不搶研究 owner）

本次 S00 基準 `5897c5058a7386686efaeb6173c8ac11bd83c78b` 已包含 [T01 的 T16-134 合併](../../research/handoffs/t01-20261031-t16-branch-integration/README.md)：`SRC-0590 REGISTERED`、Git blob `991fa3fbbb89622e264eaceb138725d597629e28`，並有六段**限定**原始 BIN/指令交叉驗證；不是整份報告 T01 FULL-PASS、原版 Quest15 C2S/S2C pairing 已閉合或原版 Client runtime 確認。Quest15→Scene3 的正向因果仍有待研究，不用它解鎖 C05 R6 或提升 SPEC-SCENE。

## 六、12 個下一輪驗收情境（均 PLAN_ONLY / NOT_RUN）

| ID | 下游需要具體取得的驗收 |
| --- | --- |
| I36-T01 | 比對 Server `3e0b→68186` 32 commits/28 files 和固定 blob |
| I36-T02 | PG v4 真正部署前後的 schema/rollback/restore digest |
| I36-T03 | C05 專屬 PG migration 禁用 004、同 provider 唯一配號 |
| I36-T04 | C05 SQLite 新版單獨配號，不誤用 PG 版號 |
| I36-T05 | PG account→session 鎖序和 `ban`/claim race |
| I36-T06 | CharacterCreate/Select/Roster 的 ban/lease guard |
| I36-T07 | v3→v4 schema verifier drift/unknown version |
| I36-T08 | WEB admin SQLite/PG 本機隔離及 Host/CSRF |
| I36-T09 | C05-P01 同交易角色/Session/停權/Encounter 資料持久化 |
| I36-T10 | P01 同 AdmissionId replay/new fingerprint/stale epoch/crash |
| I36-T11 | REQ-0006 遠端 IP/URL 與 production permission gate |
| I36-T12 | T16-134/SRC-0590 source-only 不當作 Quest15/Client Native PASS |

本輪將 source-backed **研究文件／離線檢查**上 Git；以上 I36 真 Server/原版 Client/運行測試沒有執行，不新增正式 TEST，也不改他人 Task 的研究或 Session/Quest 規格。

**接續建議**：若 Server 的 C05-P01 / R0 manifest 真正提交，先用修正後的 Iteration35 receipt checker 分 provider 預檢，再人工核對來源與 DB/schema/CI；如沒有新的實作交件，後續請**優先推進 Server 的 P01 真正開發與 policy 決策**，不是再次複製同類收件規劃。
