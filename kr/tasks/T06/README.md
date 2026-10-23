# T06 地圖與場景資源對應

狀態：bounded-review-handoff；負責人未認領。

## 範圍

地圖 ID、資源查詢及資源版本；不推定波次與 MEF 執行器

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：資源與程式精確 build 配對、波次及座標來源未確認
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。資源與程式精確 build 配對、波次及座標來源未確認
- **部分確認**：既有相關報告及audit已打包；保留其中限定結論，未在本輪重跑語意驗證。
- **AI 替代**：此檔是本機實作審核來源，不能整檔認作原生規則；其中封包欄位是否有依據須逐項核對。

## 依賴、接續與驗收

依賴：版本共用證據。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 先查來源與更正，再選一個具體阻塞；認領主要函式後開工。
- 僅對缺口做後續定向核對；缺少後端規則需標記待補充開發。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [kr-phase1-20261022/focused-profile/mcp-evidence/06-function-4f3d80.json](../../../kr/evidence/0bf0d7ed73da6fa5ee0732df39dc110334acb802fd626a6ac4bf083567177c26.txt)
- [tutorial_monster_config.py](../../../kr/evidence/11ec8d8e1e642d2626727bab0c397e16a0ad1c7b9556fa2d0b3e0121bd0ce9d8.txt)
- [audit_map_state_consumers.py](../../../kr/evidence/21107ee7b8eeadf517f7a8cc268a0d4a6d3e64003a50563dff1f47a23a097984.txt)
- [kr-boundaries-20261022/boundary-records.json](../../../kr/evidence/223d788262cf02fb04f968e8bf29c1dbd30296b201377a985df2d2ed1831f732.txt)
- [native-index/map-trigger-consumers-audit.json](../../../kr/evidence/272bcb3f233d28886f425035bed0b215e7e3880a8af3fe6cf6f1958fce3d8eab.txt)
- [MAP-STATE-RESOURCE-AND-DRAW-CONSUMERS.md](../../../kr/evidence/35addc0a92053ffcfdd7fd2d34ddeb4ee3d2945aff848609667107e6bfeb8bbd.txt)
- [kr-phase1-20261022/mef-followup/mcp-evidence/05-function-56cd10.json](../../../kr/evidence/4577cd9500168f40ee28f6e18816e6501e4867d443e27f905b2f60625653ca39.txt)
- [MAIN-PROGRAM-FUNCTION-MAP.md](../../../kr/evidence/546a89f51d0c1dc55b81c98bb0c29c632bc445a40c08d63b237a01793475f68f.txt)
- [MAPFLOW-CLUSTER-LOADING.md](../../../kr/evidence/57e031e3f88af5a9963d955b84ae1c883fa4d25fcaea382ba0ff652117c405e5.txt)
- [kr-phase1-20261022/semantic-records.json](../../../kr/evidence/622c03c8f35e217e0799ca787b550ebad648b9767cbb2bc8f2c74da71d75a65d.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/09-function-4caf10.json](../../../kr/evidence/6a087875d16bb25aa9e93b53df79dd449bde7f21c09e048e2b21031765186730.txt)
- [kr-boundaries-20261022/slot-dispositions.json](../../../kr/evidence/6c8fd87928aa3390c8a2e73f1490698771236bfcceefd785172c752e7f30e69c.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/10-function-4d0dd0.json](../../../kr/evidence/8d941b3113cec9dddc3e57657e52b0b0673c82aaec72d60e7174b4855d8fad4a.txt)
- [native-index/mapflow-cluster-loading-audit.json](../../../kr/evidence/990413230baf61d90508ad4b57ec2401b6549216235d371dc2d09006f0a51923.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/08-function-4f7df0.json](../../../kr/evidence/af75e8a81e45941f4663199d2cdfe712e5dfcde53593763e1d7c41bdfa3de745.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/11-function-4ca060.json](../../../kr/evidence/b00db972ba10bcf17f0ae57f4803ed27a8cd9f3f5318b439bbc8c6ffa46f11a2.txt)
- [NATIVE-BEHAVIOR-MAP.md](../../../unclassified/evidence/b4eb2f9eb1476821ad1b910bb7f8ba8914842b67b31bb418cc147dbee42f5c18.txt)
- [native-index/method-atlas/summary.json](../../../kr/evidence/b5621564b75a6eecf3eb300f16261099ff4972c72b2b490607544925c112da3a.txt)
- [audit_map_trigger_consumers.py](../../../kr/evidence/c01c9d6fd8ca2d63f0c42e3ea835da5217905294065d4852fdc8fe2a723d8d7e.txt)
- [native-index/map-state-consumers-audit.json](../../../kr/evidence/c32490ae1cc0837a4ae7abebc00f8748df12292b983b253f4f7ea47eddbbc478.txt)
- [kr-phase1-20261022/mef-followup/mcp-evidence/03-function-4f4960.json](../../../kr/evidence/c65a9906af8223a3b13ae8b12ea94cae4719ad2ad20ca9e74c968d3447dea738.txt)
- [native-index/map-id-string-map-subscript.txt](../../../unclassified/evidence/c6d2ca5f5abb2176ddd052a591be5116957fffe7d3d430a809ee5bf126f9a29a.txt)
- [native-index/map-change-trigger-name-lookup.txt](../../../unclassified/evidence/c8647f2a305dd504321cb05517607233c8b2e3f612f4edc1b8a69a8d6a66dafc.txt)
- [audit_mapflow_cluster_loading.py](../../../kr/evidence/d39547d41b8c9c17115c24f233c310ac6bcd71e3fff8efd98cc0144fd68794b8.txt)
- [native-index/drawing-batch-state-consumer.txt](../../../unclassified/evidence/d49bacaca6547a24d501deba185f735ff51521765f39671665574d59a0a409ad.txt)
- [tutorial_battle.py](../../../kr/evidence/d642bd503a2ec2ac4b58fb569bbb77901fba2d37246a8421eac9c8c266f96d28.txt)
- [kr-unified-ledger-20261023/catalog.json](../../../kr/evidence/eaa97822197f2d699c3234ff07947f90a04ee71bf03f9c5fc188e49b15a77cf4.txt)
- [kr-phase1-20261022/mef-followup/mcp-evidence/04-function-4f5640.json](../../../kr/evidence/ed2173b1df5e91bf59cbfc1dc27e1573cef4d4857b751bfe26439cc9c56719b4.txt)
- [MAP-TRIGGER-CONSUMERS.md](../../../kr/evidence/f64b15cd263a69a2396bc643ae10802323233c24f663efa6df89c427e3bb31e2.txt)
- [kr-phase1-20261022/focused-profile/mcp-evidence/07-function-4df510.json](../../../kr/evidence/fe1ba4d04bb33dff43a045c3eaa6e32cf60ae4aca0867623b48768dc8028bf2a.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
