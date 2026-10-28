# T08-186 — 管理器 0x007DCF40 容器析構、buffer free 與同步物件

- 時間：`2026-10-28T10:12:03.531628+08:00`（Asia/Taipei）；作者：`chatgpt-web roy`。
- 原始來源：唯讀 `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次本機重算一致。
- PE 映射由原檔標頭重驗：`.text` VA `0x00401000`、raw `0x400`、raw size `0x7D0200`；`.rdata` VA `0x00BD2000` raw `0x7D0600`；`.data` VA `0x00D61000` raw `0x95E800`。以下僅對 `.text` 依 raw = 0x400+(VA-0x401000) 轉換。
- 基準：GitHub `main` T08-181～184 原稿、T08 長期知識庫；這份記錄提供本次從 BIN 解碼的可重算窗口，不以舊筆記取代第一手證據。
- **證據標準：** 已確認=實際位元組及有界局部 CFG；部分確認=需要延伸 caller/跨型別連結；待驗=間接 call、未確知 symbol、runtime/伺服器行為。掃描 `E8` 均為 byte-offset 候選，不代表都位於可達指令邊界。

## 本段實質結論與證據

### 1. 暫定 ABI

函式直接把 `EDI` 當作 manager 基底；入口 `0x007DCF42 mov esi,[edi+0x4C]`。目前不宜稱為 `ECX this`；上游 `0x007B8136`、`0x007B7F49` 需確認如何供應 EDI。

### 2. 第一組容器逐項 free

`0x007DCF42..0x007DCF67` 迭代 `[edi+0x4C]..[edi+0x50]`，對非零項呼叫 `0x0089120C`，並寫零到該項；此階段釋放的是**+4C 向量內容**，與第二組 +7C 緩衝不可混稱。

### 3. 第二組容器 buffer 與鎖

`0x007DCF69..0x007DCF86` 若 `+0x7C` 非零則 `0x0089120C` 釋放緩衝，接著 `+0x7C/+0x80/+0x84` 均清零；`0x007DCF79 lea eax,[edi+0x64]` 並於 `0x007DCF8C` 經 IAT `[0x00BD2228]` 呼叫同步資源清理。只確認 IAT 位址；實際 API 名應讀 PE import，勿憑偏移命名。

### 4. 第一組 buffer 最後釋放

`0x007DCF92..0x007DCFAD` 檢查 `+0x4C`，非空再 free buffer，最後 `+0x4C/+0x50/+0x54` 清零。此順序支持 manager 析構與 resource object 個別析構分層。

### 5. 仍缺失

沒有任何證據顯示上述 free 等同刪除場景 actor 樹節點；亦不能只以這段證明所有 `0x0C` item 的間接資源均被釋放或異常路徑安全。

## 可重算的直接 E8 rel32 候選交叉參照

- `0x007DCF40`：2 個 `.text` 原始 byte 候選。`0x007B7F49` (`e8f24f0200`), `0x007B8136` (`e8054e0200`)
- `0x0089120C`：9180 個 `.text` 原始 byte 候選。`0x00401010` (`e8f7014900`), `0x0040133F` (`e8c8fe4800`), `0x00401355` (`e8b2fe4800`), `0x00401378` (`e88ffe4800`), `0x00401399` (`e86efe4800`), `0x004019A3` (`e864f84800`), `0x004019C3` (`e844f84800`), `0x00401B6A` (`e89df64800`), `0x00401B87` (`e880f64800`), `0x00401E41` (`e8c6f34800`), `0x004025A2` (`e865ec4800`), `0x004025E2` (`e825ec4800`), `0x0040267A` (`e88deb4800`), `0x00402817` (`e8f0e94800`), `0x004029B0` (`e857e84800`), `0x00402A2C` (`e8dbe74800`), `0x00402BC7` (`e840e64800`), `0x00402C5C` (`e8abe54800`), `0x00402D38` (`e8cfe44800`), `0x00402EC6` (`e841e34800`), `0x00402F07` (`e800e34800`), `0x00402F59` (`e8aee24800`), `0x00402FE4` (`e823e24800`), `0x0040367F` (`e888db4800`), `0x00403F88` (`e87fd24800`), `0x00403FA8` (`e85fd24800`), `0x004040AB` (`e85cd14800`), `0x004040CB` (`e83cd14800`), `0x00404C9F` (`e868c54800`), `0x00404DB3` (`e854c44800`), `0x00405123` (`e8e4c04800`), `0x004061B1` (`e856b04800`), `0x004076FB` (`e80c9b4800`), `0x0040771F` (`e8e89a4800`), `0x0040775C` (`e8ab9a4800`), `0x0040789A` (`e86d994800`), `0x00407972` (`e895984800`), `0x00407A7F` (`e888974800`), `0x00407B57` (`e8b0964800`), `0x00407BB3` (`e854964800`), `0x00407C06` (`e801964800`), `0x00407D95` (`e872944800`), `0x00407F66` (`e8a1924800`), `0x00407F8B` (`e87c924800`), `0x00407FC3` (`e844924800`), `0x00408127` (`e8e0904800`), `0x00409543` (`e8c47c4800`), `0x00409A07` (`e800784800`), `0x00409BAF` (`e858764800`), `0x00409C47` (`e8c0754800`), `0x0040A2C2` (`e8456f4800`), `0x0040A79B` (`e86c6a4800`), `0x0040A9AC` (`e85b684800`), `0x0040ABE4` (`e823664800`), `0x0040AF2E` (`e8d9624800`), `0x0040AF90` (`e877624800`), `0x0040B254` (`e8b35f4800`), `0x0040B295` (`e8725f4800`), `0x0040B4FE` (`e8095d4800`), `0x0040C212` (`e8f54f4800`), `0x0040CD9E` (`e869444800`), `0x0040CE00` (`e807444800`), `0x0040CE8E` (`e879434800`), `0x0040CEF0` (`e817434800`), `0x0040D04B` (`e8bc414800`)

掃描方法：逐位元組尋找 opcode `E8`，以 `site+5+signed(rel32)` 計算候選；這是**上限候選集合而非 CFG caller 的完整證明**。FF /2、多型 dispatch 與 import thunks 無法由此掃描完結。

## 有界偽碼（分析用，非遊戲原始 C++）

```cpp
for (auto p : manager->range4C_50) if (p) free(p);
free(manager->buffer7C);
manager->buffer7C = manager->end80 = manager->capacity84 = nullptr;
release_sync_object(&manager->field64);
free(manager->buffer4C);
manager->buffer4C = manager->end50 = manager->capacity54 = nullptr;
```

偽碼只反映本段明示的局部資料流，並不構成異常處理、競爭條件、全類型配置路徑或 runtime 語義驗收。

## 未解與下一段接續

1. 在實際 Ghidra CFG 驗證 E8 命中是否為指令邊界，並補上 vtable / FF 轉移的真實目標。
2. 對 `node+0x24`、resource 管理器、scene actor 樹分別查構造來源與型別；相同 offset 不等同同一物件。
3. 補實際 wrapper 失敗及 resource `+0x60` 計數的錯誤回退、間接析構與重入。
4. 靜態 BIN 無法證明場景更新/跨 frame 時機、官方 server 生成規則或全部參考數平衡。

## 附錄：原始 BIN 反組譯（Intel x86；每個窗口從指定 VA 起獨立解碼）

### `0x007DCF40` + `0x70` bytes

```asm
  7dcf40:	53                   	push   ebx
  7dcf41:	56                   	push   esi
  7dcf42:	8b 77 4c             	mov    esi,DWORD PTR [edi+0x4c]
  7dcf45:	33 db                	xor    ebx,ebx
  7dcf47:	3b 77 50             	cmp    esi,DWORD PTR [edi+0x50]
  7dcf4a:	74 1d                	je     0x7dcf69
  7dcf4c:	8d 64 24 00          	lea    esp,[esp+0x0]
  7dcf50:	8b 06                	mov    eax,DWORD PTR [esi]
  7dcf52:	3b c3                	cmp    eax,ebx
  7dcf54:	74 0b                	je     0x7dcf61
  7dcf56:	50                   	push   eax
  7dcf57:	e8 b0 42 0b 00       	call   0x89120c
  7dcf5c:	83 c4 04             	add    esp,0x4
  7dcf5f:	89 1e                	mov    DWORD PTR [esi],ebx
  7dcf61:	83 c6 04             	add    esi,0x4
  7dcf64:	3b 77 50             	cmp    esi,DWORD PTR [edi+0x50]
  7dcf67:	75 e7                	jne    0x7dcf50
  7dcf69:	8b 47 7c             	mov    eax,DWORD PTR [edi+0x7c]
  7dcf6c:	3b c3                	cmp    eax,ebx
  7dcf6e:	74 09                	je     0x7dcf79
  7dcf70:	50                   	push   eax
  7dcf71:	e8 96 42 0b 00       	call   0x89120c
  7dcf76:	83 c4 04             	add    esp,0x4
  7dcf79:	8d 47 64             	lea    eax,[edi+0x64]
  7dcf7c:	50                   	push   eax
  7dcf7d:	89 5f 7c             	mov    DWORD PTR [edi+0x7c],ebx
  7dcf80:	89 9f 80 00 00 00    	mov    DWORD PTR [edi+0x80],ebx
  7dcf86:	89 9f 84 00 00 00    	mov    DWORD PTR [edi+0x84],ebx
  7dcf8c:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  7dcf92:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  7dcf95:	3b c3                	cmp    eax,ebx
  7dcf97:	74 09                	je     0x7dcfa2
  7dcf99:	50                   	push   eax
  7dcf9a:	e8 6d 42 0b 00       	call   0x89120c
  7dcf9f:	83 c4 04             	add    esp,0x4
  7dcfa2:	5e                   	pop    esi
  7dcfa3:	89 5f 4c             	mov    DWORD PTR [edi+0x4c],ebx
  7dcfa6:	89 5f 50             	mov    DWORD PTR [edi+0x50],ebx
  7dcfa9:	89 5f 54             	mov    DWORD PTR [edi+0x54],ebx
  7dcfac:	5b                   	pop    ebx
  7dcfad:	c3                   	ret
  7dcfae:	cc                   	int3
  7dcfaf:	cc                   	int3
