# T16-136 — 新手教學 → 馮德斯村 → 爾斯梅勒村：KR 主線任務完整來源清單與前置／場景驗證

- 研究時間：`2026-10-31T17:15:27+08:00`；作者 `chatgpt-web roy`；**正式 T16-136（承接 T16-135）**。
- 研究範圍：列出到達爾斯梅勒的全部 `QuestInfo type=2/3` 主線鏈，另附爾斯梅勒章節延伸與往下一村的出口，避免因「到達村莊」和「完成村莊劇情」定義不同而漏段。**QuestInfo 原始欄位與完整 XML row 為本報第一手資料；中文任務名稱僅為工作譯名，非官方繁中譯文**。
- **總結與狀態**：從 `14→16→15→117→...→124→131→132→133→...→142→143→144` 共 **25 個連續 `Demands` 單前置的 type2/3 主線節點**；另列 6 個教程資源型 `type3` 任務（1002/2742–2746，沒有 `Demands`，不臆造其相互順序）。進入 town 2 的首個 Quest 是 133；爾斯梅勒章節主線終點 142；143/144 為下一地區過渡。**資源拓撲分析已完成；實際遊戲觸發時序、Client→Server 真實封包配對與可玩驗收仍分開**。
- 任務 14、16 及 15 的 Player/Client application handler 與 NPC event / mode2 UI 條件式鏈，沿用 T16-118～135；本稿新增**完整 QuestInfo + Chapter SceneList + Event SceneList + TownList + NPC 名稱的第一手交叉解碼**。原始 `Table.stp` 和 `Event.stp` 僅離線讀取、不執行遊戲，**不將完整遊戲 XML 上傳 GitHub**。

## A. 來源身份與解碼重現

