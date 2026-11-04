# T01 — 2026-11-03 KR T10／T16 分支研究整合及 BIN-first 限定審核

**責任：T01**；目標 Repo：`we88ec3-prog/ttr_anal_multi`；Client 版本：**KR**。本稿是**來源全件 R0 精確收件 + 高風險主張有界 R2 複驗**，不是整包 T01 全文 FULL-PASS、RR ACCEPTED、S00 SPEC APPROVED 或原版 Client 可玩驗收。所有原始 Client、Server、玩家 DB 均未執行、修改或連線；不碰私庫/PR，也不自行更動其他 Task README、owner、task.json、正式 RR、APPROVED、verified-knowledge。Server 開發需求另交 S00 決議。

## 0. 凍結來源、Git 整合與防覆寫

| 來源 branch | 預備審核時 HEAD | 本次尚未收錄於 `main` 的內容 |
| --- | --- | --- |
| `t10/roy/chatgpt-web` | `df53250face8a6d11f25e0cde3aa778737adddab` | 12 個 Git 檔：含五份舊研究勘誤/交接與 T10/T11 輸入契約、action-buffer、Server 適配、88 情境組合列、證據索引與 211,994B ZIP |
| `t16/roy/chatgpt-web` | `72c558ca3bb171e10ed49dfaf3027790be423bb1` | 56 個 Git 檔：Quest Runtime v0.1.0、20 Quest/4 flows/8 scenarios、CSV、來源證據、schemas、validation/NOT_RUN cards |
| T01 自身 `t01/roy/chatgpt-web` | `e50a66ca03b119fcb70353555109b2d56026a1b4` | 前次馮德斯 W1/W2/W3 41 件來源與兩批 T01 報告、獨立稽核，需**保留** |
| 合併準備時 `main` | `83959c0e7e65ab01348b285f03c285f487077610` | S00 新規劃、工作簿、既有來源台帳等，不可用較舊 T01 樹覆蓋 |

**正式整合手法：**保留 Git 真實歷史，將上述主線與 T01、T10、T16 分支做非強制多父合併；tree 以當前 `main` 為基底，明列保留 T01 獨有研究檔、T10/T16 全部 68 件來源，以及新增本報／audit／provenance／source intake。**不從舊 T01 分支覆蓋主線的 S00 工作簿與規格**。T01 工作 branch 仍是 `t01/roy/chatgpt-web`，不建立新 branch；不直接合並進 `main`。實際最後 commit SHA 以推送後遠端查核為準。

**R0 來源清單：**[source-provenance.json](source-provenance.json) 包含 68 個 repo 相對路徑、Git blob SHA-1、SHA256、來源分支精確 HEAD、size、`SRC-0695～SRC-0762`；完整保留原文、CSV、JSON、ZIP，不以摘要代替。`research/intake/index.json` 的既有 `SRC-0001～0694` 一筆不改，僅追加 68 筆 `REGISTERED`。來源登錄不是文獻全文審核通過。

## 1. 第一手證據與真正重跑的檢查

本次從實際 `/mnt/data/` 唯讀測量：

| 實際原始檔 | bytes | 本輪 SHA256 |
| --- | ---: | --- |
| `Tartaros.bin` | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `Tartaros.exe` | 2,594,816 | `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` |
| `Table.stp` | 5,248,784 | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| `Event.stp` | 11,241,597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| `BoundMap.stp` | 20,772,373 | `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` |

從 PE header 實測 `MZ/PE32/i386(machine=0x14C)/ImageBase=0x400000`；`.text` VA 0x401000/raw 0x400，`.rdata` VA 0xBD2000/raw 0x7D0600。**程式碼 VA→raw = VA−0x400C00，rdata = VA−0x401A00**；不跨 KR/TC 或不同 PE section 套值。

**T10 五份歷史交接補件**：本次另以精確 SHA256 收錄 T10 W00 row5 勘誤、P0-A、P0-B、Server handoff、T11 012A gated consumer 共五篇；歷史的 P0-B 把 000E 接收物件當 Controller，已由新 T10 evidence-index 限定修正為 Scene receiver，**只保留原稿作歷史來源，不升格錯誤推論，也不改既有 T01 退回狀態**。

**T10/T16 原件直接驗證：**T16 交付的 **7/7 個原始 BIN 完整 window SHA256**（0x4ADD50–4AE080、4B32E0–4B3350、544940–5449A0、4A39A0–4A3A00、503040–5030C0、636E10–636EE0、543B30–543BE0）吻合；另從有效 opcode 起點核對 **16/16 個精選 T10/T16 native code anchors**（具體地址/bytes列在 [native-audit.json](native-audit.json)），以及 `D6A62C/D6A630/D6A634/D6A638` 四個 unsigned DWORD 分別是 `100/120/180/300`。未對所有 indirect target 或每篇完整 CFG 做語意 FULL-PASS。

