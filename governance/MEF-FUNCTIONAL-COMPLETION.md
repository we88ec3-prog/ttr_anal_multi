# 關卡／MEF功能完成追蹤

2026-11-22追加：[旗標數量反向依賴](../design/scenario-content/FLAG-COUNT-DEPENDENCY-INDEX.md)
依新旗標只排受影響的條件列，保留原宣告順序固定點、loop重置及fork隔離。三新正流程、
舊／新版兩條完整TCP回包對照、三條Story循環控制及同版獨立Host88EXP同隊回村通過；
三Release與779 HappyPath通過，收據6257be28。所選候選列下界8對5是工作量，不是CPU節省。

2026-11-22追加：[Story初始組先清除的作者範例](../design/testing/STORY-AUTHORED-EARLY-CLEAR-ROUTES.md)
原r1保持實際起手控制；另存r2只讓初始組使用30秒起手AI，血量／傷害／護衛／獎勵保持。
停止／三輪正常清除分支保存5936／5984EXP、一次Q119及同隊回村，三TCP／三同版Host、
三Release與776 HappyPath通過，收據4c2279b4。修正Story地形預檢漏讀配套AI，舊命令保持。
這不是未變更r1的先清除證明；普通Case693／RAID完整替代分支及v2仍各自待驗。

2026-11-22追加：[Story每輪起手與護衛](../design/testing/STORY-ATTACK-START-NORMAL-ROUTES.md)
Q119首圖每輪實際起手接0.4秒護衛，四旗標隨lap重置；正常停止／三輪上限保存5936／5984EXP，
一次Q119結算、Q120游標及同隊回村。四條TCP與三個同版獨立真實時計Host（含舊停止對照）通過，
原版5932／5972保持，三Release零警告／錯誤、776 HappyPath通過，收據60eae329。
Story／RAID／普通Case693起手事件各有自己的工程路線，指定v2及自然新帳號仍待驗，整體目標未完成。

2026-11-22追加：[RAID起手事件正常通關](../design/testing/RAID-ATTACK-START-NORMAL-ROUTES.md)
補齊RAID1～3先前僅接線的缺口：各以實際指定頭目起手觸發0.5秒增援、清完護衛結算。
三份標準工作台保存／配套、六條原版及新版TCP、三個同版獨立真實時計Host均通過；
各一本書、CP3000、角色／裝備／主線保持並回廣場。三Release與776 HappyPath通過，
收據8f2939a5。早期不同DLL的Host1/2保留但不採入最終收據，Story新事件與指定v2仍待驗。

2026-11-22追加：[怪物招式起手訊號](../design/scenario-content/MONSTER-ATTACK-START-SIGNALS.md)
將實際出招接入波次／旗標延遲與圖形工作台。Case693整合副本兩分支、四條TCP及保存第三版
即時Host均88EXP保存／原村同隊返回；提前擊倒走明示替代來源，無虛構起手。
三Release與776 HappyPath通過，收據bfbe2cf4。新事件Story／RAID與指定v2待驗，完整目標持續。

2026-11-22最新：[普通狩獵場配套獨立部署](../design/scenario-content/NORMAL-HUNTING-BUNDLE-DEPLOYMENT.md)
補普通catalog匯入入口，保留loop入口；同一瀏覽器三版以同版真實時計Host完成76EXP入庫／同村同隊返回，
兩巡邏版有玩家輸入前0016證據。15普通Case配套／slot領域測試、771 HappyPath與三Release通過；
其他Case完整Host／指定v2及自然新帳號未外推。收據aeac442e，原件／現用服務保持。

2026-11-22最新：[巡邏圖形工作台](../design/scenario-content/PATROL-ROUTE-WORKBENCH.md)
補路點／綠線、增刪改排序、獨立AI副本與同版交付。瀏覽器三版／歷史讀回、HTTP精確ZIP／AI、
實際下載六路TCP76EXP同隊回村及756 HappyPath通過；收據61799a2c。這批採原76EXP範本，
不混稱前批88EXP整合內容；新三版獨立Host／Client待驗，原件／現用服務不變。

2026-11-22最新：[巡邏旗標屏障繞路](../design/scenario-content/PATROL-BARRIER-ROUTES.md)
補平時巡邏遇障礙停住的缺口；共享原追擊／回位搜尋預算與追擊圈，開門／接敵／牽引丟棄舊路。
原版BND320位置、接近前每路30筆真實0016繞路回包、兩路TCP88EXP及獨立真實時計Host
88EXP同村同隊返回通過。三Release、756 HappyPath；收據56ddf907。Server二維，Client3D門仍分開。

