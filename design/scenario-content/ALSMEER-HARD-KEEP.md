# 爾斯梅勒前哨 Stage 145／Case 315

`Table/_CaseList.xml` 的 Stage 145 只列 Case 315，引用 `Field/MapFlow/CHART_H_keep_01.xml` 與 `Field/Cluster/CLUST_H_keep_01.xml`。這組資料與 Stage 468／Cases 705–706 使用的 `Re_keep` 相互獨立。原版 Case 表的解碼 SHA-256 為 `a6282323e287900512e515be01927ae3f75fa0c1540e0261473530eb0487043a`。圖表與群組表的解碼雜湊隨 [關卡定義](alsmeer-stage145-case315.scenario.json) 固定。

## 路徑、碰撞與怪物

圖表為單一路徑 **節點 2 → 3 → 4 → 5 → 6 → 1**。下表地圖、TRIGGER 與 BOUND 來自 `Table/_MapList.xml`（SHA-256 `cd47d8ca42f4297f6584a2c0c8807ae76352e3b353855b3989f660e64fd27f8c`）。BND 從原版 `Map/BoundMap.stp`（SHA-256 `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8`）取 `BoundMap/<檔名>`，六份均為 v2、768×768、兩層。對應雜湊列於下表。遊戲原始資源留於本機。

| 節點／圖 | 原表 TRIGGER | 碰撞檔及解碼 SHA-256 | Server 候選遭遇 |
| --- | --- | --- | --- |
| 2／1753 | `H_keep01_01N.mef` | `keep02.bnd` `03e4fcd5dd61deff5620daaadd840c0164e2521063937ca94e3e783e8ea0da29` | 群組 18＋3，1024／2×2、1005／1×1 |
| 3／1754 | `H_keep02_01E.mef` | `keep04.bnd` `189834d33de3743e7b62b220fe36f8f7be06127a5b4e516ac1e25e11af53cefd` | 群組 20，1006／2×2 |
| 4／1755 | `H_keep03_01N.mef` | `keep05.bnd` `5c6b1b2f069bd25e8e40db1dc442ba03506740ae81acdb822319023b3ad22709` | 群組 22，1007／2×2 |
| 5／1756 | `H_keep04_01N.mef` | `keep06.bnd` `6a68eac0314c9f03a055763784fed8249077483da5813c8560cd085f303d5bec` | 群組 10，1002／3×2 |
| 6／1757 | `H_keep05_01D.mef` | `keep10.bnd` `f20317a89c18ec11e15253851cb861f2fda5931d7880e76ea1d9864537aa0612` | 群組 24，1018／1×2 |
| 1／1758 | `H_keep06_01B.mef` | `keep14.bnd` `611900cb7f319d4fcfb0b87a0f39eedaac40ded7202ac595ef08a02b54aede89` | 群組 1＋5，首領 1042／2×1、1005／2×1 |

群組成員與數量依原表。群組放在哪一圖、座標、AI、首領與小怪同時出場、清場出口、經驗與掉落，採 Server 候選。TRIGGER 欄位提供檔名引用，這套流程由標為 `NOT_NATIVE_MEF` 的獨立關卡定義執行。

## 正常入口、結算與任務

- 隔離驗收 Host 可用 `-IncludeHardKeepHuntingGround`。Stage 145 和 Stage 468 能同時登記。爾斯梅勒單人隊長確認 `0064` Stage 145 後按開始，Server 用既有 `0038` 裝入 Case 315，按圖表依序下發六個節點。
- 每張清怪後走到出口按 Z。最後一圖首領 1042／PRE 2（성난 보어라이더）和小怪一起出場。離線候選中，前五圖擊倒 132 EXP、首領 40 EXP、通關 72 EXP，共 **244 EXP**。首領掉一張 Product 183，Space 拾取。結算回圖 183 的原隊伍，離隊後主線保存點不變。
- 原表 Q540、Q541 皆為 Town 2、等級 14、Field 145、type 1／subtype 2，無 Demands。Q540 向 10005 接取及交付，目標是一隻 1042／PRE 2。Q541 向 10006 接取及交付，目標是五隻 1018／PRE 1。兩任務各給 **1,720 EXP、926 LeeLoo**，沒有物品報酬。地區名聲 1 仍待接入。擊倒限定 Stage 145，以免把 Stage 468 的同型 1018 計入。
- Q2844「사냥터의 난이도」同樣引用 Stage 145，向 10007 接取，報酬是 2,460 EXP 及 Product 5342 ×10。Product 5342 對應 Item 5308 的瞬間移動道具，其使用目的地與操作另需確認。Q2844 此輪仍待實作。
- `--check-early-ordinary-quests` 在原參數後加上 Case 315 設定路徑、SHA-256、`315`、`-`（直線沒有分支鍵）。同一新帳號正常完成八個狩獵場和兩村 13 項普通任務。三場 Case 315 都走通六圖、拾取、結算與原隊返回，交付 Q540／541、重登，再走完 Q144，留下 Town 3 圖 199、Lv.17／263,368 EXP、90 張復活卷軸、14,112 LeeLoo。指定 v2 的難度選項、換圖、畫面與實際任務操作列 AQ-09。
