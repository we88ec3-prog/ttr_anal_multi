# S00 Iteration 40 — 整合 T01 新證據後，C04「Server 真正接收並處理原版 Client 登入」可執行交付規劃

**版本：** 2026-11-01（Asia/Taipei），S00 main 在 T01 分支安全快轉後為 `8c93012edc4b76103a72d8b2f8868d6357034978`；Server main `b4f187445d1d287feab3ceee9ea86d9dc0f75d63`。Client 審查對象 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（對應 EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，由 T01 原稿記載）。**玩家實際「Tartaros Rebirth」畫面／EXE/BIN SHA/實際 endpoint 未核對；不能先視為同一 KR Build。**

> **性質：NON_NORMATIVE_IMPLEMENTATION_DELIVERY_PLAN。** 本檔是 S00 規劃與 Server 開發交接，不是 Server 程式實作、原版 Client 動態測試、官方 Server 格式的認證或 T01 FULL-PASS。只有 user 明確授權 GitHub S00 上稿，沒有授權修改原版 Client／對官服連線／使用未去敏憑證。

## 1. T01 同步方式與可用的新證據

本輪按使用者要求，比對 `t01/roy/chatgpt-web` 與 S00 main：merge-base `ecc948a9e2fa731a272a826e30f691dde88d7d76`、T01 分支**ahead 5/behind 0**，以 **fast-forward** 將 main 更新到 `8c93012edc4b76103a72d8b2f8868d6357034978`。保留分支三父 merge 的來源歷史，不 cherry-pick、覆寫或改寫原稿；整合的 8 路徑含兩篇原稿、驗證器、T01 README、正式 intake／claim 索引及 T01 審查報告。

- **新增 SRC-0653／CLM-NET-0037（PARTIAL）**：[T01 限定 R0–R2 審查](../../research/handoffs/t01-20261101-extra-roy1-roy2-r0-r2/README.md)、[RR-0006 來源補報](../../kr-extra-roy/20261101-020429-chatgpt-web-roy-RR0006-Rx-boundary-node-lifetime-post-error-frame.md)；精確 blob `ca698712d6016884308f866f0e7e643ce22c7d64`。原件定向確認：`0x807B40` 的 0BBB checksum/0x2633 decode 完整錯誤 frame，可跳過失敗 payload 並繼續處理同一收包批次中的下個完整 frame；0 長度/超 4096 的 parser 0 路徑不同於 checksum error。正常 WSARecv 0x1000／殘留 4103／下一次合計 8199 < Rx 0x5000 是**帶前提的算術上界**。另有 `0x807C81` 先 checkout、四個指標異常分支 `0x807DD6` 跳過正常 recycle 的**條件式**本地 pool 風險，**未證正常合法連線可觸發，也不是 Server wire MUST**。
- **新增 SRC-0652／CLM-CHAR-0007（PARTIAL）**：[E81 UI 事件補報](../../kr-extra-roy/20261031-chatgpt-web-roy-E81-RR0009-F431F-Employ-UI-events-native-supplement.md)；精確 blob `7fea46f8803d67e8d63c281f448515c37a521796`。F431F→CEmployNewCharacter 路徑更有界，但**未證** `N=0 roster→UI 可見可操作`。對「收到登入」不是 blocker；若後續要顯示空清單角色建立畫面，仍由 C04-F／T03/T06 處理。
- T01 核查 41 個原生位址/分支條件＋1 個算術檢查的**限定驗證**，**不是**任何一份原稿全文 FULL-PASS、`NATIVE_VERIFIED`、`SPEC_CONSUMABLE`。RR-0006 仍 `IN_REVIEW`，RR-0009 仍僅研究有界 `ACCEPTED`，GAP 均不因 fast-forward 自動關閉；T01 原稿與作者檢查器均不被 S00 修改。

**對 Server 的直接規劃改動：** C04-E1/E2 應把「TCP 收包」→「frame 累積」→「成功／失敗 frame 消耗」→「LOGIN app 消費」分離測試；對 checksum 壞幀＋下一好幀要有合成測試，但 **Server 拒絕壞輸入／關閉連線是自設安全策略，可與 Client 有界內部行為不同**。不模仿 Client 的 pool 指標風險、不推斷 frame 標記實際上線順序。

## 2. 最新獨立 Server 實作核對與缺口（不是舊 Iteration 38 快照）

