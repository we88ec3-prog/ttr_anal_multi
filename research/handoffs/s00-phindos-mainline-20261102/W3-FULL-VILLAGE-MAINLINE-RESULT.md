# 馮德斯村完整主線路線／村內 Quest 分類／全村終點（extra/roy3）

> 交付：2026-11-02，針對使用者新增「完整主線路線、分類村內任務、順序、NPC、前置、完成條件、必經劇情及明確全村終點」的要求，在原 W3 報告外**新增獨立檔案**；不改 W1/roy1、T16、Server 或其他 Task owner。工作分支 extra/roy3，沿現有 main 共同基準後續進展。此報告為**原版 KR 資源直接唯讀解碼 + 既存有界 Client 證據參照**，不是 T01 FULL-PASS、S00 STABLE、Server 已實作或遊玩 PASS。

## 0. 原件、方法、分類與能證的邊界

- 本次容器**實際持有並重算**原檔：`Table.stp` 5,248,784 bytes SHA-256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；`Event.stp` 11,241,597 bytes SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Tartaros.bin` 12,472,320 bytes SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。**這次沒有對全部 native producer/handler 做新的逐指令 CFG 驗收**；引用既有原生研究均標有界。
- 以已保存的 STPD archive index/XOR 和 `EX` zlib 解碼器對照重新提取，按 XML 精確 `Quest.id`、`SCENARIO.questId`、`SCENE(questIdx,sceneIdx)` JOIN；未執行遊戲、Lua、Client、Server，未修改原檔。核對：`Table/QuestInfo.xml` SHA-256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`，`Table/QuestTalk.xml` `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`，`Table/SceneList.xml` `1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037`，`Event/SceneList.xml` `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`。
- **R**=本輪原資源直接核對；**N(有界)**=既有 Client BIN-first 原稿／handler 的部分證據、本輪不重複 FULL-PASS；**S**=相容 Server 設計／驗收條件而非官服行為；**U**=缺少原版 Client 交易鏈／實機或原版 Server 證據。
- 路線**不是依 QuestID 遞增猜測**：逐筆 `Demands/Demand.id` 指向上一 Quest，連續十段 Town1 type2；Chapter XML 明列分組，Event XML 以雙 key 找到腳本。角色可接、實際 NPC 點擊成功、scene 能否逐場播放、場景勝利回覆、獎勵、DB 保存及新 Town 切換**不能只由這些 XML 斷定**。

## 1. 結論：兩層終點，完整村落以 132 合法結算為終點

```text
教學 Quest14 --Demand14--> Quest16（Town0）
    --Demand16--> Quest15（Town5, Field19, NPC10338）
    --Demand15--> Quest117（Town1, NPC10002）
       →118→119[戰鬥26]→120→121→122[戰鬥27]→123→124[戰鬥17]
       →131[Chapter2出村序章]→132[戰鬥28,離村末段]
       →133[Chapter2, Town2, NPC10053→10005；本村外的第一個任務]
```

**定義 A：馮德斯第一章劇情終點 = Quest124**。Table `CHAPTER chapterIdx=1,townId=1,chapterName=의식의 밤` 有 Quest15 與117–124，最後 `(124,7) Phindous_NightofRitual_After` 為**最後列出的場景資源**；必須再有合法 Quest124 結算／完成鍵才算第一章完成，並驗證 Quest131 的候選／接續，不能只播 `124/7` 就標完成。

**定義 B：使用者要求「完成全村主線並接到下一村」的正式開發驗收終點 = Quest132 完成且 Quest133 可正常進入。** `131/132` 在 `QuestInfo.town=1` 但 Chapter XML 已列 `chapterIdx=2,townId=2`，兩者是馮德斯**離村橋段**。最後資源 `(132,5) Phindous_pathofAlsmeer_Boss_After` 確有 `LoadMap("town002D.fld")`；這是跨村**演出**，不是正常 Town2 player spawn 證書。Quest133 `town=2, field=21, level=10, Demand132, giver=10053, finisher=10005` 是**下一村邊界，不應列入馮德斯必須完成**的 Quest。完整主線 acceptance 需**權威 Q132 已完成／合法獎勵與持久化 + Q133 在正確 Town2 角色／等級／前置下可接 + 正常 Town2 場景控制可用**，分成三項觀察，不以一張圖或一次劇情代替。

