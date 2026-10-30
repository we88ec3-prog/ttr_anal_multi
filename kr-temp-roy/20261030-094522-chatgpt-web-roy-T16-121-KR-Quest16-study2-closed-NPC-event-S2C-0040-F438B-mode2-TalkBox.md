# T16-121 — Quest16／②：NPC10027 觸發與 type2 候選；S2C `0x40` 的 `0xF438B → mode2 TalkBox` 正確 UI 橋（KR BIN-first）

- 研究者：`chatgpt-web roy`；原稿建立時間：`2026-10-30T09:45:22+08:00`；正式段號 **T16-121**，承接 T16-118/119 和前段未提交 T16-120。
- 範圍：**Quest16-② 玩家 NPC 觸發與 Client UI 橋的有界靜態閉合**。此處研究的是兩個已核實、條件式的 Client 界面：**(A)** NPC 點選事件能觸發 type2 QID16 候選與控制器；**(B)** 收到攜帶 QuestID16 的 `0x40` state0 application 時能建立 `0xF438B` 事件，通過派送表開啟 QuestInfo **mode2** TalkBox。**沒有證據證明原版 Server 必然在 A 後回送 B，因此不能聲稱 runtime A→B 必然發生、也不冒稱 `0x003F` 對應 `0x0040` 的一問一答。**
- 實際 BIN：`/mnt/data/Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE `.text` ImageBase `0x400000`、RVA `0x1000`、raw ptr `0x400`，code raw=`VA-0x400C00`。以下每一個 assembly slice 均從此唯讀原件重新反組譯並留原始 bytes hash。
- 不執行或修改原始 Client／Server、不創造動態 trace、無法重現原版 Server 對任何 NPC 事件的 response。其他 task 未被改寫。
- `main` 開工讀回 `d4639e45b1fbbaecb908f78822efa23141678a72`（觀測時點，提交前應重新核對）；T16 branch 開工相對 main ahead7/behind11。本對話已於首次啟動透過 PR#26 一次同步 main→T16；**本次不重做 Merge**。`research/dispatch/inbox/T16.md` 目前沒有 T16 RR；本段不是 S00 派工或 T01 FULL-PASS 宣告。

## 1. 問題、完成標準與最終有界結論

前段 T16-120 保留以下尚未閉合的假設：NPC10027 的 `type2` 候選 `QID16` 必須直接產生 `0x105B9(QID16)`，而 `0x105B9` 必須導向 **mode1 TalkBox**。此假設是不必要且部分錯誤的，因為**事件 type id 不能決定派送分支；真正的功能識別是 `event+0x10` 的 action code**。對相同 `0x105B9` vtable，`0xF438A` 與 `0xF438B` 在原生 action jump table 對應兩個獨立入口。

**本段達成的 Client 靜態終點（有界完成）：**

1. NPC actor 的 `0x105BD(action0x6A7)` 與巢狀 `0x105BF`，在 event action `0xF43D9` dispatch 時，確實進入 `0x5B9340`；`event+0x14` 的 giver selector 交 `0x5008B0`/`0x500A00` 尋找 type2 可接候選。當 NPC10027、同版完整 Quest XML 的 giver10027/type2 唯一候選、Quest14 prerequisite 等所有 gate 成立，返回 `QID16`，呼叫控制器 `0x561760(16,1)`，並在獨立 sender gate 成立時建立 `0x001C` payload。控制器另外可能有 `0x003F` 8-byte application producer（T16-120）；二者不能冒充 `0x0036`。
2. `0x502270`（前段已定位 S→C index `0x40` handler）在 **input DWORD `[pkt+4]==0`** 時，從 `WORD [pkt+2]` 零擴展出 QuestID，建構 vptr `0xC467AC`/type `0x105B9`、**action `0xF438B`**、`event+0x14=QuestID`；呼叫 `0x58AA50` 送往事件佇列。若 `pkt+2==16`，此時是**原生 writer 直接寫入 QID16**，不是把 NPC10027 假稱 16。
3. `0x5B7F80` event dispatcher：`(action-0xF4364)` 查 byte table `0x5B8460`，再查 DWORD jump table `0x5B8394`。`0xF438B` 的索引 **`0x27` → case `0x0C` → `0x5B7FFF`**，其 call `0x5B6D20`。此函式核對 type `0x105B9`，以 `event+0x14` 直接作為 QuestInfo map key（`0x503D20`），成功時讀該 record 的 `+0x28`（NPC giver）並 **push `0x2`，call `0x636520`**，因此打開 **mode2** 的 QuestInfo TalkBox；無法 lookup 或分配/可用狀態不符時不能保證顯示。
4. `0x636520` mode2 確認 `TalkBox+0x80=event QuestID16`、`TalkBox+0x84=QuestRecord.giver10027`，mode2 jump table `[0x636774+2*4]=0x636687`，透過 `0x500F90` 取得 QuestTalk/文字實例儲存在 `+0x88`、讀其 `+0x34` 調用 `0x635F10`。顯示條件與 type1 路徑完全不同。從 Client 能核對「接收此 state0 message → QID16 mode2 TalkBox」的**業務處理鏈**，但不等於真實原版 Server 必發。
5. 正確反例：`0xF438A` 索引 `0x26` → case `0x0B` → `0x5B7FED` → `0x5B6BE0` → TalkBox **mode1**。其兩個可見 producer：`0x636CCD` `0x5007D0→0x500950`（type1 查詢）與 `0x62EFC1`（另一 UI quest list record）均**不是** NPC10027 type2 candidate 接到 TalkBox 的原生證據。`0x6391C0/0x639210` 讀 `[child+4]+0x84`：由 `0x635A2F` 可知 child+4=TalkBox，該欄位是**NPC giver10027**，非 QuestID16。故先前擬追的 mode1 widget bridge 無需、也不得強行拼接。

**結論語意**：Quest16-② 在「NPC 互動選出 type2 候選的 Client 路徑」以及「含 QID16 的原生 S2C state0 事件如何進入 mode2 TalkBox」兩個**條件式 Client 靜態子鏈**上已閉合。這不是「點 NPC10027 必然看見 Quest16 對話」的實測證明；C→S 0x3F 與 S→C 0x40 的特定 Server 配對、`0x36` 何時送出、Server 成功／拒絕／獎勵、Quest15 解鎖分別屬後續③④⑤或真正 Server 設計。若後續 ③④ 需要完整端到端請保留可追索鏈節，不擅自補假資料。

## 2. 事件 action 反向表（由 BIN 原始 table bytes 計算，不靠文字推測）

`0x5B7F93 mov eax,[esi+0x10]`, `0x5B7F96 add eax,0xFFF0BC9C` = `action − 0xF4364`; `0x5B7FA6 movzx eax, byte [eax+0x5B8460]`; `0x5B7FAE jmp dword [eax*4+0x5B8394]`。從 raw byte 直接計算得：

| action | offset from 0xF4364 | 0x5B8460 byte case | 0x5B8394 target | Client meaning |
|---|---:|---:|---|---|
| `0xF43D9` | `0x75` | `0x1E` | `0x5B8167` | `0x5B9340` NPC 0x105BD action6A7/0x105BF type2 chooser |
| `0xF438A` | `0x26` | `0x0B` | `0x5B7FED` | `0x5B6BE0` QuestInfo TalkBox mode1 |
| **`0xF438B`** | **`0x27`** | **`0x0C`** | **`0x5B7FFF`** | **`0x5B6D20` QuestInfo TalkBox mode2** |
| `0xF43E0` | `0x7C` | `0x20` | `0x5B81C7` | another local event path, not forced to mode2 |
| `0xF43E1` | `0x7D` | `0x21` | `0x5B81D8` | another local event path, not forced to mode2 |

注意：`0x58AA50` 透過 `0x804260` 將 event pointer 放入全域 `0xF95C6C` 的 container；`0x804260` 本身是 append/enqueue **不是** callback 立即呼叫。`0x423470` 的 callback 明文呼叫 `0x5B7F80`；主程式何時 poll、UI 不在可見狀態時如何處理 queue，未以動態 trace 確認，故只斷言「被分派後，這些 handler 會如何運作」，不能稱同步立即顯示。原版現場 UI、當下 Quest14 state、記憶體/分配失敗等 gate 另列。

## 3. 真正的 Quest16 NPC 與 S2C/UI 業務資料路徑

```text
[Resource XML recorded in T16-112/117]
 Quest14 (type3) -> prerequisite key14, Quest16 (type2 giver10027, Demand14)
         |                    [all candidate exclusions/level/town satisfy]
         v
 NPC actor click/interact + event subtype 0xF43D9
 0x105BD action6A7 -> nested 0x105BF(+14=NPC giver10027; +18/+1C separate event words)
 -> 0x5B7F80 jump table -> 0x5B8167 -> 0x5B9340 -> 0x5008B0 -> 0x500A00
 -> unique type2 candidate QID16 -> 0x561760(16,1)
 -> conditional 0x003F (NOT unique ACK) and separate 0x001C (independent source)

 [No proved causal pairing of two directions across the original Server]

 Inbound S→C index0x40 handler 0x502270, packet WORD+2=16, DWORD+4=0
 -> vptr 0xC467AC type0x105B9, ACTION 0xF438B, event+14=16
 -> 0x58AA50 -> queue 0xF95C6C
 -> event callback 0x423470 -> 0x5B7F80 action map 0xF438B
 -> 0x5B7FFF -> 0x5B6D20 -> QuestInfo map 0x503D20 key16
 -> QuestRecord+28=giver10027 -> TalkBox 0x636520 MODE2
 -> TalkBox+80=16, +84=10027; +88=0x500F90 item
 -> MODE2 jump table 0x636687 -> item+34 displayed via 0x635F10
 -> depends on player UI and later C2S/Server handling, NOT acceptance confirmation

 [Reject bad bridge]
 ACTION 0xF438A -> 0x5B7FED -> 0x5B6BE0 -> MODE1 only;
 UI child+4 = TalkBox, TalkBox+84 = NPC10027 (not QID16)