| 既有工作 | 實際代碼/文件與狀態（Server main `b4f1874`） | 本輪之後應做 |
| --- | --- | --- |
| C01-A/B/C | `TcpTransportServer`、`IConnection`、`SyntheticFramedSession` 已有 raw socket/佇列/斷線測試；僅 synthetic | **不要重寫** C01 |
| **C04-D1/D2/D3** | `DiagnosticGateway`、`Program.cs` 可用明確 localhost diagnostic opt-in 啟動，收 RX chunk，不發送任何登入 bytes；詳 `docs/C04-D1-D2-D3-E0-IMPLEMENTATION.md` | 校核本機 Client endpoint/Build；用 log 判斷連線是否發生；**不把 RX>0 等同 LOGIN** |
| **C04-D4** | `SafeTcpEventJournal` 有 bounded queue、JSONL 輪替／限制／丟棄計數／ACL 工具；詳 `docs/C04-D4-IMPLEMENTATION.md` | 保留密碼/hex 一律不記預設，原生 parser 收發前要能擴充可信事件，不重做 journal |
| **C04-E0** | `NativeContractAdmission.CanEnable(KrOriginalClient,sha)` **永遠 false**；`FrameCodecCatalog` 對 KR/TC 是 `UnverifiedFrameCodec` | 這是正確隔離；**證據不足不得移除** |
| **C04-E1（部分）** | `KrE1OfflineEnvelopeInspector` 只給出 `Incomplete/Rejected/BoundedShapeOnly` 的 frame header/extent；無 XOR 還原、0x2633 inflate、app dispatch、真正 socket first-wire；詳 `docs/C04-E1-F-OFFLINE-IMPLEMENTATION.md` | 增補 **受信候選 frame→分包 buffer→source-gated payload** 的分層，不把 Inspector 當已解碼 Parser |
| **C04-F（部分）** | `KrFOfflineChoiceInspector` 只記錄登入場景 0x13/0x7A 局部 group/child 欄位；**不**能建正式 S2C 回覆 | 最小登入回覆 **F0** 仍需正確 C2S↔S2C pairing |
| **C02/C03** | `LocalLoginCoordinator` 的 `AuthenticateAndClaimAsync` 和帳號／Session lease／ban、角色資料有 Server-owned 邏輯（SQLite/PG provider 行為須對齊） | 接入**同一個 Admin 可操作資料庫**、帳密與租約審查；不可開另一套記憶體帳號而宣稱可用既有 Admin 帳號 |
| S00 Iteration 39 | 已有 D1/D2/D3→E0→E1/E2/E3→F0 18 Gate 計畫 | 本輪改成**以已提交的 Server code 當基線**，列出剩餘可做／受阻區段與交付順序 |

`Tartaros.Server.Host` health 維持 `gameListener=false` 指的是**未啟用原生遊戲服務**；診斷 Listener 開啟時可讀 `gameListenerEnabled/Bound`、`diagnosticReceivedBytes`、`diagnosticLogState`。這些指標只有 raw socket/觀察意義。

Server 的 `contracts/spec-revision.json` 仍 pinned 舊 S00 `dd69ec9d...`、`DRAFT_PARTIAL_ONLY`、`implemented_wire_contracts=[]`。新的 `contracts/c04-e1-f-source-gates.json` 只是有界離線研究快照；**source pin 的修改不代表可以啟用原生 codec**。

## 3. 「Server 接收 Client 登入」明確定義為 M2，而非僅開 Port

用五個語意上不同的完成點來防止偷換：

1. **M0 — TCP_CONNECTED/RAW_RX**：Client 同版 IP/Port 能連進 listener，Server 安全記錄收到若干 raw bytes；沒有稱它是登入封包。
2. **M1 — NATIVE_LOGIN_PARSED**：同一個已核對的 Client Build，Server 依正確方向/連線/scene 契約，frame decode 後辨別**真的登入** C2S，欄位、長度、字元編碼皆符合有界契約。
3. **M2 — SERVER_LOGIN_DECIDED**：M1 的登入請求**僅經受信原生 Adapter**交給 C02，對帳號存在、密碼、停權、租約申領產生正確安全決策；失敗不可產生有效 Session。**這才符合使用者的「讓 Server 接收並處理 Client 登入」開發目標。**
4. **M3 — CLIENT_LOGIN_ACKNOWLEDGED**：Server 將源證匹配的成功/失敗 S2C 安全編碼發出，原版 Client 在實測中進到下一個正確登入狀態；不是 `SendAsync` 單純回傳成功。
5. **M4 — CHOICE_ROSTER_UI_READY**：Client 可以選服及看見可操作角色清單；後續 C04-F 完整部分，**與 M2/M3 可獨立驗收**；不需等 C05 戰鬥、新手教學。

