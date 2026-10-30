# E71 — RR-0010 KR 建角交易：C2S 候選、S2C 回覆反證及角色名單初始化證據

> 2026-10-31（Asia/Taipei）｜chatgpt-web roy｜唯一研究分支 `extra/roy1`。研究採用原始 `Tartaros.bin` PE32 x86，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。實際原件重新計算、唯讀，未執行／修改 Client。`.text` VA `0x401000` raw `0x400`，僅此區間 raw=VA−`0x400C00`；`.rdata` VA `0xBD2000` raw `0x7D0600`。

## 0. 對玩家及 S00 的研究結果

**RR-0010 的功能是玩家建立角色後的真正 Server 交易**，不是 RR-0009 是否顯示建角視窗，也不是 RR-0002 選擇既有角色。正式問題要求：新角色建立的 C2S producer、S2C accepted/rejected consumer、欄位/長度/字元編碼、接收後 roster 初始化與重名/重試/斷線反例。RR-0010 在本輪於 GitHub main 已正式認領，claim branch=`extra/roy1`，RR-0002 原有 BLOCKED、RR-0009 原有 SUBMITTED 不變。

**本輪最大原生新發現**：`CEmployNewCharacter@FUI@@` 的真正 vtable event slot87 指向 `0x6BF2A0`，該方法符合 UI control identity、`Client+0x5F4C !=1` 時呼叫 `0x4A38D0` 產生 `C→S app 0x0033`：精確 payload `33 00`、長 2、slot0、`FBA798==0` 才呼叫送出介面。但是沒有名字/外觀/職業等 build 欄位，**不能正向定名為「新帳號建立角色」**。接收第一層 `S→C app 0x0033` 無直接 index33 override，會依 active scene 再分派；缺少請求-結果對應。另一長度可變 `C2S0x0021` 有世界場景多來源 caller；`0x0027` 是 8-byte 專用封裝器，兩者也未有建角回覆正向證據。`S2C 0x0002` 角色列表可更新本地 record，但沒有從上述 request 確定連回它。

**研究狀態**：34 項原始 byte/RTTI/direct-call 靜態斷言 PASS，提供完整可重現腳本；實質 **Client 建角 request→matching response→roster** 仍未閉合。依共同規範必須標 `BLOCKED`，不得把一份已寫完的報告冒稱原生功能完成，更不得標 T01 FULL-PASS、S00 ACCEPTED 或可玩。

## 1. 固定驗收問答矩陣

| 必查項 | 本輪限定結果 | 證據類別 |
|---|---|---|
| 哪個 UI 控件送建立請求？ | `0x6BF2A0` 由 `0x578`、`this+0xD0→+0x20` 比對控件；屬 `CEmployNewCharacter` 類別，但語意只可稱候選 | N 控件；U 新帳號建角 |
| 送出哪個 payload？ | `0x4A38D0`：`33 00` 2-byte app payload、slot0，受 `FBA798==0` gate | N，此候選 |
| 是否另有包含名字的大包？ | `0x4A39F0` 的 `0x21` 多項封裝有 3B/103B 子項、11 個 caller；沒有證據與建角 name input 配對 | N 通用格式；U 建角 |
| `0x0027` 呢？ | `0x4A3720` 的 8B request，唯一直接 caller `0x682A3F`，用 byte+DWORD+byte | N 封裝；U 建角 |
| 是否為選角 `0x0042`？ | `0x4A3B80` 由既有角色 UI 三個 caller 建 4B；**非建角正向證據** | N，另屬 RR-0002 |
| `S→C 0x0033` 是 ACK 嗎？ | 全域第一層 index0x33 不覆寫 default，需要 active scene；沒有正向結果 handler | N table；U 回覆 |
| 成功/重名/斷線/重試？ | 無完整 create-result native 分支，不能造 result codes 或 retry policy | U |
| 結果如何產生角色？ | `S2C0x0002` → `0x4B8920`，53B/row → `0x4D4150` record+`0x5C`，再 `0x4E5FB0`；與建角請求因果未閉合 | N roster；U 串接 |

N=原生直接確認；C=有條件推論；U=資訊缺失。

## 2. CEmployNewCharacter RTTI、共享事件、特有 callback

