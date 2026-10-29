# T10-078 — keymapping bank vector transfer

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

主 XML loader 在結尾依 `0xFB9034`（候選 default type）選擇 bank `0xFB8834+mode*0x280`，並以 `0x6D1BE0` 向 `0xFB8D34` 傳遞 vector 資料；另一分支先呼叫 fallback builder，再使用相同選擇。這是配置 bank→輸出表的靜態證據。

## 可複核第一手機器碼

### VA `0x006D0C4C–0x006D0C93`（raw `0x2D004C–0x2D0093`）

[code block separately checked in preflight]

### VA `0x006D1BE0–0x006D1C8A`（raw `0x2D0FE0–0x2D108A`）

[code block separately checked in preflight]

## 資料流／分支推導

1. `0x6D0C4C` 讀 `0xFB9034` 且只對0或1作輸入分支，`mode*0x280` 計算與 active bank 的 caller 概念不同。
2. `0x6D0C88 push 0xFB8D34` 與上一步的計算 bank pointer 一起給 `0x6D1BE0`；callee 進行按指標差計算的 DWORD 序列複製。
3. `0x6D1BE0` 的 ABI 與完整迭代上限未驗收；不能單憑 caller 視為 deep copy 或最新設定對所有玩家動作生效。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

[code block separately checked in preflight]

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：沿 `0xFB8D34` 消費者追蹤輸出 mapping 成功後的讀取，並驗證 `0x6D1BE0` 所有別名處理。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。