## 2. 12 筆主線／橋段完整資源矩陣

欄位 `Level` 是原始字面數字，`Town/Field` 是 **QuestInfo domain**，不是 Map、Case、World spawn。NPC 兩端為 giver→finisher 的 **NPC 資源 ID**，非網路 entityId。每列最基本的 **R 前置**是單一 `Demands`，**S 合法完成**是 Server 針對該筆接受、劇情／戰鬥結果、回報、完成及持久化的分離狀態；不能因播動畫或 `Demands`滿足就直接設 completed。

| Quest | 所屬 | 原韓文名稱 | Demand | Level | Town/Field | NPC giver→finisher | Chapter 順序 sceneIdx | 完成分類（S；未證官服內規） | RewardsEtc 原始 type:value |
|---|---|---|---|---|---|---|---|---|---|
| 15 | 進村橋接 | 핀더스 마을로 | 16 | 1 | 5/19 | 10338 → 10338 | 1,2,3,4 | 敘事 Quest；需合規接取／對話及交付 | 2:2800;4:468 |
| 117 | 村內第1章 | 사소한 소동 | 15 | 1 | 1/— | 10002 → 10002 | 1 | 敘事 Quest；需合規接取／對話及交付 | 2:710 |
| 118 | 村內第1章 | 유리와 라제드 | 117 | 5 | 1/28 | 10047 → 10047 | 1 | 敘事 Quest；需合規接取／對話及交付 | 未列 RewardsEtc |
| 119 | 村內第1章 | 유리와 라제드 (전투) | 118 | 5 | 1/26 | 10047 → 10047 | 1,2,3,4,5 | 戰鬥 Quest；需場景結果／授權交付 | 2:5850;3:40;4:900 |
| 120 | 村內第1章 | 세네레프 산의 귀신 나무 | 119 | 8 | 1/— | 10008 → 10008 | 1,2,3 | 敘事 Quest；需合規接取／對話及交付 | 未列 RewardsEtc |
| 121 | 村內第1章 | 라제드 구출 | 120 | 9 | 1/— | 10002 → 10002 | 1 | 敘事 Quest；需合規接取／對話及交付 | 未列 RewardsEtc |
| 122 | 村內第1章 | 라제드 구출 (전투) | 121 | 8 | 1/27 | 10002 → 10002 | 1,2,3,4,5 | 戰鬥 Quest；需場景結果／授權交付 | 2:9686;3:40;4:918 |
| 123 | 村內第1章 | 의식의 밤 | 122 | 9 | 1/— | 10048 → 10048 | 1 | 敘事 Quest；需合規接取／對話及交付 | 未列 RewardsEtc |
| 124 | 村內第1章 | 의식의 밤 (전투) | 123 | 9 | 1/17 | 10048 → 10048 | 1,2,3,4,5,6,7 | 戰鬥 Quest；需場景結果／授權交付 | 2:13086;3:40;4:1440 |
| 131 | 離村橋接 | 알스메르 마을 가는 길 | 124 | 10 | 1/— | 10002 → 10002 | 1 | 敘事 Quest；需合規接取／對話及交付 | 未列 RewardsEtc |
| 132 | 離村橋接 | 알스메르 마을 가는 길 (전투) | 131 | 10 | 1/28 | 10002 → 10002 | 1,2,3,4,5 | 戰鬥 Quest；需場景結果／授權交付 | 2:15850;3:40;4:1440 |
| 133 | 下一村邊界 | 정의의 사도 | 132 | 10 | 2/21 | 10053 → 10005 | 1 | 敘事 Quest；需合規接取／對話及交付 | 未列 RewardsEtc |

