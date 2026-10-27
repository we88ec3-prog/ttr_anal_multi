# T08-133 — `0x007E8640` 記錄查找、計數與實際 append 對象

## 第一手來源
- 原始證據：`Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪直接以原始檔計算）。
- 反組譯：使用 GNU `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000`，對當前 BIN 全檔建立線性反組譯索引；重要 VA 再以功能邊界與既有 T08-131/132 筆記核對。線性反組譯可能包含資料誤判，不等同控制流程圖。
- 研究屬**靜態分析**；未執行客戶端、未設記憶體斷點。
- 分析區分「已確認的本段指令」、「合理推測」、「未證實的全域別名身分」。

## 新確認：實參和欄位
`0x007E8640` 是 `ret 8` 的雙參數函式，兩個直接 `E8` caller 在所掃 BIN 的映射程式區可見 `0x007A8A18` 與 `0x007BABED`。呼叫端均先 push 待登記物件，再 push 全域 `[0x00FBA838]+0x8C`；故 `[ebp+8]` 為第一個 stack 參數，`[ebp+0xC]` 是第二個。

**已確認**：`[ebp+0xC]` 的 `+0x3ECC` 計數先遞增；`[ebp+0xC]+0x3EB0` 取得字串（含 >=0x10 的 heap-string 分支）；依 `[ebp+0xC]` 基址 `+0x0` 判斷兩條字串查找支線；`0x007E8AE0` 分別從第一參數 `+4/+14` 的容器取記錄指標；記錄首次使用時 `[record]` 由0改1；尾端把第一參數值送入 `record+0x20` 的 vector，而**不是** owner `+0xB4`。

```asm
  7e8677:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7e867a:	ff 80 cc 3e 00 00    	inc    DWORD PTR [eax+0x3ecc]
  7e8680:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7e8683:	33 d2                	xor    edx,edx
  7e8685:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  7e8689:	8d b8 b0 3e 00 00    	lea    edi,[eax+0x3eb0]
  7e868f:	39 10                	cmp    DWORD PTR [eax],edx
  7e8691:	0f 85 ac 00 00 00    	jne    0x7e8743
  7e8680:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7e8683:	33 d2                	xor    edx,edx
  7e8685:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  7e8689:	8d b8 b0 3e 00 00    	lea    edi,[eax+0x3eb0]
  7e868f:	39 10                	cmp    DWORD PTR [eax],edx
  7e8691:	0f 85 ac 00 00 00    	jne    0x7e8743
  7e8697:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  7e869b:	72 04                	jb     0x7e86a1
  7e8689:	8d b8 b0 3e 00 00    	lea    edi,[eax+0x3eb0]
  7e868f:	39 10                	cmp    DWORD PTR [eax],edx
  7e8691:	0f 85 ac 00 00 00    	jne    0x7e8743
  7e8697:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  7e869b:	72 04                	jb     0x7e86a1
  7e869d:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7e869f:	eb 02                	jmp    0x7e86a3
  7e86a1:	8b cf                	mov    ecx,edi
  7e86d0:	50                   	push   eax
  7e86d1:	8d 4b 04             	lea    ecx,[ebx+0x4]
  7e86d4:	c7 44 24 64 00 00 00 	mov    DWORD PTR [esp+0x64],0x0
  7e86db:	00 
  7e86dc:	e8 ff 03 00 00       	call   0x7e8ae0
  7e86e1:	bb 10 00 00 00       	mov    ebx,0x10
  7e86e6:	c7 44 24 60 ff ff ff 	mov    DWORD PTR [esp+0x60],0xffffffff
  7e86ed:	ff 
  7e8718:	83 3e 00             	cmp    DWORD PTR [esi],0x0
  7e871b:	0f 85 d2 00 00 00    	jne    0x7e87f3
  7e8721:	c7 06 01 00 00 00    	mov    DWORD PTR [esi],0x1
  7e8727:	39 5f 14             	cmp    DWORD PTR [edi+0x14],ebx
  7e872a:	72 04                	jb     0x7e8730
  7e872c:	8b 17                	mov    edx,DWORD PTR [edi]
  7e872e:	eb 02                	jmp    0x7e8732
  7e8730:	8b d7                	mov    edx,edi
  7e8743:	83 7f 14 10          	cmp    DWORD PTR [edi+0x14],0x10
  7e8747:	72 04                	jb     0x7e874d
  7e8749:	8b 0f                	mov    ecx,DWORD PTR [edi]
  7e874b:	eb 02                	jmp    0x7e874f
  7e874d:	8b cf                	mov    ecx,edi
  7e874f:	8b c1                	mov    eax,ecx
  7e8751:	c7 44 24 48 0f 00 00 	mov    DWORD PTR [esp+0x48],0xf
  7e8758:	00 
  7e8788:	e8 53 03 00 00       	call   0x7e8ae0
  7e878d:	bb 10 00 00 00       	mov    ebx,0x10
  7e8792:	c7 44 24 60 ff ff ff 	mov    DWORD PTR [esp+0x60],0xffffffff
  7e8799:	ff 
  7e879a:	8b f0                	mov    esi,eax
  7e879c:	39 5c 24 48          	cmp    DWORD PTR [esp+0x48],ebx
  7e87a0:	72 0d                	jb     0x7e87af
  7e87a2:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
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
  7e881c:	c2 08 00             	ret    0x8
  7e881f:	cc                   	int3
  7e8820:	55                   	push   ebp
  7e8821:	8b ec                	mov    ebp,esp
  7e8823:	6a ff                	push   0xffffffff
  7e8825:	68 58 78 93 00       	push   0x937858
  7e882a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7e8830:	50                   	push   eax
