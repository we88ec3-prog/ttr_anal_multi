# T10-58 — command 0x68 的索引邊界與派送限制

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

`0x548918` 來源索引 28..37 並產生 command 0x68 的局部路徑。10 個索引是迴圈長度，不是十段普攻；尚需派送 receiver 與 actor transition 的第一手證據。

## 第一手 x86 反組譯摘錄

### VA `0x00548918` ／ raw `0x00147D18`（310 bytes）

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
  548a4c:	8b                   	.byte 0x8b
  548a4d:	55                   	push   ebp
```

### VA `0x00548A10` ／ raw `0x00147E10`（265 bytes）

```asm
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
  548a73:	c7 81 bc 00 00 00 01 	mov    DWORD PTR [ecx+0xbc],0x1
  548a7a:	00 00 00 
  548a7d:	5e                   	pop    esi
  548a7e:	5d                   	pop    ebp
  548a7f:	c2 08 00             	ret    0x8
  548a82:	32 c0                	xor    al,al
  548a84:	5d                   	pop    ebp
  548a85:	c2 08 00             	ret    0x8
  548a88:	cc                   	int3
  548a89:	cc                   	int3
  548a8a:	cc                   	int3
  548a8b:	cc                   	int3
  548a8c:	cc                   	int3
  548a8d:	cc                   	int3
  548a8e:	cc                   	int3
  548a8f:	cc                   	int3
  548a90:	55                   	push   ebp
  548a91:	8b ec                	mov    ebp,esp
  548a93:	6a ff                	push   0xffffffff
  548a95:	68 2e 53 94 00       	push   0x94532e
  548a9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  548aa0:	50                   	push   eax
  548aa1:	51                   	push   ecx
  548aa2:	53                   	push   ebx
  548aa3:	56                   	push   esi
  548aa4:	57                   	push   edi
  548aa5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  548aaa:	33 c5                	xor    eax,ebp
  548aac:	50                   	push   eax
  548aad:	8d 45 f4             	lea    eax,[ebp-0xc]
  548ab0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  548ab6:	8b f9                	mov    edi,ecx
  548ab8:	83 7f 04 00          	cmp    DWORD PTR [edi+0x4],0x0
  548abc:	75 14                	jne    0x548ad2
  548abe:	33 c0                	xor    eax,eax
  548ac0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  548ac3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  548aca:	59                   	pop    ecx
  548acb:	5f                   	pop    edi
  548acc:	5e                   	pop    esi
  548acd:	5b                   	pop    ebx
  548ace:	8b e5                	mov    esp,ebp
  548ad0:	5d                   	pop    ebp
  548ad1:	c3                   	ret
  548ad2:	e8 e9 c7 ff ff       	call   0x5452c0
  548ad7:	8b 77 0c             	mov    esi,DWORD PTR [edi+0xc]
  548ada:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  548add:	85 f6                	test   esi,esi
  548adf:	74 3f                	je     0x548b20
  548ae1:	8b 86 58 01 00 00    	mov    eax,DWORD PTR [esi+0x158]
  548ae7:	33 db                	xor    ebx,ebx
  548ae9:	85 c0                	test   eax,eax
  548aeb:	74 03                	je     0x548af0
  548aed:	8b 58 30             	mov    ebx,DWORD PTR [eax+0x30]
  548af0:	8b ce                	mov    ecx,esi
  548af2:	e8 d9 13 f8 ff       	call   0x4c9ed0
  548af7:	85 db                	test   ebx,ebx
  548af9:	74 25                	je     0x548b20
  548afb:	85 c0                	test   eax,eax
  548afd:	75 21                	jne    0x548b20
  548aff:	8b 86 58 01 00 00    	mov    eax,DWORD PTR [esi+0x158]
  548b05:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  548b08:	83 f8 01             	cmp    eax,0x1
  548b0b:	74 05                	je     0x548b12
  548b0d:	83 f8 02             	cmp    eax,0x2
  548b10:	75 0e                	jne    0x548b20
  548b12:	8d 8f 88 00 00 00    	lea    ecx,[edi+0x88]
  548b18:	56                   	push   esi
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