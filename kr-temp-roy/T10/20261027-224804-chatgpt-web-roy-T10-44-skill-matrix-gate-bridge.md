# T10-44 — 玩家 input bitmask 至技能 matrix predicate 與動作輸出的證據界線（BIN-first 大型研究）

- 分析時間：2026-10-27T22:48:03.772321+08:00
- 來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際核對）
- `.text` 以 PE32 i386 objdump Intel 反組譯；入口對齊已知函式，局部分支首地址僅當分支落點，跨結尾需以上游完整指令校驗。
- GitHub 主責目錄：`kr-temp-roy/T10/`；不執行原程式，不修改主程式與其他 Task。

## 深度分析結果與可驗證結論
- 【已確認】`0x54F270` 依優先順序將輸入 flags `0x03/0x05/0x06/0x01/0x02/0x04/0x08/0x10` 映射至 key 4/5/6/1/2/3/7/10；flags 含 `0xC0` 直接 early allow。
- 【已確認】矩陣取值依序用 `0x40F7F0`、`0x819220`、`0x81A8E0`；得到 nonzero skill ID 後，經 `0x54F4E0` 查狀態記錄，再用其 `+4==0` 判斷。**這仍是可用性 predicate，不是技能施放指令**。
- 【已確認】`0x546100` 當 `0x54F270` 返回 0 但 actor +0x3E8 非零，仍保留局部允許旗標；因此僅從「predicate false」不能推論當次動作被完全禁止。
- 【未閉環】缺少從 controller 输出到 animation start/complete/next-action queue/cancel 的精確回呼，亦未證實 V 點按長按設置哪個 tier。此段對 T11 僅引用矩陣／消耗界線，不修改 T11 owner。

## 呼叫與欄位證據
`0x5462DD → 0x54F270 → 0x819220/0x81A8E0/0x54F4E0` 是已確認的 gating 分層；動作施放指令或冷卻 writer 不在此證據鏈。

## 技術邊界／反證
- 各段的「已確認」僅表示所列機器碼直接支持的條件或資料搬移；任何玩家 V/Z/X/C 行為都仍屬待交叉驗證。
- `+0x3E8` 要先證實 base type 相同，不能從偏移相同認為同一欄位；既有 T10-33～40 只當背景，新增結論以此段反組譯為準。
- 無法從單一 BIN 推斷伺服器權威取消窗口、技能消耗與時鐘單位；不採用本地 AI 實作的時間常數。

## 下一步可核對路徑
1. 追 `0xFAB130` 樹的讀取方（key-to-instance lookup），比對 `0x546100` 實際 controller 物件分配與寫入者。
2. 查 `0xFB9004+index` 的非零狀態 writer，以及 `KeyMapping.xml` 的 row 到 action flags 映射。
3. 由 controller 返回輸入結果的 consumer 追動作 queue/motion callback，而不是在 `0x54F270` 停止。

## 原始反組譯摘錄（各區間含上下游）

### VA 0x546254–0x546309
```asm
00546254 <.text+0x145254>:
  546254:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  546258:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  54625c:	51                   	push   ecx
  54625d:	8d 54 24 20          	lea    edx,[esp+0x20]
  546261:	52                   	push   edx
  546262:	57                   	push   edi
  546263:	e8 18 05 00 00       	call   0x546780
  546268:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  54626c:	e8 ef e6 ef ff       	call   0x444960
  546271:	80 b8 ef 07 00 00 01 	cmp    BYTE PTR [eax+0x7ef],0x1
  546278:	75 0c                	jne    0x546286
  54627a:	b8 00 01 00 00       	mov    eax,0x100
  54627f:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  546284:	eb 09                	jmp    0x54628f
  546286:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  54628a:	66 85 c0             	test   ax,ax
  54628d:	74 13                	je     0x5462a2
  54628f:	66 8b 4b 02          	mov    cx,WORD PTR [ebx+0x2]
  546293:	66 33 c8             	xor    cx,ax
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
  546306:	f6                   	.byte 0xf6
  546307:	05                   	.byte 0x5
  546308:	14                   	.byte 0x14
```

