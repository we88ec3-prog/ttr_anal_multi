# T10-W02 — 普攻作為技能：共用輸入、V 短／長按分流、SkillMatrix 與連段證據邊界（BIN-first）

研究日期：2026-10-31 16:31 Asia/Taipei。KR 原版 Client，獨立 W02 主題，不重編舊 T10-121 段號。**本稿對使用者的設計要求：在 Server 規劃和測試中，普攻就是技能的一種**；這是相容 Server 的共同抽象，不宣稱已取得原始 Client 的 C++ class/enum 名稱。使用者允許：若無法有效辨識進一步原生分歧，可在清楚記錄證據與未解界線後停止該方向深入。本次比對集中於可驗證的差異，不無限制擴張全動作系統。

## 0. 研究基準與同步

- 原始 KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本輪實際只讀計算。PE .text VA 0x401000/raw 0x400 ⇒ raw=VA−0x400C00；.rdata VA 0xBD2000/raw 0x7D0600 ⇒ raw=VA−0x401A00。
- 開工查主線 `main=e80b06d8cc7160b5624fa057c8635198fee9df29`、原工作分支 `7df328c60858961174e6c878c28cd21a1000dd9e`。因主線 ahead 44 且分歧，已建立 **真正雙 parent Git merge commit** `c6138c3f030d5b25faeb589faa6f12ab22356bb1`（parents T10 branch 與 main），保留先前 W00/W01 共12個原稿路徑，再開始本 W02。無合回 main。
- 依最新版 `AGENTS.md`、`kr/tasks/T10/{README.md,task.json}`、`kr/tasks/T11/README.md`、`research/dispatch/inbox/T10.md`、`research/requests/index.json`、共用 verified-knowledge 索引核對：**目前沒有 T10 專屬正式 RR**；W00 7件 T01 退回已有勘誤提交，但未經 T01 正式改為 RESOLVED，故本稿引用 W00 限定版本，不借用被撤回的 Row[4] 固定 B0、錯位指令與錯誤函式邊界。使用者本次指定 W02 的優先級高於重審 W00。
- 工具：原件唯讀 `objdump -D -Mintel`、原始 bytes、Python hashlib/struct、.text 有界直接 E8 rel32 搜尋；Windows import table `WINMM.dll:timeGetTime` 經 PE import 核對。**67/67 個精確 bytes anchors、9/9 原始 VA 視窗 SHA256、4 個 jump-table DWORD 全通過**。`E8` 全文字節掃描只列 direct-call 候選，不排除 indirect/vtable，亦不作全函式形式化 CFG 證明。

## 1. 核心結論：共用已證、特殊輸入差異已證、原生技能類別仍未知

| 比較項 | 同路徑證據 | 可證的差異／反例 | 結論 |
|---|---|---|---|
| 實體鍵與邏輯 action | Type0 的 DIK44 Z→MapButton13，X→14，C→15，V→16（既有 KR 配置）；Phase 0/1/2/3 由映射器產生 | Type1 或自訂 bank 可能不同；不能固定物理 Z = 官方普攻 ID | **條件共用** |
| Z 與 X/C 的本地指令 | `54543C..545578` 將 ID13/14/15 的 phase 1/2 OR 至同一 controller+5C WORD，分別 bit0/bit1/bit2；ID24/25/26 形成複合 bit mask | 不同 bit→`54F270` 不同 SkillMatrix column；「組合輸入」不等於「連段下一擊」 | **原生共用 mask；原生 column 分流** |
| 按下 Z vs **持按** Z | ID13 phase **1 或 2** 皆到 `545480 or word [ebx+5C],1`；此函式內沒有以 1/2 選不同 ID13 攻擊碼 | 一次按、持按是否每 tick 下一段仍受 timer/actor gate、row 是否追加及 motion 完成狀態制約 | **在此 producer 合流；後續 chain 未證** |
| Z 按下／持按 vs Z **放開** | 同一 ID13 phase source | phase 3 **不會由 `54543C..545480` 新增 bit0**；但 raw listener/其它 producer/舊 mask 未窮盡 | **局部分歧已證** |
| V 短按／長按 | `546780` 的 `547240` 輸出與普通 bit 合成同一 16-bit output WORD | V 是**另設 `controller+40` 狀態機**，依 ID16 phase、`timeGetTime` 及 500ms 門檻產生 bit3／bit7／bit6；不是 Z 的連段 state machine | **確定特殊輸入分歧** |
| 技能可用性 | `546263 call 546780→5462DD call 54F270`，同 WORD 可選多種矩陣 column 和 remaining timer | `AL & C0h` 直接返回 true，不查矩陣／timer；`AL=0` 也返回 true → true 不代表成功施法 | **確定 predicate 分流，不等於 action cast result** |
| 具體 action descriptor / motion | 有條件的 `5452C0` 000A 行動 row builder；W00 已修正 Row A/B/virtual callback provenance | 尚無依「BasicAttack vs ActiveSkill」判斷的已證獨立 class、motion、combo/cancel 轉換；W00 的 A/B row 是 producer 路徑，**不能命名成普攻 row／技能 row** | **尚未確認，無足夠原生反例** |
| 其他同名 predicate caller | `54F270` 可被更多 caller 使用 | `54827F`, `549C0E`, `549D54` 的本地參數及 owner 不同；後兩者屬**兩個不同函式 `549980` 與 `549C60`**（W00-026），不是直接證明普通攻擊 vs 主動技能兩類 | **多 consumer 已證，業務類別未知** |

