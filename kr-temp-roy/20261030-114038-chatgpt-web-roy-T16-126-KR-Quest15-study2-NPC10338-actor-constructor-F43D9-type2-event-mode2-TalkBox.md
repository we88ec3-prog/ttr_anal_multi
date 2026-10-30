# T16-126 — Quest15／②：NPC10338 actor 物件建構、F43D9 事件產生／路由、type2 first-match 與 mode 2 TalkBox（KR BIN-first）

- 作者：`chatgpt-web roy`；正式段號 **T16-126**；產出：2026-10-30T11:40:38+08:00。
- 任務：Quest15 5 個子研究中的 **② NPC／玩家互動事件／選取 UI**，承接 T16-125 ①；不將 ③C→S、④S→C 獨立狀態矩陣、⑤場景轉場/後續任務誤報為已完成。
- 研究結論：**Client 原生、條件式、限定範圍的靜態功能鏈已完成**（object ctor → event producer → action router → type2 filter/first result → controller；S2C callback mode2 TalkBox 作獨立可證後端）。但 **Lua CreateObject10338 → 特定 live actor instance → 真的按下滑鼠 → 原版 Server 0x40** 的單一 runtime trace 不在靜態原件中直接證明。
- KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（12472320 bytes）；Event.stp SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`（11241597 bytes），兩者唯讀。
- PE 映射：`.text` RAW `VA−0x400C00`；以下 assembly 全部以此換算，直接重新在 SHA-confirmed BIN 取 bytes，用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`；沒有執行原版程式。
- 遠端基準（本次開始）：`main` 最新 SHA `3724d850231ef26b2a36984ac1c5bc3347c4d96d`，T16 ahead13/behind36，後續主線可能持續移動；**同一對話先前 PR#26 已做一次性 main→T16 同步，本次不得重做**。
- 開工 `research/dispatch/inbox/T16.md` 與唯一 RR 台帳沒有 T16 指派；`shared/verified-knowledge/README.md` 只有先前 7 個有限 FULL-PASS 條目，本篇未自動提升。
- **T01 優先退回** `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` 此時仍 `NEEDS_FIX`：117 的「mode1..3 都 F4402→0x36/QID」和 `TalkBox+0x88=QuestID` 不正確；本次用 121/122 的反證，不重用舊肯定主張。因當次使用者明確要求 Quest15-②，未在本報修改 T01 README 或完成舊稿正式 erratum；須另案依固定 ID 修正。

## 1. 客戶端子研究完成條件及主張級別

| 問題 | 原生證據/結果 | 適用邊界 |
|---|---|---|
| Quest15 Scene 是否確實引用 giver NPC10338？ | Event.stp Scene1/2 XOR-FF 直接看見 `CreateObject(...,10338,...)` | 資源腳本參考，不是 runtime actor 出生 trace |
| 物件的 NPC ID 與類型從哪裡來？ | `0x543700` ctor `[instance+F4]=WORD kind`，`[instance+F6]=WORD id`；`0x4B2BD5` 具體 caller 從源記錄傳 WORD id/BYTE kind | 第二個 native ctor caller `0x4A914B` 固定 kind4，反例說明不能把所有物件當 NPC kind3 |
| 類型3物件如何發出任務互動？ | vtable `0xC0F7FC +0x64` 指 `0x544070`；kind3 經 `0x500A80` 結果與世界 mode gate，`0x5442CC` 創建 action F43D9，type105BF，selector=instance+F6 | 是**可執行條件式**互動分支，不保證 Lua 所建物件或玩家點擊必經 |
| 事件如何派到 Quest selector？ | `0x5B7F80` jump table action `F43D9` 對應 `0x5B8167`→`0x5B9340`；後者核對 outer 105BD/action6A7、nested105BF，取 nested+14 selector | 外層 wrapper 105BD/6A7 來源需視事件設備注入，不能因內層產生就假設所有 gate 必過 |
| NPC10338 怎樣得到 QuestID15？ | `0x5008B0→0x500A00` 在 candidate WORD vector 查 QuestRecord `giver+0x28==10338 && type+0x04==2`，**只回第一個命中 ID** | 先有 key16、town5、等級/20槽等 gate 且 first result=15；未證全表 NPC10338 唯一任務 |
| Quest15 如何顯示 mode2 TalkBox？ | S2C index0x40 `(QID=15,state=0)` → action F438B → event router `0x5B7FFF` → `0x5B6D20` 查 QuestInfo15 → `0x636520(mode2)` | 它是**另一路入站條件鏈**；未證 S2C 0x40 是 NPC 點擊、C2S 0x3F 必然回覆 |
| 點擊即直接 C2S 0x36? | 否；type2 mode2 不可套用 T16-117 的 `F4402` 對話點擊 branch | 0x36 尚有其他 producer；不主張它永不出現 |

## 2. 新發現：Actor 記錄與 vtable 的來源閉合

### 2.1 `0x543700` ctor 確實帶有 ID 與 kind

`0x543745` 從 stack argument +0x10 讀 WORD id；`0x543749` 從 +0x0C 讀 WORD kind。`0x543755` 寫 `WORD [EBX+0xF6] = id`、`0x543778` 寫 `WORD [EBX+0xF4] = kind`；`0x543772` `mov DWORD [EBX],0xC0F7FC`。其虛擬表從 .rdata 原件 `0xC0F7FC` 起第 `0x64` slot 存 DWORD `0x544070`。這是**真正的結構／virtual target**，不是只靠字串類比。

`0x4B2BD5` 與 `0x4A914B` 是此 ctor 的兩個直接 call xrefs（依 `.text` E8 rel32 全掃）；前者從解析過的記錄 BYTE/WORD push ID/kind 等欄位，後者 `push 4` 明確產生不同種類物件。`CreateObject(...,10338...)` 的 Lua native binding 至哪個 caller、是否由 Scene1/2 或 server scene record 建立，**尚未用原生唯一映射直連**。

### 2.2 `0x544070` 的重要條件，不是任意互動都送任務

`0x54409E..` 先查 instance+F4 是否等於 **3**；否則走 `0x5443C0` 分支。kind3 時讀 instance+F6 (`0x544127`) 作 selector，呼叫 `0x500A80`；此查找回值 **不是5** 走另一個 `0x753F80` 場景事件分流；等於5 才續查世界/角色狀態 `owner+0x5F4C` 是否為 3、7、0x17、0x18；不符提前返回。接著依 `owner+0x5ED8` 及 `0x539A70` 返回值選擇 action `F43D6` 或 `F43D9`；只有後者是本次追的 type2 NPC 選取路徑。

`0x5442E5/0x5442EC` 讀 `WORD[instance+F6]` 和 `WORD[instance+F4]`；`0x544309` 設 `event+10=F43D9`，`0x544310` 設 event vtable `0xC47BE4`（其 vtable `+0x04` method `0x753B60` 回 `0x105BF`），`0x544316` 寫 `event+14=selector`，`0x544319/+0x54431C` 寫其他兩個 DWORD（來源 object+F4/F6，轉 signed）；經 `0x5854B0`/`0x5740F0`/`0x58B270` 等後續腳本/事件相關路徑。`0x58B270` 是廣義字串/呼叫轉接，**不能只靠 call 存在證明事件最終送至指定 listener**。

