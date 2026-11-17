# `.mef`／重建關卡內容的完整能力索引

本表依使用者指定的能力目標整理。每列代表固定 KR BIN 中一個正常 static binding 名稱；同 target 可有多個名字，helper也可能合成多個操作。因此 **121 是列出的介面名稱數，不是121種獨立玩法，也不是整個Client所有globals的窮盡數量**。

範圍為 Q 63、Tutorial 31、lb 14、Prolog 1、CameraWorks 5、ScenarioTalkTable 5、Fade 2。前四者復用並重核公開R10的109列，其餘12列由本輪原件補齊。Rebind屬receiver重綁設施，另外說明，不作內容能力列；原始MEF首次載入與grammar的界線維持在主稿。

每列效果都須與條件一同使用。`ENTRY_STUB` 是本build正常target的空操作；`NOT_A_COUNT_QUERY`指出GetObjectCount的實際初始化用途；其餘`CONFIRMED_BOUNDED`表示引用章節內的有界能力，不是任意資源或任何context都保證成功。完整root/callsite/registrar/slot/closure/native tuple見 [capability-index.json](capability-index.json)。

## 能力目錄

### 世界、NPC與Q角色

證據：[world-npc](world-npc/report.md)、[actors](../MEF-content-contracts-20261116/actors/report.md)、[world](../MEF-end-to-end-20261116/world/report.md)、[runner](../MEF-control-flow-20261116/runner/report.md)、[world](../MEF-control-flow-20261116/world/report.md)。

| 已註冊入口 | 能做的事 | 條件／限制 | native target |
|---|---|---|---|
| `lb.GetObjectCount` | 有登記入口，但本體是一次性 manager 初始化路徑 | 不提供可信的物件數／存活數查詢。 | `0x4a0a30` |
| `lb.ChangeMap` | 要求本機地圖載入器換圖 | 需合法 map key；兩端地圖、實體、互動點與進度另外同步。 | `0x4a0ac0` |
| `lb.CreateObject` | 以簡化參數本地建立世界 actor | 固定 scale=12、direction=0；model/x/y/attach，不回傳新 EntityId。 | `0x4a0b40` |
| `lb.CreateObjectEx` | 指定模型、位置、縮放、面向建立世界 actor | model,x,y,scale,direction,attach；模型分支與資源須有效，本機配號。 | `0x4a0f70` |
| `lb.SetActorAvatar` | 更改指定世界 actor 的外觀部件／變體 | world key、part、variant；消費者是 CDoll 外觀樹，需既有 render owner。 | `0x4a0b80` |
| `lb.AttachActorItem` | 把指定附件加入世界 actor 的外觀 | 以資源 item/actor key 查附件部件；不能當新增背包道具。 | `0x4a0c50` |
| `lb.DetachActorItem` | 移除世界 actor 指定外觀部件及配對部件 | 刪 part 與 part+0x10；不是把 Attach 的 item key 直接反向傳回。 | `0x4a0d10` |
| `Tutorial.IsCharacterAvailable` | 查固定角色roster條目的可用欄位 | 固定CCharStatus第2項+5C，不按傳入世界actor key查詢。 | `0x4a9f00` |
| `Tutorial.InsertObject` | 此 build 正常 target 為空操作 | RET 4；固定教學角色可走已證InsertIsilia，不把本名稱當建立器。 | `0x476430` |
| `Tutorial.DeleteObject` | 按教學角色鍵移除對應物件 | 用低BYTE轉教學world key；不同於Q.DeleteObject stub。 | `0x4a9fe0` |
| `Tutorial.InsertIsilia` | 建立原版教學固定Isilia物件 | 固定world key F000、model4；不可改說任意NPC建立器。 | `0x4aa070` |
| `Tutorial.IsIsiliaFound` | 判斷原版固定Isilia的教學條件 | 固定對象／視認鏈，不是任意actor存亡。 | `0x4aa240` |
| `Tutorial.CheckLeader` | 檢查當前領隊的模型條件 | 取得領隊並比model低WORD是否3；不是EntityId==3。 | `0x4aa4a0` |
| `Q.CreateObject` | 用內容指定slot建立CEventActor演出物件 | 九參數，Q私有索引與prepass依賴；slot不可重複當upsert。 | `0x562ec0` |
| `Q.MoveObject` | 立即改既有Q物件位置與方向 | slot/x/y/direction，查Q tree；不同於普通world EntityId。 | `0x5632d0` |
| `Q.DeleteObject` | 此 build 正常 target 為空操作 | RET 4，不能作單一物件刪除；批次清理另有DeleteAllObject。 | `0x476430` |
| `Q.GetLeaderPosN` | 取得領隊位置指定分量 | 分量0/1/2，不提供actor ID或存活判定。 | `0x564610` |
| `Q.WalkObject` | 讓Q物件朝目標執行走位 | 使用Q slot、合法動作與速度；完成可另查全Q停止狀態。 | `0x563330` |
| `Q.WarpObject` | 將Q物件依指定位置／動作條件快速換位 | 與Walk的移動狀態不同；不是Server換圖。 | `0x5633b0` |
| `Q.AniObject` | 選Q物件的模型動畫並設定播放倍率 | 需要模型對應action；動畫不是權威傷害計算。 | `0x5634e0` |
| `Q.AniSkip` | 調整Q物件動畫播放位置 | signed整數step除render設定後加位置並clamp，無step非負gate；不是毫秒等待或跳整幕。 | `0x563530` |
| `Q.RotateObject` | 設定Q物件面向／旋轉 | direction取low BYTE；第三整數0走立即yaw但仍受gate，非零沿common更新。 | `0x563660` |
| `Q.SpeedObject` | 調整Q物件的走位倍率 | direct(slot,float)寫CEventActor+434；global helper另把speed-step轉倍率。 | `0x5636f0` |
| `Q.FaceObject` | 操作Q物件的臉部表情／Face.SKIN路徑 | 不是朝向目標；需有效臉部資源與render owner。 | `0x563730` |
| `Q.StopObject` | 停止指定Q物件的移動狀態 | 停止不等於死亡或自然到達目的地。 | `0x5637e0` |
| `Q.ShowObject` | 切換Q物件render gate | 不刪索引、不釋放actor，也不停止其update。 | `0x564900` |
| `Q.FlashObject` | 設定Q物件的顏色／透明度閃爍 | direct(slot,mode,ticks)由common update遞減；ticks不是固定毫秒。 | `0x563790` |
| `Q.DeleteAllObject` | 清除整個Q物件索引與持有actor | 批次所有Q物件，與world actors／Lua排程owner分開。 | `0x563a70` |
| `Q.IsAllObjectsStopped` | 查整棵Q tree的移動pending bit | 全Q集合，停止不必然是自然完成，亦無分組參數。 | `0x564880` |

