# MEF 全面接續分析報告

日期：2026-11-17（Asia/Taipei）；分支 `extra/roy1`。本輪沿使用者指定分支工作，讀取共用指示與當前治理／既有成果後，從已發布的 `5ef4ab8870ea1c65c6c7497901302d851f5c7a51` 接續。該提交已包含先前72份研究成果、分布於四個目錄，不能沿歷史PUBLICATION文字把它們再次當作尚未上Git。本輪只新增新的證據、勘誤、工具與規劃；來源版本見 [source-manifest.json](source-manifest.json)。

## 1. 本輪完成與整體狀態

**本輪已把全部121個已知正常Lua binding的參數與結果契約整理到可預驗內容的程度，並補齊16個觀察query的typed來源。** 同時全面盤點原文字SEQ中的literal相機依賴、接入新找到的Base／ZIP原始資料、更正圖片替換語意，並追到模型doll自身的資源引用／回載鏈。這些都是可由原BIN／原資源及固定Git來源重跑的有界成果。[ABI](abi/report.md)、[事件](events/report.md)、[資源](resources/report.md)、[重用](reuse/report.md)

**整體仍是階段性未完成。** 官方 `.mef` 的首次reader／grammar、普通場景不接管控制器的首次Lua入口B、普通world typed結果到Lua出口等缺邊，沒有因binding表完整而消失。Server需自行提供的規則、資料與回覆列為Server開發需求；功能組合與實際遊玩另行驗收。完整方向與完成條件見 [ANALYSIS-PLAN](ANALYSIS-PLAN.md)；逐功能與四類缺口見 [COMPLETION-MATRIX](COMPLETION-MATRIX.md)。

## 2. 121個正常binding：從名稱清單進到可用呼叫契約

本輪逐項重核正常closure、native slot、receiver、marshaller與結果producer，共121名稱、33個實際marshaller、159個完整函式讀集，21,204 bytes／7,074 decoded instructions。44名稱不讀使用者參數。數字只表示這份有界讀集，不能當全程式覆蓋率。[ABI原件證據](abi/native-evidence.json)、[實跑結果](abi/verification-result.json)

| 發現 | 對內容與Server工具的直接影響 |
|---|---|
| 參數從Lua stack最後N格取，沒有一般argc防線 | 精確個數與順序必須在發布前驗；少傳不能視為補nil／0，多加尾端參數會移動讀取窗口 |
| 整數／float只接受number或可解析numeric string；boolean轉0 | 數值開關傳明確0／1；不能把true當1；新工具採嚴格有限值及signed32整數 |
| `ScenarioTalkTable.open`第三參數另採Lua truthiness | 手動／自動旗標使用真正boolean；明確0在這格仍是真，和一般整數模板不同 |
| 121 closure的EAX=1是Lua結果槽數 | 不是native成功，也不代表新物件ID或完成ACK |
| 17個binding明確push新number，其餘104個沒有新binding值 | 17＝16觀察query＋lb.DoFile；不可讀取其他命令的返回值作成功條件 |
| `lb.DoFile`的0混合開檔失敗與執行成功 | 不能以status==0單獨證明成功；要遵守既有phase／export／版本契約 |

這份結果已落成 [ABI-CATALOG](abi/ABI-CATALOG.md)、機讀JSON與 `validate_calls.py`。預驗器是 **NOT_NATIVE_MEF** 宣告式呼叫檢查，沒有執行原Lua或產生可部署SEQ。14個明標合成反例驗證實際陷阱；PASS只回 `ABI_PASS_ONLY`，`deployment_ready=false`。[預驗資料與結果](abi/validation-results.json)

4個stub：`Q.DeleteObject`、`Q.BalloonTalk`、`Tutorial.InsertObject`、`lb.PrintCurrSceneID`保留不可作所命名功能的結論；`lb.GetObjectCount`亦沒有新count producer。沒有用自訂模型替原Client補成不存在的能力。

## 3. 事件查詢完整定型，避免把本地條件當世界權威

16個正常query全部回number，0在Lua仍為真。它們有可用價值，但每個都受具體owner／key／phase約束。[完整觀察表](events/observation-catalog.json)

