# T10-35 — 衍生 actor 物件的雙路建構來源、selector 5 後處理與控制器證據界線（BIN-first）

- 時間：2026-10-27 22:18:46 Asia/Taipei。
- 證據：`/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本段重新校驗。
- 靜態分析：`objdump -d -Mintel -j .text`，不執行、修改或附加目標。
- 繼承 T10-33、T10-34 已核對結論；本段增量研究，不替代舊文。GitHub 未 Commit／Push。

## 一、這次新增的可核證結論

### A. `0x4CD6F0` 有兩個直接 callsite，且所屬上游並不相同

全 `.text` 指令搜尋 `call 0x4CD6F0`，觀察到 `0x4A0FD8` 與 `0x4AE609` 兩條直接呼叫路徑。這是**直接 call 的枚舉，不包含 indirect call 或函式指標**，不可聲稱所有建構源已窮盡。

**來源 1：`0x4A0F70` 附近工廠樣流程**

[code block separately checked in preflight]

上游依參數及條件分派到三種不同大小配置/初始化，`0x444` 對應 `0x4CD6F0`，其餘是 `0x4D1710` / `0x4D2120` 類別候選。此處能明確保證 `0x4CD6F0` 不是全域唯一的物件建構類型。`0x4A0F70` 的確切函式入口需函式邊界交叉驗證，此標記只作區域稱呼。

**來源 2：`0x4AE5xx` 資料驅動的類型分派**

[code block separately checked in preflight]

這條路徑先用字節類型（0..7）選分支，再依資料 `+0xE` 的欄位建立衍生物件；緊接著跟全域上下文的一個 `+0x5F50` 值比較。可以確定是**由資料欄位驅動建構並受條件分支控制**。`ebx` 究竟是網路封包、載入暫存或內部序列化資料，尚未完成來源追溯；不能稱已證明 server 直接驅動 selector=5。

### B. `0x4CD6F0` 所建構物件大小與附屬資源生命週期

[code block separately checked in preflight]

結合配置來源，該建構分支要求 `0x444` bytes 的物件容量，`+0x42C` 等欄位在配置內。已確認的 `[this+0x42c]` 等欄位是*附屬資源/子物件指標候選*，不把它們命名成技能蓄氣器。

### C. vptr 清理階段回填與附屬物件釋放

`0x4CDAF8` 位於 `0x4CDAD0` 入口之下：

[code block separately checked in preflight]

即使入口名稱沒有符號證據，這仍是強力的**衍生類物件資源清理**跡象：vptr 恢復、檢查子物件、虛擬釋放、置零。這支持 vtable `0xC07B44` 在生命週期的兩端都有效；但 vptr 回填不能解作角色戰鬥狀態重設。

### D. selector=5 不只改一個欄位，還可能重新生成從屬物件

T10-34 已知 `0x4CE7F0` primary slot +0x2C 的分派。此段向下延伸 selector=5 的 value=1 分支，直接觀察到虛擬函式 +0x4C，以及新建從屬結果寫回 `+0x364`。

[code block separately checked in preflight]

此資料流顯示 `0x364` 先被解除/清除，條件值等於 1 時有重建路徑，指標最後回填。`0x49B140` 和 `0x551F90` 必須各自確認返回 ABI 與建立物件語意；目前僅能說與從屬狀態重建相關，不能解釋成 V 蓄氣結束或某普攻技能生成。

## 二、現階段類型證據與作用圖

[code block separately checked in preflight]

### 不應混為同一索引空間的數字

1. `0x4AE5D4` 的 data record type 0..7。
2. `0x4CE7F0` 的 selector 1..30。
3. `0xFB9004 + index` 的輸入狀態陣列。
4. `0x54F270` 的技能 matrix key / flags。

即使它們出現數值 5 或 7，沒有跨模組寄存器/參數資料流就**不認定互相映射**。

## 三、局部偽碼：分派來源（推導摘要，符號未證）

[code block separately checked in preflight]

註：上段 `helper_551F90` 的擷取略去實際寄存器與堆疊細節；不能視為已確認的 C++ 真實宣告。

## 四、明確缺口、反證與後續焦點

| 議題 | 狀態 | 證據與限制 |
|---|---|---|
| 兩個直接 constructor callers | 已確認 | `0x4A0FD8`, `0x4AE609` |
| `0x444` bytes 衍生類配置 | 已確認於兩路 | `0x4A0FB8`, `0x4AE5E4` |
| 物件 vptr +0x2C setter | 已確認 | `0x4CD728`，表 `0xC07B70` |
| selector=5 之 value=1 條件再生 | 部分確認 | `0x4CE945..0x4CE99D` |
| 讀入 record 就是 network packet | 尚待驗證 | 缺 `0x4AE5xx` 上游資料生產與來源 |
| setter receiver == 玩家 controller actor | 尚待驗證 | 同 offset 不是同指標證明 |
| 玩家 V 點按/held 對應 selector 5 | 尚待驗證 | 缺按鍵 writer → setter 路徑 |
| Z/X/C/V configurable mapping | 尚待驗證 | 需要 XML row/非零 input writer |
| 普攻/技能 queue, cancel, motion | 尚待驗證 | 須追控制器動作輸出鏈 |

下一段以 `0x4AE5xx` record 上游、vtable +0x2C 的真正 indirect callsite、`0x4CE9xx` 建立的從屬物件消費者三者為先；並行追 `0x546100` controller receiver 如何來源到相同類型。不要先把 data-driven constructor 等同 network packet/玩家按鍵。

## 五、結案標準

T10-35 已有實質且可回溯的兩個建構來源、條件再生副作用與析構生命週期原生證據，深度研究已完成；並**未**宣稱重建完整的玩家蓄氣或普攻-技能功能鏈。下一段 T10-36。無 Commit/Push。