**重要特例：** 118 雖有 `field=28`，卻僅被 Chapter 列單一談話場景且任務名無戰鬥字樣；**不能只看 field 就要求 Field28 通關**。119/122/124/132 為有戰鬥字樣及多場景的 **R 戰鬥候選**；場景結算是否滿足原版完成旗標仍 **U**。Q120 的三段劇情會載入 `bluetree12C.fld` 演出，但沒有 QuestInfo field；沒有證據可將之當戰鬥 Quest。Q121 level9 → Q122 level8 不是筆誤，本輪保留原資源數值，不擅自調成遞增。Q15 `town=5` 卻列在 `CHAPTER1 townId=1`，Q131/132 `town=1` 卻列在 `CHAPTER2 townId=2`：**Chapter、QuestTown、Field、Map、Scene 是不同 typed domain**。

**RewardsEtc**：type2/3/4 的數值是 R metadata，**類型的經驗、貨幣或其他意義與授予的原生實作未於本輪完整確認**。空白表示此 QuestInfo 節點未列 RewardsEtc，不代表所有流程必然「零獎勵」。任務接受、完成、發獎、角色權利、Town 解鎖、持久化和劇情事件都要分開；不得以一次 `46`、`45` 或 `47` 當作全部動作的官方 ACK。

## 3. 必經劇情「資料源候選」：精確 Chapter 順序與對應 Event 腳本

下表是 **R Chapter 內固定有序的 scene keys / Event key join**，每段的 `LoadMap` 是原 Lua 的**演出載圖字面量**，不是物理 Server MapID 或官方必播事件。若要復原**原版完整主線的劇情體驗**，應以這些順序和腳本做逐段可播放驗收；但**Server 何時發每個 key、是否允許選播／跳段與戰鬥的 before/after gate 尚 U**，不能宣稱它們已實測全數「必經」。

| Quest | Chapter | XML ordered (quest,scene) / funcName | 腳本 LoadMap 字面量 |
|---|---|---|---|
| 15 | Chapter 1 | (15,1) Square_Tutorial01 → (15,2) scenario_tuto1_1 → (15,3) pindos_talkevent → (15,4) scenario_tuto2_1 | Square03D.fld / town001D.map |
| 117 | Chapter 1 | (117,1) Phindous_LittleTrouble | town001D.fld |
| 118 | Chapter 1 | (118,1) Phindous_YuriandRazed | town001D.fld |
| 119 | Chapter 1 | (119,1) Phindous_YuriandRazed_Blank → (119,2) Phindous_YuriandRazed_Stage → (119,3) Phindous_YuriandRazed_Boss → (119,4) Phindous_YuriandRazed_BossClear → (119,5) Phindous_YuriandRazed_After | mushroom01D.fld / mushroom12D.fld / town001D.fld |
| 120 | Chapter 1 | (120,1) Phindous_Senerep_TalkEvent → (120,2) Phindous_Senerep_TalkEvent2 → (120,3) Phindous_Senerep_TalkEvent3 | town001D.fld / bluetree12C.fld |
| 121 | Chapter 1 | (121,1) Phindous_RazedSave_TalkEvent | town001D.fld |
| 122 | Chapter 1 | (122,1) Phindous_RazedSave_Blank → (122,2) Phindous_RazedSave_Stage → (122,3) Phindous_RazedSave_Boss → (122,4) Phindous_RazedSave_BossClear → (122,5) Phindous_RazedSave_After | bluetree01C.fld / bluetree10C.fld / town001D.fld |
| 123 | Chapter 1 | (123,1) Phindous_NightofRitual_Talk_Event | bluetree01C.fld |
| 124 | Chapter 1 | (124,1) Phindous_NightofRitual_Blank → (124,2) Phindous_NightofRitual_Stage → (124,3) Phindous_NightofRitual_Stage02 → (124,4) Phindous_NightofRitual_Stage03 → (124,5) Phindous_NightofRitual_Boss → (124,6) Phindous_NightofRitual_Clear → (124,7) Phindous_NightofRitual_After | scenario_ygg01C.fld / scenario_ygg02C.fld / scenario_ygg03C.fld / scenario_ygg04C.fld / town001D.fld |
| 131 | Chapter 2 | (131,1) Phindous_pathofAlsmeer_Talkevent | town001D.fld |
| 132 | Chapter 2 | (132,1) Phindous_pathofAlsmeer_Blank → (132,2) Phindous_pathofAlsmeer_Stage → (132,3) Phindous_pathofAlsmeer_Boss → (132,4) Phindous_pathofAlsmeer_Boss_Clear → (132,5) Phindous_pathofAlsmeer_Boss_After | barley03D.fld / keep02D.fld / town002D.fld |
| 133 | Chapter 2 | (133,1) Alsmeer_Justice_Talk01 | town002D.fld |

