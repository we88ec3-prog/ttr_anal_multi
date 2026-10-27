# T08-095 — binding 名稱解析、子項虛擬調度與解除綁定閉環

- 研究者：`chatgpt-web roy`
- 時間（Asia/Taipei）：`2026-10-27T10:51:07.947354+08:00`
- BIN：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，符合交接 SHA256。
- 來源：原始 PE32 BIN 經 `objdump -D -Mintel`，並以 BIN `.text` E8 rel32 位移掃描 xrefs；本筆記不以反編譯或臆測冒充機器碼。
- GitHub：未提交、未修改 main。

## 1. 本段與 T08-093/094 的新增連結

第94段已確認資源 `resource+0x04/+0x08` 是 4-byte 子項指標陣列，`0x007BDF00` 透過 item `+0x08` 的 binding 執行 slot `+0x20`。第95段首次以 BIN 完整串聯：

```
0x007DCFB0（資源取得/建立）
  ├─ resource 新建／指標陣列初始化
  └─ manager+0x44 >= 1 → 0x007BDF90(resource)
      ├─ item+0x04 名稱指標
      ├─ 全域 0x00FE173C 名稱集合 → 0x007B86F0（按名稱 lookup）
      ├─ 命中後 node+0x24 關聯物件 → vtable+0x10 → binding
      ├─ item+0x08 = binding（可為 NULL，缺失走診斷回報路徑）
      ├─ 0x007BE150(resource) 同步聚合及變換
      └─ resource+0x74=1
resource 更新：0x007BD8D0 → 子項更新 slot +0x1C
   ├─ 0x007BDF00(resource, external) → binding slot +0x20
   └─ 0x007BDF40(resource)（多來源）→ binding slot +0x18，受 item[0]、binding+0x80 gate
resource 釋放：0x007BE5F0 →（滿足分支）0x007BE0F0
   ├─ binding slot +0x08（無顯式參數）
   ├─ binding slot +0x00（push 1，可能 deleting destructor；未驗證）
   ├─ item+0x08 = 0
   └─ resource+0x74 = 0
```

**重要限制**：目前只定位到產生 binding 指標的介面 `node+0x24 -> vtable+0x10`，仍未定位其多型實體 vtable 常量與實作函式，故不能聲稱 `slot+0x18` 的具體意義已確認。`+0x80` 為獨立 binding 物件偏移，不能混同 manager、resource 或場景物件。

## 2. 核心新發現（已由機器碼確證）

1. `0x007BDF90` 使用 `item+0x04` 存放的 C 字串，建立暫時字串，交由 `0x007B86F0` 查詢全域 `0x00FE173C` 名稱容器。
2. 查到的樹節點不是 binding：`0x007BE082 mov ecx,[eax+24h]` 先取另一層關聯物件，再調其 vtable slot `+0x10`；回傳的 `eax` 才寫到 `item+0x08`。此來源鏈比「同偏移必然相同型別」更有力。
3. 缺少關聯時 `item+0x08` 為 0，`0x007BE099..AC` 會由 item 名稱指標走外部診斷呼叫 `[0xBD2490]`；其字串含義、嚴重性仍未考證，**不能直接認定會終止程式**。
4. `0x007BDF90` 完成後呼叫 `0x007BE150(resource)`，並寫 `resource+0x74=1`。相對的 `0x007BE0F0` 清除 binding 並寫 `resource+0x74=0`，建立明確的開關成對關係。
5. `0x007BE0F0` 循環讀 `item+0x08`；非空時先呼叫 binding vtable `+0x08`，再 `push 1` 呼叫 `+0x00`，並把 `item+0x08` 清 0。虛擬 slot `+0x00` 形態符合刪除析構器但實作未定位，**只能標注 probable**。
6. `0x007DCFB0` 在建好 resource 後檢查 **`manager+0x44 >= 1`** 才呼叫 `0x007BDF90`，表示 binding 可因管理器模式而延遲/略過，不能假設所有取得資源都已綁定。
7. `0x007BE5F0` 的釋放分支呼叫 `0x007BE0F0` 並與 `0x007BD850`、`0x0089120C` 串接；另一分支可進 `0x007DD1A0` 共享復用池，與 T08-079～094 的兩種終止方式連結。
8. `0x007BDF00` 不檢查 binding 是否非空而直接解參照，相對 `0x007BDF40` 有明確的空值檢查。這是程式內可觀察到的 **不同前置條件**，不等於可利用弱點。

