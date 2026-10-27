# KR T10 任務盤點與第一手交叉驗證（非正式分析段號）

## 正式範圍與狀態
GitHub `kr/tasks/T10/task.json` 與 `README.md` 確認：普通攻擊與連段，研究輸入、連段及取消流程；傷害公式由 T12 負責。依賴 T02/T04/T09。owner=null、state=unclaimed、handoff_status=bounded-review-handoff、native_complete=false。尚無可證實的 T10 分段研究序號。依 AGENTS.md 新增方法需先認領與登記；本次只讀，未修改 task.json。

## 現有證據與缺口
T10 README：CHAIN_WINDOW=.65 及服務端續段排程屬自製；原生連段／取消窗口未知。相關既有原生限定研究 `kr/evidence/1e15689d7bbdf4c4a83ae76cf1813d538b8cb38db79098c6b85ba386056dab36.txt` 記錄 `0x5452C0` 的 000A 行動輸入封包組裝，5-byte row（actor WORD、input WORD、heading BYTE），以及至 WSASend 的下游傳送鏈。這只能證明輸入傳輸邊界，不能推論連段判定規則。`kr/evidence/91830956fb04388f5eabd1c876f283c6e78e9f001e953e978345472ff3572866.txt` 記錄一般控制器 virtual +2C、+48 與 motion 0x10 的有條件本機路徑；不得直接命名為普通攻擊連段。

## 第一手檔案與機器碼核對
本地候選 Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，Tartaros.exe SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。BIN MZ header。依既有 T08 .text VA 0x401000/raw 0x400 暫用映射，VA 0x545829 對應 raw 0x144C29，取得 bytes `BA 0A 00 00 00 66 89 54 24 2C 8B 4C 24 2C 66 8B 54 24 30 A3 D0 48 FE 00`。其中 `BA 0A 00 00 00` 是 `mov edx,0xA`，`A3 D0 48 FE 00` 是 `mov [0xFE48D0],eax`；支持歷史筆記的 000A 常數與長度全域寫入附近，但不能單憑此核實完整封包格式或連段語義。映射仍應由 PE header 獨立復核。

## 待辦與邊界
1. 先按 AGENTS.md 登記 T10 owner/方法範圍（需協調，不擅自修改）。
2. 針對普通攻擊輸入的 virtual +48 / 0x546100 路徑追查實際按鍵映射、攻擊觸發與取消 gate，並以 BIN 逐分支驗證。
3. 將本機 motion、000A 輸入、伺服器續段與 T12 傷害分離；找不到原生 0.65 秒證據則保持 AI 替代。
4. 按 shared/CLIENT-MODIFICATION-POLICY.md，優先還原封包與服務端資料，不自行修改原始客戶端。

## GitHub
僅唯讀查核，未 Commit/Push；未認領任何方法。參考 `AGENTS.md`、`HANDOFF.md`、`kr/tasks/T10/README.md`、`kr/tasks/T10/task.json`、`shared/CLIENT-MODIFICATION-POLICY.md`。