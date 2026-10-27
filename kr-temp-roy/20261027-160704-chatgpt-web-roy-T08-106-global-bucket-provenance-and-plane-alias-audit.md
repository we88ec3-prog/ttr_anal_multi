# T08-106 — 全域分桶來源稽核、內嵌容器區隔與六係數別名追蹤

- 研究日期：2026-10-27 (Asia/Taipei)
- 分析者：chatgpt-web roy
- BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本回合本地 `sha256sum` 實測一致）
- 研究範圍：T08-105 後續，不重跑 001–104；原始機器碼優先，T08-105 兩份本地原稿補充對照。
- 狀態：**部分完成**。已釐清新增容器指標來源、插入計數值與全域引用的角色；尚未找到真正全域 consumer 與六係數的正常更新寫入者。
- GitHub：沒有 Commit 或 Push。檔案可在下次明確授權時一併提交。

## 1. 本輪方法與限制

直接使用已驗證 SHA 的 `Tartaros.bin` 及由其生成的 `t08_disasm.txt`（`objdump` PE32 x86 反組譯）。重新搜尋對 `0x00FB7740`、`0x00FB76B0` 的絕對記憶體引用和乘 `0x2004` 的指令。**直接引用集合不等於完整的別名/間接引用集合**；不能以零個明確 consumer 證明 consumer 不存在。`objdump` 的線性反組譯仍須防止誤認填充位元組與指令邊界。

## 2. 新增確認 A：`0x0079A3C0` 的桶基址來自 `manager+0x98`

```asm
  79a3bd:	5d                   	pop    ebp
  79a3be:	c3                   	ret
  79a3bf:	cc                   	int3
  79a3c0:	56                   	push   esi
  79a3c1:	8b b1 98 00 00 00    	mov    esi,DWORD PTR [ecx+0x98]
  79a3c7:	85 c0                	test   eax,eax
  79a3c9:	75 09                	jne    0x79a3d4
  79a3cb:	8b 17                	mov    edx,DWORD PTR [edi]
  79a3cd:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  79a3d0:	8b cf                	mov    ecx,edi
  79a3d2:	ff d0                	call   eax
  79a3d4:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  79a3da:	8b 8c 30 00 20 00 00 	mov    ecx,DWORD PTR [eax+esi*1+0x2000]
  79a3e1:	03 c6                	add    eax,esi
```

於入口 `0x0079A3C0`：`ESI = [ECX+0x98]`，由 `EDI` 物件的 vtable+4 取得桶索引（若 EAX 原本非0則沿用 EAX），`bucketBase=ESI+index*0x2004`；count 在 `bucketBase+0x2000`，當 count < `0x800`，才以 `entries[count]=EDI`、`count++` 插入。**此函式沒有從全域 `[0x00FB7740]` 取桶位址**。是否管理器初始化時使 `+0x98` 指向該全域陣列仍待查，不能直接斷言兩塊配置永遠不同。

暫定偽碼：

```cpp
void InsertViaManagerBucket(Manager* manager, Entry* entry, int index) {
    auto* base = *(BucketArray**)((char*)manager + 0x98);
    if (index == 0) index = entry->vfunc_04();
    Bucket* bucket = (Bucket*)((char*)base + index * 0x2004);
    if (bucket->count < 2048) {
        bucket->entries[bucket->count] = entry;
        ++bucket->count;
    }
}
```

注意：EAX、EDI 為呼叫約定中的上游輸入，尚未確定完整函式 ABI；偽碼只表示已見資料流，並非已證明可編譯的原始簽名。索引合法範圍是否受呼叫者保證亦未驗證。

## 3. 新增確認 B：`0x007D3470` 全域桶兩條插入路徑的增量確定為1

