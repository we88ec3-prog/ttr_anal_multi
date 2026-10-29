# T10-53 — 一般按鍵狀態全域位址完整直接參照盤點

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

`0xFB9004` 位址常數共七個直接命中，其中包含讀取、成批寫入與按索引寫零；已檢查的直接命中無法證明非零 writer 不存在。間接指標、不同 base 的等價位址及未定位的外部事件處理仍是缺口。

## `0xFB9004` 常數的 raw 命中逐項核對

| Raw offset | VA（同檔 `.text` 映射） | 對應指令類型（由附近 x86 定位） |
|---|---|---|
| `0x147D5A` | `0x54895A` | reader |
| `0x2CFC76` | `0x6D0876` | 初始化 DWORD 清零 |
| `0x2D0F03` | `0x6D1B03` | 刷新 DWORD 清零 |
| `0x2D3E9D` | `0x6D4A9D` | 批量清零 |
| `0x2D3F6C` | `0x6D4B6C` | 另一路批量清零 |
| `0x2D40B0` | `0x6D4CB0` | 特別鍵域相鄰寫零 |
| `0x2D419B` | `0x6D4D9B` | 索引讀取 |

**重要限制：** 此處為常數 byte-pattern census，不是 CFG/xref 完整性證明；附近指令需要從正確函式邊界解碼。

## 第一手 x86 反組譯摘錄

### VA `0x00548950` ／ raw `0x00147D50`（130 bytes）

[code block separately checked in preflight]

### VA `0x006D0861` ／ raw `0x002CFC61`（105 bytes）

[code block separately checked in preflight]

### VA `0x006D1AFB` ／ raw `0x002D0EFB`（85 bytes）

[code block separately checked in preflight]

### VA `0x006D4A93` ／ raw `0x002D3E93`（95 bytes）

[code block separately checked in preflight]

### VA `0x006D4B69` ／ raw `0x002D3F69`（90 bytes）

[code block separately checked in preflight]

### VA `0x006D4CAE` ／ raw `0x002D40AE`（80 bytes）

[code block separately checked in preflight]

### VA `0x006D4D93` ／ raw `0x002D4193`（60 bytes）

[code block separately checked in preflight]

## 已確認／部分確認／未證實

- **已確認（區域性）：** 本檔指定 VA 的可讀原始 byte 及列出的直接讀寫／call 指令；以相應位址及前置條件為限。
- **部分確認：** 這些路徑具備輸入資料結構或 controller 消費候選的關聯，確切 receiver／建構實例與完整 CFG 仍待核實。
- **未證實：** Z/X/C/V 自訂 action mapping、V 點按／長按真正的 timer/tier writer、連按 Z 和 held Z 自動續段、動畫完成 callback、普攻↔技能 queue/cancel、官方後端裁決。

## 與既有 T10-45～52／T01 整合的關係

此段為原始 BIN 的**限定驗證／擴充證據盤點**，不取代 T10-1～44 原稿或 T01-20261027-05 的有限語義接受範圍；同 offset 不能跨型別混用。使用者玩家觀察只是動機，非原生已證事實。

## 下一步可驗證路線

1. 向後追 key state 的 **非零 writer**：找不依賴絕對位址常數的 base+index store 或由 keyboard/DirectInput/window message 注入的 callback。
2. 驗證同一個 actor/controller receiver 的建構、指派、虛表及動作啟動 writer，再連接 motion completion 的 next-action queue。
3. 取得此版本的 KeyMapping.xml/fallback row 並比對 action id 與實際鍵狀態，不把 `VK_Z` 寫死。

## GitHub 提交界線

僅使用者授權的 `kr-temp-roy/` 新檔；不變更 owner、catalog、其他 Task 或原始執行檔。