**T16 資源直接驗證：**本輪以唯讀 Python 自原始 STPD/STPI 封包索引、EX mode1 XOR-1024 key、zlib EOF/decoded length 邏輯，**獨立解碼 9/9 指定 member**：`Table/QuestInfo.xml`、`QuestTalk.xml`、`SceneList.xml`、`npctable.xml`、`_TownList.xml`、`_TownTypeList.xml`、`_CaseList.xml`、`_MapList.xml`、`Event/SceneList.xml`，各 SHA256 與原件來源報告一致。原表 `QuestInfo` **4,798 筆**；原始 15→117→118→119→120→121→122→123→124→131→132→133 **12 節點 Demand 鏈**全吻合，選定 **35 個 Event Scene key／35 unique**。`Event/SceneList.xml` 與 `Table/SceneList.xml` 是不同 namespace；`Table/npctable.xml` 不是舊稿口語名 `NpcInfoTable.xml`。本輪缺 `Field.stp`，不得聲稱已獨立重解 Case107 所用 Chart/Cluster。

**Git 交付完整性：**T16 `content-manifest.json` 的 **55/55 個檔案**均從 GitHub 原始 base64 讀回、解成原始 bytes，逐一檢驗 **檔案大小及 SHA256 全相符**，另外驗 manifest 自身 SHA256。T10 **5/5 主要文字/CSV**同樣比對 `manifest.sha256`；其 Git ZIP SHA256 `050e8d999ee75edbc7e4bcbe72792bb94eb8fedb64133b2e4a1bfd6c9c412827`，大小 211,994，ZIP central directory **64 成員**，manifest **63 個名稱均在 ZIP 內**。ZIP 內部 `evidence/buffer-s2c-analysis.md` 存在，**不是缺件**；但此輪沒有逐檔 decompression 重算 ZIP 內的每份 ASM/JSON checksum，也不能假裝詳細包內全文語意已核准。

## 2. T10 逐主張：物理輸入、0A row 與動作回覆分界

| T01 主張 | 第一手與來源適用層 | 本輪裁決／不可越界 |
| --- | --- | --- |
| **T01-20261103-T10-01** Row 的 0x8000 | 原始 `546191` 清 WORD、`54638A 66 85 53 02` 測 `outWORD+2`，`54638E` 的 `jne` 使低15保留 action 時跳過 546100 中 move highbit OR；該 Single 普通路徑的 row 經 callback / owner gates | **N(partial)**：在**具體 Single/546100 路徑**，0x8000 是 row 產生時的移動報告位元，不是 physical held。不證全部 controller 都與低15互斥；Formation 副角色可有不同 producer。 |
| **T01-20261103-T10-02** held+Z vs released+Z 同值 | T10 `input-contract.md` 給出成立條件 owner+58=0、action mask1可保留、方向當前量化 h = actorB0、同 actor。兩種歷史均可輸出相同 `{actor, word=1, byte5=h}` | **I，由 N(partial) 支持的符號同值反例**：封包本身一般不能還原 release edge/pressed次數，**不是實際抓到兩段同值封包**；Server 不得以 highbit=0 自稱物理方向鍵已放開。 |
| **T01-20261103-T10-03** 0A 組包與 aggregate | `545829 BA 0A 00 00 00`、`545B79 66 89 46 5C`，另沿 W03/T10-115 已保存 native；`controller+5C` 只是一個 OR 後的 WORD，不存按鍵事件次數/時間順序。RowA 三槽、RowB 另外 append；最終 0A body 為 `[u16 000A][u32 raw header][N×(u16 actor,u16 rawword,u8 rawbyte)]`，長度 `6+5N` | **R2 bounded**：兩類 row producer／來源 byte 仍有 owner/callback 限定；不能按相同 actor/byte 自動 dedup、不能把每個 raw WORD 拆成每次實體 Z/X/C 按下。 |
| **T01-20261103-T10-04** Clock、cooldown 與 buffer | `D6A62C..38` 四 DWORD 已實測 100/120/180/300，`5457A4` 有發送 gate；資料屬 sender timing，不是 combo window。`54F270` 本地 availability predicate、`012A` timer map不同於 action queue | **N(partial)＋明確 unknown**：不得套用 `0.4/0.65sec` 作官服 chain/cancel；T10 提到 `F9423C/timeGetTime` 依其他來源，未在本批重做全部 clock caller；資料分域保留。 |
| **T01-20261103-T10-05** FSM/motion/movement | `4CA060` state transition、`4CA890` movement、`000B` 位置/moving、`000C` current-state、`000D` actor status/motion，均不同資料與更新介面；選定碼錨點已符合原 BIN | **N(partial)**：`000D motion9` 與 `000C state5` 在已查 CCharacter 路徑不等同；沒有官方「一次 0A 必收 ACK/000E」證明。不能因已有 motion 就推技能受理、扣費或命中。 |
| **T01-20261103-T10-06** 000E 舊版 P0B 勘誤 | 本次 T10 `evidence-index.md §3` **明確撤回 2026-11-01 P0B 把接收器誤當 Controller 的部分**，保留 `436C40` 分派時有 scene+28→`4B0640/4C4920` 的結果路線；舊 controller +28 stub/cleanup 的 raw vtable 存在，不足以證 actual receiver 身份 | **CONFLICT_NOTED / PARTIAL**：T01 先前曾列兩種 vtable 層，此份新原稿把 active receiver 類型更正為 scene；**不得聲稱所有 000E 都清理**，也不得聲稱 13B result 一定引發 HP/受擊或 Server 已送該封包。原 P0B 舊歷史不刪改。 |

