# T16 README 退回通知草案

本檔供主整合者更新 Task README 的退回專區；本輪未修改 Task README、原稿、catalog 或 Git。保留原作者歷史版本，收到勘誤及新版 SHA 後複驗。

### T01-RETURN-T16-069-CONT02-C11 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-170434-chatgpt-web-roy-T16-69-KR-virtual-dispatch-and-outbound-queue.md`；Git blob `2f5c65062c7ab82453dfa726019e4d5e2bf0a0dc`；SHA256 `0c0387cc78d2124f788e103344f16f1ec40bfd5c6084aa4e27c59ac27208971c`。
- 行號：67；問題：Scenario matrix calls the A0A4 gate a queue-count gate。
- 第一手反證與影響：Actual list element count isA078 (+1 onenqueue,-1 ondrain).A0A4 is a different field:804A40 updatesit±5 orresets0 basedondrainstatus. SourceL19 itself leavesA0A4 semantics provisional. Replace the definite queue-count label with signedfieldA0A4>300 gate; retainunknownbusinessmeaning.
- 修正要求：參照 `proposed-T16-69.diff` 的精確修改；保留其他獨立成立的原生主張。
- 完成條件：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。

### T01-RETURN-T16-070-CONT02-C06 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 行號：50；問題：Section1.2 heading gives marker first and length second。
- 第一手反證與影響：807A8F stores1A68 to[ebp-2],807A93 storeslength to[ebp-4];807AE2 loadsDWORDfrom[ebp-4],807AE9 copiesheader. ThereforefirstWORD length,secondmarker, as sourceL52/L74 already show.
- 修正要求：參照 `proposed-T16-70.diff` 的精確修改；保留其他獨立成立的原生主張。
- 完成條件：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。

### T01-RETURN-T16-070-CONT02-C09 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 行號：54, 80, 143, 168；問題：Connection-relative buffer offsets5004/500C。
- 第一手反證與影響：80620C passes ECX=connection+501C to807830;806234 passes EDI=connection+501C to807A70. Thuscallee+5004 isconnection+A020 writepointer,andcallee+500C isconnection+A028 bufferedlength. Bufferstarts connection+5020. Source uses stream-relative offsets while callingthebaseconnection.
- 修正要求：參照 `proposed-T16-70.diff` 的精確修改；保留其他獨立成立的原生主張。
- 完成條件：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。

### T01-RETURN-T16-070-CONT02-C13 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 行號：109, 116, 128；問題：Receive ASM block wrong coordinate for mov edx,2633。
- 第一手反證與影響：L116at807BDD actuallyC744242004000000 movdword[esp+20],4. CorrectBA33260000 mov edx,2633 is807BD8. Allother18rows inthisblockmatchactualinstructions; rootedCFG hasnooverlap.
- 修正要求：參照 `proposed-T16-70.diff` 的精確修改；保留其他獨立成立的原生主張。
- 完成條件：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。

### T01-RETURN-T16-071-CONT02-C05 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 行號：14, 29, 46；問題：806909 pushECX comment namesLPWSAOVERLAPPED。
- 第一手反證與影響：ECX=EAX+14 at8068F7,whereEAX=conn+A050; thus806909 pushesWSABUF atconn+A064. ActualOVERLAPPED conn+A050 waspushedasEAXat8068F3. OriginalopcodepushECXiscorrect; onlyAPIargumentlabelwrong.
- 修正要求：參照 `proposed-T16-71.diff` 的精確修改；保留其他獨立成立的原生主張。
- 完成條件：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。

### T01-RETURN-T16-071-CONT02-C06 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 行號：36；問題：Errorresult-zero instruction coordinate。
- 第一手反證與影響：806958 is5F popEDI;806959 is5E popESI;80695A is33C0 xorEAX,EAX. Return0 behavior survives butliteraladdressmustchange.
- 修正要求：參照 `proposed-T16-71.diff` 的精確修改；保留其他獨立成立的原生主張。
- 完成條件：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。

### T01-RETURN-T16-071-CONT02-C08 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 行號：52；問題：C51748 vtable raw852D48。
- 第一手反證與影響：Parsed.rdata startsVA BD2000/raw7D0600; C51748−BD2000+7D0600=84FD48. Snapshotatwrong852D48differsfrom11vtableentries. Correctmappingalreadyappearsin69. PEdataartifactincludesbothwindows.
- 修正要求：參照 `proposed-T16-71.diff` 的精確修改；保留其他獨立成立的原生主張。
- 完成條件：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。

### T01-RETURN-T16-071-CONT02-C14 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 行號：134, 135；問題：807DAD movEDI,EAX。
- 第一手反證與影響：CorrectmovEDI,EAXis807DABbytes8BF8;807DADbytesE8EEC2FFFFiscall8040A0. Duplicateellipsisnextlineisplaceholder,notanadditionalinstruction. Bothsitesaretrueinstructionboundaries,notmis-decoderinteriors.
- 修正要求：參照 `proposed-T16-71.diff` 的精確修改；保留其他獨立成立的原生主張。
- 完成條件：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- 驗收來源：本資料夾 `claim-matrix.json`、`source-block-instruction-audit.json`、`native-evidence.json`、`pe-data-and-imports.json`。