**目前已提交的是 M0 的 Server-only 實作（是否為真正原版 Client 連進來，仍缺對端觀測）；M1/M2/M3/M4 仍不得宣稱完成。** 本次 S00 提供的為*開發者可執行的完整規劃*；M2 真正「原版完成」仍待精確 Client Source Gate、Server 開發及經授權的 runtime。

## 4. 下一階段的真正開發順序（對 Server 開發代理直接交辦）

### C04-E1b — 從現有 Offline Envelope 進入**有界收包流水線**（先做 OFFLINE）

**Input**：同連線的 `ReadOnlyMemory<byte>` RX stream chunks 和可信的 ServerConnectionId。**Output**：`Incomplete / Rejected / Unsupported / CandidateEnvelope`；其後必須經 `SourceContractAdmission` 才能獲得 `DecodedAppEnvelope`。所有 APIs 都須攜帶 `clientVersionHash`、direction(`C2S`)、conn slot/scene evidence 與 `source_gate_state`；不允許只靠 opcode 決定要登入。

- 延用 `KrE1OfflineEnvelopeInspector` 作 header/body boundary checker（LE16 n 1..4096，0BBB header6、2633 header8、其他4），但 **它不保證 payload 有效或為官方 Server 支援 marker**。每個連線獨立 bounded accumulator；處理「一幀拆多個 Receive」、「兩幀黏在一次 Receive」、「錯誤完整 frame＋正確 frame」與無限長度、overflow、零長、未知標記、跨連線混資料。
- **方向專屬的 source gate**：Client local C2S writer 已觀察 1A68/0BBB（mode `Conn+A02C`，fallback）；Client S2C inbound parser 可看到 0x2633/0x22D7/default。不能直接把 S2C Parser 的標記清單當成 C2S 正式 whitelist，也不可假設首個 C2S／S2C 都用 0BBB。
- T01 新增 RR6 的應用是**獨立測試矩陣**：
  - `RX bad 0BBB checksum + good raw`：來源證實的是 Client 本地可在特定條件繼續解析，不是 Server 必須鏡像。Server 可以依經核准的防濫用 policy fail-closed，必須記錄 `FRAME_BAD_CHECKSUM` 且不交 C02。
  - `RX bad 2633 inflate + good raw` 同理；`RX invalid n=0 / n>4096` 與 checksum 失敗是**不同** error class；`RX incomplete` 不是 bad frame。
  - `RX bounds invalid after pool checkout`：Client-only condition 不做 Server 模擬 memory leak；Server 必須安全釋放所有自有緩衝，counter/bounded queue 不漏。
- 這個純內存處理器可立即開發和 synthetic CI；**不得**接到真 `DiagnosticGateway` 後自行更改 `NativeContractAdmission` 為 true，也不得拿純 header extent 做帳密解析。

**E1b OFFLINE Gate：** bounded stream、checksum/2633 mock reject、跨幀消費／隔離，來源分級正確，未知格式 fail-closed；不代表原版 Client M1 PASS。

### C04-E2a — Client 登入 payload 的**離線**解析與短生命週期憑證容器

**前置：** 只接受**已授權經 E1b 完整解碼**的 `DecodedAppEnvelope`（測試可用 explicit synthetic fixture），不是直接從任意 112/214 bytes 中提帳密。

