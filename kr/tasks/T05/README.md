# T05 廣場進入與移動

狀態：bounded-review-handoff；負責人未認領。

## 範圍

廣場流程、移動回報與校正；共用 actor 運動由 T09 維護

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：位置估計未含碰撞且不是客戶端位置回報；正式位置權威未知
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。位置估計未含碰撞且不是客戶端位置回報；正式位置權威未知
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：初始位置與方向速度積分是服務端估計；不是客戶端位置回報，沒有碰撞驗證。
- **AI 替代**：此模組為診斷用的服務端位移產生器，不是原生移動權威證明。

## 依賴、接續與驗收

依賴：T02, T04, T06, T09。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [POSITION-UPDATE-AND-MOVEMENT-WRITERS.md](../../../kr/evidence/00d7c1b55f3b4514fdf9db13874bc6008a563ca3e7d7d116036029327c83617e.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [25-plaza-map-initialization.md](../../../unclassified/evidence/3a0cb694d75717d9daceb35f44a848862546baeaeb69f43abda9d9d2365a8b03.txt)
- [30-plaza-collision-baseline.md](../../../unclassified/evidence/508a8f16e14a54dfd260af06c42841bad5a356bfe1065a6fb3f1ec1059de5760.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [26-player-movement-timing.md](../../../unclassified/evidence/5e5f27f1ae92595aabe1ba5a14929866a78d498f23736981a4b7d233d63d4cb0.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [movement_simulation.py](../../../kr/evidence/83a4a5d5b2f1a6ca943b07ad47f801f57ade327d720b1ed0e41629e95ff49bc0.txt)
- [movement_position.py](../../../kr/evidence/846599cf8a88e9b999e75bc4f8bbfcd4930f2a8e31c0e2de5b30b6df3a07c40f.txt)
- [scan_movement_field_writers.py](../../../unclassified/evidence/9de397913910e99b5d24ba9d13430ad62902fda225a3c2994f5d0cdad3ae3ad3.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [31-collision-grid-spawn-and-trace-crash.md](../../../unclassified/evidence/ce5e1aad285f5b3fea35f655ebba154dfbfa6f67045204284988e7d97b05b56f.txt)
- [native-index/position-update-reset-audit.json](../../../kr/evidence/d60a7dc687112ab05b1d4790bcf57b0cc496de65d9396f8ab509a188d4e836bb.txt)
- [native-index/movement-field-writer-candidates.json](../../../kr/evidence/e6fbd954ea76ae6568a4bcfb6467a7b9bf8bb997bff8b23d013f7eaf37bd4784.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [audit_position_update_and_reset.py](../../../kr/evidence/f627faa95117be14eccf61fa1b6fdd99a78b2372af8ca73dfd413db6dfcfc285.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
