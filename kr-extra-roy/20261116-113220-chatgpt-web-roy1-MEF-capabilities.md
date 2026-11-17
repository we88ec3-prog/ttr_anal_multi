# `.mef` 能做哪些事：完整能力、執行流程與 Server 開發交接

研究基準時間：2026-11-16 11:32:20（Asia/Taipei）。工作分支 **`extra/roy1`**。承接已公開 `af97bbd29c892e031eef7a3bc3a98cb79f1be729`；main 基準 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` 已在本分支祖先鏈中。本輪不建立 branch，也不修改正式 RR／REQ／Task 狀態。

## 1. 交付結論：以能力及可用條件為分析終點

**已把研究整理成可以用於內容與 Server 開發的能力手冊：建立與操控演出角色、世界 NPC 的放置與外觀、鏡頭路徑、音樂／語音／音效、畫面效果、兩套對白、書本與圖片、教學 UI、互動點、地圖／小地圖，以及原生商店服務如何接上 Server。** 每類分別交代入口、參數域、實際 consumer、完成／停止方式與依賴。

本輪按使用者最新指示，以「`.mef`／重建關卡腳本能編排哪些功能」為目標。能力的驗收重點是具體功能能否經已證入口產生正確效果、狀態是否一致，以及 Server 應提供什麼。普通戰鬥與經濟系統由 Server 承擔權威工作是整體設計的一部分；不再把完全接替那些系統作為這份能力研究的完成標準。

### 1.1 本文中 `.mef` 的精確範圍

原版 MEF 樣本已不可取得；既有研究仍未閉合 `_MapList.TRIGGER → 原生 .mef 首載入 → 官方格式／executor`。因此本稿談的是：**以 KR Client 已有腳本執行器、公開 bindings、原版 Lua helpers 與既有資料表，能支援哪些重建關卡／事件內容**。相容 Lua 新內容必須接入可達 caller，不能僅靠把檔名改成 `.mef` 就取得能力。

這個格式／首次入口界線在本文固定保留；下列已證原生能力各自成立，開發時可按適用 context 組合。它們的證據不需要以原始 MEF 還原或普通戰鬥全面替代為前置條件。[既有原生入口研究](MEF-trigger-callers-20261115/native-root/report.md)、[相容 caller 與 parser](MEF-end-to-end-20261116/entry/report.md)

### 1.2 完整交付內容

| 交付 | 可直接查到的內容 |
|---|---|
| [能力總表](MEF-capabilities-20261116/capability-catalog.md)／[機器可讀索引](MEF-capabilities-20261116/capability-index.json) | 7 個選定 namespace 的 **121 個一般 static bindings**，逐名稱列效果、條件、實際 target 與證據。數量是介面名稱數，不是121種獨立玩法或完整Client API總數。 |
| [鏡頭、音樂與畫面效果](MEF-capabilities-20261116/audiovisual/report.md) | 相機 XML／相對座標、真實 KeyFrame tick、旋轉與距離、音訊 stream、fade／transition 等。 |
| [對白與演出 UI](MEF-capabilities-20261116/dialogue-ui/report.md) | ScenarioTalkTable 的原表／頭像／文字／手動自動推進；Prolog Dialogue／語音；字幕、數字、面板與效果。 |
| [世界 NPC、外觀與服務](MEF-capabilities-20261116/world-npc/report.md) | 本地世界 actor、Q actor 動作、CDoll 外觀更新、互動點、貨單與買賣／強化服務。 |
| [教學、UI 與輔助層](MEF-capabilities-20261116/control/report.md) | 教學與scenario編排、HideUI／固定page、小地圖、計時與診斷；[75個qbase函式索引](MEF-capabilities-20261116/control/helper-index.json)。 |
| [Server 開發需求](MEF-capabilities-20261116/server-handoff.md) | 各能力需要的內容發布、key／identity、流程／取消、交易／持久化與驗收工作。 |
| [來源與核對](MEF-capabilities-20261116/README.md) | 固定原件identity、Git pins、native節錄、唯讀verifier及實際結果。 |

## 2. 腳本能編排的功能

| 功能 | 能由既有 Client 機制完成的部分 | 內容／Server 需提供的條件 |
|---|---|---|
| **演出角色** | 指定 Q slot、模型、位置、方向、動畫、外觀與附件；走位、換位、轉向、表情、速度、顯示／隱藏、閃爍與批次清理 | 合法模型與動作、prepass依賴及唯一slot；Q slot與world EntityId分開。 |
| **世界 NPC／角色放置** | `lb.CreateObjectEx` 可走真實 world actor 型別分支；位置、縮放、面向由參數決定 | 有模型資源的NPC與合法落點；本地配號與Server可互動identity需對齊。 |
| **世界角色換裝／附件** | `SetActorAvatar` 改部件／變體；Attach／Detach改CDoll外觀樹，經實際模型工作與render更新套用 | 正確world key、part／variant／item資料；外觀改動與背包／裝備權威狀態分工。 |
| **鏡頭** | 載入與播放keyframe、相對位移、跟隨Q物件、立即定位、兩角加距離、震動／位移、保存／還原快照、預設相機 | camera XML、相機節點、合格Client更新與平衡的snapshot owner。 |
| **音樂、一般音效與語音** | 請求背景音樂／一般音效／對話語音，停止音樂，逐次降低音量；原表文字可配原生語音命名 | 合法路徑與音訊owner；共享語音／背景音軌的衝突與結束條件。 |
| **畫面效果** | 淡入／淡出／色彩、全畫面淡幕、轉換、上下黑邊、褐色色調、局部慢動作、世界render gate | 正確時間／frame單位及配對清理；動畫慢速與Server邏輯時鐘各自管理。 |
| **多列對白** | `ScenarioTalkTable.open(id,scene,manual)` 選原表頭像／文字並手動或自動推進，可隱藏／恢復其他UI | 有來源的雙鍵、頭像與文字表、適用視窗context；分支與後續業務結果由流程決定。 |
| **序章文字／語音與書本** | `Q.Dialogue`、`Q.Prolog` 有表key；`Q.Book` 啟動固定書本序列；Prolog／Book有原query，Dialogue helper只yield | Book的整數參數被忽略；依各自契約區分自然完成、取消和共享voice gate，不能替Dialogue假設完成query。 |
| **字幕、圖片與提示面板** | InsertText、FlyingObject、Tutorial圖片、NumberPanel／BattlePanel、BurstStruck可產生各自的顯示效果 | 合法texture／字串／slot及對應owner；單次yield通常只是排程點。 |
| **教學與玩家操作流程** | 提示點、鍵位／輸入mask、教學狀態、指定角色檢查、雇用／提示UI、scenario請求→結束旗標→續排 | 正確Tutorial controller與UI頁面；Server提供合法scenario及對應事件。 |
| **出口／市場／NPC互動點** | 已登記點可由本地setter切換enabled，出口等類型另有視覺分支；Client判範圍、按鍵並發意圖 | 建立包含目前應保留各點的完整集合；category/key/位置及Server後續流程對齊。 |
| **換圖與小地圖** | 本地地圖載入、演出map備份／還原；依map→BOUND重載小地圖descriptor／texture／symbols | 合法map及完整依賴，已初始化owner；Server同步場景、角色、互動點與進度。 |
| **商店／強化等既有服務** | 市場點→ShopNo→NPC／Town→貨單與服務選單，已有普通買賣、裝備強化UI及各自請求路徑 | Server核商店可用性、商品／裝備、材料／費用、交易結果與持久化。選服務不等於本地完成交易。 |

演出／世界角色與商店證據見 [world-npc](MEF-capabilities-20261116/world-npc/report.md)；鏡頭、聲音與畫面見 [audiovisual](MEF-capabilities-20261116/audiovisual/report.md)；對白及面板見 [dialogue-ui](MEF-capabilities-20261116/dialogue-ui/report.md)；教學／互動與小地圖見 [control](MEF-capabilities-20261116/control/report.md)。原版圖片與清理的細節固定沿用 [R10 world](MEF-control-flow-20261116/world/report.md)、[R10 runner](MEF-control-flow-20261116/runner/report.md)。

## 3. 從內容發布到完成的完整流程

以下分別標示原件已證行為與新內容整合設計。這是功能如何接起來的操作規格，不是宣告任意原始 `.mef` 已能自動執行。

| 階段 | 實際流程 | 開發時應做的事 |
|---|---|---|
| **1. 選內容與依賴** | 指定合法scene／model／action／camera／對白／音訊／UI key，各自查對應原表／資源 | Server／內容工具保存版本與來源；不能混用Q slot、world ID、NPC、ShopNo、scenario和對白鍵。 |
| **2. 發布及資源可見** | launcher的manifest／HTTP／gzip→普通檔落地；Client resource loader有package優先、fallback、checksum／cache條件 | 以實際被選取的resource與hash驗收版本；磁碟存在不保證本輪使用。 |
| **3. 接上可達入口** | 原生S2C0047以雙鍵選 `Event/Sequences/<funcName>.seq`；已證本地／教學入口另依各自context | 可用既有scene入口。若使用新相容模組，由已證caller設計接入，明列phase與export契約。 |
| **4. prepass宣告依賴** | 獨立VM同步執行Register，收集演出物件／動作依賴，再做model/motion工作 | 宣告必須有限且不等待；宣告與正式操作一致，錯誤不得被當完整依賴成功。 |
| **5. 正式登記與執行** | 正式VM載入內容，Register建立coroutine；合格Q pump逐次resume | 頂層載入先返回，yield放在正確coroutine；module副檔名不決定Lua parser。 |
| **6. 取得功能owner** | 視需要取camera snapshot、map backup、Q slots、UI可見集合、圖片與音訊通道 | 記錄本段實際取得／修改了什麼；共享owner需要排他或替換政策。 |
| **7. 執行具體能力** | 內容呼Q/lb/Tutorial/CameraWorks/ScenarioTalkTable/Fade等；各native保存參數並由tick／draw／工作queue消費 | 按本稿能力表用正確參數與資源，分清「發起」「已建立」「已完成」。 |
| **8. 等待／選支線** | 可用CameraWorks.IsEnded、Prolog／Book／Q停止狀態、對話global、教學scenario/state等 | 讀同一owner的可靠條件；以number比較，不用Lua的0當false。沒有query的效果使用明示時序或另訂驗收。 |
| **9. 正常／錯誤／取消接回** | 原版normal return、End、Stop、removeAll各不同；R10有可讓一般Lua error回outer的條件式supervisor設計 | 若採新adapter，明列可捕捉與不可接回的情形；取消來源與外部native Stop另外協調。 |
| **10. 清理及結束** | 依取得紀錄還原map／camera／UI／render/input與效果，必要後置條件成立後最後End | Fade、音訊、images、sepia等有不同完成／回收時點；不能以一次reset概括。 |
| **11. Server續接** | 原C2S003F／S2C00EB及各scenario／互動／交易請求依各自契約運作 | Server保存內容結果與權威業務提交，處理重送／遲到／取消後事件，再決定下一步。 |

發布與入口：[交付鏈](20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md)、[resource gates](MEF-complete-flow-20261115/resource-gates/report.md)、[R9端到端流程](20261116-040128-chatgpt-web-roy1-MEF-end-to-end.md)。prepass／正式能力：[bridge](MEF-content-contracts-20261116/bridge/report.md)、[scheduler](MEF-runtime-contracts-20261115/scheduler/report.md)。錯誤／清理／完成：[supervisor](MEF-control-flow-20261116/supervisor/report.md)、[presentation](MEF-control-flow-20261116/presentation/report.md)、[原003F／00EB](MEF-world-integration-20261115/wire/report.md)。本輪新增細節由四組能力章補齊。

## 4. 本輪新增的實質能力證據

### 4.1 鏡頭路徑確實能自行逐格推進

本輪找到 KeyFrame 的實際更新入口：`491CA7` 檢查Client gate，`491CC6→434130` 取得current，`491CD3` 讀virtual `+14`，`491CD6` dispatch；KeyFrame該slot為 `54E270→797790`，逐次增加frame、做插值，再由virtual `+4=54E080` 套用相機。這閉合了**載入→開始→native逐格更新→相機效果→IsEnded** 的功能鏈。

原版 `PlayCameraNoWait` 以 `CameraWorks.LoadRel` 載路徑；選定flag才把領隊位置加進offset，`PlayCamera`再接`WaitForCamera`。原helper等待的是IsEnded數值條件，並非硬編一段影片長度。`MoveCamera/SetCameraPoint`則是立即XYZ setter；`RotCamera`的第三值是局部距離，前兩值是角，不應編成三軸旋轉。[完整鏡頭證據](MEF-capabilities-20261116/audiovisual/report.md)

### 4.2 角色能做表情與換裝，而且有實際更新 consumer

`FaceObject`走面部控制器／`Face.SKIN`；物件面向另走RotateObject。世界actor的SetActorAvatar、AttachActorItem、DetachActorItem操作的是具體CDoll外觀資料，dirty經actor更新、模型工作queue、result drain與apply才變成渲染結果。Detach用部件鍵及其配對部件，與Attach傳入的item資料鍵並不相同。

本輪因此能把「指定外觀」寫成有實際下游的能力，而不是只見到一個setter名稱。資源與world key仍需有效；本地外觀操作不會替Server新增背包物品或完成裝備交易。[完整物件與外觀證據](MEF-capabilities-20261116/world-npc/report.md)

### 4.3 對話有兩條可用的主路徑

`ScenarioTalkTable.open` 是 **兩整數雙鍵＋手動旗標**，查原ScenarioTalkTable的Talk列。actor key選頭像，talk key選文字；parser雖保存kind，所查顯示consumer不讀該欄位；它不以world EntityId或Q slot尋找說話者。手動模式支援按鍵／UI事件推進，自動模式有原生計時producer；相關timer未在所查每列next分支重設，因此不能描述為「每句固定1.5秒」。關閉路徑停止語音、呼OnEndTalk、隱藏視窗、清selected資料；hideOtherUI/showOtherUI有可配對的實際consumer。

`Q.Dialogue`則查Prolog XML文字，建立序章樣式的文字／語音演出，使用原生 `Scenario/Prologue/P%02d_%02d.ogg` 命名鏈。它與Book／其他talk voice可能共用voice handle；有聲音等待時需看同一owner的釋放條件。原表、字串轉換、typed UI、關閉與等待原件均在 [對白能力章](MEF-capabilities-20261116/dialogue-ui/report.md)。

### 4.4 聲音、淡幕與等待要按真正生命週期操作

背景音樂請求進非同步CMusicPlayer與stream driver；相同filename可以略過重播。`StopMusic`有停止／釋放stream的路徑，`StopMusicWithFadeOut`是把音量因子降到0，該終點本身不釋放stream。`SetFinalMusic`也不是立即播放或一般字串overwrite：本體有null不變、空白首字元清除、其餘追加的行為，後續由RestoreMap消費。

`Fade.Start/End`與`Q.FadeIn/Out/Color`共用FE2744遮罩，與音樂fade及Transition分屬不同owner。`Fade.End(0)`停止更新但保留alpha；draw並非只看active，若要清覆蓋需採正確非零參數。Transition則擷取畫面並作多層放大淡出，兩整數參數為layers/rate，原helper固定採(2,120)，native預設(8,120)且需要enabled。以上都會進入內容的取得／釋放規範。[完整聲音與效果證據](MEF-capabilities-20261116/audiovisual/report.md)

### 4.5 UI及小地圖也有可使用的具體能力

`Tutorial.HideUI`把空豁免集合送到typed current-page consumer，記錄並隱藏原本可見的child windows；`SetUIPage`固定選15，同頁時送固定F4355刷新事件。`lb.LoadMinimap`接整數map key，從BOUND索引取得 `.mmt` 路徑，載texture及symbols，前提是既有minimap component已安裝。這些功能都可以列入內容工具，不能由名稱另加不存在的任意page／texture參數。[control原件與參數](MEF-capabilities-20261116/control/report.md)

### 4.6 明確標出名稱存在但不能當成功能的入口

| 入口 | 原件結果 | 內容端應採用的方式 |
|---|---|---|
| `Q.DeleteObject` | normal target僅`RET 4` | 個別隱藏用ShowObject；真正Q批次回收用DeleteAllObject，別以同slot重建當替換。 |
| `Q.BalloonTalk` | normal target僅`RET 8`，兩個值被忽略 | 對話選ScenarioTalkTable／Prolog等已證路徑，不宣稱此版本有該氣泡consumer。 |
| `lb.PrintCurrSceneID` | target僅`RET` | 內容記錄自己的合法scene context，不把它當query。 |
| `Tutorial.InsertObject` | target僅`RET 4` | 已證固定角色入口為InsertIsilia；不把這個名稱當通用建立器。 |
| `lb.GetObjectCount` | 名稱對應一次性manager初始化，無可靠count producer | 不以此判斷集合大小。 |
| `StartLoading/EndLoading` | qbase只yield | 載入工作與完成條件另按實際loader／owner。 |
| 六個qbase空helper | OnNextTalk、Phase2/3/4、RevPhase4/2只有RETURN | 不把階段名稱算成已實作效果。 |

這些限制已逐列進入能力索引與verifier；其餘有正向鏈的能力不因這幾個stub被抹成「MEF什麼都不能做」。[物件](MEF-capabilities-20261116/world-npc/report.md)、[對白](MEF-capabilities-20261116/dialogue-ui/report.md)、[輔助層](MEF-capabilities-20261116/control/report.md)

## 5. 可以如何組成實際內容

### 5.1 一段NPC登場與對話演出

內容先選有來源的場景與模型／動作，在prepass宣告依賴；正式段保存camera、建立唯一Q slots，安排移動、轉向、表情與鏡頭，播放音效／音樂；需要多列頭像對白時選ScenarioTalkTable雙鍵，等待同一對話流程結束；最後按持有紀錄清理，再End。

原版Q119/3已提供可複用的固定演出實例：三個演出物件、走位、動作、音效與對話編排。這裡以其已證內容形態說明組合能力，不發布完整原SEQ，也不聲稱本輪已在Client播放。[原版實例及來源](../governance/client-variants/20261109-mef-town-services/scenario-controls.md)、[本輪分項能力](MEF-capabilities-20261116/capability-catalog.md)

### 5.2 在城鎮開放一間既有商店或強化服務

需要分別決定「世界中看見什麼NPC」「在哪個互動點可開店」「採哪個ShopNo／Town／NPC與服務資料」。本地CNPC建構器與外觀能力可以承接前一項；市場category2點、原表貨單與NPC type選單承接後兩項。部分店主在所查ActorList沒有對應world model，故服務可用性不能由同號NPC模型放置推定。

已核的Town1鐵匠鏈為Shop2→NPC10030→type12→功能29→原生普通裝備強化UI。Server應完成的是該服務的授權、材料／費用、結果、裝備變更與保存；腳本可以編排它何時開放，以及前後的對話、演出與互動狀態。[NPC／商店與資產同步證據](MEF-capabilities-20261116/world-npc/report.md)

### 5.3 一段操作教學或關卡間提示

原版Tutorial可以放提示點、調輸入mask、顯示教學文字／圖片、等待指定教學state／領隊條件，再請求既有scenario；收到適用的結束旗標後續排下一段演出或提示。Server提供合法情境與完成事件，Client負責已證本地顯示、操作判斷及編排。對已存在的出口／NPC／市場點，也可以按同key/category切換狀態。[教學與互動能力](MEF-capabilities-20261116/control/report.md)

這些例子是按現有證據形成的內容整合規格。沒有自行設計官方MEF schema、未知opcode、合法模型ID或官方座標，也沒有執行新Lua／Client／Server。

## 6. Server 開發需求

本輪將Server缺口直接列為開發需求，沿用REQ-0019／REQ-0021等已存在脈絡，未建立新正式REQ或改驗收狀態。[詳細交接](MEF-capabilities-20261116/server-handoff.md)

| 需求領域 | Server具體工作 |
|---|---|
| 內容與資源 | 固定版本、hash、相依表／圖／模型／音訊／UI資源，對齊Client實際選取的resource。 |
| 內容啟動與流程 | scene雙鍵合法性、busy序列化、教學scenario開始／結束、下一段分支與取消政策。 |
| 世界與互動 | 有來源的map/NPC/ShopNo/point key/category/位置資料；本地與網路identity、點集合完整性。 |
| 交易與服務 | 商品／裝備／材料／金錢、可用性與費率、原請求／結果輸出、原子更新、重試與持久化。 |
| 演出與共享owner | 同一玩家的camera/map/UI/音訊/image占用，外部換場／Stop與內容收尾的協調。 |
| 回報與保存 | 原演出結束回報、scenario結果、互動意圖與權威任務／資產完成分開保存；遲到／重送對帳。 |
| 驗收與記錄 | 每個能力記entry、實際資源、key/slot/ID、native觀察結果、Client效果與Server狀態。 |

原生MEF自動入口／格式仍屬Client待逆向；內容caller／owner配對屬跨功能待整合；畫面、聲音、互動與交易的實際結果屬待遊玩驗證。這些分類各自列出，不會把Server尚未實作的工作改寫為Client能力不存在。

## 7. Git、原件與驗證狀態

本輪延續已公開R10，前輪沒有再等待推送的成果。main基準與分支祖先關係、四份固定原件、提供的共享指引與前稿pins都列於 [source-manifest.json](MEF-capabilities-20261116/source-manifest.json)。全文遵守本次 `02-PROJECT-SHARED-INSTRUCTIONS.md` 與既有AGENTS readset，只在自有 `kr-extra-roy/` 新增研究交付。

總控檢查原件hash、Git pins、121項binding索引、75個helper導覽、四組原件節錄與子verifier、相對連結與整包manifest；固定前輪成果也另存實際重核結果。[核對方式](MEF-capabilities-20261116/README.md)、[總控結果](MEF-capabilities-20261116/verification-result.json)、[整合審查](MEF-capabilities-20261116/integration-review.md)

本次公開內容限分析文件、節錄證據、契約索引與核對程式。**不包含原始BIN、STP或完整解包資源。** 沒有啟動Client、執行Lua／Server或修改原始遊戲資源。PASS表示已列證據與來源一致；不等於T01 FULL-PASS、RR ACCEPTED、Server已完成或遊玩驗收。
