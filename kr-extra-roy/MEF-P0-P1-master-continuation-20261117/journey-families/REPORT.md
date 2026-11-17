# P1：Q119 完整正常旅程與七個功能族的實際資料契約

日期：2026-11-17。工作線：`extra/roy1`。固定來源基準：`5ed4833b805949fabe260aea77e3fe0fd8e86bfa`。本稿處理上一輪 P1 四題中的「第一個完整正常旅程」與「擴充所有功能族」；普通背景首次入口 B、world 結果到 Lua 出口由本輪其他分題處理。原件與 Git 身分完整列在 [source-manifest.json](source-manifest.json)。

## 1. 本輪完成了什麼

**已把 Q119 從 NPC 前置、五段原劇情、四個普通戰鬥節點、結果、返回，到下一任務資格串成可重驗的資料與 Server 接線契約；七個功能族均有真實原資料例、native 取得／退出邊界、資源前沿及 Server 開發責任。** 本輪不是再列一遍 API 名稱，也不是只排下一輪計畫。[資料結果](data-evidence.json)、[機讀契約](contracts.json)

| 實際完成的分析 | 覆蓋 |
| --- | --- |
| Q119 原劇情完整語法讀取 | 5 個 SceneList 雙鍵、5 份原 SEQ、176 次 body call；每檔全部 token 消費完畢，沒有執行 Lua |
| 劇情實際資料 | 7 份相機 XML、9 組 ScenarioTalk selector、54 筆實際 Talk row及其文字來源 hash |
| 普通旅程 | Quest119／Case107／Chart4→3→2→1／Map632→633→634→635／Cluster1→2→3→4逐段 join |
| Server 候選位置 | 4 份 BND；21 個 spawn／portal／encounter點依既有 Server static layer0/1政策皆可站；4 組 spawn→portal皆有12格四鄰路徑 |
| 功能族 | 相機、聲音、圖片、書本／教學、world NPC／服務、互動點、場景／小地圖，7/7均有實際資料契約 |
| 原件重驗 | 7個carrier、50個STP member與2個ZIP member的定位／長度／SHA；39個固定Git來源 |
| 原生證據 | 49個既有有界窗口重新比對BIN；8個新增定向窗口，共1,341 bytes，含完整指令邊界及字串 |

上述 **PASS 是有界靜態分析完成**。完整安裝的資源、實際 cache 勝者、Client 畫面聲音與 Server 執行沒有因資料分析而變成 ready；也沒有執行原 Client、Server、Lua 或封裝程式。新 `Master.stp` 已讓若干補件名稱與掛載宣告明確化，尚未提供的 payload 仍保留精確前沿。[驗證收據](verification-result.json)

採用最新 T01 的限定審核，不把整個歷史研究目錄升為 FULL-PASS。本稿沿用 P0 的121正常binding、75個helper與15項勘誤；尤其保留 number TRUE/FALSE、正常 Q Create 的 immediate1、Q 圖片先取消舊圖、零fadeout分支、原零參數EndSepia的特定轉換，以及003F非總完成證明。[T01審核](../../../research/handoffs/t01-20261117-extra-roy1-mef-sync/REPORT.md)、[P0 ABI](../../MEF-P0-content-contracts-20261117/abi-adoption/report.md)

## 2. Q119 的原資料與現行 Server 候選

### 2.1 任務與地圖的識別碼保持分域

原 `QuestInfo.Quest[id=119]` 指向 Town1、Field26、level5、giver／finisher10047，前置是 Quest118。原 `Case107` 的 `STAGE=26`，MapFlow／Cluster分別是 `CHART_scenario_chicken_01.xml`、`CLUST_scenario_chicken_01.xml`。補充ZIP提供這兩份真實XML；本輪實讀所選節點與群組，並核對現行Server候選及typed scenario JSON。[data-evidence.json：server_journey、zip_members](data-evidence.json)

