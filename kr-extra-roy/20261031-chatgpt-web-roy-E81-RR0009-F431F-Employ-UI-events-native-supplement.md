# E81 — RR-0009 補充：F431F → CEmployNewCharacter UI 消費者、事件來源、空角色清單反例

> 2026-10-31，KR T03，chatgpt-web roy；既有 RR-0009 claim branch：`extra/roy1`。**此篇是已 SUBMITTED 的 E70 追加原生證據，不取代 E70、不更動 RR 台帳、不宣稱創角 UI 已由 N=0 自動開啟。**
>
> 開工權威：`main=dd8d487316ea2bfb1de3e0b3851f14c398303a68`，RR-0009 `dispatch.state=SUBMITTED`，`submission.report_blob_sha=ef778ac58ccdfd4013962b86a2aa33bf6f245d13`，`review=null`。T03 舊 T01 `T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX` 與本次研究獨立，依使用者指定 RR9 而延後。當次確認 `main` 為工作分支祖先，已安全快轉 `main→t03/roy/chatgpt-web` 與 RR9 claim branch `main→extra/roy1`，不覆寫先前原稿。

## 1. 第一手來源、研究問題與限定結論

- 原始 `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；原始 `Tartaros.exe`：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Table.stp`：SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。本輪重新從原件讀取並計算三個 hash，沒有執行 Client 或 Server。
- PE32 x86 ImageBase `0x400000`；`.text` VA `0x401000`，raw `0x400`，size `0x7D0200`。僅在 `.text` 使用 `raw=VA−0x400C00`；RTTI `.rdata` 需依 PE section mapping。
- E70 已證 `S2C app0x0002` → `0x4B7F00` → `0x4B894C`：`N=0` 跳到 `0x4B8A20`；`N>0` 依 `65+53×N` 解析並由 `0x4D4150` 寫 `record+0x5C=1`；`0x5C30FD` cache `CEmployNewCharacter`，但未建立 N0→control 可見性的正向因果。
- **新增** E81：已從原始 BIN 將 **UI owner 事件接收 `0x5C32D0` → `0x5C36D0` → `0x6BF310`** 與另一個 **`0x5AAE80` 的 F431F 本地事件消費者**、`0x4A98D0` 事件建立來源及一層間接 callback 登記連成有限圖。此圖比「有 GUI cache」更接近真正的資料/顯示行為，但**仍沒有證明 N0 會產生或送達 F431F，更沒有同版 GUI 按鈕/control layout 的原件身份**。

## 2. UI owner 初始化：`0x11B` 是類型／組件登記碼，不等於可見建角控件

`0x5C3040` 執行對 owner 成員的多個 cache/registration，先後包含：
```asm
5C30F7 lea esi,[ebx+0x230]
5C30FD call 5AB020           ; lazy cache wrapper, CEmployNewCharacter
5C3105 call 5A9F40           ; slot capture/setup
5C3156 mov eax,[ebx+0x230]
5C316A call 596D70           ; manager registration, args include owner/object
```
新的關係是 `0x5C3210` 的組件/事件類型登記序列，依序向 `0x4095E0` 送入 `0x54, 0x57, 0x10, 0x11D, 0xD3, **0x11B**`，最後 `0x5C329A push0x11B; 0x5C32A2 call 0x4095E0`。這與 E70 在 cache 記錄 `+4=0x11B` 相互印證其 **GUI 類型註冊用途**，但不證明 `0x11B` 是建立新帳號可用角色的 XML ID，也不證明 owner/對話框在 N0 自動顯示。必要的資源載入與可見狀態仍是另外的條件。

## 3. 事件 `F431F` 的 owner 消費者：`0x5C32D0 → 0x5C36D0`

`0x5C32D0` 先呼叫共同 UI event handler `0x59B420`，接著對 `event+0x10` 分支：

```asm
5C32E0 mov eax,[edi+0x10]
5C32E3 sub eax,0xF42DB
5C32E8 je 5C330E               ; F42DB
5C32EA sub eax,2
5C32ED je 5C3301               ; F42DD
5C32EF sub eax,0x42
5C32F2 jne 5C3340              ; F431F when equal
5C32F4 mov eax,edi
5C32F6 call 5C36D0
5C3303 call 5C34B0             ; F42DD branch
```

