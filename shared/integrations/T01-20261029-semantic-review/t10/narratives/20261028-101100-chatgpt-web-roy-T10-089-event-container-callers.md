# T10-089 — 事件容器 caller 與 reset 非 producer 反證

## 原始來源／驗證方式

- 對象：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本批於實際掛載檔重新計算且一致。
- `.text` 原生 VA `0x401000`、raw offset `0x400`，既有反組譯文字 `t10-full-disasm.txt` 由 KR BIN 的 `objdump` 產生；本段抽查來源指令，並以 VA 保存可重做的窗口。
- 靜態唯讀，不啟動／附加／修改客戶端；先前 T10-081～088 作查詢線索，不把先前推測升格為本段原生結論。
- 證據分級：**已確認**＝以下實際 x86 指令與控制流；**部分確認**＝受限路徑或候選物件；**尚待驗證**＝class／語義／間接 producer、callback、motion 行為。

## 主題：0x6D4A30 的兩個真實 caller 不是同一容器來源

### Callsite A：0x490DFC 與既有全域容器

[code block separately checked in preflight]

`0x490DEF` 由 `[0xFAADFA]` 取一個 byte 並零延伸，按順序 `push 0xF95CD8`、`push eax` 後呼叫 `0x6D4A30`。只可說明第一參數是當時取得的全域 byte，第二參數是 `0xF95CD8` 容器地址；尚未知道這個 byte 是模式、事件數量或 reset selector。因為此處未見建立容器節點，它與第二個 caller 的生命週期不同。

### Callsite B：0x58A607 配置 12 bytes 的自連結節點

[code block separately checked in preflight]

`0x58A5D1 push 0xC`、`0x58A5DB call 0x891268`、`0x58A5EF mov [esi],esi` 與 `0x58A5F5 mov [esi+4],esi`，證明 12-byte allocation 的前兩個指標初始化為指回自己；stack `[esp+0x14]` 指向它。`push 1` 和 `push &stack_container` 後呼叫 `0x6D4A30`，這條路可確定使用**新建暫時容器**，但不能從 node 自連結推論已經包含按鍵事件。

### 清零實體與方向

[code block separately checked in preflight]
[code block separately checked in preflight]

重點反證：對 `0xFB9004..0xFB9028` 的 10 個 DWORD stores 使用 `xor eax,eax` 的 **0**；對一般 `ID` 的 `byte[0xFB9004+ID]` 與特殊容器項 `[eax+0x10]` 也是清零。不能因這些 caller 與鍵盤事件共用名稱或數據結構就稱它們是 `phase=1/3` producer。

## 可重建的有限資料流

[code block separately checked in preflight]

## 結論與缺口

- 已確認：兩個 callsite 的參數、暫時容器節點布局、清零操作與後續物件欄位清理。
- 部分確認：`0x6D4A30` 消費容器中的 ID；但 A 的持久容器內容 producer 與 B 的後續節點插入者不能從此處直接得到。
- 未確認：任何 Key44..47 → MapButton13..16 → phase1/3 的寫入；`0xFAADFA` 的語義；`0xF95CD8` 的寫入者。
- 下一步：追 `0xF95CD8` 的插入路徑及 `0xFAADFA` 非零 writer；不要把 reset caller 當作輸入事件發布。