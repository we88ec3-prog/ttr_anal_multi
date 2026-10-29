# T10-52 — input-controller-motion-boundary

- 時間：2026-10-28T01:49:00+08:00 (Asia/Taipei)
- 來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- PE .text: VA 0x401000 / raw 0x400；此處所有摘錄均由原始 bytes 唯讀反組譯，非 Ghidra 摘要。
- GitHub T01-20261027-05 語意接受範圍僅為部分確認；此筆記無法自動擴大為整函式 native 驗收。
- 原始目標未執行，未修改、未附加遊戲。

## 本段核心：整合輸入 consumer，區分正向證據與未連線的流程

### 已直接核對

- `0x5467A4: call 0x547240`，由返回值在 `0x5467AD..0x5467C5` 對 `ebx` OR `0x40/0x80/0x08`；`0x5467CD` 進入 `0x546850` 後另呼叫 `0x546B50`。這個 flag 轉換是直接 BIN 可驗證。
- `0x548957` 讀 `[esi+0xFB9004]`，並與立即數 `1` 比較；條件下方有 virtual `+0x10` 的呼叫，但 receiver 來自不同全域欄位，未證是角色 motion。
- `0x59624E/0x59643F` 呼叫 `0x6D4CE0`，隨後可見 `+0xEC/+0xF0` 多型檢查；這是兩條結構化 consumer，但仍欠缺對 `0x546780` 的同一實例／同一資料欄位連結。
- `0x6D4CAE` 只證 keyed clear；沒有找到與其配對的同一已確認非零 writer，不可把它命名為 keyup。

### 目前確定不能推出的原版遊戲規則

1. `0x547240` 嚴格 `>500ms` 不等於 Z combo/cancel window；AI `CHAIN_WINDOW=.65` 不是原版規則。
2. 指令索引 `28..37` 不是十段普攻連段。
3. SubAI `>60` 次計數不是玩家 V 長按秒數，候選 `7/9` 不等於 tier。
4. `+0xEC/+0xF0` 多型 predicate 尚未用接收者 vptr provenance 證明等於 attack/skill cancel。
5. 無證據證明與鍵碼相同的各容器就是同一物件。

### 下一段 T10-53 精準優先次序

1. 靜態反向搜尋非零 indexed writer：從事件分派、key input API callback、指標别名，先證實來源寄存器與 `0xFB9004`/特殊樹節點的同一性。
2. 用實際 `KeyMapping.xml` 或 fallback resource 完成 action-id→key-code→phase byte 的綁定。
3. 從 `0x546780` 的輸出 flag/command 的真實 dispatcher 追到 actor 方法及 motion 開始完成時序；記錄 queue producer/consumer 與 cancel gate 的真實物件類型。
4. 引用 T11 的施放資料，僅在同一實例被原始 bytes 證實時建立互相銜接路徑。

### 結案定義

這批完成「已核驗局部鏈＋阻塞點」而非完整玩家戰鬥規則。無仿造 Z/V 秒數、幀數、取消優先權、cooldown 或封包。

## 第一手反組譯片段

### VA `0x00546780` / raw `0x00145b80` (280 bytes)

[code block separately checked in preflight]
### VA `0x00548920` / raw `0x00147d20` (240 bytes)

[code block separately checked in preflight]
### VA `0x005961c0` / raw `0x001955c0` (265 bytes)

[code block separately checked in preflight]
### VA `0x006d4c60` / raw `0x002d4060` (110 bytes)

[code block separately checked in preflight]

## 可重現的呼叫掃描（原始 BIN）

- Direct E8 target `0x6d4ce0`：0x59624e, 0x59643f。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x6d4a30`：0x490dfc, 0x58a607。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x594610`：0x5cd91f, 0x5d1b75, 0x5d2dd5, 0x5d4045, 0x60e06b, 0x651122, 0x65117e, 0x6511da, 0x65120a。注意僅是 bytes 命中，不是全部可達路徑。

## 明確未解

- 自訂 action mapping 的實際 XML 資料與儲存 writer 尚未連上。
- 玩家 V 短按／長按、Z 長按自動續段、普通攻擊與技能前後銜接的 queue、cancel window 均尚無直接跨函式證據。
- 間接函式、物件類型與多執行緒事件來源應繼續按實例校驗，不可單憑相同 offset 或名稱視為相等。