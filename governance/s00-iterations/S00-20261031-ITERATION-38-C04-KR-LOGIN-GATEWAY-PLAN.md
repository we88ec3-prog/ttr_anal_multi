# S00 Iteration 38 — C04-D／E／F 原版 Client 登入整合、TCP 日誌與角色畫面交付計畫

> **文件性質：NON_NORMATIVE_IMPLEMENTATION_PLAN；設計交接完成，Server 程式未實作。** 日期：2026-10-31（Asia/Taipei）。
> 研究基準：S00 main `ac3aa886e9fd20be93b6f841ada66fe22e587aa1`；Server main `284c1df16707834c5df64976ff8d1307e1906ae4`。KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。使用者截圖為 *Tartaros Rebirth* Client、顯示韓文「ERROR: 서버에 접속할 수 없습니다.」；**截圖 Client 的 EXE/BIN SHA、實際連線 IP/Port、是否有 TCP SYN 尚未獨立核對**，不得把截圖當成原版 KR 測試通過。
> 明確限制：**本輪不修改任何原版 Client、Server 原始程式、資料庫或啟動進程；不執行原版 Client 或動態網路探針**。本工作包在獨立 Server repo 後續經授權實作；這一份只記錄 S00 規劃與既有證據邊界。

## 0. 決策摘要：不是重做 C01，也不是等待 C05

目前 Server `src/Tartaros.Server.Host/Program.cs` 只有 C00 HTTP diagnostics `127.0.0.1:5080/health`，明示 `gameListener=false`，沒有啟動遊戲 Socket；WEB 管理 `127.0.0.1:5091/admin` 是**另一個 Host**。C01-A/B/C 已具 loopback `TcpTransportServer`、SyntheticFramedSession、queue/backpressure/timeout 等底層元件，但從未接進原版 Client 遊戲 Host。`FrameCodecCatalog.ForProfile(KrOriginalClient)` 仍回傳 `UnverifiedFrameCodec`；C04-A/B/C 對 frame、登入、roster 的純記憶體 probe 只作有限來源格式檢查，不是 runtime decoder/serializer；C02 帳號與 Session、C03 角色持久化是 Server-only 離線功能。

**原本 C01 有規劃 TCP；實際遺漏的是 C01→C04→C02/C03→原版 Client 的 Gateway 接入工作及其可觀察性驗收。** 因此本次明確新增**建議開發工作包 C04-D、C04-E、C04-F**，不新建 C05-Pxx、不把健康檢查／合成 CI 當 native 相容成功。三組編號在本次核對的 Server main docs 僅見 C04-A/B/C，仍應在 Server 開工前檢查最新 main 有無他人新設 D/E/F 的衝突。規劃 ID 不等於已建立 GitHub PR、已核准 runtime 功能或已實作。

## 1. 既有 Server 與規格來源差距

