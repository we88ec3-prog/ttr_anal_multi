# W3-07 — 普通村落換場、玩家／NPC／互動區域初始化與過場分界

> 2026-11-02，`extra/roy3`，KR 靜態原件研究。**階段性交付：正常場景的 Client 初始化／控制／互動介面已補證；Town1 可行走出生座標及原始 NPC／互動區域佈置仍受原件缺口阻塞，不能宣稱 W3 全項完成。** 未執行或修改 Client／Server，未做遊玩測試；不是 T01 FULL-PASS、RR ACCEPTED 或 S00 STABLE。

## 0. 來源、授權與本輪終點

本輪按使用者指定，以「普通村落的換場流程、控制器、合法出生座標、玩家／NPC／互動區域初始化；區分過場與真正進村」為完整目標。保留 W3-01～06、T06/T07/T16 原稿，不改 Task owner、RR、共用驗證狀態或 Server。只新增自己的研究成果到既有 `extra/roy3`。

開工／讀取基準：`main=ac6aac673426459df2a778d20a80c623b8559a92`，`extra/roy3=e2a88ff9b9ede3cc859dc59b3428c1f7b1cd1add`，compare ahead46/behind0。沿用本對話已讀的 AGENTS、派工、共用驗證索引及 W3 工作卡；本次沒有新增分支或將研究合回 main。

| 本輪直接唯讀原件 | bytes | SHA256 |
|---|---:|---|
| Tartaros.bin | 12472320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| Tartaros.exe | 2594816 | `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` |
| Table.stp | 5248784 | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| Event.stp | 11241597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |

PE32/i386，ImageBase `400000`；`.text VA401000/raw400`，代碼 `raw=VA−400C00`；`.rdata VABD2000/raw7D0600`；`.data VAD61000/raw95E800`。BSS 全域值不能從檔案尾端假讀成 runtime 指標。

**N**＝本輪 BIN 指令／靜態 vtable/RTTI；**R**＝本輪 STPD/EX 唯讀解碼資源；**N-ref**＝既有有界來源；**S**＝相容 Server 設計候選；**U**＝未確認。所有 payload 都以 **application 起點含 opcode 的 offset** 記錄，不冒稱已捕獲 transport frame 或官服 request/reply 配對。

附 [manifest.json](W3-07-normal-town/manifest.json) 與 [verify.py](W3-07-normal-town/verify.py)：41 個有界 code slices、7 個 data slices、14 個 Table members 的精確原件 hash。本輪全部核對相符；**byte/hash check 不等於全部語意或可玩驗收**。切片是證據範圍，不一律代表完整函式；只引用已確認的完整指令。

## 1. 先把普通進村與演出分開

| 層 | 普通村落初始化 | Quest15 過場演出 |
|---|---|---|
| 意圖／入口 | Town 選擇 UI、TYPE1/unlock 等 gate → C2S003D；Server 決定目的地與實例，再發布相容場景／世界資料 | Scene key／Lua controller 啟動腳本；四段腳本資源與時序見 W3-06 |
| 場景物件 | 本輪核實 `0099/3 → Scene::CMissionRoom` 的正常控制、房間資料、player、checkpoint 接口；與 CSquare 不同 | `SceneController=FB73C0` 的 cutscene keys、Lua coroutine、臨時演出物件 |
| 地圖 | `0012` 讀 DWORD map selector；Town1 的資源候選為 Map182/town001D/town001.bnd | Scene15/3 的 `LoadMap("town001D.map")` 是演出載圖，不是永久入村證書 |
| 玩家／NPC | `0008` owner、`0007` actor、`000A` 自有角色綁定、`0027` 互動區域，各自初始化 | Lua `CreateObject` 的 ID/xy 為演出配置，不能代替正常 player/NPC 網路資料 |
| 操作恢復 | controller+4、已綁首 actor、room context、輸入旗標及 ready 必須相容 | `RevPhase1 → EnableInput` 只清輸入 bit1；不重建 owner/actor/checkpoint/room |
| 完成判定 | 正常場景、地圖／碰撞、玩家、房間、NPC、互動區域與可操作狀態分別通過 | 演出播完、RestoreMap、EndCutScene 不等於權威 Q15 完成、Town1 spawn 或 Q117 可接 |

