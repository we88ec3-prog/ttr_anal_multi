# T08-178 — 模式啟停雙容器、callback 順序與生命週期邊界

- 研究時間：2026-10-28T09:53:41.869827+08:00（Asia/Taipei）；研究者：`chatgpt-web roy`。
- 第一手來源：原始韓版 `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪本地重算一致；只讀靜態分析。
- PE `.text`：VA `0x00401000`，raw `0x400`，size `0x007D01F0`。僅這個節區採用 `raw = VA - 0x00401000 + 0x400`。
- 基準：T08-177 完整筆記、T08-176 及 T08-KNOWLEDGE-BASE；所有無符號名稱是暫稱。直接 E8 是靜態候選，不涵蓋間接呼叫、vtable、異常及 runtime。

## 1. 本批新增精確觀察

1. `0x007B7FD0` 先走 `[container+0]` 提供的迭代集合，對每個 `node+0x24` 解得的物件讀 vptr、執行 `vtable+4` 虛擬呼叫；接著遍歷 `[container+8]` 的環狀/帶 sentinel 迭代集合，把各 `node+0x24` payload `+0x44` 寫入常數 `1`，最後將 `container+0x30=1`。**第一集合的 callback 並不是第二集合的 owner gate 寫入**，同 offset 的 payload 未證實同型。
2. `0x007B8030` 反方向終止流程：先掃第二集合，把 `node+0x24` 裝入 ESI 並呼叫 `0x007DD1F0` drain，然後寫同一 payload `+0x44=0`；再掃第一集合對各 `node+0x24` 呼叫 `vtable+8`；最後寫 `container+0x30=0`。**drain 在 gate 清零之前**，不可寫成先關閉 gate 再回收。
3. 兩種 wrapper (`0x007AAF1F`、`0x007AB155`) 都在呼叫前 `push 0x00FE173C`，此為全域指標槽位的**位址**，不等於指標槽位中的值。`container+0` 可能引用由該槽取得的管理器，但是對應要看容器初始化者；不能直接認定 `0xFE173C` 是兩套 tree 的共同 owner。
4. `0x7B7FF0`、`0x7B806F` 透過尾 sentinel 的 `+4` 判斷另一集合迭代結束；第二集合迭代使用 `[container+8]` 的首元素 sentinel 判斷。迭代條件及 vfunc offset 已證，抽象 STL 型別（list/tree）仍待建構證據。
5. 兩函式都以 `ret 4` 結尾；`0x7B7FD0` 的兩個 return 路徑（第二集合是否為空）皆把容器 `+0x30` 設為 1。這避免誤解為空集合就不設定模式。

## 2. 直接 E8 caller 定向覆核

| 目標 VA | E8 byte 候選數 | callsite (原始 5 bytes) |
|---|---:|---|
| `0x007B7FD0` | 1 | `0x007AAF1F` (`e8acd00000`) |
| `0x007B8030` | 1 | `0x007AB155` (`e8d6ce0000`) |
| `0x007DD1F0` | 2 | `0x007B8045` (`e8a6510200`), `0x007DD132` (`e8b9000000`) |

## 4. 純靜態分析限制與證據等級

- **已確認（BIN bytes）**：本文列出有完整局部反組譯上下文的 `mov`、`call`、控制條件及直接目標；E8 raw 位移可由 `next_eip+signed rel32` 重算。
- **有界確認**：直接 E8 全段 raw byte 候選掃描只代表指定入口的相對呼叫，非全部合法 CFG xref；原碼若採虛擬呼叫、tail jump、資料內 E8 或間接 function pointer 均不含在內。
- **合理推論**：模式/回收/登記功能性名稱依資料流暫定，不能推成原版 server 決策、效能保證、所有權唯一性。
- **尚待驗證**：同一個 resource owner 的分配/建構 origin、間接 dispatch、callsite 實際 runtime 排程、例外中斷和多執行緒競態、全部異名寫入者；正式 T08 的 server-side 生成規則不屬本段。

## 5. 接續研究清單
1. 追 `&0xFE173C` 容器初始化、`+0` 與 `+8` 兩集合元素的實際建構及 callback 實作。
2. 定向追蹤 `owner+0x44` 的寫入來源及其型別界線，不能只搜尋 bytes 即宣稱唯一。
3. 分析 `0x7AAF1F` / `0x7AB155` 所在的更大範圍初始化／反初始化路徑。

## 附錄 A — 逐區原始 BIN 反組譯（唯讀、用於資料流稽核）

### `0x007B7FD0..0x007B8026`

```asm
007b7fd0 <.text+0x3b6fd0>:
  7b7fd0:	55                   	push   ebp
  7b7fd1:	8b ec                	mov    ebp,esp
  7b7fd3:	53                   	push   ebx
  7b7fd4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b7fd7:	56                   	push   esi
  7b7fd8:	57                   	push   edi
  7b7fd9:	8b 3b                	mov    edi,DWORD PTR [ebx]
  7b7fdb:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7b7fde:	8b 30                	mov    esi,DWORD PTR [eax]
  7b7fe0:	3b f0                	cmp    esi,eax
  7b7fe2:	74 11                	je     0x7b7ff5
  7b7fe4:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7b7fe7:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b7fe9:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7b7fec:	ff d2                	call   edx
  7b7fee:	8b 36                	mov    esi,DWORD PTR [esi]
  7b7ff0:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  7b7ff3:	75 ef                	jne    0x7b7fe4
  7b7ff5:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  7b7ff8:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b7ffa:	3b c1                	cmp    eax,ecx
  7b7ffc:	74 1c                	je     0x7b801a
  7b7ffe:	b9 01 00 00 00       	mov    ecx,0x1
  7b8003:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  7b8006:	89 4a 44             	mov    DWORD PTR [edx+0x44],ecx
  7b8009:	8b 00                	mov    eax,DWORD PTR [eax]
  7b800b:	3b 43 08             	cmp    eax,DWORD PTR [ebx+0x8]
  7b800e:	75 f3                	jne    0x7b8003
  7b8010:	5f                   	pop    edi
  7b8011:	5e                   	pop    esi
  7b8012:	89 4b 30             	mov    DWORD PTR [ebx+0x30],ecx
  7b8015:	5b                   	pop    ebx
  7b8016:	5d                   	pop    ebp
  7b8017:	c2 04 00             	ret    0x4
  7b801a:	5f                   	pop    edi
  7b801b:	5e                   	pop    esi
  7b801c:	c7 43 30 01 00 00 00 	mov    DWORD PTR [ebx+0x30],0x1
  7b8023:	5b                   	pop    ebx
  7b8024:	5d                   	pop    ebp
  7b8025:	c2                   	.byte 0xc2
