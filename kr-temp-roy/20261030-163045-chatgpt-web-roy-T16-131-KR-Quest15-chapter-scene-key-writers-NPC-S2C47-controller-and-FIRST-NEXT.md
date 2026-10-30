# T16-131 — Quest15 / Pindos：劇情 primary/scene key 的原生 writer、NPC 與 S→C 0x47 入口、FIRST/NEXT consumer（KR BIN-first）

- Author: `chatgpt-web roy`; build time: `2026-10-30T16:30:45+08:00` Asia/Taipei. 正式段號 **T16-131**，沿用 T16-130 之後的研究規劃；不重編舊稿、不把 QuestID 當正式段號。
- **KR 原件**：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` 11,241,597 bytes SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Table.stp` 5,248,784 bytes SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。原件唯讀、沒有執行/修補/上傳任何二進位。`.text` PE VA=`raw+0x400C00`；`objdump -b binary` 的 `.data` 是人工輸入格式標籤，**不代表真正 PE section 名稱**。
- **GitHub 查證**（此輪開始）：`main=a8d6f73945829425cf8d58798199bc930d814a38`，`t16/roy/chatgpt-web` 既有 ahead5 / behind144。此同一對話的 main→T16 一次性 Merge 已於本對話前段完成，**本輪依03不再自動同步**。最新 T16 inbox 無 S00 RR、唯一 RR 台帳無 T16 owner 項。T01 固定 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001 — NEEDS_FIX` 仍存在；使用者明確指定131，暫時延後該獨立勘誤、不覆寫或採用已知錯誤。
- 本輪研究符合最新 T16-only 規劃 T16-131；研究**任務/劇情鍵的來源及 native gate**，不是通用 STP 解包、地圖引擎逆向或擅自替其他 Task 派工。既有 T16-124..130 及 `shared/verified-knowledge/` 僅有的有限主張分開引用；本篇未獲 T01 FULL-PASS。
- **證據等級**：標為「本輪 KR 原生 machine code」或「繼承 T16-xxx 有界證據」或「假設/Server待證」。所有新的記憶體關係都給出機器碼偏移與先決條件。

## I. T16-131 研究問題、核心結果及精確完成界線

本段明確目標：從 Quest15 的 NPC/事件/入站狀態追到 (A) 章節物件鍵、(B) 劇情控制器 primary/scene DWORD **所有本輪可識別的 writer**，證明 FIRST/NEXT 和 Event SceneList 如何消費，不因現有 Table.stp 仍是未解包 STPD 就停止其餘 Client 靜態資料流。

### A. 三個**真正**有來源的 controller writer 入口

1. **NPC 本地任務事件 → 控制器**（本輪原件閉合條件式 writer）：`0x5B9407` 從 `0x5008B0` 拿 type2 first-match QuestID（`WORD`, zero if no match），`0x5B943F` push second argument `1`，`0x5B9441` push first `QuestID`，以 `ECX=0xFB73C0` 呼叫 `0x561760` (`0x5B9447`)。`0x5618E3/E6/E9/EC` 在可達的正常寫入分支，把 `[EBP+8]`→`controller+0x38`、`[EBP+0xC]`→`+0x3C`，`controller+0x28` 設為本地控制狀態。當 `giver=10338` 的 type2 清單符合條件且返回的 first match 為15時，**可證輸入為 `(15,1)`**；此並非「原版 Server 已認定 Quest15 完成」或「Scene3必播」。`0x5008B0` 查不到候選會回0，不保證是15。
2. **入站 opcode `0x47` → 同 controller**（**新封包鍵來源**）：`0x50210B` 將函式指標 `0x503040` 寫入 dispatch 表位址 `0xFAB4DC`。已知表首 `0xFAB2A4` 每 index 8 bytes，`(0xFAB4DC-0xFAB2A4)/8=0x47`。`0x503095..0x5030A7` 從 incoming application `+2,+4` **有號擴展**兩個 WORD，依序 push second 和 first，再呼叫 `0x561760`。若 payload 是已完整且符合路由條件的 `47 00 0F 00 03 00`，讀到 `(15,3)`，可在非忙碌正常寫入分支存入控制器；**這只是測試向量，不是原版 Server 實際發送的封包**，更不表示立即執行 Scene3。
3. **另一個本地/UI wrapper 及 S2C 0x40/0x45 特定分支**：`0x4A9730` 無修改將調用者的兩個 DWORD 傳 `0x561760`；`0x50243B` 及 `0x502889`（各自只在 `[ebx+0x3C/0x44]==2` 的分支）從 `0x422F40` 的結果取 ECX，呼叫 `0x561760`。其原始 pair 的最後來源在這兩條支線包含不同 handler 欄位；**不能把它們都叫成 0x47 或固定 `(15,3)`，也不能將 0x422F40 的 ECX 猜成原始入站 wire byte offset**。

### B. 控制器寫入並不等於立即播放：busy、特殊 gate、延後/清零

- `0x561760` 先 `cmp controller+0x28,0`，並把 `+0x89` byte 清0；busy 時 `0x5617CF..0x5617E4` 只把兩個參數送到 `0x6EDB60` 的其他處理路徑，**跳過**目前這次 `+0x38/+0x3C` 寫入。非忙碌時若 `0xFB92F1!=0` 且第一參數0、角色狀態在 `(9, 4, 25)` 且查找結果不等時，`0x5618C2..0x5618D2` 可能向 `0x4A39A0` 提交 `(0,second)`，提前離開寫入路徑；不能保證 `(0,3)` 也會寫入。
- `0x565720` 是**不同的 scene execution entry**，在 `controller+0x28==0` 時 `+0x89=1`、`+0x38`/`+0x3C` 寫入兩個傳入 DWORD、`+0x28=1`，然後對 `Event/SceneList.xml` 的 `(key,sceneIdx)` 做查找；busy 時呼叫 `0x6EDB60` 轉送並跳過新的 key write。它的**直接 native caller 只有** `0x47B64A`（chapter/object 的 FIRST-scene 結果）、`0x561EF3`（controller NEXT-scene 結果）。
- `0x561DB0` 在 `+0x89!=0` 時可使用 `controller+0x38/+0x3C` 查 `0x47E640` 下一 scene，寫回 `+0x3C`；若 next 是 0 則不呼叫 Lua 查找，並在 `0x561F47/4A` 清零。另一個 `+0x89==0` 且 `+0x28!=0` 的路徑可能透過 `0x4A39A0` 送 `0x3F`（有額外條件）、或者在 `0x562091/94` 清零；`+0x89` 與 `+0x28` 都不可當成獨立的 Server completion flag。

### C. 場景物件鍵從哪來，以及兩個相似 +0x248 不得合一

- `Table/SceneList.xml` `0x47DE40` 解析 CHAPTER 的 `chapterIdx`→row+0 和 `townId`→row+4。`0x47D290` 從 scene/widget container node `+0x10` 取得 row pointer，`0x47D36D` 傳 `ECX=row` 給 `0x47B2B0`；`0x47B2DD/EF` 將 `[row+0]` 傳到**該場景物件** `+0x248`，`row+8` 用於文字。`0x47D558` 複製 `object+0x248` → 事件物件 `+0x120`，`0x47D5A3` 將此 key 查 `0xFC0F68` FIRST，再 `0x47D5B7` 讓場景物件走 `0x47B5C0`。這條可證 `Table chapterIdx → scene object → FIRST`，**不可未經實際資料行推論 chapterIdx=QuestID15**。
- 本輪另觀察到 `0x47CC9E` 也寫入一個 `[EDI+0x248]`，但它是從另一個容器的 source `[record+0]` 寫入的迭代物件，與 `0x47B2B0` caller 的物件指標來源不同。**本輪不能以 offset 同為+0x248 直接判成同一個 live object 的第二 writer 或同一章節紀錄**；這是針對本輪初始 xref 假設的修正，原稿保留兩條及型別邊界。
- `0x47D810` 的特殊 GUI 事件入口在 `[0xFB7258]+0x28/+0x2C` 長度恰為4 bytes 時走 `0x47D9CE`→`0x47D530`；其 caller `0x47C5D0` 對入站 UI event `+0x10` 和 `+8` 有具體 gate（例如 `0x47C639` 檢查某種 event ID 與 `+8>=0x1388`）。這是**本地 GUI gate**，不能把事件 ID `0x177` 或 `0xF4421` 冒稱 Quest15 C→S 或 Server ack。
- `0x47E750` 是由 `0x47B693`、`0x47DDFD` 呼叫的**章節 UI/設定文字發布相關函式**，顯示拷貝 `[EBP+8]`→`[EDI+0x10]`、`ECX`→`[EDI+0x14]`、後呼叫 `0x58EC10` 更新共用字串/名稱。**沒有原生證據說它把 QuestID15 寫入 Server、DB 或 QuestOwner 前置鍵**；不可因名稱 chapter 就把它當任務完成 writer。

### D. T16-131 達標解讀及限制

**已閉合 Client 的「NPC QuestID/入站兩個WORD → scene controller key writer+gate → FIRST/NEXT 正確 key consumer」的條件式資料流，並列出真正可達/拒絕/覆寫/清零及不同物件類型。** T16-131 計畫明定「若缺 Table rows 不可宣稱必然觸發，但要查完可進行的 native writer/gate」。本稿就此**Client writer/gate 有界靜態研究標示完成**。然而 `Table/SceneList.xml` rows（chapterIdx 與 Scene3 序列）、真實 Server 何時送0x47、以及 Quest15 完成→Pindos必然播放皆仍**未證/完整 E2E 未完成**；它們不是因上 Git 就自動變已證。

## II. 欄位/鍵域與反證矩陣

| 欄位／鍵域 | Producer / read | 語義與限制 |
|---|---|---|
| NPC giver / type2 | `0x5B9407`→`0x5008B0` | 回 type2 first-match Quest WORD；15 只在候選及 giver10338 等條件通過且第一筆15時成立 |
| controller+0x28 | `0x561760`,`0x565720`,`0x561DB0` | 本地流程 busy/pending gate，不等於伺服器 quest accepted |
| controller+0x38 | `0x5618E9`,`0x565785`,`0x561EE?` reads | 兩種入口的第一 DWORD；可等15但不保證與 chapterIdx 表 row 同值 |
| controller+0x3C | `0x5618EC`,`0x565788`,`0x561EE5`; cleanup `0x561F4A`,`0x562094` | 第二 DWORD scene/current key；NEXT 更新，清理時設0 |
| controller+0x89 | `0x5617C6` 清0、`0x56575D` 設1 | scene function flag；在 NEXT Gate 用；不可視為 official quest completion |
| chapter record+0/+4/+8 | `0x47E003`,`0x47E043`, earlier T16-130 | 章節索引／townId／name；townId 不是 sceneIdx |
| chapter record+0x24/+0x34 | `0x47DE40` downstream | questIds 與 ordered sceneIdx 分立 vector；**需要實際 rows** |
| scene object+0x248 | `0x47B2EF` source `[row+0]` | Chapter Key，非已確認 Quest15 固定鍵 |
| Event pair `(primary,sceneIdx)` | `0x5658AC..0x56592C` | Event/SceneList key，值 `funcName`，Table row 必須實際匹配 |
| S2C app index `0x47` | `0x503040` reads signed WORD+2/+4 | 入站狀態 pair；`47 00 0F 00 03 00` 是**人造條件測試向量**，非 real trace |

### Three unrelated notions of 15/3 and reason not to conflate

- `QuestInfo.id=15` (game quest)；`TableSceneList.chapterIdx=???` (chapter primary)；`EventSceneList.questIdx=15` (script map's first key)；`SceneIdx=3` (script map second key)。三者可以在某些**輸入**下取同數字，但 Client loader 以不同文字欄位/表存入不同容器；沒有原件行時不能假定普遍 `chapterIdx==QuestID`。
- `S2C 0x38` 世界 `town5` 亦非 ChapterIdx 或 sceneIdx。`NPC ID10338`、Scene3 Lua object10047 更不能當作鍵15或3。
- 若 `0x5008B0` 返回0，NPC producer把0傳進 controller；**不可說0就是合法 Quest15**。若 controller busy，鍵不保證覆寫；若 Scene List miss/empty，FIRST/NEXT返回0，不能用「+1」模擬下一場。

## III. 正常/反例/失敗矩陣（Client靜態）

| 情境 | 可以確證的 Client 結果 | 尚不成立的推論 |
|---|---|---|
| Quest15 candidate first-match ID=15, NPC事件分派到 `0x5B9340` | `0x5B9447` 送 `(15,1)` 給 scene controller；正常空閒分支寫 `+0x38=15,+0x3C=1` | 不保證 Server 接受、立即執行 Scene1 或必達 Scene3 |
| NPC type2 無候選 | `0x5008B0` 返回 WORD0，caller 可傳 `(0,1)`；後續0有特殊 gate | 不保證有任何 Lua Script |
| 入站 app `0x47` payload ID15/index3 | `0x503098..0x5030A7` 將 `(15,3)` 傳 controller；正常空閒 gate可能寫到欄位 | 不保證該 packet 是原版Server提供、立即顯示Pindos |
| `0x47` payload frame不足 / sender framing未知 | 只證 handler按+2/+4讀欄位；未見長度防護在本函式 | 不可臆造 transport frame長度、上層安全驗證、Server policy |
| controller+0x28 busy | `0x5617CF..0x5617E4` 呼叫另一 gate 並跳出 | 不能覆寫已有 key 的保證 |
| controller 狀態特殊與輸入 key=0 | `0x5618C2..D2` 轉到 `0x4A39A0` 特殊路徑 | 不是無條件 scene cache writer |
| `0x565720` 忙碌 | `0x565766..0x565778` 轉另一處理路徑 | 不會本次直接重置已有+38/+3C |
| FIRST key缺 / sceneIdx向量空 | `0x47E890` 返回0 | 不可宣告 Scene3 fallback |
| NEXT找不到old / 到尾 | `0x47E640` 返回0；`0x561EEA` 跳過新Lua；`0x561F47/4A` 可清理鍵 | 不可宣告 sceneIdx=old+1 |
| Scene3 Event mapping命中 | `0x565720` 查 `(15,3)`命中後以 funcName 建載入路徑／call VM | 無法反推 NPC click 必然走到此鍵 |
| Scene3 Event mapping不存在 | 查找未命中時在 `0x565926` 提前跳離 script load | 不存在的 pair 不能用類似腳本名稱替代 |
| `0x47D810` UI gate沒有唯一選項 | 不進 `0x47D9CE → 0x47D530` | 不能將任意 GUI 事件當 chapter trigger |
| `0x47CC9E` 複製另一物件+0x248 | source record+0 被複製 | 與 `0x47B2EF` 同欄位號不代表同一物件 |

## IV. 呼叫關係與直接指令 xref（本輪從 BIN 直接掃描 E8 relative target；只計 direct-call，不含 indirect/vtable）

此列表是**候選指令字節掃描的 direct E8 xref**，每個重要位置再附下文 disassembly 驗證；在隨機資料中匹配 `E8` 仍可能是假陽性，不能只據 xref 判為所有 caller 已完備。`vtable`／jump-table 間接 caller 額外受限；同時每個具體函式的 `E8` 呼叫端已逐段查明。

- `0x561760`: `0x4A9792, 0x502447, 0x502895, 0x5030A7, 0x5B9447`
- `0x561DB0`: `0x561D81, 0x56288C`
- `0x565720`: `0x47B64A, 0x561EF3`
- `0x47B2B0`: `0x47D36D`
- `0x47D530`: `0x47D9DA`
- `0x47E640`: `0x561EDE`
- `0x47E890`: `0x47D5AF`
- `0x47D290`: `0x47C8FA`
- `0x47D810`: `0x47C65E, 0x47C66B, 0x47C6BB, 0x47D521`
- `0x47E750`: `0x47B693, 0x47DDFD`

## V. Native KR BIN disassembly appendix (VA, raw offset, SHA256 for every span)

以下組別是**本輪實際由原件重新反組譯**，不是沿用或偽造 T16-130 的反編譯段落。每組 bytes=`BIN[VA-0x400C00:...]`，並附 SHA256；由已確認函式/基本塊起點開始，但區段尾可能截斷下一指令，主張僅依完整的目標指令。

### N01. Inbound application dispatch table: index0x47 = 0x503040, non-equivalence with 0x40/0x45

- VA `0x5020CF..0x502125` [end exclusive]; raw `0x1014CF..0x101525`; **86 bytes**; SHA256 `cf3a5af08fa89aa2aa0e98437b41854ab2cf2e87f8e0d33f20cbb6f4a82626e4`.

```asm
005020cf <.data+0x1014cf>:
  5020cf:	c7 05 a4 b4 fa 00 70 	mov    DWORD PTR ds:0xfab4a4,0x502270
  5020d6:	22 50 00 
  5020d9:	89 0d a8 b4 fa 00    	mov    DWORD PTR ds:0xfab4a8,ecx
  5020df:	89 15 9c b4 fa 00    	mov    DWORD PTR ds:0xfab49c,edx
  5020e5:	89 0d a0 b4 fa 00    	mov    DWORD PTR ds:0xfab4a0,ecx
  5020eb:	c7 05 cc b4 fa 00 d0 	mov    DWORD PTR ds:0xfab4cc,0x5027d0
  5020f2:	27 50 00 
  5020f5:	89 0d d0 b4 fa 00    	mov    DWORD PTR ds:0xfab4d0,ecx
  5020fb:	c7 05 d4 b4 fa 00 40 	mov    DWORD PTR ds:0xfab4d4,0x502b40
  502102:	2b 50 00 
  502105:	89 0d d8 b4 fa 00    	mov    DWORD PTR ds:0xfab4d8,ecx
  50210b:	c7 05 dc b4 fa 00 40 	mov    DWORD PTR ds:0xfab4dc,0x503040
  502112:	30 50 00 
  502115:	89 0d e0 b4 fa 00    	mov    DWORD PTR ds:0xfab4e0,ecx
  50211b:	c7 05 c4 b5 fa 00 c0 	mov    DWORD PTR ds:0xfab5c4,0x5030c0
  502122:	30 50 00
