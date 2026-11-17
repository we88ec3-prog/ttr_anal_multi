# Tutorial／Synopsis runner 在既有世界與普通戰鬥場景中的適用界線

日期：2026-11-15（Asia/Taipei）。本稿承接 `extra/roy1` 的 `.mef` 使用流程分析；研究範圍為三個已知 `4A8B90(T)` 更新來源的合法啟動、owner、更新、結束及離場。原件唯讀，未執行 Client、Lua 或 Server，未修改原件、分支或 Git 狀態。

## 1. 結論：有非教學場景的正向路徑，但不是普通戰鬥的常駐 runner

**既有 tco 不只會在 `CTutorial` 教學 scene 中執行。原生 `CSquarePage` 等六個已註冊頁面，確實能透過劇情回顧視窗啟動固定 Synopsis，並在 UI 更新中持續呼叫同一個 `4A8B90(T)`。** 這次把原本停在 `47C980` 的 caller，接到具體 page vtable、page factory、NPC 對話按鈕、回顧視窗的初始化與顯示條件；不能再只因名稱含 Tutorial 就把這條非教學 scene 的能力排除。[R21–R46、A02–A16、P01–P30；`tables.json`]

同時，**普通 Mission／Scenario 戰鬥頁面 code `5/7` 的正常更新 hook 不走這條回顧 pump**。它們各自的 `+184` 是 `5AD6A0/5AFEB0`，共同呼 `59B1F0`；回顧 pump 是 Lobby 系列的 `5B87B0 → 47C980`。field 層面的正常 `CMissionField/CScenarioField` 也沒有把自己的 `+18` 接到 Tutorial／Expedition 的 tco 更新。這是對已識別正常 field/page 配對及三條已知 T caller 的限定結論，**不是全 Client 沒有其他 Lua 間接 callback 的證明**。[R32、R34、R54–R56；V_CMissionField、V_CScenarioField、V_CMissionFieldPage、V_CScenarioFieldPage；復用 lifecycle §7]

| 已閉合路徑 | 正常啟動者與 context | 持續更新條件 | 結束／取消 | 對普通場景的意義 |
|---|---|---|---|---|
| 教學 scene | `S2C 006E` 的既有成功分支建立 `CTutorial`，共同場景管理器安裝後初始化 controller kind 4 | current field 的 `+18=4C4DF0` 每次更新呼 T；不以 Q 的 `M+28` 作這個 caller 的 gate | scene `+14=4C4D60` 明確移除全部 tco；任務表空本身不在 field tick 中觸發自動換場 | 是正式教學 context；送 `006E` 會換成該 context，不能說它讓原普通 field 同時多了一個背景 runner |
| Expedition Synopsis | 既有 Expedition page 初始化／control 700 UI 路徑；`D6A674=45585044` 且 current field 非空 | `CExpedition+BD78!=0` 才呼 T | 實際 T 回傳數值 0 後移除 tco、清 native table、將 `BD78` 清 0；離場空 hook／field destructor不等同這條完成路徑 | 已有固定 Synopsis 播放機制；gate 要求原生 Expedition owner |
| 劇情回顧 Synopsis | NPC 對話框 control `1910` → `F4337` →回顧視窗；選取 quest `60001` 且項目尚未啟用 | current page 屬已證家族；page `+2AC` 視窗可見；選取項目 `+26C!=0` | 實際 T 回傳 0 → `47B6B0` 移除 tco並清項目 gate；隱藏／換頁與 tco取消是不同操作 | 在 Square／Lobby 類頁面有正向用途；仍是固定回顧/Synopsis內容，不能直接當普通戰鬥關卡的持續邏輯 |

三條路徑載入的仍是固定 `Event/TutorialMain.lua`，入口是 `Tutorial_EntryPoint` 或 `Synopsis_EntryPoint`。本輪沒有把它們改稱新的 `.mef` filename caller，也沒有找到 Server 直接傳腳本 bytes 給這三個入口的證據。[R07、R12；復用 named-calls 報告]

## 2. 證據來源、復用與本次範圍

第一手 KR BIN 為 `02-Tartaros.bin`，大小 `12,472,320` bytes，SHA256：

