# 精確來源需求與解除條件

`Master.stp` 已取得及完整使用，**不再列為待補件**。本文件區分「Master宣告的carrier」「原件內已選中的引用」「尚待cache／實際安裝決定的winner」；補檔不是由相同stem猜定原生選取。完整定位和條件在[選定路由](master-resource-closure/selected-resource-routes.json)、[新Q119資料](journey-families/data-evidence.json)。

## 1. 最小下一批材料

| 次序 | 所需材料 | 為何需要／可解除什麼 |
|---:|---|---|
| 1 | 同版`fcs.flu`，或cache-miss時實際scan／mount來源與選中group entry的可核記錄 | 固定CHA_ABF／MAP_FLD的實際目錄、同名優先序及mesh packed flag；僅Master不提供winner |
| 2 | `Character/Cha/Base.stp`、`Character/Npc/Base.stp`、`Character/Obj/Base.stp`；既有Mon Base保留原hash與安裝來源 | 補descriptor／Items.ipk／Include；現有Base root=Mon只是conditional structural match，不是整套模型內容 |
| 3 | selected avatar carriers，先由上一項descriptor／RelativePath實際展開；已知方向包括`Character/Mon/Avatar/02_Stoncken.stp`與`00_Alphonso.stp` | 完成已可解析兩模型的base mesh／motion／texture。父provider先查，所以不能先認定avatar一定是winner |
| 4 | `mushroom12D.fld`、`town014S.fld`的真正MAP_FLD entry／carrier；全Q119另需mushroom01D／04D／07D與town001D相關來源 | 補圖形map及子依賴。**不指定Field.stp為FLD來源**；`town014S`不與`town014`混用 |
| 5 | `Image/Base.stp`、`Image/Prologue.stp`及selected DDS／條件ETF；必要portrait與UI payload | 正確依probe分支選原path或ETF。Prolog19七個picture path及direct Aisen00_1獨立保留，不能只改副檔名就標present |
| 6 | 實際聲音檔／有效原安裝來源：舊P0 BGM024／147／148、Stoncken音效與voice；新Q119 bodyfall／BGM003及所選voice | Master只宣告Scenario00–12及Prologue等所列聲音provider；**不猜造Sound/BGM.stp或Monster包**。native voice13–32沒有此Master宣告不等於全局不存在 |
| 7 | `Field.stp`、`UI/LUA.stp`，並保留各自完整來源hash／member index | 針對真正MEF樣本、UI content與可能的首次入口，沿實際consumer追蹤；Field xml/mef slots不等於已知grammar |
| 8 | `Map/MiniMap.stp`、`Synopsis.stp`、`Effect/Effect.stp`與所需UI／Panel／Image資源 | 補七族真實案例：MMT與指向texture／markers、book01..04模型、Effect98的EFF及後代；Master有宣告不等於已供應payload |

這是可依賴關係分批取得的清單；拿到新carrier只重跑受影響的node，不必重做已固定的所有bindings。來源應保留版本／path／size／hash；不同BIN版本必須另作VA mapping，不能套本版地址。

## 2. Descriptor 與 avatar 不混為一件

舊P0兩scene共有15個不同模型，已解析1086／102的descriptor；其餘13個缺descriptor如下。右欄是Master的同stem **search target**，不是已選中的CHA_ABF entry，也不是已存在的payload。

| 模型ID | descriptor basename | Master avatar search target |
|---:|---|---|
| 1478 | N01_Soma.abf | Character/Npc/Avatar/N01_Soma.stp |
| 1479 | N02_Pipa.abf | Character/Npc/Avatar/N02_Pipa.stp |
| 1480 | N03_Sblm.abf | Character/Npc/Avatar/N03_Sblm.stp |
| 1481 | N04_Isla.abf | Character/Npc/Avatar/N04_Isla.stp |
| 1482 | N05_Aelt.abf | Character/Npc/Avatar/N05_Aelt.stp |
| 1483 | N06_Grnt.abf | Character/Npc/Avatar/N06_Grnt.stp |
| 1484 | N07_Crmd.abf | Character/Npc/Avatar/N07_Crmd.stp |
| 1485 | N08_Ruko.abf | Character/Npc/Avatar/N08_Ruko.stp |
| 1486 | N09_Epds.abf | Character/Npc/Avatar/N09_Epds.stp |
| 2064 | 11_SupplyCabH.abf | Character/Obj/Avatar/11_SupplyCabH.stp |
| 10107 | 07_Mimi.abf | Character/Npc/Avatar/07_Mimi.stp |
| 10320 | 14_Alster.abf | Character/Npc/Avatar/14_Alster.stp |
| 10323 | 14_Tommy.abf | Character/Npc/Avatar/14_Tommy.stp |

全Q119新增範圍另有7個缺descriptor：1478–1481、10002、10003、10047；已有1001／1009／1022／1086四份。這兩個集合有重疊且分母不同，不把7當成13已減少。新descriptor取得後才可按它真正的RelativePath／BaseFile／TextureList／Include展開後代。

## 3. 這次能存取材料的界線

本輪精確查詢Field.stp／Base.stp／Stoncken／Prologue／LUA及一次簡化查詢，只找回同大小Base與既有研究資料，沒有取得新的上述carrier。這是有限查詢結果，並非宣稱使用者所有磁碟或歷史附件不存在它們。新Master已由提供的本機副本實際分析。[來源可用性紀錄](source-availability.json)

若只是補上Master，不會解除缺少payload、cache winner或實際device接受的條件。`--require-ready`目前仍應回2；取得新材料後必須重跑相關gate，才能改其狀態。