### 鏡頭、音訊與畫面效果

證據：[audiovisual](audiovisual/report.md)、[presentation](../MEF-control-flow-20261116/presentation/report.md)。

| 已註冊入口 | 能做的事 | 條件／限制 | native target |
|---|---|---|---|
| `Tutorial.PlayMusic` | 在既有音樂播放器中請求音軌 | 與Q共享音樂owner，需合法資源；非同步且同名可略過重播。 | `0x4a9330` |
| `Tutorial.StopCameraWorks` | 停止目前 CameraWorks | 共享current pointer；不等於pop相機快照。 | `0x4a9570` |
| `Tutorial.PushCamera` | 以標籤保存相機快照 | label對應同一相機owner，取得／釋放需成對。 | `0x4a95f0` |
| `Tutorial.PopCamera` | 按標籤還原並移除相機快照 | 先還原與移除再比標籤；不匹配可能繼續消耗stack。 | `0x4a96a0` |
| `Tutorial.ApplyDefaultCamera` | 將既有預設相機值套用到相機 | 是預設值路徑，不是PopCamera的同義操作。 | `0x4a9720` |
| `Q.PlayCameraWorks` | 載入並開始指定camera work | 字串與整數relative flag；合法XML、非空路徑與current owner前置。 | `0x562b80` |
| `Q.SkipCamera` | 在目前鏡頭工作進度加上trunc(float(k)/R) | 相對增量；KeyFrame只夾尾端上界，不是絕對frame、毫秒或任意腳本skip。 | `0x562cf0` |
| `Q.CameraEffect` | 向相機加入指定震動／位移效果 | 三int native ABI；helper有額外wait flag且等待是估算。 | `0x5650c0` |
| `Q.SetCameraPoint` | 立即設定相機XYZ位置 | 三float，與Q.MoveCamera同target，沒有插值時間。 | `0x562e10` |
| `Q.BeginCameraOverride` | 保存Q演出開始前的相機快照 | 固定QSceneCam label；需平衡取得／釋放。 | `0x562a60` |
| `Q.EndCameraOverride` | 還原Q標籤相機快照 | pop先移除再比名，非可盲目重試的reset。 | `0x562b00` |
| `Q.Transition` | 擷取畫面並作多層放大淡出轉場 | 兩整數layers/rate；helper固定(2,120)，native預設(8,120)，須enabled；未有界夾任意layers。 | `0x5646a0` |
| `Q.PlayMusic` | 請求播放指定背景音樂 | 與Tutorial共享CMusicPlayer，非同步，同名可不重啟。 | `0x5643c0` |
| `Q.StopMusic` | 停止並釋放共用音樂pool的stream | 操作整個16-slot pool並清pending／fade資料，不只單一當前音軌。 | `0x564500` |
| `Q.StopMusicWithFadeOut` | 逐次降低音樂音量因子 | fade完成至0不等於停止／釋放stream。 | `0x564580` |
| `Q.AttachCamera` | 使相機工作跟隨指定Q物件節點 | Q slot與CAMERA_DUMMY01；不是任意world EntityId。 | `0x563830` |
| `Q.DetachCamera` | 解除目前附著相機工作 | 清current pointer，不pop override，不等於銷毀所有工作。 | `0x563900` |
| `Q.MoveCamera` | 立即設定相機XYZ位置 | 與SetCameraPoint同target，名稱不代表路徑移動。 | `0x562e10` |
| `Q.RotCamera` | 設定兩個相機角與局部鏡頭距離 | 三float中第三個為distance，不是第三旋轉軸。 | `0x563970` |
| `Q.ShowLetterbox` | 顯示演出上下黑邊 | 固定native draw owner，與Fade alpha不同。 | `0x564b00` |
| `Q.HideLetterbox` | 隱藏演出上下黑邊 | 清對應flag，需既有renderer context。 | `0x564b50` |
| `Q.PlaySound` | 請求播放指定一般音效 | 合法音效資源與音訊context；helper不等待播完。 | `0x564cc0` |
| `Q.PlayTalkSound` | 沿音效播放鏈請求聲音並指定Voice資源group | 修改快取SoundFile的group；helper只yield，沒有本次完成handle，不是Book／Prolog共用voice handle的寫入器。 | `0x564d90` |
| `Q.FadeOut` | 啟動畫面淡出至不透明覆蓋 | count為合格native更新次數的分母，不是毫秒；到255仍active，helper只yield一次。 | `0x564f30` |
| `Q.FadeIn` | 啟動畫面淡入至透明 | 與Q.FadeOut／Fade.Start共用遮罩；count不是毫秒，alpha到0才清active。 | `0x564fb0` |
| `Q.FadeColor` | 設定畫面淡幕色彩 | 數值色彩由native consumer處理，非文字或材質資源替換。 | `0x565040` |
| `Q.SetFinalMusic` | 修改演出保存的後續音樂字串 | null不變、首字元空白清除、其他追加；RestoreMap消費，不是立即播放。 | `0x565560` |
| `Q.StartSepia` | 啟動褐色／色調演出狀態 | 需要後續native更新及renderer context。 | `0x5655c0` |
| `Q.EndSepia` | 要求結束褐色色調效果 | 先置phase4，後續合格更新4→5→6→0，非立即全復原。 | `0x565600` |
| `Q.StartSlowMotion` | 啟用指定actor動畫delta縮放 | 選定路徑約0.2倍，不改Server時鐘或所有子系統。 | `0x565640` |
| `Q.EndSlowMotion` | 清Q slow-motion旗標 | 其他countdown可能仍使該動畫路徑慢速。 | `0x5656b0` |
| `CameraWorks.Load` | 從路徑載入相機keyframe工作 | 正確XML／frame資料，沿既有相機owner。 | `0x54e970` |
| `CameraWorks.LoadRel` | 載入並對keyframe位置加相對偏移 | path與XYZ offset，與Q.PlayCameraWorks的relative flag不同ABI。 | `0x54e990` |
| `CameraWorks.Play` | 開始目前相機工作 | 有真實KeyFrame tick→插值→camera apply，需合格Client更新。 | `0x54e9e0` |
| `CameraWorks.Stop` | 停止目前相機工作 | 不替代相機快照還原或其他效果清理。 | `0x54e9f0` |
| `CameraWorks.IsEnded` | 查目前相機工作的完成predicate | null回1，實際型別走v+20；需區分未建立與自然播完。 | `0x54ea00` |
| `Fade.Start` | 啟動原版全畫面淡幕 | 與Q.FadeIn／Out／Color共用FE2744；接方向與更新計數，不是毫秒。 | `0x55e740` |
| `Fade.End` | 停止淡幕更新並可清alpha | End(0)保留當前alpha，非零才清覆蓋；draw不以active作唯一gate。 | `0x55e770` |