| 責任層 | 現有可復用內容 | 缺少的 Client 可用功能 | 來源／阻塞 |
| --- | --- | --- | --- |
| Host/TCP | C00 HTTP `/health`；C01 `TcpTransportServer` loopback synthetic | 可配置且明確 opt-in 的 **遊戲 Listener**、accept/close/error，不能預設啟動外網 listener | Server `Program.cs`、`TcpTransportServer.cs`；C04-D |
| 診斷 | C01 socket 測試、HTTP diagnostics | per-connection **持久化 TCP RX/TX 安全日誌**，失敗原因、Port 佔用、分段讀寫與關機 flush | 本次維護者 TCP 日誌需求 `REQ-0009`（CANDIDATE） |
| Framing | C04-A `KrSourceScopedOfflineFrameProbe`，1A68/0BBB 有界；C01 synthetic codec | 目前 Client 的第一個 frame、mode/marker、unknown/retry、可靠的選擇規則與 runtime codec | RR-0001/0004/0006/0007；GAP-NET-0001/0003；C04-E |
| 登入 | C04-B 本地 E8 112B/000F 214B 結構檢查；C02 Account/Session | 真實 C2S→認證對接、字元編碼／opaque bytes、正確 request pairing | RR-0003；GAP-AUTH-0001；C04-E |
| 登入回覆 | LOGIN scene 0x13/0x7A 客戶端 handler 有界 | S2C 實際回覆配對、成功／錯誤 status 與可讀 header/child 資料，Scene gate | RR-0003/0007；GAP-AUTH/FLOW；C04-F |
| 選服與切線 | Client `806AD0` 分別找到 8415 slot1、8416 slot0、8414 slot2 的靜態 callsite；RR-0005 限定研究 ACCEPTED | 實際 Client Build 的 endpoint/連線順序、UI 選服觸發、Connection/Session handoff，不能由靜態埠號推定部署 | GAP-NET-0002 OPEN；C04-F |
| 角色畫面 | C03 create/list/select；C04-C 角色清單 app2 `65+53N` 的局部 record geometry | 完整 prefix、初始化事件、可見/可操作 UI 的正向鏈；N=0 不等於自動創角 | REQ-0003/4、RR-0002/9/10；GAP-CHAR/FLOW |
| 世界戰鬥 | C05 P01～03 已完成 Server mock 的既有程式與 CI | 與能否先到角色清單**無依賴** | 不納入 D/E/F 範圍 |

**本次僅為規格與實作交接，沒有修改正式 `SPEC-NET/AUTH/CHAR/FLOW` 的 DRAFT/PARTIAL 或原版 KrOriginalClient codec 狀態；所有 Client 可互通聲明仍是 NOT_VERIFIED。**

## 2. 工作包與相依 DAG

### C04-D — 原版遊戲 TCP Gateway 診斷骨架與收發檔案日誌（可立即做 Server-only）

- **D-01｜版本與 Endpoint preflight**：用可下載／可自行執行的 Windows 檢查步驟核對玩家本機 EXE、BIN SHA256、Client endpoint 的可信來源及目前監聽埠；結果存去敏檔，不要求使用者先修改 EXE、hosts 或網路設定。靜態 KR 8414/8415/8416 **只是候選**，不可假裝 Rebirth Build 一樣。
- **D-02｜明確 opt-in Loopback Gateway**：基於 C01 的成熟 TCP/超時/佇列元件，建議新 `KrDiagnosticGatewayHostedService` 或等價獨立程序；預設 game gateway OFF；只能以明確 `KR_DIAGNOSTIC_ONLY` 啟用指定 `127.0.0.1:port`。須防止 HTTP 5080、Admin 5091、其他服務的 port 衝突；Bind 失敗記錄錯誤並 fail closed，不能悄悄換到別的 port。支持 graceful stop、cancel、重啟、連線上限、bounded RX 和檔案權限檢查。
- **D-03｜TCP 事件追蹤**：同一 run ID 與 connection ID 串接 ACCEPT、RX_CHUNK、TX_START/COMPLETED、DISCONNECT、CLOSE_REASON、PARSE_STATE、ERROR、QUEUE_SATURATED、LOG_DROPPED。Read 是 TCP stream chunk，絕非自然「一 read 一包」；`TX_WRITE_COMPLETED` 不等於 Client ACK。
- **D-04｜日誌可保密與可維運**：建立 `logs/game-tcp-YYYYMMDD.jsonl`（建議樣式，實際名稱可由 Server 管理者配置），有界背景 writer、輪替、保留、容量上限、ACL/Gitignore、磁碟滿及壓力處理。預設只寫連線／長度／解析狀態，絕不寫原始登入 payload、密碼、Session bearer token 或雜湊。開發用 Hex trace 僅在*已核准的 redaction map*和 localhost opt-in 下顯示確定安全的 fixed headers；**未知首包、E8/000F、無遮蔽 schema 的 frame 完全不得輸出 raw bytes**。密碼字串及 UTF-16 變體必須在正常日誌、例外和輪替檔都不出現。
- **D-05｜診斷而非假登入**：即使 Client TCP 連入，此階段也不送猜測的 LOGIN/Server-first packet；不改 `FrameCodecCatalog` 將 KR 宣稱 VERIFIED，不建立持久帳號 Session，不宣稱角色畫面可達。
- **D-06｜Host 接口**：`/health` 必須分離 `httpAlive`、`gameListenerEnabled`、`gameListenerBound`、`gameProtocolProfile`、`nativeContractStatus` 等欄位；當 diagnostic listener 未上線時保留既有健康服務語意，不能標 AuthReady/WorldReady。避免將 local Admin WEB/health 認作 game listener。
- **D 的 PASS**：本機指定 Port TCP connect、fragmented reads、multiple sockets、shutdown、rebind error、timeout、日誌截斷與遮蔽/rotation/磁碟滿測試通過；**只有 synthetic/loopback transport 及觀測性完成，不算原版 Client NET-02。**