- `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `Tartaros.exe`：2,594,816 bytes，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- `Table.stp`：5,248,784 bytes，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。
- `Event.stp`：11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- `Table.stp` 資料包：`STPD` header；`raw+4` 反碼資料指向 `STPI` 檔名索引；資料區各檔 1024-byte 對齊；`EX 01 00` header 位於解 XOR-FF 後的偏移。依已驗證 E06 native `0x72F260`／1024-byte key 演算法，把 EX payload 以 key XOR 再 zlib 解壓，檢驗解壓長度。**`Table` 與 `Event` 不可混用不同的 `SceneList.xml`**。
- 解碼所用 key seed `30e7`，遞推 `key[i]=(key[i-2]+key[i-1]+0x13)&255`、`key[i+1]=(key[i-1]+key[i]+0x13)&255`，僅 `i==0x17c` 前一值減 `0x56`；key 長 `1024`，payload 異或 `key[j&1023]`。此法可獨立重現前稿 `Event/SceneList.xml` SHA。

| 原始資源 | STPD body raw（XOR 後 EX） | EX壓縮/解壓 bytes | 解壓資料 SHA256 | 索引根／筆數 |
|---|---:|---:|---|---|
| `Table/QuestInfo.xml` | `0x425010` | 204,040 / 2,503,464 | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | `QuestInfo`／4,798 |
| `Table/QuestTalk.xml` | `0x457010` | 52,388 / 342,958 | `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28` | `QuestTalk`／4,322 |
| `Table/SceneList.xml` | `0x489c10` | 3,388 / 65,494 | `1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037` | `CHAPTERTABLE`／25 |
| `Table/_TownList.xml` | `0x4f0810` | 770 / 4,883 | `bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660` | `TOWNLIST`／17 |
| `Table/_TownTypeList.xml` | `0x4f0c10` | 569 / 1,662 | `06b9a38619561c224db59f8ec8c47e578c255dba6c09146ddd8a3096d6c0c89c` | `TOWNLIST`／30 |
| `Table/NpcInfoTable.xml (NPCTABLE)` | `0x3aac10` | 27,543 / 507,817 | `a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d` | `NPCTABLE`／531 |
| `Table/_MapTitleList.xml` | `0x4d8410` | 3,258 / 22,964 | `4b22bb4e22530a58a643aee5f4f94b8b59b126263ed32ecbc4f9975725d67e22` | `MAPTITLELIST`／2 |
| `Event/SceneList.xml` | `0xa23810` | 13,984 / 158,269 | `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25` | `SCENESET`／1,687 |

**資料驗證**：QuestInfo 恰 **4,798** 個 Quest node、Event SceneList **1,687** 個 SCENE、Table CHAPTERTABLE **25** 個章節；本範圍所有 Table chapter scene indices 都能在 Event SceneList 用相同 `(questIdx,sceneIdx)` 找到對應 script name。這表示**靜態資料映射完備**，不表示 Lua 在實機會被播放。

## B. 地區、章節與身份 namespace（本次新確認）

| 識別 | 原始值 | 研究判讀／重要界線 |
|---|---|---|
| 馮德斯村 | `Table/_TownList.xml` TOWN `ID=1 NAME=핀더스`；MapTitle `Town_01_Phindous.dds` | Quest 117–124 與 131/132 任務 town1；不是 `TownID=5` 的廣場 |
| 爾斯梅勒村 | TOWN `ID=2 NAME=알스메르`；MapTitle `Town_02_Alsmeer.dds` | Quest 133 起 town2；Quest 131/132 雖在 town1，**Table CHAPTER 已掛 chapter2** |
| 教學區 | town0=`레나르트`（雷納特，工作音譯） | Quest14/16 town0；教程1002/2742–2746也是 town0；不等同進村完成 |
| Quest15 的特殊狀態 | Quest15 `town=5`,`field=19`；TOWN5=`광장1` | SceneList 把 Quest15 收在 `chapterIdx=1,townId=1`；**任務 town5/場景 Chapter town1 不可直接合一** |
| 章節1 | `chapterIdx=1,townId=1,chapterName=의식의 밤`（儀式之夜） | 收錄 Q15,117–124 |
| 章節2 | `chapterIdx=2,townId=2,chapterName=복면 K`（蒙面 K） | **收錄 Q131/132 與 Q133–142**；跨村過渡提前屬新章 |
| 章節3 邊界 | `chapterIdx=3,townId=3,chapterName=아델린 여신의 이야기` | **Q143/144 雖 QuestInfo `town=2`，Chapter 已切第3章**，後接 Quest65 `town=3` |
| NPC IDs | `giver`, `finisher` 由 QuestInfo；NPC 表中有 ID→韓文名 | NPC 名稱僅為角色索引；不表示特定 Server 場景 object 已生成 |
| 劇情 scene IDs | Table CHAPTER ordered `sceneIdx`；Event `(questIdx,sceneIdx)→funcName` | 這是原始資源順序，**不是**自動 `sceneIdx++` 的 Client 算法，也不是原版 Server 必發的 0x47 |

## C. 精確可追溯的主線鏈（25 個）

本表每列的 `Demands`、原始名稱、type、town、level、giver、finisher、field 都直接來自 `Table/QuestInfo.xml`。**沒有使用主觀數字排序取代前置查驗**；25 列逐一驗證「當前唯一 Demand = 前一列 ID」（第一列14無 Demand）。`field` 是 Quest record 欄位，不自行稱為傳輸或地圖 ID。

| # | Quest ID | 韓文原名（工作譯名） | Demand | type / town / level / field | 接取 NPC → 交付 NPC | 章節 / Scene 數 |
|---:|---:|---|---:|---|---|---|
| 1 | **14** | 튜토리얼-이실리아（教學：伊希莉亞） | — | `3/0/1/18` | 10027 → 10027 | Chapter —／0 scene |
| 2 | **16** | 튜토리얼-핑코파파（教學：平可爸爸） | 14 | `2/0/1/—` | 10027 → 10027 | Chapter —／0 scene |
| 3 | **15** | 핀더스 마을로（前往馮德斯村） | 16 | `2/5/1/19` | 10338 → 10338 | Chapter 1／4 scene |
| 4 | **117** | 사소한 소동（一場小騷動） | 15 | `2/1/1/—` | 10002 → 10002 | Chapter 1／1 scene |
| 5 | **118** | 유리와 라제드（優莉與拉傑德） | 117 | `2/1/5/28` | 10047 → 10047 | Chapter 1／1 scene |
| 6 | **119** | 유리와 라제드 (전투)（優莉與拉傑德（戰鬥）） | 118 | `2/1/5/26` | 10047 → 10047 | Chapter 1／5 scene |
| 7 | **120** | 세네레프 산의 귀신 나무（塞涅雷夫山的鬼樹） | 119 | `2/1/8/—` | 10008 → 10008 | Chapter 1／3 scene |
| 8 | **121** | 라제드 구출（救出拉傑德） | 120 | `2/1/9/—` | 10002 → 10002 | Chapter 1／1 scene |
| 9 | **122** | 라제드 구출 (전투)（救出拉傑德（戰鬥）） | 121 | `2/1/8/27` | 10002 → 10002 | Chapter 1／5 scene |
| 10 | **123** | 의식의 밤（儀式之夜） | 122 | `2/1/9/—` | 10048 → 10048 | Chapter 1／1 scene |
| 11 | **124** | 의식의 밤 (전투)（儀式之夜（戰鬥）） | 123 | `2/1/9/17` | 10048 → 10048 | Chapter 1／7 scene |
| 12 | **131** | 알스메르 마을 가는 길（前往爾斯梅勒村的道路） | 124 | `2/1/10/—` | 10002 → 10002 | Chapter 2／1 scene |
| 13 | **132** | 알스메르 마을 가는 길 (전투)（前往爾斯梅勒村的道路（戰鬥）） | 131 | `2/1/10/28` | 10002 → 10002 | Chapter 2／5 scene |
| 14 | **133** | 정의의 사도（正義的使者） | 132 | `2/2/10/21` | 10053 → 10005 | Chapter 2／1 scene |
| 15 | **134** | 정의의 사도 (전투)（正義的使者（戰鬥）） | 133 | `2/2/10/21` | 10053 → 10005 | Chapter 2／2 scene |
| 16 | **135** | 살로만 족의 습격（薩洛曼族的襲擊） | 134 | `2/2/12/29` | 10053 → 10005 | Chapter 2／2 scene |
| 17 | **136** | 살로만 족의 습격 (전투)（薩洛曼族的襲擊（戰鬥）） | 135 | `2/2/12/29` | 10053 → 10005 | Chapter 2／2 scene |
| 18 | **137** | 보리 창고 탈환（奪回大麥倉庫） | 136 | `2/2/13/30` | 10005 → 10005 | Chapter 2／1 scene |
| 19 | **138** | 보리 창고 탈환 (전투)（奪回大麥倉庫（戰鬥）） | 137 | `2/2/13/30` | 10005 → 10005 | Chapter 2／6 scene |
| 20 | **139** | 어부지리（漁翁得利） | 138 | `2/2/14/—` | 10053 → 10005 | Chapter 2／3 scene |
| 21 | **140** | 어부지리 (전투)（漁翁得利（戰鬥）） | 139 | `2/2/14/31` | 10053 → 10005 | Chapter 2／3 scene |
| 22 | **141** | 살로만 행진곡（薩洛曼進行曲） | 140 | `2/2/15/—` | 10005 → 10005 | Chapter 2／1 scene |
| 23 | **142** | 살로만 행진곡 (전투)（薩洛曼進行曲（戰鬥）） | 141 | `2/2/15/20` | 10005 → 10005 | Chapter 2／8 scene |
| 24 | **143** | 로트루아 가는 길（前往洛特魯亞之路） | 142 | `2/2/15/—` | 10012 → 10012 | Chapter 3／1 scene |
| 25 | **144** | 로트루아 가는 길 (전투)（前往洛特魯亞之路（戰鬥）） | 143 | `2/2/15/22` | 10012 → 10012 | Chapter 3／5 scene |

### C1. 對玩家而言的可辨識階段

1. **教學**：14 伊希莉亞 → 16 平可爸爸 → 15 前往馮德斯村；Quest15 必須具備 key16 的先決條件，原始型別為 type2；NPC 10338 是 `테티스`（泰蒂斯，工作譯名），不是 NPC10027。
2. **馮德斯章**：117 小騷動 → 118/119 優莉與拉傑德（對話／戰鬥）→ 120 塞涅雷夫山的鬼樹 → 121/122 救出拉傑德（對話／戰鬥）→ 123/124 儀式之夜（對話／戰鬥）。123/124 的 NPC10048 與 118/119 的 NPC10047 名稱都寫 `유리`（優莉），**不可因同名合併 ID**。
3. **前往爾斯梅勒（跨村）**：131「前往爾斯梅勒村的道路」與 132 同名戰鬥；QuestInfo 都是 town1，但 Chapter table 已把它們放到爾斯梅勒第2章；下一個 Quest 133 才是 town2 的首筆主線。
4. **爾斯梅勒本章（若使用者所說「到爾斯梅勒」包含該章）**：133/134 正義的使者 → 135/136 薩洛曼族襲擊 → 137/138 奪回大麥倉庫 → 139/140 漁翁得利 → 141/142 薩洛曼進行曲。NPC 10053→10005 的跨 NPC 交付在133/134/135/136/139/140等已由 XML 提供，不能固定只向接取 NPC 交付。
5. **離開範圍的下一地區**：143/144 前往洛特魯亞（QuestInfo town2，但 chapter3），其後 65「與邁達斯初次相遇」Demand144、town3。只為標示本研究的明確終點，不將洛特魯亞後續任務混入此範圍。

### C2. 章節與每筆劇情／場景函式（完整，有順序）

原始 `Table/SceneList.xml` 的 `SCENE` 順序與 `Event/SceneList.xml` 的 funcName 作嚴格 ID 對照。Quest14/16 在兩份 SceneList **沒有相應配對**，不能據此宣稱沒有任何 tutorial UI/Lua；教程可能採其他資源入口。

#### 教學→馮德斯（15）

- **Quest14**：Table Chapter / Event SceneList 無配對；有其它任務記錄，須分開。
- **Quest16**：Table Chapter / Event SceneList 無配對；有其它任務記錄，須分開。
- **Quest15**（Chapter 1, 의식의 밤；4 scenes）：`1:Square_Tutorial01` → `2:scenario_tuto1_1` → `3:pindos_talkevent` → `4:scenario_tuto2_1`。

#### 馮德斯章節

- **Quest117**（Chapter 1, 의식의 밤；1 scenes）：`1:Phindous_LittleTrouble`。
- **Quest118**（Chapter 1, 의식의 밤；1 scenes）：`1:Phindous_YuriandRazed`。
- **Quest119**（Chapter 1, 의식의 밤；5 scenes）：`1:Phindous_YuriandRazed_Blank` → `2:Phindous_YuriandRazed_Stage` → `3:Phindous_YuriandRazed_Boss` → `4:Phindous_YuriandRazed_BossClear` → `5:Phindous_YuriandRazed_After`。
- **Quest120**（Chapter 1, 의식의 밤；3 scenes）：`1:Phindous_Senerep_TalkEvent` → `2:Phindous_Senerep_TalkEvent2` → `3:Phindous_Senerep_TalkEvent3`。
- **Quest121**（Chapter 1, 의식의 밤；1 scenes）：`1:Phindous_RazedSave_TalkEvent`。
- **Quest122**（Chapter 1, 의식의 밤；5 scenes）：`1:Phindous_RazedSave_Blank` → `2:Phindous_RazedSave_Stage` → `3:Phindous_RazedSave_Boss` → `4:Phindous_RazedSave_BossClear` → `5:Phindous_RazedSave_After`。
- **Quest123**（Chapter 1, 의식의 밤；1 scenes）：`1:Phindous_NightofRitual_Talk_Event`。
- **Quest124**（Chapter 1, 의식의 밤；7 scenes）：`1:Phindous_NightofRitual_Blank` → `2:Phindous_NightofRitual_Stage` → `3:Phindous_NightofRitual_Stage02` → `4:Phindous_NightofRitual_Stage03` → `5:Phindous_NightofRitual_Boss` → `6:Phindous_NightofRitual_Clear` → `7:Phindous_NightofRitual_After`。

#### 跨村與爾斯梅勒

- **Quest131**（Chapter 2, 복면 K；1 scenes）：`1:Phindous_pathofAlsmeer_Talkevent`。
- **Quest132**（Chapter 2, 복면 K；5 scenes）：`1:Phindous_pathofAlsmeer_Blank` → `2:Phindous_pathofAlsmeer_Stage` → `3:Phindous_pathofAlsmeer_Boss` → `4:Phindous_pathofAlsmeer_Boss_Clear` → `5:Phindous_pathofAlsmeer_Boss_After`。
- **Quest133**（Chapter 2, 복면 K；1 scenes）：`1:Alsmeer_Justice_Talk01`。
- **Quest134**（Chapter 2, 복면 K；2 scenes）：`1:Alsmeer_Justice_Blank` → `2:Alsmeer_Justice_Clear`。
- **Quest135**（Chapter 2, 복면 K；2 scenes）：`1:Alsmeer_SalomanAttack_Talkevent` → `2:Alsmeer_SalomanAttack_Talkevent2`。
- **Quest136**（Chapter 2, 복면 K；2 scenes）：`1:Alsmeer_SalomanAttack_Blank` → `2:Alsmeer_SalomanAttack_Clear`。
- **Quest137**（Chapter 2, 복면 K；1 scenes）：`1:Alsmeer_Barley_TalkEvent`。
- **Quest138**（Chapter 2, 복면 K；6 scenes）：`1:Alsmeer_Barley_Blank` → `2:Alsmeer_Barley_Stage01` → `3:Alsmeer_Barley_Stage02` → `4:Alsmeer_Barley_Boss` → `5:Alsmeer_Barley_Boss_Clear` → `6:Alsmeer_Barley_Boss_After`。
- **Quest139**（Chapter 2, 복면 K；3 scenes）：`1:Alsmeer_Fish_TalkEvent1` → `2:Alsmeer_Fish_TalkEvent2` → `3:Alsmeer_Fish_TalkEvent3`。
- **Quest140**（Chapter 2, 복면 K；3 scenes）：`1:Alsmeer_Fish_Blank` → `2:Alsmeer_Fish_Stage01` → `3:Alsmeer_Fish_Clear`。
- **Quest141**（Chapter 2, 복면 K；1 scenes）：`1:Alsmeer_Donjuan_Talk01`。
- **Quest142**（Chapter 2, 복면 K；8 scenes）：`1:Alsmeer_Donjuan_Blank` → `2:Alsmeer_Donjuan_Stage01` → `3:Alsmeer_Donjuan_Stage02` → `4:Alsmeer_Donjuan_Stage03` → `5:Alsmeer_Donjuan_Stage04` → `6:Alsmeer_Donjuan_Boss` → `7:Alsmeer_Donjuan_Boss_Clear` → `8:Alsmeer_Donjuan_Boss_After`。

#### 下一村過渡（界線）

- **Quest143**（Chapter 3, 아델린 여신의 이야기；1 scenes）：`1:Alsmeer_PathofRotrua_TalkEvent`。
- **Quest144**（Chapter 3, 아델린 여신의 이야기；5 scenes）：`1:Alsmeer_PathofRotrua_Blank` → `2:Alsmeer_PathofRotrua_Stage01` → `3:Alsmeer_PathofRotrua_Stage02` → `4:Alsmeer_PathofRotrua_Boss` → `5:Alsmeer_PathofRotrua_After`。

## D. 教學額外 Quest 資源與「不構成有順序的需求鏈」

| ID | KR subject | type/town/level | Demand | 已有的 RewardsEtc 原始欄位 | 解讀 |
|---:|---|---|---|---|---|
| 1002 | 시놉시스 | `3/0/1` | 無 | — | 劇情前言 |
| 2742 | 튜토리얼-키보드입력 | `3/0/1` | 無 | type2=10 | 鍵盤操作 |
| 2743 | 튜토리얼-마우스입력 | `3/0/1` | 無 | type2=20 | 滑鼠操作 |
| 2744 | 튜토리얼-카메라 | `3/0/1` | 無 | type2=30 | 攝影機 |
| 2745 | 튜토리얼-캐릭터선택 | `3/0/1` | 無 | type2=40 | 角色切換 |
| 2746 | 튜토리얼-전투 | `3/0/1` | 無 | type2=50 | 戰鬥教學 |

- **重要反例**：以上六筆以及 Quest14 在 `QuestInfo.xml` 的 `<Demands>` 節點中並未構成 `1002→2742→...→14` 的顯式鏈，不能只根據任務 ID 或常識聲稱原版 Server 就照此順序發送。這類教學階段的實際切換需由 tutorial Lua/本地事件與 Server 進度驗證。
- `type=2` 代表 QuestInfo 分類；`AcceptAction.type=2`、TalkBox mode2、Reward.type=2 屬不同 namespace，禁止等值誤推。

## E. 交付者與具體 XML 屬性的工作明細（包含每筆獎勵）

| Quest | giver → finisher（NPC原名） | Level / Field | RewardsEtc 原始鍵值 | AcceptAction / CompleteAction XML |
|---:|---|---|---|---|
| 14 | `10027`（NPC 表中未索引；需另查 actor 資源） → `10027`（NPC 表中未索引；需另查 actor 資源） | `1` / `18` | — | A:{'type': '1'}；C:{'type': '1'} |
| 16 | `10027`（NPC 表中未索引；需另查 actor 資源） → `10027`（NPC 表中未索引；需另查 actor 資源） | `1` / `—` | `type2=50` | A:缺節點；C:缺節點 |
| 15 | `10338`（테티스） → `10338`（테티스） | `1` / `19` | `type2=2800`, `type4=468` | A:缺節點；C:缺節點 |
| 117 | `10002`（라제드） → `10002`（라제드） | `1` / `—` | `type2=710` | A:缺節點；C:缺節點 |
| 118 | `10047`（유리） → `10047`（유리） | `5` / `28` | — | A:缺節點；C:缺節點 |
| 119 | `10047`（유리） → `10047`（유리） | `5` / `26` | `type2=5850`, `type3=40`, `type4=900` | A:缺節點；C:缺節點 |
| 120 | `10008`（한슨） → `10008`（한슨） | `8` / `—` | — | A:缺節點；C:缺節點 |
| 121 | `10002`（라제드） → `10002`（라제드） | `9` / `—` | — | A:缺節點；C:缺節點 |
| 122 | `10002`（라제드） → `10002`（라제드） | `8` / `27` | `type2=9686`, `type3=40`, `type4=918` | A:缺節點；C:缺節點 |
| 123 | `10048`（유리） → `10048`（유리） | `9` / `—` | — | A:缺節點；C:缺節點 |
| 124 | `10048`（유리） → `10048`（유리） | `9` / `17` | `type2=13086`, `type3=40`, `type4=1440` | A:缺節點；C:缺節點 |
| 131 | `10002`（라제드） → `10002`（라제드） | `10` / `—` | — | A:缺節點；C:缺節點 |
| 132 | `10002`（라제드） → `10002`（라제드） | `10` / `28` | `type2=15850`, `type3=40`, `type4=1440` | A:缺節點；C:缺節點 |
| 133 | `10053`（쿠치） → `10005`（케인） | `10` / `21` | — | A:缺節點；C:缺節點 |
| 134 | `10053`（쿠치） → `10005`（케인） | `10` / `21` | `type2=19210`, `type4=1548` | A:缺節點；C:缺節點 |
| 135 | `10053`（쿠치） → `10005`（케인） | `12` / `29` | — | A:缺節點；C:缺節點 |
| 136 | `10053`（쿠치） → `10005`（케인） | `12` / `29` | `type2=27690`, `type3=100`, `type4=1656` | A:缺節點；C:缺節點 |
| 137 | `10005`（케인） → `10005`（케인） | `13` / `30` | — | A:缺節點；C:缺節點 |
| 138 | `10005`（케인） → `10005`（케인） | `13` / `30` | `type2=33640`, `type3=150`, `type4=1764` | A:缺節點；C:缺節點 |
| 139 | `10053`（쿠치） → `10005`（케인） | `14` / `—` | — | A:缺節點；C:缺節點 |
| 140 | `10053`（쿠치） → `10005`（케인） | `14` / `31` | `type2=39210`, `type3=150`, `type4=1872` | A:缺節點；C:缺節點 |
| 141 | `10005`（케인） → `10005`（케인） | `15` / `—` | — | A:缺節點；C:缺節點 |
| 142 | `10005`（케인） → `10005`（케인） | `15` / `20` | `type2=45720`, `type3=150`, `type4=1980` | A:缺節點；C:缺節點 |
| 143 | `10012`（데이지） → `10012`（데이지） | `15` / `—` | — | A:缺節點；C:缺節點 |
| 144 | `10012`（데이지） → `10012`（데이지） | `15` / `22` | `type2=35024`, `type3=150`, `type4=1980` | A:缺節點；C:缺節點 |

**不能把 `Reward.type` 猜成金錢／經驗值等遊戲 UI 敘述**：此處保留原始 type 與 value，待 T16 與 Server SPEC 以真正 consumer/規則定義，不能直接稱 Server 已發獎。任務 XML 可有無 `<RewardsEtc>`，無節點≠官方永遠無其他事件獎勵。

## F. 原始 Table 解碼後對 T16-125～135 的重要勘誤／缺口解除

1. **Quest15 獎勵不再僅是前段摘錄的待證數字**：完整 `QuestInfo.xml` 原件中 `<RewardsEtc id="15"><Reward type="2" value="2800"/><Reward type="4" value="468"/></RewardsEtc>` 直接存在；原始 bytes 定位由 EX block raw `0x425010`、解壓 SHA 驗證。此主張仍只限 XML，不是 Server 已給獎。
2. **Quest15 的 `AcceptAction/CompleteAction`：XML 兩者都缺節點**；本範圍絕大部分 type2 劇情任務亦同。先前 T16-134/135 把 Q15 action type / param3 標為需解包確認，本段可確認**原始 XML 沒有指定 `type=2,param=3` 的 action node**。因此不能再用「Quest15 XML 可能含 CompleteAction type2,param3」當成已存在的 scene3 直接觸發證據。要進一步判定 Client 記錄的預設初始化值，仍需看原生 parser/ctor；**缺 XML node 不等於所有 runtime 分支不可能透過其他 writer/0x47/章節入口觸發**。
3. **Table Chapter row 的真實值與順序已實際取得**：Chapter1 `(questId15)=[1,2,3,4]`，Chapter2 `(questId131)=[1]`、`132=[1,2,3,4,5]`、`133=[1]`；Chapter3 `(questId143)=[1]`、`144=[1,2,3,4,5]`。先前 T16-129～135 的「Table SceneList rows 仍未知」**對這些已解碼 row 可標資源層解除**，但原始 Server／Client runtime 是否按順序啟動仍未證。
4. **Chapter 與 QuestInfo 的 town 分開**：Q15 quest town5 vs Chapter town1；Q131/132 quest town1 vs Chapter town2；Q143/144 quest town2 vs Chapter town3。這三種都是**直接資料反例**，不能用 town ID 或 ChapterID 一欄代替其他欄。
5. **官方韓文名稱與 NPC 身份清晰**：Town1 `핀더스` / `Phindous`、Town2 `알스메르` / `Alsmeer`；NPC10338 `테티스`，NPC10002 `라제드`，NPC10047/10048 `유리`，NPC10053 `쿠치`、NPC10005 `케인`。教學 giver10027 在本次 NPCTABLE root 中未找到同 ID，不可因缺表就斷言 Client 不會生成該物件。
6. **劇情場景與任務完成仍非同一事件**：Quest15 Scene3 name=`pindos_talkevent`，已可用兩張表交叉確認 `(15,3)` 的正確映射；但 `S→C 0x46(15,0)` 的 native handler 不直接代表執行 Scene3。參照 T16-134/135 的獨立 0x40/45/47/Chapter FIRST/NEXT 入口。

## G. 與 Client native handler 的有限契約（引用既有 T16 原稿，本站再抽取代表性 BIN bytes）

| 玩家階段 | Client 已確認／可條件式接收 | C→S 條件式入口 | Server 待開發與不可猜測之處 |
|---|---|---|---|
| Quest14 解鎖16 | prereq `0x74(key14)` append / `0x6F` snapshot → `0x500240` 重建 | NPC10027 `0x1C`／controller `0x3F` gate、UI 通知 | Quest14 何時達標由 Server 定義；不把客戶端已擁有 key14 當成 DB 完成證明 |
| Quest16 解鎖15 | `0x74(key16)`／`0x6F` prerequisite；Town/world selector `0x38` 與 Q15 demand16/level/exclusion 並行 | NPC10338 偵測 event／selector / `0x1C`＋條件 0x3F | Server 何時讓角色處於 square/town5、怎樣回覆要有相容決策；實際 packet pairing 未證 |
| Q15 與往後每筆 Quest 的 NPC 顯示與接取 | `0x40(QID,state0)` 產 F438B → mode2 TalkBox、exclusion/候選重建（依 record/type/狀態 gate） | 原生 type2 NPC selector → `0x561760(id,1)` 與有條件出站；實際每一個 NPC 製作還需現場 actor | 不能憑 Demands 就保證 NPC 出現，也不能直接把每筆主線都當 `0x40` 必然返回 |
| 任務交付／後續解鎖 | `0x46(QID,substate0)` 可移 exclusion、依 subtype gate 追加 key 與 F438C mode3；`0x74`、`0x6F` 對 prereq 另有不同寫入 | 上游擊殺/關卡成功的完成意圖與 Server ACK 未由 Quest XML 證實 | Reward/戰鬥結算/重登持久化由 Server＋T14/T15；`0x46` 不直接等同任務獎勵交易 |
| 劇情 scene | `0x47(primary,secondary)→0x561760`，本地章節 FIRST `0x47E890`、NEXT `0x47E640`，`0x565720` 命中 Event 雙鍵才載入 Lua | 本地 chapter event、獨立入站 scene key、少數 AcceptAction/CompleteAction descriptor 分支皆需各自 gate | 即使 Table 有 [1,2,3,4] 也不等於 Server 必照順序給 `0x47`；Client scene player-visible 效果待實機驗證 |
| 跨村與重登入口 | Q131/132 仍 `town=1`、Q133 才 `town=2`，chapter 早已第2章 | T03/T07 登入/換圖和 scene ownership 的實際收發 | 需要 Server 自行決定真正傳送 town／map、首次進村與斷線恢復；不假設 Quest132完成瞬間客戶端無條件換圖 |

### G1. 原生入口可用的假設式 application payload 範例（**測試向量，不是抓包**）

- `74 00 7C 00`：向本地 prerequisite vector 提交 key124 的假設式 app 資料；代表進入 131 可接取所需的一項條件，另需 town/level/exclusion。不得稱官方實際傳此位元組序列。
- `74 00 84 00`：key132 使 Quest133 demand132 具備可評估條件；`0x6F` snapshot 可能完整替換先前 prerequisite，順序/Server 策略不得臆造。
- `47 00 84 00 01 00`：將 pair `(132,1)` 提交 scene controller 的**人造 6-byte application payload**，前提是 controller gate、場景資源皆有效；不能宣稱這一定是官服在 Quest132 通關後的原始回覆。
- Q15 的合成 `47 00 0F 00 03 00` 同理只測 `(15,3)` scene key，`0x46(15,0)` 與 `0x47(15,3)` 不屬同一 opcode。

## H. Server / S00 交接需求候選（**非正式 REQ 號、非 S00 核准**）

| 工作包候選 | 玩家需求 | 已確認 Client 資料 | 尚缺／驗收 |
|---|---|---|---|
| Quest 主線鏈與前置計算 | 玩家只能在符合需求後看到下一條主線 | 本段 25 節點 `Demands` 與 `type/town/level/giver/finisher` | Server 進度 authority、level gate 實際條件、發 prerequisite snapshot/delta 的時機 |
| Quest NPC/任務卡/UI | 正確 NPC 接/交，斷線後狀態一致 | 25 列 giver/finisher、多名同名 NPC 不同 ID | Actor spawn/visibility、C2S request→S2C response/拒絕、UI mode2/mode3 實機 |
| 關卡任務與狀態 | 戰鬥任務完成解鎖下段 | 任務 subject `(전투)`、field、Chapter scenes | T14 outcome/wave、持久化與 replay-safe award；不可只靠文字「戰鬥」聲稱 Win 判定 |
| 劇情安排與 chapter 交接 | 特定任務顯示其對話／過場 | Table Chapter scene index 與 Event funcName 完整對照 | 0x47/章節本地 event實際觸發、busy/skip/abort、跨村 return／camera/UI cleanup |
| 資源資料品質驗收 | 防止從舊摘要把 action/reward 值猜錯 | EX 正式解出 4 個核心 XML，hash 可重現 | 補 T01 主張級審核，不得把資源抽取直接升 FULL-PASS；中文翻譯需與正式在地化區分 |

既有 `design/requirements/index.json`、`research/requests/index.json`、`spec/` 仍是 S00 唯一流程。T16 原稿**僅提交候選與證據，不改主線 SPEC/GAP/REQ/RR 或 `native_complete`**。

## I. 有限正／負驗收矩陣（目前均 NOT_RUN）

| 編號 | 條件 | 應確認事項 | 狀態 |
|---|---|---|---|
| TQ-01 | Quest14 prerequisite 未存在 | Quest16 demand14 不通過；不能因同 giver NPC10027 自動解鎖 | `NOT_RUN` |
| TQ-02 | Append key14；level/town/exclusion 均通過 | Quest16 成為可接候選，仍需合法任務 UI producer | `NOT_RUN` |
| TQ-03 | 未有 key16，town=5 | Quest15 demand16 不通過 | `NOT_RUN` |
| TQ-04 | 已有 key16，但仍在錯誤 town | Quest15 不保證可接（town gate 不通過） | `NOT_RUN` |
| TQ-05 | Quest15 Record完整且收到0x40(15,state0) | F438B/mode2 應受 record/UI gate，檢查排除鍵和第一候選 | `NOT_RUN` |
| TQ-06 | Quest15 的 XML 查 AcceptAction.type2 | 找不到該節點；不能據此觸發 scene3 | `NOT_RUN` |
| TQ-07 | Quest15 完成通知0x46(state0) | 測試 exclusion/prereq/UI；不當作 scene3 直接命令 | `NOT_RUN` |
| TQ-08 | Chapter1 q15 scene vector | 1→2→3→4 是資源查表順序，不是固定 `+1` 程式碼 | `NOT_RUN` |
| TQ-09 | Q15 Event Scene3 存在／缺失 | 命中應選 pindos_talkevent；缺失不得用相似腳本替代 | `NOT_RUN` |
| TQ-10 | Quest117 prerequisite 15 不存在 | 進村時不能無前置就顯示完整可接 Quest117 | `NOT_RUN` |
| TQ-11 | Quest118/119 NPC10047；123/124 NPC10048 | 同名 유리 但不同 NPC IDs，不能硬合併 | `NOT_RUN` |
| TQ-12 | Quest124 完成後 key124 有／無 | 決定 Quest131 demand124 是否通過，另加 town/level/exclusion | `NOT_RUN` |
| TQ-13 | Quest131/132 town1+chapter2 | town 欄位與 chapter/scene key 不等同 | `NOT_RUN` |
| TQ-14 | Quest132 完成且準備 Quest133 | 確認 Server 權威 town2、NPC10053 spawn；不是本地資源自動換村 | `NOT_RUN` |
| TQ-15 | Quest133/134 giver10053 finisher10005 | 能從庫琪接，向凱恩交，不誤用同一 NPC | `NOT_RUN` |
| TQ-16 | Q136/138/140/142 戰鬥關卡 | 由 T14 結算/Server authority 決定成功，不能只用場景 script return | `NOT_RUN` |
| TQ-17 | Chapter2 數列 q132(1..5)、q142(1..8) | FIRST/NEXT 讀實際 ordered vector，並測末尾與 miss | `NOT_RUN` |
| TQ-18 | Q142→143→144 與 Q65 | quest town2但 Chapter3 在143/144；Q65 demand144 + town3 | `NOT_RUN` |
| TQ-19 | 0x6F snapshot 覆蓋0x74追加結果 | 驗證 prerequisite snapshot/delta 的一致性及重登恢復 | `NOT_RUN` |
| TQ-20 | 劇情 busy / miss / cancel | 不能保證 scene key 寫入或 UI/coroutine 已復原，需測 0x6EDB60 等 gate | `NOT_RUN` |

## J. 四類未解與解除證據（不因缺官方 Server 而停止 Client 原生可做部分）

- **Client 待逆向**：NPC actor10027 來源與教學 1002/2742–2746 實際排程；每個村莊 NPC live spawn/對話 event 是否進同一 `0x1C/0x3F`；完整劇情 controller `0x6EDB60` busy/deferred、`0x565720` loader 在失敗/取消時之清理；`0x46` type2 subtype1 時的完整業務 UI；XML node缺省時 parser/ctor 所寫 action descriptor 欄位。**本段已把 QuestInfo/Chapter SceneList 的原始 row 缺口解掉，不能在後續重複列「仍無表」**。
- **Server 待開發**：二十五筆主線的進度、任務/角色等級、前置 key、支線/主線資格、cross-village checkpoint、戰鬥完成事件、獎勵／防重交易、角色持久化與 S2C 訊息觸發策略。這是相容 Server 可自行設計的業務規則，不冒稱官服真實演算法。
- **跨 Task 待整合**：T02 app payload ↔ transport framing / lane、T07 chapter/scene/world ownership、T14 field戰鬥勝負與結算、T15 persistence、T03/04 新手首次角色與 town0→town1→town2 的換圖/選角及 session gating。
- **待遊玩驗證**：同一個新角色實際接取 Quest14/16/15 → Q117～144；資源已知的每一場景是否觸發；各 NPC 可點／可見、過場播放/跳過、任務成就重連與隔日恢復；既未執行原版 Client，也沒有官方/相容 Server 封包抓包，全部標 `NOT_RUN`。

## K. Native BIN 代表性指令切片（VA / raw offset / SHA256；BIN-first 交叉確認）

- PE32 `.text` ImageBase=`0x400000`、`.text VA=0x401000`、file pointer=`0x400`，所以本章限定 `.text raw = VA - 0x400C00`。所列 disassembly 是直接從本次原始 `Tartaros.bin` 取 slice，使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=VA`；**不代表全部 CFG 已獨立 FULL-PASS**。
### N01. Quest owner 候選重建入口
- VA `[0x500240,0x5002A8)`；raw `[0xFF640,0xFF6A8)`；104 bytes；SHA256 `b4cad2576417522405c8961c1e1c1bc750a114153706aeaec71b702610cfbab9`。
```asm

```

