# T08 實體生成與移除

## T01 驗收退回事項

<!-- T01-20261029-stage-notices:start -->

### 2026-10-29 階段複驗通知（7筆具體更正，既有ID原位補充）

本次僅通知已證實的錯誤；原稿全文驗收仍未完成。保留原稿，提供獨立修正版及新 blob/SHA；複驗通過前維持 NEEDS_FIX，不能將局部主張支持算作全文 FULL-PASS。

[本批總台帳](../../../shared/integrations/T01-20261029-semantic-review/README.md)；[機器可讀退回紀錄](../../../shared/integrations/T01-20261029-semantic-review/return-notices.json)。

#### T01-RETURN-T08-153-ABI-001 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-013809-chatgpt-web-roy-T08-153-GameInfo-actor-erase-bulk-cleanup.md`；Git blob `10bb0608cd1dbc9cf944eab51c74d4a2fa205e1a`；SHA256 `acc9fd34490b2f97293c0eae349c2d203a34c0830e4983bb41b1497a7490bfec`。
- 問題：Search-key storage and erase output iterator storage are conflated in A1.5/C.
- 原生反證：Caller pushes &stack key slot, not key value; callee [ebp+0xc] is output iterator pointer and writes successor to it at7B6AE6. The slot originally held key but is now an out-slot. Distinguish search-key pointer passed to82EF00 from iterator out pointer passed to7B6890.
- 修正及複驗條件：Use erase(tree, &next_iterator, node), describe stack-slot reuse and successor-before-free. Preserve old source and supply separate corrected version for revalidation.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t08-early/actor-reviews.json)。

#### T01-RETURN-T08-155-ASM-001 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-014315-chatgpt-web-roy-T08-155-tree-erase-node-and-container-invariants.md`；Git blob `45a6d797b4c33eabc24daf85292cdb005da39558`；SHA256 `099881b4a44e8c79188bd374f49b2cd46c560b25e8369538e9a3afe06bbf00cf`。
- 問題：Appendix restarts in the middle of instruction7B698E and invents instructions7B698F/90/92.
- 原生反證：Caller pushes &stack key slot, not key value; callee [ebp+0xc] is output iterator pointer and writes successor to it at7B6AE6. The slot originally held key but is now an out-slot. Distinguish search-key pointer passed to82EF00 from iterator out pointer passed to7B6890.
- 修正及複驗條件：Replace the erroneous excerpt with entry-rooted CFG decode; include7B698E and7B6991, and recheck two-child relocation control flow. T01 provides full corrected native CFG.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t08-early/actor-reviews.json)。

#### T01-RETURN-T08-183-001 — NEEDS_FIX
- 原稿：`kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-183-manager-last-release-and-container-destruction.md`；Git blob `ecbec611a9d99a7640ae4fad9668dcc3c06ad4be`；SHA256 `dd3dafebe38b5aa265a46da752269edfe890dbfd5d79451316800a9017a4fc3d`。
- 問題：0x007B8680 用於樹節點移除／調整
- 原生反證：7B868B..7B86AC computes string hash/mask and an8-byte bucket; 7B86DE EDI=&index+4 then719B20 unlinks two list links and frees node, without ordered-tree rotations.
- 修正及複驗條件：Use index-node/hash-bucket/list terminology or provide actual tree construction evidence; preserve the independently supported release ordering and separate the actor RB tree.
- 驗收紀錄：[本項證據](../../../shared/integrations/T01-20261029-semantic-review/t08-new/return-items.json)。

#### 早期映射退回更新

`T01-RETURN-T08-LEGACY-MAPPING-001` 歷史狀態為 BLOCKED；本輪已取得指定 SHA 原件並逐點核對，改為 NEEDS_FIX。24個來源版本及全部受影響原稿blob列於[映射裁決](../../../shared/integrations/T01-20261029-semantic-review/t08-early/mapping-reviews.json)；其中18篇1263條保存機器碼均在各標示VA減0x400後相符。這不是全程式重定位，也不得平移資料節絕對函式指標。7A8310/7A8E10等實際PE入口有效，早期「vtable指入指令中段」反證應重新裁決。原稿須各自提供正確PE位址／完整相關CFG的新版本；未全部複驗前不標RESOLVED。

