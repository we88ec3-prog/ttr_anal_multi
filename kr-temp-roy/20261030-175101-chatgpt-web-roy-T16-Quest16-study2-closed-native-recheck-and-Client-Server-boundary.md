# Quest16-②｜完成狀態複核及舊 UI 假設勘誤（T16／KR Client，附 BIN-first 可重現證據）

- 文件：`20261030-175101-chatgpt-web-roy-T16-Quest16-study2-closed-native-recheck-and-Client-Server-boundary.md`；產生時間 `2026-10-30T17:51:01+08:00`；研究者 `chatgpt-web roy`。
- 性質：**已完成原稿的獨立複核／補充勘誤，不新設正式 T16-NNN 段號**。T16 工作分支既有正式 `T16-121` [commit 4cc3a2a1fa9a8074413e70169e86c2f6025ca834](https://github.com/we88ec3-prog/ttr_anal_multi/commit/4cc3a2a1fa9a8074413e70169e86c2f6025ca834)，對應 `kr-temp-roy/20261030-094522-chatgpt-web-roy-T16-121-KR-Quest16-study2-closed-NPC-event-S2C-0040-F438B-mode2-TalkBox.md`，既有 blob `e5d48e09ac8604ac39ce0dc584bb20308d927b54`。
- T16-120 研究仍為歷史正確進度；與上列官方完成版**同名不同內容**的本對話較晚本機 `20261030-173036-...-T16-121-...-bridge-pending.md` 是早期 mode1 假設的未修正支線，**不可視為最新正式判決，不覆寫 GitHub 正式 121，也不另行上傳成另一份同段號**。
- 原件 `Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Table.stp` SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。四原件均存在且唯讀。`.text` PE ImageBase 0x400000, RVA 0x1000, raw 0x400，code raw=`VA−0x400C00`。

## 一、為什麼一直被說「② 沒閉合」——真正原因

### 1. 不是 Server 缺失，不是缺檔案

原生 Client 和 KR 資源有實檔且 SHA 正確。原版 Server 是否核准任務、如何持久化、怎麼回覆，是相容 Server 開發、S00 SPEC/ADR、③④封包配對與待遊玩驗證的責任，**不能被拿來阻止 Client ② 的靜態有界研究**。不能從 Client 推回原版 Server 對所有狀態必發封包。缺原版 Server runtime trace 不等於當前 Client 靜態研究受阻。

### 2. 舊版研究的錯誤假設（本次明確修正）

T16-119/120 與較晚於本機產生、但未推 Git 的同名 T16-121 pending 原稿，試圖強行證明 `NPC giver10027 → type2 QID16 → 0x105B9(action F438A) → TalkBox mode1`。這忽略事件分派真正以 `event+0x10` 的 **action** 分支，並錯把控制項 child 物件的 `+0x84` 當 QuestID writer。`0x6391C0/0x639210` 讀到的另一類 +0x84 不能代換為 QuestID。正確做法是在 **NPC 互動本地候選鏈**與 **獨立的 S2C 0x40 下游 UI 鏈** 分別驗證；沒有必要、也沒有證據虛構一個 NPC10027 直接變成 QID16 的 mode1 writer。

### 3. 反證兼容修正

- `event.type=0x105B9` **不表示**只有一種 TalkBox：`0xF438A` 與 `0xF438B` 分別 dispatch 至不同入口。
- **`0x502270` 的 `[packet+4]==0` 支路**直接從 `WORD[packet+2]` 建立 `0x105B9/action F438B/event+0x14=QuestID`；此時 `0x14=16` 並不依賴 NPC giver10027。原碼檢查 `0x5022A1 mov eax,[ebx+4]; 0x5022AC cmp eax,0; 0x502355 movzx ecx,word [ebx+2]; 0x502362 mov event.action,0xF438B; 0x50236F mov event+14,ecx; 0x502377 call 0x58AA50`。
- `0x5B7F80` action dispatcher 實際查表 `0x5B8460` → `0x5B8394`；`0xF438B` 指到 `0x5B7FFF`, `call 0x5B6D20`，後者查 QuestInfo map，成功後以 `push 0x2; call 0x636520` 開 **mode2**；`0xF438A` 則是 `0x5B7FED`, `0x5B6BE0`，mode1。
- `0x636520` 分別寫 `[TalkBox+0x80]` QuestID 與 `[TalkBox+0x84]` giver selector（此處 Quest16 的 giver10027）；mode2 case table 在 `0x636774 + 2*4` 指 `0x636687`。不可把 `[TalkBox+0x88]` 當 QuestID；它是另一個 item/QuestTalk 物件指標。

## 二、可用於 Client ② 有界完成的兩條真實流程

```text
A. 玩家/NPC actor 本地事件（有前提，不保證成功）
  actor+F6 NPC giver selector=10027
  0x105BD action0x6A7 -> nested 0x105BF
  event action0xF43D9 -> 0x5B7F80 -> 0x5B9340
  0x5B93FF event+14 -> 0x5008B0 / 0x500A00 type2 giver
  若 Quest14 Demand、角色候選、level/town/exclusion 所有門檻通過
  則唯一候選 QuestID16 -> 0x561760(16,1)
  0x001C event request 與 controller+gate 的 0x003F 均獨立，不能冒稱 0x0036。

B. S2C index0x40 state0 的 Client UI 消費鏈（另一側，有前提）
  packet WORD+2=16, DWORD+4=0
  0x502270 -> 0x105B9 action F438B event+14=16
  -> 0x58AA50 queue -> event scheduler/consumer
  -> 0x5B7F80 action=F438B -> 0x5B7FFF
  -> 0x5B6D20 -> QuestInfo map key=16
  -> 0x636520(mode2, QID16, giver10027)
  -> mode2 0x636687 with QuestTalk-derived content
  由資源存在、queue dispatch、UI 狀態/配置成功等條件決定實際顯示。

A 與 B **各自靜態已證**，但**A 到 B 的原版 Server 因果配對未證**；Server 可設計相容規則來滿足 B 的入口，不能冒稱原版 Server 一定如此決策。
```

## 三、Direct BIN native action jump-table 雙重核對

- 直接讀 raw `0x5B8460−0x400C00` 與 `0x5B8394−0x400C00`，而非引用文字原稿。
- `0x5B7F96` 對 action 扣除 `0xF4364`，`0x5B7FA6` 取 byte case，`0x5B7FAE` 取 DWORD jump target。

| event action | lookup offset | case | native target | 意義 |
|---|---:|---:|---|---|
| `0xF438A` | `0x26` | `0xB` | `0x5B7FED` | mode1 path; NOT NPC10027 type2→QID16 proof |
| `0xF438B` | `0x27` | `0xC` | `0x5B7FFF` | mode2 path; S2C state0 produced |
| `0xF43D9` | `0x75` | `0x1E` | `0x5B8167` | NPC nested-event type2 gate |

## 四、跨研究與 Server 交接，不再把 Server 不可證等同於 Client ② 受阻

| 軸 | ② 完成判準與現況 | 下一位主責 |
|---|---|---|
| 原生 Client（②） | NPC `0x105BD/105BF` → type2 QID16；獨立 S2C `0x40` state0 QID16 → `F438B` → mode2 TalkBox；**有界完成** | T16，保留完整條件 |
| Client ③／④ 待逆向 | `0x001C`、`0x003F`、`0x0036` 各 producer/queue/framing；`0x40` 非零 state、`0x74`、拒絕/確認、接受後 Client cache/UI 更新，ACK 關聯仍需證據 | T16，T02 底層協作 |
| Server 待開發 | Quest14 prerequisite、可接受 Quest16 的決策、回覆及失敗狀態、重登 snapshot、持久化策略，需自行設計並與已證 Client 介面相容；**不是要求還原原版 Server 內部演算法** | S00 產 SPEC/GAP；獨立 Server 實作 |
| 跨功能待整合 | NPC actor、場景、任務完成與存檔對應 T08/T07/T14/T15，UI T06、Session T03/T04，T02 framing | T01/S00 + 各主責 task |
| 待遊玩驗證 | NPC 現場存在、真實點擊、實際發送成功及 `0x40` 回覆時序、TalkBox 顯示、真正接取 Quest16、Quest15 解鎖 | 相容 Server + 遊玩驗收 |

Quest16 ① **有界完成**；② **Client 靜態有界完成（本次獨立確認）**；③／④／⑤ 為獨立後續研究，不得以②成果冒稱全 Quest 可玩或全主線 Server 相容。

### T01 退回修正關係

GitHub 最新 main 的 `kr/tasks/T16/README.md` 尚有 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001 — NEEDS_FIX`；T16 工作分支該同 ID 已見 `READY_FOR_REVIEW` 修正文，兩者位於**不同分支的不同時間快照**。既有 T16-121/122 分別提供 mode2 和 C2S 更正證據，本稿僅輔助主張層級核對，**不擅自修改 T01 審查狀態**、不把來源訂正認定為 FULL-PASS。此差異需由正式 Git 合併與 T01 複驗程序處理；本對話的一次性 main→T16 merge 已完成，不自動重做。

## 五、BIN-first 原生切片（位址、raw、SHA256、bytes/assembly）

以下每段均由唯讀 `/mnt/data/Tartaros.bin` `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 擷取，slice SHA256 對應 raw byte 範圍。linear decode 只依確定基本塊/跳表位址立論；中間 data or fallthrough 不作推測。

### NPC local nested event, type2 first candidate, controller and independent C2S

- VA `0x005B9340..0x005B9498`；raw `0x1B8740..0x1B8898`；344 B；SHA256 `69a5aadbc0a1ffa9d11ec62c74a1d8a40e201eee8d0e9192b5903e56aab4df99`。

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

### S2C state0 QID producer and candidate refresh

- VA `0x0050229E..0x005023C6`；raw `0x10169E..0x1017C6`；296 B；SHA256 `039adf04d50d013f4450a08ef2876ccf4b311f711f7bb4d2c670e266e8077911`。

```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0050229e <.data+0x10169e>:
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
  5023a2:	0f b7 7b 02          	movzx  edi,WORD PTR [ebx+0x2]
  5023a6:	8b b6 ac 5e 00 00    	mov    esi,DWORD PTR [esi+0x5eac]
  5023ac:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
  5023b2:	50                   	push   eax
  5023b3:	8d 85 50 ff ff ff    	lea    eax,[ebp-0xb0]
  5023b9:	8b ce                	mov    ecx,esi
  5023bb:	89 bd 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],edi
  5023c1:	e8 5a 19 00 00       	call   0x503d20
```

### event action0xF438A/F438B dispatcher

- VA `0x005B7F80..0x005B8020`；raw `0x1B7380..0x1B7420`；160 B；SHA256 `dda1cb9bb3d0d4ab424ca5c867b96264d5d5143ad249360349cc73c6286b587c`。

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
```

### mode2 event to QuestInfo lookup to TalkBox

- VA `0x005B6D20..0x005B6E43`；raw `0x1B6120..0x1B6243`；291 B；SHA256 `6672b73e6c89c2d3e162830481de1a498d1458f41123aaf0735e885384545d8e`。

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
  5b6e42:	8b             	mov    ecx,DWORD PTR [esp+0x20]
```

### TalkBox mode setup and mode2 jump case

- VA `0x00636520..0x0063670C`；raw `0x235920..0x235B0C`；492 B；SHA256 `316e233db3ae29095cb00c38289e884da7649199c459dd5258bbd429311a2541`。

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
  636630:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636636:	8b 11                	mov    edx,DWORD PTR [ecx]
  636638:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63663b:	ff d0                	call   eax
  63663d:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636643:	8b 11                	mov    edx,DWORD PTR [ecx]
  636645:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636648:	ff d0                	call   eax
  63664a:	e8 51 f6 ff ff       	call   0x635ca0
  63664f:	e9 b8 00 00 00       	jmp    0x63670c
  636654:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63665a:	8b 11                	mov    edx,DWORD PTR [ecx]
  63665c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63665f:	ff d0                	call   eax
  636661:	e8 ca 92 dd ff       	call   0x40f930
  636666:	8b c8                	mov    ecx,eax
  636668:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63666b:	e8 20 a9 ec ff       	call   0x500f90
  636670:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  636676:	3b c3                	cmp    eax,ebx
  636678:	74 73                	je     0x6366ed
  63667a:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  63667d:	51                   	push   ecx
  63667e:	8b c7                	mov    eax,edi
  636680:	e8 8b f8 ff ff       	call   0x635f10
  636685:	eb 72                	jmp    0x6366f9
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
```

### old false UI producer 0xF42EC and 0xF42EB

- VA `0x006391C0..0x0063925E`；raw `0x2385C0..0x23865E`；158 B；SHA256 `bdcd58215c829bf0d3d82156306281fba96206ff2dc15206055b8cfc57b7b62b`。

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
  63920e:	cc                   	int3
  63920f:	cc                   	int3
  639210:	56                   	push   esi
  639211:	6a 18                	push   0x18
  639213:	8b f1                	mov    esi,ecx
  639215:	e8 4e 80 25 00       	call   0x891268
  63921a:	83 c4 04             	add    esp,0x4
  63921d:	85 c0                	test   eax,eax
  63921f:	74 32                	je     0x639253
  639221:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  639224:	8b 89 84 00 00 00    	mov    ecx,DWORD PTR [ecx+0x84]
  63922a:	83 ca ff             	or     edx,0xffffffff
  63922d:	8b f0                	mov    esi,eax
  63922f:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  639232:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  639235:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  63923c:	c7 40 10 eb 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf42eb
  639243:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  639249:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  63924c:	e8 4f e0 dc ff       	call   0x4072a0
  639251:	5e                   	pop    esi
  639252:	c3                   	ret
  639253:	33 c0                	xor    eax,eax
  639255:	8b f0                	mov    esi,eax
  639257:	e8 44 e0 dc ff       	call   0x4072a0
  63925c:	5e                   	pop    esi
  63925d:	c3                   	ret
```

## 六、結論與提交限制

**Quest16-② Client 靜態有界完成。** 原版 Server 何時回覆、從 `0x003F` 或 `0x001C` 是否會直接造成 `0x0040`、NPC10027 實際 UI/遊玩結果均不可從現有 Client 原件作保證；它們是③④、Server/Spec 與待遊玩驗證，不是②再度無限期未完成的理由。

這份筆記為已存在且可驗證的正式 T16-121 提供**直接 BIN 複核、邊界勘誤與跨 Task 責任分派**；不重編原段號、不覆蓋舊報告、不將 T01 的 NEEDS_FIX 自行標 RESOLVED。
