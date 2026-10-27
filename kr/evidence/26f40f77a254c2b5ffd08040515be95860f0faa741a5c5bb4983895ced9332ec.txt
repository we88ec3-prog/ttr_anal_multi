# T08-103 — 六平面係數緩衝、分桶生產者與交叉參照

- 研究者：chatgpt-web roy
- 時間：2026-10-27T14:11:26+08:00（Asia/Taipei）
- BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（已驗證）
- 來源：`Tartaros.bin` PE32 `.text` objdump x86 Intel；未修改可執行檔；未 Commit GitHub。

## 一、本段核心成果

1. `0x00FB76B0` 為 heap 緩衝的全域**指標**。`0x00798E3A` 的 `push 0x60` 配置 96 bytes，緊接的 24 個 x87 DWORD 寫入清零；`0x00798E9C` 將返回指標存入該全域欄位。`0x0079963F–0x00799651` 則釋放並清零。這個尺寸與第102段六組、每組四 float 的 `0x00838860` 半空間判斷相符，但不能因此確認相機來源。
2. 直接位址參照 `0x00FB76B0` 的 `.text` 指令集中在配置、釋放及多處判斷**讀取**。未找到係數內容的寫入者：寫入者可能操作別名 heap 指標。不能宣稱係數永遠為零。
3. 除第102段 `0x007F23B0` 外，`0x0079CDA8`、`0x007BED5B`、`0x007CD7C9`、`0x007D34EB` 都具有讀取 `[0x00FB7740]` 並依 `index*0x2004` 選擇分桶、檢查 `<0x800`，附加指標與 `count++` 的確定模式。
4. `0x007FECE9` 的獨立分支使用**常量偏移** `0x14028` 與 `0x16028`；`0x14028 = 10 * 0x2004`，為第10桶的附加寫入者。不同寫入者傳入的物件不應在缺乏配置來源時全部歸類為 Binding。
5. 分桶真正消費者（讀取 entries 後處理）與每幀歸零入口**本段仍未證實**。現有結果應明確分類為寫入端，而不是消費端。

## 二、暫定結構（由長度/跨度驗證，語義名稱非原始符號）

```cpp
struct HalfspaceBuffer { float coefficient[6][4]; }; // 0x60 bytes
struct DispatchBucket { void* entries[2048]; uint32_t count; }; // 0x2004 bytes
struct DispatchBuckets { DispatchBucket buckets[22]; }; // 0x2C058 bytes
```

`0x00798F26` 配置 `0x2C058`，`0x00798F5B` 以固定 `0x2004` 跨度清除 22 個 count。此為容量，不保證每個桶的 bucket-index 多型方法回傳值合法；尚需控制流確認。

## 三、全域參照索引（字面地址，非完整 pointer-alias 分析）

### 0xfb76b0 — 16 個直接指令參照

```asm
  49dafb:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  4aa320:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  4c9beb:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  55b439:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  55b627:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  798e9c:	a3 b0 76 fb 00       	mov    ds:0xfb76b0,eax
  79963f:	a1 b0 76 fb 00       	mov    eax,ds:0xfb76b0
  799651:	89 3d b0 76 fb 00    	mov    DWORD PTR ds:0xfb76b0,edi
  7a5d44:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  7e10e8:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  7e4354:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  7f259f:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  7f3030:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  7f754a:	8b 3d b0 76 fb 00    	mov    edi,DWORD PTR ds:0xfb76b0
  7f98be:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  7fe498:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
```

### 0xfb7740 — 15 個直接指令參照

```asm
  798f78:	a3 40 77 fb 00       	mov    ds:0xfb7740,eax
  7995a6:	a1 40 77 fb 00       	mov    eax,ds:0xfb7740
  7995ba:	89 3d 40 77 fb 00    	mov    DWORD PTR ds:0xfb7740,edi
  79cda8:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7bed5b:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7cd7c9:	8b 35 40 77 fb 00    	mov    esi,DWORD PTR ds:0xfb7740
  7d34eb:	8b 35 40 77 fb 00    	mov    esi,DWORD PTR ds:0xfb7740
  7d357a:	8b 35 40 77 fb 00    	mov    esi,DWORD PTR ds:0xfb7740
  7dc369:	8b 35 40 77 fb 00    	mov    esi,DWORD PTR ds:0xfb7740
  7df5a7:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7e6a52:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7f24ae:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7f96ed:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7fec92:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7fece9:	8b 15 40 77 fb 00    	mov    edx,DWORD PTR ds:0xfb7740
```

### 0xfb76e4 — 13 個直接指令參照

```asm
  49daef:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  4aa314:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  4c9bdf:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  55b42d:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  55b61b:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  798f37:	89 3d e4 76 fb 00    	mov    DWORD PTR ds:0xfb76e4,edi
  7a5d31:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  7e10dc:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  7e4342:	39 35 e4 76 fb 00    	cmp    DWORD PTR ds:0xfb76e4,esi
  7f2589:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  7f301d:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  7f98af:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  7fe488:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
```

