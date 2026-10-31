# S00 Iteration 32 — 新手教學終局、正常世界入場與重登恢復的可實作交接

**2026-10-31 Asia/Taipei｜非規範 Mock-domain 設計，24 個預定案例全為 PLAN_ONLY / NOT_RUN。** 本次沒有在獨立 `ttr_server_roy` 實作新的 C05 Server 程式／資料庫，也沒有啟動原版 KR Client 或記錄原服封包。KR 目標 BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 1. 最新基線、有效證據與工作切分

| 專案 | 本次核對的 main | 事實與缺口 |
| --- | --- | --- |
| [S00 規劃](https://github.com/we88ec3-prog/ttr_anal_multi) | `dcbb7f9d41b50bdf563ff849ae1442f56d9c40c4` | [main CI #41136854759](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41136854759) **SUCCESS**（台帳、來源與離線規劃回歸測試，並非 Client 玩法驗收）。[Iteration31](S00-20261031-ITERATION-31-QUEST-REWARD-PLAN.md) 已規劃 Quest/Reward，但仍未真正寫入獨立 Server |
| [Server 實作](https://github.com/we88ec3-prog/ttr_server_roy) | `272079cc69b124870af303d711931ec20bce2229` | [main CI #41134733030](https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/41134733030) **SUCCESS**（離線 C00-OPS/C02-D/C03/C04 級別）。C05 World/Scene/Gameplay/Quest/Reward/TutorialExit **未實作**；`contracts/spec-revision.json` 仍 `implemented_wire_contracts=[]` |

原生部分：[Iteration17 E23/E24/E25/E26](S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json)、[Iteration18 E17-J](S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json)、[Iteration26 Gate overlay](S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json) 分別維持 `SERVER_POLICY_NEEDS_ADR`、`SOURCE_BACKED_PARTIAL`、`NATIVE_DISCOVERY_REQUIRED`、`ORIGINAL_CLIENT_RUNTIME_REQUIRED`、`SERVER_POLICY_PENDING_ADR` 等等級；S00 規劃不得擅改研究者已記錄的 status/owner/source。

**本輪唯一主線：**深化 [S27-W08](S00-ITERATION-27-C05-DELIVERY-MATRIX.json)，承接 [Iteration31 的 Quest14/16/15、RewardLedger](S00-ITERATION-31-QUEST-REWARD-CONTRACT.json)，形成四個開發切片：**S32-01** 完成資格／checkpoint、**S32-02** 出場 admission／CAS、**S32-03** 世界 ready／Client 觀測隔離、**S32-04** 重登／停權／崩潰恢復。實作順序為 C05-P16～P19，先有前一輪 C05-P1～P15 的內部模組才能全通過。

## 2. 必須拆成三條狀態軸（修正「任務完成即進村」誤解）

```text
A. 每角色 durable TutorialProgress（Server產品 mock domain）
   NOT_STARTED → IN_PROGRESS → TERMINAL_ELIGIBLE → COMPLETED_POLICY_APPROVED
                (policy may require exit ordering; DO NOT promote by default)

B. 本次 SceneExitAdmission／角色場景租約（短期 fencing）
   NONE → RESERVED → TRANSFERRING → WORLD_DOMAIN_ADMITTED
                ↘ ABORTED / EXPIRED
   WORLD_DOMAIN_ADMITTED != REAL_CLIENT_CONTROL_READY

C. Original Client 世界場景實際觀測（另需授權）
   UNOBSERVED → SCENE_LOADED_OBSERVED → CONTROL_READY_OBSERVED
   原版 Client runtime NOT_RUN，因此本輪不能設定 B→C 的自動規則
```

另外 **`Scenario14 SUCCEEDED` ≠ `Quest14 TURNED_IN` ≠ `Quest16 TURNED_IN` ≠ `RewardLedger CREDIT_COMMITTED` ≠ `Quest15 AVAILABLE` ≠ `TutorialCompleted` ≠ `WorldReady`**。何時標教學完成（是在場景切換之前或之後）是待核准的產品政策與 ADR-0006/0007，不是原版已證協定，不能由單一 UI/Lua/QuestInfo 靜態資源擅作決定。

## 3. S32-01：角色層級教學終局資格與唯一 checkpoint

提案 `EvaluateMockTutorialCompletionEligibilityAsync(SessionLease,CharacterId,ExpectedProgressRevision,...)` 和 `CommitMockTutorialCheckpointAsync(...)`；**新 API，不是現有 C#**。

- 前置使用 durable `Scenario14` terminal（S30）、Quest14/16 經核准的目標與 NPC 交付、RewardLedger 最終入帳（S31）與可能的 Quest15 available；這些是 **可配置且需審核的 mock policy**，不是原版自動規則。單靠 Quest15 可接、任務 UI、`CTutorial map[14]` 或 Lua `IsScenarioEnded(14)` 都不足。
- 保留 `Role/CharacterId` 專屬 `TutorialProgress`、policy digest、`progress_revision`、`completion_event_key`、audit；不能將帳號第一次登入當作所有角色都已完成教學，也不可把 selected role index 當永久 ID。
- **授權和入庫必在同一資料庫交易權威**：以 `SessionLease(SessionId,AccountId,ConnectionId,Revision,ExpiresAt)`、當前 selected CharacterId 角色所有權、SQLite C02-D ban、expected revision、已核准 policy version 檢查，防重登、停權與跨帳 TOCTOU。相同 RequestId+payload 在重新授權後可 Replay，不同 payload 同 key 返回 Conflict。
- checkpoint 終局一旦 committed 不可被舊 session/背景 job 改回 IN_PROGRESS；如果業務政策要求 SceneExit 才算完成，先持久化 `TERMINAL_ELIGIBLE`，待 exit 的同一批准協調策略完成再推進；不能說本輪已決定官方完成旗標。

## 4. S32-02：出場 admission／轉場，不能由 Client 靜態場景推成 Server 規則

提案 `ReserveMockNormalWorldExitAsync`、`CommitMockSceneTransferAsync`、`AbortOrExpireMockSceneTransferAsync`。

- 入場需先核准角色 SceneExit policy 與 destination 的**純 mock opaque key**，比對 `ProgressRevision/SessionLease/role/Encounter/SceneGeneration`，再用唯一 `AdmissionId` 和 `expected_revision` CAS 預約。一位角色同 epoch 不得有兩個 live admission；不同 epoch 不得沿用舊結果。
- EXIT 的 `RESERVED→TRANSFERRING→WORLD_DOMAIN_ADMITTED` 都是 Server 自製 domain transaction；成功不代表原 KR Client 已載入地圖、收到 Actor、取得操作權。只有 transaction 已提交／經核准補償策略才清場上 Encounter，不能先刪除 tutorial 進度造成斷線後重跑。
- `Quest15 SceneList(15,1..4)`、`Scene3` 的 `pindos_talkevent Lua LoadMap town001D.map` 和 `T07 0x005F type6` 存在正反解讀缺口，**不是 Server 必須往 town5/field19 強制傳輸的直接證據**。不寫入猜測座標、出生點、欄位或 opcodes。
- 過期、重登、renew/revoke/ban 舊 Session 後，舊 `AdmissionId` 不可提交或重送伺服器通知成功；不可跨角色偷用 scene actor lease。

## 5. S32-03：「世界 Domain 已入場」不等於「原版 Client 已可玩」

建立三個不同層次的觀測欄位與明確測試證據種類：

| 層次 | 可支持的 mock-domain 狀態 | **不成立**的主張 |
| --- | --- | --- |
| `SERVER_WORLD_ADMITTED` | Server 內部 SceneExit 的唯一 commit、有角色、SceneGeneration/Admission 識別和 durable audit | 不代表原版 Client 真的收到任何 game frame |
| `MOCK_SCENE_READY` | 透過測試版 mock actor/scene snapshot 可被重現，僅為內部 fixture/Domain assertion | 不代表 KR SceneLoaded/角色模型顯示/可行走 |
| `CLIENT_SCENE_LOADED_OBSERVED`／`CONTROL_READY_OBSERVED` | **只可能由另行授權的同版原 Client 實際操作**與有完整方向/Conn/field/Actor/Control 路徑支撐 | 本輪未執行，永不由 mock state 自動升格 |

**不可推論**：C2S0x42、S2C0x69 subtype7、C2S0x43、Client `scene+0xCC` pending、Client Lua `LoadMap`、Quest15 AVAILABLE、S2C0x004C 本地 flag 或任意 localhost mock Client PASS 都不是原版世界已可操作的單獨證據。仍需 T07/T05/T06/T16 來源和使用者另行授權的 Client runtime 才可解除 S27-W09 Native adapter gate。

## 6. S32-04：重登、停權、獎勵不重發和崩潰恢復

- **四組 Crash/Replay**：①完成資格 commit 前斷電；②checkpoint commit 後、transfer 前；③transfer commit 後、outbox message 前；④outbox 已送但未 ACK。用持久化 `CompletionEventId`、`AdmissionId`、`SceneRevision`、RewardLedger unique key、consumer inbox 恢復，重試不重複 Quest、Reward、Spawn、SceneExit。
- 新 SessionClaim/renew/revoke/ban 或 disconnect 使舊 `SessionLease` 的所有待處理 player action/transfer 寫入失效；**解封後不能復活舊 Session**。不能因 Client local 重登畫面初始化/清除 map 而重跑已完成的 Server durable 關卡。
- 若缺原 Client 世界入場 adapter、destination policy 或某個前置 gate，允許顯示內部 `PENDING/BLOCKED`，**不得**以亂轉場、清空 tutorial 資料或硬設 `WorldReady=true` 取代真實處理。對原版 Client 可玩流程，本輪仍是 source-gated。
- SQLite local **user_version=2**（C02-D ban/revoke），PostgreSQL 已有 migration **001–003**。新增 C05 的 Encounter/Combat/Settlement/Quest/Exit 表必須沿用 Iteration31 要求的**唯一遷移版本配置者**；本輪所有新增 schema/版號都是 `UNALLOCATED_NOT_APPLIED`，不能把之前幾輪各自提過的 SQLite v3/PG004 都同時落地。
- 現有 C00-OPS 離線 SQLite `status/check/backup/restore-new` 是有用的資料保護工具，但並未替 C05 新表或完整世界就緒驗證。下游應加入每 provider 的 backup→restore-new/reopen、schema checksum、unique event/foreign-key/CAS、舊帳號角色/Quest 不丟失，以及多 worker crash/ban/race 合成測試。

## 7. 後續 Server 工程 PR 與真正 Client 研究交接

| 建議獨立 Server PR | 工作包 | 尚未執行的測試 |
| --- | --- | --- |
| **C05-P16** | S32-01 per-role completion eligibility / durable checkpoint | [I32-T01～06](S00-20261031-ITERATION-32-ACCEPTANCE.md) |
| **C05-P17** | S32-02 SceneExitAdmission / transfer CAS / stale fencing | I32-T07～12 |
| **C05-P18** | S32-03 Mock WorldReady state / Client source-gated observation | I32-T13～18 |
| **C05-P19** | S32-04 relog/ban/crash/outbox/provider reconciliation | I32-T19～24 |

**研究需求（不偽造新的 RR）**：E23 由 T15/T16/T04 核對 tutorial terminal writer/角色 vs 帳號；E24 T16/T06/T02 確認 Quest15 可接與接取；E25 T07/T05/T06/T16 需找到正確 Scene leave→field/world install→Actor bootstrap→Client control 的方向／Conn／scene／error paths；E26 T15/T05/T04 需同版原版 KR Client 重登／場景／角色可操作驗收（另行明確授權）。E17-J 的重送、逾期、舊場景需 T15/T02/T07/T14 幫助 closure。原 `RR-0008`、`GAP-SCENE-0001`、`SPEC-SCENE-0001` 狀態**沒有**因本輪 CI 被升格。

正式 `ADR-0006/0007` 仍 PROPOSED / NON_NORMATIVE；不更改正式 `RR/REQ/GAP/CLM/TEST`、獨立 Server 的 `contracts/spec-revision.json`、任何原版 KR Client 實際協定或開機相容性旗標。

## 8. 下一步選項（不得誤記已完成）

若接著要求開發，須在 `ttr_server_roy` 由 P1 原子入場／Encounter 開始依序實作，逐一以真實 .NET/SQLite/PostgreSQL CI 評估。若接著要求規劃，Iteration33 可整理 C05-P1～P19 的 **整體依賴、migration 單一序列、policy 決策優先順序、分層驗收與 native Client source-gate release checklist**，幫助多工作包開發而不混淆先後。
