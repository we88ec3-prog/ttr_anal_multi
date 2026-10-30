# KR T10-7 — 即時控制器輸入三路合流與輸出位元

紀錄日期：2026-10-27T19:11:40+08:00

## 0. 來源與限制
- 研究對象：韓版 KR T10「普通攻擊與連段」，使用者指出 Z 連按、Z 按住不放兩種操作。
- 原始檔 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；僅唯讀，PE `.text` VA `0x00401000` 對映檔案 raw `0x400`；GNU objdump `-b binary -mi386 -Mintel --adjust-vma`。**所有位址為 VA，函式名稱除符號佐證者均為暫定。**
- 已有 T10-1～T10-4 原稿作背景；本段新增事項皆以本次 raw BIN 讀取核對。未啟動／附加遊戲或修改任何原始資料。
- 原生證據只證明目前觀察到的機器碼與資料流；不可反推出 Z 對應 bit、實際連段時間、是否可玩。

## 1. 分析與證據
本段以 `0x546780` 的完整函式關鍵分支建立**輸入合流優先順序**，區分「返回 action mask」與「寫入輸入 Word」。

入口由 `0x546263` 直接呼叫；`edi = eax` 保存控制器指標，從 `[edi+0x5C]` 讀取原始 `WORD`，將輸入位元組暫存複製為三份，再 `call 0x547240`。對狀態機返回 2/3/4 分別 OR `0x0008`、`0x0080`、`0x0040` 到 EBX。這是**同一個輸出 Word 中的三個相異 bit**，尚不知道是否 Z。

接著依次呼叫：`0x546850`（`0x5467CD`）、`0x546B50`（`0x5467E0`）、`0x546D50`（`0x5467EC`），保留三路返回值。於 `0x5467F1` 將 EBX 寫入 caller 提供的 WORD 指標；若 `0x546850` 結果非零，優先把第一個暫存 byte 寫回；否則若 `0x546B50` 非零，改採第二個 byte；再否則依第三路結果選第三個 byte。返回值是三路 bitwise OR 的結果，可能同時包含多個訊號，而 byte 回寫則有**優先選擇**。

與 `0x546100` 的接合：`0x546263` 的返回值存至 caller local `+0x28`，`0x546286～0x5462A2` 對另一輸出 `WORD` 使用 XOR/AND 合併；`0x5462A2` 檢查全域 `0xFBA7AC`，在此分支之外（不等於 Z gate）。`0x5462DD` 將取自當前 actor／控制器之資料送 `0x54F270` 執行額外檢查，非全然等同「連段允許」。

**暫定 C++ 偽碼，保留資料來源**：
[code block separately checked in preflight]

**已確認**：狀態返回至 bit 的映射、三條輸入收集呼叫及 byte 優先順序；**待驗證**：每個 byte 是方向還是按鍵、Z 對應哪個 bank row、三組是否對應連按／長按／其他來源。

**T10-8 接續方向**：檢查 runtime 下游使用返回值與 actor gate，確認哪些 bit 會清除、送出或經動作查表；列出對 Z 自動續段的證據缺口。


## 2. 原始 BIN 組語摘錄（逐址重新反組譯）
### 即時輸入 gather (VA `0x0054678A`)
[code block separately checked in preflight]

### 三個返回路徑及 byte 優先 (VA `0x005467C8`)
[code block separately checked in preflight]

### 控制器調用與更新 (VA `0x00546254`)
[code block separately checked in preflight]