`vptr 0xC3F024` 經 MSVC RTTI CompleteObjectLocator/TypeDescriptor 查得 `.?AVCEmployNewCharacter@FUI@@`。`vptr 0xC33C74` 則是另一類 `.?AVCCharChangeDialog@FUI@@`。兩者的 vtable **slot80 都指向 `0x65D550`**；因此之前 E70 指出的 `0x65D550` 產生本地 `F4350` 事件並不專屬建角，不能以這一個 local event 確認創角。`CEmployNewCharacter` slot87（vptr+`87*4`）是 `0x6BF2A0`，此方法本輪第一次對照完整事件與 send callee。

```asm
6BF2A3 mov eax,[ebp+8]
6BF2A6 cmp dword [eax+0x10],0x578  ; local GUI event
6BF2B2 mov ecx,[esi+0xD0]
6BF2B8 mov edx,[eax+8]
6BF2BB cmp edx,[ecx+0x20]         ; control identity
6BF2BE jne 0x6BF2FF
6BF2C0 call 0x404BA0
6BF2C5 cmp dword [eax+0x5F4C],1
6BF2CC jne 0x6BF2F5
6BF2CE call 0x49B230              ; local alternate branch
6BF2D5 call 0x6BFAE0
6BF2DA call 0x4054C0
6BF2DF call 0x58B510
6BF2E4 mov eax,[esi]
6BF2E6 mov edx,[eax+0xD4]
6BF2EE call edx
6BF2F5 call 0x414680              ; different state only
6BF2FA call 0x4A38D0
6BF2FF ret 4
```

本地反例 A：`event+0x10!=0x578` 不會進入本次分支。B：控件 identity 不符不進去。C：`Client+0x5F4C==1` 走 local UI method／virtual，而不是 `0x4A38D0`。不得把「EmployNewCharacter」類別字面上的 NewCharacter 當網路交易名稱。

`0x5AB020` 的 lazy cache、`0x5AB280` constructor、`0x5C30FD` owner registry 仍是 E70 已知的 UI 建立前提，但不能證明按鈕已顯示或名稱欄位存在；此需對應版本 T06 GUI resource + click event/控件 id 交叉證據。

## 3. 可確定的 C→S 0x0033 位元組、slot、限制

```asm
4A38D0 push ebp
4A38D4 cmp dword [0xFBA798],0x0
4A38DB mov eax,0x33
4A38E0 mov word [ebp-2],ax       ; 33 00 little-endian
4A38E4 jne 0x4A38FB
4A38E6 mov ecx,[0xFBA854]       ; manager instance
4A38EC mov edx,[ecx]
4A38EE mov edx,[edx+0x10]
4A38F1 push 2                    ; 2-byte inner app payload
4A38F3 lea eax,[ebp-2]
4A38F6 push eax
4A38F7 push 0                    ; slot argument
4A38F9 call edx
4A38FB ret
```

正向證據僅限 builder 的本地 virtual send/enqueue 呼叫；**TCP frame header/markers 不是 app 0x0033**，真正送出需 T02 transport queue、mode & WSASend gate，不能聲稱單個 `33 00` 即可傳到 wire。整段 raw-backed `.text` E8-rel32 目標 `0x4A38D0` 唯一候選 `0x6BF2FA`，已回看原生指令邊界；不排除其他 indirect callers。

## 4. 反證：0x0021 不是已確認建角名字包

`0x4A39F0` 本體初始化 opcode `0x0021`、兩個來自 stack 的 BYTE、另有初始 8B 本地 payload；對可選 4-byte-pointer vector 逐個讀 item[0] 類型，按 type 檢查後分別 copy **3B** 或 **103B**，每一項受 0x1000 載荷上限約束。下游 `0x4A3B12` 取得 `FBA854`、vtable+0x10，以計算長度入 queue。**長度 103 不足以命名為 nickname**，因同一 helper 被不同世界狀態／UI caller 呼叫。

直接 E8 候選 **11 處**：`0x45D018,0x577988,0x5FF6E4,0x60049B,0x6004ED,0x600AE3,0x6010F2,0x6092B4,0x60AB5A,0x651F64,0x8FEA9F`。例如 `0x5FF6A4` 比對本地事件 `0x6A7`，多個非空資料 gate 後才 `0x5FF6E4` 呼叫；`0x600454..0x60049B` 先檢查 `Client+0x5F4C` 等於 4、9、28；另一 `0x651F64` 從最多100個陣列項取條件資料再呼叫。這些是**非唯一多用途發送者**，與目前 N0 roster 或建角 modal 沒有已證正向連結。

