# 121 個正常 binding：以 MEF 能做什麼重新分類

這份表完整復用已核對的正常名稱、ABI、作用與 owner 邊界，改用「本地 MEF 工作／必要接線」導航。它不是 121 個獨立玩法，也不是 Server／Client 的責任分割線。16 個觀察數值及 1 個 loader 數值，不提供通用普通怪物存活／群清接口；104 個名稱不建立新 Lua 回傳值，仍可能有實際副作用。

來源：[已發布能力與來源鏈](../MEF-comprehensive-contracts-20261117/function-map/function-coverage.json)、[ABI](../MEF-comprehensive-contracts-20261117/abi/abi-contracts.json)、[機讀新分類](binding-offload-map.json)。本輪世界物件／戰鬥的增量證據見 [world-offload](world-offload/report.md)。

**來源與設計分開：**「原生作用／界線」復用原件研究；「MEF 開發工作／接線」是按使用者最新目標提出的設計分工。官方檔案復原不列門檻；各作用仍必須使用正確 context、參數及實際依賴。

機讀表中的功能域工作建議，不是對每個 API 額外增加參數或 owner 前置。獨立審查發現舊 catalog 的部分通用 context／完成／清理句與個別 API 不符，本輪已移除這些泛化欄位，保留逐項原生作用／限制及精確來源。例如字幕不要求 Q slot；螢幕 Kills 效果不選 Q 物件；時計不要求 renderer；直接換圖不自動取得 Q 地圖備份。

## 功能域與落點

| 功能域 | 名稱數 | MEF 開發工作 | 必要接線 |
|---|---:|---|---|
| 入口、有限演出與生命期 | 7 | 以已證 caller 啟動有限 Q 或 Tutorial；MEF 內自行串接有限步驟。 | 發布與選擇內容；對必要的既有回報接收／解除等待。 |
| Q 演出角色與領隊位置 | 16 | MEF 決定 Q 角色建立、走位、動畫與結束清理；native update 執行。 | 不為每個走位／動畫 frame 新增 Server tick；需要的共享關卡事件另接。 |
| 世界角色、外觀與繪製 | 8 | MEF 可請求世界物件生成及外觀；生成真實 CMonster 的細節見本輪 world-offload。 | 僅在跨端身分、共同戰鬥或同步需要時接 world adapter；不把沒有回傳 ID 推成禁止本地生成。 |
| 鏡頭工作、跟隨與快照 | 19 | MEF 選鏡頭／路徑／跟隨並配對 snapshot；native 插值更新。 | 按內容起動即可；Server 不逐 frame 計算鏡頭。 |
| 音樂、音效與語音 | 7 | MEF 排程 BGM、音效、語音；native 播放器持續運作。 | 提供可選中的音訊依賴；無需 Server 逐步派播放時鐘。 |
| 圖片、縮放與飛行圖片 | 5 | MEF 建立／替換／取消圖片，native 執行後續動畫及回收。 | 發布正確 texture；新圖替換前圖與延遲回收由既有 owner 契約處理。 |
| 對白、字幕、序章與書本 | 13 | MEF 可串接字幕、多列頭像對白、書本與 Prolog。 | 提供內容表／UI 資源；需要玩家意圖或任務變更時才使用相應 adapter。 |
| 教學角色、進度、UI 與 scenario | 17 | 在正確 Tutorial context 由 MEF 讀已證進度、控制旗標、角色／UI 條件並繼續流程。 | Scenario 啟動／完成只接既有 0040／004C 邊；不可把 typed Tutorial 旗標直接當普通關卡事件。 |
| 互動點與教學提示點 | 2 | MEF 可改既有點 enabled／出口視覺；Tutorial 可依固定表建立提示點。 | 入場提供點集合；若條件尚在 Server，只在條件邊界提供最小 adapter，不逐步派整段演出。 |
| 地圖、備份與小地圖 | 4 | MEF 可安排地圖載入、演出 map 備份還原與 minimap。 | 兩端實例、玩家位置與共享實體對齊；地圖規則可在 MEF，跨端轉場使用既有接口。 |
| 鍵位與輸入控制 | 4 | MEF 可切換支援鍵位與持有／釋放輸入 mask。 | 內容取得／清理相同 owner；不靠 Server 每 tick 重設控制。 |
| 淡幕、轉場、色調、黑邊與慢動作 | 12 | MEF 排淡幕、轉場、黑邊、色調及動畫慢速，native 自行更新。 | 以各自時基和 owner 收尾；無需 Server 模擬這些畫面效果。 |
| 數字、戰鬥與擊殺字樣 | 3 | MEF 可排數字、Miss／Block／Kills／Critical；這些指令不寫 HP。 | 戰鬥規則可以 MEF 定義，實際 HP／命中接口見 world-offload；不能用面板假造已完成扣血。 |
| 診斷與本機時計 | 3 | 可用的本機時計支援本地 wait；診斷並非玩法完成事件。 | 若需要跨端時序，另提供已有事件邊界；不把本地時鐘當網路時鐘。 |
| 顯示設定 | 1 | 可呼 rendering reset；本輪不把改解析度列為減輕 Server 的玩法優先項。 | 合法模式與玩家設定由實作整合；無需新增 Server 畫面執行器。 |

