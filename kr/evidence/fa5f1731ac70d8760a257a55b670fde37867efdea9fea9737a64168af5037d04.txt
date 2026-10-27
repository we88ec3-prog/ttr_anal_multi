# KR T10-18 — 5961C0 正常鍵與擴展鍵的事件分派

日期：2026-10-27 Asia/Taipei。原始 BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。檔案大小：12,472,320 bytes。PE .text VA 0x401000, file raw 0x400。x86 objdump Intel 模式、原檔唯讀；下列較長節錄從明確指令入口或已知對齊位置取得。

## 本段技術結論

596140..5961B9 為獨立攔截 helper，5961C0 為下一函式 prologue。5961C0 遍歷一般鍵索引 0..39，透過 6D4CE0 取 phase；phase 1 走 vtable+EC，phase 3 走 vtable+F0，其間結合由 761010 返回物件的旗標、FB73E8 gate，以及 596140 的 keyed-tree 攔截結果。0xD/0xE 存在特殊條件。596390 後另遍歷 0xFDF624 管理的擴展鍵資料，不是普通鍵的純連續追加。未確認 phase 1/3 是 keydown/keyup，也未確認 5961C0 的間接/vtable 主呼叫者。

## 原始反組譯節錄（擴充留存；按 CFG 辨識指令界線）

### 片段起點 0x596140

