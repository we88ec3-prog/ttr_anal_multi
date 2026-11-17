# 一：Case103／Map191→192 真實資料、控制關聯與發布順序

日期 2026-11-17；原件與固定來源見 [來源清單](source-manifest.json)。本題完成的是來源分類、可實作的參數化依賴及缺值阻塞，不宣稱已取得原廠出口位置／合法出生點或已能部署。

## 1. 真實關係已回到來源，不再只引用前稿摘要

本輪讀回固定 commit `83959c0…` 的原始解出 MapChart 與 MON_CLUST，並從原 Table.stp 重解 `_CaseList.xml`／`_MapList.xml`。

| 識別域 | 已有來源的值 | 不可替代的資料 |
|---|---|---|
| Case | 103，STAGE=19 | 不是 MapID、Q quest key 或 point key |
| 圖節點 | node1→node2 | 不是一次自動轉場／勝利事件 |
| 地圖 | node1=191；node2=192；weight各100 | 不是出生點坐標 |
| 視覺／BOUND | scenario_pathofpindus01D／02D；BOUND對應不帶D | 兩張不同資源，不能混用碰撞或spawn |
| TRIGGER | S_pathofpindus01.mef／02.mef | 這個名字尚未接上官方首次loader |
| 圖表位置 | node1=(360,372)，node2=(360,276) | 是圖表佈局欄位；沒有證據可當世界spawn |
| Cluster | set0/baselevel0；三組模型/PRE/count | 沒有出口key、世界坐標、死亡群清條件或wave時機 |

Field.stp 本體本輪未重新取得；公開的兩個完整解出來源已透過 GitHub 讀取。研究包只保存必要關係及 source SHA／blob，不再公開完整遊戲 member。驗證器明示「這兩個 Git 原文未由本機重算」，不可把7個實際STP member驗證數加成9個。

## 2. 出口與出生點的精確資料阻塞

`Table/_PortalList.xml` 已直接從原件讀取：10筆效果列，整份屬性集合只有 `ID／STATE／FILE`。它選的是portal效果，沒有x/y/radius/destination/world EntityId。不能把其中ID擅自配成0027的出口key，也不能用effect存在當出口幾何已取得。

W3-09既有的兩個重建候選，本輪從原 BoundMap.stp 再核：

| 地圖 | prior W3候選（未採用） | 本輪靜態重算 | 限制 |
|---|---|---|---|
| 191 | (308.5,437.5) | 以cell(308,437)為中心99×99兩層皆0 | 不是原生spawn，未核角色半徑、高度、動態障礙或實機 |
| 192 | (394.5,307.5) | 以cell(394,307)為中心67×67兩層皆0 | 同上 |

圖表坐標(360,372)在Map191取到(0,0)，在Map192取到(0,1)，再次證明不能跨圖搬用。這些零值方塊只是所選靜態資料中的候選；沒有升格「合法可走／可出生」或S00批准。`transition-profile.json` 的 `approved_spawn` 仍為null。

**解除條件有兩條，不能混在一起：**取得有來源、能對到原版producer/consumer的出口及出生配置；或由S00明確採用有標籤的相容Server重建政策，再安排正常流程驗收。原廠座標無法取得不是Server不能設計新配置的理由，但本研究不能私自把候選寫成已採用資料。

## 3. 新補證：0008 的完整 relation producer

舊稿已證000A需要世界actor及relation記錄；這次追到relation的實際producer。common initializer的`4ADD98`寫`[field+44]=4AF530`，`(44-4)/8=8`；`4ADDA2`另寫`[field+54]=4AF920`，對應000A。

S2C0008 handler `4AF530..4AF91C`：application前4 bytes為opcode及u16 replace flag，rows每22 bytes。非零replace先清`FAB228`並呼`4E1070(&FAB148)`，清的是relation map，不是world actor map。該flag在長度計數前便讀取，發送端不可利用短包分支；嚴格serializer必須完整且長度為4+22N。

