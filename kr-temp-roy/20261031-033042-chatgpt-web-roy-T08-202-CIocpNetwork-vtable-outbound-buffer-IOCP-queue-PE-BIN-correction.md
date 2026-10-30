# T08-202 BIN-first 勘誤：FE38D0 6-byte header＋5-byte entries → CIocpNetwork slot+10 → 出站佇列／WSASend 邊界

- 研究者：chatgpt-web roy；2026-10-31 03:30:42 Asia/Taipei；KR T08，延續**未完成的正式T08-202**，不開T08-203。
- 唯一一手證據：/mnt/data/Tartaros.bin，12,472,320 bytes，SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**；未執行／未patch Client。
- PE標頭來源：.text VA 0x401000／raw0x400 → **raw=VA−0x400C00**；.rdata VA 0xBD2000/raw0x7D0600 → **raw=VA−0x401A00**；.data VA 0xD61000/raw0x95E800 → **raw=VA−0x402800**。TypeDescriptor在.data，不能套用.rdata mapping。
- 基礎：本次重新從原生PE .text切片反組譯 0x545800、0x545B38、0x8046B0、0x803D60、0x8069A0、0x8060D0、0x806060、0x8068B0；並從原生.rdata/.data核對vtable/COL/TypeDescriptor、使用PE Import Table核對KERNEL32同步與WS2_32 WSASend。本稿以新增功能鏈與更正界線為主，原T08-202全篇請讀 kr-temp-roy/20261031-005014-chatgpt-web-roy-T08-202-supplemented-bounded-static-evidence-FULL.md（保留，不改寫）；原T08-201/T01的狀態分開。
- 對照已在main發布的T01嚴格驗收與T08 README：**T01-RETURN-T08-LEGACY-MAPPING-001依然NEEDS_FIX**；本稿不是24篇原稿FULL-PASS或S00/Server驗收。

## I. 更正之前最主要的證據界線

舊202全文已證 0x491CAF→0x4E0060→controller vtable+0x2C更新 tick→pair second pass→0x545B71，但停於「[FBA854]未知manager virtual+0x10，資料未證實socket send」。此說法對舊原稿當時的證據是審慎的，**本次發現新的原生上下游後可明確縮小未知**：

1. **[0xFBA854]真正是被0x80470F賦值的0x5C-byte CIocpNetwork物件**（原生MSVC RTTI，非依函式名稱猜測）。
2. 該類別vtable **0xC51748** 的槽位 **+0x10=0x8069A0**；舊控制器0x545B66讀的也正是+0x10；可建立真正動態目標的**條件性**靜態鏈。
3. 0x8069A0在connection lookup及length gate後，實際下接 **0x8060D0**，將大小不超過0x1000的資料複製到出站緩衝節點，並用 **0x806060** 在connection+0xA074待送佇列加入節點、置connection+0xA024 pending byte。
4. 同一類別另有 **vtable +0x0C=0x8068B0**，其中PE原生指令 **0x806912:FF 15 B8 25 BD 00** 的IAT **0xBD25B8** 在原生 PE Import Table明確解析為 **WS2_32.dll!WSASend**。但這不等於「本次0x545B71所在幀已成功完成WSASend」；0x8069A0（+0x10）與0x8068B0（+0x0C）是不同虛方法，兩者的具體佇列消費call chain需另外root。
5. 本地「packet」前置不是空白：0x545824將長度初始化為**6**、0x54582E將WORD 0x000A寫入暫存、0x54584A把暫存DWORD寫至 FE38D0（至少前兩bytes為**0A 00**）、0x54588D的DWORD [F93944]寫於 **FE38D2..FE38D5** 覆蓋前述DWORD的高兩bytes。其後每個entry追加**5 bytes**。故此出站buffer的**已觀測本地格式**至少可列為 **u16(0x000A)+DWORD([F93944])+5×N**，當 N>0 才呼叫CIocpNetwork。實際wire上的外層framing／加密／補充包頭與Server語義仍由T02證據決定；此「0x000A」不可與既有**S→C本地索引10**混成同一方向的既定協定。
6. 本輪也把CIocpNetwork vtable+0x0C的**真socket呼叫者**和+0x10的**queue producer**分開寫明，以免在T08-202/跨Task T02留下「已找到WSASend就代表指定payload一定成功送出」的過度聲稱。

## II. 靜態建構與原生RTTI／vtable，每個指標有自身實際來源

