# 失落要塞 Q253／Q254

KR QuestInfo 的 Demand 依序是 Q252 → Q253 → Q254 → Q255。Q253 和 Q254 由 NPC 10044 開始，建議 Lv.24。Field 46 對應 Case 122。Q254 的確認報酬為 70,391 EXP、2,952 LeeLoo。原表獎勵 type 3 的 200 暫未入帳。

| 節點／地圖 | BND | 演出 | Server 怪物配置 |
|---|---|---|---|
| 1／903 | crow02 | | 群組 2，1016 × 2 |
| 2／904 | crow05 | | 群組 5，1017 × 2 |
| 3／905 | crow07 | | 群組 14，1093／PRE 2 × 2 |
| 4／906 | crow10 | | 群組 20，1094／PRE 2 × 2 |
| 5／907 | crow11 | 入圖 Scene 2、清場 Scene 3 | 群組 30、22，1105 與 1108 各一隻 |

Q253 Scene 1 使用 `town004N`。Q254 編隊前送 Scene 1，原始演出呼叫 `LoadMap("")`。末圖兩段演出都使用 `crow11X`，入場演出引用 1105 及 1108，Server 採用 1105 作為必要頭目、1108 作為同場普通怪。普通怪 144 HP、頭目 624 HP。清場後走出口結算，確認後播放 Scene 4，再返回失落要塞的可移動圖 510。

Chart `CHART_S_Osbalt_01.XML` 與 Cluster `CLUST_S_Osbalt_01.xml` 的解碼 SHA-256 分別為 `ea415328f92c0eecabbec6507bb8778aa027d1a6a5a41a69cbbfae6fa18dc029`、`25414a490e7562757d75cbc4f2836c1153d31a237d3e8a1e214c523a9bb360e7`。末圖入場及清場序列為 `Fortress_OsbaltAttack_Boss.seq` 與 `Fortress_OsbaltAttack_Boss_Clear.seq`，解碼 SHA-256 分別為 `10f8ccdaa6798247ee28b2bd368d525b76d9226cc48eee82dab5ce20c6f7f652`、`55eee14aefd23945624c4e3e5eb0508cec0f5667334a5092a0ca92342cd86641`。每圖群組分配、怪物、入口及出口座標為 Server 候選，已核對原件 BND 的連通區。 [配置與 BND SHA-256](fortress-osbalt.append.json)

使用原版 BND 的 Release 離線流程已確認五圖、演出順序、怪物血量、兩項報酬及回村存檔。樣本角色回村時為 Lv.25、797,389 EXP、最大 HP 1,100。關卡定義為 `NOT_NATIVE_MEF`，指定 v2 的畫面與操作待驗。
