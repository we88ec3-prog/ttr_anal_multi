# T10-30 — SubAI 對 actor+0x3E8=1/2 的逐 slot 計數與兩個候選技能鍵

## 研究目標與新資料流
先前只確認 `0x549D7D` 寫入狀態 4。這一段轉往 `0x548FF0` 的有界 SubAI 更新函式，查看它是否有輸入來源和切換動作條件。

- `0x548FF0` 的 prologue 與 `ret 0x10` 結束於 `0x54916E`。入口保存 actor、target、索引等資料於 `this+0x50..0x60`，呼叫 `0x549180`，然後透過 actor+0x4 的 model? WORD 與 `this+0xA8` 起三個 stride16 的項目做匹配。注意 actor+0x4 的**正式語義未知**；不能將三個項目當三個技能鍵。
- 在有匹配的 slot（ebx）下依序呼叫 `0x549E10 → 0x54A450 → 0x54A3A0 → 0x54A200 → 0x54A2D0 → 0x54A050`，前一個成功即跳過後續。這是**多條技能/目標候選策略**的證據，不是證明普通攻擊六種組合都透過這個 chain。
- `0x5490FB..0x549114`：若 this+0x4C 非零、actor+0x3E8 為 1 或 2，才執行 `inc DWORD [this+0x40+ebx*4]`；若不是則不累加。
- `0x549118..0x549141`：計數大於 `0x3C`（60）時，如果 actor 狀態是 1 就 push `7`；若為 2 就 push `9`，再 push -1,0,0 到 `0x549C60`，最後把計數清零。**這是多次更新呼叫的次數門檻**，沒有 tick rate 的證據，不能寫成「V 按一秒」。`7`/`9` 尚非已確認的矩陣 key，須先追 `0x549C60` 参数使用。

## BIN 指令原文

研究日期：2026-10-27 Asia/Taipei。原始 KR `Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）；唯讀 GNU objdump -Mintel，VA 使用原 PE image base。原件未執行、修改或動態附加。此稿的「函式／物件語義」若沒有 RTTI 標示，僅是可閱讀的暫名。

### VA 0x00548FF0–0x00549050
[code block separately checked in preflight]

### VA 0x00549050–0x00549171
[code block separately checked in preflight]

## 資料流／偽碼
[code block separately checked in preflight]
該偽碼只保留必要條件；完整分支如上反組譯，參數寄存器／棧位置不可據此取代原生呼叫約定。前置 compare 0x3C 是**大於**才觸發；首次從0開始且每次+1將經過61次加法才成立（若沒有其他重置）。

## 與 T11／V 的分界
T11 候選：`0x549C60` 技能候選測試、`0x549E10` 目標距離狀態、`0x5490xx` 逐 slot counter。現有資料含 AI 目標與 actor 模型匹配，不能當成玩家蓄氣直接作業。下一段對 `0x549C60` 的參數 fallback、角色 gate 和矩陣選取做定向解析。
