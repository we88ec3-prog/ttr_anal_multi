# KR T10/T11 交界研究 — T10-23 四個技能 availability 呼叫者比較

- 日期：2026-10-27 Asia/Taipei
- 證據：原始 Tartaros.bin，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 方式：BIN 唯讀 objdump i386，.text VA 0x401000／raw 0x400，位址均為 VA
- 任務隔離：T10 主導攻擊輸入與連接；技能計時、消耗、施放裁決的 T11 邊界以引用／候選標記，不擅改 T11 task.json 或別人的分析
- 不執行目標、不修改遊戲檔案、不將本地替代連段窗口視為原版值

## 交叉參照
既有 GitHub T11 audit 限定四個直接 E8 call site：`0x5462DD`、`0x54827F`、`0x549C0E`、`0x549D54`。本段直接從本地 BIN 擷取四個位置附近，以 caller-specific 實參來源與 return 消費進行比較。

- `0x5462DD`：控制器取得 `0x546780` 輸入後，用 actor+0x3E8、矩陣索引與局部旗標做判斷；回傳非零寫堆疊 local flag。
- `0x54827F`：在角色狀態 `+0x158` 和 `0x4C9ED0` 閘控後，從另一筆 output word 的低 15 位組裝 flag，查 availability；返回非零則設 local flag。與 `0x5462DD` 是兩個不同 control paths，**不能因共用 callee 就稱為普攻接技能**。
- `0x549C0E`：既有 `SubAI` condition 相關路徑，呼叫前有 actor+0x3C8/+0x3CC/+0x3D0 資源或限制判斷；返回非零繼續測 `[ebp+0x14]` 及 actor+0x3E8，比純輸入合成多了一層語意 gate。
- `0x549D54`：另一條 condition 相關路徑，返回非零後會更新 object+0x72 的 WORD 及 `object + (object+0x108)*16 + 0xAC` 中 DWORD 為 4；這是確實**寫入暫定狀態欄位**的證據，但無法由該常數單獨判定為 cooldown、連段段數或取消窗口。

## 更正與分工
先前 T10 研究觸及 `0x54F270`，應將它在 T11 追蹤清單中標為「已有 partial validated callsites」；T10 不複製冷卻／消耗核心所有權。普攻與技能有交會路徑，不表示同一招式分類，也未核實兩招連接時接受次序。

## 下一段
T10-24 提出以 actor motion state / action queues 為核心的交會驗證框架，避免一直在 UI 或 matrix lookup 迴圈中打轉。

## 附錄：原始 BIN 位址範圍反組譯摘錄

### VA 0054823D..00548293
[code block separately checked in preflight]

### VA 00549BD8..00549C39
[code block separately checked in preflight]

### VA 00549D29..00549D90
[code block separately checked in preflight]