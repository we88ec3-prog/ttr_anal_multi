# T10-54 — 一般鍵域多處寫零的順序與生命週期界限

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

`0x6D0875`、`0x6D1B02`、`0x6D4A9C`、`0x6D4B6B` 有不同路徑寫 `0xFB9004`。必須依各自 caller 和前置條件分離，不是同一個輸入事件 writer，不能將清零視為 V 放開、動作取消或按鍵釋放。

## 第一手 x86 反組譯摘錄

### VA `0x006D0750` ／ raw `0x002CFB50`（140 bytes）

```asm
  6d0750:	55                   	push   ebp
  6d0751:	8b ec                	mov    ebp,esp
  6d0753:	6a ff                	push   0xffffffff
  6d0755:	68 e5 28 92 00       	push   0x9228e5
  6d075a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d0760:	50                   	push   eax
  6d0761:	51                   	push   ecx
  6d0762:	53                   	push   ebx
  6d0763:	56                   	push   esi
  6d0764:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d0769:	33 c5                	xor    eax,ebp
  6d076b:	50                   	push   eax
  6d076c:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d076f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d0775:	68 e0 08 6d 00       	push   0x6d08e0
  6d077a:	68 c0 08 6d 00       	push   0x6d08c0
  6d077f:	6a 03                	push   0x3
  6d0781:	68 80 02 00 00       	push   0x280
  6d0786:	33 f6                	xor    esi,esi
  6d0788:	68 34 88 fb 00       	push   0xfb8834
  6d078d:	c7 45 f0 30 88 fb 00 	mov    DWORD PTR [ebp-0x10],0xfb8830
  6d0794:	89 35 30 88 fb 00    	mov    DWORD PTR ds:0xfb8830,esi
  6d079a:	e8 64 18 1c 00       	call   0x892003
  6d079f:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6d07a2:	89 35 2c 90 fb 00    	mov    DWORD PTR ds:0xfb902c,esi
  6d07a8:	89 35 30 90 fb 00    	mov    DWORD PTR ds:0xfb9030,esi
  6d07ae:	89 35 34 90 fb 00    	mov    DWORD PTR ds:0xfb9034,esi
  6d07b4:	89 35 3c 90 fb 00    	mov    DWORD PTR ds:0xfb903c,esi
  6d07ba:	89 35 40 90 fb 00    	mov    DWORD PTR ds:0xfb9040,esi
  6d07c0:	89 35 44 90 fb 00    	mov    DWORD PTR ds:0xfb9044,esi
  6d07c6:	bb 01 00 00 00       	mov    ebx,0x1
  6d07cb:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  6d07ce:	e8 1d 01 00 00       	call   0x6d08f0
  6d07d3:	84 1d 28 88 fb 00    	test   BYTE PTR ds:0xfb8828,bl
  6d07d9:	75 1f                	jne    0x6d07fa
  6d07db:	09                   	.byte 0x9
```

### VA `0x006D0835` ／ raw `0x002CFC35`（140 bytes）

