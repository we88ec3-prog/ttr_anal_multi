# T03-9 — KR 接收佇列 reader → 工作迴圈虛擬 callback 的原生鏈（選角回包仍未配對）

- 研究者：chatgpt-web roy；日期：2026-10-28T22:55:22.296776+08:00。
- KR 原始 `Tartaros.bin`：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪實際讀檔重新 SHA256）；PE `.text` VA `0x401000`、raw `0x400`，故 `.text` raw=VA−`0x400C00`；`.rdata` VA `0xBD2000`、raw `0x7D0600`。
- 僅離線讀取原始機器碼、以 GNU objdump x86 反組譯；沒有執行客戶端、連線、伺服器程式或修改原始 EXE/BIN。以下無符號 C++ 物件功能名稱是研究暫稱，不是原版類名。
- 研究承接：T03-7 接收解框及 T03-8 的 `0x807E50` 後兩種中繼 lane。原稿 `kr-temp-roy/20261028-224903-chatgpt-web-roy-T03-8-recv-staging-two-lanes.md`，不能因本輪新下游線索就將兩 lane 合成同一 business opcode 域。

## 摘要：本輪重大新增證據

**原始機器碼直接建立 `0xFC10D0` lane 的 reader → callback：** `0x804841 call 0x804100` 回傳成功時 `0x804852` 取得 record；`0x80485F/0x804864/0x804868` 將 `record+4`、`record+8`、`record+0` 搬到引數；`0x804858..0x80486D` 由 `worker` 的 vtable **offset+0** 執行間接業務 callback。隨後 `0x80487C..0x804886` 呼叫同 vtable `+0xC`，且大於 `0x28` 的耗時另有 vtable `+0x8` 分支。失敗後 `0x8049B2` 重試同一 reader。因此 T03-8 的「只有 writer 沒有 reader」缺口已縮為**具體 worker 與虛擬 callback 交界**。但 worker 具體型別／vtable 實作、回覆 opcode/length 與 T03 業務路由仍待找，不可認定這一定是 command 42 的回包。

另一路 `0xFE3358`：解框直接呼叫 `0x8075B0` 作 `0x100C` 節點配置／checkout，又呼叫 `0x8076F0` 把引用節點寫入佇列並計數；對 `.text` 逐 byte 搜尋 `E8 rel32` 僅見 `0x807D97→0x8076F0`，**未查得直接的應用 reader**，不能因名稱或相近位置誤標為 user-level poll。

## 第一輪 T03-9：完整、可界定 reader→worker 鏈

### 1. FC10D0 lane 的 writer、reader 與 virtual consumer

- 先前已核 `0x807D9E`（以 record+4 不為 0 作 lane gate）→ `0x489920` 取得 `0xFC10D0` → `0x8040A0` 將資料寫入 lane 的分桶容器。**該 gate `record+4` 是 receiver intermediate record field，不能當作角色記錄 offset+4。**
- 新增 `0x804841`、`0x8049B2` 是 `call 0x804100` 唯二在 `.text` 的直接 `E8` 引用（原始 rel32 搜尋，待動態間接 caller 補充）；它們都以 `EAX=0xFC10D0`、stack `[ebp-0x10]` 作 record output、`[ebp+8]` 作另一選擇參數。`0x804100` 成功返回 `AL=1`，取值後更新 queue 數；失敗在 `0x804196` 走 lane fallback／`0x804253` 返回 0。
- `0x804858: mov edx,[ebx]`、`0x80485A: mov edx,[edx]`、`0x80486D: call edx` 是確實的**虛擬 dispatch**，且 `EBX` 必須是 worker object（證據僅到指標/表；class identity 不能猜）。
- callback 入參依實際 push 順序：`push [ebp+8]`（選擇值）、`push [record+4]`、`push &record[8]`、`push [record]`；`ECX=EBX`。所以同一 record 提供至少 4 個入參來源；不能用 `record[0]` 直接當 wire opcode 而不追 target。
- callback 後用計時值呼叫 vtable `+0xC`，高於 `0x28` 另呼叫 vtable `+0x8`，這是 worker telemetry / 其他副作用的**候選**；具體語意未知。

### 2. 另一 lane 的 checkout / return 不是業務 handler

- `0x807B40` 在 decode 期間 `0x807C81 call 0x8075B0`；後者空槽時配置 `0x100C`，清空 0x1000 payload、保留 `+0x1008` 序號，將節點指標存入內部 container。
- `0x807D97 call 0x8076F0` 前置 `EDI=0xFE3358`，後者先將 record output 的兩個 dword 清零，再以同一同步物件鎖住、將節點指標 enqueue。這是「返回給容器」而非業務 callback；已查的唯一直接 caller 位於解框流程，且只證明讀取應用的下游仍有缺口。

