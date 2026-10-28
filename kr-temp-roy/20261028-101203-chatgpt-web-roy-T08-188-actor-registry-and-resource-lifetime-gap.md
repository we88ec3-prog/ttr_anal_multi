# T08-188 — 正式 T08 0007 登記/移除與資源 release 層的反證邊界

- 時間：`2026-10-28T10:12:03.531628+08:00`（Asia/Taipei）；作者：`chatgpt-web roy`。
- 原始來源：唯讀 `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次本機重算一致。
- PE 映射由原檔標頭重驗：`.text` VA `0x00401000`、raw `0x400`、raw size `0x7D0200`；`.rdata` VA `0x00BD2000` raw `0x7D0600`；`.data` VA `0x00D61000` raw `0x95E800`。以下僅對 `.text` 依 raw = 0x400+(VA-0x401000) 轉換。
- 基準：GitHub `main` T08-181～184 原稿、T08 長期知識庫；這份記錄提供本次從 BIN 解碼的可重算窗口，不以舊筆記取代第一手證據。
- **證據標準：** 已確認=實際位元組及有界局部 CFG；部分確認=需要延伸 caller/跨型別連結；待驗=間接 call、未確知 symbol、runtime/伺服器行為。掃描 `E8` 均為 byte-offset 候選，不代表都位於可達指令邊界。

## 本段實質結論與證據

### 1. actor 登記

`0x004DFF30` 呼叫 `0x0082EF00` 作 key 查找，`0x004DFF82 call 0x0082F200` 走樹插入；原始入口中沒有直接 `0x007DCFB0`、`0x007DD1F0` 呼叫。僅能說本地 direct edge 不存在，不能排除深層析構。

### 2. actor 個別移除

`0x004DFBD5 call 0x0082EF00` 後有多型間接 `call eax`，`0x004DFC1E call 0x007B6890` 作節點移除；因此移除及其 object callback 為不同階段，不應將 `0x007B6890` 稱為 resource free。

### 3. 資源釋放橋接

前段及本批 `0x007BE5F0` 明確證實 `owner+0x60--`、再依 `resource+0x74/+0x78` 決定 `0x007DD1A0` 延遲保留或 `0x007BE0F0/0x007BD850/0x0089120C` 清理；相較之下場景 object 清理是否真的持有該 wrapper，需要沿具體 `+0xF4` 25 個 component slot 證實。

### 4. 證據分級

已確認：兩套樹函式地址/資源池增減計數與 wrapper 指標；部分確認：組件清理到 `0x007BE5F0` 已有有界入口；待驗：actor instance 及某個具體 resource owner 是否相同、間接 vtable 目標、server 生成/波次。

### 5. 跨 Task 保護

正式 T08 scope 0007 實體建立/登記/移除資料介面；不命名 server spawn trigger/AI/場景進出規則，跨 T02/T06/T07/T16 僅記證據接口。

## 可重算的直接 E8 rel32 候選交叉參照

- `0x004DFF30`：5 個 `.text` 原始 byte 候選。`0x004A11B6` (`e875ed0300`), `0x004AA222` (`e8095d0300`), `0x004AEC03` (`e828130300`), `0x004AF4F7` (`e8340a0300`), `0x004B2F83` (`e8a8cf0200`)
- `0x004DFBC0`：2 個 `.text` 原始 byte 候選。`0x004AA057` (`e8645b0300`), `0x004B2AC2` (`e8f9d00200`)
- `0x007BE5F0`：42 個 `.text` 原始 byte 候選。`0x004C7C8F` (`e85c692f00`), `0x004C7DB4` (`e837682f00`), `0x004C838C` (`e85f622f00`), `0x004C83AF` (`e83c622f00`), `0x004C8411` (`e8da612f00`), `0x004C902C` (`e8bf552f00`), `0x004C9066` (`e885552f00`), `0x004C9074` (`e877552f00`), `0x004CAFF4` (`e8f7352f00`), `0x004CC867` (`e8841d2f00`), `0x004CC89A` (`e8511d2f00`), `0x004CDDF1` (`e8fa072f00`), `0x004CE927` (`e8c4fc2e00`), `0x004CEC2C` (`e8bff92e00`), `0x004CECA7` (`e844f92e00`), `0x004D0330` (`e8bbe22e00`), `0x004D1333` (`e8b8d22e00`), `0x004D16B8` (`e833cf2e00`), `0x004D2449` (`e8a2c12e00`), `0x004D2497` (`e854c12e00`), `0x004D2522` (`e8c9c02e00`), `0x004D25A6` (`e845c02e00`), `0x004D2632` (`e8b9bf2e00`), `0x004D26BE` (`e82dbf2e00`), `0x004D2772` (`e879be2e00`), `0x004D287D` (`e86ebd2e00`), `0x00543B98` (`e853aa2700`), `0x00543FDF` (`e80ca62700`), `0x0054480B` (`e8e09d2700`), `0x00550B7D` (`e86eda2600`), `0x00550DAE` (`e83dd82600`), `0x00550EF9` (`e8f2d62600`), `0x00550EFE` (`e8edd62600`), `0x00550FB5` (`e836d62600`), `0x00552380` (`e86bc22600`), `0x007A5361` (`e88a920100`), `0x007A69A9` (`e8427c0100`), `0x007A78AA` (`e8416d0100`), `0x007A7A79` (`e8726b0100`), `0x007A7ACE` (`e81d6b0100`), `0x007A8DAC` (`e83f580100`), `0x007FF79A` (`e851eefbff`)
- `0x007DD1F0`：2 個 `.text` 原始 byte 候選。`0x007B8045` (`e8a6510200`), `0x007DD132` (`e8b9000000`)

掃描方法：逐位元組尋找 opcode `E8`，以 `site+5+signed(rel32)` 計算候選；這是**上限候選集合而非 CFG caller 的完整證明**。FF /2、多型 dispatch 與 import thunks 無法由此掃描完結。

## 有界偽碼（分析用，非遊戲原始 C++）

```cpp
register_actor(key, actor) -> scene_index_insert;
remove_actor(key) -> lookup -> virtual callbacks -> scene_tree_erase;
release_component_resource(slot) -> resource_manager_mode ? recycle : destroy;
// No proven direct equality: scene actor instance != resource manager payload
```

偽碼只反映本段明示的局部資料流，並不構成異常處理、競爭條件、全類型配置路徑或 runtime 語義驗收。

## 未解與下一段接續

1. 在實際 Ghidra CFG 驗證 E8 命中是否為指令邊界，並補上 vtable / FF 轉移的真實目標。
2. 對 `node+0x24`、resource 管理器、scene actor 樹分別查構造來源與型別；相同 offset 不等同同一物件。
3. 補實際 wrapper 失敗及 resource `+0x60` 計數的錯誤回退、間接析構與重入。
4. 靜態 BIN 無法證明場景更新/跨 frame 時機、官方 server 生成規則或全部參考數平衡。

## 附錄：原始 BIN 反組譯（Intel x86；每個窗口從指定 VA 起獨立解碼）

### `0x004DFF30` + `0x90` bytes

```asm
  4dff30:	55                   	push   ebp
  4dff31:	8b ec                	mov    ebp,esp
  4dff33:	83 ec 10             	sub    esp,0x10
  4dff36:	53                   	push   ebx
  4dff37:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dff3a:	56                   	push   esi
  4dff3b:	57                   	push   edi
  4dff3c:	8b f8                	mov    edi,eax
  4dff3e:	85 ff                	test   edi,edi
  4dff40:	75 0a                	jne    0x4dff4c
  4dff42:	68 d0 ce c0 00       	push   0xc0ced0
  4dff47:	e8 24 dd 20 00       	call   0x6edc70
  4dff4c:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dff50:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dff53:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4dff56:	8d 73 08             	lea    esi,[ebx+0x8]
  4dff59:	51                   	push   ecx
  4dff5a:	8d 45 f8             	lea    eax,[ebp-0x8]
  4dff5d:	8b ce                	mov    ecx,esi
  4dff5f:	e8 9c ef 34 00       	call   0x82ef00
  4dff64:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4dff67:	3b 53 0c             	cmp    edx,DWORD PTR [ebx+0xc]
  4dff6a:	75 24                	jne    0x4dff90
  4dff6c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dff6f:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  4dff72:	8d 7d f4             	lea    edi,[ebp-0xc]
  4dff75:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  4dff78:	e8 a3 ef 09 00       	call   0x57ef20
  4dff7d:	50                   	push   eax
  4dff7e:	56                   	push   esi
  4dff7f:	8d 75 f4             	lea    esi,[ebp-0xc]
  4dff82:	e8 79 f2 34 00       	call   0x82f200
  4dff87:	5f                   	pop    edi
  4dff88:	5e                   	pop    esi
  4dff89:	5b                   	pop    ebx
  4dff8a:	8b e5                	mov    esp,ebp
  4dff8c:	5d                   	pop    ebp
  4dff8d:	c2 04 00             	ret    0x4
  4dff90:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4dff93:	51                   	push   ecx
  4dff94:	68 f0 ce c0 00       	push   0xc0cef0
  4dff99:	e8 c2 db 20 00       	call   0x6edb60
  4dff9e:	83 c4 08             	add    esp,0x8
  4dffa1:	5f                   	pop    edi
  4dffa2:	5e                   	pop    esi
  4dffa3:	5b                   	pop    ebx
  4dffa4:	8b e5                	mov    esp,ebp
  4dffa6:	5d                   	pop    ebp
  4dffa7:	c2 04 00             	ret    0x4
  4dffaa:	cc                   	int3
  4dffab:	cc                   	int3
  4dffac:	cc                   	int3
  4dffad:	cc                   	int3
  4dffae:	cc                   	int3
  4dffaf:	cc                   	int3
  4dffb0:	55                   	push   ebp
  4dffb1:	8b ec                	mov    ebp,esp
  4dffb3:	83 e4 f8             	and    esp,0xfffffff8
  4dffb6:	6a ff                	push   0xffffffff
  4dffb8:	68 de ed 93 00       	push   0x93edde
  4dffbd:	64                   	fs
  4dffbe:	a1                   	.byte 0xa1
	...
