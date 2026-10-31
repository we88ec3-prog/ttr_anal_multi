# T01 — extra/roy2 RR-0004／RR-0005 補充分析整合與獨立原生審核

審核日期：2026-11-01（Asia/Taipei）。**整合任務：T01**，來源分支 `extra/roy2`。本報告嚴格區分作者補證、T01 本輪獨立原生測量、範圍限定與尚未取得的反面證明。

## 0. Git 來源、歷史與正式狀態

- GitHub repository `we88ec3-prog/ttr_anal_multi`，合併前 `main` **`b1fa730c99dbe2ff29f0ffed8b7a0448d6f4c460`**，本次來源 `extra/roy2` HEAD **`fe1112c77840b1627084df20f29f6f05dc64a2eb`**。分支 compare `ahead=2, behind=0`，相同 merge-base 為 `b1fa730c99dbe2ff29f0ffed8b7a0448d6f4c460`。
- 來源新增四檔（RR-0004 兩份、RR-0005 兩份），**無同路徑覆寫或 README/task.json/catalog 衝突**：
  - 原始分析 `kr-extra-roy/20261101-014300-chatgpt-web-roy-RR0004-KR-A02C-alias-native-audit-supplement.md`，Git blob **`cf9cfeb9e2f09fa1a4e02fec774642be5e679713`**、UTF-8 SHA256 **`88f92f07b277caa6dd26708980adf2e1489525d1e06ff79d1df33ebbea2bee1c`**。
  - 作者可重跑檢查程式 `kr-extra-roy/tools/rr4_native_audit.py`，Git blob **`216d39628c6c86a752e6f52bee5b58cd98c9be04`**、UTF-8 SHA256 **`3286bbdb4c6d7766b89c5bf84d48c5b5eb518d714233f130eabbd097d973f70f`**。
- 四份原始檔以完整 Git 歷史保留，使用 `main` 第一父、`extra/roy2` 第二父的**真實非強制雙親 Merge Commit**。不新開 branch、不重寫原文。登錄 `SRC-0626～SRC-0629`，保持 `REGISTERED`、`claim_ids=[]`；此項登錄本身不等於主張全文語意驗收。
- 先前正式 `RR-0004` 是 **`IN_REVIEW`**，主責 T02；`SRC-0462` 的舊 E58 仍保持原 blob `b5c53b93ec20e056fb3f07374468a341ce4ee9c9`，既有 `CLM-NET-0021/0023/0025` 的 `PARTIAL` 不變。RR-0004 僅補充 T01 R2 定向複驗；RR-0005 的 S00 有界 ACCEPTED 與 T01 原生 FULL-PASS 是獨立狀態，**不擅自改 RR 為 ACCEPTED、不新增原生 FULL-PASS，也不擅稱 SPEC STABLE**。

## 1. 原件身份與真的執行的 T01 方法

本次 T01 **親自唯讀讀取**本次工作區的四份原始檔並計算 SHA256；不執行、修改或連線遊戲，也未依作者的「PASS」文字直接認證。

| File | Size（如已驗） | 本輪 SHA256 |
| --- | ---: | --- |
| `Tartaros.bin` | 12,472,320 bytes | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `Tartaros.exe` | — | `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` |
| `Event.stp` | — | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| `Table.stp` | — | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |

獨立解析 PE `MZ`、PE Signature、x86 machine `0x14C`、imagebase `0x400000` 及 section table：`.text` VA0x401000/raw0x400/VirtualSize0x7D01F0/RawSize0x7D0200，`.rdata` VA0xBD2000/raw0x7D0600。僅在原生 `.text` 的 `raw=VA−0x400C00` 驗證機器碼。使用 Python `hashlib`/`struct` **重新自寫**獨立掃描／檢查，並用 `objdump -d -M intel` **從正確 root function entry** 分段連續反組譯 `0x805CA0`、`0x805F50`、`0x8061A0`、`0x807830`、`0x807A70`、`0x7438C0` 與 `0x7D1910` 所在區間；避免從立即數中間起始而產生假指令。

實際獨立測量結果（同目錄 `native-audit.json` 存機讀收據）：

