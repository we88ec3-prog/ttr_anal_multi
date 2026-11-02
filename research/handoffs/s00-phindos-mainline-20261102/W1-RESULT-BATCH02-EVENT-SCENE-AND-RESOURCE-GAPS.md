# W1-RESULT BATCH02 — 馮德斯主線 15→117→132：35 筆原始劇情 Scene、原始 STPD 封裝索引與補檔需求

> 2026-11-02／`extra/roy1`／**PARTIAL, FIRST-HAND RESOURCE METADATA**。延續 BATCH01；本稿重核現有 `Event.stp`、`Table.stp`、原始 KR BIN SHA，不執行／修改 Client 或 Server。檔名／劇情腳本內容與 ID 以直接從當次 STPD 實檔解析為準；**沒有**把劇情演出、QuestInfo Demand、結果包或存檔混同為已驗收完整任務。T01 獨立驗證，S00 自行決定採用。

## 1. 本輪主要新證據：`.seq` 腳本直接標明 Quest / Scene

- `Event.stp` SHA256 **`2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`**；`Table.stp` SHA256 **`09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`**。原始 `Tartaros.bin` SHA256 **`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**；BIN 僅核實檔案身分，這輪對 `.seq` 的主張是第一手**資源**證據，不是重新審查 BIN 的 Quest opcode。
- 唯讀解析 `STPD` 檔案和反相位元組，根據 `STPI` 目錄、32B 成員 metadata 與 MD5 校驗復原原始 `.seq` 內容；**1839 個 `.seq` 均為直接可讀，1836 個有 `-- Quest #... / Scene #... - Function ...` 標頭。** 與同名函式交叉核對須用 **`STPI catalog index + 1`** 對應實體成員紀錄；按此規則 **1836/1836 精確吻合**。不採此偏移會全數錯配。
- 對本批 **35 筆** Quest15、117～124、131～133 劇情腳本，均重新比對 STPD member metadata 的**原始 MD5**並核出作者註解的 Quest/Scene、`function`、`LoadMap(...)` 和 `CreateObject(...)` actor ID。`LoadMap` 表示 cutscene 對應演出載入路徑；`CreateObject` 表示演出實體/演員 ID，**不代表 World Spawn 或可點 NPC**。
- `Table/SceneList.xml` 和 `Event/SceneList.xml` 的可確認內容目前仍是 `EX v1` 封裝，未從原件完成安全且精確的解壓，因此**劇情腳本註解的 Quest/Scene 數值 != 已證可由 Client dispatch 觸發的 SceneList key 或 Chapter**。本報告把兩個結論分層。

## 2. 逐 Quest 的作者資源標頭與演出地圖摘要

