# E38 — RR-0005：0x4B7F00 接收處理表 index2、key2 `0x0BB9` 上游，以及 index0xBD2 的後續 key2 回覆

**研究時間**：2026-10-29T22:21:22+08:00（Asia/Taipei）。**研究者**：chatgpt-web roy。**版本**：KR；目標原件 `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次實際 `sha256` 重算）。BIN 唯讀，禁止執行／附加原版 Client。本段正式為 E38，接續 E37；大型批次、依 02 三輪規則，在第1輪已有重大新發現後仍進行兩輪交叉驗證與反證，均列明實作證據。

**VA/raw**：下述函式均在 `.text`；按已核對的 PE `.text VA 0x401000/raw 0x400`，`raw=VA−0x400C00`，不能對 `.rdata`、`.data` 直接套此換算。機器碼來自原始 BIN 的 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`，不是 Ghidra 偽碼代替。既有 `kr-bulk-roy/.../functions/*.c` 只用於追索函式起點／方便閱讀。靜態結果無 pcap、不可稱 first wire、亦不代表 T01 FULL-PASS。

**流程狀態**：本段承接同一對話先前核對的 `main=e751b18922d205d86dea9f280cfd060f62752bc7`、`extra/roy1=4ab2accf76fe038b41cca1e2896586446903b3de`；E37 是本地未提交原稿。使用者特別要求同對話減少重複讀 GitHub，本段不重新擷取全套 `main` 文件。最後公開 RR5 狀態仍是 KR/T02/P0 `PENDING/QUEUED`、claim=null。**本段無 Commit/Push 授權；不認領、不改台帳、T01 原生審核或 S00 規格。**

## 0. 重要結論與 E37 的界線收斂

1. **重大實質增量／已確認：**`0x0BB9` producer 所在函式完整入口為 `0x4B7F00`（到 `0x4B8DBA ret 0x0C`），**不是一個獨立的 key2 handshake 函式**。此函式把入口 param1 指向的資料拆到 `F93930`, `F938F2`, `F94208`, `F9420C`, `F94210`, `F94288` 等狀態，還會向 key0 發數筆短控制 payload、遍歷資料記錄，再在後段送出 key2 `0x0BB9/10B`，最後向 key0 發 `0x00A0/2B` 並啟用定時 `0x00A7` 的 `FD8C00` gate。與 E37 各孤立 producer 相比，現在確認**它們屬同一個執行函式的串接分支**。
2. **重大實質增量／已確認：**`0x4B7DC0` 初始化從 `FD2CFC`（實際 loop 從 `FD2D00` 以 `eax-4` 寫 handler）開始、每一項 8 bytes 的大型處理表；明確把 `0x4B7F00` 寫入 `FD2D0C`（推得 **index 2**），把 `0x4B8DC0` 寫入 `FD8B8C`（推得 **index 3026 = 0x0BD2**）。**必須保留條件**：只有再證索引由實際 S2C command ID 驅動，才能把它們稱為「S2C 0x0002／0x0BD2 handler」；目前先稱**表槽 index**。
3. **閉合初始化可達性：** `0x4B7DC0` 有實際**直接呼叫者** `0x489CD7`、`0x48C459`、`0x4C2FB7`；都在 lazy-init guard `FD2CF4&1` 未設時執行。之前僅掃描 `LE32(0x4B7DC0)` 沒找到函式指標的否定結果**不代表沒有 direct CALL**，此輪修正了可達性證據。
4. **關鍵新增回應：** `0x4B8DC0`（表 index0xBD2）會解析 param1+2 的 16-bit 字元串、param1+0x104 的第二段文字，更新兩處 Client 全域文字相關物件，且按 `FBA798==0` 的 guard 順序向**key2** enqueue **WORD `0x0BCC`/2B** 和 **WORD `0x0BD1`/2B**。與 `0x4B7F00` 的 key2 `0x0BB9` **是不同 handler/不同輸入**，不可無依據拼成 `0x0BB9→0x0BD2→0x0BCC` 的確定 wire 時序。
5. **新增反證：** `0x4B7F00` 內在 `0x4B89D2` 先對 key0 送 3-byte `0x0026`+逐筆 byte；`0x4B8ABD/0x4B8B02/0x4B8B47/0x4B8B8C` 另送四個 key0 WORD `0x0024`、`0x001F`、`0x0025`、`0x0015`；從 `0x4B8BC2` 還會在條件成立時迴圈 key0 `0x00DA`(4B) 與 `0x00D2`(3B)。這些 local producer 都在 `0x0BB9` **之前**。所以將 `0x0BB9` 稱為「key2 first wire」是未證命題；也不能由這個函式局部順序推定不同 socket 的實際網路序。

## 1. 第一輪：從 `0x0BB9` 往上還原整個函式的輸入與其他 C2S

**目標**：E37 只知 `0x4B8C8F..0x4B8CF8` 發 `0x0BB9`，但不知何時觸發。直接從 BIN 反向尋找 `0x55 0x8b 0xec` prologue 和正常尾 `ret 0xC`，再讀 `0x4B7F00` ～ `0x4B8DBA`。這是同一函式的多分支 / subflow，**不是**把位址相鄰的無關函式硬湊在一起。末尾 `0x4B8DBD` 出現 int3，`0x4B8DC0` 有全新 prologue。

### 1.1 已證的輸入欄位與狀態用途（不可自行命名官方欄位）

| 機器碼位置 | native input | local sink | 限定結論 |
|---|---|---|---|
| `0x4B7F37..4B7F46` | `[ebp+8]` | `[esp+0x28]` | 保留 param1 輸入指標 |
| `0x4B803F..4B8042` | `param1+2` DWORD | `F93930` | 複製 DWORD 原值；**不等於已識別 auth token** |
| `0x4B8075..4B8082` | `param1+0x0C` WSTR | `F938F2` | bounded `wcsncpy`（最多 0x14 UTF-16 units） |
| `0x4B80C5..4B810D` | `param1+0x38/+0x36` WORD | `F94208/F9420C` | 轉 32-bit 保存 |
| `0x4B813A..4B8149` | `param1+0x3A` WORD | `F94210` | nonzero bool |
| `0x4B817B..4B818A` | `param1+0x3C` BYTE | `F94288` | zero-equality bool，控制後段條件分支 |
| `0x4B8923..4B8A20` | `[ebp+0x0C]` + `param1+0x6F` | key0 local sends / F94240 | 使用第二入口參數的長度/計數與輸入記錄遍歷，步幅 `0x35` |
| `0x4B8CCD..4B8CDE` | `F941C0`、`param1+6` DWORD | key2 0BB9 bytes2..9 | 10-byte local payload: `[LE16 0x0BB9][DWORD F941C0][DWORD *(param1+6)]` |

**保留條件**：這些 `param1` 偏移都是該 handler 自己對收到的資料的 native 讀取。若沒有完整 dispatcher frame/length 來源與有效性驗證，不得把這張表冒充 Server 實作可立即使用的完整 wire schema；尤其需要最小長度、可選欄位、服務角色與 S2C command 的來源證明。

