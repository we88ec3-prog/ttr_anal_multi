# T16 任務與劇情流程（Quest & Story Progression）— KR

<!-- S00-DISPATCH-BOOTSTRAP:v1 -->
## S00 研究請求開工檢查（正式）

**每次開工必讀**：確認最新 origin/main SHA，先檢查本 README 的 T01 驗收退回與既有主責，再讀 [T16 S00 收件箱](../../../research/dispatch/inbox/T16.md)、[唯一 RR 台帳](../../../research/requests/index.json)、[派工／認領／回報規則](../../../research/dispatch/README.md)。先處理已指派且獲使用者授權的 P0/P1；只在認領變更發布於 main 後才算跨 Agent 已認領。完成研究需提交 Markdown + 精確 Git blob SHA 並更新 RR 為 SUBMITTED，S00 才能結案。**收件箱不會自動喚醒本 Agent**；不變更原有 Task owner、原稿及 T01 退回規則。


## T01 驗收退回事項

**T16 作者送審更新（2026-10-29）：下列 43 筆已依 `AGENTS.md` 提交獨立勘誤及原生補證，全部置為 `READY_FOR_REVIEW` 供 T01 審查；此舉不代表驗收成功。** [查看 43 筆送審表](T01-RETURNS-READY-FOR-REVIEW-20261029.md)。


#### T01-RETURN-T16-117-Q16-MODE2-C2S36-001 — RESOLVED
- **T01 限定複驗 2026-10-30：**作者勘誤 `kr-temp-roy/T16-T01-returns-20261030/errata/T16-117-Q16-MODE2-C2S36-T01-erratum.md`，Git blob `1c5efb4a0bfd07c7fbdf2bb1fcc48c4386c4f2ba`。BIN 8/8 slice SHA256 及 mode1→F4402（636BD6/636BFF）、F4402 action gate（636DF8）、+88 record pointer（636E7C/82）、+80 QuestID、4B3510 獨立 0x36 producer 核對成立；原稿117舊版保留、`CLM-QUEST-0007 REFUTED` 保留。**僅結案此固定退回，非117全文FULL-PASS或mode2 actual submit已證。**[T01 審核](../../../research/handoffs/t01-20261030-t16-quest15-quest16-bounded/README.md)。
- 原稿：`kr-temp-roy/20261030-034517-chatgpt-web-roy-T16-117-KR-Quest14-study5-Quest16-type2-unlock-UI-C2S-S2C.md`；Git blob `388b9100362ed43ec65ba1f7504f73518dce5d44`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；保留原文。
- 誤主張：T16-117 D.1/D.3 將 mode1～3 的 UI 動作一概視為 F4402→0x636E10→0x36,QID16，並以 TalkBox+0x88 當 QuestID。
- 原始反證：0x636BD6 `cmp eax,1` 才沿 mode1 寫 0x636BFF action F4402；0x636DF8 的 action==F4402 gate 才 call 0x636E10；0x636E82 使用 `WORD*([TalkBox+0x88])`，QuestID +0x80 是另一欄位。0x4B3510 為獨立 0x36 producer，不得推論 mode2 永遠不發 0x36。
- 後續更正來源：T16-121 blob `e5d48e09ac8604ac39ce0dc584bb20308d927b54`、T16-122 blob `d056bb2d0ff4ee136e13f2ff8c034434a61b2d87` 已明示合理的限定路徑，但未成作者針對117的正式 erratum。
- 修復與完成條件：T16 作者保留117舊稿，提供明確指名 D.1/D.3 及下游引用之勘誤、新 Git blob 與反證差異，將本固定 ID 標 `READY_FOR_REVIEW`；T01 複驗後才可改 `RESOLVED`。此前本 ID 為 NEEDS_FIX，不影響已結案43筆。
- T01 來源：[正式整合報告](../../../research/handoffs/t01-20261030-quest16-r0-r2/README.md)；僅針對本精確主張，非整篇 FULL-PASS 或 RR/S00 接受。

<!-- T01-continuation-02-notices:start -->

### 2026-10-29 接續第02批複驗

逐篇主張與全部碼塊已核對；以下限定需修正的內容，保留其他獨立支持的結論。

