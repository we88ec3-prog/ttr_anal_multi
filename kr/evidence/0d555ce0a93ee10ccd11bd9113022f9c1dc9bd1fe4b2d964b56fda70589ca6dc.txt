# T10-36 — selector setter 間接呼叫候選與 receiver 型別追溯（BIN-first）

- 時間：20261027-222750 Asia/Taipei；接續 T10-35，這次研究以完整欄位分派與候選去歧義為主。
- 證據：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，實際 `sha256sum` 複驗。
- `.text` PE VA/檔案映射 `0x401000`/`0x400`；此份摘錄來自唯讀 objdump `-d -Mintel -j .text`。
- 沒有執行或修改遊戲。未將未知 selector 語義命名成 Z/V 或動作取消。

## 一、新驗證：直接建構點與間接呼叫檢索的可證明範圍

1. 全 `.text` 的 `call 0x4CD6F0` 直接指令來源在本輪找到 `0x4A0FD8`、`0x4AE609`（與 T10-35 相符）；只能窮盡 *該種直接 call 編碼*，無法排除 indirect calls、函式位址取用或動態派遣。
2. `0x4AE5xx` 先透過 `BYTE` 類型 0..7 的跳轉表，經 `0x891268` 分配 `0x444` 容量，再呼叫 `0x4CD6F0`；這證明存在資料驅動的物件建構，但 **不證明輸入來源是封包或鍵盤**。
3. `0x4CD6F0` 呼叫 `0x4C7070`，覆寫 `[edi]` 為 `0xC07B44`；`0xC07B70`（相對 slot `+0x2C`）是 `0x4CE7F0`。這是能被靜態證實的類型與 slot 所有權。
4. 對整份 `.text` 進行候選間接呼叫掃描：前七行有 `mov REG,[REG+0x2c]`、後接 register `call` 的掃描得到 **236 個粗略候選**。這是*沒有 data-flow 去重/型別確認的上界候選集合*，絕不代表 236 個都是這個 setter 的呼叫者。
5. 可見例如 `0x48B7D8` 處的 vptr slot `+0x2C` 呼叫，但僅憑這個序列，無法將 `edi` receiver 等同 `0x4CD6F0` 的建構實例。`0x492A04` 等候選也持有不同上游 receiver（例如 `[ebx+0xBF50]`）；因此本段**沒有確認任何玩家事件→selector=5 setter 的直接動態連線**。
6. `0x5462B4` 的 controller 確實讀取 actor `+0x3E8`，但尚無同一個分配物件從建構/註冊到 controller 指標欄位的可追溯搬移鏈；目前只能列為結構相容性，不是 receiver identity 證據。

## 二、按鏈條標示觀察與未證明缺口

```text
factory 0x4A0FD8 or typed data reader 0x4AE609
  -> ctor 0x4CD6F0 -> base 0x4C7070 -> instance vptr 0xC07B44
  -> [virtual +0x2C] = 0x4CE7F0
     -> selector 5 -> 0x4CE914 writes instance+0x3E8
     -> when value == 1, cleanup/rebuild associated +0x364 state

player controller 0x546100 -> [actor+0x3E8] -> skill availability 0x54F270

MISSING: factory instance registration -> controller actor identity
MISSING: action input producer -> setter selector/value arguments
MISSING: animation/queue/cancel -> resulting action transition
```

## 三、第一手機器碼摘錄（入口周邊，上下游對照）

