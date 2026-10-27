# T16-39 — QuestTalk XML 載入及根節點命名空間／資料依賴

- 原始研究時間（Asia/Taipei）：20261028-023112
- Source: KR `Tartaros.bin`，唯讀靜態分析，bytes=`12472320`，SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- GitHub 起始基線：`0de4fe39719a83f38a003af8efeed6b5c9b20f90`（研究啟動時核對）
- 本段主題：QuestTalk XML 載入及根節點命名空間／資料依賴
- 界線：可確定的只有原生機器碼與本段直接解析之位址／跳躍；**不宣稱**任何原版任務 ID、NPC、完成條件、封包權威或 Lua/XML 實體內容。
- 研究方法：`objdump -D -Mintel -j .text` 依 VA 擷取原始 bytes；另外從 `.text` 扫描 `E8 rel32` 作交叉參照候選，僅經指令對齊與上下文核對後方可作控制流程證據。

## 1. 可重現基線與 PE 映射

| section | VA 起點 | file offset | 限制 |
|---|---|---|---|
| .text | `0x00401000` | `0x400` | 指令與常數候選 |
| .rdata | `0x00BD2000` | `0x007D0600` | 字串不是語義證據 |
| .data | `0x00D61000` | `0x0095E800` | static image ≠ runtime field value |

## 2. 研究範圍與函式邊界

本段截取下列 **位址視窗**，它們不必然等於完整函式；需以 prologue、返回路徑及多入口參照重新界定。總計 234 行反組譯輸出。

| start | stop (exclusive) | raw start | direct E8 candidates to start |
|---|---|---|---|
| `0x00505570` | `0x00505780` | `0x104970` | `0x005043EF` |
| `0x0072E2E0` | `0x0072E390` | `0x32D6E0` | `0x00407812`, `0x004079D5`, `0x004456C3`, `0x0044570D`, `0x0044587D`, `0x0044E9F9`, `0x0044EA0D`, `0x0046E5F4`, `0x004747E5`, `0x0047DF2B`, `0x00489A50`, `0x00489A9C` |

**注意：** raw `E8` 比對可能掃到指令中間；不得把表格所有候選自動計為真實 caller。`call [reg]`、vtable 呼叫亦不受 raw E8 掃描覆蓋。

## 3. Native assembly evidence

### `0x00505570` .. `0x00505780`

