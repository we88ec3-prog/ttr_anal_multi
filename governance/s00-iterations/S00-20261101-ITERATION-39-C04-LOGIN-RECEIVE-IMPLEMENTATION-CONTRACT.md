# S00 Iteration 39 — C04 原版 Client 登入接收／驗證可開發契約與逐步交付

**日期：2026-11-01／範圍：S00 規格設計與獨立 Server 開發交接；不是程式碼或原版遊戲相容完成。**
**基線：** S00 `main=edc11830d184165ee6d09632b35927bbd713c2d7`、`ttr_server_roy/main=284c1df16707834c5df64976ff8d1307e1906ae4`，KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。Client 截圖上顯示 Tartaros Rebirth，**不代表 EXE/BIN 與上述 SHA 同版**，目前沒有此 Client 真正 TCP trace。
**類型：** `NON_NORMATIVE_SERVER_IMPLEMENTATION_CONTRACT_PLAN`；`READY_TO_IMPLEMENT_OFFLINE_DIAGNOSTIC` 與 `BLOCKED_BY_NATIVE_CONTRACT` 分級。本文新增開發階段細項，不把 DRAFT/PARTIAL SPEC 改為 STABLE、不更動 RR/GAP、沒有進行 Client 執行／原版 Server 連線／抓包、不修改其他 Task 原稿。

## 0. 直接回答：目前規劃到哪裡、這一輪新增何物

Iteration 38 已**宏觀規劃**：C04-D「原版遊戲 TCP Listener + 日誌」、C04-E「Client frame/登入請求 → C02」、C04-F「登入結果/選服/角色清單」。截至本文基線 Server：
- `Tartaros.Server.Host/Program.cs` 僅啟動 HTTP `127.0.0.1:5080/health`，且報 `gameListener=false`。
- C01-A/B/C 的 `TcpTransportServer`、`IConnection` 已有 loopback accept/receive/send/關閉、限流；`SyntheticFramedSession` 只接受 `OfflineSynthetic`，**不可將它的 codec 當作 KR Client 登入**。
- `FrameCodecCatalog.ForProfile(KrOriginalClient)` 返回 `UnverifiedFrameCodec`。C04-A/B/C 都是**純記憶體離線檢查**，不會把原版 Client 的 socket 流自動轉為登入成功。
- C02 `LocalLoginCoordinator.AuthenticateAndClaimAsync(name,password,connectionId,lifetime)` 可調用受信 `ILocalAccountDirectory` 與 `ISessionLeaseRegistry`，但原始碼註明需**獨立安全審查與 S00 契約准入**才可用於 TCP。C02 的內部 ConnectionId 為 `Guid`，C01 `IConnection.Id` 是 `long`，須建立 Gateway-owned 穩定轉換／映射，**不可直接強制型別轉換或把 Client 自報值當 authority**。

**此次新增：C04-D1/D2/D3 與 C04-E0/E1/E2/E3、F0 最小登入回覆，以及逐 Gate／API／日誌／錯誤／安全／測試。** 最終期望是一個分級驗收鏈：`TCP_ACCEPTED → RX_BYTES_OBSERVED → FRAME_DECODED → LOGIN_REQUEST_VALIDATED → C02_AUTH_DECIDED → RESPONSE_SENT → CLIENT_LOGIN_OBSERVED`。前五步屬「Server 已接收並處理登入」，最後兩步是「Client 真正登入成功」必要但**目前尚有原生證據阻塞**。**不要只完成 Listener 就宣稱登入完成。**

## 1. 來源範圍：已證的 Client 部分 vs 必須保留的未知

