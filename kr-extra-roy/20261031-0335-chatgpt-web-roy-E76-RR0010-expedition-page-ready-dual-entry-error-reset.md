# E76 — RR-0010 KR Expedition 建名／角色清單：共同名稱 → Page ready／三項 UI 控制、失敗復原與 `F4261` 誤配反證

> **2026-10-31 03:35 Asia/Taipei｜chatgpt-web roy｜研究分支 `extra/roy1`｜只讀 KR BIN-first 靜態研究**。承接同分支 E71、E72、E73、E74（本件不覆寫前稿）。本次原始 `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe`：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。PE32 x86 ImageBase `00400000`，`.text` VA `00401000` raw `00000400` raw-size `007D0200`，`.rdata` VA `00BD2000` raw `007D0600`。函式位址依原始 PE sections 轉換，禁止將 `.text` 差額套到 RTTI。**未執行、修改或連線 Client；未取得原版 Server 封包。** E76 可重現靜態檢查器 `kr-extra-roy/20261031-0335-chatgpt-web-roy-E76-RR0010-verify.py`：**58 項 PASS**，不等於 T01 FULL-PASS、Client runtime 或官方 Server 實測。

## 0. 目標、查核基準與新結論

2026-10-31 03:32 左右先查 `main` `bf1e15ebcb19c272106627303ab27ecc0b2b3514`，`extra/roy1` `76ee900f0cc5f9157809620d84607986a36f23a1`，正式 `research/requests/index.json`：`RR-0010` 仍 `BLOCKED`，actor=`chatgpt-web roy`，claim branch=`extra/roy1`；其目標是 C2S 建立、真正 S2C 正負 outcome、建後 roster/init、錯誤／重試，**不是只定位有名字的 UI 類別**。本次使用者明確指定 RR-0010，故暫緩與 RR 無關的 T03 `T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX`。沒有更動其它 RR owner、main、SPEC 或正式狀態。歷史 E73／E74： `CExpeditionCreateDialog → C2S app 0x003E(48B, slot0, name+6)`；LOGIN scene `S2C app0x004A→ signed WORD payload+2 → local F4245`；成功 status1 將寬字元名稱複製到全域 `F938F2`；`S2C app2` 另一個 handler 在名單前把 header `payload+0x0C` 的 20 WCHAR 複製到**同一** `F938F2`，然後 53B/N row、每 row `C2S0x26`、結束 `C2S0x24`。**仍未有官方 `0x3E→0x4A→app2` 時序證據**。

E76 補上的**可證且更接近目標的本地交會**：

1. 原生 RTTI **`CExpeditionPage@FUI@@`** vptr `C1C1A4` 的 virtual slot92 是 `005A6510`。此處直接掃描全域 `F938F2` 的 UTF-16 名稱；**非空即寫同一頁面 `this+0x144=1`**，空字串只略過設值。這是 **app2 header name→登入頁/選角頁 ready** 的條件式 Client-local data dependency（假定 app2 已處理、page 初始化時沒有被另一 writer 重設）。
2. **同一頁面** vtable slot66 `005A65A0` 構造及更新 UI；`005A665F` 檢查 `this+0x144`，為 0 走三組控制 `virtual+0x94(0)`，非 0 則走三組 `virtual+0x94(1)`。這是已確認的**名稱存在／成功就緒旗標→三個 UI 控制狀態**，不是原版連線下 GUI 可見性或角色資料合法性的保證。
3. 同一頁面 vtable slot101 `005A67D0` 接收 local `F4245`：結果為 `1` 時 `005A6895→00672570` 儲存文字，`005A68AA→005F4910` 對三組 UI 控制使用 `virtual+0x94(1)`，`005A68B5→005F4950` 顯示 `F938F2`，並於 `005A68BA` **設 `page+0x144=1`**。status 非1於 `005A689E` 跳離，不會執行這組成功-only ready 操作。
4. `00672570` 對 `-1/-2/-3/default` 有不同失敗提示，部分負結果共用 `00672790..006727A4` 將 name-edit 控制 `+0x168,+0x160,+0x164,+0x14C` 清0，最後於 `006728D6..E2` 呼叫 dialog `virtual+0x90(1)`；**可證錯誤提示與本地重輸入準備，不能聲稱自動網路重試、Server 重名業務 enum 或已完成斷線復原**。
5. 另證先前 E75 記載的 `F4261` 不是 Expedition Page 的專用 ready event：頁面 `005A67D0` 的 jump map 對 `F4261-F4245=0x1C` 對應 **default (`005A6973`)**，而 `F4245` index0 對應 `005A6886`。`F4261` 的另一個 virtual getter `005DE800` 實際位於獨立 RTTI **`CItemSlotShopDismantle1@FUI@@`** 的 vtable slot2。這是**事件代號跨功能重用的反證**；不能拿 `S2C0x26→F4261` 推論 Expedition page 自動解鎖，也不能排除別的事件 subscriber。