`0x5C36D0` 不是無條件建立 GUI。它先讀 `event+0x14`，為 0 則 `0x5C36D5 je 0x5C3744` 直接返回；非 0 時才：
```asm
5C36D7 mov edx,[esi+0x230]     ; owner 的 CEmployNewCharacter
5C36DD push edx
5C36DE call 6BF310             ; 補入角色 UI record/detail
5C36E3 mov eax,[esi+0x230]
5C36EA push eax
5C36EB call 596E00             ; UI manager 操作；不把函式名猜成「一定顯示」
5C370E mov [eax+0x10],0xF43FD  ; 另一個 local event
5C3729 mov ecx,[esi+0x228]
5C3730 call 6C0170             ; 轉給另一個 UI 子組件
```
該段確實形成 F431F nonzero-param → 同一 `+0x230` cache/dialog → `0x6BF310` record setup → UI manager/本地事件的**可達 Client 片段**。尚未找到的仍是：誰在有效 scene/roster 狀態投遞這個事件、`event+0x14` 對應的合法值、資源可用性及實際控制項 visible/enabled 狀態。

## 4. 另一個 F431F 消費者 `0x5AAE80` 的雙路，不得把 C2S33 叫作建角 UI 打開

```asm
5AAEA9 cmp dword [edi+0x10],0xF431F
5AAEB2 cmp dword [edi+0x14],0
5AAEB6 je 5AAEEA                 ; zero branch
5AAEB8 mov ecx,[esi+0x164]
5AAEC6 call [vptr+0xD4]          ; cleanup/UI transition
5AAED2 call 6BF310               ; arg event+0x14, target [esi+0x168]
5AAEDF call 596E00
5AAEEA ...                        ; local branch when event+0x14==0
5AAF0A cmp dword [FBA798],0
5AAF11 mov edx,0x33
5AAF16 mov word [ebp+0xA],dx
5AAF27 push 2                     ; packet len=2
5AAF2D push 0                     ; slot0
5AAF2F call eax                   ; manager send queue virtual
```

所以 F431F 也不是無條件「開創角」事件：一個 consumer 依 event+0x14 做 UI record setup，另一支可能發出 **C2S `33 00` 長度2**；它沒有名字／外觀欄位。這與 E71 已證的 `CEmployNewCharacter::slot87(0x6BF2A0)` 在 UI event `0x578` 確認控制身份後，依 `global+0x5F4C` 分支呼叫本地 UI 或 `0x4A38D0` 同方向 C2S33 的描述不矛盾。**不能將 recruit、新手帳號創角、名字建立混為同一業務流程**。

## 5. F431F 來源：callback 註冊存在，但網路/roster 因果未證

`0x4A98D0` 是一個確定的 **本地 F431F event constructor/helper 呼叫路徑**：
```asm
4A9926 mov eax,[ebp+8]
4A9929 push eax
4A992A push 0xF431F
4A992F call 58AB80               ; 建本地事件，未證已投遞至特定 listener
```

原始 `.text` 已對 `F431F` 的直接 DWORD literal 全區掃描，只找到 `0x4A992B`、`0x5AAEAC`、`0x6BA33C`。這不是整個執行期間所有動態 event source 的窮舉。

`0x4AAE00` 在 `0x4AAE18` 把函式指標 `0x4A98D0` 寫入全域 `FE1838`；`0x4AC376` 將 `[FE1838]` 作為參數，再於 `0x4AC380` 呼叫 `0x4ACB70`。因此原生存在 **registration/global callback → generic wrapper** 的候選上游，不是 `E8 direct call→4A98D0`，也沒有於此靜態範圍解開完整的間接呼叫、事件最終 dispatch 訂閱、與 S2C command2 之間的因果。對 `.text` 全區的 `E8` rel32 查詢確認 `0x4A98D0` 沒有直接 E8 caller；**不代表它不可達**，恰好需要另查 delegate/callback。

## 6. RR-0009 的四種必要反例及新 Server 影響