- `mode0x52` 本地 E8/112B：LE16 `0x00E8`、`+2..52` 和 `+53..103` 各 51-byte narrow slot、`+104..109` 六個 opaque byte、`+110..111` 來源 WORD。E8 output narrow 使用 CP_ACP（Windows 登入環境實際 codepage 未閉合），不寫死 CP949 或 UTF8。
- `mode0x54/其他` 本地 000F/214B：LE16 `0x000F`、`+2..103` 和 `+104..205` 各 51 UTF-16 code units、`+206..209=0x00010001`、`+210..211=0x0034`、`+212..213` 來源 WORD。不能把 E8 與 000F 兩種布局合併。
- `KrLoginChoiceOfflineLayoutProbe` 已檢查上述**本地 builder 幾何**，不做真 wire parser、無法解釋 opaque bytes／官方帳號 policy。新增 E2a 只可提供 sealed `OfflineLoginCandidate`／parse-status 供單測，不應直接呼叫 C02。
- 帳號與密碼欄位必須在受信 boundary 轉換後單獨短時存活；不得留於 JSONL、例外、metrics、clone、持久隊列，必要時以 bounded byte buffers/清理避免多餘複製。無核准 Native schema、場景或來源版本者應返回 `UNKNOWN_NATIVE_FIELD` 或 `UNSUPPORTED_CLIENT_VERSION`，**禁止錯誤成功登入**。
- Server `LocalCredentialPolicy` 的登入字串合法性由自訂 Server policy 決定，與 KR Client 51 unit/byte slot 不等同；需檢驗原本管理後台創的帳號能否用此 Client 輸入長度送出，不能自動截短密碼讓測試過。

**E2a OFFLINE Gate：** E8 vs 000F、truncated/unterminated/overflow/opaque 非零、編碼 roundtrip、無憑證外洩、來源版本不匹配全部 synthetic PASS；不構成 M1 原生成功。

### C04-E2b — 實際 C2S 導線、首次封包與版本准入（**source blocker**）

T02/T03 必須交付以下可以直接翻成程式的**最低契約表**；原 Client 在有效登入 scene 中具來源與排除反例的 chain：
1. EXE/BIN/launcher build 和 endpoint/proxy/config 來源，連到哪個 IP/Port、首個 socket slot1 是否成立、pipeline/lane 方向；
2. 初始 TCP connect 後誰先發第一批 bytes（Client／Server／有額外握手）；真正可達 frame writer、mode `Conn+A02C`、marker/checksum/length、切線前後 fallback；若只能 Client 靜態證 local writer，明列**first-wire runtime UNKNOWN**，不能假填；
3. `0x440790→0x4A3360` E8 和 `0x4A31B0` 000F 的**場景/模式**，如何到 outbound network queue/OS socket；E8 +104..109 六 opaque bytes 的上游、`FB1318+BF80` 來源、主機 codepage 對實際登入影響；
4. 可由 Server 依方向與每一個連線 state 驗證的 `DecodedAppEnvelope` schema；各種 failure/invalid/duplicate/retry 的處理是**Client 必要相容**或**Server 自選安全 policy**；不可用 synthetic packet 取代實機 source。

最小交付格式：`client_sha256, connect_callsite, peer_endpoint_source, conn_slot, inbound/outbound, first_exchange_caveat, frame_marker/mode, frame_length_bounds, app_opcode, payload_offset/extent, encoding, opaque_field_provenance, scene/lane_preconditions, error_branch, source_bin_VA+bytes, negative_cases, T01_scope, S00_admission`。若確實無法單靠 Client 靜態證第一個原版 Server message，註記 `REQUIRES_AUTHORIZED_RUNTIME` 而非自行編造。

**對應既有 RR**：T02 RR-0001／0004／0006／0007；T03 RR-0003。T01 按原規範做原生限定驗收，S00 將真正可消費部分補入 DRAFT/可審核 contract；不要另起同義 RR/影子台帳。

### C04-E3a — 內部登入 Domain Bridge（**可立即做 OFFLINE**）

**目標**：把 E2a 的「可信的合成登入候選」對應到 C02 `LocalLoginCoordinator`（或 Server 同一安全介面的擴充），讓測試中的 C2S login shape 產生真正的 Server-owned Account/Session 處理，**不對原版網路暴露**。

