# KR T10-15 — 狀態位元組的另一組消費者及命令派發

原始來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，檔案大小 12,472,320 bytes。`.text` 依 PE 映射 VA `0x401000` ↔ raw `0x400`。唯讀截取，GNU objdump x86 Intel 模式；**不得執行客戶端**。以下若截取從區塊內部開始，首行解碼可能不是指令界線，應以原函式 CFG 校正。所有名稱都是暫定。日期：2026-10-27（Asia/Taipei）。

## 主要新增結果
`0x54883A～0x548883` 檢查 `[0xFB9015]`、`[0xFB9016]`、`[0xFB9017]`、`[0xFB9018]` 是否為 `1`，各自推送 `1～4` 呼叫 `0x50C640`。這與 `0x6D4CE0` 的一般狀態 getter 不同，是另一個專用消費者。`0x548891` 另外檢查 `0xFB901B`，在 actor 狀態許可時寫局部 byte `0x80`。
`0x50C640` 按輸入參數計算 `ecx + index*0x10` 的 slot，檢查 `slot+0x0C`、`slot+4` gate、樹查找和可選狀態守衛。成功時建構三個欄位 `WORD 0x22` / `BYTE index` / `DWORD slot+8`，並交 `0x50CAC0`。該命令暫定為一種**額外操作請求**，不是已證實的普攻。
`0x50CAC0` 若 `[0xFBA798]==0`，讀 `[0xFBA854]` 的 virtual `+0x10`，傳三參數 `0, packetAddr, 7`；否則直接回傳 1。這是已確認的封包送出交接邊界，未核實命令 `0x22` 的服務端語義。
## 重要界線
不能把 `0xFB9015～18` 的四個 `state==1` 當成連擊四段：它們是四個**不同位址**各觸發參數 1～4，並非單一 Z 連段 counter。需要由各位址 key mapping 與封包 response 查證用途。

## 第一手原始組語摘錄
### 原始 BIN：0x54883a
```asm
  54883a:	80 3d 15 90 fb 00 01 	cmp    BYTE PTR ds:0xfb9015,0x1
  548841:	8b 3d fc 42 f9 00    	mov    edi,DWORD PTR ds:0xf942fc
  548847:	75 09                	jne    0x548852
  548849:	6a 01                	push   0x1
  54884b:	8b cf                	mov    ecx,edi
  54884d:	e8 ee 3d fc ff       	call   0x50c640
  548852:	80 3d 16 90 fb 00 01 	cmp    BYTE PTR ds:0xfb9016,0x1
  548859:	75 09                	jne    0x548864
  54885b:	6a 02                	push   0x2
  54885d:	8b cf                	mov    ecx,edi
  54885f:	e8 dc 3d fc ff       	call   0x50c640
  548864:	80 3d 17 90 fb 00 01 	cmp    BYTE PTR ds:0xfb9017,0x1
  54886b:	75 09                	jne    0x548876
  54886d:	6a 03                	push   0x3
  54886f:	8b cf                	mov    ecx,edi
  548871:	e8 ca 3d fc ff       	call   0x50c640
  548876:	80 3d 18 90 fb 00 01 	cmp    BYTE PTR ds:0xfb9018,0x1
  54887d:	75 09                	jne    0x548888
  54887f:	6a 04                	push   0x4
  548881:	8b cf                	mov    ecx,edi
  548883:	e8 b8 3d fc ff       	call   0x50c640
  548888:	80 3d 1b 90 fb 00 01 	cmp    BYTE PTR ds:0xfb901b,0x1
  54888f:	75 1f                	jne    0x5488b0
  548891:	8b 06                	mov    eax,DWORD PTR [esi]
  548893:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  548896:	8b ce                	mov    ecx,esi
  548898:	ff d2                	call   edx
  54889a:	8b 80 58 01 00 00    	mov    eax,DWORD PTR [eax+0x158]
  5488a0:	83 78 08 03          	cmp    DWORD PTR [eax+0x8],0x3
  5488a4:	74 0a                	je     0x5488b0
  5488a6:	c6 44 24 13 80       	mov    BYTE PTR [esp+0x13],0x80
  5488ab:	eb 03                	jmp    0x5488b0
  5488ad:	83 cb ff             	or     ebx,0xffffffff
```

