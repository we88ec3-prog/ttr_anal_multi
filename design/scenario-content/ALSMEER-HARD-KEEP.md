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
- Q2844「사냥터의 난이도」也是 Town 2、Lv.14、Stage 145，type 1／subtype 4。NPC 10007 負責接取與交付。目標以 Q2844 內嵌的 Content 2940 為準，擊倒 1042／PRE 2 一隻。交付發 2,460 EXP 和 Product 5342 ×10，type 5 地區名聲 1 待接入。任務進度、交付與背包使用既有普通任務交易流程。背包 metadata 兩欄先使用 Server 候選值 0。
- `--check-early-ordinary-quests` 在原參數後加上 Case 315 設定路徑、SHA-256、`315`、`-`（直線沒有分支鍵）。同一新帳號正常完成八個狩獵場和兩村 13 項普通任務。三場 Case 315 都走通六圖、拾取、結算與原隊返回，交付 Q540／541、重登，再走完 Q144，留下 Town 3 圖 199、Lv.17／263,368 EXP、90 張復活卷軸、14,112 LeeLoo。指定 v2 的難度選項、換圖、畫面與實際任務操作列 AQ-09。

## Q116／Q273 普通版怪物

同版 `QuestInfo.xml` 把兩筆任務都放在 Town 2、Stage 145、Lv.14，無前置。Q116 的內容及對話 577～581 指向普通「살로만 저격수」七隻，Q273 的內容及對話 5321～5325 指向普通「살로만 전사」八隻。Q4736／4737 則在同一 Stage 明列「성난」，分別要求憤怒版戰士、狙擊手。依 `_ActorList.xml` 的原名及現有關卡中可核對的模型，採以下精確變體。

| 任務 | NPC | 目標 Model／PRE | 報酬 EXP／LeeLoo | 道具 |
| --- | --- | --- | --- | --- |
| Q116 | 10007 | 1007／1 ×7 | 1,720／694 | Product 234 ×3 |
| Q273 | 10053 | 1006／1 ×8 | 1,720／983 | — |

兩筆都是同一位 NPC 接取及交付，各一點公會地區名聲待實作。Q273 的 NPC 10053 交付沿用 Q136 後的普通任務順序。

`CLUST_H_keep_01.xml` 的群組 19～22 只有上述模型的 PRE 2。普通版可於 `CLUST_Re_keep_01.xml` 的群組 10（1007／1 ×2）、12（1006／1 ×2）核對，該表解碼 SHA-256 為 `1bacd222563a6d7ab49a333ac258e1bc4ae5c6c6de72d0caa05a6859959d7718`。這批採兩組原表普通怪的身分與數量，在 Stage 145 另加 Server 候選出場。原版怪群在困難前哨的精確位置與出場時機仍待取證。 [場景與群組來源](ALSMEER-ORDINARY-CLUSTER-QUESTS.md#來源)

- Q273 為 Accepted 時，在 1754 追加兩隻普通戰士，候選位置 (372,302)、(372,354)。Q116 為 Accepted 時，在 1755 追加兩隻普通狙擊手，候選位置 (368,283)、(368,294)。追加怪每隻給 12 擊倒 EXP。
- 追加群組與既有憤怒怪一起出現，各任務依 Stage、Model／PRE 獨立計數。Stage 466、468 的同型普通怪無法推進前哨任務。任務達成後下一場移除對應追加群組，通關條件及基礎經驗照常。

兩個全新帳號用一般與輪替 Case 各走完 42 場爾勒梅斯狩獵。Stage 466、468 先遇同型普通怪並核對 Q116／273 均仍為 0，再跑五場 Stage 145。前三場含 Q272 及本批兩組，結算各 316 EXP。第四場 Q272 已達成，剩 Q116／273 兩組共結算 292 EXP。第五場恢復原陣容及 244 EXP。四項普通／憤怒任務分別核對 7／8 與 2／4，逐筆只有一次 Ready。回村核對報酬、Q136 後向 10053 交付以及重新登入。兩組都完成 **86 項普通任務及 Q144**，存於圖 199、Lv.19／333,042 EXP。實機待 AQ-26。

| 離線收據 | SHA-256 |
| --- | --- |
| 一般配置 | `38f0ea8288bcf07225dac9cbff5793015b5c46fddad0bd63acde7162699bb67a` |
| 輪替配置 | `516ea498024c6558d793c74f5dc0af46b79b8664bcc60f4d289c37f361bca0a7` |

## Q2844 報酬道具

`Table/QuestTalk.xml`（解碼 SHA-256 `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`）引用對話 48231／48236／48237。`Table/TalkTable/05_Alsmeer.xml`（解碼 SHA-256 `970354e31b0853dca3d3be20709bf016bb63d663b2244511c12a42611d127731`）的 48236 明確要求打倒爾斯梅勒前哨 Hard 的首領。Stage 468 的原版 `Re_keep` 與此目標分開。

- `Table/Product.xml`（解碼 SHA-256 `8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c`）將 Product 5342 對應到 Item 5308「윙(순간이동)」。背包商品 ID 使用 5342。
- `Table/ItemTable2.xml`（解碼 SHA-256 `7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2`）列出 class 13、堆疊上限 255、冷卻群 3。道具說明為瞬間移動到傳送點，須在傳送點已開放時才可用。
- `Table/ItemUsableTable.xml`（解碼 SHA-256 `30970e8d4cffe80d6ad18552fb93601e4b0a5a8e6cfa2030064fd44192ef038c`）只列 action 10、priority 5，沒有目的地欄位。傳送點的選擇、開放條件、使用請求與扣除時機仍待確認，因此目前接通領取與保存。
- `Table/_PortalList.xml`（解碼 SHA-256 `3140d4c0703181584de2dcab0a4a48c288cb21de887b692a2f584fc88639fa56`）只對照入口開關狀態及特效檔名。韓文介面的 `kOptionKeyCom1` 起列有 A 起的傳送點移動催促指令。兩處都未提供 Item 5308 的目標選擇規則。

加入 Q2844 後，同一套原版 BND／SQLite 路線已從新帳號完成 14 項普通任務及 Q144。Stage 468 未觸發 Q2844，Stage 145 達成通知只出現一次。離線核對確認 2,460 EXP、十件 Product 5342、錢包無額外入帳，重登後完成紀錄與背包均保留，最後存到圖 199、Lv.17／265,828 EXP。指定 v2 仍待 AQ-10 驗證。