### 對白、文字與提示面板

證據：[dialogue-ui](dialogue-ui/report.md)。

| 已註冊入口 | 能做的事 | 條件／限制 | native target |
|---|---|---|---|
| `Q.InsertText` | 加入演出文字字幕queue | 採設定codepage轉寬字；最多255 UTF-16 units加NUL，native無長度guard；不是多列頭像對白。 | `0x5628c0` |
| `Q.Prolog` | 啟動既有Prolog文字／書頁呈現 | 按原表key和對應資源，狀態可由IsPrologRunning觀察。 | `0x564ba0` |
| `Q.IsPrologRunning` | 查Prolog文字流程是否running | 0也可能是關閉／失敗／取消，需結合流程原因。 | `0x564c50` |
| `Q.Book` | 啟動原版固定書本序列 | 一整數ABI但native忽略參數；Table/Book.txt固定向量與voice gate，WaitForBook讀狀態。 | `0x565140` |
| `Q.Dialogue` | 播放Prolog表指定的文字／語音演出 | 不是world actor聊天框；原helper只yield，本輪無專用完成query。 | `0x5651f0` |
| `Q.IsBookFlying` | 查書本演出active狀態 | 0可由正常最後階段或Stop清除，不能單憑值區分原因。 | `0x565270` |
| `Q.BalloonTalk` | 此 build 正常 target 為空操作 | RET 8，兩個數值被忽略；沒有氣泡文字consumer。 | `0x550450` |
| `Q.NumberPanel` | 在Q物件位置顯示數字型面板 | direct style限0..5、value0無面板；排除INT32_MIN，helper另分流；不改HP。 | `0x5652e0` |
| `Q.BattlePanel` | 在Q物件位置顯示Miss／Block提示面板 | direct style限0..3且須先驗範圍；不執行權威命中、傷害或資產更新。 | `0x5653c0` |
| `Q.BurstStruck` | 顯示擊殺數與爆擊字樣的螢幕效果 | arg1非零啟動Kills及arg3數字，arg2啟動Critical；不選Q物件，不扣HP。 | `0x565490` |
| `Prolog.OnClose` | 明確關閉Prolog流程並發相應UI事件 | 是native已註冊入口；helper同名callback是否自動觸發需另看caller。 | `0x55f950` |
| `ScenarioTalkTable.open` | 按id/scene選原表多列對白並發起 | 兩int＋Lua truthiness boolean手動模式；actor是頭像資料key，talk是文字key。 | `0x6bd620` |
| `ScenarioTalkTable.start` | 開始已選定的對白資料 | 依原生選定資料／視窗context，不是任意新對話資料生成器。 | `0x6bd6b0` |
| `ScenarioTalkTable.hideOtherUI` | 隱藏對話以外的適用UI | 保留固定豁免key集合，記錄原顯示子視窗。 | `0x6bd7f0` |
| `ScenarioTalkTable.showOtherUI` | 恢復同一頁面記錄的其他UI | 與hideOtherUI配對，同owner生命週期。 | `0x6bd9b0` |
| `ScenarioTalkTable.hide` | 停止對話語音並結束／隱藏對白 | 呼OnEndTalk、隱藏視窗、清已選定資料；不是任務結算。 | `0x6bd720` |

