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


## Server 需求發現：不必等待兩個獨立證據來源

[Server 需求候選索引](server-requirements/index.json) 與 [來源分類政策](../governance/S00-SERVER-REQUIREMENT-SOURCES.md) 現在承接三種需求來源：程式碼分析、另行授權的遊戲運行觀察，以及玩家／管理員／維護者需求。程式碼中出現需要 Server 收發封包或維持狀態的情境，就能列出有來源的 **Server 候選需求**；即使原版 Server 的實際發送時序尚未知也可以登記。使用者提供的歷史協定／舊 Server 資料歸 USER_REQUEST 參考附件，**不是第四種已驗證 Client 證據**。提案和正式 `MUST`／相容性驗收仍分開。
