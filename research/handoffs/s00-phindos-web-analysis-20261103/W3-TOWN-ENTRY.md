# W3：正常村落scene／controller／出生點／NPC初始化（P0）

你負責普通馮德斯村，尤其劇情結束後可操作的狀態。先讀COMMON.md、舊RESOURCE-BASELINE、
S00-20261102-PHINDOS-SEQUENCES-AND-BOUNDS.md及extra/roy3已交的精確版本報告（未經T01接受不可當FULL-PASS）。

請完成：
- Town1/type1、map182、town001D、BND world1536各domain與用途；從收到的scene/type分支追普通controller／world建立，不靠缺少CTown RTTI猜場景。
- 找進村玩家與NPC的合法正常位置／方向／高度／比例來源；演出CreateObject不是一般spawn，圖表node座標也不是spawn。四個演出玩家座標目前靜態blocked。
- 列完整正常換場時序：context、map、loading、reset、player metadata/actor/bind、NPC、skills/stats、控制恢復與ready證據；哪些可Server選擇要明示。
- Town1九個NPC的model／identity／互動類型、可見與可互動差異；對村落後續劇情返回時的控制／NPC保留要求給可實作資料。

首批優先：15/3演出RestoreMap之後的普通Town1場景與玩家spawn來源。這是目前直接進村的主要未知。
最終交付town-entry.json、NPC-MATRIX.csv、SPAWN-EVIDENCE.md、NORMAL-ENTRY-SEQUENCE.md、GAPS.md。
找不到合法spawn就交精確消費端／資料來源缺口，不推薦任意可走點頂替。

## 可直接貼給Web AI的任務入口

請先閱讀共同規則：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/COMMON.md
然後執行本工作卡：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/W3-TOWN-ENTRY.md
依共同交付格式新增results/W3/下的成果，先交P0可開發資料與精確未知。
