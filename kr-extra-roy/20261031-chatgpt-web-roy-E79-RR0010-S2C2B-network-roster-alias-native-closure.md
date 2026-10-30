# E79 — RR-0010：S2C `0x002B` 真實入口至 2+53N 角色增量資料、兩條 roster writer 同址修正

> 2026-10-31 Asia/Taipei ｜`chatgpt-web roy`｜KR / T03｜既有 RR claim `extra/roy1`。BIN-first，大型定向研究，**45 項全新 read-only 原始 BIN 檢查 PASS**。本篇補足 E72 已找到但尚未接上網路入口的 `0x2B` table slot，並修正 E72 對紀錄目的地「不同」的結論；**原版 Server 的 C2S→S2C 交易配對及可玩驗收仍未證實，不能聲稱 RR-0010 正式完成／ACCEPTED**。

## 0. 來源、開工檢查與 scope

原始 `Tartaros.bin`: size `12,472,320`、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原始 `Tartaros.exe`: SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本次重新計算 BIN SHA，直接讀取 raw machine bytes；沒有執行、附加、修改原版 Client，沒有官方 Server capture。PE32 x86 / ImageBase `0x400000`；`.text` VA `0x401000`/raw `0x400`/raw size `0x7D0200`；`.rdata` VA `0xBD2000`/raw `0x7D0600`；其他 section 按原件 PE header 各自換算，不能直接共用 `.text` delta。

開工 GitHub 最新檢查：`main=bf1e15ebcb19c272106627303ab27ecc0b2b3514`，`extra/roy1=3c6da3fd965d79196bf3eaa816ca50c5f1f3cbdd`（寫入前重新核對）。正式 RR-0010 `BLOCKED`（claim branch `extra/roy1`），`GAP-CHAR-0003 OPEN`；S00 在 `governance/s00-iterations/S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md` 審查 E71～E74 後，明確不接受「遠征隊建名」等同「新增可操作角色」。本輪依使用者明確指定 RR-0010 繼續研究；獨立的 T03 `T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX` 尚未處理，沒有擅改或覆寫它；不修改 RR-0002/0007/0008/0009 主責／台帳。T01 shared FULL-PASS 入口已查；既有非全驗收來源僅作定位與去重。

### 本輪相對 E71～E78 的**實質新證據**

E72 已記錄 `0x4E1DA0` 表 `index0x2B→0x4E2730`，但認為「index 未必是 wire opcode」，並把 `0x4E2730` 目的 `[client+0x6924]` 與 `S2C0x0002` 目的 `[F94304]` 列成不同來源。E79 按原始機器碼**向上追通 transport callback 註冊與原生 vtable dispatch**，並以唯一固定 singleton 地址計算**證實兩者指向同一個 pointer cell**。因此此報告既是新增證據，亦是 E72「不同 destination」句子的**限界勘誤**，原稿不覆寫。

## 1. S2C `app 0x002B` 的四段分派正向鏈

### 1.1 Network manager command callback 註冊：`0x493170` → `0x49337A`

`0x493170` 以 `EAX` 為 table owner，`LEA EDX,[EAX+0x210]`，`ESI=0xBD5` 個 entry，用 `0x493190`：

```asm
493178  lea edx,[eax+0x210]
493180  mov esi,0xbd5
493190  mov [edx-8],edi       ; callback (index 0 = owner+0x208)
493193  mov [edx-4],ebx       ; companion state
493196  mov [edx],ecx         ; metadata
493198  add edx,0x10         ; stride = 16
49319B  dec esi
49319C  jne 0x493190
...
493375  mov edx,0x4943b0
49337A  mov [eax+0x4B8],edx
```

計算：`0x4B8 − 0x208 = 0x2B0 = 0x2B × 0x10`，故**network command index 0x002B 的 callback 被直接覆寫為 `0x4943B0`**。此處是 native table entry，不是從 `0x4E2730` 的函式名稱猜 opcode。其 call 前提是 transport 已成功解出 app command 並對應至此表；不宣稱任意 TCP bytes 在任意 Conn/mode 都會直接進這裡。T02 的 framing、解壓、lane 和 payload 有效性界線仍依原 owner。

### 1.2 網路 callback → 全域 Client singleton 的虛擬分派：`0x4943B0` → `0x4FDA30`

`0x4943B0` 使用 lazy initializer，確保 `0xF8D9E0` singleton 結構曾經由 `0x4E1590` 設置 vptr；之後：

```asm
49440C  mov eax,[ebp+0x10]     ; incoming app index / third parameter
49440F  mov ecx,[ebp+0x0C]     ; len / second parameter
494412  mov edx,[ebp+0x08]     ; payload / first parameter
494415  push eax
494416  mov eax,[0xF8D9E0]    ; first DWORD = vptr
49441B  push ecx
49441C  push edx
49441D  mov edx,[eax+4]
494420  mov ecx,0xF8D9E0     ; IMPORTANT: concrete this pointer
494425  call edx
```

