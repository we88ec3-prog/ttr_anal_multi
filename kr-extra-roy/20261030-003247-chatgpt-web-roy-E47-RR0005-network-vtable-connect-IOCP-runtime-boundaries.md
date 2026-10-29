# E47 — RR-0005／KR T02：真正網路 Manager vtable、Conn 連線與池化、WSASend/WSARecv/IOCP 初始交換邊界（10 子段）

**研究者**：chatgpt-web roy；**本地實際記錄時間**：`20261030-003247` (Asia/Taipei)；**正式段號 E47**。E47.1–E47.10 是同一個正式段內的分析子段，不是十個正式段號。

**研究目標**：接 E46 從真正 `FBA854` 網路物件建立完整的 `S2C 0x0013/0x007A → FE1B54 endpoint record → UI → 4957C0 → 具體 network vtable＋port＋key → Conn pool/socket → local C2S queue/encoder → Winsock WSASend / WSARecv / IOCP → frame decoder → app callback` **條件式**原生鏈；盡力確認第一筆收發的靜態候選、mode 寫入者與失敗分支，不以單一重要發現提前結束。

**實證原件**：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；Windows PE32 MSVC x86，`.text` VMA `0x401000`，raw `0x400`，故 `.text` raw=`VA−0x400C00`；`.rdata` 另有自己的映射（VMA `0xBD2000` raw `0x7D0600`），不可混用。反組譯取自本次直接 objdump 原件，不以舊報告冒充原生證據。

**研究環境與限制**：只做離線靜態原生分析；沒有執行 Client、沒有合法實測 session、封包 PCAP、WSASend 逐次 trace、Server 實作，也不把從函式分支推導的 first-frame 候選當成第一個實際 wire。下述每個 N 為機器碼對精確主張的證明，C 為附加條件可達，U 為未決。

**GitHub 開工核對**：2026-10-30 `main=e7416169fd20e4fcb0fe2c0b4d6207e4c9b443bc`、`extra/roy1=7905e8e189f50463e89b8d35bcf531c19a447a41`（E41–E45 已提交）；已核對 main `AGENTS.md`, `kr/tasks/T02/{README.md,task.json}`, `research/dispatch/{README.md,inbox/T02.md}`, `research/requests/index.json`, `shared/verified-knowledge/README.md`。RR-0005 在 main 仍 `PENDING / QUEUED`, owner=T02/KR/P0, claim=NULL, GAP-NET-0002；另有 RR-0001/0004/0006/0007 隔離，本次只按使用者明示接續 RR-0005。既有 E41–E46 是研究筆記、非 T01 FULL-PASS。**本次無 Commit／Push 授權。**

**停止條件**：B／完成第十個大型研究子段仍欠真實 first WSASend 和 first response 的單一會話證據，因此整理全部結果交 E48；本稿不把重大單點發現當成提前停止條件。

## E47.1 — FBA854 物件的唯一可見原始建立／清理錨點：Startup → Manager

**具體研究問題**：`FBA854` 是否可與 E46 已排除的 `FBA7CC+4` 區分，網路管理器在何處由 Client 的生命週期呼叫建立？

**分析、CFG／狀態與交叉證據**：

- **N** `0x48C0E0 lea edi,[ebx+0x140]` 後 `0x48C0E6 call 0x804650`，而 `0x48C027 lea eax,[ebx−8]` 呼叫另一個 `0x493170` handler table initializer，說明這是同一 Client 附近建置流程的兩種不同子結構座標，不能將 E46 的泛型 manager 與它混同。
- **N** `0x804650` 先對 `[EDI+0x8C]` 清零，再 `0x805720` 初始化 connection pool。然後 `0x8046D7 push 0x5C` 分配 manager 本體，`0x8046F2` 呼叫 `0x803D60`，`0x8046F7` 寫 vptr `0xC51748`，`0x80470F` 才把此物件指標寫入全域 `FBA854`，隨即取 vtable `+8` 間接呼叫。`0x804717` 後才填 `[EDI+0x60]`、`[EDI+0x34]` 時戳／tick。
- **N** `0x803F76` 在 manager 的完整清理後寫 global `FBA854=0`；`0x8045DC..8045EE` 在另一個持有者 teardown 找到非零 FBA854，讀 vtable slot+0 帶 `push 1` 呼叫後亦將它清為零；這是**兩個獨立 teardown 寫點**。`0x80470F` 是正向寫入點；不是 `FBA7CC+4`。
- **C** `0x80470F` 路徑如果 `0x5C` 分配失敗仍在 `0x80470A mov edx,[ecx]` 解參照空指標；靜態碼沒有可見 graceful-null 早退，不可因此說初始化必然成功。

**限定偽碼（推導，非原始 C++）**：

```cpp
// EDI 是 48C0E0 傳入的 Client-adjacent subobject；非 FBA7CC
init_network(EDI) {
  ensure_global_pool(); pool_init(FBA858);
  Manager *m = allocate(0x5C);
  if (m) { init_manager_lists(m); m->vptr = 0xC51748; }
  FBA854 = m;                       // 0x80470F, native write
  m->vptr[2](m);                   // virtual +8, 0x806850 in this vtable
  EDI->field_60 = tick(); EDI->field_34 = tick();
}
// tear_down paths 803F76 and 8045EE clear FBA854.
```

**BIN-first 原生 Assembly：Client 鄰接的 EDI 建置入口**；VA `0x0048BFF0..0x0048C031`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x08B3F0`）：

```asm
  48bff0:	68 c8 56 c0 00       	push   0xc056c8
  48bff5:	8b d3                	mov    edx,ebx
  48bff7:	e8 04 2d 25 00       	call   0x6ded00
  48bffc:	83 c4 04             	add    esp,0x4
  48bfff:	b8 05 40 00 80       	mov    eax,0x80004005
  48c004:	e9 3b 01 00 00       	jmp    0x48c144
  48c009:	8b 83 78 bf 00 00    	mov    eax,DWORD PTR [ebx+0xbf78]
  48c00f:	68 28 5b c0 00       	push   0xc05b28
  48c014:	68 f0 56 c0 00       	push   0xc056f0
  48c019:	50                   	push   eax
  48c01a:	68 fc 56 c0 00       	push   0xc056fc
  48c01f:	e8 dc 1c 26 00       	call   0x6edd00
  48c024:	83 c4 10             	add    esp,0x10
  48c027:	8d 43 f8             	lea    eax,[ebx-0x8]
  48c02a:	e8 41 71 00 00       	call   0x493170
  48c02f:	f6                   	.byte 0xf6
  48c030:	05                   	.byte 0x5
```

**BIN-first 原生 Assembly：Client → 804650**；VA `0x0048C0B5..0x0048C110`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x08B4B5`）：

```asm
  48c0b5:	f6 05 d8 37 fe 00 01 	test   BYTE PTR ds:0xfe37d8,0x1
  48c0bc:	c7 05 78 3d d6 00 00 	mov    DWORD PTR ds:0xd63d78,0x0
  48c0c3:	00 00 00 
  48c0c6:	75 18                	jne    0x48c0e0
  48c0c8:	09 3d d8 37 fe 00    	or     DWORD PTR ds:0xfe37d8,edi
  48c0ce:	e8 1d 93 37 00       	call   0x8053f0
  48c0d3:	68 a0 0b bd 00       	push   0xbd0ba0
  48c0d8:	e8 3d 62 40 00       	call   0x89231a
  48c0dd:	83 c4 04             	add    esp,0x4
  48c0e0:	8d bb 40 01 00 00    	lea    edi,[ebx+0x140]
  48c0e6:	e8 65 85 37 00       	call   0x804650
  48c0eb:	6a 34                	push   0x34
  48c0ed:	6a 01                	push   0x1
  48c0ef:	6a 01                	push   0x1
  48c0f1:	68 24 57 c0 00       	push   0xc05724
  48c0f6:	8d 94 24 54 01 00 00 	lea    edx,[esp+0x154]
  48c0fd:	e8 ae cd 00 00       	call   0x498eb0
  48c102:	83 c4 10             	add    esp,0x10
  48c105:	e8 76 15 fc ff       	call   0x44d680
  48c10a:	8b 08                	mov    ecx,DWORD PTR [eax]
  48c10c:	85 c9                	test   ecx,ecx
  48c10e:	74 0b                	je     0x48c11b
```

**BIN-first 原生 Assembly：FBA854 分配與指標寫入**；VA `0x008046AE..0x00804738`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x403AAE`）：

```asm
  8046ae:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  8046b5:	75 15                	jne    0x8046cc
  8046b7:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  8046be:	74 07                	je     0x8046c7
  8046c0:	e8 9b 68 c9 ff       	call   0x49af60
  8046c5:	eb 05                	jmp    0x8046cc
  8046c7:	e8 34 69 c9 ff       	call   0x49b000
  8046cc:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  8046d1:	50                   	push   eax
  8046d2:	e8 49 10 00 00       	call   0x805720
  8046d7:	6a 5c                	push   0x5c
  8046d9:	e8 8a cb 08 00       	call   0x891268
  8046de:	8b f0                	mov    esi,eax
  8046e0:	83 c4 04             	add    esp,0x4
  8046e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  8046e6:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  8046ed:	85 f6                	test   esi,esi
  8046ef:	74 10                	je     0x804701
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
  804717:	8b 35 a0 25 bd 00    	mov    esi,DWORD PTR ds:0xbd25a0
  80471d:	ff d6                	call   esi
  80471f:	89 47 60             	mov    DWORD PTR [edi+0x60],eax
  804722:	ff d6                	call   esi
  804724:	89 47 34             	mov    DWORD PTR [edi+0x34],eax
  804727:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80472a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  804731:	59                   	pop    ecx
  804732:	5e                   	pop    esi
  804733:	8b e5                	mov    esp,ebp
  804735:	5d                   	pop    ebp
  804736:	c3                   	ret
  804737:	cc                   	int3
```

**BIN-first 原生 Assembly：Manager 解構清零**；VA `0x00803F55..0x00803F84`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x403355`）：

```asm
  803f55:	77 0c                	ja     0x803f63
  803f57:	75 a8                	jne    0x803f01
  803f59:	8b 57 50             	mov    edx,DWORD PTR [edi+0x50]
  803f5c:	6a ff                	push   0xffffffff
  803f5e:	52                   	push   edx
  803f5f:	c7 47 4c 01 00 00 00 	mov    DWORD PTR [edi+0x4c],0x1
  803f66:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  803f6c:	8b 47 50             	mov    eax,DWORD PTR [edi+0x50]
  803f6f:	50                   	push   eax
  803f70:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  803f76:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
  803f7c:	8d 5f 18             	lea    ebx,[edi+0x18]
  803f7f:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  803f82:	c6                   	.byte 0xc6
  803f83:	45                   	inc    ebp
```

**BIN-first 原生 Assembly：主持有者 teardown virtual+0 / global clear**；VA `0x008045D0..0x00804605`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4039D0`）：

```asm
  8045d0:	df 83 c4 0c 89 9e    	fild   WORD PTR [ebx-0x6176f33c]
  8045d6:	ac                   	lods   al,BYTE PTR ds:[esi]
  8045d7:	00 00                	add    BYTE PTR [eax],al
  8045d9:	00 33                	add    BYTE PTR [ebx],dh
  8045db:	db 8b 0d 54 a8 fb    	fisttp DWORD PTR [ebx-0x457abf3]
  8045e1:	00 3b                	add    BYTE PTR [ebx],bh
  8045e3:	cb                   	retf
  8045e4:	74 0e                	je     0x8045f4
  8045e6:	8b 11                	mov    edx,DWORD PTR [ecx]
  8045e8:	8b 02                	mov    eax,DWORD PTR [edx]
  8045ea:	6a 01                	push   0x1
  8045ec:	ff d0                	call   eax
  8045ee:	89 1d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ebx
  8045f4:	8b 86 a8 00 00 00    	mov    eax,DWORD PTR [esi+0xa8]
  8045fa:	3b c3                	cmp    eax,ebx
  8045fc:	74 09                	je     0x804607
  8045fe:	50                   	push   eax
  8045ff:	e8 08 cc 08 00       	call   0x89120c
  804604:	83                   	.byte 0x83
```

**反證、邊界與下一待查**：**U** 目前正向 writer 的直接值來源是 `0x5C` alloc 的 network manager；未從此函式證明每條 active Conn 已建立 TCP socket。若想獲 runtime 次序需第一個 48C0E6 執行時間與第一個 4957C0 時戳。

## E47.2 — vptr C51748 11 slots 與 4957C0 呼叫的身份同一性

**具體研究問題**：Client 所呼叫 network manager `vptr+0x18/+0x10/+0x20` 實際跳哪個函式？是否可和 socket/queue/IOCP 精確接上？

**分析、CFG／狀態與交叉證據**：

- **N** 原始 PE `.rdata` 地址 `0xC51748`，其 11 個 DWORD 直接讀取並比對 Native `.text` 函式起點（非任意下標猜測）：

| Vtable 位移 | 函式 VA | 本次限定語意 |
|---|---|---|
| `+0x00` | `00806670` | 解構入口 |
| `+0x04` | `00806CF0` | IOCP worker |
| `+0x08` | `00806850` | IOCP 初始化/註冊 |
| `+0x0C` | `008068B0` | 非同步送出 |
| `+0x10` | `008069A0` | keyed local enqueue |
| `+0x14` | `00806A00` | WSARecv posted read |
| `+0x18` | `00806AD0` | active connect |
| `+0x1C` | `00806F60` | 連線查找/關閉 |
| `+0x20` | `00806F80` | 連線關閉 |
| `+0x24` | `00806FC0` | 連線狀態 |
| `+0x28` | `00807090` | 其他管理方法 |

- **N** `0x4957C0` 從 `[FBA854]` 取 vptr 並讀 `[vptr+0x18]`，兩次各 push 埠 `0x20E0`（key0）／`0x20DE`（key2），因此**此 vtable 版本**的 call target 精確是 `0x806AD0`。其後 `vptr+0x10`= `0x8069A0` 負責 keyed queue，`vptr+0x20`= `0x806F80` 用於部分失敗/處置。
- **N** vptr+0x08 = `0x806850`，由 Manager 剛建立後 `0x804715` 間接呼叫，該函式透過 `0x807E80` 初始化 / 關聯全域 IOCP 物件。`vptr+0x04=0x806CF0` 對應 GetQueuedCompletionStatus 消費。
- **C** 虛表位置與 callsites 一致可證此型別「在這個建構分支」的 target；動態更換 vptr、多份 manager 例項及異常初始化未由純靜態排除。

**限定偽碼（推導，非原始 C++）**：

```cpp
Manager *M = *(Manager**)0xFBA854;  // startup vptr=0xC51748
Conn* first  = M->vptr[6](M, endpoint, 0x20E0, key=0, lane=2);
Conn* second = M->vptr[6](M, endpoint, 0x20DE, key=2, lane=2);
if (first && second) M->vptr[4](M, 0, payload, 57);
// above is vtable slot-name inference; exact push order in native excerpts.
```

**BIN-first 原生 Assembly：vptr 的間接呼叫與兩個 port**；VA `0x004957C0..0x00495813`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x094BC0`）：

