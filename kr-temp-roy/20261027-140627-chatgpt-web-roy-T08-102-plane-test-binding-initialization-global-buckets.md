# T08-102 — 六組平面係數比較、Binding 基底初始化與全域派送分桶生命週期

- 時間：2026-10-27T14:06:27+08:00 (Asia/Taipei)
- 作者：chatgpt-web roy
- SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（已核對）；Windows PE32 x86；證據來源 `/mnt/data/Tartaros.bin`
- 方法：原始 PE `.text` GNU objdump VA 反組譯、跨函式呼叫與記憶體參照核對；未執行程式；所有意義型名稱為暫定。
- 本段 **沒有 GitHub Commit**。

## 1. 新確認事項

### A. `0x00838860` 是固定 6 次的四浮點數點積與比較判斷

- `EDX` 是一組連續紀錄的起始指標，函式入口 `add edx,8`，迴圈以 `[edx-8], [edx-4], [edx], [edx+4]` 取四個 `float`，每次 `add edx,0x10`，迴圈至第六筆（`cmp ecx,6`）。
- 四個 stack 參數中，`[ebp+8/+0xC/+0x10]` 作為三維點積三個輸入，`[ebp+0x14]` 是比較基準值（實際 x87 ST 堆疊順序詳見下方反組譯），每輪計算 `a*x+b*y+c*z+d`。由 `fmul/faddp/fcomp` 及 x87 flag `test ah,0x41` 控制返回值：在出現不通過的比較時提前返回 0，六組都通過返回 1。
- 這強烈符合六個半空間或六個平面所做的幾何篩選（例如視錐平面測試），但**資料來源的物理意義尚未證實**，不可逕稱相機視錐裁切。
- 參數來自 `0x007F2520`：`binding+0x88` 關聯物件 `+0x68/+0x6C/+0x70` 三個浮點數，`binding+0xB0` 作為第四個浮點數；`EDX=[0x00FB76B0]` 指向平面參數陣列。故 `binding+0x80` 與幾何半空間比較結果直接相關，不能解釋為角色死亡/動畫停止。

### B. `0x007E9BF0` 明確初始化兩個獨立布林狀態

`0x007E9C9B mov [esi+0x7C],0`；`0x007E9CA2 mov [esi+0x80],0`。同時：`[esi+0x70]` 設為 `.rdata:0x00C556E0` 的 float，配置兩組 0x2C bytes Transform（指標 `+0x74/+0x78`），主 vptr 初始 `0x00C50618`。後續派生類（第100/101段）可再覆蓋 vptr，因此不能誤把基底表當最終 Provider vtable。

### C. `0x00FB7740` 是 22 組、每組 0x2004 bytes 的指標分桶

`0x00798F26 push 0x2C058` 配置，`0x00798F5B mov edx,0x15`、`0x00798F60 lea ecx,[eax+0x2000]`、`0x00798F66 mov [ecx],0` 逐桶清零計數，末尾 `0x00798F78 mov [0x00FB7740],eax`。`0x2C058` 大於 `22*0x2004 (0x2C058)`，**恰好相等**，共22個分桶：每桶 `0x2000` bytes 可以放 2048 個 DWORD 指標，尾端 `+0x2000` 是 DWORD count。

`0x007F23B0` 遍歷 `binding+0x8C..+0x90` 8-byte 項目，先將數值按索引送入 `0x00FB7774+index*0x10` 的另一個容器；接著透過 `binding+0x84` 的 secondary vtable `+0x04` 得到 bucket index，位址為 `base + index*0x2004`，只在 count < 0x800 時存入 `binding+0x84` 並增加 count。注意它存的是**次級子物件指標**，不是 0xB4 物件原始基址。

`0x007995A6` 讀 `[0x00FB7740]`，`0x007995B2 call 0x0089120C` 釋放，接著 `[0x00FB7740]=0`。確定分桶具有啟動/清理生命週期；消費者尚未定位。

## 2. 重要地址與角色