### N02. Quest type2 selector/candidate gate
- VA `[0x500A00,0x500A70)`；raw `[0xFFE00,0xFFE70)`；112 bytes；SHA256 `374cd4f242e8413d07fc5f2ac7de53c39e297dcf13d607946cb4d47d9e340fd0`。
```asm

```

### N03. 0x40 入站 quest 狀態 handler
- VA `[0x502270,0x5022E0)`；raw `[0x101670,0x1016E0)`；112 bytes；SHA256 `93b283afd834f1d50ace19907a797355b874dc9ec3d2c9b27541a4eb56b8c8a5`。
```asm

```

### N04. 0x46 完成狀態 handler
- VA `[0x502B40,0x502BC0)`；raw `[0x101F40,0x101FC0)`；128 bytes；SHA256 `76dcae1b6a347e42aa9332be9ca68728064f27b784e1abfe8929e614afff25c7`。
```asm

```

### N05. 0x47 scene 兩鍵 handler
- VA `[0x503040,0x5030C0)`；raw `[0x102440,0x1024C0)`；128 bytes；SHA256 `142d0323b1f076ba219871090580d380c799a152d4367177598342f586aaa23f`。
```asm

```

### N06. 0x74 prerequisite append handler
- VA `[0x503400,0x50345A)`；raw `[0x102800,0x10285A)`；90 bytes；SHA256 `00331fa2d02668da4e70c1ad58724f195425b5df3e2ee1c367df2c19a3c59efe`。
```asm

```

