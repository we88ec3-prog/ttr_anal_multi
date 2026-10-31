# KR T10-W03 — C→S 戰鬥／其它邏輯輸入訊息與傳輸端到端有界分析

日期：2026-10-31 16:57 Asia/Taipei。W03 範圍：玩家輸入 → 控制器 gate → app row/buffer → connection/queue/framing → socket，以及其它輸入訊息的分流。**研究交付已完成，總 W03 目標尚有具名技能和施放中鍵盤／滑鼠移動的 Client 來源未閉合**；請勿冒稱整個功能 FULL-PASS 或可玩。

**第一手來源**：KR Tartaros.bin，12,472,320 bytes，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；Tartaros.exe SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f。僅唯讀 objdump -D -Mintel 與原始 bytes/hash，未啟動、注入、patch、附加或連接原版。PE .text VA 0x401000/raw 0x400，raw=VA−0x400C00；.rdata VA 0xBD2000/raw 0x7D0600，raw=VA−0x401A00。FB/FE runtime globals 沒有可直接讀出的執行時值。

**開工與同步**：核對 main 5897c5058a7386686efaeb6173c8ac11bd83c78b、原 T10 head 8b3d3892fec016f751d17f400aa4f346411fb023；先依 03 規則以雙 parent merge 7c81316538e155e79ae2ebfcef22c7ca60288d66 將 main 合入 t10/roy/chatgpt-web，保留 W00/W01/W02 15 份原稿，不改 main。已讀 AGENTS、T10 task README/task.json、dispatch/inbox/T10（無待辦）、dispatch README、唯一 RR index、verified-knowledge。W00 七項原生勘誤尚待 T01 正式複驗；本稿以 W00-116 更正為準，不將舊 T10-116 被反證的 row fifth-byte 直接等同 B0。

## 一、核心成果：有原生 sender 的四個應用訊息，不等於四種技能

| app 首 WORD | 資料長度 | producer | 觸發／失敗條件 | selector | 結論與限制 |
|---|---:|---|---|---:|---|
| 000A | 6+5N（N≥1 才在此 builder 送） | 5452C0 controller / two row loops | ID13/14/15 phase1或2→mask、SkillMatrix/actor/timing/virtual row gates；沒有 row 不送 | 0 | 已證普通攻擊候選與其它戰鬥輸入可共用的 app batch；每個 row 的動作／技能身分仍未知 |
| 0022 | 7 | 54883A..548888→50C640→50CAC0 | logical ID17..20 phase1、slot/tree/actor gate、FBA798==0 | 0 | **不同 input-initiated C→S app producer**；無證據稱官方主動技能 |
| 0068 | 3 | 548918..5489B8 | logical ID28..37 phase1、mode、FBA798==0 | 0 | 索引事件，不把 1..10 當技能 ID 或連段階數 |
| 0007 | 3 | 548888..5489EC | logical ID23 phase1 及 actor state 可能設 local flag，非0且 FBA798==0 | 0 | 其它狀態事件；不冒稱技能取消、移動或結算 |

以上是 Client **app payload** 的 WORD，非外層 socket frame prefix、連線 selector、queue category 或原版 Server opcode 實作。四條都可到 manager FBA854 的 virtual+0x10；成功進入呼叫不等於 runtime socket 發送完成。這證明「所有邏輯輸入都一定只走 000A」錯誤，**沒有**證明「普攻與技能有不同的專用技能封包」。

## 二、000A 六位元組 Header 的最後寫入者：新的直接 def-use

~~~asm
545824 B8 06 00 00 00        mov eax,6
545829 BA 0A 00 00 00        mov edx,0Ah
54582E 66 89 54 24 2C       mov word [esp+2Ch],dx
54583C A3 D0 48 FE 00       mov [FE48D0],eax  ; initial len 6
54584A 89 0D D0 38 FE 00    mov [FE38D0],ecx
545850 66 89 15 D4 38 FE 00 mov word [FE38D4],dx
545887 8B 0D 44 39 F9 00    mov ecx,[F93944]
54588D 89 0D D2 38 FE 00    mov dword [FE38D2],ecx ; overwrites header +2..+5
~~~

