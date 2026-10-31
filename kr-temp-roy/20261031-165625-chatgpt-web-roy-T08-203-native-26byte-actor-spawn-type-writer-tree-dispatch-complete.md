# T08-203 — KR 本地索引7：26-byte生成row → 四類Actor建構 → 複合ID／位置／狀態 → 主樹登記、重複鍵和失敗路徑（BIN-first 全項研究）

**作者** chatgpt-web roy；**研究時間** 2026-10-31 16:56:25 +08:00（Asia/Taipei）；**任務** T08-203（203-01～203-05）；**原件** 唯讀 KR Tartaros.bin，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次本地 `sha256sum` 實核）。PE32 `.text` VA `0x401000` / raw `0x400`，code raw=VA−`0x400C00`；`.rdata` VA `0xBD2000` / raw `0x7D0600`，data VA `0xD61000` / raw `0x95E800`。所有指令地址以 GNU objdump **由真PE函式入口**解析；以下字節、jump table及vtable另以原始BIN Python讀取驗證。未執行／附加／修改客戶端。不得由本地index7直接宣稱完整wire opcode=7。

## 0. 舊來源歸屬、研究目標與優先級

固定研究終點取自已交付 `T08-20261031-後續分析大項目與小項目規劃.md` 的203-01～05：（1）26B row完整欄位；（2）0/1/6/7與不支持type；（3）成功、重複、失敗、資源/owner與rollback；（4）Actor ID／位置／狀態writer；（5）本地receiver dispatch及T02邊界。202已 bounded complete；T08全Task `native_complete`仍false。本輪查GitHub `main@5897c5058a7386686efaeb6173c8ac11bd83c78b`、T08分支開工 `52c94c0a766439e5a004be94cff128a4926a26e7`（先以non-force雙親merge同步main）、AGENTS、T08 README/task.json、T01退回、shared FULL-PASS、T08 S00 inbox/RR（當時沒有T08待辦RR）。使用者直接指定203，優先於原legacy T01候驗（作者側READY_FOR_REVIEW）；絕不改T01台帳。

**重要來源復用**：T08-201全文已證本地index7/8/10、26/81分派表、0007 26B row、type jump table、CMonster建構/位置及主樹登記，T08-202已證owner P與Controller關聯、出站處理。**本稿不是把201內容冒充新發現**；新增/本輪定向封閉：四種vtable的共同欄位setter 16/16槽驗證、每個type的特定副作用／null分支、dispatcher上下游真入口、`4CAB80`的座標更新條件、成敗路徑及舊資料欄位偏移錯誤更正，整合203-01～05可供相容Server規格使用的完整有界矩陣。

## 1. 203-05：有界接收分派身分（不跨T02宣稱wire）

原生建立/調度的資料流：

1. `48F6D9 push 0x5EAC`，`48F6EA call 4ADD50`配置/填 handler物件；`48F6EF mov [EAX],0xC072B4`寫入RTTI可核主vptr，`4B7D50`安裝至另一outer owner `+0x5EAC`。
2. `4B7EC0`在outer owner+0x5EAC非null時取handler主vptr +4並tail-jump；其virtual+4是 `4FDA30`。
3. `4FDA30`用第三參數有號WORD作本地index，查 handler實體 `this+4+8*index` 取回function pointer，傳遞同一包buffer、payload len、index並間接call。
4. handler表初始化 `4ADD50` 先建立0xBD5個8-byte slots：`4ADD7E C7 40 3C D0 E4 4A 00`，即table `+0x3C`=本地index **7** → **4AE4D0**；旁邊DWORD不是另一handler；index8→4AF530（0x2C owner P，22B row）**不是**203的Actor生成。

原生入口不等於T02已證 socket frame/加解密/domain→index映射。**T02責任**：RX frame parser、命令域及index7的真正外層wire對照；本稿已提供 T08 可引用的接收handler與邏輯payload邊界，不在此偽造原版Server流量。T08 只主張「已選中此本地handler且buffer/length有效時」的行為。

## 2. 203-01：精確 2+26N payload layout、count及來源

