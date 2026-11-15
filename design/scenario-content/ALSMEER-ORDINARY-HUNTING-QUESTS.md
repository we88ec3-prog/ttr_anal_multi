# 爾斯梅勒普通狩獵任務 Q10、Q12、Q22、Q35、Q96、Q112

KR `Table/QuestInfo.xml` 解碼 SHA-256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`。六筆皆為 Town 2、type 1／subtype 2，無 Demands，AcceptAction／CompleteAction 為 type 1。怪物名稱依同版 `Table/_ActorList.xml`（SHA-256 `b01ae70817c79126b89292567e32d4c806c3ef31478b6a2eb96dcfd21e2c78f7`）對齊。

| 任務與 Content ID | NPC／等級 | Field 與目標（Model／PRE ×數量） | 交付 |
| --- | --- | --- | --- |
| Q10 무법자，95／96 | 10004／11 | 465，뱀프 1002／1 ×12、티키 1005／1 ×5 | 1,080 EXP、630 LeeLoo、Product 232 ×5 |
| Q12 붉은 토끼 두목，98 | 10004／11 | 465，적토 1028／1 ×1 | 1,080 EXP、882 LeeLoo、Product 183 ×1 |
| Q22 식상한 정찰，104 | 10007／11 | 465，어린 뱀프 1002／4 ×8 | 1,080 EXP、504 LeeLoo、Product 234 ×3 |
| Q35 문젯거리 아이들，100 | 10004／11 | 465，만드라 로리 1010／1 ×5 | 1,080 EXP、504 LeeLoo |
| Q96 강행돌파，111 | 10005／12 | 466，살로만 저격수 1007／1 ×5 | 1,220 EXP、677 LeeLoo、Product 232 ×5 |
| Q112 살로만 족의 중무장，33 | 10005／13 | 468，중갑 살로만 전사 1018／1 ×5 | 1,480 EXP、617 LeeLoo、Product 233 ×3 |

六筆另有原表 type 5 地區名聲 1，Server 尚待接入。Product 183 是復活卷軸，232／233／234 是 HP／SP／MP 回復卷軸。

## Case 群組、候選分支與出場

Cases 699／700、701／702、705／706 的群組來源由 `Table/_CaseList.xml` 核對，解碼 SHA-256 `a6282323e287900512e515be01927ae3f75fa0c1540e0261473530eb0487043a`。下表的群組成員來自原版，地圖上的位置與出場規則沿用既有 Server 候選。

| Stage | 原版群組檔及 SHA-256 | 目標路線與每場數量 |
| --- | --- | --- |
| 465 | `CLUST_Re_fullmoon_01.xml`，`77ea3ef85edf704ac5990c2cb3826c1b87beb0a1ace745d52bb3c94c6273dfef` | Cluster 1、3、6、8、9。選第二圖出口鍵 4 到圖 3464／3465，取得兩隻普通 뱀프。首圖 3460 有一隻 티키和兩隻 만드라 로리，圖 3466 有兩隻 어린 뱀프，圖 3467 有一隻 적토。 |
| 466 | `CLUST_Re_barley_01.xml`，`c2ff8ff8b2afed7734c0573468f6d5fe5f76fbeb96e349d3bde11e2a2e60b4bb` | Cluster 10。第三圖選出口鍵 6 到圖 3476，兩隻狙擊手。離線用首圖出口鍵 1、第三圖 6。 |
| 468 | `CLUST_Re_keep_01.xml`，`1bacd222563a6d7ab49a333ac258e1bc4ae5c6c6de72d0caa05a6859959d7718` | Cluster 10、11。第二圖選出口鍵 4，先經圖 3498／3499 的兩隻狙擊手，圖 3500 有兩隻重甲戰士。這裡的狙擊手同 Model／PRE，仍只屬本 Stage。 |

## Server 規則及驗證

- 沿用 `-IncludeHuntingQuest`。到 Town 2 圖 183 後，交談距離、NPC、冒險團最高角色等級及已接狀態共同決定授權。普通任務與主線各有獨立狀態和保存。
- 目標由 Stage、Model、PRE 配對。有效擊倒、同批戰鬥 EXP、計數及達成通知的重試收據同一 SQLite 交易提交。多個已接取的任務各自累計。Q10 的兩項各自封頂，兩項達標才送 `0045`。
- `0036` 接取沿用已核對的 Quest ID 形狀。回 NPC 的 `001C/category 3` 是 Server 交付候選，同 NPC 的主線交接優先。多項 Ready 時，同 NPC 每次候選交付處理一項，按目前清單順序。指定 v2 的選任務、完成文字及未完任務列表仍待取證。
- 交付時保存完成旗標、接取角色 EXP、錢包及道具報酬。Q35 走無物品獎勵的錢包更新，既有背包逐格維持。既有 Q1／Q67 的達成收據可以由舊 SQLite 讀取。
- `--check-early-ordinary-quests` 在同一全新帳號完成馮德斯五項、爾斯梅勒六項普通任務與七個狩獵場。第一場 Stage 465 後重登，Q10 為 2／12、1／5，Q12 仍為 Ready。改打 Stage 468，確認狙擊手不會更新 Q96。爾斯梅勒共 13 場，全部交付後重登核對完成 keys，再完成 Q144、Town 3 圖 199。Server 離線樣本 Lv.17／259,196 EXP、87 張復活卷軸、12,260 LeeLoo。為保留復活卷軸堆疊空間，路線透過正常商店售 20 張，入帳 4,000 LeeLoo。
- 同一組驗收分別使用 Cases 699／701／703／705 和 700／702／704／706，兩條旅程結果一致。指定 v2 實機列 AQ-06～08。其他爾斯梅勒任務仍須逐批對齊出場、道具或重複條件。Stage 145 的前哨／難度為原版 Case 315（`CHART_H_keep_01.xml`／`CLUST_H_keep_01.xml`），與 465～468 的既有關卡獨立。

[既有四個狩獵場規劃](EARLY-HUNTING-SOURCE.md) · [馮德斯普通任務與封包來源](PHINDOS-ORDINARY-QUEST-2843.md)