### 3. 玩家情境矩陣

| 玩家情境 | C→S | S→C transport | 中繼路徑 | 下一 consumer | UI/場景結果 | 等級 |
|---|---|---|---|---|---|---|
| 選角確認、command 42 | T03-3 `42 00 XX YY`，有多個 gate | T03-6/7 通用 WSARecv/解框，**未綁定到該請求** | 若 receive record+4 != 0，`0xFC10D0` lane | 本輪確證 `0x804100→worker vtable+0` 的**一般資料** consumer | 選角批准／拒絕未知；無法定位到特定虛擬 target | 部分確認 |
| 接收 record+4 = 0 | 不適用 | 符合解框條件的資料 | `0xFE3358` 佇列 | 本輪僅確認節點 checkout/enqueue，尚未有業務 worker | 未知 | 部分確認 |
| FC10D0 reader 無資料 | 不適用 | 不適用 | 選定 bucket 為空 | `0x804100` 失敗；`0x8049B2` 可重試 | 沒有證據可說是伺服器拒絕 | 原生已確認（bounded） |

## 第二輪 T03-9-2：上游、失敗路徑與實際 callback 引數

對 `.text` 中 direct E8 rel32 的目標掃描，以及對 `0x804820..0x8048A5` CFG 分支重新核對：`0x804841` 成功才進行下游 vtable callback；`0x8049B2` 在未處理時重新嘗試同一入口。`0x8040A0` writer 會檢查 flag `byte[EDI + EBX + 0x128]`，再依 `3*(2*EBX+condition)*8` 選 `EDI+offset`，該 bucket 和 reader `0x804100` 的 bucket 選擇需保留 byte flag / channel index 意義分離。沒有成功找到實際 callback 實作的符號或 vtable 常數（本輪限制），不冒充已還原 handler。

## 第三輪 T03-9-3：兩 lane 交叉驗證與反證界線

重新檢查 `0x807C81`、`0x807D97` 及 `0x8076F0` 的 raw `E8` 即時相對位移，並掃描直接 caller。結果是 FC10D0 lane 有確實 worker callback，而 FE3358 的出列業務 consumer **尚未定位**。本輪不把 `0x807470` 的 free slot checkout 認作 S→C dispatcher，也不將 `0x804260` 通用 deque helper 的其他 87 個 callsite 當角色業務相關。屬界線分明的新進展，達重大門檻。

## 待解決事項（T03-10 優先）

1. 定位 `0x804820` 所屬 worker 物件 `EBX` 的 vtable 寫入指令，還原 vtable `+0/+8/+C` 實際 target，再追發送 opcode/長度的分派與 T03 roster/selection 特定 callback。
2. 補齊 `0xFE3358` lane 的 application-side reader / 事件 loop；不能因只找 direct calls 沒看到就推斷程式沒有間接 poll。
3. 對真實 command `0x42` 找 S→C 批准／拒絕結果、Client state writer、T05 轉場交接；若缺 Server capture，保留 unknown。
4. T02 仍是 transport/framing 主責；T03 僅界定到達業務 handler 的介面，不更動其他 task owner/catalog；T04/T05/T06 資料權威、場景、UI 資源不接管。

## 此次未做及完整性聲明

- 未執行或修改原始程式；沒有 Server 程式、封包擷取、原版結果碼；只證實目前可見 native Client 動態分派位置。
- 沒有把 `0xFC10D0`、`0xFE3358` 全域位址或 transport magic 當 wire opcode；未知虛擬 callback 不命名為角色確認。
- 第一、二、三輪均實際進行；停止是因已確認較前段新增的 bounded reader→worker virtual consumer，不是達成「T03 可遊玩」驗收。

## 原始 Assembly 證據（對本輪實際讀取 BIN 的 GNU objdump 輸出；VA/節範圍如上）

### Queue buffer checkout/allocate (0x8075B0)