| Server節點 | 原Chart節點 | MapID | 原MAP／BOUND | 候選Cluster／原OBJECT展開 | 候選入場／清組劇情 |
| ---: | ---: | ---: | --- | --- | --- |
| 1 | 4 | 632 | `mushroom01D`／`mushroom01` | 1：1001×2 | 入場119/2 |
| 2 | 3 | 633 | `mushroom04D`／`mushroom04` | 2：1001×3 | 無 |
| 3 | 2 | 634 | `mushroom07D`／`mushroom07` | 3：1001×3、1004×1 | 無 |
| 4 | 1 | 635 | `mushroom12D`／`mushroom12` | 4：1001×3、1022×1 | 入場119/3；清組119/4 |

原Chart的NodeLink也是4→3→2→1。**候選採用哪個Cluster、何時播放哪段演出仍屬Server重建政策**；原檔存在19個Cluster不表示每節點必然使用某個編號。本輪沒有將 Q119/3 的演出模型1086、原Cluster19的1086或候選王1022合併成同一種身分。[data-evidence.json：server_journey.nodes；q119_scenes[2].models](data-evidence.json)

四個Map row的TRIGGER分別是`scenario_chicken01.mef`至`04.mef`。這些字串與本輪的普通Server節點關係可核對，但不是「已證普通背景MEF首次載入」的證據。這個界線繼續交由入口B分題判定，不藉資料表名稱補造caller。[既有場景分析](../../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md)

### 2.2 每一段原劇情都已讀到底

| 原鍵 | funcName後綴 | body calls | Q建立槽數／模型數 | Camera | Talk資料列 | 特定內容 |
| --- | --- | ---: | --- | ---: | ---: | --- |
| 119/1 | `Blank` | 16 | 0／0 | 0 | 0 | `LoadMap("")`；仍有完整phase與restore流程 |
| 119/2 | `Stage` | 33 | 7／3 | 1 | 6 | mushroom01D；1001、1009、1022；Talk12/10 |
| 119/3 | `Boss` | 46 | 3／1 | 1 | 5 | 原演出模型1086；Talk12/11 |
| 119/4 | `BossClear` | 48 | 8／6 | 3 | 26 | mushroom12D；1478–1481、10002、1086；兩次bodyfall；Talk12/12–16 |
| 119/5 | `After` | 33 | 6／6 | 2 | 17 | town001D；10047、10003、1478–1481；BGM003；Talk12/17–18 |

五段全部保留原 `Register(function)` 名稱一致性；call inventory保存位置、名稱、arity及每個call的hash，資源欄位保存選定資料而非完整解包腳本。四段的模型合計11個不同ID；現有Base可找到並解析1001／1009／1022／1086四份descriptor，其餘七個ID的descriptor仍不在供應索引。這個新增Q119全旅程範圍與舊P0的「Q119/3＋Q2440/5」範圍不同，兩套缺件計數不可互相替換。[data-evidence.json：q119_scenes、available_q119_model_descriptors](data-evidence.json)

所有五段的原收尾順序都為：`RevPhase4 → RevPhase3 → RevPhase2 → Q.DeleteAllObject → RestoreMap → RevPhase1`。這不是六個互換的動作；相機、地圖、actor、UI、聲音、輸入與coroutine仍有不同owner。Server必須採P0的前後置條件排程，不能把收到003F當成這些owner同時已清空。[P0生命期](../../MEF-P0-content-contracts-20261117/execution-lifecycle/report.md)

### 2.3 新發現：Blank不是空操作

119/1沒有演出角色或台詞，但仍呼`LoadMap("")`。本輪按此具體缺邊定向查BIN：

- `563C89`只測字串指標是否null，未測首字元是否零。
- 非null路徑先備份11個DWORD的camera資料，`563D34`保存world mapKey，再由`563D45`進`7C1E00`。
- `7C1E66..7C1E76`附加原字串`.fld`，`7C1EC4`用`MAP_FLD`群組查找；空basename也不因此跳過這個流程。查不到entry有自身失敗分支。

因此對原119/1的精確結論是「空字串不構成這個native入口的no-op保證」，不是「一定成功載入空圖」或「一定崩潰」。實際basename處理、當時map/camera、cache與entry仍是條件。Server也不能因funcName含Blank就預送下一段或省去收尾。[native-evidence.json：blank_loadmap_nonnull_and_backup、graphics_empty_basename_lookup、literal_fld_suffix、literal_map_group](native-evidence.json)

