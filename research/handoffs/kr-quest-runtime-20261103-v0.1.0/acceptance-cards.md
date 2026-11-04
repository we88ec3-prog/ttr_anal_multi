# 任務 Runtime 正流程驗收卡與既有保存證據

版本：`0.1.0`。分類：**歷史證據盤點 + SERVER_CANDIDATE_DESIGN 驗收計畫**。

**本文件所有新卡的 `execution_status` 都是 `NOT_RUN`。** 本批沒有啟動或附加 Client、啟動或更換 Server、查詢或修改玩家 DB、執行遊戲正流程或debug，也沒有執行重送、斷線、重登、併發、故障或壓測。`BLOCKED` 表示尚缺開跑所需的合法規則、資料或adapter；它與「未跑」分開記錄。歷史人工回報和合成測試只保留原版本、原範圍。

配套資料：[任務 Runtime 設計](quest-runtime-design.md)、[遷移矩陣](migration-matrix.csv)、[例外表](exceptions.csv)、[遷移來源與SHA](evidence/migration-source-provenance.json)。各卡的 `Mxx` 指向遷移矩陣，`EXxx` 指向例外表；精確原檔、函式locator、Git blob SHA及內容SHA256由來源manifest保留。

## 1. 判定與收據格式

本包分開四類依據：原始Client表／腳本／有界consumer證據、使用者指定行為、現有Server候選實作、待開發Server設計。人工看到scene播放、Client送出receipt、Server成功送包、候選milestone保存、合法Quest結算是不同觀察，不互相代替。

未來每張卡至少記錄：runtime commit、definition／flow版本和SHA、Client SHA、正常進度起點、`execution_mode=NORMAL`、起止node、觀察時間與結果、去敏保存收據及來源。保存收據需要能區分同一進度所有者、同一正常run與相應session epoch，但對外交付不展示帳密或原始account/session值。

通用Runtime的 `quest_run`、`objective_counters`、`instance_id`、`settlement_key`、`reward_ledger`、`publication_outbox` 等是本包的**候選業務欄位**，不是宣稱現有DB已全部具備。原有SQL欄位另以完整表名標示。沒有規則的欄位保持空值與BLOCKED，不用假預設填滿。

## 2. 歷史已通範圍：版本、缺陷與保存界線

### H01：fresh帳號教學到廣場

判定：`HISTORICAL_WORKING_COPY_HUMAN_REPORT_WITH_SAVED_SNAPSHOT`。

