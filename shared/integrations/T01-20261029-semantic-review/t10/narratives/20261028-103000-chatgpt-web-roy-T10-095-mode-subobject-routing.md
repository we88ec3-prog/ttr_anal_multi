# T10-095 — 0x5A5760/0x5A57A0 mode 子物件路由



- 證據來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本次重新驗算一致。
- 靜態唯讀，PE32 `.text` 映射 VA `0x401000`/raw `0x400`，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。不執行遊戲。
- 地址均為 KR VA；僅摘取已核對的指令窗口。證據分級：**確定**限機器碼所示；**待驗**不升格為遊戲規則。


## 本段新證據
先前 `0x5A4614` 讀取 `0xFB73E8`，並在變化時呼叫 `0x5A55E0` 寫 `[owner+0x158]` mode。本次沿下游直接驗證 `0x5A5760` 的 `mode-1`、`mode-2` 分支：mode1 選 `[owner+0x140]`，mode2 選 `[owner+0x148]`，其他數值提前返回；針對該子物件把 `+8/+0x10` 與 `+0xC/+0x14` 作偏差調整，隨後呼叫 `0x746F70`。不能未核對其類型就命名為動畫插值。

`0x5A57A0` 用同一選擇規則，選中物件後取得 vptr，傳入 EDX 参数並呼叫 vtable `+0xB4`；mode 不是 1/2 則直接返回。`0x5A464A mov edx,0x66` 接 `0x5A57A0` 代表向選定子物件發送整數 `0x66`，**並不**證明這個數值是普通攻擊、施放或取消 opcode。

**新增已閉合局部鏈**：`[owner+0x158]` mode → mode1/2 子物件選擇 → vtable+0xB4。**未閉合**：vptr 具體值、+0xB4 implementer、角色 controller/motion、mode writer 的外部事件來源。


## BIN 指令證據（可依 VA 重現）

### 0x5a4614 .. 0x5a4670

[code block separately checked in preflight]

### 0x5a5760 .. 0x5a579b

[code block separately checked in preflight]

### 0x5a57a0 .. 0x5a57d0

[code block separately checked in preflight]

## 研究誠信與範圍

保留確證與未知的界線；不執行、不修補遊戲；不更動他人 Task。
