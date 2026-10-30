# T01 第四批實質整合 — 51 份來源逐檔 hash、KR same-key erase rooted CFG、T16 Quest16 type2 消費者改判

**時間**：2026-10-30（Asia/Taipei）。**工作性質**：T01 來源準入 R0、有限原生驗證 R2、來源衝突處置與 S00 導航；不是 RR 研究者本身的正式提交，也不是 Git 分支 Merge。**本次沒有 Commit／Push 授權，僅提交本地完整交接檔**。

## 0. 版本、基線、證據門檻

- 第一手原始 **KR** `Tartaros.bin`：12,472,320 bytes；本地重新 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE `.text` VMA=`0x401000`、raw offset=`0x400`，故指令窗口 `.text raw=VA−0x400C00`。`.rdata/.data` 各自獨立換算；不能挪用 `.text` bias。
- 新對話開工 GitHub `main=dbaf50a1dc1ff119e942458f79700bd18e8c7004`；`research/intake/index.json` 399 筆 SRC，`research/claims/index.json` 92 項 CLM，前批新增 `SRC-0392～0399` 與 `CLM-NET-0014～0017` 皆已存在。T01 收件箱無待審 S00 提交；RR-0005 為 KR/T02 `CLAIMED`，`claim.branch=extra/roy1`，未 `SUBMITTED` 或 `ACCEPTED`。
- 其餘工作分支另有 `extra/roy1` E51/E52、`t16/roy/chatgpt-web` T16-114～117，均非目前主線新增來源，並行 Agent 繼續研究。本批依來源分支讀取及相應 Git blob SHA 引用，但不 Merge 工作分支、不修改他人原稿或 RR。
- **兩軸**：`REGISTERED/CLAIMS_EXTRACTED/CONFLICT_CHECKED` 是整合進度；`PARTIAL/REFUTED/NATIVE_VERIFIED` 是主張品質。某函式 rooted CFG 已確認其限定路徑，也不自動令其來源原稿整篇 FULL-PASS、RR 達標、Server 可用或遊戲可玩。

## 1. R0：先前剩餘 51 篇有了來源 SHA256，不用重算 Git Merge

本輪從 `main` 的 `extra/roy1`、T16 歷史 Merge manifest 及 `T01-source-intake-draft-20261030.json` 取得**精確來源路徑、原 Git blob SHA**。篩除已正式 `SRC-0392～0399` 的 8 篇，得到 **51 篇**：extra 33、T16 18；合計 **2,159,331 bytes**。

- 透過 GitHub `fetch_file(path, ref=main固定SHA)` 分批讀取，每篇回傳 Git blob SHA 均符合 Merge manifest；將回傳文字依 UTF-8 編碼後以獨立 JS SHA256 實算，登錄每篇 `source_sha256` 與 bytes。**沒有混用 `Tartaros.bin` 的 SHA256、Git SHA1 與 Markdown 自身 SHA256。**
- 逐份結果和 Git SHA1 對照放於 [source-intake-51-proposal.json](source-intake-51-proposal.json)，依既有 SRC 最大 0399 形成**暫定編號 `SRC-0400～0450`**，全為 `integration_status=REGISTERED`、`claim_ids=[]`、`original_document_review_status=PENDING`。目前未由正式 T01/S00 對這 51 篇完成 bounded extraction/conflict adjudication。
- 用 [apply_source_proposal.py](apply_source_proposal.py) 在本地把這份增量加入從 GitHub 另下載的權威 `research/intake/index.json`；**腳本拒絕 SRC 最大 ID 不等於 0399 或來源路徑已存在**，以避免競爭修改；不自行更新遠端。與正式上 Git 相應的 Commit 授權仍須當次提出。
- **新分支 E51/E52、T16-114～117 尚未合入 `main`**，因此不包含在上述 51+8 篇的舊 main 對照，不以新分支筆記假充已在主線 R0 登錄。

### 收件的三個層級不可混用

