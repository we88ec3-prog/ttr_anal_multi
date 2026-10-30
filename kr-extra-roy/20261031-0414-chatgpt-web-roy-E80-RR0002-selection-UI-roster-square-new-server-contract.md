# E80 — RR-0002 KR 選角 Client 原生資料流收斂：UI 參數來源、角色記錄、Square 握手與新 Server 相容契約

> 2026-10-31 Asia/Taipei｜chatgpt-web roy｜KR T03｜認領分支 `extra/roy1`。**此篇以新相容 Server 開發需求為方向，但不偽稱已查明原版 Server 的選角 ACK/拒絕順序。** 報告中明確區分 Native 已確認、保守 Server 設計決策（非 Native）、Client 未知、待遊玩測試。
>
> **GitHub 基準**：2026-10-31 開工讀 `main=9df86e629d19b688850d5cad4dfda50691513c4e`；`research/requests/index.json` RR-0002 `BLOCKED`、T03 owner、claim branch `extra/roy1`；`t03/roy/chatgpt-web` 與此認領分支均為當時 `main` 的祖先，工作前已以安全非強制 fast-forward 同步到該 SHA，遠端 compare 驗證 t03 與 main 無差異。此輪**因使用者明確指定 RR-0002**，T03 早期 T01 `T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX` 維持原狀，不冒充已修復。`main` 正式 RR 台帳由 S00 管理，不能因報告寫完自行標成 `ACCEPTED`。
>
> **原件核對**：`/mnt/data/Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 2,594,816 bytes，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。僅離線讀取，不執行/修補/附加遊戲。PE32 x86，ImageBase `0x400000`，`.text` VA `0x401000`、raw `0x400`、size `0x7D0200`；`.rdata` VA `0xBD2000`、raw `0x7D0600`、size `0x18E200`；`.data` VA `0xD61000`、raw `0x95E800`、size `0x22B800`。只對 `.text` 使用 `raw = VA − 0x400C00`。

## 0. 整體驗收和與 E61～E79 的差異

RR-0002 正式問題是 **「Which C2S selection fields and S2C reply fields/order does original Client require? Preserve unknown values; reuse T02/T04 contracts」**；關聯 `GAP-CHAR-0001` 要求 command2 header、角色 record 權威與初始化、真正選角 request＋responses、場景轉換、source-backed tests。這份報告**不改寫正式原題**，但按使用者新的目標：不需還原原版 Server 的內部業務規則，向 S00 提供可先實作的 Client 有界協定和精確剩餘缺口。

E61～E67 已定位 C2S42 builder、三類 UI caller、app2 roster、S2C42/43 排除、S2C69/7→CSquare→C2S43。E68 證明 S2C42 不是 ScenarioReview 直接 scene writer；E75 另補 S2C26 5B record/F4261；E79（RR-0010）確認 S2C2B 2+53N 與 app2 使用同一角色 record owner。這些原稿不覆寫、不將別的 RR 子研究算成當前完成。

**本 E80 的原生新補強**：

1. **正式 class identity**：`0x5F46D0` 的 RTTI vtable base `0xC280F4`、slot87，型別 `.?AVCExpeditionScene@FUI@@`；`0x673DA0` 的 vtable base `0xC3594C`、slot87，型別 `.?AVCExpeditionDialog@FUI@@`。兩條 callback 不同 owner，不能將 UI gate 全部合併。
2. **C2S42 第一 byte 的一條正向來源**：`0x5F47A4` 讀 widget child `+0x20` 的索引，`0x5F47AC inc EAX`，存 scene+`0xC8`；`0x5F47C4 cmp <=9`、`0x5F47CD *0x210` 查 role record+`0x5C !=0`，符合時 `0x5F47F2 push 0; push selected`，`0x5F47F5 call 0x4A3B80`。因此這條 UI 分支的 index 是 **`childIndex+1`**，且存在 UI record-ready gate。**不能推導所有 UI 入口都保證此條件**。
3. **C2S42 第二 byte 的兩條正向來源及等待旗標危險**：`0x5F487C push0` 與 `0x5F48EE push2` 依不同控制按鈕送往共用 `0x5F48F0→0x5F48F7`；兩分支進入前都檢查 `scene+0xCC==0`，送出函式返回後 **`0x5F48FC mov byte [scene+0xCC],1`**。`0x4A3B80` 可以因 `FBA798!=0` 不執行 manager queue，此旗標仍可能變1，故 server-side retry/timeouts 不可假定已送出、也不能把此 flag 當 ACK。
4. **第三條 UI 入口沒有相同 flag/record gate**：`CExpeditionDialog` `0x673E8D..673EAA` 是 event `0x578`+控制 identity `dialog+0xDC`，將 `dialog+0xD8` 作第一參數、第二參數0 呼叫同一 builder，未在此 callback 明確做 role record+5C 檢查。其餘分支 `0x673DE1..673E69` 是 local `F42EF`，不是發送 C2S42；`0x673EC2` event `0x387` 會造 local `F4247`，也是本地事件。
5. **roster header 的首次讀取/role mask 合法域**：app2 `0x4B803F` 在檢查 `len>=65` 的 row count **以前**讀 `payload+2` DWORD；`0x4B8075` 從 +0x0C 讀 UTF16 名稱；`0x4B80C5/+0x38`、`0x4B8103/+0x36`、`0x4B813A/+0x3A`、`0x4B817D/+0x3C`、`0x4B81C0/+0x3D` 均有來源位址；`0x4B8923` 才計算 (len-65)/53。row ID 的正向上界 guard **只有 `ID<=9`**；`0x4B8A02` 後續 `dec ID; shl dx,cl` 的 bitmask 卻使用 `ID-1`，這讓 ID0 的 bitmask 與 UI 可能不一致。新 Server 最保守地選擇 **ID1..9**（ADR 候選，非原版 Server 完整 policy），拒絕 ID0/超界/重複。
6. **Square 的兩個資料類別與次級 C2S43**：`0x506BBE` 初始化 `FE1AA0=CSquareUserData`（`+18` 初始0、`+1C` 初始1）；`0x506C0F` 是另一個 `FE1A88=CSquareChannelState`，不可混合欄位。`S2C69 subtype7` 在 `0x4B90C1` 讀 `payload+2` 後經 `0x4B90F0` 建 `CSquare`、`0x4B90FD` 切場景、`0x4B9107` 記 local scene code7；在 `0x4B9202`/`0x4B920E` 分別讀 `payload+3/+4` 到 **ChannelState**。`CSquare` 進入回呼從 **UserData+18** 組 `C2S 43 00 XX 0A` len4/slot0（`0x4BBE66..0x4BBEAF`），不從 ChannelState+18 拿取；`0x508970` index setter 在 index<count 時也能再送 43。**無原版因果證明 S2C69 是 C2S42 的 ACK，但相容 Server 可以在 ADR 記載後用這組 Client handler 設計場景切換試驗。**

### 可以交 S00 的端到端 *候選相容 Server* 流程（不是 original Server trace）

```text
S2C app0x0002: header 65B + 53B*N role rows, valid name/record/role-index
    -> Client app2 parser/record+5C=1
    -> conditional C2S 0x0026, 0x0024 (other initialization needs may exist)
