# T10-43 — 玩家控制器 input producer → bitmask → actor +0x3E8 允許分支（BIN-first 大型研究）

- 分析時間：2026-10-27T22:48:03.751986+08:00
- 來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際核對）
- `.text` 以 PE32 i386 objdump Intel 反組譯；入口對齊已知函式，局部分支首地址僅當分支落點，跨結尾需以上游完整指令校驗。
- GitHub 主責目錄：`kr-temp-roy/T10/`；不執行原程式，不修改主程式與其他 Task。

## 深度分析結果與可驗證結論
- 【已確認】`0x546262` 將 actor 指標 `edi` 傳給 `0x546780`；返回時它先處理 `WORD [ebx+2]` 的 bitmask 組合（`xor` 加遮罩 `0x7FFF`）。
- 【已確認】僅在額外模式與非零低 16-bit 條件通過後，`0x5462B4` 取 actor `+0x3E8`，搭配 `[esi+0x2]` 決定 byte 選擇，送入 `0x54F270`。predicate 非零將 local `[esp+0x17]` 設成 1；predicate 零但 actor+0x3E8 非零時亦設成 1；兩者皆不成立時將 `WORD[ebx+2] &= 0x8000`。
- 【已確認】`0x546338` 比較全域 `[0xFB9009]` 是否為零；此值在後段方向／空間分支使用，並沒有在該點直接呼叫 actor+0x3E8 的 setter。
- 【尚未驗證】Z held/autochain 和按鍵 action row 的索引映射；不能把 bitmask `0x8000` 解為普攻取消位元。

## 呼叫與欄位證據
`0x546780 → [ebx+2] → 0x54F270`、`[edi+0x3E8]` 共同 gate。函式中另有靜態 flag `0xFB9009`，目前未能證明其 physical key binding。

## 技術邊界／反證
- 各段的「已確認」僅表示所列機器碼直接支持的條件或資料搬移；任何玩家 V/Z/X/C 行為都仍屬待交叉驗證。
- `+0x3E8` 要先證實 base type 相同，不能從偏移相同認為同一欄位；既有 T10-33～40 只當背景，新增結論以此段反組譯為準。
- 無法從單一 BIN 推斷伺服器權威取消窗口、技能消耗與時鐘單位；不採用本地 AI 實作的時間常數。

## 下一步可核對路徑
1. 追 `0xFAB130` 樹的讀取方（key-to-instance lookup），比對 `0x546100` 實際 controller 物件分配與寫入者。
2. 查 `0xFB9004+index` 的非零狀態 writer，以及 `KeyMapping.xml` 的 row 到 action flags 映射。
3. 由 controller 返回輸入結果的 consumer 追動作 queue/motion callback，而不是在 `0x54F270` 停止。

## 原始反組譯摘錄（各區間含上下游）

### VA 0x546230–0x546310
```asm
00546230 <.text+0x145230>:
  546230:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  546236:	85 c0                	test   eax,eax
  546238:	74 03                	je     0x54623d
  54623a:	8b 70 2c             	mov    esi,DWORD PTR [eax+0x2c]
  54623d:	8b cf                	mov    ecx,edi
  54623f:	e8 8c 3c f8 ff       	call   0x4c9ed0
  546244:	85 f6                	test   esi,esi
  546246:	0f 84 ba 00 00 00    	je     0x546306
  54624c:	85 c0                	test   eax,eax
  54624e:	0f 85 b2 00 00 00    	jne    0x546306
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
  546306:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  54630d:	75 29                	jne    0x546338
  54630f:	b8                   	.byte 0xb8
```

### VA 0x546338–0x546375
```asm
00546338 <.text+0x145338>:
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
  546374:	8a                   	.byte 0x8a
```

### VA 0x54f270–0x54f2d2
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
```