### 1.2 函式入口與輸入指標保存

入口 `0x4B7F00` 的 prologue、輸入 param1、state frame；此範圍沒有 dispatch opcode 比對，因此不能僅由函式名推定 packet number。

```asm
  4b7f00:	55                   	push   ebp
  4b7f01:	8b ec                	mov    ebp,esp
  4b7f03:	83 e4 f8             	and    esp,0xfffffff8
  4b7f06:	6a ff                	push   0xffffffff
  4b7f08:	68 86 4d 94 00       	push   0x944d86
  4b7f0d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b7f13:	50                   	push   eax
  4b7f14:	83 ec 68             	sub    esp,0x68
  4b7f17:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b7f1c:	33 c4                	xor    eax,esp
  4b7f1e:	89 44 24 60          	mov    DWORD PTR [esp+0x60],eax
  4b7f22:	53                   	push   ebx
  4b7f23:	56                   	push   esi
  4b7f24:	57                   	push   edi
  4b7f25:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b7f2a:	33 c4                	xor    eax,esp
  4b7f2c:	50                   	push   eax
  4b7f2d:	8d 44 24 78          	lea    eax,[esp+0x78]
  4b7f31:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b7f37:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4b7f3a:	33 db                	xor    ebx,ebx
  4b7f3c:	83 ce ff             	or     esi,0xffffffff
  4b7f3f:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b7f46:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  4b7f4a:	75 27                	jne    0x4b7f73
  4b7f4c:	83 0d 90 43 f9   	or     DWORD PTR ds:0xf94390,0x1
```

### 1.3 輸入資料寫入 F93930 與文字欄位

`param1+2 DWORD` 寫到 F93930，`param1+0xC` 的字串以 `wcsncpy_s` bounded 複製。這是有界資料來源，不是對外推的業務命名。

```asm
  4b8038:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b803f:	8b 57 02             	mov    edx,DWORD PTR [edi+0x2]
  4b8042:	89 15 30 39 f9 00    	mov    DWORD PTR ds:0xf93930,edx
  4b8048:	75 2b                	jne    0x4b8075
  4b804a:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8051:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x3
  4b8058:	03 00 00 00 
  4b805c:	e8 2f 95 02 00       	call   0x4e1590
  4b8061:	68 80 cc bc 00       	push   0xbccc80
  4b8066:	e8 af a2 3d 00       	call   0x89231a
  4b806b:	83 c4 04             	add    esp,0x4
  4b806e:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8075:	6a 14                	push   0x14
  4b8077:	8d 47 0c             	lea    eax,[edi+0xc]
  4b807a:	50                   	push   eax
  4b807b:	6a 15                	push   0x15
  4b807d:	68 f2 38 f9 00       	push   0xf938f2
  4b8082:	e8 77 bf 3d 00       	call   0x893ffe
  4b8087:	83 c4 10             	add    esp,0x10
  4b808a:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
```

### 1.4 兩個 WORD 與 boolean 欄位

在 handler 初段將兩個 WORD 轉存全域，另外由 `param1+0x3A/+0x3C` 形成布林值。

```asm
  4b80be:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b80c5:	0f b7 4f 38          	movzx  ecx,WORD PTR [edi+0x38]
  4b80c9:	89 0d 08 42 f9 00    	mov    DWORD PTR ds:0xf94208,ecx
  4b80cf:	75 2b                	jne    0x4b80fc
  4b80d1:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b80d8:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x5
  4b80df:	05 00 00 00 
  4b80e3:	e8 a8 94 02 00       	call   0x4e1590
  4b80e8:	68 80 cc bc 00       	push   0xbccc80
  4b80ed:	e8 28 a2 3d 00       	call   0x89231a
  4b80f2:	83 c4 04             	add    esp,0x4
  4b80f5:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b80fc:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8103:	0f b7 57 36          	movzx  edx,WORD PTR [edi+0x36]
  4b8107:	89 15 0c 42 f9 00    	mov    DWORD PTR ds:0xf9420c,edx
  4b810d:	75 2b                	jne    0x4b813a
  4b810f:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8116:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x6
  4b811d:	06 00 00 00 
  4b8121:	e8 6a 94 02 00       	call   0x4e1590
  4b8126:	68 80 cc bc 00       	push   0xbccc80
  4b812b:	e8 ea a1 3d 00       	call   0x89231a
  4b8130:	83 c4 04             	add    esp,0x4
  4b8133:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b813a:	66 83 7f 3a 00       	cmp    WORD PTR [edi+0x3a],0x0
  4b813f:	0f 95 c0             	setne  al
  4b8142:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8149:	a2 10 42 f9 00       	mov    ds:0xf94210,al
  4b814e:	75 2b                	jne    0x4b817b
  4b8150:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8157:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x7
  4b815e:	07 00 00 00 
  4b8162:	e8 29 94 02 00       	call   0x4e1590
  4b8167:	68 80 cc bc 00       	push   0xbccc80
  4b816c:	e8 a9 a1 3d 00       	call   0x89231a
  4b8171:	83 c4 04             	add    esp,0x4
  4b8174:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b817b:	33 c9                	xor    ecx,ecx
  4b817d:	38 4f 3c             	cmp    BYTE PTR [edi+0x3c],cl
  4b8180:	0f 94 c1             	sete   cl
  4b8183:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b818a:	89 0d 88 42 f9 00    	mov    DWORD PTR ds:0xf94288,ecx
  4b8190:	75 27                	jne    0x4b81b9
  4b8192:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8199:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  4b81a0:	e8 eb 93 02 00       	call   0x4e1590
  4b81a5:	68 80 cc bc 00       	push   0xbccc80
  4b81aa:	e8 6b a1 3d 00       	call   0x89231a
  4b81af:	83 c4 04             	add    esp,0x4
  4b81b2:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b81b9:	f6 05      	test   BYTE PTR ds:0xf94390,0x1
```

### 1.5 可變記錄列表與 key0 0x0026/3B local producer

入口第二參數 `[ebp+0xC]` 先與 `0x41` 比較，達門檻者進入由 magic multiplier 計算的 record count；`param1+0x6F` 起每一迭代向後 `0x35`，在符合 `FBA798==0` 時向 key0 `0x0026` 3B local payload 送出。一個 S2C handler 至少可對多個 key0 C2S producer 重複 enqueue，沒有跨 socket 全域順序證明。

