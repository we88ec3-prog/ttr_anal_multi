# S00 新對話接續 — Server 規格、REQ 需求來源與角色畫面階段

**每次換對話可提供此檔，並貼下面指令。** 這是交接快照和工作規則，**不是「最新 main」的替代品**；請先查 GitHub main 與其 CI 再採用新資料。最後整理日期：2026-10-30。

## 新對話可直接貼的指令

> 請接續 GitHub `we88ec3-prog/ttr_anal_multi` 的 **S00 Server 規格與需求整合**。先閱讀 `governance/S00-NEXT-CHAT.md`、`governance/s00-workflow.md`、`governance/S00-20261030-ITERATION-11.md`、`design/requirements/README.md` 及 `governance/S00-LOBBY-CREATE-RESEARCH-QUESTIONS.md`，核對**當時最新 main SHA** 與 `research/requests/index.json`、`design/requirements/index.json`、`design/gaps/index.json`、`spec/spec-index.json`，再看 `governance/s00-requirement-slices.json` 和 `governance/server_requirement_slices.py` 的阻塞清單。以 **SLICE-LOBBY：登入→選服→角色清單→角色 UI** 優先，之後才是 **SLICE-CREATE：創角**，**SLICE-ENTER-WORLD：選角後進世界** 是另一門檻。每次研究優先用現有 RR、CLM、SPEC、GAP，不重做已證 native；把程式碼發現、獲授權遊戲運行、玩家/管理員需求歸入**同一個 REQ 台帳的三種 discovery**。任何 SOURCE_ONLY/PARTIAL 不自動成 T01 FULL-PASS、RR ACCEPTED、SPEC STABLE。保留完整 Markdown 證據和未知，對話只回報關鍵結果。**只有我明確說「上 Git／Push」時才 Commit／Push。** 只允許離線讀取原始遊戲，不執行／附加／連線原版 Client，除非我另行授權。請從最新 main 的真實狀態繼續 S00 分析／規劃，不要重提已回答的分工問題。

## 資料權威與工作範圍

| 資料 | 唯一權威 | S00 使用方式 |
| --- | --- | --- |
| Server 需求 | `design/requirements/index.json`， `REQ-*` | 3 種來源可單獨發現需求，也可在同 REQ 下累積 discovery；status 不自動核准 |
| 原生研究派工/結果 | `research/requests/index.json`，`RR-*` | 由原 Txx 擁有研究；IN_REVIEW 不等於 ACCEPTED |
| Client/Spec 阻塞 | `design/gaps/index.json` | 未證時 OPEN；禁止僅因 RR 研究交件就改 RESOLVED |
| Server 可實作契約 | `spec/spec-index.json` + 各 SPEC 原稿 | 必須受 Client SHA、來源、方向、byte 前提與驗證等級約束 |
| 原生證據 | `research/claims/index.json` + SRC/T01 review | 來源 blob 和限定範圍；不能假稱新 T01 BIN 複驗 |
| 後端方案 | `design/decisions/index.json` | ADR 批准前都只是非規範提案，不能當原版 Server 行為 |
| 執行測試 | `conformance/test-index.json` | OFFLINE_SYNTHETIC 只證工具內部一致性；runtime 要另行授權 |
| 交付階段 | `governance/s00-requirement-slices.json` + `governance/s00-roadmap.json` | 前者是 REQ 需求優先順序**規劃 overlay**；後者是既有正式 roadmap，不互相取代 |

## 確認過的歷史狀態（**僅供比較；每次重讀 main**）

- 基準 KR 原件 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；不得將 KR 位址/封包套到 TC。
- 在 2026-10-30 的上一輪，REQ-0001..0005 皆為 CODE_ANALYSIS/CANDIDATE；無人造玩家/管理者需求、也沒有真 Client 運行。
- RR-0001、0003、0004、0006、0007、0008 為 IN_REVIEW；RR-0002 BLOCKED；RR-0005 ACCEPTED 僅限有界靜態研究。原稿需按 T01 S00 review 分別驗收。
- 最後先前合併的 PR #50（RR3 LOGIN）與 #51（RR6/7 transport/dispatcher）及 Iteration 10 已整理證據、6 個 OFFLINE_SYNTHETIC TEST；7 SPEC DRAFT/PARTIAL、7 GAP OPEN。不要以測試數增加宣稱 Client 可以玩。
- 第三來源（玩家/管理者）包含操作安全、備份、稽核及歷史資料附件；並**無**第五種歷史協定來源。第四個候選 `SERVER_IMPLEMENTATION_FEEDBACK` 尚未核准，既有問題走 FB。

## 下一輪必做（依當時 RR 狀態調整）

1. 執行 `python -B governance/server_requirement_slices.py --check`、`python -B governance/server_requirement_slices.py --format markdown`、`python -B governance/check_s00_readiness.py --check`，確認真實 blocker，**不另建雙重 RR/REQ/SRQ 索引**。
2. 先核對 T03 關於 **0x0002 roster→0x4D4150→UI dialog／F4246/47/條件式 F4278** 的新證據與 T06 UI 資源。先把登入到角色畫面可驗的條件拆出來，不要求先完成選角後世界轉場。
3. 再找 **創角入口／建立角色 request-reply** 的正向 Client native evidence；無來源先標 `SLICE-CREATE=DISCOVERY_REQUIRED`，不猜 C2S opcode。
4. 如有真研究提交，與 T01 共同核對 bounded report SHA/原生 scope，更新有關 SPEC/REQ 的有限敘述；RR/SPEC/GAP/TEST 各自獨立審核。
5. 運行原版 Client、抓包、對官方 Server 連線或改 Server 實作庫均需要另行明確授權；不使用外部 GitHub Issues 接受其他開發者問題。

