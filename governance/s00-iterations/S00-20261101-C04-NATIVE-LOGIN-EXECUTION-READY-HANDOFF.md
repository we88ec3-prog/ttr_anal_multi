# S00 C04 — 原版 Client 登入完整可執行交接（M2 接收認證 → M3 成功畫面）

> **規劃狀態：DESIGN_DELIVERY_COMPLETE_WITH_NATIVE_EVIDENCE_GATES。不是 NATIVE_LOGIN_IMPLEMENTED。**
> 基線：S00 main `e7c9befa49c46afdd3784ae9a910c7834f50e91e`、Server main `b4f187445d1d287feab3ceee9ea86d9dc0f75d63`；KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。實際截圖為 Tartaros Rebirth，EXE/BIN 版本、Client 實際連線 endpoint 尚未比對；開發實作前先核對更新的 main。
> 本文件只整理 S00 規格交付，沒有更動 Client、Server 程式、資料庫或執行原版 Client；也不新增 RR/GAP/TEST、批准原生 Runtime 或升級 SPEC。

## 1. 這次終於要達到的目標與完工定義

先前 Iteration38 規劃 D/E/F、Iteration39 規劃 C04-D1..D3/E0/E1/E2/E3/F0 與 M0..M3、Iteration40 核對最新 Server 並細分 E1b/E2a/E2b/E3a/E3b，**M2 工程已完整規劃，但缺最後的「逐項交付可開始／停止條件」及明確 M3 完工路徑**。

本次收斂後不用再新增一輪籠統的登入設計；按本文件直接分流 Server 工程、T02/T03 原生補證和經授權的 Client 驗收。

- **M0＝Raw TCP**：Listener bind、Accept、RX bytes；不足以證實是登入請求。Server 現有 C04-D1～D4 diagnostic-only 已實作，未證玩家截圖 Client 與它連上。
- **M1＝Original login C2S parsed**：同版 Client 的真實 frame 經驗證的方向/slot/scene/marker/解碼後被辨識為真正 E8 或 000F 登入訊息。
- **M2＝Server received and authenticated original login**：同一個原版 Client 連線的有效 C2S request 被交給 C02 帳號驗證、停權與 Session lease，正確帳密成功，錯誤／停權不能建立 Session。**這是「Server 接收 Client 登入」的明確完成條件。**
- **M3＝Client login success observable**：Server 依已證實的回覆契約送出 S2C，原版 Client 真正切換到登入後下一畫面；沒有 M3 就不得說「原版 Client 已能登入」。因此 M3 必須正式列在相同開發主線，不得因 M2 完成就遺忘。
- **M4＝角色清單畫面可操作**：登入後選服/切線及 C03 roster 初始化，獨立於 M3；若無角色還要 UI-02 建角入口，依既有 RR-0009/0010。C05 戰鬥/教學非 M2/M3 前置。

完整既有機讀驗收沿用 [Iteration39 I39-01..18](S00-ITERATION-39-C04-LOGIN-RECEIVE-GATES.json) 與 [Iteration40 I40-01..15](S00-ITERATION-40-C04-LOGIN-M2-ACCEPTANCE.json)，不要產生第三套重複 Gate。

## 2. 最新 Server 已完成什麼？嚴禁重做什麼？

