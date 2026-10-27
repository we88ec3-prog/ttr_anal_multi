# T08-137 — B 佇列直接寫入交叉參照與區域性封閉

## 來源、方法、證據界限

- 實測檔案：`Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000` 線性掃描此 BIN；局部函式地址、`call rel32` 等直接從原始機器碼核對。`0x00C4FC8C` vtable 依 PE `.rdata` 對應 `VA 0xBD2000 -> raw 0x007D0600` 讀取。
- 已確認僅代表看到的指令與可閉合的靜態資料流；沒有執行遊戲、觀測動態參數或驗證機率/距離等業務語義。全檔線性反組譯會產生資料誤反組譯，不能把字串搜尋零結果當成完整無寫入證明。
- 本段為 T08-136 後接續新分析，無已知授權修改其他 Task。

## 研究問題與新結果

本段將原先 `+0xB8` 未知 producer 的搜尋限定到**確定同一個 `0x10C` bytes 全域 manager**（constructor `0x007B8E50`、consumer `0x007BB640`）所屬局部 `VA 0x007B8000～0x007C0000`，精確分開欄位讀、寫、取址及不同區段的同 offset。

**本段新確認**：在該區段的線性 ASM 中，`[base+0xB4/0xB8/0xBC]` 的完整可見命中僅包括建構置零、析構歸零、consumer 讀取與 consumer end 重設；沒有直接 `lea reg,[manager+0xB4]` 或 `mov [manager+0xB8],new_end` 的另一路 append。這是一項**特定 VA 區段與特定指令形態**的陰性結果，而非全遊戲不存在 producer 的結論。

## 直接欄位使用的完整命中

```asm
  7b8f76:	89 9f b4 00 00 00    	mov    DWORD PTR [edi+0xb4],ebx
  7b8f7c:	89 9f b8 00 00 00    	mov    DWORD PTR [edi+0xb8],ebx
  7b8f82:	89 9f bc 00 00 00    	mov    DWORD PTR [edi+0xbc],ebx
  7b91cf:	8b 83 b4 00 00 00    	mov    eax,DWORD PTR [ebx+0xb4]
  7b91e2:	89 b3 b4 00 00 00    	mov    DWORD PTR [ebx+0xb4],esi
  7b91e8:	89 b3 b8 00 00 00    	mov    DWORD PTR [ebx+0xb8],esi
  7b91ee:	89 b3 bc 00 00 00    	mov    DWORD PTR [ebx+0xbc],esi
  7bb664:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  7bb66a:	2b 86 b4 00 00 00    	sub    eax,DWORD PTR [esi+0xb4]
  7bb6b7:	8b 96 b4 00 00 00    	mov    edx,DWORD PTR [esi+0xb4]
  7bb6d0:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  7bb6f0:	8b 8e b4 00 00 00    	mov    ecx,DWORD PTR [esi+0xb4]
  7bb705:	8b 8e b8 00 00 00    	mov    ecx,DWORD PTR [esi+0xb8]
  7bb70b:	8b be b4 00 00 00    	mov    edi,DWORD PTR [esi+0xb4]
  7bb730:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  7bddb0:	d9 94 24 b8 00 00 00 	fst    DWORD PTR [esp+0xb8]
  7bdeba:	d9 94 24 b8 00 00 00 	fst    DWORD PTR [esp+0xb8]
  7be5b7:	89 bc 24 b8 00 00 00 	mov    DWORD PTR [esp+0xb8],edi
  7be5c5:	89 94 24 b4 00 00 00 	mov    DWORD PTR [esp+0xb4],edx
  7be723:	d9 9c 24 bc 00 00 00 	fstp   DWORD PTR [esp+0xbc]
  7be760:	89 84 24 b4 00 00 00 	mov    DWORD PTR [esp+0xb4],eax
  7be772:	89 8c 24 b8 00 00 00 	mov    DWORD PTR [esp+0xb8],ecx
  7bed2f:	89 88 b8 00 00 00    	mov    DWORD PTR [eax+0xb8],ecx
```

## 兩條可核對的生存期路徑

建構在 `0x007B8F76～0x007B8F82` 清三指標；析構 `0x007B91CF～0x007B91EE` 釋放/歸零；consumer 在 `0x007BB705～0x007BB730` 把 end 設回 begin。

```asm
  7b91c3:	89 b3 cc 00 00 00    	mov    DWORD PTR [ebx+0xcc],esi
  7b91c9:	89 b3 d0 00 00 00    	mov    DWORD PTR [ebx+0xd0],esi
  7b91cf:	8b 83 b4 00 00 00    	mov    eax,DWORD PTR [ebx+0xb4]
  7b91d5:	3b c6                	cmp    eax,esi
  7b91d7:	74 09                	je     0x7b91e2
  7b91d9:	50                   	push   eax
  7b91da:	e8 2d 84 0d 00       	call   0x89160c
  7b91df:	83 c4 04             	add    esp,0x4
  7b91e2:	89 b3 b4 00 00 00    	mov    DWORD PTR [ebx+0xb4],esi
  7b91e8:	89 b3 b8 00 00 00    	mov    DWORD PTR [ebx+0xb8],esi
  7b91ee:	89 b3 bc 00 00 00    	mov    DWORD PTR [ebx+0xbc],esi
  7b91f4:	8b 83 a4 00 00 00    	mov    eax,DWORD PTR [ebx+0xa4]
```

## 偽碼與適用範圍

```cpp
struct PointerVector { void **begin, **end, **capacity; };
struct GlobalOwnerPartial {
  /* +0xA4 */ PointerVector a;
  /* +0xB4 */ PointerVector b;
  /* +0xC4 */ uint32_t max_selected;
};
// ctor: b = {nullptr,nullptr,nullptr};
// consumer: if(b.begin != b.end) b.end = b.begin;
// dtor: release(b.begin); b = {nullptr,nullptr,nullptr};
```

**已確認**：B begin/end/capacity 符合三指標容器的物理操作，max_selected 以 4 初始化。**未確認**：真正 B append 是否經 alias/helper、反射或模組外寫入；entry 類型與資料源。

## 下一段

從 `0x00C4FC8C` 全域 owner vtable 反查實體方法，不把相同 offset 的其他物件誤認成 owner；再定位可能間接持有 B 容器別名的欄位/引數。
