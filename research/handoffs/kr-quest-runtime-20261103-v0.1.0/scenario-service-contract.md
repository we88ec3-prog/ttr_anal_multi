# 單人 Scenario 與任務 Runtime：遷移接口候選

版本 `0.1.0`；分類 **SERVER_CANDIDATE_DESIGN**。本稿供 S00 接口設計，沒有修改 Server、Client、DB、owner、RR、分支或既有驗收。所有來源識別、Git blob SHA、下載後精確 blob 對照均在 `source-provenance.json`；16 筆逐分支對照在 `migration-evidence.json`／`migration-matrix.csv`。

## 1. 實際讀到的版本與目前已通邊界

正式分析 main 為 `83959c0e7e65ab01348b285f03c285f487077610`。此 main 的 W1 已有結果，W2/W3 仍主要是工作卡；它沒有最新本機教學及馮德斯結果。補充來源按 Server 文件已引用的分析開發 commit `76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac` 精確選讀，不能說已公開合入 main／RR。

Server main 為 `69c714c54fb5c802251736ee38ff37c19fba3c53`，真正含本次專用分支的既有 `codex/tutorial-combat-priority-20261101` 為 `f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e`。本次透過 connector 唯讀程式與文件，沒有執行任何 Server。不是拿舊 main 當現用程式，也不是自行創分支。

已保存的人工與 SQL 收據分兩層：全新帳號教學到廣場有正常人工回報及首戰／角色／裝備的去敏保存快照；v12 正常到馮德斯有 stage1..4、同連線教學 proof、人物／NPC／移動停止及 loading 可見回報。然而 v12 有 NPC 對話重疊、清怪自動換場、Z 後殘留移動三項缺陷。v13/v14 修改後不能直接繼承「全通」判定；其 portal 與保留戰鬥需求可保留，Z 強制停步／方向鎖後來被否定，**本稿不採該輸入政策為任務 primitive**。詳 `acceptance-evidence.md`。

目前 `LocalPhindosStage.Accepted` 是實際編隊確認後的**副本入場** milestone；`ArrivalAuthorized` 是到村資格。兩者都不是 Quest15 的合法接取／結算 enum。現有保存記錄沒有 Quest15 完成 key，Quest16 raw `type2/value50` 仍 `PENDING_NATIVE_PUBLICATION`。新引擎不可將 stage1/stage4 直接匯入 `quest.accepted/settled`。

## 2. 服務界線

| 服務 | 有權決定／保存 | 對外業務輸入輸出 | 不應承擔 |
|---|---|---|---|
| Quest Runtime | 前置、任務 scope、接取、目標計數、可交件、合法結算、下一任務 eligibility | `NpcIntentObserved`、`SceneReceiptObserved`、`InstanceObjectiveEvidence`；產出型別化 commands | 原始 byte array、怪物 AI／碰撞／技能傷害、scene/controller 的 opcode 分支 |
| Scenario Service | 單人實例與編隊授權、地圖圖形、節點進度、遭遇結果、出口及結果返回 | `PrepareAdmission`、`ConfirmFormation`、`EnterNode`、`RequestPortalUse`、`RequestResultReturn` | 任意把副本完成改成 Quest15 完成或直接授獎 |
| Encounter Service | Server 怪物／角色生命週期、傷害死亡、目標合法證據、combat context | `StartEncounter`、`EncounterObjectiveSatisfied`、`DeathPresentationComplete` | 自動換圖、改 Quest DB、把空怪集合視為所有任務成功 |
| World／Scene Service | controller、map、actor/NPC 初始化、loading／bind、對話／演出 handoff | `InstallWorld`、`PlayScene`、`PrepareSceneHandoff`、`RebindWorld` | 把 scene receipt 當通關或 DB 成功 |
| Settlement／Reward Service | 成就／獎勵資格、交易、ledger、提交版本與待發布記錄 | `AuthorizeSettlement`、`CommitSettlement`、`PublishCommittedOutcome` | 依 raw reward type 猜幣種／EXP 或從送包成功推定已付 |
| KR adapter／既有編碼器 | 依 session、scene/controller、方向與 message shape 映射業務事件 | domain command → validated DTO → existing encoder | 將同 opcode 的不同 scene 融合為通用 ACK |