## 逐項原生作用與使用界線

下列名稱集合與 ABI 集合精確相等。新回值欄只表示 marshaller 是否建立新的結果，不把 closure 的 result count 誤當成功值。`UNUSABLE_STUB` 有 4 項；`NO_COUNT_RESULT` 有 1 項；其餘 116 項有可復用的有界作用／查詢。

### 入口、有限演出與生命期

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `lb.DoFile` / `0x4a1230` | 依路徑讀資源並交正式 Lua wrapper 執行。已存在合法 caller 與資源可見性；opening failure 和成功執行都可回 0，須查當次 exports/version，與大寫 global loader 契約不同。 | 可復用；符合本列 context／owner |
| `Tutorial.StartCutScene` / `0x4a9730` | 從教學編排發起既有Q演出。使用合法scene雙鍵及對應context，受Q busy／資源前置限制。 | 可復用；符合本列 context／owner |
| `Tutorial.IsCutSceneRunning` / `0x4a97b0` | 查目前Q演出running狀態。numeric狀態；不代表教學scenario／任務已結算。 本輪觀察補充：active0不保證曾啟動、成功完成或所有呈現已回收 | 可復用；符合本列 context／owner |
| `Tutorial.StopCutScene` / `0x4a9820` | 由教學入口呼Q停止與對應清理。依native Stop guard與參數分支，與正常End不同。 | 可復用；符合本列 context／owner |
| `Q.StartCutScene` / `0x561760` | 啟動雙鍵對應的有限演出。SceneList→seq；busy與prepass/formal前置仍須成立。 | 可復用；符合本列 context／owner |
| `Q.EndCutScene` / `0x561db0` | 結束Q的正常控制流程及條件式回報。不是全部資源清理；應在選定清理完成後最後呼叫。 | 可復用；符合本列 context／owner |
| `Q.IsCutSceneRunning` / `0x489cf0` | 讀Q running狀態。number；正常回0也可能由取消／停止造成。 本輪觀察補充：不含成功／取消／skip／回收原因；本target本身不lazy-init | 可復用；符合本列 context／owner |