令 `B=[EBP+8]`、`L=[EBP+0x0C]` 為**handler收到的**buffer和len；`L<2 → N=0`，否則 `N=floor((L−2)/26)`。原件 `4AE51F lea ecx,[eax-2]`，`4AE522 mov eax,0x4EC4EC4F`，`4AE527 mul ecx`，`4AE529 shr edx,3` 為 unsigned除26魔數實作；`4AE540 add EBX,6`，每列`4AED47 add EBX,0x1A`。對第 i筆：`R=B+2+26*i`，當前 EBX=R+4。`B[0..1]`在本handler計數/迴圈中只用作被略過的前置，不證其值、業務意義；並未看到要求`(L−2)%26==0`的檢查，餘數byte不成一列。**此長度是解到handler的payload，不含T02外層網路framing。**

|row R+位移|寬度與原生讀法|真正資料流/欄位consumer|確認等級|
|---|---|---|---|
|0–1|WORD `4AE58F [EBX−4]`; BYTE `4AE5B8 [EBX−4]`|完整WORD主Actor tree key及`Actor+4`；**低BYTE**選type|原生確認|
|2|unsigned BYTE `4AE5BC [EBX−2]`|經`−1`參與Actor composite；如值0有uint32下溢，不能只用簡化byte表示|原生確認|
|3|本handler未找到獨立typed load|**不能把type6讀取誤指到R+3**；該byte若被別的helper間接讀取仍需各自證據|Client待逆向|
|4–5|unsigned WORD `4AE5C0 [EBX]`|composite低16bits；type0 local額外狀態索引（<=9 gate）；type6註冊key|原生確認|
|6–9|DWORD，`4AEB43 LEA [EBX+2]`|虛擬setter `Actor.vptr+0x44`的第1個float32數值；最終`Actor+0xA0`|原生確認|
|10–13|DWORD，經同上pointer+4|虛擬setter第2個float32數值；最終`Actor+0xA4`|原生確認|
|14–17|float32 `4AEB5B FLD [EBX+0xA]`|`Actor.vptr+0x5C`參數，原生共用 `4C8C40`寫`Actor+0xB4`；**具體物理量/單位未命名**|原生確認|
|18–21|DWORD `4AEB17 [EBX+0xE]`|`Actor+0x9C` / owner次級P樹查找key；type0 local識別比對|原生確認|
|22|unsigned BYTE `4AEB4B [EBX+0x12]`|vptr+0x58→`4C8C30`寫`Actor+0xB0`|原生確認|
|23|unsigned BYTE `4AE786 [EBX+0x13]`|type1寫Actor+0x424，若==4條件設Actor+0x428；common尾端 type==1/6用不同附加分支|原生確認|
|24|unsigned BYTE `4AEB22 [EBX+0x14]`|零擴展寫Actor+0x90 DWORD|原生確認|
|25|unsigned BYTE `4AEB0A [EBX+0x15]`|作Actor+0xF0子介面slot+8參數；若==0x18則Actor+0xBC=1|原生確認|

**更正T08-201舊表的重要位移：type6另讀的指令為`4AE8A2 MOV AL,[EBX−3]`，等於** `R+1`，不是舊筆記所列`R+3`！該值是完整主Actor key `R[0..1]` 的高BYTE，不應自創另一個R+3欄位。此為正確真PE EBX=R+4實際值運算，原稿凍結不覆寫；依本新來源作勘誤。**所有小端、float32解釋以此Tartaros.bin版本限定**。

Composite形成機器碼 `4AE5B8..4AE5D0`：

~~~cpp
uint32_t a = uint8_t(R[2]); uint32_t type = uint8_t(R[0]);
uint32_t composite = (((a - 1u) | (type << 8)) << 16)
                   | read_le16(R + 4);
~~~

當R[2]>=1時，高16可視作type及R[2]−1；R[2]=0時先做unsigned DWORD下溢，**不得無根據把它縮成只低BYTE相減**。此composite在`4AEB37`以Actor vtable+0x3C = `4C6FB0`寫 `Actor+0x88`和`Actor+0x8C`；Actor WORD ID `4AEB30`寫Actor+4。兩個key不是同一個欄位，不可混用；某些後續setter可能只改+8C。

## 3. 203-02：完整jump table、constructor、vptr、共用方法

`4AE5D4 CMP type,7`，超範圍走`4AED83`；`4AE5DD JMP DWORD PTR [EAX*4+4AED90]`，**4AED90的32bytes是小端DWORD跳表資料，不是x86 code**。本輪從原始BIN逐字核對8/8 entries：