`QuestRuntime → ScenarioService` 應是介面呼叫；不把遭遇／NPC／血量／portal bytes 插入 quest nodes。發送先後在 adapter profile 中維護，內容只引用版本化 profile。來源 decoder 先產生 `ObservedIntent`；Runtime 核對 scope/expected node，再產生授權業務事件。

## 3. 單人入場契約（草案）

```json
{
  "contract": "single-player-scenario-admission",
  "version": "0.1.0",
  "classification": "SERVER_CANDIDATE_DESIGN",
  "progress_owner": {"kind": null, "id": null},
  "session_epoch": null,
  "quest_run_id": null,
  "flow_node_id": null,
  "scenario_definition_ref": null,
  "definition_sha256": null,
  "field_id": {"domain": "FieldId", "value": 19},
  "case_id": {"domain": "CaseId", "value": 103},
  "formation_correlation": {"domain": "FormationToken", "opaque_wire_value": null},
  "allowed_owned_roles": null,
  "capacity": null,
  "participant_scope": "single_account_story_instance",
  "unknowns": ["產品進度所有者需S00決策", "原版編隊容量及隊友跟隨未恢復"]
}
```

此 null 是刻意留空的設計欄位，不是執行時可用預設。現行可回歸 profile 另行列 `allowed_roles=[1,3,4]`、capacity=1、token raw19，並逐欄標 `SERVER_IMPLEMENTATION_FACT/CANDIDATE`。單人副本是同一使用者的故事實例，不代表原版只能出戰一人；多人 party 的邀請、成員、匹配、共享權限不放在本介面。不得因 Role4→Role1 切換便建立另一套 Quest 進度：現用 store 以 account 為根，正式 Account／Expedition／Role scope 待 S00 指定。

`ConfirmFormation` 至少核對已提供該次編隊、同一 session/epoch、原樣 token、所有權、角色能力支援、容量及對應內容版本；成功才建立 `instance_id` 與 `admission_record`。現有 Accepted milestone 必須沿用來源身分保留，不重命名冒充原生 Quest accept。C2S28 的 raw token 本身沒有 FieldId／QuestId 型別；19 恰等於 Field19 不是型別證明。

## 4. 可重用實例狀態與事件

候選狀態為 `AdmissionPending → FormationOffered → Admitted → NodeInitializing → NodeActive → NodeObjectiveSatisfied → ExitAvailable → NodeTransition/ResultAvailable → ReturnPending → Returned`。任務是否 `ObjectivesSatisfied/TurnInEligible/Settled` 由 Quest Runtime 的獨立規則決定。地圖圖形可分支、合流、可選節點或不同終點；沒有資料證明的 edge 留空，不把 scene 編號升序當 map graph。

