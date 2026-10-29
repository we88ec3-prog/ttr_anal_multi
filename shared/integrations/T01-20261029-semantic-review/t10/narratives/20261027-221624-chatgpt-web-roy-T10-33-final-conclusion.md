# T10-33 — actor +0x3E8 Writer 候選與玩家控制器輸入後段（BIN-first）

- 分析時間：20261027-213053 (Asia/Taipei)
- 對象：KR Tartaros.bin；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE `.text` VA `0x401000`、raw `0x400`，由 `objdump -d -Mintel -j .text` 直接反組譯。
- 範圍：T10 普攻/連段/取消；T11 技能施放只作交界參考。前段 T10-1～32 已存在，不重編。
- 狀態：**部分原生驗證；尚未完整還原 Z/X/C/V、V charge 或 cancel/queue 閉環**。
- GitHub：本次只在本地建立完整筆記，**未提交／未推送**；未改動任何 owner/task/catalog。

## 1. 原生觀察與對象同一性

### 1.1 `0x546100` 控制器的 actor 來源（已確認）
`0x546137`：`edi=[ecx+0xC]`；模式常數 3 時由 `0x546141～0x546148` 按 `arg_0` 切換 actor 指標：`edi=[ecx+(3*arg_0+3)*4]`。`0x546171` 及後段均使用該 `edi`；讀取 `edi+0xE4/+0xE0/+0xB0/+0x158/+0x88/+0x3E8`。**本段的 actor+0x3E8 指 `edi` 的欄位，不能與任意類型同偏移相等同**。

### 1.2 技能候選 gate 實際呼叫（已確認）
在 `0x546254～0x546268` 對 controller 指標執行 `0x546780`；`0x5462B4` 載入 `ecx=[edi+0x3E8]`，`0x5462BF` 先 push 此值；選取輸入來源 byte，再由 `0x5462DD` call `0x54F270`；`0x5462E2` 判回值。若失敗又於 `0x5462ED` 比較 actor+0x3E8 是否 0：非 0 時走將 changed flag 設 1，等於 0 時於 `0x5462FD` 清除輸出 WORD 除 `0x8000` 外的 bits。這**不等於**已確認施放成功、取消窗口或 V 等級。

### 1.3 與輸入/方向後段相連之新控制器分支（已確認）
`0x546338`：`cmp byte ptr [0xFB9009],0`、`sete al`、`mov esi,eax`；其布林結果與 `actor+0x158` 的非空及 `+0x30` 非零、`0x4C9ED0` 結果共同決定是否進 `0x546374～0x54646F`。要注意 `0xFB9009=0xFB9004+5`，故是**一般鍵狀態陣列 index=5 的讀取**，**但 index=5 不等於 Z/X/C/V 任一 action 的證明**。`0x5463BB` 執行 `0x545F30`，`0x54642F` 執行 `0x5464C0`，`0x54644E` 執行 `0x4C90C0`；並出現 `controller+0x70/+0x74`、輸出 `WORD +2` bit15 的改寫。此鏈看似方向/位移相關，**不應未驗證當作技能 cancel**。

### 1.4 新找到之 writer 候選，保留型別邊界（已確認寫入；actor 身分未確認）
- `0x4CE90A～0x4CE914`：`movsx ecx, word ptr [ebp+0xC]`，`mov [ebx+0x3E8],ecx`，且 `eax=[ebx+0x364]`。`0x4CE945` 比較 `[ebx+0x3E8],1`。是真正 **非固定值寫入** 候選，**未證明 ebx 與 0x546100 的 edi 同類**；後續需要求證其函式入口、caller、vtable、RTTI 和物件配置。
- `0x4C71EF` 對 `[ebx+0x3E8]` 寫 `esi`，位於大量初始化 `+0x3C0～0x3E8` 之間，且隨後初始化 `+0x3F4` 容器；`esi` 需由函式序言溯源才可稱 zero init。
- `0x493227` 把指向 `0x4943B0` 的**程式碼地址**寫到 `[eax+0x3E8]`，與多處其他偏移的同類函式指標配置並列；不應解為 actor level 1/2。
- `0x68F3C7`、`0x839B0E`、`0x83A188`、`0x8C2540` 同樣寫 `+0x3E8`，但上下文涉及 loop 複製、container 初始化/重設或成段結構複製；**類型尚未關聯前排除作 actor writer 證據**。

### 1.5 全 `.text` 中直接基底+0x3E8 operand 掃描（已確認字面參照；非完整 alias analysis）
此純 operand 靜態清單**漏掉**經 setter、`lea`、memcpy 或暫存器加偏移間接操作，不能據此宣稱 writer 全部列舉：

[code block separately checked in preflight]

## 2. 核心控制器原生指令

### 2.1 角色選擇、輸入整合與 predicate
[code block separately checked in preflight]

### 2.2 `0xFB9009` 狀態 gate 及後段 dispatch
[code block separately checked in preflight]

