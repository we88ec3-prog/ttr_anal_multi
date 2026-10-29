# T10-080 — config to action open chain matrix

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

本批獲得完整且可核的「來源字串 → 主配置解析 → packed DWORD vector → active/default bank 選擇 → Extra DWORD 表」局部鏈。到執行時 phase、玩家 Z/X/C/V、V tap/held、普通攻擊 queue/cancel、motion writer 的連接仍未證實；不應以段號完成冒充原版玩法還原。

## 可複核第一手機器碼

### VA `0x006D0930–0x006D096A`（raw `0x2CFD30–0x2CFD6A`）

[code block separately checked in preflight]

### VA `0x006D0B0E–0x006D0B6E`（raw `0x2CFF0E–0x2CFF6E`）

[code block separately checked in preflight]

### VA `0x006D0C4C–0x006D0C93`（raw `0x2D004C–0x2D0093`）

[code block separately checked in preflight]

### VA `0x006D1A93–0x006D1B33`（raw `0x2D0E93–0x2D0F33`）

[code block separately checked in preflight]

### VA `0x006D4D70–0x006D4DBE`（raw `0x2D4170–0x2D41BE`）

[code block separately checked in preflight]

## 資料流／分支推導

1. 來源：`.rdata` `0xC40888`=`Table/KeyMapping.xml`，`0xC408C0`=`Key`，`0xC408C4`=`MapButton`，`0xC408D0`=`ModKey`。
2. loader：`0x6D08F0` 經 parser/helper 取欄位，合成32-bit DWORD 並附加至 `0xFB8834+type*0x280+row*0x10` vector。
3. bank 選用：`0x6D1A70` 設 `0xFB902C`；另一 default branch 讀 `0xFB9034` 並呼叫 `0x6D1BE0`；是否同一實際使用時機不明。
4. runtime phase：`0x6D4CE0` 僅證明一般／特殊鍵 byte 查詢，未見直接 same-object writer；需按資料擁有者追記憶體別名。
5. motion / queue / cancel：目前沒有由 `0x6D08F0` 的配置 slot 直達 actor motion 的 receiver 及 call graph，不能推時間常數或 combo 排隊機制。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

[code block separately checked in preflight]

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：下一段先查 `0x6D0D10` 是否真為 Extra 檔、`0x6D1BE0` 及 `0xFB8D34` 的 reader；最優先查 `0xFB902C` consumer、非零 phase writer，以及 game actor queue/cancel writer。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。