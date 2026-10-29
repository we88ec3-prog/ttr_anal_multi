# T10-069 — keymapping xml source

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

直接從 `.rdata` 證實原生主配置檔 `Table/KeyMapping.xml`，`0x6D08F0` 以其位址初始化字串，接 `0x72F110` 條件分支，再依 `KeyMapping`、`DefaultType` 欄位進入資料讀取。這是鍵位自訂載入來源的確認，還不是戰鬥鍵綁定的語義完成。

## 可複核第一手機器碼

### VA `0x006D08F0–0x006D099F`（raw `0x2CFCF0–0x2CFD9F`）

[code block separately checked in preflight]

### VA `0x006D09A0–0x006D0A2B`（raw `0x2CFDA0–0x2CFE2B`）

[code block separately checked in preflight]

## 資料流／分支推導

1. `0x6D0935: mov ecx,0xC40888` 指向 `Table/KeyMapping.xml`；`0x6D0963` 呼叫 `0x72F110`，其 `al` 只用來選擇設定讀取或 fallback 分支。
2. `0xC408A0` 為 `KeyMapping`，`0xC408AC` 為 `DefaultType`，由原始 `.rdata` NUL 結束 bytes 確認。
3. XML parser 型別與錯誤行為不可由 string evidence 直接命名為某個 library 或已成功開啟檔案。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

[code block separately checked in preflight]

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：要取得實際 XML 檔與各 row 的值；`0x72F110` 返回條件與取得物件型別還需追 caller/receiver。

## 額外靜態證據

字串直接 raw 查核：`0xC40888`=`Table/KeyMapping.xml`，`0xC408A0`=`KeyMapping`，`0xC408AC`=`DefaultType`。

## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。