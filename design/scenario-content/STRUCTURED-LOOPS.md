# 執行中結構化循環

2026-11-22：[分支區段循環](STRUCTURED-BRANCH-LOOPS.md)已加入正常Case693的3／5／6／4body，同一場逐輪可選不同岔路，重啟開關／延遲後保存104／120EXP回村；700 HappyPath通過。原兩房管理端及配套profile仍限前綴，分支工作台待接續；下列早期admission範圍依本補充擴大，不代表其他Case或巢狀流程開放。

2026-11-22：[循環管理工作台](STRUCTURED-LOOP-WORKBENCH.md)已補獨立profile、規則表單、Server預覽、保存／歷史版本與配套下載。實際匯出及瀏覽器保存的五條TCP通過108／128／148EXP，696 HappyPath通過；下方管理端待完成敘述保留為前一批狀態，新匯出版本Host啟動預檢與Client仍分開待驗。

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。基準Server `b68e939`，沿用已發布的訪次、機關帳本V2、旗標重置群組與正式戰鬥／經驗提交。本功能在出口依本場權威旗標決定回到同一logical node；既有固定alias展開仍是獨立功能，兩者不能混稱。

## 定義與範圍

Scenario V1增加可省略的 `structuredLoops`。未填時序列化省略，保留舊來源與編譯配套。每個描述含：

```json
{
  "id": "supply-circuit",
  "entryNode": 10,
  "latchNode": 1,
  "exitKey": 1,
  "maximumIterations": 3,
  "untilFlag": "supplies-ready",
  "resetScope": "prefix-attempt",
  "nodes": [10, 1],
  "retainFlags": ["supplies-ready"]
}
```

一次至少執行一輪。每場最多4個互不重疊的平面body，每body 1～16個既有節點、每loop最多16輪。入口及latch都在body；latch必須有一個既有NextNode出口通往body外，不能同時配置權重或條件選擇。其他body出口只能通向body內；外部只能由header進入，場景入口也不能從body中段開始。header須能到達每個body節點，所有body路線最後都經latch。巢狀／交疊或跨body中段跳轉不在本版範圍，不默默攤平成固定次數。

來源的普通出口仍須形成DAG。循環是獨立描述的虛擬backedge，不改原始圖序／chart／map。加入backedge後逐強連通元件核對：每個循環SCC必須恰好等於一個宣告body；不能直接放行任意來源cycle。

指定resetScope必須位於header。body產生的每個旗標都要列入該群組，或明列retainFlags；停止旗標必須在body有producer且保留為整場事實。body內任何其他入口重置也不能清除保留旗標。header群組可額外清除其他已宣告旗標；既有歷史逆推失效規則仍適用。多輪wave／hold／delay及選擇按現有Enter／換圖生命週期重新建立。

## 執行與分析

正常出口先通過既有清場、旗標、角色存活、距離與通行檢查，再在有效latch讀取目前untilFlag。成立就走原出口；未成立且未達上限就回header；到上限一律走原出口。沒有輪數或停止布林的Client輸入，也沒有新opcode。每次實際Enter仍建立新的visit GUID／全場序號／同node計數；fork只複製目前計數與歷史。

每個有效latch保存不可變決定：run、內容SHA、visit／序號、loop／policy SHA、實際輪次與上限、停止旗標及有無、是否重複、實際NextNode、Continue／UntilFlag／MaximumIterations原因。診斷及最後結果都保留；不把測試預期輪數注入runtime。

可達條件及獎勵改用有上限的分析狀態圖 `(原node, 此body輪次)`。離開body後不攜帶其分析計數，避免多個平面loop產生無意義乘積；上限4096狀態。只有分析狀態展開，實際內容與執行節點不複製。早於上限的離開邊保證untilFlag；上限離開邊不保證它。所有狀態經拓撲處理，旗標於每個header套重置／歷史依賴，再驗證出口、波次與AI來源。摘要按原node交集各訪次的可用旗標。

獎勵逐分析訪次累加，逆拓撲計算保守min/max，防止來源DAG遞迴漏算重訪。這是路線上下界，沒有解任意背包數值／消耗關係，因此min可能低於目前具體玩法能達成的最短輪數。正式擊倒／清組經驗仍取實際戰鬥增量；completion仍每場一次，沒有加上按node去重或每輪重發completion。