2026-11-22最新：[延遲門檻與父旗標索引](../design/scenario-content/DELAY-THRESHOLD-INDEX.md)
保留節點啟用／清場位置／父旗標三種起算及原派送順序，新增四個正流程。
舊／新版完整兩分支TCP與同版真實時計獨立Host88EXP同隊回村通過；752 HappyPath、
三Release通過。頭目房候選下界870／851對52／46門檻比較是工作量，未宣稱CPU節省。
其他combat時計、全域血量查詢與具體Client接口仍分開；收據95282d82。

2026-11-22最新：[波次血量事件索引](../design/scenario-content/WAVE-HEALTH-EVENT-INDEX.md)
完成生成／HP變更彙總、死亡分母與原派送phase；三個新正流程、完整兩分支舊／新版TCP、
同版獨立Host88EXP及748 HappyPath通過。完整回包只正規化已查明的隨機wireAlias，未宣稱原始SHA相同。
頭目房295成員訪問基準對4次登記／15次HP更新是工作量，不是CPU節省或Client卸載。
官方容器復原依[目前方向](../kr-extra-roy/MEF-CURRENT-DIRECTION.md)已退出共同門檻，不能當目前全部MEF功能阻塞。

2026-11-22主線後續：[正常通關](../design/scenario-content/STORY-STRUCTURED-LOOP-TCP-ROUTES.md)、
[主線循環工作台／政策交付](../design/scenario-content/STORY-LOOP-WORKBENCH-DELIVERY.md)、
[角色狀態延續](../design/scenario-content/STORY-LOOP-OWNER-CONTINUITY.md)已完成各自正常工程驗證。
下列742核心批次的TCP／配套OPEN維持歷史快照；新收據不回填舊檔，Client／自然新帳號仍待驗。

2026-11-22最新：[主線循環接入核心](../design/scenario-content/STORY-STRUCTURED-LOOP-ADMISSION.md)
增加明確Story模式、強制玩家資源延續、逐訪原敘事游標與最大獎勵範圍驗證。
四個隔離SQLite正流程證明回跳時保存索引、一次任務完成及已即時入帳的擊殺EXP不重算；
Q119候選原BND預檢、隔離Host設定8訪、三Release及742 HappyPath通過。
這批仍PARTIAL：正常Story-loop TCP／獨立Host完整通關、工作台與配套交付及Client均OPEN，未套用狩獵場通關主張。

2026-11-22最新：[巢狀循環](../design/scenario-content/NESTED-STRUCTURED-LOOPS.md)補嚴格包含、
外層重跑時內層Invocation／Iteration重新起算、旗標scope與多層獎勵／訪問分析。
來源四條正常原BND TCP保存188/124/120/88EXP回原村同隊；三層21訪屬領域fixture，
管理端保存三版與原版停用／歷史不可變已驗。保存版獨立Host及738 HappyPath以最終收據為準。
下方「巢狀OPEN」是歷史快照；Client／原生、自主AI、自然新帳號及其他adapter未提高。
最終：實際r2四路TCP208/160/104/88EXP，獨立完整Host19訪208／6訪88均保存同隊回村；
三版HTTP／reader、舊雙區段四路與RAID1兩路控制通過。三Release與738 HappyPath通過，隔離服務全停止，收據33ce55f4。

2026-11-22最新批次：[RAID 動態循環與外部結算](../design/scenario-content/RAID-STRUCTURED-LOOPS.md)
擴充到固定 RAID1～3，提供獨立來源 profile、兩房重訪、正常機關停止、每輪旗標重置、
書／CP每場一次預覽與版本配套。[完整驗證入口](../design/testing/RAID-LOOP-COMPLETE-ROUTES.md)
分開來源三輪、保存四輪、同程序TCP、獨立Host、停用／歷史與指定v2待驗。
下方「RAID loops OPEN」保留為前批快照；本批未提高原生MEF、Client／自然新帳號、巢狀或其他adapter狀態。
整合波次／頭目階段／機關／分支／結算與回村仍以Case693交付為準，RAID正常成功回廣場。
最終六場獨立Host／六條保存版TCP均5或11訪問、書一次／CP3000／EXP250000保持；
三個停用版本與三個原RAID控制通過。當版Case69388EXP與Case695104EXP也都保存回原村同隊。
三Release零警告／錯誤、732 HappyPath通過，隔離服務全停止；收據8af8d441。

