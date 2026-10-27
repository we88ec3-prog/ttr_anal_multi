# T08-147 — Secondary vfptr 析構回寫、生命週期及 B queue 借用指標風險

**Task**: T08 | **來源**: `Tartaros.bin`（12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實測）

**方法**：`.text` 在此 BIN 以 `offset=VA-0x401000` 讀取；`.rdata` 使用 PE 節區映射 `offset=VA-0x00BD2000+0x007D0600`，以 T08-125 已驗證 `0x00C4FF8C` 的 callback vtable 為交叉檢查。`objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 Tartaros.bin`。只作靜態研究，未執行除錯器。

**分級**：[確認] 指令或資料本身；[候選] 多項偏移結構相合但尚缺函式身分證據；[未知] 動態類別 / 實際方法身分。

## 1. 新確認的析構階段回寫

[確認] `0x007A5A51` 將 `Host+0x0C` 的 vfptr 回寫至建構早期的 `0x00C4F66C`，緊接著恢復 `+0x08/+0x04/+0x00` vfptr，符合解構時撤銷衍生型態視圖的模式。之前研究僅知道 `B entry = Host+0x0C`；這次補出此候選 Host 的 secondary vptr 生命週期證據。

```asm
  7a5a26:	8d 53 2c             	lea    edx,[ebx+0x2c]
  7a5a29:	52                   	push   edx
  7a5a2a:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  7a5a2e:	e8 ed fa ff ff       	call   0x7a5520
  7a5a33:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  7a5a37:	8b 4b 14             	mov    ecx,DWORD PTR [ebx+0x14]
  7a5a3a:	85 c9                	test   ecx,ecx
  7a5a3c:	74 13                	je     0x7a5a51
  7a5a3e:	8d 41 08             	lea    eax,[ecx+0x8]
  7a5a41:	83 ca ff             	or     edx,0xffffffff
  7a5a44:	f0 0f c1 10          	lock xadd DWORD PTR [eax],edx
  7a5a48:	75 07                	jne    0x7a5a51
  7a5a4a:	8b 01                	mov    eax,DWORD PTR [ecx]
  7a5a4c:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7a5a4f:	ff d2                	call   edx
  7a5a51:	c7 43 0c 6c f6 c4 00 	mov    DWORD PTR [ebx+0xc],0xc4f66c
  7a5a58:	c7 43 08 78 f8 c0 00 	mov    DWORD PTR [ebx+0x8],0xc0f878
  7a5a5f:	c7 43 04 4c f6 c4 00 	mov    DWORD PTR [ebx+0x4],0xc4f64c
  7a5a66:	c7 03 68 f4 c4 00    	mov    DWORD PTR [ebx],0xc4f468
  7a5a6c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7a5a6f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7a5a76:	59                   	pop    ecx
  7a5a77:	5f                   	pop    edi
  7a5a78:	5e                   	pop    esi
  7a5a79:	5b                   	pop    ebx
  7a5a7a:	8b e5                	mov    esp,ebp
  7a5a7c:	5d                   	pop    ebp
  7a5a7d:	c2 04 00             	ret    0x4
```

## 2. Producer / consumer 不是 ownership 證明

[確認] `0x007A69E5` 只用位址加法產生 embedded entry，append 時沒有對 Host 本身做 retain；`0x007BB6F0..0x007BB703` 只對 entry 虛擬呼叫；consumer 的邏輯清空並不執行 Host 析構。因此 B vector 很可能是非 owning / 借用指標容器，但「無任何外部 retain 保護」未得到全域驗證。

```asm
  7a69d9:	8b 35 38 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba838
  7a69df:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  7a69e5:	83 c7 0c             	add    edi,0xc
  7a69e8:	8d 4d ec             	lea    ecx,[ebp-0x14]
  7a69eb:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  7a69ee:	3b c8                	cmp    ecx,eax
  7a6a32:	3b 86 bc 00 00 00    	cmp    eax,DWORD PTR [esi+0xbc]
  7a6a38:	75 0b                	jne    0x7a6a45
  7a6a3a:	8d 86 b4 00 00 00    	lea    eax,[esi+0xb4]
  7a6a40:	e8 eb 12 ff ff       	call   0x797d30
  7a6a45:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  7a6a4b:	85 c0                	test   eax,eax
  7a6a4d:	74 02                	je     0x7a6a51
  7a6a4f:	89 38                	mov    DWORD PTR [eax],edi
  7a6a51:	83 86 b8 00 00 00 04 	add    DWORD PTR [esi+0xb8],0x4
```

## 3. 安全性約束與未知

[候選] 若入列 Host 與 `0x007A5050/0x007A5A51` 屬相同類別，在 consumer 調用之前 Host 完成析構，則 entry vptr 已回寫並且可能失效。這是需要用生命週期證據排除的風險，**不是**聲稱遊戲存在 use-after-free。

[未知] 需要尋找 Host 的 retain/release、移除 B entry 路徑、dispatcher 調用與物件銷毀的同幀先後順序。

## 4. 偽碼

```cpp
// hypothesis only; no ownership contract proven
struct BorrowedEntry { void **vptr; };
queue.push(reinterpret_cast<BorrowedEntry*>(reinterpret_cast<char*>(host)+0x0C));
// must verify host lifetime covers drain()/sort() before assigning a stable type
```

## 5. T08-148

建立 producer→B queue→排序/執行→全域22桶的最小「可證實 / 未證實」圖，並給出可執行的動態資料收集與斷點位址。
