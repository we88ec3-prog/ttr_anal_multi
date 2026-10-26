# T03 本機登入入口定向補證 — 待整合

基準 KR 原檔 SHA：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。這份新增審核針對 AI 替代實作，不是原生執行證據。

先前 REVIEW 的條件式缺口現在取得呼叫端文字證據：唯讀取得 `anal/login_test_server.py`，SHA256 `7385c9a5c1be5b0715ae56b189f6a584677dc657ca892377b545d233206ef35e`，完全符合 T03 原有 unresolved_dependencies 所記錄的來源 SHA；不是因檔名或日期而接受。完整原始文字保存 `evidence/local-server-7385c9a5c1be5b0715ae56b189f6a584677dc657ca892377b545d233206ef35e.py.txt`，定向摘錄、AST 條件與工具版本保存 `evidence/local-dispatch-audit.json`。

**觀察**：原始碼53–54行匯入 `credentials` 並依 `--account-db` 決定是否建立 store。407行的明確條件為 reply=login-reject/login-success、command=0xE8、payload長112；409–415行在 store 存在時才呼叫 credentials / authenticate / login_ticket_response。沒有 store 時417行改用 login_response fixture。此檔只有411行這一個直接以 credentials 名稱呼叫的點。

**成立條件與推論**：在這個來源快照的這個登入回應分支中，214-byte 000F 不符合407行條件，因此不會經這個分支進入帳號驗證。這比只看 credentials 函式更能定位 E8-only 相容性邊界；仍不能據此斷言所有本機服務、目前部署、其他處理鏈都不支援000F。未執行 server，也未讀取帳號 DB 或存檔。

**更正／追溯**：保留先前 REVIEW 與 claim 的條件式說法，新增這項快照內的呼叫端證據，不把舊結論覆寫成更廣泛的「000F 一律不支援」。官方驗證、兩種 native auth 欄位／編碼與連線時序仍未驗收。

**可玩流程與待補充開發**：若要支援已記錄的多種原生登入模式，後續應在同 SHA 原生證據下分開列 E8、000F 入口、資料驗證與回應消費者，再決定相容層規格；不能直接讓000F套用E8的112-byte切片或臆造成功回應。T02 仍負責封包框架與連線時序，T04/T05 的角色與場景缺口不由本項解除。

工具：Python 3.10.6 ast/text/hashlib；來源只讀不執行。AST 分支數僅索引用途，不是語意完成率。
