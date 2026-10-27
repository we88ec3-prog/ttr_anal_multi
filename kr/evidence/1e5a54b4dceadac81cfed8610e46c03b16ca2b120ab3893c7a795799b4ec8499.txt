# T16-40 — Quest UI 文本引用、封包預設 handler 及跨鏈反證

- 原始研究時間（Asia/Taipei）：20261028-023112
- Source: KR `Tartaros.bin`，唯讀靜態分析，bytes=`12472320`，SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- GitHub 起始基線：`0de4fe39719a83f38a003af8efeed6b5c9b20f90`（研究啟動時核對）
- 本段主題：Quest UI 文本引用、封包預設 handler 及跨鏈反證
- 界線：可確定的只有原生機器碼與本段直接解析之位址／跳躍；**不宣稱**任何原版任務 ID、NPC、完成條件、封包權威或 Lua/XML 實體內容。
- 研究方法：`objdump -D -Mintel -j .text` 依 VA 擷取原始 bytes；另外從 `.text` 扫描 `E8 rel32` 作交叉參照候選，僅經指令對齊與上下文核對後方可作控制流程證據。

## 1. 可重現基線與 PE 映射

| section | VA 起點 | file offset | 限制 |
|---|---|---|---|
| .text | `0x00401000` | `0x400` | 指令與常數候選 |
| .rdata | `0x00BD2000` | `0x007D0600` | 字串不是語義證據 |
| .data | `0x00D61000` | `0x0095E800` | static image ≠ runtime field value |

## 2. 研究範圍與函式邊界

本段截取下列 **位址視窗**，它們不必然等於完整函式；需以 prologue、返回路徑及多入口參照重新界定。總計 271 行反組譯輸出。

| start | stop (exclusive) | raw start | direct E8 candidates to start |
|---|---|---|---|
| `0x00502480` | `0x00502540` | `0x101880` | `none found by raw E8 sweep` |
| `0x00502870` | `0x00502920` | `0x101C70` | `none found by raw E8 sweep` |
| `0x004B7D30` | `0x004B7DC0` | `0xB7130` | `none found by raw E8 sweep` |
| `0x004930E0` | `0x00493200` | `0x924E0` | `none found by raw E8 sweep` |

**注意：** raw `E8` 比對可能掃到指令中間；不得把表格所有候選自動計為真實 caller。`call [reg]`、vtable 呼叫亦不受 raw E8 掃描覆蓋。

## 3. Native assembly evidence

### `0x00502480` .. `0x00502540`

