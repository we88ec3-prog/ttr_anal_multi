# T08-179 — `owner+0x5C` 歸零、管理器回收與全域登記簿交互

- 研究時間：2026-10-28T09:53:41.869827+08:00（Asia/Taipei）；研究者：`chatgpt-web roy`。
- 第一手來源：原始韓版 `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪本地重算一致；只讀靜態分析。
- PE `.text`：VA `0x00401000`，raw `0x400`，size `0x007D01F0`。僅這個節區採用 `raw = VA - 0x00401000 + 0x400`。
- 基準：T08-177 完整筆記、T08-176 及 T08-KNOWLEDGE-BASE；所有無符號名稱是暫稱。直接 E8 是靜態候選，不涵蓋間接呼叫、vtable、異常及 runtime。

## 1. 本批新增資料流確認

1. `0x007DD100` 使用 `ECX` 傳入 owner (`0x7DD125 mov esi,ecx`)，以 `EDI=-1` 執行 `add [esi+0x5C],edi`；接著 `mov eax,[esi+0x5C]`，如果非零便跳過 drain。這是**減量並在零值時處理**，但加法並未使用原子 lock 前綴，不可未經其他同步證據宣稱 thread-safe 引用計數。
2. 零值路徑順序：`call 0x7DD1F0`（以 ESI 指定 owner）→ `mov [esi+0x44],0` → 如全域 byte `0xFE1770` bit0 尚未設定，寫入 bit0 並呼叫 `0x7B7DA0`，再呼叫 `0x89231A` 註冊回收回呼 → 迭代 `[esi+0x4C]..[esi+0x50]` 的 DWORD 指標陣列。
3. 對陣列每一筆，`0x7DD174 mov edx,[eax+ebx*4]`，`0x7DD177 mov ecx,[0xFE173C]`，再 `call 0x7DC510`。注意這裡 **ECX 是指標槽中值 `[0xFE173C]`，不是模式函式傳入的 `&0xFE173C`**；一組是 owner 管理器接口、一組是地址容器接口，必須維持解參照層級區分。
4. 上游 `0x7B8124` 取得 `node+0x24` payload，`0x7B8127 mov ecx,edi` 呼叫 `0x7DD100`；若回傳非零，直接跳過釋放；若回傳零則 `0x7DCf40` 清理加 `0x89120C` 釋放指標，並對節點執行 `0x7B8680`。因此 *管理器的減量歸零與節點移除存在條件性連結*，不是每次減少都 free。
5. `[esi+0x4C]..[esi+0x50]` 是以 DWORD 元素計算數量 (`sub; sar 2`)，不是 `+0x7C..+0x80` 延遲資源陣列；兩者是不同陣列，前者委派 `0x7DC510`，後者在 `0x7DD1F0` drain。兩段清理順序可以確認，但陣列元素真實類型需要 `0x7DC510` 輔助實證。

## 2. 依原始 BIN 掃描的直接呼叫候選

| 目標 VA | E8 byte 候選數 | callsite (原始 5 bytes) |
|---|---:|---|
| `0x007DD100` | 1 | `0x007B8129` (`e8d24f0200`) |
| `0x007DC510` | 1 | `0x007DD17D` (`e88ef3ffff`) |
| `0x007DCF40` | 2 | `0x007B7F49` (`e8f24f0200`), `0x007B8136` (`e8054e0200`) |
| `0x007B8680` | 3 | `0x007B814C` (`e82f050000`), `0x007D0EDC` (`e89f77feff`), `0x007DC5C2` (`e8b9c0fdff`) |
| `0x007DD1F0` | 2 | `0x007B8045` (`e8a6510200`), `0x007DD132` (`e8b9000000`) |

## 4. 純靜態分析限制與證據等級

- **已確認（BIN bytes）**：本文列出有完整局部反組譯上下文的 `mov`、`call`、控制條件及直接目標；E8 raw 位移可由 `next_eip+signed rel32` 重算。
- **有界確認**：直接 E8 全段 raw byte 候選掃描只代表指定入口的相對呼叫，非全部合法 CFG xref；原碼若採虛擬呼叫、tail jump、資料內 E8 或間接 function pointer 均不含在內。
- **合理推論**：模式/回收/登記功能性名稱依資料流暫定，不能推成原版 server 決策、效能保證、所有權唯一性。
- **尚待驗證**：同一個 resource owner 的分配/建構 origin、間接 dispatch、callsite 實際 runtime 排程、例外中斷和多執行緒競態、全部異名寫入者；正式 T08 的 server-side 生成規則不屬本段。

## 5. 接續研究清單
1. 追 `0x7DC510` 的語意與其 ECX/EDX ABI、管理器 `+0x4C/+0x50` 元素來源。
2. 追管理器 `+0x5C` 建構初值、全部增量寫入及其同步機制。
3. 查 `0x7B8129` 上游節點與 `0x7B8680` 的實際容器關係和例外邊。

## 附錄 A — 逐區原始 BIN 反組譯（唯讀、用於資料流稽核）

### `0x007DD100..0x007DD19C`

```asm
007dd100 <.text+0x3dc100>:
  7dd100:	55                   	push   ebp
  7dd101:	8b ec                	mov    ebp,esp
  7dd103:	6a ff                	push   0xffffffff
  7dd105:	68 2e 88 91 00       	push   0x91882e
  7dd10a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7dd110:	50                   	push   eax
  7dd111:	53                   	push   ebx
  7dd112:	56                   	push   esi
  7dd113:	57                   	push   edi
  7dd114:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7dd119:	33 c5                	xor    eax,ebp
  7dd11b:	50                   	push   eax
  7dd11c:	8d 45 f4             	lea    eax,[ebp-0xc]
  7dd11f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7dd125:	8b f1                	mov    esi,ecx
  7dd127:	83 cf ff             	or     edi,0xffffffff
  7dd12a:	01 7e 5c             	add    DWORD PTR [esi+0x5c],edi
  7dd12d:	8b 46 5c             	mov    eax,DWORD PTR [esi+0x5c]
  7dd130:	75 58                	jne    0x7dd18a
  7dd132:	e8 b9 00 00 00       	call   0x7dd1f0
  7dd137:	33 db                	xor    ebx,ebx
  7dd139:	f6 05 70 17 fe 00 01 	test   BYTE PTR ds:0xfe1770,0x1
  7dd140:	89 5e 44             	mov    DWORD PTR [esi+0x44],ebx
  7dd143:	75 1f                	jne    0x7dd164
  7dd145:	83 0d 70 17 fe 00 01 	or     DWORD PTR ds:0xfe1770,0x1
  7dd14c:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7dd14f:	e8 4c ac fd ff       	call   0x7b7da0
  7dd154:	68 90 e7 bc 00       	push   0xbce790
  7dd159:	e8 bc 51 0b 00       	call   0x89231a
  7dd15e:	83 c4 04             	add    esp,0x4
  7dd161:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
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
  7dd198:	8b e5                	mov    esp,ebp
  7dd19a:	5d                   	pop    ebp
  7dd19b:	c3                   	ret
