# 121 個正常綁定的完整 ABI 表

本表的「完整」限定已固定 registrar 集合；不包括 prepass stubs、標準函式庫、全域 DoFile、動態重綁或未識別的官方 MEF。語義摘要復用既有 R11；本輪從原 BIN 新核全部 closure／marshaller 參數、順序及回值 producer。

- `I`：數字／可解析數字字串經 x87 FISTP 轉 signed DWORD；內容工具要求明確的32位整數。
- `F`：數字／可解析數字字串轉單精度；內容工具要求有限數值。
- `S`：字串或數字轉文字；內容工具要求非空字串。
- `B`：Lua truthiness；內容工具要求明確 boolean。只有 ScenarioTalkTable.open 的最後一格使用此類。
- `新 number`：binding 確實寫新 TValue；不是通用成功 ACK。`未建立`：closure 的回傳個數1不能作原生結果。
- 參數欄依正常 dot-call 的左至右順序；實際從 stack 尾端取 N 格。無 argc 檢查。

| 名稱 | 參數 | 新回值 | native / marshaller | 能力與限制來源 |
|---|---|---|---|---|
| `lb.SetDebugLevel` | I | 未建立 | `0x4a0aa0` / `0x4a23e0` | 設定 Client 診斷等級 |
| `lb.GetObjectCount` | 無 | 未建立 | `0x4a0a30` / 直接呼叫 | 有登記入口，但本體是一次性 manager 初始化路徑；NOT_COUNT_QUERY |
| `lb.ChangeMap` | I | 未建立 | `0x4a0ac0` / `0x4a23e0` | 要求本機地圖載入器換圖 |
| `lb.CreateObject` | I, F, F, I | 未建立 | `0x4a0b40` / `0x4a2460` | 以簡化參數本地建立世界 actor |
| `lb.CreateObjectEx` | I, F, F, I, I, I | 未建立 | `0x4a0f70` / `0x4a25f0` | 指定模型、位置、縮放、面向建立世界 actor |
| `lb.SetActorAvatar` | I, I, I | 未建立 | `0x4a0b80` / `0x4a2850` | 更改指定世界 actor 的外觀部件／變體 |
| `lb.AttachActorItem` | I, I | 未建立 | `0x4a0c50` / `0x4a2990` | 把指定附件加入世界 actor 的外觀 |
| `lb.DetachActorItem` | I, I | 未建立 | `0x4a0d10` / `0x4a2990` | 移除世界 actor 指定外觀部件及配對部件 |
| `lb.GetTime` | 無 | 新 number | `0x4a0b70` / 直接呼叫 | 取得本地計時值 |
| `lb.DoFile` | S | 新 number（loader有歧義） | `0x4a1230` / `0x4a2a70` | 依路徑讀資源並交正式 Lua wrapper 執行 |
| `lb.PrintCurrSceneID` | 無 | 未建立 | `0x5f5d10` / 直接呼叫 | 此 build 正常 target 為空操作；STUB |
| `lb.ChangeResolution` | I, I, I | 未建立 | `0x4a1330` / `0x4a2850` | 呼現有顯示參數與 rendering 重設路徑 |
| `lb.LoadMinimap` | I | 未建立 | `0x4a1400` / `0x4a23e0` | 按 map key 重載小地圖描述與圖示資源 |
| `lb.ChangeKeymapType` | I | 未建立 | `0x4a1440` / `0x4a23e0` | 切換原生支援的鍵位配置 |
| `Tutorial.IsSynopsisSkipped` | 無 | 新 number | `0x4a9320` / 直接呼叫 | 讀取特定簡介流程的跳過紀錄 |
| `Tutorial.PlayMusic` | S, I | 未建立 | `0x4a9330` / `0x4acaa0` | 在既有音樂播放器中請求音軌 |
| `Tutorial.InsertTutorialCheckPoint` | I | 未建立 | `0x4a9430` / `0x4acb70` | 按教學資料列建立提示點 |
| `Tutorial.SetCheckPointStatus` | I, I, I | 未建立 | `0x4a9460` / `0x4acbf0` | 切換既有互動點enabled；出口等類型另有視覺分支 |
| `Tutorial.SetKeymapEnabled` | I | 未建立 | `0x4a94c0` / `0x4acb70` | 設定教學輸入mask |
| `Tutorial.StopCameraWorks` | 無 | 未建立 | `0x4a9570` / 直接呼叫 | 停止目前 CameraWorks |
| `Tutorial.PushCamera` | S | 未建立 | `0x4a95f0` / `0x4acd30` | 以標籤保存相機快照 |
| `Tutorial.PopCamera` | S | 未建立 | `0x4a96a0` / `0x4acd30` | 按標籤還原並移除相機快照 |
| `Tutorial.ApplyDefaultCamera` | 無 | 未建立 | `0x4a9720` / 直接呼叫 | 將既有預設相機值套用到相機 |
| `Tutorial.StartCutScene` | I, I | 未建立 | `0x4a9730` / `0x4acd90` | 從教學編排發起既有Q演出 |
| `Tutorial.IsCutSceneRunning` | 無 | 新 number | `0x4a97b0` / 直接呼叫 | 查目前Q演出running狀態 |
| `Tutorial.StopCutScene` | 無 | 未建立 | `0x4a9820` / 直接呼叫 | 由教學入口呼Q停止與對應清理 |
| `Tutorial.PostUIMessage_EmployChar` | I | 未建立 | `0x4a98d0` / `0x4acb70` | 送固定雇用詢問UI事件 |
| `Tutorial.PostUIMessage_TutoMsg` | I, I | 未建立 | `0x4a9950` / `0x4acd90` | 送固定教學提示UI事件 |
| `Tutorial.HideUI` | 無 | 未建立 | `0x4a99d0` / 直接呼叫 | 隱藏適用當前頁面原先可見的子視窗 |
| `Tutorial.SetUIPage` | 無 | 未建立 | `0x4a9ae0` / 直接呼叫 | 選擇固定教學頁面；同頁時送F4355刷新事件 |
| `Tutorial.RegisterSkipMessage` | S | 未建立 | `0x4a9b70` / `0x4acd30` | 建立持續顯示的跳過提示圖片 |
| `Tutorial.RegisterScalingObject` | S, I, I | 未建立 | `0x4a9c80` / `0x4ace70` | 建立指定尺寸的縮放圖片 |
| `Tutorial.DestroyFlyingObjects` | 無 | 未建立 | `0x4a9db0` / 直接呼叫 | 取消Tutorial所追蹤的圖片 |
| `Tutorial.IsCharacterAvailable` | I | 新 number | `0x4a9f00` / `0x4acf90` | 查固定角色roster條目的可用欄位 |
| `Tutorial.SetControlStatus` | I, I | 未建立 | `0x4a9f90` / `0x4acd90` | 寫入教學controller的控制旗標 |
| `Tutorial.GetControlStatus` | I | 新 number | `0x4a9fb0` / `0x4acf90` | 讀回教學controller控制旗標 |
| `Tutorial.GetTutorialState` | 無 | 新 number | `0x4a9fd0` / 直接呼叫 | 查教學UI推進的狀態欄位 |
| `Tutorial.InsertObject` | I | 未建立 | `0x476430` / `0x4acb70` | 此 build 正常 target 為空操作；STUB |
| `Tutorial.DeleteObject` | I | 未建立 | `0x4a9fe0` / `0x4acb70` | 按教學角色鍵移除對應物件 |
| `Tutorial.InsertIsilia` | 無 | 未建立 | `0x4aa070` / 直接呼叫 | 建立原版教學固定Isilia物件 |
| `Tutorial.IsIsiliaFound` | 無 | 新 number | `0x4aa240` / 直接呼叫 | 判斷原版固定Isilia的教學條件 |
| `Tutorial.CheckLeader` | 無 | 新 number | `0x4aa4a0` / 直接呼叫 | 檢查當前領隊的模型條件 |
| `Tutorial.IsLeaderDialogOpened` | 無 | 新 number | `0x54e740` / 直接呼叫 | 查教學領隊對話UI的記錄分支 |
| `Tutorial.RequestStartScenario` | I | 未建立 | `0x4aa4d0` / `0x4acb70` | 送出教學scenario開始意圖 |
| `Tutorial.IsScenarioEnded` | I | 新 number | `0x4aa510` / `0x4acf90` | 等待對應教學scenario的結束旗標 |
| `CameraWorks.Load` | S | 未建立 | `0x54e970` / `0x54f030` | 從路徑載入相機keyframe工作 |
| `CameraWorks.LoadRel` | S, F, F, F | 未建立 | `0x54e990` / `0x54f0a0` | 載入並對keyframe位置加相對偏移 |
| `CameraWorks.Play` | 無 | 未建立 | `0x54e9e0` / 直接呼叫 | 開始目前相機工作 |
| `CameraWorks.Stop` | 無 | 未建立 | `0x54e9f0` / 直接呼叫 | 停止目前相機工作 |
| `CameraWorks.IsEnded` | 無 | 新 number | `0x54ea00` / 直接呼叫 | 查目前相機工作的完成predicate |
| `Fade.Start` | I, I | 未建立 | `0x55e740` / `0x55eb50` | 啟動原版全畫面淡幕 |
| `Fade.End` | I | 未建立 | `0x55e770` / `0x55ec40` | 停止淡幕更新並可清alpha |
| `Prolog.OnClose` | 無 | 未建立 | `0x55f950` / 直接呼叫 | 明確關閉Prolog流程並發相應UI事件 |
| `Q.StartCutScene` | I, I | 未建立 | `0x561760` / `0x56a220` | 啟動雙鍵對應的有限演出 |
| `Q.EndCutScene` | 無 | 未建立 | `0x561db0` / 直接呼叫 | 結束Q的正常控制流程及條件式回報 |
| `Q.IsCutSceneRunning` | 無 | 新 number | `0x489cf0` / 直接呼叫 | 讀Q running狀態 |
| `Q.InsertText` | S | 未建立 | `0x5628c0` / `0x56a300` | 加入演出文字字幕queue |
| `Q.EnableInput` | 無 | 未建立 | `0x562980` / 直接呼叫 | 清除Q指定輸入mask |
| `Q.DisableInput` | 無 | 未建立 | `0x5629f0` / 直接呼叫 | 設定Q指定輸入mask |
| `Q.PlayCameraWorks` | S, I | 未建立 | `0x562b80` / `0x56a360` | 載入並開始指定camera work |
| `Q.SkipCamera` | I | 未建立 | `0x562cf0` / `0x56a430` | 在目前鏡頭工作進度加上trunc(float(k)/R) |
| `Q.CameraEffect` | I, I, I | 未建立 | `0x5650c0` / `0x56a4b0` | 向相機加入指定震動／位移效果 |
| `Q.SetCameraPoint` | F, F, F | 未建立 | `0x562e10` / `0x56a5f0` | 立即設定相機XYZ位置 |
| `Q.CreateObject` | I, I, F, F, I, I, I, I, I | 未建立 | `0x562ec0` / `0x56a710` | 用內容指定slot建立CEventActor演出物件 |
| `Q.MoveObject` | I, F, F, I | 未建立 | `0x5632d0` / `0x56aaa0` | 立即改既有Q物件位置與方向 |
| `Q.DeleteObject` | I | 未建立 | `0x476430` / `0x56a430` | 此 build 正常 target 為空操作；STUB |
| `Q.BeginCameraOverride` | 無 | 未建立 | `0x562a60` / 直接呼叫 | 保存Q演出開始前的相機快照 |
| `Q.EndCameraOverride` | 無 | 未建立 | `0x562b00` / 直接呼叫 | 還原Q標籤相機快照 |
| `Q.GetLeaderPosN` | I | 新 number | `0x564610` / `0x56b590` | 取得領隊位置指定分量 |
| `Q.Transition` | I, I | 未建立 | `0x5646a0` / `0x56a220` | 擷取畫面並作多層放大淡出轉場 |
| `Q.PlayMusic` | S, I | 未建立 | `0x5643c0` / `0x56a360` | 請求播放指定背景音樂 |
| `Q.StopMusic` | 無 | 未建立 | `0x564500` / 直接呼叫 | 停止並釋放共用音樂pool的stream |
| `Q.StopMusicWithFadeOut` | I | 未建立 | `0x564580` / `0x56a430` | 逐次降低音樂音量因子 |
| `Q.AttachCamera` | I | 未建立 | `0x563830` / `0x56a430` | 使相機工作跟隨指定Q物件節點 |
| `Q.DetachCamera` | 無 | 未建立 | `0x563900` / 直接呼叫 | 解除目前附著相機工作 |
| `Q.MoveCamera` | F, F, F | 未建立 | `0x562e10` / `0x56a5f0` | 立即設定相機XYZ位置 |
| `Q.RotCamera` | F, F, F | 未建立 | `0x563970` / `0x56a5f0` | 設定兩個相機角與局部鏡頭距離 |
| `Q.WalkObject` | I, F, F, I, I, F | 未建立 | `0x563330` / `0x56ac30` | 讓Q物件朝目標執行走位 |
| `Q.WarpObject` | I, F, F, I, I, I | 未建立 | `0x5633b0` / `0x56ae80` | 將Q物件依指定位置／動作條件快速換位 |
| `Q.AniObject` | I, I, F | 未建立 | `0x5634e0` / `0x56b0e0` | 選Q物件的模型動畫並設定播放倍率 |
| `Q.AniSkip` | I, I | 未建立 | `0x563530` / `0x56a220` | 調整Q物件動畫播放位置 |
| `Q.RotateObject` | I, I, I | 未建立 | `0x563660` / `0x56a4b0` | 設定Q物件面向／旋轉 |
| `Q.SpeedObject` | I, F | 未建立 | `0x5636f0` / `0x56b210` | 調整Q物件的走位倍率 |
| `Q.FaceObject` | I, I, I | 未建立 | `0x563730` / `0x56a4b0` | 操作Q物件的臉部表情／Face.SKIN路徑 |
| `Q.StopObject` | I | 未建立 | `0x5637e0` / `0x56a430` | 停止指定Q物件的移動狀態 |
| `Q.ShowObject` | I, I | 未建立 | `0x564900` / `0x56a220` | 切換Q物件render gate |
| `Q.FlashObject` | I, I, I | 未建立 | `0x563790` / `0x56a4b0` | 設定Q物件的顏色／透明度閃爍 |
| `Q.DeleteAllObject` | 無 | 未建立 | `0x563a70` / 直接呼叫 | 清除整個Q物件索引與持有actor |
| `Q.LoadMap` | S | 未建立 | `0x563c40` / `0x56a300` | 為演出載入地圖並備份既有map/camera |
| `Q.RestoreMap` | 無 | 未建立 | `0x563fa0` / 直接呼叫 | 還原演出保存的地圖／相機並消費相關音樂設定 |
| `Q.DisableObjRender` | 無 | 未建立 | `0x5647a0` / 直接呼叫 | 暫停指定世界物件render路徑 |
| `Q.EnableObjRender` | 無 | 未建立 | `0x564810` / 直接呼叫 | 恢復指定世界物件render路徑 |
| `Q.IsAllObjectsStopped` | 無 | 新 number | `0x564880` / 直接呼叫 | 查整棵Q tree的移動pending bit |
| `Q.FlyingObject` | S, I, I, I, I, I, I | 未建立 | `0x564940` / `0x56b2e0` | 顯示具有淡入／保持／淡出狀態的圖片 |
| `Q.DelFlyingObject` | 無 | 未建立 | `0x564a60` / 直接呼叫 | 取消Q保存handle對應圖片 |
| `Q.ShowLetterbox` | 無 | 未建立 | `0x564b00` / 直接呼叫 | 顯示演出上下黑邊 |
| `Q.HideLetterbox` | 無 | 未建立 | `0x564b50` / 直接呼叫 | 隱藏演出上下黑邊 |
| `Q.Prolog` | I | 未建立 | `0x564ba0` / `0x56a430` | 啟動既有Prolog文字／書頁呈現 |
| `Q.IsPrologRunning` | 無 | 新 number | `0x564c50` / 直接呼叫 | 查Prolog文字流程是否running |
| `Q.PlaySound` | S | 未建立 | `0x564cc0` / `0x56a300` | 請求播放指定一般音效 |
| `Q.PlayTalkSound` | S | 未建立 | `0x564d90` / `0x56a300` | 沿音效播放鏈請求聲音並指定Voice資源group |
| `Q.FadeOut` | I | 未建立 | `0x564f30` / `0x56a430` | 啟動畫面淡出至不透明覆蓋 |
| `Q.FadeIn` | I | 未建立 | `0x564fb0` / `0x56a430` | 啟動畫面淡入至透明 |
| `Q.FadeColor` | I | 未建立 | `0x565040` / `0x56b630` | 設定畫面淡幕色彩 |
| `Q.Book` | I | 未建立 | `0x565140` / `0x56a430` | 啟動原版固定書本序列 |
| `Q.Dialogue` | I | 未建立 | `0x5651f0` / `0x56a430` | 播放Prolog表指定的文字／語音演出 |
| `Q.IsBookFlying` | 無 | 新 number | `0x565270` / 直接呼叫 | 查書本演出active狀態 |
| `Q.BalloonTalk` | I, I | 未建立 | `0x550450` / `0x56a220` | 此 build 正常 target 為空操作；STUB |
| `Q.NumberPanel` | I, I, I | 未建立 | `0x5652e0` / `0x56a4b0` | 在Q物件位置顯示數字型面板 |
| `Q.BattlePanel` | I, I | 未建立 | `0x5653c0` / `0x56a220` | 在Q物件位置顯示Miss／Block提示面板 |
| `Q.BurstStruck` | I, I, I | 未建立 | `0x565490` / `0x56a4b0` | 顯示擊殺數與爆擊字樣的螢幕效果 |
| `Q.SetFinalMusic` | S | 未建立 | `0x565560` / `0x56a300` | 修改演出保存的後續音樂字串 |
| `Q.StartSepia` | I | 未建立 | `0x5655c0` / `0x56a430` | 啟動褐色／色調演出狀態 |
| `Q.EndSepia` | I | 未建立 | `0x565600` / `0x56a430` | 要求結束褐色色調效果 |
| `Q.StartSlowMotion` | 無 | 未建立 | `0x565640` / 直接呼叫 | 啟用指定actor動畫delta縮放 |
| `Q.EndSlowMotion` | 無 | 未建立 | `0x5656b0` / 直接呼叫 | 清Q slow-motion旗標 |
| `ScenarioTalkTable.open` | I, I, B | 未建立 | `0x6bd620` / `0x6be090` | 按id/scene選原表多列對白並發起 |
| `ScenarioTalkTable.start` | 無 | 未建立 | `0x6bd6b0` / 直接呼叫 | 開始已選定的對白資料 |
| `ScenarioTalkTable.hideOtherUI` | 無 | 未建立 | `0x6bd7f0` / 直接呼叫 | 隱藏對話以外的適用UI |
| `ScenarioTalkTable.showOtherUI` | 無 | 未建立 | `0x6bd9b0` / 直接呼叫 | 恢復同一頁面記錄的其他UI |
| `ScenarioTalkTable.hide` | 無 | 未建立 | `0x6bd720` / 直接呼叫 | 停止對話語音並結束／隱藏對白 |

逐列原件地址、input slot、conversion instruction 與 result producer 見 [abi-contracts.json](abi-contracts.json)。能力語義與實際 owner 見 [既有能力手冊](../../MEF-capabilities-20261116/capability-catalog.md)及本輪[可觀察事件分析](../events/report.md)。名稱存在不等於新內容已部署。
