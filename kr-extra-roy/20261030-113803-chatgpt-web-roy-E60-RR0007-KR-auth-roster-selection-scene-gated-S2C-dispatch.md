# E60 — KR T02 / RR-0007：S2C 登入／角色清單／選角的命令→場景 gate 與 Client 狀態（BIN-first）

> **完成分界**：本稿針對 T02「封包解碼→app lane→Client callback→第一層／場景兩層命令表」原生靜態路由作可審查的有界交付。T03 主責的「角色選擇批准／拒絕實際 Server 回應 opcode、角色／場景 writer 與首次教學」不能在沒有正向證據時由 T02 猜測補上。嚴禁把同數值 C2S `0x0042` 視為已證的 S2C 批准。`SUBMITTED` 不是 T01 FULL-PASS／S00 ACCEPTED／Server 實際可玩。


- 完成時間：`2026-10-30T11:38:03.898484+08:00`；研究者：`chatgpt-web roy`。
- 原件：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，唯讀；**未執行 Client、未模擬官方 Server、無 pcap**。
- KR PE `.text` VA `0x401000`, raw `0x400`；本檔 `.text` VA→raw=`VA−0x400C00`；`.rdata` VA→raw=`VA−0x401A00`，不可混用。以原始 BIN raw slice 定址後 `objdump`，未用任意指令中間位元組推定 call。
- 目標：`RR-0007` / KR T02 / `GAP-NET-0003`；開始基準 `main=8a7940560c73755a29ff48af3e00109f38f2b5b4`，已公開 CLAIMED 的 `main=3724d850231ef26b2a36984ac1c5bc3347c4d96d`；後續 Commit／RR 台帳狀態以遠端實際結果為準。
- 級別：**N** 為直接由本次原始指令／唯讀 vtable 證明，**C** 為有條件的靜態連接，**U** 為無法從此原件證明／跨 Task；不得將 C/U 提升為 live session 事實。


## 一、RR-0007 正式驗收問題與對應成果

唯一 RR 台帳 `question`：*Using already identified 0x4930E0 channel2 and CClient/scene handlers, identify exact S2C dispatch handlers and state prerequisites for authentication response, roster command2, and selection, without exhaustively tracing all commands.*  `acceptance_criteria` 另要求銜接 `0x2633/0x22D7`、`0x727190`、checksum 失敗與 pool 運作（此底層由 RR-0006/E59 完整原稿交叉引用，**本稿不重做該分析**）。

| 終點 | 有界原生結論 | 缺口／非本 Task 的承諾 |
|---|---|---|
| 接收後如何進 Client callback | N/C：`0x807B40→0x489920→0x8040A0→0x804740→0x80486D`，有效正長度、正確 lane/holder/vtable 才有 Client `0x4930E0` | 不代表固定 socket key 永遠對應此 holder，也不保證某次 Server 已發送 |
| `0x4930E0` gate | N：param3 非零、param4==2 才呼叫 `[Client+B8]` 的表 +4；其 virtual return==`0x100` 且 `Client+BE8C !=0` 才 return 1，其他 return 0 | 這是**callback 回傳布林 gate**，不是每個 handler 要求 BE8C 非零的前置 gate；`Client+B8` pointer identity 仍需保留實際配置條件 |
| 第一層 app command table | N：`0x494360→FD2CF8 vptr+4=0x4FDA30`，signed WORD index、stride8；index2→`0x4B7F00`，其他先看 table | 從 `0x4930E0` 到 `0x494360` 依 member dispatch/table identity 有條件；禁止省略此層 |
| 登入／選服資料 `0x0013` | N：第一層 default `0x4B7EC0` 需 active scene；登入 scene vptr+4=`0x4C4670` 且 scene 第二層 0x13=`0x4C37A0`；handler 的 `[buf+0x16]`==5、==0、其他值分支不同 | 業務意義不能以「全部都登入成功」代替；登入權威策略及完整 header/固定場景生命週期由 T03 |
| 選服資料 `0x007A` | N：登入場景 table 0x7A→`0x4C3C10`，從 `[buf+2]` 取 DWORD 並將 `buf+6` 傳給 `0x4C3080` | 能分派不代表原版 Server 初包一定 0x7A |
| 角色名單命令 `0x0002` | N：`FD2CF8+4+2*8 = FD2D0C` 安裝 `0x4B7F00`；會讀輸入更新狀態、呼叫 `0x4D4150` 填角色記錄，該 helper 寫 `record+5C=1` | 預設 slot override 不依附登入場景第二層；資料有效性及 UI 最終顯示仍須 T03/T04/T06 gate |
| 選角請求與回覆 | N：C2S 選角 producer `0x4A3B80` 建 `WORD 0x0042, byte index, byte mode`（T03-3 已驗局部，另本稿覆核）；第一層 scene 基底對**收到** S2C `0x0042` 的 handler 是 `0x4B2190`，讀 `WORD payload+2` 並可能處理尾部子項。 | **不能證明 S2C 0x0042 即 C2S 0x0042 的批准／拒絕回覆；`0x4B2190` 的副作用是 state/list updates，非已證選角轉場。** T03 RR-0002／RR-0008 專責真實選角回覆與場景 writer |

**核心結論**：收到有效 payload 的三個條件層不同。`0x0002` 於 `FD2CF8` 第一層直接命中專用 handler；`0x0013/0x007A` 經第一層 default 時，先需要一個 active scene，後需要與 `LOGI` scene vtable/次表相符；`0x0042` 雖在基底場景表有 handler，卻不足以判斷它就是選角確認。


## 二、完整控制／資料流與必要 gate

```text
TCP bytes (original Server/wire order U)
  → 0x806CF0 recv IOCP (full legal frame)
  → 0x807B40 (0x2633/0x0BBB/0x1A68/0x22D7; checksum / inflate)
       ├─ bad content: packet length zero → 0x804310 → 0x8076F0 buffer pool; NO business callback
       ├─ invalid outer length: parser failure (different IOCP branch)
       └─ good nonzero payload → 0x807E50 → 0x489920 → 0x8040A0 → FC10D0 (Conn+A080 lane)
  → app mainloop 0x804740 → virtual callback vptr[0] (when Client+0x148 vptr C05AEC: 0x4930E0)
  → 0x4930E0: buffer WORD read; n!=0, lane=2 → [Client+B8]->slot+4 function
  → [subject to Client callback table and object identity]
  → 0x494360 → FD2CF8 vtable C06EB4+4=0x4FDA30 (first-level signed-index table)
       ├─ command 0x0002 → 0x4B7F00 (global override, roster/state/setup)
       └─ generic command → 0x4B7EC0
             ├─ no [FD2CF8+0x5EAC] scene → log and return 0
             └─ active scene vptr+4; if installed login scene C072FC → 0x4C4670
                   ├─ second table command 0x0013 → 0x4C37A0
                   ├─ second table command 0x007A → 0x4C3C10
                   └─ absent second override → 0x4FDA30 applied to scene's BASE table
                        ├─ cmd 0x0042 → 0x4B2190 (base table direct override)
                        └─ others → explicitly registered base handler or default virtual+0xC
```

**注意指標層次**：`FD2CF8` 大物件的 `+5EAC` current-scene pointer 不是 `0x4C3220` 在「登入場景物件」內建立的 `+5EAC +cmd*8` 二層函式表，兩個不同 base pointers 的同 offset 不得混用。`C05AEC` 與 `C05AA4` 是不同 Client subobject vtable。`0x4FDA30` 的 +4/stride8 table 和 Client `0x48AAD0` 的 +8/stride16 table 也不可混用。


## 三、情境／狀態矩陣（N/C/U）