## 3. 關鍵 Assembly

```asm
007BE006 mov ecx,[ebx+04h]   ; item 名稱
007BE009 mov esi,[0FE173Ch] ; 全域名稱集合
007BE04A call 007B86F0      ; 名稱查找
007BE068 mov eax,[ebp-38h]  ; 查詢結果
007BE07D cmp eax,[esi+04h]  ; sentinel 比較
007BE082 mov ecx,[eax+24h]  ; 命中的另一個關聯物件
007BE089 mov eax,[ecx]
007BE08B mov edx,[eax+10h]
007BE08E call edx
007BE090 mov [ebx+08h],eax   ; binding 回傳指標
007BE0C4 call 007BE150
007BE0C9 mov dword ptr [esi+74h],1
```

```asm
007BE108 mov ecx,[esi+08h]
007BE10B test ecx,ecx
007BE111 mov edx,[eax+08h]
007BE114 call edx            ; binding slot +08
007BE116 mov ecx,[esi+08h]
007BE121 push 1
007BE123 call edx            ; binding slot +00
007BE125 mov dword ptr [esi+08h],0
007BE138 mov dword ptr [eax+74h],0
```

```asm
007DD0E4 cmp dword ptr [ebx+44h],1
007DD0E8 jl 007DD0F1
007DD0EA mov ecx,esi
007DD0EC call 007BDF90
```

## 4. 指標與物件型別分離

| 來源 | 指向物件 | 確認偏移 | 角色（暫定） |
|---|---|---|---|
| resource+0x04..08 | DWORD* 指標陣列 | element 4 bytes | 子項指標集合 |
| item | 子項結構 | +0x00 byte gate；+0x04 char*；+0x08 binding* | 名稱引用與 binding 持有者 |
| 全域 0xFE173C | 名稱容器 | lookup sentinel +0x04 | 將 item 名稱映射至樹節點 |
| 命中 node | 名稱樹節點 | +0x24 pointer | 對應可產生 binding 的多型物件 |
| provider object | vtable 物件 | +0x10 virtual slot | 回傳 binding* |
| binding | 多型物件 | vtable+0,+8,+18,+20；field+0x80 | 子項資料和虛擬行為，精確類型不明 |
| resource | 0x7C-byte 底層物件 | +0x74 開關 | binding 初始化／解除狀態 |
| resource manager | 資源管理器 | +0x44 | 是否在取得路徑執行 binding 初始化 |

## 5. 可供後續辨識 vtable 的目標

- 從 `0x007B86F0` 命中的 `node+0x24` **實際填入者**入手，找 provider vtable 常量、slot `+0x10` 的實作返回值。
- 再從 provider slot `+0x10` 返回的 binding 分配者追 ctor 常量 vtable，最後確認 slot `+0x18/+0x20`，及 `binding+0x80` 的初始化／改寫點。
- 對 `0x007BDF00` 的非空前置條件尋找 caller gate（目前唯一直接 caller `0x007A8937`）；避免誤解為無條件安全。
- `0x007BDF40` 多個使用方包括場景相關 `0x00492C0B` / `0x004C8929` / `0x004CB062` / `0x004D2C82`；可沿任一存活物件生命週期追。
- 尚未定位場景 `object vtable+0x20` 真正上層迴圈，不得與本次 binding 或 manager 之同 offset 虛擬呼叫混淆。

## 6. 待驗證／風險邊界

- provider vtable 常量與 `+0x10` 確切實作未定位。
- binding vtable 常量與 `+0x08/+0x18/+0x20` 實作未定位。
- `binding+0x80` 寫入者未定位；只知 `0x007BDF40` 會檢查該欄位為零。
- `resource+0x74=1` 是否代表「全子項已成功綁定」不成立：有 missing binding 診斷路徑，仍可寫 1。較保守的語意是「binding resolution pass 已執行」。
- `manager+0x44` 的完整模式範圍未驗證；只證實此處對值 `>=1` 的條件。
- 所有未確認名稱皆為研究者暫名，沒有原始符號證據。

## 7. E8 rel32 掃描：直接呼叫者（BIN 全 `.text`，需依連續反組譯逐個確認）


