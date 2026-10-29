# T16-092 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-204341-chatgpt-web-roy-T16-92-KR-Quest-global-owner-and-real-read-consumers.md`
- **舊原稿 Git blob SHA**：`bd044356f64dd859fe898477d443414a468f4b85`
- T01 通知：`T01-RETURN-T16-092-6df3bb2c`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容

`T01-RETURN-T16-092-6df3bb2c`: four coordinate mistakes (some cause decoding inside prior instruction). Correct:
- `0x62E5CD`: `push eax`; next **`0x62E5CE`** starts `lea eax,[ebp-0x38]` (not previous coordinates).
- `0x5B6CCF`: `8B 53 14` is `mov edx,[ebx+0x14]`; **0x5B6CD0 is inside this instruction**.
- `0x62F700`: `C7 45 FC FF FF FF FF` (7 bytes); **0x62F706 is inside it**, next independent **0x62F70A** is `mov esi,[0xFB114C]`.
- `0x62E659` is `push esi`; **0x62E65A** is call to `0x759ED0`.
The client-local lazy owner→lookup/read chain remains bounded evidence, not automatically Quest wire protocol, `S→C` writer or unconditional-zero branch. Below the function-entry-anchored linear decode is provided; **linear decode alone is not a formal all-edges rooted CFG audit** (SEH/jumptable and inter-function target boundaries require T01 validation).

## 本次第一手 BIN 反組譯（指定入口）

注意：下面以函式入口開始連續解碼，**不自動等於完整可達 CFG**；不追逐 SEH/thunk 外部段、不可把無控制流根據的線性尾端當必然執行。

### 入口 `0x62E490` 到 `0x62E700`

