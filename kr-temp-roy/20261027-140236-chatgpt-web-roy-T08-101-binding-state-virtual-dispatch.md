# T08-101 — Binding `+0x80` 寫入者、雙 vtable 與子項調度條件

- 研究者：`chatgpt-web roy`
- 分析時間（Asia/Taipei）：`2026-10-27T14:02:36+08:00`
- 二進位：`Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（與交接值一致）
- 手法：以 GNU objdump 針對**原始 PE32 BIN** 的 VA 直接反組譯，並對 `.rdata` 常數表交叉核對。未執行遊戲，沒有 RTTI 類別符號，所有命名僅暫定。
- 本段不修改原始 EXE/BIN、不提交 GitHub。

## 1. 已確認的新證據與修正

1. **`0x007F2520` 是 `binding+0x80` 的確定寫入者**。`0x007F25C7 test eax,eax; 0x007F25C9 sete cl; 0x007F25CE mov [esi+0x80],eax`。它將前段回傳值歸一為 Boolean：返回 **0 則寫 1**，返回非零則寫 0。若全域 `[0x00FB76E4] == 0`，函式先把返回值設為 1，因而寫 0；非零時，呼叫 `0x00838860` 再反轉其是否為零的結果。**精確語義不能直接命名為停止/死亡/鎖定**。
2. `0x007F2520` 中的計算輸入包括 `binding+0xB0`、以及從 `binding+0x88` 指向的關聯物件讀取 `+0x68/+0x6C/+0x70`（`0x007F254F～0x007F2564`）。這三個 DWORD 以浮點數型態傳遞給 `0x00838860`（該函式的實際業務語義待追）。另外讀取全域 `[0x00FB76B0]`，但呼叫前暫不能單憑此片段判定該全域值是否被後續真正使用。
3. `0x007BDF40` 的調用閘為 `item+0x08 != NULL`、`item[0] == 0`、`binding+0x80 == 0`，成立才以 `binding->vtable+0x18` 呼叫；`0x007BDF72～0x007BDF82` 可直接驗證。**因此 `+0x80 == 1` 會阻斷此特定虛擬調用路徑**，並非所有 binding 更新都停用。
4. `0x007F23B0`（主 vtable `+0x18`）**先檢查 `binding+0x7C`**；若非零，會遍歷 `+0x8C～+0x90` 的每筆 8-byte 紀錄並寫入全域索引緩衝，隨後用次級虛擬介面 `binding+0x84` 的 `vtable+0x04` 得到索引，以 0x2004 stride 定位分桶，最多受計數 `0x800` 的界限控制。此路徑**不是直接讀取 `+0x80`**，也不能稱其為動畫或技能事件而無證據。
5. `0x007F2320`（主 vtable `+0x14`）將參數浮點值與 `binding+0x70` 比較，在特定條件下將 `binding+0x7C = 1`，複製關聯物件變換（`0x0077EA00`）、調度關聯物件 `vtable+0x1C`、再呼叫 `0x00780150`。其他分支將 `+0x7C=0`。因此 `+0x7C` 是另一個**條件式事件/派送旗標**，不是 `+0x80`。
6. `0x007F24F0`（主 vtable `+0x1C`）讀取 `binding+0x70` 與傳入 float，產生 0/1 返回；不應自動命名成動畫播放完成判斷。
7. vtable `.rdata` 的精確對照：`0x00C50A8C+0x28 = 0x007F2520`；`0x00C50ABC+0x08 = 0x007F25F0`，其機器碼 `sub ecx,0x84; jmp 0x007F23B0` 是次級子物件的 **this-adjusting thunk**。另一個 `0x007F2600` 對 `ecx` 減 `0x84` 後跳到析構 `0x007F1620`。**主 vtable 與次級 vtable 不是兩個可任意互換的物件類別。**
8. `0x007F21A0` 的複製路徑已重新核對：配置 `0xB4` bytes → `0x007F15B0` 初始化 → 複製 `+0x70/+0xB0/+0xAC`；如來源 `+0x88` 非 NULL，先呼叫關聯物件 `vtable+0x0C` 取得新關聯物件，再走 `0x007C7DD0`、`0x007F1EB0`、`0x007CBB00`。**這不是單純淺拷貝 `+0x88`**；但內部所有權語義仍待驗證。

## 2. 已知 vtable（BIN rdata DWORD）

主 vtable = `0x00C50A8C`：`+0x00→0x007F1620`, `+0x04→0x007F1770`, `+0x08→0x007F2110`, `+0x0C→0x007F20E0`, `+0x10→0x007F21A0`, `+0x14→0x007F2320`, `+0x18→0x007F23B0`, `+0x1C→0x007F24F0`, `+0x20→0x00476430`, `+0x24→0x005F5D10`, `+0x28→0x007F2520`。

次級 vtable = `0x00C50ABC`：`+0x00→0x007F2600`（析構 thunk），`+0x04→0x007F15A0`，`+0x08→0x007F25F0`（派送 thunk），後續條目仍待逐項確認。`obj+0x84` 是次級 vptr。

## 3. 暫定結構與 C++ 偽碼

```cpp
struct ProviderBindingB4 {
    void **vtable;           // +0x00; 0x00C50A8C
    unsigned char unknown04[0x6C];
    float threshold70;      // +0x70; 由 +0x14 / +0x1C 使用
    unsigned char unknown74[0x08];
    uint32_t dispatchReady7C; // +0x7C; 條件更新/派送
    uint32_t gated80;        // +0x80; 更新 +0x28 反轉外部判斷結果
    void **secondaryVptr;   // +0x84; 0x00C50ABC
    void *associated;       // +0x88; 另一個多型物件
    // +0x8C/+0x90: 8-byte records begin/end; +0xB0: float parameter
};

