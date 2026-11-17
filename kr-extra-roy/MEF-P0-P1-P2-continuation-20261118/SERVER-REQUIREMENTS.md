# Server 開發需求與玩家驗收

本專案目的為開發 Server。本文件將業務、規則、交易與持久化列為 **Server 開發需求**；Client 的未知原生接點另列，不以它們阻擋已有正常流程的 Server 工作。

固定來源為 `15d9501c203c6f656461b64f578a50c96e38a5ff` 的現有契約，來源明細見 [source-manifest.json](source-manifest.json)。本輪不執行或修改 Server；下面是供現有 owner 逐項去重採用的需求與驗收，不宣稱相關程式全部不存在，也不新增正式 REQ／RR。沿用 [前輪 Server 交接](../MEF-P0-P1-master-continuation-20261117/SERVER-HANDOFF.md) 與 [現有需求台帳](../../design/requirements/index.json)。

## 1. 開發次序

下列 Q119 四節點與出口政策沿用現有 **Server 重建候選**（`SERVER_RECONSTRUCTION_NOT_NATIVE_MEF`）；它們不是已從官方 MEF 還原或已在 Client 遊玩觀察的原版流程。原始 Quest／SEQ／表格事實與 Server 候選編排分別固定於既有旅程資料。

實際遊玩排程仍遵循專案既有「新帳號登入／創角選角／新手教學／進入廣場」正流程優先。本表的取消、重送、重連及失敗一致性是應保存的工程要求；這輪沒有重啟已暫緩的邊界／故障測試，也不以它們阻止先驗收正常流程。

| 次序 | 玩家目標 | Server 需提供或核對的內容 | 可判定的完成證據 |
|---:|---|---|---|
| 1 | 不播錯角色、場景或無法使用的指令 | 內容版本、typed selector、ABI／stub 檢查、資源選取與缺件狀態；把資料檢查與可上線條件分開 | 錯誤參數、bool 誤代 number、未知能力與未齊素材被拒絕；有同版來源與實際選取的內容才通過對應條件 |
| 2 | 對話與劇情不重播、不卡住，離開後恢復 | 每 run 的排程、busy、合法入口、取消／timeout、收尾次序、跨圖／重連政策 | 正常開始／結束／下一段、取消、重入皆維持一致；本地已起播分支不被 001C 再播一次；003F／00EB 不作總完成通知 |
| 3 | 怪物確實死亡，清光一群才算過關 | instance／actor 世代、HP、唯一死亡轉移、移除原因、敵群狀態、事件去重與相容 wire | 重送不重複擊殺；同 ID 的新角色不吃舊事件；傷害顯示、HP 更新、死亡與移除各按真實意義使用 |
| 4 | 清完敵人出現出口，走到出口能進下一區 | Q119 四節點、point 集合、距離／資格／目標驗證、正確 portal 建立／更新方式 | node 1–3 清組後建立出口；node 4 先有關閉出口再更新。0027 replacement 保留仍有效的 NPC／shop／其他 point；0048 不被當成建立點 |
| 5 | 結算只領一次，回城可以繼續玩 | result、任務、經驗／等級、資產原子提交；回城 world snapshot／NPC／控制狀態；重連恢復 | 斷線／重送不重複獎勵；回城可走動、對話；再次登入進度一致；Q120 仍檢前置 Q119、level 8 與 NPC10008 |
| 6 | 商店、教學及後續任務有真正結果 | 接既有服務 context、數量／價格／資格／消耗、背包／貨幣／裝備交易與持久保存；教學權威進度 | 畫面開啟後，購買或任務動作會改變正確資料；失敗不扣錯資產；重登仍一致；依現有主線及服務 owner 接續 |

現有相關脈絡為 REQ-0010／0016／0017／0018／0019／0021；本輪固定台帳仍為 CANDIDATE，沒有升級正式狀態。不要另造同義需求或覆蓋他人認領。[來源 pin](source-manifest.json)

## 2. 本輪給 Server 的兩個新增限制

### 索引開啟不能當資源完整

P0 的 cache reader 沒有以完整索引驗證作為「成功」條件。Server／發布工具應有自己的明確資料檢查：長度、結構、group／entry 參照、需要的 basename、同名優先序與實際檔案來源。工具發現不完整時保留不可發布；不得自行補猜 winner，也不得把離線合成的 cache 樣本當作玩家原安裝內容。[P0 分題](p0-selection/)

### UI 介面建立不能當背景腳本啟動

P1 已定位 resource 212 的 `UI/Component/TalkBox_Scenario_Panel.FTC` 及具體 native 建立路徑。它補上 UI resource 的證據，不提供任意內容起播或同 VM 持續 pump。Server 不新增一個假設「打開這個 UI 就會自動跑新腳本」的流程；先採已有證明的有限演出與正常封包 adapter。[P1 分題](p1-entry/)

## 3. 保留相容層界線

- Server 可內部持有 `runId / instance / generation / eventSequence / reason` 等需要的狀態；不把未證欄位硬加進原 Client wire。
- 0000 的比例值、0034 的絕對 HP／SP／MP、000E 的視覺效果、000C 的狀態轉移與001A 的 erase 分開投影。畫面變化不取代權威死亡與獎勵提交。
- 既有外部 scenario schema 的 events 是 `Entry / GroupCleared / InteractZ`，actions 是 `SpawnGroup / UnlockPortal / NextNode / Result`；`enterScenes / clearScenes / returnScenes` 位於另一內容層。研究 JSON 與任意 `PlayScene` 不是可以直接塞入既有 schema 的資料。[現有 schema](../../design/scenario-content/local-scenario-definition.schema.json)
- 外部內容定義維持明確 `NOT_NATIVE_MEF`；不以自訂 JSON 或既有 Lua 能力冒充官方 MEF 相容。
- `RestoreMap` 是圖形／camera 恢復，不能代替 Server 回城時重建 ordinary actors、points 與控制狀態。

## 4. MEF 旅程的端到端驗收目標

既有登入、創角、新手教學與廣場正流程先按主線排程。MEF 旅程接續採全 Q119 研究範圍，逐項取得下列結果：

1. 在正常 NPC／任務條件下起始，Q118、level 5、Field26／Case107／NPC10047 等資格正確。
2. 五段指定演出的角色、鏡頭、對話、聲音與收尾符合所選資料；`119/1 LoadMap("")` 不因空字串被當作無作用。
3. 四戰鬥節點依候選 Cluster／Map632–635 推進，敵群權威、門與 Z 互動一致。
4. 結果提交一次；返回119/5及Town1後可正常操作與對話。
5. 滿足條件後才開 Q120；任務／資產持久化須有工程證據。重連與重送的故障／邊界演練保留到使用者重新排程，不在本輪啟動。

驗收時分別保存內容檢查、Server 狀態／serializer、持久資料及正常 Client 流程結果。靜態 BND 座標可站立只提供候選位置，不能取代動態碰撞或實際通關。缺少聲畫素材的 profile 不提升為完整體驗 ready。

## 5. Client 原生缺邊的獨立處理

普通背景入口 B、任意 world→原 Lua 與官方 MEF 格式各有 [精確補證條件](SOURCE-REQUEST.md)。若未來產品明確要求原 Client 具備新 typed bridge，必須另做設計與驗收；現階段不能把未證接口列成 Server 排程的必要現成功能。Server 的戰鬥、任務、服務與保存工作可依上表持續。
