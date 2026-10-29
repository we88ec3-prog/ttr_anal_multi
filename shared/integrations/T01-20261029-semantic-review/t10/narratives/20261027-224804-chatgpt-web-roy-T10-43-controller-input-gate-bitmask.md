# T10-43 — 玩家控制器 input producer → bitmask → actor +0x3E8 允許分支（BIN-first 大型研究）

- 分析時間：2026-10-27T22:48:03.751986+08:00
- 來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際核對）
- `.text` 以 PE32 i386 objdump Intel 反組譯；入口對齊已知函式，局部分支首地址僅當分支落點，跨結尾需以上游完整指令校驗。
- GitHub 主責目錄：`kr-temp-roy/T10/`；不執行原程式，不修改主程式與其他 Task。

## 深度分析結果與可驗證結論
- 【已確認】`0x546262` 將 actor 指標 `edi` 傳給 `0x546780`；返回時它先處理 `WORD [ebx+2]` 的 bitmask 組合（`xor` 加遮罩 `0x7FFF`）。
- 【已確認】僅在額外模式與非零低 16-bit 條件通過後，`0x5462B4` 取 actor `+0x3E8`，搭配 `[esi+0x2]` 決定 byte 選擇，送入 `0x54F270`。predicate 非零將 local `[esp+0x17]` 設成 1；predicate 零但 actor+0x3E8 非零時亦設成 1；兩者皆不成立時將 `WORD[ebx+2] &= 0x8000`。
- 【已確認】`0x546338` 比較全域 `[0xFB9009]` 是否為零；此值在後段方向／空間分支使用，並沒有在該點直接呼叫 actor+0x3E8 的 setter。
- 【尚未驗證】Z held/autochain 和按鍵 action row 的索引映射；不能把 bitmask `0x8000` 解為普攻取消位元。

## 呼叫與欄位證據
`0x546780 → [ebx+2] → 0x54F270`、`[edi+0x3E8]` 共同 gate。函式中另有靜態 flag `0xFB9009`，目前未能證明其 physical key binding。

## 技術邊界／反證
- 各段的「已確認」僅表示所列機器碼直接支持的條件或資料搬移；任何玩家 V/Z/X/C 行為都仍屬待交叉驗證。
- `+0x3E8` 要先證實 base type 相同，不能從偏移相同認為同一欄位；既有 T10-33～40 只當背景，新增結論以此段反組譯為準。
- 無法從單一 BIN 推斷伺服器權威取消窗口、技能消耗與時鐘單位；不採用本地 AI 實作的時間常數。

## 下一步可核對路徑
1. 追 `0xFAB130` 樹的讀取方（key-to-instance lookup），比對 `0x546100` 實際 controller 物件分配與寫入者。
2. 查 `0xFB9004+index` 的非零狀態 writer，以及 `KeyMapping.xml` 的 row 到 action flags 映射。
3. 由 controller 返回輸入結果的 consumer 追動作 queue/motion callback，而不是在 `0x54F270` 停止。

## 原始反組譯摘錄（各區間含上下游）

### VA 0x546230–0x546310
[code block separately checked in preflight]

### VA 0x546338–0x546375
[code block separately checked in preflight]

### VA 0x54f270–0x54f2d2
[code block separately checked in preflight]