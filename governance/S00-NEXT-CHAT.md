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
