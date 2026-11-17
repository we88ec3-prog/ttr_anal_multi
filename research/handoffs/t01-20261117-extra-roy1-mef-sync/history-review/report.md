# T01：extra/roy1 舊 MEF 批次的重現與有界語意檢核

審查日期：2026-11-17（Asia/Taipei）。審查者：T01 / t01_legacy_native_review。來源固定為 `extra/roy1@534746f194a889ebb34dda7471c2ae62d30a1dd1`，整合基準 `main@03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。本分題涵蓋最新 P0／comprehensive 以前的 **17 個公開研究包**與其外置主稿；最新兩包只讀更正、來源及驗證邊界，另由其他分題審查。

## 1. 結果與可採用程度

17 個公開包均已找到可重跑的正確來源與命令，並取得成功的原件／結構核對結果。R6、R7、R8 由 R9 的 `--recheck-prior` 實際重新執行，其餘按各包頂層驗證器執行。one-shot 封裝先逐檔還原，再分別執行 study 與 callbacks 的驗證器。

**判定為 R0 重現通過、R1 完成範圍與更正導航，並對選定高風險主張完成 R2 定向複核；不是 17 包全文 FULL-PASS。** 未修改原稿、來源收據、Task owner、RR、正式共享知識或 Server；沒有執行 Client／Lua／Server，沒有新建 branch。

原稿中的 `PASS` 仍只代表所寫驗證器的機械檢查。尤其 feature-lifecycle 的舊圖片模型即使測試仍通過，其「新圖只覆蓋 handle、不先取消舊圖」語義已被原件反證，必須採 comprehensive／P0 的更正，不能重新升格舊模型。

此次另澄清一項可重現性問題：surface／A1 需要的是 **one-shot 封裝還原的 parser**，其正確 SHA 是 `3a7e2751…`；它不是 R2 的 `8eb16bbc…` parser。依原 README 還原並提供正確版本後，surface、feature、A1 均可完整重跑，不需修改任何舊 verifier 的 pin。

## 2. 原件、來源身份與執行環境

| 原件 | Bytes | SHA-256 |
|---|---:|---|
| Tartaros.bin | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| Event.stp | 11,241,597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| Table.stp | 5,248,784 | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| BoundMap.stp | 20,772,373 | `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` |

`source-identities.json` 固定 80 個與本檢核有關的 README、主稿、驗證器、manifest 及更正來源，逐檔核對 source commit、Git blob SHA、byte length 與 SHA-256。這 80 個檔案是本分題來源身份清單，不是宣稱只合併 80 檔或完成 80 篇全文語意驗收。整份 delta 的 R0 清單由主審另外保存。

執行前讀取各頂層 verifier、受其調用程式的 subprocess／輸出／動態載入路徑及所需 parser；可執行子程序限 Python 研究檢查器、Git 唯讀查詢與 objdump。環境使用 `-B`、`GIT_NO_LAZY_FETCH=1`、`GIT_OPTIONAL_LOCKS=0`、`GIT_NO_REPLACE_OBJECTS=1`、`GIT_TERMINAL_PROMPT=0`，並以 `protocol.allow=never` 禁止 Git 檢核自行下載來源。沒有執行原版遊戲或 Lua bytecode。

## 3. 17 包重現矩陣

下表只描述本次實際執行範圍。window、bytes、instructions 可在不同包間重疊，不能加總成全程式覆蓋率。

| 公開包（`kr-extra-roy/`） | 本次執行 | 主要範圍與限制 |
|---|---|---|
| MEF-trigger-callers-20261115 | PASS | 原件、119 個 tree pins、named calls 與三個子題；動態／間接首次 caller 未被全域排除 |
| MEF-complete-flow-20261115 | PASS | 五個子題、parser/executor、資源、保存別名、Lua 當資料、換場；不是新 MEF 首次載入成功 |
| MEF-runtime-contracts-20261115 | PASS，R9 實際重跑 | 40 個 artifacts、184 個 commit/path pins，scheduler／input／UI／VM；原 Coroutine 正確 bytes 由固定 Git carrier 暫存供應 |
| MEF-world-integration-20261115 | PASS，R9 實際重跑 | 37 個 artifacts、245 個 pins，wire／runner／identity／events；原始 source 與 SYN framing 算術分開 |
| MEF-content-contracts-20261116 | PASS，R9 實際重跑 | 37 個 artifacts、232 個 pins，bridge／actors／observers／ordinary runner；不把 Q slot 等同 world EntityId |
| MEF-end-to-end-20261116 | PASS，含 `--recheck-prior` | 41 個 artifacts、271 個 pins、265 個 source blobs；三個新子題與 R6–R8 都實際執行 |
| MEF-control-flow-20261116 | PASS | 44 個 artifacts、244 個 pins；本包去重後 11,233 個 instruction starts、39,877 bytes；舊 R9 收據僅比較，R9 已由本次獨立命令重跑 |
| MEF-capabilities-20261116 | PASS | 50 個 artifacts、341 個 pins、121 binding／75 helper；本包去重後 32,582 個 instruction starts、106,124 bytes |
| MEF-checkpoint-20261116 | PASS | 25 原件 anchors／PE mapping；另作下節獨立語意核對；原 verifier 不宣稱完整上下游語意 |
| MEF-trigger-continuation-20261116 | PASS | 12 anchors；另獨立解碼完整 544730 與最近候選選擇，保留 native latch 與 Lua getter 的區別 |
| MEF-tutorial-observation-20261116 | PASS | 24 windows、2,149 instructions、選定 Lua/XML 與明示 SYN 模型；Tutorial context 限定 |
| MEF-one-shot-followup-20261116 | PASS | 封裝 24 regular members 還原 25 個原稿檔案；study 42 windows／3,380 instructions、callbacks 35 windows／1,200 instructions 各自 PASS |
| MEF-A-minimal-spec-20261116 | PASS | 正確還原 parser、SceneList 候選鍵與原件 anchors、SYN 契約；候選未配置到真實 run、未部署 |
| MEF-full-surface-native-continuation-20261116 | PASS，含原 qbase | 121 正常名稱、122 registrar、223 closure call、11 library table call、46 windows／5,227 instructions；有界模板／sink 集合，不是全部 Client API |
| MEF-feature-lifecycle-20261117 | PASS，含原 qbase／manifest | 50 windows／2,530 instructions、121 列與 32 個歷史 SYN；圖片模型中已被推翻的預期隔離，不能因這次 PASS 復活 |
| MEF-world-identity-scene-interaction-20261117 | PASS | 48 windows／5,113 instructions、原 Table/Event/BoundMap 選定資料與推導模型；無普通 world typed result→Lua 完整橋 |
| MEF-transition-actor-event-20261117 | PASS | 19 windows／1,648 instructions、選定資源與 38 個明示模型檢查；deployment bindings 保留 null，BND 零格不是合法 spawn 證明 |

各原始 stdout、stderr、參數、退出碼、執行時間及雜湊在 `commands-results.json` 及對應檔案。本次共 23 次頂層命令記錄：15 次成功、8 次首次呼叫因附件 basename 對不上歷史 metadata 而失敗；15 次成功含同一 one-shot 公開包內的兩個研究子包。R9 另在內部重新執行 R6–R8。這些數字是執行記錄，不是主張數、獨立函式數或完成百分比。

## 4. 兩項重現問題的精確處理

### 4.1 原件相同而 basename 不同

使用本回合上傳的 `06-Event.stp`、`07-Table.stp`、`10-BoundMap.stp` 時，八組後期研究的 STPD reader 將 `Path.name` 放進 `member.carrier`，與歷史記錄的 `Event.stp`／`Table.stp`／`BoundMap.stp` 做整個 dict 比較，因而失敗。

本次沒有改原件、驗證器或保存證據。僅在 scratch 建立同 bytes 的唯讀使用路徑（symlink），保留歷史 basename，再重跑八組命令，全部成功。`basename-diagnostic.json` 直接比較同一 qbase 解出內容：decoded bytes 與 SHA 完全相同，metadata 唯一差異為 `carrier: 06-Event.stp → Event.stp`。`canonical-originals.json` 保存所有原件的對照與 hash。

首次失敗紀錄保留為呼叫環境差異，沒有偽裝成首次就成功，也不把它列作 native 語意錯誤。這項檔名相依性應在重現說明保留；不得以放寬原件 SHA 檢查處理。

### 4.2 surface 的正確 prior-parser 在原無損封裝中

`MEF-one-shot-followup-20261116/research-kit.tar.xz.part01…part12` 串接後，研究封裝 SHA 為 `b970253d6dee56b6df8e8b8b3a71285e0f320a6364ef5739f602fe869cb4524e`。tar 有 24 個 regular members；其中 `packed/previous-native.json` 按原 restore 程式恢復為兩份原檔 `native-evidence.json` 與 `native-evidence.asm`，所以最終為 `24−1+2=25` 個原稿，25 個尺寸／SHA 全符合 manifest。

其中的 `MEF-one-shot-study-20261116/verify_evidence.py` SHA 為：

`3a7e2751274b9c1cc43f514e8ab13a5b48ff5983251f847334e213baab0381d2`

正好等於 surface `PARSER_SHA` 和 A1 `PINS` 所需版本，其 parser API 為 `STP`／`lua`。comprehensive/reuse 採用的 R2 `MEF-parser-executor-storage-20261114/verify_evidence.py` 是另一個檔案，SHA `8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56`，其 API 為 `STPD`／`read_lua51_prototypes`。兩者不應互換。

因此應將「舊 aggregate 未重跑」保留為 comprehensive 當輪的真實紀錄；但**不可繼續推論舊 aggregate 已發布的 pin 本身無法滿足**。本次依 surface README 指定的來源還原並成功完整重跑，沒有修改 pin。這是 T01 對重現來源的補充裁定，不撤回 comprehensive 新原生證據，也不撤回其 FlyingObject 語意勘誤。建議採用標記：`REPRODUCIBILITY_CAUSE_REFINED_CORRECT_ARCHIVE_PARSER_AVAILABLE`。

## 5. 獨立 R2 原件複核：互動點與完成訊號

除了重跑作者工具，本分題新增 `independent_native_review.py`，不匯入任何舊 verifier，重新解析原 BIN 的 PE sections，使用 objdump 解碼 **11 個限定完整窗口、1,312 條指令**，核對 17 個關鍵指令及 9 條直接呼叫。`independent-native.json` 保存 VA/raw、SHA、邊界、錨點與 call target；`independent-native.asm` 保存此次實際解碼。

以下為本次讀過完整相關窗口後的有界裁定；全部保留 `PARTIAL_NOT_FULL_PASS`，不宣稱完整 frontend/wire／所有 caller／實際遊玩也已獨立驗完。

### T01-LEGACY-MEF-POINT-DELTA

`4B32E0..4B3347` 的 0048 handler 在 `4B3327/2B/2F` 分別讀 app 的 byte `+5`、byte `+4`、word `+2`，以 status/category/key 送到 `544940`。正式 setter `4A9460..4A94C0` 的 `4A94B6` 也直接呼同一 target。

`544940..54499F` 對 vector 逐項比 low WORD key，於 `54496F` 再將 category 的 low byte sign-extend 成 WORD 比較；第一個匹配在 `54498C` 取 point，`544993` 呼 `543B30` 後直接返回，miss 不建立 point。`543B77` 寫入 `point+0x105`。因此可保留「更新既有第一個 `(category,key)` 的狀態」；不能外推為 upsert、座標搬移、世界模型生成或業務完成。

**Server 開發需求：**以已發布完整集合為前提管理唯一 typed point、狀態 0/1、場景 generation 與再入快照；價格、強化、任務進度及資產保存由 Server 自行實作。對 0027 全量替換的完整 handler 證據，本分題復用原 source＋重跑，不另聲稱本節重新全文語意核過。

### T01-LEGACY-MEF-POINT-LATCH

`544730..5447EF` 的停用早退只寫輸出0並返回，不清 `point+0x104`。mode0 在 `5447A3` 檢查 input；非零 mode 跳到 `5447CE` 而略過該檢查。成功分支置 `+0x104=1`，但若先前已非零則把「新候選」輸出清0；落空／離開分支才在 `5447E0` 清 latch。`544A00..544B60` 同時使用 helper 回值與輸出、距離及 page gate 決定分派。

保留「disable/re-enable 不保證全新 one-shot 邊緣」。不能將這個 native latch 當作已證 Lua getter，也不能推定 mode0 必然對應某一鍵。Tutorial progress 的 getter 是另一條 context 限定鏈，已由 tutorial 包原件／Lua 資料重跑。

### T01-LEGACY-MEF-003F-NOT-SUCCESS

`4A39A0..4A39EC` 建立 8-byte application `WORD 003F | WORD arg1 | WORD arg2 | WORD 1`，在 global send guard 允許時排送。`561760..561DB0` 的既看過支線，只有在明列 flag／第一 key／GameInfo mode／集合命中等條件下，到 `5618C8` 呼 builder，`5618CD` 置等待，`5618D2` 直接跳尾部 `561D86`；正常接納的 key/active 寫入在其後的 `5618E9/EC/EF`。這是可讀原件中的具體略過反例。

normal End 的 `561FB0` 與 `561FE0` 亦可呼 builder，且在 `56202D` 的 coroutine 移除回呼之前。因此 **003F 不是新腳本曾執行、所有清理完成、通關／交易成功的充分證據**。

**Server 開發需求：**自己保存 run identity、內容雙鍵與階段，區分略過／正常End／取消，依真正業務規則更新結果。這是相容 Server 需求，不要求猜還原官方 Server 演算法。

### T01-LEGACY-MEF-00EB-UNLOCK

`4B6190..4B61FD` 正常 handler 不讀額外 message payload，`4B61E5` 呼 `562250`；已初始化狀態下，後者依 `F4322` tag 移除等待 UI，`562307` 以 `AND FB8830,FFFFFFFD` 清 mask bit2。這是等待解除鏈，沒有獨立 run token/ACK。

該有界結論不能等同所有輸入 owner 清空、Q/VM/所有 coroutine 結束或新內容成功。上游 packet/front-end/current field 的限定路由與兩種 SYN frame 由 R7 wire 原報告／作者 verifier 重跑支持；本節沒有以 11 窗口把整條 wire 鏈升格 FULL-PASS。

## 6. 原稿更正與 Server 採用邊界

| 問題 | 本次處理 |
|---|---|
| FlyingObject 舊「只覆蓋最後 handle」模型 | 原 ASM 保留；指定舊主張／SYN 預期維持已被推翻，以 comprehensive/reuse/errata.json 及 P0 採用版為準；32 個舊 SYN 仍 PASS 不構成反證 |
| surface prior-parser | 本次證明 exact archive parser 可用且 aggregate 可成功；補充重現方法，不改舊來源／舊回合紀錄 |
| A1 `(0,32760)`／新 sequence 候選 | 僅固定原 SceneList 未佔用的候選；不是官方鍵、跨 Agent 保留鍵、已安裝內容或 deployment 授權 |
| 121 binding／75 helper | interface census 與 helper 索引；不是 121 種獨立完成玩法。stub、query producer、prepass/formal、typed identity 仍須逐項採用 |
| World actor、Q slot、point key | 不同容器／命名域；不因都是整數或相同 offset 即互換 |
| 場景及 BND 靜態資料 | deployment bindings 未填、zero cell 不等於合法 spawn；不得以本次 PASS 猜合法配置 |
| 官方 MEF 首次 caller／grammar，ordinary 結果→Lua | 仍是有界讀集內未閉合的 Client 證據；並未由本次檢核取得新路徑 |

可交給 S00 的 Server 工作包括：內容版本與合法發布、完整 point snapshot／delta、run 排程與狀態對帳、003F/00EB 收尾協調、合法 typed identity、服務及資產／進度保存。這些應沿既有 REQ-0019／REQ-0021 等權威工作線去重收件；不另建平行 RR/REQ 台帳。

跨功能整合與真人遊玩驗收仍分開：合法入口、prepass/formal、owner 清理、現場資源及主線業務結果沒有因重跑腳本而自動完成。此次沒有修改任何正式接受狀態。

## 7. 發布與交接

可提交檔案以 `publication-files.json` 的明確 allowlist 為準。**不要遞迴複製本 scratch 目錄**：其中 `canonical-originals/` 是指向原 BIN/STP 的本機 symlink，`restored/` 是供重跑的歷史研究副本；兩者均不屬本輪新交付。只保存本報告、source identities、重現命令／收據、basename／封裝診斷、獨立原件節錄及檢核程式。

本分題沒有 Commit／Push；來源同步、T01 主索引與正式提交由主審統一處理。既有檔案未改寫，所有初始失敗與成功重跑都有各自收據，沒有以摘要取代實際結果。
