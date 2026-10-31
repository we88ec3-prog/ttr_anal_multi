# T10-W05 — KR 普攻、Z/X/C 組合技的 SkillMatrix、計時、資源判定及 T11 移交

**時間**：2026-10-31 18:26 Asia/Taipei。**原件**：KR Tartaros.bin 12,472,320 bytes、SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；KR Tartaros.exe SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f。當次 sha256sum 實際確認，唯讀 objdump Intel、機器碼與 .rdata DWORD；未執行、修改、附加、連線遊戲或抓包。PE32：.text VA=0x401000 raw=0x400，raw=VA-0x400C00；.rdata VA=0xBD2000 raw=0x7D0600，raw=VA-0x401A00。

**任務定位**：W05 是 T10 對「普攻作為一種技能」的 Client 輸入與 T11 技能可用/消耗/CD 裁決交接；不是 T11 整體完成。使用者指定本輪完成並上 git，目標 branch 為 t10/roy/chatgpt-web，不寫 main、不新增 branch。開工 main=f6eeef02dfa3704aabb45349718cc9da4b35fbe0、T10 head=6c13b5ffebcbb858b2d9f4c768be5b02d27fff83，compare ahead9/behind0，最新主線已包含所以沒有創造空 merge。讀取 AGENTS、kr/tasks/T10/{README,task.json} 的七筆 T01 退回、T11 README/task.json、research/dispatch/inbox/{T10,T11}.md、唯一 RR index、verified-knowledge 索引與 Client 修改政策；兩個 inbox 無待處理 RR。之前 W00 退回修正不改原稿、T01 尚未宣布 RESOLVED/FULL-PASS，本輪也不擅改。

## 1. 玩家輸入到矩陣的 native 證據

KR Type0 現在的有效 bank 若沿用 DefaultType0：Z Key44→logical13，X Key45→14，C Key46→15。545480/5454FD/545578 分別對 controller+0x5C 的 WORD OR 1/2/4，phase1（press）或2（held）同一路徑；Type1 或自訂 bank 不可將物理 Z/X/C 固定映射。故 Z+X mask0x03、Z+C mask0x05、X+C mask0x06（恰好這些位元有效時）；雙鍵先合併一個 action mask，並非兩個鍵各自建立一筆000A Row A/B。W03 已確認符合 controller subtype/gates 時此 mask 可存於 000A 一筆 Row A 高 WORD，但 callback/actor+58 分支可以清除，不能認定每按必送。

在候選 controller vtable C0F944+0x48→546100：
- 546263 call 546780；546791 讀 controller+0x5C WORD，5467F4 寫出 collector mask。
- 54628F..54629E 可更新 output 16-bit high WORD 的低15 bits；5462B4 讀 actor+0x3E8，5462DD call 54F270；若 predicate false，在 actor+3E8==0 等額外 gate 下，546302 將 output high WORD 低15 bits 清除。
- 5458CE Row A callback、owner+58 的可達分支、R virtual+58、實際 row append 及 FE48D0>6 都是後續輸出門檻。若滿足，才可能經 FBA854 virtual+10、selector0、Pending/framing、WSASend 發 C2S 000A；此論述不代表任何一次技能按下必定發一包。

### 1.1 54F270：一個組合 mask 選一個 matrix column

~~~asm
54F277 A8 C0             test al,0xC0
54F279 0F85A6000000      jne 54F325        ; early true bypass
54F28A B304              mov bl,4          ; bit0+bit1
54F297 B305              mov bl,5          ; bit0+bit2
54F2A6 B306              mov bl,6          ; bit1+bit2
54F2AF B301              mov bl,1          ; bit0
54F2B8 B302              mov bl,2          ; bit1
54F2C0 B303              mov bl,3          ; bit2
54F2C8 B307              mov bl,7          ; bit3
54F2D0 B30A              mov bl,10         ; bit4
54F2D5 0FB74E02          movzx ecx,word[esi+2]   ; model
54F2DB E81005ECFF        call 40F7F0
54F2E0 E83B9F2C00        call 819220       ; matrix row
54F2F7 E8E4B52C00        call 81A8E0       ; u16 matrix value
54F2FF 6685C0            test ax,ax        ; zero => false
54F310 E8CB010000        call 54F4E0       ; per-skill timer entry
54F317 394804            cmp dword[eax+4],ecx ; ECX=0
54F31A 0F94C1            sete cl
54F325 5EB8010000        pop esi; mov eax,1
~~~

