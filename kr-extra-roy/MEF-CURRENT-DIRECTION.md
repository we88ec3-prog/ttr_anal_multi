# MEF 目前開發方向：Server 提供內容，優先由 MEF 處理

2026-11-23：[出生定義 HP 圖形編輯](../design/scenario-content/MONSTER-HP-WORKBENCH.md)
可設定／留空恢復成長或AI，三類怪物實際保存與歷史配套通過；四TCP／兩個最終Host各88EXP
正常建隊通關同隊回村、三Release與782HappyPath通過。這是Server自有格式，非原生MEF或ClientAI移交。

2026-11-23：[全域Health彙總](../design/scenario-content/TOTAL-COMBAT-HEALTH.md)
已接首次建立、實際扣血與增援更新，不改既有返回條件。兩完整分支回包、Story控制、同版
獨立Host88EXP同隊回村、三Release與782 HappyPath通過，最終短鎖版收據cc04445a。原全域Health查詢
待辦縮小到已完成此getter；Boss／移除／AI的其他查詢、具體Client接口與人測仍分開。

2026-11-22：[FlagsCountReached反向索引](../design/scenario-content/FLAG-COUNT-DEPENDENCY-INDEX.md)
已完成逐父旗標派送、宣告順序閉合、入場繼承／重置與fork；完整兩分支TCP回包、Story循環
控制、同版Host88EXP回村及779 HappyPath通過。計量僅8對5候選列；其他消費者、全域血量、
具體Client接口與人測仍各自待辦。

2026-11-22：[Story明示初始清除分支](../design/testing/STORY-AUTHORED-EARLY-CLEAR-ROUTES.md)
以獨立r2初始組30秒起手AI驗證先清敵仍有必要護衛、逐輪重置與一次結算，三TCP／三Host、
5936／5984EXP及776 HappyPath通過。原r1下載及出招控制保持；地形匯出已接同版AI與SHA。
這是自有內容變體，不把它當未改r1、所有adapter或Client實機完成。

2026-11-22：[Story逐輪起手事件](../design/testing/STORY-ATTACK-START-NORMAL-ROUTES.md)
已補Q119實際出招→延遲護衛→逐訪擊殺EXP→一次結算與同隊回村，停止／三輪保存5936／5984EXP。
四條TCP／三個同版真實時計Host與776 HappyPath通過，收據60eae329。此前「Story新事件待驗」
為歷史批次界線；人測v2、自然新帳號、完整初始清除替代路線及其他未完功能維持各自待辦。

2026-11-22：[RAID1～3起手事件](../design/testing/RAID-ATTACK-START-NORMAL-ROUTES.md)
已由實際頭目起手接延遲護衛，三份保存配套、六條TCP與三個同版獨立Host正常通關；
一本書／CP3000及正常回廣場保持，776 HappyPath與三Release通過，收據8f2939a5。
這補上RAID新事件工程路線，不提高Story新事件、指定v2、自然新帳號或Client自主AI狀態。

2026-11-22：[普通狩獵場配套部署](../design/scenario-content/NORMAL-HUNTING-BUNDLE-DEPLOYMENT.md)已接固定普通catalog，實際瀏覽器三版用同版獨立真實時計Host完成76EXP入庫／同隊回村，兩巡邏版另驗移動前0016位置。15個普通Case的配套／slot領域測試及771 HappyPath通過；其他Case遊戲／指定v2／自然新帳號仍各自待驗。

2026-11-22：[巡邏路線圖形編輯](../design/scenario-content/PATROL-ROUTE-WORKBENCH.md)可從選取怪物建立AI副本、編排／排序／移除路點及匯出同版配套。瀏覽器三版、歷史保持、六路下載檔正常TCP各76EXP回原村同隊及756 HappyPath通過；新三版的獨立Host與指定v2各自待驗。