~~~asm
; 0x8046D7 首先產生 0x5C byte Object，呼叫base constructor，寫入derived vptr
8046D7 6A 5C                       push 0x5C
8046D9 E8 8A CB 08 00              call 0x891268                 ; heap allocate
8046ED 85 F6                       test esi,esi
8046EF 74 10                       je 0x804701
8046F1 56                          push esi
8046F2 E8 69 F6 FF FF              call 0x803D60                  ; base ctor (vptr C51408)
8046F7 C7 06 48 17 C5 00           mov dword [esi],0xC51748     ; CIocpNetwork derived
8046FD 8B CE                       mov ecx,esi
80470A 8B 11                       mov edx,[ecx]
80470C 8B 42 08                    mov eax,[edx+8]
80470F 89 0D 54 A8 FB 00           mov [0xFBA854],ecx            ; GLOBAL owner
804715 FF D0                       call eax                       ; derived slot+8 init
~~~

- **RTTI COL位址**：vtable−4 = 0xC51744，原生DWORD 0xC812E8；COL五字組 = **0,0,0,0xF8B1E0,0xC812FC**；TypeDescriptor位址 0xF8B1E0，依.data映射 raw **0xB889E0**，TD+8是原字串 **“.?AVCIocpNetwork@@”**。CHD at 0xC812FC 內容 **[0,0,3,0xC8130C]**，3項base說明，此處未逐項宣稱型別。
- vtable原生 .rdata連續DWORD（raw vtable=0x84FD48）：
  +0 = **0x806670**（刪除析構wrapper）；+4 = **0x806CF0**；+8 = **0x806850**（實際0x804715呼叫）；+0x0C = **0x8068B0**（WSASend呼叫者）；+0x10 = **0x8069A0**（本稿出站查找／queue）；+0x14 = 0x806A00；+0x18=0x806AD0；+0x1C=0x806F60；+0x20=0x806F80；+0x24=0x806FC0；+0x28=0x807090。vtable再後為非method ASCII，不能外推。
- 清理／失效：0x803F76將[0xFBA854]寫為EBX（先前函式路徑EBX可為0，必須逐函式追踪）；0x8045EE也寫該全域，不能宣稱network指標永不更換。故「必有network this」是特定初始化後的**conditional**狀態。

## III. 前置header + five-byte entry 的原生內存佈局

~~~asm
; 源自controller 5452C0執行到545800附近。
545824 B8 06 00 00 00              mov eax,6
545829 BA 0A 00 00 00              mov edx,0xA
54582E 66 89 54 24 2C              mov word [esp+0x2C],dx
545833 8B 4C 24 2C                 mov ecx,[esp+0x2C]
54583C A3 D0 48 FE 00              mov [0xFE48D0],eax            ; length=6
54584A 89 0D D0 38 FE 00           mov [0xFE38D0],ecx            ; LE low 16=000A
545850 66 89 15 D4 38 FE 00        mov word [0xFE38D4],dx       ; pre-header overwritten later
545887 8B 0D 44 39 F9 00           mov ecx,[0xF93944]
54588D 89 0D D2 38 FE 00           mov [0xFE38D2],ecx            ; header byte +2..+5
; per eligible item, after state/distance guards:
545AEB 66 8B 56 04                 mov dx,word [esi+4]
545AEF A1 D0 48 FE 00              mov eax,[0xFE48D0]
545AF9 8D 50 05                    lea edx,[eax+5]
545AFC 81 FA 00 10 00 00           cmp edx,0x1000
545B02 77 16                       ja 0x545B1A
545B04 8B 54 24 2C                 mov edx,[esp+0x2C]
545B08 8D 80 D0 38 FE 00           lea eax,[eax+0xFE38D0]
545B0E 89 10                       mov [eax],edx
545B10 88 48 04                    mov byte [eax+4],cl
545B13 83 05 D0 48 FE 00 05        add dword [0xFE48D0],5
; after all eligible pair entries:
545B38 83 3D D0 48 FE 00 06        cmp dword [0xFE48D0],6
545B43 76 2E                       jbe 0x545B73                 ; no entries=>skip
545B49 8B 0D 54 A8 FB 00           mov ecx,[0xFBA854]           ; Network*
545B5F A1 D0 48 FE 00              mov eax,[0xFE48D0]
545B64 8B 11                       mov edx,[ecx]                ; Network.vptr
545B66 8B 52 10                    mov edx,[edx+0x10]           ; +10
545B69 50                          push eax                     ; length 6+5N
545B6A 68 D0 38 FE 00              push 0xFE38D0               ; src
545B6F 6A 00                       push 0                       ; connection id
545B71 FF D2                       call edx                     ; =>0x8069A0 when vptr C51748
~~~

**精確性限制**：正常寫入至少一次entry後，總長 **6+5N <=0x1000**。entry DWORD中各子字段可溯至先前actor pair/flags邏輯，不能僅憑4-byte store說它是完整32-bit actor key；前兩bytes來自id，後二bytes是在stack scratch與旗標運算後的狀態。本地buffer就是這些byte，沒有因看到Winsock函式就自動驗證Server如何反應、或者inbound本地索引000A是否採相同header。

## IV. CIocpNetwork+0x10 實際實作：connection lookup + bounded buffer queue

