# T08-143 — B vector growth and alias safety

**第一手來源**：`Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（2026-10-27 本輪重新實測一致）。

**重現方法**：`objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 Tartaros.bin`；所摘錄 VA/bytes 直接對照原 BIN。BIN 是以 VA 0x401000 排列的反組譯資料，不能直接當原 PE sections 的 raw file offset；不宣稱使用動態除錯。

**證據分級**：`[確認]` 機器碼及確定資料流；`[推論]` 靜態語意；`[未知]` 缺少 vtable / 實際 run-time 參數。

## 本段主題：兩條 append 路徑、vector alias 保護與容量擴張

**[確認]** 在 `0x007A69EE` 先比較本地元素指標槽 `[EBP-0x14]` 的地址與 B.end / B.begin。若這個來源槽地址落在 B vector backing storage 的半開範圍 `[begin,end)`，插入之前要用來源索引避開 reallocation 後的懸空 stack/ref；正常情況從 source slot 讀出 `EDI=this+0x0C` 並直接寫入 end。這是機器碼的範圍比較與索引重算，而不是聲稱已觀察到 alias 案例。

### B append ASM

```asm
7a69d9:	8b 35 38 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba838
7a69df:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
7a69e5:	83 c7 0c             	add    edi,0xc
7a69e8:	8d 4d ec             	lea    ecx,[ebp-0x14]
7a69eb:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
7a69ee:	3b c8                	cmp    ecx,eax
7a69f0:	73 40                	jae    0x7a6a32
7a69f2:	8b 8e b4 00 00 00    	mov    ecx,DWORD PTR [esi+0xb4]
7a69f8:	8d 55 ec             	lea    edx,[ebp-0x14]
7a69fb:	3b ca                	cmp    ecx,edx
7a69fd:	77 33                	ja     0x7a6a32
7a69ff:	8b fa                	mov    edi,edx
7a6a01:	2b f9                	sub    edi,ecx
7a6a03:	c1 ff 02             	sar    edi,0x2
7a6a06:	3b 86 bc 00 00 00    	cmp    eax,DWORD PTR [esi+0xbc]
7a6a0c:	75 0b                	jne    0x7a6a19
7a6a0e:	8d 86 b4 00 00 00    	lea    eax,[esi+0xb4]
7a6a14:	e8 17 13 ff ff       	call   0x797d30
7a6a19:	8b 86 b4 00 00 00    	mov    eax,DWORD PTR [esi+0xb4]
7a6a1f:	8d 3c b8             	lea    edi,[eax+edi*4]
7a6a22:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
7a6a28:	85 c0                	test   eax,eax
7a6a2a:	74 25                	je     0x7a6a51
7a6a2c:	8b 0f                	mov    ecx,DWORD PTR [edi]
7a6a2e:	89 08                	mov    DWORD PTR [eax],ecx
7a6a30:	eb 1f                	jmp    0x7a6a51
7a6a32:	3b 86 bc 00 00 00    	cmp    eax,DWORD PTR [esi+0xbc]
7a6a38:	75 0b                	jne    0x7a6a45
7a6a3a:	8d 86 b4 00 00 00    	lea    eax,[esi+0xb4]
7a6a40:	e8 eb 12 ff ff       	call   0x797d30
7a6a45:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
7a6a4b:	85 c0                	test   eax,eax
7a6a4d:	74 02                	je     0x7a6a51
7a6a4f:	89 38                	mov    DWORD PTR [eax],edi
7a6a51:	83 86 b8 00 00 00 04 	add    DWORD PTR [esi+0xb8],0x4
7a6a58:	e8 73 19 09 00       	call   0x8383d0
```

### 泛用 grow helper `0x00797D30`

```asm
797d30:	56                   	push   esi
797d31:	8b f0                	mov    esi,eax
797d33:	8b 16                	mov    edx,DWORD PTR [esi]
797d35:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
797d38:	2b c2                	sub    eax,edx
797d3a:	c1 f8 02             	sar    eax,0x2
797d3d:	3d fe ff ff 3f       	cmp    eax,0x3ffffffe
797d42:	76 0a                	jbe    0x797d4e
797d44:	68 78 23 bf 00       	push   0xbf2378
797d49:	e8 e2 61 0e 00       	call   0x87df30
797d4e:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
797d51:	2b ca                	sub    ecx,edx
797d53:	40                   	inc    eax
797d54:	c1 f9 02             	sar    ecx,0x2
797d57:	3b c1                	cmp    eax,ecx
797d59:	76 23                	jbe    0x797d7e
797d5b:	57                   	push   edi
797d5c:	8b d1                	mov    edx,ecx
797d5e:	d1 ea                	shr    edx,1
797d60:	bf ff ff ff 3f       	mov    edi,0x3fffffff
797d65:	2b fa                	sub    edi,edx
797d67:	3b f9                	cmp    edi,ecx
797d69:	5f                   	pop    edi
797d6a:	73 04                	jae    0x797d70
797d6c:	33 c9                	xor    ecx,ecx
797d6e:	eb 02                	jmp    0x797d72
797d70:	03 ca                	add    ecx,edx
797d72:	3b c8                	cmp    ecx,eax
797d74:	73 02                	jae    0x797d78
797d76:	8b c8                	mov    ecx,eax
797d78:	51                   	push   ecx
797d79:	e8 02 00 00 00       	call   0x797d80
797d7e:	5e                   	pop    esi
797d7f:	c3                   	ret
```

**結構與邊界**

```cpp
struct PointerVector { void** begin; void** end; void** capacity; }; // +B4,+B8,+BC
// 在各分支中，若 end==capacity，傳入 &manager->B 至 grow helper
// grow helper: 讀 [EAX]、[EAX+4]、[EAX+8]，計算舊 size/capacity，必要時擴張
// append 後 B.end += sizeof(void*), 其中 sizeof(void*) == 4
```

- `0x00797D33..0x00797D4E`：依 end-begin 計算舊大小並檢查容量上界。
- `0x00797D4E..0x00797D7E`：依 capacity-begin 與 size+1 計算建議容量，必要時 call `0x00797D80`。
- `0x007A6A0E` / `0x007A6A3A`：兩條分支皆把 `&B` 交給上述 helper。
- `0x007A6A19..0x007A6A30`：來源槽在 backing storage 範圍內時，grow 後重取元素索引。
- `0x007A6A45..0x007A6A4F`：直接把候選 this+0x0C 指標寫入當前 end。

**[推論]** 這是編譯器產生的類似 `std::vector<void*>::push_back` 的形狀；不依賴 STL 類名做型別證明。

**[未知]** 動態 grow 後實際配置地址與容量、是否另外還有其他 B producer。下一段 T08-144 將與 B consumer 做物件/時序結合。