| 既有 Server 源檔與責任 | 真正已完成範圍 | 接續缺口 |
| --- | --- | --- |
| `src/Tartaros.Server.Host/Program.cs` | HTTP 5080 + opt-in localhost 診斷，`gameListener=false` 代表原生遊戲服務未啟用 | 依來源門檻另外加入正式原生登入服務，不重寫 HTTP |
| `src/Tartaros.Network/{DiagnosticGateway,SafeTcpEventJournal}.cs` | C04-D1/D2/D3/D4；TCP RX chunk、安全 metadata JSONL/輪替/大小/故障隔離，不發原生 TX | 之後加入來源核准的 frame/app/認證相位事件，仍不寫密碼/Hex |
| `src/Tartaros.Protocol/KrE1OfflineEnvelopeInspector.cs` | E1 部分：`Incomplete/Rejected/BoundedShapeOnly`、外殼長度與 marker；**不是 decoder** | E1b 串流累積、正負例、source-reviewed 解碼 |
| `src/Tartaros.Protocol/{KrLoginChoiceOfflineLayoutProbe,KrFOfflineChoiceInspector}.cs` | E8/0F、S2C 0x13/0x7A 的局部離線檢查；**不是實際登入 request/response codec** | E2a/2b/ F0 分別建模與後續核准 |
| `src/Tartaros.Protocol/{NativeContractAdmission,ProtocolProfile}.cs` | 原版 KR/TC 全部 fail closed，`UnverifiedFrameCodec` | 未獲來源審核不得把 CanEnable 改 true |
| `src/Tartaros.Session/LocalLoginCoordinator.cs` | C02 `AuthenticateAndClaimAsync(name,password,Guid,TimeSpan,ct)`、`SessionLease`，受信內部用；原碼不允許直接開放 TCP | E3a 內部信任界面，E3b 原生入站 gate；必須用同管理後台的資料來源 |
| `src/Tartaros.Network/IConnection.cs` | `Id:long`、`ReceiveAsync`、`SendAsync`、`CloseAsync` | Gateway 必須自行生成 `Guid ConnectionId` 並對應 lease，不能把 Client bytes 當 session 身分 |
| `contracts/{spec-revision,c04-e1-f-source-gates}.json` | 仍 DRAFT/PARTIAL、native codec 和 response 都 OFF | source review + security + Client runtime 驗收後逐段再評估，不因 pin 更新直接生效 |

C02 管理後台使用的 SQLite/PG Provider 必須與遊戲 Gateway 共用可核准的帳號／停權／Session 來源；若不一致，禁止 fallback 到一個空的 InMemoryAccountDirectory 後宣稱管理後台帳號可以登入。

## 3. 最終開發依賴與責任 — 直接交給 Server Agent 依序執行

| 順序 | 工作包、Owner | 輸入與必須交付的輸出 | 立即可做? | 完成證據 |
| --- | --- | --- | --- | --- |
| 0 | ENV-01 / Server operator＋T02 | 玩家本機 EXE/BIN SHA、Client endpoint/Port/DNS/launcher 設定來源、Server 實際 bind、只讀日誌已否出現 Accept/RX、同版判斷 | **唯讀預檢可立即做**；原 Client 執行/抓包須另授權 | I39-01/I40-11；沒有 Client 建立連線不能推論帳密有問題 |
| 1 | **C04-E1b / Server** | 既有 E1 inspector + per-connection bounded stream accumulator；判 `Incomplete/InvalidLength/BadChecksum/BadDecompress/Unsupported/Complete`；能分離 0x0BBB/0x2633 錯誤完整 frame、部分 frame、後續 frame | **立即做 OFFLINE** | I40-03/04，Synthetic CI；不是 M1 |
| 2 | **C04-E2a / Server** | E8 112B narrow vs 000F 214B UTF-16 離線 candidate DTO；不偷解 opaque，不假定 CP949/UTF8；credential short-lived、不寫 log | **立即做 OFFLINE** | I40-05；沒有 native scene/slot/first wire，不准呼叫 C02 |
| 3 | **C04-E3a / Server** | SyntheticTrustedLoginCommand → 受信 C02 `LocalLoginCoordinator`，同一 SQLite/PG provider、ban、lockout、重試、重登/舊 close、lease 競態和 DB-down | **立即做 OFFLINE + security review** | I40-09/10；不得把 offline C02 auth 稱為原版成功 |
| 4（與 1～3 並行） | **C04-E1native / T02＋T01** | 真正 first exchange 的 direction、slot/lane、Connect 條件、Conn+A02C 模式與 writer fallback、完整 C2S/S2C frame 長度/marker、RX error/scene gate | 原件 BIN 靜態繼續追；**尚缺正向鏈** | I40-06；沿 RR-0001/0004/0006/0007 |
| 5（並行） | **C04-E2native / T03＋T02＋T01** | `0x440790` → `0x4A3360/0x4A31B0` → manager queue/OS socket；E8 +104..109 opaque writer/codepage、000F 固定值，兩者登入場景和方向 | 原件 BIN 靜態繼續追；**尚缺正向鏈** | I40-07；沿 RR-0003 |
| 6 | **C04-E2b/E3b / S00 review＋Server** | 經審核同 SHA 版本專用真正 C2S frame/LOGIN parser、slot/scene/phase gate、C02 受信 bridge，安全 fail-closed | **只有 source＋安全審查＋明確本機 runtime 授權才可啟用**；API 可先做 offline | I40-08/12/13 → **M2** |
| 7（與 4/5 並行） | **C04-F0-source / T03＋T02＋T01** | 真正 login request→result pairing、必要 S2C success/reject bytes、scene/slot/frame/先後、0x13 與 0x7A 不等價、下一步選服條件 | **仍需來源** | I40-14；沿 RR-0003/0005/0007 |
| 8 | **C04-F0-native / S00 review＋Server** | 已核准 S2C writer、成功／失敗／停權、SendAsync error、與真 Client UI 同會話驗收 | **核准來源與測試授權後才啟用** | I40-15 → **M3** |
| 9 | **C04-F-full / Server＋T03/T06** | 選服、跨線、角色清單/創角 UI；不是 M2/M3 的替代成果 | 後續 | I39 FLOW/CHAR/UI → M4 |

