# 目前找出的 MEF 種類：用玩家功能分類

**可整理成 12 類用途，同一份 MEF 可以組合多類。** 這是本專案依已證能力與現有 Server 服務整理的用途分類，不是宣稱原版存在 12 種不同 `.mef` 格式。Server 端執行的關卡／戰鬥／獎勵規則也屬 MEF 開發。

## 各類負責什麼

| 類型 | 玩家看到的用途 | 負責的工作 | 現況與界線 |
|---|---|---|---|
| M01 關卡流程與分支 MEF | 打完第一區後開左右兩條路；選一條路繼續，最後才結算。 | 節點、前置旗標、清場後事件、每個出口的目的地及通關條件。 | 現有 scenario definition、有限節點圖、ALL 旗標及逐出口資格可沿用。 關卡規則可資料化；規則仍在 Server 求值的部分不計為 Client 計算外移。 |
| M02 生怪與增援 MEF | 進房先出一群小怪，打完再增援，達成條件後頭目登場。 | 怪物模型、出生位置、波次、生成時點、必要敵群與世界身分的接線。 | Server 波次引擎可沿用；lb.CreateObject[Ex] 有本地 world actor 建立路徑。 本地建立與封包建立的 CMonster 初始化不同；沒有新 Lua EntityId 回值，不可用 GetObjectCount 當存活數。 |
| M03 怪物行為、戰鬥與頭目階段 MEF | 頭目血量下降到指定程度後出增援；所有必要敵人確實倒下才算清場。 | 巡邏、追敵、返家、選招、戰鬥參數與階段條件、有效 HP／死亡事件、波清與對應畫面回饋。 | 實際 Server 已有行為 profile、依血量／距離／冷卻選招、傷害與投射物規則；Client 有動作、結果及投射物呈現 consumer，新的投射物視覺 adapter 仍待接入。 NumberPanel、BattlePanel、BurstStruck 是回饋，不寫權威 HP；完整普通敵方 AI／命中判定下放不是已閉合通路。 |
| M04 機關、占點與障礙 MEF | 站在圈內一段時間、按下拉桿或打倒守衛後，關閉陷阱並開放通路。 | 進區／占點／互動條件、一次性旗標、傷害區、障礙及既有點狀態。 | 現有區域與按鍵規則可用；Lua checkpoint setter 共用點更新consumer；另找到6個門模型的CEventObject外觀狀態鏈。 出口啟用、光效、門模型和碰撞各有 consumer；改點狀態不自動成為物理門。 |
| M05 出口、地圖與轉場 MEF | 清場後出口亮起，按鍵進下一區，出生位置與目前進度一起接續。 | 出口目的地、換圖、同圖重建、完整點集、演出地圖備份與小地圖。 | 現有互動意圖與 Server transition 可復用；Client 有地圖載入、小地圖與 Q 地圖備份／還原。 lb.ChangeMap 不自動取得 Q 的 map backup；只換本機地圖不等於兩端實例及進度已切換。 |
| M06 角色演出與外觀 MEF | NPC 走到玩家面前、轉身說話；頭目登場時做指定動作。 | 演出角色建立、移動、走路、轉向、動畫、顯隱與 world actor 外觀部件。 | Q 演出 slot 與 native 動作有既有入口；world 外觀與附件也有有界 consumer。 Q 角色與可戰鬥 world entity 分開；Q.DeleteObject 是 stub，Q.IsAllObjectsStopped 不能當敵群清空。 |
| M07 劇情、對話與教學 MEF | 播放對話與字幕，提示玩家移動、攻擊或切換角色，完成後繼續下一步。 | 多列對話、字幕、書本、序章、教學頁面、已映射操作與教學進度。 | 有限 Q 與真正 Tutorial context 的互動鏈可用；教學 pump 不要求 Q 正在播放。 Tutorial 條件不能直接當普通戰鬥事件；Q.BalloonTalk、Tutorial.InsertObject 是 stub；seen 回覆不證正式 callback 執行。 |
| M08 鏡頭與畫面效果 MEF | 頭目特寫、鏡頭跟隨、淡入淡出、黑邊與慢動作。 | 鏡頭路徑／跟隨／快照、畫面轉場、色調、黑邊與動畫速度效果。 | 既有 native consumer 執行鏡頭與畫面效果的後續更新。 每種效果的時基、owner、結束與回收條件不同；慢動作不等於 Server 戰鬥時計一併變慢。 |
| M09 音樂、語音與圖片 MEF | 進頭目房換音樂、對話播放語音、顯示圖片或飛入畫面。 | 音樂與淡出、音效、語音、圖片替換／縮放／飛行與取消。 | 已知 binding 可啟動 native 播放器與圖片效果；本地維持各自後續更新。 新圖片可替換先前 owner；效果消失不能當任務、獎勵或保存完成。 |
| M10 NPC 與商店服務 MEF | 完成任務後鐵匠開放，NPC 說不同台詞，玩家買賣或強化裝備。 | NPC／商店位置與資格、對話順序、貨單／價格／消耗政策，以及既有交易服務接線。 | 既有 town placement、任務解鎖、商店 UI 與交易服務可以復用。 可見模型、NPC key、ShopNo 與互動點不同；Server 改價格不代表本地貨架顯示會自動一致。 |
| M11 結算、獎勵與進度保存 MEF | 過關獲得經驗與道具，再登入仍有已完成任務與已拿到的獎勵。 | 完成條件、受益範圍、獎勵政策、提交時點、返回與可保存的里程碑。 | 既有任務、經驗、背包、錢包、冷卻與持久化服務可直接接 MEF 決策。 畫面數字、演出結束與落地掉落各不代表已入帳；目前副本暫存旗標不等於永久戰鬥檢查點。 |
| M12 輸入、排程與生命週期 MEF | 演出時暫時鎖住操控，結束後還給玩家；等待正確條件後再接下一步。 | 合法入口、協程、等待、輸入 mask、鍵位切換、收尾與所有權；診斷／顯示設定列為附屬能力。 | 既有 Q／Tutorial caller、原生輸入控制和本機時計可復用。 回傳 callback 不等於 End；End 不會自動完成全部 owner 清理；本機時計不是 Server 時計；PrintCurrSceneID 是 stub。 |

