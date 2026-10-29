# T10-093 — 0x6D4A30 初始化分支與事件容器實參



- 證據來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本次重新驗算一致。
- 靜態唯讀，PE32 `.text` 映射 VA `0x401000`/raw `0x400`，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。不執行遊戲。
- 地址均為 KR VA；僅摘取已核對的指令窗口。證據分級：**確定**限機器碼所示；**待驗**不升格為遊戲規則。


## 本段新證據
`0x490DFC` 呼叫前 `push 0xF95CD8` 與 `push [0xFAADFA]`；後者進入 `[ebp+8]` 的條件分支，前者為第二實參，並非按鍵事件 ID。`0x58A607` 則有不同的本地自鏈容器；同一函式可被不同初始化 owner 使用。`0x6D4A30` 的 `[ebp+8] != 0` 走 `0x6D4A68` 路徑，等於 0 走 `0x6D4B0A`。此分支影響初始化／重置先後，不能推斷為 key-down/key-up。

`0x6D4A93` 與 `0x6D4B69` 的 `xor eax,eax` 後連續寫入 `[0xFB9004..0xFB9028]` 十個 DWORD；這是 40 個普通 phase bytes 歸零，並非 phase 1／3 寫入。部分分支有 `0x6D0750`、`0x6D1DA0` lazy initialization guards（`0xFB7C14` 與 `0xFDF3EC` bit0）。由於初始化是有條件的，直接把它視作每次遊戲 frame 必然呼叫不成立。

**新限定結論**：reset 函式實參與兩個不同 caller 的存儲所有權不同；判定非零 writer 需要在上游事件 append / callback 查，而非把 reset 計為輸入生成。


## BIN 指令證據（可依 VA 重現）

### 0x490def .. 0x490e05

[code block separately checked in preflight]

### 0x58a5db .. 0x58a644

[code block separately checked in preflight]

### 0x6d4a58 .. 0x6d4af0

[code block separately checked in preflight]

### 0x6d4b0a .. 0x6d4bd0

[code block separately checked in preflight]

## 研究誠信與範圍

保留確證與未知的界線；不執行、不修補遊戲；不更動他人 Task。
