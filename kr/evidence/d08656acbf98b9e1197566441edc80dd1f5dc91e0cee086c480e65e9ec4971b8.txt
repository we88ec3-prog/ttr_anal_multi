# T07／roy：一般副本→村莊與廣場往返介面

待整合／有界靜態查證；未實作完整往返、未完成遊玩驗收。來源原BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。工具：既有REA6.5.0／Ghidra12.1.4 bulk，Python3.10.6、Capstone5.0.7只核對原檔bytes。每次closure_probe均重新核對原BIN雜湊，無新反編譯／遊戲執行。

## 原生工具觀察

| 入口／位址 | 查得行為 | 限制 |
|---|---|---|
|005F／4B99C0 type2|建立4C46F0，再4B7D50安裝|005F自己的type域；不得用0069 type值替換；不能因此猜完整副本封包|
|4C46F0|基底4ADD50後寫C073B4 vtable，D6A674=53434546（SCEF）；原生類別Scene::CScenarioField|不是TUTO；替換場景會失去舊物件，教學第一戰需保留coroutine的例外仍見既存tutorial-lifecycle契約|
|C073B4+10→4C4750|現controller非空且kind3：544F50重用；其他非空種類：virtual+28清理、virtual+0(1)解構，再分配200bytes、547390建構並virtual+24|同kind仍會清控制槽，不代表舊綁定保留；新分配失敗並無安全恢復保證|
|547390|CFormationController vtable=C0FA14；FBA7AC=3|只確認控制器生命週期與種類，不展開自由編隊角色清單／綁定欄位（T08/T02待確認）|
|4C4750尾段|UI manager狀態不等7時將pending值設7；已等7則58A9A0|7是此UI manager狀態，不是場景type或村ID；不等於編隊UI已開|
|C073B4+14→8DC2F0|xor eax,eax;ret，為空退出hook|不能把此hook當任務成功、劇情終止或actor清理；清理可能位於後續新場景初始化|
|C073B4+0→4C5940|改回CPacketProcessor vtable；flags bit0時釋放物件|只證明場景物件解構，不代表coroutine或每個manager狀態都已同步|
|0014→4C5930→scene virtual+2C|Scenario槽為4C4910，tail jump到4B2570；CSquare槽直接4B2570|對目前場景生效。4B2570寫目前controller+4=1；非cutscene時才清全域輸入bit0；沒有玩家／map成功檢查|
|0012／4B24F0|CCheckPointMgr清理→544F50控制槽reset→讀DWORD+2→T06 4DF510|單獨reset不等同重新安裝、不保證清所有actor。相同map selector仍先reset槽位|
|0069／4B9090 type7/23/24|4BBB70 CSquare→4B7D50；4BBC10建立／重用kind2 CSingleController|沿用既有T07契約，不猜每type的村莊用途及尾兩byte值；CSquare init也有前置有效controller要求|

共用4B7D50同步順序：舊場景virtual+14→舊場景virtual+0(1)→場景指標清零→寫新場景→新場景virtual+10。Scenario→CSquare時舊exit本身不清理；CSquare init會清理已追到的manager容器、現controller，並換回Single。CSquare→Scenario時舊Square exit與新Scenario init均不能省略。原生CSquare核心沿用[T07→T06介面](../../T07-T06-INTERFACE.md)，未重做。

4C46F0另在第二層handler table明示0014→4C5930；0012未覆寫則透過4C4670的fallback到基底4FDA30。上述vtable只取C073B4起首12 DWORD；後面鄰接vtable／RTTI字不當作同類槽位。bulk沒有獨立4C5930函式列，因此以原BIN短跳板bytes核對，沒有重新反編譯。

## 交給Server的開發約束（分析者推論）

每次跨場景／同場景換map，都應把reset後的控制槽視為需要重新完成有效綁定；不能先送新角色再用0012補載地圖。最後有效install/reset後的玩家描述、綁定、ready與劇情解鎖應屬同一次轉場。ready只開局部旗標，不能替代T08綁定、T09合法位置及劇情結束的解除條件。這是從清理副作用推導的偏序，不宣稱官方完整封包序列。

建議Server以自身轉場識別／階段去重，保留目前目的地、來源及已提交狀態，拒絕舊回報在新場景重複完成任務；這是重建設計，不是原版協定中已證的generation欄位。任何新請求尚無合法目的地參數時保留現狀並記錄原因，不用完成quest15或重播第一段劇情當作通用往返機制。

| 目標階段 | T07已交付 | 尚需介面／批准範圍 |
|---|---|---|
|第二段後自由編隊→副本|一般Scenario安裝／kind3控制器、reset／ready生命週期|T14第二段結束的合法啟動條件；T02編隊與開始封包；T08可用角色／空預選與生成綁定，已提問待答覆|
|副本完成→村莊劇情→可操作|Scenario→CSquare清理與切回kind2的偏序|T14勝利／任務提交及村劇情終止條件；T06/T09村map／合法出生位置僅引用既有成果，新解析另詢問|
|廣場→村莊→廣場，重複往返|CSquare安裝、0012 reset、0014 ready可引用；同map也會清槽|合法旅行請求與目的地context、NPC／傳送入口及T08重綁資料未閉合；若需新增其他Task解析先向使用者確認|

往返恢復不以再打一次教學或重接quest15為前提；具體解鎖政策仍待任務／旅行介面證據，不能由影片補猜。村莊選擇、地圖selector、0069尾欄位不能互相取代。現有T06 Map182→town001D／BOUNDtown001、183→town002D／BOUNDtown002是資源索引引用，不自動證明TownID／村名／出生座標配對。現用Map511廣場亦不能當官方Town5映射證明。

## 影片與驗收邊界

影片9:19的三個空出戰欄位已直接觀察；11:10村莊讀取、12:27村落劇情已直接觀察，詳見[影片紀錄](VIDEO-OBSERVATIONS.md)。畫面不含封包、官方勝利規則或自由往返證據。v7只已有使用者確認廣場NPC兩種互動與對話後移動；v8未完成第二段／編隊／副本／進村，不提升為可測完整版本。本輪不改client，不啟動Server或遊戲，也不要求目前不方便的使用者測試。

## 保存證據

本批raw/pseudo複本及帶來源SHA索引在../evidence/cache-022702445120.json、cache-022815785211.json、cache-022827531561.json、cache-022900903950.json；4C5930的not_found明示保留。位元組在scenario-ctor-roundtrip.json、scenario-vtable-roundtrip.json、scenario-lifecycle-roundtrip.json、ready-dispatch-roundtrip.json。STATIC-CHECKS.json的8項局部核對通過，只驗證所述vtable／跳板／kind常數，未做遊玩驗收或全域清理完備證明。原raw保留REA Evidence與偽碼的不完整呼叫慣例限制。