## 3. 從正常NPC到結果與回城的完整接線

以下是**現行Server候選的接線與驗收契約**，不是宣稱官方Server有同一個內部狀態機，也不是宣稱本輪已開發或部署Server。十步的機讀前置、退出、wire與開發責任在`contracts.json.journey`。[機讀旅程](contracts.json)

| 段落 | 真實資料／相容入口 | Server必須掌握的完成條件 |
| --- | --- | --- |
| J01 NPC前置 | Quest119需118；Town1 roster含10047。適用NPC modal路徑的001C帶category／NPC key；某分支先本地`561760(questLookup,1)`才發001C | 驗證角色、Town、NPC距離、任務資格及目前查到的quest；不能一收到001C就重播已本地啟動的119/1。既有modal研究是有界分支，未宣稱所有NPC都走同一路徑 |
| J02 前導與副本安裝 | 119/1 indexed SEQ；Case107／Field26；既有field／map／world／point／ready與loading adapter | 分離前導、world準備與各owner收尾；005F／0012／0014等不當作一個總ready |
| J03 節點1入場 | Map632、Cluster1；0047(119,2)選Stage原件 | Q未busy、內容來源可用；演出Qslots與權威world實體分離 |
| J04 節點1出口 | `GroupCleared→UnlockPortal`；`InteractZ→NextNode2` | 權威清組後開合法出口；001C為玩家意圖，還需距離／instance／目的地檢查 |
| J05 節點2 | Map633／Cluster2；沒有候選劇情 | 普通戰鬥、清組、Z出口推到節點3；不為補演出添加未定義Lua wire |
| J06 節點3 | Map634／Cluster3；沒有候選劇情 | 同一權威流程推到節點4 |
| J07 王前 | Map635／Cluster4；0047(119,3) | 原Q1086演出不替換候選world王1022；119/3明確是enter scene |
| J08 王後 | 權威清組後0047(119,4) | 依各owner收尾；原非零quest End並非必送003F，不能用單一回報等待模型假定正常完成 |
| J09 結果／返回 | 最後`InteractZ→Result`；候選returnTown1 | 結算、任務與資產提交冪等；普通field／map／actor／controller／points返回獨立於Q視覺RestoreMap |
| J10 回城劇情／下一任務 | 0047(119,5)；After、finalMusic BGM003；原Quest120需119且level8，giver／finisher10008 | Q119持久進度與返回一致；下一NPC改為10008，資格不足需可理解的正常進度流程，不能宣稱整村主線完成 |

NPC先本地播放再發001C的限定順序直接沿用固定`S00-20261103-PHINDOS-NPC-INTENT`；它對modal完整性、所有NPC的適用性有所保留。本稿不把10047的表列存在當作該時刻Client任務索引必然回119。這個context需要接上現有任務可用性與正常互動adapter。[既有NPC原生意圖](../../../governance/s00-iterations/S00-20261103-PHINDOS-NPC-INTENT.md)

### 3.1 目前候選的一個直接實作注意點

現行`story-q119-clear-scene.scenario.json`採用兩種不同portal政策，不能將前三節點的設定概括到第四節點：

| 節點／Map | portal key | preRegisterClosed | Server候選所需發布次序 |
| --- | ---: | --- | --- |
| 1／632、2／633、3／634 | 1、2、3 | `false` | 採清組後建立出口；若點尚不存在，必須先透過0027 snapshot建立，不能只送0048期待upsert |
| 4／635 | 4 | `true` | 入場預登記關閉出口；確認0027等既有建立路徑已發布matching category/key後，清組可用0048更新既存點狀態 |

這是候選內容的發布契約，未聲稱本輪觀察到Server已實際送出上述snapshot。若將前三節點改成預登記，應明確改版內容與發布策略；第四節點目前已是預登記候選，不需要為此再改成true。所有0027 snapshot都必須保留當時需要共存的NPC／shop／其他point，因0027替換共用集合；0048在四個節點都只更新既存matching point。[data-evidence.json：server_journey.nodes[].portal](data-evidence.json)、[point setter原件](native-evidence.json)

