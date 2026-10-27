# KR T10-20 — 三條輸入資料流與 Z 續段的證據邊界

日期：2026-10-27 Asia/Taipei。原始 BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。檔案大小：12,472,320 bytes。PE .text VA 0x401000, file raw 0x400。x86 objdump Intel 模式、原檔唯讀；下列較長節錄從明確指令入口或已知對齊位置取得。

## 本段技術結論

A：未知非零 writer -> FB9004+index 或擴展鍵樹 -> 6D4CE0 -> 5961C0 按 phase 1/3 dispatch，596140 可攔截。B：FB9014 -> 547240 (500ms timeGetTime gate) -> 546780 mask -> 546100 controller -> 5452C0 封包 000A，但未直接與 Z 對應。C：FB9015..18 -> 50C640 命令 0x22；FB9004+[28..37] -> 548918 命令 0x68；另一 controller branch 命令 0x07。三者不能混成單一 Z combo；尚未證明 held auto-chain、rapid-press chain、animation completion callback 和取消時間。未取得 Table/KeyMapping.xml 本體，不能確認 Z 的配置。

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

### 片段起點 0x5488E0

```asm
  5488e0:	cc                   	int3
  5488e1:	bc 00 e8 32 9a       	mov    esp,0x9a32e800
  5488e6:	34 00                	xor    al,0x0
  5488e8:	83 c4 04             	add    esp,0x4
  5488eb:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  5488ef:	83 3d 2c 39 f9 00 04 	cmp    DWORD PTR ds:0xf9392c,0x4
  5488f6:	74 20                	je     0x548918
  5488f8:	e8 a3 c2 eb ff       	call   0x404ba0
  5488fd:	83 b8 4c 5f 00 00 09 	cmp    DWORD PTR [eax+0x5f4c],0x9
  548904:	74 12                	je     0x548918
  548906:	e8 95 c2 eb ff       	call   0x404ba0
  54890b:	83 b8 4c 5f 00 00 06 	cmp    DWORD PTR [eax+0x5f4c],0x6
  548912:	0f 85 a1 00 00 00    	jne    0x5489b9
  548918:	33 db                	xor    ebx,ebx
  54891a:	8d 73 1c             	lea    esi,[ebx+0x1c]
  54891d:	8d 49 00             	lea    ecx,[ecx+0x0]
  548920:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  548927:	75 29                	jne    0x548952
  548929:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  548930:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  548937:	00 
  548938:	e8 13 7e 18 00       	call   0x6d0750
  54893d:	68 30 d5 bc 00       	push   0xbcd530
  548942:	e8 d3 99 34 00       	call   0x89231a
  548947:	83 c4 04             	add    esp,0x4
  54894a:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  548951:	ff 
  548952:	83 fe 27             	cmp    esi,0x27
  548955:	77 57                	ja     0x5489ae
  548957:	0f b6 86 04 90 fb 00 	movzx  eax,BYTE PTR [esi+0xfb9004]
  54895e:	83 f8 01             	cmp    eax,0x1
  548961:	75 4b                	jne    0x5489ae
  548963:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  548969:	75 13                	jne    0x54897e
  54896b:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  548971:	68 10 cf bc 00       	push   0xbccf10
  548976:	e8 9f 99 34 00       	call   0x89231a
  54897b:	83 c4 04             	add    esp,0x4
  54897e:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  548985:	b9 68 00 00 00       	mov    ecx,0x68
  54898a:	8d 53 01             	lea    edx,[ebx+0x1]
  54898d:	66 89 4c 24 14       	mov    WORD PTR [esp+0x14],cx
  548992:	88 54 24 16          	mov    BYTE PTR [esp+0x16],dl
  548996:	75 16                	jne    0x5489ae
  548998:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  54899e:	8b 01                	mov    eax,DWORD PTR [ecx]
  5489a0:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5489a3:	6a 03                	push   0x3
  5489a5:	8d 54 24 18          	lea    edx,[esp+0x18]
  5489a9:	52                   	push   edx
  5489aa:	6a 00                	push   0x0
  5489ac:	ff d0                	call   eax
  5489ae:	46                   	inc    esi
  5489af:	43                   	inc    ebx
  5489b0:	83 fe 26             	cmp    esi,0x26
  5489b3:	0f 8c 67 ff ff ff    	jl     0x548920
  5489b9:	8a 44 24 13          	mov    al,BYTE PTR [esp+0x13]
  5489bd:	84 c0                	test   al,al
  5489bf:	74 42                	je     0x548a03
  5489c1:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5489c8:	b9 07 00 00 00       	mov    ecx,0x7
  5489cd:	66 89 4c 24 18       	mov    WORD PTR [esp+0x18],cx
  5489d2:	88 44 24 1a          	mov    BYTE PTR [esp+0x1a],al
  5489d6:	75 16                	jne    0x5489ee
  5489d8:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5489de:	8b 11                	mov    edx,DWORD PTR [ecx]
  5489e0:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  5489e3:	6a 03                	push   0x3
  5489e5:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5489e9:	50                   	push   eax
  5489ea:	6a 00                	push   0x0
  5489ec:	ff d2                	call   edx
  5489ee:	b0 01                	mov    al,0x1
  5489f0:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5489f4:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5489fb:	59                   	pop    ecx
  5489fc:	5f                   	pop    edi
  5489fd:	5e                   	pop    esi
  5489fe:	5b                   	pop    ebx
  5489ff:	8b e5                	mov    esp,ebp
  548a01:	5d                   	pop    ebp
  548a02:	c3                   	ret
  548a03:	32 c0                	xor    al,al
  548a05:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  548a09:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  548a10:	59                   	pop    ecx
  548a11:	5f                   	pop    edi
  548a12:	5e                   	pop    esi
  548a13:	5b                   	pop    ebx
  548a14:	8b e5                	mov    esp,ebp
  548a16:	5d                   	pop    ebp
  548a17:	c3                   	ret
  548a18:	cc                   	int3
  548a19:	cc                   	int3
  548a1a:	cc                   	int3
  548a1b:	cc                   	int3
  548a1c:	cc                   	int3
  548a1d:	cc                   	int3
  548a1e:	cc                   	int3
  548a1f:	cc                   	int3
  548a20:	55                   	push   ebp
  548a21:	8b ec                	mov    ebp,esp
  548a23:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  548a26:	85 c0                	test   eax,eax
  548a28:	74 58                	je     0x548a82
  548a2a:	83 b8 8c 03 00 00 10 	cmp    DWORD PTR [eax+0x38c],0x10
  548a31:	74 19                	je     0x548a4c
  548a33:	83 b9 a4 00 00 00 00 	cmp    DWORD PTR [ecx+0xa4],0x0
  548a3a:	75 10                	jne    0x548a4c
  548a3c:	c7 81 bc 00 00 00 00 	mov    DWORD PTR [ecx+0xbc],0x0
  548a43:	00 00 00 
  548a46:	5d                   	pop    ebp
  548a47:	e9 b4 d6 ff ff       	jmp    0x546100
  548a4c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  548a4f:	83 b9 bc 00 00 00 00 	cmp    DWORD PTR [ecx+0xbc],0x0
  548a56:	8d 54 52 03          	lea    edx,[edx+edx*2+0x3]
  548a5a:	8b 14 91             	mov    edx,DWORD PTR [ecx+edx*4]
  548a5d:	8a 92 b0 00 00 00    	mov    dl,BYTE PTR [edx+0xb0]
  548a63:	56                   	push   esi
  548a64:	8b 75 0c             	mov    esi,DWORD PTR [ebp+0xc]
  548a67:	88 56 04             	mov    BYTE PTR [esi+0x4],dl
  548a6a:	0f 94 c0             	sete   al
  548a6d:	33 d2                	xor    edx,edx
  548a6f:	66 89 56 02          	mov    WORD PTR [esi+0x2],dx
  548a73:	c7                   	.byte 0xc7
  548a74:	81                   	.byte 0x81
  548a75:	bc 00 00 00 01       	mov    esp,0x1000000
```

## 證據分級與後續

**已確認**：上述實際機器碼中的記憶體存取、比較、呼叫與循環界限；各段範圍限於列出的指令片段。

**合理推測**：這些讀取／分派與遊戲的通用輸入設備、狀態管理有關；尚不能由此指定 Z 鍵、連段次數或取消窗口。

**尚待驗證**：真正的非零事件 writer、Z 映射、held 與連按何處合流、普通攻擊下一段動畫 callback、服務端回覆權限。後續先尋 KeyMapping.xml 及輸入 callback owner；不可將 500 ms 或自製 CHAIN_WINDOW=0.65 當成原版 combo 設定。

此為本地長版機器碼保留稿，GitHub 同編號文件為短版技術筆記，兩者並非逐字一致。