| 作業 | 本輪實際完成 | 未宣稱 |
| --- | --- | --- |
| 文件來源身分 | 51/51 Git manifest path、回讀 blob SHA、UTF-8 原文 SHA256、byte-size | 作者每篇內容正確、全部內部引用可靠 |
| 內容 R1 | 本批集中 7B6890 及 Quest UI，其他 51 篇仍待 bounded claim 萃取 | 51 篇 CONFLICT_CHECKED |
| 原生 R2/R3 | 局部函式 rooted CFG、指定 type gate 直接 native 驗證 | 整篇 FULL-PASS、Server SPEC STABLE、封包已真實收發 |

## 2. R2：Manager 同 key node erase 函式的可達控制流全面核對

### 2.1 研究問題與原作者歧義

前一批 `CLM-NET-0016` 只能聲稱：`0x806C9E` key tree lookup 命中時 `0x806CB3` 呼叫 `0x7B6890`，接著 `0x806CC7→0x57EF20` 建 node、`0x806CD2→0x57E850` insert，**尚未讀完 erase helper 所有分支，不能說會／不會析構 Conn value**。本批要確定 `0x7B6890` 是否 dereference 原節點 `node+0x10` 的 `Conn*` 值、經哪個 allocator 釋放、是否隱含 socket close／Pool+48 enqueue。

E51 已同樣指出 erase helper 釋放 tree node 而非直接以 Conn value 呼叫 `0x806FC0`；本批是**T01 使用獨立原始 BIN 重跑完整 rooted CFG 與其直接 callee**，不是轉述 E51 作者結論後自封 FULL-PASS。E52 新報告另指出 `0x8063E0` 清的是 Conn 發送佇列而非直接關閉 socket，與本段 ownership 區分相容；此處未全面重驗 E52 的該完整函式。

### 2.2 rooted CFG、指令與所有直接 CALL

- `0x7B6890..0x7B6AEE`（結尾 `0x7B6AEB ret 0xC`、後有 int3）；程式 `objdump` 按原始 `.text` 入口分段解碼，逐條以原始 BIN raw bytes 反查。
- 由入口做 DFS reachable graph，conditional branch 走 taken/fallthrough，unconditional branch 只走 target，CALL 保留返回後續並建立 callee 關聯，RET 為 terminal；**223/223 decode 指令可達、45 條 direct control branch、10 處 direct CALL、0 條 unresolved indirect jump/call，所有 branch target 為指令起點**。這只證此函式，不證整個 Manager／Conn lifetime 的所有入口。
- 10 處 call：`0x7B68A4→0x87DB7D`（sentinel 檢查非正常錯誤路徑，異常語意未深審）；`0x7B68B4→0x49E6A0`（successor）；`0x7B6949→0x823B80`（extremum）；`0x7B69F2/0x7B6A41/0x7B6AA0→0x763F60`（樹旋轉）；`0x7B6A24/0x7B6A58/0x7B6ABB→0x43E670`（反向旋轉）；`0x7B6AC7→0x89120C`（刪除 node）。
- 同時確認 `0x763F60`（33 指令、3 分支）、`0x43E670`（33、3）、`0x49E6A0`（28、7）、`0x823B80`（9、2）皆只有樹 parent/child/sentinel 相關欄位，沒有本類節點 `value+0x10` 的 Conn 為目標做 virtual invoke 或 close。原文完整視窗在 [native-disassembly.md](native-disassembly.md)；檢查機器腳本在 [verify_r2_batch4.py](verify_r2_batch4.py)。

### 2.3 從舊 node 釋放到 Windows HeapFree 的 native 因果鏈