- `0x007BDF90`：1 位置；0x007DD0EC

- `0x007BE0F0`：7 位置；0x007A53F4, 0x007A5A0C, 0x007A5AE8, 0x007A7914, 0x007A874E, 0x007BE626, 0x007DD21B

- `0x007BDF40`：13 位置；0x00492C0B, 0x004C8929, 0x004C894E, 0x004CB062, 0x004CC705, 0x004CC71D, 0x004CE2CE, 0x004D0863, 0x004D1242, 0x004D2C82, 0x007A6694, 0x007A66A9, 0x007FF8E4

- `0x007BDF00`：1 位置；0x007A8937

- `0x007B86F0`：14 位置；0x007194D9, 0x0071954A, 0x00719868, 0x00719A09, 0x007B80FA, 0x007B81E5, 0x007B8360, 0x007B84F7, 0x007BE04A, 0x007D09B1, 0x007D0E89, 0x007DC573, 0x007DC78B, 0x007DC868


## 8. BIN 原始反組譯附錄（機器碼列印，原樣供複核）

### A. binding 解析與綁定：`0x007BDF90`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdf90 <.text+0x3bcf90>:
  7bdf90:	55                   	push   ebp
  7bdf91:	8b ec                	mov    ebp,esp
  7bdf93:	6a ff                	push   0xffffffff
  7bdf95:	68 b6 8a 91 00       	push   0x918ab6
  7bdf9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7bdfa0:	50                   	push   eax
  7bdfa1:	83 ec 2c             	sub    esp,0x2c
  7bdfa4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7bdfa9:	33 c5                	xor    eax,ebp
  7bdfab:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7bdfae:	53                   	push   ebx
  7bdfaf:	56                   	push   esi
  7bdfb0:	57                   	push   edi
  7bdfb1:	50                   	push   eax
  7bdfb2:	8d 45 f4             	lea    eax,[ebp-0xc]
  7bdfb5:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7bdfbb:	8b f1                	mov    esi,ecx
  7bdfbd:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7bdfc0:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  7bdfc3:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  7bdfc6:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  7bdfc9:	0f 84 f4 00 00 00    	je     0x7be0c3
  7bdfcf:	eb 03                	jmp    0x7bdfd4
  7bdfd1:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7bdfd4:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7bdfdb:	8b 18                	mov    ebx,DWORD PTR [eax]
  7bdfdd:	75 27                	jne    0x7be006
  7bdfdf:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7bdfe6:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7bdfed:	e8 ae 9d ff ff       	call   0x7b7da0
  7bdff2:	68 90 e7 bc 00       	push   0xbce790
  7bdff7:	e8 1e 43 0d 00       	call   0x89231a
  7bdffc:	83 c4 04             	add    esp,0x4
  7bdfff:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7be006:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  7be009:	8b 35 3c 17 fe 00    	mov    esi,DWORD PTR ds:0xfe173c
  7be00f:	8b c1                	mov    eax,ecx
  7be011:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7be018:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7be01f:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7be023:	8d 78 01             	lea    edi,[eax+0x1]
  7be026:	8a 10                	mov    dl,BYTE PTR [eax]
  7be028:	40                   	inc    eax
  7be029:	84 d2                	test   dl,dl
  7be02b:	75 f9                	jne    0x7be026
  7be02d:	2b c7                	sub    eax,edi
  7be02f:	50                   	push   eax
  7be030:	51                   	push   ecx
  7be031:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7be034:	e8 37 4a c4 ff       	call   0x402a70
  7be039:	8d 45 d4             	lea    eax,[ebp-0x2c]
  7be03c:	50                   	push   eax
  7be03d:	8d 4d c8             	lea    ecx,[ebp-0x38]
  7be040:	51                   	push   ecx
  7be041:	8b c6                	mov    eax,esi
  7be043:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7be04a:	e8 a1 a6 ff ff       	call   0x7b86f0
  7be04f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7be056:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  7be05a:	72 0c                	jb     0x7be068
  7be05c:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  7be05f:	52                   	push   edx
  7be060:	e8 a7 31 0d 00       	call   0x89120c
  7be065:	83 c4 04             	add    esp,0x4
  7be068:	8b 45 c8             	mov    eax,DWORD PTR [ebp-0x38]
  7be06b:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7be072:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  7be079:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  7be07d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  7be080:	74 11                	je     0x7be093
  7be082:	8b 48 24             	mov    ecx,DWORD PTR [eax+0x24]
  7be085:	85 c9                	test   ecx,ecx
  7be087:	74 0a                	je     0x7be093
  7be089:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be08b:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  7be08e:	ff d2                	call   edx
  7be090:	89 43 08             	mov    DWORD PTR [ebx+0x8],eax
  7be093:	83 7b 08 00          	cmp    DWORD PTR [ebx+0x8],0x0
  7be097:	75 13                	jne    0x7be0ac
  7be099:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7be09c:	6a 00                	push   0x0
  7be09e:	50                   	push   eax
  7be09f:	68 ec fc c4 00       	push   0xc4fcec
  7be0a4:	6a 00                	push   0x0
  7be0a6:	ff 15 90 24 bd 00    	call   DWORD PTR ds:0xbd2490
  7be0ac:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7be0af:	8b 4d cc             	mov    ecx,DWORD PTR [ebp-0x34]
  7be0b2:	83 c0 04             	add    eax,0x4
  7be0b5:	89 45 d0             	mov    DWORD PTR [ebp-0x30],eax
  7be0b8:	3b 41 08             	cmp    eax,DWORD PTR [ecx+0x8]
  7be0bb:	0f 85 10 ff ff ff    	jne    0x7bdfd1
  7be0c1:	8b f1                	mov    esi,ecx
  7be0c3:	56                   	push   esi
  7be0c4:	e8 87 00 00 00       	call   0x7be150
  7be0c9:	c7 46 74 01 00 00 00 	mov    DWORD PTR [esi+0x74],0x1
  7be0d0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7be0d3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7be0da:	59                   	pop    ecx
  7be0db:	5f                   	pop    edi
  7be0dc:	5e                   	pop    esi
  7be0dd:	5b                   	pop    ebx
  7be0de:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  7be0e1:	33 cd                	xor    ecx,ebp
  7be0e3:	e8 19 2f 0d 00       	call   0x891001
  7be0e8:	8b e5                	mov    esp,ebp
  7be0ea:	5d                   	pop    ebp
  7be0eb:	c3                   	ret

