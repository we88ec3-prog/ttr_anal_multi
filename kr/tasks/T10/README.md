# T10 普通攻擊與連段

狀態：bounded-review-handoff；負責人未認領。

## 範圍

輸入、連段及取消流程；傷害公式交 T12

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：CHAIN_WINDOW=.65及服務端續段排程是自製；官方連段取消窗口未知
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。CHAIN_WINDOW=.65及服務端續段排程是自製；官方連段取消窗口未知
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。
- **AI 替代**：0.65秒連段窗口是本機實作選擇，正式連段/取消窗口仍待證據。

## 依賴、接續與驗收

依賴：T02, T04, T09。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [native-index/battle-input-batch-producer.txt](../../../unclassified/evidence/0815371627e08a9ce0e2c3bd049b3e9b38a563ccae35282295d3167d1e24f046.txt)
- [tutorial_skill_cast.py](../../../kr/evidence/107acb288eb3b8ccd4a2657fbe93d5fdcdc4f07c5cc5eede85b3d60f7be8ba48.txt)
- [native-index/battle-input-socket-worker.txt](../../../unclassified/evidence/172d170a21ef8fedc0bd04c0fd9bf0dcb88da582fa7a2b15072630f554371bee.txt)
- [BATTLE-INPUT-TO-SOCKET.md](../../../kr/evidence/1e15689d7bbdf4c4a83ae76cf1813d538b8cb38db79098c6b85ba386056dab36.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [tutorial-native-skills-v19.json](../../../unclassified/evidence/22ca3b44b15b76a451af4d3b5bde7da2b856222798a8f9f45f0d909f507f127c.txt)
- [audit_native_skill_timing.py](../../../unclassified/evidence/49782e44e5da6f0f86cf0ead1fecee49e0432cb4b20226024734366b6772b5e4.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [native-index/battle-input-packet-copy.txt](../../../unclassified/evidence/588f5dc116999cb57a48fed1d3db37f0935618529dd97ece4a2aaffa7a244b5b.txt)
- [native-index/battle-input-network-slot-send.txt](../../../unclassified/evidence/67682cca0b94bc1698d95851c3f8b7e5d666fa653a33d90b225c5c52f8730c1c.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [audit_battle_input_transport.py](../../../kr/evidence/74754a41cc22cc3766d83a94e1043b3521951faff7f6bb46bdf30392d7931acd.txt)
- [CONTROL-AND-SKILL-SOURCE.md](../../../unclassified/evidence/7bafd3143273877097a98dd0c42dc0f1c7e30719d0e86821318db4612473f89f.txt)
- [native-index/network-overlapped-wsasend.txt](../../../unclassified/evidence/7f5642ef15578b61a3491e8663e77e15876e3ec8a85ef0d2004671019cac8e9d.txt)
- [audit_battle_controller_sidepaths.py](../../../kr/evidence/80e6e839c336f750094477c4252b4d65358cec8345c22f524a54e396c4cf89c5.txt)
- [BATTLE-CONTROLLER-SIDEPATHS.md](../../../kr/evidence/91830956fb04388f5eabd1c876f283c6e78e9f001e953e978345472ff3572866.txt)
- [native-index/battle-input-row-append.txt](../../../unclassified/evidence/91df777cd65f424ef5e91e8d22635a0e80381ef2396b11a4d200da7440488ec6.txt)
- [native-index/battle-controller-sidepaths-audit.json](../../../kr/evidence/af5971a741bd7818c74ac9e8e51f6a765b8741cd57efc2f6d9bb0dae909c3371.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [native-index/battle-input-connection-framing.txt](../../../unclassified/evidence/cafb013e5bbd93cfa8b7d85af36cc32c61807a612ac95069cc55c8f0b4f0b96e.txt)
- [native-index/network-close-connection.txt](../../../unclassified/evidence/db5aafa5b1384358c3eb777361b2fcc9974e9b69c0bd6f9ef014cb15523f9014.txt)
- [native-index/battle-input-transport-audit.json](../../../kr/evidence/dd0ce08b9da2191d41341ed42c2f3e2c86c6ffdea781395adfc1b44c740940a8.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [native-index/battle-input-connection-queue.txt](../../../unclassified/evidence/f7402fb5881f2eff0a3a56b4fe54072ce4b3635c213a8cd17ac47b018f7e4163.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。


2026-10-27 新批次整合：[T01-20261027-04](../../../shared/integrations/T01-20261027-04/README.md)。比對來源SHA、限定結論及待核對映射；本批未把整份報告／函式或整項任務標完成。實際遠端接續基準見批次push-receipt.json。


2026-10-27 接續來源審核：[T01-20261027-05](../../../shared/integrations/T01-20261027-05/README.md)。先前105份source-only報告已有逐份來源與限定內容處置；完整語意／映射缺口仍保留。最新來源狀態見[來源審核索引](../../../shared/source-review-status.json)，實際遠端接續基準見批次收據。


2026-10-28 來源整合入口：[T01-20261028-06](../../../shared/integrations/T01-20261028-06/README.md)。限定證據、T16分工與更正已入catalog；不等完整原生／遊玩驗收，既有主責與狀態保留。實際接續SHA見批次收據。