| VA | 已確認功能 | 可信度 |
|---|---|---|
| `0x00838860` | 6 組每組 4 float 的點積與門檻比較（16-byte stride） | BIN 確認 |
| `0x007F2520` | 呼叫幾何比較並將相反狀態寫到 `binding+0x80` | BIN 確認 |
| `0x007E9BF0` | 初始化基底 `+0x70/+0x74/+0x78/+0x7C/+0x80` | BIN 確認 |
| `0x00798F26` | 建立 22 桶派送陣列 | BIN 確認（函式內地址） |
| `0x007F23B0` | 填入分桶及全域紀錄 | BIN 確認 |
| `0x007995A6` | 分桶配置的清理入口 | BIN 確認（函式內地址） |

## 3. 可驗證資料流與暫定偽程式碼

```cpp
// 只表達已驗證行為；比較方向與 NaN/x87 unordered 情形需動態或符號層驗證。
bool sub_00838860(const float* coeff6x4, float x, float y, float z, float w) {
    for (unsigned i = 0; i < 6; i++) {
        float v = coeff6x4[i*4+0]*x + coeff6x4[i*4+1]*y + coeff6x4[i*4+2]*z + coeff6x4[i*4+3];
        if (/* x87 compare rejects v versus w */) return false;
    }
    return true;
}
void updateBindingFlag(BindingB4* b) {
    const bool inTest = (global_FB76E4 == 0) ||
        sub_00838860(global_FB76B0, b->associated->x68, b->associated->x6C, b->associated->x70, b->xB0);
    b->flag80 = !inTest;
}
// 22 buckets; each bucket: 2048 pointers + uint32 count.
struct Bucket { void *objects[2048]; uint32_t count; };
static_assert(sizeof(Bucket)==0x2004);
struct Buckets { Bucket buckets[22]; };
static_assert(sizeof(Buckets)==0x2C058);
```

## 4. 已確認 / 未確認界線

- **已確認** 6 次 `0x10` stride float 比較、來源參數、`+0x80` 反向布林、初始化 `+0x7C/+0x80=0`、22 個 0x2004 分桶的建立與釋放、將 secondary object `+0x84` 指標插桶。
- **合理假設** 這是平面/視錐幾何剔除；`+0xB0` 是幾何容許半徑或偏移。但兩者皆未取得來源語義實證，不能命名為 radius/frustum。
- **尚待驗證** `0x00FB76B0` 的係數填入路徑和正規化方式、`0x00FB7740` 的真正讀取與消費者（除初始化/清理/寫入者）、各 bucket index 的意義、NaN 邊界、動態更新批次的生命周期；長期場景 vtable+0x20 主迴圈。

## 5. 下一段建議 T08-103

1. 從 `0x00FB76B0` 的所有存取參照反推平面係數來源，確認是否相機/視錐/光照判斷。
2. 追 `0x00FB7740` 真正**讀取 bucket count 與 pointer** 的迴圈，確認派送調度者與消費時點。
3. 檢查 `0x007F15B0` 衍生初始化是否對基底布林覆寫，還原分桶每幀清零順序。

## 6. 原始 BIN 反組譯（完整函式及相關區域）

### 6-plane numerical test (`0x00838860`–`0x008388C6`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00838860 <.text+0x437860>:
  838860:	55                   	push   ebp
  838861:	8b ec                	mov    ebp,esp
  838863:	d9 45 14             	fld    DWORD PTR [ebp+0x14]
  838866:	33 c9                	xor    ecx,ecx
  838868:	d9 45 10             	fld    DWORD PTR [ebp+0x10]
  83886b:	83 c2 08             	add    edx,0x8
  83886e:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  838871:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  838874:	d9 42 f8             	fld    DWORD PTR [edx-0x8]
  838877:	d8 c9                	fmul   st,st(1)
  838879:	d9 42 fc             	fld    DWORD PTR [edx-0x4]
  83887c:	d8 cb                	fmul   st,st(3)
  83887e:	de c1                	faddp  st(1),st
  838880:	d9 02                	fld    DWORD PTR [edx]
  838882:	d8 cc                	fmul   st,st(4)
  838884:	de c1                	faddp  st(1),st
  838886:	d9 5d 14             	fstp   DWORD PTR [ebp+0x14]
  838889:	d9 45 14             	fld    DWORD PTR [ebp+0x14]
  83888c:	d8 42 04             	fadd   DWORD PTR [edx+0x4]
  83888f:	d9 5d 14             	fstp   DWORD PTR [ebp+0x14]
  838892:	d9 45 14             	fld    DWORD PTR [ebp+0x14]
  838895:	d8 dc                	fcomp  st(4)
  838897:	df e0                	fnstsw ax
  838899:	f6 c4 41             	test   ah,0x41
  83889c:	74 1a                	je     0x8388b8
  83889e:	41                   	inc    ecx
  83889f:	83 c2 10             	add    edx,0x10
  8388a2:	83 f9 06             	cmp    ecx,0x6
  8388a5:	72 cd                	jb     0x838874
  8388a7:	dd db                	fstp   st(3)
  8388a9:	b8 01 00 00 00       	mov    eax,0x1
  8388ae:	dd d9                	fstp   st(1)
  8388b0:	dd d8                	fstp   st(0)
  8388b2:	dd d8                	fstp   st(0)
  8388b4:	5d                   	pop    ebp
  8388b5:	c2 10 00             	ret    0x10
  8388b8:	dd db                	fstp   st(3)
  8388ba:	33 c0                	xor    eax,eax
  8388bc:	dd d9                	fstp   st(1)
  8388be:	dd d8                	fstp   st(0)
  8388c0:	dd d8                	fstp   st(0)
  8388c2:	5d                   	pop    ebp
  8388c3:	c2 10 00             	ret    0x10