- `TrustedLoginCommand` 必須由 `SourceReviewed/AuthenticatedFrame/CorrectScene` 閘門產生。Offline 測試另提供**明確不同**的 `SyntheticTrustedLoginCommand` builder；禁止真正 Gateway 以 Test-only 信任標記硬換成 Native。
- `IAccountDirectory` / `ILocalAccountDirectory`、`ISessionLeaseRegistry`、`LocalLoginCoordinator.AuthenticateAndClaimAsync(name,password,connectionGuid,lifetime)` 皆存在；Gateway transport `IConnection.Id:long` vs Session `connectionId:Guid` 須由 Server 自己生成穩定一對一 ID，**不能**信任 Client payload。
- **資料庫一致性**：使用與獨立 Admin WEB 相同的 SQLite 或經指定的 PostgreSQL 帳號庫，且同 Provider 驗證 ban / lockout / revoke / lease；沒有足夠持久化 provider bridge 時不可默默 fallback 到空的 InMemory 帳號庫，更不可因資料庫故障回報成功。
- 對外 `AuthRejected` 不分帳號不存在與密碼錯（防枚舉），內部可留可信 `InvalidCredentials/TemporaryBan/PermanentBan/Locked/SessionStale/DbUnavailable` 分類，**只有 Backend 真提供可區分的信任決策才可細分**；現有 `LocalLoginCoordinator` 僅回傳 Authenticated bool/lease，不允許從 bool 推斷是哪一類。
- 將 `SessionLease` 與 server-generated connection Guid 建 exact mapping；同連線重送去重，同帳號第二連線取代第一 lease 時，舊連線晚到 close **不可 revoke 新連線**。超時、關機、資料庫故障/rollback、登入/停權競態皆需 deterministic test。
- 任何一方未完成安全/Provider source gate，該命令禁止 Claim Session。Logger 只寫 `AUTH_DECISION status + connection correlation`，不記 account name/password/hash/session ticket。
- 不另建 DB migration 以解決 TCP 日誌：沿用 `REQ-0009` 的 JSONL；若真需持久化登入節點，先由 Server 現行 migration manifest allocator 重新配版，不能使用過期 Iteration 33 的號碼。

**E3a OFFLINE Gate：** 正確/錯誤/停權/雙登入/舊連線晚關/Server shutdown/Provider outage + SQLite/PG 隔離整合，且錯誤請求沒有 Session ；本項達標**不是**原版 Client M2。

### C04-E3b — 真正連接 Client 的登入決策（**source + security + runtime blocker**）

當 E1b 的來源導向 frame、E2b 的正確登入 payload 和 E3a 後端安全均達成，才允許建立 `KR_REVIEWED_LOGIN_RX`（精確 build SHA + 明確 opt-in + localhost + isolated account DB + source/review pin）封閉測試模式，並加一個 release gate 驗證：
- 同一個真 Client TCP ConnectionId：`ACCEPT→RX_CHUNK→FRAME_VALIDATED→LOGIN_PAYLOAD_VALIDATED→C02_AUTH_DECISION`；所有狀態可追但不含私密 payload；M2 的判定取自真 C02 Account/Session 狀態，而不是收到 112 bytes 就報 success；
- 真 Client 某次連線中的重試/EOF/invalid frame 不能產生新 Session；未能 source-review 的 frame、opcode、Client SHA、scene/slot 一律 fail closed；
- Client 沒有正確 response（F0 尚未有來源）時，**不得**偽造回覆、不得把 M2 的 Server Decision 誤報成 Client 已登入成功。若為了分離驗收而建立測試 API 注入已審核 payload，必須保證只在合成 test harness 可用而不對原版 client 暴露。

**M2 真正 PASS 的證據**：版本一致的 Client-in-loop 監聽/安全去敏 trace + source-validated frame/app request + C02 account decision/lease + race/negative tests + S00 source gate + 經明確授權的運行記錄。GitHub build/pass、HTTP health、synthetic TCP、Source report 均不能替代。

### C04-F0（登入能讓 Client 往下走的必要延伸，但不是接收登入 M2 的子項）

T03/T02 需證**真正** C2S↔S2C pairing，特別是在 LOGIN scene 消費的 `S2C app0x0013`（status +0x16、groupCount +0x1C、cursor +0x92）與 `app0x007A`（groupCount +2、cursor +6）何者／何時成立、成功/失敗、socket／frame/scene 與下一個 UI/handoff。原 Client handler **可達**不等於任意登入一律先回 `0x13` 或 `0x7A`。只有得到完整 field/source gate 後，才實作 `IReviewedKrLoginResponseWriter`。送出失敗 reply 必須有來源，不能用猜測錯誤碼封裝；TX write success ≠ Client UI ready。

**對真正玩家登入並看到選伺服器／角色畫面仍需 M3/M4，** 不得只完成 M2 就宣稱已達到角色畫面目標。

## 5. 明確的介面、資料流及運行開關（Server-only 設計，不是 Client 命令）

