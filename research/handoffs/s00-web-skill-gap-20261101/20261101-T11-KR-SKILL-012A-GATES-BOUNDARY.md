# KR T11 — 技能可用性、012A 計時接收與伊莉西亞首戰 ID 界線（2026-11-01）

> **限定原生研究成果／階段性未完成。** 本次先完成對新手戰鬥最可供 Server 使用的 timer/availability 靜態邊界，不以資料矩陣讀取冒充施放判決。沒有執行 Client、接收正式 Server 流量或修改遊戲工作副本。本報告不是 T11 FULL-PASS／RR ACCEPTED。

## 0. 第一手與既有資料

- main baseline：`ac6aac673426459df2a778d20a80c623b8559a92`；工作卡 `research/handoffs/s00-web-skill-gap-20261101/README.md`（blob `cdfed8f0f09086f175c842ebef22ad97d2fd7c9f`，來源分支 `codex/s00-web-skill-gap-20261101`）；`kr/tasks/T11/README.md` blob `a6b1294c755802a82ad9e9f2cb366a0627d17346`。
- 原件 KR `Tartaros.bin` 12,472,320 bytes、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本次在掛載檔實算吻合。
- PE32 `.text` VA `401000` raw `400`，原始碼 `raw=VA-400C00`；工具 Python hashlib 與 LLVM 17.0.0 `llvm-objdump -d`（離線 read-only）。
- 原有部分證據：`unclassified/evidence/7bafd3143273877097a98dd0c42dc0f1c7e30719d0e86821318db4612473f89f.txt`（blob `a0a294ab559bebd5004ed5b781fdaf0f7cc865fd`；012A 最初記錄）；`kr/evidence/d90f8e9b9f64edcc6f5ae272c00365fe62c67132e51c68e1743fb52f41e3b585.txt`（blob `d74fb642bd8b028d8e23ddabf07ddbf12b09661a`）；`unclassified/evidence/304161491b17c8db220ff7ec0920d5f662781931782e700ab9e9cc1de000b21e.txt`（blob `7bced7b4738230006f672b745fa283f4ea1a1e27`）。
- `tutorial-native-skills-v19` 與 `skill-timing-fixture-audit` 均含工作副本／離線 fixture，**不是**原版 Client 的技能常數或實際封包 capture；不得作為原版 Skill ID、命中延遲、Server cooldown policy 的事實來源。現有 `Table.stp`、`Event.stp` 為 STPD 原始封裝，**未完成**解包及每筆技能／動作／特效的正式 mapping，不能假稱首戰 ID 已辨認。

## 1. 012A S→C 計時更新：實際接收與本地行為

舊來源的接收 dispatch 有 `4AE28D` 寫 `handler 4B1A00` 到 slot `+954`，對應 command `012A` 候選；`4B1A00` 經 controller vtable+40 到 `545E20`。**本次親自重查的是 `545E20..545F29` 函式原生 bytes、branch 及下述 writer**；dispatch 部分保留來源限定，未重做 T02 framing 或全部 lane 審核。下表 offset 是此 handler 可見的 app payload（不包含 socket framing）。

| offset | 物理型別 | handler 的有限作用 | 不能直接推定 |
|---:|---|---|---|
| 0 | WORD | 舊 dispatch 判讀 `012A` | 不能推出整體 network frame 格式 |
| 2 | WORD | `545E2F` 讀 actor identifier；比對 controller 3 個 12-byte slot 的 actor+4 | 不能代表任何場上 actor 都接受 |
| 4 | DWORD | `545E5F` 非零時呼叫 `597B70` 清該 actor+4 的計時 tree，之後直接 return | 不能當作「零秒冷卻」 |
| 8+6*i | WORD | `545EB0` 取一筆 skill identifier | 不能視為 Motion／Effect／TargetSkill ID |
| 10+6*i | signed DWORD | `545EBD..545ED5` 正負號處理，算 signed quotient /33 | 不能斷言是毫秒或官方冷卻秒數 |