#### T01-RETURN-T16-069-CONT02-C11 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：A0A4/A078 修正已按完整局部 producer/consumer 原生指令重新確認。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-170434-chatgpt-web-roy-T16-69-KR-virtual-dispatch-and-outbound-queue.md`；Git blob `2f5c65062c7ab82453dfa726019e4d5e2bf0a0dc`；SHA256 `0c0387cc78d2124f788e103344f16f1ec40bfd5c6084aa4e27c59ac27208971c`。
- 問題：Scenario matrix calls the A0A4 gate a queue-count gate
- 原生依據：Actual list element count isA078 (+1 onenqueue,-1 ondrain).A0A4 is a different field:804A40 updatesit±5 orresets0 basedondrainstatus. SourceL19 itself leavesA0A4 semantics provisional. Replace the definite queue-count label with signedfieldA0A4>300 gate; retainunknownbusinessmeaning.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-069-T01-erratum.md)；勘誤 Git blob `f6a35543d5f74c1ac01d05aff2cfc4cd11548a24`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-070-CONT02-C06 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x807A8F marker 存 [ebp-2]、0x807A93 len 存 [ebp-4]，0x807AE2/807AE9 複製 DWORD，header 為 LE16(len)+LE16(1A68)。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 問題：Section1.2 heading gives marker first and length second
- 原生依據：807A8F stores1A68 to[ebp-2],807A93 storeslength to[ebp-4];807AE2 loadsDWORDfrom[ebp-4],807AE9 copiesheader. ThereforefirstWORD length,secondmarker, as sourceL52/L74 already show.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-070-T01-erratum.md)；勘誤 Git blob `119fcf1501ddab652c57de9552527adebb97e36c`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-070-CONT02-C09 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x80620C/0x806234 以 connection+501C 為 stream 基準；callee+5004/+500C 即 connection+A020/+A028，buffer 始於 connection+5020。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 問題：Connection-relative buffer offsets5004/500C
- 原生依據：80620C passes ECX=connection+501C to807830;806234 passes EDI=connection+501C to807A70. Thuscallee+5004 isconnection+A020 writepointer,andcallee+500C isconnection+A028 bufferedlength. Bufferstarts connection+5020. Source uses stream-relative offsets while callingthebaseconnection.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-070-T01-erratum.md)；勘誤 Git blob `119fcf1501ddab652c57de9552527adebb97e36c`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-070-CONT02-C13 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x807BD8 BA33260000 為 mov edx,2633；0x807BDD C744242004000000 為 mov [esp+20],4。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 問題：Receive ASM block wrong coordinate for mov edx,2633
- 原生依據：L116at807BDD actuallyC744242004000000 movdword[esp+20],4. CorrectBA33260000 mov edx,2633 is807BD8. Allother18rows inthisblockmatchactualinstructions; rootedCFG hasnooverlap.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-070-T01-erratum.md)；勘誤 Git blob `119fcf1501ddab652c57de9552527adebb97e36c`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-071-CONT02-C05 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x8068F3 push EAX 對應 OVERLAPPED conn+A050；0x8068F7 ECX=EAX+14；0x806909 push ECX 是 WSABUF conn+A064。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 問題：806909 pushECX comment namesLPWSAOVERLAPPED
- 原生依據：ECX=EAX+14 at8068F7,whereEAX=conn+A050; thus806909 pushesWSABUF atconn+A064. ActualOVERLAPPED conn+A050 waspushedasEAXat8068F3. OriginalopcodepushECXiscorrect; onlyAPIargumentlabelwrong.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-071-T01-erratum.md)；勘誤 Git blob `bd4d9f45dd428e8d9a12affd7ce465aebbe7054d`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-071-CONT02-C06 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x806958 pop EDI；0x806959 pop ESI；0x80695A 33C0 xor EAX,EAX，保留原有錯誤回傳 0 行為。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 問題：Errorresult-zero instruction coordinate
- 原生依據：806958 is5F popEDI;806959 is5E popESI;80695A is33C0 xorEAX,EAX. Return0 behavior survives butliteraladdressmustchange.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-071-T01-erratum.md)；勘誤 Git blob `bd4d9f45dd428e8d9a12affd7ce465aebbe7054d`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-071-CONT02-C08 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；PE .rdata VA BD2000/raw 7D0600；vtable C51748→raw 84FD48，11 slots，其 +0x10 槽為 8069A0。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 問題：C51748 vtable raw852D48
- 原生依據：Parsed.rdata startsVA BD2000/raw7D0600; C51748−BD2000+7D0600=84FD48. Snapshotatwrong852D48differsfrom11vtableentries. Correctmappingalreadyappearsin69. PEdataartifactincludesbothwindows.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-071-T01-erratum.md)；勘誤 Git blob `bd4d9f45dd428e8d9a12affd7ce465aebbe7054d`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-071-CONT02-C14 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x807DAB 8BF8 mov edi,eax；0x807DAD E8EEC2FFFF call 8040A0；舊重複 ellipsis 不是 ASM 指令。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 問題：807DAD movEDI,EAX
- 原生依據：CorrectmovEDI,EAXis807DABbytes8BF8;807DADbytesE8EEC2FFFFiscall8040A0. Duplicateellipsisnextlineisplaceholder,notanadditionalinstruction. Bothsitesaretrueinstructionboundaries,notmis-decoderinteriors.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-071-T01-erratum.md)；勘誤 Git blob `bd4d9f45dd428e8d9a12affd7ce465aebbe7054d`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

<!-- T01-continuation-02-notices:end -->


<!-- T01-20261029-stage-notices:start -->

### 2026-10-29 階段複驗通知（35筆具體更正，既有ID原位補充）

本次僅通知已證實的錯誤；原稿全文驗收仍未完成。保留原稿，提供獨立修正版及新 blob/SHA；複驗通過前維持 NEEDS_FIX，不能將局部主張支持算作全文 FULL-PASS。