### C04-E — KR frame、分派與 C02 登入 Adapter（按證據分期）

- **E-01｜原生 frame 契約補證**：T02 對 RR-0001/0004 找 first exchange、`Conn+A02C` mode/indirect writer、1A68/0BBB/0x2633/0x22D7/unknown branch；須明確列 client build、direction、socket slot、pipeline、marker、byte extent、對應 scene、錯誤／短包及不同 runtime 分支。S00/T01 接受的**限定範圍**才可用於 opt-in KR runtime adapter。
- **E-02｜per-connection state machine**：建議 `Accepted→FirstBytes→FrameDecoded→LoginRequestValidated→Authenticated→ChoicePending`，其中每一步有 fail-closed timeout/abort；未知 Client Build/first marker 不進 Auth。必須防 frame 不完整、粘包、負長度、解壓比無界、checksum、未授權 opcode/scene、錯 lane/slot、memory bounds。
- **E-03｜Dispatcher**：由 `SPEC-NET-0003` + RR-0007 的已審核成果建立真正的 frame→channel/pipeline→app opcode→LOGIN handler 解析，不能把帧 marker 當 app command，也不能靠 C04 offline probe 的 test-only Unsupported 行為推成 Client 原生策略。
- **E-04｜C2S 解析與 C02 facade**：區分本地 mode 0x52 的 `E8/112 bytes` narrow 與 mode 0x54/other 的 `000F/214 bytes` UTF-16；E8 六個 opaque bytes `+104..109` 不能自動當零，CodePage=0/CP_ACP 與 FBA808 runtime writer 必須依 build 判定。只在受信來源、schema 合法且已核可的相容入口，才向 C02 帳密、停權、Session lease 執行 Server-side 認證，避免任意截取入站 bytes 變成帳號密碼。
- **E-05｜驗收分開**：合成 request → C02 auth service 只算 Server offline；真正 KR Client request → sanctioned gateway → C02 狀態，需 source/runtime 雙層證據。不能因帳密正確就自行發 S2C0x13 或推斷 Client 已成功。
- **E 的阻塞**：真 first mode、完整 C2S、連線順序、scene 選擇以及必需原生錯誤/回覆契約仍待 T02/T03，正向不閉合不得啟用 `KrOriginalClient` 正式 profile。

### C04-F — S2C 登入回覆、選服切線、C03 角色清單與 UI 驗收（按證據分期）

