# E74 — RR-0010：Expedition 建名結果與 S2C `app2` 名單的共享狀態，`0x26/0x24` 初始化依賴與 48B 發送安全界線

> **2026-10-31 02:44 Asia/Taipei｜chatgpt-web roy｜研究分支 `extra/roy1`**。延續 [E71](20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md)、[E72](20261031-chatgpt-web-roy-E72-RR0010-create-secondary-dispatch-roster-native-followup.md)、[E73](20261031-chatgpt-web-roy-E73-RR0010-expedition-name-create-C2S3E-S2C4A-native-chain.md)。本次從原件 `Tartaros.bin` 12,472,320B、SHA256 **`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`** 唯讀驗證；輔助原件 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。PE32 x86 ImageBase `0x400000`，`.text` VA `0x401000` raw `0x400` raw length `0x7D0200`。未執行／修改 Client，未連接原版 Server、未提供原版流量。驗證器：`kr-extra-roy/20261031-chatgpt-web-roy-E74-RR0010-verify.py`，**81 項原始 BIN byte／direct-E8-call 斷言 PASS**，非執行時或 T01 全文驗證。

## 0. 研究結論與正式 RR 驗收差距

E73 已證 `CExpeditionCreateDialog` 本地名稱輸入與驗證 → **C→S app `0x003E` 48B（slot0）**；LOGIN scene **S→C app `0x004A`** 取有號結果 `word+2` → **local `F4245`** → 對話框結果消費 → outcome `1` 保存名稱於 **`F938F2`**、變更 UI。E74 再以 raw-backed 指令證明：

1. **同一個 S→C `app2`（`0x4B7F00`）在處理 53-byte 角色名單以前，從 `payload+0x0C` 複製最多 20 UTF-16 code units 至同一全域 `F938F2`**。這是 E73「建立名稱結果」與 E71「角色清單」**在 Client 資料狀態上的可驗證交會點**。它不是原版 Server 封包因果順序的證據，卻明確限定 Server 可操作的共同 UI 名稱資料介面。
2. **`app2` 並非被動只讀 roster**：對每筆 53B record，它在本地資料寫入後使用 `0x0026` 3B app payload（2B opcode + 1B record slot、slot0 queue）；完整 list loop 後更新 mask、呼叫 `0x4E5FB0`，接著送出 `0x0024` 2B app payload（slot0 queue）。這是**名單→Client 發出補充請求**的限定、可重現內部順序；`0x26` 回覆內容、`0x24` 需要哪些 Server 狀態仍未在此證實，不能據 opcode 發明語義。
3. E73 `0x003E` payload 偏移 `+2..+5` 在已核對的**正常名稱驗證通過路徑**沒有發現寫入；`+6` 起的 21-WCHAR 區域由 `0x892E4D` 寫入，**並不保證尾端未用 bytes 全為零**。若來源超出目的 wchar 容量，helper `0x892E9F` 會將首 WCHAR 設零並回傳錯誤，但 `0x67251C` 的呼叫者**沒有檢查回傳值**就進入網路 gate。這是原版 Client 的局部邊界，**不是合法 Server 輸出定義**。合成測試應保守初始化整個 app payload，不能把未初始化四 bytes 冒充「官方固定零」或任意填值後稱其相容。
4. E73 `S→C 0x004A` 的結果經 `0x58AB80` 建立 24B 本地事件，明確保存 `[event+0x10]=F4245`、`[event+0x14]=sign_extend(word[payload+2])`；UI 顯示成功僅當 `status==1`。錯誤 `-1`、`-2`、`-3` 與 default 各有不同本地處理分支，但**不代表已知原版 Server 錯誤文字或重名策略**。

**因此本輪已閉合的部分**是：建名 C2S 本地封裝 → 候選 S2C scene result → local event/成功狀態；另一個 S2C 名單 handler 的共同名稱寫入與依記錄發出的補充 C2S 請求。**尚未閉合的 RR-0010 關鍵**：原版 Server 真實 `0x003E` 與 `0x004A` 配對／成功錯誤順序、是否與後續 `app2` 在同一建立交易、自由創建 playable-character 是否為本 KR Client 的功能。這是**Client 原生正向配對／跨流程未知**，不是應拿「原版 Server 內部政策未知」獨自作為停止研究的藉口。

## 1. `app2`：在名單前先解析 shared Expedition 名稱

入口 `0x4B7F00`，`0x4B7F37 mov edi,[ebp+8]` 指向 incoming application payload，`0x4B803F mov edx,[edi+2]`，`0x4B8042 mov [F93930],edx`，而下列源級片段定義共用全域名稱：

