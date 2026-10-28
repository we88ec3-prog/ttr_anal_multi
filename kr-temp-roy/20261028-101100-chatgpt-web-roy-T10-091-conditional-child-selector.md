# T10-091 — 0x761010 三個狀態 bit 的候選子物件選取規則

## 原始來源／驗證方式

- 對象：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本批於實際掛載檔重新計算且一致。
- `.text` 原生 VA `0x401000`、raw offset `0x400`，既有反組譯文字 `t10-full-disasm.txt` 由 KR BIN 的 `objdump` 產生；本段抽查來源指令，並以 VA 保存可重做的窗口。
- 靜態唯讀，不啟動／附加／修改客戶端；先前 T10-081～088 作查詢線索，不把先前推測升格為本段原生結論。
- 證據分級：**已確認**＝以下實際 x86 指令與控制流；**部分確認**＝受限路徑或候選物件；**尚待驗證**＝class／語義／間接 producer、callback、motion 行為。

## 主題：0x761010 是有條件遍歷器，而非固定子物件 accessor

### 完整已核對 selector 原始指令

```asm
  761010:	83 78 68 00          	cmp    DWORD PTR [eax+0x68],0x0
  761014:	56                   	push   esi
  761015:	57                   	push   edi
  761016:	74 34                	je     0x76104c
  761018:	8b 40 64             	mov    eax,DWORD PTR [eax+0x64]
  76101b:	8b 38                	mov    edi,DWORD PTR [eax]
  76101d:	3b c7                	cmp    eax,edi
  76101f:	74 2b                	je     0x76104c
  761021:	8b 70 04             	mov    esi,DWORD PTR [eax+0x4]
  761024:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  761027:	8b 49 28             	mov    ecx,DWORD PTR [ecx+0x28]
  76102a:	8b d1                	mov    edx,ecx
  76102c:	c1 ea 13             	shr    edx,0x13
  76102f:	f6 c2 01             	test   dl,0x1
  761032:	75 12                	jne    0x761046
  761034:	8b d1                	mov    edx,ecx
  761036:	c1 ea 08             	shr    edx,0x8
  761039:	f6 c2 01             	test   dl,0x1
  76103c:	74 08                	je     0x761046
  76103e:	c1 e9 0c             	shr    ecx,0xc
  761041:	f6 c1 01             	test   cl,0x1
  761044:	74 0b                	je     0x761051
  761046:	8b c6                	mov    eax,esi
  761048:	3b c7                	cmp    eax,edi
  76104a:	75 d5                	jne    0x761021
  76104c:	5f                   	pop    edi
  76104d:	33 c0                	xor    eax,eax
  76104f:	5e                   	pop    esi
  761050:	c3                   	ret
  761051:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  761054:	5f                   	pop    edi
  761055:	5e                   	pop    esi
  761056:	c3                   	ret
```

原生控制流：輸入物件由 `eax` 傳入；若 `[eax+0x68]==0` 返回 null。否則 `[eax+0x64]` 指向容器相關指標，經 `[eax]`、`[eax+4]` 取得 sentinel／節點，從 `[node+8]` 取候選物件；從 `[object+0x28]` 讀狀態整數。選擇條件為 bit19 **未設**、bit8 **設置**、bit12 **未設**，滿足則返回 `[node+8]`；不符合就按 `[node+4]` 前進直到 sentinel。以上位元值依實際 `shr`/`test`：`0x76102C shr 0x13`、`0x761036 shr 0x8`、`0x76103E shr 0xC`。需注意 bit19 的 test 結果若非零直接跳過，bit8 沒設亦跳過，bit12 設置亦跳過。

### 0x5961C0 caller 的輸入

```asm
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
```

T10-087 的 `0x5961ED mov eax,ebx`、`0x5961EF call 0x761010`，使候選對象來自 `ebx` 所指容器；若結果 null，後續子物件分派也可能走 fallback。這是明確的間接條件，不是「永遠一個玩家角色」。

### 查詢結果與 phase 消費的橋接

```asm
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
```

`0x596245 mov esi,edi` 把輸入 ID 寫入 reader 使用的寄存器，`0x59624E call 0x6D4CE0` 得 phase。phase=1 路徑查 `+0xEC`，phase=3 查 `+0xF0`；實際被選物件的 vptr 仍未得出，故尚未解出 override 的 target VA，更沒有到 motion action 的閉合證據。

## 重要反證與接續

- 新增確認：selector 不是純 getter，確實使用 3-bit predicate 篩選候選物件。
- 尚待驗證：`[eax+0x64/0x68]` 的類別及容器 owner；`node+8` 是否真正 AvatarBase；vtable+0xEC/+0xF0 implementations；motion／queue/cancel。
- 不將 T08 類別或 T11 skill object 的同名 offset 沒有指標歸屬前合併。