```

### B. binding 解綁：`0x007BE0F0`

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007be0f0 <.text+0x3bd0f0>:
  7be0f0:	55                   	push   ebp
  7be0f1:	8b ec                	mov    ebp,esp
  7be0f3:	51                   	push   ecx
  7be0f4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7be0f7:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7be0fa:	57                   	push   edi
  7be0fb:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  7be0fe:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  7be101:	3b f9                	cmp    edi,ecx
  7be103:	74 33                	je     0x7be138
  7be105:	56                   	push   esi
  7be106:	8b 37                	mov    esi,DWORD PTR [edi]
  7be108:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7be10b:	85 c9                	test   ecx,ecx
  7be10d:	74 1d                	je     0x7be12c
  7be10f:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be111:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7be114:	ff d2                	call   edx
  7be116:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7be119:	85 c9                	test   ecx,ecx
  7be11b:	74 0f                	je     0x7be12c
  7be11d:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be11f:	8b 10                	mov    edx,DWORD PTR [eax]
  7be121:	6a 01                	push   0x1
  7be123:	ff d2                	call   edx
  7be125:	c7 46 08 00 00 00 00 	mov    DWORD PTR [esi+0x8],0x0
  7be12c:	83 c7 04             	add    edi,0x4
  7be12f:	3b 7d fc             	cmp    edi,DWORD PTR [ebp-0x4]
  7be132:	75 d2                	jne    0x7be106
  7be134:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7be137:	5e                   	pop    esi
  7be138:	c7 40 74 00 00 00 00 	mov    DWORD PTR [eax+0x74],0x0
  7be13f:	5f                   	pop    edi
  7be140:	8b e5                	mov    esp,ebp
  7be142:	5d                   	pop    ebp
  7be143:	c2 04 00             	ret    0x4

```

