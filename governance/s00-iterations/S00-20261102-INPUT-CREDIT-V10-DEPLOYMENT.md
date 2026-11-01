# S00：v10輸入額度修復部署

房屋前卡點的[原始觀察／證據與修復規劃](S00-20261102-HOUSE-INPUT-CREDIT-STARVATION.md)
已提交。25個HappyPath案例通過，包含長時間正常移動與兩種保存開關路線；publish完成。

依既有授權核對Host60448為指定v9完整路徑後，只替換此loopback Host及遊戲連線。
新Host51020，UTC `2026-11-01T16:27:42.9755064Z` 啟動，來源私有commit
`cd2a7bc70f3cfb92602628137bf65c5df81b0eb2`；模式仍為EXIT_CANDIDATE。
5082／8414／8415／8416均在127.0.0.1由51020監聽，健康auth／journey正常，stderr空，
Admin2452保留且管理頁HTTP200。這是部署核對，不是Client遊玩通過。

新增journey保存模式明確OFF。唯讀DB核對Account schema2、tutorial component1、
新journey兩表數=0，沒有migration。SQLite唯讀backup API一致快照SHA：
`861670a7c26bce54db0d66c0d4c25afa4dbe05b021298f332c76e39bfebb691c`。
未修改Client／資源、未操作／附加遊戲，不公開帳號DB或登入資料。

| 核對檔案 | SHA256 |
| --- | --- |
| Network DLL | 5d7e889b1417f0adcb6aa793c1453d8ca8bf7717931e91798dd78233e1aaa0b6 |
| Protocol DLL | 2c4725249fd043fd1520aac868b7b3a108b80f14fe90d313ece6d57916c2c301 |
| 測試Client（未變） | 6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c |

已送新回饋卡：重開並正常完成首戰，回教學後走進蘋果房屋、看劇情／確認招募，
正常到廣場後移動停止就停；不點NPC、不跳過教學。不刻意重測連擊／移動後攻擊，
兩項依使用者要求保留到後續馮德斯副本測試。**實際結果待回**。
使用既有測試帳號，不是全新帳號單次教學／Quest結算驗收。

REQ-0011追加GAME_RUNTIME_OBSERVATION，REQ-0016追加使用者後續測試要求；
台帳19REQ／CODE5／RUNTIME23／PLAYER8／APPROVED0，正式規格與原生未知界線不變。