```asm
  6d0835:	d0 8f fb 00 a3 d4    	ror    BYTE PTR [edi-0x2b5cff05],1
  6d083b:	8f                   	(bad)
  6d083c:	fb                   	sti
  6d083d:	00 a3 d8 8f fb 00    	add    BYTE PTR [ebx+0xfb8fd8],ah
  6d0843:	a3 dc 8f fb 00       	mov    ds:0xfb8fdc,eax
  6d0848:	a3 e0 8f fb 00       	mov    ds:0xfb8fe0,eax
  6d084d:	a3 e4 8f fb 00       	mov    ds:0xfb8fe4,eax
  6d0852:	a3 e8 8f fb 00       	mov    ds:0xfb8fe8,eax
  6d0857:	a3 ec 8f fb 00       	mov    ds:0xfb8fec,eax
  6d085c:	a3 f0 8f fb 00       	mov    ds:0xfb8ff0,eax
  6d0861:	a3 f4 8f fb 00       	mov    ds:0xfb8ff4,eax
  6d0866:	a3 f8 8f fb 00       	mov    ds:0xfb8ff8,eax
  6d086b:	a3 fc 8f fb 00       	mov    ds:0xfb8ffc,eax
  6d0870:	a3 00 90 fb 00       	mov    ds:0xfb9000,eax
  6d0875:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d087a:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d087f:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d0884:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d0889:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d088e:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d0893:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d0898:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d089d:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d08a2:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d08a7:	b8 30 88 fb 00       	mov    eax,0xfb8830
  6d08ac:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d08af:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d08b6:	59                   	pop    ecx
  6d08b7:	5e                   	pop    esi
  6d08b8:	5b                   	pop    ebx
  6d08b9:	8b e5                	mov    esp,ebp
  6d08bb:	5d                   	pop    ebp
  6d08bc:	c3                   	ret
  6d08bd:	cc                   	int3
  6d08be:	cc                   	int3
  6d08bf:	cc                   	int3
  6d08c0:	56                   	push   esi
```

### VA `0x006D1AE0` ／ raw `0x002D0EE0`（140 bytes）

```asm
  6d1ae0:	04 8a                	add    al,0x8a
  6d1ae2:	0d eb 91 fb 00       	or     eax,0xfb91eb
  6d1ae7:	8a c3                	mov    al,bl
  6d1ae9:	3a d9                	cmp    bl,cl
  6d1aeb:	76 02                	jbe    0x6d1aef
  6d1aed:	8a c1                	mov    al,cl
  6d1aef:	8a 0d ea 91 fb 00    	mov    cl,BYTE PTR ds:0xfb91ea
  6d1af5:	3a c1                	cmp    al,cl
  6d1af7:	73 02                	jae    0x6d1afb
  6d1af9:	8a c1                	mov    al,cl
  6d1afb:	a2 e9 91 fb 00       	mov    ds:0xfb91e9,al
  6d1b00:	33 c0                	xor    eax,eax
  6d1b02:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d1b07:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d1b0c:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d1b11:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d1b16:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d1b1b:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d1b20:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d1b25:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d1b2a:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d1b2f:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d1b34:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d1b37:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d1b3e:	59                   	pop    ecx
  6d1b3f:	5b                   	pop    ebx
  6d1b40:	8b e5                	mov    esp,ebp
  6d1b42:	5d                   	pop    ebp
  6d1b43:	c2 04 00             	ret    0x4
  6d1b46:	cc                   	int3
  6d1b47:	cc                   	int3
  6d1b48:	cc                   	int3
  6d1b49:	cc                   	int3
  6d1b4a:	cc                   	int3
  6d1b4b:	cc                   	int3
  6d1b4c:	cc                   	int3
  6d1b4d:	cc                   	int3
  6d1b4e:	cc                   	int3
  6d1b4f:	cc                   	int3
  6d1b50:	55                   	push   ebp
  6d1b51:	8b ec                	mov    ebp,esp
  6d1b53:	83 ec 08             	sub    esp,0x8
  6d1b56:	56                   	push   esi
  6d1b57:	68 f0 08 c4 00       	push   0xc408f0
  6d1b5c:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d1b5f:	68 d8 08 c4 00       	push   0xc408d8
  6d1b64:	33 f6                	xor    esi,esi
  6d1b66:	50                   	push   eax
  6d1b67:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6d1b6a:	e8                   	.byte 0xe8
  6d1b6b:	23                   	.byte 0x23
```

### VA `0x006D4A30` ／ raw `0x002D3E30`（190 bytes）

