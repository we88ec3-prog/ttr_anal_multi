# T10-077 — extra mapping pair append

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

額外來源解析兩個整數後，以第一整數 `<<4` 決定 `0xFB8D34` 的 vector slot，再把第二個整數作為 DWORD 附加；此配置與 main `0xFB8834` bank 不同。

## 可複核第一手機器碼

### VA `0x006D0DBE–0x006D0E51`（raw `0x2D01BE–0x2D0251`）

[code block separately checked in preflight]

### VA `0x006D0E51–0x006D0E9D`（raw `0x2D0251–0x2D029D`）

[code block separately checked in preflight]

## 資料流／分支推導

1. `0x6D0DD2 cmp eax,2` 為兩欄解析成功的檢查；`0x6D0DE3 shl esi,4`、`0x6D0DE6 add esi,0xFB8D34` 定位 slot。
2. 使用 `[esi]`、`[esi+4]`、`[esi+8]` 三 pointer 邏輯和 `0x6D6240` capacity grow helper；此處 append 的是第二整數 DWORD，而非 mode+flag packed 值。
3. slot index 的合法上界、從何種來源來的整數和資料完整性檢查仍缺，不可推成客戶端動作列表。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

[code block separately checked in preflight]

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：需要 `0xFB8D34` 的 downstream reader 與真正的額外檔載入 API；不得將第1整數固定認作 Z/V。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。