| 項目 | 已保存證據與限制 |
|---|---|
| Server版本 | `cd2a7bc70f3cfb92602628137bf65c5df81b0eb2` |
| Client版本 | 工作副本SHA256 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`；不是原始KR BIN相容性驗收 |
| 人工回報 | 完成教學，到廣場且能移動停止 |
| 之前快照 | fresh account、無profile／name／roles／equipment、首戰尚未保存 |
| 之後快照 | profile revision4；roles `[1,2,3,4]`；tutorial revision3；first battle win已保存；role4／slot1／item28 |
| 需保留解釋 | session rows與character rows均為0；來源說明snapshot前已EOF、character為另一模型。不是目前在線readiness，也不表示流程未登入 |
| 當時缺口 | `transfer_component_present=false`；沒有後來的transfer／prerequisite元件。Quest14／16原版合法結算、已付獎勵、完整終端保存、loading可見及原生AI／MEF仍未由此證明 |

來源：[FRESH-TUTORIAL-HUMAN-PASS.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261102-FRESH-TUTORIAL-HUMAN-PASS.md)，Git blob `e3a7d6b07ea30fca3bf992c822239ae095046c43`；[去敏before/after](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/evidence/S00-20261102-FRESH-TUTORIAL-HUMAN-PASS.json)，Git blob `e70a07e07179cfd968fe34079847a8eaf05e23c5`。

### H02：v12正常到馮德斯，有三個未解缺陷

判定：`HISTORICAL_ARRIVAL_AND_LOADING_OBSERVED_WITH_THREE_OPEN_DEFECTS`。

| 項目 | 已保存證據與限制 |
|---|---|
| Server版本 | `f1261c82d76b43918a8c268ed607a898d7341af6`；Client同H01工作副本 |
| 人工回報 | 到馮德斯；人物／NPC正常；移動停止正常；loading可見有接受記錄 |
| 保存摘要 | stage4／role4；有序audit stages `[1,2,3,4]`／role4；規則 `PHINDOS_BRIDGE_CANDIDATE_V1` |
| 脈絡核對 | `same_connection_tutorial_proof_count=1`；prerequisite keys `[14,16]` |
| 獎勵狀態 | Quest16 raw `(type=2,value=50)` 為 `PENDING_NATIVE_PUBLICATION` |
| 三個缺陷 | NPC對話與scene2重疊；清怪後自動換場；前進後連按Z仍殘留移動 |
| 未證明 | Quest15合法完成、Quest15付獎、Quest117合法解鎖／通關、整村主線完成、原始KR BIN相容性 |

來源：[PHINDOS-V12-HUMAN-RESULT.md](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-PHINDOS-V12-HUMAN-RESULT.md)，Git blob `768fe53494aec176864ac59c8b5039d4b45192e7`；[PHINDOS-HUMAN-PASS.json](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/evidence/S00-20261103-PHINDOS-HUMAN-PASS.json)，Git blob `269ff2f51a02b91b1fb296f32eb4ba57928c0780`。檔名含PASS不會消除其open_defects。

### H03：後續修正與現碼不繼承完整人測通過

v13移除15/1→15/2之間多餘的S2C40；有界Client來源顯示40/status0會建立接取對話，不能當silent ACK。v14記錄使用者要求「站上出口按Z」及「清怪後保留戰鬥」，並有27項合成正常案例結果；該來源仍明示NPC重疊未單獨確認、完整到村未重驗，實機PENDING。v15的debug／輸入文件保留合成結果，實際頁面／Client切場也未由該文件證實。來源：[v13](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-PHINDOS-V13-CORRECTIONS.md)，blob `4738f3defcafe20dfebbb82db56df739ae14bc0a`；[v14](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-PHINDOS-V14-CORRECTIONS.md)，blob `c0e1ad91e77d4f8e9b8e3e235a1bf0c4e73ccbff`；[debug／輸入後續](https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-INPUT-PIPELINE-AND-PROGRESS-DEBUG.md)，blob `59b1c68e389b6ba52e49d833e8a3181019ef64af`。

本批唯讀現有Server分支的pin是 `f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e`。讀到程式不證明該版正在玩家機器執行，也不證明抽取後的新Runtime可玩。v14非戰鬥Z強制停步／方向鎖的歷史政策不採為任務primitive；輸入修正另有工作包，任務層只規定合法意圖與生命週期。

以上是重讀已有去敏快照，不是本批直接讀玩家DB。分析main基準為 `83959c0e7e65ab01348b285f03c285f487077610`；補充分析來源pin為 `76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac`，不能說補充來源已公開合入main／已認領RR。原始KR BIN SHA256為 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 3. 教學正流程卡

### TUT-01：正常入口與角色準備

`execution_status=NOT_RUN`；`readiness=EXISTING_CANDIDATE_PATH_REQUIRES_MIGRATION_VALIDATION`。來源：H01；M01、M02、M05；EX01、EX02。

1. 從已證明fresh的正常帳號登入、命名，沿原教學入口開始，記錄起點與內容版本。
2. 依原故事進行對話、角色準備及編隊入口，不套用debug或預填完成資料。
3. 核對指定角色出現、對話可正常結束、畫面控制與原教學一致。

需比對的保存欄位：既有 `local_expedition_profiles.revision`、`local_expedition_roles.role_index`、`local_tutorial_progress.revision`，以及實際用到的 `local_tutorial_equipment.role_index/slot/item_id/serial`。H01的roles與revision是舊版快照結果，不應硬設為新版每一步的必然數值。角色4／2的固定grant屬現有教學候選政策，不當通用Quest獎勵規則。

### TUT-02：首戰專屬controller與返回

`execution_status=NOT_RUN`；`readiness=EXISTING_CANDIDATE_PATH_REQUIRES_MIGRATION_VALIDATION`。來源：M03、M04；EX01；H01。

1. 由正常教學提供編隊，選已擁有且該版本支援的角色，確認首戰。
2. 保留教學 `05/type1 → C2S09 → Map190` 與CTutorial coroutine，完成候選首戰。
3. 首戰結果保存後返回原圖／原位置，走教學專用4C結束通知，繼續原故事。

Client可觀察結果：戰鬥能開始，首戰結束能返回並續接教學，沒有多餘一般Scenario結果頁或失去控制。保存核對：`local_tutorial_progress.first_battle_completed_at/revision`及選定角色裝備；快照的 `first_battle_win_saved` 是觀察欄位，不是另一個SQL欄名。通用候選可記 `tutorial_first_battle` 與證據ref，但不能因此寫Quest14／16 `SETTLED`。不得以一般 `5F/type2 + result22`取代此hook。

### TUT-03：退出演出、廣場初始化與候選前置

`execution_status=NOT_RUN`；`readiness=EXISTING_CANDIDATE_PATH_REQUIRES_MIGRATION_VALIDATION`。來源：M05–M07；H01、H02；EX03。

1. 沿正常已授權教學路線完成scene-domain1000之10、12、13、14的演出與回報，不直接發fixture receipt。
2. 依現有候選規則保存廣場轉移資格，再建立廣場世界與控制。
3. 觀察玩家／NPC正常、可移動停止、教學UI已釋放；loading可見另行記錄。

保存核對：`local_tutorial_transfers`的 `account_id/session_id/connection_id/session_revision/authorized_at/rule_version`；`local_quest_prerequisite_state.revision`；`local_quest_prerequisites.quest_key`；`local_tutorial_quest_settlements.completed_at/rule_version`；`local_tutorial_reward_entitlements.quest_key/resource_type/resource_value/state`。新引擎不得把「封包已排送」記成Client已ready。ordered scene receipt只證presentation進度，load-failure producer可能回報相同值。

### TUT-04：教學合法結算的獨立門檻

`execution_status=NOT_RUN`；`readiness=BLOCKED`。來源：M07、M16；EX02、EX03、EX08；[教學flow](examples/tutorial.current-candidate.flow.json)。

只有S00明示Quest14／16合法目標、交付、獎勵與scope策略後，才可按正常Client流程驗收接取→目標達成→交付→提交→發布。需比對候選 `quest_run/accepted_at/content_version`、`objective_counters/objective_evidence_refs`、`quest_state/settlement_key/reward_ledger/completed_prerequisites/publication_outbox`。現有候選前置keys14/16及pending entitlement繼續保留其規則版本；不得因表名含settlements便追認為原版合法結算或已付獎勵。

## 4. Quest15橋接正流程卡

### Q15-01：NPC10338對話到下一段scene

`execution_status=NOT_RUN`；`readiness=BLOCKED_CLIENT_UI_LIFECYCLE_FOR_NEW_GENERIC_BINDING`。來源：M08；EX04；H02、H03；[Quest15 flow](examples/q15.candidate.flow.json)。既有候選路徑可保留，通用關窗binding欠證時不得啟用。

1. 從正常教學／廣場路線抵達NPC10338；使用正常互動，記錄NPC、owner、當前controller與expected node。
2. 等待正確的15/1回報及合法NPC意圖，由具名adapter完成對話釋放後才開始15/2。
3. 完成scene後核對演出窗口、NPC對話和玩家控制的生命週期。

Client可觀察結果：沒有原NPC對話與下一段scene同時殘留、沒有重疊窗口、下一段只在合法操作後出現。需比對：interaction session、expected `(quest=15,scene=1/2)`、scene epoch、flow revision與cleanup evidence；這些是新Runtime候選欄位，未證現碼已持久化。若3F值1出現，只記receipt，不寫達成。S2C40/status0會開對話；沒有來源的 `CloseUi` 封包或固定sleep不算關窗證據。

### Q15-02：單人編隊與入場保存

`execution_status=NOT_RUN`；`readiness=EXISTING_CANDIDATE_MAPPING_WITH_NEW_ADMISSION_POLICY_BLOCKED`。來源：M09、M10；EX05；[Scenario入口](examples/quest15.scenario.json)。

1. 正常完成15/2的presentation handoff，顯示單人編隊；選已有且支援的角色並確認。
2. Server核對本次offer、opaque formation token、角色所有權、session與能力限制，再建立instance。
3. 入場提交完成後初始化Map191；觀察loading、角色、怪物及控制可用。

現行candidate capacity1／角色1、3、4是能力限制，不能推成原版單人編隊上限。`QuestId15`、`FieldId19`、`CaseId103`、`MapId191`與raw token19需分型核對；token數值相同不提供Field型別。

保存核對：既有 `local_phindos_journeys`的 `account_id/session_id/connection_id/session_revision/role_index/stage/accepted_at/updated_at/rule_version`及stage audit；stage1 **Accepted是副本入場**。新候選 `instance_id/formation_snapshot/admission_key`應與正常run關聯；stage1不可匯成Quest15通用接取enum。Quest接取政策仍獨立BLOCKED。

### Q15-03：Map191達成、保留戰鬥與手動portal

`execution_status=NOT_RUN`；`readiness=EXISTING_CANDIDATE_MAPPING_REQUIRES_HUMAN_VALIDATION`。來源：M10–M12；H03；[Scenario入口](examples/quest15.scenario.json)。

1. 正常進入Map191，依明示的現有候選遭遇規則戰鬥到node達成，等待死亡演出收尾。
2. 開出口後留在該圖，使用新的普攻／技能對空處動作，再正常移動到出口。
3. **站上portal後按Z**，才依已授權edge進入Map192。

Client可觀察結果：清怪後仍在戰鬥，新的攻擊／施法可用且資源／冷卻持續；未按Z不因清怪或站圈自動換場。保存核對：stage2／role／audit記錄、`encounter_outcome_ref`與本次node scope；出口使用核對current instance/node/key及Server pose。清怪後不重生怪、不重複提交勝利；這是正常流程的結果觀察，本批不做重送測試。Chart的node1→2只是資料邊，觸發條件由明示候選策略提供，不能說原生MEF已恢復。

### Q15-04：Map192手動出口、結果頁與返回意圖

`execution_status=NOT_RUN`；`readiness=EXISTING_CANDIDATE_MAPPING_WITH_RESULT_FIELDS_PARTIAL`。來源：M11–M13；H02、H03。

1. 依正常路線進Map192、完成候選遭遇、繼續保留戰鬥，再站上出口按Z。
2. 觀察一般Scenario結果頁；依正常UI選擇返回。
3. 僅在對應result controller與狀態消費C2S33，開始返回目的地。

Client可觀察結果：先出現結果再正常返回，loading可辨識；零化候選統計不冒稱原版獎勵／統計已恢復。保存核對：stage3及audit；instance outcome／result presentation／return intent獨立記錄；Scene或其他controller的相同opcode不得錯用。結果頁呈現不能授權Quest15完成或獎勵。

### Q15-05：返回Town1、scene15/3與15/4、世界重建

`execution_status=NOT_RUN`；`readiness=NEW_GENERIC_CLEANUP_BINDING_BLOCKED`。來源：M14；EX07；H02；[Quest15 flow](examples/q15.candidate.flow.json)。

1. 從Q15-04正常返回Town1／Map182，依合法expected node播放15/3及15/4。
2. 核對scene cleanup、到達資格提交與完整world rebind的偏序。
3. 觀察演出後玩家／NPC顯示完整、可移動停止、沒有殘UI或失去控制。

保存核對：`local_phindos_journeys.stage=4`、role／session revision／rule version與stage audit；候選 `journey_stage/evidence_refs`、world-ready observation分開。**現碼偏序是先成功保存ArrivalAuthorized，再由CommitPhindosStage重建world；重建完成才可另記Client可動觀察。** 新flow若改此偏序須明示遷移決策，不能冒稱原路徑完全相同。stage4既不是Client readiness，也不是Quest15 completed。

### Q15-06：合法結算、獎勵與Quest117可接

`execution_status=NOT_RUN`；`readiness=BLOCKED`。來源：M16；EX08；[Quest15定義](examples/quest15.definition.json)、[目標](quest-objectives.csv)、[獎勵](quest-rewards.csv)。

解除門檻：合法objective predicate與scope、接取／finisher／交付操作對應、reward plan／歸屬／交易與Client publication adapter均有明確來源或核准Server策略。原表沒有reward項也不能默認零獎勵。

解除後才按正常步驟驗收：合法目標證據→交付意圖→單一結算提交→Client發布→逐一重算Quest117資格。需比對 `quest_run`、`objective_counters/objective_evidence_refs`、`quest_state/settlement_key/reward_ledger/completed_prerequisites/publication_outbox`及可接projection revision。只播完15/1..4、到Town1或記stage4，都不能通過本卡。

## 5. Quest117：單scene城鎮內容樣本

結構來源：[Quest117定義](examples/quest117.definition.json)、[flow](examples/q117.candidate.flow.json)、[scene關聯](quest-scenes.csv)。QuestInfo member SHA256為 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`；SceneList member SHA256為 `1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037`。原表為Town1、Demand15、giver／finisher NPC10002、level raw1；Chapter1僅117/1，沒有Field屬性或結構化Contents目標。這是靜態差異，不能自行定義「看完117/1即完成」。

