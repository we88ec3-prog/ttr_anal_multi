# T10-29 — Actor +0x3E8 的共用技能狀態來源、條件物件比對與控制器邊界

## 本段目標
先前 T10-25 提到 actor+0x3E8 傳入 `0x54F270`。本段反向驗證此欄位至少還被 SubAI 的條件物件所讀取，避免把它只按 Z/V 蓄氣狀態命名。此欄位真正 setter 尚未定位。

## 新增原生驗證
- `0x54ADC0` 是獨立函式，以輸入物件 `[arg+0x50]` 找 actor，actor 存在時取得 `[actor+0x3E8]`，actor 不存在取 0。最後與 `this+0x4` 比較，相等回 1，不等回 0。**這直接證明同一 actor 欄位可作為 SubAI condition predicate 的精確相等比較參數**，但不能證明 `this+0x4` 是蓄氣需求。
- `0x546100` 中呼叫 `0x54F270` 前，`0x5462B4` 將 `actor+0x3E8` 壓棧；`0x5462BC..0x5462C3` 依資料記錄第 2 byte 是否非零選擇兩個 byte 之一，`0x5462D2..0x5462D9` 再用 controller 索引選 skill status object。呼叫結果 0 的分支將輸出 action word 與 0x8000 AND，清除低15 bits，**輸入准入**和**施放成功**在此不可等同。
- `0x54825D` 在另一控制器路徑同樣讀 `actor+0x3E8`，並用 `0x54F270`。這是一個交叉的資料來源，不應把 0x546100 專稱「Z」的唯一 handler。

## 可復現 BIN 指令：精確函式窗口

研究日期：2026-10-27 Asia/Taipei。原始 KR `Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）；唯讀 GNU objdump -Mintel，VA 使用原 PE image base。原件未執行、修改或動態附加。此稿的「函式／物件語義」若沒有 RTTI 標示，僅是可閱讀的暫名。

### VA 0x0054ADC0–0x0054ADE0
[code block separately checked in preflight]

### VA 0x00546254–0x00546309
[code block separately checked in preflight]

### VA 0x0054824C–0x00548290
[code block separately checked in preflight]

## 暫定 C++ 語意草圖
[code block separately checked in preflight]
這是指令層級功能概要，不含真正型別與命名；需透過 constructor/RTTI 回填。

## 與使用者遊戲行為的關係
使用者指出按鍵可改、Z/X/C 與其組合、V 點按／長按均會影響招式。actor+0x3E8 很可能提供技能取用的其中一項選擇狀態；**尚未找到此欄位由 V 輸入更新的 writer**，也未證實四個 matrix tier 全由 V 控制。

## 證據級別／待查
已確認：兩路 controller 讀取及 SubAI 精確相等條件。推測：該欄位表示角色技能可用性相關狀態。未確認：V 綁定、是否 charge stage、狀態 0/1/2 的玩家意義、動作 cancel 或 cooldown 對應。下一段沿 SubAI 選招與逐 slot 計數詳細展開，不假定它是玩家蓄氣。
