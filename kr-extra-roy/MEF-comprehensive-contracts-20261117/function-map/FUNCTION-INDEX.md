# MEF 全功能導航：121 個正常 binding 與四層後續工作

本索引把已證的完整正常註冊集合逐項連到玩家功能與開發工作。**世界／Q 角色、鏡頭、音訊、圖片、對白、教學、互動點、地圖與畫面效果都有可引用的 native 能力；尚未部署不等於這些功能全部未知或不可用。** 每個原始 API 名稱在下方逐項表恰好出現一次，總數 121。完整機讀契約見 [function-coverage.json](function-coverage.json)。

本輪圖片新建採「先取消前張，再建立新圖」的原件勘誤；模型跨段落採 CDoll 同資源引用／回載的補證，不以單一 level3 預載層推斷必然卸載。同輪更正優先於舊族表的相反推論：[U0](../reuse/report.md)、[U1](../reuse-followup/report.md)。

基線 `extra/roy1 @ 5ef4ab8870ea1c65c6c7497901302d851f5c7a51`；原 BIN SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本包只整理固定來源與本輪 ABI／觀察結果，沒有新增原件逆向、執行遊戲或修改正式 Task／RR。

## 1. 完成度分層，不合成百分比

| 層次 | 本導航的判準 | 目前可說的事 |
|---|---|---|
| 已證 native 能力 | 正常名稱、實際 target、所引原報告的效果及限制 | 116 個名稱有有界效果／查詢契約；另 4 個已證 stub、1 個已證沒有 count。alias、同 target、共用 owner 不變成獨立玩法數。 |
| Client 待逆向 | 官方 MEF 首次 reader／grammar、B 首次入口、普通 world typed observer，以及個別尚缺的合法值域 | 這些精確缺口不能被 Server 猜成 wire；也不否定已有有限內容和 native 呈現。 |
| Server 待開發 | 合法觸發、世界／群組權威、交易／資產、轉場、run、完成／取消與保存 | 依既有封包與入口開發；不必等原版 Server 內部全部還原。 |
| 跨功能待整合 | 實際內容 keys、資源版本、合法 caller、owner 取得／清理、第二次使用 | ABI 正確與原生子鏈已證之後，仍需完成具體內容的聯合預驗與交付。 |
| 待遊玩驗證 | 真實 Client 的呈現、聲音、操作恢復、返回、再觸發及 Server 一致性 | 此批沒有新增 Client／Lua／Server 執行或遊玩通過記錄。 |

以下「主要工作」是 Server 開發專案的下一步排序，**不是唯一缺口，也不是 API 可用性判決**。機讀資料每列分別保存四層狀態。對本地效果，Server 欄明示僅在用作 Server 驅動玩法時才有相關要求，不另發明 Server 相機／音效執行器。

本表不重置 main 已有 Server 功能、工程或人測狀態；Server 欄列的是本輪內容所需契約，應由 S00 對照既有需求去重，已實作部分直接復用。待整合／待遊玩是指此次新增內容尚未交付這些結果，不是說原版從未具有該效果。

## 2. 功能域總覽

| 功能域 | 名稱數 | 已證能力與整合方向 |
|---|---:|---|
| 入口、有限演出與生命期 | 7 | 相容 loader、Q／Tutorial 演出啟停與 running；合法 caller、排程和收尾需接成同一流程。 |
| Q 演出角色與領隊位置 | 16 | Q slot、建立、走位、動畫、表情、顯示、批次清理與位置分量；不冒稱普通世界怪物。 |
| 世界角色、外觀與繪製 | 8 | 本地 world 建立、CDoll 外觀／掛件、世界 render gate；權威 EntityId 與資產另由 Server 管理。 |
| 鏡頭工作、跟隨與快照 | 19 | KeyFrame、相對偏移、跟隨、位置／角度與 snapshot；current owner／pop 的配對是必要條件。 |
| 音樂、音效與語音 | 7 | 共享 BGM、停止／淡出、後續恢復音軌、一般 sound／Voice group；播放、靜音與釋放分開。 |
| 圖片、縮放與飛行圖片 | 5 | Tutorial tracking 與 Q 單一追蹤 handle 為不同 owner；新 Q 圖先取消前張，實體回收另等 manager。 |
| 對白、字幕、序章與書本 | 13 | 多列頭像對話、字幕、Prolog／Book；固定表、語音、UI 情境、完成與取消需分開。 |
| 教學角色、進度、UI 與 scenario | 17 | 固定角色／領隊條件、32 槽進度、頁面／UI 事件及 Tutorial scenario 往返；不是普通死亡事件。 |
| 互動點與教學提示點 | 2 | 既有點的 enabled 與固定教學表建立；category/key、latch/progress、Server 快照與開放條件分開。 |
| 地圖、備份與小地圖 | 4 | 本地地圖載入、Q 單份備份、BOUND/mmt/texture/symbols；不等於 Server 轉場已完成。 |
| 鍵位與輸入控制 | 4 | 鍵位配置與 mask；清 mask 不等於清 controller busy 或 UI capture。 |
| 淡幕、轉場、色調、黑邊與慢動作 | 12 | 各自 native owner 和時基；停止、透明、資源回收及 Server 時間是不同事項。 |
| 數字、戰鬥與擊殺字樣 | 3 | 數字／Miss／Block／Kills／Critical 的呈現；不改 HP、不提交命中或獎勵。 |
| 診斷與本機時計 | 3 | 診斷欄位、本機時計及已確認空 scene-ID 入口；不當任務結果。 |
| 顯示設定 | 1 | 已證三值傳入 rendering reset；合法模式值未全面定義。 |

16 個觀察查詢與 1 個 loader 會建立新 number；其餘 104 個 binding 不建立新結果。**無新值不等於沒有副作用**，而 stub 則是該 target 已確認沒有名稱暗示的作用。number 0 在 Lua 仍為真；完成、取消、持有及回收按各 owner 契約處理。所有列的 ABI 來自 [A0](../abi/abi-contracts.json)，能力與條件來自 [C0](../../MEF-capabilities-20261116/capability-index.json)，生命期來自 [L0](../../MEF-feature-lifecycle-20261117/feature-families.json)；觀察 query 加上 [E0](../events/observation-catalog.json)。

## 3. 逐項功能索引

本表「已證」只覆蓋引用的有界契約，不宣告整個 native 本體、所有動態 Rebind 或全部 Client 功能完成。各列來源欄連到原能力報告；完整 source hashes 見 [source-manifest.json](source-manifest.json)。

