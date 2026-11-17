# EXTRA-ROY：P0 分析交接

紀錄時間：2026-11-17T19:31:54+08:00（Asia/Taipei）。工作分支仍為 `extra/roy1`，不新增 branch。這是本包研究導讀，不是正式 Task／RR 收件箱或第二份狀態台帳。

## 已完成的接續

沿上一批 ANALYSIS-PLAN 的三項 P0 完成有界分析與可重跑工具：全121 binding與15項勘誤採用、75 helper及兩個完整原場景、真實依賴圖與resolver、22 owner與三策略。主報告：[REPORT.md](REPORT.md)；逐項狀態：[P0-COMPLETION.md](P0-COMPLETION.md)。

本包發表所用父 commit 為 `ac7e668ef19b91f86f05074d660aba10612c9a5f`，main治理讀集為 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。本包自身發布 commit 以 Git 歷史／分支實際 ref 為準，不在尚未建立的 commit 裡假造自己的 SHA。

## 不應重新打開的已解問題

- Boot／Logic／Coroutine 原 bytes 已在既有 Git 證據找回；Boot number TRUE1／FALSE0 是有條件基準。
- 原 RevPhase1 零參數 EndSepia 已追到特定 C frame／marshaller 的 native integer0，不再列為timer參數未知。
- 原 Q2440 圖片 fade-out0 已證先行guard繞過除法；phase0、alive0、manager實體釋放分開。
- 正常初次 Q.Create direct caller immediate1；不要再把generic deferred路徑當所選原場景已發生的pending。
- SetFinalMusic空字串retain與accepted Start assign clear不同；原RevPhase1恢復正常基準，不是所有共享旗標的任意舊值snapshot。
- Actor同ID後列覆寫、CHA_ABF／MAP_FLD同basename首筆保留、Master同目錄後續成功provider指派是三層不同規則。

## 仍未閉合的實際門檻

真實資源保持 NOT_READY：13份模型descriptor、同版本Master/cache/mount、Items.ipk與遞迴內容，以及所選模型／地圖／視聽／UI payload仍缺。取得原件後沿 [SOURCE-REQUEST.md](SOURCE-REQUEST.md) 補目前前緣，不重複掃描已有830筆Base index，也不把候選basename當已選runtime path。完整遞迴payload列舉目前為false。

Server工作沿 [SERVER-ADOPTION.md](SERVER-ADOPTION.md) 和既有REQ-0019／REQ-0021去重接收：版本化preflight、typed reference、owner/run排程、既有原回覆與業務提交分離。現行schema不能直接加入任意PlayScene／Lua欄位。Q119/3是入場，119/4清場，119/5返回；本次兩個原場景各自審讀，未指定為可串接pair。

P1第一條完整正常旅程、其餘功能族、普通首次入口B、world結果到Lua出口，以及P2官方MEF格式，沿上一批規劃接續；本輪沒有把它們冒充已完成。

## 再開工與驗證

按02共用指令先讀最新main、AGENTS、正式RR／派工／T01退回事項，已有正式狀態以main為準。本包不改Task owner、RR、T01 FULL-PASS、S00接受或Server實作／可玩狀態。重跑方法與實際證據收據在 [VALIDATION.md](VALIDATION.md)；需要完整四題重跑而非僅讀保存收據。沒有啟動Client／Server／Lua或部署遊戲內容。
