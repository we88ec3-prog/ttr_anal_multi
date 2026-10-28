# T08-180 — 正式 0007 場景登記／移除與資源釋放交界複核

- 研究時間：2026-10-28T09:53:41.869827+08:00（Asia/Taipei）；研究者：`chatgpt-web roy`。
- 第一手來源：原始韓版 `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪本地重算一致；只讀靜態分析。
- PE `.text`：VA `0x00401000`，raw `0x400`，size `0x007D01F0`。僅這個節區採用 `raw = VA - 0x00401000 + 0x400`。
- 基準：T08-177 完整筆記、T08-176 及 T08-KNOWLEDGE-BASE；所有無符號名稱是暫稱。直接 E8 是靜態候選，不涵蓋間接呼叫、vtable、異常及 runtime。

## 1. 正式範圍與跨模組界面

正式 T08 任務 0007 是**實體建立、登記、移除的資料介面**，不制定 server 生成時機、波次和 AI。場景實體登記 `0x004DFF30`、個別移除 `0x004DFBC0`、全表清理 `0x004DFE90`；資源管理器生命週期 `0x007DD1A0/0x007DD1F0/0x007DD100`；引用解除函式 `0x007BE5F0`。同一個 `+0x44`、`+0x5C` 等欄位不能跨不同結構直接等同。

## 2. 這批定向確認的交點與反證邊界

1. 場景登記、移除、全表清理與 deferred drain 的 **直接 E8 caller 集合不同**；掃描已知 `0x007DD1F0` 只有 `0x007B8045` 和 `0x007DD132`，不是 0007 三函式中的直接呼叫。這只否定「存在這條直接 E8 邊」的說法，不否定析構→資源→release 的多跳鏈。
2. `0x004C7DB4`、`0x004C838C` 等場景/元件清理中出現 `call 0x007BE5F0`。此為有界的 **resource release 接口交點**，並沒有證明傳入物件就是場景樹節點，也沒有證明 actor 的刪除直接 drain 全域資源池。
3. `0x007BE60F` 走 `0x007DD1A0`，因此 `0x007BE5F0` 資源解除引用有一條到 deferred producer 的靜態鏈；但 producer 的 owner 來源與 scene actor tree owner 身分目前不相等於已證實。
4. `0x007DD1F0` 兩條直接消費時機是 mode stop (`0x007B8045`) 及 manager `+0x5C` 變零 (`0x007DD132`)。這不是 frame clock 證據；不能將它寫為「每帧必 drain」或「角色移除必立即 drain」。
5. T08-177 已證實 `0x7DD26A mov eax,ecx; sub eax,ecx` 導致 `0x8912F0` 傳入的長度為零；本段繼承該**限定原始 BIN 程式路徑**，但不宣稱整體 resource pool 永不縮容／不回收。

## 3. 關鍵介面直接 E8 xref 表（以整段 .text byte 掃描）

| 目標 VA | E8 byte 候選數 | callsite (原始 5 bytes) |
|---|---:|---|
| `0x004DFF30` | 5 | `0x004A11B6` (`e875ed0300`), `0x004AA222` (`e8095d0300`), `0x004AEC03` (`e828130300`), `0x004AF4F7` (`e8340a0300`), `0x004B2F83` (`e8a8cf0200`) |
| `0x004DFBC0` | 2 | `0x004AA057` (`e8645b0300`), `0x004B2AC2` (`e8f9d00200`) |
| `0x004DFE90` | 11 | `0x00424448` (`e843ba0b00`), `0x004BA9C9` (`e8c2540200`), `0x004BB62A` (`e861480200`), `0x004BBCF0` (`e89b410200`), `0x004BC423` (`e8683a0200`), `0x004BCCDA` (`e8b1310200`), `0x004BE5AF` (`e8dc180200`), `0x004C1706` (`e885e70100`), `0x004C33E6` (`e8a5ca0100`), `0x004C4BE3` (`e8a8b20100`), `0x004C5AA8` (`e8e3a30100`) |
| `0x007BE5F0` | 42 | `0x004C7C8F` (`e85c692f00`), `0x004C7DB4` (`e837682f00`), `0x004C838C` (`e85f622f00`), `0x004C83AF` (`e83c622f00`), `0x004C8411` (`e8da612f00`), `0x004C902C` (`e8bf552f00`), `0x004C9066` (`e885552f00`), `0x004C9074` (`e877552f00`), `0x004CAFF4` (`e8f7352f00`), `0x004CC867` (`e8841d2f00`), `0x004CC89A` (`e8511d2f00`), `0x004CDDF1` (`e8fa072f00`), `0x004CE927` (`e8c4fc2e00`), `0x004CEC2C` (`e8bff92e00`), `0x004CECA7` (`e844f92e00`), `0x004D0330` (`e8bbe22e00`), `0x004D1333` (`e8b8d22e00`), `0x004D16B8` (`e833cf2e00`), `0x004D2449` (`e8a2c12e00`), `0x004D2497` (`e854c12e00`), `0x004D2522` (`e8c9c02e00`), `0x004D25A6` (`e845c02e00`)；其餘 20 個未展開 |
| `0x007DD1A0` | 2 | `0x007A8741` (`e85a4a0300`), `0x007BE60F` (`e88ceb0100`) |
| `0x007DD1F0` | 2 | `0x007B8045` (`e8a6510200`), `0x007DD132` (`e8b9000000`) |

## 4. 純靜態分析限制與證據等級

- **已確認（BIN bytes）**：本文列出有完整局部反組譯上下文的 `mov`、`call`、控制條件及直接目標；E8 raw 位移可由 `next_eip+signed rel32` 重算。
- **有界確認**：直接 E8 全段 raw byte 候選掃描只代表指定入口的相對呼叫，非全部合法 CFG xref；原碼若採虛擬呼叫、tail jump、資料內 E8 或間接 function pointer 均不含在內。
- **合理推論**：模式/回收/登記功能性名稱依資料流暫定，不能推成原版 server 決策、效能保證、所有權唯一性。
- **尚待驗證**：同一個 resource owner 的分配/建構 origin、間接 dispatch、callsite 實際 runtime 排程、例外中斷和多執行緒競態、全部異名寫入者；正式 T08 的 server-side 生成規則不屬本段。

## 5. 接續研究清單
1. 由場景物件 `+0xF4` 元件槽、`+0x164..0x360` 資源槽上游追逐次釋放，找到跨入 `0x7BE5F0` 的**同一指標**證據。
2. 將場景樹/名稱索引/共享池三類 owner 嚴格區分，查真正多跳 bridge。
3. 若有原生 call chain 完整證據再更新 T08 長期知識庫，不修改 T02/T06/T07/T16 主責。

## 附錄 A — 逐區原始 BIN 反組譯（唯讀、用於資料流稽核）

### `0x004C7D90..0x004C7DC3`

```asm
004c7d90 <.text+0xc6d90>:
  4c7d90:	89 bb 58 01 00 00    	mov    DWORD PTR [ebx+0x158],edi
  4c7d96:	c7 03 ac 76 c0 00    	mov    DWORD PTR [ebx],0xc076ac
  4c7d9c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c7d9f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c7da6:	59                   	pop    ecx
  4c7da7:	5f                   	pop    edi
  4c7da8:	5e                   	pop    esi
  4c7da9:	5b                   	pop    ebx
  4c7daa:	8b e5                	mov    esp,ebp
  4c7dac:	5d                   	pop    ebp
  4c7dad:	c3                   	ret
  4c7dae:	cc                   	int3
  4c7daf:	cc                   	int3
  4c7db0:	56                   	push   esi
  4c7db1:	8d 77 24             	lea    esi,[edi+0x24]
  4c7db4:	e8 37 68 2f 00       	call   0x7be5f0
  4c7db9:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  4c7dbc:	5e                   	pop    esi
  4c7dbd:	85 c9                	test   ecx,ecx
  4c7dbf:	74 1c                	je     0x4c7ddd
  4c7dc1:	8b 01                	mov    eax,DWORD PTR [ecx]