```

### `0x007B8030..0x007B8080`

```asm
007b8030 <.text+0x3b7030>:
  7b8030:	55                   	push   ebp
  7b8031:	8b ec                	mov    ebp,esp
  7b8033:	53                   	push   ebx
  7b8034:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b8037:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  7b803a:	56                   	push   esi
  7b803b:	57                   	push   edi
  7b803c:	8b 38                	mov    edi,DWORD PTR [eax]
  7b803e:	3b f8                	cmp    edi,eax
  7b8040:	74 16                	je     0x7b8058
  7b8042:	8b 77 24             	mov    esi,DWORD PTR [edi+0x24]
  7b8045:	e8 a6 51 02 00       	call   0x7dd1f0
  7b804a:	c7 46 44 00 00 00 00 	mov    DWORD PTR [esi+0x44],0x0
  7b8051:	8b 3f                	mov    edi,DWORD PTR [edi]
  7b8053:	3b 7b 08             	cmp    edi,DWORD PTR [ebx+0x8]
  7b8056:	75 ea                	jne    0x7b8042
  7b8058:	8b 3b                	mov    edi,DWORD PTR [ebx]
  7b805a:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7b805d:	8b 30                	mov    esi,DWORD PTR [eax]
  7b805f:	3b f0                	cmp    esi,eax
  7b8061:	74 11                	je     0x7b8074
  7b8063:	8b 4e 24             	mov    ecx,DWORD PTR [esi+0x24]
  7b8066:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b8068:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7b806b:	ff d2                	call   edx
  7b806d:	8b 36                	mov    esi,DWORD PTR [esi]
  7b806f:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  7b8072:	75 ef                	jne    0x7b8063
  7b8074:	5f                   	pop    edi
  7b8075:	5e                   	pop    esi
  7b8076:	c7 43 30 00 00 00 00 	mov    DWORD PTR [ebx+0x30],0x0
  7b807d:	5b                   	pop    ebx
  7b807e:	5d                   	pop    ebp
  7b807f:	c2                   	.byte 0xc2
```

### `0x007AAF17..0x007AAF34`

```asm
007aaf17 <.text+0x3a9f17>:
  7aaf17:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7aaf1a:	68 3c 17 fe 00       	push   0xfe173c
  7aaf1f:	e8 ac d0 00 00       	call   0x7b7fd0
  7aaf24:	f6 05 1c 1e fe 00 01 	test   BYTE PTR ds:0xfe1e1c,0x1
  7aaf2b:	75 22                	jne    0x7aaf4f
  7aaf2d:	09 3d 1c 1e fe 00    	or     DWORD PTR ds:0xfe1e1c,edi
  7aaf33:	c7                   	.byte 0xc7
```

### `0x007AB14D..0x007AB170`

```asm
007ab14d <.text+0x3aa14d>:
  7ab14d:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  7ab150:	68 3c 17 fe 00       	push   0xfe173c
  7ab155:	e8 d6 ce 00 00       	call   0x7b8030
  7ab15a:	84 1d f0 93 fd 00    	test   BYTE PTR ds:0xfd93f0,bl
  7ab160:	75 22                	jne    0x7ab184
  7ab162:	09 1d f0 93 fd 00    	or     DWORD PTR ds:0xfd93f0,ebx
  7ab168:	c7 45 fc 05 00 00 00 	mov    DWORD PTR [ebp-0x4],0x5
  7ab16f:	e8                   	.byte 0xe8
```
