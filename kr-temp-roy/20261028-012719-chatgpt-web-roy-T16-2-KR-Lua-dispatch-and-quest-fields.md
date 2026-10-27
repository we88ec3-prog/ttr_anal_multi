# T16-2 — KR 教學 Lua 讀取／入口分派與任務欄位解析：BIN-first 深度原稿

- 研究時刻：2026-10-28 01:27:19 Asia/Taipei
- 接續：T16-1（先前輸出檔名 T16-01；本段按使用者指定編為 **T16-2**）
- Repository：https://github.com/we88ec3-prog/ttr_anal_multi
- 核對 GitHub `main` HEAD：`52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`；截至本段核對，無遠端更新
- 第一手來源：本機只讀 `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- TC 第一手 BIN：缺失；repo 的 TC SHA256 `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873` 僅作索引，未驗檔
- 遵循：`02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T16-INSTRUCTIONS.md`、`04-T16-NEXT-CHAT-UPDATED.md`、GitHub AGENTS/HANDOFF/CLIENT-MODIFICATION-POLICY 及 T16 KR/TC 規劃
- GitHub：**未 Commit、未 Push、未變更 owner、catalog 或其他 Task**；原檔唯讀且未執行目標

## 1. 研究結論與界線

本段最重要的新進展：把 T16-1 從教學資源字串推定的「入口路徑」往下追到真正的 **Script 文件讀取 → bytes 取得 → 去 BOM 判定 → 解析執行 → 以名稱查找呼叫**；分開證實 `Synopsis_EntryPoint` 與 `Tutorial_EntryPoint` 兩個不同的函式入口名稱。此外追出 `HasQuest`、`HasCompletableQuest`、`HasScenario` 的**分欄解析**，確定它們不是同一個狀態旗標，並將 XML 節點子迴圈標成候選。

這些結果**不等於**已還原新手教學每一步、進度旗標、伺服器權威、第一個主線 ID、重登續接。沒有實際 Lua 或 XML 資源內容，也沒有版本匹配的 TC 原始資料，不能補猜。

## 2. 映射、驗證方法

- KR PE32 影像基址 `0x400000`；`.text` VA `0x00401000` ↔ raw `0x400`；`.rdata` VA `0x00BD2000` ↔ raw `0x7D0600`（T16-1 原始 PE header 核查）。
- 本次直接 `objdump -D -Mintel --start-address=... --stop-address=... Tartaros.bin`，核對執行指令相對 call 目的地及文字參照；字串直接從原 BIN 依 `.rdata` mapping 解碼。
- 指令清單皆為**靜態直接觀察**，不是目標實際執行路徑或後端語義觀測。函式名稱以下均為暫時工作標籤。

## 3. Lua 教學入口：二條具名腳本呼叫

### 3.1 native ASCII 精確字串核對

| VA | 真實 NUL terminated ASCII | 性質 |
|---|---|---|
| `0x00C06864` | `Event/TutorialBase.lua` | script path |
| `0x00C0687C` | `Event/TutorialMain.lua` | script path |
| `0x00C06894` | **`Synopsis_EntryPoint`** | named entry, **T16-1 原先未解析的常數本段已澄清** |
| `0x00C068A8` | **`Tutorial_EntryPoint`** | named entry |

**獨立 native calls**：

```asm
; A: 0x004A8A31 … 0x004A8A4B
004A8A31  push 0x00C0687C        ; Event/TutorialMain.lua
004A8A36  call 0x006F4A50        ; read / parse script bytes
004A8A3B  mov  eax,[esi]
004A8A3D  push 0
004A8A3F  push 0
004A8A41  push 0x00C06894        ; Synopsis_EntryPoint
004A8A46  call 0x006F4DD0        ; function name lookup / dispatch
004A8A4B  add esp,0xC