| 功能 | 可用的有限來源 | 尚無完整契約（嚴禁猜測） |
| --- | --- | --- |
| Client socket/Port | KR `SPEC-NET-0002`、T02 0x806AD0: 8415(slot1/pipeline2)、8416(slot0/pipeline2)、8414(slot2/pipeline2) 的**三個條件式靜態 callsite** | 截圖 Rebirth Client 的真實 endpoint、DNS/launcher config、哪個 Port 首連、有無 Server-first greeting、Client socket 重連先後 |
| Frame sender/receiver | `SPEC-NET-0001`、`C04-A`：本地 writer 1A68／0BBB 的 limited header、XOR/checksum；本地 inbound 0x2633 等條件 | 第一個實際 wire frame marker/mode、不同方向是否同規則、Runtime Conn+A02C writer、未知/短包實際 Client 行為 |
| Login payload | `SPEC-AUTH-0001`、T03 RR-0003 局部 `C2S0x00E8=112B`（mode0x52、narrow 51B slots）、`C2S0x000F=214B`（mode0x54/other、UTF-16 51 unit slots），均在 Client 本地 manager queue slot1 | 截圖版本必選哪條、真實 runtime 封包到達、E8 +104..109 六 opaque bytes、CP_ACP 會依主機而變的字元行為、正式帳號憑證語意 |
| Client 結果 | LOGIN scene handler S2C app0x13、0x7A；0x13 +0x16 status0且 UTF-16 名非空為**局部 success path**，5 為另一失敗分支；group cursor 0x13+0x92/0x7A+6 | 「C2S E8/0F 必然回 S2C0x13」未證；完整回覆 layout、原版 success/failure status 意義、Server-first 或選服交換次序 |
| Backend | C02 local account/session、C02-D account ban/revoke、C03 role list 有 Server-owned domain | 原版 Server 真實帳密演算法、session ticket、KR 密碼 policy，不能以 C02 的 ASCII 3–32 username、12–128 password 判為 Client 官方限制 |

**本文件只引用已核對的 S00 正式 SPEC、Server 已存在 API、RR 狀態。** 未重跑 KR BIN，T01 原生 FULL-PASS 軸獨立；RR-0005 限定 ACCEPTED 不代表真登入/切線。

## 2. 端到端最小垂直切片與工作包（可獨立提交／驗收）

