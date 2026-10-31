# KR T10-W01 — 統一輸入來源、普通攻擊／技能操作入口與玩家情境（BIN-first）

> 研究日期：2026-10-31 15:40:59 Asia/Taipei。完整 W01 專題研究（不是另起歷史 T10-121 段號）。來源版本：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（12,472,320 bytes），Tartaros.exe SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。只讀源 BIN/EXE，**未執行、附加、patch 或連線遊戲**；未使用 AI Server fixture 作原生證據。研究分支 `t10/roy/chatgpt-web`，起始 head `657ac7dc0c4736b6b8046c2bb2faf70b1ee21c35`，開工核對當時主線 `e1a3c383a046a0514f7eee983bc2fc3173c3a113`（主線當時 ahead 33；本次不自動 Merge main、不改 main）。
>
> **本次新增實證**：重讀 KR 原始鍵盤來源、Type0/Type1 對照與替代 buffer 分流；直接驗證三路單鍵／三路複合 ID → controller+5C bits；辨認原生 Mouse 與 Joypad 是不同 device wrapper；限定 `54F270` 作技能矩陣「可用性」而非施法完成。37 個獨立原生 byte asserts、12 個程式視窗 SHA256 全 PASS；附 JSON 與只讀複驗程式。不表示全部控制器型別、玩家目前 bank、UI listener、Server ACK、普攻連段及施放中取消已完整還原。

## 0. W01 研究終點與證據分級

本計畫的 W01 目標是對**有來源支持的玩家操作**建立「實體／配置輸入 producer → phase/event writer → 本地 controller input/skill predicate/queue/dispatch」的可複驗條件鏈，並逐項列出無法從目前 native 資料證實的操作狀態與來源。這與 W02 的「普攻作為技能是否共用所有 motion/action descriptor、原版 chain/cancel 窗口」以及 W03/W04 完整雙向協定不同。

- **NATIVE_STATIC_SCOPED**：本次以原始 BIN bytes/CFG/str 核對且在下述指明的先決條件下成立。
- **REUSED_PARTIAL**：T10-101/102/103/115 的限定已存證研究；不宣稱本次重新完整重驗其所有 200KB+ 附錄。
- **UNKNOWN_CLIENT**：尚未追完原生輸入/多型 listener、完整玩家狀態、動作/封包因果；沒有找到不等於否定。
- **SERVER_TO_DEVELOP**：相容 Server 的決策責任；不能當成原版 Server 的既成規則。
- **NOT_RUN**：沒有真實鍵鼠操作、遊戲執行、封包 trace 或可玩驗收。

版本限定：.text VA `0x401000`／raw `0x400`，僅 .text 使用 `raw=VA−0x400C00`；.rdata VA `0xBD2000`／raw `0x7D0600`，使用 `raw=VA−0x401A00`。FBxxxx global 多屬記憶體動態區，不能把 VA 地址套 text raw offset 去猜 runtime 值。

## 1. 物理鍵盤及配置：Z 不是固定遊戲 action ID

### 1.1 DirectInput 原始裝置已確認，但不是唯一來源

T10-102 以原生 COM/guid/descriptor 認定 `6F1430` 在 DirectInput8Create 後建鍵盤 device；`6F3820` 使用 GUID_SysKeyboard 及 256-byte DIDATAFORMAT；`6F38A0` Poll/GetDeviceState(0x100)。鍵盤 wrapper vtable +0x18 sample、+0x1C buffer getter，輸入 manager 在 `6F16B0` 迭代各 wrapper，`6F1790` 合併同索引的 pressed bytes，寫管理者 +0x60 held／+0x160 raw phase。鍵盤數字44=DirectInput DIK_Z (0x2C)，45=X、46=C、47=V；**不可**把這些 index 和 Windows `VK_Z=0x5A` 混用。