**T10 實作分層（可交 S00 設計，不是原官服邏輯）**：保留原始 0A bytes、row order/ordinal、rawheader、sender/owner provenance unknown；分開 `LastInputObservation`、`AuthoritativeMovement`、`ActionExecution`、`ClientFSMDirective`、`MotionDirective`。不把 last-key/hold-from-wire/nonce/cast-ACK 作原生欄位。現在仍須有正常情境同 session 真 row+S2C 時序，才能判斷 v16 玩家 held方向連點 Z 無法移動／released方向 Z 仍移動的確切層次。T10 所引用歷史使用者四方向＋Z為**整體失敗回報**，沒有逐向結果，不能補成 PASS。

## 3. T16 逐主張：原始 Quest 資料與 Server Runtime Draft 隔離

| T01 主張 | 獨立本輪依據／限定 | 適用及解除條件 |
| --- | --- | --- |
| **T01-20261103-T16-01** Quest/Demand 基本資料 | 原始 QuestInfo 4,798 rows、選定 14/16/15/117–124/131/132/133 的原始 attributes、Demands；`15→117→…→133` 十一條連接成立。14 type3 Town0 無 Demand、16 Demand14、15 Demand16。 | **R 已直接驗 member + XML 局部內容**。資料未提供完成目標 count、正式 reward policies、權威完成條件。 |
| **T01-20261103-T16-02** Chapter/Scene namespaces | 原始 Table/SceneList 與 Event/SceneList sha distinct；選定 35 Scene pairs 均唯一；Q117 一段，Q119 五段；Q118 有 Field28 卻一段；Q131/Q132 Quest town1 但 Chapter2 town2，Q133 Quest town2。 | **R 資源已確認**，不是 S2C 0047 自動送出順序；不能用 Chapter town/field/sceneIdx 直接推玩家地點、關卡入場或 NPC spawn。 |
| **T01-20261103-T16-03** wire/Scene 原生入口 | 7/7 BIN windows 全 hash 一致（包含 `4ADD50` app dispatcher、`503040` Quest ScenePair consumer、`4A39A0` local sender 等）；`0x4ADD50` 真實 app table/source 不同於原版 Server 的業務交易。 | **N(partial)**：只有選定 windows/code 範圍；端到端傳輸、UI/scene 是否接受、派送/完成、live packet 仍 U，不能用純 JSON flow 自稱官方 ACK。 |
| **T01-20261103-T16-04** 資源／NPC 字典域 | 9/9 STPD members 狀態、`npctable.xml` 正式檔名與 Town/Case/Map/Quest 的 typed IDs；原始 Quest XML 部分元素明確**缺失**，不是零或空規則。 | **R**：NPC resource ID ≠ world EntityId/event selector；同數字的 Quest/Field/Case/Map/Reward type 不互相替代。缺 `Field.stp` 的 Case107 MAPFLOW/CLUSTER 不在本輪補證範圍。 |
| **T01-20261103-T16-05** Runtime v0.1.0 validator | source `validation-report.json` 明示 `structural PASS/errors0`、`activation BLOCKED/unsafe0`、`runtime_tests_executed=false`；本輪獨立檢查 20 Quest definitions、4 flows、8 Scenario entries 的 `activation/status` **全部 DRAFT_BLOCKED**、source package 55/55 SHA256。 | **PACKAGE INTEGRITY VERIFIED + SOURCE-REPORTED structural PASS**：這次沒有重新實際執行作者完整 `validate_content.py`，也沒有執行遊戲。不得將其 CSV schema PASS 叫做 Server API 已實作或 16 張驗收卡已通過。 |
| **T01-20261103-T16-06** Quest Runtime 設計候選 | 20 Quest/4 flows/8 Scenario 的 model_kind 為 `SERVER_CANDIDATE_NOT_NATIVE_MEF`；`q15`、`q117`、`q119` nodes 是業務候選，缺合法 predicate/settlement/override 的地方保持 BLOCKED。 | **S 設計候選／未知**；任務完成、獎勵 grant/persist、重試、多人共享、Scenario 結果原服策略未從 Client 正向封包閉合。不能因有 model/schema/flow 就授權啟用。 |