| Quest ID | Scene ID (來源為 `.seq` 標頭) | Script Function | `LoadMap` 演出路徑 | STPD file record ID |
|---:|---:|---|---|---:|
| 15 | 1 | `Square_Tutorial01` | `Square03D.fld` | 7135 |
| 15 | 2 | `scenario_tuto1_1` | `Square03D.fld` | 7133 |
| 15 | 3 | `pindos_talkevent` | `town001D.map` | 6851 |
| 15 | 4 | `scenario_tuto2_1` | `""` | 7134 |
| 117 | 1 | `Phindous_LittleTrouble` | `town001D.fld` | 6816 |
| 118 | 1 | `Phindous_YuriandRazed` | `town001D.fld` | 6842 |
| 119 | 1 | `Phindous_YuriandRazed_Blank` | `""` | 6844 |
| 119 | 2 | `Phindous_YuriandRazed_Stage` | `mushroom01D.fld` | 6847 |
| 119 | 3 | `Phindous_YuriandRazed_Boss` | `mushroom12D.fld` | 6845 |
| 119 | 4 | `Phindous_YuriandRazed_BossClear` | `mushroom12D.fld` | 6846 |
| 119 | 5 | `Phindous_YuriandRazed_After` | `town001D.fld` | 6843 |
| 120 | 1 | `Phindous_Senerep_TalkEvent` | `town001D.fld` | 6839 |
| 120 | 2 | `Phindous_Senerep_TalkEvent2` | `bluetree12C.fld` | 6840 |
| 120 | 3 | `Phindous_Senerep_TalkEvent3` | `town001D.fld` | 6841 |
| 121 | 1 | `Phindous_RazedSave_TalkEvent` | `town001D.fld` | 6838 |
| 122 | 1 | `Phindous_RazedSave_Blank` | `""` | 6834 |
| 122 | 2 | `Phindous_RazedSave_Stage` | `bluetree01C.fld` | 6837 |
| 122 | 3 | `Phindous_RazedSave_Boss` | `bluetree10C.fld` | 6835 |
| 122 | 4 | `Phindous_RazedSave_BossClear` | `bluetree10C.fld` | 6836 |
| 122 | 5 | `Phindous_RazedSave_After` | `town001D.fld` | 6833 |
| 123 | 1 | `Phindous_NightofRitual_Talk_Event` | `bluetree01C.fld` | 6825 |
| 124 | 1 | `Phindous_NightofRitual_Blank` | `""` | 6819 |
| 124 | 2 | `Phindous_NightofRitual_Stage` | `scenario_ygg01C.fld` | 6822 |
| 124 | 3 | `Phindous_NightofRitual_Stage02` | `scenario_ygg02C.fld` | 6823 |
| 124 | 4 | `Phindous_NightofRitual_Stage03` | `scenario_ygg03C.fld` | 6824 |
| 124 | 5 | `Phindous_NightofRitual_Boss` | `scenario_ygg04C.fld` | 6820 |
| 124 | 6 | `Phindous_NightofRitual_Clear` | `scenario_ygg04C.fld` | 6821 |
| 124 | 7 | `Phindous_NightofRitual_After` | `town001D.fld` | 6818 |
| 131 | 1 | `Phindous_pathofAlsmeer_Talkevent` | `town001D.fld` | 6831 |
| 132 | 1 | `Phindous_pathofAlsmeer_Blank` | `""` | 6826 |
| 132 | 2 | `Phindous_pathofAlsmeer_Stage` | `barley03D.fld` | 6830 |
| 132 | 3 | `Phindous_pathofAlsmeer_Boss` | `keep02D.fld` | 6827 |
| 132 | 4 | `Phindous_pathofAlsmeer_Boss_Clear` | `keep02D.fld` | 6829 |
| 132 | 5 | `Phindous_pathofAlsmeer_Boss_After` | `town002D.fld` | 6828 |
| 133 | 1 | `Alsmeer_Justice_Talk01` | `town002D.fld` | 5629 |

### 2.1 關鍵三段——正常進村、進村後第一件任務、跨 Town2

**Quest15**：作者標註 Scene1/2/3/4；Scene3 `pindos_talkevent` 執行 `LoadMap("town001D.map")`，且 `CreateObject` 中有 ID `10047` 及 1478～1481，這提供進村劇情的**正向演出資源**。QuestInfo BATCH01 對 15 的 `town=5,field=19,demand=16,giver/finisher=10338` 獨立成立；與 Stage19/Case103、Map191/192 不能以同數值互換，**更不能以 Scene3 到 Town1 宣告 Quest15 已合法結算**。

**Quest117**：Scene1 `Phindous_LittleTrouble`，`LoadMap("town001D.fld")`、`CreateObject` 包含 ID `10002`，與 pinned Quest117 接／交 NPC10002 相交；但它是演出中的 actor ID，不是互動封包或 NPC 世界座標。仍要分開驗證 Quest15 已結算 → Quest117 offer/accepted → 達成 → NPC10002 turn-in → reward type2:value710 → 保存。