```asm
  596140:	55                   	push   ebp
  596141:	8b ec                	mov    ebp,esp
  596143:	83 ec 08             	sub    esp,0x8
  596146:	53                   	push   ebx
  596147:	56                   	push   esi
  596148:	8b f0                	mov    esi,eax
  59614a:	8d 45 fc             	lea    eax,[ebp-0x4]
  59614d:	50                   	push   eax
  59614e:	8d 8e 80 00 00 00    	lea    ecx,[esi+0x80]
  596154:	8d 45 f8             	lea    eax,[ebp-0x8]
  596157:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  59615a:	e8 a1 8d 29 00       	call   0x82ef00
  59615f:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  596162:	3b 86 84 00 00 00    	cmp    eax,DWORD PTR [esi+0x84]
  596168:	74 3e                	je     0x5961a8
  59616a:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  59616d:	8b 59 04             	mov    ebx,DWORD PTR [ecx+0x4]
  596170:	8b 33                	mov    esi,DWORD PTR [ebx]
  596172:	3b f3                	cmp    esi,ebx
  596174:	74 32                	je     0x5961a8
  596176:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  596179:	83 f8 01             	cmp    eax,0x1
  59617c:	75 0d                	jne    0x59618b
  59617e:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  596181:	8b 11                	mov    edx,DWORD PTR [ecx]
  596183:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  596189:	eb 10                	jmp    0x59619b
  59618b:	83 f8 03             	cmp    eax,0x3
  59618e:	75 12                	jne    0x5961a2
  596190:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  596193:	8b 11                	mov    edx,DWORD PTR [ecx]
  596195:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  59619b:	57                   	push   edi
  59619c:	ff d0                	call   eax
  59619e:	84 c0                	test   al,al
  5961a0:	75 10                	jne    0x5961b2
  5961a2:	8b 36                	mov    esi,DWORD PTR [esi]
  5961a4:	3b f3                	cmp    esi,ebx
  5961a6:	75 ce                	jne    0x596176
  5961a8:	5e                   	pop    esi
  5961a9:	32 c0                	xor    al,al
  5961ab:	5b                   	pop    ebx
  5961ac:	8b e5                	mov    esp,ebp
  5961ae:	5d                   	pop    ebp
  5961af:	c2 04 00             	ret    0x4
  5961b2:	5e                   	pop    esi
  5961b3:	b0 01                	mov    al,0x1
  5961b5:	5b                   	pop    ebx
  5961b6:	8b e5                	mov    esp,ebp
  5961b8:	5d                   	pop    ebp
  5961b9:	c2 04 00             	ret    0x4
  5961bc:	cc                   	int3
  5961bd:	cc                   	int3
  5961be:	cc                   	int3
  5961bf:	cc                   	int3
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
  5962bf:	0f 85 c1 00 00 00    	jne    0x596386
  5962c5:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  5962c8:	85 c9                	test   ecx,ecx
  5962ca:	74 13                	je     0x5962df
  5962cc:	8b 11                	mov    edx,DWORD PTR [ecx]
  5962ce:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  5962d4:	57                   	push   edi
  5962d5:	ff d0                	call   eax
  5962d7:	84 c0                	test   al,al
  5962d9:	74 04                	je     0x5962df
  5962db:	c6 45 f2 01          	mov    BYTE PTR [ebp-0xe],0x1
  5962df:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  5962e3:	75 65                	jne    0x59634a
  5962e5:	80 7d f2 00          	cmp    BYTE PTR [ebp-0xe],0x0
  5962e9:	75 66                	jne    0x596351
  5962eb:	8d 4d e8             	lea    ecx,[ebp-0x18]
  5962ee:	51                   	push   ecx
  5962ef:	8d 8b 80 00 00 00    	lea    ecx,[ebx+0x80]
  5962f5:	8d 45 e0             	lea    eax,[ebp-0x20]
  5962f8:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  5962fb:	e8 00 8c 29 00       	call   0x82ef00
  596300:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  596303:	3b 83 84 00 00 00    	cmp    eax,DWORD PTR [ebx+0x84]
  596309:	74 30                	je     0x59633b
  59630b:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  59630e:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  596311:	8b 31                	mov    esi,DWORD PTR [ecx]
  596313:	8b d9                	mov    ebx,ecx
  596315:	3b f3                	cmp    esi,ebx
  596317:	74 1f                	je     0x596338
  596319:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  596320:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  596323:	8b 11                	mov    edx,DWORD PTR [ecx]
  596325:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  59632b:	57                   	push   edi
  59632c:	ff d0                	call   eax
  59632e:	84 c0                	test   al,al
  596330:	75 1f                	jne    0x596351
  596332:	8b 36                	mov    esi,DWORD PTR [esi]
  596334:	3b f3                	cmp    esi,ebx
  596336:	75 e8                	jne    0x596320
  596338:	8b 5d ec             	mov    ebx,DWORD PTR [ebp-0x14]
  59633b:	8b 13                	mov    edx,DWORD PTR [ebx]
  59633d:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  596343:	57                   	push   edi
  596344:	8b cb                	mov    ecx,ebx
  596346:	ff d0                	call   eax
  596348:	eb 03                	jmp    0x59634d
  59634a:	8a 45 f2             	mov    al,BYTE PTR [ebp-0xe]
  59634d:	84 c0                	test   al,al
  59634f:	74 35                	je     0x596386
  596351:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  596354:	8b 33                	mov    esi,DWORD PTR [ebx]
  596356:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  596359:	8d 4d dc             	lea    ecx,[ebp-0x24]
  59635c:	51                   	push   ecx
  59635d:	52                   	push   edx
  59635e:	56                   	push   esi
  59635f:	e8 9c 73 1b 00       	call   0x74d700
  596364:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  596367:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  59636c:	2b d1                	sub    edx,ecx
  59636e:	83 fa 01             	cmp    edx,0x1
  596371:	0f 82 bc 00 00 00    	jb     0x596433
  596377:	41                   	inc    ecx
  596378:	89 4b 04             	mov    DWORD PTR [ebx+0x4],ecx
  59637b:	8b 5d ec             	mov    ebx,DWORD PTR [ebp-0x14]
  59637e:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  596381:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  596384:	89 01                	mov    DWORD PTR [ecx],eax
  596386:	47                   	inc    edi
  596387:	83 ff 28             	cmp    edi,0x28
  59638a:	0f 8c b5 fe ff ff    	jl     0x596245
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
  5963c7:	a1                   	.byte 0xa1
  5963c8:	24 f6                	and    al,0xf6
```

### 片段起點 0x596330