`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`

Lua 尾端的有限重驗只讀原始 `06-Event.stp`，大小 `11,241,597`，SHA256：

`2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`

工作 parent 為 `acc5b1e6d856bd31456fe2806044c3a09d5bbb43`；最新主線查核基準為 `060ed5163a67308f15aa32a91f3a6661e6e5b106`。`02-PROJECT-SHARED-INSTRUCTIONS` 對應本地 `09-02-PROJECT-SHARED-INSTRUCTIONS.md` 已全文讀取，SHA256 `624d808521354aa4fb00774839a25cac29e8fdbaa6029c66f39dc43bf7a1bb43`。最新 main 的開工、退回與共用成果查核由本輪主報告統一記錄；本子稿不另改 RR／整合狀態。

| 固定來源 | 本稿使用方式 |
|---|---|
| [前輪 lifecycle](../../MEF-entry-lifecycle-events-20261114/lifecycle.md) | 復用三個已知 T caller、T/W owner、固定 loader、Tutorial controller 與場景生命週期；本輪對必要原件窗再核 |
| [named-calls](../../MEF-trigger-callers-20261115/named-calls/report.md) | 復用固定名字呼叫與 loader 邊界，不重做舊 15/16 loader caller 或全域腳本名稱掃描 |
| [Expedition UI 入口](../../MEF-trigger-callers-20261115/alternate-entry/report.md) | 復用 control 700、`0x578 → F4248`、page router 到 `5A64B0` 的已發布陽性鏈 |
| [UI lifecycle](../../MEF-runtime-contracts-20261115/ui-lifecycle/report.md) | 復用 `58A250` pending page 切換、currentpage owner、一般 UI event queue與普通 code 5/7 factory |
| [scheduler](../../MEF-runtime-contracts-20261115/scheduler/report.md) | 復用已恢復的 Coroutine/MoCo 完整契約，不再把函式體寫成缺失 |
| [script lifecycle](../../MEF-complete-flow-20261115/script-lifecycle/report.md) | 復用 TutorialMain P2/P4/P7/P8 的呼叫、skip、父子工作及無 finally 邊界 |
| E63／E64 原稿 | 復用 review 資料列、scene-item 建立、既有 scene factory 與 Server 路由；精確 path/blob 見 manifest |
| `kr-bulk-roy/.../functions/*.c` | 只作閱讀導航。關鍵欄位、caller、vtable、switch與物件來源均以 BIN 原件核對；`63A130` 的獨立 callback 邊界本輪直接由原件辨識，沒有假借 `639F30.c` 當函式體 |

完整逐檔 `commit/path/blob` 和可用內容 hash 在 [source-manifest.json](source-manifest.json)。本稿是有限原生研究證據，沒有自行授予 T01 FULL-PASS、RR ACCEPTED、Server 可玩或完整 `.mef` 整合通過狀態。

## 3. T 是共用 owner；能登記工作不等於有更新來源

T 的固定 native owner 是 `FC0F84`，`T+0` 保存正式 Lua wrapper W。`4A88EB` 的 store 及 `4A89B6` 的 `Event/TutorialBase.lua` loader承接前輪並重驗。tco 與 qco 是正式 VM 中不同工作表，不應把 `T+34=FC0FB8` 與 Q manager 的 `M+28` 當作同一個 active flag。[R02；前輪 parser/lifecycle]

`4A8B90` 從 T 取 W，以 `4AD0A0(W,1,"t_doCoTask")` 要求一個 Lua 回值。`4A8BB7..4A8BFA` 接受 number 或可轉數值的 string，轉整數後依是否非零寫 T+34；boolean `true` 不是此 helper 的數值 1。C binding 回傳的 `EAX=1` 可能只是 Lua result slot 數量，不能與任務數混淆。[R01]

本輪只重驗／擴展下列有界 caller 集合：

| `4A8B90` callsite | 實際所在函式 | 所屬更新 hook |
|---|---|---|
| `4C4E8A` | `4C4DF0` | `CTutorial C073E8+18` |
| `4C19AE` | `4C1930` | `CExpedition C07280+18`，另受 field+BD78 限制 |
| `47CA45` | `47C980` | 經 `5B8AB8` 從 Lobby 系列 page+184 呼入，另受視窗／選取項目限制 |