### Q 演出角色與領隊位置

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Q.CreateObject` / `0x562ec0` | 用內容指定slot建立CEventActor演出物件。九參數，Q私有索引與prepass依賴；slot不可重複當upsert。 | 可復用；符合本列 context／owner |
| `Q.MoveObject` / `0x5632d0` | 立即改既有Q物件位置與方向。slot/x/y/direction，查Q tree；不同於普通world EntityId。 | 可復用；符合本列 context／owner |
| `Q.DeleteObject` / `0x476430` | 此 build 正常 target 為空操作。RET 4，不能作單一物件刪除；批次清理另有DeleteAllObject。 | 空操作，換用確有作用的路徑 |
| `Q.GetLeaderPosN` / `0x564610` | 取得領隊位置指定分量。分量0/1/2，不提供actor ID或存活判定。 本輪觀察補充：無leader或selector不屬0/1/2都返回0；與合法座標0不能區分；不是actor handle／worldID | 可復用；符合本列 context／owner |
| `Q.WalkObject` / `0x563330` | 讓Q物件朝目標執行走位。使用Q slot、合法動作與速度；完成可另查全Q停止狀態。 | 可復用；符合本列 context／owner |
| `Q.WarpObject` / `0x5633b0` | 將Q物件依指定位置／動作條件快速換位。與Walk的移動狀態不同；不是Server換圖。 | 可復用；符合本列 context／owner |
| `Q.AniObject` / `0x5634e0` | 選Q物件的模型動畫並設定播放倍率。需要模型對應action；動畫不寫 HP／不等於命中計算。 | 可復用；符合本列 context／owner |
| `Q.AniSkip` / `0x563530` | 調整Q物件動畫播放位置。signed整數step除render設定後加位置並clamp，無step非負gate；不是毫秒等待或跳整幕。 | 可復用；符合本列 context／owner |
| `Q.RotateObject` / `0x563660` | 設定Q物件面向／旋轉。direction取low BYTE；第三整數0走立即yaw但仍受gate，非零沿common更新。 | 可復用；符合本列 context／owner |
| `Q.SpeedObject` / `0x5636f0` | 調整Q物件的走位倍率。direct(slot,float)寫CEventActor+434；global helper另把speed-step轉倍率。 | 可復用；符合本列 context／owner |
| `Q.FaceObject` / `0x563730` | 操作Q物件的臉部表情／Face.SKIN路徑。不是朝向目標；需有效臉部資源與render owner。 | 可復用；符合本列 context／owner |
| `Q.StopObject` / `0x5637e0` | 停止指定Q物件的移動狀態。停止不等於死亡或自然到達目的地。 | 可復用；符合本列 context／owner |
| `Q.ShowObject` / `0x564900` | 切換Q物件render gate。不刪索引、不釋放actor，也不停止其update。 | 可復用；符合本列 context／owner |
| `Q.FlashObject` / `0x563790` | 設定Q物件的顏色／透明度閃爍。direct(slot,mode,ticks)由common update遞減；ticks不是固定毫秒。 | 可復用；符合本列 context／owner |
| `Q.DeleteAllObject` / `0x563a70` | 清除整個Q物件索引與持有actor。批次所有Q物件，與world actors／Lua排程owner分開。 | 可復用；符合本列 context／owner |
| `Q.IsAllObjectsStopped` / `0x564880` | 查整棵Q tree的移動pending bit。全Q集合，停止不必然是自然完成，亦無分組參數。 本輪觀察補充：空tree也回1；停止不等於動作結束、刪除、死亡或群組完成 | 可復用；符合本列 context／owner |

### 世界角色、外觀與繪製

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `lb.GetObjectCount` / `0x4a0a30` | 有登記入口，但本體是一次性 manager 初始化路徑。不提供可信的物件數／存活數查詢。 | 不能作 count／群清條件 |
| `lb.CreateObject` / `0x4a0b40` | 以簡化參數本地建立世界 actor。固定 scale=12、direction=0；model/x/y/attach，不回傳新 EntityId。 | 可復用；符合本列 context／owner |
| `lb.CreateObjectEx` / `0x4a0f70` | 指定模型、位置、縮放、面向建立世界 actor。model,x,y,scale,direction,attach；模型分支與資源須有效，本機配號。 | 可復用；符合本列 context／owner |
| `lb.SetActorAvatar` / `0x4a0b80` | 更改指定世界 actor 的外觀部件／變體。world key、part、variant；消費者是 CDoll 外觀樹，需既有 render owner。 | 可復用；符合本列 context／owner |
| `lb.AttachActorItem` / `0x4a0c50` | 把指定附件加入世界 actor 的外觀。以資源 item/actor key 查附件部件；不能當新增背包道具。 | 可復用；符合本列 context／owner |
| `lb.DetachActorItem` / `0x4a0d10` | 移除世界 actor 指定外觀部件及配對部件。刪 part 與 part+0x10；不是把 Attach 的 item key 直接反向傳回。 | 可復用；符合本列 context／owner |
| `Q.DisableObjRender` / `0x5647a0` | 暫停指定世界物件render路徑。只影響render gate，不停止全部世界simulation。 | 可復用；符合本列 context／owner |
| `Q.EnableObjRender` / `0x564810` | 恢復指定世界物件render路徑。與Q物件自己的ShowObject不同owner。 | 可復用；符合本列 context／owner |

### 鏡頭工作、跟隨與快照

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Tutorial.StopCameraWorks` / `0x4a9570` | 停止目前 CameraWorks。共享current pointer；不等於pop相機快照。 | 可復用；符合本列 context／owner |
| `Tutorial.PushCamera` / `0x4a95f0` | 以標籤保存相機快照。label對應同一相機owner，取得／釋放需成對。 | 可復用；符合本列 context／owner |
| `Tutorial.PopCamera` / `0x4a96a0` | 按標籤還原並移除相機快照。先還原與移除再比標籤；不匹配可能繼續消耗stack。 | 可復用；符合本列 context／owner |
| `Tutorial.ApplyDefaultCamera` / `0x4a9720` | 將既有預設相機值套用到相機。是預設值路徑，不是PopCamera的同義操作。 | 可復用；符合本列 context／owner |
| `CameraWorks.Load` / `0x54e970` | 從路徑載入相機keyframe工作。正確XML／frame資料，沿既有相機owner。 | 可復用；符合本列 context／owner |
| `CameraWorks.LoadRel` / `0x54e990` | 載入並對keyframe位置加相對偏移。path與XYZ offset，與Q.PlayCameraWorks的relative flag不同ABI。 | 可復用；符合本列 context／owner |
| `CameraWorks.Play` / `0x54e9e0` | 開始目前相機工作。有真實KeyFrame tick→插值→camera apply，需合格Client更新。 | 可復用；符合本列 context／owner |
| `CameraWorks.Stop` / `0x54e9f0` | 停止目前相機工作。不替代相機快照還原或其他效果清理。 | 可復用；符合本列 context／owner |
| `CameraWorks.IsEnded` / `0x54ea00` | 查目前相機工作的完成predicate。null回1，實際型別走v+20；需區分未建立與自然播完。 本輪觀察補充：current null直接回1；Stop與自然到尾可同值；不是載入成功或snapshot已還原 | 可復用；符合本列 context／owner |
| `Q.PlayCameraWorks` / `0x562b80` | 載入並開始指定camera work。字串與整數relative flag；合法XML、非空路徑與current owner前置。 | 可復用；符合本列 context／owner |
| `Q.SkipCamera` / `0x562cf0` | 在目前鏡頭工作進度加上trunc(float(k)/R)。相對增量；KeyFrame只夾尾端上界，不是絕對frame、毫秒或任意腳本skip。 | 可復用；符合本列 context／owner |
| `Q.CameraEffect` / `0x5650c0` | 向相機加入指定震動／位移效果。三int native ABI；helper有額外wait flag且等待是估算。 | 可復用；符合本列 context／owner |
| `Q.SetCameraPoint` / `0x562e10` | 立即設定相機XYZ位置。三float，與Q.MoveCamera同target，沒有插值時間。 | 可復用；符合本列 context／owner |
| `Q.BeginCameraOverride` / `0x562a60` | 保存Q演出開始前的相機快照。固定QSceneCam label；需平衡取得／釋放。 | 可復用；符合本列 context／owner |
| `Q.EndCameraOverride` / `0x562b00` | 還原Q標籤相機快照。pop先移除再比名，非可盲目重試的reset。 | 可復用；符合本列 context／owner |
| `Q.AttachCamera` / `0x563830` | 使相機工作跟隨指定Q物件節點。Q slot與CAMERA_DUMMY01；不是任意world EntityId。 | 可復用；符合本列 context／owner |
| `Q.DetachCamera` / `0x563900` | 解除目前附著相機工作。清current pointer，不pop override，不等於銷毀所有工作。 | 可復用；符合本列 context／owner |
| `Q.MoveCamera` / `0x562e10` | 立即設定相機XYZ位置。與SetCameraPoint同target，名稱不代表路徑移動。 | 可復用；符合本列 context／owner |
| `Q.RotCamera` / `0x563970` | 設定兩個相機角與局部鏡頭距離。三float中第三個為distance，不是第三旋轉軸。 | 可復用；符合本列 context／owner |

