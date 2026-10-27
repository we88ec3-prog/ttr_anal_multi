# T08-135 — 通用 pointer-vector append helper 與 B queue 寫入者篩選

## 第一手來源
- 原始證據：`Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪直接以原始檔計算）。
- 反組譯：使用 GNU `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000`，對當前 BIN 全檔建立線性反組譯索引；重要 VA 再以功能邊界與既有 T08-131/132 筆記核對。線性反組譯可能包含資料誤判，不等同控制流程圖。
- 研究屬**靜態分析**；未執行客戶端、未設記憶體斷點。
- 分析區分「已確認的本段指令」、「合理推測」、「未證實的全域別名身分」。

## `0x007BB750` 真實操作約定
它使用 `EDI` 作 vector 三指標結構地址，`EAX` 作待複製指標槽地址；capacity 不足時呼叫 `0x00797D30`，正常時向 `[EDI+4]` 指示 end 寫入一個 DWORD 並將 end 增加4。這是**泛用容器 helper**，不能由「call 到該函式」直接推定 queue 身分。

```asm
  7bb750:	56                   	push   esi
  7bb751:	8b f0                	mov    esi,eax
  7bb753:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb756:	3b f0                	cmp    esi,eax
  7bb758:	73 2b                	jae    0x7bb785
  7bb75a:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7bb75c:	3b ce                	cmp    ecx,esi
  7bb75e:	77 25                	ja     0x7bb785
  7bb753:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb756:	3b f0                	cmp    esi,eax
  7bb758:	73 2b                	jae    0x7bb785
  7bb75a:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7bb75c:	3b ce                	cmp    ecx,esi
  7bb75e:	77 25                	ja     0x7bb785
  7bb760:	2b f1                	sub    esi,ecx
  7bb762:	c1 fe 02             	sar    esi,0x2
  7bb760:	2b f1                	sub    esi,ecx
  7bb762:	c1 fe 02             	sar    esi,0x2
  7bb765:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  7bb768:	75 07                	jne    0x7bb771
  7bb76a:	8b c7                	mov    eax,edi
  7bb76c:	e8 bf c5 fd ff       	call   0x797d30
  7bb771:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb774:	85 c0                	test   eax,eax
  7bb765:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  7bb768:	75 07                	jne    0x7bb771
  7bb76a:	8b c7                	mov    eax,edi
  7bb76c:	e8 bf c5 fd ff       	call   0x797d30
  7bb771:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb774:	85 c0                	test   eax,eax
  7bb776:	74 24                	je     0x7bb79c
  7bb778:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7bb76a:	8b c7                	mov    eax,edi
  7bb76c:	e8 bf c5 fd ff       	call   0x797d30
  7bb771:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb774:	85 c0                	test   eax,eax
  7bb776:	74 24                	je     0x7bb79c
  7bb778:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7bb77a:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  7bb77d:	89 10                	mov    DWORD PTR [eax],edx
  7bb774:	85 c0                	test   eax,eax
  7bb776:	74 24                	je     0x7bb79c
  7bb778:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7bb77a:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  7bb77d:	89 10                	mov    DWORD PTR [eax],edx
  7bb77f:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  7bb783:	5e                   	pop    esi
  7bb784:	c3                   	ret
  7bb785:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  7bb788:	75 07                	jne    0x7bb791
  7bb78a:	8b c7                	mov    eax,edi
  7bb78c:	e8 9f c5 fd ff       	call   0x797d30
  7bb791:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb794:	85 c0                	test   eax,eax
  7bb796:	74 04                	je     0x7bb79c
  7bb798:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7bb791:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  7bb794:	85 c0                	test   eax,eax
  7bb796:	74 04                	je     0x7bb79c
  7bb798:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7bb79a:	89 08                	mov    DWORD PTR [eax],ecx
  7bb79c:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  7bb7a0:	5e                   	pop    esi
  7bb7a1:	c3                   	ret
  7bb798:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7bb79a:	89 08                	mov    DWORD PTR [eax],ecx
  7bb79c:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  7bb7a0:	5e                   	pop    esi
  7bb7a1:	c3                   	ret
  7bb7a2:	cc                   	int3
  7bb7a3:	cc                   	int3
  7bb7a4:	cc                   	int3
  7bb79c:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  7bb7a0:	5e                   	pop    esi
  7bb7a1:	c3                   	ret
  7bb7a2:	cc                   	int3
  7bb7a3:	cc                   	int3
  7bb7a4:	cc                   	int3
  7bb7a5:	cc                   	int3
  7bb7a6:	cc                   	int3