```asm
545E2F 66 8B 7B 02             mov di,word [ebx+2]     ; actor
545E35 8D 51 0C                lea edx,[ecx+0C]
545E3E 66 39 78 04             cmp di,word [eax+4]     ; 3槽匹配
545E48 83 FE 03                cmp esi,3
545E5F 83 7B 04 00             cmp dword [ebx+4],0
545E6F E8 FC 1C 05 00          call 597B70             ; reset 分支
545E7D 8B 45 0C                mov eax,[ebp+0C]       ; payload length
545E89 8D 50 F8                lea edx,[eax-8]
545E8C B8 AB AA AA AA          mov eax,0AAAAAAABh      ; floor((len-8)/6)
545E93 C1 EA 02                shr edx,2
545EB0 0F B7 13                movzx edx,word [ebx]
545EBD B8 E1 83 0F 3E          mov eax,3E0F83E1h     ; signed /33 magic
545EC2 F7 6B 02                imul dword [ebx+2]
545EC5 C1 FA 03                sar edx,3
545ECD C1 EE 1F                shr esi,31
545ED5 03 F2                   add esi,edx            ; trunc toward zero
545ED7 E8 04 96 00 00          call 54F4E0
545EE0 89 48 0C                mov [eax+0C],ecx      ; skill id
545EED 89 30                   mov [eax],esi         ; total
545EF9 89 70 04                mov [eax+4],esi       ; remaining
545F15 C6 40 08 01             mov byte [eax+8],1    ; only total != 0
545F19 83 C3 06                add ebx,6
```

**Gates/結果：** actor 不在三個主要 slot 時不更新此 actor；reset 非零時直接清 tree、不處理 rows；正常 count=`floor((len-8)/6)`；少於 8-byte header 沒有 row；每個 row 的 signed value 除以 33 後寫 total +0、remaining +4、skill id +0C，total 不為 0 時將 +8 flag 設 1。尚未見到 map entry 存在時如何由 0 值清 flag 的全面副作用，不能假造 reset/visibility 規則。

### 1.1 本地倒數與可用性不是 Server 對施放的允許

```asm
54F200 8B 50 08                mov edx,[eax+8]
54F210 8B 41 14                mov eax,[ecx+14]     ; tree node 的 remaining
54F213 85 C0                   test eax,eax
54F217 48                      dec eax
54F218 89 41 14                mov [ecx+14],eax
54F270 55                      push ebp
54F277 A8 C0                   test al,0C0h        ; 早回可用分支
54F2D2 8B 45 08                mov eax,[ebp+8]
54F2D5 0F B7 4E 02             movzx ecx,word [esi+2]
54F2E0 E8 3B 9F 2C 00          call 819220         ; matrix row lookup
54F2F7 E8 E4 B5 2C 00          call 81A8E0         ; tier/key lookup
54F310 E8 CB 01 00 00          call 54F4E0         ; timer entry
54F317 39 48 04                cmp [eax+4],ecx    ; remaining zero?
54F31A 0F 94 C1                sete cl
54F325 5E                      pop esi             ; special allow branch
54F326 B8 01 00 00 00          mov eax,1
```

- `54F200` 沿既有 tree 走訪，對非零 remaining 每次 controller 更新減 1；**每秒更新幾次未知**，不能將 `/33` 視作穩定的 seconds 換算。
- `54F270` 為 availability predicate。依 flags 的分支優先序，`1/2/4 → key1/2/3`、`3/5/6 → key4/5/6`、`bit8 → key7`、`bit10h → key0Ah`；含 `0C0h` 或未識別組合可能直接 return 1，不能一律當成跳過 Server cooldown。
- 進矩陣查詢、`54F4E0` 後對 `entry+4==0` 回可用；這是 **Client gate 或 UI/AI 檢查的本地條件**，不是已證明的本機/官方發包時刻。
- 先前 `54F330` 只做 16-byte 計時 snapshot 供 UI 候選；不能將讀取器當成更新器。

## 2. 技能矩陣與 SubAI：明確否證怪物／技能決策的錯誤泛化

本輪原生 `549980..549C4F` 對應舊 `SKILL-MATRIX-CONSUMERS.md` 的有界 helper：

