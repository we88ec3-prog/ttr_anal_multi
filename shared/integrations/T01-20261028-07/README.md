# T01-20261028-07 — 線上新研究提交增量來源登記

> 本批是 GitHub `main` 上已存在檔案的**來源索引與待審核收件紀錄**，不是重新上傳原稿，也不表示完成原生機器碼、控制流程或語意驗收。

- 前次整合基準：`b8c95431063436d24ca473876b937e4a9152210d`（T01-20261028-06）。
- 本輪觀測 HEAD：`944f06c046236afa97e1c9a46a9b5c9c3596ed4a`。
- Git compare：`b8c9543...944f06c04623`，ahead `93` commits；比較介面回傳 99 項變更。
- 可辨識新研究原稿：80 份（T08 28、T10 20、T16 32）；全部已在 main，**不重複複製**。
- 其他 19 項含前批 T01-20261028-06 的後補推送收據、相關任務檔案更新等；不在本輪重複採認。

## 范圍、歸屬與審核門檻

- T08：`173–200`，28 份；生命週期、索引與移除/登記等主題；保留 T08 原方法歸屬。
- T10：`081–100`，20 份；KeyMapping、輸入 phase、事件派送、writer/consumer 缺口；不因標題「complete」就視為功能鏈全部閉合。
- T16：`41–68`，32 份；其中 41–44 各有兩份**不同原稿**，不可單憑段號去重或擇新覆蓋；後續應做主張層級證據仲裁。T16 仍維持既有 owner／狀態，不自動認領。
- 本次未做原始 BIN 逐位址與全 CFG 重驗，未修改 `shared/catalog.json`、`shared/source-review-status.json`、KR/TC Task owner，亦未將任何新增主張標為 `native_confirmed`。
- 研究原稿 Git blob SHA 是**檔案版本鍵**，不能取代原始 `Tartaros.bin` 的 target SHA；跨版本仍需獨立驗證。

## 待審核來源逐檔清單

