# S00 Iteration 20 — E00–E26 / E17-A–J 逐 Gate 證據盤點、既有 RR 去重與下一輪驗收切片

日期：2026-10-31（Asia/Taipei）  
基準：`ttr_anal_multi` main `7d0851d3fb600106161249badc5eb2832edf02ce`。  
**狀態：規劃／靜態台帳對照（DRAFT / NOT_RUN），不是新正式 SPEC、RR、REQ、GAP、TEST、Client 可遊玩證據或 Server 已完工宣告。**

## 1. 本輪完成的 S00 設計工作

本輪依 Iteration 19 §9 的建議先做「逐 gate 現有證據映射與 RR 去重」，不重建已存在的逆向分析。可機器檢視的全量清單為 [Iteration 20 Gate Evidence Trace](S00-ITERATION-20-GATE-EVIDENCE-TRACE.json)：

- 檢查 Iteration 16 的 **E00–E12（13 個）**、Iteration 17 的 **E13–E26（14 個）** 和 Iteration 18 的 **E17-A–J（10 個，從屬於 E17）**，合計 37 列、27 個主旅程 gate，無重複 ID。
- 逐列保存原草案的 `evidence_state`、責任 Task、`blocking_unknown`，以及**原草案本來就有的** REQ/RR/GAP/SPEC 連結；沒有原草案直接連結的項目保留空陣列，**不得解讀為正式台帳不存在相關研究**。
- 對照唯一正式 `research/requests/index.json` 的八個 RR 當下 `dispatch.state`，分辨「既有範圍需要審核」、「先查範圍才能提新 RR」、「Server 政策須 ADR」和「原 Client runtime 未授權」。
- 登記所用來源檔案的 **Git blob SHA**。本輪沒有讀取／複驗原始 KR BIN，亦沒有改寫 Client、Server 實作庫或任何原生研究 owner。

原版 KR Tartaros.bin SHA256 沿用來源索引 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；**本輪未重新計算**。TC 不能共用 KR 函式位址或 opcode。

## 2. 唯一 RR 台帳核對結果（快照，不取代台帳）

| RR | 當下 dispatch | 原研究範圍 | S00 依賴與結論 |
| --- | --- | --- | --- |
| RR-0001 / T02 | IN_REVIEW | KR framing／第一筆收發與 mode | E01/E03 的部分前提；不能證明真實原 Server 首包 |
| RR-0002 / T03 | **BLOCKED** | 選角 C2S 與 S2C 結果配對 | E04/E07/E08/E09 仍受阻，不能把 C2S `0x42` 當創角 opcode |
| RR-0003 / T03 | IN_REVIEW | 登入 E8/000F／0x13 結果 | E01/E02 仍缺正向完整配對 |
| RR-0004 / T02 | IN_REVIEW | Conn+A02C alias／mode fallback | E01 transport 部分；不能外推完整 runtime |
| RR-0005 / T02 | **ACCEPTED** | 登入結果到 Connect slot 的有界研究 | 僅接受該研究交付範圍，**不等於** E03 的跨線 E2E 成功 |
| RR-0006 / T02 | IN_REVIEW | 0x2633 與錯誤處理 | 封包解析異常路徑；不解決戰鬥或選角語意 |
| RR-0007 / T02 | IN_REVIEW | S2C dispatcher 與場景 guard | E02/E04 的 Consumer 限定條件，未完成 UI-ready |
| RR-0008 / T03 | IN_REVIEW | 選角回覆到 scene key/第一次教學 | E09–E11 的正向 scene 链仍待審查／補證 |

`RR-0002` 的原稿明確表示「找不到原版 Server 的 success/error 消息順序」，可由同版本可信原始交換資料、原版 Server 來源或**新發現且可驗的 Client 正向 writer/caller 鏈**解除；本輪沒有這些新證據，不得擅自改成 ACCEPTED。所有既有 GAP 仍 OPEN、SPEC 仍 DRAFT/PARTIAL，六個正式 TEST 仍只有 OFFLINE_SYNTHETIC；這是不同台帳，不能由單一 RR 結案自動推進。

## 3. 依產品旅程進行 Gate 去重、決策及驗收