```asm
  4957c0:	55                   	push   ebp
  4957c1:	8b ec                	mov    ebp,esp
  4957c3:	83 ec 44             	sub    esp,0x44
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f                   	.byte 0xf
  495812:	84                   	.byte 0x84
```

**BIN-first 原生 Assembly：兩 Conn success 到 local enqueue**；VA `0x00495919..0x00495961`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x094D19`）：

```asm
  495919:	83 c4 2c             	add    esp,0x2c
  49591c:	e8 7f f2 f6 ff       	call   0x404ba0
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
```

**BIN-first 原生 Assembly：manager vptr 初始化及 vcall**；VA `0x008046F1..0x00804724`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x403AF1`）：

```asm
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
  804717:	8b 35 a0 25 bd 00    	mov    esi,DWORD PTR ds:0xbd25a0
  80471d:	ff d6                	call   esi
  80471f:	89 47 60             	mov    DWORD PTR [edi+0x60],eax
  804722:	ff d6                	call   esi
```

**BIN-first 原生 Assembly：IOCP init target +8**；VA `0x00806850..0x008068A0`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x405C50`）：

```asm
  806850:	b8 01 00 00 00       	mov    eax,0x1
  806855:	56                   	push   esi
  806856:	8b f1                	mov    esi,ecx
  806858:	84 05 b4 33 fe 00    	test   BYTE PTR ds:0xfe33b4,al
  80685e:	75 34                	jne    0x806894
  806860:	09 05 b4 33 fe 00    	or     DWORD PTR ds:0xfe33b4,eax
  806866:	33 c0                	xor    eax,eax
  806868:	50                   	push   eax
  806869:	50                   	push   eax
  80686a:	50                   	push   eax
  80686b:	6a ff                	push   0xffffffff
  80686d:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806872:	a3 bc 33 fe 00       	mov    ds:0xfe33bc,eax
  806877:	a3 c0 33 fe 00       	mov    ds:0xfe33c0,eax
  80687c:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806882:	68 b0 0b bd 00       	push   0xbd0bb0
  806887:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  80688c:	e8 89 ba 08 00       	call   0x89231a
  806891:	83 c4 04             	add    esp,0x4
  806894:	56                   	push   esi
  806895:	68 b8 33 fe 00       	push   0xfe33b8
  80689a:	e8 e1 15 00 00       	call   0x807e80
  80689f:	5e                   	pop    esi
```

**反證、邊界與下一待查**：**U** M->slot 6 的 stack ABI 需以 `806AD0` `[ebp+...]` 和 `4957C0` push 交叉確認；vtable 本身只表明實作地址，不能代表已完成 TCP 三向握手。

## E47.3 — Conn pool：A0D8 配置、reuse vs fresh、A02C 預設及雙重索引

**具體研究問題**：建立 Conn 物件是否每次 malloc？reuse 是否重置 framing mode2？如何分配及回收？

**分析、CFG／狀態與交叉證據**：

- **N** `0x805720` 以 `push 0xA0D8` 配置連線物件，`0x80577A` 呼叫 `0x805CA0` 作建構；建構 `0x805D02 mov byte ptr [ESI+0xA02C],2`、初始化自有 recv/send buffer 與鏈結欄位。`0x805792..8057AA` 再將 pool 層的 3 個欄位複製至 Conn `+A0C8,+A0CC,+A0D0`。
- **N** `0x805950` 是 active pool pop：若 pool `+0x20` 非零走 `0x80598B..8059FC`，從 16-entry-chunk/linked 索引取舊 Conn 並呼叫 `0x805F50` reset，將 `Conn+A0AC=1` 並更新 pool `+0x44`；若無可重用而 caller 所傳非零，走 `0x805A03..805A54` 新 alloc A0D8 → 805CA0 並註冊，還將 `A0AC=1`。
- **N** `0x805F50` reset 的直接寫入集中 socket 句柄、Conn 區中佇列／lane，其初始化不見 `A02C` 欄位賦值。因此**新建時預設2**，reuse 分支**只會保留此前 mode byte**，不是每次借用都重寫為2。這是 E46 的「mode=2 on constructor」進一步的生命週期限制。
- **N** pool `0x805720` 亦更新 `+0x20` 計數並把 Conn 加入索引；`0x806AD0` 從 `FBA858` pool 以 `0x805950(1)` 取出的才是 key0/key2 嘗試 connect 用 Conn。
- **C** 實際有無任何由別處 alias 改 A02C 的 writer 待查，不能由只見兩處 literal operand 宣告所有 lifetime 一直2。

**限定偽碼（推導，非原始 C++）**：

```cpp
Conn *pool_take(Pool *P, bool create) {
  if (P->free_count) { Conn* c=pop_free(P); reset_805F50(c);
    c->active_A0AC=1; return c; }
  if (!create) return nullptr;
  Conn *c=(Conn*)malloc(0xA0D8); if(c) construct_805CA0(c); // A02C=2
  register_in_pool(c); c->active_A0AC=1; return c;
}
// E47 corrected invariant: on a reused Conn, reset_805F50 does NOT write A02C.
```

**BIN-first 原生 Assembly：Pool 新 Conn 配置與欄位繫結**；VA `0x00805748..0x00805823`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x404B48`）：

```asm
  805748:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80574b:	8b 43 34             	mov    eax,DWORD PTR [ebx+0x34]
  80574e:	50                   	push   eax
  80574f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  805755:	33 f6                	xor    esi,esi
  805757:	89 75 ec             	mov    DWORD PTR [ebp-0x14],esi
  80575a:	eb 06                	jmp    0x805762
  80575c:	8d 64 24 00          	lea    esp,[esp+0x0]
  805760:	33 f6                	xor    esi,esi
  805762:	68 d8 a0 00 00       	push   0xa0d8
  805767:	e8 fc ba 08 00       	call   0x891268
  80576c:	83 c4 04             	add    esp,0x4
  80576f:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805772:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805775:	3b c6                	cmp    eax,esi
  805777:	74 0d                	je     0x805786
  805779:	50                   	push   eax
  80577a:	e8 21 05 00 00       	call   0x805ca0
  80577f:	8b d0                	mov    edx,eax
  805781:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  805784:	eb 05                	jmp    0x80578b
  805786:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  805789:	8b d6                	mov    edx,esi
  80578b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805792:	8b 43 38             	mov    eax,DWORD PTR [ebx+0x38]
  805795:	89 82 c8 a0 00 00    	mov    DWORD PTR [edx+0xa0c8],eax
  80579b:	8b 4b 3c             	mov    ecx,DWORD PTR [ebx+0x3c]
  80579e:	89 8a cc a0 00 00    	mov    DWORD PTR [edx+0xa0cc],ecx
  8057a4:	8b 43 40             	mov    eax,DWORD PTR [ebx+0x40]
  8057a7:	8d 7b 10             	lea    edi,[ebx+0x10]
  8057aa:	89 82 d0 a0 00 00    	mov    DWORD PTR [edx+0xa0d0],eax
  8057b0:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  8057b3:	8b 4f 0c             	mov    ecx,DWORD PTR [edi+0xc]
  8057b6:	03 c8                	add    ecx,eax
  8057b8:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  8057bb:	f6 c1 03             	test   cl,0x3
  8057be:	75 14                	jne    0x8057d4
  8057c0:	83 c0 04             	add    eax,0x4
  8057c3:	c1 e8 02             	shr    eax,0x2
  8057c6:	39 47 08             	cmp    DWORD PTR [edi+0x8],eax
  8057c9:	77 09                	ja     0x8057d4
  8057cb:	57                   	push   edi
  8057cc:	e8 9f 17 e3 ff       	call   0x636f70
  8057d1:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  8057d4:	8b 77 0c             	mov    esi,DWORD PTR [edi+0xc]
  8057d7:	03 77 10             	add    esi,DWORD PTR [edi+0x10]
  8057da:	8b 43 18             	mov    eax,DWORD PTR [ebx+0x18]
  8057dd:	8b fe                	mov    edi,esi
  8057df:	c1 ef 02             	shr    edi,0x2
  8057e2:	3b c7                	cmp    eax,edi
  8057e4:	77 02                	ja     0x8057e8
  8057e6:	2b f8                	sub    edi,eax
  8057e8:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  8057eb:	83 3c b8 00          	cmp    DWORD PTR [eax+edi*4],0x0
  8057ef:	75 1b                	jne    0x80580c
  8057f1:	6a 10                	push   0x10
  8057f3:	e8 70 ba 08 00       	call   0x891268
  8057f8:	83 c4 04             	add    esp,0x4
  8057fb:	85 c0                	test   eax,eax
  8057fd:	0f 84 12 01 00 00    	je     0x805915
  805803:	8b 4b 14             	mov    ecx,DWORD PTR [ebx+0x14]
  805806:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  805809:	89 04 b9             	mov    DWORD PTR [ecx+edi*4],eax
  80580c:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  80580f:	8b 0c b8             	mov    ecx,DWORD PTR [eax+edi*4]
  805812:	83 e6 03             	and    esi,0x3
  805815:	8d 34 b1             	lea    esi,[ecx+esi*4]
  805818:	85 f6                	test   esi,esi
  80581a:	74 02                	je     0x80581e
  80581c:	89 16                	mov    DWORD PTR [esi],edx
  80581e:	ff 43 20             	inc    DWORD PTR [ebx+0x20]
  805821:	8b                   	.byte 0x8b
  805822:	43                   	inc    ebx
```

**BIN-first 原生 Assembly：Pool free-list pop**；VA `0x00805978..0x00805A00`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x404D78`）：

```asm
  805978:	8b f9                	mov    edi,ecx
  80597a:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  80597d:	50                   	push   eax
  80597e:	33 f6                	xor    esi,esi
  805980:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  805986:	39 77 20             	cmp    DWORD PTR [edi+0x20],esi
  805989:	74 73                	je     0x8059fe
  80598b:	8d 45 e8             	lea    eax,[ebp-0x18]
  80598e:	8d 4f 10             	lea    ecx,[edi+0x10]
  805991:	e8 7a c8 d3 ff       	call   0x542210
  805996:	8b 08                	mov    ecx,DWORD PTR [eax]
  805998:	85 c9                	test   ecx,ecx
  80599a:	75 04                	jne    0x8059a0
  80599c:	33 d2                	xor    edx,edx
  80599e:	eb 02                	jmp    0x8059a2
  8059a0:	8b 11                	mov    edx,DWORD PTR [ecx]
  8059a2:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  8059a5:	8b 72 08             	mov    esi,DWORD PTR [edx+0x8]
  8059a8:	8b c1                	mov    eax,ecx
  8059aa:	c1 e8 02             	shr    eax,0x2
  8059ad:	83 e1 03             	and    ecx,0x3
  8059b0:	3b f0                	cmp    esi,eax
  8059b2:	77 02                	ja     0x8059b6
  8059b4:	2b c6                	sub    eax,esi
  8059b6:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  8059b9:	8b 04 82             	mov    eax,DWORD PTR [edx+eax*4]
  8059bc:	8b 34 88             	mov    esi,DWORD PTR [eax+ecx*4]
  8059bf:	8b 47 20             	mov    eax,DWORD PTR [edi+0x20]
  8059c2:	85 c0                	test   eax,eax
  8059c4:	74 23                	je     0x8059e9
  8059c6:	8b 57 18             	mov    edx,DWORD PTR [edi+0x18]
  8059c9:	ff 47 1c             	inc    DWORD PTR [edi+0x1c]
  8059cc:	03 d2                	add    edx,edx
  8059ce:	03 d2                	add    edx,edx
  8059d0:	3b 57 1c             	cmp    edx,DWORD PTR [edi+0x1c]
  8059d3:	77 07                	ja     0x8059dc
  8059d5:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059dc:	48                   	dec    eax
  8059dd:	89 47 20             	mov    DWORD PTR [edi+0x20],eax
  8059e0:	75 07                	jne    0x8059e9
  8059e2:	c7 47 1c 00 00 00 00 	mov    DWORD PTR [edi+0x1c],0x0
  8059e9:	e8 62 05 00 00       	call   0x805f50
  8059ee:	b8 01 00 00 00       	mov    eax,0x1
  8059f3:	89 86 ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],eax
  8059f9:	01 47 44             	add    DWORD PTR [edi+0x44],eax
  8059fc:	eb 60                	jmp    0x805a5e
  8059fe:	39                   	.byte 0x39
  8059ff:	75                   	.byte 0x75
