# T01 — T10-108～114 有界來源整合與 KR BIN-first 網路資料流 R1/R2

2026-10-30 Asia/Taipei。T01 source/claim 受理者：chatgpt-web roy。此為既有 T10 完整原稿的**主張級整合與原生限定複驗**，不是新 T10 正式段號，也不接管 T02 封包底層主責。

## 0. 基準、判定與來源身份

- 發布前驗證目標 GitHub `main`；本輪研究起始 `4a664439514e107aaa40bc3639e1e2daf46d0d45`，提交時須再次核對最新 head 並以該 head 作原子 parent，不覆寫其他 Agent。
- 唯讀原始 KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。未執行/修改 Client、未與原版 Server 連線、無現場封包擷取。
- PE32/x86 `.text` VA 0x401000 / file raw 0x400，限定地址換算 raw=VA−0x400C00；`.rdata` VA 0xBD2000 / raw 0x7D0600，raw=VA−0x401A00。FB/FD 全域多屬執行期地址，不能以 text 規則假造 raw 值。
- 預先閱讀 repo AGENTS / T01 T10 README、T01 inbox、T10 inbox、RR、governance/t01-integration-workflow、`shared/verified-knowledge/README.md`。T10 沒有新正式 RR；此批不更動已認領／已接受的其他 Task RR。
- 七份來源精確 blob 與 `research/handoffs/t01-t10-roy-20261029/sources.json` 及 `research/intake/index.json` 相同，建立有界 R1 和 R2 的 4 條不重複主張，絕不標全文 FULL-PASS。舊 CLM-NET-0004/0005/0006、CLM-NET-0014..0017、CLM-COMBAT-0002 在其原 scope 保留，僅按需關聯，不覆寫或抬高證據級別。

| 原文 SRC | 研究段 | 精確 repo 相對來源路徑 | 原始 Git blob | 本輪相關主張 |
|---|---|---|---|---|
| SRC-0372 | T10-108 | `kr-temp-roy/20261028-201546-chatgpt-web-roy-T10-108-KR-framed-receive-to-queue-producer.md` | `804572ab576259cc82162f56d68379b4f0f7d940` | CLM-NET-0032 |
| SRC-0373 | T10-109 | `kr-temp-roy/20261028-202433-chatgpt-web-roy-T10-109-KR-queue-owner-class-event-and-empty-record.md` | `dcc4609011535695f4573f5af4e729d150b146c8` | CLM-NET-0032 |
| SRC-0374 | T10-110 | `kr-temp-roy/20261028-203129-chatgpt-web-roy-T10-110-KR-IOCP-completion-to-frame-consumer.md` | `c63e65b5c3270ec3bb1b5339960668bae106ade3` | CLM-NET-0033 |
| SRC-0375 | T10-111 | `kr-temp-roy/20261028-204203-chatgpt-web-roy-T10-111-KR-WSARecv-WSASend-IOCP-overlapped-and-category-writer.md` | `af59cc9b4c11586b65989701d6e169d864e14876` | CLM-NET-0033; CLM-NET-0035 |
| SRC-0376 | T10-112 | `kr-temp-roy/20261028-204914-chatgpt-web-roy-T10-112-KR-connection-vtable-and-outbound-buffer-lifecycle.md` | `e236268d27bf0c54fa626e330cc8d84549ca883b` | CLM-NET-0034 |
| SRC-0377 | T10-113 | `kr-temp-roy/20261028-205943-chatgpt-web-roy-T10-113-KR-pending-send-pump-and-virtual-transport-gate.md` | `c23374e904a1977e6fd3b4eafc29db953801cf89` | CLM-NET-0034; CLM-NET-0035 |
| SRC-0378 | T10-114 | `kr-temp-roy/20261028-212516-chatgpt-web-roy-T10-114-KR-transport-vtable-to-WSASend-closure.md` | `4c58fab0d36bcc57914c0916ec1d39ee2c6a8e63` | CLM-NET-0035 |

## 1. 功能鏈 A：接收分框、非零 record 分類與 zero record 例外

