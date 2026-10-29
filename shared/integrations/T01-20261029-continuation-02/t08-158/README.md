# T08-158 精確原稿版本全文驗收

裁決：**FULL_PASS_DOCUMENT_SCOPED**。這表示本原稿全部實質肯定的有界原生主張及四個碼塊均已核對，不代表完整函式、Task、官方Server、遊戲可玩或執行時驗收。

原稿179行，Git blob `f4eeaddf48033005057a5c5a5ec78bd438b0eddd`，其他版本識別以 [review.json](review.json) 的完整值為準；固定來源路徑／SHA沒有替換。審核者：Codex T01 integrator，2026-10-29 Asia/Taipei。

- 原件完整SHA與PE映射獨立核對，沒有使用啟動器／TC或修改後檔案。
- 四碼塊完整列出來源行號與內容SHA：getter、複合DWORD caller、條件移除、限定C++示意。116個帶位址的顯示列區分113條指令與3條續行；末端ret顯示省略的位元組由完整根CFG確認，不誤判為新指令。
- 13項敘述／資料流／範圍矩陣覆蓋所有實質主張。`40F060` 的29條可達指令、`4B3710` 的28條、`4DFC90` 的64條，以及erase／successor／初始化的必要關聯均保存於 `native-cfg/`。
- getter以EBP還原ESP後plain ret，因此caller先push的DWORD仍在；正常返回EAX固定為FAB130。下一個`4DFC90 ret4`消耗該參數，沒有對key作轉換。
- CPP示意的長度門檻對應完整caller入口：len0/1/2/3零筆、4/5一筆，其後每兩byte一筆；奇數尾byte不納入。它不聲稱正式native函式簽名或可部署原碼。
- receiver+8、actor+88 DWORD predicate、匹配與非匹配的迭代、擦除前取得successor與輸出slot均經根CFG查核。欄位業務意義、網路opcode、動態vtable實作、例外／並行與任意壞容器沒有被冒稱已確認。

本篇對154/156的更正僅限getter不是key converter，不能據此把154/156整篇改為SUPERSEDED或FULL-PASS。既有原稿均保留。