```asm
  502480:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  502483:	33 c0                	xor    eax,eax
  502485:	3b f0                	cmp    esi,eax
  502487:	74 17                	je     0x5024a0
  502489:	39 87 70 03 00 00    	cmp    DWORD PTR [edi+0x370],eax
  50248f:	74 0f                	je     0x5024a0
  502491:	e8 6a 4c 2a 00       	call   0x7a7100
  502496:	d9 9d 54 ff ff ff    	fstp   DWORD PTR [ebp-0xac]
  50249c:	33 c0                	xor    eax,eax
  50249e:	eb 0b                	jmp    0x5024ab
  5024a0:	0f 57 c0             	xorps  xmm0,xmm0
  5024a3:	f3 0f 11 85 54 ff ff 	movss  DWORD PTR [ebp-0xac],xmm0
  5024aa:	ff 
  5024ab:	d9 85 54 ff ff ff    	fld    DWORD PTR [ebp-0xac]
  5024b1:	66 8b 7f 04          	mov    di,WORD PTR [edi+0x4]
  5024b5:	dc 05 78 5e c5 00    	fadd   QWORD PTR ds:0xc55e78
  5024bb:	83 ec 08             	sub    esp,0x8
  5024be:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  5024c1:	0f b7 d7             	movzx  edx,di
  5024c4:	d8 45 ec             	fadd   DWORD PTR [ebp-0x14]
  5024c7:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  5024ca:	c7 45 d4 98 da c0 00 	mov    DWORD PTR [ebp-0x2c],0xc0da98
  5024d1:	89 45 d8             	mov    DWORD PTR [ebp-0x28],eax
  5024d4:	d9 5d ec             	fstp   DWORD PTR [ebp-0x14]
  5024d7:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  5024da:	d9 e8                	fld1
  5024dc:	89 45 e0             	mov    DWORD PTR [ebp-0x20],eax
  5024df:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  5024e3:	d9 ee                	fldz
  5024e5:	d9 1c 24             	fstp   DWORD PTR [esp]
  5024e8:	51                   	push   ecx
  5024e9:	52                   	push   edx
  5024ea:	e8 51 8c f9 ff       	call   0x49b140
  5024ef:	8d 55 d0             	lea    edx,[ebp-0x30]
  5024f2:	8b c8                	mov    ecx,eax
  5024f4:	e8 27 fa 04 00       	call   0x551f20
  5024f9:	8b 43 28             	mov    eax,DWORD PTR [ebx+0x28]
  5024fc:	89 85 50 ff ff ff    	mov    DWORD PTR [ebp-0xb0],eax
  502502:	e8 89 d8 ff ff       	call   0x4ffd90
  502507:	8b f0                	mov    esi,eax
  502509:	8d 8d 50 ff ff ff    	lea    ecx,[ebp-0xb0]
  50250f:	51                   	push   ecx
  502510:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
  502516:	8b ce                	mov    ecx,esi
  502518:	e8 d3 1b 07 00       	call   0x5740f0
  50251d:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  502520:	8b 85 54 ff ff ff    	mov    eax,DWORD PTR [ebp-0xac]
  502526:	3b c6                	cmp    eax,esi
  502528:	74 7f                	je     0x5025a9
  50252a:	8d 70 10             	lea    esi,[eax+0x10]
  50252d:	bf 10 00 00 00       	mov    edi,0x10
  502532:	39 7e 14             	cmp    DWORD PTR [esi+0x14],edi
  502535:	72 02                	jb     0x502539
  502537:	8b 36                	mov    esi,DWORD PTR [esi]
  502539:	85 f6                	test   esi,esi
  50253b:	74 6c                	je     0x5025a9
  50253d:	68 a4 da         	push   0xc0daa4
```

### `0x00502870` .. `0x00502920`

```asm
  502870:	48                   	dec    eax
  502871:	14 e8                	adc    al,0xe8
  502873:	d9 81 08 00 e9 a1    	fld    DWORD PTR [ecx-0x5e16fff8]
  502879:	02 00                	add    al,BYTE PTR [eax]
  50287b:	00 33                	add    BYTE PTR [ebx],dh
  50287d:	c0 50 e8 cc          	rcl    BYTE PTR [eax-0x18],0xcc
  502881:	81 08 00 e9 94 02    	or     DWORD PTR [eax],0x294e900
  502887:	00 00                	add    BYTE PTR [eax],al
  502889:	8b 53 48             	mov    edx,DWORD PTR [ebx+0x48]
  50288c:	52                   	push   edx
  50288d:	57                   	push   edi
  50288e:	e8 ad 06 f2 ff       	call   0x422f40
  502893:	8b c8                	mov    ecx,eax
  502895:	e8 c6 ee 05 00       	call   0x561760
  50289a:	bf 0f 00 00 00       	mov    edi,0xf
  50289f:	68 b8 da c0 00       	push   0xc0dab8
  5028a4:	8d 47 fc             	lea    eax,[edi-0x4]
  5028a7:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  5028aa:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  5028ad:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  5028b0:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  5028b4:	e8 57 8a f0 ff       	call   0x40b310
  5028b9:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5028bc:	f6 05 d4 b0 fa 00 01 	test   BYTE PTR ds:0xfab0d4,0x1
  5028c3:	75 21                	jne    0x5028e6
  5028c5:	83 0d d4 b0 fa 00 01 	or     DWORD PTR ds:0xfab0d4,0x1
  5028cc:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  5028d0:	e8 cb 7a 30 00       	call   0x80a3a0
  5028d5:	68 d0 cd bc 00       	push   0xbccdd0
  5028da:	e8 3b fa 38 00       	call   0x89231a
  5028df:	83 c4 04             	add    esp,0x4
  5028e2:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  5028e6:	68 28 b0 fa 00       	push   0xfab028
  5028eb:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  5028ee:	e8 0d 82 30 00       	call   0x80ab00
  5028f3:	3b c6                	cmp    eax,esi
  5028f5:	74 09                	je     0x502900
  5028f7:	8b 10                	mov    edx,DWORD PTR [eax]
  5028f9:	8b c8                	mov    ecx,eax
  5028fb:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  5028fe:	ff d0                	call   eax
  502900:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  502907:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  50290b:	72 0c                	jb     0x502919
  50290d:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  502910:	51                   	push   ecx
  502911:	e8 f6 e8 38 00       	call   0x89120c
  502916:	83 c4 04             	add    esp,0x4
  502919:	68 c4 00 00 00       	push   0xc4
  50291e:	89 7d              	mov    DWORD PTR [ebp-0x18],edi
```