**Quest132**：Scene1～5 依次有 Blank、Stage、Boss、Boss_Clear、Boss_After；Scene5 `Phindous_pathofAlsmeer_Boss_After` 已直接 `LoadMap("town002D.fld")`，而 Quest133 Scene1 `Alsmeer_Justice_Talk01` 也使用 `town002D.fld`。**這證明跨 Town2 的演出素材已在 Quest132 的 Scene5 中出現，而不是只有 Quest133**；不證明 Scene5 就必定完成 Quest132 或已發 reward、持久化、解鎖 Town2。Quest133 的 pinned `town=2,demand132` 才是後續候選資料域。

### 2.2 需要避免混淆的情況

- Quest119、122、124、132 各自有 `Blank`／`Stage`／`Boss`／`Clear`／`After` 的不同 Scene，`Clear` 是**腳本名稱**，不能直接等同 Server 採用的合法副本結果或 Quest Completed flag。
- Quest124 的 Scene2～6 依次用 `scenario_ygg01C/02C/03C/04C.fld` 等 cutscene 地圖。QuestInfo `field=17`、Case101 Stage17 是候選 join，**不因劇情使用的 `.fld` 名稱而把 Stage、Case、Map、Scene 混成同一 ID**。
- Quest118/119（Level5）、120/121/122（Level8/9）、123/124（Level9）、131/132（Level10）為 pinned resource 的要求欄位；對角色實際等級、已學技能、先決角色授予仍無此輪 Client gate 正向證據。

## 3. STPD／STPI 實體成員索引：復現與原稿 BATCH01 的修正

**讀檔原則**：最外層 `STPD`／`STPI` signature 不反相，其餘欄位可用 `byte XOR 0xFF` 還原；檔案標頭記錄 STPI 位址，STPI 前有每筆 32-byte metadata（ID、儲存大小、首尾1024B資料塊、MD5），實際資料從 `start_block * 1024 + 16` 開始。此觀察只對兩個已提供且驗證 SHA 的包成立。`STPI` 的檔名字串 index 要使用 `catalog_index + 1` 才能連結到 metadata row（1836 個腳本的作者函式名全部吻合是獨立交叉檢查）。

| 來源檔案 | STPI Catalog ID | 實體成員 ID | 原始 member 長度 | 內層 EX 宣告解壓後長度 | 已取得 XML 明文？ |
|---|---:|---:|---:|---:|---|
| `Table.stp/QuestInfo.xml` | 976 | 977 | 204,056 | 2,503,464 | 否（EX_v1 編碼尚待解） |
| `Table.stp/QuestTalk.xml` | 977 | 978 | 52,404 | 342,958 | 否（EX_v1 編碼尚待解） |
| `Table.stp/SceneList.xml` | 983 | 984 | 3,404 | 65,494 | 否（EX_v1 編碼尚待解） |
| `Event.stp/SceneList.xml` | 7378 | 7379 | 14,000 | 158,269 | 否（EX_v1 編碼尚待解） |

**更正 BATCH01**：先前把 `Event/SceneList.xml` 指到相鄰 Lua 基底腳本的疑慮，源自 STPI 目錄 ID 少算 1。實體檔案需採 `catalog+1`；`Event/SceneList.xml` 實際為 **EX v1 壓縮封裝**，不能用相鄰 Lua bytecode 代替映射表。`Table/QuestInfo.xml` 同樣不可拿前一個 STPD member 當作相同文件。

## 4. 使用者如果方便補檔，請依優先序提供以下**解包後明文**