**關鍵：M2 可用 Server-only 工程與原生研究平行推進，不必停工等待全部官方 Server 規則；但 Client wire 必要欄位不可由 Server 自行猜填。** C05-P04/戰鬥/教學與此開發主線獨立。

## 4. 開發 API 與安全狀態轉換契約（建議結構，非現存程式類別）

```text
GameConnectionContext {
  serverConnectionId: Guid; transportConnectionId: long; runId: Guid;
  clientBuildSha: verified|UNKNOWN; protocolProfile: UNKNOWN|REVIEWED_KR;
  phase: Accepted|RawRx|CandidateFrame|NativeFrameValidated|
         LoginValidated|AuthInProgress|AuthAccepted|AuthRejected|
         NativeReplyUnavailable|NativeReplySent|Closed;
  exactLease?: SessionLease; sourceGateRef?: string;
}
FrameOutcome {
  kind: Incomplete|CandidateEnvelope|InvalidLength|BadChecksum|
        BadDecompress|UnsupportedMarker|UnsupportedBuild|SourceReviewedComplete;
  consumedBytes: int; bufferedBytes: int;
  direction: C2S|S2C|UNKNOWN; appOpcode?: ushort;
  payload: OwnedSensitiveBuffer?; // only after native source gate
}
TrustedLoginRequest {
  buildSha; direction=C2S; slot/scene source state; variant=E8|0F;
  charset=verified|UNKNOWN; opaqueFields=preserved;
  credential: EphemeralSecret; serverConnectionId: Guid;
}
AuthDecision { Authenticated|Rejected|Unavailable|Timeout|NativeUnverified;
               exactLease?: SessionLease; nativeReplyAvailable: bool; }
```

- `CandidateEnvelope` 只是完整標頭/長度外殼；若 build、frame direction、scene/slot、密碼字串、opaque 來源仍關鍵未知，不可進入 `TrustedLoginRequest`。
- `SyntheticTrustedLogin` 與 `SourceReviewedNativeLogin` 必須分開成不可互轉的測試／正式類型，禁止使用環境變數把測試資料改成已核准原生輸入。
- `IConnection.Id` 由 transport 給 long；Gateway 自己發 Guid，用 full SessionLease/generation fencing 防止 old-close 撤銷 new connection；同 socket 重送避免第二次 Claim。
- `E8` local builder payload `LE16 00E8`，總112 bytes，51B narrow slots at +2..52/+53..103；+104..109 opaque，+110..111 source WORD，output 文字用 CP_ACP，但真正 runtime codepage/初始化仍待核對。`000F` local builder payload `LE16 000F`，總214 bytes，51 UTF-16 code-unit slots at +2..103/+104..205，+206..209=00010001、+210..211=0034、+212..213 source WORD。**這是 Client 本地 builder，不能直接稱真 wire 或官方帳號政策。**
- 在沒有真正 S2C source 之前不送假 success/error status；任何 Client 仍在登入畫面，不能只以 `C02 Authenticated=true` 判 M3 通過。