```

### base binding constructor (`0x007E9BF0`–`0x007E9CD0`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007e9bf0 <.text+0x3e8bf0>:
  7e9bf0:	55                   	push   ebp
  7e9bf1:	8b ec                	mov    ebp,esp
  7e9bf3:	d9 05 e0 56 c5 00    	fld    DWORD PTR ds:0xc556e0
  7e9bf9:	6a 2c                	push   0x2c
  7e9bfb:	d9 5e 70             	fstp   DWORD PTR [esi+0x70]
  7e9bfe:	c7 06 18 06 c5 00    	mov    DWORD PTR [esi],0xc50618
  7e9c04:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  7e9c0b:	c7 46 08 01 00 00 00 	mov    DWORD PTR [esi+0x8],0x1
  7e9c12:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  7e9c15:	e8 4e 76 0a 00       	call   0x891268
  7e9c1a:	d9 ee                	fldz
  7e9c1c:	d9 e8                	fld1
  7e9c1e:	83 c4 04             	add    esp,0x4
  7e9c21:	85 c0                	test   eax,eax
  7e9c23:	74 28                	je     0x7e9c4d
  7e9c25:	d9 c9                	fxch   st(1)
  7e9c27:	d9 10                	fst    DWORD PTR [eax]
  7e9c29:	d9 50 04             	fst    DWORD PTR [eax+0x4]
  7e9c2c:	d9 50 08             	fst    DWORD PTR [eax+0x8]
  7e9c2f:	d9 50 0c             	fst    DWORD PTR [eax+0xc]
  7e9c32:	d9 50 10             	fst    DWORD PTR [eax+0x10]
  7e9c35:	d9 58 14             	fstp   DWORD PTR [eax+0x14]
  7e9c38:	d9 50 18             	fst    DWORD PTR [eax+0x18]
  7e9c3b:	d9 50 1c             	fst    DWORD PTR [eax+0x1c]
  7e9c3e:	d9 50 20             	fst    DWORD PTR [eax+0x20]
  7e9c41:	d9 58 24             	fstp   DWORD PTR [eax+0x24]
  7e9c44:	c7 40 28 01 00 00 00 	mov    DWORD PTR [eax+0x28],0x1
  7e9c4b:	eb 06                	jmp    0x7e9c53
  7e9c4d:	dd d9                	fstp   st(1)
  7e9c4f:	33 c0                	xor    eax,eax
  7e9c51:	dd d8                	fstp   st(0)
  7e9c53:	6a 2c                	push   0x2c
  7e9c55:	89 46 74             	mov    DWORD PTR [esi+0x74],eax
  7e9c58:	e8 0b 76 0a 00       	call   0x891268
  7e9c5d:	83 c4 04             	add    esp,0x4
  7e9c60:	85 c0                	test   eax,eax
  7e9c62:	74 2a                	je     0x7e9c8e
  7e9c64:	d9 ee                	fldz
  7e9c66:	d9 10                	fst    DWORD PTR [eax]
  7e9c68:	d9 50 04             	fst    DWORD PTR [eax+0x4]
  7e9c6b:	d9 50 08             	fst    DWORD PTR [eax+0x8]
  7e9c6e:	d9 50 0c             	fst    DWORD PTR [eax+0xc]
  7e9c71:	d9 50 10             	fst    DWORD PTR [eax+0x10]
  7e9c74:	d9 58 14             	fstp   DWORD PTR [eax+0x14]
  7e9c77:	d9 e8                	fld1
  7e9c79:	d9 50 18             	fst    DWORD PTR [eax+0x18]
  7e9c7c:	d9 50 1c             	fst    DWORD PTR [eax+0x1c]
  7e9c7f:	d9 50 20             	fst    DWORD PTR [eax+0x20]
  7e9c82:	d9 58 24             	fstp   DWORD PTR [eax+0x24]
  7e9c85:	c7 40 28 01 00 00 00 	mov    DWORD PTR [eax+0x28],0x1
  7e9c8c:	eb 02                	jmp    0x7e9c90
  7e9c8e:	33 c0                	xor    eax,eax
  7e9c90:	89 46 78             	mov    DWORD PTR [esi+0x78],eax
  7e9c93:	b8 38 0a c5 00       	mov    eax,0xc50a38
  7e9c98:	8d 56 10             	lea    edx,[esi+0x10]
  7e9c9b:	c7 46 7c 00 00 00 00 	mov    DWORD PTR [esi+0x7c],0x0
  7e9ca2:	c7 86 80 00 00 00 00 	mov    DWORD PTR [esi+0x80],0x0
  7e9ca9:	00 00 00 
  7e9cac:	2b d0                	sub    edx,eax
  7e9cae:	8b ff                	mov    edi,edi
  7e9cb0:	8a 08                	mov    cl,BYTE PTR [eax]
  7e9cb2:	88 0c 02             	mov    BYTE PTR [edx+eax*1],cl
  7e9cb5:	40                   	inc    eax
  7e9cb6:	84 c9                	test   cl,cl
  7e9cb8:	75 f6                	jne    0x7e9cb0
  7e9cba:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7e9cbd:	8d 56 30             	lea    edx,[esi+0x30]
  7e9cc0:	2b d0                	sub    edx,eax
  7e9cc2:	8a 08                	mov    cl,BYTE PTR [eax]
  7e9cc4:	88 0c 02             	mov    BYTE PTR [edx+eax*1],cl
  7e9cc7:	40                   	inc    eax
  7e9cc8:	84 c9                	test   cl,cl
  7e9cca:	75 f6                	jne    0x7e9cc2
  7e9ccc:	8b c6                	mov    eax,esi
  7e9cce:	5d                   	pop    ebp
  7e9ccf:	c2                   	.byte 0xc2

```

