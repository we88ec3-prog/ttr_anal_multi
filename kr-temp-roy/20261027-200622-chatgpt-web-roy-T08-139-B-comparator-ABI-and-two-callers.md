# T08-139 — 排序比較 context、entry ABI 與雙 caller 隔離

## 來源、方法、證據界限

- 實測檔案：`Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000` 線性掃描此 BIN；局部函式地址、`call rel32` 等直接從原始機器碼核對。`0x00C4FC8C` vtable 依 PE `.rdata` 對應 `VA 0xBD2000 -> raw 0x007D0600` 讀取。
- 已確認僅代表看到的指令與可閉合的靜態資料流；沒有執行遊戲、觀測動態參數或驗證機率/距離等業務語義。全檔線性反組譯會產生資料誤反組譯，不能把字串搜尋零結果當成完整無寫入證明。
- 本段為 T08-136 後接續新分析，無已知授權修改其他 Task。

## 真正比較 ABI 的靜態閉合

`0x007BB640` 由全域 `0x00FB76E8` 所指結構 `+0x0C/+0x10/+0x14` 製作 **三 DWORD 值複本**，向 `0x007BB7B0` 推入 `first, middle, last`。`middle = begin+4*min(max_selected, count)`；比較器 `0x007BBC70` 以 `entry vfptr+0x08` 對同一 context 求回傳至 x87 的結果。

```asm
  7bb664:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  7bb66a:	2b 86 b4 00 00 00    	sub    eax,DWORD PTR [esi+0xb4]
  7bb670:	8b 9e c4 00 00 00    	mov    ebx,DWORD PTR [esi+0xc4]
  7bb676:	c1 f8 02             	sar    eax,0x2
  7bb679:	3b d8                	cmp    ebx,eax
  7bb67b:	76 02                	jbe    0x7bb67f
  7bb67d:	8b d8                	mov    ebx,eax
  7bb67f:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7bb686:	75 27                	jne    0x7bb6af
  7bb688:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  7bb68f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7bb696:	e8 45 db fd ff       	call   0x7991e0
  7bb69b:	68 e0 d2 bc 00       	push   0xbcd2e0
  7bb6a0:	e8 75 70 0d 00       	call   0x89271a
  7bb6a5:	83 c4 04             	add    esp,0x4
  7bb6a8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7bb6af:	a1 e8 76 fb 00       	mov    eax,ds:0xfb76e8
  7bb6b4:	8b 78 0c             	mov    edi,DWORD PTR [eax+0xc]
  7bb6b7:	8b 96 b4 00 00 00    	mov    edx,DWORD PTR [esi+0xb4]
  7bb6bd:	83 ec 0c             	sub    esp,0xc
  7bb6c0:	8b cc                	mov    ecx,esp
  7bb6c2:	89 39                	mov    DWORD PTR [ecx],edi
  7bb6c4:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  7bb6c7:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  7bb6ca:	89 79 04             	mov    DWORD PTR [ecx+0x4],edi
  7bb6cd:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7bb6d0:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  7bb6d6:	50                   	push   eax
  7bb6d7:	8d 04 9a             	lea    eax,[edx+ebx*4]
  7bb6da:	50                   	push   eax
  7bb6db:	52                   	push   edx
  7bb6dc:	e8 cf 00 00 00       	call   0x7bb7b0
  7bb6e1:	83 c4 18             	add    esp,0x18
  7bb6e4:	33 ff                	xor    edi,edi
  7bb6e6:	85 db                	test   ebx,ebx
  7bb6e8:	74 1b                	je     0x7bb705
  7bb6ea:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bb6f0:	8b 8e b4 00 00 00    	mov    ecx,DWORD PTR [esi+0xb4]
  7bb6f6:	8b 0c b9             	mov    ecx,DWORD PTR [ecx+edi*4]
  7bb6f9:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bb6fb:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7bb6fe:	ff d0                	call   eax
  7bb700:	47                   	inc    edi
  7bb701:	3b fb                	cmp    edi,ebx
  7bb703:	72 eb                	jb     0x7bb6f0
```

### 比較器內部再次核驗

