# T08-187 — 資源池引用計數、wrapper 0x30 配置與返回所有權

- 時間：`2026-10-28T10:12:03.531628+08:00`（Asia/Taipei）；作者：`chatgpt-web roy`。
- 原始來源：唯讀 `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次本機重算一致。
- PE 映射由原檔標頭重驗：`.text` VA `0x00401000`、raw `0x400`、raw size `0x7D0200`；`.rdata` VA `0x00BD2000` raw `0x7D0600`；`.data` VA `0x00D61000` raw `0x95E800`。以下僅對 `.text` 依 raw = 0x400+(VA-0x401000) 轉換。
- 基準：GitHub `main` T08-181～184 原稿、T08 長期知識庫；這份記錄提供本次從 BIN 解碼的可重算窗口，不以舊筆記取代第一手證據。
- **證據標準：** 已確認=實際位元組及有界局部 CFG；部分確認=需要延伸 caller/跨型別連結；待驗=間接 call、未確知 symbol、runtime/伺服器行為。掃描 `E8` 均為 byte-offset 候選，不代表都位於可達指令邊界。

## 本段實質結論與證據

### 1. 復用池與外部活躍計數區分

`0x007DCFB7 mov ebx,[ebp+8]`、`0x007DCFBA inc dword ptr [ebx+0x60]`，在 `+0x64` 上鎖前增加 `+0x60`。`0x007DCFD4..0x007DCFF2` 取尾端資源、`0x007BE5B0` 復位、end 減 4；空時 `0x007DD011 push 0x7C`、`0x007DD013 call 0x00891268` 新配置。此 `+0x60` 與 manager `+0x5C` 不同。

### 2. 解除引用的計數配對

`0x007BE5F0` 由 `ESI` 取得資源指標，再從 `[resource+0x00]` 取 owner，`0x007BE5F9 dec dword ptr [eax+0x60]`。故最少存在 `acquire +0x60++` 和 `release +0x60--` 的同偏移局部對偶；尚未證明所有 null/失敗/額外 wrapper 路徑一一平衡。

### 3. wrapper 來源明確

`0x007F6FC1 push 0x30`、`0x007F6FC3 call 0x00891268` 配置 wrapper；`0x007F6FDB push edi`、`0x007F6FDC call 0x007DCFB0` 取 resource；`0x007F6FEA mov [esi],0x00C511CC` 設 vptr；`0x007F700B mov [esi+0x2C],eax` 接資源指標。此處 `wrapper+0x2C` 是 resource 指標，不能與 resource `+0x2C` 混淆。

### 4. 分支界線

`0x007F7021` 是 wrapper 配置失敗後 EAX=0 的返回分支；該分支尚未觸發 `0x007DCFB0`。取資源之後的失敗回退、虛擬 destructor 與 manager 保活均需再追。

## 可重算的直接 E8 rel32 候選交叉參照

- `0x007DCFB0`：2 個 `.text` 原始 byte 候選。`0x007B8275` (`e8364d0200`), `0x007F6FDC` (`e8cf5ffeff`)
- `0x007BE5F0`：42 個 `.text` 原始 byte 候選。`0x004C7C8F` (`e85c692f00`), `0x004C7DB4` (`e837682f00`), `0x004C838C` (`e85f622f00`), `0x004C83AF` (`e83c622f00`), `0x004C8411` (`e8da612f00`), `0x004C902C` (`e8bf552f00`), `0x004C9066` (`e885552f00`), `0x004C9074` (`e877552f00`), `0x004CAFF4` (`e8f7352f00`), `0x004CC867` (`e8841d2f00`), `0x004CC89A` (`e8511d2f00`), `0x004CDDF1` (`e8fa072f00`), `0x004CE927` (`e8c4fc2e00`), `0x004CEC2C` (`e8bff92e00`), `0x004CECA7` (`e844f92e00`), `0x004D0330` (`e8bbe22e00`), `0x004D1333` (`e8b8d22e00`), `0x004D16B8` (`e833cf2e00`), `0x004D2449` (`e8a2c12e00`), `0x004D2497` (`e854c12e00`), `0x004D2522` (`e8c9c02e00`), `0x004D25A6` (`e845c02e00`), `0x004D2632` (`e8b9bf2e00`), `0x004D26BE` (`e82dbf2e00`), `0x004D2772` (`e879be2e00`), `0x004D287D` (`e86ebd2e00`), `0x00543B98` (`e853aa2700`), `0x00543FDF` (`e80ca62700`), `0x0054480B` (`e8e09d2700`), `0x00550B7D` (`e86eda2600`), `0x00550DAE` (`e83dd82600`), `0x00550EF9` (`e8f2d62600`), `0x00550EFE` (`e8edd62600`), `0x00550FB5` (`e836d62600`), `0x00552380` (`e86bc22600`), `0x007A5361` (`e88a920100`), `0x007A69A9` (`e8427c0100`), `0x007A78AA` (`e8416d0100`), `0x007A7A79` (`e8726b0100`), `0x007A7ACE` (`e81d6b0100`), `0x007A8DAC` (`e83f580100`), `0x007FF79A` (`e851eefbff`)
- `0x007DD1A0`：2 個 `.text` 原始 byte 候選。`0x007A8741` (`e85a4a0300`), `0x007BE60F` (`e88ceb0100`)

掃描方法：逐位元組尋找 opcode `E8`，以 `site+5+signed(rel32)` 計算候選；這是**上限候選集合而非 CFG caller 的完整證明**。FF /2、多型 dispatch 與 import thunks 無法由此掃描完結。

## 有界偽碼（分析用，非遊戲原始 C++）

```cpp
Wrapper* w = allocate(0x30);
if (!w) return nullptr;
Resource* r = acquire_resource(manager); // increments manager+60
w->vptr = 0x00C511CC;
w->resource2C = r;
// release: --r->manager->field60; then conditional pool_or_free
```

偽碼只反映本段明示的局部資料流，並不構成異常處理、競爭條件、全類型配置路徑或 runtime 語義驗收。

## 未解與下一段接續

1. 在實際 Ghidra CFG 驗證 E8 命中是否為指令邊界，並補上 vtable / FF 轉移的真實目標。
2. 對 `node+0x24`、resource 管理器、scene actor 樹分別查構造來源與型別；相同 offset 不等同同一物件。
3. 補實際 wrapper 失敗及 resource `+0x60` 計數的錯誤回退、間接析構與重入。
4. 靜態 BIN 無法證明場景更新/跨 frame 時機、官方 server 生成規則或全部參考數平衡。

## 附錄：原始 BIN 反組譯（Intel x86；每個窗口從指定 VA 起獨立解碼）

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

### `0x007F6FBA` + `0x7B` bytes

```asm
  7f6fba:	e8 c1 11 fc ff       	call   0x7b8180
  7f6fbf:	6a 30                	push   0x30
  7f6fc1:	8b f8                	mov    edi,eax
  7f6fc3:	e8 a0 a2 09 00       	call   0x891268
  7f6fc8:	8b f0                	mov    esi,eax
  7f6fca:	83 c4 04             	add    esp,0x4
  7f6fcd:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  7f6fd0:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7f6fd7:	85 f6                	test   esi,esi
  7f6fd9:	74 46                	je     0x7f7021
  7f6fdb:	57                   	push   edi
  7f6fdc:	e8 cf 5f fe ff       	call   0x7dcfb0
  7f6fe1:	d9 ee                	fldz
  7f6fe3:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  7f6fea:	c7 06 cc 11 c5 00    	mov    DWORD PTR [esi],0xc511cc
  7f6ff0:	d9 56 08             	fst    DWORD PTR [esi+0x8]
  7f6ff3:	d9 56 0c             	fst    DWORD PTR [esi+0xc]
  7f6ff6:	d9 56 10             	fst    DWORD PTR [esi+0x10]
  7f6ff9:	d9 56 14             	fst    DWORD PTR [esi+0x14]
  7f6ffc:	d9 56 18             	fst    DWORD PTR [esi+0x18]
  7f6fff:	d9 56 1c             	fst    DWORD PTR [esi+0x1c]
  7f7002:	d9 56 20             	fst    DWORD PTR [esi+0x20]
  7f7005:	d9 56 24             	fst    DWORD PTR [esi+0x24]
  7f7008:	d9 5e 28             	fstp   DWORD PTR [esi+0x28]
  7f700b:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
  7f700e:	8b c6                	mov    eax,esi
  7f7010:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f7013:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f701a:	59                   	pop    ecx
  7f701b:	5f                   	pop    edi
  7f701c:	5e                   	pop    esi
  7f701d:	8b e5                	mov    esp,ebp
  7f701f:	5d                   	pop    ebp
  7f7020:	c3                   	ret
  7f7021:	33 c0                	xor    eax,eax
  7f7023:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f7026:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f702d:	59                   	pop    ecx
  7f702e:	5f                   	pop    edi
  7f702f:	5e                   	pop    esi
  7f7030:	8b e5                	mov    esp,ebp
  7f7032:	5d                   	pop    ebp
  7f7033:	c3                   	ret
  7f7034:	cc                   	int3