### `0x004B7D30` .. `0x004B7DC0`

```asm
  4b7d30:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d32:	ff 60 08             	jmp    DWORD PTR [eax+0x8]
  4b7d35:	cc                   	int3
  4b7d36:	cc                   	int3
  4b7d37:	cc                   	int3
  4b7d38:	cc                   	int3
  4b7d39:	cc                   	int3
  4b7d3a:	cc                   	int3
  4b7d3b:	cc                   	int3
  4b7d3c:	cc                   	int3
  4b7d3d:	cc                   	int3
  4b7d3e:	cc                   	int3
  4b7d3f:	cc                   	int3
  4b7d40:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d42:	ff 60 0c             	jmp    DWORD PTR [eax+0xc]
  4b7d45:	cc                   	int3
  4b7d46:	cc                   	int3
  4b7d47:	cc                   	int3
  4b7d48:	cc                   	int3
  4b7d49:	cc                   	int3
  4b7d4a:	cc                   	int3
  4b7d4b:	cc                   	int3
  4b7d4c:	cc                   	int3
  4b7d4d:	cc                   	int3
  4b7d4e:	cc                   	int3
  4b7d4f:	cc                   	int3
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

### `0x004930E0` .. `0x00493200`

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
  49315e:	c2 10 00             	ret    0x10
  493161:	cc                   	int3
  493162:	cc                   	int3
  493163:	cc                   	int3
  493164:	cc                   	int3
  493165:	cc                   	int3
  493166:	cc                   	int3
  493167:	cc                   	int3
  493168:	cc                   	int3
  493169:	cc                   	int3
  49316a:	cc                   	int3
  49316b:	cc                   	int3
  49316c:	cc                   	int3
  49316d:	cc                   	int3
  49316e:	cc                   	int3
  49316f:	cc                   	int3
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
  4931fb:	89 90 a8 0f 00     	mov    DWORD PTR [eax+0xfa8],edx
```

## 4. 局部控制流程與資料流（指令級）

以下為本段出現的直接 call 指令節錄；**callee 的高階名稱均不自動確定**：

```asm
  502491:	e8 6a 4c 2a 00       	call   0x7a7100
  5024ea:	e8 51 8c f9 ff       	call   0x49b140
  5024f4:	e8 27 fa 04 00       	call   0x551f20
  502502:	e8 89 d8 ff ff       	call   0x4ffd90
  502518:	e8 d3 1b 07 00       	call   0x5740f0
  50288e:	e8 ad 06 f2 ff       	call   0x422f40
  502895:	e8 c6 ee 05 00       	call   0x561760
  5028b4:	e8 57 8a f0 ff       	call   0x40b310
  5028d0:	e8 cb 7a 30 00       	call   0x80a3a0
  5028da:	e8 3b fa 38 00       	call   0x89231a
  5028ee:	e8 0d 82 30 00       	call   0x80ab00
  5028fe:	ff d0                	call   eax
  502911:	e8 f6 e8 38 00       	call   0x89120c
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d6e:	ff d2                	call   edx
  4b7d80:	ff d2                	call   edx
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7dbc:	ff d2                	call   edx
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493135:	ff d2                	call   edx
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
```

比較、測試及分支位置（節錄）：

