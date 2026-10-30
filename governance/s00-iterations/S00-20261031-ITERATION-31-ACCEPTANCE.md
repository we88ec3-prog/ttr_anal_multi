# S00 Iteration 31 — Quest14／16／15、唯一 RewardLedger 驗收草案（24 項）

**24/24 全部 PLAN_ONLY / NOT_RUN**。本次並沒有執行獨立 Server 的 C05、原版 KR Client、原版 Server，亦未更改正式 `conformance/test-index.json` TEST。下列只是後續 Server 工程/DB 可實作的 mock/domain 驗收規格，不能據此宣稱原版 Client 任務可玩。

來源：[Iteration31 施工規劃](S00-20261031-ITERATION-31-QUEST-REWARD-PLAN.md)、[S31-01～04 機讀契約](S00-ITERATION-31-QUEST-REWARD-CONTRACT.json)。

| Case | 工作包 | 類型 | 操作／前置 | 預期 Server-only MOCK 結果 |
| --- | --- | --- | --- | --- |
| I31-T01 | S31-01 | SOURCE | 已驗證 Scenario14 SUCCEEDED 與同 Role settlement | 只提供候選 Quest14 eligibility，不直接改 TURNED_IN 或 Quest16 |
| I31-T02 | S31-01 | NEGATIVE | 只收到 Client CTutorial map[14] / Lua flag，無 Server terminal | Quest14 不可完成，沒有任何 reward |
| I31-T03 | S31-01 | AUTH | Mock NPC10027、正確 Role、已達 Objective且當前 Lease | 允許單次 Quest14 turn-in CAS，保留審查記錄 |
| I31-T04 | S31-01 | REPLAY | 同 RequestId、相同 payload 並行交付兩次 | QuestRevision 只前進一次，合法重送可讀原結果 |
| I31-T05 | S31-01 | NEGATIVE | 跨 Role、錯 NPC、舊 Session／停權後交付 | 拒絕且不改 Quest/Reward/Outbox |
| I31-T06 | S31-01 | CONFLICT | 同 RequestId 但轉換 payload、Quest revision 不符 | Conflict，不重用先前成功回覆 |
| I31-T07 | S31-02 | PREREQ | Quest14 有 eligibility 但尚未 TURNED_IN | Quest16 維持 LOCKED；Demand14 靜態資源不越權 |
| I31-T08 | S31-02 | DOMAIN | Quest14 合法 TURNED_IN 與 Quest16 Mock config | Quest16 只變 AVAILABLE，不能自動 ACCEPTED |
| I31-T09 | S31-02 | AUTH | 正確 NPC mock context、Scene/Role 所有權與 revision | Quest16 ACCEPTED 恰一次 |
| I31-T10 | S31-02 | NEGATIVE | Client TalkBox 直接報完成／跳過 objective proof | 不得完成 Quest16 或發獎 |
| I31-T11 | S31-02 | RACE | 同 Role 兩個登入/Session epoch 競爭接取／交付 | 唯一有效 epoch 勝出，舊 epoch 無副作用 |
| I31-T12 | S31-02 | RESTART | Quest16 ACCEPTED 或 OBJECTIVE_READY 後中斷/重登 | 恢復同一狀態與 revision，不能倒退/跳過 |
| I31-T13 | S31-03 | QUARANTINE | Quest16 原生 Reward type=2 value=50，未有核准 mapping | 返回 REWARD_POLICY_UNRESOLVED，不發金幣/EXP/點數 |
| I31-T14 | S31-03 | MOCK_POLICY | 經維護者核准的純 mock Token definition 與 TurnIn | 單次 ledger+credit+Outbox 同交易，mock tag 不進 native wire |
| I31-T15 | S31-03 | CONCURRENCY | 同/不同 RequestId 的兩 worker 重播相同 TurnIn | 唯一 immutable grant，無雙倍數值 |
| I31-T16 | S31-03 | FAULT | DB commit 後斷電/通知前；或送通知後 ACK 前 | 恢復原 grant；Outbox 可重試、consumer 去重，無再入帳 |
| I31-T17 | S31-03 | NEGATIVE | 竄改 reward type/policyDigest、跨角色重送、停權後請款 | 拒絕且保留安全審計，不交出已記錄成功 |
| I31-T18 | S31-03 | BOUND | Mock credit overflow/負數/額度超限、非法 definition | 同交易全部 rollback，狀態不標 PAID |
| I31-T19 | S31-04 | PREREQ | Quest16 僅完成 objective，尚未正式 TurnIn／Reward gate | Quest15 不自動 AVAILABLE |
| I31-T20 | S31-04 | DOMAIN | Quest16 達合法 TurnIn／approved policy 前置 | Quest15 AVAILABLE 而非 ACCEPTED/COMPLETED |
| I31-T21 | S31-04 | NEGATIVE | Quest15 可接且 Lua town field19 可見 | 不等於已離開教學、WorldReady 或 TutorialCompleted |
| I31-T22 | S31-04 | RECOVERY | Quest14/16 交付與獎勵後新 SessionLease 重登 | 正確載入 per-Role Quest/Reward/Quest15 availability，不重發 |
| I31-T23 | S31-04 | SECURITY | 停權、解封、舊場景或舊 Session 操作 Quest15 | 舊 session 不復活、不自行接 Quest15 或離場 |
| I31-T24 | S31-04 | E2E_PLAN | 尚無正向同版本原版 Client Quest state/scene 驗收 | Native adapter OFF，原 Client 測試仍 NOT_RUN，不能由 mock PASS 代替 |

## 驗證順序與證據種類

- C05-P12：I31-T01～T06，實際測 **Quest14 與 ScenarioTerminal 分離**及 NPC/Role/Session revision。
- C05-P13：I31-T07～T12，測 Quest16 Demand14 的**Mock 前置規則**、AVAILABLE/ACCEPTED/COMPLETED/TURNED_IN 分離、雙連線與斷線。
- C05-P14：I31-T13～T18，先驗 **Reward type2/value50** 未映射必拒發，再驗核准純 mock reward unique key、DB transaction、Overflow、Outbox 和崩潰復原。
- C05-P15：I31-T19～T24，Quest15 **AVAILABLE ≠ ACCEPTED ≠ WorldReady**、重登/停權/獎勵一致性及 native no-go。
- 必備的真實下游測試紀錄：`s00_commit`、`server_commit`、`test_id`、`provider`、`schema_version`、`fixture_digest`、`quest14/16/15_revision`、`scenario_settlement_id`、`role_id`、`lease_revision`、`request_id`、`reward_definition_digest`、`ledger_key`、`outbox_id`、`expected`、`observed`、`PASS/FAIL/BLOCKED`、`evidence_class`、`native_gap`。
- SQLite local 與 PostgreSQL 分開驗 migration、併發鎖序、restore/reopen；**先由獨立 Server owner 分配 C05 全模組唯一 migration 版本序列**。本輪無已套用新 schema。
- `DOMAIN_SYNTHETIC` 僅能在真實測試成功後記錄；`NATIVE_STATIC_SCOPED` 需要同 KR BIN 的 opcode/frame/direction/scene/Conn/Quest status producer+consumer 正負來源；`COMPAT_CLIENT_RUNTIME` 需使用者另行授權；`ORIGINAL_SERVER_TRACE` 需要真的原服 trace。此處各種類均未執行，不能「假想 PASS」。