### Q117-01：正常可接、NPC窗口與單scene handoff

`execution_status=NOT_RUN`；`readiness=BLOCKED`。來源：上述原表及flow；M16、EX04、EX08。

1. 先有Quest15合法settled證據，由此任務自身的eligibility／NPC visibility／角色與level策略判斷可接；不能從舊stage4或測試快進取得資格。
2. 與NPC10002正常互動，依已確認UI mode接取；完成對話釋放後才由合法scene cue播放117/1。
3. 核對NPC窗口、scene與世界控制先後；以相同通用Runtime載入資料，不新增Quest117專用if。

可觀察結果：任務提供者、文字／scene及控制一致，沒有殘對話。保存核對：候選 `quest_run/accepted_at/content_version`、scope／definition hash、interaction session、expected117/1與cleanup evidence。`policy.acceptance_rule`、NPC可見性及各UI binding缺失時不啟用；單一scene索引可解析不是正常通關。

### Q117-02：合法目標、交付與reward發布

`execution_status=NOT_RUN`；`readiness=BLOCKED_LEGAL_OBJECTIVE_AND_REWARD`。來源：[Quest117定義](examples/quest117.definition.json)、[目標](quest-objectives.csv)、[獎勵](quest-rewards.csv)、M16／EX08。

解除門檻：補上目標型別／數量／作用域及合法事件、finisher交付綁定、reward歸屬／grant／publication plan。原表raw reward `type2/value710`及有界Client `kQuestRewardPartyExp`顯示域可以比對，不能自行推定Server加值／倍率／收件者。