```

### 3.1 Player/C2S/S2C/UI conditional matrix

| Player scenario | Input and gate | C→S application evidence | S→C business handler | Local Client effect / classification |
|---|---|---|---|---|
| NPC10027 interaction | actor action `0xF43D9`, outer `0x105BD(action6A7)`, child `0x105BF+14=10027`, candidate 14 prerequisite etc | same-event independent `0x001C` 6B (when sender gate clear) | not uniquely paired | first type2 QID16 passed to `0x561760` **native conditional** |
| controller deferred QID16, mode1 | nonbusy and correct state/other gates | conditional `0x003F` app 8B `3F 00 10 00 01 00 01 00` (see T16-120) | cannot say it causes `0x40` | local controller/scene selection **native conditional** |
| S2C message index `0x40` state0, ID16 | `[pkt+4]=0`, WORD `[pkt+2]=16`, allocation succeeds | no new C2S implied by handling it | **`0x502270`** | `0x105B9/action F438B/QID16` enqueued; if event callback runs and XML record found → mode2 TalkBox **native conditional** |
| S2C message index `0x40` nonzero state | `[pkt+4]!=0` | none deduced | `0x5026CA` elsewhere | NOT part of asserted mode2 route; requires later formal ④ |
| event `0xF438A` ID16 | legitimate producer must produce ID16; no type2 link in examined two callers | TalkBox confirm may eventually produce `0x36` only under its own gate | not uniquely paired | mode1 distinct, **do not use as Quest16 event proof** |
| event type `0x105B9` without action match | subtype not F438A/F438B | none | jump table routes elsewhere/out of range | vptr alone insufficient; no fake UI reachability |
| actual original Server accepts Quest16 | unknown after NPC interaction | `0x001C/0x003F/0x0036` cannot merge | no proved ACK relationship | **Server decision/③④ and gameplay testing required** |

## 4. 需求拆分、交接、證據等級、限制

- **Quest16 ①**（T16-118）有界已完成：XML resource, Demand14, Reward type2=50 metadata, native loader→record.
- **Quest16 ②**（T16-119/120/121）**Client 靜態有界完成**：NPC action subtype→type2 giver selector QID16→controller；S2C app state0+QID16→action F438B→mode2 TalkBox。**並不表示原版 NPC 點選後一定收到這個封包；完全可玩尚未驗證**。
- **Quest16 ③** C→S 待正式端到端：`0x001C` 事件／`0x003F` 控制器／`0x0036` TalkBox confirm 三種 packet producer 各自 gate、實際發送線及何時發出；不能混成一個 accept opcode；T02 framing 與內層 opcode 若需以 wire 證實，列交界。
- **Quest16 ④** S→C/狀態/UI 待正式端到端：`0x0040` 兩種 state、`0x0074` prereq, `0x0036/0x003F` 相容 response/拒絕/accept 的配對 **未知**；這是有意保留的上層業務缺口，不屬②的 NPC/UI 靜態 selector 目標未解。
- **Quest16 ⑤** Quest16 完成後 prerequisite key16→Quest15 Demand16、NPC10338/field19/town5/scene 與 Pindos/Fünders 待正式端到端。

**Client 待逆向**：③ 真正 outbound wire/frame、④ state1/error處理、mode2 TalkBox confirm 與 cache 寫入等；event queue scheduler 的精確 poll 時機未作動態驗證。**Server 待開發**：需能依相容業務決策產生原生 Client 能消費的 `0x40` 及其他 snapshot/旗標；但不能用這推斷原版官方何時／為何回覆。**跨 Task 待整合**：T02 收發 framing，T06 UI，T07 場景，T08 actor，T14 stage result，T15 persistent state，T03/T04 session。**待遊玩驗證**：當前場景是否真的有 NPC10027、玩家手勢、封包實際時序與 Server 接取成功、Quest15 unlocked；這些均非本段靜態 Client 已證事實。

## 5. 明確修正舊結論的差異紀錄

1. T16-120 尚假設必須讓 NPC `0x105BF+14=10027` 直接寫到 **`0x105B9+14=16` 的 mode1** 才能完成②；本段 BIN 証明 state0 S2C `0x40` 有獨立 `0xF438B QID16 → mode2`，不應跨過原版 Server 的未知決策來拼 direct event。
2. T16-120 的「UI widget+0x84 可能為 QuestID16」已由同物件別名 native `0x6359FF/0x635A2F` 和 `0x63656B` 反證：child+4=TalkBox, TalkBox+84=giver。若 10027，該欄位不是 QID16。
3. T16-119/120 對 105BA/105BF 直接轉 105B9 的分析仍保留，但**action subtype 不等**，不能只由相同 vptr/type推出同一個 TalkBox handler。
4. `0x502270` state0 雖會產生兩個 vptr 0x105B9 事件：第一個 action `0xF4281` 值0、第二個 action `0xF438B` 值QID；兩者不能混為同一事件。真正 mode2 consumer 是**第二個**。
5. `0x5023E2` 的 `QuestRecord+0x3C` 分類與 `QuestInfo.type` record+4 **不是同一欄位**；本段只就按 QID16 事件的 UI 路徑下結論，不把分支 `+0x3C==2` 當成 `QuestInfo.type==2` 的必然證明。

## 6. 完整 BIN 對齊反組譯切片與原始 byte hash

所有 code raw `VA−0x400C00`。`objdump` 使用 i386 intel、binary VMA 0x400C00；每個 raw span 的 SHA256 為方便外部驗證之直接 byte hash。若切片含有資料表或落在相鄰基本塊之間，僅由實際 jump target 與對齊完整指令支持正主張，不以線性误解跳表為 code。**原檔未上傳 GitHub。**

### S01 — NPC 0x105BF producer actor fields, action0xF43D9; VA `0x005442cc..0x0054436f`; raw `0x1436cc..0x14376f`; 163 bytes; SHA256 `d0003e30cef561af07eb5afface6c3d54fc274f1b6de89d7d22358565776a761`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005442cc <.data+0x1436cc>:
  5442cc:	53                   	push   ebx
  5442cd:	e8 1e 58 ff ff       	call   0x539af0
  5442d2:	e8 e9 11 ec ff       	call   0x4054c0
  5442d7:	6a 20                	push   0x20
  5442d9:	e8 8a cf 34 00       	call   0x891268
  5442de:	83 c4 04             	add    esp,0x4
  5442e1:	85 c0                	test   eax,eax
  5442e3:	74 3e                	je     0x544323
  5442e5:	0f b7 8e f6 00 00 00 	movzx  ecx,WORD PTR [esi+0xf6]
  5442ec:	0f b7 96 f4 00 00 00 	movzx  edx,WORD PTR [esi+0xf4]
  5442f3:	0f bf d2             	movsx  edx,dx
  5442f6:	0f bf c9             	movsx  ecx,cx
  5442f9:	83 cb ff             	or     ebx,0xffffffff
  5442fc:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  5442ff:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  544302:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  544309:	c7 40 10 d9 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43d9
  544310:	c7 00 e4 7b c4 00    	mov    DWORD PTR [eax],0xc47be4
  544316:	89 78 14             	mov    DWORD PTR [eax+0x14],edi
  544319:	89 50 18             	mov    DWORD PTR [eax+0x18],edx
  54431c:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  54431f:	8b f0                	mov    esi,eax
  544321:	eb 05                	jmp    0x544328
  544323:	33 f6                	xor    esi,esi
  544325:	83 cb ff             	or     ebx,0xffffffff
  544328:	e8 73 07 ec ff       	call   0x404aa0
  54432d:	8b 80 c4 13 00 00    	mov    eax,DWORD PTR [eax+0x13c4]
  544333:	50                   	push   eax
  544334:	56                   	push   esi
  544335:	83 ec 1c             	sub    esp,0x1c
  544338:	8b cc                	mov    ecx,esp
  54433a:	89 64 24 3c          	mov    DWORD PTR [esp+0x3c],esp
  54433e:	68 fc d1 be 00       	push   0xbed1fc
  544343:	e8 08 df eb ff       	call   0x402250
  544348:	c7 44 24 4c 03 00 00 	mov    DWORD PTR [esp+0x4c],0x3
  54434f:	00 
  544350:	c7 44 24 38 21 00 00 	mov    DWORD PTR [esp+0x38],0x21
  544357:	00 
  544358:	e8 53 11 04 00       	call   0x5854b0
  54435d:	8b f0                	mov    esi,eax
  54435f:	8d 54 24 38          	lea    edx,[esp+0x38]
  544363:	52                   	push   edx
  544364:	8d 44 24 38          	lea    eax,[esp+0x38]
  544368:	8b ce                	mov    ecx,esi
  54436a:	e8 81 fd 02 00       	call   0x5740f0
```