### C. binding 更新 slot+0x18/0x20

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdf00 <.text+0x3bcf00>:
  7bdf00:	55                   	push   ebp
  7bdf01:	8b ec                	mov    ebp,esp
  7bdf03:	53                   	push   ebx
  7bdf04:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7bdf07:	56                   	push   esi
  7bdf08:	57                   	push   edi
  7bdf09:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7bdf0c:	2b 7b 04             	sub    edi,DWORD PTR [ebx+0x4]
  7bdf0f:	33 f6                	xor    esi,esi
  7bdf11:	c1 ff 02             	sar    edi,0x2
  7bdf14:	85 ff                	test   edi,edi
  7bdf16:	74 21                	je     0x7bdf39
  7bdf18:	eb 06                	jmp    0x7bdf20
  7bdf1a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bdf20:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7bdf23:	8b 04 b0             	mov    eax,DWORD PTR [eax+esi*4]
  7bdf26:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7bdf29:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bdf2b:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7bdf2e:	8b 52 20             	mov    edx,DWORD PTR [edx+0x20]
  7bdf31:	50                   	push   eax
  7bdf32:	ff d2                	call   edx
  7bdf34:	46                   	inc    esi
  7bdf35:	3b f7                	cmp    esi,edi
  7bdf37:	72 e7                	jb     0x7bdf20
  7bdf39:	5f                   	pop    edi
  7bdf3a:	5e                   	pop    esi
  7bdf3b:	5b                   	pop    ebx
  7bdf3c:	5d                   	pop    ebp
  7bdf3d:	c2 08 00             	ret    0x8
  7bdf40:	55                   	push   ebp
  7bdf41:	8b ec                	mov    ebp,esp
  7bdf43:	53                   	push   ebx
  7bdf44:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7bdf47:	56                   	push   esi
  7bdf48:	57                   	push   edi
  7bdf49:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7bdf4c:	2b 7b 04             	sub    edi,DWORD PTR [ebx+0x4]
  7bdf4f:	33 f6                	xor    esi,esi
  7bdf51:	c1 ff 02             	sar    edi,0x2
  7bdf54:	85 ff                	test   edi,edi
  7bdf56:	74 31                	je     0x7bdf89
  7bdf58:	eb 06                	jmp    0x7bdf60
  7bdf5a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bdf60:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7bdf63:	8b 04 b0             	mov    eax,DWORD PTR [eax+esi*4]
  7bdf66:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7bdf69:	85 c9                	test   ecx,ecx
  7bdf6b:	74 17                	je     0x7bdf84
  7bdf6d:	80 38 00             	cmp    BYTE PTR [eax],0x0
  7bdf70:	75 12                	jne    0x7bdf84
  7bdf72:	83 b9 80 00 00 00 00 	cmp    DWORD PTR [ecx+0x80],0x0
  7bdf79:	75 09                	jne    0x7bdf84
  7bdf7b:	8b c1                	mov    eax,ecx
  7bdf7d:	8b 10                	mov    edx,DWORD PTR [eax]
  7bdf7f:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  7bdf82:	ff d0                	call   eax
  7bdf84:	46                   	inc    esi
  7bdf85:	3b f7                	cmp    esi,edi
  7bdf87:	72 d7                	jb     0x7bdf60
  7bdf89:	5f                   	pop    edi
  7bdf8a:	5e                   	pop    esi
  7bdf8b:	5b                   	pop    ebx
  7bdf8c:	5d                   	pop    ebp
  7bdf8d:	c2 04 00             	ret    0x4