| Player action | Native dispatch condition | Data/scene effect | What an emulator/server may assert |
|---|---|---|---|
| 帳號登入取得伺服器資料 | 有效解碼、lane2 Client callback、有登入場景 active pointer、`0x13` 0x4C37A0 installed；命令 body+0x16 分支 | `buf+0x16==5` 走另一條狀態／通知／關閉 key1；`==0` 且 UTF-16 字串非空可經 `0x4C3080` 建 endpoint list；其他值為錯誤／中止處理 | 只推具條件的 Client 解析，不能把所有 `0x13` 都當成功或指定 Server 必先回此包 |
| 選服列表補充／切換 | active 登入場景 & handler index0x7A，`0x4C3C10` | `[buf+2]` DWORD、`buf+6` 交 choice parser `0x4C3080` | 非選角結果；與登入場景生命週期密切相關 |
| 角色列表／初期人物資料 | 第一層 table index2→`0x4B7F00`；必要的資料長度／內部欄位條件滿足，`0x4D4150` 可寫 record+0x5C=1 | `0x4B7F00` 大型資料／Client state、其他本地 C2S；`0x4D4150` 完成 record fields | `command=2` 的 role 不因場景第二表未註冊而失效；不能把 `0x4B7F00` 的全部 side effects 視為單純 roster |
| 玩家點選角色 | T03 UI 本地事件 type `0x70A` 且 record+5C、index gate；`0x4A3B80` sender 另受 FBA798 gate | C2S `42 00 index mode` 4B 本地 buffer 送 manager v+0x10 | 不代表 Server 一定回 42/43/69，不代表回覆已到達 |
| 收到具有 app command `0x0042` 的 S2C | first-level default、active login scene、scene secondary no override cmd0x42、base scene override `scene+0x214=0x4B2190` | read signed WORD payload+2, call `0x500110`; length>4 時按 payload[5] 小型 switch，有條件調 `0x53D840` 等資料操作 | 確認可存在 `0x42` 收訊 handler；**但不得將其稱為選角批准；未直接證轉場** |
| 收到 0x43 或其他候選 | base scene table 另有 index0x43→0x4B1A90；只確認其呼叫 0x40F060(6)→0x4DFD40 | 本地物件更新，未確立角色世界轉場 | 不能以 C2S 42 猜 S2C 43 是原版批准；T03 RR-0002/8 專責 |
| scene 不存在／非 LOGI | first-level default `0x4B7EC0` scene pointer null logs；其他 scene vptr+4 可能不同 | handler 不必命中 LOGI secondary 0x13/0x7A | 不可假定任何時刻 0x13/0x7A 都能更新當前畫面 |
| 解碼或 checksum 失敗 | `0x807B40` 令 packet 長度0、`0x804310→0x8076F0` recycle | 不進入 app command registry | 不可把「有封包抵達」等同「遊戲已處理登入回覆」 |

### 風險與反證

1. `0x4930E0` 在 `n!=0` 測試之前先讀 `[payload]` 的 `WORD`；該處局部沒有明確 `n>=2` guard。這是有界 native observation，不推定 exploitability；上游 packet assembly / IOCP 前置需另量證。
2. `0x4930E0` 只在 forwarding return==`0x100` 且 Client+BE8C nonzero 時回傳 1。這是 **回傳層的額外 gate**，不是呼叫 handler 之前普遍要求 BE8C 非零。若混淆會誤判合法封包遭拒。
3. `0x4B7EC0` active scene check 位於 generic path；第一層有直接 override 的 `0x0002` 不經過此 scene-null 檢查。`0x0013`／`0x007A` 只有當 active scene vtable 是 LOGI 之一才命中該 scene-specific handler。
4. `0x4C3220` 所有直接覆寫 index 是 `{0x13,0x35,0x7A,0x101,0x102,0x103,0x104,0x13B,0x13C,0x13D}`，**沒有 0x42**；但 `0x4ADD50` base table 確有 `0x42→0x4B2190`，不能因前者陰性就聲稱完全無 0x42 接收 handler（本輪重要勘誤）。
5. `0x4B2190` 的副作用為類似狀態／列表更新（`0x500110` 以 WORD 查 20-slot array 並插入；`0x53D840` 更新 0x18-byte record），並沒有 native 證據可把它等同玩家角色驗證成功後的場景切換。
6. C2S `0x0042` 是**已知玩家選角請求**；S2C `0x0042` 在另一接收 handler 出現，兩者**號碼重合不等於官方 request-response pairing**。


## 四、既有成果復用與其他 Task 邊界

- **RR-0006 E59**：`kr-extra-roy/20261030-112205-chatgpt-web-roy-E59-RR0006-compressed2633-22D7-decode-checksum-pool-IOCP.md`，Git blob `c7c1474b6b3cf928b8031e17fad7761c488d9b18`。用於 0x2633/0x22D7 frame、0x727190、checksum 失敗、`0x807E50` 與 app queue/pool 分界；不重複重驗整個壓縮器。
- **E54／E56（RR-0005）**：通用 recv app lane→callback 與 Connect key/slot/first-sender。已確認 socket 連線、mainloop send pump 與收包分派是不同時間的條件，不能用 local enqueue 推 Server response 實際次序。
- **E39（RR-0005）**：兩層 callback stride16/stride8 的證據。此輪新增 `C072FC` 實際 `.rdata` slot+4=`0x4C4670`，從 `0x4C2F...` LOGIN scene 建置到 `0x4B7D50` current-scene 指標，再到 base scene table `0x42→0x4B2190` 的反證，而不是只有候選 table address。
- **T03-3**：`kr-temp-roy/20261028-204757-chatgpt-web-roy-T03-3-command42-selection-callback.md`，僅引用 C2S `42 00 XX YY` UI/index/+5C/FBA798 gate，**不重做 UI semantics**。T03 RR-0002（selection response）、RR-0003（auth result consumer）與 RR-0008（scene key/first tutorial）均是本稿不自行認領的主責。T03 README 還存在 T01 `NEEDS_FIX` for old WSASend layout，不能引用其錯誤 offset 為定論。
- **S00**：`GAP-NET-0003` 可以採用本稿有限的消息分派前置與 unknown list，但在 `0x0042` 轉場／成功語意未以 Client native 實證之前，不得直接寫 normative Server response opcode、state transition 或 TEST fixture 為官方規則。

## 五、待證事項及精確解除條件

