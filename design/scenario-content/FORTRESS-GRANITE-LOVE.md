# 失落要塞 Q249／Q250

Q248 → Q249 → Q250 的前置順序來自 KR QuestInfo 的 Demand。Q249 與 Q250 的 NPC 均為 10057，建議等級 22，Field 44 對應 Case 120。Q250 原表列 61,610 EXP、2,052 LeeLoo，type 3 的 200 用途待核對。

| Chart 節點／地圖 | BND | 劇情 | Server 候選配置 |
|---|---|---|---|
| 1／892 | crow01 | 入圖 Scene 2 | 群組 2，1016 × 2 |
| 2／893 | crow02 | — | 群組 11，1089 × 2 |
| 3／894 | crow10 | 入圖 Scene 3 | 群組 16，1101 × 2 |
| 4／895 | crow09 | 入圖 Scene 4、清場 Scene 5 | 群組 1、4，各 1016、1017 一隻 |
| 5／896 | crow14 | 清場後按出口進結算 | 群組 18、15，菁英 1119 與普通 1101 同場 |

編隊前送 Scene 1。確認結算後送 Scene 6，演出載入 `town004N`，隨後 Server 回到可移動的失落要塞圖 510。Scene 4 與 5 的 `.seq` 都載入 crow09N，Case 120 仍有第五圖 896。各圖群組對應、首領身分與點位屬 Server 重建配置；原始 Cluster 提供可用組成，其每圖綁定仍待原始事件來源。普通怪 135 HP、必要首領 585 HP，兩者都以固定關卡 Lv.22 計算。參戰角色使用實際等級與裝備。

Chart、Cluster 來源雜湊見成長規格。六段 `.seq` 來自 SHA-256 為 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` 的 KR Event.stp。每個 BND 的解碼 SHA-256 固定在追加配置，兩份本機 BoundMap.stp 相同。關卡定義為 `NOT_NATIVE_MEF`。 [成長規格](ROLE-AND-MONSTER-GROWTH.md#失落要塞成長與主線門檻) · [追加配置](fortress-granite-love.append.json)

Release 離線流程使用原版 BND 走完五圖，核對清場、場景順序、報酬與存檔。樣本角色由 599,895 EXP 增至 661,505 EXP，在回村時發布 Lv.23 及 1,050 最大 HP。指定 v2 的實際演出、裝備手感，以及 Q251 起的主線仍待驗證。
