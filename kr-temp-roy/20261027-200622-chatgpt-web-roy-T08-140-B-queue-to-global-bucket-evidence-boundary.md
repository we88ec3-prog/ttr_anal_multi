# T08-140 — B queue 與全域22桶因果界限、可執行驗證計畫

## 來源、方法、證據界限

- 實測檔案：`Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 使用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000` 線性掃描此 BIN；局部函式地址、`call rel32` 等直接從原始機器碼核對。`0x00C4FC8C` vtable 依 PE `.rdata` 對應 `VA 0xBD2000 -> raw 0x007D0600` 讀取。
- 已確認僅代表看到的指令與可閉合的靜態資料流；沒有執行遊戲、觀測動態參數或驗證機率/距離等業務語義。全檔線性反組譯會產生資料誤反組譯，不能把字串搜尋零結果當成完整無寫入證明。
- 本段為 T08-136 後接續新分析，無已知授權修改其他 Task。

## 核心研究問題與結論

經 T08-137～139 新的原始 BIN 驗證，**目前仍無證據證明 B queue 的具體 entry 類型，或其 `vtable+0x04` 最終會 append 至全域 22 桶**；但完整確認了各資料結構和控制順序。這是目前可驗證證據的結論，不代表技術上已排除任何實際資料依賴。

### 已確認的控制鏈

```text
[0x00FBA838] -> 0x10C-byte global manager
  +0xA4: A vector (已找到 append)
  +0xB4: B vector (未找到真正 append)
  +0xC4: max_selected = 4 (建構預設)

0x0079A320 (manager-phase dispatcher)
  -> 0x007BB640 (B sort + top N virtual +4 + logical clear)
  -> callback+0x0C = 0x007D1310 (全域22桶 consumer)

另一路：0x007BAC79 -> 0x007BB640

在 B 中：element vfptr+0x08 -> x87 score；+0x04 -> execute
```

### 精確控制指令摘錄

```asm
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
  7bb705:	8b 8e b8 00 00 00    	mov    ecx,DWORD PTR [esi+0xb8]
  7bb70b:	8b be b4 00 00 00    	mov    edi,DWORD PTR [esi+0xb4]
  7bb711:	3b f9                	cmp    edi,ecx
  7bb713:	74 21                	je     0x7bb736
  7bb715:	8b c1                	mov    eax,ecx
  7bb717:	2b c1                	sub    eax,ecx
  7bb719:	c1 f8 02             	sar    eax,0x2
  7bb71c:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bb723:	53                   	push   ebx
  7bb724:	51                   	push   ecx
  7bb725:	57                   	push   edi
  7bb726:	e8 c5 5f 0d 00       	call   0x8916f0
  7bb72b:	83 c4 0c             	add    esp,0xc
  7bb72e:	03 df                	add    ebx,edi
  7bb730:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  7bb736:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bb739:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7bb740:	59                   	pop    ecx
  7bb741:	5f                   	pop    edi
  7bb742:	5b                   	pop    ebx
  7bb743:	8b e5                	mov    esp,ebp
  7bb745:	5d                   	pop    ebp
  7bb746:	c3                   	ret
```

## 驗證矩陣

| 問題 | 證據 | 目前分級 |
|---|---|---|
| owner 是 0x10C bytes manager | 全域建立 `0x007AAF41` → constructor `0x007B8E50` | 已確認 |
| B 是三指標區段 | `0x007B8F76～82`、`0x007BB664～70B`、`0x007B91CF～EE` | 已確認 |
| B consumer 只執行前 N | `0x007BB670～7D`, `0x007BB6F0～703` | 已確認 |
| B consumer 後清空 | `0x007BB705～730`，計算 `end-end=0` | 已確認 |
| B entry concrete vptr | 尚無可信建構/指派鏈 | 未證實 |
| B 實際 append writer | 局部 VA 掃描僅見 init/dtor/clear；可能別名 | 未證實 |
| B entry -> 全域22桶 producer | 只有相鄰執行順序 | 未證實 |
| 分數代表距離／畫面優先級 | 未識別 entry 類型與上下文語義 | 未證實 |

## 建議的動態驗證（未執行，不冒稱結果）

1. 在 `0x007BB640` 入口記錄 ECX（consumer manager this）、`[ECX+0xB4]`、`[ECX+0xB8]`、`[ECX+0xBC]`、`[ECX+0xC4]`，以及 Return Address。先檢查 ECX 是否等於 `[0x00FBA838]`。
2. 若 B begin/end 被初始化後變為非空，對**實際 manager 的 `+0xB8`**設硬體寫入 watchpoint（不要對所有 `+B8` offset 類型設斷點），擷取當時 EIP、暫存器、stack 與 caller。這應能直接定位 alias/helper writer。
3. 在 `0x007BB6F9` 執行前讀 `entry=[begin+i*4]`、`vptr=[entry]`、`fn4=[vptr+4]`、`fn8=[vptr+8]`；另於 `0x007BBC7D` 讀評分方法地址。對應此 entry 的建構與注入來源。
4. 在 entry `fn4` 下斷點並於 `0x00FB7740` 的 22 個 count 寫入地址設資料斷點；若捕捉到因果鏈，紀錄完整 caller→entry→producer→bucket。單純呼叫順序不足。
5. 檢查 `0x007BB730` 清空前後 B end 與是否有元素指標被真正釋放；不要因 `0x008916F0` 被呼叫就推定 destructor。

## 未來段落方向（T08-141）

建議優先以反編譯資料或動態 watchpoint 追蹤 `0x007BB640` 本體 `+0xB8` 非初始化寫入，然後回到 entry vtable 定位；不再重做僅查固定 `0xB8` displacement 的無區分掃描。

**交付限制**：靜態資料無法閉合 B producer，故此次四段完成的是交叉參照、虛表、ABI 與因果邊界的研究；並非聲稱已破解 B queue 所有上游。
