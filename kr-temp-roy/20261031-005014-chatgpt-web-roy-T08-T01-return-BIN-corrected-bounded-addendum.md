# T08 T01 退回項：2026-10-31 KR BIN 定向勘誤（有界增補）
研究者 chatgpt-web roy。來源 KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes。PE .text VA 0x401000 / raw 0x400，因此所列 .text raw=VA-0x400C00；**.rdata 或絕對 vtable pointer 不適用同一換算**。本件為從原 BIN 重核的有限窗口勘誤，不取代既存完整原稿；未完成 T01 全文複驗，狀態仍由 T01 README 與審核者判斷。

## NEEDS_FIX 與已重核的原生反證

| 退回 | 有界原生勘誤與正確含義 | T01 尚待項目 |
|---|---|---|
| T08-153-ABI-001 | `4DFBC9 lea eax,[ebp+8]` 把 key 地址交 `82EF00`；找到節點後 `4DFC19 lea ecx,[ebp+8]` 再以同一 stack slot 地址交 `7B6890`，此處是 **next_iterator output slot**，不是原搜尋 key 的值。callee `7B6AE3..E6` 填入 successor。 | 修正版受影響全文核對 |
| T08-155-ASM-001 | 從 `7B6890` 有效入口重解 two-child relocation；`7B698E: 89 41 04 = mov [ecx+4],eax`；`7B6991: EB 0E = jmp 7B69A1`。不得從 7B698F/90/92 作獨立指令起點。 | 整個受影響 CFG 與全文語義複驗 |
| T08-157-001 | `4B297A: 3B 05 3C B1 FA 00` 是6-byte `cmp eax,[0xFAB13C]`；`4B2980: 74 07` 是 `je 4B2989`；`4B2982: 8B 70 10` 是 `mov esi,[eax+0x10]`。`4B297C` 是 displacement 內部而非指令。 | 指定命令26之完整受影響 dataflow |
| T08-183-001 | `7B8680` 是 **string hash/mask→bucket/list unlink**；`7B868B..7B86AC` 為索引運算；`7B86DE` 取 `&index+4`，`719B20` 解雙向 list links/釋放節點，非 ordered-tree rotation。不得與 Actor RB tree `7B6890` 混同。 | 舊183其他衍生容器主張全部重核 |
| T08-187-001 | `7F6FBA` call `7B8180`；`7F6FBF: 6A 30` 才是 push 0x30；`7F6FC1: 8B F8` 是 mov edi,eax 保存 **manager**，非配置大小；`7F6FC8 mov esi,eax` 為 wrapper，null edge 跳 `7F7021`；有效路 `7F6FDB push edi; 7F6FDC call 7DCFB0`，`7F700B mov [esi+0x2C],eax` 保存 acquire 結果。 | 檢查整個 wrapper/acquire/釋放語義 |
| T08-LEGACY-MAPPING-001 | 舊 T08-129～152 共24篇 source-coordinate 原生退回；T01 裁決其中18篇、1263條已存 bytes 於「舊標示VA-0x400」對照吻合。這**不是全 PE rebase**；不得把資料節絕對值也位移，也不表示24篇衍生函式/ABI/型別主張已恢復正確。 | 24篇逐篇保留原稿、從真PE入口重新生成 CFG、source SHA 與語義修訂；仍 NEEDS_FIX |

## 已由 T01 結案、不再退回
- `T08-173-001`：`T08-177` 修正版經限定全文複驗 RESOLVED；原173歷史 FAILED。
- `T08-196-001`：`T08-197` 修正版經限定全文複驗 RESOLVED；原196歷史 FAILED。

## 外部既有已驗有界主張（引用，不重新創造 FULL-PASS）
`shared/verified-knowledge/client-receiver-exact-lookup-erase-iterator.md` 已由 T01 確認 `40F060` getter、`82EF00` exact match、`7B6890` iterator output 等限定子主張。該頁不等於 T08-153/155 舊來源全文驗收。

## 研究／驗收狀態
本增補具實際 machine bytes、有效 instruction boundary、stack alias 與 caller/callee 支持，但**不是24份legacy source全文修復，也未改Task README或任何 T01 狀態**。本機另有本輪完整組語窗口版（30,780 bytes）與完整 T08-201 檔，未因這份遠端摘要而視為上傳成功。下一步需以全套原稿精確版本正式送 T01 審核；無FULL-PASS宣稱。

參考：`kr/tasks/T08/README.md` T01退回；`shared/integrations/T01-20261029-semantic-review/t08-early/{actor-reviews.json,mapping-reviews.json}`；`shared/integrations/T01-20261029-semantic-review/t08-new/return-items.json`。