```

**BIN-first 原生 Assembly：Pool fallback new alloc**；VA `0x00805A03..0x00805A5E`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x404E03`）：

```asm
  805a03:	68 d8 a0 00 00       	push   0xa0d8
  805a08:	e8 5b b8 08 00       	call   0x891268
  805a0d:	83 c4 04             	add    esp,0x4
  805a10:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a13:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  805a16:	3b c6                	cmp    eax,esi
  805a18:	74 08                	je     0x805a22
  805a1a:	50                   	push   eax
  805a1b:	e8 80 02 00 00       	call   0x805ca0
  805a20:	eb 02                	jmp    0x805a24
  805a22:	33 c0                	xor    eax,eax
  805a24:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  805a2b:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  805a2e:	89 88 c8 a0 00 00    	mov    DWORD PTR [eax+0xa0c8],ecx
  805a34:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  805a37:	89 90 cc a0 00 00    	mov    DWORD PTR [eax+0xa0cc],edx
  805a3d:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  805a40:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  805a43:	89 88 d0 a0 00 00    	mov    DWORD PTR [eax+0xa0d0],ecx
  805a49:	8d 45 08             	lea    eax,[ebp+0x8]
  805a4c:	e8 ff 58 fb ff       	call   0x7bb350
  805a51:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805a54:	c7 86 ac a0 00 00 01 	mov    DWORD PTR [esi+0xa0ac],0x1
  805a5b:	00 00 00 
```

**BIN-first 原生 Assembly：Conn constructor mode 設置**；VA `0x00805CC8..0x00805D4D`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4050C8`）：

```asm
  805cc8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  805ccb:	8d 46 18             	lea    eax,[esi+0x18]
  805cce:	6a 18                	push   0x18
  805cd0:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805cd6:	e8 8d b5 08 00       	call   0x891268
  805cdb:	8b f8                	mov    edi,eax
  805cdd:	33 db                	xor    ebx,ebx
  805cdf:	83 c4 04             	add    esp,0x4
  805ce2:	3b fb                	cmp    edi,ebx
  805ce4:	74 0e                	je     0x805cf4
  805ce6:	68 a0 0f 00 00       	push   0xfa0
  805ceb:	57                   	push   edi
  805cec:	ff 15 2c 22 bd 00    	call   DWORD PTR ds:0xbd222c
  805cf2:	eb 02                	jmp    0x805cf6
  805cf4:	33 ff                	xor    edi,edi
  805cf6:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805cfc:	89 be 1c 50 00 00    	mov    DWORD PTR [esi+0x501c],edi
  805d02:	c6 86 2c a0 00 00 02 	mov    BYTE PTR [esi+0xa02c],0x2
  805d09:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805d0f:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805d15:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805d1b:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  805d1e:	89 9e 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],ebx
  805d24:	33 c0                	xor    eax,eax
  805d26:	89 86 30 a0 00 00    	mov    DWORD PTR [esi+0xa030],eax
  805d2c:	89 86 34 a0 00 00    	mov    DWORD PTR [esi+0xa034],eax
  805d32:	89 86 38 a0 00 00    	mov    DWORD PTR [esi+0xa038],eax
  805d38:	89 86 3c a0 00 00    	mov    DWORD PTR [esi+0xa03c],eax
  805d3e:	89 86 40 a0 00 00    	mov    DWORD PTR [esi+0xa040],eax
  805d44:	89 9e 48 a0 00 00    	mov    DWORD PTR [esi+0xa048],ebx
  805d4a:	89                   	.byte 0x89
  805d4b:	9e                   	sahf
  805d4c:	6c                   	ins    BYTE PTR es:[edi],dx
```

**BIN-first 原生 Assembly：Conn reset 開頭**；VA `0x00805F50..0x00805FCA`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x405350`）：

```asm
  805f50:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  805f56:	33 c0                	xor    eax,eax
  805f58:	53                   	push   ebx
  805f59:	33 db                	xor    ebx,ebx
  805f5b:	89 9e ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],ebx
  805f61:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805f64:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  805f67:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  805f6a:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  805f6d:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  805f70:	8d 46 18             	lea    eax,[esi+0x18]
  805f73:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805f79:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805f7f:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805f85:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805f8b:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805f91:	33 c0                	xor    eax,eax
  805f93:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805f99:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805f9f:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805fa5:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805fab:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805fb1:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805fb7:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805fbd:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805fc3:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805fc9:	56                   	push   esi
```

**反證、邊界與下一待查**：**U** 未反組完整 pop/free list 的所有 exception／OOM 分支；Conn 借還後是否由其他 vtable setter 改 mode 要外部 xref 或合法 trace。不能將 `Conn+A02C` 等同 `Conn+A080`（lane），亦不能和 `[manager+0x2c]` pool count 混同。

## E47.4 — Network vtable+0x18 / 806AD0：endpoint、port、key、socket、IOCP 的連線實體化

**具體研究問題**：`4957C0` 兩個 Conn 是否呼叫真正 socket/connect？Connect 的錯誤／成功是否具有不同的後續？

**分析、CFG／狀態與交叉證據**：

- **N** `0x806AD0` 在 `FBA858` pool 存在或經 49AF60/49B000 初始化後呼叫 `0x805950(1)` 取 Conn，並寫 `Conn+A0B4=2`、`Conn+A080=[ebp+0x14]`（接收應用 lane，不是 mode A02C）。`0x806B39` 以 `0xBD25C0` 取 host 資訊、`0x806B65` 以 `0xBD25A8` 轉換 port；`0x806B7C` 經 `WSASocketA` 得 socket handle，`0x806B8C` 呼叫 Winsock connect import `0xBD25C4`（ordinal 4）對 `sockaddr` 16 bytes 建立 TCP 連線。
- **N** `connect` 返回 `-1` 走 `0x806B92→0x806BB6` 例外/錯誤資訊與 `0x805AF0` 回收、回傳0；不是只有指標 NULL 判定。非 `-1` 路徑繼續三組 setsockopt 控制 (`0xBD25AC`、0x6/0x1002/0x1001)；若任一失敗同樣走回收0。
- **N** 成功時 `0x806C7B→0x806C87` 從 `0x806620` 所提供 completion port handle 呼叫 `CreateIoCompletionPort`，提供 socket `ESI`、Conn 指標 `EBX` 作 completion key。接著 `0x806C91..806CD2` 將 Conn 登錄進 Manager 列表。返回 `EBX` 只有完成上述條件式分支。
- **C** 回傳 Conn* 不代表遠端應用驗證成功；此處使用阻塞式 connect return-success，但尚未證 first frame/首個 ack。新 Conn 由 key0/key2 的不同常數輸入，不得當成同一條 socket。

**限定偽碼（推導，非原始 C++）**：

```cpp
Conn *network_connect(Manager* M, endpoint, uint16_t port, int key, int lane) {
  Conn *C=pool_take(FBA858, true); if(!C) return nullptr;
  C->lane_A080=lane; C->state_A0B4=2;
  SOCKET s=WSASocketA(...); C->socket=s;
  if(connect(s,sockaddr(endpoint,port),16)==SOCKET_ERROR) goto reclaim;
  if(any_socket_option_failed) goto reclaim;
  CreateIoCompletionPort((HANDLE)s, global_iocp, (ULONG_PTR)C, 0);
  manager_insert_active(M,C); return C;
reclaim: pool_put(C); return nullptr;
}
```

**BIN-first 原生 Assembly：取 pool Conn、寫 lane、建立 socket**；VA `0x00806AD0..0x00806B94`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x405ED0`）：

```asm
  806ad0:	55                   	push   ebp
  806ad1:	8b ec                	mov    ebp,esp
  806ad3:	83 e4 f8             	and    esp,0xfffffff8
  806ad6:	83 ec 24             	sub    esp,0x24
  806ad9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806ade:	33 c4                	xor    eax,esp
  806ae0:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  806ae4:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806aeb:	53                   	push   ebx
  806aec:	56                   	push   esi
  806aed:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806af0:	57                   	push   edi
  806af1:	8b f9                	mov    edi,ecx
  806af3:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  806af7:	75 15                	jne    0x806b0e
  806af9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806b00:	74 07                	je     0x806b09
  806b02:	e8 59 44 c9 ff       	call   0x49af60
  806b07:	eb 05                	jmp    0x806b0e
  806b09:	e8 f2 44 c9 ff       	call   0x49b000
  806b0e:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  806b14:	6a 01                	push   0x1
  806b16:	e8 35 ee ff ff       	call   0x805950
  806b1b:	8b d8                	mov    ebx,eax
  806b1d:	85 db                	test   ebx,ebx
  806b1f:	0f 84 b2 01 00 00    	je     0x806cd7
  806b25:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  806b28:	56                   	push   esi
  806b29:	c7 83 b4 a0 00 00 02 	mov    DWORD PTR [ebx+0xa0b4],0x2
  806b30:	00 00 00 
  806b33:	89 83 80 a0 00 00    	mov    DWORD PTR [ebx+0xa080],eax
  806b39:	ff 15 c0 25 bd 00    	call   DWORD PTR ds:0xbd25c0
  806b3f:	0f bf 48 0a          	movsx  ecx,WORD PTR [eax+0xa]
  806b43:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  806b46:	8b 02                	mov    eax,DWORD PTR [edx]
  806b48:	51                   	push   ecx
  806b49:	50                   	push   eax
  806b4a:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  806b4e:	51                   	push   ecx
  806b4f:	e8 7c 70 09 00       	call   0x89dbd0
  806b54:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  806b57:	83 c4 0c             	add    esp,0xc
  806b5a:	ba 02 00 00 00       	mov    edx,0x2
  806b5f:	50                   	push   eax
  806b60:	66 89 54 24 20       	mov    WORD PTR [esp+0x20],dx
  806b65:	ff 15 a8 25 bd 00    	call   DWORD PTR ds:0xbd25a8
  806b6b:	6a 01                	push   0x1
  806b6d:	6a 00                	push   0x0
  806b6f:	6a 00                	push   0x0
  806b71:	6a 00                	push   0x0
  806b73:	6a 01                	push   0x1
  806b75:	6a 02                	push   0x2
  806b77:	66 89 44 24 36       	mov    WORD PTR [esp+0x36],ax
  806b7c:	ff 15 d0 25 bd 00    	call   DWORD PTR ds:0xbd25d0
  806b82:	6a 10                	push   0x10
  806b84:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  806b88:	51                   	push   ecx
  806b89:	50                   	push   eax
  806b8a:	89 03                	mov    DWORD PTR [ebx],eax
  806b8c:	ff 15 c4 25 bd 00    	call   DWORD PTR ds:0xbd25c4
  806b92:	83                   	.byte 0x83
  806b93:	f8                   	clc
```

**BIN-first 原生 Assembly：connect/setsockopt 失敗路徑**；VA `0x00806B92..0x00806C16`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x405F92`）：

```asm
  806b92:	83 f8 ff             	cmp    eax,0xffffffff
  806b95:	75 7f                	jne    0x806c16
  806b97:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806b9b:	74 19                	je     0x806bb6
  806b9d:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806ba3:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806ba6:	50                   	push   eax
  806ba7:	68 ac 16 c5 00       	push   0xc516ac
  806bac:	6a 02                	push   0x2
  806bae:	e8 4d 98 ee ff       	call   0x6f0400
  806bb3:	83 c4 0c             	add    esp,0xc
  806bb6:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806bbd:	75 35                	jne    0x806bf4
  806bbf:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806bc6:	74 27                	je     0x806bef
  806bc8:	e8 93 43 c9 ff       	call   0x49af60
  806bcd:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bd3:	53                   	push   ebx
  806bd4:	e8 17 ef ff ff       	call   0x805af0
  806bd9:	33 c0                	xor    eax,eax
  806bdb:	5f                   	pop    edi
  806bdc:	5e                   	pop    esi
  806bdd:	5b                   	pop    ebx
  806bde:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806be2:	33 cc                	xor    ecx,esp
  806be4:	e8 18 a4 08 00       	call   0x891001
  806be9:	8b e5                	mov    esp,ebp
  806beb:	5d                   	pop    ebp
  806bec:	c2 10 00             	ret    0x10
  806bef:	e8 0c 44 c9 ff       	call   0x49b000
  806bf4:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bfa:	53                   	push   ebx
  806bfb:	e8 f0 ee ff ff       	call   0x805af0
  806c00:	33 c0                	xor    eax,eax
  806c02:	5f                   	pop    edi
  806c03:	5e                   	pop    esi
  806c04:	5b                   	pop    ebx
  806c05:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806c09:	33 cc                	xor    ecx,esp
  806c0b:	e8 f1 a3 08 00       	call   0x891001
  806c10:	8b e5                	mov    esp,ebp
  806c12:	5d                   	pop    ebp
  806c13:	c2 10 00             	ret    0x10
```

