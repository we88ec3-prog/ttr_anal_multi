# S00 Iteration 18 — 新手教學 Scenario 14：怪物生成、AI、玩家攻擊與技能施放整合規劃

> **獨立草案 / 未提交 Git / 非正式 SPEC、REQ、RR、GAP、TEST。** 2026-10-30（Asia/Taipei）。核對 `we88ec3-prog/ttr_anal_multi` main `833f3b8a6a290fffe5eab8b047f93d58c36c3ac9`；延伸 `governance/s00-iterations/S00-20261030-ITERATION-17-TUTORIAL-COMPLETION-PLAN.md`，只細化 E14、E16、E17、E18、E20，不更改 E00–E26 原編號，也不要求原版 Client runtime。
>
> 原生研究版本：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（採既有 S00 記錄，這次未重驗二進位）。不自動套用 TC，不把原版 Client 可解碼形狀等同原 Server 權威。

## 0. 結論與交付終點

**已有高階規劃，尚無完整的 Scenario 14 怪物生成／AI／角色技能施放 Server 契約。** Iteration 17 E17 只要求「合法實體、敵人、目標、勝負」，未完整落實 spawn schedule、移動和 AI 來源、技能 C2S→結果、命中／傷害／死亡與回合完結的跨系統可驗證時序。

Iteration 18 目標是把 **E17「可玩戰鬥」**分成明確的規格研究/驗收子閘門：角色在教學可操控，合法敵人出現並可辨識，怪物可進行符合來源或明示替代的移動/攻擊，玩家可執行教程要求的普通攻擊與技能；Server/Client 狀態同步，合法勝利才走 E18→E20 QuestInfo14。**不把 UI 特效、合成假傷害、顯示清怪視為勝利證明。**

## 1. 目前研究事實（依 main 已有 Task README 與 Iteration 17，非本次新 BIN 複驗）

| 範圍 | 有界已知 | 不可推導的結論 | 主責 |
|---|---|---|---|
| 怪物生成 | T08 記錄 S2C 0007 有前置 2 bytes 與每列 26 bytes；type1 建 CMonster；S2C000A 有 owner/actor 相關欄位的部分觀察 | 不能推論 Scenario14 怪物種類、spawn 點/波次、生命值、何時觸發或由誰控制 | T08、T07 |
| 位置／動作 | T09 有共用 actor 移動／位置旗標研究 | 不能推論怪物決策、碰撞完整公式、哪一方主導同步 | T09 |
| NPC／怪物行動 | T13 研究非玩家實體行動的來源、SubAI 和控制權線索 | 本機追擊／回家／攻擊自製 AI 不能視為原生；Client 本地、P2P 或 Server 權威邊界未定 | **T13** |
| 角色普通攻擊 | T10 範圍為輸入、連段、取消；本機 0.65 秒連段為替代 | 原版可連段時間、取消窗口、事件與 wire 不完整 | T10 |
| 技能 | T11 主責技能計時／消費／消耗／施放裁決 | 讀到技能資源矩陣≠原生技能授權；冷卻、消耗和技能結果不能猜 | **T11** |
| 傷害與死亡 | T12 記錄 S2C000E 的 13-byte 戰鬥結果 row，S2C000B 移動 row 8 bytes | 結果接收≠原版傷害計算；本機 45/65 範圍、20/35/60 傷害及 0.2 秒延遲不可引用為原生 | T12 |
| 勝敗結算 | T14 的教學 0.75 秒清怪後完成和預標完成是本機策略 | Scenario14 成功政策、合法結算、Quest14交付仍未有閉合正向證據 | T14、T16 |

**證據等級採用四層**：`NATIVE_STATIC_BOUND`（明確 Client BIN producer/consumer、來源 SHA、方向及前提）、`RESOURCE_ONLY`（Lua/XML/配置，未閉合 wire）、`SERVER_POLICY_PROPOSED`（我們自訂後端），`FIXTURE_ONLY`（測試替代）。只有相符來源的證據或已核准 ADR 才能變更規格條款。原生 Server 封包與權威來源仍為未決議事項。

## 2. E17 分解閘門（E17-A～J；不是新的正式 E 編號）