## 維護方式

交接文件是**一份** S00 共同交接入口；新增本次工作的已驗證狀態可精簡更新本檔，詳細原稿、來源 SHA 和未解問題留在各 Iteration/Task 文件，不把所有研究原稿複製進交接。

後續對話若明確要求 GitHub Commit/Push，請建獨立工作分支，驗證並開 PR；合併 main 後核對 GitHub Actions main CI，回報實際 PR/commit。若**沒要求推送**，只交付工作檔/完整文字，不偷偷改 main。


## Iteration 12／13 — 登入至角色畫面逐項交付（2026-10-30）

前次未提交的 Iteration 12 草案現在以 [完整規劃](S00-20261030-ITERATION-12.md) 與 [12 個尚未執行的設計測試](s00-iteration12-lobby-test-plan.json) 整合進 main；接續 [Iteration 13 工作優先順序](S00-20261030-ITERATION-13.md)、[9 個 L00–L08 檢查點](s00-lobby-gates.json) 和 [唯讀檢查器](check_s00_lobby_gates.py)。新對話**先看當時最新 main**，跑 `python -B governance/check_s00_lobby_gates.py --check` 及 `--json`。此矩陣目前全部 BLOCKED，是因為正式 REQ/RR/GAP/SPEC 和原版實測仍不足，不是 CI 錯誤。優先 **P13-1：T03 roster→UI event/dialog（T06 只負責同版本資源協查）**；再做 **P13-2：T02/T03 登入/選服/跨 conn 的方向別前提**；再 **P13-3：T03/T04/T06 創角的真正 C2S/S2C positive evidence**。本節是追加交接快照，不更動前面的 Git 提交授權、原版 Client 禁止執行及唯一 REQ/RR 台帳規則。

## Iteration 20 — 全旅程逐 Gate 去重與研究候選（2026-10-31）

本次接續 [Iteration 19 的整合驗收計畫](s00-iterations/S00-20261031-ITERATION-19-END-TO-END-ACCEPTANCE.md)，新增 [Iteration 20 完整分析](s00-iterations/S00-20261031-ITERATION-20-GATE-TRIAGE-AND-RR-DEDUP.md) 與 [37 Gate source-linked 快照](s00-iterations/S00-ITERATION-20-GATE-EVIDENCE-TRACE.json)。新對話請先核對**當時最新** main 和唯一權威索引，而非延用文件內的快照狀態：

1. **P0**：E04 空角色清單 → E05 創角 UI → E06 C2S/S2C Create 真正 producer/consumer（不能把 selection `0x42` 當 creation）；核對 T03/T04/T06，與 RR-0002/0007 去重後才可能建立新 RR。
2. **P0**：E08–E12 selection → scene → tutorial first interaction；RR-0002 仍受原版 Server 正向 success/error pairing 限制，RR-0008 已有範圍，不重複要求相同研究。
3. **P1**：E17-B/F/G/H 的 monster spawn、技能施放、傷害/死亡、勝負目標需要同一 scene/instance 的 bounded native 因果證據；迭代 18 的 CR18-01..06 是候選，尚非正式 RR。
4. **P1**：E18–E26 將 Scenario14 settlement、QuestInfo14、Quest16、Quest15 可接、教學離場和重登持久化分開驗收。Server 自訂冪等／fencing 如要採用先經 ADR，不能寫成原版 protocol。

Iteration 20 沒有修改正式台帳、原 Client/BIN 或 Server 程式。JSON `linked_existing_*_ids_from_plan` 是 **Iteration 16 規劃的引用**，絕非新增的精確 native proof；新提案需沿用現有 S00/RR 註冊與 T01 review 流程。I20-T01..T12 尚未執行、未註冊正式 TEST，Original Client E2E 仍需要另外明確授權。

## Iteration 21 — 創角原生缺口已正式派工（2026-10-31）

[Iteration 21 完整派工與反證規則](s00-iterations/S00-20261031-ITERATION-21-CREATE-UI-WIRE-DISPATCH.md)。當次在 main `4ab3ce9a8a635d0b6862d6b552bf0b1098097b88` 基礎上做有限範圍去重，正式發布時請以**最新** `research/requests/index.json` 取代快照。

- **新 RR-0009／GAP-CHAR-0002，P0 QUEUED**：T03 主責，T06 僅資源協查；E05 零角色或「新增」控制到真正 Create dialog 的 **Client local UI** 正向路徑。禁止把 65+53N、F42EF 或 0x665150 當 UI-ready。
- **新 RR-0010／GAP-CHAR-0003，P0 QUEUED**：T03 主責，T04/T02 提供初始欄位/transport 介面；E06 真正 create C2S producer → S2C result consumer → roster/init。**選角 C2S 0x42 不是創角**，未知官方 Server pairing 仍 UNKNOWN。
- 已更新 `spec/spec-index.json` 與 SPEC-CHAR/FLOW DRAFT 內的未解阻塞；研究者須先確認 T03 T01 NEEDS_FIX，再按使用者明確優先與 `research/dispatch/inbox/T03.md` 依法認領。**GitHub 合併不是 Agent 已開始研究**。
- E08–E12 持續受 RR-0002 BLOCKED、RR-0008 IN_REVIEW 制約；E17 戰鬥證據以及 E18–E26 任務/離場尚未閉合。沒有新原生 BIN 研究或 Client runtime 授權，沒有更新 ttr_server_roy。

