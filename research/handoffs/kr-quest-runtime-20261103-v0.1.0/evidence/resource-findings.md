# KR 任務原表與 typed ID：直接唯讀資料盤點

基準：`ttr_anal_multi` main `83959c0e7e65ab01348b285f03c285f487077610`。本交付配合 T16，沒有修改 owner／RR／Client／Server／原表，也沒有執行遊戲。這是資源內容核對，不是 T01 FULL-PASS、S00 規格核准或實機通關。

## 本次直接取得的來源

- `project_sources/07-Table.stp`，5,248,784 bytes，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。
- `project_sources/06-Event.stp`，11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 已核對，本子工作沒有新增 BIN 語義結論。

復用現行 `governance/inspect_tutorial_bounds_resource.py`（Git blob `e39cb00a9db90fbbea00844449b4b4da56520fae`）的 STPD 目錄／block 解讀，以及 `governance/inspect_first_tutorial_cluster.py`（blob `3a8d1507c35d356c3b395c171a85249765c6a6a5`）的 EX 解碼。原 STPD XOR-FF、EX key／zlib 解碼後逐檔核對大小；20 個選取 member 的原始 stored MD5 全部符合 STPD 記錄。35 個原始 `.seq` 的 MD5、作者 Quest/Scene key、Event SceneList funcName 互相符合。

既有 T16-136 原稿（blob `6a936c0a058f785b2a9299fbbde5857fe1d83603`）核心解壓 SHA 與本次重讀相同。本次不重做全量反編譯。

| 原表 member | SHA256 | 此次可供使用的範圍 |
|---|---|---|
| Table/QuestInfo.xml | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | 4,798 筆；選取20筆完整原始row與欄位 |
| Table/QuestTalk.xml | `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28` | 4,322筆；選取20個Quest均沒有對應row |
| Table/SceneList.xml | `1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037` | CHAPTERTABLE，25個Chapter；候選鏈所屬章節及ordered scene indices |
| Event/SceneList.xml | `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25` | SCENESET，1,687 rows／1,685 unique composite keys；所選35鍵無重複 |
| Table/npctable.xml | `a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d` | NPC定義／原名／TALKSET條件；不能當世界spawn |
| Table/_TownList.xml | `bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660` | Town0/1/2/5 的 NPC membership |
| Table/_TownTypeList.xml | `06b9a38619561c224db59f8ec8c47e578c255dba6c09146ddd8a3096d6c0c89c` | Town ID與TYPE原值 |
| Table/_CaseList.xml | `a6282323e287900512e515be01927ae3f75fa0c1540e0261473530eb0487043a` | Case ID/STAGE/MAPFLOW/CLUSTER；不能直接當Quest |
| Table/_MapList.xml | `cd47d8ca42f4297f6584a2c0c8807ae76352e3b353855b3989f660e64fd27f8c` | Map ID/TRIGGER/MAP/BOUND資源名 |
| Table/_PortalList.xml | `3140d4c0703181584de2dcab0a4a48c288cb21de887b692a2f584fc88639fa56` | 10 rows，5個portal特效ID × STATE(0/1) |
| Table/_ActorList.xml | `b01ae70817c79126b89292567e32d4c806c3ef31478b6a2eb96dcfd21e2c78f7` | OBJCATEGORY／ACTOR ID／PRE三個域共同定位資源變體 |
| Table/ItemTable2.xml | `7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2` | ITEM.item 定義；Q1的RewardsItem.idx=24958可查，非馮德斯主線獎勵 |

`source-members.json`保留 carrier hash、member id、raw body offset、EX stored size、decoded size、stored SHA/MD5。`quest-facts.json`和`scene-facts.json`保留精確XPath、解碼檔SHA、選取row的byte span與row SHA。原始完整XML只作本機中間資料，不納入使用者交付內容。

**名稱更正**：舊 T16-136 原稿以 `NpcInfoTable.xml (NPCTABLE)` 指稱該原件；本次直接 STPD 目錄確認實際 member 為 `Table/npctable.xml`，解壓 SHA相同。這是來源檔名修正，未改動既有原稿。

## 候選鏈逐項核對

下列順序來自逐筆 `Demands/Demand@id`，非 ID 遞增排序。`field=空白`表示原屬性缺失，不是 Field0。原表沒有寫本表任務的合法目標／次數／結算條件。

