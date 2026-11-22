# 獨立完整Host的正常副本入口

2026-11-22；OFFLINE_SYNTHETIC / SERVER_CONFORMANCE / NOT_NATIVE_MEF。
分析基準cc5b0e971，私有Server基準7f4eabe。這批補跨程序入口證據，不是原生MEF完成。

先前完整副本TCP使用真實socket，但遊戲邏輯由檢查器內部的gateway/journey承載；
完整Host則只驗設定與啟動。因此不能用它們宣稱另啟部署Host遊戲通關。
這批實際啟動獨立Release Host程序，由另一個Python程序只透過TCP走正常入口。
遊戲邏輯、session、隊伍與副本均由Host負責，沒有測試器內的影子world或直接呼叫Handle/Poll。
Host採真實時間，未注入測試時計；HTTP只讀health計數與配置，不透過debug API改進度。

測試資料庫由既有隔離seed唯讀備份到新的輸出檔。只在新副本新增測試帳號，
以既有帳號／教學／Q15／角色API準備角色4/Lv15，累計39000EXP；準備lease關閉後，
由實際login與primary handoff建立正式連線。來源DB SHA保持一致，沒有使用者DB換版。
此準備步驟不代表全新帳號自然完成主線，不能合併至該項驗收。

兩條正流程分別使用：

- 舊固定整合Case693，保守界限88/88EXP。
- 管理端實際下載的分支r2四輪配套，保守界限88/136EXP。其manifest/profile/payload/AI/BND仍由啟動器重新核對。

每條皆驗正常登入、primary roster、角色選取、廣場1088、廣場建立並公告一人隊伍、
進馮德斯村182、同room的Lv15隊伍快照與隊伍目錄、選Stage462、正常開始副本。
接著從Server封包驗載入開始、MissionField安裝、Case693 context、map3430、chart10、
戰鬥啟用與載入結束的有序子序列，並驗玩家entity0x100與原monster1004/PRE1已安裝。
health確認一次成功登入與primary交接；不以health取代遊戲封包。
不記錄登入憑證、handoff token或原始登入封包，機器收據只留計數、內容SHA與程序分離等資料。

啟動器另加明確的 `-PreflightOnly -IsolatedPorts -KeepIsolatedHost` 測試生命週期，
先完整預檢，再回傳PID與部署路徑供TCP檢查使用。這不改預設預檢完成即停止的行為。
檢查器finally核對該PID命令列的精確部署DLL路徑，關閉自身socket後只停止該Host。
原三版與舊整合預檢的停止控制另有回歸；現用服務未替換。

首次工具使用capture管線時，保留的子程序使輸出管線未關閉而等待；已核對PID／路徑停止隔離Host，
改成檔案輸出交接後才完成正流程。該首次嘗試不列遊戲通過，也不當作遊戲故障。

`GAME_RUNTIME_OBSERVATION`：目前證據範圍只到首圖安裝／啟用，沒有攻擊、機關、分支重訪、
頭目、結算存檔或回村驗證。下一段應以Server已發布的actor/資源/出口資訊驅動正常操作，
在獨立Host中完成上述流程並讀取提交結果；不能回退成檢查器內world、虛構ACK或固定停止輪數。
原生MEF／自主AI／CPU移轉與指定v2人工仍各自OPEN，非正流程未執行。

建置與HappyPath及精確證據見[機器收據](separate-host-dungeon-entry-validation.json)。

最終三個Release零警告／錯誤，704/704 HappyPath通過、零略過。TRX SHA256 `d89f0629437e4b9c2b001e82490ef3816480b75bffb545101181848a457cba86`。