### S02 — event hub action dispatch, source/caller 0xF43D9; VA `0x005b7f80..0x005b8031`; raw `0x1b7380..0x1b7431`; 177 bytes; SHA256 `44cae149e0b7367e426dff6a23b1bf72a5592412e6222ebf34f86fbfbb833ece`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b7f80 <.data+0x1b7380>:
  5b7f80:	55                   	push   ebp
  5b7f81:	8b ec                	mov    ebp,esp
  5b7f83:	83 ec 08             	sub    esp,0x8
  5b7f86:	53                   	push   ebx
  5b7f87:	56                   	push   esi
  5b7f88:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5b7f8b:	56                   	push   esi
  5b7f8c:	8b d9                	mov    ebx,ecx
  5b7f8e:	e8 ed 3d fe ff       	call   0x59bd80
  5b7f93:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  5b7f96:	05 9c bc f0 ff       	add    eax,0xfff0bc9c
  5b7f9b:	3d db 00 00 00       	cmp    eax,0xdb
  5b7fa0:	0f 87 e3 03 00 00    	ja     0x5b8389
  5b7fa6:	0f b6 80 60 84 5b 00 	movzx  eax,BYTE PTR [eax+0x5b8460]
  5b7fad:	57                   	push   edi
  5b7fae:	ff 24 85 94 83 5b 00 	jmp    DWORD PTR [eax*4+0x5b8394]
  5b7fb5:	8b c3                	mov    eax,ebx
  5b7fb7:	e8 b4 eb ff ff       	call   0x5b6b70
  5b7fbc:	5f                   	pop    edi
  5b7fbd:	5e                   	pop    esi
  5b7fbe:	5b                   	pop    ebx
  5b7fbf:	8b e5                	mov    esp,ebp
  5b7fc1:	5d                   	pop    ebp
  5b7fc2:	c2 04 00             	ret    0x4
  5b7fc5:	8b 8b 24 02 00 00    	mov    ecx,DWORD PTR [ebx+0x224]
  5b7fcb:	8b 51 28             	mov    edx,DWORD PTR [ecx+0x28]
  5b7fce:	c1 ea 08             	shr    edx,0x8
  5b7fd1:	f6 c2 01             	test   dl,0x1
  5b7fd4:	0f 84 ae 03 00 00    	je     0x5b8388
  5b7fda:	8b 01                	mov    eax,DWORD PTR [ecx]
  5b7fdc:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  5b7fe2:	ff d2                	call   edx
  5b7fe4:	5f                   	pop    edi
  5b7fe5:	5e                   	pop    esi
  5b7fe6:	5b                   	pop    ebx
  5b7fe7:	8b e5                	mov    esp,ebp
  5b7fe9:	5d                   	pop    ebp
  5b7fea:	c2 04 00             	ret    0x4
  5b7fed:	8b ce                	mov    ecx,esi
  5b7fef:	8b d3                	mov    edx,ebx
  5b7ff1:	e8 ea eb ff ff       	call   0x5b6be0
  5b7ff6:	5f                   	pop    edi
  5b7ff7:	5e                   	pop    esi
  5b7ff8:	5b                   	pop    ebx
  5b7ff9:	8b e5                	mov    esp,ebp
  5b7ffb:	5d                   	pop    ebp
  5b7ffc:	c2 04 00             	ret    0x4
  5b7fff:	8b ce                	mov    ecx,esi
  5b8001:	8b d3                	mov    edx,ebx
  5b8003:	e8 18 ed ff ff       	call   0x5b6d20
  5b8008:	5f                   	pop    edi
  5b8009:	5e                   	pop    esi
  5b800a:	5b                   	pop    ebx
  5b800b:	8b e5                	mov    esp,ebp
  5b800d:	5d                   	pop    ebp
  5b800e:	c2 04 00             	ret    0x4
  5b8011:	8b ce                	mov    ecx,esi
  5b8013:	8b d3                	mov    edx,ebx
  5b8015:	e8 46 ee ff ff       	call   0x5b6e60
  5b801a:	5f                   	pop    edi
  5b801b:	5e                   	pop    esi
  5b801c:	5b                   	pop    ebx
  5b801d:	8b e5                	mov    esp,ebp
  5b801f:	5d                   	pop    ebp
  5b8020:	c2 04 00             	ret    0x4
  5b8023:	8b f3                	mov    esi,ebx
  5b8025:	e8 76 ef ff ff       	call   0x5b6fa0
  5b802a:	5f                   	pop    edi
  5b802b:	5e                   	pop    esi
  5b802c:	5b                   	pop    ebx
  5b802d:	8b e5                	mov    esp,ebp
  5b802f:	5d                   	pop    ebp
  5b8030:	c2               	ret    0x4
```

### S03 — event hub jump case NPC 0x5B9340; VA `0x005b8157..0x005b8177`; raw `0x1b7557..0x1b7577`; 32 bytes; SHA256 `ed72c5a23efd5bcb362cb857d670e3aef2832c5f71e3727ee280dd9c69a4ebbc`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b8157 <.data+0x1b7557>:
  5b8157:	8b c6                	mov    eax,esi
  5b8159:	e8 32 35 00 00       	call   0x5bb690
  5b815e:	5f                   	pop    edi
  5b815f:	5e                   	pop    esi
  5b8160:	5b                   	pop    ebx
  5b8161:	8b e5                	mov    esp,ebp
  5b8163:	5d                   	pop    ebp
  5b8164:	c2 04 00             	ret    0x4
  5b8167:	8b ce                	mov    ecx,esi
  5b8169:	e8 d2 11 00 00       	call   0x5b9340
  5b816e:	5f                   	pop    edi
  5b816f:	5e                   	pop    esi
  5b8170:	5b                   	pop    ebx
  5b8171:	8b e5                	mov    esp,ebp
  5b8173:	5d                   	pop    ebp
  5b8174:	c2 04 00             	ret    0x4
```

### S04 — NPC subtype 0x6A7, QuestID type2 selection, controller, C2S 0x1C; VA `0x005b9340..0x005b9498`; raw `0x1b8740..0x1b8898`; 344 bytes; SHA256 `69a5aadbc0a1ffa9d11ec62c74a1d8a40e201eee8d0e9192b5903e56aab4df99`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9340 <.data+0x1b8740>:
  5b9340:	55                   	push   ebp
  5b9341:	8b ec                	mov    ebp,esp
  5b9343:	6a ff                	push   0xffffffff
  5b9345:	68 b7 73 94 00       	push   0x9473b7
  5b934a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b9350:	50                   	push   eax
  5b9351:	83 ec 0c             	sub    esp,0xc
  5b9354:	56                   	push   esi
  5b9355:	57                   	push   edi
  5b9356:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b935b:	33 c5                	xor    eax,ebp
  5b935d:	50                   	push   eax
  5b935e:	8d 45 f4             	lea    eax,[ebp-0xc]
  5b9361:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b9367:	8b f1                	mov    esi,ecx
  5b9369:	8b 3d 80 25 bd 00    	mov    edi,DWORD PTR ds:0xbd2580
  5b936f:	85 f6                	test   esi,esi
  5b9371:	74 22                	je     0x5b9395
  5b9373:	8b 06                	mov    eax,DWORD PTR [esi]
  5b9375:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b9378:	ff d2                	call   edx
  5b937a:	3d bd 05 01 00       	cmp    eax,0x105bd
  5b937f:	75 04                	jne    0x5b9385
  5b9381:	8b c6                	mov    eax,esi
  5b9383:	eb 12                	jmp    0x5b9397
  5b9385:	6a 00                	push   0x0
  5b9387:	68 c0 1f bf 00       	push   0xbf1fc0
  5b938c:	68 18 21 bf 00       	push   0xbf2118
  5b9391:	6a 00                	push   0x0
  5b9393:	ff d7                	call   edi
  5b9395:	33 c0                	xor    eax,eax
  5b9397:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b939a:	81 f9 a7 06 00 00    	cmp    ecx,0x6a7
  5b93a0:	0f 85 f2 00 00 00    	jne    0x5b9498
  5b93a6:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  5b93a9:	85 f6                	test   esi,esi
  5b93ab:	74 20                	je     0x5b93cd
  5b93ad:	8b 06                	mov    eax,DWORD PTR [esi]
  5b93af:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b93b2:	8b ce                	mov    ecx,esi
  5b93b4:	ff d2                	call   edx
  5b93b6:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b93bb:	74 12                	je     0x5b93cf
  5b93bd:	6a 00                	push   0x0
  5b93bf:	68 c0 1f bf 00       	push   0xbf1fc0
  5b93c4:	68 18 21 bf 00       	push   0xbf2118
  5b93c9:	6a 00                	push   0x0
  5b93cb:	ff d7                	call   edi
  5b93cd:	33 f6                	xor    esi,esi
  5b93cf:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b93d6:	75 27                	jne    0x5b93ff
  5b93d8:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b93df:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  5b93e6:	e8 75 6a f4 ff       	call   0x4ffe60
  5b93eb:	68 00 cf bc 00       	push   0xbccf00
  5b93f0:	e8 25 8f 2d 00       	call   0x89231a
  5b93f5:	83 c4 04             	add    esp,0x4
  5b93f8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
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
  5b9485:	ff d0                	call   eax
  5b9487:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5b948a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b9491:	59                   	pop    ecx
  5b9492:	5f                   	pop    edi
  5b9493:	5e                   	pop    esi
  5b9494:	8b e5                	mov    esp,ebp
  5b9496:	5d                   	pop    ebp
  5b9497:	c3                   	ret