| 分類 | 未完成問題 | 已查範圍／如何解除 |
|---|---|---|
| Client 待逆向（跨 T03） | 真正玩家選角成功／失敗的 S2C opcode 和角色狀態／scene writer | 本輪逐一查 base scene `0x42/0x43`、登入 secondary 0x13/0x7a、T03-3 C2S 42，**仍無選角成功→轉場正向鏈**；由 T03 RR-0002/8 查其他 scene 與 callback 分支、釐清真正的結果 opcode |
| Client 待逆向（跨 T03） | 完整 auth payload 0x13 與登入狀態判定 | `0x4C37A0` 的 mode0、5、其他路徑已分離；無法從資料型別單獨推官方認證政策；T03 RR-0003 驗 handler payload 與 UI 消費者 |
| Client 局部待驗 | `Client+B8` 的函式表實例及其通往 `0x494360` 的動態唯一性 | `0x4930E0` 明確呼叫 `[[Client+B8]+4]`，其他表 `0x493170`/FD2CF8` 已驗；將兩表連成每種分支唯一入口需要實例 writer / virtual overrides 的限定查證，不能靠名稱假設 |
| Server 待開發 | 保持合法 frame、適合當前 scene 的 message/payload，並由 Server 決定登入／拒絕／選角的相容策略 | S00 應依原生有界 sender/consumer 建 DRAFT SPEC + GAP，未證 opcode 不作 MUST |
| 跨功能待整合 | T01 原生限定主張、T03 auth/selection、T04 roster、T05 scene | 使用精確 Git blob、原始 VA/CFG／異議交接，而不是覆蓋其他 Task 原稿 |
| 待遊玩驗證 | 原版 Server 實際回覆次序和切換時序 | 只有合法授權的 runtime+wire trace 可取得；無動態證據時不可宣稱 wire-first 或玩家完成登入 |

**研究狀態**：T02 可證的 `S2C command→scene handler` 有界靜態契約已閉合；非 T02 的 T03 選角批准／世界轉場仍未證，並以 RR-0002/8 交接。這是可供 S00/T01 審查的研究結果，不表示所有功能已可玩。無重大發現或固定子段停止規則，停止理由為本 RR 的**T02 dispatch gate 目標在可證範圍內已逐項回答**，餘項有明確其他 Task owner／原件證據限制。


## 附錄 A — 直接原生 BIN 指令（保留可重驗原始 bytes；以下每段均使用函式正確入口或已驗 CFG 分支）


### Queue consumer virtual callback and packet owner — VA `0x00804740..0x00804885`；raw `0x00403B40..0x00403C85`

```asm
  804740:	55                   	push   ebp
  804741:	8b ec                	mov    ebp,esp
  804743:	6a ff                	push   0xffffffff
  804745:	68 9c 9a 90 00       	push   0x909a9c
  80474a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  804750:	50                   	push   eax
  804751:	83 ec 4c             	sub    esp,0x4c
  804754:	53                   	push   ebx
  804755:	56                   	push   esi
  804756:	57                   	push   edi
  804757:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80475c:	33 c5                	xor    eax,ebp
  80475e:	50                   	push   eax
  80475f:	8d 45 f4             	lea    eax,[ebp-0xc]
  804762:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  804768:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80476b:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  804772:	75 27                	jne    0x80479b
  804774:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  80477b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804782:	e8 69 f8 ff ff       	call   0x803ff0
  804787:	68 90 dc bc 00       	push   0xbcdc90
  80478c:	e8 89 db 08 00       	call   0x89231a
  804791:	83 c4 04             	add    esp,0x4
  804794:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80479b:	a1 f0 11 fc 00       	mov    eax,ds:0xfc11f0
  8047a0:	6a 01                	push   0x1
  8047a2:	50                   	push   eax
  8047a3:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  8047aa:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  8047b0:	33 c0                	xor    eax,eax
  8047b2:	8d 7b 04             	lea    edi,[ebx+0x4]
  8047b5:	b9 0b 00 00 00       	mov    ecx,0xb
  8047ba:	8d 73 30             	lea    esi,[ebx+0x30]
  8047bd:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047bf:	89 45 a8             	mov    DWORD PTR [ebp-0x58],eax
  8047c2:	89 45 ac             	mov    DWORD PTR [ebp-0x54],eax
  8047c5:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  8047c8:	89 45 b4             	mov    DWORD PTR [ebp-0x4c],eax
  8047cb:	89 45 b8             	mov    DWORD PTR [ebp-0x48],eax
  8047ce:	89 45 bc             	mov    DWORD PTR [ebp-0x44],eax
  8047d1:	89 45 c0             	mov    DWORD PTR [ebp-0x40],eax
  8047d4:	89 45 c8             	mov    DWORD PTR [ebp-0x38],eax
  8047d7:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  8047da:	66 89 45 d0          	mov    WORD PTR [ebp-0x30],ax
  8047de:	b9 0b 00 00 00       	mov    ecx,0xb
  8047e3:	8d 75 a8             	lea    esi,[ebp-0x58]
  8047e6:	8d 7b 30             	lea    edi,[ebx+0x30]
  8047e9:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047eb:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8047f1:	ff d7                	call   edi
  8047f3:	8b 8b 84 00 00 00    	mov    ecx,DWORD PTR [ebx+0x84]
  8047f9:	89 43 30             	mov    DWORD PTR [ebx+0x30],eax
  8047fc:	2b 43 10             	sub    eax,DWORD PTR [ebx+0x10]
  8047ff:	8d 51 fc             	lea    edx,[ecx-0x4]
  804802:	3b c2                	cmp    eax,edx
  804804:	76 0d                	jbe    0x804813
  804806:	c7 45 ec 04 00 00 00 	mov    DWORD PTR [ebp-0x14],0x4
  80480d:	c6 43 58 01          	mov    BYTE PTR [ebx+0x58],0x1
  804811:	eb 03                	jmp    0x804816
  804813:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  804816:	33 f6                	xor    esi,esi
  804818:	89 73 50             	mov    DWORD PTR [ebx+0x50],esi
  80481b:	89 73 54             	mov    DWORD PTR [ebx+0x54],esi
  80481e:	ff d7                	call   edi
  804820:	89 43 38             	mov    DWORD PTR [ebx+0x38],eax
  804823:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  804826:	83 fe 02             	cmp    esi,0x2
  804829:	75 0c                	jne    0x804837
  80482b:	ff d7                	call   edi
  80482d:	89 43 40             	mov    DWORD PTR [ebx+0x40],eax
  804830:	c7 43 54 00 00 00 00 	mov    DWORD PTR [ebx+0x54],0x0
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  804841:	e8 ba f8 ff ff       	call   0x804100
  804846:	84 c0                	test   al,al
  804848:	0f 84 82 01 00 00    	je     0x8049d0
  80484e:	8b ff                	mov    edi,edi
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff d7                	call   edi
  804874:	2b 45 e8             	sub    eax,DWORD PTR [ebp-0x18]
  804877:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  80487a:	8b f8                	mov    edi,eax
  80487c:	8b 03                	mov    eax,DWORD PTR [ebx]
  80487e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  804881:	57                   	push   edi
  804882:	56                   	push   esi
  804883:	51                   	push   ecx
  804884:	8b                 	mov    ecx,ebx
```


### Client+0x148 virtual entry lane/return gates — VA `0x004930E0..0x00493160`；raw `0x000924E0..0x00092560`

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10              	ret    0x10
```


### Client callback table registration and special overrides — VA `0x00493170..0x00493281`；raw `0x00092570..0x00092681`

```asm
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
  493180:	be d5 0b 00 00       	mov    esi,0xbd5
  493185:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  49318a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  493190:	89 7a f8             	mov    DWORD PTR [edx-0x8],edi
  493193:	89 5a fc             	mov    DWORD PTR [edx-0x4],ebx
  493196:	89 0a                	mov    DWORD PTR [edx],ecx
  493198:	83 c2 10             	add    edx,0x10
  49319b:	4e                   	dec    esi
  49319c:	75 f2                	jne    0x493190
  49319e:	ba 80 47 49 00       	mov    edx,0x494780
  4931a3:	89 90 98 03 00 00    	mov    DWORD PTR [eax+0x398],edx
  4931a9:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931ae:	89 90 48 10 00 00    	mov    DWORD PTR [eax+0x1048],edx
  4931b4:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931b9:	89 90 c8 03 00 00    	mov    DWORD PTR [eax+0x3c8],edx
  4931bf:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931c4:	89 90 08 04 00 00    	mov    DWORD PTR [eax+0x408],edx
  4931ca:	ba 60 48 49 00       	mov    edx,0x494860
  4931cf:	89 90 38 04 00 00    	mov    DWORD PTR [eax+0x438],edx
  4931d5:	ba 90 4a 49 00       	mov    edx,0x494a90
  4931da:	89 90 48 04 00 00    	mov    DWORD PTR [eax+0x448],edx
  4931e0:	ba d0 4c 49 00       	mov    edx,0x494cd0
  4931e5:	89 90 f8 04 00 00    	mov    DWORD PTR [eax+0x4f8],edx
  4931eb:	ba 50 47 49 00       	mov    edx,0x494750
  4931f0:	89 90 78 09 00 00    	mov    DWORD PTR [eax+0x978],edx
  4931f6:	ba f0 59 49 00       	mov    edx,0x4959f0
  4931fb:	89 90 a8 0f 00 00    	mov    DWORD PTR [eax+0xfa8],edx
  493201:	ba 60 5a 49 00       	mov    edx,0x495a60
  493206:	89 90 28 0f 00 00    	mov    DWORD PTR [eax+0xf28],edx
  49320c:	ba b0 43 49 00       	mov    edx,0x4943b0
  493211:	89 90 08 09 00 00    	mov    DWORD PTR [eax+0x908],edx
  493217:	ba b0 43 49 00       	mov    edx,0x4943b0
  49321c:	89 90 98 04 00 00    	mov    DWORD PTR [eax+0x498],edx
  493222:	ba b0 43 49 00       	mov    edx,0x4943b0
  493227:	89 90 e8 03 00 00    	mov    DWORD PTR [eax+0x3e8],edx
  49322d:	ba b0 43 49 00       	mov    edx,0x4943b0
  493232:	89 90 48 06 00 00    	mov    DWORD PTR [eax+0x648],edx
  493238:	ba b0 43 49 00       	mov    edx,0x4943b0
  49323d:	89 90 a8 04 00 00    	mov    DWORD PTR [eax+0x4a8],edx
  493243:	ba b0 43 49 00       	mov    edx,0x4943b0
  493248:	89 90 c8 04 00 00    	mov    DWORD PTR [eax+0x4c8],edx
  49324e:	ba b0 43 49 00       	mov    edx,0x4943b0
  493253:	89 90 18 15 00 00    	mov    DWORD PTR [eax+0x1518],edx
  493259:	ba b0 43 49 00       	mov    edx,0x4943b0
  49325e:	89 90 d8 04 00 00    	mov    DWORD PTR [eax+0x4d8],edx
  493264:	ba b0 43 49 00       	mov    edx,0x4943b0
  493269:	89 90 18 08 00 00    	mov    DWORD PTR [eax+0x818],edx
  49326f:	ba b0 43 49 00       	mov    edx,0x4943b0
  493274:	89 90 68 08 00 00    	mov    DWORD PTR [eax+0x868],edx
  49327a:	89 b0 9c 03 00 00    	mov    DWORD PTR [eax+0x39c],esi
  493280:	89         	mov    DWORD PTR [eax+0x3a0],ecx
```


