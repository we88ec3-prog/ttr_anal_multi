# T16-27 — 其他註冊 handler 與狀態操作候選（KR，BIN-first 限定證據）

- 文件生成時間（Asia/Taipei）：20261028-022116
- 來源 `Tartaros.bin`，大小 `12472320`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本批實際讀取重算）
- 基線：2026-10-28 GitHub main 查詢後執行；以遠端最新 HEAD 為優先，詳見提交記錄
- 研究範圍：分別比較 handler 使用的輸入指標、直接呼叫與分支，排除無關結果。
- 證據標記：**原生已確認**只限於下述 bytes／assembly 的指令與直接控制流；**功能歸屬待確認**；server 權威、quest ID／step ID／獎勵與 TC 等價性均 `unknown`

## A. 本段研究問題及結論

1. **機器碼可直接確認**：所列 VA 範圍包含確實存在的 x86 指令，下面完整摘錄，不使用歷史 fixture 代替原生資料。
2. **當前功能邊界**：本段的入口地址係依前段候選與 handler 表／字串引用選定；不能由候選位置或 symbol-like 名稱推斷正式 Quest handler。
3. **反證限制**：沒有原版 Lua/XML 實體、捕獲的原版伺服器封包或能綁定玩家任務狀態的 writer-consumer 閉環；因此不能將 UI、腳本入口與 handler 候選串成原生可玩流程。

## B. 原生組合語言證據（objdump 直接對來源 BIN）

### VA `0x004AF530`–`0x004AF680`（96 行）

```asm
  4af530:	55                   	push   ebp
  4af531:	8b ec                	mov    ebp,esp
  4af533:	83 e4 f8             	and    esp,0xfffffff8
  4af536:	6a ff                	push   0xffffffff
  4af538:	68 4a 4e 94 00       	push   0x944e4a
  4af53d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4af543:	50                   	push   eax
  4af544:	83 ec 10             	sub    esp,0x10
  4af547:	53                   	push   ebx
  4af548:	56                   	push   esi
  4af549:	57                   	push   edi
  4af54a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4af54f:	33 c4                	xor    eax,esp
  4af551:	50                   	push   eax
  4af552:	8d 44 24 20          	lea    eax,[esp+0x20]
  4af556:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4af55c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4af55f:	33 f6                	xor    esi,esi
  4af561:	66 39 73 02          	cmp    WORD PTR [ebx+0x2],si
  4af565:	74 41                	je     0x4af5a8
  4af567:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4af56e:	75 25                	jne    0x4af595
  4af570:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4af577:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  4af57b:	e8 10 f7 02 00       	call   0x4dec90
  4af580:	68 30 ce bc 00       	push   0xbcce30
  4af585:	e8 90 2d 3e 00       	call   0x89231a
  4af58a:	83 c4 04             	add    esp,0x4
  4af58d:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af594:	ff 
  4af595:	68 48 b1 fa 00       	push   0xfab148
  4af59a:	89 35 28 b2 fa 00    	mov    DWORD PTR ds:0xfab228,esi
  4af5a0:	e8 cb 1a 03 00       	call   0x4e1070
  4af5a5:	83 c4 04             	add    esp,0x4
  4af5a8:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4af5ab:	83 f8 04             	cmp    eax,0x4
  4af5ae:	73 04                	jae    0x4af5b4
  4af5b0:	33 d2                	xor    edx,edx
  4af5b2:	eb 0d                	jmp    0x4af5c1
  4af5b4:	8d 48 fc             	lea    ecx,[eax-0x4]
  4af5b7:	b8 a3 8b 2e ba       	mov    eax,0xba2e8ba3
  4af5bc:	f7 e1                	mul    ecx
  4af5be:	c1 ea 04             	shr    edx,0x4
  4af5c1:	3b d6                	cmp    edx,esi
  4af5c3:	0f 86 39 03 00 00    	jbe    0x4af902
  4af5c9:	83 c3 0a             	add    ebx,0xa
  4af5cc:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  4af5d0:	eb 02                	jmp    0x4af5d4
  4af5d2:	33 f6                	xor    esi,esi
  4af5d4:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4af5db:	75 29                	jne    0x4af606
  4af5dd:	b8 01 00 00 00       	mov    eax,0x1
  4af5e2:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4af5e8:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  4af5ec:	e8 9f f6 02 00       	call   0x4dec90
  4af5f1:	68 30 ce bc 00       	push   0xbcce30
  4af5f6:	e8 1f 2d 3e 00       	call   0x89231a
  4af5fb:	83 c4 04             	add    esp,0x4
  4af5fe:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4af605:	ff 
  4af606:	8b 53 fa             	mov    edx,DWORD PTR [ebx-0x6]
  4af609:	8d 44 24 14          	lea    eax,[esp+0x14]
  4af60d:	50                   	push   eax
  4af60e:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  4af612:	b9 48 b1 fa 00       	mov    ecx,0xfab148
  4af617:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4af61b:	e8 a0 42 39 00       	call   0x8438c0
  4af620:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  4af624:	3b 05 4c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab14c
  4af62a:	74 0b                	je     0x4af637
  4af62c:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  4af62f:	3b fe                	cmp    edi,esi
  4af631:	0f 85 ba 00 00 00    	jne    0x4af6f1
  4af637:	6a 2c                	push   0x2c
  4af639:	e8 2a 1c 3e 00       	call   0x891268
  4af63e:	83 c4 04             	add    esp,0x4
  4af641:	3b c6                	cmp    eax,esi
  4af643:	74 25                	je     0x4af66a
  4af645:	33 c9                	xor    ecx,ecx
  4af647:	89 30                	mov    DWORD PTR [eax],esi
  4af649:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  4af64c:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  4af64f:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  4af652:	89 70 10             	mov    DWORD PTR [eax+0x10],esi
  4af655:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  4af658:	89 70 1c             	mov    DWORD PTR [eax+0x1c],esi
  4af65b:	c7 40 24 ff ff ff ff 	mov    DWORD PTR [eax+0x24],0xffffffff
  4af662:	66 89 48 28          	mov    WORD PTR [eax+0x28],cx
  4af666:	8b f8                	mov    edi,eax
  4af668:	eb 02                	jmp    0x4af66c
  4af66a:	33 ff                	xor    edi,edi
  4af66c:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4af673:	8b 43 fa             	mov    eax,DWORD PTR [ebx-0x6]
  4af676:	89 07                	mov    DWORD PTR [edi],eax
  4af678:	75 29                	jne    0x4af6a3
  4af67a:	83 0d 90 43 f9 00  	or     DWORD PTR ds:0xf94390,0x1
```

