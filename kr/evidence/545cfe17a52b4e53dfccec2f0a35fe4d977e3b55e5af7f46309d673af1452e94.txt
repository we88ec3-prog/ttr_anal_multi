# T16-36 — TutoQuest 屬性解析、命中／未命中分支，確認非進度 writer

- 原始研究時間（Asia/Taipei）：20261028-023112
- Source: KR `Tartaros.bin`，唯讀靜態分析，bytes=`12472320`，SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- GitHub 起始基線：`0de4fe39719a83f38a003af8efeed6b5c9b20f90`（研究啟動時核對）
- 本段主題：TutoQuest 屬性解析、命中／未命中分支，確認非進度 writer
- 界線：可確定的只有原生機器碼與本段直接解析之位址／跳躍；**不宣稱**任何原版任務 ID、NPC、完成條件、封包權威或 Lua/XML 實體內容。
- 研究方法：`objdump -D -Mintel -j .text` 依 VA 擷取原始 bytes；另外從 `.text` 扫描 `E8 rel32` 作交叉參照候選，僅經指令對齊與上下文核對後方可作控制流程證據。

## 1. 可重現基線與 PE 映射

| section | VA 起點 | file offset | 限制 |
|---|---|---|---|
| .text | `0x00401000` | `0x400` | 指令與常數候選 |
| .rdata | `0x00BD2000` | `0x007D0600` | 字串不是語義證據 |
| .data | `0x00D61000` | `0x0095E800` | static image ≠ runtime field value |

## 2. 研究範圍與函式邊界

本段截取下列 **位址視窗**，它們不必然等於完整函式；需以 prologue、返回路徑及多入口參照重新界定。總計 287 行反組譯輸出。

| start | stop (exclusive) | raw start | direct E8 candidates to start |
|---|---|---|---|
| `0x00531E00` | `0x00531F90` | `0x131200` | `none found by raw E8 sweep` |
| `0x005321E0` | `0x00532310` | `0x1315E0` | `none found by raw E8 sweep` |
| `0x0072E2E0` | `0x0072E390` | `0x32D6E0` | `0x00407812`, `0x004079D5`, `0x004456C3`, `0x0044570D`, `0x0044587D`, `0x0044E9F9`, `0x0044EA0D`, `0x0046E5F4`, `0x004747E5`, `0x0047DF2B`, `0x00489A50`, `0x00489A9C` |

**注意：** raw `E8` 比對可能掃到指令中間；不得把表格所有候選自動計為真實 caller。`call [reg]`、vtable 呼叫亦不受 raw E8 掃描覆蓋。

## 3. Native assembly evidence

### `0x00531E00` .. `0x00531F90`

