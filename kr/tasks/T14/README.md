# T14 關卡目標、完成與獎勵

<!-- S00-DISPATCH-BOOTSTRAP:v1 -->
## S00 研究請求開工檢查（正式）

**每次開工必讀**：確認最新 origin/main SHA，先檢查本 README 的 T01 驗收退回與既有主責，再讀 [T14 S00 收件箱](../../../research/dispatch/inbox/T14.md)、[唯一 RR 台帳](../../../research/requests/index.json)、[派工／認領／回報規則](../../../research/dispatch/README.md)。先處理已指派且獲使用者授權的 P0/P1；只在認領變更發布於 main 後才算跨 Agent 已認領。完成研究需提交 Markdown + 精確 Git blob SHA 並更新 RR 為 SUBMITTED，S00 才能結案。**收件箱不會自動喚醒本 Agent**；不變更原有 Task owner、原稿及 T01 退回規則。


狀態：bounded-review-handoff；負責人未認領。

## 範圍

區分小任務、勝敗、結算及返回；保存介面交 T15

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：清怪後.75秒完成與預標scenario14/16為本機策略；正式目標獎勵條件缺失
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。清怪後.75秒完成與預標scenario14/16為本機策略；正式目標獎勵條件缺失
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：清怪後延遲完成的排程是本機策略，不能取代正式任務達成條件。

## 依賴、接續與驗收

依賴：T02, T07, T08, T12, T15。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [SCENE-ENTRY-RESET-AND-READY.md](../../../kr/evidence/0bab714e82d96b0f6a4165471fc52531ba4b250f63878e2721bdd706fb8bab37.txt)
- [QUEST-STATE-NOTIFICATIONS.md](../../../kr/evidence/0ef1b842dc4d34ce8bda1944d6556f00862febd2ec98393030ac1518b55d3c22.txt)
- [tutorial_skill_cast.py](../../../kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt)
- [tutorial_monster_config.py](../../../kr/evidence/11ec8d8e1e642d2626727bab0c397e16a0ad1c7b9556fa2d0b3e0121bd0ce9d8.txt)
- [native-index/quest-state-notifications-audit.json](../../../kr/evidence/196ab5cb1f9951b7a2daa1aae318890a04ed9759ffb4748f3cf04132d83cb624.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [tutorial-native-skills-v19.json](../../../unclassified/evidence/22ca3b44b15b76a451af4d3b5bde7da2b856222798a8f9f45f0d909f507f127c.txt)
- [native-index/scene-controller-audit.json](../../../kr/evidence/2d9e26e98fd3c87bff2a1cc8cea2621a445479a2496487499f6e69aac8264fd6.txt)
- [login_protocol.py](../../../kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt)
- [MAINLINE-FLOW.md](../../../unclassified/evidence/3a6376c5d84b4f03edc301d4467746680dfa448efb1df1eb5d2c20e278a20690.txt)
- [48-tutorial-battle-fixture.md](../../../unclassified/evidence/43aa311555dd6ad2e6843224cf710036c07b390942f7836b58ae9c80de587e59.txt)
- [account_store.py](../../../kr/evidence/512368d38b4bc52372e9fc08dbd5d5921827864b1adbfb4e7ba0cb721448d075.txt)
- [audit_quest_followup_delivery.py](../../../kr/evidence/5160a9ec0027ef0958184177a63ee24c3566b9bec98f3e4adc9ecdabb133a3a1.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [new_expedition.py](../../../kr/evidence/5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [plaza_npcs.py](../../../kr/evidence/9a9e396000323e0b7359afeb933922ce3ff40b50a4dedd982ed752b2fe228e49.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [QUEST-FOLLOWUP-DELIVERY.md](../../../kr/evidence/bff92f470c840f7737652274ebcaaa36aa06c16b9f85e09cd1d1847ea9428be3.txt)
- [native-index/quest-followup-delivery-audit.json](../../../kr/evidence/c0979f6864b1ac8bc5d9844f39c69e04b7587ef0597914c0c04898f65577762b.txt)
- [audit_quest_state_notifications.py](../../../kr/evidence/c297785536d52b20ca6ac0a9ed288520d54ebb864b09c07790089262293ac301.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [audit_scene_controllers.py](../../../kr/evidence/fd26185a16f71126adee2347d1bb9a14152c42669955dc8ad46556d460f3f7c1.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。


2026-10-27 來源整合：[T01-20261027-03](../../../shared/integrations/T01-20261027-03/README.md)。只接受列明 SHA 與限定結論；其他暫存及整體功能未完成。本批已推送至 origin/main，接續基準 `d370a01645218615ad42595071c5328077e643a7`；推送收據見批次紀錄。 T14 分析維持使用者要求的暫停。


2026-10-27 新批次整合：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。比對來源SHA、限定結論及待核對映射；本批未把整份報告／函式或整項任務標完成。實際遠端接續基準見批次push-receipt.json。


2026-10-28 來源整合入口：[T01-20261028-06](../../../shared/integrations/T01-20261028-06/README.md)。限定證據、T16分工與更正已入catalog；不等完整原生／遊玩驗收，既有主責與狀態保留。實際接續SHA見批次收據。
