# T10-091 — 0x761010 三個狀態 bit 的候選子物件選取規則

## 原始來源／驗證方式

- 對象：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本批於實際掛載檔重新計算且一致。
- `.text` 原生 VA `0x401000`、raw offset `0x400`，既有反組譯文字 `t10-full-disasm.txt` 由 KR BIN 的 `objdump` 產生；本段抽查來源指令，並以 VA 保存可重做的窗口。
- 靜態唯讀，不啟動／附加／修改客戶端；先前 T10-081～088 作查詢線索，不把先前推測升格為本段原生結論。
- 證據分級：**已確認**＝以下實際 x86 指令與控制流；**部分確認**＝受限路徑或候選物件；**尚待驗證**＝class／語義／間接 producer、callback、motion 行為。

## 主題：0x761010 是有條件遍歷器，而非固定子物件 accessor

### 完整已核對 selector 原始指令

[code block separately checked in preflight]

原生控制流：輸入物件由 `eax` 傳入；若 `[eax+0x68]==0` 返回 null。否則 `[eax+0x64]` 指向容器相關指標，經 `[eax]`、`[eax+4]` 取得 sentinel／節點，從 `[node+8]` 取候選物件；從 `[object+0x28]` 讀狀態整數。選擇條件為 bit19 **未設**、bit8 **設置**、bit12 **未設**，滿足則返回 `[node+8]`；不符合就按 `[node+4]` 前進直到 sentinel。以上位元值依實際 `shr`/`test`：`0x76102C shr 0x13`、`0x761036 shr 0x8`、`0x76103E shr 0xC`。需注意 bit19 的 test 結果若非零直接跳過，bit8 沒設亦跳過，bit12 設置亦跳過。

### 0x5961C0 caller 的輸入

[code block separately checked in preflight]

T10-087 的 `0x5961ED mov eax,ebx`、`0x5961EF call 0x761010`，使候選對象來自 `ebx` 所指容器；若結果 null，後續子物件分派也可能走 fallback。這是明確的間接條件，不是「永遠一個玩家角色」。

### 查詢結果與 phase 消費的橋接

[code block separately checked in preflight]

`0x596245 mov esi,edi` 把輸入 ID 寫入 reader 使用的寄存器，`0x59624E call 0x6D4CE0` 得 phase。phase=1 路徑查 `+0xEC`，phase=3 查 `+0xF0`；實際被選物件的 vptr 仍未得出，故尚未解出 override 的 target VA，更沒有到 motion action 的閉合證據。

## 重要反證與接續

- 新增確認：selector 不是純 getter，確實使用 3-bit predicate 篩選候選物件。
- 尚待驗證：`[eax+0x64/0x68]` 的類別及容器 owner；`node+8` 是否真正 AvatarBase；vtable+0xEC/+0xF0 implementations；motion／queue/cancel。
- 不將 T08 類別或 T11 skill object 的同名 offset 沒有指標歸屬前合併。