# T13 非玩家實體的行為來源

<!-- S00-DISPATCH-BOOTSTRAP:v1 -->
## S00 研究請求開工檢查（正式）

**每次開工必讀**：確認最新 origin/main SHA，先檢查本 README 的 T01 驗收退回與既有主責，再讀 [T13 S00 收件箱](../../../research/dispatch/inbox/T13.md)、[唯一 RR 台帳](../../../research/requests/index.json)、[派工／認領／回報規則](../../../research/dispatch/README.md)。先處理已指派且獲使用者授權的 P0/P1；只在認領變更發布於 main 後才算跨 Agent 已認領。完成研究需提交 Markdown + 精確 Git blob SHA 並更新 RR 為 SUBMITTED，S00 才能結案。**收件箱不會自動喚醒本 Agent**；不變更原有 Task owner、原稿及 T01 退回規則。


狀態：bounded-review-handoff；負責人未認領。

## 範圍

追查既有動作消費端的來源；不要求客戶端一定存在AI

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：自製追逐回家與攻擊規則不能當原生AI；原生來源與P2P權威未知
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。自製追逐回家與攻擊規則不能當原生AI；原生來源與P2P權威未知
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：檔案自述不是官方AI/P2P還原；追逐、回家與攻擊均需隔離為替代規則。

## 依賴、接續與驗收

