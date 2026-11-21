# 一般狩獵場單趟正流程檢查

2026-11-22：[Case693完整TCP路線](MEF-INTEGRATED-TCP-ROUTES.md) 新增正常登入／primary與gateway tick的真正socket模式（`--tcp`）；兩路仍以原BND保存88EXP並回村。以下歷史37／41路線仍屬原來應用層收據，不因新模式而變成全部TCP已驗。

2026-11-21：[Case693 完整副本整合](../scenario-content/MEF-INTEGRATED-DUNGEON.md) 新增固定整合稿兩條正流程：計時／依序波次、頭目75%血量增援、消耗與分支機關、88 EXP結算及同村隊伍返回。逐波收據證明增援時頭目仍存活、出口未開；這仍是準備帳號應用層，不是TCP或Client實機。

此模式以一次性 SQLite 帳號，透過 Server 應用層現有封包處理，走廣場建單人隊、
進入對應村莊、選 Stage／Case、按正常開始、原 BND 戰鬥／拾取、結果提交及回到
同一等待室，完成一場即結束。不執行後續離隊、登出／重登、同伴退出或比較分支。

這是 `OFFLINE_SYNTHETIC` 的準備帳號正流程，並非原版 Client、TCP 網路端到端、
全新帳號完整教學或主線通關。準備資料明示為角色 4、Lv.15、教學／Q15 已提交；
第二村另外以固定主線的已完成前綴準備入村資格。只處理一次性測試 DB，不碰玩家存檔。
角色經驗依指定政策的 Lv.15 門檻建立，不偽稱本輪從 Lv.1 練至該等級。

檢查器既有 `--stage-one-journey` 加上 `--normal-route-only`；此模式要求完整的
主線、經驗與交易目錄配套，不與輪替多場、裝備比較、同伴或離隊選項組合。
行為配套可用 `--stage-one-behaviors <絕對路徑> <SHA>`，由同一 reader 載入。
輸出列出實際 AI SHA、正常入口／結果返回證據、準備等級與主線前綴。
原有完整工具與歷史結果保留，未因新模式而移除暫緩測試。

關卡編輯器匯出內容仍先經既有 Case／來源／圖序／AI／BND 檢查。正常入口模式
增加應用層流程證據，不代替全部 Host 配套、故障／重送等暫緩項或指定 v2 實機。

## 2026-11-19 收據

[41 條路線摘要](hunting-normal-route-validation.json) 保存逐路線內容／AI／原始收據 SHA。
15 個 Case 的全部 37 條有限圖路線通過：315 一條，693–700 各兩條、701–704 各四條、
705–706 各兩條。另外 Case 693 的自訂 AI 匯出版本兩條、結算由 20 改為 25 EXP
的匯出版本兩條通過；後者包含擊殺經驗，實際每場保存 81 EXP。
所有路線各提交一次結算，建隊與結果返回的 room key 一致，隊伍快照角色等級為 15。
檢查原 BND 靜態走位及 Server 戰鬥，不代表 Client 自主生怪、AI 或原生 MEF 執行。

兩個早期 fixture 錯誤已修正後全量重跑：準備 Lv.35 超過此早期政策的門檻表，
以及第二村前綴準備前未建立故事表。這是檢查工具初始化問題，不列為玩家故障修復。
最終分類仍為 `NOT_NATIVE_MEF`；離隊／登出、故障等暫緩分支未執行。

Host／檢查器 Release 建置零警告、零錯誤；HappyPath 628／628 通過。
第一次測試啟動因 testhost 連線逾時中止，無測試結果；確認程序退出後，
在可用的本機測試通訊環境重跑通過。收據保留此限制與最終 TRX SHA。

## 重現

私有 Server 的 `tools/check-normal-hunting-routes.py` 僅啟動上述單場正流程。
先依 Server 測試規則建置 Release 檢查器，再在該 repo 執行：

```powershell
python -B tools/check-normal-hunting-routes.py --analysis-directory E:/Tartaros/workspace/s00-runtime-dev --bounds E:/Tartaros/workspace/outputs/fresh-early-raid-story-bounds --output E:/Tartaros/workspace/outputs/normal-route-new
```

`--case 693` 限定基準 Case；配套使用 `--paired-case`、`--paired-scenario`、
`--paired-sha`、`--paired-ai`、`--paired-ai-sha` 五個參數，SHA 必須來自實際匯出檔。
`--only-paired` 跳過基準組。原始 JSON／stderr 與摘要留在指定新輸出目錄。
執行前核對配套；本工具不套用草稿到運行中 Host，也不替換遊戲資源。

直接呼叫檢查器的參數順序如下（分行僅為閱讀）：

```text
--stage-one-journey <scenario> <bounds> <scenarioSHA> <case> <default或逗號分隔出口鍵>
<story> <storyBounds> <storySHA> <squareBounds>
<experience> <experienceSHA> <trade> <tradeSHA> 0 0
[--stage-one-behaviors <AI檔> <AISHA>] --normal-route-only
```

多個分支出口依走訪次序使用，不能以最後一個出口代替整段路線。
完整模式的舊參數／歷史結果保持；當前只安排此正流程模式。