### binding gate update (`0x007F2520`–`0x007F25F0`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f2520 <.text+0x3f1520>:
  7f2520:	55                   	push   ebp
  7f2521:	8b ec                	mov    ebp,esp
  7f2523:	6a ff                	push   0xffffffff
  7f2525:	68 3e 27 93 00       	push   0x93273e
  7f252a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7f2530:	50                   	push   eax
  7f2531:	83 ec 0c             	sub    esp,0xc
  7f2534:	56                   	push   esi
  7f2535:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7f253a:	33 c5                	xor    eax,ebp
  7f253c:	50                   	push   eax
  7f253d:	8d 45 f4             	lea    eax,[ebp-0xc]
  7f2540:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7f2546:	8b f1                	mov    esi,ecx
  7f2548:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7f254f:	8b 86 88 00 00 00    	mov    eax,DWORD PTR [esi+0x88]
  7f2555:	8b 48 68             	mov    ecx,DWORD PTR [eax+0x68]
  7f2558:	8b 50 6c             	mov    edx,DWORD PTR [eax+0x6c]
  7f255b:	8b 40 70             	mov    eax,DWORD PTR [eax+0x70]
  7f255e:	89 4d e8             	mov    DWORD PTR [ebp-0x18],ecx
  7f2561:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  7f2564:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7f2567:	75 20                	jne    0x7f2589
  7f2569:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  7f2570:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7f2577:	e8 64 68 fa ff       	call   0x798de0
  7f257c:	68 e0 d2 bc 00       	push   0xbcd2e0
  7f2581:	e8 94 fd 09 00       	call   0x89231a
  7f2586:	83 c4 04             	add    esp,0x4
  7f2589:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  7f2590:	75 07                	jne    0x7f2599
  7f2592:	b8 01 00 00 00       	mov    eax,0x1
  7f2597:	eb 2c                	jmp    0x7f25c5
  7f2599:	d9 86 b0 00 00 00    	fld    DWORD PTR [esi+0xb0]
  7f259f:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  7f25a5:	83 ec 10             	sub    esp,0x10
  7f25a8:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  7f25ac:	d9 45 f0             	fld    DWORD PTR [ebp-0x10]
  7f25af:	d9 5c 24 08          	fstp   DWORD PTR [esp+0x8]
  7f25b3:	d9 45 ec             	fld    DWORD PTR [ebp-0x14]
  7f25b6:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  7f25ba:	d9 45 e8             	fld    DWORD PTR [ebp-0x18]
  7f25bd:	d9 1c 24             	fstp   DWORD PTR [esp]
  7f25c0:	e8 9b 62 04 00       	call   0x838860
  7f25c5:	33 c9                	xor    ecx,ecx
  7f25c7:	85 c0                	test   eax,eax
  7f25c9:	0f 94 c1             	sete   cl
  7f25cc:	8b c1                	mov    eax,ecx
  7f25ce:	89 86 80 00 00 00    	mov    DWORD PTR [esi+0x80],eax
  7f25d4:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f25d7:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f25de:	59                   	pop    ecx
  7f25df:	5e                   	pop    esi
  7f25e0:	8b e5                	mov    esp,ebp
  7f25e2:	5d                   	pop    ebp
  7f25e3:	c3                   	ret
  7f25e4:	cc                   	int3
  7f25e5:	cc                   	int3
  7f25e6:	cc                   	int3
  7f25e7:	cc                   	int3
  7f25e8:	cc                   	int3
  7f25e9:	cc                   	int3
  7f25ea:	cc                   	int3
  7f25eb:	cc                   	int3
  7f25ec:	cc                   	int3
  7f25ed:	cc                   	int3
  7f25ee:	cc                   	int3
  7f25ef:	cc                   	int3