```asm
; 0x806AD0 same-key path：先 erase 舊 key->Conn node，後 insert 新 node
806c9e: e8 1d cc 03 00       call 0x8438c0
806ca7: 3b 47 1c             cmp eax,[edi+0x1C] ; end/sentinel
806caa: 74 0c                je 0x806cb8
806cb3: e8 d8 fb fa ff       call 0x7B6890
806cc3: 89 5c 24 18          mov [esp+0x18],ebx ; new Conn*
806cc7: e8 54 82 d7 ff       call 0x57EF20
806cd2: e8 79 7b d7 ff       call 0x57E850

; 0x7B6890 tail，所有正常分支匯合
7b6ac3: 8b 55 fc             mov edx,[ebp-4]
7b6ac6: 52                   push edx
7b6ac7: e8 40 a7 0d 00       call 0x89120C
7b6acf: 8b 41 08             mov eax,[ecx+8] ; tree count
7b6adc: 48                   dec eax
7b6add: 89 41 08             mov [ecx+8],eax
7b6ae6: 89 08                mov [eax],ecx     ; output iterator
7b6aeb: c2 0c 00             ret 0xC

; allocator deallocation link
89120c: 8b ff                mov edi,edi
89120e: 55                   push ebp
89120f: 8b ec                mov ebp,esp
891211: 5d                   pop ebp
891212: e9 e5 0e 00 00       jmp 0x8920FC

892101: 83 7d 08 00          cmp dword [ebp+8],0
892107: ff 75 08             push [ebp+8] ; old node pointer
89210a: 6a 00                push 0
89210c: ff 35 dc d4 f8 00    push [0xF8D4DC] ; process heap handle
892112: ff 15 10 22 bd 00    call [0xBD2210] ; PE import HeapFree
```

`objdump -p` 原件 import 明確列 `IAT RVA 0x7D2210=HeapFree`，image base `0x400000`，故 IAT VA `0xBD2210`。上述 calling convention 由 push 次序和 `ret 0xC` 判斷；不是編造原始 C++ source。

**證據分級：Native R2 bounded**：對 `0x7B6890` 的 root 內沒有以樹節點 `+0x10` 取得 value Conn*，其可達直接 callees 不以 value 做 Close/Conn destructor；正常清理由舊 node 指標→HeapFree、count--、out iterator 完成。這實質收窄 `CLM-NET-0016` 的 `0x7B6890 value destruction unknown`，但還沒裁定同一 key replacement 的更上游 `0x806AD0` 各種失敗／例外時序、其他並行清理及 IOCP 舊指標所有權。**不等於在真實重連執行期必然發生 Conn leak／UAF 或 Server 沒有其他連線管理。**

## 3. R2：與 E51/E52 舊 Conn、Pool、IOCP 的功能鏈對照

| 節點／責任 | 有界 BIN / source evidence | 語意與所有權界線 |
| --- | --- | --- |
| Pool get `0x805950` | 前批 R2：重用 old block/reset 或配置 `0xA0D8` 新 Conn | 物件位址可重用，不表示 generation 無風險 |
| `0x806AD0` connect | `0x806C87` 以新 Conn* 作 IOCP key；成功回值未在下段明顯 gate | 無法由後續插入樹 node 反證 IOCP 關聯失敗 |
| Manager tree erase | **本批 223 指令 CFG**，`0x7B6890→HeapFree` old tree node | 此鏈不以 tree value Conn* 做 close；不是 whole-object release |
| new map | `0x57EF20/0x57E850` key/new Conn* insert | 不能將新 Conn 視為舊 Conn 的同一世代 |
| Close by Conn `0x806FC0` | E48～E52 共通 T02 client 路徑 | 另有 Pool+28 tracking；不和 tree erase 混同 |
| Pool+48 producer | E50/Batch2：Connect failure、manager teardown | 必須確定**舊** Conn 是否真的被任一路 producer 接納；本次不保證 |
| GQCS consumer | 前批 `0x806D84` 讀 completion key、`0x806D92` 採 Conn* | key-map overwrite 不能自動移除舊 IOCP completion |
| RX/TX | A030/A050 OVERLAPPED、A0BC vs A0B8 需分別辨識 | native sync/pending/error/cancel 與 pool reset gate 仍有並發缺口 |

**下一個最小 Client 靜態研究終點**：不是重新找出 tree erase，而是從 `Conn+0x14` 全 writers、`0x806FC0` 與 `0x805AF0` 的同步/錯誤輸入、`0x8066A0` teardown 及 `0x805B40` reset gate 回溯到底是否有「同 key old Conn」被提交清理的必經條件。再區分當場可達性的原生靜態證據與只可能透過合法 runtime session 驗證的 I/O 競態。

## 4. T16 跨 Task 新原稿：Quest16 type2 UI 反證／候選消費者

T16 工作分支目前有 `T16-114～117`，不在目前 `main`。本批定向比較 **T16-116 的 0x74→QuestOwner key14→candidate 重建**與 **T16-117 對 type2 UI 的更正**。相關 Git blob SHA：

