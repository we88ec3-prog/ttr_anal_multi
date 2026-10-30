# T10-57 — 映射讀取者與矩陣消費者的型別邊界

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

`0x594610` 回傳映射結果的查詢轉換，`0x5CD91F` 為其直接 caller，`0x5CD937` 有 `×0xB` 的索引計算。矩陣 `WORD` 不等於 phase byte；沒有 `KeyMapping.xml` 和 action row 就不能聲稱 Z/X/C/V 映射已解。

## 映射消費呼叫交叉參照

`0x594610` direct E8 候選：0x5cd91f, 0x5d1b75, 0x5d2dd5, 0x5d4045, 0x60e06b, 0x651122, 0x65117e, 0x6511da, 0x65120a。僅作位址索引，未完成 receiver 重建。

## 第一手 x86 反組譯摘錄

### VA `0x00594610` ／ raw `0x00193A10`（320 bytes）

[code block separately checked in preflight]

### VA `0x005CD890` ／ raw `0x001CCC90`（245 bytes）

[code block separately checked in preflight]

### VA `0x005CD925` ／ raw `0x001CCD25`（150 bytes）

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