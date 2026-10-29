# T10-053／055／056 全碼塊與原生主張複驗

2026-10-29 Asia/Taipei；審核者 Codex T01 / review_t10。基準 `fd8507169932ee9cb9d9362fcab07a5a3bd9bfa5`。僅讀原件，不執行／附加、目標API或修改遊戲。

三篇均完成此次逐行檢查及決議，維持 **PARTIAL，全文 FULL-PASS 0**。三篇主題的有限原生事實仍有支持；不是發現三篇新的原生行為錯誤。剩餘是原稿證據附錄與泛稱「列出的直接讀寫／call 已確認」的適用界線，不是要求先解完 Z/V 或整體遊戲才可驗收。

原件 KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。獨立讀取 PE sections，`.text` VA `401000`／raw `400`。

## 覆蓋與防止驗收器偽陽性

- **14 個 ASM 碼塊，648 行 quoted bytes** 全核對原件；602 行為對齊、操作數一致的原生指令／padding編碼；22 行為視窗尾端明示 `.byte`／segment-prefix 截斷及其後續殘片；24 行位於錯位視窗頭（其中1行已明標 `(bad)`，23行為錯位線性解碼的指令呈現）。
- 602 行另比較 mnemonic/operands；五個 `push 0xffffffff` 與 Capstone `push -1` 皆為同一 `6A FF` 的 32-bit sign-extension 顯示，已排除偽陽性。
- `.byte`、`(bad)`、續行／尾端殘片不當成新 native 行為反證。原始 byte 片段正確，不表示錯位解碼可以當作正常路徑指令。
- 原件 rooted CFG 來自九個已指定入口；cached Ghidra 的 source/index hashes 已核對。`6D08C0` 是 `6D0750` 靜態傳入的callback指標，只用來校正附錄跨入下一函式的截斷，不假造cache entry。
- 每個碼塊、每行bytes／canonical指令／分類／來源行號在 [source-codeblock-audit.json](source-codeblock-audit.json)；非code每項肯定主張、unknown和完整覆蓋決議在 [decisions.json](decisions.json)。

## 來源版本

| 原稿 | SHA256 | Git blob SHA | 本批決議 |
|---|---|---|---|
| T10-053 | `e527d144471dfa118f90b3d99c2134242d5335521a933c1757259268ecfe0089` | `4f5cde1802cedb0520c49b3ddc40eee12536298f` | PARTIAL；核心事實支持，附錄界線需註明 |
| T10-055 | `3b3a2dcf12540643499faa3f00770b61e9e74669fe6048744f0313503280f84a` | `61c1e3bca931c781be72db549bed483202cfff1a` | PARTIAL；核心事實支持，附錄界線需註明 |
| T10-056 | `0d0b9f07373355c959291cb9ac8fddc5ad840b05167e5222b9001f8626f549a5` | `e2da2b34e1c97aeffd192d5af7a258f80b50c527` | PARTIAL；核心事實支持，附錄界線需註明 |

## 全部碼塊

| 原稿／塊 | 原稿行號 | 對齊行 | 尾端明示截斷 | 起點錯位 | 決議 |
|---|---|---:|---:|---:|---|
| 053／1 | 31–67 | 33 | 0 | 2 | 需排除錯位起點指令 |
| 053／2 | 71–104 | 28 | 4 | 0 | 有效指令通過；尾端僅作raw片段 |
| 053／3 | 108–138 | 29 | 0 | 0 | 有效指令解碼通過 |
| 053／4 | 142–166 | 20 | 3 | 0 | 有效指令通過；尾端僅作raw片段 |
| 053／5 | 170–190 | 18 | 1 | 0 | 有效指令通過；尾端僅作raw片段 |
| 053／6 | 194–234 | 37 | 2 | 0 | 有效指令通過；尾端僅作raw片段 |
| 053／7 | 238–264 | 21 | 3 | 0 | 有效指令通過；尾端僅作raw片段 |
| 055／1 | 17–74 | 47 | 0 | 9 | 需排除錯位起點指令 |
| 055／2 | 78–127 | 48 | 0 | 0 | 有效指令解碼通過 |
| 055／3 | 131–189 | 52 | 4 | 0 | 有效指令通過；尾端僅作raw片段 |
| 055／4 | 193–240 | 43 | 2 | 1 | 需排除錯位起點指令 |
| 056／1 | 21–104 | 79 | 2 | 0 | 有效指令通過；尾端僅作raw片段 |
| 056／2 | 108–204 | 94 | 1 | 0 | 有效指令通過；尾端僅作raw片段 |
| 056／3 | 208–274 | 53 | 0 | 12 | 需排除錯位起點指令 |

