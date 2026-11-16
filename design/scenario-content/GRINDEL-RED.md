# Grindel Q366～Q368

韓版 QuestInfo 的 Demand 為 Q365 → Q366 → Q367 → Q368。Q366 和 Q367 由 NPC 10012 開始，要求 Lv.30。Field 61 對應 Case 128。Q368 在回村後交給 NPC 10074，要求 Lv.31。

| 節點／圖號 | 碰撞資料 | Server 怪物配置 |
|---|---|---|
| 1／985 | Moonspring01 | 群組 2，1090 × 2 |
| 2／986 | Moonspring05 | 群組 5，1003 × 2 |
| 3／987 | Moonspring07 | 群組 19，1129／PRE 2 × 2 |
| 4／988 | Moonspring10 | 群組 31，1133／PRE 3 × 2 |
| 5／989 | Moonspring11 | 頭目 1387 與 1130／PRE 3，各取自群組 45、39 |

Q366 與 Q368 的對話都使用 town005D。Q367 在編隊前播放 Scene 1，末圖播放入場 Scene 2、清場 Scene 3。兩段末圖演出都使用 Moonspring11N，並引用 1041。原始 ActorList 顯示 1041 與 Cluster 45 的 1387／PRE 1 共用 `02_Keraking` 及同一名稱、顯示比例。Server 採 1387 作必要頭目，原版戰鬥的實際觸發與怪物配置仍待確認。普通怪 165 HP、頭目 715 HP，採 Lv.30 的關卡基準。

`CHART_S_Red_01.xml` 解碼 SHA-256 為 `45cdd9cfb3ac5c87542e259fb71b5b379d034f51727f8680086e6d31986a01c8`，`CLUST_S_Red_01.xml` 為 `c1d837bf3ce762e70ab8475cd6b165a0bb42e3520233929c8b13074db5c9e1d4`。各 BND 雜湊及採用的群組與位置保存在追加配置，格式為 `NOT_NATIVE_MEF`。 [追加配置](grindel-red.append.json)

Q367 結算發放 124,880 EXP、3,600 LeeLoo。原表 type 3 的 200 暫未入帳。Lv.31 試行門檻為 1,500,000 累計 EXP，先前門檻照舊。原版碰撞離線流程已核對五圖、報酬及演出命令，樣本以 1,521,249 EXP 升至 Lv.31、最大 HP 1,250，回圖 651 後完成 Q368 存檔。指定 v2 的場景恢復、操控與戰鬥節奏待實機驗收。
