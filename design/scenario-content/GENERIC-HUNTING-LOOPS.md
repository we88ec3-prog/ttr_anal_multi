# 已知一般狩獵場的泛用循環入口與編輯形狀

2026-11-22；SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。
分析基準65b99cb3d、私有Server2aac5d4e。原Case693候選與歷史證據保持。
本批移除正常入口及管理UI對693特定房號的假設，不增加原生MEF格式／傳檔opcode或修改Client。

既有explicit `LOCAL_STRUCTURED_LOOPS_V1_NOT_NATIVE_MEF` mode現在可用於已知15個普通Case：
315、693～706。未設定mode的服務仍不啟用循環；固定alias仍不能混用，RAID／Story仍未開放此adapter。
普通來源圖必須維持其既有DAG、chart/map、分支目標、原BND與SHA；泛用schema的平面body邊界、
SCC、旗標reset/retain、有限狀態／EXP分析仍全部驗證。不是放行任意來源cycle或任意新Case。

Host所有正常狩獵場slot共用此admission。較後村莊原BND讀取分支也會把explicit admission
傳入執行器，修正先前只對693或前段路線有效的限制。15個Case皆有clear-grid領域正流程證據；
只有以下兩個新候選另有完整原BND／正常TCP，不能把其餘13個當成新實機或新BND驗收。

新profile清單 [hunting-loop-workbench-profiles.json](hunting-loop-workbench-profiles.json) SHA256
`25bd7b21064dec81d88c9f59422df74601e49a17231e464e08d8ddc55b07768f`，共用既有AI
`d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。

- [Case695](phindos-stage463-case695-loop.scenario.json)：SHA `679ec65cd66a39f3df7309ef5969f63968e646280770fd5fb6e5b4692ae032e5`，Town1/Stage463。
  普通入口1後，body2/3/4/5/6/7以2為header、7為latch、出到9頭目。
  每輪實際走2→3→5→7或2→4→6→7，四房。控制流基準76EXP，每多一輪28EXP，三輪上界132。
- [Case699](alsmeer-stage465-case699-loop.scenario.json)：SHA `a32a584fbd644444f3ce2fa7f6c68e96f758f64137db50d606ab00686773527f`，Town2/Stage465。
  body1/2/3/4/5/6以1為header、6為latch、出到7頭目。
  每輪實際走1→2→3或4→5→6，五房。基準136EXP，每多一輪88EXP，三輪上界312。

兩個body各有六個成員，但每輪互斥岔路只算一條。原分支怪物每路為兩隻同模型／PRE，
新增每隻183×1掉落；每輪共掉2，袋中達3設保留的停止旗標。可選機關695/key71、699/key61
各消耗183×2，可讓同份內容因袋中仍不足而走到三輪上限。header重置本段清場與可選機關旗標，
最後頭目及既有EXP政策保持；這是自訂成本／條件，不是官方腳本還原。

八條原BND正常TCP：各Case兩種可選機關操作及兩種首選岔路。未操作時兩輪因袋中4離開，
取得104／224EXP；每輪操作時三輪到上限，取得132／312EXP。皆正常登入、廣場建隊、進對應村莊、
選關、逐圖戰鬥／拾取／機關、一次結算存檔及同隊回村。Town2前置主線與角色4/Lv15由隔離fixture準備，
不能算自然新帳號。這些TCP的遊戲邏輯在檢查器程序內，不是另啟Host通關。

管理端的loop profile catalog與普通profile catalog分開，schema為
`LOCAL_HUNTING_LOOP_WORKBENCH_PROFILES_V1_NOT_NATIVE_MEF`，key為 `case-<Case>-loops`。
使用環境變數 `TARTAROS_ADMIN_HUNTING_LOOP_PROFILES_PATH/SHA256`、
`TARTAROS_ADMIN_HUNTING_LOOP_SCENARIO_DIRECTORY`、`TARTAROS_ADMIN_HUNTING_LOOP_BEHAVIOR_PATH/SHA256`
及既有BND目錄。清單固定Case/Stage/Town/檔名與SHA，AI另固定SHA。

表單的可編輯body形狀改由固定來源profile產生：ID/header/latch/key、成員、外部目標、
沿原DAG走到latch的最少／最多房間數及停止旗標。這份readonly capability不是遊戲內容或wire；
UI只將合法loop欄位寫回scenario JSON，不把capability欄位混入schema。
因此同一表單可顯示四房／五房、任意已驗header/latch與多區段，不再固定10/1或3/4。
既有693的單／雙區段工作台仍使用相同驗證來源，停用再啟用的body須屬原profile。

HTTP已驗兩村profile、唯讀四輪預覽、版本保存與相同ZIP下載。四輪上界為695的160與699的400，
manifest／scenario／AI成對保留。配套讀取器也已按workbench所選Case解析實際部署slot，
分別是695 alternate與699 hunting-ground slot，不把路徑寫回693 slot。
這個reader核對版本／profile／檔名、SHA、原BND與metadata，不執行配套腳本。

啟動器可使用 `-HuntingLoopProfilesManifest <catalog> -HuntingLoopProfilesSha256 <sha>`
覆蓋已明確啟用的normal hunting slots；例如本清單另指定 `-IncludeAlsmeerHuntingGround`。
它先以固定AI／BND驗profile、以各Case settings裝載，再按實際min/max與來源檔驗Host。
這批完整隔離Host確認695的76/132、699的136/312及其他已配置Case原來源後停止。
此catalog覆蓋使用repo content目錄；任意解壓目錄的generic ZIP直接匯入啟動器尚待接續。

`GAME_RUNTIME_OBSERVATION`：新Case的獨立Host遊戲通關、自然新帳號、指定v2、RAID／Story adapter、
巢狀／跨body、原生MEF載入及AI CPU移轉仍OPEN。既有693完整Host通關證據不移作695/699驗收。
現用服務、使用者DB、原始Client／資源未改；停權、重送、重登續關、故障、安全與壓測仍待測。

開發初稿門檻誤按單隻掉落配置，依原兩隻怪的實際掉落修正為門檻3、可選成本2；
未付費路線的ledger表尚未因首次扣款建立時，檢查器改記零筆而不查不存在表，預期付費筆數仍逐路核對。
重構漏掉UI profile變數的圖面載入問題也已修正，實際瀏覽器確認原BND圖面與四輪400EXP預覽。
失敗嘗試不列通過，沒有放寬Host規則或修改Client來處理。

實際下載的四輪版本另有兩條原BND正常TCP，分別160與400EXP存檔回村。
最後三個Release建置零警告／錯誤、726/726 HappyPath通過、零略過；UI修復後另重建Admin並實際驗圖面／預覽。
[驗證收據](generic-hunting-loops-validation.json)保留10條TCP、Host設定與各層證據限制；沒有把Host設定當成新Case完整Host遊戲通關。

TRX SHA256 `3e3cfee545288de0c65b571bb018c969da078660e69287493ad750914ce7c606`。