; B: 0x004A8B5D … 0x004A8B79
004A8B5D  mov  ecx,[esi]
004A8B5F  push 0x00C0687C        ; Event/TutorialMain.lua
004A8B64  call 0x006F4A50
004A8B69  mov  eax,[esi]
004A8B6B  push 0
004A8B6D  push 0
004A8B6F  push 0x00C068A8        ; Tutorial_EntryPoint
004A8B74  call 0x006F4DD0
004A8B79  add esp,0xC
```

另 `0x004A89AF: push 0x00C06864`、`0x004A89B6: call 0x006F4A50` 指向 `TutorialBase.lua`。兩個 EntryPoint 由**不同 client-side 呼叫路徑**引用；不能因名字相似視為同一回呼，更不能以 Synopsis 直接稱為「教學完成」。

### 3.2 `0x006F4A50` — read / parse script path（完整可見關鍵段）

開始 `0x006F4A50`，函式返回 `0x006F4C15`（`ret 4`）；至少一個堆疊參數（檔案路徑）。

```asm
006F4A6A  mov eax,[ebp+8]       ; incoming path
006F4A78  sub edx,eax           ; destination-minus-source for copy
006F4A80  mov cl,[eax]          ; copies until NUL
006F4A82  mov [edx+eax],cl
006F4A85  inc eax
006F4A86  test cl,cl
006F4A88  jne 0x006F4A80
006F4A8E  push 0x00BED1E0
006F4A93  push edx              ; local copied path
006F4A99  call 0x00714770      ; candidate resource/file resolver (not independently named)
006F4AA3  test edi,edi
006F4AA5  je 0x006F4BCF       ; absent/open failure route
006F4AAB  mov eax,[edi]
006F4AAD  mov edx,[eax+0x2C]
006F4AB2  call edx             ; file-interface vmethod, returns size candidate
006F4AB6  lea eax,[esi+1]
006F4ABA  call 0x0087DC3D     ; allocate size+1 candidate
006F4AC6  mov eax,[edx+0x38]
006F4ACC  call eax             ; file-interface second vmethod
006F4ACF  push ebx             ; allocated destination
006F4AD0  call 0x0089DBD0     ; buffer copy candidate
006F4AD5  mov byte ptr [esi+ebx],0
006F4AE5  cmp eax,3
006F4AEA  cmp byte ptr [ebx],0xEF
006F4AEF  cmp byte ptr [ebx+1],0xBB
006F4AF5  cmp byte ptr [ebx+2],0xBF
006F4B05  lea ecx,[ebx+3]
006F4B0B  call 0x006F7110    ; BOM path sends content skipping first 3 bytes
006F4B52  push ecx
006F4B53  mov ecx,0x00C42700
006F4B68  call 0x006FE990    ; non-BOM parse/submit path
006F4B89  push 0x006F5A50
006F4B9A  call 0x006FE770    ; shared handling of parse outcome
006F4BBD  mov edx,[edi]
006F4BBF  mov eax,[edx+4]
006F4BC4  call eax            ; file-interface close/release candidate
006F4BC6  push ebx
006F4BC7  call 0x00891D3D    ; buffer cleanup candidate
006F4BED  ...
006F4BFA  call 0x006F47A0    ; unsuccessful path reports/handles error candidate
006F4C07  mov eax,esi
006F4C15  ret 4
```

**已確認**：路徑複製、透過函式取得資源介面、透過 vtable 獲取大小／資料、以 `EF BB BF` 辨別 UTF-8 BOM、兩條解析路徑、釋放資源、回傳狀態。**部分確認**：資源介面 vtable `+0x2C/+0x38/+0x04` 的精確契約，以及錯誤處理函式的輸出方式。**未知**：尋找的容器／封裝格式、實際 Lua 內容、腳本對任務欄位的具體修改。

### 3.3 `0x006F4DD0` — named script-call function

函式 `0x006F4DD0…0x006F4F31`（回傳 `ret`）；以 `EAX` 傳入虛擬機／執行狀態物件候選，以 `[ebp+8]` 作名稱。兩呼叫者均 `push 0, push 0, push entryname`，並 `add esp,0xC`。

```asm
006F4DDC  mov edi,eax
006F4DDE  mov esi,[edi]
006F4DE0  mov eax,[ebp+8]      ; entry name
006F4DF0  mov dl,[eax]
006F4DF2  inc eax
006F4DF3  test dl,dl
006F4DF5  jne 0x006F4DF0
006F4DF7  sub eax,ecx         ; string length
006F4DFF  call 0x006FEC70    ; name-index registration/lookup candidate
006F4E1E  call 0x006FB850    ; obtain callable result candidate
006F4E35  cmp eax,0x00C0BFC8
006F4E40  cmp dword ptr [eax+8],6 ; result type/tag check
006F4E4A  mov edx,[ebp+0x10]
006F4E52  call 0x006F4CD0    ; format/pack arguments candidate
006F4E81  call 0x006FE770    ; execute/call candidate
006F4E9C  test eax,eax
006F4E9E  je 0x006F4F2B      ; failed/empty return path
006F4EE6  call 0x008930BD    ; log result candidate
006F4EF5  mov eax,[ebp+8]
006F4EFE  call 0x008930BD    ; missing/wrong-type log candidate
006F4F31  ret
```

**新結論**：EntryPoint 是按名稱查找、驗型別且呼叫的**腳本函式入口候選**，不是普通任務 ID。若 `0x6F4DD0` 執行呼叫失敗，存在另一路徑清理與訊息報告；是否會中止玩家進入教學，需補 caller 使用回傳值或狀態。`0x006F4CD0` 解析 `%d` 一類格式字符串，故不是教學條件寫入者的直接證據。`cmp [eax+8],6` 為此 VM/stack item 的標籤比較，**不是原版封包 `005F type6`**。

### 3.4 tutorial dispatch 前置全域狀態（語義未證）

```asm
004A8A94  call 0x00823850
004A8A9C  call 0x00851420
004A8AAB  test byte ptr [0x00FB7354],bl
004A8AB1  or dword ptr [0x00FB7354],ebx
004A8AD3  mov dword ptr [0x00FB73B4],ebx
004A8AD9  test byte ptr [0x00FAADD4],bl
004A8AE1  or dword ptr [0x00FAADD4],ebx
004A8AFF  mov eax,0xF
004A8B04  cmp [0x00FAadec],eax
004A8B0C  mov [0x00FAADF0],eax
004A8B13  call 0x0058A9A0
004A8B33  cmp dword ptr [0x00FBA798],0
004A8B46  jne 0x004A8B5D
004A8B48  mov ecx,[0x00FBA854]
004A8B50  mov edx,[edx+0x10]
004A8B53  push 6
004A8B55  lea eax,[ebp-0x14]
004A8B5B  call edx
```

**新結論**：分派前有一批全域旗標／模式操作，並在 `[0xFBA798] == 0` 時發出多型物件呼叫，但沒有證據將其命名為角色任務進度、教學已完成、或任務後端消息。`0xF`、`6` 是局部常數，域與使用者劇情進度 ID 尚未建立關係。保留 `0x00FBA854` 間接呼叫的 vtable owner 待跨 Task 協調。

## 4. 任務相關 XML 欄位 — `0x0053FD76..0x0053FE1C`

從原生 BIN 重驗 T16-1 的四個字段查找：

```asm
0053FD76 push 0x00C0F4E4       ; preceding key, content needs decoding
0053FD7D call 0x0072E2E0
0053FD84 push 0x00C0F4EC       ; HasQuest
0053FD8B call 0x0072E2E0
0053FD92 push 0x00C0F4F8       ; HasCompletableQuest
0053FD99 call 0x0072E2E0
0053FDA2 push 0x00C0F50C       ; HasScenario
0053FDA9 call 0x0072E2E0
0053FDB2 test edi,edi
0053FDBD call 0x0053FEB0       ; first category, ptr to structure base
0053FDC6 test esi,esi
0053FDCA lea edx,[edi+0x10]   ; HasQuest destination
0053FDD0 call 0x0053FEB0
0053FDD5 mov eax,[esp+0x20]
0053FDDD lea ecx,[edi+0x20]   ; HasCompletableQuest destination
0053FDE1 call 0x0053FEB0
0053FDE6 mov eax,[esp+0x1C]
0053FDEE lea edx,[edi+0x30]   ; HasScenario destination
0053FDF2 call 0x0053FEB0
0053FE1E mov ebx,[ebx+0x40]   ; next item on loop candidate
0053FE23 jne 0x0053FCF5
```

此為**表格式節點欄位→局部輸出容器**，不是持久化的客戶端 Quest state 或伺服器資料表本身。`0x0053FEB0` 又從 `0x00C0F4A0` 找到子節點，透過 `vtable +0x14` 及 `0x007300A0` 查詢另一個名稱，顯示有**進一步的節點展開**，但確切值類型、是否任務前置關係，需把此解析器的上游 XML root／儲存結構與消費者定位後才能定義。

### 與主線解析的關係（尚未閉合）

- QuestInfo.xml：`0x0050478B mov ecx,0x00C0DB48`、`0x00504794 call 0x0072EE30`
- QuestTalk.xml：`0x005055B8 mov ecx,0x00C0DB5C`、`0x005055C1 call 0x0072EE30`
- 本段確認「同一 generic file/path helper 被兩種 XML 使用」，但**未證實** `0x0053FD76` 的解析表就是 QuestInfo 或 QuestTalk 的欄位表；須追 caller/schema 避免錯配。未取得 XML 資料，所以本段不列猜測 quest ID。

## 5. 調用圖與資料流

```text
KR native program (T16-2 confirmed at call sites)
  0x004A89AF → path Event/TutorialBase.lua → 0x006F4A50
  0x004A8A31 → path Event/TutorialMain.lua → 0x006F4A50
                 0x004A8A41 → Synopsis_EntryPoint → 0x006F4DD0
  0x004A8B5F → path Event/TutorialMain.lua → 0x006F4A50
                 0x004A8B6F → Tutorial_EntryPoint → 0x006F4DD0

  0x006F4A50: path copy → 0x00714770 → vtable size/read →
               buffer / BOM split → 0x006F7110 or 0x006FE990 →
               0x006FE770 → cleanup & return status
  0x006F4DD0: entry string → 0x006FEC70 / 0x006FB850 →
               tag check → 0x006F4CD0 → 0x006FE770 → result/log

  0x0050478B QuestInfo.xml ─┐
                              ├→ 0x0072EE30 (file/path helper)
  0x005055B8 QuestTalk.xml ─┘

  0x0053FD76 [separate table parser; XML root not yet proven] →
    0x0072E2E0 × 4 → optional 0x0053FEB0 × 4 → output base,+0x10,+0x20,+0x30