2026-11-22接續：[RAID獨立Host與成長修正](../design/testing/RAID-SEPARATE-HOST-ROUTES.md)已完成三基準／三配套真實時間五圖通關。移除RAID對其他成長關卡的隱藏依賴，保存Lv17實際HP900，各一本書、CP3000與EXP250000保持並回廣場；六條同程序TCP及Case695獨立Host104EXP控制也通過。三Release與729 HappyPath通過，隔離Host全停止。原碼定位與Server運行證據分開，Client／原生、自然新帳號及RAID loops仍OPEN。

2026-11-22接續：[RAID正常TCP與共用配套讀取](../design/testing/RAID-NORMAL-TCP-ROUTES.md)已驗三基準與三份歷史r1配套，六場30原BND載入、各一本經驗書、CP3000保持及正常回廣場。三個舊應用層控制及726 HappyPath通過。共用reader保留來源／版本／設定核對與RAID nullable EXP；舊loop入口限制保持。這仍是同程序測試時計，獨立Host／指定v2／自然新帳號與原生MEF未提高。

2026-11-22接續：[泛用配套獨立部署](../design/scenario-content/GENERIC-LOOP-BUNDLE-DEPLOYMENT.md)已支援695/699在repo外解壓目錄的同版manifest／scenario／AI匯入。四條獨立完整Host真實時間TCP通過104/160/224/400EXP、逐訪成本、一次結算存檔與回原村同隊；726 HappyPath通過。準備帳號前置明列，指定v2／自然新帳號、RAID/Story、巢狀與原生MEF仍OPEN。下方設定-only／待部署敘述保留為前批快照。

2026-11-22：[已知狩獵場泛用循環](../design/scenario-content/GENERIC-HUNTING-LOOPS.md)已開放315/693～706的explicit normal adapter並由來源推導編輯形狀。15 Case領域正流程、695/699兩村十條原BND TCP104/132/224/312/160/400EXP與成對管理／Host設定通過，726 HappyPath通過。新Case的獨立Host遊戲、Client／原生、RAID/Story及巢狀仍OPEN。

2026-11-22：[同場雙區段循環](../design/scenario-content/SEQUENTIAL-STRUCTURED-LOOPS.md)已把入口與分支接入正常Case693、獨立編輯／停用及配套。四路TCP124/160、實際下載2/4輪156及單區段136、三版Host啟動與獨立完整Host160EXP回原村同隊皆通過；709 HappyPath及三個Release通過。巢狀／其他adapter、Client／原生及自然新帳號仍OPEN。

2026-11-22接續：[獨立Host通關](<../design/testing/SEPARATE-HOST-DUNGEON-COMPLETION.md>)已由另程序的正常TCP完成舊整合88EXP及同一下載分支r2提前離開104／四輪上限136EXP，皆保存與回原村同隊。此為準備帳號／真實時間；精確timer快照仍引用先前in-process收據，Client／原生及其他副本維持OPEN。

2026-11-22：[獨立完整Host正常入口](../design/testing/SEPARATE-HOST-DUNGEON-ENTRY.md)已有舊整合與下載分支r2兩條跨程序TCP，走登入／廣場建隊／同隊進村／選關至Case693首圖啟用，使用真實時間且無內部world。隔離Host均停止；獨立Host戰鬥、機關、循環、頭目、結算與回村仍OPEN，不能以此入場證據宣稱完整通關。

2026-11-22分支管理接續：[分支循環工作台](../design/scenario-content/STRUCTURED-BRANCH-LOOP-WORKBENCH.md)已補獨立profile、正確body表單、三版HTTP配套與五路下載檔TCP，並由完整Host載入三版後停止。舊prefix五路仍通過；Client／原生、其他adapter、巢狀與部署Host遊戲驗收仍OPEN。

2026-11-22：[同場不同岔路循環](../design/scenario-content/STRUCTURED-BRANCH-LOOPS.md)已開放Case693分支body，逐輪交替3/6或6/3，保持新開關／延遲及逐訪成本，再走原頭目與一次104／120EXP回原隊；四路新TCP及四路舊前綴控制通過。15分析state只計每輪一條岔路、最多12實際訪問，700 HappyPath與三個Release通過；新Host設定預檢後停止。分支管理／配套、其他adapter／巢狀與Client／原生MEF仍開放。

2026-11-22：[指定配套完整Host啟動](../design/scenario-content/STRUCTURED-LOOP-BUNDLE-STARTUP.md)已支援清單路徑及SHA、固定來源profile／payload／設定核對、原BND與重算metadata，再實際啟動Host驗所有四個Case。三輪／四輪／關閉／瀏覽器改名配套與舊整合控制五次預檢均停止；新關閉版本正常TCP88EXP，其他四路108／128／108／148保持。699 HappyPath及三個Release通過，現行服務未換。原生MEF、其他adapter／巢狀流程與Client／部署Host遊戲通關仍開放。