### FD2CF8 first-level redirect — VA `0x00494360..0x004943AC`；raw `0x00093760..0x000937AC`

```asm
  494360:	55                   	push   ebp
  494361:	8b ec                	mov    ebp,esp
  494363:	b8 01 00 00 00       	mov    eax,0x1
  494368:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  49436e:	75 2c                	jne    0x49439c
  494370:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  494376:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  49437d:	6e c0 00 
  494380:	c7 05 a4 8b fd 00 00 	mov    DWORD PTR ds:0xfd8ba4,0x0
  494387:	00 00 00 
  49438a:	e8 31 3a 02 00       	call   0x4b7dc0
  49438f:	68 f0 dc bc 00       	push   0xbcdcf0
  494394:	e8 81 df 3f 00       	call   0x89231a
  494399:	83 c4 04             	add    esp,0x4
  49439c:	b9 f8 2c fd 00       	mov    ecx,0xfd2cf8
  4943a1:	a1 f8 2c fd 00       	mov    eax,ds:0xfd2cf8
  4943a6:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4943a9:	5d                   	pop    ebp
  4943aa:	ff e2                	jmp    edx
```


### First-level signed word index dispatch — VA `0x004FDA30..0x004FDAB3`；raw `0x000FCE30..0x000FCEB3`

```asm
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
  4fdab0:	c2 0c 00             	ret    0xc
```


### Global first-level registration index2 — VA `0x004B7DC0..0x004B7E20`；raw `0x000B71C0..0x000B7220`

```asm
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7       	mov    DWORD PTR ds:0xfd306c,0x4b9260
  4b7e26:	   
```


### Global default current-scene gate — VA `0x004B7EC0..0x004B7EF2`；raw `0x000B72C0..0x000B72F2`

```asm
  4b7ec0:	55                   	push   ebp
  4b7ec1:	8b ec                	mov    ebp,esp
  4b7ec3:	83 b9 ac 5e 00 00 00 	cmp    DWORD PTR [ecx+0x5eac],0x0
  4b7eca:	74 0e                	je     0x4b7eda
  4b7ecc:	8b 89 ac 5e 00 00    	mov    ecx,DWORD PTR [ecx+0x5eac]
  4b7ed2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7ed4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b7ed7:	5d                   	pop    ebp
  4b7ed8:	ff e0                	jmp    eax
  4b7eda:	0f bf 4d 10          	movsx  ecx,WORD PTR [ebp+0x10]
  4b7ede:	51                   	push   ecx
  4b7edf:	68 f8 6d c0 00       	push   0xc06df8
  4b7ee4:	e8 77 5c 23 00       	call   0x6edb60
  4b7ee9:	83 c4 08             	add    esp,0x8
  4b7eec:	33 c0                	xor    eax,eax
  4b7eee:	5d                   	pop    ebp
  4b7eef:	c2 0c 00             	ret    0xc
```


### LOGI scene object construction + second table registration call — VA `0x004C2F50..0x004C2FDA`；raw `0x000C2350..0x000C23DA`

```asm
  4c2f50:	6a 03                	push   0x3
  4c2f52:	57                   	push   edi
  4c2f53:	57                   	push   edi
  4c2f54:	50                   	push   eax
  4c2f55:	ff d2                	call   edx
  4c2f57:	68 5c bd 00 00       	push   0xbd5c
  4c2f5c:	e8 07 e3 3c 00       	call   0x891268
  4c2f61:	8b f0                	mov    esi,eax
  4c2f63:	83 c4 04             	add    esp,0x4
  4c2f66:	3b f7                	cmp    esi,edi
  4c2f68:	74 28                	je     0x4c2f92
  4c2f6a:	e8 e1 ad fe ff       	call   0x4add50
  4c2f6f:	c7 06 fc 72 c0 00    	mov    DWORD PTR [esi],0xc072fc
  4c2f75:	89 be 54 bd 00 00    	mov    DWORD PTR [esi+0xbd54],edi
  4c2f7b:	89 be 58 bd 00 00    	mov    DWORD PTR [esi+0xbd58],edi
  4c2f81:	c7 05 74 a6 d6 00 49 	mov    DWORD PTR ds:0xd6a674,0x4c4f4749
  4c2f88:	47 4f 4c 
  4c2f8b:	e8 90 02 00 00       	call   0x4c3220
  4c2f90:	eb 02                	jmp    0x4c2f94
  4c2f92:	33 f6                	xor    esi,esi
  4c2f94:	b8 01 00 00 00       	mov    eax,0x1
  4c2f99:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  4c2f9f:	75 28                	jne    0x4c2fc9
  4c2fa1:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  4c2fa7:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  4c2fae:	6e c0 00 
  4c2fb1:	89 3d a4 8b fd 00    	mov    DWORD PTR ds:0xfd8ba4,edi
  4c2fb7:	e8 04 4e ff ff       	call   0x4b7dc0
  4c2fbc:	68 f0 dc bc 00       	push   0xbcdcf0
  4c2fc1:	e8 54 f3 3c 00       	call   0x89231a
  4c2fc6:	83 c4 04             	add    esp,0x4
  4c2fc9:	8b fe                	mov    edi,esi
  4c2fcb:	be f8 2c fd 00       	mov    esi,0xfd2cf8
  4c2fd0:	e8 7b 4d ff ff       	call   0x4b7d50
  4c2fd5:	5f                   	pop    edi
  4c2fd6:	33 c0                	xor    eax,eax
  4c2fd8:	5e                   	pop    esi
  4c2fd9:	c3                   	ret
```


### Active-scene replacement/activation lifecycle — VA `0x004B7D50..0x004B7DC0`；raw `0x000B7150..0x000B71C0`

```asm
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret
```


### Scene second-level 0x13/0x7A/0x101-0x13D registration — VA `0x004C3220..0x004C32DC`；raw `0x000C2620..0x000C26DC`

```asm
  4c3220:	68 a8 5e 00 00       	push   0x5ea8
  4c3225:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c322b:	6a 00                	push   0x0
  4c322d:	50                   	push   eax
  4c322e:	e8 2d b6 3d 00       	call   0x89e860
  4c3233:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c3238:	83 c4 0c             	add    esp,0xc
  4c323b:	c7 86 44 5f 00 00 a0 	mov    DWORD PTR [esi+0x5f44],0x4c37a0
  4c3242:	37 4c 00 
  4c3245:	89 86 48 5f 00 00    	mov    DWORD PTR [esi+0x5f48],eax
  4c324b:	c7 86 54 60 00 00 90 	mov    DWORD PTR [esi+0x6054],0x4c3b90
  4c3252:	3b 4c 00 
  4c3255:	89 86 58 60 00 00    	mov    DWORD PTR [esi+0x6058],eax
  4c325b:	c7 86 7c 62 00 00 10 	mov    DWORD PTR [esi+0x627c],0x4c3c10
  4c3262:	3c 4c 00 
  4c3265:	89 86 80 62 00 00    	mov    DWORD PTR [esi+0x6280],eax
  4c326b:	c7 86 b4 66 00 00 10 	mov    DWORD PTR [esi+0x66b4],0x4c3d10
  4c3272:	3d 4c 00 
  4c3275:	89 86 b8 66 00 00    	mov    DWORD PTR [esi+0x66b8],eax
  4c327b:	c7 86 bc 66 00 00 30 	mov    DWORD PTR [esi+0x66bc],0x4c3c30
  4c3282:	3c 4c 00 
  4c3285:	89 86 c0 66 00 00    	mov    DWORD PTR [esi+0x66c0],eax
  4c328b:	c7 86 84 68 00 00 b0 	mov    DWORD PTR [esi+0x6884],0x4c3fb0
  4c3292:	3f 4c 00 
  4c3295:	89 86 88 68 00 00    	mov    DWORD PTR [esi+0x6888],eax
  4c329b:	c7 86 cc 66 00 00 60 	mov    DWORD PTR [esi+0x66cc],0x4c4160
  4c32a2:	41 4c 00 
  4c32a5:	89 86 d0 66 00 00    	mov    DWORD PTR [esi+0x66d0],eax
  4c32ab:	c7 86 c4 66 00 00 90 	mov    DWORD PTR [esi+0x66c4],0x4c4090
  4c32b2:	40 4c 00 
  4c32b5:	89 86 c8 66 00 00    	mov    DWORD PTR [esi+0x66c8],eax
  4c32bb:	c7 86 8c 68 00 00 f0 	mov    DWORD PTR [esi+0x688c],0x4c3df0
  4c32c2:	3d 4c 00 
  4c32c5:	89 86 90 68 00 00    	mov    DWORD PTR [esi+0x6890],eax
  4c32cb:	c7 86 94 68 00 00 d0 	mov    DWORD PTR [esi+0x6894],0x4c3ed0
  4c32d2:	3e 4c 00 
  4c32d5:	89 86 98 68 00 00    	mov    DWORD PTR [esi+0x6898],eax
  4c32db:	c3                   	ret
```


