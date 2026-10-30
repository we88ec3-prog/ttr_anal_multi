# S00／T01 — RR-0005 KR 有界靜態研究正式驗收（2026-10-30）

## 0. 審核對象、核對基準與決議
- **唯一 RR**：`RR-0005`（owner T02, KR；對應 `GAP-NET-0002`），開工 `main=43867aa50c15984017a9b0ede94d502c4516e1b7`。
- **提交原稿**：[`E56`](../../kr-extra-roy/20261030-091559-chatgpt-web-roy-E56-RR0005-bounded-static-completion-transport-owner-retry-reply.md)；Git blob **`843889349bb58209c02221e720800f0e9e3ff9d8`**；收件 `SRC-0451`。E51–E55 完整原作者原稿另已原樣存入 main 並登錄 `SRC-0452..SRC-0456`；不以較新時間戳覆寫舊實證。
- **KR 原始證物**：`Tartaros.bin` **12,472,320 bytes**，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 i386 `.text` VA `0x401000` / raw `0x400`，`.rdata` VA `0xBD2000` / raw `0x7D0600`。原始遊戲僅離線唯讀，不執行、patch、連線或製造 pcap。
- **獨立 native 複驗**：前已提交 T01 第六批 [R2 technical review](../../research/handoffs/t01-20261030-extra-t16-r2/batch6/R2-E56-REVIEW.md) 及 [驗證腳本](../../research/handoffs/t01-20261030-extra-t16-r2/batch6/verify-native.py)，本次再次於相同原始 BIN 重跑 **155/155 條定點 machine instructions、37/37 條 E8/E9/Jcc branch targets、5/5 個 vtable pointers PASS**。另外從 native sections 重新解碼 `0x495610`、`0x4957C0`、`0x8069A0`、`0x806A00`、`0x4C37A0`、`0x4C3C10` 和 `0x66C090` 相關實際入口。此為限定 R2，**不是**所有 20 個函式 rooted CFG、全域競態或來源全文 R3 FULL-PASS。
- **兩階段決議**：T01 判定「研究主張的有界證據、版本、反例和未知範圍已足供研究交付評估」；依本次使用者明確要求完成 RR 驗收，由 **S00 流程角色**在同批公佈的唯一 RR 台帳將 `SUBMITTED→IN_REVIEW→ACCEPTED`。**ACCEPTED 僅表示 RR-0005 指定的有限 Client 靜態研究範圍已交付**，不認定整個 `GAP-NET-0002` 關閉或 Server 封包已可互通。
- **不做的升級**：E56／E51–E55 全文 `FULL_PASS_DOCUMENT_SCOPED`：**否**；新增 `NATIVE_VERIFIED`：**0**；`SPEC_CONSUMABLE`：**未升級**；`SPEC STABLE`：**0**；Client 實際連線／Server 互通／遊玩驗證：**未做**。

## 1. RR 原始 question / acceptance checklist

`question`：`Join T03 0x13 response and choice UI with KR 0x495610/0x4957C0 Connect call sites; derive actual conditions/order, close/retry/slot ownership and initial frame per connection. Separate legacy static port values from server deployment recommendations.`

`acceptance_criteria`：`Bound actual KR Client Connect/close/port roles and 0x13 login-to-choice handoff sequence including first sender/response, error/retry behavior, without inventing endpoint authority.`