**BIN-first 原生 Assembly：socket 配置完成至 IOCP association**；VA `0x00806C16..0x00806CD8`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x406016`）：

```asm
  806c16:	8b 33                	mov    esi,DWORD PTR [ebx]
  806c18:	8b 3d ac 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25ac
  806c1e:	6a 04                	push   0x4
  806c20:	8d 54 24 14          	lea    edx,[esp+0x14]
  806c24:	52                   	push   edx
  806c25:	6a 01                	push   0x1
  806c27:	6a 06                	push   0x6
  806c29:	56                   	push   esi
  806c2a:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  806c31:	00 
  806c32:	ff d7                	call   edi
  806c34:	83 f8 ff             	cmp    eax,0xffffffff
  806c37:	74 c7                	je     0x806c00
  806c39:	6a 04                	push   0x4
  806c3b:	8d 44 24 14          	lea    eax,[esp+0x14]
  806c3f:	50                   	push   eax
  806c40:	68 02 10 00 00       	push   0x1002
  806c45:	68 ff ff 00 00       	push   0xffff
  806c4a:	56                   	push   esi
  806c4b:	c7 44 24 24 00 40 00 	mov    DWORD PTR [esp+0x24],0x4000
  806c52:	00 
  806c53:	ff d7                	call   edi
  806c55:	83 f8 ff             	cmp    eax,0xffffffff
  806c58:	74 a6                	je     0x806c00
  806c5a:	6a 04                	push   0x4
  806c5c:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  806c60:	51                   	push   ecx
  806c61:	68 01 10 00 00       	push   0x1001
  806c66:	68 ff ff 00 00       	push   0xffff
  806c6b:	56                   	push   esi
  806c6c:	c7 44 24 24 00 80 00 	mov    DWORD PTR [esp+0x24],0x8000
  806c73:	00 
  806c74:	ff d7                	call   edi
  806c76:	83 f8 ff             	cmp    eax,0xffffffff
  806c79:	74 85                	je     0x806c00
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
  806c87:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806c8d:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
  806cd7:	8b                   	.byte 0x8b
```

**BIN-first 原生 Assembly：Client 兩組 network connect**；VA `0x004957C5..0x00495819`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x094BC5`）：

```asm
  4957c5:	44                   	inc    esp
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
  495817:	83                   	.byte 0x83
  495818:	be                   	.byte 0xbe
```

**反證、邊界與下一待查**：**U** 連線是否在野外正常 handshake、`CreateIoCompletionPort` 與管理器列表插入是否均有完整檢錯/rollback，各條失敗是否會立即關閉相同 fd，需補所有後段和 runtime 観測。`WSASocketA` 在 ordinal 4 connect 之前有若干中間 WinSock error，不能以 static list 當實際呼叫順序 log。

## E47.5 — local application enqueue → framing mode → WSASend：真正有一條，但 first-wire 未得

**具體研究問題**：由 `0x4957C0` 準備的 key0 57B payload 如何到 WSASend？能否從 native 靜態控制流判斷它是第一個 frame？

**分析、CFG／狀態與交叉證據**：

- **N** Client 的 `0x4957C0` key0/key2 兩個 Conn 均非零時生成 57B payload（`0x0001` LE16）並呼叫 manager `vptr+0x10`，本 vtable 中該 slot = `0x8069A0`。`0x8069A0` 使用 `this+0x18` keyed tree 和 `0x8438C0` 查詢對應 Conn，若找不到或 Conn+0x10 為 NULL → 回傳0；找到且長度非零 → `0x8060D0` 將資料封入 Conn 本地佇列。因為是**局部排隊**，不代表同步 Winsock 發送。
- **N** `0x806202` 對 `Conn+A02C` 做 signed byte 讀取：0 走 0x807A70，非0優先 0x807830；加擾編碼失敗會轉回 plain 0x807A70。這是選擇 frame 的編碼 CFG，而非 wire 出站先後順序。
- **N** `0x8068B0` 是此 vtable `+0x0C` 的非同步送出；先檢查 buffer、nonzero bytes 及 `Conn+A0A8==0`，備好 `Conn+A050` WSABUF/OVERLAPPED，`0x806912` 呼叫 import `WSASend`。返回 `-1` 且 `WSAGetLastError()==0x3E5 (WSA_IO_PENDING)` 回傳2，不視為普通失敗；直接成功回傳1，其他錯誤回傳0/記錄、可改 Conn 狀態。
- **C** 對 57B data，在 A02C==2、成功 0x0BBB、沒有先前 output 和足夠容量，先前 E46 63B候選 LE16(57),LE16(0BBB),2B checksum,encoded 57B；fallback 61B 1A68。第一個真實 WSASend 取決於各 Conn 的 pending queue、call schedule、另一 producer、執行時候選分支，因此不能稱 first wire。

**限定偽碼（推導，非原始 C++）**：

```cpp
bool enqueue_keyed(Manager*M,int key,uint8_t* data,unsigned n){
  Conn*C=lookup(M->tree,key); if(!C||!C->usable) return false;
  if(n==0) return true;
  return append_8060D0(C,data,n);
}
int send_async(Manager*M, Conn*C, uint8_t* buf,unsigned n, unsigned *written){
  if(!buf || !n || C->A0A8) return -1;
  int r=WSASend(C->socket,&C->send_wsabuf,1,...,&C->send_overlapped,NULL);
  if(r==SOCKET_ERROR) return WSAGetLastError()==997?2:0;
  return 1;
}
```

**BIN-first 原生 Assembly：Client 本地 57B 送入 keyed manager**；VA `0x00495914..0x0049595F`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x094D14`）：

```asm
  495914:	e8 40 e2 3f 00       	call   0x893b59
  495919:	83 c4 2c             	add    esp,0x2c
  49591c:	e8 7f f2 f6 ff       	call   0x404ba0
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89                   	.byte 0x89
  49595c:	be                   	.byte 0xbe
  49595d:	64                   	fs
  49595e:	bf                   	.byte 0xbf
```

**BIN-first 原生 Assembly：Manager key lookup → queue**；VA `0x008069A0..0x008069F4`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x405DA0`）：

```asm
  8069a0:	55                   	push   ebp
  8069a1:	8b ec                	mov    ebp,esp
  8069a3:	51                   	push   ecx
  8069a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8069a7:	56                   	push   esi
  8069a8:	8b f1                	mov    esi,ecx
  8069aa:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8069ad:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  8069b0:	51                   	push   ecx
  8069b1:	8d 4e 18             	lea    ecx,[esi+0x18]
  8069b4:	8d 45 fc             	lea    eax,[ebp-0x4]
  8069b7:	e8 04 cf 03 00       	call   0x8438c0
  8069bc:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  8069bf:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  8069c2:	5e                   	pop    esi
  8069c3:	74 07                	je     0x8069cc
  8069c5:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  8069c8:	85 c9                	test   ecx,ecx
  8069ca:	75 08                	jne    0x8069d4
  8069cc:	33 c0                	xor    eax,eax
  8069ce:	8b e5                	mov    esp,ebp
  8069d0:	5d                   	pop    ebp
  8069d1:	c2 0c 00             	ret    0xc
  8069d4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  8069d7:	85 c0                	test   eax,eax
  8069d9:	75 0b                	jne    0x8069e6
  8069db:	b8 01 00 00 00       	mov    eax,0x1
  8069e0:	8b e5                	mov    esp,ebp
  8069e2:	5d                   	pop    ebp
  8069e3:	c2 0c 00             	ret    0xc
  8069e6:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  8069e9:	50                   	push   eax
  8069ea:	52                   	push   edx
  8069eb:	e8 e0 f6 ff ff       	call   0x8060d0
  8069f0:	8b e5                	mov    esp,ebp
  8069f2:	5d                   	pop    ebp
  8069f3:	c2                   	.byte 0xc2
```

**BIN-first 原生 Assembly：A02C 路由 frame encoder**；VA `0x008061F6..0x00806250`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4055F6`）：

```asm
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b                   	.byte 0x8b
```

**BIN-first 原生 Assembly：WSASend / pending / 三值結果**；VA `0x008068B0..0x0080699B`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x405CB0`）：

```asm
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
  806995:	83 c8 ff             	or     eax,0xffffffff
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2                   	.byte 0xc2
```

**反證、邊界與下一待查**：**U** 本段未能從靜態 xrefs 排除在 0x0001 前更早的 heartbeats/0x0010。`WSASend` 限定在 8068B0 下游；具體 header checksum bytes、TCP 分片、最早線上先後順序需同次 session trace。

## E47.6 — WSARecv → GetQueuedCompletionStatus：兩個 OVERLAPPED 分支與錯誤狀態

**具體研究問題**：一條 Conn 有哪兩組非同步 IO，IOCP 消費如何辨識 send 與 receive 完成？

**分析、CFG／狀態與交叉證據**：

- **N** vptr+0x14 = `0x806A00`，它重設 `Conn+A030` OVERLAPPED 並配置 `Conn+A030+0x14` wsabuf len=0x1000，`0x806A4C` 呼叫 `WSARecv` (IAT 0xBD25BC)。非同步 WSA_IO_PENDING 0x3E5 不作普通錯誤；真錯誤經 manager vptr+0x24 後將 `Conn+A0A8=1`；立即成功會呼叫 `0x8065B0` 檢查狀態並可能關閉。
- **N** vptr+0x04 = `0x806CF0`，使用 `GetQueuedCompletionStatus` IAT `0xBD2274` 取得傳回 bytes、completion key (Conn*)、OVERLAPPED pointer。當 `OVERLAPPED==Conn+A030` (0x806DE4–0x806DF2)，計數增 `M+0x2c`/`M+0x3c`；在 active flag 成立時交 `0x807B40` 解析，再依非零結果走 `vptr+0x14` 再排 WSARecv。
- **N** 當 `OVERLAPPED==Conn+A050` (0x806E7D–0x806E8B)，計數增 `M+0x28`/`M+0x38`；若 Conn A0AC active，經 `0x8077B0` 消費已送 bytes／更新 output buffer；更新 `Conn+A024` 是否仍有 pending bytes，喚醒/釋放 `A0B8` 事件。
- **N** `GetQueuedCompletionStatus` 成功但 bytes==0 / overlapped NULL 各有不同路徑 (0x806DA0、0x806DC0)，失敗且 overlapped 非NULL 走 `0x806ECF` 用 type 比對進行清理。此函式並非每次 IOCP 就必然進 App handler；存在長度/狀態/錯誤條件。
- **C** 兩個 0x20 byte apart 的 OVERLAPPED 不得和應用層 lane2 推為同一字段；completion key 是 Conn* 而非 packet command。

**限定偽碼（推導，非原始 C++）**：

```cpp
void completion_loop(Manager *M) {
  ok=GetQueuedCompletionStatus(port,&bytes,&conn,&ov,INFINITE);
  if(ok && ov==conn->ovRecv_A030){
     M->recvBytes+=bytes; if(conn->A0AC && parse_807B40(conn,bytes)) post_WSARECV(conn);
  } else if(ok && ov==conn->ovSend_A050){
     M->sendBytes+=bytes; if(conn->A0AC) drain_8077B0(conn,bytes);
  } else if(!ok){ /* native branches distinguish overlapped pointers */ }
}
```

**BIN-first 原生 Assembly：WSARecv request、pending/error**；VA `0x00806A00..0x00806ACD`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x405E00`）：

```asm
  806a00:	55                   	push   ebp
  806a01:	8b ec                	mov    ebp,esp
  806a03:	51                   	push   ecx
  806a04:	53                   	push   ebx
  806a05:	56                   	push   esi
  806a06:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806a09:	57                   	push   edi
  806a0a:	8d 86 30 a0 00 00    	lea    eax,[esi+0xa030]
  806a10:	8b f9                	mov    edi,ecx
  806a12:	33 c9                	xor    ecx,ecx
  806a14:	89 08                	mov    DWORD PTR [eax],ecx
  806a16:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  806a19:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  806a1c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  806a1f:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  806a22:	8b 8e 18 50 00 00    	mov    ecx,DWORD PTR [esi+0x5018]
  806a28:	6a 00                	push   0x0
  806a2a:	50                   	push   eax
  806a2b:	89 48 18             	mov    DWORD PTR [eax+0x18],ecx
  806a2e:	8d 48 14             	lea    ecx,[eax+0x14]
  806a31:	8d 45 fc             	lea    eax,[ebp-0x4]
  806a34:	50                   	push   eax
  806a35:	8d 45 08             	lea    eax,[ebp+0x8]
  806a38:	50                   	push   eax
  806a39:	6a 01                	push   0x1
  806a3b:	c7 01 00 10 00 00    	mov    DWORD PTR [ecx],0x1000
  806a41:	8b 16                	mov    edx,DWORD PTR [esi]
  806a43:	51                   	push   ecx
  806a44:	52                   	push   edx
  806a45:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806a4c:	ff 15 bc 25 bd 00    	call   DWORD PTR ds:0xbd25bc
  806a52:	83 f8 ff             	cmp    eax,0xffffffff
  806a55:	75 54                	jne    0x806aab
  806a57:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806a5d:	8b d8                	mov    ebx,eax
  806a5f:	81 fb e5 03 00 00    	cmp    ebx,0x3e5
  806a65:	74 44                	je     0x806aab
  806a67:	8b 17                	mov    edx,DWORD PTR [edi]
  806a69:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806a6c:	6a 00                	push   0x0
  806a6e:	56                   	push   esi
  806a6f:	8b cf                	mov    ecx,edi
  806a71:	ff d0                	call   eax
  806a73:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  806a7a:	00 00 00 
  806a7d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806a81:	74 1d                	je     0x806aa0
  806a83:	8b 36                	mov    esi,DWORD PTR [esi]
  806a85:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806a8b:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806a8e:	50                   	push   eax
  806a8f:	53                   	push   ebx
  806a90:	56                   	push   esi
  806a91:	68 58 16 c5 00       	push   0xc51658
  806a96:	6a 02                	push   0x2
  806a98:	e8 63 99 ee ff       	call   0x6f0400
  806a9d:	83 c4 14             	add    esp,0x14
  806aa0:	5f                   	pop    edi
  806aa1:	5e                   	pop    esi
  806aa2:	33 c0                	xor    eax,eax
  806aa4:	5b                   	pop    ebx
  806aa5:	8b e5                	mov    esp,ebp
  806aa7:	5d                   	pop    ebp
  806aa8:	c2 04 00             	ret    0x4
  806aab:	e8 00 fb ff ff       	call   0x8065b0
  806ab0:	83 f8 01             	cmp    eax,0x1
  806ab3:	75 0c                	jne    0x806ac1
  806ab5:	8b 17                	mov    edx,DWORD PTR [edi]
  806ab7:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806aba:	6a 00                	push   0x0
  806abc:	56                   	push   esi
  806abd:	8b cf                	mov    ecx,edi
  806abf:	ff d0                	call   eax
  806ac1:	5f                   	pop    edi
  806ac2:	5e                   	pop    esi
  806ac3:	b8 01 00 00 00       	mov    eax,0x1
  806ac8:	5b                   	pop    ebx
  806ac9:	8b e5                	mov    esp,ebp
  806acb:	5d                   	pop    ebp
  806acc:	c2                   	.byte 0xc2