```

### N02. S2C 0x47 signed WORD decoding; both arguments into controller

- VA `0x503040..0x5030BF` [end exclusive]; raw `0x102440..0x1024BF`; **127 bytes**; SHA256 `bb262cf90e46e985bd2ffca7af9d529db9ddb6552659ee17e9674ad05bea3a53`.

```asm
00503040 <.data+0x102440>:
  503040:	55                   	push   ebp
  503041:	8b ec                	mov    ebp,esp
  503043:	6a ff                	push   0xffffffff
  503045:	68 ae b2 93 00       	push   0x93b2ae
  50304a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  503050:	50                   	push   eax
  503051:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  503056:	33 c5                	xor    eax,ebp
  503058:	50                   	push   eax
  503059:	8d 45 f4             	lea    eax,[ebp-0xc]
  50305c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  503062:	b8 01 00 00 00       	mov    eax,0x1
  503067:	84 05 b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,al
  50306d:	75 26                	jne    0x503095
  50306f:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  503075:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  50307c:	e8 ef d0 05 00       	call   0x560170
  503081:	68 10 d1 bc 00       	push   0xbcd110
  503086:	e8 8f f2 38 00       	call   0x89231a
  50308b:	83 c4 04             	add    esp,0x4
  50308e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  503095:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503098:	0f bf 48 04          	movsx  ecx,WORD PTR [eax+0x4]
  50309c:	0f bf 50 02          	movsx  edx,WORD PTR [eax+0x2]
  5030a0:	51                   	push   ecx
  5030a1:	52                   	push   edx
  5030a2:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5030a7:	e8 b4 e6 05 00       	call   0x561760
  5030ac:	33 c0                	xor    eax,eax
  5030ae:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5030b1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5030b8:	59                   	pop    ecx
  5030b9:	8b e5                	mov    esp,ebp
  5030bb:	5d                   	pop    ebp
  5030bc:	c2 0c 00             	ret    0xc
```

### N03. NPC event: type2 first-match candidate yields a WORD QuestID and controller pair (id,1)

- VA `0x5B93FF..0x5B9485` [end exclusive]; raw `0x1B87FF..0x1B8885`; **134 bytes**; SHA256 `c20ff7f2bd3a6a4bc089bc845c2ded6c3bc961dddb1f338c91ca0e2d28c42fc5`.

```asm
005b93ff <.data+0x1b87ff>:
  5b93ff:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  5b9402:	ba a0 b2 fa 00       	mov    edx,0xfab2a0
  5b9407:	e8 a4 74 f4 ff       	call   0x5008b0
  5b940c:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  5b9413:	0f b7 f8             	movzx  edi,ax
  5b9416:	75 27                	jne    0x5b943f
  5b9418:	b8 01 00 00 00       	mov    eax,0x1
  5b941d:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  5b9423:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5b9426:	e8 45 6d fa ff       	call   0x560170
  5b942b:	68 10 d1 bc 00       	push   0xbcd110
  5b9430:	e8 e5 8e 2d 00       	call   0x89231a
  5b9435:	83 c4 04             	add    esp,0x4
  5b9438:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b943f:	6a 01                	push   0x1
  5b9441:	57                   	push   edi
  5b9442:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5b9447:	e8 14 83 fa ff       	call   0x561760
  5b944c:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5b9453:	b8 1c 00 00 00       	mov    eax,0x1c
  5b9458:	66 89 45 e8          	mov    WORD PTR [ebp-0x18],ax
  5b945c:	66 8b 4e 18          	mov    cx,WORD PTR [esi+0x18]
  5b9460:	66 89 4d ea          	mov    WORD PTR [ebp-0x16],cx
  5b9464:	66 8b 56 1c          	mov    dx,WORD PTR [esi+0x1c]
  5b9468:	66 89 55 ec          	mov    WORD PTR [ebp-0x14],dx
  5b946c:	0f 85 e1 00 00 00    	jne    0x5b9553
  5b9472:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5b9478:	8b 01                	mov    eax,DWORD PTR [ecx]
  5b947a:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5b947d:	6a 06                	push   0x6
  5b947f:	8d 55 e8             	lea    edx,[ebp-0x18]
  5b9482:	52                   	push   edx
  5b9483:	6a 00                	push   0x0
```

### N04. NPC candidate function return zero versus first WORD ID

- VA `0x5008B0..0x500944` [end exclusive]; raw `0xFFCB0..0xFFD44`; **148 bytes**; SHA256 `aeee21cd72e41936104913bf9baa86f11b09632e77fa568f145237f67f62928c`.

```asm
005008b0 <.data+0xffcb0>:
  5008b0:	55                   	push   ebp
  5008b1:	8b ec                	mov    ebp,esp
  5008b3:	83 e4 f8             	and    esp,0xfffffff8
  5008b6:	6a ff                	push   0xffffffff
  5008b8:	68 28 88 90 00       	push   0x908828
  5008bd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5008c3:	50                   	push   eax
  5008c4:	83 ec 18             	sub    esp,0x18
  5008c7:	56                   	push   esi
  5008c8:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5008cd:	33 c4                	xor    eax,esp
  5008cf:	50                   	push   eax
  5008d0:	8d 44 24 20          	lea    eax,[esp+0x20]
  5008d4:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5008da:	33 f6                	xor    esi,esi
  5008dc:	89 74 24 0c          	mov    DWORD PTR [esp+0xc],esi
  5008e0:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  5008e4:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5008e8:	8d 44 24 0c          	lea    eax,[esp+0xc]
  5008ec:	50                   	push   eax
  5008ed:	51                   	push   ecx
  5008ee:	52                   	push   edx
  5008ef:	89 74 24 34          	mov    DWORD PTR [esp+0x34],esi
  5008f3:	e8 08 01 00 00       	call   0x500a00
  5008f8:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  5008fc:	3b 44 24 10          	cmp    eax,DWORD PTR [esp+0x10]
  500900:	75 20                	jne    0x500922
  500902:	3b c6                	cmp    eax,esi
  500904:	74 09                	je     0x50090f
  500906:	50                   	push   eax
  500907:	e8 00 09 39 00       	call   0x89120c
  50090c:	83 c4 04             	add    esp,0x4
  50090f:	33 c0                	xor    eax,eax
  500911:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500915:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50091c:	59                   	pop    ecx
  50091d:	5e                   	pop    esi
  50091e:	8b e5                	mov    esp,ebp
  500920:	5d                   	pop    ebp
  500921:	c3                   	ret
  500922:	8b 08                	mov    ecx,DWORD PTR [eax]
  500924:	0f b7 31             	movzx  esi,WORD PTR [ecx]
  500927:	50                   	push   eax
  500928:	e8 df 08 39 00       	call   0x89120c
  50092d:	83 c4 04             	add    esp,0x4
  500930:	66 8b c6             	mov    ax,si
  500933:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500937:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50093e:	59                   	pop    ecx
  50093f:	5e                   	pop    esi
  500940:	8b e5                	mov    esp,ebp
  500942:	5d                   	pop    ebp
  500943:	c3                   	ret