### N07. 0x6F snapshot 入站 handler
- VA `[0x503C70,0x503CD0)`；raw `[0x103070,0x1030D0)`；96 bytes；SHA256 `5c6b87c6fe2b1fb23f13750b083af7c445e1784ce66d67ab52869e0f70567ccf`。
```asm

```

### N08. Chapter FIRST selector
- VA `[0x47E890,0x47E908)`；raw `[0x7DC90,0x7DD08)`；120 bytes；SHA256 `3dd76f4d19fc3ceb6165116a24327d7c87fcd24d4f9c466545bec592394454d4`。
```asm

```

### N09. Chapter NEXT selector
- VA `[0x47E640,0x47E6B8)`；raw `[0x7DA40,0x7DAB8)`；120 bytes；SHA256 `9bacedf2bca2d5b18629bef63f10bc8c0ee3a9af88c54c48fcc3274169cfcc58`。
```asm

```

### N10. Scene controller 接收 pair
- VA `[0x561760,0x5617F8)`；raw `[0x160B60,0x160BF8)`；152 bytes；SHA256 `498cb7037292b6966d486ad21dacb7f403792be28e91aa6d17f13a3c643f6cc8`。
```asm

```

### N11. Scene Lua loader entry
- VA `[0x565720,0x565790)`；raw `[0x164B20,0x164B90)`；112 bytes；SHA256 `9c15fc23278ff72a012e97760af7243046e2c73e959774dfaa3dc040c83e98c5`。
```asm

```

