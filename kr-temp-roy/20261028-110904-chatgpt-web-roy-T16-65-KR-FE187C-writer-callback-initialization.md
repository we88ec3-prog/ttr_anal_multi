# KR T16-65 — [0xFE187C] setter 與實際目標函式確認

- 研究日期：20261028-110904 Asia/Taipei；分析者 `chatgpt-web roy`；**僅 KR T16**。
- KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 `12472320` bytes。實際讀取 `/mnt/data/Tartaros.bin`（唯讀）；未啟動遊戲或呼叫任何原版 API。
- PE `.text` 有效映射：VA `0x00401000`, raw `0x400`；下列 `.text` 函式轉檔案位移使用 `raw = VA - 0x00400C00`，跨 section 必須重算。
- 證據術語：原生已確認=本次直接 BIN 原始位元組與逐指令反組譯；部分確認=指標來源／語意尚未對齊；unknown=缺少原始資料。

## 1. 實測 xref

原始 BIN 逐 byte 搜尋 4-byte little endian 絕對位址 `7c 18 fe 00`：

| VA | raw | 上下文 |
|---|---|---|
| `0x004AB8BA` | `0xAACBA` | direct store immediate |
| `0x004ACA18` | `0xABE18` | direct read |

直接指標值 `0x004AA4D0` 的 little endian 常數另查得：`0x004AB8BE`。這是 data reference 命中，地址之外不自行推斷函式名。

## 2. 實際 setter / binding

`0x004AB8B8`：`C7 05 7C 18 FE 00 D0 A4 4A 00` -> `mov dword ptr ds:[0x00FE187C],0x004AA4D0`。`0x004AB909` push `0x004AC9E0`; `0x004AB90E` call `0x006F55B0`，並非單靠文字的 Lua API 名稱。

```asm
  4ab8a0:	55                   	push   ebp
  4ab8a1:	8b ec                	mov    ebp,esp
  4ab8a3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab8a6:	53                   	push   ebx
  4ab8a7:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
  4ab8ad:	56                   	push   esi
  4ab8ae:	8b 33                	mov    esi,DWORD PTR [ebx]
  4ab8b0:	57                   	push   edi
  4ab8b1:	8b 38                	mov    edi,DWORD PTR [eax]
  4ab8b3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4ab8b8:	c7 05 7c 18 fe 00 d0 	mov    DWORD PTR ds:0xfe187c,0x4aa4d0
  4ab8bf:	a4 4a 00 
  4ab8c2:	e8 b9 9d 24 00       	call   0x6f5680
  4ab8c7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4ab8c9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4ab8cc:	83 e8 10             	sub    eax,0x10
  4ab8cf:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4ab8d4:	74 06                	je     0x4ab8dc
  4ab8d6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4ab8da:	74 14                	je     0x4ab8f0
  4ab8dc:	57                   	push   edi
  4ab8dd:	68 c4 26 c4 00       	push   0xc426c4
  4ab8e2:	e8 d6 77 3e 00       	call   0x8930bd
  4ab8e7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4ab8e9:	83 c4 08             	add    esp,0x8
  4ab8ec:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4ab8f0:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4ab8f6:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab8f8:	68 68 ad d6 00       	push   0xd6ad68
  4ab8fd:	e8 0e 9c 24 00       	call   0x6f5510
  4ab902:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab904:	83 c4 04             	add    esp,0x4
  4ab907:	6a 00                	push   0x0
  4ab909:	68 e0 c9 4a 00       	push   0x4ac9e0
  4ab90e:	e8 9d 9c 24 00       	call   0x6f55b0
  4ab913:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4ab915:	51                   	push   ecx
  4ab916:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4ab91b:	e8 d0 9e 24 00       	call   0x6f57f0
  4ab920:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4ab926:	8b 02                	mov    eax,DWORD PTR [edx]
  4ab928:	83 c4 0c             	add    esp,0xc
  4ab92b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4ab92f:	8b                   	.byte 0x8b
  4ab930:	45                   	inc    ebp
```

## 3. consumer 的雙層指標傳遞

`0x004AC9E0` 以 `mov ecx,[0xFE187C] / push ecx / call 0x4ACB70` 把 callback 傳到下層；`0x4ACB70` 在成功轉型時 `call dword ptr [ebp+8]`，在不匹配時先 push 0 再呼叫**同一 callback**。因為 `0x4AB8B8` 有直接寫入，可把「初始化已生效時 callback 可達 `0x4AA4D0`」列為**部分確認**；仍須檢查初始化先後、有無第二 writer、未初始化時呼叫的可能性。

```asm
  4ac9e0:	55                   	push   ebp
  4ac9e1:	8b ec                	mov    ebp,esp
  4ac9e3:	6a ff                	push   0xffffffff
  4ac9e5:	68 c8 83 93 00       	push   0x9383c8
  4ac9ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac9f0:	50                   	push   eax
  4ac9f1:	83 ec 0c             	sub    esp,0xc
  4ac9f4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac9f9:	33 c5                	xor    eax,ebp
  4ac9fb:	50                   	push   eax
  4ac9fc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac9ff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aca05:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aca08:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4aca0b:	33 c0                	xor    eax,eax
  4aca0d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4aca10:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4aca13:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4aca16:	8b 0d 7c 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe187c
  4aca1c:	51                   	push   ecx
  4aca1d:	8d 45 e8             	lea    eax,[ebp-0x18]
  4aca20:	e8 4b 01 00 00       	call   0x4acb70
  4aca25:	83 c4 04             	add    esp,0x4
  4aca28:	b8 01 00 00 00       	mov    eax,0x1
  4aca2d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4aca30:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aca37:	59                   	pop    ecx
  4aca38:	8b e5                	mov    esp,ebp
  4aca3a:	5d                   	pop    ebp
  4aca3b:	c3                   	ret
  4aca3c:	cc                   	int3
  4aca3d:	cc                   	int3
  4aca3e:	cc                   	int3
```

## 4. 動態限制 / 排除

- 單一 BIN 靜態搜尋只確認兩個**絕對地址位元組引用**，不能排除間接寫入或 copy/memcpy。
- wrapper 回傳 `EAX=1`、bridge `EAX=0` 不是 Quest16 進度／關卡結果。
- 本段沒有任何 `server Quest16 completed` writer 證據。

## 下次依賴

進入 `0x4AA4D0` 檢查真正 message serialization、vtable 與 flags；不由 callback 名稱猜 Quest rule。
