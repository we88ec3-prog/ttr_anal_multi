# KR T10-16 — 輸入鏈整合、反證與 Z 續段缺口

來源：KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；.text VA 0x401000/raw 0x400；2026-10-27 Asia/Taipei。BIN 唯讀靜態反組譯，不執行遊戲。函式語義與 C++ 名稱均暫定。以下為可獨立理解的技術筆記；更長的逐址組語另在同名本地原稿。

## 本批完整邊界
1. 0x6D4C20 與 0x6D4CE0：擴展鍵值採 0xFDF630 樹，普通鍵值採 FB9004+index，已找到清零、讀值，但尚未定位 keyevent 非零 writer。
2. 0x59624E、0x59643F：0x6D4CE0 的直接 caller，依返回值 1 或 3 分流虛函式和本機容器查找；不能預先翻譯成 Z pressed/held/release。
3. 0x54883A～0x548883：四個不同狀態 byte 的測試，使用 0x50C640 選 slot、打包 0x22，再由 0x50CAC0 呼叫 sender；尚非普攻連擊的確證。
4. T10-1 以來 0x547240→0x546780→0x546100 的 input mask 路徑存在，但尚不能僅憑共用狀態地址區域就宣稱與上述多鍵事件屬同一條 Z 續段流程。

### 不可過度推論
FB9015～18 不代表「普攻四段」；狀態值 1/3 尚無正式 keydown/keyup 意義；0x22 非已確認普攻命令；500ms timeGetTime 不是已確認取消窗。本機自製的 CHAIN_WINDOW=0.65 亦不得套用原版。

### 後續 T10-17（具體檢查）
- 向 0x5961C0 / 0x5963xx 上游追 input polling callback，特別找 FB9004+index 寫入非零值的語句。
- 取得真實 Table/KeyMapping.xml，將 Z 鍵碼映射到 action row，連回相位函式。
- 從 actor motion completion/cancel consumer 反向找 next attack trigger，分辨 Z 多次按下與 held auto-repeat。
- 交叉引用 T02 封包送出及 T12 傷害範圍，但不重複命名其他任務核心方法。

### 驗證約束
只進行原檔唯讀反組譯；不更動遊戲、共享 task.json/catalog；所有未知 branch 另列。此篇是整合邊界與反證，非宣稱已找出 Z 連段完整閉環。

## 提交來源和可重現性
BIN 使用原本 PE .text section 映射；每個地址均為 VA。上述組語是逐址節錄；完整連續片段保留在該段獨立本地原稿，遠端版不是逐字的本地長版替身。