| 切片 | Gate | 應優先核對的既有工作 | 下一份可以交付的**有界**證據／設計 | 當下決策 |
| --- | --- | --- | --- | --- |
| A 登入到零角色清單 | E00–E04 | RR-0001/3/4/5/7、RR-0002、SPEC-NET/AUTH/CHAR/FLOW、GAP-NET/AUTH/CHAR/FLOW | 指定 key/slot + mode + direction 的登入 → 選服 → S2C roster；N=0 的 UI predicate／失敗分支 | **不開重複 RR**，先審現有成果 |
| B 創角 | E05–E07 | RR-0002/7 的 roster 範圍、T03/T04/T06 現有原稿 | 零角色 UI 正向入口 → create C2S producer → create S2C consumer → 新 roster，分離重送/失敗 | **先去重，再評估新有界 RR** |
| C 選角入場 | E08–E12 | RR-0002 (BLOCKED)、RR-0008 (IN_REVIEW)、T03/T07/T16 | C2S 選角 → *正向* result/state writer → scene-key 選擇 → 第一個可互動教學畫面；各步不同驗收 | **沿用 RR-0002/8**，不憑 `SceneList(1001,1)` 猜 wire |
| D 場景與腳本準備 | E13–E16 | T16 Tutorial Lua、T06 資源、T07 場景、T02 framing | 本地 checkpoint／Script 狀態、server-notified transition 和 Scenario14 C2S 消費前提的邊界 | **精確來源核對**；不把 local callback 當封包 |
| E 戰鬥最小閉環 | E17、E17-A–J | Iteration 18 CR18-01..06、T08/T09/T10/T11/T12/T13/T14 | 同一 instance 的 actor spawn、owner/AI、move、basic/skill intent、damage/death、objective/result 的方向別證明 | **候選研究去重**；不把 client animation 當命中結果 |
| F 任務結算 | E18–E22 | T14/T16（Scenario14、CTutorial 0x4C、QuestInfo14、Quest16） | Scenario settlement、Quest14 turn-in、Quest16 unlock/accept/complete 必須各有 writer/reader 與失敗路徑 | **檢核既有有界研究**；無交叉證據則保持 BLOCKED |
| G 離場與重登 | E23–E26 | T15/T16/T07 與 S00 Server ADR 評議 | per-character? tutorial state／Quest15 可接／非教學場景可操作／relogin 一致性逐項證明 | **Server 交易政策另提 ADR**，原 Client E2E 需明確授權 |

### 關鍵去重判定

1. **P0／登入、角色清單**：RR-0001、0003、0004、0005、0007 已涵蓋大量 transport/login/dispatch，**不建立相同問題的新 RR**。針對 E04/E05 的零角色 UI，不能把 roster 正向解析等同「創角 UI 可按」。
2. **P0／創角**：既有 RR-0002 定義的是 *selection* response，不能在未修訂範圍下視為 *creation* request/reply。先在 T03/T04/T06 的現有來源找出 create UI 入口與真實 C2S/S2C；若沒有，再由 S00 草擬窄化的 Create 專題，確定與 RR-0002/0007 邊界後，才透過唯一正式 RR 台帳派工。
3. **P0／選角與進教學**：RR-0002 本身 BLOCKED、RR-0008 尚 IN_REVIEW；不新開「再找 0x42 reply」的同義 RR。S2C `0x42/0x43`、`0x69/7`、`0x565720` 和 Event `(1001,1)` 必須分開證明。
4. **P1／戰鬥 CR18-01..06**：這六個是 **Iteration 18 候選題**，不是正式 RR。當前 8 個 RR 中沒有正式編列 Scenario14 spawn、技能結算與 AI owner 的同義獨立請求；仍必須先閱讀 T08/T09/T10/T11/T12/T13/T14 的現有主稿與 Task 收件箱，確認是否已有相同有界答案，才評估新增 RR。
5. **P1／完成教學與重登**：T14/T16 的 Lua/Quest 消費端存在，不證原版任務完成順序。Server 可先在獨立實作庫使用**標明為自訂策略**的冪等／所有權測試，但這不能填補 native wire GAP。

## 4. 下一份原生證據的最小交付格式

每項研究交給 S00 前需要以下欄位，禁止留白後假裝已驗收：

```text
Gate: E06 | E09 | E17-B | E17-F | E17-G | E17-H | E20 | E25 ...
Client version/build + SHA256: kr / original verified build
Owner Txx + source path + Git blob SHA + bounded BIN function/byte span:
Source direction: LOCAL | C2S | S2C | UNKNOWN
Preconditions: connection key/slot, frame mode, scene, actor/character/instance
Positive chain: producer -> queue/wire boundary -> dispatcher -> consumer -> visible or stored state
Negative chain: reject/malformed/missing resource/timeout/duplicate/disconnect
What is proven: source-only vs source-backed bounded (precise statement)
What remains UNKNOWN: first frame, actor authority, result order, status/field meanings
Existing RR + GAP + SPEC + CLM + TEST with status from their canonical ledgers:
New RR needed? NO | REVIEW_DEDUP_FIRST (with overlap note)
Run evidence: NOT_RUN unless separately authorized; test environment and proof required
```

尤其 E17-B（怪物出生）、E17-F（技能）、E17-G（傷害死亡）、E17-H（勝負/波次）**必須**能接起一個同場景、同 actor/instance、同時序的最小正向因果鏈；只各證一個 Client handler 並不能宣稱 E17 通過。沒有原版 spawn plan、起始技能 ID、MP/cooldown 或 Quest 勝負條件時填 `UNKNOWN`，不得為湊可玩性挪用假資料當原版值。

## 5. Server-only 提案：跨模組安全邊界（**尚非核准 ADR**）

以下可獨立交予 Server 實作者做 `SYNTHETIC_DOMAIN` 測試；**不是原版 Client/Server 協定**，不可寫成 native MUST：