```asm
  7d3491:	50                   	push   eax
  7d3492:	8d 44 24 30          	lea    eax,[esp+0x30]
  7d3496:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  7d349c:	8b d9                	mov    ebx,ecx
  7d349e:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7d34a5:	bf 01 00 00 00       	mov    edi,0x1
  7d34aa:	75 28                	jne    0x7d34d4
  7d34ac:	09 3d e8 79 fb 00    	or     DWORD PTR ds:0xfb79e8,edi
  7d34b2:	c7 44 24 38 00 00 00 	mov    DWORD PTR [esp+0x38],0x0
  7d34b9:	00 
  7d34ba:	e8 21 59 fc ff       	call   0x798de0
  7d34bf:	68 e0 d2 bc 00       	push   0xbcd2e0
  7d34c4:	e8 51 ee 0b 00       	call   0x89231a
  7d34c9:	83 c4 04             	add    esp,0x4
  7d34cc:	c7 44 24 38 ff ff ff 	mov    DWORD PTR [esp+0x38],0xffffffff
  7d34d3:	ff 
  7d34d4:	d9 43 5c             	fld    DWORD PTR [ebx+0x5c]
  7d34d7:	dc 1d 20 58 c5 00    	fcomp  QWORD PTR ds:0xc55820
  7d34dd:	df e0                	fnstsw ax
  7d34df:	f6 c4 05             	test   ah,0x5
  7d34e2:	0f 8a 86 00 00 00    	jp     0x7d356e
  7d34e8:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7d34eb:	8b 35 40 77 fb 00    	mov    esi,DWORD PTR ds:0xfb7740
  7d34f1:	85 c0                	test   eax,eax
  7d34f3:	75 09                	jne    0x7d34fe
  7d34f5:	8b 03                	mov    eax,DWORD PTR [ebx]
  7d34f7:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  7d34fa:	8b cb                	mov    ecx,ebx
  7d34fc:	ff d2                	call   edx
  7d34fe:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  7d3504:	8b 8c 30 00 20 00 00 	mov    ecx,DWORD PTR [eax+esi*1+0x2000]
  7d350b:	03 c6                	add    eax,esi
  7d350d:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7d3513:	7d 09                	jge    0x7d351e
  7d3515:	89 1c 88             	mov    DWORD PTR [eax+ecx*4],ebx
  7d3518:	01 b8 00 20 00 00    	add    DWORD PTR [eax+0x2000],edi
  7d351e:	a1 90 79 fb 00       	mov    eax,ds:0xfb7990
  7d3523:	83 e8 00             	sub    eax,0x0
  7d3526:	0f 84 cb 00 00 00    	je     0x7d35f7
  7d352c:	2b c7                	sub    eax,edi
  7d352e:	0f 85 d2 00 00 00    	jne    0x7d3606
  7d3534:	8b 43 28             	mov    eax,DWORD PTR [ebx+0x28]
  7d3537:	8b 4b 2c             	mov    ecx,DWORD PTR [ebx+0x2c]
  7d353a:	8b 53 30             	mov    edx,DWORD PTR [ebx+0x30]
  7d353d:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  7d3541:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  7d3545:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  7d3549:	b8 a8 76 fb 00       	mov    eax,0xfb76a8
  7d354e:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  7d3552:	e8 29 87 fc ff       	call   0x79bc80
  7d3557:	8b fb                	mov    edi,ebx
  7d3559:	b9 a8 76 fb 00       	mov    ecx,0xfb76a8
  7d355e:	85 c0                	test   eax,eax
  7d3560:	0f 85 98 00 00 00    	jne    0x7d35fe
  7d3566:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  7d3569:	e9 93 00 00 00       	jmp    0x7d3601
  7d356e:	8b 43 74             	mov    eax,DWORD PTR [ebx+0x74]
  7d3571:	83 78 18 00          	cmp    DWORD PTR [eax+0x18],0x0
  7d3575:	74 36                	je     0x7d35ad
  7d3577:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  7d357a:	8b 35 40 77 fb 00    	mov    esi,DWORD PTR ds:0xfb7740
  7d3580:	85 c0                	test   eax,eax
  7d3582:	75 09                	jne    0x7d358d
  7d3584:	8b 13                	mov    edx,DWORD PTR [ebx]
  7d3586:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7d3589:	8b cb                	mov    ecx,ebx
  7d358b:	ff d0                	call   eax
  7d358d:	69 c0 04 20 00 00    	imul   eax,eax,0x2004
  7d3593:	8b 8c 30 00 20 00 00 	mov    ecx,DWORD PTR [eax+esi*1+0x2000]
  7d359a:	03 c6                	add    eax,esi
  7d359c:	81 f9 00 08 00 00    	cmp    ecx,0x800
  7d35a2:	7d 09                	jge    0x7d35ad
  7d35a4:	89 1c 88             	mov    DWORD PTR [eax+ecx*4],ebx
  7d35a7:	01 b8 00 20 00 00    	add    DWORD PTR [eax+0x2000],edi
  7d35ad:	8b 4b 74             	mov    ecx,DWORD PTR [ebx+0x74]
  7d35b0:	83 79 14 00          	cmp    DWORD PTR [ecx+0x14],0x0
```