- T16-116：`a79ee0add91970494a63f4a393694ee1cd5ee15b`，路徑 `kr-temp-roy/20261030-032743-chatgpt-web-roy-T16-116-KR-Quest14-study4-S2C-0x74-quest-owner-demand-UI-end-to-end.md`。
- T16-117：`388b9100362ed43ec65ba1f7504f73518dce5d44`，路徑 `kr-temp-roy/20261030-034517-chatgpt-web-roy-T16-117-KR-Quest14-study5-Quest16-type2-unlock-UI-C2S-S2C.md`。
- 靜態資源「QuestInfo Quest16 type=2、Demand14」是來自 T16-117 所引用的 QuestInfo.xml 版本及 T16-112 的相關來源；**本批沒有直接從獨立完整 Table.stp 重驗 XML 全文**，所以下列 native 判讀把 type2 作明示前提，不偷換為本次完全獨立 XML 重驗。

### 4.1 原始 BIN 的型別分流反證

```asm
; 共通 input 是 QuestOwner+5EC0..5EC4 的 WORD IDs，lookup QuestRecord
5009d3: 39 50 28            cmp [eax+0x28],edx    ; current selector
5009d8: 83 78 04 01         cmp dword [eax+4],1 ; type1 only
5009dc: 75 0e               jne 0x5009ec         ; other types skipped
5009e4: e8 27 33 f4 ff      call 0x443D10       ; type1 output vector

500a53: 39 50 28            cmp [eax+0x28],edx
500a58: 83 78 04 02         cmp dword [eax+4],2 ; type2 only
500a5c: 75 0e               jne 0x500a6c
500a64: e8 a7 32 f4 ff      call 0x443D10       ; type2 output vector

5008f3: e8 08 01 00 00      call 0x500A00       ; native type2 reader
5008f8: 8b 44 24 0c         mov eax,[esp+0xC]
5008fc: 3b 44 24 10         cmp eax,[esp+0x10]  ; empty check
500922: 8b 08               mov ecx,[eax]
500924: 0f b7 31            movzx esi,word [ecx]
500930: 66 8b c6            mov ax,si            ; first qualifying type2 ID

5b9407: e8 a4 74 f4 ff      call 0x5008B0       ; actual Client caller
```

原件 `0x500950` 有 **type==1**，`0x500A00` 有 **type==2**，兩者 **不是無條件等價的 Quest UI reader**。`0x5008B0` 只在 type2 列表非空時返回第一個 WORD key；不能由這個 consumer 的存在推導 Quest16 一定在 NPC10027 UI 顯示、玩家一定按下 Quest16、或 S→C `0x74` 到來立即重繪。

### 4.2 T16 版本歸併與跨方向 ID 不可混名

**R2 可用邊界**：T16-116 的 Client S2C index `0x74` 到 `0x503400` 的候選 `key14` 追加路徑，及 `0x500240` rebuild 的 call，已有可追溯 native call chain（本批單獨讀 `0x503400`：`0x503413→0x44B4E0`、`0x503425→0x500240`）。但 **本批未獨立把 `0x74` 之頂層 dispatch 和 payload 最小長度完整做 R3 審核**；`0x74 00 0E 00` 作 Client 有界 handler payload 候選，不是必然 Quest14 完成成功回包。

T16-117 已明示修正：不能因 T16-116 `0x500950/0x500E00 → 0x635CA0` 是 UI reader 就聲稱其會顯示 **type2 Quest16**。**只將 type1 UI 的推論撤回／限定**，不撤銷 `0x74→key14→Demand14` 在其前提成立時的 source-derived 資料鏈。T16-117 指明額外 `0x500A80` mode gates／`0x5B9407` caller，本批直接核對後者 native CALL，但 UI 實際綁定 NPC selector、socket wire及玩家事件仍未閉合。

**Client 待逆向**：Quest16 真正可選／可交付的 UI 決策、S2C `0x74/0x40` 正確長度、Quest16 `0x36 00 10 00` C2S 之回應配對、Quest14 何時由 Server 發 key14。**Server 待開發**：處理先決與角色進度保存，不需猜成官方 Server 原本內部演算法。**跨功能待整合**：T02/T03/T16 的本地 frame/queue/選角/任務進度鏈。**待遊玩驗證**：同一合法 session wire、選 Quest16 時候/UI 刷新。