## 逐篇核心與附錄裁決

**053**：line11及17–23的七筆 literal、raw/VA、reader／zero-store 分類相符。`548950..548956` 的 `(bad)`／錯位 inc 不證明有該 inc 路徑，真正 `54894A` 長指令結束於 `548952`，後接 cmp/jump，`548957` reader 是有效邊界。原稿 line25 已明示需從正確邊界解碼，因此不把首窗當作原生語意反證，也不新建 FAILED 通知。建議只在後續勘誤把這兩行明列 diagnostic，並讓line268的泛稱確認不涵蓋它們。

**055**：line11的 `FDF630` tree、sentinel `FDF634`、命中才寫 `node+10` byte0 以及普通reader介面差異均通過。第一窗 source18–26（`6D4BB0..6D4BC1`）起點錯位；第四窗 source194的 `6D4D40 lock push` 來自前一LEA的F0 immediate。它們不是尾端 `.byte` 截斷，而是不同的頭部錯位現象。第二／第三窗已同時保留正確路徑，不能依最新視窗覆蓋。line244的泛稱確認需限定有效範圍。

**056**：line11/15的兩個 valid direct calls `59624E`、`59643F` 及附近 EC/F0 多態處理通過。第三窗 source209–220 的頭部錯位解碼含 `596441 call F8DC6459`，與本篇第二窗正確 `59643F call6D4CE0` 互相重疊；rooted CFG 證明後者是此路徑指令。這不是改變reader核心結論，應在line278的泛稱確認中排除錯位頭部。

## 具體限定修正提案

[return-proposals.json](return-proposals.json) 僅有055／056兩項 `NEEDS_QUALIFICATION` 建議，供整合者決定如何登記T10 README專區；未寫其他Task、原稿或前批資料。固定ID含EVIDENCE，明示不撤銷核心已核對事實。053有明示boundary caveat，沒有把它新增為FAILED。

修正可由T01自有勘誤先提供正確片段；要簽核原稿全文，仍須將勘誤／標註版及其新blob/SHA與原稿連結並重驗確認範圍。不能把本次結果倒寫成原始版本全文通過。

## 重跑

在repo根目錄，提供指定SHA原件與Capstone5.0.6（例為本機既有vendor）後：

```powershell
$env:T01_TARGET='E:/Tartaros/workspace/Tartaros.bin'
$env:T01_CAPSTONE_ROOT='E:/Tartaros/workspace/t01-work-20261029/vendor'
python -X utf8 -B shared/integrations/T01-20261029-continuation-02/t10/review.py
python -X utf8 -B shared/integrations/T01-20261029-continuation-02/t10/decide.py
python -X utf8 -B shared/integrations/T01-20261029-continuation-02/t10/publish.py
```

重現腳本使用前批已提交 `T01-20261029-semantic-review/support/audit.py`，不依賴私有未提交helper；cached原證據以本機anal-multi快取唯讀核SHA。未攜帶原BIN或Capstone執行庫，不宣稱沒有原件也能重做語意驗證。此批不代表其餘95篇、T10動作鏈或遊玩已驗收。