2026-11-22：[動態循環管理工作台](../design/scenario-content/STRUCTURED-LOOP-WORKBENCH.md)已加入獨立Case693循環profile、輪次／旗標表單、無草稿寫入的Server預覽及版本配套。HTTP r1三輪／r2四輪保留舊ZIP，實際下載四條TCP保存108／128／108／148EXP；瀏覽器停止旗標改名並保存的配套另通過108EXP。舊兩個單房ZIP保持golden、prefix兩路128EXP保持正常。696 HappyPath、三個Release與預設視窗截圖通過，隔離Admin均停止。新匯出版本完整Host啟動預檢、Client、其他adapter／巢狀流程及原生MEF仍開放。

2026-11-22：[真正執行中結構化循環](../design/scenario-content/STRUCTURED-LOOPS.md)已接同node重訪、明確上限／保留停止旗標、SCC與狀態圖／保守獎勵分析、V2逐訪成本及正常Case693入口。同內容因背包或上限分別兩／三輪，四條TCP各保存108／128EXP並回原隊，19／24枚投射物清除；四條舊控制與六個舊編譯配套不變。694 HappyPath及三個Release通過，隔離Host設定預檢後停止。專用Admin profile／GUI／HTTP交付、其他adapter、巢狀流程及Client／原生MEF仍開放，整體目標保持進行。

2026-11-22：[本次整合副本交付](../design/testing/INTEGRATED-DUNGEON-DELIVERY.md)以既有Case693整合內容完成最新回歸：最小版及投射物版各兩條正常TCP分支，共四路各保存88EXP並回原村原隊。舊檢查器已接V2扣款訪次，六個節點訪次及庫存發布順序保持驗證。三個Release零警告／錯誤、689 HappyPath通過。既有玩法不是本輪重新新增；Client／獨立部署Host通關、原生MEF及更廣功能仍開放，未替換現行服務。

2026-11-22：[進段重置群組](../design/scenario-content/FLAG-RESET-SCOPES.md) 已能清除指定旗標、保留整場事實並追蹤歷史逆推失效。新Case693兩路各重新付款、88EXP存檔回原隊；四條舊TCP控制及六個編譯配套bytes保持正常，689 HappyPath與三個Release通過。檢查器已支援扣款後等待開關的延後開門，庫存順序仍驗。群組／訪次紀錄保存到結果；動態loop控制、SCC／獎勵分析及Client驗收仍開放。

2026-11-22：[節點訪次及機關V2](../design/scenario-content/SCENARIO-VISIT-IDENTITY.md) 已接Enter／fork／選擇／結果，機關提交綁目前訪次。V1表保留、歷史複製到空訪次，正流程驗相同run/node/key兩訪分扣；四條既有TCP（88／128EXP）逐圖對齊訪次及ledger，存檔回原隊，685 HappyPath與三個Release通過。這是動態loop基礎；同節點兩訪只在領域測試，TCP固定alias展開不算循環。旗標作用域、循環控制與Client仍開放。

2026-11-22：[旗標條件出口](../design/scenario-content/CONDITIONAL-EXIT-SELECTION.md) 已能依本場旗標真／假選定一個出口，保留至結算；同一Case693以31/33與31/35正常機關操作走兩路，各88EXP存檔回原村同隊。683 HappyPath、三個Release、原權重控制組及六個舊編譯配套bytes通過。這只是動態loop必要的分支原語；[循環DRAFT計畫](../design/scenario-content/DYNAMIC-LOOP-EXECUTION-PLAN.md)已核對訪次／旗標／機關ledger與現有EXP流程，動態loop仍未完成。NOT_NATIVE_MEF，Client與獨立Host遊戲驗收分開待驗。

2026-11-22：[關內出口權重工作台](../design/scenario-content/WEIGHTED-EXIT-WORKBENCH.md) 已提供來源旗標、逐出口權重、條件式比例及切回手動。瀏覽器改成出口6:3=2:8、改名同步、保存r1／手動r2及歷史r1再載入均通過；實際HTTP下載兩版四路TCP各保存88EXP回原隊。679 HappyPath、三個Release建置及窄視窗畫面存證通過，瀏覽器下載等待未確認完成、未列通過。NOT_NATIVE_MEF；動態loop／一般子圖、Client與獨立Host遊戲驗收仍開放。