| 查核 | 實際結果 | 涵蓋／局限 |
| --- | --- | --- |
| 完整 BIN hash + PE mapping | **PASS** | 只適用上述 KR SHA |
| 四組 DWORD displacement literal **全 .text raw** 搜尋 | **4/4 集合精確吻合**；總 11 個 immediate sites | 精確原生 bytes 之直接 32-bit 常數，**非全 points-to/alias** |
| 16 處指定 native instruction prefix | **16/16 PASS** | 並依有效入口反組譯相鄰分支 |
| 三個 direct E8 rel32 | **3/3 PASS** | `8059E9→805F50`，`806223→807830`，`80623A→807A70` |
| 12 個純數學邊界向量 | **12/12 PASS** | `mode/n/used` 合成條件；**並非 Client runtime packets** |

## 2. Alias 純值搜尋與現場型別審核

| searched little-endian DWORD | 所有 .text 命中之 immediate 所在 VA | root-aligned 原生解釋／T01 判決 |
| --- | --- | --- |
| `0xA02C` | `805D04`, `806205` | `805D02 C6 86 2C A0 00 00 02` 是 **唯一此種 direct displacement writer**：`BYTE[Conn+A02C]=2`。另一 `806202 0F BE 86 2C A0 00 00` 是 signed BYTE reader，不是 writer |
| `0x5010` | `7438C4` | `7438C3 B8 10 50 00 00` 為 `mov eax,5010h` 的**立即數**；不能冒稱 `Tx=Conn+501C` 的 +5010 位置有 setter |
| `0xA014` | `7D1913` | `7D1910 8B 8C B7 14 A0 00 00`：`mov ecx,[edi+esi*4+A014]`，屬 indexed reader；本區 `7D1906/1922` 使用 `+C014` 上下界，**EDI 是否 Conn+18 未證** |
| `0x500C` | `8077C0,8077CC,80789C,807A21,807AAD,807AFC` | `Tx=Conn+501C` 的 `Tx+500C=Conn+A028`，為輸出 used/count，不是 A02C；不能因同一 0x500x 家族推測 mode writer |

**指標換算**：在已證根入口 `Conn*` this（`ESI`）前提下：`Conn+A02C`、`Tx=Conn+501C` ⇒ `Tx+5010`，`Rx=Conn+18` ⇒ `Rx+A014`。此換算只用於**有 provenance 的物件基址**，不把不同 this、指標別名或同名 offset 認作同一物件。

**明確沒有證明的負主張**：絕對沒有其它 writer；因為直接 literal 掃描不能排除使用 `lea` 或加減基址、其他位移寬度、間接指標逃逸／回呼、memcpy、非 .text 來源與 runtime memory corruption。對任何新的 alias 候選仍應回到有入口的指標來源與指令 CFG 驗證，不能直接升格「全域模式永不變」。

## 3. 原生 ABI/CFG：constructor、reuse、queue drain、encoder

獨立 `objdump` 從 `0x805CA0` 起，`805CC8 mov esi,[ebp+8]`（Conn pointer），`805D02` 設 +A02C=2；同函式初始化 +A020/+A024/+A028。reuse helper `805F50` 透過 `8059E9 E8 62 05 00 00` 有效 direct E8 可達；其 `805F79` 重設 +A024、`805F7F` 重設 +A028、`805F8B` 重建 +A020，而**在所核 root helper 中未直接寫** A02C，不能推出所有 caller 的 mode 不可能變。

`0x8061A0` 以 `ESI=Conn*`：取得 `Conn+A074` queue head、`[node+8]` payload、`[payload+4]` 的 n、`[payload+8]` source，`806202` 以 **signed byte** 讀 mode `[Conn+A02C]`，而 `80620C` 建立 `Tx=Conn+501C`。以下為第一手指令摘錄（全指令均實際比對，沒有把截斷行當成獨立指令）：