- **F-01｜登入結果 builder**：T03 RR-0003 的 `S2C0x13` 在 LOGIN scene +0x16 status（0 且 name 非空為局部成功，5 為專用失敗）、group count +0x1C/child cursor +0x92；`S2C0x7A` group count +2/child cursor +6，兩者**互不等價，也未證必要先後**。只有確定 request↔result 與完整必需欄位，才實作版本鎖定的 success/reject 並做 Client 可觀察判定。
- **F-02｜錯誤狀態與可控失敗**：帳號不存在／錯密碼／停權／會話失效／重複登入／資料庫 unavailable／scene 不符各記內部 code；外送 KR 真實 status/text 必須有源據，避免把所有失敗回覆成 unknown 或公開帳號是否存在。禁以 HTTP 500 與韓文 Client 顯示直接一對一配對。
- **F-03｜選服資料與 handoff**：群組 row 規則是 3 bytes/group + 10 bytes/child，`+4..7` 候選 IPv4 octets，`+8` 路徑 gate、`+9` 非 padding；只按已審核的 builder 輸出與真實選服 source。T02 RR-0005 ACCEPTED **只代表有限 handoff 研究接受**，GAP-NET-0002 持續 OPEN；Client `F4241` 是本地事件，不是切線命令。Session lease/generation 的一次性綁定、舊 Session 防重入/斷線清理應沿 C02 交易政策設計。
- **F-04｜角色清單 adapter**：使用 C03 的 owned selected role/查詢資料，依 C04-C 局部 `S2C app2 65+53N` geometry 及後續原生修正保守編碼；零筆、單筆、多筆、短包、未終止字串、UI event 及同版資源做獨立測試。`65+53N` 只是有限 Client handler 幾何，尚不足以保證所有 prefix byte 或 Client 可操作。
- **F-05｜UI ready 真正驗收**：角色 record `+0x5C` 被更新不能等同 dialog visible/interactive；RR-0009 的 ACCEPTED 僅是「阻塞證據交付」，`GAP-CHAR-0002 OPEN`。若當期目標只到**既有角色名單畫面**，不用讓創角整套 RR-0010 成功，也不用完成 C05 教學。
- **F-06｜實機 Client**：只能在使用者另外明確授權且有指定 Client build、安全測試帳號、localhost、診斷資料去敏後執行。到畫面以前 Gate 按 NET/AUTH/FLOW/CHAR/UI 個別判，不允許用 synthetic PASS 偷換真 Client。
- **F 的阻塞**：RR-0003/0007/0002 部分、實際 S2C 配對與角色 UI 場景資料；RR-0008（進教學）非「顯示角色清單」的必要依賴，不能為了 C05 延宕登入。TC 要另套 SHA 和獨立 SPEC，不可套 KR。

**依賴：`C01-A/B/C→C04-D（D-02與D-04可並行）→C04-E（T02 first-wire與T03 auth evidence）→C04-F（T02/T03 S2C/choice、C03 role、T03/T06 UI）`。C04-D 可單獨進 Server 開發；C04-E/F 可先做不啟用正式 adapter 的純記憶體 API/資料模型測試。C05-P04 是另一平行工作線，不阻塞登入。**

## 3. TCP 日誌需求：REQ-0009（CANDIDATE，Server-owned）

使用者要求「另外 Server 可能需要紀錄 log 檔紀錄 TCP 的收發」。這是確實提出的管理/維運需求，不是 Client 機器碼的規範。登錄為 `REQ-0009` CANDIDATE（與 REQ-0005 的 frame 相容性**驗收不同**，因此新增而不複製同一 REQUIREMENT）；原始語意及正式與建議的區分見 `design/requirements/requests/2026-10-31-game-tcp-observability.md`。

### 3.1 建議事件與 JSONL 欄位

- 事件：`GATEWAY_START`、`LISTEN_OK/FAILED`、`ACCEPT`、`RX_CHUNK`、`FRAME_INCOMPLETE/DECODED/REJECTED`、`APP_DISPATCH`、`AUTH_DECISION`、`TX_ENQUEUED/WRITE_STARTED/WRITE_COMPLETED/WRITE_FAILED`、`DISCONNECT`、`TIMEOUT`、`LOG_DROPPED/FILE_ERROR`、`GATEWAY_STOP`。
- 建議欄位：`ts_utc`、`run_id`、`connection_id`、`local_endpoint`、`remote_endpoint`（內部私密保護）、`direction`、`phase`、`bytes_count`、`frame_marker`（可靠驗出才填）、`app_opcode`（可靠驗出才填）、`correlation_id`（opaque 非 bearer token）、`error_category`、`socket_error_code`、`duration_ms`、`server_commit`、`profile`、`log_policy_version`。缺證時寫 `null`，不憑猜想附 opcode。
- 安全預設記錄 RX/TX 的**bytes count、時間與結果**而不是 payload；`TX_WRITE_COMPLETED` 不是 Client 應用收到或 ACK。對 Client 未連入前的「SYN 是否發出」須靠 OS 診斷／另外授權的捕捉判斷，Server 本身不能記錄沒有到達 listener 的 Client 封包。
- 若因開發需要 Hex：必須另外 opt-in、localhost、明確同版已審核的 redaction policy（僅限安全固定 header）；不認識的首包或 E8/000F 必須完全禁止 raw dump。log parser 應做 JSON escape、ACL/rotate/retention/cap，禁止路徑穿越、憑證洩漏和非同步無界佇列。

