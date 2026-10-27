# T10-56 — 鍵狀態 reader 與多型判定消費路徑

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

`0x59624E`、`0x59643F` 直接 `call 0x6D4CE0`；周邊 `virtual+0xEC/+0xF0` 的 receiver 實例仍待確認。該路徑可界定為鍵狀態消費者，不能直接解釋成玩家 attack action/cancel。

## 直接 E8 呼叫證據

`0x6D4CE0` E8 候選呼叫：0x59624e, 0x59643f。只計 direct opcode bytes，不證間接虛擬呼叫。

## 第一手 x86 反組譯摘錄

### VA `0x005961C0` ／ raw `0x001955C0`（260 bytes）

```asm
  5961c0:	55                   	push   ebp
  5961c1:	8b ec                	mov    ebp,esp
  5961c3:	6a ff                	push   0xffffffff
  5961c5:	68 ea ae 93 00       	push   0x93aeea
  5961ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5961d0:	50                   	push   eax
  5961d1:	83 ec 24             	sub    esp,0x24
  5961d4:	53                   	push   ebx
  5961d5:	56                   	push   esi
  5961d6:	57                   	push   edi
  5961d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5961dc:	33 c5                	xor    eax,ebp
  5961de:	50                   	push   eax
  5961df:	8d 45 f4             	lea    eax,[ebp-0xc]
  5961e2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5961e8:	8b d9                	mov    ebx,ecx
  5961ea:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  5961ed:	8b c3                	mov    eax,ebx
  5961ef:	e8 1c ae 1c 00       	call   0x761010
  5961f4:	33 ff                	xor    edi,edi
  5961f6:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  5961f9:	c6 45 f3 00          	mov    BYTE PTR [ebp-0xd],0x0
  5961fd:	3b c7                	cmp    eax,edi
  5961ff:	74 0e                	je     0x59620f
  596201:	8b 40 28             	mov    eax,DWORD PTR [eax+0x28]
  596204:	c1 e8 0d             	shr    eax,0xd
  596207:	a8 01                	test   al,0x1
  596209:	74 04                	je     0x59620f
  59620b:	c6 45 f3 01          	mov    BYTE PTR [ebp-0xd],0x1
  59620f:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  596216:	75 23                	jne    0x59623b
  596218:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  59621f:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  596222:	e8 49 9f fc ff       	call   0x560170
  596227:	68 10 d1 bc 00       	push   0xbcd110
  59622c:	e8 e9 c0 2f 00       	call   0x89231a
  596231:	83 c4 04             	add    esp,0x4
  596234:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  59623b:	39 3d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,edi
  596241:	0f 95 45 f1          	setne  BYTE PTR [ebp-0xf]
  596245:	8b f7                	mov    esi,edi
  596247:	c6 45 f2 00          	mov    BYTE PTR [ebp-0xe],0x0
  59624b:	89 7d dc             	mov    DWORD PTR [ebp-0x24],edi
  59624e:	e8 8d ea 13 00       	call   0x6d4ce0
  596253:	80 7d f1 00          	cmp    BYTE PTR [ebp-0xf],0x0
  596257:	74 0e                	je     0x596267
  596259:	83 ff 0d             	cmp    edi,0xd
  59625c:	74 09                	je     0x596267
  59625e:	83 ff 0e             	cmp    edi,0xe
  596261:	0f 85 1f 01 00 00    	jne    0x596386
  596267:	83 f8 01             	cmp    eax,0x1
  59626a:	75 50                	jne    0x5962bc
  59626c:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  59626f:	85 c9                	test   ecx,ecx
  596271:	74 11                	je     0x596284
  596273:	8b 11                	mov    edx,DWORD PTR [ecx]
  596275:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  59627b:	57                   	push   edi
  59627c:	ff d0                	call   eax
  59627e:	84 c0                	test   al,al
  596280:	b0 01                	mov    al,0x1
  596282:	75 03                	jne    0x596287
  596284:	8a 45 f2             	mov    al,BYTE PTR [ebp-0xe]
  596287:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  59628b:	0f 85 bc 00 00 00    	jne    0x59634d
  596291:	84 c0                	test   al,al
  596293:	0f 85 b8 00 00 00    	jne    0x596351
  596299:	6a 01                	push   0x1
  59629b:	8b c3                	mov    eax,ebx
  59629d:	e8 9e fe ff ff       	call   0x596140
  5962a2:	84 c0                	test   al,al
  5962a4:	0f 85 a7 00 00 00    	jne    0x596351
  5962aa:	8b 13                	mov    edx,DWORD PTR [ebx]
  5962ac:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  5962b2:	57                   	push   edi
  5962b3:	8b cb                	mov    ecx,ebx
  5962b5:	ff d0                	call   eax
  5962b7:	e9 91 00 00 00       	jmp    0x59634d
  5962bc:	83 f8 03             	cmp    eax,0x3
  5962bf:	0f                   	.byte 0xf
  5962c0:	85 c1                	test   ecx,eax
	...
```

### VA `0x00596390` ／ raw `0x00195790`（340 bytes）