```

### S05 — client Quest type2 0x5008B0 helper; VA `0x005008b0..0x0050094f`; raw `0xffcb0..0xffd4f`; 159 bytes; SHA256 `7a222fadf62674bc46d4e1c79ff3401134de1971d4c89b53f5d66d90d3a18d5b`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

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
  500944:	cc                   	int3
  500945:	cc                   	int3
  500946:	cc                   	int3
  500947:	cc                   	int3
  500948:	cc                   	int3
  500949:	cc                   	int3
  50094a:	cc                   	int3
  50094b:	cc                   	int3
  50094c:	cc                   	int3
  50094d:	cc                   	int3
  50094e:	cc                   	int3
```

### S06 — Client out-bound application 0x3F; VA `0x004a39a0..0x004a39ed`; raw `0xa2da0..0xa2ded`; 77 bytes; SHA256 `6c8c48ca44daab51a10224e1191b7711fbebf571352fce8ebeaab65265fa9477`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004a39a0 <.data+0xa2da0>:
  4a39a0:	55                   	push   ebp
  4a39a1:	8b ec                	mov    ebp,esp
  4a39a3:	83 ec 08             	sub    esp,0x8
  4a39a6:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a39ad:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4a39b1:	66 8b 55 0c          	mov    dx,WORD PTR [ebp+0xc]
  4a39b5:	b8 3f 00 00 00       	mov    eax,0x3f
  4a39ba:	66 89 45 f8          	mov    WORD PTR [ebp-0x8],ax
  4a39be:	b8 01 00 00 00       	mov    eax,0x1
  4a39c3:	66 89 4d fa          	mov    WORD PTR [ebp-0x6],cx
  4a39c7:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  4a39cb:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  4a39cf:	75 15                	jne    0x4a39e6
  4a39d1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a39d7:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a39d9:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a39dc:	6a 08                	push   0x8
  4a39de:	8d 45 f8             	lea    eax,[ebp-0x8]
  4a39e1:	50                   	push   eax
  4a39e2:	6a 00                	push   0x0
  4a39e4:	ff d2                	call   edx
  4a39e6:	8b e5                	mov    esp,ebp
  4a39e8:	5d                   	pop    ebp
  4a39e9:	c2 08 00             	ret    0x8
  4a39ec:	cc                   	int3
```

### S07 — in-bound handler 0x40 state-zero, QID from packet and event construction; VA `0x00502270..0x0050238e`; raw `0x101670..0x10178e`; 286 bytes; SHA256 `e3d2f3ad5b35c61b3fc5cea4148148c455181548e29f5c857704bba0cbafc60f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00502270 <.data+0x101670>:
  502270:	55                   	push   ebp
  502271:	8b ec                	mov    ebp,esp
  502273:	6a ff                	push   0xffffffff
  502275:	68 a8 41 94 00       	push   0x9441a8
  50227a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  502280:	50                   	push   eax
  502281:	81 ec a4 00 00 00    	sub    esp,0xa4
  502287:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50228c:	33 c5                	xor    eax,ebp
  50228e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  502291:	53                   	push   ebx
  502292:	56                   	push   esi
  502293:	57                   	push   edi
  502294:	50                   	push   eax
  502295:	8d 45 f4             	lea    eax,[ebp-0xc]
  502298:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50229e:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  5022a1:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  5022a4:	33 ff                	xor    edi,edi
  5022a6:	89 8d 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],ecx
  5022ac:	3b c7                	cmp    eax,edi
  5022ae:	0f 85 16 04 00 00    	jne    0x5026ca
  5022b4:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5022bb:	75 24                	jne    0x5022e1
  5022bd:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  5022c4:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5022c7:	e8 b4 51 08 00       	call   0x587480
  5022cc:	68 c0 cc bc 00       	push   0xbcccc0
  5022d1:	e8 44 00 39 00       	call   0x89231a
  5022d6:	83 c4 04             	add    esp,0x4
  5022d9:	83 ce ff             	or     esi,0xffffffff
  5022dc:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5022df:	eb 03                	jmp    0x5022e4
  5022e1:	83 ce ff             	or     esi,0xffffffff
  5022e4:	6a 18                	push   0x18
  5022e6:	e8 7d ef 38 00       	call   0x891268
  5022eb:	83 c4 04             	add    esp,0x4
  5022ee:	3b c7                	cmp    eax,edi
  5022f0:	74 1e                	je     0x502310
  5022f2:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  5022f5:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  5022f8:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  5022fb:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  5022fe:	c7 40 10 81 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4281
  502305:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50230b:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  50230e:	eb 02                	jmp    0x502312
  502310:	33 c0                	xor    eax,eax
  502312:	50                   	push   eax
  502313:	e8 38 87 08 00       	call   0x58aa50
  502318:	83 c4 04             	add    esp,0x4
  50231b:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  502322:	75 23                	jne    0x502347
  502324:	b8 01 00 00 00       	mov    eax,0x1
  502329:	09 05 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,eax
  50232f:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  502332:	e8 49 51 08 00       	call   0x587480
  502337:	68 c0 cc bc 00       	push   0xbcccc0
  50233c:	e8 d9 ff 38 00       	call   0x89231a
  502341:	83 c4 04             	add    esp,0x4
  502344:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  502347:	6a 18                	push   0x18
  502349:	e8 1a ef 38 00       	call   0x891268
  50234e:	83 c4 04             	add    esp,0x4
  502351:	3b c7                	cmp    eax,edi
  502353:	74 1f                	je     0x502374
  502355:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  502359:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  50235c:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  50235f:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  502362:	c7 40 10 8b 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438b
  502369:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50236f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502372:	eb 02                	jmp    0x502376
  502374:	33 c0                	xor    eax,eax
  502376:	50                   	push   eax
  502377:	e8 d4 86 08 00       	call   0x58aa50
  50237c:	0f b7 73 02          	movzx  esi,WORD PTR [ebx+0x2]
  502380:	8b bd 54 ff ff ff    	mov    edi,DWORD PTR [ebp-0xac]
  502386:	83 c4 04             	add    esp,0x4
  502389:	e8 82 dd ff ff       	call   0x500110
```

### S08 — S2C handler QuestRecord lookup and type-dependent controller; VA `0x00502389..0x0050244c`; raw `0x101789..0x10184c`; 195 bytes; SHA256 `dc4a3ad9ba25068e2be34bded5ca1c9363b26f3bdd28432ae5b2ece730ebe902`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00502389 <.data+0x101789>:
  502389:	e8 82 dd ff ff       	call   0x500110
  50238e:	e8 cd cc f0 ff       	call   0x40f060
  502393:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  502399:	50                   	push   eax
  50239a:	8b f7                	mov    esi,edi
  50239c:	56                   	push   esi
  50239d:	e8 9e de ff ff       	call   0x500240
  5023a2:	0f b7 7b 02          	movzx  edi,WORD PTR [ebx+0x2]
  5023a6:	8b b6 ac 5e 00 00    	mov    esi,DWORD PTR [esi+0x5eac]
  5023ac:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
  5023b2:	50                   	push   eax
  5023b3:	8d 85 50 ff ff ff    	lea    eax,[ebp-0xb0]
  5023b9:	8b ce                	mov    ecx,esi
  5023bb:	89 bd 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],edi
  5023c1:	e8 5a 19 00 00       	call   0x503d20
  5023c6:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5023c9:	8b 85 50 ff ff ff    	mov    eax,DWORD PTR [ebp-0xb0]
  5023cf:	3b c6                	cmp    eax,esi
  5023d1:	0f 84 d5 03 00 00    	je     0x5027ac
  5023d7:	8d 58 10             	lea    ebx,[eax+0x10]
  5023da:	85 db                	test   ebx,ebx
  5023dc:	0f 84 ca 03 00 00    	je     0x5027ac
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

### S09 — event enqueue 0x58AA50 to queue; VA `0x0058aa50..0x0058aaca`; raw `0x189e50..0x189eca`; 122 bytes; SHA256 `233f309a173796ad1bc25d095ebc6c41f55e01b3f9f7d80e2fda1d6af766cb52`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0058aa50 <.data+0x189e50>:
  58aa50:	55                   	push   ebp
  58aa51:	8b ec                	mov    ebp,esp
  58aa53:	6a ff                	push   0xffffffff
  58aa55:	68 be 69 91 00       	push   0x9169be
  58aa5a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  58aa60:	50                   	push   eax
  58aa61:	56                   	push   esi
  58aa62:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  58aa67:	33 c5                	xor    eax,ebp
  58aa69:	50                   	push   eax
  58aa6a:	8d 45 f4             	lea    eax,[ebp-0xc]
  58aa6d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  58aa73:	b8 01 00 00 00       	mov    eax,0x1
  58aa78:	84 05 d0 ad fa 00    	test   BYTE PTR ds:0xfaadd0,al
  58aa7e:	75 26                	jne    0x58aaa6
  58aa80:	09 05 d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,eax
  58aa86:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  58aa8d:	e8 fe 2e 1c 00       	call   0x74d990
  58aa92:	68 70 cc bc 00       	push   0xbccc70
  58aa97:	e8 7e 78 30 00       	call   0x89231a
  58aa9c:	83 c4 04             	add    esp,0x4
  58aa9f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  58aaa6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  58aaa9:	8d 4d 08             	lea    ecx,[ebp+0x8]
  58aaac:	51                   	push   ecx
  58aaad:	be 6c 5c f9 00       	mov    esi,0xf95c6c
  58aab2:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  58aab5:	e8 a6 97 27 00       	call   0x804260
  58aaba:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  58aabd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  58aac4:	59                   	pop    ecx
  58aac5:	5e                   	pop    esi
  58aac6:	8b e5                	mov    esp,ebp
  58aac8:	5d                   	pop    ebp
  58aac9:	c3                   	ret
```