| row offset | 型別 | relation record去向 | 意義界線 |
|---:|---|---|---|
| 0 | u32 | +00 | relation key，不是u16 actor ID |
| 4 | u8 | +20 | raw byte，完整業務枚舉未命名 |
| 5 | u8 | bit0→+28，bit1→+29 | 其他bits在此兩個writer未使用 |
| 6 | u32 | +0C | raw DWORD |
| 10 | u32 | +10 | raw DWORD；local路線有後續consumer |
| 14 | u16 | +14 | local路線交53A9D0，不擅改成group ID |
| 16 | u16 | +16 | raw WORD |
| 18 | u16 | +18 | raw WORD |
| 20 | i16 | +24 dword | 明確sign-extension，不是無號65535 |

record大小0x2C；缺記錄才配置，新建+04/+08初值0。record+1C由`key==F93930`寫0/1。row更新不表示已把角色綁入控制器。現有record的leader欄位由後續000A補上；0008全量reset後舊leader欄位不能假定仍存在。回傳0x100是本機handler結果，不是每筆關聯已就緒的網路ACK。

## 4. 000A 的真正資料依賴

S2C000A的application是`u16 opcode | u32 relationKey | i8 count | count*(u16 actorId,u16 bindingKey)`。count線上是signed byte；本規格選定的普通控制配置只允許1至3個槽，不把3誤稱原wire的一般上限。

`4AF920`先查`FAB148`中的relationKey，miss不建立／不排隊。命中後比較F93930；本地關聯會清／準備controller。每列再查`FAB138`的worldActor，missing跳過，沒有「actor稍後到達會自動重播」的機制。不同pair分支寫控制器的不同slot；正常leader列會更新relation+04的actorId與+08的model，actor+9C寫relationKey。**+9C因而不能命名為任意encounter group或生命週期ID。**

Server設計必須保存relationKey、actorId、bindingKey各自來源，不能用model1、角色名稱或node1頂替。0008本輪解碼多數欄位仍是raw用途；「已知布局」不等於「所有業務值已綁定」。

## 5. 可直接實作的相容發布偏序

這是本研究提出的Server策略，不是官服pcap或原Server固定序列。`transition-profile.json`與`contract.py`給出可檢查的偏序。

1. Server確認Case103/node1→node2的合法條件；核對出口意圖的(category,key)及session，不從001C自行推定目的地。
2. 先完成既有Q run及適用解除，封閉舊generation；停止排送舊圖point delta、外觀操作和過期actor更新。generation僅保存在Server，不添加原wire未讀欄位。
3. 採用已證loading流程，按清楚的保留／移除政策整理舊world。已是Scenario/Formation/page7時，不為同類節點轉場盲目重建005F；確需更換才用其合法路徑。
4. 0012載Map192。它先清points／reset controller，故point重建及控制重綁都必須在其後。不能以同MapID重送當資源重載重試。
5. 發布本圖world actor快照與有效0008 relation資料；兩者之間可依其他已證context需求排序，但**兩者都必須先於000A**。
6. 000A綁本圖正確角色；0027發布完整points。兩者都完成本次發布後再結束loading並安排0014。這裡「發布完成」只是Server順序，不是假造Client資源成功ACK。
7. 分開核對controller-ready、mask1、Q等待mask2、controller+58與UI capture。不能用固定毫秒delay推定所有gate恢復。
8. 如要在此啟動A1：資料版本、Q空閒、本圖唯一point及A1單次鍵政策都成立才發0047。匹配003F只作既有End報告，00EB只作適用的等待解除，兩者都不是setter命中證明。

0038等既有instance/context資料需求未被本規格刪除；不聲稱只發本節列出的幾個opcode就構成完整登入或任意副本入場。

## 6. 本題結案界線及下一條證據

**已完成：**真實graph/Map/BOUND來源核對、Portal表排除、候選與原生值區分、0008→000A producer/consumer、參數化發布偏序及A1掛接點。

**未完成：**可直接部署的出口key／位置／半徑、採用後spawn、當次0008 raw業務值、world/formation快照及資源發布hash。這些在JSON中明確null；不是把0當未知。Server應提供合法配置或S00採用政策，實機確認幾何與雙端狀態。

下一入口不是重掃MapChart坐標，而是所選出口的0027資料生產來源／Server配置決策，以及model/角色關聯資料的有來源實例。沒有來源的數值不得以模型測試向量補成正式封包。