### 音樂、音效與語音

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Tutorial.PlayMusic` / `0x4a9330` | 在既有音樂播放器中請求音軌。與Q共享音樂owner，需合法資源；非同步且同名可略過重播。 | 可復用；符合本列 context／owner |
| `Q.PlayMusic` / `0x5643c0` | 請求播放指定背景音樂。與Tutorial共享CMusicPlayer，非同步，同名可不重啟。 | 可復用；符合本列 context／owner |
| `Q.StopMusic` / `0x564500` | 停止並釋放共用音樂pool的stream。操作整個16-slot pool並清pending／fade資料，不只單一當前音軌。 | 可復用；符合本列 context／owner |
| `Q.StopMusicWithFadeOut` / `0x564580` | 逐次降低音樂音量因子。fade完成至0不等於停止／釋放stream。 | 可復用；符合本列 context／owner |
| `Q.PlaySound` / `0x564cc0` | 請求播放指定一般音效。合法音效資源與音訊context；helper不等待播完。 | 可復用；符合本列 context／owner |
| `Q.PlayTalkSound` / `0x564d90` | 沿音效播放鏈請求聲音並指定Voice資源group。修改快取SoundFile的group；helper只yield，沒有本次完成handle，不是Book／Prolog共用voice handle的寫入器。 | 可復用；符合本列 context／owner |
| `Q.SetFinalMusic` / `0x565560` | 修改演出保存的後續音樂字串。null不變、首字元空白清除、其他追加；RestoreMap消費，不是立即播放。 | 可復用；符合本列 context／owner |

### 圖片、縮放與飛行圖片

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Tutorial.RegisterSkipMessage` / `0x4a9b70` | 建立持續顯示的跳過提示圖片。接texture path；不是登記Lua callable。 | 可復用；符合本列 context／owner |
| `Tutorial.RegisterScalingObject` / `0x4a9c80` | 建立指定尺寸的縮放圖片。path/width/height；由圖片owner更新／繪製。 | 可復用；符合本列 context／owner |
| `Tutorial.DestroyFlyingObjects` / `0x4a9db0` | 取消Tutorial所追蹤的圖片。標記與清tracking，實體回收可能在後續合格tick。 | 可復用；符合本列 context／owner |
| `Q.FlyingObject` / `0x564940` | 顯示具有淡入／保持／淡出狀態的圖片。path 加六個整數；配置新圖之前會先取消 M+40 追蹤的前圖，再建新圖。hold=-1 也會被後次新建取消；取消不等於同步釋放，無 Lua 完成 token。 | 可復用；符合本列 context／owner |
| `Q.DelFlyingObject` / `0x564a60` | 取消Q保存handle對應圖片。取消 M+40 單一追蹤圖並清 handle；新建入口本身也會先做此取消。實體回收延後，不是掃描共享其他 owner 圖或同步 destructor。 | 可復用；符合本列 context／owner |