### 入口、有限演出與生命期（7）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `lb.DoFile` · `0x4a1230` | 依路徑讀資源並交正式 Lua wrapper 執行。已存在合法 caller 與資源可見性；opening failure 和成功執行都可回 0，須查當次 exports/version，與大寫 global loader 契約不同。 | 有界能力已證；loader number（有歧義） | **跨功能待整合**：接既有合法 caller、相同 VM／phase 與當次 exports/version；確認資源選中 bytes 和跨 run 模組狀態。 | [R9](../../MEF-end-to-end-20261116/entry/report.md) |
| `Tutorial.StartCutScene` · `0x4a9730` | 從教學編排發起既有Q演出。使用合法scene雙鍵及對應context，受Q busy／資源前置限制。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：接具體 scene 雙鍵與 prepass/formal 內容，安排取得／停止／清理／返回及第二次使用。 | [R9](../../MEF-end-to-end-20261116/entry/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Tutorial.IsCutSceneRunning` · `0x4a97b0` | 查目前Q演出running狀態。numeric狀態；不代表教學scenario／任務已結算。 本輪觀察補充：active0不保證曾啟動、成功完成或所有呈現已回收 | 有界能力已證；觀察 number | **跨功能待整合**：接具體 scene 雙鍵與 prepass/formal 內容，安排取得／停止／清理／返回及第二次使用。 | [R9](../../MEF-end-to-end-20261116/entry/report.md)、[E1](../events/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Tutorial.StopCutScene` · `0x4a9820` | 由教學入口呼Q停止與對應清理。依native Stop guard與參數分支，與正常End不同。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：接具體 scene 雙鍵與 prepass/formal 內容，安排取得／停止／清理／返回及第二次使用。 | [R9](../../MEF-end-to-end-20261116/entry/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.StartCutScene` · `0x561760` | 啟動雙鍵對應的有限演出。SceneList→seq；busy與prepass/formal前置仍須成立。 | 有界能力已證；無新 binding 值 | **Server 待開發**：落實合法 scene 雙鍵、內容版本、啟動排他與 Server run 狀態。 | [R9](../../MEF-end-to-end-20261116/entry/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.EndCutScene` · `0x561db0` | 結束Q的正常控制流程及條件式回報。不是全部資源清理；應在選定清理完成後最後呼叫。 | 有界能力已證；無新 binding 值 | **Server 待開發**：區分正常／取消／重複回報和業務提交；各 owner 清理另行整合。 | [R9](../../MEF-end-to-end-20261116/entry/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.IsCutSceneRunning` · `0x489cf0` | 讀Q running狀態。number；正常回0也可能由取消／停止造成。 本輪觀察補充：不含成功／取消／skip／回收原因；本target本身不lazy-init | 有界能力已證；觀察 number | **跨功能待整合**：接具體 scene 雙鍵與 prepass/formal 內容，安排取得／停止／清理／返回及第二次使用。 | [R9](../../MEF-end-to-end-20261116/entry/report.md)、[E1](../events/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |

### Q 演出角色與領隊位置（16）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Q.CreateObject` · `0x562ec0` | 用內容指定slot建立CEventActor演出物件。九參數，Q私有索引與prepass依賴；slot不可重複當upsert。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.MoveObject` · `0x5632d0` | 立即改既有Q物件位置與方向。slot/x/y/direction，查Q tree；不同於普通world EntityId。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.DeleteObject` · `0x476430` | 此 build 正常 target 為空操作。RET 4，不能作單一物件刪除；批次清理另有DeleteAllObject。 | 已證 stub；無新 binding 值 | **跨功能待整合**：此 build target 已證空操作；需求要選別條已證能力或保留缺口，不以此名稱完成。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md) |
| `Q.GetLeaderPosN` · `0x564610` | 取得領隊位置指定分量。分量0/1/2，不提供actor ID或存活判定。 本輪觀察補充：無leader或selector不屬0/1/2都返回0；與合法座標0不能區分；不是actor handle／worldID | 有界能力已證；觀察 number | **跨功能待整合**：先確定領隊和 controller，限制 selector 0/1/2；不要把座標 0 當缺物件 ACK。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[E1](../events/report.md) |
| `Q.WalkObject` · `0x563330` | 讓Q物件朝目標執行走位。使用Q slot、合法動作與速度；完成可另查全Q停止狀態。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.WarpObject` · `0x5633b0` | 將Q物件依指定位置／動作條件快速換位。與Walk的移動狀態不同；不是Server換圖。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.AniObject` · `0x5634e0` | 選Q物件的模型動畫並設定播放倍率。需要模型對應action；動畫不是權威傷害計算。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.AniSkip` · `0x563530` | 調整Q物件動畫播放位置。signed整數step除render設定後加位置並clamp，無step非負gate；不是毫秒等待或跳整幕。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.RotateObject` · `0x563660` | 設定Q物件面向／旋轉。direction取low BYTE；第三整數0走立即yaw但仍受gate，非零沿common更新。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.SpeedObject` · `0x5636f0` | 調整Q物件的走位倍率。direct(slot,float)寫CEventActor+434；global helper另把speed-step轉倍率。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.FaceObject` · `0x563730` | 操作Q物件的臉部表情／Face.SKIN路徑。不是朝向目標；需有效臉部資源與render owner。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.StopObject` · `0x5637e0` | 停止指定Q物件的移動狀態。停止不等於死亡或自然到達目的地。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.ShowObject` · `0x564900` | 切換Q物件render gate。不刪索引、不釋放actor，也不停止其update。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.FlashObject` · `0x563790` | 設定Q物件的顏色／透明度閃爍。direct(slot,mode,ticks)由common update遞減；ticks不是固定毫秒。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.DeleteAllObject` · `0x563a70` | 清除整個Q物件索引與持有actor。批次所有Q物件，與world actors／Lua排程owner分開。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |
| `Q.IsAllObjectsStopped` · `0x564880` | 查整棵Q tree的移動pending bit。全Q集合，停止不必然是自然完成，亦無分組參數。 本輪觀察補充：空tree也回1；停止不等於動作結束、刪除、死亡或群組完成 | 有界能力已證；觀察 number | **跨功能待整合**：對同一 Q slot／actor 生命期整合本列操作、合法資源與最終批次清理；退出／重入另驗。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md)、[E1](../events/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md)、[U1](../reuse-followup/report.md) |

### 世界角色、外觀與繪製（8）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `lb.GetObjectCount` · `0x4a0a30` | 有登記入口，但本體是一次性 manager 初始化路徑。不提供可信的物件數／存活數查詢。 | 已證非 count；無新 binding 值 | **Client 待逆向**：若需求是普通存活／群清觀察，還需真正 typed writer→observer；此名稱已證沒有 count。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md) |
| `lb.CreateObject` · `0x4a0b40` | 以簡化參數本地建立世界 actor。固定 scale=12、direction=0；model/x/y/attach，不回傳新 EntityId。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：選定合法模型、來源座標與 world owner；如需聯機實體，另接 Server 身分／回收。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md) |
| `lb.CreateObjectEx` · `0x4a0f70` | 指定模型、位置、縮放、面向建立世界 actor。model,x,y,scale,direction,attach；模型分支與資源須有效，本機配號。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：選定合法模型、來源座標與 world owner；如需聯機實體，另接 Server 身分／回收。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md) |
| `lb.SetActorAvatar` · `0x4a0b80` | 更改指定世界 actor 的外觀部件／變體。world key、part、variant；消費者是 CDoll 外觀樹，需既有 render owner。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對正確 world key／CDoll 準備合法 part/variant/descriptor；資產變更另走 Server。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md) |
| `lb.AttachActorItem` · `0x4a0c50` | 把指定附件加入世界 actor 的外觀。以資源 item/actor key 查附件部件；不能當新增背包道具。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對正確 world key／CDoll 準備合法 part/variant/descriptor；資產變更另走 Server。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md) |
| `lb.DetachActorItem` · `0x4a0d10` | 移除世界 actor 指定外觀部件及配對部件。刪 part 與 part+0x10；不是把 Attach 的 item key 直接反向傳回。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對正確 world key／CDoll 準備合法 part/variant/descriptor；資產變更另走 Server。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[R5](../../MEF-content-contracts-20261116/actors/report.md) |
| `Q.DisableObjRender` · `0x5647a0` | 暫停指定世界物件render路徑。只影響render gate，不停止全部世界simulation。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：記錄共享 render flag 的持有者，退出時只恢復自己的改動，與 simulation 分開。 | [R9](../../MEF-end-to-end-20261116/entry/report.md)、[R6](../../MEF-control-flow-20261116/presentation/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.EnableObjRender` · `0x564810` | 恢復指定世界物件render路徑。與Q物件自己的ShowObject不同owner。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：記錄共享 render flag 的持有者，退出時只恢復自己的改動，與 simulation 分開。 | [R9](../../MEF-end-to-end-20261116/entry/report.md)、[R6](../../MEF-control-flow-20261116/presentation/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |

### 鏡頭工作、跟隨與快照（19）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Tutorial.StopCameraWorks` · `0x4a9570` | 停止目前 CameraWorks。共享current pointer；不等於pop相機快照。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：取得正確 current work 並配置資源；區分載入、停止／自然終點與 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Tutorial.PushCamera` · `0x4a95f0` | 以標籤保存相機快照。label對應同一相機owner，取得／釋放需成對。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：保存／恢復依同一 owner 與 label 配對；與其他相機 writer 排序，不盲目重試 Pop。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Tutorial.PopCamera` · `0x4a96a0` | 按標籤還原並移除相機快照。先還原與移除再比標籤；不匹配可能繼續消耗stack。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：保存／恢復依同一 owner 與 label 配對；與其他相機 writer 排序，不盲目重試 Pop。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Tutorial.ApplyDefaultCamera` · `0x4a9720` | 將既有預設相機值套用到相機。是預設值路徑，不是PopCamera的同義操作。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：保存／恢復依同一 owner 與 label 配對；與其他相機 writer 排序，不盲目重試 Pop。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `CameraWorks.Load` · `0x54e970` | 從路徑載入相機keyframe工作。正確XML／frame資料，沿既有相機owner。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：取得正確 current work 並配置資源；區分載入、停止／自然終點與 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `CameraWorks.LoadRel` · `0x54e990` | 載入並對keyframe位置加相對偏移。path與XYZ offset，與Q.PlayCameraWorks的relative flag不同ABI。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：取得正確 current work 並配置資源；區分載入、停止／自然終點與 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `CameraWorks.Play` · `0x54e9e0` | 開始目前相機工作。有真實KeyFrame tick→插值→camera apply，需合格Client更新。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：取得正確 current work 並配置資源；區分載入、停止／自然終點與 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `CameraWorks.Stop` · `0x54e9f0` | 停止目前相機工作。不替代相機快照還原或其他效果清理。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：取得正確 current work 並配置資源；區分載入、停止／自然終點與 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `CameraWorks.IsEnded` · `0x54ea00` | 查目前相機工作的完成predicate。null回1，實際型別走v+20；需區分未建立與自然播完。 本輪觀察補充：current null直接回1；Stop與自然到尾可同值；不是載入成功或snapshot已還原 | 有界能力已證；觀察 number | **跨功能待整合**：取得正確 current work 並配置資源；區分載入、停止／自然終點與 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[E1](../events/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.PlayCameraWorks` · `0x562b80` | 載入並開始指定camera work。字串與整數relative flag；合法XML、非空路徑與current owner前置。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：取得正確 current work 並配置資源；區分載入、停止／自然終點與 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.SkipCamera` · `0x562cf0` | 在目前鏡頭工作進度加上trunc(float(k)/R)。相對增量；KeyFrame只夾尾端上界，不是絕對frame、毫秒或任意腳本skip。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：取得正確 current work 並配置資源；區分載入、停止／自然終點與 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.CameraEffect` · `0x5650c0` | 向相機加入指定震動／位移效果。三int native ABI；helper有額外wait flag且等待是估算。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：依三整數契約限制非零 divisor 與合法 effect 參數；helper 估算等待不當完成 ACK。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.SetCameraPoint` · `0x562e10` | 立即設定相機XYZ位置。三float，與Q.MoveCamera同target，沒有插值時間。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：使用同一座標系的三個 float，與仍會覆寫相機的 current work 排序。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.BeginCameraOverride` · `0x562a60` | 保存Q演出開始前的相機快照。固定QSceneCam label；需平衡取得／釋放。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：保存／恢復依同一 owner 與 label 配對；與其他相機 writer 排序，不盲目重試 Pop。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.EndCameraOverride` · `0x562b00` | 還原Q標籤相機快照。pop先移除再比名，非可盲目重試的reset。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：保存／恢復依同一 owner 與 label 配對；與其他相機 writer 排序，不盲目重試 Pop。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.AttachCamera` · `0x563830` | 使相機工作跟隨指定Q物件節點。Q slot與CAMERA_DUMMY01；不是任意world EntityId。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：驗 Q slot 與 model node，對正確 current 停止／解除，再按已取得 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.DetachCamera` · `0x563900` | 解除目前附著相機工作。清current pointer，不pop override，不等於銷毀所有工作。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：驗 Q slot 與 model node，對正確 current 停止／解除，再按已取得 snapshot 還原。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.MoveCamera` · `0x562e10` | 立即設定相機XYZ位置。與SetCameraPoint同target，名稱不代表路徑移動。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：使用同一座標系的三個 float；這是立即設定，與 current work 的後續寫入排序。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.RotCamera` · `0x563970` | 設定兩個相機角與局部鏡頭距離。三float中第三個為distance，不是第三旋轉軸。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：按兩個角度及 distance 的實際三 float 契約配置；與快照／current work 排序。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |

### 音樂、音效與語音（7）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Tutorial.PlayMusic` · `0x4a9330` | 在既有音樂播放器中請求音軌。與Q共享音樂owner，需合法資源；非同步且同名可略過重播。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：配置合法音軌與共享 pool 使用權；分開同名重播、fade 至 0、Stop/release 與恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.PlayMusic` · `0x5643c0` | 請求播放指定背景音樂。與Tutorial共享CMusicPlayer，非同步，同名可不重啟。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：配置合法音軌與共享 pool 使用權；分開同名重播、fade 至 0、Stop/release 與恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.StopMusic` · `0x564500` | 停止並釋放共用音樂pool的stream。操作整個16-slot pool並清pending／fade資料，不只單一當前音軌。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：配置合法音軌與共享 pool 使用權；分開同名重播、fade 至 0、Stop/release 與恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.StopMusicWithFadeOut` · `0x564580` | 逐次降低音樂音量因子。fade完成至0不等於停止／釋放stream。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：配置合法音軌與共享 pool 使用權；分開同名重播、fade 至 0、Stop/release 與恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.PlaySound` · `0x564cc0` | 請求播放指定一般音效。合法音效資源與音訊context；helper不等待播完。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：確認合法 sound 資源與 Voice group；按既有自然生命期處理，無單次 Lua 完成 handle。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.PlayTalkSound` · `0x564d90` | 沿音效播放鏈請求聲音並指定Voice資源group。修改快取SoundFile的group；helper只yield，沒有本次完成handle，不是Book／Prolog共用voice handle的寫入器。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：確認合法 sound 資源與 Voice group；按既有自然生命期處理，無單次 Lua 完成 handle。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.SetFinalMusic` · `0x565560` | 修改演出保存的後續音樂字串。null不變、首字元空白清除、其他追加；RestoreMap消費，不是立即播放。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：配置合法音軌與共享 pool 使用權；分開同名重播、fade 至 0、Stop/release 與恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |

### 圖片、縮放與飛行圖片（5）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Tutorial.RegisterSkipMessage` · `0x4a9b70` | 建立持續顯示的跳過提示圖片。接texture path；不是登記Lua callable。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對 Tutorial tracking 集合配置資源及取消／回收；不與 Q 最近 handle 混用。 | [R8](../../MEF-control-flow-20261116/world/report.md) |
| `Tutorial.RegisterScalingObject` · `0x4a9c80` | 建立指定尺寸的縮放圖片。path/width/height；由圖片owner更新／繪製。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對 Tutorial tracking 集合配置資源及取消／回收；不與 Q 最近 handle 混用。 | [R8](../../MEF-control-flow-20261116/world/report.md) |
| `Tutorial.DestroyFlyingObjects` · `0x4a9db0` | 取消Tutorial所追蹤的圖片。標記與清tracking，實體回收可能在後續合格tick。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對 Tutorial tracking 集合配置資源及取消／回收；不與 Q 最近 handle 混用。 | [R8](../../MEF-control-flow-20261116/world/report.md) |
| `Q.FlyingObject` · `0x564940` | 顯示具有淡入／保持／淡出狀態的圖片。path 加六個整數；配置新圖之前會先取消 M+40 追蹤的前圖，再建新圖。hold=-1 也會被後次新建取消；取消不等於同步釋放，無 Lua 完成 token。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：新建前先取消上一張 Q 追蹤圖；按單 handle 替換／取消及 manager 回收整合，不能用連續新建保持兩圖。 | [R8](../../MEF-control-flow-20261116/world/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md) |
| `Q.DelFlyingObject` · `0x564a60` | 取消Q保存handle對應圖片。取消 M+40 單一追蹤圖並清 handle；新建入口本身也會先做此取消。實體回收延後，不是掃描共享其他 owner 圖或同步 destructor。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：新建前先取消上一張 Q 追蹤圖；按單 handle 替換／取消及 manager 回收整合，不能用連續新建保持兩圖。 | [R8](../../MEF-control-flow-20261116/world/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md)、[U0](../reuse/report.md) |

### 對白、字幕、序章與書本（13）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Prolog.OnClose` · `0x55f950` | 明確關閉Prolog流程並發相應UI事件。是native已註冊入口；helper同名callback是否自動觸發需另看caller。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：選實際原表／語音與 UI 資源，按各 owner 區分自然完成、關閉／取消及後續動作。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `Q.InsertText` · `0x5628c0` | 加入演出文字字幕queue。採設定codepage轉寬字；最多255 UTF-16 units加NUL，native無長度guard；不是多列頭像對白。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：按設定 codepage 與 255 UTF-16 units 容量檢查字幕，接正確 queue／UI 生命期。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `Q.Prolog` · `0x564ba0` | 啟動既有Prolog文字／書頁呈現。按原表key和對應資源，狀態可由IsPrologRunning觀察。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：選實際原表／語音與 UI 資源，按各 owner 區分自然完成、關閉／取消及後續動作。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `Q.IsPrologRunning` · `0x564c50` | 查Prolog文字流程是否running。0也可能是關閉／失敗／取消，需結合流程原因。 本輪觀察補充：0不證成功播放；與ScenarioTalk、Q.Dialogue及world事件分開 | 有界能力已證；觀察 number | **跨功能待整合**：選實際原表／語音與 UI 資源，按各 owner 區分自然完成、關閉／取消及後續動作。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md)、[E1](../events/report.md) |
| `Q.Book` · `0x565140` | 啟動原版固定書本序列。一整數ABI但native忽略參數；Table/Book.txt固定向量與voice gate，WaitForBook讀狀態。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：採原版固定書本序列與 voice gate；分開自然終點及 Stop，驗第二次使用。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `Q.Dialogue` · `0x5651f0` | 播放Prolog表指定的文字／語音演出。不是world actor聊天框；原helper只yield，本輪無專用完成query。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：選實際原表／語音與 UI 資源，按各 owner 區分自然完成、關閉／取消及後續動作。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `Q.IsBookFlying` · `0x565270` | 查書本演出active狀態。0可由正常最後階段或Stop清除，不能單憑值區分原因。 本輪觀察補充：0不證曾啟動／成功；與圖片manager一般handle不同 | 有界能力已證；觀察 number | **跨功能待整合**：採原版固定書本序列與 voice gate；分開自然終點及 Stop，驗第二次使用。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md)、[E1](../events/report.md) |
| `Q.BalloonTalk` · `0x550450` | 此 build 正常 target 為空操作。RET 8，兩個數值被忽略；沒有氣泡文字consumer。 | 已證 stub；無新 binding 值 | **跨功能待整合**：此 build target 已證空操作；需求要選別條已證能力或保留缺口，不以此名稱完成。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `ScenarioTalkTable.open` · `0x6bd620` | 按id/scene選原表多列對白並發起。兩int＋Lua truthiness boolean手動模式；actor是頭像資料key，talk是文字key。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：接已存在的合法 caller、雙鍵原表、manual boolean 與頁面；安排語音、callback 尾段和 UI 還原。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `ScenarioTalkTable.start` · `0x6bd6b0` | 開始已選定的對白資料。依原生選定資料／視窗context，不是任意新對話資料生成器。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：接已存在的合法 caller、雙鍵原表、manual boolean 與頁面；安排語音、callback 尾段和 UI 還原。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `ScenarioTalkTable.hideOtherUI` · `0x6bd7f0` | 隱藏對話以外的適用UI。保留固定豁免key集合，記錄原顯示子視窗。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：接已存在的合法 caller、雙鍵原表、manual boolean 與頁面；安排語音、callback 尾段和 UI 還原。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `ScenarioTalkTable.showOtherUI` · `0x6bd9b0` | 恢復同一頁面記錄的其他UI。與hideOtherUI配對，同owner生命週期。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：接已存在的合法 caller、雙鍵原表、manual boolean 與頁面；安排語音、callback 尾段和 UI 還原。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `ScenarioTalkTable.hide` · `0x6bd720` | 停止對話語音並結束／隱藏對白。呼OnEndTalk、隱藏視窗、清已選定資料；不是任務結算。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：接已存在的合法 caller、雙鍵原表、manual boolean 與頁面；安排語音、callback 尾段和 UI 還原。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |

