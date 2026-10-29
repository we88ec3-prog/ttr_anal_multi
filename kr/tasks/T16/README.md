# T16 任務與劇情流程（Quest & Story Progression）— KR

## T01 驗收退回事項

<!-- T01-continuation-02-notices:start -->

### 2026-10-29 接續第02批複驗

逐篇主張與全部碼塊已核對；以下限定需修正的內容，保留其他獨立支持的結論。

#### T01-RETURN-T16-069-CONT02-C11 — NEEDS_QUALIFICATION
- 原稿：`kr-temp-roy/20261028-170434-chatgpt-web-roy-T16-69-KR-virtual-dispatch-and-outbound-queue.md`；Git blob `2f5c65062c7ab82453dfa726019e4d5e2bf0a0dc`；SHA256 `0c0387cc78d2124f788e103344f16f1ec40bfd5c6084aa4e27c59ac27208971c`。
- 問題：Scenario matrix calls the A0A4 gate a queue-count gate
- 原生依據：Actual list element count isA078 (+1 onenqueue,-1 ondrain).A0A4 is a different field:804A40 updatesit±5 orresets0 basedondrainstatus. SourceL19 itself leavesA0A4 semantics provisional. Replace the definite queue-count label with signedfieldA0A4>300 gate; retainunknownbusinessmeaning.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-070-CONT02-C06 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 問題：Section1.2 heading gives marker first and length second
- 原生依據：807A8F stores1A68 to[ebp-2],807A93 storeslength to[ebp-4];807AE2 loadsDWORDfrom[ebp-4],807AE9 copiesheader. ThereforefirstWORD length,secondmarker, as sourceL52/L74 already show.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-070-CONT02-C09 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 問題：Connection-relative buffer offsets5004/500C
- 原生依據：80620C passes ECX=connection+501C to807830;806234 passes EDI=connection+501C to807A70. Thuscallee+5004 isconnection+A020 writepointer,andcallee+500C isconnection+A028 bufferedlength. Bufferstarts connection+5020. Source uses stream-relative offsets while callingthebaseconnection.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-070-CONT02-C13 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-175141-chatgpt-web-roy-T16-70-KR-queue-drain-framing-and-receive-parser.md`；Git blob `b84f671788f964043180d232323ceab106ced74f`；SHA256 `43c0b0cff8236312cf00af130e889858bf92403924f859adc6a48ad26624c5bb`。
- 問題：Receive ASM block wrong coordinate for mov edx,2633
- 原生依據：L116at807BDD actuallyC744242004000000 movdword[esp+20],4. CorrectBA33260000 mov edx,2633 is807BD8. Allother18rows inthisblockmatchactualinstructions; rootedCFG hasnooverlap.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-071-CONT02-C05 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 問題：806909 pushECX comment namesLPWSAOVERLAPPED
- 原生依據：ECX=EAX+14 at8068F7,whereEAX=conn+A050; thus806909 pushesWSABUF atconn+A064. ActualOVERLAPPED conn+A050 waspushedasEAXat8068F3. OriginalopcodepushECXiscorrect; onlyAPIargumentlabelwrong.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-071-CONT02-C06 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 問題：Errorresult-zero instruction coordinate
- 原生依據：806958 is5F popEDI;806959 is5E popESI;80695A is33C0 xorEAX,EAX. Return0 behavior survives butliteraladdressmustchange.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-071-CONT02-C08 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 問題：C51748 vtable raw852D48
- 原生依據：Parsed.rdata startsVA BD2000/raw7D0600; C51748−BD2000+7D0600=84FD48. Snapshotatwrong852D48differsfrom11vtableentries. Correctmappingalreadyappearsin69. PEdataartifactincludesbothwindows.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

#### T01-RETURN-T16-071-CONT02-C14 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-183258-chatgpt-web-roy-T16-71-KR-WSASend-and-inbound-dispatch-boundary.md`；Git blob `8f2e297a563e2443ff32601e63654b3e953eaee5`；SHA256 `6aa91628cb809a41ef5b88cb5d2c87fa0cce2c9a736b461f175063681281e711`。
- 問題：807DAD movEDI,EAX
- 原生依據：CorrectmovEDI,EAXis807DABbytes8BF8;807DADbytesE8EEC2FFFFiscall8040A0. Duplicateellipsisnextlineisplaceholder,notanadditionalinstruction. Bothsitesaretrueinstructionboundaries,notmis-decoderinteriors.
- 修正及複驗：Preserve original; provide erratum/new source version+SHA correcting this item and affected repetitions. T01 rechecks corrected version, related code blocks and dependents before RESOLVED.
- [逐項驗收及原生證據](../../../shared/integrations/T01-20261029-continuation-02/t16/README.md)。

