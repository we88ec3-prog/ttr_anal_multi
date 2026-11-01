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
登入提交尚待本次測試憑證輸入授權；不把停留登入頁記成 Server 拒絕登入。
Host health 仍為 auth-only、replyAvailable=false，原生 admission OFF；舊的
354 bytes／2 accepted／1 rejected 是先前合成測試累計，不能當成本次 Client。

下一步：正常新帳號登入的同會話 RX／C02／S2C／UI 分開驗收，再繼續跨線、
空名單、第一角色、新手教學與廣場。既有候選 serializer／handoff broker
仍未接 Host；所有正式 SPEC／RR／GAP 狀態及待測清單不變。
