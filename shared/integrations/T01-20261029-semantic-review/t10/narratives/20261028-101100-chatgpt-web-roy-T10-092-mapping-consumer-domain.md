# T10-092 — 基本與 Extra MapButton 消費者的原生 domain 分界

## 原始來源／驗證方式

- 對象：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本批於實際掛載檔重新計算且一致。
- `.text` 原生 VA `0x401000`、raw offset `0x400`，既有反組譯文字 `t10-full-disasm.txt` 由 KR BIN 的 `objdump` 產生；本段抽查來源指令，並以 VA 保存可重做的窗口。
- 靜態唯讀，不啟動／附加／修改客戶端；先前 T10-081～088 作查詢線索，不把先前推測升格為本段原生結論。
- 證據分級：**已確認**＝以下實際 x86 指令與控制流；**部分確認**＝受限路徑或候選物件；**尚待驗證**＝class／語義／間接 producer、callback、motion 行為。

## 主題：0x6D4DC0 的不同 ID-domain consumer，分清 UI 文字和 action runtime

### 低 ID：0x5CD68A 明確請求 MapButton=16

[code block separately checked in preflight]

Stack vector `[esp+0x48]..[esp+0x50]` 初始化為 0，呼叫前 `push 2` / `push 0x10`，對應配置查詢的 mode / MapButton=16；返回 vector 指標後，會呼叫 `0x402160`，若有資料則 `0x594A80` 消費值並形成字串。這支持**配置／文字展現候選**，沒有證明 motion 或攻擊指令。

### 高 ID：0x650E96 明確請求 MapButton=0x2904 (10500)

[code block separately checked in preflight]

`0x2904` 十進位 10500，屬 `KeyMappingExtra.xml` 的高 ID 範圍；同樣採 vector result 與 `0x402160`/`0x594570` 字串處理。此證據反向證明不能把 0x6D4DC0 的所有 caller 都當作基本 MapButton 1..39 或戰鬥控制者。

### 兩個 callsite 的共同點及差異

| 面向 | 0x5CD68A | 0x650E96 |
|---|---|---|
| ID | 0x10 / 16 | 0x2904 / 10500 |
| XML domain | 基本候選 | Extra 候選 |
| 查詢模式參數 | push 2 | push 2 |
| 結果 | 三個 DWORD vector 的輸出區 | 三個 DWORD vector 的輸出區 |
| 後處理 | 0x402160、0x594A80 | 0x402160、0x594570 |
| 嚴格證據 | 查詢 + 字串結構處理 | 查詢 + 字串結構處理 |
| 未成立 | gameplay keydown / attack | Extra runtime action |

### 上一階段輸入／動作完整鏈狀態

[code block separately checked in preflight]

## T10-093 有限可執行研究目標

1. 從 `0x6D4CE0` 非零 phase producer 反追 pointer aliases / `memcpy` / callback，避免只尋 literal `FB9004`。
2. 從 `0x5961C0` 的 this vptr 或 `0x761010` 的 node+8 物件擷取具體 vtable，在只讀靜態下枚舉 `+0xEC/+0xF0` overrides。
3. 逆追 `0xF95CD8` event container 原始插入者與 `0xFAADFA` 的值域。
4. 找 `0xFB73E8` 的非零寫入者；未證明前保留未知。

## 嚴格驗收／禁止推論

目前沒有官方 Z 普攻/V 蓄氣或其他動作的完整 write→dispatch→motion 證據。`CHAIN_WINDOW=.65`、server SubAI>60、`0x547240 >500ms` 不能作原版連段窗口。四段均只讀；未變動其他 Task 的 owner/catalog/notes，也未上傳遊戲原件。