- `Tutorial.IsCharacterAvailable` 的native `4A9F00`忽略形式參數，固定看零起算index2、即第三筆roster狀態；不能用它等待任意角色。
- `IsIsiliaFound`固定查world key `F000`，再過camera／距離／投影gate；0不等於死亡。`CheckLeader`檢查領隊`+88 WORD==3`，不回EntityId。
- `GetLeaderPosN`只選0／1／2分量；0混合真座標、無領隊與無效selector。不能作建立完成ACK。
- `IsSynopsisSkipped`的writer `562514`在active gate `56251E`之前；保留特定quest／scene key、且合法Stop caller傳非零參數時，inactive前綴仍可設定旗標，不是天然綁定最新run的通用取消／成功旗標。

本輪也把具體對話候選查到底：`CScenarioTalkBox`與base完整91槽相比有7個override槽，所查專用方法的selected `+9C`直接writers是constructor／open／hide三筆；未找到新的普通B首次入口。`ScenarioTalkTable.open`正式closure為 `6BDEB0`，marshaller為 `6BE090`，兩者不混稱。同時 `54AA60`兩個已核consumer仍供native控制方向／輸入，沒有把結果push成Lua事件。[事件分析與有界陰性範圍](events/report.md)

對普通world權威條件，目前已證可採用的組合是「Server權威條件→既有合法有限演出→既有場景／點位流程」。若要讓Client普通腳本自行觀察清組，還需要同EntityId／generation／instance的producer與Lua出口；現有固定人物query不能代替。這個Client缺口不阻擋Server繼續完成自己的波次、AI、清場、任務及獎勵。

## 4. 圖片語意勘誤：舊圖先取消，再建新圖

原件 `Q.FlyingObject`完整 `564940..564A5B` 在 `56496A`呼 `564A60`，位於allocation之前。它先以同Q receiver取消`M+40`追蹤的上一張圖，標alive=0、清handle，再配置／發布新圖。[原件與順序](reuse/native-evidence.json)

前輪報告把「只保存最後handle」推成「再次建立不取消前圖」，原完整ASM已包含反證。這是語意與合成模型錯誤；本輪明確列 [errata.json](reuse/errata.json)，保留舊原稿／雜湊，不以舊模型PASS繼續支持錯誤結論。

精確後果是：連續兩張hold=-1的Q圖，第二張建立會先取消第一張，之後明確Del取消第二張；兩者的實體回收仍需各自合格manager pass。這不表示共享圖片全掃、同步destructor、建立失敗時復原舊圖，或取得了Lua可查的完成token。[更正模型](reuse/reference_model.py)、[重用報告](reuse/report.md)

## 5. 模型交接不能只看預載層：追加到doll引用與回載

Start(B)在正式B callback之前，已先做level3／replace=1的模型工作；`DeleteAllObject`也會清全Q樹並提交空level3 replace。因此把它放在B callback開頭，確實會影響B剛準備的預載層，不能把它叫作只清A的操作。[Start與DeleteAll原件](reuse/report.md)

繼續追完整資源使用者後，結論更精確：**level3不是模型唯一的引用。** CDoll工作對同catalog resource在 `79EB03`加`+5C`引用，materialize在 `79F045`呼 `7C5BE0`；後者在引用非0、resident旗標未設時回載。doll析構／替換有對應release路徑。已載好且未釋放的doll可保護資源；dirty／pending的後續工作也有回載途徑。[追加CDoll研究](reuse-followup/report.md)

所以不能從「Start清level3」直接推出保留actor必定失去模型，也不能從「CreateObject看到+54非NULL而跳過541610」推出完全無法reload。這條補證同時縮小了先前初步風險，讓後續規劃集中在真正剩下的失敗state、queue／callback生命期、render gate與實際資源完整度。函式等待一個模型層job，不等於所有doll／apply／release工作全部drain；全owner回收仍不能用一次返回作ACK。

兩段內容仍要明確選同run多phase或兩次Start；camera／圖片／Q樹／map備份及Server run依各自owner安排。A持有全Q樹時，在A仍有合法callback的時機做必要收尾，再End、再允許B，是容易審查的設計政策；它不是唯一原生執行方式，也不是已證的交易式安全handoff。[重用契約](reuse/reuse-contracts.json)

## 6. 資源全面盤點與新增原始資料