| 子閘門 | 為什麼必須存在 | 必填研究/設計成果 | 來源主責 | 當前狀態 |
|---|---|---|---|---|
| **E17-A 進場與 encounter 識別** | 避免把 Scenario selector 14 直接當 stage/map/quest ID | Scene / instance / encounter、進場就緒、角色權威、開始事件及必要素材映射，標示每個 namespace | T07、T16、T04 | 未閉合 |
| **E17-B 敵人出生** | 確保實際存在可操作、可命中的怪物 | 原生類型/actor id、初始位置/朝向/能力來源、出生時機/波次/通知/可見性、唯一實體鍵、撤銷流程 | T08、T07、T04 | 僅一般 spawn 接收有限證據 |
| **E17-C 控制權／AI 決策** | 避免伺服器自製 AI 與原 Client 預期衝突 | 哪一方選目標、路徑、追擊、回位、招式；P2P/Server/Client 權威的正向證據；優先與冷卻；死後停止 | **T13**、T02、T09、T11 | 來源與權威缺口 |
| **E17-D 怪物移動同步** | 避免怪物停住、瞬移、卡住或失去對象 | 移動命令方向/欄位、碰撞/校正、owner 範圍、重排/斷線/scene 切換、停止及去重 | T09、T13、T02 | 局部研究 |
| **E17-E 玩家普通攻擊** | 保證教程戰鬥能有合法起手及連段 | C2S 或本地輸入來源、普通攻擊／連段／取消合法事件、actor state 轉換、拒絕分支 | T10、T02、T04 | 時間窗口待證 |
| **E17-F 玩家技能施放** | 避免只有 UI 動畫而無技能效果或被永久拒絕 | 技能入口、角色初始可用技能、ID/等級、輸入與目標座標、前置條件、資源消耗、冷卻、起手/完成/中斷、結果通知 | **T11**、T10、T04、T02 | 施放與業務裁決未閉合 |
| **E17-G 命中、傷害、死亡** | 避免 client-only 血量、負血、重複死亡 | 命中資料來源、傷害/HP/異常、命中事件、實體死亡與移除、戰鬥結果呈現；不臆造公式 | T12、T08、T10、T11 | 消費端有限證據 |
| **E17-H 目標與波次推進** | 防止全滅後錯誤通關或無限等待 | 教學實際勝負/目標條件，是否有波次、觸發/計數規則；失敗/重試/離場的處理 | T14、T07、T08、T16 | 完整原生規則未知 |
| **E17-I 結算／Lua 解除等待** | 確保 Scenario 14 真正結束且進度各層一致 | 關卡結果狀態、S2C 與 CTutorial 0x004C map reader 的合法順序、下游 QuestInfo14 獨立完成 | T14、T16、T02、T07 | 0x40/0x4C 局部 Client 可見，未證官方交握 |
| **E17-J 例外／重連與防重** | 防止重刷獎勵與跨角色結果污染 | 重複 spawn/輸入、CD、重放、scene 不對、死亡、斷線、重連、同 key ownership、結算冪等 | T15、T02、T07、T14 | Server ADR 待核准 |

**依賴順序**：`E16 Scenario14 local request` → `E17-A scene/authority` → `E17-B spawn` → (`E17-C AI` + `E17-D motion` + `E17-E normal attack` + `E17-F skill`) → `E17-G combat results` → `E17-H valid objective` → `E17-I result & Lua` → `E20 Quest14`。E17-J 跨所有步驟。事件因果鏈是驗收需要的邏輯先後，**不是已證官方 wire 的真實送達順序**。

## 3. 提案的 Server 模組契約（全部非原版已證行為）

建議抽出可在 MockClient 驗證的介面，暫不綁死網路 opcode：

```text
TutorialEncounterCoordinator
  Start(character_id, session_id, scene_instance_id, scenario_selector)
  GetPhase / ApplyCheckpoint / EvaluateObjective / FinishOnce

EncounterSpawnManager
  ResolveSpawnPlan(encounter_definition_ref, wave_or_phase)
  SpawnOnce(instance_id, spawn_key, actor_definition_ref, position_source_ref)
  DespawnOnce(instance_id, entity_id, reason)

NpcActorController
  ResolveAuthority(actor, instance)
  SelectTarget / SelectIntent / RequestMoveOrAction / StopOnDeath

CombatActionCoordinator
  ValidateOwnership(actor, character, session, instance)
  AcceptBasicAttack / AcceptSkillCast
  ResolveCastState / ResolveHitEvent / ApplyResultOnce

TutorialProgressStore
  CommitEncounterResultOnce / CommitQuestTurnInOnce / Resume
```

