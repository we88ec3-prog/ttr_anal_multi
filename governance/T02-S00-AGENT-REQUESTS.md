# S00 → T02/T03 Agent：只處理剩餘 Server 阻塞（不需要先啟動 REA）

2026-10-29。**初始政策：S00 先依現有 GitHub 證據整理，僅缺口才派桌面 Agent；沒有 REA 亦可用唯讀已存在的反組譯與索引。**

## 類型化研究請求

| ID | 優先 | 研究問題（需交付 bounded 主張） | 接手 Agent | 停止條件 |
|---|---|---|---|---|
| RR-0001（既有） | P0 | 判斷已知 1A68/0BBB sender 與 receiver 的實際連線模式、何時首次收送、哪些 outbound payload 使用哪個 slot | T02 → 可無 REA 先整合 | 以確切版本/SHA 對每個 Server 需實作的首發/回覆路徑給出可操作規格；無證據的狀態保留 GAP |
| RR-0004 | P0 | 確認 `conn+A02C` 直接/間接 writer、初始化條件、異常 fallback 是否可能真正送出 1A68 | T02；必要時 REA | 排除高風險 alias，或提供有界可解釋的條件/反例；不是「掃到一次=唯一 writer」 |
| RR-0005 | P0 | `806AD0` 所見 socket connect/close 與 T03 0x13 登入結果 → 4957C0/495610 切線的**實際順序** | T02×T03，REA 只用於缺漏原生條件 | 提供 Client 版本、條件、S2C/C2S 訊息序列、成功與錯誤分支，不以端口常數當官方 endpoint |
| RR-0006 | P1 | `807B40` 2633/22D7 路徑與 checksum 失敗後的 node/pool/copy/close 結果 | T02；必要時 REA | 給出對 Server 互通必需的精確例外處理與測試，未知的非必要錯誤分支可標非阻塞 |
| RR-0007 | P1 | `4930E0` 之後 CClient+Scene 分派依狀態/command 的接收條件、channel≠2 的資料去向 | T02×T03/T05；可無 REA 起步 | 對 0x13/command2/選角相關需要處理的 S2C 明列目標 handler；不擴到全 3029 個 handler |

## 所有 Agent 需要遵循

- 先讀 [SPEC-NET-0001](../spec/protocol/SPEC-NET-0001.md)、[新增連線/分派規格](../spec/protocol/SPEC-NET-0002.md)、[盤點與更正](../spec/protocol/T02-EVIDENCE-INVENTORY.md)、[T01 本批 T16 勘誤](../shared/integrations/T01-20261029-continuation-02/t16/README.md)。
- **不得把現有已確認的 WSASend／WSARecv 與 dispatch 重新宣稱「未找到」**，或重花額度定位這些地址。若仍缺新細節，明確指出哪個 caller、欄位或狀態不完整。
- 以 `Txx + path + Git blob SHA + KR/TC target SHA + VA/raw/byte` 交付，只新添需要的 CLM/反證、受影響 SPEC、GAP 和離線/實測 TEST。須分辨 native、靜態衍生、Server 自訂政策。
- 未授權不得執行/修改原始遊戲與服務、動態探針或封包錄製；Server 實作在獨立 repo。不要自行 Commit/Push，除非當次用戶授權。

S00 完成從既存資料可得之範圍後，才決定是否真的需要 REA 任務；**本份是研究請求登錄與交接說明，不表示已派 Agent 執行**。