```asm
  531e00:	00 00                	add    BYTE PTR [eax],al
  531e02:	bf 0f 00 00 00       	mov    edi,0xf
  531e07:	89 bc 24 c4 00 00 00 	mov    DWORD PTR [esp+0xc4],edi
  531e0e:	89 9c 24 c0 00 00 00 	mov    DWORD PTR [esp+0xc0],ebx
  531e15:	88 9c 24 b0 00 00 00 	mov    BYTE PTR [esp+0xb0],bl
  531e1c:	c6 84 24 e8 01 00 00 	mov    BYTE PTR [esp+0x1e8],0x1
  531e23:	01 
  531e24:	6a 04                	push   0x4
  531e26:	68 f0 d5 c0 00       	push   0xc0d5f0
  531e2b:	8d 8c 24 9c 00 00 00 	lea    ecx,[esp+0x9c]
  531e32:	89 bc 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],edi
  531e39:	89 9c 24 ac 00 00 00 	mov    DWORD PTR [esp+0xac],ebx
  531e40:	88 9c 24 9c 00 00 00 	mov    BYTE PTR [esp+0x9c],bl
  531e47:	e8 24 0c ed ff       	call   0x402a70
  531e4c:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  531e50:	68 75 23 bf 00       	push   0xbf2375
  531e55:	8d 84 24 98 00 00 00 	lea    eax,[esp+0x98]
  531e5c:	8d 74 24 60          	lea    esi,[esp+0x60]
  531e60:	c6 84 24 ec 01 00 00 	mov    BYTE PTR [esp+0x1ec],0x2
  531e67:	02 
  531e68:	e8 83 ce 1f 00       	call   0x72ecf0
  531e6d:	50                   	push   eax
  531e6e:	8d 8c 24 b4 00 00 00 	lea    ecx,[esp+0xb4]
  531e75:	c6 84 24 ec 01 00 00 	mov    BYTE PTR [esp+0x1ec],0x3
  531e7c:	03 
  531e7d:	e8 2e 0d ed ff       	call   0x402bb0
  531e82:	be 10 00 00 00       	mov    esi,0x10
  531e87:	39 74 24 70          	cmp    DWORD PTR [esp+0x70],esi
  531e8b:	72 0d                	jb     0x531e9a
  531e8d:	8b 44 24 5c          	mov    eax,DWORD PTR [esp+0x5c]
  531e91:	50                   	push   eax
  531e92:	e8 75 f3 35 00       	call   0x89120c
  531e97:	83 c4 04             	add    esp,0x4
  531e9a:	c6 84 24 e8 01 00 00 	mov    BYTE PTR [esp+0x1e8],0x1
  531ea1:	01 
  531ea2:	89 7c 24 70          	mov    DWORD PTR [esp+0x70],edi
  531ea6:	89 5c 24 6c          	mov    DWORD PTR [esp+0x6c],ebx
  531eaa:	88 5c 24 5c          	mov    BYTE PTR [esp+0x5c],bl
  531eae:	39 b4 24 a8 00 00 00 	cmp    DWORD PTR [esp+0xa8],esi
  531eb5:	72 10                	jb     0x531ec7
  531eb7:	8b 8c 24 94 00 00 00 	mov    ecx,DWORD PTR [esp+0x94]
  531ebe:	51                   	push   ecx
  531ebf:	e8 48 f3 35 00       	call   0x89120c
  531ec4:	83 c4 04             	add    esp,0x4
  531ec7:	8b 74 24 10          	mov    esi,DWORD PTR [esp+0x10]
  531ecb:	83 c6 44             	add    esi,0x44
  531ece:	68 84 f1 c0 00       	push   0xc0f184
  531ed3:	8b fe                	mov    edi,esi
  531ed5:	e8 c6 e1 1f 00       	call   0x7300a0
  531eda:	3b c3                	cmp    eax,ebx
  531edc:	74 1a                	je     0x531ef8
  531ede:	83 c0 30             	add    eax,0x30
  531ee1:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  531ee5:	72 02                	jb     0x531ee9
  531ee7:	8b 00                	mov    eax,DWORD PTR [eax]
  531ee9:	3b c3                	cmp    eax,ebx
  531eeb:	74 0b                	je     0x531ef8
  531eed:	50                   	push   eax
  531eee:	e8 c1 f8 35 00       	call   0x8917b4
  531ef3:	83 c4 04             	add    esp,0x4
  531ef6:	eb 02                	jmp    0x531efa
  531ef8:	33 c0                	xor    eax,eax
  531efa:	48                   	dec    eax
  531efb:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  531eff:	c1 e0 04             	shl    eax,0x4
  531f02:	8d b8 48 1e fe 00    	lea    edi,[eax+0xfe1e48]
  531f08:	8d 8c 24 b0 00 00 00 	lea    ecx,[esp+0xb0]
  531f0f:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  531f13:	e8 58 07 00 00       	call   0x532670
  531f18:	68 90 f1 c0 00       	push   0xc0f190
  531f1d:	8b fe                	mov    edi,esi
  531f1f:	e8 7c e1 1f 00       	call   0x7300a0
  531f24:	3b c3                	cmp    eax,ebx
  531f26:	74 1a                	je     0x531f42
  531f28:	83 c0 30             	add    eax,0x30
  531f2b:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  531f2f:	72 02                	jb     0x531f33
  531f31:	8b 00                	mov    eax,DWORD PTR [eax]
  531f33:	3b c3                	cmp    eax,ebx
  531f35:	74 0b                	je     0x531f42
  531f37:	50                   	push   eax
  531f38:	e8 77 f8 35 00       	call   0x8917b4
  531f3d:	83 c4 04             	add    esp,0x4
  531f40:	eb 02                	jmp    0x531f44
  531f42:	33 c0                	xor    eax,eax
  531f44:	48                   	dec    eax
  531f45:	68 9c f1 c0 00       	push   0xc0f19c
  531f4a:	8b fe                	mov    edi,esi
  531f4c:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  531f50:	e8 4b e1 1f 00       	call   0x7300a0
  531f55:	3b c3                	cmp    eax,ebx
  531f57:	74 1e                	je     0x531f77
  531f59:	83 c0 30             	add    eax,0x30
  531f5c:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  531f60:	72 02                	jb     0x531f64
  531f62:	8b 00                	mov    eax,DWORD PTR [eax]
  531f64:	3b c3                	cmp    eax,ebx
  531f66:	74 0f                	je     0x531f77
  531f68:	50                   	push   eax
  531f69:	e8 46 f8 35 00       	call   0x8917b4
  531f6e:	83 c4 04             	add    esp,0x4
  531f71:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  531f75:	eb 04                	jmp    0x531f7b
  531f77:	89 5c 24 14          	mov    DWORD PTR [esp+0x14],ebx
  531f7b:	39 5c 24 18          	cmp    DWORD PTR [esp+0x18],ebx
  531f7f:	0f 8c 83 02 00 00    	jl     0x532208
  531f85:	39 5c 24 14          	cmp    DWORD PTR [esp+0x14],ebx
  531f89:	0f 84 79 02 00 00    	je     0x532208
  531f8f:	33                 	xor    edx,edx
```