`6F16B0` 的 raw phase1/phase3 另經 `manager+0x4F8` listener 陣列呼叫各 listener vtable+0/+4；listener 具體 caller/selector 並未對所有型別閉合，不能把 release 的唯一影響視為已證「不會發送任何資料」。GetDeviceState 失敗可能沒有清舊 wrapper buffer；`6F1790` 又要求前景 HWND 對應的路徑才合併，不能假設每輪取樣都成功/即時。上述裝置生命週期主體是 T10-102 的既有有界證據，本次重新以 [`6F16B0,6F1790`]/[`6F1790,6F1A30`] 兩個 SHA 視窗和獨立 listener 指令核對。

### 1.2 真實 KR KeyMapping.xml Type0、Type1 不同

來源為 GitHub 歸檔 KR 原始資料 `kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt`，保有 `<KeyMapping DefaultType="0">`。原始 BIN `6D0935` 以 `Table/KeyMapping.xml` 取資料；`6D08F0` 解析 Type/Key 的 MapButton/Key/ModKey，3 個 bank 的 stride = 40 rows × 16 bytes = 0x280，工作 bank 可從某一來源複製/變更，不保證當前 Type0。

| 裝置鍵位置（DirectInput index） | Type0 MapButton | Type1 MapButton | 限定含義 |
|---|---:|---:|---|
| 44 (Z) | 13 | **10** | 同個 Z 實際動作取決於 bank |
| 45 (X) | 14 | 未在所引 Type1 表中直接列此鍵 | 不能自動稱 X 必對應 14 |
| 46 (C) | 15 | **11** | Type1 不同 |
| 47 (V) | 16 | **12** | Type1 不同 |
| 36、37、38、39 | 其它配置待查 | 13、14、15、16 | Type1 可能改用此一組鍵位 |

Type0 同樣允許 `MapButton=1` 多個 Key（72、200）及修飾鍵，故一個 MapButton 並不保證唯一實體鍵。初始 DefaultType=0 和曾複製到 bank2 **不能證明運行時 bank2 必然使用 Type0**；玩家改鍵/切 bank 是否已發生，需要原生其餘 writer/runtime，不能用單一預設取代。

**本次新核對原生分流**：`6D1500 cmp dword [eax+20],0`；若零，`6D1506 add eax,260h`；若非零，`6D150D add eax,60h`。此處 eax 是輸入 manager，與鍵盤 +0x60 合併路徑不同的是 **mode0 的 +0x260 buffer producer 尚未完全追到**。原生 `6F1378 mov [manager+20],1` 只確認建構初始值，不能推成永久 mode1。映射 `6D1550 mov ecx,[esi]`、`6D1554 shr eax,10h` 取配置 key/modifier；`6D157C..1589` 依裝置 buffer 輸入決定 mapped byte，不等同硬寫鍵位。

```asm
6D1500 83 78 20 00          cmp dword [eax+20h],0
6D1504 75 07                jne 6D150D
6D1506 05 60 02 00 00       add eax,260h  ; alternate buffer
6D150B EB 03                jmp 6D1510
6D150D 83 C0 60             add eax,60h   ; normal keyboard/device merge
6D1550 8B 0E                mov ecx,[esi]
6D1554 C1 E8 10             shr eax,10h
```

## 2. 映射後的 phase / UI 消耗 / 角色可操作事件

### 2.1 0/1/2/3 是當前映射命令的相鄰取樣狀態，不是連段段數

`4914AC mov ecx,0xFB8830; 4914B1 call 6D1480` 是可驗證的邏輯事件 producer 呼叫者（T10-101）。映射物件 base = FB8830，+0x7AC 的 40-byte old held，+0x7D4 的 40-byte phase，對外 phase base FB9004；`6D1915..6D19B6` 8 次 × 5 bytes = 40 個 byte，將上一輪/current held 比較，得到 `0=idle,1=press,2=hold,3=release`；`6D19CD rep movsd` 將本輪 current 傳回 previous held。

```asm
6D1915 8B 45 B8             mov eax,[ebp-48h] ; logical mapping owner
6D191B 05 D4 07 00 00       add eax,7D4h    ; phase
6D1925 8A 48 D8             mov cl,[eax-28h]  ; old held
6D1928 3A 4A FF             cmp cl,[edx-1]   ; sampled current byte
6D1930 83 C9 40             or ecx,40h
6D1933 C1 E9 06             shr ecx,6
6D193B 83 E1 02             and ecx,2        ; same-input path
6D193E 88 08                mov byte [eax],cl
6D19CD F3 A5                rep movsd         ; copy current to old
```