```text
GameHost (existing HTTP health + C04 diagnostic)
  -> diagnostic-only accept  [EXISTS]
  -> per-connection bounded RxAccumulator [E1b OFFLINE/then gated native]
  -> IFrameDecoder{direction=C2S, build, slot, phase} [E1b / E2b]
     -> FrameCandidate {complete,rejected,incomplete,consumed}
     -> DecodedAppEnvelope {source-verified-only}
  -> ILoginCandidateParser [E2a OFFLINE -> E2b native-gated]
  -> ITrustedLoginCommandFactory {version/scene/slot+payload proven}
  -> ILoginDomainBridge [E3a OFFLINE -> E3b native-gated]
     -> C02 local AccountDirectory + SessionLeaseRegistry from same approved DB
     -> AuthDecision, SessionLease bound to server-generated ConnectionId
  -> IReviewedKrLoginResponseWriter [F0 ONLY source-reviewed, separate]
     -> TX + log safe metrics + Client GUI verification [not yet]
```

實作時 State 應明確為 `LISTENING → CONNECTED_UNCLASSIFIED → RX_INCOMPLETE/FRAME_CANDIDATE → FRAME_VERIFIED → LOGIN_VALIDATED → AUTH_ATTEMPTED → DOMAIN_AUTH_ACCEPTED/REJECTED → RESPONSE_UNAVAILABLE_OR_SENT → CLIENT_NEXT_STATE_OBSERVED`；`Unsupported` 不得成 `LOGIN_VALIDATED`。所有 queue/cursor/size/username-byte-to-string 轉換使用明確上限，server/client 版本不一致者不得導向 C02。狀態更動屬**Server proposal**，不是原版官方狀態機。

`KR_DIAGNOSTIC_ONLY`（既有）繼續只能讀 raw 不解析登入；未核准不得藉環境變數、request header 或 query string 改成 `KrOriginalClient`。未來的 `KR_REVIEWED_LOGIN_RX` **僅為候選名稱**，需要另一份具核准來源的安全入場與停用條件；此份 S00 規劃本身**不核准 runtime 開關**。

## 6. 遇到失敗時怎麼回報與回復（不偷換錯誤原因）

| 失敗位置 | Server 可記的安全證據 | 安全行為／必要後續 |
| --- | --- | --- |
| Client 目標 IP/Port 不一致、TCP 未 ACCEPT | listener bound/address, local OS port check；**不能**從零筆 log 推定 Client 沒有送 SYN | 核對 Client 設定／路由／防火牆，拒絕猜官方 Port |
| accept 後 0 bytes / 首包超時 | ConnectionId、ACCEPT 時間、RX count=0、EOF/timeout | 不猜 Client 先發封包，timeout cleanup |
| frame incomplete | RX bytes、buffer length、wait/timeout | 保留 bounded prefix，不能記 malformed |
| frame invalid size/checksum/inflate | error class、marker（來源明確才標）及 accepted byte count | 沒有 validated app payload／不得 C02 claim；Server 可選 fail-closed |
| unknown marker/source build/scene | `UNSUPPORTED_PROFILE` / `UNSUPPORTED_SCENE`，opcode 未證為 null | 不呼叫 C02、不假回 0x13 |
| Login E8/0F 字元集/opaque 不明 | `LOGIN_FIELDS_UNVERIFIED` | 拒絕進入 native credential verification；T03/T02 補證 |
| 帳號不存在／錯誤密碼／停權 | C02 可信 domain decision，不記明文/帳號唯一識別 | 不申領 lease；只有已證原版回覆才能告知 Client |
| Session 被取代或 old socket EOF | exact lease revision、server ConnectionId、close reason（不記 bearer） | CAS/fencing：old close 不能取消 new lease |
| 資料庫不可用或管理後台不同資料庫 | provider identity/version、DB outage category | 不回成功，不 fallback InMemory，不改 DB schema |
| 有效登入但無原版回覆格式 | `AUTH_DECIDED_RESPONSE_UNAVAILABLE` | F0 待證；不能聲稱 Client 顯示成功 |

**回滾／故障恢復策略**：本階段無扣費，無交易重試對玩家造成資源變更；認證 Claims 只維護 Session lease，失敗或中斷的 lease 依原有 CAS 精確釋放／到期回收；安全日誌可無資料持久化敏感內容。無法證明 Client 已收到回覆時，後續重試由 Server 規則避免重複 Session；不要把 UDP/TCP 重傳當應用層重試證明。