### 0x4A0FD8
```asm
  4a0fc2:	83 c4 04             	add    esp,0x4
  4a0fc5:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4a0fc9:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4a0fd0:	00 
  4a0fd1:	85 c0                	test   eax,eax
  4a0fd3:	74 6e                	je     0x4a1043
  4a0fd5:	6a 00                	push   0x0
  4a0fd7:	50                   	push   eax
  4a0fd8:	e8 13 c7 02 00       	call   0x4cd6f0
  4a0fdd:	eb 66                	jmp    0x4a1045
  4a0fdf:	83 fb 01             	cmp    ebx,0x1
  4a0fe2:	75 35                	jne    0x4a1019
  4a0fe4:	68 34 04 00 00       	push   0x434
  4a0fe9:	e8 7a 02 3f 00       	call   0x891268
  4a0fee:	83 c4 04             	add    esp,0x4
  4a0ff1:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4a0ff5:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  4a0ff9:	85 c0                	test   eax,eax
  4a0ffb:	74 08                	je     0x4a1005
  4a0ffd:	50                   	push   eax
  4a0ffe:	e8 0d 07 03 00       	call   0x4d1710
  4a1003:	eb 02                	jmp    0x4a1007
  4a1005:	33 c0                	xor    eax,eax
  4a1007:	57                   	push   edi
  4a1008:	c7 44 24 34 ff ff ff 	mov    DWORD PTR [esp+0x34],0xffffffff
  4a100f:	ff 
  4a1010:	8b f0                	mov    esi,eax
  4a1012:	e8 b9 fd ff ff       	call   0x4a0dd0
  4a1017:	eb 36                	jmp    0x4a104f
  4a1019:	83 fb 06             	cmp    ebx,0x6
  4a101c:	75 31                	jne    0x4a104f
  4a101e:	68 2c 04 00 00       	push   0x42c
  4a1023:	e8 40 02 3f 00       	call   0x891268
  4a1028:	83 c4 04             	add    esp,0x4
  4a102b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4a102f:	c7 44 24 30 02 00 00 	mov    DWORD PTR [esp+0x30],0x2
```

### 0x4AE609
```asm
  4ae5f1:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae5f5:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x1
  4ae5fc:	01 00 00 00 
  4ae600:	85 c0                	test   eax,eax
  4ae602:	74 0e                	je     0x4ae612
  4ae604:	8b 53 0e             	mov    edx,DWORD PTR [ebx+0xe]
  4ae607:	52                   	push   edx
  4ae608:	50                   	push   eax
  4ae609:	e8 e2 f0 01 00       	call   0x4cd6f0
  4ae60e:	8b f0                	mov    esi,eax
  4ae610:	eb 02                	jmp    0x4ae614
  4ae612:	33 f6                	xor    esi,esi
  4ae614:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae61b:	ff ff ff ff 
  4ae61f:	e8 7c 65 f5 ff       	call   0x404ba0
  4ae624:	8b 80 50 5f 00 00    	mov    eax,DWORD PTR [eax+0x5f50]
  4ae62a:	39 43 0e             	cmp    DWORD PTR [ebx+0xe],eax
  4ae62d:	0f 85 e4 02 00 00    	jne    0x4ae917
  4ae633:	e8 68 65 f5 ff       	call   0x404ba0
  4ae638:	8b 90 24 69 00 00    	mov    edx,DWORD PTR [eax+0x6924]
  4ae63e:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  4ae641:	83 f8 09             	cmp    eax,0x9
  4ae644:	0f 87 cd 02 00 00    	ja     0x4ae917
  4ae64a:	8b c8                	mov    ecx,eax
  4ae64c:	69 c9 10 02 00 00    	imul   ecx,ecx,0x210
  4ae652:	03 ca                	add    ecx,edx
  4ae654:	0f 84 bd 02 00 00    	je     0x4ae917
  4ae65a:	83 79 5c 00          	cmp    DWORD PTR [ecx+0x5c],0x0
  4ae65e:	0f 85 b3 02 00 00    	jne    0x4ae917
  4ae664:	8b 11                	mov    edx,DWORD PTR [ecx]
  4ae666:	50                   	push   eax
  4ae667:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4ae66a:	ff d0                	call   eax
  4ae66c:	e9 a6 02 00 00       	jmp    0x4ae917
  4ae671:	68 34 04 00 00       	push   0x434
  4ae676:	e8 ed 2b 3e 00       	call   0x891268
```