### VA `0x004AF920`–`0x004AFA80`（113 行）

```asm
  4af920:	55                   	push   ebp
  4af921:	8b ec                	mov    ebp,esp
  4af923:	83 ec 14             	sub    esp,0x14
  4af926:	53                   	push   ebx
  4af927:	56                   	push   esi
  4af928:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4af92b:	8b 5e 02             	mov    ebx,DWORD PTR [esi+0x2]
  4af92e:	57                   	push   edi
  4af92f:	e8 2c f7 f5 ff       	call   0x40f060
  4af934:	8b f8                	mov    edi,eax
  4af936:	8d 45 f8             	lea    eax,[ebp-0x8]
  4af939:	50                   	push   eax
  4af93a:	8d 4f 18             	lea    ecx,[edi+0x18]
  4af93d:	8d 45 fc             	lea    eax,[ebp-0x4]
  4af940:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  4af943:	e8 78 3f 39 00       	call   0x8438c0
  4af948:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4af94b:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  4af94e:	74 0c                	je     0x4af95c
  4af950:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4af953:	33 db                	xor    ebx,ebx
  4af955:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4af958:	3b c3                	cmp    eax,ebx
  4af95a:	75 1f                	jne    0x4af97b
  4af95c:	8b 4e 02             	mov    ecx,DWORD PTR [esi+0x2]
  4af95f:	51                   	push   ecx
  4af960:	68 40 6a c0 00       	push   0xc06a40
  4af965:	e8 f6 e1 23 00       	call   0x6edb60
  4af96a:	83 c4 08             	add    esp,0x8
  4af96d:	5f                   	pop    edi
  4af96e:	5e                   	pop    esi
  4af96f:	b8 05 40 00 80       	mov    eax,0x80004005
  4af974:	5b                   	pop    ebx
  4af975:	8b e5                	mov    esp,ebp
  4af977:	5d                   	pop    ebp
  4af978:	c2 0c 00             	ret    0xc
  4af97b:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  4af97e:	e8 1d 52 f5 ff       	call   0x404ba0
  4af983:	8b 56 02             	mov    edx,DWORD PTR [esi+0x2]
  4af986:	3b 90 50 5f 00 00    	cmp    edx,DWORD PTR [eax+0x5f50]
  4af98c:	75 21                	jne    0x4af9af
  4af98e:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4af994:	8b 01                	mov    eax,DWORD PTR [ecx]
  4af996:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4af999:	ff d2                	call   edx
  4af99b:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4af9a1:	8b 01                	mov    eax,DWORD PTR [ecx]
  4af9a3:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  4af9a6:	ff d2                	call   edx
  4af9a8:	c7 45 f8 01 00 00 00 	mov    DWORD PTR [ebp-0x8],0x1
  4af9af:	38 5e 06             	cmp    BYTE PTR [esi+0x6],bl
  4af9b2:	0f 8e 0f 01 00 00    	jle    0x4afac7
  4af9b8:	eb 08                	jmp    0x4af9c2
  4af9ba:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4af9c0:	8b f1                	mov    esi,ecx
  4af9c2:	0f b7 74 9e 07       	movzx  esi,WORD PTR [esi+ebx*4+0x7]
  4af9c7:	89 75 f4             	mov    DWORD PTR [ebp-0xc],esi
  4af9ca:	e8 91 f6 f5 ff       	call   0x40f060
  4af9cf:	8b f8                	mov    edi,eax
  4af9d1:	8d 45 f4             	lea    eax,[ebp-0xc]
  4af9d4:	50                   	push   eax
  4af9d5:	8d 4f 08             	lea    ecx,[edi+0x8]
  4af9d8:	8d 45 f0             	lea    eax,[ebp-0x10]
  4af9db:	e8 20 f5 37 00       	call   0x82ef00
  4af9e0:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  4af9e3:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
  4af9e6:	74 07                	je     0x4af9ef
  4af9e8:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  4af9eb:	85 ff                	test   edi,edi
  4af9ed:	75 12                	jne    0x4afa01
  4af9ef:	68 70 6a c0 00       	push   0xc06a70
  4af9f4:	e8 67 e1 23 00       	call   0x6edb60
  4af9f9:	83 c4 04             	add    esp,0x4
  4af9fc:	e9 b6 00 00 00       	jmp    0x4afab7
  4afa01:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4afa04:	66 8b 4c 98 07       	mov    cx,WORD PTR [eax+ebx*4+0x7]
  4afa09:	66 3b 4c 98 09       	cmp    cx,WORD PTR [eax+ebx*4+0x9]
  4afa0e:	74 27                	je     0x4afa37
  4afa10:	83 7d f8 00          	cmp    DWORD PTR [ebp-0x8],0x0
  4afa14:	74 21                	je     0x4afa37
  4afa16:	e8 45 f6 f5 ff       	call   0x40f060
  4afa1b:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4afa1e:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4afa24:	0f b7 44 98 09       	movzx  eax,WORD PTR [eax+ebx*4+0x9]
  4afa29:	8b 11                	mov    edx,DWORD PTR [ecx]
  4afa2b:	8b 52 08             	mov    edx,DWORD PTR [edx+0x8]
  4afa2e:	57                   	push   edi
  4afa2f:	50                   	push   eax
  4afa30:	ff d2                	call   edx
  4afa32:	e9 80 00 00 00       	jmp    0x4afab7
  4afa37:	85 db                	test   ebx,ebx
  4afa39:	75 53                	jne    0x4afa8e
  4afa3b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4afa3e:	c7 87 98 00 00 00 01 	mov    DWORD PTR [edi+0x98],0x1
  4afa45:	00 00 00 
  4afa48:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  4afa4b:	89 75 f4             	mov    DWORD PTR [ebp-0xc],esi
  4afa4e:	e8 0d f6 f5 ff       	call   0x40f060
  4afa53:	8b f0                	mov    esi,eax
  4afa55:	8d 4d f4             	lea    ecx,[ebp-0xc]
  4afa58:	51                   	push   ecx
  4afa59:	8d 4e 08             	lea    ecx,[esi+0x8]
  4afa5c:	8d 45 ec             	lea    eax,[ebp-0x14]
  4afa5f:	e8 9c f4 37 00       	call   0x82ef00
  4afa64:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  4afa67:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  4afa6a:	74 16                	je     0x4afa82
  4afa6c:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4afa6f:	85 c0                	test   eax,eax
  4afa71:	74 0f                	je     0x4afa82
  4afa73:	0f b7 90 88 00 00 00 	movzx  edx,WORD PTR [eax+0x88]
  4afa7a:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4afa7d:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
```

