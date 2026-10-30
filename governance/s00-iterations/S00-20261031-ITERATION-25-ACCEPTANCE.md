# S00 Iteration 25 — 教學首次入場與重登／進度恢復驗收計畫

**16/16 全部 PLAN_ONLY / NOT_RUN。** I25-Txx 不是正式 conformance/test-index.json 的 TEST、不是 T01 原生 FULL-PASS、不是原版 KR Client 可玩驗收。本階段未修改獨立 Server、未運行原版 Client。詳 [Iteration25 全文](S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md) 和 [ADR-0006（PROPOSED）](../../design/decisions/ADR-0006-tutorial-progress-and-session-fencing.md)。

| Case | 類型 | 初始狀態／事件 | 規劃預期（新 Server 自訂，不冒充官方規則） |
| --- | --- | --- | --- |
| I25-T01 | DOMAIN | 0 role 帳號首次登入 | 不建立虛構 playable role／TutorialProgress；角色畫面與 E05/E06 保留不同 gate |
| I25-T02 | DOMAIN | 1 role、NOT_STARTED、有效 ownership/lease | RouteDecision 可提出 FIRST_TUTORIAL；只有有效 Server 事件才能改 IN_PROGRESS，未知 Client scene 不強制發包 |
| I25-T03 | DOMAIN | 1 role、IN_PROGRESS、重登 | 讀已存 checkpoint 並返回 RESUME_ROUTE；不自動 COMPLETED、也不重播獎勵 |
| I25-T04 | DOMAIN | 1 role、COMPLETED、重登 | 提出 NORMAL_WORLD_ROUTE，保留角色及 rewards；不是原版 Client normal world 已進場 |
| I25-T05 | NEGATIVE | Account A 選 Account B RoleId | Server ownership fail-closed，無 admission/scene/教學 state 改動 |
| I25-T06 | CONCURRENCY | 同角色兩個 SessionEpoch 同時 Reserve | 僅最新有效 lease 可提交；另一個 fenced，舊 Client sender 無權寫 Progress |
| I25-T07 | NEGATIVE | Client local scene+0xCC pending，但沒有 C2S42 到達 | Server 不創造 Admission，不把本地 UI pending 當 TCP send/ACK |
| I25-T08 | DOMAIN | 已 reserve 但 scene adapter feature flag OFF | progress 不誤判 ClientReady；此 case 只測 domain，Client 原版進場仍 BLOCKED |
| I25-T09 | DOMAIN | BeginTutorial 重播、並發版本 CAS fail | 同一請求只進行一次合法 NOT_STARTED→IN_PROGRESS，revision 單調且無雙重 checkpoint |
| I25-T10 | NEGATIVE | old SessionEpoch 重送 checkpoint/scenario clear | 拒絕 stale event；不變更 Quest/Progress/Reward，重登後新 lease 不被覆蓋 |
| I25-T11 | RECOVERY | DB commit 成功、outbox 傳輸失敗／Server crash | 重新送出必要通知但不再次改 Progress／grant reward，outbox 可恢復 |
| I25-T12 | NEGATIVE | 收到 S2C0x4C 的本地 Scenario14 completion 觀測 | 不等同直接把 Quest14/16、TutorialProgress COMPLETED 或 Quest15 COMPLETED |
| I25-T13 | DOMAIN | Quest16 真正 Server-authorized 完成且重覆提交 reward key | progress + reward ledger 使用唯一 key/同一交易；不能雙重給予獎勵；Quest15 available 單獨判斷 |
| I25-T14 | RECOVERY | 帳號在 IN_PROGRESS 被停權、斷線後解封 | 撤銷 Session/Admission、保留 durable checkpoint；新 SessionEpoch 恢復，不復活過期 lease |
| I25-T15 | NEGATIVE | 已選角後收到候選 S2C0x69 subtype7，或 C2S43，或資源索引 (1001,1) | 不以任何單一 Client handler/資源 key 宣稱世界／教程可操作；未知 wire/scene adapter fail-closed |
| I25-T16 | E2E PLAN | 明確授權隔離 KR Client，從新帳號至創角/選角/教學起始/完成/離場/重登 | 需實錄 exact Client SHA/Conn/frame/scene/resource/UI/quest/角色資料；不得因 mock 測試成功而宣稱完成，未授權不得執行 |

### 交付紀錄格式

每次正式執行後另存：case_id、S00 plan commit、server_commit、build SHA、environment、input hash、expected、observed、PASS/FAIL/BLOCKED、evidence_type（DOMAIN_SYNTHETIC／STATIC_NATIVE_BIN／CLIENT_RUNTIME_COMPAT／ORIGINAL_SERVER_CAPTURE）、scope、assumptions、owner、blocker、next_step。此次所有 expected 都是**提案**，不是原版 Server 事實。

開發建議順序：先 I25-T01～T06 data/ownership、T07～T11 lease/交易，後 T12～T14 Quest/停權恢復；T15 僅 source boundary，T16 在獲另行授權與補齊 RR 之後才測。任何 PASS 不會自動修改正式 RR/GAP/REQ/SPEC/CLM。
