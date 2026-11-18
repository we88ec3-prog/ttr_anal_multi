# 關卡／MEF功能完成追蹤

使用者目前目標：完成關卡／MEF功能開發，不把取得官方檔案或復原歷史格式當前置。
自訂定義沿用自己的schema與副檔名，明示NOT_NATIVE_MEF；原生格式與傳檔相容性
是獨立研究事項。此表不是已完成宣告，也不以合成測試數量換算完成百分比。

## 2026-11-14 extra/roy1 整合

2026-11-19：[一般狩獵場單趟正常入口](../design/testing/HUNTING-NORMAL-ROUTE-INSPECTION.md)
新增 41 條工程收據：15 個 Case 全部 37 條基準路線，加自訂 AI 與 81 EXP 匯出
版本各兩條。準備角色 4／Lv.15，第二村以前綴準備資格；廣場建隊至結果同室
回村均經應用層驗證。這不提升原生 MEF、Client 自主生怪或實機驗收狀態。

2026-11-19：追加 [已存檔背包數量旗標](../design/scenario-content/BAG-QUANTITY-SIGNALS.md)
的 Server-owned 契約與實作驗證。它只表示在目前副本曾持有指定數量，
不消耗道具、不涵蓋持續持有或任務交付。原生 MEF 載入鏈缺口維持，
未將一般戰鬥生怪／AI 移交給 Client。功能實機驗收另列 BQ-01。

S00 將 `be56ab2e6`、`2d9896d62`、`0a2503db0` 的研究稿與證據包保留於主線。以本機 KR 原 BIN 及 launcher EXE 重新核對 475 個原件視窗及 28 個錨點的位元組和 PE 映射；兩份 KR 原始 STP 的整檔 SHA-256 亦與來源相同。此處為 S00 限定核對，實機驗收與 T01 全面複核仍各自記錄。

| 問題 | 本次可採用的結論 |
|---|---|
| 何時能交付檔案？ | 啟動遊戲前，原版更新器可依相容 HTTP 更新清單下載 gzip 並寫入普通檔案。已有原件靜態呼叫鏈；實機落檔待驗。直接使用指定 v2 EXE 的既有測試流程沒有用到這條更新器路徑。 [交付時機](../kr-extra-roy/20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md) |
| 何時會解析原生 MEF？ | 仍未知。Client 有可達的 Lua 解析器與本機資源載入器，已追到 `MapList.TRIGGER` 的名稱存放處，尚缺從該名稱開檔、解析並執行的呼叫鏈。已檢查的遊戲 TCP 路徑也未找到原生 MEF 接收器。 [解析器與儲存](../kr-extra-roy/20261114-190624-chatgpt-web-roy1-MEF-parser-executor-storage.md) |
| 普通副本能接手哪些工作？ | `0047` 可選擇已配置的有限 Q 劇情，並由共用場景更新協程。Q 執行時可能清除控制器的移動與動作輸入。本地生怪 API 尚缺可供 Server 對齊的物件身分及普通副本的可靠死亡事件。現行生成、AI 判定與清場仍由 Server 處理。 [場景入口與生命週期](../kr-extra-roy/20261114-192949-chatgpt-web-roy1-MEF-entry-lifecycle-events.md) |

