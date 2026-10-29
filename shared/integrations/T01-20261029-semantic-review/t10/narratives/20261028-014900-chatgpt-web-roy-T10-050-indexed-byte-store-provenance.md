# T10-50 — indexed-byte-store-provenance

- 時間：2026-10-28T01:49:00+08:00 (Asia/Taipei)
- 來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- PE .text: VA 0x401000 / raw 0x400；此處所有摘錄均由原始 bytes 唯讀反組譯，非 Ghidra 摘要。
- GitHub T01-20261027-05 語意接受範圍僅為部分確認；此筆記無法自動擴大為整函式 native 驗收。
- 原始目標未執行，未修改、未附加遊戲。

## 本段核心：靜態位址引用的讀寫分類

BIN `.text` 掃描 little-endian `0x00FB9004` 立即數共 **7** 處命中：`0x54895A`、`0x6D0876`、`0x6D1B03`、`0x6D4A9D`、`0x6D4B6C`、`0x6D4CB0`、`0x6D4D9B`（均是即時值出現的位置，與指令起點可差 1–3 bytes）。

### 逐路分類

- `0x548957: movzx eax, byte ptr [esi+0xFB9004]`：**讀取**，緊接著 `cmp eax,1`。這只證 index 狀態 byte 是否等於 1，不證其是 keydown。
- `0x6D4D98: movzx eax,byte ptr [esi+0xFB9004]`：**讀取**；此前有 `esi<=0x27` 的範圍守衛。
- `0x6D1B00: xor eax,eax; 0x6D1B02: mov [0xFB9004],eax`，並連續清理後續 DWORD：**寫零**。
- `0x6D4CAE: mov byte ptr [esi+0xFB9004],0`：**indexed 寫零**；前段 `0x6D4C20` 用特殊鍵碼範圍比較選樹分支、`0x6D4C7C` 寫特殊節點 `+0x10=0`。此段對兩域都可見 reset/clear。
- `0x6D4A9C`、`0x6D4B6B`：初始化／重置清零，需結合完整前置 `xor eax,eax` 與可達上下文判斷；不視為事件 writer。
- `0x6D0875`：初始化片段內直接 DWORD 寫入，不能只憑地址 literal 判定為實時 input phase。

### 精確限制

命中數是**原始 `.text` 位元組對 4-byte literal 的出現次數**，不是 CFG 資料流覆蓋率，亦可能漏掉 pointer alias、relocation 表、base+displacement 拆開或間接位址，因此 **不能以「沒查到」證明不存在非零 writer**。下一步需要反向找對該全域陣列取地址的 routine 或 OS 事件轉換。

## 第一手反組譯片段

### VA `0x006d1ae1` / raw `0x002d0ee1` (90 bytes)

[code block separately checked in preflight]
### VA `0x006d4a90` / raw `0x002d3e90` (75 bytes)

[code block separately checked in preflight]
### VA `0x006d4c60` / raw `0x002d4060` (115 bytes)

[code block separately checked in preflight]
### VA `0x006d4d70` / raw `0x002d4170` (70 bytes)

[code block separately checked in preflight]
### VA `0x00548950` / raw `0x00147d50` (85 bytes)

[code block separately checked in preflight]
### VA `0x006d0820` / raw `0x002cfc20` (145 bytes)

[code block separately checked in preflight]

## 可重現的呼叫掃描（原始 BIN）

- Direct E8 target `0x6d4ce0`：0x59624e, 0x59643f。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x6d4a30`：0x490dfc, 0x58a607。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x594610`：0x5cd91f, 0x5d1b75, 0x5d2dd5, 0x5d4045, 0x60e06b, 0x651122, 0x65117e, 0x6511da, 0x65120a。注意僅是 bytes 命中，不是全部可達路徑。

## 明確未解

- 自訂 action mapping 的實際 XML 資料與儲存 writer 尚未連上。
- 玩家 V 短按／長按、Z 長按自動續段、普通攻擊與技能前後銜接的 queue、cancel window 均尚無直接跨函式證據。
- 間接函式、物件類型與多執行緒事件來源應繼續按實例校驗，不可單憑相同 offset 或名稱視為相等。