```asm
  505570:	55                   	push   ebp
  505571:	8b ec                	mov    ebp,esp
  505573:	83 e4 f8             	and    esp,0xfffffff8
  505576:	6a ff                	push   0xffffffff
  505578:	68 7b 28 92 00       	push   0x92287b
  50557d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  505583:	50                   	push   eax
  505584:	81 ec 98 00 00 00    	sub    esp,0x98
  50558a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50558f:	33 c4                	xor    eax,esp
  505591:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  505598:	53                   	push   ebx
  505599:	56                   	push   esi
  50559a:	57                   	push   edi
  50559b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5055a0:	33 c4                	xor    eax,esp
  5055a2:	50                   	push   eax
  5055a3:	8d 84 24 a8 00 00 00 	lea    eax,[esp+0xa8]
  5055aa:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5055b0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5055b3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055de:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  5055f2:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0xffffffff
  5055f9:	ff ff ff ff 
  5055fd:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505604:	00 
  505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50560c:	72 0d                	jb     0x50561b
  50560e:	8b 54 24 70          	mov    edx,DWORD PTR [esp+0x70]
  505612:	52                   	push   edx
  505613:	e8 f4 bb 38 00       	call   0x89120c
  505618:	83 c4 04             	add    esp,0x4
  50561b:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50561f:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505626:	0f 00 00 00 
  50562a:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  505631:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  505635:	e8 06 8a 22 00       	call   0x72e040
  50563a:	33 c0                	xor    eax,eax
  50563c:	e9 ec 01 00 00       	jmp    0x50582d
  505641:	68 44 dc c0 00       	push   0xc0dc44
  505646:	8d 44 24 28          	lea    eax,[esp+0x28]
  50564a:	e8 91 8c 22 00       	call   0x72e2e0
  50564f:	3b c3                	cmp    eax,ebx
  505651:	75 5c                	jne    0x5056af
  505653:	68 50 dc c0 00       	push   0xc0dc50
  505658:	e8 03 85 1e 00       	call   0x6edb60
  50565d:	c7 84 24 b4 00 00 00 	mov    DWORD PTR [esp+0xb4],0xffffffff
  505664:	ff ff ff ff 
  505668:	83 c4 04             	add    esp,0x4
  50566b:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505672:	00 
  505673:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50567a:	72 0d                	jb     0x505689
  50567c:	8b 44 24 70          	mov    eax,DWORD PTR [esp+0x70]
  505680:	50                   	push   eax
  505681:	e8 86 bb 38 00       	call   0x89120c
  505686:	83 c4 04             	add    esp,0x4
  505689:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50568d:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505694:	0f 00 00 00 
  505698:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  50569f:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  5056a3:	e8 98 89 22 00       	call   0x72e040
  5056a8:	33 c0                	xor    eax,eax
  5056aa:	e9 7e 01 00 00       	jmp    0x50582d
  5056af:	e8 7c 13 00 00       	call   0x506a30
  5056b4:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5056b8:	3b c3                	cmp    eax,ebx
  5056ba:	0f 84 20 01 00 00    	je     0x5057e0
  5056c0:	eb 04                	jmp    0x5056c6
  5056c2:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5056c6:	8d 78 44             	lea    edi,[eax+0x44]
  5056c9:	68 d0 d1 be 00       	push   0xbed1d0
  5056ce:	e8 cd a9 22 00       	call   0x7300a0
  5056d3:	3b c3                	cmp    eax,ebx
  5056d5:	74 1a                	je     0x5056f1
  5056d7:	83 c0 30             	add    eax,0x30
  5056da:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5056de:	72 02                	jb     0x5056e2
  5056e0:	8b 00                	mov    eax,DWORD PTR [eax]
  5056e2:	3b c3                	cmp    eax,ebx
  5056e4:	74 0b                	je     0x5056f1
  5056e6:	50                   	push   eax
  5056e7:	e8 c8 c0 38 00       	call   0x8917b4
  5056ec:	83 c4 04             	add    esp,0x4
  5056ef:	eb 02                	jmp    0x5056f3
  5056f1:	33 c0                	xor    eax,eax
  5056f3:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5056f7:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  5056fb:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  5056ff:	51                   	push   ecx
  505700:	8d 44 24 20          	lea    eax,[esp+0x20]
  505704:	8b ce                	mov    ecx,esi
  505706:	e8 15 e6 ff ff       	call   0x503d20
  50570b:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  50570f:	3b 4e 04             	cmp    ecx,DWORD PTR [esi+0x4]
  505712:	0f 84 92 00 00 00    	je     0x5057aa
  505718:	8d 71 10             	lea    esi,[ecx+0x10]
  50571b:	3b f3                	cmp    esi,ebx
  50571d:	0f 84 87 00 00 00    	je     0x5057aa
  505723:	68 68 dc c0 00       	push   0xc0dc68
  505728:	e8 73 a9 22 00       	call   0x7300a0
  50572d:	3b c3                	cmp    eax,ebx
  50572f:	74 1a                	je     0x50574b
  505731:	83 c0 30             	add    eax,0x30
  505734:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  505738:	72 02                	jb     0x50573c
  50573a:	8b 00                	mov    eax,DWORD PTR [eax]
  50573c:	3b c3                	cmp    eax,ebx
  50573e:	74 0b                	je     0x50574b
  505740:	50                   	push   eax
  505741:	e8 6e c0 38 00       	call   0x8917b4
  505746:	83 c4 04             	add    esp,0x4
  505749:	eb 02                	jmp    0x50574d
  50574b:	33 c0                	xor    eax,eax
  50574d:	68 74 dc c0 00       	push   0xc0dc74
  505752:	89 46 30             	mov    DWORD PTR [esi+0x30],eax
  505755:	e8 46 a9 22 00       	call   0x7300a0
  50575a:	3b c3                	cmp    eax,ebx
  50575c:	74 1a                	je     0x505778
  50575e:	83 c0 30             	add    eax,0x30
  505761:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  505765:	72 02                	jb     0x505769
  505767:	8b 00                	mov    eax,DWORD PTR [eax]
  505769:	3b c3                	cmp    eax,ebx
  50576b:	74 0b                	je     0x505778
  50576d:	50                   	push   eax
  50576e:	e8 41 c0 38 00       	call   0x8917b4
  505773:	83 c4 04             	add    esp,0x4
  505776:	eb 02                	jmp    0x50577a
  505778:	33 c0                	xor    eax,eax
  50577a:	68 80 dc c0 00       	push   0xc0dc80
  50577f:	89               	mov    DWORD PTR [esi+0x34],eax
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
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  505613:	e8 f4 bb 38 00       	call   0x89120c
  505635:	e8 06 8a 22 00       	call   0x72e040
  50564a:	e8 91 8c 22 00       	call   0x72e2e0
  505658:	e8 03 85 1e 00       	call   0x6edb60
  505681:	e8 86 bb 38 00       	call   0x89120c
  5056a3:	e8 98 89 22 00       	call   0x72e040
  5056af:	e8 7c 13 00 00       	call   0x506a30
  5056ce:	e8 cd a9 22 00       	call   0x7300a0
  5056e7:	e8 c8 c0 38 00       	call   0x8917b4
  505706:	e8 15 e6 ff ff       	call   0x503d20
  505728:	e8 73 a9 22 00       	call   0x7300a0
  505741:	e8 6e c0 38 00       	call   0x8917b4
  505755:	e8 46 a9 22 00       	call   0x7300a0
  50576e:	e8 41 c0 38 00       	call   0x8917b4
  72e2fd:	e8 af 59 16 00       	call   0x893cb1
  72e33d:	e8 6f 59 16 00       	call   0x893cb1
  72e363:	e8 78 ff ff ff       	call   0x72e2e0
  72e37a:	ff d2                	call   edx
```

