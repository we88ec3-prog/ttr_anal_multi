> 2026-11-08 後補：現行部署為 v76，部署紀錄見 `governance/client-variants/20261107-all-skills-unlock/host-v76-deployment.json`。下列 v50／v44 部署描述保留為歷史。新增 [進村操作意圖與測試範圍](NORMAL-VILLAGE-ENTRY-INTENT-AND-TEST-SCOPE.md)：原有 party helper 直接呼叫 domain connection，不可稱為該段 TCP 驗證；實際 Client 正常建房進村驗收仍待回覆，多人預設停用。

2026-11-08 歷史：v50已啟用，Host PID5196，私有main來源950b1cd4371509b50977463fd48801f862cd22a5。106項HappyPath通過、0失敗；原介面正常進村實機待測。優先序：正常進村→全角色技能→原生MEF→其他。多人加入／邀請候選預設停用，不影響單人建隊進村；不宣稱多人完成。使用者稍後一起測，不重複催測。

最新已提交來源：私有main2428e3342f7fc5e3d72c60be556969e193870ad1（state-refresh／已支援角色切角kit），現行Host仍v44；公開加入／快速加入／邀請admission與多人world不在已完成功能內。

2026-11-08 狀態同步後補（未部署）：room revision／不可變snapshot讓timer只發布變更，不建無界通知佇列。房間位置取實際world，列表filter不改位置；載入／戰鬥／劇情鎖定時busy。名稱快取在建隊snapshot前發布，普通資料更新不重送本人加入旗標。正常非戰鬥切換已擁有1/3/4角色，先準備既有授權starter kit再重建，避免舊角色kit不符而漏發裝備／技能。106項正流程通過51秒，包含角色3裝備19、已學技能與party角色/等級同步；其他角色持久資料未擴充。第一候選有1項filter/位置混用失敗，修正後才通過。

2026-11-08 房主姓名後補（未部署）：008D之前在已認證slot0發布可見房主001C姓名快取，使用持久冒險團名，不是房間名／角色名。已核對slot0/slot2共用正常receive lane2，001C於CClient第一層轉GlobalStatus、無scene gate；這是Server主動發布政策，不把slot2的0013請求掛到slot0，也未猜aux認證。106項正流程通過51秒，已斷言NewVoyage姓名及UID與列表一致；實機待測。詳directory-owner-name-chain-v1.json及owner-name-proactive-dispatch-boundary-v1.json。

2026-11-08 改名／容量後補（未部署）：已接005F46B正常修改，更新共享目錄後以008B45B發布，與008C取消公開分開；106項正流程通過51秒，包含修改後008D顯示新名稱與容量。

2026-11-08 接線後補（未部署）：旅程共用目錄已接0052查詢、0053建隊、5E/60實際公開狀態、003D城鎮context及005D離隊；gateway斷線與debug覆寫清理房間。106項HappyPath通過53秒，包含真實合成TCP/SQLite旅程檢查清單由空→公開列→私人隱藏、正常進村及離隊。仍未接manual/quickjoin通知、名字cache及多人場景；現行Host仍v44/PID30596。

# 正常房間公開目錄核心（Server候選，尚未接線）

目前實際運作為v44，使用者稍後才測正常建隊進村。這份是接續開發，不能當已部署的公開組隊／加入功能。

來源：governance/client-variants/20261108-normal-village-entry 的 v2勘誤及 join-update-and-modify-v2.json。0052為7B查詢：page、literal9、kind、context、waiting filter。008D為6B表頭（currentPage BYTE2、totalPages BYTE3、WORD4本段consumer未讀）及54B列：listingWORD0、kind2、context3、name21WCHAR4、ownerUID2E、capacity32、count33、busy34及未知tail35。0054加入送ownerUID而非listing key；0055是快速加入，不是改目標。005D00離隊用008900清理是Server選定正向政策。008E/8F只建立關係，不直接證明換圖。

目錄採Host共用記憶體狀態，登入連線識別與公開UID分離。單調room key、房主公開／取消公開、列表分頁、房主位置／busy更新、成員退出與房主解散為明示Server政策。對外不洩漏連線Guid。加入必須由caller提供世界／權限准入判斷，不因找到公開列就授予村莊資格。

kind0查全部，其他kind/context精確篩選；勾待機排除busy或已滿房間，每頁9筆，空清單totalPages0由原UI顯示1頁。未知tail35發0只作候選，未命名官方enum。房主解散不選舉新房主；這不是已證官方政策或持久化／分散式房間服務。

106項HappyPath通過，新增一位房主從建立、公開、查詢008D、轉私人到離隊的完整內部正向路徑；沒有執行第二個玩家加入、併發、錯誤／邊界或實機多人測試。後續仍需接入真實連線生命週期、斷線／離隊通知佇列、名字cache、村莊場景協調。全角色技能87項映射仍未解，不將此成果當整體目標完成。

私有Server實作來源main8da7e5409059809ccd9c20bf3c36cc6c4b13c837。TRX v45-directory-core-positive.trx SHA 33dd29b3116f56b73325d5fc02a71d79e60e6ef26ebf584fbb6eeb527c828afe.
