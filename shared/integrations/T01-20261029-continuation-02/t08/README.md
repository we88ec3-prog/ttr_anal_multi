# T08 三篇接續全文複驗

凍結基準：`fd8507169932ee9cb9d9362fcab07a5a3bd9bfa5`；審核者 Codex T01 / review_t08_new；2026-10-29 Asia/Taipei。原件為指定SHA的唯讀KR BIN，未執行／附加遊戲或呼叫目標API。

| 原稿 | 全文原生主張裁決 | 碼塊 | 組語／raw byte行 |
| --- | --- | ---: | ---: |
| T08-177 | FULL_PASS_DOCUMENT_SCOPED | 12 | 327 |
| T08-197 | FULL_PASS_DOCUMENT_SCOPED | 2 | 108 |
| T08-200 | PARTIAL_CLARIFICATION | 3 | 139 |

合計43項主張、17碼塊及574行，逐篇全文和全部碼塊均已審閱；不是延續前批少量主張後把整篇自動升級。全文pass限定原稿實際肯定的KR Client有界原生事實，不把作者明示的未知、完整函式／Task、Server政策或遊玩驗收納入。

- [逐篇結果與行號矩陣](results.json)、[完整人工資料流與碼塊裁決](MANUAL-REVIEW.md)
- [每個碼塊／每行原件核對](code-block-audit.json)、[來源blob／SHA](frozen-sources.json)
- [退回項解除提案](issue-resolution.json)、[200歧義澄清](clarification-items.json)
- [驗證結果](validation.json)、[檔案manifest](manifest.json)

177已完整修復RETURN173涉及的錯入口、ECX數值來源、所有受影響+44寫入／順序及gate/counter區分；197已完整修復RETURN196的主樹／次樹、LEA、payload清理ABI和ownership錯前提。這兩個return可由已存在且重新驗過的新作者版本解除，不要求重發相同bytes；原173／196舊blob仍FAILED。200的82EF00 lower-bound-only舊拒因仍撤銷；本輪L11「索引」為鍵域／容器的語義歧義，**沒有確證原稿錯誤，也不建立NEEDS_FIX**。

組語窗口尾端截斷、長指令續行、padding及`.byte`均有明確分類與完整原件指令，未跳過或誤當新入口。機械bytes／operands／寬度核對和完整根CFG只是人工語意裁決的依據；不是工具自動宣稱語意通過。

重現：另行提供原件（`T01_TARGET`）與既有Capstone5.0.6（`T01_CAPSTONE_ROOT`），依序執行本目錄 `capture.py`、`finalize.py`、`validate.py`。`capture.py`引用前批已提交的唯讀 `native_reader.py`，並按既存bulk索引核對函式入口；不啟動新全量Ghidra、不執行原稿腳本。所有既存證據SHA另見本批記錄。`finalize.py`序列化人工決議，不從bytes匹配自動推pass。

此子代理僅寫本目錄，未改前批、原稿、Task、catalog或Git；由整合者審核與套用通知／共用知識。
