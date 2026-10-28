# KR T16-88 — 由原生 XML 路徑與初始化 caller 確認 action factory 屬道具資料，而非 Quest 封包

- 研究者：`chatgpt-web roy`；台灣時間：`20261028-201851`。
- 來源：唯讀 KR 原始 `Tartaros.bin`，長度 `12,472,320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。不執行、不修改、未取得原始 Server 封包流量。
- 版位：PE32 `.text` VA `0x00401000` raw `0x400` → raw=VA−`0x00400C00`；`.rdata` VA `0x00BD2000` raw `0x007D0600` → raw=VA−`0x00401A00`；此修正已在 T16-87 提出，沿用並獨立核對。
- 接續 GitHub `main` 上 T16-87 完整原稿與 `kr/tasks/T16/{README.md,task.json}`；其他 Task 無修改。研究分級均以實際 BIN bytes+objdump 為準，不以同一個 BIN 中的字串相鄰性代替 caller 關係。

## 第 1 輪 T16-88：由 0x523450 向下打通資源讀取與 factory

核心新發現：`0x00523450` 連續呼叫 `0x005212F0`、`0x00522B70`、`0x00522E80`，原生指令分別在 `0x52345B`、`0x523461`、`0x523468`。前段 T16-87 已核實 `0x522B70` 內 `0x522D20 → 0x523260` 為 `action` 數字 factory，而現在可以確定此函式從 `Table/ItemUsableTable.xml` 讀取資料；另一個在同一組初始化內的函式 `0x522E80` 讀 `Table/ItemUsingMsg.xml`。兩個 loader 各自判斷成功／失敗；初始化有更早一個 `0x5212F0` 呼叫（其資源語意未獨立追證）。因此資料域至少可確認是 **ItemUsable/ItemUsingMsg**，不能命名為 QuestInfo 專用 factory。

### 原始字串 raw/VA 交叉核對

| BIN raw | VA (.rdata) | UTF-8/ASCII 原始文字 | 說明 |
|---:|---:|---|---|
| `0x80D108` | `0x00C0EB08` | `Table/ItemUsableTable.xml` | 在 `0x522BB6` 作為載入字串參數 |
| `0x80D124` | `0x00C0EB24` | `Table/ItemUsingMsg.xml` | 在 `0x522EC5` 作為另一載入字串參數 |
| `0x80D0D8` | `0x00C0EAD8` | `ACTION` | 在 ItemUsable XML 遍歷程式使用 |
| `0x80C148` | `0x00C0DB48` | `Table/QuestInfo.xml` | **僅證明其他區域存在此字串**，不構成本 factory 的資料來源 |
| `0x80C15C` | `0x00C0DB5C` | `Table/QuestTalk.xml` | 同上 |

以上原生路徑都在實體 BIN 可找得到，`.rdata` 使用修正後 VA/raw 差值 `0x401A00`。`0xC0EAB8` 是 `ITEM_USABLE_TABLE`、`0xC0EACC` 是 `ITEM_USABLE`，`0xC0EAE0` 是 `ITEM_USING_MSG_LIST`；此處所有字串都是 **XML tag/資源字串**，不是網路 command ID。

## 可直接重核的 native Assembly（完整選定區間）

### 0x523450 orchestration (full local block)

.text VA `0x00523450`–`0x0052347b`; raw `0x122850`–`0x12287b`.

```asm
  523450:	55                   	push   ebp
  523451:	8b ec                	mov    ebp,esp
  523453:	83 e4 f8             	and    esp,0xfffffff8
  523456:	51                   	push   ecx
  523457:	56                   	push   esi
  523458:	8b f1                	mov    esi,ecx
  52345a:	56                   	push   esi
  52345b:	e8 90 de ff ff       	call   0x5212f0
  523460:	56                   	push   esi
  523461:	e8 0a f7 ff ff       	call   0x522b70
  523466:	8b ce                	mov    ecx,esi
  523468:	e8 13 fa ff ff       	call   0x522e80
  52346d:	83 c6 10             	add    esi,0x10
  523470:	56                   	push   esi
  523471:	e8 7a 32 30 00       	call   0x8266f0
  523476:	5e                   	pop    esi
  523477:	8b e5                	mov    esp,ebp
  523479:	5d                   	pop    ebp
  52347a:	c3                   	ret