```

**BIN-first 原生 Assembly：IOCP service setup/GQCS**；VA `0x00806CF0..0x00806D9E`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4060F0`）：

```asm
  806cf0:	55                   	push   ebp
  806cf1:	8b ec                	mov    ebp,esp
  806cf3:	83 ec 24             	sub    esp,0x24
  806cf6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806cfb:	33 c5                	xor    eax,ebp
  806cfd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  806d00:	53                   	push   ebx
  806d01:	56                   	push   esi
  806d02:	33 f6                	xor    esi,esi
  806d04:	8b d9                	mov    ebx,ecx
  806d06:	57                   	push   edi
  806d07:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806d0a:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  806d0d:	89 75 e0             	mov    DWORD PTR [ebp-0x20],esi
  806d10:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  806d13:	3b fe                	cmp    edi,esi
  806d15:	74 19                	je     0x806d30
  806d17:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  806d1a:	50                   	push   eax
  806d1b:	68 d0 16 c5 00       	push   0xc516d0
  806d20:	56                   	push   esi
  806d21:	e8 da 96 ee ff       	call   0x6f0400
  806d26:	83 c4 0c             	add    esp,0xc
  806d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  806d30:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  806d37:	75 36                	jne    0x806d6f
  806d39:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  806d40:	56                   	push   esi
  806d41:	56                   	push   esi
  806d42:	56                   	push   esi
  806d43:	6a ff                	push   0xffffffff
  806d45:	89 35 b8 33 fe 00    	mov    DWORD PTR ds:0xfe33b8,esi
  806d4b:	89 35 bc 33 fe 00    	mov    DWORD PTR ds:0xfe33bc,esi
  806d51:	89 35 c0 33 fe 00    	mov    DWORD PTR ds:0xfe33c0,esi
  806d57:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806d5d:	68 b0 0b bd 00       	push   0xbd0bb0
  806d62:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806d67:	e8 ae b5 08 00       	call   0x89231a
  806d6c:	83 c4 04             	add    esp,0x4
  806d6f:	6a ff                	push   0xffffffff
  806d71:	8d 4d e0             	lea    ecx,[ebp-0x20]
  806d74:	51                   	push   ecx
  806d75:	8b 0d b8 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b8
  806d7b:	8d 55 e4             	lea    edx,[ebp-0x1c]
  806d7e:	52                   	push   edx
  806d7f:	8d 45 dc             	lea    eax,[ebp-0x24]
  806d82:	50                   	push   eax
  806d83:	51                   	push   ecx
  806d84:	ff 15 74 22 bd 00    	call   DWORD PTR ds:0xbd2274
  806d8a:	85 c0                	test   eax,eax
  806d8c:	0f 84 3d 01 00 00    	je     0x806ecf
  806d92:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806d95:	83 f8 01             	cmp    eax,0x1
  806d98:	0f 84 90 01 00 00    	je     0x806f2e
```

**BIN-first 原生 Assembly：IOCP recv completion / re-arm**；VA `0x00806DC0..0x00806E7D`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4061C0`）：

```asm
  806dc0:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  806dc3:	3b ce                	cmp    ecx,esi
  806dc5:	75 1d                	jne    0x806de4
  806dc7:	8b 13                	mov    edx,DWORD PTR [ebx]
  806dc9:	56                   	push   esi
  806dca:	50                   	push   eax
  806dcb:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806dce:	8b cb                	mov    ecx,ebx
  806dd0:	ff d0                	call   eax
  806dd2:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  806dd5:	c7 81 a8 a0 00 00 01 	mov    DWORD PTR [ecx+0xa0a8],0x1
  806ddc:	00 00 00 
  806ddf:	e9 4c ff ff ff       	jmp    0x806d30
  806de4:	8d b8 30 a0 00 00    	lea    edi,[eax+0xa030]
  806dea:	3b d7                	cmp    edx,edi
  806dec:	0f 85 8b 00 00 00    	jne    0x806e7d
  806df2:	01 4b 2c             	add    DWORD PTR [ebx+0x2c],ecx
  806df5:	ff 43 3c             	inc    DWORD PTR [ebx+0x3c]
  806df8:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806dfe:	0f 84 2c ff ff ff    	je     0x806d30
  806e04:	8d 50 18             	lea    edx,[eax+0x18]
  806e07:	50                   	push   eax
  806e08:	e8 33 0d 00 00       	call   0x807b40
  806e0d:	85 c0                	test   eax,eax
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74 3a                	je     0x806e6e
  806e34:	0f b6 48 0b          	movzx  ecx,BYTE PTR [eax+0xb]
  806e38:	0f b6 50 0a          	movzx  edx,BYTE PTR [eax+0xa]
  806e3c:	51                   	push   ecx
  806e3d:	0f b6 48 09          	movzx  ecx,BYTE PTR [eax+0x9]
  806e41:	52                   	push   edx
  806e42:	0f b6 50 08          	movzx  edx,BYTE PTR [eax+0x8]
  806e46:	51                   	push   ecx
  806e47:	52                   	push   edx
  806e48:	68 50 b0 bf 00       	push   0xbfb050
  806e4d:	8d 55 e8             	lea    edx,[ebp-0x18]
  806e50:	e8 db d4 cb ff       	call   0x4c4330
  806e55:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806e58:	8d 45 e8             	lea    eax,[ebp-0x18]
  806e5b:	50                   	push   eax
  806e5c:	68 18 17 c5 00       	push   0xc51718
  806e61:	6a 02                	push   0x2
  806e63:	e8 98 95 ee ff       	call   0x6f0400
  806e68:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e6b:	83 c4 20             	add    esp,0x20
  806e6e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  806e75:	00 00 00 
  806e78:	e9 b3 fe ff ff       	jmp    0x806d30
```

**BIN-first 原生 Assembly：IOCP send completion**；VA `0x00806E7D..0x00806ED0`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x40627D`）：

```asm
  806e7d:	8d b8 50 a0 00 00    	lea    edi,[eax+0xa050]
  806e83:	3b d7                	cmp    edx,edi
  806e85:	0f 85 a5 fe ff ff    	jne    0x806d30
  806e8b:	01 4b 28             	add    DWORD PTR [ebx+0x28],ecx
  806e8e:	ff 43 38             	inc    DWORD PTR [ebx+0x38]
  806e91:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806e97:	74 12                	je     0x806eab
  806e99:	8d b0 1c 50 00 00    	lea    esi,[eax+0x501c]
  806e9f:	8b f9                	mov    edi,ecx
  806ea1:	e8 0a 09 00 00       	call   0x8077b0
  806ea6:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806ea9:	33 f6                	xor    esi,esi
  806eab:	39 b0 28 a0 00 00    	cmp    DWORD PTR [eax+0xa028],esi
  806eb1:	0f 97 c1             	seta   cl
  806eb4:	88 88 24 a0 00 00    	mov    BYTE PTR [eax+0xa024],cl
  806eba:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  806ebd:	81 c2 b8 a0 00 00    	add    edx,0xa0b8
  806ec3:	52                   	push   edx
  806ec4:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
  806ecf:	8b                   	.byte 0x8b
```

**BIN-first 原生 Assembly：IOCP failure cleanup**；VA `0x00806ECF..0x00806F50`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4062CF`）：

```asm
  806ecf:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  806ed2:	3b ce                	cmp    ecx,esi
  806ed4:	0f 84 56 fe ff ff    	je     0x806d30
  806eda:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806edd:	8d 90 30 a0 00 00    	lea    edx,[eax+0xa030]
  806ee3:	3b ca                	cmp    ecx,edx
  806ee5:	74 19                	je     0x806f00
  806ee7:	8d 90 50 a0 00 00    	lea    edx,[eax+0xa050]
  806eed:	3b ca                	cmp    ecx,edx
  806eef:	75 0f                	jne    0x806f00
  806ef1:	05 b8 a0 00 00       	add    eax,0xa0b8
  806ef6:	50                   	push   eax
  806ef7:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806efd:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f00:	8b 80 b8 a0 00 00    	mov    eax,DWORD PTR [eax+0xa0b8]
  806f06:	85 c0                	test   eax,eax
  806f08:	0f 85 22 fe ff ff    	jne    0x806d30
  806f0e:	8b 13                	mov    edx,DWORD PTR [ebx]
  806f10:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f13:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  806f16:	56                   	push   esi
  806f17:	50                   	push   eax
  806f18:	8b cb                	mov    ecx,ebx
  806f1a:	ff d2                	call   edx
  806f1c:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f1f:	c7 80 a8 a0 00 00 01 	mov    DWORD PTR [eax+0xa0a8],0x1
  806f26:	00 00 00 
  806f29:	e9 02 fe ff ff       	jmp    0x806d30
  806f2e:	8b 5b 58             	mov    ebx,DWORD PTR [ebx+0x58]
  806f31:	3b de                	cmp    ebx,esi
  806f33:	74 10                	je     0x806f45
  806f35:	68 f4 16 c5 00       	push   0xc516f4
  806f3a:	56                   	push   esi
  806f3b:	8b fb                	mov    edi,ebx
  806f3d:	e8 be 94 ee ff       	call   0x6f0400
  806f42:	83 c4 08             	add    esp,0x8
  806f45:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  806f48:	5f                   	pop    edi
  806f49:	5e                   	pop    esi
  806f4a:	33 cd                	xor    ecx,ebp
  806f4c:	5b                   	pop    ebx
  806f4d:	e8                   	.byte 0xe8
  806f4e:	af                   	scas   eax,DWORD PTR es:[edi]
  806f4f:	a0                   	.byte 0xa0
```

**反證、邊界與下一待查**：**U** `Conn+A0B0` 的 close-once、bytes=0 的 EOF/keepalive 語意尚無完整 runtime。只能說支援多種 completion 類型，不能說 0x13 先於 0x0001 或任何事件在同 session 發生。

## E47.7 — 收包 framing decoder 的頭部白名單、長度與容量反證

**具體研究問題**：`0x807B40` 真的按哪些 frame magic 接受 stream？其安全邊界能否支援 0x0013 接收下游？

**分析、CFG／狀態與交叉證據**：

- **N** `0x807B40` 將 bytes 累加到 `Conn+0x5000`，在 buffer 少於4B時轉到 `0x807DDA` 暫存未完成前綴；讀 LE16 payload_length 時拒絕0 (`0x807BB5`) 及大於 `0x1000` (`0x807BC3`)，比對 header magic 至少包含 `0x2633` (8-byte header)、`0x0BBB` (6-byte)、`0x1A68` 與 `0x22D7` (4-byte)。
- **N** 即使某 magic 不匹配，0x807C34 仍走預設 header_len=4 的後續邏輯；從目前這個分支**不能宣稱不在白名單就必然 reject**，需看後段解析實際錯誤/轉發。
- **N** 0x807C3A 檢查 `header_len + payload_len <= buffered_avail` 才處理完整幀；0x807C93..C5 加上 base+0x5000 地址界線反證超出單一 recv half buffer 的直接解析；`0x807CD0` 對 `0x2633` 特殊碼走不同 XOR/decompress 流程，`0x807D06` 呼叫 `0x727190`，無法由此將 `0x2633` 視同 `0x0BBB` 簡單 checksum 格式。
- **C** 從解 frame 後再入 app FIFO 的流程在先前 E38–E46 已定向追查；本段重驗保留了半包、magic分支及丟棄/錯誤的 native 條件，不能以「已找到包頭」推導出次級 dispatch 一定收到 0x13。

**限定偽碼（推導，非原始 C++）**：

```cpp
bool parse_tcp_buffer(Conn *C, size_t available){
  if(available<4) return need_more;
  uint16_t n=read_le16(buffer); if(n==0 || n>0x1000) goto error;
  uint16_t magic=read_le16(buffer+2);
  unsigned hdr=(magic==0x2633?8:magic==0x0BBB?6:4);
  if(hdr+n>available) return need_more;
  // 0x2633 has dedicated decode path; 0x0BBB another route.
  // Accept/reject of unknown magic depends on later branches.
}
```

**BIN-first 原生 Assembly：frame length/magic/headlen/容量**；VA `0x00807B85..0x00807C44`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x406F85`）：

```asm
  807b85:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  807b88:	8b fa                	mov    edi,edx
  807b8a:	01 8f 00 50 00 00    	add    DWORD PTR [edi+0x5000],ecx
  807b90:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  807b94:	8b 87 00 50 00 00    	mov    eax,DWORD PTR [edi+0x5000]
  807b9a:	2b c7                	sub    eax,edi
  807b9c:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  807ba0:	8b df                	mov    ebx,edi
  807ba2:	83 f8 04             	cmp    eax,0x4
  807ba5:	0f 82 2f 02 00 00    	jb     0x807dda
  807bab:	eb 03                	jmp    0x807bb0
  807bad:	8d 49 00             	lea    ecx,[ecx+0x0]
  807bb0:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807bb3:	33 c9                	xor    ecx,ecx
  807bb5:	66 3b f1             	cmp    si,cx
  807bb8:	0f 84 5f 02 00 00    	je     0x807e1d
  807bbe:	ba 00 10 00 00       	mov    edx,0x1000
  807bc3:	66 3b f2             	cmp    si,dx
  807bc6:	0f 87 51 02 00 00    	ja     0x807e1d
  807bcc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  807bd0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  807bd4:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  807bd8:	ba 33 26 00 00       	mov    edx,0x2633
  807bdd:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807be4:	00 
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf1:	00 
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bf9:	00 
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0d:	00 
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c15:	00 
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c33:	00 
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
```

