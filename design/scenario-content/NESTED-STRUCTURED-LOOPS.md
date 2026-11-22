# 巢狀循環：區段執行身分、旗標與獎勵界限

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。分析基準
`4c9361c267085927560fbd3e2b2f54e4f1b9ba61`，Server基準
`13dd3f182c708e8dafba06660833e3a15cb1e63e`。
接續[互不重疊的雙區段](SEQUENTIAL-STRUCTURED-LOOPS.md)與
[RAID循環](RAID-STRUCTURED-LOOPS.md)。原件／舊候選保留；不增加原生MEF格式或opcode。

## 執行契約

沿用 `LOCAL_SCENARIO_DEFINITION_V1_NOT_NATIVE_MEF` 的 `structuredLoops`：
各body必須不相交或嚴格包含；禁止部分交疊、相等body、共用header或共用latch。
原始出口圖仍須DAG，區段只有一個原始latch出口，body內所有路徑先達latch，外部只從header進入。
虛擬回邊的循環強連通分量必須等於一個完整宣告body；巢狀時為最外層body。
最多4區段、每區段16房／16輪，完整分析仍受4096狀態限制。不是放寬成任意有向循環。

每次進入外層header，該層輪次加一、其所有後代計數歸零。到達內層header才開始新一次內層執行，
內層回跳只增加自己的輪次，保留祖先輪次。每個正常Enter仍建立新的visit GUID／序號。
`LoopEntries`觀測保存run／source／visit／loop、Invocation、Iteration及被重置的後代計數；
fork與完成摘要保留紀錄。Invocation是同一場內該區段的第幾次執行，不能當成新run或新的結算。
這是記憶體中的同場執行與觀測，不宣稱重登後恢復副本。

既有每輪reset scope與retain政策保持。retain代表區段自己的每輪入口不清除該旗標，
不是跨所有祖先的永久免清除：祖先入口可依已宣告的另一scope清掉內層停止旗標。
祖先header在內層body之外，因此不違反內層body不得重置自己保留旗標的限制。
外層停止旗標仍由外層保留，不能被其子區段scope清除。來源驗證依舊要求所有body producer明列reset或retain。

靜態分析由單一輪次改為最多4個活動區段的計數向量；離開區段清除其分析計數、進入header起算，
內層保留祖先向量、外層回跳清除後代向量。只展開分析狀態，不展開內容node／chart或新增地圖別名。
旗標可達性、AI條件、每訪經驗及整場一次結算均在同一有限分析圖重算。
不同提前停止路線的下限仍是保守界限，不宣稱任意旗標在第一輪必定可達成。

## Case693正常內容

[獨立候選](phindos-stage462-case693-nested-loops.scenario.json) SHA256
`990ce3d439b90c13bbe511a549b6d959ac6a100f06396893a25540dbb8b0015c`。
使用原Case693七個節點與兩分支、原BND、最小整合版波次／頭目階段及預設AI
`fcd7437c891d6ceff3b7584831eb931ab8fe522156cb3cae69def5324cd38701`。

- 外層：header10、latch4，body10/1/3/5/6/4，最多2輪，原出口接頭目node2。
- 內層：header/latch皆1，單房最多3輪，原出口接node3；該房原定時／依序增援每訪重啟。
- node10每輪拾取183並正常操作11消耗一個，外層重跑必須重新付款；ledger沿用V2 visit身分。
- node1新增清怪旗標，出口要求當前清怪與本輪付款；可正常操作51設內層停止旗標。
- node3每輪重做31後走原分支，node4可正常操作61設外層停止旗標。
- 外層scope清除entry-paid／branch-switch／inner-cleared／inner-stop；內層scope只清inner-cleared。
- 原頭目護衛、75%血量增援、全清與延遲門檻保持，最後20EXP只結算一次。

| 正常操作 | 外層實際輪數 | 每次內層輪數 | 房間訪問 | 總EXP |
|---|---|---|---|---|
| 不操作51／61，兩層達上限 | 2 | 3 | 15 | 188 |
| 操作51，不操作61 | 2 | 1 | 11 | 124 |
| 不操作51，操作61 | 1 | 3 | 8 | 120 |
| 操作51與61 | 1 | 1 | 6 | 88 |

都是正常遊戲互動選擇，不注入輪次、停止布林或debug旗標。這批角色4Lv15、教學／Q15與初始39000EXP是準備前置，
不是自然新帳號升級。保留HP／資源／背包，每訪按原生怪/出口adapter，通關後保存並返回原村同隊。
TCP兩輪外層依正常出口3→6切換原分支，並核對第二輪內層Invocation2由Iteration1起算。