## 7. 驗收 Gate（這輪只新增規劃 overlay，**NOT_RUN**）

以 Iteration 39 的 I39-01～18 和 Iteration38 的 NET/AUTH/LOG/FLOW Gate 追溯；這裡規劃 15 個專注當前差額的 `I40-01..15` 子檢查。**沒有新增正式 conformance TEST，沒有把過去 CI 或新 T01 Limited R2 變成原版 Client PASS。**

| Gate | 最小驗收 | 證據類別 | 前置 |
| --- | --- | --- | --- |
| I40-01 | 已同步 T01 branch 的原稿/CLAIM SRC-0652/653 SHA 完整可讀、RR 不亂改 | Git source integrity | main fast-forward |
| I40-02 | Server 目前 D1–D4/E0/E1/F offline 功能盤點和本次開發差額對齊 | source/read-only | Server main pin |
| I40-03 | RX split/coalesced/bad+good、0 vs >4096、callback 狀態全分離 | Server-only offline | E1b |
| I40-04 | 0BBB checksum/2633 bad payload/未知 marker 不 dispatch 成登入 | Server-only offline | E1b |
| I40-05 | E8 112B/000F 214B、opaque、編碼、截斷錯誤不誤判登入 | Server-only offline | E2a |
| I40-06 | first actual wire direction/marker/slot/scene 有同版來源／反例／T01 scope | Native source-gated | RR-0001/0004/0006/0007 |
| I40-07 | E8/0F 本地 builder→網路 queue／runtime 條件、opaque/codepage 有同版 source | Native source-gated | RR-0003 |
| I40-08 | 可信 decoded native app login 只能在正確 slot/phase 送 C02 | Server+native source | E2b |
| I40-09 | 假憑證、停權、同資料庫、無帳號、Provider down 無 lease/無敏感 log | Server-only offline | E3a |
| I40-10 | 雙連線、重試、old close 不撤新 lease、禁重複 Claim | Server-only offline | E3a |
| I40-11 | 真 Client build/hash/endpoint/conn role 核對，不以截圖或靜態 8414 等價 | Client identity | operator+T02 |
| I40-12 | 真 Client login C2S bytes 經獲准的原生 frame/parser 被 Server 接收 | Authorized Client runtime | E1b/E2b |
| I40-13 | 同次真登入請求 C02 正確 auth/lease、失敗不做成功決策 | Authorized Client runtime | E3b |
| I40-14 | S2C 成功/拒絕 builder 有真正配對／scene／byte layout 的來源及否定例 | Native source-gated | RR-0003/0005/0007 |
| I40-15 | 真 Client 確認進下一步畫面，與 C02 Domain Auth 成功分開 | Authorized Client runtime | F0 |

**M2 到達條件**：I40-01..13 必須有其相應的 source/offline/runtime 證據，並且 I39 所需 M1+M2 gate 真正 PASS；不能因本輪文件已上 Git 視為通過。I40-14/15 是 M3 必須滿足的延伸，不能用 M2 混過；到角色名單 M4 再由 C04-F 完整驗收。

## 8. 研究題目去重與新的責任分工

| 需求 | 正式唯一台帳 | Owner / 最小新成果 | 若沒有新證據 |
| --- | --- | --- | --- |
| 第一筆 wire/mode/方向/封包解析 | REQ-0005；RR-0001/0004/0006/0007；GAP-NET-0001/0003 | **T02**：真 C2S/RX scene/slot、好壞 frame、可達條件；T01 定向 R2；S00 接受特定 scope | E1b 可離線開發，E2b 禁正式啟用 |
| 登入 app payload 與 C02 受信決策 | REQ-0001；RR-0003；GAP-AUTH-0001 | **T03**：E8/0F builder→wire、opaque/編碼/失敗路徑；T02 互證 slot；S00 接入契約 | E2a/E3a 可做純測試，M2 不算原版 PASS |
| 回覆與切線/選服 | REQ-0001/0002；RR-0003/0005/0007；GAP-NET-0002/FLOW | T03+T02：0x13/0x7A 與真正 request pairing/Client scene；Server 才寫 F0 | M3/M4 BLOCKED |
| 角色清單/創角 GUI | REQ-0003/4；RR-0002/9/10；GAP-CHAR-0001/2/3 | T03+T06（E81 是局部事件新增來源）；原本 RR9 限定研究 ACCEPTED | **不阻礙 M2**，不宣稱角色畫面可用 |
| 監聽/日誌 | REQ-0009（CANDIDATE） | Server 已 D1–D4；後續擴充 RX/TX 可信事件、secret redaction/rotation | 非 native login blocker，不重做 |

