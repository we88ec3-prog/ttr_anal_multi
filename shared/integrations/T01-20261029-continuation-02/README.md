# T01 原稿全文驗收：2026-10-29 接續第02批

本批對10個精確原稿版本完成逐項處置，包含全部55個碼塊與1,717個帶位址的顯示列。**3篇在原稿明示的有界範圍內全文通過、5篇 PARTIAL、2篇 FAILED**。全文通過不代表整個函式、Task、Server 或可玩流程驗收。基準為 main `fd8507169932ee9cb9d9362fcab07a5a3bd9bfa5`，原稿與原始程式皆唯讀。

| 來源 | 本批裁決 | 依據 |
| --- | --- | --- |
| T08-158 | FULL_PASS_DOCUMENT_SCOPED | [13項主張、4碼塊、116顯示列](t08-158/README.md) |
| T08-177、197 | FULL_PASS_DOCUMENT_SCOPED | [全文資料流、14碼塊、435顯示列](t08/MANUAL-REVIEW.md) |
| T08-200 | PARTIAL | 同一 owner+8 樹的不同 key／predicate 已核對；「不是同一索引」措辭需澄清，沒有新增確證錯誤退回 |
| T10-053、055、056 | PARTIAL | [14碼塊、648列](t10/README.md)；核心主張支持，錯位視窗頭與泛稱確認的範圍須限定 |
| T16-69 | PARTIAL／NEEDS_QUALIFICATION | [完整主張矩陣](t16/README.md)；A0A4 不應確稱佇列筆數 |
| T16-70、71 | FAILED | framer／connection 基準、標題、vtable raw 及指令座標等具體更正；三篇合計20碼塊、379列 |

T08 三篇合計574顯示列；其中200為139列。表內全部數字是審閱覆蓋量，不是通過比例或遊戲驗收結果。來源作者的時間、工具使用及研究輪次只保留為歷史自述，不冒充原生事實。

## 整合與退回

- [318版來源台帳](source-ledger.json)：全文有界通過3、FAILED71、PARTIAL151、SOURCE_ONLY9、PENDING84。承接前批精確版本，其他308篇不重新裁決；未宣稱318篇完成。[本批10版](reviewed-sources.json) 保存來源SHA、blob與決議。
- [10項新退回](return-notices.json)：T10兩項證據範圍限定，T16八項更正／限定，已寫入來源 Task README 退回專區。未修改其他 Task 的研究正文、task.json、owner 或 catalog。
- T08 RETURN173、196 分別以修正版177、197解除；舊173／196的原稿仍FAILED。[修復逐項對應](t08/issue-resolution.json)；未要求作者重發已存在且內容正確的修正版。
- [兩項新增正式共用知識](../../verified-knowledge/client-mode-gates-and-secondary-key-removal.md)：集合模式 gate、次級鍵移除；另為既有 getter／erase 知識補158全文驗收追溯。正式條目共7項，仍按功能與資料結構檢索。

## 驗證與接續

[validation.json](validation.json) 記錄重跑結果，[files-manifest.json](files-manifest.json) 記錄本批精確bytes／SHA。[verify.py](verify.py) 核對318個原稿SHA／blob、10版台帳、README通知唯一性及Task正文／catalog／owner保持；它不產生原生語意裁決。各子目錄有原件重解與完整碼塊重跑腳本，需另備指定SHA原BIN與Capstone。未附遊戲執行檔。

儲存庫檢查通過；598筆歷史外部引用仍未閉合，Client native evidence 與遊玩未完成。T16勘誤diff只是待原作者採用的提案，未套用到原稿。實際提交／推送狀態見 [push-receipt.json](push-receipt.json)。接續待辦見 [NEXT-STEPS.md](NEXT-STEPS.md)。
