# KR T10-W03 補完：Z+X／Z+C／X+C 的輸入合成、SkillMatrix、000A Row A/B 實際關係

**日期**：2026-10-31 17:06 Asia/Taipei。**使用者的本次修正**：「目前技能操作能 Z+X／Z+C／X+C；原 W03 說兩條紀錄產生路徑可合併進同一封包，應該就是這部分。」本稿不把這句推測直接改寫為 Client 事實，而以 KR 原始 BIN 判別 **雙鍵輸入合成** 與 **兩條封包紀錄 producer** 是否為同一層。原 W03 及 W00-116 勘誤不覆寫，新檔為原生證據增補和明確修正。

**最終結果：雙鍵會先以 bit 合併、選定 SkillMatrix 欄位；000A 的 Row A 和 Row B 是另一組互不等同於 Z/X/C 的物件與條件式紀錄來源。已找到在 Row A 特定分支中直接承載兩鍵 mask 的條件式 writer。這反證「兩個按鍵各對應一筆 Row A/B」的必然結論。** 目前並不宣稱已完整解析原版 Server 收到後選擇哪個技能／是否成功發動。

## 0. 第一手、同步、審核基準

- KR 原始 **Tartaros.bin**，大小 12,472,320，SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**；EXE SHA256 **03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f**。本輪唯讀 checksum、GNU objdump Intel、原件 raw bytes 和 little-endian vtable；沒有執行、patch、注入、連線原版遊戲或 socket capture。
- PE32 .text VA=0x401000/raw=0x400，.text raw=VA−0x400C00；.rdata VA=0xBD2000/raw=0x7D0600，.rdata raw=VA−0x401A00；FB/FE runtime globals 不得從檔案 raw 硬猜值。
- 本輪檢查主線 **5897c5058a7386686efaeb6173c8ac11bd83c78b**、T10 分支 **23b1b0e6b32c8865fd48a0611b3e871b09a01ee7**，比較結果為 branch ahead 6、behind 0；先前 W03 已合入最新 main，**本次無需新 Merge**。無開新 branch，不改 main。
- 已核對 AGENTS.md、T10 README/task.json 的 7 筆 T01 退回、research/dispatch/inbox/T10.md（無待處理 RR）、research/requests/index.json（無 T10 指派）、shared/verified-knowledge/README.md 和 Client 修改政策。本輪依使用者明確指定 W03 組合技優先，先前 7 項 T01 勘誤保留原狀由 T01 複驗；**不能自行宣稱 RESOLVED 或 FULL-PASS**。
- 機讀驗證：同目錄 **W03-combo-native-audit.json** 和 **verify-native.py**。本輪實際對原檔驗過 77/77 指令原始 bytes、8/8 連續 code SHA256 範圍、3/3 C0F944 vtable pointers 及 4 個依原生指令順序建立的純符號測例。這不等於 runtime 測過 Z+X 動畫／真正 Server 接受。

## 1. 先界定 Z/X/C 在哪個 keymap 成立

已存 KR KeyMapping.xml 證據，原始 repo **kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt**（Git blob **cb8a9da734567b10e37cc966a981300cb3e7b8bc**）：

- **Type idx=0 / DefaultType=0**：Key44 (DIK Z) → MapButton13；Key45 (X) → MapButton14；Key46 (C) → MapButton15；Key47 (V) → MapButton16。
- **Type idx=1**：Key44→MapButton10、Key46→11、Key47→12，MapButton13/14/15/16 改由 Key36/37/38/39 映射。自訂鍵位／目前工作 bank 仍須查；不能稱原版任何模式都固定 Z=13。
- 後文稱「Z/X/C」**皆以 Type0 或等價目前工作映射有效**為前提；其他 bank 請解讀為 logical13/14/15，不要從使用者的實體字母直接推斷 server 的數值。

## 2. 控制器先把按鍵聚合為 16-bit mask：兩鍵不會天然成兩筆 row