### 2.3 動態路由表的嚴格核對

`0x5B7F93` 取 `event+0x10`，`+0xFFF0BC9C` 等於減 `0xF4364`；`0x5B7FA6` 取 `BYTE[0x5B8460+index]`，`0x5B7FAE` 跳 `DWORD[0x5B8394+slot*4]`。原始表中 action `F43D9` → offset `0x75` → slot `30` → `0x5B8167`；`0x5B8169` 再呼叫 `0x5B9340`。這是本次新直接驗證的完整兩級 dispatch，不再只引用舊筆記對 `0x5B9340` 的標籤。

`0x5B9340` **仍需** outer `vtable +4 type==0x105BD`、outer+14 action==0x6A7、nested pointer outer+18 的 type==0x105BF；`nested+14` 才作 `0x5008B0` 的 selector，與 nested+18/+1C 作 `0x1C` application payload 的兩個 WORD。因此 actor ctor 的 key 必須一路在正確 nested message 中生效。`0x6A8` 是不同 CFG，場景/清單相依；不可將它與 `0x6A7` 等同。

## 3. Quest15 條件式完整鏈，與直接交付邊界

```text
資源側 Event.stp Scene1/2: CreateObject(..., 10338, ...)
    [resource reference; runtime CreateObject -> actor ctor mapping not yet uniquely proven]
actor source record contains (kind=3, id=10338)
    -> 0x4B2BD5 -> 0x543700 writes [actor+F4]=3, [actor+F6]=10338
    -> actor vtable [0xC0F7FC+0x64]=0x544070 (if invoked)
    -> type3, 0x500A80==5, state whitelist, owner+5ED8 gate
    -> 0x5442CC: event vtable 0xC47BE4 / type105BF / actionF43D9 / selector10338
    -> event delivery to 0x5B7F80 (specific wrapper/delivery still conditional)
    -> jump table F43D9 -> 0x5B8167 -> 0x5B9340
    -> outer105BD/action6A7/nested105BF
    -> 0x5008B0 / 0x500A00 scans candidates with giver10338,type2
    -> FIRST valid matching QuestID15 (if Q15 is first)
    -> 0x561760 controller candidate state, may later C2S 0x3F(15,1)

獨立 S2C/UI 條件鏈：
S2C app 0x40,WORD(QID)=15,DWORD(state)=0
    -> 0x502270 emits event F438B (type105B9, event+14=15)
    -> router 0x5B7F80 action F438B -> 0x5B7FFF -> 0x5B6D20
    -> QuestInfo id15 hit -> 0x636520(mode=2), TalkBox fields assigned
```

不能以箭頭圖宣稱 runtime 兩條鏈必然因果配對；前一事件是否已轉成 callback/Server 回應仍缺動態或更上游事件匯流排唯一證據。

## 4. 前置與 UI 正負測試矩陣

| 情境 | 前置及 event 條件 | 預期 Client 靜態結果 | 不可推論 |
|---|---|---|---|
| key16 缺、town5 有 | Q15 Demand16 gate 不過 | Q15 通常不入可選 candidate | NPC actor 可以存在但不能當成已解鎖 Q15 |
| key16 有、town0 | Q15 town5 gate 不過 | 不會因 key16 單獨選到 Q15 | 不等於 Server 未通關 |
| key16、town5、level、排除清單允許 | 重建候選後 Q15 in vector | 具備 type2 NPC10338 filter 必要條件 | 仍需其餘同 giver type2 的排序 |
| actor kind≠3 | 0x54409E | 不進 kind3 的 F43D9 路徑 | Lua CreateObject10338 不保證 kind3 |
| actor kind3 且 0x500A80!=5 | 0x544162/0x54416C | 走 0x753F80 的其他流程 | 不能標成 Quest15 事件 |
| actor kind3 / 0x500A80==5 / context whitelist | 0x54420A / 0x539A70 | 可建立 F43D9/type105BF selector；其他條件也可建立 F43D6 | 並非所有點擊都導向 F43D9 |
| outer event 105BD+6A7+inner105BF selector10338 | 0x5B9340+5008B0 | first-type2-match ID=15 時送控制器 | 除非完整候選順序已查證，不能保證 first=15 |
| outer action6A8 | 0x5B9498 | 從不同 map/scene cache 查找並派給 scene effect | 不走 6A7 的 NPC type2 lookup |
| S2C 0x40(15,0) 且 QuestInfo15 exists | 0x502270+5B6D20 | F438B → TalkBox mode2 | 不是肯定來自 C2S 0x3F；亦非 mode1 0x36 |
| S2C 0x40(15,1) | `0x502270` alternate branch | 不是同一個 mode2 流程 | 不可把 state 1 當作接受確認 |

## 5. 對 Server、其他 Task、真實遊玩的責任界線

**Client 待逆向（Quest15②外剩餘的進階 trace）**：Event.stp 的 `CreateObject` Lua native binding 與 `0x4B2BD5` actor construction 是否為同一子流程；`vtable+64` 的實際鼠標/碰撞回呼 origin；`0x5854B0/0x58B270` 經何種 event wrapper 登記到 `0x5B7F80` 的 `0x105BD/action6A7`；完整 type2 NPC10338 任務同 giver 全表排序；實際首次 Quest15 accept/turn-in UI feedback（屬 Quest15③/④）。這些不是本稿冒充已取得的原生證據。

**Server 待開發**：根據 Quest16 完成鍵與 town5 selector 決定 Q15 可用、處理 C2S `0x1C` NPC context 和條件式 `0x3F(15,1)`；選擇性送 S2C `0x40(15,0)` 給 Client 開 TalkBox；原版 Server 何時觸發這些為未知，不可用假定必然回覆填空。

**跨 Task 待整合**：T02 framing/dispatch/real I/O；T07 場景、SceneList與NPC actor；T08 實體建立與選取，T03/T04 登入初始化；T15 snapshot；T01 新退回與原生複驗。S00 只有 SPEC/ADR/GAP/TEST 整合權，不代表 Server 已實作。

**待遊玩驗證**：正式 Client 中 Square03D NPC10338 是否可見與可點；按下互動究竟觸發哪個 action；送出封包及原版/相容 Server 到達序列；Quest15 mode2 UI 真正開啟、可接受或拒絕、轉入 Pindos 村；尚未實測。

### 五個子研究狀態
| 子研究 | 本檔結論 |
|---|---|
| ① 資源／前置 | T16-125 有界完成 |
| **② NPC／TalkBox** | **T16-126 Client 靜態有界完成**，條件式 actor/event→type2 candidate ＋獨立 S2C mode2 UI consumer；上列 runtime 來源與完整事件匯流排因果配對未證 |
| ③ C→S | 下一步（T16-127 候選）；完整 actor callback→0x1C/0x3F dispatch/queue/fail cases |
| ④ S→C、任務狀態／UI | 尚未專段完成，部分 0x40/0x74 可復用 Quest16 研究 |
| ⑤ 走向 Pin(d)os／村莊後續 | 尚未完成 |

## 6. Quest15 Scene1~4：直接原件表（不是 NPC actor runtime trace）

