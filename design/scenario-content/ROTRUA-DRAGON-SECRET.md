# 羅特魯亞主線 Q109 至 Q145

Q108 完成後依 QuestInfo 續接 Q109 → Q46 → Q47 → Q110 → Q111 → Q145。Q110 同時依賴 Q109 及 Q47。Q46、Q47 是原表 type 1 的必要交接。Server 候選以既有城鎮 NPC 互動接取及交付，交接狀態保存至主線紀錄，方便中途下線後續接。一般任務視窗與 type 5 獎勵待接。Q110 的最後一段劇情已包含 10022，沿用主線在最後一段播完時提交的做法。 [QuestInfo](../../kr-temp-roy/T06/evidence/original-QuestInfo.xml)

| 任務 | NPC 流程 | 劇情 |
|---|---|---|
| Q109 | 10022 | Scene 1 |
| Q46 | 10023 → 10056 | 兩次 NPC 互動 |
| Q47 | 10056 → 10025 | 兩次 NPC 互動 |
| Q110 | 從 10025 啟動，末段有 10022 | Scene 1～4 |
| Q111 | 10022 | Scene 1 |
| Q145 | 10022 → 單人編隊 → Case 116 | Scene 1 編隊前，Scene 2 入場，Scene 3 清場 |

Field 39 對應 Case 116，Chart 唯一節點的地圖為 813，模型 icecrystal11C，`icecrystal11.bnd`。選用 Cluster 3，三隻 1020／PRE 1、每隻 126 HP，共 378 HP。數量有來源群組，使用時機與位置採 Server 候選。清場劇情播完後走到出口按 Z，結果頁返回羅特魯亞 199。 [場景與任務配置](rotrua-dragon-secret.append.json)

| 原件與測試工作目錄一致的解碼成員 | SHA-256 |
|---|---|
| Field/MapFlow/CHART_S_Secretdragon_01.xml | `2c15138dbc7046e83babbd396e5631d74ee3828e2b783e33aee5810de206b2d9` |
| Field/Cluster/CLUST_S_Secretdragon_01.xml | `83471bd8622e061b7a1138736786b4a01e7f54087d7e5e9663499a12c37c608e` |
| BoundMap/icecrystal11.bnd | `7f707f572bf6c0bb66fd742d925ecc7a27c4761bb3b760cc7b14eaa00412740d` |
| Event/Sequences/Rotrua_DragonSecret_Stage.seq | `6f2fcb8d40d6f693b22db97ced6dd46fa0e706feb193214a508e9a865bdbdcc6` |
| Event/Sequences/Rotrua_DragonSecret_Clear.seq | `91ba8ec922599d4662f5ed750f79cbe61408a5f5030de9275a310abd5a9ee109` |

Q145 採 QuestInfo type 2 的 51,625 EXP 及 type 4 的 1,809 LeeLoo。type 3 的 180 用途待證。將附表追加至 Q108 版，`version` 設 `rotrua-q145-candidate-v1`，`sourceBaselineSha256` 填附表 SHA，並增加 Q108 舊版任務順序至 `previousVersions`。合併內容 SHA 為 `131139de5e1a341f475bd0fb9f11cc68ce23ec064cbfdc43b84db250eb8a708f`，基線關卡圖 SHA 為 `2e790231f4d60d4a7fb87bf697fcb8d8838cc4b3fdee23882cc87c0e59f83a33`，啟用成長和重綁 Q119 覆寫後為 `0fe3ce4b7795e2c03b4dfd0b7c6eb5fa296bed9aa4563515f3242144c9e0a964`。 [錢包政策](rotrua-q145.story-wallet.json)

從馮德斯正常入口離線走至 Q145，核對交接到指定 NPC 才完成、戰鬥總傷害、劇情次序、獎勵與回城存檔。測試角色結算後達 Lv.21、426,635 EXP、滿血 1,000。指定 v2 的 NPC 標記、對話與實際操作待驗。

交付型任務在第二位 NPC 確認交付時，進度紀錄使用當前選擇的角色。接取所用角色可以和交付角色不同。合成故事流程覆蓋接取後還原已存的交付階段，再由另一角色完成，仍保留第二位 NPC 與下一任務順序。指定 v2 的中途換角、移動與交付畫面待驗。
