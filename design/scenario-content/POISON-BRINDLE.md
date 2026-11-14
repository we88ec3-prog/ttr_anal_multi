# 毒霧森林 Q442／Q443

韓版 QuestInfo 的前置順序為 Q441 → Q442 → Q443 → Q444。Q442 由 NPC 10085 開始，要求 Lv.32。Q443 改找 NPC 10086，要求 Lv.33。Q442 對應 Field 71／Case 135。

| 圖號 | BND | Server 怪物配置 |
|---|---|---|
| 1104 | erode01 | 群組 2，1009／PRE 4 × 2 |
| 1105 | erode03 | 群組 5，1090 × 2 |
| 1106 | erode05 | 群組 8，1211 × 2 |
| 1107 | erode10 | 群組 17，1210 × 2 |
| 1108 | erode13 | 群組 22、19，候選頭目 1207 與普通怪 1208 |

Q442 的 Scene 1 在編隊前播放。Scene 2、3 都載入 erode13C，分別安排在末圖進場及清場後。Scene 4 在結算確認後播放，載入 town006D，再回可移動的圖 1086。Q443 在圖 1086 接續單段對話。頭目演出的 NPC 模型為 10086，戰鬥頭目 1207 為取自 Cluster 的 Server 候選。普通怪 171 HP、頭目 741 HP。地圖分組和出生點採重建配置。

Chart `CHART_S_Brindle_01.XML` 與 Cluster `CLUST_S_Brindle_01.xml` 的解碼 SHA-256 分別為 `692227dbe1710e1f12f3d8992a181e0de306b9d2eb51e2b72e4c5be051fdfaab`、`47b24dc104857bcc162e268d9ff29e60d2e62f60cf9a46291391e59f27913d9c`。erode05、erode10、erode13 的原版 BND 有三層。三層的展開長度與格數一致，內容均為 0／1。Server 對這三個已核對的雜湊沿用「任一層非零即阻擋」規則，原版第三層用途仍待驗證。 [配置及 BND 雜湊](poison-brindle.append.json)

Q442 發放 146,489 EXP、3,816 LeeLoo。原表 type 3 的 200 暫未入帳。Lv.33 試行門檻為累計 2,340,000 EXP。原版 BND 離線驗證已走完五圖及 Q443，樣本角色以 2,371,401 EXP 升至 Lv.33、最大 HP 1,300，留在圖 1086 並保存進度。指定 v2 的碰撞、演出與操作待實機驗收。
