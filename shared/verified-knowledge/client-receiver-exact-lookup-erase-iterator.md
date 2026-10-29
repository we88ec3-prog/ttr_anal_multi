# KR Client：接收器、精確鍵查找與刪除 iterator

審核者：Codex T01 integrator；2026-10-29 Asia/Taipei。原件 KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE `.text` VA `0x401000`／raw `0x400`，本頁函式皆使用 `raw=VA-0x400C00`。

以下三項明確有界原生主張 FULL-PASS。2026-10-29 接續批次另完成 T08-158 精確來源版本的全文有界主張驗收，見文末追溯；仍不代表整個函式語意、Task、Server 或遊玩驗收。主張的機器碼、全部相關正常分支與寄存器／stack 資料流已由指定入口重解；原件 SHA 與 PE headers 獨立核對，非單純抽樣 bytes。

## CK-CLIENT-LAZY-RECEIVER-01 — FULL-PASS

`0x40F060` 的正常返回路徑固定令 `EAX=0xFAB130`，使用 plain `ret`，不彈出 caller 先推入的 DWORD。在 `0x4B3710` 的具體呼叫鏈，長度少於2時 count=0；否則 `(len-2)>>1` 個 WORD 從 buffer+2 讀取，於 `0x4B3733` 與 `0x06000000` OR、`0x4B3738` push，`0x4B3739` 呼叫 getter，再以 EAX receiver 呼叫 `0x4DFC90`；其 `ret4` 消耗這個 stack argument。

`0x40F08C` 測初始化 bit，未設時先設bit、呼叫初始化／登記函式；本結論限定其正常返回，不推論初始化無例外、執行緒安全或任何 actor 生成。`0x4DFC96` 定位 receiver+8、`0x4DFCB6` 比較 actor+88 與 stack DWORD；不替欄位或常數6填寫業務意義。

原生證據：[getter 全部可達指令](../integrations/T01-20261029-semantic-review/t08-early/native-cfg/0040f060.json)、[具體 caller](../integrations/T01-20261029-semantic-review/t08-early/native-cfg/004b3710.json)、[receiver 消費者](../integrations/T01-20261029-semantic-review/t08-early/native-cfg/004dfc90.json)。來源：原 Task T08、作者 chatgpt-web roy；`kr-temp-roy/20261028-015216-chatgpt-web-roy-T08-158-gameinfo-receiver-and-composite-key-abi.md`，Git blob `f4eeaddf48033005057a5c5a5ec78bd438b0eddd`，SHA256 `eadccf6f5a8894c6aafad7942fc5397944c007e99b488b203e6a1cfa03742b38`。

## CK-CLIENT-EXACT-TREE-LOOKUP-01 — FULL-PASS

在有效、按 unsigned DWORD key 排序的樹與合法 key 指標／輸出槽前提下，`0x82EF00` 先沿 `node+0xC >= request` 的分支取得 lower-bound candidate，隨後在 `0x82EF3B` 排除 head；`0x82EF41 cmp request,[candidate+0xC]`、`0x82EF44 jb 0x82EF55` 排除 candidate 大於 request。其餘正常路徑將 candidate 寫入 EAX 指向的輸出槽，否則寫 head。

因此在上述 invariant 下它是 exact-match-or-head，不是無等值檢查的單純 lower_bound。具體 caller `0x4DFBC0` 以 receiver+8 傳入容器、stack key 地址傳入搜尋，再比較回傳節點與 receiver+0xC sentinel。沒有證明任意損壞容器安全或上游所有 ID 都合法。

原生證據：[47條可達指令及雙出口](../integrations/T01-20261029-semantic-review/t08-early/native-cfg/0082ef00.json)、[具體 caller](../integrations/T01-20261029-semantic-review/t08-early/native-cfg/004dfbc0.json)。來源：原 Task T08、作者 chatgpt-web roy；`kr-temp-roy/20261028-013809-chatgpt-web-roy-T08-153-GameInfo-actor-erase-bulk-cleanup.md`，Git blob `10bb0608cd1dbc9cf944eab51c74d4a2fa205e1a`，SHA256 `acc9fd34490b2f97293c0eae349c2d203a34c0830e4983bb41b1497a7490bfec`。該原稿其他 ABI 措辭仍 FAILED；本條只接受獨立核對的搜尋主張。