最終 app header **offset+0:u16=0x000A**；**offset+2:u32=DWORD runtime [0xF93944]**。先前 545850 的 WORD 被 54588D 的跨 DWORD 覆蓋，不能將其當最終值，也**沒有證明 +2 是 row count、角色 ID、時間或場景**。本輪原生 literal scan 顯示 4E15E6 清 [F93944] 為零，但讀者與 runtime 間接 writer 未窮盡，故只能寫原始記憶體來源。

對 FE38D0 literal 的 .text 原始 bytes 掃描出5處 immediate（54584C、54592C、545B0A、545B6B、5471C4），FE38D2 1處（54588F），FE38D4 1處（545853）；FE48D0 的直接 literal 10處（545816、54583D、545917、545937、545AF0、545B15、545B3A、545B60、5471B1、5471D2）。**只是 hardcoded DWORD scan；沒有排除 alias、間接指標或其他 stack-based message producer。**

## 三、000A packed Row A 與 Row B：重用勘誤後的 source-to-buffer

**Row A**：545895 迴圈 3 個 owner+0xC+12*i slot，各取 R 指標與 slot enable；5458BB 讀 R+B0 到 BL，5458C4 將穩定 local S+34 作為 virtual+48 output，5458CE 呼叫 callback。virtual 返回成功及 owner+58 等條件控制是否 append；失敗可在 owner+58!=0 且 owner+6A bit15 有效時於 54598B 呼叫 **5471B0 fallback helper**。後者 5471B0/1B8/1BE 檢查 len+5<=0x1000，5471C0/1C8/1CA/1CD 寫本地 output 的 4+1 bytes 並 5471D0 更新 len。此處 fallback 不是另一 opcode，也不保證任何 row 發出。

~~~asm
5458C4 8D 44 24 34       lea eax,[esp+34h] ; stable S+34
5458C8 50                push eax
5458C9 57                push edi
5458CA 88 5C 24 20       mov [esp+20h],bl   ; ESP=S−8 -> stable S+18, NOT S+38
5458CE FF D2             call edx           ; virtual+48
5458E9 88 5C 24 38       mov [esp+38h],bl   ; only conditional branch
54590D 66 8B 46 04       mov ax,[esi+4]     ; final low WORD = R+4
54591E 81 FA 00 10 00 00 cmp edx,1000h
545930 89 10             mov [eax],edx
545932 88 48 04          mov [eax+4],cl
545935 83 05 D0 48 FE 00 05 add dword [FE48D0],5
~~~

在 owner+58==0 的正常 callback path，local highWORD/fifthByte 由 virtual+48 的 output 決定，**不可把 5458CA 說成 fifth-byte writer**。候選 C0F944 虛表的 +48=546100，在 546191 寫 out+2 WORD=0、54619B 寫 out+4 BYTE，546263 呼叫 546780 聚合 controller 輸入，5462DD 呼叫 54F270 SkillMatrix predicate；546302 可在特定失敗 gate 清 out WORD 低15位。這是共用輸入/技能 gate 到 row output 的實質接合，但 54F270 true 不代表已施法。

**Row B**：owner+30..+34 的 8-byte stride vector，5459FC 用 record+0 WORD 查 FAB13C tree，找不到 R 或 callback/flags 拒絕就不 append。545A54 初始 R+E0 DWORD，545A67/545A70 初始 fifthByte=R+E4，545A78 保存 R+B0；545A97 呼叫 virtual+44(output,record+2,R)。若回傳非零且 owner+58==0，545AA1 直接跳過 **545AC8 overwrite**，但 callback（如候選 546EF0 中 547077）仍可能改 output+4；其它可 append 分支在 545AC8 覆寫 B0，再有 R virtual+58 副作用。

