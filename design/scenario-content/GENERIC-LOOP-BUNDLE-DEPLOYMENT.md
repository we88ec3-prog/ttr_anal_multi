# 已知一般副本的成對配套獨立部署

2026-11-22；SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。
分析基準6f9bb0b4182e049514421315d4ded3ed9844ce9e，Server基準483a983386d5bf3e49f9e9673e8a474b1424c30a。
沿用[泛用循環來源](GENERIC-HUNTING-LOOPS.md)的候選／原BND與固定AI，不更動內容格式或原件。

管理端下載的ZIP應解壓到新的版本目錄，保持三個檔案在同一層：版本manifest、scenario、monster-behavior。
接受的入口是manifest的絕對路徑與SHA256；不執行ZIP內腳本或任意環境設定。
部署前依固定catalog 25bd7b21選擇695或699來源profile，再檢查profile identity、版本、成對檔名／SHA、
合法編輯範圍、metadata及原BND；來源仍是repo中固定的候選，內容載體可在repo外的任意新解壓目錄。
舊693 prefix／branch／sequential匯入入口保持。

啟動器新增 `-HuntingLoopBundleCase 695` 或 `699`，與既有 `-ScenarioBundleManifest`、
`-ScenarioBundleManifestSha256` 一起使用。它不選用693候選開關，而是採所選Case的實際slot、
成對AI及explicit loop mode。699自動啟用既有Alsmeer hunting slots。
與整批 `-HuntingLoopProfilesManifest` 互斥；Host health按該配套實際min/max、completion、來源SHA驗證。
receipt另含 `huntingLoopBundle`，可追溯解析後的實際路徑／版本與settings；不以health成功當成通關。

隔離驗收例（以預先建好的測試DB副本及已建置Release執行）：

```powershell
./tools/start-phindos-acceptance-host.ps1 `
  -Workspace E:/Tartaros/workspace `
  -AnalysisDirectory E:/Tartaros/workspace/s00-runtime-dev `
  -BoundsDirectory E:/Tartaros/workspace/outputs/all-early-hunting-bounds `
  -Database <測試DB副本絕對路徑> -LogDirectory <新的輸出目錄> `
  -HuntingLoopBundleCase 695 `
  -ScenarioBundleManifest <解壓後manifest絕對路徑> `
  -ScenarioBundleManifestSha256 <manifest的SHA256> `
  -PreflightOnly -IsolatedPorts
```

預設preflight結束即停止自己的Host。自動wire driver才明確加KeepIsolatedHost並在finally核對PID／DLL路徑後停止。
獨立Host使用15082/18414/18415/18416，只綁loopback；不取代現用服務／使用者DB。
原始Client僅核對固定SHA，不執行、附加、輸入或抓包。

`--export-hunting-host-route-terrain <case> ...` 使用指定已知Case的normal adapter與原BND匯出靜態規劃資料；
不是另一個遊戲世界。wire driver由真實Host的chart／actor／掉落事件前進，保持真實時間、普通方向與攻擊輸入、
Space拾取、原有機關／出口封包；不直接呼叫遊戲Handle／Poll，不注入死亡、旗標、位置或EXP。
EXP、袋中物品、逐訪問扣款及保存只從隔離DB唯讀核對。
Space沒有指定entity ID；檢查器選最近物件、等待最多兩秒的正常排程事件，依實際移除的drop記帳，
再核對庫存守恆。這是檢查器修正，沒有修改拾取規則、半徑、掉落、Server排程或內容。
結算檢查依完整累積入帳鏈、最後一筆completion金額與唯一credit run ID，並核對所有來源戰鬥獎勵之總和。
不能用相同EXP金額的筆數當結算次數：Case699有一筆正常擊倒批次也等於24EXP。

Town1準備既有tutorial/Q15與role4 Lv15；Town2另依固定story14773c31準備到Q132的十個主線前置，
才從廣場正常建隊、進Town2、選Stage465。這是prepared-account正常流程，不是自然新帳號完成主線。
回村核對實際Town1/map182或Town2/map183與同一room，不再固定Town1。

本批以同一管理端匯出的r1四輪版本，分別驗證不使用可選機關的袋中停止，以及每輪使用機關的四輪上限。
695是4房／輪與外部首尾兩房；699是5房／輪與外部頭目一房。
預期695早停10訪問104EXP／上限18訪問160EXP，699早停11訪問224EXP／上限21訪問400EXP。
全部保留原互斥分支，逐輪交替選擇，沒有用四輪展開副本替代動態loop。

實際結果與雜湊見配套的 `generic-loop-deployment-validation.json`；失敗開發嘗試另外記錄，不混入通過。
本批沒有新原生MEF載入證據；人類指定v2實機、自然新帳號、RAID／Story loop adapter、巢狀／跨body及AI CPU移轉仍OPEN。

驗證收據SHA256 `555cdfe804b2e99b40227acd0510a5c695107e18029b00d700f08cb6b30f4347`；最後TRX SHA256 `f59c42e6499565415aecf99a43061de1ef26c9bd4738840b2e0521471476a63a`。
兩個Release（Host／檢查器）零警告／錯誤，726/726 HappyPath、零略過。四條terminal收據經獨立audit核對，隔離連接埠均不存在。