**修正 W3 早期界線：** 以前只能說 `0099/3` 名稱是 MissionRoom，不能據名稱把它指定為村落；現在已實際核到其 controller、ready、owner/room、NPC checkpoint 等正常遊玩介面，故不是只剩名稱猜測。**仍未找到 Client 內把 `TownId=1` 無條件換成 `0099/3 + Map182` 的硬編碼或官服實錄。** 此組合可作 S00 明示的相容村落方案；官服選線／發包偏序是 Server 決策與待實機驗證，不得偽裝為已錄得的官方必然序列，也不應拿它阻止其餘 Client 靜態研究。

## 2. 玩家要求進普通村落：C2S003D

N：`0x5B6250` 的 Town UI 路徑從選中物件 `+0x24C` 所指 row 的 `+0x20C` 取得目的地。`0x4E2E70` 查角色已開放 Town 資料及 `CTownInfoTable=FE1D98`，包含 **TYPE==1** 條件。通過相應 UI／隊伍 gate 才到 `0x5B64E9 → 0x4A3620`；確認事件另有 `0x5B8314 → 0x4A3620`。不是任何按鈕皆無條件發包。

`0x4A3620` 的 3-byte application：

```text
+0 u16 003D
+2 u8  destination（caller 參數低 BYTE）
```

sender gate `FBA798==0` 才以 `FBA854` virtual+10、connection key0、length3 入列。**入列不等於 WSASend 完成或 Server 同意**。這個 producer 不建立 Town actor、不挑出生點、不直接載 Map182；Server 收到後需要獨立決定角色權限、目的地及 instance，再提供下列 Client 可消費資料。

## 3. 正常場景安裝、控制器與 CSquare 的反證

### 3.1 0099/3 → CMissionRoom（N）

管理器表 `FD2CFC` stride8；`0x4B7E2F` 寫 `[FD31C4]=0x4B9320`，索引為 `0x99`。`0x4B9320` 讀 app+2 BYTE，**只接受3**；其他值走 Invalid GameMode。有效分支配置 `0xBD58` bytes，基底 ctor `0x4ADD50`，安裝 vptr `C07098`，寫 scene marker `4D495352`（MISR），再 `0x4B7D50` 安裝場景。

```asm
4B9354 cmp al,3
4B9379 call 4ADD50
4B937E mov dword ptr [esi],C07098
4B938E mov dword ptr [D6A674],4D495352
4B9398 call 4BCB40
4B93A5 call 4B7D50
4B93E6 mov dword ptr [F9392C],eax ; subtype/game-mode 3
```

RTTI：TypeDescriptor `F7E084`，name `F7E08C = .?AVCMissionRoom@Scene@@`；COL `C69AD8`；vtable `C07098`。重要 slots：+04=`4C4670`，+10=`4BCBA0` init，+14=`4BCEB0` cleanup，+18=`4BCF60` update，+2C=`4B2570` ready。

`0x4B7D50` 先對舊場景執行 cleanup/destruction，再寫 manager+5EAC=newScene，呼叫新場景 virtual+10。不能只換 map 字串而省略場景生命週期。

### 3.2 CMissionRoom init（N）

`0x4BCBA0` 包含 cutscene controller reset、舊 controller 清理、World actor/owner 清除及 preload 狀態清理。控制器若已是 `FBA7AC==1`，沿用後呼叫 `544F50` reset；否則建立 **0xB4 bytes** controller、vtable **C0FA6C**、`FBA7AC=1`、`FBA7A4=controller`。RTTI 名稱為 **CMissionRoomController**。UI mode 為 **4**（FAADF0），不是場景 subtype、TownType 或 Quest type。