```

### `0x007B8118..0x007B8171`

```asm
007b8118 <.text+0x3b7118>:
  7b8118:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7b811b:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  7b811e:	75 04                	jne    0x7b8124
  7b8120:	33 c0                	xor    eax,eax
  7b8122:	eb 32                	jmp    0x7b8156
  7b8124:	8b 78 24             	mov    edi,DWORD PTR [eax+0x24]
  7b8127:	8b cf                	mov    ecx,edi
  7b8129:	e8 d2 4f 02 00       	call   0x7dd100
  7b812e:	85 c0                	test   eax,eax
  7b8130:	75 1f                	jne    0x7b8151
  7b8132:	85 ff                	test   edi,edi
  7b8134:	74 0e                	je     0x7b8144
  7b8136:	e8 05 4e 02 00       	call   0x7dcf40
  7b813b:	57                   	push   edi
  7b813c:	e8 cb 90 0d 00       	call   0x89120c
  7b8141:	83 c4 04             	add    esp,0x4
  7b8144:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7b8147:	50                   	push   eax
  7b8148:	8d 4d d0             	lea    ecx,[ebp-0x30]
  7b814b:	51                   	push   ecx
  7b814c:	e8 2f 05 00 00       	call   0x7b8680
  7b8151:	b8 01 00 00 00       	mov    eax,0x1
  7b8156:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7b8159:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7b8160:	59                   	pop    ecx
  7b8161:	5f                   	pop    edi
  7b8162:	5e                   	pop    esi
  7b8163:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  7b8166:	33 cd                	xor    ecx,ebp
  7b8168:	e8 94 8e 0d 00       	call   0x891001
  7b816d:	8b e5                	mov    esp,ebp
  7b816f:	5d                   	pop    ebp
  7b8170:	c3                   	ret