```asm
4B8075  push 0x14                 ; source 20 WCHAR
4B8077  lea eax,[edi+0x0C]       ; app2 payload + 12
4B807A  push eax                  ; source
4B807B  push 0x15                 ; destination 21 WCHAR
4B807D  push 0xF938F2            ; same global name as Expedition-create result
4B8082  call 0x893FFE             ; bounded TCHAR/WCHAR copy
4B8087  add esp,0x10
...
4B8923  mov ecx,[ebp+0x0C]      ; original app payload length
4B8926  cmp ecx,0x41             ; only here row count guarded by len>=65
4B892F  sub ecx,0x41
4B8932  mov eax,0x3521CFB3       ; 53B divide via reciprocal
4B894A  test ecx,ecx
4B894C  je 4B8A20                ; N=0 still name/header processed
```

**精確有限契約**：`app2` header 有 `[+2..+5]` 32-bit 被取到 `F93930`，`[+0x0C..+0x33]` 20 UTF-16 code units 供複製至 `F938F2`；`len>=65` 才存在完整 row 計數 `(len-65)/53`，row 從 payload `+0x41` 起。`0x4B807D` 先於 `0x4B8926` 的 `len>=65` row-count gate，因此不能把 `N=0` 或「len<65 就只安全忽略」誤認為 header/name 讀取安全：此處**沒有看到先以 length 防護完整 20 WCHAR header**。這是 static consumer 行為，不證 Server 實際傳過短包，也不證 global `F938F2` 必定原先有或沒有名稱。

同一個 `F938F2` 另有：

```asm
672617  push 0x14
672619  push esi                  ; local edit UTF16 name after status 1
67261A  push 0x15
67261C  push 0xF938F2
672621  call 0x893FFE             ; 0x004A local success branch
5F49B8  mov edx,0xF938F2        ; render UI text
5F49BD  call 0x757F20
```

**共同狀態不等於 `0x4A→0x2` 的網路依賴已證**：`0x672570` 與 `0x5A6886` 成功路徑沒有直接呼叫 `0x4B7F00` 或 `0x4D4150`；`app2` 與 `app4A` 是不同 incoming dispatch entry，各自可以更新名字，不可捏造固定順序或自動刷新。

## 2. `app2` 53B 角色列表 → 每筆 `0x0026` 與結束 `0x0024`

```asm
4B8952  mov edi,[esp+0x28]       ; saved incoming app buffer
4B8956  add edi,0x6F             ; row[0x2E] slot, first row at payload+65
4B8992  movzx eax,byte [edi]
4B8995  cmp eax,9
4B8998  ja 4B89B5                ; if >9 skip record copy (not rest of loop)
4B899A  imul eax,eax,0x210
4B89A0  add eax,[F94304]         ; roster slot structure base
4B89A8  lea edx,[edi-0x2E]      ; source record
4B89AD  call 0x4D4150           ; row copy (flag +0x5C etc., E71/E72)
...
4B89D2  cmp dword [FBA798],0
4B89DC  mov edx,0x26
4B89E1  mov word [esp+0x18],dx
4B89E6  mov byte [esp+0x1A],al  ; record slot
4B89F7  push 3                  ; 2B app opcode + 1B slot
4B89F9  lea edx,[esp+0x1C]
4B89FD  push edx
4B89FE  push 0                  ; queue slot 0
4B8A00  call eax                ; manager virtual+0x10
4B8A0E  add edi,0x35            ; 53B next record
...
4B8A60  mov word [F94240],ax   ; local roster mask
4B8A97  mov ecx,0xF8D9E0
4B8A9C  call 0x4E5FB0
4B8ABD  cmp dword [FBA798],0
4B8AC4  mov ecx,0x24
4B8AC9  mov word [esp+0x2E],cx
4B8ADB  push 2
4B8ADD  lea eax,[esp+0x32]
4B8AE1  push eax
4B8AE2  push 0
4B8AE4  call edx
```

**本地處理順序**是 `app2` header/name → optional N record loop (bounded only for row count) → `record+0x5C=1` for accepted slot → per-row optional `C2S0x26` → roster mask / post → optional `C2S0x24`。實際 on-wire `0x26/0x24` 的 frame、對應 S2C 回覆、選角可達與 scene 初始化仍需要 T02/T03/T04 其他證據；即使 `N=0` 也會執行 `0x4E5FB0`、具 gate 的 `0x24`，不能宣稱 `N0` 自動打開建角 UI（RR-0009）。

**反例：**當 record slot `>9` 時，`0x4B8998 ja` 只跳過 `0x4D4150` 的 row copy，仍沿 `0x4B89D2` 的 per-row request 路徑；若 queue manager gate `FBA798!=0`，即使有 record 也不呼叫 `0x26` 送出介面。不可把 `0x26` 稱「只在有效角色時送」。Record 的 `53` 大小和嚴格 name NUL 條件已在 E72 界定，不由本輪憑空新增官方角色初值。