```asm
5499AC mov eax,[ebp+8]
5499AF mov eax,[eax+50h]        ; actor/context pointer
5499C0 movzx edi,word [eax+88h]
5499F4 cmp edi,9
5499F7 ja 549A20               ; model >9 不走該 hero 查表
549A01 imul esi,esi,210h       ; per-hero record
549A7F call 819220             ; matrix lookup
549A8F cmp dl,4
549A9B cmp cl,0Bh
549AAF movzx edi,word [eax+edx*2+4]
549AB4 test di,di
549BBC add ecx,[esp+10h]       ; candidate status/resource sum
549BC0 js 549C38
549BC2 mov edx,[eax+3CCh]
549BC8 add edx,ebx
549BCA js 549C38
549BCC mov eax,[eax+3D0h]
549BD2 add eax,[esp+14h]
549BD6 js 549C38
549C0E call 54F270
549C13 test eax,eax
549C4E ret 10h
```

- `model<=9`、record stride `210h`、tier/key bounds 和技能矩陣 WORD lookup 是**本條 helper 的 Client local gates**；沒有證據表明此 helper 是所有角色／技能的唯一施放入口，更不能把它套給怪物 1036 的出招決策。
- `actor+3C8/3CC/3D0` 及三次 signed-negative guard 顯示有額外數值門檻；因屬前置累計／多個 helper 輸出，**尚不能定義為 Mana、SP、MP 之成本、公式或實際扣款 writer**。對 T11 可推導「存在條件」，對 Server **不可硬編為官方資源消耗公式**。
- `549C60` 是與 `549980` **獨立的新函式入口**；`549D54` 的 `54F270` 呼叫屬後者。這是 T10 T01-RETURN-T10-026 已要求更正的 caller 區別，不得再把全部 call 合併。

## 3. 首戰伊莉西亞技能：ID 不混用

工作卡列出的 `101…107`、`108/109`、`49/50/52` 為**待查候選**，本次沒有可驗證的角色→已學技能→preset/slot→Skill ID→motion→effect→target-skill 全鏈；因此不宣稱這些是伊莉西亞官方 X/V/Z 或初學技能 ID。原 `Table.stp`／技能資源的正式解包、專屬角色與版本驗證，及 native dispatch/actor motion caller 還未閉合。尤其 `TargetSkill ID != Motion ID` 是避免錯配的型別界線，不將不同 domain 的相同整數推成同一概念。

| ID 類型 | 已證資料位置／來源 | 能否拿來實作 |
|---|---|---|
| `012A` payload skill WORD | `545EB0` 接收 row+0、`545EE0` 寫本地 timer entry+0C | **可**保留 16-bit 欄位與計時更新，具體技能對應仍待查 |
| matrix skill WORD | `549AAF` 的 `matrix+4+2*(tier*11+key)` | **可**辨識為查表輸出；不得擅定為 motion 或 client C2S 技能編碼 |
| player slot/preset learned skill | 本次尚未追齊源頭與 consumer | **不可**自訂官方編號 |
| motion / effect / TargetSkill | 相關 S2C/資源鏈未於本輪閉合 | **不可**互相代換 |

同樣，交接工作卡所記 `0D` float 有**動畫速度倍率的限定舊證據**，不是本輪從原始 BIN 重新核對的開始時間；禁止令 float=0 以自稱凍結或控制施放起始。其精確 handler/struct、actor motion 仍須在 T09/T11 對照。

## 4. Server-ready 有限資料矩陣

