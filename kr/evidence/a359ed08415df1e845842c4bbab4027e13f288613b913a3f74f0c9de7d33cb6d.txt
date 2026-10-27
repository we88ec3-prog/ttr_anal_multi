# KR T10-5 — 映射查詢呼叫者與使用情境

紀錄日期：2026-10-27T19:11:40+08:00

## 0. 來源與限制
- 研究對象：韓版 KR T10「普通攻擊與連段」，使用者指出 Z 連按、Z 按住不放兩種操作。
- 原始檔 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；僅唯讀，PE `.text` VA `0x00401000` 對映檔案 raw `0x400`；GNU objdump `-b binary -mi386 -Mintel --adjust-vma`。**所有位址為 VA，函式名稱除符號佐證者均為暫定。**
- 已有 T10-1～T10-4 原稿作背景；本段新增事項皆以本次 raw BIN 讀取核對。未啟動／附加遊戲或修改任何原始資料。
- 原生證據只證明目前觀察到的機器碼與資料流；不可反推出 Z 對應 bit、實際連段時間、是否可玩。

## 1. 分析與證據
本段以 **`0x6D4DC0` 的直接 `E8 rel32` 呼叫者** 為入口，以「控制項索引→映射資料查詢→消費端」建立可核查邊界。

已從 `.text` 逐位元搜尋 `E8` 並解開有號相對位移，找出 **29 個**指向 `0x6D4DC0` 的 call-site；這是原始位元組**候選**引用清單，不能單靠掃描宣稱每一處都是完整有效 CFG 或唯一呼叫者（未涵蓋間接呼叫）。

代表性已對齊指令：

| call VA | 上游實際參數／來源 | 下游目前可確認 |
|---|---|---|
| `0x594672` | `push 2; push edi`，`edi` 來自物件 `ecx`；`ecx` 指向本地 DWORD vector | 從映射取得零或多個 DWORD，後接資料轉字串／屬性操作 |
| `0x5946CB` | `push 2; push 0xD` | 將映射結果用於另一屬性路徑 |
| `0x59471B` | `push 2; push 0xE` | 同一函式另一次映射查詢 |
| `0x5CD68A` | `push 2; push 0x10` | 結果轉為顯示／字串資料並和原欄位比較 |
| `0x650E96` | `push 2; push 0x2904` | 使用映射結果更新物件屬性；與後續不同代碼分支 |
| `0x650F48` | `push 2; push 0x2906` | 第二筆查詢，仍非 Z 直接回呼的證據 |

`0x650E00` 內的 `0x2904/0x2906` 位於 `0x6D4DC0` 的特殊區間內；不能因為看見數字就把它們當成 VK_Z、連段段數或技能碼。`0x594610` 與 `0x5CD610` 的結果還會進行字串比較與資料更新，說明此函式的用途比實體鍵盤 polling 更廣。

**暫定偽碼（僅代表 ABI 観察）**：
```cpp
Vector32 mapped;
lookupMappedValues(&mapped, selector /* possibly 2 */, itemCode);
if (!mapped.empty()) useValue(mapped.begin[0]); // 不表示所有 caller 都只取第一筆
```

**證據分級**：確定＝上述指令呼叫、傳參、部分讀值；合理推測＝查詢為通用「映射設定轉可使用值」；未確認＝實際 Z row、即時 key-down 事件、映射資料至普通攻擊 action 的關係。

**T10-6 接續方向**：深入 `0x6D43F0` 與 `0x6D1DA0`，區分查表副作用與靜態初始化，避免把設定表誤當 runtime 輸入狀態。

全部直接 call 候選 VA：`0x594672`, `0x5946CB`, `0x59471B`, `0x5947FD`, `0x59484D`, `0x59492F`, `0x59497F`, `0x594CD4`, `0x594DC4`, `0x594EB4`, `0x594FA4`, `0x595094`, `0x595184`, `0x595274`, `0x595364`, `0x595454`, `0x595544`, `0x595634`, `0x595724`, `0x595814`, `0x595901`, `0x5959F4`, `0x5CD68A`, `0x5CE5BA`, `0x62B5BA`, `0x650E96`, `0x650F48`, `0x650FF6`, `0x6510A4`。