針對這些 caller、起停 helper 及新上游，`scoped-xrefs.json` 僅列 11 個明確 target 的 `.text` E8/E9 及 `.text/.rdata/.data` literal 候選。逐個關鍵候選已回到指令邊界或具體 vtable；不含所有計算後的間接呼叫，也不把 caller表的陰性升格成全程式不存在其他 runner。

**回傳 0 只表示這次 helper 觀察到的數值狀態。** 已發布 MoCo 原件顯示：成功 `return` 的 thread 不會在同次走訪自動從 list 移除；後來再次走訪 dead thread、或者明確 remove/removeAll，才可能清掉其引用。因此「Lua body return」「T+34變0」「native完成收尾」「Server收到完成回報」是不同時點。不能保證完成後恰好下一畫面 frame 一定全部收完；也不能把因錯誤移除而歸零的表當作業務成功。[復用 scheduler §5–6]

## 4. Tutorial：替換成明確教學 context，結束任務本身不自動離場

### 4.1 真正 scene／controller 的初始化

`4B7E1F` 將 `4B9260` 放入既有第一層表 `FD306C`，相對表基準對應 `006E`。`4B9260` 的已證成功分支要求 payload+2 byte為1，建立 `4C4AC0`，再以共同 `4B7D50` 安裝。ctor `4C4AD5` 寫 `C073E8`，其 COL `C69E04` → type descriptor `F7E1E0` 明確為 `.?AVCTutorial@Scene@@`。[A01、R03–R05]

`4B7D50` 先呼舊 scene+14、再呼舊 deleting destructor、清 pointer；之後安裝新 scene並呼其+10。這不是在保留普通 field 的同時額外登記一個背景 tick。[R04]

`CTutorial+10=4C4B10` 會準備 Tutorial 資料，重用已是 kind4 的 controller或建立 `548B90` controller，安裝到 `FBA7A4`。最後 `4C4D3F→4A8A60(T)`，固定載入 `TutorialMain.lua` 並呼 `Tutorial_EntryPoint`。既有 C2S `000C` 長度6／參數1與 UI page15準備也屬此初始化鏈；本輪不另猜它們的 Server業務策略。[R06、R07；原 wire脈絡復用前稿]

### 4.2 更新、正常 return、場景離開

共同 frame路徑 `491CD8→489CB0` 取得 manager，再從 `+5EAC` 取 currentfield，`491CEC` 呼 field+18。Tutorial 的 slot是 `4C4DF0`，其中 `4C4E8A` 呼 T；完整 body沒有在 tick後用 T+34決定離場。[A17、R08]

TutorialMain P8 尾端以普通 CALL 執行 `Tutorial_Part2`，Part2沿同一 parent coroutine棧執行。已發布 P6 原件尾端（本輪只重核 PC137..157的84 bytes）先清 `g_TutoEmployCharQuery`，調整checkpoint，等待 scene1000/14，呼既有 `PostUIMessage_TutoMsg(TUTORIAL_STARTSCENARIO,0)` 後 RETURN。這裡沒有新 filename loader，也不能把 RETURN直接說成 Server已確認教學完成。[`tables.json` 的 `tutorial_part2_tail_reuse`；復用 script-lifecycle §4]

當共同場景管理器真的離開 CTutorial時，其 `+14=4C4D60` 在 `4C4DC2` 呼 `t_removeAllCoroutines`，並由 `4C4DCC→4A9DB0(T)` 清 native追蹤表。這是明確取消契約；不是關閉或重建整個正式 VM。[R09；VM生命週期承接前輪]

所以 Server可以按既有教學情境支援本地編排、checkpoint／scenario回覆與下一個合法場景安裝；不能僅送 `006E` 就宣稱普通戰鬥 field獲得不改context的常駐排程。普通戰鬥用到的 actor/controller欄位也不得任意套用 Tutorial的未檢查 subtype API。[復用 events §5–6、input-lifecycle]

## 5. Expedition Synopsis：完整啟用與收尾，但離場不自動等於取消