`0x5452C0` 在 controller owner+0x78 gate 通過後，按邏輯 action phase 寫 controller+0x5C WORD。phase **1(press)** 或 **2(held)** 均使對應 bit OR 進同一個 WORD；它們不是「有兩個獨立 row」的 writer：

~~~asm
54543C 80 3D 11 90 FB 00 01   cmp byte [FB9011],1 ; logical13 press
545477 80 3D 11 90 FB 00 02   cmp byte [FB9011],2 ; logical13 held
545480 66 83 4B 5C 01         or word [ebx+5C],1 ; bit0
5454B8 80 3D 12 90 FB 00 01   cmp byte [FB9012],1 ; logical14 press
5454F4 80 3D 12 90 FB 00 02   cmp byte [FB9012],2 ; logical14 held
5454FD 66 83 4B 5C 02         or word [ebx+5C],2 ; bit1
545534 80 3D 13 90 FB 00 01   cmp byte [FB9013],1 ; logical15 press
54556F 80 3D 13 90 FB 00 02   cmp byte [FB9013],2 ; logical15 held
545578 66 09 73 5C            or word [ebx+5C],si ; SI=4 here, bit2
~~~

**OR 累積規則（若其它 bit 未設、對應 phase 同在被消費的 frame、工作 bank 正確）：**

| Type0 實體操作 | logical action | 寫 controller+5C | 16-bit 候選合成值 |
|---|---|---|---|
| Z 單按／保持 | 13 | OR 1 | 0x0001 |
| X 單按／保持 | 14 | OR 2 | 0x0002 |
| C 單按／保持 | 15 | OR 4 | 0x0004 |
| **Z+X** | 13、14 | 1 OR 2 | **0x0003** |
| **Z+C** | 13、15 | 1 OR 4 | **0x0005** |
| **X+C** | 14、15 | 2 OR 4 | **0x0006** |
| Z+X+C | 13、14、15 | 1 OR 2 OR 4 | 0x0007 |

原生使用 `or` 而非每次 `mov` 清零覆寫，因此表格是**恰好這些 bit 有效時的值**；有舊位、其它 input producer、其它 V event／模式狀態時，整個 WORD 未必精確等於表內數值。尤其不能僅由某次使用者按了兩鍵，就不驗證 frame 取樣、UI 攔截、actor gate 而聲稱必送封包。

**新增的等價入口：** `FB901C` (logical24) 的 phase1/2 在 `54566D` 再 OR **0x03**；`FB901D` (logical25) 在 `5456E8` OR **0x06**；`FB901E` (logical26) 在 `545763` OR **DI=0x05**。因此這三個複合 action 的 producer 和兩個獨立 action OR 後的 mask **可收斂到相同 WORD 值**。這不能證明 ID24/25/26 必由原版雙鍵自動合成，亦不能把它們當三個新封包 opcode。Type0 的 KeyMapping.xml 沒有這三個直接鍵位 row；其上游／優先關係仍屬未知。

## 3. SkillMatrix 對組合鍵具有真正的選擇優先順序，而不是按兩個單鍵技能依序執行

接續可達的 controller vtable（候選 **C0F944+0x48→546100**），透過 `546263 call 546780` 取得 low word／事件結果，在 actor/mode 檢查後 `5462DD call 54F270`。`0x54F270` 對 AL mask 的判斷是依**順序**短路；先檢查任意 bit0+1、bit0+2、bit1+2，然後才單鍵、V、bit4：

