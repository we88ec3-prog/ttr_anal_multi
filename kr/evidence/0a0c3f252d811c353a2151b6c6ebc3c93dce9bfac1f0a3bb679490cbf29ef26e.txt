# T10-60 — 從輸入寫入到動作隊列的證據鏈終局與待驗地址

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

本輪直接位址參照盤點和關鍵 consumer 均未補足非零 writer→自訂 action row→player controller→actor start→animation completion→queue/cancel 的完整邊；保留缺口、避免以 AI 替代 `CHAIN_WINDOW=0.65` 當原生值。

## 第一手 x86 反組譯摘錄

### VA `0x006D4D90` ／ raw `0x002D4190`（85 bytes）

```asm
  6d4d90:	83 c4 04             	add    esp,0x4
  6d4d93:	83 fe 27             	cmp    esi,0x27
  6d4d96:	77 16                	ja     0x6d4dae
  6d4d98:	0f b6 86 04 90 fb 00 	movzx  eax,BYTE PTR [esi+0xfb9004]
  6d4d9f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4da2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4da9:	59                   	pop    ecx
  6d4daa:	8b e5                	mov    esp,ebp
  6d4dac:	5d                   	pop    ebp
  6d4dad:	c3                   	ret
  6d4dae:	33 c0                	xor    eax,eax
  6d4db0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4db3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4dba:	59                   	pop    ecx
  6d4dbb:	8b e5                	mov    esp,ebp
  6d4dbd:	5d                   	pop    ebp
  6d4dbe:	c3                   	ret
  6d4dbf:	cc                   	int3
  6d4dc0:	55                   	push   ebp
  6d4dc1:	8b ec                	mov    ebp,esp
  6d4dc3:	6a ff                	push   0xffffffff
  6d4dc5:	68 18 68 92 00       	push   0x926818
  6d4dca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d4dd0:	50                   	push   eax
  6d4dd1:	83 ec 0c             	sub    esp,0xc
  6d4dd4:	53                   	push   ebx
  6d4dd5:	56                   	push   esi
  6d4dd6:	57                   	push   edi
  6d4dd7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d4ddc:	33 c5                	xor    eax,ebp
  6d4dde:	50                   	push   eax
  6d4ddf:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d4de2:	64                   	fs
  6d4de3:	a3                   	.byte 0xa3
	...
```

### VA `0x00596245` ／ raw `0x00195645`（165 bytes）

```asm
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
  5962e9:	75                   	.byte 0x75
```

### VA `0x00548918` ／ raw `0x00147D18`（250 bytes）

```asm
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
```

### VA `0x005CD90A` ／ raw `0x001CCD0A`（145 bytes）

```asm
  5cd90a:	8b 0c 9d f0 32 f8 00 	mov    ecx,DWORD PTR [ebx*4+0xf832f0]
  5cd911:	6a 01                	push   0x1
  5cd913:	68 18 fb fd 00       	push   0xfdfb18
  5cd918:	8d 94 24 b0 00 00 00 	lea    edx,[esp+0xb0]
  5cd91f:	e8 ec 6c fc ff       	call   0x594610
  5cd924:	8a 4c 24 14          	mov    cl,BYTE PTR [esp+0x14]
  5cd928:	8d 43 01             	lea    eax,[ebx+0x1]
  5cd92b:	80 f9 04             	cmp    cl,0x4
  5cd92e:	73 1a                	jae    0x5cd94a
  5cd930:	3c 0b                	cmp    al,0xb
  5cd932:	73 16                	jae    0x5cd94a
  5cd934:	0f b6 c9             	movzx  ecx,cl
  5cd937:	6b c9 0b             	imul   ecx,ecx,0xb
  5cd93a:	0f b6 d0             	movzx  edx,al
  5cd93d:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5cd941:	03 ca                	add    ecx,edx
  5cd943:	0f b7 44 48 04       	movzx  eax,WORD PTR [eax+ecx*2+0x4]
  5cd948:	eb 02                	jmp    0x5cd94c
  5cd94a:	33 c0                	xor    eax,eax
  5cd94c:	0f b7 c8             	movzx  ecx,ax
  5cd94f:	8d 54 24 44          	lea    edx,[esp+0x44]
  5cd953:	89 4c 24 44          	mov    DWORD PTR [esp+0x44],ecx
  5cd957:	52                   	push   edx
  5cd958:	8d 84 24 a4 00 00 00 	lea    eax,[esp+0xa4]
  5cd95f:	8b cf                	mov    ecx,edi
  5cd961:	e8 1a 89 25 00       	call   0x826280
  5cd966:	8b 8c 24 a0 00 00 00 	mov    ecx,DWORD PTR [esp+0xa0]
  5cd96d:	3b 4f 04             	cmp    ecx,DWORD PTR [edi+0x4]
  5cd970:	0f 84 fe 02 00 00    	je     0x5cdc74
  5cd976:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  5cd979:	85 c0                	test   eax,eax
  5cd97b:	0f 84 f3 02 00 00    	je     0x5cdc74
  5cd981:	0f b7 48 04          	movzx  ecx,WORD PTR [eax+0x4]
  5cd985:	66 85 c9             	test   cx,cx
  5cd988:	0f 84 e6 02 00 00    	je     0x5cdc74
  5cd98e:	8b 38                	mov    edi,DWORD PTR [eax]
  5cd990:	8b f1                	mov    esi,ecx
  5cd992:	89 74 24 44          	mov    DWORD PTR [esp+0x44],esi
  5cd996:	e8 15 75 eb ff       	call   0x484eb0
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