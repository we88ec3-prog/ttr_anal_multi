# T10-070 — keymapping row attributes

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

主配置讀取函式在 `0x6D0A2C` 以 `Type`／`Key`／`MapButton`／`ModKey` 等字串查詢列資料，並以轉整數 helper `0x8917B4` 產生數值欄位。其迴圈依 XML node 分支與比較退出，不能光看表名就把行索引換成 Z 或 V。

## 可複核第一手機器碼

### VA `0x006D0A2C–0x006D0ACE`（raw `0x2CFE2C–0x2CFECE`）

[code block separately checked in preflight]

### VA `0x006D0ACF–0x006D0AFF`（raw `0x2CFECF–0x2CFEFF`）

[code block separately checked in preflight]

## 資料流／分支推導

1. `0xC408B8`=`Type`，`0xC408C0`=`Key`，`0xC408C4`=`MapButton`，`0xC408D0`=`ModKey`，由 BIN .rdata 查核。
2. 子項遍歷使用 `+0x50` 指標與 `edi` 比較，`0x893CB1` 文字比較結果決定對應分支，`0x8917B4` 轉成整數。
3. 數值候選以不同暫存器及 stack slot 匯合到 bank writer；必須先核對哪個欄位對應哪個暫存值才能定義 key/action 綁定。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

[code block separately checked in preflight]

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：釐清每個解析分支的 `esi`、`edi`、`ebx`、`stack+1c` 實際值與上游 node 類型。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。