<!-- T01-20261029-stage-notices:end -->



本節是 T01 對 T08 分析者的正式 GitHub README 通知；不使用 GitHub Issue。開始下一段工作前請先處理 NEEDS_FIX / FIXING，或明確記錄繼續研究與修正工作的優先序。T01 僅維護本退回專區，T08 保留原稿並產生修正版/勘誤。來源 Task 標記 READY_FOR_REVIEW 後，由 T01 複驗才標記 RESOLVED；已解決紀錄不刪。

### T01-RETURN-T08-157-001 — NEEDS_FIX

<!-- T01-RETURN-T08-157-001-20261029-update -->
2026-10-29 複驗補充：原稿blob `b67b6c415c63034607fadef59b0e4fc2892237e2`，SHA256 `b04539973e1056beea42dd4feefca905dc5b76a359cc5f6a5e24a475042d5164`。Caller pushes &stack key slot, not key value; callee [ebp+0xc] is output iterator pointer and writes successor to it at7B6AE6. The slot originally held key but is now an out-slot. Distinguish search-key pointer passed to82EF00 from iterator out pointer passed to7B6890. 修正／複驗：Update existing return with complete rooted CFG and affected dataflow; retain NEEDS_FIX until a new source version is revalidated. [本輪證據](../../../shared/integrations/T01-20261029-semantic-review/t08-early/actor-reviews.json)。

- 原稿：kr-temp-roy/20261028-015216-chatgpt-web-roy-T08-157-packet-row-removal-receiver-boundaries.md
- 原稿 Git blob SHA：b67b6c415c63034607fadef59b0e4fc2892237e2
- 問題：0x4B297C 在原稿片段誤作獨立指令起點。原生有效邊界為 0x4B297A cmp eax,[0x00FAB13C]；0x4B2980 je 0x4B2989；0x4B2982 mov esi,[eax+0x10]。原稿出現的 cmp al,0xb1/cli 屬指令中途錯位解碼。
- T08 修復：按 KR PE .text 的正確節區映射重解 0x4B28D0 整段 CFG；更正組語、ID 查找、分支、偽碼及受影響的主張。提交修正版或勘誤及新 Git blob SHA，交 T01 全文重驗。
- 來源：T01-030 本地核對；原始 KR BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。

### T01-RETURN-T08-173-001 — NEEDS_FIX

<!-- T01-RETURN-T08-173-001-20261029-update -->
2026-10-29 複驗補充：原稿blob `f643553ef1145ed65a5a724a0a9a3f19c910e76f`，SHA256 `1f5b203f381922d09d737d4fd9dbc227ec7e2a1f9597c311c604d3d7dbd9140c`。0x7B7FFE b9 01 00 00 00 dominates 0x7B8006 89 4a 44; ECX is constant1 through the loop. 修正／複驗：Correct the source/value, identify the actual 7B7FD0 entry, and revalidate affected dataflow. T08-177 is a later explicit correction; retain the old source FAILED. [本輪證據](../../../shared/integrations/T01-20261029-semantic-review/t08-new/return-items.json)。

- 原稿：kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-173-owner-44-writers.md
- Git blob SHA：f643553ef1145ed65a5a724a0a9a3f19c910e76f
- 問題：原稿把 0x7B8006 mov [edx+0x44],ecx 視為需由 caller 確認的可變 ECX；同一函式 0x7B7FFE mov ecx,1 已將此路的寫入值定為 1，入口應由 0x7B7FD0 識別。
- T08 修復：更正 +0x44 enable／disable 的 writer 描述，重驗本函式數值來源與所有受影響論點，提交修正版及 Git blob SHA。
- 來源：T01-026/027 驗收界線。

### T01-RETURN-T08-187-001 — NEEDS_FIX

