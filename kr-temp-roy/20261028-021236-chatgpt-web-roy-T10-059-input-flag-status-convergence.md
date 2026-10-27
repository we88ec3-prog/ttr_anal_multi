# T10-59 — 狀態機與多路輸入合流的跨鏈負證

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

`0x547240` 的嚴格 `>500ms`、`0x546780` 的回傳狀態對旗標映射，以及多路合流各自有局部機器碼依據；這些不足以宣稱 500ms 為連段或 V 長按窗口。

## 第一手 x86 反組譯摘錄

### VA `0x00546780` ／ raw `0x00145B80`（260 bytes）

```asm
  546780:	55                   	push   ebp
  546781:	8b ec                	mov    ebp,esp
  546783:	83 e4 f8             	and    esp,0xfffffff8
  546786:	51                   	push   ecx
  546787:	53                   	push   ebx
  546788:	56                   	push   esi
  546789:	57                   	push   edi
  54678a:	8b f8                	mov    edi,eax
  54678c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  54678f:	8a 00                	mov    al,BYTE PTR [eax]
  546791:	0f b7 5f 5c          	movzx  ebx,WORD PTR [edi+0x5c]
  546795:	8d 77 40             	lea    esi,[edi+0x40]
  546798:	88 44 24 0d          	mov    BYTE PTR [esp+0xd],al
  54679c:	88 44 24 0e          	mov    BYTE PTR [esp+0xe],al
  5467a0:	88 44 24 0f          	mov    BYTE PTR [esp+0xf],al
  5467a4:	e8 97 0a 00 00       	call   0x547240
  5467a9:	85 c0                	test   eax,eax
  5467ab:	74 1b                	je     0x5467c8
  5467ad:	83 e8 02             	sub    eax,0x2
  5467b0:	74 13                	je     0x5467c5
  5467b2:	48                   	dec    eax
  5467b3:	74 08                	je     0x5467bd
  5467b5:	48                   	dec    eax
  5467b6:	75 10                	jne    0x5467c8
  5467b8:	83 cb 40             	or     ebx,0x40
  5467bb:	eb 0b                	jmp    0x5467c8
  5467bd:	81 cb 80 00 00 00    	or     ebx,0x80
  5467c3:	eb 03                	jmp    0x5467c8
  5467c5:	83 cb 08             	or     ebx,0x8
  5467c8:	8d 4c 24 0d          	lea    ecx,[esp+0xd]
  5467cc:	51                   	push   ecx
  5467cd:	e8 7e 00 00 00       	call   0x546850
  5467d2:	8b f0                	mov    esi,eax
  5467d4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5467d7:	56                   	push   esi
  5467d8:	8d 54 24 12          	lea    edx,[esp+0x12]
  5467dc:	52                   	push   edx
  5467dd:	50                   	push   eax
  5467de:	8b c7                	mov    eax,edi
  5467e0:	e8 6b 03 00 00       	call   0x546b50
  5467e5:	8d 4c 24 0f          	lea    ecx,[esp+0xf]
  5467e9:	51                   	push   ecx
  5467ea:	8b f8                	mov    edi,eax
  5467ec:	e8 5f 05 00 00       	call   0x546d50
  5467f1:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  5467f4:	66 89 1a             	mov    WORD PTR [edx],bx
  5467f7:	85 f6                	test   esi,esi
  5467f9:	74 16                	je     0x546811
  5467fb:	8a 4c 24 0d          	mov    cl,BYTE PTR [esp+0xd]
  5467ff:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  546802:	0b c7                	or     eax,edi
  546804:	88 0a                	mov    BYTE PTR [edx],cl
  546806:	0b c6                	or     eax,esi
  546808:	5f                   	pop    edi
  546809:	5e                   	pop    esi
  54680a:	5b                   	pop    ebx
  54680b:	8b e5                	mov    esp,ebp
  54680d:	5d                   	pop    ebp
  54680e:	c2 0c 00             	ret    0xc
  546811:	85 ff                	test   edi,edi
  546813:	74 16                	je     0x54682b
  546815:	8a 4c 24 0e          	mov    cl,BYTE PTR [esp+0xe]
  546819:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  54681c:	0b c7                	or     eax,edi
  54681e:	88 0a                	mov    BYTE PTR [edx],cl
  546820:	0b c6                	or     eax,esi
  546822:	5f                   	pop    edi
  546823:	5e                   	pop    esi
  546824:	5b                   	pop    ebx
  546825:	8b e5                	mov    esp,ebp
  546827:	5d                   	pop    ebp
  546828:	c2 0c 00             	ret    0xc
  54682b:	85 c0                	test   eax,eax
  54682d:	74 09                	je     0x546838
  54682f:	8a 4c 24 0f          	mov    cl,BYTE PTR [esp+0xf]
  546833:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  546836:	88 0a                	mov    BYTE PTR [edx],cl
  546838:	0b c7                	or     eax,edi
  54683a:	5f                   	pop    edi
  54683b:	0b c6                	or     eax,esi
  54683d:	5e                   	pop    esi
  54683e:	5b                   	pop    ebx
  54683f:	8b e5                	mov    esp,ebp
  546841:	5d                   	pop    ebp
  546842:	c2 0c 00             	ret    0xc
  546845:	cc                   	int3
  546846:	cc                   	int3
  546847:	cc                   	int3
  546848:	cc                   	int3
  546849:	cc                   	int3
  54684a:	cc                   	int3
  54684b:	cc                   	int3
  54684c:	cc                   	int3
  54684d:	cc                   	int3
  54684e:	cc                   	int3
  54684f:	cc                   	int3
  546850:	55                   	push   ebp
  546851:	8b ec                	mov    ebp,esp
  546853:	6a ff                	push   0xffffffff
  546855:	68 9e ef 92 00       	push   0x92ef9e
  54685a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  546860:	50                   	push   eax
  546861:	83 ec 10             	sub    esp,0x10
  546864:	53                   	push   ebx
  546865:	56                   	push   esi
  546866:	57                   	push   edi
  546867:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54686c:	33 c5                	xor    eax,ebp
  54686e:	50                   	push   eax
  54686f:	8d 45 f4             	lea    eax,[ebp-0xc]
  546872:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  546878:	33 ff                	xor    edi,edi
  54687a:	32 db                	xor    bl,bl
  54687c:	83 ce ff             	or     esi,0xffffffff
  54687f:	f6                   	.byte 0xf6
  546880:	05                   	.byte 0x5
  546881:	14 7c                	adc    al,0x7c
  546883:	fb                   	sti
```

