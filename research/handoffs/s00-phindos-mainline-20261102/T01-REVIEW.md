# T01：馮德斯資料逐主張驗證與整合

使用者指定extra/roy1、extra/roy2、extra/roy3交付後由「T01」對話驗證整合。
先讀[總卡](README.md)及三張工作卡，保留既有T01驗證／退回規則；不將來源收件、hash
比對、窄合成測試或多分支合併當作全文FULL-PASS／Server可玩驗收。

1. 先建立本包驗證矩陣：來源branch、commit、path/blob、精確target、claim／scope、
   原件／callee／上下游／反證、PARTIAL或可接受界線、需退回項與Server可採用欄位。
2. 接收三個extra批次（S00會持續彙整交付連結）；先驗15→117、Field19→結果→進村、
   Town1 map/controller/NPC，再驗村內完整主線。不要以未知官服後端規則拒絕所有Client可查內容。
3. 校驗器先自查指令邊界、PE section映射、函式／子物件原點、callback layer；有不同
   namespace或scene覆寫不能僅按opcode數值合併。既有退回固定ID追加，不刪歷史。
4. 優先附帶審核既有Web T10/T11新成果0419c66009a958597e95c9a88740d6f7f0d6772c：
   T10-P0A-V7-Z-INPUT-ROW-CLOCK-BOUNDARY及P0B-KR-000E-VTABLE-VS-000D-MOTION。
   P0B對4ADD50/base controller的0E說法與S00先前common result row路線有適用層差異待核，
   不能只接受「0E永遠是清理」或反過來稱「0E必傷害」；沿實際scene/controller與override判讀。
5. S00載入分析0556a7af8的23/24前端與_LoadDisplay候選，可獨立核對其有限主張；
   仍不代表v8人測過關。核心AI／MEF與連段主分析留S00，不把本包改成替S00做全部開發。

按現有repo流程整合新extra分析，提交清楚的驗證／來源登錄與退回；先不替S00合併PR102，
不碰私有Server庫或繞過既有auto-review拒絕。正式規格接受／核准由S00另行處理。
必要時將可驗證部分先交付，不等待所有村內支線、取消、重播、重登或完整後端規則。

對話如出現明確長度上限，停止接新派工，保留checkpoint（已驗claim／未驗claim／工具／
來源SHA／提交），由S00接手驗證整合；不得自行建立替代對話或發訊息給其他對話。