~~~asm
54F277 A8 C0              test al,C0h ; bit6/7 -> separate fast true
54F281 83 E1 01           and ecx,1
54F286 A8 02              test al,2
54F28A B3 04              mov bl,4 ; bit0 & bit1
54F293 A8 04              test al,4
54F297 B3 05              mov bl,5 ; bit0 & bit2
54F2A2 A8 04              test al,4
54F2A6 B3 06              mov bl,6 ; bit1 & bit2
54F2AF B3 01              mov bl,1 ; bit0
54F2B8 B3 02              mov bl,2 ; bit1
54F2C0 B3 03              mov bl,3 ; bit2
54F2D2 ...                ; selected column bl, actor/mode matrix lookup
54F2E0 E8 3B 9F 2C 00    call 819220 ; matrix model
54F2F7 E8 E4 B5 2C 00    call 81A8E0 ; column lookup
54F310 E8 CB 01 00 00    call 54F4E0 ; timing payload
54F317 39 48 04          cmp [eax+4],ecx ; ecx=0 after clearing
~~~

**結果：0x03→matrix column4；0x05→column5；0x06→column6。** 這是**一個 mask 選出一個矩陣欄位**的 native check，不是「Z 技能 + X 技能，各檢查各自 col1/2，再各自發動」。例如 bit0/1/2 同時有效的 **0x07 在此 predicate 優先命中 column4**，非同時判 three skills；但未證動畫、技能結果是否只有一個，因後續還有其它 consumer／狀態。對 `0x40/0x80` gate bypass、AL==0 true 亦不能當作技能已施放；真正選取矩陣項目還要經 actor/tier、skill key、timer 是否為零的有效路徑。

**關鍵設計影響**：相容 Server 若要還原雙鍵「技能」，不應把 `0x03` 拆成技能1與技能2的兩次消耗／兩次判定；應先保留原始合成 mask 和依角色資料選擇 action 的模型。此處只證 Client 本地矩陣**判定順序**，原版 Server 自身的消耗、冷卻、取消、combo progression 不可照猜。

## 4. 新閉合的跨函式鏈：組合鍵 mask 如何有條件成為 000A 的**同一筆 Row A 高 WORD**

把三處不同層次接在一起，可以得到比先前 W03 更具體的資料流：

~~~text
Type0 Z+X/Z+C/X+C -> logical13/14/15 phase1或2
    545480/5454FD/545578 → controller+0x5C |= bit0/bit1/bit2
    （或 logical24/25/26 的等價 OR writer，實際產生者未證）
        ↓ 在相符控制器、actor/mode/時間/enable gates 通過時
    545895 ..545990：Row A slot i (i=0..2)，R=owner+0xC+12*i
        ↓ owner->vtable+0x48(&S+34, i)；候選 C0F944->546100
    546263 call 546780
       546791 read WORD[controller+0x5C] 到 EBX
       5467F4 write WORD [outputMask] = BX
        ↓
    546286 load outputMask；54628F..54629E
       更新 packet local S+36 的低15位（起初546191清0）
        ↓
    5462DD call 54F270（0x03/0x05/0x06 → col4/5/6）
       依 actor/matrix/timer gate 決定是否可以維持該 mask
       546302 可能直接清除 local highWORD 低15位
        ↓（還會有 +0x8000 狀態 flag 分流）
    5458CE virtual+48 返回 AL
       AL==0：只有特定 fallback 可能 append
       AL!=0：按 owner+0x58 決定是否清除 highWORD／呼叫 R virtual+58
        ↓
    54590D 取 WORD[R+4] 覆蓋 S+34 的 lowWORD
    545930 將 4 byte S+34 寫一筆 Row A 起始位置
    545932 寫第五 byte（最後值依 callback/branch）
    545935 FE48D0 +=5
        ↓
    545B38 若總長度>6 -> 545B71 selector0 virtual+10
        ↓ 連線／Pending／frame pump／WSASend 皆有條件
~~~

原生重點（同一個 stack local 的高 WORD，**不是兩個按鍵各一筆**）：

