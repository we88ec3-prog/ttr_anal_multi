# KR T08-169 — `0x7DD1A0` 雙路徑釋放與容器鎖定 ABI

## 一手來源及可稽核性

- **標的**：韓版 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes，PE32 x86。
- **證據方法**：本輪實際對 PE `.text` 正式 VA 執行 `objdump -d -M intel --start-address ... --stop-address ...`。展示的線性反組譯不等同全函式 CFG／動態 runtime。
- **分工**：T08 研究 actor 建立／登記／移除之資料介面及相關資源生命週期；其他 Task 的封包分派、場景政策僅交叉參照。
- **交叉來源**：原先 T08-165～168 完整研究與本輪第一手機器碼。舊報告命名均為研究標籤，非官方符號證據。
- **驗證限制**：不執行客戶端、不修改遊戲／服務或存檔；虛擬函式和 Win32 import 未獨立解析成全部實際 concrete target。

## 問題與新增結果

`0x7BE5F0` 的條件分支 `push object; push owner; call 0x7DD1A0` 究竟代表甚麼？本批擴展該 helper 的兩個分支。

1. `0x7DD1A7 cmp [ebx+0x44],1`、`jl 0x7DD1D5` 是 **owner+0x44 有號比較**，不是物件 `+0x44`。`ebx` 取 `[ebp+8]`，第二參數 `edi=[ebp+C]`。
2. owner+0x44 >=1 時，`lea esi,[ebx+0x64]`、兩次間接 IAT call 夾著 `lea edi,[ebx+0x7C]` / `lea eax,[ebp+0xC]` / `call 0x7BB350`；由形狀推定是同步保護下，將指標加入 owner+0x7C 的 DWORD vector。**對應 IAT 具體 API 名稱此段未證**。
3. owner+0x44 <1 時，只要 item 非 NULL，走 `call 0x7BD850` 然後 `push edi; call 0x89120C`，並 `ret 8`。這裡是被傳入資源／集合的獨立即時釋放路徑；`0x7BD850` 的呼叫暫時不能等價為清理任意 actor。
4. 上游 `0x7BE5F0` 在 `item+0x74` 和 `item+0x78` 均非零時呼叫本 helper，後續將 caller 的 `[esi]` 清零；其餘分支走 `0x7BE0F0`／`0x7BD850` 與 `0x89120C`。**清指標不等於 ownership 已由所有參考者正確解除**。

## 簡化偽碼（由具體 machine code 邊界導出）

```cpp
void ConditionalDeferOrRelease(Owner* owner, Resource* ptr) {
  if ((int32_t)owner->field44 >= 1) {
    lock_unknown(&owner->field64);
    // vector push helper 0x7BB350; container receiver=&owner->field7C
    append_pointer_to_vector(&owner->field7C, &ptr);
    unlock_unknown(&owner->field64);
  } else if (ptr != nullptr) {
    cleanup_nested_collection_7BD850(ptr);
    crt_free_89120C(ptr);
  }
}
```

`lock_unknown` 是對 IAT 呼叫的語意假設；來源目前僅支持 lock-like bracket，而不是已追蹤其 import symbol。`ptr` 是入參，不宜稱 game actor。

## 新解決／尚未解決

已確認 **延遲登記 vs 立即釋放** 由 owner 狀態決定，並區分資源生命週期與 actor 樹生命週期。待查：owner+44 狀態生產者；owner+64 import；owner+7C 的 drain consumer；`0x89120C` 的 CRT allocation 配對來源。

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

## 版本與交接

T08-169 僅在此列出與標的直接相關的局部確證；未知的動態所有權與執行緒時序仍列未知。請以 GitHub `main` 已驗證完整原稿為基準比較，新增語意不可覆寫舊原稿。