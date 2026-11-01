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

## 後續：獨立初始化 actor 的三個比例槽

能力頁修正後再查 `4CE7F0`（pseudocode SHA
`e561c8bdfbbe38199284f734e075c6108e0cc79d86bc251d750e131cc684f0b0`），
其 parameter setter 的 switch table 與兩段指令可確認：

| parameter | actor 欄位 | 視覺槽索引 | 寫入視覺值 |
| --- | --- | --- | --- |
| 1 | +3B0 | 0 | signed WORD × 約0.0001 |
| 2 | +3B4 | 1 | signed WORD ÷ 100.0 |
| 3 | +3B8 | 2 | signed WORD ÷ 100.0 |

視覺物件存在才走浮點寫入；此處不是完整 HUD／技能 gate 追蹤，也沒有證明
能力頁記錄會自動更新這三槽。槽2/3作為 SP/MP 的命名沿用目前候選，不能只靠
除數就當成原生顯示文字或絕對當前值已全文確認。

原始 table `4CEB5C`＋key table `4CEB88` 的前3鍵分別落到
`4CE83B/4CE880/4CE8C5`。`C557E8` double=100.0；第二／三段各69 bytes
至共同尾部跳躍，不混入下個 case。新增 `--resource-ratios` 核對表項、目的欄位、
除數與指令邊界，保存 [比例槽有限證據](evidence/S00-20261101-COMBAT-RESOURCE-RATIOS.json)。
這是有限反組譯＋既存 Ghidra來源核對，不是整體 FULL-PASS。

Server 原先 rebuild 只送 parameter1/5/6，沒有明確送滿的候選 SP/MP 槽；
現在一次初始化1/2/3/5/6，值10000/100/100/100/30。
不是把2/3誤送10000，也不假定能力頁的5C可以代替actor參數。
每次既有actor rebuild均使用這個初始候選狀態，與既有Server的滿資源重建政策一致；
沒有增加戰中自然回復、重連恢復或官方持久化假設。

正常 TCP 三怪列進一步覆蓋：持續一般輸入→收到敵人對玩家0E→X動作108→
候選SP65/MP70通知→35傷害→以Z收尾→三個entity各自移除→返回／重建滿比例→
既有勝利持久化與蘋果取得。既有單怪列與其他正常列仍保留，15 cases通過。
此處時間由測試clock控制，傷害與成本仍Server政策，非官方數值或Client畫面驗收。
其餘198方法不執行；未換版中斷目前v6測試。
