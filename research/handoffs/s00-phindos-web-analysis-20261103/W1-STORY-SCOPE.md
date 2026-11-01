# W1：整村劇情範圍、任務依賴與完整玩家路線（P0）

你負責馮德斯村「所有劇情」範圍與可執行任務流程。先讀COMMON.md、QUEST-SCOPE.json及scenes/INDEX.json。

請完成：
- 對77筆Town1任務加橋接15逐筆分類：第一章必要劇情、支線劇情、一般／重複任務、跨村橋段、非本階段；每筆有依據，不以type2十筆直接宣告完整。
- 列第一章9任務／28場景的必經順序、可選／分支、接受／目標達成／交付／完成／離場條件；檢查125–130與131/132為何未直接列在第一章SCENARIO。
- 核對15→117的進村接續、各NPC、角色需求、跨Town下一章起點；給出「完整馮德斯劇情」明確終點，不把到村當全村劇情完成。
- 每個狀態轉移給Server policy可實作提案與Client必需通知，標出現有證據不足的欄位；不將3F、scenario success與Quest completion混成同一事。

首批優先：15／117接續及28場景路線圖。最終交付scope-ledger.csv（77+橋接逐筆覆蓋）、quest-flow.json、NORMAL-ROUTE.md、GAPS.md。
任何排除項都要理由；若範圍仍不完整，明確列出未閉合集合。

## 可直接貼給Web AI的任務入口

請先閱讀共同規則：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/COMMON.md
然後執行本工作卡：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/W1-STORY-SCOPE.md
依共同交付格式新增results/W1/下的成果，先交P0可開發資料與精確未知。