### 5.1 Gate的 producer 和正確 receiver

`4C13E0` 寫 `C07280`，RTTI為 `CExpedition`；它將 `D6A674` 設為 `45585044`（EXPD數值tag），將 field+BD78初始化為0。既有 page初始化或 control700→F4248路由抵達 `5A64B0` 時，後者要求同一tag和非空 currentfield，才 `5A64FF→4C1E10`。這是已證原生receiver來源，不是把任何有相同offset的普通field當成Expedition。[R10、R15；復用 alternate-entry §5]

`4C1FCE` 將該field+BD78寫1，`4C1FFC→4A89C0(T)` 載固定 `TutorialMain.lua`、呼 `Synopsis_EntryPoint`。原有載入／入口回傳檢查的限制承接parser：這裡不能因flag先設1就保證腳本成功。[R11、R12]

### 5.2 執行與收尾

`CExpedition+18=4C1930` 只在BD78非零時 `4C19AE` 呼 T。若實際 `T+34==0`，`4C1A1F` 移除全部tco、清native表，然後 `4C1A2F→4C2050(field)`。後者再次移除tco／清表，`4C20CA` 將BD78清0，完成既有presentation／工作物件收尾。[R13、R14]

Synopsis本身是 `PlaySynopsisMain` 的Prepare→子工作／等待／skip→End流程。`PrepareSynopsis` 與 `EndSynopsis` 有既有keymap／camera等操作；已發布原件同時證明它們是普通CALL，並非語言層 finally。若parent在抵達End前遭移除或拋錯，不能只憑函式名稱保證所有成對狀態必恢復。本稿也不把 T任務表歸零當成已送某一Server ACK。[復用 script-lifecycle §4.3、scheduler §5–6]

### 5.3 換場的反證補完

Expedition `+14=8DC2F0` 原件為 `xor eax,eax; ret`。這次並未停在空hook：其 deleting destructor `4C1530` 只處理 field+BD7C的native map、釋放sentinel／field、回寫base vptr。傳給 `5540C0` 的是該map的完整 begin/end；其命中整表分支後 `823850→73EBA0` 只遞迴釋放節點，沒有呼 payload虛擬清理或 t_removeAll。[R16–R20]

因此，**共同換場機制的 Expedition離場／destructor 本身不能替代 `4C2050` 正常收尾**。換成普通field之後，原來這個field+BD78的T更新來源已不再被選中；T／tco仍是獨立共用owner。其他更上層業務事件可能另行清理，須按具體路徑引用，不可把這個有限結論擴大成所有中斷場景都不會清理。

## 6. 劇情回顧：從正常NPC按鈕到非教學頁面中的 tco

### 6.1 新閉合的顯示入口

`CTalkBoxDialog` constructor `635930` 配置NPC component，存入dialog+BC，component+4回指dialog。component ctor `6370C0` 寫vptr `C2E588`，COL／RTTI確認 `CTalkBoxNpc`；`63882E` 將 callback `63A130` 寫入component+158。[A08、A09、A18；V_CTalkBoxDialog、V_CTalkBoxNpc]

NPC component初始化時 `638D26` push control `0x776=1910`，`638D31→615FC0` 將對應contentbutton存到component+8C。dialog的`+15C=636DE0`先把事件送給component+14=`638DE0`。後者只對UI事件`0x578`，走訪41筆control/callback：比較control+20與event+8；吻合時呼component+D8+i×4。i=32時，control欄是+8C，callback欄正是+158。[R45、R46、R61、A07；lookup的既有類型檢查只稱contentbutton，沒有把0x12D當唯一子類別RTTI]

獨立原生callback `63A130..63A16F` 建立FXUIEvent，寫event+10=`F4337`，再`63A15E→4072A0`投入既有UI事件流程。這段不在bulk函式起點清冊中；其前一個原生函式已於`63A12F`返回，本稿保存獨立bytes而不把它誤算進`639F30`。[R44]

一般UI router `595D20` 的既有路由將這類事件送page+18C。Lobby的slot=`5B7750`：`F4337−F42DB=5C`，byte table `5B7BCC=1F`，dword table `5B7B3C=5B7981`，在 `5B7983→5BAF70`。後者先關page+224的NPC視窗，再針對page+2AC的回顧視窗切換顯示。[A04、A05、D_review_switch_*、R35；路由及queue復用UI lifecycle]

