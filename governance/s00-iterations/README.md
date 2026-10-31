# S00 Iterations 14–22 — 原稿保存與交接

這個目錄保存 2026-10-30 原先在舊 ChatGPT 對話生成的 **完整草案** 與工作矩陣。已從使用者的檔案庫恢復原始 Markdown / JSON，並非由簡短對話摘要重寫。

## 文件與狀態

- Iteration 14：角色清單與 F42EF / 0x665150 Dialog 有界路徑；完整 Markdown。
- Iteration 15：角色資料與事件/UI 的未閉合連結；完整 Markdown 和 16 組 UI predicate JSON。
- Iteration 16：E00–E12，新帳號到第一個新手教學可操作畫面；完整 Markdown 和 13 個 gate / 16 個規劃測試情境。
- Iteration 17：E13–E26，Scenario 14、Quest 14/16、Quest 15 可接、退出教學及重登；完整 Markdown 和 14 個 gate / 25 個規劃測試情境。
- Iteration 18：在不更動 E00–E26 編號下，細化 E17 的怪物生成、AI 行動、角色普通攻擊、技能施放、傷害/死亡及勝負結算；完整 Markdown、10 個 E17 子閘門、20 個未執行的規劃測試情境 JSON 與 6 個候選研究題目（尚未建立正式 RR）。

Iterations 16–17 的正式流程編號合計 **E00–E26（27 個 gate）與 41 個規劃測試情境**；Iteration 18 的 10 個 E17 子閘門與 20 個規劃測試情境為額外細化草案，**不納入正式 E/TEST 台帳**，不是已執行或已通過的 Client 相容性測試。每份原稿內的「未上 Git」字樣保留為當時來源歷史描述；本目錄保存動作不代表將它們升格為正式穩定 SPEC。

## 研究證據限制

- Client BIN 部分已有 T03/T16 等原稿提供的限定靜態證據；這 4 輪沒有新增原生封包抓取或原版 Client 執行。
- 角色清單寫入、事件 producer/delivery、UI-ready、選角成功到 scene handoff 不能任意拼成已證 E2E。
- SceneList (1001,1)、Scenario 14、Quest 14、Event scene key 不能用相同數字推定共用 wire opcode。
- 教學結算、Quest 前置、持久化及場景轉換仍需按照 T07/T14/T15/T16 與相關研究逐項補證或作獨立 Server ADR。
- **不改動** research/requests/index.json、正式 REQ/GAP/SPEC/TEST 狀態、Task owner、其他 Task 原稿；**不新增正式 RR**。後續 RR 必須先去重，再以官方 dispatch/event 規則發布。
- **不改動** 獨立 ttr_server_roy 的開發實作；其原有契約 pin 如需升級，須另作設計審查與開發交接。

## 下次 S00 待辦

1. 對照最新 RR-0002、RR-0008 與 T03/T06/T07/T14/T15/T16 的既有研究，逐項去重創角、零角色 UI、教學完成與離場阻塞，再評估建立新的正式 RR。
2. 將 E00–E26 分段映射到目前正式 SPEC/GAP/TEST；只在已取得有界原生證據時更新相容契約，Server 專屬選擇使用 ADR。
3. 建立正式 E2E 測試規格，將 `planned`、`synthetic`、`native-static`、`runtime-verified` 分開；沒有授權不啟動原版 Client。
4. 以新帳號完成教學、退出至可操作非教學場景及重登進度一致作為產品交付目標，而不是以任一旗標更新當作完成。

**Git 基準**：原稿分析時 main @ dd69ec9de353a695d25c6db8e362ff471ea0c137；本次保留原稿原始基準，不假稱其與日後 main 完全等同。

## Iteration 19（2026-10-31，新規劃）

- [Iteration 19 — 新帳號至教學離場 E2E 整合與驗收](S00-20261031-ITERATION-19-END-TO-END-ACCEPTANCE.md)：在 Iteration 16–18 不變的 gate 基礎上，定義登入、創角、選角、教學戰鬥、Quest 結算、離場及重登的跨模組因果與四層驗收；列出 I19-P1～P4 和 I19-T01～T12（全部 PLANNED / NOT_RUN）。
- Iteration 19 是**新增規劃**，未將原有 E00–E26、E17-A～J 或正式 REQ/RR/SPEC/GAP/TEST 變更、升級；無原版 Client 測試與 Server 程式變更。

