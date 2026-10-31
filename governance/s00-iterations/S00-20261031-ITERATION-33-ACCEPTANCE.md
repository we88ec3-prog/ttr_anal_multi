# S00 Iteration 33 — C05-P01～P19 整合與 Release Gate 驗收（24 項）

**全部 24 項 I33-T01～T24 為 PLAN_ONLY／NOT_RUN，並非已執行測試。** 這份是未來獨立 `ttr_server_roy` Server implementation owner 的跨工作包驗收清單，不修改正式 `conformance/test-index.json`，不代表原版 KR Client 已可玩。

參考：[完整 R0～R6 開發整合規劃](S00-20261031-ITERATION-33-C05-INTEGRATED-DELIVERY-PLAN.md) 與 [19-PR 機讀依賴圖](S00-ITERATION-33-C05-INTEGRATION-CONTRACT.json)。

| Case | Release | 類別 | 驗收刺激 | 合法預期（Server MOCK，非 native gameplay） |
| --- | --- | --- | --- | --- |
| I33-T01 | R0 | SOURCE | 重新核對 S00 source blob / Server main 與資料庫 provider version | 所有來源標記 version，不把歷史快照當最新；有差異必重新評估 |
| I33-T02 | R0 | POLICY | ADR-0006/0007 仍 PROPOSED，卻要求發佈 production C05 | Fail closed，不自動批准產品語意或 native adapter |
| I33-T03 | R0 | MIGRATION | Encounter/Combat/Quest 各自嘗試佔用 SQLite v3 / PG004 | Single allocator 拒絕版本/內容 hash 衝突，資料庫不部分升版 |
| I33-T04 | R0 | RESTORE | SQLite v2／PG003 有既存 account/character/session，升版中 crash | 保留舊資料，支援 restore-new、reopen、checksum/lock/uniqueness 檢查 |
| I33-T05 | R1 | SECURITY | 跨帳 Character、舊 SessionLease 要求新 Encounter | P01 在同 write transaction 拒絕，沒有 admission/角色資訊外洩 |
| I33-T06 | R1 | RACE | 角色改選/停權與 Encounter reserve 同時執行 | 僅 current selected role/未停權租約可以 commit，無 TOCTOU |
| I33-T07 | R1 | REPLAY | 重登 + 重播相同 Encounter/Spawn event | 唯一合法 aggregate/ActorId/generation，舊 epoch 無權 |
| I33-T08 | R1 | DETERMINISM | 同 config+seed 以兩個 Worker 和 restore 重算 AI/movement | 狀態一致且 tick 單調，跨 Encounter actor 假事件拒絕 |
| I33-T09 | R2 | NEGATIVE | Client 提交 damage/HP/death/skill success，缺有效 attack | Server 忽略 Client 權威，HP/skill ledger 不變 |
| I33-T10 | R2 | RACE | 兩個 Cast 同資源扣費、cooldown/取消互相競爭 | 單一 approved fixture commit、扣費/冷卻恰一次 |
| I33-T11 | R2 | SECURITY | stale Session 在 worker 排隊後被 ban/revoke | Hit commit 前再次驗 lease/role/ban，不能造成死亡 |
| I33-T12 | R2 | RESTORE | Hit 已扣 HP 與 Death commit 後 crash/replay | 重啟只保留同一 death/hit，不重扣/重生或破壞 outbox |
| I33-T13 | R3 | NEGATIVE | Client map[14]=1、單純 timer 到時，未有 objective proof | 不能成功結算 Scenario14 或直接完成 Quest14 |
| I33-T14 | R3 | RACE | 同一最終擊殺遇上 timeout/abort，兩 worker 判勝負 | 依 mock policy precedence 只得到一個 terminal CAS |
| I33-T15 | R3 | REPLAY | terminal/outbox 發送後 ACK 之前故障重送 | 一次 terminal，Outbox 至少一次、consumer inbox 去重 |
| I33-T16 | R3 | NEGATIVE | 同一 DeathEventId 跨 actor generation 或波次重播 | 拒絕，不計入新 wave，不補發 terminal/Quest |
| I33-T17 | R4 | SOURCE | Quest16 Reward type2 value50 無獲准映射 | REWARD_POLICY_UNRESOLVED，絕不擅自給 EXP/金錢 |
| I33-T18 | R4 | RACE | Quest14/16 turn-in 與同帳不同 Session worker、兩次 RequestId | 唯一正當 state/reward ledger，stale epoch/錯 NPC 無副作用 |
| I33-T19 | R4 | BOUNDARY | Quest16 完成但 Quest15 尚未被接取 | 最多 AVAILABLE，不自動 Accepted/Completed/TutorialCompleted |
| I33-T20 | R4 | RESTORE | RewardLedger commit 後 notification 前 crash、restore/relog | 不雙發帳、不失記錄、Outbox 重試結果可去重 |
| I33-T21 | R5 | POLICY | Quest15 AVAILABLE 或 Client Lua LoadMap，但缺教學終局政策 | 不提交 TutorialCompleted 或 WorldReady |
| I33-T22 | R5 | FENCING | Scene Exit RESERVED 後重新登入/停權解除、舊 worker 恢復 | 舊 admission/epoch 失效，新 lease 讀 durable state，不重 spawn/重賞 |
| I33-T23 | R5 | RESTORE | Transfer commit/Outbox 未 ACK 中斷並重新連線 | 同一 admission/event 一次恢復；Mock World admitted != original Client ready |
| I33-T24 | R6 | NATIVE_RELEASE | 尚無完整同版本 Client frame/Conn/actor/world 正向實機驗收 | 原生 adapter 停用，R6 BLOCKED_BY_EVIDENCE；原 Client runtime NOT_RUN |

## 前置與驗收規則

**R0→R5** 要逐項保存真實執行的 `server_sha`、`PR ID`、`test_case`、`migration manifest sha256`、`schema version/provider`、`policy revision`、`mock fixture digest`、`lease/role/scene/encounter/quest/reward/event ID`、`expected/actual`、`PASS/FAIL/BLOCKED`、`evidence_class`、`native_gap`。所有 C05 內部 mock Case 可以在原版 Client 協定未知時獨立開發與測試，**但不能用 S00 Python CI 當成這些 Case 的 PASS**。

- R0 要檢查未核准政策、schema manifest 唯一配號、SQLite v2/PG003 各自的 DB upgrade/backup/restore 以及原有 C02/C03 資料完整性。
- R1 使用 P01～03；R2 P04～07；R3 P08～11；R4 P12～15；R5 P16～19，所有前置 Server PR 都必須真正存在且測試通過才可把某層 release state 升格。
- R6 是**獨立且尚被來源阻塞的 native adapter**：Client KR SHA、同版 producer/consumer、C2S/S2C 完整 frame、Conn/scene/actor、錯誤/重送分支、授權隔離原版 Client runtime 正向可操作/負向驗證缺一不可。未執行原 Client 的 `NOT_RUN` 不得冒充 `PASS`。
- `DOMAIN_SYNTHETIC_PASS`、`NATIVE_STATIC_SCOPED`、`COMPAT_CLIENT_RUNTIME`、`ORIGINAL_SERVER_TRACE` 是不同證據種類。**本輪沒有執行任何一種類的 gameplay 驗收**，也沒有核准正式 ADR。
