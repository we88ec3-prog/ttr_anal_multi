# T10-32 — 蓄氣、技能矩陣、普攻互接的已證實資料鏈與缺口歸檔

## 本段目標
整合 T10-29～31 與前段 T10-1～28，建立日後可交給 T11 的**精確證據路徑**，清楚區分玩家輸入、角色狀態、SubAI 目標候選、矩陣索引與真正動作／取消判定；不把跨路徑重用的偏移當成同一個物件。

## 新的技術整理（BIN 原生證據）
(1) `0x54ADC0` 的 actor+0x3E8 和 condition+0x4 做相等比較，actor 缺失視為 0。這是能檢查 actor 目前某技能狀態的 condition-like predicate。
(2) `0x5490FB..0x549141` 同 actor 狀態 1/2 控制多次更新計數並選擇 7/9，**有能力隨狀態改變候選**，但屬 SubAI target/skill 流程；次數 0x3C 不等於 60ms 或 60 frames 的已確認時間。
(3) `0x549C60` 的 sentinel -1 從 actor+0x3E8 補值後呼叫 `0x54F270`。這是在 SubAI 技能決策入口與可用性 gate 之間目前最具體的 actor state 傳遞證據。
(4) `0x546100`、`0x54827F` 從角色狀態取得樣本再呼叫 `0x54F270`，同時還有方向、actor active flag 及 controller 節點等守門，不能直接把 `0x54F270` 的 return 1 命名為「動畫取消成功」。
(5) `0x54F270 → 0x819220 → 0x81A8E0` 的 4 tier × 11 key 矩陣回傳技能 ID 並查 cooldown/availability entry，但只是**候選技能是否可用**，未證明如何啟動施放、扣能量、動畫與 server-cast command。

## 典型第一手交叉指令

研究日期：2026-10-27 Asia/Taipei。原始 KR `Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）；唯讀 GNU objdump -Mintel，VA 使用原 PE image base。原件未執行、修改或動態附加。此稿的「函式／物件語義」若沒有 RTTI 標示，僅是可閱讀的暫名。

### VA 0x0054ADC0–0x0054ADE0
[code block separately checked in preflight]

### VA 0x005490FB–0x00549145
[code block separately checked in preflight]

### VA 0x00549D29–0x00549D89
[code block separately checked in preflight]

### VA 0x005462B0–0x00546307
[code block separately checked in preflight]

### VA 0x0081A8E0–0x0081A909
[code block separately checked in preflight]

## 按鍵／施放四個核心假說的驗證矩陣
| 行為（使用者回報） | 目前 BIN 支援的邊 | 阻塞證據 |
|---|---|---|
| 可自訂的普攻輸入 | KeyMapping.xml loader 與三 Bank 已有證據 | 實際 XML、預設 Z 對應 action、按鍵 event writer |
| 六種 Z/X/C 單雙組合技能 | 0x54F270 接受 1/2/4 和 3/5/6 flags | 實際操作對應 flags；不同角色的 matrix rows |
| V 點按與長按導致改招 | 角色狀態被採樣並影響 skill availability；SubAI state 1/2 決定候選參數 | V 行動的 KeyMapping、held/edge 判定、寫入 actor+0x3E8 者與 tier 的關係 |
| 普攻→技能、技能→普攻以及連段 | actor availability、控制器輸入 mask 與候選篩選 | motion playback state、動畫完成 callback、next-action queue、取消 gate、server authoritative decision |

## 下一段 T10-33 / T11 關聯任務
- 第一優先：透過 actor 類別 RTTI/vtable 與已知 constructor 查 `[actor+0x3E8]` 的**非零寫入者**，分析設定值變更時機。不可只搜尋固定絕對地址。
- 第二：展開 `0x548D20`、`0x54AA60`，將 `7/9` 的真實轉換與 `0x54F270` AL flags 串起來，避免把參數當 key。
- 第三：查 `0x546100` 在技能 availability 返回後的 actor motion consumer／S2C 回饋，尋找動畫取消、蓄氣後技能與普通攻擊的共同狀態機。
- 第四：取得本機原版 `Table/KeyMapping.xml`，對可自訂 Z/X/C/V 做 mapping-first 證據。

## 限制／協作
T10 主責普攻連段與技能互接；上述 SubAI 技能可用性只作 T11 標記，不覆寫 T11 task.json／owner、不將 AI 動作直接視為玩家輸入。原件唯讀，無客戶端修補。所有未知語義保留在此稿。
