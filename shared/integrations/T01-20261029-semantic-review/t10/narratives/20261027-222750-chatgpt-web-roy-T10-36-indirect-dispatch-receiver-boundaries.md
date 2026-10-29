# T10-36 — selector setter 間接呼叫候選與 receiver 型別追溯（BIN-first）

- 時間：20261027-222750 Asia/Taipei；接續 T10-35，這次研究以完整欄位分派與候選去歧義為主。
- 證據：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，實際 `sha256sum` 複驗。
- `.text` PE VA/檔案映射 `0x401000`/`0x400`；此份摘錄來自唯讀 objdump `-d -Mintel -j .text`。
- 沒有執行或修改遊戲。未將未知 selector 語義命名成 Z/V 或動作取消。

## 一、新驗證：直接建構點與間接呼叫檢索的可證明範圍

1. 全 `.text` 的 `call 0x4CD6F0` 直接指令來源在本輪找到 `0x4A0FD8`、`0x4AE609`（與 T10-35 相符）；只能窮盡 *該種直接 call 編碼*，無法排除 indirect calls、函式位址取用或動態派遣。
2. `0x4AE5xx` 先透過 `BYTE` 類型 0..7 的跳轉表，經 `0x891268` 分配 `0x444` 容量，再呼叫 `0x4CD6F0`；這證明存在資料驅動的物件建構，但 **不證明輸入來源是封包或鍵盤**。
3. `0x4CD6F0` 呼叫 `0x4C7070`，覆寫 `[edi]` 為 `0xC07B44`；`0xC07B70`（相對 slot `+0x2C`）是 `0x4CE7F0`。這是能被靜態證實的類型與 slot 所有權。
4. 對整份 `.text` 進行候選間接呼叫掃描：前七行有 `mov REG,[REG+0x2c]`、後接 register `call` 的掃描得到 **236 個粗略候選**。這是*沒有 data-flow 去重/型別確認的上界候選集合*，絕不代表 236 個都是這個 setter 的呼叫者。
5. 可見例如 `0x48B7D8` 處的 vptr slot `+0x2C` 呼叫，但僅憑這個序列，無法將 `edi` receiver 等同 `0x4CD6F0` 的建構實例。`0x492A04` 等候選也持有不同上游 receiver（例如 `[ebx+0xBF50]`）；因此本段**沒有確認任何玩家事件→selector=5 setter 的直接動態連線**。
6. `0x5462B4` 的 controller 確實讀取 actor `+0x3E8`，但尚無同一個分配物件從建構/註冊到 controller 指標欄位的可追溯搬移鏈；目前只能列為結構相容性，不是 receiver identity 證據。

## 二、按鏈條標示觀察與未證明缺口

[code block separately checked in preflight]

## 三、第一手機器碼摘錄（入口周邊，上下游對照）

### 0x4A0FD8
[code block separately checked in preflight]

### 0x4AE609
[code block separately checked in preflight]

### 0x4CD6F0
[code block separately checked in preflight]

### 0x4CE7F0
[code block separately checked in preflight]

### 0x4CE90A
[code block separately checked in preflight]

### 0x5462B4
[code block separately checked in preflight]

### 0x546338
[code block separately checked in preflight]

### 0x48B7D8
[code block separately checked in preflight]

### 0x492A04
[code block separately checked in preflight]


## 四、對可能誤判的具體否定

- selector=5 與 input index=5 不能相互代換；兩者不同結構、不同程式路徑。
- `+0x2C` 是 vtable **slot offset** 而非固定函式身分；各衍生/無關型別可有不同方法。
- 同偏移 `+0x3E8` 在不同物件中可能不同義，需從 `[this]` vptr、constructor factory、receiver 傳遞鏈確認。
- `[0xFB9009]` 是陣列 index 5，尚未證明代表物理 V、Z 或 pressed/held。
- `value=1` 的從屬重建不是「V 蓄氣達標」的原生證據。

## 五、可檢驗的下一輪研究（T10-37）

1. 從 `0x4AE609` 的建構返回值 `esi` 起找容器插入、entity registry、controller actor 的賦值流；不把相同 offset 誤當同一實體。
2. 對候選 `call [vptr+0x2C]` 逐個追 receiver 的 vptr 來源，僅將可回溯 `0xC07B44` 或該物件繼承族者列為真正 dispatch caller。
3. 找到一條真實 player input producer → action ID/selector → virtual setter 的鏈條後，才評估與 V 點按/長按、普攻→技能銜接的關係。
4. 狀態轉換 gate `0x546100` 與動畫/佇列分派仍待獨立驗證；後端規則歸 T11/T12 所有者。

## 六、結論與交付

本段以全映像間接呼叫候選掃描和 receiver 限定條件為主，確立 virtual slot 的 **證據邊界**；沒有將粗略候選冒充已識別的玩家按鍵 callback。T10-36 作為一段深度調查結案，剩餘問題繼續到 T10-37。提交時應保留本份完整原稿與既有 T10-33～35 完整原稿。GitHub commit 狀態以實際工具結果另行記錄。