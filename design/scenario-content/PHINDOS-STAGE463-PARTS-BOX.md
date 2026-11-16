# 馮德斯 Q4 蘆葦地零件箱

原版 `QuestInfo.xml` 列 Q4 為 Town 1、Lv.7、Field 463，無前置。NPC 10003 受理及交付。Content 650 要開零件箱取得兩張設計圖。馮德斯對話 142～147 交代零件箱掉在蘆葦地，146 明示靠近箱子按 Space。Product 231 對應 Item 231，為 class 6、堆疊上限 100。交付回收兩張設計圖，報酬 520 EXP、225 LeeLoo。另列的 1 點公會地區名聲待實作。

`_ActorList.xml` 有 20001（SBox）與 20152（01_Pbox）兩個同名零件箱。Stage 463 共用 `CLUST_Re_reed_01.xml` 的 PRELOADSET 明列 20152，Server 據此選 20152／PRE 1。兩個物件在 `EventObjects.xml` 的 state 0／1／2 分別列 avatar 0 和 motion 1／2／3。Cases 695 和 696 的圖表都把圖 3440 配在節點 2、`icon=3`。其他分支也有物件圖示。圖 3440 的 `TRIGGER` 欄是 `Re_reed02_01D.mef`，碰撞檔為 `reed03.bnd`。原版的精確箱子座標、開箱動畫、同場數量及掉率仍待核對。

## Server 規則

1. 一般單人 Stage 463 入場時讀取 Q4 的 Accepted 進度。圖 3440 有剩餘配額時，在可行走的 (384,236) 放一個零件箱。座標和每場一個箱子的規則以 Server 候選記錄。箱子不納入怪物 AI、擊倒計數或清場條件。
2. 用既有的 S2C `0007` 26-byte actor row。低位元組 7 走 T08 覆核的 CEventObject 建構分支，R+4 取模型 20152，R+23 傳初始候選狀態 0。物件 entity 為 `0x0107`。移除沿用 `001A` 候選。
3. C2S `0007` 的 Space 旗標沒有目標 ID。附近有可到達的地面物品時先走拾取流程，否則依 Server 位置、12 單位範圍與 BND 路徑開箱。一次產生一張 Product 231 地面掉落並移除箱子，再按 Space 拾取。掉落沿用 `0021` 商品列，在實際入包時才寫收集進度。
4. 已拾取的進度隨正常帳號保存。離開圖層或結算會清理留在場上的物品。持有兩張後，之後進 Stage 463 不再產箱，回 10003 交付時沿用現有交易，一次保存扣除、報酬與完成 key。

現有靜態證據閉合 type 7 的建構及 Space 旗標寫入。指定 v2 是否繪出 20152、是否在箱旁發布該旗標，以及物件移除和掉落的畫面仍須實機確認。 [T08 actor row](../../kr-temp-roy/20261031-165625-chatgpt-web-roy-T08-203-native-26byte-actor-spawn-type-writer-tree-dispatch-complete.md) · [Space 與地面掉落](GROUND-LOOT.md)

## 原表識別

| 解碼成員 | SHA-256 |
| --- | --- |
| Table/EventObjects.xml | `ec828746d181a3045bd796282fb567b0e4fb01ec7a24942a7e64d8a8c2a00626` |
| Field/MapFlow/CHART_Re_reed_01.xml | `26fadfb527543638f11571a51e12b7b4e32e0514f120b2f82662303780c86361` |
| Field/MapFlow/CHART_Re_reed_02.xml | `ce6380926bccae47d2a927acaf6151bbe144f5b205877ca77f4397b52d40ba4b` |
| Field/Cluster/CLUST_Re_reed_01.xml | `be75f6468e4802fd8aaa0494a31c8b2659b14286d90d625309fc9bdcd601c113` |

任務、對話、物品與 ActorList 的表版識別沿用 [馮德斯普通任務證據](PHINDOS-ORDINARY-QUEST-2843.md) 及 [爾勒梅斯收集任務的共用表版](ALSMEER-ORDINARY-COLLECTION-EXPANSION.md)。

## 離線驗證

同一趟新帳號至 Q144 的原版 BND／SQLite 驗證分別載入 Cases 695、696，每組各跑原定 15 場 Stage 463。首場核對進場 type 7、有效範圍內按 Space 後箱子移除及產生一張設計圖，隨後走正常拾取。首場後重登核對已存一張，第二場達成兩張，Ready 只出現一次。第三場起無箱子，其他怪物及既有收集任務照常。交付後檢查扣除、報酬及重新登入的完成快照。兩組均完成 **82 項普通任務及 Q144**，存於圖 199、Lv.19／327,464 EXP。指定 v2 待 AQ-24。

| 離線收據 | SHA-256 |
| --- | --- |
| Case 695 | `9d399571e846eec43b17be9e1a5f9716c63be4c3380f97cf6c7fe8658abd488d` |
| Case 696 | `378f62d7407b3e863f4b62d1429d6b192e3c5cb5be98a2cc0c292dad7f808093` |