### 0x4CD6F0
```asm
  4cd6e8:	cc                   	int3
  4cd6e9:	cc                   	int3
  4cd6ea:	cc                   	int3
  4cd6eb:	cc                   	int3
  4cd6ec:	cc                   	int3
  4cd6ed:	cc                   	int3
  4cd6ee:	cc                   	int3
  4cd6ef:	cc                   	int3
  4cd6f0:	55                   	push   ebp
  4cd6f1:	8b ec                	mov    ebp,esp
  4cd6f3:	6a ff                	push   0xffffffff
  4cd6f5:	68 74 76 91 00       	push   0x917674
  4cd6fa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4cd700:	50                   	push   eax
  4cd701:	83 ec 0c             	sub    esp,0xc
  4cd704:	53                   	push   ebx
  4cd705:	56                   	push   esi
  4cd706:	57                   	push   edi
  4cd707:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4cd70c:	33 c5                	xor    eax,ebp
  4cd70e:	50                   	push   eax
  4cd70f:	8d 45 f4             	lea    eax,[ebp-0xc]
  4cd712:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4cd718:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4cd71b:	57                   	push   edi
  4cd71c:	e8 4f 99 ff ff       	call   0x4c7070
  4cd721:	33 db                	xor    ebx,ebx
  4cd723:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4cd726:	6a 30                	push   0x30
  4cd728:	c7 07 44 7b c0 00    	mov    DWORD PTR [edi],0xc07b44
  4cd72e:	c7 87 f0 00 00 00 cc 	mov    DWORD PTR [edi+0xf0],0xc07bcc
  4cd735:	7b c0 00 
  4cd738:	89 9f 20 04 00 00    	mov    DWORD PTR [edi+0x420],ebx
  4cd73e:	89 9f 24 04 00 00    	mov    DWORD PTR [edi+0x424],ebx
  4cd744:	e8 1f 3b 3c 00       	call   0x891268
  4cd749:	0f 57 c0             	xorps  xmm0,xmm0
```

### 0x4CE7F0
```asm
  4ce7e7:	8b e5                	mov    esp,ebp
  4ce7e9:	5d                   	pop    ebp
  4ce7ea:	c3                   	ret
  4ce7eb:	cc                   	int3
  4ce7ec:	cc                   	int3
  4ce7ed:	cc                   	int3
  4ce7ee:	cc                   	int3
  4ce7ef:	cc                   	int3
  4ce7f0:	55                   	push   ebp
  4ce7f1:	8b ec                	mov    ebp,esp
  4ce7f3:	6a ff                	push   0xffffffff
  4ce7f5:	68 e8 05 94 00       	push   0x9405e8
  4ce7fa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ce800:	50                   	push   eax
  4ce801:	83 ec 3c             	sub    esp,0x3c
  4ce804:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ce809:	33 c5                	xor    eax,ebp
  4ce80b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ce80e:	53                   	push   ebx
  4ce80f:	56                   	push   esi
  4ce810:	57                   	push   edi
  4ce811:	50                   	push   eax
  4ce812:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ce815:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ce81b:	8b d9                	mov    ebx,ecx
  4ce81d:	0f bf 4d 08          	movsx  ecx,WORD PTR [ebp+0x8]
  4ce821:	8d 41 ff             	lea    eax,[ecx-0x1]
  4ce824:	83 f8 1d             	cmp    eax,0x1d
  4ce827:	0f 87 fe 02 00 00    	ja     0x4ceb2b
  4ce82d:	0f b6 80 88 eb 4c 00 	movzx  eax,BYTE PTR [eax+0x4ceb88]
  4ce834:	ff 24 85 5c eb 4c 00 	jmp    DWORD PTR [eax*4+0x4ceb5c]
  4ce83b:	0f bf 45 0c          	movsx  eax,WORD PTR [ebp+0xc]
  4ce83f:	89 83 b0 03 00 00    	mov    DWORD PTR [ebx+0x3b0],eax
  4ce845:	8b 9b 68 03 00 00    	mov    ebx,DWORD PTR [ebx+0x368]
  4ce84b:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  4ce84e:	85 db                	test   ebx,ebx
```