**限定原生肯定結論（CLM-NET-0032）：** `0x806E08 call 0x807B40` 確立真正 parser entry 是 807B40；108 篇的 807B60 是其函式內位置，不能將兩者混為入口。`0x807BB0` 讀 payload length WORD，零或超過 0x1000 走拒絕分支；`0x807BD4` 讀第二 WORD，`0x2633→8`、`0x0BBB→6`、其他一般 `→4` bytes header，`0x807C34..3E` 做剩餘資料界線檢查。這是 Client input buffer 解析，**不代表特定 gameplay opcode**。

`0x807E50` 在長度 <=0x1000 的正常路徑中，以呼叫者指定 buffer 複製到 record+8，並將 record+4 設為長度，回 AL=1；超過門檻 AL=0。`0x807D7F` 讀 record+4，非零進 `0x807D9E` 讀 `context+A080` 作分類，`0x807DA4` push 分類、`0x807DA5` push record、`0x807DA6 call 0x489920` 取固定 singleton `FC10D0`，`0x807DAD call 0x8040A0` 才將 stack args 交給分類 append。`0x489920` `ret` 不消耗 stack 參數，**不是分類函式**。

`0x8040A0` 使用 category/toggle 雙 bucket 路徑與記錄指標追加；category==2 才呼叫與 owner+0x120 事件相關的 IAT；從本地訊號只能知道有額外喚醒，不證完成派送先後。若 record+4==0，`0x807D8F..97` 改走 `0x804310→0x8076F0` 專用路徑、跳過一般 `0x8040A0`；此為解碼後的內部零長度 record 路徑，**不是 wire 合法零長度 opcode**。無效 frame length=0 的 parser 分支與此 record 分支不能混淆。

```asm
807D83 cmp dword ptr [eax+4],0
807D8D jne 807D9E
807D90 call 804310
807D97 call 8076F0
807D9E mov ecx,[ecx+0A080h]
807DA4 push ecx
807DA5 push eax
807DA6 call 489920
807DAD call 8040A0
```

原稿先後更新：T10-109 補充 108 對 `0x489920` 仍未核實之 ABI 與零長度特殊分派；並不擅改 108 作者原文。

## 2. 功能鏈 B：WSARecv 發起 → IOCP 完成 → frame parser

**限定原生肯定結論（CLM-NET-0033）：** 由 PE import table 可核 `0xBD2278=CreateIoCompletionPort`、`0xBD2274=GetQueuedCompletionStatus`、`0xBD25BC=WSARecv`、`0xBD25B8=WSASend`；直接指向這些 IAT 的 `FF15` 精確 bytes 指定片段及完整限定掃描結果在同名 JSON，不等同所有 indirect API call 的全域窮舉。

`0x806A00` 的正常提交支線以 Conn+A030 建 OVERLAPPED，Conn+A044/A048 為 WSABUF(len=0x1000, buf=Conn+0x5018)，`0x806A4C FF15 BC25BD00` 呼叫 WSARecv。`0x806D84 FF15 7422BD00` 的 GetQueuedCompletionStatus 完成後，僅當 OVERLAPPED 指標與 Conn+A030 相同且 Conn+A0AC 本地 gate 成立，`0x806E04 lea edx,[eax+18h]`、`0x806E08 call 807B40` 送入 parser。這是已驗的**條件式**接收資料路徑，不能把 WSARecv 的 Conn+5018 輸入資料與 parser 累積區 Conn+18 說成同一位址，也不能從單一報告證明完整搬運與每筆 wire 抵達。

另一條 completion OVERLAPPED==Conn+A050 走 `0x806E7D..CA`：更新與 Tx 相關的 worker 計數、視 gate 呼叫 `0x8077B0`，並以 `InterlockedDecrement(Conn+A0B8)` 做送出請求計數平衡；**不呼叫** 807B40。Conn+A030 接收與 Conn+A050 發送的 identity 分離是直接 x86 支持，不能混淆為玩家普攻回覆。

