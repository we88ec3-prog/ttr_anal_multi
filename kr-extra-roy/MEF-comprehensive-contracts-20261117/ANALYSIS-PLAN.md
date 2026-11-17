# 完整 MEF 分析與功能恢復規劃

日期：2026-11-17；範圍與來源固定於本包 [README](README.md)。這是供接續工作的規劃，不是正式 RR 認領、S00 核准或已開發宣告。

## 1. 完成目標要分開驗收

使用者要恢復完整關卡／演出／互動功能，因此規劃保留全部功能域，並分開追蹤三條成果線。

1. **原 Client 可用能力。** 確認合法入口、參數、typed identity、owner、真正作用、存續與停止方式。已證部分直接復用，本輪將121個正常binding補齊ABI及回值分類。
2. **相容 Server 與內容。** 以自己明確命名的 schema、既有封包 adapter、權威事件與資料實作所需關卡；所有新格式明示 NOT_NATIVE_MEF。是否取得官方 `.mef` 不作這條線的前置。
3. **官方 MEF 相容。** 另證 `MapList.TRIGGER → 名稱消費 → bytes loader → parser → executor`。有相似Lua loader、有副檔名或自訂JSON可執行，都不構成這條線已完成。

每條線另記原生證據、規格接受、程式實作、正常流程遊玩四種狀態。避免用 API 數量、合成測試數量或發現一個 parser 估算整體完成百分比。[主線功能政策](../../governance/MEF-FUNCTIONAL-COMPLETION.md)、[全功能矩陣](COMPLETION-MATRIX.md)

## 2. 建議接續順序

| 優先序 | 工作包 | 具體產物與完成條件 | 主責層 |
|---|---|---|---|
| P0 | 採用勘誤與 ABI | 內容編輯／載入工具拒絕錯誤數量、bool→整數誤用、無producer回值、stub能力；以新圖片替換語意修既有模型。版本綁定至本包的JSON與原件hash | 跨功能整合、Server工具 |
| P0 | 內容真實依賴 | 為選定的現有scene逐項綁 selector、SEQ、模型／動作、camera、map／BND、對話文字／portrait、音訊與圖片。採原native的ID／覆寫／索引規則，不把world PRE套入Q；缺資源維持NOT_READY | 資料／跨功能整合；必要loader由Client補證 |
| P0 | 執行與收尾契約 | 在同一Client context標明Q樹、camera snapshot、圖片、音樂與模型引用的持有及退出時機；明確選擇有限效果、同run多phase或獨立兩run。參照最新資源引用補證，不能以裸pointer推駐留 | Client補證、跨功能整合 |
| P1 | 第一個完整正常旅程 | 從已配置的正常入口進入內容，完成對話／必要演出、戰鬥／清組、出口Z、結果與返回；每一段都連已存在Server契約與真實資料 | Server開發、跨功能整合、待遊玩 |
| P1 | 擴充所有功能族 | 相機、聲音、圖片、書本／教學、世界NPC／服務、互動點、場景／小地圖各完成至少一個真實資料契約，再做組合。不要把A1有限插播當作全部MEF範圍 | 各域Client／Server／整合 |
| P1 | 不中斷普通場景首次入口B | 只追有型別receiver與真實caller的候選，證明第一次script啟動、同VM與持續排程；沒有入口就保留缺口，不用任意呼叫地址替代 | Client待逆向 |
| P1 | world結果到Lua的出口 | 從普通actor/entity生命期與已證結果producer反向接到同run、同EntityId／generation的Lua可觀察值；只有getter名字或AI內部返回值不算 | Client待逆向 |
| P2 | 官方MEF原始格式 | 有新檔案、不同Client版本或新的明確consumer才擴大搜尋；取得真實正例後，做最小可證grammar／executor測試向量 | Client待逆向，獨立相容線 |

P0不表示把所有後續功能延後到完全沒有未知。可同時推進不依賴未知入口的Server事件、任務／資產與已知正常流程；缺少B入口不妨礙Server權威觸發已知有限Q演出，缺少官方MEF也不妨礙外部關卡定義。反之，Server已能排程不會補出未知Client wire、Lua callback或完成ACK。

## 3. 研究要從具體缺邊接續

### 3.1 Lua入口與執行

已完成的正常121名稱、33 marshaller、122 registrar模板、223 direct sink與既有語言庫盤點沿用，不再把全量重掃當成新進展。若要新增能力，必須帶新的table population、receiver writer、closure installation、metatable或真正caller，並標明與既有VM／phase的關係。[ABI](abi/report.md)、[前輪surface census](../MEF-full-surface-native-continuation-20261116/REPORT.md)

普通場景首次入口B仍需「誰以什麼事件呼到哪個typed receiver，如何載入／註冊第一個callback，之後誰pump」的完整鏈。本輪 `CScenarioTalkBox` 已核91個vtable槽與選定constructor／open／hide writers；不要再僅以 `OnYes`、`open` 或共用 `this+9C` 偏移推普通入口。新的候選應來自未核的具體事件owner／controller類別，而不是重掃同一字串。[事件報告](events/report.md)