### 3.2 可被診斷而不能猜想的錯誤分類

| 已有來源支持的觀測點 | 內部 error-category 候選（**非原版 Client 錯誤碼**） | 分界 |
| --- | --- | --- |
| TCP bind fail | `LISTEN_FAILED`／OS error 10048 等 | 未必是 Client 關係；需檢查 Port |
| 沒 accept | `CONNECT_TARGET_UNOBSERVED`（僅用於診斷結論） | Server 不可能由沒有接入的 Client 假證「密碼錯」 |
| accept+0 RX | `FIRST_BYTES_TIMEOUT` | 不推定 Client 一定先送 |
| 收 bytes 但未授權 codec | `UNSUPPORTED_PROFILE/FIRST_FRAME` | 不推定 1A68/0BBB 必為第一包 |
| 已驗 frame 格式錯 | `FRAME_INVALID`、`CHECKSUM_INVALID`、`SIZE_EXCEEDED` | 源 native 异常與自設 Server 防禦分開 |
| 已解析登入、帳密錯 | `INVALID_CREDENTIALS`（對外需避免枚舉） | 只有正式 C02 呼叫才能判 |
| 已認證但 UI 不動 | `ROSTER_UI_UNVERIFIED` | TX completed ≠ Client scene ready |

## 4. Client 原生研究交接：不建重複 RR

| 現有正式 RR | 最新 state | 精確需要的原生 Client 成果 | 後續影響 |
| --- | --- | --- | --- |
| RR-0001 / RR-0004 | IN_REVIEW / IN_REVIEW | T02：第一個有效 C2S/S2C、mode/marker、Conn+A02C、間接 writer、slot/pipeline、方向別排除反例 | E-first-frame；GAP-NET-0001 |
| RR-0005 | ACCEPTED（僅有界研究） | T02：login result→UI selection→key0/key2 connect 先決條件與 runtime endpoint 欄位；原服順序未證 | F-handoff；GAP-NET-0002 OPEN |
| RR-0006 / RR-0007 | IN_REVIEW / IN_REVIEW | T02：壓縮/checksum/入站 pipeline→LOGIN scene/handler、短包／錯誤分支 | E-dispatch；GAP-NET-0003 |
| RR-0003 | IN_REVIEW | T03：E8/000F 真正 runtime path；0x13/0x7A 正負配對、status/群組、編碼與 E8 六個 opaque bytes | E-auth / F-response；GAP-AUTH-0001 |
| RR-0002 | BLOCKED | T03：selected role／post-roster 初始化，未證 wire 成功/拒絕 | F-roster UI 部分；GAP-CHAR-0001 |
| RR-0008 | IN_REVIEW | T03：0x42 進教學與 scene key，**不阻塞本輪角色畫面目標** | 延至世界登入 |
| RR-0009 | ACCEPTED（限定 blocker study） | T03/T06：N=0→dialog visible/enable/source 的正向缺口仍在，GAP-CHAR-0002 OPEN | F 空名單畫面另 gate |
| RR-0010 | BLOCKED | T03：真正 playable character create C2S→S2C→roster，**不在已有角色顯示最小目標** | 後續創角完整可玩 |