T01 新源結果由 `research/intake/index.json`／`research/claims/index.json` 保存為 `CONFLICT_CHECKED/PARTIAL`，未提升 `shared/verified-knowledge`；S00 不建立重複的正式 RR、GAP、REQ、TEST，也不將它們冒充執行過的套件。真正缺失的 Client 靜態導線應由 T02/T03 繼續，不是全部推給 Server 自行猜。

## 9. 開發者一眼可用的開工決策與驗收回報格式

**第一筆新 Server 開發工作應優先 `C04-E1b + E2a + E3a` 的安全離線部分**（已存在 D1–D4/E0/E1 inspector 不能重做）；之後依 T02/T03 已證 Source Gate 實作 E2b/E3b，再由 F0 使原版 Client 真正有登入回覆。其間可先讓玩家用 D1 的 hash/Port preflight 及 D2/D4 JSONL 判斷是否有實際 TCP ACCEPT/RX（需注意當前 Client SHA/endpoint 尚未核對）。

交付者每次須回報：`Server main commit`、`S00 pin`、`Client SHA/variant`、`work_package`、`implemented code/API`、`tests/CI`、`I40 gates evidence class & outcomes`、`runtime enabled?`、`actual original Client observed?`、`sensitive logging check`、`unresolved source RR/offset/branch`、`rollback`、`next action`。**Server offline PASS != T01 native bounded PASS != RR accepted != native runtime login PASS**。

未經使用者另行授權，不修改 Client/Server 程式、資料庫，或主動連線到原版 Client/Server。此規劃本身不代表已可使用任何原版 Client 登入，不允許取消 `NativeContractAdmission` 的 fail-closed。

## 10. 源資料

- [Iteration 38 完整 D/E/F](S00-20261031-ITERATION-38-C04-KR-LOGIN-GATEWAY-PLAN.md)；[Iteration 39 M0–M3](S00-20261101-ITERATION-39-C04-LOGIN-RECEIVE-IMPLEMENTATION-CONTRACT.md)。
- T01 新整合 [bounded native handoff](../../research/handoffs/t01-20261101-extra-roy1-roy2-r0-r2/README.md)、[E81](../../kr-extra-roy/20261031-chatgpt-web-roy-E81-RR0009-F431F-Employ-UI-events-native-supplement.md)、[RR6 increment](../../kr-extra-roy/20261101-020429-chatgpt-web-roy-RR0006-Rx-boundary-node-lifetime-post-error-frame.md)；目前新 `CLM-NET-0037` 和 `CLM-CHAR-0007` 都只是 PARTIAL。
- 權威正式 `research/requests/index.json`、`research/claims/index.json`、`research/intake/index.json`、`design/gaps/index.json`、`design/requirements/index.json`，及 `spec/protocol/SPEC-NET-0001/0002/0003.md`、`spec/session-account/SPEC-AUTH-0001.md`。原版 Client 可到登入畫面的門檻不因此上升。
- 獨立 Server：`src/Tartaros.Server.Host/Program.cs`、`src/Tartaros.Network/{DiagnosticGateway,SafeTcpEventJournal}.cs`、`src/Tartaros.Protocol/{KrE1OfflineEnvelopeInspector,NativeContractAdmission,KrLoginChoiceOfflineLayoutProbe,KrFOfflineChoiceInspector}.cs`、`src/Tartaros.Session/LocalLoginCoordinator.cs`、`docs/C04-D1-D2-D3-E0-IMPLEMENTATION.md`、`docs/C04-D4-IMPLEMENTATION.md`、`docs/C04-E1-F-OFFLINE-IMPLEMENTATION.md`、`contracts/spec-revision.json`。

**最終狀態**：T01 同步後，S00 已把 Server **M2 原版登入接收並驗證的完整工程路徑**規劃到 C04-E3b；仍缺具體真正的 first-wire/login C2S source 及真 Client 授權測試，故 M2 只能 `PLANNED_AND_NATIVE_BLOCKED`，不能因離線 Server 模組開發好便標 Client 已登入。