**必查的可見劇情段**：
- `15/3 pindos_talkevent`：`LoadMap("town001D.map")`、NPC10047 演出物件、Talk group3 index18/24/20/21、`DoProlog(1)` 與 `RestoreMap`；不等於 Quest15 完成／玩家進村可動。
- `117/1 Phindous_LittleTrouble`：`town001D.fld`、NPC10002、Talk group1 index1–14，村內故事開始候選。
- `119/2–5`：`mushroom01D` → `mushroom12D` boss/clear → `town001D` 後日談；需區分劇情出現與 Field26 正常勝利。
- `120/1–3`：`town001D` → `bluetree12C` → `town001D`，劇情三段而非已證三場任務。
- `122/2–5`：`bluetree01C` → `bluetree10C` boss/clear → `town001D` 後日談；Field27 結果必須另證。
- `124/2–7`：`scenario_ygg01C→02C→03C→04C` 的 stage/boss/clear → `town001D` 後日談；這個尾場是第一章劇情終點，但**權威 Q124 完成不能由播放推論**。
- `131/1`：`town001D` 離村談話；`132/2–5`：`barley03D` → `keep02D` boss/clear → `town002D` 後日談；Quest132 才是村落範圍最後一個 Quest，Quest133 是 Town2 新任務。

完整 **35 個** `(quest,scene)→funcName→script LoadMap→script SHA-256` 及 `Event/Sequences/*.seq` 精確 hash 存於 [W3-PHINDOS-SCENE-INDEX.json](W3-PHINDOS-SCENE-INDEX.json)。其中 4 個屬 Quest15，24 個屬 117–124，6 個屬 131–132，1 個屬 133。不能把 `sceneIdx` 當作自動 `+1`；既有 0x47E890 FIRST / 0x47E640 NEXT 以 Chapter 有序向量取候選，需以本表每列精確鍵核對 0x565720/Event script loader，與 SceneController busy/gate 分離。

## 4. 村內任務完整分類：77 筆 TownId1，不把類別混用

直接掃描原始 QuestInfo：**Town1 共77筆**，其中 `type2/subtype1` 十筆（117–124、131–132；主線與離村橋段），`type1` 另外 67 筆，依原 `subtype` 分別：**1 = 2筆、2 = 26筆、3 = 24筆、4 = 15筆**。這是**資料分類，不擅稱 subtype2/3 是每日或可重複**，亦不宣稱全部可立即接取。每一筆 `type1` 在此 pinned Chapter1/2 主線 SceneList 中**沒有被列為上述主線有序 Scenario**。