控制器主要 slots：+04=`545040` attach；+08=`5451D0`；+14=`545210` clear；+0C/+10均指向`5F5D10`的空返回；+1C=`545290` 取 slot；+20=`5452B0` 取首 actor；+2C=`548350` update。三個 actor slot 在 controller+0C/+18/+24；對應 metadata 在+10/+1C/+28。不可將 0xB4 控制器與其他同 offset 的類別混合。

### 3.3 CSquare 並非同一套初始化（N）

CSquare vtable `C06FB0`，init `4BBC10`；它建 **controller kind2**／`CSingleController`、UI mode2，還有自身 C2S0043 的入場路線。MissionRoom 是 kind1／UI4；ScenarioField、MissionField、DuelField 的 subtype 另屬別域。**因此「0069/7 能顯示廣場」不能推出它就是普通村落模式；005F/6 也不能當 Town。**

## 4. 地圖／Town context／preload 與必要偏序

### 4.1 0012 是具破壞性副作用的載圖介面（N）

基底 `4ADD50` 登錄：07→4AE4D0、08→4AF530、0A→4AF920、12→4B24F0、14→4C5930、15→4B2620、27→4B2AF0、38→4B1BF0。`4BCB40` 的 MissionRoom 附加表不把這些入口改成另一套 Town 封包。

```asm
4B253A call 5449A0       ; clear old checkpoint objects
4B2545 call 544F50       ; reset player controller / bindings
4B254D mov ecx,[eax+2]   ; eax=app；DWORD map selector
4B2557 call 4DF510       ; world map consumer
```

`0012` app 最少6B；`4DF510` 從 MAP/BOUND 等資源容器查資料，MAP/BOUND 查找及載入分別參見 `4DF787→7C1E00`、`4DF9C7→4DF1A0`。同 map/name 有快取分支，**不代表 0012 前面清掉的 checkpoint/control binding 仍存在**。scene init 的清場與 map loader 的有條件清理也不能說成同一件事。

### 4.2 0038 的 Town context 不是載圖命令（N/R）

`4B1BF0` 保存 context。byte+2 為0或5的支線，從 **WORD app+3** 取 TownID：`4B205A→540A40(TownID)` 預載，`FAB1BC` 寫 current town，再重算任務候選 `500240`。整個已檢視 handler 有讀到 app+8，故不要把它縮成只有5B的封包。其他 type2/type6 讀 WORD+7 等 field/case 資料，與 Town domain 分開。

`540A40→541C00/541F10/541A50→5417E0` 讀 `_TownList.xml` 的 NPC IDs 並載入資源。**預載九個 NPC ≠ 建立九個 CNPC ≠ 建立九個互動區域**。本輪直接解碼的 Town1 roster 為：

`10001,10002,10003,10008,10013,10014,10047,10048,10015`。

### 4.3 供 S00 實作的相依偏序（S；不是官服錄包順序）

```text
合法 destination/instance 決策（C2S003D 或既有 Quest/return 情境）
 → 安裝合適正常 scene；選用 MissionRoom 時為 S2C0099/3
 → 建立 Town context/preload 與實際 Map selector（不同域）
 → 完成最後一次 0012／會清場的操作
 → 有效 room cache／self membership、owner records、player/NPC actors
 → 自有角色 000A binding；完整 0027 checkpoint snapshot
 → 必要角色狀態／UI／資源就緒，cutscene 不再阻擋
 → 0014 ready；loading UI end 另按既有23/24契約
 → 正常移動、NPC互動、任務接續分別驗收
```

硬性依賴是：**owner+actor 在 000A 前；checkpoint／binding 在最後一次0012後；room pointer 必須在互動 tick 前有效**。room cache 可先下發再發08，也可由8F自有成員分支後設 current room；不硬造唯一總順序。23/24 只參照已有 loading UI 研究，不把24視為 controller ready，也不新增假的 ready ACK。