```asm
  596330:	75 1f                	jne    0x596351
  596332:	8b 36                	mov    esi,DWORD PTR [esi]
  596334:	3b f3                	cmp    esi,ebx
  596336:	75 e8                	jne    0x596320
  596338:	8b 5d ec             	mov    ebx,DWORD PTR [ebp-0x14]
  59633b:	8b 13                	mov    edx,DWORD PTR [ebx]
  59633d:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  596343:	57                   	push   edi
  596344:	8b cb                	mov    ecx,ebx
  596346:	ff d0                	call   eax
  596348:	eb 03                	jmp    0x59634d
  59634a:	8a 45 f2             	mov    al,BYTE PTR [ebp-0xe]
  59634d:	84 c0                	test   al,al
  59634f:	74 35                	je     0x596386
  596351:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  596354:	8b 33                	mov    esi,DWORD PTR [ebx]
  596356:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  596359:	8d 4d dc             	lea    ecx,[ebp-0x24]
  59635c:	51                   	push   ecx
  59635d:	52                   	push   edx
  59635e:	56                   	push   esi
  59635f:	e8 9c 73 1b 00       	call   0x74d700
  596364:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  596367:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  59636c:	2b d1                	sub    edx,ecx
  59636e:	83 fa 01             	cmp    edx,0x1
  596371:	0f 82 bc 00 00 00    	jb     0x596433
  596377:	41                   	inc    ecx
  596378:	89 4b 04             	mov    DWORD PTR [ebx+0x4],ecx
  59637b:	8b 5d ec             	mov    ebx,DWORD PTR [ebp-0x14]
  59637e:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  596381:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  596384:	89 01                	mov    DWORD PTR [ecx],eax
  596386:	47                   	inc    edi
  596387:	83 ff 28             	cmp    edi,0x28
  59638a:	0f 8c b5 fe ff ff    	jl     0x596245
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
  5964e3:	83 f8 03             	cmp    eax,0x3
  5964e6:	0f                   	.byte 0xf
  5964e7:	85                   	.byte 0x85
```

### 片段起點 0x5964C0