| 任務組（R metadata） | 筆數 | ID（非主線門檻） | 例／重要前置 |
|---|---:|---|---|
| type1/subtype1 | 2 | 37, 88 | Quest37 `level=120`、NPC10002，Quest88 NPC10003；不是 Quest117 前置。 |
| type1/subtype2 | 26 | 1, 5, 7, 8, 40, 42, 43, 45, 67, 74, 75, 79, 81, 83, 85, 86, 263, 516, 535, 536, 537, 538, 2089, 2092, 2095, 2096 | 多為 NPC10001/10002/10003/10008 的其他委託；如2095需2094、2096需2095。 |
| type1/subtype3 | 24 | 2, 3, 4, 6, 9, 41, 44, 68, 69, 70, 71, 72, 73, 76, 77, 78, 80, 82, 84, 87, 262, 270, 377, 378 | 如 Quest2 需1、Quest44 需43；不直接插入主線。 |
| type1/subtype4 | 15 | 125, 126, 127, 128, 129, 130, 2840, 2842, 2843, 2845, 2846, 2847, 2848, 2849, 2850 | 教學／功能引導候選。125需37；126無 Demands；127→126、128→127、129→128、130→129；2846需2845、2848需2847、2850需2849。 |

**獨立 side/guide 關聯**：`125(10002,需37)`、`126(10008,無Demand)`、`127–130(10014,需前一個)` 不能憑數字接在 Quest124→131 之間。`QuestInfo.level=120` 在多個非主線記錄存在，是**原資源字面值而不是已證玩家需要練到120級**；應檢查 UI eligibility parser/業務常數後才決定處理。已查原始所有 QuestInfo 的 `Demands` 反向關係：在同一串主線下一步以外另有 **Quest266（Town5,type1）需 Quest124**；屬主線完成後可開放的**其他任務，不是抵達 Q132 的先決**。

全 77 筆的精確 `quest/type/subtype/town/chapter/level/field/giver/finisher/Demand/韓文名稱/分類` 見 [W3-PHINDOS-QUEST-CLASSIFICATION.csv](W3-PHINDOS-QUEST-CLASSIFICATION.csv)。此 CSV 只重建 QuestInfo 指定欄位；**沒有自行改寫 QuestTalk、AcceptAction、CompleteAction**。

## 5. NPC 與正常場景／互動/完成：各自權威來源（R + N有界 + S/U）