### 2.3 writer 候選分離
**函式指標表（不應判為 actor state）**
[code block separately checked in preflight]
**另一個 `+0x3E8` 複合物件初始化/清空，身分待確認**
[code block separately checked in preflight]
**獨立容器重設的例子**
[code block separately checked in preflight]

## 3. 形式化部分資料流／偽碼
[code block separately checked in preflight]

## 4. 證據與推測邊界

| 問題 | 狀態 | 說明 |
|---|---|---|
| BIN 同版本及 PE section | 已確認 | 本次本地原檔 hash + objdump section 核對 |
| `0x546100` actor 指標來源 | 已確認 | `0x546137` / `0x546141～148` |
| actor+0x3E8 流入 `0x54F270` | 已確認 | `0x5462B4～0x5462DD` |
| `0x4CE914` 是可變 16-bit 寫入者 | 已確認 | 其 `ebx` 對象的欄位，非 actor 等價已驗 |
| `0x4CE914` 是玩家 actor 的 charge setter | 尚待驗證 | 缺 RTTI、caller、型別同一性、V action producer |
| `0xFB9009` 為 index5 狀態、影響後段 gate | 已確認 | 但映射到哪個行為仍未確認 |
| Z/X/C 可自訂鍵→動作 row→六組 flags | 尚待驗證 | fallback XML/action row、event writer 尚缺 |
| V tap/held/tier 來源與 Z 普攻替換 | 尚待驗證 | 不可把 SubAI 7/9 當 V level |
| 動作啟動→motion→queue→cancel→next action | 尚待驗證 | 需要跨模組 caller/callee 與寫入者 |

## 5. 後續追查順序（不為段號拆分析）
1. 從 `0x4CE90A` 所屬函式入口、call XREF、物件 constructor/vtable 找 `ebx` 的真實類型；和 `0x546100` 的 `edi` / `+0x158` 布局**逐欄比較**。
2. 沿 `0x6D08F0` 的 key map schema、fallback 與 `[0xFB9004+index]` 非零 writer 查 index5 對應行為；不可把 key index 當 VK 或玩家 action id。
3. 從 `0x545F30`、`0x5464C0`、`0x4C90C0` 追消費者，若僅方向/移動操作則與攻擊分流；再沿 `0x548D20`、`0x54AA60` 動作候選路線進行。
4. 同時核對原稿 T10-29～32 與 T11 的交界，不改他人資料。

## 6. 此段沒有得出的結論
- 沒有證明 `actor+0x3E8` 的有效全域值域或 V 等級，沒有證明 500ms / 60 tick 是連段／蓄氣時間。
- 沒有證明 4 tier 與 V 點按／長按的映射，也沒有證明 Z held 能自動續段或 cancel 行為。
- 目前屬於**T10-33 局部進展**，並非使用者要求的完整功能鏈終局。


---

# T10-33 補充深查（2026-10-27 22:09 Asia/Taipei）

> 此版本保留前述 T10-33 原稿全文並追加第一手證據與重要修正。原稿「局部進展」的判定仍有效：這次封閉了 `+0x3E8` setter 的分支選取與一條 vtable 入口，**並未取得 V 蓄氣／普攻技能互接完整閉環**。以下所有機器碼來自同 SHA256 的 `Tartaros.bin`、由函式入口重新 disassemble；未執行遊戲。

## 7. 重要新突破：actor-like `+0x3E8` 並非孤立的未知 writer

### 7.1 `0x4CE7F0` 是分派 30 種 selector 的原生函式

[code block separately checked in preflight]

跳轉表本地直接讀取原始位元組，PE `.text` 映射 `file_offset = VA - 0x401000 + 0x400`：

- `0x4CEB5C` 11-entry DWORD table 的第 3 號 index（從 0 起）為 `0x4CE90A`。
- `0x4CEB88` 30-byte selector-to-branch table：`index = selector-1`，其中 **index 4 = 3**，故 **selector 5** 進入 `0x4CE90A`。
- 這裡的 *selector 5* 是參數 `word [ebp+8]` 的協定/屬性編號，**不是 `[0xFB9004+5]` 的按鍵 index 5，更不是 VK_V**。前述 index 5 與此 selector 值相同屬巧合，證據鏈目前完全沒有連線。
- `value = (int16_t)[ebp+0xC]` sign-extend 為 DWORD，對 `this+0x3E8` 寫值，並於 value=1 有進一步的物件處理分支；不能由此直接推得值域恰好為 0/1/2。

**局部偽碼**：

[code block separately checked in preflight]

### 7.2 這條 setter 的宿主具有與玩家控制器 actor 相同的鄰接 layout（增強、但未嚴格完成身分證明）

`0x4CE797～0x4CE7BF`（上一函式）針對 `ebx` 使用 `+0x428 / +0x42C` 和 `+0x158`，並讀 `[ebx+0x158]+0x34`；`0x4CE7F0` 的 this 也是 `[ecx] -> ebx` 並使用 `+0x364` 與 `+0x3E8`；`0x546100` 的 `edi` 使用 `+0x158` 和 `+0x3E8`。此外 `0x4C7070` 建構函式樣式在 `0x4C70C4` 初始化 `+0x15C` 容器並在 `0x4C71EF` 初始化 `+0x3E8`。

