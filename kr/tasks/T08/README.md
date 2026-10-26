# T08 實體生成與移除

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