### 對白、字幕、序章與書本

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Prolog.OnClose` / `0x55f950` | 明確關閉Prolog流程並發相應UI事件。是native已註冊入口；helper同名callback是否自動觸發需另看caller。 | 可復用；符合本列 context／owner |
| `Q.InsertText` / `0x5628c0` | 加入演出文字字幕queue。採設定codepage轉寬字；最多255 UTF-16 units加NUL，native無長度guard；不是多列頭像對白。 | 可復用；符合本列 context／owner |
| `Q.Prolog` / `0x564ba0` | 啟動既有Prolog文字／書頁呈現。按原表key和對應資源，狀態可由IsPrologRunning觀察。 | 可復用；符合本列 context／owner |
| `Q.IsPrologRunning` / `0x564c50` | 查Prolog文字流程是否running。0也可能是關閉／失敗／取消，需結合流程原因。 本輪觀察補充：0不證成功播放；與ScenarioTalk、Q.Dialogue及world事件分開 | 可復用；符合本列 context／owner |
| `Q.Book` / `0x565140` | 啟動原版固定書本序列。一整數ABI但native忽略參數；Table/Book.txt固定向量與voice gate，WaitForBook讀狀態。 | 可復用；符合本列 context／owner |
| `Q.Dialogue` / `0x5651f0` | 播放Prolog表指定的文字／語音演出。不是world actor聊天框；原helper只yield，本輪無專用完成query。 | 可復用；符合本列 context／owner |
| `Q.IsBookFlying` / `0x565270` | 查書本演出active狀態。0可由正常最後階段或Stop清除，不能單憑值區分原因。 本輪觀察補充：0不證曾啟動／成功；與圖片manager一般handle不同 | 可復用；符合本列 context／owner |
| `Q.BalloonTalk` / `0x550450` | 此 build 正常 target 為空操作。RET 8，兩個數值被忽略；沒有氣泡文字consumer。 | 空操作，換用確有作用的路徑 |
| `ScenarioTalkTable.open` / `0x6bd620` | 按id/scene選原表多列對白並發起。兩int＋Lua truthiness boolean手動模式；actor是頭像資料key，talk是文字key。 | 可復用；符合本列 context／owner |
| `ScenarioTalkTable.start` / `0x6bd6b0` | 開始已選定的對白資料。依原生選定資料／視窗context，不是任意新對話資料生成器。 | 可復用；符合本列 context／owner |
| `ScenarioTalkTable.hideOtherUI` / `0x6bd7f0` | 隱藏對話以外的適用UI。保留固定豁免key集合，記錄原顯示子視窗。 | 可復用；符合本列 context／owner |
| `ScenarioTalkTable.showOtherUI` / `0x6bd9b0` | 恢復同一頁面記錄的其他UI。與hideOtherUI配對，同owner生命週期。 | 可復用；符合本列 context／owner |
| `ScenarioTalkTable.hide` / `0x6bd720` | 停止對話語音並結束／隱藏對白。呼OnEndTalk、隱藏視窗、清已選定資料；不是任務結算。 | 可復用；符合本列 context／owner |

### 教學角色、進度、UI 與 scenario

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Tutorial.IsSynopsisSkipped` / `0x4a9320` | 讀取特定簡介流程的跳過紀錄。number，讀FBA7A0；不是所有內容的通用取消旗標。 本輪觀察補充：只在兩個entry清0；Stop在active檢查之前即可按選定keys設1，不是最近任意演出結果 | 可復用；符合本列 context／owner |
| `Tutorial.PostUIMessage_EmployChar` / `0x4a98d0` | 送固定雇用詢問UI事件。F431F加一個整數，由適用頁面的consumer處理。 | 可復用；符合本列 context／owner |
| `Tutorial.PostUIMessage_TutoMsg` / `0x4a9950` | 送固定教學提示UI事件。F43FD加兩個整數，不能任意指定event或callback。 | 可復用；符合本列 context／owner |
| `Tutorial.HideUI` / `0x4a99d0` | 隱藏適用當前頁面原先可見的子視窗。空豁免集合，先記錄key再virtual visibility(0)，需typed page。 | 可復用；符合本列 context／owner |
| `Tutorial.SetUIPage` / `0x4a9ae0` | 選擇固定教學頁面；同頁時送F4355刷新事件。固定page15，沒有任意page參數，不表示同步完成整頁重建。 | 可復用；符合本列 context／owner |
| `Tutorial.IsCharacterAvailable` / `0x4a9f00` | 查固定角色roster條目的可用欄位。固定 roster index 2（零起算，第 3 筆）可用性；native 不讀形式引數，不能指定任意 EntityId。 | 可復用；符合本列 context／owner |
| `Tutorial.SetControlStatus` / `0x4a9f90` | 寫入教學controller的控制旗標。已知0..31 layout及正確controller，native無bounds check。 | 可復用；符合本列 context／owner |
| `Tutorial.GetControlStatus` / `0x4a9fb0` | 讀回教學controller控制旗標。與Set同owner/index，number；不是一般世界事件查詢。 本輪觀察補充：沒有bounds/type guard；旗標可被script寫入並殘留，非可消耗事件queue | 可復用；符合本列 context／owner |
| `Tutorial.GetTutorialState` / `0x4a9fd0` | 查教學UI推進的狀態欄位。CTutoMsgDummy等特定writer，不是任意關卡完成狀態。 本輪觀察補充：無receiver/type guard；不是worldFSM、任務或群清state | 可復用；符合本列 context／owner |
| `Tutorial.InsertObject` / `0x476430` | 此 build 正常 target 為空操作。RET 4；固定教學角色可走已證InsertIsilia，不把本名稱當建立器。 | 空操作，換用確有作用的路徑 |
| `Tutorial.DeleteObject` / `0x4a9fe0` | 按教學角色鍵移除對應物件。用低BYTE轉教學world key；不同於Q.DeleteObject stub。 | 可復用；符合本列 context／owner |
| `Tutorial.InsertIsilia` / `0x4aa070` | 建立原版教學固定Isilia物件。固定world key F000、model4；不可改說任意NPC建立器。 | 可復用；符合本列 context／owner |
| `Tutorial.IsIsiliaFound` / `0x4aa240` | 判斷原版固定Isilia的教學條件。固定對象／視認鏈，不是任意actor存亡。 本輪觀察補充：0混合找不到、null actor、視錐／距離／螢幕邊界失敗；不檢查一般死亡原因 | 可復用；符合本列 context／owner |
| `Tutorial.CheckLeader` / `0x4aa4a0` | 檢查當前領隊的模型條件。取得領隊並比model低WORD是否3；不是EntityId==3。 本輪觀察補充：null回0；不回EntityId，不能指定任意model或監聽領隊lifetime | 可復用；符合本列 context／owner |
| `Tutorial.IsLeaderDialogOpened` / `0x54e740` | 查教學領隊對話UI的記錄分支。讀owner+38；show可能被gate擋住，1非嚴格可見性保證。 本輪觀察補充：既有writer可在show helper被gate擋下時仍設1；非當幀可見性保證 | 可復用；符合本列 context／owner |
| `Tutorial.RequestStartScenario` / `0x4aa4d0` | 送出教學scenario開始意圖。C2S0040加low-WORD key，需連線／合法情境；Server接續流程。 | 可復用；符合本列 context／owner |
| `Tutorial.IsScenarioEnded` / `0x4aa510` | 等待對應教學scenario的結束旗標。同Tutorial owner map，S2C004C寫入；正確context下可接續腳本。 本輪觀察補充：missing key可插入0；值1可殘留；ordinary Mission/Scenario不接受004C writer | 可復用；符合本列 context／owner |