### 教學、互動、UI與輔助操作

證據：[control](control/report.md)。

| 已註冊入口 | 能做的事 | 條件／限制 | native target |
|---|---|---|---|
| `lb.SetDebugLevel` | 設定 Client 診斷等級 | 本體只寫診斷欄位並把上端限制為9；不是玩法狀態。 | `0x4a0aa0` |
| `lb.GetTime` | 取得本地計時值 | WINMM.timeGetTime 的32-bit原值以signed FILD轉Lua number；不是Server時鐘。 | `0x4a0b70` |
| `lb.PrintCurrSceneID` | 此 build 正常 target 為空操作 | RET，不提供 scene ID。 | `0x5f5d10` |
| `lb.ChangeResolution` | 呼現有顯示參數與 rendering 重設路徑 | 三個數值參數；本次不虛構合法尺寸與模式enum。 | `0x4a1330` |
| `lb.LoadMinimap` | 按 map key 重載小地圖描述與圖示資源 | 既有 minimap owner、BOUND→.mmt、texture與symbols須有效。 | `0x4a1400` |
| `lb.ChangeKeymapType` | 切換原生支援的鍵位配置 | 已證0/1兩分支；不等於解除所有輸入 owner。 | `0x4a1440` |
| `Tutorial.IsSynopsisSkipped` | 讀取特定簡介流程的跳過紀錄 | number，讀FBA7A0；不是所有內容的通用取消旗標。 | `0x4a9320` |
| `Tutorial.InsertTutorialCheckPoint` | 按教學資料列建立提示點 | 固定category4；位置與半徑取自原表。 | `0x4a9430` |
| `Tutorial.SetCheckPointStatus` | 切換既有互動點enabled；出口等類型另有視覺分支 | key/category/status，與S2C0048同setter；category2/3不保證招牌外觀改變。 | `0x4a9460` |
| `Tutorial.SetKeymapEnabled` | 設定教學輸入mask | 數字0/1；非零清mask0x2，Lua true不等於整數1。 | `0x4a94c0` |
| `Tutorial.HideUI` | 隱藏適用當前頁面原先可見的子視窗 | 空豁免集合，先記錄key再virtual visibility(0)，需typed page。 | `0x4a99d0` |
| `Tutorial.SetUIPage` | 選擇固定教學頁面；同頁時送F4355刷新事件 | 固定page15，沒有任意page參數，不表示同步完成整頁重建。 | `0x4a9ae0` |
| `Tutorial.SetControlStatus` | 寫入教學controller的控制旗標 | 已知0..31 layout及正確controller，native無bounds check。 | `0x4a9f90` |
| `Tutorial.GetControlStatus` | 讀回教學controller控制旗標 | 與Set同owner/index，number；不是一般世界事件查詢。 | `0x4a9fb0` |
| `Tutorial.GetTutorialState` | 查教學UI推進的狀態欄位 | CTutoMsgDummy等特定writer，不是任意關卡完成狀態。 | `0x4a9fd0` |
| `Tutorial.IsLeaderDialogOpened` | 查教學領隊對話UI的記錄分支 | 讀owner+38；show可能被gate擋住，1非嚴格可見性保證。 | `0x54e740` |
| `Tutorial.RequestStartScenario` | 送出教學scenario開始意圖 | C2S0040加low-WORD key，需連線／合法情境；Server接續流程。 | `0x4aa4d0` |
| `Tutorial.IsScenarioEnded` | 等待對應教學scenario的結束旗標 | 同Tutorial owner map，S2C004C寫入；正確context下可接續腳本。 | `0x4aa510` |