### Login scene second-table dispatch and base fallback — VA `0x004C4670..0x004C46F0`；raw `0x000C3A70..0x000C3AF0`

```asm
  4c4670:	55                   	push   ebp
  4c4671:	8b ec                	mov    ebp,esp
  4c4673:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c4676:	53                   	push   ebx
  4c4677:	56                   	push   esi
  4c4678:	57                   	push   edi
  4c4679:	0f bf f8             	movsx  edi,ax
  4c467c:	8b f1                	mov    esi,ecx
  4c467e:	8b 9c fe ac 5e 00 00 	mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
  4c4685:	85 db                	test   ebx,ebx
  4c4687:	75 17                	jne    0x4c46a0
  4c4689:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c468c:	50                   	push   eax
  4c468d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c4690:	50                   	push   eax
  4c4691:	51                   	push   ecx
  4c4692:	8b ce                	mov    ecx,esi
  4c4694:	e8 97 93 03 00       	call   0x4fda30
  4c4699:	5f                   	pop    edi
  4c469a:	5e                   	pop    esi
  4c469b:	5b                   	pop    ebx
  4c469c:	5d                   	pop    ebp
  4c469d:	c2 0c 00             	ret    0xc
  4c46a0:	8b 94 fe b0 5e 00 00 	mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
  4c46a7:	6a 06                	push   0x6
  4c46a9:	68 6c 6c bf 00       	push   0xbf6c6c
  4c46ae:	52                   	push   edx
  4c46af:	e8 0a e2 3c 00       	call   0x8928be
  4c46b4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c46b7:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4c46ba:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c46bd:	83 c4 0c             	add    esp,0xc
  4c46c0:	50                   	push   eax
  4c46c1:	51                   	push   ecx
  4c46c2:	52                   	push   edx
  4c46c3:	8b ce                	mov    ecx,esi
  4c46c5:	ff d3                	call   ebx
  4c46c7:	8b d8                	mov    ebx,eax
  4c46c9:	81 fb 05 40 00 80    	cmp    ebx,0x80004005
  4c46cf:	75 16                	jne    0x4c46e7
  4c46d1:	8b 84 fe b0 5e 00 00 	mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
  4c46d8:	50                   	push   eax
  4c46d9:	57                   	push   edi
  4c46da:	68 74 6c bf 00       	push   0xbf6c74
  4c46df:	e8 7c 94 22 00       	call   0x6edb60
  4c46e4:	83 c4 0c             	add    esp,0xc
  4c46e7:	5f                   	pop    edi
  4c46e8:	5e                   	pop    esi
  4c46e9:	8b c3                	mov    eax,ebx
  4c46eb:	5b                   	pop    ebx
  4c46ec:	5d                   	pop    ebp
  4c46ed:	c2 0c 00             	ret    0xc
```


### Login command0x13 data-dependent branches — VA `0x004C37A0..0x004C38A6`；raw `0x000C2BA0..0x000C2CA6`

```asm
  4c37a0:	55                   	push   ebp
  4c37a1:	8b ec                	mov    ebp,esp
  4c37a3:	6a ff                	push   0xffffffff
  4c37a5:	68 3c 07 94 00       	push   0x94073c
  4c37aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c37b0:	50                   	push   eax
  4c37b1:	81 ec 4c 04 00 00    	sub    esp,0x44c
  4c37b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c37bc:	33 c5                	xor    eax,ebp
  4c37be:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4c37c1:	53                   	push   ebx
  4c37c2:	56                   	push   esi
  4c37c3:	57                   	push   edi
  4c37c4:	50                   	push   eax
  4c37c5:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c37c8:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c37ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c37d1:	33 db                	xor    ebx,ebx
  4c37d3:	8d 46 20             	lea    eax,[esi+0x20]
  4c37d6:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c37dc:	89 8d b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],ecx
  4c37e2:	66 39 18             	cmp    WORD PTR [eax],bx
  4c37e5:	74 3a                	je     0x4c3821
  4c37e7:	8b 15 08 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba808
  4c37ed:	53                   	push   ebx
  4c37ee:	53                   	push   ebx
  4c37ef:	68 00 04 00 00       	push   0x400
  4c37f4:	8d 8d f0 fb ff ff    	lea    ecx,[ebp-0x410]
  4c37fa:	51                   	push   ecx
  4c37fb:	6a ff                	push   0xffffffff
  4c37fd:	50                   	push   eax
  4c37fe:	53                   	push   ebx
  4c37ff:	52                   	push   edx
  4c3800:	ff 15 cc 21 bd 00    	call   DWORD PTR ds:0xbd21cc
  4c3806:	6a 32                	push   0x32
  4c3808:	8d 85 f0 fb ff ff    	lea    eax,[ebp-0x410]
  4c380e:	50                   	push   eax
  4c380f:	68 97 00 00 00       	push   0x97
  4c3814:	68 00 a7 fb 00       	push   0xfba700
  4c3819:	e8 cd 20 3d 00       	call   0x8958eb
  4c381e:	83 c4 10             	add    esp,0x10
  4c3821:	8a 56 16             	mov    dl,BYTE PTR [esi+0x16]
  4c3824:	80 fa 05             	cmp    dl,0x5
  4c3827:	0f 85 1c 01 00 00    	jne    0x4c3949
  4c382d:	6a 34                	push   0x34
  4c382f:	e8 34 da 3c 00       	call   0x891268
  4c3834:	8b f8                	mov    edi,eax
  4c3836:	83 c4 04             	add    esp,0x4
  4c3839:	89 bd b0 fb ff ff    	mov    DWORD PTR [ebp-0x450],edi
  4c383f:	33 c0                	xor    eax,eax
  4c3841:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4c3844:	3b f8                	cmp    edi,eax
  4c3846:	74 4a                	je     0x4c3892
  4c3848:	33 c9                	xor    ecx,ecx
  4c384a:	50                   	push   eax
  4c384b:	66 89 8d b8 fb ff ff 	mov    WORD PTR [ebp-0x448],cx
  4c3852:	68 fc d1 be 00       	push   0xbed1fc
  4c3857:	8d 8d b8 fb ff ff    	lea    ecx,[ebp-0x448]
  4c385d:	c7 85 cc fb ff ff 07 	mov    DWORD PTR [ebp-0x434],0x7
  4c3864:	00 00 00 
  4c3867:	89 85 c8 fb ff ff    	mov    DWORD PTR [ebp-0x438],eax
  4c386d:	e8 ee e8 f3 ff       	call   0x402160
  4c3872:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4c3876:	0f be 4e 16          	movsx  ecx,BYTE PTR [esi+0x16]
  4c387a:	8d 95 b8 fb ff ff    	lea    edx,[ebp-0x448]
  4c3880:	52                   	push   edx
  4c3881:	bb 01 00 00 00       	mov    ebx,0x1
  4c3886:	57                   	push   edi
  4c3887:	89 9d ac fb ff ff    	mov    DWORD PTR [ebp-0x454],ebx
  4c388d:	e8 6e 06 29 00       	call   0x753f00
  4c3892:	50                   	push   eax
  4c3893:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  4c389a:	e8 b1 71 0c 00       	call   0x58aa50
  4c389f:	83 ce ff             	or     esi,0xffffffff
  4c38a2:	83 c4 04             	add    esp,0x4
  4c38a5:	89               	mov    DWORD PTR [ebp-0x4],esi
```


