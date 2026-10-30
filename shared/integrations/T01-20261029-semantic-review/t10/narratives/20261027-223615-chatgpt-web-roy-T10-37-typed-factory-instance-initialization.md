# T10-37 — 型別驅動工廠與新物件初始化、註冊邊界（BIN-first）

- 研究時間：2026-10-27 22:36:15 Asia/Taipei
- 原始樣本：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際驗證。
- PE `.text`: VA 0x401000 / raw 0x400。以 objdump `-d -Mintel` 唯讀反組譯，沒有啟動、修補或附加客戶端。
- 關係：T10-33～36 先前證明 constructor 0x4CD6F0、vtable 0xC07B44、slot +0x2C 0x4CE7F0；本文僅以直接 BIN 複驗內容增加限定結論。
- 證據標籤：【確認】直接指令；【推論】結構或控制流解釋；【未知】缺乏呼叫身分／玩家輸入語義。

## 新確認的證據與具體資料流
1. 【確認】`0x4AE5D4` 限制 index <=7，`0x4AE5DD` 使用 `0x4AED90` 跳轉表。只有落在 `0x4AE5E4` 分支時，配置 `0x444` 並呼叫 `0x4CD6F0`；不能將所有 0..7 類型一律判定為此 actor 類。
2. 【確認】`0x4AE604–0x4AE609` 從輸入記錄 `[ebx+0x0E]` 讀 32-bit 值、與配置指標一併傳給 ctor；`0x4AE610` 的 `esi` 保存 ctor 返回值，供之後分支共用。這是新物件指標從建立到初始化的可直接追溯段。
3. 【確認】`0x4AE917` 檢查 `esi!=0`，之後依 `[ebx]` 的 WORD 值，透過 `0x515790` 查全域 `0xFC0E90` 的資料樹；`0x4AE98A` 還透過 `[0xFBA7A4]` 的 vtable+0x20 取得外部物件。這些是建立後的依賴查找，不得未經證明命名為 entity registry 寫入。
4. 【確認】`0x4AEAA4` 以 `[ebx]` WORD 呼叫 `0x541610`；`0x4AEAE5` 透過 `0x4F7A70` 取得索引結果並取 result+0x61，存入新物件 `+0x41C`。此欄位的資料來源與控制器 `+0x3E8` 不同。
5. 【確認】`0x4AEB0A..0x4AEB30`：新物件 `+0x9C←[ebx+0x0E]`、`+0x90←BYTE[ebx+0x14]`、`+0x04←WORD[ebx-0x04]`。隨後對同一 `esi` receiver 連續呼叫 vtable `+0x3C/+0x44/+0x58/+0x5C/+0x30`（`0x4AEB34..0x4AEB7D`）。**這是從 factory 到初始化虛擬方法的同一物件身分鏈**，但沒有 +0x2C setter 的呼叫。
6. 【確認】`0x4AE9xx` 的檢索檢查與 `0x4AEBxx` 欄位填充在同一函式中；【未知】此記錄由封包、場景檔還是其他來源產生。不能將其當成玩家攻擊按鍵輸入。
## 局部偽碼（按目前已追出的分支）
[code block separately checked in preflight]
## 排除與待查
- 不能把出現在這個 constructor 尾端的虛擬方法序列直接當作 `vfunc_2C(selector=5)`。
- 下一研究入口：`0x4DFF30` 和 `0x4AEC4A` 後續的對象歸屬、`0x4AE5C0` 輸入 record 的生產者，另找導致 `+0x2C` virtual call 的具體 receiver 資料流。

## 原始 x86 證據附錄（區間按函式入口或前文已知分支起點擷取）

### VA 0x4ae5d0–0x4ae66d
[code block separately checked in preflight]

### VA 0x4ae917–0x4aea10
[code block separately checked in preflight]

### VA 0x4aeaa0–0x4aeb80
[code block separately checked in preflight]