`0x4E15C4` 在 singleton 建構時 `mov dword [0xF8D9E0],0xC0D15C`；原始 `.rdata` `[0xC0D15C+4]=0x4FDA30`。因此上述虛擬分派可定位到**同一個表 owner `this=0xF8D9E0` 的 `0x4FDA30`**；不是只有符號／可能方法。

### 1.3 singleton 次表 dispatch → 真正 2+53N consumer

`0x4FDA30` 按 `[ebp+0x10]` 的低16位作 `movsx edi,cx`，然後從 `[esi+edi*8+4]` 取得 handler，若可用則 `0x4FDA8A` 以 `ECX=ESI` 呼叫。這裡 `ESI=0xF8D9E0`；管理器表是**另一張 8-byte stride 表**，不能與 §1.1 的 16-byte transport 表相混。

`0x4E1AF4` 將 `EAX=0xF8D9E0` 傳給 `0x4E1DA0`（直接 call `0x4E1AFF`）。初始化預設 `0x4B7D40`，共 0xBD5 筆、每筆8B；特別覆寫：

```asm
4E1DA1  lea edx,[eax+8]
4E1DA4  mov esi,0xBD5
4E1DB0  mov dword [edx-4],0x4B7D40
4E1DB9  add edx,8
...
4E1E3F  mov dword [eax+0x15C],0x4E2730
```

`0x15C = 4+8×0x2B`，故**同一 app index 0x2B** 在真實 ingress path 到達 `0x4E2730`，由前兩層 original machine code/dispatch parameters 建立正向連接。

### 1.4 正向資料流圖

```text
T02 已解包的 app 0x002B，符合 network manager dispatch 前提
  -> manager callback table (0x493170, stride16, index2B, 0x49337A)
  -> 0x4943B0 / 0x49440C ... 494425
  -> lazy global Client singleton at 0xF8D9E0, vptr+4 = 0x4FDA30
  -> 0x4FDA30 / stride8 handler index2B, registration 0x4E1E3F
  -> 0x4E2730 / app payload=2+53N; each row 53 bytes
  -> 0x4D4150 / client role record+0x5C=1
  -> 0x4E5FB0 / local UI/status-related post
```

**以上是 Client 本地有條件可達路徑**，可作相容 Server 的有界 S2C app `0x002B` consumer 候選；不證明原版 Server 在任何建角操作後一定發它，也不證原版 Server 用它做成功／拒絕結果。

## 2. `0x4E2730` 的原生 record format、length 與錯誤前提

```asm
4E2734  mov eax,[ebp+0x0C]      ; len
4E2738  mov esi,ecx             ; THIS=0xF8D9E0 via path above
4E273D  cmp eax,2
4E2746  lea ecx,[eax-2]         ; compiler magic division by 53
4E2749  mov eax,0x3521CFB3
4E2756  shr ecx,5               ; floor((len-2)/53)
4E275F  mov edi,[ebp+8]        ; app payload
4E2762  add edi,2              ; first 53B row starts at +2
4E2767  movzx eax,byte [edi+0x2E]
4E276B  cmp eax,9              ; only upper bound here
4E2770  imul eax,eax,0x210
4E2776  add eax,[esi+0x6924]   ; **role record array pointer cell**
4E2782  call 0x4D4150          ; row source EDX=EDI, target ESI=record
4E278A  add edi,0x35          ; next 53-byte row
4E2794  call 0x4E5FB0         ; including N=0
```

限定合法形狀為 `u16 inner app command (0x002B)` + `N` 個 53B row，`N=floor((len−2)/53)`；`len<2` 時本 routine 計數為0，`len=2..54` 沒有完整 row，不會呼叫 `0x4D4150`；`len=55` 有一 row；長度額外的非完整 row bytes 在此 loop **不被當作完整 row**。這是 Client loop 行為，**不**證明全程安全拒絕短包；上一層 network/scene 判定可能不同。對 `row+0x2E` 大於9的資料跳過該 row 的 copy；不代表合法角色 ID 集合必然是0..9，更沒有 Server 授權驗證。共同 `0x4D4150` 寬字元 NUL copy 的越界風險沿用 E72 原生限定：應提供完整、NUL-terminated 的可消費 row，不發明角色名稱政策。

## 3. **E72 目的地修正：app2 與 app2B 寫入同一個 role record array**

在 §1.2 的正向入口中，`0x494420` 明確把 `ECX=0xF8D9E0` 傳給全域 object vtable；`0x4FDA35` 把 this 保存到 `ESI`，`0x4FDA88..8A` 又以 `ECX=ESI` 呼叫相同表的 index2B 實作。`0x4E2738` 將收到的 ECX 保存為 `ESI`。因此：