### VA `0x00546850` ／ raw `0x00145C50`（160 bytes）

```asm
  546850:	55                   	push   ebp
  546851:	8b ec                	mov    ebp,esp
  546853:	6a ff                	push   0xffffffff
  546855:	68 9e ef 92 00       	push   0x92ef9e
  54685a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  546860:	50                   	push   eax
  546861:	83 ec 10             	sub    esp,0x10
  546864:	53                   	push   ebx
  546865:	56                   	push   esi
  546866:	57                   	push   edi
  546867:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54686c:	33 c5                	xor    eax,ebp
  54686e:	50                   	push   eax
  54686f:	8d 45 f4             	lea    eax,[ebp-0xc]
  546872:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  546878:	33 ff                	xor    edi,edi
  54687a:	32 db                	xor    bl,bl
  54687c:	83 ce ff             	or     esi,0xffffffff
  54687f:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  546886:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  546889:	75 1f                	jne    0x5468aa
  54688b:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  546892:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  546895:	e8 b6 9e 18 00       	call   0x6d0750
  54689a:	68 30 d5 bc 00       	push   0xbcd530
  54689f:	e8 76 ba 34 00       	call   0x89231a
  5468a4:	83 c4 04             	add    esp,0x4
  5468a7:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5468aa:	0f b6 05 05 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9005
  5468b1:	b9 01 00 00 00       	mov    ecx,0x1
  5468b6:	3b c1                	cmp    eax,ecx
  5468b8:	74 34                	je     0x5468ee
  5468ba:	84 0d 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,cl
  5468c0:	75 23                	jne    0x5468e5
  5468c2:	09 0d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ecx
  5468c8:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  5468cb:	e8 80 9e 18 00       	call   0x6d0750
  5468d0:	68 30 d5 bc 00       	push   0xbcd530
  5468d5:	e8 40 ba 34 00       	call   0x89231a
  5468da:	83 c4 04             	add    esp,0x4
  5468dd:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5468e0:	b9 01 00 00 00       	mov    ecx,0x1
  5468e5:	80 3d 05 90 fb 00 02 	cmp    BYTE PTR ds:0xfb9005,0x2
  5468ec:	75 03                	jne    0x5468f1
  5468ee:	29                   	.byte 0x29
  5468ef:	4d                   	dec    ebp
```

### VA `0x00546B50` ／ raw `0x00145F50`（180 bytes）