|type 低BYTE|table target|heap alloc|constructor|原生 primary vptr / RTTI|特定後續|
|---:|---|---:|---|---|---|
|0|4AE5E4|0x444|4CD6F0|C07B44 / `CCharacter`|若R+18等於local識別，讀R+4 <=9及 local資料 `+0x6924` 的分支，特定virtual call|
|1|4AE671|0x434|4D1710|C0C9DC / `CMonster`|另外配置0x48輔助記錄、56F5C0登錄候選、R+23→Actor+424，可能外部 resource 查詢/狀態更新|
|2、3、4、5|4AED83|無正常Actor分配|—|—|`4AED83 PUSH 0xC069C0→6EDC70` 診斷路；未證helper會正常返回，不得視為可接受建構|
|6|4AE80A|0x42C|4D2120|C0CA9C / `CNPC`|R+4 的WORD做另一全域索引 `FE18DC` 查找，命中時讀R+1參與紀錄更新 via 53EBA0|
|7|4AE8D6|0x428|4D1060|C0C8C4 / `CEventObject`|R+23 零擴展寫Actor+420|

四個ctor均先呼叫base `4C7070`，而**各自vptr覆蓋**，所以不能只引用base vptr或把0x48 type1附屬物件誤認為Actor。原始RTTI COL+type string身分的獨立證據見先前 T08-202 四Actor研究；本輪四表絕對DWORD驗證 common virtual slots 16/16:

|Actor.vptr位移|四類原生值一致|被handler使用與效果|
|---:|---|---|
|+0x3C|`4C6FB0`|寫`Actor+0x88/+0x8C = composite`|
|+0x44|`4C8B90`|將row+6/10兩個float送`4CAB80`，條件寫Actor+0xA0/+A4|
|+0x58|`4C8C30`|R+22 BYTE → Actor+0xB0|
|+0x5C|`4C8C40`|R+14 float32 → Actor+0xB4，特定active子介面也可能接收縮放後值|

**不同vptr+0x30**（handler `4AEB7D`）：Character=4CDBA0、Monster=4D1910、NPC=4D2820、EventObject=4D1370；不能把CMonster特定CDoll建立套到所有Actor。CMonster `4D1910→4C7DF0→7A4C50`已有201原生證據，可在進主樹前安裝非空CDoll子物件，但可見像素/外部模型完成仍是T08-204/遊玩範圍。

## 4. 203-04：原生位置setter條件，並非無條件複製

`4AEB3E`取得vptr+44，`4AEB41 push1`、`4AEB43 lea [EBX+2]=R+6`、`4AEB49 call`，四類都由 `4C8B90` 接到`4CAB80`，如下：

~~~asm
4C8B90 55 8B EC               push ebp;mov ebp,esp
4C8B93 8B 45 0C               mov eax,[ebp+0xC] ; mode=1
4C8B99 8B 4D 08               mov ecx,[ebp+8]   ; &R+6
4C8BA0 E8 DB 1F 00 00         call 4CAB80
4CAB83 8B 55 08               mov edx,[ebp+8]
4CAB86 D9 81 A0 00 00 00      fld [actor+0xA0]
4CAB8C D9 02                  fld [row+6]
4CAB98 D9 81 A4 00 00 00      fld [actor+0xA4] ; conditional test
4CAB9E D9 42 04               fld [row+10]
4CABAB 83 7D 0C 00            cmp [ebp+0xC],0
4CABB1 89 81 A0 00 00 00      mov [actor+0xA0],eax
4CABBA 89 91 A4 00 00 00      mov [actor+0xA4],edx
4CABC7 C7 81 AC 00 00 00 01 00 00 00  mov [actor+0xAC],1
4CABD1 FF D2                  call [actor.vptr+0x38] ; when change and mode
~~~

`4CAB80`有浮點比較與 `jp/jnp` 路徑：**在比較判定「需要更新」的分支才寫新值**，且mode非0時`Actor+0xAC=1`並調Actor+0x38 virtual；不能把本地position writer簡寫為「每包無條件覆蓋兩個坐標」。從指令可稱**兩個float32位置量**，但不能未經地圖/場景原件驗證自行命名X/Z、世界座標單位或傳送語義。