### 3.2 事件與遊戲權威

16個正常query的來源已定型；多數是本地狀態或固定角色條件，沒有任意world EntityId的死亡／群組完成契約。若以本地自動戰鬥為目標，需接同一EntityId的建立、generation、HP／死亡、移除原因及終點consumer。`54AA60` 在已核consumer中屬native控制方向／輸入，不是Lua結果出口。[事件catalog](events/observation-catalog.json)

Server應繼續作每實例／群組權威事件、已知NPC及點位回覆、任務／結果／資產提交。事件只有在具體Lua出口或既有packet adapter證明可達時才投向Client內容；不能把Server自訂event bus稱為原Client已暴露的腳本API。具體開發輸入與驗收在 [SERVER-HANDOFF](SERVER-HANDOFF.md)。

### 3.3 資源與重用

把資料表、實際carrier member、runtime選擇及畫面可用分開。現在有完整的三包index、原文字SEQ相機引用、Q119/3選定依賴與Q2440/5單張圖的起點，新增carrier應只補變動的依賴，避免重做同一輪搜尋。[資源分析](resources/report.md)

Q模型註冊使用ID，PRE不參與該key；原FILE經`.abf`名稱查CHA_ABF後才得到真正目錄／檔名。下一份選檔材料應是目標版本的`fcs.flu`、索引內容或cache-miss時的實際目錄／mount，不能再把world PRE1當成解法，也不能把Base內Mon路徑直接替換Character fallback。[選取鏈](resource-selection/report.md)

模型工作必須核同一resource identity的所有已知持有者；只看Start的level3 replace或catalog+54非NULL都不足以裁定卸載／恢復。選定鏈已接到實際引用、reload與cleanup時，仍須核job取消、舊callback、actor留存及render gate，才可給跨段落安全結論。[重用分析及補證](reuse/report.md)

圖片的新規則是先取消上一張Q追蹤圖、再建立下一張；實體釋放仍等manager。若要求兩張同時持續，不能把連續Q.FlyingObject當多圖API；若要求自然完整淡出，不能同時再呼新圖取代。camera Stop／Detach／Pop、全Q樹清理及End按實際owner依賴排序，沒有同一run的原生token就不能假設盲重試安全。

### 3.4 官方檔案路徑

只有副檔名、`MapList.TRIGGER`字串、檔名hash、Lua parser、或Client更新器能下載檔案，仍少了「這些bytes被此parser消費」的接點。下一份證據必須是：真實MEF正例、開檔consumer／dispatch、格式magic／版本／record、執行command與狀態owner，至少能閉合一個可重現正例。不同版本要另核SHA與mapping，不跨KR／TC套位址。[既有parser與storage](../MEF-parser-executor-storage-20261114/parser.md)

此線的具體解除材料是新原始carrier／sample、實際consumer或經允許的人測trace。它不是停止現有Client靜態分析或Server功能開發的理由，也不應用重複全文搜尋來假造進度。

## 4. 每個功能都使用同一驗收模板

| 欄位 | 必填內容 |
|---|---|
| 玩家情境 | 玩家何時看見／操作什麼；正常完成、結束後可繼續哪段旅程 |
| 合法入口 | 真實場景／表格selector／native caller或已證wire；首次進入及重用分別說明 |
| 呼叫契約 | API完整參數、型別、typed ID、native及receiver；禁止把無回值當ACK |
| 資源 | 原包hash、member及variant選擇、prepass/formal差異、實體依賴完整度 |
| owner與退出 | 誰保存狀態、誰更新、什麼條件停止／恢復；共享owner與全域清理的範圍 |
| Server開發 | 需自己提供的業務規則、資料、權威事件、持久化及既有adapter |
| 未知與解除條件 | 指向具體caller／writer／缺檔／人測步驟，不能只寫「待研究」 |
| 分層證據 | 原件靜態、衍生資料、SYN、Server工程、實際Client正常流程分別列出 |

產物先過資料與ABI檢查，再過整合規格與現有Server所需的工程核對，最後依專案既定正常流程交由允許的Client測試。新內容尚未部署、沒有真實Client結果就維持待遊玩，不因工具PASS填成可玩。

## 5. 功能組合的建議路徑

第一組選「真實既有selector＋有限圖片／fade或相機／對話」驗證入口、資源與退出。第二組接「Server權威清組／互動旗標→既有有限Q內容→恢復點位→出口Z」。第三組擴充世界NPC、服務UI、書本／教學與完整場景轉場。最後再把已各自驗好的功能合成兩段或多phase內容，檢查共享owner與重用。

這個順序保留廣度：每個功能族都有自己的資料與驗收條件；同時先解會讓任何內容都出錯的共用ABI、資源與生命期問題。正式任務／商店／銀行／掉落依主線既有進度接續，不重造已完成的服務，也不為追官方格式而暫停恢復正常遊玩。