### S10 — event bus dispatcher 0x5B7F80 action 0xF438B; VA `0x005b7f80..0x005b8011`; raw `0x1b7380..0x1b7411`; 145 bytes; SHA256 `432c192de7ec5a9468206ad8db748f5037ae6819591d76bc1dbc3736050b3fcc`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b7f80 <.data+0x1b7380>:
  5b7f80:	55                   	push   ebp
  5b7f81:	8b ec                	mov    ebp,esp
  5b7f83:	83 ec 08             	sub    esp,0x8
  5b7f86:	53                   	push   ebx
  5b7f87:	56                   	push   esi
  5b7f88:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5b7f8b:	56                   	push   esi
  5b7f8c:	8b d9                	mov    ebx,ecx
  5b7f8e:	e8 ed 3d fe ff       	call   0x59bd80
  5b7f93:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  5b7f96:	05 9c bc f0 ff       	add    eax,0xfff0bc9c
  5b7f9b:	3d db 00 00 00       	cmp    eax,0xdb
  5b7fa0:	0f 87 e3 03 00 00    	ja     0x5b8389
  5b7fa6:	0f b6 80 60 84 5b 00 	movzx  eax,BYTE PTR [eax+0x5b8460]
  5b7fad:	57                   	push   edi
  5b7fae:	ff 24 85 94 83 5b 00 	jmp    DWORD PTR [eax*4+0x5b8394]
  5b7fb5:	8b c3                	mov    eax,ebx
  5b7fb7:	e8 b4 eb ff ff       	call   0x5b6b70
  5b7fbc:	5f                   	pop    edi
  5b7fbd:	5e                   	pop    esi
  5b7fbe:	5b                   	pop    ebx
  5b7fbf:	8b e5                	mov    esp,ebp
  5b7fc1:	5d                   	pop    ebp
  5b7fc2:	c2 04 00             	ret    0x4
  5b7fc5:	8b 8b 24 02 00 00    	mov    ecx,DWORD PTR [ebx+0x224]
  5b7fcb:	8b 51 28             	mov    edx,DWORD PTR [ecx+0x28]
  5b7fce:	c1 ea 08             	shr    edx,0x8
  5b7fd1:	f6 c2 01             	test   dl,0x1
  5b7fd4:	0f 84 ae 03 00 00    	je     0x5b8388
  5b7fda:	8b 01                	mov    eax,DWORD PTR [ecx]
  5b7fdc:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  5b7fe2:	ff d2                	call   edx
  5b7fe4:	5f                   	pop    edi
  5b7fe5:	5e                   	pop    esi
  5b7fe6:	5b                   	pop    ebx
  5b7fe7:	8b e5                	mov    esp,ebp
  5b7fe9:	5d                   	pop    ebp
  5b7fea:	c2 04 00             	ret    0x4
  5b7fed:	8b ce                	mov    ecx,esi
  5b7fef:	8b d3                	mov    edx,ebx
  5b7ff1:	e8 ea eb ff ff       	call   0x5b6be0
  5b7ff6:	5f                   	pop    edi
  5b7ff7:	5e                   	pop    esi
  5b7ff8:	5b                   	pop    ebx
  5b7ff9:	8b e5                	mov    esp,ebp
  5b7ffb:	5d                   	pop    ebp
  5b7ffc:	c2 04 00             	ret    0x4
  5b7fff:	8b ce                	mov    ecx,esi
  5b8001:	8b d3                	mov    edx,ebx
  5b8003:	e8 18 ed ff ff       	call   0x5b6d20
  5b8008:	5f                   	pop    edi
  5b8009:	5e                   	pop    esi
  5b800a:	5b                   	pop    ebx
  5b800b:	8b e5                	mov    esp,ebp
  5b800d:	5d                   	pop    ebp
  5b800e:	c2 04 00             	ret    0x4
```

### S11 — recipient selector 0x423470 calls common dispatch; VA `0x00423470..0x004234bd`; raw `0x22870..0x228bd`; 77 bytes; SHA256 `1c759016cdc9c1115c0486c62949e7105f67f8acc97c291751f90853fe3c2e5d`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00423470 <.data+0x22870>:
  423470:	55                   	push   ebp
  423471:	8b ec                	mov    ebp,esp
  423473:	56                   	push   esi
  423474:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  423477:	57                   	push   edi
  423478:	56                   	push   esi
  423479:	8b f9                	mov    edi,ecx
  42347b:	e8 00 4b 19 00       	call   0x5b7f80
  423480:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  423483:	2d 9e 43 0f 00       	sub    eax,0xf439e
  423488:	74 27                	je     0x4234b1
  42348a:	83 e8 66             	sub    eax,0x66
  42348d:	74 10                	je     0x42349f
  42348f:	83 e8 3d             	sub    eax,0x3d
  423492:	75 22                	jne    0x4234b6
  423494:	e8 47 02 00 00       	call   0x4236e0
  423499:	5f                   	pop    edi
  42349a:	5e                   	pop    esi
  42349b:	5d                   	pop    ebp
  42349c:	c2 04 00             	ret    0x4
  42349f:	8b 87 fc 02 00 00    	mov    eax,DWORD PTR [edi+0x2fc]
  4234a5:	50                   	push   eax
  4234a6:	e8 95 fa 28 00       	call   0x6b2f40
  4234ab:	5f                   	pop    edi
  4234ac:	5e                   	pop    esi
  4234ad:	5d                   	pop    ebp
  4234ae:	c2 04 00             	ret    0x4
  4234b1:	e8 4a 01 00 00       	call   0x423600
  4234b6:	5f                   	pop    edi
  4234b7:	5e                   	pop    esi
  4234b8:	5d                   	pop    ebp
  4234b9:	c2 04 00             	ret    0x4
  4234bc:	cc                   	int3
```

### S12 — S2C mode2 handler event type and quest lookup; VA `0x005b6d20..0x005b6e55`; raw `0x1b6120..0x1b6255`; 309 bytes; SHA256 `bff7e1c4bc98f2415a5dee032688ea8fc43b60e36679d36fd0d121b2e1ac651e`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6d20 <.data+0x1b6120>:
  5b6d20:	55                   	push   ebp
  5b6d21:	8b ec                	mov    ebp,esp
  5b6d23:	83 e4 f8             	and    esp,0xfffffff8
  5b6d26:	6a ff                	push   0xffffffff
  5b6d28:	68 2c 93 94 00       	push   0x94932c
  5b6d2d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b6d33:	50                   	push   eax
  5b6d34:	83 ec 10             	sub    esp,0x10
  5b6d37:	53                   	push   ebx
  5b6d38:	56                   	push   esi
  5b6d39:	57                   	push   edi
  5b6d3a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b6d3f:	33 c4                	xor    eax,esp
  5b6d41:	50                   	push   eax
  5b6d42:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b6d46:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b6d4c:	8b f1                	mov    esi,ecx
  5b6d4e:	8b fa                	mov    edi,edx
  5b6d50:	85 f6                	test   esi,esi
  5b6d52:	74 26                	je     0x5b6d7a
  5b6d54:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6d56:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6d59:	ff d2                	call   edx
  5b6d5b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6d60:	75 04                	jne    0x5b6d66
  5b6d62:	8b de                	mov    ebx,esi
  5b6d64:	eb 16                	jmp    0x5b6d7c
  5b6d66:	6a 00                	push   0x0
  5b6d68:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6d6d:	68 18 21 bf 00       	push   0xbf2118
  5b6d72:	6a 00                	push   0x0
  5b6d74:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6d7a:	33 db                	xor    ebx,ebx
  5b6d7c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6d83:	75 29                	jne    0x5b6dae
  5b6d85:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6d8c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6d93:	00 
  5b6d94:	e8 c7 90 f4 ff       	call   0x4ffe60
  5b6d99:	68 00 cf bc 00       	push   0xbccf00
  5b6d9e:	e8 77 b5 2d 00       	call   0x89231a
  5b6da3:	83 c4 04             	add    esp,0x4
  5b6da6:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6dad:	ff 
  5b6dae:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6db1:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6db7:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6dbb:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6dbf:	51                   	push   ecx
  5b6dc0:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6dc4:	8b ce                	mov    ecx,esi
  5b6dc6:	e8 55 cf f4 ff       	call   0x503d20
  5b6dcb:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6dce:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6dd2:	3b c6                	cmp    eax,esi
  5b6dd4:	74 6c                	je     0x5b6e42
  5b6dd6:	8d 70 10             	lea    esi,[eax+0x10]
  5b6dd9:	85 f6                	test   esi,esi
  5b6ddb:	74 65                	je     0x5b6e42
  5b6ddd:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6de4:	75 29                	jne    0x5b6e0f
  5b6de6:	b8 01 00 00 00       	mov    eax,0x1
  5b6deb:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6df1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6df5:	e8 96 7e f2 ff       	call   0x4dec90
  5b6dfa:	68 30 ce bc 00       	push   0xbcce30
  5b6dff:	e8 16 b5 2d 00       	call   0x89231a
  5b6e04:	83 c4 04             	add    esp,0x4
  5b6e07:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6e0e:	ff 
  5b6e0f:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6e12:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6e17:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6e1a:	52                   	push   edx
  5b6e1b:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e21:	6a 02                	push   0x2
  5b6e23:	50                   	push   eax
  5b6e24:	e8 f7 f6 07 00       	call   0x636520
  5b6e29:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6e2f:	51                   	push   ecx
  5b6e30:	e8 db 31 19 00       	call   0x74a010
  5b6e35:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e3b:	52                   	push   edx
  5b6e3c:	57                   	push   edi
  5b6e3d:	e8 be ff fd ff       	call   0x596e00
  5b6e42:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6e46:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6e4d:	59                   	pop    ecx
  5b6e4e:	5f                   	pop    edi
  5b6e4f:	5e                   	pop    esi
  5b6e50:	5b                   	pop    ebx
  5b6e51:	8b e5                	mov    esp,ebp
  5b6e53:	5d                   	pop    ebp
  5b6e54:	c3                   	ret