### `0x005321E0` .. `0x00532310`

```asm
  5321e0:	a8 00                	test   al,0x0
  5321e2:	00 00                	add    BYTE PTR [eax],al
  5321e4:	08 c7                	or     bh,al
  5321e6:	44                   	inc    esp
  5321e7:	24 54                	and    al,0x54
  5321e9:	07                   	pop    es
  5321ea:	00 00                	add    BYTE PTR [eax],al
  5321ec:	00 89 5c 24 50 66    	add    BYTE PTR [ecx+0x6650245c],cl
  5321f2:	89 54 24 40          	mov    DWORD PTR [esp+0x40],edx
  5321f6:	72 10                	jb     0x532208
  5321f8:	8b 84 24 94 00 00 00 	mov    eax,DWORD PTR [esp+0x94]
  5321ff:	50                   	push   eax
  532200:	e8 07 f0 35 00       	call   0x89120c
  532205:	83 c4 04             	add    esp,0x4
  532208:	88 9c 24 e8 01 00 00 	mov    BYTE PTR [esp+0x1e8],bl
  53220f:	83 bc 24 c4 00 00 00 	cmp    DWORD PTR [esp+0xc4],0x10
  532216:	10 
  532217:	72 10                	jb     0x532229
  532219:	8b 8c 24 b0 00 00 00 	mov    ecx,DWORD PTR [esp+0xb0]
  532220:	51                   	push   ecx
  532221:	e8 e6 ef 35 00       	call   0x89120c
  532226:	83 c4 04             	add    esp,0x4
  532229:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  53222d:	bf 7c f1 c0 00       	mov    edi,0xc0f17c
  532232:	e8 89 c1 1f 00       	call   0x72e3c0
  532237:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  53223b:	3b c3                	cmp    eax,ebx
  53223d:	0f 85 bf fb ff ff    	jne    0x531e02
  532243:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  532247:	68 a4 f1 c0 00       	push   0xc0f1a4
  53224c:	e8 8f c0 1f 00       	call   0x72e2e0
  532251:	3b c3                	cmp    eax,ebx
  532253:	0f 84 f7 02 00 00    	je     0x532550
  532259:	bf 7c f1 c0 00       	mov    edi,0xc0f17c
  53225e:	e8 fd c0 1f 00       	call   0x72e360
  532263:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  532267:	3b c3                	cmp    eax,ebx
  532269:	0f 84 e1 02 00 00    	je     0x532550
  53226f:	90                   	nop
  532270:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  532274:	83 c7 44             	add    edi,0x44
  532277:	68 b0 f1 c0 00       	push   0xc0f1b0
  53227c:	e8 1f de 1f 00       	call   0x7300a0
  532281:	3b c3                	cmp    eax,ebx
  532283:	74 1e                	je     0x5322a3
  532285:	83 c0 30             	add    eax,0x30
  532288:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53228c:	72 02                	jb     0x532290
  53228e:	8b 00                	mov    eax,DWORD PTR [eax]
  532290:	3b c3                	cmp    eax,ebx
  532292:	74 0f                	je     0x5322a3
  532294:	50                   	push   eax
  532295:	e8 1a f5 35 00       	call   0x8917b4
  53229a:	83 c4 04             	add    esp,0x4
  53229d:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  5322a1:	eb 04                	jmp    0x5322a7
  5322a3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  5322a7:	68 b4 f1 c0 00       	push   0xc0f1b4
  5322ac:	e8 ef dd 1f 00       	call   0x7300a0
  5322b1:	3b c3                	cmp    eax,ebx
  5322b3:	74 1c                	je     0x5322d1
  5322b5:	83 c0 30             	add    eax,0x30
  5322b8:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5322bc:	72 02                	jb     0x5322c0
  5322be:	8b 00                	mov    eax,DWORD PTR [eax]
  5322c0:	3b c3                	cmp    eax,ebx
  5322c2:	74 0d                	je     0x5322d1
  5322c4:	50                   	push   eax
  5322c5:	e8 ea f4 35 00       	call   0x8917b4
  5322ca:	83 c4 04             	add    esp,0x4
  5322cd:	8b f0                	mov    esi,eax
  5322cf:	eb 02                	jmp    0x5322d3
  5322d1:	33 f6                	xor    esi,esi
  5322d3:	68 b8 f1 c0 00       	push   0xc0f1b8
  5322d8:	e8 c3 dd 1f 00       	call   0x7300a0
  5322dd:	3b c3                	cmp    eax,ebx
  5322df:	74 1e                	je     0x5322ff
  5322e1:	83 c0 30             	add    eax,0x30
  5322e4:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5322e8:	72 02                	jb     0x5322ec
  5322ea:	8b 00                	mov    eax,DWORD PTR [eax]
  5322ec:	3b c3                	cmp    eax,ebx
  5322ee:	74 0f                	je     0x5322ff
  5322f0:	50                   	push   eax
  5322f1:	e8 be f4 35 00       	call   0x8917b4
  5322f6:	83 c4 04             	add    esp,0x4
  5322f9:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5322fd:	eb 04                	jmp    0x532303
  5322ff:	89 5c 24 14          	mov    DWORD PTR [esp+0x14],ebx
  532303:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  532307:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53230b:	89 74 24 34          	mov    DWORD PTR [esp+0x34],esi
  53230f:	8d             	lea    edi,[esp+0x2c]
```