```

### `0x007DD1F0..0x007DD29B`

```asm
007dd1f0 <.text+0x3dc1f0>:
  7dd1f0:	55                   	push   ebp
  7dd1f1:	8b ec                	mov    ebp,esp
  7dd1f3:	51                   	push   ecx
  7dd1f4:	53                   	push   ebx
  7dd1f5:	8d 46 64             	lea    eax,[esi+0x64]
  7dd1f8:	57                   	push   edi
  7dd1f9:	50                   	push   eax
  7dd1fa:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  7dd1fd:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7dd203:	8b 46 7c             	mov    eax,DWORD PTR [esi+0x7c]
  7dd206:	8b 8e 80 00 00 00    	mov    ecx,DWORD PTR [esi+0x80]
  7dd20c:	2b c8                	sub    ecx,eax
  7dd20e:	c1 f9 02             	sar    ecx,0x2
  7dd211:	33 db                	xor    ebx,ebx
  7dd213:	85 c9                	test   ecx,ecx
  7dd215:	74 46                	je     0x7dd25d
  7dd217:	8b 14 98             	mov    edx,DWORD PTR [eax+ebx*4]
  7dd21a:	52                   	push   edx
  7dd21b:	e8 d0 0e fe ff       	call   0x7be0f0
  7dd220:	8b 46 7c             	mov    eax,DWORD PTR [esi+0x7c]
  7dd223:	83 3c 98 00          	cmp    DWORD PTR [eax+ebx*4],0x0
  7dd227:	8d 04 98             	lea    eax,[eax+ebx*4]
  7dd22a:	74 1e                	je     0x7dd24a
  7dd22c:	8b 38                	mov    edi,DWORD PTR [eax]
  7dd22e:	85 ff                	test   edi,edi
  7dd230:	74 0e                	je     0x7dd240
  7dd232:	e8 19 06 fe ff       	call   0x7bd850
  7dd237:	57                   	push   edi
  7dd238:	e8 cf 3f 0b 00       	call   0x89120c
  7dd23d:	83 c4 04             	add    esp,0x4
  7dd240:	8b 4e 7c             	mov    ecx,DWORD PTR [esi+0x7c]
  7dd243:	c7 04 99 00 00 00 00 	mov    DWORD PTR [ecx+ebx*4],0x0
  7dd24a:	8b 46 7c             	mov    eax,DWORD PTR [esi+0x7c]
  7dd24d:	8b 96 80 00 00 00    	mov    edx,DWORD PTR [esi+0x80]
  7dd253:	2b d0                	sub    edx,eax
  7dd255:	43                   	inc    ebx
  7dd256:	c1 fa 02             	sar    edx,0x2
  7dd259:	3b da                	cmp    ebx,edx
  7dd25b:	72 ba                	jb     0x7dd217
  7dd25d:	8b 8e 80 00 00 00    	mov    ecx,DWORD PTR [esi+0x80]
  7dd263:	8b 7e 7c             	mov    edi,DWORD PTR [esi+0x7c]
  7dd266:	3b f9                	cmp    edi,ecx
  7dd268:	74 21                	je     0x7dd28b
  7dd26a:	8b c1                	mov    eax,ecx
  7dd26c:	2b c1                	sub    eax,ecx
  7dd26e:	c1 f8 02             	sar    eax,0x2
  7dd271:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7dd278:	53                   	push   ebx
  7dd279:	51                   	push   ecx
  7dd27a:	57                   	push   edi
  7dd27b:	e8 70 40 0b 00       	call   0x8912f0
  7dd280:	83 c4 0c             	add    esp,0xc
  7dd283:	03 df                	add    ebx,edi
  7dd285:	89 9e 80 00 00 00    	mov    DWORD PTR [esi+0x80],ebx
  7dd28b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  7dd28e:	50                   	push   eax
  7dd28f:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dd295:	5f                   	pop    edi
  7dd296:	5b                   	pop    ebx
  7dd297:	8b e5                	mov    esp,ebp
  7dd299:	5d                   	pop    ebp
  7dd29a:	c3                   	ret
