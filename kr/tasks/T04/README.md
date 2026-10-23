# T04 角色初始化

狀態：bounded-review-handoff；負責人未認領。

## 範圍

角色初始欄位及位置來源；生成傳輸介面由 T08 維護

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：900/900、固定地圖與戰鬥座標不是正式出生來源；能力、裝備初值未完整確認
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。900/900、固定地圖與戰鬥座標不是正式出生來源；能力、裝備初值未完整確認
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：初始900/900由本機fixture設定；不代表正式出生點或合法地形。
- **AI 替代**：本機帳號預設角色、地圖與位置屬替代後端初始化。
- **AI 替代**：固定戰鬥出生座標屬本機策略，正式座標來源未確認。

## 依賴、接續與驗收

依賴：T02, T06, T08。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [login_protocol.py](../../../kr/evidence/2df1658bde172c672d7a3d45fe0534fc766bbe952bb53ecf49bc4ebff6b4094e.txt)
- [audit_monster_parameters.py](../../../kr/evidence/2ed438229ff83d5e42febee6deba0e63f2aa5a6257aca16f2cb3b5d74792f89c.txt)
- [22-plaza-player-fixture.md](../../../unclassified/evidence/34288de6210193e8b09325a4097c513340420a3dafa0c742524ef5f8fcc3d38a.txt)
- [native-index/monster-effective-speed.txt](../../../unclassified/evidence/4bda15af5f27661338975b7109162a76cd993f28f2aa4d70288ae3f19277f1fe.txt)
- [account_store.py](../../../kr/evidence/512368d38b4bc52372e9fc08dbd5d5921827864b1adbfb4e7ba0cb721448d075.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [new_expedition.py](../../../kr/evidence/5f83768f68f251d3b39da666438a0803bd011142b8cb2b28216c7363ff424534.txt)
- [MONSTER-PARAMETERS-AND-MOVEMENT-INITIALIZATION.md](../../../kr/evidence/632e0b1887052506ff0ea0451b7f2ee63ed2c8f14f46703ac53f907efca35aa7.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [native-index/monster-parameter-audit.json](../../../kr/evidence/83a73168ad61957ebfc5be8fa2064c229f1eccc18a5b59f8889b531f9b2895c2.txt)
- [tutorial_monster_ai.py](../../../kr/evidence/9c1a55a267f465549b585b7c457471a6ce293feac0fe57daf40f3b74f6669286.txt)
- [native-index/monster-spawn-control-audit.json](../../../kr/evidence/9f023435f85886c849e3a0266f00700d294b6a2625ccd11a777512934a11b449.txt)
- [23-player-control-init.md](../../../unclassified/evidence/a2e7773074d3ca85ae8c3e19ff136bf70fbbb2ab28103fdb34c93f96e723f70c.txt)
- [native-index/actor-movement-default-initialization.txt](../../../unclassified/evidence/a3a76d0958d7b867b5b90fe6ebbe8fa3edbe14f22343dec15bbdae46ca0f1817.txt)
- [native-index/monster-parameter-setter.txt](../../../unclassified/evidence/a3fefaf444add87d0165a1a595cffc06299a1dd29fc44146c6fde6c3b5af3176.txt)
- [native-index/monster-model-initialization.txt](../../../unclassified/evidence/b1f4f3b94d789e46c0f46386d1358513dc2deb523a8a5489bc08a28fd55d565c.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [31-collision-grid-spawn-and-trace-crash.md](../../../unclassified/evidence/ce5e1aad285f5b3fea35f655ebba154dfbfa6f67045204284988e7d97b05b56f.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [native-index/monster-parameter-common-receiver.txt](../../../unclassified/evidence/fd14ba513ad175d99b4c862dbc583f1b57b00d23e6e5a119577987c940ca98bf.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