[本批總台帳](../../../shared/integrations/T01-20261029-semantic-review/README.md)；[機器可讀退回紀錄](../../../shared/integrations/T01-20261029-semantic-review/return-notices.json)。

#### T01-RETURN-T16-002-9c70bd9f — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x6F4A94 ESI=1；缺檔跳轉 0x6F4BCF，0x6F4C07 EAX=ESI；成功解析時以 ESI=0。修正 C++ 偽碼的 raw-status 極性。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-012719-chatgpt-web-roy-T16-2-KR-Lua-dispatch-and-quest-fields.md`；Git blob `c3c7a7efc3b1aed44d9bb3187e652ba3638ae595`；SHA256 `59c8a07618e363bfc9f863d233208c124d6b493b1944c9d93fb0aeb2247a720f`。
- 問題：Native return polarity is inverted in conceptual pseudocode
- 原生反證：6F4A94 initializes ESI=1; absent resource reaches 6F4BCF and returns EAX=ESI. Normal parse success sets ESI=0.
- 修正及複驗條件：Represent zero-success/nonzero-failure native status. Do not use false to represent missing-file return without an explicit inversion wrapper.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-002-T01-erratum.md)；勘誤 Git blob `e214f68a0c0dfd02f64f1bb3cdb441b048f4a8d8`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-005-82389c1b — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x53FEB0 根函式 44 條連續可解碼指令、7 個直接分支目標均為指令起點；0x53FECF 非空轉換值，0x53FF0E 始終用 [ESI+40] 走原節點。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-014323-chatgpt-web-roy-T16-5-KR-child-parser-vector.md`；Git blob `ae3dec4d3e612e2b20e31db54b6425602786c615`；SHA256 `2d9e7779ff5368f496f21062369b4a642de9bb6957f71f2b0f017538769a7105`。
- 問題：Pseudocode advances the callback result instead of the original Shout node
- 原生反證：ESI retains original node; virtual +14 result is EAX; next iteration reads [ESI+40]. Null callback result skips append.
- 修正及複驗條件：Maintain original-node iterator separately from converted callback result and preserve null-result branch.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-005-T01-erratum.md)；勘誤 Git blob `e415707cc217a3d8d363240b14fa72b2dd97c60d`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-013-36353f64 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；0x8438C0 根函式 47 條連續可解碼指令、6 個直接分支目標均為指令起點，雙 ret4；0x843901 signed cmp key,[best+C]，0x843904 jl 0x843915 排除 key<best。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-020402-chatgpt-web-roy-T16-13-KR-tree-lookup-ABI.md`；Git blob `b5ea5e5ed5312c287f2051b1db6ed3326c44be9c`；SHA256 `ee0226360ca0ccc934993efe8874dd5c166bdc48d7f478bfa21910e5a33a2a93`。
- 問題：Final signed tree inequality is reversed
- 原生反證：843901 cmp esi,[edx+C]; 843904 jl sentinel. ESI is search key. Lower-bound best >= key; absent key5 with candidate7 must return sentinel.
- 修正及複驗條件：Return head if best==head or key<best.key. Preserve signed comparison and calling convention.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-013-T01-erratum.md)；勘誤 Git blob `ab33b55d09a87b73d7b9ab2b062b04821b65d36d`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-045-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-101028-chatgpt-web-roy-T16-45-KR-Lua-XML-source-and-BIN-validation.md`；Git blob `8067059908d888141c8d7b4a12b80eb6b427e49c`；SHA256 `52c9551a807dd347c184b4a9adf044a02d575d0d665870d96756fe35321042c2`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-045-T01-erratum.md)；勘誤 Git blob `81325624253d6b6eca19da064a69cd992b021f31`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-046-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md`；Git blob `dea68e6db1af124ecdaca7943a877a7dbddd2377`；SHA256 `25246ae4a95c7837343206e9ff957831dd8c7e0d5e65248d3d63d306cb1a6545`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-046-T01-erratum.md)；勘誤 Git blob `13438858f2bfd5e96ed01bb4b6e412dd0a5df9c7`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-048-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-48-KR-quest-authority-validation-matrix.md`；Git blob `e4633cecbb8531a950a4d15f24d7db5ae4fd6529`；SHA256 `6f93462118e51cd370df8241aba523eb4678105641ae4b3790a601c1cbc39641`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-048-T01-erratum.md)；勘誤 Git blob `4843fe5ebe9bcc164c6a69b25fd351ad5f0ef6f1`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-049-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-49-KR-resource-provenance-pe-audit.md`；Git blob `0df285c934581b93bb2339320a2c8a6e69772675`；SHA256 `524227b0093f7ad4c4d9ea591424b21df329a598e3f9a9be8068baf827de5549`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-049-T01-erratum.md)；勘誤 Git blob `7da5eb9c3b73bbedf16bcd8c2719fa136857932a`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-052-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-52-KR-quest-authority-handoff.md`；Git blob `84e4f83eff35ed0c0da23880fe54553bd065b2ef`；SHA256 `f37d39303baf9cd94ef8e80d3a32e03a51f4cfeccf87e734495a759edaa397bd`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-052-T01-erratum.md)；勘誤 Git blob `a022e26fd25a59a73299b31f4462f51fe7d0027a`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-054-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-54-KR-tutorial-lua-direct-call-xrefs.md`；Git blob `319c873eab18f80db3c464df38b51ab396dc80a7`；SHA256 `74bbb543328f7f521d716a6e895c17cb6b7e924cae4ee2ea6ff9deb3643e69b9`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-054-T01-erratum.md)；勘誤 Git blob `1fad5020431f41f54d8296519c00def97c1aadac`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-056-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-56-KR-authority-gap-next-contract.md`；Git blob `f6c7a0bb219c11c561e6463a7ae121bf6a41b4f2`；SHA256 `45a4b69a6190d4c3f5dfb324104433afd690e6303b25adcdfd6e0b48726674c8`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-056-T01-erratum.md)；勘誤 Git blob `4980478272dfb650daebe4fc4471b356a17bc814`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-060-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-60-KR-Quest16-Quest15-native-proof-matrix.md`；Git blob `b91b766bbfd2272dae446c428c600ccaeaec1fa7`；SHA256 `9e56eb03747e290d564623f8abd42b2ac5031591cf03303375e6b7f35d2ed226`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-060-T01-erratum.md)；勘誤 Git blob `342d92b1fa3dc4c90e06d3a8c45a8b80a41afb21`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-061-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-61-KR-scenario-lua-callback-argument-marshal.md`；Git blob `d8877384dd938cab6421c67fcc62f451d196ccd5`；SHA256 `3e3f518fdb983cab445ab75a6b4e698a79723cf2a57b871a22d7fea193d9a43e`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-061-T01-erratum.md)；勘誤 Git blob `d89fc3f116186c2b8cdf262416e525396eef2778`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-062-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-62-KR-quest-xml-node-consumer-callgraph.md`；Git blob `e9b16c654215aa1567cb66571d721c1ab01eea97`；SHA256 `56139bdcb333f02b609dadc7aa45cb18f3a0f4d6b818e5f6bf4494a6272585ed`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-062-T01-erratum.md)；勘誤 Git blob `f0c0ea584cc85a2e7635830d3bdc2749b6c1a102`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-063-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-63-KR-quest-readers-and-data-lifecycle.md`；Git blob `26c595c295093777a7153426a16757b11eacec19`；SHA256 `02fe48ceb6de16e34edad6699c24680f30f7c29d556a5fd481e7c20e7deab846`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-063-T01-erratum.md)；勘誤 Git blob `317b498a2dc78ce67a238d095ccc4b1d26f55c71`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-064-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-64-KR-end-to-end-quest16-quest15-evidence-gates.md`；Git blob `dee3295e7cdde882aae96b277d224160420608c8`；SHA256 `84ff514e4b9198f465c451d0c44917e7f5c0d730a2bc50bb20afda5a60fe57f7`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-064-T01-erratum.md)；勘誤 Git blob `1b5575a25f87c4d8eeb1da93cffe9b6b815399f7`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-067-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-67-KR-scenario-dispatch-state-versus-quest.md`；Git blob `21e9facd60a283e4b9f097937b98b91defbdb53e`；SHA256 `9e8ba04b64205c6126a1ef58434df5d0984b05a0a9e35ae46e207ded11f480a0`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-067-T01-erratum.md)；勘誤 Git blob `861c5d0f238aae3f3c26a852e0622dfdbd526abb`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-068-89ddf3e8 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 56-hex SHA 已由作者 erratum 更正，T01 直接由已上傳 Event.stp 重建 member 並核對。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-68-KR-quest16-quest15-native-handoff.md`；Git blob `158ceaa7b548c9216e4b14e2dab80f14a6afa0e7`；SHA256 `31f1c987d0e72d37cccbc981b0debd976ccf562fd6d90de34c2c782625f01098`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-068-T01-erratum.md)；勘誤 Git blob `535d1c081ddf492d319950f4b5944619fc062f2b`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-046-2170ef08 — RESOLVED
- **T01 獨立複驗（2026-10-30；僅本通知）**：作者獨立勘誤 blob 與 KR 原件、指令界線及原稿受影響的限定敘述已交叉核對；Event.stp TutorialMain.lua proto5 PC20/40/136 原生 words 0080801C/0100801C/0080801C，Lua5.1 CALL 的 C=2 表示1個結果，而不是2個。 詳見 [T01 本批決議](../../../shared/integrations/T01-20261030-t16-followup/README.md)。**原始舊 blob、全文 FULL-PASS 與 Quest 端到端功能仍不因此通過**。
- 原稿：`kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md`；Git blob `dea68e6db1af124ecdaca7943a877a7dbddd2377`；SHA256 `25246ae4a95c7837343206e9ff957831dd8c7e0d5e65248d3d63d306cb1a6545`。
- 問題：Lua CALL C=2 means one result, not two
- 原生反證：KR TutorialMain prototype5 PC20/40/136 raw words0080801C/0100801C/0080801C have C=2. Lua5.1 VM computes nresults=GETARG_C(i)-1.
- 修正及複驗條件：Correct all three return counts to1; preserve arguments B-1 and coroutine/local-only interpretation. Primary reference: https://www.lua.org/source/5.1/lvm.c.html#luaV_execute
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-046-T01-erratum.md)；勘誤 Git blob `13438858f2bfd5e96ed01bb4b6e412dd0a5df9c7`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-092-6df3bb2c — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-204341-chatgpt-web-roy-T16-92-KR-Quest-global-owner-and-real-read-consumers.md`；Git blob `bd044356f64dd859fe898477d443414a468f4b85`；SHA256 `6266a150e2887f4a29895445cb115e20b0c0a31ce401b45f16007f3e8add117b`。
- 問題：Four reported instruction coordinates are wrong
- 原生反證：62E5CD is push eax;62E5CE starts8D45C8 lea eax,[ebp-38].5B6CCF is8B5314 mov edx,[ebx+14];5B6CD0 is interior.62F70A is mov esi,[FB114C];62F706 lies inside instruction62F700.62E659 is push esi and call starts62E65A.
- 修正及複驗條件：Repair coordinates and re-render complete rooted CFGs62E490/5B6BE0/62F640. Preserve supported owner-to-lookup/read relationship; no false unconditional-zero inference from truncated fallthrough.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-092-T01-erratum.md)；勘誤 Git blob `6b5fb000aa1015a0c2f37be9015ab52c24dc8fd0`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-092-rooted-cfg-addendum.md)，Git blob `3c80ebbecc3fcc2d78fef25ade744e7ece6466ba`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-001-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-012351-chatgpt-web-roy-T16-1-KR-tutorial-quest-entry.md`；Git blob `ec933435d90f08710ffe594a0b5ac68e3d012f40`；SHA256 `786a654cbaceda45f6cb4ecf57375748f5fabc13977e3fdd4555c3634436bbce`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Tutorial/Quest literals and local calls are supported; appendix resumes at 4A899F/4A8B2F/50559F inside existing instructions. Re-decode those windows from true roots. No runtime quest authority accepted.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-001-T01-erratum.md)；勘誤 Git blob `ad7031509bd926aa9440dae2afaaf6f331e3b539`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-001-rooted-cfg-addendum.md)，Git blob `66fb7d663c29aa9ebd7a8ba0151259e39c32d411`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-009-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-014919-chatgpt-web-roy-T16-9-KR-FE18DC-global-index.md`；Git blob `d6bbfe7ac55f07308093cc2ca2f0ad021bed37e5`；SHA256 `ed5a8d7317337f32a5dcdc4a373a6e3f2bb6cfdcfbbae82fe52611bb70d5ed64`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Four FE18DC literal operands and runtime lookup/payload→16-byte append supported; supplemental block begins at 53FADE inside MOV at53FADC and manufactures lock fcomp. Re-decode disposal block; retain the supported non-quest-authority boundary.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-009-T01-erratum.md)；勘誤 Git blob `aae80b9e5f3ec116ea8e8c8f6c3f717308e3eff7`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-009-rooted-cfg-addendum.md)，Git blob `5c673ccbb355ab6b6e5b15ce0a2efd0e56fe865b`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-020-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-020939-chatgpt-web-roy-T16-20-KR-quest-ui-status.md`；Git blob `342da9acb11bfe29720419d8a7c615f2296c139a`；SHA256 `c25d02ad83d9d53c0518f07fe84ad04fe781e383a1c7253c8ccbcd6040dab7ea`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：QUESTSTATE/QUEST_READY literal UI uses and listed valid calls supported; opening502460 lies inside JE at50245D, producing false initial instruction rows502460/502462. Re-decode actual parent CFG and retain local-display-only conclusion.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-020-T01-erratum.md)；勘誤 Git blob `6c18eadc765bb68c8314ca7dbf5a426bdaf7d419`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-020-rooted-cfg-addendum.md)，Git blob `59446bbd4f50bb09e6e2374f1be657a0cbb32458`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-021-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-020939-chatgpt-web-roy-T16-21-KR-tutoquest-parser.md`；Git blob `f6ca97b7c25a0dd957305d98b929e3467253805c`；SHA256 `5949a81f75f1961e0f7bc65ca1b70ac1e3ab0e3360dfa80115f0f4c56ba83a15`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：TutoQuest key lookup, HasQuest vectors and actual valid calls supported.5321A0 starts inside CALL53219F and53FD40 inside allocator CALL53FD3D. Their invented starting instructions cannot be native CFG proof.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-021-T01-erratum.md)；勘誤 Git blob `bfa8076bcd1e372c2e28f940c98a6e7231eb7437`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-021-rooted-cfg-addendum.md)，Git blob `7b91b63796ed1cdb7fc49386b09c77b1c00f81e9`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-022-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-020939-chatgpt-web-roy-T16-22-KR-tutorial-bootstrap.md`；Git blob `138c49cbd53e41169c386c9f1d7e826211fec283`；SHA256 `126a117ab7b87a42654eb4c4bcad34b199b95bd79cf9ba8fad52f953f8aefd61`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Lua paths, named dispatch and FBA798 gate semantics supported.4A89A0 starts inside CALL4A899E;4A8B10 is inside MOV4A8B0C and subsequent misdecoded rows. Reconstruct windows from parent roots.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-022-T01-erratum.md)；勘誤 Git blob `f065e2c8458355edcd12c7ad7c493e2dc692caf5`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-022-rooted-cfg-addendum.md)，Git blob `8833bace8ea8e1d7f3fcb11320fd9782d8004711`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-026-c26518b1 — RESOLVED
- **T01 第二輪獨立裁決（2026-10-30，僅此固定通知）**：原 T01 反證失效，由 T01 自行撤回；不要求原作者修補一個不存在的入口錯誤。 [原件與精確適用範圍](../../../shared/integrations/T01-20261030-t16-resource-followup/README.md)。**舊版來源的歷史錯誤不被抹除；整篇原稿、Quest 業務封包及 Server 狀態仍未獲 FULL-PASS。**
- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-26-KR-handler-candidate-one.md`；Git blob `1a05ec70ba24945d1dc85952d237983f13056a08`；SHA256 `49d2619048d63ba1174a1b117b986f14f252f47df933a3ede54283e9ed438d11`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：4AE4D0 and valid4AEDxx calls/dataflow supported, with no quest meaning asserted.4AEDB0 begins inside ADD4AEDAF and yields invalid first rows. Repair source appendix and derived observations from parent CFG.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-026-T01-erratum.md)；勘誤 Git blob `dc19d1690bf4fad89416c6016780fdb9156aa2d4`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-026-rooted-cfg-addendum.md)，Git blob `c22ce563cfd2734ffaac6f8e91fa0f184e2d4443`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-029-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-29-KR-quest-ui-notification.md`；Git blob `72d9faebfa9bf65628a57ab0f0d57e67d764a4c4`；SHA256 `e246c6a8eb61e6a8d9e888902284f52932eba5812f901ba5eba0ca943bef998d`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：QUESTSTATE/QUEST_READY display-path facts remain supported.502470/502860 window starts inside true instructions, spawning false rows and a spurious branch list entry50247C. Re-decode and update all dependent listed calls/branches.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-029-T01-erratum.md)；勘誤 Git blob `5925836868b7f2d374f6a0bf81565b6cd61f900c`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-029-rooted-cfg-addendum.md)，Git blob `69888b75e08d5b75de7111c21bf2fb1dc60a6745`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-030-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-30-KR-tutoquest-conditions.md`；Git blob `bc12a16b71a596a32ceeafe47795e892fb2b38f5`；SHA256 `9e94a8a2a78f6b5a41c9e88d6c0060a6b9096d080da7c2a53ed06b5eaae5d1e1`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：TutoQuest/XML-like key and four-vector parsing supported;5321A0 starts inside CALL53219F, manufacturing initial rows. Correct source appendix and regenerate derived observation lists.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-030-T01-erratum.md)；勘誤 Git blob `910a4bc2daf1ee4c44d867bb55f550a298886ecf`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-030-rooted-cfg-addendum.md)，Git blob `521f15a439ef23c4b3e3b6a6cef6f45dad8b4f90`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-031-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-31-KR-tutorial-script-control.md`；Git blob `50d455ad73780a4b351a166dce23f2d0b4ee835e`；SHA256 `49dac7dcaf5aa1b94ab0185f0b615d8c612c7b58bb09244e433f7c61f1ac8110`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Synopsis/Tutorial call paths and local gate supported;4A89A0 is inside CALL4A899E. Window disclaimer does not make the resulting fabricated instruction an actual native boundary.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-031-T01-erratum.md)；勘誤 Git blob `f59171e9c568bd5135d77bdac0e81638d7cb74f4`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-031-rooted-cfg-addendum.md)，Git blob `cae6da6b07898ac4c95b5c8ee230a5c6941c8e2d`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-033-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-023112-chatgpt-web-roy-T16-33-KR-Tutorial-entry-upstream-xrefs.md`；Git blob `d4d3e8e5c276c2e0236f16c3381ce9daabbab0e0`；SHA256 `f02fb54df44b61e6dcc41b4b9b8d81b598b54dcb14762b6a690d7a28793a38df`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：4A8A60 gate/calls and direct caller4C4D3F supported. Caller window4C4C80 starts within PUSH4C4C7F;4C4C87 within CALL4C4C84. Correct misdecoded call table and parent context.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-033-T01-erratum.md)；勘誤 Git blob `1c26b5275f7c72e2b021617258a278e43c58b183`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-033-rooted-cfg-addendum.md)，Git blob `c3f4877c9b1ee072398dc6ff53ee530e15a6f941`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-034-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-023112-chatgpt-web-roy-T16-34-KR-Synopsis-entry-callers.md`；Git blob `d40e04e082a100447c773be6e4a9a3c5f786b57b`；SHA256 `4a5dcf0e30c3e4f068b5dcf8795bfb9564d475aa72fe11b5a69cb7deac2f7767`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Synopsis entry and two true direct callers supported.47BA80 begins inside MOV47BA7F and4C1F90 inside CALL4C1F8D; resulting synthetic instruction/call rows require regeneration.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-034-T01-erratum.md)；勘誤 Git blob `3123d1e815c70c0e2abe3f1055f8dab79895142a`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-034-rooted-cfg-addendum.md)，Git blob `e11c6749adb067bfbefbb97a2aae26f1c51a878e`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-036-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-023112-chatgpt-web-roy-T16-36-KR-TutoQuest-node-parser.md`；Git blob `cac59d7ffa953663da5753574eb47304504887f0`；SHA256 `545cfe17a52b4e53dfccec2f0a35fe4d977e3b55e5af7f46309d673af1452e94`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：TutoQuest lookup and generic72E2E0 child lookup facts supported;531E00 is inside JE531DFC and5321E0 inside CMP5321DD. Repair all synthetic rows and derived observations.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-036-T01-erratum.md)；勘誤 Git blob `e02e0b4f4503b3e2a6cff2221aa8f3c3cd7f4532`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-036-rooted-cfg-addendum.md)，Git blob `ad7fa43ec38eba08e9442d15f5b67e52a3b2b374`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-040-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-023112-chatgpt-web-roy-T16-40-KR-notification-UI-dispatch-crosscheck.md`；Git blob `b35ca329c1a657364c997c701b806d6847ea5917`；SHA256 `1e5a54b4dceadac81cfed8610e46c03b16ca2b120ab3893c7a795799b4ec8499`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：UI-string/default-handler/queue local facts supported;502870 starts inside MOV50286F and generates false instructions502871/502873 and further misalignment. Correct appendix/derived call list while retaining non-authority boundary.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-040-T01-erratum.md)；勘誤 Git blob `ae73f08fe02c50d29bc5292253dee25d1747493b`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-040-rooted-cfg-addendum.md)，Git blob `b2cd36b3b1cfae6b66c2a50c98d685275d259e25`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-050-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-50-KR-lua-bridge-asm.md`；Git blob `bf3fc0814f75e19ced4ac95bfff6a67ebf4e9564`；SHA256 `375392df34f1315e05d676d947b477c1a7599a6bdd091ec7b614c9468da30943`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Lua name-length/value lookup and Synopsis/Tutorial native entry facts supported.6F4E83 is inside CALL6F4E81 in source appendix; re-decode complete6F4DD0 CFG. No Quest business semantics accepted.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-050-T01-erratum.md)；勘誤 Git blob `620f1186066700e97162f0c22ce29b7336766fc2`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-050-rooted-cfg-addendum.md)，Git blob `54b20a93d2aad6e2c4b27a1ca75cfdd2015a2c31`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-051-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-51-KR-quest-reader-source-boundary.md`；Git blob `d6591307065c066485ec3e312aafe69b38c72448`；SHA256 `59fce8a8ee1466c98df371dc925aca2619127d62d6704b8baa378bffdba3368a`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Distinct XML reader paths and QuestTalk excerpt boundary supported.504817 is inside MOV504816;50564B is inside CALL50564A. Correct appendix rooted in504740/505570 while retaining original source and current resource clarification.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-051-T01-erratum.md)；勘誤 Git blob `b48238622a74e961b6b12125779ec9512e230fdc`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-051-rooted-cfg-addendum.md)，Git blob `aa8e019b0b9750fe909897f0e1a2d8088f615ce3`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。
#### T01-RETURN-T16-065-c26518b1 — RESOLVED
- **T01 第三輪限定複驗（2026-10-30）**：已依 KR `Tartaros.bin` 原件與本次 phase3 作者 ZIP 的 rooted CFG 逐條核對指令 bytes/邊界、直接 branch/fallthrough、所涉舊窗口及引用的 71 筆歷史 call/jmp；必要的原句位置與已撤回錯誤指令見 [T01 第三輪決議](../../../shared/integrations/T01-20261030-t16-phase3-table-review/README.md) 和 [機器對照](../../../shared/integrations/T01-20261030-t16-phase3-table-review/native-validation.json)。**本 ID 的 appendix 修正已通過；舊版本錯誤、原稿全文 FULL-PASS、Quest wire/Server 行為與可玩性都沒有因此通過。**
- 原稿：`kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-65-KR-FE187C-writer-callback-initialization.md`；Git blob `c248ef57f8604d09ed0020c69533b236881cfd5e`；SHA256 `8b76af03d3e6a2017656d60b8876c7a297052d660d46ea599d18d1ff7795e4a8`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：FE187C setter4AB8B8=4AA4D0, literal refs and wrapper delegation supported. Source appendix starts4AB930 inside MOV4AB92F, producing invalid initial instruction; re-decode parent before promoting document entirety.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