因此 Server 的設計可先用單一 `CombatAction`／`SkillAction` 管理普攻與主動技能，**另把「輸入觸發樣式／續段規則」視為 action-specific policy**，勿將普攻在 Client 預設上獨立成專屬 opcode/class，也不要無條件把 500ms 套用為連段秒數。

## 2. 「按 Z／長壓 Z」為何在局部相同，而不能假稱連段完成

原始指令：

```asm
54543C 80 3D 11 90 FB 00 01 cmp byte [FB9011],1 ; logical ID13 press
545443 74 3B                je 545480
545477 80 3D 11 90 FB 00 02 cmp byte [FB9011],2 ; same ID13 held
54547E 75 05                jne 545485
545480 66 83 4B 5C 01       or word [ebx+5C],1
5454B8 80 3D 12 90 FB 00 01 cmp byte [FB9012],1 ; ID14
5454FD 66 83 4B 5C 02       or word [ebx+5C],2
545534 80 3D 13 90 FB 00 01 cmp byte [FB9013],1 ; ID15
545578 66 09 73 5C          or word [ebx+5C],si ; SI 既有來源=4的條件
54566D 66 83 4B 5C 03       or word [ebx+5C],3 ; composite ID24
5456E8 66 83 4B 5C 06       or word [ebx+5C],6 ; composite ID25
545763 66 09 7B 5C          or word [ebx+5C],di ; DI 既有來源=5的條件
```

這個 controller 處理的是**邏輯動作 ID 而非 physical key**；預設 Type0 的 Key44/45/46 和現在的工作 bank 不可混淆。按下的 phase1 和下一次 poll 延續的 phase2 共用 bit0 writer，但下一次 tick 是否產生新 row 取決於 `545767` virtual+18 gate、`5457A4..5457F9` controller/動態間隔比較、`545895..` Row A callback、`5459B7..` Row B tree/payload、`545B38` 是否真的 >6 bytes。這**只證連按／持按可能提供重複輸入**，不證每次按必發包、不證連段階數／切動畫時間／伺服器批准。

另外 `5452C0` 在 `54534B` 的三 slot tick 會對每個有效 record 呼叫 `54F200`（timer payload 剩餘計數減 1，非毫秒 delta）；`5457ED` 的動態比較並非固定 500ms。把 `54F200` 視為「普攻段數計時器」沒有已證依據。

## 3. 實際找到的特殊差異：V 邏輯 ID16 的輸入狀態機

這裡「V」限 **KR Type0 的 Key47→MapButton16** 及工作 bank 確實採用該映射。它和 Z 的 bit0 並不是兩套獨立施放 opcode，而是 **V 另用相位/時鐘轉換，再回到同一輸入 WORD**。

### 3.1 State 與來源從同一 BIN 直接對上

```asm
546791 0F B7 5F 5C          movzx ebx,word [edi+5C]   ; regular action mask
546795 8D 77 40             lea esi,[edi+40]         ; distinct state {state,timestamp}
5467A4 E8 97 0A 00 00      call 547240
54728E 8B 0E                mov ecx,[esi]            ; state0..3
547290 0F B6 05 14 90 FB 00 movzx eax,byte [FB9014] ; logical ID16 mapped phase
5472A0 FF 24 8D 70 73 54 00 jmp dword [ecx*4+547370]
547370 ..                  ; four little-endian DWords (below)
```