void updateGate80(ProviderBindingB4* self) {
    int status;
    if (global_FB76E4 == 0) {
        status = 1;
    } else {
        // 參數從 associated+0x68/+0x6C/+0x70 與 self+0xB0 擷取
        status = external_00838860(/* 4 float values */);
    }
    self->gated80 = (status == 0);
}

void dispatchResourceItems(Resource *r) {
  for (Item *item : r->items) {
    ProviderBindingB4* b = item->binding; // item+0x08
    if (b != nullptr && item->firstByte == 0 && b->gated80 == 0)
      b->vtable_slot_18(); // 對於 0x00C50A8C → 0x007F23B0
  }
}
```

## 4. 指標來源與生命週期的已證界線

- `0x007F15B0` 對 `+0x84` 寫入次級 vptr，`+0x88` 設 0，且多個末端容器指標設 0；**對 `+0x80` 的具體初始化可能由基底建構 `0x007E9BF0` 進行**，本段未完整讀該基底函式，不能宣稱唯一初值。
- `0x007F2520` 的 `+0x80` 寫入具備實際反轉外部回傳值的證據；是否尚有其他不在此範圍的寫入者，需要全 `.text` 實體別名及記憶體流追蹤。
- `0x007F2320` 所使用的 `+0x88` 關聯物件與 `0x007F21A0` 複製時 `vtable+0x0C` 回傳的物件相關，但不能直接定為單純 refcounted clone，因為仍有 `0x007C7DD0` 等資料轉換。
- `0x007F23B0` 的 `0x800` 計數上限為該條寫入全域分桶路徑上的局部檢查，**不是**指 resource 最多 2048 個動畫或技能。

## 5. 待確認問題 / T08-102

1. 深入反組譯 `0x00838860` 的真正判定邏輯與其所有呼叫者，釐清 gate80 對何種外部狀態敏感。
2. 追 `0x007E9BF0` 基底物件初始化以核對 `+0x70/+0x7C/+0x80` 初始狀態。
3. 查 `0x007F23B0` 使用的全域 `0x00FB7740`，確認 0x2004 bytes 分桶表的建立/消費者。
4. 釐清 `0x007F1EB0`、`0x007C7DD0`、`0x007CBB00` 造成的關聯物件複製、引用、回收。
5. 長期：場景 `object vtable+0x20` 真正的更新主迴圈仍待追查；不可與本段 Provider vtable 的 `+0x20` 混用。

## 6. 原始 BIN 反組譯證據（選定函式全範圍）

### Provider 初始化與雙 vptr (`0x007F15B0–0x007F16C5`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f15b0 <.text+0x3f05b0>:
  7f15b0:	55                   	push   ebp
  7f15b1:	8b ec                	mov    ebp,esp
  7f15b3:	56                   	push   esi
  7f15b4:	50                   	push   eax
  7f15b5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7f15b8:	8b f1                	mov    esi,ecx
  7f15ba:	e8 31 86 ff ff       	call   0x7e9bf0
  7f15bf:	d9 05 18 7d c0 00    	fld    DWORD PTR ds:0xc07d18
  7f15c5:	c7 86 84 00 00 00 68 	mov    DWORD PTR [esi+0x84],0xc4f468
  7f15cc:	f4 c4 00 
  7f15cf:	33 c0                	xor    eax,eax
  7f15d1:	89 86 88 00 00 00    	mov    DWORD PTR [esi+0x88],eax
  7f15d7:	c7 06 8c 0a c5 00    	mov    DWORD PTR [esi],0xc50a8c
  7f15dd:	c7 86 84 00 00 00 bc 	mov    DWORD PTR [esi+0x84],0xc50abc
  7f15e4:	0a c5 00 
  7f15e7:	89 86 8c 00 00 00    	mov    DWORD PTR [esi+0x8c],eax
  7f15ed:	89 86 90 00 00 00    	mov    DWORD PTR [esi+0x90],eax
  7f15f3:	89 86 94 00 00 00    	mov    DWORD PTR [esi+0x94],eax
  7f15f9:	89 86 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],eax
  7f15ff:	89 86 a0 00 00 00    	mov    DWORD PTR [esi+0xa0],eax
  7f1605:	89 86 a4 00 00 00    	mov    DWORD PTR [esi+0xa4],eax
  7f160b:	d9 9e b0 00 00 00    	fstp   DWORD PTR [esi+0xb0]
  7f1611:	89 86 ac 00 00 00    	mov    DWORD PTR [esi+0xac],eax
  7f1617:	8b c6                	mov    eax,esi
  7f1619:	5e                   	pop    esi
  7f161a:	5d                   	pop    ebp
  7f161b:	c2 04 00             	ret    0x4
  7f161e:	cc                   	int3
  7f161f:	cc                   	int3
  7f1620:	55                   	push   ebp
  7f1621:	8b ec                	mov    ebp,esp
  7f1623:	56                   	push   esi
  7f1624:	8b f1                	mov    esi,ecx
  7f1626:	e8 a5 00 00 00       	call   0x7f16d0
  7f162b:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  7f162f:	74 09                	je     0x7f163a
  7f1631:	56                   	push   esi
  7f1632:	e8 d5 fb 09 00       	call   0x89120c
  7f1637:	83 c4 04             	add    esp,0x4
  7f163a:	8b c6                	mov    eax,esi
  7f163c:	5e                   	pop    esi
  7f163d:	5d                   	pop    ebp
  7f163e:	c2 04 00             	ret    0x4
  7f1641:	cc                   	int3
  7f1642:	cc                   	int3
  7f1643:	cc                   	int3
  7f1644:	cc                   	int3
  7f1645:	cc                   	int3
  7f1646:	cc                   	int3
  7f1647:	cc                   	int3
  7f1648:	cc                   	int3
  7f1649:	cc                   	int3
  7f164a:	cc                   	int3
  7f164b:	cc                   	int3
  7f164c:	cc                   	int3
  7f164d:	cc                   	int3
  7f164e:	cc                   	int3
  7f164f:	cc                   	int3
  7f1650:	55                   	push   ebp
  7f1651:	8b ec                	mov    ebp,esp
  7f1653:	56                   	push   esi
  7f1654:	50                   	push   eax
  7f1655:	8b f1                	mov    esi,ecx
  7f1657:	33 c0                	xor    eax,eax
  7f1659:	e8 92 85 ff ff       	call   0x7e9bf0
  7f165e:	d9 05 18 7d c0 00    	fld    DWORD PTR ds:0xc07d18
  7f1664:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7f1667:	c7 86 84 00 00 00 68 	mov    DWORD PTR [esi+0x84],0xc4f468
  7f166e:	f4 c4 00 
  7f1671:	33 c0                	xor    eax,eax
  7f1673:	c7 06 8c 0a c5 00    	mov    DWORD PTR [esi],0xc50a8c
  7f1679:	c7 86 84 00 00 00 bc 	mov    DWORD PTR [esi+0x84],0xc50abc
  7f1680:	0a c5 00 
  7f1683:	89 8e 88 00 00 00    	mov    DWORD PTR [esi+0x88],ecx
  7f1689:	89 86 8c 00 00 00    	mov    DWORD PTR [esi+0x8c],eax
  7f168f:	89 86 90 00 00 00    	mov    DWORD PTR [esi+0x90],eax
  7f1695:	89 86 94 00 00 00    	mov    DWORD PTR [esi+0x94],eax
  7f169b:	89 86 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],eax
  7f16a1:	89 86 a0 00 00 00    	mov    DWORD PTR [esi+0xa0],eax
  7f16a7:	89 86 a4 00 00 00    	mov    DWORD PTR [esi+0xa4],eax
  7f16ad:	d9 9e b0 00 00 00    	fstp   DWORD PTR [esi+0xb0]
  7f16b3:	89 86 ac 00 00 00    	mov    DWORD PTR [esi+0xac],eax
  7f16b9:	c7 46 04 01 00 00 00 	mov    DWORD PTR [esi+0x4],0x1
  7f16c0:	8b c6                	mov    eax,esi
  7f16c2:	5e                   	pop    esi
  7f16c3:	5d                   	pop    ebp
  7f16c4:	c2                   	.byte 0xc2
```

