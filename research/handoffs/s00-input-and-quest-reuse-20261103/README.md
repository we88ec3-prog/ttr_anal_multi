# S00：多鍵輸入與共用任務引擎分析工作包

使用者要求明天交由Web AI分析：多方向／多動作鍵輸入，以及將目前逐段實作的主線改為可大量配置的共用處理。此包供使用者貼入Web AI；不是已派送、已認領或已完成研究。僅推送S00開發分支，尚非main上公開的RR認領；不手改生成的Task inbox、不更動Task owner。已有相同RR時請延伸既有請求，避免重複登記。

1. **P0 [多鍵輸入與動作消費](W1-MULTI-KEY-INPUT.md)**：建議T10主查輸入／連擊、T11補技能裁決，T01驗證。S00繼續負責Server核心修正。
2. **P1 [共用任務與批量內容](W2-REUSABLE-QUEST-RUNTIME.md)**：建議T16主查任務、引用T06/T07場景與T09副本既有資料；T01驗證，S00整合Server設計。

先交最小可用結論，再補全稿。每份都分已證Client事實、使用者要求、Server候選設計、未知；來源要有版本／原件SHA／檔案與Git blob SHA／函式分支及表格欄位。禁止把本地Server fixture或影片推測寫成原生事實。不要執行／附加或修改Client。只靜態分析正常流程；其他測試整理待測，不實際執行。

本輪基準：分析分支 codex/s00-combat-priority-20261101，Server分析前基準e01730c9eed62f9edbd25eb2453898e198032a38。原KR SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。未聲稱核對最新main；Web AI開工依AGENTS讀取當時main與既有收件箱，若無私有Server存取權，使用本包與公開分析，缺資料請列清單，不假稱已讀私有原碼。

## 交付位置

研究者沿已授權個人分支，新增 `research/handoffs/s00-input-and-quest-reuse-20261103/results/` 下的報告／資料（或既有Task研究位置並從本包引用），回覆commit及各檔blob SHA，供T01/S00驗證。若Web AI無Git寫入工具，交付可直接存檔的完整內容與來源，不宣稱已上Git。本包不是另一份RR狀態台帳。