**BIN-first 原生 Assembly：frame buffer address guards/decode dispatch**；VA `0x00807C7C..0x00807D2C`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x40707C`）：

```asm
  807c7c:	bf 58 33 fe 00       	mov    edi,0xfe3358
  807c81:	e8 2a f9 ff ff       	call   0x8075b0
  807c86:	8d 3c 1e             	lea    edi,[esi+ebx*1]
  807c89:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807c8c:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  807c90:	8d 0c 3e             	lea    ecx,[esi+edi*1]
  807c93:	3b 7c 24 14          	cmp    edi,DWORD PTR [esp+0x14]
  807c97:	0f 82 39 01 00 00    	jb     0x807dd6
  807c9d:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807ca1:	81 c2 00 50 00 00    	add    edx,0x5000
  807ca7:	3b fa                	cmp    edi,edx
  807ca9:	0f 83 27 01 00 00    	jae    0x807dd6
  807caf:	3b 4c 24 14          	cmp    ecx,DWORD PTR [esp+0x14]
  807cb3:	0f 82 1d 01 00 00    	jb     0x807dd6
  807cb9:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  807cbd:	81 c2 00 50 00 00    	add    edx,0x5000
  807cc3:	3b ca                	cmp    ecx,edx
  807cc5:	0f 83 0b 01 00 00    	jae    0x807dd6
  807ccb:	83 7c 24 18 00       	cmp    DWORD PTR [esp+0x18],0x0
  807cd0:	74 5a                	je     0x807d2c
  807cd2:	8a 17                	mov    dl,BYTE PTR [edi]
  807cd4:	80 f2 7c             	xor    dl,0x7c
  807cd7:	b8 01 00 00 00       	mov    eax,0x1
  807cdc:	88 54 24 2c          	mov    BYTE PTR [esp+0x2c],dl
  807ce0:	3b f0                	cmp    esi,eax
  807ce2:	76 10                	jbe    0x807cf4
  807ce4:	8a 0c 07             	mov    cl,BYTE PTR [edi+eax*1]
  807ce7:	32 4c 04 2b          	xor    cl,BYTE PTR [esp+eax*1+0x2b]
  807ceb:	40                   	inc    eax
  807cec:	88 4c 04 2b          	mov    BYTE PTR [esp+eax*1+0x2b],cl
  807cf0:	3b c6                	cmp    eax,esi
  807cf2:	72 f0                	jb     0x807ce4
  807cf4:	8d 94 24 2c 10 00 00 	lea    edx,[esp+0x102c]
  807cfb:	52                   	push   edx
  807cfc:	8b ce                	mov    ecx,esi
  807cfe:	8d 44 24 30          	lea    eax,[esp+0x30]
  807d02:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  807d06:	c7 44 24 1c 00 10 00 	mov    DWORD PTR [esp+0x1c],0x1000
  807d0d:	00 
  807d0e:	e8 7d f4 f1 ff       	call   0x727190
  807d13:	83 c4 04             	add    esp,0x4
  807d16:	85 c0                	test   eax,eax
  807d18:	75 65                	jne    0x807d7f
  807d1a:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  807d1e:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  807d22:	8d 84 24 2c 10 00 00 	lea    eax,[esp+0x102c]
  807d29:	50                   	push   eax
  807d2a:	eb 4e                	jmp    0x807d7a
```

**BIN-first 原生 Assembly：send buffer drain / non-negative byte count**；VA `0x008077B0..0x0080782E`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x406BB0`）：

```asm
  8077b0:	53                   	push   ebx
  8077b1:	8b 1e                	mov    ebx,DWORD PTR [esi]
  8077b3:	53                   	push   ebx
  8077b4:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8077ba:	85 ff                	test   edi,edi
  8077bc:	78 5b                	js     0x807819
  8077be:	8b 86 0c 50 00 00    	mov    eax,DWORD PTR [esi+0x500c]
  8077c4:	3b c7                	cmp    eax,edi
  8077c6:	72 51                	jb     0x807819
  8077c8:	2b c7                	sub    eax,edi
  8077ca:	89 86 0c 50 00 00    	mov    DWORD PTR [esi+0x500c],eax
  8077d0:	74 3e                	je     0x807810
  8077d2:	8b 86 04 50 00 00    	mov    eax,DWORD PTR [esi+0x5004]
  8077d8:	8d 8e 04 50 00 00    	lea    ecx,[esi+0x5004]
  8077de:	8d 56 04             	lea    edx,[esi+0x4]
  8077e1:	2b c7                	sub    eax,edi
  8077e3:	3b d1                	cmp    edx,ecx
  8077e5:	73 32                	jae    0x807819
  8077e7:	3b c2                	cmp    eax,edx
  8077e9:	72 2e                	jb     0x807819
  8077eb:	3b c1                	cmp    eax,ecx
  8077ed:	73 2a                	jae    0x807819
  8077ef:	89 01                	mov    DWORD PTR [ecx],eax
  8077f1:	2b c6                	sub    eax,esi
  8077f3:	83 e8 04             	sub    eax,0x4
  8077f6:	50                   	push   eax
  8077f7:	8d 44 37 04          	lea    eax,[edi+esi*1+0x4]
  8077fb:	50                   	push   eax
  8077fc:	52                   	push   edx
  8077fd:	e8 ce 63 09 00       	call   0x89dbd0
  807802:	83 c4 0c             	add    esp,0xc
  807805:	53                   	push   ebx
  807806:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80780c:	b0 01                	mov    al,0x1
  80780e:	5b                   	pop    ebx
  80780f:	c3                   	ret
  807810:	8d 4e 04             	lea    ecx,[esi+0x4]
  807813:	89 8e 04 50 00 00    	mov    DWORD PTR [esi+0x5004],ecx
  807819:	53                   	push   ebx
  80781a:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807820:	32 c0                	xor    al,al
  807822:	5b                   	pop    ebx
  807823:	c3                   	ret
  807824:	cc                   	int3
  807825:	cc                   	int3
  807826:	cc                   	int3
  807827:	cc                   	int3
  807828:	cc                   	int3
  807829:	cc                   	int3
  80782a:	cc                   	int3
  80782b:	cc                   	int3
  80782c:	cc                   	int3
  80782d:	cc                   	int3
```

**反證、邊界與下一待查**：**U** 必須完整追 `0x807D2C` plain/0BBB 後段、特殊壞 checksum/壞 compression、FIFO enqueue 才能嚴格宣稱 message validation；這與 RR-0006 的專門 compression issue 有重疊，不越權寫入其他 Task 狀態。

## E47.8 — Command 0x0013 vs 0x007A：長度下游問題已縮小為 dispatcher ABI 缺失

**具體研究問題**：本地 S2C parser 是否知道 payload 總長，會不會檢查群組數量與 child 10B 的底限？

**分析、CFG／狀態與交叉證據**：

- **N** 第二層 `0x4C4670` 以 signed16 command 索引 `esi+0x5EAC+cmd*8`，若 handler 不存在 fallback `0x4FDA30`；本次原生檢查 `0x4C3220` 確實寫 `0x4C37A0` 到 offset 0x5F44（cmd 0x13）、`0x4C3C10` 到 0x627C（cmd 0x7A）。
- **N** `0x4C3C10` 直接把 `[payload+2]` DWORD 作 0x4C3080 的唯一 stack arg，`lea ecx,[payload+6]` 作資料起點，函式**沒有在這個短 handler 裡比較 payload_length**。`0x4C37A0` 先讀 `[payload+0x16]` 作分支判定，合格 branch 之 `0x4C3A0A` 取 `[payload+0x92]` 作資料基址、呼叫 `0x4C3080`；也沒有就地把 `length` 參數傳給 parser。
- **N** `0x4C3080` 在開始時讀 `[ebp+8]` group_count，`test EBX,EBX` 為 0 不處理，但非零逐 group 讀 `[ESI]` WORD 和 `[ESI+2]` byte count，進入子迴圈每個 child 固定 `add edi,0xA`，讀 `[child+4..+9]`；只用 declared count 控制 loops，沒有直接 total_byte_count 上限欄位，因此不能因 `0x807B40` 最大 frame 為4096就推出 parser 一定安全。
- **U** 接收端的上層 dispatcher (`0x48AAD0`、`0x4FDA30`、`0x4C4670`) 雖有 length 傳遞在某些層，當前分支未找到下游 parser 對 `len >= 6+3*groups+10*sum(children)` 類型的總長檢查；需確認 `0x4C37A0` 的 0x92 下游最小 input guard 或封包本來已經由外部類型擔保，不可虛構。

**限定偽碼（推導，非原始 C++）**：

```cpp
// for 0x007A only; source length is NOT passed to 4C3080 in this native handler:
unsigned groups = *(uint32_t*)(payload+2);
parse_choice_groups_4C3080(payload+6, groups);
// each group: +0 word key, +2 byte childcount, +3 start children
// each child: exactly 10 bytes in this parser, fixed count-controlled.
// 0x0013 uses condition-dependent payload+0x92 origin; never equate layouts.
```

**BIN-first 原生 Assembly：兩條 handler registrations**；VA `0x004C3220..0x004C327B`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x0C2620`）：

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
```

**BIN-first 原生 Assembly：command secondary dispatcher**；VA `0x004C4670..0x004C46EE`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x0C3A70`）：

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
  4c46ed:	c2                   	.byte 0xc2
```

**BIN-first 原生 Assembly：0x007A short handler**；VA `0x004C3C10..0x004C3C29`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x0C3010`）：

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

**BIN-first 原生 Assembly：0x0013 mode/choice parser call**；VA `0x004C39E0..0x004C3A24`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x0C2DE0`）：

```asm
  4c39e0:	ff                   	(bad)
  4c39e1:	ff 8d 8e 87 00 00    	dec    DWORD PTR [ebp+0x878e]
  4c39e7:	00 51 8d             	add    BYTE PTR [ecx-0x73],dl
  4c39ea:	97                   	xchg   edi,eax
  4c39eb:	99                   	cdq
  4c39ec:	68 00 00 6a 05       	push   0x56a0000
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
```

**BIN-first 原生 Assembly：group parser 10B stride**；VA `0x004C3094..0x004C314A`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x0C2494`）：

```asm
  4c3094:	53                   	push   ebx
  4c3095:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4c3098:	56                   	push   esi
  4c3099:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  4c309f:	57                   	push   edi
  4c30a0:	83 c6 08             	add    esi,0x8
  4c30a3:	8b f9                	mov    edi,ecx
  4c30a5:	e8 96 11 00 00       	call   0x4c4240
  4c30aa:	85 db                	test   ebx,ebx
  4c30ac:	0f 84 98 00 00 00    	je     0x4c314a
  4c30b2:	89 5c 24 0c          	mov    DWORD PTR [esp+0xc],ebx
  4c30b6:	8b 15 54 1b fe 00    	mov    edx,DWORD PTR ds:0xfe1b54
  4c30bc:	8b df                	mov    ebx,edi
  4c30be:	0f b7 0b             	movzx  ecx,WORD PTR [ebx]
  4c30c1:	83 c7 03             	add    edi,0x3
  4c30c4:	e8 47 44 04 00       	call   0x507510
  4c30c9:	80 7b 02 00          	cmp    BYTE PTR [ebx+0x2],0x0
  4c30cd:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4c30d1:	c7 44 24 10 00 00 00 	mov    DWORD PTR [esp+0x10],0x0
  4c30d8:	00 
  4c30d9:	76 65                	jbe    0x4c3140
  4c30db:	eb 03                	jmp    0x4c30e0
  4c30dd:	8d 49 00             	lea    ecx,[ecx+0x0]
  4c30e0:	8b f7                	mov    esi,edi
  4c30e2:	0f b6 46 07          	movzx  eax,BYTE PTR [esi+0x7]
  4c30e6:	0f b6 4e 06          	movzx  ecx,BYTE PTR [esi+0x6]
  4c30ea:	0f b6 56 05          	movzx  edx,BYTE PTR [esi+0x5]
  4c30ee:	50                   	push   eax
  4c30ef:	0f b6 46 04          	movzx  eax,BYTE PTR [esi+0x4]
  4c30f3:	51                   	push   ecx
  4c30f4:	52                   	push   edx
  4c30f5:	50                   	push   eax
  4c30f6:	68 50 b0 bf 00       	push   0xbfb050
  4c30fb:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  4c30ff:	83 c7 0a             	add    edi,0xa
  4c3102:	e8 29 12 00 00       	call   0x4c4330
  4c3107:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  4c310b:	83 c4 14             	add    esp,0x14
  4c310e:	85 c9                	test   ecx,ecx
  4c3110:	74 1d                	je     0x4c312f
  4c3112:	0f b7 06             	movzx  eax,WORD PTR [esi]
  4c3115:	8d 54 24 18          	lea    edx,[esp+0x18]
  4c3119:	52                   	push   edx
  4c311a:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  4c311e:	50                   	push   eax
  4c311f:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  4c3123:	50                   	push   eax
  4c3124:	a1 54 1b fe 00       	mov    eax,ds:0xfe1b54
  4c3129:	50                   	push   eax
  4c312a:	e8 e1 44 04 00       	call   0x507610
  4c312f:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4c3133:	0f b6 4b 02          	movzx  ecx,BYTE PTR [ebx+0x2]
  4c3137:	40                   	inc    eax
  4c3138:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4c313c:	3b c1                	cmp    eax,ecx
  4c313e:	72 a0                	jb     0x4c30e0
  4c3140:	ff 4c 24 0c          	dec    DWORD PTR [esp+0xc]
  4c3144:	0f 85 6c ff ff ff    	jne    0x4c30b6
