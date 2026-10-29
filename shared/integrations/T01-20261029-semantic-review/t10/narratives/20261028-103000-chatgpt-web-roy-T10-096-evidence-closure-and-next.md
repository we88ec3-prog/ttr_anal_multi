# T10-096 — T10-89～96 功能鏈矩陣與 producer 缺口再定位



- 證據來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本次重新驗算一致。
- 靜態唯讀，PE32 `.text` 映射 VA `0x401000`/raw `0x400`，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。不執行遊戲。
- 地址均為 KR VA；僅摘取已核對的指令窗口。證據分級：**確定**限機器碼所示；**待驗**不升格為遊戲規則。


## 本段交叉驗證結論
| 分段 | 已確認事項 | 尚未確認事項 |
|---|---|---|
| 配置 | 原始 KeyMapping Type0 的 MapButton13～16=Key44..47；三 bank 與工作 bank2 | 自訂檔 writer、實際玩家模式、scan-code producer |
| phase | `[0xFB9004+ID]` reader；`0x6D4A30` 多路清零 | 寫入 phase=1/3 的非零 producer |
| dispatch | `0x5961C0` 依狀態分派候選子物件和 listener 的 +0xEC/+0xF0 | 動作 override/vtable owner 及 motion/queue |
| mode | `0xFB73E8` gate；`0x5A55E0` mode，`0x5A5760/0x5A57A0` 選子物件並派發 | 非零 gate writer、+0xB4 implementer、狀態業務語義 |

### T10-97 優先方案
1. 定位 `0x5961C0` 真正 vptr 及 +0xEC / +0xF0 / +0xB4 覆寫地址，查 vtable 在 `.rdata` 的實際物件與生命週期。
2. 逆追 `0x490DFC`、`0x58A607` 上游事件 append/producer；不要再將 reset 當非零 writer。
3. 對 `[0xFB9004+ID]` 的 alias-based stores 使用 register-def/use 或局部資料流掃描；絕對位址負結果不足以排除。
4. 對 `0xFB73E8` 按 base+offset 別名查來源，確定是否與角色／ UI 模式相關。
5. 連接真正 motion/queue/cancel 前，不把 XML MapButton13～16 硬命名為攻擊技能，也不採 AI `CHAIN_WINDOW=0.65`、>500ms 等替代。

### 證據限制
本段新增局部實作路由，但沒有找到 phase 非零 writer、完整角色 motion 或 native combo 時窗。原始檔不提交 GitHub；其他 Task 的主責範圍不修改。


## BIN 指令證據（可依 VA 重現）

### 0x6d4d8e .. 0x6d4da3

[code block separately checked in preflight]

### 0x596245 .. 0x5962b9

[code block separately checked in preflight]

### 0x5a5760 .. 0x5a57d0

[code block separately checked in preflight]

## 研究誠信與範圍

保留確證與未知的界線；不執行、不修補遊戲；不更動他人 Task。