## 內容在哪裡執行

| 路線 | 負責的內容 | 適用條件 | Server 能少做什麼 |
|---|---|---|---|
| Server 執行的規則 MEF | 生怪、戰鬥條件、波次、分支、機關、出口、獎勵與保存政策。 | 沿用現有 scenario／MonsterBehavior 與服務；新語法另列編譯／adapter 工作。 | 少寫每關專用程式；事件索引等優化可減少求值；規則本身仍在 Server。 |
| Client 有限演出 MEF | 一段有起點與終點的對話、鏡頭、動作、等待與既有點操作。 | 選已發布內容，接受 Q 對輸入／UI 的影響；新版 seen 持久化及點換代約束照前輪補證。 | 可移走多步演出的中間計時與派送；單一點開關不保證更省。 |
| Client 教學互動 MEF | 教學提示、已映射操作與進區觀察、頁面與角色條件、串接有限演出。 | 使用真正 Tutorial field／controller／page；普通關卡不能直接套用同一觀察通路。 | 可移走已支持教學的提示監看、UI 順序及本地等待。 |
| 由 MEF 啟動的原生持續效果 | 已建立角色的更新，或音訊、鏡頭、圖片、淡幕等各自原生工作。 | 每項各有 owner／gate／完成與回收條件；不是 End 後仍能任意排新 Lua 工作。 | 使用 Client 本來已有的逐幀更新，不重複在 Server 模擬；既有工作不全算本輪新增節省。 |

**普通場景常駐 Lua 是另外一個尚未接完整的選用 profile。** 目標是在普通戰鬥保持操控時持續執行新背景腳本，仍需首次內容 producer、持續 pump、輸入 owner、取消／重入及所需事件橋。它不阻塞現有 Server 規則 MEF、有限 Q 或真正 Tutorial 路線。

## 種類數與接口數如何理解

- 已有來源的正常 binding 名稱共 121 個，跨 15 個技術功能域；116 個有可引用的有界作用／查詢，4 個是 stub，1 個不提供名稱暗示的 count。
- 本表把這些名稱各映射到一個主要玩家用途，僅為查找；一項玩法可使用多個功能域，多個玩法也可共用同一接口。
- NPC／商店、關卡分支、結算保存可透過 Server MEF 與既有服務承接；沒有直接 Client Lua binding 不代表沒有這一類 MEF 能力。
- Q.CreateObject 的演出角色、lb.CreateObjectEx 的本地 world actor、Server 封包建立的戰鬥 actor 要分開。畫面數字、點光效與演出完成也不能代替 HP、碰撞或交易提交。
- Q.DeleteObject、Q.BalloonTalk、Tutorial.InsertObject、lb.PrintCurrSceneID 保留 stub 判定；lb.GetObjectCount 保留無有效 count 的判定，沒有因重新分類升格。

## 各類來源及接續工作

### M01 關卡流程與分支 MEF