```

**反證、邊界與下一待查**：**安全界線**：靜態缺少直接 total-length guard 的證據不是已證某條真實網路封包可造成 OOB，也不代表必然沒有 upstream envelope validation。將其標成「Client 待逆向」及合法 fuzz/trace 需求。

## E47.9 — A02C/F94294 直接 operand xref、zero-first branch 與穩定性界線

**具體研究問題**：可否不靠 runtime 確認 A02C 的非初始模式 setter、F94294 的非零 writer？

**分析、CFG／狀態與交叉證據**：

- **N** 對整個 PE `.text` 的原件完整 `objdump -d` 清單依 operand bytes 搜索，直接記錄 `Conn+A02C` 的固定 displacement (`2C A0 00 00`) **僅兩處**：`0x805D02 mov byte[esi+A02C],2` 與 `0x806202 movsx eax,byte[esi+A02C]`。這表示全 `.text` 直接常數 displacement 只有一個 writer、一個 reader；不包含透過 `[reg+offset]` 計算地址、memcpy、inline aliases 或插件／外部程式改寫。
- **N** `F94294` 直接位址 (`94 42 F9 00`) 也**僅兩處**：`0x4E16BF mov [F94294],ebx`（由此前 E46 已驗對此初始化的 EBX=0）、`0x66C17E cmp [F94294],0`。沒有從本檔的直接 literal reference 找到任何非零 writer，因此目前沒有 native 根據宣稱 `F94294!=0` 會在一般玩家選服時變為可達。
- **N** `0x66C090` 在選服 UI 收到 local selected keys 後，先 `0x5078C0` 得 record+4 type，再 `0x507750` 得 record+0xC endpoint；`0x66C17E` gate 非零時可 `0x66C1A7 call 0x4957C0`；為零則跳 `0x66C21D` alternative，對 type 有不同集合判斷且 endpoint 非零時 `0x66C247 call 0x4957C0`。故**沒有證明非零 flag 也不會阻斷全部選服**，zero-first branch 有自己的 connect 可達域。
- **C** 要求靜態全體 writer「不存在」超越單一 module/.text 的 direct operand 結果；定位 indirect writer 需動態監看精確 4-byte global address 或深度全程 alias/指標存取分析。

**限定偽碼（推導，非原始 C++）**：

```cpp
// Native E47 direct-displacement / absolute operand count:
//  Conn+A02C: 805D02 write constant2; 806202 read signed byte
//  F94294:   4E16BF write EBX (zero on known init); 66C17E compare 0
if (F94294 != 0) {
    if(record_type && endpoint) connect_4957C0(endpoint);
} else {
    if(alternative_type_gate && endpoint) connect_4957C0(endpoint);
}
```

**BIN-first 原生 Assembly：選服 state type / endpoint lookup**；VA `0x0066C128..0x0066C17E`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x26B528`）：

```asm
  66c128:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  66c12e:	57                   	push   edi
  66c12f:	50                   	push   eax
  66c130:	8b c6                	mov    eax,esi
  66c132:	e8 89 b7 e9 ff       	call   0x5078c0
  66c137:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  66c13b:	57                   	push   edi
  66c13c:	8b d8                	mov    ebx,eax
  66c13e:	51                   	push   ecx
  66c13f:	8b c6                	mov    eax,esi
  66c141:	e8 0a b6 e9 ff       	call   0x507750
  66c146:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  66c14d:	8b f0                	mov    esi,eax
  66c14f:	75 2a                	jne    0x66c17b
  66c151:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  66c158:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  66c15f:	00 
  66c160:	e8 2b 54 e7 ff       	call   0x4e1590
  66c165:	68 80 cc bc 00       	push   0xbccc80
  66c16a:	e8 ab 61 22 00       	call   0x89231a
  66c16f:	83 c4 04             	add    esp,0x4
  66c172:	83 cf ff             	or     edi,0xffffffff
  66c175:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  66c179:	eb 03                	jmp    0x66c17e
  66c17b:	83 cf ff             	or     edi,0xffffffff
```

**BIN-first 原生 Assembly：F94294 gate & first conditional Connect**；VA `0x0066C17E..0x0066C1B2`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x26B57E`）：

```asm
  66c17e:	83 3d 94 42 f9 00 00 	cmp    DWORD PTR ds:0xf94294,0x0
  66c185:	0f 84 92 00 00 00    	je     0x66c21d
  66c18b:	85 db                	test   ebx,ebx
  66c18d:	0f 84 8a 00 00 00    	je     0x66c21d
  66c193:	85 f6                	test   esi,esi
  66c195:	0f 84 1e 03 00 00    	je     0x66c4b9
  66c19b:	e8 e0 84 da ff       	call   0x414680
  66c1a0:	56                   	push   esi
  66c1a1:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c1a7:	e8 14 96 e2 ff       	call   0x4957c0
  66c1ac:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  66c1af:	8b                   	.byte 0x8b
  66c1b0:	82                   	.byte 0x82
  66c1b1:	f0                   	lock
```

**BIN-first 原生 Assembly：zero branch alternate gate**；VA `0x0066C21D..0x0066C268`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x26B61D`）：

```asm
  66c21d:	83 fb 04             	cmp    ebx,0x4
  66c220:	74 52                	je     0x66c274
  66c222:	85 db                	test   ebx,ebx
  66c224:	0f 84 bc 01 00 00    	je     0x66c3e6
  66c22a:	83 fb 05             	cmp    ebx,0x5
  66c22d:	0f 84 bc 01 00 00    	je     0x66c3ef
  66c233:	85 f6                	test   esi,esi
  66c235:	0f 84 7e 02 00 00    	je     0x66c4b9
  66c23b:	e8 40 84 da ff       	call   0x414680
  66c240:	56                   	push   esi
  66c241:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c247:	e8 74 95 e2 ff       	call   0x4957c0
  66c24c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66c24f:	8b 80 f0 00 00 00    	mov    eax,DWORD PTR [eax+0xf0]
  66c255:	e8 d6 02 dc ff       	call   0x42c530
  66c25a:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c25f:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c263:	64                   	fs
  66c264:	89                   	.byte 0x89
  66c265:	0d                   	.byte 0xd
```

**BIN-first 原生 Assembly：flag initial clear**；VA `0x004E16AA..0x004E16D3`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x0E0AAA`）：

```asm
  4e16aa:	42                   	inc    edx
  4e16ab:	f9                   	stc
  4e16ac:	00 89 1d 84 42 f9    	add    BYTE PTR [ecx-0x6bd7be3],cl
  4e16b2:	00 89 1d 8c 42 f9    	add    BYTE PTR [ecx-0x6bd73e3],cl
  4e16b8:	00 88 1d 90 42 f9    	add    BYTE PTR [eax-0x6bd6fe3],cl
  4e16be:	00 89 1d 94 42 f9    	add    BYTE PTR [ecx-0x6bd6be3],cl
  4e16c4:	00 89 1d 98 42 f9    	add    BYTE PTR [ecx-0x6bd67e3],cl
  4e16ca:	00 c7                	add    bh,al
  4e16cc:	05 9c 42 f9 00       	add    eax,0xf9429c
  4e16d1:	ff                   	(bad)
  4e16d2:	ff                   	.byte 0xff
```

**BIN-first 原生 Assembly：Conn constructor mode writer**；VA `0x00805CF6..0x00805D18`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4050F6`）：

```asm
  805cf6:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805cfc:	89 be 1c 50 00 00    	mov    DWORD PTR [esi+0x501c],edi
  805d02:	c6 86 2c a0 00 00 02 	mov    BYTE PTR [esi+0xa02c],0x2
  805d09:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805d0f:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805d15:	89                   	.byte 0x89
  805d16:	9e                   	sahf
  805d17:	28                   	.byte 0x28
```

**BIN-first 原生 Assembly：mode reader & encoder branch**；VA `0x008061F6..0x0080624F`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4055F6`）：

```asm
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
```

**反證、邊界與下一待查**：**反證**：`F94294` 零時 *有*別的 connect 路徑，不能把缺非零 writer 當作所有登入不可選服。direct operand 搜尋的覆蓋範圍與限制需同時紀錄；切勿稱 native 遊戲沒有 setter。

## E47.10 — 起訖鏈、失敗矩陣、準確的驗收停止條件與 E48 可執行的補證

**具體研究問題**：經十個實質子段、能否完全宣稱端到端 first wire/first S2C 已閉合？若否，具體卡點和最小可操作驗證契約是什麼？

**分析、CFG／狀態與交叉證據**：

### 已有足夠的 native 交叉證據之**條件式完整網路子鏈**

1. 登入/伺服器列表消息 **cmd0x13 的限定分支／cmd0x7A 的另一處理入口** → `0x4C3080` 逐 3B group header、10B children → `0x507510/0x507610` 在 `FE1B54` 建 records（E44/E45 原件多次復核）。`child+4..7` 組成 IPv4 十進位，`record+0xC` endpoint 位址被 UI 查找。
2. `0x66C090` UI lookup type & address → 經 `F94294` nonzero 或 zero 分支各自的 gated `0x4957C0`，**不是所有記錄必定 Connect**；`F94294` 的直接原件可見初始化零，非零 writer 無直接 literal 證據。
3. `0x48C0E6` 建真正 network manager `FBA854`，vptr `0xC51748`；`0x4957C0` 的 `+0x18` 虛呼叫精確到 `0x806AD0`，先 key0 port `0x20E0`，再 key2 port `0x20DE`；`0x806AD0` pool_take `0x805950`、socket→connect→setsockopt→IOCP association→active list。不是 E46 誤用的 `FBA7CC+4` 泛型指標。
4. 只有兩 Conn 成立，`0x4957C0` 才排入 key0 57B 0x0001：manager `+0x10→0x8069A0→0x8060D0`；可由 `A02C` 選 encoded/plain → `+0x0C→0x8068B0→WSASend`；此為 native **可達條件鏈**，不是 first-wire observation。
5. `+0x14→0x806A00 WSARecv`，`+0x04→0x806CF0 GQCS`，以 Conn+A030 (receive)/+A050 (send) 分枝，receive `0x807B40` 解析 frame → 已在 E41 等驗明的 app queue/callback/dispatch conditional chain；不能把 callback vptr 是否曾在真實 session 命中當作已觀察。

### 分類與失敗/反證矩陣

| 邊界 | N 原生支持 | 失敗／不同分支 | 欠缺／狀態 |
|---|---|---|---|
| Manager global | startup 80470F writes `FBA854` from 0x5C-object, C51748 | 803F76/8045EE 清零 | live object lifetime 未觀察 |
| Conn acquisition | 805950 active pool pop/reuse/new, 805CA0 mode2 | OOM/slot reuse、partial rollback | A02C indirect writer 未定位 |
| TCP Connect | 806AD0 socket ordinal4 connect, key/port + lane2 | socket/option failure returns null/recycles | network trace 缺 |
| key0 local initial | 4957C0 2 Conn guard, 8069A0 keyed queue | missing key, zero size, backlog | 真正首 frame 未定位 |
| send | 8068B0 WSASend / pending997 branch | ordinary error and state flag | completion timing 缺 |
| receive | 806A00 WSARecv and 806CF0 IOCP type | EOF/no data/failed overlapped | 首個 S2C command 缺 |
| frame | 807B40 len 1..4096, 2633/0BBB/plain branches | half frame / wrong length / checksum path | magic 未知時處置未全驗 |
| command | 4C4670, cmd13/7A → 4C3080 | conditional branch & optional fallback | full input length guard 缺 |
| UI Connect gate | F94294=0 known startup, zero branch alternate | type gate/record endpoint absent | nonzero alias writer 未定位 |

### 必須收集的**同一合法 session** 最小 trace（本次完全未做）

- **T0** Startup `0x80470F`：記錄 `FBA854` 指標、`[FBA854]` vptr 必須為 C51748，`FBA7CC` 另行記錄但不當等價。
- **T1** 收到 cmd0x13 或 0x7A：記錄 packet size、key/lane、`0x807B40` decode path、0x4C4670 handler dispatch、`0x4C3080` group count/count*10，UI record+0xC 的 IP 字串。
- **T2** `0x66C090`：監看 `F94294` DWORD、type、endpoint，該 local event 選走兩個 `0x4957C0` 中哪個。若從未 connect，回收 UI branch/record 提供做 Client 待逆向。
- **T3** `0x806AD0`：對 key0／key2 分別記錄 `Conn*`, socket, sockaddr IPv4/port, actual `connect()` success, `CreateIoCompletionPort` completion key, 其 `Conn+A02C` mode；重用與新建分開。
- **T4** `0x8069A0` local enqueue ID+len、每個 Conn 的 queue-before/after；`0x806202` mode、0x807830 是否成功、0x807A70 是否 fallback；`0x8068B0` 每個 WSASend bytes (hash/hex/len/key/port) 和 GQCS 記錄。排序須使用單一 clock、每事件單調 sequence ID。
- **T5** 第一個 `WSARecv`/GQCS bytes、frame magic、decoded cmd、callback identity 與 UI response。須注意 TCP segmentation 以及 completion 並不與單一 message 一對一。

**應提交的測試資料**：合法採得之每個 session `events.csv` (seq, time, thread, Conn*, key/lane, opcode, frame magic, len, outcome)、二進位 pcap/WSA bytes、UI 最小狀態截圖、commit hashes/版本與分支；敏感身份/token IP 需遮蔽或安全保存，報告不要外洩。無 live trace 時不能虛稱本段已達 A。

### 工程分工與四種完成狀態

- **Client 待逆向**：0x13/0x7A 最小 input length guard；A02C computed/alias setter；F94294 非零全域 writer；GQCS 發現的 earliest server command、WSASend packet exact bytes與時序；socket 成功後業務狀態更新。
- **Server 待開發**：以已證 Client 接口做兼容 Server DRAFT 協定/登錄資料/端點；不能推測原版認證資料庫或業務規則。固定 `0x20E0/0x20DE` 是原生 Client **呼叫站** port，非對未來部署的無條件建議。
- **跨功能待整合**：T02 native transport proof、T03 handler/UI proof、T01 嚴格有界 FULL-PASS 驗收、S00 GAP-NET-0002 設計發布；本稿沒有權限擅改上述任一狀態。
- **待遊玩驗證**：同 session 間連線確立/消息回覆/畫面轉換、Server 可連與可玩性。離線靜態 native 與實際可玩完全分開。

**正式停止 B**：E47.1–E47.10 十個大子段已做，第一手機器碼含物件生命週期、虛表、pool、Winsock connect、send/recv、IOCP、framing、UI/handler guard、fail paths；但未有第一實際 wire/first response 的執行時序，無法再靠靜態資料排定。**不啟動 E47.11**。E48 應精準補 `806AD0` partial close/rollback、`806CF0` 各 FAILED-overlapped、`807B40` 後半 checksum/FIFO、`0x13/7A` 上游 length parameter 一路如何消失，並若可提供合法 trace 再驗第一序；不重做 FBA7CC+4 的非相關假設。

**限定偽碼（推導，非原始 C++）**：

```cpp
// Summary: hypothetical event order needed, not a proven actual sequence.
// Native static proof only establishes conditional call paths:
if (server_list_command_is_valid) update_FE1B54_records();
if (ui_event_selects_record && gate_allows) {
    Conn *k0 = net_connect(ip,0x20E0, key0,lane2);
    Conn *k2 = net_connect(ip,0x20DE, key2,lane2);
    if(k0 && k2) enqueue(k0, payload_0x0001, 57);
}
// runtime send and S2C order remain indeterminate in absence of trace.
```

**BIN-first 原生 Assembly：native local enqueue & manager side effects**；VA `0x004957C0..0x00495865`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x094BC0`）：