顯示還有原生gate：`596E00` 要求page+F0為0，依預先登記的window group走`596EC0`。回顧的登記是group1及flags `1,1,0,0,0`；`596EC0` 的既有資料／狀態檢查通過才show。原件亦可見特定flag下沿既有sender送app值 `0x00010049`、4bytes；本稿不把它定義成下載 `.mef` 請求、不猜Server回覆策略。這些gate代表control callback存在不等於任何遊戲狀態都允許開窗。[A03、R36、R37]

### 6.2 page+2AC確實是回顧視窗，不是同offset推測

`5B52C0`在`5B5597`取page+2AC地址；`5B559D→5BDE40`取得singleton descriptor `FE2EAC`，`5B55A5→5A9F40`綁定。descriptor ctor `5C18A0`配置0x128 bytes、呼`47C370`，把window存descriptor+C、resourceID0x123存descriptor+4。descriptor v+10=`5ADE20`回+C window，v+4=`7B3250`回resourceID；`5A3840`最後將同一window pointer寫入傳入destination。[A02、R38–R43、R60]

`47C370`寫window vptr `C0312C`，RTTI為 `CScenarioReviewWnd`；其show slot+D0=`47CAB0`，hide slot+D4=`44DB00→4067F0`，UIevent slot+15C=`47C5D0`。view與所選SceneItem是不同物件；SceneItem ctor `47B480`寫`C02F3C`並把+26C初始化0。選取項目+4方法回0x12D只是繼承的contentbutton類型檢查，SceneItem具體來源由ctor／既有review資料列與建立鏈證明。[R26、R28、R58–R60；復用E63]

### 6.3 哪些正常頁面會跑這個更新

UI engine singleton `F94810` 的ctor明寫vptr `C4790C`。`750550`在currentpage+13C4非空時呼engine+28=`7507E0`；後者處理既有targeted events後，`75089C..7508AA`再取當時currentpage、呼page+184。此呼叫位置不受engine+140C那兩個輸入處理skip分支包住；但仍要求currentpage存在。[A11、R33、R34]

本輪把 `5B87B0` 的七個直接caller與各自vtable接回factory。七個直接caller不是七個已註冊page：`CPartyLobbyPage`、`CUnionPartyLobbdyPage`在此是base鏈；真正由 `5877F0`建立並以key存入page map的相關頁面如下。[A12–A16；P01–P30]

| page code | 原件型別／vtable | `+184` 到共用更新 | 初始化／離場base鏈 |
|---|---|---|---|
| 2 | `CSquarePage C1E454` | `5B2F20→5B87B0` | `5B26C0→5C29B0→5B52C0`；`5B2A30→5C2A60→5B5F90` |
| 3 | `CDuelSquarePage C1E084` | `5B1C30→5C2C60→5B87B0` | `5B1860→5C2B20→5B52C0`；`5B1A80→5C2BD0→5B5F90` |
| 4 | `CMissionLobbyPage C1D9A4` | `5B07B0→5B87B0` | 經`5C29B0/5C2A60`到共同init/leave |
| 9 | `CDuelLobbyPage C1E834` | `5B3F60→5B87B0` | 經`5C29B0/5C2A60`到共同init/leave |
| 13 (`D`) | `CRaidLobbyPage C1DD14` | `5B1290→5B87B0` | 經`5C29B0/5C2A60`到共同init/leave |
| 21 (`15`) | `CDailyDungeonLobbyPage BF6F8C` | `4234E0→5B87B0` | 經`5C29B0/5C2A60`到共同init/leave |

這六個頁面的`+15C`均為既有router `595D20`；各自`+18C` wrapper先呼共同`5B7750`，所以不只有tick相容，F4337 consumer也有原生繼承鏈（P25–P30）。

`5B87B0`本身仍先做既有base/UI更新；在`5B8AA6`取page+2AC，僅當window+28含0x100可見bit，才`5B8AB8→47C980(window)`。這是UI自己的可見mask，不是Q.EnableInput／FB8830的輸入mask，也不是controller+58。[R32；input-lifecycle區分沿用]

