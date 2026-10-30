# T08-170～200 原稿逐篇語意驗收

2026-10-29 Asia/Taipei；驗收者 Codex T01 / review_t08_new。31 個凍結來源版本的 SHA256、Git blob SHA、逐項主張與裁決在 [results.json](results.json)，主張原生依據在 [SEMANTIC-EVIDENCE.md](SEMANTIC-EVIDENCE.md)。原稿未改寫，Task owner、task.json、catalog 與 native_complete 均未改動。

本輪逐篇核對結果：**27 篇的列明主張矩陣有界通過；4 篇原稿確認 FAILED；原稿全文 FULL-PASS 為 0**。有界通過不是對未逐條裁決的附錄／全篇作整體升級。通過不覆蓋原稿自己保留的未知、不等於完整函式、Task、官方 Server 或遊玩完成。

| 原稿 | 裁決 | 需更正的具體內容 |
| --- | --- | --- |
| T08-173 | FAILED；後續177有明示更正 | 7B8006 的 ECX 由同函式7B7FFE固定為1，不由caller決定 |
| T08-183 | FAILED | 7B8680是hash bucket/list index節點移除，不是已證有序樹erase |
| T08-187 | FAILED | push0x30在7F6FBF；7F6FC1是保存manager的mov edi,eax |
| T08-196 | FAILED；後續197有正確區分 | 4DFC90遍歷owner+8主樹；次樹+18是另一個4DFC30函式 |

既有通知ID與新183通知草稿見 [return-items.json](return-items.json)。[T01自有勘誤](CORRECTIONS.md)不覆寫或偷換舊稿SHA；原作者修正版本仍需明確交回複驗，不能將原錯稿改判通過。

已獨立解析原件PE節區、54個相關函式/入口的CFG與關鍵caller/callee、IAT命名、字串hash/bucket與list結構、actor vtable具體個案、producer/consumer、欄位及參數資料流。實際函式數以 [entry-provenance.json](entry-provenance.json) 為準；此數量不是原生語意完成率。兩個初探中途窗口已明示拒絕為函式入口，見 [rejected-exploratory-windows.json](rejected-exploratory-windows.json)。

5,401條原稿組語byte跨度皆匹配，只是來源自洽性核對；語意裁決另外依完整相關CFG/資料流及反例，**沒有用bytes全符就判通過**。原稿可見的窗口尾端截斷指令也沒有被當成合法新指令界線。

重現需另行提供指定SHA的原始KR BIN，及Capstone5.0.6（本輪取自已安裝Ghidra debugger wheel，未安裝套件／下載／執行遊戲）。可用 `T01_TARGET`、`T01_CAPSTONE_ROOT` 指定原件與既有解壓模組位置；`review.py evidence`重驗全部原稿組語跨度，`review.py cfg 0x...`擷取可達指令，`review.py support`重建全.text E8候選、PE imports及既存Ghidra索引關聯。後者另需已保存bulk索引；這些機械工具不自動產生語意通過，人工裁決在 `finalize_reviews.py` 與結果JSON中明列。

所有正常路徑結論以有效容器與物件不變量、所呼叫者正常返回為前提。未確認之動態virtual target、失敗/異常/競爭、完整owner同源與實際網路觸發保留Client待逆向。原版Server生成政策與波次等仍屬Server待開發；未執行遊玩驗證。
