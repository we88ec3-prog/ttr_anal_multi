# T10-44 — 玩家 input bitmask 至技能 matrix predicate 與動作輸出的證據界線（BIN-first 大型研究）

- 分析時間：2026-10-27T22:48:03.772321+08:00
- 來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際核對）
- `.text` 以 PE32 i386 objdump Intel 反組譯；入口對齊已知函式，局部分支首地址僅當分支落點，跨結尾需以上游完整指令校驗。
- GitHub 主責目錄：`kr-temp-roy/T10/`；不執行原程式，不修改主程式與其他 Task。

## 深度分析結果與可驗證結論
- 【已確認】`0x54F270` 依優先順序將輸入 flags `0x03/0x05/0x06/0x01/0x02/0x04/0x08/0x10` 映射至 key 4/5/6/1/2/3/7/10；flags 含 `0xC0` 直接 early allow。
- 【已確認】矩陣取值依序用 `0x40F7F0`、`0x819220`、`0x81A8E0`；得到 nonzero skill ID 後，經 `0x54F4E0` 查狀態記錄，再用其 `+4==0` 判斷。**這仍是可用性 predicate，不是技能施放指令**。
- 【已確認】`0x546100` 當 `0x54F270` 返回 0 但 actor +0x3E8 非零，仍保留局部允許旗標；因此僅從「predicate false」不能推論當次動作被完全禁止。
- 【未閉環】缺少從 controller 输出到 animation start/complete/next-action queue/cancel 的精確回呼，亦未證實 V 點按長按設置哪個 tier。此段對 T11 僅引用矩陣／消耗界線，不修改 T11 owner。

## 呼叫與欄位證據
`0x5462DD → 0x54F270 → 0x819220/0x81A8E0/0x54F4E0` 是已確認的 gating 分層；動作施放指令或冷卻 writer 不在此證據鏈。

## 技術邊界／反證
- 各段的「已確認」僅表示所列機器碼直接支持的條件或資料搬移；任何玩家 V/Z/X/C 行為都仍屬待交叉驗證。
- `+0x3E8` 要先證實 base type 相同，不能從偏移相同認為同一欄位；既有 T10-33～40 只當背景，新增結論以此段反組譯為準。
- 無法從單一 BIN 推斷伺服器權威取消窗口、技能消耗與時鐘單位；不採用本地 AI 實作的時間常數。

## 下一步可核對路徑
1. 追 `0xFAB130` 樹的讀取方（key-to-instance lookup），比對 `0x546100` 實際 controller 物件分配與寫入者。
2. 查 `0xFB9004+index` 的非零狀態 writer，以及 `KeyMapping.xml` 的 row 到 action flags 映射。
3. 由 controller 返回輸入結果的 consumer 追動作 queue/motion callback，而不是在 `0x54F270` 停止。

## 原始反組譯摘錄（各區間含上下游）

### VA 0x546254–0x546309
[code block separately checked in preflight]

### VA 0x54f270–0x54f330
[code block separately checked in preflight]

### VA 0x4aebfc–0x4aec18
[code block separately checked in preflight]