# KR T08-170 — `0x7BE0F0` 虛擬二階段銷毀的巢狀資源集合

## 一手來源及可稽核性

- **標的**：韓版 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes，PE32 x86。
- **證據方法**：本輪實際對 PE `.text` 正式 VA 執行 `objdump -d -M intel --start-address ... --stop-address ...`。展示的線性反組譯不等同全函式 CFG／動態 runtime。
- **分工**：T08 研究 actor 建立／登記／移除之資料介面及相關資源生命週期；其他 Task 的封包分派、場景政策僅交叉參照。
- **交叉來源**：原先 T08-165～168 完整研究與本輪第一手機器碼。舊報告命名均為研究標籤，非官方符號證據。
- **驗證限制**：不執行客戶端、不修改遊戲／服務或存檔；虛擬函式和 Win32 import 未獨立解析成全部實際 concrete target。

## 核心發現

`0x7BE0F0` 不是 CMonster 的通用析構。函式用 `[ebp+8]` 當入參 `item`，讀取 `item+0x04` 和 `item+0x08` 作為指標陣列的 begin/end。每格存一個 node 指標，`node+0x08` 指向非 NULL 多型 payload。

在 `0x7BE10F..0x7BE125`：先取 `payload->vtable+0x08` 呼叫一次，再重新取 `node+8`，若仍非零則呼叫 `payload->vtable+0`，並帶入 `push 1`；最後 `mov [node+8],0`。這是一條 **對具體巢狀 payload 的二階段清理 + deleting destructor-like 呼叫**，但目前無法確定兩個 vslot 的確切符號名稱。

跳出陣列遍歷後，`mov [item+0x74],0; ret 4`，直接吻合上游 `0x7BE5F0` 以 `item+0x74` 判斷是否需要清理的門檻。**這代表欄位 `+0x74` 是清理狀態候選，不是 actor 的資源 index 或死亡 flag。**

## 有證據的偽碼

```cpp
void clear_child_objects(Item* item) {
  for (auto it = item->begin_at_04; it != item->end_at_08; ++it) {
    Node* node = *it; // 由 [edi] -> [esi] 的雙指標關係
    Object* obj = node ? node->at_08 : nullptr;
    if (obj) {
      obj->vtable[2](obj); // +8 slot，預清理候選
      obj = node->at_08;  // 刻意重新讀取
      if (obj) { obj->vtable[0](obj, 1); node->at_08 = nullptr; }
    }
  }
  item->field74 = 0;
}
```

若 `node` 可為 NULL，上述偽碼的 `node?` 是防禦性展示，**原機器碼沒有顯式 NULL node guard**，因此必須維持容器的非空 node invariant 才能安全。

## 限制及交互

本段確認兩個 virtual call 及回填欄位，但沒有證實所有衍生類別的 vtable 指標，也沒有證實上游每條路徑一定先走 `0x7BE0F0`；`0x7BE5F0` 的 owner 延遲路徑會避開立即清理。下一步追 iterator 實際資料與 `.rdata` slot 對應。

## 原始 machine-code 摘錄（含實際 VA）

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

## 版本與交接

T08-170 僅在此列出與標的直接相關的局部確證；未知的動態所有權與執行緒時序仍列未知。請以 GitHub `main` 已驗證完整原稿為基準比較，新增語意不可覆寫舊原稿。