### Provider 複製與關聯物件複製 (`0x007F21A0–0x007F2320`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f21a0 <.text+0x3f11a0>:
  7f21a0:	55                   	push   ebp
  7f21a1:	8b ec                	mov    ebp,esp
  7f21a3:	83 e4 f8             	and    esp,0xfffffff8
  7f21a6:	6a ff                	push   0xffffffff
  7f21a8:	68 d3 9b 90 00       	push   0x909bd3
  7f21ad:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7f21b3:	50                   	push   eax
  7f21b4:	83 ec 30             	sub    esp,0x30
  7f21b7:	53                   	push   ebx
  7f21b8:	56                   	push   esi
  7f21b9:	57                   	push   edi
  7f21ba:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7f21bf:	33 c4                	xor    eax,esp
  7f21c1:	50                   	push   eax
  7f21c2:	8d 44 24 40          	lea    eax,[esp+0x40]
  7f21c6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7f21cc:	8b f9                	mov    edi,ecx
  7f21ce:	68 b4 00 00 00       	push   0xb4
  7f21d3:	e8 90 f0 09 00       	call   0x891268
  7f21d8:	8b c8                	mov    ecx,eax
  7f21da:	83 c4 04             	add    esp,0x4
  7f21dd:	89 4c 24 28          	mov    DWORD PTR [esp+0x28],ecx
  7f21e1:	33 db                	xor    ebx,ebx
  7f21e3:	89 5c 24 48          	mov    DWORD PTR [esp+0x48],ebx
  7f21e7:	3b cb                	cmp    ecx,ebx
  7f21e9:	74 12                	je     0x7f21fd
  7f21eb:	6a 01                	push   0x1
  7f21ed:	8d 47 30             	lea    eax,[edi+0x30]
  7f21f0:	e8 bb f3 ff ff       	call   0x7f15b0
  7f21f5:	8b f0                	mov    esi,eax
  7f21f7:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  7f21fb:	eb 06                	jmp    0x7f2203
  7f21fd:	89 5c 24 10          	mov    DWORD PTR [esp+0x10],ebx
  7f2201:	8b f3                	mov    esi,ebx
  7f2203:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  7f220a:	ff 
  7f220b:	d9 47 70             	fld    DWORD PTR [edi+0x70]
  7f220e:	d9 5e 70             	fstp   DWORD PTR [esi+0x70]
  7f2211:	d9 87 b0 00 00 00    	fld    DWORD PTR [edi+0xb0]
  7f2217:	d9 9e b0 00 00 00    	fstp   DWORD PTR [esi+0xb0]
  7f221d:	8b 87 ac 00 00 00    	mov    eax,DWORD PTR [edi+0xac]
  7f2223:	89 86 ac 00 00 00    	mov    DWORD PTR [esi+0xac],eax
  7f2229:	39 9f 88 00 00 00    	cmp    DWORD PTR [edi+0x88],ebx
  7f222f:	0f 84 d5 00 00 00    	je     0x7f230a
  7f2235:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  7f223b:	8b 11                	mov    edx,DWORD PTR [ecx]
  7f223d:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  7f2240:	ff d0                	call   eax
  7f2242:	89 86 88 00 00 00    	mov    DWORD PTR [esi+0x88],eax
  7f2248:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  7f224c:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  7f2250:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  7f2254:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  7f2258:	51                   	push   ecx
  7f2259:	50                   	push   eax
  7f225a:	c7 44 24 50 01 00 00 	mov    DWORD PTR [esp+0x50],0x1
  7f2261:	00 
  7f2262:	e8 69 5b fd ff       	call   0x7c7dd0
  7f2267:	8b 54 24 38          	mov    edx,DWORD PTR [esp+0x38]
  7f226b:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  7f226f:	2b d0                	sub    edx,eax
  7f2271:	c1 fa 02             	sar    edx,0x2
  7f2274:	83 c4 08             	add    esp,0x8
  7f2277:	85 d2                	test   edx,edx
  7f2279:	74 62                	je     0x7f22dd
  7f227b:	d9 05 f0 5a c5 00    	fld    DWORD PTR ds:0xc55af0
  7f2281:	d9 54 24 14          	fst    DWORD PTR [esp+0x14]
  7f2285:	d9 54 24 18          	fst    DWORD PTR [esp+0x18]
  7f2289:	d9 54 24 1c          	fst    DWORD PTR [esp+0x1c]
  7f228d:	d9 54 24 20          	fst    DWORD PTR [esp+0x20]
  7f2291:	d9 54 24 24          	fst    DWORD PTR [esp+0x24]
  7f2295:	d9 5c 24 28          	fstp   DWORD PTR [esp+0x28]
  7f2299:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  7f22a0:	8b 14 98             	mov    edx,DWORD PTR [eax+ebx*4]
  7f22a3:	8d 7c 24 14          	lea    edi,[esp+0x14]
  7f22a7:	8d 74 24 18          	lea    esi,[esp+0x18]
  7f22ab:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  7f22af:	e8 1c 2f 06 00       	call   0x8551d0
  7f22b4:	8d 7c 24 20          	lea    edi,[esp+0x20]
  7f22b8:	8d 74 24 24          	lea    esi,[esp+0x24]
  7f22bc:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  7f22c0:	e8 4b 2e 06 00       	call   0x855110
  7f22c5:	8b 4c 24 30          	mov    ecx,DWORD PTR [esp+0x30]
  7f22c9:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  7f22cd:	2b c8                	sub    ecx,eax
  7f22cf:	43                   	inc    ebx
  7f22d0:	c1 f9 02             	sar    ecx,0x2
  7f22d3:	3b d9                	cmp    ebx,ecx
  7f22d5:	72 c9                	jb     0x7f22a0
  7f22d7:	8b 74 24 10          	mov    esi,DWORD PTR [esp+0x10]
  7f22db:	33 db                	xor    ebx,ebx
  7f22dd:	56                   	push   esi
  7f22de:	e8 cd fb ff ff       	call   0x7f1eb0
  7f22e3:	8b 86 88 00 00 00    	mov    eax,DWORD PTR [esi+0x88]
  7f22e9:	8d 96 9c 00 00 00    	lea    edx,[esi+0x9c]
  7f22ef:	52                   	push   edx
  7f22f0:	50                   	push   eax
  7f22f1:	e8 0a 98 fd ff       	call   0x7cbb00
  7f22f6:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  7f22fa:	83 c4 08             	add    esp,0x8
  7f22fd:	3b c3                	cmp    eax,ebx
  7f22ff:	74 09                	je     0x7f230a
  7f2301:	50                   	push   eax
  7f2302:	e8 05 ef 09 00       	call   0x89120c
  7f2307:	83 c4 04             	add    esp,0x4
  7f230a:	8b c6                	mov    eax,esi
  7f230c:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  7f2310:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f2317:	59                   	pop    ecx
  7f2318:	5f                   	pop    edi
  7f2319:	5e                   	pop    esi
  7f231a:	5b                   	pop    ebx
  7f231b:	8b e5                	mov    esp,ebp
  7f231d:	5d                   	pop    ebp
  7f231e:	c3                   	ret
  7f231f:	cc                   	int3
