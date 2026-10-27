# T07 關卡進入與退出

狀態：bounded-review-handoff；負責人未認領。

## 範圍

場景安裝、地圖重設及就緒；生成與勝利分別由 T08/T14 維護

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：原版005F type6建立CDuelField；測試修補改為恢復Tutorial；不能沿用可玩結論
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。原版005F type6建立CDuelField；測試修補改為恢復Tutorial；不能沿用可玩結論
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。

## 依賴、接續與驗收

依賴：T02, T04, T06。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [SCENE-ENTRY-RESET-AND-READY.md](../../../kr/evidence/0bab714e82d96b0f6a4165471fc52531ba4b250f63878e2721bdd706fb8bab37.txt)
- [tutorial_skill_cast.py](../../../kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt)
- [tutorial_monster_config.py](../../../kr/evidence/11ec8d8e1e642d2626727bab0c397e16a0ad1c7b9556fa2d0b3e0121bd0ce9d8.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [tutorial-native-skills-v19.json](../../../unclassified/evidence/22ca3b44b15b76a451af4d3b5bde7da2b856222798a8f9f45f0d909f507f127c.txt)
- [native-index/map-trigger-consumers-audit.json](../../../kr/evidence/272bcb3f233d28886f425035bed0b215e7e3880a8af3fe6cf6f1958fce3d8eab.txt)
- [native-index/scene-controller-audit.json](../../../kr/evidence/2d9e26e98fd3c87bff2a1cc8cea2621a445479a2496487499f6e69aac8264fd6.txt)
- [login_protocol.py](../../../kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt)
- [native-index/single-controller-constructor.txt](../../../unclassified/evidence/37a0121b35abf7977bdfa6e8c1069fad011240e6d0457cf76a8d3a54c4d4bb15.txt)
- [MAINLINE-FLOW.md](../../../unclassified/evidence/3a6376c5d84b4f03edc301d4467746680dfa448efb1df1eb5d2c20e278a20690.txt)
- [audit_scene_entry_lifecycle.py](../../../kr/evidence/3b0fb72a936dcf5c4142d6cb5aff094b75b09feaade4185d5b4923ac3d4fbe5a.txt)
- [native-index/formation-controller-constructor.txt](../../../unclassified/evidence/3e3c1c23b01d2bcd47bac24d4f038164b68d6b644f65d229d9b5d0d9e2d43205.txt)
- [48-tutorial-battle-fixture.md](../../../unclassified/evidence/43aa311555dd6ad2e6843224cf710036c07b390942f7836b58ae9c80de587e59.txt)
- [native-index/native-pipeline-consumer.txt](../../../unclassified/evidence/4b1e0d833bf64bc44f5fcf36939c541109dea640ba11898a0c10611b02df6553.txt)
- [06-runtime-login-fix.md](../../../unclassified/evidence/4d4a53d916b03a6766d33001449ed765af88a1cd1088471dc5bd2b4c6e0c72db.txt)
- [account_store.py](../../../kr/evidence/512368d38b4bc52372e9fc08dbd5d5921827864b1adbfb4e7ba0cb721448d075.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/client-packet-registration.txt](../../../unclassified/evidence/594d603ef6815a4ec7f3e9c5667f106dbe0d9b219399bf8c20b47a214ff8b85e.txt)
- [make_tutorial_transition_probe.py](../../../kr/evidence/5a7ed431c62a10b04772709141aaabbbea7f5c0f9d4cbffc4eb769ff62efc47c.txt)
- [new_expedition.py](../../../kr/evidence/5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534.txt)
- [native-index/scene-entry-lifecycle-audit.json](../../../kr/evidence/65fcc929b4ca918c01643028c1057967ade7c2769382236e4c2971d7b4f6b086.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [tutorial-transition-disassembly.txt](../../../unclassified/evidence/6d2afd42a99891a06b46c7e2bec4646f63b0e8b28229c771c5889c0b9866e7d2.txt)
- [tutorial-transition-probe.json](../../../unclassified/evidence/6dedb2c94c69132d1d00c1345ab4ec582efadcf2928ac9e82d8e45bdc19654cd.txt)
- [audit_receive_dispatch.py](../../../kr/evidence/6edd738baf3155447230b055dade20c5b5172fb59302f80345fb15067bfec006.txt)
- [native-index/native-receive-frame-parser.txt](../../../unclassified/evidence/729f62d279cdf7d09d62795b72d55f22fe86db3a51fa22d3cd4ad3be8c81f795.txt)
- [native-index/native-pipeline-pop.txt](../../../unclassified/evidence/7fff352733c5845e85e912eb8a599e1986422cc761fdb7bd09ae49e24e451612.txt)
- [native-index/client-default-to-scene-manager.txt](../../../unclassified/evidence/85bd97b43752ff0ca9d49947f695c1a2bd053515366f1b79ea45dab06445aa3d.txt)
- [SCENE-CONTROLLER-SELECTION.md](../../../kr/evidence/8762287177ecd19a4bf1b4a21c8e311a58733e962b1bacc28c6c1461e02b7bb3.txt)
- [native-index/decision-scene-overlay-dispatch.txt](../../../unclassified/evidence/89e2dc31c862bfc2f9c2ca6ac6b8f107367b418cc40cd1f13651f6af7515e814.txt)
- [native-index/client-receive-callback.txt](../../../unclassified/evidence/8f0ee00805db0d5429f096b7561bc0b407a85862e7273d05e037c86f6da201f9.txt)
- [native-index/field-scene-overlay-dispatch.txt](../../../unclassified/evidence/96adf4bbffa8a04d655a6765ec7b10303f5b59e9c14f9f9509db4bcc901bf82e.txt)
- [native-index/receive-dispatch-audit.json](../../../kr/evidence/98bb5f4494347a2262c23cfe789a9652f29cfe37db9f630f2272ba91f6a74af5.txt)
- [plaza_npcs.py](../../../kr/evidence/9a9e396000323e0b7359afeb933922ce3ff40b50a4dedd982ed752b2fe228e49.txt)
- [native-index/client-packet-dispatch.txt](../../../unclassified/evidence/a6c4aa13af24ed13272accd7c43d01ba7e06c73af4cece2d98eda09cbc1f159d.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [audit_map_trigger_consumers.py](../../../kr/evidence/c01c9d6fd8ca2d63f0c42e3ea835da5217905294065d4852fdc8fe2a723d8d7e.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [native-index/client-packet-overrides.json](../../../unclassified/evidence/e874221a59968898d4e9656de7d88f7d1a2cb176dd54bce9f238494df9fe7224.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [native-index/native-pipeline-push.txt](../../../unclassified/evidence/f32c35238a71d659fdbc086b0ba5a0545fff6c164e99215f48fb28ca189c6b6c.txt)
- [audit_scene_controllers.py](../../../kr/evidence/fd26185a16f71126adee2347d1bb9a14152c42669955dc8ad46556d460f3f7c1.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。

## 兩村切城接續需求（行政交接，非新原生結論）

使用者已指定由其他對話接續T07；roy/T06保持只引用。請讀[具體問題、已存raw/pseudo與驗收邊界](../../../shared/T07-TOWN-ENTRY-DEPENDENCY-HANDOFF.md)，先認領再分析；未變更本任務owner/state。


2026-10-26 T01 整合交接：[T01-20261026-01](../../../shared/integrations/T01-20261026-01/README.md)。僅列明 SHA 的凍結成果已整合；其他暫存／新修改仍待下一輪。各任務未整體完成，接續前以此批次所在 origin/main commit 為基準。


2026-10-27 來源整合：[T01-20261027-03](../../../shared/integrations/T01-20261027-03/README.md)。只接受列明 SHA 與限定結論；其他暫存及整體功能未完成。本批已推送至 origin/main，接續基準 `d370a01645218615ad42595071c5328077e643a7`；推送收據見批次紀錄。


2026-10-27 新批次整合：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。比對來源SHA、限定結論及待核對映射；本批未把整份報告／函式或整項任務標完成。實際遠端接續基準見批次push-receipt.json。


2026-10-27 接續來源更正：[T01-20261027-05](../../../shared/integrations/T01-20261027-05/README.md)，含早期網路／map／碰撞筆記的去重與限定，實際接續SHA見收據。