| Scene | decoded offset | SHA256 of extracted function body (UTF-8) | 主要第一手內容 |
|---|---|---|---|
| 1 | `0x96943E` | `5cbd5cba8bda6244f260a16a481f37d888addfb44a38a9981ba4f7dd024042fc` | CreateObject(..,10338,..)/ Square03D.fld |
| 2 | `0x96883E` | `216daaf33c478ba276c1a19ebd2b21ce491ee6ead47d0fcaf4ae5930e60acfce` | CreateObject(..,10338,..)/ Square03D.fld |
| 3 | `0x8C1C3E` | `c1b4f04c08a645b48e337de503819c7a92c99a885a9ec7f17ecb2bbc974ae639` | CreateObject(..,10047,..) / town001D.map |
| 4 | `0x96903E` | `0a29b24c36fdf3ca58be503da25cad742501bc816565797da822a87a8a6ac33f` | Scenario callback |

> 注意：此表的 SHA 是在上方界定的**函式文字**上計算，和 T16-125 以固定原始 raw 範圍計算的 hash 不可互換。此表只是同原件獨立重讀。

## 7. 原始 jump table bytes：一次性索引正反確認

| action | raw index | byte slot | native dispatch target |
|---|---:|---:|---|
| `0xf438a` | `0x26` | `11` | `0x5b7fed` |
| `0xf438b` | `0x27` | `12` | `0x5b7fff` |
| `0xf43d8` | `0x74` | `29` | `0x5b8196` |
| `0xf43d9` | `0x75` | `30` | `0x5b8167` |
| `0xf43da` | `0x76` | `31` | `0x5b8177` |

對照：`0xF43D9` → `0x5B8167`（`0x5B8169 call 0x5B9340`）；`0xF438B` → `0x5B7FFF`（`0x5B8003 call 0x5B6D20`）。此處指向的是 router case 位址，不是直接 function pointer 在 event 中。

## 8. 原始 BIN assembly 與每段 bytes SHA256

下列證據是同一原始 KR BIN 直接解碼的完整函式邊界或目標局部 CFG 切片。字元標籤由本稿自行命名，**並非 PDB 原生符號名**。

### E01. Actor instance: source record -> constructor type/id
- VA `0x4B2B8E..0x4B2C2A`（end exclusive）、raw `0xB1F8E..0xB202A`、156 bytes，SHA256 `3f732e9ad80681f748ccfb3f1e65fcf683129f1d001e1f3e16c609599ccd777d`。

```asm
  4b2b8e:	83 c7 12             	add    edi,0x12
  4b2b91:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4b2b95:	68 08 01 00 00       	push   0x108
  4b2b9a:	e8 c9 e6 3d 00       	call   0x891268
  4b2b9f:	83 c4 04             	add    esp,0x4
  4b2ba2:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2ba6:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4b2baa:	3b c3                	cmp    eax,ebx
  4b2bac:	74 30                	je     0x4b2bde
  4b2bae:	0f b6 57 01          	movzx  edx,BYTE PTR [edi+0x1]
  4b2bb2:	d9 47 fc             	fld    DWORD PTR [edi-0x4]
  4b2bb5:	0f b6 0f             	movzx  ecx,BYTE PTR [edi]
  4b2bb8:	52                   	push   edx
  4b2bb9:	0f b6 57 f3          	movzx  edx,BYTE PTR [edi-0xd]
  4b2bbd:	51                   	push   ecx
  4b2bbe:	52                   	push   edx
  4b2bbf:	0f b7 57 f0          	movzx  edx,WORD PTR [edi-0x10]
  4b2bc3:	51                   	push   ecx
  4b2bc4:	8d 4f f4             	lea    ecx,[edi-0xc]
  4b2bc7:	d9 1c 24             	fstp   DWORD PTR [esp]
  4b2bca:	52                   	push   edx
  4b2bcb:	66 0f be 57 f2       	movsx  dx,BYTE PTR [edi-0xe]
  4b2bd0:	0f b7 d2             	movzx  edx,dx
  4b2bd3:	52                   	push   edx
  4b2bd4:	50                   	push   eax
  4b2bd5:	e8 26 0b 09 00       	call   0x543700
  4b2bda:	8b f0                	mov    esi,eax
  4b2bdc:	eb 02                	jmp    0x4b2be0
  4b2bde:	33 f6                	xor    esi,esi
  4b2be0:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4b2be7:	ff 
  4b2be8:	f6 05 ec 79 fb 00 01 	test   BYTE PTR ds:0xfb79ec,0x1
  4b2bef:	75 39                	jne    0x4b2c2a
  4b2bf1:	b8 01 00 00 00       	mov    eax,0x1
  4b2bf6:	09 05 ec 79 fb 00    	or     DWORD PTR ds:0xfb79ec,eax
  4b2bfc:	68 70 d2 bc 00       	push   0xbcd270
  4b2c01:	c7 05 f0 79 fb 00 68 	mov    DWORD PTR ds:0xfb79f0,0xc0f868
  4b2c08:	f8 c0 00 
  4b2c0b:	89 1d f4 79 fb 00    	mov    DWORD PTR ds:0xfb79f4,ebx
  4b2c11:	89 1d f8 79 fb 00    	mov    DWORD PTR ds:0xfb79f8,ebx
  4b2c17:	89 1d fc 79 fb 00    	mov    DWORD PTR ds:0xfb79fc,ebx
  4b2c1d:	a3 04 7a fb 00       	mov    ds:0xfb7a04,eax
  4b2c22:	e8 f3 f6 3d 00       	call   0x89231a
  4b2c27:	83 c4 04             	add    esp,0x4
```

### E02. Counterexample: other actor constructor type4
- VA `0x4A911B..0x4A9153`（end exclusive）、raw `0xA851B..0xA8553`、56 bytes，SHA256 `82931cabfd0bd037f865a40ec3e527499d52e7de5286a816cd90308d7059bc5e`。

```asm
  4a911b:	68 08 01 00 00       	push   0x108
  4a9120:	e8 43 81 3e 00       	call   0x891268
  4a9125:	83 c4 04             	add    esp,0x4
  4a9128:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4a912b:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4a912e:	3b c6                	cmp    eax,esi
  4a9130:	74 20                	je     0x4a9152
  4a9132:	8b 57 10             	mov    edx,DWORD PTR [edi+0x10]
  4a9135:	d9 47 0c             	fld    DWORD PTR [edi+0xc]
  4a9138:	56                   	push   esi
  4a9139:	52                   	push   edx
  4a913a:	0f b7 57 02          	movzx  edx,WORD PTR [edi+0x2]
  4a913e:	6a 01                	push   0x1
  4a9140:	51                   	push   ecx
  4a9141:	8d 4f 04             	lea    ecx,[edi+0x4]
  4a9144:	d9 1c 24             	fstp   DWORD PTR [esp]
  4a9147:	52                   	push   edx
  4a9148:	6a 04                	push   0x4
  4a914a:	50                   	push   eax
  4a914b:	e8 b0 a5 09 00       	call   0x543700
  4a9150:	8b f0                	mov    esi,eax
  4a9152:	83               	or     ebx,0xffffffff
```

