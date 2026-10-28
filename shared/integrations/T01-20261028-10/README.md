# T01-20261028-10 — 80 份研究原稿來源驗證與 KR BIN 限定抽樣

> 本批依使用者要求「能驗證的先驗證，缺少原件先跳過」。**80/80 來源版本核對並不等於 80/80 技術語義驗收通過。**

## 驗收方法與可信邊界

- 逐份透過 GitHub `fetch_file` 讀取 T01-20261028-07 登記的 80 份原稿並比較 blob SHA，**80/80 相符**；涵蓋 T08 28、T10 20、T16 32。T16 41–44 各兩份均保留獨立 SHA，不以段號去重。
- 本地直接讀取 `/mnt/data/Tartaros.bin` (12,472,320 bytes) 與 `Tartaros.exe`；實測 SHA256 分別為 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，均與既有基準一致。
- 從研究原稿摘取有界的 43 個原生 VA→raw byte 樣本，使用 KR `.text` 映射 `raw = VA - 0x00400C00` 直接比較原始 BIN：**43/43 相符**。含多個僅一 byte 的 prologue 檢查，這只能證明位址位元組相符；**不得推論函式語義已通過**。重複地址不計為新函式發現。
- 以下逐檔表格「局部樣本」只是便於追溯到其中一組已比對地址，**不是逐行審核該文件全部 ASM 或全部函式**。`DOCUMENT-ONLY` 代表來源已核對、本批未找到適合的直接 bytes 核對；`BYTE-SAMPLE-PASS` 只代表表列地址的一個短片段一致。所有文件仍是 `SEMANTICS-PENDING`，除非先前批次已明列極有限主張。
- 本批不執行目標、不更改其他 Task owner、`shared/catalog.json`、`shared/source-review-status.json` 或作者原稿；此紀錄附加於 T01 integration，不能冒充 T08/T10/T16 對整份原稿的認可。

## 80 份逐檔結果