下一次 S00 請先審這兩個 RR 是否被認領／交件，再判斷 E07 應否獨立開研究；不應直接再重複建立同義 Create RR。

## Iteration 22 — WEB 管理後台正式需求（2026-10-31）

本次使用者**首次實際提出管理員需求**：「WEB端後台，新增玩家帳號／停權 N 天／永久／解封」。已將去敏來源保存在 [使用者需求登記](../design/requirements/requests/2026-10-31-admin-web-account-operations.md)、唯一 REQ 台帳新增 `REQ-0006..0008` **CANDIDATE**；[Iteration 22 導航](s00-iterations/S00-20261031-ITERATION-22-ADMIN-WEB-V1.md)、[Admin WEB V1 功能設計](../design/admin-web/ADMIN-WEB-V1-PLAN.md)、[30 個計畫測試](../design/admin-web/ADMIN-WEB-V1-ACCEPTANCE.md)。

本輪只設計，未部署、未開管理網路端口或修改 Server repo；`ADR-0004/0005` **PROPOSED**。新對話先核對最新 main、REQ 與 ADR 狀態，再視使用者指示將 Admin WEB V1 分別交付 `ttr_server_roy` 的 Tartaros.Admin／Account／Session／Persistence／獨立 Admin Host。**管理員建立玩家帳號 != 原 Client 創角**（T03 RR-0010），`locked_until` 仍是密碼失敗暫時鎖定，不能充當 N 天/永久停權。需要核對來源 IP/CIDR＋管理 WEB URL/Host 設定與私網/代理／CSRF 防護、正整數 N 的政策、UTC 到期/立即撤銷 Session、資料庫交易/audit、部署/備份才可上線；不要用本次需求去假造原版 Client opcode 或冒充原版遊戲登入已可玩。

## Admin WEB V1 後續更新：IP / URL 免登入（2026-10-31）

使用者指定：**「目前先不管權限，指定的IP與URL就能管理」**。以 `REQ-0006` 第二筆 `PLAYER_ADMIN_REQUEST` 記錄修訂同一需求，未新增 REQ/Client RR。最新應以 [Admin WEB V1 設計](../design/admin-web/ADMIN-WEB-V1-PLAN.md)、[ADR-0004](../design/decisions/ADR-0004-admin-web-security-boundary.md) 為準：不做管理員帳號/登入/MFA/RBAC；配置**來源客戶端 IP/CIDR allowlist** 和**確切 WEB Host/port/base path** 進入後台，預設拒絕，私網/VPN/TLS、可信代理、POST Origin/CSRF、稽核來源 IP/理由/事件仍必要。同 IP 可能多人，不能假稱可辨識個別操作者；URL 不是憑證。新增帳號、N 天/永久停權、解封及 Session fencing 不變。無具體 IP/URL 時不要猜；未授權曝露公網或改 C00/Server，整體仍 CANDIDATE/PROPOSED、無執行測試。


## 2026-10-31 — extra/roy1 merge + RR-0010 新來源驗證

