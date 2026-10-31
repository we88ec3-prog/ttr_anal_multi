# S00 Iteration 31 — Quest14 → Quest16 → Quest15、唯一發獎、重登持久化和 Server 接手

**日期：2026-10-31（Asia/Taipei）｜範圍：獨立 Server 的 MOCK/DOMAIN 非規範設計**。全部驗收案例都 **PLAN_ONLY / NOT_RUN**；**沒有**在 `ttr_server_roy` 實作 Quest、Reward、DB migration，也沒有執行原版 Client 或 Server。

## 1. 已核對的基線與來源

| 庫 | 本輪核對的 main | 已有能力與**尚缺**內容 |
| --- | --- | --- |
| [S00 設計](https://github.com/we88ec3-prog/ttr_anal_multi) | `4ee57b51e600653537afaa6cecedf1cfe0551f8b` | [Iteration30 Main CI #41135452095](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41135452095) SUCCESS，僅規格與離線測試；W05 Scenario unique settlement/outbox 也**尚未實作** |
| [獨立 Server](https://github.com/we88ec3-prog/ttr_server_roy) | `272079cc69b124870af303d711931ec20bce2229` | [Main CI #41134733030](https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/41134733030) SUCCESS；現有 C00-OPS SQLite backup/restore、C02-D 停權/Session revoke、C03-C atomic selected character、C04 離線局部協定檢查。**C05 Quest/Reward 尚無實作** |

GitHub 僅為本輪讀取快照；本規格的 CI 不會重新查詢遠端 Server main。**正式資料表狀態**：SQLite local schema **v2**（C02-D 實作）；PostgreSQL migrations **001–003**（未證與 SQLite 停權策略完全同等）；Server `contracts/spec-revision.json` 仍 pin 舊 S00 `dd69ec9...`，`implemented_wire_contracts=[]`。

關鍵上游：[Iteration30 W05 勝利結算](S00-20261031-ITERATION-30-OBJECTIVE-SETTLEMENT-PLAN.md)、[Iteration27 W06/W07 任務/獎勵工作包](S00-ITERATION-27-C05-DELIVERY-MATRIX.json)、[Iteration17 E20～E24、E26 原生 Gate](S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json) 及 [Iteration26 Source-pinned Overlay](S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json)。目標原版 KR BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 2. 最重要的六種狀態：不要把它們誤當同一個完成

```text
S30 Verified Scenario14 SUCCEEDED (unique terminal)
    -> Quest14 Objective/Eligibility [reviewed MOCK policy]
       -> Quest14 COMPLETED (requires actual quest predicate)
          -> Quest14 TURNED_IN (separate authorized NPC action)
             -> Quest16 AVAILABLE -> ACCEPTED -> OBJECTIVE_READY
                -> Quest16 COMPLETED -> TURNED_IN
                   -> approved RewardLedger credit exactly once
                      -> Quest15 AVAILABLE (not accepted!)
                         != TutorialCompleted
                         != SceneExitApproved / WorldReady
```

此圖是**自製 Server 待核准 mock domain**的候選，不是原版 KR Server 已證流程。真正 `QuestInfo.xml` 已知的是 **Quest16 Demand id=14**、giver/finisher **NPC10027**、Quest16 的 `Reward type=2,value=50`；**Quest15 Demand id=16**，town5 field19 的 NPC10338 與 SceneList/本地 Lua 線索。**資源需求／動畫／UI 可顯示 ≠ 原版 Server 的 quest status/C2S/S2C / reward 結算已證。**

## 3. S31-01 — Quest14 目標證明與 NPC 交付

提議應用 API（尚未存在）：

```csharp
Task<QuestTransitionResult> OfferMockQuest14EligibilityAsync(
  SessionLease exactLease, RoleId ownedRole, SettlementId proof, Guid eventId, CancellationToken ct);
Task<QuestTransitionResult> SubmitMockQuest14TurnInAsync(
  SessionLease exactLease, RoleId ownedRole, MockNpcContext npc, Guid requestId,
  long expectedQuestRevision, CancellationToken ct);
```

- `OfferEligibility` 只能讀取 **S30 的 durable SUCCEEDED terminal**，核對 Encounter／Scene mock/config 與 Role 所有權。已存在原版 Client `CTutorial` app0x004C consumer 與 `map[14]` 只是**本地消息可消費形狀**，不能作業務證明。
- `COMPLETE`、`TURN_IN` 是獨立動作：勝利只是其中一項前置，是否須 NPC10027 及 CompleteAction、是否有其他狀態需由正式維護者核准的 mock policy 決定；不能完成關卡就自動改成任務14「已交付」。
- 必須在交易**最後寫入點**同時重新驗證 `SessionLease(SessionId,AccountId,ConnectionId,Revision,ExpiresAt)`、當前已選角色屬權、SQLite C02-D 停權狀態、Quest revision 與授權 NPC/scene context。舊會話、跨帳角色、雙提交及錯 NPC 一律不能改進度。
- Unique `(roleId,questId,transitionKind,requestId)` + payload digest 和 `expectedQuestRevision`：相同合法重送可回 Replay（須先重驗授權），**更換 payload 卻沿用 RequestId 應拒絕**，不會出現「雙交付」。

## 4. S31-02 — Quest16 解鎖、接取及完成不得混在一起

- 當 Quest14 按選定 policy 合法 `TURNED_IN` 才允許 Quest16 `AVAILABLE`；`Demand id=14` 本身不代表原 Client 會自動收到任務。
- `AVAILABLE → ACCEPTED` 要獨立授權的 NPC mock context；接受之後的 Quest16 **目標完成條件**不能單由 Quest14 勝利、S2C0x4C、UI TalkBox、或 Quest16 的獎勵配置取代。
- `ACCEPTED → OBJECTIVE_READY → COMPLETED → TURNED_IN` 的產品決策、NPC、場景、任務提示及失敗分支都需明確 policy；本輪不猜原版封包 opcode 或獎勵時點。
- 舊 Session 或修改過的 client quest status 不能越過狀態機；依 RoleId 及 QuestRevision 驗權限，同角色兩個連線的競態由 CAS 只允許一個結果。

## 5. S31-03 — Reward type=2 / value=50 必須先封存語意，再唯一發獎

**目前不能將原版 Quest16 的 `Reward type=2, value=50` 解釋成金幣、EXP、技能點或任何通用資產。** `REWARD_POLICY_UNRESOLVED` 應是 fail-closed 的合法業務結果：保留 Quest 進度和待核准結果，但**不進行未授權資產入帳或假稱 PAID**。

只有維護者核准針對**MOCK**的獎勵映射（例如測試中純內部 `MOCK_TOKEN`，不映射 Client 物品）後，才能用 `CommitMockQuestPayoutOnceAsync` 提案落帳：

1. 同交易核驗 Role/Quest/TurnIn、有效 SessionLease、停權、`RewardPolicyDigest`、已核准的 `definitionId` 與 credit 上限；
2. 確保 `unique(roleId,questId,turnInId,definitionId)`，一次性寫 `RewardLedger` 和實際被審核的 mock credit；
3. 同交易新增 Outbox 的 `RewardCommitted` intent；外部配送可 *at-least-once*，需 consumer inbox 去重，**不保證 exactly-once 網路傳輸**；
4. 崩潰於「提交前」、「DB commit 後／通知前」、「通知後／ACK 前」，都不得二次 credit；修改 RequestId/重送不同 policy digest 不能繞過 unique reward grant；
5. 如果 reward mapping 未批准、或角色/Quest/Session 權限不符，不能把該筆任務標示成「已發獎」，不可因補償流程失敗而重發過去的獎勵。

**Quest 完成狀態與 RewardLedger 是兩個不同 aggregate**。若產品政策要求同一個 TurnIn 包含一次性 payout，就必須採單 transaction 實作；不能只靠外部訊息後續發放而跳過 unique ledger，亦不能使已接受任務因未批准 reward 被誤標已付款。

## 6. S31-04 — Quest15「可接」與正常世界「可玩」分離

- Quest16 按已核准政策正式結束/交付/發獎後，Quest15 才進入 **AVAILABLE**；**AVAILABLE ≠ ACCEPTED ≠ COMPLETED**。
- `Quest15 <Demand id=16>`、town5/field19/NPC10338 只是原版靜態資源及部分本地 consumer，不能自行推導已跳村、正常世界已載入、角色已生成或 Client UI 可操作。
- 重登後從 durable per-Role QuestProgress/RewardLedger 重建結果，未交付不自動交付、已發獎不重發；ban/unban/reconnect 不會復活舊 SessionLease。
- 教學正式完成 `TutorialCompleted` 與 `WorldReady` 仍屬 **S27-W08** 的獨立決策及原 Client Scene/Actor gate；不因 Quest15 available 或任務16結束而自動放行。

## 7. Migration 版本排序：防止多個 C05 工作包撞版

之前 Iteration28～30 均把 **SQLite v3 / PostgreSQL v4** 當作「相對當時基準」的**候選下一版**，並未實際寫入 migration。**若讓 Encounter、Combat、Settlement、Quest 四個子團隊都建立 SQLite v3／PG 004，必然產生版本衝突或已建表不一致。**

本輪要求獨立 Server implementation owner 先建立一份 **C05 全模組 migration 序列表**，再核准以下任一政策：
- 依 P1～Pxx（Encounter → Actor → Action → Settlement → Quest/Reward）各自分配互斥的版本號，或
- 由同一次明確核准的 C05 schema migration 合併建表；其版本只有**一個**來源並有可用的 rollback/restore 計畫。

**本輪不替 Server 選定任何新的數字版本**：`sqlite_next=UNALLOCATED_NOT_APPLIED`、`postgres_next=UNALLOCATED_NOT_APPLIED`。下一次落地需實際先核對最新 schema/migrations，不能憑本文件假設目前沒有其他團隊先開工。

建議待核准候選表：`mock_quest_progress`、`mock_quest_transition_inbox`、`mock_reward_definition`、`mock_reward_ledger`、`mock_quest_outbox`、`mock_quest_consumer_inbox`。**SQLite 本地 v2 與 PostgreSQL 003 是兩份不同 Provider schema**；各自需要升級、範圍鎖、FK/unique/verifier、現有 C02/C03 資料保存、backup→restore-new→reopen、雙工並行和意外中斷測試。C00-OPS CLI 已能備份／還原，不表示未來新表已通過恢復驗收。

## 8. 真正的下游開發交接與研究需求

| 建議下游 Server PR | 工作包 | 尚未執行的最小測試 |
| --- | --- | --- |
| C05-P12 | S31-01 Quest14 eligibility、QuestRevision/CAS 與 NPC TurnIn | [I31-T01～T06](S00-20261031-ITERATION-31-ACCEPTANCE.md) |
| C05-P13 | S31-02 Quest16 unlock、accept、objective/turn-in | I31-T07～T12 |
| C05-P14 | S31-03 未核准 reward quarantine、唯一 Ledger/Outbox/恢復 | I31-T13～T18 |
| C05-P15 | S31-04 Quest15 可接、重登 reconciliation、Scene/教學分界 | I31-T19～T24 |

下游尚有 **Iteration28 Encounter/Actor、Iteration29 Combat、Iteration30 Objective/Settlement**，均是設計而非已在 Server main 實作的模組，必須依序做出可測的內部 domain 才能從 Scenario14 真正開始 Quest14。

**原版 Client 分析由既有 Task/Gate 接手，不重新創造正式 RR**：E20 Quest14 writer/NPC（T16/T14/T15）；E21 Quest16 TalkBox/接取（T16/T06/T02）；E22 Reward type2/真實消費端（T16/T14/T15/T04）；E24 Quest15/Town UI（T16/T06/T02）；E23/E26 教學終局與重登（T15/T16/T05/T04）。需要同版 Client SHA、C2S/S2C 方向、Conn/scene/field/role owner、長度、失敗分支和源級因果鏈；原版 Client 真正執行另需使用者明確授權。

[機讀工作包](S00-ITERATION-31-QUEST-REWARD-CONTRACT.json)、[24 項驗收草案](S00-20261031-ITERATION-31-ACCEPTANCE.md) 及 `governance/check_s00_iteration31.py --check` 只做**規劃**的來源與狀態檢查。正式 `ADR-0006/7` **PROPOSED/NON_NORMATIVE**、SPEC-FLOW/SCENE **DRAFT/PARTIAL**；不變更 `RR/REQ/GAP/CLM/TEST` 台帳狀態，不更動 `ttr_server_roy` 的任何原碼或 db，也不聲稱原 Client 已可玩。

**下一階段 Iteration32 候選**：S27-W08 教學終局、正常世界 Scene Exit/WorldReady、重登與原版 Client 的分層驗收；不把 Quest15 可接當成已離開教學。