- `*_ref` 一律是需追查的資料引用，不是用假定位置、怪物種類/編號、技能 ID 或時間常數填值。
- **怪物 AI 權威不可先寫死為 Server**：先由 T13/T02 調查原生 Client 是否使用本地 actor AI、網路 owner、主機代理、真正 Server 等。Server 最少要驗證其信任邊界與狀態有效性；若產品決定完全 Server-authoritative，須個別 ADR，且不能直接宣稱 KR 原版兼容。
- **玩家技能要拆四段**：要求/意圖 → 合法性判定 → 動作與結果執行 → 向 Client 可消費的通知。技能按鍵已觸發、施放動畫出現都不代表傷害或 Server 接受。
- **戰鬥結果與通關要拆兩段**：`encounter_result=scenario14` 不等於 `QuestInfo14=COMPLETED`，也不等於 `Quest16=AVAILABLE` 或 `tutorial=EXITED`。
- 數據防重候選鍵：`(instance_id, spawn_key)`、`(actor_id, action_sequence)`、`(character_id, instance_id, settlement_version)`；交易與失敗復原方式等 ADR 批准後才能規範化。

## 4. 候選研究題單（僅 S00 規劃，不是正式 RR，也非已派工）

1. **CR18-01 / T08 + T07：Scenario14 真正 monster spawn plan。** 提交有來源的 enemy resource ID、波次、觸發器、spawn frame/consumer、清理和場景前置。須對照既有 T08 一般 S2C0007 研究去重。
2. **CR18-02 / T13 + T09 + T02：NPC/怪物 AI 的決策來源與 actor owner。** 追查 SubAI 本地動作、網路 owner 授權、移動與 attack intent 從哪裡產生及誰發送；不得把自製 chase/home 改稱官方。
3. **CR18-03 / T11 + T10 + T04：教學角色初始技能以及施放因果鏈。** 確認技能/等級/取得條件、C2S 或 local producer、施放合法條件、取消與冷卻、消耗、結果的 Client 寫讀端；禁止將 resource 矩陣視為 Server 裁決。
4. **CR18-04 / T12 + T10 + T11 + T13：雙方攻擊命中→結果呈現。** 追查 S2C000E 具體 row 與命中/死亡/血量狀態寫入，分清 actor action 和 damage event；不要反推公式。
5. **CR18-05 / T14 + T07 + T16：Scenario14 波次完成/勝敗與通知條件。** 必須和 Iteration17 CR-02 去重，依已證 CTutorial 0x40/0x4C 子鏈補缺；不能造官方成功結果。
6. **CR18-06 / T15 + S00：同場戰鬥中斷／回復／防重，純 Server ADR 提案。** 區分 Client 可見現象與 Server 自訂 transaction/instance policy。

正式開 RR 前：核查 `research/requests/index.json`（目前 RR-0001..0008，無怪物/技能專案 RR）、對應 Txx inbox 與研究原稿，逐題列出 `BIN address / resource / existing SRC or CLM / blocking SPEC clause / nonduplicate proof obligation`；需要原生訊息就按唯一 RR 流程派工，不另設任務台帳。是否另建新的 REQ/GAP/SPEC，須先設計審核而不能僅因本草案即新增正式 ID。

## 5. 最小可行戰鬥契約的三個驗收層次

**Layer 1 — Mock / Server internal（可先做）**：記錄不可變角色/場景識別、實體生成唯一性、技能權限檢查、抽象 action/result、傷亡一致性、波次完成防重及重登復原；只使用自訂 ID 不假稱 native-compatible。

**Layer 2 — Native-static bounded（研究後才能做）**：以指定 KR SHA 的 producer/consumer、精確方向/offset/frame/scene gate 證明 Client 能消費必要 spawn、movement、skill/action、damage、result；若缺任一正向連結則 `BLOCKED`，不得提供猜測封包。

**Layer 3 — Original KR Client runtime（需用戶額外明確授權）**：由未修改原件、可重現 SHA、隔離環境，實際走完整教程怪物出生、攻擊/技能、傷害/死亡、勝敗、Quest14、重連；屬未執行目標，不能用合成 CI 取代。

### 測試規劃（全部 `PLANNED`、未執行、未登記正式 TEST）

