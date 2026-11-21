# 有限兩房前綴重訪

2026-11-22，SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。延續有限入口重訪，新增
Case693 前綴 `[10,1]` 的明確計畫；原單房計畫、編譯器與mode保持原契約。
這是有限DAG展開，不是重用同一runtime節點的動態loop。

新計畫 `LOCAL_FINITE_PREFIX_REPEAT_PLAN_V1_NOT_NATIVE_MEF` 固定來源關卡／AI雙SHA、
Case693、sourceNodes=[10,1]、visits=1..16、VisitLocalRetainLast／PerVisit／
OnceAtOriginalResult。兩來源房間各有一個NextNode出口，不含Result／必要Boss。
先驗來源為完整七節點原圖序、無chart別名、入口10→1→3；不接受隱藏的外部旗標依賴。

前N-1輪各建立兩個新logical節點與encounterGroup，投影原chart10/map3430及
chart1/map3431；每輪最後一房接下一輪首房。最末輪保留原10／1及原旗標名稱，
才進入原3→5或6→4→2分支／頭目／Result。各輪的旗標producer和所有consumer
（含AI招式、計時鏈、波次、機關、屏障、傷害區）使用同輪namespace；最後原
旗標只表示最後輪。所有怪、波、機關、掉落、成本與擊倒／清場EXP按visit計數，
全關結算EXP只一次。既有換圖玩家狀態政策沿用，不新增資源延續或存檔續關。

輸出使用新來源種類SERVER_FINITE_PREFIX_REPEAT_PLAN，來源plan SHA寫入定義；
Scenario／AI／編譯manifest以LF輸出並可重現。編譯manifest列每輪每房logical／
chart／map及原／新最小最大獎勵。原來源bytes、單房候選與既有history保持不變。

正式Case693 adapter另以 `LOCAL_FINITE_PREFIX_REPEAT_V1_NOT_NATIVE_MEF` 明確
opt-in；驗證新別名只形成有限的10／1交替鏈並以canonical10結束，canonical
七節點不改圖序。Story／RAID／lab及原單房mode均不藉此開放兩房別名。
所有圖仍使用既有固定BND來源與幾何驗證，不能新增map或編造傳檔opcode。

Native限制沿用 [前批有界審核](FINITE-ENTRY-REPEAT-NATIVE-REVIEW.md)：0049 consumer
匹配合法chart key，沒有在已讀有界body內檢查前後鄰接；這不證明整體Client回跳
相容性。Server採用1→10回跳是本次設計，非官方原路線結論。原BND、點集、怪物／
掉落／投射物退休和owner重建仍走既有生命週期。Client鏡頭、小地圖、控制latch、
回跳畫面與操作待單獨人測；不把0014當完整Client完成ACK。

正流程需覆蓋2／3輪編譯、旗標只在最後輪形成、波次／機關重新開始、實際成本及
全部獎勵。固定候選走兩條正常建隊TCP路線至一次結算、保存、原村同隊返回，
配套與原單房編譯bytes核對。新增深度native查詢、Client、自然新帳號升級、
動態無限loop與暫緩的非正流程測試不列本批通過。

## 固定三輪驗證

plan SHA `d7cce0e394cc7a640710342d656dbea69eba615f6c43e3bfe4a550b1f9957732`；
Scenario SHA `ba415c0509427033fcba14ab76bc24f6eed8236916dfcc341163abe71401c1c5`；
AI SHA `feb5f781cedf07960651e31336a1df393caa4e7b1598425899aa6aa320c70398`。
Schema及分析／Server副本bytes核對通過，新三檔及舊單房三檔重新編譯都逐位元組相同。

兩條正常登入／primary／廣場建隊／入村／選關TCP路線的前綴為11→12→13→14→10→1，
map3430／3431、chart10／1各三輪，EXP累積4／20／24／40／44／60。第二房各有順序
與定時增援；首房各有一筆Product183機關扣款，node11／13／10三筆收據且最後輪才
形成entry-paid。消耗後背包183依序剩0／1／2，保留前輪第二房拾得的物品。

原後段兩個分支、頭目階段與結果都完成；各只一次128EXP、存檔及回原村同隊。
第二房是近身AI，故仍各24枚投射物建立／退休，沒有跨房殘留。初始檢查器誤設
應多於24枚，修正為內容實際的24後核對原收據，再以最終版本重跑兩路通過；
沒有改遊戲規則或繞過handler。Host最終獨立預檢確認新mode、四個有增援的節點
（12／14／1／2）與128EXP，關閉自己的Host，未更換現有服務。

機器收據見 [finite-prefix-repeat-validation.json](finite-prefix-repeat-validation.json)。

最終Release Host／Inspector／Admin.Web零警告錯誤；674／674 HappyPath通過，含新增三個2／3輪正流程案例。新計畫、Scenario與AI Schema核對通過。此編譯器批次最初使用CLI與獨立Host模式；後續[兩房工作台](FINITE-PREFIX-REPEAT-WORKBENCH.md)已提供保存版本的範圍選擇、預覽與配套下載。