解除後正常完成目標、交付NPC10002、提交結算、發布後重算Quest118資格。Client任務狀態與獎勵須對應已提交的 `objective_counters/objective_evidence_refs`、`quest_state/settlement_key/reward_ledger/completed_prerequisites/publication_outbox`。`SceneReported`不得直接連到settled；現有scene全播放仍不能讓本卡通過。

## 6. Quest119：多scene、Scenario事件樣本

結構來源：[Quest119定義](examples/quest119.definition.json)、[flow](examples/q119.candidate.flow.json)、[Scenario入口](examples/quest119.scenario.json)。與Quest117同一QuestInfo／SceneList來源SHA。原表為Town1、Demand118、Field26、NPC10047、level raw5；Chapter1有119/1..5，腳本分別含Blank、Stage、Boss、BossClear、After標記。Field26與Case107的join只是靜態候選關聯；本包Case107 `map_graph=null`，不得用scene的fld名稱或序號猜出圖與觸發順序。

### Q119-01：正常入場與Scenario服務邊界

`execution_status=NOT_RUN`；`readiness=BLOCKED_SCENARIO_POLICY_AND_MAP_GRAPH`。來源：上述定義／Scenario入口；M09–M13作共用候選，EX05、EX06、EX08。

1. 先有Quest118合法settled證據，按Quest119自身scope、NPC與level策略正常互動與接取。
2. 釋放NPC窗口，按獨立已核准的編隊政策提供與確認隊員；不能把Quest15 raw token19或capacity1自動套用。
3. Quest Runtime只呼叫Scenario服務，由其依版本化admission、map graph與Encounter策略建立實例。