| 序 | 編號 | 責任／可交付物 | 實作條件 | 在本階段能證明什麼 |
| --- | --- | --- | --- | --- |
| 1 | **C04-D1** | 配置/Host startup：`GameGatewayOptions`、localhost opt-in、依實際 Client Build 確認的目標 IP/Port；單一由 Host 管理的 `IHostedService`，不影響 5080/5091 | **現在可開發** | Server 指定 port bind/listen/停止；不代表 Client 真有連入 |
| 2 | **C04-D2** | raw 接收：使用 C01 `TcpTransportServer` 的 `IConnection.ReceiveAsync`，為每個 Client 建 `Guid ServerConnectionId`、協定未識別時只累積**有界 stream**；read bytes/EOF/timeouts 都可區分 | **現在可開發** | NET-01、synthetic NET-02：能收原始 TCP 位元組（不知道內容是否登入） |
| 3 | **C04-D3** | REQ-0009 JSONL RX/TX/錯誤、connection correlation；預設無 raw payload，日誌輪替/限額/權限/敏感測試 | **現在可開發** | LOG-01..07；可排「沒有人連／收到但無回覆／斷線」 |
| 4 | **C04-E0** | ``FrameEnvelope/FrameDecodeOutcome`、`LoginRequestCandidate`、`LoginReceiveState` 純記憶體介面；`UNVERIFIED` 時拒絕轉交 C02，分段/黏包/oversize/未知 frame 的負例 | **現在可寫 API/合成測試**，**不得啟用 KrOriginalClient** | 建好 Adapter seam 而非完成原生登入 |
| 5 | **C04-E1** | 版本鎖定的 **KR inbound frame decoder**：明確 first connection、direction、marker/mode/length/checksum、app dispatch/scene gate、握手前後切換；T02 資源與 T01/S00 定向核查 | **阻塞：RR-0001/0004/0006/0007；GAP-NET-0001/0003** | NET-03：才能把真 Client bytes 轉成正確 app payload |
| 6 | **C04-E2** | **LOGIN C2S parser**：識別 source-backed E8/0F runtime 路徑、大小/帳密字串/編碼/opaque 欄位；在正確 session/connection 上產生可信 `ParsedLogin`，不回傳密碼到日誌 | **阻塞：RR-0003** | AUTH-01 前段：已解析真正的登入請求，不是任意兩段字串 |
| 7 | **C04-E3** | **C02 受信認證 Adapter**：檢查 Port/lane/State，限速與 ban policy；原子驗證帳號/claim Session、連線 ID/lease fencing、錯誤分類、超時/斷線/競態處理 | **C02 可先做合成／安全 review**；對**原生 Socket 啟用**仍需要 E1/E2 與安全批准 | AUTH-01 後段：Server 確認已處理登入，但 Client 尚未收到成功回覆 |
| 8 | **C04-F0** | **原版登入 S2C 最小回覆**（僅 Auth 成功/拒絕及下一個必要 Client 狀態）— 嚴格用 T03/T02 已審核回覆 pairing、欄位、frame、socket；回覆 TX 與真 Client UI 狀態分驗 | **阻塞：RR-0003/0005/0007、GAP-AUTH/NET/FLOW；需 Client 真實驗收** | AUTH-02/03：Client 真正判成功/失敗；後續選服、角色畫面留 C04-F 完整階段 |

**分工修正**：D1/D2/D3 → Server 工程；E0/E3 的測試接口 → Server 工程；E1 → T02 原生研究＋T01/S00 契約驗收；E2 → T03 研究（T02 協調）＋T01/S00 契約驗收；F0 → T03/T02 研究＋S00 契約，Server 工程最後啟用。**沒有把可由 Client 靜態繼續追的 E1/E2 直接推成「需要原服 runtime 才能繼續」。**

## 3. Server 元件邊界、建議類別與呼叫流程

下面都是**提案介面、不是既有實際 C# 類別**；實作需遵守現有 .NET 10 及 namespace/依賴方向，不得改 C01 的 synthetic profile 語意。

| 建議位置 | 元件／責任 | 核心限制 |
| --- | --- | --- |
| `Tartaros.Server.Host` | `GameGatewayHostedService`、`GameGatewayOptions`、`GatewayHealth` | Host 啟動配置、只 loopback、啟停與端點衝突；保留診斷 HTTP 5080；不依賴 Admin Web 5091 |
| `Tartaros.Network` 或 Gateway 實作層 | `GameConnectionContext`、`ConnectionRunId`、`ITcpEventSink` | 將 C01 long `IConnection.Id` 與 Server `Guid` 的 `ConnectionId` 建立穩定 server-owned mapping；每連線獨立 buffer，禁共享敏感 byte[] |
| `Tartaros.Protocol` | `IKrInboundFrameReader`／`FrameDecodeOutcome` | `Incomplete/Invalid/Unsupported/Complete`；只有 S00 source-gate 通過才可解析 KR runtime；所有 socket bytes bounded |
| Gateway 應用層 | `IClientLoginParser`／`ParsedLoginRequest` | 只有完整 app payload+版本/scene/slot gate 才可輸出。nullable/opaque 源欄位不取「全部0」捷徑 |
| Gateway 應用層 | `ITrustedLoginAdapter` | 已驗證 schema 的 account credentials 短生命週期傳到 C02，永不在 log/message queue 內序列化 |
| `Tartaros.Session`（現有） | `LocalLoginCoordinator`、`ISessionLeaseRegistry` | 只有內部可信路由、安全審查與版號許可才能調用；成功後必建 exact session lease，不暴露内部 lease 作 Client token |
| C04-F 回覆層 | `IClientLoginResultWriter` | 原生回覆 builder 只有核對 request↔response 與 scene/version 才可啟用；未知時不猜成功/失敗 opcode |

### 建議接收管線（概念性偽碼）

```text
GameGatewayHostedService (EXPLICIT_LOCAL_DIAGNOSTIC=true)
  -> TcpTransportServer.Accept
     -> Create server-owned RunId / Guid ConnectionId, state=ACCEPTED_UNCLASSIFIED
     -> Read raw TCP chunks into bounded per-connection accumulator
     -> ITcpEventSink.Emit(RX_CHUNK size/time/phase only)
     -> if Client build / first frame contract UNKNOWN:
            emit UNSUPPORTED_NATIVE_PROFILE / CONNECTED_BUT_LOGIN_UNCLASSIFIED
            -> no credential extraction, no C02 call, no invented S2C; timeout/close safely
        else (S00-reviewed specific KR contract active):
            frameReader.Decode -> bounded FrameEnvelope
            appDispatcher(version, lane, scene, opcode) -> LoginCandidate
            parser.Validated -> TrustedLoginInput (ephemeral credential)
            authAdapter.AuthenticateAndClaimAsync(...) -> DomainDecision
            if result writer native contract independently approved:
                 encode matching S2C and send; log TX_WRITE_COMPLETED, not Client accepted
            else:
                 no guessed reply; record AUTH_DECIDED_RESPONSE_UNAVAILABLE
     -> on cancellation/EOF/error: try disconnect EXACT current lease only
        (stale close must not revoke newer session), dispose, end log