`0x007D34A5: mov edi,0x1` 先設定 `EDI=1`，沿 `0x007D34EB` 桶插入分支至 `0x007D3518` 使用 `add [bucket+0x2000],edi`，所以**此分支 count+=1**。另一條 `0x007D357A`→`0x007D35A7` 也對相同全域桶加 `EDI`，但在該條路徑上需注意 intervening calls 是否保留 EDI；x86 常用呼叫約定通常將 EDI 視為 callee-saved，局部指令亦未觀察到其被直接覆寫。此函式的第二條路徑因而可強力支持相同加1，但嚴格 ABI 仍待對非標準被呼叫程式確認。

另外在 `0x007F24AE`，先讀取 `object+0x84` 當成次級 vptr，將 `ESI` 加 `0x84` 再通過次級 vtable+4 取得桶 index；插入的 entry 是 **object+0x84 子物件位址** 而非完整 Provider 物件起點。這是多型插入時不能混淆指標型別的額外證據。

## 4. 新增確認 C：全域桶直接引用為註冊/插入與生命週期操作

對 `0x00FB7740` 的文字機器碼直接引用包括：

- 配置/設值：`0x00798F78`；配置大小 `0x2C058 = 22 * 0x2004`，`0x00798F5B` 起初始化每桶 count。
- 釋放/清空指標：`0x007995A6` 與 `0x007995BA`。
- 直接讀指標供插入：`0x0079CDA8`、`0x007BED5B`、`0x007CD7C9`、`0x007D34EB`、`0x007D357A`、`0x007DC369`、`0x007DF5A7`、`0x007E6A52`、`0x007F24AE`、`0x007F96ED`、`0x007FEC92`、`0x007FECE9`。

這份清單從 `t08_disasm.txt` 的**絕對地址文本引用**編列；各讀取點經局部組語核對用於插入（通常 `entries[count] = object; ++count`），未見以此地址來源執行 `entry vtable+0x0C` 消費迴圈。間接指標別名/結構持有/傳遞沒有因此排除。

`0x007F24AE` 與 `0x007DC369`、`0x007DF5A7` 是本段檢視的重要登記證據；他們並不構成 consumer。

## 5. 原本被誤認 consumer 的內嵌桶：物件基址來自 EBX，不是全域

