# Grindel Q371～Q374

韓版 QuestInfo 的 Demand 依序為 Q370 → Q371 → Q372 → Q373 → Q374。Q371 由 NPC 10074 開始，Q372～Q374 由 NPC 10077 開始。前兩場戰鬥要求 Lv.31，Q374 要求 Lv.32。

| 任務與地圖 | 碰撞 | 演出 | Server 候選怪物 |
|---|---|---|---|
| Q371／995 | fairyforest011 | 入場 Scene 2、清場 Scene 3 | 群組 18、6，1137 與 1135 同場 |
| Q373／996 | bugnest007 | 入場 Scene 2 | 群組 4，1136 × 2 |
| Q373／997 | bugnest008 | | 群組 10，1091 × 2 |
| Q373／998 | bugnest010 | | 群組 13，1109 × 2 |
| Q373／999 | bugnest012 | | 群組 16，1128 × 2 |
| Q373／1000 | bugnest014 | 入場 Scene 3、清場 Scene 4 | 群組 18、6，1137 與 1135 同場 |

Q371 為 Field 63／Case 130，Q373 為 Field 64／Case 131。兩場都在編隊前播放 Scene 1。末圖演出引用 1137，Server 採其為必要頭目，血量 728 HP；普通怪 168 HP。各圖組合、頭目判定及點位為 Server 候選，在原版 BND 的連通區驗證。Q372 播放一段對話，Q374 依序播放三段並存檔。

| 原始資源 | 解碼 SHA-256 |
|---|---|
| CHART_S_Bbormodo_01.xml | `19373db82003a5b80e46a6832811a62d80b84f20970e67bb8b83b94c95fb1f10` |
| CLUST_S_Bbormodo_01.xml | `1a03a8414b77b3cd501351acb0d245c495be0bfdd2d3523d673d5e9d6e36b511` |
| CHART_S_Bugnest_01.xml | `172a50ae96fe9afcda1b90b524f4eb26afa49ab6163632c612b2e1253273fe8c` |
| CLUST_S_Bugnest_01.xml | `f29b6f5401603546c3612698be5926cc2f9a1713c3be902f8d7c388789c59857` |

Q371、Q373 各發放 136,895 EXP，LeeLoo 分別為 2,781、3,708。原表 type 3 的 200 暫未入帳。Lv.32 試行門檻為累計 1,900,000 EXP。離線樣本完成 Q371 後維持 Lv.31，Q373 結算後以 1,931,934 EXP 升至 Lv.32，最大 HP 1,275，回 Grindel 圖 651 完成 Q374 存檔。指定 v2 的演出、操控及戰鬥節奏待實機驗收。 [配置與 BND 雜湊](grindel-bugnest.append.json)
