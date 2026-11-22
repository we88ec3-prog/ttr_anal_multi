# RAID 獨立Host部署與真實時間通關

2026-11-22；SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。
分析基準32a70624f7cf481b86daba9b735a2f0be93edb4a，Server基準c3e22ae821b64eabb391f974712a84f195f24f1c。
接續[同程序TCP](RAID-NORMAL-TCP-ROUTES.md)，這批使用獨立Release Host、不同driver PID與真實時間。
不執行／附加／操作Client，不取代現用Host或玩家DB。

啟動器增加 `-IncludeEarlyRaids` 及 `-RaidBoundsDirectory`，載入三個既有固定來源與15張原BND，
並啟用原有RoTrua經驗曲線與普通裝備／HP卷軸模式，不啟用其他狩獵場或主線成長。
修正的是RAID成長的啟用條件；使用已保存等級與既有HP／攻防公式，不另調怪物／AI、拾取或獎勵。
`-RaidBundleId <1..3> -RaidBundleManifest <絕對路徑> -RaidBundleManifestSha256 <SHA>`
會先經共用配套reader核對固定RAID來源profile、版本、檔名／SHA、BND與完整settings，再覆蓋該RAID及配對AI。
另外兩個RAID仍是原固定來源，但同樣使用該次共用AI。與狩獵配套匯入互斥，不執行包內腳本。

Host health新增 `localChallengeRoutes`，每個已載入RAID公開raid／Stage／Case、來源／AI SHA、
最低等級、入口node及實際node/map順序。預檢核對三關、各五圖、7／12／17等級與當版來源；
receipt保存 `raidRoutes` 與選用的 `raidBundle`。這些是設定證據，須另有正常遊玩才能算通關。

角色4、Lv17／250000EXP、教學／Q15里程碑、普通2725／11262及20張232先準備於新的SQLite副本。
CP走既有每天刷新為3000。此帳號不是自然新帳號，也沒有宣稱從零完成Q144或練到17級。
進入遊戲後正常登入／primary handoff、角色選擇、廣場、穿戴與快捷綁定、建一人隊、選RAID與開始。
全部遊戲輸入走真實loopback TCP；driver只按正常方向／普攻／卷軸／出口操作，沒有內部world或直接Handle／Poll。
靜態路線規劃只讀固定BND匯出的碰撞資料；AI、命中、生怪、HP／冷卻、勝利與發獎均由Host決定。

共同走位／戰鬥器保留既有一般副本流程，只抽出各adapter的結算處理。
RAID結果依19-byte既有成功回覆核對產品2274／2275／2276；確認後核對正常隊伍清理，再載入廣場。
書必須在廣場0024啟用前經0029／002C可見。DB全程唯讀核對：僅一本已交付、CP與錢包保持、
穿戴實例、角色經驗及故事狀態保持，除所用HP卷軸與獎勵書外其他背包不變。
卷軸由driver在HP低於60%且正常四秒冷卻後操作；逐次核對最大HP30%回復、剩餘數與冷卻。
真實時間、走位與輸入節奏會影響受擊，但本輪也查出下述原成長啟用缺口；不可只把用量差異歸因於時計。
不同配置的HP卷軸用量各自保存，不沿用舊同程序固定用量。

正常成功返回廣場會清理原RAID隊伍；不同於一般狩獵場的同隊回村。這是成功流程，不是主動離隊、敗退或重登測試。
每場最後關閉自己的socket，核對PID及完整部署DLL路徑後只停止該場Host；來源DB前後SHA須不變。
隔離連接埠為15082／18414／18415／18416，只在loopback監聽，整批後核對均不存在。

```powershell
python -B tools/check-deployed-raid-route.py `
 --workspace E:/Tartaros/workspace --analysis-directory E:/Tartaros/workspace/s00-runtime-dev `
 --bounds E:/Tartaros/workspace/outputs/all-early-hunting-bounds `
 --raid-bounds E:/Tartaros/workspace/outputs/early-raid-bounds `
 --seed-db <唯讀來源DB> --output <新的輸出目錄> --raid 1
```

