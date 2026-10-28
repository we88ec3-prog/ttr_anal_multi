# T01 歷史研究統一索引：非 FULL-PASS 導覽

日期：2026-10-28（Asia/Taipei）。範圍：GitHub `main` 內四批 `accepted-claims.json`、`shared/source-review-status.json` 與 T01 歷史 `local-items.json`／`online-items.json`。本報告僅整合歷史資料，不作新逆向或提升任何驗證狀態。

## 交付與可重現核對

- [CLAIM-SOURCE-EDGES.csv](CLAIM-SOURCE-EDGES.csv)：**437** 條 Claim → 來源引用，包含原 Task、歷史 verdict、來源 SHA256、正式 evidence 路徑、整合來源清單與歷史 Claim 檔 Git blob SHA。來源檔案 Git blob SHA 欄位若未獨立取得則留空，**來源 SHA256 不可冒充 blob SHA**。
- [HISTORICAL-CLAIMS.json](HISTORICAL-CLAIMS.json)：**115** 筆原文主張、來源、條件／限制、證據 ID，保留舊判定。
- [FUNCTIONAL-NAVIGATION.json](FUNCTIONAL-NAVIGATION.json)：以協定、場景旅行、角色 UI、actor 資源生命週期、移動輸入、戰鬥狀態、任務 Lua、資料格式、Server／unknown 橫向查找。標籤為 **文字關鍵詞導航，不是新的語意驗證**，可多重歸類；未被規則分類的原始 Claim 仍在總索引中。
- 總計 **334** 個不同來源路徑；`source-review-status` 對應 **252** 個；其他 **82** 個由歷史 local-items 正式保存清單補齊。每條正式 evidence 路徑及 SHA256 非空。
- GitHub 遠端讀回：CSV **437** 條、JSON **115** 筆；檔案 Git blob SHA：CSV `f9121b0e4b61bb0b5dbdca916ae9a8b9677ab5a3`，Claim JSON `d5fd2dc1a4b96dfb1ffc9d6bf8c9a237479d8626`。

### 歷史分類分布（不能當 FULL-PASS）

| 原歷史 verdict | Claim 數 |
| --- | ---: |
| 部分確認 | 94 |
| 原生已確認 | 6 |
| 資訊缺失 | 11 |
| AI 替代 | 3 |
| 待補充開發 | 1 |
| 合計 | **115** |

**正式 FULL-PASS：0**。不得因這個導覽或本批來源完整性核對而提升任何原生語意結論。現行正式入口仍為 [verified-knowledge](../../verified-knowledge/README.md)，本目錄是帶明確標記的歷史非 FULL-PASS 導覽。

## 2026-10-26 早期 42 筆新增結論：刻意不做假去重

`T01-20261026-01/README.md` 可確定當批整合共新增 **42** 筆結論（另有 2 筆更正），分類為 11 原生已確認、21 部分確認、5 AI 替代、3 資訊缺失、1 待補充開發、1 使用者記憶待原生核對。然而 `T01-20261026-01/accepted-claims.json` 不存在，當批已查 `local-items.json`、`resolutions.json`、`checkpoint.json`、`validation.json` 也不足以在這次索引中逐筆重建全部 42 項與四批 115 項的精確同一性。

**決議：**保留 42 筆為「歷史批次層級、逐筆去重不可判定」的獨立待銜接紀錄。不可把 42+115 宣稱為 157 條獨立結論；不得藉推論合併、刪除或改寫歷史 verdict。若日後取得凍結時的 claim ID／原 catalog 增量及其 SHA，再執行正式對照。

## 來源與版本範圍

四批 Claims 檔的 Git blob SHA：
- `20261027-03`: `87f73c706b4cc1f2b629b8a95c142444e93610d3`
- `20261027-04`: `4d7963ee156255a4e8a33c224e952e232741b31c`
- `20261027-05`: `f65ab5090df94887bf5084ad8ebdc2c2917ae2fa`
- `20261028-06`: `a9dd589d97c9c8ac1e1daf63efc2427b65332c79`

`source-review-status.json` blob：`85d93a86b928028494be218581db558250eb427a`。
local mapping blobs：`03` `321813076ec41cdeddae5e7bbecaf398093ac553`；`04` `87cb8ee3ff3027963c7b4077e920dace909ef1e2`；`06` `b5035314cc0f859abbd654d634085efe8f881611`。在線來源等額外清單只作補充，不改核心計數。

## 工作狀態及四種缺口

- **Client 待逆向**：未知封包格式、接收／回傳條件、場景／角色 UI／事件 callback 等尚需明確原始證據的部分。
- **Server 待開發**：官方 Server 內部的任務條件、勝負／獎勵、持久化與 exactly-once 等無法僅由 Client 推定的政策。
- **跨功能整合**：已知有界路徑之間的跨 scene、角色、任務、操作時序與恢復連結。
- **遊玩待驗證**：進入流程、重登、任務完成、返回與重複互動的執行證據。
- **來源審核待深化**：局部 bytes、驗證器通過、source-only 保存、歷史原生已確認並不滿足新政策第二節 FULL-PASS。須精確限定 KR／TC 來源、PE/VA/raw、CFG、caller/callee、衝突、原稿 blob SHA、審核者及決議。

## 不變項

未改 `shared/catalog.json`、任何 Task owner／task.json、歷史 claim、source-review-status、T08 的五筆正式退回事項及任何來源原稿。不把 KR 位址套用 TC，不把 AI／fixture 當原生；不執行／附加遊戲。

本次把**索引整理**交付完成，但不是「所有研究主張完成驗證」；早期 42 筆逐筆去重、來源 Git blob 全量確認、更多 FULL-PASS 複驗屬明確仍未完成的後續工作。
