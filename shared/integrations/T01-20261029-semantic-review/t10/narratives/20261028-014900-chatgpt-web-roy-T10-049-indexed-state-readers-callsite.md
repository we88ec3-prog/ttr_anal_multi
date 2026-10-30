# T10-49 — indexed-state-readers-callsite

- 時間：2026-10-28T01:49:00+08:00 (Asia/Taipei)
- 來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- PE .text: VA 0x401000 / raw 0x400；此處所有摘錄均由原始 bytes 唯讀反組譯，非 Ghidra 摘要。
- GitHub T01-20261027-05 語意接受範圍僅為部分確認；此筆記無法自動擴大為整函式 native 驗收。
- 原始目標未執行，未修改、未附加遊戲。

## 本段核心：reader 的上游接點

1. **原始 BIN**：`0x6D4CE0` 在 `.text` 中找出 2 處可直接解成相對 `E8` 呼叫的候選：`0x59624E` 和 `0x59643F`，兩者均位於 `0x5961C0` 相關流程。逐條指令需視呼叫 ABI 與前置 register 的可達性確定。
2. `0x5961ED → 0x761010` 給出一個物件，`0x596201` 讀 `+0x28` 後右移 13 位測試旗標；`0x59624E` 對一般索引讀狀態後，有 `0x596273` 的 vtable `+0xEC` 間接呼叫。這裡是額外的 input filter，而不是已證明 action/motion writer。
3. `0x5963C7/0x5963F9` 讀特殊鍵域樹頭 `0xFDF624`，`0x596419` 按 `0x2AF9..0x2AFA` 作條件排除；`0x59643F` 再查同一鍵域 reader，並在 `0x596454` 執行另一個 vtable `+0xEC`。
4. `0x5964B5` 可見 vtable `+0xF0` 的迭代判斷：其 receiver 從容器節點 `+0x8` 取得，不能與上一步 `+0xEC` receiver 直接視為相同類別。

## 本段界線

兩個直接 call 都被確認，**但尚未將 `0x5961C0` 證成玩家戰鬥 controller**；`0x2AF9..0x2AFA` 是比較常數而不是已經命名的 Z/V。非零狀態 writer、鍵碼→action 對應、動畫 queue 都未閉合。

## 下一段銜接

以 `0xFB9004` 地址引用分類零值／非零值寫入，找出每幀或事件推進狀態之間接指標來源。

## 第一手反組譯片段

### VA `0x005961c0` / raw `0x001955c0` (940 bytes)

[code block separately checked in preflight]
### VA `0x00596390` / raw `0x00195790` (590 bytes)

[code block separately checked in preflight]
### VA `0x006d4ce0` / raw `0x002d40e0` (214 bytes)

[code block separately checked in preflight]

## 可重現的呼叫掃描（原始 BIN）

- Direct E8 target `0x6d4ce0`：0x59624e, 0x59643f。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x6d4dc0`：0x594672, 0x5946cb, 0x59471b, 0x5947fd, 0x59484d, 0x59492f, 0x59497f, 0x594cd4, 0x594dc4, 0x594eb4, 0x594fa4, 0x595094, 0x595184, 0x595274, 0x595364, 0x595454, 0x595544, 0x595634, 0x595724, 0x595814, 0x595901, 0x5959f4, 0x5cd68a, 0x5ce5ba, 0x62b5ba, 0x650e96, 0x650f48, 0x650ff6, 0x6510a4。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x594610`：0x5cd91f, 0x5d1b75, 0x5d2dd5, 0x5d4045, 0x60e06b, 0x651122, 0x65117e, 0x6511da, 0x65120a。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x546780`：0x546263。注意僅是 bytes 命中，不是全部可達路徑。

## 明確未解

- 自訂 action mapping 的實際 XML 資料與儲存 writer 尚未連上。
- 玩家 V 短按／長按、Z 長按自動續段、普通攻擊與技能前後銜接的 queue、cancel window 均尚無直接跨函式證據。
- 間接函式、物件類型與多執行緒事件來源應繼續按實例校驗，不可單憑相同 offset 或名稱視為相等。