### N12. Quest NPC event to controller
- VA `[0x5B9340,0x5B93C0)`；raw `[0x1B8740,0x1B87C0)`；128 bytes；SHA256 `a0108729e5e2bce5be3bfd3b7fb6a090681760f963e867caa6a38d194e457e82`。
```asm

```

### 原始 Event Script header token 審計
- Quest15 `Event.stp` XOR-FF decoded raw `0x8c1c3e`：`-- Quest #15 / Scene #3 - Function pindos_talkevent`；後續200 decoded bytes SHA256 `2a5ae4ac764beb2aeec7522ab7947914c8af81a5300c36e8831921bcb582474d`。
- Quest15 `Event.stp` XOR-FF decoded raw `0x96883e`：`-- Quest #15 / Scene #2 - Function scenario_tuto1_1`；後續200 decoded bytes SHA256 `b376fd83fb6a2527897edf39cf9a721677f88479db517778a258ad6e0aa4fe3c`。
- Quest15 `Event.stp` XOR-FF decoded raw `0x96903e`：`-- Quest #15 / Scene #4 - Function scenario_tuto2_1`；後續200 decoded bytes SHA256 `00370eb399198af026f3e61e0887c060af9f4c4097f14b6840cb8dda351caea1`。
- Quest15 `Event.stp` XOR-FF decoded raw `0x96943e`：`-- Quest #15 / Scene #1 - Function Square_Tutorial01`；後續200 decoded bytes SHA256 `aaef74a92f3253037e158ac01f96c150da0f95563da36762af1a12cf05c70f71`。
- Quest117 `Event.stp` XOR-FF decoded raw `0x8b183e`：`-- Quest #117 / Scene #1 - Function Phindous_LittleTrouble`；後續200 decoded bytes SHA256 `c6b20b8868adb992c7715119be53040d4910c8633aebc7ccef9a2b0b5b47fc84`。
- Quest118 `Event.stp` XOR-FF decoded raw `0x8bdc3e`：`-- Quest #118 / Scene #1 - Function Phindous_YuriandRazed`；後續200 decoded bytes SHA256 `75f66ed6a9a77906091b0679e2233c659c7d2bfd59cb6b5d4e40ff695d468310`。
- Quest119 `Event.stp` XOR-FF decoded raw `0x8bec3e`：`-- Quest #119 / Scene #5 - Function Phindous_YuriandRazed_After`；後續200 decoded bytes SHA256 `76afc572474485b940d711d3145e965b1069211777ffc0311779b3cbb12f238e`。
- Quest119 `Event.stp` XOR-FF decoded raw `0x8bf43e`：`-- Quest #119 / Scene #1 - Function Phindous_YuriandRazed_Blank`；後續200 decoded bytes SHA256 `78aea9d0857c49ab72ff0c57375a09b547a01e3f950f85de3f7722db1ffba9de`。
- Quest119 `Event.stp` XOR-FF decoded raw `0x8bf83e`：`-- Quest #119 / Scene #3 - Function Phindous_YuriandRazed_Boss`；後續200 decoded bytes SHA256 `03e6aeb5735188eb1875d7e5742e255128f0abafd6a17e7bcf940d11cf679132`。
- Quest119 `Event.stp` XOR-FF decoded raw `0x8c003e`：`-- Quest #119 / Scene #4 - Function Phindous_YuriandRazed_BossClear`；後續200 decoded bytes SHA256 `328e0c48b18fd98b5be05deb98fd26c95aceb58768c462928bcb09aa237b3fa9`。
- Quest119 `Event.stp` XOR-FF decoded raw `0x8c083e`：`-- Quest #119 / Scene #2 - Function Phindous_YuriandRazed_Stage`；後續200 decoded bytes SHA256 `9139f1df819e40745a4dec559beaf9402ec84e9f518a15dbd35544cef8535347`。
- Quest122 `Event.stp` XOR-FF decoded raw `0x8b983e`：`-- Quest #122 / Scene #5 - Function Phindous_RazedSave_After`；後續200 decoded bytes SHA256 `d213043e309efb9de5aebfdf0e518343df45b3490f43e95dfc6717ecfc67815f`。
- Quest122 `Event.stp` XOR-FF decoded raw `0x8ba43e`：`-- Quest #122 / Scene #1 - Function Phindous_RazedSave_Blank`；後續200 decoded bytes SHA256 `e295da48fe196496956e2a1e8bfb58f0deeb37fbcea332782bff5243f6d81da1`。
- Quest122 `Event.stp` XOR-FF decoded raw `0x8ba83e`：`-- Quest #122 / Scene #3 - Function Phindous_RazedSave_Boss`；後續200 decoded bytes SHA256 `f239ba621f1e123cf31ade96027fe7147bffa894f631f368c57d82d95e04daf6`。
- Quest122 `Event.stp` XOR-FF decoded raw `0x8bb43e`：`-- Quest #122 / Scene #4 - Function Phindous_RazedSave_BossClear`；後續200 decoded bytes SHA256 `10f88323c9f6a4036f42d382b951177fc8fb872f8579d9bea98cd559d15d9e52`。
- Quest122 `Event.stp` XOR-FF decoded raw `0x8bb83e`：`-- Quest #122 / Scene #2 - Function Phindous_RazedSave_Stage`；後續200 decoded bytes SHA256 `3bd4928f1f70e89803d3869b207da5aa7f40c09bedd7310d488fdbb23961e791`。
- Quest124 `Event.stp` XOR-FF decoded raw `0x8b2c3e`：`-- Quest #124 / Scene #7 - Function Phindous_NightofRitual_After`；後續200 decoded bytes SHA256 `25120f736d71cfe0d145f25626637506ac5a2ac2da3eb18f7e666e9929c802b3`。
- Quest124 `Event.stp` XOR-FF decoded raw `0x8b343e`：`-- Quest #124 / Scene #1 - Function Phindous_NightofRitual_Blank`；後續200 decoded bytes SHA256 `06de694e69a90a51a4d868e5034549fe37b987b9026df5c576d9029968fdcfcd`。
- Quest124 `Event.stp` XOR-FF decoded raw `0x8b383e`：`-- Quest #124 / Scene #5 - Function Phindous_NightofRitual_Boss`；後續200 decoded bytes SHA256 `1f7d2e65a83aaad1b706bad5814cb083b72f3d3ec9da754422d9ed66d4dbb46a`。
- Quest124 `Event.stp` XOR-FF decoded raw `0x8b403e`：`-- Quest #124 / Scene #6 - Function Phindous_NightofRitual_Clear`；後續200 decoded bytes SHA256 `32c9f007d62c57adc8111381049a175e7493a6b6871ffb70ea0e56704dcce2c8`。
- Quest124 `Event.stp` XOR-FF decoded raw `0x8b483e`：`-- Quest #124 / Scene #2 - Function Phindous_NightofRitual_Stage`；後續200 decoded bytes SHA256 `1306e7b80078ba9a9c4bbdaedc5cde45cc9a247384691084027d619dd57bad46`。
- Quest124 `Event.stp` XOR-FF decoded raw `0x8b4c3e`：`-- Quest #124 / Scene #3 - Function Phindous_NightofRitual_Stage02`；後續200 decoded bytes SHA256 `075d2e9c36d6c837254dd50ef1b8ecf90a23467a01b0ad6ce769fa46bdbda012`。
- Quest124 `Event.stp` XOR-FF decoded raw `0x8b503e`：`-- Quest #124 / Scene #4 - Function Phindous_NightofRitual_Stage03`；後續200 decoded bytes SHA256 `bc7fcf331f84bf0b98092d629380ade3402ba244c7eff14e6b8c1a9533ece2b4`。
- Quest131 `Event.stp` XOR-FF decoded raw `0x8b903e`：`-- Quest #131 / Scene #1 - Function Phindous_pathofAlsmeer_Talkevent`；後續200 decoded bytes SHA256 `bd5d790f868b3c7afc156cbc03199e7505b635efb0230e43f5c6976b422fed6c`。
- Quest132 `Event.stp` XOR-FF decoded raw `0x8b603e`：`-- Quest #132 / Scene #1 - Function Phindous_pathofAlsmeer_Blank`；後續200 decoded bytes SHA256 `8cecfb85f11795860f4498416d38438614de8210a47e27bb4668065927c4a264`。
- Quest132 `Event.stp` XOR-FF decoded raw `0x8b643e`：`-- Quest #132 / Scene #3 - Function Phindous_pathofAlsmeer_Boss`；後續200 decoded bytes SHA256 `dca368c2cbafc19b5f1348e1470f5845674c73aa2daa9e1fbe799ec941460bee`。
- Quest132 `Event.stp` XOR-FF decoded raw `0x8b6c3e`：`-- Quest #132 / Scene #5 - Function Phindous_pathofAlsmeer_Boss_After`；後續200 decoded bytes SHA256 `b85df6533a13f0d205d0852022a857c7d7694743b2fb20d14d32409471ffdcad`。
- Quest132 `Event.stp` XOR-FF decoded raw `0x8b7c3e`：`-- Quest #132 / Scene #4 - Function Phindous_pathofAlsmeer_Boss_Clear`；後續200 decoded bytes SHA256 `1529a144a66350480ddd74153e7cef54186b41a696cebba5553218bb21b55377`。
- Quest132 `Event.stp` XOR-FF decoded raw `0x8b883e`：`-- Quest #132 / Scene #2 - Function Phindous_pathofAlsmeer_Stage`；後續200 decoded bytes SHA256 `f42edcdabe4ba37a21a5ea44a635dd7a51132df7229358da9c997b7e8f99c23d`。
- Quest133 `Event.stp` XOR-FF decoded raw `0x5c9c3e`：`-- Quest #133 / Scene #1 - Function Alsmeer_Justice_Talk01`；後續200 decoded bytes SHA256 `de84284827f102926587e725d51cbff681b50ab39da31dc51b54fb4a4964be39`。
- Quest142 `Event.stp` XOR-FF decoded raw `0x5be83e`：`-- Quest #142 / Scene #1 - Function Alsmeer_Donjuan_Blank`；後續200 decoded bytes SHA256 `ea382ae9811b123632af8f0aefa7480d85d6303ef70fed7e1d7048ae516dfbd0`。
- Quest142 `Event.stp` XOR-FF decoded raw `0x5bec3e`：`-- Quest #142 / Scene #6 - Function Alsmeer_Donjuan_Boss`；後續200 decoded bytes SHA256 `8fd2a957b91dd68ac37980eb89620d719f2e30186d71c856d292bff475e63c0d`。
- Quest142 `Event.stp` XOR-FF decoded raw `0x5bf43e`：`-- Quest #142 / Scene #8 - Function Alsmeer_Donjuan_Boss_After`；後續200 decoded bytes SHA256 `c3338a14703e4e10a5212659d242b4af69fcba563e34880f15acf8acb4854cde`。
- Quest142 `Event.stp` XOR-FF decoded raw `0x5c043e`：`-- Quest #142 / Scene #7 - Function Alsmeer_Donjuan_Boss_Clear`；後續200 decoded bytes SHA256 `54318543d0caf21b7cbad86f399f508921e863c1d6752d4e1a4eee29b2136c95`。
- Quest142 `Event.stp` XOR-FF decoded raw `0x5c0c3e`：`-- Quest #142 / Scene #2 - Function Alsmeer_Donjuan_Stage01`；後續200 decoded bytes SHA256 `07daea0ac88ec6339a7c8a3c4e1cc3c1c52ec744370476316c954d0d41e206db`。
- Quest142 `Event.stp` XOR-FF decoded raw `0x5c143e`：`-- Quest #142 / Scene #3 - Function Alsmeer_Donjuan_Stage02`；後續200 decoded bytes SHA256 `29a1582a09ad89212fcaf6edfba1d509d721428495db3c3256516026ccde61b4`。
- Quest142 `Event.stp` XOR-FF decoded raw `0x5c1c3e`：`-- Quest #142 / Scene #4 - Function Alsmeer_Donjuan_Stage03`；後續200 decoded bytes SHA256 `aad3e62179ca30a81ee2c0b46da31677f9c1d9b46b5c8c24dedc12afb0d0729c`。
- Quest142 `Event.stp` XOR-FF decoded raw `0x5c243e`：`-- Quest #142 / Scene #5 - Function Alsmeer_Donjuan_Stage04`；後續200 decoded bytes SHA256 `df4bb53e9d9055085e6d2f8c71e087e41844f1c2e26fc0c1d6c892e63d44db61`。
- Quest143 `Event.stp` XOR-FF decoded raw `0x5d003e`：`-- Quest #143 / Scene #1 - Function Alsmeer_PathofRotrua_TalkEvent`；後續200 decoded bytes SHA256 `4bfefb1ab54f8a624f60303d692cc4a4c62282e425eb1b447e2e97520fd06fcd`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5ca83e`：`-- Quest #144 / Scene #5 - Function Alsmeer_PathofRotrua_After`；後續200 decoded bytes SHA256 `80b55a894f1b747906f2579154633fbe5e508bb88f9662605f079c9de7c70fb9`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5cb03e`：`-- Quest #144 / Scene #1 - Function Alsmeer_PathofRotrua_Blank`；後續200 decoded bytes SHA256 `d11fd59e889fedd12181561ba3a319cd8cc6c4ffcc0ef716e8054980320a1f70`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5cb43e`：`-- Quest #144 / Scene #4 - Function Alsmeer_PathofRotrua_Boss`；後續200 decoded bytes SHA256 `bba4dc913961551d7c459c905361c00ced31a5089caefd18d28606c86a796d8a`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5ce03e`：`-- Quest #144 / Scene #5 - Function Alsmeer_PathofRotrua_Boss_After`；後續200 decoded bytes SHA256 `e51503851038238530b0da8b3d89207842e992d3a1ac86ec7c2a87706e8caffa`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5ce43e`：`-- Quest #144 / Scene #5 - Function Alsmeer_PathofRotrua_Ending01`；後續200 decoded bytes SHA256 `dfc975c87163c19f0acc5faf036226b7aa0836f04e16974ea1187f2eeb0f0015`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5ce83e`：`-- Quest #144 / Scene #6 - Function Alsmeer_PathofRotrua_Ending02`；後續200 decoded bytes SHA256 `6a7888ae88850a40d47f03ad52e5ac3cb0da2408e537fe19ed2eba5bd9d9a9e4`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5cec3e`：`-- Quest #144 / Scene #7 - Function Alsmeer_PathofRotrua_Ending03`；後續200 decoded bytes SHA256 `3e4ed381a6b8ad1b7f09f187bcfee3605e19700e7304edf3b98cdbbf6e2a903d`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5cf43e`：`-- Quest #144 / Scene #2 - Function Alsmeer_PathofRotrua_Stage01`；後續200 decoded bytes SHA256 `dd24e5b3f535511508222235166bac54a1b5fa3b53abf2fe8b3ec86777f2c372`。
- Quest144 `Event.stp` XOR-FF decoded raw `0x5cf83e`：`-- Quest #144 / Scene #3 - Function Alsmeer_PathofRotrua_Stage02`；後續200 decoded bytes SHA256 `147afc6abb17adaaca13f88f4901fb8dfb40e7ebed25d14093b619b753cf835e`。