```

### `0x007DC510..0x007DC5A0`

```asm
007dc510 <.text+0x3db510>:
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
  7dc59e:	8b                   	.byte 0x8b
  7dc59f:	50                   	push   eax
```

### `0x007DCF40..0x007DCFA0`

```asm
007dcf40 <.text+0x3dbf40>:
  7dcf40:	53                   	push   ebx
  7dcf41:	56                   	push   esi
  7dcf42:	8b 77 4c             	mov    esi,DWORD PTR [edi+0x4c]
  7dcf45:	33 db                	xor    ebx,ebx
  7dcf47:	3b 77 50             	cmp    esi,DWORD PTR [edi+0x50]
  7dcf4a:	74 1d                	je     0x7dcf69
  7dcf4c:	8d 64 24 00          	lea    esp,[esp+0x0]
  7dcf50:	8b 06                	mov    eax,DWORD PTR [esi]
  7dcf52:	3b c3                	cmp    eax,ebx
  7dcf54:	74 0b                	je     0x7dcf61
  7dcf56:	50                   	push   eax
  7dcf57:	e8 b0 42 0b 00       	call   0x89120c
  7dcf5c:	83 c4 04             	add    esp,0x4
  7dcf5f:	89 1e                	mov    DWORD PTR [esi],ebx
  7dcf61:	83 c6 04             	add    esi,0x4
  7dcf64:	3b 77 50             	cmp    esi,DWORD PTR [edi+0x50]
  7dcf67:	75 e7                	jne    0x7dcf50
  7dcf69:	8b 47 7c             	mov    eax,DWORD PTR [edi+0x7c]
  7dcf6c:	3b c3                	cmp    eax,ebx
  7dcf6e:	74 09                	je     0x7dcf79
  7dcf70:	50                   	push   eax
  7dcf71:	e8 96 42 0b 00       	call   0x89120c
  7dcf76:	83 c4 04             	add    esp,0x4
  7dcf79:	8d 47 64             	lea    eax,[edi+0x64]
  7dcf7c:	50                   	push   eax
  7dcf7d:	89 5f 7c             	mov    DWORD PTR [edi+0x7c],ebx
  7dcf80:	89 9f 80 00 00 00    	mov    DWORD PTR [edi+0x80],ebx
  7dcf86:	89 9f 84 00 00 00    	mov    DWORD PTR [edi+0x84],ebx
  7dcf8c:	ff 15 28 22 bd 00    	call   DWORD PTR ds:0xbd2228
  7dcf92:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  7dcf95:	3b c3                	cmp    eax,ebx
  7dcf97:	74 09                	je     0x7dcfa2
  7dcf99:	50                   	push   eax
  7dcf9a:	e8 6d 42 0b 00       	call   0x89120c
  7dcf9f:	83                   	.byte 0x83
```