| 必答項目 | 版本限定的 evidence / 主要 native 位址 | T01 有界裁決 | 對 Server / SPEC 的限制 |
|---|---|---|---|
| S2C `0x0013` / `0x007A` 入站 | `0x807B40→0x8040A0→0x4930E0→0x4C4670→0x4C37A0/0x4C3C10`（E56 A.14–A.17） | **CONDITIONAL / source-scoped**，前置 frame/mode、字串及 handler 前提不可省 | 0x13/0x7A 是「選服資訊可達」來源，**不保證新 key 第一筆回覆就是它** |
| 選服 UI / endpoint 來源 | `0x4C3080` list、`FE1B54`、UI resolver `0x66C090`，call `0x66C1A7` / `0x66C247→0x4957C0` | **PARTIAL**：record+0x0C 的 dotted IPv4 ASCII 僅為受條件束縛的 Client 讀取 | 不可把文字 endpoint 推成官方 Server IP，亦不等於部署建議 |
| key0 / key2 Connect | `0x4957E0–0x495803` vtable+0x18、key0:port `0x20E0`，key2:port `0x20DE`，lane2 | **PARTIAL 有原生正證**；兩個 Connect 方法都被嘗試，接著才判斷非 NULL | `0x20E0=8416`、`0x20DE=8414` 是舊 Client 常數 |
| key1 Connect/reuse | `0x495610`，port `0x20DF=8415`、key1、lane2；6 direct caller `0x6D6377/6424/6508/65C8/670C/696C` | **PARTIAL 有原生正證**；第三參數1與0的 shutdown 前提不同，舊 `BF60` 非 NULL 可不重建 Conn | 不能用一筆 key1 模板覆蓋六種 caller |
| Client slot aliases | `Client+BF60` key1、`+BF64` key0、`+BF68` key2；constructor `0x48ACB6–0x48ACC2`、成功 writer `0x495794/595B/5962` | **PARTIAL**，指定 writer/條件成立；`BF58` 未知別名、不得硬等同第四 key | slot 是 Client 本地 pointer 而非 Server 強制相同結構 |
| key0 首次本地 C2S 候選 | `0x495884` WORD `0x0001`、`0x495935–0x49593D` key0 送出長 `0x39=57` | **PARTIAL**；是 Client payload queue candidate，非完整 wire，部分 bytes 依 `0x404BA0` | 明確分 `payload builder→local queue→send pump→WSASend→wire` |
| key1 C2S 候選 | 4 條 queue caller 長 `0x38/0x68/0x2CE/0x2CE`，另2條 callback-only | **PARTIAL**；六入口原生 E8 與分支均交叉核 | 沒有固定唯一 key1 first wire，無原版 session trace |
| local queue / recv-post 成功 | `0x8069A0→0x8060D0`：key 欄／長度／queue 容量 gate；`0x806A00`：WSARecv、WSA_IO_PENDING 997、hard error | **PARTIAL 有原生正證**：`0x4957C0` 的 return1 **未檢查** local send 和兩個 recv-post 的 virtual return | 「Connect helper 回1」≠本地 queue 成功≠WSARecv 成功≠網路 wire 完成 |
| partial Connect failure | `0x495807/49580F` NULL guard → `0x49597E/4959B0/4959D0` shutdown-by-key／return0 | **PARTIAL 有原生正證**；本函式未自身 retry，其他 UI events 可再觸發 | 不可將 shutdown-by-key 當同步 closesocket/Pool 已收完 |
| same-key oldConn 所有權 | `0x806C9E→0x806CB3(0x7B6890)→0x806CC7/0x806CD2`；T01 rooted tree-erase + Pool28/48 | **PARTIAL**：erase tree node 不等於 oldConn close，另有 `0x490FE0` conditional Pool producer；`Conn+14==0` 也可來自 reset | 既不能保證無 leak/UAF 也不能假設一定會 leak |
| reset / socket close / IOCP | `0x806FC0` close-by-Conn；`0x805F50` reset；`0x806D84` GQCS completion key | **PARTIAL**：所見物件與操作分離，未覆蓋所有 cancellation/race | 不承諾所有 Conn generation / handles 都安全回收 |
| 首個 S2C 回覆與 retry 全域策略 | 已知 `0x807B40` frame/dispatcher consumer；Client 各函式局部失敗/可能再觸發 | **UNKNOWN（明確合理）**：原版 Server 所送 first response opcode/順序與 runtime 重試頻率不是由 Client 同一份靜態 BIN 單獨可知 | 新 Server 必須自行以 ADR/TEST 設計與驗證，不能把推測說成原生 |

這 12 項構成 RR-0005 的**限定研究契約**。全部對應明確原始 Client 資訊或誠實記錄其不可證邊界；**不是**要求原版 Server 內部機制、動態 race 或實際玩家 session 現場已恢復。

## 2. 獨立 cross-check 細節與反證