**結論：E76 關閉了之前只知 `F938F2` 共同 writer、不知 GUI 如何消費的 Client-local 分支；仍未閉合原版 Server request→reply→roster 的交易時序。** 這是有實質進展的 RR-0010 補證，非原稿填充，也不可據此寫 `ACCEPTED`。

## 1. 原生 RTTI／vtable 的精確 owner 身分

`CExpeditionPage` 的 COL 在 vptr 前一 DWORD：`[C1C1A0]=C6EF78`；該 COL `+0x0C` 的 MSVC TypeDescriptor 之 `+8` 為原件內 ASCII **`.?AVCExpeditionPage@FUI@@`**。`005A6486: C7 06 A4 C1 C1 00`（destructor/install path）再次直接寫此 vptr；函式指標在該表之實際 offset：

| vtable cell | slot | native function | 本次限定作用 |
|---|---:|---|---|
| `C1C2AC` | 66（`+0x108`） | `005A65A0` | Expedition Page 的控制建立／顯示更新，含 `+0x144` gate |
| `C1C314` | 92（`+0x170`） | `005A6510` | 從 global UTF-16 name 決定 page ready 旗標 |
| `C1C338` | 101（`+0x194`） | `005A67D0` | 具有限定 switch table 的 local event handler，包含 `F4245` |

這三者**同屬一個 CExpeditionPage vtable**，不是根據命名將不同類別拼接。`CExpeditionCreateDialog` 是**另一個** RTTI/vptr `C35784`；`CEmployNewCharacter` 又是 `C3F024`，其發送 `0x0033` 2B（E71）不可偷換成有名稱的 `0x003E`。

### 1.1 `005A6510` 對 roster header name 的本地 ready 判斷

```asm
5A6566 B8 F2 38 F9 00      mov eax,0F938F2h         ; shared Expedition name
5A656B 8D 50 02            lea edx,[eax+2]
5A6570 66 8B 08            mov cx,word[eax]
5A6573 83 C0 02            add eax,2
5A6576 66 85 C9            test cx,cx
5A6579 75 F5               jne 5A6570
5A657B 2B C2               sub eax,edx
5A657D D1 F8               sar eax,1                  ; UTF-16 non-NUL length
5A657F 74 0A               je 5A658B                 ; empty: no write here
5A6581 C7 86 44 01 00 00 01 00 00 00
                            mov dword[esi+144h],1
```

先前已驗 `S2C app2` `004B8075–004B8082`：從 `payload+0x0C` 以最大20 WCHAR/目的21 WCHAR 寫 `F938F2`。`004B8082 call 893FFE`；因這個共享全域是 **page 旗標的正向讀取來源**，可得到**在頁面此初始化方法執行時**，若 app2 已先寫入非空名稱，則設 `+0x144=1`。不能反推 S00/Server 一定先送 app2 或空 header 會把已設定旗標清零；此函式的 empty branch 沒有明確 `page+144=0` writer。

### 1.2 `005A65A0` 的 UI gate：三組明確控制，非網路握手

```asm
5A665F 83 BB 44 01 00 00 00  cmp dword[ebx+144h],0
5A6666 75 52                  jne 5A66BA
; not ready: use UI virtual+94h with arg0
5A667D mov ecx,[esi+0B0h]      ; child control #1
5A668B 6A 00                    push 0
5A6695 ...                     ; child control #2 at +B4
5A669D 6A 00                    push 0
5A66A1 ...                     ; child control #3 at +B8
5A66AF 6A 00                    push 0
5A66B3 E8 F8 FD FF FF          call 5A64B0
5A66B8 EB 3C                  jmp 5A66F6
; ready: use same three UI vtable+94h with arg1
5A66BA 8B B3 34 01 00 00      mov esi,[ebx+134h]
5A66CE 6A 01                    push 1
5A66E0 6A 01                    push 1
5A66F2 6A 01                    push 1
```

