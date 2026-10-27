# KR T08-159 — actor virtual cleanup and erase order

- 研究時間：2026-10-28T01:52:16+08:00（Asia/Taipei）；研究者：`chatgpt-web roy`。
- 第一手來源：唯讀 `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，GNU objdump 對 PE `.text` VA 反組譯。
- 正式 Task：GitHub KR T08 只負責 `0007` 實體建立／登記／移除的資料介面；dispatch 框架屬 T02、場景重置屬 T06/T07，僅交叉參照，不更動其他任務。
- 分級：**原始 bytes**／**已證局部 data-flow**／**有條件推論**／**未知**。線性反組譯與直接呼叫搜尋不代表完整 CFG；外部封包來源與 runtime 未驗證。
- 參照：`T08-153`、`T08-154`、`T08-155`、`T08-156`；上批保留的映射差異與 `T01-20261027-05` 部分驗收限制持續適用。
- 無遊戲執行、修改主程式、服務或存檔。本文不是可直接部署的 C++ 原始碼。

## 分析範圍

本段重讀 `0x4DFBC0`、`0x4DFC30`、`0x4DFD40`、`0x4DFE90` 的原生 call order，比較 actor 清理虛擬方法和節點釋放；不因 vtable slot index 類似就升級成 `CMonster::~CMonster` 正式名稱。尤其補上**無節點、空 payload 的錯誤分支風險**，以及樹 helper 與物件清除分離。

### 1. 依 ID 先解控制器槽、再處理物件、最後刪節點

```asm
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04              	ret    0x4
```

- `4DFBCF` push stack address 當 search key；`4DFBD5 call 82EF00`，`4DFBDD..E0` sentinel equal 時直跳尾端，不作其餘處理。
- 找到節點後 `4DFBE4..4DFBF6` 固定三次對 `[0xFBA7A4]` controller vptr+0x1C 做間接呼叫；這是**所有找到 key 的路徑**的副作用，不是只在 actor kind 1 才發生。
- `4DFBF8` 讀 node+0x10 **沒有先測試 null**，即取 `[ecx]` 以執行 vtable +0x14；因此必須保留資料結構 `payload` 非空的**前置條件**。`4DFC02` 後測 null 是第二步，不能拿此 null check 保證前一個 virtual call 安全。
- vtable+0x14 呼叫後再發出 vtable+0x00 且 push 1，清掉 node payload pointer，最後 `4DFC1E call 7B6890` 只移除 tree node。

限定生命期順序：`find(key) -> controller-slot v1C(3次) -> actor.virtual+14 -> actor.virtual+0(1) -> node+10=0 -> RB erase`。若外部引用依舊持有指標、虛擬函式有額外引用計數，不能由此宣告「無 UAF 風險」或「一定完全 free」。

### 2. 第二棵樹的 erase 路徑並不相同

```asm
  4dfc30:	55                   	push   ebp
  4dfc31:	8b ec                	mov    ebp,esp
  4dfc33:	51                   	push   ecx
  4dfc34:	53                   	push   ebx
  4dfc35:	57                   	push   edi
  4dfc36:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfc39:	8d 5e 18             	lea    ebx,[esi+0x18]
  4dfc3c:	50                   	push   eax
  4dfc3d:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfc40:	8b cb                	mov    ecx,ebx
  4dfc42:	e8 79 3c 36 00       	call   0x8438c0
  4dfc47:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfc4a:	3b 7e 1c             	cmp    edi,DWORD PTR [esi+0x1c]
  4dfc4d:	74 36                	je     0x4dfc85
  4dfc4f:	8b 86 f8 00 00 00    	mov    eax,DWORD PTR [esi+0xf8]
  4dfc55:	85 c0                	test   eax,eax
  4dfc57:	74 11                	je     0x4dfc6a
  4dfc59:	8b 08                	mov    ecx,DWORD PTR [eax]
  4dfc5b:	3b 4d 08             	cmp    ecx,DWORD PTR [ebp+0x8]
  4dfc5e:	75 0a                	jne    0x4dfc6a
  4dfc60:	c7 86 f8 00 00 00 00 	mov    DWORD PTR [esi+0xf8],0x0
  4dfc67:	00 00 00 
  4dfc6a:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  4dfc6d:	85 c0                	test   eax,eax
  4dfc6f:	74 09                	je     0x4dfc7a
  4dfc71:	50                   	push   eax
  4dfc72:	e8 95 15 3b 00       	call   0x89120c
  4dfc77:	83 c4 04             	add    esp,0x4
  4dfc7a:	57                   	push   edi
  4dfc7b:	8d 55 08             	lea    edx,[ebp+0x8]
  4dfc7e:	52                   	push   edx
  4dfc7f:	53                   	push   ebx
  4dfc80:	e8 0b 6c 2d 00       	call   0x7b6890
  4dfc85:	5f                   	pop    edi
  4dfc86:	5b                   	pop    ebx
  4dfc87:	8b e5                	mov    esp,ebp
  4dfc89:	5d                   	pop    ebp
  4dfc8a:	c2 04              	ret    0x4
