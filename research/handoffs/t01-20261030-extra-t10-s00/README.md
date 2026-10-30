# T01 → S00：extra/roy1 E61–E69 + T10 93 篇有界驗收交接

2026-10-30 Asia/Taipei；原 main `94899b7bf99228215073d4c524773e4cdc7283bf`。**T01 有界 R0–R2 驗收可交付 S00 研究；沒有 R3 FULL-PASS，沒有 S00 RR ACCEPTED／SPEC STABLE／可玩。**

## R0 精確來源
已將 extra/roy1 八篇 E61–E67、E69 原稿原 blob 納入 main（未改正文）。完整路徑、40 位 Git blob SHA、64 位 UTF-8 SHA256 和 SRC-0475～0482 見 [證據矩陣](s00-evidence-matrix.json)；E68 已在 SRC-0474，未重複。E64 內含 E63 原生附錄，重複內容不能視為兩個獨立實證。

T10 early 49／middle 44 來源全文早已在 main；以 [early](../t01-t10-roy-20261029/early/proposal.json) 和 [middle](../t01-t10-roy-20261029/middle/proposal.json) 逐來源提案及 [sources](../t01-t10-roy-20261029/sources.json) 對照：93/93 SRC/blob/已登錄 SHA 一致、383/383 source-line 區間合法；並不表示重新取得 93 篇全文重算雜湊或逐行機器碼審核。40 組 R1 提案合併／隔離為 30 研究桶：27 項新 PARTIAL/UNKNOWN T10 CLM，一項重用 CLM-CLIENT-0030，兩組 REFUTED（T10-062/063）隔離。這是**有限 source-level CONFLICT_CHECKED**，不是原稿 FULL-PASS。T10-107 SRC-0370 僅為合併索引，維持 REGISTERED。

## R1 裁決與 R2 原生來源
extra 既有 CHAR／SCENE／AUTH 主張精確追加來源；新 CLM-SCENE-0007 僅描述 S2C69 subtype7→CSquare→條件式 C2S43 local 4-byte `43 00 XX 0A`，新 CLM-AUTH-0006 僅描述 E8 len112／000F len214、兩條 local manager selector1、E8 outgoing CP_ACP 與可見的 tail-word offset。**不**推得原版 C2S42→S2C69 success/error 配對或原版 Server 帳密策略。

對原始 KR BIN 12,472,320 bytes SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 唯讀重跑：84/84 focused byte/E8/vptr checks PASS；另一組 71 個指令 asserts、9 RTTI、14 native 窗口 PASS（有交集，不能相加成獨立事實）。PE image base 0x400000；.text raw=VA−0x400C00，.rdata raw=VA−0x401A00。可回查 original source full disassembly。
關鍵地址：`4A32B6/4A32C4`、`4A34FC/4A3505`（AUTH selector1）；`4A33B5/4A33C5`（E8 tail offset +110）；`4A3455/3475/34AA/34C8`（E8 WCTMB CP_ACP）；`4C3821/3949/4C3A10`（S2C13 status/group）；`4B90C1/4B90FD`、`C06FB0+10=4BBC10`、`4BBE60..4BBEAF`（Square→C2S43）；`4914B1→6D1480`、`6D193E`、`6D19F2`（FB9004 phase writer/override）；`545A70/545AA1/545AC8/545ADB/545B10`（RowB R+E4/B0 反證）。

## 交付／禁止升級
- **T01 有界來源與主張整合：PASS，S00 可以開始分析**；R3 FULL-PASS 未核可。93 T10 claims 僅供研究導航，不是 gameplay Server MUST。
- **RR-0002 BLOCKED**：官方選角成功/失敗 S2C 身分、欄位、因果及真正 trace 未證；需可信原版捕獲／Server source／Client 正向 writer 新證據。RR-0003、RR-0008 仍 IN_REVIEW。
- T10-116 普遍化 row[4]=R+B0 有原生反例，固定 NEEDS_FIX 保留；T10-062/063 既有反證不能轉正；override producer 與 motion→Server 閉環未知。
- 不修改 RR/SPEC/GAP/TEST、其他 Task owner/原稿、historical FULL-PASS、`shared/verified-knowledge`。本批沒有原版 Client 執行、遊戲連線或 Server 實測。

相關：[T01 R0–R3 流程](../../../governance/t01-integration-workflow.md) · [來源 SRC](../../intake/index.json) · [有限 CLM](../../claims/index.json) · [RR 權威](../../requests/index.json)。