User click on ExpeditionScene/ExpeditionDialog
    -> Client local checks, may queue C2S 0x0042 [roleIndex, mode0|2] len4 slot0
    -> NEW SERVER designs authorization and success/failure policy (not original Server fact)
    -> one candidate compatibility action: valid S2C app0x0069 subtype7 plus required fields/state
    -> Client scene-manager -> CSquare::entry -> conditional C2S 0x0043 [UserData.currentIndex, 0x0A]
    -> under active CSquare scene, S2C0x0068/0x006A supply separate channel/user data
```

此候選**不能**跨越兩處未證關係：(i) 真正的 Client 拒絕/重試 UI 回覆 handler 和有限 payload；(ii) 新 Server 發出 `S2C69/7` 時資源/場景/角色上下游必然完整的執行證據。這是新 Server 應以合成相容測試實驗的假設，不是本輪聲稱通關。

## 1. 原始 C2S42 builder：4-byte、slot0、兩引數、無自行 request ID

```asm
4A3B84  cmp dword ptr [0xFBA798],0
4A3B8B  mov cl,byte ptr [EBP+8]        ; selectedIndex LOW8
4A3B8E  mov dl,byte ptr [EBP+0xC]      ; mode LOW8
4A3B91  mov eax,0x42
4A3B96  mov word ptr [EBP-4],ax
4A3B9A  mov byte ptr [EBP-2],cl
4A3B9D  mov byte ptr [EBP-1],dl
4A3BA0  jne 0x4A3BB7                  ; manager gate nonzero => no local queue
4A3BA2  mov ecx,[0xFBA854]
4A3BA8  mov eax,[ecx]
4A3BAA  mov eax,[eax+0x10]
4A3BAD  push 4                          ; local inner app body length
4A3BAF  lea edx,[EBP-4]
4A3BB2  push edx                        ; pointer
4A3BB3  push 0                          ; lane/slot0
4A3BB5  call eax                        ; queue, not proof of WSASend delivery
4A3BBA  ret 8
```

`C2S` inner bytes layout (wire frame/T02 remains separate):

| Offset | Length | 原生來源及性質 |
| --- | --- | --- |
| `0..1` | 2 | little-endian application command `0x0042` (`42 00`) |
| `2` | 1 | first argument low byte `XX`；在 ExpeditionScene 的 role click 來源為 `widgetChild+0x20+1`，需相對 0x210 record+5C 可用；另其他入口可直接使用 cache index |
| `3` | 1 | second argument low byte `YY`；已確認 UI callsite 值0與2，**此字節的業務語意由新 Server 選擇定義，不能稱作角色 ID** |

有界 UI producer：

- `CExpeditionScene` vtable base `0xC280F4` slot87=`0x5F46D0`，RTTI TypeDescriptor=`0xF8462C`；事件 `0x70A` branch `0x5F477E..0x5F47FC`（widget index+1、role available）發 `YY=0`，事件 `0x578` 的次按鈕 `scene+0xB4` 發 `YY=0`，`scene+0xB8` 發 `YY=2`。後兩條先檢查 `scene+0xCC==0`，成功走到 builder 之後設 `+0xCC=1`。
- `CExpeditionDialog` vtable base `0xC3594C` slot87=`0x673DA0`，RTTI TypeDescriptor=`0xF865C4`；`0x578` 且 control `dialog+DC` 時，`dialog+D8` index、`YY=0` 發送。其另一個 local event `F42EF` 是 UI 詳細資料事件，**不等於 C2S/S2C 回覆**。
- `0x414680` 在部分送出前被呼叫，但仍不能推得成功 ACK 的狀態。上述 UI 保護是**限定特定分支的必要條件**，不能說所有來源一律檢查 `record+5C`，也不能說每次 `scene+CC=1` 都真的把封包送上線。

**可供 Server 設計的保守解碼策略（ADR 候選）：**只接受 cmd `42 00`、長度4、role ID1..9、mode0/2；需 Session 已登入、該 ID 在此玩家可用清單、不得同時重複處理；失敗時保持 Session/scene 完整並由明確的相容 UI error path 表示。**此策略比原版 Client 在所有入口的 guard 更保守，是 Server 自訂規則，不是原始協定完整合法值枚舉。**

## 2. S2C app2 roster：當次新增 header-source 與 mask/ID 邊界

原始 `0x4B7F00` 於 `0x4B803F` 已讀 payload+2 DWORD `→F93930`；`0x4B8075..0x4B8087` 以 helper `0x893FFE` 將 payload+0x0C 的最多20 WCHAR 來源複製至全域目的 `F938F2` (目的容納21 WCHAR)。`
- `0x4B80C5`：`u16 payload+0x38→F94208`；`0x4B8103`：`u16 payload+0x36→F9420C`；`0x4B813A`：`payload+0x3A != 0→F94210`；`0x4B817D`：`payload+0x3C == 0→F94288`；`0x4B81C0`：`u32 payload+0x3D→F9428C`。位移高達 `+0x40`，所以 `len<65` 的合成 packet **不能被認為原生會安全拒絕**，因為 `0x4B8923` row count guard 在這些讀取**之後**。
- `0x4B8923 cmp len,0x41` 才處理 `(len-65)//53`；`0x4B894C` N=0 直接到 `0x4B8A20`，N>0 第i筆在 payload+`65+53*i`，index at row+`0x2E`=`payload+0x6F+53*i`。`0x4B8995 cmp id,9` 只設上界；可定位 record base `[0xF94304]+id*0x210`（原件又證 base 是 owner `F8D9E0+0x6924`），`0x4B89AD call 0x4D4150` 依有效 slot 寫 `record+0x5C=1`。
- `0x4B89DC..0x4B8A00` 每筆可 enqueue `C2S 26 00 id` (len3, slot0)；**在 role index >9 的情況下，該 per-row queue 還是可能走到**，所以不應讓 Server 傳入非法 ID 假設 Client 可安全忽略。
- `0x4B8A02..0x4B8A11` 計算 `mask |= (WORD(1) << (ID-1))`，但沒有完整重用 `<=9` guard。對 **ID0**，該位移不對應有效的1-based角色 bit；以 x86 shift low5 count 解釋會使16-bit結果為0。這是 Client 內部潛在不一致，不能將 `ID0` 當作可靠的初始角色槽。
- `0x4B8A60` 寫 mask `F94240`；`0x4B8A97 call 0x4E5FB0` 共用 record 後處理；`0x4B8AC4..0x4B8AE4` 可 enqueue `C2S 24 00` len2 slot0；後續尚可能有其他初始化封包。不應把整段理解為「Server 只需這兩個命令」。