歷史更正：`T01-20261028-12` 的 N8 漏看尾端 equality gate，不能再據此宣稱 `4DFBC0` 會刪除下一個較大 key。保留歷史原稿，不把此更正反寫為當時已驗對；[本輪裁決](../integrations/T01-20261029-semantic-review/t08-early/actor-reviews.json)。

## CK-CLIENT-ERASE-NEXT-ITERATOR-01 — FULL-PASS

在有效樹／非 sentinel 節點、各相關呼叫正常返回的前提下，`0x7B6890` 保存原節點於 `[ebp-4]`，以 `EAX=&[ebp+0x10]` 呼叫 `0x49E6A0`，先將該 stack 槽更新為 successor；接著對原節點 unlink／必要時搬接與平衡修復，原節點交 `0x89120C`，計數非零時減1。最後 `0x7B6AE0` 讀取已更新的 `[ebp+0x10]`，`0x7B6AE3` 取得第二參數輸出槽、`0x7B6AE6` 寫入 successor，令 EAX 返回輸出槽地址。

`0x4DFCE6 mov esi,[eax]` 取的是這個 successor；不能將其描述為解參照已釋放的原節點，也不能把 erase 第二參數稱為 key 值。已檢查完整223條可達指令、two-child 分支及兩側 fixup；cached Ghidra 偽碼刪去的7B6959等區段由原件 CFG補核，不以工具省略當作不可達證明。樹節點處理不等於 actor payload virtual cleanup、也不保證跨執行緒或重入安全。

原生證據：[erase完整可達 CFG](../integrations/T01-20261029-semantic-review/t08-early/native-cfg/007b6890.json)、[successor helper](../integrations/T01-20261029-semantic-review/t08-early/native-cfg/0049e6a0.json)、[接收結果 caller](../integrations/T01-20261029-semantic-review/t08-early/native-cfg/004dfc90.json)。來源：原 Task T08、作者 chatgpt-web roy；`kr-temp-roy/20261028-014315-chatgpt-web-roy-T08-155-tree-erase-node-and-container-invariants.md`，Git blob `45a6d797b4c33eabc24daf85292cdb005da39558`，SHA256 `099881b4a44e8c79188bd374f49b2cd46c560b25e8369538e9a3afe06bbf00cf`、原 Task T08、作者 chatgpt-web roy；`kr-temp-roy/20261028-015216-chatgpt-web-roy-T08-158-gameinfo-receiver-and-composite-key-abi.md`，Git blob `f4eeaddf48033005057a5c5a5ec78bd438b0eddd`，SHA256 `eadccf6f5a8894c6aafad7942fc5397944c007e99b488b203e6a1cfa03742b38`。155 的附錄指令界線錯誤與153的 ABI措辭另有退回；不提升整篇來源。

## 責任與未解範圍

2026-10-29 接續複驗：上述同一 T08-158 blob `f4eeaddf48033005057a5c5a5ec78bd438b0eddd` 的全部13項實質敘述／資料流／範圍主張及4碼塊已由 T01 integrator 核對，判為 `FULL_PASS_DOCUMENT_SCOPED`。保存 [逐項裁決](../integrations/T01-20261029-continuation-02/t08-158/review.json) 與 [重現說明](../integrations/T01-20261029-continuation-02/t08-158/README.md)。此為精確原稿的驗收進度更新；不新增或擴大本頁三項知識的適用條件，也不提升153、154、155、156等其他原稿。

Client 待逆向：所有上游封包註冊、actor+88的業務身分、未知動態 vtable、配置／例外與跨場景世代；Server 待開發：生成／移除時機、任務／勝負／獎勵規則與持久化；跨功能整合與遊玩待驗證：均未完成。以上三條不需要以官方 Server 演算法或遊戲執行證明才能成立，但不得據此補猜那些規則。