## 2. 原始 BIN 組語摘錄（逐址重新反組譯）
### 映射結果消費者 A (VA `0x00594664`)
```asm
  594664:	6a 02                	push   0x2
  594666:	57                   	push   edi
  594667:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  59466b:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  594672:	e8 49 07 14 00       	call   0x6d4dc0
  594677:	83 c4 08             	add    esp,0x8
  59467a:	53                   	push   ebx
  59467b:	68 fc d1 be 00       	push   0xbed1fc
  594680:	8b ce                	mov    ecx,esi
  594682:	e8 d9 da e6 ff       	call   0x402160
  594687:	83 ff 18             	cmp    edi,0x18
  59468a:	0f 85 29 01 00 00    	jne    0x5947b9
  594690:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  594694:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  594698:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  59469c:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  5946a0:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  5946a4:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  5946a8:	33 c9                	xor    ecx,ecx
  5946aa:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  5946b1:	00 
  5946b2:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  5946b6:	66 89 4c 24 4c       	mov    WORD PTR [esp+0x4c],cx
  5946bb:	6a 02                	push   0x2
  5946bd:	6a 0d                	push   0xd
  5946bf:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  5946c3:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x3
  5946ca:	03 
  5946cb:	e8 f0 06 14 00       	call   0x6d4dc0
  5946d0:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5946d4:	83 c4 08             	add    esp,0x8
  5946d7:	3b 44 24 30          	cmp    eax,DWORD PTR [esp+0x30]
  5946db:	74 27                	je     0x594704
  5946dd:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  5946e1:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  5946e4:	74 12                	je     0x5946f8
  5946e6:	8b 10                	mov    edx,DWORD PTR [eax]
  5946e8:	52                   	push   edx
  5946e9:	8d 74 24 50          	lea    esi,[esp+0x50]
  5946ed:	e8 8e 03 00 00       	call   0x594a80
  5946f2:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5946f6:	eb 0c                	jmp    0x594704
  5946f8:	8b 00                	mov    eax,DWORD PTR [eax]
  5946fa:	50                   	push   eax
  5946fb:	8d 44 24 50          	lea    eax,[esp+0x50]
  5946ff:	e8 6c fe ff ff       	call   0x594570
  594704:	6a ff                	push   0xffffffff
  594706:	53                   	push   ebx
  594707:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  59470b:	51                   	push   ecx
  59470c:	8b ce                	mov    ecx,esi
```

### 映射結果消費者 B (VA `0x005CD67A`)
```asm
  5cd67a:	6a 02                	push   0x2
  5cd67c:	6a 10                	push   0x10
  5cd67e:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  5cd682:	c6 84 24 f8 00 00 00 	mov    BYTE PTR [esp+0xf8],0x3
  5cd689:	03 
  5cd68a:	e8 31 77 10 00       	call   0x6d4dc0
  5cd68f:	83 c4 08             	add    esp,0x8
  5cd692:	57                   	push   edi
  5cd693:	68 fc d1 be 00       	push   0xbed1fc
  5cd698:	8d 8c 24 cc 00 00 00 	lea    ecx,[esp+0xcc]
  5cd69f:	e8 bc 4a e3 ff       	call   0x402160
  5cd6a4:	8b 74 24 48          	mov    esi,DWORD PTR [esp+0x48]
  5cd6a8:	3b 74 24 4c          	cmp    esi,DWORD PTR [esp+0x4c]
  5cd6ac:	74 1e                	je     0x5cd6cc
  5cd6ae:	8b d6                	mov    edx,esi
  5cd6b0:	8b 02                	mov    eax,DWORD PTR [edx]
  5cd6b2:	50                   	push   eax
  5cd6b3:	8d b4 24 c8 00 00 00 	lea    esi,[esp+0xc8]
  5cd6ba:	bf 18 fb fd 00       	mov    edi,0xfdfb18
  5cd6bf:	e8 bc 73 fc ff       	call   0x594a80
  5cd6c4:	8b 74 24 48          	mov    esi,DWORD PTR [esp+0x48]
  5cd6c8:	33 ff                	xor    edi,edi
  5cd6ca:	eb 12                	jmp    0x5cd6de
  5cd6cc:	8d 8c 24 c4 00 00 00 	lea    ecx,[esp+0xc4]
  5cd6d3:	51                   	push   ecx
  5cd6d4:	ba fc d1 be 00       	mov    edx,0xbed1fc
  5cd6d9:	e8 b2 1d e5 ff       	call   0x41f490
  5cd6de:	c6 84 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],0x1
  5cd6e5:	01 
  5cd6e6:	3b f7                	cmp    esi,edi
  5cd6e8:	74 09                	je     0x5cd6f3
  5cd6ea:	56                   	push   esi
  5cd6eb:	e8 1c 3b 2c 00       	call   0x89120c
  5cd6f0:	83 c4 04             	add    esp,0x4
  5cd6f3:	83 bc 24 d8 00 00 00 	cmp    DWORD PTR [esp+0xd8],0x8
  5cd6fa:	08 
  5cd6fb:	8b 8c 24 c4 00 00 00 	mov    ecx,DWORD PTR [esp+0xc4]
  5cd702:	73 07                	jae    0x5cd70b
  5cd704:	8d 8c 24 c4 00 00 00 	lea    ecx,[esp+0xc4]
```