**T16 歷史工作副本的正流程**：來源接受卡保留使用者到廣場、v12 到馮德斯的舊人測（其中還有 NPC 對話重疊、清怪後自動換場、放方向後 Z 仍移動三項缺陷）。它們是特定 Server/Client 工作副本和保存快照的**歷史觀察**，不是原始 KR Client 全面驗收，更不是新 Runtime v0.1.0 人測。`Field.stp` 缺件，作者未重解相關圖/cluster；T01 不用 BND、Event/Scene 動畫座標當世界合法玩家出生點。

## 4. Server 待開發（非 Client 待逆向）

| 玩家需求／ Server 開發候選 | 已有 Client 介面證據 | 必須由 S00/Server 定義或保持未採用 |
| --- | --- | --- |
| T10 原始按鍵與多 row 保真 | `000A 6+5N`、`controller+5C` OR/clear、`000B/0C/0D` 各自更新 | 意圖解析、動作／移動權威決策、同 actor 多row處置、啟用/取消/扣費/冷卻、拒絕/修正與廣播；**不冒稱還原物理 released/held** |
| T16 通用 Quest 接取／目標／結算 | QuestInfo Demands、Scene pairing、限定 `0036/003F/0040/0045/0046/0047` producer/consumer | QuestRun/ObjectiveEvidence/合法完成 gate、reward ledger、持久化、公佈與次一Quest解鎖；禁止把劇情播完當完成 |
| T16 Scenario bridge | Field/Case/MapFlow typed candidates、result22/return33 既有 W2 有界界面 | Instance admission、opaque token 保留、過關與結算條件、Scene ready/return；Q119 Case107 charts **原 Field.stp 未提供** |
| T16 migration／新引擎切換 | 四個候選 flows、八 Scenario、16 張 NOT_RUN 卡與舊版工作副本保全 | S00 核准每個 BLOCKED gate，正流程 Client 人測後逐項遷移；不直接一次取代 tutorial/Quest15 舊版路線 |

**Client 待逆向**：T10 full producer 及 multi-context heading、physical phase→row 的全路徑與實機 S2C 時序、000E receiver instance identity；T16 Quest accept/complete/reward 的真 app 消費者與 Quest119 field resource/UI 回應。**跨功能**：T02 framing、T07 Scene、T08 Actor、T09 Motion、T11 skill、T12 damage、T14 Scenario、T16 Quest。**待遊玩驗證**：上述流程及新 Runtime 均為 `NOT_RUN`，不因 source SHA 或 CI 改為 PASS。

## 5. 正式 T01 審核裁決與歷史保持

1. **R0 已完成：** T10 12、T16 56 筆 exact blob/source SHA，共 68 個來源登錄 `SRC-0695～0762`；T16 55/55 source SHA、T10 5/5 top-level SHA、ZIP/manifest 成員名稱及 blob 核實；原件 hash/section 身份符合。
2. **R2 限定已完成：** 上述 16 個 T10/T16 anchors、7 個 T16 BIN windows、9 個原始 STPD member、Quest chain、35 Scene keys；可供 S00 跨 Task 具體查詢，但**不代表新的 NATIVE_VERIFIED / FULL-PASS**。
3. **嚴格歷史保留：** T10 原七個 T01 RETURN（116、062、063、007、026、055、056）依原 README 狀態不變；T16 既有固定退回和歷史 RESOLVED/READY_FOR_REVIEW 不改。原來源報告本次只加引用與勘誤，不改舊原文。沒有任何新的 RR ACCEPTED、S00 APPROVED、SPEC STABLE、Server 試跑或原版 Client 人測。
4. **下一個精確門檻：** 要正式准入某一主張，先以精確 source blob/受影響 scope 追完整 function entry、回呼 this、關鍵 CFG、positive/negative 相反證據與資料依賴，再由 T01 独立作 FULL-PASS 決議。S00 另外依實作設計/玩家正流程核可。