```asm
  4b8923:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4b8926:	83 f9 41             	cmp    ecx,0x41
  4b8929:	73 04                	jae    0x4b892f
  4b892b:	33 c9                	xor    ecx,ecx
  4b892d:	eb 13                	jmp    0x4b8942
  4b892f:	83 c1 bf             	add    ecx,0xffffffbf
  4b8932:	b8 b3 cf 21 35       	mov    eax,0x3521cfb3
  4b8937:	f7 e1                	mul    ecx
  4b8939:	2b ca                	sub    ecx,edx
  4b893b:	d1 e9                	shr    ecx,1
  4b893d:	03 ca                	add    ecx,edx
  4b893f:	c1 e9 05             	shr    ecx,0x5
  4b8942:	c7 44 24 14 00 00 00 	mov    DWORD PTR [esp+0x14],0x0
  4b8949:	00 
  4b894a:	85 c9                	test   ecx,ecx
  4b894c:	0f 84 ce 00 00 00    	je     0x4b8a20
  4b8952:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  4b8956:	83 c7 6f             	add    edi,0x6f
  4b8959:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  4b895d:	bb 1d 00 00 00       	mov    ebx,0x1d
  4b8962:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8969:	75 27                	jne    0x4b8992
  4b896b:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8972:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  4b8979:	e8 12 8c 02 00       	call   0x4e1590
  4b897e:	68 80 cc bc 00       	push   0xbccc80
  4b8983:	e8 92 99 3d 00       	call   0x89231a
  4b8988:	83 c4 04             	add    esp,0x4
  4b898b:	89 b4 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],esi
  4b8992:	0f b6 07             	movzx  eax,BYTE PTR [edi]
  4b8995:	83 f8 09             	cmp    eax,0x9
  4b8998:	77 1b                	ja     0x4b89b5
  4b899a:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  4b89a0:	03 05 04 43 f9 00    	add    eax,DWORD PTR ds:0xf94304
  4b89a6:	74 0d                	je     0x4b89b5
  4b89a8:	8d 57 d2             	lea    edx,[edi-0x2e]
  4b89ab:	8b f0                	mov    esi,eax
  4b89ad:	e8 9e b7 01 00       	call   0x4d4150
  4b89b2:	83 ce ff             	or     esi,0xffffffff
  4b89b5:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4b89bc:	75 14                	jne    0x4b89d2
  4b89be:	83 0d 14 13 fb 00 01 	or     DWORD PTR ds:0xfb1314,0x1
  4b89c5:	68 10 cf bc 00       	push   0xbccf10
  4b89ca:	e8 4b 99 3d 00       	call   0x89231a
  4b89cf:	83 c4 04             	add    esp,0x4
  4b89d2:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b89d9:	0f b6 07             	movzx  eax,BYTE PTR [edi]
  4b89dc:	ba 26 00 00 00       	mov    edx,0x26
  4b89e1:	66 89 54 24 18       	mov    WORD PTR [esp+0x18],dx
  4b89e6:	88 44 24 1a          	mov    BYTE PTR [esp+0x1a],al
  4b89ea:	75 16                	jne    0x4b8a02
  4b89ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b89f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b89f4:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b89f7:	6a 03                	push   0x3
  4b89f9:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  4b89fd:	52                   	push   edx
  4b89fe:	6a 00                	push   0x0
  4b8a00:	ff d0                	call   eax
  4b8a02:	0f b6 0f             	movzx  ecx,BYTE PTR [edi]
  4b8a05:	49                   	dec    ecx
  4b8a06:	ba 01 00 00 00       	mov    edx,0x1
  4b8a0b:	66 d3 e2             	shl    dx,cl
  4b8a0e:	83 c7 35             	add    edi,0x35
  4b8a11:	66 09 54 24 14       	or     WORD PTR [esp+0x14],dx
  4b8a16:	ff 4c 24 10          	dec    DWORD PTR [esp+0x10]
  4b8a1a:	0f 85 42 ff ff ff    	jne    0x4b8962
```

### 1.6 key0 四筆固定 short producer（0x24/1F/25/15）

在 `0x0BB9` 之前，同一函式各自有 FBA798 guard，對 key0 發送 2B 的 `0x0024`、`0x001F`、`0x0025`、`0x0015`。這些數字是本地 payload WORD，不是 Ghidra enum。

```asm
  4b8abd:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8ac4:	b9 24 00 00 00       	mov    ecx,0x24
  4b8ac9:	66 89 4c 24 2e       	mov    WORD PTR [esp+0x2e],cx
  4b8ace:	75 16                	jne    0x4b8ae6
  4b8ad0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8ad6:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8ad8:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8adb:	6a 02                	push   0x2
  4b8add:	8d 44 24 32          	lea    eax,[esp+0x32]
  4b8ae1:	50                   	push   eax
  4b8ae2:	6a 00                	push   0x0
  4b8ae4:	ff d2                	call   edx
  4b8ae6:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4b8aed:	75 13                	jne    0x4b8b02
  4b8aef:	09 3d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,edi
  4b8af5:	68 10 cf bc 00       	push   0xbccf10
  4b8afa:	e8 1b 98 3d 00       	call   0x89231a
  4b8aff:	83 c4 04             	add    esp,0x4
  4b8b02:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8b09:	b8 1f 00 00 00       	mov    eax,0x1f
  4b8b0e:	66 89 44 24 32       	mov    WORD PTR [esp+0x32],ax
  4b8b13:	75 16                	jne    0x4b8b2b
  4b8b15:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8b1b:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8b1d:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8b20:	6a 02                	push   0x2
  4b8b22:	8d 44 24 36          	lea    eax,[esp+0x36]
  4b8b26:	50                   	push   eax
  4b8b27:	6a 00                	push   0x0
  4b8b29:	ff d2                	call   edx
  4b8b2b:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4b8b32:	75 13                	jne    0x4b8b47
  4b8b34:	09 3d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,edi
  4b8b3a:	68 10 cf bc 00       	push   0xbccf10
  4b8b3f:	e8 d6 97 3d 00       	call   0x89231a
  4b8b44:	83 c4 04             	add    esp,0x4
  4b8b47:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8b4e:	b8 25 00 00 00       	mov    eax,0x25
  4b8b53:	66 89 44 24 30       	mov    WORD PTR [esp+0x30],ax
  4b8b58:	75 16                	jne    0x4b8b70
  4b8b5a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8b60:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8b62:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8b65:	6a 02                	push   0x2
  4b8b67:	8d 44 24 34          	lea    eax,[esp+0x34]
  4b8b6b:	50                   	push   eax
  4b8b6c:	6a 00                	push   0x0
  4b8b6e:	ff d2                	call   edx
  4b8b70:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4b8b77:	75 13                	jne    0x4b8b8c
  4b8b79:	09 3d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,edi
  4b8b7f:	68 10 cf bc 00       	push   0xbccf10
  4b8b84:	e8 91 97 3d 00       	call   0x89231a
  4b8b89:	83 c4 04             	add    esp,0x4
  4b8b8c:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8b93:	b8 15 00 00 00       	mov    eax,0x15
  4b8b98:	66 89 44 24 18       	mov    WORD PTR [esp+0x18],ax
  4b8b9d:	75 16                	jne    0x4b8bb5
  4b8b9f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8ba5:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8ba7:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8baa:	6a 02                	push   0x2
  4b8bac:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  4b8bb0:	50                   	push   eax
  4b8bb1:	6a 00                	push   0x0
  4b8bb3:	ff d2                	call   edx
  4b8bb5:	bb 01 00 00 00       	mov    ebx,0x1
  4b8bba:	be 10 02 00 00       	mov    esi,0x210
```

