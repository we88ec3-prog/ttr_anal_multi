# T10-51 — keymap-vs-phase-domain

- 時間：2026-10-28T01:49:00+08:00 (Asia/Taipei)
- 來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- PE .text: VA 0x401000 / raw 0x400；此處所有摘錄均由原始 bytes 唯讀反組譯，非 Ghidra 摘要。
- GitHub T01-20261027-05 語意接受範圍僅為部分確認；此筆記無法自動擴大為整函式 native 驗收。
- 原始目標未執行，未修改、未附加遊戲。

## 本段核心：key mapping 結果與 phase 消費不是同型別

- `.text` 直接 `E8`→`0x6D4DC0` 有 **29** 處候選呼叫：集中 `0x5946xx..0x5959xx`，另在 `0x5CD68A / 0x5CE5BA / 0x62B5BA / 0x650E96..0x6510A4`；**caller 數不等於 action row 數**。
- `0x5CD91F` 直接呼叫 `0x594610`；`0x5CD90A` 先從全域指標表 `[ebx*4+0xF832F0]` 取得參數；緊接 `0x5CD924` 檢查局部 byte 與 `0x5CD930` 的 `al<0x0B` 守衛。`0x5CD937: imul ecx,ecx,0xB`，`0x5CD943: add ecx,edx`，`0x5CD943` 後採 `[eax+ecx*2+4]` 讀 WORD；這是矩陣式索引的正向局部證據，不能直接命名成技能/普攻 tier。
- `0x596390..0x5964C0` 可見特殊鍵域迭代讀取鍵碼、呼叫 `0x6D4CE0` 與多型 `+0xEC/+0xF0` predicate。這個流程**沒有因同樣使用鍵碼**而自動等於 `0x5CD91F` 的映射矩陣或玩家 controller。
- `0x6D4C7C` 對特殊鍵樹節點 `+0x10` 寫零；這和 `0x5CD943` 取 WORD 是不同容器/單位。

## 交叉模組界線

T10 管輸入與 combo/cancel；T11 主責 cooldown/cost/cast。若 `0x5CD9xx` 屬技能資料生產鏈，這裡只記錄輸入到資料表示的介面，並不擅自併入 T10 主責。

## 後續最小閉合試驗

需要相同版本的 `KeyMapping.xml`/fallback row、實際 action id 與 `0x6D4DC0` 回傳項值，才可建立 Z/X/C/V 的映射表。目前無此原始資料直接連接，保持缺口。

## 第一手反組譯片段

### VA `0x00594610` / raw `0x00193a10` (920 bytes)

[code block separately checked in preflight]
### VA `0x005cd8b0` / raw `0x001cccb0` (320 bytes)

[code block separately checked in preflight]
### VA `0x00596390` / raw `0x00195790` (570 bytes)

[code block separately checked in preflight]
### VA `0x006d4c06` / raw `0x002d4006` (200 bytes)

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