~~~asm
545A67 8A 8E E4 00 00 00 mov cl,[esi+E4]
545A70 88 4C 24 30        mov [esp+30],cl
545A78 8A 9E B0 00 00 00 mov bl,[esi+B0]
545A97 FF D2              call edx       ; owner virtual+44
545AA1 74 33              je 545AD6     ; true and A+58==0 -> skips B0 overwrite
545AC8 88 5C 24 30        mov [esp+30],bl
545ADB 8A 4C 24 30        mov cl,[esp+30]
545AEB 66 8B 56 04        mov dx,[esi+4]
545AFC 81 FA 00 10 00 00  cmp edx,1000h
545B0E 89 10              mov [eax],edx
545B10 88 48 04           mov [eax+4],cl
545B13 83 05 D0 48 FE 00 05 add [FE48D0],5
~~~

可達 append 決策：
| virtual+44 | owner+58 | owner+6A bit15 | row? | caller fifth-byte 最後直接 writer |
|---|---|---|---|---|
| 非零 | 0 | 不查 | 另需 tree/len gate | 初始 R+E4，**callback 可改 output+4** |
| 非零 | 非0 | 不查 | 另需 tree/len gate | 545AC8 overwrite BL（先讀的 R+B0） |
| 0 | 0 | 任意 | 否 | 無 |
| 0 | 非0 | 0 | 否 | 無 |
| 0 | 非0 | 1 | 另需 tree/len gate | 545AC8 overwrite BL |

兩者可統一為**packed 5-byte row**：+0 u16（append 前直接 WORD[R+4]）、+2 u16（callback/本地可變 high WORD）、+4 u8（callback/本地可變 fifthByte）。**不是**「Row A=普攻；Row B=技能」，也不能把 +2 / +4 無據命名為 SkillId、heading 或 Server status。候選 vtable C0F944 +44=546EF0 的 547044 OR output+2 bit15、5470B3 OR bit1、5470BF 清 bit15，以及 547077 寫 output+4，均提供 callback 可能改資料的第一手佐證；多型實際 owner 未全窮盡。

**上限與送出門檻**：每路 append 要 len+5 <=4096；理論整數上界 N=floor((4096−6)/5)=818，不是每 tick 可執行818次技能。545B38 cmp [FE48D0],6；545B43 jbe 不呼叫 sender。多路 append 數不固定，任何一次按鍵/held 不能直接對映 1 packet 或 1 row。

## 四、0022：邏輯 ID17..20 的不同應用訊息

~~~asm
54883A cmp byte [FB9015],1 ; logical ID17
548849 push 1 / 54884D call 50C640
548852 cmp byte [FB9016],1 ; logical ID18
54885B push 2 / 54885F call 50C640
548864 cmp byte [FB9017],1 ; logical ID19
54886D push 3 / 548871 call 50C640
548876 cmp byte [FB9018],1 ; logical ID20
54887F push 4 / 548883 call 50C640
50C652 cmp byte [esi+0Ch],0 ; enabled?
50C65C cmp dword [esi+4],0 ; owner?
50C691 cmp dword [eax+8],1Ah ; alternate actor gate
50C6B9 mov ecx,22h
50C6C4 mov word [ebp-8],cx
50C6C8 mov byte [ebp-6],bl
50C6BE mov dword [ebp-5],edx ; [slot+8], unaligned packed
50C6CB call 50CAC0
50CAC0 cmp dword [FBA798],0
50CAC7 jne 50CADC             ; suppress sender, return 1
50CAC9 mov ecx,[FBA854]
50CAD1 mov eax,[eax+10h]    ; virtual sender
50CAD4 push 7
50CAD6 push edx             ; pointer to local 7 bytes
50CAD7 push 0               ; selector
50CAD9 call eax
~~~

packed payload offset+0:u16=0x0022, +2:u8=1..4, +3:u32=[16-byte slot+8]。有效輸出還需 slot/tree/actor 檢查；node+8==0x1A 等分支會額外檢查 40F060/4C9530 和 controller vtable+20；不認定每個 ID17..20 按下必送。50CAC0 若 FBA798 非0直接返回1**未送出**，不能以非0回傳視為 OS send 成功。此原生路徑有條件連到 transport，**未能識別具名技能**。

## 五、0068 與 0007：其它的 3-byte app producer

