# T01 — 馮德斯 extra/roy1、extra/roy2、extra/roy3 原始資料與逐主張整合

**日期：2026-11-02，版本 KR。** 使用者授權 T01 驗證、整合與 Commit/Push；本篇屬 **R0 精確來源收件、R2 主張級有限複驗**。不是來源全文 `FULL-PASS`、S00 `APPROVED`、Server 已開發或原版 Client 遊玩驗收。無 Client 執行、附加、修改，無 Server、PR102 或私庫操作，沒有負向／重播／重登／併發／故障／壓測。AI／MEF 核心與連擊由 S00 規劃，不在此重新做。

## 1. 來源與整合方式

| 來源分支 | frozen HEAD | 範圍 | 新增檔案數 |
| --- | --- | --- | ---: |
| `extra/roy1` | `bcecd92294154fbeeafa1dfd8fc0f05403e0706b` | W1 批次01～04，Quest/Scene、對話索引、驗證腳本 | 12 |
| `extra/roy2` | `44e91057a9a3f9ba7a2fcac8c5bca53c7899f5bb` | W2 Field19/Case103 0022→0033，W5 角色/獎勵/技能群組補充 | 10 |
| `extra/roy3` | `cbb07b123395d884c8defaa74dae0d33367e46d9` | W3 Town1 正常場景／角色／NPC、完整村主線、BND v0/v2 | 19 |

**精確來源清單：** 同目錄 `T01-EXTRA-ROY123-SOURCE-MANIFEST-20261102.json`，共 **41 份**，逐件保存 repository path、原始 Git blob SHA-1、原始 UTF-8 SHA256、來源分支 HEAD 及來源登錄 `SRC-0654～SRC-0694`。原文、JSON、Python 與 CSV **按相同 Git blob 原樣加入**，不用工作副本覆蓋舊研究；保留 T01 前兩批報告。三個 extra 分支和最新 main 有大量無關舊 S00 差異，故本次僅整合其研究來源，不以整棵 extra branch tree 覆寫 S00 的 ADR、APPROVED、RR/owner。

## 2. 第一手原件核驗

本次只讀實際檔案 SHA256：`Tartaros.bin=9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（12,472,320B）、`Tartaros.exe=03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`、`Table.stp=09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`、`Event.stp=2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`、`BoundMap.stp=07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8`。

第一手獨立程式以 STPD/STPI 索引、EX mode1 XOR-1024 key＋zlib EOF/原長度重建 **8 個 Table、1 個 Event、3 個 BND** 成員，12 個成員 SHA256 與釘版證據相符，並從原始 `QuestInfo.xml` 和 `Event/SceneList.xml` 解析 12 個 Quest、35 個 `(questIdx,sceneIdx,funcName)`，Town1 NPC roster 9筆，Town1 Quest 共 **77筆（type1 67、type2 10）**。原始 BIN PE32/I386 ImageBase 0x400000，`.text VA 401000/raw 400`，依 VA−400C00 對指定指令錨點、switch/call/window 抽核。完整結果和限定證據見 `T01-EXTRA-ROY123-NATIVE-AUDIT-20261102.json`。

特別注意 W1 批次03一度宣稱 Event/SceneList 及 QuestTalk EX 成員未解；**這是早期批次的歷史限制**。T01 此輪已從本次提供的同 SHA 原始 STP 直接解出 `Event/SceneList.xml` SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`、`Table/SceneList.xml` SHA256 `1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037`、`QuestTalk.xml` SHA256 `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`；兩個同名 SceneList **不同 namespace／內容**。僅解除「原始 XML 尚無法直接解碼」的資料阻塞，不是確認全部 Quest callback 或 Scene 動態順序。

## 3. 逐主張審核與 S00 可實作界線