```

### N05. Controller 0x561760 entry: busy gate and notification, not unconditional field writer

- VA `0x561760..0x5617E9` [end exclusive]; raw `0x160B60..0x160BE9`; **137 bytes**; SHA256 `a267f1cc4e2406a3b2230369273672b1483a81f6c5100e485cf564e39e6c9c5d`.

```asm
00561760 <.data+0x160b60>:
  561760:	55                   	push   ebp
  561761:	8b ec                	mov    ebp,esp
  561763:	83 e4 f8             	and    esp,0xfffffff8
  561766:	6a ff                	push   0xffffffff
  561768:	68 2c fd 93 00       	push   0x93fd2c
  56176d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561773:	50                   	push   eax
  561774:	83 ec 50             	sub    esp,0x50
  561777:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56177c:	33 c4                	xor    eax,esp
  56177e:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  561782:	53                   	push   ebx
  561783:	56                   	push   esi
  561784:	57                   	push   edi
  561785:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56178a:	33 c4                	xor    eax,esp
  56178c:	50                   	push   eax
  56178d:	8d 44 24 60          	lea    eax,[esp+0x60]
  561791:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  561797:	83 3d 18 ab fb 00 00 	cmp    DWORD PTR ds:0xfbab18,0x0
  56179e:	8b d9                	mov    ebx,ecx
  5617a0:	74 20                	je     0x5617c2
  5617a2:	0f 57 c0             	xorps  xmm0,xmm0
  5617a5:	f3 0f 11 05 24 ab fb 	movss  DWORD PTR ds:0xfbab24,xmm0
  5617ac:	00 
  5617ad:	e8 ae d8 ea ff       	call   0x40f060
  5617b2:	f3 0f 10 05 70 59 c5 	movss  xmm0,DWORD PTR ds:0xc55970
  5617b9:	00 
  5617ba:	f3 0f 11 80 ac 00 00 	movss  DWORD PTR [eax+0xac],xmm0
  5617c1:	00 
  5617c2:	83 7b 28 00          	cmp    DWORD PTR [ebx+0x28],0x0
  5617c6:	c6 83 89 00 00 00 00 	mov    BYTE PTR [ebx+0x89],0x0
  5617cd:	74 1a                	je     0x5617e9
  5617cf:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5617d2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5617d5:	50                   	push   eax
  5617d6:	51                   	push   ecx
  5617d7:	68 ac 06 c1 00       	push   0xc106ac
  5617dc:	e8 7f c3 18 00       	call   0x6edb60
  5617e1:	83 c4 0c             	add    esp,0xc
  5617e4:	e9 9d 05 00 00       	jmp    0x561d86
```

### N06. Controller 0x561760 conditional internal gate: alternate sender and early exit

- VA `0x561823..0x5618DC` [end exclusive]; raw `0x160C23..0x160CDC`; **185 bytes**; SHA256 `2e84b5ad0018fa57cd3f10973cf1af61da1152d7e3596af87348a46f984bf3ab`.

```asm
00561823 <.data+0x160c23>:
  561823:	80 3d f1 92 fb 00 00 	cmp    BYTE PTR ds:0xfb92f1,0x0
  56182a:	0f 84 ac 00 00 00    	je     0x5618dc
  561830:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  561834:	0f 85 a2 00 00 00    	jne    0x5618dc
  56183a:	e8 61 33 ea ff       	call   0x404ba0
  56183f:	83 b8 4c 5f 00 00 09 	cmp    DWORD PTR [eax+0x5f4c],0x9
  561846:	74 1c                	je     0x561864
  561848:	e8 53 33 ea ff       	call   0x404ba0
  56184d:	83 b8 4c 5f 00 00 04 	cmp    DWORD PTR [eax+0x5f4c],0x4
  561854:	74 0e                	je     0x561864
  561856:	e8 45 33 ea ff       	call   0x404ba0
  56185b:	83 b8 4c 5f 00 00 19 	cmp    DWORD PTR [eax+0x5f4c],0x19
  561862:	75 78                	jne    0x5618dc
  561864:	8b 73 78             	mov    esi,DWORD PTR [ebx+0x78]
  561867:	8d 55 0c             	lea    edx,[ebp+0xc]
  56186a:	52                   	push   edx
  56186b:	8d 4b 74             	lea    ecx,[ebx+0x74]
  56186e:	8d 44 24 14          	lea    eax,[esp+0x14]
  561872:	e8 49 4c ed ff       	call   0x4364c0
  561877:	39 30                	cmp    DWORD PTR [eax],esi
  561879:	74 5c                	je     0x5618d7
  56187b:	6a 0f                	push   0xf
  56187d:	e8 2e 3d 02 00       	call   0x5855b0
  561882:	8b f0                	mov    esi,eax
  561884:	e8 a7 3a 02 00       	call   0x585330
  561889:	50                   	push   eax
  56188a:	8d 4c 24 40          	lea    ecx,[esp+0x40]
  56188e:	e8 bd 09 ea ff       	call   0x402250
  561893:	8d 44 24 3c          	lea    eax,[esp+0x3c]
  561897:	50                   	push   eax
  561898:	c7 44 24 6c 01 00 00 	mov    DWORD PTR [esp+0x6c],0x1
  56189f:	00 
  5618a0:	e8 1b e0 ea ff       	call   0x40f8c0
  5618a5:	8b f8                	mov    edi,eax
  5618a7:	e8 84 52 f7 ff       	call   0x4d6b30
  5618ac:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
  5618b0:	c7 44 24 68 ff ff ff 	mov    DWORD PTR [esp+0x68],0xffffffff
  5618b7:	ff 
  5618b8:	e8 83 8b f9 ff       	call   0x4fa440
  5618bd:	e8 be 2d eb ff       	call   0x414680
  5618c2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  5618c5:	51                   	push   ecx
  5618c6:	6a 00                	push   0x0
  5618c8:	e8 d3 20 f4 ff       	call   0x4a39a0
  5618cd:	e8 de 07 00 00       	call   0x5620b0
  5618d2:	e9 af 04 00 00       	jmp    0x561d86
  5618d7:	be 01 00 00 00       	mov    esi,0x1
```

### N07. Controller 0x561760 actual key fields: input+8=>+38, input+0C=>+3C, state+28

- VA `0x5618DC..0x56191F` [end exclusive]; raw `0x160CDC..0x160D1F`; **67 bytes**; SHA256 `c98ea552f67d341b52b7bd4ca9b87467d04e71ae5bd492e1fbecdf6b197f80d2`.

```asm
005618dc <.data+0x160cdc>:
  5618dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38             	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28             	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                	jne    0x561918
  5618f4:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  5618fa:	c7 44 24 68 02 00 00 	mov    DWORD PTR [esp+0x68],0x2
  561901:	00 
  561902:	e8 79 5b 02 00       	call   0x587480
  561907:	68 c0 cc bc 00       	push   0xbcccc0
  56190c:	e8 09 0a 33 00       	call   0x89231a
  561911:	83 c4 04             	add    esp,0x4
  561914:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561918:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
```

### N08. Second writer 0x565720: early busy branch or +38/+3C and flag+89

- VA `0x565720..0x56579C` [end exclusive]; raw `0x164B20..0x164B9C`; **124 bytes**; SHA256 `38f256a811f311bb17744f6e924c11318a9154b001b1af2e51b9c2dc1d42314c`.

```asm
00565720 <.data+0x164b20>:
  565720:	55                   	push   ebp
  565721:	8b ec                	mov    ebp,esp
  565723:	83 e4 f8             	and    esp,0xfffffff8
  565726:	6a ff                	push   0xffffffff
  565728:	68 e8 fb 93 00       	push   0x93fbe8
  56572d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  565733:	50                   	push   eax
  565734:	83 ec 34             	sub    esp,0x34
  565737:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56573c:	33 c4                	xor    eax,esp
  56573e:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  565742:	53                   	push   ebx
  565743:	57                   	push   edi
  565744:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  565749:	33 c4                	xor    eax,esp
  56574b:	50                   	push   eax
  56574c:	8d 44 24 40          	lea    eax,[esp+0x40]
  565750:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  565756:	83 7e 28 00          	cmp    DWORD PTR [esi+0x28],0x0
  56575a:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56575d:	c6 86 89 00 00 00 01 	mov    BYTE PTR [esi+0x89],0x1
  565764:	74 17                	je     0x56577d
  565766:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  565769:	50                   	push   eax
  56576a:	51                   	push   ecx
  56576b:	68 ac 06 c1 00       	push   0xc106ac
  565770:	e8 eb 83 18 00       	call   0x6edb60
  565775:	83 c4 0c             	add    esp,0xc
  565778:	e9 e8 02 00 00       	jmp    0x565a65
  56577d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  565780:	bb 01 00 00 00       	mov    ebx,0x1
  565785:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  565788:	89 46 3c             	mov    DWORD PTR [esi+0x3c],eax
  56578b:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
  56578e:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  565794:	75 29                	jne    0x5657bf
  565796:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
```

### N09. Controller NEXT uses prior keys then overwrites +3C with successor, zero gate

- VA `0x561ED1..0x561F0B` [end exclusive]; raw `0x1612D1..0x16130B`; **58 bytes**; SHA256 `9c3730eb69f44b32f778ce4a8f4aba5fe9eb59bf29778cdd9b979b5b31b383eb`.

```asm
00561ed1 <.data+0x1612d1>:
  561ed1:	8b 47 3c             	mov    eax,DWORD PTR [edi+0x3c]
  561ed4:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561ed7:	50                   	push   eax
  561ed8:	51                   	push   ecx
  561ed9:	68 68 0f fc 00       	push   0xfc0f68
  561ede:	e8 5d c7 f1 ff       	call   0x47e640
  561ee3:	33 db                	xor    ebx,ebx
  561ee5:	89 47 3c             	mov    DWORD PTR [edi+0x3c],eax
  561ee8:	3b c3                	cmp    eax,ebx
  561eea:	74 1f                	je     0x561f0b
  561eec:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561eef:	50                   	push   eax
  561ef0:	52                   	push   edx
  561ef1:	8b f7                	mov    esi,edi
  561ef3:	e8 28 38 00 00       	call   0x565720
  561ef8:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561efc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f03:	59                   	pop    ecx
  561f04:	5f                   	pop    edi
  561f05:	5e                   	pop    esi
  561f06:	5b                   	pop    ebx
  561f07:	8b e5                	mov    esp,ebp
  561f09:	5d                   	pop    ebp
  561f0a:	c3                   	ret
```

### N10. Controller NEXT terminator resets both keys

- VA `0x561F39..0x561F60` [end exclusive]; raw `0x161339..0x161360`; **39 bytes**; SHA256 `3fa8d92ff450419c178df0cd2713901aed3ce981fa241ac970a7ea69ca5714eb`.

```asm
00561f39 <.data+0x161339>:
  561f39:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  561f3c:	50                   	push   eax
  561f3d:	b9 c8 0f fc 00       	mov    ecx,0xfc0fc8
  561f42:	e8 e9 74 17 00       	call   0x6d9430
  561f47:	89 5f 38             	mov    DWORD PTR [edi+0x38],ebx
  561f4a:	89 5f 3c             	mov    DWORD PTR [edi+0x3c],ebx
  561f4d:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561f51:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f58:	59                   	pop    ecx
  561f59:	5f                   	pop    edi
  561f5a:	5e                   	pop    esi
  561f5b:	5b                   	pop    ebx
  561f5c:	8b e5                	mov    esp,ebp
  561f5e:	5d                   	pop    ebp
  561f5f:	c3                   	ret