2026-11-22：[關內出口權重](../design/scenario-content/WEIGHTED-EXIT-SELECTION.md) 已於清場且機關延遲旗標成立後，依當時合格出口6:4只選一次，保存run／來源／policy／ticket至結算；兩路正常TCP各保存88EXP回原村同隊，原手動雙出口控制組及六個舊編譯配套bytes保持一致。Host隔離預檢與三個Release建置通過，679 HappyPath全通過。NOT_NATIVE_MEF；指定v2、自然新帳號、獨立Host遊戲通關、分布與專用權重GUI仍待驗／待開發。

2026-11-22：[兩房重訪工作台](../design/scenario-content/FINITE-PREFIX-REPEAT-WORKBENCH.md) 已可選單房／前兩房、依保存版本預覽及下載配套。HTTP兩房2／3輪為108／128EXP，舊缺省單房ZIP與原golden bytes一致；實際下載三輪配套兩路TCP各一次128EXP保存回原隊伍。瀏覽器控制項108／96／128已驗、676 HappyPath通過；截圖擷取失敗未列版面驗收，Client與獨立Host遊戲通關仍待驗。

2026-11-22：[任務門檻正常NPC／TCP](../design/testing/QUEST-GATE-NPC-TCP-ROUTE.md) 已補Q117正常交接、Q2842接取／目標對話／交付，未預設完成紀錄。兩路門檻副本各保存700＋88EXP＝788增量並回原村同隊，任務仍Completed、主線索引1；674 HappyPath與建置通過。生產規則未改；Client、自然升級及獨立Host遊戲通關維持待驗。

2026-11-22：[有限兩房前綴重訪](../design/scenario-content/FINITE-PREFIX-REPEAT.md) 已有獨立計畫／mode與Case693 adapter。三輪logical11／12／13／14／10／1投影map3430／3431、chart10／1，重啟波次與三筆機關成本後接回分支頭目；兩路TCP各一次128EXP存檔回原隊伍，24枚投射物清理。674 HappyPath、新舊編譯bytes與Host預檢通過；Client回跳畫面與兩房管理端仍待驗／待開發。

2026-11-22：[有限重訪管理端](../design/scenario-content/FINITE-REPEAT-WORKBENCH.md) 已可由保存版本預覽次數及獎勵，下載含來源、計畫、配對與Host設定的可重現ZIP。r2保存後r1的2／3次匯出仍為92／96EXP，實際下載配套兩條TCP路線均一次96EXP存檔回原隊伍；671 HappyPath通過。瀏覽器與Client實機仍待驗，未換既有服務。

2026-11-22：[有限同圖入口重複](../design/scenario-content/FINITE-ENTRY-REPEAT.md) 已有固定SHA計畫、可重現編譯器與Case693正常入口opt-in。logical11／12／10投影既有map3430／chart10，各自拾取並消耗開門道具，接回原分支頭目後單次96EXP；兩條TCP路線通過、各24枚子彈退休，669 HappyPath通過。原件17窗重核／37來源保存；Client鏡頭／小地圖／latch仍待驗，新Ghidra逾時未列通過。

2026-11-22：[旗標後延遲](../design/scenario-content/FLAG-DELAY-SIGNALS.md) 已接正常poll時計、延遲鏈與節點／fork界線。Case693開關達標後1.5秒才開門、頭目階段後0.75秒門檻於下一poll才增援；兩條TCP路線各清理14枚子彈、保存88EXP回原隊伍。665 HappyPath通過；Client／新管理欄位／自然新帳號仍待驗。

2026-11-22：[多機關旗標條件](../design/scenario-content/FLAG-COUNT-CONDITIONS.md) 已接有限固定點、路徑可達性與管理端編排。Case693三開關任選兩個，三組各兩條TCP路線均在第二個後才送0048開兩出口，未按第三個保持未成立；各保存88EXP回原村同隊。662 HappyPath通過；Client、自然新帳號及新管理欄位瀏覽器仍待驗。

2026-11-22：[招式旗標條件](../design/scenario-content/MONSTER-ATTACK-FLAGS.md) 已接怪物選招與接近距離，並使用既有圖路徑分析驗證AI旗標來源。新Case693兩條TCP路線的同一活頭目由真實75%HP旗標切換兩階段招式；每路13枚子彈清理、保存88EXP回原村同隊。658 HappyPath通過；指定v2與CPU移轉仍未宣稱通過。

2026-11-22：[已交付任務條件](../design/scenario-content/QUEST-COMPLETION-SIGNALS.md) 已接正式授權存檔讀取與副本旗標。Case693新候選首圖要求Q2842已交付及消耗機關；兩條TCP正常路線各保存88EXP回原村同隊，655 HappyPath通過。Q2842為入場前準備紀錄；自然交任務、指定v2與新管理欄位瀏覽器操作仍各自待驗。