`+0x134` 是一個已建的子頁/控件 owner；三個 child control pointers 位於該子物件 `+0xB0/+0xB4/+0xB8`。此表只確認虛函式 arg0/arg1 對同控制的分支，不必推測這個 virtual 具體「enabled」還是「visible」，直到 UI vtable callee/資源被定向驗證；因此保守稱 **UI 狀態切換**。`5A64B0` 是不就緒分支的後續 helper，不是 app2 packet sender。

## 2. `S2C 0x4A` status→page ready 的成功分支與負向條件

`004C14E1` 在 LOGIN scene 次級 handler table index `0x4A` 註冊 `004C21D0`，其 `004C21D6 movsx ecx,word[payload+2]` → `004C21DB push F4245` → `004C21E0 call 58AB80` 產生**本地**事件。E74 已證 event 結構 `+0x10=F4245`、`+0x14=signed_result`。在上述 page vslot101 `005A67D0` 的本地 switch：

```asm
5A680E add eax,0FFF0BDBBh  ; event code - F4245
5A6813 cmp eax,33h          ; only delta<=0x33 mapped
5A681C movzx eax,byte [eax+005A69A0h]
5A6823 jmp dword [eax*4+005A6988h]
; event F4245 -> jump index0 -> 5A6886
5A6886 call 40AFC0h
5A688B mov ecx,[edi+140h]   ; Expedition Create dialog owner
5A6895 call 672570h         ; result handler
5A689A cmp dword[ebx+14h],1
5A689E jne 5A6973          ; no success ready for other status
5A68AA call 5F4910h         ; 3 UI control arg1
5A68B5 call 5F4950h         ; display F938F2
5A68BA mov dword[edi+144h],1
```

因此能證**兩條不同 Client-local 寫入來源（`app2` name preload、成功 status1）以同一 global-name / page flag 匯入 UI**；但仍是兩個獨立 incoming app handler 的 data state，沒有直接 Server wire 因果，亦無從此直接跳至 `app2` handler 或呼叫 `C2S 0x42` 選角。

### 2.1 名稱失敗結果及復原，只宣告有指令證據的部分

`00672570` 由 `005A6895` call；在 `006725AA` 比較 signed event status `1`，成功才調 `893FFE` 寫 `F938F2`、dialog virtual `+0xD4`。失敗 `-1` at `0067264D`、`-2` at `006727AF`、`-3` at `00672817`、其餘 default at `0067285B`。其失敗文案路徑用本地 `5854B0` resource IDs 與 `58B270` 顯示提示，不可因某字串推定官方 DB 決策。 `-1/-2` 的已查分支匯入 `00672755..006727AA`：

```asm
672790 33 C0                xor eax,eax
672792 89 87 68 01 00 00    mov [edi+168h],eax
672798 89 87 60 01 00 00    mov [edi+160h],eax
67279E 89 87 64 01 00 00    mov [edi+164h],eax
6727A4 89 87 4C 01 00 00    mov [edi+14Ch],eax
6727AA E9 27 01 00 00       jmp 6728D6
6728D6 8B 13                mov edx,[ebx]
6728D8 8B 82 90 00 00 00    mov eax,[edx+90h]
6728DE 6A 01                push 1
6728E2 FF D0                call eax
```

`-2` 在 `672812` 跳至 `672755`，再進共同 edit-state reset。`-3`/default 另走 `672898..6728D6` 的提示/終結分支，不應在無證下宣稱其與 `-1/-2` 具有相同 edit reset。對網路層沒有重試 timer / 舊 request replay / S2C callback retry 正向證據；只能稱可供再次操作的本地錯誤處理，**不能宣稱 Server 重名、永久停權、角色名滿額、斷線等既定映射**。

## 3. `S2C 0x26 → F4261` 的嚴格負向界線（承接 E75）

`CGameInfo` 的二層 handler `004DE020` 於 `004DE0DD push F4261`、`004DE0E2 call 58AAD0` 投遞本地 event（E75 證實是 4+5N record consumer）；不能從此推「必然打開建角/選角」。這次反查 Expedition Page event table 原始 52-byte map `005A69A0..005A69D3`：index0=`0`、index `0x1C`=`5`、index `0x33`=`4`；jump table `005A6988` slot0=`005A6886` (F4245)、slot4=`005A68D8`、slot5=`005A6973`（common return）。因 `F4261−F4245=0x1C`，**當 F4261 投遞到這個 CExpeditionPage 事件方法時，只走其 default return，並不調 `00672570` 或 ready update**。這是 *這個 page 接收者* 的陰性證據，不否定 `F4261` 可能存在其他本地訂閱者。