### 1.7 key0 0xDA/0xD2 迴圈與判斷

迴圈依 `F94304` 的十筆 `0x210` stride 資料和 entry+0x5C 是否非零決定是否送 key0 `0x00DA/4B`、`0x00D2/3B`。這是條件性迴圈，不能稱必送每筆。

```asm
  4b8bc2:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8bc9:	75 2b                	jne    0x4b8bf6
  4b8bcb:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8bd2:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x20
  4b8bd9:	20 00 00 00 
  4b8bdd:	e8 ae 89 02 00       	call   0x4e1590
  4b8be2:	68 80 cc bc 00       	push   0xbccc80
  4b8be7:	e8 2e 97 3d 00       	call   0x89231a
  4b8bec:	83 c4 04             	add    esp,0x4
  4b8bef:	89 bc 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],edi
  4b8bf6:	83 fb 09             	cmp    ebx,0x9
  4b8bf9:	0f 87 76 00 00 00    	ja     0x4b8c75
  4b8bff:	a1 04 43 f9 00       	mov    eax,ds:0xf94304
  4b8c04:	03 c6                	add    eax,esi
  4b8c06:	83 78 5c 00          	cmp    DWORD PTR [eax+0x5c],0x0
  4b8c0a:	74 69                	je     0x4b8c75
  4b8c0c:	85 c0                	test   eax,eax
  4b8c0e:	74 65                	je     0x4b8c75
  4b8c10:	83 78 5c 00          	cmp    DWORD PTR [eax+0x5c],0x0
  4b8c14:	74 5f                	je     0x4b8c75
  4b8c16:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8c1d:	b9 da 00 00 00       	mov    ecx,0xda
  4b8c22:	66 89 4c 24 10       	mov    WORD PTR [esp+0x10],cx
  4b8c27:	88 5c 24 12          	mov    BYTE PTR [esp+0x12],bl
  4b8c2b:	c6 44 24 13 01       	mov    BYTE PTR [esp+0x13],0x1
  4b8c30:	75 16                	jne    0x4b8c48
  4b8c32:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8c38:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8c3a:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8c3d:	6a 04                	push   0x4
  4b8c3f:	8d 44 24 14          	lea    eax,[esp+0x14]
  4b8c43:	50                   	push   eax
  4b8c44:	6a 00                	push   0x0
  4b8c46:	ff d2                	call   edx
  4b8c48:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8c4f:	b8 d2 00 00 00       	mov    eax,0xd2
  4b8c54:	66 89 44 24 14       	mov    WORD PTR [esp+0x14],ax
  4b8c59:	88 5c 24 16          	mov    BYTE PTR [esp+0x16],bl
  4b8c5d:	75 16                	jne    0x4b8c75
  4b8c5f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8c65:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8c67:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8c6a:	6a 03                	push   0x3
  4b8c6c:	8d 44 24 18          	lea    eax,[esp+0x18]
  4b8c70:	50                   	push   eax
  4b8c71:	6a 00                	push   0x0
  4b8c73:	ff d2                	call   edx
  4b8c75:	81 c6 10 02 00 00    	add    esi,0x210
  4b8c7b:	43                   	inc    ebx
  4b8c7c:	81 fe a0 14 00 00    	cmp    esi,0x14a0
  4b8c82:	0f 8c 3a ff ff ff    	jl     0x4b8bc2
```

### 1.8 key2 0x0BB9 payload writer 與 guard

同一 handler（不是另一個 direct caller）：在讀取 `param1+6`、`F941C0` 後，才執行 `+0x10(key2, &local, 0x0A)`；`FBA798!=0` 不送，但仍會計算 local bytes。

```asm
  4b8c88:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b8c8f:	b8 b9 0b 00 00       	mov    eax,0xbb9
  4b8c94:	66 89 44 24 1c       	mov    WORD PTR [esp+0x1c],ax
  4b8c99:	75 2b                	jne    0x4b8cc6
  4b8c9b:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  4b8ca2:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x21
  4b8ca9:	21 00 00 00 
  4b8cad:	e8 de 88 02 00       	call   0x4e1590
  4b8cb2:	68 80 cc bc 00       	push   0xbccc80
  4b8cb7:	e8 5e 96 3d 00       	call   0x89231a
  4b8cbc:	83 c4 04             	add    esp,0x4
  4b8cbf:	89 bc 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],edi
  4b8cc6:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8ccd:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  4b8cd1:	8b 0d c0 41 f9 00    	mov    ecx,DWORD PTR ds:0xf941c0
  4b8cd7:	8b 42 06             	mov    eax,DWORD PTR [edx+0x6]
  4b8cda:	89 4c 24 1e          	mov    DWORD PTR [esp+0x1e],ecx
  4b8cde:	89 44 24 22          	mov    DWORD PTR [esp+0x22],eax
  4b8ce2:	75 16                	jne    0x4b8cfa
  4b8ce4:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8cea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8cec:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8cef:	6a 0a                	push   0xa
  4b8cf1:	8d 44 24 20          	lea    eax,[esp+0x20]
  4b8cf5:	50                   	push   eax
  4b8cf6:	6a 02                	push   0x2
  4b8cf8:	ff d2                	call   edx
```

### 1.9 key0 0x00A0 與 FD8C00 timer arm、單一 ret

後段先送 `0x00A0/2B` 到 key0（有 FBA798 guard），再 `FD8BFC=timeGetTime` 與 `FD8C00=1`，最後以 `ret 0xC` 返回。這把 E37 的 0x00A0 與 0x00A7 gate 串成**直接原生資料流**，但主循環何時跑到 0x00A7 仍屬不同排程。