### 教學角色、進度、UI 與 scenario（17）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Tutorial.IsSynopsisSkipped` · `0x4a9320` | 讀取特定簡介流程的跳過紀錄。number，讀FBA7A0；不是所有內容的通用取消旗標。 本輪觀察補充：只在兩個entry清0；Stop在active檢查之前即可按選定keys設1，不是最近任意演出結果 | 有界能力已證；觀察 number | **跨功能待整合**：結合指定流程 key、entry reset 與本輪 run；skip store 早於 active gate，不能作通用取消 ACK。 | [R2](../../MEF-capabilities-20261116/control/report.md)、[E1](../events/report.md) |
| `Tutorial.PostUIMessage_EmployChar` · `0x4a98d0` | 送固定雇用詢問UI事件。F431F加一個整數，由適用頁面的consumer處理。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對固定頁面／事件／旗標接正確 owner 與 producer；分開操作記錄和實際顯示。 | [R8](../../MEF-control-flow-20261116/world/report.md) |
| `Tutorial.PostUIMessage_TutoMsg` · `0x4a9950` | 送固定教學提示UI事件。F43FD加兩個整數，不能任意指定event或callback。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對固定頁面／事件／旗標接正確 owner 與 producer；分開操作記錄和實際顯示。 | [R8](../../MEF-control-flow-20261116/world/report.md) |
| `Tutorial.HideUI` · `0x4a99d0` | 隱藏適用當前頁面原先可見的子視窗。空豁免集合，先記錄key再virtual visibility(0)，需typed page。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對固定頁面／事件／旗標接正確 owner 與 producer；分開操作記錄和實際顯示。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `Tutorial.SetUIPage` · `0x4a9ae0` | 選擇固定教學頁面；同頁時送F4355刷新事件。固定page15，沒有任意page參數，不表示同步完成整頁重建。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對固定頁面／事件／旗標接正確 owner 與 producer；分開操作記錄和實際顯示。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `Tutorial.IsCharacterAvailable` · `0x4a9f00` | 查固定角色roster條目的可用欄位。固定 roster index 2（零起算，第 3 筆）可用性；native 不讀形式引數，不能指定任意 EntityId。 | 有界能力已證；觀察 number | **跨功能待整合**：依固定角色／領隊或原教學 key 編碼使用，確認相同 controller 與相應資源。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[E1](../events/report.md) |
| `Tutorial.SetControlStatus` · `0x4a9f90` | 寫入教學controller的控制旗標。已知0..31 layout及正確controller，native無bounds check。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：在已證 Tutorial controller／合法欄位使用，明確 expected number、writer 與 reset owner。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `Tutorial.GetControlStatus` · `0x4a9fb0` | 讀回教學controller控制旗標。與Set同owner/index，number；不是一般世界事件查詢。 本輪觀察補充：沒有bounds/type guard；旗標可被script寫入並殘留，非可消耗事件queue | 有界能力已證；觀察 number | **跨功能待整合**：在已證 Tutorial controller／合法欄位使用，明確 expected number、writer 與 reset owner。 | [R2](../../MEF-capabilities-20261116/control/report.md)、[E1](../events/report.md) |
| `Tutorial.GetTutorialState` · `0x4a9fd0` | 查教學UI推進的狀態欄位。CTutoMsgDummy等特定writer，不是任意關卡完成狀態。 本輪觀察補充：無receiver/type guard；不是worldFSM、任務或群清state | 有界能力已證；觀察 number | **跨功能待整合**：在已證 Tutorial controller／合法欄位使用，明確 expected number、writer 與 reset owner。 | [R2](../../MEF-capabilities-20261116/control/report.md)、[E1](../events/report.md) |
| `Tutorial.InsertObject` · `0x476430` | 此 build 正常 target 為空操作。RET 4；固定教學角色可走已證InsertIsilia，不把本名稱當建立器。 | 已證 stub；無新 binding 值 | **跨功能待整合**：此 build target 已證空操作；需求要選別條已證能力或保留缺口，不以此名稱完成。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md) |
| `Tutorial.DeleteObject` · `0x4a9fe0` | 按教學角色鍵移除對應物件。用低BYTE轉教學world key；不同於Q.DeleteObject stub。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：依固定角色／領隊或原教學 key 編碼使用，確認相同 controller 與相應資源。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md) |
| `Tutorial.InsertIsilia` · `0x4aa070` | 建立原版教學固定Isilia物件。固定world key F000、model4；不可改說任意NPC建立器。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：依固定角色／領隊或原教學 key 編碼使用，確認相同 controller 與相應資源。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md) |
| `Tutorial.IsIsiliaFound` · `0x4aa240` | 判斷原版固定Isilia的教學條件。固定對象／視認鏈，不是任意actor存亡。 本輪觀察補充：0混合找不到、null actor、視錐／距離／螢幕邊界失敗；不檢查一般死亡原因 | 有界能力已證；觀察 number | **跨功能待整合**：依固定角色／領隊或原教學 key 編碼使用，確認相同 controller 與相應資源。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[E1](../events/report.md) |
| `Tutorial.CheckLeader` · `0x4aa4a0` | 檢查當前領隊的模型條件。取得領隊並比model低WORD是否3；不是EntityId==3。 本輪觀察補充：null回0；不回EntityId，不能指定任意model或監聽領隊lifetime | 有界能力已證；觀察 number | **跨功能待整合**：依固定角色／領隊或原教學 key 編碼使用，確認相同 controller 與相應資源。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md)、[E1](../events/report.md) |
| `Tutorial.IsLeaderDialogOpened` · `0x54e740` | 查教學領隊對話UI的記錄分支。讀owner+38；show可能被gate擋住，1非嚴格可見性保證。 本輪觀察補充：既有writer可在show helper被gate擋下時仍設1；非當幀可見性保證 | 有界能力已證；觀察 number | **跨功能待整合**：對固定頁面／事件／旗標接正確 owner 與 producer；分開操作記錄和實際顯示。 | [R2](../../MEF-capabilities-20261116/control/report.md)、[E1](../events/report.md) |
| `Tutorial.RequestStartScenario` · `0x4aa4d0` | 送出教學scenario開始意圖。C2S0040加low-WORD key，需連線／合法情境；Server接續流程。 | 有界能力已證；無新 binding 值 | **Server 待開發**：處理既有開始意圖、合法 key、權威流程與結果。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `Tutorial.IsScenarioEnded` · `0x4aa510` | 等待對應教學scenario的結束旗標。同Tutorial owner map，S2C004C寫入；正確context下可接續腳本。 本輪觀察補充：missing key可插入0；值1可殘留；ordinary Mission/Scenario不接受004C writer | 有界能力已證；觀察 number | **Server 待開發**：由正確 Tutorial 生命期的 Server 結果寫同 key；不移植為普通事件。 | [R2](../../MEF-capabilities-20261116/control/report.md)、[E1](../events/report.md) |