原Event、Table、BoundMap三個STP完整index均已核對；Event有7,382 members，其中5,535 camera、1,840 SEQ。1,837個文字SEQ以Lua詞法掃描排除註解、字串範例及namespaced假命中，得到6,080個literal camera呼叫、5,403個unique path；三個compiled SEQ與動態表達式另保留範圍。[carrier inventory](resources/carrier-inventory.json)、[camera audit](resources/camera-audit.json)

43次camera exact-path miss中，1個為大小寫候選；37次所在SEQ沒有同名SceneList funcName，只有6次具exact selector。因此這是「在現有carrier中找不到精確路徑」及可選性風險清單，不能寫成43次實機播放失敗。沒有解析／開檔實測，casefold候選也不直接算成功。XML空白、tag大小寫或重複framepos的結構觀察同樣不自動等於native拒絕。

Q119/3的選定依賴已拆到模型、動作、對話、camera、field／BND與音效；Q2440/5只補一個原DDS圖片依賴，不代表該場景全部資源均已審計。Base補充包的完整索引有830個 `Mon/*.abf` 成員，本輪定向解析 `Mon/02_Stoncken.abf`，取得選定的六個動作descriptor；先前ZIP亦補MapFlow／Cluster的原資料上下文。[資源主文](resources/report.md)

追加原生選取分析已解除PRE疑問：`540B10`註冊模型時以ID建key，這條鏈的PRE解析結果不參與key；同ID的FILE按原生覆寫規則處理。model1086的三列均指`02_Stoncken`，不是由world cluster PRE1選出其中一個Q變體。之後用`FILE + .abf`查`CHA_ABF`索引；無快取fallback使用`Character/`與`*.abf`建立索引，`fcs.flu`快取分支可提供目錄。因此已證的`Mon/02_Stoncken.abf`原member仍不能逕稱實際runtime全路徑；需要目標安裝的cache／mount映射。[模型選取補證](resource-selection/report.md)

這讓「沒有descriptor」的一部分缺口被解除，但GB3／動作payload／DDS／WAV等實體資源、角色portrait與特定path變換仍不可混為已齊全。原資料列名與實際可載入／render結果分開；資源工具刻意維持 `ready=false`，不是分析失敗。沒有將原carrier或完整member上Git。

## 7. Server需求與完整方向

主線已有多種外部關卡、波次／旗標、NPC／市場與遊玩記錄，本輪按當前 `REQ-0019`／`REQ-0021`接續，沒有聲稱從零實作。新增交接重點是：內容版本＋ABI／依賴預驗、typed identity、權威事件與業務結果、owner收尾／兩段交接、缺少ACK時的狀態語意，以及各功能族的正常旅程驗收。[SERVER-HANDOFF](SERVER-HANDOFF.md)、[主線功能追蹤](../../governance/MEF-FUNCTIONAL-COMPLETION.md)

建議先把本輪共用契約接到已有內容管線，綁定真實資源及selector，完成一段可恢復操作的有限內容；同時保持Server戰鬥與業務權威。再逐族完成相機、音訊、對話／書本／教學、NPC服務、點位與場景返回，最後組合多段／重用。不中斷B入口與world→Lua事件是獨立Client研究線；官方MEF格式相容另外追，不能成為所有功能開發的前置。[完整規劃](ANALYSIS-PLAN.md)

## 8. 驗證及不升格界線

本包原件驗證器核SHA、PE mapping、指令邊界、call／欄位錨點、表格／member摘要及固定Git blob；ABI與事件集合另做交叉核對。工具反例、資源lexer與生命期模型均明標SYN。各分題讀集可能重疊，不能把byte／函式數相加當總覆蓋。[VALIDATION](VALIDATION.md)、[整包實跑結果](verification-result.json)

另發現歷史full-surface總verifier所pin的parser SHA，與該基準Git實存parser不符。本輪審讀實存版本，pin正確 `8eb16bbc…`後重新讀原Event；沒有宣稱舊總包在本輪重驗PASS，也沒有修改舊檔掩蓋差異。[重用報告§9](reuse/report.md)

所有原件唯讀。沒有遊戲／Lua／Server執行、Client修改、正式RR接受或T01 FULL-PASS提升。整體功能與實際可玩仍按上述四類缺口接續，完整證據及工具留在本包供下一輪直接復用。