### `0x0072E2E0` .. `0x0072E390`

```asm
  72e2e0:	55                   	push   ebp
  72e2e1:	8b ec                	mov    ebp,esp
  72e2e3:	53                   	push   ebx
  72e2e4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  72e2e7:	56                   	push   esi
  72e2e8:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  72e2eb:	85 f6                	test   esi,esi
  72e2ed:	74 21                	je     0x72e310
  72e2ef:	90                   	nop
  72e2f0:	83 7e 34 10          	cmp    DWORD PTR [esi+0x34],0x10
  72e2f4:	8d 46 20             	lea    eax,[esi+0x20]
  72e2f7:	72 02                	jb     0x72e2fb
  72e2f9:	8b 00                	mov    eax,DWORD PTR [eax]
  72e2fb:	53                   	push   ebx
  72e2fc:	50                   	push   eax
  72e2fd:	e8 af 59 16 00       	call   0x893cb1
  72e302:	83 c4 08             	add    esp,0x8
  72e305:	85 c0                	test   eax,eax
  72e307:	74 0f                	je     0x72e318
  72e309:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  72e30c:	85 f6                	test   esi,esi
  72e30e:	75 e0                	jne    0x72e2f0
  72e310:	5e                   	pop    esi
  72e311:	33 c0                	xor    eax,eax
  72e313:	5b                   	pop    ebx
  72e314:	5d                   	pop    ebp
  72e315:	c2 04 00             	ret    0x4
  72e318:	8b c6                	mov    eax,esi
  72e31a:	5e                   	pop    esi
  72e31b:	5b                   	pop    ebx
  72e31c:	5d                   	pop    ebp
  72e31d:	c2 04 00             	ret    0x4
  72e320:	55                   	push   ebp
  72e321:	8b ec                	mov    ebp,esp
  72e323:	53                   	push   ebx
  72e324:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  72e327:	56                   	push   esi
  72e328:	8b 70 40             	mov    esi,DWORD PTR [eax+0x40]
  72e32b:	85 f6                	test   esi,esi
  72e32d:	74 21                	je     0x72e350
  72e32f:	90                   	nop
  72e330:	83 7e 34 10          	cmp    DWORD PTR [esi+0x34],0x10
  72e334:	8d 46 20             	lea    eax,[esi+0x20]
  72e337:	72 02                	jb     0x72e33b
  72e339:	8b 00                	mov    eax,DWORD PTR [eax]
  72e33b:	53                   	push   ebx
  72e33c:	50                   	push   eax
  72e33d:	e8 6f 59 16 00       	call   0x893cb1
  72e342:	83 c4 08             	add    esp,0x8
  72e345:	85 c0                	test   eax,eax
  72e347:	74 0f                	je     0x72e358
  72e349:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  72e34c:	85 f6                	test   esi,esi
  72e34e:	75 e0                	jne    0x72e330
  72e350:	5e                   	pop    esi
  72e351:	33 c0                	xor    eax,eax
  72e353:	5b                   	pop    ebx
  72e354:	5d                   	pop    ebp
  72e355:	c2 04 00             	ret    0x4
  72e358:	8b c6                	mov    eax,esi
  72e35a:	5e                   	pop    esi
  72e35b:	5b                   	pop    ebx
  72e35c:	5d                   	pop    ebp
  72e35d:	c2 04 00             	ret    0x4
  72e360:	53                   	push   ebx
  72e361:	56                   	push   esi
  72e362:	57                   	push   edi
  72e363:	e8 78 ff ff ff       	call   0x72e2e0
  72e368:	8b f0                	mov    esi,eax
  72e36a:	85 f6                	test   esi,esi
  72e36c:	74 38                	je     0x72e3a6
  72e36e:	bb 10 00 00 00       	mov    ebx,0x10
  72e373:	8b 06                	mov    eax,DWORD PTR [esi]
  72e375:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  72e378:	8b ce                	mov    ecx,esi
  72e37a:	ff d2                	call   edx
  72e37c:	85 c0                	test   eax,eax
  72e37e:	75 34                	jne    0x72e3b4
  72e380:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  72e383:	85 f6                	test   esi,esi
  72e385:	74 1f                	je     0x72e3a6
  72e387:	39 5e 34             	cmp    DWORD PTR [esi+0x34],ebx
  72e38a:	8d 46 20             	lea    eax,[esi+0x20]
  72e38d:	72 02                	jb     0x72e391
  72e38f:	8b                 	mov    eax,DWORD PTR [eax]
```