```asm
  4b8cfa:	bb 01 00 00 00       	mov    ebx,0x1
  4b8cff:	84 1d 78 13 fb 00    	test   BYTE PTR ds:0xfb1378,bl
  4b8d05:	75 2a                	jne    0x4b8d31
  4b8d07:	09 1d 78 13 fb 00    	or     DWORD PTR ds:0xfb1378,ebx
  4b8d0d:	c7 84 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],0x22
  4b8d14:	22 00 00 00 
  4b8d18:	e8 03 0f 08 00       	call   0x539c20
  4b8d1d:	68 b0 cf bc 00       	push   0xbccfb0
  4b8d22:	e8 f3 95 3d 00       	call   0x89231a
  4b8d27:	83 c4 04             	add    esp,0x4
  4b8d2a:	89 bc 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],edi
  4b8d31:	be 80 13 fb 00       	mov    esi,0xfb1380
  4b8d36:	e8 45 29 08 00       	call   0x53b680
  4b8d3b:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8d42:	b8 a0 00 00 00       	mov    eax,0xa0
  4b8d47:	66 89 44 24 28       	mov    WORD PTR [esp+0x28],ax
  4b8d4c:	75 16                	jne    0x4b8d64
  4b8d4e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8d54:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8d56:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8d59:	6a 02                	push   0x2
  4b8d5b:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  4b8d5f:	50                   	push   eax
  4b8d60:	6a 00                	push   0x0
  4b8d62:	ff d2                	call   edx
  4b8d64:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4b8d6b:	75 1d                	jne    0x4b8d8a
  4b8d6d:	09 1d f8 8b fd 00    	or     DWORD PTR ds:0xfd8bf8,ebx
  4b8d73:	68 10 e3 bc 00       	push   0xbce310
  4b8d78:	c7 05 fc 8b fd 00 00 	mov    DWORD PTR ds:0xfd8bfc,0x0
  4b8d7f:	00 00 00 
  4b8d82:	e8 93 95 3d 00       	call   0x89231a
  4b8d87:	83 c4 04             	add    esp,0x4
  4b8d8a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  4b8d90:	a3 fc 8b fd 00       	mov    ds:0xfd8bfc,eax
  4b8d95:	89 1d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,ebx
  4b8d9b:	33 c0                	xor    eax,eax
  4b8d9d:	8b 4c 24 78          	mov    ecx,DWORD PTR [esp+0x78]
  4b8da1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b8da8:	59                   	pop    ecx
  4b8da9:	5f                   	pop    edi
  4b8daa:	5e                   	pop    esi
  4b8dab:	5b                   	pop    ebx
  4b8dac:	8b 4c 24 60          	mov    ecx,DWORD PTR [esp+0x60]
  4b8db0:	33 cc                	xor    ecx,esp
  4b8db2:	e8 4a 82 3d 00       	call   0x891001
  4b8db7:	8b e5                	mov    esp,ebp
  4b8db9:	5d                   	pop    ebp
  4b8dba:	c2 0c 00             	ret    0xc
```

### Round 1 停止條件

此輪已將 E37 沒找到的 producer enclosing function / inbound input origin 及下游控制訊息都界定，屬重大 native 增量，依 02 可結束正式段號。因還有「此函式究竟如何被 dispatcher 使用」的不確定性，本段自願延伸第2輪、第3輪，先核驗 handler table 安裝，再查相鄰應答，免得將 generic scene callback 當已證 packet 2。

## 2. 第二輪：`0x4B7DC0` 8-byte table/索引證據、初始化可達性、scene/dispatch 的反證界線

### 2.1 表基址與索引數學

`0x4B7DC0` 首先：

- `EAX=0xFD2D00`，`EDX=0x4B7EC0` (fallback) ，`ECX=0xBF2375` (shared value)
- 在迴圈內 `mov [eax-4],edx`，`mov [eax],ecx`，`eax +=8`，直到 `eax >= 0xFD8BA8`
- 因此 handler pointer slots 從 `0xFD2CFC` 起，每項間隔8，另一個 DWORD 在同項 +4。
- 之後覆寫：`[FD2D0C]=0x4B7F00`，`[FD8B8C]=0x4B8DC0`；而 `FD2D0C = FD2CFC + 8*2`，`FD8B8C = FD2CFC +8*3026`。這只證**table position**，並不直接證 network command ID 的使用。

| 靜態處理表位置 | 相對 base `FD2CFC` | 函式 entry | 可確定語意 |
|---|---:|---|---|
| `FD2CFC` | 0 | `0x4B7EC0` 初始化預設 | default fallback |
| `FD2D04` | 1 | `0x4B7EC0` 初始化預設 | default fallback |
| `FD2D0C` | 2 | **`0x4B7F00`** | long input/update/send handler |
| `FD2FFC` | 96 (`0x60`) | `0x4B8F50` | 另一明確覆寫 entry，未在本段展開 |
| `FD8B8C` | 3026 (`0x0BD2`) | **`0x4B8DC0`** | 兩段文字／key2 two replies |

**注意**：`0xBF2375` 看起來像反覆沿用的共用 metadata pointer，但未核查 RTTI/string 語意，勿以它當 Server opcode 含義；其他數十個特殊表項不在此 RR 的最小阻斷範圍內。

### 2.2 `0x4B7DC0` 函式表初始化、entry2/0xBD2 登記

直接保留 `FD2D00..FD8BA8` 的 stride8 迴圈、兩個 index 的明確覆寫以及部分其他 handler 項，以便另一 Agent 重算。

```asm
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7       	mov    DWORD PTR ds:0xfd306c,0x4b9260
  4b7e26:	   
```

### 2.3 表 entry 當前 scene proxy fallback `0x4B7EC0`

當 `[this+5EAC]` 非空，經 `vtable+4` tail-call 目前場景的處理方法；為空時會 log `Received packet from invalid scene. Command #%d` 並返回0。這表明有 **scene-relative callback/dispatch** 邊界；但當 `0x4B7F00` 表項覆寫後，不能把 default proxy 的行為自動套在該函式。

```asm
  4b7ec0:	55                   	push   ebp
  4b7ec1:	8b ec                	mov    ebp,esp
  4b7ec3:	83 b9 ac 5e 00 00 00 	cmp    DWORD PTR [ecx+0x5eac],0x0
  4b7eca:	74 0e                	je     0x4b7eda
  4b7ecc:	8b 89 ac 5e 00 00    	mov    ecx,DWORD PTR [ecx+0x5eac]
  4b7ed2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7ed4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b7ed7:	5d                   	pop    ebp
  4b7ed8:	ff e0                	jmp    eax
  4b7eda:	0f bf 4d 10          	movsx  ecx,WORD PTR [ebp+0x10]
  4b7ede:	51                   	push   ecx
  4b7edf:	68 f8 6d c0 00       	push   0xc06df8
  4b7ee4:	e8 77 5c 23 00       	call   0x6edb60
  4b7ee9:	83 c4 08             	add    esp,0x8
  4b7eec:	33 c0                	xor    eax,eax
  4b7eee:	5d                   	pop    ebp
  4b7eef:	c2 0c 00             	ret    0xc
```

### 2.4 反向 direct-call scan：原生有初始化呼叫者

從 `.text` raw `[0x400,0x7D0600)` 對每個 E8+LE32 rel 進行 `target=(VA+5+signed rel32)&0xffffffff` 計算（非字面指標 constant search），得到 `0x4B7DC0` 的 direct-call：

```text
0x00489CD7
0x0048C459
0x0048F725
0x0049244B
0x0049438A
0x00495348
0x004C2FB7
0x005A64D7
```

這些 CALL 真正存在且直接可達於各自帶 guard 的入口；但尚未證任意實際登入 session 會走入哪個 lazy-init caller。若 `0x4B7DC0` 已被設 bit，這些 site 不再次初始化。**此區分是本輪的主張範圍**。

