# MEF 重新啟動與Server內容層：2026-11-07

## 排程與授權

使用者要求「請先繼續.mef的分析/規劃/開發」，本次優先回到MEF，優先於2026-11-04等Server60%後再做的暫緩規則。root與兩庫AGENTS已記錄新排程；原來Client／原件唯讀及不執行／附加限制維持。技能人測回饋另行接續，沒有因此中止MEF。

## 原生補證：縮小舊疑點

[原生報告](../client-variants/20261107-mef-resume/native/README.md)保存26項來源SHA與原BIN窗口，舊三窗口重新逐byte一致：4F3D80是容器建構及固定tableloader入口，4F4960呼叫10項固定表載入。4DF510在4F7DF0查TRIGGER字串後，初始化／已初始化兩分支都沒有保存、解參照或傳入該返回字串，4DF5B9覆寫EAX。已檢4B24F0呼叫者只傳packet+2 mapID，沒有傳檔內容buffer。

這關閉的是「先前初始化helper可能消費回傳MEF檔名」的精確疑點；其他虛擬呼叫、helper下游、別名、模組與網路handler未窮盡，不能說整個Client無MEF支援。沒有新接收opcode、magic、格式、分片、壓縮或事件parser證據。loading顯示已通過仍不等於下載MEF。

## 資源追加核對：先比身份再讀索引

[資源報告](../client-variants/20261107-mef-resume/resources/README.md)在original／working／TC三個授權遊戲目錄核對140個載體實例：139與舊索引SHA相同而沿用既有負查；只有原件Table.stp相對舊MEF索引身份不同，僅重讀該STPI，_MapList payload仍與舊KR一致。指定5個TRIGGER引用與Map182/188/190/191/192仍存在，但其精確／忽略大小寫member均0，三目錄鬆散*.mef亦0。74筆既有town EMF參照及其載體同hash，屬另一圖形資源域，不當MEF。

沒有把這個範圍的未命中擴大成全Client／全版本／改名或內嵌資料不存在，也沒有重做一週全掃或把新原始member上傳Git。

## 本輪已實作：Server自訂內容，不是原生MEF

私有main實作提交84ae6ad（完整SHA與建置收據待部署段補），新增：

1. 不可變ScenarioDefinition catalog與外部JSON＋SHA載入，schema明示LOCAL_SCENARIO_DEFINITION_V1_NOT_NATIVE_MEF、nativeMef=false；原生MEF capability仍unsupported，不建立偽reader。
2. 每instance獨立事件狀態：Entry→SpawnGroup，正常勝利提交後GroupCleared→UnlockPortal，站在出口按Z→NextNode／Result。未知事件不跳過；不直接執行Lua或任意腳本。
3. 將Map191／192出生、怪物群、出口位置／key／Server半徑、下一node／結果從World固定陣列／分支搬入Scenario JSON。勝利／主線保存仍由domain核准；目前adapter只准入其已知兩個domain節點，不能借共用reader擴張到未知任務。
4. MonsterBehavior JSON提供HP、移動／native速度候選、進場緩衝、攻擊與命中距離、追逐停距、傷害、群體／個體節奏、起手／收尾、出招／死亡動作與移除延遲。保留v31既有數值，不假裝回復官方AI。
5. Host可使用絕對外部檔案與exactSHA，health公布內容來源、hash與原生reader未支援狀態。Client仍收既有地圖／物件／移動／動作／命中／出口訊息，沒有發送MEF blob或新傳檔opcode。

原固定兩圖座標／四怪數及portal內容保留。玩家技能、連段、輸入、資源回復、帳號／主線權威仍是共用Server規則；不是為了搬檔案就全部塞進MEF。教學固定出生／遭遇及之後主線的自動佈點仍待搬，不能把本輪算全內容完成。

## 驗證

77項HappyPath先通過；另有一個112ms合法外部定義的World整合案例：替換出生點、只生1隻指定怪、使用出口key71，清怪不換圖、按Z才送Map192，證實不是表面包一層但仍用舊陣列。最終整批78通過59秒、0失敗／略過；AI profile變更HP／動作／傷害／時點亦有正向案例，既有完整TCP教學／主線與v31技能操控均保留。

正式JSON Schema檔已提供，typed C# loader與有限事件圖有驗證；沒有額外安裝jsonschema套件，也沒有聲稱完整Schema合規工具驗收。malformed、未知格式／opcode、重送重入、併發故障安全壓測維持待測。合成測試不是原件Client／官方MEF驗收。

Default Scenario SHA25624fa27e5352cc0d8de47e970f3b6923ff6137fd230cbcb522fb4479017442d20；AI profile SHAd530c7715c61051ceb2655a93775f8ed17c9e6ee13b1bbac0a1d0c1770d0061f。兩份embedded檔指定LF以保持跨平台hash。Scenario中的舊Bridge sourcehash12a800b33b8a0d6e5d60ccc154bf4f8d5753c7d2bc8beeb3f09722af299b83ae指遷移前來源，不是新adapter hash。

## 之後順序與原生完成門檻

- 先把場景定義→instance事件→封包adapter這條路穩定，逐圖補來源／人測；再移其他遭遇、波次、NPC／互動、每種怪物的AI設定。後續關卡仍逐圖確認出生安全距離／通道底大型出口等細節。
- 下一層擴充僅增加明確typed條件／動作與behavior策略；仇恨、回位、定點植物、投射物、召喚與多階段技能不能由一個近戰追逐profile冒充。
- 原生MEF仍是獨立阻塞：需要真實sample＋載體／member SHA、producer／consumer、版本與section／長度／壓縮／指令／引用語意後，才做NativeMefReader→有來源的IR→Runtime。到時為native-derived資料另建明確authority，不能把現行Server JSON標成native。
- Client回傳／執行MEF要另外閉合opcode／framing／傳輸／parser→事件鏈；目前沒有這個契約，不虛構。

只有已證原生MEF及其引用能驅動至少一個正常關卡、對應硬編碼移除且有真人收據，才可標「原生MEF完成」。本輪完成的是Server內容層的先期工程與舊原生疑點收斂。

## 實際啟用收據

v32實作提交完整SHA84ae6ad11bf1ddf74ef830a84aae0b5f3a6d77e3；v32只建置、不打斷既有技能測試。合併回饋後以v33一次啟用，見[v33部署](S00-20261107-V33-HELD-V-ANIMATION-AND-V7-TOOLTIPS.md)。health實際確認Scenario SHA24fa27…d20、AI SHAd530c7…061f，兩者來源PINNED_EXTERNAL_SERVER_JSON；native reader維持unsupported。此為Server自訂內容層啟用，不算原生MEF完成。