## 4. 局部控制流程與資料流（指令級）

以下為本段出現的直接 call 指令節錄；**callee 的高階名稱均不自動確定**：

```asm
  531e47:	e8 24 0c ed ff       	call   0x402a70
  531e68:	e8 83 ce 1f 00       	call   0x72ecf0
  531e7d:	e8 2e 0d ed ff       	call   0x402bb0
  531e92:	e8 75 f3 35 00       	call   0x89120c
  531ebf:	e8 48 f3 35 00       	call   0x89120c
  531ed5:	e8 c6 e1 1f 00       	call   0x7300a0
  531eee:	e8 c1 f8 35 00       	call   0x8917b4
  531f13:	e8 58 07 00 00       	call   0x532670
  531f1f:	e8 7c e1 1f 00       	call   0x7300a0
  531f38:	e8 77 f8 35 00       	call   0x8917b4
  531f50:	e8 4b e1 1f 00       	call   0x7300a0
  531f69:	e8 46 f8 35 00       	call   0x8917b4
  532200:	e8 07 f0 35 00       	call   0x89120c
  532221:	e8 e6 ef 35 00       	call   0x89120c
  532232:	e8 89 c1 1f 00       	call   0x72e3c0
  53224c:	e8 8f c0 1f 00       	call   0x72e2e0
  53225e:	e8 fd c0 1f 00       	call   0x72e360
  53227c:	e8 1f de 1f 00       	call   0x7300a0
  532295:	e8 1a f5 35 00       	call   0x8917b4
  5322ac:	e8 ef dd 1f 00       	call   0x7300a0
  5322c5:	e8 ea f4 35 00       	call   0x8917b4
  5322d8:	e8 c3 dd 1f 00       	call   0x7300a0
  5322f1:	e8 be f4 35 00       	call   0x8917b4
  72e2fd:	e8 af 59 16 00       	call   0x893cb1
  72e33d:	e8 6f 59 16 00       	call   0x893cb1
  72e363:	e8 78 ff ff ff       	call   0x72e2e0
  72e37a:	ff d2                	call   edx
```