```asm
  6d4a30:	55                   	push   ebp
  6d4a31:	8b ec                	mov    ebp,esp
  6d4a33:	6a ff                	push   0xffffffff
  6d4a35:	68 f0 68 92 00       	push   0x9268f0
  6d4a3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d4a40:	50                   	push   eax
  6d4a41:	83 ec 0c             	sub    esp,0xc
  6d4a44:	53                   	push   ebx
  6d4a45:	56                   	push   esi
  6d4a46:	57                   	push   edi
  6d4a47:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d4a4c:	33 c5                	xor    eax,ebp
  6d4a4e:	50                   	push   eax
  6d4a4f:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d4a52:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d4a58:	83 cb ff             	or     ebx,0xffffffff
  6d4a5b:	80 7d 08 00          	cmp    BYTE PTR [ebp+0x8],0x0
  6d4a5f:	8d 73 02             	lea    esi,[ebx+0x2]
  6d4a62:	0f 84 a2 00 00 00    	je     0x6d4b0a
  6d4a68:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4a6f:	75 22                	jne    0x6d4a93
  6d4a71:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4a77:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d4a7e:	e8 cd bc ff ff       	call   0x6d0750
  6d4a83:	68 30 d5 bc 00       	push   0xbcd530
  6d4a88:	e8 8d d8 1b 00       	call   0x89231a
  6d4a8d:	83 c4 04             	add    esp,0x4
  6d4a90:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4a93:	33 c0                	xor    eax,eax
  6d4a95:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4a9c:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4aa1:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4aa6:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4aab:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4ab0:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4ab5:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4aba:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4abf:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4ac4:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4ac9:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d4ace:	75 1e                	jne    0x6d4aee
  6d4ad0:	09 35 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,esi
  6d4ad6:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6d4ad9:	e8 c2 d2 ff ff       	call   0x6d1da0
  6d4ade:	68 30 e3 bc 00       	push   0xbce330
  6d4ae3:	e8 32 d8 1b 00       	call   0x89231a
  6d4ae8:	83 c4 04             	add    esp,0x4
  6d4aeb:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
```

### VA `0x006D4B20` ／ raw `0x002D3F20`（180 bytes）

```asm
  6d4b20:	e8 2b bc ff ff       	call   0x6d0750
  6d4b25:	68 30 d5 bc 00       	push   0xbcd530
  6d4b2a:	e8 eb d7 1b 00       	call   0x89231a
  6d4b2f:	83 c4 04             	add    esp,0x4
  6d4b32:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4b35:	83 3d 30 88 fb 00 00 	cmp    DWORD PTR ds:0xfb8830,0x0
  6d4b3c:	74 5f                	je     0x6d4b9d
  6d4b3e:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4b45:	75 22                	jne    0x6d4b69
  6d4b47:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4b4d:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  6d4b54:	e8 f7 bb ff ff       	call   0x6d0750
  6d4b59:	68 30 d5 bc 00       	push   0xbcd530
  6d4b5e:	e8 b7 d7 1b 00       	call   0x89231a
  6d4b63:	83 c4 04             	add    esp,0x4
  6d4b66:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4b69:	33 c0                	xor    eax,eax
  6d4b6b:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4b70:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4b75:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4b7a:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4b7f:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4b84:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4b89:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4b8e:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4b93:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4b98:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d4b9d:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4ba4:	75 22                	jne    0x6d4bc8
  6d4ba6:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4bac:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  6d4bb3:	e8 98 bb ff ff       	call   0x6d0750
  6d4bb8:	68 30 d5 bc 00       	push   0xbcd530
  6d4bbd:	e8 58 d7 1b 00       	call   0x89231a
  6d4bc2:	83 c4 04             	add    esp,0x4
  6d4bc5:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4bc8:	83 3d 30 88 fb 00 00 	cmp    DWORD PTR ds:0xfb8830,0x0
  6d4bcf:	74 35                	je     0x6d4c06
  6d4bd1:	f6                   	.byte 0xf6
  6d4bd2:	05                   	.byte 0x5
  6d4bd3:	ec                   	in     al,dx
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