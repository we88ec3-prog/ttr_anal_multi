# S00 Iteration 30 — Scenario14 勝負目標、波次、唯一結算、Outbox 與 Quest14 交接驗收

**24/24 案例均為 PLAN_ONLY / NOT_RUN。** 本輪不執行原版 Client、Server C05 gameplay 或原版 Server，不新增正式 `conformance/test-index.json` 的 TEST。這是下一次在獨立 `ttr_server_roy` 進行 Server-only mock 實作時的驗收草案。

參考：[Iteration30 完整規劃](S00-20261031-ITERATION-30-OBJECTIVE-SETTLEMENT-PLAN.md)、[S30-01..04 機讀契約](S00-ITERATION-30-OBJECTIVE-SETTLEMENT-CONTRACT.json)、[Iteration29 verified hit/death 原型設計](S00-20261031-ITERATION-29-COMBAT-IMPLEMENTATION-PLAN.md)。

| Case | Package | 分類 | 刺激／前置 | Mock Server 預期（不等於原版 Client 相容） |
| --- | --- | --- | --- | --- |
| I30-T01 | S30-01 | DOMAIN | 已 commit 的 S29 DeathEvent、同 Encounter 正確 actor generation | Objective inbox 收一次事件，objectiveRevision 遞增一次，不產生 terminal |
| I30-T02 | S30-01 | REPLAY | 同 DeathEventId 同 payload 由兩 worker 重播 | 唯一事件/結果，objective counter 不重複計數 |
| I30-T03 | S30-01 | NEGATIVE | Client 自稱 kill、HP≠0、action/cast 未 commit | 拒絕作權威，不動 Objective/Quest/Outbox |
| I30-T04 | S30-01 | NEGATIVE | 跨 Encounter ActorId、舊 generation / 舊 wave death | 拒絕錯 scope 事件，不借用其他波次擊殺 |
| I30-T05 | S30-01 | FENCING | Session renew/revoke/ban 後舊 worker 提交玩家所屬 death event | 在單一權威交易/已批准 actor processing lease 下拒絕 stale event |
| I30-T06 | S30-01 | CONFLICT | 同 DeathEventId 不同 actor、HP 結果或 payload fingerprint | 回 Conflict，不得把後者當新擊殺 |
| I30-T07 | S30-02 | DOMAIN | mock fixture 三波，第一波所有必需 death 已驗證 | 第一波 COMPLETE 後唯一地進入第二波，不直接通關 |
| I30-T08 | S30-02 | NEGATIVE | 部分 required actor 還活著或 ActorDeath 未 commit | 不宣稱 wave/Scenario 成功 |
| I30-T09 | S30-02 | TIMING | 只有計時器走完，沒有達成明確 goal | 不得自動成功；可依已核准 mock failure policy 判失敗 |
| I30-T10 | S30-02 | RACE | 最後一次合法擊殺與超時/abort 同 tick 競爭 | 按 mock fixture 指定的固定決勝序與 CAS 得唯一結果 |
| I30-T11 | S30-02 | REPLAY | 重複進波次命令或由舊 worker 帶過期 expectedRevision | 不二次 spawn/跳波，回 Replay 或 Conflict |
| I30-T12 | S30-02 | NEGATIVE | 切換途中 fixture hash/configVersion 變化 | fail closed、不能跨配置拼接勝利 |
| I30-T13 | S30-03 | DOMAIN | 所有前置 mock objectives 真正成立並已保存 objectiveRevision | RESERVED/ACTIVE 正確落到唯一 SUCCEEDED terminal，留下證據 hash |
| I30-T14 | S30-03 | NEGATIVE | Lua map[14]=1、Client S2C0x004C consumer 或 QuestInfo14 畫面旗標 | 不能直接觸發 Server 結算/Quest14 完成 |
| I30-T15 | S30-03 | CONCURRENCY | 兩 worker 以不同 settlementKey 同時判相同 Encounter 勝負 | 唯一 Terminal CAS，另一衝突，不能雙終局 |
| I30-T16 | S30-03 | RECOVERY | terminal + audit/outbox commit 後 worker 崩潰 | 重啟讀出相同 terminal/一個事件，不再次勝利或增額 |
| I30-T17 | S30-03 | NEGATIVE | 舊 Session/失效 Role/錯 scene/不同 objectiveDigest 提交 terminal | fail closed，沒有偽造 success 記錄 |
| I30-T18 | S30-03 | RACE | 合法 fail/abort 與 success objective 同時抵達 | 依 fixture precedence 唯一合法 terminal，禁止 FAILED→SUCCEEDED |
| I30-T19 | S30-04 | DOMAIN | 唯一 ScenarioTerminal 寫入 Outbox，adapter 只處理 mock event | 一次持久化、多次投遞容許，不能自動送 KR 0x4C |
| I30-T20 | S30-04 | RECOVERY | outbox 發送後 crash before ACK、worker 更換 | 重送安全，consumer inbox 去重，不 double terminal/Quest |
| I30-T21 | S30-04 | NEGATIVE | 原版 KR 封包/Conn/scene 仍未確認，要求對外送 Scenario14 result | native adapter 明確 Unsupported/Disabled，保留 durable 事件待核准 |
| I30-T22 | S30-04 | BOUNDARY | Scenario SUCCEEDED 但 Quest14 尚未正式 NPC 交付 | 最多生成待查 eligibility，不升 Quest14 COMPLETED/TURNED_IN |
| I30-T23 | S30-04 | RECOVERY | DB commit 後 backup-restore 至新 disposable SQLite、重放 EventId | 維運檢查可辨資料一致性；新增 C05 schema/backups 須另行核准，no double event |
| I30-T24 | S30-04 | E2E_PLAN | 原版 KR Client 接到真正 Scenario14 result 與 Lua/Quest 流程 | 另需明確授權與同版 Client/Server 封包證據；本項 NOT_RUN，不能用 mock 取代 |

## 日後實際執行才可填入的證據

每個案例至少附 `s00_commit`、`ttr_server_roy_commit`、`case_id`、`provider(SQLite/PostgreSQL)`、`schema_migration_version`、`fixture_digest`、`encounter_id`、`actor_generation`、`death_event_id`、`objective_revision`、`settlement_key`、`outbox_event_id`、`expected / observed`、`PASS/FAIL/BLOCKED`、`evidence_class`。使用測試用 ID，禁止將真玩家帳密/個資放入 CI log。

- **DOMAIN_SYNTHETIC**：只證明自製 Mock Encounter/Objective 的交易與冪等；必須在真正完成相關 .NET/DB 測試後才能報 PASS。
- **NATIVE_STATIC_SCOPED**：只承認同版 KR BIN 的 producer/consumer/方向/Conn/scene/field bounds、失敗分支及反例，不能從單一 `CTutorial` map flag 擴大成已證 Server 封包。
- **COMPAT_CLIENT_RUNTIME**：需另行明確授權與完整 Original KR Client 可操作/UI/攻擊/Scenario/Quest/重登結果。
- **ORIGINAL_SERVER_TRACE**：只有真實 original Server trace/source 才可使用；此規劃完全沒有此種證據。

先落地 `I30-T01～T06` 驗 ActorDeath Inbox，接 `T07～T12` Objective+wave，再 `T13～T18` terminal CAS，最後 `T19～T24` outbox/Quest boundary。**若 Iteration28/29 的 W01～04 尚未實作，必須在 Server repo 先完成前置模組，不能把本文件當可運行遊戲程式。**
