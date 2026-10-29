# T10-090 — FB73E8 全部直接引用與初始化／getter 區分

## 原始來源／驗證方式

- 對象：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本批於實際掛載檔重新計算且一致。
- `.text` 原生 VA `0x401000`、raw offset `0x400`，既有反組譯文字 `t10-full-disasm.txt` 由 KR BIN 的 `objdump` 產生；本段抽查來源指令，並以 VA 保存可重做的窗口。
- 靜態唯讀，不啟動／附加／修改客戶端；先前 T10-081～088 作查詢線索，不把先前推測升格為本段原生結論。
- 證據分級：**已確認**＝以下實際 x86 指令與控制流；**部分確認**＝受限路徑或候選物件；**尚待驗證**＝class／語義／間接 producer、callback、motion 行為。

## 主題：0xFB73E8 跨系統讀者／唯一可直接證實的初始化 writer

### 全 .text 絕對位址參照（採文字反組譯掃描）

[code block separately checked in preflight]

這是反組譯行中**直接包含** `fb73e8` 的參照，既不包含通過 pointer alias 的寫入，也不保證所有 data producer 都是同一 `.text` 區段。不能將搜尋負面結果敘述成「此狀態永遠為零」。

### 初始化 writer 復查

[code block separately checked in preflight]

`0x560197 xor ebx,ebx` 隨後的 `mov [0xFB73E8],ebx`，從來源可證明寫 0；沒有在此窗口寫 1 的原生指令。

### Getter 反例：0x4A97FE

[code block separately checked in preflight]

此函式先呼叫 `0x560170`，再從 `0xFB73E8` 取值為返回 `eax`；是**讀取與回傳**，非直接 flag producer。`0x560170` 的間接效果與各 caller 尚須另追，不能因 `call` 在 load 之前就宣稱它設置了 flag。

### 與控制流程的有界關聯

[code block separately checked in preflight]

當 `0xFB73E8` 非零，此控制流按 `[esi+0x154]` 舊狀態條件呼叫 `0x5A55E0` 的 mode=2，並伴隨 `0x5A5760`、`0x5A57A0`。非零變零時可呼叫 mode=1；它跟 `0x5961C0` 的 ID13/14 特例共用同一全域條件。**不可直接命名**其為戰鬥取消／蓄力狀態，也不可將物件 `+0x154` 等同全域地址。

## 證據分級與後續

- 已確認：列出的直接 xrefs、初始化 zero store、0x4A97FE getter、0x5A4614 條件消費者。
- 尚未確認：`0xFB73E8` 非零 writer（可能是 base-relative，間接 alias，其他模組）；`0x560170` 間接副作用；所有 reader 的業務分類。
- 推薦按 0xFB73C0 鄰近全域結構作 base pointer/alias 追溯；釐清 bitfield/整數型態後才命名業務語義。