## 5. 玩家與 NPC 的實體初始化：0007、0008、000A

### 5.1 S2C0007：26-byte actor 記錄（N）

`4AE4D0`：count=floor((appLen−2)/26)，r=app+2+26*i。以下是實際 reader 的欄位，不是自訂封包：

| record offset | 型別／用途 |
|---|---|
| +00 | u16 actor key；**低 BYTE 同時作 class selector**，不是任意可指派的16-bit entityID |
| +02 | u8 PRE/variant；建立資源鍵時取 PRE−1 |
| +03 | 本輪不賦予業務意義 |
| +04 | u16 model/resource ID |
| +06/+10 | f32 x/y；新 actor 的位置來源 |
| +14 | f32 傳 virtual+5C（scale 路線） |
| +18 | u32 owner key → actor+9C |
| +22 | u8 傳 virtual+58（朝向路線） |
| +23 | class-specific 欄位，不能一律套同語意 |
| +24 | u8 → actor+90 |
| +25 | u8 → component virtual+8；不猜原服初始狀態值 |

class0 → player `4CD6F0`；class6 → `CNPC/4D2120`；class1是 monster，其他 switch 分支不在此當 NPC 替代。複合資源鍵使用 `((class<<8)|(PRE−1))<<16 | model`。**actorKey 低位元組6、model10002、checkpoint kind3/selector10002 是三個不同欄位／分類。**

`4AEB43` 把 r+6 傳 actor virtual+44，`4AEB49` 呼叫。player vptr `C07B44` 與 NPC vptr `C0CA9C` 的 +44 均為 **4C8B90**；它先調 **4CAB80**，將兩個 float 寫 actor+A0/+A4，更新 dirty 狀態並可能調 virtual+38，再做顯示同步。這條 writer 沒有提供 Town1 的預設出生座標；**收到 x/y 並寫入，不等於座標已通過碰撞／可達性驗證**。

重要反例：`4AE58F` 查 actor key 已存在時，不走新建/上述 position writer，跳到下一筆。**重送同 key 的0007不能當作通用 teleport／reposition**。需按既有生命週期或其他已證同步介面處理；本輪不新增猜測的移動封包。

### 5.2 S2C0008：owner／room lookup 資料（N）

`4AF530`：WORD app+2 非零先清舊 owner map；r=app+4+22*i，count=floor((len−4)/22)。

| r offset | 寫入 owner（0x2C bytes）／用途 |
|---|---|
| +00 u32 | owner ID；與自有 ID F93930 比對 |
| +04 u8 | owner+20 |
| +05 u8 | bit0→owner+28、bit1→owner+29 |
| +06 u32 | owner+0C |
| +10 u32 | owner+10 |
| +14 u16 | owner+14；自有 owner 時作 `53A9D0` 的 **room lookup key** |
| +16 u16 | owner+16 |
| +18 u16 | owner+18 |
| +20 i16 | owner+24，signed extension |

未具體命名者保留 offset，不能填「看起來合理」的隊伍/公會/等級值。self 分支 `4AF82D→53A9D0`，`4AF839` 將結果寫 **FB7258/current room**；缺 room 會寫NULL，見第6節。

### 5.3 S2C000A：自有控制綁定（N）

`4AF920`：app+2 u32 owner；app+6 **signed BYTE count**；app+7起每筆兩個WORD，stride4。先查 owner，缺失便失敗；再以 actor key 查已有 actor。對 self owner，清舊 controller slots，再以 virtual+4 attach（兩WORD相等路線）或 virtual+8 處理另一種關聯；最後 virtual+10；此CMissionRoomController的+0C/+10都是空返回，不把它們當另一個Server握手。第一筆標 actor+98=1、owner+4/key與owner+8/model；actor+9C保存owner。

`545040` 往三個空 slot之一附加 actor並設 controller+4=1；`545210/544F50`會清 bindings。**故同時需要正確 self owner、已建立 actor、正確 actorKey 與匹配 room，不是發000A任意兩個數字即可。** 另一個WORD不同時不推定為等價成功綁定。

