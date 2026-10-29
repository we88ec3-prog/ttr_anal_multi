# KR T10-27 — 三按鍵組合旗標、四層技能矩陣與 V 蓄氣假說邊界

原始資料：`/mnt/data/Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）。研究日期：2026-10-27（Asia/Taipei）。

**方法**：唯讀 `objdump -D -Mintel --start-address=... --stop-address=...`，先核實完整函式的入口和跳轉邊界；未執行、注入或改寫客戶端。組語是 BIN 第一手證據；T10-24 與 GitHub T11 既有審核作交叉參考，不替代機器碼。未命名函式、物件欄位的語義均為候選。

**使用者補充（研究需求，非由 BIN 證明）**：按鍵可自訂；六種輸入 Z、X、C、Z+X、Z+C、X+C；V 點按／長按影響技能且包含 Z；普攻／技能有交互接續。研究不能將字母按鍵硬對映到 mask。

## 研究目標與本次範圍

專門驗證 `0x54F270` 的 flags→key 條件先後和 `0x81A8E0` 的 tier/key 索引，將使用者提到的六組 Z/X/C 與 V 變化轉成可驗證的候選矩陣模型，並明確指出目前無法證實的實際映射。

## 第一手組語摘錄

[code block separately checked in preflight]

## 逐層分析與新結論

**控制流程與優先序（直接指令）**：`0x54F277 test al,0xC0` 有任一高位就走 `0x54F325 return 1`；否則從低位依 `bit0&bit1→key4`、`bit0&bit2→key5`、`bit1&bit2→key6` 的優先順序檢查。若沒有兩位組合，檢查 bit0→key1、bit1→key2、bit2→key3，再查 bit3→key7、bit4→key10。不匹配亦走 return1。**此分類的 bit 是內部技能旗標，不是鍵盤 Z/X/C 的物理掃描碼**，要連到可自訂 KeyMapping 才能命名。

**關鍵陷阱：** 若三個低位同時為 1，函式首先命中 bit0+bit1（key4），不會「自動」出現第七種三鍵技能。若混合低位及 bit3/bit4，會先命中低位。在沒有更上游 normalizer 的證據前，只能把它解釋為優先序。`0xC0` return1 分支跳過矩陣，既不是技能發動成功，也不是 V 長按已成功；可能是特殊動作免檢查，需要 caller 驗證。

**矩陣第一手**：`0x81A8E3 cmp al,4`、`0x81A8E7 cmp cl,0xB`，超出直接回0；`0x81A8EC..FF` 以 `WORD [matrix + 4 + 2*(tier*11 + key)]` 取技能 ID。可見 4 tier × 11 keys 的索引形狀，**但 4 個 tier 代表何種遊戲狀態、是否全由 V 控制仍未知**。

**可驗證的假說矩陣**（內部 bit→實際按鍵尚待確認）：
| flags | key | 已證實 | 不得先下的結論 |
|---|---:|---|---|
| 0x1 | 1 | 單 bit | Z |
| 0x2 | 2 | 單 bit | X |
| 0x4 | 3 | 單 bit | C |
| 0x3 | 4 | 兩 bit | Z+X |
| 0x5 | 5 | 兩 bit | Z+C |
| 0x6 | 6 | 兩 bit | X+C |
| 0x8 | 7 | 特殊 bit | V 點按 |
| 0x10 | 10 | 特殊 bit | V 長按 |

**不同 tier 的同一 key** 確實可能得到不同 WORD skill ID，這是與蓄氣後技能變化相容的資料結構，但不是蓄氣導致 tier 改變的原始證據。

**冷卻／可用性邊界**：`0x54F2D5` 讀 object+2 model WORD，查 `0x40F7F0→0x819220→0x81A8E0`；有 skill ID 時 `0x54F310` 進入可能**插入節點**的 `0x54F4E0`，`0x54F317` 比較 node payload +4 是否為 0。這既不是資源扣除也不是 cooldown timer 寫入。

## 證據分級及限制

- **已確認**：上述精確地址及機器碼、可見的記憶體讀寫和條件分支。
- **合理假說**：上述流程可能與 T10／T11 通用技能層相關；只把適合的欄位列為候選，不預先認作玩家蓄氣或普攻。
- **尚未驗證**：V 按鍵來源、四 tier 的實際觸發條件、Z/X/C 各自的映射值、連按 vs 長按、動畫完結時的下一招消費、扣除資源與冷卻 writer。
- **協作**：僅新增個人 `kr-temp-roy/T10/` 的交界分析；正式 T11 owner/task.json 和其他 Agent 筆記不修改。

## 後續定向追查

沿 KeyMapping.xml 實際檔案尋找「實體鍵→動作 bit」，沿 `0x5462DD` 的 tier 引數 producer 尋找 V 事件對其的寫入；再分析 tier 進入動畫／施放 callback 前後的採樣時機。