# 關內出口權重選擇

2026-11-22，SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF，擴充既有有限DAG節點。
節點可填weightedExits={afterFlag,choices:[{key,weight}]}。choices按作者順序列
2～8個不同現有出口key、完整涵蓋所有出口，正整數weight總和不超過int32。
afterFlag須有宣告producer，且每條到達此節點的路線均可成立。省略欄位保留原有
手動分支及原內容SHA；這不是入場Case權重、動態loop或官方MEF格式。

僅在已啟動時計、清場、玩家存活、afterFlag成立的正常位置／世界更新選擇。
候選池為當時requiredFlags全滿足的出口；空池等待、不抽選。ActivationRegion
只控制選中後的開門／使用，玩家位置不決定抽選池。以可信均勻整數[0,totalWeight)
按作者順序累加選一個。之後新旗標、移動、查詢、互動、重建與poll都不再抽選。
選擇不發獎、不扣道具；未選前全部出口關閉，之後只有選中出口能沿原條件開啟。
沒有新opcode，仍用0027快照、0048狀態及001C意圖，走原圖邊。

記錄run、definition SHA、node、policy SHA、候選池、ticket、總權重及key／target。
fork複製已選結果，查詢／Enter／GroupCleared／互動不消耗亂數；既有Story規劃fork
只在提交後的正常ObservePosition選擇。afterFlag是離開此節點的必要保證，靜態
分析仍保留出口自身旗標及合流交集。新run重新選，跨登入仍按既有重開政策。

Schema、不可變catalog、Story欄位轉接須同步；JSON工作台能保存／匯出，旗標改名
同步afterFlag。後續[權重工作台](WEIGHTED-EXIT-WORKBENCH.md)已補圖形控制項。測試ticket只由檢查器可信委派注入，
不接受遊戲封包或Host配置指定結果；正式runtime使用系統隨機來源。

固定Case693候選在puzzle-door-ready後以出口3:6=6:4選一次，再接原分支、頭目、
88EXP及同村同隊返回。驗證兩種選擇、計時前後、只一個0048開點、後續節點與結果
保存、原手動控制組及既有內容SHA。分布、非正流程、Client畫面、自然新帳號與
獨立Host遊戲通關仍分開待驗。

## 本批驗證

[固定候選](phindos-stage462-case693-weighted-exits.scenario.json) SHA-256
`7143e259c8309cc1abc42b565a85cf807426fe49bcd802fc28c590b847e2e930`；
AI仍為attack-flags配套`d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。
[驗證收據](weighted-exits-validation.json)保存可信ticket2／8，分別走
10→1→3→5或6→4→2。正常login／primary gateway、廣場建隊、村莊選關
及回村，沒有直接呼叫遊戲Handle或Poll。三選二機關31／33及延遲1.5秒
後才發布選中出口的0048，另一出口保持關閉。頭目存活轉階段、0.75秒延遲
增援、14枚投射物建立與清理，單次88EXP存檔回原村原隊伍。選擇保存在後續
節點及完成摘要。這是準備Lv15角色4的合成流程，不是自然升級／指定v2驗收。

原手動控制組仍開3與6、兩路各88EXP；舊單房／兩房編譯器六個配套輸出
與固定版本bytes相同。Host獨立資料庫、隔離埠預檢確認88EXP及相符SHA，
預檢程序已停止；這不是獨立Host遊戲通關。操作入口為私有庫
`docs/LOCAL-WEIGHTED-EXITS.md`與啟動器`-IncludeWeightedExits`，
正式runtime用系統亂數，沒有固定ticket的Host設定。

最終Host／Inspector／Admin.Web Release建置零警告、零錯誤；679項HappyPath全通過。