### 互動點與教學提示點（2）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Tutorial.InsertTutorialCheckPoint` · `0x4a9430` | 按教學資料列建立提示點。固定category4；位置與半徑取自原表。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：選原表提示點及正確 Tutorial controller，分開 enabled、point latch 與 progress 的重置。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `Tutorial.SetCheckPointStatus` · `0x4a9460` | 切換既有互動點enabled；出口等類型另有視覺分支。key/category/status，與S2C0048同setter；category2/3不保證招牌外觀改變。 | 有界能力已證；無新 binding 值 | **Server 待開發**：實作合法 point 快照、開放條件與更新排序，再整合既有 setter。 | [R2](../../MEF-capabilities-20261116/control/report.md) |

### 地圖、備份與小地圖（4）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `lb.ChangeMap` · `0x4a0ac0` | 要求本機地圖載入器換圖。需合法 map key；兩端地圖、實體、互動點與進度另外同步。 | 有界能力已證；無新 binding 值 | **Server 待開發**：完整換圖仍須 Server 轉場、角色／points、ready 與持久化協同。 | [R4](../../MEF-capabilities-20261116/world-npc/report.md) |
| `lb.LoadMinimap` · `0x4a1400` | 按 map key 重載小地圖描述與圖示資源。既有 minimap owner、BOUND→.mmt、texture與symbols須有效。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：選定 map→BOUND→mmt/texture/symbols 的完整依賴，確認已安裝的 UI owner。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `Q.LoadMap` · `0x563c40` | 為演出載入地圖並備份既有map/camera。只有一份backup，不是巢狀map stack。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：在同一生命期管理單份 map/camera backup 的取得和消費；真實轉場另接 Server。 | [R9](../../MEF-end-to-end-20261116/entry/report.md) |
| `Q.RestoreMap` · `0x563fa0` | 還原演出保存的地圖／相機並消費相關音樂設定。重寫backup欄位；資源與當前context須有效。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：在同一生命期管理單份 map/camera backup 的取得和消費；真實轉場另接 Server。 | [R9](../../MEF-end-to-end-20261116/entry/report.md) |