| 事件／primitive | 前置及 input | effect | 等待／receipt | 提交點及未知 |
|---|---|---|---|---|
| `offer_single_player_formation` | 授權 flow node、owned roster、內容能力限制 | 提供型別化 formation view 與 opaque token | 預期 C2S28 profile | 待選擇一般為暫態；是否可恢復由策略指定 |
| `admit_instance` | 正確 formation confirmation、同 owner/session/內容版本 | 固定本次角色及 instance | map/controller ready profile 分開 | admission commit；不能記 Quest settled |
| `initialize_node` | admitted instance、合法 node/map/bounds/spawn profile | install context、reset、actor/NPC/monster、bind、activate、loading end | 已知 profile 的必要 receipt；送出不等人測 ready | 保存 node attempt/version；spawn／MEF未知與候選值分開 |
| `collect_objective_evidence` | 遭遇服務已授權 kill/clear/other objective | 提交有 scope 的 counter或objective proof | 可另等死亡演出收尾 | 數量/範圍/可重複鍵由內容指定；不以所有怪全死作所有任務模板 |
| `open_manual_portal` | 當前 node 的合法達成已保存 | 發出口、保留 combat context；清除舊queued intents一次 | 等站圈內按Z產生的portal intent | 不換圖／不顯示result；原版位置/key/radius不可從ID猜 |
| `use_portal` | current instance/node/key、仍存在的portal、owner與Server當前pose合格 | 執行內容edge；下一node或result | 相應轉場profile | 終止舊node資源、保持 instance 脈絡；不保存Quest完成 |
| `show_result` | 符合 instance terminal policy、結果證據保存 | 交 result presenter | 一般 Scenario C2S33/2B返回 profile | result 展示與獎勵交易獨立；22未解欄位要BLOCKED或明示candidate profile |
| `return_to_town` | 有效result return intent及目的地授權 | world service建立Town/Map/actor/NPC/control | 場景ready/receipt依profile | 到達授權不等Client已可動；需人工觀察 |
| `play_scene`／`await_scene_receipt` | 已核對scene雙鍵、owner和expected node、UI handoff符合 | 請求既有scene入口，保存可稽核pending receipt | (scene-domain key, scene key, expected producer class) | literal1不是成功保證；不得直接settle |

**清怪後仍可攻擊／施法、維持資源與冷卻，以及站上出口按 Z** 是明確使用者要求。現行實作已在候選碼中保留 `_combat`，直到真正換圖／結果才清理；資料化不能退回 v12 的全死立即換圖，也不能把清怪當退出戰鬥。與教學首戰返回分開。

## 5. 教學特例與 NPC／scene 生命週期

教學 `BeginFirstBattle` 保留原 CTutorial scene／Lua coroutine，走專屬 `05/type1 → C2S09 → map190`；結束後恢復保存的原圖位置，再走教學 `4C` local scenario-ended。一般副本走 `5F/type2`、kind3 controller、result22與return33。這是需要保留的 protocol/lifecycle hook，不能為共用而統一 opcode。

Quest15 的對話缺陷已有具體來源：v12 將 S2C40/status0 與47/15/2同批送出；有界原生檢查顯示40排F438B而建立接取對話，不是無窗ACK。v13候選移除該40，只有有效 NPC 意圖與 expected15/1 receipt 才47/15/2。**移除多餘對話是已實作修正，真Client無殘窗／重疊仍待測**。通用設計需要 `InteractionSession`（owner、NPC、menu/scene、expected receipt、presentation lifecycle），但現在不能捏造 `CloseDialogue` 封包。

建議 primitive `prepare_scene_handoff` 交給具名 adapter policy：明確確認哪些對話是本地結束、哪些有可用C2S事件、哪些不能證實關閉；未知使用 `BLOCKED_CLIENT_UI_LIFECYCLE`，不可固定 sleep 後宣告已關閉。`CloseUi` 可存在於抽象語彙，但每個 binding 必須有已知實作與證據，否則不得啟用。

Quest15 15/3、15/4 的演出與 `RestoreMap` 會影響 controller／actor binding。當前返回村落後，收到預期scene receipts與到達資格保存，再完整重建 map/player/NPC/checkpoint/control。資料化時保留這個 rebind hook；不要只記 `scene_done=true` 然後假定舊玩家仍可控。`DoProlog(1)`、`LoadMap`、`RevPhase1`不是 Quest settle 或 Town unlock 證明。

## 6. 現有保存契約如何保留

`SqlitePhindosJourneyStore.RecordStageAuthorizedAsync` 先核當前 lease/revision/role ownership，再核同一 connection 的 tutorial transfer與候選settlement、prerequisite14/16，沿 stage1→2→3→4 保存 journey及audit。資料字段為 account_id/session_id/connection_id/session_revision/role_index/stage/accepted_at/updated_at/rule_version；audit另有recorded_at。這個 store 可作現有路線 adapter，但不直接當一般 QuestProgress表。