可觀察結果：正常編隊／loading／地圖與可控角色成立。保存核對：`quest_run/accepted_at/content_version`與instance admission、formation snapshot、scope、map graph版本。由於Case107圖、出口geometry、完整遭遇完成及入場策略尚未閉合，卡片保持BLOCKED，不填出生點／怪數／邊或接受所有預設。

### Q119-02：事件分派各scene、清怪／result／return分離

`execution_status=NOT_RUN`；`readiness=BLOCKED_EVENT_SCHEDULE_AND_OBJECTIVE_RULES`。來源：[事件式flow](examples/q119.candidate.flow.json)、[scene關聯](quest-scenes.csv)、EX03、EX04、EX06。

1. Scenario服務只有在已授權的事件條件達成時才送對應 `SceneCueAuthorized`；各scene的guard須明確選中119/1..5之一。
2. 每個scene等待自身receipt與cleanup，再回到事件等待，不按sceneIdx升序自動觸發下一個。
3. 只有合法 `EncounterOutcomeCommitted`才進result流程；按正常返回操作、恢復世界後才產生有scope的返回授權。

可觀察結果：演出與地圖／遭遇事件相符；BossClear演出不自動結算；result頁、手動出口與返回事件各有合法前置。保存核對：instance／node／outcome ref、expected node與scene epoch、cleanup evidence、return authorization；新內容不自行繞過Scenario／Encounter服務計數。合法排程、完成predicate與Case107 graph缺失，所以這不是現在可執行的整串片段播放測試。

