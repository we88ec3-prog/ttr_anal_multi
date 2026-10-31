# Tartaros Server 規格入口（Phase B — T02/T03 整合試行）

目前 **7 份 KR 規格均為 DRAFT / PARTIAL，沒有 STABLE**。只適用於 `shared/targets.json` 指定的原始 KR SHA；不能跨到 TC。目的是供其他人獨立設計 Server，不要求使用此庫內的任何 Server 實作。

| 規格 | 目前可引用的有限結果 | 尚未完成 |
|---|---|---|
| [SPEC-NET-0001](protocol/SPEC-NET-0001.md) | 1A68/0BBB frame、XOR/checksum、sender/receiver 長度限制 | 端到端收送模式與全部 marker |
| [SPEC-NET-0002](protocol/SPEC-NET-0002.md) | Connect 參數/slot/pipeline、outbound queue→WSASend | 握手、連線切換、重試、真正 Server 實收 |
| [SPEC-NET-0003](protocol/SPEC-NET-0003.md) | WSARecv/IOCP→frame parser→queue→CClient/Scene 命令分派 | 非法 frame 的完整處理與各業務狀態 |
| [SPEC-AUTH-0001](session-account/SPEC-AUTH-0001.md) | E8/0F 認證 payload 與局部登入回覆消費 | 帳號政策、完整回覆及切線 |
| [SPEC-CHAR-0001](session-account/SPEC-CHAR-0001.md) | command2 65+53N 角色清單與 UI record 部分對應 | 選角確認、初始化和場景切線 |
| [SPEC-FLOW-0001](session-account/SPEC-FLOW-0001.md) | 登入→選服→清單→選角→場景的已知條件與不連續之處 | 跨步驟真實收發/回覆順序未閉合 |
| [SPEC-SCENE-0001](world/SPEC-SCENE-0001.md) | extra/roy1 E01–E16 的 SceneList/seq/Lua 靜態資源鏈 | 尚未證明 0x42 回覆到 1001/1 場景 key 的連結 |

## 下一階段工作與驗收門檻

- [S00 Phase B 收斂與 Phase C 交接計畫](../governance/S00-NEXT-PLAN.md)：工作包依賴、完成條件和 Server 實作者交付。
- [方向別封包／狀態證據矩陣](session-account/phase-b-message-matrix.md)：區分已觀察的 local payload、S2C handler 和仍 UNKNOWN 的交互。
- [機器工作包計畫](../governance/s00-roadmap.json) 與 [準備度檢查](../governance/check_s00_readiness.py)：從 RR/GAP/SPEC/TEST 計算阻塞；**不會自動宣布相容或 STABLE**。

## 規格交付與 Server 專屬設計審核

- [獨立實作者規格驗收清單](IMPLEMENTER-HANDOFF.md)：只看 spec/conformance，逐項指出仍需的方向別位元組與狀態。
- [七項契約覆蓋矩陣](../conformance/contract-coverage.json) 與 [結構／阻塞檢查器](../governance/check_contract_coverage.py)：目前七項均 BLOCKED；這是交付準備度，不是原版 Client 行為檢驗。
- [三份 Server-only ADR 提案](../design/decisions/README.md)：狀態均為 PROPOSED、NON-NORMATIVE；不能當成官方 Server 語意，也未加入本頁的正式 SPEC normative ADR。
- [T01 最新 R0 來源整合結果](../research/handoffs/t01-20261029-risk-intake/server-impact.md)：新增 Client/Quest 有界主張，**尚無新登入／選角封包**。

## 研究與可實作性的入口