~~~asm
546191 66 89 43 02        mov word [ebx+2],ax ; out +2 先=0
546263 E8 18 05 00 00     call 546780
546791 0F B7 5F 5C        movzx ebx,word [edi+5C]
5467F4 66 89 1A           mov word [edx],bx   ; collector word
546286 8B 44 24 20        mov eax,[esp+20]   ; collector word
54628F 66 8B 4B 02        mov cx,[ebx+2]
546293 66 33 C8           xor cx,ax
546296 BA FF 7F 00 00     mov edx,7FFFh
54629B 66 23 CA           and cx,dx
54629E 66 31 4B 02        xor word [ebx+2],cx ; low15 <- current collector mask
5462DD E8 8E 8F 00 00     call 54F270        ; local matrix/timer gate
546302 66 21 53 02        and word [ebx+2],dx ; dx=0x8000, conditional clear low15
5458D8 83 78 58 00        cmp dword [eax+58],0 ; owner mode/gate
5458E0 66 89 44 24 36     mov word [S+36],ax  ; ax=0, branch clears highWORD
54590D 66 8B 46 04        mov ax,word [R+4]
545911 66 89 44 24 34     mov word [S+34],ax  ; lowWORD final source R+4
545930 89 10              mov dword [dest],edx ; lowWORD + highWORD in ONE row
545932 88 48 04           mov byte [dest+4],cl
~~~

其中 `546100` 及 `546EF0` 的 vtable 目標源自原始 .rdata **C0F944 +0x2C=5452C0、+0x44=546EF0、+0x48=546100**；C0F944 是**候選控制器 subtype**，不保證所有角色、所有模式、所有 owner 實例都使用同一張表。`546100` 中 return AL 並非僅由是否按鍵決定：包括 actor+0x158/+0x3E8、全域 FBA7AC、FBA7B0、可用矩陣和高 bit 狀態等 gates。

**兩個必要反例／不可漏掉的分支：**

1. `5458D0 AL!=0 且 owner+0x58==0`：直接跳 `5458FB`，不做 `5458E0` 的高 WORD 清零。**若 546100 未從內部清低15位、後續沒有別的可寫 alias 且其它 bit 未加入**，一筆 Row A 的 offset +2/+3 就可保留 **0x0003/0x0005/0x0006（也可能帶 bit15）**。這是我們找到的**條件式、真正可從組合鍵一路到 app payload 的 native dataflow**，不能簡寫成每按組合鍵必然 1 row。
2. `5458D0 AL!=0 且 owner+0x58!=0`：`5458E0` 明確把 local `S+36` 高 WORD 清為0，`5458E9` 重設 local fifth byte，接著 `5458F5` 呼叫 R vtable+0x58。故 **即使先前 546100 曾把 0x03/0x05/0x06 寫進 out+2，此分支也能在 Row A append 前清掉它**。需要具體 callback/alias 與 runtime subtype 才能聲稱 row 最終保留組合 mask。不能把這條分支誤判為「另一鍵形成第二筆」。
3. `5458D0 AL==0` 的 fallback 也會於 `545955` 清高 WORD，而只有 owner+0x58!=0、owner+0x6A bit15 有效才用 `5471B0` append 5 bytes。**fallback 不會自動重做 Z/X/C 分拆**。
4. 即便 `54628F..54629E` 寫入 mask，`546302` 的條件式清除、`5463FB/546440` 的 bit15 設定、`546406/54647C` 的 bit15 清除，都可能改 packet-ready WORD；此外 controller+0x5C 可能同時有 V 的 bit。**不能把 `row[2..3]=0x03` 視為全時真值**。

因此目前最強有界事實是「雙鍵合成 mask 可進入同一個 Row A 的高 WORD，再因 callback/owner/actor/matrix gate 保留或消除」，而不是「按兩鍵產生兩個五位元組 row」。

## 5. Row A、Row B 合批的真正語意和新增反證

`0x5452C0` 建構應用緩衝 `FE38D0` 時先設 `FE48D0=6`，header 為 +0:u16 opcode 000A，+2:u32 runtime [F93944]（後者是 `54588D` 最後覆寫者），後面依 append 成功次數增加 5-byte rows。**Row A/B 名稱僅是本研究按 producer 分類，不是 KR 原版符號。**