### 特殊編號呼叫者 (VA `0x00650E86`)
```asm
  650e86:	6a 02                	push   0x2
  650e88:	68 04 29 00 00       	push   0x2904
  650e8d:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  650e91:	c6 44 24 58 02       	mov    BYTE PTR [esp+0x58],0x2
  650e96:	e8 25 3f 08 00       	call   0x6d4dc0
  650e9b:	83 c4 08             	add    esp,0x8
  650e9e:	57                   	push   edi
  650e9f:	68 fc d1 be 00       	push   0xbed1fc
  650ea4:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  650ea8:	e8 b3 12 db ff       	call   0x402160
  650ead:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  650eb1:	3b 74 24 18          	cmp    esi,DWORD PTR [esp+0x18]
  650eb5:	74 15                	je     0x650ecc
  650eb7:	8b 0e                	mov    ecx,DWORD PTR [esi]
  650eb9:	51                   	push   ecx
  650eba:	8d 44 24 28          	lea    eax,[esp+0x28]
  650ebe:	bf 18 fb fd 00       	mov    edi,0xfdfb18
  650ec3:	e8 a8 36 f4 ff       	call   0x594570
  650ec8:	33 ff                	xor    edi,edi
  650eca:	eb 0f                	jmp    0x650edb
  650ecc:	8d 54 24 24          	lea    edx,[esp+0x24]
  650ed0:	52                   	push   edx
  650ed1:	ba fc d1 be 00       	mov    edx,0xbed1fc
  650ed6:	e8 b5 e5 dc ff       	call   0x41f490
  650edb:	c6 44 24 50 00       	mov    BYTE PTR [esp+0x50],0x0
  650ee0:	3b f7                	cmp    esi,edi
  650ee2:	74 09                	je     0x650eed
  650ee4:	56                   	push   esi
  650ee5:	e8 22 03 24 00       	call   0x89120c
  650eea:	83 c4 04             	add    esp,0x4
  650eed:	8b b3 20 01 00 00    	mov    esi,DWORD PTR [ebx+0x120]
  650ef3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  650ef7:	51                   	push   ecx
  650ef8:	8d b6 e8 00 00 00    	lea    esi,[esi+0xe8]
  650efe:	e8 fd 68 10 00       	call   0x757800
  650f03:	f6 05 10 fb fd 00 01 	test   BYTE PTR ds:0xfdfb10,0x1
  650f0a:	75 1e                	jne    0x650f2a
  650f0c:	83 0d 10 fb fd 00 01 	or     DWORD PTR ds:0xfdfb10,0x1
  650f13:	c6 44 24 50 0c       	mov    BYTE PTR [esp+0x50],0xc
  650f18:	e8 43 f8 f3 ff       	call   0x590760
  650f1d:	68 60 e7 bc 00       	push   0xbce760
  650f22:	e8                   	.byte 0xe8
  650f23:	f3                   	repz
  650f24:	13                   	.byte 0x13
  650f25:	24                   	.byte 0x24
```