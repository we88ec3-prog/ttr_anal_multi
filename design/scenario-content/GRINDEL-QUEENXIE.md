# Grindel Q23、Q363～Q365

原版 QuestInfo 的 Demand 為 Q362 → Q23 → Q363 → Q364 → Q365。前三個任務為 Lv.29，Q365 要求 Lv.30。Q23 由 NPC 10078 開始，Q363 和 Q364 改由 NPC 10079，Q365 回到 NPC 10078。

| 任務 | 原始地圖與演出 | Server 候選配置 |
|---|---|---|
| Q23 | Field 68／Case 133，圖 1087、town005D。編隊前 Scene 1，清場 Scene 2。 | Cluster 1 的 1201／PRE 1 單獨登場，頭目 702 HP。 |
| Q363 | Scene 1 使用 fairyforest001C。 | 演出結束後恢復可移動的 Grindel 圖 651。 |
| Q364 | Field 60／Case 127，圖 984、fairyforest001C。編隊前 Scene 1，清場 Scene 2。 | 1137／PRE 1 作為頭目（702 HP），與三隻 1135／PRE 1（各 162 HP）同場。Cluster 5 有兩隻 1137，這版取一隻作為必要頭目；三隻普通怪取自 Cluster 4。 |
| Q365 | Scene 1 載入 Moonspring05N。 | 完成演出後返回圖 651，儲存 Q365 完成。 |

`CHART_S_Alphonce_01.xml` 與 `CLUST_S_Alphonce_01.xml` 的解碼 SHA-256 分別為 `7d90589e351a0c83e3b3265be78f77ac01e6e79064c9d364eeaf3560521d0d0c`、`b0666b60e1615e75eeac33f3557ce28f115ebdc2ee7b48adf3c7c374b89812bf`。`CHART_S_Queenxie_01.xml` 與 `CLUST_S_Queenxie_01.xml` 分別為 `67f91b49e4e28bffea4389cc01bef833ae12a991c266162f926bdc98ce22d377`、`aa04fdd6255372466990d626162a21f65c6467eceb8db5ca2875ba5262fd8705`。怪物配置、首領判定及點位屬 Server 重建，已用原版 BND 核對可走範圍。 [追加配置與 BND 雜湊](grindel-queenxie.append.json)

Q23 與 Q364 各發放 113,871 EXP，另分別發放 3,492 與 1,746 LeeLoo。原表 type 3 的 200 暫未入帳。Server 採 1,360,000 累計 EXP 作為 Lv.30 試行門檻。離線樣本完成 Q23 後維持 Lv.29，完成 Q364 後以 1,396,369 EXP 升至 Lv.30（最大 HP 1,225），並接續完成 Q365。指定 v2 的演出、互動與戰鬥仍待驗收。