## C. Caller / callee 與分支觀察

以下列出本 VA 範圍內 `call` 指令及直接可觀察的條件分支；這是局部 call-site 列表，**不是已完成全域 xref 搜尋**。

### Direct callees / indirect calls

```asm
4af57b:	e8 10 f7 02 00       	call   0x4dec90
4af585:	e8 90 2d 3e 00       	call   0x89231a
4af5a0:	e8 cb 1a 03 00       	call   0x4e1070
4af5ec:	e8 9f f6 02 00       	call   0x4dec90
4af5f6:	e8 1f 2d 3e 00       	call   0x89231a
4af61b:	e8 a0 42 39 00       	call   0x8438c0
4af639:	e8 2a 1c 3e 00       	call   0x891268
4af92f:	e8 2c f7 f5 ff       	call   0x40f060
4af943:	e8 78 3f 39 00       	call   0x8438c0
4af965:	e8 f6 e1 23 00       	call   0x6edb60
4af97e:	e8 1d 52 f5 ff       	call   0x404ba0
4af999:	ff d2                	call   edx
4af9a6:	ff d2                	call   edx
4af9ca:	e8 91 f6 f5 ff       	call   0x40f060
4af9db:	e8 20 f5 37 00       	call   0x82ef00
4af9f4:	e8 67 e1 23 00       	call   0x6edb60
4afa16:	e8 45 f6 f5 ff       	call   0x40f060
4afa30:	ff d2                	call   edx
4afa4e:	e8 0d f6 f5 ff       	call   0x40f060
4afa5f:	e8 9c f4 37 00       	call   0x82ef00
```