2026-11-22：[巡邏屏障繞路](../design/scenario-content/PATROL-BARRIER-ROUTES.md)已從既有追擊／回位延伸至平時巡邏，保留路點順序、共用搜尋上限與追擊圈。原BND320位置、兩路正常TCP繞路及88EXP通關、獨立真實時計Host同隊回村、756 HappyPath通過；仍是Server二維路線，未提高Client自主AI／3D門或人測狀態。

2026-11-22：[延遲門檻與父旗標索引](../design/scenario-content/DELAY-THRESHOLD-INDEX.md)保留三種起算／原phase與source順序，完成四個新正流程、完整兩分支舊新版TCP、同版真實時計獨立Host88EXP同隊回村及752 HappyPath。每路頭目房候選槽下界870／851對52／46門檻比較是工作量，不是CPU節省或Client卸載；其他combat時計／全域血量與具體接口分開接續。

2026-11-22：[波次血量事件索引](../design/scenario-content/WAVE-HEALTH-EVENT-INDEX.md)已把原每poll重掃改為生成／已接受扣血更新，保留死亡分母與原回報phase。獨立參考、完整兩分支TCP回包（只正規化隨機wireAlias）、同版獨立Host88EXP與748 HappyPath通過；每路頭目波原295成員訪問，改為登記4／HP更新15，非CPU／Client卸載量。官方格式搜尋維持退出目前功能目標，仍按下方已確定方向開發具體接口。

2026-11-22主線接續：[正常TCP／Host通關](../design/scenario-content/STORY-STRUCTURED-LOOP-TCP-ROUTES.md)、[主線循環政策配套](../design/scenario-content/STORY-LOOP-WORKBENCH-DELIVERY.md)及[資源／索瑪防禦延續](../design/scenario-content/STORY-LOOP-OWNER-CONTINUITY.md)已另有完整工程收據；舊核心-only／工作台OPEN為當時快照。指定v2、自然新帳號及其他效果／具體Client接口仍分開，不改歷史原稿認定。

2026-11-22：[分支區段動態循環](../design/scenario-content/STRUCTURED-BRANCH-LOOPS.md)已接正常Case693入口，同場兩／三輪交替不同岔路並重啟機關／延遲，四路保存104／120EXP回原隊，700 HappyPath及三個Release通過。宣告4個body成員但每輪只走3間房，沒有把互斥岔路都計EXP。分支管理端／配套仍待接續，NOT_NATIVE_MEF與Client移轉未知保持。

2026-11-22：[完整配套Host啟動](../design/scenario-content/STRUCTURED-LOOP-BUNDLE-STARTUP.md)已從指定清單／SHA重驗profile、關卡、AI、原BND及界限，再啟動真正隔離Host驗設定。三／四輪、關閉、改名四個配套及舊整合控制五次通過後停止；699 HappyPath、三個Release與關閉版本88EXP正常TCP通過。這仍是NOT_NATIVE_MEF；原生分析、Client移轉、其他adapter與巢狀流程尚未完成。

2026-11-22：[循環管理工作台](../design/scenario-content/STRUCTURED-LOOP-WORKBENCH.md)已補專用profile、條件／輪次／重置保留旗標編輯、Server預覽及不可變版本ZIP。實際下載三／四輪及瀏覽器改名配套五條TCP保存108／128／148EXP回原隊，696 HappyPath與三個Release通過；舊配套控制不變。這是Server-owned NOT_NATIVE_MEF，沒有Client CPU卸載。新匯出版本Host啟動預檢、巢狀／其他adapter與原生／Client驗收仍開放。

2026-11-22：[結構化循環](../design/scenario-content/STRUCTURED-LOOPS.md)已在執行中依權威旗標或上限重訪同node／離開，並接SCC、有界狀態條件與獎勵分析。相同Case693配套由正常機關選擇走兩／三輪，再走兩條原分支，各保存108／128EXP回原隊；694 HappyPath及三個Release通過。這是Server-owned NOT_NATIVE_MEF，沒有把生怪／AI移交Client。Admin完整交付、其他adapter、巢狀流程與實機仍待完成。

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
2026-11-22 網路整合：[完整副本TCP正流程](../design/testing/MEF-INTEGRATED-TCP-ROUTES.md) 兩條Case693分支已經正式登入／primary gateway的真正loopback socket通關回村，含機關、存活頭目階段、每路5枚子彈清理與88EXP保存。此為準備角色及受控制時計、同程序正式Server元件，Client／另行部署Host實機與全新帳號升級仍分開待驗。