## 6. 本輪新閉合的重要阻塞：room cache／membership／current room

### 6.1 為何有玩家模型仍不能互動（N）

MissionRoom controller `548350`：先看 controller+4非零，呼叫基底 tick `5452C0`，然後要求首 actor+0C非NULL，**FB7258/current room非NULL**，才繼續後面的房間/成員/UI gate與 checkpoint 掃描。room NULL阻擋的是此段後續互動分支；**不能由此斷言基底 tick 中所有移動也必定停止**。

```asm
54837B cmp dword ptr [esi+4],0
548393 call 5452C0
548398 cmp dword ptr [esi+0C],0
5483D1 mov eax,[FB7258]
5483D9 test eax,eax
5483DB je 548381
5484D5 cmp byte ptr [eax+7E1],1 ; eax=input owner
5484E7 call 544A00 ; manual=1
548523 call 544A00 ; manual=0
```

`53A9D0` 以WORD room key查 `FB1380+5EC8` map。找不到時在sender gate允許下，分別送 **C2S00C8、00C9**：各4B=`[u16 opcode][u16 room key]`，並返回NULL。**它不自動建房間，也不保證查詢已有Server回覆。** 這可解釋一種「08/07/0A/14都送了，NPC還是無法接續」的靜態原因；不等於本輪已觀察到使用者實機遇到此原因。

### 6.2 真正可建立資料的 S2C008E／008F（N）

`539DF0` 註冊 room manager handlers：8E→`53A050`、8F→`53A0A0`。88→`53A440` 是通知/錯誤UI，**不能因00C8字面相近就把0088當room detail ACK**。C8/C9與8E/8F的官服一對一配對未證，以下只列原生資料效果。

**008E：至少0x31 bytes 的已讀欄位範圍。**

```text
app+02 UTF-16 NUL terminated name（下一固定欄位在+2C；native loop未見長度上限）
app+2C u8  → room+20
app+2D u16 → room+24
app+2F u16 → room key，傳AX給53A960
```

`53A960` 找不到 room 時建立0x38 bytes record、保存 key+0、字串+4、成員vector+28/+2C/+30，插入 map；有資料則取既有record。008E本身**沒有直接把這筆設為 current room**；後續self08或8F的相應分支才完成此連結。

**008F：header8 + 9*n bytes。** WORD app+2 room key→53A960；DWORD app+4非零清該room舊成員vector。每筆r從app+8起：ownerID DWORD+0，BYTE+4/+5，flags WORD+6，BYTE+8。flag bit7/8/9分別寫member+7/+8/+9，BYTE+8寫member+B；bit0/1/5影響member+6與局部通知。重要正流程分支：

```asm
53A1B1 test al,4                       ; member flags bit2
53A1C0 cmp [ebx-6],eax                 ; r+0 vs selfOwner
53A1C8 movzx ecx,word ptr [eax+2]       ; eax=app
53A1D0 call 53B750                     ; select current room
53B77E mov [esi+5ED8],eax              ; esi=room manager           ; global FB7258
```

隨後 `53AAA0` 等維護 room members/UI；不可僅發一個裸key便當作完整成員狀態。Server應維護 roomKey/ownerID/member flags 的一致性，根據已證欄位建立相容資料；**本稿不替其他flag、room+20/+24或官方實例政策猜值**。

可用偏序是「room cache 先存在→self08 lookup成功」，或「8F確實包含self+bit2→53B750選中room」。若08先於cache而寫了NULL，單有後來008E**不直接**修正FB7258；需走已證current-room writer，不能無條件假設會自動恢復。

## 7. 互動區域是獨立資料：S2C0027 → checkpoint → NPC事件

### 7.1 全量替換與18-byte schema（N）

`4B2AF0` **先** `5449A0(FB79F0)` 清除全部舊checkpoint，再按floor((len−2)/18)筆建立。r=app+2+18*i：