再從 `.rdata` `C252B0` COL、`+0x0C` TypeDescriptor 驗出 `.?AVCItemSlotShopDismantle1@FUI@@`，該 vtable `C252B4` slot2=`005DE800`，其 body `005DE800: B8 61 42 0F 00` 只是回傳**同一 F4261** 事件常量。證明 `F4261` *跨功能使用*；不可把代號相同寫成「角色初始化 ack」。

## 4. 已證、未知、失敗與 Server 契約矩陣

| 玩家／Client 情境 | 本次有原件來源的結果 | 未證、不能外推 |
|---|---|---|
| `CExpeditionPage` 初始化時 `F938F2` 有非空名稱 | `5A6510`: UTF16 長度非0 → `page+144=1`；`5A65A0` 可把三個控件切到 `virtual+94(1)` | 不證該名稱何時由 Server 產生、UI 已顯示、能選既有角色 |
| 同方法遇空名稱 | `5A657F` 跳過本方法對 `page+144` 的設值 | 不證所有路徑把 ready flag 清0；初值另取 ctor 前提 |
| 建立名稱被本地 scene 回覆傳入 status1 | `4C21D0→F4245→5A6886→672570→F938F2`；`5A68AA/B5/BA` 更新控件、名稱與 ready | 不證官方 `C2S3E→S2C4A` 一定配對、Server 已存檔或已下發角色清單 |
| status-1、-2、-3、default | 各有條件式 GUI 提示；-1/-2 部分分支清 edit state 並回 dialog virtual+90 | 不證錯誤枚舉的官方業務意義、Server 重送／取消／斷線幂等性 |
| 已有 app2 roster `65+53N` | E74 由 header 名稱共同寫 `F938F2`，row/slot writer 及依賴 C2S0x26/0x24；E76 page 讀共同名稱且切三控件 | app2 必然是建名後第一回覆、每個角色都能選、`0x42` 成功/進世界 |
| 收到同場景 S2C26、發本地 F4261 | E75 二層 CGameInfo handler +5B record；E76 證 F4261 在 Expedition Page 本地表落 default | 不能把 F4261 當成此 page 正向就緒信號；別的 subscriber 未排除 |

### RR-0010 正式 acceptance 逐項更新

1. **Build、位址、欄位、方向**：E73 C2S3E 48B，slot0，+0..1 opcode，+6..47 bounded UTF16 copy，+2..5 UNKNOWN；E74 app2+0x0C 名稱，E76 同版 Page RTTI/flag/status UI 完成限定者。外層 TCP frame、原版 Conn 串接仍須 T02 邊界，不能自行貼合。
2. **正向 request→result→roster、錯誤/重試**：已證彼此相容的本地入口／結果／UI/roster 共享名稱與條件式 ready；**原版 Server `0x3E→0x4A→app2` 真實 transaction 配對與角色創建後 roster/init 順序仍 UNKNOWN**；錯誤 -1/-2/-3 的本地不同復原已查，但無官方 duplicate/disconnect semantics。
3. **Client vs Server**：`F4244/F4245/F4261` 屬 local event，不是 wire；`0x33` Employ、`0x42` select-existing 與 `0x3E` Expedition name 區分；不得將 Server 命名唯一性、持久化、帳號策略當 native Client 失敗原因。
4. **其它 RR**：只引用 RR-0002、RR-0007、RR-0008 及 E75，不修改其狀態或 owner，亦不偽稱 RR-0009 的 N=0→create dialog GUI 正向入口已閉合。
5. **交付**：E76 本報告、58-byte/RTTI/branch checks script、完整不同方向/反例/四類未知及解除條件。本報告 Git blob SHA 必須以實際 Push 後回讀為準。**正式 `BLOCKED → QUEUED` 需 S00 重新確認；只有 S00 能將經審查的 RR 記為 `ACCEPTED`。**

## 5. 依新版 02 分流，向 S00 的可直接收件資料