### VA 0x54f270–0x54f330
```asm
0054f270 <.text+0x14e270>:
  54f270:	55                   	push   ebp
  54f271:	8b ec                	mov    ebp,esp
  54f273:	53                   	push   ebx
  54f274:	56                   	push   esi
  54f275:	8b f1                	mov    esi,ecx
  54f277:	a8 c0                	test   al,0xc0
  54f279:	0f 85 a6 00 00 00    	jne    0x54f325
  54f27f:	8b c8                	mov    ecx,eax
  54f281:	83 e1 01             	and    ecx,0x1
  54f284:	74 08                	je     0x54f28e
  54f286:	a8 02                	test   al,0x2
  54f288:	74 04                	je     0x54f28e
  54f28a:	b3 04                	mov    bl,0x4
  54f28c:	eb 44                	jmp    0x54f2d2
  54f28e:	66 85 c9             	test   cx,cx
  54f291:	74 08                	je     0x54f29b
  54f293:	a8 04                	test   al,0x4
  54f295:	74 04                	je     0x54f29b
  54f297:	b3 05                	mov    bl,0x5
  54f299:	eb 37                	jmp    0x54f2d2
  54f29b:	8b d0                	mov    edx,eax
  54f29d:	83 e2 02             	and    edx,0x2
  54f2a0:	74 08                	je     0x54f2aa
  54f2a2:	a8 04                	test   al,0x4
  54f2a4:	74 04                	je     0x54f2aa
  54f2a6:	b3 06                	mov    bl,0x6
  54f2a8:	eb 28                	jmp    0x54f2d2
  54f2aa:	66 85 c9             	test   cx,cx
  54f2ad:	74 04                	je     0x54f2b3
  54f2af:	b3 01                	mov    bl,0x1
  54f2b1:	eb 1f                	jmp    0x54f2d2
  54f2b3:	66 85 d2             	test   dx,dx
  54f2b6:	74 04                	je     0x54f2bc
  54f2b8:	b3 02                	mov    bl,0x2
  54f2ba:	eb 16                	jmp    0x54f2d2
  54f2bc:	a8 04                	test   al,0x4
  54f2be:	74 04                	je     0x54f2c4
  54f2c0:	b3 03                	mov    bl,0x3
  54f2c2:	eb 0e                	jmp    0x54f2d2
  54f2c4:	a8 08                	test   al,0x8
  54f2c6:	74 04                	je     0x54f2cc
  54f2c8:	b3 07                	mov    bl,0x7
  54f2ca:	eb 06                	jmp    0x54f2d2
  54f2cc:	a8 10                	test   al,0x10
  54f2ce:	74 55                	je     0x54f325
  54f2d0:	b3 0a                	mov    bl,0xa
  54f2d2:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  54f2d5:	0f b7 4e 02          	movzx  ecx,WORD PTR [esi+0x2]
  54f2d9:	50                   	push   eax
  54f2da:	51                   	push   ecx
  54f2db:	e8 10 05 ec ff       	call   0x40f7f0
  54f2e0:	e8 3b 9f 2c 00       	call   0x819220
  54f2e5:	85 c0                	test   eax,eax
  54f2e7:	75 08                	jne    0x54f2f1
  54f2e9:	33 c0                	xor    eax,eax
  54f2eb:	5e                   	pop    esi
  54f2ec:	5b                   	pop    ebx
  54f2ed:	5d                   	pop    ebp
  54f2ee:	c2 08 00             	ret    0x8
  54f2f1:	50                   	push   eax
  54f2f2:	8a 45 0c             	mov    al,BYTE PTR [ebp+0xc]
  54f2f5:	8a cb                	mov    cl,bl
  54f2f7:	e8 e4 b5 2c 00       	call   0x81a8e0
  54f2fc:	0f b7 c0             	movzx  eax,ax
  54f2ff:	66 85 c0             	test   ax,ax
  54f302:	74 e5                	je     0x54f2e9
  54f304:	8b d0                	mov    edx,eax
  54f306:	83 c6 04             	add    esi,0x4
  54f309:	56                   	push   esi
  54f30a:	8d 45 08             	lea    eax,[ebp+0x8]
  54f30d:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  54f310:	e8 cb 01 00 00       	call   0x54f4e0
  54f315:	33 c9                	xor    ecx,ecx
  54f317:	39 48 04             	cmp    DWORD PTR [eax+0x4],ecx
  54f31a:	0f 94 c1             	sete   cl
  54f31d:	8b c1                	mov    eax,ecx
  54f31f:	5e                   	pop    esi
  54f320:	5b                   	pop    ebx
  54f321:	5d                   	pop    ebp
  54f322:	c2 08 00             	ret    0x8
  54f325:	5e                   	pop    esi
  54f326:	b8 01 00 00 00       	mov    eax,0x1
  54f32b:	5b                   	pop    ebx
  54f32c:	5d                   	pop    ebp
  54f32d:	c2 08 00             	ret    0x8
```

### VA 0x4aebfc–0x4aec18
```asm
004aebfc <.text+0xadbfc>:
  4aebfc:	68 30 b1 fa 00       	push   0xfab130
  4aec01:	8b c6                	mov    eax,esi
  4aec03:	e8 28 13 03 00       	call   0x4dff30
  4aec08:	83 7b 0e 00          	cmp    DWORD PTR [ebx+0xe],0x0
  4aec0c:	0f 84 86 00 00 00    	je     0x4aec98
  4aec12:	f6                   	.byte 0xf6
  4aec13:	05 2c b2 fa 00       	add    eax,0xfab22c
```