```

### 更新/條件觸發 (`0x007F2320–0x007F23B0`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f2320 <.text+0x3f1320>:
  7f2320:	55                   	push   ebp
  7f2321:	8b ec                	mov    ebp,esp
  7f2323:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  7f2326:	56                   	push   esi
  7f2327:	8b f1                	mov    esi,ecx
  7f2329:	d9 46 70             	fld    DWORD PTR [esi+0x70]
  7f232c:	d8 d9                	fcomp  st(1)
  7f232e:	df e0                	fnstsw ax
  7f2330:	f6 c4 05             	test   ah,0x5
  7f2333:	7b 64                	jnp    0x7f2399
  7f2335:	d9 ee                	fldz
  7f2337:	de d9                	fcompp
  7f2339:	df e0                	fnstsw ax
  7f233b:	f6 c4 41             	test   ah,0x41
  7f233e:	74 5b                	je     0x7f239b
  7f2340:	8b 4e 74             	mov    ecx,DWORD PTR [esi+0x74]
  7f2343:	53                   	push   ebx
  7f2344:	57                   	push   edi
  7f2345:	8b be 88 00 00 00    	mov    edi,DWORD PTR [esi+0x88]
  7f234b:	8d 47 68             	lea    eax,[edi+0x68]
  7f234e:	c7 46 7c 01 00 00 00 	mov    DWORD PTR [esi+0x7c],0x1
  7f2355:	e8 a6 c6 f8 ff       	call   0x77ea00
  7f235a:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  7f235d:	dc 0d c8 56 c5 00    	fmul   QWORD PTR ds:0xc556c8
  7f2363:	c7 87 c0 00 00 00 00 	mov    DWORD PTR [edi+0xc0],0x0
  7f236a:	00 00 00 
  7f236d:	8b be 88 00 00 00    	mov    edi,DWORD PTR [esi+0x88]
  7f2373:	8b 1f                	mov    ebx,DWORD PTR [edi]
  7f2375:	e8 96 c9 10 00       	call   0x8fed10
  7f237a:	50                   	push   eax
  7f237b:	8b 43 1c             	mov    eax,DWORD PTR [ebx+0x1c]
  7f237e:	8b cf                	mov    ecx,edi
  7f2380:	ff d0                	call   eax
  7f2382:	8b b6 88 00 00 00    	mov    esi,DWORD PTR [esi+0x88]
  7f2388:	8b 4e 30             	mov    ecx,DWORD PTR [esi+0x30]
  7f238b:	51                   	push   ecx
  7f238c:	56                   	push   esi
  7f238d:	e8 be dd f8 ff       	call   0x780150
  7f2392:	5f                   	pop    edi
  7f2393:	5b                   	pop    ebx
  7f2394:	5e                   	pop    esi
  7f2395:	5d                   	pop    ebp
  7f2396:	c2 08 00             	ret    0x8
  7f2399:	dd d8                	fstp   st(0)
  7f239b:	c7 46 7c 00 00 00 00 	mov    DWORD PTR [esi+0x7c],0x0
  7f23a2:	5e                   	pop    esi
  7f23a3:	5d                   	pop    ebp
  7f23a4:	c2 08 00             	ret    0x8
  7f23a7:	cc                   	int3
  7f23a8:	cc                   	int3
  7f23a9:	cc                   	int3
  7f23aa:	cc                   	int3
  7f23ab:	cc                   	int3
  7f23ac:	cc                   	int3
  7f23ad:	cc                   	int3
  7f23ae:	cc                   	int3
  7f23af:	cc                   	int3
```

