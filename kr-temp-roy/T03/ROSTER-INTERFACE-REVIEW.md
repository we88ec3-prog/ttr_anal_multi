# KR T03 角色清單→UI記錄介面 — 待整合

原檔Tartaros.bin SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。REA6.5.0/Ghidra12.1.4；profile 3c06738e45e144d5f073edbd3244c6bff46222f389525fe659bc92dca2ccdece。逐筆Evidence／檔案SHA／body見roster-acceptance-review.json，獨立位元組核對見roster-interface-byte-verification.json。個人session-status僅為工具交付進度，不是語意驗收依據。

## 已觀察：命令與清單切分

共用T02場景分派以manager+4+command*8選handler。4B7DC0將4B7F00寫到FD2D0C；49439C的manager receiver為FD2CF8，因此(FD2D0C-FD2CF8-4)/8=2。manager、index、lookup精確指令已由REA及原檔位元組核對，T02收包分派語意只引用共用成果，不重新定義核心。4B7DC0先登記為T03候選，觀察其共用角色後已更正主責T02、roy不認領；更正前後在changes.json。

4B7F00的角色記錄數為length<65時0，否則floor((length-65)/53)；第一記錄是payload+65，每次前進53 bytes。來源ID在record+2E，unsigned ID<=9且得到非零目標指標時，將F94304+ID*210作ESI、來源record作EDX呼叫4D4150。這正是672F00先前核對的UI記錄陣列與+5C消費位置。

另一消費者4E2730使用2-byte標頭，記錄數floor((length-2)/53)，從payload+2開始；選取基底由client+6924取得，同樣依ID*210呼叫4D4150。只觀察到4E1E3F將該handler寫入receiver+15C，未把此偏移直接猜成命令號。

兩條迴圈沒有下界1、去重或完整餘數檢查；這不等於官方允許ID0／重複角色或不完整封包。4B7F00在計算角色筆數前已讀多個標頭欄位，不能將「length<65→0筆」說成短封包安全檢查。角色記錄只取整筆，尾部未滿53的部分不增加迴圈次數。

4B7F00進入角色迴圈前另有多次資源文字查詢，部分查無資料分支為INT3終止；本報告的資料交接結論以有效資源／初始化狀態並到達該迴圈為條件，不代表任意合成標頭都能完成callback。

## 已觀察：單筆欄位與UI旗標

4D4150 body為[4D4150,4D419C] inclusive，ESI為目標記錄，EDX為來源。先寫目標+5C=1，後續複製如下；欄位名稱未經原生消費者驗收的部分只列寬度及位置。

| 來源 | 目的 | 已確認與限制 |
|---|---|---|
| offset0開始的NUL終止UTF-16字串 | record+C | 逐word複製至包含NUL；leaf內沒有長度／容量限制。不能把固定記錄尺寸當成copy自動截斷。 |
| byte+2E | dword+4 | caller亦用此byte選ID*210；官方可用角色政策仍未知。 |
| byte+2F | dword+D4 | 原生欄位複製；不命名世界內統計。 |
| byte+30 | dword+DC | 同上。 |
| dword+31 | dword+50 | 未對齊來源4-byte讀取，延伸至+34。 |
| dword+2A | dword+8 | 寬度確認；fixture literal1不能提升為官方初值。 |

leaf回傳EAX=1。此結果與caller選取、先前672F00的record+5C UI gate合併，證明「有效記錄可寫入UI所讀的可用旗標」；不代表server授權或UI/場景已刷新成功。還需要有效來源／目的記憶體及正確NUL終止，上游完整錯誤契約未驗收。

## 已觀察：後續動作與排除結果

4B7F00對每筆來源記錄建立command26+ID的3-byte請求，發送仍受FBA798==0 gate；此步在ID選取guard之外。它也建立16-bit選取mask並存F94240。後面另有初始化請求，包含24/1F/25/15，以及對可用ID1..9送DA/D2；不能把收到清單解讀成所有bootstrap已完成，更不能猜request+1回應。

兩個清單消費者都呼叫4E5FB0。該方法觀察到rank表、receiver+68D0/+68CC更新及TeamRankIcon_64.dds效果；未看到通用角色清單刷新通知。這排除先前候選描述，沒有沿其callee分析rank計算／世界初值。也沒有以一個helper排除其他位置的UI通知。

## 本機AI替代與開發界線

SHA 2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e 的login_protocol.py：command2使用65-byte base，附加53-byte記錄，+2A填1、+2E填ID，其餘零值與LocalHero名稱。這些欄位位置／清單形狀已有上述原生對應，但內容與預設名單仍是合成資料。roster_ids的unique IDs1..9/default1為本機政策；不能宣稱native lower bound或官方名單。account_store另有自身預設名單，應按實際入口分辨。

後續相容層可依已驗證的command2/header/stride/copy位置實作；應明確保留NUL及完整記錄的有效輸入契約。未知byte+2F/+30/dword+31與+2A業務值須繼續標資訊缺失／AI替代，不能因fixture零值可顯示而說是官方規格。command60的27-byte場景資料、角色世界初值／位置留給T04/T05；這次未新增其核心分析。

## 尚未完成及遊玩影響

- 清單→UI記錄+5C的資料橋接已補證；實際control資源、觸發刷新／生命週期與完整初始化回覆順序仍未閉合，可能仍造成可用旗標已有而畫面或後續操作未就緒。
- 替代2-byte標頭路徑的命令號、完整錯誤／重試／斷線契約仍未知；不能將兩種header混用。
- F42EF/F4247業務消費者、42之後的場景前置與43/69測試配對仍待T05介面回補。
- T02保留連線／framing／時序核心；T04保留真實初值／資料權威；T06保留同版本UI資源身分。官方帳號與角色授權不由客戶端欄位推造。

本報告是有限介面審核，不是完整T03可玩驗收。暫存待整合；正式增量版本以changes.json的內容SHA對應為準。

工具限制另存roster-value-flow-limit-review.json：4B7F00的high-pcode/def-use輸出標示truncated=true，omitted_operations_lower_bound=1、known_omitted_edges=1；不能以它宣稱完整資料流。此處的筆數／cursor／receiver／呼叫結論改由所列assembly區塊及原檔位元組核對支撐。其餘函式def-use未截斷亦不等於完整程式語意。初次驗收腳本因要求全部def-use未截斷而拒絕；後續僅接受已獨立核對的局部指令事實，保留此限制，沒有提升整個callback為語意完成。
