# Server 開發增量：MEF run 的持有、退出與下次准入

本稿配合整包 [SERVER-ADOPTION.md](../SERVER-ADOPTION.md)，作為既有 **REQ-0019／REQ-0021** 的研究輸入。這裡的名稱是 `NOT_NATIVE_MEF` 設計欄位；沒有新增 wire、部署 schema、原版 Server 規則或改正式狀態。現有 Server 外部 scenario schema 沒有 scene selection／cleanup ledger 欄位，不能把本題 JSON 原封不動塞進去。[本輪 integration 的原 schema 核對](../integration/README.md)

## 1. 需要落實的五項開發

| 開發輸入 | 具體內容 | 驗收邊界 |
|---|---|---|
| 每 Client 的演出准入 | 關聯 session／instance／scene世代、內容版本、真雙鍵、normal/review政策；共享Q／map／camera／UI演出依准入序列化 | 不把 busy 的忽略當排隊；不同 run 不能對共享 owner 競爭全清 |
| 版本綁定內容審查 | pin Client hash、SceneList／SEQ／helper、完整依賴、ABI結果及 owner acquisition plan | declaration／table命中／檔名存在不是 runtime-ready；缺依賴維持NOT_READY |
| 分離完成記錄 | 分別記 requested、發送、可能skip、報告觀察、內容結果未知、owner清理請求、native後續未證、權威業務提交 | 003F不證script執行／cleanup成功；沒有已證ACK的欄位保留unknown，不能自動補true |
| 下一 run 策略 | 明選有限效果、同run多phase、獨立run；B使用自己的真雙鍵／seen／context條件 | 不任意重播、不拿Q119/3與Q2440/5配成A/B；不可讓A晚到的全清清掉B新state |
| 正常返回與權威結果 | 控制mask／00EB／controller恢復各有分支；任務、戰鬥、出口與結果由Server既有權威流程決定 | 演出actor不是worldEntity；Qmodel1086不是candidateboss1022；不依UIobserver0結算 |

依據為 [owner-ledger.json](owner-ledger.json)、[run-contracts.json](run-contracts.json)、[report.md §8](report.md#8-入口seenbusypump與回報同run和跨run的差別) 及既有 [entry](../../MEF-end-to-end-20261116/entry/report.md)／[input-lifecycle](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md)。具體程式接點與目前候選來源以 root 採用規格為準，這份交接不建立平行需求台帳。

## 2. 退出策略必須能接受的真實狀態

正常 Q.CreateObject 的 first request 是 immediate1，正常返回前 apply。不要因 generic deferred模型而把現有scene標成必有舊callback；真正非immediate情境需附mode0 producer。對 selected item 更新，dirty改變但D+20未被setter改變。無論初始模式如何，applied instance的清理可以先排native release、再清樹，後續worker才放引用。[本題report §3–4、native N01–N04]

`DeleteAllObject` 的level-job event不是所有request/result/release工作的drain；003F也不是這種token。因此正常handoff採用「已證清理順序＋清楚記錄允許的native後續＋B的獨立前提」，不要把未知變成成功，也不要強迫產品等待一個沒有Client出口的假想ACK。若確定業務需要全queue靜止，新增的需求必須指定同manager的queue-empty、in-flight及apply/release consumer，交Client補證後才可宣稱實現。[completion-boundaries.json](completion-boundaries.json)]

圖片與音樂要作內容政策，而非全部退出就一律stop。Q新圖會先取消舊圖；如果需求是完整自然淡出，次圖時間另訂。BGM pool共享，StopMusic是全pool。SetFinalMusic空字串不清，但acceptedStart會assign empty；同run第二phase不會自動取得這個Start reset。camera Stop／Detach／snapshotpop、單mapbackup與page savedUI也各有自己的配對條件。[report §6–7]

## 3. 對目前兩個原 scene 的採用結果

| 原場景 | 本題提供的可採用結果 | 仍不能放行的項目 |
|---|---|---|
| Q119/3 | 原正常前綴／尾端、3個Qactors及完整helper鏈；目前Server候選的Map635 enter scene | 依賴／runtime selection與context；不是Q119/4 clear scene，不宣稱完成清組 |
| Q2440/5 | 14actors、預設及9顯式item ownership；camera／talk／image／Prolog／BGM等共享owner的收尾結構 | 真資料缺口依資源分題；原fadeout0已證跳過除法並達有限回收；原helper零arg EndSepia已證native入參0；新作者explicit-arity政策另列，不改原資源 |

這兩列並非新的部署列表。本輪 [original-call-review](../abi-adoption/original-call-review.json) 和 [content-dependencies](../content-dependencies/) 的真來源、缺檔、strictauthor與原件相容語義應一起審閱。任一分析工具PASS不解除資料NOT_READY，也不等於此Client已看見這版本。

## 4. 完成條件與接續順序

1. 將本輪ABI／資源／owner evidence的hash綁到既有Server內容審查輸入；使用版本化的新增開發，保留現有schema契約。
2. 從目前主線候選選一個真正正常入口，補齊該入口的所有原payload及runtime選取材料，核對同page／controller／map／camera取得基準。
3. 按該內容實際選擇一種run策略與清理DAG；需要multi-phase或兩run時，提出真slot/model/action及真正相容的雙鍵集合。
4. 串回現有Server權威戰鬥／清組／出口／結果／返回路線；分開記演出報告與權威業務提交。
5. 依專案既定正常流程驗收可見圖／音樂／對話／相機／操控及返回。此輪只交分析與工具，不例行啟動完整Server行為、故障或壓測。

這些是待開發／待整合／待遊玩的具體工作，不是把原Server內部決策未知當Client逆向失敗。P1普通場景首次非Q入口、world結果到Lua、P2官方MEF格式仍依整體計畫獨立排程。