```

`4DFC30` 以 `esi+0x18` 的另一樹作查找；如果 `esi+0xF8` 的關聯資料與 key 一致就先清指標；`node+0x10` 的值非空則直接 `0x89120C` free（沒有 actor vtable+0/+14），再交相同 `7B6890` 處理 node。不能把它與 `GameInfo+8` 的物件生命期合併。

### 3. 類型移除與整表清理差異

```asm
  4dfd40:	55                   	push   ebp
  4dfd41:	8b ec                	mov    ebp,esp
  4dfd43:	83 e4 f8             	and    esp,0xfffffff8
  4dfd46:	83 ec 18             	sub    esp,0x18
  4dfd49:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  4dfd4c:	83 c1 08             	add    ecx,0x8
  4dfd4f:	56                   	push   esi
  4dfd50:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfd52:	57                   	push   edi
  4dfd53:	89 4c 24 08          	mov    DWORD PTR [esp+0x8],ecx
  4dfd57:	3b f0                	cmp    esi,eax
  4dfd59:	0f 84 23 01 00 00    	je     0x4dfe82
  4dfd5f:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfd66:	00 
  4dfd67:	eb 07                	jmp    0x4dfd70
  4dfd69:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfd70:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4dfd73:	0f b6 50 04          	movzx  edx,BYTE PTR [eax+0x4]
  4dfd77:	66 3b 55 08          	cmp    dx,WORD PTR [ebp+0x8]
  4dfd7b:	0f 85 b8 00 00 00    	jne    0x4dfe39
  4dfd81:	8b f8                	mov    edi,eax
  4dfd83:	85 ff                	test   edi,edi
  4dfd85:	74 72                	je     0x4dfdf9
  4dfd87:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dfd8b:	3c 01                	cmp    al,0x1
  4dfd8d:	74 0c                	je     0x4dfd9b
  4dfd8f:	3c 06                	cmp    al,0x6
  4dfd91:	74 08                	je     0x4dfd9b
  4dfd93:	84 c0                	test   al,al
  4dfd95:	74 04                	je     0x4dfd9b
  4dfd97:	3c 07                	cmp    al,0x7
  4dfd99:	75 5e                	jne    0x4dfdf9
  4dfd9b:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfda1:	f3 0f 11 44 24 10    	movss  DWORD PTR [esp+0x10],xmm0
  4dfda7:	f3 0f 11 44 24 14    	movss  DWORD PTR [esp+0x14],xmm0
  4dfdad:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  4dfdb3:	f3 0f 11 44 24 1c    	movss  DWORD PTR [esp+0x1c],xmm0
  4dfdb9:	85 c0                	test   eax,eax
  4dfdbb:	74 3c                	je     0x4dfdf9
  4dfdbd:	83 bf 70 03 00 00 00 	cmp    DWORD PTR [edi+0x370],0x0
  4dfdc4:	74 33                	je     0x4dfdf9
  4dfdc6:	6a 00                	push   0x0
  4dfdc8:	50                   	push   eax
  4dfdc9:	e8 f2 7e 2c 00       	call   0x7a7cc0
  4dfdce:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4dfdd2:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4dfdd6:	83 ec 10             	sub    esp,0x10
  4dfdd9:	8b c4                	mov    eax,esp
  4dfddb:	89 08                	mov    DWORD PTR [eax],ecx
  4dfddd:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4dfde1:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4dfde4:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  4dfde8:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4dfdeb:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4dfdee:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfdf4:	e8 f7 7d 2c 00       	call   0x7a7bf0
  4dfdf9:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfdfc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfdfe:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfe01:	ff d2                	call   edx
  4dfe03:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfe06:	85 c9                	test   ecx,ecx
  4dfe08:	74 0f                	je     0x4dfe19
  4dfe0a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfe0c:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfe0e:	6a 01                	push   0x1
  4dfe10:	ff d2                	call   edx
  4dfe12:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfe19:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe1d:	56                   	push   esi
  4dfe1e:	8d 44 24 10          	lea    eax,[esp+0x10]
  4dfe22:	50                   	push   eax
  4dfe23:	51                   	push   ecx
  4dfe24:	e8 67 6a 2d 00       	call   0x7b6890
  4dfe29:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe2b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfe32:	00 
  4dfe33:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe37:	eb 40                	jmp    0x4dfe79
  4dfe39:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfe3d:	75 3a                	jne    0x4dfe79
  4dfe3f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfe42:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe46:	75 16                	jne    0x4dfe5e
  4dfe48:	8b f0                	mov    esi,eax
  4dfe4a:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe4c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe50:	75 27                	jne    0x4dfe79
  4dfe52:	8b f0                	mov    esi,eax
  4dfe54:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe56:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe5a:	74 f6                	je     0x4dfe52
  4dfe5c:	eb 1b                	jmp    0x4dfe79
  4dfe5e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfe61:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe65:	75 10                	jne    0x4dfe77
  4dfe67:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfe6a:	75 0b                	jne    0x4dfe77
  4dfe6c:	8b f0                	mov    esi,eax
  4dfe6e:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfe71:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe75:	74 f0                	je     0x4dfe67
  4dfe77:	8b f0                	mov    esi,eax
  4dfe79:	3b 71 04             	cmp    esi,DWORD PTR [ecx+0x4]
  4dfe7c:	0f 85 ee fe ff ff    	jne    0x4dfd70
  4dfe82:	5f                   	pop    edi
  4dfe83:	5e                   	pop    esi
  4dfe84:	8b e5                	mov    esp,ebp
  4dfe86:	5d                   	pop    ebp
  4dfe87:	c2 04 00             	ret    0x4
  4dfe8a:	cc                   	int3
  4dfe8b:	cc                   	int3
  4dfe8c:	cc                   	int3
  4dfe8d:	cc                   	int3
  4dfe8e:	cc                   	int3
  4dfe8f:	cc                   	int3