```

### 0x522B70 item-usable XML loading and ACTION extraction

.text VA `0x00522b70`–`0x00522ca0`; raw `0x121f70`–`0x1220a0`.

```asm
  522b70:	55                   	push   ebp
  522b71:	8b ec                	mov    ebp,esp
  522b73:	6a ff                	push   0xffffffff
  522b75:	68 0b 61 92 00       	push   0x92610b
  522b7a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  522b80:	50                   	push   eax
  522b81:	81 ec 98 00 00 00    	sub    esp,0x98
  522b87:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  522b8c:	33 c5                	xor    eax,ebp
  522b8e:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  522b91:	53                   	push   ebx
  522b92:	56                   	push   esi
  522b93:	57                   	push   edi
  522b94:	50                   	push   eax
  522b95:	8d 45 f4             	lea    eax,[ebp-0xc]
  522b98:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  522b9e:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  522ba1:	8d 85 74 ff ff ff    	lea    eax,[ebp-0x8c]
  522ba7:	50                   	push   eax
  522ba8:	89 9d 68 ff ff ff    	mov    DWORD PTR [ebp-0x98],ebx
  522bae:	e8 cd c1 20 00       	call   0x72ed80
  522bb3:	33 ff                	xor    edi,edi
  522bb5:	57                   	push   edi
  522bb6:	b9 08 eb c0 00       	mov    ecx,0xc0eb08
  522bbb:	8d b5 74 ff ff ff    	lea    esi,[ebp-0x8c]
  522bc1:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  522bc4:	e8 47 c5 20 00       	call   0x72f110
  522bc9:	80 7d b8 00          	cmp    BYTE PTR [ebp-0x48],0x0
  522bcd:	74 43                	je     0x522c12
  522bcf:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  522bd6:	83 7d d4 10          	cmp    DWORD PTR [ebp-0x2c],0x10
  522bda:	c7 85 74 ff ff ff 94 	mov    DWORD PTR [ebp-0x8c],0xbf2394
  522be1:	23 bf 00 
  522be4:	72 0c                	jb     0x522bf2
  522be6:	8b 4d c0             	mov    ecx,DWORD PTR [ebp-0x40]
  522be9:	51                   	push   ecx
  522bea:	e8 1d e6 36 00       	call   0x89120c
  522bef:	83 c4 04             	add    esp,0x4
  522bf2:	8d 8d 74 ff ff ff    	lea    ecx,[ebp-0x8c]
  522bf8:	c7 45 d4 0f 00 00 00 	mov    DWORD PTR [ebp-0x2c],0xf
  522bff:	89 7d d0             	mov    DWORD PTR [ebp-0x30],edi
  522c02:	c6 45 c0 00          	mov    BYTE PTR [ebp-0x40],0x0
  522c06:	e8 35 b4 20 00       	call   0x72e040
  522c0b:	33 c0                	xor    eax,eax
  522c0d:	e9 47 02 00 00       	jmp    0x522e59
  522c12:	68 b8 ea c0 00       	push   0xc0eab8
  522c17:	8d 85 74 ff ff ff    	lea    eax,[ebp-0x8c]
  522c1d:	e8 be b6 20 00       	call   0x72e2e0
  522c22:	3b c7                	cmp    eax,edi
  522c24:	0f 84 ea 01 00 00    	je     0x522e14
  522c2a:	bf cc ea c0 00       	mov    edi,0xc0eacc
  522c2f:	e8 2c b7 20 00       	call   0x72e360
  522c34:	8b f0                	mov    esi,eax
  522c36:	89 b5 6c ff ff ff    	mov    DWORD PTR [ebp-0x94],esi
  522c3c:	85 f6                	test   esi,esi
  522c3e:	0f 84 d0 01 00 00    	je     0x522e14
  522c44:	eb 16                	jmp    0x522c5c
  522c46:	eb 08                	jmp    0x522c50
  522c48:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  522c4f:	90                   	nop
  522c50:	8b b5 6c ff ff ff    	mov    esi,DWORD PTR [ebp-0x94]
  522c56:	8b 9d 68 ff ff ff    	mov    ebx,DWORD PTR [ebp-0x98]
  522c5c:	68 50 e5 c0 00       	push   0xc0e550
  522c61:	8d 7e 44             	lea    edi,[esi+0x44]
  522c64:	e8 37 d4 20 00       	call   0x7300a0
  522c69:	85 c0                	test   eax,eax
  522c6b:	74 1a                	je     0x522c87
  522c6d:	83 c0 30             	add    eax,0x30
  522c70:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  522c74:	72 02                	jb     0x522c78
  522c76:	8b 00                	mov    eax,DWORD PTR [eax]
  522c78:	85 c0                	test   eax,eax
  522c7a:	74 0b                	je     0x522c87
  522c7c:	50                   	push   eax
  522c7d:	e8 32 eb 36 00       	call   0x8917b4
  522c82:	83 c4 04             	add    esp,0x4
  522c85:	eb 02                	jmp    0x522c89
  522c87:	33 c0                	xor    eax,eax
  522c89:	8d 95 70 ff ff ff    	lea    edx,[ebp-0x90]
  522c8f:	89 85 70 ff ff ff    	mov    DWORD PTR [ebp-0x90],eax
  522c95:	52                   	push   edx
  522c96:	8d 85 60 ff ff ff    	lea    eax,[ebp-0xa0]
  522c9c:	8b cb                	mov    ecx,ebx
  522c9e:	e8 1d          	call   0x8438c0