```text
0x4E2730 的 [ESI + 0x6924]，在這條正向路徑中
ESI = 0xF8D9E0
0xF8D9E0 + 0x6924 = 0xF94304
```

`S2C app0x0002` 的 65B-header roster loop 在 `0x4B899A..A0` 用 `index*0x210 + [0xF94304]` 定位 record；而 S2C app0x002B `0x4E2770..7C` 用 `index*0x210 + [0xF8D9E0+0x6924]` 定位 record。**這兩個 memory operand 引用同一個全域 DWORD pointer cell，不只是資料「長得像」或同用 `0x4D4150`。**

`0x4E19DC` 把分配的 10*0x210 bytes pointer 寫入 `[0xF94304]`；兩個 handler 對應同一組最多10筆的角色記錄。這也把 E77 `0x672F00` 以 `F94304+index*0x210` 讀取 `record+0x5C` 的 UI 分支正向串接到**兩種來源**：完整 roster 和有界增量更新都可提供角色紀錄可用旗標。此前 E72 §0/§3 將兩種 destination 寫作「不同」，本篇修正為**同一個指標欄位／不同封包 header 與呼叫上下文**。

```text
S2C app0x0002 (65 + 53*N) ─> 0x4B8920 ─┐
                                          ├──> [0xF94304] -> record[index]*0x210 -> 0x4D4150
S2C app0x002B ( 2 + 53*N) ─> 0x4E2730 ─┘                    │
                                                               └ record+0x5C=1
                                                                     │
                                          S2C0xB6 -> F4278 -> 0x672F00 UI reader
```

圖中的兩個 S2C writer→角色記錄 cell 是 memory identity 正向關係；第三條 UI handler 讀取同一記錄仍需有效事件、Page/child index、scene 和其他本地 gate。**不是單筆 Server 交易時序圖。**

## 4. 逐一排除錯誤配對：建名、招募、選角、角色更新分離

- **C2S `0x0033`（E71）**：`CEmployNewCharacter` 符合 0x578/控件 identity 且 `Client+0x5F4C !=1` 的分支 `0x6BF2FA→0x4A38D0` 送 `33 00`（2B）；不含姓名、角色外觀，不能直接把它與 app2B 以未經證實的 Server 因果配對。`Client+0x5F4C==1` 時走 `0x6BFAE0` 的 local scene/UI 分支而非同一 sender，重要反例。**新發現的 app2B 可能是某種角色增量通知，但不是已證 `C2S0x33` ACK。**
- **C2S `0x003E`（E73/78）**：真實遠征隊名稱 edit→驗證→`0x003E` 48-byte UTF-16 name+6，slot0、`+2..5 UNKNOWN`；同場景 S2C `0x004A` signed status+2→本地 `F4245` status1 名稱更新，**仍缺原版 Server 配對**；角色 record 更新不能由相同全域名稱直接推為 0x3E 結果。
- **S2C `0x002B`（本輪）**：handler 的可見 payload 是 53B rows，**沒有一個正向的「成功／重名／拒絕」專用 signed outcome/status 字段**；N0 時仍呼叫 0x4E5FB0，不代表建立成功。它是角色紀錄更新 handler，不是已證 official 建角結果 enum。
- **S2C `0x00B6`（E77）**：local F4278 觸發既有 record UI；E78 已驗 `F4278` 還有 `CPhaseSlot` 的獨立來源，故不能專屬看作「招募／建角成功」；B7 為不同 handler。
- **C2S `0x0042`（RR-0002）**：從既有可選角色 UI 寄出4B，S2C `0x42/43` 各有不同資料效果；不得偷借作 RR-0010 的回覆。

## 5. 驗收條件與下一步責任矩陣

| RR-0010 正式條件 | 本輪及 E71～E78 能支持 | 是否整體達標 |
|---|---|---|
| ① build/SHA、builder/consumer、方向別 fields/slot/frame/scene | BIN/PE、0x33/0x3E、0x4A、完整 roster app2、**新增經 network routing 確認的 app2B**/length/role writer、T02 framing 引用；仍有 0x3E+2..5 和必要配對/Conn UNKNOWN | **PARTIAL** |
| ② **建立新角色** request→matching accepted/rejected→roster/init，重複建立／斷線 | 現可證 role 更新 app2B 與 app2 共享 destination，可觸發 UI；**仍未證 C2S33/3E 與任一 response 的官方 Server 因果及 rejected/retry/disconnect 業務分支** | **NOT CLOSED** |
| ③ wire 與 local event、未知 Server 政策，42 不冒建角 | 已分開 C2S/S2C/event，明確保留未知 | BOUNDED PASS |
| ④ RR0002/0007/0008 來源復用/不越權 | 只引用，不改他人的研究範圍與 RR 台帳 | PASS |
| ⑤ 完整 Markdown、原始證據、負向測試/GAP/SPEC 影響及外部解除條件 | 本 E79 + 45 assertions 可重跑，附來源與明確可解除證據 | RESEARCH DELIVERED；S00 審查待辦 |