現行外部JSON只接受`Entry／GroupCleared／InteractZ`三種event和`SpawnGroup／UnlockPortal／NextNode／Result`四種action。候選的`enterScenes／clearScenes／returnScenes`在另一份mainline內容中，**不能直接將`PlayScene`或任意Lua欄位塞進現有schema**。需要使用已有scene adapter／編排層，或經正式內容版本擴充。這是Server開發與整合需求，不是要求Client猜新的opcode。[固定schema](../../../design/scenario-content/local-scenario-definition.schema.json)

### 3.2 本輪已驗的地圖資料適用範圍

四份BND都是version2、768×768格、world extent768×768。本輪重用既有Server static layer0/1非零聯集政策，檢查21個候選點及四條spawn→portal四鄰連通；結果全部成立，路徑各12格。這個檢查只支持**現行Server靜態格網政策**，未檢查動態障礙、actor半徑、可見幾何、Client當次collision安裝或實際行走。它的用途是排除已給候選在已知靜態BND上立刻落牆的資料錯配，不能代替遊玩驗收。[data-evidence.json：server_journey.maps[].static_server_bound_check](data-evidence.json)

## 4. 七個功能族：有來源的可用契約

這七個案例是不同合法context下的實際資料。**沒有把書本／Tutorial點／Aisen圖片硬塞入Q119的正常原SEQ。** 全ABI覆蓋沿P0採用；本輪補的是每族可交給Server與內容工具的具體selector、owner、資源和退出條件。[contracts.json：families](contracts.json)

### 4.1 相機

Q119/2實際呼`PlayCameraNoWait("Phin_YuriandRazed_Stage_01.cam",0,0,0,0)`。原XML兩個keyframe的framepos為0、140，position均為(454,357,72.34)，pivot pitch1.28、dist55，yaw由1.42到0.78。本輪沒有將140直接換算成wall-clock毫秒。[data-evidence.json：family_examples.camera](data-evidence.json)

取得流程是合法Q caller選原SEQ→helper加`Event/CameraWorks/`→共用KeyFrame Load/Play。原例使用NoWait；若內容改用WaitForCamera，getter回1還可能表示current為null，應與本run曾接納的狀態合看。退出要分開「Stop目前camera work」和「恢復相機快照」；前者不是後者。XML已存在，當時world/camera、Script版本及owner競合仍須由內容排程滿足。Server只需要在合法時點選scene，無須為這兩幀另造逐幀封包。[native-evidence.json：C03–C07、C12復用窗](native-evidence.json)

### 4.2 聲音

Q119/4兩次播放`Sound/Scene/bodyfall.wav`。原`_Sound.xml`同時有Name／File=`Scene/bodyfall.wav`、Setting=`Character`；Q119/5的BGM003在`_SoundList.txt`對應`MUSIC_PHINDOUS`。這是實際資料宣告，並非從音效名稱猜group或場景。[data-evidence.json：family_examples.sound](data-evidence.json)

`PlaySound`沒有本例可公開等待的逐音效completion handle；helper讓出一次與native回傳個數均不能證明播完。Q／Tutorial音樂共享primary slot；退出若要真的停止／釋放用既有StopMusic，不把音量淡到零當成Stop。FinalMusic由RestoreMap消費，並保留P0「空字串append不清舊值、接納Start才assign空」的差別。Server仍須自行決定轉場後背景音樂策略與演出排程，音效不提交戰鬥結果。[既有視聽生命期](../../MEF-capabilities-20261116/audiovisual/report.md)、[P0生命期](../../MEF-P0-content-contracts-20261117/execution-lifecycle/report.md)

所選WAV／OGG沒有出現在本輪供應索引。Master的聲音掛載主要是Scenario目錄；沒有本題可直接據以命名的Sound/BGM或System包，所以不新造`BGM.stp`補件名。[本輪Master閉合](../master-resource-closure/native-evidence.json)

### 4.3 圖片與序章

Q2440/5真實`FlyingObject`參數為`Image/Prologue/Aisen00_1.dds,50,30,100,100,0,0`；後面的DoProlog19有10個Dialog、7個不同PicturePath，加直接圖共8個不同DDS參照。原件資料、每段文字hash及圖片路徑都已保存為derived facts。[data-evidence.json：family_examples.images](data-evidence.json)