<!-- T01-RETURN-T08-187-001-20261029-update -->
2026-10-29 複驗補充：原稿blob `cf2b5d3fc74b6d0199837c957a214765ac14866f`，SHA256 `bc0e9037d4e8a9a3108e395837e583096ed68f6d25230db9d6577488c06e978c`。0x7F6FBF=6a30 push0x30; 0x7F6FC1=8bf8 mov edi,eax. The latter saves manager before allocation. 修正／複驗：Correct instruction address and recheck manager provenance, allocation/null edge, acquire and wrapper+2C storage; source version remains FAILED. [本輪證據](../../../shared/integrations/T01-20261029-semantic-review/t08-new/return-items.json)。

- 原稿：kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-187-acquire-wrapper-and-resource-return.md
- 問題：原稿將 0x7F6FC1 註為 push 0x30；原始 BIN push 0x30 在 0x7F6FBF，0x7F6FC1 實為 mov edi,eax。
- T08 修復：重驗 0x7F6FBA 周邊 wrapper 配置、0x7DCFB0 acquire、callsite 和位址；提供修正版本路徑及新 Git blob SHA。
- 來源：T01-026 的明確原生反證。

### T01-RETURN-T08-196-001 — NEEDS_FIX

<!-- T01-RETURN-T08-196-001-20261029-update -->
2026-10-29 複驗補充：原稿blob `b1879330f55b5d7b6d38a697a46a0f40ce3b6aca`，SHA256 `e8b1564e8b92aaf59ca2fcffd9e3ca8c834f953811e348a6a8a6ea30e03665b0`。0x4DFC96=8d7808 lea edi,[eax+8]; subsequent sentinel is[edi+4]=owner+C. Secondary tree is the separate4DFC30 ESI+18 path. 修正／複驗：Correct tree base, sentinel and LEA addressing; remove/re-evaluate dual-tree ownership deductions and revalidate complete affected CFG. T08-197 correctly distinguishes the two paths. [本輪證據](../../../shared/integrations/T01-20261029-semantic-review/t08-new/return-items.json)。

- 原稿：kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-196-composite-id-secondary-tree-remove.md
- Git blob SHA：b1879330f55b5d7b6d38a697a46a0f40ce3b6aca
- 問題：原稿將 0x4DFC90 當作 owner+0x18 的第二樹；原生 0x4DFC96 lea edi,[eax+8] 指向主樹。第二樹是獨立的 0x4DFC30（lea ebx,[esi+0x18]）路徑。
- T08 修復：拆開主樹／次級樹、actor+0x88 條件與 key 移除、不同 payload 清理的全部相關結論；附完整 CFG 與修正版 Git SHA。
- 來源：T01-026、T01-030 有界核對。

### T01-RETURN-T08-LEGACY-MAPPING-001 — NEEDS_FIX（來源映射已定位）
- 範圍：T08-140～152 等較早原稿使用 BIN offset=VA-0x401000 的線性映射；此處是「群組來源調和」提醒，不把每篇都斷言相同錯誤。
- 具體例子：在 VA 0x7A507F 舊線性映射讀到 c7 46 04 4c f6 c4 00，但目前 KR PE .text VA 0x401000/raw 0x400 的對應 bytes 不同。可能是來源檔格式／攤平 image 類型不同；不可直接將兩種檔案等同。
- T08 修復：逐一找出舊筆記使用的實際檔案版本、檔案格式、SHA、.text raw 映射；證實後重新解碼並更新出處。無法取得所需原始資料時明列解除條件，勿憑推測修稿。
- 來源：T01-029 本地映射衝突核查。

### 當前不需退回／避免重複
- T08-200：0x82EF00 在 lower_bound 後有候選 key 等值檢查，舊退回理由已撤銷；見 [T01-027](../../../shared/integrations/T01-20261028-27/README.md)。
2026-10-28歷史快照（保留原文；2026-10-29已對153/155追加確證退回，158/159仍未全文通過）：

- T08-153、155、158、159 尚屬 PARTIAL（未驗完）不是已證原稿錯誤，待 T01 繼續驗收；T08-154/156 的歷史 getter 說法已由 T08-158 更新，不把已被正確更正的歷史當成新缺陷。


