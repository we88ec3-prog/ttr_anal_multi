# T12 命中、傷害與死亡

狀態：bounded-review-handoff；負責人未認領。

## 範圍

戰鬥結果消費與死亡資料；不把顯示結果推成計算公式

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：半徑45/65、傷害20/35/60、延遲.2皆為fixture；命中死亡復活權威缺失
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。半徑45/65、傷害20/35/60、延遲.2皆為fixture；命中死亡復活權威缺失
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **原生已確認**：S2C000E的row為13 bytes；這是結果消費端，未取得傷害計算公式。
- **原生已確認**：S2C000B移動row為8 bytes，與000E結果row分開。
- **AI 替代**：半徑45/65的命中規則屬fixture；非原生傷害/命中裁決。

## 依賴、接續與驗收

依賴：T02, T08, T10, T11。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [native-index/hero-ai-hit-feedback.txt](../../../unclassified/evidence/00723626cc0ae186c8b8745497c9599a33f3ee9e06ec40c472b79d33fcc18a5d.txt)
- [native-index/battle-result-route-audit.json](../../../kr/evidence/0124ca7a9184fc541708d37dee2516ec3d5f7bd788b1bbeb9df8f86399f81f71.txt)
- [kr-battle-frame-binding-20261023/closeout.json](../../../kr/evidence/1495830d18b81ba12cf637972191be3ff641bf072ca45309e1eaf5aa514f86d6.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/01-session-start.json](../../../unclassified/evidence/15571507d63e3eff34c942d2769cd566f0dc01dc338e2ada8427eeca8b3ee0ec.txt)
- [native-index/actor-movement-receive.txt](../../../unclassified/evidence/1e844b935c37d6b1e0df299ffa0b588013cee4f3d9fa632028ccb0459dfb4233.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [audit_battle_result_routes.py](../../../kr/evidence/26702822e990953bde0a72c314e04eac1d2627c1a201689bbe01a0e584c2b2df.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/08-close.json](../../../unclassified/evidence/277a432e35342ec51d445d56bb42fd9a931b5d00c5590e702f7ea9cb790a561c.txt)
- [kr-battle-frame-binding-20261023/verify_effects.py](../../../kr/evidence/29521e2ec01274be008c5d6de93a39e67cdd65aa00989907b06aab85efe5da1f.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/03-function-7ac030.json](../../../kr/evidence/31374e3f7f2d22b8fb994deecfe14816eaf3d644291021ef1747168901731d5d.txt)
- [native-index/actor-heading-only.txt](../../../unclassified/evidence/3901d805382ff675515e88448a0058855f64112f1875fb1e5194ed48e06e631c.txt)
- [CHECKPOINT-WIRE-AND-ACTION-NOTIFICATIONS.md](../../../kr/evidence/401e0526feff1cb6f88298a2b5ec7bed454705259fd5846c0f80283664c5ff0d.txt)
- [native-index/battle-result-common.txt](../../../unclassified/evidence/41fa17caac92ad6409c7de8bc4aa770123b0b0671b54a16ad035dce179ea11d7.txt)
- [kr-battle-frame-binding-20261023/artifact-manifest.json](../../../kr/evidence/443e99ab4f3890d22bfa38a187ce36a7f00f64abcc94b32a5165db58eba7295a.txt)
- [kr-battle-frame-binding-20261023/build_effect_semantics.py](../../../kr/evidence/45700f1ef8bff364cac51cc82b68ee1789becbc34c7922b2965f92906cc9476f.txt)
- [kr-battle-frame-binding-20261023/build_binding.py](../../../kr/evidence/4771aaf0ee3c3fa102df4b28cd29d3d68023396e8e9ed7a0e7e195a13955fb34.txt)
- [kr-battle-frame-binding-20261023/native-plan.json](../../../unclassified/evidence/4b12770b3beec51f2ba1bc3ceb34f748edb38110cefb12a017ab79d804410867.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/actor-model-and-state-tick-full.txt](../../../unclassified/evidence/55f98c310a0a6a3381e0511d2953997502d3fd37f426524c1af291118d111933.txt)
- [kr-persistence-20261023/verify_records.py](../../../kr/evidence/56a4a7ae64cd109803d86db2693ffedda697f91a55fb79ba942f942921c86221.txt)
- [native-index/checkpoint-action-notifications-audit.json](../../../kr/evidence/5fa49ace198f155afd65d0b3dafbd56fe0e4796736f6a05c7d2d277109e03229.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [kr-persistence-20261023/framecontrol-table.json](../../../kr/evidence/6e21430a8d3595ff357791f8de9757dcce2496ad60a5790c25dbe143db0d8ed8.txt)
- [kr-battle-frame-binding-20261023/input-provenance.json](../../../unclassified/evidence/6f224e61185edb39c14fb77da4d186ffe8dafc37a60ca14f017c8db1685465f7.txt)
- [native-index/battle-ready-common.txt](../../../unclassified/evidence/718f8db3b5102f65a011816cf5759cbc816ca155d1bb7df09aa6f277fe30ae40.txt)
- [kr-persistence-20261023/workbench/mcp-evidence/11-function-7a87d0.json](../../../kr/evidence/752cd473b7fbf2a24fdb62316dbb9598182b970f14dbc65de84e0ab7f8cdcc29.txt)
- [native-index/battle-ready-mission.txt](../../../unclassified/evidence/767badf995cb91d2e4dc6c4f3b6199247a335ef5f6b9b6e52133033d26dea4c7.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/07-export.json](../../../unclassified/evidence/76f933ad841e15f96aa509acfe374571feb496a71048bc099e8314541fbee1d7.txt)
- [kr-persistence-20261023/followup/mcp-evidence/05-function-7d2170.json](../../../kr/evidence/77a44c2d488546257f1279d6ce49b25495199b8062bc46ff6f17f2acc5e2647f.txt)
- [BATTLE-RESULT-AND-AI-FEEDBACK.md](../../../kr/evidence/81a3fe379d433685e342d65c96db6aa78a52e0510f294cc3e338c4e7b63269b6.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/06-function-5521d0.json](../../../kr/evidence/87d4ca89e725ec78f1b266bfc0a97a020af78d92ae9f57c18f1ab682434c79ba.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/02-open.json](../../../kr/evidence/9795c0be73f9b83fe8878c9b0bd64a876b41e05fe1ae97e1e7451552946c04c7.txt)
- [tutorial_monster_ai.py](../../../kr/evidence/9c1a55a267f465549b585b7c457471a6ce293feac0fe57daf40f3b74f6669286.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/04-function-7abcd0.json](../../../kr/evidence/a5689975f31907bfb6dd148d6c8175e8074b15782690b8c01a048fd6222d2826.txt)
- [kr-persistence-20261023/validation.json](../../../kr/evidence/a748263f55082027021f46f607a76c273999bd10f5b358fa983814d433ec9dab.txt)
- [kr-battle-frame-binding-20261023/effect-semantic-records.json](../../../kr/evidence/a82f71cf3cc9d74b2d5039db8f0379d8d8535866fb2598efd29a629b5e86de35.txt)
- [kr-battle-frame-binding-20261023/finalize_delivery.py](../../../kr/evidence/ad7d4ad3fc86839cb39b80804f9c01bc065399c40515cdd355d47bff59776740.txt)
- [audit_checkpoint_and_action_notifications.py](../../../kr/evidence/ad86312b02a092bae6c2f6d6b3d803070d79de96a284bdd14cee35788b8b768c.txt)
- [kr-battle-frame-binding-20261023/binding-records.json](../../../kr/evidence/af3cb8ac9f8af8a3c291e0efa790ab403875b7498eac771c0181c64ef2ba5f48.txt)
- [kr-battle-frame-binding-20261023/REPORT.md](../../../kr/evidence/b031b1f51bb9d8958fbaaa555b45f8b38845abd027e049d064525c747fabac34.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [kr-persistence-20261023/battle-frame-contexts.json](../../../kr/evidence/ba6c120c80e55bf2d1f5bb2fcdd46c2ac320d94181aa0211f132abe7f052c94f.txt)
- [kr-battle-frame-binding-20261023/effect-validation.json](../../../kr/evidence/bb65427a7cc64c9f80fa22f9d9f6579ff39d933219d194e09b304e1ab8750a2d.txt)
- [kr-battle-frame-binding-20261023/progress.json](../../../kr/evidence/bf98d2d0fb288e2dee8ec4df23d596d6c1d7361295bd5efc26423439b6f86a4c.txt)
- [kr-persistence-20261023/workbench/mcp-evidence/14-function-7a5c50.json](../../../kr/evidence/c12373d7e96ccc0227f59c7778dfdbb344fd84159d0e265ade0e4605b79b27f7.txt)
- [kr-battle-frame-binding-20261023/unknowns.json](../../../kr/evidence/c682677da9c9d0f6b0e3a4a0a1488694f52cd0503e1acd5517badb73d482b570.txt)
- [kr-persistence-20261023/workbench/mcp-evidence/12-function-7d28e0.json](../../../kr/evidence/d39d9622828a44ac1ad2044624a3c58d6068ca5ec3f742788cb568af752eb7a5.txt)
- [kr-battle-frame-binding-20261023/verify_binding.py](../../../kr/evidence/d413e6df3ce8c97f6b27793855afbcce6eba2bab36366c7eafd4e96569debb20.txt)
- [kr-battle-frame-binding-20261023/binding-validation.json](../../../kr/evidence/d596123ef6870dc5e795298d978952f4617076c5ce45cb84fd0d751801386284.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [kr-battle-frame-binding-20261023/mcp-evidence/05-function-551f20.json](../../../kr/evidence/db0b4c8798acdb538a09167b3d36d09ac355eea95b54d0f2a87641e99f7d953a.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [kr-battle-frame-binding-20261023/class-relations.json](../../../kr/evidence/f453c7473c3e14aed710fa8a5b36d79f08e814bb31b8cf8c06f9f3c64573c86d.txt)
- [native-index/battle-result-scenario-feedback.txt](../../../unclassified/evidence/fc4f6129884a7eecdcc5962ba6cfccb9372e453520a636de27413c481c5d08ee.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
