# 兩房重訪工作台

2026-11-22，SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。將已完成的
[兩房前綴編譯器](FINITE-PREFIX-REPEAT.md)接入[已保存版本重訪工作台](FINITE-REPEAT-WORKBENCH.md)。
未展開的Case693來源可選僅入口第一房，或前兩房依序重訪；次數包含最後一輪。
選兩房時，三輪即六次房間訪問，不把它顯示成三間房或同場增援。

POST表單新增shape=entry／prefix；舊請求未帶shape時仍為entry。原單房計畫、
ZIP檔名與內容bytes對同一來源／draft／revision／次數保持；兩房使用獨立的
LOCAL_FINITE_PREFIX_REPEAT_WORKBENCH_BUNDLE_V1_NOT_NATIVE_MEF manifest schema，
plan檔為prefix.prefix-repeat.json，設定使用既有獨立prefix mode。七檔ZIP其餘
來源、配對與manifest檔名沿用工作台契約。匯出檔名另標prefix，不能和單房混淆。

預覽明示選定範圍、輪數、每輪房間順序、logical／chart／map，以及原／新路線
收益和單次結算。以同一保存revision及shape再次下載，不切換到最新草稿；仍先驗
來源／AI／BND及完整Case693 adapter。JSON使用LF，ZIP固定時間／順序，可重現。
未保存編輯、原件、歷史、遊戲進度與運行服務不因預覽或下載而改變。

正流程須以原r1來源、較新r2並存驗證2／3輪兩房配套為108／128EXP（含最後20），
比對每檔SHA、mode、兩房計畫及來源bytes；實際下載的三輪配套走兩條正常TCP分支
至一次128EXP保存與同村同隊返回。另以先前已保存的單房ZIP作golden bytes對照，
證明缺省shape的舊下載沒有改版。工作頁選擇／預覽與HTTP下載驗收分別記錄。
Client回跳、自然新帳號、獨立Host遊戲通關及暫緩非正流程仍不由本項代填。

## 本批正流程結果

兩房2／3輪HTTP預覽與實際ZIP下載為108／128EXP，保持r1（已有r2）及全部SHA；
兩次下載bytes相同。缺省shape的舊單房2／3次ZIP與原golden完全相同。新三輪輸出
Scenario／AI bytes也和先前固定prefix3候選相同。實際下載配套兩條TCP各一次128EXP
保存回原村同隊，三筆機關成本及兩房波次重啟、24枚投射物退休均保持。

獨立in-app browser實際選兩房2輪、單房3次、兩房3輪，文字／表格顯示108／96／128，
回來源連結保持r1。截圖API回報Unable to capture screenshot，未列pixel／版面截圖
驗收；瀏覽器未點下載，下載由相同正式HTTP表單核對。兩個獨立測試Admin均已關閉。
Release Host／Inspector／Admin.Web零警告錯誤，676 HappyPath通過，含兩個新增配套案例。
詳見 [機器收據](finite-prefix-repeat-workbench-validation.json)。