```

```asm
  4dfe90:	55                   	push   ebp
  4dfe91:	8b ec                	mov    ebp,esp
  4dfe93:	53                   	push   ebx
  4dfe94:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dfe97:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  4dfe9a:	56                   	push   esi
  4dfe9b:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe9d:	57                   	push   edi
  4dfe9e:	3b f0                	cmp    esi,eax
  4dfea0:	74 65                	je     0x4dff07
  4dfea2:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  4dfea5:	85 ff                	test   edi,edi
  4dfea7:	74 13                	je     0x4dfebc
  4dfea9:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeab:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfeae:	8b cf                	mov    ecx,edi
  4dfeb0:	ff d2                	call   edx
  4dfeb2:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeb4:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfeb6:	6a 01                	push   0x1
  4dfeb8:	8b cf                	mov    ecx,edi
  4dfeba:	ff d2                	call   edx
  4dfebc:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfec0:	75 40                	jne    0x4dff02
  4dfec2:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfec5:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfec9:	75 16                	jne    0x4dfee1
  4dfecb:	8b f0                	mov    esi,eax
  4dfecd:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfecf:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfed3:	75 2d                	jne    0x4dff02
  4dfed5:	8b f0                	mov    esi,eax
  4dfed7:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfed9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfedd:	74 f6                	je     0x4dfed5
  4dfedf:	eb 21                	jmp    0x4dff02
  4dfee1:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfee4:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfee8:	75 16                	jne    0x4dff00
  4dfeea:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4dfef0:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfef3:	75 0b                	jne    0x4dff00
  4dfef5:	8b f0                	mov    esi,eax
  4dfef7:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfefa:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfefe:	74 f0                	je     0x4dfef0
  4dff00:	8b f0                	mov    esi,eax
  4dff02:	3b 73 0c             	cmp    esi,DWORD PTR [ebx+0xc]
  4dff05:	75 9b                	jne    0x4dfea2
  4dff07:	8d 7b 08             	lea    edi,[ebx+0x8]
  4dff0a:	e8 41 39 34 00       	call   0x823850
  4dff0f:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dff15:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dff17:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dff1a:	ff d2                	call   edx
  4dff1c:	5f                   	pop    edi
  4dff1d:	5e                   	pop    esi
  4dff1e:	5b                   	pop    ebx
  4dff1f:	5d                   	pop    ebp
  4dff20:	c2 04 00             	ret    0x4
  4dff23:	cc                   	int3
  4dff24:	cc                   	int3
  4dff25:	cc                   	int3
  4dff26:	cc                   	int3
  4dff27:	cc                   	int3
  4dff28:	cc                   	int3
  4dff29:	cc                   	int3
  4dff2a:	cc                   	int3