```

### `0x007DCFB0` + `0x90` bytes

```asm
  7dcfb0:	55                   	push   ebp
  7dcfb1:	8b ec                	mov    ebp,esp
  7dcfb3:	83 ec 10             	sub    esp,0x10
  7dcfb6:	53                   	push   ebx
  7dcfb7:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dcfba:	ff 43 60             	inc    DWORD PTR [ebx+0x60]
  7dcfbd:	56                   	push   esi
  7dcfbe:	57                   	push   edi
  7dcfbf:	8d 7b 64             	lea    edi,[ebx+0x64]
  7dcfc2:	57                   	push   edi
  7dcfc3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7dcfc9:	8b 43 7c             	mov    eax,DWORD PTR [ebx+0x7c]
  7dcfcc:	3b 83 80 00 00 00    	cmp    eax,DWORD PTR [ebx+0x80]
  7dcfd2:	74 36                	je     0x7dd00a
  7dcfd4:	8b 83 80 00 00 00    	mov    eax,DWORD PTR [ebx+0x80]
  7dcfda:	8b 70 fc             	mov    esi,DWORD PTR [eax-0x4]
  7dcfdd:	8b c6                	mov    eax,esi
  7dcfdf:	e8 cc 15 fe ff       	call   0x7be5b0
  7dcfe4:	8b 83 80 00 00 00    	mov    eax,DWORD PTR [ebx+0x80]
  7dcfea:	39 43 7c             	cmp    DWORD PTR [ebx+0x7c],eax
  7dcfed:	74 09                	je     0x7dcff8
  7dcfef:	83 c0 fc             	add    eax,0xfffffffc
  7dcff2:	89 83 80 00 00 00    	mov    DWORD PTR [ebx+0x80],eax
  7dcff8:	57                   	push   edi
  7dcff9:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dcfff:	8b c6                	mov    eax,esi
  7dd001:	5f                   	pop    edi
  7dd002:	5e                   	pop    esi
  7dd003:	5b                   	pop    ebx
  7dd004:	8b e5                	mov    esp,ebp
  7dd006:	5d                   	pop    ebp
  7dd007:	c2 04 00             	ret    0x4
  7dd00a:	57                   	push   edi
  7dd00b:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dd011:	6a 7c                	push   0x7c
  7dd013:	e8 50 42 0b 00       	call   0x891268
  7dd018:	33 ff                	xor    edi,edi
  7dd01a:	83 c4 04             	add    esp,0x4
  7dd01d:	3b c7                	cmp    eax,edi
  7dd01f:	74 15                	je     0x7dd036
  7dd021:	d9 43 48             	fld    DWORD PTR [ebx+0x48]
  7dd024:	51                   	push   ecx
  7dd025:	8b cb                	mov    ecx,ebx
  7dd027:	d9 1c 24             	fstp   DWORD PTR [esp]
  7dd02a:	e8 b1 07 fe ff       	call   0x7bd7e0
  7dd02f:	8b f0                	mov    esi,eax
  7dd031:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  7dd034:	eb 05                	jmp    0x7dd03b
  7dd036:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  7dd039:	8b f7                	mov    esi,edi
  7dd03b:	8b 43 50             	mov    eax,DWORD PTR [ebx+0x50]
  7dd03e:	2b                   	.byte 0x2b
  7dd03f:	43                   	inc    ebx
```
