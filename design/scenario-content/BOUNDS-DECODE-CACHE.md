# 已驗證的唯讀地形解碼共用

2026-11-24。SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。實作既有D08／OPT01的底圖共用部分；
不變更碰撞政策、路徑搜尋、地圖配置或原始BND。

每次`Read`仍計算輸入bytes的SHA並比對來源；通過後才以原始SHA、小寫正規化的鍵、
明確version2准入布林值與解碼政策版本1查詢。沒有用檔名或MapID代替來源，
也不因某次已准入就跳過另一次的政策。原有第三層特例、header／extent／layer檢查完全沿用。

只共用原解碼器建立的不可變底圖；不同MapID仍由各配置的字典綁定。機關屏障的wrapper、
旗標predicate、instance／世代與可變路徑狀態不進快取，原位置和路徑判定仍各自執行。
弱參考不延長舊底圖生命；最多256鍵，以先加入先移除的方式限制索引。GC回收或鍵移除後
可以再次解碼，不承諾永久命中率。政策改變時需換政策版本；新行程自然有新快取。

## 已驗範圍

三新增正流程驗不同輸入buffer／大小寫SHA共用、兩個合法准入context分開、兩個instance
屏障開關互不影響且原底圖不變。沒有新增邊界／故障／併發／安全測試。
同一Case693正常配置兩次載入：第一次7驗證／7解碼，第二次累計14驗證／7解碼／7命中；
七個MapID跨兩次配置指向相同底圖。該Case內沒有重複BND別名，不把它當跨Map別名案例。
完整七圖尺寸、來源與阻擋mask和舊版本輸出完全相等。

相同Inspector、相同保存的階段頭目／掉落配套，以保留的舊Network及新版各走兩分支TCP，
四路各88EXP一次、原村原隊返回；完整primary回包僅正規化既有fixture帳號識別欄後逐byte相同。
同版獨立真實時計Host也完成六圖、同頭目兩階段、五筆拾取8件／付款1件、88EXP一次與原隊回村。
該Host只讀診斷實測72次驗證、50次解碼、22次命中、0移除。這是工作量，不是CPU百分比或Client卸載。
分析規劃的118 MapID／74 BND是另一個corpus統計，不作本批實測覆蓋。

Host停止後的原fixture留有rollback journal，冷開唯讀SQL報需要回復。先核對原Host PID已不存在，
保留原DB與journal，只把停止狀態的一組檔案複製到另一讀回目錄讓SQLite完成回復。
直接查該副本得183×7及88EXP；原DB／sidecars雜湊不變，來源種子也不變。
沒有注入故障、刪journal、忽略WAL或執行備份／還原測試套件，這項必要fixture處理獨立記錄。

Host／Inspector／Admin三Release零警告／錯誤，802 HappyPath零失敗／略過。
收據：[bounds-cache-20261124.receipt.json](../testing/bounds-cache-20261124.receipt.json)，
SHA256 `097275f2d910686df365fb25a4161e5b3f7f1737d740a967b68d36cea740658b`。
原Client、現用服務／資料未換版。指定v2、自然新帳號、UI-DROP-01、復活Action3／23及其他MEF仍另列。