## Iteration 20（2026-10-31，逐 Gate 證據盤點與去重）

- [Iteration 20 詳細規劃](S00-20261031-ITERATION-20-GATE-TRIAGE-AND-RR-DEDUP.md)：依 Iteration 19 的下一輪建議，依序處理登入/空角色 UI、創角、選角進教學、E17 戰鬥、Quest 結算及教學離場/重登。對現有 8 個 RR 去重、建立新證據最小交付表與 I20-T01～T12 **未執行**的測試草案。
- [Iteration 20 全量機讀盤點](S00-ITERATION-20-GATE-EVIDENCE-TRACE.json)：E00–E26 **27 主 gate**、E17-A–J **10 子 gate**，逐列保存既有規劃狀態、owners、未解證據與 Iteration 16 草案引用的正式 ID，並附用來檢視的當時各索引 blob SHA／RR dispatch 快照。
- 仍只有正式 RR-0001..0008：RR-0002 BLOCKED、RR-0005 研究範圍 ACCEPTED、其他 IN_REVIEW（快照，不應代替重讀唯一 RR 索引）。**沒有**本輪新正式 RR/REQ/GAP/SPEC/TEST、原 Client 動態測試、Server 開發或規格升級；建議先審核既有 Txx 結果後再決定要不要發新的狹義 RR。

## Iteration 21（2026-10-31，正式 E05／E06 派工）

- [Iteration 21 詳細分析與正式派工](S00-20261031-ITERATION-21-CREATE-UI-WIRE-DISPATCH.md)：從 Iteration20 Gate Trace 的 E04→E05→E06 開始；在對照既有 RR-0002（選角，BLOCKED）、RR-0007（入站 dispatcher）、RR-0008（選角→場景）後，**新增** `GAP-CHAR-0002/0003` 與 `RR-0009`（零角色／創角 UI 正向入口）、`RR-0010`（真正創角 C2S/S2C 正向交易）。
- 兩個研究請求均 **P0 / QUEUED / 未認領**，T03 主責、T06 資源與 T04 欄位為定向協查。T03 生成收件箱已更新，唯一正式 RR 台帳從 8 增至 10；既有 8 個 RR 不變。
- `SPEC-CHAR-0001`／`SPEC-FLOW-0001` 仍 DRAFT/PARTIAL，僅加明確 blocker，不新增 Client 封包、Server 跨任務實作、原 Client runtime 或任何 FULL-PASS／SPEC STABLE。Git 合併不自動喚醒其他 Agent。

## Iteration 22（2026-10-31，WEB 玩家帳號後台第一版）

- [Iteration 22 正式管理員需求與實作交接](S00-20261031-ITERATION-22-ADMIN-WEB-V1.md)；[WEB Admin V1 功能設計](../../design/admin-web/ADMIN-WEB-V1-PLAN.md)；[25 項未執行驗收草案](../../design/admin-web/ADMIN-WEB-V1-ACCEPTANCE.md)。
- REQ-0006 管理員權限稽核、REQ-0007 新增玩家帳號、REQ-0008 停權 N 天／永久／解封，以**真實** `PLAYER_ADMIN_REQUEST` 去敏登錄；不污染原有 CODE_ANALYSIS 需求。
- ADR-0004/0005 提供 Server-only 安全、停權與 Session 整合提案，全部 **PROPOSED**。此輪沒有修改 `ttr_server_roy`、沒有新 Client RR/GAP/SPEC/TEST/CLM，亦沒有部署 WEB 或測試執行。


## RR-0010 extra/roy1 合併來源有界複核（2026-10-31）

