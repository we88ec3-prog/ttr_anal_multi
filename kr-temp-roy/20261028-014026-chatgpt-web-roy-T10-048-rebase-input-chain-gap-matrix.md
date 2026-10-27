# T10-48 — 輸入→狀態→命令→動作的閉合邊界及下一輪精準追查

- 產生時間：2026-10-28T01:40:26+08:00（Asia/Taipei）
- BIN：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- EXE：`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- BIN PE `.text` 解碼採 VA = `0x401000 + (file_offset - 0x400)`；以下 raw offset = VA − 0x401000 + 0x400，僅適用 `.text`。
- 只做唯讀靜態分析；沒有啟動／附加／修改遊戲，也沒有把 AI fixture 視為原生結論。
- T10-45 後續連號；REBASE-01/02 不佔正式段號；過去筆記的主張須與 T01 限定整合及 BIN 直接核對分開。

## 本段原生核對與限定結論

### 多條已驗證的**局部**路徑與未閉合接點
A. `0x6D4DC0` 可依兩域容器蒐集 key mapping DWORD → `0x594610` 按條件再查鄰近 mapping → `0x594A80`/`0x594570` 做輸出格式轉換。此路徑缺「設定／資源載入 writer」及「實時動作 reader」。

B. `0x6D4CE0` 以特殊域樹的 byte 或一般域 `0xFB9004 + index` 的 byte 回傳 key-state；`0x6D4A30` 可清後者的前 40 bytes。此路徑缺真正的非零事件 writer、觸發 frame/frequency、index→action mapping。

C. 前一輪證據指出 `0x546780` 會將 `0x547240` 的狀態值轉成 `0x0008/0x0080/0x0040` bit，並與 `0x546850/0x546B50/0x546D50` 合流；`0x548918` 有 28..37 phase index 相關 `0x68` command 產出。**本段仍未證明 B 的 key-state reader 必然流入 C 或 B/C 與 Z/V 的對應。**

D. 角色動畫動作啟動、motion completion、next-action queue／取消及 tier 真正 writer，目前沒有從上述特定資料流得到跨函式的同一 instance、同一 frame 的正向連結。故不推論連段窗口、蓄氣秒數、優先權、取消時間。

### 與 T01 限定整合的相容性
- `timeGetTime` 嚴格 `>500 ms` 只能稱有條件狀態機，非 Z combo window。
- command index `28..37` 只表述索引域，非十段普通攻擊。
- 三路 OR 與 byte 選擇有不同合成策略。
- SubAI 計數 >60 不代表玩家 V 的實時持續秒數；SubAI candidate 7/9 不是已證 tier。
- `FB9004` 被清零不是非零按鍵 phase writer，phase1/3 不逕自稱 keydown/keyup。

### 下一輪可直接實施的位址導向研究
1. 按鍵非零 phase writer：以 `0x6D4CE0` 的 direct caller、`0xFB9004` 的常數與指標引用交叉核實 `store` 指令，區分直接／間接 writer。
2. 來源鍵位載入：`0x6D4DC0` 所引用 `0xFB8834/0xFDF3F4` 的填充路徑與配置物件型別，檢查 XML action 名與實際值域。
3. 動作下游：以 `0x548918` `0x68` 命令的 consumer 與 actor receiver provenance 追 motion／queue，跨 T11 只引用其主責。
4. 舉證完成條件：每條有效連接至少需要 BIN assembly caller+callee、傳遞寄存器／stack 位址、同一實例/結構證據，並與來源SHA及同一 target version 對應。


## 目標位址與原始 PE bytes 證據

### VA `0x00546780` / raw `0x00145B80` / window `528` bytes

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
  5468ee:	29 4d e8             	sub    DWORD PTR [ebp-0x18],ecx
  5468f1:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  5468f8:	75 27                	jne    0x546921
  5468fa:	09 0d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ecx
  546900:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  546907:	e8 44 9e 18 00       	call   0x6d0750
  54690c:	68 30 d5 bc 00       	push   0xbcd530
  546911:	e8 04 ba 34 00       	call   0x89231a
  546916:	83 c4 04             	add    esp,0x4
  546919:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  54691c:	b9 01 00 00 00       	mov    ecx,0x1
  546921:	0f b6 05 06 90 fb 00 	movzx  eax,BYTE PTR ds:0xfb9006
  546928:	3b c1                	cmp    eax,ecx
  54692a:	74 39                	je     0x546965
  54692c:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  546933:	75 27                	jne    0x54695c
  546935:	09 0d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ecx
  54693b:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  546942:	e8 09 9e 18 00       	call   0x6d0750
  546947:	68 30 d5 bc 00       	push   0xbcd530
  54694c:	e8 c9 b9 34 00       	call   0x89231a
  546951:	83 c4 04             	add    esp,0x4
  546954:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  546957:	b9 01 00 00 00       	mov    ecx,0x1
  54695c:	80 3d 06 90 fb 00 02 	cmp    BYTE PTR ds:0xfb9006,0x2
  546963:	75 03                	jne    0x546968
  546965:	01 4d e8             	add    DWORD PTR [ebp-0x18],ecx
  546968:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  54696f:	75 27                	jne    0x546998
  546971:	09 0d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ecx
  546977:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  54697e:	e8 cd 9d 18 00       	call   0x6d0750
  546983:	68 30 d5 bc 00       	push   0xbcd530
  546988:	e8 8d b9 34 00       	call   0x89231a
  54698d:	83 c4 04             	add    esp,0x4
```