### 載入、演出與生命週期

證據：[entry](../MEF-end-to-end-20261116/entry/report.md)、[presentation](../MEF-control-flow-20261116/presentation/report.md)、[MEF-entry-lifecycle-events-20261114](../MEF-entry-lifecycle-events-20261114/lifecycle.md)。

| 已註冊入口 | 能做的事 | 條件／限制 | native target |
|---|---|---|---|
| `lb.DoFile` | 依路徑讀資源並交正式 Lua wrapper 執行 | 不同於全域DoFile的0/1契約；不得把closure結果個數當載入成功值。 | `0x4a1230` |
| `Tutorial.StartCutScene` | 從教學編排發起既有Q演出 | 使用合法scene雙鍵及對應context，受Q busy／資源前置限制。 | `0x4a9730` |
| `Tutorial.IsCutSceneRunning` | 查目前Q演出running狀態 | numeric狀態；不代表教學scenario／任務已結算。 | `0x4a97b0` |
| `Tutorial.StopCutScene` | 由教學入口呼Q停止與對應清理 | 依native Stop guard與參數分支，與正常End不同。 | `0x4a9820` |
| `Q.StartCutScene` | 啟動雙鍵對應的有限演出 | SceneList→seq；busy與prepass/formal前置仍須成立。 | `0x561760` |
| `Q.EndCutScene` | 結束Q的正常控制流程及條件式回報 | 不是全部資源清理；應在選定清理完成後最後呼叫。 | `0x561db0` |
| `Q.IsCutSceneRunning` | 讀Q running狀態 | number；正常回0也可能由取消／停止造成。 | `0x489cf0` |
| `Q.EnableInput` | 清除Q指定輸入mask | 不單獨釋放controller忙碌owner。 | `0x562980` |
| `Q.DisableInput` | 設定Q指定輸入mask | 需在結束時配對恢復。 | `0x5629f0` |
| `Q.LoadMap` | 為演出載入地圖並備份既有map/camera | 只有一份backup，不是巢狀map stack。 | `0x563c40` |
| `Q.RestoreMap` | 還原演出保存的地圖／相機並消費相關音樂設定 | 重寫backup欄位；資源與當前context須有效。 | `0x563fa0` |
| `Q.DisableObjRender` | 暫停指定世界物件render路徑 | 只影響render gate，不停止全部世界simulation。 | `0x5647a0` |
| `Q.EnableObjRender` | 恢復指定世界物件render路徑 | 與Q物件自己的ShowObject不同owner。 | `0x564810` |