## 5. 對正式 T01 索引的增量準備（未提交）

- **來源收件**：`source-intake-51-proposal.json` 內 51 筆以 `SRC-0400..0450` **暫定**，source SHA256 + Git blob identity 完成。正式 main 仍只有 399 筆 SRC；對 `research/intake/index.json` 的寫入需使用者本次明確 Commit/Push 授權、檢查最新 main 競爭及去重。
- **主張品質**：建議為 `CLM-NET-0016` 建立限定 `R2` addendum：`0x7B6890` rooted graph 223指令/45分支、只釋放 tree node，**不由此推出 old Conn 無其他 owner**。不得覆寫原作者 E48/E49/E50 原文，也不刪 E51 已經得到的近似結論。
- **T16 反證**：T16-116 type1 UI to Quest16 type2 屬作者 T16-117 已自我限定更正。因兩份在當次 `main` 尚未入庫，先保留版本關聯於此 handoff；待納正式來源索引時再決定是否須建立 T01 固定更正通知或只做 `REFUTED historical assertion` 的 canonical link，避免重複派單。
- **FULL-PASS**：無新增。局部 rooted graph / 11個函式窗口 byte verification 不等於 E51/E52/T16-116～117 全部主張都已獨立逐項審核。
- **RR**：RR-0005 為 T02 `CLAIMED`；T01 無權替研究者 `SUBMITTED` 或替 S00 `ACCEPTED`；其他 Task README、owner、SPEC/GAP/TEST 均未更動。

## 6. 真實證據限制與下一輪入口

1. **靜態可進一步查的缺口**：Manager 的其他 same-key helper 呼叫者、`0x806FC0` 與 `0x805AF0` 完整 dispatch/owner、Conn+0x14 全 writers、`0x805B40` cross-thread guard、`0x500A80` 所有 type2 consumer 的 UI 串接。
2. **原始 Client 不能自動證明的事情**：真正 Server 何時發 Quest14 key、所有 IOCP completion 的執行時序、Server 內部狀態、實際遊玩。必須另開合法 trace / Server integration TEST，不把抽樣碼證明等同 runtime。
3. **需要帶給 S00 的可用資料**：強制區分 (a) active manager map 的 key replace、(b) Conn pool 物件生命週期、(c) IOCP completion-key 持有、(d) QuestOwner 狀態 key、(e) `QuestRecord.type`、(f) local TalkBox event/cmd；不得把同一 `0x14`、`0x36`、`0x40` 或相同 socket key 混用不同型別／方向語意。
4. **批次停止原因**：本次完成「51份 R0 精確 SHA 準入草案」和「精確 rooted 7B6890 所有正常分支 + type1/type2 gate」兩個限定整合交付；**完整 RR-0005、Quest16 UI 與全文 R3 仍階段性未完成**。不因出現重大發現而聲稱其原始研究目標全部完成。下輪續作 writer/refcount/alias 與 type2 caller closure。

### 檔案與重現方式

- [verify_r2_batch4.py](verify_r2_batch4.py)：唯讀本地 PE bytes / GNU objdump 解析、入口 CFG 與精確指令比對，核對 11 個函式入口／原始 VA 視窗及 type1/type2 比較；不執行任何遊戲原件程式碼。`python verify_r2_batch4.py /path/to/Tartaros.bin --output native.json`。
- [native-r2-batch4.json](native-r2-batch4.json)：完整 direct CALL/branch、原始 window hash、可達指令數、限制。
- [native-disassembly.md](native-disassembly.md)：12 組原生組語與 raw bytes 明文，含 `0x806AD0` caller 片段、node free、HeapFree 與 Quest type readers。
- [source-intake-51-proposal.json](source-intake-51-proposal.json)：51 筆 `source_file/source_blob_sha/source_sha256/source_bytes` 與暫定 SRC，**未上傳**。
- [apply_source_proposal.py](apply_source_proposal.py)：未授權時只用於產生本地修訂版 JSON，無 GitHub 寫入。