# 接續 MEF 完整分析的方向與順序

本輪已按[原計畫](../MEF-comprehensive-contracts-20261117/ANALYSIS-PLAN.md)完成三項P0的增量處置與四項P1有界續析；具體未閉合條件以[P0-P1-COMPLETION](P0-P1-COMPLETION.md)為準。本規劃不再把重列bindings或相同字串掃描當成完成度增長。

## 1. 最先接續：資源選取與 Server 工程並行

**資源線先固定真正winner。** 優先取得同版fcs／實際scan來源、category Base、selected avatar及FLD；按父provider→子provider與loose／cache／resident條件確認所選path，再解析其後代。對已證base mesh只在正確flag／probe條件下展開EMF，對texture只在原path probe0下展開ETF。輸出應是每個實際dependency的source hash、member、選取原因與接受結果，不以「某包包含同名檔」代替。[補件清單](SOURCE-REQUEST.md)

**Server線可以即刻採用已有契約。** 按內容版本／typed ID→run與scene排程→權威world與逐節點出口→結算／返回／Q120資格→既定服務順序推進。Server缺失規則是開發需求，不列成Client逆向封鎖。[Server驗收](SERVER-HANDOFF.md)

## 2. 普通首次入口 B：改追新正向來源

本輪已完成正常talk receiver安裝、global writers、繼承reader／clone；它們未提供首次本次content執行。下一步只有在新Field／UI Lua載體或具體ordinary事件owner出現時，沿「事件→typed caller→首次load／execute→同VM後續pump」接合。每一步保留owner、取消、重入與普通input／field是否持續；不能以Rebind原始指標或Q已有pump代替B證據。[候選與缺邊](entry-b/candidate-contracts.json)

完成門檻是一條真正原版可達、typed、可固定原件的完整鏈，再接允許的正常流程驗收；不是再加一個可能callback名字。

## 3. world→Lua：從橋接 writer 與生命期身分接合

HP比例／絕對值、結果顯示、nativeAI、paired視覺record、死亡FSM及erase各自終點已明確。下一條有價值的候選應提供真正storage／callback registration或Server→script adapter，並可核對run／actor generation／eventSequence與同VM consumer。計算指標及外部模組仍受有限census邊界限制，不因本輪未找到而全局排除。[未閉合endpoint](world-lua/contracts.json)

若產品目標就是讓Client Lua讀任意world事件，應列typed bridge為明確新需求，對事件型別、身分、取消／消費／清理作設計與驗證。Server權威事件可先完成；不要把未證存在的Client bridge當成排程必備。

## 4. 七族組合與正常旅程驗收

七族各一真例已齊，下一階段按共享owner的相互影響組合：相機work與snapshot、Q圖與Tutorial／Prolog UI、primary music與voice、actor引用與texture queue、point snapshot與map／controller。只增加會解除具體整合風險的案例；不以更多同型API呼叫數當成進度。

首個旅程依本輪十步Q119契約驗收，最後必須包含結果持久化、返回可走動／NPC、Q120等級及新NPC資格。四BND靜態路徑檢查只支持候選座標，後續正常Client流程才支持動態碰撞、畫面、音訊與實際操控。[完整旅程](journey-families/REPORT.md)

## 5. 官方 MEF grammar：原 P2 有了具體 carrier

新線索已由泛稱`.mef`收斂成Master Field宣告。取得Field.stp後先固定真MEF sample與metadata，再查打開該bytes的實際consumer、header／version／record與executor狀態owner，做最小可證正例及拒絕案例。若sample是另一版本，另固定BIN與mapping。

Field extension slot、MapList.TRIGGER字串、封裝工具規則、Lua parser存在，都不能單獨宣稱MEF grammar或executor完成。此線與Server外部scenario內容版本保持清楚，不用自訂JSON冒充官方MEF格式。

## 6. 後續每次交付的共同欄位

每一增量保留玩家情境、真正入口、typed參數／回值、source/member/winner、owner與退出、Server責任、未知與解除證據，並區分原件靜態／衍生資料／SYN／Server工程／正常Client流程。只有影響的依賴重驗；來源無新增時不重做全量census。正式完成旗標與產品驗收由既有owner採用證據後處理。