### Binding 觸發、旗標與計算比較 (`0x007F23B0–0x007F2510`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f23b0 <.text+0x3f13b0>:
  7f23b0:	55                   	push   ebp
  7f23b1:	8b ec                	mov    ebp,esp
  7f23b3:	6a ff                	push   0xffffffff
  7f23b5:	68 ae b9 92 00       	push   0x92b9ae
  7f23ba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7f23c0:	50                   	push   eax
  7f23c1:	83 ec 0c             	sub    esp,0xc
  7f23c4:	53                   	push   ebx
  7f23c5:	56                   	push   esi
  7f23c6:	57                   	push   edi
  7f23c7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7f23cc:	33 c5                	xor    eax,ebp
  7f23ce:	50                   	push   eax
  7f23cf:	8d 45 f4             	lea    eax,[ebp-0xc]
  7f23d2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7f23d8:	8b f1                	mov    esi,ecx
  7f23da:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  7f23dd:	83 7e 7c 00          	cmp    DWORD PTR [esi+0x7c],0x0
  7f23e1:	0f 84 f7 00 00 00    	je     0x7f24de
  7f23e7:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7f23ee:	75 27                	jne    0x7f2417
  7f23f0:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  7f23f7:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7f23fe:	e8 dd 69 fa ff       	call   0x798de0
  7f2403:	68 e0 d2 bc 00       	push   0xbcd2e0
  7f2408:	e8 0d ff 09 00       	call   0x89231a
  7f240d:	83 c4 04             	add    esp,0x4
  7f2410:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  7f2417:	8b 86 90 00 00 00    	mov    eax,DWORD PTR [esi+0x90]
  7f241d:	8b 9e 8c 00 00 00    	mov    ebx,DWORD PTR [esi+0x8c]
  7f2423:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  7f2426:	3b d8                	cmp    ebx,eax
  7f2428:	74 7b                	je     0x7f24a5
  7f242a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7f2430:	8b 33                	mov    esi,DWORD PTR [ebx]
  7f2432:	8b 7b 04             	mov    edi,DWORD PTR [ebx+0x4]
  7f2435:	c1 e6 04             	shl    esi,0x4
  7f2438:	81 c6 74 77 fb 00    	add    esi,0xfb7774
  7f243e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7f2441:	8d 4d f0             	lea    ecx,[ebp-0x10]
  7f2444:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
  7f2447:	3b c8                	cmp    ecx,eax
  7f2449:	73 31                	jae    0x7f247c
  7f244b:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7f244d:	8d 55 f0             	lea    edx,[ebp-0x10]
  7f2450:	3b ca                	cmp    ecx,edx
  7f2452:	77 28                	ja     0x7f247c
  7f2454:	8b fa                	mov    edi,edx
  7f2456:	2b f9                	sub    edi,ecx
  7f2458:	c1 ff 02             	sar    edi,0x2
  7f245b:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  7f245e:	75 0c                	jne    0x7f246c
  7f2460:	b9 01 00 00 00       	mov    ecx,0x1
  7f2465:	8b c6                	mov    eax,esi
  7f2467:	e8 a4 9a fa ff       	call   0x79bf10
  7f246c:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7f246f:	85 c0                	test   eax,eax
  7f2471:	74 23                	je     0x7f2496
  7f2473:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7f2475:	8b 14 b9             	mov    edx,DWORD PTR [ecx+edi*4]
  7f2478:	89 10                	mov    DWORD PTR [eax],edx
  7f247a:	eb 1a                	jmp    0x7f2496
  7f247c:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  7f247f:	75 0c                	jne    0x7f248d
  7f2481:	b9 01 00 00 00       	mov    ecx,0x1
  7f2486:	8b c6                	mov    eax,esi
  7f2488:	e8 83 9a fa ff       	call   0x79bf10
  7f248d:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  7f2490:	85 c0                	test   eax,eax
  7f2492:	74 02                	je     0x7f2496
  7f2494:	89 38                	mov    DWORD PTR [eax],edi
  7f2496:	83 46 04 04          	add    DWORD PTR [esi+0x4],0x4
  7f249a:	83 c3 08             	add    ebx,0x8
  7f249d:	3b 5d ec             	cmp    ebx,DWORD PTR [ebp-0x14]
  7f24a0:	75 8e                	jne    0x7f2430
  7f24a2:	8b 75 e8             	mov    esi,DWORD PTR [ebp-0x18]
  7f24a5:	8b 86 84 00 00 00    	mov    eax,DWORD PTR [esi+0x84]
  7f24ab:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7f24ae:	8b 3d 40 77 fb 00    	mov    edi,DWORD PTR ds:0xfb7740
  7f24b4:	81 c6 84 00 00 00    	add    esi,0x84
  7f24ba:	8b ce                	mov    ecx,esi
  7f24bc:	ff d2                	call   edx
  7f24be:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  7f24c4:	8b 8c 38 00 20 00 00 	mov    ecx,DWORD PTR [eax+edi*1+0x2000]
  7f24cb:	03 c7                	add    eax,edi
  7f24cd:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7f24d3:	7d 09                	jge    0x7f24de
  7f24d5:	89 34 88             	mov    DWORD PTR [eax+ecx*4],esi
  7f24d8:	ff 80 00 20 00 00    	inc    DWORD PTR [eax+0x2000]
  7f24de:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f24e1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f24e8:	59                   	pop    ecx
  7f24e9:	5f                   	pop    edi
  7f24ea:	5e                   	pop    esi
  7f24eb:	5b                   	pop    ebx
  7f24ec:	8b e5                	mov    esp,ebp
  7f24ee:	5d                   	pop    ebp
  7f24ef:	c3                   	ret
  7f24f0:	55                   	push   ebp
  7f24f1:	8b ec                	mov    ebp,esp
  7f24f3:	d9 45 08             	fld    DWORD PTR [ebp+0x8]
  7f24f6:	d9 41 70             	fld    DWORD PTR [ecx+0x70]
  7f24f9:	de d9                	fcompp
  7f24fb:	df e0                	fnstsw ax
  7f24fd:	f6 c4 05             	test   ah,0x5
  7f2500:	7a 09                	jp     0x7f250b
  7f2502:	b8 01 00 00 00       	mov    eax,0x1
  7f2507:	5d                   	pop    ebp
  7f2508:	c2 04 00             	ret    0x4
  7f250b:	33 c0                	xor    eax,eax
  7f250d:	5d                   	pop    ebp
  7f250e:	c2                   	.byte 0xc2
  7f250f:	04                   	.byte 0x4