Column：Z→1、X→2、C→3、Z+X→4、Z+C→5、X+C→6。mask0x07 因優先判 bit0+bit1，命中 column4，不是同時釋放三技能。bit3→7、bit4→10。若 AL 的 bit6/7 設置則在 54F279 直接 TRUE；AL=0/未辨識位也可走 54F325 TRUE，**沒查 matrix/cooldown 也能 TRUE**。所以「54F270 true = 已施放或 Server 同意」是錯誤。054F270 的正常 matrix path 查找失敗/skill u16 ID=0 才返回 FALSE；有 ID 才查 local timer remaining+4==0。

**819220**：以 model/角色 key 查 ordered matrix tree，missing→null。**81A8E0**：tier AL 必須小於4、column CL 小於11，讀 little-endian WORD[row+4 + 2*(tier*11+column)]；超出範圍回0。這是**技能 ID 或 skill-like key 的矩陣值取得**，不證業務名稱、消耗值、動畫或已施放。通用 54F270 不包含 549980 的 hero-model<=9 條件，不可混同。

直接 E8 reference（以原 BIN 的 .text raw-backed byte scan、指令邊界確認）：54F270 的四個呼叫點是 **5462DD、54827F、549C0E、549D54**。5462DD 是 546100 的 Row A local gate；54827F 是另一 actor/controller 分支；549C0E 屬 549980 SubAI skill condition；**549D54 屬另一函式 549C60**（W00-026 已勘誤）。不能把它們全當一般玩家技能施放，亦不能由僅四個 direct call 推說沒有 indirect/vtable consumer。

## 2. Timer local record：查/建、倒數、UI read 和另一路重設

**54F4E0**（VA54F4E0..54F56B）：按 DWORD key 搜索 tree node+0xC 的 key，找不到可能經 54F7D0/54F6A0 建立新項，最後返回 node+0x10（entry 指標）。它是 per-key lookup/insert，不是確定 cast 或 start cooldown。

| entry 相對 offset | 直接 native writer/reader | 有界欄位解讀 |
|---|---|---|
| +0 DWORD | 545EED 寫更新後的數值，54F330 snapshot 讀 | 起始/總量候選 |
| **+4 DWORD** | **54F317 ==0 檢查、54F217/218 逐次−1、545EF9 重設、5CE348 清0** | **Client 本地 remaining countdown** |
| +8 BYTE | 545F15 非0時設1；5CE33A 設0 | active/flag 候選 |
| +0xC DWORD | 545EE0 保存 row u16 key；54F330 snapshot 複製 | per-key value/ID 候選 |

**54F200**：545351 是唯一確認的直接 call，位於 5452C0 的三 slot tick loop。函式遍歷 timer tree node，讀 [node+0x14]（等於 entry+4），非0時 DEC1、回寫同位置；0則不減。此函式**沒有讀 timeGetTime／elapsed millisecond**，因此原生只證「每次 visit 非零 −1」，不能說1 tick=1ms/33ms/1s，也不能拿 W02 V 的500ms長按門檻當 cooldown 或普攻連段窗口。負值/溢出及 tick 間隔的全貌仍待實際 caller/初始化查清。

**54F330**：另行用 ordered tree 和 matrix tier/column 查 ID，54F41C call54F4E0，再於 54F421..434 將四個 DWORD **16 bytes** 複製給輸出 snapshot。直接 E8 callers 為5CDD2F、5CDEB0、5CE0A7（和 T11 BottomMenu/UI bounded evidence 相符），單靠這個 snapshot 不證施法或耗資。但在同 UI 家族的 5CE335/5CE343 call54F4E0 後，5CE33A 寫 entry+8=0，5CE348 寫 entry+4=0；**UI family 並非所有路徑都 read-only**，上游條件與可用性互動須由 T11 繼續追。

## 3. W05 新的實質 writer：545E20 的 8+6N 資料、÷33計算及 per-key 更新

原生 **545E20**（VA545E20..545F2A，ret12）在已驗分支從 ECX=controller-like owner、arg8=P buffer、argC=L 讀：