```

### S13 — TalkBox mode2 stores original QID and giver from record; VA `0x00636520..0x00636631`; raw `0x235920..0x235a31`; 273 bytes; SHA256 `0a83d73577c696c589f09a33cae5e0208d29c36069869fc6f60c810224f90180`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636520 <.data+0x235920>:
  636520:	55                   	push   ebp
  636521:	8b ec                	mov    ebp,esp
  636523:	83 e4 f8             	and    esp,0xfffffff8
  636526:	6a ff                	push   0xffffffff
  636528:	68 32 92 94 00       	push   0x949232
  63652d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  636533:	50                   	push   eax
  636534:	83 ec 28             	sub    esp,0x28
  636537:	53                   	push   ebx
  636538:	56                   	push   esi
  636539:	57                   	push   edi
  63653a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  63653f:	33 c4                	xor    eax,esp
  636541:	50                   	push   eax
  636542:	8d 44 24 38          	lea    eax,[esp+0x38]
  636546:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  63654c:	8b f1                	mov    esi,ecx
  63654e:	8b fa                	mov    edi,edx
  636550:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  636553:	8b 1d d0 1b fe 00    	mov    ebx,DWORD PTR ds:0xfe1bd0
  636559:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  63655d:	89 87 80 00 00 00    	mov    DWORD PTR [edi+0x80],eax
  636563:	51                   	push   ecx
  636564:	8d 4b 08             	lea    ecx,[ebx+0x8]
  636567:	8d 44 24 18          	lea    eax,[esp+0x18]
  63656b:	89 b7 84 00 00 00    	mov    DWORD PTR [edi+0x84],esi
  636571:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  636575:	e8 46 d3 20 00       	call   0x8438c0
  63657a:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  63657d:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  636581:	33 db                	xor    ebx,ebx
  636583:	3b c8                	cmp    ecx,eax
  636585:	74 05                	je     0x63658c
  636587:	8b 49 10             	mov    ecx,DWORD PTR [ecx+0x10]
  63658a:	eb 02                	jmp    0x63658e
  63658c:	33 c9                	xor    ecx,ecx
  63658e:	8b 87 bc 00 00 00    	mov    eax,DWORD PTR [edi+0xbc]
  636594:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  636597:	56                   	push   esi
  636598:	50                   	push   eax
  636599:	89 8f b8 00 00 00    	mov    DWORD PTR [edi+0xb8],ecx
  63659f:	89 97 90 00 00 00    	mov    DWORD PTR [edi+0x90],edx
  6365a5:	89 9f 88 00 00 00    	mov    DWORD PTR [edi+0x88],ebx
  6365ab:	e8 30 24 00 00       	call   0x6389e0
  6365b0:	6a 24                	push   0x24
  6365b2:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  6365b6:	e8 ad ac 25 00       	call   0x891268
  6365bb:	83 c4 04             	add    esp,0x4
  6365be:	3b c3                	cmp    eax,ebx
  6365c0:	0f 84 85 01 00 00    	je     0x63674b
  6365c6:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6365ca:	89 00                	mov    DWORD PTR [eax],eax
  6365cc:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  6365d3:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d7:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  6365da:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  6365de:	c6 41 20 01          	mov    BYTE PTR [ecx+0x20],0x1
  6365e2:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  6365e6:	c6 42 21 01          	mov    BYTE PTR [edx+0x21],0x1
  6365ea:	53                   	push   ebx
  6365eb:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  6365ef:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  6365f5:	8b 97 80 00 00 00    	mov    edx,DWORD PTR [edi+0x80]
  6365fb:	8d 44 24 28          	lea    eax,[esp+0x28]
  6365ff:	50                   	push   eax
  636600:	a1 b4 1d fe 00       	mov    eax,ds:0xfe1db4
  636605:	51                   	push   ecx
  636606:	52                   	push   edx
  636607:	50                   	push   eax
  636608:	e8 43 5c ec ff       	call   0x4fc250
  63660d:	39 5c 24 2c          	cmp    DWORD PTR [esp+0x2c],ebx
  636611:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636617:	0f 95 c1             	setne  cl
  63661a:	88 8f 8c 00 00 00    	mov    BYTE PTR [edi+0x8c],cl
  636620:	83 f8 03             	cmp    eax,0x3
  636623:	0f 87 e3 00 00 00    	ja     0x63670c
  636629:	ff 24 85 74 67 63 00 	jmp    DWORD PTR [eax*4+0x636774]
  636630:	8b         	mov    ecx,DWORD PTR [edi+0xbc]
```

### S14 — TalkBox mode2 renders selected QuestInfo and advances; VA `0x00636687..0x00636714`; raw `0x235a87..0x235b14`; 141 bytes; SHA256 `12914fa322b44615222cfc0fa0f5ca605fb529c096ce6860f1b8e812b2a2aa22`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636687 <.data+0x235a87>:
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  6366b0:	51                   	push   ecx
  6366b1:	8b c7                	mov    eax,edi
  6366b3:	e8 58 f8 ff ff       	call   0x635f10
  6366b8:	eb 3f                	jmp    0x6366f9
  6366ba:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366c0:	8b 11                	mov    edx,DWORD PTR [ecx]
  6366c2:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  6366c5:	ff d0                	call   eax
  6366c7:	e8 64 92 dd ff       	call   0x40f930
  6366cc:	8b c8                	mov    ecx,eax
  6366ce:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  6366d1:	e8 ba a8 ec ff       	call   0x500f90
  6366d6:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366dc:	3b c3                	cmp    eax,ebx
  6366de:	74 0d                	je     0x6366ed
  6366e0:	8b 48 38             	mov    ecx,DWORD PTR [eax+0x38]
  6366e3:	51                   	push   ecx
  6366e4:	8b c7                	mov    eax,edi
  6366e6:	e8 25 f8 ff ff       	call   0x635f10
  6366eb:	eb 0c                	jmp    0x6366f9
  6366ed:	8b 17                	mov    edx,DWORD PTR [edi]
  6366ef:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  6366f5:	8b cf                	mov    ecx,edi
  6366f7:	ff d0                	call   eax
  6366f9:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366ff:	8b 11                	mov    edx,DWORD PTR [ecx]
  636701:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636704:	ff d0                	call   eax
  636706:	57                   	push   edi
  636707:	e8 44 f9 ff ff       	call   0x636050
  63670c:	c7 44 24 40 01 00 00 	mov    DWORD PTR [esp+0x40],0x1
  636713:	00
```

### S15 — TalkBox object constructor owns UI widget alias; VA `0x006359d0..0x00635a47`; raw `0x234dd0..0x234e47`; 119 bytes; SHA256 `0d8583ffca0c9f9878de672b0e72a7495e705594b960ba0659e0ffa647bd5187`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006359d0 <.data+0x234dd0>:
  6359d0:	68 80 01 00 00       	push   0x180
  6359d5:	66 89 9e b4 00 00 00 	mov    WORD PTR [esi+0xb4],bx
  6359dc:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  6359e2:	e8 81 b8 25 00       	call   0x891268
  6359e7:	83 c4 04             	add    esp,0x4
  6359ea:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  6359ed:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  6359f1:	3b c3                	cmp    eax,ebx
  6359f3:	74 08                	je     0x6359fd
  6359f5:	50                   	push   eax
  6359f6:	e8 c5 16 00 00       	call   0x6370c0
  6359fb:	eb 02                	jmp    0x6359ff
  6359fd:	33 c0                	xor    eax,eax
  6359ff:	89 86 bc 00 00 00    	mov    DWORD PTR [esi+0xbc],eax
  635a05:	89 9e c0 00 00 00    	mov    DWORD PTR [esi+0xc0],ebx
  635a0b:	89 9e c4 00 00 00    	mov    DWORD PTR [esi+0xc4],ebx
  635a11:	89 9e c8 00 00 00    	mov    DWORD PTR [esi+0xc8],ebx
  635a17:	89 9e cc 00 00 00    	mov    DWORD PTR [esi+0xcc],ebx
  635a1d:	89 9e d0 00 00 00    	mov    DWORD PTR [esi+0xd0],ebx
  635a23:	89 9e d4 00 00 00    	mov    DWORD PTR [esi+0xd4],ebx
  635a29:	89 9e d8 00 00 00    	mov    DWORD PTR [esi+0xd8],ebx
  635a2f:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  635a32:	8b c6                	mov    eax,esi
  635a34:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  635a37:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  635a3e:	59                   	pop    ecx
  635a3f:	5f                   	pop    edi
  635a40:	5e                   	pop    esi
  635a41:	5b                   	pop    ebx
  635a42:	8b e5                	mov    esp,ebp
  635a44:	5d                   	pop    ebp
  635a45:	c2 04              	ret    0x4
```