```

### 0x522CF0 action number check, creation and append

.text VA `0x00522cf0`–`0x00522df4`; raw `0x1220f0`–`0x1221f4`.

```asm
  522cf0:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  522cf4:	8d 46 14             	lea    eax,[esi+0x14]
  522cf7:	72 02                	jb     0x522cfb
  522cf9:	8b 00                	mov    eax,DWORD PTR [eax]
  522cfb:	68 a8 69 c0 00       	push   0xc069a8
  522d00:	50                   	push   eax
  522d01:	e8 ab 0f 37 00       	call   0x893cb1
  522d06:	83 c4 08             	add    esp,0x8
  522d09:	85 c0                	test   eax,eax
  522d0b:	74 1c                	je     0x522d29
  522d0d:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  522d10:	3b f7                	cmp    esi,edi
  522d12:	75 dc                	jne    0x522cf0
  522d14:	33 c0                	xor    eax,eax
  522d16:	8d 48 ff             	lea    ecx,[eax-0x1]
  522d19:	83 f9 1a             	cmp    ecx,0x1a
  522d1c:	77 29                	ja     0x522d47
  522d1e:	33 c0                	xor    eax,eax
  522d20:	e8 3b 05 00 00       	call   0x523260
  522d25:	8b f8                	mov    edi,eax
  522d27:	eb 20                	jmp    0x522d49
  522d29:	85 f6                	test   esi,esi
  522d2b:	74 e7                	je     0x522d14
  522d2d:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  522d31:	8d 46 30             	lea    eax,[esi+0x30]
  522d34:	72 02                	jb     0x522d38
  522d36:	8b 00                	mov    eax,DWORD PTR [eax]
  522d38:	85 c0                	test   eax,eax
  522d3a:	74 d8                	je     0x522d14
  522d3c:	50                   	push   eax
  522d3d:	e8 72 ea 36 00       	call   0x8917b4
  522d42:	83 c4 04             	add    esp,0x4
  522d45:	eb cf                	jmp    0x522d16
  522d47:	33 ff                	xor    edi,edi
  522d49:	89 bd 70 ff ff ff    	mov    DWORD PTR [ebp-0x90],edi
  522d4f:	85 ff                	test   edi,edi
  522d51:	0f 84 87 00 00 00    	je     0x522dde
  522d57:	57                   	push   edi
  522d58:	8b c3                	mov    eax,ebx
  522d5a:	e8 91 d8 ff ff       	call   0x5205f0
  522d5f:	8b b5 64 ff ff ff    	mov    esi,DWORD PTR [ebp-0x9c]
  522d65:	8b 86 4c 01 00 00    	mov    eax,DWORD PTR [esi+0x14c]
  522d6b:	8d 8d 70 ff ff ff    	lea    ecx,[ebp-0x90]
  522d71:	3b c8                	cmp    ecx,eax
  522d73:	73 43                	jae    0x522db8
  522d75:	8b 8e 48 01 00 00    	mov    ecx,DWORD PTR [esi+0x148]
  522d7b:	8d 95 70 ff ff ff    	lea    edx,[ebp-0x90]
  522d81:	3b ca                	cmp    ecx,edx
  522d83:	77 33                	ja     0x522db8
  522d85:	8b fa                	mov    edi,edx
  522d87:	2b f9                	sub    edi,ecx
  522d89:	c1 ff 02             	sar    edi,0x2
  522d8c:	3b 86 50 01 00 00    	cmp    eax,DWORD PTR [esi+0x150]
  522d92:	75 0b                	jne    0x522d9f
  522d94:	8d 86 48 01 00 00    	lea    eax,[esi+0x148]
  522d9a:	e8 11 bd fb ff       	call   0x4deab0
  522d9f:	8b 86 48 01 00 00    	mov    eax,DWORD PTR [esi+0x148]
  522da5:	8d 0c b8             	lea    ecx,[eax+edi*4]
  522da8:	8b 86 4c 01 00 00    	mov    eax,DWORD PTR [esi+0x14c]
  522dae:	85 c0                	test   eax,eax
  522db0:	74 25                	je     0x522dd7
  522db2:	8b 09                	mov    ecx,DWORD PTR [ecx]
  522db4:	89 08                	mov    DWORD PTR [eax],ecx
  522db6:	eb 1f                	jmp    0x522dd7
  522db8:	3b 86 50 01 00 00    	cmp    eax,DWORD PTR [esi+0x150]
  522dbe:	75 0b                	jne    0x522dcb
  522dc0:	8d 86 48 01 00 00    	lea    eax,[esi+0x148]
  522dc6:	e8 e5 bc fb ff       	call   0x4deab0
  522dcb:	8b 86 4c 01 00 00    	mov    eax,DWORD PTR [esi+0x14c]
  522dd1:	85 c0                	test   eax,eax
  522dd3:	74 02                	je     0x522dd7
  522dd5:	89 38                	mov    DWORD PTR [eax],edi
  522dd7:	83 86 4c 01 00 00 04 	add    DWORD PTR [esi+0x14c],0x4
  522dde:	bf d8 ea c0 00       	mov    edi,0xc0ead8
  522de3:	8b c3                	mov    eax,ebx
  522de5:	e8 d6 b5 20 00       	call   0x72e3c0
  522dea:	8b d8                	mov    ebx,eax
  522dec:	85 db                	test   ebx,ebx
  522dee:	0f 85 ec fe ff ff    	jne    0x522ce0