1. 545E2F 讀 WORD[P+2]；545E35..545E4B 走 3 個 owner+0xC+12*i actor slot，找 WORD[R+4] 相同者，找不到就直接 ret。
2. 545E5F 判 DWORD[P+4]。**非0**時：545E65..545E6F 取得相應 slot map，call597B70 clear/helper，**提前返回**；不是繼續解析 rows。這是 Client 有界清理分支，597B70 具體清什麼尚未全部審。
3. P+4==0 才解析 L：L<8 ⇒0 rows；L>=8 以 0xAAAAAAAB unsigned multiplication/shr2 得 **N=floor((L−8)/6)**。L=8→0、L=14→1、L=20→2。此布局是**目前函式輸入緩衝**，不是已確認 TCP wire/S2C opcode。
4. P+8+6*i 每筆：+0=u16 per-key identifier；+2=i32 原始 signed 數值。545EBD magic0x3E0F83E1、545EC2 signed IMUL、545EC5 SAR3、545ECD SHR31、545ED5 ADD，把數值近似（在正常 signed32 定義域）轉成**trunc(input/33)**，不是檔案中明文秒數。
5. 545ED7/EE8/EF4/F01/F10 多次 call54F4E0，為**同一 key**取得 entry：545EE0 寫 +0xC=key、545EED 寫 +0=轉換後計數、545EF9 寫 +4=轉換後計數；545F06 檢 entry+0 非0才於545F15 設 BYTE[entry+8]=1，為0的路徑未於本函式明確將 flag 清0；545F19 +6 下一筆。

~~~asm
545E2F 668B7B02          mov di,word[P+2]
545E3E 66397804          cmp word[R+4],di
545E5F 837B0400          cmp dword[P+4],0
545E6F E8FC1C0500        call 597B70        ; conditional early clear/return
545E8C B8ABAAAAAA        mov eax,0xAAAAAAAB
545E93 C1EA02            shr edx,2          ; floor((L−8)/6)
545EB0 0FB713            movzx edx,word[row]
545EBD B8E1830F3E        mov eax,0x3E0F83E1
545EC2 F76B02            imul dword[row+2] ; signed value
545EC5 C1FA03            sar edx,3
545ECD C1EE1F            shr esi,31
545ED5 03F2              add esi,edx
545ED7 E804960000        call 54F4E0
545EE0 89480C            mov [entry+0xC],ecx
545EED 8930              mov [entry],esi
545EF9 897004            mov [entry+4],esi
545F15 C6400801          mov byte[entry+8],1 ; if nonzero
545F19 83C306            add row_ptr,6
~~~

這個 input update 的 **u16 key + i32 numeric data** 與前述 local timer availability 是真實同欄資料鏈：input → set entry+4 → 54F200 decrement → 54F270 test entry+4==0 → 可影響下一次 Row A 的 mask/output gate。但**尚未證明資料從 S2C 某個 opcode 來，更不能直接稱為「官方冷卻封包」**。完整 network 入口是 T11/T02 需要的明確工作。

原件 .rdata scan 有 7 個 DWORD pointer 等於 545E20，位址 **BFB5E4、C0F984、C0F9DC、C0FA54、C0FAAC、C0FB04、C0FB5C**。其中 C0F944 +0x40 = C0F984，與 W03 候選 controller vtable 對應。全 .text E8 rel32 direct-call 545E20 命中0個——**不排除 indirect / vtable 正是主要入口**。這個證據只證函式可被此類型表間接引用，不證特定 recv dispatcher/actor instance 已經進這個 handler。

## 4. T11 的 SubAI 三欄資源檢查，與一般輸入不同

T11 已有 bounded hero/SubAI skill condition；本輪回到 BIN 確認：54AE70 的 adapter 在 54AE83 **call549980**；549980 是 SubAI condition source，**不能無證擴張到每一次玩家 Z/Z+X**。5499C0..549A1A 要求 actor+0x88 model<=9、F94304+model*0x210 hero record+0x5C 有效，取得 record+0x1F4；549A7F call819220，tier<4、column<11，取 row u16 ID 非0；549AE3 call825F70 取得對應技能條目，經 530530、5305C0、530650 建立三組有符號調整量，部分可達分支再加入另一組數值。

原生關鍵失敗路徑：

~~~asm
549BB6 8B88C8030000    mov ecx,[actor+0x3C8]
549BBC 034C2410        add ecx,[local1]
549BC0 7876            js fail
549BC2 8B90CC030000    mov edx,[actor+0x3CC]
549BC8 03D3            add edx,ebx
549BCA 786C            js fail
549BCC 8B80D0030000    mov eax,[actor+0x3D0]
549BD2 03442414        add eax,[local3]
549BD6 7860            js fail
549C0E E85D560000      call 54F270    ; after resource checks
549C13 85C0            test eax,eax
549C28 39BAE8030000    cmp [actor+0x3E8],edi
~~~