## 四、原始 BIN 逐段反組譯（所列位址為指令內地址，不全是函式入口）

### 係數緩衝初始化 — `0x00798E3A–0x00798EA8`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00798e3a <.text+0x397e3a>:
  798e3a:	6a 60                	push   0x60
  798e3c:	a3 ac 76 fb 00       	mov    ds:0xfb76ac,eax
  798e41:	e8 22 84 0f 00       	call   0x891268
  798e46:	83 c4 04             	add    esp,0x4
  798e49:	3b c3                	cmp    eax,ebx
  798e4b:	74 4b                	je     0x798e98
  798e4d:	d9 ee                	fldz
  798e4f:	d9 10                	fst    DWORD PTR [eax]
  798e51:	d9 50 04             	fst    DWORD PTR [eax+0x4]
  798e54:	d9 50 08             	fst    DWORD PTR [eax+0x8]
  798e57:	d9 50 0c             	fst    DWORD PTR [eax+0xc]
  798e5a:	d9 50 10             	fst    DWORD PTR [eax+0x10]
  798e5d:	d9 50 14             	fst    DWORD PTR [eax+0x14]
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
  798ea7:	89                   	.byte 0x89
```

### 係數緩衝釋放 — `0x0079963F–0x00799657`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0079963f <.text+0x39863f>:
  79963f:	a1 b0 76 fb 00       	mov    eax,ds:0xfb76b0
  799644:	3b c7                	cmp    eax,edi
  799646:	74 0f                	je     0x799657
  799648:	50                   	push   eax
  799649:	e8 be 7b 0f 00       	call   0x89120c
  79964e:	83 c4 04             	add    esp,0x4
  799651:	89 3d b0 76 fb 00    	mov    DWORD PTR ds:0xfb76b0,edi
```

### 分桶配置 — `0x00798F26–0x00798F7D`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00798f26 <.text+0x397f26>:
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
```

### 通用分桶 append A — `0x0079CDA3–0x0079CDD2`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0079cda3 <.text+0x39bda3>:
  79cda3:	8b 06                	mov    eax,DWORD PTR [esi]
  79cda5:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  79cda8:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  79cdae:	8b ce                	mov    ecx,esi
  79cdb0:	ff d2                	call   edx
  79cdb2:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  79cdb8:	8b 8c 38 00 20 00 00 	mov    ecx,DWORD PTR [eax+edi*1+0x2000]
  79cdbf:	03 c7                	add    eax,edi
  79cdc1:	81 f9 00 08 00 00    	cmp    ecx,0x800
  79cdc7:	7d 09                	jge    0x79cdd2
  79cdc9:	89 34 88             	mov    DWORD PTR [eax+ecx*4],esi
  79cdcc:	ff 80 00 20 00 00    	inc    DWORD PTR [eax+0x2000]
```

### 通用分桶 append B — `0x007BED56–0x007BED85`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bed56 <.text+0x3bdd56>:
  7bed56:	8b 06                	mov    eax,DWORD PTR [esi]
  7bed58:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7bed5b:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7bed61:	8b ce                	mov    ecx,esi
  7bed63:	ff d2                	call   edx
  7bed65:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  7bed6b:	8b 8c 38 00 20 00 00 	mov    ecx,DWORD PTR [eax+edi*1+0x2000]
  7bed72:	03 c7                	add    eax,edi
  7bed74:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7bed7a:	7d 09                	jge    0x7bed85
  7bed7c:	89 34 88             	mov    DWORD PTR [eax+ecx*4],esi
  7bed7f:	ff 80 00 20 00 00    	inc    DWORD PTR [eax+0x2000]
```

### 通用分桶 append C — `0x007CD7C1–0x007CD7F3`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007cd7c1 <.text+0x3cc7c1>:
  7cd7c1:	8b 7d e4             	mov    edi,DWORD PTR [ebp-0x1c]
  7cd7c4:	8b 17                	mov    edx,DWORD PTR [edi]
  7cd7c6:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7cd7c9:	8b 35 40 77 fb 00    	mov    esi,DWORD PTR ds:0xfb7740
  7cd7cf:	8b cf                	mov    ecx,edi
  7cd7d1:	ff d0                	call   eax
  7cd7d3:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  7cd7d9:	8b 8c 30 00 20 00 00 	mov    ecx,DWORD PTR [eax+esi*1+0x2000]
  7cd7e0:	03 c6                	add    eax,esi
  7cd7e2:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7cd7e8:	7d 09                	jge    0x7cd7f3
  7cd7ea:	89 3c 88             	mov    DWORD PTR [eax+ecx*4],edi
  7cd7ed:	ff 80 00 20 00 00    	inc    DWORD PTR [eax+0x2000]
```