| 候選測試 | 驗證焦點 | 期望/阻塞 |
|---|---|---|
| C18-T01 | 合法開始 Scenario14 | 無正確角色/session/instance 不得生成；encounter ID 與 quest ID 分離 |
| C18-T02 | spawn 去重與合法場景 | 重送相同 spawn key 不能雙重生成；未知 native plan 阻塞相容結論 |
| C18-T03 | spawn 可見與 actor type | 只有經 Client native 消費端支持的 actor 屬性才能生成原版 wire |
| C18-T04 | AI 無目標與失去目標 | 不產生跨場/已死 actor 的動作；原生決策仍待 T13 證明 |
| C18-T05 | AI owner 變更或連線中斷 | 無雙重權威、重複攻擊、失控 NPC；策略待 ADR |
| C18-T06 | 非法位移/碰撞 | 拒絕不合法位置；原生精確校正等待 T09 |
| C18-T07 | 合法普通攻擊起手 | 認證角色及 actor state、拒絕非法 C2S |
| C18-T08 | 連段與取消邊界 | 原生時窗不使用 0.65 秒 fixture 當真值 |
| C18-T09 | 技能合法施放 | 角色擁有技能、目標合法、資源足夠、冷卻到期、符合場景 |
| C18-T10 | 技能拒絕 | 無技能、冷卻中、MP/其他資源不足、已死、錯 owner、錯 instance |
| C18-T11 | 技能中斷及重送 | 消耗與冷卻不得二次計費；取消的退款/保留策略待查 |
| C18-T12 | 怪物攻擊玩家 | 命中/HP 來源可追；怪物不因死亡後殘留行動再扣血 |
| C18-T13 | 玩家擊中怪物 | 命中結果與 Client 消費保持一致；未證公式不以 fixture 補值 |
| C18-T14 | 怪物死亡與移除 | 只執行一次；活躍目標計數/後續 wave 不錯誤 |
| C18-T15 | 第一波/多波目標 | 只有找到原生客觀規則才允許判勝，無證不能把清怪+0.75 秒當完成 |
| C18-T16 | Scenario14 success / failure | 必須由可稽核的合法完成事件授權、只完成一次 |
| C18-T17 | 0x4C 和 CTutorial map | 有界 Client 狀態更新，不直接代表 QuestInfo14 completed |
| C18-T18 | Quest14 turn-in | 僅合法 Quest 狀態更新解鎖 Quest16，與 Scenario14 旗標分離 |
| C18-T19 | 斷線/重登 | 未完成可安全恢復/重試、已完成不重領/重刷；按 ADR 定義 |
| C18-T20 | 原版 KR 教學 E2E | 需要獨立 runtime 授權，當前 `NOT_RUN` |

## 6. 本輪設計決策與優先順序

- **P0-1**：T08/T07 的 Scene14 實際怪物種類/出生/波次 + T14 勝敗規則，優先確保關卡不可能無敵人或假結束。
- **P0-2**：T11/T10/T12 的「玩家普通攻擊和至少一個教學必需技能」從輸入到顯示結果的閉合證據，技能 ID 和數值都需追資源。
- **P0-3**：T13/T09/T02 的怪物決策與控制權位置，特別檢查是否原生 Client-side/SubAI/P2P 而非 Server 自主 AI。
- **P1**：死亡/碰撞/特效、全部其他職業技能與異常路徑；教學通關最小子集優先，不要求一開始覆蓋整套遊戲。
- **P1**：T15 的 resume/idempotency、失敗重試、斷線前後進度。

**Server 實作庫交接建議**：在 `ttr_server_roy` 先建立抽象 Spawn / ActorControl / Attack / Skill / CombatResult / EncounterResult 介面與 MockClient 測試，不輸出未知的 KR opcode、定值傷害或假官方波次。等 S00 審核有界原生 Client 契約與必要 ADR 後，才允許分 gate 對接真 KR Client。

## 7. 需要跨 Task 確認的最小交付格式

每條研究結論必須記：`Scope`（Scene/Scenario/Actor/Skill）、`Client source`（版本和 SHA，必要時 BIN 位址/資源路徑）、`Direction`（local / C2S / S2C / ownership）、`Producer`、`Consumer`、`Payload/layout`（若已證）、`Prerequisite/scene gate`、`Failure/unknown`、`Prior correction`、`S00 consequence`。只看到動作/技能 ID 時不得寫成已證 wire；只看到 Client handler 時不得推為 Server 生成規則。

### 與現有正式規劃的關係

本稿僅是 `Iteration17/E17` 細分，保持 `research/requests/index.json`、`design/requirements/index.json`、`design/gaps/index.json`、`spec/spec-index.json`、`conformance/test-index.json` 全不變。用戶明確要求「上 Git／Push」前不 Commit／Push，也不擅自啟動 Txx Agent 或執行原版 KR Client。

## 8. 核對來源（GitHub main）

- `governance/s00-iterations/S00-20261030-ITERATION-17-TUTORIAL-COMPLETION-PLAN.md`
- `governance/s00-iterations/S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json`
- `governance/s00-iterations/README.md`
- `governance/S00-NEXT-CHAT.md`
- `governance/s00-workflow.md`
- `kr/tasks/T07/README.md`、`T08/README.md`、`T09/README.md`、`T10/README.md`、`T11/README.md`、`T12/README.md`、`T13/README.md`、`T14/README.md`、`T16/README.md`
- `research/requests/index.json`、`design/requirements/index.json`、`design/gaps/index.json`、`spec/spec-index.json`

**已完成：** Iteration18 設計草案與研究題單；**未完成：** 正式 RR 建立、實作、原生兼容、原版 Client 驗證、Git 提交。