### 鍵位與輸入控制（4）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `lb.ChangeKeymapType` · `0x4a1440` | 切換原生支援的鍵位配置。已證0/1兩分支；不等於解除所有輸入 owner。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：區分鍵位配置、各 mask、controller busy 與 UI capture，按實際持有者恢復。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `Tutorial.SetKeymapEnabled` · `0x4a94c0` | 設定教學輸入mask。數字0/1；非零清mask0x2，Lua true不等於整數1。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：區分鍵位配置、各 mask、controller busy 與 UI capture，按實際持有者恢復。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `Q.EnableInput` · `0x562980` | 清除Q指定輸入mask。不單獨釋放controller忙碌owner。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：區分鍵位配置、各 mask、controller busy 與 UI capture，按實際持有者恢復。 | [R9](../../MEF-end-to-end-20261116/entry/report.md) |
| `Q.DisableInput` · `0x5629f0` | 設定Q指定輸入mask。需在結束時配對恢復。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：區分鍵位配置、各 mask、controller busy 與 UI capture，按實際持有者恢復。 | [R9](../../MEF-end-to-end-20261116/entry/report.md) |

### 淡幕、轉場、色調、黑邊與慢動作（12）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Fade.Start` · `0x55e740` | 啟動原版全畫面淡幕。與Q.FadeIn／Out／Color共用FE2744；接方向與更新計數，不是毫秒。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對共享 overlay 配對操作，分開 alpha、active、draw 與清理；不以 EndQ 代替恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Fade.End` · `0x55e770` | 停止淡幕更新並可清alpha。End(0)保留當前alpha，非零才清覆蓋；draw不以active作唯一gate。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對共享 overlay 配對操作，分開 alpha、active、draw 與清理；不以 EndQ 代替恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.Transition` · `0x5646a0` | 擷取畫面並作多層放大淡出轉場。兩整數layers/rate；helper固定(2,120)，native預設(8,120)，須enabled；未有界夾任意layers。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：選已證有界 layers/rate 與有效 graphics context，驗 capture、freeze、自然終點和退出。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.ShowLetterbox` · `0x564b00` | 顯示演出上下黑邊。固定native draw owner，與Fade alpha不同。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對獨立黑邊 flag 配對顯示／隱藏；結束演出不能代替呈現清理。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.HideLetterbox` · `0x564b50` | 隱藏演出上下黑邊。清對應flag，需既有renderer context。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對獨立黑邊 flag 配對顯示／隱藏；結束演出不能代替呈現清理。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.FadeOut` · `0x564f30` | 啟動畫面淡出至不透明覆蓋。count為合格native更新次數的分母，不是毫秒；到255仍active，helper只yield一次。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對共享 overlay 配對操作，分開 alpha、active、draw 與清理；不以 EndQ 代替恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.FadeIn` · `0x564fb0` | 啟動畫面淡入至透明。與Q.FadeOut／Fade.Start共用遮罩；count不是毫秒，alpha到0才清active。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對共享 overlay 配對操作，分開 alpha、active、draw 與清理；不以 EndQ 代替恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.FadeColor` · `0x565040` | 設定畫面淡幕色彩。數值色彩由native consumer處理，非文字或材質資源替換。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：對共享 overlay 配對操作，分開 alpha、active、draw 與清理；不以 EndQ 代替恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.StartSepia` · `0x5655c0` | 啟動褐色／色調演出狀態。需要後續native更新及renderer context。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：在同一色調 owner 管理 phase 推進及退出；結束請求須待原生更新消費。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.EndSepia` · `0x565600` | 要求結束褐色色調效果。先置phase4，後續合格更新4→5→6→0，非立即全復原。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：在同一色調 owner 管理 phase 推進及退出；結束請求須待原生更新消費。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md) |
| `Q.StartSlowMotion` · `0x565640` | 啟用指定actor動畫delta縮放。選定路徑約0.2倍，不改Server時鐘或所有子系統。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：分開 Q flag 與其他 countdown writer，驗實際動畫 delta 及退出恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |
| `Q.EndSlowMotion` · `0x5656b0` | 清Q slow-motion旗標。其他countdown可能仍使該動畫路徑慢速。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：分開 Q flag 與其他 countdown writer，驗實際動畫 delta 及退出恢復。 | [R1](../../MEF-capabilities-20261116/audiovisual/report.md)、[L2](../../MEF-feature-lifecycle-20261117/REPORT.md) |