## 3. `0x003E` 48B payload：精確 byte 來源與未初始化界線

`0x672180` prologue `and esp,-8; push -1; push EH; push fs:0; sub esp,0x48; ...; push EBX/ESI/EDI; push cookie`。令完成 prologue 的 `ESP=S`，當到達正常驗證通過分支 `0x6724B1`，即：

```asm
672505 push esi
672506 lea edx,[esp+0x2A]     ; S+0x26 (=payload+6)
67250A mov ecx,0x3E
67250F push 0x15               ; max 21 WCHAR incl NUL
672511 push edx
672512 mov word[esp+0x2C],cx  ; S+0x20 (=payload+0)
672517 call 0x892E4D
67251C add esp,0x0C
67251F cmp dword[FBA798],0
672533 push 0x30               ; 48-byte total application payload
672535 lea edx,[esp+0x24]     ; S+0x20
672539 push edx
67253A push 0                   ; queue slot0
67253C call eax                ; manager vtable+0x10
```

因此精確 wire/application **payload bytes**：`+0..+1=3E 00`、`+2..+5=UNKNOWN`（沒有在本次追查的 positive-path 本地組裝流程找到寫入，**不能假設 zero**）、`+6..+47=21 UTF-16 code-unit output slots`（第一個 NUL 之後未使用空間**未見整塊清零**）。`0x892E4D` 每次讀、寫 2 bytes，遇 NUL 停止；容量歸零 `0x892E9F mov word[dest],0`，設 CRT errno `0x22` 並回錯誤。`0x67251C` 只做 `add esp,12`，沒有讀回傳值／分支：**失敗後仍有可能進 manager gate，不能把封包發送當作已通過目的緩衝拷貝檢查。** 真正上層 GUI edit length gate 與全體字詞比對仍可能額外約束，本輪不以 helper 單獨定義玩家可輸入長度。

**S00 的安全實作說明（非原版 Server 政策）：**應把 `0x3E+2..+5` 標 UNKNOWN，避免用未證 4 bytes 做 DB key/帳號信任；接收包時應明確檢查 frame/bounds/name NUL/合法性，建立 idempotence／重名處置的 Server 自訂策略，並將合成 payload 餘位明確初始化。這些是相容 Server 的待決策事項，不是說原版 Client 保證送出被清零的 48 bytes。

## 4. `0x004A` → 事件物件 → UI：完整的 local status 位元傳遞

E73 已證 scene `0x4C14E1` index `0x4A` 登記至 `0x4C21D0`。E74 新證 `0x58AB80` 將收到的 signed result 放入**獨立本地事件**：

```asm
4C21D6 movsx ecx,word [payload+2]
4C21DA push ecx
4C21DB push 0xF4245
4C21E0 call 0x58AB80
58ABA4 push 0x18                 ; alloc 24 bytes
58ABB4 mov edx,[ebp+8]
58ABB7 mov [eax+0x10],edx        ; event code=F4245
58ABBA mov edx,[ebp+0xC]
58ABD4 mov [eax+0x14],edx        ; signed result (32-bit)
58AC18 call 0x804260            ; local event queue path
5A680E add eax,0xFFF0BDBB       ; event minus F4245
5A6895 call 0x672570            ; create dialog result consumer
5A689A cmp dword[ebx+0x14],1    ; success UI only
6725A2 mov eax,[eax+0x14]
6725AA cmp eax,ecx              ; ecx=1
```

`-1` 在 `0x67264D`、`-2` 在 `0x6727AF`、`-3` 在 `0x672817`，其餘 default 進另一文字提示；局部 UI 文字資源來自 `0x5854B0` 等，**不以文字推回官方 Server enum、重名／滿額語義**。Result !=1 不走 `5A68A4..BA` 名稱更新/ready flag；沒有從該 callback 直接到 `app2` roster 的 native call。`S2C0x4A` 仍需符合 LOGIN scene 生效條件，原版 Server 是否把它當 `C2S0x3E` ACK 未有實際交互 trace。

## 5. RR-0010 按正式條件的逐項判定