<!-- T01-continuation-02-notices:end -->


<!-- T01-20261029-stage-notices:start -->

### 2026-10-29 階段複驗通知（35筆具體更正，既有ID原位補充）

本次僅通知已證實的錯誤；原稿全文驗收仍未完成。保留原稿，提供獨立修正版及新 blob/SHA；複驗通過前維持 NEEDS_FIX，不能將局部主張支持算作全文 FULL-PASS。

[本批總台帳](../../../shared/integrations/T01-20261029-semantic-review/README.md)；[機器可讀退回紀錄](../../../shared/integrations/T01-20261029-semantic-review/return-notices.json)。

#### T01-RETURN-T16-002-9c70bd9f — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-012719-chatgpt-web-roy-T16-2-KR-Lua-dispatch-and-quest-fields.md`；Git blob `c3c7a7efc3b1aed44d9bb3187e652ba3638ae595`；SHA256 `59c8a07618e363bfc9f863d233208c124d6b493b1944c9d93fb0aeb2247a720f`。
- 問題：Native return polarity is inverted in conceptual pseudocode
- 原生反證：6F4A94 initializes ESI=1; absent resource reaches 6F4BCF and returns EAX=ESI. Normal parse success sets ESI=0.
- 修正及複驗條件：Represent zero-success/nonzero-failure native status. Do not use false to represent missing-file return without an explicit inversion wrapper.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-005-82389c1b — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-014323-chatgpt-web-roy-T16-5-KR-child-parser-vector.md`；Git blob `ae3dec4d3e612e2b20e31db54b6425602786c615`；SHA256 `2d9e7779ff5368f496f21062369b4a642de9bb6957f71f2b0f017538769a7105`。
- 問題：Pseudocode advances the callback result instead of the original Shout node
- 原生反證：ESI retains original node; virtual +14 result is EAX; next iteration reads [ESI+40]. Null callback result skips append.
- 修正及複驗條件：Maintain original-node iterator separately from converted callback result and preserve null-result branch.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-013-36353f64 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-020402-chatgpt-web-roy-T16-13-KR-tree-lookup-ABI.md`；Git blob `b5ea5e5ed5312c287f2051b1db6ed3326c44be9c`；SHA256 `ee0226360ca0ccc934993efe8874dd5c166bdc48d7f478bfa21910e5a33a2a93`。
- 問題：Final signed tree inequality is reversed
- 原生反證：843901 cmp esi,[edx+C]; 843904 jl sentinel. ESI is search key. Lower-bound best >= key; absent key5 with candidate7 must return sentinel.
- 修正及複驗條件：Return head if best==head or key<best.key. Preserve signed comparison and calling convention.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-045-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-101028-chatgpt-web-roy-T16-45-KR-Lua-XML-source-and-BIN-validation.md`；Git blob `8067059908d888141c8d7b4a12b80eb6b427e49c`；SHA256 `52c9551a807dd347c184b4a9adf044a02d575d0d665870d96756fe35321042c2`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-046-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md`；Git blob `dea68e6db1af124ecdaca7943a877a7dbddd2377`；SHA256 `25246ae4a95c7837343206e9ff957831dd8c7e0d5e65248d3d63d306cb1a6545`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-048-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-48-KR-quest-authority-validation-matrix.md`；Git blob `e4633cecbb8531a950a4d15f24d7db5ae4fd6529`；SHA256 `6f93462118e51cd370df8241aba523eb4678105641ae4b3790a601c1cbc39641`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-049-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-49-KR-resource-provenance-pe-audit.md`；Git blob `0df285c934581b93bb2339320a2c8a6e69772675`；SHA256 `524227b0093f7ad4c4d9ea591424b21df329a598e3f9a9be8068baf827de5549`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-052-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-52-KR-quest-authority-handoff.md`；Git blob `84e4f83eff35ed0c0da23880fe54553bd065b2ef`；SHA256 `f37d39303baf9cd94ef8e80d3a32e03a51f4cfeccf87e734495a759edaa397bd`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-054-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-54-KR-tutorial-lua-direct-call-xrefs.md`；Git blob `319c873eab18f80db3c464df38b51ab396dc80a7`；SHA256 `74bbb543328f7f521d716a6e895c17cb6b7e924cae4ee2ea6ff9deb3643e69b9`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-056-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-56-KR-authority-gap-next-contract.md`；Git blob `f6c7a0bb219c11c561e6463a7ae121bf6a41b4f2`；SHA256 `45a4b69a6190d4c3f5dfb324104433afd690e6303b25adcdfd6e0b48726674c8`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-060-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-60-KR-Quest16-Quest15-native-proof-matrix.md`；Git blob `b91b766bbfd2272dae446c428c600ccaeaec1fa7`；SHA256 `9e56eb03747e290d564623f8abd42b2ac5031591cf03303375e6b7f35d2ed226`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-061-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-61-KR-scenario-lua-callback-argument-marshal.md`；Git blob `d8877384dd938cab6421c67fcc62f451d196ccd5`；SHA256 `3e3f518fdb983cab445ab75a6b4e698a79723cf2a57b871a22d7fea193d9a43e`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-062-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-62-KR-quest-xml-node-consumer-callgraph.md`；Git blob `e9b16c654215aa1567cb66571d721c1ab01eea97`；SHA256 `56139bdcb333f02b609dadc7aa45cb18f3a0f4d6b818e5f6bf4494a6272585ed`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-063-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-63-KR-quest-readers-and-data-lifecycle.md`；Git blob `26c595c295093777a7153426a16757b11eacec19`；SHA256 `02fe48ceb6de16e34edad6699c24680f30f7c29d556a5fd481e7c20e7deab846`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-064-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-64-KR-end-to-end-quest16-quest15-evidence-gates.md`；Git blob `dee3295e7cdde882aae96b277d224160420608c8`；SHA256 `84ff514e4b9198f465c451d0c44917e7f5c0d730a2bc50bb20afda5a60fe57f7`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-067-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-67-KR-scenario-dispatch-state-versus-quest.md`；Git blob `21e9facd60a283e4b9f097937b98b91defbdb53e`；SHA256 `9e8ba04b64205c6126a1ef58434df5d0984b05a0a9e35ae46e207ded11f480a0`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-068-89ddf3e8 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-68-KR-quest16-quest15-native-handoff.md`；Git blob `158ceaa7b548c9216e4b14e2dab80f14a6afa0e7`；SHA256 `31f1c987d0e72d37cccbc981b0debd976ccf562fd6d90de34c2c782625f01098`。
- 問題：TutorialBase exact-source SHA is malformed (56 hex characters)
- 原生反證：Claimed 26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744 is56 chars. Carrier-bound decoded member SHA256 is26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744,1416 bytes,6prototypes,72instructions.
- 修正及複驗條件：Correct source identity and lookup path; distinguish historical connector404 from actual member absence. Do not treat previously inaccessible content as permanent missing evidence.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-046-2170ef08 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md`；Git blob `dea68e6db1af124ecdaca7943a877a7dbddd2377`；SHA256 `25246ae4a95c7837343206e9ff957831dd8c7e0d5e65248d3d63d306cb1a6545`。
- 問題：Lua CALL C=2 means one result, not two
- 原生反證：KR TutorialMain prototype5 PC20/40/136 raw words0080801C/0100801C/0080801C have C=2. Lua5.1 VM computes nresults=GETARG_C(i)-1.
- 修正及複驗條件：Correct all three return counts to1; preserve arguments B-1 and coroutine/local-only interpretation. Primary reference: https://www.lua.org/source/5.1/lvm.c.html#luaV_execute
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-092-6df3bb2c — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-204341-chatgpt-web-roy-T16-92-KR-Quest-global-owner-and-real-read-consumers.md`；Git blob `bd044356f64dd859fe898477d443414a468f4b85`；SHA256 `6266a150e2887f4a29895445cb115e20b0c0a31ce401b45f16007f3e8add117b`。
- 問題：Four reported instruction coordinates are wrong
- 原生反證：62E5CD is push eax;62E5CE starts8D45C8 lea eax,[ebp-38].5B6CCF is8B5314 mov edx,[ebx+14];5B6CD0 is interior.62F70A is mov esi,[FB114C];62F706 lies inside instruction62F700.62E659 is push esi and call starts62E65A.
- 修正及複驗條件：Repair coordinates and re-render complete rooted CFGs62E490/5B6BE0/62F640. Preserve supported owner-to-lookup/read relationship; no false unconditional-zero inference from truncated fallthrough.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-001-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-012351-chatgpt-web-roy-T16-1-KR-tutorial-quest-entry.md`；Git blob `ec933435d90f08710ffe594a0b5ac68e3d012f40`；SHA256 `786a654cbaceda45f6cb4ecf57375748f5fabc13977e3fdd4555c3634436bbce`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Tutorial/Quest literals and local calls are supported; appendix resumes at 4A899F/4A8B2F/50559F inside existing instructions. Re-decode those windows from true roots. No runtime quest authority accepted.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-009-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-014919-chatgpt-web-roy-T16-9-KR-FE18DC-global-index.md`；Git blob `d6bbfe7ac55f07308093cc2ca2f0ad021bed37e5`；SHA256 `ed5a8d7317337f32a5dcdc4a373a6e3f2bb6cfdcfbbae82fe52611bb70d5ed64`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Four FE18DC literal operands and runtime lookup/payload→16-byte append supported; supplemental block begins at 53FADE inside MOV at53FADC and manufactures lock fcomp. Re-decode disposal block; retain the supported non-quest-authority boundary.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-020-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-020939-chatgpt-web-roy-T16-20-KR-quest-ui-status.md`；Git blob `342da9acb11bfe29720419d8a7c615f2296c139a`；SHA256 `c25d02ad83d9d53c0518f07fe84ad04fe781e383a1c7253c8ccbcd6040dab7ea`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：QUESTSTATE/QUEST_READY literal UI uses and listed valid calls supported; opening502460 lies inside JE at50245D, producing false initial instruction rows502460/502462. Re-decode actual parent CFG and retain local-display-only conclusion.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-021-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-020939-chatgpt-web-roy-T16-21-KR-tutoquest-parser.md`；Git blob `f6ca97b7c25a0dd957305d98b929e3467253805c`；SHA256 `5949a81f75f1961e0f7bc65ca1b70ac1e3ab0e3360dfa80115f0f4c56ba83a15`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：TutoQuest key lookup, HasQuest vectors and actual valid calls supported.5321A0 starts inside CALL53219F and53FD40 inside allocator CALL53FD3D. Their invented starting instructions cannot be native CFG proof.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-022-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-020939-chatgpt-web-roy-T16-22-KR-tutorial-bootstrap.md`；Git blob `138c49cbd53e41169c386c9f1d7e826211fec283`；SHA256 `126a117ab7b87a42654eb4c4bcad34b199b95bd79cf9ba8fad52f953f8aefd61`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Lua paths, named dispatch and FBA798 gate semantics supported.4A89A0 starts inside CALL4A899E;4A8B10 is inside MOV4A8B0C and subsequent misdecoded rows. Reconstruct windows from parent roots.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-026-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-26-KR-handler-candidate-one.md`；Git blob `1a05ec70ba24945d1dc85952d237983f13056a08`；SHA256 `49d2619048d63ba1174a1b117b986f14f252f47df933a3ede54283e9ed438d11`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：4AE4D0 and valid4AEDxx calls/dataflow supported, with no quest meaning asserted.4AEDB0 begins inside ADD4AEDAF and yields invalid first rows. Repair source appendix and derived observations from parent CFG.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-029-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-29-KR-quest-ui-notification.md`；Git blob `72d9faebfa9bf65628a57ab0f0d57e67d764a4c4`；SHA256 `e246c6a8eb61e6a8d9e888902284f52932eba5812f901ba5eba0ca943bef998d`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：QUESTSTATE/QUEST_READY display-path facts remain supported.502470/502860 window starts inside true instructions, spawning false rows and a spurious branch list entry50247C. Re-decode and update all dependent listed calls/branches.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-030-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-30-KR-tutoquest-conditions.md`；Git blob `bc12a16b71a596a32ceeafe47795e892fb2b38f5`；SHA256 `9e94a8a2a78f6b5a41c9e88d6c0060a6b9096d080da7c2a53ed06b5eaae5d1e1`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：TutoQuest/XML-like key and four-vector parsing supported;5321A0 starts inside CALL53219F, manufacturing initial rows. Correct source appendix and regenerate derived observation lists.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-031-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-31-KR-tutorial-script-control.md`；Git blob `50d455ad73780a4b351a166dce23f2d0b4ee835e`；SHA256 `49dac7dcaf5aa1b94ab0185f0b615d8c612c7b58bb09244e433f7c61f1ac8110`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Synopsis/Tutorial call paths and local gate supported;4A89A0 is inside CALL4A899E. Window disclaimer does not make the resulting fabricated instruction an actual native boundary.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-033-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-023112-chatgpt-web-roy-T16-33-KR-Tutorial-entry-upstream-xrefs.md`；Git blob `d4d3e8e5c276c2e0236f16c3381ce9daabbab0e0`；SHA256 `f02fb54df44b61e6dcc41b4b9b8d81b598b54dcb14762b6a690d7a28793a38df`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：4A8A60 gate/calls and direct caller4C4D3F supported. Caller window4C4C80 starts within PUSH4C4C7F;4C4C87 within CALL4C4C84. Correct misdecoded call table and parent context.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-034-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-023112-chatgpt-web-roy-T16-34-KR-Synopsis-entry-callers.md`；Git blob `d40e04e082a100447c773be6e4a9a3c5f786b57b`；SHA256 `4a5dcf0e30c3e4f068b5dcf8795bfb9564d475aa72fe11b5a69cb7deac2f7767`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Synopsis entry and two true direct callers supported.47BA80 begins inside MOV47BA7F and4C1F90 inside CALL4C1F8D; resulting synthetic instruction/call rows require regeneration.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-036-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-023112-chatgpt-web-roy-T16-36-KR-TutoQuest-node-parser.md`；Git blob `cac59d7ffa953663da5753574eb47304504887f0`；SHA256 `545cfe17a52b4e53dfccec2f0a35fe4d977e3b55e5af7f46309d673af1452e94`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：TutoQuest lookup and generic72E2E0 child lookup facts supported;531E00 is inside JE531DFC and5321E0 inside CMP5321DD. Repair all synthetic rows and derived observations.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-040-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-023112-chatgpt-web-roy-T16-40-KR-notification-UI-dispatch-crosscheck.md`；Git blob `b35ca329c1a657364c997c701b806d6847ea5917`；SHA256 `1e5a54b4dceadac81cfed8610e46c03b16ca2b120ab3893c7a795799b4ec8499`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：UI-string/default-handler/queue local facts supported;502870 starts inside MOV50286F and generates false instructions502871/502873 and further misalignment. Correct appendix/derived call list while retaining non-authority boundary.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-050-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-50-KR-lua-bridge-asm.md`；Git blob `bf3fc0814f75e19ced4ac95bfff6a67ebf4e9564`；SHA256 `375392df34f1315e05d676d947b477c1a7599a6bdd091ec7b614c9468da30943`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Lua name-length/value lookup and Synopsis/Tutorial native entry facts supported.6F4E83 is inside CALL6F4E81 in source appendix; re-decode complete6F4DD0 CFG. No Quest business semantics accepted.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-051-c26518b1 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-51-KR-quest-reader-source-boundary.md`；Git blob `d6591307065c066485ec3e312aafe69b38c72448`；SHA256 `59fce8a8ee1466c98df371dc925aca2619127d62d6704b8baa378bffdba3368a`。
- 問題：Appendix window starts or resumes inside a different instruction
- 原生反證：Distinct XML reader paths and QuestTalk excerpt boundary supported.504817 is inside MOV504816;50564B is inside CALL50564A. Correct appendix rooted in504740/505570 while retaining original source and current resource clarification.
- 修正及複驗條件：Replace affected window using complete containing function entry and branch graph; preserve raw original and identify corrected boundaries. Do not promote entire original appendix from matching individual bytes.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json)。

#### T01-RETURN-T16-065-c26518b1 — NEEDS_FIX
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
