# T08 roy 106–152：R0/R1中段交接

48份來源（129兩個不同blob均保留）的實際narrative已閱讀，未完成0份。按功能歸併12組：4組PARTIAL研究導航、8組UNKNOWN缺口；新增NATIVE_VERIFIED及全文PASS均為0。

`proposal.json`逐份包含source file/blob/SHA、精確行號與原文摘錄、claim keys、觀察及衝突處置。`build_proposal.py`是人工閱讀後的有限主張歸組，不依檔名生成語意。

去重以桶儲存、callback slot、owner身分、core介面、平面buffer、更新時序、B queue因果、entry評分、writer範圍、record/vector owner、Host生命週期與座標修正區隔；同主張的多份研究稿只增加來源關聯。

既有精確來源FAILED有24份：129-resolved和130–152，並非只有140–152。這些版本只對應UNKNOWN/R2缺口導航，座標錯誤衍生的肯定結論全部隔離。129-static另為不同來源，保留其未閉合owner的歷史狀態。146/149/151/152所述「vtable目標進入指令中段」不能繼續當有效ABI反證：T01已確認舊flat與PE文字區差0x400，7A8310/7A8E10等實際PE入口需按既有裁決處理；資料節絕對值及vtable不可全量平移。

118的非初始化plane writer屬對早稿未知的研究進展，仍以PARTIAL標記；129後稿聲稱owner問題已解不會覆寫其FAILED版本。B entry到22桶因果、同實例生命週期保護、具體score與外層觸發均保留UNKNOWN。原稿動態斷點只是未執行方案，本次沒有執行、附加、native重分析或原稿修改。

沒有現有Server SPEC直接規定這些Client幾何/調度細節，`affected_spec_ids=[]`，避免臆造Server契約。S00遇到具體設計阻塞時才應按列出的最小R2問題派工；完成來源身份、有限用途與衝突處置後即停止R1。

重跑：repo根執行 `python -X utf8 -B research/handoffs/t01-t08-roy-20261029/middle/build_proposal.py`，再執行同資料夾的 `validate.py`。驗證只核對來源身份、行號、關聯及FAILED隔離，不產生語意通過。
