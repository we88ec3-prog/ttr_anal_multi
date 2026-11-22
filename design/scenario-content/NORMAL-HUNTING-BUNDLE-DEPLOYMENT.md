# 普通狩獵場管理配套的獨立部署

2026-11-22，SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。
接續[PATROL-ROUTE-WORKBENCH](PATROL-ROUTE-WORKBENCH.md)的下載版獨立Host缺口。

既有LocalScenarioBundleReader已支援普通配套；新增明確普通狩獵場啟動選項，
不套用循環profile或強制loop mode。來源從固定普通15 Case catalog選定，
驗證來源profile、版本身分、同目錄配對檔名／SHA、重算metadata、精確settings及原BND。
匯入只取reader驗證後的資料設定，不執行配套腳本或任意環境設定。
舊693循環及695／699泛用循環入口保持，不能混用新舊入口或其他比較候選。

正常匯入須開啟該Case原有Stage／town slot，並以該版本實際的min/max EXP、
completion、來源／AI SHA核對health。health成功只代表部署，正常TCP通關仍另驗。
輪替Case保持原選關政策，不因部署單一配套就硬改首次入場選擇。
人測、自然新帳號、原生容器與Client自主AI保持各自範圍。

## 使用方式

管理端下載的完整ZIP解壓到一個新的版本目錄，讓manifest、scenario與AI三檔同層；
保留舊版。啟動器使用 `-HuntingBundleCase`，與舊 `-HuntingLoopBundleCase` 分開。
普通來源catalog SHA為 `2173bc50eebbc16b037cfbdcbb24396299087a1ce6a48b5f59ae8dca5e901a1d`。
其15個已知Case為315、693～706，來源profile與各Case的正常slot設定仍由原workbench推導。

```powershell
./tools/start-phindos-acceptance-host.ps1 `
  -Workspace E:/Tartaros/workspace `
  -AnalysisDirectory E:/Tartaros/workspace/s00-runtime-dev `
  -BoundsDirectory E:/Tartaros/workspace/outputs/fresh-early-raid-story-bounds `
  -Database <已初始化的測試DB副本> -LogDirectory <新的輸出目錄> `
  -HuntingBundleCase 693 `
  -ScenarioBundleManifest <解壓後manifest絕對路徑> `
  -ScenarioBundleManifestSha256 <manifest的SHA256> `
  -PreflightOnly -IsolatedPorts
```

上述預檢用15082／18414／18415／18416，成功後停止自己的Host；只有自動wire driver另加
KeepIsolatedHost，並在finally核對本次PID／DLL路徑後停止。沒有覆寫現用Host／Admin／玩家DB。
啟動收據的 `huntingBundle` 記錄實際版本／路徑／SHA／preview及正規化設定。
需要其他普通Case時，啟動器會開啟它原有的Stage／town slot；輪替Case仍照原入場選擇政策。

檢查器 `--inspect-hunting-bundle <來源catalog> <catalog SHA> <來源目錄> <BND目錄>
<Case> <manifest> <manifest SHA>` 使用相同reader及完整原BND配置驗證，不啟動遊戲。
正常driver可用 `--hunting-bundle-case 693 --scenario-bundle <manifest> --complete-route`。
driver只提供現有prepared-account第一場主Case路線；不是任意輪替Case或自然新帳號驗收。
另加 `--observe-entry-patrol` 可於第一房開始先等待3.2秒，記錄實際0016位置，
期間不送玩家移動或攻擊；沒有巡邏配置時不建立觀察。

## 完整部署驗證

[收據](normal-hunting-bundle-deployment-validation.json) SHA-256
`aeac442eef72d1c1ec175b1acfdf00b8ce29cd669aad8d164d520b3d6f0c1859`。
使用前批瀏覽器實際保存／下載的同一r1／r2／r3，版本／scenario／AI／manifest與歷史bytes均未改。
三次獨立完整Host皆用最終Network SHA
`6dff7201c8cc2360e5399efc13ca5dac8001f9198ec1510a09ae8a03ace87ce4`，
正常登入、廣場建隊、進村選關、六圖戰鬥、單次76EXP入庫、39076累積EXP及原村同隊返回通過。
三版均明確未啟用structured loops，來源profile維持普通catalog；不混稱前批88EXP整合候選。

r1／r2額外在送玩家移動／攻擊前等待3.2秒，記錄真實0016巡邏位置，
逐段以0.05單位內距重核原BND通行格及出生點24範圍；不是Client自主運算證據。
r3無patrol欄位、保留同一AI，不建立巡邏觀察，仍正常通關。
第一場較早使用的部署組件與最終建置不同，舊收據保留；已另以最終組件重驗r1，
本收據只採用同版最終結果，沒有放寬DLL一致性要求。

十五個普通Case正流程測試驗證作者巡邏／AI配套往返、精確payload、正確slot設定、
無loop mode及原獎勵範圍。這15項使用合成地形；新獨立Host遊戲證據僅上述Case693三版，
其他Case／輪替選擇仍需自己的遊戲證據，不能把15項領域測試外推為全部可玩驗收。
舊Case695四輪配套的獨立Host預檢仍能載入160EXP上限；控制組只驗配置，不宣稱本批另跑其遊戲。

Host／Inspector／Admin三Release零警告與錯誤，771／771 HappyPath，失敗／跳過0；
TRX SHA `8682d17346cb31e3400c615d8c83405883c3d04c210a4a6b047d7acae8d916c7`。
各原seed DB保持，隔離Host及監聽已停止，現用服務／玩家DB不變。
指定v2及自然新帳號仍待驗，暫緩的倒地／重送／重登／故障／安全／併發／壓測未執行。
