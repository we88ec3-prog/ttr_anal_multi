# T08-142 — B producer control gates

**第一手來源**：`Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（2026-10-27 本輪重新實測一致）。

**重現方法**：`objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 Tartaros.bin`；所摘錄 VA/bytes 直接對照原 BIN。BIN 是以 VA 0x401000 排列的反組譯資料，不能直接當原 PE sections 的 raw file offset；不宣稱使用動態除錯。

**證據分級**：`[確認]` 機器碼及確定資料流；`[推論]` 靜態語意；`[未知]` 缺少 vtable / 實際 run-time 參數。

## 本段主題：producer 何時被允許執行

**[確認]** `0x007A67C0` 的開頭 this 來自 `ECX`，先核對 `this+0x1C` 與 `this+0x124`，兩者有任一為零就跳過整個 producer 分支到 `0x007A6A89`。接著 `this+0xAC` 存在時呼叫其 `vtable+0x2C`；`this+0x70` 指向的樹/鏈迭代元素中亦呼叫 `vtable+0x30`；不同結果控制是否進入中間處理或進入候選 append。

### 入口與早退 ASM

```asm
7a67c0:	55                   	push   ebp
7a67c1:	8b ec                	mov    ebp,esp
7a67c3:	6a ff                	push   0xffffffff
7a67c5:	68 76 bd 92 00       	push   0x92bd76
7a67ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
7a67d0:	50                   	push   eax
7a67d1:	83 ec 18             	sub    esp,0x18
7a67d4:	53                   	push   ebx
7a67d5:	56                   	push   esi
7a67d6:	57                   	push   edi
7a67d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
7a67dc:	33 c5                	xor    eax,ebp
7a67de:	50                   	push   eax
7a67df:	8d 45 f4             	lea    eax,[ebp-0xc]
7a67e2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
7a67e8:	8b f9                	mov    edi,ecx
7a67ea:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
7a67ed:	83 7f 1c 00          	cmp    DWORD PTR [edi+0x1c],0x0
7a67f1:	0f 84 92 02 00 00    	je     0x7a6a89
7a67f7:	83 bf 24 01 00 00 00 	cmp    DWORD PTR [edi+0x124],0x0
7a67fe:	0f 84 85 02 00 00    	je     0x7a6a89
7a6804:	83 bf ac 00 00 00 00 	cmp    DWORD PTR [edi+0xac],0x0
7a680b:	be 01 00 00 00       	mov    esi,0x1
7a6810:	8b de                	mov    ebx,esi
7a6812:	74 13                	je     0x7a6827
7a6814:	8b 8f ac 00 00 00    	mov    ecx,DWORD PTR [edi+0xac]
7a681a:	8b 01                	mov    eax,DWORD PTR [ecx]
7a681c:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
7a681f:	ff d2                	call   edx
7a6821:	85 c0                	test   eax,eax
7a6823:	75 02                	jne    0x7a6827
7a6825:	33 db                	xor    ebx,ebx
7a6827:	8b 4f 70             	mov    ecx,DWORD PTR [edi+0x70]
7a682a:	8b 01                	mov    eax,DWORD PTR [ecx]
7a682c:	89 4d e8             	mov    DWORD PTR [ebp-0x18],ecx
7a682f:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
7a6832:	3b c1                	cmp    eax,ecx
7a6834:	74 4d                	je     0x7a6883
7a6836:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
7a6839:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
7a683c:	2b 46 18             	sub    eax,DWORD PTR [esi+0x18]
7a683f:	33 ff                	xor    edi,edi
7a6841:	c1 f8 02             	sar    eax,0x2
7a6844:	85 c0                	test   eax,eax
7a6846:	74 23                	je     0x7a686b
7a6848:	8b 4e 18             	mov    ecx,DWORD PTR [esi+0x18]
7a684b:	8b 0c b9             	mov    ecx,DWORD PTR [ecx+edi*4]
7a684e:	8b 11                	mov    edx,DWORD PTR [ecx]
7a6850:	8b 42 30             	mov    eax,DWORD PTR [edx+0x30]
7a6853:	ff d0                	call   eax
7a6855:	85 c0                	test   eax,eax
7a6857:	74 10                	je     0x7a6869
7a6859:	8b 4e 1c             	mov    ecx,DWORD PTR [esi+0x1c]
7a685c:	2b 4e 18             	sub    ecx,DWORD PTR [esi+0x18]
7a685f:	47                   	inc    edi
7a6860:	c1 f9 02             	sar    ecx,0x2
7a6863:	3b f9                	cmp    edi,ecx
7a6865:	72 e1                	jb     0x7a6848
7a6867:	eb 02                	jmp    0x7a686b
7a6869:	33 db                	xor    ebx,ebx
7a686b:	8d 45 ec             	lea    eax,[ebp-0x14]
7a686e:	e8 cd 7d 0b 00       	call   0x85e640
7a6873:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
7a6876:	3b 45 e8             	cmp    eax,DWORD PTR [ebp-0x18]
7a6879:	75 bb                	jne    0x7a6836
7a687b:	8b 7d f0             	mov    edi,DWORD PTR [ebp-0x10]
7a687e:	be 01 00 00 00       	mov    esi,0x1
7a6883:	85 db                	test   ebx,ebx
7a6885:	0f 85 8d 00 00 00    	jne    0x7a6918
```

### 分歧流程 ASM

```asm
7a6883:	85 db                	test   ebx,ebx
7a6885:	0f 85 8d 00 00 00    	jne    0x7a6918
7a688b:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
7a6892:	d9 87 fc 00 00 00    	fld    DWORD PTR [edi+0xfc]
7a6898:	d9 5d dc             	fstp   DWORD PTR [ebp-0x24]
7a689b:	d9 ee                	fldz
7a689d:	d9 55 e0             	fst    DWORD PTR [ebp-0x20]
7a68a0:	d9 5d e4             	fstp   DWORD PTR [ebp-0x1c]
7a68a3:	75 22                	jne    0x7a68c7
7a68a5:	09 35 e8 79 fb 00    	or     DWORD PTR ds:0xfb79e8,esi
7a68ab:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
7a68ae:	e8 2d 29 ff ff       	call   0x7991e0
7a68b3:	68 e0 d2 bc 00       	push   0xbcd2e0
7a68b8:	e8 5d be 0e 00       	call   0x89271a
7a68bd:	83 c4 04             	add    esp,0x4
7a68c0:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
7a68c7:	8b 55 dc             	mov    edx,DWORD PTR [ebp-0x24]
7a68ca:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
7a68cd:	83 ec 0c             	sub    esp,0xc
7a68d0:	8b c4                	mov    eax,esp
7a68d2:	89 10                	mov    DWORD PTR [eax],edx
7a68d4:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
7a68d7:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
7a68da:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
7a68dd:	8b 97 ec 00 00 00    	mov    edx,DWORD PTR [edi+0xec]
7a68e3:	8b 87 f4 00 00 00    	mov    eax,DWORD PTR [edi+0xf4]
7a68e9:	83 ec 0c             	sub    esp,0xc
7a68ec:	8b cc                	mov    ecx,esp
7a68ee:	89 11                	mov    DWORD PTR [ecx],edx
7a68f0:	8b 97 f0 00 00 00    	mov    edx,DWORD PTR [edi+0xf0]
7a68f6:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
7a68f9:	68 a8 76 fb 00       	push   0xfb76a8
7a68fe:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
7a6901:	e8 7a 46 ff ff       	call   0x79af80
7a6906:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
7a6909:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
7a6910:	59                   	pop    ecx
7a6911:	5f                   	pop    edi
7a6912:	5e                   	pop    esi
7a6913:	5b                   	pop    ebx
7a6914:	8b e5                	mov    esp,ebp
7a6916:	5d                   	pop    ebp
7a6917:	c3                   	ret
7a6918:	b8 ec f5 c4 00       	mov    eax,0xc4f5ec
7a691d:	e8 8e 1b 09 00       	call   0x8384b0
7a6922:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
7a6925:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
7a692c:	75 20                	jne    0x7a694e
7a692e:	09 35 e8 79 fb 00    	or     DWORD PTR ds:0xfb79e8,esi
7a6934:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
7a6938:	e8 a3 28 ff ff       	call   0x7991e0
7a693d:	68 e0 d2 bc 00       	push   0xbcd2e0
7a6942:	e8 d3 bd 0e 00       	call   0x89271a
7a6947:	83 c4 04             	add    esp,0x4
7a694a:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
7a694e:	e8 cd 1c 00 00       	call   0x7a8620
7a6953:	8b 7d f0             	mov    edi,DWORD PTR [ebp-0x10]
7a6956:	8b 4f 1c             	mov    ecx,DWORD PTR [edi+0x1c]
7a6959:	8b 11                	mov    edx,DWORD PTR [ecx]
7a695b:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
7a695e:	ff d0                	call   eax
```

### 迭代與最後 append 門檻

```asm
7a6960:	8b 47 70             	mov    eax,DWORD PTR [edi+0x70]
7a6963:	8b 30                	mov    esi,DWORD PTR [eax]
7a6965:	8b 5d e8             	mov    ebx,DWORD PTR [ebp-0x18]
7a6968:	3b f3                	cmp    esi,ebx
7a696a:	74 52                	je     0x7a69be
7a696c:	8d 64 24 00          	lea    esp,[esp+0x0]
7a6970:	8b 4e 18             	mov    ecx,DWORD PTR [esi+0x18]
7a6973:	8b 11                	mov    edx,DWORD PTR [ecx]
7a6975:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
7a6978:	ff d0                	call   eax
7a697a:	80 7e 21 00          	cmp    BYTE PTR [esi+0x21],0x0
7a697e:	75 3a                	jne    0x7a69ba
7a6980:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
7a6983:	80 78 21 00          	cmp    BYTE PTR [eax+0x21],0x0
7a6987:	75 16                	jne    0x7a699f
7a6989:	8b f0                	mov    esi,eax
7a698b:	8b 06                	mov    eax,DWORD PTR [esi]
7a698d:	80 78 21 00          	cmp    BYTE PTR [eax+0x21],0x0
7a6991:	75 27                	jne    0x7a69ba
7a6993:	8b f0                	mov    esi,eax
7a6995:	8b 06                	mov    eax,DWORD PTR [esi]
7a6997:	80 78 21 00          	cmp    BYTE PTR [eax+0x21],0x0
7a699b:	74 f6                	je     0x7a6993
7a699d:	eb 1b                	jmp    0x7a69ba
7a699f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
7a69a2:	80 78 21 00          	cmp    BYTE PTR [eax+0x21],0x0
7a69a6:	75 10                	jne    0x7a69b8
7a69a8:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
7a69ab:	75 0b                	jne    0x7a69b8
7a69ad:	8b f0                	mov    esi,eax
7a69af:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
7a69b2:	80 78 21 00          	cmp    BYTE PTR [eax+0x21],0x0
7a69b6:	74 f0                	je     0x7a69a8
7a69b8:	8b f0                	mov    esi,eax
7a69ba:	3b f3                	cmp    esi,ebx
7a69bc:	75 b2                	jne    0x7a6970
7a69be:	83 bf 8c 00 00 00 00 	cmp    DWORD PTR [edi+0x8c],0x0
7a69c5:	0f 84 a0 00 00 00    	je     0x7a6a6b
7a69cb:	b8 fc f5 c4 00       	mov    eax,0xc4f5fc
7a69d0:	e8 db 1a 09 00       	call   0x8384b0
7a69d5:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
7a69d9:	8b 35 38 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba838
```

**可確認的判定**

1. `this+0x1C == 0` 或 `this+0x124 == 0`：不可能走向本次 append。
2. `this+0xAC` 非空時其虛擬 slot `+0x2C` 的回傳參與 EBX 布林決策；但無此 slot 的具體實作，不能命名為「可見／有效／可執行」。
3. `this+0x70` 容器成員虛擬 slot `+0x30` 影響 EBX 與後續分支；樹 node 中的虛擬 slot `+0x08` 在另一條路上被派送。
4. 真正入桶的最後 guard 為 `0x007A69BE: cmp [edi+0x8C],0`；若零跳過 `0x007A69D9` 的 append。

### 兩條宏觀路徑（暫定）

```text
ECX = candidate Host
  |-- +0x1C or +0x124 is null --> end path
  |-- +0xAC vcall(+0x2C), +0x70 children vcall(+0x30)
       |-- EBX == 0 --> 0x007A688B... 0x0079AF80 (另一路，不是 B append)
       |-- EBX != 0 --> 0x007A6918... virtual +0x08 traverse
                             |-- +0x8C == 0 --> skip append
                             |-- +0x8C != 0 --> 0x007A69D9 B append
```

**[未知]** 函式完整觸發頻率/所有上游（可能間接呼叫）；上述虛擬方法的實際語義；子物件 +0x0C 的所有權與析構次序。T08-143 繼續精確拆解 append 的 alias 分支與 helper。