### 比較與跳轉（前 55 筆）

```asm
4af561:	66 39 73 02          	cmp    WORD PTR [ebx+0x2],si
4af565:	74 41                	je     0x4af5a8
4af567:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
4af56e:	75 25                	jne    0x4af595
4af5ab:	83 f8 04             	cmp    eax,0x4
4af5ae:	73 04                	jae    0x4af5b4
4af5b2:	eb 0d                	jmp    0x4af5c1
4af5c1:	3b d6                	cmp    edx,esi
4af5c3:	0f 86 39 03 00 00    	jbe    0x4af902
4af5d0:	eb 02                	jmp    0x4af5d4
4af5d4:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
4af5db:	75 29                	jne    0x4af606
4af624:	3b 05 4c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab14c
4af62a:	74 0b                	je     0x4af637
4af62f:	3b fe                	cmp    edi,esi
4af631:	0f 85 ba 00 00 00    	jne    0x4af6f1
4af641:	3b c6                	cmp    eax,esi
4af643:	74 25                	je     0x4af66a
4af668:	eb 02                	jmp    0x4af66c
4af66c:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
4af678:	75 29                	jne    0x4af6a3
4af94b:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
4af94e:	74 0c                	je     0x4af95c
4af958:	3b c3                	cmp    eax,ebx
4af95a:	75 1f                	jne    0x4af97b
4af986:	3b 90 50 5f 00 00    	cmp    edx,DWORD PTR [eax+0x5f50]
4af98c:	75 21                	jne    0x4af9af
4af9af:	38 5e 06             	cmp    BYTE PTR [esi+0x6],bl
4af9b8:	eb 08                	jmp    0x4af9c2
4af9e3:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
4af9e6:	74 07                	je     0x4af9ef
4af9eb:	85 ff                	test   edi,edi
4af9ed:	75 12                	jne    0x4afa01
4af9fc:	e9 b6 00 00 00       	jmp    0x4afab7
4afa09:	66 3b 4c 98 09       	cmp    cx,WORD PTR [eax+ebx*4+0x9]
4afa0e:	74 27                	je     0x4afa37
4afa10:	83 7d f8 00          	cmp    DWORD PTR [ebp-0x8],0x0
4afa14:	74 21                	je     0x4afa37
4afa32:	e9 80 00 00 00       	jmp    0x4afab7
4afa37:	85 db                	test   ebx,ebx
4afa39:	75 53                	jne    0x4afa8e
4afa67:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
4afa6a:	74 16                	je     0x4afa82
4afa6f:	85 c0                	test   eax,eax
4afa71:	74 0f                	je     0x4afa82
```