`.text` 真實跳轉表 `0x547370`（是**資料**，不能由 objdump 線性反組譯當成指令）：

| state index | jump target | 可見條件／結果 |
|---:|---|---|
| 0 | `5472A7` | phase1/2 → 取 `timeGetTime` 存 `[esi+4]`，設 state2，回傳1；其它 phase 走共用 return0 |
| 1 | `5472DB` | 另一清理／回零路徑；未證其現場生成者 |
| 2 | `5472F6` | phase3/0 → 重置 state0，**回傳2**；若仍按住且 elapsed>500ms，設 state3，**回傳3**；未跨門檻回傳0 |
| 3 | `54734B` | phase3/0 → 重置 state0，**回傳4**；持續按住則回傳0 |

精確原生短片段：

```asm
5472A7 83 F8 01             cmp eax,1
5472AC 83 F8 02             cmp eax,2
5472B5 FF 15 A0 25 BD 00   call dword [BD25A0]   ; PE import WINMM!timeGetTime
5472C0 89 46 04             mov [esi+4],eax
5472C3 C7 06 02 00 00 00   mov dword [esi],2
5472F6 83 F8 03             cmp eax,3            ; release
5472FB 3B C7                cmp eax,edi          ; edi=0
5472FF FF 15 A0 25 BD 00   call dword [BD25A0]
547305 2B 46 04             sub eax,[esi+4]
547308 3D F4 01 00 00      cmp eax,1F4h        ; 500 ms
54730D 76 4F               jbe 54735E         ; <=500 → 此次不產生長按事件
547312 BF 03 00 00 00      mov edi,3
547317 C7 06 03 00 00 00   mov dword [esi],3
547334 BF 02 00 00 00      mov edi,2
54734B 83 F8 03             cmp eax,3
547359 BF 04 00 00 00      mov edi,4
```

**重要反證**：0x1F4 比較位置在 `547240`，直接讀的是 `FB9014 = FB9004 + 16`；相對於 ID13 的 `FB9011` 不同。故已證的 500ms 是**ID16 的 V 短／長按輸入門檻**，**不是已證的 Z 普攻連段窗口、Z 自動下一擊秒數或 Server 的取消時窗**。

### 3.2 輸出映射：短放開、長按觸發、長按放開的三種不同事件

```asm
5467AD 83 E8 02             sub eax,2
5467B0 74 13                je 5467C5
5467B2 48                   dec eax
5467B3 74 08                je 5467BD
5467B5 48                   dec eax
5467B6 75 10                jne 5467C8
5467B8 83 CB 40             or ebx,40h          ; return4 -> bit6
5467BD 81 CB 80 00 00 00    or ebx,80h          ; return3 -> bit7
5467C5 83 CB 08             or ebx,8            ; return2 -> bit3
5467F4 66 89 1A             mov word [edx],bx   ; W00-007 修正後的真正 store
```

| 由 state machine 回傳 | 直接合成 mask | 有界 input 情境 |
|---:|---:|---|
| 0 或 1 | 不加上述三個 bit | 初始 press/hold 已啟動狀態但尚未產生該三類 event，或清理 |
| 2 | +0x0008 | State2 後放開/停止按住；短按路徑 |
| 3 | +0x0080 | State2 持按且經 `timeGetTime` 超過500ms |
| 4 | +0x0040 | State3 後放開/停止按住 |

這是 **事件輸入合成**，不是已證的某個 V 技能播出、技能傷害、充能堆疊次數或 Server cooldown。State machine 轉移可能受外部 state writer/reset 影響，故表述為「在所列 state 進入、phase、正常取樣前提下」。

## 4. 為何普攻與技能可作同類規劃：同一 SkillMatrix predicate，但有 fast-path

`546263 call 546780` 輸出 WORD；`5462DD call 54F270` 使用其低位 mask 和 actor+0x3E8 候選 mode，並依回傳結果可能在 `546302` 將 row+2 WORD 的低15位清空。這是**本地輸入可用性／抑制**，不是 Server 擁有技能許可的證據，也不是播放 animation 的開始信號。

`54F270` 的原生分派與 guard：

