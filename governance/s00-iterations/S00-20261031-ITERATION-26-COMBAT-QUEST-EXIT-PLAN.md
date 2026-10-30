# S00 Iteration 26 — Scenario14 戰鬥權威、結算、Quest14→16→15、教學離場及重登

**2026-10-31 Asia/Taipei**｜S00 Server design／原生研究邊界收斂，**PLAN_ONLY / NOT_RUN**。KR Client 目標 BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本回合沒有重新執行原 BIN、原版 Client、原版 Server；也沒有實作獨立 `ttr_server_roy`。

## 0. 起點與相容性層級

- 開始 main：`41a7ba739e81c4f434078025b7fad2ede9436bb1`，GitHub Actions [#41125898881](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41125898881) **SUCCESS**。CI 只證 S00 台帳/離線 Python 等工作，**不證原版 KR Client 已進教學**。
- [Iteration 25](S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md) 已將 Account/Role/Admission 與 per-role TutorialProgress（提案）、QuestProgress、RewardLedger 分離，提出 SessionEpoch、事件冪等、Outbox、斷線恢復；[ADR-0006](../../design/decisions/ADR-0006-tutorial-progress-and-session-fencing.md) 仍 **PROPOSED**，沒有核准任何 original Server policy。
- 本輪讀取原件規劃 [Iteration17 E13–E26](S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json) 及 [Iteration18 E17-A–J](S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json)，**直接保留它們的 `evidence_state` 和 `blocking_unknown`**，產生可由 [唯讀檢查器](../../governance/check_s00_iteration26.py) 驗證的 [19 項 Gate overlay](S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json)。**這不是新 RR/GAP/REQ/CLM/TEST 權威或已證 original Client message chain。**
- C2S `40 00 0E 00` 是既有局部 `Tutorial.RequestStartScenario(14)` 的 Client builder 研究線索，不證原版 Server 對應回覆／連線／成功；S2C `0x004C` → `CTutorial` 本地 `map[scenarioId]=1` 是分離的 consumer。**不得把兩者配對成已證 Scenario14 官方交易，或把 `map[14]` 誤認為 Quest14/Quest16/TutorialCompleted。**
- QuestInfo.xml 靜態鏈：Quest16 對 Quest14 有 `Demand id=14`、Quest15 對 Quest16 有 `Demand id=16` 的候選資源依賴；Quest16 的 Reward type=2/value=50 **未知其貨幣/經驗值實際語意**。真正 Quest server state、NPC 互動 C2S/S2C、授權結算/退出場景仍缺正向證據。

## 1. 消除「打怪→自動完成全部教學」捷徑：五個各自有權威的聚合

| 聚合 / 權威 | 識別鍵 | Server V1 候選操作 | 禁止混淆 |
| --- | --- | --- | --- |
| `RoleAdmission`／Scene | `RoleId, SessionEpoch, InstanceId` | 驗 owner、版本、有效 lease；角色入場後才允許 encounter | Client 本地 UI ready / Client 發訊不等於 Server Admission |
| `EncounterState`／戰鬥 | `EncounterId, InstanceId, RoleId, revision` | CONFIGURED→ACTIVE→SUCCEEDED/FAILED/ABORTED，Server-approved actor/spawn/AI/action/hit/objective，CAS 定案 | 原版 Scenario14 的波次、傷害公式、AI 目前 UNKNOWN；mock 配置不是原版 |
| `ScenarioSettlement`／結算 | `EncounterId, settlementKey UNIQUE` | 先驗 objective，再單一交易記 terminal outcome、Outbox；後送 Client compatible result（**暫 feature OFF**） | 不將 S2C0x4C local map[14] 誤當 Quest14 complete 或 Server 已 ACK |
| `QuestProgress`／任務 | `RoleId, QuestId, revision` | Quest14 可接/完成/交付 → Quest16 available/accepted/completed → Quest15 available 的**候選 gating** | 每個 Quest 的 unlock/accept/turn-in 完全不同；Quest15 available ≠ accepted/completed |
| `TutorialProgress + RewardLedger` | `RoleId, progressRevision, rewardKey` | 只有已批准完成政策和 terminal/exit 前提都符合才完成；exactly-once DB effect、可重登 | 出現劇情動畫/解鎖 Quest15/獎勵事件都不能單獨證明已離開教程 |

**正反例分層**：當 Scenario14 在 mock 中贏了，只能標 `Encounter.SUCCEEDED` 與 `ScenarioSettlement.SUCCEEDED`；仍需**不同**的 Quest14 turn-in、Quest16 改變、tutorial terminal、非教程 scene readiness。Scenario14 敗北、timeout、disconnect 應留有無獎勵、安全重入或恢復策略，不可依任意固定計時自動勝利。

## 2. 戰鬥可先開發的最小接口（均是 Server-only proposal）

| Workstream | Proposed domain command / event | 不可缺失的檢查 | Client/native 線索與阻塞 |
| --- | --- | --- | --- |
| **S26-C01** Encounter admission | `ReserveEncounter(role,sessionEpoch,sceneInstance,scenarioKey)` → `EncounterReserved` | Role ownership、scene/lease valid、同 role 同 scene single-flight、versioned encounter | E17-A：Client 真實 Scenario14↔instance/scene relation 未證；T07/T02 |
| **S26-C02** Actor/world spawning | `MaterializeActorSet(encounter,templateRevision)` → `ActorSpawned` | deterministic mock fixtures，actor owner、波次 revision、spawn/removal idempotent | E17-B：T08/T07 客戶端原始 spawn/wave/座標需 source 邊界；不使用杜撰初值 |
| **S26-C03** AI and movement | `TickNpcAi`, `ApplyActorMoveIntent` | 單一 AI authority、序列 tick、場景/actor ownership、過期/非法位置拒絕 | E17-C/D：T08/T09/T05 真實 AI/移動支配權和 C2S/S2C 仍 UNKNOWN |
| **S26-C04** Basic attack and skill | `SubmitAttackIntent`, `SubmitCastIntent` | session/actor/skill owner、cooldown/resource、repeat intent key 和 hit windows | E17-E/F/G：T09/T10 skill/action/hit/death 原版時間與封包仍未閉合 |
| **S26-C05** Objective terminal | `EvaluateEncounterObjective` → `EncounterTerminated` | verified actor/death/objective state、once-only result CAS，失敗不得成功 | E17-H/I：T14 真實 Scenario14 success/failure、勝利 predicate、結果 handler 未證 |
| **S26-C06** Crash/disconnect | `FenceEncounterLease`, `RecoverEncounter` | 舊 epoch 失效、不 double spawn/damage、穩定 Outbox/Settlement | E17-J：T07/T15 original Client reconnect/scene/Lua continuity 不明 |
| **S26-C07** Scenario result adapter seam | `QueueCompatibleScenarioResult` | 必須在確認原生 S2C 必需 header/Conn/scene/field 才開；無法確定就保存域結果並 fail closed | E18/19：CTutorial app0x4C handler 局部存在，但非完整 official Server 交易 |
| **S26-C08** Quest/Reward turn-in | `CompleteQuest14`, `AcceptQuest16`, `CompleteQuest16`, `MakeQuest15Available`, `GrantRewardOnce` | 狀態前置、角色 owner、唯一 event/reward key、Quest16 reward type 未定映射 | E20–24：T14/T15/T16/T06 還需 NPC、QuestStatus、Server result 傳送/拒絕 |
| **S26-C09** Tutorial terminal / world exit | `CommitTutorialTerminal`, `ExitToNormalWorld`, `ReLoginReconcile` | 不由單獨 UI flag 設 COMPLETED；正常場景 admission＋role/world 可操作是另一 gate | E23–26：T07/T05/T16 normal world field/map/entry/Client runtime 未證 |

### 完成策略不是現在已批准的政策

提出 [ADR-0007：Encounter/Scenario/Quest/Reward bounded authority](../../design/decisions/ADR-0007-encounter-quest-settlement-boundaries.md) 作為 **PROPOSED / NON-NORMATIVE**。原版 Scenario14 actor/AI/hit、Quest 14/16/15、terminal/skip/重玩和正常世界入場均需經 S00/Server 維護者批准安全/資料/流程規則後才能變成正規實作需求。ADR-0007 與 ADR-0006 可平行規劃：前者管戰鬥及結算，後者管 role tutorial durable progress 和 session fencing；**兩個 ADR 均非 original Server 記錄**。

## 3. 設計中的「正向因果」與「可觀測驗收」分開

```text
Server-owned domain (proposed; test with MockClient):
  Authorized RoleAdmission
    -> Instance/Encounter reserved
    -> Actor roster + movement/AI + player intents validated
    -> Objective evaluated -> one terminal ScenarioSettlement
    -> Outbox delivery attempt (Client adapter separately gated)
    -> Quest14 turn-in (not same transaction automatically)
    -> Quest16 unlock/accept/complete and reward once
    -> Quest15 available (not accepted/completed)
    -> Approved tutorial terminal state + separate scene exit admission
    -> ReLogin reconcile (same Role; newer SessionEpoch, durable progress)

Client/source boundaries (NOT a proven linear official Server sequence):
  local Tutorial.RequestStartScenario(14) -> C2S 40 00 0E 00 (bounded local builder)
  separate CTutorial S2C 0x004C handler -> local scenario-ended map[14]
  separate QuestInfo 14/16/15 resource dependencies
  separate Event.stp SceneList 1001/1 and later scene resources
  actual Server send order, game frames, actor spawn, Quest turn-in, scene exit UNKNOWN
```

**產品級 E2E 成功**需**都**有 Client 進場/可操作、敵人顯示及行為、角色技能/傷害與合法勝負、Scenario settle、任務進度/獎勵、教學 terminal、非教程可操作 scene、重登不回退。不可只觀察 `S2C0x4C`、Quest15 available 或 Quest progress row 就宣布完成。

## 4. 有界研究交接，避免 Txx 重複全文分析

| Evidence package | 綁定 gate/主責 | 下一份有用的最小正向來源／反例 | 實測替代/堵點 |
| --- | --- | --- | --- |
| **R26-01** | E17-A/B, T07/T08/T05 | Scenario14 的 Scene/Instance/Actor spawn 配置、生成/移除事件、失敗路徑、Server message owner | E17-B 原本 NATIVE_STATIC_PARTIAL 不代表整波已知 |
| **R26-02** | E17-C/D/E/F/G, T08/T09/T10/T02 | Client movement/AI/attack/skill/hit 的具體 producer/consumer、role/actor/scene 統一授權及最短 message layout | 只有 Ghidra 局部 callable 不能推出誰算傷害 |
| **R26-03** | E17-H/I/J、E18/19, T14/T16/T07/T15 | Scenario14 真 objective/win/fail、S2C0x4C 需要哪些欄位/scene/Conn、Lua map reset/恢復、settle result sender | 不能從 local map 逆推出原 Server 結算結果碼 |
| **R26-04** | E20–24, T14/T15/T16/T06/T02 | Quest14 complete/turn-in→Quest16 unlock/accept/complete→Quest15 available 的 status writer、NPC、packet/資源；Reward type=2 真實語意 | 只有 XML Demand chain 不證 Server 順序、金錢/經驗映射 |
| **R26-05** | E25/26, T07/T05/T16/T15 | 完整 exit/switch world scene/actor/role-ready 和重登 client consuming path；首教學 vs 完成 route | 不能以 Quest15 Scene3/town map 的本地 Lua loader 說 Client 已離場 |
| **R26-06** | 交叉 T01/S00/T02 | 將已有 native report 的 **同 KR SHA/原件 blob/offset/CGF** 精確審核後，才更新單一 RR/CLM/REQ/SPEC TEST；新的工作先跟 Txx 去重 | 不要另建重複 RR，不因別的函式 T01 FULL-PASS 自動繼承 |

**現有正式 RR-0008**仍涵蓋選角到場景的一段，不直接解答教學完成後離場；若經正式去重確認有真的新窄題，再走唯一 `research/requests/index.json` 的 QUEUED/認領流程。**本輪不憑空新增 RR 或把其餘 Txx 研究標為接受**。

## 5. 驗收矩陣、機器校驗與 next implementation handoff

- [19-gate source-pinned matrix](S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json)：E17-A～J + E18～E26，不改原主 gate 次序。每列記原 `evidence_state/blocking_unknown`、現有 RR/GAP/SPEC、owner、Proposed Server-domain action 和 native missing proof；全部 `native_compatibility_confirmed=false`。
- [18 個 I26 設計測試](S00-20261031-ITERATION-26-ACCEPTANCE.md) 涵蓋越權、Actor/技能/傷害重送、任務完成前置、獎勵去重、Outbox crash、normal-scene admission/relog；全部 `PLAN_ONLY/NOT_RUN`。
- `python -B governance/check_s00_iteration26.py --check` 對**原始規劃 SHA/上游 evidence_state/唯一 ID/已有台帳引用/禁止偽裝 runtime**做結構驗證；另有 Unit negative tests。此檢查器不讀 Client BIN、更不驗原版封包。
- 獨立 Server 開發 `ttr_server_roy` 接手順序：**先** SR25-01/02 儲存/角色/Session → S26-C01/C02 actor/instance → C03/C04 action/AI → C05/C06 terminal/recovery → C08 Quest/Reward → C09 terminal/exit；**最後** C07 原始 Client adapter（必須來源證據、授權 runtime）。若未批准 ADR，可先建立設計/Mock prototype 並標為 proposal；不可把它直接稱正式規範。
- 本次只更新 S00 規劃與最少 DRAFT SPEC/GAP 導覽，**不改 `ttr_server_roy`**。現有 RR-0002/0010=BLOCKED、RR-0008=IN_REVIEW，`GAP-SCENE-0001 OPEN`、`SPEC-SCENE/FLOW DRAFT/PARTIAL`，直到各自真正補證仍保留。

**結論**：不用等真實 Client 才能開發 Server 遊戲邏輯，但也不能將自製資料模型或 Client 局部 handler 拼成原版官方封包。Iteration26 把「戰鬥中的權威」「Scenario 結算」「Quest 交接」「Tutorial terminal」「離場與重登」切成不同原子邊界與負向測試，供下一輪直接分派實作或研究。
