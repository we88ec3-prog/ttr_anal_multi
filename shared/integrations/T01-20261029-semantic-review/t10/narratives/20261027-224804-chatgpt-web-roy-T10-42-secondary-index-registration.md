# T10-42 — 第二容器的索引與 controller actor slot 來源之辨別（BIN-first 大型研究）

- 分析時間：2026-10-27T22:48:03.731845+08:00
- 來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際核對）
- `.text` 以 PE32 i386 objdump Intel 反組譯；入口對齊已知函式，局部分支首地址僅當分支落點，跨結尾需以上游完整指令校驗。
- GitHub 主責目錄：`kr-temp-roy/T10/`；不執行原程式，不修改主程式與其他 Task。

## 深度分析結果與可驗證結論
- 【已確認】工廠建構回傳的 `esi` 先傳入 `0x4DFF30`；它的註冊鍵來自 `[esi+4]`，不能視為玩家角色 slot 編號。
- 【已確認】`0x4DFFB0` 的入口使用 `ecx` 指向另一物件，`[esi]` 作為識別，`0x4E0020` 在特定全域條件下向 `[ebx+0xF8]` 寫回該 `esi`，隨後在 `ebx+0x18` 呼叫 `0x57E850`。這是另一個容器更新流，而非足以證明 controller actor 的直接證據。
- 【已確認】`0x546137` 從 controller `[ecx+0xC]` 讀取 actor；若全域模式 `[0xFBA7AC]==3`，`0x546141..148` 以 `3*(slot)+3` 生成索引，從同一 controller 的不同位置讀取。
- 【排除】不應把 `0x4DFFB0` 的 `ebx+0xF8` 與 `0x546137` 的 controller `[ecx+0xC]` 混同；必須先追到同一個 owner 指標。

## 呼叫與欄位證據
`0x4DFFB0 → 0x57E850` 把第二種物件/容器的寫入與 controller slot 區隔。`0x546137` 的 `[ecx+0xC]` 和 slot 分流皆從 controller `ecx` 派生。

## 技術邊界／反證
- 各段的「已確認」僅表示所列機器碼直接支持的條件或資料搬移；任何玩家 V/Z/X/C 行為都仍屬待交叉驗證。
- `+0x3E8` 要先證實 base type 相同，不能從偏移相同認為同一欄位；既有 T10-33～40 只當背景，新增結論以此段反組譯為準。
- 無法從單一 BIN 推斷伺服器權威取消窗口、技能消耗與時鐘單位；不採用本地 AI 實作的時間常數。

## 下一步可核對路徑
1. 追 `0xFAB130` 樹的讀取方（key-to-instance lookup），比對 `0x546100` 實際 controller 物件分配與寫入者。
2. 查 `0xFB9004+index` 的非零狀態 writer，以及 `KeyMapping.xml` 的 row 到 action flags 映射。
3. 由 controller 返回輸入結果的 consumer 追動作 queue/motion callback，而不是在 `0x54F270` 停止。

## 原始反組譯摘錄（各區間含上下游）

### VA 0x4aec00–0x4aec90
[code block separately checked in preflight]

### VA 0x4dffb0–0x4e0060
[code block separately checked in preflight]

### VA 0x546100–0x5461c0
[code block separately checked in preflight]