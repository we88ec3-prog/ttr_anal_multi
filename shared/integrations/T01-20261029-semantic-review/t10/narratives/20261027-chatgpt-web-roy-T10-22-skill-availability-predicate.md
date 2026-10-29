# KR T10/T11 交界研究 — T10-22 T11 技能矩陣與剩餘計時 gate

- 日期：2026-10-27 Asia/Taipei
- 證據：原始 Tartaros.bin，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 方式：BIN 唯讀 objdump i386，.text VA 0x401000／raw 0x400，位址均為 VA
- 任務隔離：T10 主導攻擊輸入與連接；技能計時、消耗、施放裁決的 T11 邊界以引用／候選標記，不擅改 T11 task.json 或別人的分析
- 不執行目標、不修改遊戲檔案、不將本地替代連段窗口視為原版值

## 核心結論
`0x54F270..0x54F32F` 為有界獨立函式；直接檢查 input flag byte：若含 `0xC0`，跳過矩陣檢查直接回傳 1。其他位元組先映射 key（單鍵 1/2/3、組合鍵 4/5/6、bit8 -> 7、bit16 -> 10），接著從 `[esi+2]` 讀 model WORD 與 caller 提供的第二索引查矩陣。`0x819220` 回傳非零才可呼叫 `0x81A8E0`，取得矩陣 WORD skill ID。查到 ID 後進入 `0x54F4E0` 的樹，檢測記錄 `+4` DWORD 是否為零：相等則回 1。這是 *predicate*，不是冷卻啟動器。

與 T10-1/T10-4 既有查詢結論交叉核對：`0x54F4E0` 找不到 key 時可能新增節點，因此即使 `0x54F270` 在語意上是 availability check，也**不等於所有記憶體寫入皆無副作用**。但新增節點本身不足以證實冷卻開始。

## T11 候選標記
- `0x54F270`：**T11 可用性 / 檢查**，已直接確立用在 T10 控制器。
- `0x819220` + `0x81A8E0`：矩陣解析 / key lookup，**不是 T11 施放裁決本身**。
- `0x54F4E0`：含容器插入的 cooldown 記錄查找，需追實際 timer writer。

## 偽碼
[code block separately checked in preflight]
**不保證完全複製參數順序**；`0x54F4E0` 可能修改樹結構。

## 下一段
與其他 `0x54F270` 呼叫者比對，分別判定 actor 控制器與 SubAI 決策何處交錯。

## 附錄：原始 BIN 位址範圍反組譯摘錄

### VA 0054F270..0054F330
[code block separately checked in preflight]