| 情境 | 可證的 Client 行為 | 不可升格為已驗證 |
| --- | --- | --- |
| `N=0`、完整 65B prefix | `0x4B894C` 跳過 53B row loop、到 `0x4B8A20` 共通後處理，更新 mask、呼叫 `0x4E5FB0` | **沒有正向 N0→F431F producer/listener/建角按鈕**，也未證自動顯示 dialog |
| `N>0`、合法 role index | `0x4D4150` 寫 role record/ready，後續 F431F nonzero 可在有 owner/非零 event payload 時進 `6BF310` | role ready ≠ 初次建角/GUI visible；F431F 不等於 cmd2 的直接結果 |
| 缺同版 GUI 資源 | cache/type registration 與事件 handler 代碼仍可存在 | `Table.stp` 不是已核定的 GUI layout/control pack；缺資源時視窗是否可見尚不能以原始 client 運行確認 |
| Record 已寫但 UI 未 ready | `+0x5C`、F42EF/list-hit 和 F431F UI processing 可能分別成立 | 必須有相應 owner、listener、resource、screen gate、visibility；多一個事件 consumer 不能取代這些 |

**Server 設計**：已證的相容封包 `S2C app2` 角色清單與 `C2S0x33` 招募候選可交 S00 作 DRAFT，附加 N0/N1/缺資源/不同本地 event 值測試；「新帳號預設幾名角色」「是否自動顯示招募/建角」「何時提供角色」由 S00 在 Server ADR 明確設計，不要推成官方行為或未證的 Client 自動對話框。且不能因為有 `0x11B` 就硬編一個假 XML 按鈕。

## 7. 完成條件對照、交接與重現

RR-0009 原訂 acceptance ① 真實 N0→create GUI branch/resource identity、②四種反例、③ local vs wire、④報告/GAP/TEST、⑤若找不到正向入口提交精確 blocker。E70 已依 **⑤** 提交到 `main` 的 RR `SUBMITTED` 狀態，原稿 Git blob `ef778ac58ccdfd4013962b86a2aa33bf6f245d13`；本次 E81 對 ① 更往內追到 F431F UI consumer 但仍未接到 N0、對 ②③④ 增補 source-only 證據。**未滿足 ① 的完整正向因果，故不可自稱 Client GUI 可操作/已 T01 FULL-PASS/S00 ACCEPTED。** 由 S00 決定既有 SUBMITTED 接受或要求 NEEDS_REVISION；不重置 claim、不自行修改台帳。

```bash
python -B kr-extra-roy/20261031-chatgpt-web-roy-E81-RR0009-verify.py /path/to/Tartaros.bin
# 預期 E81 PASS 31 bounded first-hand BIN assertions
# 僅讀原件；沒有 Client 執行、GUI 實機、Server 收發或官服 pcap
```

E81 驗證器除了原始 SHA/PE 映射，還核對 E70 的 N0 branch/record flag、F431F 常量 xrefs、owner+0x230/type0x11B、`0x5C32D0` branch、`0x5C36D0` & `0x5AAE80` 各自送 `0x6BF310`、`0x4A98D0` local event、`FE1838` function-pointer registration、無直接 N0 xref。**31 項 source-byte assertions 本輪已在本機原始 BIN 實際 PASS，不能冒稱遊玩驗證。**

仍需解除的 Client-only 證據：對 `FE1838/0x4ACB70` 間接 caller/listener 做 pointer provenance，以及將 `F431F` event+0x14 provenance 追到有/無角色 scene gate；需要 T06 同版本 GUI pack 的 create/recruit control 真實身份。**缺少原版 Server 內部演算法不是理由，缺少原生 Client UI 正向可達性才是 RR9 尚待功能閉合的部分。**

來源／相鄰：E70 原稿與 verify（不覆寫）、E71（CEmployNewCharacter C2S33，不假定建角）、E80（ExpeditionScene/ExpeditionDialog 選角，非 RR9 建角 UI）、T02 RR-0007 網路分派、T06 資源主責、S00 `SPEC-CHAR-0001`／`SPEC-FLOW-0001` `DRAFT/PARTIAL`、`GAP-CHAR-0002 OPEN`。本檔需待 GitHub 實際提交後以 remote blob SHA 記錄。