| | Row A producer | Row B producer |
|---|---|---|
| 入口 | `545895`，**固定迴圈 i=0..2（三個 12-byte slots）** | `5459B7`，**owner+0x30～+0x34 的 8-byte vector、動態筆數** |
| 原始 R 來源 | `[owner+0xC+12*i]`；slot enabled gate | `vector[i].WORD` 查 `FAB13C` tree，node+0x10 取 R |
| 關鍵 virtual | owner vtable+0x48（候選 546100），可讀 controller+0x5C mask 與 SkillMatrix | owner vtable+0x44（候選 546EF0），處理 vector 的 WORD 及 R、output pointer |
| 已可證輸出 | row+0..1 最後直接讀 WORD[R+4]；row+2..3 是 mask/狀態 callback local；row+4 是 callback local | row+0..1 最後直接讀 WORD[R+4]；row+2..3 與 row+4 受 R/actor/geometry 虛函式及回呼影響 |
| append | 任一 slot 成功，可追加一筆；容量與 owner flags 有門檻 | 任一 vector entry 查到 R 且 callback/fallback 通過，可追加一筆 |
| 和 Z+X 的關係 | **可以在同一 row 的 16-bit 欄位攜帶合成 mask**；不是 Z/X 各自一筆 | **沒有已證的 Z+X 專屬對應**；不得叫做「第二鍵 row」 |
| 同封包 | A 迴圈結束後才遍歷 B；多筆 row 可共存 | 與 A 共用 FE38D0/FE48D0 |

**新增 Row B 的「另一種操作」反證：** 候選 `546EF0` 在 `546F81` 將 vector 提供的 WORD 作 `FAB138` actor tree lookup；`546FAF..546FFF` 讀取目標與目前物件的 `+0xA0/+0xA4` 浮點位置、計算差值與距離；`547037..547077` 可設 output+2 bit15、利用角度/量化回傳寫 `output+4`；`5470B3` 也可 OR out+2 bit1。這是**物件/位置/方向類資訊的候選 producer**，不是對第二個實體按鍵作 mask OR 的程式碼。是否為玩家鎖定目標、滑鼠朝向或另外的動作系統，仍缺上游 object owner 與實際情境，不能直接下正式業務命名。

**為何兩者不是兩鍵對兩路？** Row A 的迴圈最多看三個物件 slot，而不是輸入「Z 和 X」的兩個鍵；Row B 取任意長度的 vector actor key，而不是拿 Key45 / FB9012；**在僅按單個 Z 時也可能有多個 Row A 或 Row B 記錄**，是否 append 由其各自 gate 決定，不能用 row 個數等於按鍵數。真正的兩鍵選擇明確出現在較早的單一 WORD bitmask + SkillMatrix column，與 append 筆數完全是兩個概念。

### 5.1 精確但有界的 000A ABI

~~~text
offset   size    來源 (正常建包)
0        2       little-endian 0x000A
2        4       runtime DWORD [F93944]，未命名
6        5       Row[0] if appended
11       5       Row[1] if appended
...
Row[j]+0 2       WORD [R+4]，append 前直接讀入
Row[j]+2 2       callback/actor/local highWORD（某分支可為 combo mask）
Row[j]+4 1       callback/actor/local byte（不是已證的 skill ID）
length = 6 + 5 * N; 只在 N>0 才由 545B71 呼叫 sender
~~~

Row A/B 的其他分支、最後第五 byte 條件**一律以 W00-116 修正版優先**：Row B 在 owner+0x58==0 且 virtual+44 非零時可跳過 `545AC8` B0 覆寫，callback 又可能改 out+4；Row A `5458CA` 因 stack push alias 不等於 fifth byte。不可把兩路 row+4 無條件都寫成 R+B0，亦不可由此宣稱有兩次技能。

### 5.2 傳輸與 C/S 邊界