## 工作台與保存配套

管理端新來源key `case-693-nested-loops`，環境前綴 `TARTAROS_ADMIN_STRUCTURED_NESTED_LOOP`
搭配 `_SCENARIO_PATH`／`_SCENARIO_SHA256`／`_BEHAVIOR_PATH`／`_BEHAVIOR_SHA256` 及既有原BND目錄。
profile由來源／AI／BND固定；可改兩層上限、各自停用及原有允許欄位，不可藉此更改body邊界。
來源形狀增加可選NestedEntries，外層不再用基礎房數直接乘輪數假裝涵蓋內層。
完整預覽同時計算兩層：原2×3最多15訪／188EXP，另存3×2為19訪／208EXP，兩層停用為6訪／88EXP。
保存r2後歷史r1 ZIP保持；r3停用仍用同一profile讀取，原manifest/scenario/AI三檔及SHA契約保持。
不自動發布遊戲資源或換現用服務。

啟動器新增 `-IncludeNestedLoops`（固定來源），或 `-ScenarioBundleProfile nested` 搭配保存manifest絕對路徑與SHA，
先經共用reader核對來源、版本、配對AI、原BND、loop metadata與EXP界限再啟動。
維持既有明確 `LOCAL_STRUCTURED_LOOPS_V1_NOT_NATIVE_MEF` 模式。
正常Host測試工具用 `--scenario-interaction-keys`選正常機關操作，入口必需的11仍搭配`--offering`。
內部計數不由driver提供，driver只用回覆chart與正常輸入核對路線。

## 驗證範圍與待驗

來源四條原版BND正常登入／廣場建隊／進村／選關／戰鬥／機關／結算／回村TCP已分層留存。
三層21訪／四次最內層執行屬領域正流程；不能提升為三層原BND或Client通過。
工作台HTTP三版與reader、瀏覽器未保存外4×內2預覽25訪／260EXP，與實際通關的保存r2分開記錄。
實際保存版獨立Host結果、當版原平坦雙循環／RAID控制與HappyPath見最終收據。

GAME_RUNTIME_OBSERVATION：本輪沒有新的指定v2畫面。NL-01待正常建隊進村，觀察內層回跳、波次重生、
外層回跳後再付入口成本及內層重新起算，正常停止51／61，最後只結算一次並回原村同隊。
原圖/鏡頭、機關可見與操作仍待人工；不執行／附加／修改Client。原生MEF／自主AI、自然新帳號完整主線、
Story等其他adapter及既有負面／重登／故障／併發／安全／壓測維持未完成或待測。

## 最終結果

[機器收據](nested-loop-validation.json) SHA256
`33ce55f46556bd2b65f9f682601086e081efbbc95ba666a6013784d8923813e6`。
來源四條TCP為188／124／120／88EXP；實際下載r2四條TCP為208／160／104／88EXP，
均保存回原村同隊。r2的獨立完整Host以真實時間完成19訪／208EXP與6訪／88EXP，
外層入口成本分別3筆／1筆，綁不同visit；SQLite核對Lv15與39208／39088累積經驗、
所有credit合計、最後20EXP一次結算、背包守恆。世界trace的實際map/chart與路線一致，
每場部署Network DLL與最終建置相同。trace不是所有S2C，精確Invocation快照屬同程序只讀診斷。

管理HTTP三版、歷史r1不可變及每版exact reader通過；瀏覽器只讀外4／內2顯示25訪、88～260EXP，
沒有保存或發布此未保存編輯。[預覽畫面](nested-loop-preview.jpg)。
原平坦雙區段四路TCP仍124／160EXP，原RAID1同版提前停止／四輪上限仍一本書、CP與資產保持及回廣場。
Host、Inspector、Admin三個Release零警告／錯誤，738/738 HappyPath、零失敗／略過。
TRX SHA256 `198429d059bab8261aa5890edf74ccf391661380b36b299f5c8c25727355f907`。
自己的Host／Admin均已停止，15082／18414／18415／18416／57934無監聽；未換現用服務或玩家DB。

失敗開發嘗試另存，沒有列通過：首個領域fixture仍保留未驅動的頭目階段門檻、初始工具誤用缺town001的BND目錄、
舊檢查器把整場node1訪次當內層輪次，以及nullable編譯錯誤後仍啟動舊檢查器的外層指令。
修正領域fixture範圍、來源目錄、只讀觀測與型別後，以新目錄完整重驗；沒有放寬正式消耗機關／頭目條件。
