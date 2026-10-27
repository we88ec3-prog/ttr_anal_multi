# T09 關卡內移動與同步

狀態：bounded-review-handoff；負責人未認領。

## 範圍

共用 actor 移動、位置旗標、碰撞邊界及校正；不制定決策

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：原生命令產生權責、碰撞細節及校正來源仍未知
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。原生命令產生權責、碰撞細節及校正來源仍未知
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。

## 依賴、接續與驗收

依賴：T02, T04, T06, T08。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [POSITION-UPDATE-AND-MOVEMENT-WRITERS.md](../../../kr/evidence/00d7c1b55f3b4514fdf9db13874bc6008a563ca3e7d7d116036029327c83617e.txt)
- [native-index/shared-actor-motion-setter.txt](../../../kr/evidence/0443bd467294aa34c424df63fff977774d3d4133960bd360f7c9ab0343d49efb.txt)
- [native-index/register-StopObject.txt](../../../kr/evidence/0985f21fc270fcb24a2246c02b789d73b71832e971b3a999f1e9704a07362ec1.txt)
- [kr-frame-dispatch-20261023/native/mcp-evidence/03-function-490fe0.json](../../../kr/evidence/0e3dd3d66fda572b607776ea6189b8ac82e4153764cf1751bac81df52d16f265.txt)
- [native-index/duel-decision-stop-reset.txt](../../../kr/evidence/0fc454fed0ee52753b8712254d643b2e569536c8c44c4526318dbb1b2cd87f0a.txt)
- [native-index/actor-input-phase.txt](../../../unclassified/evidence/19ac9d151365da67b763ed9f86ced86a69c918f793bd9ca5b96413e8977e4db2.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [native-index/script-WarpObject.txt](../../../kr/evidence/25f09b3e51f1fafe23f2230266e30eef827ac9bbdf0b81586a8f630b46bf1577.txt)
- [native-index/register-AniObject.txt](../../../kr/evidence/26ccf40d9cb45eb4c68d7ca25255364a36bc5f020bcbf26cd19f57558f22fa16.txt)
- [native-index/actor-target-position-receive.txt](../../../unclassified/evidence/2cf70c84f011058dafcddf8fe7c503be448995098cc585b72eedf743fffc19a2.txt)
- [kr-frame-dispatch-20261023/identity.json](../../../kr/evidence/2d9fc381a82a8f0d93ad2b4bca23c6c9c5e31ab4556c81d14b5181bc794da9d2.txt)
- [native-index/native-heading-smoothing.txt](../../../unclassified/evidence/30c483947738a3772dc8702172172c6aeae05093c1dde13a447d83c68cc6a770.txt)
- [native-index/lua-StopObject-wrapper.txt](../../../kr/evidence/311d9e05031ec48a6379787554b8ff4fb7edc6a30434a93c0be55b6fe535e296.txt)
- [native-index/event-actor-target-direction.txt](../../../kr/evidence/32319c0978a795fab1b1f429bb1149a9007dd9ca07c436a63250cad7778e530d.txt)
- [audit_script_object_motion.py](../../../kr/evidence/3784075d4a7148da5007f07f7a40abcc64a75f4f949b0ea1fa56e692d968fdc6.txt)
- [SCRIPT-OBJECT-MOTION-BOUNDARY.md](../../../kr/evidence/3db1e759b68fb22ca16a0b268f557a2dba2d00cd4f73ebdaaf76f33a40da49a2.txt)
- [ACTOR-TARGET-POSITION-SOURCE.md](../../../kr/evidence/4409808e43eabea02d3d18aac8e9fa705932c84faf01079a96239fcb12f41ae7.txt)
- [native-index/monster-effective-speed.txt](../../../unclassified/evidence/4bda15af5f27661338975b7109162a76cd993f28f2aa4d70288ae3f19277f1fe.txt)
- [native-index/script-AniObject.txt](../../../kr/evidence/4c1aa29b91dc5abeda0a81ec0eb7a94546eb5a412ac0d9452dbe48148325ce1d.txt)
- [native-index/ui-list-content-offset-collision.txt](../../../kr/evidence/4e02221d453ea383c6c7b1a2676373167ea3d79eaf15d1bb91fee19634057625.txt)
- [native-index/actor-input-tree-walk.txt](../../../unclassified/evidence/4e3d32f6a54a8c08c25a5b93e01b3fb99fb7aeb6ec3702d8cd3172a23a9e9d83.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/script-object-motion-audit.json](../../../kr/evidence/5cc77faebee10f1aaf3c439545976a771918ad68b31191e05ae1f7f21d9aa9db.txt)
- [native-index/event-actor-target-arrival.txt](../../../kr/evidence/601e8bbb94084dda20bc5dae7e81c9e8aa859fc27dcaad0e924a60260b6e6a4a.txt)
- [kr-frame-dispatch-20261023/frame-paths.json](../../../kr/evidence/65f0c8ca3d39abf67d181959bbae931273a75d2f28083227e02275ad92452bb9.txt)
- [kr-frame-dispatch-20261023/instruction-evidence.json](../../../kr/evidence/6b7d37887bc9e4e4d3294bc580089e17225f08d95bea778faa8847240c18394a.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [native-index/native-movement-consumer.txt](../../../unclassified/evidence/6eb36f58ca42dd0126191c4b6adf41d807b045eb90a50fb25ff8a39ae4e79c60.txt)
- [kr-frame-dispatch-20261023/corrections.json](../../../unclassified/evidence/815b706183d0c9944787c7243a07dee6a1332685ea248692513d3c98aae622c2.txt)
- [movement_position.py](../../../kr/evidence/846599cf8a88e9b999e75bc4f8bbfcd4930f2a8e31c0e2de5b30b6df3a07c40f.txt)
- [native-index/native-movement-relative-position.txt](../../../unclassified/evidence/8551b90f0bcd479521c1d3931bfd11ade630fe9fbe0a680a7aae4895830fb492.txt)
- [native-index/gvg-duel-decision-stop-reset.txt](../../../kr/evidence/88cab32e233a4909a6e499a2452da14cd4895ad7d11b9bce38a7e0e30bae9d04.txt)
- [native-index/actor-position-update-0001-0016.txt](../../../kr/evidence/8d22ff6e097f3272f21e3568c53a231e8b7bd219bd08991b3ce55f4c42273692.txt)
- [native-index/actor-target-producer-audit.json](../../../kr/evidence/91d22e4e9e1328e9cbfaef10327808228daa99d702514cc7c30f1706d1496f41.txt)
- [native-index/lua-one-number-member-adapter.txt](../../../kr/evidence/932e1cba50e86f2929973e54b97e0dd692c2f8aedb706b6a4d157b35f35d4799.txt)
- [tutorial_monster_ai.py](../../../kr/evidence/9c1a55a267f465549b585b7c457471a6ce293feac0fe57daf40f3b74f6669286.txt)
- [native-index/tutorial-controller-field-initialization.txt](../../../kr/evidence/9c641f60af2fe472931243398451a47bd42d803cc7b2231221a06120601cb9d8.txt)
- [scan_movement_field_writers.py](../../../unclassified/evidence/9de397913910e99b5d24ba9d13430ad62902fda225a3c2994f5d0cdad3ae3ad3.txt)
- [native-index/native-movement-consumer-audit.json](../../../kr/evidence/a232a9412df8ad8943bb5c4b19d9235e70e321db5abcddf7a934cc09fec7503d.txt)
- [native-index/register-WarpObject.txt](../../../kr/evidence/a64802389c7194659c9dbb10735e8d17d206d6f4e276e16c7404f1116fd1665b.txt)
- [native-index/script-StopObject.txt](../../../kr/evidence/ab8dca5edcce8689604f308d303ca03e01d5dc6679c9e0041a8ac3f1608052cd.txt)
- [native-index/actor-input-phase-common.txt](../../../unclassified/evidence/b2ec3394f651ee67be9569e08397d9eab7cb09f4fbdb012230997042cd91ae44.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [native-index/actor-battle-stop-receive.txt](../../../unclassified/evidence/b89fc23b400e24121147a707f1e522351e9b00fafebb4fdb03765c3bc64fb876.txt)
- [native-index/script-WalkObject.txt](../../../kr/evidence/ba1ed7f65b7f6156b920435a99794d6269547e0e24195138888a36fc9d993962.txt)
- [audit_native_movement_consumer.py](../../../kr/evidence/c6a4f37c88fee8cf75fb0391df9fb84fad71bb8aedfcda967c13507929547987.txt)
- [audit_actor_target_producers.py](../../../kr/evidence/ccf2df7e156674571ff3abb7a0d1ab697f5e0876d4e36955735212377ffe20e7.txt)
- [native-index/event-actor-tick-target-consumer.txt](../../../kr/evidence/d1742609d223a1a6b4fede289125be649eab2c9b2eb879d92d911e3d3acb20ca.txt)
- [native-index/position-update-reset-audit.json](../../../kr/evidence/d60a7dc687112ab05b1d4790bcf57b0cc496de65d9396f8ab509a188d4e836bb.txt)
- [kr-frame-dispatch-20261023/native/mcp-evidence/04-function-4e0060.json](../../../kr/evidence/e377ae95f2eec2045d71521986dc42b0033fa845aea3a6ce0b61bad8962018a1.txt)
- [native-index/movement-field-writer-candidates.json](../../../kr/evidence/e6fbd954ea76ae6568a4bcfb6467a7b9bf8bb997bff8b23d013f7eaf37bd4784.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [NATIVE-MOVEMENT-CONSUMER.md](../../../kr/evidence/ee36565a40d1ec7a15040a57ce40ca9179b9a216fc3331fd058bfa73d094bcc6.txt)
- [audit_position_update_and_reset.py](../../../kr/evidence/f627faa95117be14eccf61fa1b6fdd99a78b2372af8ca73dfd413db6dfcfc285.txt)
- [native-index/actor-residual-position-correction.txt](../../../unclassified/evidence/f6759f0379a93f1cb6fe093b3fb45f8b703470eb2d1876f9e40fbc5aed25fe66.txt)
- [native-index/register-WalkObject.txt](../../../kr/evidence/ff586e55c10c11129382754abdcc7e6fd56fb6db8e4a918d35beecd8834cfad5.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。


2026-10-26 T01 整合交接：[T01-20261026-01](../../../shared/integrations/T01-20261026-01/README.md)。僅列明 SHA 的凍結成果已整合；其他暫存／新修改仍待下一輪。各任務未整體完成，接續前以此批次所在 origin/main commit 為基準。


2026-10-27 來源整合：[T01-20261027-03](../../../shared/integrations/T01-20261027-03/README.md)。只接受列明 SHA 與限定結論；其他暫存及整體功能未完成。本批已推送至 origin/main，接續基準 `d370a01645218615ad42595071c5328077e643a7`；推送收據見批次紀錄。


2026-10-27 新批次整合：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。比對來源SHA、限定結論及待核對映射；本批未把整份報告／函式或整項任務標完成。實際遠端接續基準見批次push-receipt.json。


2026-10-27 接續來源審核：[T01-20261027-05](../../../shared/integrations/T01-20261027-05/README.md)。先前105份source-only報告已有逐份來源與限定內容處置；完整語意／映射缺口仍保留。最新來源狀態見[來源審核索引](../../../shared/source-review-status.json)，實際遠端接續基準見批次收據。
