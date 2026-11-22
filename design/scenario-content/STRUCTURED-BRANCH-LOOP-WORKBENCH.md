# 分支循環副本的管理與配套發布

2026-11-22；SERVER_DESIGN_CHOICE / OFFLINE_SYNTHETIC / NOT_NATIVE_MEF。
接續分析庫50e211ef9與私有Server230bcd36；不代表原生MEF格式或Client驗收。

管理端新增獨立 `case-693-branch-loop` profile。使用原Case693的3→5或6→4區段，
header3、latch4/key4、出口2及原BND保持；前兩房10→1 profile仍另列。
兩種profile可同時設定，使用各自來源SHA，草稿不能跨profile套用循環形狀。
既有15個普通Case及歷史版本保持。

配置使用四個環境變數：

- `TARTAROS_ADMIN_STRUCTURED_BRANCH_LOOP_SCENARIO_PATH`：分支候選的絕對路徑。
- `TARTAROS_ADMIN_STRUCTURED_BRANCH_LOOP_SCENARIO_SHA256`：`95248af6d1f74c9d6525fd80bd8bf717b832b6243a616dd170d4400ed909c154`。
- `TARTAROS_ADMIN_STRUCTURED_BRANCH_LOOP_BEHAVIOR_PATH`：配對AI絕對路徑。
- `TARTAROS_ADMIN_STRUCTURED_BRANCH_LOOP_BEHAVIOR_SHA256`：`d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。

沿用原BND目錄設定。變數只配置此副本工作台，不自動發布、不改Client。
來源檔見[分支候選](phindos-stage462-case693-branch-loop.scenario.json)及
[原AI配套](integrated-attack-flags.monster-behavior.json)。

表單依profile提供正確循環body、入口重置群組與body內產生的停止旗標。
可調輪數1～16、循環ID、停止旗標、重置與保留旗標，或關閉循環。
Server仍驗證來源、原圖／出口、body形狀、SCC、旗標相依與地形；不能以表單預估取代完整檢查。
分支body有四個成員，但每輪實際走三間房，不把兩條互斥岔路重複計算。

按「套用並檢查循環」只更新本頁JSON並向Server取唯讀預覽，不保存草稿。
三輪版保守界限88～120EXP、最多12次整場訪問；四輪版88～136EXP、最多15次。
最後20EXP結算包含在界限中，整場只結算一次。每輪實際獎勵依擊殺與正常條件累計。
保存後可以查看舊版，下載該版本的三檔ZIP：scenario、monster-behavior、manifest。
相同draft/revision重複下載位元組一致，歷史r1不受r2/r3影響。

啟動器匯入時明確選 `-ScenarioBundleProfile branch`，另提供解壓後manifest絕對路徑與SHA256。
它使用固定branch來源profile重新核對manifest/profile、draft/revision、檔名／成對SHA、
原BND／AI、loop/reward metadata及限定的部署設定，然後才啟動Host。
沒有提供profile時仍為prefix，既有使用方式保持；不讀取任意環境變數或執行配套腳本。
可加 `-PreflightOnly -IsolatedPorts` 只在隔離port檢查Host後停止自身服務。
檔案需保留在固定解壓目錄供Host讀取；保存或下載並不使既有服務換版。

這批實證：隔離Admin HTTP的未保存預覽、r1/r2/r3保存、歷史下載，以及實際下載的三個版本
五條正常TCP都通過。r1正常不支付可選機關為104EXP、支付則三輪120EXP；
r2不支付仍104EXP、支付則四輪136EXP；r3關閉循環88EXP。
逐輪開關31/33、1.5秒延遲、清除旗標、逐訪成本與投射物回收另從實際收據核對。
完整Host分別載入88/120、88/136、88/88，其他Case保持76EXP；舊固定候選88EXP控制也通過。
舊prefix工作台另五條正常TCP108/128/148/88EXP仍通過。

[畫面](structured-branch-loop-preview.png)記錄隔離管理頁實際把三輪改四輪並通過預覽；
只保存畫面、未提交此瀏覽器編輯。HTTP測試的保存版本另有獨立收據。
最後只調整profile顯示名稱以區分前兩房／分支區段，不改遊戲內容；最終建置與HappyPath另記。
[機器收據](structured-branch-loop-workbench-validation.json)保存版本、路線、Host及證據SHA。

`GAME_RUNTIME_OBSERVATION`：TCP使用準備角色4/Lv15及教學/Q15前提，是真實loopback gateway
傳輸但遊戲邏輯在檢查器程序內；完整Host這批只驗設定／啟動，沒有部署Host的遊戲通關。
指定v2人工DL-B01、全新帳號自然升級、原生MEF載入／自主AI與CPU移轉仍OPEN。
沒有執行／修改Client、替換既有服務或使用者DB；非正流程未跑。
巢狀／跨body循環、其他正常入口adapter及其管理交付仍待後續，不能宣稱MEF整體完成。

最終三個Release建置零警告／錯誤，704/704 HappyPath通過、零略過。TRX SHA256 `cfbb74f8100589ed75a321a270f283a2026a1a62b6cdf822ead1588c387bc474`。