T01 獨立核對關鍵 byte/CFG／來源 SHA，不能因上面 RR 研究交付或 S00 文件可讀便改成全文 FULL-PASS。S00 不改上述 RR 正式狀態、其它 Task owner 或 Client 研究原稿。`GAP-NET-0001/0002/0003`、`GAP-AUTH-0001`、`GAP-CHAR-0001/0002/0003`、`GAP-FLOW-0001`、`GAP-SCENE-0001` 均保留 OPEN。REQ-0001/2/3/4/5 仍是已存在的相容需求，不複製；REQ-0009 只新增獨立 Server TCP 安全日誌候選。

## 5. 驗收層級與 Gate（**全部為規劃：NOT_RUN**）

**四個不同真相：** (a) DESIGN_READY 只有規劃；(b) SOURCE_SCOPED 只有 Client 靜態有界證據；(c) SERVER_OFFLINE_PASS 為自設 Server 單測／合成 TCP；(d) CLIENT_RUNTIME_PASS 必須另外授權 Client 真實連線與 UI。無論 GitHub Actions CI 綠燈、`/health` 200、P03 mock 測試 PASS，均不能冒稱 (d)。

| Gate | 需要的可稽核驗收結果 | 前置 |
| --- | --- | --- |
| BUILD-01 | 本次用的 Tartaros.exe / Tartaros.bin SHA256、設定來源與分析版本相符或明確另立版本 | D-01 |
| NET-01 | 指定可允許 localhost Port bind / fail / stop / rebind、真正可連的 synthetic socket | D-02 |
| LOG-01 | 建立連線、RX/TX/斷線事件的 JSONL timestamp、ID、方向正確 | D-03/D-04 |
| LOG-02 | 1 frame 拆多 read、1 read 含多 frame，日誌分辨 chunk 與 decoded frame | D-03 |
| LOG-03 | OS write success+Client close，**不得記成 Client 已受理/顯示** | D-03 |
| LOG-04 | 人造 E8/000F 的密碼/UTF-16 marker 不得出現在 jsonl/hex/exception/rotation | D-04 |
| LOG-05 | unknown marker/truncation/too-large/parse fail 各留原因、不猜 app opcode | D-03/D-04 |
| LOG-06 | 兩個連線競態、磁碟滿、權限拒絕、rotation、重啟，bounded queue與drop counter | D-04 |
| LOG-07 | 可分享的診斷包遮蔽 IP/個資/ticket，不含任何私密原始資料 | D-04 |
| NET-02 | 指定**正確** Client Build 實際 TCP 連入同一 endpoint、並有 matching accept 或有解釋的失敗證據 | D-01/D-02，另行實測授權 |
| NET-03 | 具版本與方向的首次 frame 可 decode、malformed tests 和 S00/T01 evidence | E-01..03 |
| AUTH-01 | Client 真正 C2S app 正確解析到已審核的 request／C02 account 交易 | E-04 |
| AUTH-02 | 有來源的 S2C 成功、Client 實際進入下一個已觀察狀態 | F-01 |
| AUTH-03 | 錯帳密/停權的 Server domain 差異、正確 Client-compatible 失敗視圖、不洩漏憑證 | F-02 |
| FLOW-01 | session 綁定跨選服及 socket/重試/切線、舊租約拒絕 | F-03 |
| CHAR-01 | 0/1/N 角色列表的 Server→Client 正確內容與所需本地初始化 | F-04 |
| UI-01 | 原版 Client 實際顯示**有角色、可操作的選角畫面** | F-05/F-06 |
| UI-02 | 原版 Client **零角色→可操作創角入口**，**不與 UI-01 混算** | RR-0009 的剩餘正向缺口 |

每個結果保存：`gate_id`、`evidence_class`、`client_build_sha256`、`server_commit`、`s00_commit`、`provider`、`run_id`、`connection_id`、`fixture_digest`、`log_file_sha256`（限可分享、安全日誌）、`expected/actual`、`negative_counterexample`、`status`、`native_gap`；不記實際帳密、bearer token、私有抓包到 GitHub。

## 6. Server 開發交接／進度與解除阻塞