比較、測試及分支位置（節錄）：

```asm
  531e87:	39 74 24 70          	cmp    DWORD PTR [esp+0x70],esi
  531e8b:	72 0d                	jb     0x531e9a
  531eae:	39 b4 24 a8 00 00 00 	cmp    DWORD PTR [esp+0xa8],esi
  531eb5:	72 10                	jb     0x531ec7
  531eda:	3b c3                	cmp    eax,ebx
  531edc:	74 1a                	je     0x531ef8
  531ee1:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  531ee5:	72 02                	jb     0x531ee9
  531ee9:	3b c3                	cmp    eax,ebx
  531eeb:	74 0b                	je     0x531ef8
  531ef6:	eb 02                	jmp    0x531efa
  531f24:	3b c3                	cmp    eax,ebx
  531f26:	74 1a                	je     0x531f42
  531f2b:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  531f2f:	72 02                	jb     0x531f33
  531f33:	3b c3                	cmp    eax,ebx
  531f35:	74 0b                	je     0x531f42
  531f40:	eb 02                	jmp    0x531f44
  531f55:	3b c3                	cmp    eax,ebx
  531f57:	74 1e                	je     0x531f77
  531f5c:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  531f60:	72 02                	jb     0x531f64
  531f64:	3b c3                	cmp    eax,ebx
  531f66:	74 0f                	je     0x531f77
  531f75:	eb 04                	jmp    0x531f7b
  531f7b:	39 5c 24 18          	cmp    DWORD PTR [esp+0x18],ebx
  531f7f:	0f 8c 83 02 00 00    	jl     0x532208
  531f85:	39 5c 24 14          	cmp    DWORD PTR [esp+0x14],ebx
  531f89:	0f 84 79 02 00 00    	je     0x532208
  5321e0:	a8 00                	test   al,0x0
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