### 互動點與教學提示點

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Tutorial.InsertTutorialCheckPoint` / `0x4a9430` | 按教學資料列建立提示點。固定category4；位置與半徑取自原表。 | 可復用；符合本列 context／owner |
| `Tutorial.SetCheckPointStatus` / `0x4a9460` | 切換既有互動點enabled；出口等類型另有視覺分支。key/category/status，與S2C0048同setter；category2/3不保證招牌外觀改變。 | 可復用；符合本列 context／owner |

### 地圖、備份與小地圖

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `lb.ChangeMap` / `0x4a0ac0` | 要求本機地圖載入器換圖。需合法 map key；兩端地圖、實體、互動點與進度另外同步。 | 可復用；符合本列 context／owner |
| `lb.LoadMinimap` / `0x4a1400` | 按 map key 重載小地圖描述與圖示資源。既有 minimap owner、BOUND→.mmt、texture與symbols須有效。 | 可復用；符合本列 context／owner |
| `Q.LoadMap` / `0x563c40` | 為演出載入地圖並備份既有map/camera。只有一份backup，不是巢狀map stack。 | 可復用；符合本列 context／owner |
| `Q.RestoreMap` / `0x563fa0` | 還原演出保存的地圖／相機並消費相關音樂設定。重寫backup欄位；資源與當前context須有效。 | 可復用；符合本列 context／owner |

### 鍵位與輸入控制

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `lb.ChangeKeymapType` / `0x4a1440` | 切換原生支援的鍵位配置。已證0/1兩分支；不等於解除所有輸入 owner。 | 可復用；符合本列 context／owner |
| `Tutorial.SetKeymapEnabled` / `0x4a94c0` | 設定教學輸入mask。數字0/1；非零清mask0x2，Lua true不等於整數1。 | 可復用；符合本列 context／owner |
| `Q.EnableInput` / `0x562980` | 清除Q指定輸入mask。不單獨釋放controller忙碌owner。 | 可復用；符合本列 context／owner |
| `Q.DisableInput` / `0x5629f0` | 設定Q指定輸入mask。需在結束時配對恢復。 | 可復用；符合本列 context／owner |

### 淡幕、轉場、色調、黑邊與慢動作

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Fade.Start` / `0x55e740` | 啟動原版全畫面淡幕。與Q.FadeIn／Out／Color共用FE2744；接方向與更新計數，不是毫秒。 | 可復用；符合本列 context／owner |
| `Fade.End` / `0x55e770` | 停止淡幕更新並可清alpha。End(0)保留當前alpha，非零才清覆蓋；draw不以active作唯一gate。 | 可復用；符合本列 context／owner |
| `Q.Transition` / `0x5646a0` | 擷取畫面並作多層放大淡出轉場。兩整數layers/rate；helper固定(2,120)，native預設(8,120)，須enabled；未有界夾任意layers。 | 可復用；符合本列 context／owner |
| `Q.ShowLetterbox` / `0x564b00` | 顯示演出上下黑邊。固定native draw owner，與Fade alpha不同。 | 可復用；符合本列 context／owner |
| `Q.HideLetterbox` / `0x564b50` | 隱藏演出上下黑邊。清對應flag，需既有renderer context。 | 可復用；符合本列 context／owner |
| `Q.FadeOut` / `0x564f30` | 啟動畫面淡出至不透明覆蓋。count為合格native更新次數的分母，不是毫秒；到255仍active，helper只yield一次。 | 可復用；符合本列 context／owner |
| `Q.FadeIn` / `0x564fb0` | 啟動畫面淡入至透明。與Q.FadeOut／Fade.Start共用遮罩；count不是毫秒，alpha到0才清active。 | 可復用；符合本列 context／owner |
| `Q.FadeColor` / `0x565040` | 設定畫面淡幕色彩。數值色彩由native consumer處理，非文字或材質資源替換。 | 可復用；符合本列 context／owner |
| `Q.StartSepia` / `0x5655c0` | 啟動褐色／色調演出狀態。需要後續native更新及renderer context。 | 可復用；符合本列 context／owner |
| `Q.EndSepia` / `0x565600` | 要求結束褐色色調效果。先置phase4，後續合格更新4→5→6→0，非立即全復原。 | 可復用；符合本列 context／owner |
| `Q.StartSlowMotion` / `0x565640` | 啟用指定actor動畫delta縮放。選定路徑約0.2倍，不改Server時鐘或所有子系統。 | 可復用；符合本列 context／owner |
| `Q.EndSlowMotion` / `0x5656b0` | 清Q slow-motion旗標。其他countdown可能仍使該動畫路徑慢速。 | 可復用；符合本列 context／owner |