```

### 0x522E80 ItemUsingMsg XML loader

.text VA `0x00522e80`–`0x00522f55`; raw `0x122280`–`0x122355`.

```asm
  522e80:	55                   	push   ebp
  522e81:	8b ec                	mov    ebp,esp
  522e83:	6a ff                	push   0xffffffff
  522e85:	68 cb 39 92 00       	push   0x9239cb
  522e8a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  522e90:	50                   	push   eax
  522e91:	81 ec 04 01 00 00    	sub    esp,0x104
  522e97:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  522e9c:	33 c5                	xor    eax,ebp
  522e9e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  522ea1:	53                   	push   ebx
  522ea2:	56                   	push   esi
  522ea3:	57                   	push   edi
  522ea4:	50                   	push   eax
  522ea5:	8d 45 f4             	lea    eax,[ebp-0xc]
  522ea8:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  522eae:	8d 85 08 ff ff ff    	lea    eax,[ebp-0xf8]
  522eb4:	8b f9                	mov    edi,ecx
  522eb6:	50                   	push   eax
  522eb7:	89 bd f4 fe ff ff    	mov    DWORD PTR [ebp-0x10c],edi
  522ebd:	e8 be be 20 00       	call   0x72ed80
  522ec2:	33 db                	xor    ebx,ebx
  522ec4:	53                   	push   ebx
  522ec5:	b9 24 eb c0 00       	mov    ecx,0xc0eb24
  522eca:	8d b5 08 ff ff ff    	lea    esi,[ebp-0xf8]
  522ed0:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  522ed3:	e8 38 c2 20 00       	call   0x72f110
  522ed8:	38 9d 4c ff ff ff    	cmp    BYTE PTR [ebp-0xb4],bl
  522ede:	74 51                	je     0x522f31
  522ee0:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  522ee7:	83 bd 68 ff ff ff 10 	cmp    DWORD PTR [ebp-0x98],0x10
  522eee:	c7 85 08 ff ff ff 94 	mov    DWORD PTR [ebp-0xf8],0xbf2394
  522ef5:	23 bf 00 
  522ef8:	72 0f                	jb     0x522f09
  522efa:	8b 8d 54 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xac]
  522f00:	51                   	push   ecx
  522f01:	e8 06 e3 36 00       	call   0x89120c
  522f06:	83 c4 04             	add    esp,0x4
  522f09:	8d 8d 08 ff ff ff    	lea    ecx,[ebp-0xf8]
  522f0f:	c7 85 68 ff ff ff 0f 	mov    DWORD PTR [ebp-0x98],0xf
  522f16:	00 00 00 
  522f19:	89 9d 64 ff ff ff    	mov    DWORD PTR [ebp-0x9c],ebx
  522f1f:	88 9d 54 ff ff ff    	mov    BYTE PTR [ebp-0xac],bl
  522f25:	e8 16 b1 20 00       	call   0x72e040
  522f2a:	33 c0                	xor    eax,eax
  522f2c:	e9 e0 02 00 00       	jmp    0x523211
  522f31:	68 e0 ea c0 00       	push   0xc0eae0
  522f36:	8d 85 08 ff ff ff    	lea    eax,[ebp-0xf8]
  522f3c:	e8 9f b3 20 00       	call   0x72e2e0
  522f41:	3b c3                	cmp    eax,ebx
  522f43:	0f 84 79 02 00 00    	je     0x5231c2
  522f49:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  522f4c:	bf f4 67 c0 00       	mov    edi,0xc067f4
  522f51:	89 95 fc fe      	mov    DWORD PTR [ebp-0x104],edx