1. **立即可交給 Server 開發者：C04-D**（新 Listener opt-in、日志、單純收發、安全故障），重用 C01，不動官方 codec；獨立 branch 不自動建立，遵守使用者主線政策。先做失敗或無 Client 的診斷也有價值。
2. **平行由 T02/T03 補 source：**只查現有 RR 的精確 Client-first frame、LOGIN scene/封包及切線/UI；需要新狹義研究且與既有 RR 真正不同時才由 S00 新建。
3. **C04-E／F 只能逐段開啟 native：**純內部 API/合成 fixture 可先測，真正 KrOriginalClient runtime profile 的啟用必須有版本匹配的 direction/field/state、S00/T01 review、負向安全測試和 explicit opt-in。未知必須 fail closed。
4. **驗證策略**：先 Server offline CI（.NET unit、protocol、integration、reconnect、SQLite/PG 分開）、再經授權 real Client 的 NET-02→NET-03→AUTH→FLOW→CHAR→UI 分別驗收。任何失敗寫最小去敏回報 `docs/FEEDBACK.md`；沒有新可證 wire 就保留正式 GAP，不編假的成功回應。
5. **互不阻塞**：C05-P04 普攻／連段開發不依賴本工作包；但未來要宣布原版 Client 可玩必須獨立經過 Client gateway/UI。Admin WEB 5091、HTTP 5080、game Listener 是三個獨立角色，避免借用管理 API 作遊戲封包。

## 7. 下輪保留的政策決定（不在此份規劃擅自批准）

- C04-D 的實際 listener Port/IP（預設 OFF+localhost；不可由歷史 KR 8414/8415/8416 自行全開）；建議配置項與操作維護人由 Server repo 決定。
- Log retention、rotation size/total disk budget、ACL、敏感欄位摘要與故障時 fail/continue 的精確上限（Server-owned operation policy）。
- Runtime Client build identity 判定、KR profile feature flag/kill switch、錯誤回覆 mapping、Session takeover/duplicate login、channel/choice handoff policy；均不得無來源擅自聲稱官方原版規則。
- 對原版 Client 的真正動態測試、Client 視窗及封包抓取應有另行明確授權，且不包含修改原版 Client 或連接原版官方線上服務。
- SPEC-NET/AUTH/CHAR/FLOW 仍 DRAFT/PARTIAL；REQ-0009 仍 CANDIDATE，並不因本文件 commit 就自動 APPROVED／Server shipped。

## 8. 完整來源及既有 S00 追溯

- S00：`spec/protocol/SPEC-NET-0001.md`、`SPEC-NET-0002.md`、`SPEC-NET-0003.md`；`spec/session-account/SPEC-AUTH-0001.md`、`SPEC-CHAR-0001.md`、`SPEC-FLOW-0001.md`；`governance/s00-lobby-gates.json`、`governance/s00-iteration12-lobby-test-plan.json`；`governance/s00-iterations/S00-20261031-RR0009-RR0010-REVIEW-AND-HANDOFF.md`。
- 正式唯一索引：`design/requirements/index.json`、`research/requests/index.json`、`design/gaps/index.json`、`conformance/test-index.json`。不增加 RR/GAP/正式 TEST 或新 native claim。
- Server：`src/Tartaros.Server.Host/Program.cs`、`src/Tartaros.Network/TcpTransportServer.cs`、`src/Tartaros.Network/SyntheticFramedSession.cs`、`src/Tartaros.Protocol/ProtocolProfile.cs`、`docs/C01-A-IMPLEMENTATION.md`、`docs/C04-A-IMPLEMENTATION.md`、`docs/C04-B-IMPLEMENTATION.md`、`docs/C04-C-IMPLEMENTATION.md`；`contracts/spec-revision.json` 原生 wire 仍不核准。
- 歷史規劃：Iteration 12 Lobby 測試、Iteration 16 新帳號到教學 E00-E12、Iteration 33 C05-P01～19，這次**不改舊 Gate 或 P 編號**。本次因真人畫面提醒缺少 Gateway 端到端開發整合，新增 C04-D/E/F 只是補明確交付路徑。
