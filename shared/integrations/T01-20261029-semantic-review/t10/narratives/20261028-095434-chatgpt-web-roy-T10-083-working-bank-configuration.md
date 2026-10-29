# T10-083 — KR KeyMapping 工作 bank 與外部設定回填（BIN-first）

- 研究日期：2026-10-28 Asia/Taipei；靜態唯讀。
- KR BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本地重新驗證一致。
- 對應 PE .text VA 0x401000 / raw 0x400，objdump binary adjustment 0x400C00。交叉引用 T10-081/082、T01-20261028-06。

## 1. 三組 0x280 bank 的實際用途

已確認 `0x6D0750` 透過 `0x892003` 建立三組元素長度 `0x280` 的 bank，基址 `0xFB8834`、`0xFB8AB4`、`0xFB8D34`。`0x6D1A70` 將 `mode*0x280` 加到基址，並更新 `[0xFB902C]`、`[0xFB9030]`。第三組是工作 bank，不等於 XML 中存在 Type2。

`0x4A1440` 只接受參數 0/1，從所選基本 bank 複製到 bank2。BIN x86：

[code block separately checked in preflight]

`0x6D1BE0` 的首參數 `[ebp+8]`、次參數 `[ebp+0xC]` 為兩個 0x280 bank 首址；其以 0x10 大小 slot 的 vector begin/end/capacity 逐欄複製和分配，而不是簡單 raw-memory memcpy。因此 bank 內 pointer 不能直接視為鍵碼或技能 ID。

## 2. 外部資料回填 bank2 的原生鏈

當 `[0xFB91E9]==2` 時由初始化函式 `0x6D0750` 的 `0x6D0803` 呼叫 `0x6D0D10`。已直接核對：

[code block separately checked in preflight]

兩個整數配對的第一個指定 bank2 slot (乘16)，第二個放入該 slot 的 DWORD vector；`0x6D0DFB..0x6D0E31` 還有 alias/搬移判定，所以不能把整個路徑簡化為單一無條件 push_back。尚未從 `0xBED1E0`/`0xC408D8`/`0xC408E8` 和 `0x891892` 嚴格還原來源設定檔名、編碼與保存 writer，也未取得任何玩家的實際配置，故僅能證明存在外部設定資料回填，不可擅稱完整存檔規格。

## 3. 已確認、待驗與反證

已確認 XML Type0 的 MapButton13..16 分配 Key44..47；Type1 的 MapButton13..16 另分配 Key36..39，並非缺這些 MapButton。Type1 *基本表* 不直接列 Key45/ModKey0，但 Extra Type1 的 Key45/ModKey29 對應高 ID 10509；工作 bank2 亦有其他內容來源，故尚不能判定 X 無效或確定 fallback。

**已確認**：三 bank，0/1→bank2 複製，以及外部資料→bank2 逐 slot 配對回填。
**部分確認**：外部資料可能為使用者鍵位設定（功能線索），仍缺檔名／保存鏈。
**待驗**：`0x4A1440` 於 `0xFE17B0` 註冊後的 callback、設定 UI 寫回、`0xFB902C` 實際讀鍵 producer、Key45 fallback、動作執行者。

沒有確認 Z/X/C/V 的戰鬥動作意義、連段或取消窗口；`CHAIN_WINDOW=0.65` 為 AI 替代。
