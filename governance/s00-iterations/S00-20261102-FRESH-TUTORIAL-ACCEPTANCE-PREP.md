# S00：全新帳號首次教學驗證基線

先前v10人工結果確認既有帳號能進蘋果房屋、招募、到廣場移動與停止。
這次另建立全新隔離帳號，避免把舊帳號已有的角色／首戰狀態當成首次旅程驗收。
帳密不公開。未替換執行中的Host、未操作遊戲或修改Client／資源。

## 實際完成的準備

私庫LocalDev新增明示`--provision-kr-test-account <existing absolute DB> <name>`工具模式。
它只接受redirected stdin的6..128字元ASCII測試密碼，使用既有KR transform及
Account provider的salt/PBKDF2保存；不改一般Admin／帳號密碼政策。
工具先驗證既有expedition／tutorial component，僅建立新Account，不執行schema初始化，
不填角色、裝備、勝利或任務狀態。實際一次建立成功，工具build零警告／錯誤。

另新增`tools/inspect_tutorial_account.py`，既有DB以SQLite URI mode=ro、
query_only及同一read transaction取得單帳號進度。輸出不含密碼、salt/hash、
顯示名稱、session識別或原始封包；帳號關聯僅私下用SHA參考，公開副本移除此值。
此工具沒有從DB推定Client已到廣場或Quest／獎勵完成。

[公開去識別基線](evidence/S00-20261102-FRESH-TUTORIAL-BASELINE.json)實查：
Account schema2，profile無、roles空、equipment空、tutorial progress無、
first battle win false、session0、character0。journey component不存在，未遷移／補種。
這是fresh baseline資料證據，不是遊戲通過。

## 明確的人工驗證卡

新帳號首次登入、命名，正常通過移動／視角／Tab、預設伊莉西亞首戰、
招募與蘋果家後續劇情，到廣場確認人物／NPC可見並移動停止；不點NPC、不跳過教學。
遇到卡住停下回報；不刻意重測已安排於馮德斯副本的連擊手感。
另觀察換場畫面是否可見，不加固定sleep假裝已證原生載入交握。
**人工結果待回**；測後再以相同帳號私有參考讀取保存狀態，分開記錄缺口。

## 環境核對與限制

一般沙箱的process/netstat/socket觀察看不見外部服務，不能據此判定已停止。
本次曾因此誤判並在沙箱嘗試啟動，外部查核後修正：原Host51020／Admin2452仍存在，
外部健康authBound=true、journeyEnabled=true、Admin HTTP200；沙箱嘗試的兩個PID
在外部查核不存在，未停止原服務，沒有執行舊版stop腳本。
後續以外部精確PID／path與loopback核對為準。仍為已部署v10原code cd2a7bc。

Quest14／16合法結算與獎勵發布仍待實作；fresh遊戲觀察也不替代其DB與協定證據。
本紀錄不新增APPROVED需求或提高原生FULL-PASS，不把測試準備寫成整體goal完成。

## 後續登入缺陷與替代基線

原測試卡登入卡住，並非通過；詳見[登入名稱限制觀察](S00-20261102-FRESH-LOGIN-NAME-LIMIT.md)。
已限制工具的fixture名稱為3..9 ASCII並另建短帳號；原baseline保留作歷史證據。
新版測試卡結果待回，不能再以舊卡的帳號進行測試。