```asm
805CF6  8D 86 20 50 00 00    lea eax, [esi+5020]
805D02  C6 86 2C A0 00 00 02 mov BYTE PTR [esi+A02C], 2
805D09  89 86 20 A0 00 00    mov DWORD PTR [esi+A020], eax
805D15  89 9E 28 A0 00 00    mov DWORD PTR [esi+A028], ebx
805F79  88 9E 24 A0 00 00    mov BYTE PTR [esi+A024], bl
805F7F  89 9E 28 A0 00 00    mov DWORD PTR [esi+A028], ebx
805F8B  89 86 20 A0 00 00    mov DWORD PTR [esi+A020], eax
806202  0F BE 86 2C A0 00 00 movsx eax, BYTE PTR [esi+A02C]
806218  74 15                je 80622F            ; mode == 0
80621A  48                   dec eax
80621B  74 01                je 80621E
80621D  48                   dec eax
806223  E8 08 16 00 00       call 807830         ; 0BBB
806228  85 C0                test eax,eax
80622A  75 23                jne 80624F           ; encoder success
80623A  E8 31 18 00 00       call 807A70         ; 1A68
806246  0F 84 58 01 00 00    je 8063A4           ; both fail
80624F  8B 0B                mov ecx, [ebx]       ; successful unlink begins
806275  FF 8E 78 A0 00 00    dec DWORD PTR [esi+A078]
8063A4  83 BE B4 A0 00 00 01 cmp DWORD PTR [esi+A0B4], 1
807887  3D 00 10 00 00       cmp eax, 0x1000     ; encoded n+6
8078A2  81 FA 00 40 00 00    cmp edx, 0x4000     ; TX used+n+6
807A97  81 FB 00 10 00 00    cmp ebx, 0x1000     ; plain n+4
807AB3  81 F9 00 40 00 00    cmp ecx, 0x4000     ; TX used+n+4
7438C3  B8 10 50 00 00       mov eax, 0x5010      ; IMMEDIATE
7D1910  8B 8C B7 14 A0 00 00 mov ecx, [edi+esi*4+A014] ; indexed READ
```

**完整限定路徑**：

1. `mode==0` 在 `806218 je 80622F` **直接**進 `807A70`（4-byte `1A68` header encoder）。
2. `mode!=0` 進 `806223 call 807830`（6-byte `0BBB` encoder）；若 `test eax,eax` 成功走 `80624F`，失敗才沿 `80623A call 807A70` 嘗試 plaintext。中間的 `dec eax` 並沒有分派到另一個 callee；mode1 與 mode2 於此段使用同一 encoded-then-fallback 路徑。
3. `806246 je 8063A4` 為兩個 encoder 失敗/無成功時跳**過** `80624F..` 成功 unlink 與 `806275` 的 `Conn+A078--`；`8063A4` 另用 `[Conn+A0B4]==1` 及 local flag 控制 return。**return != 0 不等於本次成功寫 socket**。
4. `807887` 比較 `n+6 <=0x1000`；`8078A2` 比較 `used+n+6 <=0x4000`；`807A97` 比較 `n+4 <=0x1000`；`807AB3` 比較 `used+n+4<=0x4000`。上述僅是比較/分支的正常數值模型，真正 encoder 亦具 pointer/range guards，當 used 或 cursor 非法不能以數學通過推 runtime 執行必成功。

## 4. 可重現 12 個 synthetic guards（不是實機封包）

在 mode2、used0 的正常數值前提下，n=4090 仍可 `0BBB`，n=4091/4092 可以退到 `1A68`，n>=4093 兩種 encoder 的單 frame 上限皆不成立。mode0 不走 `0BBB`；在 n1／mode2 且 used 為 16377、16378、16379、16380 時依次為 `0BBB`、`1A68`、`1A68`、`NONE`。完整機讀 12 項列於 `native-audit.json`，以及作者 `kr-extra-roy/tools/rr4_native_audit.py` 的 source。

- **這些是 branch/capacity 算式的可達條件模型**，不是 game producer 真曾發送 4091、4092 bytes，亦無 Client/Server wire capture 或 OS successful send。
- `0BBB` 轉換、`1A68` fallback 的靜態碼能證分支存在，不等於 mode0 在正常玩家登入/遊戲流程曾被配置。
- 跨 Task 相關已有 `SRC-0462`／`CLM-NET-0021/0023/0025`，本次來源作**獨立補強/反假陽性**，不再新造同義 CLM，不以一個報告覆蓋其他來源。

## 5. 正式 T01 驗收裁決與交接