**正式結論：RR-0010 尚未全面完成，主題仍有 Client 真正的建角 result→roster 因果未證，應保持 `BLOCKED` 直到 S00 按唯一台帳規則處理。** 不因已提交研究原稿或 Client-only 完整 writer 便擅改成 `SUBMITTED`、`IN_REVIEW`、`ACCEPTED`、`GAP RESOLVED` 或 T01 FULL-PASS。使用者先前反覆要求完成，不能用多寫一份筆記冒充整體完成；這次 E79 明確解決的是 E72 留下的兩個可驗證 Client 缺口。

### Client 待逆向（T03／協作 T04/T06/T02）

1. **以新 app2B 為上游**追它是否在 CEmployNewCharacter 控件操作後確實更新指定 role 的本地可用狀態；需要 GUI/事件與直接或間接 caller 交叉證據，不能用「同 UI／同 index」猜出 Server 時序。
2. 定向追同版 S2C0x2B 是否還有在其他 active scene 下的特殊 register/handler override、相同 opcode 多 Conn/lane 上下文；本輪證的是 global F8D9E0 有界入口及其成功到達路徑，非所有 scene/indirect registrations 全集。
3. Client 取得真實建立成功/拒絕分支前，不得把不含 outcome 的 app2B 設計為唯一 ACK；錯誤／重名/斷線的原版 Client 是否重送可繼續查 UI state writer/timer/queue，原版 Server retry/idempotence 規則仍是獨立未知。

### Server 待開發（移交 S00，不阻止 Client 分析）

- 對 **既有 `REQ-0003` 角色清單**與 `REQ-0004` 角色 UI 就緒做去重增補：S2C app0x2B **增量角色資料** `2+53*N` 與 app2 完整清單 `65+53*N` 可寫同一 pointer cell；補成 `SPEC-CHAR-0001` DRAFT 方向別候選及 `TEST` synthetic：len2/N0、len54/N0、len55/N1、有/無有效 UTF-16 NUL、ID>9、record valid/invalid、B6 不發時仍可更新 record 的比較。
- 名稱唯一、保留字、招募／新增角色來源、持久化、重複提交、斷線冪等和錯誤呈現由 S00 設計 Server policy/ADR，不能當原版 Client 靜態研究停工理由；禁止在 wire `0x3E+2..5` 填猜測值，禁止將 app2B 當已證配對 ACK。
- **`GAP-CHAR-0003` 保持 OPEN**；S00 可選擇把「遠征隊身分名稱建立」與「角色招募/新增可用角色」分成兩個可各自驗收的 REQ/RR，保留 append-only 歷史，不由 T03 自行改權威台帳。

### 待遊玩／外部解除條件

A. 取得相同 KR build 原版 Server 的合法成功／失敗／重複／斷線抓包（包含全部 slot/Conn/frame 與 UI/scene 時間），證明實際 create request→結果→app2B/app2/B6 順序；或 B. verified 官方 Server source/handler；或 C. 再從此 Client 原始 BIN 找到明確把 `0x33`/`0x3E` 某 pending UI state 與 `0x2B` roster writer/拒絕 status 綁在同一筆建立操作的 native callback（需完整此物件/alias/CFG/反例）；或 D. 由 S00 正式修訂 RR 的**Client-only 可驗證終點**後按原程序 requeue 和審查。只有合成相容 Server 的跑通，不自動代表官方時序被還原。

## 6. 機器碼驗證腳本、重現與精確限制

```bash
sha256sum Tartaros.bin Tartaros.exe
python -B kr-extra-roy/20261031-chatgpt-web-roy-E79-RR0010-verify.py Tartaros.bin
# PASS 45 native BIN assertions; 顯示 SHA256 與尚未證實的 Server 因果界線
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x493170 --stop-address=0x4933b8 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x4e1da0 --stop-address=0x4e1e50 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x4e2730 --stop-address=0x4e27a2 Tartaros.bin
```

**驗證範圍：** 45 個 PE SHA/原始指令 byte、vptr/table pointer、direct E8、stride/offset、alias identity、C2S3E/33 反例檢查皆 PASS；不是 45 個完整功能、不是執行程式、沒有 T01 semantic FULL-PASS 或原版封包 capture。Script 獨立新檔（保留 E71～E78 原稿及 checker 不覆寫）。當 GitHub 上傳成功後，提交使用實際 blob SHA 與遠端 Commit SHA 為準。