# 毒霧森林 Q444／Q445

韓版 QuestInfo 的前置順序為 Q443 → Q444 → Q445 → Q446。Q444 由 NPC 10086 開始，要求 Lv.33。Q445 改找 NPC 10085，要求 Lv.34。Q444 對應 Field 72／Case 136。

| 圖號 | BND | 演出 | Server 候選怪物 |
|---|---|---|---|
| 1109 | erode02 | 入圖 Scene 2 | 群組 2，兩隻 1009／PRE 4 |
| 1110 | erode06 | | 群組 8，兩隻 1211 |
| 1111 | erode09 | | 群組 14，兩隻 1209 |
| 1112 | erode11 | | 群組 26，兩隻 1222 |
| 1113 | erode13 | 入圖 Scene 3、清場 Scene 4 | 群組 22、28，必要頭目 1207 與普通怪 1212 |

Scene 1 在編隊前播放。原版的末圖演出使用 erode13C 並引用 1207，Server 以群組 22 的 1207 為頭目。Lv.33 戰鬥採普通怪 174 HP、頭目 754 HP。清場後走出口，結算確認時播放使用 town006D 的 Scene 5，隨後回圖 1086。Q445 三段劇情依序使用 erode08C、town006D、Cloudtree03N，結束後仍回圖 1086。

`CHART_S_Feeler_01.XML` 的解碼 SHA-256 為 `c912dbcd237fea525a1d54db96b3837ada5255b226910e32f3f1c4a31cae7de3`，`CLUST_S_Feeler_01.xml` 為 `a2a7de19e73b3d32f7ad7e2a823c4f199f9b1d6fda7a30f52bf9605d6bb21af9`。erode06 和 erode09 各有三層等尺寸的 0／1 位圖。Server 以兩份原檔的精確雜湊納入第三層保守阻擋規則。群組分配、點位和觸發時機採 Server 候選配置。 [配置與 BND 雜湊](poison-feeler.append.json)

Q444 發放 155,237 EXP、3,924 LeeLoo；原表 type 3 的 200 暫未入帳。Lv.34 試行門檻為累計 2,500,000 EXP。原版 BND 離線流程已確認五圖、演出命令、報酬與回村存檔。樣本以 2,526,638 EXP 升到 Lv.34、最大 HP 1,325，接續完成 Q445。指定 v2 的演出、走格與戰鬥節奏仍待驗收。