## Case693正常入口

[獨立候選](phindos-stage462-case693-structured-loop.scenario.json) SHA256 `61a0532e0908345cbcc87322ae87a5b0cb19d280dcd35e63cf6f36ab173d983a`，沿用AId4768b72全SHA `d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。來源是既有flag-delay版，非原生MEF新證據。

目前正常adapter明確opt-in：`TARTAROS_LOCAL_STRUCTURED_LOOPS_MODE=LOCAL_STRUCTURED_LOOPS_V1_NOT_NATIVE_MEF`，只接受Case693原兩房10／1、header10單出口、latch1／key1及原chart/map；與固定展開mode互斥。其他狩獵場／RAID／Story不借用此adapter。通用領域引擎的平面多loop另由正流程測試證明，不當成這些入口已開放。固定entry／prefix編譯器明確拒絕動態來源。

- Node10每輪正常掉落183×1、機關11消耗183×1；重新入header清除entry-paid及offering-made。
- Node1每輪正常掉落183×2，背包達3設supplies-ready；可選機關41每輪消耗183×2，設offering-made，出口本身不要求這個可選機關。
- 不操作41：第一輪袋中2、第二輪4，當場旗標成立後離開，共兩輪。接原開關／分支／頭目，各保存108EXP。
- 每輪操作41：袋中2再消耗為0，停止旗標未成立；第三輪達上限離開，共三輪。接相同分支／頭目，各保存128EXP。
- 保守路線界限為88～128EXP；兩種正常玩法實測108／128，不把88宣稱成本候選已實測的通關值。

啟動腳本新增 `-IncludeStructuredLoops`，會檢查兩庫配套與mode；隔離預檢使用 `-PreflightOnly -IsolatedPorts`，只驗設定後停止自己。遊戲操作仍由使用者，沒有在本輪替換現行Host／Admin或使用者資料庫。

## 驗收與未完成

私有 `tools/check-structured-loops.py` 用相同SHA、兩種正常機關選擇及兩條後段分支，經真實loopback登入／primary交接／廣場建隊／選關通關回村。逐訪檢查node、chart、原BND、旗標重置、扣款visit／run、掉落與存檔EXP、一次結算、同村同隊及投射物清除。結果見[驗證收據](structured-loops-validation.json)。準備角色4／Lv15及教學／Q15進度保持明示；同程序正式gateway與控制時計不等於另啟部署Host、自然升級或指定v2 Client實機。

四條新路線已通過：兩輪路線每場2筆機關成本、19枚投射物建立／清除、108EXP；三輪路線每場6筆成本（總9個183）、24枚投射物建立／清除、128EXP。每個扣款visit、latch決定及header重置都對齊實際同node訪次。兩條舊prefix128EXP及兩條舊reset88EXP控制也通過，六個舊編譯配套bytes不變。隔離Host載入新SHA／mode及88～128界限後停止；三個Release零警告／錯誤，**694/694 HappyPath**通過。TRX SHA `a7ab2d6f3cd0ce2b4b00950a68c1e4bef1235c0dd39181784fa725815a2305ee`。最初測試類別篩選未匹配及檢查器變數命名編譯錯誤已修正，沒有把這兩次列成通過。

共用JSON工作台領域類別已能驗證啟用中的候選profile及產生保留loop mode的部署設定，既有旗標改名同步untilFlag及retainFlags。這批只有領域正流程證據；管理端候選profile啟用、HTTP保存／配套匯出、專用loop表單／圖形預覽與瀏覽器驗收仍待完成。巢狀／跨body流程、其他入口adapter、Client畫面與回跳行為、原生MEF閉合及更廣功能仍開放；非正流程仍依原清單待測。

`GAME_RUNTIME_OBSERVATION`：本輪無新Client人測。新批次須驗同chart10／1實際回跳、每輪生怪與機關、資源延續、背包及108／128EXP結算回村，不能將合成證據填成實機通過。

新增待測仍保留：非法／交疊body、跨header跳轉、超限／缺失producer、visit收據挪用、latch重送、重連恢復、同場併發、故障與資產提交中斷，以及分布／負載。這些未列入本輪HappyPath驗收，既有保護與歷史結果不刪除。
