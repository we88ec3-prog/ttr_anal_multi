# T01：T10 分支整合階段保存（依使用者要求暫停）

2026-10-30 Asia/Taipei。使用者要求「不繼續整合，請將已整合部分更新git」，因此僅發布已完成的來源收件、現有提案與T01自有通知勘誤，不繼續canonical整合。來源分支 `t10/roy/chatgpt-web` head `decc50e3c5c05bb405704df82dae06ebcf783454`；研究起始 main `e751b18922d205d86dea9f280cfd060f62752bc7`，發布前已快進同步至 `43c51f579`，保留其T16退回READY_FOR_REVIEW及開工規則更新，未接續處理T16。

## 已完成並保存

- 127份精確來源身份核對；105份原已在main，22份增量按分支blob原樣補入，共1,152,171 bytes。兩套101／102按完整路徑與blob分開；不匯入分支個人政策檔。[來源SHA與原有狀態](sources.json)、[R0動作](r0-actions.json)。
- 補登29個SRC（7個早期／REBASE、22個增量），新台帳總計391個SRC；本分支127份目前仍REGISTERED，未升CLAIMS_EXTRACTED或CONFLICT_CHECKED。
- early 49份、middle 44份的逐來源／功能提案已落盤，合計93份、40組提案；屬待整合者完成跨區去重與裁決的材料，沒有寫入正式claim台帳。late 34份尚無完整可提交提案，現有讀取helper僅保留接續工具。[early提案](early/proposal.json)、[middle提案](middle/proposal.json)、[middle檢查](middle/validation.json)。子提案的完成數僅指各自閱讀／提案階段，不能當成全分支或原生驗收完成。
- T01自有通知007／026／063的原生反證欄曾誤貼062清零時序，已依原有正確DECISIONS.md勘誤；舊錯文字與正確依據保存在[integrator-errata.json](integrator-errata.json)。退回ID、原稿SHA、NEEDS_FIX及歷史裁決不變，沒有新增作者退回。

## 未完成與剩餘

**T10 canonical整合剩127份；其中34份尚無完整提案，93份已有待裁決提案。原318版R1待萃取仍194份。** 不使用尚未執行的全量整合腳本或預期完成數；舊318篇全文判決維持3篇有界全文通過、315篇未通過。沒有新NATIVE_VERIFIED、FULL-PASS、SPEC_CONSUMABLE或S00接受，也未改claim台帳、RR／SPEC／GAP／ADR／TEST、owner／task.json／catalog及原稿。

[階段動作](actions.json)｜[階段驗證](validation.json)｜[驗證器](validate.py)

驗證涵蓋精確來源blob／SHA、未升級狀態、proposal引用／行號、歷史與Task研究正文保持，以及12組既有CI／離線合成檢查；不是原生語意或遊玩驗收。未執行／附加遊戲、未呼叫目標API或修改原件。待使用者另行要求再繼續整合。