```asm
  8075b0:	55                   	push   ebp
  8075b1:	8b ec                	mov    ebp,esp
  8075b3:	8b 47 58             	mov    eax,DWORD PTR [edi+0x58]
  8075b6:	83 ec 10             	sub    esp,0x10
  8075b9:	53                   	push   ebx
  8075ba:	56                   	push   esi
  8075bb:	50                   	push   eax
  8075bc:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8075c2:	83 7f 4c 00          	cmp    DWORD PTR [edi+0x4c],0x0
  8075c6:	0f 85 8e 00 00 00    	jne    0x80765a
  8075cc:	33 db                	xor    ebx,ebx
  8075ce:	8b ff                	mov    edi,edi
  8075d0:	68 0c 10 00 00       	push   0x100c
  8075d5:	e8 8e 9c 08 00       	call   0x891268
  8075da:	8b f0                	mov    esi,eax
  8075dc:	33 c0                	xor    eax,eax
  8075de:	83 c4 04             	add    esp,0x4
  8075e1:	3b f0                	cmp    esi,eax
  8075e3:	74 1f                	je     0x807604
  8075e5:	68 00 10 00 00       	push   0x1000
  8075ea:	50                   	push   eax
  8075eb:	8d 4e 08             	lea    ecx,[esi+0x8]
  8075ee:	51                   	push   ecx
  8075ef:	89 06                	mov    DWORD PTR [esi],eax
  8075f1:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  8075f4:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  8075fa:	e8 61 72 09 00       	call   0x89e860
  8075ff:	83 c4 0c             	add    esp,0xc
  807602:	eb 02                	jmp    0x807606
  807604:	33 f6                	xor    esi,esi
  807606:	8b 47 2c             	mov    eax,DWORD PTR [edi+0x2c]
  807609:	8d 50 01             	lea    edx,[eax+0x1]
  80760c:	89 57 2c             	mov    DWORD PTR [edi+0x2c],edx
  80760f:	89         	mov    DWORD PTR [esi+0x1008],eax
```

### Queue buffer check-in (0x8076F0)

```asm
  8076f0:	55                   	push   ebp
  8076f1:	8b ec                	mov    ebp,esp
  8076f3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8076f6:	c7 00 00 00 00 00    	mov    DWORD PTR [eax],0x0
  8076fc:	c7 40 04 00 00 00 00 	mov    DWORD PTR [eax+0x4],0x0
  807703:	8b 47 58             	mov    eax,DWORD PTR [edi+0x58]
  807706:	56                   	push   esi
  807707:	50                   	push   eax
  807708:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80770e:	8d 4d 08             	lea    ecx,[ebp+0x8]
  807711:	51                   	push   ecx
  807712:	8d 77 3c             	lea    esi,[edi+0x3c]
  807715:	e8 46 cb ff ff       	call   0x804260
  80771a:	8b 57 58             	mov    edx,DWORD PTR [edi+0x58]
  80771d:	ff 4f 54             	dec    DWORD PTR [edi+0x54]
  807720:	52                   	push   edx
  807721:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807727:	5e                   	pop    esi
  807728:	5d                   	pop    ebp
  807729:	c2               	ret    0x4
```

### Decoded delivery and lane selection

```asm
  807d7a:	e8 d1 00 00 00       	call   0x807e50
  807d7f:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  807d83:	83 78 04 00          	cmp    DWORD PTR [eax+0x4],0x0
  807d87:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  807d8b:	89 08                	mov    DWORD PTR [eax],ecx
  807d8d:	75 0f                	jne    0x807d9e
  807d8f:	50                   	push   eax
  807d90:	e8 7b c5 ff ff       	call   0x804310
  807d95:	8b f8                	mov    edi,eax
  807d97:	e8 54 f9 ff ff       	call   0x8076f0
  807d9c:	eb 14                	jmp    0x807db2
  807d9e:	8b 89 80 a0 00 00    	mov    ecx,DWORD PTR [ecx+0xa080]
  807da4:	51                   	push   ecx
  807da5:	50                   	push   eax
  807da6:	e8 75 1b c8 ff       	call   0x489920
  807dab:	8b f8                	mov    edi,eax
  807dad:	e8 ee c2 ff ff       	call   0x8040a0
  807db2:	0f b7 13             	movzx  edx,WORD PTR [ebx]
  807db5:	03 54 24 20          	add    edx,DWORD PTR [esp+0x20]
  807db9:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  807dbd:	8b 80 00 50 00 00    	mov    eax,DWORD PTR [eax+0x5000]
  807dc3:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  807dc7:	03 da                	add    ebx,edx
  807dc9:	2b c3                	sub    eax,ebx
  807dcb:	83 f8 04             	cmp    eax,0x4
  807dce:	0f 83 dc fd ff ff    	jae    0x807bb0
```

### FC10D0 reader slot selection (0x804100)