**容易混淆的另一 writer**：`6D19CF..6D1A0D` 遍歷 owner+0x80C/+0x810 中每筆8 bytes `{DWORD index, BYTE value, ...}`，`6D19F2 88 8C 13 D4 07 00 00` 依 index 覆寫 mapped phase。該寫入點附近沒有 index 上限檢查；但事件清單上游可能已有 gate，所以**既不承諾所有 ID 由鍵盤映射來，也不能宣稱真有越界漏洞**。尤其 ID24/25/26 可能來自此類補充 producer 或其它 writer，還沒閉合來源。

### 2.2 UI 先於戰鬥 tick 的一條正常路徑已存證

T10-101/102 中同一 `0x490FE0` 更新序列（**僅限定可達條件**）：
```text
491437 call 6F16B0          ; device sampling / raw listeners
4914AC ECX=FB8830
4914B1 call 6D1480          ; mapped phase generation
... owner virtual callbacks, UI/event stage ...
491530 call 490D40          ; consumed event IDs -> 6D4A30 partial clear
... other stage callbacks ...
491CB6 call 4E0060          ; controller tick dispatch
4E0060 -> FBA7A4 vtable+2C
  if compatible table C0FAC4 -> 548A90 -> 5452C0
```
UI 消耗邏輯事件成功且隨後清除 phase 的條件下，`54543C` 不會**因該已清除的本輪 phase**新增 bit0；但 controller+0x5C 可能已有值，別的 producer 也可設它，故**不證明該幀必不發包**。其他 UI/場景模式、早退路徑不能套用同一固定順序。

## 3. 控制器真正的「單鍵與組合 input bit」來源：本批新增的主要閉合

`5452C0` 是本段分析的角色控制器候選 tick／batch builder。在 owner+4 non-null、角色/時間等條件下，`54543C..545763` 依邏輯 phase==1 或2 把位元 OR 入同一物件 `[EBX+0x5C]`。以下 offset **皆以實際 controller 的 EBX 基址**為準，而非 KeyMapping owner：

| logical ID | phase VA (即 FB9004+ID) | 實際 native writer | OR mask | 維持與限制 |
|---:|---|---|---:|---|
| 13 | `FB9011` | `545480` | `0x0001` | 1/2，Type0 physical Key44 可映射，但 current bank 未保證 |
| 14 | `FB9012` | `5454FD` | `0x0002` | 1/2 |
| 15 | `FB9013` | `545578` | `0x0004`（SI） | 1/2，`SI` 來源需依函式內既有常數／寄存器存活 |
| 22 | `FB901A` | `5455F2` | `0x0010` | 1/2 |
| 24 | `FB901C` | `54566D` | `0x0003` | 1/2；XML Type0/1 未直接列 MapButton24 |
| 25 | `FB901D` | `5456E8` | `0x0006` | 1/2；XML Type0/1 未直接列 MapButton25 |
| 26 | `FB901E` | `545763` | `0x0005`（DI） | 1/2；`EDI` 由 `5454BF mov edi,5`，同一函式內可能的內間接影響須按 ABI 限定 |

`0x5454BF BF 05 00 00 00` 設 EDI=5，`0x545578` 使用 SI 的對應值應從 `0x5452C0` 來源確認；本次已核對 OR 指令本身，**不將寄存器字面數值以未驗證副作用跨回呼絕對化**。三種複合 ID 只是**同時存在多個 bit 的 mask**，不能稱為「連按三段」或「取消接續」。若同時多個 ID 有效，OR 可累加；最後通過的 mask 仍可能被 actor gate 改寫。