**category writer**：T10-111 的 `0x806B29 mov [Conn+A0B4],2` 與 `0x806B33 mov [Conn+A080],eax` 分別是常數2與第4個 stack argument 的分類值。`A0B4=2` 不能改寫為 queue category2。`0x807D9E` 從 Conn+A080 取值的 producer 因此已有一個具體入口，但實際連線所用分類與所有其他 writer 未窮盡。

```asm
806D84 call dword ptr [BD2274]   ; GetQueuedCompletionStatus
806DE4 lea edi,[eax+0A030h]  ; rx OVERLAPPED candidate
806E08 call 807B40
806E7D lea edi,[eax+0A050h]  ; tx OVERLAPPED
806E83 cmp edx,edi
806EC4 call dword ptr [BD227C]  ; InterlockedDecrement
806A4C call dword ptr [BD25BC]  ; WSARecv
806B33 mov [ebx+0A080h],eax    ; category from arg14
```

## 3. 功能鏈 C：Pending list → frame → 兩個獨立 pump → 真正 WSASend

**限定原生肯定結論（CLM-NET-0034）：** T10-112 靜態證據在連線 `0x8060D0` 的有效 copy 路徑建立 pending record、`0x806060` 以 `Conn+A074` list 和 `Conn+A078` count 入列，並設 `Conn+A024` 有待送狀態；`0x8061A0` pump 讀出 record+8/payload、record+4/length，依 `Conn+A02C` 走 `0x807A70` plain `0x1A68`（4-byte header）或先試 `0x807830` framed transform（失敗可 fallback）。成功後從 pending list 移除 record。不同「記錄 queue」不能直接等同遊戲的攻擊連段/queue。

有獨立 native 前後路徑：`0x804AD6`、`0x805228` 都呼叫 `0x8061A0`，但屬不同 caller 管理路徑，**沒有任何證據可說兩個更新必定同幀**。在 `Conn+A028 !=0`、`Conn+A0B8<=0` 的指定分支，它們以全域 `FBA854` 的 vtable+0xC 虛呼叫，push `(Conn, Conn+0x5020, pendingLen, &localResult)`，`0x804B5A call edx` / `0x8052AC call edx`。若 +A0B8>0，該 pump 當次不提交新的 I/O，**不是網路封包已丟棄**。

**源碼整合必要修正**：T10-113 當時將 `FBA854` 虛表目標標為待證；T10-114 新增 constructor/vptr/store，解除其當時的局部未知。不可把時間上較舊的未知搜尋當成另一個矛盾結論。

## 4. 功能鏈 D：具體虛表、WSASend ABI 與四種返回值

**限定原生肯定結論（CLM-NET-0035）：** `0x8046D7 push 0x5C`、`0x8046D9 call 0x891268` 配置管理物件；在非空分支 `0x8046F2 call 0x803D60`、`0x8046F7 mov [esi],C51748h`，`0x80470F mov [FBA854],ecx`，是具體全域 transport owner 的一條安裝鏈。`.rdata C51748` 連續 11 個 DWORD 已從原始 BIN 重讀：`+0=806670`, `+4=806CF0`, `+8=806850`, `+C=8068B0`, `+10=8069A0`, `+14=806A00`, `+18=806AD0`, `+1C=806F60`, `+20=806F80`, `+24=806FC0`, `+28=807090`。因此指定構造路徑上的 pump `virtual+C` 可達 `0x8068B0`，但不證 runtime 無其他替換 vptr。

`0x8068B0` 先檢查 buffer 非空、len非零、`Conn+A0A8==0`，建立 `Conn+A050` OVERLAPPED；`Conn+A064` 的 WSABUF.len、`Conn+A068` 的 WSABUF.buf，並以 Conn 首 DWORD socket 呼叫 `0x806912 FF15 B825BD00`（WSASend）。本地回傳狀態：

