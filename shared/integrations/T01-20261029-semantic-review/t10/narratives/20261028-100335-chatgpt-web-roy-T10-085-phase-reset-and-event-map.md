# T10-085 — 輸入 phase 清零與事件容器：定位非零 writer 的負面邊界

**證據版本**：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪 `sha256sum` 核對）；`.text` VA `0x401000`，raw `0x400`；`objdump -D -Mintel` 直接對 PE32 `.text` 反組譯。檔案靜態唯讀。

## 新結論

1. `0x6D4A30` 不只是清空全域 40 byte：先以 guard 初始化 bank / 事件結構，`0x6D4A93..0x6D4AC9` 與 `0x6D4B69..0x6D4B98` 將 `[0xFB9004..0xFB902B]` 分別以 10 DWORD 寫零。
2. `0x6D4C06..0x6D4CC0` 迭代傳入容器的節點，取 `node+8` 作事件 ID；`0x6D4C23` 用 `ID-0x2711` 比較 `0x270E`（亦即 ID 10001..19999 的另一資料域），對特殊 ID 透過 `0x82EF00` 搜索 `0xFDF630` 節點並將 `node+0x10=0`；普通 ID 走 `byte[0xFB9004+ID]=0`。注意這是清零，不是非零 phase writer。
3. `0x6D4CE0` 對普通 ID `<=39` 直接讀 phase byte，對 10001..19999 的 ID 由 `0xFDF630` 關聯容器讀 `node+0x10`。因此同一 reader 已實證可同時處理普通與特殊映射 ID，不能把其調用一概視為 Z/X/C/V。
4. 本段仍沒有證明 phase=1/3 由哪個輸入 producer 寫入；不可由 reset 反推 producer。下一輪需追入 `0x6D4A30` 的兩個 callsite 及事件容器生產者。

## BIN 組語原稿片段（直接證據）

### VA 0x006D4A93..0x006D4AD0

[code block separately checked in preflight]

### VA 0x006D4C06..0x006D4CC1

[code block separately checked in preflight]

### VA 0x006D4D05..0x006D4DBF

[code block separately checked in preflight]

## 證據分級與研究限制

- 「已確認」僅指列出的 BIN 字節與控制流；對象／業務語義若沒有 vtable 及 producer 證據一律維持「部分確認」或「尚待驗證」。
- 未執行、修改客戶端，未引入任何原始遊戲資源至 GitHub；沒有擅自修改其他 Task 的 owner、catalog 或筆記。
- 此筆記為 T10 專項研究完整原稿，包含可複查的 VA 原始指令及限制，不將反編譯和 AI 替代當原生依據。