```asm
54543C 80 3D 11 90 FB 00 01 cmp byte [FB9011],1  ; ID13 press
545443 74 3B                je 545480
545477  ...                 ; 同一 byte==2 的第二 gate
545480 66 83 4B 5C 01       or word [ebx+5Ch],1
5454B8 80 3D 12 90 FB 00 01 cmp byte [FB9012],1  ; ID14
5454FD 66 83 4B 5C 02       or word [ebx+5Ch],2
545534 80 3D 13 90 FB 00 01 cmp byte [FB9013],1  ; ID15
545578 66 09 73 5C          or word [ebx+5Ch],si
5455AE 80 3D 1A 90 FB 00 01 cmp byte [FB901A],1  ; ID22
5455F2 66 83 4B 5C 10       or word [ebx+5Ch],10h
545629 80 3D 1C 90 FB 00 01 cmp byte [FB901C],1  ; ID24
54566D 66 83 4B 5C 03       or word [ebx+5Ch],3
5456A4 80 3D 1D 90 FB 00 01 cmp byte [FB901D],1  ; ID25
5456E8 66 83 4B 5C 06       or word [ebx+5Ch],6
54571F 80 3D 1E 90 FB 00 01 cmp byte [FB901E],1  ; ID26
545763 66 09 7B 5C          or word [ebx+5Ch],di
```

**差異提示**：Type0 `MapButton16 Key47=V` 不直接出現在以上 ID13/14/15/22/24/25/26 的 OR 表內，**僅證明此區間沒有 ID16→相同 mask 的直接讀取**；V 可能透過其它狀態、`547240`、mode/charge 或事件來源影響施法，不能反向聲稱 V 無效。使用者既有需求「V 點按/長按」尚待 W02、其它 producer 靜態查證。

### 3.1 Actor 與 tick 的前置、拒絕/抑制界線

```asm
5452F2 83 7E 04 00           cmp dword [esi+4],0 ; no owner -> exit
545400 83 7B 78 00           cmp dword [ebx+78h],0
545404 0F 85 73 07 00 00     jne 545B7D
545767 8B 13                 mov edx,[ebx] ; later indirect virtual+18
5457E4 39 73 0C              cmp [ebx+0Ch],esi
5457E7 0F 84 ...             je 545B7D
5457ED 39 44 24 1C           cmp [esp+1Ch],eax ; dynamic timing
5457F1 0F 86 ...             jbe 545B7D
5457F7 3B D6                 cmp edx,esi ; input/slot candidate
5457F9 0F 8E ...             jle 545B7D
545824 B8 06 00 00 00        mov eax,6
545829 BA 0A 00 00 00        mov edx,0Ah
545B38 83 3D D0 48 FE 00 06 cmp dword [FE48D0],6
545B43 76 2E                 jbe 545B73
545B71 FF D2                 call edx ; connection-manager vtable+10
```

注意 `owner+4`、`controller+78`、`controller+C`、`[esp+1C]`、`FBA7B0` 各自為**可證的條件輸入**，不能在沒有 type/producer 的證據時命名為死亡、暈眩、技能後搖、按鍵冷卻毫秒、Server 拒絕。就此 builder 而言，若早退，這段不會呼叫其 `545B71`，**不等於遊戲其它 producer 一概不送**。時間閾值由其它欄位動態決定，本函式看見 elapsed comparison 不可硬編固定 combo window。

## 4. 真正輸入與技能 predicate 的交界：同一 input mask，但不是所有技能共用已證

候選 owner vtable `0xC0F944` +0x48 `0x546100`（W00 修正已驗），先行 actor/map/control gate，再呼叫 `0x546780`：
```asm
546263 E8 18 05 00 00       call 546780
5462B4 8B 8F E8 03 00 00    mov ecx,[edi+3E8h]
5462DD E8 8E 8F 00 00       call 54F270
5462E2 85 C0                test eax,eax
5462FD BA 00 80 00 00       mov edx,8000h
546302 66 21 53 02          and word [ebx+2],dx ; gate failure with +3E8==0
5467F1 8B 55 10             mov edx,[ebp+10h] ; input WORD* pointer
5467F4 66 89 1A             mov word [edx],bx ; 實際 store，W00-007 已更正
```

`546780` 先讀 controller+0x5C，`547240` 的狀態輸出 2/3/4 轉成 mask 0x8/0x80/0x40，後依序走 `546850`、`546B50`、`546D50` 三個 collector。回傳值是 OR 合併，輸出 byte 按三路結果優先選一條；**不是**全部取第一個、也不是所有 bit 都有同一個 byte。上一次 T10-7 原稿把 `5467F1` 誤記為 WORD store，必須復用 W00 的 `5467F4` 修正，不能再次傳播錯位主張。

