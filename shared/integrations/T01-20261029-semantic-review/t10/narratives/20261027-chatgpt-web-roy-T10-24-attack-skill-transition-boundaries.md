# KR T10/T11 交界研究 — T10-24 普攻→技能／技能→普攻交界：已證實資料流與缺口

- 日期：2026-10-27 Asia/Taipei
- 證據：原始 Tartaros.bin，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 方式：BIN 唯讀 objdump i386，.text VA 0x401000／raw 0x400，位址均為 VA
- 任務隔離：T10 主導攻擊輸入與連接；技能計時、消耗、施放裁決的 T11 邊界以引用／候選標記，不擅改 T11 task.json 或別人的分析
- 不執行目標、不修改遊戲檔案、不將本地替代連段窗口視為原版值

## 研究命題
使用者明確補充「普攻可視為技能系統的一部分」，並要求比較 Z 普攻接技能及技能結束接普攻。本文件把這當作**研究假說／觀察**而不是 BIN 已驗證的實作結構。

## 已由第一手機器碼支持的關係
1. `0x546780` 的輸入聚合與 `0x54F270` availability 在同一條 `0x546100` 控制器路徑相接（`0x546263` -> `0x5462DD`）。可證明 **控制器依技能 availability 篩選輸入**。
2. `0x54F270` 讀取 matrix model/tier/key，並經 tree lookup 查 remaining DWORD 為零，為真正 T11 相關的技能 gate，但不代表發出施放事件。
3. 另外三個 `0x54F270` 呼叫者分別來自不同 controller / SubAI 條件，並不能直接合成一個全域 combo graph。
4. `0x549D7D` 寫入 `object + (object+0x108)*16 + 0xAC` 一個 DWORD 值 4，構成可繼續追查的**條件成立後狀態寫入者**，但暫不能命名為 normal attack index。

## 尚未證實的四種 transition
| 問題 | 現況 | 應採集的證據 |
|---|---|---|
| Z 重複按下，普攻續段 | 未證實 | action key + actor motion completion + state writer |
| Z 按住，普攻自動續段 | 未證實 | held poll / animation end / next action |
| 普攻中按技能，切到技能 | 未證實 | 同一 actor current motion 與 skill input 接受／拒絕條件，是否緩存 |
| 技能結束接普攻 | 未證實 | 技能完成 callback、狀態清除／queue flush、Z pressed/held 被消費的時間 |

## T11 標記表
- **T11-相關已確認**：`0x54F270` 可用性 check；`0x819220`/`0x81A8E0` 矩陣 key；`0x54F4E0` 樹查找含可能插入；`0x549980` SubAI 技能條件，僅既有 audited 范圍。
- **T10 主責、引用 T11**：`0x546100`、`0x546780`、`0x54827F` controller 輸入 gate。
- **可能交叉但暫不可命名**：`0x549D54` 返回後狀態寫入；`0x5961C0` 事件 phase 1/3 分流；`0x547240` 500ms gate。
- **不可直接當技能判定**：`0x50C640` cmd 0x22、`0x548918` cmd 0x68、`0x81A8E0` 純 lookup、T10-1 的 500ms timer。

## 下一批 T10-25～28 / T11
A. 從 motion 完成及 actor+0x3E8 讀寫 xref 追 action completion consumer。
B. 找 `0x549D7D` 那組 16-byte status slot 的 reader、初始化、重置條件。
C. 尋找 `0x54F4E0` cooldown entry 的實際非零剩餘時間 writer，不能只找 predicate。
D. 找 Z 映射的 `Table/KeyMapping.xml`，並驗證 pressed/held。
E. 最後才比較四種 transition 的 gating（Z 連按、Z 長按、普攻→技能、技能→普攻）。

## 範圍限制
不執行目標、不修改遊戲或封包；T11 尚未正式 owner 登記，本批只分析 T10↔T11 shared boundary，不覆寫任何其他 Agent 已負責的方法。

## 附錄：原始 BIN 位址範圍反組譯摘錄

### VA 00546250..00546310
[code block separately checked in preflight]

### VA 00549D45..00549D95
[code block separately checked in preflight]