```asm
  596390:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  596397:	bf 01 00 00 00       	mov    edi,0x1
  59639c:	75 22                	jne    0x5963c0
  59639e:	09 3d ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,edi
  5963a4:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5963a7:	e8 f4 b9 13 00       	call   0x6d1da0
  5963ac:	68 30 e3 bc 00       	push   0xbce330
  5963b1:	e8 64 bf 2f 00       	call   0x89231a
  5963b6:	83 c4 04             	add    esp,0x4
  5963b9:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5963c0:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  5963c7:	a1 24 f6 fd 00       	mov    eax,ds:0xfdf624
  5963cc:	8b 30                	mov    esi,DWORD PTR [eax]
  5963ce:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  5963d1:	75 26                	jne    0x5963f9
  5963d3:	09 3d ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,edi
  5963d9:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  5963e0:	e8 bb b9 13 00       	call   0x6d1da0
  5963e5:	68 30 e3 bc 00       	push   0xbce330
  5963ea:	e8 2b bf 2f 00       	call   0x89231a
  5963ef:	83 c4 04             	add    esp,0x4
  5963f2:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5963f9:	8b 0d 24 f6 fd 00    	mov    ecx,DWORD PTR ds:0xfdf624
  5963ff:	89 4d d0             	mov    DWORD PTR [ebp-0x30],ecx
  596402:	3b f1                	cmp    esi,ecx
  596404:	0f 84 ac 01 00 00    	je     0x5965b6
  59640a:	80 7d f1 00          	cmp    BYTE PTR [ebp-0xf],0x0
  59640e:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  596411:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  596414:	89 75 d4             	mov    DWORD PTR [ebp-0x2c],esi
  596417:	74 24                	je     0x59643d
  596419:	81 fe f9 2a 00 00    	cmp    esi,0x2af9
  59641f:	72 08                	jb     0x596429
  596421:	81 fe fa 2a 00 00    	cmp    esi,0x2afa
  596427:	76 14                	jbe    0x59643d
  596429:	8b 10                	mov    edx,DWORD PTR [eax]
  59642b:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  59642e:	e9 7a 01 00 00       	jmp    0x5965ad
  596433:	68 34 20 bf 00       	push   0xbf2034
  596438:	e8 f3 76 2e 00       	call   0x87db30
  59643d:	32 db                	xor    bl,bl
  59643f:	e8 9c e8 13 00       	call   0x6d4ce0
  596444:	83 f8 01             	cmp    eax,0x1
  596447:	0f 85 96 00 00 00    	jne    0x5964e3
  59644d:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  596450:	85 c9                	test   ecx,ecx
  596452:	74 11                	je     0x596465
  596454:	8b 01                	mov    eax,DWORD PTR [ecx]
  596456:	8b 90 ec 00 00 00    	mov    edx,DWORD PTR [eax+0xec]
  59645c:	56                   	push   esi
  59645d:	ff d2                	call   edx
  59645f:	84 c0                	test   al,al
  596461:	74 02                	je     0x596465
  596463:	b3 01                	mov    bl,0x1
  596465:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  596469:	0f 85 fd 00 00 00    	jne    0x59656c
  59646f:	84 db                	test   bl,bl
  596471:	0f 85 f9 00 00 00    	jne    0x596570
  596477:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  59647a:	8d 45 dc             	lea    eax,[ebp-0x24]
  59647d:	50                   	push   eax
  59647e:	8d 8f 80 00 00 00    	lea    ecx,[edi+0x80]
  596484:	8d 45 e0             	lea    eax,[ebp-0x20]
  596487:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  59648a:	e8 71 8a 29 00       	call   0x82ef00
  59648f:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  596492:	3b 87 84 00 00 00    	cmp    eax,DWORD PTR [edi+0x84]
  596498:	74 35                	je     0x5964cf
  59649a:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  59649d:	8b 59 04             	mov    ebx,DWORD PTR [ecx+0x4]
  5964a0:	8b 3b                	mov    edi,DWORD PTR [ebx]
  5964a2:	3b fb                	cmp    edi,ebx
  5964a4:	74 26                	je     0x5964cc
  5964a6:	eb 08                	jmp    0x5964b0
  5964a8:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5964af:	90                   	nop
  5964b0:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  5964b3:	8b 11                	mov    edx,DWORD PTR [ecx]
  5964b5:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  5964bb:	56                   	push   esi
  5964bc:	ff d0                	call   eax
  5964be:	84 c0                	test   al,al
  5964c0:	0f 85 aa 00 00 00    	jne    0x596570
  5964c6:	8b 3f                	mov    edi,DWORD PTR [edi]
  5964c8:	3b fb                	cmp    edi,ebx
  5964ca:	75 e4                	jne    0x5964b0
  5964cc:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  5964cf:	8b 17                	mov    edx,DWORD PTR [edi]
  5964d1:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  5964d7:	56                   	push   esi
  5964d8:	8b cf                	mov    ecx,edi
  5964da:	ff d0                	call   eax
  5964dc:	84 c0                	test   al,al
  5964de:	e9 8b 00 00 00       	jmp    0x59656e
  5964e3:	83                   	.byte 0x83
```

### VA `0x00596430` ／ raw `0x00195830`（195 bytes）