```

### global setup and buckets allocation (`0x00798E60`–`0x00799005`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00798e60 <.text+0x397e60>:
  798e60:	d9 50 18             	fst    DWORD PTR [eax+0x18]
  798e63:	d9 50 1c             	fst    DWORD PTR [eax+0x1c]
  798e66:	d9 50 20             	fst    DWORD PTR [eax+0x20]
  798e69:	d9 50 24             	fst    DWORD PTR [eax+0x24]
  798e6c:	d9 50 28             	fst    DWORD PTR [eax+0x28]
  798e6f:	d9 50 2c             	fst    DWORD PTR [eax+0x2c]
  798e72:	d9 50 30             	fst    DWORD PTR [eax+0x30]
  798e75:	d9 50 34             	fst    DWORD PTR [eax+0x34]
  798e78:	d9 50 38             	fst    DWORD PTR [eax+0x38]
  798e7b:	d9 50 3c             	fst    DWORD PTR [eax+0x3c]
  798e7e:	d9 50 40             	fst    DWORD PTR [eax+0x40]
  798e81:	d9 50 44             	fst    DWORD PTR [eax+0x44]
  798e84:	d9 50 48             	fst    DWORD PTR [eax+0x48]
  798e87:	d9 50 4c             	fst    DWORD PTR [eax+0x4c]
  798e8a:	d9 50 50             	fst    DWORD PTR [eax+0x50]
  798e8d:	d9 50 54             	fst    DWORD PTR [eax+0x54]
  798e90:	d9 50 58             	fst    DWORD PTR [eax+0x58]
  798e93:	d9 58 5c             	fstp   DWORD PTR [eax+0x5c]
  798e96:	eb 02                	jmp    0x798e9a
  798e98:	33 c0                	xor    eax,eax
  798e9a:	6a 30                	push   0x30
  798e9c:	a3 b0 76 fb 00       	mov    ds:0xfb76b0,eax
  798ea1:	89 1d b4 76 fb 00    	mov    DWORD PTR ds:0xfb76b4,ebx
  798ea7:	89 1d b8 76 fb 00    	mov    DWORD PTR ds:0xfb76b8,ebx
  798ead:	89 1d bc 76 fb 00    	mov    DWORD PTR ds:0xfb76bc,ebx
  798eb3:	89 1d c8 76 fb 00    	mov    DWORD PTR ds:0xfb76c8,ebx
  798eb9:	e8 aa 83 0f 00       	call   0x891268
  798ebe:	83 c4 04             	add    esp,0x4
  798ec1:	3b c3                	cmp    eax,ebx
  798ec3:	0f 84 16 06 00 00    	je     0x7994df
  798ec9:	a3 c4 76 fb 00       	mov    ds:0xfb76c4,eax
  798ece:	89 00                	mov    DWORD PTR [eax],eax
  798ed0:	a1 c4 76 fb 00       	mov    eax,ds:0xfb76c4
  798ed5:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  798ed8:	a1 c4 76 fb 00       	mov    eax,ds:0xfb76c4
  798edd:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  798ee0:	a1 c4 76 fb 00       	mov    eax,ds:0xfb76c4
  798ee5:	c6 40 2c 01          	mov    BYTE PTR [eax+0x2c],0x1
  798ee9:	8b 0d c4 76 fb 00    	mov    ecx,DWORD PTR ds:0xfb76c4
  798eef:	c6 41 2d 01          	mov    BYTE PTR [ecx+0x2d],0x1
  798ef3:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  798ef6:	6a 0c                	push   0xc
  798ef8:	89 1d d4 76 fb 00    	mov    DWORD PTR ds:0xfb76d4,ebx
  798efe:	e8 65 83 0f 00       	call   0x891268
  798f03:	83 c4 04             	add    esp,0x4
  798f06:	3b c3                	cmp    eax,ebx
  798f08:	0f 84 ad 05 00 00    	je     0x7994bb
  798f0e:	a3 d0 76 fb 00       	mov    ds:0xfb76d0,eax
  798f13:	89 00                	mov    DWORD PTR [eax],eax
  798f15:	a1 d0 76 fb 00       	mov    eax,ds:0xfb76d0
  798f1a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  798f1d:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  798f21:	bf 01 00 00 00       	mov    edi,0x1
  798f26:	68 58 c0 02 00       	push   0x2c058
  798f2b:	89 1d dc 76 fb 00    	mov    DWORD PTR ds:0xfb76dc,ebx
  798f31:	89 1d e0 76 fb 00    	mov    DWORD PTR ds:0xfb76e0,ebx
  798f37:	89 3d e4 76 fb 00    	mov    DWORD PTR ds:0xfb76e4,edi
  798f3d:	89 1d e8 76 fb 00    	mov    DWORD PTR ds:0xfb76e8,ebx
  798f43:	89 1d 34 77 fb 00    	mov    DWORD PTR ds:0xfb7734,ebx
  798f49:	89 1d 38 77 fb 00    	mov    DWORD PTR ds:0xfb7738,ebx
  798f4f:	e8 14 83 0f 00       	call   0x891268
  798f54:	83 c4 04             	add    esp,0x4
  798f57:	3b c3                	cmp    eax,ebx
  798f59:	74 19                	je     0x798f74
  798f5b:	ba 15 00 00 00       	mov    edx,0x15
  798f60:	8d 88 00 20 00 00    	lea    ecx,[eax+0x2000]
  798f66:	89 19                	mov    DWORD PTR [ecx],ebx
  798f68:	81 c1 04 20 00 00    	add    ecx,0x2004
  798f6e:	2b d7                	sub    edx,edi
  798f70:	79 f4                	jns    0x798f66
  798f72:	eb 02                	jmp    0x798f76
  798f74:	33 c0                	xor    eax,eax
  798f76:	6a 10                	push   0x10
  798f78:	a3 40 77 fb 00       	mov    ds:0xfb7740,eax
  798f7d:	e8 e6 82 0f 00       	call   0x891268
  798f82:	83 c4 04             	add    esp,0x4
  798f85:	3b c3                	cmp    eax,ebx
  798f87:	74 0a                	je     0x798f93
  798f89:	89 18                	mov    DWORD PTR [eax],ebx
  798f8b:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  798f8e:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  798f91:	eb 02                	jmp    0x798f95
  798f93:	33 c0                	xor    eax,eax
  798f95:	6a 14                	push   0x14
  798f97:	a3 44 77 fb 00       	mov    ds:0xfb7744,eax
  798f9c:	89 1d 48 77 fb 00    	mov    DWORD PTR ds:0xfb7748,ebx
  798fa2:	89 1d 4c 77 fb 00    	mov    DWORD PTR ds:0xfb774c,ebx
  798fa8:	89 1d 50 77 fb 00    	mov    DWORD PTR ds:0xfb7750,ebx
  798fae:	89 1d 5c 77 fb 00    	mov    DWORD PTR ds:0xfb775c,ebx
  798fb4:	e8 af 82 0f 00       	call   0x891268
  798fb9:	83 c4 04             	add    esp,0x4
  798fbc:	3b c3                	cmp    eax,ebx
  798fbe:	0f 84 d3 04 00 00    	je     0x799497
  798fc4:	a3 58 77 fb 00       	mov    ds:0xfb7758,eax
  798fc9:	89 00                	mov    DWORD PTR [eax],eax
  798fcb:	a1 58 77 fb 00       	mov    eax,ds:0xfb7758
  798fd0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  798fd3:	a1 58 77 fb 00       	mov    eax,ds:0xfb7758
  798fd8:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  798fdb:	8b 15 58 77 fb 00    	mov    edx,DWORD PTR ds:0xfb7758
  798fe1:	c6 42 10 01          	mov    BYTE PTR [edx+0x10],0x1
  798fe5:	a1 58 77 fb 00       	mov    eax,ds:0xfb7758
  798fea:	c6 40 11 01          	mov    BYTE PTR [eax+0x11],0x1
  798fee:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  798ff2:	6a 14                	push   0x14
  798ff4:	89 1d 6c 77 fb 00    	mov    DWORD PTR ds:0xfb776c,ebx
  798ffa:	e8 69 82 0f 00       	call   0x891268
  798fff:	83 c4 04             	add    esp,0x4
  799002:	3b c3                	cmp    eax,ebx
  799004:	0f                   	.byte 0xf

```