### 2.5 其中一條 lazy-init：`0x489CB0` 直接 call

`FD2CF4` bit0 guard → `FD2CF8` vptr 寫入 → `FD8BA4=0` → `call 0x4B7DC0` → 返回 `FD2CF8` 物件指標。

```asm
  489cb0:	b8 01 00 00 00       	mov    eax,0x1
  489cb5:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  489cbb:	75 2c                	jne    0x489ce9
  489cbd:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  489cc3:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  489cca:	6e c0 00 
  489ccd:	c7 05 a4 8b fd 00 00 	mov    DWORD PTR ds:0xfd8ba4,0x0
  489cd4:	00 00 00 
  489cd7:	e8 e4 e0 02 00       	call   0x4b7dc0
  489cdc:	68 f0 dc bc 00       	push   0xbcdcf0
  489ce1:	e8 34 86 40 00       	call   0x89231a
  489ce6:	83 c4 04             	add    esp,0x4
  489ce9:	b8 f8 2c fd 00       	mov    eax,0xfd2cf8
  489cee:	c3                   	ret
  489cef:	cc                   	int3
```

### 2.6 主流程中的 lazy-init `0x48C459` 與目前 scene cleanup

另一獨立位置 `0x48C459` CALL `0x4B7DC0`，隨後讀 `FD8BA4`，必要時呼叫該 scene `vtable+0x14`/析構；這是生命周期相關證據，不等同查到實際 network opcode 消費者。

```asm
  48c43a:	f6 05 f4 2c fd 00 01 	test   BYTE PTR ds:0xfd2cf4,0x1
  48c441:	75 28                	jne    0x48c46b
  48c443:	09 35 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,esi
  48c449:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  48c450:	6e c0 00 
  48c453:	89 1d a4 8b fd 00    	mov    DWORD PTR ds:0xfd8ba4,ebx
  48c459:	e8 62 b9 02 00       	call   0x4b7dc0
  48c45e:	68 f0 dc bc 00       	push   0xbcdcf0
  48c463:	e8 b2 5e 40 00       	call   0x89231a
  48c468:	83 c4 04             	add    esp,0x4
  48c46b:	8b 0d a4 8b fd 00    	mov    ecx,DWORD PTR ds:0xfd8ba4
  48c471:	3b cb                	cmp    ecx,ebx
  48c473:	74 1e                	je     0x48c493
  48c475:	8b 11                	mov    edx,DWORD PTR [ecx]
  48c477:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  48c47a:	ff d0                	call   eax
  48c47c:	8b 0d a4 8b fd 00    	mov    ecx,DWORD PTR ds:0xfd8ba4
  48c482:	3b cb                	cmp    ecx,ebx
  48c484:	74 0d                	je     0x48c493
  48c486:	8b 11                	mov    edx,DWORD PTR [ecx]
  48c488:	8b 02                	mov    eax,DWORD PTR [edx]
  48c48a:	56                   	push   esi
  48c48b:	ff d0                	call   eax
  48c48d:	89 1d a4 8b fd 00    	mov    DWORD PTR ds:0xfd8ba4,ebx
  48c493:	f6       	test   BYTE PTR ds:0xfab22c,0x1
```

### 2.7 `0x4C2FB7` lazy-init 並進入 scene 交接 `0x4B7D50`

第三條 direct-call 在 `0x4C2FB7`，緊接著用 `ESI=FD2CF8`、`EDI` 參數呼叫 `0x4B7D50`，證明這張表和場景指標替換/初始化聯繫，而不是純靜態未用資料。

```asm
  4c2f94:	b8 01 00 00 00       	mov    eax,0x1
  4c2f99:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  4c2f9f:	75 28                	jne    0x4c2fc9
  4c2fa1:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  4c2fa7:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  4c2fae:	6e c0 00 
  4c2fb1:	89 3d a4 8b fd 00    	mov    DWORD PTR ds:0xfd8ba4,edi
  4c2fb7:	e8 04 4e ff ff       	call   0x4b7dc0
  4c2fbc:	68 f0 dc bc 00       	push   0xbcdcf0
  4c2fc1:	e8 54 f3 3c 00       	call   0x89231a
  4c2fc6:	83 c4 04             	add    esp,0x4
  4c2fc9:	8b fe                	mov    edi,esi
  4c2fcb:	be f8 2c fd 00       	mov    esi,0xfd2cf8
  4c2fd0:	e8 7b 4d ff ff       	call   0x4b7d50
  4c2fd5:	5f                   	pop    edi
  4c2fd6:	33 c0                	xor    eax,eax
  4c2fd8:	5e                   	pop    esi
  4c2fd9:	c3                   	ret
```

### 2.8 場景替換 `0x4B7D50`：5EAC 及 vtable callbacks

若存在舊 `[sceneManager+5EAC]` 先 `vtable+0x14`、再 call `vtable+0`，設0；記錄新 scene 物件到 +5EAC，呼叫新 scene `vtable+0x10`。這條與 `0x4B7EC0` default fallback 調度相對應，但不是已證 0x4B7F00 的所有 callsite。

```asm
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret
```

### 2.9 需要保留的「opcode」門檻

目前 native 表已知是 dense stride8 handler slots，**index2 和 index0xBD2 完全成立**。若 network dispatcher 使用 `opcode*8 + FD2CFC`，才可提升為「S2C 0x0002」與「S2C 0x0BD2」。本段尚未直接從 `0x807B40` 收包、`0x807E50` payload copy，一路追到對此 dense table 的 indexed fetch。因此使用*候選 inbound opcode*而非已證 wire command；本點交 E39 繼續。

## 3. 第三輪：高索引 callback `0x4B8DC0` 與 key2 應答的資料流閉合

### 3.1 與 E37 的不同角色

`0x4B8DC0` 不是 `0x4B7F00` 的下游直接呼叫：前者是另一個在 `0x4B7DC0` 已登錄的 handler（index `0x0BD2`），後者的 key2 送 `0x0BB9`。目前沒有證明 S2C `index0xBD2` 一定是 0x0BB9 的 immediate reply 或 first reply；必須區分 **兩個獨立 table dispatch events**。

- `0x4B8DE6`: `EBX=[ebp+8]`，`ESI=EBX+2`，沿 16-bit zero terminator 求字串長度，`0x4B8E07..4B8E0A` 複製到 `0xFD8BB0+0x20` 所在物件。
- `0x4B8E4A`: 第二個 `wchar_t*` 源自 `EBX+0x104`，`0x4B8E66..6B` 轉存至 `0xFE1A50`。
- `0x4B8E9C`: 呼叫 `0x4FABF0` 更新 `0xFE1900` 附近狀態（業務意義未命名）。
- `0x4B8EC2` `FBA798==0` 時，對 **key2** call +0x10 送 2-byte WORD `0x0BCC`；`0x4B8F05` 同 guard 下送 2-byte WORD `0x0BD1`。無 ack 成功的返回值檢查、沒有 OS completion 證據。

