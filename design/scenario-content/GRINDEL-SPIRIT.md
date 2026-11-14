# Grindel Q375／Q376

韓版 QuestInfo 的 Demand 為 Q374 → Q375 → Q376 → Q439。Q375 由 NPC 10077 開始，Q376 回村後找 NPC 10079，兩者均要求 Lv.32。Q375 對應 Field 65／Case 132，結算發放 146,489 EXP 與 3,816 LeeLoo。原表 type 3 的 200 暫未入帳。

| 節點／地圖 | 碰撞 | Server 配置 |
|---|---|---|
| 1／1001 | fairyforest003 | 群組 5，1009／PRE 3 × 2 |
| 2／1002 | fairyforest005 | 群組 8，1010 × 2 |
| 3／1003 | fairyforest009 | 群組 22，1008／PRE 3 × 2 |
| 4／1004 | fairyforest008 | 群組 27，1131 × 2 |
| 5／1005 | fairyforest012 | 群組 33，必要頭目 1138／PRE 1 與五隻 1137／PRE 3 |

Scene 1 在編隊前播放。Scene 2 使用 fairyforest001C，Server 安排於圖 1001 開場並在演出後還原戰鬥圖。Scene 3 在末圖播放，其序列使用 fairyforest012C，引用 1138 與 1137。Scene 4 在末圖清場後播放，序列使用 fairyforest011C，結束後還原戰鬥圖與出口。普通怪 171 HP、頭目 741 HP。各地圖分組、出生點與演出插入時機採 Server 候選。末圖保留原群組 33 的全部六隻怪。

`CHART_S_Spirit_01.xml` 解碼 SHA-256 為 `a4cafe1ccf25ff46762b43d3e09e11c30b2a1dfd2bf60979612bb7fe5a4db604`，`CLUST_S_Spirit_01.xml` 為 `50cf51426dbeb478c3a8225bc75bcf6e01b5e8661b1389e2c0a16400872df30b`。 [配置與 BND 雜湊](grindel-spirit.append.json)

原版碰撞離線流程已核對五圖、末圖總血量、場景命令、報酬、回圖 651，以及 Q376 播放與存檔。角色維持 Lv.32、最大 HP 1,275，累計 2,078,423 EXP。指定 v2 的場景切換及面對六隻怪時的操控與節奏待實機驗收。