### E03. Actor constructor stores category +0xF4 and key +0xF6 and vtable
- VA `0x543700..0x543798`（end exclusive）、raw `0x142B00..0x142B98`、152 bytes，SHA256 `921438da7b461f1a924af7f69549f8a34fed2a522a2f65a80c56e852a11788dd`。

```asm
  543700:	55                   	push   ebp
  543701:	8b ec                	mov    ebp,esp
  543703:	6a ff                	push   0xffffffff
  543705:	68 28 98 92 00       	push   0x929828
  54370a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  543710:	50                   	push   eax
  543711:	83 ec 28             	sub    esp,0x28
  543714:	53                   	push   ebx
  543715:	56                   	push   esi
  543716:	57                   	push   edi
  543717:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54371c:	33 c5                	xor    eax,ebp
  54371e:	50                   	push   eax
  54371f:	8d 45 f4             	lea    eax,[ebp-0xc]
  543722:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  543728:	8b f9                	mov    edi,ecx
  54372a:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  54372d:	8a 45 18             	mov    al,BYTE PTR [ebp+0x18]
  543730:	8b f3                	mov    esi,ebx
  543732:	89 5d cc             	mov    DWORD PTR [ebp-0x34],ebx
  543735:	88 45 f3             	mov    BYTE PTR [ebp-0xd],al
  543738:	e8 f3 6f f8 ff       	call   0x4ca730
  54373d:	33 d2                	xor    edx,edx
  54373f:	89 93 f0 00 00 00    	mov    DWORD PTR [ebx+0xf0],edx
  543745:	66 8b 45 10          	mov    ax,WORD PTR [ebp+0x10]
  543749:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  54374d:	f3 0f 10 45 14       	movss  xmm0,DWORD PTR [ebp+0x14]
  543752:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  543755:	66 89 83 f6 00 00 00 	mov    WORD PTR [ebx+0xf6],ax
  54375c:	8a 45 20             	mov    al,BYTE PTR [ebp+0x20]
  54375f:	88 83 f8 00 00 00    	mov    BYTE PTR [ebx+0xf8],al
  543765:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  543768:	89 83 00 01 00 00    	mov    DWORD PTR [ebx+0x100],eax
  54376e:	0f b6 45 f3          	movzx  eax,BYTE PTR [ebp-0xd]
  543772:	c7 03 fc f7 c0 00    	mov    DWORD PTR [ebx],0xc0f7fc
  543778:	66 89 8b f4 00 00 00 	mov    WORD PTR [ebx+0xf4],cx
  54377f:	f3 0f 11 83 fc 00 00 	movss  DWORD PTR [ebx+0xfc],xmm0
  543786:	00 
  543787:	88 93 04 01 00 00    	mov    BYTE PTR [ebx+0x104],dl
  54378d:	88 83 05 01 00 00    	mov    BYTE PTR [ebx+0x105],al
  543793:	d9 83 a0 00 00     	fld    DWORD PTR [ebx+0xa0]
```

### E04. Actor vtable interaction handler and type=3 gate
- VA `0x544070..0x54422D`（end exclusive）、raw `0x143470..0x14362D`、445 bytes，SHA256 `36ce9a5e44506e8212ae1a3d6ea730653ca6a58f333f1dd02a33a26e5c8d28fe`。

```asm
  544070:	55                   	push   ebp
  544071:	8b ec                	mov    ebp,esp
  544073:	83 e4 f8             	and    esp,0xfffffff8
  544076:	6a ff                	push   0xffffffff
  544078:	68 04 78 94 00       	push   0x947804
  54407d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  544083:	50                   	push   eax
  544084:	83 ec 10             	sub    esp,0x10
  544087:	53                   	push   ebx
  544088:	56                   	push   esi
  544089:	57                   	push   edi
  54408a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54408f:	33 c4                	xor    eax,esp
  544091:	50                   	push   eax
  544092:	8d 44 24 20          	lea    eax,[esp+0x20]
  544096:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  54409c:	8b f1                	mov    esi,ecx
  54409e:	0f b7 86 f4 00 00 00 	movzx  eax,WORD PTR [esi+0xf4]
  5440a5:	66 83 f8 03          	cmp    ax,0x3
  5440a9:	0f 85 11 03 00 00    	jne    0x5443c0
  5440af:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  5440b5:	8b 01                	mov    eax,DWORD PTR [ecx]
  5440b7:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  5440ba:	ff d2                	call   edx
  5440bc:	8b f8                	mov    edi,eax
  5440be:	85 ff                	test   edi,edi
  5440c0:	74 5e                	je     0x544120
  5440c2:	d9 87 a0 00 00 00    	fld    DWORD PTR [edi+0xa0]
  5440c8:	d8 a6 a0 00 00 00    	fsub   DWORD PTR [esi+0xa0]
  5440ce:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  5440d2:	d9 87 a4 00 00 00    	fld    DWORD PTR [edi+0xa4]
  5440d8:	d8 a6 a4 00 00 00    	fsub   DWORD PTR [esi+0xa4]
  5440de:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  5440e2:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  5440e6:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  5440ea:	e8 db ac 3b 00       	call   0x8fedca
  5440ef:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  5440f3:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  5440f7:	8b 1f                	mov    ebx,DWORD PTR [edi]
  5440f9:	dc 05 28 58 c5 00    	fadd   QWORD PTR ds:0xc55828
  5440ff:	51                   	push   ecx
  544100:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  544104:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  544108:	d9 1c 24             	fstp   DWORD PTR [esp]
  54410b:	e8 40 73 f7 ff       	call   0x4bb450
  544110:	8b 53 58             	mov    edx,DWORD PTR [ebx+0x58]
  544113:	2c 80                	sub    al,0x80
  544115:	0f b6 c0             	movzx  eax,al
  544118:	83 c4 04             	add    esp,0x4
  54411b:	50                   	push   eax
  54411c:	8b cf                	mov    ecx,edi
  54411e:	ff d2                	call   edx
  544120:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  544127:	0f b7 86 f6 00 00 00 	movzx  eax,WORD PTR [esi+0xf6]
  54412e:	0f bf f8             	movsx  edi,ax
  544131:	75 29                	jne    0x54415c
  544133:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  54413a:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  544141:	00 
  544142:	e8 19 bd fb ff       	call   0x4ffe60
  544147:	68 00 cf bc 00       	push   0xbccf00
  54414c:	e8 c9 e1 34 00       	call   0x89231a
  544151:	83 c4 04             	add    esp,0x4
  544154:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  54415b:	ff 
  54415c:	57                   	push   edi
  54415d:	68 a0 b2 fa 00       	push   0xfab2a0
  544162:	e8 19 c9 fb ff       	call   0x500a80
  544167:	83 f8 05             	cmp    eax,0x5
  54416a:	74 7b                	je     0x5441e7
  54416c:	8b 35 d0 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1bd0
  544172:	8d 44 24 14          	lea    eax,[esp+0x14]
  544176:	50                   	push   eax
  544177:	8d 4e 08             	lea    ecx,[esi+0x8]
  54417a:	8d 44 24 14          	lea    eax,[esp+0x14]
  54417e:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  544182:	e8 39 f7 2f 00       	call   0x8438c0
  544187:	8b 76 0c             	mov    esi,DWORD PTR [esi+0xc]
  54418a:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  54418e:	3b c6                	cmp    eax,esi
  544190:	0f 84 7d 05 00 00    	je     0x544713
  544196:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  544199:	85 c0                	test   eax,eax
  54419b:	0f 84 72 05 00 00    	je     0x544713
  5441a1:	8b 48 40             	mov    ecx,DWORD PTR [eax+0x40]
  5441a4:	3b 48 44             	cmp    ecx,DWORD PTR [eax+0x44]
  5441a7:	0f 84 66 05 00 00    	je     0x544713
  5441ad:	6a 1c                	push   0x1c
  5441af:	e8 b4 d0 34 00       	call   0x891268
  5441b4:	8b f0                	mov    esi,eax
  5441b6:	83 c4 04             	add    esp,0x4
  5441b9:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5441bd:	c7 44 24 28 01 00 00 	mov    DWORD PTR [esp+0x28],0x1
  5441c4:	00 
  5441c5:	85 f6                	test   esi,esi
  5441c7:	0f 84 26 03 00 00    	je     0x5444f3
  5441cd:	e8 8e ae ec ff       	call   0x40f060
  5441d2:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  5441d8:	50                   	push   eax
  5441d9:	8b d7                	mov    edx,edi
  5441db:	8b c6                	mov    eax,esi
  5441dd:	e8 9e fd 20 00       	call   0x753f80
  5441e2:	e9 0e 03 00 00       	jmp    0x5444f5
  5441e7:	e8 b4 09 ec ff       	call   0x404ba0
  5441ec:	8b 80 4c 5f 00 00    	mov    eax,DWORD PTR [eax+0x5f4c]
  5441f2:	83 f8 03             	cmp    eax,0x3
  5441f5:	74 13                	je     0x54420a
  5441f7:	83 f8 07             	cmp    eax,0x7
  5441fa:	74 0e                	je     0x54420a
  5441fc:	83 f8 17             	cmp    eax,0x17
  5441ff:	74 09                	je     0x54420a
  544201:	83 f8 18             	cmp    eax,0x18
  544204:	0f 85 09 05 00 00    	jne    0x544713
  54420a:	e8 c1 62 ed ff       	call   0x41a4d0
  54420f:	8b 98 d8 5e 00 00    	mov    ebx,DWORD PTR [eax+0x5ed8]
  544215:	85 db                	test   ebx,ebx
  544217:	0f 84 af 00 00 00    	je     0x5442cc
  54421d:	8b d3                	mov    edx,ebx
  54421f:	e8 4c 58 ff ff       	call   0x539a70
  544224:	83 f8 01             	cmp    eax,0x1
  544227:	0f 84 9f 00 00 00    	je     0x5442cc
```