```

### `0x004C8380..0x004C83C0`

```asm
004c8380 <.text+0xc7380>:
  4c8380:	c0 74 0e 83 78       	shl    BYTE PTR [esi+ecx*1-0x7d],0x78
  4c8385:	24 00                	and    al,0x0
  4c8387:	8d 70 24             	lea    esi,[eax+0x24]
  4c838a:	74 05                	je     0x4c8391
  4c838c:	e8 5f 62 2f 00       	call   0x7be5f0
  4c8391:	81 c7 64 01 00 00    	add    edi,0x164
  4c8397:	bb 80 00 00 00       	mov    ebx,0x80
  4c839c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4c83a0:	8b 07                	mov    eax,DWORD PTR [edi]
  4c83a2:	85 c0                	test   eax,eax
  4c83a4:	74 0e                	je     0x4c83b4
  4c83a6:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4c83aa:	8d 70 24             	lea    esi,[eax+0x24]
  4c83ad:	74 05                	je     0x4c83b4
  4c83af:	e8 3c 62 2f 00       	call   0x7be5f0
  4c83b4:	83 c7 04             	add    edi,0x4
  4c83b7:	4b                   	dec    ebx
  4c83b8:	75 e6                	jne    0x4c83a0
  4c83ba:	5f                   	pop    edi
  4c83bb:	5e                   	pop    esi
  4c83bc:	33 c0                	xor    eax,eax
  4c83be:	5b                   	pop    ebx
  4c83bf:	c3                   	ret