### 數字、戰鬥與擊殺字樣

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `Q.NumberPanel` / `0x5652e0` | 在Q物件位置顯示數字型面板。direct style限0..5、value0無面板；排除INT32_MIN，helper另分流；不改HP。 | 可復用；符合本列 context／owner |
| `Q.BattlePanel` / `0x5653c0` | 在Q物件位置顯示Miss／Block提示面板。direct style限0..3且須先驗範圍；不執行命中、傷害或資產更新。 | 可復用；符合本列 context／owner |
| `Q.BurstStruck` / `0x565490` | 顯示擊殺數與爆擊字樣的螢幕效果。arg1非零啟動Kills及arg3數字，arg2啟動Critical；不選Q物件，不扣HP。 | 可復用；符合本列 context／owner |

### 診斷與本機時計

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `lb.SetDebugLevel` / `0x4a0aa0` | 設定 Client 診斷等級。本體只寫診斷欄位並把上端限制為9；不是玩法狀態。 | 可復用；符合本列 context／owner |
| `lb.GetTime` / `0x4a0b70` | 取得本地計時值。WINMM.timeGetTime 的32-bit原值以signed FILD轉Lua number；不是Server時鐘。 本輪觀察補充：不是時間事件、frame callback或Server時鐘；signed number轉換另見ABI審計 | 可復用；符合本列 context／owner |
| `lb.PrintCurrSceneID` / `0x5f5d10` | 此 build 正常 target 為空操作。RET，不提供 scene ID。 | 空操作，換用確有作用的路徑 |

### 顯示設定

| 名稱／native | 原生作用與界線 | MEF 使用判定 |
|---|---|---|
| `lb.ChangeResolution` / `0x4a1330` | 呼現有顯示參數與 rendering 重設路徑。三個數值參數；本次不虛構合法尺寸與模式enum。 | 可復用；符合本列 context／owner |