```asm
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
  5964f3:	8b 11                	mov    edx,DWORD PTR [ecx]
  5964f5:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  5964fb:	56                   	push   esi
  5964fc:	ff d0                	call   eax
  5964fe:	84 c0                	test   al,al
  596500:	74 02                	je     0x596504
  596502:	b3 01                	mov    bl,0x1
  596504:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  596508:	75 62                	jne    0x59656c
  59650a:	84 db                	test   bl,bl
  59650c:	75 62                	jne    0x596570
  59650e:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  596511:	8d 4d dc             	lea    ecx,[ebp-0x24]
  596514:	51                   	push   ecx
  596515:	8d 8f 80 00 00 00    	lea    ecx,[edi+0x80]
  59651b:	8d 45 d8             	lea    eax,[ebp-0x28]
  59651e:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  596521:	e8 da 89 29 00       	call   0x82ef00
  596526:	8b 45 d8             	mov    eax,DWORD PTR [ebp-0x28]
  596529:	3b 87 84 00 00 00    	cmp    eax,DWORD PTR [edi+0x84]
  59652f:	74 2a                	je     0x59655b
  596531:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  596534:	8b 5a 04             	mov    ebx,DWORD PTR [edx+0x4]
  596537:	8b 3b                	mov    edi,DWORD PTR [ebx]
  596539:	3b fb                	cmp    edi,ebx
  59653b:	74 1b                	je     0x596558
  59653d:	8d 49 00             	lea    ecx,[ecx+0x0]
  596540:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  596543:	8b 01                	mov    eax,DWORD PTR [ecx]
  596545:	8b 90 f0 00 00 00    	mov    edx,DWORD PTR [eax+0xf0]
  59654b:	56                   	push   esi
  59654c:	ff d2                	call   edx
  59654e:	84 c0                	test   al,al
  596550:	75 1e                	jne    0x596570
  596552:	8b 3f                	mov    edi,DWORD PTR [edi]
  596554:	3b fb                	cmp    edi,ebx
  596556:	75 e8                	jne    0x596540
  596558:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  59655b:	8b 07                	mov    eax,DWORD PTR [edi]
  59655d:	8b 90 f0 00 00 00    	mov    edx,DWORD PTR [eax+0xf0]
  596563:	56                   	push   esi
  596564:	8b cf                	mov    ecx,edi
  596566:	ff d2                	call   edx
  596568:	84 c0                	test   al,al
  59656a:	eb 02                	jmp    0x59656e
  59656c:	84 db                	test   bl,bl
  59656e:	74 32                	je     0x5965a2
  596570:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  596573:	8b 37                	mov    esi,DWORD PTR [edi]
  596575:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  596578:	8d 45 d4             	lea    eax,[ebp-0x2c]
  59657b:	50                   	push   eax
  59657c:	51                   	push   ecx
  59657d:	56                   	push   esi
  59657e:	e8 7d 71 1b 00       	call   0x74d700
  596583:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  596586:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  59658b:	2b d1                	sub    edx,ecx
  59658d:	83 fa 01             	cmp    edx,0x1
  596590:	0f 82 9d fe ff ff    	jb     0x596433
  596596:	41                   	inc    ecx
  596597:	89 4f 04             	mov    DWORD PTR [edi+0x4],ecx
  59659a:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  59659d:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  5965a0:	89 01                	mov    DWORD PTR [ecx],eax
  5965a2:	8b 55 e8             	mov    edx,DWORD PTR [ebp-0x18]
  5965a5:	8b 02                	mov    eax,DWORD PTR [edx]
  5965a7:	8b 4d d0             	mov    ecx,DWORD PTR [ebp-0x30]
  5965aa:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  5965ad:	39 4d e8             	cmp    DWORD PTR [ebp-0x18],ecx
  5965b0:	0f 85 54 fe ff ff    	jne    0x59640a
  5965b6:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5965b9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5965c0:	59                   	pop    ecx
  5965c1:	5f                   	pop    edi
  5965c2:	5e                   	pop    esi
  5965c3:	5b                   	pop    ebx
  5965c4:	8b e5                	mov    esp,ebp
  5965c6:	5d                   	pop    ebp
  5965c7:	c2 04 00             	ret    0x4
  5965ca:	cc                   	int3
  5965cb:	cc                   	int3
  5965cc:	cc                   	int3
  5965cd:	cc                   	int3
  5965ce:	cc                   	int3
  5965cf:	cc                   	int3
  5965d0:	55                   	push   ebp
  5965d1:	8b ec                	mov    ebp,esp
  5965d3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5965d6:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  5965d9:	81 ea 4e 43 0f 00    	sub    edx,0xf434e
  5965df:	74 1e                	je     0x5965ff
  5965e1:	83 ea 02             	sub    edx,0x2
  5965e4:	74 0f                	je     0x5965f5
  5965e6:	83 ea 05             	sub    edx,0x5
  5965e9:	75 1f                	jne    0x59660a
  5965eb:	51                   	push   ecx
  5965ec:	e8 5f 0c 00 00       	call   0x597250
  5965f1:	5d                   	pop    ebp
  5965f2:	c2 04 00             	ret    0x4
  5965f5:	51                   	push   ecx
  5965f6:	e8 15 0b 00 00       	call   0x597110
  5965fb:	5d                   	pop    ebp
  5965fc:	c2 04 00             	ret    0x4
  5965ff:	8b 89 b4 00 00 00    	mov    ecx,DWORD PTR [ecx+0xb4]
  596605:	e8 16 71 12 00       	call   0x6bd720
  59660a:	5d                   	pop    ebp
  59660b:	c2 04 00             	ret    0x4
  59660e:	cc                   	int3
  59660f:	cc                   	int3
  596610:	55                   	push   ebp
  596611:	8b ec                	mov    ebp,esp
  596613:	8b                   	.byte 0x8b
```

## 證據分級與後續

**已確認**：上述實際機器碼中的記憶體存取、比較、呼叫與循環界限；各段範圍限於列出的指令片段。

**合理推測**：這些讀取／分派與遊戲的通用輸入設備、狀態管理有關；尚不能由此指定 Z 鍵、連段次數或取消窗口。

**尚待驗證**：真正的非零事件 writer、Z 映射、held 與連按何處合流、普通攻擊下一段動畫 callback、服務端回覆權限。後續先尋 KeyMapping.xml 及輸入 callback owner；不可將 500 ms 或自製 CHAIN_WINDOW=0.65 當成原版 combo 設定。

此為本地長版機器碼保留稿，GitHub 同編號文件為短版技術筆記，兩者並非逐字一致。