```asm
  62e490:	55                   	push   ebp
  62e491:	8b ec                	mov    ebp,esp
  62e493:	6a ff                	push   0xffffffff
  62e495:	68 ce 8c 94 00       	push   0x948cce
  62e49a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  62e4a0:	50                   	push   eax
  62e4a1:	83 ec 48             	sub    esp,0x48
  62e4a4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  62e4a9:	33 c5                	xor    eax,ebp
  62e4ab:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  62e4ae:	53                   	push   ebx
  62e4af:	56                   	push   esi
  62e4b0:	57                   	push   edi
  62e4b1:	50                   	push   eax
  62e4b2:	8d 45 f4             	lea    eax,[ebp-0xc]
  62e4b5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  62e4bb:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62e4c2:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  62e4c5:	75 28                	jne    0x62e4ef
  62e4c7:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  62e4ce:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  62e4d5:	e8 86 19 ed ff       	call   0x4ffe60
  62e4da:	68 00 cf bc 00       	push   0xbccf00
  62e4df:	e8 36 3e 26 00       	call   0x89231a
  62e4e4:	83 c4 04             	add    esp,0x4
  62e4e7:	83 cf ff             	or     edi,0xffffffff
  62e4ea:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  62e4ed:	eb 03                	jmp    0x62e4f2
  62e4ef:	83 cf ff             	or     edi,0xffffffff
  62e4f2:	68 a0 b2 fa 00       	push   0xfab2a0
  62e4f7:	e8 d4 2a ed ff       	call   0x500fd0
  62e4fc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62e503:	0f b7 f0             	movzx  esi,ax
  62e506:	75 23                	jne    0x62e52b
  62e508:	b8 01 00 00 00       	mov    eax,0x1
  62e50d:	09 05 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,eax
  62e513:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  62e516:	e8 45 19 ed ff       	call   0x4ffe60
  62e51b:	68 00 cf bc 00       	push   0xbccf00
  62e520:	e8 f5 3d 26 00       	call   0x89231a
  62e525:	83 c4 04             	add    esp,0x4
  62e528:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  62e52b:	68 a0 b2 fa 00       	push   0xfab2a0
  62e530:	e8 6b 2e ed ff       	call   0x5013a0
  62e535:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62e53c:	0f b7 c0             	movzx  eax,ax
  62e53f:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  62e542:	75 23                	jne    0x62e567
  62e544:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  62e54b:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  62e552:	e8 09 19 ed ff       	call   0x4ffe60
  62e557:	68 00 cf bc 00       	push   0xbccf00
  62e55c:	e8 b9 3d 26 00       	call   0x89231a
  62e561:	83 c4 04             	add    esp,0x4
  62e564:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  62e567:	89 75 d0             	mov    DWORD PTR [ebp-0x30],esi
  62e56a:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  62e570:	8d 4d d0             	lea    ecx,[ebp-0x30]
  62e573:	51                   	push   ecx
  62e574:	8d 45 c8             	lea    eax,[ebp-0x38]
  62e577:	8b ce                	mov    ecx,esi
  62e579:	e8 a2 57 ed ff       	call   0x503d20
  62e57e:	8b 4d c8             	mov    ecx,DWORD PTR [ebp-0x38]
  62e581:	3b 4e 04             	cmp    ecx,DWORD PTR [esi+0x4]
  62e584:	74 08                	je     0x62e58e
  62e586:	83 c1 10             	add    ecx,0x10
  62e589:	89 4d d0             	mov    DWORD PTR [ebp-0x30],ecx
  62e58c:	eb 07                	jmp    0x62e595
  62e58e:	c7 45 d0 00 00 00 00 	mov    DWORD PTR [ebp-0x30],0x0
  62e595:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62e59c:	75 29                	jne    0x62e5c7
  62e59e:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  62e5a5:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  62e5ac:	e8 af 18 ed ff       	call   0x4ffe60
  62e5b1:	68 00 cf bc 00       	push   0xbccf00
  62e5b6:	e8 5f 3d 26 00       	call   0x89231a
  62e5bb:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  62e5be:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  62e5c4:	83 c4 04             	add    esp,0x4
  62e5c7:	8b 55 cc             	mov    edx,DWORD PTR [ebp-0x34]
  62e5ca:	8d 45 cc             	lea    eax,[ebp-0x34]
  62e5cd:	50                   	push   eax
  62e5ce:	8d 45 c8             	lea    eax,[ebp-0x38]
  62e5d1:	8b ce                	mov    ecx,esi
  62e5d3:	89 55 cc             	mov    DWORD PTR [ebp-0x34],edx
  62e5d6:	e8 45 57 ed ff       	call   0x503d20
  62e5db:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  62e5de:	8b 45 c8             	mov    eax,DWORD PTR [ebp-0x38]
  62e5e1:	3b c6                	cmp    eax,esi
  62e5e3:	74 05                	je     0x62e5ea
  62e5e5:	8d 78 10             	lea    edi,[eax+0x10]
  62e5e8:	eb 02                	jmp    0x62e5ec
  62e5ea:	33 ff                	xor    edi,edi
  62e5ec:	8b 55 d0             	mov    edx,DWORD PTR [ebp-0x30]
  62e5ef:	85 d2                	test   edx,edx
  62e5f1:	0f 84 95 00 00 00    	je     0x62e68c
  62e5f7:	83 c2 4c             	add    edx,0x4c
  62e5fa:	bf 08 00 00 00       	mov    edi,0x8
  62e5ff:	39 7a 14             	cmp    DWORD PTR [edx+0x14],edi
  62e602:	72 02                	jb     0x62e606
  62e604:	8b 12                	mov    edx,DWORD PTR [edx]
  62e606:	33 c9                	xor    ecx,ecx
  62e608:	8b c2                	mov    eax,edx
  62e60a:	c7 45 c0 07 00 00 00 	mov    DWORD PTR [ebp-0x40],0x7
  62e611:	c7 45 bc 00 00 00 00 	mov    DWORD PTR [ebp-0x44],0x0
  62e618:	66 89 4d ac          	mov    WORD PTR [ebp-0x54],cx
  62e61c:	8d 70 02             	lea    esi,[eax+0x2]
  62e61f:	90                   	nop
  62e620:	66 8b 08             	mov    cx,WORD PTR [eax]
  62e623:	83 c0 02             	add    eax,0x2
  62e626:	66 85 c9             	test   cx,cx
  62e629:	75 f5                	jne    0x62e620
  62e62b:	2b c6                	sub    eax,esi
  62e62d:	d1 f8                	sar    eax,1
  62e62f:	50                   	push   eax
  62e630:	52                   	push   edx
  62e631:	8d 4d ac             	lea    ecx,[ebp-0x54]
  62e634:	e8 27 3b dd ff       	call   0x402160
  62e639:	8b b3 08 01 00 00    	mov    esi,DWORD PTR [ebx+0x108]
  62e63f:	81 c6 e8 00 00 00    	add    esi,0xe8
  62e645:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  62e64c:	e8 9f 92 12 00       	call   0x7578f0
  62e651:	6a 7d                	push   0x7d
  62e653:	6a 7b                	push   0x7b
  62e655:	8d 55 ac             	lea    edx,[ebp-0x54]
  62e658:	52                   	push   edx
  62e659:	56                   	push   esi
  62e65a:	e8 71 b8 12 00       	call   0x759ed0
  62e65f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  62e666:	39 7d c0             	cmp    DWORD PTR [ebp-0x40],edi
  62e669:	72 0c                	jb     0x62e677
  62e66b:	8b 45 ac             	mov    eax,DWORD PTR [ebp-0x54]
  62e66e:	50                   	push   eax
  62e66f:	e8 98 2b 26 00       	call   0x89120c
  62e674:	83 c4 04             	add    esp,0x4
  62e677:	8b 8b 08 01 00 00    	mov    ecx,DWORD PTR [ebx+0x108]
  62e67d:	8b 11                	mov    edx,DWORD PTR [ecx]
  62e67f:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  62e685:	ff d0                	call   eax
  62e687:	e9 cd 00 00 00       	jmp    0x62e759
  62e68c:	85 ff                	test   edi,edi
  62e68e:	0f 84 9f 00 00 00    	je     0x62e733
  62e694:	83 7f 60 08          	cmp    DWORD PTR [edi+0x60],0x8
  62e698:	8d 47 4c             	lea    eax,[edi+0x4c]
  62e69b:	72 07                	jb     0x62e6a4
  62e69d:	8b 08                	mov    ecx,DWORD PTR [eax]
  62e69f:	89 4d d0             	mov    DWORD PTR [ebp-0x30],ecx
  62e6a2:	eb 03                	jmp    0x62e6a7
  62e6a4:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  62e6a7:	c7 45 cc 57 01 00 00 	mov    DWORD PTR [ebp-0x34],0x157
  62e6ae:	e8 6d 6f f5 ff       	call   0x585620
  62e6b3:	8b f0                	mov    esi,eax
  62e6b5:	8d 55 cc             	lea    edx,[ebp-0x34]
  62e6b8:	52                   	push   edx
  62e6b9:	8d 45 c8             	lea    eax,[ebp-0x38]
  62e6bc:	8b ce                	mov    ecx,esi
  62e6be:	e8 2d 5a f4 ff       	call   0x5740f0
  62e6c3:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  62e6c6:	8b 45 c8             	mov    eax,DWORD PTR [ebp-0x38]
  62e6c9:	3b c6                	cmp    eax,esi
  62e6cb:	74 0d                	je     0x62e6da
  62e6cd:	83 78 24 08          	cmp    DWORD PTR [eax+0x24],0x8
  62e6d1:	8d 48 10             	lea    ecx,[eax+0x10]
  62e6d4:	72 0a                	jb     0x62e6e0
  62e6d6:	8b 09                	mov    ecx,DWORD PTR [ecx]
  62e6d8:	eb 06                	jmp    0x62e6e0
  62e6da:	cc                   	int3
  62e6db:	b9 fc d1 be 00       	mov    ecx,0xbed1fc
  62e6e0:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  62e6e3:	50                   	push   eax
  62e6e4:	8b 47 0c             	mov    eax,DWORD PTR [edi+0xc]
  62e6e7:	8d 75 ac             	lea    esi,[ebp-0x54]
  62e6ea:	e8 11 58 e5 ff       	call   0x483f00
  62e6ef:	8b b3 08 01 00 00    	mov    esi,DWORD PTR [ebx+0x108]
  62e6f5:	83 c4 04             	add    esp,0x4
  62e6f8:	81 c6 e8 00 00 00    	add    esi,0xe8
  62e6fe:	c7 45      	mov    DWORD PTR [ebp-0x4],0x5
```