狀態：bounded-review-handoff；負責人未認領。

## 範圍

0007 建立、登記、移除的資料介面；不制定生成時間或決策規則

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：數量、座標、時機、owner 正式來源及通用移除規則缺失
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。數量、座標、時機、owner 正式來源及通用移除規則缺失
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **原生已確認**：S2C0007前置2 bytes、row26 bytes；type1分支建立CMonster。這不證明波次、生成時機或AI。
- **原生已確認**：S2C000A有owner及actor/related欄位；控制槽登記不等於怪物決策接管。
- **AI 替代**：怪物固定位置由fixture設定；不能推論正式波次與出生資料。
- **AI 替代**：fixture的怪物HP設定不是已確認的物種原生能力規則。

## 依賴、接續與驗收

依賴：T02, T06, T07。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [native-index/spawn-auxiliary-marker-insertion.txt](../../../unclassified/evidence/058b32976b87013fa975500b5fe126d574963ad3b3e03c95a5a43fe7727f233f.txt)
- [native-index/lb-create-object-abi-audit.json](../../../kr/evidence/117948deb154e54a66f233d059f7385cd0c9da84f3059991f764bae3993ee168.txt)
- [tutorial_monster_config.py](../../../kr/evidence/11ec8d8e1e642d2626727bab0c397e16a0ad1c7b9556fa2d0b3e0121bd0ce9d8.txt)
- [native-index/lb-CreateObject-four-argument-adapter.txt](../../../kr/evidence/12e8c92287bf2534fde7d4aff2811e7274a484b526b494b308bfd50b2eb88e97.txt)
- [native-index/lb-CreateObjectEx-six-argument-adapter.txt](../../../kr/evidence/1c0293dde9b7d5058fae8a5f67e9cc104746451c460bc005ecdf723ab343c0cc.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [native-index/monster-spawn-common-receiver.txt](../../../unclassified/evidence/232b1e969052328119dd37ad9b3487eb7aff2f9437a29ea1ade63e01e8b2c0ae.txt)
- [native-index/event-actor-constructor.txt](../../../kr/evidence/2461475830ab90b315f7830900cc3adaee41aeae38e43a43c8d9eb2646d1f391.txt)
- [native-index/common-actor-map-registration.txt](../../../unclassified/evidence/2b03641dba4cc73a8ecf0fdceb9135b3ba987dceb2a652aaedd953c48ef675b4.txt)
- [LB-CREATE-OBJECT-ABI-AND-CONTROL.md](../../../kr/evidence/33de7cea0ce88d82032b9b4e5fe7689a8acb8e4ef15728d78ba0b96c1e033ec5.txt)
- [native-index/lb-script-references.json](../../../unclassified/evidence/37bee438ee50f3dee2e82f8e3f94ba29c2675401cc492a56e064aa2b6e0e9214.txt)
- [native-index/register-DeleteObject.txt](../../../kr/evidence/3888059f1f56b3f89df96ebc00c3ba009e46e2ae984e02ebb31c978e288b3442.txt)
- [native-index/script-Q-base-binding.txt](../../../kr/evidence/38a0e526cc7b509001045b287520be2c6b25bdea5fbd492faa0dec1ee4f54765.txt)
- [native-index/script-DeleteAllObject.txt](../../../kr/evidence/3a44c60063ffad3833adaadb65fe0e1dacc127cef3a1ca10b213dffd97848453.txt)
- [native-index/register-DeleteAllObject.txt](../../../kr/evidence/4c8bbab7a87e8ca0b3a81f38a886e1848156bd0e07faaf7d4a23f6c42b2aaf10.txt)
- [audit_lb_create_object_abi.py](../../../kr/evidence/4fa0939b7e927480bff5617c84c042b2878c8c4f307d82985b78d2095f88119a.txt)
- [native-index/register-CreateObject.txt](../../../kr/evidence/546424b3940d44bf955f4f62c2ff24bc6eeb4920cf44459465d76522d298e843.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/script-object-tree-node-allocation.txt](../../../kr/evidence/6025e44dae22caf0604ae456d022c6983efb129a52f4e0a3ae6d7d3ad5b9fc61.txt)
- [native-index/player-active-actor-helper.txt](../../../unclassified/evidence/60f331c6c4569ada50b572bc1231a90efbe6ebdea4642139ef608bfb8cd80e94.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [MONSTER-SPAWN-AND-CONTROL-BOUNDARY.md](../../../kr/evidence/6ef16f451f942d2e828a1b6936b466332736d7dc75fa0152fcbb6289863902dd.txt)
- [native-index/script-Q-registration-and-base-load.txt](../../../kr/evidence/76ca4ca0918b6081c5aa323c95f5786aea0ce45585afd187e31b4a16b75d2659.txt)
- [native-index/lb-CreateObject-Lua-wrapper.txt](../../../kr/evidence/77178b09c0ec8426bd3b0565a09e8c5c7e96d79a2b7ec0ed24d99faa8864aacb.txt)
- [native-index/lb-table-binding.txt](../../../kr/evidence/839f55892432e6a8fa4fa3f5454d7ef3fdba06c04ed16d7493134ade32b07496.txt)
- [native-index/spawn-auxiliary-marker-manager-constructor.txt](../../../unclassified/evidence/83e988ac6b0f02987d703927bf132cbd0ee9bea5d166bca2de3dac58618dab69.txt)
- [scan_lb_script_references.py](../../../unclassified/evidence/8876fa300f1c610f1f331c6cc554f11d8a1132eac240c97d3ccaaff33673214d.txt)
- [native-index/lb-register-CreateObject.txt](../../../kr/evidence/8b8d4625cf6df9e8f26198e5cf7c288db965c76690aaeabb7b7bd3cf5452a364.txt)
- [native-index/lb-monster-creation-resource-sidepath.txt](../../../kr/evidence/8efc8f8dd725c5d50fc1feb600038cc1404ea0ce08ecf893d0a33fc611488760.txt)
- [native-index/monster-spawn-control-audit.json](../../../kr/evidence/9f023435f85886c849e3a0266f00700d294b6a2625ccd11a777512934a11b449.txt)
- [native-index/spawn-auxiliary-marker-free.txt](../../../unclassified/evidence/9f6ecdc49a5e76927c9291ffd351a9968d54c0baf9edba5439013599f8fc4842.txt)
- [native-index/lb-CreateObjectEx-native-factory.txt](../../../kr/evidence/a2d1dcf90e3cf3e4ff21f5422ff611cac284b6a232a8ac479236051932ce39c8.txt)
- [native-index/lb-CreateObjectEx-Lua-wrapper.txt](../../../kr/evidence/a516fd2a6716c652d88c9273319f60a4b88c4829ccaf5dc3dd195edaee11e1a1.txt)
- [native-index/script-DeleteObject-no-op.txt](../../../kr/evidence/a607cd903831b70cc24131938368ef19c0a537b63a4506190b2926d48500ae65.txt)
- [native-index/spawn-auxiliary-marker-render.txt](../../../unclassified/evidence/ad554ad1d134f6e8f9351a02538a9b011174849a673f024e1e1ca25bf72046b1.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [SCRIPT-OBJECT-CREATION-AND-OWNERSHIP.md](../../../kr/evidence/b9e06b547ba8028e9a2383caa9c1ad6082e03a02897b554ce222df272e772b20.txt)
- [native-index/lb-register-CreateObjectEx.txt](../../../kr/evidence/bc52c6dda9e2a640bc43c4340e699fba05fafd6a95d7e115b67e3ad9e66668a0.txt)
- [native-index/script-object-lifecycle-audit.json](../../../kr/evidence/c21e09019d3e7e97fddc6f8ff8b334aa849964cd7eba41662f3fec5e6f0c9d56.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [native-index/lb-registration-chain.txt](../../../kr/evidence/da508a89b5d91849872e0e8b59d2e18513d351ef3f8ae729e16a0f71e7dd19c4.txt)
- [native-index/script-CreateObject-event-actor.txt](../../../kr/evidence/e1988092215136b24c7b3a10ea5b7451a697bc3d43e9cfc6b6c9e5d301dcb988.txt)
- [native-index/script-object-tree-unique-insertion.txt](../../../kr/evidence/e2d196f0e8c18f017df72433d5c3ad850c788d86ee7c2f04494e141a3153c273.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [native-index/actor-control-assignment-bounded.txt](../../../unclassified/evidence/edad70db3c441b0936b7f9090776679d5eefc4a3e508cc8b7cd8d1a2c184a210.txt)
- [native-index/lb-CreateObject-fixed-defaults.txt](../../../kr/evidence/ee4cc0decd44c6fb41776bb23c24b2b754a88e0ccb5f7181e662567cfb4ad117.txt)
- [audit_script_object_lifecycle.py](../../../kr/evidence/fb396ef585cf77e9ebfe3b2e7efcba45ecef1a48a3980e4a0717dec046872a27.txt)
- [native-index/lb-Rebind-wrapper.txt](../../../kr/evidence/fcdb89407927a21d3b536793322ed327e8c3678ae0fae9a77d501289da07c8ca.txt)
- [audit_monster_spawn_control.py](../../../kr/evidence/fe843f6e9d6a23bad7405d0daf0e4eddaa043b0571b1d8c3fcf82c8ce38df2ae.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。


2026-10-26 T01 整合交接：[T01-20261026-01](../../../shared/integrations/T01-20261026-01/README.md)。僅列明 SHA 的凍結成果已整合；其他暫存／新修改仍待下一輪。各任務未整體完成，接續前以此批次所在 origin/main commit 為基準。


2026-10-27 來源整合：[T01-20261027-03](../../../shared/integrations/T01-20261027-03/README.md)。只接受列明 SHA 與限定結論；其他暫存及整體功能未完成。本批已推送至 origin/main，接續基準 `d370a01645218615ad42595071c5328077e643a7`；推送收據見批次紀錄。


2026-10-27 新批次整合：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。比對來源SHA、限定結論及待核對映射；本批未把整份報告／函式或整項任務標完成。實際遠端接續基準見批次push-receipt.json。


2026-10-27 接續來源審核：[T01-20261027-05](../../../shared/integrations/T01-20261027-05/README.md)。先前105份source-only報告已有逐份來源與限定內容處置；完整語意／映射缺口仍保留。最新來源狀態見[來源審核索引](../../../shared/source-review-status.json)，實際遠端接續基準見批次收據。


2026-10-28 來源整合入口：[T01-20261028-06](../../../shared/integrations/T01-20261028-06/README.md)。限定證據、T16分工與更正已入catalog；不等完整原生／遊玩驗收，既有主責與狀態保留。實際接續SHA見批次收據。


## 2026-10-28：封包引發的關卡變化／本地深度追查

- [T08 本地接手清單：封包→場景／怪物／事件效果](LOCAL-FOLLOWUP-PACKET-STAGE-EFFECTS.md)：列明 Web 已確認的 **S2C 0007 建立、S2C 000A 控制關聯、命令 26／81 移除、命令 151 狀態同步** 及證據邊界；特別注意 wire opcode/domain 不能只憑命令編號直接假定。
- 優先由 **T02 收包與拆包 → T08 handler → Actor/Scene writer → 玩家可見效果** 閉合；另查其他 S2C 是否造成怪物生成／刪除、場景事件、下一波、關卡切換。Server 決定生成時機、波次及事件的原始規則，缺原生 Server／封包資料時須標為**資訊缺失、待本地查證**，不可用 AI fixture 補猜。
- Web 缺少完整外部原始主程式配套／動態資料／原版 Server 或 runtime 證據而無法閉合的指標、vtable、所有權、錯誤路徑與時序，統一交由本地研究；**Web 無法取證不表示原版不存在**。完整工作項與驗收矩陣見上列文件。
- **本次僅追加交接，不修改 task owner/state、正式 0007 scope 或其他 Task 主責；未授權執行/附加/修改目標程式。**