`54F270` 有真實原生 mask 分類，並由 `819220` 及 `81A8E0` 讀矩陣項／`54F4E0` timer map（T10-103/T11 的部分來源）：
| `AL` 條件依順序 | 被選矩陣 column | native 節點 |
|---|---:|---|
| `AL & 0xC0 != 0` | 不查、返回 true | `54F277,54F279→54F325` |
| `AL & 1 && AL & 2` | 4 | `54F28A` |
| `AL & 1 && AL & 4` | 5 | `54F297` |
| `AL & 2 && AL & 4` | 6 | `54F2A6` |
| bit0 / bit1 / bit2 | 1 / 2 / 3 | `54F2AF / 54F2B8 / 54F2C0` |
| bit3 | 7 | `54F2C8` |
| bit4 | 十進位10 | `54F2D0` |
| 其它 | 不查、返回 true | `54F2CC→54F325` |

選定矩陣 column 後，`54F2D2` 讀 record+2 的外層 key，`54F2E0` 查矩陣，`54F2F7` 讀WORD skill candidate；缺矩陣或零 key 返回false，非零時 `54F4E0` 取得 payload 並在 `54F317 cmp dword [eax+4],0;54F31A sete` 測候選 timer。**可證的是本地可用性／抑制而不是技能已開始、Client 已發特定技能 opcode、Server 允許、冷卻時間或資源已消耗**。當判斷為false、actor+3E8==0，`546302` 會清 `[row+2]` 低15位；其它條件可能保留結果，不能將任一 false 等於直接不送封包。

本段建立：**存在原生「單鍵／複合 bit → 共用本地 mask → SkillMatrix 索引 predicate → 有條件的行動 row」鏈**。但「普通攻擊和每個技能都使用同一動作 descriptor、相同 motion、相同取消窗」是 W02 **UNKNOWN**，不以研究上的統一分類取代程式事實。

## 5. Mouse／Joypad 分開實證：不把裝置存在冒充技能中移動

本次從 `6F1430` 原始多 wrapper 初始化重新查：
- `6F3980` 配置 0x1130 bytes、`6F3A80 mov eax,C4081C`，.rdata `C4081C` ASCII **Joypad**，其 wrapper+1C buffer 與鍵盤不同。
- `6F14FF` 另一個 **0x1C bytes** wrapper；`6F3E69 mov dword [esi],C424A4` 指派另一 vtable。該表 +0x4 的 `6F3ED0 mov eax,C4247C`，原始字串 `C4247C` ASCII **Mouse**，+0x10 `6F3EF0` 呼叫 DirectInput mouse CreateDevice/SetDataFormat/SetCooperativeLevel，+0x18 `6F3FA0` 處理 Poll/GetDeviceState。
- `6F3FC7 push 14h` 表明 20-byte state request；成功時 `6F403E..6F405C` 將 5×DWORD 寫 wrapper+8..+18。這是 **原生 mouse device data**，**尚未**追到「滑鼠點地移動 → 戰鬥取消」的 Player controller/movement producer，不能把 mouse button 和鍵盤戰鬥 mask 直接合稱。

```asm
6F3A80 B8 1C 08 C4 00       mov eax,C4081Ch    ; "Joypad"
6F3E69 C7 06 A4 24 C4 00    mov dword [esi],C424A4h ; Mouse wrapper vptr
6F3ED0 B8 7C 24 C4 00       mov eax,C4247Ch    ; "Mouse"
6F3FC7 6A 14                push 14h          ; mouse state bytes
6F403E 8B 4D E8             mov ecx,[ebp-18h]
6F405C 89 56 18             mov [esi+18h],edx
6F1700 0F B6 84 38 60 01 00 movzx eax,byte [eax+edi+160h] ; raw phase
6F173E 8B 02                mov eax,[edx]     ; raw press listener slot
6F174B 8B 42 04             mov eax,[edx+4]  ; raw release listener slot
```