```

### D. 來源 `0x007DCFB0` 末段與選擇性初始化

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007dd0b0 <.text+0x3dc0b0>:
  7dd0b0:	8b 14 b9             	mov    edx,DWORD PTR [ecx+edi*4]
  7dd0b3:	89 10                	mov    DWORD PTR [eax],edx
  7dd0b5:	eb 16                	jmp    0x7dd0cd
  7dd0b7:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  7dd0ba:	75 08                	jne    0x7dd0c4
  7dd0bc:	8d 46 04             	lea    eax,[esi+0x4]
  7dd0bf:	e8 6c a8 fb ff       	call   0x797930
  7dd0c4:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  7dd0c7:	85 c0                	test   eax,eax
  7dd0c9:	74 02                	je     0x7dd0cd
  7dd0cb:	89 38                	mov    DWORD PTR [eax],edi
  7dd0cd:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  7dd0d0:	83 46 08 04          	add    DWORD PTR [esi+0x8],0x4
  7dd0d4:	40                   	inc    eax
  7dd0d5:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  7dd0d8:	3b 45 f4             	cmp    eax,DWORD PTR [ebp-0xc]
  7dd0db:	0f 82 73 ff ff ff    	jb     0x7dd054
  7dd0e1:	8b 75 f8             	mov    esi,DWORD PTR [ebp-0x8]
  7dd0e4:	83 7b 44 01          	cmp    DWORD PTR [ebx+0x44],0x1
  7dd0e8:	7c 07                	jl     0x7dd0f1
  7dd0ea:	8b ce                	mov    ecx,esi
  7dd0ec:	e8 9f 0e fe ff       	call   0x7bdf90
  7dd0f1:	5f                   	pop    edi
  7dd0f2:	8b c6                	mov    eax,esi
  7dd0f4:	5e                   	pop    esi
  7dd0f5:	5b                   	pop    ebx
  7dd0f6:	8b e5                	mov    esp,ebp
  7dd0f8:	5d                   	pop    ebp
  7dd0f9:	c2 04 00             	ret    0x4

```

### E. 直接釋放分支與共享回收模式

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007be600 <.text+0x3bd600>:
  7be600:	74 85                	je     0x7be587
  7be602:	c9                   	leave
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
  7be64c:	c7 06 00 00      	mov    DWORD PTR [esi],0x0

```

### F. 單一資源 item 與子項初始結構的製作片段

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bd740 <.text+0x3bc740>:
  7bd740:	55                   	push   ebp
  7bd741:	8b ec                	mov    ebp,esp
  7bd743:	6a ff                	push   0xffffffff
  7bd745:	68 4b 19 91 00       	push   0x91194b
  7bd74a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7bd750:	50                   	push   eax
  7bd751:	56                   	push   esi
  7bd752:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7bd757:	33 c5                	xor    eax,ebp
  7bd759:	50                   	push   eax
  7bd75a:	8d 45 f4             	lea    eax,[ebp-0xc]
  7bd75d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7bd763:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  7bd766:	8b 07                	mov    eax,DWORD PTR [edi]
  7bd768:	89 06                	mov    DWORD PTR [esi],eax
  7bd76a:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  7bd76d:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  7bd770:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  7bd773:	6a ff                	push   0xffffffff
  7bd775:	8d 4e 0c             	lea    ecx,[esi+0xc]
  7bd778:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  7bd77b:	6a 00                	push   0x0
  7bd77d:	8d 47 0c             	lea    eax,[edi+0xc]
  7bd780:	c7 41 14 0f 00 00 00 	mov    DWORD PTR [ecx+0x14],0xf
  7bd787:	c7 41 10 00 00 00 00 	mov    DWORD PTR [ecx+0x10],0x0
  7bd78e:	50                   	push   eax
  7bd78f:	c6 01 00             	mov    BYTE PTR [ecx],0x0
  7bd792:	e8 a9 58 c4 ff       	call   0x403040
  7bd797:	6a ff                	push   0xffffffff
  7bd799:	8d 4e 28             	lea    ecx,[esi+0x28]
  7bd79c:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7bd7a3:	6a 00                	push   0x0
  7bd7a5:	8d 57 28             	lea    edx,[edi+0x28]
  7bd7a8:	c7 41 14 0f 00 00 00 	mov    DWORD PTR [ecx+0x14],0xf
  7bd7af:	c7 41 10 00 00 00 00 	mov    DWORD PTR [ecx+0x10],0x0
  7bd7b6:	52                   	push   edx
  7bd7b7:	c6 01 00             	mov    BYTE PTR [ecx],0x0
  7bd7ba:	e8 81 58 c4 ff       	call   0x403040
  7bd7bf:	8b 47 44             	mov    eax,DWORD PTR [edi+0x44]
  7bd7c2:	89 46 44             	mov    DWORD PTR [esi+0x44],eax
  7bd7c5:	8b c6                	mov    eax,esi
  7bd7c7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bd7ca:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7bd7d1:	59                   	pop    ecx
  7bd7d2:	5e                   	pop    esi
  7bd7d3:	8b e5                	mov    esp,ebp
  7bd7d5:	5d                   	pop    ebp
  7bd7d6:	c2 04 00             	ret    0x4

```