共用尾端（按CFG有條件）：
- `4AEB17..1C`: R+18→Actor+0x9C；
- `4AEB22..26`: R+24零擴展→Actor+0x90；
- `4AEB30`: R+0 WORD→Actor+4；
- `4AEB34/3A`: vptr+0x3C→4C6FB0寫Actor+0x88/+8C；
- `4AEB3E..49`: vptr+0x44→4C8B90→4CAB80 處理位置；
- `4AEB4B..57`: vptr+0x58→4C8C30→Actor+0xB0；
- `4AEB5B..67`: vptr+0x5C→4C8C40→Actor+0xB4；
- `4AEB69..6F`: 若R+25=0x18→Actor+0xBC=1；
- `4AEB78..7D`: vptr+0x30不同Actor類別初始化/side effect；
- `4AEBFC..4AEC03`: EAX=Actor*, push FAB130→4DFF30主Actor樹插入；
- `4AEC08..4AEC95`: R+18!=0則查FAB148二級P樹，P有效且P+4==0呼叫4C6E50數值綁定；若`Actor+4`低byte==0再`Actor+0x98=1`；
- 其後R+23特別值4/6、extra global state等不同分支，而非所有type必有該後置side effect。

## 5. 203-03：新建、duplicate、invalid、null與rollback真CFG

|情況|原生分支與結果|禁止過度主張|
|---|---|---|
|L<2 或 2<=L<28|N=0，`4AE53A`跳`4AED58`；EAX=0x100、ret0xC|沒有Actor建立不等於T02判定包有效|
|L=2+26N+k,0<k<26|N=floor，尾k bytes被此迴圈忽略；不見remainder拒絕|不可說上游允許短包或無讀取風險|
|main Actor key已存在|`4AE58F`讀WORD ID→`82EF00`；`4AE5AC..B2`與主樹sentinel比較，存在跳`4AED42`前進下一筆，**不重新ctor/覆蓋同ID**|只限本handler precheck；不保證競態下永無duplicate|
|新ID且type0/1/6/7|依jump table allocation+ctor、共用setter、`4DFF30`成功主樹插入（若此前/期間狀態有效）|`4DFF30`不傳回boolean，不代表每分支均成功|
|type2/3/4/5或>7|跳`4AED83`診斷helper`6EDC70`；不走正常`4AEB17`共用Actor setter|callee有否noreturn未驗，不能聲稱會安全忽略/一定crash|
|新ID但allocator返回0|四type均有各自null分支，但type1新aux0x48分配成功時在`4AE6C7`仍讀`[ESI+4]`，若Actor分配失敗ESI可能0；type7 `4AE90F`直接`[EAX+0x420]`，而EAX可由null分支成0|局部指令暴露可能空解參照路徑，**不是已實測崩潰**，也不應寫安全rollback|
|type1 aux或資源查找失敗|`4AE6C3` aux0走EDI=0；非空時建立0x48資料並`56F5C0`交付。後續資源 `4AE7D2→4F7A70` 回傳+0x61狀態、[Actor+0x368]條件清欄位，部分路徑跳`4AE917`|不同aux/資源失敗未證同一rollback/無漏指標；不要混0x48 aux與owner 0x2C P|
|type6 registry缺key|`4AE87C`按R+4查`FE18DC`，node==sentinel時直接到共用尾端；命中讀R+1走`53EBA0`|不同于拒絕整隻CNPC建立|
|`4DFF30`插樹時發現重複|`4DFF5F→82EF00`再查；已有時`4DFF90..9E→6EDB60`診斷而非直接free incoming Actor|不能對未見rollback或race聲稱無洩漏/無崩潰|
|R+18 owner key無次級P|`4AEC08`檢查R+18；若0 skip；非0時`8438C0`查FAB148，sentinel/null/P+4非0各自skip bind；主Actor已先插入|**缺P不阻止本handler已進行的主樹登記**；P數值綁定是附加效果|
|每列正常尾端|`4AED42`計數+1、cursor+26，最後`4AED58`固定EAX=0x100|此固定回傳值不是建立幾隻的計數|