```

### N11. Controller inactive branch follows different +38/+3C and 0x3F path

- VA `0x561F60..0x561FF1` [end exclusive]; raw `0x161360..0x1613F1`; **145 bytes**; SHA256 `a092e3d406740e3acaf021c9f20768648879e0426dfc56a43ca27dc18496e9fb`.

```asm
00561f60 <.data+0x161360>:
  561f60:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561f63:	0f 84 28 01 00 00    	je     0x562091
  561f69:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561f6c:	e8 df 22 ed ff       	call   0x434250
  561f71:	bb 01 00 00 00       	mov    ebx,0x1
  561f76:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  561f79:	39 77 38             	cmp    DWORD PTR [edi+0x38],esi
  561f7c:	74 39                	je     0x561fb7
  561f7e:	68 44 03 c1 00       	push   0xc10344
  561f83:	53                   	push   ebx
  561f84:	e8 a7 92 f3 ff       	call   0x49b230
  561f89:	50                   	push   eax
  561f8a:	e8 11 b1 f4 ff       	call   0x4ad0a0
  561f8f:	6a ff                	push   0xffffffff
  561f91:	51                   	push   ecx
  561f92:	e8 99 92 f3 ff       	call   0x49b230
  561f97:	83 c4 04             	add    esp,0x4
  561f9a:	e8 b1 0b f4 ff       	call   0x4a2b50
  561f9f:	3b c3                	cmp    eax,ebx
  561fa1:	75 4e                	jne    0x561ff1
  561fa3:	e8 d8 26 eb ff       	call   0x414680
  561fa8:	8b 4f 3c             	mov    ecx,DWORD PTR [edi+0x3c]
  561fab:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561fae:	51                   	push   ecx
  561faf:	52                   	push   edx
  561fb0:	e8 eb 19 f4 ff       	call   0x4a39a0
  561fb5:	eb 3a                	jmp    0x561ff1
  561fb7:	8d 5f 3c             	lea    ebx,[edi+0x3c]
  561fba:	8d 77 74             	lea    esi,[edi+0x74]
  561fbd:	53                   	push   ebx
  561fbe:	e8 7d be 15 00       	call   0x6bde40
  561fc3:	50                   	push   eax
  561fc4:	56                   	push   esi
  561fc5:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  561fc9:	e8 c2 48 ed ff       	call   0x436890
  561fce:	57                   	push   edi
  561fcf:	e8 cc 03 00 00       	call   0x5623a0
  561fd4:	e8 a7 26 eb ff       	call   0x414680
  561fd9:	8b 03                	mov    eax,DWORD PTR [ebx]
  561fdb:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561fde:	50                   	push   eax
  561fdf:	51                   	push   ecx
  561fe0:	e8 bb 19 f4 ff       	call   0x4a39a0
  561fe5:	e8 c6 00 00 00       	call   0x5620b0
  561fea:	bb 01 00 00 00       	mov    ebx,0x1
  561fef:	33 f6                	xor    esi,esi
```

### N12. Controller inactive cleanup resets keys and returns

- VA `0x562080..0x5620AA` [end exclusive]; raw `0x161480..0x1614AA`; **42 bytes**; SHA256 `d5e9525c291da39d891b2230f3dd4c7ca3790e459bfb2b5af2469b1218a91dff`.

```asm
00562080 <.data+0x161480>:
  562080:	8a 9f 88 00 00 00    	mov    bl,BYTE PTR [edi+0x88]
  562086:	e8 15 2b ea ff       	call   0x404ba0
  56208b:	88 98 c4 68 00 00    	mov    BYTE PTR [eax+0x68c4],bl
  562091:	89 77 38             	mov    DWORD PTR [edi+0x38],esi
  562094:	89 77 3c             	mov    DWORD PTR [edi+0x3c],esi
  562097:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  56209b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5620a2:	59                   	pop    ecx
  5620a3:	5f                   	pop    edi
  5620a4:	5e                   	pop    esi
  5620a5:	5b                   	pop    ebx
  5620a6:	8b e5                	mov    esp,ebp
  5620a8:	5d                   	pop    ebp
  5620a9:	c3                   	ret
```

### N13. Client UI/business wrapper: arbitrary caller pair -> 0x561760

- VA `0x4A9730..0x4A97A8` [end exclusive]; raw `0xA8B30..0xA8BA8`; **120 bytes**; SHA256 `865a82dd68c7b5dbe62784bd7999f9cb9117086533becf0105145ba6e86e9b62`.

```asm
004a9730 <.data+0xa8b30>:
  4a9730:	55                   	push   ebp
  4a9731:	8b ec                	mov    ebp,esp
  4a9733:	6a ff                	push   0xffffffff
  4a9735:	68 ae b2 93 00       	push   0x93b2ae
  4a973a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a9740:	50                   	push   eax
  4a9741:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a9746:	33 c5                	xor    eax,ebp
  4a9748:	50                   	push   eax
  4a9749:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a974c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a9752:	b8 01 00 00 00       	mov    eax,0x1
  4a9757:	84 05 b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,al
  4a975d:	75 26                	jne    0x4a9785
  4a975f:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  4a9765:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a976c:	e8 ff 69 0b 00       	call   0x560170
  4a9771:	68 10 d1 bc 00       	push   0xbcd110
  4a9776:	e8 9f 8b 3e 00       	call   0x89231a
  4a977b:	83 c4 04             	add    esp,0x4
  4a977e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a9785:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4a9788:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4a978b:	50                   	push   eax
  4a978c:	51                   	push   ecx
  4a978d:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  4a9792:	e8 c9 7f 0b 00       	call   0x561760
  4a9797:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a979a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a97a1:	59                   	pop    ecx
  4a97a2:	8b e5                	mov    esp,ebp
  4a97a4:	5d                   	pop    ebp
  4a97a5:	c2 08 00             	ret    0x8
```

### N14. S2C 0x40 conditional subtype2 producer obtains pair from 0x422F40

- VA `0x5023E2..0x50244C` [end exclusive]; raw `0x1017E2..0x10184C`; **106 bytes**; SHA256 `3f829375a3e6193082be0b6aedd469934caef370bbf36d53f18eda17662434bf`.

```asm
005023e2 <.data+0x1017e2>:
  5023e2:	8b 43 3c             	mov    eax,DWORD PTR [ebx+0x3c]
  5023e5:	83 e8 02             	sub    eax,0x2
  5023e8:	74 51                	je     0x50243b
  5023ea:	48                   	dec    eax
  5023eb:	75 5f                	jne    0x50244c
  5023ed:	e8 ce 30 f0 ff       	call   0x4054c0
  5023f2:	6a 18                	push   0x18
  5023f4:	e8 6f ee 38 00       	call   0x891268
  5023f9:	83 c4 04             	add    esp,0x4
  5023fc:	85 c0                	test   eax,eax
  5023fe:	74 2e                	je     0x50242e
  502400:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  502403:	83 ca ff             	or     edx,0xffffffff
  502406:	50                   	push   eax
  502407:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  50240a:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  50240d:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  502414:	c7 40 10 06 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf4306
  50241b:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  502421:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502424:	e8 27 86 08 00       	call   0x58aa50
  502429:	e9 7b 03 00 00       	jmp    0x5027a9
  50242e:	33 c0                	xor    eax,eax
  502430:	50                   	push   eax
  502431:	e8 1a 86 08 00       	call   0x58aa50
  502436:	e9 6e 03 00 00       	jmp    0x5027a9
  50243b:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  50243e:	51                   	push   ecx
  50243f:	57                   	push   edi
  502440:	e8 fb 0a f2 ff       	call   0x422f40
  502445:	8b c8                	mov    ecx,eax
  502447:	e8 14 f3 05 00       	call   0x561760
```

### N15. S2C 0x45 conditional subtype2 producer obtains pair from 0x422F40

- VA `0x502834..0x50289A` [end exclusive]; raw `0x101C34..0x101C9A`; **102 bytes**; SHA256 `146839c599b8363732dd655cc96d36a4787a45f23c6383da7454ef5aa66d3efa`.

```asm
00502834 <.data+0x101c34>:
  502834:	8b 43 44             	mov    eax,DWORD PTR [ebx+0x44]
  502837:	83 e8 02             	sub    eax,0x2
  50283a:	74 4d                	je     0x502889
  50283c:	48                   	dec    eax
  50283d:	75 5b                	jne    0x50289a
  50283f:	e8 7c 2c f0 ff       	call   0x4054c0
  502844:	6a 18                	push   0x18
  502846:	e8 1d ea 38 00       	call   0x891268
  50284b:	83 c4 04             	add    esp,0x4
  50284e:	3b c6                	cmp    eax,esi
  502850:	74 2a                	je     0x50287c
  502852:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  502855:	83 ca ff             	or     edx,0xffffffff
  502858:	50                   	push   eax
  502859:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  50285c:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  50285f:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  502862:	c7 40 10 06 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf4306
  502869:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50286f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502872:	e8 d9 81 08 00       	call   0x58aa50
  502877:	e9 a1 02 00 00       	jmp    0x502b1d
  50287c:	33 c0                	xor    eax,eax
  50287e:	50                   	push   eax
  50287f:	e8 cc 81 08 00       	call   0x58aa50
  502884:	e9 94 02 00 00       	jmp    0x502b1d
  502889:	8b 53 48             	mov    edx,DWORD PTR [ebx+0x48]
  50288c:	52                   	push   edx
  50288d:	57                   	push   edi
  50288e:	e8 ad 06 f2 ff       	call   0x422f40
  502893:	8b c8                	mov    ecx,eax
  502895:	e8 c6 ee 05 00       	call   0x561760
```

### N16. Table/SceneList initialization + chapter table loader (distinct from Event)

- VA `0x47DD08..0x47DD6C` [end exclusive]; raw `0x7D108..0x7D16C`; **100 bytes**; SHA256 `9a6666b1b68dbbd1a3588a121010d5e1e55215036b6ec44d5d17e3d53a48b2b9`.

```asm
0047dd08 <.data+0x7d108>:
  47dd08:	bf 68 0f fc 00       	mov    edi,0xfc0f68
  47dd0d:	33 db                	xor    ebx,ebx
  47dd0f:	6a 18                	push   0x18
  47dd11:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  47dd14:	89 1d 70 0f fc 00    	mov    DWORD PTR ds:0xfc0f70,ebx
  47dd1a:	e8 49 35 41 00       	call   0x891268
  47dd1f:	83 c4 04             	add    esp,0x4
  47dd22:	3b c3                	cmp    eax,ebx
  47dd24:	0f 84 ec 00 00 00    	je     0x47de16
  47dd2a:	a3 6c 0f fc 00       	mov    ds:0xfc0f6c,eax
  47dd2f:	89 00                	mov    DWORD PTR [eax],eax
  47dd31:	a1 6c 0f fc 00       	mov    eax,ds:0xfc0f6c
  47dd36:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  47dd39:	a1 6c 0f fc 00       	mov    eax,ds:0xfc0f6c
  47dd3e:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  47dd41:	a1 6c 0f fc 00       	mov    eax,ds:0xfc0f6c
  47dd46:	c6 40 14 01          	mov    BYTE PTR [eax+0x14],0x1
  47dd4a:	8b 0d 6c 0f fc 00    	mov    ecx,DWORD PTR ds:0xfc0f6c
  47dd50:	c6 41 15 01          	mov    BYTE PTR [ecx+0x15],0x1
  47dd54:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47dd57:	89 1d 78 0f fc 00    	mov    DWORD PTR ds:0xfc0f78,ebx
  47dd5d:	c7 05 7c 0f fc 00 61 	mov    DWORD PTR ds:0xfc0f7c,0xea61
  47dd64:	ea 00 00 
  47dd67:	e8 d4 00 00 00       	call   0x47de40
```

### N17. Chapter Table child parsed value fields to chapterRecord +0/+4 (showing separate town)

- VA `0x47DFA0..0x47E046` [end exclusive]; raw `0x7D3A0..0x7D446`; **166 bytes**; SHA256 `73a0fed3a3ea35494982109fc84897856842bb8e8dd2189153890bd02310e234`.

```asm
0047dfa0 <.data+0x7d3a0>:
  47dfa0:	6a 44                	push   0x44
  47dfa2:	e8 c1 32 41 00       	call   0x891268
  47dfa7:	83 c4 04             	add    esp,0x4
  47dfaa:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47dfae:	c6 84 24 08 01 00 00 	mov    BYTE PTR [esp+0x108],0x1
  47dfb5:	01 
  47dfb6:	85 c0                	test   eax,eax
  47dfb8:	74 0e                	je     0x47dfc8
  47dfba:	50                   	push   eax
  47dfbb:	e8 c0 05 00 00       	call   0x47e580
  47dfc0:	8b d8                	mov    ebx,eax
  47dfc2:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47dfc6:	eb 06                	jmp    0x47dfce
  47dfc8:	33 db                	xor    ebx,ebx
  47dfca:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  47dfce:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  47dfd2:	83 c7 44             	add    edi,0x44
  47dfd5:	68 58 33 c0 00       	push   0xc03358
  47dfda:	c6 84 24 0c 01 00 00 	mov    BYTE PTR [esp+0x10c],0x0
  47dfe1:	00 
  47dfe2:	e8 b9 20 2b 00       	call   0x7300a0
  47dfe7:	85 c0                	test   eax,eax
  47dfe9:	74 1a                	je     0x47e005
  47dfeb:	83 c0 30             	add    eax,0x30
  47dfee:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  47dff2:	72 02                	jb     0x47dff6
  47dff4:	8b 00                	mov    eax,DWORD PTR [eax]
  47dff6:	85 c0                	test   eax,eax
  47dff8:	74 0b                	je     0x47e005
  47dffa:	50                   	push   eax
  47dffb:	e8 b4 37 41 00       	call   0x8917b4
  47e000:	83 c4 04             	add    esp,0x4
  47e003:	eb 02                	jmp    0x47e007
  47e005:	33 c0                	xor    eax,eax
  47e007:	68 64 33 c0 00       	push   0xc03364
  47e00c:	89 03                	mov    DWORD PTR [ebx],eax
  47e00e:	e8 8d 20 2b 00       	call   0x7300a0
  47e013:	85 c0                	test   eax,eax
  47e015:	74 1a                	je     0x47e031
  47e017:	83 c0 30             	add    eax,0x30
  47e01a:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  47e01e:	72 02                	jb     0x47e022
  47e020:	8b 00                	mov    eax,DWORD PTR [eax]
  47e022:	85 c0                	test   eax,eax
  47e024:	74 0b                	je     0x47e031
  47e026:	50                   	push   eax
  47e027:	e8 88 37 41 00       	call   0x8917b4
  47e02c:	83 c4 04             	add    esp,0x4
  47e02f:	eb 02                	jmp    0x47e033
  47e031:	33 c0                	xor    eax,eax
  47e033:	6a 0b                	push   0xb
  47e035:	bf 0f 00 00 00       	mov    edi,0xf
  47e03a:	68 6c 33 c0 00       	push   0xc0336c
  47e03f:	8d 4c 24 68          	lea    ecx,[esp+0x68]
  47e043:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