**Server-side 合成測試要求（非原生官方 fixture）**：`N=0,1,9` 用有效 65B prefix 與長度正確的 UTF-16、row+0 NUL 終止、row+2E ID1..9，檢查 role data/UI availability、後續 C2S26/24；`N=0` 不代表創建 UI 必然可點。增加不合法 ID0、10、重複、短 header、非終止 UTF16/row、尾部殘留等負例，應由新 Server 自己拒絕或不產生。前段原生名稱與欄位的官方業務含義未全部還原，不能把 synthetic 0 值填入正式 MUST。

## 3. 候選 S2C69/7 → Square → C2S43：場景轉移的真正 Client 正向鏈

在 E61～E67 的既有證據上，本次獨立重驗以下機器碼與分離物件：

```asm
4B90C1  movsx ecx,byte ptr [payload+2]    ; app69 subtype
4B90C5  lea eax,[ecx-7]
4B90DF  push 0xBD54                      ; subtype7 branch, handle resource
4B90F0  call 0x4BBB70                   ; CSquare creation
4B90FD  call 0x4B7D50                   ; scene manager
4B9107  mov dword ptr [client+0x69A8],7 ; local scene state
4B9202  movzx edx,byte ptr [payload+3]
4B920B  mov [CSquareChannelState+0x18],edx
4B920E  movzx ecx,byte ptr [payload+4]
4B9212  mov [CSquareChannelState+0x1C],ecx
```

