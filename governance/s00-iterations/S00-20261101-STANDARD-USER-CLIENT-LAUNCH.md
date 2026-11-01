# S00 — 指定工作副本的一般權限啟動

基線：S00 `7650d9425c0a8603fd24b0a697f4a72a53c01465`；私有 Server
`73e6d3c5b9e99182b959d6d921438b8fc1e134a9`。這是獲授權工作副本的實際
啟動觀察，並非原始 KR Client、官方 Server 相容性或登入成功證明。

## 授權與處置

使用者明確允許 agent 啟動指定遊戲測試，並要求自行排除啟動問題。在另外
詢問持續允許項目後，使用者回覆「同意，僅允許這兩個程式」；所指僅為
`Tartaros.LocalClientLauncher.exe` 與 `Tartaros.ip-zh-tw-only-v2.exe`。
Codex 本機設定已先備份，只加入這兩個 Computer Use Always allow 項目，
其他設定保持；本機設定／備份不入 Git。沒有修改 Windows UAC、遊戲 EXE、
原始 BIN 或原始證據，沒有附加／注入。

先前工具逾時須區分兩層：指定 EXE 的 requireAdministrator manifest，與
Computer Use 自身 app approval。後者曾阻止 launcher 執行，不能一律歸因
UAC、遊戲當機或 Server 問題。[官方 Computer Use 文件](https://learn.chatgpt.com/docs/computer-use)
說明 app approval 與 OS permission 分離。

私庫新增無視窗、`asInvoker` 的測試啟動器：只接受指定工作副本檔名及既有
SHA 白名單，拒絕 elevated caller，以 `UseShellExecute=false` 及僅限子程序的
`__COMPAT_LAYER=RunAsInvoker` 啟動。不永久登錄相容性設定，也不取得更高權限。
[Microsoft RunAsInvoker 說明](https://devblogs.microsoft.com/oldnewthing/20161117-00/?p=94735/)
支持這個權限語義；不是關閉 UAC。

## 實際結果與限制

- 工作副本 SHA256：`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`，啟動前後一致。
- 研究基準仍為原始 KR SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；不是本次執行檔。
- 2026-11-01 05:39:16 UTC（台北 13:39:16），launcher 回報非 elevated，建立
  PID 47532；短暫觀察期間程序未結束。
- Computer Use 隨後獨立確認標題 `Tartaros Rebirth`、window 1118546，畫面為
  登入頁、顯示版本 `1.1.62.46214`。本次成功啟動沒有要求使用者按 UAC。
- 無視窗 launcher 自行結束造成工具回報無 targetable window；這不是遊戲
  啟動失敗。判定依據是 child window 與實際畫面，而非只有 Process.Start。
- 正常輸入應用 Tab 從帳號切到密碼；實際已確認密碼遮罩出現。滑鼠欄位
  焦點及 Unicode 輸入在此舊遊戲不可靠；未據此推論 Server 認證錯誤。

本次啟動結果追加既有 REQ-0001 的 GAME_RUNTIME_OBSERVATION，不新增同義需求。
使用者另外明確同意將本次產生的隔離測試帳密輸入指定遊戲、送至本機
`127.0.0.1:8415` 完成正流程登入；測試帳密不入 Git。透過鍵盤 Return 提交，
2026-11-01 05:50:15.7588287 UTC 本機 journal 記到 connection 4 ACCEPT，
05:50:16.2603646 UTC RXCHUNK 118 bytes，隨即 LOGINSYNTAXREJECTED／CLOSE。
尚無 AUTHSTARTED，未到帳密驗證；畫面仍在登入頁且欄位 disabled。

同期 health receivedBytes 由354增加到472，accepted=2、rejected=1沒有增加，
replyAvailable=false，原生 admission OFF。舊的認證累計是合成測試，不能當成
本次 Client 通過。這次沒有保存封包內容或密碼，也未擷取遊戲記憶體。

### 由此提出的修正需求（仍屬既有 REQ-0001）

正常登入須能在正確 frame／字串邊界內解析到 C02，再分別驗收 S2C 與下一畫面。
本次 runtime 已證 Server 接收後在 syntax 階段中斷，但**僅有目前 journal 不能
斷言是哪一個欄位造成**。不得將此寫成密碼錯誤或直接放寬所有 layout 檢查。

Server source review 發現 E8 的高位元組編碼預檢掃過完整51B容量，連第一個NUL
後面的未使用空間都檢查；實際 decoder 卻只消費 NUL 前內容。修正預檢只看
字串內容、保留長度／terminator／真正內容編碼檢查，並補 enum-only 拒絕原因。
既有正常 E8 登入測試改用合法字串加非零未用容量，六項 HappyPath 通過；這是
合成正流程 fixture，不是本次封包內容或原版 producer padding 的證據。
修正後重新啟動 Host、正常重開同一工作副本，以同一隔離測試帳號完成重驗：

| UTC（2026-11-01） | 新 run 的 connection 1 事件 | bytes |
| --- | --- | --- |
| 05:57:28.307746 | ACCEPT | 0 |
| 05:57:28.7386137 | RXCHUNK | 118 |
| 05:57:28.7420541 | AUTHSTARTED | 0 |
| 05:57:28.9031495 | AUTHACCEPTED | 0 |
| 05:57:28.903162 | REPLYUNAVAILABLE | 0 |

新 Host run health 為 received=118、accepted=1、rejected=0，providerUnavailable=0、
logDropped=0、replyAvailable=false。Computer Use 獨立確認新 window 45551238、
PID23092 仍在登入頁、欄位 disabled。launcher 第二次啟動仍非 elevated 且 EXE
hash 不變。中間工具的 ShellExecuteW error2 為呼叫路徑轉義問題，改用正確
完整路徑後成功，不歸因 Server／遊戲。

**本次工作副本 M2 已確認**：正常遊戲請求經 parser→C02→AUTHACCEPTED；不是
原始 KR Client M2，也不代表 M3。重現的 syntax 阻礙已排除，後續實際阻礙
為 Host 未送回覆。未留 raw payload，故不將「NUL後特定bytes」寫成封包觀察。

下一步：正常新帳號登入的同會話 RX／C02／S2C／UI 分開驗收，再繼續跨線、
空名單、第一角色、新手教學與廣場。既有候選 serializer／handoff broker
仍未接 Host；所有正式 SPEC／RR／GAP 狀態及待測清單不變。
