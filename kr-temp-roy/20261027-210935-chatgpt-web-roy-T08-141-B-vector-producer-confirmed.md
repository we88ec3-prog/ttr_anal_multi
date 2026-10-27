# T08-141 — B vector producer confirmed

**第一手來源**：`Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（2026-10-27 本輪重新實測一致）。

**重現方法**：`objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 Tartaros.bin`；所摘錄 VA/bytes 直接對照原 BIN。BIN 是以 VA 0x401000 排列的反組譯資料，不能直接當原 PE sections 的 raw file offset；不宣稱使用動態除錯。

**證據分級**：`[確認]` 機器碼及確定資料流；`[推論]` 靜態語意；`[未知]` 缺少 vtable / 實際 run-time 參數。

## 新成果：全域 B queue 的真正寫入者已定位

**[確認]** `0x007A67C0` 函式內 `0x007A69D9～0x007A6A51` 路徑，從 `[0x00FBA838]` 讀取全域 `0x10C` bytes manager，對 `manager+0xB4` 三指標 vector 進行容量檢查與單一 entry append；`manager+0xB8` 最後增加 4 bytes。

這是對 T08-137～140「真正 B queue append 尚未定位」的正式更正；此前僅局部地址範圍查找，漏掉較早的 `0x007A6xxx` caller。此函式**不是**先前的 A queue helper `0x007BB750`。

### 主要 ASM 與分支（完整關鍵窗口）

```asm
7a69be:	83 bf 8c 00 00 00 00 	cmp    DWORD PTR [edi+0x8c],0x0
7a69c5:	0f 84 a0 00 00 00    	je     0x7a6a6b
7a69cb:	b8 fc f5 c4 00       	mov    eax,0xc4f5fc
7a69d0:	e8 db 1a 09 00       	call   0x8384b0
7a69d5:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
7a69d9:	8b 35 38 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba838
7a69df:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
7a69e5:	83 c7 0c             	add    edi,0xc
7a69e8:	8d 4d ec             	lea    ecx,[ebp-0x14]
7a69eb:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
7a69ee:	3b c8                	cmp    ecx,eax
7a69f0:	73 40                	jae    0x7a6a32
7a69f2:	8b 8e b4 00 00 00    	mov    ecx,DWORD PTR [esi+0xb4]
7a69f8:	8d 55 ec             	lea    edx,[ebp-0x14]
7a69fb:	3b ca                	cmp    ecx,edx
7a69fd:	77 33                	ja     0x7a6a32
7a69ff:	8b fa                	mov    edi,edx
7a6a01:	2b f9                	sub    edi,ecx
7a6a03:	c1 ff 02             	sar    edi,0x2
7a6a06:	3b 86 bc 00 00 00    	cmp    eax,DWORD PTR [esi+0xbc]
7a6a0c:	75 0b                	jne    0x7a6a19
7a6a0e:	8d 86 b4 00 00 00    	lea    eax,[esi+0xb4]
7a6a14:	e8 17 13 ff ff       	call   0x797d30
7a6a19:	8b 86 b4 00 00 00    	mov    eax,DWORD PTR [esi+0xb4]
7a6a1f:	8d 3c b8             	lea    edi,[eax+edi*4]
7a6a22:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
7a6a28:	85 c0                	test   eax,eax
7a6a2a:	74 25                	je     0x7a6a51
7a6a2c:	8b 0f                	mov    ecx,DWORD PTR [edi]
7a6a2e:	89 08                	mov    DWORD PTR [eax],ecx
7a6a30:	eb 1f                	jmp    0x7a6a51
7a6a32:	3b 86 bc 00 00 00    	cmp    eax,DWORD PTR [esi+0xbc]
7a6a38:	75 0b                	jne    0x7a6a45
7a6a3a:	8d 86 b4 00 00 00    	lea    eax,[esi+0xb4]
7a6a40:	e8 eb 12 ff ff       	call   0x797d30
7a6a45:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
7a6a4b:	85 c0                	test   eax,eax
7a6a4d:	74 02                	je     0x7a6a51
7a6a4f:	89 38                	mov    DWORD PTR [eax],edi
7a6a51:	83 86 b8 00 00 00 04 	add    DWORD PTR [esi+0xb8],0x4
7a6a58:	e8 73 19 09 00       	call   0x8383d0
7a6a5d:	8b 15 fc 39 d6 00    	mov    edx,DWORD PTR ds:0xd639fc
7a6a63:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
7a6a66:	a3 fc 39 d6 00       	mov    ds:0xd639fc,eax
7a6a6b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
```

### 物件身分鏈

- `0x007A67E8 mov edi,ecx`：保存進入函式的 this。
- `0x007A69D9 mov esi,[0x00FBA838]`：確實取全域 manager，非僅同名 offset。
- `0x007A69E5 add edi,0xC`：候選 B entry 指向原始 this+0x0C（embedded subobject / 欄位位址，具體型別未證實）。
- `0x007A69EB mov [ebp-0x14],edi`：將候選指標置於 stack 暫存槽。
- 兩條容量飽和路徑 `0x007A6A0E` / `0x007A6A3A` 都呼叫 `0x00797D30` 並傳入 `manager+0xB4`。
- `0x007A6A2E` 或 `0x007A6A4F` 寫入新元素；共同在 `0x007A6A51` 把 B.end +4。

### 暫定偽碼（保留自插入 alias 特例）

```cpp
void candidate_push(Host* self) {
    if (!self->field1C || !self->field124) return;
    // 中間還有 vcall 與容器檢查；並非任何 host 都必加入
    if (self->field8C) {
        GlobalManager* m = global_manager_00FBA838;
        void* embedded = (char*)self + 0x0C;
        // 如原值的 stack 暫存位址落在 vector 儲存區內，擴容後重取索引
        push_pointer_with_alias_handling(&m->b, embedded);
    }
}
```

## 證據界限與下一步

[確認] B producer 身分、元素長度 +4、直接存入原始物件 this+0x0C。

[未知] 機器碼未直接顯示 `this+0x0C` 的 vfptr 值；沒有建構函式與 vtable 方法本體就不能將此 entry 命名為特定 C++ 類型，也不能證明它一定向全域 22 桶寫入。後續 T08-142 先追本函式控制流條件。

