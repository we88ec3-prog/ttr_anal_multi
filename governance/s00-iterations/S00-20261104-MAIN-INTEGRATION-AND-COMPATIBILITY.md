# 2026-11-04 main整合、來源驗證與v18相容性修正

## 使用者要求與本批Git邊界

後續直接在main作業，除非使用者另有要求不開新branch。已在workspace、分析庫、Server AGENTS記錄，優先於舊每人另開分支規則。原main工作樹確認乾淨後停留原commit的detached狀態，將main移到目前實際維護工作樹；沒有刪除原檔、原worktree或歷史分支。

分析main基準83959c0e7e65ab01348b285f03c285f487077610；整合既有S00遠端18bbf99e4、T01的81a49342474ced9b306ed8b8a305a2aa326a7bac（包含T10 df53250f及T16 72c558ca的研究）、extra/roy2與extra/roy3歷史。保留T01／S00兩邊補件，fixture衝突採用完整provenance來源與動態計數，不以舊硬編碼數量覆寫新台帳。這裡同步本輪開發與相關研究分支，不任意合併其他TC／歷史廢棄工作。

Server原main69c714c54fb5c802251736ee38ff37c19fba3c53快轉整合現有f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e，之後修正在main提交；不是另開功能分支。

## T0／T01來源核對與S00採用界線

此處T0來源核對沿用既有T01的R0/R2流程，不新增另一個正式來源台帳、不改其他Task owner。既有T01報告為 research/handoffs/t01-20261103-t10-t16-native-review/README.md；本批獨立完成：

- 68份來源的Git blob SHA、SHA256、bytes全吻合；T16 manifest的55份內容全吻合。
- T10 ZIP內63個manifest成員逐一解壓重算SHA256全吻合。補足T01原批未重跑的ZIP內部完整性，不冒稱全文語意通過。
- 原始BIN完整SHA核對；按PE section映射再核對T01列出的7個window及16個anchor，全部相符；4個sender門檻DWORD為100/120/180/300。它們不是combo/cancel時間。
- 重跑T16 validate_content：structural PASS/errors0、activation BLOCKED、unsafe enabled0、deferred0。不是20任務已實作或已通關。
- S00台帳完整性、REQ來源及dispatch檢查通過；不提升RR、GAP、SPEC、ADR或原稿FULL-PASS狀態。

機械檢核結果見 evidence/S00-20261104-SOURCE-INTAKE-REVIEW.json、NATIVE-INTAKE-REVIEW.json、T10-ZIP-REVIEW.json。原件與來源原稿未修改。

## v18實作採用

| 項目 | 採用修正 | 限制 |
| --- | --- | --- |
| 0A輸入觀測 | 保存raw header、全部row的ordinal/actor/word/byte，重複actor不去重；分開low15與reported moving | gameplay仍只處理唯一控制actor，不把未知producer或重複actor偷偷last-wins |
| 實際回覆 | 捕捉成功完成Server Send的0B/0C/0D/0E/16/DA/012A，附source batch；timer/debug回覆不冒歸前一輸入 | send完成不是Client ACK、畫面完成或官方時序 |
| 多鍵動作 | 只將已有候選1、2、5映射至現有普攻／技能；3、6、7等不再因位元重疊誤變成X或Z+C | 本批不虛構缺失組合技能；原生availability column不是Server施放裁決 |
| 玩家受擊 | 改送000C state5進入Attacked，而非000D motion9要求SkillState13；既有Server受擊CD／恢復政策保留 | 未恢復官方硬直、霸體、取消／自然退出完整規則，需人測 |
| 多鍵移動 | 撤銷8000=physical held的說法，保留reported bit與physical unknown兩層 | 分析有同值反例；本批不能保證區分held方向+Z與released方向+Z，未宣稱移動缺陷已修好 |
| 診斷保存 | debug opt-in下非同步限量gameplay sidecar，ring可即時查；只記上述輸入／gameplay回覆，不記登入帳密或任意payload | sidecar上限4MiB、queue1024，quota／IO狀態與dropped可查；不以記錄失敗改gameplay決策 |

既有v16測試的8001是合成wire向量，不是所有Client控制器的held方向+Z證據。真人未通過的紀錄仍保留。未能從舊v17Host取得新trace；不補造四方向實測資料。

## 共用任務Runtime的S00決議

採用T16的typed ID／事件／服務分層與資料schema作後續設計輸入；20 definition、4 flow、8 scenario仍全部DRAFT_BLOCKED，不匯成啟用的任務、不以scene播完結算或發獎。現有到村路線保留，Quest117以後尚未因這次整合變成可玩。

下一步依migration-matrix逐點抽取Presentation、Scenario、Quest settlement接口，先對教學與Quest15保存行為，再對117/119補合法predicate／結算／world資源。此為共用引擎後續工作，不以增加QuestId switch當作批量化完成。MEF原生格式仍缺；候選JSON不是MEF。

## 驗證與部署

v18最後一輪28個HappyPath通過（19秒，0失敗／略過），Release publish成功。中間診斷持久檔讀取測試遇到Windows檔案共享限制，修正為FileShare.ReadWrite後重跑允許集合通過。只執行Category=HappyPath與靜態內容／治理檢查，其餘已暫緩套件不執行。Client EXE／資源未修改或操作；真人驗收仍待測。

## v18發行收據

分析main d552852448d63755e55f97c314486c6b07e7f723，Server main a3478089164d24eeaec75839ee5c5b86cb36aad7 均已推送。啟用PID23216，完整指定路徑 runtime-observations/2026-11-04-main-integration/server-host-v18/Tartaros.Server.Host.exe；沿用本任務原隔離DB，不修改Client。
Host DLL SHA256 dc7f89abcc337ec7c7b41a82747582f5802eda44f73c2d5adc2a0bf8ac617e26；Network DLL SHA256 4419c3c56389cb733327b1c4e2df4549f6ec06c97d9fda2553cf9c13c6f6b648。啟用前已在實際執行環境保存Listener清單（本輪為空），腳本仍限制只可替換原v17 exactpath的loopback Listener。health登入與journey啟用，progress/status顯示traceJournalState Healthy、dropped0，尚未有遊戲連線。

本版是有限相容性修正，不是宣稱四方向加Z已修復或整村主線已完成；下一輪需實際row＋S2C紀錄確定可區分的輸入與FSM生命週期。未接收到的新遊戲測試不補寫PASS。

## 工作台同步與下一目標

11份既有工作簿已獨立驗證／發布，SRC762、REQ20、SFD13等正式欄位就地同步；人工備註、ID、公式、原樣式與sheet控制保留。同步收據 workbooks/tartaros-kr/update-history/20261104-002455.json。功能表未測狀態不升格。更新器修復正式欄之間人工欄誤套格式問題。

使用者後續指定繼續開發至爾斯梅勒村，稍後才人測。沿Quest15後的候選主線查證到Town2／Alsmeer；v18保持可測，不因未完成的後續逐個換版。新的終點不代表本報T16草案已自動啟用。