### S16 — UI parent callback emits different action, not QID; VA `0x006391c0..0x0063920e`; raw `0x2385c0..0x23860e`; 78 bytes; SHA256 `ea50707b9e7855ba4e7b29ac3e443965f63b6ac10eda7cd75341b7e2c5a69bec`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006391c0 <.data+0x2385c0>:
  6391c0:	56                   	push   esi
  6391c1:	6a 18                	push   0x18
  6391c3:	8b f1                	mov    esi,ecx
  6391c5:	e8 9e 80 25 00       	call   0x891268
  6391ca:	83 c4 04             	add    esp,0x4
  6391cd:	85 c0                	test   eax,eax
  6391cf:	74 32                	je     0x639203
  6391d1:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  6391d4:	8b 89 84 00 00 00    	mov    ecx,DWORD PTR [ecx+0x84]
  6391da:	83 ca ff             	or     edx,0xffffffff
  6391dd:	8b f0                	mov    esi,eax
  6391df:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  6391e2:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  6391e5:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  6391ec:	c7 40 10 ec 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf42ec
  6391f3:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  6391f9:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  6391fc:	e8 9f e0 dc ff       	call   0x4072a0
  639201:	5e                   	pop    esi
  639202:	c3                   	ret
  639203:	33 c0                	xor    eax,eax
  639205:	8b f0                	mov    esi,eax
  639207:	e8 94 e0 dc ff       	call   0x4072a0
  63920c:	5e                   	pop    esi
  63920d:	c3                   	ret
```

### S17 — TalkBox internal F438A event producer 0x5007D0 type1; VA `0x00636c84..0x00636d1a`; raw `0x236084..0x23611a`; 150 bytes; SHA256 `c25587d928ffe667c0aaeaa0788970d0731d63b60251d644404e4153cff4b3fd`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636c84 <.data+0x236084>:
  636c84:	83 f8 03             	cmp    eax,0x3
  636c87:	75 71                	jne    0x636cfa
  636c89:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  636c8f:	3b c3                	cmp    eax,ebx
  636c91:	74 67                	je     0x636cfa
  636c93:	8b 10                	mov    edx,DWORD PTR [eax]
  636c95:	52                   	push   edx
  636c96:	51                   	push   ecx
  636c97:	e8 94 8c dd ff       	call   0x40f930
  636c9c:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  636ca2:	83 c4 04             	add    esp,0x4
  636ca5:	8b d0                	mov    edx,eax
  636ca7:	e8 24 9b ec ff       	call   0x5007d0
  636cac:	0f b7 f0             	movzx  esi,ax
  636caf:	85 f6                	test   esi,esi
  636cb1:	74 47                	je     0x636cfa
  636cb3:	6a 18                	push   0x18
  636cb5:	e8 ae a5 25 00       	call   0x891268
  636cba:	83 c4 04             	add    esp,0x4
  636cbd:	85 c0                	test   eax,eax
  636cbf:	74 1e                	je     0x636cdf
  636cc1:	83 c9 ff             	or     ecx,0xffffffff
  636cc4:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636cc7:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636cca:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636ccd:	c7 40 10 8a 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438a
  636cd4:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  636cda:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  636cdd:	eb 02                	jmp    0x636ce1
  636cdf:	33 c0                	xor    eax,eax
  636ce1:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  636ce5:	e8 b6 dd dc ff       	call   0x404aa0
  636cea:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  636cee:	51                   	push   ecx
  636cef:	8d b0 5c 14 00 00    	lea    esi,[eax+0x145c]
  636cf5:	e8 66 d5 1c 00       	call   0x804260
  636cfa:	8b 8c 24 88 00 00 00 	mov    ecx,DWORD PTR [esp+0x88]
  636d01:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  636d08:	59                   	pop    ecx
  636d09:	5e                   	pop    esi
  636d0a:	5b                   	pop    ebx
  636d0b:	8b 4c 24 74          	mov    ecx,DWORD PTR [esp+0x74]
  636d0f:	33 cc                	xor    ecx,esp
  636d11:	e8 eb a2 25 00       	call   0x891001
  636d16:	8b e5                	mov    esp,ebp
  636d18:	5d                   	pop    ebp
  636d19:	c3                   	ret
```

### S18 — type1-only query 0x5007D0 to 0x500950; VA `0x005007d0..0x00500886`; raw `0xffbd0..0xffc86`; 182 bytes; SHA256 `6f93b7ab0d019b3bff0dfbdf9c8559e74cdb39f3dd7079f78ab9993f64308be0`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005007d0 <.data+0xffbd0>:
  5007d0:	55                   	push   ebp
  5007d1:	8b ec                	mov    ebp,esp
  5007d3:	83 e4 f8             	and    esp,0xfffffff8
  5007d6:	6a ff                	push   0xffffffff
  5007d8:	68 08 6a 90 00       	push   0x906a08
  5007dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5007e3:	50                   	push   eax
  5007e4:	83 ec 18             	sub    esp,0x18
  5007e7:	53                   	push   ebx
  5007e8:	56                   	push   esi
  5007e9:	57                   	push   edi
  5007ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5007ef:	33 c4                	xor    eax,esp
  5007f1:	50                   	push   eax
  5007f2:	8d 44 24 28          	lea    eax,[esp+0x28]
  5007f6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5007fc:	33 f6                	xor    esi,esi
  5007fe:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  500802:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  500806:	89 74 24 1c          	mov    DWORD PTR [esp+0x1c],esi
  50080a:	8d 44 24 14          	lea    eax,[esp+0x14]
  50080e:	50                   	push   eax
  50080f:	51                   	push   ecx
  500810:	52                   	push   edx
  500811:	89 74 24 3c          	mov    DWORD PTR [esp+0x3c],esi
  500815:	e8 36 01 00 00       	call   0x500950
  50081a:	8b 7c 24 18          	mov    edi,DWORD PTR [esp+0x18]
  50081e:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  500822:	2b fb                	sub    edi,ebx
  500824:	c1 ff 02             	sar    edi,0x2
  500827:	85 ff                	test   edi,edi
  500829:	74 32                	je     0x50085d
  50082b:	eb 03                	jmp    0x500830
  50082d:	8d 49 00             	lea    ecx,[ecx+0x0]
  500830:	8b 14 b3             	mov    edx,DWORD PTR [ebx+esi*4]
  500833:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  500836:	2b 42 10             	sub    eax,DWORD PTR [edx+0x10]
  500839:	33 c9                	xor    ecx,ecx
  50083b:	c1 f8 02             	sar    eax,0x2
  50083e:	85 c0                	test   eax,eax
  500840:	74 16                	je     0x500858
  500842:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  500845:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  500848:	39 1a                	cmp    DWORD PTR [edx],ebx
  50084a:	74 35                	je     0x500881
  50084c:	41                   	inc    ecx
  50084d:	83 c2 04             	add    edx,0x4
  500850:	3b c8                	cmp    ecx,eax
  500852:	72 f1                	jb     0x500845
  500854:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  500858:	46                   	inc    esi
  500859:	3b f7                	cmp    esi,edi
  50085b:	72 d3                	jb     0x500830
  50085d:	85 db                	test   ebx,ebx
  50085f:	74 09                	je     0x50086a
  500861:	53                   	push   ebx
  500862:	e8 a5 09 39 00       	call   0x89120c
  500867:	83 c4 04             	add    esp,0x4
  50086a:	33 c0                	xor    eax,eax
  50086c:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  500870:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  500877:	59                   	pop    ecx
  500878:	5f                   	pop    edi
  500879:	5e                   	pop    esi
  50087a:	5b                   	pop    ebx
  50087b:	8b e5                	mov    esp,ebp
  50087d:	5d                   	pop    ebp
  50087e:	c2 04 00             	ret    0x4
  500881:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  500885:	8b               	mov    ecx,DWORD PTR [eax+esi*4]
