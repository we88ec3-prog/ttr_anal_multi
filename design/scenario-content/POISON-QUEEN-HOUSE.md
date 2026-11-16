# 毒霧森林 Q452 與 Q628

KR QuestInfo 指定 Q451 → Q452 → Q628 → Q629。Q452 由村莊 9 的 NPC 10086 受理，完成後改找 NPC 10085 開始 Q628。兩者皆要求 Lv.35。Q452 對應 Field 76／Case 140。

| 圖號 | BND | Server 候選怪物 |
|---|---|---|
| 1121 | Queen01 | 群組 2，兩隻 1136 |
| 1122 | Queen02 | 群組 5，兩隻 1109／PRE 5 |
| 1123 | Queen03 | 群組 26，兩隻 1128／PRE 5 |
| 1124 | cloudtree10 | 群組 14，兩隻 1135／PRE 4 |
| 1125 | cloudtree14 | 群組 31、32、33，頭目 1214 與小怪 1148、1149 同時在場 |

Scene 1 在編隊前播放，Scene 2 在末圖入場時播放，Scene 3 清場時使用 Cloudtree13X 演出。結算後播放使用 fairyforest013C 的 Scene 4，再回村莊 9 的圖 1086。Q628 在圖 1086 接續單段 town006D 劇情。群組分配與座標採 Server 候選，場景腳本出現的角色只用於對照。Lv.35 參考裸裝普攻 61，普通怪 183 HP、頭目 793 HP，末圖合計 1,159 HP。 [各圖座標與 BND 雜湊](poison-queen-house.append.json)

| KR 原件成員 | 解碼 SHA-256 |
|---|---|
| Field/MapFlow/CHART_S_QueenHouse_01.XML | `c8bf0374e8218003986bc013b2c9ab51b5bb5a7f2206c714d69aa5b6d7f4efc4` |
| Field/Cluster/CLUST_S_QueenHouse_01.xml | `2dbfa70f272ad04a5393ff9312d57577a694a5c6ca7a743d6cee1fef0fc10fab` |
| Poison_Seventh_Boss.seq | `80ba25dfe1e74205de9ecadde979cbc876241d78912dd14dd21c2a4028552a8d` |
| Poison_Seventh_BossClear.seq | `430a10e57bd4fc090f1c4de9114d0a64c48ed22d0137c4e3c29d13926c32d5ba` |
| Poison_Seventh_Ending.seq | `a1719efb6aa15e99a1c0347a798d9471b8aeca4a93bdb0fe5e28db30ba0d32c4` |
| Kavershard_First_Talkevent.seq | `51990e0899a559bb6363f02b1611ac97a634dafac5336a7573d86feb657c8a2f` |

Q452 發放 169,797 EXP 與 4,140 LeeLoo，原表 type 3 的 200 暫未入帳。原版 BND 離線流程已核對五圖、戰鬥血量、場景順序、結算與 Q628 存檔。樣本維持 Lv.35，累計 3,185,552 EXP。指定 v2 的走格、頭目及演出仍待實機驗收。 [錢包政策](poison-q452.story-wallet.json)