| 本地狀態 | Native 路徑 | 本地返回值 | 與原版 Server 界線 |
|---|---|---|---|
| WSASend API 直接成功 | `80697A`，`InterlockedIncrement(Conn+A0B8)` | 1 | OS API 成功提交，不證 Server 接受 |
| SOCKET_ERROR 且 WSAGetLastError=997 (`0x3E5`) | `806961`，同樣增加計數 | 2 | 等待/非同步中，非遊戲 ACK |
| SOCKET_ERROR，其他 WinSock error | `806935..80695E` | 0 | Client 本地出錯，不是 Server gameplay 拒絕 |
| 參數或 Conn+A0A8 gate 提前失敗 | `806993` | -1 | **非零**，上層僅 `test eax,eax` 時不會進 EAX==0 的故障支線；並不代表成功傳送 |

這項 `-1` 回傳值是跨 Task 審核的高風險分歧。此前 T01/T02 的 CLM-NET-0005 已覆蓋一條 WSASend 有界路徑；本段專門添加**vptr 原生安裝證據、四分返回**與 Tx pending count，不重造「已經 wire 發出某次 Z/000A」之主張。

```asm
8046F7 mov dword ptr [esi],0C51748h
80470F mov dword ptr [0FBA854h],ecx
804B4A mov edx,[edx+0Ch]
804B5A call edx
8052AC call edx
806912 call dword ptr [0BD25B8h] ; WSASend
806968 call dword ptr [0BD2284h] ; InterlockedIncrement
806981 call dword ptr [0BD2284h] ; InterlockedIncrement
806993 ... mov eax,-1; ret 10h
806EC4 call dword ptr [0BD227Ch] ; InterlockedDecrement
```

## 5. 機器碼抽查、精確 bytes、可重算方式

本次 Python 直接讀取原始 KR BIN，對 19 個獨立 `.text` 視窗計算 SHA256、對 15 項 byte asserts 精確比較，`.rdata` 11 個 vtable DWORD 精確讀取、對 `FF15 IAT` bytes 執行限定 raw `.text` 尋找。所有當次檢查通過。詳同資料夾的 [`R2-audit.json`](20261030-162252-chatgpt-web-roy-T01-T10-108-114-R2-audit.json) 與 [`revalidate.py`](20261030-162252-chatgpt-web-roy-T01-T10-108-114-revalidate.py)。本地重跑用 `python revalidate.py Tartaros.bin R2-audit.json`。

已確認直接 IAT 型式的 raw 命中：WSASend/0xBD25B8 → `0x806912`；WSARecv/0xBD25BC → `0x806A4C`；GetQueuedCompletionStatus/0xBD2274 → `0x806D84`；CreateIoCompletionPort/0xBD2278 有多個命中，`0x806D57` 是此路徑的一個。**raw bytes 候選與所有指令/所有間接 API 呼叫不等價。** `objdump` 以有效函式入口重新解碼，沒有用落在立即值中的視窗首位置亂判 `call`。

具體 machine-code assert：`806E08 E8330D0000`（call 807B40）、`807DAD E8EEC2FFFF`（call 8040A0）、`806912 FF15B825BD00`（WSASend）、`806A4C FF15BC25BD00`（WSARecv）、`8046F7 C7064817C500`（vptr store）、`80470F 890D54A8FB00`（FBA854 store）、`806B33 898380A00000`（A080 writer）、`806E83 3BD7`（send completion compare；byte-assert 本批只取首 BYTE），其餘逐項見 JSON。完整 window bytes 可從原始 BIN 按 `raw=VA−400C00` 重現；SHA 相符只保證**定位**，不代表全部路徑均已語意認證。

## 6. 跨 Task 去重、來源判定與已知反例

