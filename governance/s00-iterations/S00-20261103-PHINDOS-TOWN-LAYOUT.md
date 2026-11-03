# S00：馮德斯村一般入場的候選配置

本輪供「正常廣場主線接續後進入馮德斯村」使用。沒有啟動／修改Client，
沒有將過場演員座標當玩家出生點。它是**明示的Server重建配置**，不是官服位置還原。

## 已有原生介面與本輪取捨

- 原BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
  [既有T07查核的釘定副本](evidence/t07-phindos-intake-20261103/post-t01/MISSION-LOBBY-AND-TOWN-PRELOAD-DEPENDENCIES.md)
  已保存0099/type3→CMissionRoom→kind1控制器/UI4，及0038/type0的Town context／NPC預載。
  [收件來源與SHA](evidence/t07-phindos-intake-20261103/manifest.json)保留本機原稿位置；本輪只採用列明的有界內容。
- 保存bulk `0x4B9320`、`0x4BCBA0`、`0x4BCB40` 可直接選讀；
  4BCBA0末段為UI4與54C410相機狀態設定，未見廣場4BBC10那條C2S43送出。
  這是目前保存函式的有限觀察，不證明所有間接呼叫都無訊息。
- 因此選0099/type3作**一般村落候選**時，不能沿用廣場「等待43才送map」的前提。
  依已有reset副作用，候選偏序為安裝scene、Town context、map182/reset，
  然後同一世代的玩家、控制綁定、NPC／checkpoint、ready。
  Town1究竟使用哪種官服scene回覆，仍無官方trace或完整producer證據。
- 0038是Town context與預載，不提供map或spawn；Town1與map182仍分域。

## 原始資料與位置缺口

本輪重新唯讀抽取原始Table `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。
`Table/_TownList.xml` member SHA256
`bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660`：
Town1 NPC成員為10001、10002、10003、10008、10013、10014、10047、10048、10015。
此表無XY。npctable的10047是Yuri/type0，10013銀行/type1、10014技能師/type2；
該type不能直接替代checkpoint category或scene mode。

`_PositionList.txt` 前述Field-like行有內容19「新手／往馮德斯的路」，
但未取得一般村落spawn的consumer／索引對應；不採其734/1106作村落出生。
TownWorld bindno100是另一路UI資料，也不作spawn。
之前15/3演出玩家座標在目前靜態判定被阻擋，而NPC演出734/744可走，
兩者均不直接挪為本次玩家位置。

## 明示的重建位置及資格核對

[可重跑工具](../inspect_phindos_town_layout.py)從原始BoundMap載體唯讀抽取town001，
member SHA256 `30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6`。
版本0、768×768 cells、world1536×1536；沿用兩個靜態層均非零即阻擋的候選判定。

選點規則是尋找「距地圖幾何中心最近，33×33 cells整塊無阻擋」的方形區域，
不是從NPC或演出點開始找。4,843個合格區域中選到中心778/722。
整個world矩形x746..810、y690..754的4,225個整數樣點均可走。

- 玩家候選spawn：778/746，方向64沿既有Server方向編碼；不聲稱官服進村朝向。
- 九名NPC排列在x758/778/798、y702/714/726，Yuri在778/726。
- 玩家與NPC均在同一完全清空的矩形中，玩家可走到各NPC附近，非孤立清空cell。
- 私有新類別 `LocalPhindosTownCandidates` 提供Town/Map/SpawnX/SpawnY/SpawnDirection、
  Definitions、Validate、Spawn、InteractionRegions、TownContext；Validate檢查整塊矩形，
  沒有all-clear fallback。呼叫者須用Phindos182Sha256載入正確BND。

[精確輸出](evidence/S00-20261103-PHINDOS-TOWN-LAYOUT.json)記錄來源、演算法及全部候選位置。
這只證靜態層條件；模型重疊、相機、動態MEF、真正Client可操作與官服配置仍未驗收。
不能因有村落配置就授權略過Field19或直接完成Quest15；正常主線條件另由Server流程負責。