### 入口 `0x5B6BE0` 到 `0x5B6D20`

```asm
  5b6be0:	55                   	push   ebp
  5b6be1:	8b ec                	mov    ebp,esp
  5b6be3:	83 e4 f8             	and    esp,0xfffffff8
  5b6be6:	6a ff                	push   0xffffffff
  5b6be8:	68 2c 93 94 00       	push   0x94932c
  5b6bed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b6bf3:	50                   	push   eax
  5b6bf4:	83 ec 10             	sub    esp,0x10
  5b6bf7:	53                   	push   ebx
  5b6bf8:	56                   	push   esi
  5b6bf9:	57                   	push   edi
  5b6bfa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b6bff:	33 c4                	xor    eax,esp
  5b6c01:	50                   	push   eax
  5b6c02:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b6c06:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b6c0c:	8b f1                	mov    esi,ecx
  5b6c0e:	8b fa                	mov    edi,edx
  5b6c10:	85 f6                	test   esi,esi
  5b6c12:	74 26                	je     0x5b6c3a
  5b6c14:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6c16:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6c19:	ff d2                	call   edx
  5b6c1b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6c20:	75 04                	jne    0x5b6c26
  5b6c22:	8b de                	mov    ebx,esi
  5b6c24:	eb 16                	jmp    0x5b6c3c
  5b6c26:	6a 00                	push   0x0
  5b6c28:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6c2d:	68 18 21 bf 00       	push   0xbf2118
  5b6c32:	6a 00                	push   0x0
  5b6c34:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6c3a:	33 db                	xor    ebx,ebx
  5b6c3c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6c43:	75 29                	jne    0x5b6c6e
  5b6c45:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6c4c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6c53:	00 
  5b6c54:	e8 07 92 f4 ff       	call   0x4ffe60
  5b6c59:	68 00 cf bc 00       	push   0xbccf00
  5b6c5e:	e8 b7 b6 2d 00       	call   0x89231a
  5b6c63:	83 c4 04             	add    esp,0x4
  5b6c66:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6c6d:	ff 
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
  5b6d02:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6d06:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6d0d:	59                   	pop    ecx
  5b6d0e:	5f                   	pop    edi
  5b6d0f:	5e                   	pop    esi
  5b6d10:	5b                   	pop    ebx
  5b6d11:	8b e5                	mov    esp,ebp
  5b6d13:	5d                   	pop    ebp
  5b6d14:	c3                   	ret
  5b6d15:	cc                   	int3
  5b6d16:	cc                   	int3
  5b6d17:	cc                   	int3
  5b6d18:	cc                   	int3
  5b6d19:	cc                   	int3
  5b6d1a:	cc                   	int3
  5b6d1b:	cc                   	int3
  5b6d1c:	cc                   	int3
  5b6d1d:	cc                   	int3
  5b6d1e:	cc                   	int3
  5b6d1f:	cc                   	int3
```