```

### N18. Chapter object iterator source is an actual container node payload

- VA `0x47D2D8..0x47D372` [end exclusive]; raw `0x7C6D8..0x7C772`; **154 bytes**; SHA256 `7844f6246366256c581ee80b6b2b6f1909b910eb1d50614649b610a1345d9943`.

```asm
0047d2d8 <.data+0x7c6d8>:
  47d2d8:	8b 83 10 01 00 00    	mov    eax,DWORD PTR [ebx+0x110]
  47d2de:	8b 30                	mov    esi,DWORD PTR [eax]
  47d2e0:	33 d2                	xor    edx,edx
  47d2e2:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  47d2e5:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  47d2e8:	3b f0                	cmp    esi,eax
  47d2ea:	0f 84 30 01 00 00    	je     0x47d420
  47d2f0:	eb 11                	jmp    0x47d303
  47d2f2:	eb 0c                	jmp    0x47d300
  47d2f4:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  47d2fb:	eb 03                	jmp    0x47d300
  47d2fd:	8d 49 00             	lea    ecx,[ecx+0x0]
  47d300:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  47d303:	8b 83 f8 00 00 00    	mov    eax,DWORD PTR [ebx+0xf8]
  47d309:	8b 88 cc 00 00 00    	mov    ecx,DWORD PTR [eax+0xcc]
  47d30f:	85 c9                	test   ecx,ecx
  47d311:	74 49                	je     0x47d35c
  47d313:	8b 81 ac 00 00 00    	mov    eax,DWORD PTR [ecx+0xac]
  47d319:	2b 81 a8 00 00 00    	sub    eax,DWORD PTR [ecx+0xa8]
  47d31f:	c1 f8 02             	sar    eax,0x2
  47d322:	83 fa ff             	cmp    edx,0xffffffff
  47d325:	7e 35                	jle    0x47d35c
  47d327:	3b d0                	cmp    edx,eax
  47d329:	7d 31                	jge    0x47d35c
  47d32b:	8b 81 a8 00 00 00    	mov    eax,DWORD PTR [ecx+0xa8]
  47d331:	8b 3c 90             	mov    edi,DWORD PTR [eax+edx*4]
  47d334:	85 ff                	test   edi,edi
  47d336:	74 24                	je     0x47d35c
  47d338:	8b 17                	mov    edx,DWORD PTR [edi]
  47d33a:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  47d33d:	8b cf                	mov    ecx,edi
  47d33f:	ff d0                	call   eax
  47d341:	3d 2d 01 00 00       	cmp    eax,0x12d
  47d346:	74 16                	je     0x47d35e
  47d348:	6a 00                	push   0x0
  47d34a:	68 c0 1f bf 00       	push   0xbf1fc0
  47d34f:	68 18 21 bf 00       	push   0xbf2118
  47d354:	6a 00                	push   0x0
  47d356:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  47d35c:	33 ff                	xor    edi,edi
  47d35e:	ff 45 f0             	inc    DWORD PTR [ebp-0x10]
  47d361:	3b b3 10 01 00 00    	cmp    esi,DWORD PTR [ebx+0x110]
  47d367:	74 69                	je     0x47d3d2
  47d369:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  47d36c:	57                   	push   edi
  47d36d:	e8 3e df ff ff       	call   0x47b2b0
```

### N19. Chapter object key writer explicitly copies row+0 into object+0x248

- VA `0x47B2D8..0x47B315` [end exclusive]; raw `0x7A6D8..0x7A715`; **61 bytes**; SHA256 `4cedcb1c466e44fd177f56271871a174d24f8c223fc64725c7a7e1464336706e`.

```asm
0047b2d8 <.data+0x7a6d8>:
  47b2d8:	8b f9                	mov    edi,ecx
  47b2da:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  47b2dd:	8b 07                	mov    eax,DWORD PTR [edi]
  47b2df:	6a ff                	push   0xffffffff
  47b2e1:	6a 00                	push   0x0
  47b2e3:	8d 4f 08             	lea    ecx,[edi+0x8]
  47b2e6:	8d b3 4c 02 00 00    	lea    esi,[ebx+0x24c]
  47b2ec:	51                   	push   ecx
  47b2ed:	8b ce                	mov    ecx,esi
  47b2ef:	89 83 48 02 00 00    	mov    DWORD PTR [ebx+0x248],eax
  47b2f5:	e8 e6 73 f8 ff       	call   0x4026e0
  47b2fa:	56                   	push   esi
  47b2fb:	8d b3 e8 00 00 00    	lea    esi,[ebx+0xe8]
  47b301:	e8 fa c4 2d 00       	call   0x757800
  47b306:	83 7f 04 16          	cmp    DWORD PTR [edi+0x4],0x16
  47b30a:	b8 01 00 00 00       	mov    eax,0x1
  47b30f:	0f 8e 86 00 00 00    	jle    0x47b39b
```

### N20. Scene object interaction copies object key to event+0x120; FIRST selector from chapter table

- VA `0x47D530..0x47D5BC` [end exclusive]; raw `0x7C930..0x7C9BC`; **140 bytes**; SHA256 `1afab9bddcd1096e2b55fbbeefb5ac7b54cbb9ef3f48309378610a8186961c5e`.

```asm
0047d530 <.data+0x7c930>:
  47d530:	55                   	push   ebp
  47d531:	8b ec                	mov    ebp,esp
  47d533:	6a ff                	push   0xffffffff
  47d535:	68 7e 7e 94 00       	push   0x947e7e
  47d53a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d540:	50                   	push   eax
  47d541:	56                   	push   esi
  47d542:	57                   	push   edi
  47d543:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d548:	33 c5                	xor    eax,ebp
  47d54a:	50                   	push   eax
  47d54b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d54e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d554:	8b f1                	mov    esi,ecx
  47d556:	8b fa                	mov    edi,edx
  47d558:	8b 86 48 02 00 00    	mov    eax,DWORD PTR [esi+0x248]
  47d55e:	89 87 20 01 00 00    	mov    DWORD PTR [edi+0x120],eax
  47d564:	8b 86 4c 02 00 00    	mov    eax,DWORD PTR [esi+0x24c]
  47d56a:	89 87 1c 01 00 00    	mov    DWORD PTR [edi+0x11c],eax
  47d570:	b8 01 00 00 00       	mov    eax,0x1
  47d575:	84 05 64 0f fc 00    	test   BYTE PTR ds:0xfc0f64,al
  47d57b:	75 26                	jne    0x47d5a3
  47d57d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47d583:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d58a:	e8 51 07 00 00       	call   0x47dce0
  47d58f:	68 f0 da bc 00       	push   0xbcdaf0
  47d594:	e8 81 4d 41 00       	call   0x89231a
  47d599:	83 c4 04             	add    esp,0x4
  47d59c:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d5a3:	8b 87 20 01 00 00    	mov    eax,DWORD PTR [edi+0x120]
  47d5a9:	50                   	push   eax
  47d5aa:	68 68 0f fc 00       	push   0xfc0f68
  47d5af:	e8 dc 12 00 00       	call   0x47e890
  47d5b4:	50                   	push   eax
  47d5b5:	8b ce                	mov    ecx,esi
  47d5b7:	e8 04 e0 ff ff       	call   0x47b5c0
```

### N21. FIRST scene selector per key and vector first item

- VA `0x47E890..0x47E995` [end exclusive]; raw `0x7DC90..0x7DD95`; **261 bytes**; SHA256 `86aaa0d13e90d97e83646404fb05bc5ea9e658eac14eb63791e61168e92d8f54`.

```asm
0047e890 <.data+0x7dc90>:
  47e890:	55                   	push   ebp
  47e891:	8b ec                	mov    ebp,esp
  47e893:	6a ff                	push   0xffffffff
  47e895:	68 b8 8a 90 00       	push   0x908ab8
  47e89a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e8a0:	50                   	push   eax
  47e8a1:	83 ec 14             	sub    esp,0x14
  47e8a4:	53                   	push   ebx
  47e8a5:	56                   	push   esi
  47e8a6:	57                   	push   edi
  47e8a7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e8ac:	33 c5                	xor    eax,ebp
  47e8ae:	50                   	push   eax
  47e8af:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e8b2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e8b8:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e8bb:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  47e8be:	8b 33                	mov    esi,DWORD PTR [ebx]
  47e8c0:	3b f3                	cmp    esi,ebx
  47e8c2:	74 67                	je     0x47e92b
  47e8c4:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  47e8c7:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  47e8ca:	51                   	push   ecx
  47e8cb:	8d 4f 34             	lea    ecx,[edi+0x34]
  47e8ce:	8d 45 08             	lea    eax,[ebp+0x8]
  47e8d1:	e8 fa e5 0a 00       	call   0x52ced0
  47e8d6:	8b 7f 38             	mov    edi,DWORD PTR [edi+0x38]
  47e8d9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e8dc:	3b c7                	cmp    eax,edi
  47e8de:	75 61                	jne    0x47e941
  47e8e0:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  47e8e4:	75 41                	jne    0x47e927
  47e8e6:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  47e8e9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e8ed:	75 1d                	jne    0x47e90c
  47e8ef:	8b f0                	mov    esi,eax
  47e8f1:	8b 06                	mov    eax,DWORD PTR [esi]
  47e8f3:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e8f7:	75 2e                	jne    0x47e927
  47e8f9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  47e900:	8b f0                	mov    esi,eax
  47e902:	8b 06                	mov    eax,DWORD PTR [esi]
  47e904:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e908:	74 f6                	je     0x47e900
  47e90a:	eb 1b                	jmp    0x47e927
  47e90c:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  47e90f:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e913:	75 10                	jne    0x47e925
  47e915:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  47e918:	75 0b                	jne    0x47e925
  47e91a:	8b f0                	mov    esi,eax
  47e91c:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  47e91f:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e923:	74 f0                	je     0x47e915
  47e925:	8b f0                	mov    esi,eax
  47e927:	3b f3                	cmp    esi,ebx
  47e929:	75 99                	jne    0x47e8c4
  47e92b:	33 c0                	xor    eax,eax
  47e92d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e930:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e937:	59                   	pop    ecx
  47e938:	5f                   	pop    edi
  47e939:	5e                   	pop    esi
  47e93a:	5b                   	pop    ebx
  47e93b:	8b e5                	mov    esp,ebp
  47e93d:	5d                   	pop    ebp
  47e93e:	c2 08 00             	ret    0x8
  47e941:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  47e944:	83 c0 14             	add    eax,0x14
  47e947:	50                   	push   eax
  47e948:	8d 45 e4             	lea    eax,[ebp-0x1c]
  47e94b:	50                   	push   eax
  47e94c:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  47e94f:	e8 3c a1 36 00       	call   0x7e8a90
  47e954:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e95b:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  47e95e:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  47e961:	2b c8                	sub    ecx,eax
  47e963:	c1 f9 02             	sar    ecx,0x2
  47e966:	85 c9                	test   ecx,ecx
  47e968:	75 0a                	jne    0x47e974
  47e96a:	68 08 34 bf 00       	push   0xbf3408
  47e96f:	e8 09 f2 3f 00       	call   0x87db7d
  47e974:	8b 30                	mov    esi,DWORD PTR [eax]
  47e976:	50                   	push   eax
  47e977:	e8 90 28 41 00       	call   0x89120c
  47e97c:	83 c4 04             	add    esp,0x4
  47e97f:	8b c6                	mov    eax,esi
  47e981:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e984:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e98b:	59                   	pop    ecx
  47e98c:	5f                   	pop    edi
  47e98d:	5e                   	pop    esi
  47e98e:	5b                   	pop    ebx
  47e98f:	8b e5                	mov    esp,ebp
  47e991:	5d                   	pop    ebp
  47e992:	c2 08 00             	ret    0x8