2026-11-22：[一般狩獵場入場權重](../design/scenario-content/HUNTING-ENTRY-WEIGHTS.md) 已接正常入場與管理端版本／ZIP。Stage462 Case693:694=6:4，每場只選一次並綁來源與run；4條固定選擇TCP路線及管理端實際匯出2條路線通關回村，652 HappyPath通過。這是自有MEF功能，NOT_NATIVE_MEF；分布、指定v2畫面與完整新帳號實機分開待驗。
使用者目前目標：完成關卡／MEF功能開發，不把取得官方檔案或復原歷史格式當前置。
自訂定義沿用自己的schema與副檔名，明示NOT_NATIVE_MEF；原生格式與傳檔相容性
是獨立研究事項。此表不是已完成宣告，也不以合成測試數量換算完成百分比。

## 2026-11-21 完整副本整合

2026-11-22 [TCP整合](../design/testing/MEF-INTEGRATED-TCP-ROUTES.md) 已補兩條完整副本的正常登入、交接、建隊、通關及同村返回實際socket證據。既有應用層證據保留；這關閉準備帳號loopback TCP路線缺口，不把同程序元件測試寫成部署Host或指定Client驗收。

2026-11-22 追加[投射物呈現配套](../design/scenario-content/MONSTER-PROJECTILE-VISUALS.md)：首次將既有怪物直線飛行接上已證0094／0000速度／001A；兩路正常入口各5枚建立與清除，保留88EXP及同村返回。這閉合Server視覺adapter實作，仍不等於Client效果、速度或原生MEF執行通過。

[Case693 整合副本](../design/scenario-content/MEF-INTEGRATED-DUNGEON.md) 已在同一內容組合波次、頭目血量階段、消耗機關、分支與結算；兩條正常廣場建隊至回村、原版 BND 應用層正流程各取得88 EXP且保存。640 HappyPath通過。此為準備帳號 OFFLINE_SYNTHETIC／NOT_NATIVE_MEF，不代表官方格式、全新帳號升級、TCP或Client實機完成；沿用既有能力，不以測試數換算整體百分比。

## 2026-11-14 extra/roy1 整合

2026-11-19：[RAID 配套單場正流程](../design/testing/RAID-NORMAL-ROUTE-INSPECTION.md)
補上三個基準與三個實際匯出稿的廣場建隊至成功返回／發書證據，使用準備角色、
一般裝備及正常 HP 卷軸輸入，合計 30 次原 BND 地圖載入。此為離線應用層，
未提高新帳號、TCP、Client 或原生 MEF 完成狀態。

2026-11-19：[RAID 1–3 工作台](../design/scenario-content/RAID-SCENARIO-WORKBENCH.md)
補上三組固定 RAID 範本、AI 配對及 Host 覆蓋稿載入。15 張原 BND 的編輯／匯出／
載入預檢已通過；既有入場等級、圖序、必要頭目與 CP／經驗書領域規則保留。
管理端已更新，但遊戲 Host 未換；新稿正常通關、Client 與原生 MEF 仍各自待驗。

2026-11-19：[一般狩獵場單趟正常入口](../design/testing/HUNTING-NORMAL-ROUTE-INSPECTION.md)
新增 41 條工程收據：15 個 Case 全部 37 條基準路線，加自訂 AI 與 81 EXP 匯出
版本各兩條。準備角色 4／Lv.15，第二村以前綴準備資格；廣場建隊至結果同室
回村均經應用層驗證。這不提升原生 MEF、Client 自主生怪或實機驗收狀態。

2026-11-19：追加 [已存檔背包數量旗標](../design/scenario-content/BAG-QUANTITY-SIGNALS.md)
的 Server-owned 契約與實作驗證。它只表示在目前副本曾持有指定數量，
不消耗道具、不涵蓋持續持有或任務交付。原生 MEF 載入鏈缺口維持，
未將一般戰鬥生怪／AI 移交給 Client。功能實機驗收另列 BQ-01。

S00 將 `be56ab2e6`、`2d9896d62`、`0a2503db0` 的研究稿與證據包保留於主線。以本機 KR 原 BIN 及 launcher EXE 重新核對 475 個原件視窗及 28 個錨點的位元組和 PE 映射；兩份 KR 原始 STP 的整檔 SHA-256 亦與來源相同。此處為 S00 限定核對，實機驗收與 T01 全面複核仍各自記錄。

