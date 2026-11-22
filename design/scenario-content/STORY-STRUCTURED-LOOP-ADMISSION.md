# 主線循環接入：敘事、保存與設定預檢

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。分析基準
`74b4119ce870d6ef8cddb71a79893362f95465ad`，Server基準
`1cc6edd7575cb16e88db7caec3e55e70cf7e8c55`。
接續[共用巢狀循環](NESTED-STRUCTURED-LOOPS.md)。本批是主線adapter接入與保存核心，
**尚未完成主線循環的正常TCP／獨立Host通關或管理端配套交付**；不能沿用狩獵場結果替代。

## 接入契約

既有主線對structuredLoops一律拒絕。新增明確
`TARTAROS_LOCAL_STORY_STRUCTURED_LOOPS_MODE=LOCAL_STRUCTURED_LOOPS_V1_NOT_NATIVE_MEF`
才允許主線外部關卡帶循環，省略時保持原拒絕規則。與一般狩獵場循環模式分開設定。
所有帶循環的主線定義必須 `preserveOwnerAcrossNodes=true`，避免換訪時重新補滿玩家資源。
原任務順序、NPC、節點數／編號、各圖及初始模型順序與主線SHA綁定仍保持。
不新增原生MEF格式、Client腳本入口或傳檔opcode。

共用執行器負責回邊、visit／Invocation／Iteration、旗標重置、有限圖與獎勵分析；
主線敘事仍按實際node索引選原EnterScenes／ClearScenes，返回原node會再次走其原劇情序列。
QuestIndex直到真正結束返回劇情才前進，來回node索引不等於重做一次任務。
每個敘事轉換仍先提交SQLite，再發布新游標。未完成副本重登仍依原政策從NPC重來，沒有新增副本恢復功能。

逐訪清場／尚未入帳的擊殺經驗累積於同場；已在戰鬥階段入帳的擊殺經驗不再次加入最終交易。
CompletionExperience只在一次最終完成事件加入，固定任務獎勵沿用原每帳號每任務一次收據。
啟動驗證把循環最大路線擊殺／清場＋一次通關＋固定任務獎勵納入既有int結算範圍檢查。
這不是修改角色曲線或原經驗政策。

一般主線工作台目前沒有主線循環的獎勵／版本metadata與部署契約，因此明確拒絕匯出此種定義，
不把缺少loop metadata的舊ZIP當成有效新配套。此限制只擋循環稿，原主線編排及匯出保持。
後續需獨立可固定來源與經驗政策的工作台profile，再做正常下載配套驗收。

## Q119候選

[獨立候選](story-q119-structured-loop.scenario.json) SHA256
`ca0707961a10914fe25b7f1a3606020f0f1129e19154aa19a2349dfcfaa49089`。
原主線 `14773c3184b201e6a369b753fbf1094972d792c1e2f8e10a4f67587714def50c`，
原經驗政策 `60ca18e680aecec6218f96b5d6d09baf781ff6e81ef7812f9372f4a2d90940ee`。

- 保留node1～4／map632～635、出生與原出口、原初始模型順序及原敘事來源。
- node1清場產生lap-cleared；node2出口要求它，回到node1時重置。
- node1→2最多3輪，接回node3→4結果；最大8次訪問，第一輪正常停止為4次。
- node2停止互動51、視覺標記52，放在原定義已可達出生點。其旗標整場保留。
- 每名原初始敵人配置4EXP，末圖清場10、整場通關20，保持玩家資源延續。
- 預期第一輪52擊殺EXP、三輪92；最終任務交易5850固定＋10清場＋20通關＝5880，
  首次完整增加應為5932／5972。**這是待正常路線核對的內容預期，尚非通關結果。**
- 不自訂新地面掉落，沿用既有主線ground-loot來源；health authoredDropsEnabled應為false。

首次停止點曾放在原出生點附近的未證可達位置，原BND預檢正確拒絕；改用原出生點後通過，沒有放寬碰撞檢查。

## 已驗證範圍

四個正流程fixture以清空測試地形與已授權的隔離SQLite帳號，準備Q119前綴、走原敘事狀態機：
停止／上限各4／8訪，再分擊殺EXP延至結算或已即時入帳兩種流程。
每次敘事轉換均呼叫正式CommitAuthorizedAsync並讀回node索引／revision，
重訪保持同QuestIndex、一次最終ScenarioCompletion、一次任務經驗收據。
即時擊殺信用另用既有CreditMissionExperienceAuthorizedAsync，核對其不在最終交易重複加入，
最後角色累積經驗等於原值＋逐訪信用＋一次固定及場景獎勵。
此fixture不是正常登入／NPC操作、原BND戰鬥或Client證據。

`--story-loop-preflight`核對原版BND、固定主線／外部檔／經驗政策、圖綁定、條件與最大8訪。
啟動器 `-IncludeStoryLoops -PreflightOnly -IsolatedPorts`在DB副本啟動完整Host，
health確認外部檔、合併圖 `ea5a473d55e3a2e8d27a6a42380e2db2c8183146005e47504303734e6e60f480`、
經驗政策、最大8訪與沿用掉落，最後停止自己的PID／DLL。這是HOST_CONFIGURATION_ONLY。
原Q119獎勵候選的預檢預設要求authored drops；本候選沒有自訂掉落，已改為按profile精確比對false，
並另外要求主線循環字典只有Q119且界限8，其他舊profile仍要求true。

## 下一步完成條件（仍OPEN）

1. 準備帳號走正常登入／primary、廣場建隊／進村、原NPC開始Q119；準備前綴與自然新帳號分開。
2. 真正TCP按當前StoryDiagnostic游標動態走4／8訪，逐訪原入場／清場劇情，不能沿用舊foreach固定四圖檢查器。
3. 正常走位／普攻／清怪、停止標記／出口，核對HP／SP／MP／冷卻延續、每訪怪物重建、visit與重置紀錄。
4. 核對戰鬥EXP與一次5880任務交易、完整5932／5972增量、固定獎勵／任務／下一任務及回村。
5. 同版獨立Host真實時間完整路線；再接主線循環專用管理profile／版本預覽／不可變成對ZIP。
6. 指定v2由使用者驗收重播原劇情、回跳／鏡頭、標記操作及結算；不能由合成或預檢填成人測通過。

GAME_RUNTIME_OBSERVATION：本批無新指定v2結果，SL-S01留待上述正常路線準備後再排程。
原生MEF／Client自主AI、自然新帳號全主線及既有重登／重送／故障／安全／併發／壓測仍分開未完成／待測。

## 本批收據

[核心／設定收據](story-loop-admission-validation.json) SHA256
`97291edc59864f7a4af8b032b719d0f99abf300630c640f910d6ae94bdcf9a23`。
Host、Inspector、Admin三個Release建置零警告／錯誤，742/742 HappyPath、零失敗／略過。
四個新增SQLite正流程都在同一完整TRX內，SHA256
`2f763104308d347b88a60d3716e37ebd5345a2717d2c4bf4f98c17a9286bee36`。
隔離Host部署Network DLL與最終建置相同，預檢後未保留Host，來源DB SHA保持；
normalTcp／separateHostRoute／designatedClient／storyLoopWorkbench皆明列false。
這不代表已完成上方六項正常路線及交付驗收，也不代表整體MEF目標完成。