- [S00 逐條驗證與 Server 交接](S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md)：在 [PR #63](https://github.com/we88ec3-prog/ttr_anal_multi/pull/63) 合併 E71–E75 研究後，核對 Git blobs、E73/E74 的 Client 建名 sender/result/shared-name、和已保存同版 Ghidra 偽碼；本環境沒有原始 KR BIN，不宣稱親自重跑作者 58/81 項 source-byte checker。
- [SPEC-CHAR](../../spec/session-account/SPEC-CHAR-0001.md)、[SPEC-FLOW](../../spec/session-account/SPEC-FLOW-0001.md) 及 `GAP-CHAR-0003` 只新增「有界證據／未知」註記，`RR-0010=BLOCKED`、`GAP-CHAR-0003=OPEN`、SPEC `DRAFT/PARTIAL`；**無原版 Server 0x3E↔0x4A 配對、角色建立→roster 因果，沒有新增 accepted claim/full pass**。E75 屬 RR-0002 的相鄰補證，不能冒稱 RR-0010 閉合。


## Iteration 23（2026-10-31，extra/roy1 E76–E79 研究整合與新手前段交接）

- [Iteration 23 — 遠征隊建名、角色 Full/Delta 同址、UI gate 與 Server 分階段計畫](S00-20261031-ITERATION-23-EXPEDITION-ROSTER-PLAN.md)。本輪 [PR #65](https://github.com/we88ec3-prog/ttr_anal_multi/pull/65) 合併 E76～E79 八個新研究檔案；E79 更正 E72「不同角色 record destination」，證明 S2C app2（65+53N）與 app2B（2+53N）寫入相同 `F94304` pointer cell；E76 有 name ready flag/UI gate；E77 有條件 S2C B6→F4278→角色記錄 UI。
- [Iteration 23 — 24 項規劃測試](S00-20261031-ITERATION-23-ACCEPTANCE.md)：DOMAIN / STATIC / NEGATIVE / E2E 等級與原版 Client gate 明確分離，全部 `PLAN_ONLY / NOT_RUN`。另更新 `SPEC-CHAR-0001`／`SPEC-FLOW-0001`、`GAP-CHAR-0003`、`SLICE-CREATE` 的 RR9/RR10及 GAP 對照。
- **未改**正式 REQ/RR/CLM 或原生 TEST index；無 T01 正式新增 CLM（所以不以舊 CLM 假裝 E79 已正式來源驗收）。`RR-0010 BLOCKED`、`GAP-CHAR-0003 OPEN`、SPEC `DRAFT/PARTIAL`；原件 BIN 未在本次環境重跑。完整 Server 可開始做 **ExpeditionProfile/FullRoster+Delta 單一模型與合成測試**，但 Client native adapter 必須等待 T02/T03/T04 條件。


## Iteration 24（2026-10-31，E80 選角／Square 串接新手流程）

- [Iteration 24 — RR-0010 斷點不變、E80 選角與 Square 開發交接](S00-20261031-ITERATION-24-SELECTION-SQUARE-HANDOFF.md)：新增 E80 RR-0002 正向 Client 靜態研究（經 PR #67 合併），C2S42 4B roleIndex+mode、ExpeditionScene 選角 UI gate 與 pending flag 可能未送出、候選 S2C69 subtype7→CSquare→C2S43 的不同 owner 來源；非 original Server 42→69 ACK，不能拿選角完成補 RR-0010 建角因果。
- [Iteration 24 — 20 項規劃測試](S00-20261031-ITERATION-24-ACCEPTANCE.md)：DOMAIN/NEGATIVE/STATIC/E2E 全部 PLAN_ONLY/NOT_RUN，延伸 Iteration23 的 ExpeditionProfile/Full+DeltaRoleStore 至 SelectionAttempt/SceneBootstrap/WorldReady，原 Client/Server 實測另須授權。
- 更新 DRAFT SPEC-CHAR/FLOW、GAP-CHAR-0001/0003、SLICE-ENTER-WORLD 與 B-CHAR/B-SCENE roadmap；正式 REQ/RR/CLM/TEST 索引不新增或升級。RR-0002、RR-0010 保持 BLOCKED，相關 GAP OPEN，無 T01 FULL-PASS 或新 Server 實作。


## Iteration 25（2026-10-31）：首次教學入場及復原 Server domain

- [Iteration25 — 教學首次入場、Progress/Session lease、Scenario/Quest/Reward、離場重登的完整交接](S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md)：承接 Iteration23 Account/Expedition/Role、Iteration24 SelectionAttempt/Square 候選；把 E10–E26 的進度與 Client 場景可操作證據分層。**沒有原版 Client 遊玩、沒有完整官方 Client↔Server 因果鏈**。
- [Iteration25 — I25-T01～T16 計畫測試](S00-20261031-ITERATION-25-ACCEPTANCE.md)：16 項全部 PLAN_ONLY/NOT_RUN，重點在 per-role State、SessionEpoch fencing、outbox/reward idempotency、ban/unban、scene/Conn/Quest 誤判反例。沒有註冊正式 native TEST。
- [ADR-0006](../../design/decisions/ADR-0006-tutorial-progress-and-session-fencing.md) 正式列入 ADR 台帳，狀態 PROPOSED、非規範；路線圖增列與 Client 研究可並行但**需維護者批准後才能作正式業務政策**的 C-TUTORIAL-DOMAIN。維持 RR-0002/0010 BLOCKED、RR-0008 IN_REVIEW（當時 main）、SPEC-FLOW/SCENE DRAFT/PARTIAL，native adapters OFF。


## Iteration 26（2026-10-31）— 教學戰鬥到任務結算及退出的 source-pinned 工作矩陣

- [Iteration26 完整 Server 規劃與研究交接](S00-20261031-ITERATION-26-COMBAT-QUEST-EXIT-PLAN.md)：接續 Iteration25，處理 E17-A～J 戰鬥子 gate、E18–E26 Scenario14→Quest14/16→Quest15可用→教學 terminal→離場/重登，分成 Encounter、ScenarioSettlement、QuestProgress、RewardLedger、TutorialProgress、WorldExit 五個獨立權威。
- [Iteration26 19-gate JSON matrix](S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json)：逐 gate 保存原始 Iteration17/18 evidence_state、blocking_unknown、source Git blob、research owner、native missing proof、Server 端 proposed domain；非正式 RR/GAP/TEST 台帳或官方 Server 時序。
- [18 項 I26-T01～T18 未執行測試](S00-20261031-ITERATION-26-ACCEPTANCE.md)：DOMAIN/NEGATIVE/CONCURRENCY/RECOVERY/STATIC/E2E，全部 PLAN_ONLY/NOT_RUN。CI 以 `python -B governance/check_s00_iteration26.py --check` 和 13 項回歸測試保護原始 source evidence level 不被假升格。
- [ADR-0007](../../design/decisions/ADR-0007-encounter-quest-settlement-boundaries.md) PROPOSED/NON-NORMATIVE，保持既有 7 個 roadmap 工作包，不動研究 RR/CLM/REQ/TEST、Task owner 或獨立 Server 實作庫；原版 Client 未執行。


## Iteration 27（2026-10-31）：以真實 Server C03/C04 基線規劃 C05 可接手任務

- [Iteration27 完整開發交接](S00-20261031-ITERATION-27-C05-DELIVERY-PLAN.md)：比對 `ttr_server_roy main=c17a986fc66caca8af0efb72e2b42d1188e2a584` 的 C03-C `IAtomicCharacterActions`／`ISessionLeaseRegistry`、本地 SQLite 與獨立 PostgreSQL migrations、C04-A/B/C bounded offline 實際進度，避免重做既有交易、錯當 C05 已開發。
- [9 個 S27-W01～W09 工作包機讀矩陣](S00-ITERATION-27-C05-DELIVERY-MATRIX.json)：八個 `DOMAIN_OFFLINE_PROTOTYPE` 與一個 `SOURCE_GATED_NO_IMPLEMENTATION` 原 Client adapter；記錄上游 Iteration26 來源 Git blob SHA 與 5 個已核對 Server Git blob。CI 本身**不會連線自動重新驗證遠端 Server 庫**，Server snapshot 只是這一輪的固定基準。
- [I27-T01～T18（18 項）未執行驗收草案](S00-20261031-ITERATION-27-C05-ACCEPTANCE.md)：角色/Session ownership、Encounter/Actor/AI/Skill/Scenario 結算、Quest/Reward/Outbox、退出重登、原生 no-go；全部 `PLAN_ONLY / NOT_RUN`，不是正式 conformance TEST。
- [read-only checker](../check_s00_iteration27.py) 及 15 項單元回歸測試護欄接入 GitHub CI；**不新增重複正式 RR/REQ/CLM/TEST、不可核准 ADR-0006/0007、不修改獨立 Server 程式庫或 spec pin**。C-TUTORIAL-DOMAIN 仍 Phase C / EXTERNAL_REVIEW_REQUIRED。


## Iteration 28（2026-10-31）：C05 W01～W03 原子選角、Encounter、Actor／AI 實作準備

- [完整開發契約與下游 3 個 Server PR 切片](S00-20261031-ITERATION-28-W01-W03-IMPLEMENTATION-PLAN.md)：依真實 C03-C `IAtomicCharacterActions`、`SessionLease` 和 PostgreSQL `selected_revision`／SQLite local v1 的已存在程式，指出**先 GetSelectedAsync 再跨交易寫 Encounter** 之 TOCTOU，要求在 Encounter 交易內重新核對 exact lease/owned selected role。
- [S28-01～03 機讀契約](S00-ITERATION-28-C05-W01-W03-CONTRACT.json)：完整來源 Git blob anchor（Iteration27 和獨立 Server 八個實際檔案）、SQLite/PostgreSQL 各自待核准 migration、reserved/active/terminal state、Session fencing、deterministic mock actors/AI tick。此檔**不代表 Server 已實作**。
- [16 個 I28-T01～T16 未執行驗收案例](S00-20261031-ITERATION-28-W01-W03-ACCEPTANCE.md)：競態、斷線、新舊 Session、同請求去重、崩潰恢復、Actor tick/AI/movement 原型；全部 `PLAN_ONLY / NOT_RUN`，不等於原 Client 可玩。
- GitHub CI 新增 `governance/check_s00_iteration28.py --check` 與 **16 項回歸測試**，只保護規劃及證據等級，不讀遠端 Server 最新 main、不升格 ADR-0006/7、RR/REQ/GAP/SPEC/TEST，也不修改 `ttr_server_roy`。


## Iteration 29（2026-10-31）：W04 攻擊、技能、冷卻、傷害與死亡

- [Iteration29 詳細 Server mock-domain 實作規劃](S00-20261031-ITERATION-29-COMBAT-IMPLEMENTATION-PLAN.md)：接續 Iteration28 的原子授權/Encounter/Actor 方案，將普通攻擊、技能預留及取消、命中傷害/死亡、斷線/崩潰恢復分四個工程 PR 切片；不把本地 Client 動畫或受限 consumer 當 Server 官方規則。
- [S29-01～04 機讀契約](S00-ITERATION-29-C05-COMBAT-CONTRACT.json)：pin Iteration28/27/18/26 的 Git blob 和原 E17-E/F/G `evidence_state/blocking_unknown/owners`；真實 Server `main=9caffb75c374147b71dea51227b5c4f13b33071d` 的 8 個來源 blob 只為本輪觀察快照，**CI 不會重新讀遠端 Server**。最新 C02-D 已令 local SQLite 升至 v2；對照 Iteration28 v1 時應以各時點歷史快照為準。
- [24 個 I29-T01～T24 驗收草案](S00-20261031-ITERATION-29-COMBAT-ACCEPTANCE.md)：全為 `PLAN_ONLY/NOT_RUN`，並非正式 conformance TEST；規劃 CI 以 `python -B governance/check_s00_iteration29.py --check` 和 **18 項回歸測試**保護未經證據的戰鬥成功/Client 兼容宣稱。
- ADR-0006/0007 仍 **PROPOSED**，尚未修改獨立 Server 的 C05 程式或 migration，也未核准 KR/TC native adapter；攻擊/技能/傷害的原版 Client 研究仍由 E17-E/F/G 既有 Txx 所有者補證。


## Iteration 30（2026-10-31）：S27-W05 Scenario14 勝負、波次、唯一結算與 Quest14 交界

- [Iteration30 完整設計／下游 Server PR 切片](S00-20261031-ITERATION-30-OBJECTIVE-SETTLEMENT-PLAN.md)：把 verified ActorDeath、波次/Objective、terminal CAS、Outbox→Quest14 eligibility 分為四個**新 Server mock-only 提案**，不把 Client 局部 `0x004C` map flag 或 timer 當原生勝利證據。
- [S30-01～04 JSON 契約](S00-ITERATION-30-OBJECTIVE-SETTLEMENT-CONTRACT.json)：pin Iteration29/27/18/17/26 五份來源 Git blob，保存 E17-G/H/I/J 與 E18/19/20 七個原 evidence/owner/blocker；最新 Server `272079cc` 的 C00-OPS 離線 SQLite 維運檔只是快照，當時該提交 CI 尚在執行，不能誤宣稱 C05 已完成或 CI pass。
- [I30-T01～T24 驗收計畫](S00-20261031-ITERATION-30-ACCEPTANCE.md)：24 個皆 `PLAN_ONLY/NOT_RUN`，並非正式 conformance TEST。新 CI 執行 `python -B governance/check_s00_iteration30.py --check` 與 18 個 regression；只驗本庫規劃/來源未被誤升格，不做獨立 Server 或原版 Client 測試。
- 接續 Iteration29 W04，後續可規劃 Iteration31 W06/W07 Quest14/16/15 及 RewardLedger；ADR-0006/7 仍 PROPOSED，`SPEC-FLOW/SCENE` 仍 DRAFT/PARTIAL，Native adapter OFF。


## Iteration 31（2026-10-31）：Quest14→16→15 及唯一獎勵帳本

- [Iteration31 完整 Server 設計交接](S00-20261031-ITERATION-31-QUEST-REWARD-PLAN.md)：從 Iteration30 ScenarioTerminal 的 durable proof 才進 Quest14 eligibility／交付，再以獨立 NPC/mock policy 進 Quest16，Reward type2/value50 語意未證時**絕不入帳**，Quest15 AVAILABLE 不等於 accepted 或 WorldReady。
- [S31-01～04 機讀契約](S00-ITERATION-31-QUEST-REWARD-CONTRACT.json)：固定 Iteration30/27/17/26 來源 Git blob、E20-E24/E26 原始 gate 的 evidence/owner/blocker、8 個真 Server 來源 blob；最新 Server C00-OPS/C02-D/C03 尚無 C05 Quest/Reward code。Server 快照僅為本輪 GitHub 唯讀觀察，不在 S00 CI 自動再次驗證。
- [24 個 I31-T01～24 驗收草案](S00-20261031-ITERATION-31-ACCEPTANCE.md)：全部 `PLAN_ONLY / NOT_RUN`；新規劃 CI 執行 `governance/check_s00_iteration31.py --check` 與 **18 項回歸測試**，不執行任何 .NET/原版 KR Client。
- **新的整合要求**：Iterations28～30 各自提過 SQLite 候選 v3／PG004；Iteration31 不會再重複佔用這些版本，要求 Server maintainer 統一配置 C05 全模組 migration 序列，當前一切下一版號 `UNALLOCATED_NOT_APPLIED`。ADR-0006/0007 仍 PROPOSED，Native adapter OFF。


## Iteration 32（2026-10-31）：教學終局、出場、WorldReady 與重登恢復

- [Iteration32 完整工程交接](S00-20261031-ITERATION-32-TUTORIAL-EXIT-RELOG-PLAN.md)：延續 Iteration31 的 Quest/RewardLedger，分別審核角色教學終局資格、SceneExitAdmission、Mock world state、真實 Client scene/control 觀測及重登後復原，**不能把 Quest15 AVAILABLE 或出場寫入成功當作原 Client 已可玩**。
- [S32-01～04 JSON 契約](S00-ITERATION-32-TUTORIAL-EXIT-RELOG-CONTRACT.json)：固定 Iteration31/27/17/18/26 五份來源 Git blob，E23/E24/E25/E26/E17-J 原 evidence/owner/blocker，與獨立 Server 八個 source blob；不在 S00 CI 重新驗遠端 Server。
- [I32-T01～24 驗收草案](S00-20261031-ITERATION-32-ACCEPTANCE.md)：全部 `PLAN_ONLY / NOT_RUN`；增加 `governance/check_s00_iteration32.py --check` 和 **18 項規劃回歸測試**，不執行任何新 C05/.NET 或原版 Client。
- 對應下游 Server C05-P16～P19 提案；SQLite local v2／PostgreSQL 003，後續 migration 仍 `UNALLOCATED_NOT_APPLIED`、需統一 C05 序列，ADR-0006/7 PROPOSED，Native adapter S27-W09 維持 OFF。


## Iteration 33（2026-10-31）：C05-P01～P19 統一開發 DAG／migration／policy／native gate

- [Iteration33 完整整合規劃](S00-20261031-ITERATION-33-C05-INTEGRATED-DELIVERY-PLAN.md)：把 Iterations28～32 的 19 個 mock Server 工程切片接成具正確前置依賴的 **C05-P01～P19**，R0 policy/source/migration、R1 Encounter、R2 Combat、R3 Scenario、R4 Quest/Reward、R5 TutorialExit，以及獨立 R6 原版 Client native gate。**此 19 個編號只是候選 Server PR，尚未在 Server repo 實作。**
- [S33 機讀 19-PR DAG](S00-ITERATION-33-C05-INTEGRATION-CONTRACT.json)：來源 Git blob pin Iterations27～32 六份契約及 E17-A/J/E23～E26 兩份 native gate、八份 Server 實際來源 blob，保存八個產品/DB/Native 決策清單；Server CI 僅為既存離線測試，不能當 original Client 相容性。
- [24 個 I33-T01～T24 整合驗收](S00-20261031-ITERATION-33-ACCEPTANCE.md)：全部 `PLAN_ONLY/NOT_RUN`，加上 `python -B governance/check_s00_iteration33.py --check` 和 **18 個反升格回歸測試**。
- 中央 C05 migration manifest 需由 Server owner 配號：SQLite local v2、PostgreSQL 003 已觀察，下一版均 `UNALLOCATED_NOT_APPLIED`，不可將 Iterations28～30 各自提過的候選 v3/004 直接套入不同 C05 模組。ADR-0006/0007 仍 PROPOSED，原 Client adapter OFF。


## Iteration 34（2026-10-31）：真實 Server 21-commit Delta 收件與 C05 R0/P01 預檢

- [Iteration34 完整 R0/P01 交付與 WEB Admin 回饋分類](S00-20261031-ITERATION-34-C05-R0-SERVER-DELTA-PREFLIGHT.md)：在 Iteration33 後，實際核對獨立 `ttr_server_roy` `272079cc→3e0b7e3` 的 21 個新提交／14 個變更檔案、最新四個 CI SUCCESS（均為原本離線／source-scoped 範圍）；確認新增 SQLite v2 本機 WEB Admin，但非 PostgreSQL／可配置遠端 IP，且 C05 仍未實作、`implemented_wire_contracts=[]`。
- [S34 機讀差異與前置契約](S00-ITERATION-34-C05-R0-SERVER-DELTA-CONTRACT.json)：鎖定原 Iteration33 source blobs 和真 Server 7 個 Git blob、8 項 R0 未完成 gate、C05-P01 的單交易 Admission 及無 Native wire 的 domain 建議。**是一次快照，CI 不會 live 重新驗遠端 Server**。
- [I34-T01～16 驗收草案](S00-20261031-ITERATION-34-ACCEPTANCE.md)：全部 `PLAN_ONLY/NOT_RUN`，新增 `python -B governance/check_s00_iteration34.py --check`、20 項 regression；它們只檢查本庫文件與證據身分，**不執行 Server .NET 或原版 Client**。
- 不重開同義 REQ／RR，不推進 ADR-0004/5/6/7、正式 SPEC/GAP/CLM/TEST，亦不覆寫獨立 Server 庫。下一輪需 Server 真正提交 R0 policy/migration allocator 或 C05-P01 的實作／測試收據；不能再只畫同一份 19 PR DAG。


## Iteration 35（2026-10-31）：C05 R0／P01 證據收件 CLI 與 fail-closed gate

- [Iteration35 完整規範](S00-20261031-ITERATION-35-R0-P01-EVIDENCE-INTAKE-PLAN.md)：對照 Iteration34 和獨立 Server main `3e0b7e3`，確認沒有新的 C05-P01 code/政策/migration 實際交付；因此不重畫第三份 C05-P01～P19 DAG，而建立真正可使用的開發成果收件與拒收工具。
- [五槽空收件狀態](S00-ITERATION-35-C05-EVIDENCE-INTAKE.json)：R0 policy／SQLite+PG migration／P01 SQLite+PG 均 `NO_RECEIPT`；D33-01～08 尚未核准、12 個 I35-T01～T12 下游驗收全 `PLAN_ONLY/NOT_RUN`；原版 Client/native adapter OFF。
- `python -B governance/check_s00_iteration35.py --check` 只驗源 Git blob、空收件狀態、未批准邊界。新 `--candidate receipt.json` 可對未來真 Server PR/CI/政策簽核的證據形狀做**離線**拒收，格式通過只輸出 `STRUCTURALLY_REVIEWABLE_NOT_APPROVED`，還要人員遠端重新核對 SHA、Actions、schema、trace 與批准。
- [22 項檢查器單元測試](../tests/test_s00_iteration35.py) 涵蓋假 SHA、CI head 不符、path traversal、Migration 重複版本、無備份還原、錯誤 provider、P01 少同交易/租約/重試負例、假政策批准及 Native 偽升格。這是測試驗證器，不是執行任何 I35-Txx Server 測試。
- 不新增正式 RR/REQ/GAP/CLM/SPEC/TEST/ADR，不動 `ttr_server_roy` 或原版 Client；下一階段只在有實際 R0 設計核准／migration 或 C05-P01 Server PR 附 CI 收據時繼續實質審核。