### 數字、戰鬥與擊殺字樣（3）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `Q.NumberPanel` · `0x5652e0` | 在Q物件位置顯示數字型面板。direct style限0..5、value0無面板；排除INT32_MIN，helper另分流；不改HP。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：按本列 style/value 邊界與適用 Q actor/UI context 配置；顯示與 Server 命中／資產分開。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `Q.BattlePanel` · `0x5653c0` | 在Q物件位置顯示Miss／Block提示面板。direct style限0..3且須先驗範圍；不執行權威命中、傷害或資產更新。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：按本列 style/value 邊界與適用 Q actor/UI context 配置；顯示與 Server 命中／資產分開。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |
| `Q.BurstStruck` · `0x565490` | 顯示擊殺數與爆擊字樣的螢幕效果。arg1非零啟動Kills及arg3數字，arg2啟動Critical；不選Q物件，不扣HP。 | 有界能力已證；無新 binding 值 | **跨功能待整合**：按本列 style/value 邊界與適用 Q actor/UI context 配置；顯示與 Server 命中／資產分開。 | [R3](../../MEF-capabilities-20261116/dialogue-ui/report.md) |

### 診斷與本機時計（3）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `lb.SetDebugLevel` · `0x4a0aa0` | 設定 Client 診斷等級。本體只寫診斷欄位並把上端限制為9；不是玩法狀態。 | 有界能力已證；無新 binding 值 | **待遊玩驗證**：以已證診斷欄位用途驗收；不是新增玩法或任務狀態。 | [R2](../../MEF-capabilities-20261116/control/report.md) |
| `lb.GetTime` · `0x4a0b70` | 取得本地計時值。WINMM.timeGetTime 的32-bit原值以signed FILD轉Lua number；不是Server時鐘。 本輪觀察補充：不是時間事件、frame callback或Server時鐘；signed number轉換另見ABI審計 | 有界能力已證；觀察 number | **待遊玩驗證**：驗收 signed 32-bit 時計差值／跨界處理；不接成自動 timer 或 Server clock。 | [R2](../../MEF-capabilities-20261116/control/report.md)、[E1](../events/report.md) |
| `lb.PrintCurrSceneID` · `0x5f5d10` | 此 build 正常 target 為空操作。RET，不提供 scene ID。 | 已證 stub；無新 binding 值 | **跨功能待整合**：此 build target 已證空操作；需求要選別條已證能力或保留缺口，不以此名稱完成。 | [R2](../../MEF-capabilities-20261116/control/report.md) |

