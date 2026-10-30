# E73 — RR-0010 KR 建立流程正向突破：`CExpeditionCreateDialog` → `0x003E` 名稱請求、`0x004A` 結果 → 本地 `F4245`／UI

> **2026-10-31 Asia/Taipei｜chatgpt-web roy｜研究分支 `extra/roy1`｜第一手原始 BIN 唯讀研究，未執行 Client。** 原件 `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；參照 `Tartaros.exe` 2,594,816 bytes，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。`Tartaros.bin` PE32 x86 ImageBase=`00400000`；`.text` RVA `00001000`／VA `00401000`、raw `00000400`、raw size `007D0200`；以下 VA 均依原始 section header 映射確認。完整可重現檢查器：`kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-verify.py`，**58 項原始 BIN 指令、表槽、分支與呼叫驗證全 PASS**。自動斷言不代表 T01 FULL-PASS／官方封包實測。

## 0. 研究目標、歷史誤解與成果範圍

RR-0010 名稱是「character-create C2S/S2C positive transaction and roster initialization boundary」。E71／E72 已發現 `CEmployNewCharacter@FUI@@` 的 `0x6BF2A0→0x4A38D0` 僅送出 `0x0033`、**2-byte** 內層應用 payload，根本不含命名欄位；`0x0021` 多種用途及 `0x0027` 8-byte 也無正向建立玩家身分證據。E72 另證明兩條不同角色資料 writer（`65+53*N` 與 `2+53*N`），但沒有交易鏈。此前過度按傳統 MMORPG「新建自由捏角角色」尋找，有可能混淆 **遠征隊／玩家身分命名** 與 **招募預製可操作角色**，本次須以 BIN 重新確定真正輸入名稱的 sender。

本輪實際找到：**有 RTTI 的 `CExpeditionCreateDialog@FUI@@` → 按鈕及確認事件 → 寬字元名稱檢查 → C→S app `0x003E` 48-byte 的內層 payload；另外找到 LOGIN scene S→C app `0x004A` 的有符號結果字、該結果轉成本地 `F4245` 事件，進入對話框 `0x672570`，成功時保存輸入名稱到 `F938F2`，後續 UI 更新。** 這解決了「存在真實具名稱欄位的 Client 建立請求與結果處理者」的主要靜態研究缺口，**比 E71 的 `0x0033` 更切題**。但：沒有原版 Server 原始封包、沒有同一 transaction 的實際 trace，也沒有證據建立 `0x003E → 0x004A → command2 roster 65+53N` 的因果順序；因此**不能宣告原版 Server 必然用 0x4A 回覆 0x3E、不能宣告新增任意角色或 Server 已持久化，也不能由研究者自行把正式 RR-0010 從 main 的 `BLOCKED` 改為 `SUBMITTED/ACCEPTED`**。應由 S00 按本新證據重新核對 RR 問題（原題「角色」是否誤指遠征隊命名）與解除條件。

補充其他地區、不同時期的**非原生背景**：日本遊戲評測（https://game.watch.impress.co.jp/docs/review/346384.html）指出遊玩角色是故事中的預設角色，Wiki（https://wikiwiki.jp/re-tar2os/%E5%BA%8F%E7%9B%A4%E3%81%AE%E6%B5%81%E3%82%8C）指出最初建立遠征隊名稱。上述資料只用來選研究方向，**不可當成本 KR BIN 的封包或 UI 證據**。

## 1. 第一手類別身分與 UI 事件正向來源

MSVC RTTI 原生名稱 `. ?AVCExpeditionCreateDialog@FUI@@`（去空白即 `.?AVCExpeditionCreateDialog@FUI@@`），本機映射到 type descriptor；vtable `0xC35784`，`0x671F35: C7 06 84 57 C3 00` 寫 `this->vptr=0xC35784`；**slot87** `[0xC35784+87*4] = 0x671FD0`。另外的 `CEmployNewCharacter` vtable `0xC3F024` slot87=`0x6BF2A0`，證明兩者不同對象；不能再拿後者 `0x0033` 的 2B 當遠征隊建名。此 RTTI 是符號性字串原生證據，名稱「Expedition」仍不證明遊戲所有版本規則。

`0x671F80` 初始化 UI 控制成員：`0x671F8A lea edi,[esi+0xF0]; 0x671F92 call 0x672900`、`0x671F97 lea edi,[esi+0xF4]; 0x671F9F call 0x6729F0`；後續 `+0xF0` 是取文字的欄位，`+0xF4` 是比對按鈕事件的控制。

`0x671FD0` callback：

```asm
672001 mov eax,[ecx+10h]                ; event code
672004 cmp eax,578h                    ; control UI click
67200F mov eax,[esi+0F4h]             ; dialog button
672015 mov eax,[eax+20h]
672018 cmp [ecx+8],eax                 ; identity match or skip
672021 mov edi,[esi+0F0h]             ; edit control
67203E cmp dword [edi+118h],ebx       ; text gate
67206F mov dword [eax+10h],0F4244h    ; local confirmation event
...
672154 cmp eax,0F4244h                ; local confirmation returned
67215B cmp dword [ecx+14h],6A7h       ; local affirmative branch
672165 call 672180h                   ; name validation and send
```

`F4244`、`0x578`、`0x6A7` **全部是本地 UI 事件／確認碼，不是 C2S opcode 或 S2C command**。控制不匹配、未經本地確認、必要文字條件不成立均可能停在本地 UI；這些是正式 C2S builder 的上游前提，不意味著原始執行時畫面必定已可見。零角色名單 `S2C app2 N=0` 可否打開此對話框仍屬 RR-0009 的獨立問題。

## 2. 名稱驗證：不是 Server 帳號命名政策

`0x672180` 從 `dialog+0xF0` 的文字控制抽出 UTF-16 字串；依 `[edit+0x11C] < 8` 選 inline `edit+0x108` 或堆配置 `[edit+0x108]`。**這是 Client string 儲存分支，絕不是「名稱只能 8 字」**。在 `0x672240` 逐 `WORD` 讀取、`0x672243` 比較 `0x80`；ASCII 走 `0x672358`（`'0'..'9'`）、`0x672364`（`'A'..'Z'`）、`0x672370`（`'a'..'z'`）條件，非 ASCII 走全域 `FB7608` 的 classifier `vtable+8`，拒絕時跳 `0x6722C0`。逐字符之後，`0x672274`、`0x672288`、`0x67229C`、`0x6722B0` 分別呼叫 `0x81EB80`，參照全域配置 `FB75C8/E8/D8/F8` 進一步比對，未通過進本地錯誤/提示路徑。這些比較的語言／字典內容目前未被解析，不可宣告完整合法字元集、禁詞或官方角色重名政策。

僅在原生控制與驗證鏈到達 `0x6724B1` 後，才依 `edit+0x11C` 取來源寬字元指標，構造封包；任何未經驗證的合成 payload 都不能據此推論原版 Client 實際會傳。

## 3. **C→S 建名 0x003E：48-byte 內層 app 載荷、slot0**

原始 `0x672505–0x67253C`：

```asm
672505 56                       push esi              ; UTF16 source
672506 8D 54 24 2A              lea edx,[esp+2Ah]    ; name destination
67250A B9 3E 00 00 00           mov ecx,3Eh         ; u16 opcode 0x003E
67250F 6A 15                    push 15h              ; dest capacity 21 WCHAR
672511 52                       push edx
672512 66 89 4C 24 2C           mov word [esp+2Ch],cx; app offset0
672517 E8 31 09 22 00           call 892E4Dh         ; bounded UTF16 copy
67251C 83 C4 0C                 add esp,0Ch
67251F 83 3D 98 A7 FB 00 00     cmp dword [FBA798],0
672526 75 16                    jne 67253Eh         ; if unavailable, no send
672528 8B 0D 54 A8 FB 00        mov ecx,[FBA854]    ; network manager
67252E 8B 01                    mov eax,[ecx]
672530 8B 40 10                 mov eax,[eax+10h]   ; virtual queue method
672533 6A 30                    push 30h             ; **48-byte payload**
672535 8D 54 24 24              lea edx,[esp+24h]   ; payload pointer
672539 52                       push edx
67253A 6A 00                    push 0               ; **slot argument 0**
67253C FF D0                    call eax            ; enqueue/send
```

嚴格 stack 運算（避免把 `LEA` 臆解成另一封包）：令 `S=ESP` 在 `0x672505` 前。`push esi` 後 `LEA edx,[esp+2Ah]` 指 **`S+0x26`**；另兩次 `push` 後寫 `word [esp+2Ch]` 指 **`S+0x20`**；虛擬送出前 `push 0x30` 後 `LEA [esp+24h]` 亦指 **`S+0x20`**。故 payload `[S+0x20..S+0x4F]` 共 `0x30=48` bytes，opcode 16-bit LE 位於 **偏移+0..+1**，名稱目標 **偏移+6 起、42 bytes（21 WCHAR 槽位）**。**偏移+2..+5（4 bytes）的來源和值未追到保證，保留 UNKNOWN／不要填 0**。``等字面事件不是 payload。

`0x892E4D` 輔助函式 `0x892E87 movzx ecx,word[eax]`／`0x892E8A mov word [edx+eax],cx`、每碼位加2，`0x892E96 dec edi`，以 NUL 或計數限界；容量耗盡時 `0x892E9F` 將首 `WORD` 置0 並回報失敗。**因此 21 WCHAR 是目的欄位容量，不代表能安全輸入 21 個非 NUL 字或 payload 的未使用空間必被填零**。`FBA798==0` 是特定 manager gate，不能推論 socket 已在 wire 傳送；外層 frame／可靠性／connection lane 仍引用 T02，不把 inner `0x003E` 誤當 TCP 外框。

## 4. **S→C app0x004A 的 LOGIN scene handler；正向 native consumer，但未有官方 request-reply trace**

`0x4C14B6` 取得場景物件的 base `ESI+0x5EAC`，`0x4C14C8 call 0x89E860` 初始化表；明確覆寫：

```asm
4C14E1 C7 86 FC 60 00 00 D0 21 4C 00   mov dword [esi+60FCh],4C21D0h
4C14EB C7 86 EC 61 00 00 F0 21 4C 00   mov dword [esi+61ECh],4C21F0h
```

每 app 表槽 stride 8；`(0x60FC-0x5EAC)/8=0x4A`，第二個是 `(0x61EC-0x5EAC)/8=0x68` **不同 handler**。全域第一層 S2C app `0x004A` 未在 E71 研究的 `0x4B7DC0` init 做專用覆寫，使用 active scene fallback→scene table；**因此是否在此 LOGIN scene 收到及出現本事件，仍取決於 scene 狀態與其他 dispatch gate**。

`0x4C21D0` 實際讀 `payload+2` 的 **有號 16-bit 結果**：

```asm
4C21D3 8B 45 08        mov eax,[ebp+8]         ; app payload ptr
4C21D6 0F BF 48 02     movsx ecx,word [eax+2] ; signed result
4C21DA 51              push ecx
4C21DB 68 45 42 0F 00  push 0F4245h            ; LOCAL app/UI event
4C21E0 E8 9B 89 0C 00  call 58AB80h
4C21E8 33 C0           xor eax,eax
4C21EB C2 0C 00        ret 0Ch
```

此函式自身**沒有在讀取 `+2` 前做明確長度檢查**；不能把自訂測試器的「短包拒絕」冒稱原版原生 guard。這個 `0x004A` / `0x003E` 配對是基於 Client 同一畫面功能的**強有界關聯**，並非從同一條真實 Server transaction 觀察到的「必然 ACK」。`0x004A != 0x003E+1`，不能用機械 request+1 推論；真正 original Server policy／進入 LOGIN scene 的順序／失敗 enum 訊息文字仍待驗證。

## 5. S2C local event → 建名結果 → UI name update

LOGIN scene consumer 呼叫 `0x58AB80(event_code=F4245, signed_result)`。本地 owner 的 `0x5A67D0` 讀 `[event+0x10]`，`0x5A680E add eax,0xFFF0BDBB`（扣除 `F4245`），`0x5A681C` 讀映射 table `0x5A69A0`，`0x5A6823` 跳到 jump-table `0x5A6988`；index0 slot=`0x5A6886`。**本地事件常量 `F4245` 不可冒充 on-wire app id**。

```asm
5A6886 call 40AFC0h           ; local result/context pointer
5A688B mov ecx,[edi+140h]    ; Expedition dialog
5A6891 push esi              ; event pointer
5A6892 push ecx              ; dialog
5A6895 call 672570h          ; result consumer
5A689A cmp dword [ebx+14h],1 ; local outcome==1
5A68A4 mov esi,[edi+134h]
5A68AA call 5F4910h          ; UI controls update
5A68AF mov esi,[edi+134h]
5A68B5 call 5F4950h          ; UI display name
5A68BA mov dword [edi+144h],1
```

`0x672570` 取 `[event+0x14]`（`0x67259F–0x6725AC`），比較 1，其他值走 `0x67264A` 的 `-1` 比較、`0x6727AF` 的 `-2`、`0x672817` 的 `-3` 與 default 分流。**結果枚舉的官方業務含義未解**：不可先定義 `-1=重名` 或 `-2=滿額`；應再對照訊息資源/原版觀察。`status==1` 的 `0x6725B2` 讀取同一文字 edit control，按 SSO 分支取 UTF16 字串，`0x672617`：

```asm
672617 push 14h                ; source count/copy parameter
672619 push esi                ; local name source
67261A push 15h                ; destination count 21 WCHAR
67261C push 0F938F2h           ; destination persistent local name
672621 call 893FFEh            ; guarded string copy
672633 call dword [vtable+D4h] ; close/transition local dialog
```

`0x5F4910` 對 UI 控制做啟用／可見狀態調整，`0x5F4950` 從 `F938F2` 顯示名稱，建立可確認的**結果→本地名稱/介面變更**。`0x5A68BA` flag `[owner+0x144]=1` 也僅是 Client local ready；不能據此證明 Server 已新增 53-byte 角色資料、已寫入 DB 或畫面必達可操作世界。

### 可稽核的 Client-only 功能鏈與反例

| 節點／條件 | Source-backed positive | 排除／未證範圍 |
|---|---|---|
| GUI event=0x578 + button identity + local confirm F4244/0x6A7 | `671FD0→672180` | 不代表所有 N=0 roster 自動開啟（RR-0009） |
| UTF16 input / local validation | `672180..6724B1`、寬字元與四項字串比較 | 不代表 Server 帳號命名政策、character avatar fields |
| inner C2S 003E | `672505..67253C`，48B，slot0，name offset+6 | `+2..+5` UNKNOWN，TCP外框未證，manager gate 可不送 |
| scene S2C app004A | `4C14E1→4C21D0`，signed WORD +2 | 必須 active scene；和 C2S 003E 原版因果未由 Server trace 證實 |
| local result F4245 | `4C21DB→58AB80→5A67D0/5A6886` | 不是 C2S opcode，不能推 request+1 |
| local success outcome=1 | `672570/672617→893FFE→F938F2→5F4910/5F4950` | 不等於 app2 roster、53B record writer、選角 0x42 或世界初始化 |
| distinct non-1 outcomes | `67264A`(-1), `6727AF`(-2), `672817`(-3), default | 原版錯誤碼文案／重名／取消／重試 Server side 未證 |

## 6. 與 E71／E72、其他 RR、Server-only 需求的界線

- E71 `CEmployNewCharacter` app `0x0033` 2B 是**不同 UI 類別**。目前最有證據的「名稱建立」是 `CExpeditionCreateDialog→0x003E`。若目標其實是招募預設角色，`0x0033` 可另供 T04 或 S00 查既有 REQ／GAP，但不得與此請求合併為「玩家自由捏角」協定。
- E72 `0x4E2730` `2+53N` 與 E71 `0x4B8920` S2C app2 `65+53N` 均有 Client record writer，**本次結果處理沒有任何可靠的正向呼叫鏈直接更新它們**。所以沒有聲稱 `0x003E → 0x004A → 0x0002` 必然是同一 Server 交易；需 S00 決定建遠征隊與建立角色之需求/測試是否分成不同 milestones。
- **RR-0002** C2S `0x0042` 是**選擇既有角色**；S2C app `0x0042/0x0043` 不能冒充本次建名結果；**RR-0007／RR-0008** 是 dispatcher／選角→scene 界線；**RR-0009** 是空名單或 create button 能否開 UI。這些 RR 範圍及狀態保持原狀。
- Client 仍須逆向：`0x003E` `+2..+5` 的真正 initializer/source；其他 scene 是否會覆寫 app0x004A；`0x58AB80` local event 物件結果資料傳遞的全鏈；dialog 被哪個 N=0 控制建立（RR-0009）；成功後何時 S2C0x2 roster、初始狀態或選角（別的流程）；不同失敗值之 Client 文字/可重試 UI。尚未找到原版 Server 時序不阻止以上可推進的 Client 靜態分析。

## 7. **依 02 共用規範正式分流與 S00 交接（不是停止 Client 的藉口）**

1. **Client 待逆向（T03 主責）：**真實 003E payload `+2..+5`、LOGIN scene 可達性與事件 context、結果狀態文案、額外 S2C writer／後續 roster 初始化與本機重試；T02 framing；T06 GUI 資源入口（對應 RR-0009）；T04 遠征隊與操作角色初值區分。仍以 BIN-first 自查，不因沒有原版 Server 停止。
2. **Server 待開發（交 S00）：**建立／保留遠征隊名稱的權威與持久化、名稱唯一性與保留字、角色/遠征隊資料模型、登入初始化與建立失敗、重複送出與斷線後冪等處理。需對照現有 `design/requirements/index.json` 的 `REQ-*` 去重；現有 `SLICE-CREATE` 為規劃視圖、非已證 packet。建議 **S00 評估獨立候選 REQ**（遠征隊命名、可操作角色解鎖/招募若需求不同才分），並按有限 Client 正向證據更新 `SPEC-CHAR-0001`、`SPEC-FLOW-0001` 的 DRAFT 和 `GAP-CHAR-0003`；**不能自行編官方 0x004A status 文字、0x003E +2..+5 欄位或既有 Server 政策**。這是 Server-only 待決策，**不是阻止 Client 研究的理由**；本研究工作分支不直接改 S00 owner 的台帳。
3. **跨功能待整合：**T03 登入/Expedition UI 与 T02 queue(slot0)/frame、T04 預製角色欄位、T06 同版 GUI 資源、S00 REQ/GAP/SPEC/TEST，對照原生主張的 SHA 與證據邊界，不跨 KR/TC 混用。
4. **待遊玩驗證：**經使用者**另行明確授權**後，才可用本地隔離相容 Server 測實際原版 Client 的命名成功、非1錯誤/重名、取消、角色清單0/1、斷線重登、創角畫面與選角可達性。合成測試只能證 synthetic compatibility，不能冒稱官方 Server 行為。**此次沒有執行或連線原版 Client**。

### RR-0010 正式狀態處置

最新核對 `main` 基準 `412a2374a7c6c56de8ab881bcac8c9caa8aaac5c`，`research/requests/index.json` 的 RR-0010 為 `BLOCKED`、claim `extra/roy1`，其 acceptance 仍要求「建角色 request→result→roster」與真正錯誤/斷線相依。E73 已找到可本地證明的名稱建立 Client C2S/S2C/result/UI 重大新鏈，**不能繼續以『找不到名稱建立 producer』當唯一阻塞理由**。但原版 Server request–response pairing、角色 roster 因果及該 RR「character vs expedition」定義未完全達標，故**在 S00 重新審閱前，保留 RR-0010 `BLOCKED`／`GAP-CHAR-0003 OPEN`，不強行轉正式 `SUBMITTED/ACCEPTED`，不宣稱整體角色建立契約已完成**。向 S00 的建議：檢查是否須把此 RR 的實際目標修訂為「Expedition identity create」，或者另開限定研究請求研究 playable-character unlock／roster，保留原始審查事件及現有 owner 界線；由 S00 依程序 requeue/審核，不自行改歷史。

## 8. 可重現原生驗證、局限與來源

完整測試在未修改原件下通過：

```bash
sha256sum Tartaros.bin Tartaros.exe
python -B kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-verify.py /path/to/Tartaros.bin
# 可選：抽取原始 .text 後 disassemble（raw=0x400, size=0x7D0200）
dd if=Tartaros.bin of=kr-text.bin bs=1 skip=$((0x400)) count=$((0x7d0200))
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x672180 --stop-address=0x67256a kr-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4c14b6 --stop-address=0x4c14f5 kr-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4c21d0 --stop-address=0x4c21ed kr-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x5a67d0 --stop-address=0x5a68c4 kr-text.bin
```

原始 Native verifier 逐項核對 `vptr[87]`、`F4244`、ASCII+wide validator、`0x81EB80` 四個 direct call、opcode及 21WCHAR 送出／48B slot0、`0x4A` scene table、signed result `+2`、`F4245`、`5A6886` jump table、`672570` outcome、`F938F2` 保存、`0x0033` 與本 request 的反例，**共 58 項 source-based byte/assertion**。不包括完整 CFG 穷舉、original Server trace、真機 Client 測試或 T01 FULL-PASS；對未直接驗證的非本目標函式保持未知。

**此前原稿（不覆寫）：** `kr-extra-roy/20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md`（Git blob `57f809809e28d24cd9779549d95e9b269db4870b`）；`kr-extra-roy/20261031-chatgpt-web-roy-E72-RR0010-create-secondary-dispatch-roster-native-followup.md`（Git blob `7f1907f8fa0877c9fcd905eba048ec7f3e52cb9c`）。本 E73 是**新增正向證據與限定勘誤**，不覆蓋先前原稿或代表 T01 對前文已給出 FULL-PASS。