1. **key0+key2 非 NULL才到達 local queue / recv 投遞；但返回成功仍不表示下游成功**：原生 `0x4957EA` key0 Connect, `0x495803` key2 Connect, `0x495807/80F` test, `0x49593D` send-by-key, `0x49594B` key0 recv, `0x495959` key2 recv，接續 `0x49595B/5962` 無檢查三次 vcall return 就寫 aliases、`0x495968 mov eax,1`。對 `CLM-NET-0019/0020`，保留 **PARTIAL** 及 fail preconditions。
2. **key1 六 caller 的明確不同發送候選**：原生 6 direct `E8` 皆指向 `0x495610`；第三參數僅 `0x6D6508` 是1，另外5條是0；後續兩 callback-only、四條 local key1 queue 長56/104/718/718。不能衍生「同一次連線全部四包必發」。相關 `CLM-NET-0018` = **PARTIAL**。
3. **queue/sock return gates**：`0x8069A0` map not-found →0、len0→1 且不 queue、len>0 委派 `0x8060D0`；`0x8060FA cmp Conn+A0A4,0x12C` 若超過300有回0分支；`0x806A4C` 的 WSARecv 返回 -1 且非997 → vtable+0x24 close-by-Conn + return0。上層不看這些 return，不能宣稱 I/O readiness。
4. **0x13/0x7A 樣本**：原生 `0x4C37A0` 檢查 byte `[record+0x16]` 的 mode (例如 `0x4C3824 cmp 5`), 而 `0x4C3C10` 則取 `[record+2]` 並傳 `[record+6]` 至 `0x4C3080`。二者資料形狀不相同；report 未編造兩者必有固定因果順序。尚未完成所有最短可讀 payload 驗證，相關欄位不可提升為 Server 正式 MUST。
5. **oldConn 所有權與 BF58**：`0x7B6890` tree-erase 之受檢 direct chain 最後 `0x89120C→HeapFree` 的目標是 tree node；`0x490FE0` conditional Pool28→48 路徑與 reset `0x805F50` 另行成立。前後證據不矛盾、但不能證所有 oldConn 的完整持有者消失。BF58 並非已證等於 key1/0/2 alias；後續有意義之 Client 補證可另開限定問題，不作本 RR 虛假交付條件。
6. **範圍與既有 CLM 去重**：關鍵有界主張由 `CLM-NET-0014..0020` 已保存；沒有再新增重複 ID；其中所有 RR-0005 相關主張維持原有品質，不因研究請求被 S00 接受而自動變為 `NATIVE_VERIFIED`。

## 3. S00 正式研究驗收決議和後續責任

**決議：`ACCEPTED`（僅限此 RR 的 bounded KR Client static research delivery）。**

理由：E56 已按當前 RR 每項 clause 提供可核對的 native caller/callee、關鍵 branching、ports/slots、first local send candidates、close/error/retry 範圍及 Client-only source-limit；T01 定向複核對主要路徑與反例沒有確立會推翻此有限交付的相反 machine code。未知 wire/S2C 首回覆已明確保留，既不推成假的原生事實，也不因它本來必須由 Server/runtime 證明就虛稱 Client 原生部分沒有研究。對這個**研究交付**給出 S00 有界接受，而非改寫 S00 的 Client-facing implementation readiness。

**維持未解／不可同步變更：**
- **`GAP-NET-0002 = OPEN`**：完整可實作方向別消息、真實 first response、最小 payload schema、同一 session 順序及異常恢復仍不足；不把 open GAP 自動關閉。
- **`SPEC-NET-0002`, `SPEC-AUTH-0001`, `SPEC-FLOW-0001` 仍 `DRAFT/PARTIAL`**；TEST 仍 `OFFLINE_SYNTHETIC`。沒有核准 Server 端口部署、frame marker/mode、一律回覆之 opcode 或傳輸次序。
- **Client 待逆向**：T02/T03 的 first incoming response payload/mode 安全下界、key1 builder 每個 payload offset、同 key Conn 全部實際 owner/cancel；如未來是 **Server 可實作規格的 Client 必需阻塞**，由 S00 建精確新 RR/GAP 或修改既有別項，不藉本 RR 偷改 scope。
- **Server 待開發**：帳號/會話政策、endpoint 配置、斷線/重連策略、具來源的 success/error 回覆；僅把已證 Client 接口當相容約束。
- **跨功能待整合**：T02 transport、T03 選服 UI、T16 quest/場景，按獨立來源 blob 與版本。
- **待遊玩驗證**：合法同 session first wire/first S2C、connection migration、timeout/cancel、重登入/選服狀態轉移。
- **T01 嚴格軸**：沒有 E56 全稿 `FULL_PASS_DOCUMENT_SCOPED`、沒有新增 `shared/verified-knowledge` CK、沒有清除舊 FAILED/NEEDS_FIX，也沒有修改 T02 原作者研究成果。

## 4. 權限與可重現交付

- T01 原生複核與 S00 RR 限定研究結案分別記錄為唯一 RR append-only `SUBMITTED→IN_REVIEW`（T01）及 `IN_REVIEW→ACCEPTED`（S00）事件；S00 紀錄為本次使用者明確要求「完成 RR5 驗收並提交」下的正式**流程角色**決議，不應被理解為另有獨立真實使用者執行了 Client runtime 測試。
- RR 狀態唯一權威 `research/requests/index.json`；鏡像索引 `governance/reviews/index.json` 僅保存本項決議指標與精確原始 blob SHA；兩者須通過一致性驗證。
- 原始 R2 機器碼 evidence/腳本：`research/handoffs/t01-20261030-extra-t16-r2/batch6/`；其它前置 Pool、tree、S2C 欄位有界審核：`.../batch4/`, `.../batch5/`。驗證只可重現有限靜態判斷，不宣稱完整原版互通。
- GitHub 提交經 ref lease 保護，不 force push；發布後逐檔讀回 RR state、mirror blob、來源 E56 與 inbox，再確認結果。

