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

## Stage 465 Server 關卡

| Case | Server 定義 | SHA-256 |
|---|---|---|
| 699 | [Fullmoon 699](alsmeer-stage465-case699.scenario.json) | `6f1f3b7bd61aa9a4abd7f350a92144614ca937a476dd57fc74951f8e87bccc58` |
| 700 | [Fullmoon 700](alsmeer-stage465-case700.scenario.json) | `54333ee7d405f0fdc38ab944f59b0c2509ed7725c5bce5e0c751f80d4c358dda` |

這兩份內容採 `NOT_NATIVE_MEF` 格式。Server 以 Case 原表的地圖 ID 和分支核對定義，七份 BND 各自固定雜湊，再檢查出生至怪物、出口的可達性。怪群組成由 `CLUST_Re_fullmoon_01.xml` 的 Model／PRE／COUNT 取得，分配到哪張圖、點位及首領判定由本機 Server 配置。末圖 1085 與 1015 同場，清場後走出口按 Z 結算。每條六圖路徑暫定 112 擊倒 EXP、24 結算 EXP。啟用 `SCENARIO_CATALOG` 掉落時，末圖首領掉落 Product 183。建議戰鬥等級 11 用於本機怪物與角色成長配置，原版關卡解鎖條件仍待取證。

原有馮德斯主配置與替代 Stage 設定照常使用。Stage 465 可額外用 `TARTAROS_LOCAL_HUNTING_GROUNDS__699__PATH` 和 `TARTAROS_LOCAL_HUNTING_GROUNDS__699__SHA256` 帶入；也可選 Case 700 並改用鍵 700。同一 Stage 每次只設一個主 Case，另一個可由既有 `TARTAROS_LOCAL_HUNTING_GROUND_ROTATION__700__PATH` 和 `__SHA256` 指定輪替。各來源共用 BND 目錄與目前的角色經驗政策。Server 只受理所在村莊已配置的 Stage，選關使用 Stage 465，進場發布當次 Case；結算返回爾勒梅斯及原單人隊伍。

本機驗收啟動器可加 `-IncludeAlsmeerHuntingGround`，載入 Case 699 及 700 輪替。BND 目錄需另備 Fullmoon 的七份碰撞檔。先用 `-PreflightOnly -IsolatedPorts` 檢查兩個 Case 的村莊、起始圖、雜湊和預期經驗。

隔離 Host 已通過上述預檢。兩個 Case 都回報 Town 2、最初圖 3460、總經驗 136，Case 700 登記為輪替。預檢使用升級至主線元件 V2 的測試資料庫副本，結束後關閉隔離 Host。

兩村共用大廳進場與結算流程。狩獵場在建隊進村與結算回原隊時，於場景啟用前送出背包、貨幣與銀行狀態。主線演出或主線副本返回仍使用既有的城鎮載入確認，讓任務、角色與資產在同次切換同步。

四條離線路線均從空白 SQLite 建立帳號，正常打完馮德斯 Stage 462／463，再由 Q132 抵達資格從廣場建隊進爾勒梅斯。Case 699 的分岔圖是 3463／3464，Case 700 是 3462／3465。各場應用層核對 136 EXP、一張復活卷軸、結算回原隊伍、離隊後續接 Q133，最後完成 Q144、圖 199。Q144 當下的參戰角色樣本為 245,452 EXP、背包六張復活卷軸，錢包 3,598 LeeLoo。指定 v2 的正常選關、分支、怪物、結算與回村畫面待實機。 [TS-38 批次驗收](../testing/S00-CONTENT-BATCH-TESTS.md#爾勒梅斯一般副本)

## Stage 466 Server 關卡

| Case | Server 定義 | SHA-256 |
|---|---|---|
| 701 | [Barley 701](alsmeer-stage466-case701.scenario.json) | `c439ec3602efc7f0885f240df319538a7f5591e2a27b9ed145171a6fb8118246` |
| 702 | [Barley 702](alsmeer-stage466-case702.scenario.json) | `39c1ac5a9b745313849db2831f2b12b3f397f04f4891dfdfb1fd1c90e3eb1848` |

兩個 Case 的節點順序皆為 `1 → 2 或 3 → 5 → 4→7 或 6→8 → 9`，每條路六圖。Case 701 的節點 2／3 是地圖 3471／3472，Case 702 是 3470／3473。兩個 Case 均由圖 3469 開始、在圖 3479 結算。Server 啟動時按 Case 檢查全部九個節點、各自可到達的下一節點及原版 BND 雜湊。

兩處分岔的出口可分別選擇。本機候選用 `CLUST_Re_barley_01.xml` 的 Model／PRE／COUNT 設定怪群，首領 1088 在末圖與 1015 同場。出生、出口、怪群分配及首領判定為 Server 配置。每場暫定 128 擊倒 EXP、32 結算 EXP，啟用 `SCENARIO_CATALOG` 時首領掉落一張 Product 183。角色成長使用建議戰鬥等級 12，原服關卡條件仍待取證。這些定義使用 Server JSON，標示 `NOT_NATIVE_MEF`。

既有 Host 驗收啟動器加 `-IncludeBarleyHuntingGround` 會加載 Case 701 與 702 輪替。該選項可與 Stage 465 的 `-IncludeAlsmeerHuntingGround` 一起使用，BND 目錄另需九份 Barley 碰撞檔。直接設定 Host 時，使用 `TARTAROS_LOCAL_HUNTING_GROUNDS__701__PATH` 和 `TARTAROS_LOCAL_HUNTING_GROUNDS__701__SHA256`，Case 702 可使用 `TARTAROS_LOCAL_HUNTING_GROUND_ROTATION__702__PATH` 和 `TARTAROS_LOCAL_HUNTING_GROUND_ROTATION__702__SHA256`。

原版 BND 與隔離 SQLite 的八條新帳號旅程均通過。Q132 後先在爾勒梅斯完成 Stage 465，再使用同一支隊伍選 Stage 466。兩處分岔分別選出口鍵 1／3、5／6，覆蓋每個 Case 四條路線。各場結算 160 EXP、拾取一張復活卷軸並回原隊伍；接續 Q133 至 Q144 後，角色樣本為 245,612 累計 EXP，背包七張復活卷軸，錢包 3,598 LeeLoo。 [TS-39 批次驗收](../testing/S00-CONTENT-BATCH-TESTS.md#爾勒梅斯一般副本)

隔離 Host 已核對 Stage 465、466 的主 Case 與輪替 Case 可同時載入。Stage 466 兩個 Case 都回報 Town 2、起始圖 3469、每條路線 160 EXP。輪替登記屬 Host 設定驗證，實機連刷時的輪替與畫面仍待驗。
