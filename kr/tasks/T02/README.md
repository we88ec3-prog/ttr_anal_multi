# T02 共用通訊與封包框架

狀態：bounded-review-handoff；負責人未認領。

## 範圍

封包邊界、連線角色與分派；業務欄位交對應任務

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：傳輸封裝與官方連線時序未完整確認
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。傳輸封裝與官方連線時序未完整確認
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **原生已確認**：C2S000A前置6 bytes，row為5 bytes；F93944欄位正式語意仍未知。

## 依賴、接續與驗收

依賴：版本共用證據。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [native-index/network-connect-and-slot-map.txt](../../../unclassified/evidence/0372486cd2ae892bc3c089420678be615beeeee02664997ddf53be5ba55bfea9.txt)
- [native-index/battle-input-batch-producer.txt](../../../unclassified/evidence/0815371627e08a9ce0e2c3bd049b3e9b38a563ccae35282295d3167d1e24f046.txt)
- [native-index/battle-input-socket-worker.txt](../../../unclassified/evidence/172d170a21ef8fedc0bd04c0fd9bf0dcb88da582fa7a2b15072630f554371bee.txt)
- [BATTLE-INPUT-TO-SOCKET.md](../../../kr/evidence/1e15689d7bbdf4c4a83ae76cf1813d538b8cb38db79098c6b85ba386056dab36.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [native-index/nested-data-00c1.txt](../../../unclassified/evidence/247951f54248416a12dc4edf4a17a63b09762bc591c2778169c178034d839914.txt)
- [native-index/nested-item-slots-00c3.txt](../../../unclassified/evidence/27a4711fde3fc98f1a5d8a2452715f9618c276eab286ff61fbaa73a081d38bce.txt)
- [NESTED-DATA-AND-TCP-TYPES.md](../../../kr/evidence/2a2bb12081b77f189328db79ab8a65a2e43fc4cc901f072880701ff63bd484c8.txt)
- [native-index/item-product-lookup.txt](../../../unclassified/evidence/2a3b2c54cbada079cfc5d44506cb37bc32e4636ed2d62e770c80029c9ba34277.txt)
- [login_protocol.py](../../../kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt)
- [native-index/connection-route-audit.json](../../../kr/evidence/2fa2401ccc630b0feb26350f98fdb24062358f757a175e65c25ccc292bd4341a.txt)
- [audit_nested_data_and_tcp_types.py](../../../kr/evidence/43950661891e72341377f00557ee524eb1e371fb2932a54e1d4090721b123883.txt)
- [RECEIVE-AND-SCENE-DISPATCH.md](../../../kr/evidence/4a64b51809c87fe6c8bab24f033fb4c94964a8e403e861be22e8210d3f639b8e.txt)
- [native-index/native-pipeline-consumer.txt](../../../unclassified/evidence/4b1e0d833bf64bc44f5fcf36939c541109dea640ba11898a0c10611b02df6553.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/battle-input-packet-copy.txt](../../../unclassified/evidence/588f5dc116999cb57a48fed1d3db37f0935618529dd97ece4a2aaffa7a244b5b.txt)
- [native-index/client-packet-registration.txt](../../../unclassified/evidence/594d603ef6815a4ec7f3e9c5667f106dbe0d9b219399bf8c20b47a214ff8b85e.txt)
- [native-index/battle-input-network-slot-send.txt](../../../unclassified/evidence/67682cca0b94bc1698d95851c3f8b7e5d666fa653a33d90b225c5c52f8730c1c.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [audit_receive_dispatch.py](../../../kr/evidence/6edd738baf3155447230b055dade20c5b5172fb59302f80345fb15067bfec006.txt)
- [native-index/native-receive-frame-parser.txt](../../../unclassified/evidence/729f62d279cdf7d09d62795b72d55f22fe86db3a51fa22d3cd4ad3be8c81f795.txt)
- [audit_battle_input_transport.py](../../../kr/evidence/74754a41cc22cc3766d83a94e1043b3521951faff7f6bb46bdf30392d7931acd.txt)
- [audit_connection_routes.py](../../../kr/evidence/7a32458fe1301b7f9161a3c495c1716e94bfa3c259472afcf5c8992433f0f4f0.txt)
- [native-index/network-overlapped-wsasend.txt](../../../unclassified/evidence/7f5642ef15578b61a3491e8663e77e15876e3ec8a85ef0d2004671019cac8e9d.txt)
- [native-index/native-pipeline-pop.txt](../../../unclassified/evidence/7fff352733c5845e85e912eb8a599e1986422cc761fdb7bd09ae49e24e451612.txt)
- [native-index/client-default-to-scene-manager.txt](../../../unclassified/evidence/85bd97b43752ff0ca9d49947f695c1a2bd053515366f1b79ea45dab06445aa3d.txt)
- [native-index/decision-scene-overlay-dispatch.txt](../../../unclassified/evidence/89e2dc31c862bfc2f9c2ca6ac6b8f107367b418cc40cd1f13651f6af7515e814.txt)
- [native-index/nested-item-slot-clear.txt](../../../unclassified/evidence/8d8f7c345bdec3fe5fd7c5394fb696a0d6196a6a6e345ed07b21bb2e4475701a.txt)
- [native-index/client-receive-callback.txt](../../../unclassified/evidence/8f0ee00805db0d5429f096b7561bc0b407a85862e7273d05e037c86f6da201f9.txt)
- [native-index/battle-input-row-append.txt](../../../unclassified/evidence/91df777cd65f424ef5e91e8d22635a0e80381ef2396b11a4d200da7440488ec6.txt)
- [native-index/nested-item-result-00c4.txt](../../../unclassified/evidence/922d9b6bbb5535a6108ba05ee750b47ce4badfcb1ad6218c0f4fafee42d59b77.txt)
- [native-index/field-scene-overlay-dispatch.txt](../../../unclassified/evidence/96adf4bbffa8a04d655a6765ec7b10303f5b59e9c14f9f9509db4bcc901bf82e.txt)
- [native-index/receive-dispatch-audit.json](../../../kr/evidence/98bb5f4494347a2262c23cfe789a9652f29cfe37db9f630f2272ba91f6a74af5.txt)
- [native-index/client-packet-dispatch.txt](../../../unclassified/evidence/a6c4aa13af24ed13272accd7c43d01ba7e06c73af4cece2d98eda09cbc1f159d.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/nested-item-slots-00c2.txt](../../../unclassified/evidence/b550279a1a51d972a2d283bf402d835c1a6792a0d18d4e8a28e095118bd9d7b3.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [CONNECTION-ROLES-AND-HANDOFF.md](../../../kr/evidence/bcc93c2f8128b12d86fd1e296198e4e1735fd410336510b15c58415b6a0c9ced.txt)
- [native-index/nested-data-tcp-type-audit.json](../../../kr/evidence/bd39e3e5451a279157759ced7e0b4e52c47511708b1480a70391382a5cc3cf87.txt)
- [native-index/nested-item-slot-assignment.txt](../../../unclassified/evidence/bf81638e4ee6b933eb59c7afe64aa150ab74d5fccb61f6155e1a515c3ce52322.txt)
- [native-index/battle-input-connection-framing.txt](../../../unclassified/evidence/cafb013e5bbd93cfa8b7d85af36cc32c61807a612ac95069cc55c8f0b4f0b96e.txt)
- [native-index/network-close-connection.txt](../../../unclassified/evidence/db5aafa5b1384358c3eb777361b2fcc9974e9b69c0bd6f9ef014cb15523f9014.txt)
- [native-index/battle-input-transport-audit.json](../../../kr/evidence/dd0ce08b9da2191d41341ed42c2f3e2c86c6ffdea781395adfc1b44c740940a8.txt)
- [native-index/client-connect-selection.txt](../../../unclassified/evidence/e818a6e78620d6daf9ed8f3cd092c1edfbe7d97341f2c835417b1765e5a9fc69.txt)
- [native-index/client-packet-overrides.json](../../../unclassified/evidence/e874221a59968898d4e9656de7d88f7d1a2cb176dd54bce9f238494df9fe7224.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [native-index/client-connect-initial-pair.txt](../../../unclassified/evidence/ee45c7daf0bca3b5e4ee856f171a995af789a6d735b20f08b455d0c886ab9794.txt)
- [native-index/native-pipeline-push.txt](../../../unclassified/evidence/f32c35238a71d659fdbc086b0ba5a0545fff6c164e99215f48fb28ca189c6b6c.txt)
- [native-index/battle-input-connection-queue.txt](../../../unclassified/evidence/f7402fb5881f2eff0a3a56b4fe54072ce4b3635c213a8cd17ac47b018f7e4163.txt)
- [native-index/scene-manager-current-handoff.txt](../../../unclassified/evidence/fb45bc0938a4f022f2a7fc4f9180a5cb75f8d3ff2217cca37c99df6b5724909b.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
