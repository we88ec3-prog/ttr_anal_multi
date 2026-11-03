# W5：全村劇情角色／技能／裝備／獎勵與保存資料（P1）

你負責支持劇情流程的靜態資料、ownership及Client發布介面，不調整S00的連擊／硬直演算法。
先讀COMMON.md、QUEST-SCOPE及S00-20261102-QUEST-REWARD-CHANNELS.md。

請完成：
- 每段劇情／任務需要或授予的隊員、等級、技能、裝備、道具、章節開放；分清演出模型1478等與玩家role ID。
- Reward type2已連Client PartyExp顯示、type4已連Leeloo，這不自動證Server縮放／實發／等級換算。追餘額及升級／技能獲取的實際更新consumer與欄位。
- 任務完成／獎勵權利／實際入帳／Client發布分開；設計正常原子保存、來源key與提交版本，參考原始資源而非猜幣種。
- 檢查6F完整snapshot／74 delta／40/45/46等更新對NPC候選列表、接取／交付UI的影響；未知路由保留。

首批優先：Quest16→15→117的前置發布及PartyExp／Leeloo正常結算資料；不得把PENDING entitlement說成PAID。
最終交付requirements-and-grants.csv、reward-definitions.json、STATE-PUBLICATION.md、GAPS.md。
Server內部規則可提出可編碼政策；沒有原版後端不阻止設計，但不能據此宣稱官方算法。

## 可直接貼給Web AI的任務入口

請先閱讀共同規則：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/COMMON.md
然後執行本工作卡：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/W5-ROLES-REWARDS.md
依共同交付格式新增results/W5/下的成果，先交P0可開發資料與精確未知。