```asm
  7bbc70:	55                   	push   ebp
  7bbc71:	8b ec                	mov    ebp,esp
  7bbc73:	83 ec 0c             	sub    esp,0xc
  7bbc76:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7bbc79:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7bbc7b:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bbc7d:	8b 52 08             	mov    edx,DWORD PTR [edx+0x8]
  7bbc80:	53                   	push   ebx
  7bbc81:	8b 1f                	mov    ebx,DWORD PTR [edi]
  7bbc83:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  7bbc86:	8d 45 0c             	lea    eax,[ebp+0xc]
  7bbc89:	50                   	push   eax
  7bbc8a:	ff d2                	call   edx
  7bbc8c:	dd 5d f4             	fstp   QWORD PTR [ebp-0xc]
  7bbc8f:	8b 03                	mov    eax,DWORD PTR [ebx]
  7bbc91:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7bbc94:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  7bbc97:	51                   	push   ecx
  7bbc98:	8b cb                	mov    ecx,ebx
  7bbc9a:	ff d2                	call   edx
  7bbc9c:	dc 5d f4             	fcomp  QWORD PTR [ebp-0xc]
  7bbc9f:	df e0                	fnstsw ax
  7bbca1:	f6 c4 41             	test   ah,0x41
  7bbca4:	75 08                	jne    0x7bbcae
  7bbca6:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7bbca8:	8b 06                	mov    eax,DWORD PTR [esi]
  7bbcaa:	89 0e                	mov    DWORD PTR [esi],ecx
  7bbcac:	89 07                	mov    DWORD PTR [edi],eax
  7bbcae:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
```

- `[esi]`、`[edi]` 是元素槽內物件指標；`mov edx,[ecx]` 取得 vptr 後 `mov edx,[edx+8]`，`call edx` 取得浮點回傳。
- `fstp qword [ebp-0xc]` / `fcomp qword` 比較兩個呼叫回傳；`fnstsw ax`, `test ah,0x41` 決定是否交換 entry pointer。**只確認相對比較與交換，不推定距離越大越優先或更高優先級的語義**。
- `0x007BB6F9～0x007BB6FE` 執行前 N 筆是 `entry->vtable+0x04`，與 comparator 的 `+0x08` 分離。

## 全部已知直接呼叫 consumer 的位置

```asm
  79a376:	83 c4 04             	add    esp,0x4
  79a379:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  79a37c:	6a 00                	push   0x0
  79a37e:	68 50 32 fe 00       	push   0xfe3250
  79a383:	e8 68 50 03 00       	call   0x7cf3f0
  79a388:	57                   	push   edi
  79a389:	e8 d2 10 00 00       	call   0x79b460
  79a38e:	8b 35 38 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba838
  79a394:	e8 a7 12 02 00       	call   0x7bb640
  79a399:	8b 8f a0 00 00 00    	mov    ecx,DWORD PTR [edi+0xa0]
  79a39f:	8b 01                	mov    eax,DWORD PTR [ecx]
  79a3a1:	8b 97 98 00 00 00    	mov    edx,DWORD PTR [edi+0x98]
  79a3a7:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  79a3aa:	52                   	push   edx
  79a3ab:	ff d0                	call   eax
  79a3ad:	8b 0f                	mov    ecx,DWORD PTR [edi]
  79a3af:	8b 11                	mov    edx,DWORD PTR [ecx]
```
```asm
  7bac62:	83 c6 2c             	add    esi,0x2c
  7bac65:	4b                   	dec    ebx
  7bac66:	75 ec                	jne    0x7bac54
  7bac68:	8b 5d ec             	mov    ebx,DWORD PTR [ebp-0x14]
  7bac6b:	8b 75 e8             	mov    esi,DWORD PTR [ebp-0x18]
  7bac6e:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  7bac71:	40                   	inc    eax
  7bac72:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7bac75:	3b c3                	cmp    eax,ebx
  7bac77:	72 ac                	jb     0x7bac25
  7bac79:	e8 c2 09 00 00       	call   0x7bb640
  7bac7e:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  7bac81:	8b 08                	mov    ecx,DWORD PTR [eax]
  7bac83:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  7bac86:	50                   	push   eax
  7bac87:	ff d2                	call   edx
  7bac89:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bac8c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
```

兩個 caller 對 global manager 的直接呼叫地址分別為 `0x0079A394` 與 `0x007BAC79`。此前者屬全域 22 桶 dispatcher 的前置階段，後者位於不同 A-array/記錄調度之後；兩者**不證明** B entry 的 `execute()` 寫入 22 桶，也不證明每次 caller 執行時 B 必然非空。

## 偽碼

```cpp
void consumeB(Manager* owner) {
  size_t count = (owner->b.end - owner->b.begin);
  size_t n = std::min((size_t)owner->max_selected, count);
  Context ctx = *(Context*)((char*)global_FB76E8 + 0x0C);
  partial_sort_like(owner->b.begin, owner->b.begin+n, owner->b.end, ctx);
  for (size_t i=0;i<n;i++) owner->b.begin[i]->execute();
  owner->b.end = owner->b.begin;
}
```

`partial_sort_like` 是算法型態假說而非已證實的原始 STL 符號；也不應以 `ctx` 欄位值認定位置/相機/距離。

## 下一段

對 B producer 搜尋結果與既有 22 桶呼叫鏈進行最後證據分級，形成動態觀測的最小可重現方案與 T08-141 明確候選，避免重複 T08-133～136 的無效 xref。
