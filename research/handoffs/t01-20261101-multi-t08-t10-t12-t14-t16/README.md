# T01 — 五研究分支整合與原始 KR BIN-first 限定驗證（2026-11-01）

**T01 來源整合基準：** `main=ccad1b06ebc256c64642b48eb26c48ddaa9c6686`。使用者所寫 `t8/roy/chatgpt-web` 在 GitHub **不存在**，經正式分支清單查明實際名稱為 `t08/roy/chatgpt-web`，按原有 T08 研究分支整合，**不另開新 branch**。以下五個 branch 均以原 HEAD 作為**多父 merge（octopus）**的真實第二至第六父，保留研究 Commit DAG 和所有原稿。

| 來源 branch | frozen HEAD |
| --- | --- |
| `t08/roy/chatgpt-web` | `3f24b023aaf927ebaa807bdc87ca5a94d472d918` |
| `t10/roy/chatgpt-web` | `0b0a00dd1019743dba7f45c769f8f76e17ebd310` |
| `t12/roy/chatgpt-web` | `22ca86bf7f96bd46435f49ee74004f97dd675974` |
| `t14/roy/chatgpt-web` | `e8ee70dca88347faa0755f60ecf5b9e0edcfbf2f` |
| `t16/roy/chatgpt-web` | `124b96c1e75ec6bc83a15006a8e4894d0603e576` |

## 1. Git 內容、衝突與不覆寫規則

- 本批為 **22 件新增完整來源**：T08 新增4件研究及 Python，T10 新增7件 W06/W07 與回歸矩陣，T12 新增1件 A/B 結果接收研究，T14 新增7件 WP01～03、native JSON/Python，T16 新增3件 Quest135/136 完整研究及結構化索引。原稿均使用 Git 原始 blob，不做摘要替換或更名。
- T08 分支另修改 `kr/tasks/T08/README.md`：本輪查證 branch 從 `## T08-203` 起的其餘內容與 `main` 同節以下**逐字相同**，只新增 T08-204/205 的領先段落。因此可採用 branch README Git blob `bb45431ad7b443dcbda4dd422ea7c1c56a61be39`，保留主線既有歷史退回／203 與更早追溯，不修改 task.json、owner 或 native_complete。
- 合併前另一 Agent 把 E84 RR-0007 研究加至 main（更新到 `ccad1b06ebc256c64642b48eb26c48ddaa9c6686`），本輪**保留它**，不以舊主線樹覆蓋；五個來源分支都包含與 main 不同的舊基準，不能用其中任一來源的完整 tree 直接覆蓋 main。建立的合併 tree 以**當下 main tree 為基礎，明列 22 個 additive blobs + T08 README + 本 T01 報告、audit、intake**。
- 精確 Git blob SHA/UTF-8 SHA256 逐件收件為 **SRC-0630～SRC-0651**，維持 `integration_status=REGISTERED`、空 `claim_ids`。既有 T01 退回、RR、S00 SPEC、Task 主責、`shared/verified-knowledge` 不修改。作者稱 FINISHED 或檔名含 FULL 不等於 T01 對全文原生語意的 FULL-PASS。

## 2. T01 這一輪真正重新跑的原件與測試