`0x4B90C1` 在消費 handler 內無獨立明確的「至少5 bytes」檢查；結果分支後會讀 offset+3/+4。因此新 Server 不能隨意構造短 app69 payload，更不能從一個 `69 00 07` 推定可以正常進 Square。前置資源取得/instance 失敗與 scene-manager state 的生命週期需保持；不把所有 subtype7 arrival 當成功進世界。

`0x506BBE` 初始化 `FE1AA0` 指向 `CSquareUserData`（`vptr=0xC0DDA4`，`+18=0`，`+1C=1`），`0x506C0F` 初始化 `FE1A88` 指向不同 `CSquareChannelState`（`vptr=0xC0DD84`，`+18=0`，`+1C=0`）。原生 RTTI 名稱與兩個不同 vptr 已由 E66/E67 核對。本輪直接以 BIN 位元組確認對應的 singleton assignment、field initialization 和讀取者。`S2C69` 後段 `payload+3/4` 寫 **ChannelState**；`0x4BBE66` 的 `CSquare::entry` 讀 **UserData+18**，建立 `C2S 43 00 XX 0A`，並以 `FBA798==0` 為 queue gate。`0x508970..0x5089D7` 在本地 index 變更時也有同樣的 C2S43 sender，且 check `index<count`；這個 C2S43 是另一個方向，不要和 S2C43 混成 ACK。