### 6.4 選擇60001、持續tick及完成

回顧視窗既有UI選擇路徑經 `47C5D0→47D810→47D530`；`47D810`的party條件及scene選擇資料流仍保留原件，不把任何點擊都等同啟動。[R29–R31；完整資料列來源復用E63]

`47B5C0`於`47B5EB`比較SceneItem+248是否`EA61=60001`；這個分支還要求+26C為0，才`47B601→47B850`。其他quest走既有review Q支線。`47B850`先設+26C為1，再`47BACE→4A89C0(T)`呼固定Synopsis入口。[R21、R22]

每次可見的page更新，`47C980`由window+FC→control+CC→selected+DC取項目；通過非空、contentbutton類型與項目+26C非零檢查，才`47CA45→4A8B90(T)`。如果實際T+34為0，`47CA7E→47B6B0(selected)`，後者移除全部tco、清native table並將項目+26C清0，再做presentation收尾。[R23、R24]

因此這條**非教學scene的正向runner**仍由「current page、回顧視窗可見、目前選取項目、其active欄位」共同維持。它不是只要往同一Lua VM註冊工作就會永遠更新；也不是MapList trigger名稱自動決定其file/entry。

### 6.5 主動關窗與換頁的取消邊界

不能把 `47DA00→47B6B0` 的callsite單獨寫成「按鍵可隨時取消正在跑的Synopsis」。原件先檢項目+26C；非零就返回0。之後才要求key `2AF9`，並在非active項目分支呼cleanup／hide。[R25]

另一條 `F4337→5BAF70` 若抵達，target只按window可見bit切換；hide的 `44DB00→4067F0` 呼base hide並送內部F4350。這個body沒有直接t_removeAll。是否玩家在某個modal／input狀態可再次觸發該控制，由當時UI gate決定；本稿不把target存在當成已觀測的玩家操作trace。[R27、R35、R59]

換頁方面，既有 `58A250`會呼舊page+10C並換掉currentpage。這六個page的leave最後到 `5B5F90`，其中resourceID0x123經`4095E0`解除UI綁定。這次繼續追其具體receiver：stack binder `C1920C`的+14=`585690`取manager `FAAFD8`，ctor寫`BFC9D8`，manager+30=`44E3F0`。[R47–R49、R57；A10及相關vtable]

`44E3F0`先按狀態走unload，再以window+4查cache；cache命中時跳過window destructor，只移除active UI map項目。`5BDE40`確實以window+4登記該descriptor，這個key不要與descriptor+4的resourceID0x123混淆。回顧window自己的+10C是空`5F5D10`；`745680`另遞迴呼動態child+10C。[R38、R49–R51]

即使cache不命中而進destructor，已核的 `47C510`／`47B520`是native tree／字串與baseUI清理，並沒有把 `47B6B0`當通用析構流程。baseUI仍含動態child清理，因此本稿保留該具體邊界，沒有宣稱全UI析構鏈不可能呼Lua。[R52、R53；原件導航所見base `745380`的動態+1C]

**可直接用於整合的結論是：換到普通page 5/7後，此回顧pump不再由該currentpage hook選中；隱藏／移除active視窗項目本身不能當成tco已取消的保證。** 重新顯示還會刷新review資料與選取項目，不能在沒有owner/selection證據下承諾保留原工作、立即恢復同一項目或重新載入檔案。

## 7. 普通戰鬥的精確反證及仍保留的動態邊界

ordinary page5/7的factory、安裝時機承接UI lifecycle；本輪原件重核其+184和完整body。`5AD6A0`與`5AFEB0`先呼`59B1F0`，後續是各自的UI子視窗更新，並沒有上述page+2AC→47C980鏈。這不是將field offset+2AC套到page或另一類別，也不是以類別名字作排除。[R54–R56；V_CMissionFieldPage、V_CScenarioFieldPage]

