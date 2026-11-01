# S00：戰鬥模擬數值與能力頁欄位落差

接續 REQ-0016 戰鬥優先；REQ-0017 兩段劇情後留原地仍保留，沒有宣稱出口修復。
這次是 Server 實作落差與舊證據重核，不是新的人測結果，也不新增重複需求。

## 舊資料實際留下了什麼

唯讀 `workspace/anal/34-combined-initialization-experiment.md` 保存 5C fixture，
`35-combined-ui-results.md` 已明確區分：DWORD +4/+8/+12 的 500/100/100
沒有成為當時能力頁的 HP/SP/MP；WORD +16/+18/+20 的 20/20/20 與頁面顯示對應。
這是歷史修改副本的 UI 相關性，不能升級為官方目前值／最大值／HUD完整語意。
因此本例不是沒有留下分析，而是新實作沿用 fixture 時沒有完整帶入其反證與限制。

原始 KR SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，
既存 Ghidra `4D41A0` pseudocode SHA
`4a4e1c2225c01bbd414b80a07f518b5feb733ead9c46d5c955ca9e58a8e5d126`；
`4B3DA0` SHA `e5eed0809fce8ced190f0ba982547681ee9a801712761c3421447a5764d75eaf`。
後者按角色索引已存在資料後呼叫前者，非新建角色／生怪功能。

| 5C payload offset | 4D41A0 寫入角色記錄 | 可支持的結論 |
| --- | --- | --- |
| +4/+8/+12 DWORD | +50/+58/+54 DWORD | 有搬移；用途 UNKNOWN，不能標為 HP/SP/MP |
| +16/+18/+20 WORD | +40/+48/+44 DWORD | 有零擴展搬移；舊能力頁 HP/SP/MP 相關性 |
| +22/+24/+26 WORD | +60/+64/+68 DWORD | 舊能力頁物攻／魔攻／精神攻擊相關性 |

新增 `inspect_tutorial_combat_sources.py --stats-mapping` 核對原檔完整
`4D41A0..4D4208`（104 bytes，至第一個 ret，沒有把後續 padding 算入），
固定檢查上述 DWORD 與 WORD 的來源／目的指令。輸出
[有限證據](evidence/S00-20261101-COMBAT-STAT-MAPPING.json) 包含工具版本、原檔 SHA、
指令與既有資源 metadata；不是整份函式語意 FULL-PASS 或官方 Server 封包觀察。

## Server 修正與驗收界線

目前 Server 模擬玩家 HP500、SP100、MP100，但 5C 能力頁欄位仍是20/20/20。
候選改為共享 Server 政策常數，將 WORD +16/+18/+20 填500/100/100；
保留未知 DWORD 的既有 fixture，不冒然改其語意。這些數值不是官方角色平衡。
normalized HP parameter1 仍獨立使用萬分比，不拿能力頁值代替血條比例。

既有正常 TCP／SQLite 旅程增加接收端能力資料檢查，沒有增加鏡像 builder 單測。
15 個 HappyPath cases 通過；其餘198方法維持待測。舊 v6 人測結果尚待回，
本次修正只在源碼準備，沒有中斷 v6、沒有更新 Client 或資料庫 schema。
能力頁實際顯示、HUD current/max、SP/MP 顯示及技能可用條件仍需後續連測／補證。

T10/T11 接續優先核對：能力記錄 +40/+48/+44 的 HUD／技能消費者，
與 actor normalized parameter1/2/3 的關係；不能把兩組欄位或未知 DWORD 合併命名。
冷卻012A時基、正式取消／命中窗口仍 UNKNOWN，未因本次更正而完成。
normative pin、formal admission 與 APPROVED 狀態不變。
