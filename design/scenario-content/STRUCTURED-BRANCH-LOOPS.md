# 同場重訪不同岔路的循環區段

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。基準Server `4f052b7`，分析庫 `c55593354`。沿用既有SCC／有界狀態、逐訪身分、旗標重置、機關帳本及正式戰鬥／結算，將Case693正常入口的動態循環由前兩房擴充至既有分支區段。沒有修改Client、原BND或加入opcode。

## 內容及admission

[新獨立候選](phindos-stage462-case693-branch-loop.scenario.json) SHA256 `95248af6d1f74c9d6525fd80bd8bf717b832b6243a616dd170d4400ed909c154`，原AI仍為 `d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。舊flag-delay與兩房循環檔保持。

正常入口仍為廣場一人隊→逢德斯村→Stage462／Case693。入口10正常拾取並消耗183×1，第二房1仍有計時／依序增援及原183×1掉落。後續body宣告四個節點 `[3,5,6,4]`：header3、latch4／出口4、原離開目標2。每輪清header3、重新按31及33、等待1.5秒後，選出口3到node5或出口6到node6，再經node4匯合。每輪實際只走三間房，不把兩條互斥岔路都算入EXP或訪問次數。

Node5／6各沿用原怪物／PRE，新增該怪物掉183×1。Node4觀察共用背包達3個183時，設整場保留的branch-supplies-ready；也有可選機關41消耗183×1。latch依實際旗標成立或三輪上限離開，否則回header3。進header3重置本區段開關、聚合、延遲及可選機關旗標，保留先前入口付款entry-paid與停止事實。

- 不操作41：進body前袋中1，兩輪分支拾取後達3，走原頭目房2，單次104EXP。
- 每輪操作41：拾取後消耗1，停止事實未成立，第三輪上限離開，單次120EXP。入口扣款僅一次，node4每個實際visit各扣一次。
- 任一玩法都可在同一場依正常出口意圖交替走5／6；這些是逐訪玩家選擇，不是固定alias展開或傳給runtime的停止輪數。

沿用 `LOCAL_STRUCTURED_LOOPS_V1_NOT_NATIVE_MEF` admission mode，普通來源圖仍DAG、虛擬backedge受明確body／SCC及上限限制。Case693只接受既有10／1前綴，或這個3／5／6／4body；後者header3須保留兩出口、latch4一出口及既有原圖／chart目標，不混入固定alias。其餘Case、巢狀／跨body流程未藉此開放。

## 實作及驗證界線

有界分析已能正確處理body內岔路：本候選共15個分析state，實際最多12個節點訪問，保守路線88～120EXP。每個有效latch保存run／內容／visit／輪次／原因；重返相同header重新啟用互動、flag-delay及戰鬥。資產／EXP仍按實際擊倒與已提交成本累加，最後completion一次。

正常TCP檢查器新增可選 `--scenario-branch-exits`，只安排逐訪正常分支鍵。驗證器逐步比對實際source出口、latch權威旗標及上限；重訪後走不同支線時，與來源DAG路線對照只採該body第一輪，後續每一輪另作完整逐邊核對，不能用「曾見過node」漏掉第二條岔路。

私有 `tools/check-structured-branch-loop.py` 同一內容跑四種正常意圖：3,6／6,3提前離開，以及3,6,3／6,3,6到上限。四路各完成原BND、重啟開關／延遲、分支掉落、逐訪成本、頭目及104／120EXP保存，返回原村同隊。每路14枚投射物建立／清除；兩輪為9個實際訪問，三輪為12個，明確不同於四個body成員的數量。結果見[收據](structured-branch-loop-validation.json)。

啟動器新增 `-IncludeStructuredBranchLoop`，核對兩庫固定SHA、使用原mode並執行來源推導的完整Host設定檢查；加 `-PreflightOnly -IsolatedPorts` 即暫時啟動檢查後停止自身Host。Stage462仍輪替693／694，694保持原樣。

三個Release零警告／錯誤、**700/700 HappyPath**通過。舊兩房循環四路仍保存108／128EXP，隔離Host確認新body與88～120界限、其他三Case仍76EXP後停止。TRX SHA `3e57860b1e00eb76e2d13ab1a735ee2c1588cd72f20e4aecf1cf913d2240be51`由機器收據保留；最初新測試的nullable標註編譯錯誤已修正，未列為通過。

原批次只開放JSON候選及正常入口／Host設定。後續[分支循環工作台](STRUCTURED-BRANCH-LOOP-WORKBENCH.md)已補獨立profile、正確body表單、HTTP版本交付及完整Host配套載入；原批次700項結果保留，最新驗證以工作台收據為準。

`GAME_RUNTIME_OBSERVATION`：準備角色4／Lv15與教學／Q15的loopback TCP，並非指定v2、人類正常升級或另啟部署Host遊戲通關。Client同chart3回跳、岔路圖序／畫面、每輪互動與104／120EXP仍待DL-B01；原生MEF／CPU移轉不因此閉合，非正流程仍待測。