```

### S19 — quest list selected event F438A uses its own record; VA `0x0062ef7e..0x0062f044`; raw `0x22e37e..0x22e444`; 198 bytes; SHA256 `f3c9645b9fdf8dba160a1984ed5fcad71332a36deca2e430e2b0d9ffbbaf6b7f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0062ef7e <.data+0x22e37e>:
  62ef7e:	8b 96 18 01 00 00    	mov    edx,DWORD PTR [esi+0x118]
  62ef84:	2b 96 14 01 00 00    	sub    edx,DWORD PTR [esi+0x114]
  62ef8a:	c1 fa 02             	sar    edx,0x2
  62ef8d:	3b fa                	cmp    edi,edx
  62ef8f:	0f 83 8c 00 00 00    	jae    0x62f021
  62ef95:	6a 18                	push   0x18
  62ef97:	e8 cc 22 26 00       	call   0x891268
  62ef9c:	83 c4 04             	add    esp,0x4
  62ef9f:	85 c0                	test   eax,eax
  62efa1:	74 32                	je     0x62efd5
  62efa3:	8b 8e 14 01 00 00    	mov    ecx,DWORD PTR [esi+0x114]
  62efa9:	8b 14 b9             	mov    edx,DWORD PTR [ecx+edi*4]
  62efac:	8d 0c b9             	lea    ecx,[ecx+edi*4]
  62efaf:	8b 0a                	mov    ecx,DWORD PTR [edx]
  62efb1:	83 cf ff             	or     edi,0xffffffff
  62efb4:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  62efb7:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  62efba:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  62efc1:	c7 40 10 8a 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438a
  62efc8:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  62efce:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  62efd1:	8b f0                	mov    esi,eax
  62efd3:	eb 05                	jmp    0x62efda
  62efd5:	33 f6                	xor    esi,esi
  62efd7:	83 cf ff             	or     edi,0xffffffff
  62efda:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  62efe1:	75 2b                	jne    0x62f00e
  62efe3:	83 0d d0 ad fa 00 01 	or     DWORD PTR ds:0xfaadd0,0x1
  62efea:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0x6
  62eff1:	06 00 00 00 
  62eff5:	e8 96 e9 11 00       	call   0x74d990
  62effa:	68 70 cc bc 00       	push   0xbccc70
  62efff:	e8 16 33 26 00       	call   0x89231a
  62f004:	83 c4 04             	add    esp,0x4
  62f007:	89 bc 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],edi
  62f00e:	8d 44 24 0c          	lea    eax,[esp+0xc]
  62f012:	89 74 24 0c          	mov    DWORD PTR [esp+0xc],esi
  62f016:	50                   	push   eax
  62f017:	be 6c 5c f9 00       	mov    esi,0xf95c6c
  62f01c:	e8 3f 52 1d 00       	call   0x804260
  62f021:	8b 8c 24 a8 00 00 00 	mov    ecx,DWORD PTR [esp+0xa8]
  62f028:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  62f02f:	59                   	pop    ecx
  62f030:	5f                   	pop    edi
  62f031:	5e                   	pop    esi
  62f032:	8b 8c 24 94 00 00 00 	mov    ecx,DWORD PTR [esp+0x94]
  62f039:	33 cc                	xor    ecx,esp
  62f03b:	e8 c1 1f 26 00       	call   0x891001
  62f040:	8b e5                	mov    esp,ebp
  62f042:	5d                   	pop    ebp
  62f043:	c3                   	ret
```

### S20 — event jump table case for F438A vs F438B; VA `0x005b7fed..0x005b8011`; raw `0x1b73ed..0x1b7411`; 36 bytes; SHA256 `0d631d79f728ee2248354ce69ccba24056b5a64e2d013ad194d9d7da6fdf3503`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b7fed <.data+0x1b73ed>:
  5b7fed:	8b ce                	mov    ecx,esi
  5b7fef:	8b d3                	mov    edx,ebx
  5b7ff1:	e8 ea eb ff ff       	call   0x5b6be0
  5b7ff6:	5f                   	pop    edi
  5b7ff7:	5e                   	pop    esi
  5b7ff8:	5b                   	pop    ebx
  5b7ff9:	8b e5                	mov    esp,ebp
  5b7ffb:	5d                   	pop    ebp
  5b7ffc:	c2 04 00             	ret    0x4
  5b7fff:	8b ce                	mov    ecx,esi
  5b8001:	8b d3                	mov    edx,ebx
  5b8003:	e8 18 ed ff ff       	call   0x5b6d20
  5b8008:	5f                   	pop    edi
  5b8009:	5e                   	pop    esi
  5b800a:	5b                   	pop    ebx
  5b800b:	8b e5                	mov    esp,ebp
  5b800d:	5d                   	pop    ebp
  5b800e:	c2 04 00             	ret    0x4
```

### S21 — mode1 on F438A, control case; VA `0x005b6c6e..0x005b6d02`; raw `0x1b606e..0x1b6102`; 148 bytes; SHA256 `f28f3da2f749e7e5b9258047a4d7c039aa8374b73e300193488af105578ed58e`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6c6e <.data+0x1b606e>:
  5b6c6e:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6c71:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6c77:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6c7b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6c7f:	51                   	push   ecx
  5b6c80:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6c84:	8b ce                	mov    ecx,esi
  5b6c86:	e8 95 d0 f4 ff       	call   0x503d20
  5b6c8b:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6c8e:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6c92:	3b c6                	cmp    eax,esi
  5b6c94:	74 6c                	je     0x5b6d02
  5b6c96:	8d 70 10             	lea    esi,[eax+0x10]
  5b6c99:	85 f6                	test   esi,esi
  5b6c9b:	74 65                	je     0x5b6d02
  5b6c9d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6ca4:	75 29                	jne    0x5b6ccf
  5b6ca6:	b8 01 00 00 00       	mov    eax,0x1
  5b6cab:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6cb1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6cb5:	e8 d6 7f f2 ff       	call   0x4dec90
  5b6cba:	68 30 ce bc 00       	push   0xbcce30
  5b6cbf:	e8 56 b6 2d 00       	call   0x89231a
  5b6cc4:	83 c4 04             	add    esp,0x4
  5b6cc7:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6cce:	ff 
  5b6ccf:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6cd2:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6cd7:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6cda:	52                   	push   edx
  5b6cdb:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6ce1:	6a 01                	push   0x1
  5b6ce3:	50                   	push   eax
  5b6ce4:	e8 37 f8 07 00       	call   0x636520
  5b6ce9:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6cef:	51                   	push   ecx
  5b6cf0:	e8 1b 33 19 00       	call   0x74a010
  5b6cf5:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6cfb:	52                   	push   edx
  5b6cfc:	57                   	push   edi
  5b6cfd:	e8 fe 00 fe ff       	call   0x596e00
```

### S22 — local quest-list UI population gating (type1); VA `0x0062f6d5..0x0062f75a`; raw `0x22ead5..0x22eb5a`; 133 bytes; SHA256 `c05a949940b76ac059fd2a6b90cf1f52833c4deab1b704c4f0546a7d0f633b00`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0062f6d5 <.data+0x22ead5>:
  62f6d5:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  62f6d8:	85 f6                	test   esi,esi
  62f6da:	74 6e                	je     0x62f74a
  62f6dc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62f6e3:	75 22                	jne    0x62f707
  62f6e5:	09 3d 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,edi
  62f6eb:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  62f6ee:	e8 6d 07 ed ff       	call   0x4ffe60
  62f6f3:	68 00 cf bc 00       	push   0xbccf00
  62f6f8:	e8 1d 2c 26 00       	call   0x89231a
  62f6fd:	83 c4 04             	add    esp,0x4
  62f700:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  62f707:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  62f70a:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  62f710:	8d 45 f0             	lea    eax,[ebp-0x10]
  62f713:	50                   	push   eax
  62f714:	8d 45 ec             	lea    eax,[ebp-0x14]
  62f717:	8b ce                	mov    ecx,esi
  62f719:	e8 02 46 ed ff       	call   0x503d20
  62f71e:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  62f721:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  62f724:	74 05                	je     0x62f72b
  62f726:	83 c0 10             	add    eax,0x10
  62f729:	eb 02                	jmp    0x62f72d
  62f72b:	33 c0                	xor    eax,eax
  62f72d:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  62f730:	85 c0                	test   eax,eax
  62f732:	74 16                	je     0x62f74a
  62f734:	39 78 04             	cmp    DWORD PTR [eax+0x4],edi
  62f737:	75 11                	jne    0x62f74a
  62f739:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  62f73c:	8d 45 f0             	lea    eax,[ebp-0x10]
  62f73f:	81 c7 14 01 00 00    	add    edi,0x114
  62f745:	e8 c6 45 e1 ff       	call   0x443d10
  62f74a:	83 c3 02             	add    ebx,0x2
  62f74d:	81 fb 98 11 fb 00    	cmp    ebx,0xfb1198
  62f753:	0f 8c 48 ff ff ff    	jl     0x62f6a1
  62f759:	8b               	mov    ecx,DWORD PTR [ebp+0x8]
```

## 7. 下輪精確入口與上 Git 注意事項

- 下一段正式研究建議 **T16-122／Quest16-③**：從 mode2 UI 玩家 confirm 的 0x0036 builder 與 `0x003F` controller/`0x001C` event 重建逐條 C→S sender chain，明確區分選取／交付、封包 gate，跨 T02 協定 framing 調查。
- Quest16-④ 單獨檢查 S2C `0x40` nonzero branch `0x5026CA`、`0x74` prereq state、拒絕/成功效果與是否有合法 ACK 配對；**絕不以本段自創 0x3F→0x40 自動回覆規則**。
- 需 Commit／Push 的待提交自身原稿：**T16-120**（誠實保留研究當時尚未完成狀態與錯誤假說，不能事後竄改）以及本 **T16-121**（標出本次更正與本次有界結案）。已在 GitHub 的 T16-118/119 不覆寫。僅推 `t16/roy/chatgpt-web`，提交後讀回 SHA/content；不 Merge main。
- 此報告屬原生靜態研究，**不是 T01 FULL-PASS、S00 SPEC STABLE、官方 Server 內部還原或實際可玩驗收**。
