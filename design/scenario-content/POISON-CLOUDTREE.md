# 毒霧森林 Q448～Q451

KR QuestInfo 的前置為 Q447 → Q448 → Q449 → Q450 → Q451。村莊 9 的 NPC 10087 處理 Q448～Q450，要求 Lv.34。Q451 改找 NPC 10086，要求 Lv.35。Q448 對應 Field 74／Case 138，Q450 對應 Field 75／Case 139。

| 任務／圖號 | BND | 演出 | Server 候選怪物 |
|---|---|---|---|
| Q448／1115 | cloudtree01 | | 群組 1，兩隻 1109 |
| Q448／1116 | cloudtree02 | | 群組 19，兩隻 1136 |
| Q448／1117 | cloudtree03 | 入圖 Scene 2 | 群組 12，兩隻 1135 |
| Q448／1118 | cloudtree09 | | 群組 31，兩隻 1222 |
| Q448／1119 | cloudtree11 | 清場 Scene 3 | 群組 44、48，頭目 1213 與一隻 1137 同時在場 |
| Q450／1120 | town006 | 清場 Scene 2 | 群組 16、2、13，一隻 1137、兩隻 1135、一隻 1136 |

Q448 與 Q450 的 Scene 1 在編隊前播放。Q449 與 Q451 各有一段 town006D 劇情。戰鬥依序清場並使用出口，結算回村圖 1086。群組選擇和點位屬 Server 候選；Q448 Scene 3 出現的 1213 與群組 44 相符。Q450 暫採普通怪。Lv.34 參考裸裝普攻 60，普通怪 180 HP，必要頭目 780 HP。 [配置與碰撞雜湊](poison-cloudtree.append.json)

| KR 原件成員 | 解碼 SHA-256 |
|---|---|
| Field/MapFlow/CHART_S_cloudtreeSecret_01.XML | `96dc115dcddeea90e8d3a7fe959ec9d06064aaeff3bb75b7b25162e6474dc146` |
| Field/Cluster/CLUST_S_cloudtreeSecret_01.xml | `fb046da6197047910822a73fb29ef6f724cbda962ba241f8845b1dd76a1646de` |
| Field/MapFlow/CHART_S_TagarogReAttack_01.XML | `ea31527ad744dbeafc8e4f06e50b890742ac9e6ced879820064ecaef501ae8aa` |
| Field/Cluster/CLUST_S_TagarogReAttack_01.xml | `442920cd70582764b531dea5c62bca1b13ad41582218953570f978ddc5423e12` |
| Poison_Fifth_Stage03.seq | `e41585b9216b44875e5028012f637de88d2c1797a5f2a968088fe8f59a7b639e` |
| Poison_Fifth_BossClear.seq | `114f18f406d6de3c9f016bd966a466aea6e42c7cd42f70934f5509f4976a8521` |
| Poison_Sixth_Stage.seq | `c868e9f3dfe6112fcd761d66e7aea17c671a1a2dfc08547bc34db140b9b60d3b` |
| Poison_Sixth_StageClear.seq | `9a2af36f0fdffd9c9ad6148c248e6708cdde41640a767e382cd375b87a41e7f7` |
| Poison_Seventh_Talkevent.seq | `55276eeac10661bc9bf67876175ab798922c43c4ad4ed810b218b0ee083fb460` |

兩場各給 163,039 EXP。Q448 給 4,032 LeeLoo，Q450 給 3,024 LeeLoo。兩筆 type 3 的 200 暫未入帳。Lv.35 暫定門檻為 3,000,000 EXP，角色無裝備基礎 HP 1,350、攻擊 304、防禦 270，裝備曲線沿用共用公式。 [成長公式](ROLE-AND-MONSTER-GROWTH.md) · [錢包政策](poison-q450.story-wallet.json)

原版 BND 離線流程已走完兩場，核對相符戰鬥血量、結算、角色面板與回村存檔。樣本在 Q450 結算以 3,015,755 累計 EXP 升至 Lv.35，回圖 1086 完成 Q451。指定 v2 的走格、演出及戰鬥手感待驗收。