| r offset | 型別 | ctor／物件結果 |
|---|---|---|
| +00 | u16 selector | checkpoint+F6 |
| +02 | i8 kind | 先sign extend成WORD，再保存+F4 |
| +03 | u8 enabled | +105 |
| +04/+08 | f32 x/y | +A0/+A4 |
| +0C | f32 radius | +FC；kind0的Portal資源支線另可調整 |
| +10 | u8 activation policy | 擴展存DWORD+100；0為需要manual input的路線 |
| +11 | u8 flag | +F8；本輪不猜完整業務枚舉 |

配置0x108 bytes，`4B2BD5→543700`；vtable `C0F7FC`、virtual+64=`544070`。新object加入FB79F0的vector。**0027不是增量append API**：分成九包各一NPC而不重送前面的區域，會使最後只留下最後一包的區域。

### 7.2 距離與真正事件入口（N）

`548350→544A00` 由當前controller virtual+20取首actor，用actor+A0/A4與checkpoint中心比較。`544730` 要求enabled(+105)!=0，計算d²=(x−cx)²+(y−cy)²，**strict radius²>d²** 才inside；等距邊界不算inside。policy+100==0時，還須manual參數非0。+104作inside/重複觸發latch；policy非0走自動進入/離開的另一分支，不能把兩種模式視為等價。

`544A00` 選擇符合範圍的最近候選，經全域/UI gate後呼叫virtual+64→544070。kind3在相應world/mode/quest gate成立時可產生F43D9；nested NPC selector再找type2任務候選。**NPC class6不是checkpoint kind3；NPC可見但沒有0027區域、不在半徑內、未按互動、room缺失或候選不符，都不是「Server只差一個成功ACK」。**

沿用W3-05/T16-127界線：kind3不是直接544020→001C的簡化路線；F43D9後續wrapper條件可有另一條001C producer。不可因本地event存在便編造001D回覆解鎖。

### 7.3 Town1 NPC資源與主線關係（R，座標仍U）

| NPC model ID | PRE | Actor FILE | 原table SCALE字面值 | type2主線 |
|---|---:|---|---:|---|
| 10001 | 1 | 01_Berta | 120 | 此十筆主線無giver關聯 |
| 10002 | 1 | 01_Elder | 120 | 117/121/122/131/132 |
| 10003 | 1 | 01_Selien | 120 | 此十筆主線無giver關聯 |
| 10008 | 1 | 01_Hansen | 120 | 120 |
| 10013 | 1 | 00_Ertale | 120 | 此十筆主線無giver關聯 |
| 10014 | 1 | 00_Skmaster | 120 | 此十筆主線無giver關聯 |
| 10047 | 1 | 01_Yuri01 | 100 | 118/119 |
| 10048 | 1 | 01_Yuri02 | 100 | 123/124 |
| 10015 | 1 | 00_Mixer | 120 | 此十筆主線無giver關聯 |

Table SCALE是資源元資料，**不直接把120/100塞進0007 float scale**；需保持資源／封包縮放域分開。NPC10013/10014/10015的npctable TYPE分別1/2/6，亦不能直填checkpoint kind。

對Q117可描述條件式介面：正確Town1/context與Demand15、對應NPC視覺actor、checkpoint kind3/selector10002等原生路線及其gate；**Town1原配置是否正是此kind、NPC原位置、半徑、activation/flag皆尚未直取，不能當原版樣本。** 多種服務NPC不能一律造kind3。

## 8. Ready、輸入與loading：不能只清一個旗標

`S2C0014 → 4C5930` 是activeScene virtual+2C跳板；在CMissionRoom該slot為 **4B2570**。

```asm
4B259D mov [eax+4],ebx         ; eax=controller, ebx=1
4B25CE cmp dword ptr [FB73E8],0 ; cutscene controller+28
4B25D5 jne 4B2601              ; busy時略過bit0清除
4B25FA and dword ptr [FB8830],FFFFFFFE
```