### 3.2 `0x4B8DC0` 入口 + 第一字串讀取

以 `param1+2` 做 UTF-16 字串處理；字串是否保證有 NUL 與封包長度合法仍待 receiver bounds 來源補證，不能自行補正 Server 欄位。

```asm
  4b8dc0:	55                   	push   ebp
  4b8dc1:	8b ec                	mov    ebp,esp
  4b8dc3:	6a ff                	push   0xffffffff
  4b8dc5:	68 9c 4b 94 00       	push   0x944b9c
  4b8dca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b8dd0:	50                   	push   eax
  4b8dd1:	51                   	push   ecx
  4b8dd2:	53                   	push   ebx
  4b8dd3:	56                   	push   esi
  4b8dd4:	57                   	push   edi
  4b8dd5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b8dda:	33 c5                	xor    eax,ebp
  4b8ddc:	50                   	push   eax
  4b8ddd:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b8de0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b8de6:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4b8de9:	8d 73 02             	lea    esi,[ebx+0x2]
  4b8dec:	e8 ef 10 fd ff       	call   0x489ee0
  4b8df1:	8b ce                	mov    ecx,esi
  4b8df3:	8d 79 02             	lea    edi,[ecx+0x2]
  4b8df6:	66 8b 11             	mov    dx,WORD PTR [ecx]
  4b8df9:	83 c1 02             	add    ecx,0x2
  4b8dfc:	66 85 d2             	test   dx,dx
  4b8dff:	75 f5                	jne    0x4b8df6
  4b8e01:	2b cf                	sub    ecx,edi
  4b8e03:	d1 f9                	sar    ecx,1
  4b8e05:	51                   	push   ecx
  4b8e06:	56                   	push   esi
  4b8e07:	8d 48 20             	lea    ecx,[eax+0x20]
  4b8e0a:	e8 51 93 f4 ff       	call   0x402160
  4b8e0f:	e8           	call   0x489ee0
```

### 3.3 第二字串與全域物件更新

來源 `param1+0x104`，寫入 `0xFE1A50` 並執行全域管理 helper。這是 native 讀寫而不是推測 UTF-16 Server schema 長度。

```asm
  4b8e4a:	8d 93 04 01 00 00    	lea    edx,[ebx+0x104]
  4b8e50:	8b c2                	mov    eax,edx
  4b8e52:	8d 70 02             	lea    esi,[eax+0x2]
  4b8e55:	66 8b 08             	mov    cx,WORD PTR [eax]
  4b8e58:	83 c0 02             	add    eax,0x2
  4b8e5b:	66 85 c9             	test   cx,cx
  4b8e5e:	75 f5                	jne    0x4b8e55
  4b8e60:	2b c6                	sub    eax,esi
  4b8e62:	d1 f8                	sar    eax,1
  4b8e64:	50                   	push   eax
  4b8e65:	52                   	push   edx
  4b8e66:	b9 50 1a fe 00       	mov    ecx,0xfe1a50
  4b8e6b:	e8 f0 92 f4 ff       	call   0x402160
  4b8e70:	f6 05 fc 18 fe 00 01 	test   BYTE PTR ds:0xfe18fc,0x1
  4b8e77:	be 01 00 00 00       	mov    esi,0x1
  4b8e7c:	75 1e                	jne    0x4b8e9c
  4b8e7e:	09 35 fc 18 fe 00    	or     DWORD PTR ds:0xfe18fc,esi
  4b8e84:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4b8e87:	e8 a4 14 04 00       	call   0x4fa330
  4b8e8c:	68 00 e9 bc 00       	push   0xbce900
  4b8e91:	e8 84 94 3d 00       	call   0x89231a
  4b8e96:	83 c4 04             	add    esp,0x4
  4b8e99:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4b8e9c:	68 00 19 fe 00       	push   0xfe1900
  4b8ea1:	e8 4a 1d 04 00       	call   0x4fabf0
  4b8ea6:	f6       	test   BYTE PTR ds:0xfb1314,0x1
```

### 3.4 key2 的 0x0BCC、0x0BD1 兩筆 2B local sends

`0x4B8EC9` 寫 0x0BCC，push `len=2, source=&[ebp+0x0A], key=2`；`0x4B8F0C` 寫 0x0BD1，push 同長/key。兩次 call 受各自的 FBA798 guard，並非無條件送達，且意義不從數字猜測。

```asm
  4b8ea6:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4b8ead:	75 13                	jne    0x4b8ec2
  4b8eaf:	09 35 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,esi
  4b8eb5:	68 10 cf bc 00       	push   0xbccf10
  4b8eba:	e8 5b 94 3d 00       	call   0x89231a
  4b8ebf:	83 c4 04             	add    esp,0x4
  4b8ec2:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8ec9:	b8 cc 0b 00 00       	mov    eax,0xbcc
  4b8ece:	66 89 45 0a          	mov    WORD PTR [ebp+0xa],ax
  4b8ed2:	75 15                	jne    0x4b8ee9
  4b8ed4:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8eda:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8edc:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8edf:	6a 02                	push   0x2
  4b8ee1:	8d 45 0a             	lea    eax,[ebp+0xa]
  4b8ee4:	50                   	push   eax
  4b8ee5:	6a 02                	push   0x2
  4b8ee7:	ff d2                	call   edx
  4b8ee9:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  4b8ef0:	75 13                	jne    0x4b8f05
  4b8ef2:	09 35 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,esi
  4b8ef8:	68 10 cf bc 00       	push   0xbccf10
  4b8efd:	e8 18 94 3d 00       	call   0x89231a
  4b8f02:	83 c4 04             	add    esp,0x4
  4b8f05:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b8f0c:	b8 d1 0b 00 00       	mov    eax,0xbd1
  4b8f11:	66 89 45 f2          	mov    WORD PTR [ebp-0xe],ax
  4b8f15:	75 15                	jne    0x4b8f2c
  4b8f17:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b8f1d:	8b 11                	mov    edx,DWORD PTR [ecx]
  4b8f1f:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4b8f22:	6a 02                	push   0x2
  4b8f24:	8d 45 f2             	lea    eax,[ebp-0xe]
  4b8f27:	50                   	push   eax
  4b8f28:	6a 02                	push   0x2
  4b8f2a:	ff d2                	call   edx
  4b8f2c:	33 c0                	xor    eax,eax
  4b8f2e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b8f31:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b8f38:	59                   	pop    ecx
  4b8f39:	5f                   	pop    edi
  4b8f3a:	5e                   	pop    esi
  4b8f3b:	5b                   	pop    ebx
  4b8f3c:	8b e5                	mov    esp,ebp
  4b8f3e:	5d                   	pop    ebp
  4b8f3f:	c2 0c              	ret    0xc
```

### 3.5 正反面對照、原生與推測分離

