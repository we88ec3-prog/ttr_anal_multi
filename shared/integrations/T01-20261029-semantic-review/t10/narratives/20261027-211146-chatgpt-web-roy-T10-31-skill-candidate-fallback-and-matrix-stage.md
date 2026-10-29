# T10-31 — 0x549C60 技能候選 7/9 的參數傳遞、actor fallback 與矩陣界線

## 本段動機
T10-30 見 1/2 actor 狀態選擇 7/9 呼叫 0x549C60。需要驗證 7/9 經何處處理，避免直接命名 V 技能 tier 或冷卻結束。

## 第一手發現
- `0x549C60` 透過 `0x54AA60` 對最初兩個參數作候選設定，`0x548D20` 對 `[ebp+0x14]` 作額外數值轉換；此處回傳值 EAX 低16位保存在 EDI（`movzx edi,ax`）。
- 模型資料來源是 `this+0x50` 的 actor +0x88 WORD，拒絕 model >9；使用 hero record stride 0x210，必須滿足 hero record +0x5C 非零；接著對 +0x1F4 指向的資料記錄讀 byte。這與 T10-29 controller 的 skill tier 資料存取**形狀一致**，但不證明是相同 actor 物件實例或同一個 action。
- `0x549D29` 先比較 arg+0x10 是否為 `-1`，是就以 actor+0x3E8 覆蓋這個參數；因此 **-1 是一個回退到 actor state 的候選 sentinel**，至少在此函式確定。這為 T10-30 的 7/9 呼叫澄清：其 `-1` 參數會促使 state fallback，7/9 則是另外的參數，不能當作 tier。
- `0x549D54` 接 `0x54F270` availability predicate，成功後將輸出 mask 低15位更新，寫 [0m`[this + 0xAC + slot*16] = 4`，並用目標座標差計算角度寫 `this+0x74`。**這是 SubAI 的候選及方向更新，不是施放完成或資源消耗**。

## 逐址原始組語

研究日期：2026-10-27 Asia/Taipei。原始 KR `Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）；唯讀 GNU objdump -Mintel，VA 使用原 PE image base。原件未執行、修改或動態附加。此稿的「函式／物件語義」若沒有 RTTI 標示，僅是可閱讀的暫名。

### VA 0x00549C60–0x00549D29
[code block separately checked in preflight]

### VA 0x00549D29–0x00549E05
[code block separately checked in preflight]

### VA 0x0054F270–0x0054F330
[code block separately checked in preflight]

### VA 0x0081A8E0–0x0081A909
[code block separately checked in preflight]

## 矩陣與組合交叉確認
`0x54F270` 將 bit0/1/2 的單項和兩項組合映射至 key 1..6，另 bit3->key7、bit4->key10；`0x81A8E0` 適用 tier [0,3]、key [0,10]。這能容納使用者所述 Z/X/C 單鍵與組合，但 **7/9 在 SubAI `0x549C60` 入口是參數，不可直接等於「matrix key7/key9」**；必須沿 `0x548D20` 的轉換和 `0x54AA60` 後才能證實。

## 偽碼與未解
[code block separately checked in preflight]
未解：`0x548D20` 使 7/9 變成何種 flags、`0x54AA60` 是否改寫候選集、actor+0x3E8 真正 writer。以上仍不能回答 V 點按/長按或普攻接技能之動畫合法窗口。