1. **最重要：`Table/SceneList.xml`、`Event/SceneList.xml`**（最好包含完整 XML 內容、檔案 SHA256 和使用的 KR resource 版本）。這兩個存於已提供 STP 內，但其**內層 EX v1 內容尚未完成解碼**。它們能把本批的 35 筆作者 Scene ID 與實際 Client SceneList key／觸發路徑對上。
2. **`Table/QuestTalk.xml`**（完整原件，避免只截圖）。可協助將 Quest 接受／結算 NPC 的對話分支與 `Quest` ID 連上。它也包含在現有 STP 內，但仍是 EX 封裝。
3. **`Table/QuestInfo.xml` 原始明文**，或原先供 S00 `RESOURCE-BASELINE.json` 抽取的**同版 Table 來源檔**。基準成員 SHA256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`；基準來源載體 SHA256 `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`，**與這次本地 Table.stp SHA `09e2...` 不同**，不能假設內容一模一樣。
4. **若另有 Chapter/ChapterList 表或 Story/Quest 章節映射 XML，請提供其原始檔名及所在資源包**；現有兩包的 STPI 檔名目錄沒有 `Chapter` 字樣，這不代表遊戲不存在 Chapter 系統。若有 `Table/ScenarioTalkTable.xml`、`Table/TalkTableSet.xml` 的可讀內容，也能協助劇情對話，但優先度低於上面三項。

**目前不用重新上傳** `Tartaros.bin`、`Table.stp`、`Event.stp` 或 `BoundMap.stp` 的同一檔案；四個檔的 SHA 已有或可重核。也**不需要提供原版 Server** 的 DB、業務原始碼，Server 規則由 S00 自行設計。

## 5. W1 對 S00 的可交付邊界（功能狀態彼此獨立）

| 階段／欄位 | 新增證據 | 對 Server 現階段的用法 | 尚不可宣稱 |
|---|---|---|---|
| Quest 前置 `Demand`／NPC／Town／Field／Level | BATCH01 pinned QuestInfo | 建 DRAFT typed ID 和合法接取候選條件 | Client 真正 UI 已啟用／玩家已接取 |
| Quest/Scene 作者標頭及 `LoadMap` | BATCH02 Event `.seq` 35份、MD5 每份核對 | 作場景與人工正常測試的候選正流程清單 | SceneList 正式 route／spawn／world MapId／演出播完即完成 |
| Quest15→117 正常銜接 | Demand(15)、Quest15 Scene3、Quest117 Scene1 | 分開記錄主線前置、Town1 達到、Quest117 offer／accept／達成／turn-in | 到村即結算Quest15/117 |
| Quest132→133 跨 Town | Quest132 Scene5 地圖 `town002D.fld`，Quest133 Demand132 | 設立村內終點與跨村劇情的分離驗收條件 | Scene5 播放即任務132獎勵／保存成功 |
| Quest 完成 / S2C snapshot/增量 / Reward type2/3/4 / 持久化 | 尚缺 QuestTalk、SceneList、T03/T04 Client Consumer | 只預留 domain 和原子結算設計接口 | 猜 Type 為金幣/EXP、跳過交付、假造封包 |

## 6. 下一批只做正常情境，且仍維持 W1 範圍

- 取得明文 QuestTalk／SceneList 後，以實際鍵對照 BATCH02 35 筆 Scene，定位 NPC 對話、接任務／交付與 Client 事件消費者；只做必要 BIN-first 原生 handler 定向核對。
- 追 Reward type2/3/4 原生 consumer、`6F` 完整 snapshot 與 `74` 增量用途及 Quest settlement 的實際 UI 畫面資料來源，交給 S00 設計一次性結算及角色持久化。
- 和 W2 對接 Case/Field 正常副本結果、W3 對接 Town1 NPC 可見／可互動與合法座標；不重做 S00 的 AI/MEF 或戰鬥連擊，也不做使用者禁止的重播／重登／負向／併發／故障／壓測。

**實際執行的限定檢查**：Event 1839 個 `.seq` 的原始成員 MD5 全吻合、1836 個 TTEX 資源標頭/函式名全吻合（需 catalog+1）、35 筆本輪 Quest/Scene 已列出；Table/Event STPI/EX metadata 可重現。這些都是資源局部 PASS，**不等於 T01 FULL-PASS、Server 已可玩或正式 RR/APPROVED**。

**搭配的機讀與唯讀腳本**：`W1-RESULT-BATCH02-EVENT-SCENE-MATRIX.json`、`W1-RESULT-BATCH02-ARCHIVE-INDEX.json`、`W1-RESULT-BATCH02-EVENT-SEQUENCE-AUDIT.py`、`W1-RESULT-BATCH02-STPD-INDEX-AUDIT.py`。