```

### N22. NEXT scene selector compares previous value with ordered list rather than increment

- VA `0x47E640..0x47E746` [end exclusive]; raw `0x7DA40..0x7DB46`; **262 bytes**; SHA256 `965b183296c4cee83f20fee39ecdbabdb492535378acb098d956830a4c065ab7`.

```asm
0047e640 <.data+0x7da40>:
  47e640:	55                   	push   ebp
  47e641:	8b ec                	mov    ebp,esp
  47e643:	6a ff                	push   0xffffffff
  47e645:	68 b8 8a 90 00       	push   0x908ab8
  47e64a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e650:	50                   	push   eax
  47e651:	83 ec 14             	sub    esp,0x14
  47e654:	53                   	push   ebx
  47e655:	56                   	push   esi
  47e656:	57                   	push   edi
  47e657:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e65c:	33 c5                	xor    eax,ebp
  47e65e:	50                   	push   eax
  47e65f:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e662:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e668:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  47e66b:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  47e66f:	0f 84 86 00 00 00    	je     0x47e6fb
  47e675:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e678:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  47e67b:	8b 07                	mov    eax,DWORD PTR [edi]
  47e67d:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  47e680:	3b c7                	cmp    eax,edi
  47e682:	74 77                	je     0x47e6fb
  47e684:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  47e687:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  47e68a:	51                   	push   ecx
  47e68b:	8d 4e 34             	lea    ecx,[esi+0x34]
  47e68e:	8d 45 08             	lea    eax,[ebp+0x8]
  47e691:	e8 3a e8 0a 00       	call   0x52ced0
  47e696:	8b 76 38             	mov    esi,DWORD PTR [esi+0x38]
  47e699:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e69c:	3b c6                	cmp    eax,esi
  47e69e:	75 11                	jne    0x47e6b1
  47e6a0:	8d 45 10             	lea    eax,[ebp+0x10]
  47e6a3:	e8 f8 ff 01 00       	call   0x49e6a0
  47e6a8:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  47e6ab:	3b c7                	cmp    eax,edi
  47e6ad:	75 d5                	jne    0x47e684
  47e6af:	eb 4a                	jmp    0x47e6fb
  47e6b1:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  47e6b4:	83 c0 14             	add    eax,0x14
  47e6b7:	50                   	push   eax
  47e6b8:	8d 45 e4             	lea    eax,[ebp-0x1c]
  47e6bb:	50                   	push   eax
  47e6bc:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  47e6bf:	e8 cc a3 36 00       	call   0x7e8a90
  47e6c4:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e6cb:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  47e6ce:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  47e6d1:	2b ca                	sub    ecx,edx
  47e6d3:	c1 f9 02             	sar    ecx,0x2
  47e6d6:	8d 71 ff             	lea    esi,[ecx-0x1]
  47e6d9:	33 c0                	xor    eax,eax
  47e6db:	85 f6                	test   esi,esi
  47e6dd:	74 0f                	je     0x47e6ee
  47e6df:	90                   	nop
  47e6e0:	3b c8                	cmp    ecx,eax
  47e6e2:	76 32                	jbe    0x47e716
  47e6e4:	3b 1c 82             	cmp    ebx,DWORD PTR [edx+eax*4]
  47e6e7:	74 28                	je     0x47e711
  47e6e9:	40                   	inc    eax
  47e6ea:	3b c6                	cmp    eax,esi
  47e6ec:	72 f2                	jb     0x47e6e0
  47e6ee:	85 d2                	test   edx,edx
  47e6f0:	74 09                	je     0x47e6fb
  47e6f2:	52                   	push   edx
  47e6f3:	e8 14 2b 41 00       	call   0x89120c
  47e6f8:	83 c4 04             	add    esp,0x4
  47e6fb:	33 c0                	xor    eax,eax
  47e6fd:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e700:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e707:	59                   	pop    ecx
  47e708:	5f                   	pop    edi
  47e709:	5e                   	pop    esi
  47e70a:	5b                   	pop    ebx
  47e70b:	8b e5                	mov    esp,ebp
  47e70d:	5d                   	pop    ebp
  47e70e:	c2 0c 00             	ret    0xc
  47e711:	40                   	inc    eax
  47e712:	3b c8                	cmp    ecx,eax
  47e714:	77 0a                	ja     0x47e720
  47e716:	68 08 34 bf 00       	push   0xbf3408
  47e71b:	e8 5d f4 3f 00       	call   0x87db7d
  47e720:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  47e723:	85 d2                	test   edx,edx
  47e725:	74 09                	je     0x47e730
  47e727:	52                   	push   edx
  47e728:	e8 df 2a 41 00       	call   0x89120c
  47e72d:	83 c4 04             	add    esp,0x4
  47e730:	8b c6                	mov    eax,esi
  47e732:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e735:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e73c:	59                   	pop    ecx
  47e73d:	5f                   	pop    edi
  47e73e:	5e                   	pop    esi
  47e73f:	5b                   	pop    ebx
  47e740:	8b e5                	mov    esp,ebp
  47e742:	5d                   	pop    ebp
  47e743:	c2 0c 00             	ret    0xc
```

### N23. Object scene dispatcher special key 0xEA61 versus Event SceneList

- VA `0x47B5C0..0x47B64F` [end exclusive]; raw `0x7A9C0..0x7AA4F`; **143 bytes**; SHA256 `53dd8506239db93db828016e09cadb63b173d026ffd5cd4d32e833282810fa46`.

```asm
0047b5c0 <.data+0x7a9c0>:
  47b5c0:	55                   	push   ebp
  47b5c1:	8b ec                	mov    ebp,esp
  47b5c3:	83 e4 f8             	and    esp,0xfffffff8
  47b5c6:	6a ff                	push   0xffffffff
  47b5c8:	68 7c 10 94 00       	push   0x94107c
  47b5cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b5d3:	50                   	push   eax
  47b5d4:	51                   	push   ecx
  47b5d5:	56                   	push   esi
  47b5d6:	57                   	push   edi
  47b5d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b5dc:	33 c4                	xor    eax,esp
  47b5de:	50                   	push   eax
  47b5df:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b5e3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b5e9:	8b f9                	mov    edi,ecx
  47b5eb:	81 bf 48 02 00 00 61 	cmp    DWORD PTR [edi+0x248],0xea61
  47b5f2:	ea 00 00 
  47b5f5:	75 11                	jne    0x47b608
  47b5f7:	80 bf 6c 02 00 00 00 	cmp    BYTE PTR [edi+0x26c],0x0
  47b5fe:	75 4f                	jne    0x47b64f
  47b600:	57                   	push   edi
  47b601:	e8 4a 02 00 00       	call   0x47b850
  47b606:	eb 47                	jmp    0x47b64f
  47b608:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  47b60f:	75 29                	jne    0x47b63a
  47b611:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  47b618:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47b61f:	00 
  47b620:	e8 4b 4b 0e 00       	call   0x560170
  47b625:	68 10 d1 bc 00       	push   0xbcd110
  47b62a:	e8 eb 6c 41 00       	call   0x89231a
  47b62f:	83 c4 04             	add    esp,0x4
  47b632:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b639:	ff 
  47b63a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47b63d:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b643:	50                   	push   eax
  47b644:	51                   	push   ecx
  47b645:	be c0 73 fb 00       	mov    esi,0xfb73c0
  47b64a:	e8 d1 a0 0e 00       	call   0x565720
```

### N24. Other scene object writer source: separate object context +0x248 from entry+0

- VA `0x47CC7E..0x47CCBE` [end exclusive]; raw `0x7C07E..0x7C0BE`; **64 bytes**; SHA256 `e13e77d5484510971ebf7acd6fbb167a9f8e15e184f7929307d0660df3ecff30`.

```asm
0047cc7e <.data+0x7c07e>:
  47cc7e:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  47cc82:	8b 04 99             	mov    eax,DWORD PTR [ecx+ebx*4]
  47cc85:	6a ff                	push   0xffffffff
  47cc87:	c6 87 6c 02 00 00 00 	mov    BYTE PTR [edi+0x26c],0x0
  47cc8e:	8b 10                	mov    edx,DWORD PTR [eax]
  47cc90:	6a 00                	push   0x0
  47cc92:	83 c0 4c             	add    eax,0x4c
  47cc95:	8d b7 50 02 00 00    	lea    esi,[edi+0x250]
  47cc9b:	50                   	push   eax
  47cc9c:	8b ce                	mov    ecx,esi
  47cc9e:	89 97 48 02 00 00    	mov    DWORD PTR [edi+0x248],edx
  47cca4:	e8 37 5a f8 ff       	call   0x4026e0
  47cca9:	56                   	push   esi
  47ccaa:	8d b7 e8 00 00 00    	lea    esi,[edi+0xe8]
  47ccb0:	e8 4b ab 2d 00       	call   0x757800
  47ccb5:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  47ccb8:	89 87 4c 02 00 00    	mov    DWORD PTR [edi+0x24c],eax
```

### N25. Event dispatch gates UI interaction for scene object

- VA `0x47C5D0..0x47C6D8` [end exclusive]; raw `0x7B9D0..0x7BAD8`; **264 bytes**; SHA256 `791c1cc1c040b406ae825a44ae59a88ddbc4ff13ce9640cb6d2d656dde0a3b8e`.

```asm
0047c5d0 <.data+0x7b9d0>:
  47c5d0:	55                   	push   ebp
  47c5d1:	8b ec                	mov    ebp,esp
  47c5d3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  47c5d6:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  47c5d9:	2d 78 05 00 00       	sub    eax,0x578
  47c5de:	0f 84 90 00 00 00    	je     0x47c674
  47c5e4:	2d 92 01 00 00       	sub    eax,0x192
  47c5e9:	74 4e                	je     0x47c639
  47c5eb:	48                   	dec    eax
  47c5ec:	0f 85 e6 00 00 00    	jne    0x47c6d8
  47c5f2:	81 7a 08 a0 0f 00 00 	cmp    DWORD PTR [edx+0x8],0xfa0
  47c5f9:	0f 83 d9 00 00 00    	jae    0x47c6d8
  47c5ff:	8b 81 f8 00 00 00    	mov    eax,DWORD PTR [ecx+0xf8]
  47c605:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  47c60b:	85 c0                	test   eax,eax
  47c60d:	74 17                	je     0x47c626
  47c60f:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  47c615:	8b 80 48 02 00 00    	mov    eax,DWORD PTR [eax+0x248]
  47c61b:	50                   	push   eax
  47c61c:	51                   	push   ecx
  47c61d:	e8 de 04 00 00       	call   0x47cb00
  47c622:	5d                   	pop    ebp
  47c623:	c2 04 00             	ret    0x4
  47c626:	33 c0                	xor    eax,eax
  47c628:	8b 80 48 02 00 00    	mov    eax,DWORD PTR [eax+0x248]
  47c62e:	50                   	push   eax
  47c62f:	51                   	push   ecx
  47c630:	e8 cb 04 00 00       	call   0x47cb00
  47c635:	5d                   	pop    ebp
  47c636:	c2 04 00             	ret    0x4
  47c639:	81 7a 08 88 13 00 00 	cmp    DWORD PTR [edx+0x8],0x1388
  47c640:	0f 82 92 00 00 00    	jb     0x47c6d8
  47c646:	8b 81 fc 00 00 00    	mov    eax,DWORD PTR [ecx+0xfc]
  47c64c:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  47c652:	85 c0                	test   eax,eax
  47c654:	74 11                	je     0x47c667
  47c656:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  47c65c:	50                   	push   eax
  47c65d:	51                   	push   ecx
  47c65e:	e8 ad 11 00 00       	call   0x47d810
  47c663:	5d                   	pop    ebp
  47c664:	c2 04 00             	ret    0x4
  47c667:	33 c0                	xor    eax,eax
  47c669:	50                   	push   eax
  47c66a:	51                   	push   ecx
  47c66b:	e8 a0 11 00 00       	call   0x47d810
  47c670:	5d                   	pop    ebp
  47c671:	c2 04 00             	ret    0x4
  47c674:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  47c677:	8b 91 08 01 00 00    	mov    edx,DWORD PTR [ecx+0x108]
  47c67d:	39 42 20             	cmp    DWORD PTR [edx+0x20],eax
  47c680:	75 0e                	jne    0x47c690
  47c682:	8b 01                	mov    eax,DWORD PTR [ecx]
  47c684:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  47c68a:	ff d2                	call   edx
  47c68c:	5d                   	pop    ebp
  47c68d:	c2 04 00             	ret    0x4
  47c690:	8b 91 04 01 00 00    	mov    edx,DWORD PTR [ecx+0x104]
  47c696:	39 42 20             	cmp    DWORD PTR [edx+0x20],eax
  47c699:	75 29                	jne    0x47c6c4
  47c69b:	8b 81 fc 00 00 00    	mov    eax,DWORD PTR [ecx+0xfc]
  47c6a1:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  47c6a7:	85 c0                	test   eax,eax
  47c6a9:	74 08                	je     0x47c6b3
  47c6ab:	8b 80 dc 00 00 00    	mov    eax,DWORD PTR [eax+0xdc]
  47c6b1:	eb 02                	jmp    0x47c6b5
  47c6b3:	33 c0                	xor    eax,eax
  47c6b5:	85 c0                	test   eax,eax
  47c6b7:	74 1f                	je     0x47c6d8
  47c6b9:	50                   	push   eax
  47c6ba:	51                   	push   ecx
  47c6bb:	e8 50 11 00 00       	call   0x47d810
  47c6c0:	5d                   	pop    ebp
  47c6c1:	c2 04 00             	ret    0x4
  47c6c4:	8b 91 00 01 00 00    	mov    edx,DWORD PTR [ecx+0x100]
  47c6ca:	39 42 20             	cmp    DWORD PTR [edx+0x20],eax
  47c6cd:	75 09                	jne    0x47c6d8
  47c6cf:	56                   	push   esi
  47c6d0:	8b f1                	mov    esi,ecx
  47c6d2:	e8 b9 0d 00 00       	call   0x47d490
  47c6d7:	5e                   	pop    esi