### E05. Alternate F43D6 path versus F43D9 event constructor
- VA `0x54422D..0x54436F`（end exclusive）、raw `0x14362D..0x14376F`、322 bytes，SHA256 `1e9b5d46cb40645261d329d87362499c041c75431cc8df387f39d53801749ba5`。

```asm
  54422d:	e8 8e 12 ec ff       	call   0x4054c0
  544232:	6a 1c                	push   0x1c
  544234:	e8 2f d0 34 00       	call   0x891268
  544239:	33 f6                	xor    esi,esi
  54423b:	83 c4 04             	add    esp,0x4
  54423e:	83 cb ff             	or     ebx,0xffffffff
  544241:	3b c6                	cmp    eax,esi
  544243:	74 1e                	je     0x544263
  544245:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  544248:	89 70 18             	mov    DWORD PTR [eax+0x18],esi
  54424b:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  54424e:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  544251:	c7 40 10 d6 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43d6
  544258:	c7 00 cc 7b c4 00    	mov    DWORD PTR [eax],0xc47bcc
  54425e:	89 78 14             	mov    DWORD PTR [eax+0x14],edi
  544261:	8b f0                	mov    esi,eax
  544263:	e8 38 08 ec ff       	call   0x404aa0
  544268:	8b 80 c4 13 00 00    	mov    eax,DWORD PTR [eax+0x13c4]
  54426e:	50                   	push   eax
  54426f:	56                   	push   esi
  544270:	83 ec 1c             	sub    esp,0x1c
  544273:	8b cc                	mov    ecx,esp
  544275:	89 64 24 38          	mov    DWORD PTR [esp+0x38],esp
  544279:	68 fc d1 be 00       	push   0xbed1fc
  54427e:	e8 cd df eb ff       	call   0x402250
  544283:	6a 20                	push   0x20
  544285:	c7 44 24 50 02 00 00 	mov    DWORD PTR [esp+0x50],0x2
  54428c:	00 
  54428d:	e8 1e 12 04 00       	call   0x5854b0
  544292:	8b f0                	mov    esi,eax
  544294:	e8 97 10 04 00       	call   0x585330
  544299:	83 ec 1c             	sub    esp,0x1c
  54429c:	8b cc                	mov    ecx,esp
  54429e:	89 64 24 50          	mov    DWORD PTR [esp+0x50],esp
  5442a2:	50                   	push   eax
  5442a3:	e8 a8 df eb ff       	call   0x402250
  5442a8:	68 cf 00 00 00       	push   0xcf
  5442ad:	89 5c 24 6c          	mov    DWORD PTR [esp+0x6c],ebx
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

### E06. Actor lookup by (WORD key,BYTE kind) pair
- VA `0x544940..0x54499A`（end exclusive）、raw `0x143D40..0x143D9A`、90 bytes，SHA256 `e65d8856a79a3808854b835748c44b31b719d049d752f29b7093f03adbcd369b`。

```asm
  544940:	55                   	push   ebp
  544941:	8b ec                	mov    ebp,esp
  544943:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  544946:	2b 42 04             	sub    eax,DWORD PTR [edx+0x4]
  544949:	53                   	push   ebx
  54494a:	c1 f8 02             	sar    eax,0x2
  54494d:	56                   	push   esi
  54494e:	33 c9                	xor    ecx,ecx
  544950:	57                   	push   edi
  544951:	85 c0                	test   eax,eax
  544953:	74 43                	je     0x544998
  544955:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  544958:	8b f2                	mov    esi,edx
  54495a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  544960:	8b 3e                	mov    edi,DWORD PTR [esi]
  544962:	66 8b 9f f6 00 00 00 	mov    bx,WORD PTR [edi+0xf6]
  544969:	66 3b 5d 08          	cmp    bx,WORD PTR [ebp+0x8]
  54496d:	75 0e                	jne    0x54497d
  54496f:	66 0f be 5d 0c       	movsx  bx,BYTE PTR [ebp+0xc]
  544974:	66 39 9f f4 00 00 00 	cmp    WORD PTR [edi+0xf4],bx
  54497b:	74 0f                	je     0x54498c
  54497d:	41                   	inc    ecx
  54497e:	83 c6 04             	add    esi,0x4
  544981:	3b c8                	cmp    ecx,eax
  544983:	72 db                	jb     0x544960
  544985:	5f                   	pop    edi
  544986:	5e                   	pop    esi
  544987:	5b                   	pop    ebx
  544988:	5d                   	pop    ebp
  544989:	c2 0c 00             	ret    0xc
  54498c:	8b 04 8a             	mov    eax,DWORD PTR [edx+ecx*4]
  54498f:	8a 4d 10             	mov    cl,BYTE PTR [ebp+0x10]
  544992:	50                   	push   eax
  544993:	e8 98 f1 ff ff       	call   0x543b30
  544998:	5f                   	pop    edi
  544999:	5e                   	pop    esi
