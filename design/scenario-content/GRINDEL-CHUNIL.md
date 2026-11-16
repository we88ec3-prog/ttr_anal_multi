# Grindel Q369／Q370

韓版 QuestInfo 的 Demand 依序為 Q368 → Q369 → Q370 → Q371。Q369、Q370 都在 Grindel 由 NPC 10074 開始，需求 Lv.31。Q369 為 Field 62／Case 129，結算發放 136,895 EXP 與 3,708 LeeLoo。原表 type 3 的 200 暫未入帳。

| 節點／圖號 | BND | Server 怪物配置 |
|---|---|---|
| 1／990 | twinrock01 | 群組 2，1095 × 2 |
| 2／991 | twinrock03 | 群組 5，1039 × 2 |
| 3／992 | twinrock05 | 群組 8，1046 × 2 |
| 4／993 | twinrock08 | 群組 26，1134／PRE 2 × 2 |
| 5／994 | twinrock11 | 群組 29、19，1140 頭目與 1139／PRE 3 同場 |

Q369 編隊前使用 Scene 1，末圖使用 Scene 2。原版末圖序列載入 twinrock11X，並使用 1140、1139，與 Cluster 群組記錄相符。普通怪 168 HP、頭目 728 HP。每圖群組配置、點位及頭目判定是 Server 候選。末圖清場開出口，結算後返回圖 651。Q370 播放使用 town005D 的 Scene 1 並存檔。

`CHART_S_Chunil_01.xml` 與 `CLUST_S_Chunil_01.xml` 解碼 SHA-256 分別為 `b18bcd376de44eb3c141dc84ce7f1e5046f7aa34772c5a6d9bd72e996ba3efed`、`570dfbf25f35d24ea4667b26845ad00d3a2ab3ef676ec6dfbb3bf0583a720033`。各圖原版 BND 的雜湊與點位列於配置，採 `NOT_NATIVE_MEF`。 [候選配置](grindel-chunil.append.json)

使用原版 BND 的離線流程已驗五圖、場景命令、戰鬥血量、報酬、回村與 Q370 存檔。樣本角色維持 Lv.31、最大 HP 1,250，累計 1,658,144 EXP。指定 v2 的畫面與操作待實機確認。