| 玩家／Server 情境 | 輸入或觸發 | Client gate／writer | 輸出／clock | 已知／未知責任 |
|---|---|---|---|---|
| 角色已有技能且按技能鍵 | 角色、preset/slot、輸入 phase | SubAI hero `549980` 部分有 matrix/tier/key/數值/remaining gates | **C→S skill opcode/bytes/時序未證** | Server 施放裁決、角色 learned list、成本/取消條件尚未確認 |
| Server 下發技能倒數 | `012A` actor + reset + 6-byte rows | `545E20` actor 三槽比對；reset 或更新 tree | signed count /33 寫 total/remaining；`54F200` 每更新減 1 | **已證 Client 消費介面**，後端何時發送、秒數/頻率與權威決策未證 |
| 冷卻中／已歸零 | `54F270` matrix lookup + timer entry | 限定 flags branch，entry+4==0 才可用；特殊 branch 直回1 | 本地 Boolean | 不足以說明 Server 是否接受、是否可連擊或技能互斥 |
| 其他玩家或怪物施放 | 接收 app 動作資料 | 共用 actor motion 尚需 T09/T08 交界 | 畫面動作、Hit/Target ID 尚未閉合 | 未確認官方動作開始時間、命中、傷害與廣播 |
| 首戰伊莉西亞按 X／V | 候選 skill/motion/target 多域 | 首戰角色定位、已學技能表、原生 slot mapping 未核 | **不可輸出確定官方 ID** | 待精確 STP／DB 原件與封包/handler 補證 |

## 5. 正流程檢查與後續工作

**可立即採用作相容接口的有限事項（非原版 Server 規則）：**
1. 保留 `012A` app payload 的 actor WORD、reset DWORD、skill WORD + signed value DWORD 的定長列，先核對 framing/actor slot 與發送時機；不要直接把畫面 cooldown 當伺服器冷卻裁決。
2. 讓 Server 與 UI 的 cooldown state 可分開表示；Client 的計數更新本身存在，卻**不**決定官方技能冷卻長度。
3. 首戰 happy-path 驗收先看「原版 Client 有正確已學技能/preset → 按鍵 gate → 出動作 → 正確計時狀態」，不要混入傷害公式、PVP、重送、故障壓測。

**Client 待逆向：** (a) 首戰伊莉西亞的 matrix／learned list／slot／preset 及技能 ID 來源；(b) normal C→S 技能 request builders／實際 socket，是否與 T10 000A rows 共用；(c) S→C 0D actor motion 的 motion/effect/target 關係；(d) skill 開始/結束、施放中再次輸入與鍵盤/滑鼠移動 gate，按 release/hold 與 animation event/clock 分段追；(e) `012A` handler 的完整 framing、何種 Server 事件更新及 UI reader 刷新頻率。

**Server 待開發／自行決策：** cooldown 資料政策、可施放驗證、資源扣款、技能與連段互斥、怪物出招/波次；不能假稱是官方原版常數。**跨功能待整合：** T02 framing、T04 learned skills/初值、T09 motion、T10 input、T12 damage、T14 tutorial battle。**待遊玩驗證：** 尚無本工作所產出的官方 S↔C 實測、遊玩 trace 或首戰新驗收；異常／重送／併發／安全／壓測**僅列待測，不在此工作執行**。

## 6. 可重現原始機器碼視窗

| 用途 | VA 半開範圍 | bytes | SHA256（BIN 實際重新計算） |
|---|---|---:|---|
| `012A` controller handler | `545E20..545F29` | 265 | `5001977eb515729a846cf24e4d6be76ace6644ac6c8da0c9d365739f66e0fc08` |
| 本地剩餘 count 減一 | `54F200..54F267` | 103 | `977731b2d09a4d9ae74f41c48f9b004b246607d1e4cb16bef5077f9544d8f9d5` |
| skill flag + matrix availability | `54F270..54F32E` | 190 | `977d4ddb33d52769fb63f3661db57651548fcb38057ff86f046c799d2823a999` |
| hero-only SubAI gates | `549980..549C4F` | 719 | `a20410dbf2495b8172aab9c6c99d328c0e4d84c05f9e5b8cf89d9ed724863537` |

重現：對 `Tartaros.bin` 用 `start_raw = start_VA - 0x400C00`，`hashlib.sha256(data[start_raw:start_raw+(end-start)])`。位元組符合≠整篇語意 FULL-PASS。現無可供官方 Server 用的首戰技能完整 101～109 mapping、冷卻秒數、資源扣款或 cancel window，因此**本任務階段性未完成**。