```asm
54F277 A8 C0                test al,0C0h
54F279 0F 85 A6 00 00 00   jne 54F325         ; 0x40/0x80：直接 true
54F284 74 08               je 54F28E
54F28A B3 04               mov bl,4           ; bit0+bit1
54F297 B3 05               mov bl,5           ; bit0+bit2
54F2A6 B3 06               mov bl,6           ; bit1+bit2
54F2AF B3 01               mov bl,1           ; bit0
54F2B8 B3 02               mov bl,2           ; bit1
54F2C0 B3 03               mov bl,3           ; bit2
54F2C8 B3 07               mov bl,7           ; bit3
54F2D0 B3 0A               mov bl,0Ah         ; bit4
54F2E0 E8 3B 9F 2C 00      call 819220        ; matrix lookup
54F2F7 E8 E4 B5 2C 00      call 81A8E0       ; matrix WORD candidate
54F310 E8 CB 01 00 00      call 54F4E0       ; timer payload lookup/create
54F317 39 48 04            cmp [eax+4],ecx   ; ecx=0
54F31A 0F 94 C1            sete cl
54F325 5E                  pop esi
54F326 B8 01 00 00 00      mov eax,1         ; fast-path true
```

| mask 候選 | predicate 結果的實際 source path | 限制 |
|---|---|---|
| bit0 `0x01`（ID13） | column1 的 matrix candidate，再查 timer payload+4 是否為零 | **支持把普攻當一種可經技能矩陣的 action**；並非 proof 某動畫名 |
| bit1 `0x02`、bit2 `0x04` | column2／3 | 欄值需真實 character/mode matrix；不保証每職業存在 |
| bit0+1 `0x03`、bit0+2 `0x05`、bit1+2 `0x06` | column4／5／6，優先度高於單 bit | **輸入組合**，不是歷時的 Z combo |
| V 短放開 `0x08` | column7 | 仍受矩陣/計時限制，可能無候選 |
| bit4 `0x10` | column10 | 不擴張成特定官方技能名 |
| V 長按事件 `0x80`、其放開 `0x40` | **直接 true，跳過 matrix/timer lookup** | 這是 predicate 的 gate bypass，**不是 Server 或 Client 已執行該行動** |
| `0x00` 或其它未匹配 bit | 亦可走 return true | **true 不等於有動作**：反證把所有 return1 當技能成功 |

該函式另有直接 E8 near-call 候選 `54827F`、`549C0E`、`549D54`，與本地 `5462DD` 共4處；每處上下文不同。W00 已指出 `549C0E` 位於 `549980` 函式，`549D54` 位於下一個獨立 `549C60` 函式；**不能**將 549D54 誤歸第一個函式，再宣稱同一技能 state machine。直接 E8 模式掃描不計間接呼叫，以上計數只是已檢查的 near-call 候選數。

## 5. 何時才真正可能 C→S：包與動作不等價

已核對 `5452C0` 的本地 tick 調度、各 slot/actor gate、計數門檻與兩路 row append：

```asm
5457ED 39 44 24 1C        cmp [esp+1C],eax ; 動態比較，非 500ms V threshold
5457F1 0F 86 ...           jbe 545B7D      ; local early-return
545824 B8 06 00 00 00      mov eax,6
545829 BA 0A 00 00 00      mov edx,0Ah    ; application opcode 000A
545B38 83 3D D0 48 FE 00 06 cmp dword [FE48D0],6
545B43 76 2E                jbe 545B73   ; 沒有 append row，本 builder 不進 send
545B6F 6A 00                push 0       ; transport selector，不是 app opcode
545B71 FF D2                call edx     ; vtable+10, compatible target 8069A0
```

W00 已修正第一路 row A 和第二路 row B 的第五 byte provenance：不同 callback、A+58 gate、R+E4 初始化、R+B0 local overwrite / retN。**不因同一個包內存在兩個 producer，就自動將 Row A 稱作「普攻」、Row B 稱作「技能」**；actor/record class 與 action ID 還缺對應的 evidence。此項屬 W03/W04 必須保持的 Client wire 可證界線，不能自行新增普攻獨立 opcode 或假稱 000A 是每次按鍵都會有的封包。

## 6. 操作×Client×C→S×S→C×motion×責任矩陣