### 入口 `0x62F640` 到 `0x62F780`

```asm
  62f640:	55                   	push   ebp
  62f641:	8b ec                	mov    ebp,esp
  62f643:	6a ff                	push   0xffffffff
  62f645:	68 5c 69 94 00       	push   0x94695c
  62f64a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  62f650:	50                   	push   eax
  62f651:	83 ec 08             	sub    esp,0x8
  62f654:	53                   	push   ebx
  62f655:	56                   	push   esi
  62f656:	57                   	push   edi
  62f657:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  62f65c:	33 c5                	xor    eax,ebp
  62f65e:	50                   	push   eax
  62f65f:	8d 45 f4             	lea    eax,[ebp-0xc]
  62f662:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  62f668:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  62f66b:	8b 8b 18 01 00 00    	mov    ecx,DWORD PTR [ebx+0x118]
  62f671:	8b b3 14 01 00 00    	mov    esi,DWORD PTR [ebx+0x114]
  62f677:	3b f1                	cmp    esi,ecx
  62f679:	74 21                	je     0x62f69c
  62f67b:	8b c1                	mov    eax,ecx
  62f67d:	2b c1                	sub    eax,ecx
  62f67f:	c1 f8 02             	sar    eax,0x2
  62f682:	8d 3c 85 00 00 00 00 	lea    edi,[eax*4+0x0]
  62f689:	57                   	push   edi
  62f68a:	51                   	push   ecx
  62f68b:	56                   	push   esi
  62f68c:	e8 5f 1c 26 00       	call   0x8912f0
  62f691:	83 c4 0c             	add    esp,0xc
  62f694:	03 fe                	add    edi,esi
  62f696:	89 bb 18 01 00 00    	mov    DWORD PTR [ebx+0x118],edi
  62f69c:	bb 70 11 fb 00       	mov    ebx,0xfb1170
  62f6a1:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  62f6a8:	bf 01 00 00 00       	mov    edi,0x1
  62f6ad:	75 26                	jne    0x62f6d5
  62f6af:	09 3d 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,edi
  62f6b5:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  62f6bc:	e8 9f 07 ed ff       	call   0x4ffe60
  62f6c1:	68 00 cf bc 00       	push   0xbccf00
  62f6c6:	e8 4f 2c 26 00       	call   0x89231a
  62f6cb:	83 c4 04             	add    esp,0x4
  62f6ce:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
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
  62f759:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  62f75c:	e8 2f 03 00 00       	call   0x62fa90
  62f761:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  62f764:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  62f76b:	59                   	pop    ecx
  62f76c:	5f                   	pop    edi
  62f76d:	5e                   	pop    esi
  62f76e:	5b                   	pop    ebx
  62f76f:	8b e5                	mov    esp,ebp
  62f771:	5d                   	pop    ebp
  62f772:	c2 04 00             	ret    0x4
  62f775:	cc                   	int3
  62f776:	cc                   	int3
  62f777:	cc                   	int3
  62f778:	cc                   	int3
  62f779:	cc                   	int3
  62f77a:	cc                   	int3
  62f77b:	cc                   	int3
  62f77c:	cc                   	int3
  62f77d:	cc                   	int3
  62f77e:	cc                   	int3
  62f77f:	cc                   	int3
```