### 0x4CE90A
```asm
  4ce8eb:	dc 35 e8 57 c5 00    	fdiv   QWORD PTR ds:0xc557e8
  4ce8f1:	d9 5d cc             	fstp   DWORD PTR [ebp-0x34]
  4ce8f4:	d9 45 cc             	fld    DWORD PTR [ebp-0x34]
  4ce8f7:	d9 5d cc             	fstp   DWORD PTR [ebp-0x34]
  4ce8fa:	e8 d1 65 2e 00       	call   0x7b4ed0
  4ce8ff:	d9 45 cc             	fld    DWORD PTR [ebp-0x34]
  4ce902:	d9 58 0c             	fstp   DWORD PTR [eax+0xc]
  4ce905:	e9 34 02 00 00       	jmp    0x4ceb3e
  4ce90a:	0f bf 4d 0c          	movsx  ecx,WORD PTR [ebp+0xc]
  4ce90e:	8b 83 64 03 00 00    	mov    eax,DWORD PTR [ebx+0x364]
  4ce914:	89 8b e8 03 00 00    	mov    DWORD PTR [ebx+0x3e8],ecx
  4ce91a:	85 c0                	test   eax,eax
  4ce91c:	74 27                	je     0x4ce945
  4ce91e:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4ce922:	8d 70 24             	lea    esi,[eax+0x24]
  4ce925:	74 05                	je     0x4ce92c
  4ce927:	e8 c4 fc 2e 00       	call   0x7be5f0
  4ce92c:	8b bb 64 03 00 00    	mov    edi,DWORD PTR [ebx+0x364]
  4ce932:	85 ff                	test   edi,edi
  4ce934:	74 0f                	je     0x4ce945
  4ce936:	e8 75 94 ff ff       	call   0x4c7db0
  4ce93b:	c7 83 64 03 00 00 00 	mov    DWORD PTR [ebx+0x364],0x0
  4ce942:	00 00 00 
  4ce945:	83 bb e8 03 00 00 01 	cmp    DWORD PTR [ebx+0x3e8],0x1
  4ce94c:	0f 85 ec 01 00 00    	jne    0x4ceb3e
  4ce952:	d9 e8                	fld1
  4ce954:	8b 13                	mov    edx,DWORD PTR [ebx]
  4ce956:	8b 42 4c             	mov    eax,DWORD PTR [edx+0x4c]
  4ce959:	83 ec 08             	sub    esp,0x8
  4ce95c:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  4ce960:	83 cf ff             	or     edi,0xffffffff
  4ce963:	d9 ee                	fldz
  4ce965:	8b cb                	mov    ecx,ebx
  4ce967:	d9 1c 24             	fstp   DWORD PTR [esp]
  4ce96a:	c7 45 b8 02 00 00 00 	mov    DWORD PTR [ebp-0x48],0x2
  4ce971:	c7 45 bc ec 7a c0 00 	mov    DWORD PTR [ebp-0x44],0xc07aec
```

### 0x5462B4
```asm
  546296:	ba ff 7f 00 00       	mov    edx,0x7fff
  54629b:	66 23 ca             	and    cx,dx
  54629e:	66 31 4b 02          	xor    WORD PTR [ebx+0x2],cx
  5462a2:	83 3d ac a7 fb 00 01 	cmp    DWORD PTR ds:0xfba7ac,0x1
  5462a9:	74 5b                	je     0x546306
  5462ab:	66 85 c0             	test   ax,ax
  5462ae:	74 56                	je     0x546306
  5462b0:	8b 74 24 24          	mov    esi,DWORD PTR [esp+0x24]
  5462b4:	8b 8f e8 03 00 00    	mov    ecx,DWORD PTR [edi+0x3e8]
  5462ba:	33 d2                	xor    edx,edx
  5462bc:	38 56 02             	cmp    BYTE PTR [esi+0x2],dl
  5462bf:	51                   	push   ecx
  5462c0:	0f 95 c2             	setne  dl
  5462c3:	8a 14 32             	mov    dl,BYTE PTR [edx+esi*1]
  5462c6:	88 54 24 28          	mov    BYTE PTR [esp+0x28],dl
  5462ca:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  5462ce:	51                   	push   ecx
  5462cf:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5462d2:	8d 14 49             	lea    edx,[ecx+ecx*2]
  5462d5:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5462d9:	8b 4c 91 10          	mov    ecx,DWORD PTR [ecx+edx*4+0x10]
  5462dd:	e8 8e 8f 00 00       	call   0x54f270
  5462e2:	85 c0                	test   eax,eax
  5462e4:	74 07                	je     0x5462ed
  5462e6:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  5462eb:	eb 19                	jmp    0x546306
  5462ed:	83 bf e8 03 00 00 00 	cmp    DWORD PTR [edi+0x3e8],0x0
  5462f4:	74 07                	je     0x5462fd
  5462f6:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  5462fb:	eb 09                	jmp    0x546306
  5462fd:	ba 00 80 00 00       	mov    edx,0x8000
  546302:	66 21 53 02          	and    WORD PTR [ebx+0x2],dx
  546306:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  54630d:	75 29                	jne    0x546338
  54630f:	b8 01 00 00 00       	mov    eax,0x1
  546314:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
```