```

### E07. Event router type/action jump gate
- VA `0x5B7F80..0x5B7FB5`（end exclusive）、raw `0x1B7380..0x1B73B5`、53 bytes，SHA256 `f2396ef149d6a50e7dbcd6d7b71e5ec75edd7cfefbdc881a62aa3ee42905e8c2`。

```asm
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
```

### E08. F43D9 routing branch calls Quest-type2 handler
- VA `0x5B8167..0x5B8195`（end exclusive）、raw `0x1B7567..0x1B7595`、46 bytes，SHA256 `ba3025631b5faa86d21540adaea62f57af367116544721fdacf799fe76163d54`。

```asm
  5b8167:	8b ce                	mov    ecx,esi
  5b8169:	e8 d2 11 00 00       	call   0x5b9340
  5b816e:	5f                   	pop    edi
  5b816f:	5e                   	pop    esi
  5b8170:	5b                   	pop    ebx
  5b8171:	8b e5                	mov    esp,ebp
  5b8173:	5d                   	pop    ebp
  5b8174:	c2 04 00             	ret    0x4
  5b8177:	8b f3                	mov    esi,ebx
  5b8179:	e8 62 15 00 00       	call   0x5b96e0
  5b817e:	5f                   	pop    edi
  5b817f:	5e                   	pop    esi
  5b8180:	5b                   	pop    ebx
  5b8181:	8b e5                	mov    esp,ebp
  5b8183:	5d                   	pop    ebp
  5b8184:	c2 04 00             	ret    0x4
  5b8187:	53                   	push   ebx
  5b8188:	e8 e3 13 00 00       	call   0x5b9570
  5b818d:	5f                   	pop    edi
  5b818e:	5e                   	pop    esi
  5b818f:	5b                   	pop    ebx
  5b8190:	8b e5                	mov    esp,ebp
  5b8192:	5d                   	pop    ebp
  5b8193:	c2 04              	ret    0x4
```

### E09. Outer event 105BD/action6A7, nested 105BF selector -> first type2 candidate
- VA `0x5B9340..0x5B9498`（end exclusive）、raw `0x1B8740..0x1B8898`、344 bytes，SHA256 `69a5aadbc0a1ffa9d11ec62c74a1d8a40e201eee8d0e9192b5903e56aab4df99`。

```asm
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

### E10. Outer action6A8 branch is different
- VA `0x5B9498..0x5B9563`（end exclusive）、raw `0x1B8898..0x1B8963`、203 bytes，SHA256 `cfcc346ce40d3b55c73015b1ce2ed6d66268936d93d95646b05ac8f6d881b834`。

```asm
  5b9498:	81 f9 a8 06 00 00    	cmp    ecx,0x6a8
  5b949e:	0f 85 af 00 00 00    	jne    0x5b9553
  5b94a4:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  5b94a7:	85 f6                	test   esi,esi
  5b94a9:	74 20                	je     0x5b94cb
  5b94ab:	8b 16                	mov    edx,DWORD PTR [esi]
  5b94ad:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  5b94b0:	8b ce                	mov    ecx,esi
  5b94b2:	ff d0                	call   eax
  5b94b4:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b94b9:	74 12                	je     0x5b94cd
  5b94bb:	6a 00                	push   0x0
  5b94bd:	68 c0 1f bf 00       	push   0xbf1fc0
  5b94c2:	68 18 21 bf 00       	push   0xbf2118
  5b94c7:	6a 00                	push   0x0
  5b94c9:	ff d7                	call   edi
  5b94cb:	33 f6                	xor    esi,esi
  5b94cd:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  5b94d0:	8b 3d d0 1b fe 00    	mov    edi,DWORD PTR ds:0xfe1bd0
  5b94d6:	8d 55 f0             	lea    edx,[ebp-0x10]
  5b94d9:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  5b94dc:	52                   	push   edx
  5b94dd:	8d 4f 08             	lea    ecx,[edi+0x8]
  5b94e0:	8d 45 e8             	lea    eax,[ebp-0x18]
  5b94e3:	e8 d8 a3 28 00       	call   0x8438c0
  5b94e8:	8b 7f 0c             	mov    edi,DWORD PTR [edi+0xc]
  5b94eb:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  5b94ee:	3b c7                	cmp    eax,edi
  5b94f0:	74 61                	je     0x5b9553
  5b94f2:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5b94f5:	85 c0                	test   eax,eax
  5b94f7:	74 5a                	je     0x5b9553
  5b94f9:	8b 48 40             	mov    ecx,DWORD PTR [eax+0x40]
  5b94fc:	3b 48 44             	cmp    ecx,DWORD PTR [eax+0x44]
  5b94ff:	74 52                	je     0x5b9553
  5b9501:	6a 1c                	push   0x1c
  5b9503:	e8 60 7d 2d 00       	call   0x891268
  5b9508:	8b f8                	mov    edi,eax
  5b950a:	83 c4 04             	add    esp,0x4
  5b950d:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  5b9510:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  5b9517:	85 ff                	test   edi,edi
  5b9519:	74 18                	je     0x5b9533
  5b951b:	e8 40 5b e5 ff       	call   0x40f060
  5b9520:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  5b9526:	8b 56 14             	mov    edx,DWORD PTR [esi+0x14]
  5b9529:	50                   	push   eax
  5b952a:	8b c7                	mov    eax,edi
  5b952c:	e8 4f aa 19 00       	call   0x753f80
  5b9531:	eb 02                	jmp    0x5b9535
  5b9533:	33 c0                	xor    eax,eax
  5b9535:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b953c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  5b953f:	e8 5c b5 e4 ff       	call   0x404aa0
  5b9544:	8d 55 e8             	lea    edx,[ebp-0x18]
  5b9547:	52                   	push   edx
  5b9548:	8d b0 5c 14 00 00    	lea    esi,[eax+0x145c]
  5b954e:	e8 0d ad 24 00       	call   0x804260
  5b9553:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5b9556:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b955d:	59                   	pop    ecx
  5b955e:	5f                   	pop    edi
  5b955f:	5e                   	pop    esi
  5b9560:	8b e5                	mov    esp,ebp
  5b9562:	5d                   	pop    ebp
```

### E11. First candidate selected, not all matches
- VA `0x5008B0..0x500944`（end exclusive）、raw `0xFFCB0..0xFFD44`、148 bytes，SHA256 `aeee21cd72e41936104913bf9baa86f11b09632e77fa568f145237f67f62928c`。