```asm
  596430:	01 00                	add    DWORD PTR [eax],eax
  596432:	00 68 34             	add    BYTE PTR [eax+0x34],ch
  596435:	20 bf 00 e8 f3 76    	and    BYTE PTR [edi+0x76f3e800],bh
  59643b:	2e 00 32             	add    BYTE PTR cs:[edx],dh
  59643e:	db e8                	fucomi st,st(0)
  596440:	9c                   	pushf
  596441:	e8 13 00 83 f8       	call   0xf8dc6459
  596446:	01 0f                	add    DWORD PTR [edi],ecx
  596448:	85 96 00 00 00 8b    	test   DWORD PTR [esi-0x75000000],edx
  59644e:	4d                   	dec    ebp
  59644f:	e4 85                	in     al,0x85
  596451:	c9                   	leave
  596452:	74 11                	je     0x596465
  596454:	8b 01                	mov    eax,DWORD PTR [ecx]
  596456:	8b 90 ec 00 00 00    	mov    edx,DWORD PTR [eax+0xec]
  59645c:	56                   	push   esi
  59645d:	ff d2                	call   edx
  59645f:	84 c0                	test   al,al
  596461:	74 02                	je     0x596465
  596463:	b3 01                	mov    bl,0x1
  596465:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  596469:	0f 85 fd 00 00 00    	jne    0x59656c
  59646f:	84 db                	test   bl,bl
  596471:	0f 85 f9 00 00 00    	jne    0x596570
  596477:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  59647a:	8d 45 dc             	lea    eax,[ebp-0x24]
  59647d:	50                   	push   eax
  59647e:	8d 8f 80 00 00 00    	lea    ecx,[edi+0x80]
  596484:	8d 45 e0             	lea    eax,[ebp-0x20]
  596487:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  59648a:	e8 71 8a 29 00       	call   0x82ef00
  59648f:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  596492:	3b 87 84 00 00 00    	cmp    eax,DWORD PTR [edi+0x84]
  596498:	74 35                	je     0x5964cf
  59649a:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  59649d:	8b 59 04             	mov    ebx,DWORD PTR [ecx+0x4]
  5964a0:	8b 3b                	mov    edi,DWORD PTR [ebx]
  5964a2:	3b fb                	cmp    edi,ebx
  5964a4:	74 26                	je     0x5964cc
  5964a6:	eb 08                	jmp    0x5964b0
  5964a8:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5964af:	90                   	nop
  5964b0:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  5964b3:	8b 11                	mov    edx,DWORD PTR [ecx]
  5964b5:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  5964bb:	56                   	push   esi
  5964bc:	ff d0                	call   eax
  5964be:	84 c0                	test   al,al
  5964c0:	0f 85 aa 00 00 00    	jne    0x596570
  5964c6:	8b 3f                	mov    edi,DWORD PTR [edi]
  5964c8:	3b fb                	cmp    edi,ebx
  5964ca:	75 e4                	jne    0x5964b0
  5964cc:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  5964cf:	8b 17                	mov    edx,DWORD PTR [edi]
  5964d1:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  5964d7:	56                   	push   esi
  5964d8:	8b cf                	mov    ecx,edi
  5964da:	ff d0                	call   eax
  5964dc:	84 c0                	test   al,al
  5964de:	e9 8b 00 00 00       	jmp    0x59656e
  5964e3:	83 f8 03             	cmp    eax,0x3
  5964e6:	0f 85 b6 00 00 00    	jne    0x5965a2
  5964ec:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  5964ef:	85 c9                	test   ecx,ecx
  5964f1:	74 11                	je     0x596504
```

## 已確認／部分確認／未證實

- **已確認（區域性）：** 本檔指定 VA 的可讀原始 byte 及列出的直接讀寫／call 指令；以相應位址及前置條件為限。
- **部分確認：** 這些路徑具備輸入資料結構或 controller 消費候選的關聯，確切 receiver／建構實例與完整 CFG 仍待核實。
- **未證實：** Z/X/C/V 自訂 action mapping、V 點按／長按真正的 timer/tier writer、連按 Z 和 held Z 自動續段、動畫完成 callback、普攻↔技能 queue/cancel、官方後端裁決。

## 與既有 T10-45～52／T01 整合的關係

此段為原始 BIN 的**限定驗證／擴充證據盤點**，不取代 T10-1～44 原稿或 T01-20261027-05 的有限語義接受範圍；同 offset 不能跨型別混用。使用者玩家觀察只是動機，非原生已證事實。

## 下一步可驗證路線

1. 向後追 key state 的 **非零 writer**：找不依賴絕對位址常數的 base+index store 或由 keyboard/DirectInput/window message 注入的 callback。
2. 驗證同一個 actor/controller receiver 的建構、指派、虛表及動作啟動 writer，再連接 motion completion 的 next-action queue。
3. 取得此版本的 KeyMapping.xml/fallback row 並比對 action id 與實際鍵狀態，不把 `VK_Z` 寫死。

## GitHub 提交界線

僅使用者授權的 `kr-temp-roy/` 新檔；不變更 owner、catalog、其他 Task 或原始執行檔。