| 軸 | 結論 |
| --- | --- |
| **R0 來源/身份** | 四份來源原始 Git blob 完整歸併，加入 `SRC-0626～0629`，核實 BIN 精確 SHA。 |
| **R2 有界原生語義** | 對直接 literal 集合、root-aligned writer/reader/立即數假陽性、A02C=2 ctor、已見 reuse 範圍、`8061A0` 非零模式兩 encoder 的 signed mode 分支、三個 E8、失敗跳過 success unlink、容量 compare，給**受前提限制的肯定支持**。 |
| **R3 原生 FULL-PASS** | **未完成**。本次未取得全部 Conn alias 寫入者全集、跨型別／跨執行緒影響與原版 runtime；也沒有對原 E58 及此份補證的全部肯定主張做全局 CFG/資料流逐項完審。原作者聲稱通過的腳本亦不替代 T01 審核。 |
| **RR / S00** | RR-0004 **仍 IN_REVIEW**，T02 主責；GAP-NET-0001 及 S00 必須自行審核是否足夠規劃。本次沒有宣稱 ACCEPTED 或 SPEC STABLE。 |
| **Client 待逆向** | 全域 mode writer/alias proof、任意 callback/memcpy、mode0 在正常 runtime 何時可達、真 socket framing 與 first-message sequencing（另參 RR-0001）。 |
| **Server 待開發** | 相容 Server 需處理已證 marker/length 的收發契約，不能反推原版 Server 只允許一種 marker 或做出原版政策肯定句。 |
| **跨功能** | T02 連線模式與 T01 既存網路主張；S00 依現行 REQ/SPEC/GAP/TEST 去重。 |
| **待遊玩驗證** | 真實 Client mode/bytes/cursor、n=4091/4092 fallback 實際發生、OS 送達、對端回包與初始化交換順序。 |

**結論：**完成 Git 分支來源整合與本輪獨立 BIN-first **限定 R2 審核**；所有原稿仍受其明確證據邊界限制，**不把「沒有找到直接 literal writer」寫成「不存在間接 writer」**。核對實際 merge commit、來源 SHA 與 CI 後方可對外宣告上傳成功。

## 6. 同步納入的 RR-0005 原生增量補證（Branch 第二個提交）

本次來源 `extra/roy2` 後續新增：
- **`kr-extra-roy/20261101-014912-chatgpt-web-roy-RR0005-KR-hidden-ESI-Connect-slot-local-send-bounded.md`**；精確 Git blob `a8047fb1497aa05e29f71efa14cde12d9b26e1a5`，UTF-8 SHA256 `df479930ef1753279f984de7f10423ec566b69f3a4400eecf9737767a8d592b4`；登錄 `SRC-0628`。
- **`kr-extra-roy/tools/rr5_esi_connect_native_audit.py`**；精確 Git blob `a21858c9b0e31385a2394e9efac257d57591916a`，UTF-8 SHA256 `0e8b0c3de568e6aa01c77a03f39ec7d357f8ff66981a93a021efbff3cc5be8a8`；登錄 `SRC-0629`。

**現行正式狀態對照**：`RR-0005` 在 `research/requests/index.json` 為 `RESOLVED`，其 dispatch 為 **`ACCEPTED`**（僅限 S00 已核可的 KR Client 靜態研究）。本份增量研究**不需重新認領、不更改 RR 事件紀錄**，原 `E56` Git blob `843889349bb58209c02221e720800f0e9e3ff9d8` 保持不動。此項既有 ACCEPTED **不是**本份新文稿 T01 FULL-PASS、Server 可玩或 `GAP-NET-0002` 已解除。

### 6.1 真的由本輪 BIN-first 驗出的 Native ABI、dataflow

T01 在相同原始 BIN 上**獨立實測 32/32 native machine-code prefixes**，並掃出完整 .text raw `E8 rel32` 之三組直接呼叫*bytes 候選*集合，共 **10 處完全與作者腳本吻合**：
- `4957C0` 的兩處 direct E8：**`66C1A7`、`66C247`**。
- `495610` 的六處 direct E8：`6D6377,6D6424,6D6508,6D65C8,6D670C,6D696C`。
- `8060D0` 的兩處 direct E8：`495853,8069EB`。

所有 E8 candidate 均以 **VA+5 + signed rel32** 計算；只有已用原生 caller entry `48AB70`、`4957C0`、相關 UI caller 前後段核對的站點提升為有界 caller-to-callee；**不可把 raw opcode 掃描自動當整個 Client 的完整 CFG**，也不能排除 indirect calls。