```asm
  804100:	55                   	push   ebp
  804101:	8b ec                	mov    ebp,esp
  804103:	83 ec 0c             	sub    esp,0xc
  804106:	53                   	push   ebx
  804107:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  80410a:	56                   	push   esi
  80410b:	8b f0                	mov    esi,eax
  80410d:	8a 8c 33 28 01 00 00 	mov    cl,BYTE PTR [ebx+esi*1+0x128]
  804114:	0f b6 c1             	movzx  eax,cl
  804117:	8d 14 1b             	lea    edx,[ebx+ebx*1]
  80411a:	03 c2                	add    eax,edx
  80411c:	8d 04 40             	lea    eax,[eax+eax*2]
  80411f:	83 7c c6 10 00       	cmp    DWORD PTR [esi+eax*8+0x10],0x0
  804124:	57                   	push   edi
  804125:	8d 3c c6             	lea    edi,[esi+eax*8]
  804128:	89 55 0c             	mov    DWORD PTR [ebp+0xc],edx
  80412b:	74 69                	je     0x804196
  80412d:	8d 45 f4             	lea    eax,[ebp-0xc]
  804130:	8b cf                	mov    ecx,edi
  804132:	e8 d9 e0 d3 ff       	call   0x542210
  804137:	8b 08                	mov    ecx,DWORD PTR [eax]
  804139:	33 db                	xor    ebx,ebx
  80413b:	3b cb                	cmp    ecx,ebx
  80413d:	75 04                	jne    0x804143
  80413f:	33 d2                	xor    edx,edx
  804141:	eb 02                	jmp    0x804145
  804143:	8b 11                	mov    edx,DWORD PTR [ecx]
  804145:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  804148:	8b 72 08             	mov    esi,DWORD PTR [edx+0x8]
  80414b:	8b c1                	mov    eax,ecx
  80414d:	c1 e8 02             	shr    eax,0x2
  804150:	83 e1 03             	and    ecx,0x3
  804153:	3b f0                	cmp    esi,eax
  804155:	77 02                	ja     0x804159
  804157:	2b c6                	sub    eax,esi
  804159:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  80415c:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  80415f:	8b 0c 88             	mov    ecx,DWORD PTR [eax+ecx*4]
  804162:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
```

### Worker callback dispatch and alternate vtable paths (0x804820)

```asm
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
  804884:	8b cb                	mov    ecx,ebx
  804886:	ff d2                	call   edx
  804888:	83 ff 28             	cmp    edi,0x28
  80488b:	76 16                	jbe    0x8048a3
  80488d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804890:	8b 03                	mov    eax,DWORD PTR [ebx]
  804892:	8b 93 8c 00 00 00    	mov    edx,DWORD PTR [ebx+0x8c]
  804898:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  80489b:	57                   	push   edi
  80489c:	56                   	push   esi
  80489d:	51                   	push   ecx
  80489e:	52                   	push   edx
  80489f:	8b cb                	mov    ecx,ebx
  8048a1:	ff d0                	call   eax
  8048a3:	f6 05      	test   BYTE PTR ds:0xfe3354,0x1
```

### Worker retry / poll

```asm
  80499a:	75 03                	jne    0x80499f
  80499c:	01 73 54             	add    DWORD PTR [ebx+0x54],esi
  80499f:	83 7d e4 00          	cmp    DWORD PTR [ebp-0x1c],0x0
  8049a3:	75 22                	jne    0x8049c7
  8049a5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8049a8:	50                   	push   eax
  8049a9:	8d 4d f0             	lea    ecx,[ebp-0x10]
  8049ac:	51                   	push   ecx
  8049ad:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  8049b2:	e8 49 f7 ff ff       	call   0x804100
  8049b7:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8049bd:	84 c0                	test   al,al
  8049bf:	0f 85 8b fe ff ff    	jne    0x804850
  8049c5:	eb 06                	jmp    0x8049cd
```

### FC10D0 writer

```asm
  8040a0:	55                   	push   ebp
  8040a1:	8b ec                	mov    ebp,esp
  8040a3:	8b 87 24 01 00 00    	mov    eax,DWORD PTR [edi+0x124]
  8040a9:	53                   	push   ebx
  8040aa:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8040ad:	56                   	push   esi
  8040ae:	50                   	push   eax
  8040af:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8040b5:	33 d2                	xor    edx,edx
  8040b7:	38 94 3b 28 01 00 00 	cmp    BYTE PTR [ebx+edi*1+0x128],dl
  8040be:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8040c1:	0f 94 c2             	sete   dl
  8040c4:	51                   	push   ecx
  8040c5:	8d 04 5a             	lea    eax,[edx+ebx*2]
  8040c8:	8d 04 40             	lea    eax,[eax+eax*2]
  8040cb:	8d 34 c7             	lea    esi,[edi+eax*8]
  8040ce:	e8 8d 01 00 00       	call   0x804260
  8040d3:	8b 8f 24 01 00 00    	mov    ecx,DWORD PTR [edi+0x124]
  8040d9:	51                   	push   ecx
  8040da:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8040e0:	5e                   	pop    esi
  8040e1:	83 fb 02             	cmp    ebx,0x2
  8040e4:	5b                   	pop    ebx
  8040e5:	75 0d                	jne    0x8040f4
  8040e7:	8b 97 20 01 00 00    	mov    edx,DWORD PTR [edi+0x120]
  8040ed:	52                   	push   edx
  8040ee:	ff 15 d0 20 bd 00    	call   DWORD PTR ds:0xbd20d0
  8040f4:	5d                   	pop    ebp
  8040f5:	c2 08 00             	ret    0x8
```