**只確認三個欄位剩餘非負檢查，沒有在上述 block 把值寫回 actor+0x3C8/0x3CC/0x3D0**；不可稱已扣HP/MP/SP（欄位名字也未證），不能用 SubAI adapter 將資源不足的 Server 拒絕直接推到玩家操作。549D54 屬獨立 549C60，可能改它的 action-state，但並非549980 的另一 caller。

## 5. 玩家情境 × 本地檢查 × C→S × S→C × 動作 × 責任

| 玩家/系統操作 | 原生 Client 已證 | C→S | S→C | 動作/角色效果 | 分工 |
|---|---|---|---|---|---|
| Type0 短按或長按 Z | phase1/2→mask1→matrix column1→timer+4 check | 000A 在 Row A/B append>0 和 selector0/queue/send 成立才可能送；不是每按一包 | 專屬 ACK 未證 | 連段/起手未知 | T10 input、T11技能 |
| Type0 X 或 C | mask2/4→column2/3，同可用性流程 | 可能000A，仍受 callback | unknown | unknown | T10/T11 |
| Z+X | mask3→column4，並非兩次單鍵技能 | 單一 Row A highWORD 候選，可能被清 | unknown | unknown | T10已證組合、T11技能名稱 |
| Z+C | mask5→column5 | 同上 | unknown | unknown | 同上 |
| X+C | mask6→column6 | 同上 | unknown | unknown | 同上 |
| matrix row 缺失或 ID=0 | 54F270 進 false | 本地 Row A 可能被清；其它 send 未排除 | unknown | unknown | 有界 Client negative |
| entry+4 非0 | 54F317 false | 不等同 Server 拒絕 | unknown | unknown | Client timer gate |
| entry+4 為0 | 54F317 true | 仍不保證發包/施放 | unknown | unknown | true不是 cast |
| bit0x40/0x80 或 mask=0 | predicate 可直接 true、未查 matrix | 不保證任何技能送出 | unknown | unknown | 重要反例 |
| 545E20 buffer 更新 | 角色 slot 符合、P+4=0、8+6N 解析、計時重新設 | 本 handler 無必然送出 | **P 來源未證為網路** | 下次可用性可變 | T11/T02 network caller待追 |
| 545E20 P+4 非0 | 597B70 helper 後提前返 | 未見 C2S | unknown | 可清理計時資料 | Client helper待審 |
| SubAI 資源不足 | 3C8/3CC/3D0 + signed adjust，js fail | 不證玩家操作被拒絕 | unknown | unknown | T11 SubAI |
| S2C key0 property4 | 特定 actor vtable可寫 actor+3E8，5462B4 下次讀 | 可能影響之後 000A | W04 部分原生 | 不等於技名/CD | T10/T11 |
| 施放中再按/移動 | W05 只閉 local gate，未閉 cast/cancel | 順序和數量未知 | unknown | unknown | T10/T09/T11 |

## 6. T11 的精確 Client 未解與 Server 相容移交

**W05 已完成的 T10↔T11 有界界面**：普通攻擊與組合鍵相同的 matrix/predicate／entry+4 檢查、timer 更新／逐次倒數、三欄 SubAI 資源先決條件的清楚分層，及原始 buffer 具體欄位。**沒有確實辨識到某個有正式名稱的玩家技能**：現有 T11 matrix 資料舉怪物1036 tier0 value 288/289/290，是怪物限定、不是玩家命名技能；沒有完整 KR CharacterMatrices/SkillMatrix.xml model0..9 及 skill-name/asset value provenance 連到單次 C2S 的證據。此點明確維持 CLIENT_UNKNOWN，不能猜技能名稱/ID。