比較、測試及分支位置（節錄）：

```asm
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50560c:	72 0d                	jb     0x50561b
  50563c:	e9 ec 01 00 00       	jmp    0x50582d
  50564f:	3b c3                	cmp    eax,ebx
  505651:	75 5c                	jne    0x5056af
  505673:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50567a:	72 0d                	jb     0x505689
  5056aa:	e9 7e 01 00 00       	jmp    0x50582d
  5056b8:	3b c3                	cmp    eax,ebx
  5056ba:	0f 84 20 01 00 00    	je     0x5057e0
  5056c0:	eb 04                	jmp    0x5056c6
  5056d3:	3b c3                	cmp    eax,ebx
  5056d5:	74 1a                	je     0x5056f1
  5056da:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5056de:	72 02                	jb     0x5056e2
  5056e2:	3b c3                	cmp    eax,ebx
  5056e4:	74 0b                	je     0x5056f1
  5056ef:	eb 02                	jmp    0x5056f3
  50570f:	3b 4e 04             	cmp    ecx,DWORD PTR [esi+0x4]
  505712:	0f 84 92 00 00 00    	je     0x5057aa
  50571b:	3b f3                	cmp    esi,ebx
  50571d:	0f 84 87 00 00 00    	je     0x5057aa
  50572d:	3b c3                	cmp    eax,ebx
  50572f:	74 1a                	je     0x50574b
  505734:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  505738:	72 02                	jb     0x50573c
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