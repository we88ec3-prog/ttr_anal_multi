# S00 — NPC三倍互動距離與正常登入回廣場（2026-11-04）

使用者回覆v19測試卡：「無法與NPC對話，另外目前與NPC對話的範圍希望能放大為3倍」。隨後回報：「另外現在無法記錄進度，進入廣場後重登仍會從新手教學開始」。本輪明確重排正向重新登入恢復驗證；其他重送／故障／併發等暫緩項不因此開放。

## 實際觀測

唯讀狀態在回報後顯示lastApplied=Square、story=null，不能視為Story117已失敗。限定story trace有NPC10338的1C/category3、Quest15 scene1/2回報及formation request；可證明有收到廣場主線互動，不能證明所有NPC均可對話或精確定位使用者失敗的那一次。尚無Quest117互動紀錄，不憑韓文名稱猜NPC。

指定工作副本SHA6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c；Server v19 f6c1b171132365d94c9026605f4f5ad0ed81920d。玩家自行操作，agent未修改／操作Client。只讀指定測試帳號的進度計數：normal transfers2、normal tutorial settlement1、phindos journey0、story runs0，不輸出帳密／session／account識別碼。

## 修正需求與實作界線

1. 使用者政策：所有目前共用NPC互動區域packet27 radius2→6；廣場主線NPC及Town1 narrative距離驗證3→9，距離平方9→81。其餘NPC仍需對應已實作內容；放大範圍不新增任務／對話。副本出口與觸發點不變。這是明確PLAYER_ADMIN_REQUEST，不是官方距離原生結論。
2. CODE_ANALYSIS：named profile的A0入口一律送6E tutorial，未讀已有transfer/prerequisites；因此保存證據存在也會重跑。新增授權只讀normal resume，核對當前有效session與角色，並要求同歷史lease提交的normal transfer＋normal prerequisite settlement＋firstbattle完成及14/16keys；準備既有starter kit後直接走69/CSquare43既有轉場與初始化。沒有改寫完成時間／舊session、沒有重發reward／新角色、沒有從Client scene receipt推斷保存。
3. debug跳轉仍不保存normal紀錄。登入位置固定廣場；account主線checkpoint依content SHA讀回及繼承revision。未完成副本登出視為放棄，重新進入時整個副本重置；不恢復村莊位置、戰鬥中途或怪物HP。不可把舊lease proof改成當前lease完成。
4. 無正常完成證據的新帳號仍走原教學。當前profile無可恢復證據不補造normal completion。

## 驗證與限制

30項Category=HappyPath通過50秒。既有完整TCP十任務旅程改為距NPC5單位觸發，覆蓋已超出舊radius2/guard3、位於新radius6/guard9的正常互動。正向登入恢復使用已正常完成教學的合成帳號，重新認證新lease與新connection，斷言收到69、沒有6E、43初始化Map511及NPC regions。原正常旅程與debug隔離保留。這些是Server合成結果，真人測試待做；完整斷點續玩與未知NPC內容仍OPEN。輸入抖動／方向＋Z未因此修好。

## 後續使用者更正（同輪，優先）

「每次登入必定是廣場，但主線任務的進度要記錄」：登入位置與account主線checkpoint分開。正常完成教學的帳號登入只落廣場，讀取原normal證據並授權本次廣場轉場；此轉場授權不是重寫歷史完成紀錄。主線snapshot按content SHA讀取account最新revision，跨session提交繼承該revision，不把每次連線當成新的任務進度0。再次前往Town1敘事時保留已完成的QuestIndex前綴；未完成的任務從該NPC入口重新進行，副本中途位置／怪物HP不跨登入續存。Town2已完成的進度也不導致登入直接落Town2。測試跳轉不寫normal紀錄。

為維持外鍵與授權鏈，新的廣場登入轉場寫自己的transfer authorization；Phindos接受新旅程時可引用同帳號原normal settlement＋同歷史lease transfer，不篡改該settlement的session。仍核對當前session有效／owned role，後續每個新旅程stage正常提交。主線跨登入checkpoint與地點恢復分開，不重發正式獎勵。

副本共通事項另記：通道底端的大型傳送陣，站上按Z觸發、怪物不要生在玩家入口附近。使用者要求各副本實作時再詳細確認。本輪不猜全圖座標／effect scale、不修改佈點。影片9:26直接網頁開啟未成功，瀏覽工具初始化也失敗；未聲稱已觀看。MEF搜尋等開發至少60%後再做，Web派工改為既有資料整理，見research/handoffs/s00-web-server-definitions-20261104/README.md。

## 使用者最終明確語意

「除了新帳號，每次登出後登入都是在廣場，副本未完成登出視為放棄，重新進入副本的進度重來，副本進度重登不紀錄」。不保存副本進行狀態供續玩；既有事件journal僅留追溯。已完成主線前綴／進村milestone保留並在廣場初始化投影；沒有完成的當前任務重新進入時從其入口重置。正式Quest結算／獎勵仍未因此補完。

正常重新登入的current transfer row只授權此次確實發送的廣場轉場；原normal settlement不移轉session、不重發角色／reward。合成測試加入跨登入新lease後可接受後續主線旅程，修正最初因缺少current transfer authorization導致的FK失敗，最終完整正流程結果另隨發行收據更新。