本輪可直接核對 `545B38 cmp [FE48D0],6`、`545B43 jbe 545B73`，因此沒追加任何 row，這個 builder 不進 `545B71`。有 row 時 `545B6F push 0` 傳連線 selector0，`545B71` 經 manager FBA854 virtual+0x10→候選 `8069A0`；selector0 在 T10-117/118 已找到建立 caller `4957EA`，connection 成功、pending queue、packet framing、WSASend 必須另外符合其 gates。單一 combo mask 本身**不保證**發出一個封包，batch 也可能含其他物件/目標 rows；「兩個按鍵→兩次 WSASend」沒有原生依據。

本輪沒有把 `000A` 的 app header 當最終 socket frame header；socket framing 委 T02 的已確認／待分析責任。`0022/0068/0007` 是 W03 之前已核對的**其它不同 logical-input event producers**，目前沒有這三者就是 Z+X、Z+C、X+C 的直接鏈；不應把「三種雙鍵組合」配對到「三種其它 opcode」。S2C category2 key13/000D actor consumer 屬 W04 來源，不是已證 000A 的直接 ACK。

## 6. 玩家情境 × 原生 Client × C→S × S→C × motion × 責任

| 玩家操作 | Client 本地判斷 | C→S 已證有界路徑 | S→C | 動作／連段 | Client/Server分工 |
|---|---|---|---|---|---|
| Type0 同時 Z+X | bit0|bit1→0x03；54F270 col4 優先 | 若 actor gate、Row A callback、owner+58 等條件成立，可以**一筆 row 高 WORD**攜帶 0x03/帶 flag；仍可能不 append | 000A 對應回覆未知 | 哪個動畫／cancel/window 未證 | Client mask+matrix 已證；Server 原版技能裁決未知 |
| Type0 同時 Z+C | bit0|bit2→0x05；col5 | 同上，單 row 高WORD候選為0x05 | 未證 | 未證 | 同上 |
| Type0 同時 X+C | bit1|bit2→0x06；col6 | 同上，單 row 高WORD候選為0x06 | 未證 | 未證 | 同上 |
| Type0 連按／長按某鍵 | phase1或2 可反覆進 OR bit；是否在同一 frame 合成要看取樣 | 無法從 phase1/2 直接求封包數、row數 | 未證 | held chain 時窗未證 | Client 續查實際狀態重算 |
| 三鍵 Z+X+C | 0x07 在 54F270 優先 col4（若低位為7且 0xC0 gate 未命中） | 可能進同 Row A；是否被後續阻擋 unknown | 未證 | 一次或多次技能未知 | 不猜「三技全放」 |
| logical24/25/26 phase1/2 | 各直接 OR 0x03/0x06/0x05 | 共同輸出 mask 可等價；實際 producer 尚缺 | 未證 | 未證 | 不臆測就是實體雙鍵發出的事件 |
| 任意 combo，但 Row A AL=0 | callback 可能因狀態不變/矩陣/actor gate 不回報新結果 | 若 fallback 條件不滿足，這一路無新 row；其它路仍可能有 | 未證 | 未證 | Client native negative condition |
| 任意 combo，Row A AL!=0、owner+58!=0 | 原本 out+2 可能帶 mask，5458E0 明確清 high WORD | 這筆 Row A **不能不加條件視為傳送 0x03/05/06** | 未證 | 未證 | 需再查 actor subtype/callback |
| Row B 查到別的物件／目標 | 546EF0 物件 tree、位置差分、角度欄位可能寫 output | 可和 Row A 追加到同一 000A buffer；不是「第二個按鍵」的證明 | 未證 | 可能空間/朝向資訊，尚待確認 | Client object/motion/T09 界線 |
| 000A 最終 N=0 | 545B43 不進 sender | 這條 builder **不送** | 不適用 | 不能反推沒有動作 | 有界 Client 負向 |
| 非 Type0 KeyMapping | 實體鍵→logical13/14/15 可能不同 | 不能硬套上表物理按鍵 | 未證 | 未證 | 需取得實際工作 bank |

