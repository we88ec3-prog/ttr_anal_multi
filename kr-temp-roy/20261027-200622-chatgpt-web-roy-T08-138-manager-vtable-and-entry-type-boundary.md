# T08-138 — 全域 manager 虛表實體與間接方法歧義

## 來源、方法、證據界限

- 實測檔案：`Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000` 線性掃描此 BIN；局部函式地址、`call rel32` 等直接從原始機器碼核對。`0x00C4FC8C` vtable 依 PE `.rdata` 對應 `VA 0xBD2000 -> raw 0x007D0600` 讀取。
- 已確認僅代表看到的指令與可閉合的靜態資料流；沒有執行遊戲、觀測動態參數或驗證機率/距離等業務語義。全檔線性反組譯會產生資料誤反組譯，不能把字串搜尋零結果當成完整無寫入證明。
- 本段為 T08-136 後接續新分析，無已知授權修改其他 Task。

## 新核驗：`0x00C4FC8C` 虛表不是 T08-129 callback 虛表

對 `0x007B8E50` 建構時寫入 `0x00C4FC8C`，改以 `.rdata` 的 **正確 PE RVA-to-file** 映射取出八個 DWORD（不能用 `.text` 的 `VA-0x401000` 映射讀 vtable，否則只會得到字串/偽資料）：

| vtable 位址 | 讀取的 DWORD / 方法候選 |
|---|---|
| `0x00C4FC8C` (+0x00) | `0x007BA8A0` |
| `0x00C4FC90` (+0x04) | `0x007B8C80` |
| `0x00C4FC94` (+0x08) | `0x007B9390` |
| `0x00C4FC98` (+0x0C) | `0x007B96E0` |
| `0x00C4FC9C` (+0x10) | `0x007B98B0` |
| `0x00C4FCA0` (+0x14) | `0x007B99C0` |
| `0x00C4FCA4` (+0x18) | `0x007BA380` |
| `0x00C4FCA8` (+0x1C) | `0x007BA6B0` |

直接對照程式碼：

```asm
  7b8e78:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  7b8e7b:	33 db                	xor    ebx,ebx
  7b8e7d:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7b8e80:	c7 07 8c fc c4 00    	mov    DWORD PTR [edi],0xc4fc8c
  7b8e86:	be 0f 00 00 00       	mov    esi,0xf
  7b8e8b:	89 77 18             	mov    DWORD PTR [edi+0x18],esi
  7b8e8e:	89 5f 14             	mov    DWORD PTR [edi+0x14],ebx
  7b8e91:	88 5f 04             	mov    BYTE PTR [edi+0x4],bl
  7b8e94:	89 77 34             	mov    DWORD PTR [edi+0x34],esi
  7b8e97:	89 5f 30             	mov    DWORD PTR [edi+0x30],ebx
  7b8e9a:	88 5f 20             	mov    BYTE PTR [edi+0x20],bl
  7b8e9d:	89 5f 3c             	mov    DWORD PTR [edi+0x3c],ebx
```

另有已在 T08-131 證實的全域 manager cleanup 間接派送（`[manager->vtable+0x04]`），對這份表而言 slot `+4` 的候選是 `0x007B8C80`：

```asm
  7aafa9:	33 c5                	xor    eax,ebp
  7aafab:	50                   	push   eax
  7aafac:	8d 45 f4             	lea    eax,[ebp-0xc]
  7aafaf:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7aafb5:	8b 0d 38 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba838
  7aafbb:	33 ff                	xor    edi,edi
  7aafbd:	bb 01 00 00 00       	mov    ebx,0x1
  7aafc2:	3b cf                	cmp    ecx,edi
  7aafc4:	74 0e                	je     0x7aafd4
  7aafc6:	8b 01                	mov    eax,DWORD PTR [ecx]
  7aafc8:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7aafcb:	53                   	push   ebx
  7aafcc:	ff d2                	call   edx
  7aafce:	89 3d 38 a8 fb 00    	mov    DWORD PTR ds:0xfba838,edi
  7aafd4:	83 ce ff             	or     esi,0xffffffff
```

## 關鍵的型別排除

- `manager` vptr `0x00C4FC8C`；T08-129 的 22 桶 callback 物件 vptr 則為 `0x00C4FF8C`，兩個相差 `0x300`，不可互換。
- consumer 對 `B-entry->vtable+0x04/+0x08` 的呼叫**針對陣列元素**，不是對 `manager` 的上述虛表呼叫。即使兩者皆使用同一 slot offset，也沒有型別同一性的證據。
- 部分虛表候選落於反組譯顯示的函式中段；若沒有 ABI thunk / 函式邊界或動態位址確認，僅記錄 DWORD 指向地址，**不強行替每個 slot 命名**。

## 暫定資料模型

```cpp
struct Manager {
  void **vfptr; // +0 = 0x00C4FC8C
  // ...
  PointerVector a; // +A4
  PointerVector b; // +B4
};
struct BEntryInterface {
  virtual void unknown0();
  virtual void execute();  // +4, 0x007BB6FB
  virtual double score(Context*); // +8, x87 ST(0), 0x007BBC7D
};
```

最後一個型別只是依 dispatch ABI 編寫的**介面草案**，並非已找到具體 B entry constructor。

## 下一段

核實比較器的上下文與兩個 consumer caller 的入口路徑；確認所謂排序評分並非存於 manager 的 vtable。