```

### +0x80 寫入者與 secondary thunk (`0x007F2520–0x007F2610`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f2520 <.text+0x3f1520>:
  7f2520:	55                   	push   ebp
  7f2521:	8b ec                	mov    ebp,esp
  7f2523:	6a ff                	push   0xffffffff
  7f2525:	68 3e 27 93 00       	push   0x93273e
  7f252a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7f2530:	50                   	push   eax
  7f2531:	83 ec 0c             	sub    esp,0xc
  7f2534:	56                   	push   esi
  7f2535:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7f253a:	33 c5                	xor    eax,ebp
  7f253c:	50                   	push   eax
  7f253d:	8d 45 f4             	lea    eax,[ebp-0xc]
  7f2540:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7f2546:	8b f1                	mov    esi,ecx
  7f2548:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7f254f:	8b 86 88 00 00 00    	mov    eax,DWORD PTR [esi+0x88]
  7f2555:	8b 48 68             	mov    ecx,DWORD PTR [eax+0x68]
  7f2558:	8b 50 6c             	mov    edx,DWORD PTR [eax+0x6c]
  7f255b:	8b 40 70             	mov    eax,DWORD PTR [eax+0x70]
  7f255e:	89 4d e8             	mov    DWORD PTR [ebp-0x18],ecx
  7f2561:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  7f2564:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  7f2567:	75 20                	jne    0x7f2589
  7f2569:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  7f2570:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7f2577:	e8 64 68 fa ff       	call   0x798de0
  7f257c:	68 e0 d2 bc 00       	push   0xbcd2e0
  7f2581:	e8 94 fd 09 00       	call   0x89231a
  7f2586:	83 c4 04             	add    esp,0x4
  7f2589:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  7f2590:	75 07                	jne    0x7f2599
  7f2592:	b8 01 00 00 00       	mov    eax,0x1
  7f2597:	eb 2c                	jmp    0x7f25c5
  7f2599:	d9 86 b0 00 00 00    	fld    DWORD PTR [esi+0xb0]
  7f259f:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  7f25a5:	83 ec 10             	sub    esp,0x10
  7f25a8:	d9 5c 24 0c          	fstp   DWORD PTR [esp+0xc]
  7f25ac:	d9 45 f0             	fld    DWORD PTR [ebp-0x10]
  7f25af:	d9 5c 24 08          	fstp   DWORD PTR [esp+0x8]
  7f25b3:	d9 45 ec             	fld    DWORD PTR [ebp-0x14]
  7f25b6:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  7f25ba:	d9 45 e8             	fld    DWORD PTR [ebp-0x18]
  7f25bd:	d9 1c 24             	fstp   DWORD PTR [esp]
  7f25c0:	e8 9b 62 04 00       	call   0x838860
  7f25c5:	33 c9                	xor    ecx,ecx
  7f25c7:	85 c0                	test   eax,eax
  7f25c9:	0f 94 c1             	sete   cl
  7f25cc:	8b c1                	mov    eax,ecx
  7f25ce:	89 86 80 00 00 00    	mov    DWORD PTR [esi+0x80],eax
  7f25d4:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f25d7:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f25de:	59                   	pop    ecx
  7f25df:	5e                   	pop    esi
  7f25e0:	8b e5                	mov    esp,ebp
  7f25e2:	5d                   	pop    ebp
  7f25e3:	c3                   	ret
  7f25e4:	cc                   	int3
  7f25e5:	cc                   	int3
  7f25e6:	cc                   	int3
  7f25e7:	cc                   	int3
  7f25e8:	cc                   	int3
  7f25e9:	cc                   	int3
  7f25ea:	cc                   	int3
  7f25eb:	cc                   	int3
  7f25ec:	cc                   	int3
  7f25ed:	cc                   	int3
  7f25ee:	cc                   	int3
  7f25ef:	cc                   	int3
  7f25f0:	81 e9 84 00 00 00    	sub    ecx,0x84
  7f25f6:	e9 b5 fd ff ff       	jmp    0x7f23b0
  7f25fb:	cc                   	int3
  7f25fc:	cc                   	int3
  7f25fd:	cc                   	int3
  7f25fe:	cc                   	int3
  7f25ff:	cc                   	int3
  7f2600:	81 e9 84 00 00 00    	sub    ecx,0x84
  7f2606:	e9 15 f0 ff ff       	jmp    0x7f1620
  7f260b:	cc                   	int3
  7f260c:	cc                   	int3
  7f260d:	cc                   	int3
  7f260e:	cc                   	int3
  7f260f:	cc                   	int3
```