### 顯示設定（1）

| 正常 API／native | 已證用途與條件 | native／回值分類 | 主要未完成層與工作 | 原報告 |
|---|---|---|---|---|
| `lb.ChangeResolution` · `0x4a1330` | 呼現有顯示參數與 rendering 重設路徑。三個數值參數；本次不虛構合法尺寸與模式enum。 | 有界能力已證；無新 binding 值 | **Client 待逆向**：既有 rendering reset 已證；採用新尺寸／模式前須釐清第三值 enum 及合法值。 | [R2](../../MEF-capabilities-20261116/control/report.md) |

## 4. 121 名稱以外的完整 MEF 方向

### qbase helper、排程與載入階段

既有原件另有 75 個 qbase root helper exports。它們含參數加工、Register／coroutine、明確等待、只 yield 一次的包裝及空函式，與正常 native binding 不能相加成 196 種獨立功能，也不能把 helper 簽章套到同名 native。完整結構可直接沿 [H0](../../MEF-capabilities-20261116/helper-catalog.md)，本包沒有重發原腳本。預掃描 stubs／collectors、標準函式庫、Rebind 與額外 globals 另屬階段／管理／語言設施，範圍見 [S0](../../MEF-full-surface-native-continuation-20261116/REPORT.md)。

### 世界 NPC、商店、強化與權威戰鬥