<!-- T01-20261029-stage-notices:end -->



## 既有任務說明

> 規劃文件，尚未認領；`native_complete=false`。此文件已納入 GitHub，不代表 catalog 正式登記、原生功能驗收或可遊玩完成。

## 正式範圍
新手教學（P0）、早期主線（P0）、後續主線（P1）、支線（P2；主線必要前置優先）的接取、前置依賴、事件觸發、階段推進、交付、解鎖、狀態同步與中斷續接。

## 職責邊界
T16 主責跨任務／跨關卡 Quest & Story Progression；不建立新角色，不負責初始能力、裝備、出生位置、初始場景。T04 主責角色初始化；T03 主責登入選角；T07 主責關卡進出；T14 主責關卡目標、勝敗、結算與獎勵；T15 主責底層持久化；T02 主責封包基礎框架。引用其他 Task 的地圖、NPC、實體和戰鬥證據，不改其 owner 或 catalog。

## 修訂：Client 封包優先的研究定位（2026-10-28）

**T16 分析的是原始 KR 主程式送出哪些 C→S 封包、接收哪些 S→C 封包，以及回覆如何改變客戶端 Quest 狀態、NPC 可接任務、教學與劇情 UI。** 原版 Server 的內部通關判定、任務前置解鎖規則、資料庫 writer 是**待開發 Server 功能／介面設計**，不是 T16 必須還原的原始 Server 演算法，也不能當作 Client 逆向的阻塞驗收。

