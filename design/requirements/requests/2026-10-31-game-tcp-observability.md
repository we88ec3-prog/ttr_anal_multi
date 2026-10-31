# 2026-10-31 — 遊戲 TCP 收發檔案日誌：使用者需求登記

**來源類別**：`PLAYER_ADMIN_REQUEST`；`requester_role=ADMINISTRATOR`。這是相容 Server 的使用者需求，不是原 Client 源碼證據、原版 Server 規則、已獲核准的維運政策或動態執行授權。

## 使用者原始要求

> 另外Server可能需要紀錄log檔紀錄TCP的收發

隨後使用者要求：

> 請規劃完成上git

此處只正式登記 **`REQ-0009`、狀態 `CANDIDATE`**。使用者說「可能需要」，沒有指定正式保留期、容量、是否完整儲存每個封包或允許公開網路；這些由 S00 提出安全的 Server-only 建議，尚非維護者已批准的營運部署設定。

## 去重與職責

- `REQ-0005` 處理 Client 可解碼的原生 framing／接收錯誤，沒有要求持久且可查詢的遊戲 TCP RX/TX 檔案日誌。兩者驗收結果不同，故獨立新增。
- `REQ-0006` 是 **Web Admin** 的 IP/Host 管理入口與稽核；與遊戲 Gateway 連線診斷不同，不得混入玩家認證資料。
- Client 原生 first wire/LOGIN/handoff 問題沿用 `RR-0001/0003/0004/0005/0006/0007`，不得建立重複 RR/GAP。
- 本需求不依賴 KR 或 TC 特定 binary 內容，所以 requirement 版本為 `client_version=null`，不據此宣稱任何原生 opcode。

## 可先開發的最小安全規格

1. 由 Server 記錄每個 Gateway 的 start/stop、listen/error、accept、RX chunk、TX enqueue/write、close、timeout 與有限解析狀態；每筆有 UTC、runId、connectionId、方向、長度及事件結果。
2. 預設採 JSONL **安全元資料**，絕不記錄明文密碼、可能的 Session token、Account credential/hash 或未知 raw payload。Hex 診斷需隔離 localhost、另行 opt-in、可核對版本和完整遮蔽規則；遇未知 frame 或 E8/000F 登入內容無法安全遮蔽時禁止 raw dump。
3. 異步寫入、bounded queue、丟失計數、檔案輪替、容量上限、權限/ACL、磁碟故障處理與重啟恢復都必須驗收；具體保留天數／磁碟配額需 Server 維護者明確批准。
4. 日誌可用於觀察 Client 連線失敗，但**TCP 收到/寫入成功不等於原版 Client 已登入或畫面顯示成功**；不得自行執行原版 Client、收集私人憑證或公開私有抓包。

完整 C04-D／E／F [開發規劃](../../../governance/s00-iterations/S00-20261031-ITERATION-38-C04-KR-LOGIN-GATEWAY-PLAN.md) 與 [18 Gate 驗收矩陣](../../../governance/s00-iterations/S00-ITERATION-38-C04-LOGIN-GATES.json)。
