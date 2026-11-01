# 明日Web AI分析工作包：馮德斯村完整劇情

使用者本次稱「蒙德斯村」，本包沿目前同一個Town1／map182「馮德斯村」處理。
這是整村劇情的分析準備；active Server近期里程碑仍先達成正常進村，不混成已完成全村。

原始Table實查：Town1任務77筆；第一章9個劇情任務、28段scene。
本包另提供28段本地Event腳本的1173個literal calls／member SHA／分檔索引，Web可直接研究，
不必假裝能存取使用者E槽。這些metadata不是完整helper執行或原生成功證據。

| 工作卡 | 優先 | 交付目的 |
| --- | --- | --- |
| [W1 範圍與任務路線](W1-STORY-SCOPE.md) | P0 | 完整劇情邊界、77筆處置、28場景玩家路線與合法任務轉移 |
| [W2 NPC與劇情事件](W2-NPC-SCENES.md) | P0 | NPC／對話／本地scene／封包／控制接續 |
| [W3 普通村落初始化](W3-TOWN-ENTRY.md) | P0 | scene/controller、合法spawn、玩家／NPC／可操作入場 |
| [W4 劇情副本](W4-SCENARIO-FLOW.md) | P1 | 必經戰鬥、編隊／目標／結果／返回與BNDv2缺口 |
| [W5 角色與獎勵](W5-ROLES-REWARDS.md) | P1 | 隊員／技能／裝備／任務前置及實際獎勵保存與發布 |

## 明天怎麼使用

有五個可用對話就一個對話一張卡，避免多人改同一成果檔。
只有三個時先W1／W2／W3平行，首批交付後把W4／W5補上。
每張卡末尾有可直接貼給Web AI的入口，先讀[COMMON](COMMON.md)。
先交能解除目前進村卡點的P0資料，再補整村；不必等全份寫完才交首批。
成果放results/W1..W5，各自精確commit/blob回報，由T01核對，再交S00整合。
這次只整理供使用者明天派工，**尚未替使用者建立新對話或發送這五張新卡**。

## 現成來源

- [精簡任務／章節scope](QUEST-SCOPE.json)、[28段逐檔索引](scenes/INDEX.json)、[完整metadata](RESOURCE-SCOPE.json)。
- [既有開發分析入口](../../../governance/s00-iterations/S00-CURRENT-DEVELOPMENT-INDEX.md)。
- [整合驗收清單](REVIEW-CHECKLIST.md)。原始Table與本地Event的來源SHA及未知均在metadata／COMMON。
- 生成器：governance/inspect_phindos_story_scope.py；只讀原件，無Client執行或資源修改。

這份包用來讓S00直接接手可實作資料；關鍵未知沒有閉合時須交精確缺口，
不能用假座標、假MEF、假完成狀態換取「明天一定全部完成」的結論。