- **Scope 與 fencing**：對每筆 action 檢查 `account_id / character_id / session_generation / scene_instance / encounter_id`；新 session 取代舊 owner 時拒絕舊連線更新。
- **Domain idempotency**：`spawn_key`、`action_id`、`result_id`、`settlement_id`、`quest_turnin_id` 用於不同事件的唯一處理，絕不因 resend 雙生成、雙扣 HP、雙發獎勵。這些 key 名稱僅為 Server 實作提案。
- **獨立交易邊界**：Encounter settlement、QuestInfo14 turn-in、Quest16 解鎖、Quest16 完成／領獎、Tutorial exit 分開建模；不能以 `CTutorial 0x4C` 一次本地寫入冒充全部完成。
- **恢復策略須選擇**：中斷前的 encounter 是否重新生成、重進哪個 checkpoint、complete flag 保存於 account 還是 character，都待 Server ADR 明確決策；不能逆推為原版規則。

### 擬議測試清單（全部 PLANNED / NOT_RUN）

| 草案 ID | 測試目標 | 分層 |
| --- | --- | --- |
| I20-T01 | 0 角色 roster 及可用創角 UI；區分單純 record decoder | NATIVE_STATIC_REQUIRED |
| I20-T02 | 創角與選角是兩個不同 producer；拒絕把 0x42 當 create | NATIVE_STATIC_REQUIRED |
| I20-T03 | 登入跨 Conn stale session 不能污染當前角色 | SYNTHETIC_DOMAIN |
| I20-T04 | 選角結果與 scene key 沒有正向配對時不得宣稱入場 | NATIVE_STATIC_REQUIRED |
| I20-T05 | 相同 encounter/spawn key 重送不重複產生怪物 | SYNTHETIC_DOMAIN |
| I20-T06 | AI owner/fencing、死亡後移動與攻擊拒絕 | SYNTHETIC_DOMAIN |
| I20-T07 | 同角色同 encounter 普攻／技能 intent 與消耗、重送一致 | SYNTHETIC_DOMAIN |
| I20-T08 | 傷害／死亡／結果重送只結算一次 | SYNTHETIC_DOMAIN |
| I20-T09 | 無來源 objective 或未達條件，不得假勝利 | SYNTHETIC_DOMAIN |
| I20-T10 | Encounter settlement ≠ Quest14 ≠ Quest16 ≠ Quest15 unlock | SYNTHETIC_DOMAIN |
| I20-T11 | Crash-after-commit／relogin 不重發獎勵、不倒退 | SYNTHETIC_DOMAIN |
| I20-T12 | 真 KR Client 從 0 角色至教學後非教學區並重登 | ORIGINAL_CLIENT_E2E / NEEDS_EXPLICIT_AUTHORIZATION |

I20-Txx 是本文**局部規劃編號**，**尚未**建立 `conformance/test-index.json` 正式 TEST，也**沒有**測試執行紀錄或通過結果。即使未來 Server 合成測試 PASS，仍不能把原版 Client E2E 當成成功。

## 6. Iteration 21 建議執行順序與停止線

1. **先處理 E04→E05→E06**：確認零角色 UI 與 create command 是否能從既有研究閉合，先消除「已可登入但不能創角」的 blocker；如需派工，經 RR 去重後由 S00 發布。
2. **同步審 RR-0002／0008 的新證據**：從選角直到 tutorial first-visible-frame；無正向 source chain 仍 BLOCKED。不得拿無授權原 Client 測試繞過。
3. **再對 E17-B/F/G/H 開精確 proof checklist**：由對應 Task 交回來源、版本、關鍵 producer/consumer、正反例。先打通最小一組同場景戰鬥，不設定未證波次/技能表。
4. **最後串 E18–E26**：實作安全的 synthetic domain 策略建議與 native evidence 分線追蹤，Quest14、Quest16、Quest15 及離場/重登各自驗收。

**本輪停止線／不變更項**：沒有建立新正式 RR；沒有修改官方 `REQ/GAP/SPEC/TEST/CLM`、Task owner、FULL-PASS/REVIEW；沒有使用原 Client runtime、抓包或新 BIN 反編譯；沒有更新 `ttr_server_roy`；不能宣稱「已可完成新手教學」。

## 7. 來源與可重現檢查

- 主旅程：`S00-ITERATION-16-NEW-ACCOUNT-TO-TUTORIAL-GATES.json`、`S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json`；E17 細節 `S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json`。
- 確認範圍：`S00-20261031-ITERATION-19-END-TO-END-ACCEPTANCE.md`、`research/requests/index.json`、`design/requirements/index.json`、`design/gaps/index.json`、`spec/spec-index.json`、`conformance/test-index.json`。
- 完整 source **blob SHA** 與 37 列對照見同目錄 JSON；JSON 欄位 `source_evidence_state` 及 `existing_rr_dispatch_snapshot` 都是帶基準的歷史快照，查新 main 時以 canonical index 為準。
- 本次做了文件結構核對（27 主 Gate + 10 子 Gate、ID 唯一、Iteration 16 的 linked ID 全存在於所讀正式索引、所有計畫 gate 均未標 runtime test success）；**未在本輪執行 repository CI、T01 semantic validation 或原 Client E2E**。