```

### `0x007BE5F0..0x007BE648`

```asm
007be5f0 <.text+0x3bd5f0>:
  7be5f0:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5f2:	85 c0                	test   eax,eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    eax,DWORD PTR [eax]
  7be5f9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7be5fc:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5fe:	8b 48 74             	mov    ecx,DWORD PTR [eax+0x74]
  7be601:	85 c9                	test   ecx,ecx
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
  7be647:	b8                   	.byte 0xb8
```

### `0x007DD1A0..0x007DD1EC`

```asm
007dd1a0 <.text+0x3dc1a0>:
  7dd1a0:	55                   	push   ebp
  7dd1a1:	8b ec                	mov    ebp,esp
  7dd1a3:	53                   	push   ebx
  7dd1a4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dd1a7:	83 7b 44 01          	cmp    DWORD PTR [ebx+0x44],0x1
  7dd1ab:	57                   	push   edi
  7dd1ac:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  7dd1af:	7c 24                	jl     0x7dd1d5
  7dd1b1:	56                   	push   esi
  7dd1b2:	8d 73 64             	lea    esi,[ebx+0x64]
  7dd1b5:	56                   	push   esi
  7dd1b6:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7dd1bc:	8d 7b 7c             	lea    edi,[ebx+0x7c]
  7dd1bf:	8d 45 0c             	lea    eax,[ebp+0xc]
  7dd1c2:	e8 89 e1 fd ff       	call   0x7bb350
  7dd1c7:	56                   	push   esi
  7dd1c8:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dd1ce:	5e                   	pop    esi
  7dd1cf:	5f                   	pop    edi
  7dd1d0:	5b                   	pop    ebx
  7dd1d1:	5d                   	pop    ebp
  7dd1d2:	c2 08 00             	ret    0x8
  7dd1d5:	85 ff                	test   edi,edi
  7dd1d7:	74 0e                	je     0x7dd1e7
  7dd1d9:	e8 72 06 fe ff       	call   0x7bd850
  7dd1de:	57                   	push   edi
  7dd1df:	e8 28 40 0b 00       	call   0x89120c
  7dd1e4:	83 c4 04             	add    esp,0x4
  7dd1e7:	5f                   	pop    edi
  7dd1e8:	5b                   	pop    ebx
  7dd1e9:	5d                   	pop    ebp
  7dd1ea:	c2                   	.byte 0xc2
  7dd1eb:	08                   	.byte 0x8
```