### 資源對 binding 的調用閘 (`0x007BDF40–0x007BDF90`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007bdf40 <.text+0x3bcf40>:
  7bdf40:	55                   	push   ebp
  7bdf41:	8b ec                	mov    ebp,esp
  7bdf43:	53                   	push   ebx
  7bdf44:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7bdf47:	56                   	push   esi
  7bdf48:	57                   	push   edi
  7bdf49:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7bdf4c:	2b 7b 04             	sub    edi,DWORD PTR [ebx+0x4]
  7bdf4f:	33 f6                	xor    esi,esi
  7bdf51:	c1 ff 02             	sar    edi,0x2
  7bdf54:	85 ff                	test   edi,edi
  7bdf56:	74 31                	je     0x7bdf89
  7bdf58:	eb 06                	jmp    0x7bdf60
  7bdf5a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bdf60:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7bdf63:	8b 04 b0             	mov    eax,DWORD PTR [eax+esi*4]
  7bdf66:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7bdf69:	85 c9                	test   ecx,ecx
  7bdf6b:	74 17                	je     0x7bdf84
  7bdf6d:	80 38 00             	cmp    BYTE PTR [eax],0x0
  7bdf70:	75 12                	jne    0x7bdf84
  7bdf72:	83 b9 80 00 00 00 00 	cmp    DWORD PTR [ecx+0x80],0x0
  7bdf79:	75 09                	jne    0x7bdf84
  7bdf7b:	8b c1                	mov    eax,ecx
  7bdf7d:	8b 10                	mov    edx,DWORD PTR [eax]
  7bdf7f:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  7bdf82:	ff d0                	call   eax
  7bdf84:	46                   	inc    esi
  7bdf85:	3b f7                	cmp    esi,edi
  7bdf87:	72 d7                	jb     0x7bdf60
  7bdf89:	5f                   	pop    edi
  7bdf8a:	5e                   	pop    esi
  7bdf8b:	5b                   	pop    ebx
  7bdf8c:	5d                   	pop    ebp
  7bdf8d:	c2 04 00             	ret    0x4