## L. 完成判定與下一步

**本次 T16-136 所需的「新手教學到馮德斯／爾斯梅勒的主線任務資源清單、前置關係與場景表整理」已達成**：25 筆完整 `Demand` 單鏈及 6 筆獨立教學資源、兩村來源、Chapter1/2/3 邊界、每任務 QuestInfo 欄位與 NPC/獎勵、兩套 SceneList 精確鍵映射、EX decode 壓縮/解壓 hash 及 native handler 有界引用；本段工作主題是**資源內容的全量列舉與靜態契約**，不將未知的原版 Server 配對或實機遊玩冒稱已閉合。
- 若下一輪要達成「所有這些主線都能遊玩」，應依本清單逐筆追查 Q117～144 NPC actor/complete response 或先實作 S00 相容 Server 狀態資料源；對話層可分批實際驗收，不能一口氣把 25 筆列為在線通過。
- 來源優先級：原始 Table/Event EX 解壓成功 XML 與 BIN raw > 既有 T16-118～135／E06 分析 > Server compatible hypothesis。舊 T16-125/129/130/135 的「完整 QuestInfo/Chapter rows 未直接取得」可由本稿所列原始 SHA 精確限定地解除；不改寫或刪除舊稿。
- GitHub 目標：`we88ec3-prog/ttr_anal_multi`、`t16/roy/chatgpt-web`、只在本次授權範圍提交此 Markdown 原稿；**不改 `main`、不改 `task.json/native_complete`、不改 S00 台帳**。此文件最後由 GitHub 回傳真實 Commit/blob SHA 另行驗證。