```

**TCP 粘包／分包**：一個 ReceiveAsync 不等於一個 frame；接收零 bytes 視為 peer EOF 而不是空 Login；短 header 保留 bounded prefix，append 後反覆 decode 直到 Incomplete，再等待 bytes；decode 消費位元數和剩餘緩衝不能溢位或「吞掉下一包」。如有 Client-first vs Server-first 未知時設 `AWAITING_EXCHANGE_EVIDENCE`，不可自己發 greeting。每個進程有監聽/連線數量上限、每連線 RX buffer 上限、超時、背壓、停止關閉和超量拒絕；輸入過大預設 fail closed（上限屬 Server 安全策略，不稱 Client 官方限制）。

## 4. 連線與登入狀態機（非原始 Server 狀態機）

| State | 入口與輸入 | 合法前進 | 失敗/保留 |
| --- | --- | --- | --- |
| `DISABLED` | Host 無 opt-in | `LISTENING`（明確 localhost 設定） | `HTTP_HEALTH_ONLY` |
| `LISTENING` | bind OK | `CONNECTED_UNCLASSIFIED` | Bind 失敗 `LISTEN_FAILED`；不可改隨機 Port 靜默重試 |
| `CONNECTED_UNCLASSIFIED` | Accept, server Guid ConnectionId | `FIRST_BYTES_OBSERVED` | Idle/EOF/Close；不推測 Client 已送 Auth |
| `FIRST_BYTES_OBSERVED` | bounded RX_CHUNK | `FRAME_COMPLETE` **僅當版本/decoder gate 成立** | `UNSUPPORTED_NATIVE_CONTRACT`、`INCOMPLETE`、`INVALID_FRAME` |
| `FRAME_COMPLETE` | 完整 source-reviewed envelope | `LOGIN_PAYLOAD_VALIDATED` | 非 LOGIN scene/opcode 或未知 lane/pipeline 拒絕 |
| `LOGIN_PAYLOAD_VALIDATED` | verified login schema + account credential bytes | `AUTH_IN_PROGRESS` | bytes/text/codepage 未證拒絕；敏感緩衝禁記錄 |
| `AUTH_IN_PROGRESS` | C02 auth + current-lease fencing | `AUTH_DECIDED_ACCEPT/REJECT` | DB unavailable、timeout、ban/stale/replay；撤銷/完成的原子性需測 |
| `AUTH_DECIDED_ACCEPT` | Domain Auth OK, lease acquired | `RESPONSE_PENDING_NATIVE_CONTRACT` 或 `RESPONSE_SENT` | 無來源支持 reply 時不得送猜測封包；可先本地合成驗收 |
| `AUTH_DECIDED_REJECT` | Domain Auth rejected | 同上（failure reply 也需證） | 不洩漏帳號是否存在；不申領 lease |
| `RESPONSE_SENT` | 完整 sent bytes | `AWAIT_CLIENT_RESULT` | TX completed ≠ 客戶端成功；timeout cleanup |
| `AWAIT_CLIENT_RESULT` | 經授權 Client 觀察下個 UI/network event | `CLIENT_LOGIN_ACCEPTED_OBSERVED`（實際證據） | 失敗/斷線/未知保持保守、不能預升狀態 |

**冪等／唯一性**：每個 `ServerConnectionId` 在同一 epoch 只能對同一 login attempt 呼叫一次 C02 Claim；如遇重送，按政策明確拒絕/重用已完成結果，**不得產生第二個有效 Session**。不同 ConnectionId 之間的競態維持 C02 既有 lease CAS，晚到的 old connection close 不可撤銷新 lease。Db failure/授權失效不發成功 reply；ban/lockout/duplicate login 的外部可觀察結果須區分**內部分類**與**待證原生 status**。

## 5. 具體資料契約草案：只規定 Server-owned 安全 API

```text
GatewayOptions:
  enabled: bool = false
  bind: 127.0.0.1 (loopback ONLY)
  port: explicit int (never assume 8414/8415/8416)
  profile: KR_DIAGNOSTIC_UNVERIFIED | KR_REVIEWED_EXPLICIT
  maxConnections, maxRxBytes, maxBufferedBytes, idleTimeout: bounded Server policy
  safeTcpLogEnabled: bool; rawPayloadLogEnabled: false (default)
  clientBuildPin: SHA256; require match for native adapter