### Login command0x13 nonzero string path — VA `0x004C3949..0x004C3A30`；raw `0x000C2D49..0x000C2E30`

```asm
  4c3949:	84 d2                	test   dl,dl
  4c394b:	0f 85 df 00 00 00    	jne    0x4c3a30
  4c3951:	8d 7e 02             	lea    edi,[esi+0x2]
  4c3954:	8b c7                	mov    eax,edi
  4c3956:	8d 48 02             	lea    ecx,[eax+0x2]
  4c3959:	89 8d a8 fb ff ff    	mov    DWORD PTR [ebp-0x458],ecx
  4c395f:	90                   	nop
  4c3960:	66 8b 08             	mov    cx,WORD PTR [eax]
  4c3963:	83 c0 02             	add    eax,0x2
  4c3966:	66 85 c9             	test   cx,cx
  4c3969:	75 f5                	jne    0x4c3960
  4c396b:	2b 85 a8 fb ff ff    	sub    eax,DWORD PTR [ebp-0x458]
  4c3971:	d1 f8                	sar    eax,1
  4c3973:	0f 84 b7 00 00 00    	je     0x4c3a30
  4c3979:	8b 5e 18             	mov    ebx,DWORD PTR [esi+0x18]
  4c397c:	e8 1f 12 f4 ff       	call   0x404ba0
  4c3981:	89 98 e0 67 00 00    	mov    DWORD PTR [eax+0x67e0],ebx
  4c3987:	e8 14 12 f4 ff       	call   0x404ba0
  4c398c:	85 ff                	test   edi,edi
  4c398e:	74 13                	je     0x4c39a3
  4c3990:	6a 0a                	push   0xa
  4c3992:	57                   	push   edi
  4c3993:	05 e4 67 00 00       	add    eax,0x67e4
  4c3998:	6a 0b                	push   0xb
  4c399a:	50                   	push   eax
  4c399b:	e8 5e 06 3d 00       	call   0x893ffe
  4c39a0:	83 c4 10             	add    esp,0x10
  4c39a3:	0f b6 7e 17          	movzx  edi,BYTE PTR [esi+0x17]
  4c39a7:	e8 f4 11 f4 ff       	call   0x404ba0
  4c39ac:	89 b8 b4 68 00 00    	mov    DWORD PTR [eax+0x68b4],edi
  4c39b2:	8a 9e 90 00 00 00    	mov    bl,BYTE PTR [esi+0x90]
  4c39b8:	e8 e3 11 f4 ff       	call   0x404ba0
  4c39bd:	88 98 b0 68 00 00    	mov    BYTE PTR [eax+0x68b0],bl
  4c39c3:	8a 96 86 00 00 00    	mov    dl,BYTE PTR [esi+0x86]
  4c39c9:	8b 9e 8c 00 00 00    	mov    ebx,DWORD PTR [esi+0x8c]
  4c39cf:	88 95 b4 fb ff ff    	mov    BYTE PTR [ebp-0x44c],dl
  4c39d5:	e8 c6 11 f4 ff       	call   0x404ba0
  4c39da:	8b f8                	mov    edi,eax
  4c39dc:	8a 85 b4 fb ff ff    	mov    al,BYTE PTR [ebp-0x44c]
  4c39e2:	8d 8e 87 00 00 00    	lea    ecx,[esi+0x87]
  4c39e8:	51                   	push   ecx
  4c39e9:	8d 97 99 68 00 00    	lea    edx,[edi+0x6899]
  4c39ef:	6a 05                	push   0x5
  4c39f1:	52                   	push   edx
  4c39f2:	88 87 98 68 00 00    	mov    BYTE PTR [edi+0x6898],al
  4c39f8:	e8 5c 01 3d 00       	call   0x893b59
  4c39fd:	89 9f a0 68 00 00    	mov    DWORD PTR [edi+0x68a0],ebx
  4c3a03:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
  4c3a06:	83 c4 0c             	add    esp,0xc
  4c3a09:	50                   	push   eax
  4c3a0a:	8d 8e 92 00 00 00    	lea    ecx,[esi+0x92]
  4c3a10:	e8 6b f6 ff ff       	call   0x4c3080
  4c3a15:	80 be 90 00 00 00 00 	cmp    BYTE PTR [esi+0x90],0x0
  4c3a1c:	75 0b                	jne    0x4c3a29
  4c3a1e:	8b bd b0 fb ff ff    	mov    edi,DWORD PTR [ebp-0x450]
  4c3a24:	e8 47 f7 ff ff       	call   0x4c3170
  4c3a29:	33 c0                	xor    eax,eax
  4c3a2b:	e9 34 01 00 00       	jmp    0x4c3b64
```


### Login command0x13 error shutdown — VA `0x004C3B30..0x004C3B82`；raw `0x000C2F30..0x000C2F82`

```asm
  4c3b30:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  4c3b36:	3b cf                	cmp    ecx,edi
  4c3b38:	74 08                	je     0x4c3b42
  4c3b3a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c3b3c:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4c3b3f:	57                   	push   edi
  4c3b40:	ff d2                	call   edx
  4c3b42:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4c3b48:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c3b4a:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4c3b4d:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  4c3b53:	6a 01                	push   0x1
  4c3b55:	6a 01                	push   0x1
  4c3b57:	ff d2                	call   edx
  4c3b59:	b8 05 40 00 80       	mov    eax,0x80004005
  4c3b5e:	89 be 60 bf 00 00    	mov    DWORD PTR [esi+0xbf60],edi
  4c3b64:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c3b67:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c3b6e:	59                   	pop    ecx
  4c3b6f:	5f                   	pop    edi
  4c3b70:	5e                   	pop    esi
  4c3b71:	5b                   	pop    ebx
  4c3b72:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4c3b75:	33 cd                	xor    ecx,ebp
  4c3b77:	e8 85 d4 3c 00       	call   0x891001
  4c3b7c:	8b e5                	mov    esp,ebp
  4c3b7e:	5d                   	pop    ebp
  4c3b7f:	c2 0c 00             	ret    0xc
```


### Login scene 0x7A parser delegate — VA `0x004C3C10..0x004C3C29`；raw `0x000C3010..0x000C3029`

```asm
  4c3c10:	55                   	push   ebp
  4c3c11:	8b ec                	mov    ebp,esp
  4c3c13:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c3c16:	8b 48 02             	mov    ecx,DWORD PTR [eax+0x2]
  4c3c19:	51                   	push   ecx
  4c3c1a:	8d 48 06             	lea    ecx,[eax+0x6]
  4c3c1d:	e8 5e f4 ff ff       	call   0x4c3080
  4c3c22:	33 c0                	xor    eax,eax
  4c3c24:	5d                   	pop    ebp
  4c3c25:	c2 0c 00             	ret    0xc
  4c3c28:	cc                   	int3
```


### First-level command0x02 roster handler entry — VA `0x004B7F00..0x004B7F9F`；raw `0x000B7300..0x000B739F`

```asm
  4b7f00:	55                   	push   ebp
  4b7f01:	8b ec                	mov    ebp,esp
  4b7f03:	83 e4 f8             	and    esp,0xfffffff8
  4b7f06:	6a ff                	push   0xffffffff
  4b7f08:	68 86 4d 94 00       	push   0x944d86
  4b7f0d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b7f13:	50                   	push   eax
  4b7f14:	83 ec 68             	sub    esp,0x68
  4b7f17:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b7f1c:	33 c4                	xor    eax,esp
  4b7f1e:	89 44 24 60          	mov    DWORD PTR [esp+0x60],eax
  4b7f22:	53                   	push   ebx
  4b7f23:	56                   	push   esi
  4b7f24:	57                   	push   edi
  4b7f25:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b7f2a:	33 c4                	xor    eax,esp
  4b7f2c:	50                   	push   eax
  4b7f2d:	8d 44 24 78          	lea    eax,[esp+0x78]
  4b7f31:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b7f37:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4b7f3a:	33 db                	xor    ebx,ebx
  4b7f3c:	83 ce ff             	or     esi,0xffffffff
  4b7f3f:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b7f46:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  4b7f4a:	75 27                	jne    0x4b7f73
  4b7f4c:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b7f53:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  4b7f5a:	e8 31 96 02 00       	call   0x4e1590
  4b7f5f:	68 80 cc bc 00       	push   0xbccc80
  4b7f64:	e8 b1 a3 3d 00       	call   0x89231a
  4b7f69:	83 c4 04             	add    esp,0x4
  4b7f6c:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b7f73:	33 c0                	xor    eax,eax
  4b7f75:	66 89 44 24 34       	mov    WORD PTR [esp+0x34],ax
  4b7f7a:	b8 8c 38 f9 00       	mov    eax,0xf9388c
  4b7f7f:	c7 44 24 48 07 00 00 	mov    DWORD PTR [esp+0x48],0x7
  4b7f86:	00 
  4b7f87:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  4b7f8b:	8d 50 02             	lea    edx,[eax+0x2]
  4b7f8e:	8b ff                	mov    edi,edi
  4b7f90:	66 8b 08             	mov    cx,WORD PTR [eax]
  4b7f93:	83 c0 02             	add    eax,0x2
  4b7f96:	66 3b cb             	cmp    cx,bx
  4b7f99:	75 f5                	jne    0x4b7f90
  4b7f9b:	2b c2                	sub    eax,edx
  4b7f9d:	d1 f8                	sar    eax,1
```