## D. 資料流與局部偽碼

```cpp
// 以下僅是抽象的有界行為，非官方函式名稱，未自動確認函式 ABI。
void investigated_entry(UnknownContext* ctx, UnknownPayload* input) {
    // Refer to raw assembly above for exact push/this/stack args.
    // Conditional and call-site details must be traced into callees.
    // Native quest_step_id, writer, server_authority: unknown.
}
```

研究上，`eax/ecx/edx` 值必須依函式入口與呼叫約定回溯，不能跨不同物件將相同 offset 當相同欄位。字串與 handler 表不構成正式 Quest 型別的證明。

## E. 節點矩陣與跨 Task 協作

| 節點 | 前置／角色狀態 | 入口／可觀察內容 | 伺服器權威 | state writer | UI／通知 | 下一步／重登 |
|---|---|---|---|---|---|---|
| 本段查核候選 | unknown | 見第 B 節實際 assembly | unknown | unknown | unknown | unknown |
| Tutorial 完成 → 主線任務 | unknown | Lua／XML 類型已有歷史地址線索，實體內容缺失 | unknown | unknown | unknown | unknown |

- `T02` 保留傳輸與 opcode 基底分派主責；本段只研究 Quest 業務連接是否可證實。
- `T03/T04` 保留登入／角色初始化；本段不設定角色初值。
- `T07/T14` 保留場景進出與勝敗結算；不將通關直接等同任務完成。
- `T15` 保留儲存與恢復底層；目前 Quest 欄位持久化鍵 unknown。
- `TC` 仍只有目標 SHA 與資料來源索引，本段沒有 TC BIN 直接驗證。

## F. 分析與可玩性驗收獨立

| 檢驗項目 | 結論 |
|---|---|
| KR 原始 BIN SHA | 已驗證 |
| 指定 VA 機器碼存在 | 已驗證 |
| 本段地址屬 Quest business handler | 尚待驗證 |
| 教學完整步驟 | 資源缺失 |
| 第一個主線 ID／NPC | 資源缺失 |
| 伺服器任務寫入／重登續接 | 未閉環 |
| 真實遊玩測試 | 未執行，未通過驗收 |

## G. 下一步與未解事項

1. 依 B 節 `call` 目標做選擇性的全域 caller/callee / writer-consumer 交叉參照，優先找明確 Quest payload 而非任意 handler。
2. 從版本匹配的原版 `Event/TutorialMain.lua`、`Table/QuestInfo.xml`、`Table/QuestTalk.xml` 取得真正 quest IDs／觸發條件，避免 fixture 補猜。
3. 將 Quest 通知的 T02 opcode 及 T16 writer 對接；未找到時保留 `unknown` 而不是填假值。
4. TC 版本只在取得原始對應來源與 hash 後獨立驗證；不沿用 KR VA。

## H. 提交說明

此為完整可回溯的本批**限定範圍原始技術原稿**，不是整個任務業務鏈已復原之證明。來源檔唯讀，未執行或修改客戶端，未改其他 Task 的 owner、catalog 或原稿。