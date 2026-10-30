# KR T10-28 — T10／T11 交界：蓄氣改招及普攻／技能互接的證據矩陣

原始資料：`/mnt/data/Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）。研究日期：2026-10-27（Asia/Taipei）。

**方法**：唯讀 `objdump -D -Mintel --start-address=... --stop-address=...`，先核實完整函式的入口和跳轉邊界；未執行、注入或改寫客戶端。組語是 BIN 第一手證據；T10-24 與 GitHub T11 既有審核作交叉參考，不替代機器碼。未命名函式、物件欄位的語義均為候選。

**使用者補充（研究需求，非由 BIN 證明）**：按鍵可自訂；六種輸入 Z、X、C、Z+X、Z+C、X+C；V 點按／長按影響技能且包含 Z；普攻／技能有交互接續。研究不能將字母按鍵硬對映到 mask。

## 研究目標與本次範圍

統整本批對使用者新需求的影響；額外展開 `0x54A050` 對 4/5/6 狀態與候選目標的查詢，以區分 SubAI 技能狀態與玩家 charge 動作。明確列出「普攻→技能」「技能→普攻」「V 蓄氣後改招」尚缺哪一條完整邊。

## 第一手組語摘錄

[code block separately checked in preflight]

## 逐層分析與新結論

**獨立功能鏈 A — 通用動作可用性**：`0x546780` 合成輸入→`0x546100` 控制器處理→`0x54F270` flags + tier 驗證→`0x819220` 矩陣→`0x81A8E0` key/ID→`0x54F4E0` entry。已確認「輸入可用性 predicate」，沒有確認「動畫開始、技能扣藍、技能冷卻開始、接續窗口」。不能因普攻 Z 也屬技能就把這條當已經定位 combo 事件。

**獨立功能鏈 B — SubAI 目標／技能狀態**：`0x549D54` predicate 成功時寫 slot state 4；`0x549E10` 依幾何／目標資訊讀寫 state 1/2/3；`0x54A050` 認可 4、5、6 的 slot state，經全域 `0xFAB138` 樹以 slot+4 的候選 ID 找目標，再檢查 target+0x158/+0x34 的狀態與方向／距離。這是更多**與技能狀態關聯**的原版機器碼，但 state 4/5/6 不等於 V 三個蓄氣級別。

**通用配置與 V**：`0x6D08F0` 從 `Table/KeyMapping.xml` 讀入 KeyMapping、DefaultType、Type、Key；`0x6D0A23 cmp esi,3` 限制三組銀行的 index，載入每組 key row 的 16-byte slot。不同設定 Bank 並非自動等於三段蓄氣。用户能改按鍵意味著任何以 ASCII 0x5A 去找 Z skill ID 的方法都不可靠。

**四個必須閉環的銜接問題**：
1. Z 連按續普攻：要找 action pressed edge 進入 motion queue 與前段動作完成的 read。
2. Z held 續普攻：要找按住 state 的持續 writer／sampler；同一 action 是否在 motion window 再次消費。
3. 普攻→技能：要找初始普攻的 motion state/phase，轉向新的 skill key/tier 的 accept/cancel gate；只看到 availability 不能證明取消。
4. 技能→普攻：要找技能 motion completion 的 state reset 及 Z action 再許可；避免混同 SubAI 的 target reset。
5. V 點按 vs 長按及蓄氣改招：要找實際 V 訊息在 KeyMapping 的動作索引，以及兩種操作更改哪個 `tier` / queue field 的機器碼。

**本批跨 T11 候選整理（不更動其 owner）**：確立 skill availability=`0x54F270`；skill ID matrix=`0x819220/0x81A8E0`；存取/插入=`0x54F4E0`；SubAI state writer=`0x549D7D`、`0x549E76/0x549EAA/0x54A022`；SubAI 4/5/6 consumer=`0x54A050`；必須分開於玩家輸入事件分發=`0x5961C0`。

**追查順序優化**：與其繼續單純掃 FB9014，應以動作 ID→客戶端 motion 控制器→動作完成通知→下一段 accept 反推，再向 KeyMapping 映射回溯 Z/X/C/V。

## 證據分級及限制

- **已確認**：上述精確地址及機器碼、可見的記憶體讀寫和條件分支。
- **合理假說**：上述流程可能與 T10／T11 通用技能層相關；只把適合的欄位列為候選，不預先認作玩家蓄氣或普攻。
- **尚未驗證**：V 按鍵來源、四 tier 的實際觸發條件、Z/X/C 各自的映射值、連按 vs 長按、動畫完結時的下一招消費、扣除資源與冷卻 writer。
- **協作**：僅新增個人 `kr-temp-roy/T10/` 的交界分析；正式 T11 owner/task.json 和其他 Agent 筆記不修改。

## 後續定向追查

下一組 T10-29～32：查 `0x54A050` 的 caller/vtable 與 4/5/6 writer；查 `0x546100` 的 motion 入列 consumer、`0x54F270` 非零冷卻 writer、`0x6D4CE0` 正常非零鍵盤 state producer。取得真正 KeyMapping.xml 前不得命名按鍵 bit。