[code block separately checked in preflight]

`0x4C7070` 早期於 `0x4C70BE` 明確 `xor esi,esi`，在沒有中途覆寫 `esi` 的情況下 `0x4C71EF` 是零初始化；但仍需跨該完整流程逐指令確認沒有別路變更，**不能以此當 V released reset 的證明**。這些布局線索將 writer 升級為「高關聯候選」，但缺少此 setter 的**物件實例指標與 `0x546100` 的 `edi` 等價的上游鏈**；不得寫成已嚴格證明同一類別。

### 7.3 setter 透過虛擬函式表掛載（新原生 xref）

對 PE raw bytes 搜尋 little-endian `0x004CE7F0` 得到 `file_offset 0x806170` 一筆。依 `.rdata` 映射 `VA 0xBD2000 ↔ raw 0x7D0600`，是 `0x00C07B70`；附近連續的函式指標：

[code block separately checked in preflight]

此為**可驗證的虛擬方法入口候選**。仍需確認 vtable 頭地址/RTTI，以免將表中的內部偏移當作 slot 0。直接 `call 0x4CE7F0` 在 `.text` 掃描中沒有命中，不代表它沒有被呼叫；**很可能需要沿 virtual dispatch 追 selector/value producer**。這也解釋先前只找 direct caller 為何找不到寫入上游。

## 8. 按鍵狀態與 setter selector 5 的反例

[code block separately checked in preflight]

這裡的普通鍵狀態查詢界限是索引 `0..39`，index 5 即 `0xFB9009`；目前只觀察到讀取與部分清零者，**未解析 action-to-key map、非零事件寫入者或 press/held/release phase**。由 selector 5 推導「V」或由 `0xFB9009` 推導「Z」都不成立。

## 9. 實質結果與缺口管理

| 目標 | 進展 | 結論級別 |
| --- | --- | --- |
| `+0x3E8` 非零可變寫入者 | 找到 `0x4CE7F0` selector 5 → `0x4CE90A/14`；value 來自第二個 WORD 參數 | **已確認局部機器碼** |
| setter 的 virtual xref | `.rdata` `0xC07B70` 指向 `0x4CE7F0` | **已確認指標；slot 類型待 RTTI** |
| constructor 類型關聯 | `0x4C7070` 初始化 `+0x3E8`，鄰接有共同 actor-like 欄位 | **合理推測同家族，未關閉 identity path** |
| 玩家輸入產生 selector=5 | 未取得從 Z/X/C/V mapping/event 到 virtual setter 的 callsite | **尚待驗證** |
| V tap/hold → 4-tier 技能選擇 | 未證明 | **尚待驗證** |
| Z held / combo / skill cancel / action queue | 未證明 | **尚待驗證** |

### 接續精確追查

1. 用 `0xC07B70` 所屬 vtable 的 ctor/vptr writer 鎖定 actor 類型和 virtual index，從所有 `call [vptr+offset]` 的上游回溯 `selector=5,value` 的生成者；尤其要驗證 selector 是否源於動畫/網路/腳本，而不是誤判為 V 鍵。
2. 繼續追 `0x6D08F0` XML row/action mapping 與鍵事件非零 writer，釐清 `[0xFB9009]` 是哪個動作。
3. 回到 `0x546100` 的 WORD+2 與 `0x54F270`、`0x548D20`/`0x54AA60`，把 movement branch 與攻擊、skill、motion/cancel queue 拆開並沿實際呼叫關係驗證。

**交付邊界：** 本段可視為「完成一個有原生證據的新 writer 及其分派入口研究主題」，**不可視為 T10 的 Z/X/C/V 與 V 蓄氣、普攻技能互接整條功能鏈已完成**。無 GitHub Commit、Push 或任何 Task 檔案修改。


## 10. T10-33 正式分析結論／結案判定

**研究主題已完成（不等於整體系統已完整還原）。** 原始 BIN 直接證實 `0x4CE7F0` 依 1..30 selector 進入 jump-table；selector=5 時，由 `0x4CE90A` 將第二個 signed WORD 參數擴展後於 `0x4CE914` 寫入接收物件 `+0x3E8`；若舊關聯 `+0x364` 存在，隨後執行清理；新值為 1 時另走特殊後續處理。原始 `.rdata` 中 `0xC07B70` 指向 dispatcher。`0x546100` 的玩家控制器亦讀取所選 actor `+0x3E8`，並在 `0x5462DD` 前傳入技能可用性檢查。

**證據保留界限：** 不能單由同 offset 判定控制器 actor 與 setter 物件完全同一型別；selector=5 絕不能與 `[0xFB9009]` 的鍵狀態 index 5 混同；更不能據此宣稱 V 點按／長按等級。缺少事件輸入到 selector/value、player actor instance identity、motion/queue/cancel 的證據。本段完成 writer/dispatch 主題的深入研究，後續由 T10-34 接續，不以未解缺口阻止結案。

**GitHub：未提交／未推送。**