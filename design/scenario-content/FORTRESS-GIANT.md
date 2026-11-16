# 失落要塞 Q251／Q252

韓版 QuestInfo 的 Demand 依序為 Q250 → Q251 → Q252 → Q253。Q251、Q252 以 NPC 10057 開始，建議 Lv.23。Field 45 對應 Case 121。Q252 原表列 65,493 EXP、2,844 LeeLoo，另有 type 3 的 200，暫未入帳。

| 節點／地圖 | BND | 已核對演出 | Server 配置候選 |
|---|---|---|---|
| 1／897 | ruins02 | 入圖 Scene 2 | 群組 2，1023 × 2 |
| 2／898 | ruins04 | | 群組 27，1024／PRE 2 × 2 |
| 3／899 | ruins06 | | 群組 8，1091 × 2 |
| 4／900 | ruins11 | | 群組 14，1095 × 2 |
| 5／901 | ruins13 | | 群組 23，1097 × 2 |
| 6／902 | ruins12 | 入圖 Scene 3、清場 Scene 4 | 群組 25、19，各一隻 1103 與 1098 |

Q251 的 Scene 1 在 `town004S` 播放。Q252 在編隊前送空地圖參數的 Scene 1。最後一圖的 Boss 演出直接引用模型 1103，清場演出同時引用 1098；Server 讓兩隻都在入場時出現。普通怪 138 HP、必要頭目 598 HP。清完走出口結算，確認後播放 Scene 5（`town004N`），再返回可移動圖 510。

原件 `Field/MapFlow/CHART_S_Giant_01.XML` 的解碼 SHA-256 為 `d0b0a585b6a929d7593072c820847895bf3cc7fe35a3383d924c64f6e82ca143`，`Field/Cluster/CLUST_S_Giant_01.xml` 為 `32e6e1bee2251ef72e49f8498903845c83ff854d4de2bd449839e0b29f8ecc58`。SceneList 與劇情來源為韓版 Event.stp。群組與地圖的對應、出生點、出口位置屬 Server 候選，均落在 BND 的連通區。 [各圖資源雜湊與候選配置](fortress-giant.append.json)

使用原版 BND 的 Release 離線流程已確認六圖、場景順序、頭目與小怪同場、經驗及錢包入帳。樣本角色回村為 Lv.24、726,998 EXP、最大 HP 1,075。此關卡為 `NOT_NATIVE_MEF`。指定 v2 實際顯示與操控待驗。
