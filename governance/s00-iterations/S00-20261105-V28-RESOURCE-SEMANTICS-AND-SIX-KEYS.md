# v28：資源語意、重複加級、反灰與伊莉西亞六鍵測試

## v27 GAME_RUNTIME_OBSERVATION

使用者回報技能測試OK、SP/MP回復OK、HP未測；技能消耗大於持有MP時圖示幾乎全黑，等於時反灰，小於時亮起，要求不足時應反灰；並要求可測伊莉西亞與其他角色所有技能，實際消耗也需與說明一致。v27 Server73081eef10ed01fe8f1efced1f13df09100e03c9／舊工作副本EXE SHA6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c。v27-human-result-snapshot保留本機資料。HP維持NOT_TESTED，不把圖示／實際耗量算已驗收。

## 確認缺陷與有限來源

1. 530890讀ACTIVEINFO hp/sp/mp到16B entry+0/+2/+4；530530/5305C0/530650分別讀該signed值。5CD520將它們分別加actor3C8/3CC/3D0，sum<0不可用。4B3090 kind2/3/4分別寫3C8/3CC/3D0，故typed34應為HP/SP/MP，舊候選HP/MP/SP錯置。normalized0000 code2/3僅寫3B4/3B8及child bar，不能自行當作完整HUD資源同步語意已證；保留歷史候選比例回覆，以typed為主。
2. 126 learned與127 preset同一Practice都level1。4E46D0/4E48A0把兩集合交41D5F0，81B7F0/7BB350只是append未去重，825FA0對SkillLevel modifier value相加，造成Client active level2而Server按level1扣。修為learned1 + enabled空preset（127=5B），保留學習權限只貢獻一次；不猜Level0安全性。其後12C選preset0，來源支持空集合沒有再加級。
3. 資源不足以int.MaxValue假冷卻會遮黑圖示。已支持技能的012A只發布真實剩餘CD，typed資源讓原生依資源反灰，Server仍檢查資源。等於成本時該原生resource predicate允許sum0，不能僅憑人測灰色推斷官方嚴格大於成本才可施放；可能另有CD／其他UI條件。晚到失敗action-only不強停，含明確moving bit的失敗row仍可開始／維持行走。
4. 按一級SkillActiveTable投影扣費，不再所有角色套同一35/30或80：Soma X50SP、Z+C90SP；現行Shubal候選X50SP、Z+C100SP；Isilia X35SP/30MP、Z+C80SP。rawCD/10秒保留既有Server候選，沒有正式單位完整還原。其餘角色／原Shubal X與matrix不一致、Soma/Shubal固定motion錯配仍待後續，不能因耗量修正宣稱全角色動作可用。

## 六鍵與全角色目錄

本地catalog含846Practice／469active L1／9角色1260matrix鍵；852個指定Table member原／工作相同。全角色motion join有1401motion、270active Practice-target、2408個明確ABF/ASD/Effect member原／工作相同；158有同stem但多變體、112無精確同stem，全部保留UNRESOLVED，未照數字或相似名字亂選。全量JSON及raw資料留本機，Git存工具/49KB摘要/來源hash。

這版只先開放伊莉西亞default matrix0/tier0六鍵空場候選，不等於全部30active或9角色完成：

|輸入|Practice|Active|motion候選|SP/MP一級消耗|
|---|---:|---:|---:|---|
|Z|49|29|101～107|0/0|
|X|50|30|108|35/30|
|C|51|33|109|60/0|
|Z+X|53|32|111|0/150|
|Z+C|52|31|112|80/0|
|X+C|55|35|110|175/0|

ABF motionID/ASD HeaderID與Effect路徑是資源事實；Practice filename同stem對到motion是明示有限join候選，尚非完整native activeID dispatch。舊Z+C109其實Sslash，改Surprise112／1.325秒；前輪「Z+C有反應」結果保留，但不能稱曾驗證正確招式。

測試頁新增IsiliaSkills，空Road191／MP SP1000，僅當前debug連線、learned六個level1、空preset，不寫正常任務勝利／獎勵或帳號技能；空場不自動清關或出傳送點。一般Road191與正常教學仍原三招/資源100。六招的命中時間、範圍、傷害、位移／多段完整規則仍為Server prototype，這輪先驗動畫及耗量，不能叫完整技能實作。

## 驗證與Client變更界線

57項Category=HappyPath通過59秒：correct typed位置、一級耗量、preset不再雙加、失敗技能明確移動row、六鍵各自motion/成本/回復、空測試場無敵人無勝利，及原TCP旅程。首輪50項有1舊offset期待20在kind4而失敗；改正kind3 SP20/kind4 MP100。六鍵建置曾有UTF編碼讀取與C#primary constructor型別編譯問題；修正後57輪又有1案例誤將owner actor視敵人，改以entity區分並補空場不ReadyToReturn，最後整批綠燈。未跑暫緩測試。

使用者另授權新Client開場／台版翻譯／字型版本，見../client-variants/20261105-zh-tw-v3/README.md；原版及v2不動。新EXE兩byte差異、文字only overlay、TC主字型補KR回退均靜態驗證，不當作原件或真人通過。

v28及新Client真人PENDING。先新啟動檔到廣場看NPC翻譯／字型，再選六鍵測試場依序各一次，不走出口；任何錯誤立即停。缺資源灰色可另選普通Road191 Z+C後觀察CD結束但資源尚不足時，不應再無限黑。HP回復仍待使用者之後實測。其餘角色與進階技能持續依catalog缺口開發，不以固定motion代替。