```


## Call graph、CFG 與資料流

```text
0x523450  [初始化某道具資料容器；所屬 C++ 類別尚無符號]
  |-- call 0x5212F0  [其他初始化，語意未追]
  |-- call 0x522B70  [Table/ItemUsableTable.xml]
  |     |-- call 0x72F110 [xml path parameter = C0EB08]
  |     |-- validate ITEM_USABLE_TABLE / ITEM_USABLE tags
  |     |-- lookup ACTION and child action attribute
  |     |-- at 0x522D20 call 0x523260 [1..27 → object factory]
  |     |-- at 0x522D5A call 0x5205F0 [object XML fields]
  |     `-- append pointer at owner +0x148/0x14C/0x150
  |-- call 0x522E80 [Table/ItemUsingMsg.xml]
  |     |-- call 0x72F110 [xml path parameter = C0EB24]
  |     `-- validate ITEM_USING_MSG_LIST and parse list
  `-- call 0x8266F0 with owner+0x10 [role still unknown]
```

**Failure branches:** `0x522BC9` tests a parsed/load status byte and jumps to error/early cleanup; when main XML root is missing `0x522C24` branches to `0x522E14`; `0x522D19` checks the normalized action index `<= 0x1A`, invalid value sets object null, `0x522D4F` skips `0x5205F0` and append if factory result null. Other loader `0x522EDE` tests its separate load status and jumps to early cleanup on failure; `0x522F41` branches when expected list root absent. These are **Client local XML error paths**, not S→C拒絕/Server validation.

**ABI caution:** `0x523450` uses ECX as owner at entry (`mov esi,ecx`), then passes `push esi` to both `0x522B70` and `0x5212F0`, and `mov ecx,esi` to `0x522E80`; `0x522E80` is thiscall-like. Adjacent code/data `0x522B44` through `0x522B62` includes jump/data bytes, do not interpret blind disassembly as executable instructions. `E8 rel32` direct-xref scan is only candidate identification; instructions re-checked via objdump.

