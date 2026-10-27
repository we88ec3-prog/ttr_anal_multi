# KR T08-171 — `0x7BD850` 集合釋放與 `0x7BB350` 延遲佇列寫入

## 一手來源及可稽核性

- **標的**：韓版 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes，PE32 x86。
- **證據方法**：本輪實際對 PE `.text` 正式 VA 執行 `objdump -d -M intel --start-address ... --stop-address ...`。展示的線性反組譯不等同全函式 CFG／動態 runtime。
- **分工**：T08 研究 actor 建立／登記／移除之資料介面及相關資源生命週期；其他 Task 的封包分派、場景政策僅交叉參照。
- **交叉來源**：原先 T08-165～168 完整研究與本輪第一手機器碼。舊報告命名均為研究標籤，非官方符號證據。
- **驗證限制**：不執行客戶端、不修改遊戲／服務或存檔；虛擬函式和 Win32 import 未獨立解析成全部實際 concrete target。

## 主要成果

本段比較 169 的兩條支路下游，避免把清除容器認定成 actor 析構。

`0x7BD850` 用 `EDI` 作 implicit receiver，讀 `[edi+4]`／`[edi+8]` 形成 begin/end。對每個 4-byte pointer：非 NULL 時呼叫 `0x89120C` 釋放並寫回 0；完成後還會對 contiguous storage 使用 `0x8912F0`，隨後釋放 begin storage (`0x89120C`)，把 `[edi+4],[edi+8],[edi+C]` 全部歸零。這是 **vector-like ownership cleanup**，不代表裡面皆為 CActor 指標。

`0x7BB350` 呼叫方式特殊：`EDI=&owner+7C`，`EAX=&stack_arg_0C`；非必要擴容時讀入來源 DWORD 寫至 `[container.end]`，`container.end+=4`；容量不足時呼叫 `0x797930`。`0x7BB350` 對來源是否在既存 vector 內有範圍判斷，避免同一 vector 擴容造成來源位址失效，這是典型 vector insertion 的 aliasing-guard 形狀，並非鍵值 hash/actor map insertion。

兩條路徑的語意對比：

| 條件 | `0x7DD1A0` 下游 | 可證資料效果 |
|---|---|---|
| owner+44 >=1 | `0x7BB350` | push 指標值到 owner+7C vector（在 IAT 括號內） |
| owner+44 <1 | `0x7BD850` → `0x89120C` | free item 的巢狀分配及 item 本身 |

## 重要的新不確定性

`0x7BD850` 裡觀察到 `mov eax,ecx; sub eax,ecx`，產生零長度傳給 `0x8912F0` 的路徑；這是字節級事實，**不應把此 helper 簡化成「必然移動非零記憶體」**。即使看似 CRT/STL deallocation cleanup，也不得據此宣稱已證明 memory leak 或 double free。未查明 allocator 附屬狀態及相關 begin/end 初值。

## 邊界

目前只連結 `0x7DD1A0` immediate branch 和 `0x7BE5F0` immediate branch 至 `0x7BD850`，未確認延遲佇列何時 drain。尚需調查 `owner+7C` reader、`owner+44` writer、`0x797930` capacity policy，以及 `0x8912F0` 的確切 CRT 功能。

## 原始 machine-code 摘錄（含實際 VA）

### 原始 PE VA `0x007bd850..0x007bd8c2`

```asm
  7bd850:	53                   	push   ebx
  7bd851:	8b 5f 08             	mov    ebx,DWORD PTR [edi+0x8]
  7bd854:	56                   	push   esi
  7bd855:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  7bd858:	3b f3                	cmp    esi,ebx
  7bd85a:	74 20                	je     0x7bd87c
  7bd85c:	8d 64 24 00          	lea    esp,[esp+0x0]
  7bd860:	8b 06                	mov    eax,DWORD PTR [esi]
  7bd862:	85 c0                	test   eax,eax
  7bd864:	74 0f                	je     0x7bd875
  7bd866:	50                   	push   eax
  7bd867:	e8 a0 39 0d 00       	call   0x89120c
  7bd86c:	83 c4 04             	add    esp,0x4
  7bd86f:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7bd875:	83 c6 04             	add    esi,0x4
  7bd878:	3b f3                	cmp    esi,ebx
  7bd87a:	75 e4                	jne    0x7bd860
  7bd87c:	8b 4f 08             	mov    ecx,DWORD PTR [edi+0x8]
  7bd87f:	8b 77 04             	mov    esi,DWORD PTR [edi+0x4]
  7bd882:	3b f1                	cmp    esi,ecx
  7bd884:	74 1e                	je     0x7bd8a4
  7bd886:	8b c1                	mov    eax,ecx
  7bd888:	2b c1                	sub    eax,ecx
  7bd88a:	c1 f8 02             	sar    eax,0x2
  7bd88d:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bd894:	53                   	push   ebx
  7bd895:	51                   	push   ecx
  7bd896:	56                   	push   esi
  7bd897:	e8 54 3a 0d 00       	call   0x8912f0
  7bd89c:	83 c4 0c             	add    esp,0xc
  7bd89f:	03 de                	add    ebx,esi
  7bd8a1:	89 5f 08             	mov    DWORD PTR [edi+0x8],ebx
  7bd8a4:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bd8a7:	5e                   	pop    esi
  7bd8a8:	5b                   	pop    ebx
  7bd8a9:	85 c0                	test   eax,eax
  7bd8ab:	74 09                	je     0x7bd8b6
  7bd8ad:	50                   	push   eax
  7bd8ae:	e8 59 39 0d 00       	call   0x89120c
  7bd8b3:	83 c4 04             	add    esp,0x4
  7bd8b6:	33 c0                	xor    eax,eax
  7bd8b8:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  7bd8bb:	89 47 08             	mov    DWORD PTR [edi+0x8],eax
  7bd8be:	89 47 0c             	mov    DWORD PTR [edi+0xc],eax
  7bd8c1:	c3                   	ret
```

