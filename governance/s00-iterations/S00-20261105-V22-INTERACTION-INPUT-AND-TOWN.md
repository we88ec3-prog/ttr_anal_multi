# v22：非戰鬥輸入可用性與村莊互動候選

## 問題與處理範圍

承接v21人測：展示頁／按鈕進廣場通過；方向＋Z與Story117村莊NPC不通過。使用者要求修復後測試，操控與NPC整批處理。沿用REQ-0011／REQ-0019，不另建平行台帳；Client完全不修改，不把synthetic通過當成原件或實機PASS。

## 這次採用的不同解法

T10已證原0A的action-only row不能反推實體held/released。本次沒有再加last-key、Z強停或長按猜測。改為在非戰鬥世界**發布技能不可用的本機計時狀態**，使原生Single producer不保留該技能候選，方向報告可繼續產生。這是Server自己「村莊／廣場只互動，不施放戰鬥技能」的候選政策，並不是修補原Client，也不是官方冷卻值。

- 54F270把mask映matrix欄，查出實際skill key後看per-key timer.remaining==0。
- 546100在controller mode!=1、actor3E8=0、availability失敗時清low15；接著原移動分支仍可依本機採樣方向／碰撞產生8000。其他FSM/status/producer gates保持有效。
- 012A/4B1A00→controller+40→545E20已見actor u16、reset DWORD、6B `{key u16, raw i32}`。raw值signed除33，非0啟用counter。
- 非戰鬥使用int.MaxValue作「本連線場景不可用」counter，**不是官方技能CD／毫秒承諾**。進戰鬥先以012A reset清除該限制，角色學習／裝備／存檔不改。UI可能將其顯示為冷卻樣式，實際顯示仍待觀察；若有不合適呈現需另修，不宣稱UI無影響。
- 只採原始CharacterMatrices.xml明列的279個非0 skill keys，單包1682B，沒有把所有ushort或實體按鍵碼亂塞timer。所有角色矩陣的union是為避免猜role/model/matrix index映射；這些key僅套在本機受控actor256，無其他玩家。

來源原Table.stp SHA09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442；指定member `Table/Skill/Matrix/CharacterMatrices.xml` SHA78ca8db32ae323436d5c37b0162cca72a3c2b2a769924a63458dd087f96b7dad。另唯讀核對工作目錄Table.stp SHAea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c，同member SHA相同。只解指定member，沒有MEF搜尋、沒有原資源或ZIP新增上Git。公開保存key投影／SHA／方法來源，詳evidence/20261105-v22-controls/。

## NPC卡住的新增來源層原因

現行Town候選原先以99/3安裝CMissionRoom／CMissionRoomController。548350先5452C0收移動，隨後若CPartyMgr目前party指標FB7258為null便return，**NPC檢查尚未執行**；所以可以走動卻沒有1C。539C20初始化該指標為0；4AF530本機metadata查party ID，53A9D0不存在時只送C8/C9查詢並return0。原Server沒有供應相應party狀態，故這是具體缺失鏈，符合v21未見NPC上行，但未讀Client記憶體，不聲稱已動態證明該指標值。

本次不為單人村落互動虛構多人組隊。改用已在人測廣場可用的69/7→43入口，採Single控制器，再獨立發布Town1/Map182、角色、完整prerequisite、九NPC與manual checkpoint。Single的548A90互動不經上述MissionRoom party early-return，且其mode2會檢查技能可用性，與本次輸入策略一致。原生kind3的Quest/UI模式gate包含mode7。這是**新Server場景候選**，不是宣稱找到原服村落唯一scene subtype。村落的實體地圖、NPC資料、主線及3倍互動半徑不改；正式隊伍邀請／匹配／多人副本仍未實作。

Town43前不發布角色／NPC ready及劇情。先排隊世界資料，待43後送整批初始化；返回村落的新劇情亦排在同一ready批次之後。正常進村、debugStory117、每任務返回／Town2都共用此路徑，避免僅修debug。保留NPC ID／phase／Server位置範圍檢核，不把0A的Z任意當NPC成功。

## 工程測試與限制

34項Category=HappyPath全部通過49秒。新直接世界案例核對69/7等待43、Town182／NPC初始化、279key限制、靠近NPC10002啟動117/1、切入Road191清限制且仍可攻擊。完整TCP/SQLite旅程仍覆蓋新帳號、教學、廣場、10任務／16圖／30劇情及Town2；它是合成正流程，不是Client實機操控證據。

測試中曾漏處理無副本任務完成後新增69/43交握，致整段case等待；已修正合成Client的ReadStoryReady交握。兩次未完成測試程序在確認精確UT testhost路徑後結束，沒有動遊戲或live Host；並行建置曾遇該testhost檔鎖，後續採序列重跑完整34項通過。不存在負向／壓測／新MEF或新原件二進位分析。

750ms watchdog及估算截斷修正一併包含，沿用前報告限制：v21快照沒有證明watchdog觸發，不把移除它單獨當根因。原角色、技能、怪物AI／戰鬥手感及獎勵／正式任務結算缺口不因本輪擴大為完成。

## 發行／人測

工程修正就緒，準備批次發行v22；精確commit、DLL SHA、Host PID與發行時間另存收據。人測仍PENDING：廣場短按方向後放開只Z、持續方向加Z、同方向重新按；再Story117正常靠近NPC按Z到第一段劇情就停。若控制失敗或卡住就停，避免重跑新手流程；不按跳過教學、不擴大目前暫緩測試。

## v22發行收據

2026-11-05 00:27:43 +08:00，核對舊Host PID30924／精確v21路徑與loopback listeners後替換；一致性SQLite備份成功，未變schema或帳號正常進度。v22 build source287bf10efa1b2eaf20f6fa42d821cbd1f2f338d2，PID38440。Host DLL42340ef36d934fd9c576f6e97ed0fa432c74d92f7c45bbba1133efced6b2054f；Network DLLf85090fe0c63ec564b199a20bd2365dea3f1b115341ca4602bcccfa7a2addd85；story內容SHA不變。兩個journal Healthy/dropped0；Client EXE SHA與既有6f92ba12…d3b3c一致。

已發同一張正向短卡：角色展示→廣場三種移動／Z→debugStory117→NPC第一段劇情就停，技能欄異常冷卻呈現另記。人測PENDING，未列任何新增實機PASS。收據只代表啟動與工程檢核，不代表原件相容或操控需求完成。