## 5. 給研究者的精確 evidence 檔案交付格式（沿現有 RR，不新增重複）

### T02：C04-KR-FIRST-WIRE-EVIDENCE
`BIN SHA；function VA＋原生 instruction bytes；Connect slot＋實際 endpoint source；first send/recv 的必要 scene/phase/handshake；direction；Conn+A02C 的初始化/間接 writer/fallback；frame header／length／checksum/decompress；lane/dispatch；partial/invalid/retry；正反例；仍未知的原生呼叫鏈；T01 限定審核範圍。`

T01 已整合的 `SRC-0653／CLM-NET-0037 PARTIAL` 可供 C04-E1b 的錯誤幀與下一幀測試設計；checkout-before-pointer-guard 只是一條 **Client-only 條件式 pool 風險**，未證合法連線會觸發，也不是 Server 必須模仿的記憶體行為。正常 partial+下一次 WSARecv 的 8199<0x5000 只是帶前提推導。

### T03：C04-KR-LOGIN-C2S-EVIDENCE
`BIN SHA；0x440790 mode 0x52/0x54 的真正 scene／觸發；E8 vs 000F builder → queue → socket producer；帳號/密碼 slot 範圍；E8 +104..109 writer provenance；CP_ACP/FBA808 codepage runtime；固定/不固定尾欄；失敗/重送；反例；T01 限定審核。`

### T03/T02：C04-KR-LOGIN-RESULT-EVIDENCE
`真 C2S variant→S2C response 的 matching；是否有 Server-first 必需回覆；LOGIN scene app0x13/0x7A 是否、何時可達；status/success/reject；完整 S2C 欄位/byte extent；group/child/endpoint/下一個 UI／socket handoff；正反例；原生 SHA／原稿 blob；T01 審核分級。`

**原版 Server 內部的帳號資料庫、密碼雜湊與策略無須還原**，由 Server 自訂受信 Provider/ADR；但不可把 Client 必須接受的 Byte layout、frame/response/順序交給 Server 亂猜。當靜態已盡，須列已查上下游與需另授權之本機 runtime 觀測；不得以「等原版 Server」提早放棄 Client 可查線索。

## 6. 實作測試、錯誤分類與回滾

| 分類（均為 Server 自設診斷碼，不是 Client 錯誤 status） | 應保存去敏證據 | 正確行為 |
| --- | --- | --- |
| LISTEN_FAILED/WRONG_ENDPOINT | listener IP/Port/OS bind code；若無 Accept **不能推定 Client 無 SYN** | 核對本地設定／防火牆，不亂選 8414/15/16 |
| ACCEPT_NO_RX/FIRST_BYTES_TIMEOUT | ConnectionId、accept/EOF/timeout 時間、RX bytes=0 | 需查 Client-first/Server-first，不能盲發 greeting |
| FRAME_INCOMPLETE | 收到 raw bytes、buffer 長度、等待/timeout | bounded retain，不誤判 malformed |
| FRAME_INVALID_SIZE/BAD_CHECKSUM/BAD_DECOMPRESS/UNKNOWN | 只記可靠分類、marker provenance，無 raw login | 不產生 app login/C02 claim，選安全拒絕 policy |
| LOGIN_FIELDS_UNVERIFIED | scene/slot/build/opcode provenance 與未證欄名（不記實際值） | 不把任意112/214 bytes 當帳密 |
| C02_AUTH_REJECTED/BANNED/PROVIDER_DOWN | domain status、Session lease 申領成功與否（無 token） | 無成功 Session、provider down fail-closed、不 fallback InMemory |
| OLD_CONNECTION_CLOSED | exact lease/generation、連線 id，不記私有憑證 | 舊 close 不撤銷新的租約 |
| AUTH_DECIDED_REPLY_UNAVAILABLE | C02 已判定、F0 source gate 未過 | 不送猜測的 0x13/0x7A；M3 不通過 |
| TX_FAILED/CLIENT_UI_UNOBSERVED | send error、connection/run ids、去敏 Client 畫面驗收 | TX OS write≠ Client 已收到或進畫面 |