### Minimal C-like pseudocode, evidence bounded

```cpp
void initialize_item_tables_unknown_class(Owner *owner) {
    init_a(owner);                  // 0x5212F0, semantics open
    parse_item_usable(owner);       // 0x522B70: File=ItemUsableTable.xml
    parse_item_using_msg(owner);    // 0x522E80: File=ItemUsingMsg.xml
    after_init(owner + 0x10);       // 0x8266F0: meaning unknown
}

// Inside parse_item_usable XML ITEM_USABLE list:
for (auto *item : matching_ITEM_USABLE_nodes) {
    auto action_int = get_action_attribute_as_int(item);
    unsigned idx = action_int - 1;
    if (idx <= 26) {
        ActionObject *obj = action_factory(idx); // 0x523260: 27-to-10 switch
        if (obj) {
            fill_XML_fields(obj, item);           // 0x5205F0
            append(owner->pointer_vector_at_0x148, obj);
        }
    }
}
```

注意：此偽碼是**局部資料解析演算法**，非逐指令完全可編譯翻譯；型別名稱只是描述標籤，原版 class 尚未證明；不推定 item 對應角色 quest。

## T16-88 的三輪門檻

第 1 輪已用三個 native call、兩個路徑 literal、XML 標記檢查與 object factory call 建成可複查的完整上游**資源來源閉環**，直接修正原本最重要的未解點「通用 action factory 是否屬 Quest」：現有唯一已確認呼叫路徑屬 ItemUsableTable 資料鏈。這是重大本機資料 provenance 發現，故第 2 輪 `T16-88-2`、第 3 輪 `T16-88-3` **未啟動**。這不構成全程排除其他未分析的間接指標或反射性共享 parser 呼叫；僅足以確認**本研究追的這一條 factory 路徑**不能拿來定義任務 opcode。

## 任務玩家情境與 Client／Server 分界

| 玩家情境 | Client 本地條件 | C→S | S→C | Client state/UI | Server 待開發 |
|---|---|---|---|---|---|
| 讀取 ItemUsableTable.xml | XML path、tag、action value (1..27) | 未找到此路徑發送；**不能證實全局沒有發包** | unknown | 本地 factory object／容器 append 已證 | 不是 Quest 接取協定 |
| NPC 點擊接任務 | Quest UI callback **unknown** | opcode/len/fields **unknown** | opcode/handler **unknown** | cache writer **unknown** | 要求原生 packet trace 或 native producer 證據 |
| Quest 完成、下一任務解鎖 | 原生 quest state **unknown** | unknown | unknown | next Quest unlock **unknown** | 官方 Server 判定與 DB 不可從道具 action XML 猜測 |

## 對歷史原稿的具體更正與後續入口

- T16-86 對 `0x523260` 作出 QuestInfo factory 候選的過早推定：現以 `0x522B70` 的 `ItemUsableTable.xml` 明確上游更正為 **道具使用動作資料 factory**（本條已確認）；不用其 object internal type、XML action number 來定 Quest ID／opcode。
- T16-87 已提醒通用 action factory 尚無 Quest caller；本段正面證明其已知 caller 的實際 XML 來源。其他 QuestInfo.xml／QuestTalk.xml 字串存在，但與此 factory 沒有現成資料流關係。
- 下一正式段 `T16-89`：**停止深追 ItemUsable／UI 通用容器**，由 QuestInfo／QuestTalk 路徑原生 xref 找出真正 loader，或從 Quest cache writer／NPC accept UI callback 追 S→C/C→S。優先要求明確 packet business dispatcher → state writer/producer → queue → socket 證據。不能因沒找到就說 Client 不發包。T02/T07/T14/T15 主責不變。

## GitHub 範圍

僅提交 `kr-temp-roy/` 此文字研究原稿，保留既有 T16-86/87 供修訂歷史，不覆寫別人 Task／catalog；絕不提交 BIN／EXE。