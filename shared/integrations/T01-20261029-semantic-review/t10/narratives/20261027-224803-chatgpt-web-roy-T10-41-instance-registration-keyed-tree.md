# T10-41 — 工廠物件註冊：WORD key 與樹節點插入／重複鍵分流（BIN-first 大型研究）

- 分析時間：2026-10-27T22:48:03.715707+08:00
- 來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際核對）
- `.text` 以 PE32 i386 objdump Intel 反組譯；入口對齊已知函式，局部分支首地址僅當分支落點，跨結尾需以上游完整指令校驗。
- GitHub 主責目錄：`kr-temp-roy/T10/`；不執行原程式，不修改主程式與其他 Task。

## 深度分析結果與可驗證結論
- 【已確認】`0x4AEC01` 將 `esi` 中的實例放入 `eax`，並把 `0xFAB130` 放在堆疊，直接呼叫 `0x4DFF30`。`0x4DFF30` 在 `0x4DFF4C` 從 `[edi+4]` 取得 unsigned WORD 索引鍵，並用 `0x82EF00` 搜尋傳入容器 `ebx+8` 的樹。
- 【已確認】`0x4DFF67` 以 `[ebx+0xC]` 判斷是否走 missing 分支。missing 時準備 `{key, instance}` 寫入來源並呼叫 `0x82F200`；命中時走 `0x6EDB60` 的另一支線，**不是覆寫原節點已確認**。
- 【重要界線】此處只證實「物件到索引容器」；不能從 `0xFAB130` 推論它就是 `0x546100` 控制器物件 `[ecx+0xC]`。
- 【待查】找出容器 `0xFAB130` 的所有讀取 caller，以及 instance 指標是否複製至 controller +0xC 或 slot table。

## 呼叫與欄位證據
`0x4AEC03 → 0x4DFF30`，`0x4DFF30 → 0x82EF00 / 0x82F200 / 0x6EDB60`。物件 `esi+4` 為 WORD 鍵，容器 `ebx+8` 為樹搜尋入口。

## 技術邊界／反證
- 各段的「已確認」僅表示所列機器碼直接支持的條件或資料搬移；任何玩家 V/Z/X/C 行為都仍屬待交叉驗證。
- `+0x3E8` 要先證實 base type 相同，不能從偏移相同認為同一欄位；既有 T10-33～40 只當背景，新增結論以此段反組譯為準。
- 無法從單一 BIN 推斷伺服器權威取消窗口、技能消耗與時鐘單位；不採用本地 AI 實作的時間常數。

## 下一步可核對路徑
1. 追 `0xFAB130` 樹的讀取方（key-to-instance lookup），比對 `0x546100` 實際 controller 物件分配與寫入者。
2. 查 `0xFB9004+index` 的非零狀態 writer，以及 `KeyMapping.xml` 的 row 到 action flags 映射。
3. 由 controller 返回輸入結果的 consumer 追動作 queue/motion callback，而不是在 `0x54F270` 停止。

## 原始反組譯摘錄（各區間含上下游）

### VA 0x4aeb78–0x4aec18
[code block separately checked in preflight]

### VA 0x4dff30–0x4dffaa
[code block separately checked in preflight]