### VA `0x00548918` / raw `0x00147D18` / window `341` bytes

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
```

### VA `0x006D4CE0` / raw `0x002D40E0` / window `213` bytes

```asm
  6d4ce0:	55                   	push   ebp
  6d4ce1:	8b ec                	mov    ebp,esp
  6d4ce3:	6a ff                	push   0xffffffff
  6d4ce5:	68 5c 68 92 00       	push   0x92685c
  6d4cea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d4cf0:	50                   	push   eax
  6d4cf1:	83 ec 08             	sub    esp,0x8
  6d4cf4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d4cf9:	33 c5                	xor    eax,ebp
  6d4cfb:	50                   	push   eax
  6d4cfc:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d4cff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d4d05:	8d 86 ef d8 ff ff    	lea    eax,[esi-0x2711]
  6d4d0b:	3d 0e 27 00 00       	cmp    eax,0x270e
  6d4d10:	b8 01 00 00 00       	mov    eax,0x1
  6d4d15:	77 59                	ja     0x6d4d70
  6d4d17:	84 05 ec f3 fd 00    	test   BYTE PTR ds:0xfdf3ec,al
  6d4d1d:	75 1f                	jne    0x6d4d3e
  6d4d1f:	09 05 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,eax
  6d4d25:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d4d2c:	e8 6f d0 ff ff       	call   0x6d1da0
  6d4d31:	68 30 e3 bc 00       	push   0xbce330
  6d4d36:	e8 df d5 1b 00       	call   0x89231a
  6d4d3b:	83 c4 04             	add    esp,0x4
  6d4d3e:	8d 4d f0             	lea    ecx,[ebp-0x10]
  6d4d41:	51                   	push   ecx
  6d4d42:	8d 45 ec             	lea    eax,[ebp-0x14]
  6d4d45:	b9 30 f6 fd 00       	mov    ecx,0xfdf630
  6d4d4a:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  6d4d4d:	e8 ae a1 15 00       	call   0x82ef00
  6d4d52:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  6d4d55:	3b 05 34 f6 fd 00    	cmp    eax,DWORD PTR ds:0xfdf634
  6d4d5b:	74 51                	je     0x6d4dae
  6d4d5d:	0f b6 40 10          	movzx  eax,BYTE PTR [eax+0x10]
  6d4d61:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4d64:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4d6b:	59                   	pop    ecx
  6d4d6c:	8b e5                	mov    esp,ebp
  6d4d6e:	5d                   	pop    ebp
  6d4d6f:	c3                   	ret
  6d4d70:	84 05 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,al
  6d4d76:	75 1b                	jne    0x6d4d93
  6d4d78:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  6d4d7e:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6d4d81:	e8 ca b9 ff ff       	call   0x6d0750
  6d4d86:	68 30 d5 bc 00       	push   0xbcd530
  6d4d8b:	e8 8a d5 1b 00       	call   0x89231a
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
  6d4db3:	64                   	fs
  6d4db4:	89                   	.byte 0x89