| Quest | Demand | Quest town | field | level | giver→finisher | Chapter / Chapter town | Scene IDs | Raw RewardsEtc |
|---:|---:|---:|---:|---:|---|---|---|---|
| 15 | 16 | 5 | 19 | 1 | 10338→10338 | 1 / 1 | 1,2,3,4 | type2=2800; type4=468 |
| 117 | 15 | 1 |  | 1 | 10002→10002 | 1 / 1 | 1 | type2=710 |
| 118 | 117 | 1 | 28 | 5 | 10047→10047 | 1 / 1 | 1 | 節點缺失 |
| 119 | 118 | 1 | 26 | 5 | 10047→10047 | 1 / 1 | 1,2,3,4,5 | type2=5850; type3=40; type4=900 |
| 120 | 119 | 1 |  | 8 | 10008→10008 | 1 / 1 | 1,2,3 | 節點缺失 |
| 121 | 120 | 1 |  | 9 | 10002→10002 | 1 / 1 | 1 | 節點缺失 |
| 122 | 121 | 1 | 27 | 8 | 10002→10002 | 1 / 1 | 1,2,3,4,5 | type2=9686; type3=40; type4=918 |
| 123 | 122 | 1 |  | 9 | 10048→10048 | 1 / 1 | 1 | 節點缺失 |
| 124 | 123 | 1 | 17 | 9 | 10048→10048 | 1 / 1 | 1..7 | type2=13086; type3=40; type4=1440 |
| 131 | 124 | 1 |  | 10 | 10002→10002 | 2 / 2 | 1 | 節點缺失 |
| 132 | 131 | 1 | 28 | 10 | 10002→10002 | 2 / 2 | 1..5 | type2=15850; type3=40; type4=1440 |
| 133 | 132 | 2 | 21 | 10 | 10053→10005 | 2 / 2 | 1 | 節點缺失 |

以上12筆全都缺 `<Contents>`、`<AcceptAction>`、`<CompleteAction>`，也沒有 `<RewardsItem>`。缺節點不等於零值／永無獎勵／永無劇情／已完成。Quest133 giver與finisher不同。Quest131/132仍在Town1，但Chapter2.townId為2；不可把 Chapter town當目前玩家所在地。

教學直接原表：Quest14 type3／town0／field18／level1／giver=finisher10027；AcceptAction.type1和CompleteAction.type1存在；沒有Demands。Quest16 type2／town0／level1／Demand14／giver=finisher10027；Raw Reward type2=50。1002、2742–2746各為type3／town0／level1／NPC10027，沒有Demands；2742..2746有Raw Reward type2=10,20,30,40,50。不能自行組成1002→2742→…→14。10027在完整Table/npctable.xml中缺row，Town0.NPCLIST為空，顯示教學不能直接套普通Town NPC清單。

## 至少兩種後續形態的實際結構

**Quest117**：沒有field屬性，Chapter1只列Scene1；Event composite key(117,1)為`Phindous_LittleTrouble`；SEQ載入`town001D.fld`，呼叫`OpenTalkScene(1,1)`至`(1,14)`，含NPC10002、10008、10003與演出角色。這支持「單段村內演出」資源形態，不支持「播完即達標／自動結算」。

**Quest119**：field26、Chapter1列五個scene；(119,1)Blank載入空字串；(119,2)Stage載入`mushroom01D.fld`；(119,3)Boss與(119,4)BossClear載入`mushroom12D.fld`；(119,5)After載入`town001D.fld`。原始Quest名稱含`(전투)`，Case107.STAGE=26及MAPFLOW/CLUSTER的映射可作資源join。這支持「有遭遇資源依賴且有多段演出」形態，沒有證明每段與地圖／清怪事件的官方配對。Blank scene必須能合法存在，不能強制每個scene有非空MapPath。

**Quest118是重要反例**：它只有村內一段scene，卻有field28；同field28也出現在Q132。Field28的Case109指向`CHART_S_pathofAlsmeer_01.xml`。因此「有field即立刻建立instance」、「field相同就是相同Quest」、「Scene名或Quest標題就能決定目標」均不成立。

## 原表能力與後端缺項

完整QuestInfo的已見結構：Quest固定有id/type/town/level/giver/finisher/subtype/subject，field可缺；Demands只列id；Contents只有Content.id及文字；AcceptAction有type、可選param；CompleteAction只有type；RewardsEtc包含Reward.type/value；RewardsItem有type及Item.idx/value。

- XML沒有AND／OR欄位。4,798筆中有6筆有兩個Demand（Q110、721、1012、2841、3080、3485）；列表本身不證明AND／OR。所選鏈每筆只有一個Demand。
- `Contents`顯示文字可以寫「擊殺30隻」等，但沒有結構化monster ID／count／scope欄位；例如Q1 Content1是韓文擊殺文字，Q3080有兩個Content。這些文字不能代替權威事件predicate。
- 沒有可直接證明角色限制／重複次數／每日reset／可選分支／隊伍共享計數／獎勵交易／進度保存的所選row欄位。這些須分列Server候選或待補Client consumer，不能以預設值帶過。
- Reward.type值1..6、RewardsItem.type值1/2、Quest.type值1/2/3、AcceptAction.type、NPC.TYPE與Actor.OBJCATEGORY是不同enum域。數字相同不可跨域解讀。
- `_PortalList.xml`末尾原始註解將ID定義為「effect ID」，STATE為1 Open／0 Close，FILE為EffectList PORTAL category檔名。這只證明特效表，不含portal位置／destination／按Z判定。
- `ActorResource(category,id,pre)`不是世界EntityId。Q119演出CreateObject有1001/1009/1022/1086等原型；不能把演出腳本物件數變成instance擊殺要求。
- 35個選取Scene composite key都唯一且能join；整個Event SceneList另有(0,249)/(0,250)重複列，位於本次範圍外。全村內容檢核器應檢查輸出內容鍵，不應假稱整個原表無重複。

