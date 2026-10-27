# T10-53 — 一般按鍵狀態全域位址完整直接參照盤點

- 編製時間：2026-10-28T02:12:36+08:00
- 標的：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 不執行
- 靜態驗證：原檔唯讀；PE `.text` VA 0x401000/raw 0x400，此列地址使用 VA−0x400C00 raw 換算
- 範圍：依 `kr/tasks/T10` 定義只研究輸入／普通攻擊／連段／取消的證據介面；技能施放屬 T11，傷害屬 T12
- 保守性：關鍵 x86 byte 重新由原始 BIN 取得；整函式 CFG、writer 無窮盡證明和 runtime 仍不成立

## 本段結論與證據範圍

`0xFB9004` 位址常數共七個直接命中，其中包含讀取、成批寫入與按索引寫零；已檢查的直接命中無法證明非零 writer 不存在。間接指標、不同 base 的等價位址及未定位的外部事件處理仍是缺口。

## `0xFB9004` 常數的 raw 命中逐項核對

| Raw offset | VA（同檔 `.text` 映射） | 對應指令類型（由附近 x86 定位） |
|---|---|---|
| `0x147D5A` | `0x54895A` | reader |
| `0x2CFC76` | `0x6D0876` | 初始化 DWORD 清零 |
| `0x2D0F03` | `0x6D1B03` | 刷新 DWORD 清零 |
| `0x2D3E9D` | `0x6D4A9D` | 批量清零 |
| `0x2D3F6C` | `0x6D4B6C` | 另一路批量清零 |
| `0x2D40B0` | `0x6D4CB0` | 特別鍵域相鄰寫零 |
| `0x2D419B` | `0x6D4D9B` | 索引讀取 |

**重要限制：** 此處為常數 byte-pattern census，不是 CFG/xref 完整性證明；附近指令需要從正確函式邊界解碼。

## 第一手 x86 反組譯摘錄

### VA `0x00548950` ／ raw `0x00147D50`（130 bytes）

```asm
  548950:	ff                   	(bad)
  548951:	ff 83 fe 27 77 57    	inc    DWORD PTR [ebx+0x577727fe]
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
```

### VA `0x006D0861` ／ raw `0x002CFC61`（105 bytes）

```asm
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
  6d08c1:	68 90 82 41 00       	push   0x418290
  6d08c6:	68                   	.byte 0x68
  6d08c7:	30                   	.byte 0x30
  6d08c8:	93                   	xchg   ebx,eax
  6d08c9:	68                   	.byte 0x68
```

### VA `0x006D1AFB` ／ raw `0x002D0EFB`（85 bytes）

```asm
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
```

### VA `0x006D4A93` ／ raw `0x002D3E93`（95 bytes）

```asm
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
  6d4aee:	bf                   	.byte 0xbf
  6d4aef:	30 f6                	xor    dh,dh
  6d4af1:	fd                   	std
```

### VA `0x006D4B69` ／ raw `0x002D3F69`（90 bytes）

```asm
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
  6d4bc2:	83                   	.byte 0x83
```

### VA `0x006D4CAE` ／ raw `0x002D40AE`（80 bytes）

```asm
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
  6d4cce:	8b e5                	mov    esp,ebp
  6d4cd0:	5d                   	pop    ebp
  6d4cd1:	c3                   	ret
  6d4cd2:	cc                   	int3
  6d4cd3:	cc                   	int3
  6d4cd4:	cc                   	int3
  6d4cd5:	cc                   	int3
  6d4cd6:	cc                   	int3
  6d4cd7:	cc                   	int3
  6d4cd8:	cc                   	int3
  6d4cd9:	cc                   	int3
  6d4cda:	cc                   	int3
  6d4cdb:	cc                   	int3
  6d4cdc:	cc                   	int3
  6d4cdd:	cc                   	int3
  6d4cde:	cc                   	int3
  6d4cdf:	cc                   	int3
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
  6d4cfc:	8d                   	.byte 0x8d
  6d4cfd:	45                   	inc    ebp
```

### VA `0x006D4D93` ／ raw `0x002D4193`（60 bytes）

```asm
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
  6d4dca:	64                   	fs
  6d4dcb:	a1                   	.byte 0xa1
  6d4dcc:	00 00                	add    BYTE PTR [eax],al
	...
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