### dispatch producer (`0x007F23B0`–`0x007F24F0`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f23b0 <.text+0x3f13b0>:
  7f23b0:	55                   	push   ebp
  7f23b1:	8b ec                	mov    ebp,esp
  7f23b3:	6a ff                	push   0xffffffff
  7f23b5:	68 ae b9 92 00       	push   0x92b9ae
  7f23ba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7f23c0:	50                   	push   eax
  7f23c1:	83 ec 0c             	sub    esp,0xc
  7f23c4:	53                   	push   ebx
  7f23c5:	56                   	push   esi
  7f23c6:	57                   	push   edi
  7f23c7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7f23cc:	33 c5                	xor    eax,ebp
  7f23ce:	50                   	push   eax
  7f23cf:	8d 45 f4             	lea    eax,[ebp-0xc]
  7f23d2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7f23d8:	8b f1                	mov    esi,ecx
  7f23da:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  7f23dd:	83 7e 7c 00          	cmp    DWORD PTR [esi+0x7c],0x0
  7f23e1:	0f 84 f7 00 00 00    	je     0x7f24de
  7f23e7:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7f23ee:	75 27                	jne    0x7f2417
  7f23f0:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  7f23f7:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7f23fe:	e8 dd 69 fa ff       	call   0x798de0
  7f2403:	68 e0 d2 bc 00       	push   0xbcd2e0
  7f2408:	e8 0d ff 09 00       	call   0x89231a
  7f240d:	83 c4 04             	add    esp,0x4
  7f2410:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7f2417:	8b 86 90 00 00 00    	mov    eax,DWORD PTR [esi+0x90]
  7f241d:	8b 9e 8c 00 00 00    	mov    ebx,DWORD PTR [esi+0x8c]
  7f2423:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  7f2426:	3b d8                	cmp    ebx,eax
  7f2428:	74 7b                	je     0x7f24a5
  7f242a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7f2430:	8b 33                	mov    esi,DWORD PTR [ebx]
  7f2432:	8b 7b 04             	mov    edi,DWORD PTR [ebx+0x4]
  7f2435:	c1 e6 04             	shl    esi,0x4
  7f2438:	81 c6 74 77 fb 00    	add    esi,0xfb7774
  7f243e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7f2441:	8d 4d f0             	lea    ecx,[ebp-0x10]
  7f2444:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
  7f2447:	3b c8                	cmp    ecx,eax
  7f2449:	73 31                	jae    0x7f247c
  7f244b:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7f244d:	8d 55 f0             	lea    edx,[ebp-0x10]
  7f2450:	3b ca                	cmp    ecx,edx
  7f2452:	77 28                	ja     0x7f247c
  7f2454:	8b fa                	mov    edi,edx
  7f2456:	2b f9                	sub    edi,ecx
  7f2458:	c1 ff 02             	sar    edi,0x2
  7f245b:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  7f245e:	75 0c                	jne    0x7f246c
  7f2460:	b9 01 00 00 00       	mov    ecx,0x1
  7f2465:	8b c6                	mov    eax,esi
  7f2467:	e8 a4 9a fa ff       	call   0x79bf10
  7f246c:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7f246f:	85 c0                	test   eax,eax
  7f2471:	74 23                	je     0x7f2496
  7f2473:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7f2475:	8b 14 b9             	mov    edx,DWORD PTR [ecx+edi*4]
  7f2478:	89 10                	mov    DWORD PTR [eax],edx
  7f247a:	eb 1a                	jmp    0x7f2496
  7f247c:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  7f247f:	75 0c                	jne    0x7f248d
  7f2481:	b9 01 00 00 00       	mov    ecx,0x1
  7f2486:	8b c6                	mov    eax,esi
  7f2488:	e8 83 9a fa ff       	call   0x79bf10
  7f248d:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7f2490:	85 c0                	test   eax,eax
  7f2492:	74 02                	je     0x7f2496
  7f2494:	89 38                	mov    DWORD PTR [eax],edi
  7f2496:	83 46 04 04          	add    DWORD PTR [esi+0x4],0x4
  7f249a:	83 c3 08             	add    ebx,0x8
  7f249d:	3b 5d ec             	cmp    ebx,DWORD PTR [ebp-0x14]
  7f24a0:	75 8e                	jne    0x7f2430
  7f24a2:	8b 75 e8             	mov    esi,DWORD PTR [ebp-0x18]
  7f24a5:	8b 86 84 00 00 00    	mov    eax,DWORD PTR [esi+0x84]
  7f24ab:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7f24ae:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7f24b4:	81 c6 84 00 00 00    	add    esi,0x84
  7f24ba:	8b ce                	mov    ecx,esi
  7f24bc:	ff d2                	call   edx
  7f24be:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  7f24c4:	8b 8c 38 00 20 00 00 	mov    ecx,DWORD PTR [eax+edi*1+0x2000]
  7f24cb:	03 c7                	add    eax,edi
  7f24cd:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7f24d3:	7d 09                	jge    0x7f24de
  7f24d5:	89 34 88             	mov    DWORD PTR [eax+ecx*4],esi
  7f24d8:	ff 80 00 20 00 00    	inc    DWORD PTR [eax+0x2000]
  7f24de:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f24e1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f24e8:	59                   	pop    ecx
  7f24e9:	5f                   	pop    edi
  7f24ea:	5e                   	pop    esi
  7f24eb:	5b                   	pop    ebx
  7f24ec:	8b e5                	mov    esp,ebp
  7f24ee:	5d                   	pop    ebp
  7f24ef:	c3                   	ret

```

### bucket cleanup (`0x00799598`–`0x007995C0`)

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00799598 <.text+0x398598>:
  799598:	c7 45 f0 a8 76 fb 00 	mov    DWORD PTR [ebp-0x10],0xfb76a8
  79959f:	c7 45 fc 06 00 00 00 	mov    DWORD PTR [ebp-0x4],0x6
  7995a6:	a1 40 77 fb 00       	mov    eax,ds:0xfb7740
  7995ab:	33 ff                	xor    edi,edi
  7995ad:	3b c7                	cmp    eax,edi
  7995af:	74 0f                	je     0x7995c0
  7995b1:	50                   	push   eax
  7995b2:	e8 55 7c 0f 00       	call   0x89120c
  7995b7:	83 c4 04             	add    esp,0x4
  7995ba:	89 3d 40 77 fb 00    	mov    DWORD PTR ds:0xfb7740,edi

```