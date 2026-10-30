# S00 Iteration 27 — C05 執行交接驗收草案（18 項）

**18/18 全部 PLAN_ONLY / NOT_RUN**，本輪沒有執行 Server C05、原版 KR Client 或原版 Server。這些不是正式 `conformance/test-index.json` 的 TEST ID；既有 C03/C04 離線 CI PASS 也不能轉移成新 C05 驗收。來源：[Iteration27 9-pack 矩陣](S00-ITERATION-27-C05-DELIVERY-MATRIX.json)、[完整開發交接](S00-20261031-ITERATION-27-C05-DELIVERY-PLAN.md)。

| Case | Pack | 層級 | 前置／故障刺激 | 完成條件（全為 Server-only 設計候選／源級不確定處） |
| --- | --- | --- | --- | --- |
| I27-T01 | W01 | DOMAIN | 有效 lease + 已選擇同帳號 Role | C03-C transactional existing selected-role 可用於 C05 提案 boundary；未建立原版場景封包 |
| I27-T02 | W01 | NEGATIVE | 過期 SessionLease、Cross-account RoleId、舊 selected-role revision | 必須拒絕而非只靠 legacy LocalCharacterService pre-check；無副作用 |
| I27-T03 | W02 | CONCURRENCY | 兩條連線同角色同 Scene 嘗試 ReserveEncounter | 僅單一 Admission/EncounterId；不同 SessionEpoch 符合 fencing 策略，不二次 spawn |
| I27-T04 | W02 | RECOVERY | 停權、斷線、重登後舊 Admission 重送 | 舊 epoch 不可 commit；durable Role Progress 與內部 lease 分開 |
| I27-T05 | W03 | DOMAIN | 同一 mock fixture seed/config 兩次建立 Actor set | 生成一致 actor list / spawn IDs，不宣稱原版 Scenario14 敵人規則 |
| I27-T06 | W03 | NEGATIVE | Client 嘗試自造 spawn、跨 owner 的 NPC AI、stale movement tick | Server-only authoritative Actor/AI ownership、reject/rollback，實際 Client AI source 未證 |
| I27-T07 | W04 | DOMAIN | 同一角色重送技能和普通攻擊意圖 | 相同 action key 至多一次資源扣除/冷卻，原版技能/傷害公式仍 unknown |
| I27-T08 | W04 | NEGATIVE | 錯角色 Skill、跨 Scene 目標、Client 自選 Hit/Death | 不得直接授權傷害、擊殺或通關；Reject 不改 Encounter revision |
| I27-T09 | W05 | DOMAIN | Mock Objective 未達成但已過固定秒數 | 不得自動成功；只有明確被審查的 mock predicate 能給 ScenarioTerminal |
| I27-T10 | W05 | RECOVERY | Scenario terminal DB commit 成功、通知失敗或兩 worker 併發 | settlementKey/Outbox 去重；S2C0x4C local map 不是 Server terminal authority |
| I27-T11 | W06 | DOMAIN | Scenario14 settled 且 Quest14 未交付，Quest16/15 嘗試前進 | Quest14/16/15 狀態不同；拒絕越過 Quest/turn-in 前置 |
| I27-T12 | W06 | NEGATIVE | Quest16 錯 NPC/跨 Role、或 Quest15 available 當 accepted/completed | 各 Quest revision/owner fail closed，不自動標教學結束 |
| I27-T13 | W07 | CONCURRENCY | 同一 rewardKey 在兩 worker 重送且事件跨 worker | RewardLedger 只能一次 durable effect；同一 outbox event 可安全重送 |
| I27-T14 | W07 | RECOVERY | SQLite transaction crash、PostgreSQL restore 後重新發 reward | 兩 provider 各自 migration/restore 測試，無雙倍獎勵；Reward type2/value50 不猜含義 |
| I27-T15 | W08 | DOMAIN | Quest16 完成、Quest15 available、但 tutorial terminal/exit 尚未核准 | Progress 不提前完成、WorldReadyObserved 仍 false，Scene adapter OFF |
| I27-T16 | W08 | RECOVERY | ban/unban、舊 SessionEpoch 完成 event、relog Resume | 重登保留 Progress/Quest/Reward，過期 lease 不復活、不 double spawn |
| I27-T17 | W09 | NEGATIVE | 測試要求把 KR S2C0x69、0x4C、tutorial resource key 當官方封包發出 | native profile 維持 Unsupported/feature flag OFF；編碼器不作猜測 |
| I27-T18 | W09 | E2E PLAN | 另行授權同 SHA KR Client 且已具方向/Conn/scene/Actor/Quest 完整來源證據 | 記錄原 Client 真正啟動與可操作結果，未授權保持 NOT_RUN，不用 mock/CI 取代 |

## 每包完成提交的最低證據

- 交 `work_pack_id, case_id, server_commit, s00_plan_commit, relevant_original_server_pin, schema_version, provider(SQLite/PostgreSQL), fixture_sha256, test_runtime/environment, expected, actual, pass_fail_blocked, evidence_class, unresolved_native_gate, reviewer, date`。
- 第一類 `DOMAIN_SYNTHETIC`：可先產生真實 Server Unit/DB tests；仍需維護者核准 ADR-0006/0007 的正式產品業務政策。S00 不將計畫案例宣稱已執行。
- 第二類 `ORIGINAL_CLIENT_STATIC_SCOPED`：只在同 KR BIN SHA 的 producer/consumer、路徑和必要 byte/scene/frame/Conn 完整時記錄，並由 T01 按限定主張核對。
- 第三類 `COMPAT_CLIENT_RUNTIME`：須使用者另行授權隔離的原版 Client 真實驗收；第四類 `ORIGINAL_SERVER_TRACE` 要實際有 Server trace/source，任何 mock 都不具有。
- W09 應建立原生 admission review 表，只有完整 source/provenance／適用 Client 版本／場景前置／拒絕分支及具授權實測才可考慮變更 native codec。**拒絕**從編號相鄰的 C2S42→S2C43、C2S40→S2C4C 直接猜 response。
- 工作包回報應發回 Server repo 自己的 PR/CI/SFD 或 S00 既有 FB 機制；不能以新工作包代替正式 RR/REQ/GAP/TEST 台帳。