~~~asm
8069A0 55 8B EC                 push ebp; mov ebp,esp
8069A4 8B 45 08                 mov eax,[ebp+8]                ; first arg connectionId=0
8069B1 8D 4E 18                 lea ecx,[esi+0x18]            ; lookup tree inside net object
8069B7 E8 04 CF 03 00           call 0x8438C0                 ; locate connectionId
8069BC 8B 45 FC                 mov eax,[ebp-4]
8069BF 3B 46 1C                 cmp eax,[esi+0x1C]            ; sentinel end?
8069C5 8B 48 10                 mov ecx,[eax+0x10]            ; connection pointer
8069C8 85 C9                    test ecx,ecx
8069CC 33 C0                    xor eax,eax                   ; false if absent
8069D4 8B 45 10                 mov eax,[ebp+0x10]            ; length
8069D7 85 C0                    test eax,eax
8069DB B8 01 00 00 00           mov eax,1                     ; true if length=0
8069E6 8B 55 0C                 mov edx,[ebp+0xC]             ; data ptr
8069E9 50                       push eax                      ; length
8069EA 52                       push edx                      ; data
8069EB E8 E0 F6 FF FF           call 0x8060D0                 ; ECX remains looked-up connection*
8069F3 C2 0C 00                 ret 0xC
~~~

此段為**同一CIocpNetwork object**的出站介面。精確條件：connection tree找不到id或指標為NULL則返回0；length==0直接返回1；否則把 data/len 交至查得的connection*。它不能證明特定user session連線已存在，因為查找樹內容需runtime或另一個已核builder。

~~~asm
; 8060D0: this=connection*, [EBP+8]=data, [EBP+C]=len
8060F5 8B 5D 0C                 mov ebx,[ebp+0xC]
8060F8 8B F1                    mov esi,ecx
8060FA 81 BE A4 A0 00 00 2C 01 00 00  cmp dword [esi+0xA0A4],0x12C
806104 7E 16                    jle 0x80611C
806106 33 C0                    xor eax,eax                 ; guarded failure
80614F BF 58 33 FE 00           mov edi,0xFE3358            ; packet memory pool global
806154 E8 17 13 00 00           call 0x807470               ; acquire/prepare packet node
80615B 81 FB 00 10 00 00        cmp ebx,0x1000
806161 77 14                    ja 0x806177
806163 8B 45 08                 mov eax,[ebp+8]
806166 53                       push ebx                    ; len
806167 50                       push eax                    ; src
806168 8D 4F 08                 lea ecx,[edi+8]
80616B 51                       push ecx                    ; dst=node+8
80616C E8 5F 7A 09 00           call 0x89DBD0               ; memcpy-like
806174 89 5F 04                 mov [edi+4],ebx              ; node+4=len
806177 57                       push edi
806178 E8 E3 FE FF FF           call 0x806060               ; queue node
80618E C2 08 00                 ret 8
; 0x807470另有原生push0x100C，準備0x1000 byte payload capacity
~~~

**本次Controller的源長度已受0x1000上限保護**，故通常經80616C copy分支。其他呼叫者若len>0x1000，8060D0自己跳過copy與node+4寫入但仍call806060，**不能在本稿臆造這條異常路的socket語義或安全性**；應另驗callers和error policy。

~~~asm
; 0x806060 uses esi=connection* and [ebp+8]=packetNode*
806063 8B 86 D4 A0 00 00        mov eax,[esi+0xA0D4]           ; critsec
80606B FF 15 4C 22 BD 00        call [0xBD224C]              ; Import: EnterCriticalSection
806071 8B BE 74 A0 00 00        mov edi,[esi+0xA074]           ; intrusive queue sentinel
806077 8B 57 04                 mov edx,[edi+4]
806080 E8 7B 76 F4 FF           call 0x74D700                 ; link helper
8060A1 41                       inc ecx
8060A2 89 8E 78 A0 00 00        mov [esi+0xA078],ecx           ; queue count
8060A8 89 47 04                 mov [edi+4],eax               ; update next link
8060B0 8B 96 D4 A0 00 00        mov edx,[esi+0xA0D4]
8060B7 FF 15 48 22 BD 00        call [0xBD2248]              ; Import: LeaveCriticalSection
8060BD C6 86 24 A0 00 00 01     mov byte [esi+0xA024],1     ; queued/pending flag
8060C4 B8 01 00 00 00           mov eax,1
8060CB C2 04 00                 ret 4
~~~

因此 T08-202已有**原生Client sender construction→network object→connection queue**的靜態鏈，超過舊「未知manager」結論；但**仍不是OS/Server已收到packet**的可驗收證據。

## V. 真實Winsock socket送出函式：不同的CIocpNetwork slot+0x0C，須保留異步邊界

原生PE import directory由 GNU objdump -p查得：

