# S00 → T02/T03/T04/T06/T01：登入至角色畫面與創角入口補證題單

**性質：可交接的研究導航，不是新的 RR 認領或正式研究回覆。** 任務 owner、既有 RR dispatch、T01 審查軸保持不變。只適用 KR 原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；TC 須獨立分析。

## 目標 A：登入至角色選擇畫面（先於世界轉場）

**已知有界 Client 事實**：本地 C2S E8/000F、LOGIN scene 的 S2C 0x0013/0x007A handler、選服 UI 到 key0/key2 Connect 的限定 gate、S2C 0x0002 global handler 的 65+53*N 記錄，以及 0x4D4150 對角色 UI 記錄旗標的局部寫入。**這些是相鄰靜態路徑而非一條已捕獲的 Server session。**

1. **T02／現有 RR-0001/0004/0005/0006/0007**：第一次實際送/收候選與 framing mode/connection slot/IOCP 狀態，標出哪裡僅能從本地 Client 證明而無法推出真實原版 Server 回覆；不要求 T02 重做 T03 GUI。
2. **T03／既有 RR-0003 與 RR-0002 受限清單子問題**：由 0x0013/0x007A 的有效 LOGIN scene/UI 通知、實際選服 gate 追查其後何種 Client state/scene 預備角色清單；從 cmd2 0x4B7F00 → 0x4D4150 到 dialog 消費者 0x672F00 的最低必要條件，以及 F4246、F4247、條件式 F4278 的 producer/consumer/event subscription 關係。注意既有 RR-0002 status BLOCKED，**不能由本題單擅自拆 RR 或修改其正式狀態**。
3. **T04**：角色來源權威、有效資料初始值/持久化策略與 UI 欄位必要範圍；來源中沒有官方 Server 數值不得用本地 LocalHero 假資料作歷史結論。
4. **T06**：角色畫面 control/dialog 與資源身分、存在條件、初始化完成旗標；record+0x5C 有資料不等於玩家看見畫面。
5. **T01/S00**：對確定阻擋實作的 branch/byte/handler 指令作定向 native review；評估 REQ-0001..0005 的實際可實作成熟度。不存在 Client runtime 證據前，維持「畫面已顯示」未證。

**驗收建議**：按登入成功／登入錯誤、角色名單非空／空、資料不足／合法初始化、已收封包但 handler scene 不存在等情形逐項列出 source/前提/結果/UNKNOWN；每一項必須分清方向、wire frame、app opcode、connection、UI 事件和實測地位。

## 目標 B：角色建立介面（尚未建立原生契約）

1. **T03**：從 login→角色畫面的必要條件與 UI 事件查「零角色、新增角色」各自怎樣開啟創角 dialog；不得預先認定零角色必自動跳創角。
2. **T03 + T04**：找到真正 **建立角色** C2S producer / S2C 成功錯誤 consumer，名稱、職業、外觀、資源 ID 與所有 opaque 欄位、帳號角色上限、保存/重取清單的真實 Client 限定前提。不把「選中既有角色」C2S command0x42 誤當角色建立。
3. **T06**：創角 UI 本地資源/選項/事件；區分 Client 控制與 Server 權威驗證。管理員要的限制、權限、取名政策屬 `PLAYER_ADMIN_REQUEST` 或經審核的 ADR，不是原版 Client binary 的既有 Server 規則。
4. **S00**：先查現有 Txx 新成果；若確有不同的 Client Server 收發需求，附精確 CLM 與未知再建 REQ，必要時開**不重複** RR/GAP。此文件不證明目前已有創角 packet 或由玩家提出了特定自訂需求。

## 目標 C：選角之後進世界（另列，不卡住 A/B 的分析）

RR-0002 真實 C2S 0x42→S2C success/error pairing 與 RR-0008 scene writer／EndCutScene 資源差異仍須繼續。S2C 0x42/0x43 handler 可達，不等於 server 官方配對，更不能從 Event/SceneList `(1001,1)` 推成第一個 network scene key。建議留給 `SLICE-ENTER-WORLD` 單獨驗收。

## 根據現有 repo 的來源

- [SPEC-FLOW-0001](../spec/session-account/SPEC-FLOW-0001.md)；[SPEC-CHAR-0001](../spec/session-account/SPEC-CHAR-0001.md)；[完整收發矩陣](../spec/session-account/phase-b-message-matrix.md)
- [T03 研究入口](../kr/tasks/T03/README.md)、[RR 唯一台帳](../research/requests/index.json)
- [需求台帳](../design/requirements/index.json)；[本次 delivery slice](s00-requirement-slices.json)

禁止在證據不足時自行創造新的 S2C opcode、Server-first wire order、授權/建角政策或 native success status。所有 3 種正式 REQ discovery 皆可提出需求，但來源類別不等於已核准。
