# T10-52 — input-controller-motion-boundary

- 時間：2026-10-28T01:49:00+08:00 (Asia/Taipei)
- 來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- PE .text: VA 0x401000 / raw 0x400；此處所有摘錄均由原始 bytes 唯讀反組譯，非 Ghidra 摘要。
- GitHub T01-20261027-05 語意接受範圍僅為部分確認；此筆記無法自動擴大為整函式 native 驗收。
- 原始目標未執行，未修改、未附加遊戲。

## 本段核心：整合輸入 consumer，區分正向證據與未連線的流程

### 已直接核對

- `0x5467A4: call 0x547240`，由返回值在 `0x5467AD..0x5467C5` 對 `ebx` OR `0x40/0x80/0x08`；`0x5467CD` 進入 `0x546850` 後另呼叫 `0x546B50`。這個 flag 轉換是直接 BIN 可驗證。
- `0x548957` 讀 `[esi+0xFB9004]`，並與立即數 `1` 比較；條件下方有 virtual `+0x10` 的呼叫，但 receiver 來自不同全域欄位，未證是角色 motion。
- `0x59624E/0x59643F` 呼叫 `0x6D4CE0`，隨後可見 `+0xEC/+0xF0` 多型檢查；這是兩條結構化 consumer，但仍欠缺對 `0x546780` 的同一實例／同一資料欄位連結。
- `0x6D4CAE` 只證 keyed clear；沒有找到與其配對的同一已確認非零 writer，不可把它命名為 keyup。

### 目前確定不能推出的原版遊戲規則

1. `0x547240` 嚴格 `>500ms` 不等於 Z combo/cancel window；AI `CHAIN_WINDOW=.65` 不是原版規則。
2. 指令索引 `28..37` 不是十段普攻連段。
3. SubAI `>60` 次計數不是玩家 V 長按秒數，候選 `7/9` 不等於 tier。
4. `+0xEC/+0xF0` 多型 predicate 尚未用接收者 vptr provenance 證明等於 attack/skill cancel。
5. 無證據證明與鍵碼相同的各容器就是同一物件。

### 下一段 T10-53 精準優先次序

1. 靜態反向搜尋非零 indexed writer：從事件分派、key input API callback、指標别名，先證實來源寄存器與 `0xFB9004`/特殊樹節點的同一性。
2. 用實際 `KeyMapping.xml` 或 fallback resource 完成 action-id→key-code→phase byte 的綁定。
3. 從 `0x546780` 的輸出 flag/command 的真實 dispatcher 追到 actor 方法及 motion 開始完成時序；記錄 queue producer/consumer 與 cancel gate 的真實物件類型。
4. 引用 T11 的施放資料，僅在同一實例被原始 bytes 證實時建立互相銜接路徑。

### 結案定義

這批完成「已核驗局部鏈＋阻塞點」而非完整玩家戰鬥規則。無仿造 Z/V 秒數、幀數、取消優先權、cooldown 或封包。

## 第一手反組譯片段

### VA `0x00546780` / raw `0x00145b80` (280 bytes)

```asm
00546780 <.data>:
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
  546895:	e8                   	.byte 0xe8
  546896:	b6 9e                	mov    dh,0x9e
```
### VA `0x00548920` / raw `0x00147d20` (240 bytes)

```asm
00548920 <.data>:
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
```
### VA `0x005961c0` / raw `0x001955c0` (265 bytes)

```asm
005961c0 <.data>:
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
  5962c8:	85                   	.byte 0x85
```
### VA `0x006d4c60` / raw `0x002d4060` (110 bytes)

```asm
006d4c60 <.data>:
  6d4c60:	52                   	push   edx
  6d4c61:	8d 45 f0             	lea    eax,[ebp-0x10]
  6d4c64:	b9 30 f6 fd 00       	mov    ecx,0xfdf630
  6d4c69:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  6d4c6c:	e8 8f a2 15 00       	call   0x82ef00
  6d4c71:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  6d4c74:	3b 05 34 f6 fd 00    	cmp    eax,DWORD PTR ds:0xfdf634
  6d4c7a:	74 39                	je     0x6d4cb5
  6d4c7c:	c6 40 10 00          	mov    BYTE PTR [eax+0x10],0x0
  6d4c80:	eb 33                	jmp    0x6d4cb5
  6d4c82:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4c89:	75 23                	jne    0x6d4cae
  6d4c8b:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  6d4c92:	c7 45 fc 07 00 00 00 	mov    DWORD PTR [ebp-0x4],0x7
  6d4c99:	e8 b2 ba ff ff       	call   0x6d0750
  6d4c9e:	68 30 d5 bc 00       	push   0xbcd530
  6d4ca3:	e8 72 d6 1b 00       	call   0x89231a
  6d4ca8:	83 c4 04             	add    esp,0x4
  6d4cab:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4cae:	c6 86 04 90 fb 00 00 	mov    BYTE PTR [esi+0xfb9004],0x0
  6d4cb5:	8b 3f                	mov    edi,DWORD PTR [edi]
  6d4cb7:	3b 7d ec             	cmp    edi,DWORD PTR [ebp-0x14]
  6d4cba:	0f 85 60 ff ff ff    	jne    0x6d4c20
  6d4cc0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4cc3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4cca:	59                   	pop    ecx
  6d4ccb:	5f                   	pop    edi
  6d4ccc:	5e                   	pop    esi
  6d4ccd:	5b                   	pop    ebx
```

## 可重現的呼叫掃描（原始 BIN）

- Direct E8 target `0x6d4ce0`：0x59624e, 0x59643f。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x6d4a30`：0x490dfc, 0x58a607。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x594610`：0x5cd91f, 0x5d1b75, 0x5d2dd5, 0x5d4045, 0x60e06b, 0x651122, 0x65117e, 0x6511da, 0x65120a。注意僅是 bytes 命中，不是全部可達路徑。

## 明確未解

- 自訂 action mapping 的實際 XML 資料與儲存 writer 尚未連上。
- 玩家 V 短按／長按、Z 長按自動續段、普通攻擊與技能前後銜接的 queue、cancel window 均尚無直接跨函式證據。
- 間接函式、物件類型與多執行緒事件來源應繼續按實例校驗，不可單憑相同 offset 或名稱視為相等。