```

### VA `0x00594610` / raw `0x00193A10` / window `384` bytes

```asm
  594610:	55                   	push   ebp
  594611:	8b ec                	mov    ebp,esp
  594613:	83 e4 f8             	and    esp,0xfffffff8
  594616:	6a ff                	push   0xffffffff
  594618:	68 00 70 92 00       	push   0x927000
  59461d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  594623:	50                   	push   eax
  594624:	83 ec 60             	sub    esp,0x60
  594627:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  59462c:	33 c4                	xor    eax,esp
  59462e:	89 44 24 58          	mov    DWORD PTR [esp+0x58],eax
  594632:	53                   	push   ebx
  594633:	56                   	push   esi
  594634:	57                   	push   edi
  594635:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  59463a:	33 c4                	xor    eax,esp
  59463c:	50                   	push   eax
  59463d:	8d 44 24 70          	lea    eax,[esp+0x70]
  594641:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  594647:	8b f9                	mov    edi,ecx
  594649:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  59464c:	33 db                	xor    ebx,ebx
  59464e:	8b f2                	mov    esi,edx
  594650:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  594654:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  594658:	89 5c 24 3c          	mov    DWORD PTR [esp+0x3c],ebx
  59465c:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  594660:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  594664:	6a 02                	push   0x2
  594666:	57                   	push   edi
  594667:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  59466b:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  594672:	e8 49 07 14 00       	call   0x6d4dc0
  594677:	83 c4 08             	add    esp,0x8
  59467a:	53                   	push   ebx
  59467b:	68 fc d1 be 00       	push   0xbed1fc
  594680:	8b ce                	mov    ecx,esi
  594682:	e8 d9 da e6 ff       	call   0x402160
  594687:	83 ff 18             	cmp    edi,0x18
  59468a:	0f 85 29 01 00 00    	jne    0x5947b9
  594690:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  594694:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  594698:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  59469c:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  5946a0:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  5946a4:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  5946a8:	33 c9                	xor    ecx,ecx
  5946aa:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  5946b1:	00 
  5946b2:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  5946b6:	66 89 4c 24 4c       	mov    WORD PTR [esp+0x4c],cx
  5946bb:	6a 02                	push   0x2
  5946bd:	6a 0d                	push   0xd
  5946bf:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  5946c3:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x3
  5946ca:	03 
  5946cb:	e8 f0 06 14 00       	call   0x6d4dc0
  5946d0:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5946d4:	83 c4 08             	add    esp,0x8
  5946d7:	3b 44 24 30          	cmp    eax,DWORD PTR [esp+0x30]
  5946db:	74 27                	je     0x594704
  5946dd:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  5946e1:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  5946e4:	74 12                	je     0x5946f8
  5946e6:	8b 10                	mov    edx,DWORD PTR [eax]
  5946e8:	52                   	push   edx
  5946e9:	8d 74 24 50          	lea    esi,[esp+0x50]
  5946ed:	e8 8e 03 00 00       	call   0x594a80
  5946f2:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5946f6:	eb 0c                	jmp    0x594704
  5946f8:	8b 00                	mov    eax,DWORD PTR [eax]
  5946fa:	50                   	push   eax
  5946fb:	8d 44 24 50          	lea    eax,[esp+0x50]
  5946ff:	e8 6c fe ff ff       	call   0x594570
  594704:	6a ff                	push   0xffffffff
  594706:	53                   	push   ebx
  594707:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  59470b:	51                   	push   ecx
  59470c:	8b ce                	mov    ecx,esi
  59470e:	e8 dd fa e6 ff       	call   0x4041f0
  594713:	6a 02                	push   0x2
  594715:	6a 0e                	push   0xe
  594717:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  59471b:	e8 a0 06 14 00       	call   0x6d4dc0
  594720:	8b 7c 24 24          	mov    edi,DWORD PTR [esp+0x24]
  594724:	83 c4 08             	add    esp,0x8
  594727:	3b 7c 24 20          	cmp    edi,DWORD PTR [esp+0x20]
  59472b:	74 2f                	je     0x59475c
  59472d:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  594730:	74 16                	je     0x594748
  594732:	8b 17                	mov    edx,DWORD PTR [edi]
  594734:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  594738:	52                   	push   edx
  594739:	8d 74 24 50          	lea    esi,[esp+0x50]
  59473d:	e8 3e 03 00 00       	call   0x594a80
  594742:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  594746:	eb 10                	jmp    0x594758
  594748:	8b 07                	mov    eax,DWORD PTR [edi]
  59474a:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  59474e:	50                   	push   eax
  59474f:	8d 44 24 50          	lea    eax,[esp+0x50]
  594753:	e8 18 fe ff ff       	call   0x594570
  594758:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  59475c:	6a ff                	push   0xffffffff
  59475e:	53                   	push   ebx
  59475f:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  594763:	51                   	push   ecx
  594764:	8b ce                	mov    ecx,esi
  594766:	e8 85 fa e6 ff       	call   0x4041f0
  59476b:	83 7c 24 60 08       	cmp    DWORD PTR [esp+0x60],0x8
  594770:	72 0d                	jb     0x59477f
  594772:	8b 54 24 4c          	mov    edx,DWORD PTR [esp+0x4c]
  594776:	52                   	push   edx
  594777:	e8 90 ca 2f 00       	call   0x89120c
  59477c:	83 c4 04             	add    esp,0x4
  59477f:	33 c0                	xor    eax,eax
  594781:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  594788:	00 
  594789:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  59478d:	66                   	data16
  59478e:	89                   	.byte 0x89
  59478f:	44                   	inc    esp