```asm
  546b50:	55                   	push   ebp
  546b51:	8b ec                	mov    ebp,esp
  546b53:	83 e4 f8             	and    esp,0xfffffff8
  546b56:	83 ec 1c             	sub    esp,0x1c
  546b59:	53                   	push   ebx
  546b5a:	56                   	push   esi
  546b5b:	57                   	push   edi
  546b5c:	8b f8                	mov    edi,eax
  546b5e:	a1 0c a8 fb 00       	mov    eax,ds:0xfba80c
  546b63:	33 db                	xor    ebx,ebx
  546b65:	3b c3                	cmp    eax,ebx
  546b67:	75 21                	jne    0x546b8a
  546b69:	68 7c 05 00 00       	push   0x57c
  546b6e:	e8 f5 a6 34 00       	call   0x891268
  546b73:	83 c4 04             	add    esp,0x4
  546b76:	3b c3                	cmp    eax,ebx
  546b78:	74 09                	je     0x546b83
  546b7a:	8b f0                	mov    esi,eax
  546b7c:	e8 ef a7 1a 00       	call   0x6f1370
  546b81:	eb 02                	jmp    0x546b85
  546b83:	33 c0                	xor    eax,eax
  546b85:	a3 0c a8 fb 00       	mov    ds:0xfba80c,eax
  546b8a:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  546b90:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  546b93:	74 2e                	je     0x546bc3
  546b95:	0f b6 88 68 03 00 00 	movzx  ecx,BYTE PTR [eax+0x368]
  546b9c:	3b cb                	cmp    ecx,ebx
  546b9e:	74 23                	je     0x546bc3
  546ba0:	8b 8a 1c c0 00 00    	mov    ecx,DWORD PTR [edx+0xc01c]
  546ba6:	d1 e9                	shr    ecx,1
  546ba8:	f6 c1 01             	test   cl,0x1
  546bab:	75 16                	jne    0x546bc3
  546bad:	f6 82 1c c0 00 00 01 	test   BYTE PTR [edx+0xc01c],0x1
  546bb4:	75 0d                	jne    0x546bc3
  546bb6:	c7 47 7c 01 00 00 00 	mov    DWORD PTR [edi+0x7c],0x1
  546bbd:	89 9f 80 00 00 00    	mov    DWORD PTR [edi+0x80],ebx
  546bc3:	39 5d 10             	cmp    DWORD PTR [ebp+0x10],ebx
  546bc6:	74 14                	je     0x546bdc
  546bc8:	89 5f 7c             	mov    DWORD PTR [edi+0x7c],ebx
  546bcb:	89 9f 80 00 00 00    	mov    DWORD PTR [edi+0x80],ebx
  546bd1:	33 c0                	xor    eax,eax
  546bd3:	5f                   	pop    edi
  546bd4:	5e                   	pop    esi
  546bd5:	5b                   	pop    ebx
  546bd6:	8b e5                	mov    esp,ebp
  546bd8:	5d                   	pop    ebp
  546bd9:	c2 0c 00             	ret    0xc
  546bdc:	8d 88 70 03 00 00    	lea    ecx,[eax+0x370]
  546be2:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  546be5:	74 06                	je     0x546bed
  546be7:	8d 88 60 03 00 00    	lea    ecx,[eax+0x360]
  546bed:	38 59 02             	cmp    BYTE PTR [ecx+0x2],bl
  546bf0:	74 32                	je     0x546c24
  546bf2:	f6 82 1c c0 00 00 01 	test   BYTE PTR [edx+0xc01c],0x1
  546bf9:	75 29                	jne    0x546c24
  546bfb:	39 1d 20 1e fe 00    	cmp    DWORD PTR ds:0xfe1e20,ebx
  546c01:	75 27                	jne    0x546c2a
  546c03:	b9                   	.byte 0xb9
```

### VA `0x00546D50` ／ raw `0x00146150`（160 bytes）

```asm
  546d50:	55                   	push   ebp
  546d51:	8b ec                	mov    ebp,esp
  546d53:	83 e4 f8             	and    esp,0xfffffff8
  546d56:	6a ff                	push   0xffffffff
  546d58:	68 fe ee 92 00       	push   0x92eefe
  546d5d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  546d63:	50                   	push   eax
  546d64:	83 ec 1c             	sub    esp,0x1c
  546d67:	53                   	push   ebx
  546d68:	57                   	push   edi
  546d69:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  546d6e:	33 c4                	xor    eax,esp
  546d70:	50                   	push   eax
  546d71:	8d 44 24 28          	lea    eax,[esp+0x28]
  546d75:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  546d7b:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  546d82:	75 29                	jne    0x546dad
  546d84:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  546d8b:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  546d92:	00 
  546d93:	e8 b8 99 18 00       	call   0x6d0750
  546d98:	68 30 d5 bc 00       	push   0xbcd530
  546d9d:	e8 78 b5 34 00       	call   0x89231a
  546da2:	83 c4 04             	add    esp,0x4
  546da5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  546dac:	ff 
  546dad:	83 3d 30 88 fb 00 00 	cmp    DWORD PTR ds:0xfb8830,0x0
  546db4:	0f 85 1f 01 00 00    	jne    0x546ed9
  546dba:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  546dbf:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  546dc2:	ff 15 5c 24 bd 00    	call   DWORD PTR ds:0xbd245c
  546dc8:	3b c7                	cmp    eax,edi
  546dca:	0f 85 09 01 00 00    	jne    0x546ed9
  546dd0:	f6 05 6c 1a fc 00 01 	test   BYTE PTR ds:0xfc1a6c,0x1
  546dd7:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  546dde:	00 
  546ddf:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  546de6:	00 
  546de7:	75 14                	jne    0x546dfd
  546de9:	83 0d 6c 1a fc 00 01 	or     DWORD PTR ds:0xfc1a6c,0x1
```

