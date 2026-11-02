# S00：連續收包、輸入緩衝與主線進度測試控制

使用者回報v14「上→Z→上不能走，上→Z→右可以走」，要求詳細說明收包堆疊，並新增
直接指定主線段落、快進／退回以持續測試。以下描述目前候選Server實作，不冒稱原版完整輸入佇列。
被測Server為`bfc04f1f131c053192546e89a2624050c0b9c6ac`、指定工作副本SHA仍為
`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`；本輪不操作Client。

## 實際收包與執行順序

1. `TcpConnection`一條連線只允許一個Receive及一個Send操作，不並行修改同一世界。
   primary每次最多讀4096bytes；TCP讀取不等於遊戲封包，可為半包或多包。
2. `KrE1bOfflineStreamReader.Append`先累積4byte框頭，依marker取得4／6byte header與
   payload長度；組到完整候選frame才decode、檢查完整性、加入completed清單。
   不完整的最後一包保留。A完整+B前半，接著B後半+C完整，輸出順序仍A/B/C。
   這是FIFO byte/frame處理，不是後進先出stack。壓縮2633等未支援格式不假裝解出。
3. `ReceivePrimaryAsync`以foreach依序處理該次completed清單，逐包await domain處理，
   再依序await送完該包回覆。沒有每個指令各開Task，也沒有按方向排序或反轉。
   SQL／送出等待期間，後到資料可能暫存在socket／待讀取chunk，並非動作全部同時執行。
4. 每100ms世界計時分支與Receive共用同一外層迴圈；deadline跨讀取保留，避免持續輸入
   不斷重設計時。它不是獨立即時執行緒；一次chunk有多個frame時會先跑完foreach，
   domain／送出慢會造成時間偏移。尚未量測每包等待時間／實際backlog，不能宣稱永不延遲。
5. `0A`輸入batch結構為6+5N；只採用唯一匹配本連線控制actor的row。header2..5仍opaque，
   不當作可信Client時鐘；同actor重複row未定義合併語意，目前不執行，不偷偷去重／排序。
6. 移動是目前方向／moving／單調Server時間與碰撞pose的狀態更新，沒有「按上十次便累積
   十格」的指令隊列。新有效輸入覆蓋目前意圖。750ms無新輸入有停止保護；pose在Input／Stop
   等時點更新，不是每收到一包便固定走一格。
7. 戰鬥另有有限buffer：普攻一個pending意圖與timestamp，技能一個最新pending選擇與timestamp。
   期限0.4s；普攻候選恢復0.35s且需已過impact，再決定下一段；技能依動作結束／冷卻／資源
   消費。連按十次Z不會儲存成十次稍後全部打出；新的技能選擇可替換舊pending。
   每個收到的frame已處理，不表示每個要求都會成功開招。這些仍是Server重建政策。
8. 每五個非空0A batch送一次DA，DA補五個Client傳送額度；依batch不是row數計算。
   即使gameplay不接受該row，也補已消耗的傳輸額度。不是湊五個動作才執行，也不是增加五段連擊。

現行測試primary另有30分鐘／1MiB總接收budget，屬目前候選連線生命週期限制，
不是動作buffer長度。收包／驗證／動作buffer與正常任務保存是不同層。

## 本次方向問題的原因與修正

v14為阻止Z後舊walking bit恢復，加入按方向鎖定；同方向只有收到release或換方向才解除。
因此新的「上」也被當舊輸入丟掉，右則解除。這是確定的程式判斷缺陷，不能用「還在排隊」解釋。
v15移除此跨封包同方向鎖：Z當下停止；下一個有效移動row即使方向相同，也接受為新意圖。
保留戰鬥期間的動作／移動規則，沒有新增Client補丁。

## 主線進度指定功能

本輪使用者明確授權測試進度跳轉；只新增這項正向測試能力，不擴大為全部重登／重送／故障測試。
Host明示`TARTAROS_LOCAL_PROGRESS_DEBUG_MODE=LOCAL_TEST_PROGRESS_OVERRIDE`才開本機頁面：
`http://127.0.0.1:5082/local-test/progress`。一般模式預設不開。

可選Square廣場、Story2第二段劇情、Formation編隊、Road191第一圖、Road192第二圖、Phindos村落。
未開發的Quest117之後不提供虛構跳轉。需登入已命名、持有伊莉西亞與蘋果的測試帳號，
目前控制最新綁定的遊戲連線；不會替未完成角色準備的新帳號任意解鎖全隊。

HTTP只排一個pending要求，由現行遊戲連線Poll在單一序列中取出／套用；不從HTTP執行緒
直接修改world。切換清除舊移動、攻擊buffer與場景等待，再按目標重建scene/context/map/
actor/NPC/control，廣場仍等原有43初始化訊息。跳到劇情／編隊需真Client視窗生命週期驗證。

第一次套用後整條連線標記TEST_PROGRESS_OVERRIDE；跳轉前置snapshot只作測試呈現，不插入
正常Quest完成key。後續debug遭遇／返回不提交正常主線勝利／到村／獎勵，現有帳號進度不回寫。
本機audit記queued/applied、checkpoint、UTC與測試標記，不記帳密。重新登入回一般路線；
重進頁面可再次指定測試段落，跳轉結果不能作新帳號正常流程人測通過證據。

## 驗證

27個允許的正流程／新授權debug案例通過（18秒）、0失敗／略過；Host Release零警告／錯誤。
完整TCP正常路線驗證同方向→Z→同方向可恢復，及後續NPC／兩圖／手動出口／村落。
正常到村後再正向切六個checkpoint、重打第一圖並用出口進第二圖，最後SQL核對原正常
stage1..4與lease／role紀錄仍未改寫。這些為合成TCP／資料驗證，實際頁面操作與Client切場待測。
其餘負向、取消競態、多人、未知資產、重登恢復與壓測仍暫緩。