- [T02 既有成果完整盤點及 T01 勘誤對照](protocol/T02-EVIDENCE-INVENTORY.md)
- [T03 extra/roy1 原稿引入與更正、證據邊界](../governance/PHASE-B-T03-EXTRA-ROY1.md)
- [T03 定向研究交接](../governance/T03-S00-AGENT-REQUESTS.md)
- [連線邊界狀態模型](protocol/t02-network-state-model.md)：只描述已觀察的 Client 路徑，**不宣稱官方 Server state machine**。
- [S00 整合流程](../governance/s00-workflow.md)、[目前優先的精確研究請求](../governance/T02-S00-AGENT-REQUESTS.md)
- [機器規格索引](spec-index.json) → [20 條 CLM](../research/claims/index.json) → [328 份 SRC 登記](../research/intake/index.json)；其中後續 T01 新增的 318 份主要為 R0 來源身分收件，**不代表 318 份原稿完成語意驗收或能成為規範性 wire 依據**。目前 [7 個 GAP](../design/gaps/index.json)、[8 個研究請求](../research/requests/index.json) 仍阻塞。
- [離線測試](../conformance/README.md) 只驗證研究派生的局部格式與靜態邊界映射，**沒有 Client 封包實測或 Server 連線驗收**。

目前不受理外部 Issues；Server 程式碼、運行、資料庫及部署獨立於本設計庫。未證實的官方 Server 內部規則不能轉為此處的 Client 原生事實。


## Server 需求清單（與原生證據分開）

[統一 REQ 來源與規則](../design/requirements/README.md) 收錄程式碼分析所見 Client↔Server 交互候選、**已獲授權的**遊戲運行觀察，以及玩家/管理員功能需求（含安全、GM 稽核與營運）。同一項需求可累積三種來源，只有明確核准才是實作要求。起始五條均為 CANDIDATE；不得因此自行變更原版封包或宣稱已運行測試。驗證：`python -B governance/check_server_requirements.py --check`。


## 登入至角色畫面的優先交付

目前依 [S00 需求分段](../governance/s00-requirement-slices.json)：`SLICE-LOBBY` 先研究登入/選服/角色清單到 UI 的實際狀態與資源門檻，`SLICE-CREATE` 獨立找創角入口及 Server 建角請求/回覆，`SLICE-ENTER-WORLD` 再處理選角成功與場景。這是規劃視圖，**不是**原版 Server 的已驗證封包時序。精確研究責任見 [S00 研究題單](../governance/S00-LOBBY-CREATE-RESEARCH-QUESTIONS.md)。下次新對話從 [S00 交接檔](../governance/S00-NEXT-CHAT.md) 開始。


## Server Lobby 逐項可交付性（Iteration 12／13）

[登入到角色畫面 9 個檢查點](../governance/s00-lobby-gates.json) 與 [12 個尚未執行的驗收情境](../governance/s00-iteration12-lobby-test-plan.json) 清楚區分原始 Client 靜態證據、方向別契約、原版 Client 畫面實測。執行 `python -B governance/check_s00_lobby_gates.py --check` 或 `--json` 可從現有 REQ/RR/GAP/SPEC 看到仍缺的部分。所有項目目前仍是設計阻塞，沒有測試或原版登入成功證據；工作優先與主責見 [Iteration 13](../governance/S00-20261030-ITERATION-13.md)。

## 2026-10-31 — C04-D/E/F 原版 Client Gateway 整合規劃（不升 SPEC）

S00 [Iteration38](../governance/s00-iterations/S00-20261031-ITERATION-38-C04-KR-LOGIN-GATEWAY-PLAN.md) 補足原本 C01 synthetic TCP 元件尚未接入原版遊戲 Host 的**開發交付規劃**。C04-D 是 local-only listener/TCP 安全日誌；C04-E 是 source-gated KR framing/Auth；C04-F 是登入結果/選服切線/角色清單/UI。18 個規劃 Gate 見 [矩陣](../governance/s00-iterations/S00-ITERATION-38-C04-LOGIN-GATES.json)。

**七份 SPEC 仍 DRAFT/PARTIAL、原有 GAP 全 OPEN、原有 conformance TEST 僅 OFFLINE_SYNTHETIC。** 本輪新增版本中立 `REQ-0009 CANDIDATE`（TCP RX/TX 日誌維運需求），**沒有新 native opcode、實機封包、T01 FULL-PASS、Server 源碼或原版 Client runtime PASS**。本頁較早記載的 7 GAP/8 RR 是舊迭代快照，必須查唯一 [RR](../research/requests/index.json)、[GAP](../design/gaps/index.json)、[REQ](../design/requirements/index.json) 最新狀態，不得以歷史文字代替台帳。
