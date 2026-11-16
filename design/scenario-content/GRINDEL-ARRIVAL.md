# Q244／Q245 至 Grindel Q362

韓版 QuestInfo 的 Demand 為 Q261 → Q244 → Q245 → Q362。Q244、Q245 使用失落要塞 NPC 10057，建議 Lv.28。Q362 使用城鎮 6 的 NPC 10078，建議 Lv.29。`_MapList` 將 Grindel 可移動城鎮對應為圖 651、`town005D`、`town005.bnd`。城鎮 NPC 名單取自 `_TownList`。

| 時機 | 演出與關卡 |
|---|---|
| Q244 | Scene 1 使用 Manarus，完成後回到失落要塞。 |
| Q245 編隊前 | Scene 1 使用空地圖參數。 |
| Field 58／Case 126 | Chart 依序為 978 → 980 → 977 → 979。Scene 2 使用 fairyforest008C，Chart 頭圖是 fairyforest007C；Server 候選在進 978 時播放 Scene 2，演出後還原戰鬥圖。 |
| 圖 980 | Scene 3、4 使用 fairyforest011C。Server 候選搭配群組 13、12，以 1137 為必要頭目，和四隻 1135／PRE 4 同場。清場演出後仍需通過圖 977、979。 |
| 結算 | Q245 發放 102,318 EXP、1,692 LeeLoo。原始 type 3 的 200 暫未入帳。Scene 5 使用 town005D 並呼叫 DoProlog，之後 Server 進入圖 651 並存城鎮 6。 |
| Q362 | 在圖 651 與 NPC 10078 對話，播放 Scene 1 並存檔。 |

Chart `CHART_S_pathofGrindel_01.xml` 的解碼 SHA-256 為 `8f5e1300079fa981c3e833703646ad4bc8c0ebf66ac28eef5a8d620f5214f1d3`，Cluster `CLUST_S_pathofGrindel_01.xml` 為 `b3b7a7978927b3e20d654d6f34c2375603300afb518ef6b06669bdb74c0dc9a0`。地圖各組怪物、頭目判定、NPC 座標與演出插入點是 Server 重建。原版 BND 確認各候選點可達。 [追加配置與原始 BND 雜湊](grindel-arrival.append.json)

Q245 普通怪 156 HP、必要頭目 676 HP，沿用關卡 Lv.28。角色成長延伸至 Lv.29，試行累計門檻為 1,160,000 EXP。離線樣本完成 Q245 後達 1,168,627 EXP，回村發布 Lv.29、最大 HP 1,200，並成功接取及完成 Q362。指定 v2 仍待驗證演出切換、城鎮互動及戰鬥節奏。關卡配置為 `NOT_NATIVE_MEF`。