2026-11-22 開發整合：[怪物投射物視覺adapter](../design/scenario-content/MONSTER-PROJECTILE-VISUALS.md) 已把既有Server直線飛行接到0094／速度selector／001A生命期；獨立Case693配套兩路正常入口各5枚子彈建立／清除，88EXP通關回村，648 HappyPath通過。效果可見性與速度仍待指定v2人測，未修改Client，碰撞／傷害仍由Server判定。

2026-11-21 開發整合：[Case693 完整副本](../design/scenario-content/MEF-INTEGRATED-DUNGEON.md) 已將計時／依序波次、頭目血量階段、消耗機關、兩條分支與結算串為同一內容；兩條正常廣場建隊至回村的原 BND 離線路線通過，640 HappyPath 通過。自訂 schema／NOT_NATIVE_MEF，指定 v2 實機、TCP 端到端仍待驗，不提高原生容器完成狀態。

**2026-11-18 使用者最新指示；適用 `extra/roy1` 的後續 MEF 分析與規劃。**

本頁是目前研究入口。最新 P0-3～10 深入分析與種類整理在 [MEF-P0-level-execution-20261118](MEF-P0-level-execution-20261118/README.md)；前輪20類關卡全表在 [MEF-level-functional-closure-20261118](MEF-level-functional-closure-20261118/README.md)；能力與執行位置基礎見 [MEF-server-provided-capabilities-20261118](MEF-server-provided-capabilities-20261118/README.md)。歷史包保留原始證據與當時結論；遇到「是否必須還原官方 MEF」「Server 責任是否排除 MEF」「哪些項目阻塞所有自製內容」的方向衝突，依本頁與本輪報告解讀。

## 已確定的目標

1. **MEF 開發屬於 Server 開發。** Server 提供、選擇及管理 MEF 內容；生怪、戰鬥判定、敵群清空、開出口、任務結算、獎勵與進度保存均在此開發範圍。
2. **能用 MEF 處理的優先交給 MEF。** 分析每項功能的規則、排程、執行、觀察、回報與保存，不因標示「Server 負責」就把整項排除於 MEF。
3. **以可實作能力為目標。** 官方 `.mef` 檔案、官方容器與格式復原不再是研究目標，也不作自有 MEF 開發的共同門檻。來源標籤 `NOT_NATIVE_MEF` 僅區分自行設計與原生事實，不表示自有內容不算 MEF 開發。
4. **區分執行位置及實際收益。** Client 執行的 MEF／native 效果可承擔本地排程與運作；Server 執行的 MEF 規則可集中關卡邏輯、減少硬編碼，但不能直接算成 CPU 已移到 Client。節省量須以實際流程量測。
5. **只保留具體接口缺口。** 例如某個普通怪物事件未能傳入 Lua、某個原生指令不回傳物件 ID、現有結算 adapter 尚未讀取新 MEF 規則。不要再用「缺官方 MEF」概括這些不同的工作。

## 歷史結論如何使用

- 既有 BIN／資源證據、ABI、作用對象、生命期與 loader 結論仍可引用。不能因目標改變就把空操作說成有效、把顯示傷害說成扣血，或創造原件未證的 wire。
- 舊版 P2 官方格式搜尋改為**退出本次目標**，不是已復原；既有搜尋紀錄不必重做。
- 舊版普通場景背景 Lua（B）缺口只約束「保持普通場景操控且常駐 Lua」這個 profile；有限 Q 與 Tutorial 的已證入口仍可用。
- 舊版特定 Q119／模型／UI 資源缺口，僅約束真正依賴那些資源的內容；不能阻擋不使用那些資源的新 MEF。
- 既有 Server 功能與驗證收據要復用。新 MEF 還沒接入，不等於整個背包、任務或存檔功能從未實作。