```asm
  4957c0:	55                   	push   ebp
  4957c1:	8b ec                	mov    ebp,esp
  4957c3:	83 ec 44             	sub    esp,0x44
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9 7e 00 00 00       	mov    ecx,0x7e
  495843:	6a 02                	push   0x2
  495845:	8d 55 be             	lea    edx,[ebp-0x42]
  495848:	66 89 4d be          	mov    WORD PTR [ebp-0x42],cx
  49584c:	8b 8e 60 bf 00 00    	mov    ecx,DWORD PTR [esi+0xbf60]
  495852:	52                   	push   edx
  495853:	e8 78 08 37 00       	call   0x8060d0
  495858:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  49585e:	c7                   	.byte 0xc7
  49585f:	80                   	.byte 0x80
  495860:	b0 a0                	mov    al,0xa0
  495862:	00 00                	add    BYTE PTR [eax],al
  495864:	01                   	.byte 0x1
```

**BIN-first 原生 Assembly：完成 key0 enqueue 與 fail close**；VA `0x00495915..0x004959EA`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x094D15`）：

```asm
  495915:	40                   	inc    eax
  495916:	e2 3f                	loop   0x495957
  495918:	00 83 c4 2c e8 7f    	add    BYTE PTR [ebx+0x7fe82cc4],al
  49591e:	f2 f6 ff             	repnz idiv bh
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
  495961:	5f                   	pop    edi
  495962:	89 9e 68 bf 00 00    	mov    DWORD PTR [esi+0xbf68],ebx
  495968:	b8 01 00 00 00       	mov    eax,0x1
  49596d:	5b                   	pop    ebx
  49596e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  495971:	33 cd                	xor    ecx,ebp
  495973:	e8 89 b6 3f 00       	call   0x891001
  495978:	8b e5                	mov    esp,ebp
  49597a:	5d                   	pop    ebp
  49597b:	c2 04 00             	ret    0x4
  49597e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495984:	8b 01                	mov    eax,DWORD PTR [ecx]
  495986:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495989:	6a 01                	push   0x1
  49598b:	6a 00                	push   0x0
  49598d:	ff d2                	call   edx
  49598f:	68 3c 5a c0 00       	push   0xc05a3c
  495994:	e8 c7 81 25 00       	call   0x6edb60
  495999:	83 c4 04             	add    esp,0x4
  49599c:	5f                   	pop    edi
  49599d:	33 c0                	xor    eax,eax
  49599f:	5b                   	pop    ebx
  4959a0:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959a3:	33 cd                	xor    ecx,ebp
  4959a5:	e8 57 b6 3f 00       	call   0x891001
  4959aa:	8b e5                	mov    esp,ebp
  4959ac:	5d                   	pop    ebp
  4959ad:	c2 04 00             	ret    0x4
  4959b0:	68 1c 5a c0 00       	push   0xc05a1c
  4959b5:	e8 a6 81 25 00       	call   0x6edb60
  4959ba:	83 c4 04             	add    esp,0x4
  4959bd:	85 db                	test   ebx,ebx
  4959bf:	74 ce                	je     0x49598f
  4959c1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4959c7:	8b 01                	mov    eax,DWORD PTR [ecx]
  4959c9:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4959cc:	6a 01                	push   0x1
  4959ce:	6a 02                	push   0x2
  4959d0:	ff d2                	call   edx
  4959d2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959d5:	5f                   	pop    edi
  4959d6:	33 cd                	xor    ecx,ebp
  4959d8:	33 c0                	xor    eax,eax
  4959da:	5b                   	pop    ebx
  4959db:	e8 21 b6 3f 00       	call   0x891001
  4959e0:	8b e5                	mov    esp,ebp
  4959e2:	5d                   	pop    ebp
  4959e3:	c2 04 00             	ret    0x4
  4959e6:	cc                   	int3
  4959e7:	cc                   	int3
  4959e8:	cc                   	int3
  4959e9:	cc                   	int3
```

**BIN-first 原生 Assembly：IOCP recv/send branch summary evidence**；VA `0x00806DE0..0x00806EBB`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x4061E0`）：

```asm
  806de0:	4c                   	dec    esp
  806de1:	ff                   	(bad)
  806de2:	ff                   	(bad)
  806de3:	ff 8d b8 30 a0 00    	dec    DWORD PTR [ebp+0xa030b8]
  806de9:	00 3b                	add    BYTE PTR [ebx],bh
  806deb:	d7                   	xlat   BYTE PTR ds:[ebx]
  806dec:	0f 85 8b 00 00 00    	jne    0x806e7d
  806df2:	01 4b 2c             	add    DWORD PTR [ebx+0x2c],ecx
  806df5:	ff 43 3c             	inc    DWORD PTR [ebx+0x3c]
  806df8:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806dfe:	0f 84 2c ff ff ff    	je     0x806d30
  806e04:	8d 50 18             	lea    edx,[eax+0x18]
  806e07:	50                   	push   eax
  806e08:	e8 33 0d 00 00       	call   0x807b40
  806e0d:	85 c0                	test   eax,eax
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74 3a                	je     0x806e6e
  806e34:	0f b6 48 0b          	movzx  ecx,BYTE PTR [eax+0xb]
  806e38:	0f b6 50 0a          	movzx  edx,BYTE PTR [eax+0xa]
  806e3c:	51                   	push   ecx
  806e3d:	0f b6 48 09          	movzx  ecx,BYTE PTR [eax+0x9]
  806e41:	52                   	push   edx
  806e42:	0f b6 50 08          	movzx  edx,BYTE PTR [eax+0x8]
  806e46:	51                   	push   ecx
  806e47:	52                   	push   edx
  806e48:	68 50 b0 bf 00       	push   0xbfb050
  806e4d:	8d 55 e8             	lea    edx,[ebp-0x18]
  806e50:	e8 db d4 cb ff       	call   0x4c4330
  806e55:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806e58:	8d 45 e8             	lea    eax,[ebp-0x18]
  806e5b:	50                   	push   eax
  806e5c:	68 18 17 c5 00       	push   0xc51718
  806e61:	6a 02                	push   0x2
  806e63:	e8 98 95 ee ff       	call   0x6f0400
  806e68:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e6b:	83 c4 20             	add    esp,0x20
  806e6e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  806e75:	00 00 00 
  806e78:	e9 b3 fe ff ff       	jmp    0x806d30
  806e7d:	8d b8 50 a0 00 00    	lea    edi,[eax+0xa050]
  806e83:	3b d7                	cmp    edx,edi
  806e85:	0f 85 a5 fe ff ff    	jne    0x806d30
  806e8b:	01 4b 28             	add    DWORD PTR [ebx+0x28],ecx
  806e8e:	ff 43 38             	inc    DWORD PTR [ebx+0x38]
  806e91:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806e97:	74 12                	je     0x806eab
  806e99:	8d b0 1c 50 00 00    	lea    esi,[eax+0x501c]
  806e9f:	8b f9                	mov    edi,ecx
  806ea1:	e8 0a 09 00 00       	call   0x8077b0
  806ea6:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806ea9:	33 f6                	xor    esi,esi
  806eab:	39 b0 28 a0 00 00    	cmp    DWORD PTR [eax+0xa028],esi
  806eb1:	0f 97 c1             	seta   cl
  806eb4:	88 88 24 a0 00 00    	mov    BYTE PTR [eax+0xa024],cl
  806eba:	8b                   	.byte 0x8b
```

**BIN-first 原生 Assembly：decoder 0BBB/plain magic**；VA `0x00807BB0..0x00807C44`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x406FB0`）：

```asm
  807bb0:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  807bb3:	33 c9                	xor    ecx,ecx
  807bb5:	66 3b f1             	cmp    si,cx
  807bb8:	0f 84 5f 02 00 00    	je     0x807e1d
  807bbe:	ba 00 10 00 00       	mov    edx,0x1000
  807bc3:	66 3b f2             	cmp    si,dx
  807bc6:	0f 87 51 02 00 00    	ja     0x807e1d
  807bcc:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  807bd0:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  807bd4:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  807bd8:	ba 33 26 00 00       	mov    edx,0x2633
  807bdd:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807be4:	00 
  807be5:	66 3b ca             	cmp    cx,dx
  807be8:	75 12                	jne    0x807bfc
  807bea:	c7 44 24 18 01 00 00 	mov    DWORD PTR [esp+0x18],0x1
  807bf1:	00 
  807bf2:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  807bf9:	00 
  807bfa:	eb 38                	jmp    0x807c34
  807bfc:	ba bb 0b 00 00       	mov    edx,0xbbb
  807c01:	66 3b ca             	cmp    cx,dx
  807c04:	75 12                	jne    0x807c18
  807c06:	c7 44 24 1c 01 00 00 	mov    DWORD PTR [esp+0x1c],0x1
  807c0d:	00 
  807c0e:	c7 44 24 20 06 00 00 	mov    DWORD PTR [esp+0x20],0x6
  807c15:	00 
  807c16:	eb 1c                	jmp    0x807c34
  807c18:	ba 68 1a 00 00       	mov    edx,0x1a68
  807c1d:	66 3b ca             	cmp    cx,dx
  807c20:	74 0a                	je     0x807c2c
  807c22:	ba d7 22 00 00       	mov    edx,0x22d7
  807c27:	66 3b ca             	cmp    cx,dx
  807c2a:	75 08                	jne    0x807c34
  807c2c:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  807c33:	00 
  807c34:	8b ce                	mov    ecx,esi
  807c36:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  807c3a:	03 ce                	add    ecx,esi
  807c3c:	3b c8                	cmp    ecx,eax
  807c3e:	0f 8f 96 01 00 00    	jg     0x807dda
```

**BIN-first 原生 Assembly：S2C 0x7A parser entry**；VA `0x004C3C10..0x004C3C29`；`.text` raw 由 `VA - 0x400C00` 逐段換算（起始 raw `0x0C3010`）：

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

**反證、邊界與下一待查**：**阻塞記錄／停止根據**：以直接 literal writer 掃描、完整 vtable、兩種 Conn pool 取得、精確 connect success paths、兩種 overlapped completion、frame header、0x13/0x7A handler 查核後，仍無唯一 first-send/first-response 觀測。這不是「發現重要函式就停」，而是 B（10子段）強制交付；可繼續的 E48 問題已列並區分靜態可做與需合法執行的事項。

## 原始檔驗證、可重現命令與提交邊界

```bash
sha256sum Tartaros.bin
objdump -h Tartaros.bin
objdump -p Tartaros.bin | grep -E 'WSASend|WSARecv|GetQueuedCompletionStatus|CreateIoCompletionPort|WSASocketA'
objdump -d -M intel --start-address=0x804650 --stop-address=0x804740 Tartaros.bin
objdump -d -M intel --start-address=0x805950 --stop-address=0x805e00 Tartaros.bin
objdump -d -M intel --start-address=0x806ad0 --stop-address=0x806cf0 Tartaros.bin
objdump -d -M intel --start-address=0x806cf0 --stop-address=0x806f60 Tartaros.bin
objdump -d -M intel --start-address=0x807b40 --stop-address=0x807e30 Tartaros.bin
objdump -d -M intel --start-address=0x4c3080 --stop-address=0x4c316b Tartaros.bin
```

**原稿狀態**：僅本機完整 Markdown；使用者本次未授權 Commit/Push，未建立 Git blob SHA，未認領或提交 RR-0005，也未改 `main`、T01、S00 或其他 Task。