### VA `0x00547240` ／ raw `0x00146640`（240 bytes）

```asm
  547240:	55                   	push   ebp
  547241:	8b ec                	mov    ebp,esp
  547243:	6a ff                	push   0xffffffff
  547245:	68 1e 74 92 00       	push   0x92741e
  54724a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  547250:	50                   	push   eax
  547251:	51                   	push   ecx
  547252:	57                   	push   edi
  547253:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  547258:	33 c5                	xor    eax,ebp
  54725a:	50                   	push   eax
  54725b:	8d 45 f4             	lea    eax,[ebp-0xc]
  54725e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  547264:	b8 01 00 00 00       	mov    eax,0x1
  547269:	33 ff                	xor    edi,edi
  54726b:	84 05 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,al
  547271:	75 1b                	jne    0x54728e
  547273:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  547279:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  54727c:	e8 cf 94 18 00       	call   0x6d0750
  547281:	68 30 d5 bc 00       	push   0xbcd530
  547286:	e8 8f b0 34 00       	call   0x89231a
  54728b:	83 c4 04             	add    esp,0x4
  54728e:	8b 0e                	mov    ecx,DWORD PTR [esi]
  547290:	0f b6 05 14 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9014
  547297:	83 f9 03             	cmp    ecx,0x3
  54729a:	0f 87 be 00 00 00    	ja     0x54735e
  5472a0:	ff 24 8d 70 73 54 00 	jmp    DWORD PTR [ecx*4+0x547370]
  5472a7:	83 f8 01             	cmp    eax,0x1
  5472aa:	74 09                	je     0x5472b5
  5472ac:	83 f8 02             	cmp    eax,0x2
  5472af:	0f 85 a9 00 00 00    	jne    0x54735e
  5472b5:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  5472bb:	bf 01 00 00 00       	mov    edi,0x1
  5472c0:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  5472c3:	c7 06 02 00 00 00    	mov    DWORD PTR [esi],0x2
  5472c9:	8b c7                	mov    eax,edi
  5472cb:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5472ce:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5472d5:	59                   	pop    ecx
  5472d6:	5f                   	pop    edi
  5472d7:	8b e5                	mov    esp,ebp
  5472d9:	5d                   	pop    ebp
  5472da:	c3                   	ret
  5472db:	3b c7                	cmp    eax,edi
  5472dd:	74 7f                	je     0x54735e
  5472df:	89 3e                	mov    DWORD PTR [esi],edi
  5472e1:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  5472e4:	8b c7                	mov    eax,edi
  5472e6:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5472e9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5472f0:	59                   	pop    ecx
  5472f1:	5f                   	pop    edi
  5472f2:	8b e5                	mov    esp,ebp
  5472f4:	5d                   	pop    ebp
  5472f5:	c3                   	ret
  5472f6:	83 f8 03             	cmp    eax,0x3
  5472f9:	74 34                	je     0x54732f
  5472fb:	3b c7                	cmp    eax,edi
  5472fd:	74 30                	je     0x54732f
  5472ff:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  547305:	2b 46 04             	sub    eax,DWORD PTR [esi+0x4]
  547308:	3d f4 01 00 00       	cmp    eax,0x1f4
  54730d:	76 4f                	jbe    0x54735e
  54730f:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  547312:	bf 03 00 00 00       	mov    edi,0x3
  547317:	c7 06 03 00 00 00    	mov    DWORD PTR [esi],0x3
  54731d:	8b c7                	mov    eax,edi
  54731f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  547322:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  547329:	59                   	pop    ecx
  54732a:	5f                   	pop    edi
  54732b:	8b e5                	mov    esp,ebp
  54732d:	5d                   	pop    ebp
  54732e:	c3                   	ret
  54732f:	89                   	.byte 0x89
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