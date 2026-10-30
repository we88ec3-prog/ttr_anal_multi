# E77 — RR-0010：S2C `0x00B6` → local `F4278` → Expedition role-record UI；`EXPD` 場景與建名結果的嚴格界線

> **2026-10-31 Asia/Taipei｜chatgpt-web roy｜工作分支 `extra/roy1`｜KR 原始 BIN 唯讀分析。** 本稿延續 E71–E74／E76（不覆寫舊原稿）；研究者沒有原始官方 Server 封包、沒有執行／修改 Client、沒有接收原版 Server 的真實網路交易。`RR-0010` 在開工時 `main=bf1e15ebcb19c272106627303ab27ecc0b2b3514` 的唯一台帳仍為 `BLOCKED`，claim actor=`chatgpt-web roy`、branch=`extra/roy1`。本次使用者明確要求繼續 RR-0010 並推送，因此將既有 T03 的 `T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX` 留給原 T03/T01 退回流程，不擅自標為已修復或取代其他 RR owner。
>
> 原件：`Tartaros.bin` **12,472,320 bytes**，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` **2,594,816 bytes**，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本輪從實際上傳的檔案重算。PE32/x86 ImageBase `00400000`，`.text` VA `00401000`，raw `00000400`，size `007D0200`；本篇 code VA 用 raw=`VA-00400C00`，其他 section 依 PE 表分別轉換。E77 驗證器 `kr-extra-roy/20261031-chatgpt-web-roy-E77-RR0010-verify.py` **69 項原始 byte／pointer／branch／direct-call assertions PASS**；不是 T01 FULL-PASS、Client 實際顯示、或原版 Server 時序證明。

## 0. 前稿與本輪定位

已知 E73/E74/E76：`CExpeditionCreateDialog`（RTTI）經 UI confirm／名稱檢查至 `00672505..0067253C` 形成 **C2S app `0x003E` 48-byte payload，slot0，opcode+0、UTF-16LE 名稱+6、+2..+5 UNKNOWN**；`EXPD` scene 的 `S2C app0x004A` handler `004C21D0` 讀 signed WORD `payload+2` 並投遞 **local `F4245`**；`F4245` status1 在 `005A6886→00672570` 更新 `F938F2` 名稱，最後 `page+0x144=1`；status 非1不執行相同 ready 分支。`S2C app0x0002` 是獨立的 65B prefix+53N roster consumer，從 header+0x0C 複製 Expedition 名稱至同一 `F938F2`，row `004D4150` 把 `record+0x5C=1`；其後可產生每 row `C2S0x0026` 和 post `C2S0x0024`，不能把它們當成建名 wire ACK。

**本次填補的是另一條以前只看到「F4278 是 local event」但沒有正向跨 domain 來源的路徑：base scene `S2C0x00B6` 的正確 table registration → native handler 產生 local `F4278` → 若 Expedition Page 的事件訂閱與結果前提滿足，選取已存在角色 record＋正反 UI 路徑。** 這是 Server 對 Client 可達的**有界角色畫面更新候選**，不是 `C2S0x003E` 的已證回覆，也不是新角色被 DB 建立的證據。

### 摘要矩陣

| 所在層 | 原件位址／值 | 精確確認 | 禁止外推 |
|---|---|---|---|
| S2C base scene | `004AE11D` `eax+0x5B4` → `004B5DD0` | app index `(0x5B4−4)/8=0xB6` 對應真正 handler | 不能推定 Server 必定發 appB6 |
| 不同 S2C handler | `004AE12D` `eax+0x5BC` → `004B5E50` | index `0xB7`，payload+2 byte／payload+3 float 路徑，**與 B6 不同** | 不是 B6 的 `+1 ACK`／角色建立狀態 |
| B6 incoming consumer | `004B5DD0..004B5E46` | `push 0; push F4278; call 58AB80` 後 return0；該 handler 不取用業務 payload 欄位 | 非官方「選角／建角成功 code」；需要正常 scene/table/lane 分派 |
| local event routing | `005A67D0`、`005A680E`、`005A69A0`、`005A6988` | `(F4278−F4245)=0x33`；byte map index0x33→jump slot4→`005A68D8` | 其他訂閱者／其它來源可以使用同一事件碼 |
| Page 事件處理 | `005A68D8..005A6905` | local context result `[event+0x14]` 必須為0；以 `page+0x138` owner、`ECX=0` 呼叫 `00672F00`，並繼續本地控制/UI 路徑 | `event status 0` 不等於原版 Server 結果碼0 |
| 角色索引／紀錄 | `00672F00..00672FA7` | `ECX=0` 時取 owner `+0xD8` 索引；索引 `<=9` 才用 `F94304+index*0x210`，讀 `+0x5C` 並產出條件式 record pointer | 未證 slot 授權／新角色建立／入世界 |
| 角色 UI 分岔 | `0067315E`、`006733xx`、`00673556` | 有 record pointer 走記錄填入與控制更新；NULL 走 `00673556→00673790` 的另一套 role placeholder/UI 分支 | NULL UI 處理不等於自動呼叫 Create `0x003E`，也不等於 Server 已拒絕 |
| EXPD scene 本地門檻 | `004C14BE`、`005A64E9` | scene ctor 設 `D6A674='EXPD'`；Page `005A64B0` 在特定本地初始化路徑比對同一標記與 `FD8BA4` 非空 | 同一場景字串不是原版交易時間先後 |

## 1. **`0xB6`／`0xB7` 不是建名 `0x3E/0x4A` 的 +1 回覆**

`004ADD50` 的 base scene handler table 以 stride8 配置、handler 位移 `4+8×command`（E61/E68 已確定 `0x42→+0x214`）。本輪從原件看到兩條**直接表槽覆寫**：

```asm
4AE11D  C7 80 B4 05 00 00 D0 5D 4B 00  ; [eax+0x5B4]=004B5DD0, index 0xB6
4AE12D  C7 80 BC 05 00 00 50 5E 4B 00  ; [eax+0x5BC]=004B5E50, index 0xB7
```

`004B5DD0` 的唯一可見業務副作用，是在必要的本地 lazy init 後：

```asm
4B5E25  6A 00                 push 0              ; local event result
4B5E27  68 78 42 0F 00        push 0F4278h        ; local event code
4B5E2C  E8 4F 4D 0D 00        call 0058AB80
4B5E34  33 C0                 xor eax,eax
4B5E44  C2 0C 00              ret 0Ch
```

該入口 **沒有從 `[ebp+8]` payload 取業務資料**，故只能證有界 local event0，不能要求 Server 另外塞「建角成功角色索引」在 B6 的某個未證 offset。`0xB7` 的 handler `004B5E50` 卻讀 `payload+2` byte、`payload+3` float，經另一處理器寫其他資料；B6/B7 **不是同義回應**。只憑 opcode 相鄰配對會錯誤。

分派前提：decoded app message 經 T02 確認的 channel/scene route 到有效 base scene table 時，才有上述 handler；沒有這個前提不能宣稱任何收到 `B6` 的原始 TCP frame 均必然進此方法。

## 2. `F4278` 是**本地事件**，對應 `CExpeditionPage` 的 slot4

`CExpeditionPage@FUI@@` 的 vtable `C1C1A4` slot101=`005A67D0`（E76 已定向證明 RTTI）。本次依原始指令與兩張 table 重新計算：

```asm
5A680E  add eax,FFF0BDBBh    ; event_code − F4245
5A6813  cmp eax,33h          ; supported delta up to 0x33
5A681C  movzx eax,byte [eax+5A69A0h]
5A6823  jmp dword [eax*4+5A6988h]
```

`F4278−F4245=0x33`；原始 `[005A69A0+0x33]=4`、`[005A6988+4*4]=005A68D8`。作為對照，`F4245`（建名結果）map index0→`005A6886`；default slot5→`005A6973`。**所以 F4278 確實有 Expedition Page 可進的獨立事件分支，不是 E76 所述 `F4261` 的 default。** 另一函式 `0060B200` 會回傳 `F4278` 事件常量，也代表 local event ID 不專屬 `0xB6`，故不能逆推「看到 F4278 必是收到 S2C B6」。

該 switch 的 `F4278` case：

```asm
5A68D8  call 0040AFC0          ; local event context
5A68DD  cmp dword [eax+14h],0 ; only zero branch continues
5A68E7  mov edx,[edi+138h]    ; ExpeditionPage child owner
5A68ED  push edx
5A68EE  xor ecx,ecx           ; caller selects stored-index fallback
5A68F0  call 00672F00
5A68F5  mov ecx,[edi+13Ch]   ; separate UI child
5A6903  call edx             ; child virtual +D4
```

後面 `5A6905..5A6957` 建立本地提示/UI 資料，**不是網路 send**。event result 非0在 `5A68E1` 跳到共同 return `5A6973`，不執行上述角色 UI 路徑。這個 `0` 是 **local `58AB80` 的事件參數**；不能與 `S2C0x4A` 的 signed status `1`（成功）混淆。

## 3. **`00672F00` 的精確角色紀錄來源、null 與非 null 分支**

注意呼叫慣例：`5A68ED` push 的是 **Page+0x138 指向的 child owner**，同時把 `ECX` 清零；在 `00672F00` 才把那個 child owner 設為 `EBX`，由 `ECX==0` 選擇 `EBX+0xD8` 保存的角色索引。不是直接拿 Page+0x138 這個位址當角色 ID。

```asm
672F37  mov ebx,[ebp+8]          ; child owner
672F3E  mov [esp+18h],esi        ; esi = incoming ECX (0)
672F42  cmp esi,edi             ; edi=0
672F46  mov eax,[ebx+0D8h]      ; since ECX==0, index from child+0xD8
672F80  cmp esi,9
672F83  ja  6730?                ; invalid -> pointer 0
672F85  mov ecx,[0F94304h]     ; roster records base
672F8B  imul esi,esi,210h       ; 0x210 bytes each
672F91  mov eax,[ecx+esi+5Ch]   ; local record usable flag
672F95  add ecx,esi
672F97  neg eax; sbb eax,eax; and eax,ecx
672F9D  mov [esp+1Ch],eax       ; either record pointer or null
...
67315E  test esi,esi            ; later loads saved record pointer
673160  je 00673556            ; local empty/locked record branch
...
673556  mov ecx,[esp+18h]
67355A  push ebx
67355B  call 00673790            ; fallback UI helper for missing record
```

此處與 E71/E74 的原始 role writer 有**精確資料關聯**：`S2C app2` 的每筆 53-byte row 經 `004D4150` 將 `record+0x5C=1`，而 `00672F00` 讀這個 flag 決定是否存在 usable record。role ID `<=9` 是這個 Client helper 的本地上界；沒有觀察到 Server 的權限/角色出生值。非 NULL 路徑進 `00673166` 之後的角色展示/控件更新（例如 `00673208` 取 `record+0x08`）；NULL 走 `00673556`，並委派 `00673790` 的資源字串/控制建構。後者 `006737F3..00673800` 對 index 5..9 有獨立 switch，不能把它宣稱為「Server 發出成功／拒絕訊息」。

**新增正向的 Client-local 依賴**（有條件）：

```text
S2C app0x0002: 53B row → 4D4150 → selected role record+0x5C
                                          │
