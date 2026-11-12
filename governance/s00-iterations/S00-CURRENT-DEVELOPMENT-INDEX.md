2026-11-13：[主線入場計時增援](../../design/scenario-content/NODE-DELAY-SIGNALS.md)可在劇情結束、正式開放戰鬥後計時，支援不清初始怪即觸發增援。372 項 Server 正流程合成通過，Q119 範例通過 36 張地圖預檢。[ND-01](../../design/testing/S00-CONTENT-BATCH-TESTS.md) 已累積待實機，可與 SO-01／SC-01 同輪驗收。本機版本未替換。

2026-11-13：[主線換圖資源延續](../../design/scenario-content/STORY-SCENARIO-OVERRIDES.md#同一副本內延續玩家資源與冷卻)可逐關卡啟用，涵蓋入場劇情後的戰鬥重建。371 項 Server 正流程合成通過，Host 編譯與 36 張地圖預檢成功。[SC-01](../../design/testing/S00-CONTENT-BATCH-TESTS.md) 已累積待實機。Client 本地生成與自主 AI 的驗證條件已補入[怪物控制界線](S00-20261113-MONSTER-LOCAL-CONTROLLER-BOUNDARY.md#與現行-server-路徑的對照)，候選未啟用。

2026-11-13：[主線外部關卡檔](../../design/scenario-content/STORY-SCENARIO-OVERRIDES.md)可綁定已驗證主線版本並逐任務載入戰鬥編排。Q119 候選與 36 張地圖通過正式讀檔預檢，370 項 Server 正流程合成通過。[SO-01](../../design/testing/S00-CONTENT-BATCH-TESTS.md) 待實機，未啟用。

2026-11-13：[波次血量階段](../../design/scenario-content/WAVE-HEALTH-SIGNALS.md)可用波次合計 HP 在戰鬥中觸發定時增援。369 項 Server 正流程合成通過，Host 編譯與圖 193 靜態座標檢查成功。[WH-01](../../design/testing/S00-CONTENT-BATCH-TESTS.md) 已累積待驗，未啟用。

2026-11-13：[逐波清除訊號](../../design/scenario-content/WAVE-CLEAR-SIGNALS.md)支援初始及具名波次。367 項 Server 正流程合成通過，Host 編譯成功。[WC-01](../../design/testing/S00-CONTENT-BATCH-TESTS.md) 已累積待驗，未啟用。

2026-11-13：[旗標增援](../../design/scenario-content/REINFORCEMENT-FLAGS.md)接入一般主線及共用測試場。順序與定時增援可要求實例旗標。365 項 Server 正流程合成通過，Host 編譯成功。[FW-01](../../design/testing/S00-CONTENT-BATCH-TESTS.md) 已累積待驗，未啟用。

2026-11-13：[清場後延遲訊號](../../design/scenario-content/CLEAR-DELAY-SIGNALS.md)接入一般主線與測試執行器。363 項 Server 正流程合成通過，Host 編譯成功，Schema 與資料雙庫一致。[CD-01](../../design/testing/S00-CONTENT-BATCH-TESTS.md) 為圖 193 的三秒延遲互動測試，尚未啟用或實機驗收。

2026-11-13：[普通怪本地建立與控制器掛接](S00-20261113-MONSTER-LOCAL-CONTROLLER-BOUNDARY.md)已核對三類 vtable、兩條場景初始化路徑及 20 個原件指令／資料視窗。已知 SubAI 攻擊執行器拒絕模型 1036。普通副本的本地生成觸發、實體身分與自主決策仍待證。正常建隊進村 NV-01 另列於[批次表](../../design/testing/S00-CONTENT-BATCH-TESTS.md)，與先前八項一併等候排程。

2026-11-13：Server 受擊後移動恢復候選（SFD-0017）通過 359 項正流程合成。短暫受擊保留最近明確移動意圖，明確放開則停止，已施放技能仍接管動作。實機另列 HR-01，候選未啟用。v99 投射物視覺仍待證。

2026-11-11 後續：[v99怪物直線投射物後端](S00-20261111-MONSTER-PROJECTILE-VALIDATION.md)準備完成，358個受影響HappyPath通過；飛行視覺／物種動作未核對，不新增人測入口、不套主線、不啟用Host。既有8項待集中人測與線上v96a保持原狀。

2026-11-11 最新接續：目前以關卡／MEF功能開發為目標，並非宣稱原生檔案復原。
線上v96a保留；[v97條件出口](S00-20261111-CONDITIONAL-EXIT-VALIDATION.md)與[v98手動互動點](S00-20261111-MANUAL-INTERACTION-VALIDATION.md)已準備、未啟用。
最新350個受影響HappyPath通過，Client實機結果仍待回。使用者目前無法測，統一在[批次測試表](../../design/testing/S00-CONTENT-BATCH-TESTS.md)累積8項，不逐列催問。
原生MEF、完整機關／道具條件、完整物種AI與跨圖效果等尚未完成。下方不同日期的版本、部署與來源描述保留為歷史快照，不能當作現行狀態。

2026-11-08 開發中更新：[共享房間、名稱與角色狀態](../../design/runtime-content/NORMAL-PARTY-DIRECTORY-CANDIDATE.md)私有main2428e3342f7f，106項正流程通過51秒，尚未部署。實際仍v44/PID30596，使用者稍後再測；全角色87項未開、3組新資源family仍無唯一可用變體。

2026-11-08 開發中：[共享正常房間目錄核心](../../design/runtime-content/NORMAL-PARTY-DIRECTORY-CANDIDATE.md)，私有main8da7e540，106項正流程通過；尚未接線／未部署。現行Host仍v44/PID30596，使用者稍後再測。

2026-11-08 最新：v44啟用（PID30596/source1e739c3c）；v43因008B/008C索引換算錯誤撤回。105項HappyPath通過，增加公開轉私人分支；使用者要求稍後一起測，實機待回。全角色仍87映射未解；公開房間目錄／加入繼續開發，不閒置。v10翻譯待測。

2026-11-08 最新部署：[v43正常一人建隊進村候選](S00-20261108-V43-NORMAL-VILLAGE-PARTY-CANDIDATE.md)，105項正流程通過，Host PID3552／來源3ac6b910，實機待回。v10翻譯一併短卡待回。全角色仍87項未開，公開招募目錄／跨連線加入未完成；不因正常旅程合成通過宣稱整體目標完成。

2026-11-08 最新：目前階段目標為全角色技能開放及正常建隊進村，見 [正常房間阻塞](S00-20261108-NORMAL-ROOM-VILLAGE-ENTRY.md)。v8 啟動失敗、v9 啟動部分通過但介面仍韓文；[v10](../client-variants/20261108-variant-v10/README.md) 改用已確認的直接 XML 文字讀取路徑，靜態檢查通過、人測待回。Server 仍 v42，以下舊版本部署／待測敘述為歷史。

正常主線補證：[角色成長／結算缺口](../client-variants/20261108-mainline-progression/README.md)。22任務原值已核對，19條超過固定顯示5級，第一風險Q120=8；RR-0014查EXP／level發布，不把debug補等級當自然升級。

2026-11-08：人測Q119公雞副本返回後已推進Q120，但等級8成長門檻未補齊，REQ-0019／GAP-PROGRESS-0001／RR-0014保持未完成；[回報](S00-20261108-V42-HUMAN-PROGRESSION-AND-TEXT-GAPS.md)。另v8翻譯候選已製作，645列UI、7714處任務顯示與9角色名，[來源與驗證](../client-variants/20261108-variant-v8/README.md)；REQ-0022人測待回，未修改任務數值。

2026-11-08：v42已批次啟用（PID7684），合併v39–41及怪物碰撞停止修正，105項HappyPath通過。來源內容仍為v34，資料庫無schema變更、已備份；[換版收據](evidence/S00-20261108-V42-DEPLOYMENT.json)。v42新帳號至馮德斯測試卡取代v38，結果待回；不能算新版人測通過。

2026-11-08：v41將10副本／33節點接入共用有限事件引擎，敘事Commit後才發布副本狀態。104項HappyPath及兩份真實內容靜態載入通過；[設計](../../design/runtime-content/STORY-EVENT-ENGINE-CANDIDATE.md)／[建置收據](evidence/S00-20261108-V41-BUILD-ONLY.json)。未部署，不代表原生MEF、完整波次、正式獎勵或新的人測通過。

2026-11-08：v40顯式副本配置已建置（未部署），[設計／轉換工具](../../design/runtime-content/STORY-PLACEMENT-CANDIDATE.md)及[102項正流程／33節點靜態載入收據](evidence/S00-20261108-V40-BUILD-ONLY.json)。保留已核對的v38 PID27096與待回測試卡；不是原生MEF或逐圖位置驗收。

2026-11-08：補齊[Client 額外實體追隨的既有證據接續界線](../client-variants/20261108-extra-control-boundary/README.md)，9原檔區段／4匯出來源核對；不等於敵方自主AI、MEF或傷害權限。RR-0013接續目標已收斂，現行Host不變。

開發準備：[v39後續主線共用AI設定](S00-20261108-V39-SHARED-STORY-AI-PROFILES.md)。補33個node的外部AI接線，先建置／驗證，不中斷v38測試；原生MEF未完成。

架構補證：[怪物AI／位置／傷害權限界線](../client-variants/20261108-monster-authority-boundary/README.md)。現行Server控制維持，原生Client完整自主AI／MEF執行仍未證；RR-0013由T13定向接續，未改Runtime。

目前接續：[v38 V矩陣／原生選列與跨列長按](S00-20261108-V38-CHARGE-ROW-BOUNDARIES.md)。v37三項操作通過；v38解除row2無col8而拒絕長V的Server限制，98正流程合成通過，v38已部署、短卡人測待回。兩次短V／長V同組仍是政策，未冒稱官方已證。

目前P0：[v37原生ForceState修正](S00-20261108-V37-FORCE-STATE-INPUT-RECOVERY.md)。v36人測無法移動／施放退回；改用原生FSM12而非000D循環19，95正流程合成通過，v37三項操作人測通過。兩次短V／長V同技能組仍是Server政策，RR-0012待補證；87映射缺口由RR-0011定向接續。

目前P0：[v36立即解除蓄力與長按V](S00-20261107-V36-IMMEDIATE-CHARGE-AND-HELD-V.md)。v35主線標記人測通過；v36已啟用，95正流程合成通過，長按氣散發／放開移動／圖示立即復原人測待回。全角色仍87項未開放。

目前P0：[v35主線標記／成功技能解除蓄力／全角色開放](S00-20261107-V35-NPC-MARKER-CHARGE-AND-SKILL-OPENING.md)。v34進村與移動人測通過、NPC標記退回；93正流程合成通過。動畫候選新增至156／243，剩87項未開，全角色技能工作未完成；正式結算仍有缺口。

主線接續：[爾勒梅斯村Town2主線](S00-20261107-TOWN2-MAINLINE-CONTINUATION.md)。v34已接Q133～144十二段敘事／6單人副本候選；整村實機與正式結算仍未完成。銀行／裝備／商店／掉落撿取依使用者要求排在其後。

最新：[v33＋v7、v31人測回饋](S00-20261107-V33-HELD-V-ANIMATION-AND-V7-TOOLTIPS.md)。MEF資料層外部檔已啟用，79正流程合成通過；V補單次／循環動畫與release候選，v7修中文說明。原生MEF／SP轉換與89技能缺口仍未完成，實機待回。

最新：[MEF重新啟動／Server內容層](S00-20261107-MEF-RESUME-AND-SERVER-SCENARIO-DATA.md)。新排程解除60%暫緩；78項正流程合成通過，原生MEF reader仍缺樣本／格式，與Server自訂JSON清楚分開。

最新：[v31全角色技能／等級／V與Tab](S00-20261107-V31-ALL-ROLE-SKILLS-LEVELS-V-TAB.md)。72項正流程合成通過、已部署；九角色27技能清單齊，154動畫候選／89未開，長V及特性呈現仍P0未完成，人測待回。

最新：[v30泳池廣場、完整移動範圍比較與500／多角色技能場](S00-20261107-V30-POOL-AND-SKILL-LAB.md)。64項正流程合成通過；v6 NPC頭頂中文人測通過，泳池及技能場人測待回，真實V流程仍未開放。下列較早狀態按當時版本保留。

最新：[v6直接讀取NPC中文XML](../client-variants/20261107-zh-tw-v6/README.md)。保留v5退回，v6靜態檢查通過、實機待測；v29冷卻亦待回。測試卡送出後已續查聊天提示來源與台韓指令差異。

最新：[v29冷卻增量修正已部署](S00-20261107-V29-COOLDOWN-DELTA-DEPLOYMENT.md)。59項正流程合成通過；資源回復、其他技能與到期不再重建未改變的冷卻。實機圖示待測，翻譯仍v5退回、無新版。

目前P0：[資源回復造成冷卻圓形進度重轉](S00-20261107-RESOURCE-RECOVERY-COOLDOWN-RESTART.md)。已核對Server全表reset/republication觸發，原deadline不變；Server-only修正需求已記錄，尚未套用。

最新：[Server與測試現況](S00-20261107-CURRENT-SERVER-AND-TEST-STATUS.md)；[已核准Client v5頭頂名稱修正](../client-variants/20261107-zh-tw-v5/README.md)。v28持續運作，v5與六鍵人測待回。

最新：[使用者核准的原目錄Client v4](../client-variants/20261107-zh-tw-v4/README.md)。只新增EXE與四個翻譯/字型檔，79個既有檔案hash保留，靜態檢查通過、實機待測。

目前P0：[v28資源語意／反灰／一級耗量與六鍵測試](S00-20261105-V28-RESOURCE-SEMANTICS-AND-SIX-KEYS.md)。v27技能／MP-SP回復通過，HP未測，耗量／黑圖示退回；57正流程合成通過，新Client與v28人測PENDING。

目前：[v26圖示／連段／Z+C／行走人測通過；v27末段間隔與暫定回復](S00-20261105-V27-COMBO-RESTART-AND-RECOVERY.md)。44正流程合成通過；v27人測PENDING。

目前P0：[v26技能ID域混用](S00-20261105-V26-SKILL-ID-DOMAINS.md)。v25副本仍空白退回；已證timer錯把Practice49/50/52當active29/30/31，修正後尚待人測。

目前P0：[v25技能快捷列空白](S00-20261105-V25-EMPTY-SKILL-SHORTCUTS.md)。v24戰鬥短卡中止；綁定後發布完整組態與固定出站診斷修補候選，尚待人測。

目前P0：[v24普攻輸入回復／資源顯示／不可用技能移動](S00-20261105-V24-COMBAT-INPUT-AND-RESOURCES.md)。v23非戰鬥操控與NPC通過保留；新增副本問題人測退回，37合成通過，v24人測待完成。

最新結果：[v23本輪實機通過](S00-20261105-V23-DISPLAY-DEFAULT-ROLE.md)：角色0入口、廣場三種方向／Z操作、Story117村莊NPC劇情；34正向合成通過49秒。僅此工作副本短卡，不升級原件／完整主線／SPEC驗收。

最新退回：[v22展示頁role0卡住／v23預設擁有角色修補](S00-20261105-V23-DISPLAY-DEFAULT-ROLE.md)。v22未進世界，操控／NPC策略尚未被人測執行。34正向重跑通過，v23待部署及人測。

本輪：[v22非戰鬥輸入可用性與村莊互動候選](S00-20261105-V22-INTERACTION-INPUT-AND-TOWN.md)。34正流程合成通過；待發行及人測，不改Client。

本輪P0：[v21操控／NPC退回](S00-20261104-V21-CONTROLS-NPC-REVIEW.md)。展示頁與進廣場人測通過；村莊NPC／方向＋Z仍未通過。750ms修正33項合成通過但尚未換版，整批就緒前不要求重測。

本輪接續：[T01 W1/W2/W3複核與v21候選](S00-20261104-T01-W123-INTAKE-AND-V21-BOOTSTRAP.md)。

最新修正：[NPC三倍距離與登入回廣場](S00-20261104-NPC-RANGE-AND-SQUARE-RESUME.md)。真人驗收待測。

最新：[馮德斯→爾斯梅勒主線旅程候選](S00-20261104-ALSMEER-STORY-CONTINUATION.md)：共用敘事／Scenario骨架接10任務、16圖及Town2初始化；30個合成正流程通過。正式獎勵／EXP／角色取得與MEF仍有缺口，真人驗收待測。

最新：[2026-11-04 main整合與v18相容性修正](S00-20261104-MAIN-INTEGRATION-AND-COMPATIBILITY.md)：T10/T16與T01審核已接收整合；來源獨立核對，修正組合動作誤選與受擊FSM，保留全row及實際回覆診斷。共用任務仍DRAFT_BLOCKED，多鍵移動待實機時序。後續直接main，不開新分支。

最新工作包：[多鍵輸入與共用任務引擎](../../research/handoffs/s00-input-and-quest-reuse-20261103/README.md)，供明天Web AI分析；尚未派送／認領。P0輸入組合，P1任務資料化與共用流程。

最新：[v16移動意圖更正](S00-20261103-MOVEMENT-INTENT-V16.md)：撤除非戰鬥Z強制停步，方向放開與方向加Z分別驗證。v14/v15相關停步目標為錯誤解讀，真人修正結果待測。

# 2026-11-03 v15輸入說明／進度測試

[收包管線、同方向恢復與主線段落指定](S00-20261103-INPUT-PIPELINE-AND-PROGRESS-DEBUG.md)：修除v14方向鎖，本機測試頁可指定六個已實作段落；測試連線不回寫正常主線紀錄，27個正常／新授權debug案例通過，Client操作待測。

# 2026-11-03 v14與MEF遷移規劃

[v14修正](S00-20261103-PHINDOS-V14-CORRECTIONS.md)：出口改站上按Z、清怪後保留戰鬥與空揮、修正非戰鬥Z停步；27正常測試通過，人測待完成。[MEF遷移計畫](S00-20261103-MEF-IMPLEMENTATION-AND-MIGRATION-PLAN.md)列內容／AI搬移及原生格式Gate，尚非已實作MEF。

# 2026-11-03 v12人測與v13修正

[人測](S00-20261103-PHINDOS-V12-HUMAN-RESULT.md)確認到村、人物NPC／移動停止及換場畫面，並有三項缺陷；[v13修正](S00-20261103-PHINDOS-V13-CORRECTIONS.md)已通過正常合成測試，實際遊戲重測待完成。以下較早「人工未完成／自動換圖／40接取」敘述按其版本保留。

# 2026-11-03 最新進度

[單人主線進村候選](S00-20261103-PHINDOS-SINGLE-PLAYER-BRIDGE.md)已接通廣場NPC、兩圖戰鬥、結果返回與村落初始化；27個HappyPath通過，Host及工具建置通過。實際工作副本人測尚未完成。此為單人主線副本，與多人組隊不同；目前僅一角色出戰，三角色跟隨仍未完成。以下較早條目的未接通／未部署敘述為各版歷史。

# S00 目前開發採用的分析與規劃入口

分析、原始證據追溯、Server規劃及實測範圍保存在本公開分析庫。
Server實作程式只保存在使用者指定的私有ttr_server_roy，不複製到此庫。
本入口是目前主要採用資料的導覽，不宣稱所有探索、尚未採用的舊稿或第三方報告都已驗收。

歷史工作分支曾為`codex/s00-combat-priority-20261101`。其提交現已全部納入main；目前只在main作業，見2026-11-07分支稽核。
原始bulk及歷史Task主張沿用原索引與限制，分支推送不等於正式規格批准。

- [舊Server資料採用界線](S00-20261101-LEGACY-SERVER-INTAKE-AUDIT.md)
- [冒險團命名與教學入口](S00-20261101-EXPEDITION-NAME-TUTORIAL-ENTRY.md)
- [移動輸入額度修正](S00-20261102-HOUSE-INPUT-CREDIT-STARVATION.md)
- [連擊與受擊候選](S00-20261101-COMBO-RECOVERY-AND-HURT-COOLDOWN.md)
- [怪物AI與MEF缺口](S00-20261101-ENEMY-PACING-AND-MEF-BOUNDARY.md)
- [任務結算接手](S00-20261101-T16-QUEST-SETTLEMENT-INTAKE.md)
- [獎勵顯示欄位核對](S00-20261102-QUEST-REWARD-CHANNELS.md)
- [新帳號登入卡點修復](S00-20261102-FRESH-LOGIN-NAME-LIMIT.md)
- [全新帳號教學人工結果](S00-20261102-FRESH-TUTORIAL-HUMAN-PASS.md)
- [目前進村階段規劃](S00-20261102-PHINDOS-ENTRY-MILESTONE.md)

[完整迭代索引](README.md)保留較早所有設計；
[馮德斯分析工作包](../../research/handoffs/s00-phindos-mainline-20261102/README.md)
列各對話工作與來源收件狀態。收到報告與T01獨立驗證／S00採用分開；目前不能說全部通過。

每項採用結論應記原始來源版本／SHA、有界核對工具／結果、Server設計選擇、
實際遊戲結果及未知。原始資源、本機帳密、帳號DB及私有Server程式不公開。
本輪新查的Quest15資源資料已補進上述進村規劃與可重跑工具；沒有只停留在對話摘要。

- [進村四段事件與碰撞資格核對](S00-20261102-PHINDOS-SEQUENCES-AND-BOUNDS.md)：演出與普通村落初始化分開，實際Server讀取器核對，不宣稱進村成功。

- [NPC本地劇情與通知方向](S00-20261102-SCENE-NOTIFICATION-ORDER.md)：1C前已有本地scene呼叫，3F literal1不作任務成功證明；採用typed欄位解析。

- [任務前置保存候選](S00-20261102-TUTORIAL-PREREQUISITES-STORE.md)：source-only，尚未接live發布，獎勵僅pending entitlement。
- [明日整村劇情Web AI工作包](../../research/handoffs/s00-phindos-web-analysis-20261103/README.md)：五張工作卡、77筆Town1任務、28段scene與分檔metadata、整合驗收格式。

- [任務前置明示發布與CSquare控制器核對](S00-20261102-TUTORIAL-PREREQUISITES-PUBLICATION.md)：26個正流程測試，模式預設關閉／未部署，普通Town1入口仍待證。

- [Quest15開場NPC／對話及控制候選](S00-20261102-QUEST15-INTRO-CONTROL.md)：原始目錄欄位分域、六筆文字存在性、限定控制恢復，未宣稱NPC／進村人測成功。

- [隔離前置測試準備](S00-20261102-ISOLATED-PREREQUISITES-PREP.md)：新空白資料庫與獨立發行檔，尚未換版。
- [場景啟動接收函式](S00-20261102-SCENE-START-CONSUMER.md)：確認0x47及兩個有號WORD，排程與任務授權仍待接通。

- [廣場 NPC 互動區域補齊](S00-20261102-SQUARE-NPC-INTERACTION.md)：0x27 完整清單、劇情後恢復與26個正流程測試；舊Server錯誤opcode／提前完成任務不可沿用。