```asm
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

### E12. Type2 NPC giver equality filter
- VA `0x500A00..0x500A7D`（end exclusive）、raw `0xFFE00..0xFFE7D`、125 bytes，SHA256 `7249341812963eb07e7eff57ed46c249bb791275e54364b6265debf16c55a929`。

```asm
  500a00:	55                   	push   ebp
  500a01:	8b ec                	mov    ebp,esp
  500a03:	83 ec 0c             	sub    esp,0xc
  500a06:	53                   	push   ebx
  500a07:	57                   	push   edi
  500a08:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a0b:	8b 87 c4 5e 00 00    	mov    eax,DWORD PTR [edi+0x5ec4]
  500a11:	8b 9f c0 5e 00 00    	mov    ebx,DWORD PTR [edi+0x5ec0]
  500a17:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  500a1a:	3b d8                	cmp    ebx,eax
  500a1c:	74 57                	je     0x500a75
  500a1e:	56                   	push   esi
  500a1f:	90                   	nop
  500a20:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  500a23:	8b b7 ac 5e 00 00    	mov    esi,DWORD PTR [edi+0x5eac]
  500a29:	8d 4d fc             	lea    ecx,[ebp-0x4]
  500a2c:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a2f:	51                   	push   ecx
  500a30:	8d 45 f8             	lea    eax,[ebp-0x8]
  500a33:	8b ce                	mov    ecx,esi
  500a35:	e8 e6 32 00 00       	call   0x503d20
  500a3a:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500a3d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500a40:	74 05                	je     0x500a47
  500a42:	83 c0 10             	add    eax,0x10
  500a45:	eb 02                	jmp    0x500a49
  500a47:	33 c0                	xor    eax,eax
  500a49:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a4c:	85 c0                	test   eax,eax
  500a4e:	74 1c                	je     0x500a6c
  500a50:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  500a53:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  500a56:	75 14                	jne    0x500a6c
  500a58:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500a5c:	75 0e                	jne    0x500a6c
  500a5e:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500a61:	8d 45 fc             	lea    eax,[ebp-0x4]
  500a64:	e8 a7 32 f4 ff       	call   0x443d10
  500a69:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a6c:	83 c3 02             	add    ebx,0x2
  500a6f:	3b 5d f4             	cmp    ebx,DWORD PTR [ebp-0xc]
  500a72:	75 ac                	jne    0x500a20
  500a74:	5e                   	pop    esi
  500a75:	5f                   	pop    edi
  500a76:	5b                   	pop    ebx
  500a77:	8b e5                	mov    esp,ebp
  500a79:	5d                   	pop    ebp
  500a7a:	c2 0c 00             	ret    0xc
```

### E13. Controller first stage local state/action flags
- VA `0x561760..0x561919`（end exclusive）、raw `0x160B60..0x160D19`、441 bytes，SHA256 `54a4fa313f581ef4f967a8c4a84988e713df7544a9e0e5d7b48bd38bdd369a08`。

```asm
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
  5617e9:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  5617f0:	be 01 00 00 00       	mov    esi,0x1
  5617f5:	75 29                	jne    0x561820
  5617f7:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  5617fd:	c7 44 24 68 00 00 00 	mov    DWORD PTR [esp+0x68],0x0
  561804:	00 
  561805:	e8 46 e0 fe ff       	call   0x54f850
  56180a:	68 80 d5 bc 00       	push   0xbcd580
  56180f:	e8 06 0b 33 00       	call   0x89231a
  561814:	83 c4 04             	add    esp,0x4
  561817:	83 cf ff             	or     edi,0xffffffff
  56181a:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  56181e:	eb 03                	jmp    0x561823
  561820:	83 cf ff             	or     edi,0xffffffff
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
  561918:	f6       	test   BYTE PTR ds:0xfaadd0,0x1
```

### E14. Controller conditional 0x3F application path
- VA `0x561918..0x5619C0`（end exclusive）、raw `0x160D18..0x160DC0`、168 bytes，SHA256 `d8936a587445d6044e227344b77d99f385d3c48defd72edcfc034e2a7f06a62a`。

```asm
  561918:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  56191f:	75 24                	jne    0x561945
  561921:	09 35 d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,esi
  561927:	c7 44 24 68 03 00 00 	mov    DWORD PTR [esp+0x68],0x3
  56192e:	00 
  56192f:	e8 5c c0 1e 00       	call   0x74d990
  561934:	68 70 cc bc 00       	push   0xbccc70
  561939:	e8 dc 09 33 00       	call   0x89231a
  56193e:	83 c4 04             	add    esp,0x4
  561941:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561945:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  56194c:	8b 0d bc 5b f9 00    	mov    ecx,DWORD PTR ds:0xf95bbc
  561952:	8b 15 c0 5b f9 00    	mov    edx,DWORD PTR ds:0xf95bc0
  561958:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  56195c:	f3 0f 10 44 24 14    	movss  xmm0,DWORD PTR [esp+0x14]
  561962:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  561966:	f3 0f 11 83 84 00 00 	movss  DWORD PTR [ebx+0x84],xmm0
  56196d:	00 
  56196e:	75 24                	jne    0x561994
  561970:	09 35 90 43 f9 00    	or     DWORD PTR ds:0xf94390,esi
  561976:	c7 44 24 68 04 00 00 	mov    DWORD PTR [esp+0x68],0x4
  56197d:	00 
  56197e:	e8 0d fc f7 ff       	call   0x4e1590
  561983:	68 80 cc bc 00       	push   0xbccc80
  561988:	e8 8d 09 33 00       	call   0x89231a
  56198d:	83 c4 04             	add    esp,0x4
  561990:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561994:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  56199b:	a0 a4 42 f9 00       	mov    al,ds:0xf942a4
  5619a0:	88 83 88 00 00 00    	mov    BYTE PTR [ebx+0x88],al
  5619a6:	75 24                	jne    0x5619cc
  5619a8:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  5619ae:	c7 44 24 68 05 00 00 	mov    DWORD PTR [esp+0x68],0x5
  5619b5:	00 
  5619b6:	e8 c5 5a 02 00       	call   0x587480
  5619bb:	68 c0 cc bc 00       	push   0xbcccc0
```

### E15. Inbound 0x40 state0 constructs action F438B and recalc
- VA `0x502270..0x5023A2`（end exclusive）、raw `0x101670..0x1017A2`、306 bytes，SHA256 `96a7de374e84ee7653e5286e5e69c5d638406d005be5a3e093a347390edd93dc`。

```asm
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
  50238e:	e8 cd cc f0 ff       	call   0x40f060
  502393:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  502399:	50                   	push   eax
  50239a:	8b f7                	mov    esi,edi
  50239c:	56                   	push   esi
  50239d:	e8 9e de ff ff       	call   0x500240
```

### E16. F438B event receiver -> QuestInfo lookup -> mode2 TalkBox
- VA `0x5B6D20..0x5B6E55`（end exclusive）、raw `0x1B6120..0x1B6255`、309 bytes，SHA256 `bff7e1c4bc98f2415a5dee032688ea8fc43b60e36679d36fd0d121b2e1ac651e`。

```asm
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

### E17. TalkBox initializer stores QuestID and giver/mode
- VA `0x636520..0x6365B0`（end exclusive）、raw `0x235920..0x2359B0`、144 bytes，SHA256 `2d7cae95d74559fee174b16f7b4cd7b24cc5637b233721f1e954a9af1f2035d9`。

```asm
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
```

### E18. Mode-specific UI action: mode1 guard, avoid mistaking 0x36
- VA `0x636B70..0x636C20`（end exclusive）、raw `0x235F70..0x236020`、176 bytes，SHA256 `a24261f73cfd3244899a2abee1ca72a3d812559362932704d48b34fc12ccb62d`。