以本輪容器中的 **唯讀原始 `Tartaros.bin`**、`Tartaros.exe`、`Event.stp`、`Table.stp` 計算 SHA256，使用 Python `hashlib`/ `struct` 的**獨立 T01 檢查**比較位址的機器碼、vtable DWORD、direct E8 rel32、局部原生函式 SHA256、switch table、完整 .text raw DWORD literal occurrences、Event XOR-FF tokens；再由 GNU `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 連續解碼五個小區間。**未實際執行 Client、未 patch / attach、未抓 Server 封包。**

| 原始檔 | bytes | 實測 SHA256 |
|---|---:|---|
| `Tartaros.bin` | 12472320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `Tartaros.exe` | 2594816 | `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` |
| `Event.stp` | 11241597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| `Table.stp` | 5248784 | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |

原始 PE 已核 `MZ/PE`、x86 `machine=0x14C`、ImageBase `0x400000`、.text VA `401000` raw `400`、.rdata VA `BD2000` raw `7D0600`。對 .text 只使用 `raw=VA−0x400C00`，rdata pointers 的 raw=VA−0x401A00。不同版本或 section 不混用偏移公式。

**真正重跑的 157 項選定檢查：全 PASS**：

| T01 scope | pass數與方法 | 精確可支持界線 |
|---|---:|---|
| source SHA/PE | 4 + 2 | 來源身分、section mapping |
| T08 | 33 條 code-byte、8 個 vtable、8 個 direct E8 | CMonster/NPC→CDoll、B entry producer/consumer、控制／回收 |
| T10 | 15 條 code-byte、9 個 SHA window、9 個 switch DWORD | 000E 13-byte/9case、輸入 mask、SkillMatrix gate |
| T12 | 8 條 code-byte、2 個 SHA window | 000E `4ADDEA→436C40→4B0640` 與 T10 重疊的有界 receiver |
| T14 | 19 條 code-byte、8 個 switch DWORD、4 組 whole .text literal scan | 0022/8case 分派、Scenario/Quest/Outcome 局部 writer |
| T16 | 17 個 SHA code window、6 個 Event XOR-FF 200-byte token | QuestOwner、0x40/46/47/74、Chapter、Quest15/117 Event source |
| objdump | 5 個 rooted 局部區間 | `7A63C0,4B0640,4B0730,4B9790,503400` |

```asm
4D193E E8 AD 64 FF FF              ; call 4C7DF0 (CMonster scene init)
4D2827 E8 C4 55 FF FF              ; call 4C7DF0 (CNPC scene init)
7A65E5 83 C7 0C                    ; borrowed CDoll embedded interface
7BB2FE FF D0                       ; B consumer virtual call
4ADDEA C7 40 74 40 6C 43 00        ; result receiver 436C40 registry
4B0745 B8 4F EC C4 4E              ; result division constant
545480 66 83 4B 5C 01 F6         ; input bit0
4B979B 0F BE 40 02                ; scenario result subtype
4B97A8 FF 24 85 94 99 4B 00      ; 8-case jump
```

**特別驗過的原始資料/陣列**：T10+T12 所述 `0x4B1914` 9 個 DWORD targets，T14 的 `0x4B9994` 8 個 type switch DWORD；T14 直接 constant `0xFC0F88/0xFE18F8/0xF4297/0xF431F` 的 .text raw 搜尋結果依序 3／14／2／3 處，**不能排除 indirect alias**。T10-W07 JSON 可解析出 **12 個玩家情境與24個計畫測試**，尚未執行測試。T16-136 嵌入的 JSON 確認有 **25 個 mainline entries 和6個 independent tutorial entries**，且原稿明示未實機驗證；**未在本次重新解壓/比對所有 Table.stp Quest XML rows**。

## 3. T01 claim 級裁決（不得擴張成 FULL-PASS）

### T08-204/205（Monster/NPC 顯示、刪除與借用持有）
- type1 Monster `C0C9DC+30→4D1910`、type6 NPC `C0CA9C+30→4D2820` 的 Actor 初始化選定分支皆到 `4C7DF0`；CDoll embedded `+0x0C` 借用型指標可透過 `7A63C0` 進 B-vector，`7BB240` consumer 間接調用 vtable slot `C4F6C0+4=7A8310`，選定 bytes / table / E8 均符合 BIN。**不是實際 GPU 像素已驗證**。
- `4B28D0`（命令26）、`4B3710`（81）、`4DFE90`（清場）有不同 Actor/Controller/持有者清理時序。CDoll shared ownership release 與 B-vector raw pointer queue 清除不是同一操作；**只得到可能懸空的條件性風險，不是原版一定 UAF/crash**。

### T10 W06/W07 與 T12 A/B（戰鬥輸入/結果）
- W06/T12 有**同一批 native 000E receiver**：`4B0640` 的 13-byte row、`4B1914` 的 9-case dispatch，與雙 Actor lookup/effect 分支。因此是同源/互證的靜態 consumer，不能因兩篇來源就雙倍升級可信度；T10 000F 不可用訊息和 001A Actor 移除也不能直接視為命中拒絕/死亡。
- W07 接合 S00 Iteration29 的 12 種玩家操作及 24 個 I29 規劃測試；**這些是 matrix/設計交接，不是已完成 Server、執行測試、封包或施放成功公式**。原版 C2S 000A→S2C 000E 是否一次攻擊因果、傷害／扣 HP／死亡規則仍待 Client native + runtime/Server 設計分別處理。

### T14 WP01～03（關卡事件與勝敗）
- WP01 資源/歷史來源 baseline；WP02 的 Scenario/Quest progress writer `4C4F75`、WP03 `4B979B` subtype 和 `4B9994` 8-case、`4C4580` 其它狀態 gate 在 BIN 有選定原生證據。
- `0022` 的八種 result type **不是直接等同八種勝敗結果**。清怪/關卡完成/結果頁/失敗/中止/重入不同；本次沒有完整追到官方勝敗條件、結果冪等或各個異常/UI 下游。
- 既有共享 `CK-SCENARIO-MAP-READ-NATIVE-01`、`CK-SCENARIO-MAP-CLEAR-STATE-01` 的限定 FULL-PASS 不因此擴大或撤回。

### T16-135/136（Quest14→16→15/Pindos 與主線拓撲）
- T16-135 的 Quest14、16、15 / Pindos 是有條件的 Client application/quest UI/scene dataflow，加上 Server 相容性候選，不等於已在原版 Server 實測。T16-136 的25主線/6教程清單來自**原稿已整理的 QuestInfo/Chapter/Event XML**；本輪僅核對嵌入 JSON 結構，並從 Event.stp 原件獨立核對 Quest15 4 個 token 與 Quest117/118 2 個 token 的 XOR-FF decoded200-byte SHA 及 BIN 17個窗口 SHA。
- 原文「QuestInfo table 25條 Demands chain」是作者資源分析主張；**本輪未完全獨立解出全部 XML row**，不能自行升格完整資料鏈 T01 FULL-PASS。Scene3 `pindos_talkevent` 存在不證 Quest15 完成必觸發該場景。

## 4. 全部來源、正式狀態與後續界線

- **T01 R0**：22份新增文稿/驗證資料精確 Git blob、UTF-8 SHA256、版本及路徑 `REGISTERED`；T08 README 只有兩個新專題 prepend，完整保護主線其他更新。
- **R2 定向 native**：上述157個 checks 真實通過；只支持被覆核的精確指令/窗口/部分資料流，並保留反例及 unknown。
- **R3 / FULL-PASS**：沒有整篇通過；未追全 indirect virtual/CFG、完整 000A→000E→死亡重登、T14 真正 victory/wire 時序、T16 全部原始 STP 解壓與Quest實機序列。來源文中的 `FULL`、作者驗證器 PASS 及 CI 不構成原生全文認證。
- **Client 待逆向**：T08 render/delete interleave/indirect owner；T10/T12 封包命中與UI/HP時序；T14 result subtype/Scene轉換及 abnormal path；T16 Quest status/Scene action 真 trigger/QuestInfo完整素材。
- **Server 待開發**：怪物生成／清理時機、技能受理/成本、命中/傷害、勝敗/獎勵、Quest/Server 進度持久化；由 S00 依已證接口制定相容規則，不假稱官服公式。
- **跨 Task 待整合**：T02 framing、T06 asset、T07 scene、T09 motion、T11 skills、T12 hit、T14 scenario、T16 Quest 與 S00 contract；現有 RR SPEC/TEST 不自行改狀態。
- **待遊玩驗證**：真實 KR 客戶端收發、monster visible/deletion、技能/命中、clear/reentry 和25個Quest 逐一實玩，均 **NOT_RUN**。

| Source ID | Task | 精確 GitHub repo 路徑 | Git blob SHA | 來源 SHA256 |
| --- | --- | --- | --- | --- |
| SRC-0630 | T08 | `kr-temp-roy/20261031-171502-chatgpt-web-roy-T08-204-Monster-NPC-CDoll-render-queue-scene-consumer-native-BIN-FULL.md` | `632166645d0e3692e979a81000c2af35d40691a0` | `970c2de56161cd2254f5b2e76f3fb965fd14c8081f4a08b47f97453b9c035f40` |
| SRC-0631 | T08 | `kr-temp-roy/20261031-190457-chatgpt-web-roy-T08-205-Actor-CDoll-B-vector-borrowed-lifetime-and-26-81-reset-BIN-FULL.md` | `e42d1a5c0ad5e1a9a193e71ddb102ca2cb019af0` | `2ee29667010b0a3244999b243f7dc1d46d9181e286f09ce0531322ab14d98aa4` |
| SRC-0632 | T08 | `kr-temp-roy/T08-204-native-pe-verifier.py` | `935aa187e060f8a436357bc434ac6d4dd1c0b277` | `702a5b69f4f84676df791111e5a1dc796cc09a0d68a01fe6fb44edd3cc9a6bfe` |
| SRC-0633 | T08 | `kr-temp-roy/T08-205-native-lifetime-verifier.py` | `40dc14b4adc62f925a965bc82302c6e514d6eb0e` | `ba56e636ac452af35a81a584812928e217758dbe727fc07c67e69cbec396c677` |
| SRC-0634 | T10 | `kr-temp-roy/T10/W06-20261031/20261031-184010-chatgpt-web-roy-T10-W06-hit-result-death-T12-boundary.md` | `69189fda3fee408c373738a1c1113f9470b9d640` | `df9a0cdf5efa817c23df67bb43bac9fb8991f81f3ccdc935eba187b769b0b627` |
| SRC-0635 | T10 | `kr-temp-roy/T10/W06-20261031/20261031-184010-chatgpt-web-roy-T10-W06-native-audit.json` | `7d9770d644e7328329102163cf9225ea8175c5d2` | `ba64bbf1a94db0264dafad61d0fe9d13c62e2b612eccf27e9f862b7c54b275e3` |
| SRC-0636 | T10 | `kr-temp-roy/T10/W06-20261031/20261031-184010-chatgpt-web-roy-T10-W06-verify-native.py` | `497220a48bcdc81a2b41701ffd67d5233686606e` | `a622d2d30dd96db2d4b3abcda61ba156ea8b0e8f89c4e5685c44489284a0e912` |
| SRC-0637 | T10 | `kr-temp-roy/T10/W07-20261031/20261031-191217-chatgpt-web-roy-T10-W07-S00-combat-feasibility-handoff.md` | `1bd44222725303783c0e216d7dbe88b829b1aba7` | `f16df56c25d665442e6dcf2df4264d96f168452f9931ef428352bbdbf47eb7a9` |
| SRC-0638 | T10 | `kr-temp-roy/T10/W07-20261031/20261031-191217-chatgpt-web-roy-T10-W07-S00-matrix.json` | `b3cf7364387cc0fdd598c7831771fe1841f887cf` | `e037d8f05ef27883e1183ff0bc0d30e9faa21901b4a45ac7f6bd10443fe3b809` |
| SRC-0639 | T10 | `kr-temp-roy/T10/W07-20261031/20261031-191217-chatgpt-web-roy-T10-W07-native-audit.json` | `a68c5f3aa17c8df44f82037b3f83f2b9d7e17059` | `5d024a4e1eab35752e6b52cc63abed4c8109b3953857f8f594cb93601eb381cb` |
| SRC-0640 | T10 | `kr-temp-roy/T10/W07-20261031/20261031-191217-chatgpt-web-roy-T10-W07-verify-native.py` | `9609af5609e81515228caa51f1cb65e43f583169` | `76bad6f6425164e57f720de143a690322f95c9193acc8ef43f90e2176b8d03cb` |
| SRC-0641 | T12 | `kr-temp-roy/20261031-212052-chatgpt-web-roy-T12-A-B-BIN-first-battle-result-receiver.md` | `d7cb77d28bf1d8f9b1fa801136afebe7acf80496` | `3c958218112f5dc16e7a4cc7e94a63ba93550ef895e209863e406191f76eea73` |
| SRC-0642 | T14 | `kr-temp-roy/T14/T14-WP01-SOURCE-BASELINE-20261031.md` | `6e65af816d1a5061484e7f21e79cdccce3595f3a` | `fd2cb7b6f1935d3771d85d32f101f84b9d2339441efbf01c08a2516a5fd01137` |
| SRC-0643 | T14 | `kr-temp-roy/T14/WP02-20261031/T14-WP02-OBJECTIVES-EVENTS-PROGRESS-NATIVE.md` | `827216ca7b8ce9dc7460b37673e057d4b0753448` | `1052dd735c7bffacee45af0a063bc811cd8be427e1f943a3e82e0a9f93d0c354` |
| SRC-0644 | T14 | `kr-temp-roy/T14/WP02-20261031/native-window-audit.json` | `ce630ca52414771dc93caf8de2eeaca46272e021` | `e4d0c522dc432006901d6bfd24695996277a2d8dfaaca30814faa0913659a34a` |
| SRC-0645 | T14 | `kr-temp-roy/T14/WP02-20261031/verify_wp02_native.py` | `540dd8d741fd66f7d5e178d629f80cd7522fc804` | `77572e26ca571de91edadbbc0b0e4937253809b27d19a3fc4606cc5af7ea35af` |
| SRC-0646 | T14 | `kr-temp-roy/T14/WP03-20261101/T14-WP03-WIN-FAIL-ABORT-REENTRY-NATIVE.md` | `de17ff49afb2ff460453784b8c1180e63021a3b9` | `d11e599231d805716266b2e2fba539557090685515503f65372731ab0885959f` |
| SRC-0647 | T14 | `kr-temp-roy/T14/WP03-20261101/native-window-audit.json` | `e34a97085e73339e9f4399edb313a7a01b12604c` | `704c09eccf6d617019cd1c5222bd2faee051de2bd341468c6f71260b6cabe3f0` |
| SRC-0648 | T14 | `kr-temp-roy/T14/WP03-20261101/verify_wp03_native.py` | `e56e912e85cb06ffb95b433114943cbf32912706` | `38cfddef62b58162756beac8d1b87676820259b092d448b0e6766aae7b8c0c96` |
| SRC-0649 | T16 | `kr-temp-roy/20261031-165535-chatgpt-web-roy-T16-135-KR-Quest14-16-15-Pindos-player-flow-Server-contract-evidence-matrix.md` | `b0a15aaabe1fc2d86225c5d5466b6ab78564c29c` | `c30665adfbbd10893bc26c938cb025f67aeb6f34051cc5287c641b095caf2efa` |
| SRC-0650 | T16 | `kr-temp-roy/20261031-171527-chatgpt-web-roy-T16-136-KR-Quest-chain-structured-inventory.md` | `18f17463976f570d0b2691e4ff4b3eda1a68421f` | `90e2b1dde0b3aa3841d29ed3388352905492061770984a2a06afd0babf289830` |
| SRC-0651 | T16 | `kr-temp-roy/20261031-171527-chatgpt-web-roy-T16-136-KR-Tutorial-Phindous-Alsmeer-main-story-QuestInfo-Chapter-Event-source-matrix.md` | `6a936c0a058f785b2a9299fbbde5857fe1d83603` | `96cf0925002fbf77b87a47d41a0cf7ad5206ca6e0d67d0878d0be1f35913961d` |

**合併檔案本身不代表五個 Task 已結案**；GitHub merge及 CI 完成後另讀回稽核，並依 T01 原流程繼續各篇有必要的完整驗證。
