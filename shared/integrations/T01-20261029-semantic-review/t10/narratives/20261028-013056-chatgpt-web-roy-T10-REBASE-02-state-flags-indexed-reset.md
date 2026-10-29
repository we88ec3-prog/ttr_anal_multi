# T10 REBASE-02 — 輸入狀態回傳旗標、索引清除與命令產生資料流

- 時間：2026-10-28T01:30:56.494136+08:00
- 來源：本機 `/mnt/data/Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，原始唯讀靜態分析；GNU objdump `-D -Mintel -b pei-i386 -m i386`。
- GitHub：繼承 REBASE-01 的 T01-20261027-05 限定接受邊界；本段 **沒有** commit、push、owner/catalog 變動。T10-1～44 尚未逐份完成 SHA reconciliation，不能稱全面 rebase。
- 新段號採 `REBASE-02`，不是未經基準重審的 `T10-45`。

## 核心新證據及分析

### A. `0x546780`：狀態機輸出轉換為 WORD bitmask，再合流三路輸入

1. `0x546791` 從 `[edi+0x5c]` 取 WORD 作為 `ebx` 既有旗標；`esi=edi+0x40`。`0x54678f` 取得來源 BYTE，複製到三個暫存位置。
2. `0x5467a4` 直接呼叫 `0x547240`；該函式按照 `esi` 的兩 DWORD state/tick 與全域 `[0xFB9014]` 做狀態轉換，當它回傳 **2、3、4**，caller 各自把 **`0x08`、`0x80`、`0x40`** OR 到 `ebx`。其他回傳值（0、1）不在這段設定上述位元。
3. `0x5467cc` 呼叫 `0x546850`，`0x5467e0` 呼叫 `0x546b50`，`0x5467ec` 呼叫 `0x546d50`。`0x5467f4` 將 WORD `bx` 寫至 `[ebp+0x10]` 指向的外部輸出；0x5467f7 後呈現路徑優先順序：`546850` 非零則選第一個 byte；否則 `546b50` 非零則選第二個 byte；否則依第三個結果走後續分支。各路 BOOL 結果使用 OR 合流，不能與 byte 選擇優先順序混淆。
4. **限制：** 僅知 machine-code 的 bitmask 生成，不可命名 `0x80=V 長按` 或 `0x08=普攻`；`edi+0x5c` 的結構來源、caller 實參、輸出消費者仍需逆追。

[code block separately checked in preflight]

### B. `0x6D4A30`：輸入索引清除 producer；不是非零 key-phase writer

1. 在 `[ebp+8]` BYTE 非零分支 (`0x6d4a93` 起)，`xor eax,eax` 後多次 `mov [0xFB9004..0xFB9028],eax`，每次是 DWORD zero；實際覆蓋連續 bytes，不應直接把這些位置都當獨立 action。
2. 在 BYTE 零分支，若 `[0xFB8830]` 非零，`0x6d4b69..0x6d4b98` 也執行同區域清除。
3. `0x6d4c20..0x6d4cb5` 遍歷傳入鏈表的節點 `[edi+8]`，比較 `esi - 0x2711` 與 `0x270E`，區分受管理 key/index 域。範圍外走 `0x6d4cae: mov byte ptr [esi+0xFB9004],0`；範圍內則查 `0xFDF630` 索引樹並清節點 `+0x10` BYTE。此為依 key domain 選擇不同清零位置，不能等同 nonzero writer。
4. **重要邊界：** index 來源取自鏈表資料，尚未與遊戲 action row 或 Z/X/C/V 直接綁定；`0x2711..0x4E1F` 的算術測試不代表真實可用鍵碼完整列表。

[code block separately checked in preflight]

### C. `0x6D4CE0`：一般與特殊鍵範圍的讀取介面

`0x6d4d05` 使用 `[esi - 0x2711] <= 0x270E` unsigned 範圍決定查 `0xFDF630` 索引樹並取 `node+0x10` BYTE，超出範圍時轉到 `0x6d4d70`，後續讀 `[esi+0xFB9004]`；與 `0x6d4a30` 的清除分流對應。尚未定位其所有 caller 如何提供 `esi`，所以不是全域玩家輸入 API 的完整證明。

[code block separately checked in preflight]

### D. `0x548918`：特殊索引 phase=1 生成命令的前次 BIN 證據交叉引用

`0x548957` 對 `[esi+0xFB9004]` 按 BYTE 讀取，`0x54895e` 只接受 1，`0x548985` 設命令 WORD=0x68；`0x5489a0` 從 `[0xFBA854]` 取得 receiver vtable+0x10，經 gate `[0xFBA798]==0` 後間接呼叫。索引初始化 28，最後處理至 37。此僅證明 phase consumer / conditional command producer，不證明 0x68 命令就是普攻或取消。

[code block separately checked in preflight]

## 已確認／推測／缺口

| 範圍 | 狀態 | 依據或限制 |
|---|---|---|
| `0x547240` 回傳值 2/3/4 對 bit 0x08/0x80/0x40 | BIN 直接確認 | `0x5467a4..0x5467c5` |
| `0x546780` 三路輸入合流與 byte 優先選擇 | BIN 局部確認 | `0x5467c8..0x546838`；尾段及上游需擴充 |
| `0x6d4a30` 清零 `[0xFB9004]` 索引狀態 | BIN 直接確認 | 多段 DWORD zero 與 indexed byte zero |
| `0x6d4ce0` 根據索引範圍選不同儲存結構查詢 | BIN 局部確認 | key identity / full caller 未閉合 |
| `0x548918` phase1 特殊命令 0x68 | BIN 局部確認 | 0x68 實際 server 協定、動作語義未閉合 |
| 正常鍵 down/held/release phase 非零 writer | 缺口 | 搜到的直接定址多為零；可能間接 / memcpy 寫入 |
| Z/X/C/V 的使用者自訂對照 | 玩家觀察＋研究缺口 | 找 `KeyMapping.xml` row / fallback / parser，不以 VK_Z 假定 |
| V tap/hold 與普攻交互影響 | 玩家觀察＋研究缺口 | 不將 500ms 或 SubAI >60 套為 V 蓄氣 |
| combo / cancel / motion completion / next-action queue | 缺口 | 不使用 0.65 秒替代規則 |

## 後續優先功能鏈（不切碎成補段）

1. 逆追 `0x546780` caller 及 `edi` 真實配置，確認 state/tick +0x40 和 bitmask +0x5c 的 actor/controller 所有權，以及輸出消費者。
2. 沿 `0x6d4ce0` 與 `0x6d4dc0` 事件路由尋找 **非零 byte phase writer**，尤其非立即定址的索引 store、物件 byte 寫入和 keyboard event dispatch。
3. 審核 `KeyMapping.xml` 字串參照、action row loader、fallback 對照，將實際自訂 Z/X/C/V action 與輸入陣列接起來。
4. 找 `0xFBA854` receiver 真正 vtable +0x10 實例和 `0x68` command 處理者，再追 action queue、動作開始／完成與 cancel，跨 T11 只記介面。
5. 將全 44 篇筆記 SHA 對照 `shared/source-review-status.json`，逐條接受有限整合結論與更正。若無逐檔驗證不得寫已完成。

## PE VA↔file raw

本段 `.text` VA = `0x401000` raw = `0x400`（BIN PE section header）。因此 raw = VA - `0x400C00`：`0x546780`→`0x145B80`；`0x6D4A30`→`0x2D3E30`；`0x6D4CE0`→`0x2D40E0`；`0x548918`→`0x147D18`。需注意之前其他 Task 所述 PE/flat 來源映射爭議不可直接套用到此個別核對。