| 問題 | 本次可採用的結論 |
|---|---|
| 何時能交付檔案？ | 啟動遊戲前，原版更新器可依相容 HTTP 更新清單下載 gzip 並寫入普通檔案。已有原件靜態呼叫鏈；實機落檔待驗。直接使用指定 v2 EXE 的既有測試流程沒有用到這條更新器路徑。 [交付時機](../kr-extra-roy/20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md) |
| 何時會解析原生 MEF？ | 仍未知。Client 有可達的 Lua 解析器與本機資源載入器，已追到 `MapList.TRIGGER` 的名稱存放處，尚缺從該名稱開檔、解析並執行的呼叫鏈。已檢查的遊戲 TCP 路徑也未找到原生 MEF 接收器。 [解析器與儲存](../kr-extra-roy/20261114-190624-chatgpt-web-roy1-MEF-parser-executor-storage.md) |
| 普通副本能接手哪些工作？ | `0047` 可選擇已配置的有限 Q 劇情，並由共用場景更新協程。Q 執行時可能清除控制器的移動與動作輸入。本地生怪 API 尚缺可供 Server 對齊的物件身分及普通副本的可靠死亡事件。現行生成、AI 判定與清場仍由 Server 處理。 [場景入口與生命週期](../kr-extra-roy/20261114-192949-chatgpt-web-roy1-MEF-entry-lifecycle-events.md) |