## 7. 對 Server 規劃最有用的明確結論

1. 依使用者既定設計，**普通攻擊是技能的一種**；但傳入 Client app 的「組合」候選是一個 **bitmask/矩陣欄選擇**，不是被 Row A/B 強制拆成兩個技能施放。
2. **應保留原始 000A row[2..3] WORD 的 bitmask/flag 資訊及可能為零的分支**，先由原生 Client 報告逐欄命名，再決定相容 Server 的 action resolution／target／cooldown；**不要把 0x03 解析為「先放 Z 技能、後放 X 技能」**。
3. 原版 Client 可證的 skill matrix 欄位優先度：Z+X→4、Z+C→5、X+C→6（Type0 限定），另 bit0/1/2 全有時優先 col4。未實測原版 Server 是否對這些欄使用完全相同的決策；Server 自訂與不確定部分應由 S00 ADR 明示，T11 負責技能成本/冷卻原生核對。
4. Row A 是至多三個 controller-actor slots 的條件性 append，Row B 是 vector+object tree 的條件性 append。**不能由 000A 出現 N=2 就認定是玩家按了 Z+X**，也不能認定 N=1 就是單鍵。
5. 還缺的 **Client**：真實工作 bank/mapping、actor owner+58 的 runtime writer/instance、virtual+48/+44 不同 subtype、確切 row+2/+4 在施放中／移動時的所有分支、具名 skillId 最終映射、技能中鍵盤／滑鼠移動 producer、000A 與 S2C 000D 的因果。原版 Server 的受理／耗資／連段是**Server 不可直接由 Client 機器碼推出**；不把這類 Server-only 缺口誤算為本輪 Client 反證。
6. **尚待正式整合**：T02 frame、T09 motion、T11 skill availability、T01 W00 勘誤複驗、S00 REQ/SPEC/TEST；**待遊玩驗證 NOT_RUN**。本次 W03 對「雙鍵與兩路合批是否同一機制」的靜態問題已有明確結論及反例；較廣的「全技能/施放中操作完整端到端」仍是待研究，不以這份補強冒稱 T10 整體完工。

## 8. 來源追溯及驗證

- 本輪原始 BIN 指令獨立讀取、vtable Little Endian 來源：`.rdata C0F944 +2C=5452C0, +44=546EF0, +48=546100`。同目錄機讀 `W03-combo-native-audit.json`，77 條 raw 指令與 8 個 hash windows，`verify-native.py` 無執行 Client 的 source-only checker。
- **KeyMapping.xml 來源**：`kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt`（blob cb8a9da734567b10e37cc966a981300cb3e7b8bc）。
- **原 W03**：`kr-temp-roy/T10/W03-20261031/20261031-165757-chatgpt-web-roy-T10-W03-action-transport-native.md`（blob 62d31e8b3d8a450e644362092fd04e7ae696c729），本輪明確補完「雙鍵合成不等於兩條 Row producer」和單 row high WORD 條件式通路，不撤回其 0022/0068/0007 的有限證據。
- **W00-116 優先勘誤**：`kr-temp-roy/T10/W00-20261031/20261031-060240-chatgpt-web-roy-T10-W00-116-correction.md`（blob bb5f5972d4d0bf0ac91bf944aeb82ffd39d00804），已撤回「兩路 row fifth-byte 一定 R+B0」。待 T01 正式審核。
- **W02**：`kr-temp-roy/T10/W02-20261031/20261031-163141-chatgpt-web-roy-T10-W02-basic-attack-as-skill-native-difference.md`（blob e8a0cedc28c28968905e914d01379915fe9dc17f）；**T10-115/117/118**：C2S builder→manager selector0→conditional pending/framing→WSASend 原生靜態條件式路徑。
- 本稿是有界新增的 Client 靜態逆向，不能將 raw byte 符合、符號模型測試或檔案 Push 當作「全部 gameplay 動作可玩」、「原版 Server 已接受」或「T01 FULL-PASS」。