| 玩家操作（都需工作 Bank/actor 前提） | Client 已證結果 | C→S | S→C | local/remote motion | 相容 Server／仍缺 |
|---|---|---|---|---|---|
| Z 短按（Type0 Key44→ID13） | ID13 phase1 可 OR bit0；SkillMatrix column1 與 timer predicate，可能被 actor gate 抑制 | 000A 的**條件式** batch row 路徑；是否此按必送未知 | 專屬 ACK unknown | 是否本地先播 unknown | 普攻當技能建模可行；時窗未知 |
| 持按 Z | ID13 phase2 亦可 OR **相同 bit0**；沒有僅因 phase2 切另一連段技能之直接證據 | 頻率／每 tick row 數 unknown | unknown | 自動下一段／動畫完成 unknown | 不設計自動 500ms combo |
| Z 快速連按 | 映射 phase1/3/1 可跨取樣週期形成，但 poll 未必每次觀測得到 | 連按 packet 次數 unknown | unknown | chain/cancel gate unknown | input-repeat policy 可先抽象，不假冒原版 |
| 放開 Z | phase3 不由 ID13 的 54543C writer OR bit0 | 其他 producer/已存在 mask／raw listener 未窮盡 | unknown | 取消/停止未知 | 不把零新 bit 誤作停招命令 |
| X/C 與雙鍵組合 | 共用 mask，依 bit1/bit2 或 col4/5/6 判本地 matrix | 仍須通過同 controller/row gate；實際發送時間未知 | unknown | 技能或複合技 motion 未配對 | 同一 action abstraction 保留不同矩陣欄 |
| V 短按後放開（Type0 Key47→ID16） | state2 遇 phase3/0 → result2 → input+0x8；matrix column7 gate | 是否有 000A row unknown | unknown | 未核對是哪個技能/動作 | 真實短按事件已證，不是某技能成功 |
| V 按住超過 500ms | state2→3、result3→input+0x80；54F270 直接 true | 真正 row/packet/技能生效 unknown | unknown | 是否蓄氣動作／UI/動畫未知 | 500ms 只能是**輸入長壓判定** |
| V 長按後放開 | state3→0、result4→input+0x40；predicate 直接 true | unknown | unknown | 未核對是否「釋放蓄氣技能」 | 不假設 cooldown 消耗／motion |
| 普攻過程按技能，或技能過程按 Z | 目前兩類按鍵可能走共用 controller，但有 actor/phase/callback gate | 是否排隊、打斷、立即送 unknown | unknown | 是否允許互取消 unknown | 不硬編 chain/cancel time window |
| 施放中鍵盤／滑鼠移動 | W01 已區分 keyboard/mouse device，movement writer 尚未接至 cast state | 各自的移動 packet/order unknown | unknown | interrupt/cancel unknown | T09/T02/T11；另 W03/W04 |
| 遠端玩家／怪物動作 | 沒有本機鍵盤操作；S2C actor consumer 另追 | 本地輸入發包不適用 | 事件格式仍待 W04 | 播放/覆蓋未知 | 不用本地 phase 代替遠端 animation |

## 7. 有界可重現模型：**設計用途**，不是 Client 或原版 Server 原始碼

```cpp
// Compatibility Server design, provisional. Not a recovered native class.
struct CombatAction {
    ActionKey key;        // Native action identity mapping still unknown
    TriggerMode trigger;  // e.g. press/hold/release; do not assign game values
    ActionPhase phase;    // server-owned / verified client-relevant where known
};
bool is_basic_attack(CombatAction const& a); // one action category, not separate wire system
// Only confirmed native client-local input examples:
// mapped ID13 press OR held -> bit0 -> SkillMatrix col1 gate;
// mapped ID16 tap release -> bit3 -> SkillMatrix col7 gate;
// mapped ID16 held >500ms -> bit7 (predicate early true);
// mapped ID16 release after held -> bit6 (predicate early true).
// Unknown: actual player combo transition/animation/interrupt authority/timing.
// Never use CHAIN_WINDOW=0.65 or V 500ms as basic attack chain window.
```

**設計建議（非已驗證原版規則）：** 保留 `BasicAttack` 在技能資料模型內，差別只透過配置的連按/長按觸發、連段序列與動作狀態策略表達。先不拆成全新獨立協定。只有找到原生 action identity/motion/cancel/wire 的實質反例，才重新評估分支。此方向與 S00 Iteration29 的 mock-only `CombatAction` 概念一致，但 **Server mock，不是 Client 封包/原版規則**。

## 8. 停止進一步深挖差異的理由（使用者明確指定）