| 驗收條件 | E71–E74 可重現證據 | 未閉合／不能宣稱 |
|---|---|---|
| 1. 原件 SHA、producer/consumer、offset、len、encoding、scene/Conn | 原件 SHA、C2S 3E 48B offset0/6 slot0；S2C app4A signed result+2，local event 與 app2 65+53N；21 WCHAR copy | `3E+2..5` 值、完整 TCP frame/實際 Conn 變更、其他 S2C handler 覆寫及 runtime scene |
| 2. 正向請求→回覆→roster/初值＋失敗/重試 | 名稱 UI→3E sender、app4A→F4245→local outcome1，與 app2 共同 name writer；app2 per row 26、post24，非1失敗枝 | 無原版 Server 真實3E↔4A配對；無 4A→app2 on-wire 因果；官方 duplicate、disconnect/retry、初值結果不明 |
| 3. 分離 Client local／transmitted；不可把選角0x42當創角 | 已證 `F4244/F4245` 是 local、3E/26/24 是 Client send、4A/2 是 Server-facing consumer；0x33 `CEmploy` 和0x42 selection 分離 | 不可創造原版 Server status／玩家自由捏角欄位 |
| 4. RR-0002/0007/0008 相鄰復用 | 僅引用，不改各自結果與台帳 | 選角→場景、註冊表等其它任務獨立審查 |
| 5. 完整原稿／blob／bounded negative／S00 影響 | 本原稿、81 assertion verifier、四類移交、具體缺口 | Git blob 需本文件 Push 後核對；正式 S00 RR 審核不由研究者自動宣布 ACCEPTED |

**狀態界線**：RR-0010 在本次讀取之 GitHub `main` `412a2374a7c6c56de8ab881bcac8c9caa8aaac5c` 仍為 `BLOCKED`；`GAP-CHAR-0003 OPEN`、`SPEC-CHAR-0001/SPEC-FLOW-0001 DRAFT/PARTIAL`。本次已提供另一批實質原始證據，且其正式驗收第5項允許「無原版 Server 配對時明列解除條件」。**是否依第5項可解除 BLOCKED、將 bounded report SUBMITTED 送審、或由 S00 拆分「遠征隊身分命名」與「可操作角色招募」的 RR，必須按唯一台帳與正式權限處理；研究者不能自行補改 main 或標 ACCEPTED。** 此 Markdown 是可供 S00 直接引用的原始研究結果，而非 Server 已能建立角色的可玩證明。

## 6. 四類分流與下一步——不得因 Server-only 未知停止 Client 分析

- **Client 待逆向（T03）：** `0x3E+2..5` 的完整 CFG stack writer 證否（本輪僅 positive-path 明顯存取）、`0x4A` 可能的 scene 層 dispatcher 覆蓋、LOGIN scene 零 roster→create dialog、`0x26/0x24` 對應 S2C/init consumer、`0x4A` 狀態提示文案及取消/重試 UI，屬於可繼續原生研究，並不以缺原版 Server 為理由停工。
- **Server 待開發（S00 收件）：** 使用既有 REQ 去重，評估獨立建立遠征隊名稱的 `CODE_ANALYSIS` 候選 REQ，與角色 unlock/recruit 分離；正式規格宜列 `C2S0x3E(48B, name+6, unknown+2..5)`、`S2C0x4A(result +2)` **source-only pair candidate**、S2C app2 header name+0xC／65+53N、per-row C2S0x26／post C2S0x24，並註明非已證原版時序。名稱合法性、唯一性、資料庫持久化、duplicate/斷線冪等、Server 自訂錯誤回應屬 ADR/TEST，不可冒充原版官方 Server 規則。
- **跨功能待整合（T02/T03/T04/T06/S00）：** T02 slot0 app framing/Conn 與 queue gate、T04 可操作角色初始／招募、T06 GUI pack 的 create UI 可達性、T03 response/table/roster 主張、S00 的 `REQ/SPEC/GAP/TEST` 審查；不修改其他 owner 的文件或其 RR。
- **待遊玩驗證（另行授權）：** 原版 Client + 隔離相容 Server 做建名成功及不同 status、零/多角色 app2、出/入世界、斷線重試測試；合成向量與原生原版行為分層標識。

### 精確解阻條件

A. 以同版可信原版 Server 行為 trace/來源證明 `C2S0x3E` 對應 `S2C0x4A`、結果後的 `app2`/0x26/0x24 時序，以及實際失敗/重送；或 B. 新的 Client native call/scene-statewriter 證明建立結果對下游 roster/UI 的完整必要連接；或 C. S00 正式收斂 RR 可驗範圍，將「Expedition name create」和「playable-character recruit」分成不同可測 Server 契約，保留未知值為 UNKNOWN；或 D. 另經使用者授權的隔離相容 Client runtime trace 供相容性而非官方原版時序證明。

**參考：**GitHub `research/requests/index.json`、`research/dispatch/README.md`、`governance/s00-workflow.md`、`design/requirements/README.md`；其他研究採來源/blob 可稽核復用而不覆寫 E71–E73。`E74` 僅對所列指令/呼叫核驗，不宣稱已完成全 `.text` CFG 或 T01 FULL-PASS。