- **Client 待逆向（T03）：** 找到 `CExpeditionPage` 的名稱狀態、ready flag、成功結果與三控件狀態；下一步可查同版 `CExpeditionPage` 頁面建立前提／`S2C app2` 觸發順序及命名與 playable character 的差別；未識別的 `0x3E+2..5`、場景/Conn gate、真正 create-result→roster/世界初始化、失敗後 `0x42`選角成功等，不能拿 Server-only 未知取代。
- **Server 待開發 → S00，`CODE_ANALYSIS` 候選：** 需要獨立於既有「角色招募」的「遠征隊／玩家身分名稱建立或載入」REQ 去重審查；可交付 bounded 介面 `C2S0x3E(48B, name UTF16+6, unknown+2..5)`, candidate `S2C0x4A(signed16+2)`, `app2` 的 header-name+0x0C 及 53B rows/後續 `0x26/0x24`，再加本輪 `F938F2→page+144→三個控件`；協定真正交易配對不明，不能寫成官方 MUST。名稱唯一性、保留字、權威、持久化、登出/重登冪等、錯誤策略是 Server ADR/TEST 待決策；不應阻止仍可研究的 Client 靜態路徑。
- **跨功能待整合：** T02 framing/slot、T04 招募預製角色/初始資料、T06 UI 實際 layout、T03 Expedition Page/Role roster、S00 `REQ/SPEC/GAP/ADR/TEST`；原先 `GAP-CHAR-0003 OPEN` 與 `SPEC-CHAR-0001/SPEC-FLOW-0001 DRAFT/PARTIAL` 不因發現 page flag 而自動關閉。
- **待遊玩驗證：** 只有使用者另行授權的隔離原版 Client↔自製相容 Server 測試可測頁面出現/角色可選、失敗輸入復原與 app2 時序；那也不等於已捕捉原版官方 Server 的歷史行為。

**具體解除 RR 核心阻塞需要任一可靠路線：** (A) 同版原始 Server handler/source 或合法、同版、多 Conn 成功及失敗的真實 trace，錨定 `0x3E` 與 `0x4A`、app2 時序/角色 record；(B) Client 原生其他明確狀態 writer/事件/資料依賴把建立結果正向連上 roster 更新（超過此篇的 shared name/ready flag）；(C) S00 正式依既有 acceptance 第5條審閱有限原生結果、重設 RR 可證範圍或拆分 Expedition identity 建立與 playable-character recruit，保留未證項與歷史事件。不得因原版 Server 資料庫演算法未知就停止還能查的 Client 證據。

## 6. 可重現性與審核界線

```bash
sha256sum Tartaros.bin Tartaros.exe
python -B kr-extra-roy/20261031-0335-chatgpt-web-roy-E76-RR0010-verify.py /path/to/Tartaros.bin
# 原始 .text（raw 0x400 長度 0x7D0200）抽取後：
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x5a6510 --stop-address=0x5a659c extracted-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x5a65a0 --stop-address=0x5a671f extracted-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x5a67d0 --stop-address=0x5a6987 extracted-text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x672570 --stop-address=0x672900 extracted-text.bin
```

Checker 從原始 PE sections 直接讀 x86 機器碼，驗證 page RTTI/type descriptor、3 個 vtable 槽、名稱 NUL 計數及非空分支、UI 3 控件的 `arg0/arg1`、local result status 1、錯誤復原欄位、共享 `F938F2` 兩種寫入、`F4261` page jump map、商店拆解 UI 類型反例，共 **58 項正/負斷言 PASS**。程式完整與本報告並列保存，不需修改原版 BIN；**靜態自我驗證不代表真正官方 Server request/reply、實際使用者畫面或 T01 全文通過**。

### 既存原稿（不複寫）

- E71：`kr-extra-roy/20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md`
- E72：`kr-extra-roy/20261031-chatgpt-web-roy-E72-RR0010-create-secondary-dispatch-roster-native-followup.md`
- E73：`kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-expedition-name-create-C2S3E-S2C4A-native-chain.md`
- E74：`kr-extra-roy/20261031-0244-chatgpt-web-roy-E74-RR0010-expedition-name-roster-shared-state.md`
- E75：`kr-extra-roy/20261031-0305-chatgpt-web-roy-E75-RR0002-roster-0x26-two-layer-gameinfo-handler-native.md`（只引用 `S2C0x26` 限定結果，不改它的主責）。