```asm
4A3A0A mov eax,0x21
4A3A0F mov word [ebp-0x1018],ax
4A3A16 mov al,[ebp+0xC]
4A3A28 mov byte [ebp-0x1016],cl
4A3A6A movzx ecx,byte [eax]
4A3A73 lea ecx,[edx+0x67]       ; type branch 103-byte
4A3A76 cmp ecx,0x1000
4A3A7E push 0x67
4A3A89 call 0x89DBD0
4A3A99 lea ecx,[edx+3]          ; other type 3-byte
4A3A9C cmp ecx,0x1000
4A3B12 mov ecx,[0xFBA854]
4A3B1A mov eax,[eax+0x10]
4A3B1D push edx                 ; composed len
4A3B27 call eax                 ; virtual send
```

## 5. 反證：0x0027 與 0x0042

`0x4A3720` 初始化 `0x0027`，讀一個 byte、DWORD、另一個 byte，組 `3+5=8B` app payload 並入 send；整段直接 caller 只有 `0x682A3F`，後者讀 `ESI+0x160/+0x164/+0xD0` 當參數。原生資料來源沒有正向指向建角姓名/外觀輸入；不能把 `0x0027` 稱角色建立。`0x4A3B80` 的 `0x0042` 確認為既有角色選擇的 4B C2S，由三處 `0x5F47F5/0x5F48F7/0x673EAA` 呼叫，明確屬 RR-0002，不可借作建角。

## 6. S→C 方向：沒有完成的 create-result handler

`0x4B7DC0` 使用 first-layer table `FD2CF8`：以 stride8 初始化預設 handler `0x4B7EC0`，而 command2 被覆寫在 `FD2D0C=0x4B7F00`。對 command `0x33` 的 handler slot 算式為 `FD2CFC + 0x33*8 = FD2E94`。本輪核對 `0x4B7DC0..0x4B7EBF` 未有直接 static register 對該位置覆寫，因此若 S2C app0x33 進來，**第一層仍依 active scene 走 generic fallback**。`0x4B7EC0` 先檢查 `Client+0x5EAC`，無 active scene 就診斷/返回，並不是專用 Create ACK。此為**限定在這份初始表的直接覆寫陰性證據**：其它場景表、virtual/indirect registration、原版 Server 使用另一 opcode 均未被排除。

先前 E61/E68 已證 base scene S2C `0x42` 是 effect/list container consumer、`0x43` 是 object cleanup 路徑，**不能**視為 create request +1 結果。也沒有查到能接合上述 C2S0x33/0x21/0x27 與指定 roster 的可靠 Server request/response 交易。

## 7. 角色初始資料與成功結果的真正缺鏈

第一層 S2C app `0x0002` → `0x4B7F00` → `0x4B8920`（len>=65，`N=floor((len-65)/53)`）。N0 於 `0x4B894C` 跳到共同 post `0x4B8A20`；N>0 的 row source 53B、index<=9 通過後 `0x4B89AD` 呼叫 `0x4D4150`，`0x4D4154` 設記錄 `+0x5C=1`；之後 `0x4B8A60` 更新 `F94240` mask，`0x4B8A9C` 呼叫 `0x4E5FB0`。**這是角色名單解析，還不能稱建角成功事件必會回 roster**。角色世界內初值為 T04 主責，T02 的 TCP/IOCP、framing 是共用下游，T06 GUI resource 是上游前置，不因數字相同合併。

## 8. 成功／失敗／重複建立／斷線的矩陣

| 情境 | 已確認 Client 靜態邊界 | 未知／待證 |
|---|---|---|
| 相關控件按下且 `Client+0x5F4C!=1` | `0x6BF2FA` 有條件呼叫 `0x4A38D0`；`FBA798==0` 時 enqueue 33 00 | 該控件是否是新帳號 Create；Server 正負回覆 |
| 相同控件，`+5F4C==1` | 走本地 `0x49B230/0x6BFAE0/0x4054C0/0x58B510` 和 UI virtual | 不保證有創角提交；也不宣稱一定無其它 indirect send |
| 建角名稱已輸入 | 目前無從同版 GUI name/control 正向到專用建角 wire 的 chain | 姓名字元編碼、外觀欄位、有效長度仍 U |
| 成功/重名/角色數已滿 | roster parser 可被 S2C0x2 獨立觸發 | 確切建角結果 opcode、body/enum、與 roster 的依賴 U |
| 斷線／重試／取消 | T02 transport 具獨立清理和重連語意 | 建角特有 pending/retry/idempotence/duplicate 防護 U |
| Server 有 roster N1，但 UI 未 ready | `record+0x5C` 只代表已寫入記錄 | 資源、scene、控件可見/啟用/建立交易均需另證 |