|功能需求|目前具體成果|未完成／可驗收的下一步|
|---|---|---|
|有版本及來源的內容定義|Scenario／MonsterBehavior JSON、SHA及唯讀目錄。[主線外部關卡檔](../design/scenario-content/STORY-SCENARIO-OVERRIDES.md)可逐任務覆蓋戰鬥編排並檢查來源|擴充條件與動作後持續維護 Schema 和契約。Q119 候選待實機|
|每實例事件與保存界線|Entry／聚合GroupCleared／InteractZ、圖序與結果提交。順序波次、定時與區域增援已有實機結果；條件出口與手動互動點已有合成驗證|分支、條件出口、手動互動及清場延遲待集中實機。未完成的副本依既有規則重登重來；完整3D機關與更多條件來源待開發|
|出生與怪物群|首兩圖與33個後續節點可由內容指定配置；換波保留玩家資源／冷卻。[旗標增援](../design/scenario-content/REINFORCEMENT-FLAGS.md)可由區域或互動觸發，[逐波清除](../design/scenario-content/WAVE-CLEAR-SIGNALS.md)可在指定波倒下後開互動或觸發增援|教學固定配置、其餘關卡的出生與出口幾何仍待核對；兩項候選待實機，正式關卡資料待編排|
|Client本地生成怪物|既有lb.CreateObjectEx可本地建立CMonster；與0007外部生怪是不同入口。第六參數可接現有控制槽，已知SubAI攻擊執行器會跳過模型1036|普通副本的合法啟動來源、生成物件ID對齊與同步待證；目前仍由Server發生怪封包。見[控制器掛接補證](s00-iterations/S00-20261113-MONSTER-LOCAL-CONTROLLER-BOUNDARY.md)|
|物種AI與個別參數|逐出生指定profile、追擊／定點近身、輪替選招與個別冷卻。v93實機確認追擊／回位。v99直線投射物後端已通過合成。[波次血量旗標](../design/scenario-content/WAVE-HEALTH-SIGNALS.md)支援在原波存活時觸發增援或互動|選招實機、投射物視覺／物種動作、多目標仇恨、物種召喚、特殊Boss資料與血量階段實機仍待驗|
|Client執行固定路段|單次目標＋Server待機排程已實作；v92人測停止彈跳、速度可接受（當次程序v10）|尚未併入戰鬥AI；自主抵達／取消條件未知，排程不算Client完成ACK|
|怪物巡邏路線|關卡可逐怪指定路點，接索敵、追擊、回位與巡邏恢復。巡邏怪追擊或回位遇靜態牆面可改走可通行路徑。Q119 有一般巡邏及繞牆候選|PT-01 至 PT-03 待實機。Q119 有靜態地形對照，動態障礙未接入。 [巡邏規格](../design/scenario-content/MONSTER-PATROLS.md)|
|既有劇情啟動與收尾|已知scene鍵交由Client序列執行|普通副本腳本入口與壽命、與清組／任務完成的正確關聯|
|出口生命週期|出口可預先關閉登記，勝利後更新再按 Z 換圖。清場劇情後可按已提交旗標重建整組點位。[清場後延遲旗標](../design/scenario-content/CLEAR-DELAY-SIGNALS.md)可控制出口與互動點|分支多點、清場劇情重建和延遲旗標待實機。入場標記已通過，正式特效待決定|
|換圖後玩家狀態|一般主線可由外部關卡指定延續 HP、SP、MP、定時回復與剩餘冷卻，涵蓋入場劇情後的戰鬥重建|Q119 的 SC-01 待實機。增益、連段、蓄氣與投射物延續未開放。 [外部關卡規格](../design/scenario-content/STORY-SCENARIO-OVERRIDES.md)|
|入場後計時事件|戰鬥開放後依關卡指定秒數設立旗標，可控制增援、互動及出口。Q119 第一圖有定時增援範例|ND-01 待實機。原版個別關卡的時間與配置仍待來源核對。 [計時旗標規格](../design/scenario-content/NODE-DELAY-SIGNALS.md)|
|Client自行開門|本地setter存在|能收到該instance清組事件且Server停發開門時仍能完成，尚未證實|
|旗標控制通行|主線可用既有旗標解除個別副本的屏障，適用 Server 移動、尋路、戰鬥與互動，並能同步既有 Client 點的開關狀態|GB-01、GB-02 待實機。Client 的 3D 門、動畫與本地碰撞待接。 [屏障規格](../design/scenario-content/FLAG-BARRIERS.md)|
|地形傷害區|主線可配置週期傷害，依玩家位置與旗標開始、重算或停用|HZ-01 待實機。Client 陷阱外觀及跳字待來源。 [地形傷害規格](../design/scenario-content/AREA-HAZARDS.md)|
|持續占點|可按區域停留時間設立旗標，接增援、屏障與出口。離區會重算未完成時間|RH-01 待實機。Q119 提供占點開門候選。 [占點規格](../design/scenario-content/REGION-HOLD-SIGNALS.md)|
|NPC／市場內容|市場配置獨立載入，三村商店已接共用交易與資產更新，銀行共用存提款。三村可穿戴商品已接裝備欄、基礎能力值及鐵匠商品外觀更新|待實機驗商戶點位、視窗、交易、裝備面板／外觀及傷害。強化與進階能力公式待接。 [三村市場](../design/scenario-content/TOWN-MARKETS.md) · [裝備規格](../design/scenario-content/EQUIPMENT-WEAR-WIRE.md)|
|通用內容執行器交付|有限typed事件與既有packet adapter|功能範圍足夠支援需求關卡，不能只搬常數便算完成|
|管理／編輯工作台|Admin.Web 提供[主線副本](../design/scenario-content/SCENARIO-WORKBENCH.md)、[一般狩獵場 15 個 Case](../design/scenario-content/HUNTING-SCENARIO-WORKBENCH.md)及[自訂 AI 配套](../design/scenario-content/SCENARIO-AI-BUNDLES.md)：固定範本、關卡與 AI 同版保存、來源／條件／AI／BND 驗證與配對 ZIP。新舊草稿及原 BND 正流程已驗，編輯的 Case 693 結算與預覽一致，新 AI 已進入 Server 戰鬥執行器|圖形化編排、任意新 Case 部署及原生 MEF 尚未完成。未自動發布或宣告遊戲實機通過；使用者已取消另建簡易帳號頁|
|完整場景驗證|已有部分正常旅程人測及獨立工程收據|每個新增功能的來源／Server測試／Client人測分開驗收|
|馮德斯一般副本練等|Stage 462／463 的四個 Case、八條路線均用原版 BND 走完正常建隊、選關、生怪、戰鬥、頭目清除、掉落、拾取、結算與回村。每條路在出口前已入帳 56 EXP，結算後單場合計 76 EXP。Case 693 兩路各撿三張復活卷軸，其餘各一張。離線檢查器逐圖比對測試頁顯示、存檔與預期經驗。|指定 v2 Client 的正常入口、戰鬥、Space 拾取、升級顯示及回村循環待實機。見 [TS-37 批次驗收](../design/testing/S00-CONTENT-BATCH-TESTS.md)。|

輸入、連段、合法移動／命中、HP／資源／冷卻、帳號／任務／背包與資產提交，
仍屬共用Server領域功能；關卡可以描述何時觸發，但不得繞過權威與持久化。

後續實作者須區分兩種進度：內容定義取代了哪些逐關硬編碼；哪些原有Server
指令停止後Client仍完成操作。任何自動決策、完成ACK或官方格式沒有證據時保留未知。
功能開發不因此停下：用明確Server-owned定義與可驗接口推進，不偽裝成原生復原。