```asm
  636b70:	55                   	push   ebp
  636b71:	8b ec                	mov    ebp,esp
  636b73:	83 e4 f8             	and    esp,0xfffffff8
  636b76:	6a ff                	push   0xffffffff
  636b78:	68 97 89 94 00       	push   0x948997
  636b7d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  636b83:	50                   	push   eax
  636b84:	83 ec 7c             	sub    esp,0x7c
  636b87:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  636b8c:	33 c4                	xor    eax,esp
  636b8e:	89 44 24 74          	mov    DWORD PTR [esp+0x74],eax
  636b92:	53                   	push   ebx
  636b93:	56                   	push   esi
  636b94:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  636b99:	33 c4                	xor    eax,esp
  636b9b:	50                   	push   eax
  636b9c:	8d 84 24 88 00 00 00 	lea    eax,[esp+0x88]
  636ba3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  636ba9:	83 bf ac 00 00 00 01 	cmp    DWORD PTR [edi+0xac],0x1
  636bb0:	76 0c                	jbe    0x636bbe
  636bb2:	8b c7                	mov    eax,edi
  636bb4:	e8 a7 01 00 00       	call   0x636d60
  636bb9:	e9 3c 01 00 00       	jmp    0x636cfa
  636bbe:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636bc4:	33 db                	xor    ebx,ebx
  636bc6:	3b c3                	cmp    eax,ebx
  636bc8:	75 0c                	jne    0x636bd6
  636bca:	8b f7                	mov    esi,edi
  636bcc:	e8 4f 01 00 00       	call   0x636d20
  636bd1:	e9 24 01 00 00       	jmp    0x636cfa
  636bd6:	83 f8 01             	cmp    eax,0x1
  636bd9:	0f 85 a5 00 00 00    	jne    0x636c84
  636bdf:	6a 14                	push   0x14
  636be1:	e8 82 a6 25 00       	call   0x891268
  636be6:	83 c4 04             	add    esp,0x4
  636be9:	3b c3                	cmp    eax,ebx
  636beb:	74 1b                	je     0x636c08
  636bed:	83 c9 ff             	or     ecx,0xffffffff
  636bf0:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636bf3:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  636bf9:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636bfc:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636bff:	c7 40 10 02 44 0f 00 	mov    DWORD PTR [eax+0x10],0xf4402
  636c06:	8b d8                	mov    ebx,eax
  636c08:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  636c0e:	83 c0 4c             	add    eax,0x4c
  636c11:	50                   	push   eax
  636c12:	8d 74 24 4c          	lea    esi,[esp+0x4c]
  636c16:	e8 85 08 12 00       	call   0x7574a0
  636c1b:	6a 1f                	push   0x1f
  636c1d:	c7 84 24     	mov    DWORD PTR [esp+0x94],0x0
  636c24:	    
```

### E19. Generic 0x3F payload builder
- VA `0x4A39A0..0x4A3A15`（end exclusive）、raw `0xA2DA0..0xA2E15`、117 bytes，SHA256 `65f2ea549d982adcbfedeb0dff460225bc15932a2ebe379499f2b123ecd18d09`。

```asm
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
  4a39ed:	cc                   	int3
  4a39ee:	cc                   	int3
  4a39ef:	cc                   	int3
  4a39f0:	55                   	push   ebp
  4a39f1:	8b ec                	mov    ebp,esp
  4a39f3:	b8 18 10 00 00       	mov    eax,0x1018
  4a39f8:	e8 73 cc 40 00       	call   0x8b0670
  4a39fd:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a3a02:	33 c5                	xor    eax,ebp
  4a3a04:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4a3a07:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3a0a:	b8 21 00 00 00       	mov    eax,0x21
  4a3a0f:	66 89 85 e8 ef ff  	mov    WORD PTR [ebp-0x1018],ax
```

### E20. S2C key16 and candidate rebuild
- VA `0x503400..0x50343A`（end exclusive）、raw `0x102800..0x10283A`、58 bytes，SHA256 `1684a055a3dca3dd3608adf959f8d69730f364c4875f17a0e23ccc6394f4e7a9`。

```asm
  503400:	55                   	push   ebp
  503401:	8b ec                	mov    ebp,esp
  503403:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503406:	56                   	push   esi
  503407:	8b f1                	mov    esi,ecx
  503409:	57                   	push   edi
  50340a:	83 c0 02             	add    eax,0x2
  50340d:	8d be b0 5e 00 00    	lea    edi,[esi+0x5eb0]
  503413:	e8 c8 80 f4 ff       	call   0x44b4e0
  503418:	e8 43 bc f0 ff       	call   0x40f060
  50341d:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  503423:	50                   	push   eax
  503424:	56                   	push   esi
  503425:	e8 16 ce ff ff       	call   0x500240
  50342a:	5f                   	pop    edi
  50342b:	33 c0                	xor    eax,eax
  50342d:	5e                   	pop    esi
  50342e:	5d                   	pop    ebp
  50342f:	c2 0c 00             	ret    0xc
  503432:	cc                   	int3
  503433:	cc                   	int3
  503434:	cc                   	int3
  503435:	cc                   	int3
  503436:	cc                   	int3
  503437:	cc                   	int3
  503438:	cc                   	int3
  503439:	cc                   	int3
```

## 9. 精確可續研究入口（不要用段號當完成條件）

1. `0x544070` 所在 actor vtable `0xC0F7FC+0x64` 的**實際 event callback 呼叫者**：已查 `0x544B28`、`0x4CDBDA`、`0x4CE08A`、`0x4D1948` 的 virtual call class 可能不同；需要物件活體類型對應才可提升為「玩家鼠標點擊」唯一原生 producer。
2. `0x4B2BD5` 源記錄欄位到 Lua `CreateObject` binding/SceneList 消費者 `0x??`：已證 constructor 參數 map，但沒有 source-of-origin 唯一路徑，應由 T07/T08 聯合驗證。
3. `0x54433E` 傳事件物件給 `0x5854B0`/`0x5740F0`，`0x58B270` 消費；外層 `0x105BD` action `0x6A7` 的真正 producer/registration 仍需沿 event bridge 追，不能倒推「一定派送」。
4. Q15 同 giver type2 的 first-match 順序需取得完整 QuestInfo.XML 快照（Git evidence 巨檔本工具讀回可能 content empty，原 `Table.stp` 尚不能按同 XOR 規則解出 XML），不要用資源無證唯一性。
5. Quest15-③ 專研 `0x544070` / `0x5B9340` 發送 `0x1C` 與 `0x561760` 延後 `0x3F`、跳過的 gate 和 sender queue；並確認 mode2 GUI 的其餘 callback；④再研究 0x40/0x74 詳細 state1/refusal/status。

**核對判定：本次達到 Quest15-② 定義之**有界 Client 條件式 actor→任務候選 + Quest15 mode2 TalkBox 消費**目標；外層事件 wrapper 和原版 Server 的時序若要作為「真正按鍵後 UI 必開」的保證，仍須附新的原生／runtime 證據，不能把本次有界結論擴大為那種保證。**