**Town1 靜態 roster R**：`10001,10002,10003,10008,10013,10014,10047,10048,10015`（`Table/_TownList.xml`），當中主線 NPC 是 `10002`（117/121/122/131/132）、`10047`（118/119）、`10008`（120）、`10048`（123/**124**）。特別修正容易遺漏的 **Quest123 也由10048給予／交付**。`10001/10003/10013/10014/10015` 沒有這十筆主線 giver 關係，不代表它們不會有其他 side、服務、事件。

- **Town context / physical scene**：W3 資源證據 `TownId=1 / TYPE1`、`MapList.ID=182`、`town001D.fld/mre`、`BoundMap/town001.bnd` version0/world1536/768 grid；`0038/type0` 可以更新業務 Town context，`0012` 是物理 map selector 的既有 Client 候選。這些值不能互相替代，也不能將 Quest15 演出 `town001D.map` 當自動建立正常 Town scene。
- **NPC to C2S**：W3-05 對既有 T16-126/127 的有限引用，事件建構 `object+F4` kind、`+F6` selector，`0x544070` kind3 可先走 `F43D9→0x5B9340`、type2候選再走另一段 `C2S001C`。`001C` app body 是 `[u16 001C][u16 event word][u16 event word]`，不能猜成 `[001C,QuestId,NpcId]`。Town1 各 NPC 的實際 kind/selector + world actor/entityId **U**，也不能把看到 NPC 與可接取等號。
- **劇情/接取/提交互斥界線**：既有 T16-135/W3-05 有界 `C2S003F` [primary,secondary,1] controller/queue、`0036` [qid] 獨立條件 sender，`S2C0040` qid/state (mode2 UI)、`0045` CompleteAction、`0046` qid/substate (mode3/UI/prereq有條件)、`0047` (primary,secondary) controller、`0074` prereq key增量、`006F` **完整 bitmap snapshot**。它們是 application body/consumer 有界主張，**不是已證完整 wire frame、原版 Server 收發時序或每筆一一對應 ACK**。`46/0` 不直接調 SceneController；`40/45` 的 action type2 分支須真的存在於該 Quest 的 QuestInfo。`type=2` Quest ≠ `AcceptAction.type=2`。本輪原始 117–132 的 Quest XML **未含 AcceptAction/CompleteAction 節點**，因此**不得把既有 action2 分支硬塞到每個 Quest**。
- **正常 NPC/場景**：場景 actor 07→NPC model 可見 ≠ quest interaction 已閉合。原生 Town 的 RTTI/controller、合法 Spawn/回城點、NPC event actor 綁定、街道互動距離、ready/loading、輸入重啟仍未完整證明。所謂 `town001D.fld` 或演出 `CreateObject(x,y)` 是劇情資源，**不能當 Server spawn**。W3-01/05 保留此界線。

## 6. 待 Server 實作的逐任務狀態機與最小正流程（S，不冒稱官服規則）

針對 Quest `q`，至少分開：
```text
eligible(q): authoritative completed(Demand(q)) + Town/Level/排除條件（Client 有界篩選；Server 政策待 S00 決定）
  → offer(q, NPC giver): NPC 事件上下文 + Quest Candidate/UI
  → accept(q): 合法輸入/權威 accepted + 可播放 (q,Scene FIRST) 的獨立控制
  → story/field(q): 依章節 ordered scene keys, 戰鬥者另需 Field/Scenario result
  → turn-in(q, NPC finisher): 不是僅播放最後一場動畫
  → settle(q): 權威 completed、reward entitlement、持久化、發布下一個 Demands key
  → offer(next) / Town/Scenario transition: 不把 reward/UI/劇情當 completed
```

`S` **正流程最小測試**（全為 **NOT_RUN**）：

1. 權威 Q14→Q16→Q15 合法結算；Town5 NPC10338 交付後，Town1 正常載入 Map182/角色控制/九 NPC；確認 Q117 是候選，非僅播放 Q15/3。
2. 依次對 `117→118→119` 正確 NPC、level、前置與 Chapter script key，Q119 的 Field26 有可稽核勝利/結果/交付；完成後 Q120 可接。
3. `120` 三個談話/演出 key 與 `121` 橋接 NPC 不互相代替；`122` Field27 合法通關/交付，才釋放 Q123。
4. `123` 在 NPC10048 互動，`124` Field17 多 stage/Boss/Clear/After 且合法結算；**Checkpoint A**：Q124 完成、Q131 可接，此時第一章完成，但**全村主線尚未完成**。
5. `131` NPC10002 的出村對話後，`132` Field28 完成正常入場/戰鬥/結果/交付/獎勵/保存；**Checkpoint B**：Q132 completed 的完整 snapshot 不覆蓋先前 key，Q133 在 Town2/level10/NPC10053 可合法接取（交給NPC10005），正常 Town2 player controller/UI 成立。**此時才標「全村主線完成」**。
6. 每階段記錄 Server branch/commit、原件 SHA、typed quest/town/map/field/scene/NPC、角色身分、C2S/S2C application bytes 與 transport 外框（若有）、Client UI+場景可見性及 DB 權威狀態；劇情可播放、Quest 合法完成、reward、下一任務出現、地圖可走**分開打勾**。

**S 持久化不變量建議**：completed 集合、active/accepted、Scenario outcome、reward ledger、當前 Town/World、各個場景事件須分開；QuestInfo `Demand` 在 Client 是 eligibility 候選，不是證明原版 Server DB 規則。採 006F 時它**重建整份 bitmap**，不得在先前 0074/0046 後發過時 snapshot 導致先決被清掉。禁止 Client 虛擬完成或「跳過支線或劇情便設 completed」的捷徑。

## 7. 精確缺口／分工（不阻止仍可開發的 S 規格）

| 類型 | 未閉合的精確問題 | 下步驗證 / 不可代用 |
|---|---|---|
| Client 待逆向（T16/T07/T02） | Q117–132 實際 NPC event kind/selector、C2S001C/0036/003F/003C 每種 producer gate、收到0040/45/46/47 的真正主線時序、各 scene LAST→下一任務交付判斷 | 原 BIN producer→queue、S2C dispatcher/consumer 配特定資源，再以合法原 Client 正流程驗收；不得猜 opcode、ACK。 |
| Client 待逆向（T07/T08/T09） | Town1 正常 scene/controller、Map182 轉入、NPC world entity/event binding、合法出生/返回點、bounds可達路徑及 loading/ready | 按 W3-01/05 既有入口補證；不能把任何 cutscene camera/object xy 當玩家或 NPC 標準位置。 |
| Scenario/結果（W2/T14） | Field26/27/17/28 的真 Scenario/Case/Map、objective success、結果返回與Quest settlement 對接 | 必須從各 field 資源與 Client 結果路徑核對，不能從 FieldId 推 MapID，也不能把教學 TUTO 的 4C 直接套用。 |
| Server 待開發（S00） | 角色權威任務狀態/合法前置與等級政策、獎勵 type 解義/發放交易、Town 解鎖、任務完成→下一任務發布與 Scene 排程 | 可設計並標 ADR/SPEC DRAFT，不等同官服行為；角色取得/Level/已學技能的真業務 gate 需明定與測試。 |
| 待遊玩驗證 | 全程正常新角色15→117→…→132→133，場景播完可互動、各戰鬥回城、DB 及 UI 一致 | 本輪未操作 Client/Server，**NOT_RUN**；取消、重登、重試、負向、競態、故障/壓測按使用者現有政策延後。 |

## 8. 來源追溯及與其他工作包之關係

- [本派工總卡](README.md)；[W1 既有負責範圍](W1-QUEST-CHAIN.md)（指定 extra/roy1）、[W3 Town 資源原稿](W3-RESULT.md)、[W3-05 NPC producer 勘誤](W3-RESULT-05-NPC-SCENE-INTERFACE-BOUNDARIES.md)。**本次是使用者更新指定 extra/roy3 執行路線整合**，不修改 roy1 的工作卡或原稿。
- 舊原生有界參考：`kr-temp-roy/20261031-165535-chatgpt-web-roy-T16-135-KR-Quest14-16-15-Pindos-player-flow-Server-contract-evidence-matrix.md` blob `b0a15aaabe1fc2d86225c5d5466b6ab78564c29c`；`kr-temp-roy/20261030-114038-chatgpt-web-roy-T16-126-KR-Quest15-study2-NPC10338-actor-constructor-F43D9-type2-event-mode2-TalkBox.md` blob `ae6e38af9c7078c23c21ca793e49bbcbc31b8ea6`；`kr-temp-roy/20261030-141801-chatgpt-web-roy-T16-127-KR-Quest15-study3-NPC10338-001C-003F-0036-sender-queue-native.md` blob `4e8e07719e882b4525481641dce929dd9786b87d`；`governance/s00-iterations/S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.md`。
- 本次原件由同版本 `Table.stp` 與 `Event.stp` 重新解碼精確資源；`W3-PHINDOS-SCENE-INDEX.json` 記每支故事腳本 SHA256，`W3-PHINDOS-QUEST-CLASSIFICATION.csv` 記全 Town1 QuestInfo 欄位，供 T01 校對去重與 S00 分別接受。此操作未設置正式 RR/T01 FULL-PASS，亦未替 W1、W2 或 S00 擅自提交 Server 實作。