**最低測試**：TCP fragmented/coalesced、bad+good／invalid length、E8/0F bytes/UTF16/opaque/no-terminal、密碼 sentinel 不出現在任何 JSONL/rotation/exception/health、同 Admin DB 帳號／ban/lockout、雙登入/重送/舊連線 close、DB down、Port 10048、log 滿/ACL、host shutdown。用隔離 synthetic 測試時明確標記 `OFFLINE_SYNTHETIC`。真正 Client M1/M2/M3 需經使用者**另行授權**，以相同 Client build、session/runID、安全日誌和 Client UI 結果驗收；不要求上傳私人 pcap/明文密碼到公共 Git。

**回滾策略**：一旦原生 decoder/驗證/回覆結果與預期不同，立即停用獨立 native feature flag，退回 C04-D diagnostic-only、保留 HTTP 5080/Admin 5091，使用 exact lease clean-up；拒絕無界重試，不修改 Client EXE、BIN 或官方遊戲服務。log write 失敗以 bounded drop counter 表示，不把沒有 log 誤當沒有收包。

## 7. 一次性交付閉合與給 Server 開發者的開工指令

**S00 設計收斂判定：** C04 原版登入已可明確派工至 **M2**，並已安排能消除 Client 登入失敗的 **M3**；後續應做 Server 程式和 T02/T03/T01 具體證據，不以再寫一份宏觀計畫代替工作。source 改變時只回填既有 SPEC/GAP、I39/I40 及交接，不建立影子台帳。

> 請同步 `ttr_server_roy/main`，先閱讀 S00 此份 `S00-20261101-C04-NATIVE-LOGIN-EXECUTION-READY-HANDOFF.md`、Iteration39/40、Server `AGENTS.md` 和現有 C04-D1..D4/E0/E1/F offline implementation notes。**禁止重做 C01/C04-D**。直接開發 `C04-E1b＋E2a＋E3a` 的 offline、安全分層接口、SQLite/PG 帳號與 Session integration tests；逐項提交程式碼和驗收報告，記載 Server/S00 SHA、pass 的 I40 Gate/Client SHA、failed source gap、是否 runtime enable。與 T02/T03 按既有 RR 並行補 first-wire、E8/0F 真 queue-to-socket、0x13/0x7A 成功回覆的方向/時序證據；只有契約審核、安全與另行 Client 測試授權符合時才接入 E2b/E3b/F0 的 native listener。若證據不完整，保留 Unknown 和 fail-closed，不得假裝已可讓原版 Client 登入。最後按 M2「原生 Client request→C02 Auth」和 M3「Client 接受正確 reply→下一畫面」**分別驗收**，完整角色畫面 M4 另外驗。

來源： [Iteration38](S00-20261031-ITERATION-38-C04-KR-LOGIN-GATEWAY-PLAN.md)、[Iteration39](S00-20261101-ITERATION-39-C04-LOGIN-RECEIVE-IMPLEMENTATION-CONTRACT.md)、[Iteration40](S00-20261101-ITERATION-40-T01-SYNC-C04-LOGIN-RECEIVE-DELIVERY.md)、[T01 R0–R2](../../research/handoffs/t01-20261101-extra-roy1-roy2-r0-r2/README.md)、`research/requests/index.json`、`design/gaps/index.json`、`design/requirements/index.json`。本次不新增正式 RR/GAP/TEST/REQ 或升 SPEC；所有未經原版 Client 證實 Gate 維持 NOT_RUN/BLOCKED。