對 W01 的有界結論：keyboard 原生輸入路徑可到 logical phase；mouse 的原生資料採樣已證，但**特定滑鼠移動／點擊的玩家意圖 consumer 未證**。Joypad 不可被誤稱 mouse。若日後查 mouse 移動需要由 +0x8..+0x18 raw state 的消費 xref 追進 Player movement producer，不能把裝置 API 的成功當成移動請求。

## 6. 玩家操作矩陣（分開 local Client／C→S／S→C／motion／責任）

| 情境 | 已知原生 Client producer/guard | C→S / S→C | 本地／遠端 motion | 已證與缺口 |
|---|---|---|---|---|
| Type0、bank實際含 Key44→ID13，按 Z | DIK44 sampled, mapped phase1→`545480 OR bit0`，受 UI/actor/tick/SkillMatrix 抑制 | **有條件** `5452C0` 的 000A app buffer→selector0 Pending→WSASend（T10-115）；專屬 S→C ACK 不明 | 動作先播或等回覆 UNKNOWN | scoped Client native |
| Type0 同一鍵持按 | phase2 亦可 OR bit0；每次 tick 是否清除重送需加上 gate/消耗 | 發包次數、頻率、一次長按產生幾 row UNKNOWN | 自動續擊/連段 UNKNOWN | 不把 hold 等於 server combo |
| 放開 Z | phase3；`54543C..545480` 的 phase1/2 gate 不新增 bit0；raw listener+4 仍可執行 | 專用 release 命令未證；不能宣稱全程零封包 | 取消/立即停止 UNKNOWN | 限定否證 |
| X、C 在 Type0 | ID14→bit1，ID15→bit2 | 可能進同一輸入 WORD；具體 skill request/ack 未閉合 | 實際技能 animation UNKNOWN | common local input bit confirmed |
| Z+X、Z+C、X+C 同時按／複合 ID24..26 | `mask3/5/6` 與 SkillMatrix column4/5/6 均存在；ID24..26 真正 producer 未閉合 | 是否一個 row、何時輸出、兩次接續 UNKNOWN | 不等於時間連段 | common mask; source gap |
| Type1 配置按 Z | Key44 在 Type1 為 MapButton10，不直接是ID13 | 是否 attack 由其它 ID10/owner rule 決定，UNKNOWN | UNKNOWN | 反證固定 Z→普攻 |
| V 短按／長按 | Type0 MapButton16=Key47；本批 controller mask table 沒有 ID16 直接 OR；其他 `547240` path 未窮盡 | UNKNOWN | charge/cancel UNKNOWN | 確定局部沒有，不能全域否定 |
| 快速連按 Z（按放按） | phase1/3/1 可能出現在不同取樣；若兩次取樣間發生無法由這條 sampled state 必然觀察 | 每次按下必一包 **未證** | chain window、段數 UNKNOWN | Input sample與時間窗口分開 |
| 施放中再按 Z/X/C | 遵循相同 input producer；actor/control gates 可能抑制，也有未查 queue/writer | 是否阻止/緩存/延後/立即發包 UNKNOWN | cancel/overwrite/queue UNKNOWN | W02/W03 |
| 普攻進行中按另一技能 | controller 共享 mask→`54F270` gated，並不足以判定合法插入 | S→C result/Client 預演 UNKNOWN | motion切換 UNKNOWN | W02/W04 |
| 施放中鍵盤移動 | KeyMapping Type0 ID1..4 方向按鍵來源可見；完整 movement producer/actor state 區分未閉合 | 移動封包與 attack row 的先後 UNKNOWN | cancel/移動 UNKNOWN | T09/T02 交界 |
| 施放中滑鼠移動/點擊 | Mouse 20-byte poll/copy **已證**；動作 consumer/導航意圖未接通 | UNKNOWN | UNKNOWN | 不與 keyboard 混證 |
| 受擊／死亡／場景切換／無角色 | 有 `controller+78`,`owner+4` 等局部 gate，尚缺其原生 runtime 狀態身分/所有 writer | 只可說該 builder 特定 early-return 無此 send | UNKNOWN | 禁止自命名 gate |
| 遠端玩家或怪物動作 | 本鏈是 local input→controller；S2C key13 的 motion 類候選由 T10-119 研究，**不是 000A ACK 已證** | 依外部下發 handler；配對因果 UNKNOWN | consumer 類型分離待 W04 | 不把遠端 NPC 當鍵盤使用者 |