加 `--scenario-bundle <該RAID已解壓manifest>` 測同一份管理端版本；啟動器自行固定其SHA與基準。
指定v2／自然新帳號、RAID動態循環、巢狀／任意新Case與原生MEF／AI移轉仍OPEN。
本批不提高任何Client／native驗收；停權、重送、重登、故障、安全與壓測保持待測。
世界trace僅涵蓋map／chart／資源等世界事件，不是全部S2C；成功回覆與書的發布由實際socket讀取核對，
發獎由SQLite交叉驗證。最終六場皆另核對全局成功frame只有一次；首批歷史收據沒有的欄位不回填。
最終通過範圍、原始收據與gate SHA另列於 `raid-separate-host-validation.json`。

## GAME_RUNTIME_OBSERVATION：RAID成長的隱藏依賴

ID：S00-GAME_RUNTIME_OBSERVATION-RAID-INDEPENDENT-GROWTH-20261122。
檢查先前RAID領域fixture與真實Host的用量差異時，查到 GrowthEnabled 只檢查已配置的普通狩獵場／
Story recommended level，沒有檢查目前啟動的RAID。角色／隊伍可以顯示保存的Lv17，純RAID執行時
卻不會把這個等級送入既有角色HP／攻防公式；先前完整Host因載有一般成長關卡而掩蓋缺口。
這是Server-owned成因，不是Client故障或原生MEF行為；舊版缺口以原碼路徑定位，未另外執行舊版Client或獨立Host的失敗案例。

修正將目前active scenario的RecommendedCombatLevel納入成長啟用判斷；實際角色等級仍取授權保存資料，
不是把RAID最低等級當角色等級。新領域三個正流程只配置RAID與保存Lv17，驗基礎最大／目前HP900。
這三個測試用clear-grid，不能當成原BND證據；完整原BND與獨立Host另跑三基準、三配套。
啟動器的RAID模式也拆除對IncludeCombatGrowth的依賴，原一般副本來源保持非成長版，Story quest growth關閉。
第一批帶其他成長來源的六場Host及舊同程序結果保留為歷史控制，不列成最終獨立成長配置的通過場次。

最終稽核也從停止後保留的部署目錄計算Network DLL SHA，要求六場與最後建置相同；啟動收據已有SHA時另核對吻合。
實際世界資源事件須顯示最大HP900，配合保存Lv17及未啟用其他成長來源，證明此修正已進入獨立Host。

## 最終結果

最終獨立成長配置六場全部通過，三個基準與三份歷史r1配套各五圖，合計30次原BND載入。
每關擊倒16／20／18隻；最大HP均900、最低觀察HP為796～812，每場HP卷軸用量均0。
各一本2274／2275／2276，CP3000與保存Lv17／250000EXP保持，正常隊伍清理返回1088廣場。
六份同程序TCP重驗亦使用成長後能力，50／78／78次有效普攻、卷軸0，既有資產不變。
舊同程序3～4卷軸用量屬未啟用成長的歷史配置，不回填為本版結果。

共用結算抽取後，獨立Host Case695控制仍完成10訪問、一次104EXP保存並同隊回村。
六場保留部署的Network DLL皆與最後建置相同，實際map／chart順序、世界HP事件、發書ledger與背包／角色表均獨立核對。
全域成功結果frame各1、書在0024前可見，所有自己的Host已停止，四個隔離監聽埠均不存在。
三個Release零警告／錯誤，729/729 HappyPath、零略過。這不提高Client／native或自然新帳號完成狀態。

[最終收據](raid-separate-host-validation.json)另列首批混合成長配置的六場歷史控制，不混入最終六場。

收據SHA256 `43bc310a07fd6dd84fdb269fc9e6c11d8aab1adf68aa3405758bc94a7b5cd504`；TRX SHA256 `ee5e1d798a78fad4204240e67e78403e119b2e1c4115b6dbba2e747f58763001`。