```

### `0x004DFBC0` + `0x70` bytes

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
  4dfc29:	c2 04 00             	ret    0x4
  4dfc2c:	cc                   	int3
  4dfc2d:	cc                   	int3
  4dfc2e:	cc                   	int3
  4dfc2f:	cc                   	int3
```

### `0x007BE5F0` + `0x60` bytes

```asm
  7be5f0:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5f2:	85 c0                	test   eax,eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    eax,DWORD PTR [eax]
  7be5f9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7be5fc:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5fe:	8b 48 74             	mov    ecx,DWORD PTR [eax+0x74]
  7be601:	85 c9                	test   ecx,ecx
  7be603:	74 1b                	je     0x7be620
  7be605:	83 78 78 00          	cmp    DWORD PTR [eax+0x78],0x0
  7be609:	74 15                	je     0x7be620
  7be60b:	50                   	push   eax
  7be60c:	8b 00                	mov    eax,DWORD PTR [eax]
  7be60e:	50                   	push   eax
  7be60f:	e8 8c eb 01 00       	call   0x7dd1a0
  7be614:	b8 01 00 00 00       	mov    eax,0x1
  7be619:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be61f:	c3                   	ret
  7be620:	83 f9 01             	cmp    ecx,0x1
  7be623:	7c 06                	jl     0x7be62b
  7be625:	50                   	push   eax
  7be626:	e8 c5 fa ff ff       	call   0x7be0f0
  7be62b:	57                   	push   edi
  7be62c:	8b 3e                	mov    edi,DWORD PTR [esi]
  7be62e:	85 ff                	test   edi,edi
  7be630:	74 14                	je     0x7be646
  7be632:	e8 19 f2 ff ff       	call   0x7bd850
  7be637:	57                   	push   edi
  7be638:	e8 cf 2b 0d 00       	call   0x89120c
  7be63d:	83 c4 04             	add    esp,0x4
  7be640:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be646:	5f                   	pop    edi
  7be647:	b8 01 00 00 00       	mov    eax,0x1
  7be64c:	c7                   	.byte 0xc7
  7be64d:	06                   	push   es
	...
```