### Q119-03：合法結算與下一可接任務

`execution_status=NOT_RUN`；`readiness=BLOCKED_LEGAL_OBJECTIVE_AND_REWARD`。來源：[Quest119定義](examples/quest119.definition.json)、[獎勵](quest-rewards.csv)、M16／EX08。

原表reward tuples為 `(type2,value5850)`、`(type3,value40)`、`(type4,value900)`。已恢復的parser／顯示域與Server付獎分開；type3不能猜成幣種，type2／type4顯示label也不能補倍率、歸屬或發送包。

解除合法目標、finisher交付、scope及reward plan門檻後，才從正常Scenario返回完成實際交付並核對提交／發布。需比對 `objective_counters/objective_evidence_refs`、`quest_state/settlement_key/reward_ledger/completed_prerequisites/publication_outbox`；Quest120由自己的資格策略重新判斷，不按ID加一發布。五段scene全播完、instance結果頁出現或回到Town1，都不能單獨通過本卡。

## 7. 逐項遷移驗收與保存含義

### MIG-01：切換一個primitive後沿正常路線核對

`execution_status=NOT_RUN`；`readiness=REQUIRES_S00_ADOPTION_AND_APPLICABLE_BLOCKERS_CLEARED`。來源：[遷移矩陣](migration-matrix.csv)、[例外表](exceptions.csv)、[Runtime設計](quest-runtime-design.md)。

依矩陣一次選一個可抽取切點，保留既有候選profile和版本，走對應教學／Quest15卡；確認Client可見效果、提交點與正常保存等價後才停用對應舊分支。先抽presentation gate或單圖clear→portal，再逐段處理formation、instance、result/return及world rebind，不一次重寫整條已通路徑。Quest117與Quest119只在各自blocker解除後驗證共用性；目前已確認的是靜態結構差異。

