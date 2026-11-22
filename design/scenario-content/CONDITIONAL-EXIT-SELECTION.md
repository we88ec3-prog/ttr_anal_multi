# 旗標條件出口選擇

2026-11-22，SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。這是動態決定繼續／離開
所需的分支原語；本批不宣稱已完成動態loop或任意循環圖。

有限scenario節點可選填conditionalExits={afterFlag,whenFlag,trueKey,falseKey}。
兩個key須完整對應兩個現有出口且互異；afterFlag與whenFlag均須有宣告producer，
afterFlag須在每條入路可達。同節點不能並用weightedExits；省略欄位時保留舊
JSON／內容SHA與手動分支行為。沒有新增opcode、Client修改或原生MEF聲明。

只在已啟動節點時計、清場、玩家存活且afterFlag成立的正式位置／世界更新，
讀取本場權威旗標是否含whenFlag：有則選trueKey，沒有則選falseKey。每節點
僅決定一次，後來才成立的whenFlag不重新選，不能由Client直接指定布林值。
查詢、Enter、GroupCleared、互動本身及Story規劃fork不決定結果。
所選出口仍須等自己的requiredFlags及ActivationRegion成立才開啟／使用，
不因條件未滿就改走另一出口。即使其必要旗標稍後才成立，也不重選分支。

靜態分析將afterFlag帶入兩條出路，只有trueKey路徑保證帶入whenFlag，並沿用
既有相依閉合／合流交集。falseKey不設立否定旗標；旗標仍是單場一次性集合。
記錄run、scenario SHA、node、policy SHA、whenFlag、當時是否存在、key與target，
跨圖、fork及結果摘要保留。這不是RNG票據；不產生假的draw或權重紀錄。
新run重新判斷，跨登入仍依現有重開政策。

Schema／Story inline轉接／診斷與一般狩獵場結果同步。JSON工作台可保存匯出，
訊號改名同步afterFlag與whenFlag；此節點的權重表單停用以避免混用兩種規則。
專用旗標分支表單尚未提供，編輯內容仍須經來源、AI、BND及路徑檢查。

固定Case693候選沿用flag-delay完整副本，在node3以puzzle-door-ready後判斷
branch-switch-c，有則走出口6、無則走出口3。11／31／33與11／31／35兩組
正常checkpoint意圖由正式adapter提交旗標，在同一份內容上產生不同分支。
再驗延遲、波次、存活頭目轉階段、一次88EXP存檔及同村同隊返回。
指定v2、自然升級及獨立Host遊戲通關分開記錄；
非正流程照既有清單待測。

下一步循環仍須處理訪次身分、旗標作用域、重啟波次、逐訪成本／掉落／EXP、
當場決定停止以及唯一結果；不能把固定最大次數展開或單次分支當成循環完成。

## 本批工程驗證

[固定Case693](phindos-stage462-case693-conditional-exits.scenario.json) SHA-256
`803b749d0335084a1e690470c61abd93788140a77a4d9cb7c46f7408d3b1b725`，
AI仍為attack-flags d4768b72。[收據](conditional-exits-validation.json)記錄兩條
正常TCP：11/31/33沒有C旗標，選出口3到node5；11/31/35已有C，選出口6
到node6。沒有真假值或亂數測試注入；兩路都只選一次，選擇保留至後續節點
與結果。條件選擇不經權重抽選，正流程單元測試另驗亂數委派未被呼叫。機關延遲1.5秒後只開該出口，頭目存活轉階段及
0.75秒延遲增援保持；各14枚子彈建立／清理、一次88EXP存檔回原村同隊。

原權重控制組仍各抽一次、不產生條件選擇，各88EXP回村；舊單房／兩房編譯器
六個固定配套bytes相同。Host獨立資料庫及隔離埠預檢確認來源、AI與88EXP後
停止，只證明Host配置。schema鏡像相同，舊約束保留。沒有替換目前服務，
也沒有執行Client。動態loop的接續工作見[DRAFT計畫](DYNAMIC-LOOP-EXECUTION-PLAN.md)。

最終Host／Inspector／Admin.Web Release建置零警告、零錯誤；683項HappyPath全通過。
