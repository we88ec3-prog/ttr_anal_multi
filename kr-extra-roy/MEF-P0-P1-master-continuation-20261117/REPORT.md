# Master 新原件閉合、P0 增量與 P1 全方向分析

日期：2026-11-17（Asia/Taipei）。工作 branch：`extra/roy1`。唯一原生判定程式為 KR `Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。新增內容接在 `5ed4833b805949fabe260aea77e3fe0fd8e86bfa` 的 T01 限定審核之後，未另開 branch。

## 1. 結論

**現在已能讀取並已完整核對 `Master.stp`。** 它確實解除上一輪的 Master 掛載宣告缺口；本輪同時補到真正 base mesh 與三種圖片／texture consumer，完成原規劃的四項 P1 有界續析。交付已把每項正向結果、排除候選、來源缺口、Server開發需求及解除條件分開固定，詳見[完成判定](P0-P1-COMPLETION.md)與[機讀狀態](status.json)。

目前仍不能宣稱完整資源可用、B背景首次入口已存在、普通world結果已能被同一Lua run／generation觀察，或完整旅程已可玩。這些是實際未通過的驗收條件，不以分析器PASS、binding存在、畫面數值或metadata取代。

## 2. Master 帶來的實際增量

新原件大小 **1,094,887 bytes**，SHA-256 **`f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d`**。檔內899個file members、908個directory加root共1,808個索引node；899檔由897個`AttachedPackage`、`EncFlag`及`PackingRules`組成。897筆PackingRules完整消費至EOF，全部與掛載宣告一對一join。這是本檔的觀測資料形狀；兩個flag仍未命名。[Master報告](master-resource-closure/report.md)、[全索引衍生證據](master-resource-closure/master-member-evidence.json)

三個影響既有結論的細節：

1. **`EncFlag=5`不是native要求的`EncSetting`。** 這份Master沒有後者；已核consumer依缺省分支傳1，不把近似名稱或相同整數型別當成別名。
2. **provider先查父目錄，再於miss時往子目錄。** 例如Character/Mon的Base provider可能先於avatar provider供應同一路徑；不能按最長prefix假定avatar必勝。宣告與供應檔root相符，也不等於已觀測原安裝選中該物理檔案。
3. **Field與UI Lua線索變得具體。** Master宣告`Field.stp`，Field的extension slots為`xml/mef`；另宣告`UI/LUA.stp`及`lua`slot。Master自身沒有MEF/Lua member，這些宣告不會直接證明grammar、首次入口或普通pump。[載入契約](master-resource-closure/resource-loader-contract.json)

原兩場景Q119/3與Q2440/5的132個dependency node已全部重接Master；122個可列出至少一個宣告provider候選，並非122個成功載入。17筆「缺Master」說明獲新事實取代，**108個原前緣及13個缺descriptor仍未因metadata消失**。Master未提供模型、地圖、圖片或聲音payload，真實選取還受cache、provider成功安裝、父子查找、loose來源及resident狀態影響。[前緣差異](master-resource-closure/p0-frontier-delta.json)、[選定路由](master-resource-closure/selected-resource-routes.json)

## 3. 真正的 EMF／ETF consumer 已補上

過去只看到封裝規則或另一條檔案檢查路徑，不能推論真正render loader。本輪沿base reload到`7D0920→79BCE0`：resident命中可略過讀檔；需要物理載入時，僅在`FB79A8 != 0`且原path probe為0，才將副檔名改為`.emf`，進`7CBF70`。旗標在正常初始化由讀取`fcs.flu`的結果設定。旗標為0或原path可被probe接受，就保持原path走`7CBEE0`。範圍限定base mesh，沒有擴張到所有motion／ASD。[Master §4.1](master-resource-closure/report.md)

圖片則接出三條有receiver與caller的consumer：

| 類別 | 已證鏈 | 必須保留的差異 |
|---|---|---|
| Prolog | `55F370→736B00→typed73ABE0→737D40→737F40` | image-info非負才繼續texture-create |
| direct FlyingImage | `560030→734330→7340C0→737D40／737F40` | 不具有上述相同info-result gate |
| model TextureList | `7C4310→FE1AE0=7BC2C0→FE1AC8 queue→7BCA20→737D40` | 真實caller把同manager送入worker；processed位不是success／drain ACK |

共用`737D40`只有在原path probe為0才改`.etf`；原path被接受而後續decode／adapter失敗，不會因此自動再試ETF。model與image texture-create的不同adapter已核至原PE的`D3DXCreateTextureFromFileInMemoryEx` import，image-info則是另一個`D3DXGetImageInfoFromFileInMemory`。這完成所列路徑與consumer接合，並未執行DLL或證明缺少的payload能被圖形API接受。[原生證據](master-resource-closure/native-evidence.json)

新增條件候選共 **13筆ETF＋2筆EMF＝15筆，去重12種path**，全部保留選取條件。聲音沒有可從Master推導的任意BGM包名；正確補件清單見[SOURCE-REQUEST](SOURCE-REQUEST.md)。

## 4. P1：正常旅程完成資料級接合

Q119由Quest118前置、Town1／NPC10047、Field26／Case107開始。五段原SEQ全部讀到底，body call數為16／33／46／48／33，共176；七份camera XML、54筆Talk rows與所選table資料都已核原件。這是全部五個本次scene的靜態讀取，沒有執行Lua。[旅程及七族報告](journey-families/REPORT.md)

| 候選Server節點 | 原Chart node | Map／Cluster | 劇情 | 出口政策 |
|---:|---:|---|---|---|
| 1 | 4 | 632／1 | 入場119/2 | 清組後建立 |
| 2 | 3 | 633／2 | 無候選演出 | 清組後建立 |
| 3 | 2 | 634／3 | 無候選演出 | 清組後建立 |
| 4 | 1 | 635／4 | 入場119/3、清組119/4 | 預登記關閉點，合法清組後更新 |

Q119/3演出模型1086與候選普通world王1022分開；Chart／Cluster的採用與演出排程是現行Server重建政策。四張真BND按既有Server layer0/1政策核21個候選站位與四條spawn→portal路徑，均成立、每條12格；未驗動態障礙、actor半徑或Client行走。[資料證據](journey-families/data-evidence.json)

**119/1的Blank不是空操作保證。** 它仍有16 calls和`LoadMap("")`；native只測pointer非null，會保存map／camera再進附加`.fld`的group lookup。不能因名稱Blank就跳過其生命期，也不能從此推論一定成功或崩潰。另在返回119/5之後，原Quest120要求119完成且level8，NPC換為10008；Q119分析完成不等於整村主線接續已修復。[旅程 §2–3](journey-families/REPORT.md)

## 5. 七個功能族均有實例及契約

本輪完成的是原計畫的7/7功能族各至少一個真實案例，並逐一列入口、selector／typed ID、資源、owner／退出、Server責任及缺件。不同context的案例沒有被硬塞進Q119原SEQ。[機讀契約](journey-families/contracts.json)

| 功能族 | 實際案例與本輪可採用事項 |
|---|---|
| 相機 | Q119/2真camera兩keyframes；NoWait、stop及restore分開 |
| 聲音 | `bodyfall.wav`的原Sound設定、BGM003對應；沒有completion handle就不把yield視為播完 |
| 圖片 | Q2440/5 direct FlyingObject＋Prolog19十段／七圖；採取消舊圖、零fadeout與新ETF選取鏈 |
| 書本／教學 | Book.txt兩組原值、固定`Synopsis/book01..04.gb3`，typed狀態與voice共同完成條件 |
| world NPC／服務 | Shop2→NPC10030/type12→Product2614→Item2607；ShopNo／NPC／產品／物品分域 |
| 互動點 | TutPoint1→TUTPOINT／subcategory0→Effect98→真EFF路徑；建立、更新、disable、erase分開 |
| 場景／小地圖 | Map632的MAP／BOUND／TRIGGER分域、真BND、MMT請求與marker；Q RestoreMap不等於普通world恢復 |

新增完整Q119範圍共有11個不同模型，目前可解析1001／1009／1022／1086四份descriptor，其餘1478–1481、10002、10003、10047七份仍缺。這個7與舊P0兩場景的13是不同分母，不可互換。[資料證據](journey-families/data-evidence.json)

## 6. P1 的兩條未知能力已進一步縮小

**普通首次入口B：** 已正向接上Mission／Scenario正常initializer→cached descriptor→`CScenarioTalkBox`→`page+B4`與正式VM receiver；繼承XML reader及clone也已展開。constructor建立namespace／closure，沒有本次content filename／buffer或普通frame task。Rebind僅把既有Lua最後參數轉整數寫receiver，沒有typed owner工廠或首次起播。這些候選均已裁決，但B所需load／execute／same-VM pump完整鏈仍未證。[B報告](entry-b/report.md)

**world→Lua：** 0000比例、0034絕對HP/SP/MP、000E結果顯示、000C死亡FSM、001A移除具有不同producer／consumer。HUD死亡畫面可顯示0而未寫actor currentHP；零HP snapshot也不會在該receiver自動進死亡FSM。`000E case8`的28-byte成對ID記錄已跟到tick／draw及圖形出口，只保留live u16 IDs、RGBA、duration，沒有run／generation／sequence／reason，不能當Lua死亡queue。新的native技能成本bool也不是Lua返回值。剩餘缺邊已明列為typed bridge，而非籠統「待runtime」。[world報告](world-lua/report.md)

以上有限候選及census不是全程式alias不存在證明；有新Field/UI載體、實際producer或owner線索時才接續，不重掃同一binding清單當新進展。

## 7. Server 可先做什麼

目的仍是開發Server。權威HP／死亡／移除原因、敵群／任務、結果／資產、NPC／商店、持久化、run／generation及冪等，都列為Server開發需求。Client未知B或Lua bridge不阻止採用現有普通world與已證有限Q演出。[SERVER-HANDOFF](SERVER-HANDOFF.md)

建議先接現有內容版本、typed selector及合法adapter，再完成run／scene排程、戰鬥權威與出口政策，最後把結果／返回／Q120資格與持久化接合。既有外部schema僅三種event及四種action，不能直接添`PlayScene`或任意Lua欄位；需既有scene編排或明確內容版本擴充。新研究契約不是該schema可直接接受的部署檔。[既有Server context重跑](baseline-replay/server-context.json)

## 8. 驗證、審查與交付邊界

舊P0 ABI、生命期及Server context已在本輪實際重跑；四個新分題分別有原件hash、immutable Git pins、native窗口及資料重建檢查器，root另重跑四分題並驗`--require-ready`確實拒絕ready。所有結果與完整檔案集合在[根驗證收據](verification-result.json)。

同行審查補正了model worker同receiver、direct-image獨立consumer、實際loaded來源固定、packed request算術，以及第四節點與前三節點不同的portal政策。修正及證據位置在[REVIEW-NOTES](REVIEW-NOTES.md)。這是本輪研究互核，不取代T01或正式Server驗收。

本包沒有執行Client／Lua／Server、沒有提交原件或完整解包member，未改正式REQ／RR／Task／native_complete。已完成分析成果與未通過gate均會一併發布於原工作branch，接續方向見[ANALYSIS-PLAN](ANALYSIS-PLAN.md)。