**禁止補值**：不能發明建角 opcode、重名錯誤 code、slot 或 username encoding；原版 Server 名稱唯一性/角色初值屬未知 Server policy，而 Client 欄位本身仍未知則應留作 Client 待逆向。

## 9. 完整工作邊界、可解除阻塞的證據

本輪實查：全部 raw-backed `.text` 的 direct E8 目標與各候選 xref；`0x6BF2A0` 的控件／雙路 branch 與 `0x4A38D0` builder；`CEmployNewCharacter`、`CCharChangeDialog` 兩份 MSVC RTTI/vtable；`0x4A39F0` 及 11 caller 中具不同 world/UI gate 的示例；`0x4A3720/0x682A3F`；`0x4B7DC0` first-level registration、`0x4B7EC0` generic active-scene fallback；`0x4B8920/0x4D4150` roster。**未查透全 Client indirect/vtable/message handlers，不以 direct E8 未命中證不存在。**

解除 A（Client 優先）：同版 T06 GUI pack、控制 ID、建角 name input/properties 擷取 → 實際 event/handler → C2S builder register/stack → 與之對應的 S2C handler callback 和 visible/dialog result。解除 B：取得同版本 KR 官方封包 capture（成功/重名/斷線、所有 Conn key 及解碼 frame 和 UI 時序）或原版 Server handler 源碼，用來確認真正 request/result pair。解除 C：明確標成合成測試的原版 Client+相容 Server 配對，配合函式斷點、UI event、後續 S2C0x2/本地 record 的完整 runtime trace；此只能證相容，不證原版官方時序。解除 D：再逆向間接 network send/scene handler 註冊以排除尚存的 native writer；不能以一次合成 packet 取代缺少的正向鏈。

**四項移交**：
- Client 待逆向：真正 Create C2S producer、matching S2C handler、建角結果→record/UI 正向效果。
- Server 待開發：取得 Client 契約後才做名稱衝突、建立權威、持久化、回覆策略的自訂 ADR。
- 跨功能整合：T03 主責協調 T02/T04/T06 的限定證據；RR-0002 保持 BLOCKED，RR-0009 不因本輪變動。
- 待遊玩驗證：Create 成功/拒絕/重名/取消/斷線後 roster/UI，且不能把靜態 self-audit 或 T01 source-only 當正式玩家畫面。

`GAP-CHAR-0003` 必須保持 OPEN，`SPEC-CHAR-0001`、`SPEC-FLOW-0001` 不能 STABLE；建議測試 `CREATE-UI-GATE`、`CREATE-C2S-FIELDS`、`CREATE-S2C-RESULT`、`CREATE-ROSTER-REFRESH`、`CREATE-DUPLICATE`、`CREATE-DISCONNECT-RETRY` 目前**只是待建測試建議，非既存 TEST ID**。T01 審查者可使用本輪 34 項原始 BIN 斷言腳本，限於所列正向主張；這不是 T01 FULL-PASS、RR ACCEPTED、Server 實作或可玩。

## 10. 重現方法

```bash
sha256sum Tartaros.bin Tartaros.exe
dd if=Tartaros.bin of=text.bin bs=1 skip=1024 count=$((0x7d01f0))
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x6bf2a0 --stop-address=0x6bf310 text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4a38d0 --stop-address=0x4a3900 text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4a39f0 --stop-address=0x4a3b3a text.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x4b7dc0 --stop-address=0x4b7ef2 text.bin
python 20261031-010823-chatgpt-web-roy-E71-RR0010-verify.py Tartaros.bin
```

**E71 結論**：本輪已完整保存可核對的候選與反證，但 RR-0010 的核心正向功能鏈仍受阻；遵循專案研究停止規則，提交具解除條件的 BLOCKED 原稿，而非宣稱已還原建立角色 Server 交易。