採最新P0／T01結論：Q建立新追蹤圖前先取消舊圖；fadeout0在所選phase4先判remaining並跳除法，phase0、下次合格tick的alive清零及manager回收是不同步驟。圖片可見仍需texture，不能把phase可前進當成已正確呈現。退出需分開Q追蹤圖、Tutorial tracking、Prolog/UI與shared voice；003F不會替這些owner提供總ACK。[P0圖片生命期](../../MEF-P0-content-contracts-20261117/execution-lifecycle/selected-image-contract.json)

Master現已提供`Image/Prologue.stp`宣告。本輪Master分題又閉合texture的原path存在probe與條件式`.etf`改名consumer：**原path查無才進packed路線，不能說原檔decode失敗就必然再試ETF**。本分題同時查原DDS與條件式ETF的供應索引；兩者皆未取得。這已從「猜PackingRules」改成有原生consumer的補件前沿，但仍未證明實際payload可用。[同輪texture原件](../master-resource-closure/native-evidence.json)、[本題索引結果](data-evidence.json)

### 4.4 書本與教學

原`Table/Book.txt`兩個三分量設定是(808,-4.5,108.5)與(45,0,13.5)。本稿按原native位置／第二向量用途保存數值，不把所有向量單位自行改稱角度弧度。`Q.Book(integer)`的完整native body不使用該integer選書，而是固定owner`FC1BF8`讀設定並開始四個typed state。[data-evidence.json：family_examples.book_tutorial](data-evidence.json)、[book_config_start復用窗](native-evidence.json)

本輪補核constructor使用的四個原字串：`Synopsis/book01.gb3`至`book04.gb3`。Master對應`Synopsis.stp`，因此模型補件方向已具體；實際四個模型及其後代仍未提供。不能藉泛用GB3／EMF規則宣稱每個書本實際選到哪個檔案。[native-evidence.json：fixed_book_paths及book_constructor](native-evidence.json)

完成鏈不是固定時間：State2要文字完成且shared voice handle為0；最末phase清`B+74`，`Q.IsBookFlying`真正推number，原helper才離開等待。初始0不能證明曾播放；取消coroutine也不能代替native owner退出。教學RequestStartScenario／IsScenarioEnded及既有0040／004C的合法context仍沿原契約，由Server實作權威教學進度與保存，不以書本active flag提交任務。[既有書本狀態機](../../MEF-control-flow-20261116/world/report.md)

### 4.5 World NPC與服務

本輪新增逐欄實讀的服務例為：`Town1 + ShopNo2 + Shop TYPE2 → NPC10030 / NPC TYPE12 → PRODUCT2614 → ITEM2607`。該店有27個PRODUCT宣告；NPC有5個TALKSET。Product2614原表列LEELOO3700、SELL_LEELOO370、LEVELUP_DISABLED0；這是來源資料，不代表Server交易已實作或所有強化資格可由單欄決定。[data-evidence.json：family_examples.world_npc_services](data-evidence.json)

category2互動點的key是ShopNo2，不能填10030。前段由shop row找NPC，後段用currentTown+NPC取商品；NPC TYPE12的選單已有強化operation29與F42F6 consumer。買賣、強化各有既有request／結果路徑：001C服務context、C2S0027購買、0020販售、00A1強化，資產另由002C等同步。S2C0027則是point snapshot；同值opcode必須保留方向與context。[native-evidence.json：world-npc復用窗](native-evidence.json)

可見角色與服務context分開：ActorList沒有10030模型列，因此直接CreateObject(10030)不能被本稿宣稱能顯示鐵匠。Q119/5的10047則有category6／FILE=`01_Yuri01`，但Npc/Base descriptor與外觀payload仍缺。Server需完成地點／服務資格、商品與數量、資金／背包、強化消耗成敗、原子提交、資產同步及保存；這些是REQ0021後續服務工作線的開發輸入，並未越權宣稱S00已接受新增強化規格。[既有NPC服務契約](../../MEF-capabilities-20261116/world-npc/report.md)

### 4.6 互動點