## 7. 靜態因果圖與可審核 pseudocode

```text
[KR raw asset Table/KeyMapping.xml] --current Type/bank?--> [MapButton<->physical Key]
   [DirectInput Keyboard wrapper state 256]
      -> 6F16B0 sample -> 6F1790 combined held 0x60 -> raw phase 0x160
            -> raw listeners press/release (side channel; subtype UNKNOWN)
      -> 6D1480 [manager+0x20? choose +0x60 or +0x260]
            -> current working bank vector -> 40 mapped held
            -> 6D1915.. phase0/1/2/3 [FB9004..FB902B]
            -> conditional 6D19F2 override via independent list
      -> UI/owner/event consumption -> 490D40 clears selected phase
      -> 4E0060 virtual controller+2C, compatible 548A90 → 5452C0
            -> phase ID13/14/15/22/24/25/26 -> controller+0x5C OR bits
            -> actor/tick/controller+18 checks
            -> virtual+48 candidate 546100 -> 546780 input WORD/byte
            -> 54F270 SkillMatrix+timer availability predicate
            -> only if row constructed: 5452C0 C2S app 000A (6+5*N)
            -> 545B71 selector0 -> pending enqueue -> conditional WSASend
    [Mouse wrapper C424A4] → 20-byte state; player move consumer UNKNOWN
    [Joypad wrapper] → separately named; player move consumer UNKNOWN
    [S→C actual app response and local/remote motion start] UNKNOWN
```

```cpp
// W01「有界示意」，非原版 class/Server code；不假設欄位均為已知語意。
if (input_manager.mode20 != 0) raw = input_manager.held60;
else raw = input_manager.alternate260; // source not fully known
current = map_input(currentBank, raw);
phase[logicalId] = compare(previous[logicalId], current[logicalId]); // 0/1/2/3
apply_conditionally(injectedPhaseRecords); // only within actual caller/index rules
if (phase[13] == 1 || phase[13] == 2) controllerMask |= 1;
if (phase[14] == 1 || phase[14] == 2) controllerMask |= 2;
if (phase[15] == 1 || phase[15] == 2) controllerMask |= 4;
// 22=>0x10; 24=>0x03; 25=>0x06; 26=>0x05 in the checked consumer.
if (actorAndTickLocalGatesHold) {
  record = virtual_controller_48_input(controllerMask, chosenRecord);
  // skill predicate may clear lower15 of record.word;
  // a record still needs app row/size gates.
  if (appBufferLength > 6) transport_select0(appBuffer, appBufferLength);
}
```

## 8. 逐類剩餘障礙、反證與 W02/W03/W04 交接

**Client 待逆向（下一個實質靜態研究目標，不因本次交付就冒稱全功能閉合）**：
1. `6D1480` 的 mode0 +0x260 各個 writer、current Bank 的最終 writer/切換；Type1 下 Z ID10 的具體 consumer；raw listener 虛表+0/+4 各 runtime owner；`owner+80C` phase 覆寫 row 的生成者與 ID24–26 的上游。
2. actor control `controller+0x5C` reset/累加生存期，`controller+78`/actor+3E8/actor+158/actor+0x88 的具體 writer 與合法狀態集合；按下/放開於 UI 已消耗後殘留 bit 的情境；死亡／受擊／場景切換 gate 的實際 native 身分。
3. V 的單按/長按特殊狀態輸入、`547240` 及非零 phase writer；「Z 連按」與「技能施放中再按」事件時間窗、queue/replacement/motion 由下一 W02 專題深入，不在本報告填 AI 秒數。
4. Mouse wrapper+8..+18 的下游 movement/target producer、鍵盤移動不同來源，以及兩者在 cast 中的 cancel/ignore/move 發包；怪物/遠端 actor 的 S2C 來源另由 W04 結合 T08/T09。
5. C2S wire 原始 frame、selector0 実際活連線、S2C ACK/remote broadcast/local prediction；已證 `000A` 是 Client application buffer 頭、並非實際每次按鍵一對一 ACK；前述功能需 W03/W04 及 T02。