`S2C0015→4B2620` 將controller+4清零並走actor輸入清理。W3-06核實的 `Q.EnableInput/562980` 則是 `FB8830 &= FFFFFFFD`，只清bit1；DisableInput設bit1。**0014在cutscene busy時收到，不能推定稍後RevPhase1會連bit0一起清。** 其他modal/input gate也可能存在，bit0/bit1都清仍不是全套可玩驗收。

S00應將「正常scene ready」「cutscene收尾」「loading UI消失」「controller綁actor」「room/member有效」分開觀察。不因一張村落畫面或loading消失就標初始化PASS；也不發任意Quest完成封包充當通用解除鎖定。

## 9. 合法出生座標：本輪尚未核定，阻塞精確範圍

### 已查明與已排除（N/R）

1. 正常新建player/NPC的x/y直接來自0007；互動中心/半徑來自0027。這些interface足以讓相容Server供應配置，**不必等待官服後端源碼**；但配置仍須有碰撞與地圖的正當依據。
2. Table/Event本輪唯讀解碼1026/7382個members；對Town相關表、NPC表及命中town001字串的腳本檢索。已見的是Map名、NPC資源、任務、演出；**未取得可認定為普通Town1玩家出生／九NPC區域配置的資料**。這是有界搜尋結果，不聲稱遊戲所有封裝皆不存在配置。
3. `_PositionList.txt` 是665筆×5float，`4F9D80`載入FE1A90；其外部直接使用點`4BAA3C`位於以world值+50000作map selector的展示路線，`4BAB0A→4DF510`。`_SysMapList.xml` 的500xx亦有victory_*／演出地圖。**不能取row1或某個(x,y)當Town1出生點**。
4. `TutCheckPointList.xml` 只有教學checkpoint；`CameraMovePosition.xml`為角色鏡頭；`EventObjects.xml`為物件avatar/motion關係；`_PortalList.xml`為效果資源；都未提供Town1合法spawn。
5. Quest15 `CreateObject`、Scene3的734/744等座標、舊square候選格點及900/900合成值全部排除作「已證普通村落spawn」；界內也不等於可走或可達。

### 真正缺少的原始資料

Git既有 `kr-temp-roy/T06/evidence/town12-resource-bytes.json`（blob `1f8bca927dda9d46871950b39eb7416a4b382cc4`）只有原件metadata與prefix，**不是完整BND格資料**。

| 需要的原件／依據 | 已知識別 | 用途／目前缺口 |
|---|---|---|
| **BoundMap/town001.bnd** | **12044B**，SHA256 `30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6` | 最低優先：完整v0 collision layers、阻擋格、連通性；現在僅64B前綴，無法證明任一格可走 |
| 原封裝 Map/BoundMap.stp | SHA256 `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` | 本地可從此提取上列member；不必上傳整包到Git |
| Town/town001D.fld/.mre | fld SHA `92c9684cdbebb7f8bda29e8687ed96540b9ebc84abaa3861cfe2fd719f1bf63f`；mre SHA `4a0429a4a95e8261e529967e6b02eee465e6c7b912e14158b2b0eaaca951b4f8` | 核地圖幾何/配置/資源依賴；FLD靜物也不能自動當NPC或spawn |
| town001.mef 或可信原始placement／入村記錄 | 目前沒有本輪可校驗原件 | 原NPC位置、區域kind/selector/radius/flags、入口/回城點的來源；不宣稱MEF一定包含全部項目 |

已保存header支持v0、grid768×768/world1536×1536；**沒有full BND不得從world尺寸推一個「合法點」**。同時缺原位置不代表Server不能重建：S00可明示選擇重建spawn/placement policy，取得完整同版BND後核對格語意、角色半徑/餘裕、路徑連通與NPC可達，再進正流程遊玩驗收。這是相容Server設計，不冒稱官方原點。

