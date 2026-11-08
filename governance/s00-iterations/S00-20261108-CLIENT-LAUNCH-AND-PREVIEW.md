# S00 — 啟動恢復與頁面單次試播

類別：GAME_RUNTIME_OBSERVATION／既有 REQ-0001 追加觀察。
基準：公開 main 96a78555375d76bc0474e68fc1ba38685536e67a；Server v80。

使用者本輪明確授權重新開啟指定 v2 Client，批次比對多個角色及多組動作／特效。
範圍不含附加、注入、Client 修改或系統設定變更。

## 啟動與交握觀察

沿用 2026-11-01 的 Tartaros.LocalClientLauncher.exe；其來源明確設工作目錄
E:\Tartaros\workspace、UseShellExecute=false、僅限子程序 RunAsInvoker，拒絕高權限 caller。
2026-11-08T07:54:21Z 啟動記錄為非 elevated、Client PID 47760，SHA256
6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c，前後未變。
畫面確認正常登入頁，沒有 NOT DEFINED。先前直接啟動的實際工作目錄未留存，
因此不能把工作目錄視為已證明的唯一根因。UI 工具對 Windows 路徑應保留反斜線，
JavaScript 使用 String.raw，避免跳脫字元使工具取得錯誤路徑。

第一次登入後長時間停在選服，發生頻道逾時；Server authAccepted=1、primaryHandoffs=0。
正常關閉後重開、縮短選服停留，再次觀察 authAccepted=2、primaryHandoffs=1、
rostersSent=1，實際進入角色展示頁與技能空場。這不是 Server 格式修改的驗收。
廣場入口實際可點區在圖示本體；下方「進入廣場」文字 hover 不能單獨當成功證據。

## 比對工具需求／S00 接受的 Server 自有設計

遊戲文字欄位可由帳號點選後 Tab 切到密碼，逐數字輸入；短按 Z 在技能場接收不穩定。
目前僅留到一個 flags=1／direction=64 的受控 actor input 與 action184 的既有000D回覆。
畫面只有局部姿態觀察，不足以確認手榴彈完整特效，更不能建立185等變體與技能ID的配對。

新增本機測試頁「選用並試播一次」，使用現有已准入原始動作目錄與000D候選，
不製造Client輸入列、不改正式技能、資源、傷害、AI、角色持有或正常主線。
只在同角色已載入的預覽場重置並播放一次；不同角色先選用等待載入，再試播。
既有「選用此動作預覽」及手動Z保留。這是 SERVER_DESIGN_CHOICE，並非新原生協定證據。

目前仍待多角色完整畫面比對；不能將合成封包測試或畫面待機標成技能完成。
原生 MEF 格式、傳檔 opcode 與官方 AI 仍無新增結論。