~~~asm
548918 xor ebx,ebx
54891A lea esi,[ebx+1Ch]      ; logical ID28 start
548957 movzx eax,byte [esi+FB9004]
54895E cmp eax,1             ; press only
54897E cmp dword [FBA798],0
548985 mov ecx,68h
54898A lea edx,[ebx+1]
54898D mov word [esp+14h],cx
548992 mov byte [esp+16h],dl
5489A3 push 3
5489A9 push &local3
5489AA push 0
5489AC call eax               ; FBA854 virtual+10
5489AE inc esi
5489AF inc ebx
5489B0 cmp esi,26h           ; while logical index <38 (28..37)
5489B3 jl 548920
~~~

0068 payload = u16 0x0068 + u8 (logicalID−27) = 1..10，需 caller mode gate（5488EF F9392C==4 或某些狀態模式9/6）及 FBA798==0。**沒有**證據說這10個數字是十種技能或連段階數；phase ID28..37 的上游事件可能含其它非鍵盤 producer。

~~~asm
548888 cmp byte [FB901B],1   ; logical ID23
5488A6 mov byte [esp+13h],80h ; actor+158 state and virtual gate
5489B9 mov al,[esp+13h]
5489BD test al,al
5489C1 cmp dword [FBA798],0
5489C8 mov ecx,7
5489CD mov word [esp+18h],cx
5489D2 mov byte [esp+1Ah],al
5489E3 push 3
5489E9 push &local3
5489EA push 0
5489EC call edx              ; virtual+10
~~~

0007 payload = u16 0x0007 + u8 local-state。僅確認特定 5488A6 分支可把 local 設0x80；未窮盡所有 local writer，故不是全域固定值，也不是已證取消技能、移動或傷害指令。**0022 / 0068 在此檢查 phase1；ID13 在前述 000A mask 可由 phase1 或 phase2 OR**。這是輸入 producer 的明確差異，但不是所有遊戲 input release 路徑的否證。

## 六、傳輸 manager、selector0 connection writer、queue 與 socket

所有已列 app sender 的資料指標/長度在進入 FBA854 virtual+0x10 時是參數；本輪原始 rdata pointer C51758 的 DWORD = 0x8069A0，配合已確認 constructor/vtable 類型（並非證明執行時物件永遠此型別）：

~~~asm
545B49 mov ecx,[FBA854]
545B64 mov edx,[ecx]
545B66 mov edx,[edx+10h]
545B69 push len
545B6A push FE38D0
545B6F push 0              ; selector0, not app opcode
545B71 call edx
8069B1 lea ecx,[esi+18h]  ; manager selector tree
8069B7 call 8438C0
8069BF cmp eax,[esi+1Ch]  ; sentinel
8069C5 mov ecx,[eax+10h]  ; connection
8069CC xor eax,eax        ; absent connection => return0
8069D4 mov eax,[ebp+10h]  ; data len
8069DB mov eax,1          ; len==0 => return1 without enqueue
8069EB call 8060D0       ; valid connection and nonzero len
8060FA cmp [esi+A0A4h],12Ch ; pending >300 early return0
80615B cmp ebx,1000h
806163..174 copy app bytes to pooled item+8 and store item+4=len
806178 call 806060       ; Pending List, not yet WSASend
~~~

T10-117/118 已有原生 selector tree writer：初始化 vtable+0x18 目標 806AD0 將第三 stack argument selector 放到 node+0xC、connection 到 node+0x10，與 8069A0 reader 相同 manager+0x18；4957EA 明確以 selector=0、category=2、port=0x20E0 註冊；selector2（495803）、selector1（49575B）獨立。**成功執行此初始化路徑才可能在 manager tree 有 usable selector0**；socket/IOCP/tree insert 仍有失敗分支。category2、port0x20E0 不等於 app opcode。