### Roster item writer 0x4D4150 — VA `0x004D4150..0x004D419D`；raw `0x000D3550..0x000D359D`

```asm
  4d4150:	57                   	push   edi
  4d4151:	8d 7e 0c             	lea    edi,[esi+0xc]
  4d4154:	c7 46 5c 01 00 00 00 	mov    DWORD PTR [esi+0x5c],0x1
  4d415b:	8b c2                	mov    eax,edx
  4d415d:	2b fa                	sub    edi,edx
  4d415f:	90                   	nop
  4d4160:	0f b7 08             	movzx  ecx,WORD PTR [eax]
  4d4163:	66 89 0c 07          	mov    WORD PTR [edi+eax*1],cx
  4d4167:	83 c0 02             	add    eax,0x2
  4d416a:	66 85 c9             	test   cx,cx
  4d416d:	75 f1                	jne    0x4d4160
  4d416f:	0f b6 42 2e          	movzx  eax,BYTE PTR [edx+0x2e]
  4d4173:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  4d4176:	0f b6 4a 2f          	movzx  ecx,BYTE PTR [edx+0x2f]
  4d417a:	89 8e d4 00 00 00    	mov    DWORD PTR [esi+0xd4],ecx
  4d4180:	0f b6 42 30          	movzx  eax,BYTE PTR [edx+0x30]
  4d4184:	89 86 dc 00 00 00    	mov    DWORD PTR [esi+0xdc],eax
  4d418a:	8b 4a 31             	mov    ecx,DWORD PTR [edx+0x31]
  4d418d:	89 4e 50             	mov    DWORD PTR [esi+0x50],ecx
  4d4190:	8b 52 2a             	mov    edx,DWORD PTR [edx+0x2a]
  4d4193:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  4d4196:	b8 01 00 00 00       	mov    eax,0x1
  4d419b:	5f                   	pop    edi
  4d419c:	c3                   	ret
```


### Roster writer use inside first-level command2 — VA `0x004B89A0..0x004B89B6`；raw `0x000B7DA0..0x000B7DB6`

```asm
  4b89a0:	03 05 04 43 f9 00    	add    eax,DWORD PTR ds:0xf94304
  4b89a6:	74 0d                	je     0x4b89b5
  4b89a8:	8d 57 d2             	lea    edx,[edi-0x2e]
  4b89ab:	8b f0                	mov    esi,eax
  4b89ad:	e8 9e b7 01 00       	call   0x4d4150
  4b89b2:	83 ce ff             	or     esi,0xffffffff
  4b89b5:	f6       	test   BYTE PTR ds:0xfb1314,0x1
```


### Alternative roster item count and 0x35 stride — VA `0x004E2730..0x004E2799`；raw `0x000E1B30..0x000E1B99`

```asm
  4e2730:	55                   	push   ebp
  4e2731:	8b ec                	mov    ebp,esp
  4e2733:	51                   	push   ecx
  4e2734:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4e2737:	56                   	push   esi
  4e2738:	8b f1                	mov    esi,ecx
  4e273a:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4e273d:	83 f8 02             	cmp    eax,0x2
  4e2740:	73 04                	jae    0x4e2746
  4e2742:	33 c9                	xor    ecx,ecx
  4e2744:	eb 13                	jmp    0x4e2759
  4e2746:	8d 48 fe             	lea    ecx,[eax-0x2]
  4e2749:	b8 b3 cf 21 35       	mov    eax,0x3521cfb3
  4e274e:	f7 e1                	mul    ecx
  4e2750:	2b ca                	sub    ecx,edx
  4e2752:	d1 e9                	shr    ecx,1
  4e2754:	03 ca                	add    ecx,edx
  4e2756:	c1 e9 05             	shr    ecx,0x5
  4e2759:	85 c9                	test   ecx,ecx
  4e275b:	74 35                	je     0x4e2792
  4e275d:	53                   	push   ebx
  4e275e:	57                   	push   edi
  4e275f:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4e2762:	83 c7 02             	add    edi,0x2
  4e2765:	8b d9                	mov    ebx,ecx
  4e2767:	0f b6 47 2e          	movzx  eax,BYTE PTR [edi+0x2e]
  4e276b:	83 f8 09             	cmp    eax,0x9
  4e276e:	77 1a                	ja     0x4e278a
  4e2770:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  4e2776:	03 86 24 69 00 00    	add    eax,DWORD PTR [esi+0x6924]
  4e277c:	74 0c                	je     0x4e278a
  4e277e:	8b d7                	mov    edx,edi
  4e2780:	8b f0                	mov    esi,eax
  4e2782:	e8 c9 19 ff ff       	call   0x4d4150
  4e2787:	8b 75 fc             	mov    esi,DWORD PTR [ebp-0x4]
  4e278a:	83 c7 35             	add    edi,0x35
  4e278d:	4b                   	dec    ebx
  4e278e:	75 d7                	jne    0x4e2767
  4e2790:	5f                   	pop    edi
  4e2791:	5b                   	pop    ebx
  4e2792:	8b ce                	mov    ecx,esi
  4e2794:	e8 17 38 00 00       	call   0x4e5fb0
```


### Base scene table initialization default — VA `0x004ADD50..0x004ADD6F`；raw `0x000AD150..0x000AD16F`

```asm
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
```


### Base scene table command0x42/0x43 overrides — VA `0x004ADF2D..0x004ADF60`；raw `0x000AD32D..0x000AD360`

```asm
  4adf2d:	c7 80 c4 01 00 00 f0 	mov    DWORD PTR [eax+0x1c4],0x4b1bf0
  4adf34:	1b 4b 00 
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
  4adf5d:	c7 80 fc     	mov    DWORD PTR [eax+0x3fc],0x4b23c0
  4adf64:	   
```


### S2C command0x42 base handler state/list logic — VA `0x004B2190..0x004B22DC`；raw `0x000B1590..0x000B16DC`

```asm
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
  4b2278:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b227f:	75 29                	jne    0x4b22aa
  4b2281:	b8 01 00 00 00       	mov    eax,0x1
  4b2286:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b228c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b2290:	e8 fb c9 02 00       	call   0x4dec90
  4b2295:	68 30 ce bc 00       	push   0xbcce30
  4b229a:	e8 7b 00 3e 00       	call   0x89231a
  4b229f:	83 c4 04             	add    esp,0x4
  4b22a2:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b22a9:	ff 
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b22d3:	59                   	pop    ecx
  4b22d4:	5f                   	pop    edi
  4b22d5:	5e                   	pop    esi
  4b22d6:	5b                   	pop    ebx
  4b22d7:	8b e5                	mov    esp,ebp
  4b22d9:	5d                   	pop    ebp
  4b22da:	c2 0c              	ret    0xc
```


### S2C command0x42 state WORD insertion helper — VA `0x00500110..0x00500153`；raw `0x000FF510..0x000FF553`