### 原始 BIN：0x50c640
```asm
  50c640:	55                   	push   ebp
  50c641:	8b ec                	mov    ebp,esp
  50c643:	83 ec 08             	sub    esp,0x8
  50c646:	53                   	push   ebx
  50c647:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  50c64a:	56                   	push   esi
  50c64b:	8b f3                	mov    esi,ebx
  50c64d:	c1 e6 04             	shl    esi,0x4
  50c650:	03 f1                	add    esi,ecx
  50c652:	80 7e 0c 00          	cmp    BYTE PTR [esi+0xc],0x0
  50c656:	0f 84 96 00 00 00    	je     0x50c6f2
  50c65c:	83 7e 04 00          	cmp    DWORD PTR [esi+0x4],0x0
  50c660:	0f 84 8c 00 00 00    	je     0x50c6f2
  50c666:	8b 16                	mov    edx,DWORD PTR [esi]
  50c668:	57                   	push   edi
  50c669:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  50c66c:	e8 6f 6e ef ff       	call   0x4034e0
  50c671:	8b f8                	mov    edi,eax
  50c673:	8d 45 08             	lea    eax,[ebp+0x8]
  50c676:	50                   	push   eax
  50c677:	8d 45 f8             	lea    eax,[ebp-0x8]
  50c67a:	8b cf                	mov    ecx,edi
  50c67c:	e8 3f 72 33 00       	call   0x8438c0
  50c681:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  50c684:	3b 47 04             	cmp    eax,DWORD PTR [edi+0x4]
  50c687:	5f                   	pop    edi
  50c688:	74 68                	je     0x50c6f2
  50c68a:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  50c68d:	85 c0                	test   eax,eax
  50c68f:	74 61                	je     0x50c6f2
  50c691:	83 78 08 1a          	cmp    DWORD PTR [eax+0x8],0x1a
  50c695:	75 41                	jne    0x50c6d8
  50c697:	e8 c4 29 f0 ff       	call   0x40f060
  50c69c:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  50c6a2:	8b 11                	mov    edx,DWORD PTR [ecx]
  50c6a4:	8b 42 20             	mov    eax,DWORD PTR [edx+0x20]
  50c6a7:	ff d0                	call   eax
  50c6a9:	85 c0                	test   eax,eax
  50c6ab:	74 45                	je     0x50c6f2
  50c6ad:	e8 7e ce fb ff       	call   0x4c9530
  50c6b2:	85 c0                	test   eax,eax
  50c6b4:	74 3c                	je     0x50c6f2
  50c6b6:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  50c6b9:	b9 22 00 00 00       	mov    ecx,0x22
  50c6be:	89 55 fb             	mov    DWORD PTR [ebp-0x5],edx
  50c6c1:	8d 55 f8             	lea    edx,[ebp-0x8]
  50c6c4:	66 89 4d f8          	mov    WORD PTR [ebp-0x8],cx
  50c6c8:	88 5d fa             	mov    BYTE PTR [ebp-0x6],bl
  50c6cb:	e8 f0 03 00 00       	call   0x50cac0
  50c6d0:	5e                   	pop    esi
  50c6d1:	5b                   	pop    ebx
  50c6d2:	8b e5                	mov    esp,ebp
  50c6d4:	5d                   	pop    ebp
  50c6d5:	c2 04 00             	ret    0x4
  50c6d8:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  50c6db:	b8 22 00 00 00       	mov    eax,0x22
  50c6e0:	8d 55 f8             	lea    edx,[ebp-0x8]
  50c6e3:	66 89 45 f8          	mov    WORD PTR [ebp-0x8],ax
  50c6e7:	89 4d fb             	mov    DWORD PTR [ebp-0x5],ecx
  50c6ea:	88 5d fa             	mov    BYTE PTR [ebp-0x6],bl
  50c6ed:	e8 ce 03 00 00       	call   0x50cac0
  50c6f2:	5e                   	pop    esi
  50c6f3:	5b                   	pop    ebx
  50c6f4:	8b e5                	mov    esp,ebp
  50c6f6:	5d                   	pop    ebp
  50c6f7:	c2                   	.byte 0xc2
  50c6f8:	04                   	.byte 0x4
```

### 原始 BIN：0x50cac0
```asm
  50cac0:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  50cac7:	75 13                	jne    0x50cadc
  50cac9:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  50cacf:	8b 01                	mov    eax,DWORD PTR [ecx]
  50cad1:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  50cad4:	6a 07                	push   0x7
  50cad6:	52                   	push   edx
  50cad7:	6a 00                	push   0x0
  50cad9:	ff d0                	call   eax
  50cadb:	c3                   	ret
  50cadc:	b8 01 00 00 00       	mov    eax,0x1
  50cae1:	c3                   	ret
  50cae2:	cc                   	int3
```

## Git 與來源完整性
此檔為含原始反組譯摘錄的獨立原稿；實際是否推送成功以 GitHub 遠端回讀和 SHA 為準。