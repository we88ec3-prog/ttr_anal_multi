# T08-185 — 索引節點、虛擬 callback 與 0x007DC510 的移除條件

- 時間：`2026-10-28T10:12:03.531628+08:00`（Asia/Taipei）；作者：`chatgpt-web roy`。
- 原始來源：唯讀 `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次本機重算一致。
- PE 映射由原檔標頭重驗：`.text` VA `0x00401000`、raw `0x400`、raw size `0x7D0200`；`.rdata` VA `0x00BD2000` raw `0x7D0600`；`.data` VA `0x00D61000` raw `0x95E800`。以下僅對 `.text` 依 raw = 0x400+(VA-0x401000) 轉換。
- 基準：GitHub `main` T08-181～184 原稿、T08 長期知識庫；這份記錄提供本次從 BIN 解碼的可重算窗口，不以舊筆記取代第一手證據。
- **證據標準：** 已確認=實際位元組及有界局部 CFG；部分確認=需要延伸 caller/跨型別連結；待驗=間接 call、未確知 symbol、runtime/伺服器行為。掃描 `E8` 均為 byte-offset 候選，不代表都位於可達指令邊界。

## 本段實質結論與證據

### 1. 輸入 ABI 與查詢鍵

`0x007DC53B mov edi,edx` 暫存字串來源；`0x007DC541 mov esi,ecx` 暫存索引 owner；`0x007DC550～0x007DC561` 走字串長度與 `0x00402A70` 暫存字串建構。`0x007DC56E mov eax,esi` 呼叫 `0x007B86F0`，取 `[ebp-0x4C]` 節點候選。此 ABI 是暫定 `ECX/EDX` 雙寄存器輸入，不可套用通用單參 thiscall。

### 2. 節點是否存在

`0x007DC591 mov eax,[ebp-0x4C]` 對比 `0x007DC594 cmp eax,[esi+4]`：與哨兵一致時轉入缺失分支。不能把 `0x007DC510` 當成無條件移除。

### 3. payload vtable 雙 callback

命中節點時 `0x007DC599 mov edi,[eax+0x24]`；`0x007DC59C mov eax,[edi]`，`0x007DC59E mov edx,[eax+0x0C]`、`0x007DC5A3 call edx`。返回 `EAX==0` 才進 `0x007DC5B0` 呼叫 `vtable+0x00`（`push 1`），隨後 `0x007DC5C2 call 0x007B8680` 將索引節點移除。這是局部確認的**條件式 callback→移除**，虛表身份與 callback 語義尚待來源追查。

### 4. 與 manager 最後引用分離

`0x007DD17D` 在 `+0x5C==0` 最後清理段使用 `ECX=[0x00FE173C]` 呼叫 `0x007DC510`；此關係確認索引清理可由管理器終止引用觸發，**不能推導它必然是場景 actor 0007 的主索引**。

## 可重算的直接 E8 rel32 候選交叉參照

- `0x007DC510`：1 個 `.text` 原始 byte 候選。`0x007DD17D` (`e88ef3ffff`)
- `0x007B86F0`：14 個 `.text` 原始 byte 候選。`0x007194D9` (`e812f20900`), `0x0071954A` (`e8a1f10900`), `0x00719868` (`e883ee0900`), `0x00719A09` (`e8e2ec0900`), `0x007B80FA` (`e8f1050000`), `0x007B81E5` (`e806050000`), `0x007B8360` (`e88b030000`), `0x007B84F7` (`e8f4010000`), `0x007BE04A` (`e8a1a6ffff`), `0x007D09B1` (`e83a7dfeff`), `0x007D0E89` (`e86278feff`), `0x007DC573` (`e878c1fdff`), `0x007DC78B` (`e860bffdff`), `0x007DC868` (`e883befdff`)
- `0x007B8680`：3 個 `.text` 原始 byte 候選。`0x007B814C` (`e82f050000`), `0x007D0EDC` (`e89f77feff`), `0x007DC5C2` (`e8b9c0fdff`)

掃描方法：逐位元組尋找 opcode `E8`，以 `site+5+signed(rel32)` 計算候選；這是**上限候選集合而非 CFG caller 的完整證明**。FF /2、多型 dispatch 與 import thunks 無法由此掃描完結。

## 有界偽碼（分析用，非遊戲原始 C++）

```cpp
ManagerItem* item = lookup_by_string(index, key);
if (item != sentinel) {
  Payload* p = item->payload24;
  auto result = p->vtable_slot_0C();
  if (result == 0) { p->vtable_slot_00(1); erase_index_node(item); }
}
```

偽碼只反映本段明示的局部資料流，並不構成異常處理、競爭條件、全類型配置路徑或 runtime 語義驗收。

## 未解與下一段接續

1. 在實際 Ghidra CFG 驗證 E8 命中是否為指令邊界，並補上 vtable / FF 轉移的真實目標。
2. 對 `node+0x24`、resource 管理器、scene actor 樹分別查構造來源與型別；相同 offset 不等同同一物件。
3. 補實際 wrapper 失敗及 resource `+0x60` 計數的錯誤回退、間接析構與重入。
4. 靜態 BIN 無法證明場景更新/跨 frame 時機、官方 server 生成規則或全部參考數平衡。

## 附錄：原始 BIN 反組譯（Intel x86；每個窗口從指定 VA 起獨立解碼）

### `0x007DC510` + `0x13A` bytes

```asm
  7dc510:	55                   	push   ebp
  7dc511:	8b ec                	mov    ebp,esp
  7dc513:	6a ff                	push   0xffffffff
  7dc515:	68 b0 49 91 00       	push   0x9149b0
  7dc51a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dc520:	50                   	push   eax
  7dc521:	83 ec 44             	sub    esp,0x44
  7dc524:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dc529:	33 c5                	xor    eax,ebp
  7dc52b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7dc52e:	53                   	push   ebx
  7dc52f:	56                   	push   esi
  7dc530:	57                   	push   edi
  7dc531:	50                   	push   eax
  7dc532:	8d 45 f4             	lea    eax,[ebp-0xc]
  7dc535:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dc53b:	8b fa                	mov    edi,edx
  7dc53d:	33 db                	xor    ebx,ebx
  7dc53f:	8b c7                	mov    eax,edi
  7dc541:	8b f1                	mov    esi,ecx
  7dc543:	c7 45 cc 0f 00 00 00 	mov    DWORD PTR [ebp-0x34],0xf
  7dc54a:	89 5d c8             	mov    DWORD PTR [ebp-0x38],ebx
  7dc54d:	88 5d b8             	mov    BYTE PTR [ebp-0x48],bl
  7dc550:	8d 50 01             	lea    edx,[eax+0x1]
  7dc553:	8a 08                	mov    cl,BYTE PTR [eax]
  7dc555:	40                   	inc    eax
  7dc556:	3a cb                	cmp    cl,bl
  7dc558:	75 f9                	jne    0x7dc553
  7dc55a:	2b c2                	sub    eax,edx
  7dc55c:	50                   	push   eax
  7dc55d:	57                   	push   edi
  7dc55e:	8d 4d b8             	lea    ecx,[ebp-0x48]
  7dc561:	e8 0a 65 c2 ff       	call   0x402a70
  7dc566:	8d 45 b8             	lea    eax,[ebp-0x48]
  7dc569:	50                   	push   eax
  7dc56a:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  7dc56d:	51                   	push   ecx
  7dc56e:	8b c6                	mov    eax,esi
  7dc570:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7dc573:	e8 78 c1 fd ff       	call   0x7b86f0
  7dc578:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7dc57f:	83 7d cc 10          	cmp    DWORD PTR [ebp-0x34],0x10
  7dc583:	72 0c                	jb     0x7dc591
  7dc585:	8b 55 b8             	mov    edx,DWORD PTR [ebp-0x48]
  7dc588:	52                   	push   edx
  7dc589:	e8 7e 4c 0b 00       	call   0x89120c
  7dc58e:	83 c4 04             	add    esp,0x4
  7dc591:	8b 45 b4             	mov    eax,DWORD PTR [ebp-0x4c]
  7dc594:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  7dc597:	74 33                	je     0x7dc5cc
  7dc599:	8b 78 24             	mov    edi,DWORD PTR [eax+0x24]
  7dc59c:	8b 07                	mov    eax,DWORD PTR [edi]
  7dc59e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7dc5a1:	8b cf                	mov    ecx,edi
  7dc5a3:	ff d2                	call   edx
  7dc5a5:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  7dc5a8:	3b c3                	cmp    eax,ebx
  7dc5aa:	0f 85 8a 00 00 00    	jne    0x7dc63a
  7dc5b0:	8b 07                	mov    eax,DWORD PTR [edi]
  7dc5b2:	8b 10                	mov    edx,DWORD PTR [eax]
  7dc5b4:	6a 01                	push   0x1
  7dc5b6:	8b cf                	mov    ecx,edi
  7dc5b8:	ff d2                	call   edx
  7dc5ba:	8b 45 b4             	mov    eax,DWORD PTR [ebp-0x4c]
  7dc5bd:	50                   	push   eax
  7dc5be:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  7dc5c1:	51                   	push   ecx
  7dc5c2:	e8 b9 c0 fd ff       	call   0x7b8680
  7dc5c7:	8b 45 b0             	mov    eax,DWORD PTR [ebp-0x50]
  7dc5ca:	eb 6e                	jmp    0x7dc63a
  7dc5cc:	8b c7                	mov    eax,edi
  7dc5ce:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  7dc5d5:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  7dc5d8:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  7dc5db:	8d 50 01             	lea    edx,[eax+0x1]
  7dc5de:	8b ff                	mov    edi,edi
  7dc5e0:	8a 08                	mov    cl,BYTE PTR [eax]
  7dc5e2:	40                   	inc    eax
  7dc5e3:	3a cb                	cmp    cl,bl
  7dc5e5:	75 f9                	jne    0x7dc5e0
  7dc5e7:	2b c2                	sub    eax,edx
  7dc5e9:	50                   	push   eax
  7dc5ea:	57                   	push   edi
  7dc5eb:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7dc5ee:	e8 7d 64 c2 ff       	call   0x402a70
  7dc5f3:	6a 43                	push   0x43
  7dc5f5:	68 78 03 c5 00       	push   0xc50378
  7dc5fa:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  7dc5fd:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7dc604:	e8 b7 59 c2 ff       	call   0x401fc0
  7dc609:	8b 45 d4             	mov    eax,DWORD PTR [ebp-0x2c]
  7dc60c:	be 10 00 00 00       	mov    esi,0x10
  7dc611:	39 75 e8             	cmp    DWORD PTR [ebp-0x18],esi
  7dc614:	73 03                	jae    0x7dc619
  7dc616:	8d 45 d4             	lea    eax,[ebp-0x2c]
  7dc619:	53                   	push   ebx
  7dc61a:	68 d4 53 c4 00       	push   0xc453d4
  7dc61f:	50                   	push   eax
  7dc620:	53                   	push   ebx
  7dc621:	ff 15 90 24 bd 00    	call   DWORD PTR ds:0xbd2490
  7dc627:	39 75 e8             	cmp    DWORD PTR [ebp-0x18],esi
  7dc62a:	72 0c                	jb     0x7dc638
  7dc62c:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  7dc62f:	52                   	push   edx
  7dc630:	e8 d7 4b 0b 00       	call   0x89120c
  7dc635:	83 c4 04             	add    esp,0x4
  7dc638:	33 c0                	xor    eax,eax
  7dc63a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7dc63d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7dc644:	59                   	pop    ecx
  7dc645:	5f                   	pop    edi
  7dc646:	5e                   	pop    esi
  7dc647:	5b                   	pop    ebx
  7dc648:	8b                   	.byte 0x8b
  7dc649:	4d                   	dec    ebp
```

### `0x007DD164` + `0x35` bytes

```asm
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
  7dd198:	8b                   	.byte 0x8b
```
