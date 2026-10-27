# KR T08-172 — T08 actor／資源釋放兩條路徑的交叉證據驗收

## 一手來源及可稽核性

- **標的**：韓版 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes，PE32 x86。
- **證據方法**：本輪實際對 PE `.text` 正式 VA 執行 `objdump -d -M intel --start-address ... --stop-address ...`。展示的線性反組譯不等同全函式 CFG／動態 runtime。
- **分工**：T08 研究 actor 建立／登記／移除之資料介面及相關資源生命週期；其他 Task 的封包分派、場景政策僅交叉參照。
- **交叉來源**：原先 T08-165～168 完整研究與本輪第一手機器碼。舊報告命名均為研究標籤，非官方符號證據。
- **驗證限制**：不執行客戶端、不修改遊戲／服務或存檔；虛擬函式和 Win32 import 未獨立解析成全部實際 concrete target。

## 研究定位

此段整合 169～171 的新證據，將 T08-165～168 的基底解構鏈與此次的資源回收分成**兩個不同層級**。不能因為兩者均出現 `free` 就假設 owner 相同。

## 規範化資料流

```text
GameInfo actor removal (此前 T08-153～160)
  ├─ actor 虛擬預清理（T08-161～167）
  ├─ actor deleting destructor／基底釋放（T08-165～168）
  └─ tree node erase 0x7B6890（Actor ID 容器）

資源指標槽 release (T08-166; 本批直接 BIN 核驗)
  └─ 0x7BE5F0(ESI=pointer-slot)
       ├─ [slot]==0 → ret, 不寫資料
       ├─ item+0x74!=0 且 item+0x78!=0
       │    └─ 0x7DD1A0(owner=[item+0], item)
       │         ├─ owner+0x44>=1 → owner+0x7C vector append (0x7BB350)
       │         └─ owner+0x44<1 → nested storage free (0x7BD850), free item
       └─ otherwise
            ├─ item+0x74>=1 → nested payload cleanup 0x7BE0F0
            ├─ vector cleanup 0x7BD850
            └─ free item
       [slot]=0
```

## 確認層級與對應反證

| 判斷 | 等級 | 依據／限制 |
|---|---|---|
| `0x7DD1A0` 的 `owner+44` 控制 defer 或 immediate | BIN 直接確認 | 有號比較與兩個分支；尚未追 writer |
| `0x7BB350` 擴增 DWORD vector | BIN 直接確認 | `[edi+4]`、`[edi+8]`，擴容呼叫 0x797930 |
| `0x7BE0F0` 走 vtable+8 然後 vtable+0(1) | BIN 直接確認 | 每個 node+8 payload |
| `0x7BD850` 清除 dynamic pointer vector | BIN 直接確認 | pointer 清零、free storage、三欄位清零 |
| 佇列 drain 與跨 thread 時序 | 未確認 | IAT 尚未命名；reader/writer 尚未閉合 |
| 任何一條是特定「怪物 AI／伺服器權限」 | 無證據 | 僅是 resource lifecycle helper |
| T08 整體完整反編譯完成 | 未確認 | 此為有界功能鏈，不是全域覆蓋率 |

## 下一段研究建議

T08-173 應追 `owner+0x44` 寫入者及 `owner+0x7C` 消費者，解析 `0x7DD1F0` 的 drain loop 和 `0x7DD1A0` 的 IAT，確定延遲釋放是否在鎖保護下執行與完成；另看多型 payload+0x8 vtable 來源。函式命名仍以地址與資料效果為主。

## 原始 machine-code 摘錄（含實際 VA）

### 原始 PE VA `0x007be5f0..0x007be653`

```asm
  7be5f0:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5f2:	85 c0                	test   eax,eax
  7be5f4:	75 01                	jne    0x7be5f7
  7be5f6:	c3                   	ret
  7be5f7:	8b 00                	mov    eax,DWORD PTR [eax]
  7be5f9:	ff 48 60             	dec    DWORD PTR [eax+0x60]
  7be5fc:	8b 06                	mov    eax,DWORD PTR [esi]
  7be5fe:	8b 48 74             	mov    ecx,DWORD PTR [eax+0x74]
  7be601:	85 c9                	test   ecx,ecx
  7be603:	74 1b                	je     0x7be620
  7be605:	83 78 78 00          	cmp    DWORD PTR [eax+0x78],0x0
  7be609:	74 15                	je     0x7be620
  7be60b:	50                   	push   eax
  7be60c:	8b 00                	mov    eax,DWORD PTR [eax]
  7be60e:	50                   	push   eax
  7be60f:	e8 8c eb 01 00       	call   0x7dd1a0
  7be614:	b8 01 00 00 00       	mov    eax,0x1
  7be619:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be61f:	c3                   	ret
  7be620:	83 f9 01             	cmp    ecx,0x1
  7be623:	7c 06                	jl     0x7be62b
  7be625:	50                   	push   eax
  7be626:	e8 c5 fa ff ff       	call   0x7be0f0
  7be62b:	57                   	push   edi
  7be62c:	8b 3e                	mov    edi,DWORD PTR [esi]
  7be62e:	85 ff                	test   edi,edi
  7be630:	74 14                	je     0x7be646
  7be632:	e8 19 f2 ff ff       	call   0x7bd850
  7be637:	57                   	push   edi
  7be638:	e8 cf 2b 0d 00       	call   0x89120c
  7be63d:	83 c4 04             	add    esp,0x4
  7be640:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be646:	5f                   	pop    edi
  7be647:	b8 01 00 00 00       	mov    eax,0x1
  7be64c:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  7be652:	c3                   	ret
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

### 原始 PE VA `0x007be0f0..0x007be146`

```asm
  7be0f0:	55                   	push   ebp
  7be0f1:	8b ec                	mov    ebp,esp
  7be0f3:	51                   	push   ecx
  7be0f4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7be0f7:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  7be0fa:	57                   	push   edi
  7be0fb:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  7be0fe:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  7be101:	3b f9                	cmp    edi,ecx
  7be103:	74 33                	je     0x7be138
  7be105:	56                   	push   esi
  7be106:	8b 37                	mov    esi,DWORD PTR [edi]
  7be108:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7be10b:	85 c9                	test   ecx,ecx
  7be10d:	74 1d                	je     0x7be12c
  7be10f:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be111:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  7be114:	ff d2                	call   edx
  7be116:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7be119:	85 c9                	test   ecx,ecx
  7be11b:	74 0f                	je     0x7be12c
  7be11d:	8b 01                	mov    eax,DWORD PTR [ecx]
  7be11f:	8b 10                	mov    edx,DWORD PTR [eax]
  7be121:	6a 01                	push   0x1
  7be123:	ff d2                	call   edx
  7be125:	c7 46 08 00 00 00 00 	mov    DWORD PTR [esi+0x8],0x0
  7be12c:	83 c7 04             	add    edi,0x4
  7be12f:	3b 7d fc             	cmp    edi,DWORD PTR [ebp-0x4]
  7be132:	75 d2                	jne    0x7be106
  7be134:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  7be137:	5e                   	pop    esi
  7be138:	c7 40 74 00 00 00 00 	mov    DWORD PTR [eax+0x74],0x0
  7be13f:	5f                   	pop    edi
  7be140:	8b e5                	mov    esp,ebp
  7be142:	5d                   	pop    ebp
  7be143:	c2 04 00             	ret    0x4
```

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

## 版本與交接

T08-172 僅在此列出與標的直接相關的局部確證；未知的動態所有權與執行緒時序仍列未知。請以 GitHub `main` 已驗證完整原稿為基準比較，新增語意不可覆寫舊原稿。