ConnectionContext:
  runId, serverConnectionId(Guid), transportConnectionId(long)
  acceptedAtUtc, remote/local endpoint, clientBuildProvenance
  state, parserVersion, receivedBytes, sentBytes, closeReason
  sessionLease? (private server-only, never serialized to Client/log)

FrameDecodeOutcome:
  status: Incomplete | Complete | Invalid | Unsupported
  frameMarker? / appOpcode? / lane? (only if reviewed)
  consumedBytes, payloadOwnedSecurely? (never emitted to logs)
  reasonCode, sourceSpecRef, sourceClientSha

TrustedLoginInput:
  serverConnectionId; nativeClientVersionHash; loginVariant (E8 | 0F)
  normalizedServerAccountName; ephemeralSecret (secure short-lived)
  opaqueNativeFields: SourceVerifiedOnly / UNKNOWN => fail closed
  sourceConfidence; decodedScene/slot/frame references

AuthDecision:
  internalCode: Authenticated | InvalidCredentials | Banned | Locked |
                DuplicateOrStale | InvalidRequest | ProviderUnavailable | Timeout
  acquiredLease?: SessionLease (internal)
  nativeReplyCode?: ONLY_WHEN_SOURCE_REVIEWED
```

介面安全**不要**先定為接收任意 `username,password` 的公開 TCP JSON/HTTP endpoint；純內部 `ITrustedLoginAdapter` 才能依 C02 執行。空白／非零 opaque bytes 保留並依未知源規則分別處理；C02 的 12–128 密碼長度屬自訂規則，與 51-byte/51-code-unit Client 字串槽**可能衝突**，需要產品策略審核，不能悄悄截斷、改大小寫、加零字元或用錯字元集去判定輸入；C02 API 只提供成功/拒絕，精細 ban/lockout 類別須透過受信資料來源安全決策或保持 `AuthRejectedUnspecified`，**不能由 bool 猜出停權原因**。

## 6. 接收與 C02 授權的安全政策、資料一致性

1. **Client 版本與環境**：要求真實 EXE/BIN SHA、檔名/路徑（可私下保留）、一致的 KR source pin；如果不同，`UNSUPPORTED_CLIENT_BUILD`。可先讓本地 TCP accept 觀察大小，但不能以未驗版本執行 KR parser。
2. **端點**：localhost by default，不能由 `Connect` callsite 假裝正式 Port；不與 HTTP Admin/diagnostic 共享 listener。若需要 Client 改 endpoint，先查原始 Client 允許的設定途徑，不修改 EXE 或自動覆寫 hosts。
3. **Provider**：C02 目前有 InMemory/PostgreSQL/SQLite 部分服務；遊戲 Gateway 必須用與管理端所管理帳號**相同已核准資料來源**。獨立 InMemory 開新帳號集不會認識 Admin WEB 的 SQLite 帳號；SQLite Provider/SessionAdapter 是否完整同語意需要先確認，不可在規劃中假稱已實作。跨 Provider migration/lockout/ban 一致性由 Server 維護者驗證。
4. **帳密與停權**：憑證原文只在解析/驗證短生命週期記憶體存在；合法 request 才進 C02；登入候選無認證前不授權任何角色/世界操作。外送失敗結果不暴露 user enumeration。ban/lockout與 Session revoke 在同一安全決策門檻內。
5. **Session**：只使用 Server-generated connection Guid；lease Claim/IsCurrent/Disconnect 的 epoch/Revision 符合 C02；以同資料源事務/鎖序驗證 ban、claim 原子性，必測雙連線登入、停權競態、舊連線晚斷、重試、provider fault。**本次不用創新表／新 DB migration**，若確需新增，先查 Server 唯一 migration manifest/SQLite與PG實際版本和 allocator。
6. **速度和隔離**：IP/connection rate limit、first-bytes timeout、max frames/bytes、CPU 解壓 budget、bounded pending auth/task、DOS 和 log-injection 防護；詳值是 Server-only 待核准配置，不是官方封包值。
7. **錯誤可見性**：`NO_LISTENER`、`NO_ACCEPT`、`ACCEPT_NO_BYTES`、`RX_UNKNOWN_FRAME`、`RX_UNSUPPORTED_VERSION`、`RX_LOGIN_SHAPE_REJECTED`、`AUTH_REJECTED`、`AUTH_PROVIDER_DOWN`、`TX_FAILED`、`CLIENT_UI_UNOBSERVED`，**全部為 Server 診斷分類，不是原版 Client/error status code**。

## 7. 日誌規格（REQ-0009 沿用，不新增需求）

- `run_id`、`connection_id`、`ts_utc`、`event`、`phase`、`direction`、`bytes_count`、`frame_marker`、`app_opcode`、`error_category`、`source_client_sha`、`server_commit`；若未 source verified 的 opcode/marker 為 null，Ip/port 視資料敏感性遮蔽或本機限權保存。
- `RX_CHUNK` 為 TCP read 的 bytes 數；`FRAME_DECODED` 是確認完整且有方向證據的 frame；`LOGIN_CANDIDATE` 不代表已成功認證；`AUTH_DECISION` 不寫帳密/帳號原文/lease；`TX_WRITTEN` 不是 Client ACK/操作成功。使用 UTC、每個連線相同 correlation，系統時間不可作原本 Client 協定序列保證。
- 關鍵負例：UTF-16LE/ASCII 密碼 sentinel 不得出現在任何 JSONL、exception stack、rotated log、debug hex、健康檢查輸出；未經完整 redaction policy **禁止**登入 raw hex；log 寫失敗時記有限警報/metric，不阻塞清理 socket，亦不得無界累積。
- `LOG_DROPPED` 與 `LOG_FILE_ERROR` 必須能被辨認；發生漏寫不可拿殘缺 trace 推斷 Client 未發封包。

## 8. 完整 Gate 定義與硬性完成條件

**此處為規劃中的新 `I39-*` Gate，不進正式 `conformance/test-index.json`，也不冒充 Iteration38 的 18 Gate 已通過。** 機讀矩陣：`governance/s00-iterations/S00-ITERATION-39-C04-LOGIN-RECEIVE-GATES.json`。

| Gate | 驗收操作／必要正反例 | 何時才可標 PASS |
| --- | --- | --- |
| I39-01 CLIENT_BUILD | 按 Client 實際 SHA/endpoint 設定資料比對；不同版拒絕 native parse | 有版本可追溯記錄，不靠截圖 |
| I39-02 HOST_LISTEN | 顯式 localhost port 可 bind；重複 port 失敗且錯誤可觀察 | .NET socket 合成 |
| I39-03 RAW_ACCEPT | loopback socket Connect→Accept→RX>0，EOF/timeout 差別 | .NET socket 合成 |
| I39-04 RAW_STREAM | split header/payload、coalesced 2 frames、bounded growth | .NET socket 合成 |
| I39-05 LOG_SAFE | JSONL event correlation、rotated log、不洩密碼/token/未知 raw | .NET 合成 |
| I39-06 HOST_RESTART | port bind 異常、Ctrl+C、reuse、multi-client+cancel/rebind | .NET 合成 |
| I39-07 FAIL_CLOSED | unknown build/marker/scene/lane 無 C02 claim、無 invented reply | .NET unit + socket 合成 |
| I39-08 FRAME_CONTRACT | T02 的真實 first frame/mode/slot + T01/S00 有界審查 | 有來源 SHA/分支/byte/方向/負例 |
| I39-09 FRAME_DECODE | source-backed frame+parser state 可解析碎包／黏包而不重吞 | unit+受核准 profile |
| I39-10 LOGIN_BUILDER | T03 E8/0F 真實可達 sender、字串/opaque、runtime mode | 有來源 SHA/byte/producer→wire |
| I39-11 LOGIN_PARSE | 真 frame 中辨別合法 C2S login vs 非 login（不得 false positive） | S00 reviewed vector 和負測 |
| I39-12 PROVIDER_PARITY | 正確 DB/Account provider、ban/lockout/session semantics，不新建錯資料源 | SQLite/PG isolated integration |
| I39-13 AUTH_GATE | 正確/錯誤憑證、停權、無帳號、DB unavailable 對應內部分類 | offline synthetic + security review |
| I39-14 EPOCH_FENCING | 重複 login、舊 close 不踢新 Session、time-out/crash/ban raced | deterministic concurrency test |
| I39-15 NATIVE_RX | 經授權同 SHA 原版 Client→本地 listener RX、frame、app login traces | 真實 Client 可重現去敏證據 |
| I39-16 NATIVE_AUTH | 原版 Client Login request 在已審核 parse 下到達 C02，產生正確 domain decision | 原版 Client→Server 完整有界測試 |
| I39-17 LOGIN_REPLY | 已審核 S2C success/reject encode+TX，Client 正確收到 | C04-F0 source-backed+實測 |
| I39-18 CLIENT_LOGIN | Client 確實進入已確認登入後 UI/選服狀態 | 真實 Client UI/connection 驗收 |

**可先交付的里程碑：**
- **M0（工程可開發）**：完成 I39-02～07（以及連線/敏感資料負例），日誌可查 Client 是否有 Connect/RX，**但不會辨認原版登入**。
- **M1（原生登入接收／可辨識）**：I39-01、08～11、15 PASS：Client 真登入 payload 被正確識別；受原生證據與另行動態授權阻塞。
- **M2（Server 登入處理）**：再完成 I39-12～14、16：可信 parser→C02 帳密/停權/Session 決策閉合，**正式符合「Server 能接收並處理 Client 登入」**，不代表 Client 顯示成功。
- **M3（Client 真正登入）**：再完成 I39-17/18（C04-F0）：有版本確定的 S2C reply、Client UI 實測；目前必需 S2C pairing 尚未完全證實。完整角色清單是 C04-F 後續目標，不必把 C05 併進本輪。

任何 one-off local test 或 CI PASS 只能聲稱對應的 `OFFLINE_SYNTHETIC` Gate；`NATIVE_RX/NATIVE_AUTH/CLIENT_LOGIN` 全部保持 `NOT_RUN/BLOCKED` 直到實際觀測。

## 9. 給 T02／T03／T01 的**精確**補證題目（沿既有 RR）

| 原 RR | 主責／當前狀態（基準） | 最小正向來源與反例成果 | 對應 Gate |
| --- | --- | --- | --- |
| RR-0001（IN_REVIEW）／RR-0004（IN_REVIEW） | T02 | 區分 Client-first／Server-first 的證據邊界，實際進第一個送/收的 caller→slot→frame writer/router、Conn+A02C 的 writer、fallback、marker/length；排除非首包候選 | I39-08/09 |
| RR-0006（IN_REVIEW）／RR-0007（IN_REVIEW） | T02 | recv→IOCP→length/decoder→queue/lane→LOGIN scene dispatcher；invalid/0x2633/0x22D7 的失敗與 gate，不能把純測試器 rejection 當 Client 行為 | I39-08/09/11 |
| RR-0003（IN_REVIEW） | T03 | mode0x52/0x54 與 E8/0F 實際 runtime 可達條件、E8 6B opaque bytes writer/反例、CP_ACP/UTF16 級別、登入 payload→queue→socket 的最小原生鏈 | I39-10/11/16 |
| RR-0003 + RR-0005（ACCEPTED limited）／RR-0007 | T03/T02 | 正確 S2C 對應、LOGIN handler 執行時的 client scene、group row/端點、是否先 server-first；選服 UI/Socket gate；不因 RR-5 接受就閉合 GAP-NET-0002 | I39-17/18 |
| T01（原生獨立） | T01 | 對 **啟用 KR adapter 真正依賴的每個關鍵 byte/branch** 做精確原生核對及原有 FULL-PASS 分流；S00 記錄可用的限定 contract | I39-08/10/17 |

不重開 RR-0001..0007 同義研究、不覆蓋 T03 原稿；因原版 Server 本身內部認證算法未知，不得阻擋 Client 可直接從 BIN 驗證的 sender/handler 研究。`GAP-NET-0001/0002/0003`、`GAP-AUTH-0001`、`GAP-FLOW-0001` 均維持 OPEN。`RR-0002`（選角）及 RR-0009/0010（創角）不屬「收登入封包」最小阻斷；`RR-0008`（入教學）亦不阻擋 M2。

## 10. 推送到 Server 開發者的交接順序（**本輪只有 S00 規劃，不代為實作**）

1. Server 開工先讀 `AGENTS.md`、`docs/DEVELOPMENT-PLAN.md`、`contracts/spec-revision.json`、`docs/C01-A/B/C-IMPLEMENTATION.md`、`docs/C04-A/B/C-IMPLEMENTATION.md` 及本次 I39 plan；比對最新 Server main、資料源與 migration allocator。**不修改 S00 的 Source Pin 以掩蓋缺證**。
2. 第一個可交付 Commit／PR **C04-D1/D2/D3**：opt-in localhost listener + safe structured log + RX byte observability；合成 Client 測試、埠占用/超時/EOF/輪替/不洩密。功能預設 OFF，保留 HTTP 5080、Admin 5091，不啟用 KR codec。
3. 第二個工程工作 **C04-E0**：純記憶體 `FrameDecodeOutcome`／`LoginCandidate`／`ITrustedLoginAdapter`／未核准 fail-closed，測試未知 profile 絕不觸發帳密 C02。
4. T02/T03 與 T01 關鍵 source review 並行；每解除一個 source gate，針對限定 build 實作 **C04-E1/E2**。不要硬編 first packet、固定 opcode、CP949、E8 尾六 byte 或「S2C0x13 必然是 ACK」。
5. **C04-E3** 在已驗證正確後端 Provider、C02 安全 review、租約/ban/replay/rate limit 合格後，才把 `ParsedLoginRequest` 導到 `LocalLoginCoordinator`。Server-only offline 通過與原版 Client 的登入是兩份不同報告。
6. **C04-F0** 依 T03/T02 真回覆證據實作結果 writer；直到 Source Gate 與實機 Client 授權/測試通過前，不能在正式 KR profile 推送猜的 success bytes。進角色清單另由 C04-F 全版。
7. 每次開發交付要列「**已做到哪一個 I39 Gate（DESIGN/OFFLINE/SOURCE/NATIVE）**」、最新 Server/S00 SHA、埠與測試方式、log redaction、未解 native byte/scene/state、是否收到真 Client 的 RX（不得用合成代替）、下一項阻塞；若需要規格修正，走 `docs/FEEDBACK.md` 再交 S00。
8. **Server-only DB 範圍**：先复用現有 Schema，無必要不新建 migration；若確需持久 login attempts/connection audits，應優先寫有界 JSONL 與受控輪替，不能把原版封包內容長期落 DB。PostgreSQL/SQLite 同一份管理帳號能登入是獨立驗收。

## 11. 策略與歷史資料追溯

- 正式原生規格：`spec/protocol/SPEC-NET-0001.md`、`SPEC-NET-0002.md`、`SPEC-NET-0003.md`、`spec/session-account/SPEC-AUTH-0001.md`、`SPEC-FLOW-0001.md`；對應正式需求 `REQ-0001`（登入收發）、`REQ-0002`（選服）、`REQ-0005`（frame）、`REQ-0009`（TCP 日誌）。
- 唯一 RR/GAP/REQ/TEST：`research/requests/index.json`、`design/gaps/index.json`、`design/requirements/index.json`、`conformance/test-index.json`；目前沒有建立新的正式 RR/TEST/CLM。所有 7 SPEC 持續 DRAFT/PARTIAL，原版 Client 尚未驗收。
- 上層規劃 `governance/s00-iterations/S00-20261031-ITERATION-38-C04-KR-LOGIN-GATEWAY-PLAN.md`；18 Gates `S00-ITERATION-38-C04-LOGIN-GATES.json`。Iteration39 的 I39-01～18 是更細的「**接收登入請求**」子驗收，不更改 Iteration38 既有 Gate ID 或將其標為 PASS。
- C05-P04 普攻與連段不在本輪依賴圖內；對「只想收到登入並驗證」的可交付目標，**不需**等待選角後場景、新手教學、怪物或技能。

**結論：** S00 本輪能讓開發者直接開始 **C04-D1/D2/D3 與 E0**，並為 **E1/E2/E3/F0** 指定足以解除阻塞的精確證據及驗收標準。只要 Client 原生 first-frame/login producer/回覆契約尚未補齊，不能聲稱 Server 已能原版登入；這是研究缺口，不是以猜封包來彌補的開發空白。