原`TutCheckPointList` row1提供x311、y149、range30、active1、effect=`TUTPOINT`。本輪沿實際native`4A9430→4A90C0`確認low-WORD查表、category4建構、effect呼叫及manager插入。這不是通用category2／3／出口建立器，也不能把教學點座標直接搬到Q119或Town1服務位置。[data-evidence.json：family_examples.interaction_points](data-evidence.json)、[新增tutorial point窗口](native-evidence.json)

效果不再以名稱猜副檔名：原`EffectCategoryMapper`的TUTPOINT→subcategory0／Sequential→effectId98；`EffectList[98]`明確給`Folder=Area\\Zone\\`、`File=A_Zone_TutorialZone01.eff`、`Sound=NULL`。`551B80`新窗口補到category lookup、負subcategory改0及effect-ID map，沒有把宣告存在擴張為EFF已成功materialize。Master提供`Effect/Effect.stp`根掛載宣告；真正EFF及其texture等後代仍待取得。[data-evidence.json與native-evidence.json：effect_category_lookup](native-evidence.json)

退出方面，SetCheckPointStatus或0048只更新既存matching point；disable不清latch，enable不保證新one-shot邊緣。關閉狀態也不是刪除。0012前置／0027替換會清共用集合；Server需要管理完整point snapshot、合法出口意圖與過期delta，不在Client不讀的payload自行添run token。[最新T01互動點限定結論](../../../research/handoffs/t01-20261117-extra-roy1-mef-sync/REPORT.md)

### 4.7 場景與小地圖

Map632實際分成`MAP=mushroom01D`、`BOUND=mushroom01`、`TRIGGER=scenario_chicken01.mef`。小地圖入口`lb.LoadMinimap(632)`傳map key，使用BOUND組`Map/Minimap/mushroom01.mmt`，另依field mode取town／field marker並讀`minimapSymbols.eif`；不是直接傳texture path。原BND已取得，MMT及TextureFile尚未取得，不能由同名BOUND猜worldsize或texture。[data-evidence.json：family_examples.scene_minimap](data-evidence.json)、[minimap原件復用窗](native-evidence.json)

普通0012會先清point/resetcontroller；同MapID的worldloader可能略過graphics／BOUND／minimap重載。`lb.ChangeMap`缺少0012的相同前置；`Q.LoadMap/RestoreMap`則只有視覺圖與單份map/camera備份，不能恢復world entities、controller、points、Server節點。這些差異已放入十步旅程的前後置條件。[既有完整場景分層](../../MEF-world-identity-scene-interaction-20261117/SCENE-INTERACTION.md)

Master使補件名收斂為`Map/MiniMap.stp`；graphics FLD仍須真正MAP_FLD/cache entry及所選carrier。Field的規則只含xml／mef，不能把mushroom FLD指派給`Field.stp`。Server可以先完成合法map選擇與snapshot／ready順序，視覺資源未齊仍不得標ready。[同輪Master原件](../master-resource-closure/native-evidence.json)

## 5. Server開發需求與可直接接續的順序

本輪不新增競爭台帳、不改正式REQ／RR／Task owner。現行REQ0010／0016／0017／0018／0019／0021皆維持CANDIDATE；下列是可給既有owner去重採用的增量。Server內部規則未實作，不列成Client待逆向的停止條件。[data-evidence.json：existing_server_requirements](data-evidence.json)、[contracts.json：server_development_requirements](contracts.json)