`S2C app0x0043→0x4B1A90` 只在取得 type6 object 後呼叫 `0x4DFD40` 清理/更新該類物件；`S2C app0x0042→0x4B2190` 做另一個 list/review 記錄效果（E68），均不能由 opcode 數字近似推定是 `C2S 0x42` 選角結果。

## 4. 新 Server 實作建議：設計上的 transaction state machine（明示為設計，不是官方事實）

以 `SPEC-CHAR-0001`／`SPEC-FLOW-0001` 的 `DRAFT/PARTIAL` 增量版本為目標，S00 可選擇以下 **proposed** 狀態機：

```text
Authenticated/SlotConnected
   └─ Server sends valid app2 roster (session-owned role indices)
          └─ Client local role UI available
                 └─ receive C2S42 (index,variant)
                        ├─ not owned / invalid / duplicate / stale → reject safely,
                        │   keep session & world state; choose Client-compatible visible error path after testing
                        └─ accepted by new Server policy → provide required scene/bootstrap S2C data;
                            candidate first step is app69 subtype7 (needs tested resource/Conn state)
                               └─ CSquare entry may emit C2S43 index,0x0A
                                    └─ Server sends Square-specific app68/6A and gameplay initialization
```

這份設計**不能**預先承諾「拒絕選角封包應是 0x43 或 0x42」、「0x69/7 必定為官方成功 ACK」、「首教學 key=1001/1」；相容 Server 的 error UI 和首登場景應在專門合成遊玩測試確定並記為 ADR，缺少 Client 必要 consumer 時由 T03/T05 續查。業務層身分綁定、權限、DB、Session 重複 request、重連與回滾均由 Server 決定，不需要原版 Server 內部原始碼。

**S00 應新增/更新的測試草案（不自改 S00 owner 檔案）：**

| Test ID（提案） | 測試 | 預期或待驗證點 |
| --- | --- | --- |
| `TEST-CHAR-RR2-01` | C2S42 `42 00 01 00`（synthetic） | Parser len4，驗角色1在登入 Session 且已可用；response 暫不由 opcode 猜配對 |
| `TEST-CHAR-RR2-02` | C2S42 `42 00 01 02`（synthetic） | 應和 mode0 區分；由 S00 ADR 定義 mode2 對玩家的行為 |
| `TEST-CHAR-RR2-03` | C2S42 截斷、超長、ID0、ID10、mode3 | Proposed Server parser fail-closed，不轉場、不改角色資料；**不是原生 Client 拒包能力宣稱** |
| `TEST-CHAR-RR2-04` | app2 N0/N1/N9 + role NUL name | Client role availability UI、26/24 出站、資源可達；測到失敗要區分本地 UI 與協定 |
| `TEST-CHAR-RR2-05` | app2 重複/ID0/ID10/短 header/無 NUL | 新 Server 拒絕生成及不覆蓋既有角色；避免 mask underflow/越界的 Client 風險 |
| `TEST-CHAR-RR2-06` | 經授權、隔離 Client 配合自製 Server 在有效 scene 送 app69 subtype7/offset+3/+4 | 是否真的切 Square、是否送出 43 00 XX 0A、是否需要 app68/6A；**synthetic compatibility** |
| `TEST-CHAR-RR2-07` | manager unavailable 與重複點擊 mode0/2 | local pending flag=1 但 C2S42 未入隊；Server 超時和 retry 必須具保守處理；不宣稱原 Client 自動重試 |
| `TEST-CHAR-RR2-08` | 選角拒絕/帳號已解封但角色未授權/斷線 | 不能假造原生錯誤 UI；測可否回選角、恢復角色資訊與連線清理 |

**測試器** 

```bash
python -B kr-extra-roy/20261031-0414-chatgpt-web-roy-E80-RR0002-native-verifier.py Tartaros.bin
```

驗證器使用 Python 標準庫唯讀檔案；實測**117 項 assertion 全 PASS**，由 **PE/RTTI/vtable、x86 原始位元組、E8 callee、場景和 header 精確來源** 加上 **顯式標為 Synthetic Server Policy 的選角 encode/decode／拒絕負例** 組成，不能把 117 理解為 117 項官方 Client/Server 功能測試。報告及腳本都不能替代 T01 對實質主張的逐項原生驗收。