**Server 待開發（S00 接口需求，非官方 Server 內部原生主張）**：相容層需接收/解讀 Client 已證之有條件 000A batch/row、驗證 owner/action 狀態並提供必要角色動作／技能結果同步。實際 cooldown、消耗、combo/cancel window、傷害／命中策略須由 S00/T11/T12 依 Client 必要相容欄位及獨立 Server ADR 後設計；不可用 S00 Iteration29 的 mock-only ActionId/CastId、時間常數填原版 wire。

**跨功能待整合**：T02 framing/connection、T09 actor motion、T11 技能費用和冷卻、T12 命中傷害、T08 actor producer、S00 E17-E/F/G。T10 本輪只提交自己的 research，不覆寫其它 Task task.json、catalog、退回狀態或 S00 RR。

**待遊玩驗證**：一律 NOT_RUN；沒有 real-time click/keypress trace、網路抓包、動畫錄影或 Server 正式 ACK。原版 Server 內部沒有來源不阻止 Client 靜態後續研究；unknown 不當作 100% 否定。

**W01 可交付評價：** 真實來源支援的 Type0/Type1 physical key→logical ID、phase→single/composite controller mask→有界 SkillMatrix gate/000A builder 已逐段索引並補上反例；鼠標、手把的各自 device 區別已有原生位址；不完整的 current bank/listener/mode0/施放中 gate 均列具體候選入口。故完成的是**W01 的有界研究交付與缺口分流**，不是一切玩家狀態/所有輸入完整還原，更不是 W02–W04 或 T01 FULL-PASS。

## 9. 複驗索引及完整來源

- 本次精確原生附錄：[W01 audit JSON](20261031-154059-chatgpt-web-roy-T10-W01-native-byte-audit.json)（37 bytes asserts、12 x SHA256、3 .rdata 字串）；配套 [read-only verify Python](20261031-154059-chatgpt-web-roy-T10-W01-verify-native.py)。目標 BIN SHA 不符合時停止，禁止混用 TC VA；該腳本不載入/執行遊戲。
- `kr-temp-roy/20261028-1843-chatgpt-web-roy-T10-101-phase-writer-consumption-and-transport.md` blob `388d050b133af5325424391fb5eb487922f7cf5f`：phase writer、ID13+bit0、local events。
- `kr-temp-roy/20261028-1855-chatgpt-web-roy-T10-102-directinput-key44-and-battle-tick-order.md` blob `1a034ab7112645f0996266c42ed47e5d8b52aeb1`：DIK0x2C=Z、keyboard descriptor、device failures、UI-before-tick bounded schedule。
- `kr-temp-roy/20261028-1906-chatgpt-web-roy-T10-103-input-skill-matrix-and-tick-countdown.md` blob `5eda574c9d7b32c01def1cc97f0024fdb3027c2c`：mask/SkillMatrix/timer 函式和 W03 wire 界線。
- `kr-temp-roy/20261028-213024-chatgpt-web-roy-T10-115-KR-C2S000A-builder-to-pending-transport-closure.md` blob `e5de0249c0fdc0b97685e68b76921510e57aea78`：條件式 app 000A → selector0 Pending → WSASend。
- `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md` blob `bb5f5972d4d0bf0ac91bf944aeb82ffd39d00804`：不能將雙路 fifth byte 固定等同 B0，虛函式副作用及 stack alias。
- `kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt`：KR KeyMapping.xml 的 Type0/Type1 實際 Key/MapButton 對照（保留原始內容於 Git，未在本文複製全部 XML）。
- W01 新增原生資料：原始 0x6D1480/0x5452C0/0x546100/0x54F270/0x6F16B0/0x6F3E69 等函式窗口，詳細地址、bytes、SHA 以 audit 為準。重要觀察是**有條件的正常分支和已查負向 gate**；T01 後續仍需原生語意審核，沒有因一次 hash 成功而自升 FULL-PASS。
