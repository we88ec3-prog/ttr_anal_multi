# T08-134 — 名稱記錄查找子容器與兩條登記上游

## 第一手來源
- 原始證據：`Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪直接以原始檔計算）。
- 反組譯：使用 GNU `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000`，對當前 BIN 全檔建立線性反組譯索引；重要 VA 再以功能邊界與既有 T08-131/132 筆記核對。線性反組譯可能包含資料誤判，不等同控制流程圖。
- 研究屬**靜態分析**；未執行客戶端、未設記憶體斷點。
- 分析區分「已確認的本段指令」、「合理推測」、「未證實的全域別名身分」。

## `0x007E8AE0` 的記錄鍵搜尋
`0x007E8640` 對第一參數的 `+4` 或 `+14` 作 `this` 呼叫 `0x007E8AE0`，傳入由 `source+0x3EB0` 複製的字串。後者從 `0x007E8E00` 查找，針對節點中的鍵（可見 `0x0049B230` 的字串比較）判斷已存在或建立。`0x007E8AE0` 所用的 `+4` 是該**子容器**欄位，不是 priority entry 的 `vtable+4`。

```asm
  7e8b0e:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7e8b11:	8b f9                	mov    edi,ecx
  7e8b13:	53                   	push   ebx
  7e8b14:	8b c7                	mov    eax,edi
  7e8b16:	89 9d 68 ff ff ff    	mov    DWORD PTR [ebp-0x98],ebx
  7e8b1c:	e8 df 02 00 00       	call   0x7e8e00
  7e8b21:	8b f0                	mov    esi,eax
  7e8b23:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  7e8b1c:	e8 df 02 00 00       	call   0x7e8e00
  7e8b21:	8b f0                	mov    esi,eax
  7e8b23:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  7e8b26:	74 12                	je     0x7e8b3a
  7e8b28:	8d 46 0c             	lea    eax,[esi+0xc]
  7e8b2b:	8b d3                	mov    edx,ebx
  7e8b2d:	e8 fe 26 cb ff       	call   0x49b230
  7e8b32:	84 c0                	test   al,al
  7e8b23:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  7e8b26:	74 12                	je     0x7e8b3a
  7e8b28:	8d 46 0c             	lea    eax,[esi+0xc]
  7e8b2b:	8b d3                	mov    edx,ebx
  7e8b2d:	e8 fe 26 cb ff       	call   0x49b230
  7e8b32:	84 c0                	test   al,al
  7e8b34:	0f 84 8c 00 00 00    	je     0x7e8bc6
  7e8b3a:	33 db                	xor    ebx,ebx
  7e8b28:	8d 46 0c             	lea    eax,[esi+0xc]
  7e8b2b:	8b d3                	mov    edx,ebx
  7e8b2d:	e8 fe 26 cb ff       	call   0x49b230
  7e8b32:	84 c0                	test   al,al
  7e8b34:	0f 84 8c 00 00 00    	je     0x7e8bc6
  7e8b3a:	33 db                	xor    ebx,ebx
  7e8b3c:	89 5d bc             	mov    DWORD PTR [ebp-0x44],ebx
  7e8b3f:	c7 45 d4 0f 00 00 00 	mov    DWORD PTR [ebp-0x2c],0xf
  7e8b2d:	e8 fe 26 cb ff       	call   0x49b230
  7e8b32:	84 c0                	test   al,al
  7e8b34:	0f 84 8c 00 00 00    	je     0x7e8bc6
  7e8b3a:	33 db                	xor    ebx,ebx
  7e8b3c:	89 5d bc             	mov    DWORD PTR [ebp-0x44],ebx
  7e8b3f:	c7 45 d4 0f 00 00 00 	mov    DWORD PTR [ebp-0x2c],0xf
  7e8b46:	89 5d d0             	mov    DWORD PTR [ebp-0x30],ebx
  7e8b49:	88 5d c0             	mov    BYTE PTR [ebp-0x40],bl
  7e8b3a:	33 db                	xor    ebx,ebx
  7e8b3c:	89 5d bc             	mov    DWORD PTR [ebp-0x44],ebx
  7e8b3f:	c7 45 d4 0f 00 00 00 	mov    DWORD PTR [ebp-0x2c],0xf
  7e8b46:	89 5d d0             	mov    DWORD PTR [ebp-0x30],ebx
  7e8b49:	88 5d c0             	mov    BYTE PTR [ebp-0x40],bl
  7e8b4c:	89 5d dc             	mov    DWORD PTR [ebp-0x24],ebx
  7e8b4f:	89 5d e0             	mov    DWORD PTR [ebp-0x20],ebx
  7e8b52:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  7e8b5b:	8b 8d 68 ff ff ff    	mov    ecx,DWORD PTR [ebp-0x98]
  7e8b61:	50                   	push   eax
  7e8b62:	51                   	push   ecx
  7e8b63:	8d 95 6c ff ff ff    	lea    edx,[ebp-0x94]
  7e8b69:	52                   	push   edx
  7e8b6a:	e8 11 0c 00 00       	call   0x7e9780
  7e8b6f:	8d 85 6c ff ff ff    	lea    eax,[ebp-0x94]
  7e8b75:	50                   	push   eax
  7e8b6a:	e8 11 0c 00 00       	call   0x7e9780
  7e8b6f:	8d 85 6c ff ff ff    	lea    eax,[ebp-0x94]
  7e8b75:	50                   	push   eax
  7e8b76:	8b cf                	mov    ecx,edi
  7e8b78:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  7e8b7c:	e8 2f 0b 00 00       	call   0x7e96b0
  7e8b81:	50                   	push   eax
  7e8b82:	56                   	push   esi
