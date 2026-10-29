# KR T10-8 — 控制器 Gate 與 Z 連段證據邊界整合

紀錄日期：2026-10-27T19:11:40+08:00

## 0. 來源與限制
- 研究對象：韓版 KR T10「普通攻擊與連段」，使用者指出 Z 連按、Z 按住不放兩種操作。
- 原始檔 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；僅唯讀，PE `.text` VA `0x00401000` 對映檔案 raw `0x400`；GNU objdump `-b binary -mi386 -Mintel --adjust-vma`。**所有位址為 VA，函式名稱除符號佐證者均為暫定。**
- 已有 T10-1～T10-4 原稿作背景；本段新增事項皆以本次 raw BIN 讀取核對。未啟動／附加遊戲或修改任何原始資料。
- 原生證據只證明目前觀察到的機器碼與資料流；不可反推出 Z 對應 bit、實際連段時間、是否可玩。

## 1. 分析與證據
本段將 T10-7 已確認的輸入輸出，延伸到 `0x546100` 下游 gate，區分三種層級：**input state**、**actor/action constraint**、**傳送封包**。本輪未見足以證實 Z 長按自動續段的原生閉環，故不把「取得關鍵 bit」虛報為 Z 已還原。

`0x546263` 的返回存進 caller stack，對 controller／actor 的輸入 Word 在 `0x54628F～0x5462A2` 結合原舊值；`0x5462A2` 檢查全域 `0xFBA7AC==1` 並可能短路。`0x5462B0` 取 `[edi+0x3E8]`，`0x5462DD` 用 `ecx` 中的資料結構呼叫 `0x54F270`，以返回值控制 `0x5462E2～0x546306` 是否接受或清理資料。`0x5462FD` 用 `and WORD [ebx+2],0x8000` 清除其低 15 位，**但此分支並未證明是 Z 連段取消**。

在 `0x546306～0x54636E`，全域一次性初始化可呼叫 `0x6D0750`；接著檢查 `[edi+0x158]` 狀態元件是否存在及 `+0x30` 是否為 0，並呼叫 `0x4C9ED0` 檢查旗標。**這是下游條件限制的機器碼事實，正式動作語義未核定。**

本輪 T10-5～T10-8 的可連結證據鏈：
[code block separately checked in preflight]

**明確缺口**：
1. 找到**實際版本** `Table/KeyMapping.xml` 並確認 Z 對應的 row 與 action；fallback 不等於實際配置。
2. 找出 physical keydown、keyup、held 或 polling writer，連回 `0xFB9014`，而非把 `0x547240` 直接命名為 Z 長按。
3. 找出 attack motion／animation 的下一段消費者，確認 held 會如何每段續發，連按是否只依 pressed edge；查出 cancel 與 chain window 的真正依據。
4. 區分 client 與 server 權威；不可沿用本機自製 `CHAIN_WINDOW=0.65`。T12 傷害公式排除。

**證據級別**：確定＝上述指令、欄位、mask 運算、呼叫鏈中每一已觀察邊；合理推測＝存在 actor/action 接受條件；未確認＝兩類 Z 操作合流、續段、取消／窗口與遊玩實測。

**下一階段 T10-9**：優先取得實際 XML 與上游 writer，按控制器 action bit 追查原生普通攻擊下游消費者；不再擴大通用映射 tree/CRT 分支。

**協作**：僅保存 T10 個人研究文件，無遊戲執行或修改，不能覆蓋 T02／T04／T09／T12 的主責結論。根據使用者本次明確授權，四段全完成後方允許 Commit／Push。


## 2. 原始 BIN 組語摘錄（逐址重新反組譯）
### actor/input gate (VA `0x0054627A`)
[code block separately checked in preflight]

### actor 狀態後續 gate (VA `0x00546338`)
[code block separately checked in preflight]

### 狀態機 500ms 分支 (VA `0x005472F6`)
[code block separately checked in preflight]