~~~text
KERNEL32.dll  IAT 0xBD224C EnterCriticalSection; 0xBD2248 LeaveCriticalSection
WS2_32.dll   IAT 0xBD25B8 WSASend; 0xBD25BC WSARecv
~~~

~~~asm
; same CIocpNetwork vtable: C51748+0x0C = 8068B0
8068B0 55 8B EC                  push ebp; mov ebp,esp
8068B6 8B 7D 0C                 mov edi,[ebp+0xC]           ; buffer len or WSABUF target depending caller
8068BB 85 FF                    test edi,edi
8068C3 8B 55 10                 mov edx,[ebp+0x10]
8068C6 85 D2                    test edx,edx
8068CE 8B 75 08                 mov esi,[ebp+8]             ; per-connection structure
8068DE 8D 86 50 A0 00 00        lea eax,[esi+0xA050]        ; overlapped region
8068FC 89 78 18                 mov [eax+0x18],edi
806903 6A 01                    push 1                       ; buffer count
806907 8B 16                    mov edx,[esi]               ; socket HANDLE
80690A 51                       push ecx
80690B 52                       push edx
806912 FF 15 B8 25 BD 00        call dword [0xBD25B8]     ; **WSASend** confirmed imported function
806920 83 F8 FF                 cmp eax,-1                  ; socket failure/pending handling
806925 FF 15 CC 25 BD 00        call dword [0xBD25CC]     ; separate imported error function
80692D 81 FF E5 03 00 00        cmp edi,0x3E5               ; WSA_IO_PENDING (997) branch
80695E C2 10 00                 ret 0x10
~~~

slot+0x0C確實經WSASend向Winsock提交一組buffer；但CIocpNetwork vtable+0x10=8069A0的**準確指標仍透過connection tree、內存queue再更新pending flag**。另一段 0x8061A0會在connection+0xA074 list迭代處理隊列且有direct E8 callers 0x804AD6/0x805228；本輪尚未把這個queue reader的全部分支、其間接+0x0C派送與WSASend的個別buffer identity閉合。因此：

- **已證**：Client確實構造該6+5N的outgoing data，經CIocpNetwork+0x10交付其connection的出站queue。
- **已證**：同一CIocpNetwork實作另有含WSASend的真socket vmethod+0x0C。
- **尚待Client逆向**：從此packetNode經queue drain→WSABUF→WSASend的完整caller/this/size同一性、外層封裝／壓縮／加密與packet解析domain、connection id=0屬何lane、錯誤分支與生命週期。
- **不是**Server原版決策；不由outgoing本地0x000A推斷本地inbound索引000A、遊戲控制交換，亦不宣稱網路實機已成功發送。

### 補充：跨writer的T08-202狀態不能用本稿消除

這次修正的是**出站網路物件身份與可證到queue的路徑**。舊T08-202的其他Client未知依然存在：record P+4/+8其餘alias writer、命令26/81不同路徑與controller slot/owner解除一致性、特殊local owner的pair idB溯源、會話異步返回、及所有mode該tick如何被調度。T01原生退回24份source全文亦未審；**T08-202仍為階段性未完成**，不改成FINISHED、不新增203。

## VI. 可交給S00的玩家情境與真正研究邊界

|功能情境|Client靜態已確認|Client仍待逆向|Server待開發|跨功能待整合／待遊玩驗證|
|---|---|---|---|---|
|本地controller pair狀態出站|0x491CB6→4E0060派生tick→545Bxx，存header 000A/全域4bytes與5-byte entries，len 6+5N≤4096，push connectionId0+buffer+len→CIocpNetwork+10→buffer node queue|完整session/packet framing、queue drain至本buffer的WSASend、加密/pack-layer、實際序列化位序與回傳碼|相容Server需要如何解析此outgoing payload**須等T02可驗wire證據**，不能定義原版回覆策略|T02 socket/framing、T07控制器/scene、動態封包與可玩驗收|
|獨立網路類別socket實作|CIocpNetwork RTTI名稱+11-method vtable、slot+C directWSASend、slot+10 enqueue|何時drain、是否共享同一socket/connectionId0|不可由本地IOCP推官方Server規則|T01 bounded審核仍未完成|
|本地000A／26／81 actor/owner記錄|上一份202已證writer及清理窗口|P+4/P+8 alias writer、移除一致性仍欠靜態檢查|原版Server波次/仲裁不推測|T02/T06/T07/T14需按協定補證|

**後續確切原生查點**：8061A0 queue reader→807A70/807830→[Connection.vtable+0x0C] 8068B0；Connection物件由805CA0或805950配置/池化並和CIocpNetwork owner關聯；Import WSASend/WSARecv的ASYNC completion callback；本地P+4/+8寫入別名以及26/81 caller。須找原生call site和釋放條件，不能用「沒有runtime就做不到」提前停工。