```asm
  500110:	33 c0                	xor    eax,eax
  500112:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500118:	53                   	push   ebx
  500119:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  500120:	0f b7 19             	movzx  ebx,WORD PTR [ecx]
  500123:	3b de                	cmp    ebx,esi
  500125:	74 2a                	je     0x500151
  500127:	40                   	inc    eax
  500128:	83 c1 02             	add    ecx,0x2
  50012b:	83 f8 14             	cmp    eax,0x14
  50012e:	7c f0                	jl     0x500120
  500130:	33 c0                	xor    eax,eax
  500132:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500138:	66 83 39 00          	cmp    WORD PTR [ecx],0x0
  50013c:	74 0b                	je     0x500149
  50013e:	40                   	inc    eax
  50013f:	83 c1 02             	add    ecx,0x2
  500142:	83 f8 14             	cmp    eax,0x14
  500145:	7c f1                	jl     0x500138
  500147:	5b                   	pop    ebx
  500148:	c3                   	ret
  500149:	66 89 b4 47 d0 5e 00 	mov    WORD PTR [edi+eax*2+0x5ed0],si
  500150:	00 
  500151:	5b                   	pop    ebx
  500152:	c3                   	ret
```


### S2C command0x42 tail item consumer 0x18 byte records — VA `0x0053D840..0x0053D907`；raw `0x0013CC40..0x0013CD07`

```asm
  53d840:	55                   	push   ebp
  53d841:	8b ec                	mov    ebp,esp
  53d843:	83 ec 18             	sub    esp,0x18
  53d846:	53                   	push   ebx
  53d847:	57                   	push   edi
  53d848:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d84b:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  53d84e:	2b 4f 10             	sub    ecx,DWORD PTR [edi+0x10]
  53d851:	83 c7 10             	add    edi,0x10
  53d854:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  53d859:	f7 e9                	imul   ecx
  53d85b:	c1 fa 02             	sar    edx,0x2
  53d85e:	8b c2                	mov    eax,edx
  53d860:	c1 e8 1f             	shr    eax,0x1f
  53d863:	03 c2                	add    eax,edx
  53d865:	b9 00 00 00 00       	mov    ecx,0x0
  53d86a:	74 28                	je     0x53d894
  53d86c:	8b 17                	mov    edx,DWORD PTR [edi]
  53d86e:	0f b7 5e 04          	movzx  ebx,WORD PTR [esi+0x4]
  53d872:	83 c2 02             	add    edx,0x2
  53d875:	66 39 1a             	cmp    WORD PTR [edx],bx
  53d878:	74 0c                	je     0x53d886
  53d87a:	41                   	inc    ecx
  53d87b:	83 c2 18             	add    edx,0x18
  53d87e:	3b c8                	cmp    ecx,eax
  53d880:	72 f3                	jb     0x53d875
  53d882:	33 c9                	xor    ecx,ecx
  53d884:	eb 0e                	jmp    0x53d894
  53d886:	8b 07                	mov    eax,DWORD PTR [edi]
  53d888:	8d 0c 49             	lea    ecx,[ecx+ecx*2]
  53d88b:	8d 04 c8             	lea    eax,[eax+ecx*8]
  53d88e:	33 c9                	xor    ecx,ecx
  53d890:	3b c1                	cmp    eax,ecx
  53d892:	75 22                	jne    0x53d8b6
  53d894:	33 d2                	xor    edx,edx
  53d896:	8d 45 e8             	lea    eax,[ebp-0x18]
  53d899:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53d89c:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  53d89f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  53d8a2:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  53d8a5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  53d8a8:	e8 43 ac 0b 00       	call   0x5f84f0
  53d8ad:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53d8b0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  53d8b3:	83 e8 18             	sub    eax,0x18
  53d8b6:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  53d8ba:	66 89 48 14          	mov    WORD PTR [eax+0x14],cx
  53d8be:	0f b6 56 01          	movzx  edx,BYTE PTR [esi+0x1]
  53d8c2:	66 89 50 04          	mov    WORD PTR [eax+0x4],dx
  53d8c6:	0f b6 4e 02          	movzx  ecx,BYTE PTR [esi+0x2]
  53d8ca:	66 89 08             	mov    WORD PTR [eax],cx
  53d8cd:	0f b7 56 04          	movzx  edx,WORD PTR [esi+0x4]
  53d8d1:	66 89 50 02          	mov    WORD PTR [eax+0x2],dx
  53d8d5:	0f b6 4e 03          	movzx  ecx,BYTE PTR [esi+0x3]
  53d8d9:	88 48 0a             	mov    BYTE PTR [eax+0xa],cl
  53d8dc:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d8e0:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d8e3:	0f b6 0e             	movzx  ecx,BYTE PTR [esi]
  53d8e6:	88 48 0b             	mov    BYTE PTR [eax+0xb],cl
  53d8e9:	80 3e 02             	cmp    BYTE PTR [esi],0x2
  53d8ec:	75 08                	jne    0x53d8f6
  53d8ee:	ba ff 00 00 00       	mov    edx,0xff
  53d8f3:	66 89 10             	mov    WORD PTR [eax],dx
  53d8f6:	0f b6 4e 01          	movzx  ecx,BYTE PTR [esi+0x1]
  53d8fa:	49                   	dec    ecx
  53d8fb:	83 f9 0a             	cmp    ecx,0xa
  53d8fe:	0f 87 3b 01 00 00    	ja     0x53da3f
  53d904:	ff 24 8d     	jmp    DWORD PTR [ecx*4+0x53da48]
```


### S2C command0x43 base handler limited native behavior — VA `0x004B1A90..0x004B1AA3`；raw `0x000B0E90..0x000B0EA3`

```asm
  4b1a90:	6a 06                	push   0x6
  4b1a92:	e8 c9 d5 f5 ff       	call   0x40f060
  4b1a97:	8b c8                	mov    ecx,eax
  4b1a99:	e8 a2 e2 02 00       	call   0x4dfd40
  4b1a9e:	33 c0                	xor    eax,eax
  4b1aa0:	c2 0c 00             	ret    0xc
```


### C2S command0x42 payload builder for comparison only — VA `0x004A3B80..0x004A3C08`；raw `0x000A2F80..0x000A3008`

```asm
  4a3b80:	55                   	push   ebp
  4a3b81:	8b ec                	mov    ebp,esp
  4a3b83:	51                   	push   ecx
  4a3b84:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3b8b:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3b8e:	8a 55 0c             	mov    dl,BYTE PTR [ebp+0xc]
  4a3b91:	b8 42 00 00 00       	mov    eax,0x42
  4a3b96:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4a3b9a:	88 4d fe             	mov    BYTE PTR [ebp-0x2],cl
  4a3b9d:	88 55 ff             	mov    BYTE PTR [ebp-0x1],dl
  4a3ba0:	75 15                	jne    0x4a3bb7
  4a3ba2:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3ba8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4a3baa:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4a3bad:	6a 04                	push   0x4
  4a3baf:	8d 55 fc             	lea    edx,[ebp-0x4]
  4a3bb2:	52                   	push   edx
  4a3bb3:	6a 00                	push   0x0
  4a3bb5:	ff d0                	call   eax
  4a3bb7:	8b e5                	mov    esp,ebp
  4a3bb9:	5d                   	pop    ebp
  4a3bba:	c2 08 00             	ret    0x8
  4a3bbd:	cc                   	int3
  4a3bbe:	cc                   	int3
  4a3bbf:	cc                   	int3
  4a3bc0:	55                   	push   ebp
  4a3bc1:	8b ec                	mov    ebp,esp
  4a3bc3:	51                   	push   ecx
  4a3bc4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3bcb:	b8 44 00 00 00       	mov    eax,0x44
  4a3bd0:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  4a3bd4:	75 15                	jne    0x4a3beb
  4a3bd6:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a3bdc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a3bde:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a3be1:	6a 02                	push   0x2
  4a3be3:	8d 45 fe             	lea    eax,[ebp-0x2]
  4a3be6:	50                   	push   eax
  4a3be7:	6a 00                	push   0x0
  4a3be9:	ff d2                	call   edx
  4a3beb:	8b e5                	mov    esp,ebp
  4a3bed:	5d                   	pop    ebp
  4a3bee:	c3                   	ret
  4a3bef:	cc                   	int3
  4a3bf0:	55                   	push   ebp
  4a3bf1:	8b ec                	mov    ebp,esp
  4a3bf3:	83 ec 0c             	sub    esp,0xc
  4a3bf6:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a3bfd:	8a 4d 08             	mov    cl,BYTE PTR [ebp+0x8]
  4a3c00:	8a 55 0c             	mov    dl,BYTE PTR [ebp+0xc]
  4a3c03:	b8 a1 00 00 00       	mov    eax,0xa1
```