| ID／來源 | T01 實際核對、適用前提與反證 | 結論／Server 可用與未知 |
| --- | --- | --- |
| **PHI-W1-01** Quest15→117→…→132→133 | 原始 `QuestInfo.xml` 的 Demand 每筆單鏈精確符合；Quest15 前置16，Quest117 前置15；132 前置131、133 前置132。 | **R 資源已證**。可建 typed Quest prerequisite，但演出 Scene15/3 ≠ Q15 合法交付 ≠ Q117 接受；原版 Server 實際受理時序未知。 |
| **PHI-W1-02** Chapter／Scene | `Event/SceneList.xml` 對 Quest15、117–124、131–133 有 **35 筆**；章節 XML/SceneList/腳本名稱用原始 XML 調閱；編號 119/122/124/132 多 scene。 | **R 資源已證**；35 種 SceneScript 鍵不是官方逐段封包順序、獎勵或存檔。第一章結尾 Q124、全村開發驗收終點 Q132完成且Q133可接，後者屬 **S00 測試定義**。 |
| **PHI-W1-03** Town1 分類與 NPC | `_TownList.xml` Town1 九個 NPC 資源 ID `10001,10002,10003,10008,10013,10014,10047,10048,10015`；Quest117 giver10002、123/124 giver10048；Town1 Quest 77筆中 type2 為10筆。 | **R**，不等於九個實際 world entity ID、原服 NPC 座標或可互動 event selector。 |
| **PHI-W2-01** Field19 進場 | Quest15 `FieldId19`，`CaseId103`/MapFlow node1→Map191、node2→Map192；不同於 TownId1／Map182。 | **R + Client bounded**；004E/0028 opaque token、Formation/Scene/Ready 的正式先後和 node transition **UNKNOWN**，不能虛構封包。 |
| **PHI-W2-02** 一般結果與返回 | 原始 BIN 20/20 W2 關鍵前綴一致：`S2C0022/type0` result/UI storage 及 `C2S0033` local sender；0022 handler 至少讀到 22 bytes，0033 是 2-byte application，UI/scene/mode gate 仍必要。 | **N(partial)**。不把 0022 任意 DWORD 命名為勝敗/傷害官方 enum；0033 不含 Town/Map/QID，也不等於 Q15 reward/完成。 |
| **PHI-W2-03** 角色、獎勵與技能補證 | W5 33/33 原生錨點及六路 reward jump table 符合：type1→record+80, 2→+88, 3→+84, 4→+7C, 5→+8C, 6→+90；另選定指令支持 S2C005C role-attribute 與 S2C0127 skill-group callback。 | **N(partial)**；六個 type 值只是欄位映射，**業務名稱未知**。005C/0127 不等於角色招募／技能取得／裝備穿戴成功。Server 須另設 grant/persist 和 compatible sync，C2S transaction/ACK 仍 U。 |
| **PHI-W3-01** Town map/room | 原始 `_MapList.xml` `MapSelector182→town001D / town001.mef / town001`，TownId1/type1；既有 W3 有限 BIN `0099/type3→CMissionRoom` normal-room/owner/checkpoint 消費路線。 | **R + N(partial) 候選**：S00 可依 ADR 自選 `0099/type3 + 182` 相容方案，但 **官服 Town1 是否必用這組命令仍 UNKNOWN**；不能將 TownType1=controller kind1 當證明。 |
| **PHI-W3-02** Town1 / Field19 BND | 本輪從真 `BoundMap.stp` 解 3 個原始 BND，Town1 v0/grid768/world1536，Field19 191/192 各v2/grid768/world768；各兩層計數與 SHA、zlib EOF 全符合。雙層同時為零：Town1 **63091**、Map191 **72495**、Map192 **37530**。 | **R 已證 3 個靜態樣本**。原生 `830040` version==3→82F850，其餘→82F660 的限定 code windows 一致。可規劃 v0/v2 reader，但 **靜態可解 ≠ 原版 legal player spawn / pathfinder / 動態障礙**。 |
| **PHI-W3-03** Actor／NPC/互動 | W3 0007 Actor、0008 owner、000A binder、0027 checkpoint 是不同接收接口。T01 選定 nested `F43D9→001C` 12/12 native bytes 符合，event+F4 kind 和 +F6 selector 是另一物件 namespace。 | **N(partial)**：Town1 10002/10047 的實際 event kind/selector、world actor ID、NPC position/radius 都 U；不得一律發 `001C(kind3,resourceId)` 或點擊即結算。 |
| **PHI-W3-04** cutscene／合法出生 | W1 / W3 Quest15/3 `pindos_talkevent` 及 MapFlow graph `(360,372)` 為劇情／圖表素材；W3 以靜態 BND 生成 Town1 `(921,613)` 及九 NPC **deployable=false** 的集中候選。 | **R 素材、S 重建政策**：沒有原廠 Town1 出生點/九 NPC 擺位的認證；候選可記錄但必須 S00 明確採用並進行正常正流程人測。 |

## 4. 精確可開發 Server 需求（由 S00 確認，不在此批准）

| 需求候選 | 必要 Client/資源證據 | 仍缺的 Client 正向證據及可玩驗收 |
| --- | --- | --- |
| Q15→Town1→Q117／全村到Q132→Q133 | Quest 前置、Chapter/Scene、九 NPC 資源、Quest UI 本地 handler | 合法 Q15 結算、reward 持久化、每段任務接取/完成/獎勵時序、NPC click event與 S2C 0040/45/46/47 配對 |
| Field19/Case103/Map191→192/0022→0033 | 精確案例/地圖、兩張 v2 BND、結果/返回部分原生 | opaque 004E/0028、node 切換、場景狀態、回村目的地、Q15 是否完成的權威判定 |
| 正常 Town1/room/player/NPC/checkpoint | Map182/Town1、CMissionRoom route、0012/07/08/0A/27 有界 consumer、Town1 BND v0 | 官服 Town1 scene 對應、可行走合法 spawn、九 NPC 位置/事件/半徑、ready/loading 與實機互動 |
| reward/role/skills/items | 原始 raw Reward type 1..6 寫入欄位、005C role update、0127 skill group | 官方 reward business mapping、真招募/解鎖/背包/裝備交易及 UI、一次性 grant 與保存由 Server 設計 |

**隔離與結案：** T01 整合 **僅**完成精確來源收件與 selected 原生／資源 R2；source ledger 仍 `REGISTERED`，無任何新 `NATIVE_VERIFIED`、全文 `FULL_PASS`、`RR ACCEPTED` 或 `S00 APPROVED`。未操作 PR102、私庫、Server、原始 Client；AI/MEF 與連擊由 S00 處理。正常實機 Quest15→117→…→132→133 / NPC / 出入村均 **NOT_RUN**。先前 T01 batch01/02 原稿保留，後續待 S00 將限定證據採納為正式 SPEC/ADR/TEST。