本頁不變更正式 Task owner、RR、T01 驗證、S00 規格狀態或遊玩驗收；原件唯讀及分析與執行分離仍依共用指示。使用者已指定工作分支 `extra/roy1`，不另開分支。

## 最新關卡分析補充

- 2026-11-22：[怪物招式起手訊號](../design/scenario-content/MONSTER-ATTACK-START-SIGNALS.md)
  將實際Server起手接入MEF旗標、頭目增援與圖形工作台；Case693來源／保存版兩分支及
  獨立Host88EXP同隊回村，776 HappyPath。提前擊倒有明示替代來源，不等同起手。
  新事件Story／RAID、人測v2及自然新帳號另待驗；官方格式仍不作功能開發門檻。

- 已完成20類關卡功能的有界分析；實際67份配置的圖／旗標和BND分層稽核，進度、缺項、優化分列[玩家進度](MEF-level-functional-closure-20261118/PLAYER-PROGRESS.md)。這些包含歷史與候選，不等於67個已部署可玩副本。
- 原生 `CSL.scn` 有保存／讀回seen紀錄的路徑。舊「一次／Client epoch」只足作Server派送預算，不保證重啟後未看或callback必跑；003F也可來自seen-skip。[原件補證](MEF-level-functional-closure-20261118/finite-handoff/report.md)
- Q119清場演出後的地圖／完整點集重建會換代；較早的本地setter不保證保留。沿用已提交Server MEF旗標投影到新快照；只有需要多步演出才新增有限插播hook。
- 現有scenario JSON／typed規則可以直接作MEF開發，不強制新建格式。公開範例缺口、實作缺口、特定Client可見操作與新玩法擴充分開，不能互相代換。

## P0-3～10 深入分析後的採用補充

- 已直接讀固定 Server `e88ac0a` 原碼核對出生、行為／戰鬥、時計、清場與轉場；既有巡邏、追敵、返家、選招、傷害及投射物能力可接 Server MEF。原碼實作、Client 原件、自有設計與實機結果分層記錄。
- 本地 Lua 與封包建立的 CMonster 初始化不同；普通 group writer、signed 速度界線與 Client 原生投射物鏈已補證。group 與 relation key 不同；完整普通 Client 自主 AI／命中下放仍另需接口。[生怪與戰鬥](MEF-P0-level-execution-20261118/actors-combat/report.md)
- 波次 timestamp 換算與 NodeDelay／ClearDelay／RegionHeld 的 elapsed 比較不能一律合成同一公式。主線／一般副本的清場、功能測試場返回及一般副本擊倒經驗處理有各自 gate；較精確原碼結論優先於舊概括。[規則與時計](MEF-P0-level-execution-20261118/rules-scheduling/report.md)
- 補齊公開作者範例；固定輪數可用逐節點展開，同房連戰仍用增援。作者 ID 必須接相容 catalog／selector，不能忽略既有主線 override 的限制。
- Map635 有8格真封口的新候選，會移動出口、縮小半徑；只證所列Server二維地形／overlay。另找到6個門模型的CEventObject狀態consumer，實際motion開關語意與Client動態碰撞仍分開。[門與轉場](MEF-P0-level-execution-20261118/gates-transitions/report.md)
- 最新Portal adapter在有ClearScenes或未預註冊出口時走完整重建；全預註冊且無該演出才走點狀態更新。不能把單次setter路線的限制外推成所有內容禁止ClearScenes。
- [12類MEF](MEF-P0-level-execution-20261118/MEF-TYPES.md)是可組合的玩家用途分類，不是12種原生檔案格式；Server規則、有限Q、Tutorial與原生持續效果依各自條件選用。