### FE3358 queue node insertion

```asm
  807470:	55                   	push   ebp
  807471:	8b ec                	mov    ebp,esp
  807473:	8b 47 28             	mov    eax,DWORD PTR [edi+0x28]
  807476:	83 ec 10             	sub    esp,0x10
  807479:	53                   	push   ebx
  80747a:	56                   	push   esi
  80747b:	50                   	push   eax
  80747c:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  807482:	83 7f 1c 00          	cmp    DWORD PTR [edi+0x1c],0x0
  807486:	0f 85 8d 00 00 00    	jne    0x807519
  80748c:	33 db                	xor    ebx,ebx
  80748e:	8b ff                	mov    edi,edi
  807490:	68 0c 10 00 00       	push   0x100c
  807495:	e8 ce 9d 08 00       	call   0x891268
  80749a:	8b f0                	mov    esi,eax
  80749c:	33 c0                	xor    eax,eax
  80749e:	83 c4 04             	add    esp,0x4
  8074a1:	3b f0                	cmp    esi,eax
  8074a3:	74 1f                	je     0x8074c4
  8074a5:	68 00 10 00 00       	push   0x1000
  8074aa:	50                   	push   eax
  8074ab:	8d 4e 08             	lea    ecx,[esi+0x8]
  8074ae:	51                   	push   ecx
  8074af:	89 06                	mov    DWORD PTR [esi],eax
  8074b1:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  8074b4:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  8074ba:	e8 a1 73 09 00       	call   0x89e860
  8074bf:	83 c4 0c             	add    esp,0xc
  8074c2:	eb 02                	jmp    0x8074c6
  8074c4:	33 f6                	xor    esi,esi
  8074c6:	8b 47 2c             	mov    eax,DWORD PTR [edi+0x2c]
  8074c9:	8d 50 01             	lea    edx,[eax+0x1]
  8074cc:	89 57 2c             	mov    DWORD PTR [edi+0x2c],edx
  8074cf:	89 86 08 10 00 00    	mov    DWORD PTR [esi+0x1008],eax
  8074d5:	8d 45 fc             	lea    eax,[ebp-0x4]
  8074d8:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  8074db:	50                   	push   eax
  8074dc:	8d 77 0c             	lea    esi,[edi+0xc]
  8074df:	e8 7c cd ff ff       	call   0x804260
  8074e4:	8b                 	mov    esi,DWORD PTR [edi]
```

### FE3358 queue initialisation

```asm
  807148:	33 f6                	xor    esi,esi
  80714a:	6a 0c                	push   0xc
  80714c:	c7 45 e8 58 33 fe 00 	mov    DWORD PTR [ebp-0x18],0xfe3358
  807153:	89 35 5c 33 fe 00    	mov    DWORD PTR ds:0xfe335c,esi
  807159:	e8 0a a1 08 00       	call   0x891268
  80715e:	83 c4 04             	add    esp,0x4
  807161:	3b c6                	cmp    eax,esi
  807163:	0f 84 b1 01 00 00    	je     0x80731a
  807169:	a3 58 33 fe 00       	mov    ds:0xfe3358,eax
  80716e:	89 00                	mov    DWORD PTR [eax],eax
  807170:	a1 58 33 fe 00       	mov    eax,ds:0xfe3358
  807175:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  807178:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  80717b:	6a 08                	push   0x8
  80717d:	89 35 64 33 fe 00    	mov    DWORD PTR ds:0xfe3364,esi
  807183:	e8 e0 a0 08 00       	call   0x891268
  807188:	83 c4 04             	add    esp,0x4
  80718b:	3b c6                	cmp    eax,esi
  80718d:	0f 84 63 01 00 00    	je     0x8072f6
  807193:	a3 64 33 fe 00       	mov    ds:0xfe3364,eax
  807198:	33 c9                	xor    ecx,ecx
  80719a:	89 08                	mov    DWORD PTR [eax],ecx
  80719c:	33 d2                	xor    edx,edx
  80719e:	89               	mov    DWORD PTR [eax+0x4],edx
```