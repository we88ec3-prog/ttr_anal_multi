# SPEC-CHAR-0001 — KR command 2 角色清單有限契約

**DRAFT / PARTIAL**｜KR SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。資料形狀僅在有效資源/狀態且路徑進入 0x4B7F00 角色迴圈時適用。

共享 dispatch handler index 2 對應這個消費者。完整 payload = **65-byte prefix + 53-byte records**；第一筆起點 +65；完整筆數為 floor((payload_len-65)/53)。**另一個 0x4E2730 consumer 用的是 2-byte prefix**，尚未確認命令號，不可混用。64-byte 以下不代表原版會安全拒絕，因為此前已有 header 讀取。

| Record offset | 有限 Client 消費 | 未知 |
|---|---|---|
| +0 | NUL 終止 UTF-16 name copy | 名稱政策/容量防護 |
| +0x2A | u32 → UI+8 | 正式業務意義 |
| +0x2E | u8 ID（觀察比較 <=9 且有效目標指標），→ UI+4 | 官方合法 ID 集合及去重 |
| +0x2F | u8 → UI+0xD4 | 業務意義 |
| +0x30 | u8 → UI+0xDC | 業務意義 |
| +0x31 | u32 → UI+0x50 | 業務意義 |

0x4D4150 對有效記錄寫入 UI+0x5C=1，只證明此記錄可用旗標，**不代表畫面刷新、成功選角或世界轉場**。清單後還會有初始化請求（包含 26+ID），回覆配對不完整。選角 command42 的完整請求/回覆仍缺。

`conformance/character/` 為人造記錄格式的測試，不是真實回覆或角色合法性。保守拒絕未終止 name／短 header 是**測試器政策**，非原版確認行為。

來源：`CLM-CHAR-0001`、`CLM-CHAR-0002`（PARTIAL）；`kr/evidence/7a594f0ba64354a1c22fa2a6fe22f45e3a29699fb2bf5f73c2023e8113b9cac7.txt`；`GAP-CHAR-0001`、`RR-0002`、`TEST-CHAR-0001`。

## Iteration 21 — 創角入口與交易缺口（2026-10-31，DRAFT／非封包契約）

- `GAP-CHAR-0002`／`RR-0009 (QUEUED)`：目前沒有證明 KR Client 從 `command2 N=0` 或「新增角色」控制器到**可操作的創角對話框**的正向 scene/dialog/callback 鏈。T03 研究 UI event/scene gate，T06 協查同版本資源。UI 本地事件不等於 Client↔Server message。
- `GAP-CHAR-0003`／`RR-0010 (QUEUED)`：目前沒有可核定的建立角色 C2S builder 與 S2C 成功/拒絕 consumer 配對、方向別 layout、slot/frame/encoding、創角後 roster/init 時序；T03 為研究主責，T04/T02 提供欄位/transport 介面。
- **選角不是創角**：既有 C2S `0x42` 是選中既有角色的有界 Client builder；`RR-0002 BLOCKED` 處理選角結果，`RR-0007 IN_REVIEW` 處理 dispatcher，`RR-0008 IN_REVIEW` 處理選角到場景。新請求不得替代它們，也不能借用 S2C `0x42/0x43` 當創角回覆。
- **可實作限制**：此時只能做獨立的 Server-side domain mock / adapter fail-closed 設計，不可硬編任何未證的 Create opcode、初始數值、官方回覆結果或直接宣稱原版 Client 可以創角。正式台帳與原 Client 執行授權各自獨立。