```

### N26. UI scene interaction special length-one branch to 0x47d530

- VA `0x47D810..0x47D889` [end exclusive]; raw `0x7CC10..0x7CC89`; **121 bytes**; SHA256 `1c1ae81939bb33632a608944f07c15fe2ec3322e0e318f9eb1c9cc8cffaad1b9`.

```asm
0047d810 <.data+0x7cc10>:
  47d810:	55                   	push   ebp
  47d811:	8b ec                	mov    ebp,esp
  47d813:	6a ff                	push   0xffffffff
  47d815:	68 c2 91 94 00       	push   0x9491c2
  47d81a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d820:	50                   	push   eax
  47d821:	51                   	push   ecx
  47d822:	53                   	push   ebx
  47d823:	56                   	push   esi
  47d824:	57                   	push   edi
  47d825:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d82a:	33 c5                	xor    eax,ebp
  47d82c:	50                   	push   eax
  47d82d:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d830:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d836:	33 db                	xor    ebx,ebx
  47d838:	f6 05 78 13 fb 00 01 	test   BYTE PTR ds:0xfb1378,0x1
  47d83f:	8d 73 01             	lea    esi,[ebx+0x1]
  47d842:	75 23                	jne    0x47d867
  47d844:	09 35 78 13 fb 00    	or     DWORD PTR ds:0xfb1378,esi
  47d84a:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47d84d:	e8 ce c3 0b 00       	call   0x539c20
  47d852:	68 b0 cf bc 00       	push   0xbccfb0
  47d857:	e8 be 4a 41 00       	call   0x89231a
  47d85c:	83 c4 04             	add    esp,0x4
  47d85f:	83 cf ff             	or     edi,0xffffffff
  47d862:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  47d865:	eb 03                	jmp    0x47d86a
  47d867:	83 cf ff             	or     edi,0xffffffff
  47d86a:	a1 58 72 fb 00       	mov    eax,ds:0xfb7258
  47d86f:	3b c3                	cmp    eax,ebx
  47d871:	0f 84 5d 01 00 00    	je     0x47d9d4
  47d877:	8b 48 2c             	mov    ecx,DWORD PTR [eax+0x2c]
  47d87a:	2b 48 28             	sub    ecx,DWORD PTR [eax+0x28]
  47d87d:	83 e1 fc             	and    ecx,0xfffffffc
  47d880:	83 f9 04             	cmp    ecx,0x4
  47d883:	0f 84 45 01 00 00    	je     0x47d9ce
```

### N27. UI scene interaction actual 0x47d530 caller, not a universal Quest15 completion trigger

- VA `0x47D9CE..0x47D9F2` [end exclusive]; raw `0x7CDCE..0x7CDF2`; **36 bytes**; SHA256 `ba9a41be1226db96308f7ea700d13013ddd66bafae47be3935955f57de59d736`.

```asm
0047d9ce <.data+0x7cdce>:
  47d9ce:	50                   	push   eax
  47d9cf:	e8 1c c1 0b 00       	call   0x539af0
  47d9d4:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  47d9d7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  47d9da:	e8 51 fb ff ff       	call   0x47d530
  47d9df:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47d9e2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47d9e9:	59                   	pop    ecx
  47d9ea:	5f                   	pop    edi
  47d9eb:	5e                   	pop    esi
  47d9ec:	5b                   	pop    ebx
  47d9ed:	8b e5                	mov    esp,ebp
  47d9ef:	5d                   	pop    ebp
  47d9f0:	c2 08              	ret    0x8
```

### N28. Object first-scene dispatch into Event lookup and chapter side effect

- VA `0x47B64A..0x47B6AA` [end exclusive]; raw `0x7AA4A..0x7AAAA`; **96 bytes**; SHA256 `1efb72cb968017a38d328cc3208620319cfa9324bffc0811fc1be5691a5ee1a6`.

```asm
0047b64a <.data+0x7aa4a>:
  47b64a:	e8 d1 a0 0e 00       	call   0x565720
  47b64f:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  47b656:	75 29                	jne    0x47b681
  47b658:	b8 01 00 00 00       	mov    eax,0x1
  47b65d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47b663:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47b667:	e8 74 26 00 00       	call   0x47dce0
  47b66c:	68 f0 da bc 00       	push   0xbcdaf0
  47b671:	e8 a4 6c 41 00       	call   0x89231a
  47b676:	83 c4 04             	add    esp,0x4
  47b679:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b680:	ff 
  47b681:	8b 97 4c 02 00 00    	mov    edx,DWORD PTR [edi+0x24c]
  47b687:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b68d:	52                   	push   edx
  47b68e:	bf 68 0f fc 00       	mov    edi,0xfc0f68
  47b693:	e8 b8 30 00 00       	call   0x47e750
  47b698:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b69c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b6a3:	59                   	pop    ecx
  47b6a4:	5f                   	pop    edi
  47b6a5:	5e                   	pop    esi
  47b6a6:	8b e5                	mov    esp,ebp
  47b6a8:	5d                   	pop    ebp
  47b6a9:	c2               	ret    0x4
```

### N29. Ancillary chapter UI string writer, NOT Server completion persistence

- VA `0x47E750..0x47E888` [end exclusive]; raw `0x7DB50..0x7DC88`; **312 bytes**; SHA256 `6a6a9a1d7e3f49a45ba65a4e3fffe60d1c911edc0960e429a2e1e0c3f8f9ee6e`.

```asm
0047e750 <.data+0x7db50>:
  47e750:	55                   	push   ebp
  47e751:	8b ec                	mov    ebp,esp
  47e753:	6a ff                	push   0xffffffff
  47e755:	68 ec 00 92 00       	push   0x9200ec
  47e75a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e760:	50                   	push   eax
  47e761:	83 ec 3c             	sub    esp,0x3c
  47e764:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e769:	33 c5                	xor    eax,ebp
  47e76b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  47e76e:	53                   	push   ebx
  47e76f:	56                   	push   esi
  47e770:	50                   	push   eax
  47e771:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e774:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e77a:	f6 05 7c af fa 00 01 	test   BYTE PTR ds:0xfaaf7c,0x1
  47e781:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e784:	89 47 10             	mov    DWORD PTR [edi+0x10],eax
  47e787:	89 4f 14             	mov    DWORD PTR [edi+0x14],ecx
  47e78a:	75 27                	jne    0x47e7b3
  47e78c:	83 0d 7c af fa 00 01 	or     DWORD PTR ds:0xfaaf7c,0x1
  47e793:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e79a:	e8 71 ec 10 00       	call   0x58d410
  47e79f:	68 c0 cd bc 00       	push   0xbccdc0
  47e7a4:	e8 71 3b 41 00       	call   0x89231a
  47e7a9:	83 c4 04             	add    esp,0x4
  47e7ac:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47e7b3:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  47e7b6:	8d 75 d4             	lea    esi,[ebp-0x2c]
  47e7b9:	e8 c2 07 f9 ff       	call   0x40ef80
  47e7be:	bb 08 00 00 00       	mov    ebx,0x8
  47e7c3:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  47e7ca:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  47e7cd:	72 02                	jb     0x47e7d1
  47e7cf:	8b 00                	mov    eax,DWORD PTR [eax]
  47e7d1:	68 dc 32 c0 00       	push   0xc032dc
  47e7d6:	68 80 af fa 00       	push   0xfaaf80
  47e7db:	8b c8                	mov    ecx,eax
  47e7dd:	ba fc 32 c0 00       	mov    edx,0xc032fc
  47e7e2:	e8 29 04 11 00       	call   0x58ec10
  47e7e7:	83 ce ff             	or     esi,0xffffffff
  47e7ea:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  47e7ed:	39 5d e8             	cmp    DWORD PTR [ebp-0x18],ebx
  47e7f0:	72 0c                	jb     0x47e7fe
  47e7f2:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  47e7f5:	52                   	push   edx
  47e7f6:	e8 11 2a 41 00       	call   0x89120c
  47e7fb:	83 c4 04             	add    esp,0x4
  47e7fe:	f6 05 7c af fa 00 01 	test   BYTE PTR ds:0xfaaf7c,0x1
  47e805:	75 23                	jne    0x47e82a
  47e807:	83 0d 7c af fa 00 01 	or     DWORD PTR ds:0xfaaf7c,0x1
  47e80e:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  47e815:	e8 f6 eb 10 00       	call   0x58d410
  47e81a:	68 c0 cd bc 00       	push   0xbccdc0
  47e81f:	e8 f6 3a 41 00       	call   0x89231a
  47e824:	83 c4 04             	add    esp,0x4
  47e827:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  47e82a:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  47e82d:	8d 75 b8             	lea    esi,[ebp-0x48]
  47e830:	e8 4b 07 f9 ff       	call   0x40ef80
  47e835:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  47e83c:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  47e83f:	72 02                	jb     0x47e843
  47e841:	8b 00                	mov    eax,DWORD PTR [eax]
  47e843:	68 24 33 c0 00       	push   0xc03324
  47e848:	68 80 af fa 00       	push   0xfaaf80
  47e84d:	8b c8                	mov    ecx,eax
  47e84f:	ba fc 32 c0 00       	mov    edx,0xc032fc
  47e854:	e8 b7 03 11 00       	call   0x58ec10
  47e859:	39 5d cc             	cmp    DWORD PTR [ebp-0x34],ebx
  47e85c:	72 0c                	jb     0x47e86a
  47e85e:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  47e861:	50                   	push   eax
  47e862:	e8 a5 29 41 00       	call   0x89120c
  47e867:	83 c4 04             	add    esp,0x4
  47e86a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e86d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e874:	59                   	pop    ecx
  47e875:	5e                   	pop    esi
  47e876:	5b                   	pop    ebx
  47e877:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  47e87a:	33 cd                	xor    ecx,ebp
  47e87c:	e8 80 27 41 00       	call   0x891001
  47e881:	8b e5                	mov    esp,ebp
  47e883:	5d                   	pop    ebp
  47e884:	c2 04 00             	ret    0x4
  47e887:	cc                   	int3
