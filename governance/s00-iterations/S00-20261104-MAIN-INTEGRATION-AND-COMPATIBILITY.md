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

v18正流程測試、main推送與部署收據在本批完成後補入。只執行Category=HappyPath與靜態內容／治理檢查，其餘已暫緩套件不執行。Client EXE／資源未修改或操作；真人驗收仍待測。