```

**Pseudocode（抽象控制流程，非完整型別已確認）**：

```cpp
// Conceptual only — VM structures and ABI names unverified
bool loadScriptCandidate(VM* vm, const char* path) {
    auto file = resolveCandidate(path);
    if (!file) return false; // outcome details unverified
    auto bytes = readCandidate(file);     // vtable +0x2C/+0x38
    bool bom = bytes.size() >= 3 && bytes[0]==0xEF && bytes[1]==0xBB && bytes[2]==0xBF;
    bool ok = bom ? parseCandidate(bytes+3) : parseCandidate(bytes);
    releaseCandidate(file, bytes);
    return ok;
}
void invokeNamedScriptCandidate(VM* vm, const char* name, ...) {
    auto value = lookupCandidate(vm,name);
    if (!callableTagCandidate(value)) { logCandidate(name); return; }
    prepareArgsCandidate();
    callCandidate();
}
```

## 6. tutorial-node-matrix / early-mainline-flow

| node | 前置 | native client trigger | server authority | writer | UI/notification | next or recovery | 級別 |
|---|---|---|---|---|---|---|---|
| TUT-resource-base | unknown | `TutorialBase.lua` xref to 0x6F4A50 | unknown | VM parse candidate | unknown | unknown | 原生已確認（腳本載入呼叫），語義部分確認 |
| TUT-synopsis-entry | unknown | `TutorialMain.lua` + `Synopsis_EntryPoint` | unknown | unknown | unknown | unknown | 原生已確認（具名分派呼叫） |
| TUT-tutorial-entry | unknown | `TutorialMain.lua` + `Tutorial_EntryPoint` | unknown | unknown | unknown | unknown | 原生已確認（具名分派呼叫） |
| TUT-complete/relogin | unknown | unknown | unknown | unknown | unknown | unknown | 資訊缺失 |
| MAINLINE-first-offer | unknown | `QuestInfo.xml` / `QuestTalk.xml` 的路徑引用 | unknown | unknown | unknown | unknown | 資訊缺失（只確認資源引用） |
| MAINLINE-first-unlock | unknown | unknown | unknown | unknown | unknown | unknown | 資訊缺失 |

### KR↔TC evidence matrix

| domain | KR | TC | 目前可否宣稱相同 |
|---|---|---|---|
| 原始 BIN | SHA 已直接驗證 | 僅 metadata SHA | 否 |
| TutorialMain/Base.lua 路徑 | KR 原生 BIN 已確認 | unknown | 否 |
| Synopsis_EntryPoint | KR 原生字串 + 分派 xref | unknown | 否 |
| Tutorial_EntryPoint | KR 原生字串 + 分派 xref | unknown | 否 |
| QuestInfo/QuestTalk.xml 路徑 | KR 原生 BIN 已確認 | unknown | 否 |
| quest/step ID | unknown | unknown | 否 |
| server quest state / reconnect | unknown | unknown | 否 |

## 7. cross-task-interfaces / owner 防護

- T03/T04 → T16：已存在角色／登入後可取得的狀態，未驗證具體教學旗標；不推導新角色起始位置。
- T02 → T16：等待任務指令封包業務欄位與 payload；本次 `cmp 6` 與 `push 6` **不是**封包證據。
- T07/T14 → T16：教學/任務完成要求的關卡事件與結算通知尚未追到；不將通關等同主線完成。
- T15 ↔ T16：需持久化的 quest ID/step/status/writer 尚未定位；不研究底層保存機制。
- T08/T10/T11：僅引用可能在教學中被要求的實體/行為事件，未更改其 owner。

## 8. acceptance-matrix

| 可驗收斷言 | 本段狀態 | 依據 |
|---|---|---|
| KR BIN 身分 | verified | length + SHA256 |
| Lua 路徑實際傳入解析器 | verified | caller instructions + 0x6F4A50 |
| 檔案讀取含 UTF-8 BOM 處理 | verified | 0x6F4AEA..0x6F4B15 |
| Synopsis 與 Tutorial 為不同具名入口 | verified | ASCII bytes + call sites |
| named VM 值查找／型別檢查／call | partially verified | 0x6F4DD0 + VM internal names pending |
| HasQuest 等解析到不同局部欄位 | verified | 0x53FD76..0x53FDF2 |
| Tutorial 正式進度與完成旗標 | not verified | 缺 Lua 腳本與 writer |
| QuestInfo/QuestTalk 真實 XML schema | not verified | 未取得 XML |
| 首個主線 NPC／quest ID／前置條件 | not verified | 未取得原始表與 server 証據 |
| TC 與 KR 相同 | not verified | TC 原件缺失 |
| 可玩性或伺服器恢復 | not tested | 本任務僅唯讀逆向 |

## 9. 本段反證及修正

1. T16-1 對 `0x00C06894` 未命名；本次直接讀為 `Synopsis_EntryPoint`，不可稱 tutorial completion。
2. `0x006F4A50` 不只是看到了腳本路徑；native bytes 證實真正**讀入 bytes / BOM 處理 / 解析處理**；但不代表 Lua 已成功執行。
3. `0x006F4DD0` 的 `cmp [...+8],6` 為 VM value type candidate，與原版 005F type6 未建立任何關係。
4. `HasQuest` 與 `HasCompletableQuest`、`HasScenario` 屬三個**不同 lookup + output offsets**，不能當作單一持久化 state。
5. 目前無 caller 連結可證 `0x53FD76` 屬 `QuestInfo.xml`，不可把兩條各自獨立的引用拼成已確認原生資料流。

## 10. 下一段 T16-3 優先工作（按深度自動延伸）

1. 找 `0x004A8A60` 的 caller、路徑分支與狀態來源，辨別何時呼叫 `Synopsis_EntryPoint` 或 `Tutorial_EntryPoint`；檢查 `0xFBA798` writer（但不跨 Task 改 owner）。
2. 將 0x6F4A50 的 `0x714770`、Lua VM 入口、錯誤支路與 0x6F4DD0 回傳契約串起；追到腳本 callback 是否能讀/寫 Quest state。
3. 從 `0x50478B`、`0x5055B8` 上游 caller 與 `0x53FD76` 的 XML root 逐一辨認 Quest table reader／consumer，取得真實任務源資料再建立主線初段。
4. 搜尋 repo 既有 QUEST-STATE-NOTIFICATIONS/MAINLINE-FLOW/48-tutorial-battle-fixture 詳細來源並逐項標示 native/fixture；不執行歷史檔。
5. TC 若無 native source 繼續僅做 source inventory；不重啟保護殼。

**提交狀態**：T16-2 原稿已產生在本對話本機 `/mnt/data/`，GitHub 無寫入、無 commit、無 push。