### 四項座標第一手 bytes

- VA 0x0062E5CD, .text raw 0x0022D9CD: 50 8d 45 c8 8b ce 89 55 cc e8 45 57
- VA 0x0062E5CE, .text raw 0x0022D9CE: 8d 45 c8 8b ce 89 55 cc e8 45 57 ed
- VA 0x005B6CCF, .text raw 0x001B60CF: 8b 53 14 a1 bc b1 fa 00 8b 4e 28 52
- VA 0x0062F700, .text raw 0x0022EB00: c7 45 fc ff ff ff ff 89 75 f0 8b 35
- VA 0x0062F70A, .text raw 0x0022EB0A: 8b 35 4c 11 fb 00 8d 45 f0 50 8d 45
- VA 0x0062E659, .text raw 0x0022DA59: 56 e8 71 b8 12 00 c7 45 fc ff ff ff
- VA 0x0062E65A, .text raw 0x0022DA5A: e8 71 b8 12 00 c7 45 fc ff ff ff ff

## 修正影響／驗收門檻

- **Client 待逆向**：此勘誤沒有證成任何新的 Quest S→C wire opcode 或 Quest16→15 接取 UI 閉環。
- **Server 待開發**：相容 Server 的任務前置、解鎖、持久化由 S00 SPEC/ADR 獨立設計，不可由局部 ASM 冒稱官方判斷。
- **跨功能待整合**：如涉及 T02 framing/網路、T06 UI 等，由相關 Task 的原始證據及 T01 claim-level review 處理。
- **待遊玩驗證**：未執行原 Client 或動態封包測試。
- **T01 狀態**：GitHub 仍為 `NEEDS_FIX`/`NEEDS_QUALIFICATION`；待來源 Task 將此勘誤審核／提交後，才能提出 `READY_FOR_REVIEW`，且 T01 通過才可 `RESOLVED`。

## 原始來源／交叉引用

- `kr/tasks/T16/README.md` 上固定退回 ID 和精確 blob SHA。
- `shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json`；`shared/integrations/T01-20261029-continuation-02/t16/README.md`。
- `shared/verified-knowledge/README.md` 的有界條目不等於本篇 FULL-PASS。