普通field的base更新 `4ADB10`仍遍歷native actor list之v+20並呼field+24；`59B1F0`含page+164的v+198、page+168選取panel的v+1A8等間接目標，Mission page又有+22C的v+16C。這些都是具體尚未宣稱全程式閉合的邊界，列在`tables.json`。本輪已把所選三條Tcaller追到正常入口／完成／離場；沒有因此順勢重掃所有UI或假稱所有動態callback都無Lua能力。

目前可證兩件不同的事：

1. Square／Lobby等非教學頁面**已能原生承載限定回顧Synopsis**，無須以改receiver來達成。
2. 已識別的普通Mission／Scenario戰鬥field/page配對，**沒有把上述任一T更新來源接成通用常駐battle runner**；仍不能把這一用途當已串接完成。

## 8. 交給Server開發與後續研究的界線

| 分類 | 需求／未知 | 已有可用介面與限制 |
|---|---|---|
| Server待開發 | 支援既有教學、Expedition／Square、review情境的合法進入與離開 | 使用已證scene/page資料及回覆，尊重原controller與view gate；原版Server內部業務規則不用還原才能開始實作 |
| Server待開發 | 選擇、授權與記錄可播放的回顧內容、章節進度及普通戰鬥狀態 | view的合法資料來源與既有特定事件可用；不要把固定60001／Synopsis直接改稱任意MapList MEF entry |
| Server待開發 | 生命週期與回報的冪等處理 | 以實際context、scene/quest身分及原生回報定義處理；tco表空／UI隱藏不是通用完成ACK。`003F`精確語意及wire使用本輪主稿，不假設每個003F均代表本次檔案執行完成 |
| 跨功能待整合 | 固定TutorialMain／子Q序列、local scheduler、UI／場景切換與Server回覆 | 已有元件可組合限定功能；tco取消、qco停止、輸入恢復與page移除必須按實際路徑分開對接 |
| Client待逆向 | `.mef`首次被正常caller選出並交給parser的橋接 | 三條固定TutorialMain入口都沒有提供MEFfilename或Serverbuffer；此缺口仍承接主稿，不以Server內容設計補造原生caller |
| Client待逆向 | 普通戰鬥可用的常駐工作入口、死亡／清組等原生事件與owner對齊 | 此題已排清三個已知T更新來源的正常適用界線；未識別的動態callback與缺失內容不等於陽性入口 |
| 待遊玩驗證 | modal狀態、skip／error／離場、資料未就緒或loader失敗時的完整操作 | 靜態gate、fallback與owner已列；不把bytes比對PASS當實際遊玩驗收 |

本稿的限定研究目標已完成：三個已知T更新caller的正常context、啟用、持續更新、任務表清空收尾與離場界線均已說清。整體`.mef`首次caller／普通battle整合仍按主稿標示；沒有以有限陰性宣稱Client完全不支援，也沒有為繼續研究提出改Client／改receiver方案。

## 9. 可重驗交付

[native-windows.json](native-windows.json)與[native-windows.asm](native-windows.asm)保存每窗VA、raw offset、end-exclusive、完整hex、SHA256及指令邊界；[tables.json](tables.json)保存vtable/COL/RTTI、六個註冊頁面、switch資料、Lua尾端及動態界線；[scoped-xrefs.json](scoped-xrefs.json)保存11個有界target的候選集合。

執行方式：

```bash
python -B verify_evidence.py --bin /path/to/02-Tartaros.bin \
  --repo /path/to/ttr_anal_multi --event-stp /path/to/06-Event.stp
```

verifier只讀原件和固定Git來源，明設 `GIT_NO_LAZY_FETCH=1`、`GIT_OPTIONAL_LOCKS=0`、`GIT_TERMINAL_PROMPT=0`並停用promisor自動下載；不執行Client或Lua。它檢查原件身分、PE的VA/raw對應、原bytes與連續指令覆蓋、vtable/RTTI/slot、限定xref、selected Lua原bytes及Git tree pins，stdout為JSON。來源blob不存在或不符時失敗，不以連網取件隱藏來源缺失。

最後計數與結果以 [verification-result.json](verification-result.json) 為準；交付檔hash在[deliverables-manifest.json](deliverables-manifest.json)。`status=PASS`僅表示上述可重驗的有界靜態檢查通過，並不自動構成T01 FULL-PASS或Server可玩。