按玩家操作研究：`接取／交付／教學觸發 → Client local 判斷 → C→S opcode/欄位/時序 → S→C opcode/欄位/handler → Client quest state / NPC / UI`。接取後續任務要追到主程式再送出的封包。所有尚未核對的 opcode、封包內容與 Client 動作均填 `unknown`，不可將 `0x0040` 4-byte buffer 未經下游驗證直接視為已確認 wire opcode。

優先序：**P0** 教學關卡與 Quest16→Quest15 的 C→S／S→C 雙向鏈、任務接取／交付與解鎖的 client consumer；**P1** Lua／XML／NPC 前置和主線支線擴展；**P2** 登出／重登：先查主程式是否送出保存任務階段請求，或只由 Server 主動管理、登入時下發 snapshot，未知不猜。Server 需實作什麼由已確認封包與 client 反應推導為相容開發需求，而非聲稱官方 Server 真實內部規則。

下一入口：T16-69 延續 `[0x00FBA854]` vtable `+0x10` 的 downstream dispatch／packet queue／socket；同時拓展 Quest S→C handler、狀態 writer 與 NPC 可接任務 consumer。T02/T07/T14/T15 跨 Task 只引用，不修改其他範圍。

## 優先研究
1. 按版本與 SHA 盤點任務資源、任務 ID／step ID、文本、事件、封包，區分原生與 AI/fixture。
2. 以 T03/T04 既有角色資料為輸入，查教學適用判定→逐步目標與驗證→完成或中斷續接；區分 UI、本地事件及伺服器權威。
3. 還原教學結束→主線首節 NPC/對話前置→接取→場景／關卡條件→交付→後續解鎖。
4. 逐章延伸主線依賴圖；支線獨立建檔，若阻塞主線則優先。
5. 形成最小伺服器／封包恢復規格，不把測試 fixture 的自製條件當官方規則。