```

### 次級子物件析構鏈 (`0x007F2730–0x007F27CF`)

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

007f2730 <.text+0x3f1730>:
  7f2730:	55                   	push   ebp
  7f2731:	8b ec                	mov    ebp,esp
  7f2733:	6a ff                	push   0xffffffff
  7f2735:	68 fe 46 90 00       	push   0x9046fe
  7f273a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7f2740:	50                   	push   eax
  7f2741:	51                   	push   ecx
  7f2742:	53                   	push   ebx
  7f2743:	56                   	push   esi
  7f2744:	57                   	push   edi
  7f2745:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  7f274a:	33 c5                	xor    eax,ebp
  7f274c:	50                   	push   eax
  7f274d:	8d 45 f4             	lea    eax,[ebp-0xc]
  7f2750:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7f2756:	8b f1                	mov    esi,ecx
  7f2758:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  7f275b:	c7 06 d0 0a c5 00    	mov    DWORD PTR [esi],0xc50ad0
  7f2761:	33 db                	xor    ebx,ebx
  7f2763:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7f2766:	8b 86 98 00 00 00    	mov    eax,DWORD PTR [esi+0x98]
  7f276c:	2b 86 94 00 00 00    	sub    eax,DWORD PTR [esi+0x94]
  7f2772:	33 ff                	xor    edi,edi
  7f2774:	c1 f8 02             	sar    eax,0x2
  7f2777:	85 c0                	test   eax,eax
  7f2779:	74 40                	je     0x7f27bb
  7f277b:	eb 03                	jmp    0x7f2780
  7f277d:	8d 49 00             	lea    ecx,[ecx+0x0]
  7f2780:	8b 8e 94 00 00 00    	mov    ecx,DWORD PTR [esi+0x94]
  7f2786:	39 1c b9             	cmp    DWORD PTR [ecx+edi*4],ebx
  7f2789:	8d 04 b9             	lea    eax,[ecx+edi*4]
  7f278c:	74 19                	je     0x7f27a7
  7f278e:	8b 00                	mov    eax,DWORD PTR [eax]
  7f2790:	3b c3                	cmp    eax,ebx
  7f2792:	74 0a                	je     0x7f279e
  7f2794:	8b 10                	mov    edx,DWORD PTR [eax]
  7f2796:	8b c8                	mov    ecx,eax
  7f2798:	8b 02                	mov    eax,DWORD PTR [edx]
  7f279a:	6a 01                	push   0x1
  7f279c:	ff d0                	call   eax
  7f279e:	8b 8e 94 00 00 00    	mov    ecx,DWORD PTR [esi+0x94]
  7f27a4:	89 1c b9             	mov    DWORD PTR [ecx+edi*4],ebx
  7f27a7:	8b 96 98 00 00 00    	mov    edx,DWORD PTR [esi+0x98]
  7f27ad:	2b 96 94 00 00 00    	sub    edx,DWORD PTR [esi+0x94]
  7f27b3:	47                   	inc    edi
  7f27b4:	c1 fa 02             	sar    edx,0x2
  7f27b7:	3b fa                	cmp    edi,edx
  7f27b9:	72 c5                	jb     0x7f2780
  7f27bb:	8b 86 94 00 00 00    	mov    eax,DWORD PTR [esi+0x94]
  7f27c1:	3b c3                	cmp    eax,ebx
  7f27c3:	74 09                	je     0x7f27ce
  7f27c5:	50                   	push   eax
  7f27c6:	e8 41 ea 09 00       	call   0x89120c
  7f27cb:	83 c4 04             	add    esp,0x4
  7f27ce:	89                   	.byte 0x89
```