### 原始 PE VA `0x007bb350..0x007bb3a2`

```asm
  7bb350:	56                   	push   esi
  7bb351:	8b f0                	mov    esi,eax
  7bb353:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb356:	3b f0                	cmp    esi,eax
  7bb358:	73 2b                	jae    0x7bb385
  7bb35a:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7bb35c:	3b ce                	cmp    ecx,esi
  7bb35e:	77 25                	ja     0x7bb385
  7bb360:	2b f1                	sub    esi,ecx
  7bb362:	c1 fe 02             	sar    esi,0x2
  7bb365:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  7bb368:	75 07                	jne    0x7bb371
  7bb36a:	8b c7                	mov    eax,edi
  7bb36c:	e8 bf c5 fd ff       	call   0x797930
  7bb371:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb374:	85 c0                	test   eax,eax
  7bb376:	74 24                	je     0x7bb39c
  7bb378:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7bb37a:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  7bb37d:	89 10                	mov    DWORD PTR [eax],edx
  7bb37f:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  7bb383:	5e                   	pop    esi
  7bb384:	c3                   	ret
  7bb385:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  7bb388:	75 07                	jne    0x7bb391
  7bb38a:	8b c7                	mov    eax,edi
  7bb38c:	e8 9f c5 fd ff       	call   0x797930
  7bb391:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb394:	85 c0                	test   eax,eax
  7bb396:	74 04                	je     0x7bb39c
  7bb398:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7bb39a:	89 08                	mov    DWORD PTR [eax],ecx
  7bb39c:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  7bb3a0:	5e                   	pop    esi
  7bb3a1:	c3                   	ret
```

### 原始 PE VA `0x007dd1a0..0x007dd1ed`

```asm
  7dd1a0:	55                   	push   ebp
  7dd1a1:	8b ec                	mov    ebp,esp
  7dd1a3:	53                   	push   ebx
  7dd1a4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7dd1a7:	83 7b 44 01          	cmp    DWORD PTR [ebx+0x44],0x1
  7dd1ab:	57                   	push   edi
  7dd1ac:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  7dd1af:	7c 24                	jl     0x7dd1d5
  7dd1b1:	56                   	push   esi
  7dd1b2:	8d 73 64             	lea    esi,[ebx+0x64]
  7dd1b5:	56                   	push   esi
  7dd1b6:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  7dd1bc:	8d 7b 7c             	lea    edi,[ebx+0x7c]
  7dd1bf:	8d 45 0c             	lea    eax,[ebp+0xc]
  7dd1c2:	e8 89 e1 fd ff       	call   0x7bb350
  7dd1c7:	56                   	push   esi
  7dd1c8:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  7dd1ce:	5e                   	pop    esi
  7dd1cf:	5f                   	pop    edi
  7dd1d0:	5b                   	pop    ebx
  7dd1d1:	5d                   	pop    ebp
  7dd1d2:	c2 08 00             	ret    0x8
  7dd1d5:	85 ff                	test   edi,edi
  7dd1d7:	74 0e                	je     0x7dd1e7
  7dd1d9:	e8 72 06 fe ff       	call   0x7bd850
  7dd1de:	57                   	push   edi
  7dd1df:	e8 28 40 0b 00       	call   0x89120c
  7dd1e4:	83 c4 04             	add    esp,0x4
  7dd1e7:	5f                   	pop    edi
  7dd1e8:	5b                   	pop    ebx
  7dd1e9:	5d                   	pop    ebp
  7dd1ea:	c2 08 00             	ret    0x8
```

## 版本與交接

T08-171 僅在此列出與標的直接相關的局部確證；未知的動態所有權與執行緒時序仍列未知。請以 GitHub `main` 已驗證完整原稿為基準比較，新增語意不可覆寫舊原稿。