```asm
  7d16fd:	8d 83 4c 60 02 00    	lea    eax,[ebx+0x2604c]
  7d1703:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  7d1707:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d170b:	83 fa 16             	cmp    edx,0x16
  7d170e:	73 37                	jae    0x7d1747
  7d1710:	33 ff                	xor    edi,edi
  7d1712:	39 b8 00 20 00 00    	cmp    DWORD PTR [eax+0x2000],edi
  7d1718:	7e 23                	jle    0x7d173d
  7d171a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7d1720:	8b 0c b8             	mov    ecx,DWORD PTR [eax+edi*4]
  7d1723:	8b 01                	mov    eax,DWORD PTR [ecx]
  7d1725:	52                   	push   edx
  7d1726:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  7d1729:	56                   	push   esi
  7d172a:	ff d2                	call   edx
  7d172c:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  7d1730:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  7d1734:	47                   	inc    edi
  7d1735:	3b b8 00 20 00 00    	cmp    edi,DWORD PTR [eax+0x2000]
  7d173b:	7c e3                	jl     0x7d1720
  7d173d:	c7 80 00 20 00 00 00 	mov    DWORD PTR [eax+0x2000],0x0
  7d1744:	00 00 00 
  7d1747:	42                   	inc    edx
  7d1748:	05 04 20 00 00       	add    eax,0x2004
  7d174d:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  7d1751:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  7d1755:	83 fa 16             	cmp    edx,0x16
  7d1758:	7c b4                	jl     0x7d170e
  7d175a:	8b 16                	mov    edx,DWORD PTR [esi]
  7d175c:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  7d175f:	6a 01                	push   0x1
  7d1761:	6a 01                	push   0x1
  7d1763:	6a 01                	push   0x1
  7d1765:	8b ce                	mov    ecx,esi
  7d1767:	ff d0                	call   eax
  7d1769:	81 c3 00 20 00 00    	add    ebx,0x2000
  7d176f:	b8 16 00 00 00       	mov    eax,0x16
  7d1774:	eb 0a                	jmp    0x7d1780
  7d1776:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  7d177d:	8d 49 00             	lea    ecx,[ecx+0x0]
  7d1780:	c7 03 00 00 00 00    	mov    DWORD PTR [ebx],0x0
  7d1786:	81 c3 04 20 00 00    	add    ebx,0x2004
  7d178c:	48                   	dec    eax
```

`0x007D170B` 的桶指標 `EAX = EBX+0x2604C`，從 `entry = [EAX+EDI*4]` 消費，執行 `entry->vfunc_0C(...)` 後清 bucket count。`0x007D1769` 再將 `EBX` 加 `0x2000`，每 `0x2004` 步距將22個 count 置零。由此只能確認這是某管理器的**內嵌桶**，不能假設它使用 `[0x00FB7740]` 全域配置。兩套桶可能使用相同的 `0x2004` 結構但來源不同。

## 6. 六個四浮點係數：重新驗證初始化與直接引用角色

```asm
  798e34:	eb 04                	jmp    0x798e3a
  798e36:	dd d8                	fstp   st(0)
  798e38:	33 c0                	xor    eax,eax
  798e3a:	6a 60                	push   0x60
  798e3c:	a3 ac 76 fb 00       	mov    ds:0xfb76ac,eax
  798e41:	e8 22 84 0f 00       	call   0x891268
  798e46:	83 c4 04             	add    esp,0x4
  798e49:	3b c3                	cmp    eax,ebx
  798e4b:	74 4b                	je     0x798e98
  798e4d:	d9 ee                	fldz
  798e4f:	d9 10                	fst    DWORD PTR [eax]
  798e51:	d9 50 04             	fst    DWORD PTR [eax+0x4]
  798e54:	d9 50 08             	fst    DWORD PTR [eax+0x8]
  798e57:	d9 50 0c             	fst    DWORD PTR [eax+0xc]
  798e5a:	d9 50 10             	fst    DWORD PTR [eax+0x10]
  798e5d:	d9 50 14             	fst    DWORD PTR [eax+0x14]
  798e60:	d9 50 18             	fst    DWORD PTR [eax+0x18]
  798e63:	d9 50 1c             	fst    DWORD PTR [eax+0x1c]
  798e66:	d9 50 20             	fst    DWORD PTR [eax+0x20]
  798e69:	d9 50 24             	fst    DWORD PTR [eax+0x24]
  798e6c:	d9 50 28             	fst    DWORD PTR [eax+0x28]
  798e6f:	d9 50 2c             	fst    DWORD PTR [eax+0x2c]
  798e72:	d9 50 30             	fst    DWORD PTR [eax+0x30]
  798e75:	d9 50 34             	fst    DWORD PTR [eax+0x34]
  798e78:	d9 50 38             	fst    DWORD PTR [eax+0x38]
  798e7b:	d9 50 3c             	fst    DWORD PTR [eax+0x3c]
  798e7e:	d9 50 40             	fst    DWORD PTR [eax+0x40]
  798e81:	d9 50 44             	fst    DWORD PTR [eax+0x44]
  798e84:	d9 50 48             	fst    DWORD PTR [eax+0x48]
  798e87:	d9 50 4c             	fst    DWORD PTR [eax+0x4c]
  798e8a:	d9 50 50             	fst    DWORD PTR [eax+0x50]
  798e8d:	d9 50 54             	fst    DWORD PTR [eax+0x54]
  798e90:	d9 50 58             	fst    DWORD PTR [eax+0x58]
  798e93:	d9 58 5c             	fstp   DWORD PTR [eax+0x5c]
  798e96:	eb 02                	jmp    0x798e9a
  798e98:	33 c0                	xor    eax,eax
  798e9a:	6a 30                	push   0x30
  798e9c:	a3 b0 76 fb 00       	mov    ds:0xfb76b0,eax
  798ea1:	89 1d b4 76 fb 00    	mov    DWORD PTR ds:0xfb76b4,ebx
  798ea7:	89 1d b8 76 fb 00    	mov    DWORD PTR ds:0xfb76b8,ebx
```