```

## 三條已確認 append 路徑的容器身分
| caller | 實際傳入 EDI | 結論 |
|---|---|---|
| `0x007BB623` | `owner+0xA4`（`0x007BB61A`） | A array writer，不是 B array |
| `0x007E87FA` | `record+0x20`（`0x007E87F7`） | 分組記錄 writer，不是全域 B array |
| `0x007B96D1` | `EBX+0x7C`（`0x007B96CB`） | group 子陣列 writer，不是 B array |

```asm
  7bb61a:	81 c7 a4 00 00 00    	add    edi,0xa4
  7bb620:	8d 45 0c             	lea    eax,[ebp+0xc]
  7bb623:	e8 28 01 00 00       	call   0x7bb750
  7bb628:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bb62b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7bb632:	59                   	pop    ecx
  7bb633:	5f                   	pop    edi
  7bb634:	5e                   	pop    esi
  7bb623:	e8 28 01 00 00       	call   0x7bb750
  7bb628:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bb62b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7bb632:	59                   	pop    ecx
  7bb633:	5f                   	pop    edi
  7bb634:	5e                   	pop    esi
  7bb635:	5b                   	pop    ebx
  7bb636:	8b e5                	mov    esp,ebp
  7e87f3:	8d 44 24 14          	lea    eax,[esp+0x14]
  7e87f7:	8d 7e 20             	lea    edi,[esi+0x20]
  7e87fa:	e8 51 2f fd ff       	call   0x7bb750
  7e87ff:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  7e8803:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7e880a:	59                   	pop    ecx
  7e880b:	5f                   	pop    edi
  7e880c:	5e                   	pop    esi
  7e87fa:	e8 51 2f fd ff       	call   0x7bb750
  7e87ff:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  7e8803:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7e880a:	59                   	pop    ecx
  7e880b:	5f                   	pop    edi
  7e880c:	5e                   	pop    esi
  7e880d:	5b                   	pop    ebx
  7e880e:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  7b96cb:	8d 7b 7c             	lea    edi,[ebx+0x7c]
  7b96ce:	8d 45 d0             	lea    eax,[ebp-0x30]
  7b96d1:	e8 7a 20 00 00       	call   0x7bb750
  7b96d6:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7b96d9:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7b96dc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7b96e3:	59                   	pop    ecx
  7b96e4:	5f                   	pop    edi
  7b96d1:	e8 7a 20 00 00       	call   0x7bb750
  7b96d6:	8b 45 d0             	mov    eax,DWORD PTR [ebp-0x30]
  7b96d9:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7b96dc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7b96e3:	59                   	pop    ecx
  7b96e4:	5f                   	pop    edi
  7b96e5:	5e                   	pop    esi
  7b96e6:	5b                   	pop    ebx
```

## 限制：負面掃描不是 producer 不存在的證明
在 `0x007B8E00..0x007BCF00` 直接形如 `mov [base+0xB8]` 的可確認初始化/清空位置包含 `0x007B8F7C`、`0x007B91E8`、`0x007BB730`；`0x007BB640` 同時讀 B begin/end 做排序與派送。然而 writer 可以使用不同基址別名、另一 helper 或位於其他區段。全檔 linear disasm 的純 displacement 搜尋因相同數值偏移遍及不同物件，不能認定為本 owner 的完整 xref。

## 已確認 / 待證
- 已確認：`0x007BB750` append 是一個 DWORD，而且根據 vector 容量分流擴容。
- 已確認：上述三條 caller 的容器基址不是已知的 `owner+0xB4`。
- 未證實：priority queue B 的 append 位置與 B entry 具體 vtable 身分。
- 下一段：回到 B consumer，稽核 top-N 派送及 end 重置行為，界定後續動態斷點應該觀測什麼。