| 觀察／保存欄位 | 允許含義 | 不可提升為 |
|---|---|---|
| 教學首戰保存 | 現有候選首戰結果 | Quest14／16原版合法結算 |
| prerequisite keys14/16 | 現有候選規則下的前置snapshot | 獎勵已支付／原版交付已恢復 |
| stage1 Accepted | 副本編隊確認後入場milestone | 通用Quest15已接權威enum |
| stage2／3 | 候選兩圖遭遇勝利milestone | 原生MEF完整規則／所有任務皆清怪 |
| stage4 ArrivalAuthorized | 到村資格 | Client已ready／Quest15 completed／Quest117可接 |
| PENDING_NATIVE_PUBLICATION | 保留raw reward entitlement | 已授予EXP／幣／道具／角色 |
| scene receipt值1 | 特定context下的presentation回報 | 播放必然成功／目標達成／合法結算 |

## 8. debug不回寫正常紀錄：開發門檻

`execution_status=NOT_RUN`；`readiness=BLOCKED_IMPLEMENTATION_GAP`。此節是開發門檻，debug不能替代上述任何正常通關卡。來源：M15、EX09；[遷移來源](evidence/migration-source-provenance.json)。

現碼 `_debugProgressOverride` 確實跳過正常Phindos stage保存，但 `LocalExpeditionConnection.PollWorldAsync` 在設override前呼叫 `PrepareStarterKitAuthorizedAsync(lease,4)`；debug編隊亦沿用它。`SqliteTutorialStateStore`的此方法對正常 `local_tutorial_progress`、`local_tutorial_equipment`有 `INSERT OR IGNORE`並commit。相應Server blob為 `af60eb3cf7b74e9f500a906a9e12556fcc72f344`、`995fc114e4181cccec8b652839e7513a59bb91cb`，commit `f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e`。這是靜態呼叫／寫入路徑證據；沒有查DB，不能宣稱歷史玩家資料已受污染。

S00採用前須具體做到：

1. debug kit改用唯讀既有資料或獨立fixture store；不能以帳號通常已有裝備來取代零寫入契約。
2. `execution_mode=TEST_PROGRESS_OVERRIDE`在flow、instance、event與所有正常write入口一致傳遞；接取、目標、場景進度、角色／裝備、instance outcome、結算、獎勵、unlock均不得回寫正常紀錄。
3. 快進／退回僅變更測試呈現與獨立debug audit；保留正常progress revision與歷史audit，不覆寫、回退或補完成key。
4. 未來隔離驗證需核對所有相關正常表，而不只核對stage1..4。歷史debug合成結果只證當時覆蓋的stage／lease／role欄位，不能擴張為所有表零寫入。

本批不實作、不啟用、不操作debug，也不執行隔離測試。

## 9. 延後待測清單：只列契約，現在不執行

| 待測項 | 未來要驗證的候選契約 | 本批狀態 |
|---|---|---|
| 重複accept／receipt／objective | stable operation key、owner／scope、revision與來源去重；receipt不轉為award | `DEFERRED_NOT_RUN` |
| 重複結算／發布 | 單一settlement ledger；重發布已提交projection與新授獎分開 | `DEFERRED_NOT_RUN` |
| scene途中斷線／重登 | expected node與安全恢復點；不得假定Lua coroutine能持久化 | `DEFERRED_NOT_RUN; resume_policy未知` |
| instance途中／結果頁斷線 | 分離持久outcome、暫態combat與Client世界；恢復地點／圖狀態待策略 | `DEFERRED_NOT_RUN` |
| reward commit後、publication前中斷 | 已提交ledger與未確認Client顯示分開；不重複付獎 | `DEFERRED_NOT_RUN` |
| debug正常寫入隔離 | 包含kit／角色／裝備／objective／reward／unlock的完整write入口 | `BLOCKED_IMPLEMENTATION_GAP; NOT_RUN` |
| 多連線、角色切換與併發 | owner/account/expedition scope正式決策與session fencing；Tab換角色不隱式另建進度 | `DEFERRED_NOT_RUN` |
| 故障、超時、安全營運、壓測 | 另排範圍與驗收，維持既有歷史結果及限制 | `DEFERRED_BY_USER` |

這些是候選Server設計與待測清單，不是原Server規則還原，也不是測試已通。歷史已跑結果維持原範圍；本包未新增執行。只有合法目標、交付、獎勵、提交與Client可見結果都分別有證據，才可談某個Quest正常完成；播放完整scene清單不足以宣告整村主線完成。