## 5. RR-0002 正式條件、真正未解與任務分流

| RR 最初需求 | E80 與既有來源 | 狀態 |
| --- | --- | --- |
| C2S 選角兩參數／本地 send guard | `0x4A3B80`、兩個 RTTI class 的三條 direct callers、mode0/2、local +CC | **Client 靜態已證，限定路徑** |
| S2C app2 完整記錄及 header | `0x4B7F00`＋65+53N、header +2/+0C/+36..+40、role0 mask 風險、26/24 | **Client 靜態已證基本讀寫幾何，業務欄位尚有未知** |
| 選角後的 Client 場景入口/附加請求 | `S2C69/7→CSquare`；`C2S43`、Square68/6A；不同 Owner | **Client 有界可證，但與 C2S42 因果配對未證** |
| 選角成功/拒絕回覆 opcode、body、最小欄位和 Client UI 重試 | `S2C42/43` 有反證，`S2C69/7` 是相容候選；沒有完整 positive rejection consumer | **真正 Client 缺口，不能直接宣稱 full RR 完成** |
| S00 Server 規則 | 可以依 Client sender/consumer 明示候選流程與 fail-closed policy，測試後更新 SPEC | **已足以啟動設計，非官方原版政策** |

**Client 待逆向**：真正顯示「選角拒絕」的 S2C handler→UI 接收鏈；mode2 完整 UI 行為／重選 reset+CC；S2C69/7 與遊戲世界/角色 ID 綁定欄位是否需其他 S2C 初始化；app2 header 高位欄位與資源限制。先沿這些 Client source 做定向研究，而不是只因原版 Server 不可得就停止。

**Server 待開發（S00 交接，不能作 RR 阻塞理由）**：角色所有權、初值、角色 unlock/招募、Session 和連線恢復、mode0/2 業務策略、duplicate & idempotency、防過期選角、拒絕與重試的 transaction rollback。去重現有 `REQ-0003`「角色清單資料提供」、`REQ-0004`「角色 UI 就緒」，若選角需新需求則由 S00 對照需求台帳新增，不自行在研究分支平行建一本。

**跨功能待整合**：T02 transport/framing (RR-0001/0004/0007)、T04 role authority/initial data、T05 Square/world/first-tutorial、T06 UI resources；RR-0008 場景/SceneList 路徑只作鄰接，不得把 `(1001,1)` 當網路欄位。

**待遊玩驗證**：經使用者另外明確授權的隔離 original Client + new Server；必須記錄 app body/key/frame、UI、Square entry/exit、重試/拒絕/斷線。自製 Server 測試成功只證「可相容」，不還原原版 Server 真實時序。

### 正式狀態建議

截至 `main` 台帳仍記 `RR-0002 BLOCKED`、`submission=null`。這篇 E80 把 **可由原始 Client 靜態證實、可交 S00 規劃新 Server 的研究部分交付到 Git**；若 S00 同意使用者「不還原原版 Server」的新驗收定位，可**由 S00 依 append-only workflow**對目前 RR 明確拆分/改可驗收子條件、重新指派或接受有界 Client contract；剩餘 Client rejection wire/UI 繼續開別的限定 RR/GAP。**研究者不自改 `main` 的正式狀態、不冒稱 ACCEPTED。**

## 6. 出處與重現限制

本報告只引原件及有界既有同版本證據：E61/E62（roster、C2S42/S2C42/43）、E63（ScenarioReview 非網路 writer）、E64-E67（CSquare、64/69、C2S43、blocked 反證）、E68（SceneList／EndCutScene 複用反例）、E75（S2C26 補初始化）、E79（S2C2B→同一 record owner）。原研究與 S00/T01 的正式狀態均不覆寫。本輪原始 `.text` 反組譯使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000`；Script 每項 source check 從原始 BIN 的 PE section 轉址讀取，非使用先前偽碼直接當事實。

**E80 本身是「新 Server 可開始規劃的有界 Client static compatibility contract」完成交付；不是已完成所有 RR-0002 正式 acceptance、不是 T01 FULL-PASS、不是 S00 ACCEPTED、不是 Client 可實際登入世界的 runtime PASS。**