```

### `0x007DD125` + `0x85` bytes

```asm
  7dd125:	8b f1                	mov    esi,ecx
  7dd127:	83 cf ff             	or     edi,0xffffffff
  7dd12a:	01 7e 5c             	add    DWORD PTR [esi+0x5c],edi
  7dd12d:	8b 46 5c             	mov    eax,DWORD PTR [esi+0x5c]
  7dd130:	75 58                	jne    0x7dd18a
  7dd132:	e8 b9 00 00 00       	call   0x7dd1f0
  7dd137:	33 db                	xor    ebx,ebx
  7dd139:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7dd140:	89 5e 44             	mov    DWORD PTR [esi+0x44],ebx
  7dd143:	75 1f                	jne    0x7dd164
  7dd145:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7dd14c:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7dd14f:	e8 4c ac fd ff       	call   0x7b7da0
  7dd154:	68 90 e7 bc 00       	push   0xbce790
  7dd159:	e8 bc 51 0b 00       	call   0x89231a
  7dd15e:	83 c4 04             	add    esp,0x4
  7dd161:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  7dd164:	8b 7e 50             	mov    edi,DWORD PTR [esi+0x50]
  7dd167:	2b 7e 4c             	sub    edi,DWORD PTR [esi+0x4c]
  7dd16a:	c1 ff 02             	sar    edi,0x2
  7dd16d:	3b fb                	cmp    edi,ebx
  7dd16f:	76 16                	jbe    0x7dd187
  7dd171:	8b 46 4c             	mov    eax,DWORD PTR [esi+0x4c]
  7dd174:	8b 14 98             	mov    edx,DWORD PTR [eax+ebx*4]
  7dd177:	8b 0d 3c 17 fe 00    	mov    ecx,DWORD PTR ds:0xfe173c
  7dd17d:	e8 8e f3 ff ff       	call   0x7dc510
  7dd182:	43                   	inc    ebx
  7dd183:	3b df                	cmp    ebx,edi
  7dd185:	72 ea                	jb     0x7dd171
  7dd187:	8b 46 5c             	mov    eax,DWORD PTR [esi+0x5c]
  7dd18a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7dd18d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7dd194:	59                   	pop    ecx
  7dd195:	5f                   	pop    edi
  7dd196:	5e                   	pop    esi
  7dd197:	5b                   	pop    ebx
  7dd198:	8b e5                	mov    esp,ebp
  7dd19a:	5d                   	pop    ebp
  7dd19b:	c3                   	ret
  7dd19c:	cc                   	int3
  7dd19d:	cc                   	int3
  7dd19e:	cc                   	int3
  7dd19f:	cc                   	int3
  7dd1a0:	55                   	push   ebp
  7dd1a1:	8b ec                	mov    ebp,esp
  7dd1a3:	53                   	push   ebx
  7dd1a4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dd1a7:	83                   	.byte 0x83
  7dd1a8:	7b 44                	jnp    0x7dd1ee
```