1. **先固定內容版本與typed selector。** 保留Quest119、五個scene鍵、四節點及原Chart／Cluster的來源。原模型、Qslot、world entity、ShopNo、NPC、Product、Item分域；實際資源未滿足的內容profile不可放行為完整聲畫。先接現有candidate／schema／adapter，不重新從零造一套未證MEF語法。
2. **完成run與scene排程。** 使用已證0047及既有本地NPC起播路徑；重入前核對busy與當前run，非零quest End條件納入狀態機。003F只按有限語意處理，00EB只解除適用等待層；timeout、取消、跨圖、重連和晚到訊息由Server持有狀態。對接REQ0017／0018／0019。
3. **保持普通戰鬥與演出責任清楚。** 以現有四節點Entry／GroupCleared／InteractZ推進權威world；前三節點採候選的清組後建門，第四節點則採既有`preRegisterClosed=true`預登記關閉門，再於合法清組時更新既存點。核對各節點snapshot是否已建立matching point，不混用0027建點與0048更新；若改變前三節點政策，再明確改版。無須先把普通戰鬥全改成MEF，亦不以背景Lua出口尚待研究阻塞不依賴它的Server開發。對接REQ0016。
4. **閉合結果、返回與持久進度。** 把Q119結算、角色等級／資產與返回地點合成一致的Server提交。原Quest120要求level8且轉到NPC10008，資格不足要有可繼續的正常進度。REQ0019已有正常Q117/118/119後卡Q120的歷史工作副本觀察，不能把本輪靜態PASS改寫為該問題已修復。
5. **依現有排序接服務功能。** 主線完成後沿REQ0021既定順序細化銀行／裝備／商店／掉落；本題Shop2是已有Client路線的具體輸入。交易與強化需資格、消耗、結果、資產與保存一致，UI開成功不能視為業務成功；沒有模型來源不能先宣稱服務NPC可見。

這些工作可以與精確補件並行。相機XML、Table資料與已取得BND足以開始多項內容檢查與Server設計；未取得的模型、FLD、MMT、音訊、圖片、UI並不阻止所有Server功能開發，但阻止把對應完整聲畫／遊玩目標標為已驗收。

## 6. 尚未越過的邊界與解除條件

| 分類 | 本輪精確狀態 | 可解除的具體證據 |
| --- | --- | --- |
| Q119新增七個缺descriptor | 1478、1479、1480、1481、10002、10003、10047在所供索引無相應ABF；已有ActorList FILE | 同版Npc／Obj等實際carrier與相符descriptor；再展開其Avatar／mesh／animation／texture後代 |
| 已有四個Mon descriptor | 1001、1009、1022、1086已解析；其存在不是實際CHA_ABF勝者 | 同版cache／scan entry、mount與實際payload；不靠FILE stem猜贏家 |
| Map／minimap | 四BND可重算；圖形FLD、MMT及所指texture／marker／symbols未齊 | 實際MAP_FLD entry／carrier、`Map/MiniMap.stp`與所選members |
| 圖片／書本／效果／聲音 | Master已給Prologue／Synopsis／Effect等宣告；具體payload未取得 | `Image/Prologue.stp`、`Synopsis.stp`、`Effect/Effect.stp`及依已證consumer選中的payload；聲音不得猜造包名 |
| Server業務／排程 | 六條既有REQ的增量開發輸入已具體，未改正式狀態或執行Server | 實作差異、相容serializer、狀態與保存證據，再由owner驗收 |
| 遊玩 | 本輪沒有Client／Lua／Server執行 | 經授權的正常NPC→四節點→result→返回旅程，聲畫、輸入、可走動、NPC與持久狀態一致 |
| 其他P1／P2 | 本稿不以七個案例替代普通入口B／world→Lua出口分題，也不聲稱官方MEF grammar還原 | 使用同輪各自的有界原件結論；官方grammar另有其原件與parser責任 |

## 7. 重現與交付

檢查器會重新讀固定Git objects、核7份原件整檔hash、只讀解析選定資源、對比所有derived JSON，並以PE section映射重驗原件窗口。新增code window重新反組譯並要求整段指令覆蓋；四個分析器陰性案例確認branch、assignment、非literal表達式與Register後多餘語句會被拒絕。這些是分析器檢查，不是遊戲執行測試。[verify_evidence.py](verify_evidence.py)

```sh
python -B kr-extra-roy/MEF-P0-P1-master-continuation-20261117/journey-families/verify_evidence.py \
  --repo /absolute/path/ttr_anal_multi \
  --sources /absolute/path/project_sources \
  --supplemental /absolute/path/supplemental_resources/ttr \
  --receipt /absolute/path/receipt.json
```

重建derived資料使用同目錄`audit.py`，相同三個來源參數另加`--output /scratch/output`。工具不寫原件、不寫完整decoded member、不執行Lua；repo輸出限本題目錄。`source-manifest.json`固定commit／blob／SHA／bytes，`native-selection.json`界定每次讀取邊界；`verification-result.json`保存本輪實跑結果與交付檔hash。未操作Git commit／push，本題交回主代理統一發布。