依賴：T02, T08, T09, T10, T11。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [native-index/obsessions-rule-execution.txt](../../../unclassified/evidence/02f5eeb510720366e1475bcbd84f679bcccb72a850885f1f319b20dcac9fba73.txt)
- [native-index/matrix-index-lookup.txt](../../../unclassified/evidence/0881a061cfb58b7c4e97482147c99e85d0305ebd72310b14b7e0ee98428909a1.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [native-index/actor-state-transitions-audit.json](../../../kr/evidence/23187178ddaa21787462266428509c564ee87581dc0d00669c4107e845b93358.txt)
- [scan_actor_state_dispatch_calls.py](../../../unclassified/evidence/231e241beb7b2e382e5d6009639420d323ad8f4f17f25713549e4f9cb1135cec.txt)
- [native-index/base-controller-input-full.txt](../../../unclassified/evidence/2a325d7719b500c9cf32683b374ba60eebef58adb8acaef7e27f447e84415d4d.txt)
- [native-index/network-send-gate-xrefs.json](../../../unclassified/evidence/2c91dab04a66085f453e387a7cb115417e26c98a622d98a16eefdaed512aeef5.txt)
- [native-index/general-monster-comparison.json](../../../unclassified/evidence/2d8d0f50e7dba1c7a712acb6e8cd4f36d41e8519bdf42e36207ebd6c49b1dbc2.txt)
- [native-index/local-actor-binding-and-ai-framework.txt](../../../unclassified/evidence/35007d3c3abed7f2279b553c213bd79cdfda1dd430d5a99a255c9504c39d760f.txt)
- [GENERAL-MONSTER-AI-COMPARISON.md](../../../kr/evidence/3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2.txt)
- [native-index/qbase-lua-prototypes.json](../../../unclassified/evidence/4000af88173963e0bcd2916d7b74b8ca606a69879ef4c89c578b64636f3c2e8c.txt)
- [native-index/actor-state-dispatch-call-candidates.json](../../../kr/evidence/47cb5ffc69580e4cde47a88d1d8069c4df047ccf15d6b8c0c55dc41fc2938085.txt)
- [native-index/local-actor-resource-references.json](../../../unclassified/evidence/52418b07b4ea755fcada1fccf23cb7c99a3bab08ca739e59fbe83095a805b903.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/battle-start-full.txt](../../../unclassified/evidence/5872782ce0a3c34e2f75e3fc2ae8f7198ead2b66ed548193a89ea7e522d86e12.txt)
- [new_expedition.py](../../../kr/evidence/5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534.txt)
- [BATTLE-AUTHORITY-TRACE.md](../../../kr/evidence/61f019a41dc1dac0aba54bb25295bb0eadb53bb16474d3c1e74ed5c49be65ab1.txt)
- [native-index/subai-target-selection.txt](../../../unclassified/evidence/64e391bea54e65020df5694371c23cff211d65f421ce9bbd3868c82e659692d9.txt)
- [native-index/matrix-file-loader.txt](../../../unclassified/evidence/673c92234834b527f9b30cb9fff1e647b3e06fe8f273d09d5c091ef6e5e5fb49.txt)
- [native-index/matrix-0081a8e0.txt](../../../unclassified/evidence/69f69c6748f3651ee5a0c11f82eb472f0ccf1ff0d936fc34958c6f4116722c46.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [native-index/general-monster-skill-id-hits.json](../../../unclassified/evidence/6d70c3b97d5429908131980e6928cacf59d80273108b524aba5cd95e421e8e1a.txt)
- [scan_actor_state_writers.py](../../../unclassified/evidence/73ed84f39af70cee57f4b6c8a93986cbbc803fa2b331bd4800410672486cfc67.txt)
- [native-index/subai-nearest-candidate.txt](../../../unclassified/evidence/777472689e6e2c0b445bd0a784dfc2ba250044a67b132d94eb37d7e8991e01d5.txt)
- [native-index/authority-string-candidates.json](../../../unclassified/evidence/80389d846abafd83536f66ff439fa94c670e9f2d91fe8447841f16f7c4f54adc.txt)
- [SUBAI-ACTION-TRACE.md](../../../unclassified/evidence/80d9c08b8ff9446ab95039db7af35195f60dd66e7f5b5b08042751abc6d6ed29.txt)
- [native-index/summary.json](../../../kr/evidence/84562223511b4147a91cf92d7d79303f63094c779d085903c76c24c2b43da69e.txt)
- [native-index/controller-input-and-actor-tick.txt](../../../unclassified/evidence/97effb33fa898a4a873ca337a594e2e8b16889f4734a3168b8fd020c5380c829.txt)
- [native-index/mission-scene-update.txt](../../../unclassified/evidence/98ae57de67cee74bc7784b07f52b92e20fe2cdbc27e5d0f423ba2117218828a4.txt)
- [tutorial_monster_ai.py](../../../kr/evidence/9c1a55a267f465549b585b7c457471a6ce293feac0fe57daf40f3b74f6669286.txt)
- [LOCAL-ACTOR-AND-AI-FRAMEWORK.md](../../../unclassified/evidence/a262daeb6885c6d38c6aa9f6f1ad2aca9d8477487f865c99ad648fd7591c4c21.txt)
- [native-index/single-controller-objects.txt](../../../unclassified/evidence/a32fba779c5c7adf4c9b4186ef830a85ab1fe3ccf271b6c45517b468083c0c5a.txt)
- [native-index/local-actor-create.txt](../../../unclassified/evidence/a95a093551ba643742b3c7421cbaaeb79841c4faa08c9414d73fc44d4ecd7e29.txt)
- [native-index/subai-enemy-search.txt](../../../unclassified/evidence/aa0fe09eba4a3148e28d596d53d86d04b530555769fb92728169019693d444a8.txt)
- [MONSTER-STATE-TRANSITIONS-AND-SOURCES.md](../../../kr/evidence/ac5eefb8fa7bf5856730239b90dc47442a3d015500e849c3339d5e382badd424.txt)
- [native-index/matrix-list-loader.txt](../../../unclassified/evidence/addff13491ca8b3eb68dab1810b5b7e9b48b5f77f9b7014add070b18b3dfee12.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [native-index/local-actor-create-wrapper.txt](../../../unclassified/evidence/ccaa2264a0e3c525351ec0d7559cbc0b25baff12494fcf835a6651fdc5abe71f.txt)
- [native-index/actor-state-writer-candidates.json](../../../kr/evidence/cdfc784dab06853a93d433ddbce0c6ea540c2667802f228bb848732f2410b882.txt)
- [native-index/monster-alternative-and-ai-manager.txt](../../../unclassified/evidence/d279a024dc4a390f7dd2d5aaa83d93ee019cf110ab33e10211949b8b7d55f7f3.txt)
- [native-index/local-actor-api-bindings.txt](../../../unclassified/evidence/d8d5d331930f1c4adeda245cf14171f1ee7572c79ed3c2711b75df60c0773687.txt)
- [native-index/subai-action-methods.txt](../../../unclassified/evidence/e291cc7721c8ff40b09bcb59d28132aa5c7f3d66979fe8794cb7bc44368a91ea.txt)
- [native-index/subai-target-and-skill-validation.txt](../../../unclassified/evidence/e2a358f008c79a5df97bb019fc48966b5bfe4f55cce2d62b3bcfa31bdb810494.txt)
- [native-index/subai-candidate-predicate.txt](../../../unclassified/evidence/e924430e5a031fdc32c92b1dd451ea0dec0fae6e2266da95d53a76f808180152.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [native-index/matrix-0040f7f0.txt](../../../unclassified/evidence/f98244749162cdb1657aab85832eb28db2c987d8449700e4d9a8c141568c51da.txt)
- [audit_actor_state_transitions.py](../../../kr/evidence/fa08327930a174846e07e0abdd727d4adb233c943e46c8b748113da61dc76ff7.txt)
- [audit_general_monsters.py](../../../unclassified/evidence/fb5dabe6d0d600496e532de1cc710f5e165293b2aacff98fd92c604c099a7dc3.txt)
- [native-index/subai-action-execution.txt](../../../unclassified/evidence/fb82c3e2a2758b5c893a65375ba0754ee2ae442849ed03277908708a28b78773.txt)
- [native-index/single-controller-actions.txt](../../../unclassified/evidence/fc188a90132f791c97fd4475230d8fff9f4bc5541f60d3dd4d5542fbae1f85aa.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
