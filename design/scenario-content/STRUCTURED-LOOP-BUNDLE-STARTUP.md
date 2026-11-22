# 指定版本配套的完整Host啟動

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。接續[循環管理工作台](STRUCTURED-LOOP-WORKBENCH.md)，基準分析庫 `f76548fb4`、Server `9c9789e`。這批補齊從實際下載配套到完整Host啟動的預檢與啟動入口，保留原固定範本選項及所有舊版。沒有修改或執行Client，沒有替換現行服務。

## 配套讀取契約

輸入為解壓後某一份 `.scenario-bundle.json` 的絕對路徑及操作者指定的SHA256，不搜尋最新版本。先固定清單bytes，再讀同目錄的關卡／AI；不執行清單文字或任意環境設定。[靜態schema](local-structured-loop-bundle.schema.json)描述本工作台的canonical輸出；型別讀取器另外完成跨檔及語意驗證，schema檢查本身不能代替預檢。

1. 清單維持 `LOCAL_SCENARIO_AUTHORING_BUNDLE_V1_NOT_NATIVE_MEF`、nativeMef=false、既有Server authority。draft為非空GUID、revision為正Int64；manifest最多64KiB，兩個payload各最多256KiB。
2. 來源profile必須等於用原BND及固定循環範本／AI重新載入後的profile SHA。範本仍為scenario61a0532e、AId4768b72；編輯稿／自訂AI另核對實際SHA。這驗證資料的一致性，不是管理端簽章或回查草稿資料庫。
3. Payload檔名必須恰為 `scenario-{draft:N}-r{revision}.scenario.json` 及同stem的 `.monster-behavior.json`。只能讀清單同目錄的這兩個basename，逐檔核對SHA；不接受由清單擴展任意路徑。
4. 重新走工作台的來源／Case693圖序、AI、條件、循環與原BND驗證，獨立計算最小／最大EXP、completion、最大節點訪次及loop預覽。清單若提供循環／獎勵metadata，必須與重算結果一致；有啟用loop的配套必須保留這兩份metadata。
5. settings只接受原工作台生成的六個鍵及精確值：Case693、關卡路徑／SHA、AI路徑／SHA、明確loop mode。讀取器產生解析後絕對路徑；啟動器只套用這些固定鍵，不匯入其他設定。
6. 關閉循環的保存版本仍保留profile及顯式mode；清單不帶loop／bounds欄位時，由內容重算，回到六個實際節點、88EXP原路線。不能因「沒有loop metadata」就改載固定範本或最新草稿。

私有檢查器新增 `--inspect-loop-bundle <manifest> <manifestSha> <baselineScenario> <baselineSha> <baselineAI> <baselineAISha> <bounds>`。結果為 `BUNDLE_AND_ORIGINAL_BND_CONFIGURATION_ONLY`，包含實際release身分、兩檔SHA／路徑、重算preview及受限settings；不建立遊戲連線、不改帳號資料。

## 啟動與預檢

私有 `tools/start-phindos-acceptance-host.ps1` 新增 `-ScenarioBundleManifest` 及 `-ScenarioBundleManifestSha256`，兩者必須成對。它會自動啟用該Case693來源的明確admission mode，與其他Case693比較候選互斥。未指定這兩項時，所有舊的固定範本選項保持原行為。

```powershell
$releaseManifest = 'E:/Tartaros/workspace/outputs/my-release/scenario-<草稿GUID的N格式>-r2.scenario-bundle.json'
$releaseSha = (Get-FileHash -LiteralPath $releaseManifest -Algorithm SHA256).Hash
& E:/Tartaros/workspace/server-runtime-dev/tools/start-phindos-acceptance-host.ps1 `
  -Workspace E:/Tartaros/workspace `
  -AnalysisDirectory E:/Tartaros/workspace/s00-runtime-dev `
  -BoundsDirectory E:/Tartaros/workspace/outputs/fresh-early-raid-story-bounds `
  -Database <已初始化的獨立測試資料庫> `
  -LogDirectory <新的預檢日誌目錄> `
  -ScenarioBundleManifest $releaseManifest `
  -ScenarioBundleManifestSha256 $releaseSha `
  -PreflightOnly -IsolatedPorts
```

先建置Host及LocalTutorialInspect Release。預檢使用15082／18414／18415／18416 loopback埠；任一已占用就不啟動。清單讀取失敗時不啟動Host。通過後用新部署副本啟動真正Host，從health核對關卡、配對AI、循環開關、EXP界限、completion、增援、掉落及最終出口；其餘694～696及輪替身分也需保持。匯出版本的內容以該來源推導核對，舊固定範本仍保留原特定場景檢查。

預檢完成會關閉並等待自身Host結束，receipt帶scenarioBundle的指定draft／revision／manifest SHA及實際載入資訊。這是完整程序的設定啟動驗證，不是該部署Host已由遊戲Client通關。

要保留這個Host供之後使用者測試，使用另一個新日誌目錄，省略 `-PreflightOnly -IsolatedPorts`，會使用既有5082／8414／8415／8416埠；先核對原測試Host的PID／路徑及埠，按既有換版流程處理。工具不會自動停止其他服務，也不會操作Client。三個解壓檔可放在獨立版本目錄，預檢與啟動均由指定清單定位，不需產生Table.stp或改遊戲資源。

## 本輪正流程

[機器收據](structured-loop-bundle-startup-validation.json)保存實際配套與完整Host預檢資料。原管理端三輪r1、四輪r2、瀏覽器改名的四輪配套都已啟動成功，實際關卡／AI SHA一致，界限分別88～128、88～148、88～148。新增管理端保存r3關閉循環，實際下載後Host回報88～88、loop=false，正常TCP亦一次88EXP回原村同隊；啟用版本四路仍保存108／128／108／148EXP。原固定整合版亦保持88EXP啟動控制，其餘三個Case每次仍76EXP。

配套讀取正流程另涵蓋實際ZIP解壓、指定r2、三／四輪及關閉狀態，確認解析設定與指定資料一致且不改清單。所有隔離Host／Admin均停止，來源測試資料庫只讀複製；沒有換現行服務或Client。非法清單、篡改、重送／重連、併發、故障、安全與壓測維持待測，不因本批成功便宣稱這些類別通過。

三個Release建置零警告／零錯誤，**699/699 HappyPath**通過，零失敗／略過。TRX SHA `b49e74ebb354152ca53ccacd2bfebdc35678502e1ae7fda3a9248b4960b4c747`。五次Host預檢的實際部署Network DLL與本輪建置一致；四個匯出版本加舊整合控制的逐筆SHA均保留。靜態schema已解析、核對兩庫bytes及檔名pattern；未宣稱跑過外部JSON Schema引擎的完整驗證。

原生MEF容器／解析／傳檔、Client自主生怪與完整AI移轉、指定v2實機、自然新帳號與另啟部署Host的遊戲通關仍各自未閉合。其他adapter、巢狀／跨body循環及更廣MEF功能保持進行。