### 0x546338
```asm
  546314:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  54631a:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  54631e:	e8 2d a4 18 00       	call   0x6d0750
  546323:	68 30 d5 bc 00       	push   0xbcd530
  546328:	e8 ed bf 34 00       	call   0x89231a
  54632d:	83 c4 04             	add    esp,0x4
  546330:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  546337:	ff 
  546338:	33 c0                	xor    eax,eax
  54633a:	38 05 09 90 fb 00    	cmp    BYTE PTR ds:0xfb9009,al
  546340:	0f 94 c0             	sete   al
  546343:	8b f0                	mov    esi,eax
  546345:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  54634b:	85 c0                	test   eax,eax
  54634d:	0f 84 29 01 00 00    	je     0x54647c
  546353:	83 78 30 00          	cmp    DWORD PTR [eax+0x30],0x0
  546357:	0f 84 1f 01 00 00    	je     0x54647c
  54635d:	8b cf                	mov    ecx,edi
  54635f:	e8 6c 3b f8 ff       	call   0x4c9ed0
  546364:	85 c0                	test   eax,eax
  546366:	0f 85 10 01 00 00    	jne    0x54647c
  54636c:	85 f6                	test   esi,esi
  54636e:	0f 84 08 01 00 00    	je     0x54647c
  546374:	8a 4c 24 1c          	mov    cl,BYTE PTR [esp+0x1c]
  546378:	88 4b 04             	mov    BYTE PTR [ebx+0x4],cl
  54637b:	39 44 24 28          	cmp    DWORD PTR [esp+0x28],eax
  54637f:	0f 84 ea 00 00 00    	je     0x54646f
  546385:	ba ff 7f 00 00       	mov    edx,0x7fff
  54638a:	66 85 53 02          	test   WORD PTR [ebx+0x2],dx
  54638e:	0f 85 db 00 00 00    	jne    0x54646f
  546394:	8b 07                	mov    eax,DWORD PTR [edi]
  546396:	8b 50 60             	mov    edx,DWORD PTR [eax+0x60]
  546399:	8b cf                	mov    ecx,edi
  54639b:	8d b7 a0 00 00 00    	lea    esi,[edi+0xa0]
  5463a1:	ff d2                	call   edx
  5463a3:	dc 0d 70 5a c5 00    	fmul   QWORD PTR ds:0xc55a70
```

### 0x48B7D8
```asm
  48b7c7:	32 db                	xor    bl,bl
  48b7c9:	eb 2e                	jmp    0x48b7f9
  48b7cb:	8b 07                	mov    eax,DWORD PTR [edi]
  48b7cd:	8b 50 38             	mov    edx,DWORD PTR [eax+0x38]
  48b7d0:	8b cf                	mov    ecx,edi
  48b7d2:	ff d2                	call   edx
  48b7d4:	8b f0                	mov    esi,eax
  48b7d6:	8b 07                	mov    eax,DWORD PTR [edi]
  48b7d8:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  48b7db:	8b cf                	mov    ecx,edi
  48b7dd:	ff d2                	call   edx
  48b7df:	50                   	push   eax
  48b7e0:	8d 8d e8 fe ff ff    	lea    ecx,[ebp-0x118]
  48b7e6:	e8 55 db 00 00       	call   0x499340
  48b7eb:	8a d8                	mov    bl,al
  48b7ed:	8b 07                	mov    eax,DWORD PTR [edi]
  48b7ef:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  48b7f2:	83 c4 04             	add    esp,0x4
  48b7f5:	8b cf                	mov    ecx,edi
  48b7f7:	ff d2                	call   edx
  48b7f9:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  48b7fd:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  48b801:	72 0c                	jb     0x48b80f
  48b803:	8b 45 d4             	mov    eax,DWORD PTR [ebp-0x2c]
  48b806:	50                   	push   eax
  48b807:	e8 00 5a 40 00       	call   0x89120c
  48b80c:	83 c4 04             	add    esp,0x4
  48b80f:	84 db                	test   bl,bl
  48b811:	74 53                	je     0x48b866
  48b813:	8b 8d e8 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x118]
  48b819:	68 80 55 c0 00       	push   0xc05580
  48b81e:	8d bd e0 fe ff ff    	lea    edi,[ebp-0x120]
  48b824:	8d 85 e4 fe ff ff    	lea    eax,[ebp-0x11c]
  48b82a:	89 8d e4 fe ff ff    	mov    DWORD PTR [ebp-0x11c],ecx
  48b830:	e8 0b 02 29 00       	call   0x71ba40
  48b835:	8b 10                	mov    edx,DWORD PTR [eax]
```

