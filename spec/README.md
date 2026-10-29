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

## 研究與可實作性的入口

- [T02 既有成果完整盤點及 T01 勘誤對照](protocol/T02-EVIDENCE-INVENTORY.md)
- [T03 extra/roy1 原稿引入與更正、證據邊界](../governance/PHASE-B-T03-EXTRA-ROY1.md)
- [T03 定向研究交接](../governance/T03-S00-AGENT-REQUESTS.md)
- [連線邊界狀態模型](protocol/t02-network-state-model.md)：只描述已觀察的 Client 路徑，**不宣稱官方 Server state machine**。
- [S00 整合流程](../governance/s00-workflow.md)、[目前優先的精確研究請求](../governance/T02-S00-AGENT-REQUESTS.md)
- [機器規格索引](spec-index.json) → [16 條 CLM](../research/claims/index.json) → [10 份 SRC](../research/intake/index.json)，皆非新增 FULL-PASS；[7 個 GAP](../design/gaps/index.json)、[8 個研究請求](../research/requests/index.json)。
- [離線測試](../conformance/README.md) 只驗證研究派生的局部格式與靜態邊界映射，**沒有 Client 封包實測或 Server 連線驗收**。

目前不受理外部 Issues；Server 程式碼、運行、資料庫及部署獨立於本設計庫。未證實的官方 Server 內部規則不能轉為此處的 Client 原生事實。