### 圖片與固定UI事件

證據：[world](../MEF-control-flow-20261116/world/report.md)、[runner](../MEF-control-flow-20261116/runner/report.md)。

| 已註冊入口 | 能做的事 | 條件／限制 | native target |
|---|---|---|---|
| `Tutorial.PostUIMessage_EmployChar` | 送固定雇用詢問UI事件 | F431F加一個整數，由適用頁面的consumer處理。 | `0x4a98d0` |
| `Tutorial.PostUIMessage_TutoMsg` | 送固定教學提示UI事件 | F43FD加兩個整數，不能任意指定event或callback。 | `0x4a9950` |
| `Tutorial.RegisterSkipMessage` | 建立持續顯示的跳過提示圖片 | 接texture path；不是登記Lua callable。 | `0x4a9b70` |
| `Tutorial.RegisterScalingObject` | 建立指定尺寸的縮放圖片 | path/width/height；由圖片owner更新／繪製。 | `0x4a9c80` |
| `Tutorial.DestroyFlyingObjects` | 取消Tutorial所追蹤的圖片 | 標記與清tracking，實體回收可能在後續合格tick。 | `0x4a9db0` |
| `Q.FlyingObject` | 顯示具有淡入／保持／淡出狀態的圖片 | path加六int，handle保留native；helper只yield一次。 | `0x564940` |
| `Q.DelFlyingObject` | 取消Q保存handle對應圖片 | 標alive並重設handle，實體回收可能延後。 | `0x564a60` |

## helper、直接native與來源資料分開看

原版qbase共有75個root closure exports。本輪全部從原件重新解析並生成結構索引；完整列表見 [helper-catalog.md](helper-catalog.md)，opcode-derived欄位與code SHA見 [control/helper-index.json](control/helper-index.json)。helper參數個數是prototype固定形參，不保證全部必填、沒有defaults或能直接套到同名native。

多數native wrapper未建立新Lua成功值；外層closure回傳個數1不能當成功ACK。數值型marshaller、ScenarioTalkTable的Lua truthiness boolean、不同namespace的slot/key、共享owner，以及phase／yield差異，均按相應分題使用。

商店、普通買賣／強化與checkpoint互動是已證原生功能鏈；本表不虛構名為OpenShop等不存在於本次已列surface的Lua入口。如何透過既有point／NPC／table組合見 [world-npc/report.md](world-npc/report.md)。