### `0x004C83C0` + `0x85` bytes

```asm
  4c83c0:	55                   	push   ebp
  4c83c1:	8b ec                	mov    ebp,esp
  4c83c3:	83 ec 0c             	sub    esp,0xc
  4c83c6:	56                   	push   esi
  4c83c7:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c83ca:	83 be 6c 03 00 00 00 	cmp    DWORD PTR [esi+0x36c],0x0
  4c83d1:	75 6d                	jne    0x4c8440
  4c83d3:	53                   	push   ebx
  4c83d4:	57                   	push   edi
  4c83d5:	33 ff                	xor    edi,edi
  4c83d7:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4c83da:	8d 9e 64 01 00 00    	lea    ebx,[esi+0x164]
  4c83e0:	0f b7 c7             	movzx  eax,di
  4c83e3:	8d 4d f8             	lea    ecx,[ebp-0x8]
  4c83e6:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  4c83e9:	51                   	push   ecx
  4c83ea:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c83ed:	8d 8e f0 03 00 00    	lea    ecx,[esi+0x3f0]
  4c83f3:	e8 88 de 35 00       	call   0x826280
  4c83f8:	8b 10                	mov    edx,DWORD PTR [eax]
  4c83fa:	3b 96 f4 03 00 00    	cmp    edx,DWORD PTR [esi+0x3f4]
  4c8400:	75 2d                	jne    0x4c842f
  4c8402:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c8404:	85 c0                	test   eax,eax
  4c8406:	74 27                	je     0x4c842f
  4c8408:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c840c:	8d 70 24             	lea    esi,[eax+0x24]
  4c840f:	74 05                	je     0x4c8416
  4c8411:	e8 da 61 2f 00       	call   0x7be5f0
  4c8416:	8b 03                	mov    eax,DWORD PTR [ebx]
  4c8418:	85 c0                	test   eax,eax
  4c841a:	74 10                	je     0x4c842c
  4c841c:	8b f8                	mov    edi,eax
  4c841e:	e8 8d f9 ff ff       	call   0x4c7db0
  4c8423:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4c8426:	c7 03 00 00 00 00    	mov    DWORD PTR [ebx],0x0
  4c842c:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4c842f:	47                   	inc    edi
  4c8430:	83 c3 04             	add    ebx,0x4
  4c8433:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4c8436:	81 ff 80 00 00 00    	cmp    edi,0x80
  4c843c:	7c a2                	jl     0x4c83e0
  4c843e:	5f                   	pop    edi
  4c843f:	5b                   	pop    ebx
  4c8440:	5e                   	pop    esi
  4c8441:	8b e5                	mov    esp,ebp
  4c8443:	5d                   	pop    ebp
  4c8444:	c2                   	.byte 0xc2
```