T10-112～114 的有界傳輸結果：8061A0 pump 使用 807A70/807830 等 mode-specific framing，通過 connection gate 後 FBA854 vtable+0xC 對應 8068B0，再到 WSASend。**本輪沒宣稱已經從這四種 app payload 各自逐 byte 還原全部 final wire frame**，也沒有 OS socket completion 或原版 Server 接受的現場證據。8060D0 這個通用 enqueue helper 有 len>4096 時跳過 copy 卻仍可能流入入列的路徑，不能硬稱通用 helper 一定拒絕；本輪四種 producer 的正常長度有明確 <=4096 guard 或常數7/3。

## 七、S→C key13 ≠ 000A ACK：W04 移交

已有 T10-119/120 的部分原生證據：Client category2 應用 key13/0x000D handler 4B01C0 以 floor((L−2)/9) 解析 9-byte rows，row 有 u16 actor lookup、u8 state、u16 word、f32 value；查 FAB138 actor tree，部分 actor vtable+0x58=4C8C30 會將 state 寫 actor+B0，並有 4C8A90 與 actor positional state 處理。**不能由 key13 的 S→C handler 存在就證明它是此次 000A 的 ACK**、伺服器已接受一個「Z 普攻」、本地動畫須等這個回覆，或所有 subclass 實作相同。詳情交 W04 分開驗證本地／遠端 actor 的 consumer。

## 八、玩家操作 × Client × C→S × S→C × Motion × 分工

| 玩家情境 | Client gate | C→S | S→C | 角色 motion | 證據／責任 |
|---|---|---|---|---|---|
| Type0 配置 Key44→logical13 短按 Z | phase1→bit0；SkillMatrix/actor/callback/timing gates | N≥1 可達 000A→Pending→conditional WSASend；**不保證每按一包** | 不明 | 本地預播/等待回覆未知 | Client native bounded；Server 判定未證 |
| Z 持按 | phase2 同 bit0 producer，可能遇到相同與新 gate | 是否持續送及每段次數未知 | 不明 | 續段窗口未知 | 不用 V 500ms 或 AI 0.65s 假值 |
| Z 放開 | phase3 不由 54543C..480 新增 bit0 | 此路徑此來源不新增，不排除其它 source | 不明 | 不明 | 有界否定 |
| X/C、雙鍵組合 | 共用 controller WORD 和 SkillMatrix column2/3/4/5/6 | 可能共用 000A row，值/數量受 gate | 不明 | 不明 | 尚無具名 Skill ID |
| logical17..20 phase1 | slot/lookup 等判斷、FBA798 | **0022 7 bytes** 可達 sender | 不明 | 不明 | 不可斷言技能施放 |
| logical28..37 phase1 | mode/index、FBA798 | **0068 3 bytes** 可達 sender | 不明 | 不明 | 事件，不等於 combo |
| logical23 + actor 條件 | local flag非零、FBA798 | **0007 3 bytes** 可達 sender | 不明 | 不明 | 未證是 cancel |
| 施放中再按普攻或技能 | 上述 phase/mask gate可能再執行；actor+158/+3E8/owner+78 動態狀態未全追 | 是否立即、丟棄、延後、入列未知 | 不明 | 可否互取消未知 | Client 待逆向＋T11/T09 |
| 施放中鍵盤移動 | W01 已確認鍵盤/Type0 direction MapButton1..4；尚無 movement producer→packet 的同一鏈 | opcode、與 cast input 先後未知 | 不明 | 取消/移動未知 | Client/T09/T02 |
| 施放中滑鼠移動 | W01 的 Mouse DirectInput 20-byte state 明確，consumer未同 actor move 打通 | opcode、是否發送未知 | 不明 | 不明 | Client 待逆向 |
| 000A 0 rows | FE48D0==6, 545B43 jbe | **這次 builder 不呼叫 sender** | 不適用 | 不推出沒有動畫 | 有界 no-send |
| selector0 缺失/queue >300 | 8069A0 lookup fail 或 8060D0 backpressure | 不入 Pending；其它 lane 不排除 | 不明 | 不明 | transport failure≠Server拒絕 |

## 九、尚未完成之精確研究入口、證據分級和 Server 交接