| 命題 | 本段結論 | 證據/缺口 |
|---|---|---|
| `0x0BB9` 是 key2 的 local C2S payload | **已確認** | `0x4B8CC6..4B8CF8`，`key=2`，payload length=0xA |
| 它在 handler `0x4B7F00` 的多筆 key0 enqueue 之後 | **已確認，限定同一函式內指令順序** | `0x4B89D2..4B8C75` → `0x4B8C8F..4B8CF8` |
| `0x4B7F00` 在 dense table index2 | **已確認** | `0x4B7DE0` 對 `FD2D0C` 写 function pointer |
| `0x4B8DC0` 在 table index0xBD2 | **已確認** | `0x4B7DEF` 對 `FD8B8C` 写 function pointer |
| `0x4B7DC0` 根本沒 caller | **已被反證** | `0x489CD7`, `0x48C459`, `0x4C2FB7` 都是 E8 rel32 direct call |
| incoming wire command ID2 觸發 `0x4B7F00` | **合理但尚待驗證** | 需網路 dispatcher 對 dense table 的 indexed lookup 證據 |
| incoming wire command ID0xBD2 觸發 `0x4B8DC0` | **合理但尚待驗證** | 同上，且 source socket key 未證 |
| key2 0x0BB9 一定是選服後第一筆 socket write | **無證據，不能主張** | key0/key2 並行；local C2S!=WSASend/IOCP/pcap |
| `0x4B8DC0` 的 S2C 一定是 key2 `0x0BB9` immediate response | **尚待驗證** | 暫無 cross-connection event ordering/packet trace |
| `0x4B7F00` 所見文字與 DWORD 是帳號 token／正式 Server 欄位 | **尚待驗證** | 僅 native bytes/Global copy；無業務命名證據 |

**三輪完成判準**：第1輪取得 E37 缺少的完整 ingress handler enclosing function 及多筆 C2S 有界資料流；第2輪取得 handler table 真正初始化呼叫者、場景管理員繫結並分隔索引與 wire ID；第3輪取得另一個高索引 callback 的雙向局部回應與字串消費。已足以交付**有界 Client 分析增量**，尚未達 RR-0005 全項 acceptance。全程有原始 BIN assembly，不將 Ghidra wrapper 形同 FULL-PASS。

## 4. 對恢復遊戲的意義、責任分層、E39 最小阻斷

### 4.1 玩家可理解版

現有 Client 在某個大型回覆／初始化處理函式中，會先把收到的伺服器資料填入各種畫面/系統狀態，然後以數個短封包通知 key0，再送 key2 的 `0x0BB9`，並開啟之後的定時控制。這明確比較接近「接到初始化資料後回應多個服務」而非「選完伺服器立即只送一包」。但**不能從這段說明推導可用新 Server 的完整登入／選服回應規格**。

### 4.2 四類缺口

**Client 待逆向**：找出由接收 frame（`0x807B40`/`0x807E50`）至 `FD2CFC` dense callback table 的真正索引資料流，確認 opcode/字節數/來源 socket key；`0x4B7F00` 的所有可達分支及 param2 長度檢查；`0x4B8DC0` 第二 UTF16 段的結束條件；`F941C0` 被重置/使用時的真實 token 身分、真正 first wire/first S2C reply。

**Server 待開發**：只可將已證 input→Client state→local enqueues 當相容測試來源；不直接把 handler-index 命名成官方 opcode、不要把 0x0BB9→0x0BD2 視為 Server 必須照走的官方 handshake，也不把舊 Client port 靜態數值當 deployment requirement。

**跨功能待整合**：本段與 T03 的角色/選服 UI、T02 framing、T01/S00 的有限 CLM/SPEC/TRACES 交接；完整原稿的原生主張仍需 T01 查核，S00 應依 RR 的精確完成條件審核，不能自改 `main` 的 `research/requests/index.json`。

**待遊玩驗證**：需要明確授權的 socket send/receive trace 或可回放離線錄包資料，才能區分 app-level enqueue、ring encode、WSASend post、IOCP completion、remote accepted 的真實前後與是否按 key 分流。本段不執行目標，仍未完成。

**E39 下一個定向分析**：

1. 尋找 `FD2CF8` 全域 dispatcher 物件的執行入口、callback table `[base + opcode*8 + 4]` 之類的索引，從 framed parser 的 `0x807E50` 接到 `0x4B7F00` 的最短可驗路徑；若表索引不等於 opcode，要**明確修正** E38 候選命名。
2. 追 `0x4B7F00` 的 `param2` 來源與最小合法長度，尤其 `param1+0x6F` 若存在多筆 `0x35` 資料時，確定 Server 必須提供的格式界線；原始值仍保留數值名。
3. 證明 `0x4B8DC0` 的回覆表 index0xBD2 是否有不同命令路由與真實 connection key；沒有 wire 證據則不要拼出假 handshake。

## 5. 重現腳本／不覆寫原稿

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4b7dc0 --stop-address=0x4b7e20 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4b7f00 --stop-address=0x4b8dbb /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4b8dc0 --stop-address=0x4b8f41 /mnt/data/Tartaros.bin
```

Direct E8 rel32 caller scan：

```python
from pathlib import Path
import struct
b=Path('/mnt/data/Tartaros.bin').read_bytes()
target=0x4b7dc0; base=0x400c00
for i in range(0x400,0x7d0600-5):
    if b[i] == 0xe8 and ((i+base+5+struct.unpack_from('<i',b,i+1)[0]) & 0xffffffff) == target:
        print(hex(i+base))
```

**本地研究交付**：E38 完整 Markdown；無 GitHub Commit／Push／RR Claim。提交時需與 E37 及其他尚未推送的個人原稿一起檢查，遠端內容與 Git blob SHA 核對後才能宣稱正式發表；此文件不自動把 `QUEUED` 改成 `SUBMITTED`。

## 附錄 A：本輪有界主張/引用範圍

| E38 claim | 本地 VA 鏈 | 提供的必要反證／限制 |
|---|---|---|
| E38-C01 ingress handler enclosing | `4B7F00..4B8DBA` | 同函式不是同一 socket 的 first frame |
| E38-C02 handler registration | `4B7DC0..4B7EBE` | table index 不直接等於 wire opcode |
| E38-C03 lazy-init reachability | `489CD7`, `48C459`, `4C2FB7` | guard/實際 runtime 入口未追齊 |
| E38-C04 data payload map | `4B803F..4B818A`, `4B8923..4B8A20` | 欄位的業務語意與完整最小長度未確認 |
| E38-C05 grouped outgoing | `4B89D2..4B8D95` | local enqueue 不是 OS send/ack |
| E38-C06 next response handler | `4B8DC0..4B8F3F` | 0BB9→0BD2 因果仍無 runtime/dispatch 確認 |

**異動與隔離**：不修改 E37 或 GitHub 上 E32–E36 原稿；若 T01 語意驗證推翻任何 claim，保留本篇版本並以新 correction 文檔 append-only 更正。所有檔案/地址均 KR，TC 需另核。
