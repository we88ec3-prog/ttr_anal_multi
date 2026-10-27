# KR T10-11 — 0x546B50 裝置狀態、邊沿旗標與方向產生

日期：2026-10-27（Asia/Taipei）。客戶端：KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；採原始 BIN 唯讀反組譯，不執行或修改客戶端。`.text` VA `0x00401000` 對應 raw `0x400`；以下為 x86 VA，無原生符號的名稱皆屬暫稱。依使用者提出的「Z 連按」及「Z 按住不放」進行追查，不將使用者行為描述倒推為程式語義。

## 問題
`0x546B50` 是 `0x546780` 即時合流的第二路。確認其狀態來源、邊沿記錄、阻擋條件及返回值，避免將所有 output mask 都誤歸於 Z 長按。

## 新證據
- `[0xFBA80C]` 為懶初始化全域指標；為空時配置 `0x57C` bytes 並呼叫 `0x6F1370`。
- 讀取 `[0xFB1318]`，在 `+0xC01C` 測 bit 0 與 bit 1，控制是否可以繼續某個裝置輸入分支。
- `[edi+0x7C]` 與 `[edi+0x80]` 被反覆清零、比較及變更；`0x546C03..0x546C24` 利用全域 `0xFE1E20` 做一次性邊沿門檻及狀態翻轉。不能直接命名為 Z keypress。
- `0x546BC3` 檢查 caller 第三參數，不為 0 時清 `+7C/+80` 並返回 0；這是可確認的 gate。
- `0x546C79..0x546D39` 經 vtable `+0x4C`、`0x434740`、`0x79A6B0`，以座標差和三角函式 `0x8FEDCA`、`0x4BB450` 產生輸出 byte，顯示存在畫面／指標座標式方向候選路徑。確切 UI 裝置和座標空間待確認。

### 原始 BIN 節錄：一次性狀態與 gate
```asm
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
```
```asm
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
  546c03:	b9 01 00 00 00       	mov    ecx,0x1
  546c08:	89 0d 20 1e fe 00    	mov    DWORD PTR ds:0xfe1e20,ecx
  546c0e:	2b 8f 80 00 00 00    	sub    ecx,DWORD PTR [edi+0x80]
  546c14:	8b d3                	mov    edx,ebx
  546c16:	0f 95 c2             	setne  dl
  546c19:	89 8f 80 00 00 00    	mov    DWORD PTR [edi+0x80],ecx
  546c1f:	89 57 7c             	mov    DWORD PTR [edi+0x7c],edx
  546c22:	eb 06                	jmp    0x546c2a
  546c24:	89 1d 20 1e fe 00    	mov    DWORD PTR ds:0xfe1e20,ebx
  546c2a:	39 5f 7c             	cmp    DWORD PTR [edi+0x7c],ebx
  546c2d:	74 9c                	je     0x546bcb
  546c2f:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  546c32:	75 07                	jne    0x546c3b
  546c34:	05 70 03 00 00       	add    eax,0x370
  546c39:	eb 05                	jmp    0x546c40
  546c3b:	05 60 03 00 00       	add    eax,0x360
  546c40:	38 18                	cmp    BYTE PTR [eax],bl
  546c42:	75 16                	jne    0x546c5a
  546c44:	39 9f 80 00 00 00    	cmp    DWORD PTR [edi+0x80],ebx
  546c4a:	75 0e                	jne    0x546c5a
  546c4c:	89 5f 7c             	mov    DWORD PTR [edi+0x7c],ebx
  546c4f:	33 c0                	xor    eax,eax
  546c51:	5f                   	pop    edi
  546c52:	5e                   	pop    esi
  546c53:	5b                   	pop    ebx
  546c54:	8b e5                	mov    esp,ebp
  546c56:	5d                   	pop    ebp
  546c57:	c2 0c 00             	ret    0xc
```

### 原始 BIN 節錄：指標座標角度
```asm
546c79:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  546c7c:	8b 01                	mov    eax,DWORD PTR [ecx]
  546c7e:	8b 50 4c             	mov    edx,DWORD PTR [eax+0x4c]
  546c81:	ff d2                	call   edx
  546c83:	50                   	push   eax
  546c84:	51                   	push   ecx
  546c85:	e8 b6 da ee ff       	call   0x434740
  546c8a:	83 c4 04             	add    esp,0x4
  546c8d:	50                   	push   eax
  546c8e:	8d 7c 24 28          	lea    edi,[esp+0x28]
  546c92:	e8 19 3a 25 00       	call   0x79a6b0
  546c97:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  546c9c:	db 80 0c c0 00 00    	fild   DWORD PTR [eax+0xc00c]
  546ca2:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  546ca6:	db 80 10 c0 00 00    	fild   DWORD PTR [eax+0xc010]
  546cac:	8d 44 24 18          	lea    eax,[esp+0x18]
  546cb0:	50                   	push   eax
  546cb1:	8b c8                	mov    ecx,eax
  546cb3:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  546cb7:	51                   	push   ecx
  546cb8:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  546cbc:	d8 64 24 28          	fsub   DWORD PTR [esp+0x28]
  546cc0:	d9 5c 24 20          	fstp   DWORD PTR [esp+0x20]
  546cc4:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  546cc8:	d8 64 24 2c          	fsub   DWORD PTR [esp+0x2c]
  546ccc:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  546cd0:	ff 15 f8 25 bd 00    	call   DWORD PTR ds:0xbd25f8
  546cd6:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  546cda:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  546cde:	e8 e7 80 3b 00       	call   0x8fedca
```
```asm
546d0b:	e8 40 47 f7 ff       	call   0x4bb450
  546d10:	83 c4 04             	add    esp,0x4
  546d13:	8a d8                	mov    bl,al
  546d15:	e8 26 da ee ff       	call   0x434740
  546d1a:	8b 50 40             	mov    edx,DWORD PTR [eax+0x40]
  546d1d:	d9 42 20             	fld    DWORD PTR [edx+0x20]
  546d20:	51                   	push   ecx
  546d21:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  546d25:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  546d29:	d9 1c 24             	fstp   DWORD PTR [esp]
  546d2c:	e8 1f 47 f7 ff       	call   0x4bb450
  546d31:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  546d34:	83 c4 04             	add    esp,0x4
  546d37:	02 c3                	add    al,bl
  546d39:	88 01                	mov    BYTE PTR [ecx],al
  546d3b:	5f                   	pop    edi
  546d3c:	5e                   	pop    esi
  546d3d:	b8 01 00 00 00       	mov    eax,0x1
  546d42:	5b                   	pop    ebx
  546d43:	8b e5                	mov    esp,ebp
  546d45:	5d                   	pop    ebp
  546d46:	c2                   	.byte 0xc2
```

## 結論與否定
**已確認**：多個全域/控制器 gate，及使用位置資料產生 byte 方向的處理。
**合理推測**：這可能是指標／滑鼠取向分支，但原始符號、IAT 與來源還需驗證。
**未證實**：此 branch 是 Z 連按的 edge consumer、`[edi+0x80]` 是普攻 combo index、global `0xFE1E20` 是按鍵 debounce。

```cpp
bool secondaryInput(Control* c, Obj* actor, uint8_t* direction, bool block) {
  if (block) { c->flag7C=0; c->state80=0; return false; }
  if (!passesDeviceGate()) { c->flag7C=0; return false; }
  if (needsDirection()) *direction=quantizeAngleFromPosition();
  return true; // 僅表達結構，非逐分支對等還原
}
```

下一段 T10-12 研究第三路 `0x546D50` 的差異，完成這批非 Z 分支的證據邊界及待追查優先序。