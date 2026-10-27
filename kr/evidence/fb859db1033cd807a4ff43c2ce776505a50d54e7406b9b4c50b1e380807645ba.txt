# T08-144 — B producer consumer link and vtable limit

**第一手來源**：`Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（2026-10-27 本輪重新實測一致）。

**重現方法**：`objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 Tartaros.bin`；所摘錄 VA/bytes 直接對照原 BIN。BIN 是以 VA 0x401000 排列的反組譯資料，不能直接當原 PE sections 的 raw file offset；不宣稱使用動態除錯。

**證據分級**：`[確認]` 機器碼及確定資料流；`[推論]` 靜態語意；`[未知]` 缺少 vtable / 實際 run-time 參數。

## 本段主題：已閉合的 B producer→vector→consumer，及仍未閉合的虛擬方法因果鏈

**重要修正**：T08-137～140 以局部 VA 與固定偏移搜尋，未抓到真正 writer；T08-141 實際在 `0x007A69D9～0x007A6A51` 找到 global B `end+=4`，而且 `0x007A67E8 / 0x007A69E5` 共同確立 entry 來源為 `Host+0x0C`。現在可以證明 B 容器中寫入與讀出屬同一全域 manager，但無法證明 `entry->vtable+0x04` 向全域 22 桶產生資料。

### 三段閉合證據

**1. B producer**

```asm
7a69d9:	8b 35 38 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba838
7a69df:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
7a69e5:	83 c7 0c             	add    edi,0xc
7a69e8:	8d 4d ec             	lea    ecx,[ebp-0x14]
7a69eb:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
7a69ee:	3b c8                	cmp    ecx,eax
...
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

**2. consumer 實際取值**（`ESI` 為 manager，由 caller 設定的已研究來源）

```asm
7bb664:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
7bb66a:	2b 86 b4 00 00 00    	sub    eax,DWORD PTR [esi+0xb4]
7bb670:	8b 9e c4 00 00 00    	mov    ebx,DWORD PTR [esi+0xc4]
7bb676:	c1 f8 02             	sar    eax,0x2
7bb679:	3b d8                	cmp    ebx,eax
7bb67b:	76 02                	jbe    0x7bb67f
7bb67d:	8b d8                	mov    ebx,eax
...
7bb6f0:	8b 8e b4 00 00 00    	mov    ecx,DWORD PTR [esi+0xb4]
7bb6f6:	8b 0c b9             	mov    ecx,DWORD PTR [ecx+edi*4]
7bb6f9:	8b 11                	mov    edx,DWORD PTR [ecx]
7bb6fb:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
7bb6fe:	ff d0                	call   eax
7bb700:	47                   	inc    edi
7bb701:	3b fb                	cmp    edi,ebx
7bb703:	72 eb                	jb     0x7bb6f0
```

**3. 排序比較器**（entry vfptr+8，與 execute 的 +4 是同一元素的虛擬方法 slots）

```asm
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
```

### 靜態關係圖

```text
Host this (ECX at 0x007A67C0)
  -> +0x1C / +0x124 / +0xAC / +0x70 / +0x8C guards
  -> candidate = Host+0x0C
  -> global Manager [0x00FBA838] +0xB4/0xB8/0xBC
  -> writer 0x007A69D9..0x007A6A51
  -> B vector pointer entry = Host+0x0C
  -> consumer 0x007BB640
     -> B entry vtable+0x08(context) -> x87 score
     -> B entry vtable+0x04() -> side effect UNKNOWN
     -> B.end = B.begin (logical clear)

separate known sequence:
  0x0079A320 -> 0x007BB640 -> callback vtable+0x0C -> 0x007D1310 (22桶)
  (sequence confirmed; entry execute producing bucket remains UNPROVEN)
```

### 技術判定與後續必要觀測

| 問題 | 判定 |
|---|---|
| global B producer 是否存在？ | **已確認**，0x007A69D9..0x007A6A51 |
| B entry pointer 身分？ | **已確認相對位址** `Host+0x0C`，但 Host 類型未知 |
| 會否不經 guard 每次都 append？ | **否**，多個 early exit / guard |
| B score 的實際意義？ | **未知** |
| B execute 是否對全域22桶入桶？ | **未知**，尚缺具體 vptr/+4 方法與完整 caller chain |

**下一段 T08-145 建議**：由 `0x007A67C0` this+0x0C 的 vfptr 實際賦值位置找 constructor / concrete methods；優先反查 `this+0x0C` 可能為 interface base 的初始化。可在 `0x007BB6F9` 動態讀 `[entry]` 與 `[vptr+4/+8]`，再對 `0x00FB7740` count 設硬體寫入斷點，比對同一幀 call stack。未執行動態驗證，不冒稱結果。