```

## Direct E8 relative call 候選（機械搜尋，不等同完整 CFG）

- `0x00546780`：1 個候選指令位址：`0x00546263`

- `0x00548918`：0 個候選指令位址：無 E8 direct hit

- `0x006D4CE0`：2 個候選指令位址：`0x0059624E`, `0x0059643F`

- `0x00594610`：9 個候選指令位址：`0x005CD91F`, `0x005D1B75`, `0x005D2DD5`, `0x005D4045`, `0x0060E06B`, `0x00651122`, `0x0065117E`, `0x006511DA`, `0x0065120A`

## 記錄品質／驗收界線
- 本段第一手原始 bytes 是上述每段 BIN window，由 GNU objdump i386 解析；窗口起點選自既有函式入口，遇內部跳轉目標超出窗口時需另定位反組譯，不能把未列入的分支稱不存在。
- E8 搜尋依 direct rel32 靜態匹配（可能偽陽性），只屬候選來源，不包含 indirect/vtable/tailcall。
- PE raw vs flat 位址混淆應每次由原始 PE section header 檢查，絕不把本報告的局部核對推廣為整個反編譯索引皆正確。
- 本段不宣稱 Z/X/C/V 特定綁定、V 蓄氣、Z held 自動續段、queue/cancel 已閉合；亦不新增動作／伺服器規則或修改程式。
- GitHub 送交狀態以實際遠端 Commit+讀回為準；本檔在本機完成不等於已提交。