S2C app0x00B6 → 4B5DD0 → local F4278(0) │
                           ↓              │
                     Page 5A68D8 ─────→ 672F00
                                          ↓
                             record exists → UI record data
                             absent/invalid → placeholder UI path 673790
```

**尚不能宣告的外部依賴**：原版 Server 一定在 `0x003E` 後送 `0x004A`、`app2`、`B6`，或原版 Server 一定為某個新角色設 flag。這四個 incoming/outgoing domain 的發送時序沒有可信 trace。event subscriber、page/live scene、角色 control 和資料有效性仍是正向路徑的先決條件。

## 4. `EXPD`：同一場景對建名結果與頁面未就緒控制的要求

`004C13E0..004C1507` 是以 base scene ctor `004ADD50` 為上游的特定場景建構鏈，於 `004C14BE` 寫 global marker `D6A674=0x45585044`（小端 bytes `44 50 58 45`，ASCII `DPXE`，作為整數/字節讀取時含對應 **`EXPD`** 四字元縮寫；本報告以來源程式意圖稱 `EXPD` tag，不能當作網路封包）。在同個 ctor `004C14E1` 寫此場景 S2C index `0x4A→004C21D0`；`004C14EB` 再寫 `index0x68→004C21F0`。這是**同一場景註冊表內兩個不同消息**；`004C21F0` 處理 byte+paired data，不等於 roster `app2`，更不等於 `0x004A` accepted/rejected result。

`005A65A0` 在 `page+0x144` 不就緒路徑，三組 child control 的 vtable+0x94(0) 後 `005A66B3 call 005A64B0`。`005A64B0` 檢查：

```asm
5A64E9 cmp dword [D6A674],45585044h ; scene marker
5A64F3 jne 5A6504                      ; wrong scene -> no call
5A64F5 mov eax,[FD8BA4]               ; globally held owner / scene pointer
5A64FA test eax,eax
5A64FC je 5A6504                       ; missing owner -> no call
5A64FE push eax
5A64FF call 004C1E10                  ; independent local setup
```

`004C1E10` 建構與傳遞一組整數／資源配置（例如 `0x3F8/0x3F9/0x2714..0x2717` 等），不是在此找到 `S2C4A→app2` 直接呼叫。這個新證據補強 **建名結果可在特定 Expedition scene handler 被消費，而 Page 不就緒狀態還有同一 scene marker 的局部啟動 gate**；它不把 scene marker 自動等同為角色建立完成/刷新，也不證 `FD8BA4` 在當時一定非 NULL。

## 5. 以 RR-0010 原始五項驗收條件檢查

| Criterion | E71–E77 累積確證 | 仍未完全達標／必須標 UNKNOWN |
|---|---|---|
| (1) KR SHA／C2S/S2C／offset/len/codepage/scene | 原件 hash；C2S3E 48B/name+6/slot0；EXPD app4A signed status+2；app2 roster 65+53N；本輪 appB6/B7 與 local event F4278 的精確表槽 | C2S3E +2..5 未初始化／來源未知；真正 framed TCP/Conn、完整例外分支、更多場景覆寫未確證 |
| (2) create request→reply→roster/init 正向依賴／異常 | 已證 UI→C2S3E，S2C4A→F4245→name/page ready，S2C2→role records，**S2CB6→F4278→role record flag→UI**（本輪新正向） | **沒有同一筆原版 Server 交易把上述 incoming/outgoing app 排成唯一必然序列**；建名與可玩角色 recruit 的身份是否相同，official duplicate/retry/斷線策略仍 UNKNOWN |
| (3) Client local vs wire | F4244/F4245/F4278 皆 local；appB6 handler 不取額外業務欄位；0x42 是既有角色選擇，不是 create ACK | 0xB6 本地 event0 不代表 Server 官方成功碼0；UI 角色資料被讀不代表 Server 已建立它 |
| (4) adjacent RR reuse | RR-0002/0007/0008 只引用其已證分派/角色/場景資訊，不改主張和台帳；RR-0009 N0 到可見 GUI 不自動套用 | 選角 S2C 真正成功配對／初登場景另外待證 |
| (5) 完整原稿、原生測試、SPEC/GAP 影響 | 本 E77、69 original-BIN assertions、反例、S00 四類移交、外部解除條件 | Git blob SHA 請以本稿實際推送後由遠端核對；正式 RR `BLOCKED → QUEUED → ... → ACCEPTED` 需 S00 依台帳審核，不能由研究者跳狀態 |

**結論：**這是對 RR-0010 核心功能鏈有實質推進的一個新 native subchain。建名成功分支不再只有 F938F2/page ready，還找到**另外一種 S2C 指令能經 local event 觸及 roster ready record 的 UI**；但**本輪沒有原版 Server 序列／建立新 playable character 的唯一肯定配對**，故不得聲稱 RR-0010 `ACCEPTED`、SPEC STABLE、GAP RESOLVED 或可遊玩；也不能因原版 Server 內部決策未知，停止剩餘 Client 可證部分。

## 6. 四類移交與可操作解除條件

- **Client 待逆向（T03）**：追 `004AE11D` base B6 註冊在不同 active scene 下的可達性及其它 overwrite；`F4278` 的產生／訂閱者先後、角色 index `child+0xD8` 的上游 writer、`00673790` 缺角色 GUI 資源與 `CEmployNewCharacter 0x33` 的實際上游；證明／否定 `0x003E` 與 `0x004A` 後是否透過任何 native state writer 自動觸發 `S2C0xB6` 或重取 roster。未查證的 indirect/virtual caller 不可因沒有 direct E8 宣稱全域不存在。
- **Server 待開發（S00 正式收件；沿用既有 REQ 去重）**：可就地登錄有界 Client 相容需求：可在必要場景下消費 `S2C0x00B6` 這種不讀附加業務欄位的本地 UI 事件入口；名單仍需 app2 的合理長度與欄位（65+53N，UTF-16 名稱有有效 NUL），原版名稱、名單／角色權威、持久化、角色缺席與失敗/重複提交由相容 Server 的 ADR/TEST 決策。**S00 尚不得批准 `0x3E→0x4A→app2→B6` 為官方 MUST sequence**，需在 DRAFT 表中明示條件和 unknown。現有 `REQ-0003`/`REQ-0004` 角色清單與 UI 就緒可先評估追加 CODE_ANALYSIS discovery；建遠征隊姓名若交付獨立，評估另立候選 REQ，勿複製同義需求。
- **跨功能待整合**：T02 frame/key/scene dispatch、T03 角色 UI、T04 playable-character／招募與初值、T06 GUI layout/resources、S00 `SPEC-CHAR-0001`/`SPEC-FLOW-0001`、`GAP-CHAR-0003`；不更動其它主責研究原稿。
- **待遊玩驗證**：只有原版 Client/測試 Server 的實際事件與 wire 捕捉（另須明確授權），才可驗證 `app2`、`B6`、角色資料/UI、失敗重登是否產生預期畫面；synthetic traffic 不等於官方原始 Server 時序。

**精確解除證據**：A. 相同 KR build 的可信原版 Server 完整 multi-Conn create 成功/失敗/duplicate/disconnect trace（含 app0x3E、0x4A、0x2、0xB6 是否真正相鄰）；B. verified original Server source；C. 由 Client original BIN 另找到同一筆建名結果至 roster refresh/b6 dispatch 的 producer/state-writer 與可達 guard（若不存在需有完整 xref/CFG 陰性範圍）；D. S00 在保留歷史 RR 的前提下，正式將「遠征隊身分命名」與「操作角色取得／招募」拆成兩個實際可驗收的問題，原本 RR 的範圍變更不可由研究者自行決定。沒有 A/B 時仍繼續 C 可做的靜態查證，不能用「原版 Server 不可得」單獨結束工作。

## 7. 重現、來源與反例

```bash
sha256sum Tartaros.bin Tartaros.exe
python -B kr-extra-roy/20261031-chatgpt-web-roy-E77-RR0010-verify.py Tartaros.bin
# .text 可由原件 raw offset 0x400，size 0x7D0200 抽出，再使用：
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4AE11D --stop-address=0x4AE140 text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4B5DD0 --stop-address=0x4B5F10 text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x5A67D0 --stop-address=0x5A6988 text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x672F00 --stop-address=0x673790 text.bin
```

69 項檢查包含 PE section、SHA、兩條 scene table registration、`0xB6` handler payload-independent/local-event source、B7 反例、F4278 switch byte/jump tables、status0/owner/ECX 條件、record index/stride/flag、null branch、EXPD marker/page-not-ready gate、與既有 E74 row flag 寫入。所有測試為**原始 bytes 的可重現有限斷言**，不是全函式控制流的語意驗收；不可將 69 PASS 說成 69 個遊戲功能或 Server 端測試。E71～E76 舊原稿與 blob 按原樣保留，尤其 E74/E76 的建名正向來源、已知反例應繼續引用。