- NET existing CLM-NET-0004/0006 已涵蓋原始 frame/parser/queue 的部分子範圍，NET-0005/0014/0015/0016/0017/0018 涵蓋部分 transport/IOCP/Conn lifetime；本輪 4 條 claim 只針對 **T10 原始視窗**、分類/零長 record、A030/A050 identity、queue writer、具體 FBA854 vptr provenance 和 WinSock 返回分級。與既有主張重疊處以 `related_claim_ids` 交叉引用，不因原稿重複而製造不同 wire 格式。
- T02 原稿與 RR-0005 被 S00 接受也不使 T10 本輪資料變成 FULL-PASS；T01 舊退回、T08 異型 actor/owner 的相同 offset 或 T10-055/056 錯位窗口不挪來做此處新肯定主張。
- API 成功/IOCP 完成 ≠ Server 接受普通攻擊；C2S app opcode 000A ≠ frame discriminator 1A68/0BBB/2633；conn+A080 queue category ≠ app S2C key0/13。`0x8076F0` zero-record 與 parser zero-length invalid 也不得混合。
- 風險：本次沒有完整的所有 WinSock early/failure CFG、所有 alias dataflow、每個 Conn subtype 的 vptr、字節流完整有效性、line-rate runtime trace、各 connection lane 的實際事件；記錄為 PARTIAL 而非全面驗證。

## 7. 玩家情境、Client／Server／跨功能／遊玩驗證矩陣

| 玩家／系統情境 | Client 靜態確認 | C→S 送出 | S→C 消費 | 動作／Server 分工 |
|---|---|---|---|---|
| 玩家站立短按 Z，工作 bank 含 Key44→ID13 | 前段 T10 有條件 phase→000A，本輪有通用 pending→WSASend | **不證明**該次 Z 必送 000A 或一定成功提交 | 此批 generic IOCP/queue 成立，但沒有配對這次 Z 的 Server 回覆 | 起手、combo、取消、Server 判斷仍未知 |
| 接收一個有效 frame，Conn 的類別與 gate 有效 | 806A00→IOCP→807B40→非零 record 依 A080 queue 分類 | 無上行新結論 | 在指定條件下可入 8040A0，再由既有 804740 消費 | app key/actor motion 另需 T10/T09、S00 Client contract 補證 |
| 解碼後產生零長 record | 走 804310→8076F0，跳過一般 append | 無上行新結論 | 不會由此路直接進一般 bucket | 不可當 Wire 零長 opcode 或攻擊拒絕 |
| Conn pending buffer 不空、A0B8<=0 | 兩個不同 pump 候選可嘗試 FBA854 virtual+C → WSASend | 可能回 1/2/0/-1，非零不一定已提交 | 不由本路證 ACK | Conn lifecycle、重試/清空、原版 Server 仍待證 |

**Client 待逆向：** 其他 Conn+0xA080 writer、`0x807B40` 所有 error/partial frame 消費、`0x8076F0` 特別 bucket drain、`0x8060D0` 超過4096 bytes 的 copy/queue語意、全型別動態 FBA854 vptr、WSASend error=-1 上層關閉/重試與真正 000A 到該 send 事件實例的聯繫。

**Server 待開發：** 僅能引用 Client 已證的 frame/application queue 接口候選，不能從 OS 提交成功推得官方 Server 對普攻、連段或防作弊的內部裁決。

**跨功能待整合：** T02 有 RR-0001/0004/0006/0007 的網路與協定權責，T10 提供 app 000A、S2C key13 / actor B0 的有限參照，T08/T09 再分別接 actor lifetime/motion。若 S00 需要確切 Server 契約，必須依各 GAP 與對應原始證據另審，不以本 batch 自動升 SPEC。

**待遊玩驗證：** 沒有執行遊戲、沒有現場 WSASend/WSARecv 封包、沒有原版 Server reply；此次亦未確認 Player Z 對應實際 WSASend 的一次輸出數量。

## 8. 本批完成界線

這次只完成七份 T10 原稿的主張級 canonical 入庫、四條限定新增 claim（CLM-NET-0032～0035）與本地19視窗+15byte R2 校驗。T10 精確來源總數維持：T10 此分支有127份；此前23份在這條整合流程已有主張連結，本批再7份，剩97份待各自 R1/R2 與必要全文驗證。全篇 FULL-PASS、NATIVE_VERIFIED、SPEC_CONSUMABLE、RR ACCEPTED、Server 已實作、遊玩可行，均沒有因本輪更新。
