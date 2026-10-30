# KR T10-6 — 映射樹資料取得與靜態初始化邊界

紀錄日期：2026-10-27T19:11:40+08:00

## 0. 來源與限制
- 研究對象：韓版 KR T10「普通攻擊與連段」，使用者指出 Z 連按、Z 按住不放兩種操作。
- 原始檔 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；僅唯讀，PE `.text` VA `0x00401000` 對映檔案 raw `0x400`；GNU objdump `-b binary -mi386 -Mintel --adjust-vma`。**所有位址為 VA，函式名稱除符號佐證者均為暫定。**
- 已有 T10-1～T10-4 原稿作背景；本段新增事項皆以本次 raw BIN 讀取核對。未啟動／附加遊戲或修改任何原始資料。
- 原生證據只證明目前觀察到的機器碼與資料流；不可反推出 Z 對應 bit、實際連段時間、是否可玩。

## 1. 分析與證據
本段剖析上段查詢使用的 `0x6D43F0`，並確認 `0x6D1DA0` 並非每次按鍵觸發的「長按狀態更新」。

**樹查找**：`0x6D441A` 取 `[ebp+8]` 為被查容器，`0x6D4420` 取得樹 root；`0x6D4427` 讀節點 `+0x21` 哨兵標誌，循環在 `0x6D4430` 比較查詢 key `[edi]` 與 node `+0x0C`，沿 child 指標尋找 lower_bound 類候選。`0x6D4443～0x6D444F` 依找到與否決定進入建立路徑。`0x6D446E` 呼叫 `0x4FCAE0`，`0x6D447F` 呼叫 `0x6D48A0`（具容器變更副作用的候選）。其返回 `lea eax,[esi+0x10]` 指向**節點內欄位**，並非直接回傳單一 bool。

**初始化**：`0x6D1DA0` 對 `0xFDF3F4` 為起點的 16-byte 項目進行建構，傳入項目大小 `0x10`、數量 `3`，配置 `0x0C`、`0x18` 的容器管理記錄並初始化多組全域位址，相關地址為 `0xFDF624/0xFDF634/0xFDF644/0xFDF654`。這是初始化大型資料系統的局部證據，**不能宣稱它代表某個按鍵被按住**。

**暫定 C++ 邊界**：
[code block separately checked in preflight]

**重要區隔**：`0x6D43F0` 的節點比較、插入與 `0x54F4E0` 舊研究中的另一套樹不能只因 offset 相似即合併成同一資料型別。`0x6D1DA0` 的值是結構初始化，不是 500ms 計時器。所有推測以不同呼叫者與物件指標來源重新核對。

**證據分級**：確定＝節點哨兵、key 比較、`0xFDF3F4` 陣列建構、配置大小；合理推測＝map get-or-insert；未確認＝完整 key/value 類別、插入後內容來源、與 Z 事件語義。

**T10-7 接續方向**：轉回 runtime 控制器 `0x546780`，重建各輸入來源合併時的優先順序與 Word/Byte 位置。


## 2. 原始 BIN 組語摘錄（逐址重新反組譯）
### 0x6D43F0 的樹查找與可能插入 (VA `0x006D4418`)
[code block separately checked in preflight]

### 0x6D1DA0 建構輸入映射容器 (VA `0x006D1DC8`)
[code block separately checked in preflight]

### 映射查詢時的 call-site (VA `0x006D4E27`)
[code block separately checked in preflight]