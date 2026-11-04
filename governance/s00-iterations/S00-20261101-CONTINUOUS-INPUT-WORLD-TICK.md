# S00：持續正常輸入不能阻擋戰鬥更新

接續 REQ-0016 戰鬥優先。此次是 **Server實作缺陷與正流程合成證據**，
不是新增原始Client觀察。現有17REQ／18runtime／6玩家需求／0approved不變。
沒有Client修改／附加或代替使用者操作遊戲。

## 問題與修正需求

本機候選將100ms延遲與每次socket read競賽，只有延遲先完成才更新world。
但每次收到資料後又重新建立100ms延遲；正常移動／按住攻擊若持續送輸入，
就可能反覆讓read先完成。結果是命中、AI、死亡移除及勝利返回依賴「停止傳資料」，
這與可正常操作的教學戰鬥不符。v5的獨立模擬通過，未涵蓋這個實際TCP迴圈條件。

需求：同一合法Session的world更新要有自己的期限，不能因一般read抵達就重新延後。
維持lease查核、取消、發送界線及紀錄策略，不以放寬認證或讓Client少傳資料處理。

Server重建排程採一個跨read保留的100ms deadline；到期時優先處理world，
處理完才建立下一個deadline。既有pending read保持同一個，不另開重疊Receive。
這是Server排程選擇，100ms不是官方tick規格，也不改012A冷卻counter頻率未知的結論。

## 證據與驗證範圍

新增正常旅程的第六個Theory資料列，明確啟用三怪模式，與原單怪／world OFF等列分開。
實際經過loopback TCP、候選frame、SQLite帳號／Session／ownership與教學交握：

1. 正常登入、命名、教學移動／切角、伊莉西亞取得／編隊及05→09。
2. 檢查三個不同monster entity、model1036、scale1、滿血萬分比及速度初始化。
3. 每20ms持續送正常輸入；受控simulation clock每次前進100ms。這是測試時間控制，
   不是宣稱原Client實際固定20ms或遊戲時間倍率。初期維持idle輸入直到收到敵人對玩家的0E，
   然後正常按住Z，持續接收玩家對三怪的0E與各自移除。
4. 接收返回map188及既有重建／4C14，再接正常後續劇情與蘋果取得。
   SQLite獨立查詢確認Server勝利、裝備、role2與profile revision；不是只驗某個builder。

15個HappyPath cases通過：原14例＋新增三怪TCP列。仍208方法／10正向方法／198暫緩。
這輪先因nullable分支的CS8602編譯檢查失敗，補明確非null條件後，同組重跑通過。
沒有把測試通過當作Client遊戲畫面／操作或完整教學→廣場驗收。

前一輪v5唯讀健康快照尚未出現新auth／教學連線；這只描述該次快照，
不是使用者永遠沒有測試，也不能用metadata缺少反應推定Client行為。

## 接續與限制

此修正與已準備的各段普攻名目片長合併為下一個可連測版本；結果卡須對齊實際部署版。
完整官方AI、技能取消／命中窗口、冷卻UI、失敗／復活，以及REQ-0017任務／轉場／廣場
仍未完成，沒有刪除或以合成結果代替。

多連線公平性、持續高流量、取消／半包、過期lease、partial-send、併發與故障等記待測，
現在不執行。此案使用單一有效Session的正常輸入，不是負載／壓力測試。
normative pin、formal admission及原始證據唯讀要求不變。

## v6本機啟用

2026-11-01 12:19:26 UTC，依既有授權替換指定v5 Host，資料庫／Admin／Client保留，
無schema migration。v6含跨read world deadline及逐段普攻名目時長，15正流程通過、
publish完成。源碼commit以私庫本次提交追溯；實際DLL SHA256：
Network `2e617f509ba13d5baf9e24da846e09822f0ecd5dffcfeca527ccafdf35e2843e`；
Protocol `bf87cdc5c0d09631abac6c060df17f8a2f03efe3d7a2ba77599d72dab4a9bc4e`。
健康端點正常。新的v6結果卡取代v5卡，範圍仍為三怪追擊／出招／受傷、Z持續輸入及放開、
一次X、全滅後返回即停。實際結果待回，不將這次換版當Client驗收。