| Task | 段號 | 檔案（main） | Blob SHA |
|---|---:|---|---|
| T10 | 081 | [kr-temp-roy/20261028-085723-chatgpt-web-roy-T10-081-native-keymapping-resource-recovery.md](../../../kr-temp-roy/20261028-085723-chatgpt-web-roy-T10-081-native-keymapping-resource-recovery.md) | `882743a9197fff2a5a1d7c189c5d301c8a9da8a4` |
| T16 | 41 | [kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-41-KR-Lua-tutorial-static-source-audit.md](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-41-KR-Lua-tutorial-static-source-audit.md) | `709dc7206d8ef70024a2f77de79d86ce3c557cc7` |
| T16 | 42 | [kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-42-KR-QuestXML-source-inventory-and-schema-gates.md](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-42-KR-QuestXML-source-inventory-and-schema-gates.md) | `97773d959e623df88dec3a4506ebd83c8ac9c115` |
| T16 | 43 | [kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-43-KR-tutorial-to-mainline-evidence-edges.md](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-43-KR-tutorial-to-mainline-evidence-edges.md) | `2feafd823d0de32ec1b2503df9fa2a9c2b3c1856` |
| T16 | 44 | [kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-44-KR-quest-state-authority-and-acceptance.md](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-44-KR-quest-state-authority-and-acceptance.md) | `c7d68207f95fd2ceb1d9ad8cbe4d5410e04e8f41` |
| T08 | 173 | [kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-173-owner-44-writers.md](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-173-owner-44-writers.md) | `f643553ef1145ed65a5a724a0a9a3f19c910e76f` |
| T08 | 174 | [kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-174-deferred-queue-consumer.md](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-174-deferred-queue-consumer.md) | `c56a5cae912d81bfad8141eeeaaa3b83016e209b` |
| T08 | 175 | [kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-175-release-protocol.md](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-175-release-protocol.md) | `7af6cbd50284aee17caf4b77912b1a708a239efe` |
| T08 | 176 | [kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-176-ownership-lifecycle-audit.md](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-176-ownership-lifecycle-audit.md) | `735c789499a8af2581f748dc766de87a417def90` |
| T08 | 177 | [kr-temp-roy/20261028-094900-chatgpt-web-roy-T08-177-owner-mode-caller-drain-closure.md](../../../kr-temp-roy/20261028-094900-chatgpt-web-roy-T08-177-owner-mode-caller-drain-closure.md) | `fdc8a64aa0f33866defe5a2484fa432f4bbaf66c` |
| T10 | 082 | [kr-temp-roy/20261028-094926-chatgpt-web-roy-T10-082-keymapping-runtime-xrefs.md](../../../kr-temp-roy/20261028-094926-chatgpt-web-roy-T10-082-keymapping-runtime-xrefs.md) | `4a3f3028ffc003883430eaf88c70852cc6314ab4` |
| T16 | 41 | [kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-41-KR-tutorial-Lua-provenance-and-entry.md](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-41-KR-tutorial-Lua-provenance-and-entry.md) | `46d93721bb6a343d83a00fa5cfe2283b33e16337` |
| T16 | 42 | [kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-42-KR-quest-XML-versioned-source.md](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-42-KR-quest-XML-versioned-source.md) | `77b960803fe95ba9fc5dd7a7f086dcc79c05b6e4` |
| T16 | 43 | [kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-43-KR-tutorial-to-quest16-quest15-evidence.md](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-43-KR-tutorial-to-quest16-quest15-evidence.md) | `22c02f093ab0e8804e42ec5b071c9fb316e9bebc` |
| T16 | 44 | [kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-44-KR-quest-state-authority-acceptance.md](../../../kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-44-KR-quest-state-authority-acceptance.md) | `8262d45d0f8cf5672ff4617d2c0ac741d764c205` |
| T08 | 178 | [kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-178-mode-two-container-callback-boundary.md](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-178-mode-two-container-callback-boundary.md) | `a338ee89963c817f50010ddec3a2985d6603beee` |
| T08 | 179 | [kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-179-last-reference-registry-release.md](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-179-last-reference-registry-release.md) | `76e410b206bde1e85444134303da17b0242794f0` |
| T08 | 180 | [kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-180-formal-0007-resource-interface-audit.md](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-180-formal-0007-resource-interface-audit.md) | `4ab548ce691aca8e04f0be4ec83899d577290719` |
| T10 | 083 | [kr-temp-roy/20261028-095434-chatgpt-web-roy-T10-083-working-bank-configuration.md](../../../kr-temp-roy/20261028-095434-chatgpt-web-roy-T10-083-working-bank-configuration.md) | `3097b2d57a62703d31bb59409283ac4e00becf33` |
| T10 | 084 | [kr-temp-roy/20261028-095435-chatgpt-web-roy-T10-084-phase-dispatch-boundaries.md](../../../kr-temp-roy/20261028-095435-chatgpt-web-roy-T10-084-phase-dispatch-boundaries.md) | `91fcdcce12d14724648650829e971a380be25ecf` |
| T08 | 181 | [kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-181-reuse-pool-acquisition-and-count-separation.md](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-181-reuse-pool-acquisition-and-count-separation.md) | `2f0175b00bd9f96ec62b92065a832693b4cebe6a` |
| T08 | 182 | [kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-182-mode-switch-and-binding-boundary.md](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-182-mode-switch-and-binding-boundary.md) | `f9717b667a90cee6a554f04d4070472e643918bb` |
| T08 | 183 | [kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-183-manager-last-release-and-container-destruction.md](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-183-manager-last-release-and-container-destruction.md) | `ecbec611a9d99a7640ae4fad9668dcc3c06ad4be` |
| T08 | 184 | [kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-184-0007-scene-actor-resource-ownership-interface.md](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-184-0007-scene-actor-resource-ownership-interface.md) | `55058a01ad35dc4f01c49ab781780e556ef506ee` |
| T10 | 085 | [kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-085-phase-reset-and-event-map.md](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-085-phase-reset-and-event-map.md) | `cf1906f0c6f6d09846d1aefc45736d0f6eb1d706` |
| T10 | 086 | [kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-086-fb73e8-transition.md](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-086-fb73e8-transition.md) | `c5290e18160287e2e77ea430b4b26697fcac6b3f` |
| T10 | 087 | [kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-087-dispatch-consumer.md](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-087-dispatch-consumer.md) | `161febaa46a936da40588783860ef904b0e620cf` |
| T10 | 088 | [kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-088-producer-gap-and-next.md](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-088-producer-gap-and-next.md) | `54a205919cb7cbb180610439067aa85eef1815c9` |
| T16 | 45 | [kr-temp-roy/20261028-101028-chatgpt-web-roy-T16-45-KR-Lua-XML-source-and-BIN-validation.md](../../../kr-temp-roy/20261028-101028-chatgpt-web-roy-T16-45-KR-Lua-XML-source-and-BIN-validation.md) | `8067059908d888141c8d7b4a12b80eb6b427e49c` |
| T10 | 089 | [kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-089-event-container-callers.md](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-089-event-container-callers.md) | `b9522feee0464b68ead6ff1ea09f84e09a168510` |
| T10 | 090 | [kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-090-fb73e8-reader-audit.md](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-090-fb73e8-reader-audit.md) | `d232cee52ae99734bdae7229a5c1e0e9f2451bd5` |
| T10 | 091 | [kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-091-conditional-child-selector.md](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-091-conditional-child-selector.md) | `6f76c33948d04582983855a574dabe64eb185599` |
| T10 | 092 | [kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-092-mapping-consumer-domain.md](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-092-mapping-consumer-domain.md) | `4902528ed87c5ecfc0477cb248794ea1bd937f4c` |
| T08 | 185 | [kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-185-registry-node-virtual-callback-disposal.md](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-185-registry-node-virtual-callback-disposal.md) | `24077d1529e6031fa9fda874ac14b2b79b5ccb7f` |
| T08 | 186 | [kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-186-manager-destructor-buffer-lock-order.md](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-186-manager-destructor-buffer-lock-order.md) | `2e9880fdf0b4a0bec0b2f92dfc401f0013439a1a` |
| T08 | 187 | [kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-187-acquire-wrapper-and-resource-return.md](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-187-acquire-wrapper-and-resource-return.md) | `cf2b5d3fc74b6d0199837c957a214765ac14866f` |
| T08 | 188 | [kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-188-actor-registry-and-resource-lifetime-gap.md](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-188-actor-registry-and-resource-lifetime-gap.md) | `115bbbf2b6005d2920cc46f606763c3ff8b8d687` |
| T16 | 46 | [kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-46-KR-tutorial-lua-opcode-cfg.md) | `dea68e6db1af124ecdaca7943a877a7dbddd2377` |
| T16 | 47 | [kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-47-KR-quest16-quest15-source-schema.md](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-47-KR-quest16-quest15-source-schema.md) | `fef1cae164a07377ce29b8586453e385bd05520c` |
| T16 | 48 | [kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-48-KR-quest-authority-validation-matrix.md](../../../kr-temp-roy/20261028-101606-chatgpt-web-roy-T16-48-KR-quest-authority-validation-matrix.md) | `e4633cecbb8531a950a4d15f24d7db5ae4fd6529` |
| T08 | 189 | [kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-189-registry-lookup-payload-vcall-boundary.md](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-189-registry-lookup-payload-vcall-boundary.md) | `a593f50abda9dc3523e07c727c8eeab6d3ae4514` |
| T08 | 190 | [kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-190-resource-counter-acquire-release-balance.md](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-190-resource-counter-acquire-release-balance.md) | `a633fc34c161afd168b74ba1f35a6fcf3fd17c33` |
| T08 | 191 | [kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-191-wrapper-binding-registry-integration.md](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-191-wrapper-binding-registry-integration.md) | `728bf5f312d0959def19e48b53bc3f25cd28a478` |
| T08 | 192 | [kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-192-0007-actor-component-release-crosscheck.md](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-192-0007-actor-component-release-crosscheck.md) | `b94d840de16d8b1d6b43d9132993b52b8ca03175` |
| T10 | 093 | [kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-093-reset-branch-and-parameters.md](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-093-reset-branch-and-parameters.md) | `886c94170e3a83f5161c6df9608f2c874f6b3dee` |
| T10 | 094 | [kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-094-phase-dispatch-fallback.md](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-094-phase-dispatch-fallback.md) | `f5534c77d75aab81b72a448c0901ec552a29a364` |
| T10 | 095 | [kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-095-mode-subobject-routing.md](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-095-mode-subobject-routing.md) | `1049f0f0c409d202a552ef35c673051fc0527f89` |
| T10 | 096 | [kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-096-evidence-closure-and-next.md](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-096-evidence-closure-and-next.md) | `951336b952cd2bbf7bf19fa01eb6e31177027ea3` |
| T16 | 49 | [kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-49-KR-resource-provenance-pe-audit.md](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-49-KR-resource-provenance-pe-audit.md) | `0df285c934581b93bb2339320a2c8a6e69772675` |
| T16 | 50 | [kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-50-KR-lua-bridge-asm.md](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-50-KR-lua-bridge-asm.md) | `bf3fc0814f75e19ced4ac95bfff6a67ebf4e9564` |
| T16 | 51 | [kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-51-KR-quest-reader-source-boundary.md](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-51-KR-quest-reader-source-boundary.md) | `d6591307065c066485ec3e312aafe69b38c72448` |
| T16 | 52 | [kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-52-KR-quest-authority-handoff.md](../../../kr-temp-roy/20261028-103208-chatgpt-web-roy-T16-52-KR-quest-authority-handoff.md) | `84e4f83eff35ed0c0da23880fe54553bd065b2ef` |
| T08 | 193 | [kr-temp-roy/20261028-103715-chatgpt-web-roy-T08-193-cmonster-removal-vtable-precleanup-closure.md](../../../kr-temp-roy/20261028-103715-chatgpt-web-roy-T08-193-cmonster-removal-vtable-precleanup-closure.md) | `a5b63c691aefc0bb076283d528f8ea4d912eab4f` |
| T16 | 53 | [kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-53-KR-quest-native-string-xrefs.md](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-53-KR-quest-native-string-xrefs.md) | `8329a3d73f7b1cbf543e07a936bf46927bed6913` |
| T16 | 54 | [kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-54-KR-tutorial-lua-direct-call-xrefs.md](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-54-KR-tutorial-lua-direct-call-xrefs.md) | `319c873eab18f80db3c464df38b51ab396dc80a7` |
| T16 | 55 | [kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-55-KR-quest-loader-caller-evidence.md](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-55-KR-quest-loader-caller-evidence.md) | `d8100e0a7989a4cc7619b6bf1796e2b0cab9d54d` |
| T16 | 56 | [kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-56-KR-authority-gap-next-contract.md](../../../kr-temp-roy/20261028-103816-chatgpt-web-roy-T16-56-KR-authority-gap-next-contract.md) | `f6c7a0bb219c11c561e6463a7ae121bf6a41b4f2` |
| T16 | 57 | [kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-57-KR-condition-name-resolution-node-graph.md](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-57-KR-condition-name-resolution-node-graph.md) | `1a415a61ed27c2e2abc9ff23be1e821f27839c6d` |
| T16 | 58 | [kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-58-KR-RequestStartScenario-lua-binding-call-path.md](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-58-KR-RequestStartScenario-lua-binding-call-path.md) | `e839fac14c60b94911f002fed0f04b3631729111` |
| T16 | 59 | [kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-59-KR-QuestInfo-QuestTalk-consecutive-readers.md](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-59-KR-QuestInfo-QuestTalk-consecutive-readers.md) | `f0edc4812ca0d60bfbd35ed00e79d7498d074b67` |
| T16 | 60 | [kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-60-KR-Quest16-Quest15-native-proof-matrix.md](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-60-KR-Quest16-Quest15-native-proof-matrix.md) | `b91b766bbfd2272dae446c428c600ccaeaec1fa7` |
| T08 | 194 | [kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-194-bulk-clear-virtual-precleanup.md](../../../kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-194-bulk-clear-virtual-precleanup.md) | `ee3ed3098a9a0a4059f99a0430be4ca151f8e8a0` |
| T08 | 195 | [kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-195-child-interface-precleanup-abi.md](../../../kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-195-child-interface-precleanup-abi.md) | `90ed8a670620ebe87c6532ebcda881607d410a8f` |
| T08 | 196 | [kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-196-composite-id-secondary-tree-remove.md](../../../kr-temp-roy/20261028-110153-chatgpt-web-roy-T08-196-composite-id-secondary-tree-remove.md) | `b1879330f55b5d7b6d38a697a46a0f40ce3b6aca` |
| T10 | 097 | [kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-097-dispatch-success-result-list.md](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-097-dispatch-success-result-list.md) | `4384b7604b9ece90d765978d426192585a383000` |
| T10 | 098 | [kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-098-child-selector-and-listener-buckets.md](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-098-child-selector-and-listener-buckets.md) | `868aa5369cb5c062dbe13dccaaeed7cc7da71f91` |
| T10 | 099 | [kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-099-fb73e8-direct-xrefs-and-writer-limits.md](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-099-fb73e8-direct-xrefs-and-writer-limits.md) | `ecaf018a76ba0e0ab11570a629dfa99fea3aa7f3` |
| T10 | 100 | [kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-100-input-dispatch-closure-matrix.md](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-100-input-dispatch-closure-matrix.md) | `124e47117fee777aea6da73d9fb755fd1915fa9a` |
| T16 | 61 | [kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-61-KR-scenario-lua-callback-argument-marshal.md](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-61-KR-scenario-lua-callback-argument-marshal.md) | `d8877384dd938cab6421c67fcc62f451d196ccd5` |
| T16 | 62 | [kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-62-KR-quest-xml-node-consumer-callgraph.md](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-62-KR-quest-xml-node-consumer-callgraph.md) | `e9b16c654215aa1567cb66571d721c1ab01eea97` |
| T16 | 63 | [kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-63-KR-quest-readers-and-data-lifecycle.md](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-63-KR-quest-readers-and-data-lifecycle.md) | `26c595c295093777a7153426a16757b11eacec19` |
| T16 | 64 | [kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-64-KR-end-to-end-quest16-quest15-evidence-gates.md](../../../kr-temp-roy/20261028-110252-chatgpt-web-roy-T16-64-KR-end-to-end-quest16-quest15-evidence-gates.md) | `dee3295e7cdde882aae96b277d224160420608c8` |
| T16 | 65 | [kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-65-KR-FE187C-writer-callback-initialization.md](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-65-KR-FE187C-writer-callback-initialization.md) | `c248ef57f8604d09ed0020c69533b236881cfd5e` |
| T16 | 66 | [kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-66-KR-scenario40-message-dispatch.md](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-66-KR-scenario40-message-dispatch.md) | `fd1b40e6dfddc4eb4fd88d7515c6f70f5d674a44` |
| T16 | 67 | [kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-67-KR-scenario-dispatch-state-versus-quest.md](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-67-KR-scenario-dispatch-state-versus-quest.md) | `21e9facd60a283e4b9f097937b98b91defbdb53e` |
| T16 | 68 | [kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-68-KR-quest16-quest15-native-handoff.md](../../../kr-temp-roy/20261028-110904-chatgpt-web-roy-T16-68-KR-quest16-quest15-native-handoff.md) | `158ceaa7b548c9216e4b14e2dab80f14a6afa0e7` |
| T08 | 197 | [kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-197-secondary-tree-key-removal.md](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-197-secondary-tree-key-removal.md) | `4812aa8da49c40647538206679b414753a4c6e5e` |
| T08 | 198 | [kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-198-conditional-type-removal.md](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-198-conditional-type-removal.md) | `0a143c3b3a9fa33976e536dc03848041dcd15ec1` |
| T08 | 199 | [kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-199-bulk-removal-sentinel.md](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-199-bulk-removal-sentinel.md) | `195f91121f21352ad2b8f26d16fb534ce4d84a09` |
| T08 | 200 | [kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-200-registration-identity-and-duplicate.md](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-200-registration-identity-and-duplicate.md) | `6f867a929563e531a09342c2e0cecafb8d6baf44` |

## 後續整合工作

1. 逐篇比對前批 `accepted-claims.json`、`resolutions.json`、`shared/source-review-status.json`，按**來源 SHA＋主張＋版本**去重；T16-41～44 必須明示雙原稿衝突或互補關係。
2. 對新主張逐項取得 BIN bytes、PE/flat 映射與反證，才可調整 catalog／source-review 狀態；source-only 原稿先保留 `pending`。
3. 跨 T08/T10/T16 的相同地址或術語不等於相同方法 owner。不得因收件更動 T04/T07/T14/T15 等任務範圍。
4. 在沒有本地工作樹、後續對話未提交檔案的可驗證來源時，本清單僅覆蓋上述 Git 比較範圍，不聲稱涵蓋其他尚未上傳成果。

## 收件校核

- 檔案來自 GitHub Compare API 中的原始路徑與 blob SHA。
- 本批內容不涉及遊戲執行、附加、修改或腳本執行。
- 建立此收件紀錄之 commit 應另行從遠端回讀驗證；HEAD 比對基準為 `944f06c046236afa97e1c9a46a9b5c9c3596ed4a`。