T11待續入口：
- **Named skill**：取得 KR 真正 hero CharacterMatrices/SkillMatrix 的角色 model、tier/column、row value 與具名技能/資源對應，定向接 546100→54F270→81A8E0→54F4E0→該角色000A row。沒有這個來源不能自稱「已還原至少一個具名技能的全流程」。
- **Update buffer network origin**：追 C0F944+40 及其它6個 vtable method=545E20 的 constructor、virtual+0x40 call site/傳 P/L 的上游，和 T02 807B40/804740/4930E0 接收分類/dispatcher 是否相同。未確認前不能在 Server 生成猜測的 8+6N S2C opcode。
- **Timing units/lifecycle**：輸入 i32 除33 的實際單位、5452C0 tick 頻率、5CE33A/348 的 UI branch、+8 flag 清除/重設、重連/切場景。**33 不能直接稱33毫秒，每次54F200減1不能直接等於一幀或一秒**。
- **Resource writers**：actor+3C8/3CC/3D0 的實際變更 writer/來源，是否由 S2C property/other result 更新、真正扣除、回復及 UI；549980只是檢查，與一般玩家按鍵並無已證直接同一路徑。
- **Cast/ACK/取消**：W04的0000/000B/000C/000D未證專屬 000A ACK；應尋相同 action identity 的成功/拒絕/Server correction、motion clip、Client先播/後播、施放中連按和移動。勿用自訂 CHAIN_WINDOW=0.65 或 V 的 500ms 按鍵長按門檻取代原版連段/冷卻。

**責任分級**：Client 已確認的是 local mask/matrix/timer/resource bounded check；**Client 待逆向**是具名技能、545E20 正確 S2C 入口、resource/cooldown writer/units 與 cast response；**Server 待開發**是經 S00 審核契約後自行保存/校驗 skill identity、資源、CD 與必要同步，官方 Server 內部規則不可由 Client 原始碼直接推得；**跨功能待整合** T02/T09/T10/T11/S00；**待遊玩驗證** NOT_RUN。T01 FULL-PASS、RR ACCEPTED、SPEC STABLE、實際 Server 和 playable 絕不因本 Markdown 或 audit 自動升級。

**完成狀態**：W05 的 T10/T11 有界交接已交付，但要求「至少一個具名玩家技能」沒有來源閉合；545E20 的網路 caller 也尚未驗證，故較大的技能 cast/計時端到端問題保持**階段性未完成**。這是精確的 Client 阻塞，不是「Server 原始碼未知所以 Client 不必再查」。

## 7. 第一手重現、歷史證據與勘誤

本輪 .text E8 rel32 direct-call 候選：
- 54F200 ← 545351；54F270 ← 5462DD,54827F,549C0E,549D54；54F330 ← 5CDD2F,5CDEB0,5CE0A7。
- 54F4E0 ← 545ED7,545EE8,545EF4,545F01,545F10,54F310,54F41C,5CE335,5CE343。545E20 direct E8 hits=0，但 rdata 含七個 vtable pointer，不能視為 unreachable。
- 本目錄 native audit JSON：15 個 .text window SHA256，118 原始 byte anchors，7 個 rdata 指標；只讀 Python verifier 原件 SHA gating。這是來源一致性檢查，非所有 CFG/語意 FULL-PASS。

跨 Task GitHub 有界證據（保留原稿不改）：
- W03 combo：kr-temp-roy/T10/W03-20261031/20261031-170644-chatgpt-web-roy-T10-W03-combo-mask-row-producer-closure.md，blob 0d17362eb300ab8ea002c3d6380d5a41039665bc。
- W04 S2C：kr-temp-roy/T10/W04-20261031/20261031-172536-chatgpt-web-roy-T10-W04-S2C-receive-actor-motion-native.md，blob 8e915daab064177490d5de0b3f193810a5de2f41。
- T11 native-index/skill-flags-availability：unclassified/evidence/304161491b17c8db220ff7ec0920d5f662781931782e700ab9e9cc1de000b21e.txt，blob 7bced7b4738230006f72b745fa283f4ea1a1e27。
- T11 hero/SubAI：unclassified/evidence/0f7204eda6a341f1a3c065f6364664d95b3cdfd99c79ef393bece190e5b1ed18.txt，blob 78ad524727bff97f56e132b2ab32f0a63fc127d8。
- T11 matrix accessor：unclassified/evidence/69f69c6748f3651ee5a0c11f82eb472f0ccf1ff0d936fc34958c6f4116722c46.txt，blob 07a616aa952747cc8ffb9e9394feaafb34b56166。
- T11 matrix consumer note：kr/evidence/d90f8e9b9f64edcc6f5ae272c00365fe62c67132e51c68e1743fb52f41e3b585.txt，blob d74fb642bd8b028d8e23ddabf07ddbf12b09661a。