### 0x492A04
```asm
  4929eb:	50                   	push   eax
  4929ec:	ff d2                	call   edx
  4929ee:	85 c0                	test   eax,eax
  4929f0:	78 1a                	js     0x492a0c
  4929f2:	e8 f9 71 ff ff       	call   0x489bf0
  4929f7:	8b f0                	mov    esi,eax
  4929f9:	e8 52 29 0c 00       	call   0x555350
  4929fe:	8b 83 50 bf 00 00    	mov    eax,DWORD PTR [ebx+0xbf50]
  492a04:	8b 08                	mov    ecx,DWORD PTR [eax]
  492a06:	8b 51 2c             	mov    edx,DWORD PTR [ecx+0x2c]
  492a09:	50                   	push   eax
  492a0a:	ff d2                	call   edx
  492a0c:	8b 43 10             	mov    eax,DWORD PTR [ebx+0x10]
  492a0f:	8b 08                	mov    ecx,DWORD PTR [eax]
  492a11:	8b 91 a8 00 00 00    	mov    edx,DWORD PTR [ecx+0xa8]
  492a17:	50                   	push   eax
  492a18:	ff d2                	call   edx
  492a1a:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  492a1e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  492a25:	59                   	pop    ecx
  492a26:	5f                   	pop    edi
  492a27:	5e                   	pop    esi
  492a28:	5b                   	pop    ebx
  492a29:	8b e5                	mov    esp,ebp
  492a2b:	5d                   	pop    ebp
  492a2c:	c2 04 00             	ret    0x4
  492a2f:	f6 05 f4 f6 fd 00 01 	test   BYTE PTR ds:0xfdf6f4,0x1
  492a36:	75 17                	jne    0x492a4f
  492a38:	09 3d f4 f6 fd 00    	or     DWORD PTR ds:0xfdf6f4,edi
  492a3e:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  492a42:	e8 49 8a 00 00       	call   0x49b490
  492a47:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  492a4e:	ff 
  492a4f:	f6 05 d8 48 fe 00 01 	test   BYTE PTR ds:0xfe48d8,0x1
  492a56:	75 0b                	jne    0x492a63
  492a58:	09 3d d8 48 fe 00    	or     DWORD PTR ds:0xfe48d8,edi
```


## 四、對可能誤判的具體否定

- selector=5 與 input index=5 不能相互代換；兩者不同結構、不同程式路徑。
- `+0x2C` 是 vtable **slot offset** 而非固定函式身分；各衍生/無關型別可有不同方法。
- 同偏移 `+0x3E8` 在不同物件中可能不同義，需從 `[this]` vptr、constructor factory、receiver 傳遞鏈確認。
- `[0xFB9009]` 是陣列 index 5，尚未證明代表物理 V、Z 或 pressed/held。
- `value=1` 的從屬重建不是「V 蓄氣達標」的原生證據。

## 五、可檢驗的下一輪研究（T10-37）

1. 從 `0x4AE609` 的建構返回值 `esi` 起找容器插入、entity registry、controller actor 的賦值流；不把相同 offset 誤當同一實體。
2. 對候選 `call [vptr+0x2C]` 逐個追 receiver 的 vptr 來源，僅將可回溯 `0xC07B44` 或該物件繼承族者列為真正 dispatch caller。
3. 找到一條真實 player input producer → action ID/selector → virtual setter 的鏈條後，才評估與 V 點按/長按、普攻→技能銜接的關係。
4. 狀態轉換 gate `0x546100` 與動畫/佇列分派仍待獨立驗證；後端規則歸 T11/T12 所有者。

## 六、結論與交付

本段以全映像間接呼叫候選掃描和 receiver 限定條件為主，確立 virtual slot 的 **證據邊界**；沒有將粗略候選冒充已識別的玩家按鍵 callback。T10-36 作為一段深度調查結案，剩餘問題繼續到 T10-37。提交時應保留本份完整原稿與既有 T10-33～35 完整原稿。GitHub commit 狀態以實際工具結果另行記錄。