```

`4DFD40` 是按條件遍歷的批次移除，會讀 `actor+4` 類型 byte，再根據不同分支調用 virtual 和 node erase；不能憑迴圈調用就認為呼叫了 `4DFBC0` 同樣三次 controller slot reset。`4DFE90` 清全表時的容器清理 helper 不等於 `4DFBC0` 的單鍵刪除；需分開列明哪條路徑會額外解除控制器引用。

### 4. 虛擬函式身分仍需獨立證明

| 呼叫 | 確認 | 目前未知 |
|---|---|---|
| controller vptr +0x1C | 4DFBC0 內三槽循環直接指令 | 哪些 controller 實例、slot 與 actor ID 對應 |
| actor vptr +0x14 | 讀 vptr 再間接 call | CMonster / CCharacter / CEventObject 對各具體 vtable 的 callee |
| actor vptr +0x00(1) | 帶整數 1 的虛擬調用 | 是否 scalar deleting destructor、實際 free owner 路線 |
| 7B6890 | node unlink/balance/free，見 T08-155 | 不保證任何 actor deallocation |
| 823850 | 批次容器清空節點 | 是否呼叫 payload cleanup 視 caller 前序而定 |

### 5. 保守偽碼

```cpp
void removeById(GameInfoLike *g, uint16_t id) {
    Node *n = find(g->actorTree, id);
    if (n == g->actorTree.end) return;
    Actor *p = n->payload; // 限定此原生分支預期非空
    for (int slot=0; slot<3; ++slot) g_controller->virtual1C(slot);
    p->virtual14();
    if (p) { p->virtual0(1); n->payload = nullptr; }
    eraseTreeNode(g->actorTree, n);
}
```

此偽碼**不等於**官方類別辨識、完整異常處理、動態分派還原。後續需抽取實際 actor vtable 的 scalar deleting destructor 以驗證 delete flag=1 是否表示 free。採用 BIN 中有效函式入口，不能任選 flat/PE 指令表。

## 下一步

T08-160 整理新修正與可提交的限定結論，建立跨 task provenance；後續 T08-161 可集中比較 vtable+0x14 具體 class 或追 T02 dispatch 表。