**Client 待逆向**：W03 原定至少一個**具名技能**從 SkillMatrix/角色變體到最後 000A row/action ID；目前只有 logical13/14/15 shared mask/SkillMatrix、以及 logical17..20 的另一 C2S 類輸入，不能將「別的按鍵」逕認「官方具名技能」。下一個靜態入口是 T11 819220/81A8E0 真實 matrix value → 546100/546EF0 out+2/+4、實際 runtime owner vtable/actor+58 及 5452C0 的 row；並核對 000A wire fields 究竟被 Server 如何解讀（原版 Server-only 不在 Client 可證範圍，但 Client 送出的欄位仍需證）。

**Client 待逆向**：施放中鍵盤／滑鼠移動要從 6F1790 鍵盤 raw/mapping，與 Mouse 6F3FA0 20-byte state 分別逆追到 actor move 封包 producer，再和 5452C0 owner+78/+C、546100 actor+158/+3E8 的狀態 writer 對照，不能把 0022/0068/0007 猜成移動。施放中再次按鍵是否吞掉、立即發送、緩衝及取消，需要接同一 actor 狀態資料；不能僅以沒有 wire capture 便叫全部 Client 證據不可研究。

**Client/T02**：把各 stack app (0022/0068/0007) 送到 8060D0 Pending 後，依實際 connection mode/multiplex 追 8061A0→807A70/807830→8068B0→WSASend 的最終 frame bytes、length/framing，並從接收反向 parser 規格驗證，不將 app WORD 直接當完整 wire header。

**Client/W04**：確認 S→C opcode/handler、local vs remote actor 以及 000A 是否為 000D 的成因；仍不得以 key13 直接稱 ACK。

**Server 待開發**：以 Client 已有的四種應用格式建立相容性分析／parser 介面，但欠實際欄位業務身分與必要回覆，不能憑空填補官方 combo/cancel window、資源與 CD、target/heading。T11 成本冷卻，T09 motion，T12 傷害，T02 網路，S00 再依既有 REQ/SPEC/GAP/ADR/TEST 去重處理。**不在本 T10 分支創建未派工 RR、改其他 Task owner、把 mock 當原生**。

**待遊玩驗證**：NOT_RUN，沒有 Client實機、socket trace、Server ACK 或角色動畫檢驗。T01 FULL-PASS、RR ACCEPTED、Server SPEC STABLE 與可玩四項狀態各自獨立。

## 十、稽核及歷史來源

同目錄機讀原生證據：W03-native-audit.json（多個 exact-VA 原生 bytes、15個固定程式視窗SHA256及一個 C51758 vtable pointer）與 read-only verify-native.py；皆要求完全匹配 KR BIN SHA，不修改或執行遊戲。

- 上游 T10-115：kr-temp-roy/20261028-213024-chatgpt-web-roy-T10-115-KR-C2S000A-builder-to-pending-transport-closure.md，Git blob e5de0249c0fdc0b97685e68b76921510e57aea78。
- T10-117：kr-temp-roy/20261028-223848-chatgpt-web-roy-T10-117-KR-selector-registration-to-000A-transport-tree.md，blob 01607b45a2decdc526063081ad6020b3d8742e0e。
- T10-118：kr-temp-roy/20261028-224346-chatgpt-web-roy-T10-118-KR-selector0-category2-connect-callers.md，blob 8f00225b580fab47b9d7964c9bdf6511047c911f。
- W00-116 correction：kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md，blob bb5f5972d4d0bf0ac91bf944aeb82ffd39d00804。不能引用被它撤回的原 T10-116「兩路 row[4] 一律 R+B0」。
- S2C T10-119 blob d44df2cf097e112ff98a78ebd918fbf9910b8952 與 T10-120 blob d0efddc90c9943bbad3bc121ad9898304f11d8ea。
- W01 blob a5d6c4ca0104e8ffba51e151169f6072f09035d4；W02 blob e8a0cedc28c28968905e914d01379915fe9dc17f。這些來源是本輪定位導航與局部交叉證據，不因本報告便把舊全文升為 FULL-PASS。

本批結論是有條件的 Client 靜態可達性及明確尚缺介面，不是原版 Server 內部規則、最終完整 wire、正式可玩流程或所有技能都共用單一 opcode 的主張。