## IDs與來源邊界

`typed-domain-facts.json`含所有選取typed row。Quest15→Field19是QuestInfo欄位；Field19與Case103.STAGE19相等是跨表候選join；Case103的MapFlow檔名直接來自Case表；Map191/192資源字串直接來自Map表；MapFlow具體node圖須引用W2／既有RESOURCE-BASELINE，不可用場景Lua中的LoadMap反推。

本次沒有上傳Field.stp，因而沒有直接重新驗證Case103或107/109的Chart/Cluster／MEF內部資料；可引用現行`RESOURCE-BASELINE.json`（原報告Field carrier SHA `18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a`、橋接chart SHA `79f79516d68183a0f8efb44664139f2c69813c4c190f5e89bbacfef82e6d5049`），必須標既有來源而非本次原件直接驗證。該報告Table carrier SHA為`ea2af30c...`，與本次Table carrier不同；核心選取解壓XML SHA相同，可在member層對齊，不能抹平carrier差異。

編隊token沒有本次原表來源；保留wire入場服務輸入／回覆opaque token，不能用Quest／Field／Case／Map ID生成。Portal實例ID、instance completion、合法reward與結算需各自證據。

## 交付檔案與目前可用程度

- `quest-facts.json`：20筆完整選取Quest原始欄位與XML片段、Chapter引用、QuestTalk不存在證據、SHA及byte span。
- `scene-facts.json`：35個Event composite scene keys，原SEQ身份、hash、LoadMap/OpenTalkScene/CreateObject等帶行號選取呼叫。
- `typed-domain-facts.json`：66筆NPC/Town/Case/Map/Portal effect/Actor variant/Item選取資料。
- `table-structure-report.json`：原表元素／屬性統計、六個multi-Demand反例、單鏈逐項校驗、源表重複Scene key。
- `source-members.json`：20個解壓member來源與完整SHA鏈。

可用於建立schema與填入靜態內容。合法目標、reward語義、instance outcome→Quest結算、NPC UI關閉／scene receipt、存檔commit仍須對應交付中的Client證據或Server候選契約；本子工作不以空缺值假設它們已通。

## 追加：復用已保存的原始 Chart／Cluster bytes

`scenario-resource-facts.json`補上Case103與教學Case102。從main `kr/evidence/<SHA>.txt`直接讀回原始XML bytes並重新算SHA，以下是本次重新解析既有原件副本，未重新取得Field.stp carrier：

- Case103 Chart SHA `79f79516d68183a0f8efb44664139f2c69813c4c190f5e89bbacfef82e6d5049`：Node1→Map191、Node2→Map192，真正NodeLink是1→2。
- Case103 Cluster SHA `bf3cfce20eb7ef61d6e1961072a7084f09cfe1313f6a21dc04f2bb961767b182`：set0 cluster1為1001/PRE1×3及1009/PRE1×1，cluster2為1001/PRE1×2及1009/PRE1×2，cluster3為1001/PRE1×3及1004/PRE1×1。沒有把任何cluster對應某張map，也沒有將這些literal數量當關卡總生成數／擊殺目標／勝利條件。
- Case102 Chart SHA `c7ac1fe050335455fb7b4ca9707adc8b0553226c53aaab94d3609eec47b54eb6`與Cluster SHA `f2cbdae86822dfa25936087700ae3c44f3f68703d8d0fc6a5a35a8cda387c159`：一個node／Map190，set0/cluster1的OBJECT1036 PRE1 COUNT1；不代表整個教學只打一隻或只有一波。

Case107/109/108/101仍缺Chart/Cluster本體。其精確member分別為：

|Case|Chart member|Cluster member|
|---:|---|---|
|107|Field/MapFlow/CHART_scenario_chicken_01.xml|Field/Cluster/CLUST_scenario_chicken_01.xml|
|109|Field/MapFlow/CHART_S_pathofAlsmeer_01.xml|Field/Cluster/CLUST_S_pathofAlsmeer_01.xml|
|108|Field/MapFlow/CHART_scenario_razed_01.xml|Field/Cluster/CLUST_scenario_razed_01.xml|
|101|Field/MapFlow/CHART_scenario_ygg_01.xml|Field/Cluster/CLUST_scenario_ygg_01.xml|

解除條件：取得上述member的原始解碼bytes／SHA，或原Field.stp（現存來源記錄SHA `18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a`）再以相同唯讀解碼器提取。已查本次與過去scratch來源、Library名稱、main `kr/evidence`的MapChart本體以及supplement T07 Case103收件。沒有用scene的LoadMap檔名猜Case107圖。第一批Q119可以交出有場景證據的不同形態樣本，其實際遭遇map graph必須明確BLOCKED。

`scene-facts.json`另增加Phase／RevPhase／DeleteAllObject／RestoreMap原始呼叫行號，使scene生命週期資料不只含開始與對話；這些是literal calls，不取代helper或原生receipt的語意驗證。