```asm
  502485:	3b f0                	cmp    esi,eax
  502487:	74 17                	je     0x5024a0
  502489:	39 87 70 03 00 00    	cmp    DWORD PTR [edi+0x370],eax
  50248f:	74 0f                	je     0x5024a0
  50249e:	eb 0b                	jmp    0x5024ab
  502526:	3b c6                	cmp    eax,esi
  502528:	74 7f                	je     0x5025a9
  502532:	39 7e 14             	cmp    DWORD PTR [esi+0x14],edi
  502535:	72 02                	jb     0x502539
  502539:	85 f6                	test   esi,esi
  50253b:	74 6c                	je     0x5025a9
  5028bc:	f6 05 d4 b0 fa 00 01 	test   BYTE PTR ds:0xfab0d4,0x1
  5028c3:	75 21                	jne    0x5028e6
  5028f3:	3b c6                	cmp    eax,esi
  5028f5:	74 09                	je     0x502900
  502907:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  50290b:	72 0c                	jb     0x502919
  4b7d32:	ff 60 08             	jmp    DWORD PTR [eax+0x8]
  4b7d42:	ff 60 0c             	jmp    DWORD PTR [eax+0xc]
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7dbf:	c3                   	ret
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  493102:	c2 10 00             	ret    0x10
  49310b:	75 47                	jne    0x493154
```

### 最低限度的局部偽碼（語義不作確定）

```cpp
// Abstracted from instruction traces, not reconstructed source.
void candidate_native_path(State* opaque, Input* candidate) {
    // Calls and conditional transitions follow the literal assembly above.
    // Unknowns: field ownership, valid input domain, caller context, side effects.
    // Any quest step / success / tutorial flag semantics remain unknown.
}
```

## 5. T16 功能鏈驗收矩陣

| 驗證項 | 狀態 | 說明 |
|---|---|---|
| KR 映像版本與 VA 原生反組譯 | 原生已確認 | 本段實際读取 BIN 機器碼並附起訖區間 |
| 選定指令之直接 call / branch | 原生已確認（有界） | 詳見 assembly，非完整函式 call graph |
| 此路徑是否屬 Quest / Tutorial 的業務邏輯 | 部分確認／推測 | 依前批上下文選取；需要 event 與進度鏈封閉 |
| 伺服器權威任務 writer | 資訊缺失 | 未由本段地址鎖定 |
| 教學步驟及觸發旗標 | 資訊缺失 | 不能由腳本入口名稱倒推 |
| 教學完成後第一個主線 | 資訊缺失 | 無原生 quest/step ID |
| TC 版本函式對應 | 資訊缺失 | 本段只使用 KR BIN |
| 可玩性驗證 | 未測試 | 禁止將原生指令分析視為可玩 |

## 6. 跨 Task 分工與證據風險

- T02：封包 envelope／dispatcher 是其主責；T16 僅需任務業務欄位與事件結果。
- T03/T04：登入與既有角色是 T16 的輸入；不可臆造新角色教學初始值。
- T07/T14：關卡轉場／結算由其主責，T16 僅需其對進度的輸入事件。
- T15：持久化底層，T16 僅指定需要寫入或恢復之欄位（目前 unknown）。
- T08：實體行為僅作事件界面引用。

## 7. 延後本地資源（DEFERRED-LOCAL-RESOURCE）

| 來源 | 待本地分析交付的最小內容 | 阻塞語義 |
|---|---|---|
| `Event/TutorialMain.lua` | 函式定義／呼叫、步驟與事件線索、原檔 SHA | 教學節點序列／完成條件 |
| `Event/TutorialBase.lua` | 提供的 Lua API 清單及參數 | 客戶端教學行為 |
| `Table/QuestInfo.xml` | Quest/step ID 與前置條件及資料 schema | 主線入口／依賴 |
| `Table/QuestTalk.xml` | NPC／對話／任務 ID 關聯及 SHA | 交付與對話 |
| 原版伺服器任務資料與封包 | 任務業務欄位、接受／拒絕及重登資料 | 權威、儲存、恢復 |

以上列為延後，本批不要求、下載或臆造檔案。

## 8. 後續應查項目

1. 從本段已驗證的 branch / call 對應上游條件與下游 consumer；目標是可確認業務 writer，而非重複解析 CRT 或 container。
2. 比對 T16-1～T16-32 有界結論，釐清新發現是否真能跨越任務介面。
3. 有足夠原生來源前不將任何 `0x6`、Quest 顯示文字或本地補丁當作原版進度旗標。
4. 將原始資源缺口留待本地流程回填，下一段仍優先研究 BIN/EXE 可證實的路徑。

## 9. 提交狀態

本文件生成時為原始本地稿；是否已推 GitHub 以後續實際提交收據為準。