已有原生互動點→NPC／Shop／表格→選單→買賣／強化 UI→請求／結果鏈；不在這 121 名稱中另編造 OpenShop、SpawnMonster 或 OnDeath。Server 可開發合法商品、價格、材料、背包／裝備、原子提交與保存；生成／死亡／群清則保存權威 entity、generation、group 與原因。若內容要由普通 world 結果直接喚起 Lua，仍須找到有型別的合法出口，不能用 Q slot、空樹停步或 Tutorial latch 代用。來源：[R4](../../MEF-capabilities-20261116/world-npc/report.md)、[S0](../../MEF-full-surface-native-continuation-20261116/REPORT.md)、[E1](../events/report.md)。

### 三條精確的 Client 研究線

1. 官方 MEF：取得可追的 filename/bytes producer→reader→parser／grammar；改副檔名與字串命中不成立。
2. 普通事件：由同一 world identity／lifetime 的 native 結果追到實際 registered wrapper 或合法 callback；現有 16 query 已定型，不重掃已排除名稱。
3. B 首次入口：找普通 field/page 的真正 producer→typed receiver→首次載入／Lua caller；已知對話 callback 只證續行，不能循環假設第一次已發生。

這三條應持續推進，但不是每個鏡頭、聲音、圖片或有限演出實作的前置阻塞。合法 caller 已成立時，已有能力可以按其限制組合。來源：[S0](../../MEF-full-surface-native-continuation-20261116/REPORT.md)、[E1](../events/report.md)。

## 5. 建議的全功能實作順序

| 工作線 | 具體產出 | 判定完成的證據 |
|---|---|---|
| 內容聯合預驗 | 把 ABI、typed keys、資源選中 bytes、owner／清理與同 run 觀察合成一份逐呼叫計畫 | 121 名稱精確匹配；禁止 stub／假成功；每個等待有真實 producer 及 timeout/cancel 策略 |
| 呈現組合 | 選定實際角色／鏡頭／音訊／對白／圖片／遮罩內容，連同退出與第二次使用 | 合法入口、相同 prepass/formal 依賴、取得／清理配對；按各 native 終點驗收，不只驗一個開門點 |
| 地圖與世界服務 | 合法轉場、世界身分、互動點快照、NPC 買賣／強化與資產持久化 | Server 權威結果與 Client 呈現一致；異常、重複與遲到回覆受控 |
| 普通事件整合 | Server 波次／死亡／群組狀態，接已有有限內容入口；並行補 Client typed observer | 真正 identity／lifetime／cause 證據及可達 Lua 出口，未證出口保留缺邊 |
| 遊玩驗收 | 正常完成、取消、中斷、換圖、連續兩次、資源失敗與恢復 | 實際 Client 證據、畫面／聲音／操作恢復與 Server 保存一致；不以靜態 PASS 代替 |

## 6. 可重核的集合結果

本次實際集合核對 PASS：ABI、既有 capability 與 lifecycle 三份集合一致；121 個唯一名稱，各有且只有一個主要功能域；native targets 逐項相等；16 個觀察 query 與事件表一致；Markdown 121 列無重複或遺漏。統計：4 stub、1 非 count、116 個有界能力名稱，17 個新 number／104 個無新 binding 值。這不是全程式覆蓋率，也沒有完成百分比。

## 7. 來源導航

同輪檔案以 SHA-256 固定本次版本；既有報告全部固定於前述 Git 基線。若同輪 ABI 改稿，重新核對集合和 source hashes。

| ID | 來源 | 用途 |
|---|---|---|
| A0 | [本輪完整正常 binding ABI](../abi/abi-contracts.json) | 本輪檔案快照 |
| E0 | [本輪 16 個觀察查詢來源](../events/observation-catalog.json) | 本輪檔案快照 |
| E1 | [本輪事件、typed query 與 B 的有界結果](../events/report.md) | 本輪檔案快照 |
| U0 | [本輪圖片替換勘誤與兩段內容重用](../reuse/report.md) | 本輪檔案快照 |
| U1 | [本輪 CDoll 同資源引用、回載與失敗界線](../reuse-followup/report.md) | 本輪檔案快照 |
| C0 | [121 名稱的既有能力與條件](../../MEF-capabilities-20261116/capability-index.json) | 固定 Git blob |
| L0 | [36 個功能族的 owner／完成／清理契約](../../MEF-feature-lifecycle-20261117/feature-families.json) | 固定 Git blob |
| L1 | [既有全部功能族導覽及各層界線](../../MEF-feature-lifecycle-20261117/CAPABILITIES.md) | 固定 Git blob |
| L2 | [原生持續效果與回收生命期增量](../../MEF-feature-lifecycle-20261117/REPORT.md) | 固定 Git blob |
| S0 | [正常註冊面範圍及 End 後 native 效果](../../MEF-full-surface-native-continuation-20261116/REPORT.md) | 固定 Git blob |
| H0 | [75 個 qbase root helper 索引](../../MEF-capabilities-20261116/helper-catalog.md) | 固定 Git blob |
| R1 | [MEF-capabilities-20261116/audiovisual/report.md](../../MEF-capabilities-20261116/audiovisual/report.md) | 固定 Git blob |
| R2 | [MEF-capabilities-20261116/control/report.md](../../MEF-capabilities-20261116/control/report.md) | 固定 Git blob |
| R3 | [MEF-capabilities-20261116/dialogue-ui/report.md](../../MEF-capabilities-20261116/dialogue-ui/report.md) | 固定 Git blob |
| R4 | [MEF-capabilities-20261116/world-npc/report.md](../../MEF-capabilities-20261116/world-npc/report.md) | 固定 Git blob |
| R5 | [MEF-content-contracts-20261116/actors/report.md](../../MEF-content-contracts-20261116/actors/report.md) | 固定 Git blob |
| R6 | [MEF-control-flow-20261116/presentation/report.md](../../MEF-control-flow-20261116/presentation/report.md) | 固定 Git blob |
| R7 | [MEF-control-flow-20261116/runner/report.md](../../MEF-control-flow-20261116/runner/report.md) | 固定 Git blob |
| R8 | [MEF-control-flow-20261116/world/report.md](../../MEF-control-flow-20261116/world/report.md) | 固定 Git blob |
| R9 | [MEF-end-to-end-20261116/entry/report.md](../../MEF-end-to-end-20261116/entry/report.md) | 固定 Git blob |
| R10 | [MEF-end-to-end-20261116/world/report.md](../../MEF-end-to-end-20261116/world/report.md) | 固定 Git blob |
| R11 | [MEF-entry-lifecycle-events-20261114/lifecycle.md](../../MEF-entry-lifecycle-events-20261114/lifecycle.md) | 固定 Git blob |