- 研究原稿 `extra/roy1` 已透過 [PR #63](https://github.com/we88ec3-prog/ttr_anal_multi/pull/63) 合併 `main`，merge `3ccbee4a78346b0c8751984555fc43157db5f723`；相對當時 main 新增 13 個研究報告與 BIN-byte verifier，不覆寫原研究台帳或其他作者文件。
- 正式 [S00 有界審查全文](s00-iterations/S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md) 已核對 E71–E74 的報告 SHA／類別區分與 5 份 KR 同版既存 Ghidra 偽碼。**無原始 BIN 可在此 ChatGPT 工作環境重跑作者的 native checker**，不得冒稱 T01 FULL-PASS、原版 Server 封包實測或 Client runtime。
- 真正新事實是 **CExpeditionCreateDialog 名稱 sender `C2S0x003E`（48B，UTF-16 at +6，+2..5 UNKNOWN）**、LOGIN scene **S2C `0x004A` signed status+2 → 本地 F4245 → name UI**，以及 app2 header name +0x0C 寫共享 `F938F2`、per-row C2S `0x26`/post `0x24`；它們**不是**已證同一原版 Server 交易或 playable-character 創建。
- RR-0010 繼續 **BLOCKED**，GAP-CHAR-0003 **OPEN**，SPEC-CHAR/FLOW **DRAFT/PARTIAL**；先從 Client 靜態 `0x3E+2..5`、LOGIN scene/狀態、N0 create UI、`0x4A→app2` 必要橋樑、E75 `F4261` subscriber 研究下去，不要以「無原版 Server」中止可進行的 BIN-first 工作。與 RR-0002/0009 去重。
- **CI 注意：**在此研究來源合併之前的 main `afc0b1fe` 已有 [CLM-CLIENT-0063 原生證據來源缺失的 CI failure](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41110975506)；不能為了使 CI 變綠而捏造 CLM proof 或自動降級別人原生主張。請交其 owner/T01 修正，不當作 RR-0010 已通過。


## 2026-10-31 Iteration 23 — 最新 extra/roy1 E76～E79 與 RR-0010 應用

`extra/roy1` 相對上次 PR #63 又新增 **E76～E79 八份研究/驗證器**，已由 [PR #65](https://github.com/we88ec3-prog/ttr_anal_multi/pull/65) 合併到 `main`（merge `9df86e629d19b688850d5cad4dfda50691513c4e`）。完整驗證／規劃見 [Iteration 23](s00-iterations/S00-20261031-ITERATION-23-EXPEDITION-ROSTER-PLAN.md) 與 [24 項未執行測試](s00-iterations/S00-20261031-ITERATION-23-ACCEPTANCE.md)。

**下一輪先引用的確切成果：** E76 `F938F2` nonempty→Expedition Page+0x144 ready→三個 UI controls；E77 `S2C B6→local F4278(0)→0x672F00` 條件式 role record/placeholder UI；E78 `C2S3E+2..5` 仍 UNKNOWN，`F4278` 有額外本地來源；**E79 正向 trace S2C app `0x002B` network+singleton→2+53N row writer，與 app2 65+53N 共用 `F94304` 同一角色 array**，明確修正 E72 曾稱 destination 不同的說法。這些不等於原版 Server 已證 `3E↔4A`、`33↔2B`、`4A→app2/2B/B6`，更不等於已可建立 playable-character。

已在 DRAFT `SPEC-CHAR/FLOW`、`GAP-CHAR-0003`、`s00-requirement-slices.json` 納入。**RR-0010 BLOCKED**、**GAP-CHAR-0003 OPEN**、SPEC DRAFT/PARTIAL；正式 REQ 未追加未審核 CODE_ANALYSIS discovery（缺新的同版正式 CLM）。開發可先做 `ExpeditionProfile` 和 `FullRosterSnapshot/ApplyRosterDelta` **同一 source-of-truth**、合成0/1/10角色／異常/重放/錯序測試；native framing/scene 必須交 T02/T03/T04/T06 繼續研究。沒有獲獨立授權不執行/連線原 Client；本 S00 回合也未取得原始 Tartaros.bin 重跑 T03 verifier。CI 若沿舊的 `CLM-CLIENT-0063` 報錯，不可擅自偽造原生 evidence 讓其變綠。


## 2026-10-31 — 最新 extra/roy1 E80 / Iteration 24 規劃

E80 是 **RR-0002 選角的研究**，不是 RR-0010 真正建立 playable-character。已透過 [PR #67](https://github.com/we88ec3-prog/ttr_anal_multi/pull/67) 合併來源（merge ba5f2795a047b01d861ad470b424a555d7554353），S00 詳細審查和可實作切片：[Iteration 24](s00-iterations/S00-20261031-ITERATION-24-SELECTION-SQUARE-HANDOFF.md)、[20 項測試草案](s00-iterations/S00-20261031-ITERATION-24-ACCEPTANCE.md)。E80 來源/verify blob、同版 Ghidra 0x4a3b80/0x5f46d0/0x673da0/0x4b7f00 交叉讀取記錄見規劃；未獨立重跑原始 KR BIN 或 Client。

- 可引用的有限新證據：C2S42 4B slot0（角色 index u8 at+2、mode u8 at+3；UI 見 mode0/2）、部分 ExpeditionScene UI index=child+1 / role+0x5C guard，部分按鈕在 manager gate 擋住 queue 時仍設 local scene+0xCC pending=1；**pending 不等於 Server 收到/ACK**。
- 另一個有條件 Client subchain 是 **S2C0x69 subtype7→CSquare/ChannelState +3/+4 → C2S0x43 UserData+18 u8、常量0A**。UserData 與 ChannelState 是兩個不同 object，這不是 original Server 對 C2S42 的已證 ACK；S2C42/43 也不是已證選角回覆。
- Iteration23 的 **S2C2 full 65+53N 與 S2C2B delta 2+53N 共用 F94304 role data** 繼續有效；app2 的 ID0 role mask shift 有潛在不一致，Server 初期若採 role1..9 是自訂保守策略，並非官方規則。
- **角色建立與選擇分開**：RR-0010 BLOCKED（playable-character create→reply→roster 未閉合），RR-0002 BLOCKED（selection response pairing/拒絕 UI 不明），RR-0008 IN_REVIEW、RR-0009 SUBMITTED，GAP-CHAR-0001/0003 OPEN，SPEC-CHAR/FLOW DRAFT/PARTIAL。不要把源碼研究上 Git 或 synthetic Domain test 視為 ACCEPTED/T01 FULL-PASS。
- 開發次序：Iteration23 SR23-01/02 Expedition/RoleStore → Iteration24 SR24-01/02 RoleOwnership/SelectionAttempt→ SR24-03 bounded C2S42 parser→SR24-04 Square candidate **feature off by default**；另交 T02/T03/T04/T05/T06/T16 查正向場景/錯誤/教學。當前未在設計 repo 開發 Server。


## 2026-10-31 — Iteration 25 已提交的後續規劃（新對話先核對最新 main）

前一階段 main=e9ec313b3d2cf0693134606d1e58f818c2f557ca CI 在 Actions #41124285391 成功（修正 CLM-CLIENT-0063 native evidence refs）；這個 CI **不證 Client 可玩**。接續 Iteration23/24 的 RoleStore/SelectionAttempt/Square 有界研究，新建 [Iteration25 完整教學首次入場與復原設計](s00-iterations/S00-20261031-ITERATION-25-TUTORIAL-ENTRY-RECOVERY-PLAN.md) + [I25-T01～T16 未執行測試](s00-iterations/S00-20261031-ITERATION-25-ACCEPTANCE.md)，以及 [ADR-0006](../design/decisions/ADR-0006-tutorial-progress-and-session-fencing.md)（**PROPOSED、不具 normative 效力**）。

- 下一個真正可在獨立 Server 庫做的開發包：SR25-01 per-role Progress/revision、SR25-02 AdmissionId/SessionEpoch fencing+ban、SR25-03 首進/重登/完成 route 分歧、SR25-04 Quest/Reward/idempotency/outbox、SR25-05 adapter OFF，SR25-06 合成負例測試，SR25-07 補原 Client scene/quest 所需正向證據。**本文沒有修改 ttr_server_roy**。
- 研究前提：原版 C2S42→Server success/失敗→S2C69 subtype7→CSquare→C2S43→tutorial scene/Quest 的因果並未證實；SceneList(1001,1) 是資源鍵、Client S2C0x4C Scenario14 map flag 非 Quest 完成；不能將 MockClient/CI PASS 當作 original client E2E。
- Roadmap 的 C-TUTORIAL-DOMAIN 與 B-NET/B-CHAR/B-SCENE 研究可獨立開始規劃，但僅是 phase-C 候選，checker 仍應給 EXTERNAL_REVIEW_REQUIRED／BLOCKED，正式 Native/ADR/REGISTRY 不自行升格。下次要修改 Server 請直接在 ttr_server_roy 下建立實際 DEV/C05 接手任務並經維護者確認政策。


## 2026-10-31 — Iteration 26 最新接續：Encounter → Scenario14 → Quest14/16/15 → Tutorial terminal/Exit

先從真正當前 main 和其 GitHub Actions 重新確認。本輪基線 main=41a7ba739e81c4f434078025b7fad2ede9436bb1、Actions #41125898881 SUCCESS（僅離線治理，不是原版 Client E2E）。

已新增 [Iteration26 完整規劃](s00-iterations/S00-20261031-ITERATION-26-COMBAT-QUEST-EXIT-PLAN.md)、[E17-A～J/E18～26 的 19 gate source-pinned matrix](s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json)、[18 個 I26-Txx PLAN_ONLY/NOT_RUN 案例](s00-iterations/S00-20261031-ITERATION-26-ACCEPTANCE.md)、[ADR-0007 PROPOSED](../design/decisions/ADR-0007-encounter-quest-settlement-boundaries.md)、唯讀 checker 與 13 項 regression tests／CI step。**沒有原版 Client、沒有實作 ttr_server_roy**。

關鍵源級邊界：local C2S40 00 0E 00 可能請求 Scenario14，另 S2C0x4C 本地 CTutorial map[14] 可表示 Lua scenario-ended，**但沒有已證原版 Server pairing**，更不等於 Quest14 complete/Quest16 complete/TutorialCompleted。Quest15 available≠accepted/completed；Quest16 Reward type2/value50 不得冒稱 EXP/金錢。E25/26 normal-world/重登仍缺真 Client→Scene→Actor/Control Ready positive proof。

下一輪開工：Server-only 先做 S26-C01/C02 Encounter/Actor → C03/C04 AI/action/skill/damage → C05/C06 settlement/recovery → C08 Quest14/16/15＋reward→ C09 terminal/exit／relogin；原始 Client protocol adapter C07 只在 T02/T07/T08/T09/T10/T14/T15/T16 等同版正向證據完整後，另經授權 runtime 才考慮打開。現有 RR-0002/0010 BLOCKED、RR-0008 IN_REVIEW，GAP-SCENE OPEN，SPEC-FLOW/SCENE DRAFT/PARTIAL；ADR-0006/7 PROPOSED、沒有被主庫 CI 自動批准。


## 2026-10-31 — Iteration 27：C05 實際可接手規劃（先確認新 main）

本輪先核對 `ttr_anal_multi main=5c1aac53faf4638c72a000f673ee04750fdcdf4c` CI #41127783472 **SUCCESS**，再讀 `ttr_server_roy main=c17a986fc66caca8af0efb72e2b42d1188e2a584` 的 C02/C03 transactional APIs、C04 offline probes、原來源 pin `dd69ec9...` 仍未升正式 Client wire。未做 Server 實作/原 Client 運行。

已新增 [Iteration27 C05 工程交接](s00-iterations/S00-20261031-ITERATION-27-C05-DELIVERY-PLAN.md)、[S27-W01～W09 9 工作包 JSON](s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json)、[I27-T01～T18 驗收計畫](s00-iterations/S00-20261031-ITERATION-27-C05-ACCEPTANCE.md)。W01 C03 lease/selected-role seam → W02 Encounter Admission → W03 Actor/AI → W04 Attack/Skill/Hit → W05 Scenario Settlement → W06 Quest14/16/15 → W07 Reward/Outbox → W08 tutorial terminal/exit/relog；W09 原 Client adapter **維持 OFF** 及獨立 source/runtime gate。全部工作包尚待正式 Server owner 接手，並非在 `ttr_server_roy` 有實作結果。

與 Iteration26 19-gate source overlay 精確連結；整合後的 S00 CI 會驗證工作包 DAG、現有原始 gate refs、ADR-0006/0007 仍 PROPOSED、18 個 `NOT_RUN`、native adapter 不可自動開啟。**這只驗規劃不驗 Client 可玩**。下次如果使用者明確要 Server 開發，應改在 `ttr_server_roy` 開實作 PR 並跑 .NET/SQLite/PostgreSQL 測試、保留原始 `contracts/spec-revision.json` 原來源 pin 的版本審查，不可以因為新 S00 main 就把 proposed ADR 認為 approved。

此時正式 RR-0002/0010 BLOCKED、RR-0008 IN_REVIEW、SPEC-FLOW/SCENE DRAFT/PARTIAL；如有人更新主分支，優先重讀 registry，不用此快照代替當前唯一權威。


## 2026-10-31 — Iteration 28：C05 W01～W03 第一組可實作契約

開工已核對 S00 `main=97e019c603bea79a7774631e82195b13be207fc4`，其 Actions #41129086650 SUCCESS；Server `ttr_server_roy main=c17a986fc66caca8af0efb72e2b42d1188e2a584` 的 `IAtomicCharacterActions`、`ISessionLeaseRegistry`、`SessionLease`、SQLite/PostgreSQL 選角存儲與 schema。**下次要先重讀最新 main，不可把本快照當最新**。

[Iteration28 詳細設計](s00-iterations/S00-20261031-ITERATION-28-W01-W03-IMPLEMENTATION-PLAN.md)、[S28-01/02/03 機讀契約](s00-iterations/S00-ITERATION-28-C05-W01-W03-CONTRACT.json)、[16 個 I28-Txx NOT_RUN 測試](s00-iterations/S00-20261031-ITERATION-28-W01-W03-ACCEPTANCE.md) 已把 W01～W03 拆成三個預定下游 Server PR：
- **C05-P1**：新原子 persistence contract 在同資料交易查 exact SessionLease/selected-role ownership 並 ReserveEncounter，絕不能只信任另一 transaction 讀到的 `GetSelectedAsync` 結果；SQLite writer/PG Session row FOR UPDATE 鎖序要對齊既有 C03。
- **C05-P2**：Encounter RESERVE→ACTIVE→終局、CAS、Session renew/revoke/relog fencing、crash 後 idempotent reconcile。Resume/abort policy 未批准只能 mock。
- **C05-P3**：可重現的 mock Actor spawn/AI tick/movement（fixture SHA/seed、同 EncounterId 唯一事件/版本、錯 role/actor/tick 拒絕），**不等於原版 Scenario14 敵人資料或協定**。

SQLite local user_version=1、PostgreSQL 已有 migration003，任何新表都需獨立 schema/migration/recovery review；**本輪沒有在獨立 Server repo 實作/提交 migration，也沒有執行原 Client**。ADR-0006/0007 仍 PROPOSED，不可因 S00 CI PASS 自動核准、不可開原版 KR/TC codec。後續可以接續 Iteration27 W04（Attack/Skill/Hit）的細分，或由 Server 開發者在其 repo 接手 P1。


## 2026-10-31 — Iteration 29：W04 Attack/Skill/Hit/Death + Crash/Session fencing

開工 S00 `main=d1f9e174eb1e24e0589eee6605b750bc85a54215`／Actions #41130071717 SUCCESS；獨立 Server `main=9caffb75c374147b71dea51227b5c4f13b33071d`／Actions #41130449937 SUCCESS。**新對話務必重新核對當時最新 main/CI**，不能依此快照聲稱 remote head 永不變。

已規劃 [Iteration29 詳細實作](s00-iterations/S00-20261031-ITERATION-29-COMBAT-IMPLEMENTATION-PLAN.md)、[S29-01～04 source-pinned machine contract](s00-iterations/S00-ITERATION-29-C05-COMBAT-CONTRACT.json)、[I29-T01～T24（24 項）NOT_RUN 測試](s00-iterations/S00-20261031-ITERATION-29-COMBAT-ACCEPTANCE.md)。S29-01 ordinary attack/atomic lease and combo; S29-02 skill availability/resource/cooldown/cast cancellation; S29-03 authoritative hit/damage/HP/death once; S29-04 cancel/relogin/ban/crash and verified ActorDeath→W05 handoff。下游 PR 候選 C05-P4..P7，依賴 Iteration28 仍未實作的 W01–W03 原子 Encounter/Actor 基礎；**本輪只有規劃，沒有下游 code/DB change**。

關鍵 Server 基線修正：C02-D 已於最新 `ttr_server_roy` main 實作 SQLite local account suspend/unban，SQLite schema v2、ban 同交易 revoke Session；Iteration28 當時 SQLite v1 是**歷史真實快照**，不要修改歷史文件。下次規劃或實作新 combat migration 應從 local v2→待核准 v3；PostgreSQL 仍 003→候選004；不得自動認定 C02-D moderation 在 PG 已實作。Downstream code 必須於權威交易內重驗 exact lease、selected character/Encounter、ban/epoch 和 Actor revision，不能信任 Client damage/HP/勝利事件。

E17-E original T10/T02/T04、E17-F T11/T10/T04/T02、E17-G T12/T08/T10/T11 的原 Client 技能/命中正向因果仍 SOURCE PARTIAL；原 Client 測試須另外授權。ADR-0006/0007 PROPOSED/NON-NORMATIVE；SPEC-FLOW/SCENE DRAFT/PARTIAL，native adapter OFF；S00 CI/24 `NOT_RUN` 不能當 Server 或原 Client 相容驗收。

**Iteration30 建議**：W05 Objective/Scenario14 once-only Settlement/outbox；必須從已授權 ActorDeath/event 而不是固定秒數或 local S2C0x4C map flag 直接勝利。也可交由實作庫先做 C05-P1 原子入場，不因等待原 Client 而停掉 mock-domain 開發。


## 2026-10-31 — Iteration 30：Scenario14 mock objective/wave/terminal/outbox/Quest14 eligibility

核對開工 S00 `main=295b53b003f93e41d7281f94b98d158f06302bb1`，Actions #41134506321 **SUCCESS**（只代表規劃/離線測試）。Server `ttr_server_roy main=272079cc69b124870af303d711931ec20bce2229` 的最新提交新增 **C00-OPS SQLite 維運工具**，C05 Gameplay/Scenario14 **未實作**，其當次 Actions 在查核時 **IN_PROGRESS**。新對話應重讀兩庫最新 main 和 workflow，不能把這份快照當永久最新或把 C00-OPS 當 C05。

本輪 [Iteration30 完整開發交接](s00-iterations/S00-20261031-ITERATION-30-OBJECTIVE-SETTLEMENT-PLAN.md)、[S30-01～04 machine contract](s00-iterations/S00-ITERATION-30-OBJECTIVE-SETTLEMENT-CONTRACT.json)、[I30-T01～24](s00-iterations/S00-20261031-ITERATION-30-ACCEPTANCE.md) 都是 **PLAN_ONLY/NOT_RUN**。S30-01 僅接收 S29 Hit/Death 同 Encounter/ActorGeneration 的 verified death event，S30-02 才計 mock wave 和 objective，S30-03 一次性 terminal CAS/audit，S30-04 Outbox 重送與獨立 Quest14 eligibility（**不完成 Quest14**）。

Server 建議開工 C05-P8..P11，但**依賴**前面未實作的 C05-P1..P7（Iteration28 Encounter/Actor、Iteration29 Hit/Death）。DB SQLite C02-D v2 且新 mock Schema v3 未批准/未套；PostgreSQL current 003 下一版 004 同樣未套；現有 C00-OPS 可做 DB 備份/恢復演練但沒有替 C05 domain schema 測試。不得把局部 Client `0x004C` `map[14]` 當 official Server result 或 Quest14 completed。原 E17-H DISCOVERY_REQUIRED、E17-I PARTIAL、E17-J ADR_PENDING、E18～E20 仍 source PARTIAL；ADR-0006/0007 PROPOSED，不可自動將 Native KR/TC adapter 打開，實際原 Client 需另行授權。

下一輪若繼續 S00 規劃，優先 Iteration31 W06 Quest14→Quest16→Quest15 與 W07 唯一 RewardLedger、Quest/Scenario transaction 邊界；若改要求實作，在獨立 `ttr_server_roy` 建真實程式碼 PR/測試，不在分析庫混寫 Server code。


## 2026-10-31 — Iteration 31：W06 Quest14/16/15 + W07 RewardLedger

開工核對 S00 `main=4ee57b51e600653537afaa6cecedf1cfe0551f8b`，Main Actions #41135452095 SUCCESS；獨立 Server `main=272079cc69b124870af303d711931ec20bce2229` 的 CI #41134733030 SUCCESS，但僅 C00-OPS SQLite tools、C02-D Account Moderation、C03-C Character、C04 bounded offline probe，不代表 C05 任務/獎勵已開發。**下次一定重新讀兩庫最新 main。**

本輪新增 [Iteration31 詳細規劃](s00-iterations/S00-20261031-ITERATION-31-QUEST-REWARD-PLAN.md)、[S31-01～04 contract](s00-iterations/S00-ITERATION-31-QUEST-REWARD-CONTRACT.json)、[I31-T01～24 NOT_RUN](s00-iterations/S00-20261031-ITERATION-31-ACCEPTANCE.md)。S31-01 Quest14 eligibility≠TURNED_IN；S31-02 Quest16 AVAILABLE/ACCEPTED/COMPLETED/TURNED_IN 各獨立；S31-03 Quest16 原版 Reward type2/value50 映射未知，獨立 Mock RewardPolicy 封存/唯一 ledger/Outbox；S31-04 Quest15 僅 available，另與 TutorialCompleted/WorldReady 及重登入隔離。

**本輪重要新風險/修正**：Iteration28～30 的不同規劃均以 SQLite v3、PostgreSQL 004 當相對下一個候選版本，並未真正開 schema。若 Server 每個 C05 工作包各自使用相同版本號會產生 collision；故 Iteration31 一律保留 SQLite v2/PG003 現有基線、後續版號 `UNALLOCATED_NOT_APPLIED`，待 Server maintainer 一次配置 Encounter/Combat/Scenario/Quest 所有 migration 的唯一順序。現有 SQLite C02-D ban 不可自動當 PostgreSQL 已具相同功能。

所有新工作包只是 `SERVER_MOCK_ONLY` 的設計，24 個驗收都 `NOT_RUN`；原版 Client NPC/Quest/status/Reward/Wire 仍 E20-E24/E26 PARTIAL/UNKNOWN，沒有新正式 RR/GAP/REQ/TEST 結案、沒有任何 KR Client runtime；ADR-0006/7 仍 PROPOSED/NON-NORMATIVE，原生 adapter OFF。下一步如繼續規劃可做 Iteration32 S27-W08 Tutorial terminal/Scene Exit/WorldReady/relog；若要求 Server 實作，應到 `ttr_server_roy` 實際建 C05 code/DB PR，從最前置的 W01/Encounter 開始。


## 2026-10-31 — Iteration 32：S27-W08 TutorialComplete、SceneExit、WorldReady、ReLogin

已核對 S00 `main=dcbb7f9d41b50bdf563ff849ae1442f56d9c40c4`／CI #41136854759 SUCCESS；Server `ttr_server_roy main=272079cc69b124870af303d711931ec20bce2229`／CI #41134733030 SUCCESS，仍只有 C00-OPS、C02-D local moderation、C03 offline Character、C04 bounded evidence，**C05 尚未實作**。下次開工必須重新查最新 main，不可長期沿用歷史快照。

本輪新 [完整開發規劃](s00-iterations/S00-20261031-ITERATION-32-TUTORIAL-EXIT-RELOG-PLAN.md)、[S32-01..04 機讀契約](s00-iterations/S00-ITERATION-32-TUTORIAL-EXIT-RELOG-CONTRACT.json)、[24 項 I32-T01～24 皆 NOT_RUN](s00-iterations/S00-20261031-ITERATION-32-ACCEPTANCE.md)：S32-01 每角色 checkpoint 完成資格（Quest15 available 不是 completed），S32-02 獨立 SceneExitAdmission/CAS/lease/ban，S32-03 Server mock world admitted 與真實原版 Client scene/control ready 觀測隔離（native OFF），S32-04 new SessionLease、Quest/RewardLedger、crash/outbox/provider 恢復。S32 仍依賴未在 Server main 落地的 Iteration28～31 C05 模組，**沒有直接可跑原版 Client 的新程式**。

E23 SERVER_POLICY_NEEDS_ADR、E24 SOURCE_BACKED_PARTIAL、E25 NATIVE_DISCOVERY_REQUIRED、E26 ORIGINAL_CLIENT_RUNTIME_REQUIRED、E17-J SERVER_POLICY_PENDING_ADR；研究 owner、阻塞與正式 RR/GAP/SPEC/TEST 未因 S00 CI 而改。原 Client 實跑需要另行明確授權；ADR-0006/0007 仍 PROPOSED。SQLite v2 / PostgreSQL 003 是現行已觀察 schema；下一版維持 `UNALLOCATED_NOT_APPLIED`，由 Server 專案統一配置模組 migration，避免不同 Iteration 方案互相佔用 v3/004。

下輪若繼續規劃，建議 Iteration33 統整 C05-P1～P19 真實開發順序、統一 migration 版本、未決 policy 决策以及原版 Client native release gate。若使用者要「開發」而非「規劃」，須在 `ttr_server_roy` 實際寫 domain code/測試/PR，而不是在 S00 看見規劃就宣稱 gameplay 已完成。


## 2026-10-31 — Iteration33：C05-P01～P19 整體開工順序／DB Schema 及 native release

本輪查核 S00 `main=e1a3c383a046a0514f7eee983bc2fc3173c3a113`、[main CI #41179316444](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41179316444) SUCCESS；Server `ttr_server_roy main=272079cc69b124870af303d711931ec20bce2229`、CI #41134733030 SUCCESS，仍只有 C00-OPS、C02-D SQLite local suspension/Session revocation、C03 character offline、C04 scoped static checks，**C05 實作不存在**。下次應重查兩個 main、Server schema/CI、ADR policy；這裡是當時 read-only snapshot。

新 [Iteration33 完整整合規劃](s00-iterations/S00-20261031-ITERATION-33-C05-INTEGRATED-DELIVERY-PLAN.md)、[19-PR DAG/7 release gates/8 decisions/來源 pin JSON](s00-iterations/S00-ITERATION-33-C05-INTEGRATION-CONTRACT.json)、[I33-T01～24 整合驗收](s00-iterations/S00-20261031-ITERATION-33-ACCEPTANCE.md) 已定義，但全為 `PLAN_ONLY/NOT_RUN`，**並非 19 個已建立的 GitHub Server PR**。順序：R0 Schema/ADR/source→R1 P01～03 Encounter/Actor→R2 P04～07 combat→R3 P08～11 objective/terminal/outbox→R4 P12～15 Quest/Reward→R5 P16～19 tutorial exit/relog；R6 原生 Client adapter 額外與獨立授權。

重大前置：**唯一 C05 migration manifest / owner**，SQLite current v2、PG current migrations003；Iteration28～30 所說的 SQLite v3/PG004 都是歷史候選，禁止各模組重用版號，下一版 `UNALLOCATED_NOT_APPLIED`。PostgreSQL 是否等同 SQLite C02-D 的停權能力未驗證，不得默認跨 Provider parity。產品八個未決決策 D33-01～08 要經維護者批准，不可因 mock 完成便自動核准 ADR-0006/0007。

原版 Client `CTutorial 0x4C` local map、Quest15 AVAILABLE、Lua town LoadMap、C2S0x42/S2C0x69/C2S0x43、Server Mock WorldAdmitted 都不能推論原版 KR Client ready。E17-A/J/E23～E26 的源證據、原 RR/GAP/CLAIM/TEST 及 ADR 狀態均未被更改，R6 `BLOCKED_BY_EVIDENCE`。如使用者改要求「開發」，應直接在獨立 `ttr_server_roy` 先落實 R0 schema/policy guard 與 P01 transactional Admission，然後逐步 commit/測試各 PR；原版 Client 證據不足不能成為停止所有 mock domain 工程的理由。