```

## 兩個 caller 的身分限制
```asm
  7a8a0b:	a1 38 a8 fb 00       	mov    eax,ds:0xfba838
  7a8a10:	8b 88 8c 00 00 00    	mov    ecx,DWORD PTR [eax+0x8c]
  7a8a16:	53                   	push   ebx
  7a8a17:	51                   	push   ecx
  7a8a18:	e8 23 fc 03 00       	call   0x7e8640
  7a8a1d:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  7a8a21:	5f                   	pop    edi
  7a8a22:	5e                   	pop    esi
  7a8a16:	53                   	push   ebx
  7a8a17:	51                   	push   ecx
  7a8a18:	e8 23 fc 03 00       	call   0x7e8640
  7a8a1d:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  7a8a21:	5f                   	pop    edi
  7a8a22:	5e                   	pop    esi
  7a8a23:	5b                   	pop    ebx
  7a8a24:	33 cc                	xor    ecx,esp
  7a8a18:	e8 23 fc 03 00       	call   0x7e8640
  7a8a1d:	8b 4c 24 54          	mov    ecx,DWORD PTR [esp+0x54]
  7a8a21:	5f                   	pop    edi
  7a8a22:	5e                   	pop    esi
  7a8a23:	5b                   	pop    ebx
  7a8a24:	33 cc                	xor    ecx,esp
  7a8a26:	e8 d6 89 0e 00       	call   0x891401
  7a8a2b:	8b e5                	mov    esp,ebp
  7babd9:	8b 14 99             	mov    edx,DWORD PTR [ecx+ebx*4]
  7babdc:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  7babdf:	8b 0d 38 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba838
  7babe5:	8b 91 8c 00 00 00    	mov    edx,DWORD PTR [ecx+0x8c]
  7babeb:	50                   	push   eax
  7babec:	52                   	push   edx
  7babed:	e8 4e da 02 00       	call   0x7e8640
  7babf2:	43                   	inc    ebx
  7babdf:	8b 0d 38 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba838
  7babe5:	8b 91 8c 00 00 00    	mov    edx,DWORD PTR [ecx+0x8c]
  7babeb:	50                   	push   eax
  7babec:	52                   	push   edx
  7babed:	e8 4e da 02 00       	call   0x7e8640
  7babf2:	43                   	inc    ebx
  7babf3:	3b df                	cmp    ebx,edi
  7babf5:	72 dc                	jb     0x7babd3
  7babeb:	50                   	push   eax
  7babec:	52                   	push   edx
  7babed:	e8 4e da 02 00       	call   0x7e8640
  7babf2:	43                   	inc    ebx
  7babf3:	3b df                	cmp    ebx,edi
  7babf5:	72 dc                	jb     0x7babd3
  7babf7:	83 be 8c 00 00 00 00 	cmp    DWORD PTR [esi+0x8c],0x0
  7babfe:	74 0d                	je     0x7bac0d
```
`0x007A8A18` 發生在 `0x007BAE80` 產生或取得 `[EBX+0x150]` 後；`0x007BABED` 從 A-array entry `+0x34` 取得參數。兩者**共享登記函式**，但對象身分並未證明與 B queue entry 相同。

## 可交付偽碼（抽象）
```cpp
void register_record_007E8640(RecordTable* table, SourceObject* source) {
    ++source->field_3ECC;
    auto key = source->string_3EB0;
    Record* record = lookup_or_insert_by_name(table, key, source->field_0);
    if (record->field_0 == 0) { record->field_0 = 1; /* copy associated name */ }
    append_pointer(&record->vector_20, source); // helper 0x007BB750
}
```
`lookup_or_insert_by_name` 是對 `0x007E8AE0` 的抽象化，不表示已重建樹節點或比較器的完整類型。

## 結論與未解
**已確認**：此函式是按來源字串查找/建立記錄並增加記錄所屬的 `+0x20` 指標陣列；不能再列為 B queue 直接 producer。**未證實**：記錄後續是否間接產生 B queue entry；記錄的完整所有權/釋放條件。下一段追其下層 `0x007E8AE0` 與向量 helper。