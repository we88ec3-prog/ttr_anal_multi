# T10-34 — actor-derived vtable ownership、selector setter 與玩家 gate 的類型邊界（BIN-first）

- 分析：20261027-221624（Asia/Taipei）；起始段 T10-34，未重編 T10-33。
- 原始資料：`/mnt/data/Tartaros.bin`，PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新 `sha256sum` 驗證）。
- 反組譯：`objdump -d -Mintel -j .text`；只靜態讀取，不執行/附加。原版資源未修改。
- GitHub：未 Commit、未 Push；T11 只作交界，不修改 owner、其他 Agent 內容。

## A. 此段實質新證據與區別於 T10-33 的結果

### A1. **確定** 0xC07B44 vtable 的建構期安裝，不再只是孤立的 `.rdata` 函式指標

`0x4CD6F0` **由函式入口**追查，在 `0x4CD718` 取得參數物件 `edi`，`0x4CD71C` 呼叫基底初始化 `0x4C7070`，隨後 `0x4CD728` 寫 `[edi]=0xC07B44`，`0x4CD72E` 寫 `[edi+0xF0]=0xC07BCC`。`0x4C7070` 自身曾設 `[ebx]=0xC07554` 以及 `[ebx+0xF0]=0xC075DC`；因此這是**可由直接指令支持的衍生階段 vptr 覆寫**。

`0xC07B70 - 0xC07B44 = 0x2C`，`0xC07B70 -> 0x4CE7F0`，從而確認 **這個衍生物件的 primary vtable slot +0x2C 指向 selector dispatcher**。這不是 setter 的直接 caller：執行時若走多型分派，需要找到 `call [vptr+0x2C]` 與正確 receiver 來源。

**重要範圍收斂：** 0x4CE7F0 不再只稱 actor-like 任意物件中的非零 writer，而是 `0x4CD6F0` 所建構、繼承 `0x4C7070` layout 的物件家族中的 virtual setter。尚缺 RTTI 名稱與 `0x546100` 直接使用的 actor 指標相等的可追蹤證據，因此不宣稱已證明玩家實體。

### A2. 分派器的 selector 與值不同維度（獨立可驗證）

入口使用 `movsx ecx,word [ebp+8]` 導入 selector、`selector-1 <= 29` 做界限；在 selector 5 對應的 jump-table 分支用 `movsx ecx,word [ebp+0xC]` 取得 value，寫入 `[ebx+0x3E8]`。緊接檢查舊 `[ebx+0x364]` 是否存在，並呼叫 cleanup/helper；當寫入值為 1 才走額外後續邏輯。可從此判定這不是單純裸 setter，而包含關聯狀態生命週期處理。未見可證實 V 按壓時長的分支。

### A3. 玩家 gate 的關聯性與反證

`0x546100` 由 controller actor `edi` 讀 `[edi+0x3E8]`，在 `0x5462DD` `call 0x54F270` 前作參數。這與上述 selector setter 共享 offset，但**不是函式調用連線**。`0x546338` 讀取 `[0xFB9009]` 是 index 5 的狀態陣列入口，與 setter selector 5 屬不同索引空間。本次尚未找出 action ID 及 nonzero writer。

## B. 選取的第一手 x86 指令

[code block separately checked in preflight]

## C. vtable 局部清單（從 BIN little-endian 讀 `.rdata`）

| vtable address | entry | slot offset from 0xC07B44 |
|---|---|---|
| `0xC07B44` | `0x4CDAA0` | `0x00` |
| `0xC07B48` | `0x5F5D10` | `0x04` |
| `0xC07B64` | `0x4CDD40` | `0x20` |
| `0xC07B68` | `0x4CDE30` | `0x24` |
| `0xC07B6C` | `0x4CE270` | `0x28` |
| **`0xC07B70`** | **`0x4CE7F0`** | **`0x2C`** |
| `0xC07B74` | `0x4CDBA0` | `0x30` |
| `0xC07B78` | `0x4C8060` | `0x34` |

此清單是原檔 raw 位元組反解的靜態表；相鄰表、RTTI 起點另須驗證，不對整個範圍任意定義型別。

## D. 類型／資料流關係（只畫已獲得的邊）

[code block separately checked in preflight]

## E. 偽碼（部分已確認，型別暫名）

[code block separately checked in preflight]

## F. 對 T10 全面課題的貢獻與仍缺的環節

**本段確定：** 建構函式 → 衍生類型 vptr → slot +0x2C → setter dispatcher → selector 5 → 欄位 +0x3E8 的靜態原生鏈。這是一條比 T10-33 更完整的**物件／虛擬分派鏈**。

**未確認：** RTTI 類名；primary vtable +0x2C 所有可能的 virtual callsite；某個 callsite 如何提供 selector=5；玩家控制器 actor instance 是否必然屬於此 vtable；selector 5 是否由伺服器、腳本、動畫或玩家 V 產生；Z/X/C/V 的 XML 設定 row 和非零按鍵 writer；4 tier 實際選擇、普攻/技能 motion/cancel/queue 的因果鏈。不要將任何缺口命名為原版已證機制。

### 建議後續定向分析（T10-35 起）

1. 靠近 `0x4CD6F0` 與 `0x4C7070` 的 RTTI / 物件分配 caller 查 actor 來源，再在 `0x546100` 取得的 actor 指標類型作同一性驗證。
2. 在 `.text` 中找所有 `[vptr+0x2C]` 讀取 → register indirect call，交叉整理 receiver 型別，回推 selector=5 的產生者（可能由 script/network/simulation 觸發，待證）。
3. 獨立追 `0x6D08F0` XML fallback mapping 和 `0xFB9004+index` 的非零 writer，避免與 setter selector 數字巧合污染結論。
4. 追 `0x546100` gate 向 motion/queue/cancel 輸出串接，必要時僅引用 T11/T12 證據，維持 Task 邊界。

## G. 完成判定

本段已完成**建構函式、vtable owner、虛擬方法指標、setter side effects 的深度分析**；大系統尚有缺口不阻止此段交付。未提交 GitHub。