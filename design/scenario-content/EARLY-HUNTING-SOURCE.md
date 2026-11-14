# 馮德斯至爾勒梅斯一般副本原表核對

[原表索引](early-hunting-kr-source.json)記錄 10 個 Case 的節點、完整路徑、地圖 ID、怪群候選和碰撞檔 SHA-256。資料從 KR 原始安裝的 `Table.stp`、`Field.stp`、`Map/BoundMap.stp` 讀取，索引記錄封裝和引用成員的雜湊。怪群的 `members` 每列依序為 Model、PRE、COUNT。Git 保存衍生證據，原始 BND 保留於本機。

| 村莊 | Stage | Case | 每個 Case 的完整路徑數 | 終點節點／地圖 |
|---|---:|---|---:|---|
| 馮德斯 | 464 bluetree | 697／698 | 2 | 9／3459 |
| 爾勒梅斯 | 465 fullmoon | 699／700 | 2 | 7／3468 |
| 爾勒梅斯 | 466 barley | 701／702 | 4 | 9／3479 |
| 爾勒梅斯 | 467 reservoir | 703／704 | 4 | 8／3489 |
| 爾勒梅斯 | 468 keep | 705／706 | 2 | 8／3501 |

村莊歸屬由 `_MapTitleList.xml` 的 Stage 圖資前綴和 `QuestInfo.xml` 的 `town`／`field` 交叉核對。Stage 464 使用 `Field_01_bluetree.dds`，其對應任務在 Town 1。Stage 465 使用 `Field_02_fullmoon.dds`，Q10、Q11 等對應 Town 2。任務等級屬任務條件，關卡自己的入場等級仍待確認。

## Stage 465 開發順序

1. Case 699／700 共用節點路徑 `1 → 2 → 3 或 4 → 5 → 6 → 7`，分岔送出的地圖不同。Case 699 的節點 3／4 分別是圖 3463／3464，Case 700 為圖 3462／3465。兩個 Case 均從圖 3460 開始、在圖 3468 結束。四個分岔圖共用兩份地形 BND，但各有不同的 Trigger 引用。
2. 用已核對的 BND 設置各圖出生點、怪物與出口，逐圖核對可達性。Cluster 已提供 Model／PRE／COUNT 的組合，仍需核對各圖使用哪個群組、何時出現及首領身分。座標與節奏可由 Server 內容設定建立候選，保留來源與待實機項。
3. 現行一般副本大廳以 Town 1、Stage 462／463 為範圍。擴充時依所在村莊與已配置的 Stage 過濾正常選關，沿用 `0064` 選關、`009A` 回覆和 `0038` 安裝 Stage／Case 的候選流程。Case 在開場時決定，跨圖沿用同一 Case；結算則回到出發村莊及原單人隊伍。
4. 從完成 Q132 的正常帳號在爾勒梅斯建單人隊，分別走兩個 Case 的各兩條分支。驗證清場後按 Z 換圖、末圖首領、結算、回原隊伍，以及回村可繼續 Q133。Stage 464 則從馮德斯的原大廳驗證，與既有 Stage 462／463 共存。

這批驗證已核對 28 條路徑、53 個地圖 ID、41 份 BND 成員的對應與雜湊。Server Release 的 `LocalTutorialBounds.Read` 已逐份接受 41 個 BND。MapList 的 `TRIGGER` 欄記錄原始名稱。出生點、怪群配置、通關獎勵、原生 MEF 執行和 Client 實機仍有各自的驗收工作。