**已有效找到一個真實差異**：V 的獨立短／長按 input state machine + 500ms 門檻 + fast-path matrix bypass；並已確認 Z press/hold 在目前 ID13 writer 合流。繼續追「普攻到底是否另有 motion/descriptor/cancel 類別」時，所檢查之 `5452C0/546100/54F270/547240` 沒有足夠 evidence 把某一行動類別分成普通攻擊專屬、主動技能專屬。這不是宣告所有 Client 架構都相同，也不是宣告永遠找不到分歧；依使用者要求**不繼續無限制掃描整個動畫/AI 系統來尋找未明確需求的差異**。

如日後 W03/W04 追到明確的不同 action descriptor、motion consumer、cancel gate、opcode 或 row provenance，自動回填本 W02 差異矩陣，並交 T11/T09 原生查證。這比用 speculative class 名或將 V threshold 假裝 Z combo 能降低 Server 實作風險。

## 9. 分工／四類缺口與交付

- **Client 待逆向（實際留待 W03/W04 或新增需求）**：Z press/repeat 的真正 combo stage 選擇、action/motion 映射、V state 和 input mask 到 000A row 的每個 callback/subtype writer、角色本地是否先播、S2C 是否 ACK/拒絕、取消窗口、技能中移動。
- **Server 待開發／S00**：統一 CombatAction 模型，按已證 Client mask/批次封包界面處理，Server 自訂連段/長壓策略的設計必須標 ADR，不能冒充官方；T11 才能補完整消耗/冷卻 Client 依據。
- **跨功能待整合**：T02 wire framing/selector、T11 skill cost/cooldown、T09 motion、T08 actor；T01 既有七退回仍按既定程序，不由 T10 自行標 `RESOLVED`。
- **待遊玩驗證**：NOT_RUN，沒有 client runtime、實際 UI 長按 500ms trace、發送封包抓取、Server 接受或動畫狀態錄影。

**W02 對此次使用者調整後目標的結論：** 共用項有 native 條件鏈；辨識出值得保留的 V 狀態機差異；對未能有效證明的「普攻和技能另一套核心結構差異」採保留未知並停止無目的深挖，轉 W03/W04 證據驅動追查。W02 比較作業交付完成；不自稱 T10/T11 全面研究已完成、T01 FULL-PASS、RR ACCEPTED 或可玩。

## 10. 證據追溯

1. 本次 [原始 BIN 67 bytes anchors / 9 SHA256 windows / V 四條跳表 / direct-call candidates](20261031-163141-chatgpt-web-roy-T10-W02-native-audit.json)，以及 [只讀重現腳本](20261031-163141-chatgpt-web-roy-T10-W02-verify-native.py)。原始全檔 checksum 和函式 bytes 不同層，不能因單個 anchor PASS 而提升 FULL-PASS。
2. `kr-temp-roy/T10/W01-20261031/20261031-154059-chatgpt-web-roy-T10-W01-input-source-to-action-gates.md` blob `a5d6c4ca0104e8ffba51e151169f6072f09035d4`，W01 的 KR Type0/Type1、DirectInput raw/phase/controller mask、UI-first normal route。
3. `kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md` blob `bb5f5972d4d0bf0ac91bf944aeb82ffd39d00804`，Row A/B callback/row[4] 修正；`W00-026` 另一函式邊界修正。
4. `kr-temp-roy/20261028-1843-chatgpt-web-roy-T10-101-phase-writer-consumption-and-transport.md` blob `388d050b133af5325424391fb5eb487922f7cf5f`；`kr-temp-roy/20261028-1855-chatgpt-web-roy-T10-102-directinput-key44-and-battle-tick-order.md` blob `1a034ab7112645f0996266c42ed47e5d8b52aeb1`；`kr-temp-roy/20261028-1906-chatgpt-web-roy-T10-103-input-skill-matrix-and-tick-countdown.md` blob `5eda574c9d7b32c01def1cc97f0024fdb3027c2c`；`kr-temp-roy/20261028-213024-chatgpt-web-roy-T10-115-KR-C2S000A-builder-to-pending-transport-closure.md` blob `e5de0249c0fdc0b97685e68b76921510e57aea78`。這些歷史文件只按有界已核實主張引用。
5. 物理鍵 config 來源：`kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt` 實際 KR XML；PE import WINMM timeGetTime 來自原件 `objdump -p`，非假設函式名稱。