## 10. 可直接交開發的最小契約與未完成項

| 項目 | 本輪能交付 | 尚缺／責任 |
|---|---|---|
| 普通村落意圖 | TYPE1 gate、003D/3B producer | 實例/權限/目的地政策由S00決定 |
| 正常scene/controller | 0099/3→CMissionRoom→kind1/0xB4/CMissionRoomController/UI4、清場與ready | Town1採用此組合需S00明示並實機驗；不是官服配對證明 |
| 載圖/context | 0012 DWORD map、0038 Town context/preload、破壞性reset偏序 | Map182與Town1相容配置；實際資源依賴/地圖運行驗收 |
| 玩家 | 08 owner、07 actor/xy、0A binding完整有界layout與consumer | 完整角色數值/資源初值沿T04等既有結果整合，不猜值 |
| 房間 | 8E cache、8F成員／self current-room writer、C8/C9缺資料查詢 | room metadata/flags權威政策；不可把field/type等不同域混用 |
| NPC與互動 | 九NPC靜態資源、07 CNPC與27全量區域、距離/manual/current-room gates | **原NPC/區域位置及kind/radius/flags未核定** |
| 合法spawn | xy消費鏈、候選來源排除、缺件SHA及驗證方法 | **未取得full town001.bnd，沒有合法數值；本項受阻** |
| 過場分界 | Lua input bit1與scene ready bit0分開；RestoreMap不等於bootstrap | cutscene與normal scene排程/待遊玩驗收 |

正常人工驗收卡（全部 **NOT_RUN**）：合法發起入村 → 正常scene身份/Map182/context1正確 → room/self owner/actor binding一致 → 非演出角色落在核可位置且能行走 → 預期NPC可見 → 27區域與NPC位置相容、正確互動事件 → NPC10002的Q117候選/接取可走原生流程。每一步記錄build/SHA、app bytes、scene/controller、Map/Room/Town/actor/checkpoint typed IDs及畫面；不能把其中一項PASS當全村初始化PASS。

取消、重登、重入、負向、競態、故障、安全/壓測依目前使用者政策延後，本輪未跑。**Client可證介面、Server待開發、跨功能待整合、實機驗收是不同狀態。**

## 11. 證據復現與歷史來源

```powershell
python .\W3-07-normal-town\verify.py --bin <原始Tartaros.bin> --table <原始Table.stp> --event <原始Event.stp> --exe <原始Tartaros.exe>
# 安裝GNU objdump的環境可額外加：--assembly-dir <全新輸出資料夾>
```

工具只讀原件、檢查來源/PE映射/slice/member hashes，可輸出反組譯；不執行遊戲或Lua、不改DB、不注入或送包。實際本輪結果：41code+7data+14members hash check相符；`runtime=NOT_RUN`、`legal_spawn=NOT_ESTABLISHED`、`full_semantic_review=NOT_CLAIMED`。完整切片起訖、raw與SHA見manifest；末端若截到下一指令，不用截斷行作肯定主張。

既有來源的精確適用邊界：W3-06 blob `a170f02bb5675a6b514b20bcb4aeebd83fe17542`（cutscene callback/input）；W3-05 blob `6fa66a3ab7b4e6324182604cc7c0689b9eca2ecb`（NPC事件/C2S分流）；T06 TOWN12-HANDOFF blob `eba0172c7200d287488aad678147da65b90c81e5`（地圖候選與舊缺口）；T07 town dependency blob `1ec858d1a3db2f7cb959a6637d6e3455e04cc794`；T16-127 blob `4e8e07719e882b4525481641dce929dd9786b87d`。本輪是在這些原稿外補證，不把原作者的待驗證改成FULL-PASS。

**交付結論：可將上述有界Client介面與相依偏序交S00實作；不能宣告已完成普通Town1合法落地。接續的精確阻塞是同版完整碰撞/placement資料，而不是再盤點更多無關函式或等待不可得的官服內部演算法。**