固定輪數可逐節點展開，同房連戰用增援；作者ID需登錄相容入口且保留主線override限制。入口選路及關內動態分支分開接線。

來源：[report.md](../MEF-level-functional-closure-20261118/rules-waves/report.md)；[report.md](rules-scheduling/report.md)。

### M02 生怪與增援 MEF

依 actor profile 接齊身分、關係／控制、屬性與終端事件；新正速度值限制至native signed16可表達範圍；生成外觀不自行代表完整敵對 AI。

來源：[report.md](actors-combat/report.md)；[report.md](rules-scheduling/report.md)；[report.md](../MEF-server-provided-capabilities-20261118/world-offload/report.md)。

### M03 怪物行為、戰鬥與頭目階段 MEF

MEF 規則接既有戰鬥事件；0094/0000/001A投射物視覺adapter及network entity生命期仍需新增。完整Client自主戰鬥另需控制與結果觀察／回報接口。

來源：[report.md](actors-combat/report.md)；[report.md](rules-scheduling/report.md)。

### M04 機關、占點與障礙 MEF

Server二維封口候選已給；採用時保留必要怪與機關可達。門模型motion的開關語意及真正Client動態碰撞仍另需材料／接口。

來源：[report.md](gates-transitions/report.md)；[report.md](../MEF-level-functional-closure-20261118/space-mechanisms/report.md)。

### M05 出口、地圖與轉場 MEF

按選定入口保持實例、角色、點集與 loading／ready／Q 的交接，重建後使用當代點資料。

來源：[report.md](gates-transitions/report.md)；[report.md](../MEF-level-functional-closure-20261118/finite-handoff/report.md)。

### M06 角色演出與外觀 MEF

選有效資源及角色身分，按該 owner 清理；不得把外觀附件當背包道具。

來源：[report.md](actors-combat/report.md)；[BINDING-OFFLOAD-MAP.md](../MEF-server-provided-capabilities-20261118/BINDING-OFFLOAD-MAP.md)。

### M07 劇情、對話與教學 MEF

綁定內容版本、入口、播放／跳過政策和結束交接；對話結束與任務完成分別提交。

來源：[report.md](../MEF-server-provided-capabilities-20261118/delivery-profiles/report.md)；[report.md](../MEF-level-functional-closure-20261118/finite-handoff/report.md)。

### M08 鏡頭與畫面效果 MEF

內容按自己的資源與生命期配對開始／結束及快照還原；衡量多步演出的實際下放收益。

來源：[BINDING-OFFLOAD-MAP.md](../MEF-server-provided-capabilities-20261118/BINDING-OFFLOAD-MAP.md)；[report.md](../MEF-server-provided-capabilities-20261118/delivery-profiles/report.md)。

### M09 音樂、語音與圖片 MEF

發行正確音訊／貼圖，保留已更正的 FlyingObject 參數與回收契約。

來源：[BINDING-OFFLOAD-MAP.md](../MEF-server-provided-capabilities-20261118/BINDING-OFFLOAD-MAP.md)；[abi-contracts.json](../MEF-comprehensive-contracts-20261117/abi/abi-contracts.json)。

### M10 NPC 與商店服務 MEF

新 MEF 規則接既有資格與交易，選定本地表可支援的內容；不新增第二套背包／錢包。

來源：[report.md](../MEF-server-provided-capabilities-20261118/npc-progression/report.md)；[SERVER-REUSE.md](../MEF-server-provided-capabilities-20261118/SERVER-REUSE.md)。

### M11 結算、獎勵與進度保存 MEF

新增規則綁版本及原有提交點；若要求中途永久續玩，再定義可保存的 checkpoint。

來源：[report.md](../MEF-level-functional-closure-20261118/outcomes-continuity/report.md)；[LATEST-MAIN-UPDATE.md](../MEF-level-functional-closure-20261118/LATEST-MAIN-UPDATE.md)。

### M12 輸入、排程與生命週期 MEF

選定 profile 的首次執行、持續 pump、輸入交接及取消生命期；普通場景常駐 Lua 仍是獨立選用接口。

來源：[report.md](rules-scheduling/report.md)；[contracts.json](../MEF-server-provided-capabilities-20261118/delivery-profiles/contracts.json)；[report.md](../MEF-level-functional-closure-20261118/finite-handoff/report.md)。

機讀分類及逐 binding 的原作用／限制見 [mef-types.json](mef-types.json)。來源為固定 Git 版本；本頁可由 [build_catalog.py](build_catalog.py) 重建。分類與來源核對不代表新增 Client／Server 部署或遊玩驗收。
