# T08-145 — `Host+0x0C` vfptr 建構候選與型別邊界

**Task**: T08 | **來源**: `Tartaros.bin`（12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實測）

**方法**：`.text` 在此 BIN 以 `offset=VA-0x401000` 讀取；`.rdata` 使用 PE 節區映射 `offset=VA-0x00BD2000+0x007D0600`，以 T08-125 已驗證 `0x00C4FF8C` 的 callback vtable 為交叉檢查。`objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 Tartaros.bin`。只作靜態研究，未執行除錯器。

**分級**：[確認] 指令或資料本身；[候選] 多項偏移結構相合但尚缺函式身分證據；[未知] 動態類別 / 實際方法身分。

## 1. 新定位到的 vfptr stores

[確認] `0x007A5050` 的初始化路徑確實將 secondary vfptr 寫入 `object+0x0C`，並在同一物件內寫入 `+0x1C/+0x70/+0x8C/+0xAC/+0x124` 等欄位。其中相同偏移也出現在 T08-141 的 `0x007A67C0` 入列篩選，構成具體 Host 類別候選，而非已證實同一物件。

```asm
  7a5077:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  7a507a:	33 db                	xor    ebx,ebx
  7a507c:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7a507f:	c7 46 04 4c f6 c4 00 	mov    DWORD PTR [esi+0x4],0xc4f64c
  7a5086:	c7 46 08 78 f8 c0 00 	mov    DWORD PTR [esi+0x8],0xc0f878
  7a508d:	c7 46 0c 6c f6 c4 00 	mov    DWORD PTR [esi+0xc],0xc4f66c
  7a5094:	89 5e 10             	mov    DWORD PTR [esi+0x10],ebx
  7a5097:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  7a509a:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  7a509e:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7a50a1:	8d 4e 2c             	lea    ecx,[esi+0x2c]
  7a50a4:	51                   	push   ecx
  7a50a5:	c7 06 7c f6 c4 00    	mov    DWORD PTR [esi],0xc4f67c
  7a50ab:	c7 46 04 90 f6 c4 00 	mov    DWORD PTR [esi+0x4],0xc4f690
  7a50b2:	c7 46 08 b0 f6 c4 00 	mov    DWORD PTR [esi+0x8],0xc4f6b0
  7a50b9:	c7 46 0c c0 f6 c4 00 	mov    DWORD PTR [esi+0xc],0xc4f6c0
  7a50c0:	89 46 18             	mov    DWORD PTR [esi+0x18],eax
  7a50c3:	89 5e 1c             	mov    DWORD PTR [esi+0x1c],ebx
  7a50c6:	88 5e 20             	mov    BYTE PTR [esi+0x20],bl
  7a50c9:	89 5e 24             	mov    DWORD PTR [esi+0x24],ebx
  7a50cc:	c6 46 28 01          	mov    BYTE PTR [esi+0x28],0x1
  7a50d0:	e8 4b 03 00 00       	call   0x7a5420
  7a50d5:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
```

```asm
  7a51b9:	c6 42 14 01          	mov    BYTE PTR [edx+0x14],0x1
  7a51bd:	8b 86 80 00 00 00    	mov    eax,DWORD PTR [esi+0x80]
  7a51c3:	c6 40 15 01          	mov    BYTE PTR [eax+0x15],0x1
  7a51c7:	c7 86 8c 00 00 00 01 	mov    DWORD PTR [esi+0x8c],0x1
  7a51ce:	00 00 00 
  7a51d1:	89 9e 90 00 00 00    	mov    DWORD PTR [esi+0x90],ebx
  7a51f5:	c7 86 a8 00 00 00 02 	mov    DWORD PTR [esi+0xa8],0x2
  7a51fc:	00 00 00 
  7a51ff:	89 9e ac 00 00 00    	mov    DWORD PTR [esi+0xac],ebx
  7a5205:	89 9e b0 00 00 00    	mov    DWORD PTR [esi+0xb0],ebx
  7a52c4:	89 9e 1c 01 00 00    	mov    DWORD PTR [esi+0x11c],ebx
  7a52ca:	89 9e 20 01 00 00    	mov    DWORD PTR [esi+0x120],ebx
  7a52d0:	89 9e 24 01 00 00    	mov    DWORD PTR [esi+0x124],ebx
  7a52d6:	89 9e 28 01 00 00    	mov    DWORD PTR [esi+0x128],ebx
  7a52dc:	d9 96 2c 01 00 00    	fst    DWORD PTR [esi+0x12c]
```

## 2. 兩次 vfptr 設定不是兩個獨立物件

[確認] 同一個 `ESI` 物件 `+0x0C` 先設定 `0x00C4F66C`，稍後改為 `0x00C4F6C0`；這符合基底到衍生型態的建構階段轉換，但 C++ 類別身分仍未經 RTTI 或動態型別確認。另有相鄰 `+0/+4/+8` vfptr，也提示多重介面佈局。不可單憑 `+0x0C` 恰好一致就把此類別等同 B producer 的 Host。

## 3. 與 producer 的必要身分比對

T08-141 的 `0x007A67E8 mov edi,ecx` 保存 Host；`0x007A69E5 add edi,0x0C` 會將 embedded 指標入 B queue。要證明上述 constructor 就是 Host，仍需追出 constructor 所配置物件的使用方，建立 `this` 身分鏈，或在佇列 entry 上讀取實際 `[entry]` 與 `0x00C4F6C0` 比較。

## 4. 偽碼（候選）

```cpp
void candidate_ctor(UnknownHost* p) {
    // 不代表完整 ctor；只摘錄已確認 stores
    p->interface_0C.vptr = (void**)0x00C4F66C;
    p->interface_0C.vptr = (void**)0x00C4F6C0;
    p->field_1C = 0;
    // +0x70, +0x8C, +0xAC, +0x124 另見 ASM
}
```

## 5. T08-146

採正確 `.rdata` 映射抽出這兩組 vtable 的實際 slots，不把 BIN `.text` 線性映射錯用在 `.rdata`，再比較 B consumer 的 slot +4/+8 呼叫慣例。