|功能需求|目前具體成果|未完成／可驗收的下一步|
|---|---|---|
|有版本及來源的內容定義|Scenario／MonsterBehavior JSON、SHA及唯讀目錄。[主線外部關卡檔](../design/scenario-content/STORY-SCENARIO-OVERRIDES.md)可逐任務覆蓋戰鬥編排並檢查來源|擴充條件與動作後持續維護 Schema 和契約。Q119 候選待實機|
|每實例事件與保存界線|Entry／聚合GroupCleared／InteractZ、圖序與結果提交。順序波次、定時與區域增援已有實機結果；條件出口與手動互動點已有合成驗證|分支、條件出口、手動互動及清場延遲待集中實機。未完成的副本依既有規則重登重來；完整3D機關與更多條件來源待開發|
|出生與怪物群|首兩圖與33個後續節點可由內容指定配置；換波保留玩家資源／冷卻。[旗標增援](../design/scenario-content/REINFORCEMENT-FLAGS.md)可由區域或互動觸發，[逐波清除](../design/scenario-content/WAVE-CLEAR-SIGNALS.md)可在指定波倒下後開互動或觸發增援|教學固定配置、其餘關卡的出生與出口幾何仍待核對；兩項候選待實機，正式關卡資料待編排|
|Client本地生成怪物|既有lb.CreateObjectEx可本地建立CMonster；與0007外部生怪是不同入口。第六參數可接現有控制槽，已知SubAI攻擊執行器會跳過模型1036|普通副本的合法啟動來源、生成物件ID對齊與同步待證；目前仍由Server發生怪封包。見[控制器掛接補證](s00-iterations/S00-20261113-MONSTER-LOCAL-CONTROLLER-BOUNDARY.md)|
|物種AI與個別參數|逐出生指定profile、追擊／定點近身、輪替選招與個別冷卻。v93實機確認追擊／回位。v99直線投射物後端已通過合成。[波次血量旗標](../design/scenario-content/WAVE-HEALTH-SIGNALS.md)支援在原波存活時觸發增援或互動|選招實機、投射物視覺／物種動作、多目標仇恨、物種召喚、特殊Boss資料與血量階段實機仍待驗|
|Client執行固定路段|單次目標＋Server待機排程已實作；v92人測停止彈跳、速度可接受（當次程序v10）|尚未併入戰鬥AI；自主抵達／取消條件未知，排程不算Client完成ACK|
|怪物巡邏路線|關卡可逐怪指定路點，接索敵、追擊、回位與巡邏恢復。巡邏怪追擊或回位遇靜態牆面可改走可通行路徑。Q119 有一般巡邏及繞牆候選|PT-01 至 PT-03 待實機。Q119 有靜態地形對照，動態障礙未接入。 [巡邏規格](../design/scenario-content/MONSTER-PATROLS.md)|
|既有劇情啟動與收尾|已知scene鍵交由Client序列執行|普通副本腳本入口與壽命、與清組／任務完成的正確關聯|
|出口生命週期|出口可預先關閉登記，勝利後更新再按 Z 換圖。清場劇情後可按已提交旗標重建整組點位。[清場後延遲旗標](../design/scenario-content/CLEAR-DELAY-SIGNALS.md)可控制出口與互動點|分支多點、清場劇情重建和延遲旗標待實機。入場標記已通過，正式特效待決定|
|換圖後玩家狀態|一般主線可由外部關卡指定延續 HP、SP、MP、定時回復與剩餘冷卻，涵蓋入場劇情後的戰鬥重建|Q119 的 SC-01 待實機。增益、連段、蓄氣與投射物延續未開放。 [外部關卡規格](../design/scenario-content/STORY-SCENARIO-OVERRIDES.md)|
|入場後計時事件|戰鬥開放後依關卡指定秒數設立旗標，可控制增援、互動及出口。Q119 第一圖有定時增援範例|ND-01 待實機。原版個別關卡的時間與配置仍待來源核對。 [計時旗標規格](../design/scenario-content/NODE-DELAY-SIGNALS.md)|
|Client自行開門|本地setter存在|能收到該instance清組事件且Server停發開門時仍能完成，尚未證實|
|旗標控制通行|主線可用既有旗標解除個別副本的屏障，適用 Server 移動、尋路、戰鬥與互動，並能同步既有 Client 點的開關狀態|GB-01、GB-02 待實機。Client 的 3D 門、動畫與本地碰撞待接。 [屏障規格](../design/scenario-content/FLAG-BARRIERS.md)|
|地形傷害區|主線可配置週期傷害，依玩家位置與旗標開始、重算或停用|HZ-01 待實機。Client 陷阱外觀及跳字待來源。 [地形傷害規格](../design/scenario-content/AREA-HAZARDS.md)|
|持續占點|可按區域停留時間設立旗標，接增援、屏障與出口。離區會重算未完成時間|RH-01 待實機。Q119 提供占點開門候選。 [占點規格](../design/scenario-content/REGION-HOLD-SIGNALS.md)|
|NPC／市場內容|市場配置獨立載入，三村商店已接共用交易與資產更新，銀行共用存提款。三村可穿戴商品已接裝備欄、基礎能力值及鐵匠商品外觀更新|待實機驗商戶點位、視窗、交易、裝備面板／外觀及傷害。強化與進階能力公式待接。 [三村市場](../design/scenario-content/TOWN-MARKETS.md) · [裝備規格](../design/scenario-content/EQUIPMENT-WEAR-WIRE.md)|
|通用內容執行器交付|有限typed事件與既有packet adapter|功能範圍足夠支援需求關卡，不能只搬常數便算完成|
|管理／編輯工作台|Admin.Web 提供[主線副本](../design/scenario-content/SCENARIO-WORKBENCH.md)、[一般狩獵場 15 個 Case](../design/scenario-content/HUNTING-SCENARIO-WORKBENCH.md)及[自訂 AI 配套](../design/scenario-content/SCENARIO-AI-BUNDLES.md)、[二維點位編排](../design/scenario-content/SCENARIO-MAP-EDITOR.md)與[波次管理](../design/scenario-content/SCENARIO-WAVE-EDITOR.md)：固定範本、關卡與 AI 同版保存、來源／條件／AI／BND 驗證與配對 ZIP。新舊草稿及原 BND 正流程已驗，編輯的 Case 693 結算與預覽一致，新 AI 已進入 Server 戰鬥執行器|完整規則流程／條件與三維編排、任意新 Case 部署及原生 MEF 尚未完成。未自動發布或宣告遊戲實機通過；使用者已取消另建簡易帳號頁|
|完整場景驗證|已有部分正常旅程人測及獨立工程收據|每個新增功能的來源／Server測試／Client人測分開驗收|
|馮德斯一般副本練等|Stage 462／463 的四個 Case、八條路線均用原版 BND 走完正常建隊、選關、生怪、戰鬥、頭目清除、掉落、拾取、結算與回村。每條路在出口前已入帳 56 EXP，結算後單場合計 76 EXP。Case 693 兩路各撿三張復活卷軸，其餘各一張。離線檢查器逐圖比對測試頁顯示、存檔與預期經驗。|指定 v2 Client 的正常入口、戰鬥、Space 拾取、升級顯示及回村循環待實機。見 [TS-37 批次驗收](../design/testing/S00-CONTENT-BATCH-TESTS.md)。|

輸入、連段、合法移動／命中、HP／資源／冷卻、帳號／任務／背包與資產提交，
仍屬共用Server領域功能；關卡可以描述何時觸發，但不得繞過權威與持久化。

後續實作者須區分兩種進度：內容定義取代了哪些逐關硬編碼；哪些原有Server
指令停止後Client仍完成操作。任何自動決策、完成ACK或官方格式沒有證據時保留未知。
功能開發不因此停下：用明確Server-owned定義與可驗接口推進，不偽裝成原生復原。