```

### N30. Event SceneList pair lookup, missing pair => no script branch

- VA `0x5658AC..0x56592C` [end exclusive]; raw `0x164CAC..0x164D2C`; **128 bytes**; SHA256 `ed53b15a0fed7b2dcc01f985aec31d3a02ce6bcfa85b8c414b4d71d5913d8e76`.

```asm
005658ac <.data+0x164cac>:
  5658ac:	6a 00                	push   0x0
  5658ae:	68 75 23 bf 00       	push   0xbf2375
  5658b3:	8d 4e 44             	lea    ecx,[esi+0x44]
  5658b6:	c6 05 a4 42 f9 00 01 	mov    BYTE PTR ds:0xf942a4,0x1
  5658bd:	e8 ae d1 e9 ff       	call   0x402a70
  5658c2:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  5658c5:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  5658c8:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5658cc:	75 27                	jne    0x5658f5
  5658ce:	8b ff                	mov    edi,edi
  5658d0:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  5658d3:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5658d6:	3b fa                	cmp    edi,edx
  5658d8:	7f 0a                	jg     0x5658e4
  5658da:	7c 0d                	jl     0x5658e9
  5658dc:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5658df:	39 50 10             	cmp    DWORD PTR [eax+0x10],edx
  5658e2:	7d 05                	jge    0x5658e9
  5658e4:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5658e7:	eb 04                	jmp    0x5658ed
  5658e9:	8b c8                	mov    ecx,eax
  5658eb:	8b 00                	mov    eax,DWORD PTR [eax]
  5658ed:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5658f1:	74 dd                	je     0x5658d0
  5658f3:	eb 03                	jmp    0x5658f8
  5658f5:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5658f8:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  5658fb:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  5658ff:	3b ca                	cmp    ecx,edx
  565901:	74 17                	je     0x56591a
  565903:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  565906:	3b c7                	cmp    eax,edi
  565908:	7f 10                	jg     0x56591a
  56590a:	7c 08                	jl     0x565914
  56590c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56590f:	3b 41 10             	cmp    eax,DWORD PTR [ecx+0x10]
  565912:	7c 06                	jl     0x56591a
  565914:	8d 44 24 18          	lea    eax,[esp+0x18]
  565918:	eb 08                	jmp    0x565922
  56591a:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  56591e:	8d 44 24 10          	lea    eax,[esp+0x10]
  565922:	8b 38                	mov    edi,DWORD PTR [eax]
  565924:	3b fa                	cmp    edi,edx
  565926:	0f 84 39 01 00 00    	je     0x565a65
```

### N31. Event SceneList script resource path and loader call

- VA `0x56592C..0x5659E3` [end exclusive]; raw `0x164D2C..0x164DE3`; **183 bytes**; SHA256 `385132cc922e14607427d84ca09a6bbe6b764b6f6a5c5cc189b53564441ce0ef`.

```asm
0056592c <.data+0x164d2c>:
  56592c:	6a 10                	push   0x10
  56592e:	68 d0 06 c1 00       	push   0xc106d0
  565933:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  565937:	c7 44 24 38 0f 00 00 	mov    DWORD PTR [esp+0x38],0xf
  56593e:	00 
  56593f:	c7 44 24 34 00 00 00 	mov    DWORD PTR [esp+0x34],0x0
  565946:	00 
  565947:	c6 44 24 24 00       	mov    BYTE PTR [esp+0x24],0x0
  56594c:	e8 1f d1 e9 ff       	call   0x402a70
  565951:	6a ff                	push   0xffffffff
  565953:	8d 47 14             	lea    eax,[edi+0x14]
  565956:	6a 00                	push   0x0
  565958:	bb 05 00 00 00       	mov    ebx,0x5
  56595d:	50                   	push   eax
  56595e:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  565962:	89 5c 24 54          	mov    DWORD PTR [esp+0x54],ebx
  565966:	e8 65 c5 e9 ff       	call   0x401ed0
  56596b:	6a 04                	push   0x4
  56596d:	68 e4 06 c1 00       	push   0xc106e4
  565972:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  565976:	e8 45 c6 e9 ff       	call   0x401fc0
  56597b:	83 7c 24 30 10       	cmp    DWORD PTR [esp+0x30],0x10
  565980:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  565984:	73 04                	jae    0x56598a
  565986:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  56598a:	f6 05 e8 1e fe 00 01 	test   BYTE PTR ds:0xfe1ee8,0x1
  565991:	75 22                	jne    0x5659b5
  565993:	83 0d e8 1e fe 00 01 	or     DWORD PTR ds:0xfe1ee8,0x1
  56599a:	c6 44 24 48 06       	mov    BYTE PTR [esp+0x48],0x6
  56599f:	e8 6c 6c ff ff       	call   0x55c610
  5659a4:	68 90 f2 bc 00       	push   0xbcf290
  5659a9:	e8 6c c9 32 00       	call   0x89231a
  5659ae:	83 c4 04             	add    esp,0x4
  5659b1:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  5659b5:	57                   	push   edi
  5659b6:	68 ec 1e fe 00       	push   0xfe1eec
  5659bb:	e8 e0 7c ff ff       	call   0x55d6a0
  5659c0:	bf 10 00 00 00       	mov    edi,0x10
  5659c5:	89 46 70             	mov    DWORD PTR [esi+0x70],eax
  5659c8:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  5659cc:	39 7c 24 30          	cmp    DWORD PTR [esp+0x30],edi
  5659d0:	73 04                	jae    0x5659d6
  5659d2:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5659d6:	8b 0e                	mov    ecx,DWORD PTR [esi]
  5659d8:	50                   	push   eax
  5659d9:	e8 72 f0 18 00       	call   0x6f4a50
  5659de:	e8 6d e8 ec ff       	call   0x434250
```

### N32. NPC event creator with nested object kind/id; not itself a chapter key

- VA `0x5442B0..0x5442F0` [end exclusive]; raw `0x1436B0..0x1436F0`; **64 bytes**; SHA256 `121cd8c15e20e97fe8e3d3aa5d4c8490a12eb74d2d1ec5973e00754df8b82778`.

```asm
005442b0 <.data+0x1436b0>:
  5442b0:	6c                   	ins    BYTE PTR es:[edi],dx
  5442b1:	e8 ba 6f 04 00       	call   0x58b270
  5442b6:	83 c4 44             	add    esp,0x44
  5442b9:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5442bd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5442c4:	59                   	pop    ecx
  5442c5:	5f                   	pop    edi
  5442c6:	5e                   	pop    esi
  5442c7:	5b                   	pop    ebx
  5442c8:	8b e5                	mov    esp,ebp
  5442ca:	5d                   	pop    ebp
  5442cb:	c3                   	ret
  5442cc:	53                   	push   ebx
  5442cd:	e8 1e 58 ff ff       	call   0x539af0
  5442d2:	e8 e9 11 ec ff       	call   0x4054c0
  5442d7:	6a 20                	push   0x20
  5442d9:	e8 8a cf 34 00       	call   0x891268
  5442de:	83 c4 04             	add    esp,0x4
  5442e1:	85 c0                	test   eax,eax
  5442e3:	74 3e                	je     0x544323
  5442e5:	0f b7 8e f6 00 00 00 	movzx  ecx,WORD PTR [esi+0xf6]
  5442ec:	0f b7 96 f4    	movzx  edx,WORD PTR [esi+0xf4]
```

## VI. 僅 T16 責任內的 pseudo-code / Server-facing interface contract

```cpp
// Interpret only as bounded KR Client pseudocode, not original class names.
// C = scene controller at 0xFB73C0 where original call sites use ECX accordingly.
void onNPCQuestEvent(WORD giverNpc, NestedEvent e) {
    WORD quest = firstType2CandidateForGiver(giverNpc); // 0x5008B0, may be 0
    sceneControllerInput((int)quest, 1);                // 0x5B9447 -> 0x561760
    sendNpcInteractionIfAllowed(e.kind, e.npcID);      // separate app 0x1C; not QuestID
}
void onS2CApp47(const uint8_t* p) {  // payload length ensured elsewhere, not by this function
    int first=(int16_t)LE16(p+2);  // first to controller+38
    int second=(int16_t)LE16(p+4);// second to controller+3C
    sceneControllerInput(first,second);
}
void sceneControllerInput(int primary, int secondary) {
    sceneFlag89=0;
    if (busy28!=0) { deferredOrNotifiedElsewhere(primary,secondary); return; }
    if (specialZeroKeyGate(primary,secondary)) { alternateAppProducer(0,secondary); return; }
    key38=primary; scene3C=secondary; busy28=1;
    // additional native state/VM/UI setup; not necessarily instant Lua execution
}
void executeEventSceneIfAllowed(int primary,int scene) {
    sceneFlag89=1;
    if(busy28!=0) { deferredOrNotifiedElsewhere(primary,scene); return; }
    key38=primary; scene3C=scene; busy28=1;
    if(!eventSceneListHas(primary,scene)) return; // no script fallback proven
    loadLuaScript(eventSceneListLookup(primary,scene));
}
void nextSceneWhenFlagged() {
    if(!sceneFlag89) return; // other control paths handled separately
    int next = tableSceneListNext(key38,scene3C);
    scene3C=next;
    if(next!=0) executeEventSceneIfAllowed(key38,next);
    else clearCurrentSceneKeysWhenRequired();
}
```

**相容 Server 可利用的已證 Client 介面**：`S→C 0x47` application 有兩個 WORD at offsets +2,+4 送到 controller；與 NPC/0x40/0x45 local producer 共用 `0x561760` gate。任何想依 Quest15 推動劇情的 Server 規格，必須另外決定 `0x47` 或其他已確認 handler 是否送、何時送、是否已有 controller state、Table SceneList 的實際 key/序列及 Event Script row 是否相容。**本報告不要求 Server 仿製不可見的原版判斷，只提供原版 Client 的相容入口。**

## VII. Four research-accountability buckets (T16-only; no cross-task dispatch)

- **Client 待逆向 / Input blockers**：完整 `Table/SceneList.xml` 真正 `chapterIdx`/`questId`/`sceneIdx` row 與順序；`0x6EDB60` busy 時 deferred input ownership與 replay；不同 widget 類實例的確切 class identity；將 NPC/scene events 配對實機 UI 的 runtime時序；特殊 key0xEA61 分支對劇情的進一步狀態差異。本段直接完成 native writer／gate，不把外部資料缺失改稱已確認 Scene3 必然播放。
- **Server 待開發 / 決策**：Quest15 eligibility/complete 及何時給 Client 0x47 等劇情鍵、任務完成標記、角色保存、劇情恢復介面；以上均是相容 Server 可自行設計，不聲稱原版相同。
- **跨功能待整合 / S00 管理**：Table原始 rows／資源版本與場景生命周期等底層資訊、登入狀態與任務 snapshot、應用封包 framing 的完整驗證；本T16原稿只列精確缺少的輸入／交界**不替其他 Task 指派或建立 RR**。
- **待遊玩驗證**：NPC10338 實際 click → quest candidate gate → controller+38 value；真正 Server 返回0x47後會否跳到 Scene3；Scene3 Lua Return/RestoreMap 後 UI／玩家位置；登出重登和壞封包/重複觸發。

**與 T16-117 T01 NEEDS_FIX 關係**：舊稿錯誤將 mode2 一律當 F4402→0x36，此研究完全不採用該錯誤；固定退回仍應獨立製作作者勘誤，新 SHA、送T01複驗。這不屬本段131的自動修復，也不佔 T16-132 名額。

## VIII. Final T16-131 status and precise next objective

- **T16-131：Native KR Client chapter/quest/scene key writer and relevant gate chain — BOUNDED COMPLETE.** 完成 `type2 NPC QuestID→controller`、`S2C 0x47 WORD pair→controller`、額外 0x40/0x45 wrapper、多來源+38/+3C、章節物件+248、FIRST/NEXT consumer、zero/miss/busy/reset 分支，且每條關係已附原始 assembly。這是 T16-131 計畫指定的**有界 Client 核對終點**，不是全部 Pindos E2E 或 T01 FULL-PASS。
- **仍未完成**：Quest15 完成必定播放 Scene3、Table.SceneList row 裏 primary key 的實際數字與順序、runtime response pairing、真正 Server 策略及可玩驗收。**下一段 T16-132** 研究 Quest15 FIRST/NEXT 觸發、scene-busy/deferred/UI callback、到尾和拒絕行為，根據131直接延伸，毋須重掃各個上游已解碼的 handler。
- 此 Markdown 是原始研究交付，不含未經 GitHub 實際回覆的 commit/blob 成功聲明；Commit / Push 後請以遠端讀回的 SHA 與 local Git blob 相符為準。
