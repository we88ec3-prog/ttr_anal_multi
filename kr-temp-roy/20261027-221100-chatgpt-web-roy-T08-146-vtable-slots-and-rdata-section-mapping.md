# T08-146 — `0x00C4F66C/0x00C4F6C0` 正確虛表映射與候選 slots

**Task**: T08 | **來源**: `Tartaros.bin`（12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實測）

**方法**：`.text` 在此 BIN 以 `offset=VA-0x401000` 讀取；`.rdata` 使用 PE 節區映射 `offset=VA-0x00BD2000+0x007D0600`，以 T08-125 已驗證 `0x00C4FF8C` 的 callback vtable 為交叉檢查。`objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 Tartaros.bin`。只作靜態研究，未執行除錯器。

**分級**：[確認] 指令或資料本身；[候選] 多項偏移結構相合但尚缺函式身分證據；[未知] 動態類別 / 實際方法身分。

## 1. 映射方式的重要稽核

[確認] 先前只對 `.text` 使用的 BIN 線性映射，**不能**直接用於 `.rdata`：例如 `0x00C4F66C` 用 `VA-0x401000` 讀到文字常數；用 PE `.rdata` raw mapping 讀到像程式碼地址的 DWORD。交叉驗證 `0x00C4FF8C+0x0C=0x007D1310` 與 T08-125 記錄一致。

```text
0x00c4ff8c: 0x007d12e0
0x00c4ff90: 0x005f5d10
0x00c4ff94: 0x005f5d10
0x00c4ff98: 0x007d1310
```

## 2. 初始 vfptr `0x00C4F66C`

```text
0x00c4f66c: 0x007a4c20
0x00c4f670: 0x00891fb2
0x00c4f674: 0x00891fb2
0x00c4f678: 0x00c7fa7c
0x00c4f67c: 0x007a4ff0
0x00c4f680: 0x0077b4e0
0x00c4f684: 0x007a63c0
0x00c4f688: 0x00550450
```

## 3. 改寫後 vfptr `0x00C4F6C0`

```text
0x00c4f6c0: 0x007aaa90
0x00c4f6c4: 0x007a8310
0x00c4f6c8: 0x007a8e10
0x00c4f6cc: 0x00c7f9f4
0x00c4f6d0: 0x007aaa40
0x00c4f6d4: 0x007a3920
0x00c4f6d8: 0x007a3950
0x00c4f6dc: 0x007848c0
```

[確認] 若以 vptr 視角，`0x00C4F6C0+0x04` 指向 `0x007A8310`，`+0x08` 指向 `0x007A8E10`。但這些地址與 B consumer 的 thiscall / 浮點回傳慣例是否相容仍有疑點：`0x007A8310` 出現在 `0x007A8300` 函式的非 prologue 位置；`0x007A8E10` 在線性反組譯亦無明確函式入口。**不能僅憑映射得出的兩個 DWORD 就正式命名為 B entry 方法。**

## 4. 指令窗口：候選執行目標

```asm
  7a8300:	55                   	push   ebp
  7a8301:	8b ec                	mov    ebp,esp
  7a8303:	83 ec 4c             	sub    esp,0x4c
  7a8306:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7a830b:	33 c5                	xor    eax,ebp
  7a830d:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  7a8310:	83 bf ac 00 00 00 00 	cmp    DWORD PTR [edi+0xac],0x0
  7a8317:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7a831a:	d9 00                	fld    DWORD PTR [eax]
  7a831c:	53                   	push   ebx
  7a831d:	d9 5d e0             	fstp   DWORD PTR [ebp-0x20]
  7a8320:	56                   	push   esi
  7a8321:	d9 40 04             	fld    DWORD PTR [eax+0x4]
  7a8324:	d9 5d e4             	fstp   DWORD PTR [ebp-0x1c]
  7a8327:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  7a832a:	d9 40 08             	fld    DWORD PTR [eax+0x8]
  7a832d:	8b 45 e0             	mov    eax,DWORD PTR [ebp-0x20]
  7a8330:	d9 5d e8             	fstp   DWORD PTR [ebp-0x18]
  7a8333:	89 45 b8             	mov    DWORD PTR [ebp-0x48],eax
  7a8336:	d9 01                	fld    DWORD PTR [ecx]
  7a8338:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  7a833b:	d9 5d e0             	fstp   DWORD PTR [ebp-0x20]
  7a833e:	89 55 bc             	mov    DWORD PTR [ebp-0x44],edx
  7a8341:	d9 41 04             	fld    DWORD PTR [ecx+0x4]
  7a8344:	89 45 c0             	mov    DWORD PTR [ebp-0x40],eax
  7a8347:	d9 5d e4             	fstp   DWORD PTR [ebp-0x1c]
  7a834a:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  7a834d:	d9 41 08             	fld    DWORD PTR [ecx+0x8]
  7a8350:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  7a8353:	d9 5d e8             	fstp   DWORD PTR [ebp-0x18]
  7a8356:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  7a8359:	89 4d c4             	mov    DWORD PTR [ebp-0x3c],ecx
  7a835c:	89 55 c8             	mov    DWORD PTR [ebp-0x38],edx
  7a835f:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  7a8362:	74 27                	je     0x7a838b
  7a8364:	8b 47 1c             	mov    eax,DWORD PTR [edi+0x1c]
  7a8367:	85 c0                	test   eax,eax
  7a8369:	74 20                	je     0x7a838b
  7a836b:	83 78 14 00          	cmp    DWORD PTR [eax+0x14],0x0
  7a836f:	74 1a                	je     0x7a838b
  7a8371:	8b 8f ac 00 00 00    	mov    ecx,DWORD PTR [edi+0xac]
```

[未知] 仍需核實 host subobject vfptr 的動態實際值、slot 所指地址是否屬 thunk/共用片段/非函式資料及 dispatch ABI，並排除 `.rdata` 表格邊界解讀錯誤。

## 5. 偽碼（未知方法語義）

```cpp
void* candidate_interface = (void*)0x00C4F6C0;
// only if proven at runtime: entry_vptr == candidate_interface
// execution = ((void(**)(void*))candidate_interface)[1];
// scoring   = ((double(**)(void*, void*))candidate_interface)[2];
```

## 6. T08-147

反查 constructor / destructor 何時置換 secondary vfptr，確保 B queue 不會保留已析構的 embedded object 指標。