**異常分支分析的判斷原則**：除真正有原生store／branch／free證據外，一律不能猜完整exception unwinding、OOM處理、強引用與Server重送策略；另由210針對高風險資源rollback再深入，不把「可從Client靜態繼續研究」偷換成Server-only問題。

## 6. 由現有 BIN 自動驗證的可重現邊界

本次以 `sha256sum`和Python從原始PE `VA−0x400C00`逐位元組比對：
- **113個真PE指令byte anchors PASS**：handler入口、計數魔數、重複key跳轉、四個type ctor、部分特定狀態、共用setter、主樹/P-tree插入、錯誤與尾端。
- **8/8 jump-table DWORD PASS**：type2～5皆4AED83，不用線性反組譯把`4AED90`當code。
- **四張Actor主要vtable的16/16共同method pointer PASS**：+3C=4C6FB0、+44=4C8B90、+58=4C8C30、+5C=4C8C40。
- 研究中的方法位址如4CAB80、4DFF30、4ADD50由根入口objdump重解；這是**作者側精確byte/source驗證**，**不是**T01全篇原生FULL-PASS、不是GitHub CI已執行腳本或實機效果測試。
- 可重新核對：SHA256原件、跳表地址 `4AED90`、四個vptr、列明VA byte片段。新技術稿採獨立檔案，**不原地修改T01已登錄及凍結SRC-0589等歷史原稿**，避免CI source identity hash mismatch。

## 7. 玩家情境、相容Server契約與五種完成狀態

|玩家/封包情境|方向/handler domain|Client已確認|Client待逆向|Server待開發／跨Task|待遊玩驗證|
|---|---|---|---|---|---|
|批次建立怪物/NPC/角色/事件物件|本地index7 /4AE4D0，handler payload 2+26N；**wire opcode未升格**|type0/1/6/7各自配置/ctor→共用ID/位置/狀態writer→4DFF30樹插入；Monster有CDoll子物件前置|完整type特有的外部資源consumer、渲染首次可見、部分異常回滾|Server按Client可接受格式提供列資料；T02完成真正wire frame/dispatcher domain；T06/T07接可見及Scene就緒|合法本地Client看到對應模型、位置與數量|
|重複Actor ID|同上|既有主樹key skip new ctor，不刷新同ID Actor；插入者另有duplicate診斷|特殊race與進場反覆處理的全部效果|Server是否允許重用key由相容SPEC決定，非原版內部公式|連續重送／移除後重用|
|不支持type／無效長度|同上|2~5及>7診斷；count floor((L−2)/26)、忽略尾bytes；allocator null存在有條件風險|完整exception與上游有效frame/len檢查|T02 frame validation及S00可明訂相容Server不發非法type；不能假稱Client安全處理|畸形包在授權環境驗收|
|依owner P建立數值關聯|本地index7 + index8（**不同row格式**）|R+18 key→二級P tree；P+4==0才補ID，P+8由Actor+88低WORD而來|全部間接P alias與再綁定屬205/208|Server需依可相容順序供owner record；何時發由自訂SPEC規範|先P後Actor或先Actor後P|
|type1模型初始鏈|4D1710/4D1910/CDoll|主樹登記之前可建立CDoll、接受位置setter|實際圖像Render/載入及首次可見時點是204目標|T06資源ID/外觀；T07 Scene就緒|畫面首次出現/失敗演示|

**T08-203完成裁決**：依203原訂的**有界Client靜態目標**（203-01～05），已以原始BIN封閉本地index7接收調度→長度/26B row→type/newID/duplicate/error→四種ctor與實際欄位setter→main Actor tree登記，並標清缺P時附加綁定缺失及T02 wire邊界。因此標**T08-203 = FINISHED (BOUNDED_CLIENT_STATIC)**。這**不是**T08整體native_complete、T01 FULL-PASS、S00 RR ACCEPTED、原版Server行為定案或實機可玩；203計畫中「從收到資料」限本地分派後的handler buffer，外層wire回溯屬T02需另驗證。

**下一段建議T08-204**：只沿203已建立CMonster與CNPC的真正「Actor→子物件／模型／Scene更新→可見性」鏈，不重做本段row/ctor；另外把203異常配置分支、完整rollback交210、跨包重複與owner順序交208。T01舊退回仍待獨立複驗，不能因本203完成而改RESOLVED。
