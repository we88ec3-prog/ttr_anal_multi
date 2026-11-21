# 旗標觸發後延遲

2026-11-22，自有MEF scenario V1／NOT_NATIVE_MEF。新增 `FlagDelayElapsed`
訊號，帶 `afterFlag`與正數 `delaySeconds`（最多3600秒），其他事件資料必須省略。
afterFlag需為已宣告、可在本節點路徑產生或保證帶入的其他旗標，不可指向自己。

不同於NodeDelayElapsed從節點啟用算時間，這個訊號等parent旗標成立後，
在第一個既有adapter允許的ObserveNodeTime poll開始倒數。這是Server poll
觀察時機，最多含既有poll間隔的延後，不宣稱C2S到達瞬間或Client動畫ACK。
關卡尚未ActivateNodeTimer時不開始；若parent由前圖帶入，新圖另起自己的倒數。
沒有此類訊號的舊內容不增加計時掃描。

parent來自消耗機關時仍只接受正式交易receipt之後的旗標；背包／任務及戰鬥
亦沿用既有權威producer。預覽、單純查詢、planning fork或UI回覆不啟動計時。
倒數只由既有正常世界poll推進；達標設立一次性flag，接既有出口、增援、互動、
屏障、危險區或招式條件。延遲鏈在同個poll啟動後續timer，不依JSON訊號順序；
正delay不會在新啟動的同一時計瞬間直接完成。

timer屬本節點、旗標屬本場。fork複製已開始的timer，不共享可變狀態；換圖
清除timer，再按新節點定義啟動。沿用現有NodeDelay的Server經過時間語意：
已啟動後若場景暫停poll，時間仍流逝，恢復正常poll時評估；不額外停表。
planning未發布時不會poll該fork，未開始的timer要等正式採用後才開始。
不是持久化續關、現實倒數或任意取消重置計時器。

載入器將afterFlag依賴納入既有可達性／路徑交集固定點，循環無根不可達；
通過需此延遲flag的出口可推得parent已成立。管理端增加parent旗標欄位，
重新命名／刪除引用一起處理，保存／匯出不自動發布。指定v2另行驗收。

## 整合候選

Case693獨立flag-delay關卡沿用上一版switch-puzzle與原AI，三開關任選兩個
產生puzzle-ready後，新增1.5秒延遲才開3／6出口；75%實際血量產生boss-phase-two
後新增0.75秒延遲才出原有兩名階段增援。原消耗機關、招式、分支及88EXP不變。
source SHA為c0b22c412c8cca7889bc24167c9802b85199558974226c3d5a99f68a8d38ca6a，
AI沿用d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4。
IncludeFlagDelays啟動選項與其他獨立整合候選互斥，不自動替換服務。

檢查器只保留各timer開始、到期前最後一poll、到期第一poll三筆只讀收據，
並核對實際0048開門／活頭目增援封包與狀態；計時不由收據getter或檢查器設定。
這是準備角色／受控時計的正常TCP工程證據；Client倒數畫面或效果尚未驗收。

## 本輪正流程驗證

Release Host／Inspector／Admin.Web建置通過，HappyPath665/665；新增三個案例
驗證晚觸發不沿用入圖時間、getter不啟動timer、延遲鏈同poll啟動、fork獨立
與新圖先啟用才起算。JS語法及兩庫相同Schema的候選驗證通過。

兩條正式gateway元件loopback TCP路線通過。門的到期前／後觀察為
1.433→1.533秒與1.4→1.5秒，只有到期後收到3／6開門；頭目增援皆為
0.7→0.8秒，0.75秒門檻在下一正常poll成立，當時頭目未死。
所以不寫成0.75秒精準動畫時點，也不忽略移動所產生的非整百毫秒步長。
每路14枚子彈建立／清除、88EXP保存及原村莊隊伍返回；舊配套兩路維持13枚／88EXP。
獨立Host來源預檢通過且完成後關閉自己的Host，未更換目前服務。
詳見 [機器收據](flag-delay-signals-validation.json)。

循環／非法引用／閾值邊界／重送／故障等保持待測；Client、自然新帳號、
新管理欄位瀏覽器互動及獨立部署Host遊玩未列通過。原生MEF或CPU移轉狀態不變。
