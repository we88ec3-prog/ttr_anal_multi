# S00 Iteration 26 — Encounter／Scenario14／Quest14-16-15／離場重登驗收設計

**全部 18/18 個案例：PLAN_ONLY / NOT_RUN**。只規劃未執行，非正式 conformance/test-index.json TEST，也不是原始 KR Client／原版 Server 的實測相容性。

來源：[Iteration17 E13-E26 gate](S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json)、[Iteration18 E17-A～J gate](S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json)、[Iteration25 域進度及恢復](S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md)；19-gate source-pin 索引：[Iteration26 JSON matrix](S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json)。詳 [Iteration26 完整規劃](S00-20261031-ITERATION-26-COMBAT-QUEST-EXIT-PLAN.md)。

| Case | 層級 | Gate | 測試刺激與狀態 | 新 Server 自訂預期（不代表官方原版 Client） |
| --- | --- | --- | --- | --- |
| I26-T01 | DOMAIN | E17-A | 同帳號同一 RoleId/SessionEpoch 嘗試兩次 EncounterAdmission | 只產一個 Instance/Encounter lease，重送引用既有結果；不是 Client 原生入場驗收 |
| I26-T02 | NEGATIVE | E17-A | RoleId owner 不符、錯 WorldInstance 或斷線舊 epoch | 拒絕入場與 Actor spawn，不回覆假 success |
| I26-T03 | DOMAIN | E17-B | 合成 EncounterConfig 含合法角色/怪物模板 | 按配置可重現生成與銷毀，不把假波次當原版 Scenario14 |
| I26-T04 | NEGATIVE | E17-B/E17-C | Client 偽造 Spawn/AI success 或不屬自己的 Actor 動作 | 拒絕跨 owner/越權生成，Client/local AI 不決定 authoritative outcome |
| I26-T05 | DOMAIN | E17-D | 移動更新中角色錯位、tick stale、scene mismatch | movement/state revision 單調，過期更新不得回退 actor |
| I26-T06 | DOMAIN | E17-E/E17-F | 同一次普通攻擊/技能 cast 重送、並行消耗 | 相同 intent 去重，冷卻/資源扣除唯一，實際原版技能資料仍待 T09/T10 |
| I26-T07 | NEGATIVE | E17-G | Client 提交自選傷害或重送怪物死亡事件 | 只採 server-authorized hit，傷害/死亡至多一次且不超授權 |
| I26-T08 | DOMAIN | E17-H | 目標尚有存活敵人、計時到期、未達擊殺條件 | 不能因時間或 Client 回覆自動宣告 Scenario14 成功；勝利 predicate 需明確配置 |
| I26-T09 | CONCURRENCY | E17-I/E17-J | 兩個 worker 同時對 Scenario14 計算終局結果 | Terminal outcome CAS/unique key 唯一，不 double reward/spawn，失敗有可追跡狀態 |
| I26-T10 | RECOVERY | E17-J/E18 | 結算資料庫 commit 後 outbox 發送失敗、重啟 | 可重新送出有版本證據的通知而不再 commit 領域結果；不假稱 0x4C 已被 Client 確認 |
| I26-T11 | STATIC PLAN | E18/E19 | Client 部分 source 的 S2C0x4C handler 與 local IsScenarioEnded(14) | 記錄 sender/consumer 不等於官方 Server 因果；本地 Lua map reset/reentry 與 Quest 權威不同 |
| I26-T12 | NEGATIVE | E20 | Scenario14 marked settled 但 Quest14 turn-in/前置未核准 | Quest14 不自動完成，錯誤序列與跨角色必拒 |
| I26-T13 | DOMAIN | E21 | Quest14 真的完成且 NPC 互動/接取條件具有效 Server policy | Quest16 AVAILABLE、ACCEPTED、COMPLETED 獨立；本例不驗證原始 Client NPC wire |
| I26-T14 | DOMAIN | E22 | Quest16 完成請求與 reward key 重播 | RewardLedger 唯一提交，Quest16 reward type2/value50 原始業務意義不得擅映射貨幣/EXP |
| I26-T15 | NEGATIVE | E23/E24 | Scenario14 success 或 Quest15 available；Quest16 未完成 | Tutorial COMPLETED 不可提前，Quest15 available 不等於 accepted/completed |
| I26-T16 | RECOVERY | E25 | Quest/教程 domain 完成，但退出 scene adapter OFF 或 scene bootstrap 失敗 | 保留 durable progress，世界/原版 Client READY 不得憑空提升；下次可安全重試 |
| I26-T17 | RECOVERY | E26 | 斷線舊 epoch 重送 scenario/quest/reward、重登換新 epoch | 舊 lease 拒絕，角色/Quest/獎勵持久化重讀，進度不倒退、不雙發 |
| I26-T18 | E2E PLAN | E17-A..J/E18..E26 | 另行授權隔離 KR 原版 Client 從教學戰鬥到 Scenario 結算、Quest14/16、Quest15可用、離場與重登 | 需 exact build/原件 SHA、frame/Conn、scene、actor、UI、quest/recorded outcomes；本回合 NOT_RUN、synthetic 不可替代 |

## 實際執行記錄要求

每次日後真正執行必須保存：case_id, linked_gate_ids, Server commit, S00 matrix commit, Client SHA（如適用）, environment, fixture hash, account_id/role_id（可用測試代號且不得洩露真資料）, session_epoch, encounter_id, input, expected, observed, result PASS/FAIL/BLOCKED, evidence_type, scenario/quest revision, native_scope, unresolved_dependencies, reviewer/date。

證據級別不可混用：
- **DOMAIN_SYNTHETIC**：只證新 Server 模型對應 case 的決定性結果。
- **NATIVE_STATIC_SCOPED**：必須有同 SHA 原始 BIN/資源 bytes、函式/handler/offset/場景/反例及明確審查，不能憑本計畫自稱。
- **COMPAT_CLIENT_RUNTIME**：必須有使用者另行授權的隔離實測、完整 Client→相容 Server 交換與可見/UI/操作結果。
- **ORIGINAL_SERVER_TRACE**：只有實際可驗的原版 Server trace／原始實作才有資格宣稱；本專案沒有此類證據。

Server 實作順序：先 T01～T10 的 actor/encounter/outbox 交易模型；再 T11～T15 區分 Client local scenario 和 Quest/Reward；後 T16～T17 的離場與重登；T18 是需要另行授權與正向協定的終局驗收，**不可因無原版實測就停止 Domain 工作，也不可因 Domain 測試 PASS 就關閉原版兼容 GAP**。