### 條件式 append — `0x007D34E8–0x007D351E`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007d34e8 <.text+0x3d24e8>:
  7d34e8:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7d34eb:	8b 35 40 77 fb 00    	mov    esi,DWORD PTR ds:0xfb7740
  7d34f1:	85 c0                	test   eax,eax
  7d34f3:	75 09                	jne    0x7d34fe
  7d34f5:	8b 03                	mov    eax,DWORD PTR [ebx]
  7d34f7:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7d34fa:	8b cb                	mov    ecx,ebx
  7d34fc:	ff d2                	call   edx
  7d34fe:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  7d3504:	8b 8c 30 00 20 00 00 	mov    ecx,DWORD PTR [eax+esi*1+0x2000]
  7d350b:	03 c6                	add    eax,esi
  7d350d:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7d3513:	7d 09                	jge    0x7d351e
  7d3515:	89 1c 88             	mov    DWORD PTR [eax+ecx*4],ebx
  7d3518:	01 b8 00 20 00 00    	add    DWORD PTR [eax+0x2000],edi
```

### 第10桶固定偏移 append — `0x007FECE9–0x007FED0A`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007fece9 <.text+0x3fdce9>:
  7fece9:	8b 15 40 77 fb 00    	mov    edx,DWORD PTR ds:0xfb7740
  7fecef:	8b 8a 28 60 01 00    	mov    ecx,DWORD PTR [edx+0x16028]
  7fecf5:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7fecfb:	7d 0d                	jge    0x7fed0a
  7fecfd:	89 b4 8a 28 40 01 00 	mov    DWORD PTR [edx+ecx*4+0x14028],esi
  7fed04:	ff 82 28 60 01 00    	inc    DWORD PTR [edx+0x16028]
```

### 另一個六平面測試使用者 — `0x007F7545–0x007F7584`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f7545 <.text+0x3f6545>:
  7f7545:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7f7548:	8b 30                	mov    esi,DWORD PTR [eax]
  7f754a:	8b 3d b0 76 fb 00    	mov    edi,DWORD PTR ds:0xfb76b0
  7f7550:	85 f6                	test   esi,esi
  7f7552:	0f 84 15 01 00 00    	je     0x7f766d
  7f7558:	d9 46 68             	fld    DWORD PTR [esi+0x68]
  7f755b:	83 ec 10             	sub    esp,0x10
  7f755e:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  7f7562:	8b d7                	mov    edx,edi
  7f7564:	d9 46 34             	fld    DWORD PTR [esi+0x34]
  7f7567:	d9 5c 24 08          	fstp   DWORD PTR [esp+0x8]
  7f756b:	d9 46 30             	fld    DWORD PTR [esi+0x30]
  7f756e:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  7f7572:	d9 46 2c             	fld    DWORD PTR [esi+0x2c]
  7f7575:	d9 1c 24             	fstp   DWORD PTR [esp]
  7f7578:	e8 e3 12 04 00       	call   0x838860
  7f757d:	85 c0                	test   eax,eax
  7f757f:	75 16                	jne    0x7f7597
  7f7581:	89 46 6c             	mov    DWORD PTR [esi+0x6c],eax
```

### 分桶清理 — `0x007995A6–0x007995BF`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007995a6 <.text+0x3985a6>:
  7995a6:	a1 40 77 fb 00       	mov    eax,ds:0xfb7740
  7995ab:	33 ff                	xor    edi,edi
  7995ad:	3b c7                	cmp    eax,edi
  7995af:	74 0f                	je     0x7995c0
  7995b1:	50                   	push   eax
  7995b2:	e8 55 7c 0f 00       	call   0x89120c
  7995b7:	83 c4 04             	add    esp,0x4
  7995ba:	89                   	.byte 0x89
  7995bb:	3d                   	.byte 0x3d
  7995bc:	40                   	inc    eax
  7995bd:	77 fb                	ja     0x7995ba
```

## 五、完成/推測/未解決

**直接已確認**：24 float 清零初始化、`0x60` 配置、釋放路徑、多個 `0x2004` stride 桶 append、`0x800` cap、固定第10桶插入。

**合理推測**：六組係數表示幾何半空間；相關 Binding 幾何判斷參與可見性/空間篩選。但相機/陰影/空間系統具體角色無法命名。

**未確認**：六平面數值寫入者、視圖矩陣來源、分桶消費端、每幀分桶 reset、各種物件的確切型別及場景主更新迴圈 `object vtable+0x20`。

## 六、T08-104 建議

從六平面 buffer 參數指標被暫存/傳遞的資料流開始搜尋 `movups/movss/fstp` 關聯寫入；分桶則專找對 `entries[i]` 的讀取後間接呼叫/提交，並確認相鄰 count 歸零的位置。分辨 append writer 和 dispatch reader，防止錯誤歸因。