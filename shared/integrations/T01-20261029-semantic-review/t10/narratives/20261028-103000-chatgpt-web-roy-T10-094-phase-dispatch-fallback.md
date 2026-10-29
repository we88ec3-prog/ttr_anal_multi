# T10-094 — 0x5961C0 phase1／phase3 fallback 之非對稱性



- 證據來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本次重新驗算一致。
- 靜態唯讀，PE32 `.text` 映射 VA `0x401000`/raw `0x400`，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。不執行遊戲。
- 地址均為 KR VA；僅摘取已核對的指令窗口。證據分級：**確定**限機器碼所示；**待驗**不升格為遊戲規則。


## 本段新證據
`0x596267` 比對 phase==1，先向候選子物件的 vtable `+0xEC` 傳入 ID (`push edi`)；返回 `AL` 若為真，短路 this 事件，若為假經 `0x596140` 的條件 helper 後才可能呼叫 this vtable `+0xEC`。這是有序的 **handled / fallback** 路徑，而非保證每個按鍵觸發角色動作。

phase==3 在 `0x5962BC` 分支先向候選子物件的 `+0xF0` 傳 ID；回傳真寫局部 `[ebp-0xE]=1`，然後依旗標可能進入 this+0x80 的關聯節點查找 `0x82EF00`，在節點上的其他 listener 再各自呼叫 vtable `+0xF0`。這段具有多 listener 的通知語義，不能未驗證命名為連段佇列。

`0xFB73E8 != 0` 時的 13／14 ID 特例發生在讀 phase **之後**、vtable 處理之前，因此是此派送路徑的 gate；不代表映射表刪除 15、16，也不代表全局停用其他鍵。

**缺口**：vtable owner 與實際 overrides、`0x596140` helper 可否處理鍵 ID 的具體語義、原生角色 motion writer。


## BIN 指令證據（可依 VA 重現）

### 0x596245 .. 0x5962bc

[code block separately checked in preflight]

### 0x5962bc .. 0x596352

[code block separately checked in preflight]

## 研究誠信與範圍

保留確證與未知的界線；不執行、不修補遊戲；不更動他人 Task。