```asm
48AB98  8B 7D 08                  mov edi,[ebp+8]             ; Client*
48ABA1  89 3D 18 13 FB 00         mov [0xFB1318],edi        ; global Client pointer
66C1A0  56                        push esi                  ; original host
66C1A1  8B 35 18 13 FB 00         mov esi,[0xFB1318]       ; NEW ESI=Client*
66C1A7  E8 14 96 E2 FF            call 0x4957C0
66C240  56                        push esi
66C241  8B 35 18 13 FB 00         mov esi,[0xFB1318]
66C247  E8 74 95 E2 FF            call 0x4957C0
4957E0  6A 02                     push 2
4957E2  6A 00                     push 0                   ; key0
4957E4  68 E0 20 00 00            push 0x20E0              ; 8416, legacy
4957F2  6A 02 6A 02               push 2; push 2          ; key2 lane2
4957FD  68 DE 20 00 00            push 0x20DE              ; 8414, legacy
495807  85 FF                     test edi,edi             ; key0 Conn gate
49580F  85 DB                     test ebx,ebx             ; key2 Conn gate
495817  83 BE 60 BF 00 00 00      cmp dword[esi+BF60],0   ; old key1
495853  E8 78 08 37 00            call 0x8060D0            ; old key1 local enqueue
49585E  C7 80 B0 A0 00 00 01 00 00 00  mov dword[eax+A0B0],1
495868  C7 86 60 BF 00 00 00 00 00 00  mov dword[esi+BF60],0
49593D  FF D2                     call edx                  ; vtable+10, 57B local
49594B  FF D2                     call edx                  ; vtable+14, key0 recv
495959  FF D2                     call edx                  ; vtable+14, key2 recv
49595B  89 BE 64 BF 00 00         mov dword[esi+BF64],edi
495962  89 9E 68 BF 00 00         mov dword[esi+BF68],ebx
495968  B8 01 00 00 00            mov eax,1
```

從 `0x48AB70` 的 Client ctor 確認 `48ABA1` 直接將 `Client*` 寫入 global `FB1318`；兩個已證 UI callers 分開保留原本 `ESI` host 作堆疊參數，再把 **global Client*** 載入新的 ESI，才 `call 4957C0`。`4957C0` 在成功的兩個 Conn 非 NULL 分支會透過 `ESI+BF60/64/68` 使用/更新 Client 狀態，因此**不是只有 host 字串的一個普通堆疊 API**。這些是限定兩個已追過的 UI caller，不擴張到所有未知間接 caller。

**後置成功與回傳值界線**：`49593D` 對 key0 的 57 bytes 做本地 network virtual+0x10；`49594B` / `495959` 對兩 Conn 呼叫 virtual+0x14 掛載接收。從有效原生連續解碼可見後三者的 return value **都未在 `49595B`／`495962` 的 BF64/BF68 store 前被 branch test**，接著 `495968 mov eax,1`；只證這個 helper 的**條件式完成/slot store**，不是 IOCP/WSASend／Server 收到的證據。若存在 old key1，`495853` 的 `0x007E`、2 bytes local queue API 返回值未查就由 `49585E` 標 oldConn+A0B0=1、`495868` 清 BF60；**不能宣稱 0x007E 一定送達對端**。

**靜態失敗前提**：`495807/49580F` 對 key0/key2 Conn NULL 的跳轉，可避免進入其成功 store；其它 provider callback 失敗、異步事件、合法 Client global 的全局生存期、BF58 alias/old-key1 最終回收、首次真 wire response 全部仍未知。legacy ports `0x20E0=8416`、`0x20DE=8414`、`0x20DF=8415` 僅是舊 Client 靜態值，**不是新 Server 部署建議**。

### 6.2 分工、正反證與驗收裁決

- **R0**：`SRC-0628/0629` Source Git blob/SHA256 已登錄；沒有改原始 E56。
- **R2**：32 bytes anchors、10 E8 直接候選與已核入口支持 **有界的 ESI 隱含上下文、雙 Conn 及後置 unchecked return 的 Client 靜態主張**。
- **R3 FULL-PASS**：**未完成**。沒有全文所有間接 caller、alias、動態狀態、virtual callback 與 Server/runtime 的原生閉合。沒有把字節匹配當全文語意驗證。
- **Server 待開發**：相容連線/接收路徑及三 key 的角色由 S00 設計，嚴禁從 local enqueue/Connect return1 推算原版 Server 已接收/認可。
- **跨功能**：T02/E56、T03 登入 0x13／選服、T01 原生驗證及 E57 首發判斷仍需引用各自精確版本；本稿不推任何 S00 RR 狀態變更。
- **待遊玩驗證**：同版 KR Client 真 socket trace、UI 實際 click、post-recv 及首回覆。原版 Server 內部策略未知不等於 Client 已驗的資料流不存在。

**總裁決**：extra/roy2 的兩個新增研究主題 RR-0004（仍 `IN_REVIEW`）與 RR-0005（之前已 `ACCEPTED` 的 bounded S00 research），均完成本次 T01 **來源合併 + 限定原生 R2 複核**；**沒有一份因此取得全文 T01 FULL-PASS，也沒有將 Source REGISTERED 升格為完整語意 NATIVE_VERIFIED**。