`0x00798E3A` 配置 `0x60`，`0x00798E4D～0x00798E93` 使用 `fldz/fst/fstp` 把整整24個 float 初始化為0，於 `0x00798E9C` 將返回值儲存到 `[0x00FB76B0]`。這是**唯一已經定位到的緩衝內容明確寫入**（初始化）；不能從此推論更新時的實值全為0。

`[0x00FB76AC]` 另行指向 `0x10` bytes、四個 float 為 `(0,0,0,1)` 的配置；這與六平面係數有相鄰性，但**沒有證據**證明是平面計算來源矩陣。後續應分析參數傳遞及可能的 SIMD/x87 store 與複製路徑，而不是直接宣稱它是相機矩陣。

測試函式 `0x00838800` / `0x00838860` 的比較計算見 T08-105 延伸筆記，不在本段重複證據；四參數與三參數變體的語義區別依然成立。

## 7. 訊息協作與暫定模型

```cpp
struct Bucket { void* entries[2048]; int32_t count; }; // sizeof = 0x2004
struct GlobalBucketStorage { Bucket buckets[22]; }; // sizeof = 0x2C058
// Global: Bucket* g_bucketArray = *(Bucket**)0x00FB7740;
// Manager: Bucket* embeddedOrReferenced = *(Bucket**)(manager + 0x98);
// 上述兩者是否別名未知，不能直接合併。
```

### 已確認

- BIN 雜湊符合；上述逐指令地址與參照可直接驗證。
- 全域22桶配置與直接插入路徑。
- `0x0079A3C0` 從 manager+0x98 取桶，而不是取全域地址。
- `0x007D3470` 至少第一條路徑 `EDI=1` 因而增量是1；第二條也強烈支持。
- `0x007F24AE` 插入的 entry 指向擁有次級 vptr 的子物件偏移 `+0x84`。
- 係數配置初始化24浮點為0；更新寫入者仍未定位。

### 合理推測但未驗證

- 管理器 `+0x98` 可能持有另一份22桶，也可能別名全域桶，須由實際初始化寫入者決定。
- 六組4浮點可用於幾何平面排除，具體是否相機視錐仍未知。

### 尚待驗證 / T08-107 建議

1. 鎖定所有對 `manager+0x98` 的賦值、`0x0079A3C0` 的呼叫者與 manager 配置大小，建立它和 `0x007D17xx` 內嵌 consumer 的真實關係。
2. 從全域桶的初始化與全部直接插入點反查**是否有全域桶 base 的別名賦值**，搭配 `entry vtable+0x0C` 或桶 count 清零者交叉驗證。不能由相同偏移推定同一物件。
3. 查詢六係數 `0x60` 緩衝指標的寄存器/堆疊傳遞、複製呼叫以及非絕對址 `fstp/movss/movaps` 的間接寫入；建立確切 writer 以前不命名為相機視錐。
4. 若能確定 consumer 的實際持有者與時序，再尋求到 `0x00C07554+0x20` 場景物件更新方法的呼叫鏈。

## 8. GitHub 狀態

本段技術原稿僅存於本地，**未 Commit/Push**；T08-105 初稿與延伸稿也仍為可下載未提交筆記。沒有覆寫其他 Agent 文件，也未修改 BIN/EXE。