## KR 證據與驗收
以版本匹配的 KR BIN、客戶端資源、可信封包和原始來源交叉驗證，提供原始位址、指令、來源 SHA、狀態欄位、證據分級和明確缺口。既有 MAINLINE-FLOW、QUEST-STATE-NOTIFICATIONS 與 tutorial fixture 均只能作研究線索。

每個節點應記錄 quest/step ID、前置、trigger、state writer、網路通知、下一節點解鎖、持久化需求、證據與測試案例；未知欄位填 unknown。遵循 AGENTS.md、HANDOFF.md 與 shared/CLIENT-MODIFICATION-POLICY.md。

2026-10-28 來源整合入口：[T01-20261028-06](../../../shared/integrations/T01-20261028-06/README.md)。限定證據、T16分工與更正已入catalog；不等完整原生／遊玩驗收，既有主責與狀態保留。實際接續SHA見批次收據。

- **T16 送審（2026-10-29，待 T01 獨立複驗）**：[T16 送審勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/errata/T16-065-T01-erratum.md)；勘誤 Git blob `a2f1e7300ff622bf1b32040d0930f66eee23d1ee`；[rooted CFG 補證](https://github.com/we88ec3-prog/ttr_anal_multi/blob/9ee2234dca294fd0b9f59d730b5f043cc7d50f52/kr-temp-roy/T16-T01-returns-20261029/rooted-cfg/T16-065-rooted-cfg-addendum.md)，Git blob `6abc3bed253f03fd08832bb3f5188680cbadb6a1`；KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此狀態僅表示已提交作者端修正證據；若 T01 判定文件／語意尚不足，請保留退回並列具體差距，不得自動升級為 `RESOLVED` 或 `FULL-PASS`。