| Task | 段號 | 原稿與 Git blob SHA | BIN 局部抽樣 | 結果 |
|---|---|---|---|---|
| T10 | 081 | [來源](../../../kr-temp-roy/20261028-085723-chatgpt-web-roy-T10-081-native-keymapping-resource-recovery.md) `882743a9197fff2a5a1d7c189c5d301c8a9da8a4` | `0x006d08f0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 41 | [來源](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-41-KR-Lua-tutorial-static-source-audit.md) `709dc7206d8ef70024a2f77de79d86ce3c557cc7` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 42 | [來源](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-42-KR-QuestXML-source-inventory-and-schema-gates.md) `97773d959e623df88dec3a4506ebd83c8ac9c115` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 43 | [來源](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-43-KR-tutorial-to-mainline-evidence-edges.md) `2feafd823d0de32ec1b2503df9fa2a9c2b3c1856` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 44 | [來源](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-44-KR-quest-state-authority-and-acceptance.md) `c7d68207f95fd2ceb1d9ad8cbe4d5410e04e8f41` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T08 | 173 | [來源](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-173-owner-44-writers.md) `f643553ef1145ed65a5a724a0a9a3f19c910e76f` | `0x007b7fa0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 174 | [來源](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-174-deferred-queue-consumer.md) `c56a5cae912d81bfad8141eeeaaa3b83016e209b` | `0x007dd1a0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 175 | [來源](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-175-release-protocol.md) `7af6cbd50284aee17caf4b77912b1a708a239efe` | `0x007be5f0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 176 | [來源](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-176-ownership-lifecycle-audit.md) `735c789499a8af2581f748dc766de87a417def90` | `0x007dd1a0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 177 | [來源](../../../kr-temp-roy/20261028-094900-chatgpt-web-roy-T08-177-owner-mode-caller-drain-closure.md) `fdc8a64aa0f33866defe5a2484fa432f4bbaf66c` | `0x007b7fd0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 082 | [來源](../../../kr-temp-roy/20261028-094926-chatgpt-web-roy-T10-082-keymapping-runtime-xrefs.md) `4a3f3028ffc003883430eaf88c70852cc6314ab4` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 41 | [來源](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-41-KR-tutorial-Lua-provenance-and-entry.md) `46d93721bb6a343d83a00fa5cfe2283b33e16337` | `0x004a8a60` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 42 | [來源](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-42-KR-quest-XML-versioned-source.md) `77b960803fe95ba9fc5dd7a7f086dcc79c05b6e4` | `0x00504740` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 43 | [來源](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-43-KR-tutorial-to-quest16-quest15-evidence.md) `22c02f093ab0e8804e42ec5b071c9fb316e9bebc` | `0x004a89c0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 44 | [來源](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-44-KR-quest-state-authority-acceptance.md) `8262d45d0f8cf5672ff4617d2c0ac741d764c205` | `0x004a8a60` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 178 | [來源](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-178-mode-two-container-callback-boundary.md) `a338ee89963c817f50010ddec3a2985d6603beee` | `0x007b7fd0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 179 | [來源](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-179-last-reference-registry-release.md) `76e410b206bde1e85444134303da17b0242794f0` | `0x007dd100` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 180 | [來源](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-180-formal-0007-resource-interface-audit.md) `4ab548ce691aca8e04f0be4ec83899d577290719` | `0x004c7d90` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 083 | [來源](../../../kr-temp-roy/20261028-095434-chatgpt-web-roy-T10-083-working-bank-configuration.md) `3097b2d57a62703d31bb59409283ac4e00becf33` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T10 | 084 | [來源](../../../kr-temp-roy/20261028-095435-chatgpt-web-roy-T10-084-phase-dispatch-boundaries.md) `91fcdcce12d14724648650829e971a380be25ecf` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T08 | 181 | [來源](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-181-reuse-pool-acquisition-and-count-separation.md) `2f0175b00bd9f96ec62b92065a832693b4cebe6a` | `0x007dcfb0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 182 | [來源](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-182-mode-switch-and-binding-boundary.md) `f9717b667a90cee6a554f04d4070472e643918bb` | `0x007b7fd0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 183 | [來源](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-183-manager-last-release-and-container-destruction.md) `ecbec611a9d99a7640ae4fad9668dcc3c06ad4be` | `0x007dd100` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 184 | [來源](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-184-0007-scene-actor-resource-ownership-interface.md) `55058a01ad35dc4f01c49ab781780e556ef506ee` | `0x004dff30` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 085 | [來源](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-085-phase-reset-and-event-map.md) `cf1906f0c6f6d09846d1aefc45736d0f6eb1d706` | `0x006d4a93` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 086 | [來源](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-086-fb73e8-transition.md) `c5290e18160287e2e77ea430b4b26697fcac6b3f` | `0x00560197` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 087 | [來源](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-087-dispatch-consumer.md) `161febaa46a936da40588783860ef904b0e620cf` | `0x005961ed` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 088 | [來源](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-088-producer-gap-and-next.md) `54a205919cb7cbb180610439067aa85eef1815c9` | `0x00490de0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 45 | [來源](../../../kr-temp-roy/20261028-101028-chatgpt-web-roy-T16-45-KR-Lua-XML-source-and-BIN-validation.md) `8067059908d888141c8d7b4a12b80eb6b427e49c` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T10 | 089 | [來源](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-089-event-container-callers.md) `b9522feee0464b68ead6ff1ea09f84e09a168510` | `0x00490de8` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 090 | [來源](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-090-fb73e8-reader-audit.md) `d232cee52ae99734bdae7229a5c1e0e9f2451bd5` | `0x004a97fe` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 091 | [來源](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-091-conditional-child-selector.md) `6f76c33948d04582983855a574dabe64eb185599` | `0x00761010` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 092 | [來源](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-092-mapping-consumer-domain.md) `4902528ed87c5ecfc0477cb248794ea1bd937f4c` | `0x005cd661` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 185 | [來源](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-185-registry-node-virtual-callback-disposal.md) `24077d1529e6031fa9fda874ac14b2b79b5ccb7f` | `0x007dc510` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 186 | [來源](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-186-manager-destructor-buffer-lock-order.md) `2e9880fdf0b4a0bec0b2f92dfc401f0013439a1a` | `0x007dcf40` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 187 | [來源](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-187-acquire-wrapper-and-resource-return.md) `cf2b5d3fc74b6d0199837c957a214765ac14866f` | `0x007be5f0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 188 | [來源](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-188-actor-registry-and-resource-lifetime-gap.md) `115bbbf2b6005d2920cc46f606763c3ff8b8d687` | `0x004dff30` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 46 | [來源](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md) `dea68e6db1af124ecdaca7943a877a7dbddd2377` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 47 | [來源](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-47-KR-quest16-quest15-source-schema.md) `fef1cae164a07377ce29b8586453e385bd05520c` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 48 | [來源](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-48-KR-quest-authority-validation-matrix.md) `e4633cecbb8531a950a4d15f24d7db5ae4fd6529` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T08 | 189 | [來源](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-189-registry-lookup-payload-vcall-boundary.md) `a593f50abda9dc3523e07c727c8eeab6d3ae4514` | `0x007dc510` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 190 | [來源](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-190-resource-counter-acquire-release-balance.md) `a633fc34c161afd168b74ba1f35a6fcf3fd17c33` | `0x007dcfb0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 191 | [來源](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-191-wrapper-binding-registry-integration.md) `728bf5f312d0959def19e48b53bc3f25cd28a478` | `0x007f6fba` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 192 | [來源](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-192-0007-actor-component-release-crosscheck.md) `b94d840de16d8b1d6b43d9132993b52b8ca03175` | `0x004dff30` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 093 | [來源](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-093-reset-branch-and-parameters.md) `886c94170e3a83f5161c6df9608f2c874f6b3dee` | `0x00490de8` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 094 | [來源](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-094-phase-dispatch-fallback.md) `f5534c77d75aab81b72a448c0901ec552a29a364` | `0x00596245` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 095 | [來源](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-095-mode-subobject-routing.md) `1049f0f0c409d202a552ef35c673051fc0527f89` | `0x005a4614` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T10 | 096 | [來源](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-096-evidence-closure-and-next.md) `951336b952cd2bbf7bf19fa01eb6e31177027ea3` | `0x006d4d8e` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 49 | [來源](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-49-KR-resource-provenance-pe-audit.md) `0df285c934581b93bb2339320a2c8a6e69772675` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 50 | [來源](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-50-KR-lua-bridge-asm.md) `bf3fc0814f75e19ced4ac95bfff6a67ebf4e9564` | `0x006f4a50` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 51 | [來源](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-51-KR-quest-reader-source-boundary.md) `d6591307065c066485ec3e312aafe69b38c72448` | `0x00504740` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 52 | [來源](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-52-KR-quest-authority-handoff.md) `84e4f83eff35ed0c0da23880fe54553bd065b2ef` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T08 | 193 | [來源](../../../kr-temp-roy/20261028-103715-chatgpt-web-roy-T08-193-cmonster-removal-vtable-precleanup-closure.md) `a5b63c691aefc0bb076283d528f8ea4d912eab4f` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 53 | [來源](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-53-KR-quest-native-string-xrefs.md) `8329a3d73f7b1cbf543e07a936bf46927bed6913` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 54 | [來源](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-54-KR-tutorial-lua-direct-call-xrefs.md) `319c873eab18f80db3c464df38b51ab396dc80a7` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 55 | [來源](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-55-KR-quest-loader-caller-evidence.md) `d8100e0a7989a4cc7619b6bf1796e2b0cab9d54d` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 56 | [來源](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-56-KR-authority-gap-next-contract.md) `f6c7a0bb219c11c561e6463a7ae121bf6a41b4f2` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 57 | [來源](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-57-KR-condition-name-resolution-node-graph.md) `1a415a61ed27c2e2abc9ff23be1e821f27839c6d` | `0x0053fd76` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 58 | [來源](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-58-KR-RequestStartScenario-lua-binding-call-path.md) `e839fac14c60b94911f002fed0f04b3631729111` | `0x004ab8f0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 59 | [來源](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-59-KR-QuestInfo-QuestTalk-consecutive-readers.md) `f0edc4812ca0d60bfbd35ed00e79d7498d074b67` | `0x005043d6` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 60 | [來源](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-60-KR-Quest16-Quest15-native-proof-matrix.md) `b91b766bbfd2272dae446c428c600ccaeaec1fa7` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T08 | 194 | [來源](../../../kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-194-bulk-clear-virtual-precleanup.md) `ee3ed3098a9a0a4059f99a0430be4ca151f8e8a0` | `0x004dfe90` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 195 | [來源](../../../kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-195-child-interface-precleanup-abi.md) `90ed8a670620ebe87c6532ebcda881607d410a8f` | `0x004c8360` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 196 | [來源](../../../kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-196-composite-id-secondary-tree-remove.md) `b1879330f55b5d7b6d38a697a46a0f40ce3b6aca` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T10 | 097 | [來源](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-097-dispatch-success-result-list.md) `4384b7604b9ece90d765978d426192585a383000` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T10 | 098 | [來源](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-098-child-selector-and-listener-buckets.md) `868aa5369cb5c062dbe13dccaaeed7cc7da71f91` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T10 | 099 | [來源](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-099-fb73e8-direct-xrefs-and-writer-limits.md) `ecaf018a76ba0e0ab11570a629dfa99fea3aa7f3` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T10 | 100 | [來源](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-100-input-dispatch-closure-matrix.md) `124e47117fee777aea6da73d9fb755fd1915fa9a` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 61 | [來源](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-61-KR-scenario-lua-callback-argument-marshal.md) `d8877384dd938cab6421c67fcc62f451d196ccd5` | `0x004ac9e0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 62 | [來源](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-62-KR-quest-xml-node-consumer-callgraph.md) `e9b16c654215aa1567cb66571d721c1ab01eea97` | `0x0053fdb2` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 63 | [來源](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-63-KR-quest-readers-and-data-lifecycle.md) `26c595c295093777a7153426a16757b11eacec19` | `0x00504370` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 64 | [來源](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-64-KR-end-to-end-quest16-quest15-evidence-gates.md) `dee3295e7cdde882aae96b277d224160420608c8` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T16 | 65 | [來源](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-65-KR-FE187C-writer-callback-initialization.md) `c248ef57f8604d09ed0020c69533b236881cfd5e` | `0x004ab8a0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 66 | [來源](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-66-KR-scenario40-message-dispatch.md) `fd1b40e6dfddc4eb4fd88d7515c6f70f5d674a44` | `0x004aa4d0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 67 | [來源](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-67-KR-scenario-dispatch-state-versus-quest.md) `21e9facd60a283e4b9f097937b98b91defbdb53e` | `0x004aa5a0` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T16 | 68 | [來源](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-68-KR-quest16-quest15-native-handoff.md) `158ceaa7b548c9216e4b14e2dab80f14a6afa0e7` | — | SOURCE-PASS; DOCUMENT-ONLY; SEMANTICS-PENDING |
| T08 | 197 | [來源](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-197-secondary-tree-key-removal.md) `4812aa8da49c40647538206679b414753a4c6e5e` | `0x004dfc30` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 198 | [來源](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-198-conditional-type-removal.md) `0a143c3b3a9fa33976e536dc03848041dcd15ec1` | `0x004dfd40` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 199 | [來源](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-199-bulk-removal-sentinel.md) `195f91121f21352ad2b8f26d16fb534ce4d84a09` | `0x004dfe90` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |
| T08 | 200 | [來源](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-200-registration-identity-and-duplicate.md) `6f867a929563e531a09342c2e0cecafb8d6baf44` | `0x004dff30` | SOURCE-PASS; BYTE-SAMPLE-PASS; SEMANTICS-PENDING |

## 無法取得／未審之證據（不算反證）

- `DEFERRED-RESOURCE`：KR `Event.stp` 原始載體及完整 `TutorialBase.lua`、`TutorialMain.lua`、`qbase.lua`；KR `Table.stp` 的 `QuestInfo.xml` / `QuestTalk.xml` 各 row；只有既有 T01-06 的 resource-source-audit 摘要，不能本批宣稱原始 XML/Lua 已逐欄核對。
- `DEFERRED-TC`：本次未對 TC 原生檔案及其資源另行校驗，不跨版套用 VA/ID。
- `DEFERRED-SERVER`：官方 Quest16→Quest15 實際完成/接受/通知/保存、scenario14 成功/返回、重登角色狀態與伺服器權威。
- `DEFERRED-INPUT`：T10 KeyMapping 原始 XML 與裝置事件 producer、C→S/S→C 普攻連段及非零 phase writer 關聯。
- `SEMANTICS-PENDING`：80 份文件其餘 ASM、CFG、間接 call target、callers/callees、writer/consumer、資料結構、所有權/析構及其主張級反證仍須深入；**本批 byte sample 不可提升整份原稿或 catalog native_complete**。

## 可回溯指令抽樣範例

- `0x004DFF4C: 0F B7 47 04`（movzx，T08 主 key）
- `0x004AB8B8: C7 05 7C 18 FE 00 D0 A4 4A 00`（直接寫 callback slot）
- `0x00560239: 89 1D E8 73 FB 00`（T10 直接 store 指令，但未由這一截確定寫入來源值）
- `0x00504740: 55`、`0x006F4A50: 55`（只確認函式開頭一 byte，不能據此升級整個 loader）

## 結果界線與後續

**本次 80/80 Git blob 核對通過，43/43 本地 BIN raw byte 抽樣符合。** 源文件中列為部分確認或未知的業務規則繼續保持未知；不把來源存在、bytes 相符或前人報告中的「已確認」直接改寫為已完成端到端原生流程。後續逐主張應保存 `source SHA → VA/raw span → 完整指令/CFG → claim → pass/partial/deferred/conflict` 的新台帳，先針對可讀 BIN 擴展，再解除資源與 Server 缺件。
