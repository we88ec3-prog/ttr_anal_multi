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


## 2026-10-31 S00 RR-0010 後續驗證（E71–E74；有界 Client 靜態研究，非正式 wire transaction）

[完整 S00 逐條審查](../../governance/s00-iterations/S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md)（PR #63，`extra/roy1`）。**此節更新 Iteration 21 歷史「RR 已 QUEUED/未知 create opcode」的現況，不刪改當時原始研究與狀態快照。**

- **建名是遠征隊／玩家身分，而不等於新增可操作角色。** T03 E73 在 `CExpeditionCreateDialog` 找到名稱 edit→本地 confirm `F4244`→有條件 **C→S inner `0x003E` 48B、slot0** 的 builder：opcode 在 `+0..1`，UTF-16 name buffer 起於 `+6`（21 WCHAR 容量，含終止字元）；`+2..5` 值 **UNKNOWN**，其餘未用 buffer bytes 不保證為零。所述精確 byte-level 證據來自 T03 作者的 KR BIN verifier；S00 本輪用已存反編譯交叉核對寬字元名稱/send，不冒稱親自重跑原始 BIN 或 T01 FULL-PASS。
- **候選結果消費**：LOGIN scene 有 **S→C `0x004A`** consumer，讀 signed word at `+2` → **本地** `F4245`；result `1` 可更新 `F938F2` 名稱及 UI，`-1/-2/-3` 各有分支但**不知官方含義**。缺少原版 Server 的 `0x003E↔0x004A` request–reply 配對及實際 Client scene/Conn 與 frame trace，**不是已完成官方建角 ACK 契約**。
- **清單共用名稱**：S→C `app2` header `+0x0C` 的 name copy 到**同一個** `F938F2`，名單 65B prefix + 53B/row；逐 row 可能送 C→S `0x26` 3B，結尾 `0x24` 2B。shared global 不等於 `0x004A→app2` 時序、創角成功或世界初始化。E75（RR-0002）找到的 S→C `0x26` 另是 4+5N consumer，**不能**將 C2S/S2C 的同值 opcode 視為已配對。
- **不同事件不可混淆**：`CEmployNewCharacter` 的 C2S `0x33` 僅2B、不含創角姓名；C2S `0x42` 是已存在角色 selection。既有 RR-0009 UI 入口、RR-0002 選角與 RR-0010 真正建角→roster 因果分離。
- **狀態不提升**：截至本次驗證 RR-0010 **BLOCKED**（非 ACCEPTED）、GAP-CHAR-0003 **OPEN**；本規格 **DRAFT/PARTIAL**。本節可供 Server-side 模型/合成向量設計，但不得硬填 `0x3E+2..5`、錯誤碼、初始數值或推定原版 request/reply/可遊玩。