通用提案至少分開 `QuestRun`、`ObjectiveProgress`、`FlowCheckpoint`、`InstanceRun/NodeOutcome`、`SettlementRecord`、`RewardEntitlement/Ledger`、`PublishedRevision/Outbox`。候選字段應包括 progress_owner、quest_id、definition_version/hash、run_id、state/revision、branch choices、objective counters與作用域、expected presentation receipt、instance reference、settlement_policy_version、reward raw tuples／mapped types／pending原因、debug_mode。只有合法結算授權才把 QuestRun 設為 settled；未知權威條件／reward映射／發布欄位不得猜值。

長期保存與短期網路 session 分開；原本 stage journal 的 connection-scoped proof 不可偷偷改成新帳號已完成，也不可因登出就刪任務。斷線後恢復哪個安全node、Lua coroutine能否續播、結果頁能否重發及重複結算處理，都列候選設計與待測；本輪不執行。

### debug 隔離的實際缺口

現有 `_debugProgressOverride` 確實繞過正常Phindos stage寫入，跳轉snapshot只是測試呈現，debug audit獨立。但 `PollWorldAsync` 在設flag前會呼叫 `PrepareStarterKitAuthorizedAsync(lease,4)`，該方法會對正常 `local_tutorial_progress`、`local_tutorial_equipment` 執行 `INSERT OR IGNORE`並commit；debug編隊確認也沿用它。已經有裝備的測試帳號可能看不到新增列，這不等於接口沒有寫入副作用。

**Server開發需求**：debug runtime使用既有kit的唯讀讀取或獨立fixture store；`execution_mode=TEST_PROGRESS_OVERRIDE`隨flow/instance/event一路傳遞，所有正常進度、grant、reward、unlock、equipment write入口統一阻擋。原有正常紀錄不得退回／快進。此為程式靜態發現，未觸發或測試DB，不宣稱歷史人測已造成資料污染。

## 7. 採用順序

1. 先保存現有教學與Quest15候選profile及精確版本，將16筆分支對照作入口清單；既有packet codec不改其效果。
2. 先抽 typed IDs、definition loader、graph resolver、event envelopes與persistent interfaces；在現有 handler 外包一層，保持正常路線偏序。
3. 第一個切換點選 Quest15 scene1→scene2 的 presentation gate 或單圖 clear→portal，逐一以同一正常流程人工核對。沒有UI life-cycle binding的節點維持明確阻塞。
4. 再資料化 formation與instance接口、兩圖graph、result/return與world rebind，保留TUTO特例、current candidate rule版本與未恢復欄位。
5. 以原表確認的一個對話型後續任務與一個多scene/副本型後續任務做**結構驗證**；不把static graph可載入說成已可遊玩。Quest117/119的合法結算與reward未閉合時仍BLOCKED。
6. 只有新資料路徑的正流程通過才逐一停用對應專用分支；不一次重寫已通的全鏈。自訂JSON是 Server候選definition，不能稱原生MEF。

## 8. 來源入口

- [現用單人橋接程式說明](https://github.com/we88ec3-prog/ttr_server_roy/blob/f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e/docs/LOCAL-PHINDOS-SINGLE-PLAYER-BRIDGE.md)
- [現用connection實作](https://github.com/we88ec3-prog/ttr_server_roy/blob/f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e/src/Tartaros.Network/LocalTutorialWorldConnection.cs)
- [全新帳號人工／保存證據](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261102-FRESH-TUTORIAL-HUMAN-PASS.md)
- [v12進村有缺陷的人工結果](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-PHINDOS-V12-HUMAN-RESULT.md)
- [v13 NPC/portal修正邊界](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-PHINDOS-V13-CORRECTIONS.md)
- [MEF獨立格式與遷移規劃](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-MEF-IMPLEMENTATION-AND-MIGRATION-PLAN.md)

原Task T09 README是「關卡內移動與同步」，不因工作卡簡稱副本而改其owner／任務定義；副本controller/result介面實際引用T07／T16及W2的精確來源。
