# S00 Iteration 32 — 教學完成、離開場景、世界就緒與重登驗收草案

**24/24 全為 PLAN_ONLY / NOT_RUN。** 這些是給日後 `ttr_server_roy` C05 mock-domain 實作的工程驗收設計，**沒有實際執行任何 .NET/DB 新玩法測試或原版 KR Client**，也沒有建立正式 `conformance/test-index.json` TEST。

相關：[完整設計](S00-20261031-ITERATION-32-TUTORIAL-EXIT-RELOG-PLAN.md)、[S32-01～04 機讀契約](S00-ITERATION-32-TUTORIAL-EXIT-RELOG-CONTRACT.json)、[Iteration31 Quest/Reward 規劃](S00-20261031-ITERATION-31-QUEST-REWARD-PLAN.md)。

| Case | 工作包 | 類型 | 刺激／前置 | Mock Domain 預期（非原版 KR 客戶端證據） |
| --- | --- | --- | --- | --- |
| I32-T01 | S32-01 | DOMAIN | 合法 Scenario14 durable terminal + Quest14/16 turn-in + approved reward policy | 只判可完成教學候選；進度按版本記錄，不自動讓世界就緒 |
| I32-T02 | S32-01 | NEGATIVE | 只有 Quest15 AVAILABLE 或 Client map[14]=1 / Lua 回呼 | 不得直接完成 TutorialProgress |
| I32-T03 | S32-01 | POLICY | Quest 已完成但原完成與出場先後政策尚未核准 | 回 POLICY_PENDING，不得自造原 Client terminal flag |
| I32-T04 | S32-01 | SECURITY | 角色跨帳、沒有 selected role、Session 已換代或停權 | 同交易 fail closed，無 checkpoint side effect |
| I32-T05 | S32-01 | CONCURRENCY | 同一 checkpoint event 兩 worker 重送、相同 payload | 唯一 durable revision/result，不修改獎勵 |
| I32-T06 | S32-01 | CONFLICT | 同 RequestId 不同政策 digest 或進度 revision | Conflict 不得攜帶舊合法成功 |
| I32-T07 | S32-02 | DOMAIN | 已核准 mock completion 與 mock destination key | 預約唯一 Scene ExitAdmissionId 且不視作原版 Client 世界 |
| I32-T08 | S32-02 | REPLAY | 雙連線、同/異 RequestId 同角色同目標同時出場 | 只有一個合法 live admission 並 CAS；不重複生成角色 |
| I32-T09 | S32-02 | FENCING | 請求已 RESERVED 後重登/續租/撤銷或停權 | 舊 epoch 不得提交轉場；仍可安全恢復 durable progress |
| I32-T10 | S32-02 | NEGATIVE | 試圖把 Quest15 靜態 town5 / SceneList / LoadMap 當 forced entry | 拒絕未審核原版目的地/封包 writer；保留 mock opaque key |
| I32-T11 | S32-02 | RECOVERY | 轉場交易 commit 後崩潰、尚未清舊 Encounter | 重新讀 Admission 並一次性清理；不能雙場景或遺失已完成進度 |
| I32-T12 | S32-02 | STATE | 出場 ABORTED/EXPIRED 後重送舊 transfer request | Terminal monotonic；不得回到 active 或重複送出 native scene |
| I32-T13 | S32-03 | DOMAIN | mock Server admission 完成，mock actor/scene state 可重現 | 分開標 SERVER_ADMITTED 與 MOCK_SCENE_READY，不當成 Client UI ready |
| I32-T14 | S32-03 | NEGATIVE | C2S0x42、S2C0x69、C2S0x43、scene+0xCC 先有訊號 | 不得直接視為原版角色操控就緒 |
| I32-T15 | S32-03 | NEGATIVE | Client 本地 Lua LoadMap town001D、Quest15 AVAILABLE | 不得建立真正 Client runtime READY 事實 |
| I32-T16 | S32-03 | NATIVE_GUARD | 尚未掌握 KR version-scoped scene/field/actor bootstrap，企圖啟用 native writer | 回 UNSUPPORTED / DISABLED；不可生造欄位/座標/opcode |
| I32-T17 | S32-03 | REPLAY | 重複同一 mock observation id，改動 payload/context | 同值去重、異值衝突；不能升格原 Client observation |
| I32-T18 | S32-03 | DOMAIN | mock World admitted 而 mock actor snapshot 尚未 install | 保持 READY_PENDING 而非控制已就緒 |
| I32-T19 | S32-04 | RELOGIN | 教學已 durable completed，Quest15 AVAILABLE、RewardLedger 已發放，使用新 lease | 恢復每 Role 進度/Quest/Reward，不重跑 Scenario14/不再發獎 |
| I32-T20 | S32-04 | CRASH | checkpoint 已 commit，但轉場/Outbox 未完成 | reconcile exactly one transition；保留 PENDING 或 approved abort，不重賞 |
| I32-T21 | S32-04 | CRASH | 轉場 commit 後通知前斷電或通知後 ACK 前中斷 | Outbox 可重送，consumer 去重，Scene/Role 只建立一次 |
| I32-T22 | S32-04 | SECURITY | 停權→解封→舊 Session retry 同一 Admission | 舊 lease 仍被 fence；不得跳進世界或偽造控制 ready |
| I32-T23 | S32-04 | DB_RESTORE | SQLite local v2 備份還原至新測試檔；PG 003 獨立測試 | 保留 Role/Quest/Reward/scene audit；C05 新 migration 尚未使用衝突版號 |
| I32-T24 | S32-04 | E2E_PLAN | 要求宣稱原版 Client 完成教學並在城鎮自由行動 | 實際 Client/Server trace 未授權／未執行，標 NOT_RUN，不能用 mock PASS 代替 |

## 日後 Server 驗收順序

- C05-P16 `S32-01`：I32-T01～06，**進度和獎勵/NPC/Scene 分離**，測 policy/version/lease/ban、冪等。
- C05-P17 `S32-02`：I32-T07～12，ExitAdmission、單角色單 admission、scene CAS、重登/停權/崩潰。
- C05-P18 `S32-03`：I32-T13～18，嚴格分離 `SERVER_WORLD_ADMITTED`、`MOCK_SCENE_READY` 與**真正原版 Client 可操作**，最後一者因沒有授權原版 runtime 而仍 `NOT_RUN`。
- C05-P19 `S32-04`：I32-T19～24，new lease、Quest/RewardLedger、crash/outbox、SQLite/PG provider 獨立升版及備份/還原。
- 日後報告至少填 `s00_sha`、`server_sha`、`case_id`、`provider/schema`、`role_id`、`session/lease_revision`、`tutorial_progress_revision`、`quest/reward_keys`、`admission_id`、`scene_revision`、`policy_digest`、`expected/observed`、`PASS/FAIL/BLOCKED`、`evidence_class`、`native_gap`。禁止把玩家憑證、正式玩家資料或猜測的原 Client packet 標為真證據。
- `DOMAIN_SYNTHETIC` PASS 只能由將來真正執行的 Server mock tests 支持；`NATIVE_STATIC_SCOPED` 需具備同版本目標 KR BIN function/field/Conn/C2S-S2C/scene 的正反 trace；`COMPAT_CLIENT_RUNTIME` 必須另外明確授權原版 Client 執行。以上皆不因本規劃 CI 通過而成立。