```

## 新的上游分流證據
`0x007A8A18` caller 在其前核查 `[EBX+0x150]`：若為空可由 `0x007BAE80` 返回指標並寫回該欄位。另一條 `0x007BABED` caller 則從 A-array entry `+0x34` 取值後與全域欄位組合呼叫。兩條來源**不同**，均通往相同的按字串分組容器。

```asm
  7a89ce:	83 bb 50 01 00 00 00 	cmp    DWORD PTR [ebx+0x150],0x0
  7a89d5:	75 2a                	jne    0x7a8a01
  7a89d7:	d9 05 c0 56 c5 00    	fld    DWORD PTR ds:0xc556c0
  7a89dd:	8b 15 38 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba838
  7a89e3:	d9 5c 24 38          	fstp   DWORD PTR [esp+0x38]
  7a89e7:	51                   	push   ecx
  7a89e8:	d9 ee                	fldz
  7a89ea:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  7a89e7:	51                   	push   ecx
  7a89e8:	d9 ee                	fldz
  7a89ea:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  7a89ee:	d9 1c 24             	fstp   DWORD PTR [esp]
  7a89f1:	52                   	push   edx
  7a89f2:	8d 54 24 40          	lea    edx,[esp+0x40]
  7a89f6:	e8 85 24 01 00       	call   0x7bae80
  7a89fb:	89 83 50 01 00 00    	mov    DWORD PTR [ebx+0x150],eax
  7a89f6:	e8 85 24 01 00       	call   0x7bae80
  7a89fb:	89 83 50 01 00 00    	mov    DWORD PTR [ebx+0x150],eax
  7a8a01:	8b 9b 50 01 00 00    	mov    ebx,DWORD PTR [ebx+0x150]
  7a8a07:	85 db                	test   ebx,ebx
  7a8a09:	74 12                	je     0x7a8a1d
  7a8a0b:	a1 38 a8 fb 00       	mov    eax,ds:0xfba838
  7a8a10:	8b 88 8c 00 00 00    	mov    ecx,DWORD PTR [eax+0x8c]
  7a8a16:	53                   	push   ebx
  7a89fb:	89 83 50 01 00 00    	mov    DWORD PTR [ebx+0x150],eax
  7a8a01:	8b 9b 50 01 00 00    	mov    ebx,DWORD PTR [ebx+0x150]
  7a8a07:	85 db                	test   ebx,ebx
  7a8a09:	74 12                	je     0x7a8a1d
  7a8a0b:	a1 38 a8 fb 00       	mov    eax,ds:0xfba838
  7a8a10:	8b 88 8c 00 00 00    	mov    ecx,DWORD PTR [eax+0x8c]
  7a8a16:	53                   	push   ebx
  7a8a17:	51                   	push   ecx
  7a8a01:	8b 9b 50 01 00 00    	mov    ebx,DWORD PTR [ebx+0x150]
  7a8a07:	85 db                	test   ebx,ebx
  7a8a09:	74 12                	je     0x7a8a1d
  7a8a0b:	a1 38 a8 fb 00       	mov    eax,ds:0xfba838
  7a8a10:	8b 88 8c 00 00 00    	mov    ecx,DWORD PTR [eax+0x8c]
  7a8a16:	53                   	push   ebx
  7a8a17:	51                   	push   ecx
  7a8a18:	e8 23 fc 03 00       	call   0x7e8640
  7a8a0b:	a1 38 a8 fb 00       	mov    eax,ds:0xfba838
  7a8a10:	8b 88 8c 00 00 00    	mov    ecx,DWORD PTR [eax+0x8c]
  7a8a16:	53                   	push   ebx
  7a8a17:	51                   	push   ecx
  7a8a18:	e8 23 fc 03 00       	call   0x7e8640
  7a8a1d:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  7a8a21:	5f                   	pop    edi
  7a8a22:	5e                   	pop    esi
  7babd3:	8b 8e a4 00 00 00    	mov    ecx,DWORD PTR [esi+0xa4]
  7babd9:	8b 14 99             	mov    edx,DWORD PTR [ecx+ebx*4]
  7babdc:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  7babdf:	8b 0d 38 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba838
  7babe5:	8b 91 8c 00 00 00    	mov    edx,DWORD PTR [ecx+0x8c]
  7babeb:	50                   	push   eax
  7babec:	52                   	push   edx
  7babed:	e8 4e da 02 00       	call   0x7e8640
  7babdc:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  7babdf:	8b 0d 38 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba838
  7babe5:	8b 91 8c 00 00 00    	mov    edx,DWORD PTR [ecx+0x8c]
  7babeb:	50                   	push   eax
  7babec:	52                   	push   edx
  7babed:	e8 4e da 02 00       	call   0x7e8640
  7babf2:	43                   	inc    ebx
  7babf3:	3b df                	cmp    ebx,edi
```

## 重要語義邊界
1. **確認**：`source+0x3ECC` 是此函式內被 `inc` 的 DWORD；尚不能命名其意義為活躍引用計數或網路事件數。
2. **確認**：同一字串可在兩個不同內部子容器分流（source `+0x0` 條件）；其 `+4/+14` 不可和 owner `+0xB4` 混同。
3. **尚待驗證**：`0x007E8AE0` 會否建立新的 B-queue entry；本段可見它處理的是記錄與鍵比較，沒有 owner B-array 身分鏈。

## 資料流
```text
A-array entry+0x34 ─> 0x007BABED ─┐
                                   ├─> 0x007E8640 ─> child [+4/+14] ─> 0x007E8AE0
object+0x150 ───────> 0x007A8A18 ─┘                         └─> record+0x20 append
```

**後續**：分離研究通用 vector append `0x007BB750` 的參數約定及 B queue 是否有匹配實參。
